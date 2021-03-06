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
guestfs_internal_test_rbool (guestfs_h *g,
                             const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rbool", 19);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rbool", "val");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rbool");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rbool (g, val);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rbool");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rbool", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_internal_test_rstringlist (guestfs_h *g,
                                   const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstringlist", 25);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rstringlist", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rstringlist");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rstringlist (g, val);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rstringlist");
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
                       "internal_test_rstringlist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_internal_test_rstringlisterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstringlisterr", 28);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rstringlisterr");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rstringlisterr (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rstringlisterr");
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
                       "internal_test_rstringlisterr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_internal_test_rhashtable (guestfs_h *g,
                                  const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rhashtable", 24);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rhashtable", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rhashtable");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__internal_test_rhashtable (g, val);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rhashtable");
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
                       "internal_test_rhashtable", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_add_cdrom (guestfs_h *g,
                   const char *filename)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "add_cdrom");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_cdrom", 9);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_cdrom", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "add_cdrom");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__add_cdrom (g, filename);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "add_cdrom");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_cdrom", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_autosync (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_autosync", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_autosync");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_autosync (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_autosync");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_autosync", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_ready (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_ready", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_ready");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__is_ready (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "is_ready");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_ready", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_busy (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_busy", 7);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_busy");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__is_busy (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "is_busy");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_busy", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_pid (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_pid", 7);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_pid");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_pid (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_pid");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_pid", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_selinux (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_selinux", 11);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_selinux");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_selinux (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_selinux");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_selinux", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_shared_memory (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_shared_memory", 17);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_shared_memory");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_shared_memory (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_shared_memory");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_shared_memory", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_hostname (guestfs_h *g,
                              const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_hostname", 20);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_hostname", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_hostname");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_hostname (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_hostname");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_hostname", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_format (guestfs_h *g,
                            const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_format", 18);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_format", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_format");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_get_format (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_format");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_format", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_inspect_is_multipart (guestfs_h *g,
                              const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_is_multipart", 20);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_is_multipart", "root");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_is_multipart");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__inspect_is_multipart (g, root);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_is_multipart");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_is_multipart", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_canonical_device_name (guestfs_h *g,
                               const char *device)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "canonical_device_name", 21);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "canonical_device_name", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "canonical_device_name");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__canonical_device_name (g, device);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "canonical_device_name");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "canonical_device_name", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_shutdown (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "shutdown", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "shutdown");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__shutdown (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "shutdown");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "shutdown", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_readlinklist (guestfs_h *g,
                      const char *path,
                      char *const *names)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "readlinklist", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readlinklist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readlinklist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "readlinklist");
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

  r = guestfs__readlinklist (g, path, names);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "readlinklist");
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
                       "readlinklist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_libvirt_requested_credential_challenge (guestfs_h *g,
                                                    int index)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_libvirt_requested_credential_challenge", 42);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_libvirt_requested_credential_challenge");
    fprintf (trace_buffer.fp, " %d", index);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__get_libvirt_requested_credential_challenge (g, index);

  if (r != NULL) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_libvirt_requested_credential_challenge");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_libvirt_requested_credential_challenge", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_cachedir (guestfs_h *g,
                      const char *cachedir)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_cachedir");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_cachedir", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_cachedir");
    if (cachedir)
      fprintf (trace_buffer.fp, " \"%s\"", cachedir);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  r = guestfs__set_cachedir (g, cachedir);

  if (r != -1) {
    if (trace_flag) {
      guestfs___trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_cachedir");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs___trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_cachedir", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_init (guestfs_h *g,
                  const char *root,
                  int flags)
{
  guestfs_protobuf_aug_init_args args;
  guestfs_protobuf_aug_init_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_init", 8);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_init", "root");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_init");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    fprintf (trace_buffer.fp, " %d", flags);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_init") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  args.root = (char *) root;
  args.flags = flags;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_INIT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_init_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_INIT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_init", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_init",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_init");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_set (guestfs_h *g,
                 const char *augpath,
                 const char *val)
{
  guestfs_protobuf_aug_set_args args;
  guestfs_protobuf_aug_set_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_set", 7);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_set", "augpath");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_set", "val");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_set");
    fprintf (trace_buffer.fp, " \"%s\"", augpath);
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_set") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  args.augpath = (char *) augpath;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_SET,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_set_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_set", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_SET, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_set", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_set",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_set");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_insert (guestfs_h *g,
                    const char *augpath,
                    const char *label,
                    int before)
{
  guestfs_protobuf_aug_insert_args args;
  guestfs_protobuf_aug_insert_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_insert", 10);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_insert", "augpath");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_insert", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_insert");
    fprintf (trace_buffer.fp, " \"%s\"", augpath);
    fprintf (trace_buffer.fp, " \"%s\"", label);
    fputs (before ? " true" : " false", trace_buffer.fp);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_insert") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  args.augpath = (char *) augpath;
  args.label = (char *) label;
  args.before = before;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_INSERT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_insert_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_insert", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_INSERT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_insert", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_insert",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_insert");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_rm (guestfs_h *g,
                const char *augpath)
{
  guestfs_protobuf_aug_rm_args args;
  guestfs_protobuf_aug_rm_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_aug_rm_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_rm", 6);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_rm", "augpath");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_rm");
    fprintf (trace_buffer.fp, " \"%s\"", augpath);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_rm") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_RM,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_aug_rm_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "aug_rm", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_aug_rm_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_RM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_rm", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_rm",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->nrnodes;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_rm");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_aug_rm_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_aug_load (guestfs_h *g)
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
                                    "aug_load", 8);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_load");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "aug_load") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_AUG_LOAD, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "aug_load", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_AUG_LOAD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_load", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "aug_load",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_load");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_tgz_out (guestfs_h *g,
                 const char *directory,
                 const char *tarball)
{
  guestfs_protobuf_tgz_out_args args;
  guestfs_protobuf_tgz_out_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tgz_out", 7);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tgz_out", "directory");
    return -1;
  }
  if (tarball == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tgz_out", "tarball");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tgz_out");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    fprintf (trace_buffer.fp, " \"%s\"", tarball);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "tgz_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TGZ_OUT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_tgz_out_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "tgz_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_TGZ_OUT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tgz_out", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "tgz_out",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  if (guestfs___recv_file (g, tarball) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tgz_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_options (guestfs_h *g,
                       const char *options,
                       const char *mountable,
                       const char *mountpoint)
{
  guestfs_protobuf_mount_options_args args;
  guestfs_protobuf_mount_options_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_options", 13);
  if (options == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_options", "options");
    return -1;
  }
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_options", "mountable");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_options", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount_options");
    fprintf (trace_buffer.fp, " \"%s\"", options);
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mount_options") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  args.options = (char *) options;
  args.mountable = (char *) mountable;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_OPTIONS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mount_options_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mount_options", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MOUNT_OPTIONS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_options", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mount_options",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mount_options");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_e2label (guestfs_h *g,
                     const char *device,
                     const char *label)
{
  guestfs_protobuf_set_e2label_args args;
  guestfs_protobuf_set_e2label_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_e2label", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2label", "device");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2label", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_e2label");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "set_e2label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2LABEL,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_set_e2label_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "set_e2label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SET_E2LABEL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_e2label", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "set_e2label",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_e2label");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_e2uuid (guestfs_h *g,
                    const char *device)
{
  guestfs_protobuf_get_e2uuid_args args;
  guestfs_protobuf_get_e2uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_get_e2uuid_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_e2uuid", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_e2uuid", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_e2uuid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "get_e2uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_get_e2uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "get_e2uuid", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_get_e2uuid_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GET_E2UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_e2uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "get_e2uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->uuid); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "get_e2uuid");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_get_e2uuid_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_hexdump (guestfs_h *g,
                 const char *path)
{
  guestfs_protobuf_hexdump_args args;
  guestfs_protobuf_hexdump_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_hexdump_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hexdump", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hexdump", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hexdump");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hexdump") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEXDUMP,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_hexdump_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "hexdump", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_hexdump_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HEXDUMP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hexdump", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hexdump",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->dump); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hexdump");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_hexdump_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lvresize (guestfs_h *g,
                  const char *device,
                  int mbytes)
{
  guestfs_protobuf_lvresize_args args;
  guestfs_protobuf_lvresize_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvresize", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvresize", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvresize");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", mbytes);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lvresize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.mbytes = mbytes;
  serial = guestfs___send (g, GUESTFS_PROC_LVRESIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lvresize_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "lvresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LVRESIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvresize", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lvresize",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvresize");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ntfs3g_probe (guestfs_h *g,
                      int rw,
                      const char *device)
{
  guestfs_protobuf_ntfs3g_probe_args args;
  guestfs_protobuf_ntfs3g_probe_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_ntfs3g_probe_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfs3g_probe", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfs3g_probe", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ntfs3g_probe");
    fputs (rw ? " true" : " false", trace_buffer.fp);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ntfs3g_probe") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs3g_probe", "-1");
    return -1;
  }

  args.rw = rw;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_NTFS3G_PROBE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_ntfs3g_probe_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs3g_probe", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "ntfs3g_probe", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_ntfs3g_probe_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs3g_probe", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_NTFS3G_PROBE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs3g_probe", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs3g_probe", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfs3g_probe", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ntfs3g_probe",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->status;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ntfs3g_probe");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_ntfs3g_probe_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_sh_lines (guestfs_h *g,
                  const char *command)
{
  guestfs_protobuf_sh_lines_args args;
  guestfs_protobuf_sh_lines_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_sh_lines_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sh_lines", 8);
  if (command == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sh_lines", "command");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sh_lines");
    fprintf (trace_buffer.fp, " \"%s\"", command);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "sh_lines") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  args.command = (char *) command;
  serial = guestfs___send (g, GUESTFS_PROC_SH_LINES,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_sh_lines_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "sh_lines", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_sh_lines_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SH_LINES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sh_lines", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "sh_lines",
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
    fprintf (trace_buffer.fp, "%s = ", "sh_lines");
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
  guestfs_protobuf_sh_lines_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_scrub_device (guestfs_h *g,
                      const char *device)
{
  guestfs_protobuf_scrub_device_args args;
  guestfs_protobuf_scrub_device_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "scrub_device", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "scrub_device", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "scrub_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "scrub_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_DEVICE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_scrub_device_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "scrub_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SCRUB_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "scrub_device", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "scrub_device",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "scrub_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_umask (guestfs_h *g,
               int mask)
{
  guestfs_protobuf_umask_args args;
  guestfs_protobuf_umask_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_umask_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "umask", 5);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "umask");
    fprintf (trace_buffer.fp, " %d", mask);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "umask") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  args.mask = mask;
  serial = guestfs___send (g, GUESTFS_PROC_UMASK,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_umask_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "umask", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_umask_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_UMASK, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "umask", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "umask",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->oldmask;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "umask");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_umask_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *
guestfs_lgetxattrs (guestfs_h *g,
                    const char *path)
{
  guestfs_protobuf_lgetxattrs_args args;
  guestfs_protobuf_lgetxattrs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_lgetxattrs_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_xattr_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lgetxattrs", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lgetxattrs", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lgetxattrs");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lgetxattrs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LGETXATTRS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lgetxattrs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "lgetxattrs", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_lgetxattrs_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LGETXATTRS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lgetxattrs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lgetxattrs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_xattr_list));
  convert_guestfs_int_xattr_list_protobuf_to_xdr (ret->xattrs, (guestfs_int_xattr_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lgetxattrs");
    fprintf (trace_buffer.fp, "<struct guestfs_xattr_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_lgetxattrs_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_rmmountpoint (guestfs_h *g,
                      const char *exemptpath)
{
  guestfs_protobuf_rmmountpoint_args args;
  guestfs_protobuf_rmmountpoint_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rmmountpoint", 12);
  if (exemptpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rmmountpoint", "exemptpath");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "rmmountpoint");
    fprintf (trace_buffer.fp, " \"%s\"", exemptpath);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "rmmountpoint") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  args.exemptpath = (char *) exemptpath;
  serial = guestfs___send (g, GUESTFS_PROC_RMMOUNTPOINT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_rmmountpoint_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "rmmountpoint", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RMMOUNTPOINT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rmmountpoint", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "rmmountpoint",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "rmmountpoint");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_grepi (guestfs_h *g,
               const char *regex,
               const char *path)
{
  guestfs_protobuf_grepi_args args;
  guestfs_protobuf_grepi_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_grepi_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "grepi", 5);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grepi", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "grepi");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "grepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GREPI,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_grepi_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "grepi", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_grepi_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_GREPI, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "grepi", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "grepi",
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
    fprintf (trace_buffer.fp, "%s = ", "grepi");
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
  guestfs_protobuf_grepi_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapon_file (guestfs_h *g,
                     const char *file)
{
  guestfs_protobuf_swapon_file_args args;
  guestfs_protobuf_swapon_file_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapon_file", 11);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_file", "file");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapon_file");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "swapon_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_FILE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_swapon_file_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "swapon_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SWAPON_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_file", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "swapon_file",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapon_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mke2fs_jj (guestfs_h *g,
                   const char *fstype,
                   int blocksize,
                   const char *device,
                   const char *journal)
{
  guestfs_protobuf_mke2fs_jj_args args;
  guestfs_protobuf_mke2fs_jj_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs_jj", 9);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_jj", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_jj", "device");
    return -1;
  }
  if (journal == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_jj", "journal");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mke2fs_jj");
    fprintf (trace_buffer.fp, " \"%s\"", fstype);
    fprintf (trace_buffer.fp, " %d", blocksize);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", journal);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "mke2fs_jj") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jj", "-1");
    return -1;
  }

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.journal = (char *) journal;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JJ,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_mke2fs_jj_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jj", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "mke2fs_jj", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jj", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_MKE2FS_JJ, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jj", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_jj", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs_jj", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "mke2fs_jj",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mke2fs_jj");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_case_sensitive_path (guestfs_h *g,
                             const char *path)
{
  guestfs_protobuf_case_sensitive_path_args args;
  guestfs_protobuf_case_sensitive_path_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_case_sensitive_path_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "case_sensitive_path", 19);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "case_sensitive_path", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "case_sensitive_path");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "case_sensitive_path") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CASE_SENSITIVE_PATH,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_case_sensitive_path_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "case_sensitive_path", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_case_sensitive_path_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_CASE_SENSITIVE_PATH, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "case_sensitive_path", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "case_sensitive_path",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->rpath); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "case_sensitive_path");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_case_sensitive_path_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *
guestfs_internal_lxattrlist (guestfs_h *g,
                             const char *path,
                             char *const *names)
{
  guestfs_protobuf_internal_lxattrlist_args args;
  guestfs_protobuf_internal_lxattrlist_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_internal_lxattrlist_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_xattr_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_lxattrlist", 19);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_lxattrlist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_lxattrlist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_lxattrlist");
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

  if (guestfs___check_appliance_up (g, "internal_lxattrlist") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lxattrlist", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.names = (char **) names;
  for (args.n_names = 0; names[args.n_names]; args.n_names++) ;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_LXATTRLIST,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_internal_lxattrlist_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lxattrlist", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "internal_lxattrlist", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_internal_lxattrlist_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lxattrlist", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_LXATTRLIST, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lxattrlist", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lxattrlist", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_lxattrlist", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_lxattrlist",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_xattr_list));
  convert_guestfs_int_xattr_list_protobuf_to_xdr (ret->xattrs, (guestfs_int_xattr_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_lxattrlist");
    fprintf (trace_buffer.fp, "<struct guestfs_xattr_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_internal_lxattrlist_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_init (guestfs_h *g,
                   const char *device,
                   const char *parttype)
{
  guestfs_protobuf_part_init_args args;
  guestfs_protobuf_part_init_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_init", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_init", "device");
    return -1;
  }
  if (parttype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_init", "parttype");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_init");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", parttype);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_init") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.parttype = (char *) parttype;
  serial = guestfs___send (g, GUESTFS_PROC_PART_INIT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_init_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "part_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_INIT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_init", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_init",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_init");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_add (guestfs_h *g,
                  const char *device,
                  const char *prlogex,
                  int64_t startsect,
                  int64_t endsect)
{
  guestfs_protobuf_part_add_args args;
  guestfs_protobuf_part_add_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_add", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_add", "device");
    return -1;
  }
  if (prlogex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_add", "prlogex");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_add");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", prlogex);
    fprintf (trace_buffer.fp, " %" PRIi64, startsect);
    fprintf (trace_buffer.fp, " %" PRIi64, endsect);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_add") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.prlogex = (char *) prlogex;
  args.startsect = startsect;
  args.endsect = endsect;
  serial = guestfs___send (g, GUESTFS_PROC_PART_ADD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_add_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "part_add", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_ADD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_add", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_add",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_add");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lvrename (guestfs_h *g,
                  const char *logvol,
                  const char *newlogvol)
{
  guestfs_protobuf_lvrename_args args;
  guestfs_protobuf_lvrename_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvrename", 8);
  if (logvol == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvrename", "logvol");
    return -1;
  }
  if (newlogvol == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvrename", "newlogvol");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvrename");
    fprintf (trace_buffer.fp, " \"%s\"", logvol);
    fprintf (trace_buffer.fp, " \"%s\"", newlogvol);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lvrename") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  args.logvol = (char *) logvol;
  args.newlogvol = (char *) newlogvol;
  serial = guestfs___send (g, GUESTFS_PROC_LVRENAME,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lvrename_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "lvrename", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LVRENAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvrename", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lvrename",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvrename");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_pvuuid (guestfs_h *g,
                const char *device)
{
  guestfs_protobuf_pvuuid_args args;
  guestfs_protobuf_pvuuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_pvuuid_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvuuid", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvuuid", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvuuid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "pvuuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVUUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_pvuuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "pvuuid", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_pvuuid_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PVUUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvuuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "pvuuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->uuid); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvuuid");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_pvuuid_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_lvuuid (guestfs_h *g,
                const char *device)
{
  guestfs_protobuf_lvuuid_args args;
  guestfs_protobuf_lvuuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_lvuuid_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvuuid", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvuuid", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvuuid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lvuuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LVUUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lvuuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "lvuuid", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_lvuuid_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LVUUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvuuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lvuuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->uuid); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvuuid");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_lvuuid_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_copy_size (guestfs_h *g,
                   const char *src,
                   const char *dest,
                   int64_t size)
{
  guestfs_protobuf_copy_size_args args;
  guestfs_protobuf_copy_size_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "copy_size", 9);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_size", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_size", "dest");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "copy_size");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "copy_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_COPY_SIZE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_copy_size_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "copy_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_COPY_SIZE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_size", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "copy_size",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "copy_size");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_get_mbr_id (guestfs_h *g,
                         const char *device,
                         int partnum)
{
  guestfs_protobuf_part_get_mbr_id_args args;
  guestfs_protobuf_part_get_mbr_id_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_part_get_mbr_id_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_get_mbr_id", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_mbr_id", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_get_mbr_id");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_get_mbr_id") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_MBR_ID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_get_mbr_id_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "part_get_mbr_id", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_part_get_mbr_id_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_GET_MBR_ID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_mbr_id", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_get_mbr_id",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->idbyte;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_get_mbr_id");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_part_get_mbr_id_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_debug_upload (guestfs_h *g,
                      const char *filename,
                      const char *tmpname,
                      int mode)
{
  guestfs_protobuf_debug_upload_args args;
  guestfs_protobuf_debug_upload_args__init (&args);
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
                                    "debug_upload", 12);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug_upload", "filename");
    return -1;
  }
  if (tmpname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug_upload", "tmpname");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "debug_upload");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", tmpname);
    fprintf (trace_buffer.fp, " %d", mode);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs___check_appliance_up (g, "debug_upload") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  args.tmpname = (char *) tmpname;
  args.mode = mode;
  serial = guestfs___send (g, GUESTFS_PROC_DEBUG_UPLOAD,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_debug_upload_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "debug_upload");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "debug_upload", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DEBUG_UPLOAD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "debug_upload", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "debug_upload",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "debug_upload");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_luks_format (guestfs_h *g,
                     const char *device,
                     const char *key,
                     int keyslot)
{
  guestfs_protobuf_luks_format_args args;
  guestfs_protobuf_luks_format_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_format", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format", "key");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "luks_format");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " %d", keyslot);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "luks_format") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.keyslot = keyslot;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_FORMAT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_luks_format_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "luks_format", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LUKS_FORMAT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_format", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "luks_format",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "luks_format");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_findfs_uuid (guestfs_h *g,
                     const char *uuid)
{
  guestfs_protobuf_findfs_uuid_args args;
  guestfs_protobuf_findfs_uuid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_findfs_uuid_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "findfs_uuid", 11);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "findfs_uuid", "uuid");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "findfs_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "findfs_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_FINDFS_UUID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_findfs_uuid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "findfs_uuid", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_findfs_uuid_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FINDFS_UUID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "findfs_uuid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "findfs_uuid",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->device); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "findfs_uuid");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_findfs_uuid_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_download_offset (guestfs_h *g,
                         const char *remotefilename,
                         const char *filename,
                         int64_t offset,
                         int64_t size)
{
  guestfs_protobuf_download_offset_args args;
  guestfs_protobuf_download_offset_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "download_offset", 15);
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download_offset", "remotefilename");
    return -1;
  }
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download_offset", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "download_offset");
    fprintf (trace_buffer.fp, " \"%s\"", remotefilename);
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " %" PRIi64, offset);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "download_offset") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  args.remotefilename = (char *) remotefilename;
  args.offset = offset;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_DOWNLOAD_OFFSET,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_download_offset_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "download_offset", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_DOWNLOAD_OFFSET, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "download_offset", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "download_offset",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  if (guestfs___recv_file (g, filename) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "download_offset");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_lvm_canonical_lv_name (guestfs_h *g,
                               const char *lvname)
{
  guestfs_protobuf_lvm_canonical_lv_name_args args;
  guestfs_protobuf_lvm_canonical_lv_name_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_lvm_canonical_lv_name_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvm_canonical_lv_name", 21);
  if (lvname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvm_canonical_lv_name", "lvname");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvm_canonical_lv_name");
    fprintf (trace_buffer.fp, " \"%s\"", lvname);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "lvm_canonical_lv_name") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  args.lvname = (char *) lvname;
  serial = guestfs___send (g, GUESTFS_PROC_LVM_CANONICAL_LV_NAME,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_lvm_canonical_lv_name_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "lvm_canonical_lv_name", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_lvm_canonical_lv_name_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LVM_CANONICAL_LV_NAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_canonical_lv_name", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "lvm_canonical_lv_name",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->lv); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvm_canonical_lv_name");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_lvm_canonical_lv_name_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_resize2fs_mm (guestfs_h *g,
                      const char *device)
{
  guestfs_protobuf_resize2fs_mm_args args;
  guestfs_protobuf_resize2fs_mm_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "resize2fs_mm", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "resize2fs_mm", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "resize2fs_mm");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "resize2fs_mm") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_mm", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS_MM,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_resize2fs_mm_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_mm", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "resize2fs_mm", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_mm", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_RESIZE2FS_MM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_mm", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_mm", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "resize2fs_mm", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "resize2fs_mm",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "resize2fs_mm");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_dm_devices (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_list_dm_devices_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_dm_devices", 15);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_dm_devices");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "list_dm_devices") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LIST_DM_DEVICES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "list_dm_devices", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_list_dm_devices_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LIST_DM_DEVICES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_dm_devices", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "list_dm_devices",
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
    fprintf (trace_buffer.fp, "%s = ", "list_dm_devices");
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
  guestfs_protobuf_list_dm_devices_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_to_partnum (guestfs_h *g,
                         const char *partition)
{
  guestfs_protobuf_part_to_partnum_args args;
  guestfs_protobuf_part_to_partnum_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_part_to_partnum_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_to_partnum", 15);
  if (partition == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_to_partnum", "partition");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_to_partnum");
    fprintf (trace_buffer.fp, " \"%s\"", partition);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_to_partnum") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  args.partition = (char *) partition;
  serial = guestfs___send (g, GUESTFS_PROC_PART_TO_PARTNUM,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_to_partnum_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "part_to_partnum", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_part_to_partnum_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_TO_PARTNUM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_to_partnum", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_to_partnum",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = ret->partnum;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_to_partnum");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_part_to_partnum_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_blkid (guestfs_h *g,
               const char *device)
{
  guestfs_protobuf_blkid_args args;
  guestfs_protobuf_blkid_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_blkid_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blkid", 5);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blkid", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blkid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "blkid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkid", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLKID,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_blkid_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkid", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "blkid", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_blkid_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BLKID, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkid", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blkid", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blkid", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "blkid",
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
    fprintf (trace_buffer.fp, "%s = ", "blkid");
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
  guestfs_protobuf_blkid_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_wipefs (guestfs_h *g,
                const char *device)
{
  guestfs_protobuf_wipefs_args args;
  guestfs_protobuf_wipefs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wipefs", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wipefs", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "wipefs");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "wipefs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wipefs", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_WIPEFS,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_wipefs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wipefs", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "wipefs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wipefs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_WIPEFS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wipefs", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wipefs", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wipefs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "wipefs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "wipefs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ntfsfix_argv (guestfs_h *g,
                      const char *device,
                      const struct guestfs_ntfsfix_argv *optargs)
{
  struct guestfs_ntfsfix_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_ntfsfix_args args;
  guestfs_protobuf_ntfsfix_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfsfix", 7);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsfix", "device");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "ntfsfix", "ntfsfix");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ntfsfix");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "clearbadsectors", optargs->clearbadsectors ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ntfsfix") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsfix", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK) {
    args.clearbadsectors = optargs->clearbadsectors;
  } else {
    args.clearbadsectors = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_NTFSFIX,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_ntfsfix_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsfix", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "ntfsfix", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsfix", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_NTFSFIX, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsfix", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsfix", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsfix", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ntfsfix",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ntfsfix");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_e2attrs_argv (guestfs_h *g,
                          const char *file,
                          const char *attrs,
                          const struct guestfs_set_e2attrs_argv *optargs)
{
  struct guestfs_set_e2attrs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_set_e2attrs_args args;
  guestfs_protobuf_set_e2attrs_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_e2attrs", 11);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2attrs", "file");
    return -1;
  }
  if (attrs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2attrs", "attrs");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "set_e2attrs", "set_e2attrs");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_e2attrs");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    fprintf (trace_buffer.fp, " \"%s\"", attrs);
    if (optargs->bitmask & GUESTFS_SET_E2ATTRS_CLEAR_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "clear", optargs->clear ? "true" : "false");
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "set_e2attrs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2attrs", "-1");
    return -1;
  }

  args.file = (char *) file;
  args.attrs = (char *) attrs;
  if (optargs->bitmask & GUESTFS_SET_E2ATTRS_CLEAR_BITMASK) {
    args.clear = optargs->clear;
  } else {
    args.clear = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2ATTRS,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_set_e2attrs_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2attrs", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "set_e2attrs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2attrs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_SET_E2ATTRS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2attrs", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2attrs", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_e2attrs", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "set_e2attrs",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_e2attrs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_subvolume_snapshot (guestfs_h *g,
                                  const char *source,
                                  const char *dest)
{
  guestfs_protobuf_btrfs_subvolume_snapshot_args args;
  guestfs_protobuf_btrfs_subvolume_snapshot_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_subvolume_snapshot", 24);
  if (source == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_snapshot", "source");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_snapshot", "dest");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_subvolume_snapshot");
    fprintf (trace_buffer.fp, " \"%s\"", source);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_subvolume_snapshot") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_snapshot", "-1");
    return -1;
  }

  args.source = (char *) source;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_SUBVOLUME_SNAPSHOT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_subvolume_snapshot_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_snapshot", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_subvolume_snapshot", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_snapshot", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_SUBVOLUME_SNAPSHOT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_snapshot", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_snapshot", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_subvolume_snapshot", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_subvolume_snapshot",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_subvolume_snapshot");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_subvolume_create (guestfs_h *g,
                                const char *dest)
{
  guestfs_protobuf_btrfs_subvolume_create_args args;
  guestfs_protobuf_btrfs_subvolume_create_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_subvolume_create", 22);
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_create", "dest");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_subvolume_create");
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_subvolume_create") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_create", "-1");
    return -1;
  }

  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_SUBVOLUME_CREATE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_subvolume_create_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_create", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_subvolume_create", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_create", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_SUBVOLUME_CREATE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_create", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_create", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_subvolume_create", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_subvolume_create",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_subvolume_create");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_subvolume_set_default (guestfs_h *g,
                                     int64_t id,
                                     const char *fs)
{
  guestfs_protobuf_btrfs_subvolume_set_default_args args;
  guestfs_protobuf_btrfs_subvolume_set_default_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_subvolume_set_default", 27);
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_set_default", "fs");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_subvolume_set_default");
    fprintf (trace_buffer.fp, " %" PRIi64, id);
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "btrfs_subvolume_set_default") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_set_default", "-1");
    return -1;
  }

  args.id = id;
  args.fs = (char *) fs;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_SUBVOLUME_SET_DEFAULT,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_btrfs_subvolume_set_default_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_set_default", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "btrfs_subvolume_set_default", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_set_default", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_BTRFS_SUBVOLUME_SET_DEFAULT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_set_default", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_subvolume_set_default", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_subvolume_set_default", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "btrfs_subvolume_set_default",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_subvolume_set_default");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_fstrim_argv (guestfs_h *g,
                     const char *mountpoint,
                     const struct guestfs_fstrim_argv *optargs)
{
  struct guestfs_fstrim_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  guestfs_protobuf_fstrim_args args;
  guestfs_protobuf_fstrim_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fstrim", 6);
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fstrim", "mountpoint");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "fstrim", "fstrim");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fstrim");
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_FSTRIM_OFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "offset", optargs->offset);
    }
    if (optargs->bitmask & GUESTFS_FSTRIM_LENGTH_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "length", optargs->length);
    }
    if (optargs->bitmask & GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "minimumfreeextent", optargs->minimumfreeextent);
    }
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "fstrim") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fstrim", "-1");
    return -1;
  }

  args.mountpoint = (char *) mountpoint;
  if (optargs->bitmask & GUESTFS_FSTRIM_OFFSET_BITMASK) {
    args.offset = optargs->offset;
  } else {
    args.offset = 0;
  }
  if (optargs->bitmask & GUESTFS_FSTRIM_LENGTH_BITMASK) {
    args.length = optargs->length;
  } else {
    args.length = 0;
  }
  if (optargs->bitmask & GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK) {
    args.minimumfreeextent = optargs->minimumfreeextent;
  } else {
    args.minimumfreeextent = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_FSTRIM,
                           progress_hint, optargs->bitmask,
                           (protobuf_proc_pack) guestfs_protobuf_fstrim_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fstrim", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "fstrim", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fstrim", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_FSTRIM, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fstrim", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fstrim", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fstrim", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "fstrim",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "fstrim");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_hivex_node_list *
guestfs_hivex_node_children (guestfs_h *g,
                             int64_t nodeh)
{
  guestfs_protobuf_hivex_node_children_args args;
  guestfs_protobuf_hivex_node_children_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_hivex_node_children_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_hivex_node_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_children", 19);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_children");
    fprintf (trace_buffer.fp, " %" PRIi64, nodeh);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_children") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_children", "NULL");
    return NULL;
  }

  args.nodeh = nodeh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_CHILDREN,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_hivex_node_children_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_children", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "hivex_node_children", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_hivex_node_children_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_children", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_HIVEX_NODE_CHILDREN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_children", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_children", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_children", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "hivex_node_children",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_hivex_node_list));
  convert_guestfs_int_hivex_node_list_protobuf_to_xdr (ret->nodehs, (guestfs_int_hivex_node_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_children");
    fprintf (trace_buffer.fp, "<struct guestfs_hivex_node_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_hivex_node_children_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_hot_remove_drive (guestfs_h *g,
                                   const char *label)
{
  guestfs_protobuf_internal_hot_remove_drive_args args;
  guestfs_protobuf_internal_hot_remove_drive_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_hot_remove_drive", 25);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_hot_remove_drive", "label");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_hot_remove_drive");
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "internal_hot_remove_drive") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive", "-1");
    return -1;
  }

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_internal_hot_remove_drive_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive", "-1");
    return -1;
  }

  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "internal_hot_remove_drive", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_hot_remove_drive", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_hot_remove_drive",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_hot_remove_drive");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_ldm_volumes (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_list_ldm_volumes_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_ldm_volumes", 16);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_ldm_volumes");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "list_ldm_volumes") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_volumes", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LIST_LDM_VOLUMES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_volumes", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "list_ldm_volumes", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_list_ldm_volumes_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_volumes", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LIST_LDM_VOLUMES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_volumes", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_ldm_volumes", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_ldm_volumes", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "list_ldm_volumes",
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
    fprintf (trace_buffer.fp, "%s = ", "list_ldm_volumes");
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
  guestfs_protobuf_list_ldm_volumes_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_ldmtool_scan (guestfs_h *g)
{
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_ldmtool_scan_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_scan", 12);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_scan");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_scan") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_SCAN, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "ldmtool_scan", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_ldmtool_scan_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_LDMTOOL_SCAN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_scan", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_scan", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "ldmtool_scan",
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
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_scan");
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
  guestfs_protobuf_ldmtool_scan_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_rhbz914931 (guestfs_h *g,
                             const char *filename,
                             int count)
{
  guestfs_protobuf_internal_rhbz914931_args args;
  guestfs_protobuf_internal_rhbz914931_args__init (&args);
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
                                    "internal_rhbz914931", 19);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_rhbz914931", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_rhbz914931");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " %d", count);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs___check_appliance_up (g, "internal_rhbz914931") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_rhbz914931", "-1");
    return -1;
  }

  args.count = count;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_RHBZ914931,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_internal_rhbz914931_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_rhbz914931", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_rhbz914931", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "internal_rhbz914931");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  hdr = NULL;
  err = NULL;

  r = guestfs___recv (g, "internal_rhbz914931", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_rhbz914931", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_RHBZ914931, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_rhbz914931", "-1");
    return -1;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_rhbz914931", "-1");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_rhbz914931", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_rhbz914931",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_rhbz914931");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_part_get_name (guestfs_h *g,
                       const char *device,
                       int partnum)
{
  guestfs_protobuf_part_get_name_args args;
  guestfs_protobuf_part_get_name_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_part_get_name_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_get_name", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_name", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_get_name");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  if (guestfs___check_appliance_up (g, "part_get_name") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_name", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_NAME,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_part_get_name_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_name", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "part_get_name", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_part_get_name_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_name", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_PART_GET_NAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_name", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_name", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_name", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "part_get_name",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  ret_v = safe_strdup (g, ret->name); /* caller will free */
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_get_name");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_part_get_name_ret__free_unpacked (ret, NULL);
  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_statns_list *
guestfs_internal_lstatnslist (guestfs_h *g,
                              const char *path,
                              char *const *names)
{
  guestfs_protobuf_internal_lstatnslist_args args;
  guestfs_protobuf_internal_lstatnslist_args__init (&args);
  guestfs_protobuf_message_header *hdr;
  guestfs_protobuf_message_error *err;
  guestfs_protobuf_internal_lstatnslist_ret *ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_statns_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_lstatnslist", 20);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_lstatnslist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_lstatnslist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_lstatnslist");
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

  if (guestfs___check_appliance_up (g, "internal_lstatnslist") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lstatnslist", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.names = (char **) names;
  for (args.n_names = 0; names[args.n_names]; args.n_names++) ;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_LSTATNSLIST,
                           progress_hint, 0,
                           (protobuf_proc_pack) guestfs_protobuf_internal_lstatnslist_args__pack, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lstatnslist", "NULL");
    return NULL;
  }

  hdr = NULL;
  err = NULL;
  ret = NULL;

  r = guestfs___recv (g, "internal_lstatnslist", &hdr, &err,
        (protobuf_proc_unpack) guestfs_protobuf_internal_lstatnslist_ret__unpack, (ProtobufCMessage **) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lstatnslist", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, hdr, GUESTFS_PROC_INTERNAL_LSTATNSLIST, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lstatnslist", "NULL");
    return NULL;
  }

  if (hdr->status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_lstatnslist", "NULL");
    if (err->errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err->errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_lstatnslist", err->error_message);
    else
      guestfs___error_errno (g, errnum, "%s: %s", "internal_lstatnslist",
                           err->error_message);
    guestfs_protobuf_message_error__free_unpacked (err, NULL);
    guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_malloc (g, sizeof (struct guestfs_statns_list));
  convert_guestfs_int_statns_list_protobuf_to_xdr (ret->statbufs, (guestfs_int_statns_list *) ret_v);
  if (trace_flag) {
    guestfs___trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_lstatnslist");
    fprintf (trace_buffer.fp, "<struct guestfs_statns_list *>");
    guestfs___trace_send_line (g, &trace_buffer);
  }

  guestfs_protobuf_message_header__free_unpacked (hdr, NULL);
  guestfs_protobuf_internal_lstatnslist_ret__free_unpacked (ret, NULL);
  return ret_v;
}

