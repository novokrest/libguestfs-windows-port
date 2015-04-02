/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009-2014 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <inttypes.h>
#include <unistd.h>
#include <errno.h>
#include <sys/param.h>		/* defines MIN */
#include <sys/select.h>
#include <sys/time.h>

#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif

#include "c-ctype.h"

#include "daemon.h"
#include "guestfs_protocol.h"
#include "errnostring.h"

/* The message currently being processed. */
int proc_nr;
int serial;

/* Hint for implementing progress messages for uploaded/incoming data.
 * The caller sets this to a value > 0 if it knows or can estimate how
 * much data will be sent (this is not always known, eg. for uploads
 * coming from a pipe).  If this is known then we can emit progress
 * messages as we write the data.
 */
uint64_t progress_hint;

/* Optional arguments bitmask.  Caller sets this to indicate which
 * optional arguments in the guestfs_<foo>_args structure are
 * meaningful.  Optional arguments not covered by the bitmask are set
 * to arbitrary values and the daemon should ignore them.  If the
 * bitmask has bits set that the daemon doesn't understand, then the
 * whole call is rejected early in processing.
 */
uint64_t optargs_bitmask;

/* Time at which we received the current request. */
static struct timeval start_t;

/* Time at which the last progress notification was sent. */
static struct timeval last_progress_t;

/* Counts the number of progress notifications sent during this call. */
static size_t count_progress;

/* The daemon communications socket. */
static int sock;

void
main_loop (int _sock)
{
  char *buf;
  char lenbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  uint32_t len;
  guestfs_protobuf_flag_message *flagmsg;
  guestfs_protobuf_message_header *hdr;

  sock = _sock;

  for (;;) {
    /* Read the length word. */
    if (xread (sock, lenbuf, PROTOBUF_FLAG_MESSAGE_SIZE) == -1)
      exit (EXIT_FAILURE);

    flagmsg = guestfs_protobuf_flag_message__unpack (NULL, PROTOBUF_FLAG_MESSAGE_SIZE, lenbuf);
    len = flagmsg->val;
    guestfs_protobuf_flag_message__free_unpacked (flagmsg, NULL);

    if (verbose)
      fprintf (stderr,
	       "guestfsd: main_loop: new request, len 0x%" PRIx32 "\n",
	       len);

    /* Cancellation sent from the library and received after the
     * previous request has finished processing.  Just ignore it.
     */
    if (len == GUESTFS_CANCEL_FLAG)
      continue;

    if (len > GUESTFS_MESSAGE_MAX) {
      fprintf (stderr, "guestfsd: incoming message is too long (%u bytes)\n",
               len);
      exit (EXIT_FAILURE);
    }

    buf = malloc (len);
    if (!buf) {
      reply_with_perror ("malloc");
      continue;
    }

    if (xread (sock, buf, len) == -1)
      exit (EXIT_FAILURE);

#ifdef ENABLE_PACKET_DUMP
    if (verbose) {
      size_t i, j;

      for (i = 0; i < len; i += 16) {
        printf ("%04zx: ", i);
        for (j = i; j < MIN (i+16, len); ++j)
          printf ("%02x ", (unsigned char) buf[j]);
        for (; j < i+16; ++j)
          printf ("   ");
        printf ("|");
        for (j = i; j < MIN (i+16, len); ++j)
          if (c_isprint (buf[j]))
            printf ("%c", buf[j]);
          else
            printf (".");
        for (; j < i+16; ++j)
          printf (" ");
        printf ("|\n");
      }
    }
#endif

    gettimeofday (&start_t, NULL);
    last_progress_t = start_t;
    count_progress = 0;

    /* Decode the message header. */
    hdr = guestfs_protobuf_message_header__unpack (NULL, PROTOBUF_MESSAGE_HEADER_SIZE, buf);
    if (!hdr) {
      fprintf (stderr, "guestfsd: could not decode message header\n");
      exit (EXIT_FAILURE);
    }

    /* Check the version etc. */
    if (hdr->prog != GUESTFS_PROGRAM) {
      reply_with_error ("wrong program (%d)", hdr->prog);
      goto cont;
    }
    if (hdr->vers != GUESTFS_PROTOCOL_VERSION) {
      reply_with_error ("wrong protocol version (%d)", hdr->vers);
      goto cont;
    }
    if (hdr->direction != GUESTFS_DIRECTION_CALL) {
      reply_with_error ("unexpected message direction (%d)", hdr->direction);
      goto cont;
    }
    if (hdr->status != GUESTFS_STATUS_OK) {
      reply_with_error ("unexpected message status (%d)", hdr->status);
      goto cont;
    }

    proc_nr = hdr->proc;
    serial = hdr->serial;
    progress_hint = hdr->progress_hint;
    optargs_bitmask = hdr->optargs_bitmask;

    /* Clear errors before we call the stub functions.  This is just
     * to ensure that we can accurately report errors in cases where
     * error handling paths don't set errno correctly.
     */
    errno = 0;
#ifdef WIN32
    SetLastError (0);
    WSASetLastError (0);
#endif

    /* Now start to process this message. */
    dispatch_incoming_message (buf + PROTOBUF_MESSAGE_HEADER_SIZE, len - PROTOBUF_MESSAGE_HEADER_SIZE);
    /* Note that dispatch_incoming_message will also send a reply. */

    /* In verbose mode, display the time taken to run each command. */
    if (verbose) {
      struct timeval end_t;
      gettimeofday (&end_t, NULL);

      int64_t start_us, end_us, elapsed_us;
      start_us = (int64_t) start_t.tv_sec * 1000000 + start_t.tv_usec;
      end_us = (int64_t) end_t.tv_sec * 1000000 + end_t.tv_usec;
      elapsed_us = end_us - start_us;

      fprintf (stderr,
	       "guestfsd: main_loop: proc %d (%s) took %d.%02d seconds\n",
               proc_nr,
               proc_nr >= 0 && proc_nr <= GUESTFS_MAX_PROC_NR
               ? function_names[proc_nr] : "UNKNOWN PROCEDURE",
               (int) (elapsed_us / 1000000),
               (int) ((elapsed_us / 10000) % 100));
    }

  cont:
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    free (buf);
  }
}

static void send_error (int errnum, char *msg);

void
reply_with_error_errno (int err, const char *fs, ...)
{
  CLEANUP_FREE char *buf = NULL;
  va_list args;
  int r;

  va_start (args, fs);
  r = vasprintf (&buf, fs, args);
  va_end (args);

  if (r == -1) {
    perror ("vasprintf");
    exit (EXIT_FAILURE);
  }

  send_error (err, buf);
}

void
reply_with_perror_errno (int err, const char *fs, ...)
{
  CLEANUP_FREE char *buf1 = NULL;
  CLEANUP_FREE char *buf2 = NULL;
  va_list args;
  int r;

  va_start (args, fs);
  r = vasprintf (&buf1, fs, args);
  va_end (args);

  if (r == -1) {
  error:
    perror ("vasprintf");
    exit (EXIT_FAILURE);
  }

  r = asprintf (&buf2, "%s: %s", buf1, strerror (err));
  if (r == -1)
    goto error;

  send_error (err, buf2);
}

static void
send_error (int errnum, char *msg)
{
  CLEANUP_FREE char *buf = NULL;
  char lenbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  guestfs_protobuf_flag_message flagmsg;
  guestfs_protobuf_message_header hdr;
  guestfs_protobuf_message_error err;
  unsigned len, flaglen, hdrlen, errlen;

  /* Print the full length error message. */
  fprintf (stderr, "guestfsd: error: %s\n", msg);

  /* We want to truncate the error message to GUESTFS_ERROR_LEN bytes
   * (not including the \0 since it is not encoded in XDR).  This is
   * so that the xdr_guestfs_message_error call below won't fail on
   * very long error messages.  We can overwrite the message since all
   * callers of send_error pass a temporary buffer.
   */
  if (strlen (msg) > GUESTFS_ERROR_LEN)
    msg[GUESTFS_ERROR_LEN] = '\0';

  buf = malloc (GUESTFS_ERROR_LEN + 200);
  if (!buf) {
    perror ("malloc");
    exit (EXIT_FAILURE);
  }

  guestfs_protobuf_message_header__init (&hdr);
  hdr.prog = GUESTFS_PROGRAM;
  hdr.vers = GUESTFS_PROTOCOL_VERSION;
  hdr.direction = GUESTFS_DIRECTION_REPLY;
  hdr.status = GUESTFS_STATUS_ERROR;
  hdr.proc = proc_nr;
  hdr.serial = serial;
  
  hdrlen = guestfs_protobuf_message_header__pack (&hdr, buf);
  assert (hdrlen == PROTOBUF_MESSAGE_HEADER_SIZE);

  if (!hdrlen) {
    fprintf (stderr, "guestfsd: failed to encode error message header\n");
    exit (EXIT_FAILURE);
  }

  /* These strings are not going to be freed.  We just cast them
   * to (char *) because they are defined that way in the XDR structs.
   */
  guestfs_protobuf_message_error__init (&err);
  err.errno_string =
    (char *) (errnum > 0 ? guestfs___errno_to_string (errnum) : "");
  err.error_message = (char *) msg;

  errlen = guestfs_protobuf_message_error__pack (&err, buf + PROTOBUF_MESSAGE_HEADER_SIZE);

  if (!errlen) {
    fprintf (stderr, "guestfsd: failed to encode error message body\n");
    exit (EXIT_FAILURE);
  }

  len = hdrlen + errlen;

  guestfs_protobuf_flag_message__init (&flagmsg);
  flagmsg.val = len;
  flaglen = guestfs_protobuf_flag_message__pack (&flagmsg, lenbuf);
  assert (flaglen == PROTOBUF_FLAG_MESSAGE_SIZE);

  if (xwrite (sock, lenbuf, PROTOBUF_FLAG_MESSAGE_SIZE) == -1) {
    fprintf (stderr, "guestfsd: xwrite failed\n");
    exit (EXIT_FAILURE);
  }
  if (xwrite (sock, buf, len) == -1) {
    fprintf (stderr, "guestfsd: xwrite failed\n");
    exit (EXIT_FAILURE);
  }
}

void
reply (protobuf_proc_pack pb_pack, char *ret)
{
  CLEANUP_FREE char *buf = NULL;
  char lenbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  guestfs_protobuf_flag_message flagmsg;
  guestfs_protobuf_message_header hdr;
  uint32_t len, flaglen, hdrlen, retlen;

  buf = malloc (GUESTFS_MESSAGE_MAX);
  if (!buf) {
    perror ("malloc");
    exit (EXIT_FAILURE);
  }

  guestfs_protobuf_message_header__init (&hdr);
  hdr.prog = GUESTFS_PROGRAM;
  hdr.vers = GUESTFS_PROTOCOL_VERSION;
  hdr.direction = GUESTFS_DIRECTION_REPLY;
  hdr.status = GUESTFS_STATUS_OK;
  hdr.proc = proc_nr;
  hdr.serial = serial;

  hdrlen = guestfs_protobuf_message_header__pack (&hdr, buf);
  assert (hdrlen == PROTOBUF_MESSAGE_HEADER_SIZE);

  if (!hdrlen) {
    fprintf (stderr, "guestfsd: failed to encode reply header\n");
    exit (EXIT_FAILURE);
  }

  retlen = 0;
  if (pb_pack) {
    /* This can fail if the reply body is too large, for example
     * if it exceeds the maximum message size.  In that case
     * we want to return an error message instead. (RHBZ#509597).
     */
    retlen = pb_pack ((ProtobufCMessage*) ret, buf + PROTOBUF_MESSAGE_HEADER_SIZE);
    if (!retlen || retlen > GUESTFS_MESSAGE_MAX) {
      reply_with_error ("guestfsd: failed to encode reply body\n(maybe the reply exceeds the maximum message size in the protocol?)");
      return;
    }
  }

  len = hdrlen + retlen;

  guestfs_protobuf_flag_message__init (&flagmsg);
  flagmsg.val = len;
  flaglen = guestfs_protobuf_flag_message__pack (&flagmsg, lenbuf);
  assert (flaglen == PROTOBUF_FLAG_MESSAGE_SIZE);

  if (xwrite (sock, lenbuf, PROTOBUF_FLAG_MESSAGE_SIZE) == -1) {
    fprintf (stderr, "guestfsd: xwrite failed\n");
    exit (EXIT_FAILURE);
  }
  if (xwrite (sock, buf, (size_t) len) == -1) {
    fprintf (stderr, "guestfsd: xwrite failed\n");
    exit (EXIT_FAILURE);
  }
}

/* Receive file chunks, repeatedly calling 'cb'. */
int
receive_file (receive_cb cb, void *opaque)
{
  guestfs_protobuf_chunk *chunk;
  guestfs_protobuf_flag_message *flagmsg;
  char lenbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  int r;
  uint32_t len;

  for (;;) {
    CLEANUP_FREE char *buf = NULL;

    if (verbose)
      fprintf (stderr, "guestfsd: receive_file: reading length word\n");

    /* Read the length word. */
    if (xread (sock, lenbuf, PROTOBUF_FLAG_MESSAGE_SIZE) == -1)
      exit (EXIT_FAILURE);

    flagmsg = guestfs_protobuf_flag_message__unpack (NULL, PROTOBUF_FLAG_MESSAGE_SIZE, lenbuf);
    len = flagmsg->val;
    guestfs_protobuf_flag_message__free_unpacked (flagmsg, NULL);

    if (len == GUESTFS_CANCEL_FLAG)
      continue;			/* Just ignore it. */

    if (len > GUESTFS_MESSAGE_MAX) {
      fprintf (stderr, "guestfsd: incoming message is too long (%u bytes)\n",
               len);
      exit (EXIT_FAILURE);
    }

    buf = malloc (len);
    if (!buf) {
      perror ("malloc");
      return -1;
    }

    if (xread (sock, buf, len) == -1)
      exit (EXIT_FAILURE);

    chunk = guestfs_protobuf_chunk__unpack (NULL, len, buf);
    if (!chunk) {
      return -1;
    }

    if (verbose)
      fprintf (stderr,
               "guestfsd: receive_file: got chunk: cancel = 0x%x, len = %zd, buf = %p\n",
               chunk->cancel, chunk->data.len, chunk->data.data);

    if (chunk->cancel != 0 && chunk->cancel != 1) {
      fprintf (stderr,
               "guestfsd: receive_file: chunk.cancel != [0|1] ... "
               "continuing even though we have probably lost synchronization with the library\n");
      return -1;
    }

    if (chunk->cancel) {
      if (verbose)
        fprintf (stderr,
	  "guestfsd: receive_file: received cancellation from library\n");
      guestfs_protobuf_chunk__free_unpacked (chunk, NULL);
      return -2;
    }
    if (chunk->data.len == 0) {
      if (verbose)
        fprintf (stderr,
		 "guestfsd: receive_file: end of file, leaving function\n");
      guestfs_protobuf_chunk__free_unpacked (chunk, NULL);
      return 0;			/* end of file */
    }

    /* Note that the callback can generate progress messages. */
    if (cb)
      r = cb (opaque, chunk->data.data, chunk->data.len);
    else
      r = 0;

    guestfs_protobuf_chunk__free_unpacked (chunk, NULL);
    if (r == -1) {		/* write error */
      if (verbose)
        fprintf (stderr, "guestfsd: receive_file: write error\n");
      return -1;
    }
  }
}

/* Send a cancellation flag back to the library. */
int
cancel_receive (void)
{
  char flagbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  guestfs_protobuf_flag_message flagmsg;
  uint32_t flag = GUESTFS_CANCEL_FLAG, flaglen;

  guestfs_protobuf_flag_message__init (&flagmsg);
  flagmsg.val = flag;
  flaglen = guestfs_protobuf_flag_message__pack (&flagmsg, flagbuf);
  assert (flaglen == PROTOBUF_FLAG_MESSAGE_SIZE);

  if (xwrite (sock, flagbuf, sizeof flagbuf) == -1) {
    perror ("write to socket");
    return -1;
  }

  /* Keep receiving chunks and discarding, until library sees cancel. */
  return receive_file (NULL, NULL);
}

static int check_for_library_cancellation (void);
static int send_chunk (const guestfs_protobuf_chunk *);

/* Also check if the library sends us a cancellation message. */
int
send_file_write (const void *buf, size_t len)
{
  guestfs_protobuf_chunk chunk;
  int cancel;

  if (len > GUESTFS_MAX_CHUNK_SIZE) {
    fprintf (stderr, "guestfsd: send_file_write: len (%zu) > GUESTFS_MAX_CHUNK_SIZE (%d)\n",
             len, GUESTFS_MAX_CHUNK_SIZE);
    return -1;
  }

  cancel = check_for_library_cancellation ();

  if (cancel) {
    chunk.cancel = 1;
    chunk.data.len = 0;
    chunk.data.data = NULL;
  } else {
    chunk.cancel = 0;
    chunk.data.len = len;
    chunk.data.data = (char *) buf;
  }

  if (send_chunk (&chunk) == -1)
    return -1;

  if (cancel) return -2;
  return 0;
}

static int
check_for_library_cancellation (void)
{
  fd_set rset;
  struct timeval tv;
  int r;
  char buf[PROTOBUF_FLAG_MESSAGE_SIZE];
  uint32_t flag;
  guestfs_protobuf_flag_message *flagmsg;

  FD_ZERO (&rset);
  FD_SET (sock, &rset);
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  r = select (sock+1, &rset, NULL, NULL, &tv);
  if (r == -1) {
    perror ("select");
    return 0;
  }
  if (r == 0)
    return 0;

  /* Read the message from the daemon. */
  r = xread (sock, buf, sizeof buf);
  if (r == -1)
    return 0;

  flagmsg = guestfs_protobuf_flag_message__unpack (NULL, PROTOBUF_FLAG_MESSAGE_SIZE, buf);
  flag = flagmsg->val;
  guestfs_protobuf_flag_message__free_unpacked (flagmsg, NULL);

  if (flag != GUESTFS_CANCEL_FLAG) {
    fprintf (stderr, "guestfsd: check_for_library_cancellation: read 0x%x from library, expected 0x%x\n",
             flag, GUESTFS_CANCEL_FLAG);
    return 0;
  }

  return 1;
}

int
send_file_end (int cancel)
{
  guestfs_protobuf_chunk chunk;

  chunk.cancel = cancel;
  chunk.data.len = 0;
  chunk.data.data = NULL;
  return send_chunk (&chunk);
}

static int
send_chunk (const guestfs_protobuf_chunk *chunk)
{
  char buf[GUESTFS_MAX_CHUNK_SIZE + 48];
  char lenbuf[PROTOBUF_FLAG_MESSAGE_SIZE];
  guestfs_protobuf_flag_message flagmsg;
  uint32_t len, flaglen;

  len = guestfs_protobuf_chunk__pack (chunk, buf);
  if (!len) {
    fprintf (stderr, "guestfsd: send_chunk: failed to encode chunk\n");
    return -1;
  }

  guestfs_protobuf_flag_message__init (&flagmsg);
  flagmsg.val = len;
  flaglen = guestfs_protobuf_flag_message__pack (&flagmsg, lenbuf);
  assert (flaglen == PROTOBUF_FLAG_MESSAGE_SIZE);

  int err = (xwrite (sock, lenbuf, PROTOBUF_FLAG_MESSAGE_SIZE) == 0
             && xwrite (sock, buf, len) == 0 ? 0 : -1);
  if (err) {
    fprintf (stderr, "guestfsd: send_chunk: write failed\n");
    exit (EXIT_FAILURE);
  }

  return err;
}

/* Initial delay before sending notification messages, and
 * the period at which we send them thereafter.  These times
 * are in microseconds.
 */
#define NOTIFICATION_INITIAL_DELAY 2000000
#define NOTIFICATION_PERIOD         333333

void
notify_progress (uint64_t position, uint64_t total)
{
  struct timeval now_t;
  int64_t last_us, now_us, elapsed_us;

  gettimeofday (&now_t, NULL);

  /* Always send a notification at 100%.  This simplifies callers by
   * allowing them to 'finish' the progress bar at 100% without
   * needing special code.
   */
  if (count_progress > 0 && position == total) {
    notify_progress_no_ratelimit (position, total, &now_t);
    return;
  }

  /* Calculate time in microseconds since the last progress message
   * was sent out (or since the start of the call).
   */
  last_us =
    (int64_t) last_progress_t.tv_sec * 1000000 + last_progress_t.tv_usec;
  now_us = (int64_t) now_t.tv_sec * 1000000 + now_t.tv_usec;
  elapsed_us = now_us - last_us;

  /* Rate limit. */
  if ((count_progress == 0 && elapsed_us < NOTIFICATION_INITIAL_DELAY) ||
      (count_progress > 0 && elapsed_us < NOTIFICATION_PERIOD))
    return;

  notify_progress_no_ratelimit (position, total, &now_t);
}

void
notify_progress_no_ratelimit (uint64_t position, uint64_t total,
                              const struct timeval *now_t)
{
  char buf[PROTOBUF_PROGRESS_MESSAGE_SIZE];
  uint32_t i;
  size_t len, flaglen;
  guestfs_protobuf_flag_message flagmsg;
  guestfs_protobuf_progress message;

  count_progress++;
  last_progress_t = *now_t;

  /* Send the header word. */
  i = GUESTFS_PROGRESS_FLAG;
  
  guestfs_protobuf_flag_message__init (&flagmsg);
  flagmsg.val = i;
  flaglen = guestfs_protobuf_flag_message__pack (&flagmsg, buf);
  assert (flaglen == PROTOBUF_FLAG_MESSAGE_SIZE);

  if (xwrite (sock, buf, PROTOBUF_FLAG_MESSAGE_SIZE) == -1) {
    fprintf (stderr, "guestfsd: xwrite failed\n");
    exit (EXIT_FAILURE);
  }

  guestfs_protobuf_progress__init (&message);
  message.proc = proc_nr;
  message.serial = serial;
  message.position = position;
  message.total = total;

  len = guestfs_protobuf_progress__pack (&message, buf);
  assert (len == PROTOBUF_PROGRESS_MESSAGE_SIZE);
  if (!len) {
    fprintf (stderr, "guestfsd: xdr_guestfs_progress: failed to encode message\n");
    return;
  }
  
  if (xwrite (sock, buf, len) == -1) {
    fprintf (stderr, "guestfsd: xwrite failed\n");
    exit (EXIT_FAILURE);
  }
}

/* "Pulse mode" progress messages. */

#if defined(HAVE_SETITIMER) && defined(HAVE_SIGACTION)

static void async_safe_send_pulse (int sig);

void
pulse_mode_start (void)
{
  struct sigaction act;
  struct itimerval it;

  memset (&act, 0, sizeof act);
  act.sa_handler = async_safe_send_pulse;
  act.sa_flags = SA_RESTART;

  if (sigaction (SIGALRM, &act, NULL) == -1) {
    perror ("pulse_mode_start: sigaction");
    return;
  }

  it.it_value.tv_sec = NOTIFICATION_INITIAL_DELAY / 1000000;
  it.it_value.tv_usec = NOTIFICATION_INITIAL_DELAY % 1000000;
  it.it_interval.tv_sec = NOTIFICATION_PERIOD / 1000000;
  it.it_interval.tv_usec = NOTIFICATION_PERIOD % 1000000;

  if (setitimer (ITIMER_REAL, &it, NULL) == -1)
    perror ("pulse_mode_start: setitimer");
}

void
pulse_mode_end (void)
{
  pulse_mode_cancel ();         /* Cancel the itimer. */

  notify_progress (1, 1);
}

void
pulse_mode_cancel (void)
{
  int err = errno;              /* Function must preserve errno. */
  struct itimerval it;
  struct sigaction act;

  /* Setting it_value to zero cancels the itimer. */
  it.it_value.tv_sec = 0;
  it.it_value.tv_usec = 0;
  it.it_interval.tv_sec = 0;
  it.it_interval.tv_usec = 0;

  if (setitimer (ITIMER_REAL, &it, NULL) == -1)
    perror ("pulse_mode_cancel: setitimer");

  memset (&act, 0, sizeof act);
  act.sa_handler = SIG_DFL;

  if (sigaction (SIGALRM, &act, NULL) == -1)
    perror ("pulse_mode_cancel: sigaction");

  errno = err;
}

/* Send a position = 0, total = 1 (pulse mode) message.  The tricky
 * part is we have to do it without invoking any non-async-safe
 * functions (see signal(7) for a list).  Therefore, KISS.
 */
static void
async_safe_send_pulse (int sig)
{
  /* XDR is a RFC ... */
  unsigned char msg[] = {
    (GUESTFS_PROGRESS_FLAG & 0xff000000) >> 24,
    (GUESTFS_PROGRESS_FLAG & 0x00ff0000) >> 16,
    (GUESTFS_PROGRESS_FLAG & 0x0000ff00) >> 8,
    GUESTFS_PROGRESS_FLAG & 0x000000ff,
    (proc_nr & 0xff000000) >> 24,
    (proc_nr & 0x00ff0000) >> 16,
    (proc_nr & 0x0000ff00) >> 8,
    proc_nr & 0x000000ff,
    (serial & 0xff000000) >> 24,
    (serial & 0x00ff0000) >> 16,
    (serial & 0x0000ff00) >> 8,
    serial & 0x000000ff,
    /* 64 bit position = 0 */ 0, 0, 0, 0, 0, 0, 0, 0,
    /* 64 bit total = 1 */    0, 0, 0, 0, 0, 0, 0, 1
  };

  if (xwrite (sock, msg, sizeof msg) == -1)
    exit (EXIT_FAILURE);
}

#else /* !HAVE_SETITIMER || !HAVE_SIGACTION */

void
pulse_mode_start (void)
{
  /* empty */
}

void
pulse_mode_end (void)
{
  /* empty */
}

void
pulse_mode_cancel (void)
{
  /* empty */
}

#endif /* !HAVE_SETITIMER || !HAVE_SIGACTION */
