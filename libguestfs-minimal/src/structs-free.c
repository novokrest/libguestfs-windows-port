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
#include "guestfs_protocol.pb-c.h"
#include "guestfs_protocol_typedefs.h"

/* Structure-freeing functions.  These rely on the fact that the
 * structure format is identical to the Protobuf format.  See note in
 * generator.ml.
 */

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool (struct guestfs_int_bool *x)
{
  if (x) {
    int_bool__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool_list (struct guestfs_int_bool_list *x)
{
  if (x) {
    int_bool__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv (struct guestfs_lvm_pv *x)
{
  if (x) {
    lvm_pv__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *x)
{
  if (x) {
    lvm_pv__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg (struct guestfs_lvm_vg *x)
{
  if (x) {
    lvm_vg__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *x)
{
  if (x) {
    lvm_vg__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv (struct guestfs_lvm_lv *x)
{
  if (x) {
    lvm_lv__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *x)
{
  if (x) {
    lvm_lv__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat (struct guestfs_stat *x)
{
  if (x) {
    stat__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat_list (struct guestfs_stat_list *x)
{
  if (x) {
    stat__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statns (struct guestfs_statns *x)
{
  if (x) {
    statns__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statns_list (struct guestfs_statns_list *x)
{
  if (x) {
    statns__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs (struct guestfs_statvfs *x)
{
  if (x) {
    statvfs__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs_list (struct guestfs_statvfs_list *x)
{
  if (x) {
    statvfs__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent (struct guestfs_dirent *x)
{
  if (x) {
    dirent__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent_list (struct guestfs_dirent_list *x)
{
  if (x) {
    dirent__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version (struct guestfs_version *x)
{
  if (x) {
    version__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version_list (struct guestfs_version_list *x)
{
  if (x) {
    version__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr (struct guestfs_xattr *x)
{
  if (x) {
    xattr__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr_list (struct guestfs_xattr_list *x)
{
  if (x) {
    xattr__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event (struct guestfs_inotify_event *x)
{
  if (x) {
    inotify_event__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *x)
{
  if (x) {
    inotify_event__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition (struct guestfs_partition *x)
{
  if (x) {
    partition__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition_list (struct guestfs_partition_list *x)
{
  if (x) {
    partition__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application (struct guestfs_application *x)
{
  if (x) {
    application__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application_list (struct guestfs_application_list *x)
{
  if (x) {
    application__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2 (struct guestfs_application2 *x)
{
  if (x) {
    application2__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2_list (struct guestfs_application2_list *x)
{
  if (x) {
    application2__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo (struct guestfs_isoinfo *x)
{
  if (x) {
    isoinfo__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo_list (struct guestfs_isoinfo_list *x)
{
  if (x) {
    isoinfo__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat (struct guestfs_mdstat *x)
{
  if (x) {
    mdstat__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat_list (struct guestfs_mdstat_list *x)
{
  if (x) {
    mdstat__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume (struct guestfs_btrfssubvolume *x)
{
  if (x) {
    btrfssubvolume__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *x)
{
  if (x) {
    btrfssubvolume__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo (struct guestfs_xfsinfo *x)
{
  if (x) {
    xfsinfo__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo_list (struct guestfs_xfsinfo_list *x)
{
  if (x) {
    xfsinfo__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname (struct guestfs_utsname *x)
{
  if (x) {
    utsname__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname_list (struct guestfs_utsname_list *x)
{
  if (x) {
    utsname__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node (struct guestfs_hivex_node *x)
{
  if (x) {
    hivex_node__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node_list (struct guestfs_hivex_node_list *x)
{
  if (x) {
    hivex_node__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value (struct guestfs_hivex_value *x)
{
  if (x) {
    hivex_value__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value_list (struct guestfs_hivex_value_list *x)
{
  if (x) {
    hivex_value__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable (struct guestfs_internal_mountable *x)
{
  if (x) {
    internal_mountable__free_unpacked(x, NULL);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable_list (struct guestfs_internal_mountable_list *x)
{
  if (x) {
    internal_mountable__free_unpacked(x, NULL);
  }
}

