/* libguestfs
 * Copyright (C) 2009-2014 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <win-unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <assert.h>

#include "c-ctype.h"
#include "glthread/lock.h"
#include "ignore-value.h"

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"


/* This is the code used to send and receive RPC messages and (for
 * certain types of message) to perform file transfers.  This code is
 * driven from the generated actions (src/actions.c).  There
 * are five different cases to consider:
 *
 * (1) A non-daemon function.  There is no RPC involved at all, it's
 * all handled inside the library.
 *
 * (2) A simple RPC (eg. "mount").  We write the request, then read
 * the reply.  The sequence of calls is:
 *
 *   guestfs___send
 *   guestfs___recv
 *
 * (3) An RPC with FileOut parameters (eg. "upload").  We write the
 * request, then write the file(s), then read the reply.  The sequence
 * of calls is:
 *
 *   guestfs___send
 *   guestfs___send_file  (possibly multiple times)
 *   guestfs___recv
 *
 * (4) An RPC with FileIn parameters (eg. "download").  We write the
 * request, then read the reply, then read the file(s).  The sequence
 * of calls is:
 *
 *   guestfs___send
 *   guestfs___recv
 *   guestfs___recv_file  (possibly multiple times)
 *
 * (5) Both FileOut and FileIn parameters.  There are no calls like
 * this in the current API, but they would be implemented as a
 * combination of cases (3) and (4).
 *
 * All read/write/etc operations are performed using the current
 * connection module (g->conn).  During operations the connection
 * module transparently handles log messages that appear on the
 * console.
 */

/* This is called if we detect EOF, ie. qemu died. */
static void
child_cleanup (guestfs_h *g)
{
  debug (g, "child_cleanup: %p: child process died", g);

  g->backend_ops->shutdown (g, g->backend_data, 0);
  if (g->conn) {
    g->conn->ops->free_connection (g, g->conn);
    g->conn = NULL;
  }
  memset (&g->launch_t, 0, sizeof g->launch_t);
  guestfs___free_drives (g);
  g->state = CONFIG;
  guestfs___call_callbacks_void (g, GUESTFS_EVENT_SUBPROCESS_QUIT);
}

/* Convenient wrapper to generate a progress message callback. */
void
guestfs___progress_message_callback (guestfs_h *g,
                                     const guestfs_protobuf_progress *message)
{
  uint64_t array[4];

  array[0] = message->proc;
  array[1] = message->serial;
  array[2] = message->position;
  array[3] = message->total;

  guestfs___call_callbacks_array (g, GUESTFS_EVENT_PROGRESS,
                                  array, sizeof array / sizeof array[0]);
}

/* Connection modules call us back here when they get a log message. */
void
guestfs___log_message_callback (guestfs_h *g, const char *buf, size_t len)
{
  /* Send the log message upwards to anyone who is listening. */
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_APPLIANCE, buf, len);

  /* This is used to generate launch progress messages.  See comment
   * above guestfs___launch_send_progress.
   */
  if (g->state == LAUNCHING) {
    const char *sentinel;
    size_t slen;

    sentinel = "Linux version"; /* kernel up */
    slen = strlen (sentinel);
    if (memmem (buf, len, sentinel, slen) != NULL)
      guestfs___launch_send_progress (g, 6);

    sentinel = "Starting /init script"; /* /init running */
    slen = strlen (sentinel);
    if (memmem (buf, len, sentinel, slen) != NULL)
      guestfs___launch_send_progress (g, 9);
  }
}

/* Before writing to the daemon socket, check the read side of the
 * daemon socket for any of these conditions:
 *
 *   - error:                       return -1
 *   - daemon cancellation message: return -2
 *   - progress message:            handle it here
 *   - end of input / appliance exited unexpectedly: return 0
 *   - anything else:               return 1
 */
static ssize_t
check_daemon_socket (guestfs_h *g)
{
  char buf[PROTOBUF_FLAG_MESSAGE_SIZE];
  ssize_t n;
  uint32_t flag;
  guestfs_protobuf_flag_message *flag_msg;

  assert (g->conn); /* callers must check this */

 again:
  if (! g->conn->ops->can_read_data (g, g->conn))
    return 1;

  n = g->conn->ops->read_data (g, g->conn, buf, PROTOBUF_FLAG_MESSAGE_SIZE);
  if (n <= 0) /* 0 or -1 */
    return n;

  flag_msg = guestfs_protobuf_flag_message__unpack (NULL, PROTOBUF_FLAG_MESSAGE_SIZE, buf);
  flag = flag_msg->val;
  guestfs_protobuf_flag_message__free_unpacked (flag_msg, NULL);

  /* Read and process progress messages that happen during FileIn. */
  if (flag == GUESTFS_PROGRESS_FLAG) {
    char buf[PROTOBUF_PROGRESS_MESSAGE_SIZE];
    guestfs_protobuf_progress *message;

    n = g->conn->ops->read_data (g, g->conn, buf, PROTOBUF_PROGRESS_MESSAGE_SIZE);
    if (n <= 0) /* 0 or -1 */
      return n;

    message = guestfs_protobuf_progress__unpack (NULL, PROTOBUF_PROGRESS_MESSAGE_SIZE, (uint8_t *) buf);
    guestfs___progress_message_callback (g, message);
    guestfs_protobuf_progress__free_unpacked (message, NULL);

    goto again;
  }

  if (flag != GUESTFS_CANCEL_FLAG) {
    error (g, _("check_daemon_socket: read 0x%x from daemon, expected 0x%x.  Lost protocol synchronization (bad!)\n"),
           flag, GUESTFS_CANCEL_FLAG);
    return -1;
  }

  return -2;
}

int
guestfs___send (guestfs_h *g, int proc_nr,
                uint64_t progress_hint, uint64_t optargs_bitmask,
                protobuf_proc_pack pb_pack, char *args)
{
  guestfs_protobuf_message_header hdr;
  guestfs_protobuf_flag_message len_msg;
  uint32_t len, flag_len, hdr_len, pack_len = 0;
  int serial = g->msg_next_serial++;
  ssize_t r;
  CLEANUP_FREE char *msg_out = NULL;
  size_t msg_out_size;

  if (!g->conn) {
    guestfs___unexpected_close_error (g);
    return -1;
  }

  /* We have to allocate this message buffer on the heap because
   * it is quite large (although will be mostly unused).  We
   * can't allocate it on the stack because in some environments
   * we have quite limited stack space available, notably when
   * running in the JVM.
   */
  msg_out = safe_malloc (g, GUESTFS_MESSAGE_MAX + PROTOBUF_FLAG_MESSAGE_SIZE);

  /* Serialize the header. */
  guestfs_protobuf_message_header__init (&hdr);
  hdr.prog = GUESTFS_PROGRAM;
  hdr.vers = GUESTFS_PROTOCOL_VERSION;
  hdr.proc = proc_nr;
  hdr.direction = GUESTFS_DIRECTION_CALL;
  hdr.serial = serial;
  hdr.status = GUESTFS_STATUS_OK;
  hdr.progress_hint = progress_hint;
  hdr.optargs_bitmask = optargs_bitmask;

  hdr_len = guestfs_protobuf_message_header__pack (&hdr, (uint8_t *) msg_out + PROTOBUF_FLAG_MESSAGE_SIZE);
  assert (hdr_len == PROTOBUF_MESSAGE_HEADER_SIZE);
  if (!hdr_len) {
    error (g, _("protobuf-c's guestfs_message_header__pack failed"));
    free (msg_out);
    return -1;
  }

  /* Serialize the args.  If any, because some message types
   * have no parameters.
   */
  if (pb_pack) {
    pack_len = pb_pack ((ProtobufCMessage*) args, msg_out + PROTOBUF_FLAG_MESSAGE_SIZE + PROTOBUF_MESSAGE_HEADER_SIZE);
    if (!pack_len) {
      error (g, _("dispatch failed to marshal args"));
      free(msg_out);
      return -1;
    }
  }

  /* Get the actual length of the message, resize the buffer to match
   * the actual length, and write the length word at the beginning.
   */
  len = hdr_len + pack_len;

  msg_out = safe_realloc (g, msg_out, len + PROTOBUF_FLAG_MESSAGE_SIZE);
  msg_out_size = len + PROTOBUF_FLAG_MESSAGE_SIZE;

  guestfs_protobuf_flag_message__init (&len_msg);
  len_msg.val = len;
  flag_len = guestfs_protobuf_flag_message__pack (&len_msg, (uint8_t *) msg_out);
  assert (flag_len == PROTOBUF_FLAG_MESSAGE_SIZE);
  
  /* Look for stray daemon cancellation messages from earlier calls
   * and ignore them.
   */
  r = check_daemon_socket (g);
  /* r == -2 (cancellation) is ignored */
  if (r == -1) {
    free(msg_out);
    return -1;
  }
  if (r == 0) {
    guestfs___unexpected_close_error (g);
    child_cleanup (g);
    free(msg_out);
    return -1;
  }

  /* Send the message. */
  r = g->conn->ops->write_data (g, g->conn, msg_out, msg_out_size);
  if (r == -1) {
    free(msg_out);
    return -1;
  }
  if (r == 0) {
    guestfs___unexpected_close_error (g);
    child_cleanup (g);
    free(msg_out);
    return -1;
  }

  free(msg_out);
  return serial;
}

static void
fadvise_sequential (int fd)
{
#if defined(HAVE_POSIX_FADVISE) && defined(POSIX_FADV_SEQUENTIAL)
  /* Since the fd might be a non-file, eg. /dev/stdout, just ignore
   * this when it fails.  It's not clear from the man page, but the
   * 'advice' parameter is NOT a bitmask.  You can only pass one
   * parameter with each call.
   */
  ignore_value (posix_fadvise (fd, 0, 0, POSIX_FADV_SEQUENTIAL));
#endif
}

static int send_file_chunk (guestfs_h *g, int cancel, const char *buf, size_t len);
static int send_file_data (guestfs_h *g, const char *buf, size_t len);
static int send_file_cancellation (guestfs_h *g);
static int send_file_complete (guestfs_h *g);

/* Send a file.
 * Returns:
 *   0 OK
 *   -1 error
 *   -2 daemon cancelled (we must read the error message)
 */
int
guestfs___send_file (guestfs_h *g, const char *filename)
{
  char buf[GUESTFS_MAX_CHUNK_SIZE];
  int fd, r = 0, err;

  g->user_cancel = 0;

  fd = _open (filename, O_RDONLY);
  if (fd == -1) {
    perrorf (g, "open: %s", filename);
    send_file_cancellation (g);
    return -1;
  }

  fadvise_sequential (fd);

  /* Send file in chunked encoding. */
  while (!g->user_cancel) {
    r = _read (fd, buf, sizeof buf);
    if (r == -1 && (errno == EINTR || errno == EAGAIN))
      continue;
    if (r <= 0) break;
    err = send_file_data (g, buf, r);
    if (err < 0) {
      if (err == -2)		/* daemon sent cancellation */
        send_file_cancellation (g);
      _close (fd);
      return err;
    }
  }

  if (r == -1) {
    perrorf (g, "read: %s", filename);
    send_file_cancellation (g);
    _close (fd);
    return -1;
  }

  if (g->user_cancel) {
    error (g, _("operation cancelled by user"));
    g->last_errnum = EINTR;
    send_file_cancellation (g);
    _close (fd);
    return -1;
  }

  /* End of file, but before we send that, we need to close
   * the file and check for errors.
   */
  if (_close (fd) == -1) {
    perrorf (g, "close: %s", filename);
    send_file_cancellation (g);
    return -1;
  }

  err = send_file_complete (g);
  if (err < 0) {
    if (err == -2)              /* daemon sent cancellation */
      send_file_cancellation (g);
    return err;
  }

  return 0;
}

/* Send a chunk of file data. */
static int
send_file_data (guestfs_h *g, const char *buf, size_t len)
{
  return send_file_chunk (g, 0, buf, len);
}

/* Send a cancellation message. */
static int
send_file_cancellation (guestfs_h *g)
{
  return send_file_chunk (g, 1, NULL, 0);
}

/* Send a file complete chunk. */
static int
send_file_complete (guestfs_h *g)
{
  char buf[1];
  return send_file_chunk (g, 0, buf, 0);
}

static int
send_file_chunk (guestfs_h *g, int cancel, const char *buf, size_t buflen)
{
  uint32_t len, flag_len;
  ssize_t r;
  guestfs_protobuf_flag_message len_msg;
  guestfs_protobuf_chunk chunk;
  CLEANUP_FREE char *msg_out = NULL;
  size_t msg_out_size;

  /* Allocate the chunk buffer.  Don't use the stack to avoid
   * excessive stack usage and unnecessary copies.
   */
  msg_out = safe_malloc (g, GUESTFS_MAX_CHUNK_SIZE + PROTOBUF_FLAG_MESSAGE_SIZE + 48);

  /* Serialize the chunk. */
  guestfs_protobuf_chunk__init (&chunk);
  chunk.cancel = cancel;
  chunk.data.len = buflen;
  chunk.data.data = (uint8_t *) buf;

  len = guestfs_protobuf_chunk__pack (&chunk, (uint8_t *) msg_out + PROTOBUF_FLAG_MESSAGE_SIZE);
  if (!len) {
    error (g, _("protobuf-c's guestfs_chunk_pack failed (buf = %p, buflen = %zu)"),
           buf, buflen);
    free (msg_out);
    return -1;
  }

  /* Reduce the size of the outgoing message buffer to the real length. */
  msg_out = safe_realloc (g, msg_out, len + PROTOBUF_FLAG_MESSAGE_SIZE);
  msg_out_size = len + PROTOBUF_FLAG_MESSAGE_SIZE;

  guestfs_protobuf_flag_message__init (&len_msg);
  len_msg.val = len;
  flag_len = guestfs_protobuf_flag_message__pack (&len_msg, (uint8_t *) msg_out);
  assert (flag_len == PROTOBUF_FLAG_MESSAGE_SIZE);

  /* Did the daemon send a cancellation message? */
  r = check_daemon_socket (g);
  if (r == -2) {
    debug (g, "got daemon cancellation");
    free(msg_out);
    return -2;
  }
  if (r == -1) {
    free(msg_out);
    return -1;
  }
  if (r == 0) {
    guestfs___unexpected_close_error (g);
    child_cleanup (g);
    free(msg_out);
    return -1;
  }

  /* Send the chunk. */
  r = g->conn->ops->write_data (g, g->conn, msg_out, msg_out_size);
  if (r == -1) {
    free(msg_out);
    return -1;
  }
  if (r == 0) {
    guestfs___unexpected_close_error (g);
    child_cleanup (g);
    free(msg_out);
    return -1;
  }

  free(msg_out);
  return 0;
}

/* guestfs___recv_from_daemon: This reads a single message, file
 * chunk, launch flag or cancellation flag from the daemon.  If
 * something was read, it returns 0, otherwise -1.
 *
 * Both size_rtn and buf_rtn must be passed by the caller as non-NULL.
 *
 * *size_rtn returns the size of the returned message or it may be
 * GUESTFS_LAUNCH_FLAG or GUESTFS_CANCEL_FLAG.
 *
 * *buf_rtn is returned containing the message (if any) or will be set
 * to NULL.  *buf_rtn must be freed by the caller.
 *
 * This checks for EOF (appliance died) and passes that up through the
 * child_cleanup function above.
 *
 * Log message, progress messages are handled transparently here.
 */

static int
recv_from_daemon (guestfs_h *g, uint32_t *size_rtn, void **buf_rtn)
{
  char lenbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  guestfs_protobuf_flag_message *lenmsg;
  ssize_t n;
  size_t message_size;

  *size_rtn = 0;
  *buf_rtn = NULL;

  /* RHBZ#914931: Along some (rare) paths, we might have closed the
   * socket connection just before this function is called, so just
   * return an error if this happens.
   */
  if (!g->conn) {
    guestfs___unexpected_close_error (g);
    return -1;
  }

  /* Read the 4 byte size / flag. */
  n = g->conn->ops->read_data (g, g->conn, lenbuf, PROTOBUF_FLAG_MESSAGE_SIZE);
  if (n == -1)
    return -1;
  if (n == 0) {
    guestfs___unexpected_close_error (g);
    child_cleanup (g);
    return -1;
  }

  lenmsg = guestfs_protobuf_flag_message__unpack (NULL, PROTOBUF_FLAG_MESSAGE_SIZE, (uint8_t *) lenbuf);
  *size_rtn = lenmsg->val;
  guestfs_protobuf_flag_message__free_unpacked (lenmsg, NULL);
  
  if (*size_rtn == GUESTFS_LAUNCH_FLAG) {
    if (g->state != LAUNCHING)
      error (g, _("received magic signature from guestfsd, but in state %d"),
             g->state);
    else {
      g->state = READY;
      guestfs___call_callbacks_void (g, GUESTFS_EVENT_LAUNCH_DONE);
    }
    debug (g, "recv_from_daemon: received GUESTFS_LAUNCH_FLAG");
    return 0;
  }
  else if (*size_rtn == GUESTFS_CANCEL_FLAG) {
    debug (g, "recv_from_daemon: received GUESTFS_CANCEL_FLAG");
    return 0;
  }
  else if (*size_rtn == GUESTFS_PROGRESS_FLAG)
    /*FALLTHROUGH*/;
  else if (*size_rtn > GUESTFS_MESSAGE_MAX) {
    /* If this happens, it's pretty bad and we've probably lost
     * synchronization.
     */
    error (g, _("message length (%u) > maximum possible size (%d)"),
           (unsigned) *size_rtn, GUESTFS_MESSAGE_MAX);
    return -1;
  }

  /* Calculate the message size. */
  message_size =
    *size_rtn != GUESTFS_PROGRESS_FLAG ? *size_rtn : PROTOBUF_PROGRESS_MESSAGE_SIZE;

  /* Allocate the complete buffer, size now known. */
  *buf_rtn = safe_malloc (g, message_size);

  /* Read the message. */
  n = g->conn->ops->read_data (g, g->conn, *buf_rtn, message_size);
  if (n == -1) {
    free (*buf_rtn);
    *buf_rtn = NULL;
    return -1;
  }
  if (n == 0) {
    guestfs___unexpected_close_error (g);
    child_cleanup (g);
    free (*buf_rtn);
    *buf_rtn = NULL;
    return -1;
  }

  /* ... it's a normal message (not progress/launch/cancel) so display
   * it if we're debugging.
   */
#ifdef ENABLE_PACKET_DUMP
  if (g->verbose) {
    ssize_t i, j;

    for (i = 0; i < n; i += 16) {
      printf ("%04zx: ", i);
      for (j = i; j < MIN (i+16, n); ++j)
        printf ("%02x ", (*(unsigned char **)buf_rtn)[j]);
      for (; j < i+16; ++j)
        printf ("   ");
      printf ("|");
      for (j = i; j < MIN (i+16, n); ++j)
        if (c_isprint ((*(char **)buf_rtn)[j]))
          printf ("%c", (*(char **)buf_rtn)[j]);
        else
          printf (".");
      for (; j < i+16; ++j)
        printf (" ");
      printf ("|\n");
    }
  }
#endif

  return 0;
}

int
guestfs___recv_from_daemon (guestfs_h *g, uint32_t *size_rtn, void **buf_rtn)
{
  int r;

 again:
  r = recv_from_daemon (g, size_rtn, buf_rtn);
  if (r == -1)
    return -1;

  if (*size_rtn == GUESTFS_PROGRESS_FLAG) {
    guestfs_protobuf_progress *message;

    message = guestfs_protobuf_progress__unpack (NULL, PROTOBUF_PROGRESS_MESSAGE_SIZE, *buf_rtn);
    guestfs___progress_message_callback (g, message);
    guestfs_protobuf_progress__free_unpacked (message, NULL);

    free (*buf_rtn);
    *buf_rtn = NULL;

    /* Process next message. */
    goto again;
  }

  if (*size_rtn == GUESTFS_LAUNCH_FLAG || *size_rtn == GUESTFS_CANCEL_FLAG)
    return 0;

  /* Got the full message, caller can start processing it. */
  assert (*buf_rtn != NULL);

  return 0;
}

/* Receive a reply. */
int
guestfs___recv (guestfs_h *g, const char *fn,
                guestfs_protobuf_message_header **hdr,
                guestfs_protobuf_message_error **err,
                protobuf_proc_unpack pb_unpack, ProtobufCMessage **ret)
{
  guestfs_protobuf_message_header *tmphdr;
  guestfs_protobuf_message_error *tmperr;
  ProtobufCMessage *tmpret;
  CLEANUP_FREE void *buf = NULL;
  uint32_t size;
  int r;

 again:
  r = guestfs___recv_from_daemon (g, &size, &buf);
  if (r == -1)
    return -1;

  /* This can happen if a cancellation happens right at the end
   * of us sending a FileIn parameter to the daemon.  Discard.  The
   * daemon should send us an error message next.
   */
  if (size == GUESTFS_CANCEL_FLAG)
    goto again;

  if (size == GUESTFS_LAUNCH_FLAG) {
    error (g, "%s: received unexpected launch flag from daemon when expecting reply", fn);
    return -1;
  }
  
  tmphdr = guestfs_protobuf_message_header__unpack (NULL, PROTOBUF_MESSAGE_HEADER_SIZE, (uint8_t *) buf);
  if (!tmphdr) {
    error (g, "%s: failed to parse reply header", fn);
    return -1;
  }
  *hdr = tmphdr;
//  convert_guestfs_message_header_protobuf_to_xdr (tmphdr, hdr);
//  guestfs_message_header__free_unpacked (tmphdr, NULL);

  if (tmphdr->status == GUESTFS_STATUS_ERROR) {
    tmperr = guestfs_protobuf_message_error__unpack (NULL, size - PROTOBUF_MESSAGE_HEADER_SIZE, (uint8_t *) buf + PROTOBUF_MESSAGE_HEADER_SIZE);
    if (!tmperr) {
      error (g, "%s: failed to parse reply error", fn);
      return -1;
    }
    *err = tmperr;
//    convert_guestfs_message_error_protobuf_to_xdr (tmperr, err);
//    guestfs_message_error__free_unpacked (tmperr, NULL);
  } else {
    if (pb_unpack && ret) {
      tmpret = pb_unpack (NULL, size - PROTOBUF_MESSAGE_HEADER_SIZE, (uint8_t *) buf + PROTOBUF_MESSAGE_HEADER_SIZE);
      if (tmpret == NULL) {
        error (g, "%s: failed to parse reply", fn);
        return -1;
      }
      *ret = tmpret;
    } 
  }

  return 0;
}

/* Same as guestfs___recv, but it discards the reply message.
 *
 * Notes (XXX):
 * (1) This returns an int, but all current callers ignore it.
 * (2) The error string may end up being set twice on error paths.
 */
int
guestfs___recv_discard (guestfs_h *g, const char *fn)
{
  CLEANUP_FREE void *buf = NULL;
  uint32_t size;
  int r;

 again:
  r = guestfs___recv_from_daemon (g, &size, &buf);
  if (r == -1)
    return -1;

  /* This can happen if a cancellation happens right at the end
   * of us sending a FileIn parameter to the daemon.  Discard.  The
   * daemon should send us an error message next.
   */
  if (size == GUESTFS_CANCEL_FLAG)
    goto again;

  if (size == GUESTFS_LAUNCH_FLAG) {
    error (g, "%s: received unexpected launch flag from daemon when expecting reply", fn);
    return -1;
  }

  return 0;
}

/* Receive a file. */

static int
xwrite (int fd, const void *v_buf, size_t len)
{
  const char *buf = (char *) v_buf;
  int r;

  while (len > 0) {
    r = _write (fd, buf, len);
    if (r == -1)
      return -1;

    buf += r;
    len -= r;
  }

  return 0;
}

static ssize_t receive_file_data (guestfs_h *g, void **buf);

/* Returns -1 = error, 0 = EOF, > 0 = more data */
int
guestfs___recv_file (guestfs_h *g, const char *filename)
{
  void *buf = NULL;
  int fd, r;

  g->user_cancel = 0;

  fd = _open (filename, O_WRONLY|O_CREAT|O_TRUNC|O_BINARY, S_IWRITE);
  if (fd == -1) {
    perrorf (g, "open: %s", filename);
    goto cancel;
  }

  fadvise_sequential (fd);

  /* Receive the file in chunked encoding. */
  while ((r = receive_file_data (g, &buf)) > 0) {
    if (xwrite (fd, buf, r) == -1) {
      perrorf (g, "%s: write", filename);
      if (!g->enable_shm)
        free (buf);
      _close (fd);
      goto cancel;
    }
    if (!g->enable_shm)
      free (buf);

    if (g->user_cancel) {
      _close (fd);
      goto cancel;
    }
  }

  if (r == -1) {
    _close (fd);
    return -1;
  }

  if (_close (fd) == -1) {
    perrorf (g, "close: %s", filename);
    return -1;
  }

  return 0;

 cancel: ;
  /* Send cancellation message to daemon, then wait until it
   * cancels (just throwing away data).
   */
  guestfs_protobuf_flag_message flagmsg;
  char flagbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  uint32_t flag = GUESTFS_CANCEL_FLAG, flaglen;

  debug (g, "%s: waiting for daemon to acknowledge cancellation",
         __FUNCTION__);

  guestfs_protobuf_flag_message__init (&flagmsg);
  flagmsg.val = flag;
  flaglen = guestfs_protobuf_flag_message__pack (&flagmsg, (uint8_t *) flagbuf);
  assert (flaglen == PROTOBUF_FLAG_MESSAGE_SIZE);

  if (g->conn->ops->write_data (g, g->conn, flagbuf, sizeof flagbuf) == -1) {
    perrorf (g, _("write to daemon socket"));
    return -1;
  }

  while (receive_file_data (g, NULL) > 0)
    ;                           /* just discard it */

  return -1;
}

static ssize_t receive_file_data_shm(guestfs_h *g, void **buf_r);
static ssize_t receive_file_data_sock(guestfs_h *g, void **buf_r);

static ssize_t
receive_file_data(guestfs_h *g, void **buf_r)
{
    if (g->enable_shm) {
        return receive_file_data_shm(g, buf_r);
    }

    return receive_file_data_sock(g, buf_r);
}

/* Returns length of data_for_reading from shared memory, buf_r is ignored */
/* Returned 0 indicates the end of transfer */
static ssize_t
receive_file_data_shm(guestfs_h *g, void **buf_r)
{
    int r;
    CLEANUP_FREE void *buf = NULL;
    uint32_t buflen, len_r;
    guestfs_protobuf_shm_chunk *shm_chunk;

    r = guestfs___recv_from_daemon(g, &buflen, &buf);
    if (r == -1)
        return -1;

    shm_chunk = guestfs_protobuf_shm_chunk__unpack(NULL, buflen, buf);

    if (!shm_chunk) {
        error(g, _("failed to parse shm chunk"));
        return -1;
    }

    if (shm_chunk->cancel) {
        if (g->user_cancel) {
            error(g, _("operation cancelled by user"));
            g->last_errnum = EINTR;
        }
        else
            error(g, _("file receive cancelled by daemon"));
        guestfs_protobuf_shm_chunk__free_unpacked(shm_chunk, NULL);
        return -1;
    }

    len_r = shm_chunk->len;
    guestfs_protobuf_shm_chunk__free_unpacked(shm_chunk, NULL);

    if (buf_r) {
        *buf_r = g->shm->ops->get_ptr(g, g->shm);
    }

    return len_r;
}

/* Receive a chunk of file data. */
/* Returns -1 = error, 0 = EOF, > 0 = more data */
static ssize_t
receive_file_data_sock(guestfs_h *g, void **buf_r)
{
    int r;
    CLEANUP_FREE void *buf = NULL;
    uint32_t len;
    guestfs_protobuf_chunk *chunk;

    r = guestfs___recv_from_daemon(g, &len, &buf);
    if (r == -1)
        return -1;

    if (len == GUESTFS_LAUNCH_FLAG || len == GUESTFS_CANCEL_FLAG) {
        error(g, _("receive_file_data: unexpected flag received when reading file chunks"));
        return -1;
    }

    chunk = guestfs_protobuf_chunk__unpack(NULL, len, buf);

    if (!chunk) {
        error(g, _("failed to parse file chunk"));
        return -1;
    }

    if (chunk->cancel) {
        if (g->user_cancel) {
            error(g, _("operation cancelled by user"));
            g->last_errnum = EINTR;
        }
        else
            error(g, _("file receive cancelled by daemon"));
        guestfs_protobuf_chunk__free_unpacked(chunk, NULL);
        return -1;
    }

    if (chunk->data.len == 0) { /* end of transfer */
        guestfs_protobuf_chunk__free_unpacked(chunk, NULL);
        return 0;
    }

    len = chunk->data.len;

    if (len && buf_r) {
        /* Fix (-1 copy): Move data from unpacked chunk without copying */
        *buf_r = chunk->data.data;
        chunk->data.data = NULL;
        chunk->data.len = 0;
    }

    guestfs_protobuf_chunk__free_unpacked(chunk, NULL);
    return len;
}

int
guestfs_user_cancel (guestfs_h *g)
{
  g->user_cancel = 1;
  return 0;
}
