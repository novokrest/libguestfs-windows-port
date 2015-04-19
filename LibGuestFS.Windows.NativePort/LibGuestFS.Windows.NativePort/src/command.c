/* libguestfs
 * Copyright (C) 2010-2012 Red Hat Inc.
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

/* Wrapper for running external command, loosely based on libvirt's
 * virCommand interface.  Read the comments at the top of each
 * function for detailed information on how to use this interface.  In
 * outline what you have to do is:
 *
 * (1) Create a new command handle:
 *
 *   struct command *cmd;
 *   cmd = guestfs___new_command (g);
 *
 * (2) EITHER add arguments:
 *
 *   guestfs___cmd_add_arg (cmd, "qemu-img");
 *   guestfs___cmd_add_arg (cmd, "info");
 *   guestfs___cmd_add_arg (cmd, filename);
 *
 * NB: You don't need to add a NULL argument at the end.
 *
 * (3) OR construct a command using a mix of quoted and unquoted
 * strings.  (This is useful for system(3)/popen("r")-style shell
 * commands, with the added safety of allowing args to be quoted
 * properly).
 *
 *   guestfs___cmd_add_string_unquoted (cmd, "qemu-img info ");
 *   guestfs___cmd_add_string_quoted (cmd, filename);
 *
 * (4) Set various flags, such as whether you want to capture
 * errors in the regular libguestfs error log.
 *
 * (5) Run the command.  This is what does the fork call, optionally
 * loops over the output, and then does a waitpid and returns the
 * exit status of the command.
 *
 *   r = guestfs___cmd_run (cmd);
 *   if (r == -1)
 *     // error
 *   // else test r using the WIF* functions
 *
 * (6) Close the handle:
 *
 *   guestfs___cmd_close (cmd);
 *
 * (or use CLEANUP_CMD_CLOSE).
 */

/* https://msdn.microsoft.com/ru-ru/library/edze9h7e.aspx */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <win-unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/wait.h>
//#include <sys/select.h>

#include "guestfs.h"
#include "guestfs-internal.h"

enum command_style {
  COMMAND_STYLE_NOT_SELECTED = 0,
  COMMAND_STYLE_EXECV = 1,
  COMMAND_STYLE_SYSTEM = 2
};

struct command;

static void add_line_buffer (struct command *cmd, const char *buf, size_t len);
static void close_line_buffer (struct command *cmd);
static void add_unbuffered (struct command *cmd, const char *buf, size_t len);
static void add_whole_buffer (struct command *cmd, const char *buf, size_t len);
static void close_whole_buffer (struct command *cmd);

struct buffering {
  char *buffer;
  size_t len;
  void (*add_data) (struct command *cmd, const char *buf, size_t len);
  void (*close_data) (struct command *cmd);
};

struct command
{
  guestfs_h *g;

  enum command_style style;
  union {
    /* COMMAND_STYLE_EXECV */
    struct stringsbuf argv;
    /* COMMAND_STYLE_SYSTEM */
    struct {
      char *str;
      size_t len, alloc;
    } string;
  };

  /* Capture errors to the error log (defaults to true). */
  bool capture_errors;
  HANDLE hStdErr;

  /* Close file descriptors (defaults to true). */
  bool close_files;

  /* Supply a callback to receive stdout. */
  cmd_stdout_callback stdout_callback;
  void *stdout_data;
  HANDLE hStdOut;

  struct buffering outbuf;

  /* For programs that send output to stderr.  Hello qemu. */
  bool stderr_to_stdout;

  /* PID of subprocess (if > 0). */
  PROCESS_INFORMATION piProcInfo;
};

/* Create a new command handle. */
struct command *
guestfs___new_command (guestfs_h *g)
{
  struct command *cmd;

  cmd = safe_calloc (g, 1, sizeof *cmd);
  cmd->g = g;
  cmd->capture_errors = true;
  cmd->close_files = true;
  cmd->hStdErr = NULL;
  cmd->hStdOut = NULL;
  ZeroMemory(&cmd->piProcInfo, sizeof(PROCESS_INFORMATION));

  return cmd;
}

/* Add single arg (for execv-style command execution). */
static void
add_arg_no_strdup (struct command *cmd, char *arg)
{
  assert (cmd->style != COMMAND_STYLE_SYSTEM);
  cmd->style = COMMAND_STYLE_EXECV;

  guestfs___add_string_nodup (cmd->g, &cmd->argv, arg);
}

static void
add_arg (struct command *cmd, const char *arg)
{
  assert (arg != NULL);
  add_arg_no_strdup (cmd, safe_strdup (cmd->g, arg));
}

void
guestfs___cmd_add_arg (struct command *cmd, const char *arg)
{
  add_arg (cmd, arg);
}

void
guestfs___cmd_add_arg_format (struct command *cmd, const char *fs, ...)
{
  va_list args;
  char *arg;
  int err;

  va_start (args, fs);
  err = vasprintf (&arg, fs, args);
  va_end (args);

  if (err < 0)
    cmd->g->abort_cb ();

  add_arg_no_strdup (cmd, arg);
}

/* Add strings (for system(3)-style command execution). */
static void
add_string (struct command *cmd, const char *str, size_t len)
{
  assert (cmd->style != COMMAND_STYLE_EXECV);
  cmd->style = COMMAND_STYLE_SYSTEM;

  if (cmd->string.len >= cmd->string.alloc) {
    if (cmd->string.alloc == 0)
      cmd->string.alloc = 256;
    else
      cmd->string.alloc += MAX (cmd->string.alloc, len);
    cmd->string.str = safe_realloc (cmd->g, cmd->string.str, cmd->string.alloc);
  }

  memcpy (&cmd->string.str[cmd->string.len], str, len);
  cmd->string.len += len;
}

void
guestfs___cmd_add_string_unquoted (struct command *cmd, const char *str)
{
  add_string (cmd, str, strlen (str));
}

/* Add a string enclosed in double quotes, with any special characters
 * within the string which need escaping done.  This is used to add a
 * single argument to a system(3)-style command string.
 */
void
guestfs___cmd_add_string_quoted (struct command *cmd, const char *str)
{
  add_string (cmd, "\"", 1);

  for (; *str; str++) {
    if (*str == '$' ||
        *str == '`' ||
        *str == '\\' ||
        *str == '"')
      add_string (cmd, "\\", 1);
    add_string (cmd, str, 1);
  }

  add_string (cmd, "\"", 1);
}

/* Set a callback which will capture stdout.
 *
 * If flags contains CMD_STDOUT_FLAG_LINE_BUFFER (the default), then
 * the callback is called line by line on the output.  If there is a
 * trailing \n then it is automatically removed before the callback is
 * called.  The line buffer is \0-terminated.
 *
 * If flags contains CMD_STDOUT_FLAG_UNBUFFERED, then buffers are
 * passed to the callback as it is received from the command.  Note in
 * this case the buffer is NOT \0-terminated, so you need to may
 * attention to the length field in the callback.
 *
 * If flags contains CMD_STDOUT_FLAG_WHOLE_BUFFER, then the callback
 * is called exactly once, with the entire buffer.  Note in this case
 * the buffer is NOT \0-terminated, so you need to may attention to
 * the length field in the callback.
 */
void
guestfs___cmd_set_stdout_callback (struct command *cmd,
                                   cmd_stdout_callback stdout_callback,
                                   void *stdout_data, unsigned flags)
{
  cmd->stdout_callback = stdout_callback;
  cmd->stdout_data = stdout_data;

  /* Buffering mode. */
  if ((flags & 3) == CMD_STDOUT_FLAG_LINE_BUFFER) {
    cmd->outbuf.add_data = add_line_buffer;
    cmd->outbuf.close_data = close_line_buffer;
  }
  else if ((flags & 3) == CMD_STDOUT_FLAG_UNBUFFERED) {
    cmd->outbuf.add_data = add_unbuffered;
    cmd->outbuf.close_data = NULL;
  }
  else if ((flags & 3) == CMD_STDOUT_FLAG_WHOLE_BUFFER) {
    cmd->outbuf.add_data = add_whole_buffer;
    cmd->outbuf.close_data = close_whole_buffer;
  }
  else
    abort ();
}

/* Equivalent to adding 2>&1 to the end of the command.  This is
 * incompatible with the capture_errors flag, because it doesn't make
 * sense to combine them.
 */
void
guestfs___cmd_set_stderr_to_stdout (struct command *cmd)
{
  cmd->stderr_to_stdout = true;
}

/* Clear the capture_errors flag.  This means that any errors will go
 * to stderr, instead of being captured in the event log, and that is
 * usually undesirable.
 */
void
guestfs___cmd_clear_capture_errors (struct command *cmd)
{
  cmd->capture_errors = false;
}

/* Don't close file descriptors after the fork.  XXX Should allow
 * single fds to be sent to child process.
 */
void
guestfs___cmd_clear_close_files (struct command *cmd)
{
  cmd->close_files = false;
}

/* Finish off the command by either NULL-terminating the argv array or
 * adding a terminating \0 to the string, or die with an internal
 * error if no command has been added.
 */
static void
finish_command (struct command *cmd)
{
  switch (cmd->style) {
  case COMMAND_STYLE_EXECV:
    guestfs___end_stringsbuf (cmd->g, &cmd->argv);
    break;

  case COMMAND_STYLE_SYSTEM:
    add_string (cmd, "\0", 1);
    break;

  case COMMAND_STYLE_NOT_SELECTED:
    abort ();
  }
}

static void
debug_command (struct command *cmd)
{
  size_t i, last;

  switch (cmd->style) {
  case COMMAND_STYLE_EXECV:
    debug (cmd->g, "command: run: %s", cmd->argv.argv[0]);
    last = cmd->argv.size-1;     /* omit final NULL pointer */
    for (i = 1; i < last; ++i) {
      if (i < last-1 &&
          cmd->argv.argv[i][0] == '-' && cmd->argv.argv[i+1][0] != '-') {
        debug (cmd->g, "command: run: \\ %s %s",
               cmd->argv.argv[i], cmd->argv.argv[i+1]);
        i++;
      }
      else
        debug (cmd->g, "command: run: \\ %s", cmd->argv.argv[i]);
    }
    break;

  case COMMAND_STYLE_SYSTEM:
    debug (cmd->g, "command: run: %s", cmd->string.str);
    break;

  case COMMAND_STYLE_NOT_SELECTED:
    abort ();
  }
}

static int
run_command (struct command *cmd)
{
    HANDLE hStdOut_Wr = NULL, hStdOut_Rd = NULL, hStdErr_Rd = NULL, hStdErr_Wr = NULL;
    SECURITY_ATTRIBUTES saAttr;
    STARTUPINFO siStartInfo;
    char *cmdline = NULL;

    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

  /* Set up a pipe to capture command output and send it to the error log. */
  if (cmd->capture_errors) {
      if (!CreatePipe(&hStdErr_Rd, &hStdOut_Wr, &saAttr, 0) || !SetHandleInformation(hStdErr_Rd, HANDLE_FLAG_INHERIT, 0)) {
          perrorf_win(cmd->g, "CreatePipe");
          goto error;
      }
  }

  /* Set up a pipe to capture stdout for the callback. */
  if (cmd->stdout_callback) {
      if (!CreatePipe(&hStdOut_Rd, &hStdOut_Wr, &saAttr, 0) || !SetHandleInformation(hStdOut_Rd, HANDLE_FLAG_INHERIT, 0)) {
          perrorf_win(cmd->g, "CreatePipe");
          goto error;
      }
  }

  cmd->hStdOut = hStdOut_Rd;
  cmd->hStdErr = hStdErr_Rd;

  ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
  siStartInfo.cb = sizeof(STARTUPINFO);
  if (cmd->stderr_to_stdout) {
      siStartInfo.hStdError = hStdOut_Wr;
  }
  else {
      siStartInfo.hStdError = hStdErr_Wr;
  }
  siStartInfo.hStdOutput = hStdOut_Wr;
  siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

  switch (cmd->style) {
  case COMMAND_STYLE_EXECV:
      cmdline = guestfs___join_strings(" ", cmd->argv.argv);
      break;

  case COMMAND_STYLE_SYSTEM:
      cmdline = cmd->string.str;
      break;

  case COMMAND_STYLE_NOT_SELECTED:
      abort();
  }
  /*NOTREACHED*/


  if (!CreateProcess(NULL,
      cmdline,
      NULL,
      NULL,
      TRUE,
      0,
      NULL,
      NULL,
      &siStartInfo,
      &cmd->piProcInfo)) {
      perrorf_win(cmd->g, "CreateProcess");
      goto error;
  }

  CloseHandle(hStdErr_Wr);
  CloseHandle(hStdOut_Wr);

  return 0;

error:
  cmd->hStdErr = NULL;
  cmd->hStdOut = NULL;

  CloseHandle(hStdErr_Rd);
  CloseHandle(hStdErr_Wr);
  CloseHandle(hStdOut_Rd);
  CloseHandle(hStdOut_Wr);

  return -1;
}

/* The loop which reads errors and output and directs it either
 * to the log or to the stdout callback as appropriate.
 */
static int
loop (struct command *cmd)
{
    DWORD dwRead;
    CHAR buf[BUFSIZ];
    BOOL bSuccess = FALSE;
    size_t n_hdls = 0;

    if (cmd->hStdErr) {
        ++n_hdls;
    }

    if (cmd->hStdOut) {
        ++n_hdls;
    }

    while (n_hdls > 0) {
        if (cmd->hStdErr) {
            bSuccess = ReadFile(cmd->hStdErr, buf, BUFSIZ, &dwRead, NULL);
            if (!bSuccess && GetLastError() != ERROR_BROKEN_PIPE) {
                perrorf_win(cmd->g, "read: errorfd");
                CloseHandle(cmd->hStdErr);
                cmd->hStdErr = NULL;
                --n_hdls;
            }
            /* If anonymous pipe is closed (child returns) than GetLastError() == ERROR_BROKEN_PIPE */
            else if ((!bSuccess && GetLastError() == ERROR_BROKEN_PIPE) || dwRead == 0) {
                CloseHandle(cmd->hStdErr);
                cmd->hStdErr = NULL;
                --n_hdls;
            }
            else if (dwRead > 0) {
                guestfs___call_callbacks_message(cmd->g, GUESTFS_EVENT_APPLIANCE, buf, dwRead);
            }
        }

        if (cmd->hStdOut) {
            bSuccess = ReadFile(cmd->hStdOut, buf, BUFSIZ, &dwRead, NULL);
            if (!bSuccess && GetLastError() != ERROR_BROKEN_PIPE) {
                perrorf_win(cmd->g, "read: outfd");
                CloseHandle(cmd->hStdOut);
                cmd->hStdOut = NULL;
                --n_hdls;
            }
            else if (dwRead > 0) {
                if (cmd->outbuf.add_data)
                    cmd->outbuf.add_data(cmd, buf, dwRead);
            }
            else if ((!bSuccess && GetLastError == ERROR_BROKEN_PIPE) || dwRead == 0) {
                if (cmd->outbuf.close_data)
                    cmd->outbuf.close_data(cmd);
                CloseHandle(cmd->hStdOut);
                cmd->hStdOut = NULL;
                --n_hdls;
            }
        }
    }

  return 0;
}

static int
wait_command (struct command *cmd)
{
  int status;
  int exitcode;

  status = WaitForSingleObject(cmd->piProcInfo.hProcess, INFINITE);
  if (status == WAIT_FAILED) {
      perrorf_win(cmd->g, "WaitForSingleObject");
      return -1;
  }

  if (!GetExitCodeProcess(cmd->piProcInfo.hProcess, &exitcode)) {
      perrorf_win(cmd->g, "GetExitCodeProcess");
      return -1;
  }

  CloseHandle(cmd->piProcInfo.hProcess);
  cmd->piProcInfo.hProcess = INVALID_HANDLE_VALUE;
  CloseHandle(cmd->piProcInfo.hThread);
  cmd->piProcInfo.hThread = INVALID_HANDLE_VALUE;

  return exitcode;
}

/* Fork, run the command, loop over the output, and waitpid.
 *
 * Returns the exit status.  Test it using WIF* macros.
 *
 * On error: Calls error(g) and returns -1.
 */
int
guestfs___cmd_run (struct command *cmd)
{
  finish_command (cmd);

  if (cmd->g->verbose)
    debug_command (cmd);

  if (run_command (cmd) == -1)
    return -1;

  if (loop (cmd) == -1)
    return -1;

  return wait_command (cmd);
}

void
guestfs___cmd_close (struct command *cmd)
{
  if (!cmd)
    return;

  switch (cmd->style) {
  case COMMAND_STYLE_NOT_SELECTED:
    /* nothing */
    break;

  case COMMAND_STYLE_EXECV:
    guestfs___free_stringsbuf (&cmd->argv);
    break;

  case COMMAND_STYLE_SYSTEM:
    free (cmd->string.str);
    break;
  }

  if (cmd->hStdErr)
      CloseHandle(cmd->hStdErr);

  if (cmd->hStdOut)
      CloseHandle(cmd->hStdOut);

  free(cmd->outbuf.buffer);

  if (cmd->piProcInfo.hProcess != INVALID_HANDLE_VALUE)
      WaitForSingleObject(cmd->piProcInfo.hProcess, INFINITE);

  free (cmd);
}

void
guestfs___cleanup_cmd_close (struct command **ptr)
{
  guestfs___cmd_close (*ptr);
}

/* Deal with buffering stdout for the callback. */
static void
process_line_buffer (struct command *cmd, int closed)
{
  guestfs_h *g = cmd->g;
  char *p;
  size_t len, newlen;

  while (cmd->outbuf.len > 0) {
    /* Length of the next line. */
    p = strchr (cmd->outbuf.buffer, '\n');
    if (p != NULL) {            /* Got a whole line. */
      len = p - cmd->outbuf.buffer;
      newlen = cmd->outbuf.len - len - 1;
    }
    else if (closed) {          /* Consume rest of input even if no \n found. */
      len = cmd->outbuf.len;
      newlen = 0;
    }
    else                        /* Need to wait for more input. */
      break;

    /* Call the callback with the next line. */
    cmd->outbuf.buffer[len] = '\0';
    cmd->stdout_callback (g, cmd->stdout_data, cmd->outbuf.buffer, len);

    /* Remove the consumed line from the buffer. */
    cmd->outbuf.len = newlen;
    memmove (cmd->outbuf.buffer, cmd->outbuf.buffer + len + 1, newlen);

    /* Keep the buffer \0 terminated. */
    cmd->outbuf.buffer[newlen] = '\0';
  }
}

static void
add_line_buffer (struct command *cmd, const char *buf, size_t len)
{
  guestfs_h *g = cmd->g;
  size_t oldlen;

  /* Append the new content to the end of the current buffer.  Keep
   * the buffer \0 terminated to make things simple when processing
   * the buffer.
   */
  oldlen = cmd->outbuf.len;
  cmd->outbuf.len += len;
  cmd->outbuf.buffer = safe_realloc (g, cmd->outbuf.buffer,
                                     cmd->outbuf.len + 1 /* for \0 */);
  memcpy (cmd->outbuf.buffer + oldlen, buf, len);
  cmd->outbuf.buffer[cmd->outbuf.len] = '\0';

  process_line_buffer (cmd, 0);
}

static void
close_line_buffer (struct command *cmd)
{
  process_line_buffer (cmd, 1);
}

static void
add_unbuffered (struct command *cmd, const char *buf, size_t len)
{
  cmd->stdout_callback (cmd->g, cmd->stdout_data, buf, len);
}

static void
add_whole_buffer (struct command *cmd, const char *buf, size_t len)
{
  guestfs_h *g = cmd->g;
  size_t oldlen;

  /* Append the new content to the end of the current buffer. */
  oldlen = cmd->outbuf.len;
  cmd->outbuf.len += len;
  cmd->outbuf.buffer = safe_realloc (g, cmd->outbuf.buffer, cmd->outbuf.len);
  memcpy (cmd->outbuf.buffer + oldlen, buf, len);
}

static void
close_whole_buffer (struct command *cmd)
{
  cmd->stdout_callback (cmd->g, cmd->stdout_data,
                        cmd->outbuf.buffer, cmd->outbuf.len);
}
