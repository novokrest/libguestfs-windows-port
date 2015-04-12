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

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs_protocol.h"

/* Structure-freeing functions.  These rely on the fact that the
 * structure format is identical to the Protobuf format.  See note in
 * generator.ml.
 */

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool (struct guestfs_int_bool *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool_list (struct guestfs_int_bool_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_int_bool (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv (struct guestfs_lvm_pv *x)
{
  if (x) {
    free (x->pv_name);
    free (x->pv_fmt);
    free (x->pv_attr);
    free (x->pv_tags);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_lvm_pv (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg (struct guestfs_lvm_vg *x)
{
  if (x) {
    free (x->vg_name);
    free (x->vg_fmt);
    free (x->vg_attr);
    free (x->vg_sysid);
    free (x->vg_tags);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_lvm_vg (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv (struct guestfs_lvm_lv *x)
{
  if (x) {
    free (x->lv_name);
    free (x->lv_attr);
    free (x->origin);
    free (x->move_pv);
    free (x->lv_tags);
    free (x->mirror_log);
    free (x->modules);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_lvm_lv (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat (struct guestfs_stat *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat_list (struct guestfs_stat_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_stat (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statns (struct guestfs_statns *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statns_list (struct guestfs_statns_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_statns (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs (struct guestfs_statvfs *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs_list (struct guestfs_statvfs_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_statvfs (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent (struct guestfs_dirent *x)
{
  if (x) {
    free (x->name);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent_list (struct guestfs_dirent_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_dirent (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version (struct guestfs_version *x)
{
  if (x) {
    free (x->extra);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version_list (struct guestfs_version_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_version (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr (struct guestfs_xattr *x)
{
  if (x) {
    free (x->attrname);
    free (x->attrval);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr_list (struct guestfs_xattr_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_xattr (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event (struct guestfs_inotify_event *x)
{
  if (x) {
    free (x->in_name);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_inotify_event (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition (struct guestfs_partition *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition_list (struct guestfs_partition_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_partition (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application (struct guestfs_application *x)
{
  if (x) {
    free (x->app_name);
    free (x->app_display_name);
    free (x->app_version);
    free (x->app_release);
    free (x->app_install_path);
    free (x->app_trans_path);
    free (x->app_publisher);
    free (x->app_url);
    free (x->app_source_package);
    free (x->app_summary);
    free (x->app_description);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application_list (struct guestfs_application_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_application (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2 (struct guestfs_application2 *x)
{
  if (x) {
    free (x->app2_name);
    free (x->app2_display_name);
    free (x->app2_version);
    free (x->app2_release);
    free (x->app2_arch);
    free (x->app2_install_path);
    free (x->app2_trans_path);
    free (x->app2_publisher);
    free (x->app2_url);
    free (x->app2_source_package);
    free (x->app2_summary);
    free (x->app2_description);
    free (x->app2_spare1);
    free (x->app2_spare2);
    free (x->app2_spare3);
    free (x->app2_spare4);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2_list (struct guestfs_application2_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_application2 (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo (struct guestfs_isoinfo *x)
{
  if (x) {
    free (x->iso_system_id);
    free (x->iso_volume_id);
    free (x->iso_volume_set_id);
    free (x->iso_publisher_id);
    free (x->iso_data_preparer_id);
    free (x->iso_application_id);
    free (x->iso_copyright_file_id);
    free (x->iso_abstract_file_id);
    free (x->iso_bibliographic_file_id);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo_list (struct guestfs_isoinfo_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_isoinfo (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat (struct guestfs_mdstat *x)
{
  if (x) {
    free (x->mdstat_device);
    free (x->mdstat_flags);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat_list (struct guestfs_mdstat_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_mdstat (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume (struct guestfs_btrfssubvolume *x)
{
  if (x) {
    free (x->btrfssubvolume_path);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_btrfssubvolume (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo (struct guestfs_xfsinfo *x)
{
  if (x) {
    free (x->xfs_mntpoint);
    free (x->xfs_logname);
    free (x->xfs_rtname);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo_list (struct guestfs_xfsinfo_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_xfsinfo (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname (struct guestfs_utsname *x)
{
  if (x) {
    free (x->uts_sysname);
    free (x->uts_release);
    free (x->uts_version);
    free (x->uts_machine);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname_list (struct guestfs_utsname_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_utsname (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node (struct guestfs_hivex_node *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node_list (struct guestfs_hivex_node_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_hivex_node (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value (struct guestfs_hivex_value *x)
{
  if (x) {
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value_list (struct guestfs_hivex_value_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_hivex_value (&x->val[i]);
    }
    free (x->val);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable (struct guestfs_internal_mountable *x)
{
  if (x) {
    free (x->im_device);
    free (x->im_volume);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable_list (struct guestfs_internal_mountable_list *x)
{
  int i;
  if (x) {
    for (i = 0; i < x->len; ++i) {
      guestfs_free_internal_mountable (&x->val[i]);
    }
    free (x->val);
  }
}

