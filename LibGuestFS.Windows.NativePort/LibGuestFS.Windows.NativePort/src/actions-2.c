/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"
#include "errnostring.h"

GUESTFS_DLL_PUBLIC int
guestfs_internal_test_rinterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rinterr", 21);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rinterr");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rinterr (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rinterr");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rinterr", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_internal_test_rconstoptstringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rconstoptstringerr", 32);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rconstoptstringerr");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rconstoptstringerr (g);

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_test_rconstoptstringerr");
    fprintf (trace_buffer.fp, "\"%s\"", r != NULL ? r : "NULL");
    guestfs___trace_send_line (g, &trace_buffer);
  }


  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_internal_test_rbufferout (guestfs_h *g,
                                  const char *val,
                                  size_t *size_r)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rbufferout", 24);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rbufferout", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rbufferout");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rbufferout (g, val, size_r);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rbufferout");
      guestfs___print_BufferOut (trace_buffer.fp, r, *size_r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rbufferout", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_test_set_output (guestfs_h *g,
                                  const char *filename)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_set_output", 24);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_set_output", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_set_output");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_set_output (g, filename);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_set_output");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_set_output", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_test_close_output (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_close_output", 26);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_close_output");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_close_output (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_close_output");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_close_output", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_kill_subprocess (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "kill_subprocess", 15);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "kill_subprocess");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__kill_subprocess (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "kill_subprocess");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "kill_subprocess", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_path (guestfs_h *g,
                  const char *searchpath)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_path");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_path", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_path");
    if (searchpath)
      fprintf (trace_buffer.fp, " \"%s\"", searchpath);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_path (g, searchpath);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_path");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_path", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_launching (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_launching", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_launching");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__is_launching (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "is_launching");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_launching", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_file_architecture (guestfs_h *g,
                           const char *filename)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "file_architecture", 17);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "file_architecture", "filename");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "file_architecture");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__file_architecture (g, filename);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "file_architecture");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file_architecture", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_arch (guestfs_h *g,
                          const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_arch", 16);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_arch", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_arch");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_arch (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_arch");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_arch", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_add_drive_opts_argv (guestfs_h *g,
                             const char *filename,
                             const struct guestfs_add_drive_opts_argv *optargs)
{
  struct guestfs_add_drive_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive", 9);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_opts", "filename");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK) &&
      optargs->format == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "format");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK) &&
      optargs->iface == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "iface");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK) &&
      optargs->name == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "name");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "label");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK) &&
      optargs->protocol == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "protocol");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK) &&
      optargs->server == NULL) {
    error (g, "%s: %s: optional list cannot be NULL",
           "add_drive_opts", "server");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK) &&
      optargs->username == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "username");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK) &&
      optargs->secret == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "secret");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK) &&
      optargs->cachemode == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "cachemode");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK) &&
      optargs->discard == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "discard");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffff000)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "add_drive_opts", "add_drive_opts");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "add_drive");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "readonly", optargs->readonly ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "format", optargs->format);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "iface", optargs->iface);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "name", optargs->name);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "label", optargs->label);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "protocol", optargs->protocol);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:", "server");
      for (i = 0; optargs->server[i] != NULL; ++i) {
        if (i > 0) fputc (' ', trace_buffer.fp);
        fputs (optargs->server[i], trace_buffer.fp);
      }
      fputc ('\"', trace_buffer.fp);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "username", optargs->username);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "secret", optargs->secret);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "cachemode", optargs->cachemode);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "discard", optargs->discard);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "copyonread", optargs->copyonread ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__add_drive_opts (g, filename, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "add_drive");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_windows_systemroot (guestfs_h *g,
                                        const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_windows_systemroot", 30);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_windows_systemroot", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_windows_systemroot");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_windows_systemroot (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_windows_systemroot");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_windows_systemroot", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_backend (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_backend", 11);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_backend");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_backend (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_backend");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_backend", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_windows_current_control_set (guestfs_h *g,
                                                 const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_windows_current_control_set", 39);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_windows_current_control_set", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_windows_current_control_set");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_windows_current_control_set (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_windows_current_control_set");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_windows_current_control_set", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_inspect_get_drive_mappings (guestfs_h *g,
                                    const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_drive_mappings", 26);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_drive_mappings", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_drive_mappings");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_drive_mappings (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_drive_mappings");
      fputs ("[", trace_buffer.fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_buffer.fp);
        fputs ("\"", trace_buffer.fp);
        fputs (r[i], trace_buffer.fp);
        fputs ("\"", trace_buffer.fp);
      }
      fputs ("]", trace_buffer.fp);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_drive_mappings", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_pgroup (guestfs_h *g,
                    int pgroup)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_pgroup");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_pgroup", 10);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_pgroup");
    fputs (pgroup ? " true" : " false", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_pgroup (g, pgroup);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_pgroup");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_pgroup", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_write_append (guestfs_h *g,
                      const char *path,
                      const char *content,
                      size_t content_size)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "write_append", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_append", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_append", "content");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "write_append");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fputc (' ', trace_buffer.fp);
    guestfs___print_BufferIn (trace_buffer.fp, content, content_size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__write_append (g, path, content, content_size);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "write_append");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_libvirt_supported_credentials (guestfs_h *g,
                                           char *const *creds)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_libvirt_supported_credentials", 33);
  if (creds == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_libvirt_supported_credentials", "creds");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_libvirt_supported_credentials");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; creds[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (creds[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_libvirt_supported_credentials (g, creds);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_libvirt_supported_credentials");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_libvirt_supported_credentials", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_libvirt_requested_credential (guestfs_h *g,
                                          int index,
                                          const char *cred,
                                          size_t cred_size)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_libvirt_requested_credential", 32);
  if (cred == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_libvirt_requested_credential", "cred");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_libvirt_requested_credential");
    fprintf (trace_buffer.fp, " %d", index);
    fputc (' ', trace_buffer.fp);
    guestfs___print_BufferIn (trace_buffer.fp, cred, cred_size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_libvirt_requested_credential (g, index, cred, cred_size);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_libvirt_requested_credential");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_libvirt_requested_credential", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_parse_environment (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "parse_environment", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "parse_environment");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__parse_environment (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "parse_environment");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "parse_environment", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_add_drive_scratch_argv (guestfs_h *g,
                                int64_t size,
                                const struct guestfs_add_drive_scratch_argv *optargs)
{
  struct guestfs_add_drive_scratch_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive_scratch", 17);
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK) &&
      optargs->name == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_scratch", "name");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_scratch", "label");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "add_drive_scratch", "add_drive_scratch");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "add_drive_scratch");
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "name", optargs->name);
    }
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "label", optargs->label);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__add_drive_scratch (g, size, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "add_drive_scratch");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_scratch", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *
guestfs_pvs_full (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_pvs_full_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_lvm_pv_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvs_full", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvs_full");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pvs_full") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_PVS_FULL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "pvs_full", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_pvs_full_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PVS_FULL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvs_full", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pvs_full",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_lvm_pv_list));
  convert_guestfs_int_lvm_pv_list_protobuf_to_xdr (ret->physvols, (guestfs_int_lvm_pv_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvs_full");
    fprintf (trace_buffer.fp, "<struct guestfs_lvm_pv_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_pvs_full_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkdir (guestfs_h *g,
               const char *path)
{
  guestfs_protobuf_mkdir_args args;
  guestfs_protobuf_mkdir_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkdir", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdir", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkdir");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mkdir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mkdir_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mkdir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKDIR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdir", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mkdir",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkdir");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_chown (guestfs_h *g,
               int owner,
               int group,
               const char *path)
{
  guestfs_protobuf_chown_args args;
  guestfs_protobuf_chown_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "chown", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "chown", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "chown");
    fprintf (trace_buffer.fp, " %d", owner);
    fprintf (trace_buffer.fp, " %d", group);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "chown") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHOWN,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_chown_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "chown", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CHOWN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "chown", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "chown",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "chown");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_umount_all (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "umount_all", 10);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "umount_all");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "umount_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_UMOUNT_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "umount_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_UMOUNT_ALL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "umount_all", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "umount_all",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "umount_all");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_command (guestfs_h *g,
                 char *const *arguments)
{
  guestfs_protobuf_command_args args;
  guestfs_protobuf_command_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_command_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "command", 7);
  if (arguments == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "command", "arguments");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "command");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; arguments[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (arguments[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "command") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  args.arguments = (char **) arguments;
  for (args.n_arguments = 0; arguments[args.n_arguments]; args.n_arguments++) ;
  serial = guestfs___send (g, GUESTFS_PROC_COMMAND,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_command_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "command", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_command_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_COMMAND, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "command", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "command",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->output); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "command");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_command_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_tune2fs_ll (guestfs_h *g,
                    const char *device)
{
  guestfs_protobuf_tune2fs_ll_args args;
  guestfs_protobuf_tune2fs_ll_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_tune2fs_ll_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tune2fs_ll", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tune2fs_ll", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tune2fs_ll");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "tune2fs_ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_ll", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_TUNE2FS_LL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_tune2fs_ll_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_ll", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "tune2fs_ll", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_tune2fs_ll_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_ll", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TUNE2FS_LL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_ll", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_ll", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tune2fs_ll", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "tune2fs_ll",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_superblock));
  int i;
  for (i = 0; i < ret->n_superblock - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->superblock[i]);
  }
  ret_v[ret->n_superblock - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tune2fs_ll");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_tune2fs_ll_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_getss (guestfs_h *g,
                        const char *device)
{
  guestfs_protobuf_blockdev_getss_args args;
  guestfs_protobuf_blockdev_getss_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blockdev_getss_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getss", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getss", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_getss");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_getss") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_getss_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blockdev_getss", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blockdev_getss_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_GETSS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getss", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_getss",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->sectorsize;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_getss");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_blockdev_getss_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_blockdev_getsize64 (guestfs_h *g,
                            const char *device)
{
  guestfs_protobuf_blockdev_getsize64_args args;
  guestfs_protobuf_blockdev_getsize64_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blockdev_getsize64_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getsize64", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getsize64", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_getsize64");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_getsize64") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSIZE64,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_getsize64_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blockdev_getsize64", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blockdev_getsize64_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_GETSIZE64, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getsize64", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_getsize64",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->sizeinbytes;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_getsize64");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_blockdev_getsize64_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_rereadpt (guestfs_h *g,
                           const char *device)
{
  guestfs_protobuf_blockdev_rereadpt_args args;
  guestfs_protobuf_blockdev_rereadpt_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_rereadpt", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_rereadpt", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_rereadpt");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_rereadpt") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_REREADPT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_rereadpt_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "blockdev_rereadpt", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_REREADPT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_rereadpt", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_rereadpt",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_rereadpt");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_debug (guestfs_h *g,
               const char *subcmd,
               char *const *extraargs)
{
  guestfs_protobuf_debug_args args;
  guestfs_protobuf_debug_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_debug_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "debug", 5);
  if (subcmd == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug", "subcmd");
    return NULL;
  }
  if (extraargs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug", "extraargs");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "debug");
    fprintf (trace_buffer.fp, " \"%s\"", subcmd);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; extraargs[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (extraargs[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "debug") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  args.subcmd = (char *) subcmd;
  args.extraargs = (char **) extraargs;
  for (args.n_extraargs = 0; extraargs[args.n_extraargs]; args.n_extraargs++) ;
  serial = guestfs___send (g, GUESTFS_PROC_DEBUG,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_debug_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "debug", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_debug_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DEBUG, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "debug", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "debug",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->result); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "debug");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_debug_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_e2uuid (guestfs_h *g,
                    const char *device,
                    const char *uuid)
{
  guestfs_protobuf_set_e2uuid_args args;
  guestfs_protobuf_set_e2uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_e2uuid", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2uuid", "device");
    return -1;
  }
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_e2uuid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "set_e2uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_set_e2uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "set_e2uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SET_E2UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_e2uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "set_e2uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_e2uuid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_grub_install (guestfs_h *g,
                      const char *root,
                      const char *device)
{
  guestfs_protobuf_grub_install_args args;
  guestfs_protobuf_grub_install_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "grub_install", 12);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grub_install", "root");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grub_install", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "grub_install");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "grub_install") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  args.root = (char *) root;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GRUB_INSTALL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_grub_install_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "grub_install", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GRUB_INSTALL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "grub_install", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "grub_install",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "grub_install");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_drop_caches (guestfs_h *g,
                     int whattodrop)
{
  guestfs_protobuf_drop_caches_args args;
  guestfs_protobuf_drop_caches_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "drop_caches", 11);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "drop_caches");
    fprintf (trace_buffer.fp, " %d", whattodrop);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "drop_caches") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  args.whattodrop = whattodrop;
  serial = guestfs___send (g, GUESTFS_PROC_DROP_CACHES,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_drop_caches_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "drop_caches", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DROP_CACHES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "drop_caches", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "drop_caches",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "drop_caches");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_pvresize (guestfs_h *g,
                  const char *device)
{
  guestfs_protobuf_pvresize_args args;
  guestfs_protobuf_pvresize_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvresize", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvresize", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvresize");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pvresize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVRESIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_pvresize_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "pvresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PVRESIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvresize", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pvresize",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvresize");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_sfdisk_disk_geometry (guestfs_h *g,
                              const char *device)
{
  guestfs_protobuf_sfdisk_disk_geometry_args args;
  guestfs_protobuf_sfdisk_disk_geometry_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_sfdisk_disk_geometry_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sfdisk_disk_geometry", 20);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_disk_geometry", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sfdisk_disk_geometry");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sfdisk_disk_geometry") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_DISK_GEOMETRY,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_sfdisk_disk_geometry_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "sfdisk_disk_geometry", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_sfdisk_disk_geometry_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SFDISK_DISK_GEOMETRY, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_disk_geometry", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sfdisk_disk_geometry",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->partitions); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sfdisk_disk_geometry");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_sfdisk_disk_geometry_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_resize2fs (guestfs_h *g,
                   const char *device)
{
  guestfs_protobuf_resize2fs_args args;
  guestfs_protobuf_resize2fs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "resize2fs", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "resize2fs", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "resize2fs");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "resize2fs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_resize2fs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "resize2fs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RESIZE2FS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "resize2fs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "resize2fs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "resize2fs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_e2fsck_ff (guestfs_h *g,
                   const char *device)
{
  guestfs_protobuf_e2fsck_ff_args args;
  guestfs_protobuf_e2fsck_ff_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "e2fsck_ff", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "e2fsck_ff", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "e2fsck_ff");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "e2fsck_ff") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_ff", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_E2FSCK_FF,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_e2fsck_ff_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_ff", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "e2fsck_ff", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_ff", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_E2FSCK_FF, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_ff", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_ff", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "e2fsck_ff", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "e2fsck_ff",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "e2fsck_ff");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_sh (guestfs_h *g,
            const char *command)
{
  guestfs_protobuf_sh_args args;
  guestfs_protobuf_sh_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_sh_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sh", 2);
  if (command == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sh", "command");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sh");
    fprintf (trace_buffer.fp, " \"%s\"", command);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sh") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  args.command = (char *) command;
  serial = guestfs___send (g, GUESTFS_PROC_SH,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_sh_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "sh", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_sh_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SH, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sh", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sh",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->output); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sh");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_sh_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_glob_expand (guestfs_h *g,
                     const char *pattern)
{
  guestfs_protobuf_glob_expand_args args;
  guestfs_protobuf_glob_expand_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_glob_expand_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "glob_expand", 11);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "glob_expand", "pattern");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "glob_expand");
    fprintf (trace_buffer.fp, " \"%s\"", pattern);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "glob_expand") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  args.pattern = (char *) pattern;
  serial = guestfs___send (g, GUESTFS_PROC_GLOB_EXPAND,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_glob_expand_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "glob_expand", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_glob_expand_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GLOB_EXPAND, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "glob_expand", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "glob_expand",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_paths));
  int i;
  for (i = 0; i < ret->n_paths - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->paths[i]);
  }
  ret_v[ret->n_paths - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "glob_expand");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_glob_expand_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_wc_ww (guestfs_h *g,
               const char *path)
{
  guestfs_protobuf_wc_ww_args args;
  guestfs_protobuf_wc_ww_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_wc_ww_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wc_ww", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wc_ww", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "wc_ww");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "wc_ww") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ww", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_WW,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_wc_ww_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ww", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "wc_ww", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_wc_ww_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ww", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_WC_WW, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ww", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ww", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wc_ww", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "wc_ww",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->words;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "wc_ww");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_wc_ww_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkfifo (guestfs_h *g,
                int mode,
                const char *path)
{
  guestfs_protobuf_mkfifo_args args;
  guestfs_protobuf_mkfifo_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkfifo", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfifo", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkfifo");
    fprintf (trace_buffer.fp, " %d", mode);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mkfifo") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  args.mode = mode;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKFIFO,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mkfifo_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mkfifo", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKFIFO, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfifo", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mkfifo",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkfifo");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_dirent_list *
guestfs_readdir (guestfs_h *g,
                 const char *dir)
{
  guestfs_protobuf_readdir_args args;
  guestfs_protobuf_readdir_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_readdir_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_dirent_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "readdir", 7);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readdir", "dir");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "readdir");
    fprintf (trace_buffer.fp, " \"%s\"", dir);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "readdir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_READDIR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_readdir_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "readdir", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_readdir_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_READDIR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "readdir", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "readdir",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_dirent_list));
  convert_guestfs_int_dirent_list_protobuf_to_xdr (ret->entries, (guestfs_int_dirent_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "readdir");
    fprintf (trace_buffer.fp, "<struct guestfs_dirent_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_readdir_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lsetxattr (guestfs_h *g,
                   const char *xattr,
                   const char *val,
                   int vallen,
                   const char *path)
{
  guestfs_protobuf_lsetxattr_args args;
  guestfs_protobuf_lsetxattr_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lsetxattr", 9);
  if (xattr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lsetxattr", "xattr");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lsetxattr", "val");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lsetxattr", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lsetxattr");
    fprintf (trace_buffer.fp, " \"%s\"", xattr);
    fprintf (trace_buffer.fp, " \"%s\"", val);
    fprintf (trace_buffer.fp, " %d", vallen);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lsetxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  args.xattr = (char *) xattr;
  args.val = (char *) val;
  args.vallen = vallen;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSETXATTR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lsetxattr_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "lsetxattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LSETXATTR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lsetxattr", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lsetxattr",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lsetxattr");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_egrep (guestfs_h *g,
               const char *regex,
               const char *path)
{
  guestfs_protobuf_egrep_args args;
  guestfs_protobuf_egrep_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_egrep_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "egrep", 5);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrep", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "egrep");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "egrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EGREP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_egrep_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "egrep", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_egrep_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_EGREP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "egrep", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "egrep",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_lines));
  int i;
  for (i = 0; i < ret->n_lines - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->lines[i]);
  }
  ret_v[ret->n_lines - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "egrep");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_egrep_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_zgrep (guestfs_h *g,
               const char *regex,
               const char *path)
{
  guestfs_protobuf_zgrep_args args;
  guestfs_protobuf_zgrep_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_zgrep_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zgrep", 5);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrep", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zgrep");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "zgrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZGREP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_zgrep_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "zgrep", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_zgrep_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ZGREP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zgrep", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "zgrep",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_lines));
  int i;
  for (i = 0; i < ret->n_lines - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->lines[i]);
  }
  ret_v[ret->n_lines - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "zgrep");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_zgrep_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_readlink (guestfs_h *g,
                  const char *path)
{
  guestfs_protobuf_readlink_args args;
  guestfs_protobuf_readlink_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_readlink_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "readlink", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readlink", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "readlink");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "readlink") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READLINK,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_readlink_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "readlink", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_readlink_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_READLINK, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "readlink", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "readlink",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->link); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "readlink");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_readlink_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapon_label (guestfs_h *g,
                      const char *label)
{
  guestfs_protobuf_swapon_label_args args;
  guestfs_protobuf_swapon_label_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapon_label", 12);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_label", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapon_label");
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "swapon_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_LABEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_swapon_label_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "swapon_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SWAPON_LABEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_label", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "swapon_label",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapon_label");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mke2journal_ll (guestfs_h *g,
                        int blocksize,
                        const char *label,
                        const char *device)
{
  guestfs_protobuf_mke2journal_ll_args args;
  guestfs_protobuf_mke2journal_ll_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2journal_ll", 14);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal_ll", "label");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal_ll", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mke2journal_ll");
    fprintf (trace_buffer.fp, " %d", blocksize);
    fprintf (trace_buffer.fp, " \"%s\"", label);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mke2journal_ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_ll", "-1");
    return -1;
  }

  args.blocksize = blocksize;
  args.label = (char *) label;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL_LL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mke2journal_ll_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_ll", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mke2journal_ll", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_ll", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKE2JOURNAL_LL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_ll", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_ll", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2journal_ll", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mke2journal_ll",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mke2journal_ll");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_modprobe (guestfs_h *g,
                  const char *modulename)
{
  guestfs_protobuf_modprobe_args args;
  guestfs_protobuf_modprobe_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "modprobe", 8);
  if (modulename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "modprobe", "modulename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "modprobe");
    fprintf (trace_buffer.fp, " \"%s\"", modulename);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "modprobe") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  args.modulename = (char *) modulename;
  serial = guestfs___send (g, GUESTFS_PROC_MODPROBE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_modprobe_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "modprobe", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MODPROBE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "modprobe", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "modprobe",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "modprobe");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_set_bootable (guestfs_h *g,
                           const char *device,
                           int partnum,
                           int bootable)
{
  guestfs_protobuf_part_set_bootable_args args;
  guestfs_protobuf_part_set_bootable_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_set_bootable", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_bootable", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_set_bootable");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    fputs (bootable ? " true" : " false", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_set_bootable") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  args.bootable = bootable;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_BOOTABLE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_set_bootable_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "part_set_bootable", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_SET_BOOTABLE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_bootable", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_set_bootable",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_set_bootable");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_partition_list *
guestfs_part_list (guestfs_h *g,
                   const char *device)
{
  guestfs_protobuf_part_list_args args;
  guestfs_protobuf_part_list_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_part_list_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_partition_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_list", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_list", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_list");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_list") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PART_LIST,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_list_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "part_list", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_part_list_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_LIST, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_list", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_list",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_partition_list));
  convert_guestfs_int_partition_list_protobuf_to_xdr (ret->partitions, (guestfs_int_partition_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_list");
    fprintf (trace_buffer.fp, "<struct guestfs_partition_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_part_list_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_vgpvuuids (guestfs_h *g,
                   const char *vgname)
{
  guestfs_protobuf_vgpvuuids_args args;
  guestfs_protobuf_vgpvuuids_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_vgpvuuids_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgpvuuids", 9);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgpvuuids", "vgname");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgpvuuids");
    fprintf (trace_buffer.fp, " \"%s\"", vgname);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "vgpvuuids") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGPVUUIDS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_vgpvuuids_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "vgpvuuids", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_vgpvuuids_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_VGPVUUIDS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgpvuuids", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "vgpvuuids",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_uuids));
  int i;
  for (i = 0; i < ret->n_uuids - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->uuids[i]);
  }
  ret_v[ret->n_uuids - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgpvuuids");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_vgpvuuids_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_txz_out (guestfs_h *g,
                 const char *directory,
                 const char *tarball)
{
  guestfs_protobuf_txz_out_args args;
  guestfs_protobuf_txz_out_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "txz_out", 7);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "txz_out", "directory");
    return -1;
  }
  if (tarball == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "txz_out", "tarball");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "txz_out");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    fprintf (trace_buffer.fp, " \"%s\"", tarball);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "txz_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TXZ_OUT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_txz_out_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "txz_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TXZ_OUT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "txz_out", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "txz_out",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  if (guestfs___recv_file (g, tarball) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "txz_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_luks_kill_slot (guestfs_h *g,
                        const char *device,
                        const char *key,
                        int keyslot)
{
  guestfs_protobuf_luks_kill_slot_args args;
  guestfs_protobuf_luks_kill_slot_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_kill_slot", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_kill_slot", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_kill_slot", "key");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "luks_kill_slot");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " %d", keyslot);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "luks_kill_slot") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.keyslot = keyslot;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_KILL_SLOT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_luks_kill_slot_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "luks_kill_slot", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LUKS_KILL_SLOT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_kill_slot", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "luks_kill_slot",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "luks_kill_slot");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_lv (guestfs_h *g,
               const char *device)
{
  guestfs_protobuf_is_lv_args args;
  guestfs_protobuf_is_lv_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_lv_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_lv", 5);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_lv", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_lv");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_lv") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_IS_LV,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_is_lv_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_lv", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_lv_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_LV, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_lv", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_lv",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->lvflag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_lv");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_lv_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_chardev_opts_argv (guestfs_h *g,
                              const char *path,
                              const struct guestfs_is_chardev_opts_argv *optargs)
{
  struct guestfs_is_chardev_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_is_chardev_args args;
  guestfs_protobuf_is_chardev_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_chardev_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_chardev", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_chardev_opts", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "is_chardev_opts", "is_chardev_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_chardev");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "followsymlinks", optargs->followsymlinks ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_chardev") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK) {
    args.followsymlinks = optargs->followsymlinks;
  } else {
    args.followsymlinks = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_IS_CHARDEV,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_is_chardev_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_chardev", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_chardev_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_CHARDEV, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_chardev", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_chardev",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->flag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_chardev");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_chardev_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_socket_opts_argv (guestfs_h *g,
                             const char *path,
                             const struct guestfs_is_socket_opts_argv *optargs)
{
  struct guestfs_is_socket_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_is_socket_args args;
  guestfs_protobuf_is_socket_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_socket_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_socket", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_socket_opts", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "is_socket_opts", "is_socket_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_socket");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "followsymlinks", optargs->followsymlinks ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_socket") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK) {
    args.followsymlinks = optargs->followsymlinks;
  } else {
    args.followsymlinks = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_IS_SOCKET,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_is_socket_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_socket", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_socket_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_SOCKET, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_socket", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_socket",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->flag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_socket");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_socket_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_part_to_dev (guestfs_h *g,
                     const char *partition)
{
  guestfs_protobuf_part_to_dev_args args;
  guestfs_protobuf_part_to_dev_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_part_to_dev_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_to_dev", 11);
  if (partition == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_to_dev", "partition");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_to_dev");
    fprintf (trace_buffer.fp, " \"%s\"", partition);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_to_dev") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  args.partition = (char *) partition;
  serial = guestfs___send (g, GUESTFS_PROC_PART_TO_DEV,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_to_dev_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "part_to_dev", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_part_to_dev_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_TO_DEV, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_to_dev", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_to_dev",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->device); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_to_dev");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_part_to_dev_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_upload_offset (guestfs_h *g,
                       const char *filename,
                       const char *remotefilename,
                       int64_t offset)
{
  guestfs_protobuf_upload_offset_args args;
  guestfs_protobuf_upload_offset_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "upload_offset", 13);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload_offset", "filename");
    return -1;
  }
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload_offset", "remotefilename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "upload_offset");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", remotefilename);
    fprintf (trace_buffer.fp, " %" PRIi64, offset);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (stat (filename, &progress_stat) == 0 &&
      (progress_stat.st_mode & S_IFREG))
    progress_hint += progress_stat.st_size;

  if (guestfs___check_appliance_up (g, "upload_offset") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  args.remotefilename = (char *) remotefilename;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_UPLOAD_OFFSET,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_upload_offset_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "upload_offset");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "upload_offset", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_UPLOAD_OFFSET, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "upload_offset", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "upload_offset",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "upload_offset");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_pwrite_device (guestfs_h *g,
                       const char *device,
                       const char *content,
                       size_t content_size,
                       int64_t offset)
{
  guestfs_protobuf_pwrite_device_args args;
  guestfs_protobuf_pwrite_device_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_pwrite_device_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pwrite_device", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pwrite_device", "device");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pwrite_device", "content");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pwrite_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fputc (' ', trace_buffer.fp);
    guestfs___print_BufferIn (trace_buffer.fp, content, content_size);
    fprintf (trace_buffer.fp, " %" PRIi64, offset);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pwrite_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    error (g, "%s: size of input buffer too large", "pwrite_device");
    return -1;
  }
  args.content.data = (char *) content;
  args.content.len = content_size;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PWRITE_DEVICE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_pwrite_device_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "pwrite_device", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_pwrite_device_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PWRITE_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pwrite_device", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pwrite_device",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->nbytes;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pwrite_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_pwrite_device_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_copy_device_to_file_argv (guestfs_h *g,
                                  const char *src,
                                  const char *dest,
                                  const struct guestfs_copy_device_to_file_argv *optargs)
{
  struct guestfs_copy_device_to_file_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_copy_device_to_file_args args;
  guestfs_protobuf_copy_device_to_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "copy_device_to_file", 19);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_device_to_file", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_device_to_file", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_device_to_file", "copy_device_to_file");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "copy_device_to_file");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "sparse", optargs->sparse ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "copy_device_to_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK) {
    args.srcoffset = optargs->srcoffset;
  } else {
    args.srcoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK) {
    args.destoffset = optargs->destoffset;
  } else {
    args.destoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK) {
    args.size = optargs->size;
  } else {
    args.size = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK) {
    args.sparse = optargs->sparse;
  } else {
    args.sparse = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_COPY_DEVICE_TO_FILE,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_copy_device_to_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "copy_device_to_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_COPY_DEVICE_TO_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_device_to_file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "copy_device_to_file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "copy_device_to_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_e2attrs (guestfs_h *g,
                     const char *file)
{
  guestfs_protobuf_get_e2attrs_args args;
  guestfs_protobuf_get_e2attrs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_get_e2attrs_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_e2attrs", 11);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_e2attrs", "file");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_e2attrs");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "get_e2attrs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2attrs", "NULL");
    return NULL;
  }

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2ATTRS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_get_e2attrs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2attrs", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "get_e2attrs", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_get_e2attrs_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2attrs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GET_E2ATTRS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2attrs", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2attrs", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_e2attrs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "get_e2attrs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->attrs); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "get_e2attrs");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_get_e2attrs_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_get_e2generation (guestfs_h *g,
                          const char *file)
{
  guestfs_protobuf_get_e2generation_args args;
  guestfs_protobuf_get_e2generation_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_get_e2generation_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_e2generation", 16);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_e2generation", "file");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_e2generation");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "get_e2generation") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2generation", "-1");
    return -1;
  }

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2GENERATION,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_get_e2generation_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2generation", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "get_e2generation", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_get_e2generation_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2generation", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GET_E2GENERATION, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2generation", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2generation", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_e2generation", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "get_e2generation",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->generation;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "get_e2generation");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_get_e2generation_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_set_seeding (guestfs_h *g,
                           const char *device,
                           int seeding)
{
  guestfs_protobuf_btrfs_set_seeding_args args;
  guestfs_protobuf_btrfs_set_seeding_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_set_seeding", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_set_seeding", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_set_seeding");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fputs (seeding ? " true" : " false", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_set_seeding") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_set_seeding", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.seeding = seeding;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_SET_SEEDING,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_set_seeding_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_set_seeding", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_set_seeding", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_set_seeding", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_SET_SEEDING, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_set_seeding", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_set_seeding", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_set_seeding", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_set_seeding",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_set_seeding");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_utsname *
guestfs_utsname (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_utsname_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_utsname *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "utsname", 7);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "utsname");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "utsname") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utsname", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_UTSNAME, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utsname", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "utsname", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_utsname_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utsname", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_UTSNAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utsname", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utsname", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "utsname", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "utsname",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_utsname))
;  convert_guestfs_int_utsname_protobuf_to_xdr (ret->uts, (guestfs_int_utsname *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "utsname");
    fprintf (trace_buffer.fp, "<struct guestfs_utsname *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_utsname_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rsync_in_argv (guestfs_h *g,
                       const char *remote,
                       const char *dest,
                       const struct guestfs_rsync_in_argv *optargs)
{
  struct guestfs_rsync_in_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_rsync_in_args args;
  guestfs_protobuf_rsync_in_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rsync_in", 8);
  if (remote == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rsync_in", "remote");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rsync_in", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "rsync_in", "rsync_in");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rsync_in");
    fprintf (trace_buffer.fp, " \"%s\"", remote);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_RSYNC_IN_ARCHIVE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "archive", optargs->archive ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_RSYNC_IN_DELETEDEST_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "deletedest", optargs->deletedest ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rsync_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_in", "-1");
    return -1;
  }

  args.remote = (char *) remote;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_RSYNC_IN_ARCHIVE_BITMASK) {
    args.archive = optargs->archive;
  } else {
    args.archive = 0;
  }
  if (optargs->bitmask & GUESTFS_RSYNC_IN_DELETEDEST_BITMASK) {
    args.deletedest = optargs->deletedest;
  } else {
    args.deletedest = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_RSYNC_IN,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_rsync_in_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_in", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rsync_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_in", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RSYNC_IN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_in", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_in", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rsync_in", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rsync_in",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rsync_in");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_hivex_node_get_value (guestfs_h *g,
                              int64_t nodeh,
                              const char *key)
{
  guestfs_protobuf_hivex_node_get_value_args args;
  guestfs_protobuf_hivex_node_get_value_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_hivex_node_get_value_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_get_value", 20);
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hivex_node_get_value", "key");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_get_value");
    fprintf (trace_buffer.fp, " %" PRIi64, nodeh);
    fprintf (trace_buffer.fp, " \"%s\"", key);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_get_value") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_value", "-1");
    return -1;
  }

  args.nodeh = nodeh;
  args.key = (char *) key;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_GET_VALUE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_hivex_node_get_value_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_value", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "hivex_node_get_value", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_hivex_node_get_value_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_value", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_NODE_GET_VALUE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_value", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_value", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_get_value", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_node_get_value",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->valueh;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_get_value");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_hivex_node_get_value_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_hivex_node_add_child (guestfs_h *g,
                              int64_t parent,
                              const char *name)
{
  guestfs_protobuf_hivex_node_add_child_args args;
  guestfs_protobuf_hivex_node_add_child_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_hivex_node_add_child_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_add_child", 20);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hivex_node_add_child", "name");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_add_child");
    fprintf (trace_buffer.fp, " %" PRIi64, parent);
    fprintf (trace_buffer.fp, " \"%s\"", name);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_add_child") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_add_child", "-1");
    return -1;
  }

  args.parent = parent;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_ADD_CHILD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_hivex_node_add_child_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_add_child", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "hivex_node_add_child", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_hivex_node_add_child_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_add_child", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_NODE_ADD_CHILD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_add_child", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_add_child", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_add_child", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_node_add_child",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->nodeh;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_add_child");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_hivex_node_add_child_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_ldmtool_scan_devices (guestfs_h *g,
                              char *const *devices)
{
  guestfs_protobuf_ldmtool_scan_devices_args args;
  guestfs_protobuf_ldmtool_scan_devices_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_ldmtool_scan_devices_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_scan_devices", 20);
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_scan_devices", "devices");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_scan_devices");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (devices[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_scan_devices") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan_devices", "NULL");
    return NULL;
  }

  args.devices = (char **) devices;
  for (args.n_devices = 0; devices[args.n_devices]; args.n_devices++) ;
  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_SCAN_DEVICES,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ldmtool_scan_devices_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan_devices", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "ldmtool_scan_devices", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_ldmtool_scan_devices_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan_devices", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LDMTOOL_SCAN_DEVICES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan_devices", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan_devices", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_scan_devices", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ldmtool_scan_devices",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_guids));
  int i;
  for (i = 0; i < ret->n_guids - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->guids[i]);
  }
  ret_v[ret->n_guids - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_scan_devices");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_ldmtool_scan_devices_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_journal_open (guestfs_h *g,
                      const char *directory)
{
  guestfs_protobuf_journal_open_args args;
  guestfs_protobuf_journal_open_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "journal_open", 12);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "journal_open", "directory");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "journal_open");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "journal_open") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_open", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_JOURNAL_OPEN,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_journal_open_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_open", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "journal_open", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_open", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_JOURNAL_OPEN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_open", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_open", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "journal_open", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "journal_open",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "journal_open");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_aug_label (guestfs_h *g,
                   const char *augpath)
{
  guestfs_protobuf_aug_label_args args;
  guestfs_protobuf_aug_label_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_aug_label_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_label", 9);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_label", "augpath");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_label");
    fprintf (trace_buffer.fp, " \"%s\"", augpath);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_label", "NULL");
    return NULL;
  }

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_LABEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_label_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_label", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "aug_label", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_aug_label_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_label", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_LABEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_label", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_label", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_label", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_label",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->label); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_label");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_aug_label_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blkdiscardzeroes (guestfs_h *g,
                          const char *device)
{
  guestfs_protobuf_blkdiscardzeroes_args args;
  guestfs_protobuf_blkdiscardzeroes_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blkdiscardzeroes_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blkdiscardzeroes", 16);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blkdiscardzeroes", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blkdiscardzeroes");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blkdiscardzeroes") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscardzeroes", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLKDISCARDZEROES,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blkdiscardzeroes_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscardzeroes", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blkdiscardzeroes", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blkdiscardzeroes_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscardzeroes", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLKDISCARDZEROES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscardzeroes", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscardzeroes", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blkdiscardzeroes", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blkdiscardzeroes",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->zeroes;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blkdiscardzeroes");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_blkdiscardzeroes_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_statns *
guestfs_statns (guestfs_h *g,
                const char *path)
{
  guestfs_protobuf_statns_args args;
  guestfs_protobuf_statns_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_statns_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_statns *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "statns", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "statns", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "statns");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "statns") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statns", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STATNS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_statns_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statns", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "statns", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_statns_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statns", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_STATNS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statns", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statns", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "statns", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "statns",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_statns))
;  convert_guestfs_int_statns_protobuf_to_xdr (ret->statbuf, (guestfs_int_statns *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "statns");
    fprintf (trace_buffer.fp, "<struct guestfs_statns *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_statns_ret__free_unpacked (ret, NULL);
  return ret_v;
}

