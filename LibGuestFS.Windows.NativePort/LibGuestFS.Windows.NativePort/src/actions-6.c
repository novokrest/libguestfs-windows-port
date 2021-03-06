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
guestfs_internal_test_rint (guestfs_h *g,
                            const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rint", 18);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rint", "val");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rint");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rint (g, val);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rint");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rint", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_internal_test_rint64err (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rint64err", 23);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rint64err");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rint64err (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rint64err");
      fprintf (trace_buffer.fp, "%" PRIi64, r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rint64err", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_internal_test_rconststring (guestfs_h *g,
                                    const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rconststring", 26);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rconststring", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rconststring");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rconststring (g, val);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rconststring");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rconststring", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *
guestfs_internal_test_rstruct (guestfs_h *g,
                               const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_lvm_pv *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstruct", 21);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rstruct", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rstruct");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rstruct (g, val);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rstruct");
      fprintf (trace_buffer.fp, "<struct guestfs_lvm_pv *>");
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rstruct", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_wait_ready (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wait_ready", 10);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "wait_ready");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__wait_ready (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "wait_ready");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wait_ready", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_hv (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_hv", 6);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_hv");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_hv (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_hv");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_hv", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_direct (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_direct", 10);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_direct");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_direct (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_direct");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_direct", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_product_name (guestfs_h *g,
                                  const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_product_name", 24);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_product_name", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_product_name");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_product_name (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_product_name");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_product_name", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_inspect_get_mountpoints (guestfs_h *g,
                                 const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_mountpoints", 23);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_mountpoints", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_mountpoints");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_mountpoints (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_mountpoints");
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
                       "inspect_get_mountpoints", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_package_management (guestfs_h *g,
                                        const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_package_management", 30);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_package_management", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_package_management");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_package_management (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_package_management");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_package_management", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_max_disks (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "max_disks", 9);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "max_disks");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__max_disks (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "max_disks");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "max_disks", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_find (guestfs_h *g,
              const char *directory)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "find", 4);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "find", "directory");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "find");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__find (g, directory);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "find");
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
                       "find", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_read_lines (guestfs_h *g,
                    const char *path)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "read_lines", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "read_lines", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "read_lines");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__read_lines (g, path);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "read_lines");
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
                       "read_lines", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_disk_format (guestfs_h *g,
                     const char *filename)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "disk_format", 11);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "disk_format", "filename");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "disk_format");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__disk_format (g, filename);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "disk_format");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "disk_format", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_get_libvirt_requested_credentials (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_libvirt_requested_credentials", 33);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_libvirt_requested_credentials");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_libvirt_requested_credentials (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_libvirt_requested_credentials");
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
                       "get_libvirt_requested_credentials", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_sync (guestfs_h *g)
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
                                    "sync", 4);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sync");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sync") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_SYNC, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "sync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SYNC, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sync", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sync",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sync");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_lvs (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_lvs_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvs", 3);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvs");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lvs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LVS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "lvs", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_lvs_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LVS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lvs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_logvols));
  int i;
  for (i = 0; i < ret->n_logvols - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->logvols[i]);
  }
  ret_v[ret->n_logvols - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvs");
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
  guestfs_protobuf_lvs_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_mv (guestfs_h *g,
                const char *src,
                const char *dest)
{
  guestfs_protobuf_aug_mv_args args;
  guestfs_protobuf_aug_mv_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_mv", 6);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_mv", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_mv", "dest");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_mv");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_mv") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_MV,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_mv_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_mv", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_MV, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_mv", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_mv",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_mv");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_vgcreate (guestfs_h *g,
                  const char *volgroup,
                  char *const *physvols)
{
  guestfs_protobuf_vgcreate_args args;
  guestfs_protobuf_vgcreate_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgcreate", 8);
  if (volgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgcreate", "volgroup");
    return -1;
  }
  if (physvols == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgcreate", "physvols");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgcreate");
    fprintf (trace_buffer.fp, " \"%s\"", volgroup);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; physvols[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (physvols[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "vgcreate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  args.volgroup = (char *) volgroup;
  args.physvols = (char **) physvols;
  for (args.n_physvols = 0; physvols[args.n_physvols]; args.n_physvols++) ;
  serial = guestfs___send (g, GUESTFS_PROC_VGCREATE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_vgcreate_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "vgcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_VGCREATE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgcreate", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "vgcreate",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgcreate");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_file (guestfs_h *g,
              const char *path)
{
  guestfs_protobuf_file_args args;
  guestfs_protobuf_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_file_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "file", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "file", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "file", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_file_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->description); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "file");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_file_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_getro (guestfs_h *g,
                        const char *device)
{
  guestfs_protobuf_blockdev_getro_args args;
  guestfs_protobuf_blockdev_getro_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blockdev_getro_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getro", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getro", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_getro");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_getro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETRO,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_getro_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blockdev_getro", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blockdev_getro_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_GETRO, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getro", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_getro",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->ro;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_getro");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_blockdev_getro_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_getbsz (guestfs_h *g,
                         const char *device)
{
  guestfs_protobuf_blockdev_getbsz_args args;
  guestfs_protobuf_blockdev_getbsz_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blockdev_getbsz_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getbsz", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getbsz", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_getbsz");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_getbsz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETBSZ,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_getbsz_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blockdev_getbsz", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blockdev_getbsz_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_GETBSZ, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getbsz", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_getbsz",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->blocksize;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_getbsz");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_blockdev_getbsz_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_setbsz (guestfs_h *g,
                         const char *device,
                         int blocksize)
{
  guestfs_protobuf_blockdev_setbsz_args args;
  guestfs_protobuf_blockdev_setbsz_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_setbsz", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_setbsz", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_setbsz");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", blocksize);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blockdev_setbsz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.blocksize = blocksize;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETBSZ,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blockdev_setbsz_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "blockdev_setbsz", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLOCKDEV_SETBSZ, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_setbsz", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blockdev_setbsz",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_setbsz");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_tar_out_opts_argv (guestfs_h *g,
                           const char *directory,
                           const char *tarfile,
                           const struct guestfs_tar_out_opts_argv *optargs)
{
  struct guestfs_tar_out_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_tar_out_args args;
  guestfs_protobuf_tar_out_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tar_out", 7);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_out_opts", "directory");
    return -1;
  }
  if (tarfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_out_opts", "tarfile");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK) &&
      optargs->compress == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "tar_out_opts", "compress");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK) &&
      optargs->excludes == NULL) {
    error (g, "%s: %s: optional list cannot be NULL",
           "tar_out_opts", "excludes");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "tar_out_opts", "tar_out_opts");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tar_out");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    fprintf (trace_buffer.fp, " \"%s\"", tarfile);
    if (optargs->bitmask & GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "compress", optargs->compress);
    }
    if (optargs->bitmask & GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "numericowner", optargs->numericowner ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:", "excludes");
      for (i = 0; optargs->excludes[i] != NULL; ++i) {
        if (i > 0) fputc (' ', trace_buffer.fp);
        fputs (optargs->excludes[i], trace_buffer.fp);
      }
      fputc ('\"', trace_buffer.fp);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "tar_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  if (optargs->bitmask & GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK) {
    args.compress = (char *) optargs->compress;
  } else {
    args.compress = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK) {
    args.numericowner = optargs->numericowner;
  } else {
    args.numericowner = 0;
  }
  if (optargs->bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK) {
    args.excludes = (char **) optargs->excludes;
    for (args.n_excludes = 0; optargs->excludes[args.n_excludes]; args.n_excludes++) ;
  } else {
    args.n_excludes = 0;
    args.excludes = NULL;
  }
  serial = guestfs___send (g, GUESTFS_PROC_TAR_OUT,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_tar_out_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "tar_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TAR_OUT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tar_out", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "tar_out",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  if (guestfs___recv_file (g, tarfile) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tar_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_vfs (guestfs_h *g,
                   const char *options,
                   const char *vfstype,
                   const char *mountable,
                   const char *mountpoint)
{
  guestfs_protobuf_mount_vfs_args args;
  guestfs_protobuf_mount_vfs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_vfs", 9);
  if (options == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "options");
    return -1;
  }
  if (vfstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "vfstype");
    return -1;
  }
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "mountable");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount_vfs");
    fprintf (trace_buffer.fp, " \"%s\"", options);
    fprintf (trace_buffer.fp, " \"%s\"", vfstype);
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mount_vfs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  args.options = (char *) options;
  args.vfstype = (char *) vfstype;
  args.mountable = (char *) mountable;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_VFS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mount_vfs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mount_vfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MOUNT_VFS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_vfs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mount_vfs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mount_vfs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_sfdisk_kernel_geometry (guestfs_h *g,
                                const char *device)
{
  guestfs_protobuf_sfdisk_kernel_geometry_args args;
  guestfs_protobuf_sfdisk_kernel_geometry_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_sfdisk_kernel_geometry_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sfdisk_kernel_geometry", 22);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_kernel_geometry", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sfdisk_kernel_geometry");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sfdisk_kernel_geometry") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_sfdisk_kernel_geometry_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "sfdisk_kernel_geometry", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_sfdisk_kernel_geometry_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_kernel_geometry", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sfdisk_kernel_geometry",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->partitions); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sfdisk_kernel_geometry");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_sfdisk_kernel_geometry_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_sleep (guestfs_h *g,
               int secs)
{
  guestfs_protobuf_sleep_args args;
  guestfs_protobuf_sleep_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sleep", 5);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sleep");
    fprintf (trace_buffer.fp, " %d", secs);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sleep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  args.secs = secs;
  serial = guestfs___send (g, GUESTFS_PROC_SLEEP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_sleep_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "sleep", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SLEEP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sleep", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sleep",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sleep");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_wc_ll (guestfs_h *g,
               const char *path)
{
  guestfs_protobuf_wc_ll_args args;
  guestfs_protobuf_wc_ll_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_wc_ll_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wc_ll", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wc_ll", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "wc_ll");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "wc_ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ll", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_LL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_wc_ll_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ll", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "wc_ll", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_wc_ll_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ll", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_WC_LL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ll", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_ll", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wc_ll", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "wc_ll",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->lines;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "wc_ll");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_wc_ll_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_head (guestfs_h *g,
              const char *path)
{
  guestfs_protobuf_head_args args;
  guestfs_protobuf_head_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_head_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "head", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "head", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "head");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "head") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEAD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_head_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "head", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_head_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HEAD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "head", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "head",
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
    fprintf (trace_buffer.fp, "%s = ", "head");
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
  guestfs_protobuf_head_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_df (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_df_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "df", 2);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "df");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "df") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_DF, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "df", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_df_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DF, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "df", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "df",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->output); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "df");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_df_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_df_hh (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_df_hh_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "df_hh", 5);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "df_hh");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "df_hh") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_hh", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_DF_HH, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_hh", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "df_hh", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_df_hh_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_hh", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DF_HH, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_hh", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_hh", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "df_hh", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "df_hh",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->output); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "df_hh");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_df_hh_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_loop (guestfs_h *g,
                    const char *file,
                    const char *mountpoint)
{
  guestfs_protobuf_mount_loop_args args;
  guestfs_protobuf_mount_loop_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_loop", 10);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_loop", "file");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_loop", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount_loop");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mount_loop") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  args.file = (char *) file;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_LOOP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mount_loop_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mount_loop", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MOUNT_LOOP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_loop", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mount_loop",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mount_loop");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkswap_opts_argv (guestfs_h *g,
                          const char *device,
                          const struct guestfs_mkswap_opts_argv *optargs)
{
  struct guestfs_mkswap_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_mkswap_args args;
  guestfs_protobuf_mkswap_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkswap", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_opts", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKSWAP_OPTS_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkswap_opts", "label");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKSWAP_OPTS_UUID_BITMASK) &&
      optargs->uuid == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkswap_opts", "uuid");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mkswap_opts", "mkswap_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkswap");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_MKSWAP_OPTS_LABEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "label", optargs->label);
    }
    if (optargs->bitmask & GUESTFS_MKSWAP_OPTS_UUID_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "uuid", optargs->uuid);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mkswap") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_MKSWAP_OPTS_LABEL_BITMASK) {
    args.label = (char *) optargs->label;
  } else {
    args.label = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKSWAP_OPTS_UUID_BITMASK) {
    args.uuid = (char *) optargs->uuid;
  } else {
    args.uuid = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_mkswap_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mkswap", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKSWAP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mkswap",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkswap");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkswap_ll (guestfs_h *g,
                   const char *label,
                   const char *device)
{
  guestfs_protobuf_mkswap_ll_args args;
  guestfs_protobuf_mkswap_ll_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkswap_ll", 9);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_ll", "label");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_ll", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkswap_ll");
    fprintf (trace_buffer.fp, " \"%s\"", label);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mkswap_ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_ll", "-1");
    return -1;
  }

  args.label = (char *) label;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_LL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mkswap_ll_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_ll", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mkswap_ll", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_ll", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKSWAP_LL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_ll", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_ll", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap_ll", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mkswap_ll",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkswap_ll");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkswap_uu (guestfs_h *g,
                   const char *uuid,
                   const char *device)
{
  guestfs_protobuf_mkswap_uu_args args;
  guestfs_protobuf_mkswap_uu_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkswap_uu", 9);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_uu", "uuid");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_uu", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkswap_uu");
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mkswap_uu") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_uu", "-1");
    return -1;
  }

  args.uuid = (char *) uuid;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_UU,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mkswap_uu_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_uu", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mkswap_uu", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_uu", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKSWAP_UU, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_uu", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_uu", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap_uu", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mkswap_uu",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkswap_uu");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mknod_cc (guestfs_h *g,
                  int mode,
                  int devmajor,
                  int devminor,
                  const char *path)
{
  guestfs_protobuf_mknod_cc_args args;
  guestfs_protobuf_mknod_cc_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mknod_cc", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mknod_cc", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mknod_cc");
    fprintf (trace_buffer.fp, " %d", mode);
    fprintf (trace_buffer.fp, " %d", devmajor);
    fprintf (trace_buffer.fp, " %d", devminor);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mknod_cc") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_cc", "-1");
    return -1;
  }

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD_CC,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mknod_cc_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_cc", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mknod_cc", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_cc", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKNOD_CC, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_cc", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_cc", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mknod_cc", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mknod_cc",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mknod_cc");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_removexattr (guestfs_h *g,
                     const char *xattr,
                     const char *path)
{
  guestfs_protobuf_removexattr_args args;
  guestfs_protobuf_removexattr_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "removexattr", 11);
  if (xattr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "removexattr", "xattr");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "removexattr", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "removexattr");
    fprintf (trace_buffer.fp, " \"%s\"", xattr);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "removexattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  args.xattr = (char *) xattr;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_REMOVEXATTR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_removexattr_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "removexattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_REMOVEXATTR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "removexattr", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "removexattr",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "removexattr");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_fgrep (guestfs_h *g,
               const char *pattern,
               const char *path)
{
  guestfs_protobuf_fgrep_args args;
  guestfs_protobuf_fgrep_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_fgrep_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fgrep", 5);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrep", "pattern");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrep", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fgrep");
    fprintf (trace_buffer.fp, " \"%s\"", pattern);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "fgrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FGREP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_fgrep_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "fgrep", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_fgrep_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FGREP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fgrep", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "fgrep",
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
    fprintf (trace_buffer.fp, "%s = ", "fgrep");
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
  guestfs_protobuf_fgrep_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_egrepi (guestfs_h *g,
                const char *regex,
                const char *path)
{
  guestfs_protobuf_egrepi_args args;
  guestfs_protobuf_egrepi_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_egrepi_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "egrepi", 6);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "egrepi");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "egrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EGREPI,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_egrepi_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "egrepi", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_egrepi_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_EGREPI, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "egrepi", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "egrepi",
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
    fprintf (trace_buffer.fp, "%s = ", "egrepi");
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
  guestfs_protobuf_egrepi_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_zegrep (guestfs_h *g,
                const char *regex,
                const char *path)
{
  guestfs_protobuf_zegrep_args args;
  guestfs_protobuf_zegrep_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_zegrep_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zegrep", 6);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zegrep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zegrep", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zegrep");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "zegrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZEGREP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_zegrep_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "zegrep", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_zegrep_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ZEGREP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zegrep", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "zegrep",
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
    fprintf (trace_buffer.fp, "%s = ", "zegrep");
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
  guestfs_protobuf_zegrep_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_fallocate (guestfs_h *g,
                   const char *path,
                   int len)
{
  guestfs_protobuf_fallocate_args args;
  guestfs_protobuf_fallocate_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fallocate", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fallocate", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fallocate");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %d", len);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "fallocate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.len = len;
  serial = guestfs___send (g, GUESTFS_PROC_FALLOCATE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_fallocate_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "fallocate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FALLOCATE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fallocate", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "fallocate",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "fallocate");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_inotify_event_list *
guestfs_inotify_read (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_inotify_read_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_inotify_event_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_read", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inotify_read");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "inotify_read") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_READ, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "inotify_read", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_inotify_read_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INOTIFY_READ, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_read", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "inotify_read",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_inotify_event_list));
  convert_guestfs_int_inotify_event_list_protobuf_to_xdr (ret->events, (guestfs_int_inotify_event_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "inotify_read");
    fprintf (trace_buffer.fp, "<struct guestfs_inotify_event_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_inotify_read_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_vfs_type (guestfs_h *g,
                  const char *mountable)
{
  guestfs_protobuf_vfs_type_args args;
  guestfs_protobuf_vfs_type_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_vfs_type_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vfs_type", 8);
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vfs_type", "mountable");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vfs_type");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "vfs_type") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  args.mountable = (char *) mountable;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_TYPE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_vfs_type_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "vfs_type", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_vfs_type_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_VFS_TYPE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vfs_type", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "vfs_type",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->fstype); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vfs_type");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_vfs_type_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_internal_readlinklist (guestfs_h *g,
                               const char *path,
                               char *const *names)
{
  guestfs_protobuf_internal_readlinklist_args args;
  guestfs_protobuf_internal_readlinklist_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_internal_readlinklist_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_readlinklist", 21);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_readlinklist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_readlinklist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_readlinklist");
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

  if (guestfs___check_appliance_up (g, "internal_readlinklist") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_readlinklist", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.names = (char **) names;
  for (args.n_names = 0; names[args.n_names]; args.n_names++) ;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_READLINKLIST,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_internal_readlinklist_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_readlinklist", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "internal_readlinklist", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_internal_readlinklist_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_readlinklist", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_READLINKLIST, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_readlinklist", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_readlinklist", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_readlinklist", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_readlinklist",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_links));
  int i;
  for (i = 0; i < ret->n_links - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->links[i]);
  }
  ret_v[ret->n_links - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_readlinklist");
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
  guestfs_protobuf_internal_readlinklist_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_fill (guestfs_h *g,
              int c,
              int len,
              const char *path)
{
  guestfs_protobuf_fill_args args;
  guestfs_protobuf_fill_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fill", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fill", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fill");
    fprintf (trace_buffer.fp, " %d", c);
    fprintf (trace_buffer.fp, " %d", len);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "fill") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  args.c = c;
  args.len = len;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_fill_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "fill", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FILL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fill", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "fill",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "fill");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_filesize (guestfs_h *g,
                  const char *file)
{
  guestfs_protobuf_filesize_args args;
  guestfs_protobuf_filesize_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_filesize_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "filesize", 8);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "filesize", "file");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "filesize");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "filesize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_FILESIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_filesize_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "filesize", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_filesize_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FILESIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "filesize", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "filesize",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->size;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "filesize");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_filesize_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_set_mbr_id (guestfs_h *g,
                         const char *device,
                         int partnum,
                         int idbyte)
{
  guestfs_protobuf_part_set_mbr_id_args args;
  guestfs_protobuf_part_set_mbr_id_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_set_mbr_id", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_mbr_id", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_set_mbr_id");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    fprintf (trace_buffer.fp, " %d", idbyte);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_set_mbr_id") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  args.idbyte = idbyte;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_MBR_ID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_set_mbr_id_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "part_set_mbr_id", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_SET_MBR_ID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_mbr_id", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_set_mbr_id",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_set_mbr_id");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_checksums_out (guestfs_h *g,
                       const char *csumtype,
                       const char *directory,
                       const char *sumsfile)
{
  guestfs_protobuf_checksums_out_args args;
  guestfs_protobuf_checksums_out_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "checksums_out", 13);
  if (csumtype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksums_out", "csumtype");
    return -1;
  }
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksums_out", "directory");
    return -1;
  }
  if (sumsfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksums_out", "sumsfile");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "checksums_out");
    fprintf (trace_buffer.fp, " \"%s\"", csumtype);
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    fprintf (trace_buffer.fp, " \"%s\"", sumsfile);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "checksums_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  args.csumtype = (char *) csumtype;
  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUMS_OUT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_checksums_out_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "checksums_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CHECKSUMS_OUT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "checksums_out", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "checksums_out",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  if (guestfs___recv_file (g, sumsfile) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "checksums_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_resize2fs_size (guestfs_h *g,
                        const char *device,
                        int64_t size)
{
  guestfs_protobuf_resize2fs_size_args args;
  guestfs_protobuf_resize2fs_size_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "resize2fs_size", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "resize2fs_size", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "resize2fs_size");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "resize2fs_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS_SIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_resize2fs_size_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "resize2fs_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RESIZE2FS_SIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "resize2fs_size", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "resize2fs_size",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "resize2fs_size");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_pvresize_size (guestfs_h *g,
                       const char *device,
                       int64_t size)
{
  guestfs_protobuf_pvresize_size_args args;
  guestfs_protobuf_pvresize_size_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvresize_size", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvresize_size", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvresize_size");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pvresize_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_PVRESIZE_SIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_pvresize_size_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "pvresize_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PVRESIZE_SIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvresize_size", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pvresize_size",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvresize_size");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_available_all_groups (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_available_all_groups_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "available_all_groups", 20);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "available_all_groups");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "available_all_groups") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_AVAILABLE_ALL_GROUPS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "available_all_groups", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_available_all_groups_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AVAILABLE_ALL_GROUPS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "available_all_groups", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "available_all_groups",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_groups));
  int i;
  for (i = 0; i < ret->n_groups - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->groups[i]);
  }
  ret_v[ret->n_groups - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "available_all_groups");
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
  guestfs_protobuf_available_all_groups_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_fallocate64 (guestfs_h *g,
                     const char *path,
                     int64_t len)
{
  guestfs_protobuf_fallocate64_args args;
  guestfs_protobuf_fallocate64_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fallocate64", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fallocate64", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fallocate64");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %" PRIi64, len);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "fallocate64") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.len = len;
  serial = guestfs___send (g, GUESTFS_PROC_FALLOCATE64,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_fallocate64_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "fallocate64", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FALLOCATE64, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fallocate64", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "fallocate64",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "fallocate64");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lvm_clear_filter (guestfs_h *g)
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
                                    "lvm_clear_filter", 16);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvm_clear_filter");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lvm_clear_filter") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LVM_CLEAR_FILTER, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "lvm_clear_filter", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LVM_CLEAR_FILTER, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_clear_filter", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lvm_clear_filter",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvm_clear_filter");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_luks_format_cipher (guestfs_h *g,
                            const char *device,
                            const char *key,
                            int keyslot,
                            const char *cipher)
{
  guestfs_protobuf_luks_format_cipher_args args;
  guestfs_protobuf_luks_format_cipher_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_format_cipher", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format_cipher", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format_cipher", "key");
    return -1;
  }
  if (cipher == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format_cipher", "cipher");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "luks_format_cipher");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " %d", keyslot);
    fprintf (trace_buffer.fp, " \"%s\"", cipher);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "luks_format_cipher") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.keyslot = keyslot;
  args.cipher = (char *) cipher;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_FORMAT_CIPHER,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_luks_format_cipher_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "luks_format_cipher", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LUKS_FORMAT_CIPHER, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_format_cipher", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "luks_format_cipher",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "luks_format_cipher");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_pread_device (guestfs_h *g,
                      const char *device,
                      int count,
                      int64_t offset,
                      size_t *size_r)
{
  guestfs_protobuf_pread_device_args args;
  guestfs_protobuf_pread_device_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_pread_device_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pread_device", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pread_device", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pread_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", count);
    fprintf (trace_buffer.fp, " %" PRIi64, offset);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pread_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  args.count = count;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PREAD_DEVICE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_pread_device_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "pread_device", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_pread_device_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PREAD_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pread_device", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pread_device",
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
  if (ret->content.len > 0) {
    *size_r = ret->content.len;
    ret_v = safe_memdup (g, ret->content.data, ret->content.len); /* caller will free */
  } else {
    char *p = safe_malloc (g, 1);
    *size_r = ret->content.len;
    ret_v = p;
  }
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pread_device");
    guestfs___print_BufferOut (trace_buffer.fp, ret_v, *size_r);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_pread_device_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_lgetxattr (guestfs_h *g,
                   const char *path,
                   const char *name,
                   size_t *size_r)
{
  guestfs_protobuf_lgetxattr_args args;
  guestfs_protobuf_lgetxattr_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_lgetxattr_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lgetxattr", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lgetxattr", "path");
    return NULL;
  }
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lgetxattr", "name");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lgetxattr");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " \"%s\"", name);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lgetxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_LGETXATTR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lgetxattr_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "lgetxattr", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_lgetxattr_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LGETXATTR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lgetxattr", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lgetxattr",
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
    fprintf (trace_buffer.fp, "%s = ", "lgetxattr");
    guestfs___print_BufferOut (trace_buffer.fp, ret_v, *size_r);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_lgetxattr_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_autosync (guestfs_h *g)
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
                                    "internal_autosync", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_autosync");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "internal_autosync") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_AUTOSYNC, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "internal_autosync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_AUTOSYNC, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_autosync", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_autosync",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_autosync");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount9p_argv (guestfs_h *g,
                      const char *mounttag,
                      const char *mountpoint,
                      const struct guestfs_mount9p_argv *optargs)
{
  struct guestfs_mount9p_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_mount9p_args args;
  guestfs_protobuf_mount9p_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount9p", 7);
  if (mounttag == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount9p", "mounttag");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount9p", "mountpoint");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MOUNT9P_OPTIONS_BITMASK) &&
      optargs->options == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mount9p", "options");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mount9p", "mount9p");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount9p");
    fprintf (trace_buffer.fp, " \"%s\"", mounttag);
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_MOUNT9P_OPTIONS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "options", optargs->options);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mount9p") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount9p", "-1");
    return -1;
  }

  args.mounttag = (char *) mounttag;
  args.mountpoint = (char *) mountpoint;
  if (optargs->bitmask & GUESTFS_MOUNT9P_OPTIONS_BITMASK) {
    args.options = (char *) optargs->options;
  } else {
    args.options = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT9P,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_mount9p_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount9p", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mount9p", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount9p", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MOUNT9P, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount9p", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount9p", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount9p", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mount9p",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mount9p");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_md_detail (guestfs_h *g,
                   const char *md)
{
  guestfs_protobuf_md_detail_args args;
  guestfs_protobuf_md_detail_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_md_detail_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "md_detail", 9);
  if (md == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "md_detail", "md");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "md_detail");
    fprintf (trace_buffer.fp, " \"%s\"", md);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "md_detail") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_detail", "NULL");
    return NULL;
  }

  args.md = (char *) md;
  serial = guestfs___send (g, GUESTFS_PROC_MD_DETAIL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_md_detail_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_detail", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "md_detail", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_md_detail_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_detail", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MD_DETAIL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_detail", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_detail", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "md_detail", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "md_detail",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret_v = safe_malloc (g, sizeof (char *) * (ret->n_info));
  int i;
  for (i = 0; i < ret->n_info - 1; ++i) {
     ret_v[i] = safe_strdup (g, ret->info[i]);
  }
  ret_v[ret->n_info - 1] = NULL;
  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "md_detail");
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
  guestfs_protobuf_md_detail_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_label (guestfs_h *g,
                   const char *mountable,
                   const char *label)
{
  guestfs_protobuf_set_label_args args;
  guestfs_protobuf_set_label_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_label", 9);
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_label", "mountable");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_label", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_label");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "set_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_label", "-1");
    return -1;
  }

  args.mountable = (char *) mountable;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SET_LABEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_set_label_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_label", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "set_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_label", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SET_LABEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_label", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_label", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_label", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "set_label",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_label");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_isoinfo *
guestfs_isoinfo (guestfs_h *g,
                 const char *isofile)
{
  guestfs_protobuf_isoinfo_args args;
  guestfs_protobuf_isoinfo_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_isoinfo_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_isoinfo *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "isoinfo", 7);
  if (isofile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "isoinfo", "isofile");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "isoinfo");
    fprintf (trace_buffer.fp, " \"%s\"", isofile);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "isoinfo") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "isoinfo", "NULL");
    return NULL;
  }

  args.isofile = (char *) isofile;
  serial = guestfs___send (g, GUESTFS_PROC_ISOINFO,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_isoinfo_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "isoinfo", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "isoinfo", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_isoinfo_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "isoinfo", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_ISOINFO, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "isoinfo", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "isoinfo", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "isoinfo", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "isoinfo",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_isoinfo))
;  convert_guestfs_int_isoinfo_protobuf_to_xdr (ret->isodata, (guestfs_int_isoinfo *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "isoinfo");
    fprintf (trace_buffer.fp, "<struct guestfs_isoinfo *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_isoinfo_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_e2generation (guestfs_h *g,
                          const char *file,
                          int64_t generation)
{
  guestfs_protobuf_set_e2generation_args args;
  guestfs_protobuf_set_e2generation_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_e2generation", 16);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2generation", "file");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_e2generation");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    fprintf (trace_buffer.fp, " %" PRIi64, generation);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "set_e2generation") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2generation", "-1");
    return -1;
  }

  args.file = (char *) file;
  args.generation = generation;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2GENERATION,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_set_e2generation_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2generation", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "set_e2generation", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2generation", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SET_E2GENERATION, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2generation", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2generation", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_e2generation", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "set_e2generation",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_e2generation");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_filesystem_available (guestfs_h *g,
                              const char *filesystem)
{
  guestfs_protobuf_filesystem_available_args args;
  guestfs_protobuf_filesystem_available_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_filesystem_available_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "filesystem_available", 20);
  if (filesystem == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "filesystem_available", "filesystem");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "filesystem_available");
    fprintf (trace_buffer.fp, " \"%s\"", filesystem);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "filesystem_available") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesystem_available", "-1");
    return -1;
  }

  args.filesystem = (char *) filesystem;
  serial = guestfs___send (g, GUESTFS_PROC_FILESYSTEM_AVAILABLE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_filesystem_available_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesystem_available", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "filesystem_available", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_filesystem_available_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesystem_available", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FILESYSTEM_AVAILABLE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesystem_available", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesystem_available", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "filesystem_available", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "filesystem_available",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->fsavail;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "filesystem_available");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_filesystem_available_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_pvchange_uuid (guestfs_h *g,
                       const char *device)
{
  guestfs_protobuf_pvchange_uuid_args args;
  guestfs_protobuf_pvchange_uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvchange_uuid", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvchange_uuid", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvchange_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pvchange_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVCHANGE_UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_pvchange_uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "pvchange_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PVCHANGE_UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvchange_uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pvchange_uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvchange_uuid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_pvchange_uuid_all (guestfs_h *g)
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
                                    "pvchange_uuid_all", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvchange_uuid_all");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pvchange_uuid_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid_all", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_PVCHANGE_UUID_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid_all", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "pvchange_uuid_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PVCHANGE_UUID_ALL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid_all", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvchange_uuid_all", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvchange_uuid_all", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pvchange_uuid_all",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvchange_uuid_all");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rsync_out_argv (guestfs_h *g,
                        const char *src,
                        const char *remote,
                        const struct guestfs_rsync_out_argv *optargs)
{
  struct guestfs_rsync_out_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_rsync_out_args args;
  guestfs_protobuf_rsync_out_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rsync_out", 9);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rsync_out", "src");
    return -1;
  }
  if (remote == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rsync_out", "remote");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "rsync_out", "rsync_out");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rsync_out");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", remote);
    if (optargs->bitmask & GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "archive", optargs->archive ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "deletedest", optargs->deletedest ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rsync_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_out", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.remote = (char *) remote;
  if (optargs->bitmask & GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK) {
    args.archive = optargs->archive;
  } else {
    args.archive = 0;
  }
  if (optargs->bitmask & GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK) {
    args.deletedest = optargs->deletedest;
  } else {
    args.deletedest = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_RSYNC_OUT,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_rsync_out_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_out", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rsync_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RSYNC_OUT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_out", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rsync_out", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rsync_out", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rsync_out",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rsync_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_hivex_node_name (guestfs_h *g,
                         int64_t nodeh)
{
  guestfs_protobuf_hivex_node_name_args args;
  guestfs_protobuf_hivex_node_name_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_hivex_node_name_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_name", 15);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_name");
    fprintf (trace_buffer.fp, " %" PRIi64, nodeh);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_name") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_name", "NULL");
    return NULL;
  }

  args.nodeh = nodeh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_NAME,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_hivex_node_name_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_name", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "hivex_node_name", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_hivex_node_name_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_name", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_NODE_NAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_name", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_name", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_name", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_node_name",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->name); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_name");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_hivex_node_name_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_hivex_value_list *
guestfs_hivex_node_values (guestfs_h *g,
                           int64_t nodeh)
{
  guestfs_protobuf_hivex_node_values_args args;
  guestfs_protobuf_hivex_node_values_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_hivex_node_values_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_hivex_value_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_values", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_values");
    fprintf (trace_buffer.fp, " %" PRIi64, nodeh);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_values") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_values", "NULL");
    return NULL;
  }

  args.nodeh = nodeh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_VALUES,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_hivex_node_values_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_values", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "hivex_node_values", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_hivex_node_values_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_values", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_NODE_VALUES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_values", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_values", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_values", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_node_values",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_hivex_value_list));
  convert_guestfs_int_hivex_value_list_protobuf_to_xdr (ret->valuehs, (guestfs_int_hivex_value_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_values");
    fprintf (trace_buffer.fp, "<struct guestfs_hivex_value_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_hivex_node_values_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_mktemp_argv (guestfs_h *g,
                     const char *tmpl,
                     const struct guestfs_mktemp_argv *optargs)
{
  struct guestfs_mktemp_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_mktemp_args args;
  guestfs_protobuf_mktemp_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_mktemp_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mktemp", 6);
  if (tmpl == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mktemp", "tmpl");
    return NULL;
  }
  if ((optargs->bitmask & GUESTFS_MKTEMP_SUFFIX_BITMASK) &&
      optargs->suffix == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mktemp", "suffix");
    return NULL;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mktemp", "mktemp");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mktemp");
    fprintf (trace_buffer.fp, " \"%s\"", tmpl);
    if (optargs->bitmask & GUESTFS_MKTEMP_SUFFIX_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "suffix", optargs->suffix);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mktemp") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mktemp", "NULL");
    return NULL;
  }

  args.tmpl = (char *) tmpl;
  if (optargs->bitmask & GUESTFS_MKTEMP_SUFFIX_BITMASK) {
    args.suffix = (char *) optargs->suffix;
  } else {
    args.suffix = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_MKTEMP,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_mktemp_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mktemp", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "mktemp", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_mktemp_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mktemp", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKTEMP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mktemp", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mktemp", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mktemp", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mktemp",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->path); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mktemp");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_mktemp_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_ldm_partitions (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_list_ldm_partitions_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_ldm_partitions", 19);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_ldm_partitions");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "list_ldm_partitions") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_partitions", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LIST_LDM_PARTITIONS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_partitions", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "list_ldm_partitions", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_list_ldm_partitions_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_partitions", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LIST_LDM_PARTITIONS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_partitions", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_partitions", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_ldm_partitions", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "list_ldm_partitions",
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
    fprintf (trace_buffer.fp, "%s = ", "list_ldm_partitions");
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
  guestfs_protobuf_list_ldm_partitions_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_internal_mountable *
guestfs_internal_parse_mountable (guestfs_h *g,
                                  const char *mountable)
{
  guestfs_protobuf_internal_parse_mountable_args args;
  guestfs_protobuf_internal_parse_mountable_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_internal_parse_mountable_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_internal_mountable *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_parse_mountable", 24);
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_parse_mountable", "mountable");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_parse_mountable");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "internal_parse_mountable") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_parse_mountable", "NULL");
    return NULL;
  }

  args.mountable = (char *) mountable;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_PARSE_MOUNTABLE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_internal_parse_mountable_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_parse_mountable", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "internal_parse_mountable", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_internal_parse_mountable_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_parse_mountable", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_PARSE_MOUNTABLE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_parse_mountable", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_parse_mountable", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_parse_mountable", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_parse_mountable",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_internal_mountable))
;  convert_guestfs_int_internal_mountable_protobuf_to_xdr (ret->mountable, (guestfs_int_internal_mountable *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_parse_mountable");
    fprintf (trace_buffer.fp, "<struct guestfs_internal_mountable *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_internal_parse_mountable_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_cp_rr (guestfs_h *g,
               const char *src,
               const char *dest)
{
  guestfs_protobuf_cp_rr_args args;
  guestfs_protobuf_cp_rr_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cp_rr", 5);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp_rr", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp_rr", "dest");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "cp_rr");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "cp_rr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_rr", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP_RR,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_cp_rr_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_rr", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "cp_rr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_rr", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CP_RR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_rr", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_rr", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cp_rr", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "cp_rr",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "cp_rr");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_remount_argv (guestfs_h *g,
                      const char *mountpoint,
                      const struct guestfs_remount_argv *optargs)
{
  struct guestfs_remount_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_remount_args args;
  guestfs_protobuf_remount_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "remount", 7);
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "remount", "mountpoint");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "remount", "remount");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "remount");
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_REMOUNT_RW_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "rw", optargs->rw ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "remount") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "remount", "-1");
    return -1;
  }

  args.mountpoint = (char *) mountpoint;
  if (optargs->bitmask & GUESTFS_REMOUNT_RW_BITMASK) {
    args.rw = optargs->rw;
  } else {
    args.rw = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_REMOUNT,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_remount_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "remount", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "remount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "remount", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_REMOUNT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "remount", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "remount", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "remount", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "remount",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "remount");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_journal_close (guestfs_h *g)
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
                                    "journal_close", 13);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "journal_close");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "journal_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_close", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_JOURNAL_CLOSE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_close", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "journal_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_close", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_JOURNAL_CLOSE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_close", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "journal_close", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "journal_close", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "journal_close",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "journal_close");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

