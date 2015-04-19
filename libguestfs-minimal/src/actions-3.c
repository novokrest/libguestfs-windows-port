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
guestfs_internal_test_only_optargs_argv (guestfs_h *g,
                                         const struct guestfs_internal_test_only_optargs_argv *optargs)
{
  struct guestfs_internal_test_only_optargs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_only_optargs", 26);
  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "internal_test_only_optargs", "internal_test_only_optargs");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_only_optargs");
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "test", optargs->test);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_only_optargs (g, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_only_optargs");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_only_optargs", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_internal_test_rconststringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rconststringerr", 29);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rconststringerr");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rconststringerr (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rconststringerr");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rconststringerr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_launch (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "launch");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "launch", 6);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "launch");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__launch (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "launch");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "launch", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_qemu (guestfs_h *g,
                  const char *hv)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_qemu");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_qemu", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_qemu");
    if (hv)
      fprintf (trace_buffer.fp, " \"%s\"", hv);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_qemu (g, hv);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_qemu");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_qemu", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_hv (guestfs_h *g,
                const char *hv)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_hv");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_hv", 6);
  if (hv == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_hv", "hv");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_hv");
    fprintf (trace_buffer.fp, " \"%s\"", hv);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_hv (g, hv);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_hv");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_hv", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_version *
guestfs_version (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_version *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "version", 7);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "version");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__version (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "version");
      fprintf (trace_buffer.fp, "<struct guestfs_version *>");
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "version", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_recovery_proc (guestfs_h *g,
                           int recoveryproc)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_recovery_proc");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_recovery_proc", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_recovery_proc");
    fputs (recoveryproc ? " true" : " false", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_recovery_proc (g, recoveryproc);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_recovery_proc");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_recovery_proc", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_recovery_proc (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_recovery_proc", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_recovery_proc");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_recovery_proc (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_recovery_proc");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_recovery_proc", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_type (guestfs_h *g,
                          const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_type", 16);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_type", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_type");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_type (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_type");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_type", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_filesystems (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_filesystems", 16);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_filesystems");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__list_filesystems (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "list_filesystems");
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
                       "list_filesystems", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_inspect_is_live (guestfs_h *g,
                         const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_is_live", 15);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_is_live", "root");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_is_live");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_is_live (g, root);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_is_live");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_is_live", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_local_argv (guestfs_h *g,
                          const char *localmountpoint,
                          const struct guestfs_mount_local_argv *optargs)
{
  struct guestfs_mount_local_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_local", 11);
  if (localmountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_local", "localmountpoint");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK) &&
      optargs->options == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mount_local", "options");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mount_local", "mount_local");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount_local");
    fprintf (trace_buffer.fp, " \"%s\"", localmountpoint);
    if (optargs->bitmask & GUESTFS_MOUNT_LOCAL_READONLY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "readonly", optargs->readonly ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "options", optargs->options);
    }
    if (optargs->bitmask & GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "cachetimeout", optargs->cachetimeout);
    }
    if (optargs->bitmask & GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "debugcalls", optargs->debugcalls ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__mount_local (g, localmountpoint, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "mount_local");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_local", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *
guestfs_lxattrlist (guestfs_h *g,
                    const char *path,
                    char *const *names)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_xattr_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lxattrlist", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lxattrlist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lxattrlist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lxattrlist");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; names[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (names[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__lxattrlist (g, path, names);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "lxattrlist");
      fprintf (trace_buffer.fp, "<struct guestfs_xattr_list *>");
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lxattrlist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_ls (guestfs_h *g,
            const char *directory)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ls", 2);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ls", "directory");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ls");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__ls (g, directory);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "ls");
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
                       "ls", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_hivex_value_utf8 (guestfs_h *g,
                          int64_t valueh)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_value_utf8", 16);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_value_utf8");
    fprintf (trace_buffer.fp, " %" PRIi64, valueh);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__hivex_value_utf8 (g, valueh);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "hivex_value_utf8");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_utf8", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_remove_drive (guestfs_h *g,
                      const char *label)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "remove_drive", 12);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "remove_drive", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "remove_drive");
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__remove_drive (g, label);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "remove_drive");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "remove_drive", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_tmpdir (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_tmpdir", 10);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_tmpdir");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_tmpdir (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_tmpdir");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_tmpdir", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_disk_create_argv (guestfs_h *g,
                          const char *filename,
                          const char *format,
                          int64_t size,
                          const struct guestfs_disk_create_argv *optargs)
{
  struct guestfs_disk_create_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "disk_create", 11);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "disk_create", "filename");
    return -1;
  }
  if (format == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "disk_create", "format");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK) &&
      optargs->backingfile == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "disk_create", "backingfile");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK) &&
      optargs->backingformat == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "disk_create", "backingformat");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK) &&
      optargs->preallocation == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "disk_create", "preallocation");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_DISK_CREATE_COMPAT_BITMASK) &&
      optargs->compat == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "disk_create", "compat");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "disk_create", "disk_create");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "disk_create");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", format);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    if (optargs->bitmask & GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "backingfile", optargs->backingfile);
    }
    if (optargs->bitmask & GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "backingformat", optargs->backingformat);
    }
    if (optargs->bitmask & GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "preallocation", optargs->preallocation);
    }
    if (optargs->bitmask & GUESTFS_DISK_CREATE_COMPAT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "compat", optargs->compat);
    }
    if (optargs->bitmask & GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "clustersize", optargs->clustersize);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__disk_create (g, filename, format, size, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "disk_create");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "disk_create", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_get_backend_settings (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_backend_settings", 20);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_backend_settings");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_backend_settings (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_backend_settings");
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
                       "get_backend_settings", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_backend_settings (guestfs_h *g,
                              char *const *settings)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_backend_settings");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_backend_settings", 20);
  if (settings == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_backend_settings", "settings");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_backend_settings");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; settings[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (settings[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_backend_settings (g, settings);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_backend_settings");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_backend_settings", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_backend_setting (guestfs_h *g,
                             const char *name)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_backend_setting", 19);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_backend_setting", "name");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_backend_setting");
    fprintf (trace_buffer.fp, " \"%s\"", name);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_backend_setting (g, name);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_backend_setting");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_backend_setting", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_devices (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_list_devices_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_devices", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_devices");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "list_devices") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LIST_DEVICES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "list_devices", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_list_devices_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LIST_DEVICES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_devices", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "list_devices",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_devices));
  int i;
  for (i = 0; i < ret->n_devices - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->devices[i]);
  }
  ret_v[ret->n_devices - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "list_devices");
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
  guestfs_protobuf_list_devices_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_vgs (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_vgs_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgs", 3);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgs");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "vgs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_VGS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "vgs", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_vgs_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_VGS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "vgs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_volgroups));
  int i;
  for (i = 0; i < ret->n_volgroups - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->volgroups[i]);
  }
  ret_v[ret->n_volgroups - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgs");
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
  guestfs_protobuf_vgs_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_close (guestfs_h *g)
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
                                    "aug_close", 9);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_close");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_AUG_CLOSE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_CLOSE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_close", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_close",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_close");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_int_bool *
guestfs_aug_defnode (guestfs_h *g,
                     const char *name,
                     const char *expr,
                     const char *val)
{
  guestfs_protobuf_aug_defnode_args args;
  guestfs_protobuf_aug_defnode_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_aug_defnode_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_int_bool *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_defnode", 11);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defnode", "name");
    return NULL;
  }
  if (expr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defnode", "expr");
    return NULL;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defnode", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_defnode");
    fprintf (trace_buffer.fp, " \"%s\"", name);
    fprintf (trace_buffer.fp, " \"%s\"", expr);
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_defnode") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  args.name = (char *) name;
  args.expr = (char *) expr;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_DEFNODE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_defnode_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "aug_defnode", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_aug_defnode_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_DEFNODE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_defnode", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_defnode",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_int_bool))
;  convert_guestfs_int_int_bool_protobuf_to_xdr (ret->nrnodescreated, (guestfs_int_int_bool *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_defnode");
    fprintf (trace_buffer.fp, "<struct guestfs_int_bool *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_aug_defnode_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_aug_get (guestfs_h *g,
                 const char *augpath)
{
  guestfs_protobuf_aug_get_args args;
  guestfs_protobuf_aug_get_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_aug_get_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_get", 7);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_get", "augpath");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_get");
    fprintf (trace_buffer.fp, " \"%s\"", augpath);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_get") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_GET,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_get_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "aug_get", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_aug_get_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_GET, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_get", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_get",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->val); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_get");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_aug_get_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_save (guestfs_h *g)
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
                                    "aug_save", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_save");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_save") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_AUG_SAVE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_save", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_SAVE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_save", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_save",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_save");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rm (guestfs_h *g,
            const char *path)
{
  guestfs_protobuf_rm_args args;
  guestfs_protobuf_rm_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rm", 2);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rm", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rm");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rm") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_rm_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rm", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rm", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rm",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rm");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rmdir (guestfs_h *g,
               const char *path)
{
  guestfs_protobuf_rmdir_args args;
  guestfs_protobuf_rmdir_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rmdir", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rmdir", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rmdir");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rmdir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RMDIR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_rmdir_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rmdir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RMDIR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rmdir", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rmdir",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rmdir");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_chmod (guestfs_h *g,
               int mode,
               const char *path)
{
  guestfs_protobuf_chmod_args args;
  guestfs_protobuf_chmod_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "chmod", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "chmod", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "chmod");
    fprintf (trace_buffer.fp, " %d", mode);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "chmod") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  args.mode = mode;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHMOD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_chmod_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "chmod", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CHMOD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "chmod", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "chmod",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "chmod");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_file_opts_argv (guestfs_h *g,
                           const char *path,
                           const struct guestfs_is_file_opts_argv *optargs)
{
  struct guestfs_is_file_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_is_file_args args;
  guestfs_protobuf_is_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_file_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_file", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_file_opts", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "is_file_opts", "is_file_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "followsymlinks", optargs->followsymlinks ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK) {
    args.followsymlinks = optargs->followsymlinks;
  } else {
    args.followsymlinks = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_IS_FILE,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_is_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_file", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_file_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->fileflag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_file_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_dir_opts_argv (guestfs_h *g,
                          const char *path,
                          const struct guestfs_is_dir_opts_argv *optargs)
{
  struct guestfs_is_dir_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_is_dir_args args;
  guestfs_protobuf_is_dir_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_dir_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_dir", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_dir_opts", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "is_dir_opts", "is_dir_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_dir");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "followsymlinks", optargs->followsymlinks ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_dir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK) {
    args.followsymlinks = optargs->followsymlinks;
  } else {
    args.followsymlinks = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_IS_DIR,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_is_dir_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_dir", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_dir_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_DIR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_dir", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_dir",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->dirflag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_dir");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_dir_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_write_file (guestfs_h *g,
                    const char *path,
                    const char *content,
                    int size)
{
  guestfs_protobuf_write_file_args args;
  guestfs_protobuf_write_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "write_file", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_file", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_file", "content");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "write_file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " \"%s\"", content);
    fprintf (trace_buffer.fp, " %d", size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "write_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.content = (char *) content;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_WRITE_FILE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_write_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "write_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_WRITE_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "write_file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "write_file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "write_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_statvfs *
guestfs_statvfs (guestfs_h *g,
                 const char *path)
{
  guestfs_protobuf_statvfs_args args;
  guestfs_protobuf_statvfs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_statvfs_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_statvfs *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "statvfs", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "statvfs", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "statvfs");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "statvfs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STATVFS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_statvfs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "statvfs", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_statvfs_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_STATVFS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "statvfs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "statvfs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_statvfs))
;  convert_guestfs_int_statvfs_protobuf_to_xdr (ret->statbuf, (guestfs_int_statvfs *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "statvfs");
    fprintf (trace_buffer.fp, "<struct guestfs_statvfs *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_statvfs_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_setro (guestfs_h *g,
                        const char *device)
{
  guestfs_protobuf_blockdev_setro_args args;
  guestfs_protobuf_blockdev_setro_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_setro", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_setro", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_setro");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_setro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETRO,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_setro_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "blockdev_setro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_SETRO, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_setro", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_setro",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_setro");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_blockdev_getsz (guestfs_h *g,
                        const char *device)
{
  guestfs_protobuf_blockdev_getsz_args args;
  guestfs_protobuf_blockdev_getsz_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blockdev_getsz_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getsz", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getsz", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_getsz");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_getsz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSZ,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_getsz_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blockdev_getsz", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blockdev_getsz_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_GETSZ, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getsz", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_getsz",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->sizeinsectors;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_getsz");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_blockdev_getsz_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_upload (guestfs_h *g,
                const char *filename,
                const char *remotefilename)
{
  guestfs_protobuf_upload_args args;
  guestfs_protobuf_upload_args__init (&args);
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
                                    "upload", 6);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload", "filename");
    return -1;
  }
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload", "remotefilename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "upload");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", remotefilename);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs___check_appliance_up (g, "upload") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  args.remotefilename = (char *) remotefilename;
  serial = guestfs___send (g, GUESTFS_PROC_UPLOAD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_upload_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "upload");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "upload", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_UPLOAD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "upload", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "upload",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "upload");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_checksum (guestfs_h *g,
                  const char *csumtype,
                  const char *path)
{
  guestfs_protobuf_checksum_args args;
  guestfs_protobuf_checksum_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_checksum_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "checksum", 8);
  if (csumtype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksum", "csumtype");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksum", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "checksum");
    fprintf (trace_buffer.fp, " \"%s\"", csumtype);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "checksum") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  args.csumtype = (char *) csumtype;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUM,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_checksum_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "checksum", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_checksum_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CHECKSUM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "checksum", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "checksum",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->checksum); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "checksum");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_checksum_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_tar_in_opts_argv (guestfs_h *g,
                          const char *tarfile,
                          const char *directory,
                          const struct guestfs_tar_in_opts_argv *optargs)
{
  struct guestfs_tar_in_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_tar_in_args args;
  guestfs_protobuf_tar_in_args__init (&args);
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
                                    "tar_in", 6);
  if (tarfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_in_opts", "tarfile");
    return -1;
  }
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_in_opts", "directory");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK) &&
      optargs->compress == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "tar_in_opts", "compress");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "tar_in_opts", "tar_in_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tar_in");
    fprintf (trace_buffer.fp, " \"%s\"", tarfile);
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    if (optargs->bitmask & GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "compress", optargs->compress);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (stat (tarfile, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs___check_appliance_up (g, "tar_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  if (optargs->bitmask & GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK) {
    args.compress = (char *) optargs->compress;
  } else {
    args.compress = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_TAR_IN,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_tar_in_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  r = guestfs___send_file (g, tarfile);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "tar_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "tar_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TAR_IN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tar_in", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "tar_in",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tar_in");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_e2label (guestfs_h *g,
                     const char *device)
{
  guestfs_protobuf_get_e2label_args args;
  guestfs_protobuf_get_e2label_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_get_e2label_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_e2label", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_e2label", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_e2label");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "get_e2label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2LABEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_get_e2label_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "get_e2label", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_get_e2label_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GET_E2LABEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_e2label", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "get_e2label",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->label); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "get_e2label");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_get_e2label_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_zero (guestfs_h *g,
              const char *device)
{
  guestfs_protobuf_zero_args args;
  guestfs_protobuf_zero_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zero", 4);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zero", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zero");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "zero") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZERO,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_zero_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "zero", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ZERO, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zero", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "zero",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "zero");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_cp_aa (guestfs_h *g,
               const char *src,
               const char *dest)
{
  guestfs_protobuf_cp_aa_args args;
  guestfs_protobuf_cp_aa_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cp_aa", 5);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp_aa", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp_aa", "dest");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "cp_aa");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "cp_aa") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_aa", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP_AA,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_cp_aa_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_aa", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "cp_aa", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_aa", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CP_AA, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_aa", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_aa", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cp_aa", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "cp_aa",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "cp_aa");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_dmesg (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_dmesg_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "dmesg", 5);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "dmesg");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "dmesg") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_DMESG, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "dmesg", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_dmesg_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DMESG, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "dmesg", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "dmesg",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->kmsgs); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "dmesg");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_dmesg_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ping_daemon (guestfs_h *g)
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
                                    "ping_daemon", 11);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ping_daemon");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ping_daemon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_PING_DAEMON, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ping_daemon", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PING_DAEMON, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ping_daemon", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ping_daemon",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ping_daemon");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_equal (guestfs_h *g,
               const char *file1,
               const char *file2)
{
  guestfs_protobuf_equal_args args;
  guestfs_protobuf_equal_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_equal_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "equal", 5);
  if (file1 == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "equal", "file1");
    return -1;
  }
  if (file2 == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "equal", "file2");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "equal");
    fprintf (trace_buffer.fp, " \"%s\"", file1);
    fprintf (trace_buffer.fp, " \"%s\"", file2);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "equal") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  args.file1 = (char *) file1;
  args.file2 = (char *) file2;
  serial = guestfs___send (g, GUESTFS_PROC_EQUAL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_equal_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "equal", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_equal_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_EQUAL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "equal", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "equal",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->equality;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "equal");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_equal_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_strings (guestfs_h *g,
                 const char *path)
{
  guestfs_protobuf_strings_args args;
  guestfs_protobuf_strings_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_strings_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "strings", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "strings", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "strings");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "strings") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STRINGS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_strings_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "strings", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_strings_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_STRINGS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "strings", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "strings",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_stringsout));
  int i;
  for (i = 0; i < ret->n_stringsout - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->stringsout[i]);
  }
  ret_v[ret->n_stringsout - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "strings");
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
  guestfs_protobuf_strings_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_zerofree (guestfs_h *g,
                  const char *device)
{
  guestfs_protobuf_zerofree_args args;
  guestfs_protobuf_zerofree_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zerofree", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zerofree", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zerofree");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "zerofree") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZEROFREE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_zerofree_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "zerofree", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ZEROFREE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zerofree", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "zerofree",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "zerofree");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_sfdisk_ll (guestfs_h *g,
                   const char *device)
{
  guestfs_protobuf_sfdisk_ll_args args;
  guestfs_protobuf_sfdisk_ll_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_sfdisk_ll_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sfdisk_ll", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_ll", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sfdisk_ll");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sfdisk_ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_ll", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_LL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_sfdisk_ll_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_ll", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "sfdisk_ll", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_sfdisk_ll_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_ll", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SFDISK_LL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_ll", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_ll", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_ll", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sfdisk_ll",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->partitions); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sfdisk_ll");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_sfdisk_ll_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_tail_nn (guestfs_h *g,
                 int nrlines,
                 const char *path)
{
  guestfs_protobuf_tail_nn_args args;
  guestfs_protobuf_tail_nn_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_tail_nn_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tail_nn", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tail_nn", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tail_nn");
    fprintf (trace_buffer.fp, " %d", nrlines);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "tail_nn") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_nn", "NULL");
    return NULL;
  }

  args.nrlines = nrlines;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TAIL_NN,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_tail_nn_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_nn", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "tail_nn", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_tail_nn_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_nn", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TAIL_NN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_nn", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_nn", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tail_nn", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "tail_nn",
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
    fprintf (trace_buffer.fp, "%s = ", "tail_nn");
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
  guestfs_protobuf_tail_nn_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_du (guestfs_h *g,
            const char *path)
{
  guestfs_protobuf_du_args args;
  guestfs_protobuf_du_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_du_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "du", 2);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "du", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "du");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "du") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_DU,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_du_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "du", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_du_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DU, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "du", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "du",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->sizekb;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "du");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_du_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mknod_bb (guestfs_h *g,
                  int mode,
                  int devmajor,
                  int devminor,
                  const char *path)
{
  guestfs_protobuf_mknod_bb_args args;
  guestfs_protobuf_mknod_bb_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mknod_bb", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mknod_bb", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mknod_bb");
    fprintf (trace_buffer.fp, " %d", mode);
    fprintf (trace_buffer.fp, " %d", devmajor);
    fprintf (trace_buffer.fp, " %d", devminor);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mknod_bb") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_bb", "-1");
    return -1;
  }

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD_BB,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mknod_bb_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_bb", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mknod_bb", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_bb", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKNOD_BB, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_bb", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_bb", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mknod_bb", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mknod_bb",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mknod_bb");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_fgrepi (guestfs_h *g,
                const char *pattern,
                const char *path)
{
  guestfs_protobuf_fgrepi_args args;
  guestfs_protobuf_fgrepi_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_fgrepi_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fgrepi", 6);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrepi", "pattern");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fgrepi");
    fprintf (trace_buffer.fp, " \"%s\"", pattern);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "fgrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FGREPI,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_fgrepi_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "fgrepi", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_fgrepi_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FGREPI, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fgrepi", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "fgrepi",
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
    fprintf (trace_buffer.fp, "%s = ", "fgrepi");
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
  guestfs_protobuf_fgrepi_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_zgrepi (guestfs_h *g,
                const char *regex,
                const char *path)
{
  guestfs_protobuf_zgrepi_args args;
  guestfs_protobuf_zgrepi_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_zgrepi_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zgrepi", 6);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zgrepi");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "zgrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZGREPI,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_zgrepi_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "zgrepi", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_zgrepi_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ZGREPI, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zgrepi", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "zgrepi",
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
    fprintf (trace_buffer.fp, "%s = ", "zgrepi");
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
  guestfs_protobuf_zgrepi_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ln_ff (guestfs_h *g,
               const char *target,
               const char *linkname)
{
  guestfs_protobuf_ln_ff_args args;
  guestfs_protobuf_ln_ff_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ln_ff", 5);
  if (target == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_ff", "target");
    return -1;
  }
  if (linkname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_ff", "linkname");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ln_ff");
    fprintf (trace_buffer.fp, " \"%s\"", target);
    fprintf (trace_buffer.fp, " \"%s\"", linkname);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ln_ff") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ff", "-1");
    return -1;
  }

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_FF,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ln_ff_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ff", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ln_ff", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ff", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LN_FF, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ff", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ff", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln_ff", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ln_ff",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ln_ff");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ln_ss (guestfs_h *g,
               const char *target,
               const char *linkname)
{
  guestfs_protobuf_ln_ss_args args;
  guestfs_protobuf_ln_ss_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ln_ss", 5);
  if (target == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_ss", "target");
    return -1;
  }
  if (linkname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_ss", "linkname");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ln_ss");
    fprintf (trace_buffer.fp, " \"%s\"", target);
    fprintf (trace_buffer.fp, " \"%s\"", linkname);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ln_ss") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ss", "-1");
    return -1;
  }

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_SS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ln_ss_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ss", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ln_ss", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ss", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LN_SS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ss", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_ss", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln_ss", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ln_ss",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ln_ss");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapoff_label (guestfs_h *g,
                       const char *label)
{
  guestfs_protobuf_swapoff_label_args args;
  guestfs_protobuf_swapoff_label_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapoff_label", 13);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_label", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapoff_label");
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "swapoff_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_LABEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_swapoff_label_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "swapoff_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SWAPOFF_LABEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_label", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "swapoff_label",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapoff_label");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapoff_uuid (guestfs_h *g,
                      const char *uuid)
{
  guestfs_protobuf_swapoff_uuid_args args;
  guestfs_protobuf_swapoff_uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapoff_uuid", 12);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapoff_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "swapoff_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_swapoff_uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "swapoff_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SWAPOFF_UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "swapoff_uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapoff_uuid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_inotify_init (guestfs_h *g,
                      int maxevents)
{
  guestfs_protobuf_inotify_init_args args;
  guestfs_protobuf_inotify_init_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_init", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inotify_init");
    fprintf (trace_buffer.fp, " %d", maxevents);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "inotify_init") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  args.maxevents = maxevents;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_INIT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_inotify_init_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "inotify_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INOTIFY_INIT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_init", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "inotify_init",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "inotify_init");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_inotify_add_watch (guestfs_h *g,
                           const char *path,
                           int mask)
{
  guestfs_protobuf_inotify_add_watch_args args;
  guestfs_protobuf_inotify_add_watch_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_inotify_add_watch_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_add_watch", 17);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inotify_add_watch", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inotify_add_watch");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %d", mask);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "inotify_add_watch") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.mask = mask;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_ADD_WATCH,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_inotify_add_watch_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "inotify_add_watch", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_inotify_add_watch_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INOTIFY_ADD_WATCH, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_add_watch", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "inotify_add_watch",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->wd;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "inotify_add_watch");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_inotify_add_watch_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_setcon (guestfs_h *g,
                const char *context)
{
  guestfs_protobuf_setcon_args args;
  guestfs_protobuf_setcon_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "setcon", 6);
  if (context == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "setcon", "context");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "setcon");
    fprintf (trace_buffer.fp, " \"%s\"", context);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "setcon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  args.context = (char *) context;
  serial = guestfs___send (g, GUESTFS_PROC_SETCON,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_setcon_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "setcon", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SETCON, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "setcon", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "setcon",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "setcon");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_getcon (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_getcon_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "getcon", 6);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "getcon");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "getcon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_GETCON, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "getcon", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_getcon_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GETCON, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "getcon", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "getcon",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->context); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "getcon");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_getcon_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mke2journal (guestfs_h *g,
                     int blocksize,
                     const char *device)
{
  guestfs_protobuf_mke2journal_args args;
  guestfs_protobuf_mke2journal_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2journal", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mke2journal");
    fprintf (trace_buffer.fp, " %d", blocksize);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mke2journal") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  args.blocksize = blocksize;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mke2journal_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mke2journal", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKE2JOURNAL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2journal", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mke2journal",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mke2journal");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mke2fs_jl (guestfs_h *g,
                   const char *fstype,
                   int blocksize,
                   const char *device,
                   const char *label)
{
  guestfs_protobuf_mke2fs_jl_args args;
  guestfs_protobuf_mke2fs_jl_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs_jl", 9);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_jl", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_jl", "device");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_jl", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mke2fs_jl");
    fprintf (trace_buffer.fp, " \"%s\"", fstype);
    fprintf (trace_buffer.fp, " %d", blocksize);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mke2fs_jl") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jl", "-1");
    return -1;
  }

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mke2fs_jl_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jl", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mke2fs_jl", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jl", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKE2FS_JL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jl", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jl", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs_jl", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mke2fs_jl",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mke2fs_jl");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mke2fs_ju (guestfs_h *g,
                   const char *fstype,
                   int blocksize,
                   const char *device,
                   const char *uuid)
{
  guestfs_protobuf_mke2fs_ju_args args;
  guestfs_protobuf_mke2fs_ju_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs_ju", 9);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_ju", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_ju", "device");
    return -1;
  }
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_ju", "uuid");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mke2fs_ju");
    fprintf (trace_buffer.fp, " \"%s\"", fstype);
    fprintf (trace_buffer.fp, " %d", blocksize);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mke2fs_ju") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_ju", "-1");
    return -1;
  }

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JU,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mke2fs_ju_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_ju", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mke2fs_ju", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_ju", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKE2FS_JU, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_ju", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_ju", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs_ju", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mke2fs_ju",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mke2fs_ju");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_echo_daemon (guestfs_h *g,
                     char *const *words)
{
  guestfs_protobuf_echo_daemon_args args;
  guestfs_protobuf_echo_daemon_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_echo_daemon_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "echo_daemon", 11);
  if (words == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "echo_daemon", "words");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "echo_daemon");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; words[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (words[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "echo_daemon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  args.words = (char **) words;
  for (args.n_words = 0; words[args.n_words]; args.n_words++) ;
  serial = guestfs___send (g, GUESTFS_PROC_ECHO_DAEMON,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_echo_daemon_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "echo_daemon", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_echo_daemon_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ECHO_DAEMON, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "echo_daemon", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "echo_daemon",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->output); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "echo_daemon");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_echo_daemon_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_truncate (guestfs_h *g,
                  const char *path)
{
  guestfs_protobuf_truncate_args args;
  guestfs_protobuf_truncate_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "truncate", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "truncate", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "truncate");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "truncate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TRUNCATE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_truncate_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "truncate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TRUNCATE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "truncate", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "truncate",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "truncate");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_utimens (guestfs_h *g,
                 const char *path,
                 int64_t atsecs,
                 int64_t atnsecs,
                 int64_t mtsecs,
                 int64_t mtnsecs)
{
  guestfs_protobuf_utimens_args args;
  guestfs_protobuf_utimens_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "utimens", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "utimens", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "utimens");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %" PRIi64, atsecs);
    fprintf (trace_buffer.fp, " %" PRIi64, atnsecs);
    fprintf (trace_buffer.fp, " %" PRIi64, mtsecs);
    fprintf (trace_buffer.fp, " %" PRIi64, mtnsecs);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "utimens") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.atsecs = atsecs;
  args.atnsecs = atnsecs;
  args.mtsecs = mtsecs;
  args.mtnsecs = mtnsecs;
  serial = guestfs___send (g, GUESTFS_PROC_UTIMENS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_utimens_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "utimens", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_UTIMENS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "utimens", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "utimens",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "utimens");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkdir_mode (guestfs_h *g,
                    const char *path,
                    int mode)
{
  guestfs_protobuf_mkdir_mode_args args;
  guestfs_protobuf_mkdir_mode_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkdir_mode", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdir_mode", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkdir_mode");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %d", mode);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mkdir_mode") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.mode = mode;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR_MODE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mkdir_mode_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mkdir_mode", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKDIR_MODE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdir_mode", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mkdir_mode",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkdir_mode");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_available (guestfs_h *g,
                   char *const *groups)
{
  guestfs_protobuf_available_args args;
  guestfs_protobuf_available_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "available", 9);
  if (groups == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "available", "groups");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "available");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; groups[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (groups[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "available") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  args.groups = (char **) groups;
  for (args.n_groups = 0; groups[args.n_groups]; args.n_groups++) ;
  serial = guestfs___send (g, GUESTFS_PROC_AVAILABLE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_available_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "available", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AVAILABLE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "available", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "available",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "available");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_del (guestfs_h *g,
                  const char *device,
                  int partnum)
{
  guestfs_protobuf_part_del_args args;
  guestfs_protobuf_part_del_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_del", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_del", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_del");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_del") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_DEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_del_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "part_del", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_DEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_del", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_del",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_del");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ntfsresize_size (guestfs_h *g,
                         const char *device,
                         int64_t size)
{
  guestfs_protobuf_ntfsresize_size_args args;
  guestfs_protobuf_ntfsresize_size_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfsresize_size", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsresize_size", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ntfsresize_size");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ntfsresize_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_NTFSRESIZE_SIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ntfsresize_size_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ntfsresize_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_NTFSRESIZE_SIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsresize_size", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ntfsresize_size",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ntfsresize_size");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_vfs_uuid (guestfs_h *g,
                  const char *mountable)
{
  guestfs_protobuf_vfs_uuid_args args;
  guestfs_protobuf_vfs_uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_vfs_uuid_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vfs_uuid", 8);
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vfs_uuid", "mountable");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vfs_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "vfs_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  args.mountable = (char *) mountable;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_vfs_uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "vfs_uuid", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_vfs_uuid_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_VFS_UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vfs_uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "vfs_uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->uuid); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vfs_uuid");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_vfs_uuid_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_getxattr (guestfs_h *g,
                  const char *path,
                  const char *name,
                  size_t *size_r)
{
  guestfs_protobuf_getxattr_args args;
  guestfs_protobuf_getxattr_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_getxattr_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "getxattr", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "getxattr", "path");
    return NULL;
  }
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "getxattr", "name");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "getxattr");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " \"%s\"", name);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "getxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_GETXATTR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_getxattr_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "getxattr", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_getxattr_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GETXATTR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "getxattr", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "getxattr",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret->xattr.len > 0) {
    *size_r = ret->xattr.len;
    ret_v = safe_memdup (g, ret->xattr.data, ret->xattr.len); /* caller will free */
  } else {
    char *p = safe_malloc (g, 1);
    *size_r = ret->xattr.len;
    ret_v = p;
  }
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "getxattr");
    guestfs___print_BufferOut (trace_buffer.fp, ret_v, *size_r);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_getxattr_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_zero_device (guestfs_h *g,
                        const char *device)
{
  guestfs_protobuf_is_zero_device_args args;
  guestfs_protobuf_is_zero_device_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_zero_device_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_zero_device", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_zero_device", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_zero_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_zero_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_IS_ZERO_DEVICE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_is_zero_device_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_zero_device", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_zero_device_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_ZERO_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_zero_device", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_zero_device",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->zeroflag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_zero_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_zero_device_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list9p (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_list9p_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list9p", 6);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list9p");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "list9p") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list9p", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LIST9P, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list9p", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "list9p", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_list9p_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list9p", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LIST9P, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list9p", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list9p", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list9p", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "list9p",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_mounttags));
  int i;
  for (i = 0; i < ret->n_mounttags - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->mounttags[i]);
  }
  ret_v[ret->n_mounttags - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "list9p");
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
  guestfs_protobuf_list9p_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_filesystem_resize_argv (guestfs_h *g,
                                      const char *mountpoint,
                                      const struct guestfs_btrfs_filesystem_resize_argv *optargs)
{
  struct guestfs_btrfs_filesystem_resize_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_btrfs_filesystem_resize_args args;
  guestfs_protobuf_btrfs_filesystem_resize_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_filesystem_resize", 23);
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_filesystem_resize", "mountpoint");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "btrfs_filesystem_resize", "btrfs_filesystem_resize");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_filesystem_resize");
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_filesystem_resize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  args.mountpoint = (char *) mountpoint;
  if (optargs->bitmask & GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK) {
    args.size = optargs->size;
  } else {
    args.size = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_filesystem_resize_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_filesystem_resize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_filesystem_resize", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_filesystem_resize",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_filesystem_resize");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_tune2fs_argv (guestfs_h *g,
                      const char *device,
                      const struct guestfs_tune2fs_argv *optargs)
{
  struct guestfs_tune2fs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_tune2fs_args args;
  guestfs_protobuf_tune2fs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tune2fs", 7);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tune2fs", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK) &&
      optargs->errorbehavior == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "tune2fs", "errorbehavior");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK) &&
      optargs->lastmounteddirectory == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "tune2fs", "lastmounteddirectory");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffc00)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "tune2fs", "tune2fs");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tune2fs");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_TUNE2FS_FORCE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "maxmountcount", optargs->maxmountcount);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "mountcount", optargs->mountcount);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "errorbehavior", optargs->errorbehavior);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_GROUP_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "group", optargs->group);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "intervalbetweenchecks", optargs->intervalbetweenchecks);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "reservedblockspercentage", optargs->reservedblockspercentage);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "lastmounteddirectory", optargs->lastmounteddirectory);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "reservedblockscount", optargs->reservedblockscount);
    }
    if (optargs->bitmask & GUESTFS_TUNE2FS_USER_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "user", optargs->user);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "tune2fs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_TUNE2FS_FORCE_BITMASK) {
    args.force = optargs->force;
  } else {
    args.force = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK) {
    args.maxmountcount = optargs->maxmountcount;
  } else {
    args.maxmountcount = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK) {
    args.mountcount = optargs->mountcount;
  } else {
    args.mountcount = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK) {
    args.errorbehavior = (char *) optargs->errorbehavior;
  } else {
    args.errorbehavior = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_GROUP_BITMASK) {
    args.group = optargs->group;
  } else {
    args.group = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK) {
    args.intervalbetweenchecks = optargs->intervalbetweenchecks;
  } else {
    args.intervalbetweenchecks = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK) {
    args.reservedblockspercentage = optargs->reservedblockspercentage;
  } else {
    args.reservedblockspercentage = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK) {
    args.lastmounteddirectory = (char *) optargs->lastmounteddirectory;
  } else {
    args.lastmounteddirectory = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK) {
    args.reservedblockscount = optargs->reservedblockscount;
  } else {
    args.reservedblockscount = 0;
  }
  if (optargs->bitmask & GUESTFS_TUNE2FS_USER_BITMASK) {
    args.user = optargs->user;
  } else {
    args.user = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_TUNE2FS,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_tune2fs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "tune2fs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TUNE2FS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tune2fs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "tune2fs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tune2fs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_subvolume_delete (guestfs_h *g,
                                const char *subvolume)
{
  guestfs_protobuf_btrfs_subvolume_delete_args args;
  guestfs_protobuf_btrfs_subvolume_delete_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_subvolume_delete", 22);
  if (subvolume == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_delete", "subvolume");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_subvolume_delete");
    fprintf (trace_buffer.fp, " \"%s\"", subvolume);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_subvolume_delete") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_delete", "-1");
    return -1;
  }

  args.subvolume = (char *) subvolume;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_SUBVOLUME_DELETE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_subvolume_delete_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_delete", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_subvolume_delete", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_delete", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_SUBVOLUME_DELETE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_delete", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_delete", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_subvolume_delete", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_subvolume_delete",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_subvolume_delete");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfssubvolume_list *
guestfs_btrfs_subvolume_list (guestfs_h *g,
                              const char *fs)
{
  guestfs_protobuf_btrfs_subvolume_list_args args;
  guestfs_protobuf_btrfs_subvolume_list_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_btrfs_subvolume_list_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_btrfssubvolume_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_subvolume_list", 20);
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_list", "fs");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_subvolume_list");
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_subvolume_list") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_list", "NULL");
    return NULL;
  }

  args.fs = (char *) fs;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_SUBVOLUME_LIST,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_subvolume_list_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_list", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "btrfs_subvolume_list", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_btrfs_subvolume_list_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_list", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_SUBVOLUME_LIST, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_list", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_list", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_subvolume_list", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_subvolume_list",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_btrfssubvolume_list));
  convert_guestfs_int_btrfssubvolume_list_protobuf_to_xdr (ret->subvolumes, (guestfs_int_btrfssubvolume_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_subvolume_list");
    fprintf (trace_buffer.fp, "<struct guestfs_btrfssubvolume_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_btrfs_subvolume_list_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_filesystem_sync (guestfs_h *g,
                               const char *fs)
{
  guestfs_protobuf_btrfs_filesystem_sync_args args;
  guestfs_protobuf_btrfs_filesystem_sync_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_filesystem_sync", 21);
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_filesystem_sync", "fs");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_filesystem_sync");
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_filesystem_sync") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_sync", "-1");
    return -1;
  }

  args.fs = (char *) fs;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_FILESYSTEM_SYNC,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_filesystem_sync_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_sync", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_filesystem_sync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_sync", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_FILESYSTEM_SYNC, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_sync", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_sync", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_filesystem_sync", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_filesystem_sync",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_filesystem_sync");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_device_delete (guestfs_h *g,
                             char *const *devices,
                             const char *fs)
{
  guestfs_protobuf_btrfs_device_delete_args args;
  guestfs_protobuf_btrfs_device_delete_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_device_delete", 19);
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_device_delete", "devices");
    return -1;
  }
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_device_delete", "fs");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_device_delete");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (devices[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_device_delete") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_device_delete", "-1");
    return -1;
  }

  args.devices = (char **) devices;
  for (args.n_devices = 0; devices[args.n_devices]; args.n_devices++) ;
  args.fs = (char *) fs;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_DEVICE_DELETE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_device_delete_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_device_delete", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_device_delete", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_device_delete", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_DEVICE_DELETE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_device_delete", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_device_delete", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_device_delete", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_device_delete",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_device_delete");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rsync_argv (guestfs_h *g,
                    const char *src,
                    const char *dest,
                    const struct guestfs_rsync_argv *optargs)
{
  struct guestfs_rsync_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_rsync_args args;
  guestfs_protobuf_rsync_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rsync", 5);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rsync", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rsync", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "rsync", "rsync");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rsync");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_RSYNC_ARCHIVE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "archive", optargs->archive ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_RSYNC_DELETEDEST_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "deletedest", optargs->deletedest ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rsync") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_RSYNC_ARCHIVE_BITMASK) {
    args.archive = optargs->archive;
  } else {
    args.archive = 0;
  }
  if (optargs->bitmask & GUESTFS_RSYNC_DELETEDEST_BITMASK) {
    args.deletedest = optargs->deletedest;
  } else {
    args.deletedest = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_RSYNC,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_rsync_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rsync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RSYNC, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rsync", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rsync",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rsync");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ls0 (guestfs_h *g,
             const char *dir,
             const char *filenames)
{
  guestfs_protobuf_ls0_args args;
  guestfs_protobuf_ls0_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ls0", 3);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ls0", "dir");
    return -1;
  }
  if (filenames == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ls0", "filenames");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ls0");
    fprintf (trace_buffer.fp, " \"%s\"", dir);
    fprintf (trace_buffer.fp, " \"%s\"", filenames);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ls0") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls0", "-1");
    return -1;
  }

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_LS0,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ls0_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls0", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ls0", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls0", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LS0, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls0", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls0", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ls0", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ls0",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  if (guestfs___recv_file (g, filenames) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls0", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ls0");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_hivex_open_argv (guestfs_h *g,
                         const char *filename,
                         const struct guestfs_hivex_open_argv *optargs)
{
  struct guestfs_hivex_open_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_hivex_open_args args;
  guestfs_protobuf_hivex_open_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_open", 10);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hivex_open", "filename");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "hivex_open", "hivex_open");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_open");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    if (optargs->bitmask & GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "verbose", optargs->verbose ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_HIVEX_OPEN_DEBUG_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "debug", optargs->debug ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_HIVEX_OPEN_WRITE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "write", optargs->write ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_open") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_open", "-1");
    return -1;
  }

  args.filename = (char *) filename;
  if (optargs->bitmask & GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK) {
    args.verbose = optargs->verbose;
  } else {
    args.verbose = 0;
  }
  if (optargs->bitmask & GUESTFS_HIVEX_OPEN_DEBUG_BITMASK) {
    args.debug = optargs->debug;
  } else {
    args.debug = 0;
  }
  if (optargs->bitmask & GUESTFS_HIVEX_OPEN_WRITE_BITMASK) {
    args.write = optargs->write;
  } else {
    args.write = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_OPEN,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_hivex_open_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_open", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "hivex_open", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_open", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_OPEN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_open", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_open", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_open", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_open",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_open");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_hivex_close (guestfs_h *g)
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
                                    "hivex_close", 11);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_close");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_close", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_CLOSE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_close", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "hivex_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_close", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_CLOSE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_close", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_close", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_close", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_close",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_close");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rm_ff (guestfs_h *g,
               const char *path)
{
  guestfs_protobuf_rm_ff_args args;
  guestfs_protobuf_rm_ff_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rm_ff", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rm_ff", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rm_ff");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rm_ff") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_ff", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM_FF,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_rm_ff_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_ff", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rm_ff", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_ff", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RM_FF, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_ff", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_ff", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rm_ff", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rm_ff",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rm_ff");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mke2fs_argv (guestfs_h *g,
                     const char *device,
                     const struct guestfs_mke2fs_argv *optargs)
{
  struct guestfs_mke2fs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_mke2fs_args args;
  guestfs_protobuf_mke2fs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK) &&
      optargs->journaldevice == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "journaldevice");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "label");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK) &&
      optargs->lastmounteddir == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "lastmounteddir");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_CREATOROS_BITMASK) &&
      optargs->creatoros == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "creatoros");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_FSTYPE_BITMASK) &&
      optargs->fstype == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "fstype");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_USAGETYPE_BITMASK) &&
      optargs->usagetype == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "usagetype");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKE2FS_UUID_BITMASK) &&
      optargs->uuid == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mke2fs", "uuid");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffc000000000)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mke2fs", "mke2fs");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mke2fs");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "blockscount", optargs->blockscount);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_BLOCKSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "blocksize", optargs->blocksize);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_FRAGSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "fragsize", optargs->fragsize);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "blockspergroup", optargs->blockspergroup);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "numberofgroups", optargs->numberofgroups);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_BYTESPERINODE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "bytesperinode", optargs->bytesperinode);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_INODESIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "inodesize", optargs->inodesize);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_JOURNALSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "journalsize", optargs->journalsize);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "numberofinodes", optargs->numberofinodes);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_STRIDESIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "stridesize", optargs->stridesize);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "stripewidth", optargs->stripewidth);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "maxonlineresize", optargs->maxonlineresize);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "reservedblockspercentage", optargs->reservedblockspercentage);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "mmpupdateinterval", optargs->mmpupdateinterval);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "journaldevice", optargs->journaldevice);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_LABEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "label", optargs->label);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "lastmounteddir", optargs->lastmounteddir);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_CREATOROS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "creatoros", optargs->creatoros);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_FSTYPE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "fstype", optargs->fstype);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_USAGETYPE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "usagetype", optargs->usagetype);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_UUID_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "uuid", optargs->uuid);
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_FORCECREATE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "forcecreate", optargs->forcecreate ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "writesbandgrouponly", optargs->writesbandgrouponly ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "lazyitableinit", optargs->lazyitableinit ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "lazyjournalinit", optargs->lazyjournalinit ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_TESTFS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "testfs", optargs->testfs ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_DISCARD_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "discard", optargs->discard ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_QUOTATYPE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "quotatype", optargs->quotatype ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_EXTENT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "extent", optargs->extent ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_FILETYPE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "filetype", optargs->filetype ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_FLEXBG_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "flexbg", optargs->flexbg ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_HASJOURNAL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "hasjournal", optargs->hasjournal ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_JOURNALDEV_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "journaldev", optargs->journaldev ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_LARGEFILE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "largefile", optargs->largefile ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_QUOTA_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "quota", optargs->quota ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_RESIZEINODE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "resizeinode", optargs->resizeinode ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_SPARSESUPER_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "sparsesuper", optargs->sparsesuper ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_MKE2FS_UNINITBG_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "uninitbg", optargs->uninitbg ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mke2fs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK) {
    args.blockscount = optargs->blockscount;
  } else {
    args.blockscount = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_BLOCKSIZE_BITMASK) {
    args.blocksize = optargs->blocksize;
  } else {
    args.blocksize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_FRAGSIZE_BITMASK) {
    args.fragsize = optargs->fragsize;
  } else {
    args.fragsize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK) {
    args.blockspergroup = optargs->blockspergroup;
  } else {
    args.blockspergroup = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK) {
    args.numberofgroups = optargs->numberofgroups;
  } else {
    args.numberofgroups = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_BYTESPERINODE_BITMASK) {
    args.bytesperinode = optargs->bytesperinode;
  } else {
    args.bytesperinode = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_INODESIZE_BITMASK) {
    args.inodesize = optargs->inodesize;
  } else {
    args.inodesize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_JOURNALSIZE_BITMASK) {
    args.journalsize = optargs->journalsize;
  } else {
    args.journalsize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK) {
    args.numberofinodes = optargs->numberofinodes;
  } else {
    args.numberofinodes = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_STRIDESIZE_BITMASK) {
    args.stridesize = optargs->stridesize;
  } else {
    args.stridesize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK) {
    args.stripewidth = optargs->stripewidth;
  } else {
    args.stripewidth = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK) {
    args.maxonlineresize = optargs->maxonlineresize;
  } else {
    args.maxonlineresize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK) {
    args.reservedblockspercentage = optargs->reservedblockspercentage;
  } else {
    args.reservedblockspercentage = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK) {
    args.mmpupdateinterval = optargs->mmpupdateinterval;
  } else {
    args.mmpupdateinterval = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK) {
    args.journaldevice = (char *) optargs->journaldevice;
  } else {
    args.journaldevice = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_LABEL_BITMASK) {
    args.label = (char *) optargs->label;
  } else {
    args.label = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK) {
    args.lastmounteddir = (char *) optargs->lastmounteddir;
  } else {
    args.lastmounteddir = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_CREATOROS_BITMASK) {
    args.creatoros = (char *) optargs->creatoros;
  } else {
    args.creatoros = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_FSTYPE_BITMASK) {
    args.fstype = (char *) optargs->fstype;
  } else {
    args.fstype = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_USAGETYPE_BITMASK) {
    args.usagetype = (char *) optargs->usagetype;
  } else {
    args.usagetype = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_UUID_BITMASK) {
    args.uuid = (char *) optargs->uuid;
  } else {
    args.uuid = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_FORCECREATE_BITMASK) {
    args.forcecreate = optargs->forcecreate;
  } else {
    args.forcecreate = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK) {
    args.writesbandgrouponly = optargs->writesbandgrouponly;
  } else {
    args.writesbandgrouponly = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK) {
    args.lazyitableinit = optargs->lazyitableinit;
  } else {
    args.lazyitableinit = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK) {
    args.lazyjournalinit = optargs->lazyjournalinit;
  } else {
    args.lazyjournalinit = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_TESTFS_BITMASK) {
    args.testfs = optargs->testfs;
  } else {
    args.testfs = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_DISCARD_BITMASK) {
    args.discard = optargs->discard;
  } else {
    args.discard = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_QUOTATYPE_BITMASK) {
    args.quotatype = optargs->quotatype;
  } else {
    args.quotatype = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_EXTENT_BITMASK) {
    args.extent = optargs->extent;
  } else {
    args.extent = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_FILETYPE_BITMASK) {
    args.filetype = optargs->filetype;
  } else {
    args.filetype = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_FLEXBG_BITMASK) {
    args.flexbg = optargs->flexbg;
  } else {
    args.flexbg = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_HASJOURNAL_BITMASK) {
    args.hasjournal = optargs->hasjournal;
  } else {
    args.hasjournal = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_JOURNALDEV_BITMASK) {
    args.journaldev = optargs->journaldev;
  } else {
    args.journaldev = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_LARGEFILE_BITMASK) {
    args.largefile = optargs->largefile;
  } else {
    args.largefile = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_QUOTA_BITMASK) {
    args.quota = optargs->quota;
  } else {
    args.quota = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_RESIZEINODE_BITMASK) {
    args.resizeinode = optargs->resizeinode;
  } else {
    args.resizeinode = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_SPARSESUPER_BITMASK) {
    args.sparsesuper = optargs->sparsesuper;
  } else {
    args.sparsesuper = 0;
  }
  if (optargs->bitmask & GUESTFS_MKE2FS_UNINITBG_BITMASK) {
    args.uninitbg = optargs->uninitbg;
  } else {
    args.uninitbg = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_mke2fs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mke2fs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKE2FS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mke2fs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mke2fs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_acl_get_file (guestfs_h *g,
                      const char *path,
                      const char *acltype)
{
  guestfs_protobuf_acl_get_file_args args;
  guestfs_protobuf_acl_get_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_acl_get_file_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "acl_get_file", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "acl_get_file", "path");
    return NULL;
  }
  if (acltype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "acl_get_file", "acltype");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "acl_get_file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " \"%s\"", acltype);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "acl_get_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_get_file", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.acltype = (char *) acltype;
  serial = guestfs___send (g, GUESTFS_PROC_ACL_GET_FILE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_acl_get_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_get_file", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "acl_get_file", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_acl_get_file_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_get_file", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ACL_GET_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_get_file", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_get_file", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "acl_get_file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "acl_get_file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->acl); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "acl_get_file");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_acl_get_file_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_cap_get_file (guestfs_h *g,
                      const char *path)
{
  guestfs_protobuf_cap_get_file_args args;
  guestfs_protobuf_cap_get_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_cap_get_file_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cap_get_file", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cap_get_file", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "cap_get_file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "cap_get_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cap_get_file", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CAP_GET_FILE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_cap_get_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cap_get_file", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "cap_get_file", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_cap_get_file_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cap_get_file", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CAP_GET_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cap_get_file", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cap_get_file", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cap_get_file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "cap_get_file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->cap); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "cap_get_file");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_cap_get_file_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ldmtool_remove_all (guestfs_h *g)
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
                                    "ldmtool_remove_all", 18);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_remove_all");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_remove_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_remove_all", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_REMOVE_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_remove_all", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ldmtool_remove_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_remove_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LDMTOOL_REMOVE_ALL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_remove_all", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_remove_all", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_remove_all", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ldmtool_remove_all",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_remove_all");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_ldmtool_volume_type (guestfs_h *g,
                             const char *diskgroup,
                             const char *volume)
{
  guestfs_protobuf_ldmtool_volume_type_args args;
  guestfs_protobuf_ldmtool_volume_type_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_ldmtool_volume_type_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_volume_type", 19);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_volume_type", "diskgroup");
    return NULL;
  }
  if (volume == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_volume_type", "volume");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_volume_type");
    fprintf (trace_buffer.fp, " \"%s\"", diskgroup);
    fprintf (trace_buffer.fp, " \"%s\"", volume);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_volume_type") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_type", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  args.volume = (char *) volume;
  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_VOLUME_TYPE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ldmtool_volume_type_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_type", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "ldmtool_volume_type", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_ldmtool_volume_type_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_type", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LDMTOOL_VOLUME_TYPE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_type", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_type", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_volume_type", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ldmtool_volume_type",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->voltype); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_volume_type");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_ldmtool_volume_type_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_ldmtool_volume_hint (guestfs_h *g,
                             const char *diskgroup,
                             const char *volume)
{
  guestfs_protobuf_ldmtool_volume_hint_args args;
  guestfs_protobuf_ldmtool_volume_hint_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_ldmtool_volume_hint_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_volume_hint", 19);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_volume_hint", "diskgroup");
    return NULL;
  }
  if (volume == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_volume_hint", "volume");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_volume_hint");
    fprintf (trace_buffer.fp, " \"%s\"", diskgroup);
    fprintf (trace_buffer.fp, " \"%s\"", volume);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_volume_hint") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_hint", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  args.volume = (char *) volume;
  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_VOLUME_HINT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ldmtool_volume_hint_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_hint", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "ldmtool_volume_hint", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_ldmtool_volume_hint_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_hint", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LDMTOOL_VOLUME_HINT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_hint", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_volume_hint", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_volume_hint", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ldmtool_volume_hint",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->hint); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_volume_hint");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_ldmtool_volume_hint_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_part_get_gpt_type (guestfs_h *g,
                           const char *device,
                           int partnum)
{
  guestfs_protobuf_part_get_gpt_type_args args;
  guestfs_protobuf_part_get_gpt_type_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_part_get_gpt_type_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_get_gpt_type", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_gpt_type", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_get_gpt_type");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_get_gpt_type") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_gpt_type", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_GPT_TYPE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_get_gpt_type_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_gpt_type", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "part_get_gpt_type", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_part_get_gpt_type_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_gpt_type", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_GET_GPT_TYPE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_gpt_type", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_gpt_type", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_gpt_type", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_get_gpt_type",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->guid); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_get_gpt_type");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_part_get_gpt_type_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_whole_device (guestfs_h *g,
                         const char *device)
{
  guestfs_protobuf_is_whole_device_args args;
  guestfs_protobuf_is_whole_device_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_is_whole_device_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_whole_device", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_whole_device", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_whole_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "is_whole_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_whole_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_IS_WHOLE_DEVICE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_is_whole_device_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_whole_device", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "is_whole_device", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_is_whole_device_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_whole_device", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_IS_WHOLE_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_whole_device", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_whole_device", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_whole_device", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "is_whole_device",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->flag;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_whole_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_is_whole_device_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_uuid (guestfs_h *g,
                  const char *device,
                  const char *uuid)
{
  guestfs_protobuf_set_uuid_args args;
  guestfs_protobuf_set_uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_uuid", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_uuid", "device");
    return -1;
  }
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "set_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_uuid", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SET_UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_set_uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_uuid", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "set_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_uuid", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SET_UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_uuid", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_uuid", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "set_uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_uuid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_journal_set_data_threshold (guestfs_h *g,
                                    int64_t threshold)
{
  guestfs_protobuf_journal_set_data_threshold_args args;
  guestfs_protobuf_journal_set_data_threshold_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "journal_set_data_threshold", 26);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "journal_set_data_threshold");
    fprintf (trace_buffer.fp, " %" PRIi64, threshold);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "journal_set_data_threshold") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_set_data_threshold", "-1");
    return -1;
  }

  args.threshold = threshold;
  serial = guestfs___send (g, GUESTFS_PROC_JOURNAL_SET_DATA_THRESHOLD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_journal_set_data_threshold_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_set_data_threshold", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "journal_set_data_threshold", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_set_data_threshold", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_JOURNAL_SET_DATA_THRESHOLD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_set_data_threshold", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_set_data_threshold", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "journal_set_data_threshold", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "journal_set_data_threshold",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "journal_set_data_threshold");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_setm (guestfs_h *g,
                  const char *bbase,
                  const char *sub,
                  const char *val)
{
  guestfs_protobuf_aug_setm_args args;
  guestfs_protobuf_aug_setm_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_aug_setm_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_setm", 8);
  if (bbase == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_setm", "bbase");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_setm", "val");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_setm");
    fprintf (trace_buffer.fp, " \"%s\"", bbase);
    if (sub)
      fprintf (trace_buffer.fp, " \"%s\"", sub);
    else
      fprintf (trace_buffer.fp, " null");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_setm") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_setm", "-1");
    return -1;
  }

  args.bbase = (char *) bbase;
  args.sub = sub ? (char **) &sub : NULL;
  args.n_sub = sub ? 1 : 0;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_SETM,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_setm_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_setm", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "aug_setm", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_aug_setm_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_setm", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_SETM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_setm", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_setm", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_setm", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_setm",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->nodes;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_setm");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_aug_setm_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_exit (guestfs_h *g)
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
                                    "internal_exit", 13);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_exit");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "internal_exit") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_exit", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_EXIT, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_exit", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "internal_exit", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_exit", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_EXIT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_exit", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_exit", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_exit", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_exit",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_exit");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blkdiscard (guestfs_h *g,
                    const char *device)
{
  guestfs_protobuf_blkdiscard_args args;
  guestfs_protobuf_blkdiscard_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blkdiscard", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blkdiscard", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blkdiscard");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blkdiscard") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscard", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLKDISCARD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blkdiscard_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscard", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "blkdiscard", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscard", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLKDISCARD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscard", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkdiscard", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blkdiscard", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blkdiscard",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blkdiscard");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_journal_get_realtime_usec (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_journal_get_realtime_usec_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "journal_get_realtime_usec", 25);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "journal_get_realtime_usec");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "journal_get_realtime_usec") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_get_realtime_usec", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_JOURNAL_GET_REALTIME_USEC, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_get_realtime_usec", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "journal_get_realtime_usec", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_journal_get_realtime_usec_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_get_realtime_usec", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_JOURNAL_GET_REALTIME_USEC, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_get_realtime_usec", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_get_realtime_usec", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "journal_get_realtime_usec", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "journal_get_realtime_usec",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->usec;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "journal_get_realtime_usec");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_journal_get_realtime_usec_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_statns *
guestfs_lstatns (guestfs_h *g,
                 const char *path)
{
  guestfs_protobuf_lstatns_args args;
  guestfs_protobuf_lstatns_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_lstatns_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_statns *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lstatns", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lstatns", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lstatns");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lstatns") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatns", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSTATNS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lstatns_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatns", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "lstatns", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_lstatns_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatns", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LSTATNS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatns", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatns", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lstatns", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lstatns",
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
    fprintf (trace_buffer.fp, "%s = ", "lstatns");
    fprintf (trace_buffer.fp, "<struct guestfs_statns *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_lstatns_ret__free_unpacked (ret, NULL);
  return ret_v;
}

