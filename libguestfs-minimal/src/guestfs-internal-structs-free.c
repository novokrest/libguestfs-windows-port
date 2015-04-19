/* libguestfs generated file -*- c -*-
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

/* This file defines destructors for all guestfs internal structures */

#include "xdr.h"
void
guestfs_int_free_int_bool (guestfs_int_int_bool *s)
{
}

void
guestfs_int_free_int_bool_list (guestfs_int_int_bool_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_int_bool_list_len; ++i) {
    guestfs_int_free_int_bool (&s->guestfs_int_int_bool_list_val[i]);
  }
  free (s->guestfs_int_int_bool_list_val);
}

void
guestfs_int_free_lvm_pv (guestfs_int_lvm_pv *s)
{
  free (s->pv_name);
  free (s->pv_fmt);
  free (s->pv_attr);
  free (s->pv_tags);
}

void
guestfs_int_free_lvm_pv_list (guestfs_int_lvm_pv_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_lvm_pv_list_len; ++i) {
    guestfs_int_free_lvm_pv (&s->guestfs_int_lvm_pv_list_val[i]);
  }
  free (s->guestfs_int_lvm_pv_list_val);
}

void
guestfs_int_free_lvm_vg (guestfs_int_lvm_vg *s)
{
  free (s->vg_name);
  free (s->vg_fmt);
  free (s->vg_attr);
  free (s->vg_sysid);
  free (s->vg_tags);
}

void
guestfs_int_free_lvm_vg_list (guestfs_int_lvm_vg_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_lvm_vg_list_len; ++i) {
    guestfs_int_free_lvm_vg (&s->guestfs_int_lvm_vg_list_val[i]);
  }
  free (s->guestfs_int_lvm_vg_list_val);
}

void
guestfs_int_free_lvm_lv (guestfs_int_lvm_lv *s)
{
  free (s->lv_name);
  free (s->lv_attr);
  free (s->origin);
  free (s->move_pv);
  free (s->lv_tags);
  free (s->mirror_log);
  free (s->modules);
}

void
guestfs_int_free_lvm_lv_list (guestfs_int_lvm_lv_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_lvm_lv_list_len; ++i) {
    guestfs_int_free_lvm_lv (&s->guestfs_int_lvm_lv_list_val[i]);
  }
  free (s->guestfs_int_lvm_lv_list_val);
}

void
guestfs_int_free_stat (guestfs_int_stat *s)
{
}

void
guestfs_int_free_stat_list (guestfs_int_stat_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_stat_list_len; ++i) {
    guestfs_int_free_stat (&s->guestfs_int_stat_list_val[i]);
  }
  free (s->guestfs_int_stat_list_val);
}

void
guestfs_int_free_statns (guestfs_int_statns *s)
{
}

void
guestfs_int_free_statns_list (guestfs_int_statns_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_statns_list_len; ++i) {
    guestfs_int_free_statns (&s->guestfs_int_statns_list_val[i]);
  }
  free (s->guestfs_int_statns_list_val);
}

void
guestfs_int_free_statvfs (guestfs_int_statvfs *s)
{
}

void
guestfs_int_free_statvfs_list (guestfs_int_statvfs_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_statvfs_list_len; ++i) {
    guestfs_int_free_statvfs (&s->guestfs_int_statvfs_list_val[i]);
  }
  free (s->guestfs_int_statvfs_list_val);
}

void
guestfs_int_free_dirent (guestfs_int_dirent *s)
{
  free (s->name);
}

void
guestfs_int_free_dirent_list (guestfs_int_dirent_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_dirent_list_len; ++i) {
    guestfs_int_free_dirent (&s->guestfs_int_dirent_list_val[i]);
  }
  free (s->guestfs_int_dirent_list_val);
}

void
guestfs_int_free_version (guestfs_int_version *s)
{
  free (s->extra);
}

void
guestfs_int_free_version_list (guestfs_int_version_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_version_list_len; ++i) {
    guestfs_int_free_version (&s->guestfs_int_version_list_val[i]);
  }
  free (s->guestfs_int_version_list_val);
}

void
guestfs_int_free_xattr (guestfs_int_xattr *s)
{
  free (s->attrname);
  free (s->attrval.attrval_val);
}

void
guestfs_int_free_xattr_list (guestfs_int_xattr_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_xattr_list_len; ++i) {
    guestfs_int_free_xattr (&s->guestfs_int_xattr_list_val[i]);
  }
  free (s->guestfs_int_xattr_list_val);
}

void
guestfs_int_free_inotify_event (guestfs_int_inotify_event *s)
{
  free (s->in_name);
}

void
guestfs_int_free_inotify_event_list (guestfs_int_inotify_event_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_inotify_event_list_len; ++i) {
    guestfs_int_free_inotify_event (&s->guestfs_int_inotify_event_list_val[i]);
  }
  free (s->guestfs_int_inotify_event_list_val);
}

void
guestfs_int_free_partition (guestfs_int_partition *s)
{
}

void
guestfs_int_free_partition_list (guestfs_int_partition_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_partition_list_len; ++i) {
    guestfs_int_free_partition (&s->guestfs_int_partition_list_val[i]);
  }
  free (s->guestfs_int_partition_list_val);
}

void
guestfs_int_free_application (guestfs_int_application *s)
{
  free (s->app_name);
  free (s->app_display_name);
  free (s->app_version);
  free (s->app_release);
  free (s->app_install_path);
  free (s->app_trans_path);
  free (s->app_publisher);
  free (s->app_url);
  free (s->app_source_package);
  free (s->app_summary);
  free (s->app_description);
}

void
guestfs_int_free_application_list (guestfs_int_application_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_application_list_len; ++i) {
    guestfs_int_free_application (&s->guestfs_int_application_list_val[i]);
  }
  free (s->guestfs_int_application_list_val);
}

void
guestfs_int_free_application2 (guestfs_int_application2 *s)
{
  free (s->app2_name);
  free (s->app2_display_name);
  free (s->app2_version);
  free (s->app2_release);
  free (s->app2_arch);
  free (s->app2_install_path);
  free (s->app2_trans_path);
  free (s->app2_publisher);
  free (s->app2_url);
  free (s->app2_source_package);
  free (s->app2_summary);
  free (s->app2_description);
  free (s->app2_spare1);
  free (s->app2_spare2);
  free (s->app2_spare3);
  free (s->app2_spare4);
}

void
guestfs_int_free_application2_list (guestfs_int_application2_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_application2_list_len; ++i) {
    guestfs_int_free_application2 (&s->guestfs_int_application2_list_val[i]);
  }
  free (s->guestfs_int_application2_list_val);
}

void
guestfs_int_free_isoinfo (guestfs_int_isoinfo *s)
{
  free (s->iso_system_id);
  free (s->iso_volume_id);
  free (s->iso_volume_set_id);
  free (s->iso_publisher_id);
  free (s->iso_data_preparer_id);
  free (s->iso_application_id);
  free (s->iso_copyright_file_id);
  free (s->iso_abstract_file_id);
  free (s->iso_bibliographic_file_id);
}

void
guestfs_int_free_isoinfo_list (guestfs_int_isoinfo_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_isoinfo_list_len; ++i) {
    guestfs_int_free_isoinfo (&s->guestfs_int_isoinfo_list_val[i]);
  }
  free (s->guestfs_int_isoinfo_list_val);
}

void
guestfs_int_free_mdstat (guestfs_int_mdstat *s)
{
  free (s->mdstat_device);
  free (s->mdstat_flags);
}

void
guestfs_int_free_mdstat_list (guestfs_int_mdstat_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_mdstat_list_len; ++i) {
    guestfs_int_free_mdstat (&s->guestfs_int_mdstat_list_val[i]);
  }
  free (s->guestfs_int_mdstat_list_val);
}

void
guestfs_int_free_btrfssubvolume (guestfs_int_btrfssubvolume *s)
{
  free (s->btrfssubvolume_path);
}

void
guestfs_int_free_btrfssubvolume_list (guestfs_int_btrfssubvolume_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_btrfssubvolume_list_len; ++i) {
    guestfs_int_free_btrfssubvolume (&s->guestfs_int_btrfssubvolume_list_val[i]);
  }
  free (s->guestfs_int_btrfssubvolume_list_val);
}

void
guestfs_int_free_xfsinfo (guestfs_int_xfsinfo *s)
{
  free (s->xfs_mntpoint);
  free (s->xfs_logname);
  free (s->xfs_rtname);
}

void
guestfs_int_free_xfsinfo_list (guestfs_int_xfsinfo_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_xfsinfo_list_len; ++i) {
    guestfs_int_free_xfsinfo (&s->guestfs_int_xfsinfo_list_val[i]);
  }
  free (s->guestfs_int_xfsinfo_list_val);
}

void
guestfs_int_free_utsname (guestfs_int_utsname *s)
{
  free (s->uts_sysname);
  free (s->uts_release);
  free (s->uts_version);
  free (s->uts_machine);
}

void
guestfs_int_free_utsname_list (guestfs_int_utsname_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_utsname_list_len; ++i) {
    guestfs_int_free_utsname (&s->guestfs_int_utsname_list_val[i]);
  }
  free (s->guestfs_int_utsname_list_val);
}

void
guestfs_int_free_hivex_node (guestfs_int_hivex_node *s)
{
}

void
guestfs_int_free_hivex_node_list (guestfs_int_hivex_node_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_hivex_node_list_len; ++i) {
    guestfs_int_free_hivex_node (&s->guestfs_int_hivex_node_list_val[i]);
  }
  free (s->guestfs_int_hivex_node_list_val);
}

void
guestfs_int_free_hivex_value (guestfs_int_hivex_value *s)
{
}

void
guestfs_int_free_hivex_value_list (guestfs_int_hivex_value_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_hivex_value_list_len; ++i) {
    guestfs_int_free_hivex_value (&s->guestfs_int_hivex_value_list_val[i]);
  }
  free (s->guestfs_int_hivex_value_list_val);
}

void
guestfs_int_free_internal_mountable (guestfs_int_internal_mountable *s)
{
  free (s->im_device);
  free (s->im_volume);
}

void
guestfs_int_free_internal_mountable_list (guestfs_int_internal_mountable_list *s)
{
  int i;
  for (i = 0; i < s->guestfs_int_internal_mountable_list_len; ++i) {
    guestfs_int_free_internal_mountable (&s->guestfs_int_internal_mountable_list_val[i]);
  }
  free (s->guestfs_int_internal_mountable_list_val);
}

