/* libguestfs
 * Copyright (C) 2013 Red Hat Inc.
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

/* Connection module for regular POSIX sockets. */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <win-unistd.h>
#include <fcntl.h>
#include <errno.h>
//#include <poll.h>
#include <sys/stat.h>
//#include <sys/socket.h>
#include <sys/types.h>
#include <assert.h>

#include <WS2tcpip.h>

#include "guestfs.h"
#include "guestfs-internal.h"

struct connection_socket {
  const struct connection_ops *ops;

  SOCKET console_sock;          /* Appliance console (for debug info). */
  SOCKET daemon_sock;           /* Daemon communications socket. */

  /* Socket for accepting a connection from the daemon.  Only used
   * before and during accept_connection.
   */
  SOCKET daemon_accept_sock;
};

static int handle_log_message (guestfs_h *g, struct connection_socket *conn);

static int
accept_connection (guestfs_h *g, struct connection *connv)
{
  struct connection_socket *conn = (struct connection_socket *) connv;
  int sock = INVALID_SOCKET;
  time_t start_t, now_t;
  struct timeval timeout_ms;
  u_long ulMode;

  time (&start_t);

  if (conn->daemon_accept_sock == INVALID_SOCKET) {
    error(g, _("accept_connection called twice"));
    return -1;
  }

  while (sock == INVALID_SOCKET) {
    fd_set readfds;
    int nfds = 1;
    int r;

    FD_ZERO(&readfds);
    FD_SET(conn->daemon_accept_sock, &readfds);

    if (conn->console_sock != INVALID_SOCKET) {
        FD_SET(conn->console_sock, &readfds);
        nfds++;
    }

    time (&now_t);
    timeout_ms.tv_sec = APPLIANCE_TIMEOUT - (now_t - start_t);
    timeout_ms.tv_usec = 0;

    r = select(0, &readfds, NULL, NULL, &timeout_ms);
    if (r == SOCKET_ERROR) {
      if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
        continue;
      perrorf_wsa (g, "accept_connection: poll");
      return -1;
    }

    if (r == 0) {               /* timeout reached */
      guestfs___launch_timeout (g);
      return -1;
    }

    /* Log message? */
    if (nfds > 1 && FD_ISSET(conn->console_sock, &readfds)) {
      r = handle_log_message (g, conn);
      if (r <= 0)
        return r;
    }

    /* Accept on socket? */
    if (FD_ISSET(conn->daemon_accept_sock, &readfds)) {
      sock = accept(conn->daemon_accept_sock, NULL, NULL);
      if (sock == SOCKET_ERROR) {
        if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
          continue;
        perrorf_wsa (g, "accept_connection: accept");
        return -1;
      }
    }
  }

  /* Got a connection and accepted it, so update the connection's
   * internal status.
   */
  closesocket (conn->daemon_accept_sock);
  conn->daemon_accept_sock = INVALID_SOCKET;
  conn->daemon_sock = sock;

  /* Make sure the new socket is non-blocking. */
  ulMode = 1;
  if (ioctlsocket(conn->daemon_sock, FIONBIO, &ulMode) == SOCKET_ERROR) {
    perrorf_wsa (g, "accept_connection: fcntl");
    return -1;
  }

  return 1;
}

static ssize_t
read_data (guestfs_h *g, struct connection *connv, void *bufv, size_t len)
{
  char *buf = bufv;
  struct connection_socket *conn = (struct connection_socket *) connv;
  size_t original_len = len;

  if (conn->daemon_sock == INVALID_SOCKET) {
    error (g, _("read_data: socket not connected"));
    return -1;
  }

  while (len > 0) {
    fd_set readfds;
    int nfds = 1;
    int r;

    FD_ZERO(&readfds);
    FD_SET(conn->daemon_sock, &readfds);

    if (conn->console_sock != INVALID_SOCKET) {
        FD_SET(conn->console_sock, &readfds);
        nfds++;
    }

    r = select(0, &readfds, NULL, NULL, NULL);
    if (r == SOCKET_ERROR) {
      if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
        continue;
      perrorf_wsa (g, "read_data: poll");
      return -1;
    }

    /* Log message? */
    if (nfds > 1 && FD_ISSET(conn->console_sock, &readfds)) {
      r = handle_log_message (g, conn);
      if (r <= 0)
        return r;
    }

    /* Read data on daemon socket? */
    if (FD_ISSET(conn->daemon_sock, &readfds)) {
      int n = recv(conn->daemon_sock, buf, len, 0);
      if (n == SOCKET_ERROR) {
        if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
          continue;
        if (WSAGetLastError() == WSAECONNRESET) /* essentially the same as EOF case */
          goto closed;
        perrorf_wsa (g, "read_data: read");
        return -1;
      }
      if (n == 0) {
      closed:
        /* Even though qemu has gone away, there could be more log
         * messages in the console socket buffer in the kernel.  Read
         * them out here.
         */
        if (g->verbose && conn->console_sock != INVALID_SOCKET) {
          while (handle_log_message (g, conn) == 1)
            ;
        }
        return 0;
      }

      buf += n;
      len -= n;
    }
  }

  return original_len;
}

static int
can_read_data (guestfs_h *g, struct connection *connv)
{
  struct connection_socket *conn = (struct connection_socket *) connv;
  fd_set readfds;
  int r;
  struct timeval timeout = { .tv_sec = 0, .tv_usec = 0 };

  if (conn->daemon_sock == INVALID_SOCKET) {
    error (g, _("can_read_data: socket not connected"));
    return -1;
  }

again:
  FD_ZERO(&readfds);
  FD_SET(conn->daemon_sock, &readfds);
  r = select(0, &readfds, NULL, NULL, &timeout);
  if (r == SOCKET_ERROR) {
    if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
      goto again;
    perrorf_wsa (g, "can_read_data: poll");
    return -1;
  }

  return FD_ISSET(conn->daemon_sock, &readfds) != 0 ? 1 : 0;
}

static ssize_t
write_data (guestfs_h *g, struct connection *connv,
            const void *bufv, size_t len)
{
  const char *buf = bufv;
  struct connection_socket *conn = (struct connection_socket *) connv;
  size_t original_len = len;

  if (conn->daemon_sock == INVALID_SOCKET) {
    error(g, _("write_data: socket not connected"));
    return -1;
  }

  while (len > 0) {
    fd_set readfds, writefds;
    int nfds = 1;
    int r;

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);

    FD_SET(conn->daemon_sock, &writefds);

    if (conn->console_sock != INVALID_SOCKET) {
        FD_SET(conn->console_sock, &readfds);
        nfds++;
    }

    r = select(0, &readfds, &writefds, NULL, NULL);
    if (r == SOCKET_ERROR) {
      if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
        continue;
      perrorf_wsa (g, "write_data: select");
      return -1;
    }

    /* Log message? */
    if (nfds > 1 && FD_ISSET(conn->console_sock, &readfds)) {
      r = handle_log_message (g, conn);
      if (r <= 0)
        return r;
    }

    /* Can write data on daemon socket? */
    if (FD_ISSET(conn->daemon_sock, &writefds)) {
      int n = send(conn->daemon_sock, buf, len, 0);
      if (n == SOCKET_ERROR) {
        if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
          continue;
        if (WSAGetLastError() == WSAECONNRESET) /* Disconnected from guest (RHBZ#508713). */
          return 0;
        perrorf_wsa (g, "write_data: write");
        return -1;
      }

      buf += n;
      len -= n;
    }
  }

  return original_len;
}

/* This is called if conn->console_sock becomes ready to read while we
 * are doing one of the connection operations above.  It reads and
 * deals with the log message.
 *
 * Returns:
 *   1 = log message(s) were handled successfully
 *   0 = connection to appliance closed
 *  -1 = error
 */
static int
handle_log_message (guestfs_h *g,
                    struct connection_socket *conn)
{
  char buf[BUFSIZ];
  ssize_t n;

  /* Carried over from ancient proto.c code.  The comment there was:
   *
   *   "QEMU's console emulates a 16550A serial port.  The real 16550A
   *   device has a small FIFO buffer (16 bytes) which means here we
   *   see lots of small reads of 1-16 bytes in length, usually single
   *   bytes.  Sleeping here for a very brief period groups reads
   *   together (so we usually get a few lines of output at once) and
   *   improves overall throughput, as well as making the event
   *   interface a bit more sane for callers.  With a virtio-serial
   *   based console (not yet implemented) we may be able to remove
   *   this.  XXX"
   */
  Sleep(1);

  n = recv(conn->console_sock, buf, sizeof buf, 0);
  if (n == 0)
    return 0;

  if (n == SOCKET_ERROR) {
    if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK)
      return 1; /* not an error */

    perrorf_wsa (g, _("error reading console messages from the appliance"));
    return -1;
  }

  /* It's an actual log message, send it upwards. */
  guestfs___log_message_callback (g, buf, n);

#ifdef VALGRIND_DAEMON
  /* Find the canary printed by appliance/init if valgrinding of the
   * daemon fails, and exit abruptly.  Note this is only used in
   * developer builds, and should never be enabled in ordinary/
   * production builds.
   */
  if (g->verbose) {
    const char *valgrind_canary = "DAEMON VALGRIND FAILED";

    if (memmem (buf, n, valgrind_canary, strlen (valgrind_canary)) != NULL) {
      fprintf (stderr,
               "Detected valgrind failure in the daemon!  Exiting with exit code 119.\n"
               "See log messages printed above.\n"
               "Note: This happens because libguestfs was configured with\n"
               "'--enable-valgrind-daemon' which should not be used in production builds.\n");
      exit (119);
    }
  }
#endif

  return 1;
}

static void
free_conn_socket (guestfs_h *g, struct connection *connv)
{
  struct connection_socket *conn = (struct connection_socket *) connv;

  if (conn->console_sock != INVALID_SOCKET)
    closesocket (conn->console_sock);
  if (conn->daemon_sock != INVALID_SOCKET)
    closesocket (conn->daemon_sock);
  if (conn->daemon_accept_sock != INVALID_SOCKET)
    closesocket (conn->daemon_accept_sock);

  free (conn);
}

static struct connection_ops ops = {
  .free_connection = free_conn_socket,
  .accept_connection = accept_connection,
  .read_data = read_data,
  .write_data = write_data,
  .can_read_data = can_read_data,
};

/* Create a new socket connection, listening.
 *
 * Note that it's OK for console_sock to be passed as -1, meaning
 * there's no console available for this appliance.
 *
 * After calling this, daemon_accept_sock is owned by the connection,
 * and will be closed properly either in accept_connection or
 * free_connection.
 */
struct connection *
guestfs___new_conn_socket_listening (guestfs_h *g,
                                     int daemon_accept_sock,
                                     int console_sock)
{
  struct connection_socket *conn;
  u_long ulMode = 1;

  assert (daemon_accept_sock != INVALID_SOCKET);

  if (ioctlsocket(daemon_accept_sock, FIONBIO, &ulMode) == SOCKET_ERROR) {
    perrorf_wsa(g, "new_conn_socket_listening: fcntl");
    return NULL;
  }

  if (console_sock != INVALID_SOCKET) {
    if (ioctlsocket(console_sock, FIONBIO, &ulMode) == SOCKET_ERROR) {
      perrorf_wsa(g, "new_conn_socket_listening: fcntl");
      return NULL;
    }
  }

  conn = safe_malloc (g, sizeof *conn);

  /* Set the operations. */
  conn->ops = &ops;

  /* Set the internal state. */
  conn->console_sock = console_sock;
  conn->daemon_sock = INVALID_SOCKET;
  conn->daemon_accept_sock = daemon_accept_sock;

  return (struct connection *) conn;
}

/* Create a new socket connection, connected.
 *
 * As above, but the caller passes us a connected daemon_sock
 * and promises not to call accept_connection.
 */
struct connection *
guestfs___new_conn_socket_connected (guestfs_h *g,
                                     int daemon_sock,
                                     int console_sock)
{
  struct connection_socket *conn;
  u_long ulMode = 1;

  assert(daemon_sock != INVALID_SOCKET);

  if (ioctlsocket(daemon_sock, FIONBIO, &ulMode) == SOCKET_ERROR) {
    perrorf_wsa(g, "new_conn_socket_connected: ioctlsocket");
    return NULL;
  }

  if (console_sock != INVALID_SOCKET) {
    if (ioctlsocket(console_sock, FIONBIO, &ulMode) == SOCKET_ERROR) {
      perrorf_wsa(g, "new_conn_socket_connected: ioctlsocket");
      return NULL;
    }
  }


  conn = safe_malloc (g, sizeof *conn);

  /* Set the operations. */
  conn->ops = &ops;

  /* Set the internal state. */
  conn->console_sock = console_sock;
  conn->daemon_sock = daemon_sock;
  conn->daemon_accept_sock = INVALID_SOCKET;

  return (struct connection *) conn;
}
