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

#ifndef GUESTFS_PROTOCOL_CONVERTERS_H_
#define GUESTFS_PROTOCOL_CONVERTERS_H_

#include "guestfs.h"
#include "guestfs_protocol.h"
#include "xdr.h"

struct guestfs_int_bool;
struct guestfs_lvm_pv;
struct guestfs_lvm_vg;
struct guestfs_lvm_lv;
struct guestfs_stat;
struct guestfs_statns;
struct guestfs_statvfs;
struct guestfs_dirent;
struct guestfs_version;
struct guestfs_xattr;
struct guestfs_inotify_event;
struct guestfs_partition;
struct guestfs_application;
struct guestfs_application2;
struct guestfs_isoinfo;
struct guestfs_mdstat;
struct guestfs_btrfssubvolume;
struct guestfs_xfsinfo;
struct guestfs_utsname;
struct guestfs_hivex_node;
struct guestfs_hivex_value;
struct guestfs_internal_mountable;
void
convert_guestfs_int_int_bool_xdr_to_protobuf (
                                    guestfs_int_int_bool *xdr,
                                    guestfs_protobuf_int_int_bool *pbc);

void
convert_guestfs_int_int_bool_protobuf_to_xdr (
                                    guestfs_protobuf_int_int_bool *pbc,
                                    guestfs_int_int_bool *xdr);

void
convert_guestfs_int_int_bool_list_xdr_to_protobuf (
                                         guestfs_int_int_bool_list *xdr,
                                         guestfs_protobuf_int_int_bool_list *pbc);

void
convert_guestfs_int_int_bool_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_int_bool_list *pbc,
                                         guestfs_int_int_bool_list *xdr);

void
convert_guestfs_int_lvm_pv_xdr_to_protobuf (
                                    guestfs_int_lvm_pv *xdr,
                                    guestfs_protobuf_int_lvm_pv *pbc);

void
convert_guestfs_int_lvm_pv_protobuf_to_xdr (
                                    guestfs_protobuf_int_lvm_pv *pbc,
                                    guestfs_int_lvm_pv *xdr);

void
convert_guestfs_int_lvm_pv_list_xdr_to_protobuf (
                                         guestfs_int_lvm_pv_list *xdr,
                                         guestfs_protobuf_int_lvm_pv_list *pbc);

void
convert_guestfs_int_lvm_pv_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_lvm_pv_list *pbc,
                                         guestfs_int_lvm_pv_list *xdr);

void
convert_guestfs_int_lvm_vg_xdr_to_protobuf (
                                    guestfs_int_lvm_vg *xdr,
                                    guestfs_protobuf_int_lvm_vg *pbc);

void
convert_guestfs_int_lvm_vg_protobuf_to_xdr (
                                    guestfs_protobuf_int_lvm_vg *pbc,
                                    guestfs_int_lvm_vg *xdr);

void
convert_guestfs_int_lvm_vg_list_xdr_to_protobuf (
                                         guestfs_int_lvm_vg_list *xdr,
                                         guestfs_protobuf_int_lvm_vg_list *pbc);

void
convert_guestfs_int_lvm_vg_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_lvm_vg_list *pbc,
                                         guestfs_int_lvm_vg_list *xdr);

void
convert_guestfs_int_lvm_lv_xdr_to_protobuf (
                                    guestfs_int_lvm_lv *xdr,
                                    guestfs_protobuf_int_lvm_lv *pbc);

void
convert_guestfs_int_lvm_lv_protobuf_to_xdr (
                                    guestfs_protobuf_int_lvm_lv *pbc,
                                    guestfs_int_lvm_lv *xdr);

void
convert_guestfs_int_lvm_lv_list_xdr_to_protobuf (
                                         guestfs_int_lvm_lv_list *xdr,
                                         guestfs_protobuf_int_lvm_lv_list *pbc);

void
convert_guestfs_int_lvm_lv_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_lvm_lv_list *pbc,
                                         guestfs_int_lvm_lv_list *xdr);

void
convert_guestfs_int_stat_xdr_to_protobuf (
                                    guestfs_int_stat *xdr,
                                    guestfs_protobuf_int_stat *pbc);

void
convert_guestfs_int_stat_protobuf_to_xdr (
                                    guestfs_protobuf_int_stat *pbc,
                                    guestfs_int_stat *xdr);

void
convert_guestfs_int_stat_list_xdr_to_protobuf (
                                         guestfs_int_stat_list *xdr,
                                         guestfs_protobuf_int_stat_list *pbc);

void
convert_guestfs_int_stat_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_stat_list *pbc,
                                         guestfs_int_stat_list *xdr);

void
convert_guestfs_int_statns_xdr_to_protobuf (
                                    guestfs_int_statns *xdr,
                                    guestfs_protobuf_int_statns *pbc);

void
convert_guestfs_int_statns_protobuf_to_xdr (
                                    guestfs_protobuf_int_statns *pbc,
                                    guestfs_int_statns *xdr);

void
convert_guestfs_int_statns_list_xdr_to_protobuf (
                                         guestfs_int_statns_list *xdr,
                                         guestfs_protobuf_int_statns_list *pbc);

void
convert_guestfs_int_statns_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_statns_list *pbc,
                                         guestfs_int_statns_list *xdr);

void
convert_guestfs_int_statvfs_xdr_to_protobuf (
                                    guestfs_int_statvfs *xdr,
                                    guestfs_protobuf_int_statvfs *pbc);

void
convert_guestfs_int_statvfs_protobuf_to_xdr (
                                    guestfs_protobuf_int_statvfs *pbc,
                                    guestfs_int_statvfs *xdr);

void
convert_guestfs_int_statvfs_list_xdr_to_protobuf (
                                         guestfs_int_statvfs_list *xdr,
                                         guestfs_protobuf_int_statvfs_list *pbc);

void
convert_guestfs_int_statvfs_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_statvfs_list *pbc,
                                         guestfs_int_statvfs_list *xdr);

void
convert_guestfs_int_dirent_xdr_to_protobuf (
                                    guestfs_int_dirent *xdr,
                                    guestfs_protobuf_int_dirent *pbc);

void
convert_guestfs_int_dirent_protobuf_to_xdr (
                                    guestfs_protobuf_int_dirent *pbc,
                                    guestfs_int_dirent *xdr);

void
convert_guestfs_int_dirent_list_xdr_to_protobuf (
                                         guestfs_int_dirent_list *xdr,
                                         guestfs_protobuf_int_dirent_list *pbc);

void
convert_guestfs_int_dirent_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_dirent_list *pbc,
                                         guestfs_int_dirent_list *xdr);

void
convert_guestfs_int_version_xdr_to_protobuf (
                                    guestfs_int_version *xdr,
                                    guestfs_protobuf_int_version *pbc);

void
convert_guestfs_int_version_protobuf_to_xdr (
                                    guestfs_protobuf_int_version *pbc,
                                    guestfs_int_version *xdr);

void
convert_guestfs_int_version_list_xdr_to_protobuf (
                                         guestfs_int_version_list *xdr,
                                         guestfs_protobuf_int_version_list *pbc);

void
convert_guestfs_int_version_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_version_list *pbc,
                                         guestfs_int_version_list *xdr);

void
convert_guestfs_int_xattr_xdr_to_protobuf (
                                    guestfs_int_xattr *xdr,
                                    guestfs_protobuf_int_xattr *pbc);

void
convert_guestfs_int_xattr_protobuf_to_xdr (
                                    guestfs_protobuf_int_xattr *pbc,
                                    guestfs_int_xattr *xdr);

void
convert_guestfs_int_xattr_list_xdr_to_protobuf (
                                         guestfs_int_xattr_list *xdr,
                                         guestfs_protobuf_int_xattr_list *pbc);

void
convert_guestfs_int_xattr_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_xattr_list *pbc,
                                         guestfs_int_xattr_list *xdr);

void
convert_guestfs_int_inotify_event_xdr_to_protobuf (
                                    guestfs_int_inotify_event *xdr,
                                    guestfs_protobuf_int_inotify_event *pbc);

void
convert_guestfs_int_inotify_event_protobuf_to_xdr (
                                    guestfs_protobuf_int_inotify_event *pbc,
                                    guestfs_int_inotify_event *xdr);

void
convert_guestfs_int_inotify_event_list_xdr_to_protobuf (
                                         guestfs_int_inotify_event_list *xdr,
                                         guestfs_protobuf_int_inotify_event_list *pbc);

void
convert_guestfs_int_inotify_event_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_inotify_event_list *pbc,
                                         guestfs_int_inotify_event_list *xdr);

void
convert_guestfs_int_partition_xdr_to_protobuf (
                                    guestfs_int_partition *xdr,
                                    guestfs_protobuf_int_partition *pbc);

void
convert_guestfs_int_partition_protobuf_to_xdr (
                                    guestfs_protobuf_int_partition *pbc,
                                    guestfs_int_partition *xdr);

void
convert_guestfs_int_partition_list_xdr_to_protobuf (
                                         guestfs_int_partition_list *xdr,
                                         guestfs_protobuf_int_partition_list *pbc);

void
convert_guestfs_int_partition_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_partition_list *pbc,
                                         guestfs_int_partition_list *xdr);

void
convert_guestfs_int_application_xdr_to_protobuf (
                                    guestfs_int_application *xdr,
                                    guestfs_protobuf_int_application *pbc);

void
convert_guestfs_int_application_protobuf_to_xdr (
                                    guestfs_protobuf_int_application *pbc,
                                    guestfs_int_application *xdr);

void
convert_guestfs_int_application_list_xdr_to_protobuf (
                                         guestfs_int_application_list *xdr,
                                         guestfs_protobuf_int_application_list *pbc);

void
convert_guestfs_int_application_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_application_list *pbc,
                                         guestfs_int_application_list *xdr);

void
convert_guestfs_int_application2_xdr_to_protobuf (
                                    guestfs_int_application2 *xdr,
                                    guestfs_protobuf_int_application2 *pbc);

void
convert_guestfs_int_application2_protobuf_to_xdr (
                                    guestfs_protobuf_int_application2 *pbc,
                                    guestfs_int_application2 *xdr);

void
convert_guestfs_int_application2_list_xdr_to_protobuf (
                                         guestfs_int_application2_list *xdr,
                                         guestfs_protobuf_int_application2_list *pbc);

void
convert_guestfs_int_application2_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_application2_list *pbc,
                                         guestfs_int_application2_list *xdr);

void
convert_guestfs_int_isoinfo_xdr_to_protobuf (
                                    guestfs_int_isoinfo *xdr,
                                    guestfs_protobuf_int_isoinfo *pbc);

void
convert_guestfs_int_isoinfo_protobuf_to_xdr (
                                    guestfs_protobuf_int_isoinfo *pbc,
                                    guestfs_int_isoinfo *xdr);

void
convert_guestfs_int_isoinfo_list_xdr_to_protobuf (
                                         guestfs_int_isoinfo_list *xdr,
                                         guestfs_protobuf_int_isoinfo_list *pbc);

void
convert_guestfs_int_isoinfo_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_isoinfo_list *pbc,
                                         guestfs_int_isoinfo_list *xdr);

void
convert_guestfs_int_mdstat_xdr_to_protobuf (
                                    guestfs_int_mdstat *xdr,
                                    guestfs_protobuf_int_mdstat *pbc);

void
convert_guestfs_int_mdstat_protobuf_to_xdr (
                                    guestfs_protobuf_int_mdstat *pbc,
                                    guestfs_int_mdstat *xdr);

void
convert_guestfs_int_mdstat_list_xdr_to_protobuf (
                                         guestfs_int_mdstat_list *xdr,
                                         guestfs_protobuf_int_mdstat_list *pbc);

void
convert_guestfs_int_mdstat_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_mdstat_list *pbc,
                                         guestfs_int_mdstat_list *xdr);

void
convert_guestfs_int_btrfssubvolume_xdr_to_protobuf (
                                    guestfs_int_btrfssubvolume *xdr,
                                    guestfs_protobuf_int_btrfssubvolume *pbc);

void
convert_guestfs_int_btrfssubvolume_protobuf_to_xdr (
                                    guestfs_protobuf_int_btrfssubvolume *pbc,
                                    guestfs_int_btrfssubvolume *xdr);

void
convert_guestfs_int_btrfssubvolume_list_xdr_to_protobuf (
                                         guestfs_int_btrfssubvolume_list *xdr,
                                         guestfs_protobuf_int_btrfssubvolume_list *pbc);

void
convert_guestfs_int_btrfssubvolume_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_btrfssubvolume_list *pbc,
                                         guestfs_int_btrfssubvolume_list *xdr);

void
convert_guestfs_int_xfsinfo_xdr_to_protobuf (
                                    guestfs_int_xfsinfo *xdr,
                                    guestfs_protobuf_int_xfsinfo *pbc);

void
convert_guestfs_int_xfsinfo_protobuf_to_xdr (
                                    guestfs_protobuf_int_xfsinfo *pbc,
                                    guestfs_int_xfsinfo *xdr);

void
convert_guestfs_int_xfsinfo_list_xdr_to_protobuf (
                                         guestfs_int_xfsinfo_list *xdr,
                                         guestfs_protobuf_int_xfsinfo_list *pbc);

void
convert_guestfs_int_xfsinfo_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_xfsinfo_list *pbc,
                                         guestfs_int_xfsinfo_list *xdr);

void
convert_guestfs_int_utsname_xdr_to_protobuf (
                                    guestfs_int_utsname *xdr,
                                    guestfs_protobuf_int_utsname *pbc);

void
convert_guestfs_int_utsname_protobuf_to_xdr (
                                    guestfs_protobuf_int_utsname *pbc,
                                    guestfs_int_utsname *xdr);

void
convert_guestfs_int_utsname_list_xdr_to_protobuf (
                                         guestfs_int_utsname_list *xdr,
                                         guestfs_protobuf_int_utsname_list *pbc);

void
convert_guestfs_int_utsname_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_utsname_list *pbc,
                                         guestfs_int_utsname_list *xdr);

void
convert_guestfs_int_hivex_node_xdr_to_protobuf (
                                    guestfs_int_hivex_node *xdr,
                                    guestfs_protobuf_int_hivex_node *pbc);

void
convert_guestfs_int_hivex_node_protobuf_to_xdr (
                                    guestfs_protobuf_int_hivex_node *pbc,
                                    guestfs_int_hivex_node *xdr);

void
convert_guestfs_int_hivex_node_list_xdr_to_protobuf (
                                         guestfs_int_hivex_node_list *xdr,
                                         guestfs_protobuf_int_hivex_node_list *pbc);

void
convert_guestfs_int_hivex_node_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_hivex_node_list *pbc,
                                         guestfs_int_hivex_node_list *xdr);

void
convert_guestfs_int_hivex_value_xdr_to_protobuf (
                                    guestfs_int_hivex_value *xdr,
                                    guestfs_protobuf_int_hivex_value *pbc);

void
convert_guestfs_int_hivex_value_protobuf_to_xdr (
                                    guestfs_protobuf_int_hivex_value *pbc,
                                    guestfs_int_hivex_value *xdr);

void
convert_guestfs_int_hivex_value_list_xdr_to_protobuf (
                                         guestfs_int_hivex_value_list *xdr,
                                         guestfs_protobuf_int_hivex_value_list *pbc);

void
convert_guestfs_int_hivex_value_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_hivex_value_list *pbc,
                                         guestfs_int_hivex_value_list *xdr);

void
convert_guestfs_int_internal_mountable_xdr_to_protobuf (
                                    guestfs_int_internal_mountable *xdr,
                                    guestfs_protobuf_int_internal_mountable *pbc);

void
convert_guestfs_int_internal_mountable_protobuf_to_xdr (
                                    guestfs_protobuf_int_internal_mountable *pbc,
                                    guestfs_int_internal_mountable *xdr);

void
convert_guestfs_int_internal_mountable_list_xdr_to_protobuf (
                                         guestfs_int_internal_mountable_list *xdr,
                                         guestfs_protobuf_int_internal_mountable_list *pbc);

void
convert_guestfs_int_internal_mountable_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_internal_mountable_list *pbc,
                                         guestfs_int_internal_mountable_list *xdr);

void
convert_mount_args_xdr_to_protobuf (                                 guestfs_mount_args *xdr,
                                 guestfs_protobuf_mount_args *pbc);
void
convert_mount_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_args *pbc,
                                 guestfs_mount_args *xdr);
void
convert_touch_args_xdr_to_protobuf (                                 guestfs_touch_args *xdr,
                                 guestfs_protobuf_touch_args *pbc);
void
convert_touch_args_protobuf_to_xdr (                                 guestfs_protobuf_touch_args *pbc,
                                 guestfs_touch_args *xdr);
void
convert_ll_args_xdr_to_protobuf (                                 guestfs_ll_args *xdr,
                                 guestfs_protobuf_ll_args *pbc);
void
convert_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_ll_args *pbc,
                                 guestfs_ll_args *xdr);
void
convert_ll_ret_xdr_to_protobuf (                                guestfs_ll_ret *xdr,
                                guestfs_protobuf_ll_ret *pbc);
void
convert_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_ll_ret *pbc,
                                guestfs_ll_ret *xdr);
void
convert_list_devices_ret_xdr_to_protobuf (                                guestfs_list_devices_ret *xdr,
                                guestfs_protobuf_list_devices_ret *pbc);
void
convert_list_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_list_devices_ret *pbc,
                                guestfs_list_devices_ret *xdr);
void
convert_list_partitions_ret_xdr_to_protobuf (                                guestfs_list_partitions_ret *xdr,
                                guestfs_protobuf_list_partitions_ret *pbc);
void
convert_list_partitions_ret_protobuf_to_xdr (                                guestfs_protobuf_list_partitions_ret *pbc,
                                guestfs_list_partitions_ret *xdr);
void
convert_pvs_ret_xdr_to_protobuf (                                guestfs_pvs_ret *xdr,
                                guestfs_protobuf_pvs_ret *pbc);
void
convert_pvs_ret_protobuf_to_xdr (                                guestfs_protobuf_pvs_ret *pbc,
                                guestfs_pvs_ret *xdr);
void
convert_vgs_ret_xdr_to_protobuf (                                guestfs_vgs_ret *xdr,
                                guestfs_protobuf_vgs_ret *pbc);
void
convert_vgs_ret_protobuf_to_xdr (                                guestfs_protobuf_vgs_ret *pbc,
                                guestfs_vgs_ret *xdr);
void
convert_lvs_ret_xdr_to_protobuf (                                guestfs_lvs_ret *xdr,
                                guestfs_protobuf_lvs_ret *pbc);
void
convert_lvs_ret_protobuf_to_xdr (                                guestfs_protobuf_lvs_ret *pbc,
                                guestfs_lvs_ret *xdr);
void
convert_pvs_full_ret_xdr_to_protobuf (                                guestfs_pvs_full_ret *xdr,
                                guestfs_protobuf_pvs_full_ret *pbc);
void
convert_pvs_full_ret_protobuf_to_xdr (                                guestfs_protobuf_pvs_full_ret *pbc,
                                guestfs_pvs_full_ret *xdr);
void
convert_vgs_full_ret_xdr_to_protobuf (                                guestfs_vgs_full_ret *xdr,
                                guestfs_protobuf_vgs_full_ret *pbc);
void
convert_vgs_full_ret_protobuf_to_xdr (                                guestfs_protobuf_vgs_full_ret *pbc,
                                guestfs_vgs_full_ret *xdr);
void
convert_lvs_full_ret_xdr_to_protobuf (                                guestfs_lvs_full_ret *xdr,
                                guestfs_protobuf_lvs_full_ret *pbc);
void
convert_lvs_full_ret_protobuf_to_xdr (                                guestfs_protobuf_lvs_full_ret *pbc,
                                guestfs_lvs_full_ret *xdr);
void
convert_aug_init_args_xdr_to_protobuf (                                 guestfs_aug_init_args *xdr,
                                 guestfs_protobuf_aug_init_args *pbc);
void
convert_aug_init_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_init_args *pbc,
                                 guestfs_aug_init_args *xdr);
void
convert_aug_defvar_args_xdr_to_protobuf (                                 guestfs_aug_defvar_args *xdr,
                                 guestfs_protobuf_aug_defvar_args *pbc);
void
convert_aug_defvar_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_defvar_args *pbc,
                                 guestfs_aug_defvar_args *xdr);
void
convert_aug_defvar_ret_xdr_to_protobuf (                                guestfs_aug_defvar_ret *xdr,
                                guestfs_protobuf_aug_defvar_ret *pbc);
void
convert_aug_defvar_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_defvar_ret *pbc,
                                guestfs_aug_defvar_ret *xdr);
void
convert_aug_defnode_args_xdr_to_protobuf (                                 guestfs_aug_defnode_args *xdr,
                                 guestfs_protobuf_aug_defnode_args *pbc);
void
convert_aug_defnode_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_defnode_args *pbc,
                                 guestfs_aug_defnode_args *xdr);
void
convert_aug_defnode_ret_xdr_to_protobuf (                                guestfs_aug_defnode_ret *xdr,
                                guestfs_protobuf_aug_defnode_ret *pbc);
void
convert_aug_defnode_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_defnode_ret *pbc,
                                guestfs_aug_defnode_ret *xdr);
void
convert_aug_get_args_xdr_to_protobuf (                                 guestfs_aug_get_args *xdr,
                                 guestfs_protobuf_aug_get_args *pbc);
void
convert_aug_get_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_get_args *pbc,
                                 guestfs_aug_get_args *xdr);
void
convert_aug_get_ret_xdr_to_protobuf (                                guestfs_aug_get_ret *xdr,
                                guestfs_protobuf_aug_get_ret *pbc);
void
convert_aug_get_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_get_ret *pbc,
                                guestfs_aug_get_ret *xdr);
void
convert_aug_set_args_xdr_to_protobuf (                                 guestfs_aug_set_args *xdr,
                                 guestfs_protobuf_aug_set_args *pbc);
void
convert_aug_set_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_set_args *pbc,
                                 guestfs_aug_set_args *xdr);
void
convert_aug_insert_args_xdr_to_protobuf (                                 guestfs_aug_insert_args *xdr,
                                 guestfs_protobuf_aug_insert_args *pbc);
void
convert_aug_insert_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_insert_args *pbc,
                                 guestfs_aug_insert_args *xdr);
void
convert_aug_rm_args_xdr_to_protobuf (                                 guestfs_aug_rm_args *xdr,
                                 guestfs_protobuf_aug_rm_args *pbc);
void
convert_aug_rm_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_rm_args *pbc,
                                 guestfs_aug_rm_args *xdr);
void
convert_aug_rm_ret_xdr_to_protobuf (                                guestfs_aug_rm_ret *xdr,
                                guestfs_protobuf_aug_rm_ret *pbc);
void
convert_aug_rm_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_rm_ret *pbc,
                                guestfs_aug_rm_ret *xdr);
void
convert_aug_mv_args_xdr_to_protobuf (                                 guestfs_aug_mv_args *xdr,
                                 guestfs_protobuf_aug_mv_args *pbc);
void
convert_aug_mv_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_mv_args *pbc,
                                 guestfs_aug_mv_args *xdr);
void
convert_aug_match_args_xdr_to_protobuf (                                 guestfs_aug_match_args *xdr,
                                 guestfs_protobuf_aug_match_args *pbc);
void
convert_aug_match_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_match_args *pbc,
                                 guestfs_aug_match_args *xdr);
void
convert_aug_match_ret_xdr_to_protobuf (                                guestfs_aug_match_ret *xdr,
                                guestfs_protobuf_aug_match_ret *pbc);
void
convert_aug_match_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_match_ret *pbc,
                                guestfs_aug_match_ret *xdr);
void
convert_aug_ls_args_xdr_to_protobuf (                                 guestfs_aug_ls_args *xdr,
                                 guestfs_protobuf_aug_ls_args *pbc);
void
convert_aug_ls_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_ls_args *pbc,
                                 guestfs_aug_ls_args *xdr);
void
convert_aug_ls_ret_xdr_to_protobuf (                                guestfs_aug_ls_ret *xdr,
                                guestfs_protobuf_aug_ls_ret *pbc);
void
convert_aug_ls_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_ls_ret *pbc,
                                guestfs_aug_ls_ret *xdr);
void
convert_rm_args_xdr_to_protobuf (                                 guestfs_rm_args *xdr,
                                 guestfs_protobuf_rm_args *pbc);
void
convert_rm_args_protobuf_to_xdr (                                 guestfs_protobuf_rm_args *pbc,
                                 guestfs_rm_args *xdr);
void
convert_rmdir_args_xdr_to_protobuf (                                 guestfs_rmdir_args *xdr,
                                 guestfs_protobuf_rmdir_args *pbc);
void
convert_rmdir_args_protobuf_to_xdr (                                 guestfs_protobuf_rmdir_args *pbc,
                                 guestfs_rmdir_args *xdr);
void
convert_rm_rf_args_xdr_to_protobuf (                                 guestfs_rm_rf_args *xdr,
                                 guestfs_protobuf_rm_rf_args *pbc);
void
convert_rm_rf_args_protobuf_to_xdr (                                 guestfs_protobuf_rm_rf_args *pbc,
                                 guestfs_rm_rf_args *xdr);
void
convert_mkdir_args_xdr_to_protobuf (                                 guestfs_mkdir_args *xdr,
                                 guestfs_protobuf_mkdir_args *pbc);
void
convert_mkdir_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdir_args *pbc,
                                 guestfs_mkdir_args *xdr);
void
convert_mkdir_pp_args_xdr_to_protobuf (                                 guestfs_mkdir_pp_args *xdr,
                                 guestfs_protobuf_mkdir_pp_args *pbc);
void
convert_mkdir_pp_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdir_pp_args *pbc,
                                 guestfs_mkdir_pp_args *xdr);
void
convert_chmod_args_xdr_to_protobuf (                                 guestfs_chmod_args *xdr,
                                 guestfs_protobuf_chmod_args *pbc);
void
convert_chmod_args_protobuf_to_xdr (                                 guestfs_protobuf_chmod_args *pbc,
                                 guestfs_chmod_args *xdr);
void
convert_chown_args_xdr_to_protobuf (                                 guestfs_chown_args *xdr,
                                 guestfs_protobuf_chown_args *pbc);
void
convert_chown_args_protobuf_to_xdr (                                 guestfs_protobuf_chown_args *pbc,
                                 guestfs_chown_args *xdr);
void
convert_exists_args_xdr_to_protobuf (                                 guestfs_exists_args *xdr,
                                 guestfs_protobuf_exists_args *pbc);
void
convert_exists_args_protobuf_to_xdr (                                 guestfs_protobuf_exists_args *pbc,
                                 guestfs_exists_args *xdr);
void
convert_exists_ret_xdr_to_protobuf (                                guestfs_exists_ret *xdr,
                                guestfs_protobuf_exists_ret *pbc);
void
convert_exists_ret_protobuf_to_xdr (                                guestfs_protobuf_exists_ret *pbc,
                                guestfs_exists_ret *xdr);
void
convert_is_file_args_xdr_to_protobuf (                                 guestfs_is_file_args *xdr,
                                 guestfs_protobuf_is_file_args *pbc);
void
convert_is_file_args_protobuf_to_xdr (                                 guestfs_protobuf_is_file_args *pbc,
                                 guestfs_is_file_args *xdr);
void
convert_is_file_ret_xdr_to_protobuf (                                guestfs_is_file_ret *xdr,
                                guestfs_protobuf_is_file_ret *pbc);
void
convert_is_file_ret_protobuf_to_xdr (                                guestfs_protobuf_is_file_ret *pbc,
                                guestfs_is_file_ret *xdr);
void
convert_is_dir_args_xdr_to_protobuf (                                 guestfs_is_dir_args *xdr,
                                 guestfs_protobuf_is_dir_args *pbc);
void
convert_is_dir_args_protobuf_to_xdr (                                 guestfs_protobuf_is_dir_args *pbc,
                                 guestfs_is_dir_args *xdr);
void
convert_is_dir_ret_xdr_to_protobuf (                                guestfs_is_dir_ret *xdr,
                                guestfs_protobuf_is_dir_ret *pbc);
void
convert_is_dir_ret_protobuf_to_xdr (                                guestfs_protobuf_is_dir_ret *pbc,
                                guestfs_is_dir_ret *xdr);
void
convert_pvcreate_args_xdr_to_protobuf (                                 guestfs_pvcreate_args *xdr,
                                 guestfs_protobuf_pvcreate_args *pbc);
void
convert_pvcreate_args_protobuf_to_xdr (                                 guestfs_protobuf_pvcreate_args *pbc,
                                 guestfs_pvcreate_args *xdr);
void
convert_vgcreate_args_xdr_to_protobuf (                                 guestfs_vgcreate_args *xdr,
                                 guestfs_protobuf_vgcreate_args *pbc);
void
convert_vgcreate_args_protobuf_to_xdr (                                 guestfs_protobuf_vgcreate_args *pbc,
                                 guestfs_vgcreate_args *xdr);
void
convert_lvcreate_args_xdr_to_protobuf (                                 guestfs_lvcreate_args *xdr,
                                 guestfs_protobuf_lvcreate_args *pbc);
void
convert_lvcreate_args_protobuf_to_xdr (                                 guestfs_protobuf_lvcreate_args *pbc,
                                 guestfs_lvcreate_args *xdr);
void
convert_sfdisk_args_xdr_to_protobuf (                                 guestfs_sfdisk_args *xdr,
                                 guestfs_protobuf_sfdisk_args *pbc);
void
convert_sfdisk_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_args *pbc,
                                 guestfs_sfdisk_args *xdr);
void
convert_write_file_args_xdr_to_protobuf (                                 guestfs_write_file_args *xdr,
                                 guestfs_protobuf_write_file_args *pbc);
void
convert_write_file_args_protobuf_to_xdr (                                 guestfs_protobuf_write_file_args *pbc,
                                 guestfs_write_file_args *xdr);
void
convert_umount_args_xdr_to_protobuf (                                 guestfs_umount_args *xdr,
                                 guestfs_protobuf_umount_args *pbc);
void
convert_umount_args_protobuf_to_xdr (                                 guestfs_protobuf_umount_args *pbc,
                                 guestfs_umount_args *xdr);
void
convert_mounts_ret_xdr_to_protobuf (                                guestfs_mounts_ret *xdr,
                                guestfs_protobuf_mounts_ret *pbc);
void
convert_mounts_ret_protobuf_to_xdr (                                guestfs_protobuf_mounts_ret *pbc,
                                guestfs_mounts_ret *xdr);
void
convert_file_args_xdr_to_protobuf (                                 guestfs_file_args *xdr,
                                 guestfs_protobuf_file_args *pbc);
void
convert_file_args_protobuf_to_xdr (                                 guestfs_protobuf_file_args *pbc,
                                 guestfs_file_args *xdr);
void
convert_file_ret_xdr_to_protobuf (                                guestfs_file_ret *xdr,
                                guestfs_protobuf_file_ret *pbc);
void
convert_file_ret_protobuf_to_xdr (                                guestfs_protobuf_file_ret *pbc,
                                guestfs_file_ret *xdr);
void
convert_command_args_xdr_to_protobuf (                                 guestfs_command_args *xdr,
                                 guestfs_protobuf_command_args *pbc);
void
convert_command_args_protobuf_to_xdr (                                 guestfs_protobuf_command_args *pbc,
                                 guestfs_command_args *xdr);
void
convert_command_ret_xdr_to_protobuf (                                guestfs_command_ret *xdr,
                                guestfs_protobuf_command_ret *pbc);
void
convert_command_ret_protobuf_to_xdr (                                guestfs_protobuf_command_ret *pbc,
                                guestfs_command_ret *xdr);
void
convert_command_lines_args_xdr_to_protobuf (                                 guestfs_command_lines_args *xdr,
                                 guestfs_protobuf_command_lines_args *pbc);
void
convert_command_lines_args_protobuf_to_xdr (                                 guestfs_protobuf_command_lines_args *pbc,
                                 guestfs_command_lines_args *xdr);
void
convert_command_lines_ret_xdr_to_protobuf (                                guestfs_command_lines_ret *xdr,
                                guestfs_protobuf_command_lines_ret *pbc);
void
convert_command_lines_ret_protobuf_to_xdr (                                guestfs_protobuf_command_lines_ret *pbc,
                                guestfs_command_lines_ret *xdr);
void
convert_statvfs_args_xdr_to_protobuf (                                 guestfs_statvfs_args *xdr,
                                 guestfs_protobuf_statvfs_args *pbc);
void
convert_statvfs_args_protobuf_to_xdr (                                 guestfs_protobuf_statvfs_args *pbc,
                                 guestfs_statvfs_args *xdr);
void
convert_statvfs_ret_xdr_to_protobuf (                                guestfs_statvfs_ret *xdr,
                                guestfs_protobuf_statvfs_ret *pbc);
void
convert_statvfs_ret_protobuf_to_xdr (                                guestfs_protobuf_statvfs_ret *pbc,
                                guestfs_statvfs_ret *xdr);
void
convert_tune2fs_ll_args_xdr_to_protobuf (                                 guestfs_tune2fs_ll_args *xdr,
                                 guestfs_protobuf_tune2fs_ll_args *pbc);
void
convert_tune2fs_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_tune2fs_ll_args *pbc,
                                 guestfs_tune2fs_ll_args *xdr);
void
convert_tune2fs_ll_ret_xdr_to_protobuf (                                guestfs_tune2fs_ll_ret *xdr,
                                guestfs_protobuf_tune2fs_ll_ret *pbc);
void
convert_tune2fs_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_tune2fs_ll_ret *pbc,
                                guestfs_tune2fs_ll_ret *xdr);
void
convert_blockdev_setro_args_xdr_to_protobuf (                                 guestfs_blockdev_setro_args *xdr,
                                 guestfs_protobuf_blockdev_setro_args *pbc);
void
convert_blockdev_setro_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_setro_args *pbc,
                                 guestfs_blockdev_setro_args *xdr);
void
convert_blockdev_setrw_args_xdr_to_protobuf (                                 guestfs_blockdev_setrw_args *xdr,
                                 guestfs_protobuf_blockdev_setrw_args *pbc);
void
convert_blockdev_setrw_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_setrw_args *pbc,
                                 guestfs_blockdev_setrw_args *xdr);
void
convert_blockdev_getro_args_xdr_to_protobuf (                                 guestfs_blockdev_getro_args *xdr,
                                 guestfs_protobuf_blockdev_getro_args *pbc);
void
convert_blockdev_getro_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getro_args *pbc,
                                 guestfs_blockdev_getro_args *xdr);
void
convert_blockdev_getro_ret_xdr_to_protobuf (                                guestfs_blockdev_getro_ret *xdr,
                                guestfs_protobuf_blockdev_getro_ret *pbc);
void
convert_blockdev_getro_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getro_ret *pbc,
                                guestfs_blockdev_getro_ret *xdr);
void
convert_blockdev_getss_args_xdr_to_protobuf (                                 guestfs_blockdev_getss_args *xdr,
                                 guestfs_protobuf_blockdev_getss_args *pbc);
void
convert_blockdev_getss_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getss_args *pbc,
                                 guestfs_blockdev_getss_args *xdr);
void
convert_blockdev_getss_ret_xdr_to_protobuf (                                guestfs_blockdev_getss_ret *xdr,
                                guestfs_protobuf_blockdev_getss_ret *pbc);
void
convert_blockdev_getss_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getss_ret *pbc,
                                guestfs_blockdev_getss_ret *xdr);
void
convert_blockdev_getbsz_args_xdr_to_protobuf (                                 guestfs_blockdev_getbsz_args *xdr,
                                 guestfs_protobuf_blockdev_getbsz_args *pbc);
void
convert_blockdev_getbsz_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getbsz_args *pbc,
                                 guestfs_blockdev_getbsz_args *xdr);
void
convert_blockdev_getbsz_ret_xdr_to_protobuf (                                guestfs_blockdev_getbsz_ret *xdr,
                                guestfs_protobuf_blockdev_getbsz_ret *pbc);
void
convert_blockdev_getbsz_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getbsz_ret *pbc,
                                guestfs_blockdev_getbsz_ret *xdr);
void
convert_blockdev_setbsz_args_xdr_to_protobuf (                                 guestfs_blockdev_setbsz_args *xdr,
                                 guestfs_protobuf_blockdev_setbsz_args *pbc);
void
convert_blockdev_setbsz_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_setbsz_args *pbc,
                                 guestfs_blockdev_setbsz_args *xdr);
void
convert_blockdev_getsz_args_xdr_to_protobuf (                                 guestfs_blockdev_getsz_args *xdr,
                                 guestfs_protobuf_blockdev_getsz_args *pbc);
void
convert_blockdev_getsz_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getsz_args *pbc,
                                 guestfs_blockdev_getsz_args *xdr);
void
convert_blockdev_getsz_ret_xdr_to_protobuf (                                guestfs_blockdev_getsz_ret *xdr,
                                guestfs_protobuf_blockdev_getsz_ret *pbc);
void
convert_blockdev_getsz_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getsz_ret *pbc,
                                guestfs_blockdev_getsz_ret *xdr);
void
convert_blockdev_getsize64_args_xdr_to_protobuf (                                 guestfs_blockdev_getsize64_args *xdr,
                                 guestfs_protobuf_blockdev_getsize64_args *pbc);
void
convert_blockdev_getsize64_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getsize64_args *pbc,
                                 guestfs_blockdev_getsize64_args *xdr);
void
convert_blockdev_getsize64_ret_xdr_to_protobuf (                                guestfs_blockdev_getsize64_ret *xdr,
                                guestfs_protobuf_blockdev_getsize64_ret *pbc);
void
convert_blockdev_getsize64_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getsize64_ret *pbc,
                                guestfs_blockdev_getsize64_ret *xdr);
void
convert_blockdev_flushbufs_args_xdr_to_protobuf (                                 guestfs_blockdev_flushbufs_args *xdr,
                                 guestfs_protobuf_blockdev_flushbufs_args *pbc);
void
convert_blockdev_flushbufs_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_flushbufs_args *pbc,
                                 guestfs_blockdev_flushbufs_args *xdr);
void
convert_blockdev_rereadpt_args_xdr_to_protobuf (                                 guestfs_blockdev_rereadpt_args *xdr,
                                 guestfs_protobuf_blockdev_rereadpt_args *pbc);
void
convert_blockdev_rereadpt_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_rereadpt_args *pbc,
                                 guestfs_blockdev_rereadpt_args *xdr);
void
convert_upload_args_xdr_to_protobuf (                                 guestfs_upload_args *xdr,
                                 guestfs_protobuf_upload_args *pbc);
void
convert_upload_args_protobuf_to_xdr (                                 guestfs_protobuf_upload_args *pbc,
                                 guestfs_upload_args *xdr);
void
convert_download_args_xdr_to_protobuf (                                 guestfs_download_args *xdr,
                                 guestfs_protobuf_download_args *pbc);
void
convert_download_args_protobuf_to_xdr (                                 guestfs_protobuf_download_args *pbc,
                                 guestfs_download_args *xdr);
void
convert_checksum_args_xdr_to_protobuf (                                 guestfs_checksum_args *xdr,
                                 guestfs_protobuf_checksum_args *pbc);
void
convert_checksum_args_protobuf_to_xdr (                                 guestfs_protobuf_checksum_args *pbc,
                                 guestfs_checksum_args *xdr);
void
convert_checksum_ret_xdr_to_protobuf (                                guestfs_checksum_ret *xdr,
                                guestfs_protobuf_checksum_ret *pbc);
void
convert_checksum_ret_protobuf_to_xdr (                                guestfs_protobuf_checksum_ret *pbc,
                                guestfs_checksum_ret *xdr);
void
convert_tar_in_args_xdr_to_protobuf (                                 guestfs_tar_in_args *xdr,
                                 guestfs_protobuf_tar_in_args *pbc);
void
convert_tar_in_args_protobuf_to_xdr (                                 guestfs_protobuf_tar_in_args *pbc,
                                 guestfs_tar_in_args *xdr);
void
convert_tar_out_args_xdr_to_protobuf (                                 guestfs_tar_out_args *xdr,
                                 guestfs_protobuf_tar_out_args *pbc);
void
convert_tar_out_args_protobuf_to_xdr (                                 guestfs_protobuf_tar_out_args *pbc,
                                 guestfs_tar_out_args *xdr);
void
convert_tgz_in_args_xdr_to_protobuf (                                 guestfs_tgz_in_args *xdr,
                                 guestfs_protobuf_tgz_in_args *pbc);
void
convert_tgz_in_args_protobuf_to_xdr (                                 guestfs_protobuf_tgz_in_args *pbc,
                                 guestfs_tgz_in_args *xdr);
void
convert_tgz_out_args_xdr_to_protobuf (                                 guestfs_tgz_out_args *xdr,
                                 guestfs_protobuf_tgz_out_args *pbc);
void
convert_tgz_out_args_protobuf_to_xdr (                                 guestfs_protobuf_tgz_out_args *pbc,
                                 guestfs_tgz_out_args *xdr);
void
convert_mount_ro_args_xdr_to_protobuf (                                 guestfs_mount_ro_args *xdr,
                                 guestfs_protobuf_mount_ro_args *pbc);
void
convert_mount_ro_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_ro_args *pbc,
                                 guestfs_mount_ro_args *xdr);
void
convert_mount_options_args_xdr_to_protobuf (                                 guestfs_mount_options_args *xdr,
                                 guestfs_protobuf_mount_options_args *pbc);
void
convert_mount_options_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_options_args *pbc,
                                 guestfs_mount_options_args *xdr);
void
convert_mount_vfs_args_xdr_to_protobuf (                                 guestfs_mount_vfs_args *xdr,
                                 guestfs_protobuf_mount_vfs_args *pbc);
void
convert_mount_vfs_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_vfs_args *pbc,
                                 guestfs_mount_vfs_args *xdr);
void
convert_debug_args_xdr_to_protobuf (                                 guestfs_debug_args *xdr,
                                 guestfs_protobuf_debug_args *pbc);
void
convert_debug_args_protobuf_to_xdr (                                 guestfs_protobuf_debug_args *pbc,
                                 guestfs_debug_args *xdr);
void
convert_debug_ret_xdr_to_protobuf (                                guestfs_debug_ret *xdr,
                                guestfs_protobuf_debug_ret *pbc);
void
convert_debug_ret_protobuf_to_xdr (                                guestfs_protobuf_debug_ret *pbc,
                                guestfs_debug_ret *xdr);
void
convert_lvremove_args_xdr_to_protobuf (                                 guestfs_lvremove_args *xdr,
                                 guestfs_protobuf_lvremove_args *pbc);
void
convert_lvremove_args_protobuf_to_xdr (                                 guestfs_protobuf_lvremove_args *pbc,
                                 guestfs_lvremove_args *xdr);
void
convert_vgremove_args_xdr_to_protobuf (                                 guestfs_vgremove_args *xdr,
                                 guestfs_protobuf_vgremove_args *pbc);
void
convert_vgremove_args_protobuf_to_xdr (                                 guestfs_protobuf_vgremove_args *pbc,
                                 guestfs_vgremove_args *xdr);
void
convert_pvremove_args_xdr_to_protobuf (                                 guestfs_pvremove_args *xdr,
                                 guestfs_protobuf_pvremove_args *pbc);
void
convert_pvremove_args_protobuf_to_xdr (                                 guestfs_protobuf_pvremove_args *pbc,
                                 guestfs_pvremove_args *xdr);
void
convert_set_e2label_args_xdr_to_protobuf (                                 guestfs_set_e2label_args *xdr,
                                 guestfs_protobuf_set_e2label_args *pbc);
void
convert_set_e2label_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2label_args *pbc,
                                 guestfs_set_e2label_args *xdr);
void
convert_get_e2label_args_xdr_to_protobuf (                                 guestfs_get_e2label_args *xdr,
                                 guestfs_protobuf_get_e2label_args *pbc);
void
convert_get_e2label_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2label_args *pbc,
                                 guestfs_get_e2label_args *xdr);
void
convert_get_e2label_ret_xdr_to_protobuf (                                guestfs_get_e2label_ret *xdr,
                                guestfs_protobuf_get_e2label_ret *pbc);
void
convert_get_e2label_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2label_ret *pbc,
                                guestfs_get_e2label_ret *xdr);
void
convert_set_e2uuid_args_xdr_to_protobuf (                                 guestfs_set_e2uuid_args *xdr,
                                 guestfs_protobuf_set_e2uuid_args *pbc);
void
convert_set_e2uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2uuid_args *pbc,
                                 guestfs_set_e2uuid_args *xdr);
void
convert_get_e2uuid_args_xdr_to_protobuf (                                 guestfs_get_e2uuid_args *xdr,
                                 guestfs_protobuf_get_e2uuid_args *pbc);
void
convert_get_e2uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2uuid_args *pbc,
                                 guestfs_get_e2uuid_args *xdr);
void
convert_get_e2uuid_ret_xdr_to_protobuf (                                guestfs_get_e2uuid_ret *xdr,
                                guestfs_protobuf_get_e2uuid_ret *pbc);
void
convert_get_e2uuid_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2uuid_ret *pbc,
                                guestfs_get_e2uuid_ret *xdr);
void
convert_fsck_args_xdr_to_protobuf (                                 guestfs_fsck_args *xdr,
                                 guestfs_protobuf_fsck_args *pbc);
void
convert_fsck_args_protobuf_to_xdr (                                 guestfs_protobuf_fsck_args *pbc,
                                 guestfs_fsck_args *xdr);
void
convert_fsck_ret_xdr_to_protobuf (                                guestfs_fsck_ret *xdr,
                                guestfs_protobuf_fsck_ret *pbc);
void
convert_fsck_ret_protobuf_to_xdr (                                guestfs_protobuf_fsck_ret *pbc,
                                guestfs_fsck_ret *xdr);
void
convert_zero_args_xdr_to_protobuf (                                 guestfs_zero_args *xdr,
                                 guestfs_protobuf_zero_args *pbc);
void
convert_zero_args_protobuf_to_xdr (                                 guestfs_protobuf_zero_args *pbc,
                                 guestfs_zero_args *xdr);
void
convert_grub_install_args_xdr_to_protobuf (                                 guestfs_grub_install_args *xdr,
                                 guestfs_protobuf_grub_install_args *pbc);
void
convert_grub_install_args_protobuf_to_xdr (                                 guestfs_protobuf_grub_install_args *pbc,
                                 guestfs_grub_install_args *xdr);
void
convert_cp_args_xdr_to_protobuf (                                 guestfs_cp_args *xdr,
                                 guestfs_protobuf_cp_args *pbc);
void
convert_cp_args_protobuf_to_xdr (                                 guestfs_protobuf_cp_args *pbc,
                                 guestfs_cp_args *xdr);
void
convert_cp_aa_args_xdr_to_protobuf (                                 guestfs_cp_aa_args *xdr,
                                 guestfs_protobuf_cp_aa_args *pbc);
void
convert_cp_aa_args_protobuf_to_xdr (                                 guestfs_protobuf_cp_aa_args *pbc,
                                 guestfs_cp_aa_args *xdr);
void
convert_mv_args_xdr_to_protobuf (                                 guestfs_mv_args *xdr,
                                 guestfs_protobuf_mv_args *pbc);
void
convert_mv_args_protobuf_to_xdr (                                 guestfs_protobuf_mv_args *pbc,
                                 guestfs_mv_args *xdr);
void
convert_drop_caches_args_xdr_to_protobuf (                                 guestfs_drop_caches_args *xdr,
                                 guestfs_protobuf_drop_caches_args *pbc);
void
convert_drop_caches_args_protobuf_to_xdr (                                 guestfs_protobuf_drop_caches_args *pbc,
                                 guestfs_drop_caches_args *xdr);
void
convert_dmesg_ret_xdr_to_protobuf (                                guestfs_dmesg_ret *xdr,
                                guestfs_protobuf_dmesg_ret *pbc);
void
convert_dmesg_ret_protobuf_to_xdr (                                guestfs_protobuf_dmesg_ret *pbc,
                                guestfs_dmesg_ret *xdr);
void
convert_equal_args_xdr_to_protobuf (                                 guestfs_equal_args *xdr,
                                 guestfs_protobuf_equal_args *pbc);
void
convert_equal_args_protobuf_to_xdr (                                 guestfs_protobuf_equal_args *pbc,
                                 guestfs_equal_args *xdr);
void
convert_equal_ret_xdr_to_protobuf (                                guestfs_equal_ret *xdr,
                                guestfs_protobuf_equal_ret *pbc);
void
convert_equal_ret_protobuf_to_xdr (                                guestfs_protobuf_equal_ret *pbc,
                                guestfs_equal_ret *xdr);
void
convert_strings_args_xdr_to_protobuf (                                 guestfs_strings_args *xdr,
                                 guestfs_protobuf_strings_args *pbc);
void
convert_strings_args_protobuf_to_xdr (                                 guestfs_protobuf_strings_args *pbc,
                                 guestfs_strings_args *xdr);
void
convert_strings_ret_xdr_to_protobuf (                                guestfs_strings_ret *xdr,
                                guestfs_protobuf_strings_ret *pbc);
void
convert_strings_ret_protobuf_to_xdr (                                guestfs_protobuf_strings_ret *pbc,
                                guestfs_strings_ret *xdr);
void
convert_strings_ee_args_xdr_to_protobuf (                                 guestfs_strings_ee_args *xdr,
                                 guestfs_protobuf_strings_ee_args *pbc);
void
convert_strings_ee_args_protobuf_to_xdr (                                 guestfs_protobuf_strings_ee_args *pbc,
                                 guestfs_strings_ee_args *xdr);
void
convert_strings_ee_ret_xdr_to_protobuf (                                guestfs_strings_ee_ret *xdr,
                                guestfs_protobuf_strings_ee_ret *pbc);
void
convert_strings_ee_ret_protobuf_to_xdr (                                guestfs_protobuf_strings_ee_ret *pbc,
                                guestfs_strings_ee_ret *xdr);
void
convert_hexdump_args_xdr_to_protobuf (                                 guestfs_hexdump_args *xdr,
                                 guestfs_protobuf_hexdump_args *pbc);
void
convert_hexdump_args_protobuf_to_xdr (                                 guestfs_protobuf_hexdump_args *pbc,
                                 guestfs_hexdump_args *xdr);
void
convert_hexdump_ret_xdr_to_protobuf (                                guestfs_hexdump_ret *xdr,
                                guestfs_protobuf_hexdump_ret *pbc);
void
convert_hexdump_ret_protobuf_to_xdr (                                guestfs_protobuf_hexdump_ret *pbc,
                                guestfs_hexdump_ret *xdr);
void
convert_zerofree_args_xdr_to_protobuf (                                 guestfs_zerofree_args *xdr,
                                 guestfs_protobuf_zerofree_args *pbc);
void
convert_zerofree_args_protobuf_to_xdr (                                 guestfs_protobuf_zerofree_args *pbc,
                                 guestfs_zerofree_args *xdr);
void
convert_pvresize_args_xdr_to_protobuf (                                 guestfs_pvresize_args *xdr,
                                 guestfs_protobuf_pvresize_args *pbc);
void
convert_pvresize_args_protobuf_to_xdr (                                 guestfs_protobuf_pvresize_args *pbc,
                                 guestfs_pvresize_args *xdr);
void
convert_sfdisk_nn_args_xdr_to_protobuf (                                 guestfs_sfdisk_nn_args *xdr,
                                 guestfs_protobuf_sfdisk_nn_args *pbc);
void
convert_sfdisk_nn_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_nn_args *pbc,
                                 guestfs_sfdisk_nn_args *xdr);
void
convert_sfdisk_ll_args_xdr_to_protobuf (                                 guestfs_sfdisk_ll_args *xdr,
                                 guestfs_protobuf_sfdisk_ll_args *pbc);
void
convert_sfdisk_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_ll_args *pbc,
                                 guestfs_sfdisk_ll_args *xdr);
void
convert_sfdisk_ll_ret_xdr_to_protobuf (                                guestfs_sfdisk_ll_ret *xdr,
                                guestfs_protobuf_sfdisk_ll_ret *pbc);
void
convert_sfdisk_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_sfdisk_ll_ret *pbc,
                                guestfs_sfdisk_ll_ret *xdr);
void
convert_sfdisk_kernel_geometry_args_xdr_to_protobuf (                                 guestfs_sfdisk_kernel_geometry_args *xdr,
                                 guestfs_protobuf_sfdisk_kernel_geometry_args *pbc);
void
convert_sfdisk_kernel_geometry_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_kernel_geometry_args *pbc,
                                 guestfs_sfdisk_kernel_geometry_args *xdr);
void
convert_sfdisk_kernel_geometry_ret_xdr_to_protobuf (                                guestfs_sfdisk_kernel_geometry_ret *xdr,
                                guestfs_protobuf_sfdisk_kernel_geometry_ret *pbc);
void
convert_sfdisk_kernel_geometry_ret_protobuf_to_xdr (                                guestfs_protobuf_sfdisk_kernel_geometry_ret *pbc,
                                guestfs_sfdisk_kernel_geometry_ret *xdr);
void
convert_sfdisk_disk_geometry_args_xdr_to_protobuf (                                 guestfs_sfdisk_disk_geometry_args *xdr,
                                 guestfs_protobuf_sfdisk_disk_geometry_args *pbc);
void
convert_sfdisk_disk_geometry_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_disk_geometry_args *pbc,
                                 guestfs_sfdisk_disk_geometry_args *xdr);
void
convert_sfdisk_disk_geometry_ret_xdr_to_protobuf (                                guestfs_sfdisk_disk_geometry_ret *xdr,
                                guestfs_protobuf_sfdisk_disk_geometry_ret *pbc);
void
convert_sfdisk_disk_geometry_ret_protobuf_to_xdr (                                guestfs_protobuf_sfdisk_disk_geometry_ret *pbc,
                                guestfs_sfdisk_disk_geometry_ret *xdr);
void
convert_vg_activate_all_args_xdr_to_protobuf (                                 guestfs_vg_activate_all_args *xdr,
                                 guestfs_protobuf_vg_activate_all_args *pbc);
void
convert_vg_activate_all_args_protobuf_to_xdr (                                 guestfs_protobuf_vg_activate_all_args *pbc,
                                 guestfs_vg_activate_all_args *xdr);
void
convert_vg_activate_args_xdr_to_protobuf (                                 guestfs_vg_activate_args *xdr,
                                 guestfs_protobuf_vg_activate_args *pbc);
void
convert_vg_activate_args_protobuf_to_xdr (                                 guestfs_protobuf_vg_activate_args *pbc,
                                 guestfs_vg_activate_args *xdr);
void
convert_lvresize_args_xdr_to_protobuf (                                 guestfs_lvresize_args *xdr,
                                 guestfs_protobuf_lvresize_args *pbc);
void
convert_lvresize_args_protobuf_to_xdr (                                 guestfs_protobuf_lvresize_args *pbc,
                                 guestfs_lvresize_args *xdr);
void
convert_resize2fs_args_xdr_to_protobuf (                                 guestfs_resize2fs_args *xdr,
                                 guestfs_protobuf_resize2fs_args *pbc);
void
convert_resize2fs_args_protobuf_to_xdr (                                 guestfs_protobuf_resize2fs_args *pbc,
                                 guestfs_resize2fs_args *xdr);
void
convert_e2fsck_ff_args_xdr_to_protobuf (                                 guestfs_e2fsck_ff_args *xdr,
                                 guestfs_protobuf_e2fsck_ff_args *pbc);
void
convert_e2fsck_ff_args_protobuf_to_xdr (                                 guestfs_protobuf_e2fsck_ff_args *pbc,
                                 guestfs_e2fsck_ff_args *xdr);
void
convert_sleep_args_xdr_to_protobuf (                                 guestfs_sleep_args *xdr,
                                 guestfs_protobuf_sleep_args *pbc);
void
convert_sleep_args_protobuf_to_xdr (                                 guestfs_protobuf_sleep_args *pbc,
                                 guestfs_sleep_args *xdr);
void
convert_ntfs3g_probe_args_xdr_to_protobuf (                                 guestfs_ntfs3g_probe_args *xdr,
                                 guestfs_protobuf_ntfs3g_probe_args *pbc);
void
convert_ntfs3g_probe_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfs3g_probe_args *pbc,
                                 guestfs_ntfs3g_probe_args *xdr);
void
convert_ntfs3g_probe_ret_xdr_to_protobuf (                                guestfs_ntfs3g_probe_ret *xdr,
                                guestfs_protobuf_ntfs3g_probe_ret *pbc);
void
convert_ntfs3g_probe_ret_protobuf_to_xdr (                                guestfs_protobuf_ntfs3g_probe_ret *pbc,
                                guestfs_ntfs3g_probe_ret *xdr);
void
convert_sh_args_xdr_to_protobuf (                                 guestfs_sh_args *xdr,
                                 guestfs_protobuf_sh_args *pbc);
void
convert_sh_args_protobuf_to_xdr (                                 guestfs_protobuf_sh_args *pbc,
                                 guestfs_sh_args *xdr);
void
convert_sh_ret_xdr_to_protobuf (                                guestfs_sh_ret *xdr,
                                guestfs_protobuf_sh_ret *pbc);
void
convert_sh_ret_protobuf_to_xdr (                                guestfs_protobuf_sh_ret *pbc,
                                guestfs_sh_ret *xdr);
void
convert_sh_lines_args_xdr_to_protobuf (                                 guestfs_sh_lines_args *xdr,
                                 guestfs_protobuf_sh_lines_args *pbc);
void
convert_sh_lines_args_protobuf_to_xdr (                                 guestfs_protobuf_sh_lines_args *pbc,
                                 guestfs_sh_lines_args *xdr);
void
convert_sh_lines_ret_xdr_to_protobuf (                                guestfs_sh_lines_ret *xdr,
                                guestfs_protobuf_sh_lines_ret *pbc);
void
convert_sh_lines_ret_protobuf_to_xdr (                                guestfs_protobuf_sh_lines_ret *pbc,
                                guestfs_sh_lines_ret *xdr);
void
convert_glob_expand_args_xdr_to_protobuf (                                 guestfs_glob_expand_args *xdr,
                                 guestfs_protobuf_glob_expand_args *pbc);
void
convert_glob_expand_args_protobuf_to_xdr (                                 guestfs_protobuf_glob_expand_args *pbc,
                                 guestfs_glob_expand_args *xdr);
void
convert_glob_expand_ret_xdr_to_protobuf (                                guestfs_glob_expand_ret *xdr,
                                guestfs_protobuf_glob_expand_ret *pbc);
void
convert_glob_expand_ret_protobuf_to_xdr (                                guestfs_protobuf_glob_expand_ret *pbc,
                                guestfs_glob_expand_ret *xdr);
void
convert_scrub_device_args_xdr_to_protobuf (                                 guestfs_scrub_device_args *xdr,
                                 guestfs_protobuf_scrub_device_args *pbc);
void
convert_scrub_device_args_protobuf_to_xdr (                                 guestfs_protobuf_scrub_device_args *pbc,
                                 guestfs_scrub_device_args *xdr);
void
convert_scrub_file_args_xdr_to_protobuf (                                 guestfs_scrub_file_args *xdr,
                                 guestfs_protobuf_scrub_file_args *pbc);
void
convert_scrub_file_args_protobuf_to_xdr (                                 guestfs_protobuf_scrub_file_args *pbc,
                                 guestfs_scrub_file_args *xdr);
void
convert_scrub_freespace_args_xdr_to_protobuf (                                 guestfs_scrub_freespace_args *xdr,
                                 guestfs_protobuf_scrub_freespace_args *pbc);
void
convert_scrub_freespace_args_protobuf_to_xdr (                                 guestfs_protobuf_scrub_freespace_args *pbc,
                                 guestfs_scrub_freespace_args *xdr);
void
convert_mkdtemp_args_xdr_to_protobuf (                                 guestfs_mkdtemp_args *xdr,
                                 guestfs_protobuf_mkdtemp_args *pbc);
void
convert_mkdtemp_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdtemp_args *pbc,
                                 guestfs_mkdtemp_args *xdr);
void
convert_mkdtemp_ret_xdr_to_protobuf (                                guestfs_mkdtemp_ret *xdr,
                                guestfs_protobuf_mkdtemp_ret *pbc);
void
convert_mkdtemp_ret_protobuf_to_xdr (                                guestfs_protobuf_mkdtemp_ret *pbc,
                                guestfs_mkdtemp_ret *xdr);
void
convert_wc_ll_args_xdr_to_protobuf (                                 guestfs_wc_ll_args *xdr,
                                 guestfs_protobuf_wc_ll_args *pbc);
void
convert_wc_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_wc_ll_args *pbc,
                                 guestfs_wc_ll_args *xdr);
void
convert_wc_ll_ret_xdr_to_protobuf (                                guestfs_wc_ll_ret *xdr,
                                guestfs_protobuf_wc_ll_ret *pbc);
void
convert_wc_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_wc_ll_ret *pbc,
                                guestfs_wc_ll_ret *xdr);
void
convert_wc_ww_args_xdr_to_protobuf (                                 guestfs_wc_ww_args *xdr,
                                 guestfs_protobuf_wc_ww_args *pbc);
void
convert_wc_ww_args_protobuf_to_xdr (                                 guestfs_protobuf_wc_ww_args *pbc,
                                 guestfs_wc_ww_args *xdr);
void
convert_wc_ww_ret_xdr_to_protobuf (                                guestfs_wc_ww_ret *xdr,
                                guestfs_protobuf_wc_ww_ret *pbc);
void
convert_wc_ww_ret_protobuf_to_xdr (                                guestfs_protobuf_wc_ww_ret *pbc,
                                guestfs_wc_ww_ret *xdr);
void
convert_wc_cc_args_xdr_to_protobuf (                                 guestfs_wc_cc_args *xdr,
                                 guestfs_protobuf_wc_cc_args *pbc);
void
convert_wc_cc_args_protobuf_to_xdr (                                 guestfs_protobuf_wc_cc_args *pbc,
                                 guestfs_wc_cc_args *xdr);
void
convert_wc_cc_ret_xdr_to_protobuf (                                guestfs_wc_cc_ret *xdr,
                                guestfs_protobuf_wc_cc_ret *pbc);
void
convert_wc_cc_ret_protobuf_to_xdr (                                guestfs_protobuf_wc_cc_ret *pbc,
                                guestfs_wc_cc_ret *xdr);
void
convert_head_args_xdr_to_protobuf (                                 guestfs_head_args *xdr,
                                 guestfs_protobuf_head_args *pbc);
void
convert_head_args_protobuf_to_xdr (                                 guestfs_protobuf_head_args *pbc,
                                 guestfs_head_args *xdr);
void
convert_head_ret_xdr_to_protobuf (                                guestfs_head_ret *xdr,
                                guestfs_protobuf_head_ret *pbc);
void
convert_head_ret_protobuf_to_xdr (                                guestfs_protobuf_head_ret *pbc,
                                guestfs_head_ret *xdr);
void
convert_head_nn_args_xdr_to_protobuf (                                 guestfs_head_nn_args *xdr,
                                 guestfs_protobuf_head_nn_args *pbc);
void
convert_head_nn_args_protobuf_to_xdr (                                 guestfs_protobuf_head_nn_args *pbc,
                                 guestfs_head_nn_args *xdr);
void
convert_head_nn_ret_xdr_to_protobuf (                                guestfs_head_nn_ret *xdr,
                                guestfs_protobuf_head_nn_ret *pbc);
void
convert_head_nn_ret_protobuf_to_xdr (                                guestfs_protobuf_head_nn_ret *pbc,
                                guestfs_head_nn_ret *xdr);
void
convert_tail_args_xdr_to_protobuf (                                 guestfs_tail_args *xdr,
                                 guestfs_protobuf_tail_args *pbc);
void
convert_tail_args_protobuf_to_xdr (                                 guestfs_protobuf_tail_args *pbc,
                                 guestfs_tail_args *xdr);
void
convert_tail_ret_xdr_to_protobuf (                                guestfs_tail_ret *xdr,
                                guestfs_protobuf_tail_ret *pbc);
void
convert_tail_ret_protobuf_to_xdr (                                guestfs_protobuf_tail_ret *pbc,
                                guestfs_tail_ret *xdr);
void
convert_tail_nn_args_xdr_to_protobuf (                                 guestfs_tail_nn_args *xdr,
                                 guestfs_protobuf_tail_nn_args *pbc);
void
convert_tail_nn_args_protobuf_to_xdr (                                 guestfs_protobuf_tail_nn_args *pbc,
                                 guestfs_tail_nn_args *xdr);
void
convert_tail_nn_ret_xdr_to_protobuf (                                guestfs_tail_nn_ret *xdr,
                                guestfs_protobuf_tail_nn_ret *pbc);
void
convert_tail_nn_ret_protobuf_to_xdr (                                guestfs_protobuf_tail_nn_ret *pbc,
                                guestfs_tail_nn_ret *xdr);
void
convert_df_ret_xdr_to_protobuf (                                guestfs_df_ret *xdr,
                                guestfs_protobuf_df_ret *pbc);
void
convert_df_ret_protobuf_to_xdr (                                guestfs_protobuf_df_ret *pbc,
                                guestfs_df_ret *xdr);
void
convert_df_hh_ret_xdr_to_protobuf (                                guestfs_df_hh_ret *xdr,
                                guestfs_protobuf_df_hh_ret *pbc);
void
convert_df_hh_ret_protobuf_to_xdr (                                guestfs_protobuf_df_hh_ret *pbc,
                                guestfs_df_hh_ret *xdr);
void
convert_du_args_xdr_to_protobuf (                                 guestfs_du_args *xdr,
                                 guestfs_protobuf_du_args *pbc);
void
convert_du_args_protobuf_to_xdr (                                 guestfs_protobuf_du_args *pbc,
                                 guestfs_du_args *xdr);
void
convert_du_ret_xdr_to_protobuf (                                guestfs_du_ret *xdr,
                                guestfs_protobuf_du_ret *pbc);
void
convert_du_ret_protobuf_to_xdr (                                guestfs_protobuf_du_ret *pbc,
                                guestfs_du_ret *xdr);
void
convert_initrd_list_args_xdr_to_protobuf (                                 guestfs_initrd_list_args *xdr,
                                 guestfs_protobuf_initrd_list_args *pbc);
void
convert_initrd_list_args_protobuf_to_xdr (                                 guestfs_protobuf_initrd_list_args *pbc,
                                 guestfs_initrd_list_args *xdr);
void
convert_initrd_list_ret_xdr_to_protobuf (                                guestfs_initrd_list_ret *xdr,
                                guestfs_protobuf_initrd_list_ret *pbc);
void
convert_initrd_list_ret_protobuf_to_xdr (                                guestfs_protobuf_initrd_list_ret *pbc,
                                guestfs_initrd_list_ret *xdr);
void
convert_mount_loop_args_xdr_to_protobuf (                                 guestfs_mount_loop_args *xdr,
                                 guestfs_protobuf_mount_loop_args *pbc);
void
convert_mount_loop_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_loop_args *pbc,
                                 guestfs_mount_loop_args *xdr);
void
convert_mkswap_args_xdr_to_protobuf (                                 guestfs_mkswap_args *xdr,
                                 guestfs_protobuf_mkswap_args *pbc);
void
convert_mkswap_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_args *pbc,
                                 guestfs_mkswap_args *xdr);
void
convert_mkswap_ll_args_xdr_to_protobuf (                                 guestfs_mkswap_ll_args *xdr,
                                 guestfs_protobuf_mkswap_ll_args *pbc);
void
convert_mkswap_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_ll_args *pbc,
                                 guestfs_mkswap_ll_args *xdr);
void
convert_mkswap_uu_args_xdr_to_protobuf (                                 guestfs_mkswap_uu_args *xdr,
                                 guestfs_protobuf_mkswap_uu_args *pbc);
void
convert_mkswap_uu_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_uu_args *pbc,
                                 guestfs_mkswap_uu_args *xdr);
void
convert_mknod_args_xdr_to_protobuf (                                 guestfs_mknod_args *xdr,
                                 guestfs_protobuf_mknod_args *pbc);
void
convert_mknod_args_protobuf_to_xdr (                                 guestfs_protobuf_mknod_args *pbc,
                                 guestfs_mknod_args *xdr);
void
convert_mkfifo_args_xdr_to_protobuf (                                 guestfs_mkfifo_args *xdr,
                                 guestfs_protobuf_mkfifo_args *pbc);
void
convert_mkfifo_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfifo_args *pbc,
                                 guestfs_mkfifo_args *xdr);
void
convert_mknod_bb_args_xdr_to_protobuf (                                 guestfs_mknod_bb_args *xdr,
                                 guestfs_protobuf_mknod_bb_args *pbc);
void
convert_mknod_bb_args_protobuf_to_xdr (                                 guestfs_protobuf_mknod_bb_args *pbc,
                                 guestfs_mknod_bb_args *xdr);
void
convert_mknod_cc_args_xdr_to_protobuf (                                 guestfs_mknod_cc_args *xdr,
                                 guestfs_protobuf_mknod_cc_args *pbc);
void
convert_mknod_cc_args_protobuf_to_xdr (                                 guestfs_protobuf_mknod_cc_args *pbc,
                                 guestfs_mknod_cc_args *xdr);
void
convert_umask_args_xdr_to_protobuf (                                 guestfs_umask_args *xdr,
                                 guestfs_protobuf_umask_args *pbc);
void
convert_umask_args_protobuf_to_xdr (                                 guestfs_protobuf_umask_args *pbc,
                                 guestfs_umask_args *xdr);
void
convert_umask_ret_xdr_to_protobuf (                                guestfs_umask_ret *xdr,
                                guestfs_protobuf_umask_ret *pbc);
void
convert_umask_ret_protobuf_to_xdr (                                guestfs_protobuf_umask_ret *pbc,
                                guestfs_umask_ret *xdr);
void
convert_readdir_args_xdr_to_protobuf (                                 guestfs_readdir_args *xdr,
                                 guestfs_protobuf_readdir_args *pbc);
void
convert_readdir_args_protobuf_to_xdr (                                 guestfs_protobuf_readdir_args *pbc,
                                 guestfs_readdir_args *xdr);
void
convert_readdir_ret_xdr_to_protobuf (                                guestfs_readdir_ret *xdr,
                                guestfs_protobuf_readdir_ret *pbc);
void
convert_readdir_ret_protobuf_to_xdr (                                guestfs_protobuf_readdir_ret *pbc,
                                guestfs_readdir_ret *xdr);
void
convert_sfdiskm_args_xdr_to_protobuf (                                 guestfs_sfdiskm_args *xdr,
                                 guestfs_protobuf_sfdiskm_args *pbc);
void
convert_sfdiskm_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdiskm_args *pbc,
                                 guestfs_sfdiskm_args *xdr);
void
convert_zfile_args_xdr_to_protobuf (                                 guestfs_zfile_args *xdr,
                                 guestfs_protobuf_zfile_args *pbc);
void
convert_zfile_args_protobuf_to_xdr (                                 guestfs_protobuf_zfile_args *pbc,
                                 guestfs_zfile_args *xdr);
void
convert_zfile_ret_xdr_to_protobuf (                                guestfs_zfile_ret *xdr,
                                guestfs_protobuf_zfile_ret *pbc);
void
convert_zfile_ret_protobuf_to_xdr (                                guestfs_protobuf_zfile_ret *pbc,
                                guestfs_zfile_ret *xdr);
void
convert_getxattrs_args_xdr_to_protobuf (                                 guestfs_getxattrs_args *xdr,
                                 guestfs_protobuf_getxattrs_args *pbc);
void
convert_getxattrs_args_protobuf_to_xdr (                                 guestfs_protobuf_getxattrs_args *pbc,
                                 guestfs_getxattrs_args *xdr);
void
convert_getxattrs_ret_xdr_to_protobuf (                                guestfs_getxattrs_ret *xdr,
                                guestfs_protobuf_getxattrs_ret *pbc);
void
convert_getxattrs_ret_protobuf_to_xdr (                                guestfs_protobuf_getxattrs_ret *pbc,
                                guestfs_getxattrs_ret *xdr);
void
convert_lgetxattrs_args_xdr_to_protobuf (                                 guestfs_lgetxattrs_args *xdr,
                                 guestfs_protobuf_lgetxattrs_args *pbc);
void
convert_lgetxattrs_args_protobuf_to_xdr (                                 guestfs_protobuf_lgetxattrs_args *pbc,
                                 guestfs_lgetxattrs_args *xdr);
void
convert_lgetxattrs_ret_xdr_to_protobuf (                                guestfs_lgetxattrs_ret *xdr,
                                guestfs_protobuf_lgetxattrs_ret *pbc);
void
convert_lgetxattrs_ret_protobuf_to_xdr (                                guestfs_protobuf_lgetxattrs_ret *pbc,
                                guestfs_lgetxattrs_ret *xdr);
void
convert_setxattr_args_xdr_to_protobuf (                                 guestfs_setxattr_args *xdr,
                                 guestfs_protobuf_setxattr_args *pbc);
void
convert_setxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_setxattr_args *pbc,
                                 guestfs_setxattr_args *xdr);
void
convert_lsetxattr_args_xdr_to_protobuf (                                 guestfs_lsetxattr_args *xdr,
                                 guestfs_protobuf_lsetxattr_args *pbc);
void
convert_lsetxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_lsetxattr_args *pbc,
                                 guestfs_lsetxattr_args *xdr);
void
convert_removexattr_args_xdr_to_protobuf (                                 guestfs_removexattr_args *xdr,
                                 guestfs_protobuf_removexattr_args *pbc);
void
convert_removexattr_args_protobuf_to_xdr (                                 guestfs_protobuf_removexattr_args *pbc,
                                 guestfs_removexattr_args *xdr);
void
convert_lremovexattr_args_xdr_to_protobuf (                                 guestfs_lremovexattr_args *xdr,
                                 guestfs_protobuf_lremovexattr_args *pbc);
void
convert_lremovexattr_args_protobuf_to_xdr (                                 guestfs_protobuf_lremovexattr_args *pbc,
                                 guestfs_lremovexattr_args *xdr);
void
convert_mountpoints_ret_xdr_to_protobuf (                                guestfs_mountpoints_ret *xdr,
                                guestfs_protobuf_mountpoints_ret *pbc);
void
convert_mountpoints_ret_protobuf_to_xdr (                                guestfs_protobuf_mountpoints_ret *pbc,
                                guestfs_mountpoints_ret *xdr);
void
convert_mkmountpoint_args_xdr_to_protobuf (                                 guestfs_mkmountpoint_args *xdr,
                                 guestfs_protobuf_mkmountpoint_args *pbc);
void
convert_mkmountpoint_args_protobuf_to_xdr (                                 guestfs_protobuf_mkmountpoint_args *pbc,
                                 guestfs_mkmountpoint_args *xdr);
void
convert_rmmountpoint_args_xdr_to_protobuf (                                 guestfs_rmmountpoint_args *xdr,
                                 guestfs_protobuf_rmmountpoint_args *pbc);
void
convert_rmmountpoint_args_protobuf_to_xdr (                                 guestfs_protobuf_rmmountpoint_args *pbc,
                                 guestfs_rmmountpoint_args *xdr);
void
convert_grep_args_xdr_to_protobuf (                                 guestfs_grep_args *xdr,
                                 guestfs_protobuf_grep_args *pbc);
void
convert_grep_args_protobuf_to_xdr (                                 guestfs_protobuf_grep_args *pbc,
                                 guestfs_grep_args *xdr);
void
convert_grep_ret_xdr_to_protobuf (                                guestfs_grep_ret *xdr,
                                guestfs_protobuf_grep_ret *pbc);
void
convert_grep_ret_protobuf_to_xdr (                                guestfs_protobuf_grep_ret *pbc,
                                guestfs_grep_ret *xdr);
void
convert_egrep_args_xdr_to_protobuf (                                 guestfs_egrep_args *xdr,
                                 guestfs_protobuf_egrep_args *pbc);
void
convert_egrep_args_protobuf_to_xdr (                                 guestfs_protobuf_egrep_args *pbc,
                                 guestfs_egrep_args *xdr);
void
convert_egrep_ret_xdr_to_protobuf (                                guestfs_egrep_ret *xdr,
                                guestfs_protobuf_egrep_ret *pbc);
void
convert_egrep_ret_protobuf_to_xdr (                                guestfs_protobuf_egrep_ret *pbc,
                                guestfs_egrep_ret *xdr);
void
convert_fgrep_args_xdr_to_protobuf (                                 guestfs_fgrep_args *xdr,
                                 guestfs_protobuf_fgrep_args *pbc);
void
convert_fgrep_args_protobuf_to_xdr (                                 guestfs_protobuf_fgrep_args *pbc,
                                 guestfs_fgrep_args *xdr);
void
convert_fgrep_ret_xdr_to_protobuf (                                guestfs_fgrep_ret *xdr,
                                guestfs_protobuf_fgrep_ret *pbc);
void
convert_fgrep_ret_protobuf_to_xdr (                                guestfs_protobuf_fgrep_ret *pbc,
                                guestfs_fgrep_ret *xdr);
void
convert_grepi_args_xdr_to_protobuf (                                 guestfs_grepi_args *xdr,
                                 guestfs_protobuf_grepi_args *pbc);
void
convert_grepi_args_protobuf_to_xdr (                                 guestfs_protobuf_grepi_args *pbc,
                                 guestfs_grepi_args *xdr);
void
convert_grepi_ret_xdr_to_protobuf (                                guestfs_grepi_ret *xdr,
                                guestfs_protobuf_grepi_ret *pbc);
void
convert_grepi_ret_protobuf_to_xdr (                                guestfs_protobuf_grepi_ret *pbc,
                                guestfs_grepi_ret *xdr);
void
convert_egrepi_args_xdr_to_protobuf (                                 guestfs_egrepi_args *xdr,
                                 guestfs_protobuf_egrepi_args *pbc);
void
convert_egrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_egrepi_args *pbc,
                                 guestfs_egrepi_args *xdr);
void
convert_egrepi_ret_xdr_to_protobuf (                                guestfs_egrepi_ret *xdr,
                                guestfs_protobuf_egrepi_ret *pbc);
void
convert_egrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_egrepi_ret *pbc,
                                guestfs_egrepi_ret *xdr);
void
convert_fgrepi_args_xdr_to_protobuf (                                 guestfs_fgrepi_args *xdr,
                                 guestfs_protobuf_fgrepi_args *pbc);
void
convert_fgrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_fgrepi_args *pbc,
                                 guestfs_fgrepi_args *xdr);
void
convert_fgrepi_ret_xdr_to_protobuf (                                guestfs_fgrepi_ret *xdr,
                                guestfs_protobuf_fgrepi_ret *pbc);
void
convert_fgrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_fgrepi_ret *pbc,
                                guestfs_fgrepi_ret *xdr);
void
convert_zgrep_args_xdr_to_protobuf (                                 guestfs_zgrep_args *xdr,
                                 guestfs_protobuf_zgrep_args *pbc);
void
convert_zgrep_args_protobuf_to_xdr (                                 guestfs_protobuf_zgrep_args *pbc,
                                 guestfs_zgrep_args *xdr);
void
convert_zgrep_ret_xdr_to_protobuf (                                guestfs_zgrep_ret *xdr,
                                guestfs_protobuf_zgrep_ret *pbc);
void
convert_zgrep_ret_protobuf_to_xdr (                                guestfs_protobuf_zgrep_ret *pbc,
                                guestfs_zgrep_ret *xdr);
void
convert_zegrep_args_xdr_to_protobuf (                                 guestfs_zegrep_args *xdr,
                                 guestfs_protobuf_zegrep_args *pbc);
void
convert_zegrep_args_protobuf_to_xdr (                                 guestfs_protobuf_zegrep_args *pbc,
                                 guestfs_zegrep_args *xdr);
void
convert_zegrep_ret_xdr_to_protobuf (                                guestfs_zegrep_ret *xdr,
                                guestfs_protobuf_zegrep_ret *pbc);
void
convert_zegrep_ret_protobuf_to_xdr (                                guestfs_protobuf_zegrep_ret *pbc,
                                guestfs_zegrep_ret *xdr);
void
convert_zfgrep_args_xdr_to_protobuf (                                 guestfs_zfgrep_args *xdr,
                                 guestfs_protobuf_zfgrep_args *pbc);
void
convert_zfgrep_args_protobuf_to_xdr (                                 guestfs_protobuf_zfgrep_args *pbc,
                                 guestfs_zfgrep_args *xdr);
void
convert_zfgrep_ret_xdr_to_protobuf (                                guestfs_zfgrep_ret *xdr,
                                guestfs_protobuf_zfgrep_ret *pbc);
void
convert_zfgrep_ret_protobuf_to_xdr (                                guestfs_protobuf_zfgrep_ret *pbc,
                                guestfs_zfgrep_ret *xdr);
void
convert_zgrepi_args_xdr_to_protobuf (                                 guestfs_zgrepi_args *xdr,
                                 guestfs_protobuf_zgrepi_args *pbc);
void
convert_zgrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_zgrepi_args *pbc,
                                 guestfs_zgrepi_args *xdr);
void
convert_zgrepi_ret_xdr_to_protobuf (                                guestfs_zgrepi_ret *xdr,
                                guestfs_protobuf_zgrepi_ret *pbc);
void
convert_zgrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_zgrepi_ret *pbc,
                                guestfs_zgrepi_ret *xdr);
void
convert_zegrepi_args_xdr_to_protobuf (                                 guestfs_zegrepi_args *xdr,
                                 guestfs_protobuf_zegrepi_args *pbc);
void
convert_zegrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_zegrepi_args *pbc,
                                 guestfs_zegrepi_args *xdr);
void
convert_zegrepi_ret_xdr_to_protobuf (                                guestfs_zegrepi_ret *xdr,
                                guestfs_protobuf_zegrepi_ret *pbc);
void
convert_zegrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_zegrepi_ret *pbc,
                                guestfs_zegrepi_ret *xdr);
void
convert_zfgrepi_args_xdr_to_protobuf (                                 guestfs_zfgrepi_args *xdr,
                                 guestfs_protobuf_zfgrepi_args *pbc);
void
convert_zfgrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_zfgrepi_args *pbc,
                                 guestfs_zfgrepi_args *xdr);
void
convert_zfgrepi_ret_xdr_to_protobuf (                                guestfs_zfgrepi_ret *xdr,
                                guestfs_protobuf_zfgrepi_ret *pbc);
void
convert_zfgrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_zfgrepi_ret *pbc,
                                guestfs_zfgrepi_ret *xdr);
void
convert_realpath_args_xdr_to_protobuf (                                 guestfs_realpath_args *xdr,
                                 guestfs_protobuf_realpath_args *pbc);
void
convert_realpath_args_protobuf_to_xdr (                                 guestfs_protobuf_realpath_args *pbc,
                                 guestfs_realpath_args *xdr);
void
convert_realpath_ret_xdr_to_protobuf (                                guestfs_realpath_ret *xdr,
                                guestfs_protobuf_realpath_ret *pbc);
void
convert_realpath_ret_protobuf_to_xdr (                                guestfs_protobuf_realpath_ret *pbc,
                                guestfs_realpath_ret *xdr);
void
convert_ln_args_xdr_to_protobuf (                                 guestfs_ln_args *xdr,
                                 guestfs_protobuf_ln_args *pbc);
void
convert_ln_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_args *pbc,
                                 guestfs_ln_args *xdr);
void
convert_ln_ff_args_xdr_to_protobuf (                                 guestfs_ln_ff_args *xdr,
                                 guestfs_protobuf_ln_ff_args *pbc);
void
convert_ln_ff_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_ff_args *pbc,
                                 guestfs_ln_ff_args *xdr);
void
convert_ln_ss_args_xdr_to_protobuf (                                 guestfs_ln_ss_args *xdr,
                                 guestfs_protobuf_ln_ss_args *pbc);
void
convert_ln_ss_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_ss_args *pbc,
                                 guestfs_ln_ss_args *xdr);
void
convert_ln_sf_args_xdr_to_protobuf (                                 guestfs_ln_sf_args *xdr,
                                 guestfs_protobuf_ln_sf_args *pbc);
void
convert_ln_sf_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_sf_args *pbc,
                                 guestfs_ln_sf_args *xdr);
void
convert_readlink_args_xdr_to_protobuf (                                 guestfs_readlink_args *xdr,
                                 guestfs_protobuf_readlink_args *pbc);
void
convert_readlink_args_protobuf_to_xdr (                                 guestfs_protobuf_readlink_args *pbc,
                                 guestfs_readlink_args *xdr);
void
convert_readlink_ret_xdr_to_protobuf (                                guestfs_readlink_ret *xdr,
                                guestfs_protobuf_readlink_ret *pbc);
void
convert_readlink_ret_protobuf_to_xdr (                                guestfs_protobuf_readlink_ret *pbc,
                                guestfs_readlink_ret *xdr);
void
convert_fallocate_args_xdr_to_protobuf (                                 guestfs_fallocate_args *xdr,
                                 guestfs_protobuf_fallocate_args *pbc);
void
convert_fallocate_args_protobuf_to_xdr (                                 guestfs_protobuf_fallocate_args *pbc,
                                 guestfs_fallocate_args *xdr);
void
convert_swapon_device_args_xdr_to_protobuf (                                 guestfs_swapon_device_args *xdr,
                                 guestfs_protobuf_swapon_device_args *pbc);
void
convert_swapon_device_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_device_args *pbc,
                                 guestfs_swapon_device_args *xdr);
void
convert_swapoff_device_args_xdr_to_protobuf (                                 guestfs_swapoff_device_args *xdr,
                                 guestfs_protobuf_swapoff_device_args *pbc);
void
convert_swapoff_device_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_device_args *pbc,
                                 guestfs_swapoff_device_args *xdr);
void
convert_swapon_file_args_xdr_to_protobuf (                                 guestfs_swapon_file_args *xdr,
                                 guestfs_protobuf_swapon_file_args *pbc);
void
convert_swapon_file_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_file_args *pbc,
                                 guestfs_swapon_file_args *xdr);
void
convert_swapoff_file_args_xdr_to_protobuf (                                 guestfs_swapoff_file_args *xdr,
                                 guestfs_protobuf_swapoff_file_args *pbc);
void
convert_swapoff_file_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_file_args *pbc,
                                 guestfs_swapoff_file_args *xdr);
void
convert_swapon_label_args_xdr_to_protobuf (                                 guestfs_swapon_label_args *xdr,
                                 guestfs_protobuf_swapon_label_args *pbc);
void
convert_swapon_label_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_label_args *pbc,
                                 guestfs_swapon_label_args *xdr);
void
convert_swapoff_label_args_xdr_to_protobuf (                                 guestfs_swapoff_label_args *xdr,
                                 guestfs_protobuf_swapoff_label_args *pbc);
void
convert_swapoff_label_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_label_args *pbc,
                                 guestfs_swapoff_label_args *xdr);
void
convert_swapon_uuid_args_xdr_to_protobuf (                                 guestfs_swapon_uuid_args *xdr,
                                 guestfs_protobuf_swapon_uuid_args *pbc);
void
convert_swapon_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_uuid_args *pbc,
                                 guestfs_swapon_uuid_args *xdr);
void
convert_swapoff_uuid_args_xdr_to_protobuf (                                 guestfs_swapoff_uuid_args *xdr,
                                 guestfs_protobuf_swapoff_uuid_args *pbc);
void
convert_swapoff_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_uuid_args *pbc,
                                 guestfs_swapoff_uuid_args *xdr);
void
convert_mkswap_file_args_xdr_to_protobuf (                                 guestfs_mkswap_file_args *xdr,
                                 guestfs_protobuf_mkswap_file_args *pbc);
void
convert_mkswap_file_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_file_args *pbc,
                                 guestfs_mkswap_file_args *xdr);
void
convert_inotify_init_args_xdr_to_protobuf (                                 guestfs_inotify_init_args *xdr,
                                 guestfs_protobuf_inotify_init_args *pbc);
void
convert_inotify_init_args_protobuf_to_xdr (                                 guestfs_protobuf_inotify_init_args *pbc,
                                 guestfs_inotify_init_args *xdr);
void
convert_inotify_add_watch_args_xdr_to_protobuf (                                 guestfs_inotify_add_watch_args *xdr,
                                 guestfs_protobuf_inotify_add_watch_args *pbc);
void
convert_inotify_add_watch_args_protobuf_to_xdr (                                 guestfs_protobuf_inotify_add_watch_args *pbc,
                                 guestfs_inotify_add_watch_args *xdr);
void
convert_inotify_add_watch_ret_xdr_to_protobuf (                                guestfs_inotify_add_watch_ret *xdr,
                                guestfs_protobuf_inotify_add_watch_ret *pbc);
void
convert_inotify_add_watch_ret_protobuf_to_xdr (                                guestfs_protobuf_inotify_add_watch_ret *pbc,
                                guestfs_inotify_add_watch_ret *xdr);
void
convert_inotify_rm_watch_args_xdr_to_protobuf (                                 guestfs_inotify_rm_watch_args *xdr,
                                 guestfs_protobuf_inotify_rm_watch_args *pbc);
void
convert_inotify_rm_watch_args_protobuf_to_xdr (                                 guestfs_protobuf_inotify_rm_watch_args *pbc,
                                 guestfs_inotify_rm_watch_args *xdr);
void
convert_inotify_read_ret_xdr_to_protobuf (                                guestfs_inotify_read_ret *xdr,
                                guestfs_protobuf_inotify_read_ret *pbc);
void
convert_inotify_read_ret_protobuf_to_xdr (                                guestfs_protobuf_inotify_read_ret *pbc,
                                guestfs_inotify_read_ret *xdr);
void
convert_inotify_files_ret_xdr_to_protobuf (                                guestfs_inotify_files_ret *xdr,
                                guestfs_protobuf_inotify_files_ret *pbc);
void
convert_inotify_files_ret_protobuf_to_xdr (                                guestfs_protobuf_inotify_files_ret *pbc,
                                guestfs_inotify_files_ret *xdr);
void
convert_setcon_args_xdr_to_protobuf (                                 guestfs_setcon_args *xdr,
                                 guestfs_protobuf_setcon_args *pbc);
void
convert_setcon_args_protobuf_to_xdr (                                 guestfs_protobuf_setcon_args *pbc,
                                 guestfs_setcon_args *xdr);
void
convert_getcon_ret_xdr_to_protobuf (                                guestfs_getcon_ret *xdr,
                                guestfs_protobuf_getcon_ret *pbc);
void
convert_getcon_ret_protobuf_to_xdr (                                guestfs_protobuf_getcon_ret *pbc,
                                guestfs_getcon_ret *xdr);
void
convert_mkfs_bb_args_xdr_to_protobuf (                                 guestfs_mkfs_bb_args *xdr,
                                 guestfs_protobuf_mkfs_bb_args *pbc);
void
convert_mkfs_bb_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfs_bb_args *pbc,
                                 guestfs_mkfs_bb_args *xdr);
void
convert_mke2journal_args_xdr_to_protobuf (                                 guestfs_mke2journal_args *xdr,
                                 guestfs_protobuf_mke2journal_args *pbc);
void
convert_mke2journal_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2journal_args *pbc,
                                 guestfs_mke2journal_args *xdr);
void
convert_mke2journal_ll_args_xdr_to_protobuf (                                 guestfs_mke2journal_ll_args *xdr,
                                 guestfs_protobuf_mke2journal_ll_args *pbc);
void
convert_mke2journal_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2journal_ll_args *pbc,
                                 guestfs_mke2journal_ll_args *xdr);
void
convert_mke2journal_uu_args_xdr_to_protobuf (                                 guestfs_mke2journal_uu_args *xdr,
                                 guestfs_protobuf_mke2journal_uu_args *pbc);
void
convert_mke2journal_uu_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2journal_uu_args *pbc,
                                 guestfs_mke2journal_uu_args *xdr);
void
convert_mke2fs_jj_args_xdr_to_protobuf (                                 guestfs_mke2fs_jj_args *xdr,
                                 guestfs_protobuf_mke2fs_jj_args *pbc);
void
convert_mke2fs_jj_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_jj_args *pbc,
                                 guestfs_mke2fs_jj_args *xdr);
void
convert_mke2fs_jl_args_xdr_to_protobuf (                                 guestfs_mke2fs_jl_args *xdr,
                                 guestfs_protobuf_mke2fs_jl_args *pbc);
void
convert_mke2fs_jl_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_jl_args *pbc,
                                 guestfs_mke2fs_jl_args *xdr);
void
convert_mke2fs_ju_args_xdr_to_protobuf (                                 guestfs_mke2fs_ju_args *xdr,
                                 guestfs_protobuf_mke2fs_ju_args *pbc);
void
convert_mke2fs_ju_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_ju_args *pbc,
                                 guestfs_mke2fs_ju_args *xdr);
void
convert_modprobe_args_xdr_to_protobuf (                                 guestfs_modprobe_args *xdr,
                                 guestfs_protobuf_modprobe_args *pbc);
void
convert_modprobe_args_protobuf_to_xdr (                                 guestfs_protobuf_modprobe_args *pbc,
                                 guestfs_modprobe_args *xdr);
void
convert_echo_daemon_args_xdr_to_protobuf (                                 guestfs_echo_daemon_args *xdr,
                                 guestfs_protobuf_echo_daemon_args *pbc);
void
convert_echo_daemon_args_protobuf_to_xdr (                                 guestfs_protobuf_echo_daemon_args *pbc,
                                 guestfs_echo_daemon_args *xdr);
void
convert_echo_daemon_ret_xdr_to_protobuf (                                guestfs_echo_daemon_ret *xdr,
                                guestfs_protobuf_echo_daemon_ret *pbc);
void
convert_echo_daemon_ret_protobuf_to_xdr (                                guestfs_protobuf_echo_daemon_ret *pbc,
                                guestfs_echo_daemon_ret *xdr);
void
convert_find0_args_xdr_to_protobuf (                                 guestfs_find0_args *xdr,
                                 guestfs_protobuf_find0_args *pbc);
void
convert_find0_args_protobuf_to_xdr (                                 guestfs_protobuf_find0_args *pbc,
                                 guestfs_find0_args *xdr);
void
convert_case_sensitive_path_args_xdr_to_protobuf (                                 guestfs_case_sensitive_path_args *xdr,
                                 guestfs_protobuf_case_sensitive_path_args *pbc);
void
convert_case_sensitive_path_args_protobuf_to_xdr (                                 guestfs_protobuf_case_sensitive_path_args *pbc,
                                 guestfs_case_sensitive_path_args *xdr);
void
convert_case_sensitive_path_ret_xdr_to_protobuf (                                guestfs_case_sensitive_path_ret *xdr,
                                guestfs_protobuf_case_sensitive_path_ret *pbc);
void
convert_case_sensitive_path_ret_protobuf_to_xdr (                                guestfs_protobuf_case_sensitive_path_ret *pbc,
                                guestfs_case_sensitive_path_ret *xdr);
void
convert_vfs_type_args_xdr_to_protobuf (                                 guestfs_vfs_type_args *xdr,
                                 guestfs_protobuf_vfs_type_args *pbc);
void
convert_vfs_type_args_protobuf_to_xdr (                                 guestfs_protobuf_vfs_type_args *pbc,
                                 guestfs_vfs_type_args *xdr);
void
convert_vfs_type_ret_xdr_to_protobuf (                                guestfs_vfs_type_ret *xdr,
                                guestfs_protobuf_vfs_type_ret *pbc);
void
convert_vfs_type_ret_protobuf_to_xdr (                                guestfs_protobuf_vfs_type_ret *pbc,
                                guestfs_vfs_type_ret *xdr);
void
convert_truncate_args_xdr_to_protobuf (                                 guestfs_truncate_args *xdr,
                                 guestfs_protobuf_truncate_args *pbc);
void
convert_truncate_args_protobuf_to_xdr (                                 guestfs_protobuf_truncate_args *pbc,
                                 guestfs_truncate_args *xdr);
void
convert_truncate_size_args_xdr_to_protobuf (                                 guestfs_truncate_size_args *xdr,
                                 guestfs_protobuf_truncate_size_args *pbc);
void
convert_truncate_size_args_protobuf_to_xdr (                                 guestfs_protobuf_truncate_size_args *pbc,
                                 guestfs_truncate_size_args *xdr);
void
convert_utimens_args_xdr_to_protobuf (                                 guestfs_utimens_args *xdr,
                                 guestfs_protobuf_utimens_args *pbc);
void
convert_utimens_args_protobuf_to_xdr (                                 guestfs_protobuf_utimens_args *pbc,
                                 guestfs_utimens_args *xdr);
void
convert_mkdir_mode_args_xdr_to_protobuf (                                 guestfs_mkdir_mode_args *xdr,
                                 guestfs_protobuf_mkdir_mode_args *pbc);
void
convert_mkdir_mode_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdir_mode_args *pbc,
                                 guestfs_mkdir_mode_args *xdr);
void
convert_lchown_args_xdr_to_protobuf (                                 guestfs_lchown_args *xdr,
                                 guestfs_protobuf_lchown_args *pbc);
void
convert_lchown_args_protobuf_to_xdr (                                 guestfs_protobuf_lchown_args *pbc,
                                 guestfs_lchown_args *xdr);
void
convert_internal_lxattrlist_args_xdr_to_protobuf (                                 guestfs_internal_lxattrlist_args *xdr,
                                 guestfs_protobuf_internal_lxattrlist_args *pbc);
void
convert_internal_lxattrlist_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_lxattrlist_args *pbc,
                                 guestfs_internal_lxattrlist_args *xdr);
void
convert_internal_lxattrlist_ret_xdr_to_protobuf (                                guestfs_internal_lxattrlist_ret *xdr,
                                guestfs_protobuf_internal_lxattrlist_ret *pbc);
void
convert_internal_lxattrlist_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_lxattrlist_ret *pbc,
                                guestfs_internal_lxattrlist_ret *xdr);
void
convert_internal_readlinklist_args_xdr_to_protobuf (                                 guestfs_internal_readlinklist_args *xdr,
                                 guestfs_protobuf_internal_readlinklist_args *pbc);
void
convert_internal_readlinklist_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_readlinklist_args *pbc,
                                 guestfs_internal_readlinklist_args *xdr);
void
convert_internal_readlinklist_ret_xdr_to_protobuf (                                guestfs_internal_readlinklist_ret *xdr,
                                guestfs_protobuf_internal_readlinklist_ret *pbc);
void
convert_internal_readlinklist_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_readlinklist_ret *pbc,
                                guestfs_internal_readlinklist_ret *xdr);
void
convert_pread_args_xdr_to_protobuf (                                 guestfs_pread_args *xdr,
                                 guestfs_protobuf_pread_args *pbc);
void
convert_pread_args_protobuf_to_xdr (                                 guestfs_protobuf_pread_args *pbc,
                                 guestfs_pread_args *xdr);
void
convert_pread_ret_xdr_to_protobuf (                                guestfs_pread_ret *xdr,
                                guestfs_protobuf_pread_ret *pbc);
void
convert_pread_ret_protobuf_to_xdr (                                guestfs_protobuf_pread_ret *pbc,
                                guestfs_pread_ret *xdr);
void
convert_part_init_args_xdr_to_protobuf (                                 guestfs_part_init_args *xdr,
                                 guestfs_protobuf_part_init_args *pbc);
void
convert_part_init_args_protobuf_to_xdr (                                 guestfs_protobuf_part_init_args *pbc,
                                 guestfs_part_init_args *xdr);
void
convert_part_add_args_xdr_to_protobuf (                                 guestfs_part_add_args *xdr,
                                 guestfs_protobuf_part_add_args *pbc);
void
convert_part_add_args_protobuf_to_xdr (                                 guestfs_protobuf_part_add_args *pbc,
                                 guestfs_part_add_args *xdr);
void
convert_part_disk_args_xdr_to_protobuf (                                 guestfs_part_disk_args *xdr,
                                 guestfs_protobuf_part_disk_args *pbc);
void
convert_part_disk_args_protobuf_to_xdr (                                 guestfs_protobuf_part_disk_args *pbc,
                                 guestfs_part_disk_args *xdr);
void
convert_part_set_bootable_args_xdr_to_protobuf (                                 guestfs_part_set_bootable_args *xdr,
                                 guestfs_protobuf_part_set_bootable_args *pbc);
void
convert_part_set_bootable_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_bootable_args *pbc,
                                 guestfs_part_set_bootable_args *xdr);
void
convert_part_set_name_args_xdr_to_protobuf (                                 guestfs_part_set_name_args *xdr,
                                 guestfs_protobuf_part_set_name_args *pbc);
void
convert_part_set_name_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_name_args *pbc,
                                 guestfs_part_set_name_args *xdr);
void
convert_part_list_args_xdr_to_protobuf (                                 guestfs_part_list_args *xdr,
                                 guestfs_protobuf_part_list_args *pbc);
void
convert_part_list_args_protobuf_to_xdr (                                 guestfs_protobuf_part_list_args *pbc,
                                 guestfs_part_list_args *xdr);
void
convert_part_list_ret_xdr_to_protobuf (                                guestfs_part_list_ret *xdr,
                                guestfs_protobuf_part_list_ret *pbc);
void
convert_part_list_ret_protobuf_to_xdr (                                guestfs_protobuf_part_list_ret *pbc,
                                guestfs_part_list_ret *xdr);
void
convert_part_get_parttype_args_xdr_to_protobuf (                                 guestfs_part_get_parttype_args *xdr,
                                 guestfs_protobuf_part_get_parttype_args *pbc);
void
convert_part_get_parttype_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_parttype_args *pbc,
                                 guestfs_part_get_parttype_args *xdr);
void
convert_part_get_parttype_ret_xdr_to_protobuf (                                guestfs_part_get_parttype_ret *xdr,
                                guestfs_protobuf_part_get_parttype_ret *pbc);
void
convert_part_get_parttype_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_parttype_ret *pbc,
                                guestfs_part_get_parttype_ret *xdr);
void
convert_fill_args_xdr_to_protobuf (                                 guestfs_fill_args *xdr,
                                 guestfs_protobuf_fill_args *pbc);
void
convert_fill_args_protobuf_to_xdr (                                 guestfs_protobuf_fill_args *pbc,
                                 guestfs_fill_args *xdr);
void
convert_available_args_xdr_to_protobuf (                                 guestfs_available_args *xdr,
                                 guestfs_protobuf_available_args *pbc);
void
convert_available_args_protobuf_to_xdr (                                 guestfs_protobuf_available_args *pbc,
                                 guestfs_available_args *xdr);
void
convert_dd_args_xdr_to_protobuf (                                 guestfs_dd_args *xdr,
                                 guestfs_protobuf_dd_args *pbc);
void
convert_dd_args_protobuf_to_xdr (                                 guestfs_protobuf_dd_args *pbc,
                                 guestfs_dd_args *xdr);
void
convert_filesize_args_xdr_to_protobuf (                                 guestfs_filesize_args *xdr,
                                 guestfs_protobuf_filesize_args *pbc);
void
convert_filesize_args_protobuf_to_xdr (                                 guestfs_protobuf_filesize_args *pbc,
                                 guestfs_filesize_args *xdr);
void
convert_filesize_ret_xdr_to_protobuf (                                guestfs_filesize_ret *xdr,
                                guestfs_protobuf_filesize_ret *pbc);
void
convert_filesize_ret_protobuf_to_xdr (                                guestfs_protobuf_filesize_ret *pbc,
                                guestfs_filesize_ret *xdr);
void
convert_lvrename_args_xdr_to_protobuf (                                 guestfs_lvrename_args *xdr,
                                 guestfs_protobuf_lvrename_args *pbc);
void
convert_lvrename_args_protobuf_to_xdr (                                 guestfs_protobuf_lvrename_args *pbc,
                                 guestfs_lvrename_args *xdr);
void
convert_vgrename_args_xdr_to_protobuf (                                 guestfs_vgrename_args *xdr,
                                 guestfs_protobuf_vgrename_args *pbc);
void
convert_vgrename_args_protobuf_to_xdr (                                 guestfs_protobuf_vgrename_args *pbc,
                                 guestfs_vgrename_args *xdr);
void
convert_initrd_cat_args_xdr_to_protobuf (                                 guestfs_initrd_cat_args *xdr,
                                 guestfs_protobuf_initrd_cat_args *pbc);
void
convert_initrd_cat_args_protobuf_to_xdr (                                 guestfs_protobuf_initrd_cat_args *pbc,
                                 guestfs_initrd_cat_args *xdr);
void
convert_initrd_cat_ret_xdr_to_protobuf (                                guestfs_initrd_cat_ret *xdr,
                                guestfs_protobuf_initrd_cat_ret *pbc);
void
convert_initrd_cat_ret_protobuf_to_xdr (                                guestfs_protobuf_initrd_cat_ret *pbc,
                                guestfs_initrd_cat_ret *xdr);
void
convert_pvuuid_args_xdr_to_protobuf (                                 guestfs_pvuuid_args *xdr,
                                 guestfs_protobuf_pvuuid_args *pbc);
void
convert_pvuuid_args_protobuf_to_xdr (                                 guestfs_protobuf_pvuuid_args *pbc,
                                 guestfs_pvuuid_args *xdr);
void
convert_pvuuid_ret_xdr_to_protobuf (                                guestfs_pvuuid_ret *xdr,
                                guestfs_protobuf_pvuuid_ret *pbc);
void
convert_pvuuid_ret_protobuf_to_xdr (                                guestfs_protobuf_pvuuid_ret *pbc,
                                guestfs_pvuuid_ret *xdr);
void
convert_vguuid_args_xdr_to_protobuf (                                 guestfs_vguuid_args *xdr,
                                 guestfs_protobuf_vguuid_args *pbc);
void
convert_vguuid_args_protobuf_to_xdr (                                 guestfs_protobuf_vguuid_args *pbc,
                                 guestfs_vguuid_args *xdr);
void
convert_vguuid_ret_xdr_to_protobuf (                                guestfs_vguuid_ret *xdr,
                                guestfs_protobuf_vguuid_ret *pbc);
void
convert_vguuid_ret_protobuf_to_xdr (                                guestfs_protobuf_vguuid_ret *pbc,
                                guestfs_vguuid_ret *xdr);
void
convert_lvuuid_args_xdr_to_protobuf (                                 guestfs_lvuuid_args *xdr,
                                 guestfs_protobuf_lvuuid_args *pbc);
void
convert_lvuuid_args_protobuf_to_xdr (                                 guestfs_protobuf_lvuuid_args *pbc,
                                 guestfs_lvuuid_args *xdr);
void
convert_lvuuid_ret_xdr_to_protobuf (                                guestfs_lvuuid_ret *xdr,
                                guestfs_protobuf_lvuuid_ret *pbc);
void
convert_lvuuid_ret_protobuf_to_xdr (                                guestfs_protobuf_lvuuid_ret *pbc,
                                guestfs_lvuuid_ret *xdr);
void
convert_vgpvuuids_args_xdr_to_protobuf (                                 guestfs_vgpvuuids_args *xdr,
                                 guestfs_protobuf_vgpvuuids_args *pbc);
void
convert_vgpvuuids_args_protobuf_to_xdr (                                 guestfs_protobuf_vgpvuuids_args *pbc,
                                 guestfs_vgpvuuids_args *xdr);
void
convert_vgpvuuids_ret_xdr_to_protobuf (                                guestfs_vgpvuuids_ret *xdr,
                                guestfs_protobuf_vgpvuuids_ret *pbc);
void
convert_vgpvuuids_ret_protobuf_to_xdr (                                guestfs_protobuf_vgpvuuids_ret *pbc,
                                guestfs_vgpvuuids_ret *xdr);
void
convert_vglvuuids_args_xdr_to_protobuf (                                 guestfs_vglvuuids_args *xdr,
                                 guestfs_protobuf_vglvuuids_args *pbc);
void
convert_vglvuuids_args_protobuf_to_xdr (                                 guestfs_protobuf_vglvuuids_args *pbc,
                                 guestfs_vglvuuids_args *xdr);
void
convert_vglvuuids_ret_xdr_to_protobuf (                                guestfs_vglvuuids_ret *xdr,
                                guestfs_protobuf_vglvuuids_ret *pbc);
void
convert_vglvuuids_ret_protobuf_to_xdr (                                guestfs_protobuf_vglvuuids_ret *pbc,
                                guestfs_vglvuuids_ret *xdr);
void
convert_copy_size_args_xdr_to_protobuf (                                 guestfs_copy_size_args *xdr,
                                 guestfs_protobuf_copy_size_args *pbc);
void
convert_copy_size_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_size_args *pbc,
                                 guestfs_copy_size_args *xdr);
void
convert_zero_device_args_xdr_to_protobuf (                                 guestfs_zero_device_args *xdr,
                                 guestfs_protobuf_zero_device_args *pbc);
void
convert_zero_device_args_protobuf_to_xdr (                                 guestfs_protobuf_zero_device_args *pbc,
                                 guestfs_zero_device_args *xdr);
void
convert_txz_in_args_xdr_to_protobuf (                                 guestfs_txz_in_args *xdr,
                                 guestfs_protobuf_txz_in_args *pbc);
void
convert_txz_in_args_protobuf_to_xdr (                                 guestfs_protobuf_txz_in_args *pbc,
                                 guestfs_txz_in_args *xdr);
void
convert_txz_out_args_xdr_to_protobuf (                                 guestfs_txz_out_args *xdr,
                                 guestfs_protobuf_txz_out_args *pbc);
void
convert_txz_out_args_protobuf_to_xdr (                                 guestfs_protobuf_txz_out_args *pbc,
                                 guestfs_txz_out_args *xdr);
void
convert_part_del_args_xdr_to_protobuf (                                 guestfs_part_del_args *xdr,
                                 guestfs_protobuf_part_del_args *pbc);
void
convert_part_del_args_protobuf_to_xdr (                                 guestfs_protobuf_part_del_args *pbc,
                                 guestfs_part_del_args *xdr);
void
convert_part_get_bootable_args_xdr_to_protobuf (                                 guestfs_part_get_bootable_args *xdr,
                                 guestfs_protobuf_part_get_bootable_args *pbc);
void
convert_part_get_bootable_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_bootable_args *pbc,
                                 guestfs_part_get_bootable_args *xdr);
void
convert_part_get_bootable_ret_xdr_to_protobuf (                                guestfs_part_get_bootable_ret *xdr,
                                guestfs_protobuf_part_get_bootable_ret *pbc);
void
convert_part_get_bootable_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_bootable_ret *pbc,
                                guestfs_part_get_bootable_ret *xdr);
void
convert_part_get_mbr_id_args_xdr_to_protobuf (                                 guestfs_part_get_mbr_id_args *xdr,
                                 guestfs_protobuf_part_get_mbr_id_args *pbc);
void
convert_part_get_mbr_id_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_mbr_id_args *pbc,
                                 guestfs_part_get_mbr_id_args *xdr);
void
convert_part_get_mbr_id_ret_xdr_to_protobuf (                                guestfs_part_get_mbr_id_ret *xdr,
                                guestfs_protobuf_part_get_mbr_id_ret *pbc);
void
convert_part_get_mbr_id_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_mbr_id_ret *pbc,
                                guestfs_part_get_mbr_id_ret *xdr);
void
convert_part_set_mbr_id_args_xdr_to_protobuf (                                 guestfs_part_set_mbr_id_args *xdr,
                                 guestfs_protobuf_part_set_mbr_id_args *pbc);
void
convert_part_set_mbr_id_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_mbr_id_args *pbc,
                                 guestfs_part_set_mbr_id_args *xdr);
void
convert_checksum_device_args_xdr_to_protobuf (                                 guestfs_checksum_device_args *xdr,
                                 guestfs_protobuf_checksum_device_args *pbc);
void
convert_checksum_device_args_protobuf_to_xdr (                                 guestfs_protobuf_checksum_device_args *pbc,
                                 guestfs_checksum_device_args *xdr);
void
convert_checksum_device_ret_xdr_to_protobuf (                                guestfs_checksum_device_ret *xdr,
                                guestfs_protobuf_checksum_device_ret *pbc);
void
convert_checksum_device_ret_protobuf_to_xdr (                                guestfs_protobuf_checksum_device_ret *pbc,
                                guestfs_checksum_device_ret *xdr);
void
convert_lvresize_free_args_xdr_to_protobuf (                                 guestfs_lvresize_free_args *xdr,
                                 guestfs_protobuf_lvresize_free_args *pbc);
void
convert_lvresize_free_args_protobuf_to_xdr (                                 guestfs_protobuf_lvresize_free_args *pbc,
                                 guestfs_lvresize_free_args *xdr);
void
convert_aug_clear_args_xdr_to_protobuf (                                 guestfs_aug_clear_args *xdr,
                                 guestfs_protobuf_aug_clear_args *pbc);
void
convert_aug_clear_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_clear_args *pbc,
                                 guestfs_aug_clear_args *xdr);
void
convert_get_umask_ret_xdr_to_protobuf (                                guestfs_get_umask_ret *xdr,
                                guestfs_protobuf_get_umask_ret *pbc);
void
convert_get_umask_ret_protobuf_to_xdr (                                guestfs_protobuf_get_umask_ret *pbc,
                                guestfs_get_umask_ret *xdr);
void
convert_debug_upload_args_xdr_to_protobuf (                                 guestfs_debug_upload_args *xdr,
                                 guestfs_protobuf_debug_upload_args *pbc);
void
convert_debug_upload_args_protobuf_to_xdr (                                 guestfs_protobuf_debug_upload_args *pbc,
                                 guestfs_debug_upload_args *xdr);
void
convert_base64_in_args_xdr_to_protobuf (                                 guestfs_base64_in_args *xdr,
                                 guestfs_protobuf_base64_in_args *pbc);
void
convert_base64_in_args_protobuf_to_xdr (                                 guestfs_protobuf_base64_in_args *pbc,
                                 guestfs_base64_in_args *xdr);
void
convert_base64_out_args_xdr_to_protobuf (                                 guestfs_base64_out_args *xdr,
                                 guestfs_protobuf_base64_out_args *pbc);
void
convert_base64_out_args_protobuf_to_xdr (                                 guestfs_protobuf_base64_out_args *pbc,
                                 guestfs_base64_out_args *xdr);
void
convert_checksums_out_args_xdr_to_protobuf (                                 guestfs_checksums_out_args *xdr,
                                 guestfs_protobuf_checksums_out_args *pbc);
void
convert_checksums_out_args_protobuf_to_xdr (                                 guestfs_protobuf_checksums_out_args *pbc,
                                 guestfs_checksums_out_args *xdr);
void
convert_fill_pattern_args_xdr_to_protobuf (                                 guestfs_fill_pattern_args *xdr,
                                 guestfs_protobuf_fill_pattern_args *pbc);
void
convert_fill_pattern_args_protobuf_to_xdr (                                 guestfs_protobuf_fill_pattern_args *pbc,
                                 guestfs_fill_pattern_args *xdr);
void
convert_internal_write_args_xdr_to_protobuf (                                 guestfs_internal_write_args *xdr,
                                 guestfs_protobuf_internal_write_args *pbc);
void
convert_internal_write_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_write_args *pbc,
                                 guestfs_internal_write_args *xdr);
void
convert_pwrite_args_xdr_to_protobuf (                                 guestfs_pwrite_args *xdr,
                                 guestfs_protobuf_pwrite_args *pbc);
void
convert_pwrite_args_protobuf_to_xdr (                                 guestfs_protobuf_pwrite_args *pbc,
                                 guestfs_pwrite_args *xdr);
void
convert_pwrite_ret_xdr_to_protobuf (                                guestfs_pwrite_ret *xdr,
                                guestfs_protobuf_pwrite_ret *pbc);
void
convert_pwrite_ret_protobuf_to_xdr (                                guestfs_protobuf_pwrite_ret *pbc,
                                guestfs_pwrite_ret *xdr);
void
convert_resize2fs_size_args_xdr_to_protobuf (                                 guestfs_resize2fs_size_args *xdr,
                                 guestfs_protobuf_resize2fs_size_args *pbc);
void
convert_resize2fs_size_args_protobuf_to_xdr (                                 guestfs_protobuf_resize2fs_size_args *pbc,
                                 guestfs_resize2fs_size_args *xdr);
void
convert_pvresize_size_args_xdr_to_protobuf (                                 guestfs_pvresize_size_args *xdr,
                                 guestfs_protobuf_pvresize_size_args *pbc);
void
convert_pvresize_size_args_protobuf_to_xdr (                                 guestfs_protobuf_pvresize_size_args *pbc,
                                 guestfs_pvresize_size_args *xdr);
void
convert_ntfsresize_size_args_xdr_to_protobuf (                                 guestfs_ntfsresize_size_args *xdr,
                                 guestfs_protobuf_ntfsresize_size_args *pbc);
void
convert_ntfsresize_size_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsresize_size_args *pbc,
                                 guestfs_ntfsresize_size_args *xdr);
void
convert_available_all_groups_ret_xdr_to_protobuf (                                guestfs_available_all_groups_ret *xdr,
                                guestfs_protobuf_available_all_groups_ret *pbc);
void
convert_available_all_groups_ret_protobuf_to_xdr (                                guestfs_protobuf_available_all_groups_ret *pbc,
                                guestfs_available_all_groups_ret *xdr);
void
convert_fallocate64_args_xdr_to_protobuf (                                 guestfs_fallocate64_args *xdr,
                                 guestfs_protobuf_fallocate64_args *pbc);
void
convert_fallocate64_args_protobuf_to_xdr (                                 guestfs_protobuf_fallocate64_args *pbc,
                                 guestfs_fallocate64_args *xdr);
void
convert_vfs_label_args_xdr_to_protobuf (                                 guestfs_vfs_label_args *xdr,
                                 guestfs_protobuf_vfs_label_args *pbc);
void
convert_vfs_label_args_protobuf_to_xdr (                                 guestfs_protobuf_vfs_label_args *pbc,
                                 guestfs_vfs_label_args *xdr);
void
convert_vfs_label_ret_xdr_to_protobuf (                                guestfs_vfs_label_ret *xdr,
                                guestfs_protobuf_vfs_label_ret *pbc);
void
convert_vfs_label_ret_protobuf_to_xdr (                                guestfs_protobuf_vfs_label_ret *pbc,
                                guestfs_vfs_label_ret *xdr);
void
convert_vfs_uuid_args_xdr_to_protobuf (                                 guestfs_vfs_uuid_args *xdr,
                                 guestfs_protobuf_vfs_uuid_args *pbc);
void
convert_vfs_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_vfs_uuid_args *pbc,
                                 guestfs_vfs_uuid_args *xdr);
void
convert_vfs_uuid_ret_xdr_to_protobuf (                                guestfs_vfs_uuid_ret *xdr,
                                guestfs_protobuf_vfs_uuid_ret *pbc);
void
convert_vfs_uuid_ret_protobuf_to_xdr (                                guestfs_protobuf_vfs_uuid_ret *pbc,
                                guestfs_vfs_uuid_ret *xdr);
void
convert_lvm_set_filter_args_xdr_to_protobuf (                                 guestfs_lvm_set_filter_args *xdr,
                                 guestfs_protobuf_lvm_set_filter_args *pbc);
void
convert_lvm_set_filter_args_protobuf_to_xdr (                                 guestfs_protobuf_lvm_set_filter_args *pbc,
                                 guestfs_lvm_set_filter_args *xdr);
void
convert_luks_open_args_xdr_to_protobuf (                                 guestfs_luks_open_args *xdr,
                                 guestfs_protobuf_luks_open_args *pbc);
void
convert_luks_open_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_open_args *pbc,
                                 guestfs_luks_open_args *xdr);
void
convert_luks_open_ro_args_xdr_to_protobuf (                                 guestfs_luks_open_ro_args *xdr,
                                 guestfs_protobuf_luks_open_ro_args *pbc);
void
convert_luks_open_ro_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_open_ro_args *pbc,
                                 guestfs_luks_open_ro_args *xdr);
void
convert_luks_close_args_xdr_to_protobuf (                                 guestfs_luks_close_args *xdr,
                                 guestfs_protobuf_luks_close_args *pbc);
void
convert_luks_close_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_close_args *pbc,
                                 guestfs_luks_close_args *xdr);
void
convert_luks_format_args_xdr_to_protobuf (                                 guestfs_luks_format_args *xdr,
                                 guestfs_protobuf_luks_format_args *pbc);
void
convert_luks_format_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_format_args *pbc,
                                 guestfs_luks_format_args *xdr);
void
convert_luks_format_cipher_args_xdr_to_protobuf (                                 guestfs_luks_format_cipher_args *xdr,
                                 guestfs_protobuf_luks_format_cipher_args *pbc);
void
convert_luks_format_cipher_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_format_cipher_args *pbc,
                                 guestfs_luks_format_cipher_args *xdr);
void
convert_luks_add_key_args_xdr_to_protobuf (                                 guestfs_luks_add_key_args *xdr,
                                 guestfs_protobuf_luks_add_key_args *pbc);
void
convert_luks_add_key_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_add_key_args *pbc,
                                 guestfs_luks_add_key_args *xdr);
void
convert_luks_kill_slot_args_xdr_to_protobuf (                                 guestfs_luks_kill_slot_args *xdr,
                                 guestfs_protobuf_luks_kill_slot_args *pbc);
void
convert_luks_kill_slot_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_kill_slot_args *pbc,
                                 guestfs_luks_kill_slot_args *xdr);
void
convert_is_lv_args_xdr_to_protobuf (                                 guestfs_is_lv_args *xdr,
                                 guestfs_protobuf_is_lv_args *pbc);
void
convert_is_lv_args_protobuf_to_xdr (                                 guestfs_protobuf_is_lv_args *pbc,
                                 guestfs_is_lv_args *xdr);
void
convert_is_lv_ret_xdr_to_protobuf (                                guestfs_is_lv_ret *xdr,
                                guestfs_protobuf_is_lv_ret *pbc);
void
convert_is_lv_ret_protobuf_to_xdr (                                guestfs_protobuf_is_lv_ret *pbc,
                                guestfs_is_lv_ret *xdr);
void
convert_findfs_uuid_args_xdr_to_protobuf (                                 guestfs_findfs_uuid_args *xdr,
                                 guestfs_protobuf_findfs_uuid_args *pbc);
void
convert_findfs_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_findfs_uuid_args *pbc,
                                 guestfs_findfs_uuid_args *xdr);
void
convert_findfs_uuid_ret_xdr_to_protobuf (                                guestfs_findfs_uuid_ret *xdr,
                                guestfs_protobuf_findfs_uuid_ret *pbc);
void
convert_findfs_uuid_ret_protobuf_to_xdr (                                guestfs_protobuf_findfs_uuid_ret *pbc,
                                guestfs_findfs_uuid_ret *xdr);
void
convert_findfs_label_args_xdr_to_protobuf (                                 guestfs_findfs_label_args *xdr,
                                 guestfs_protobuf_findfs_label_args *pbc);
void
convert_findfs_label_args_protobuf_to_xdr (                                 guestfs_protobuf_findfs_label_args *pbc,
                                 guestfs_findfs_label_args *xdr);
void
convert_findfs_label_ret_xdr_to_protobuf (                                guestfs_findfs_label_ret *xdr,
                                guestfs_protobuf_findfs_label_ret *pbc);
void
convert_findfs_label_ret_protobuf_to_xdr (                                guestfs_protobuf_findfs_label_ret *pbc,
                                guestfs_findfs_label_ret *xdr);
void
convert_is_chardev_args_xdr_to_protobuf (                                 guestfs_is_chardev_args *xdr,
                                 guestfs_protobuf_is_chardev_args *pbc);
void
convert_is_chardev_args_protobuf_to_xdr (                                 guestfs_protobuf_is_chardev_args *pbc,
                                 guestfs_is_chardev_args *xdr);
void
convert_is_chardev_ret_xdr_to_protobuf (                                guestfs_is_chardev_ret *xdr,
                                guestfs_protobuf_is_chardev_ret *pbc);
void
convert_is_chardev_ret_protobuf_to_xdr (                                guestfs_protobuf_is_chardev_ret *pbc,
                                guestfs_is_chardev_ret *xdr);
void
convert_is_blockdev_args_xdr_to_protobuf (                                 guestfs_is_blockdev_args *xdr,
                                 guestfs_protobuf_is_blockdev_args *pbc);
void
convert_is_blockdev_args_protobuf_to_xdr (                                 guestfs_protobuf_is_blockdev_args *pbc,
                                 guestfs_is_blockdev_args *xdr);
void
convert_is_blockdev_ret_xdr_to_protobuf (                                guestfs_is_blockdev_ret *xdr,
                                guestfs_protobuf_is_blockdev_ret *pbc);
void
convert_is_blockdev_ret_protobuf_to_xdr (                                guestfs_protobuf_is_blockdev_ret *pbc,
                                guestfs_is_blockdev_ret *xdr);
void
convert_is_fifo_args_xdr_to_protobuf (                                 guestfs_is_fifo_args *xdr,
                                 guestfs_protobuf_is_fifo_args *pbc);
void
convert_is_fifo_args_protobuf_to_xdr (                                 guestfs_protobuf_is_fifo_args *pbc,
                                 guestfs_is_fifo_args *xdr);
void
convert_is_fifo_ret_xdr_to_protobuf (                                guestfs_is_fifo_ret *xdr,
                                guestfs_protobuf_is_fifo_ret *pbc);
void
convert_is_fifo_ret_protobuf_to_xdr (                                guestfs_protobuf_is_fifo_ret *pbc,
                                guestfs_is_fifo_ret *xdr);
void
convert_is_symlink_args_xdr_to_protobuf (                                 guestfs_is_symlink_args *xdr,
                                 guestfs_protobuf_is_symlink_args *pbc);
void
convert_is_symlink_args_protobuf_to_xdr (                                 guestfs_protobuf_is_symlink_args *pbc,
                                 guestfs_is_symlink_args *xdr);
void
convert_is_symlink_ret_xdr_to_protobuf (                                guestfs_is_symlink_ret *xdr,
                                guestfs_protobuf_is_symlink_ret *pbc);
void
convert_is_symlink_ret_protobuf_to_xdr (                                guestfs_protobuf_is_symlink_ret *pbc,
                                guestfs_is_symlink_ret *xdr);
void
convert_is_socket_args_xdr_to_protobuf (                                 guestfs_is_socket_args *xdr,
                                 guestfs_protobuf_is_socket_args *pbc);
void
convert_is_socket_args_protobuf_to_xdr (                                 guestfs_protobuf_is_socket_args *pbc,
                                 guestfs_is_socket_args *xdr);
void
convert_is_socket_ret_xdr_to_protobuf (                                guestfs_is_socket_ret *xdr,
                                guestfs_protobuf_is_socket_ret *pbc);
void
convert_is_socket_ret_protobuf_to_xdr (                                guestfs_protobuf_is_socket_ret *pbc,
                                guestfs_is_socket_ret *xdr);
void
convert_part_to_dev_args_xdr_to_protobuf (                                 guestfs_part_to_dev_args *xdr,
                                 guestfs_protobuf_part_to_dev_args *pbc);
void
convert_part_to_dev_args_protobuf_to_xdr (                                 guestfs_protobuf_part_to_dev_args *pbc,
                                 guestfs_part_to_dev_args *xdr);
void
convert_part_to_dev_ret_xdr_to_protobuf (                                guestfs_part_to_dev_ret *xdr,
                                guestfs_protobuf_part_to_dev_ret *pbc);
void
convert_part_to_dev_ret_protobuf_to_xdr (                                guestfs_protobuf_part_to_dev_ret *pbc,
                                guestfs_part_to_dev_ret *xdr);
void
convert_upload_offset_args_xdr_to_protobuf (                                 guestfs_upload_offset_args *xdr,
                                 guestfs_protobuf_upload_offset_args *pbc);
void
convert_upload_offset_args_protobuf_to_xdr (                                 guestfs_protobuf_upload_offset_args *pbc,
                                 guestfs_upload_offset_args *xdr);
void
convert_download_offset_args_xdr_to_protobuf (                                 guestfs_download_offset_args *xdr,
                                 guestfs_protobuf_download_offset_args *pbc);
void
convert_download_offset_args_protobuf_to_xdr (                                 guestfs_protobuf_download_offset_args *pbc,
                                 guestfs_download_offset_args *xdr);
void
convert_pwrite_device_args_xdr_to_protobuf (                                 guestfs_pwrite_device_args *xdr,
                                 guestfs_protobuf_pwrite_device_args *pbc);
void
convert_pwrite_device_args_protobuf_to_xdr (                                 guestfs_protobuf_pwrite_device_args *pbc,
                                 guestfs_pwrite_device_args *xdr);
void
convert_pwrite_device_ret_xdr_to_protobuf (                                guestfs_pwrite_device_ret *xdr,
                                guestfs_protobuf_pwrite_device_ret *pbc);
void
convert_pwrite_device_ret_protobuf_to_xdr (                                guestfs_protobuf_pwrite_device_ret *pbc,
                                guestfs_pwrite_device_ret *xdr);
void
convert_pread_device_args_xdr_to_protobuf (                                 guestfs_pread_device_args *xdr,
                                 guestfs_protobuf_pread_device_args *pbc);
void
convert_pread_device_args_protobuf_to_xdr (                                 guestfs_protobuf_pread_device_args *pbc,
                                 guestfs_pread_device_args *xdr);
void
convert_pread_device_ret_xdr_to_protobuf (                                guestfs_pread_device_ret *xdr,
                                guestfs_protobuf_pread_device_ret *pbc);
void
convert_pread_device_ret_protobuf_to_xdr (                                guestfs_protobuf_pread_device_ret *pbc,
                                guestfs_pread_device_ret *xdr);
void
convert_lvm_canonical_lv_name_args_xdr_to_protobuf (                                 guestfs_lvm_canonical_lv_name_args *xdr,
                                 guestfs_protobuf_lvm_canonical_lv_name_args *pbc);
void
convert_lvm_canonical_lv_name_args_protobuf_to_xdr (                                 guestfs_protobuf_lvm_canonical_lv_name_args *pbc,
                                 guestfs_lvm_canonical_lv_name_args *xdr);
void
convert_lvm_canonical_lv_name_ret_xdr_to_protobuf (                                guestfs_lvm_canonical_lv_name_ret *xdr,
                                guestfs_protobuf_lvm_canonical_lv_name_ret *pbc);
void
convert_lvm_canonical_lv_name_ret_protobuf_to_xdr (                                guestfs_protobuf_lvm_canonical_lv_name_ret *pbc,
                                guestfs_lvm_canonical_lv_name_ret *xdr);
void
convert_mkfs_args_xdr_to_protobuf (                                 guestfs_mkfs_args *xdr,
                                 guestfs_protobuf_mkfs_args *pbc);
void
convert_mkfs_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfs_args *pbc,
                                 guestfs_mkfs_args *xdr);
void
convert_getxattr_args_xdr_to_protobuf (                                 guestfs_getxattr_args *xdr,
                                 guestfs_protobuf_getxattr_args *pbc);
void
convert_getxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_getxattr_args *pbc,
                                 guestfs_getxattr_args *xdr);
void
convert_getxattr_ret_xdr_to_protobuf (                                guestfs_getxattr_ret *xdr,
                                guestfs_protobuf_getxattr_ret *pbc);
void
convert_getxattr_ret_protobuf_to_xdr (                                guestfs_protobuf_getxattr_ret *pbc,
                                guestfs_getxattr_ret *xdr);
void
convert_lgetxattr_args_xdr_to_protobuf (                                 guestfs_lgetxattr_args *xdr,
                                 guestfs_protobuf_lgetxattr_args *pbc);
void
convert_lgetxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_lgetxattr_args *pbc,
                                 guestfs_lgetxattr_args *xdr);
void
convert_lgetxattr_ret_xdr_to_protobuf (                                guestfs_lgetxattr_ret *xdr,
                                guestfs_protobuf_lgetxattr_ret *pbc);
void
convert_lgetxattr_ret_protobuf_to_xdr (                                guestfs_protobuf_lgetxattr_ret *pbc,
                                guestfs_lgetxattr_ret *xdr);
void
convert_resize2fs_mm_args_xdr_to_protobuf (                                 guestfs_resize2fs_mm_args *xdr,
                                 guestfs_protobuf_resize2fs_mm_args *pbc);
void
convert_resize2fs_mm_args_protobuf_to_xdr (                                 guestfs_protobuf_resize2fs_mm_args *pbc,
                                 guestfs_resize2fs_mm_args *xdr);
void
convert_is_zero_args_xdr_to_protobuf (                                 guestfs_is_zero_args *xdr,
                                 guestfs_protobuf_is_zero_args *pbc);
void
convert_is_zero_args_protobuf_to_xdr (                                 guestfs_protobuf_is_zero_args *pbc,
                                 guestfs_is_zero_args *xdr);
void
convert_is_zero_ret_xdr_to_protobuf (                                guestfs_is_zero_ret *xdr,
                                guestfs_protobuf_is_zero_ret *pbc);
void
convert_is_zero_ret_protobuf_to_xdr (                                guestfs_protobuf_is_zero_ret *pbc,
                                guestfs_is_zero_ret *xdr);
void
convert_is_zero_device_args_xdr_to_protobuf (                                 guestfs_is_zero_device_args *xdr,
                                 guestfs_protobuf_is_zero_device_args *pbc);
void
convert_is_zero_device_args_protobuf_to_xdr (                                 guestfs_protobuf_is_zero_device_args *pbc,
                                 guestfs_is_zero_device_args *xdr);
void
convert_is_zero_device_ret_xdr_to_protobuf (                                guestfs_is_zero_device_ret *xdr,
                                guestfs_protobuf_is_zero_device_ret *pbc);
void
convert_is_zero_device_ret_protobuf_to_xdr (                                guestfs_protobuf_is_zero_device_ret *pbc,
                                guestfs_is_zero_device_ret *xdr);
void
convert_list9p_ret_xdr_to_protobuf (                                guestfs_list9p_ret *xdr,
                                guestfs_protobuf_list9p_ret *pbc);
void
convert_list9p_ret_protobuf_to_xdr (                                guestfs_protobuf_list9p_ret *pbc,
                                guestfs_list9p_ret *xdr);
void
convert_mount9p_args_xdr_to_protobuf (                                 guestfs_mount9p_args *xdr,
                                 guestfs_protobuf_mount9p_args *pbc);
void
convert_mount9p_args_protobuf_to_xdr (                                 guestfs_protobuf_mount9p_args *pbc,
                                 guestfs_mount9p_args *xdr);
void
convert_list_dm_devices_ret_xdr_to_protobuf (                                guestfs_list_dm_devices_ret *xdr,
                                guestfs_protobuf_list_dm_devices_ret *pbc);
void
convert_list_dm_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_list_dm_devices_ret *pbc,
                                guestfs_list_dm_devices_ret *xdr);
void
convert_ntfsresize_args_xdr_to_protobuf (                                 guestfs_ntfsresize_args *xdr,
                                 guestfs_protobuf_ntfsresize_args *pbc);
void
convert_ntfsresize_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsresize_args *pbc,
                                 guestfs_ntfsresize_args *xdr);
void
convert_btrfs_filesystem_resize_args_xdr_to_protobuf (                                 guestfs_btrfs_filesystem_resize_args *xdr,
                                 guestfs_protobuf_btrfs_filesystem_resize_args *pbc);
void
convert_btrfs_filesystem_resize_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_filesystem_resize_args *pbc,
                                 guestfs_btrfs_filesystem_resize_args *xdr);
void
convert_internal_write_append_args_xdr_to_protobuf (                                 guestfs_internal_write_append_args *xdr,
                                 guestfs_protobuf_internal_write_append_args *pbc);
void
convert_internal_write_append_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_write_append_args *pbc,
                                 guestfs_internal_write_append_args *xdr);
void
convert_compress_out_args_xdr_to_protobuf (                                 guestfs_compress_out_args *xdr,
                                 guestfs_protobuf_compress_out_args *pbc);
void
convert_compress_out_args_protobuf_to_xdr (                                 guestfs_protobuf_compress_out_args *pbc,
                                 guestfs_compress_out_args *xdr);
void
convert_compress_device_out_args_xdr_to_protobuf (                                 guestfs_compress_device_out_args *xdr,
                                 guestfs_protobuf_compress_device_out_args *pbc);
void
convert_compress_device_out_args_protobuf_to_xdr (                                 guestfs_protobuf_compress_device_out_args *pbc,
                                 guestfs_compress_device_out_args *xdr);
void
convert_part_to_partnum_args_xdr_to_protobuf (                                 guestfs_part_to_partnum_args *xdr,
                                 guestfs_protobuf_part_to_partnum_args *pbc);
void
convert_part_to_partnum_args_protobuf_to_xdr (                                 guestfs_protobuf_part_to_partnum_args *pbc,
                                 guestfs_part_to_partnum_args *xdr);
void
convert_part_to_partnum_ret_xdr_to_protobuf (                                guestfs_part_to_partnum_ret *xdr,
                                guestfs_protobuf_part_to_partnum_ret *pbc);
void
convert_part_to_partnum_ret_protobuf_to_xdr (                                guestfs_protobuf_part_to_partnum_ret *pbc,
                                guestfs_part_to_partnum_ret *xdr);
void
convert_copy_device_to_device_args_xdr_to_protobuf (                                 guestfs_copy_device_to_device_args *xdr,
                                 guestfs_protobuf_copy_device_to_device_args *pbc);
void
convert_copy_device_to_device_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_device_to_device_args *pbc,
                                 guestfs_copy_device_to_device_args *xdr);
void
convert_copy_device_to_file_args_xdr_to_protobuf (                                 guestfs_copy_device_to_file_args *xdr,
                                 guestfs_protobuf_copy_device_to_file_args *pbc);
void
convert_copy_device_to_file_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_device_to_file_args *pbc,
                                 guestfs_copy_device_to_file_args *xdr);
void
convert_copy_file_to_device_args_xdr_to_protobuf (                                 guestfs_copy_file_to_device_args *xdr,
                                 guestfs_protobuf_copy_file_to_device_args *pbc);
void
convert_copy_file_to_device_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_file_to_device_args *pbc,
                                 guestfs_copy_file_to_device_args *xdr);
void
convert_copy_file_to_file_args_xdr_to_protobuf (                                 guestfs_copy_file_to_file_args *xdr,
                                 guestfs_protobuf_copy_file_to_file_args *pbc);
void
convert_copy_file_to_file_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_file_to_file_args *pbc,
                                 guestfs_copy_file_to_file_args *xdr);
void
convert_tune2fs_args_xdr_to_protobuf (                                 guestfs_tune2fs_args *xdr,
                                 guestfs_protobuf_tune2fs_args *pbc);
void
convert_tune2fs_args_protobuf_to_xdr (                                 guestfs_protobuf_tune2fs_args *pbc,
                                 guestfs_tune2fs_args *xdr);
void
convert_md_create_args_xdr_to_protobuf (                                 guestfs_md_create_args *xdr,
                                 guestfs_protobuf_md_create_args *pbc);
void
convert_md_create_args_protobuf_to_xdr (                                 guestfs_protobuf_md_create_args *pbc,
                                 guestfs_md_create_args *xdr);
void
convert_list_md_devices_ret_xdr_to_protobuf (                                guestfs_list_md_devices_ret *xdr,
                                guestfs_protobuf_list_md_devices_ret *pbc);
void
convert_list_md_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_list_md_devices_ret *pbc,
                                guestfs_list_md_devices_ret *xdr);
void
convert_md_detail_args_xdr_to_protobuf (                                 guestfs_md_detail_args *xdr,
                                 guestfs_protobuf_md_detail_args *pbc);
void
convert_md_detail_args_protobuf_to_xdr (                                 guestfs_protobuf_md_detail_args *pbc,
                                 guestfs_md_detail_args *xdr);
void
convert_md_detail_ret_xdr_to_protobuf (                                guestfs_md_detail_ret *xdr,
                                guestfs_protobuf_md_detail_ret *pbc);
void
convert_md_detail_ret_protobuf_to_xdr (                                guestfs_protobuf_md_detail_ret *pbc,
                                guestfs_md_detail_ret *xdr);
void
convert_md_stop_args_xdr_to_protobuf (                                 guestfs_md_stop_args *xdr,
                                 guestfs_protobuf_md_stop_args *pbc);
void
convert_md_stop_args_protobuf_to_xdr (                                 guestfs_protobuf_md_stop_args *pbc,
                                 guestfs_md_stop_args *xdr);
void
convert_blkid_args_xdr_to_protobuf (                                 guestfs_blkid_args *xdr,
                                 guestfs_protobuf_blkid_args *pbc);
void
convert_blkid_args_protobuf_to_xdr (                                 guestfs_protobuf_blkid_args *pbc,
                                 guestfs_blkid_args *xdr);
void
convert_blkid_ret_xdr_to_protobuf (                                guestfs_blkid_ret *xdr,
                                guestfs_protobuf_blkid_ret *pbc);
void
convert_blkid_ret_protobuf_to_xdr (                                guestfs_protobuf_blkid_ret *pbc,
                                guestfs_blkid_ret *xdr);
void
convert_e2fsck_args_xdr_to_protobuf (                                 guestfs_e2fsck_args *xdr,
                                 guestfs_protobuf_e2fsck_args *pbc);
void
convert_e2fsck_args_protobuf_to_xdr (                                 guestfs_protobuf_e2fsck_args *pbc,
                                 guestfs_e2fsck_args *xdr);
void
convert_llz_args_xdr_to_protobuf (                                 guestfs_llz_args *xdr,
                                 guestfs_protobuf_llz_args *pbc);
void
convert_llz_args_protobuf_to_xdr (                                 guestfs_protobuf_llz_args *pbc,
                                 guestfs_llz_args *xdr);
void
convert_llz_ret_xdr_to_protobuf (                                guestfs_llz_ret *xdr,
                                guestfs_protobuf_llz_ret *pbc);
void
convert_llz_ret_protobuf_to_xdr (                                guestfs_protobuf_llz_ret *pbc,
                                guestfs_llz_ret *xdr);
void
convert_wipefs_args_xdr_to_protobuf (                                 guestfs_wipefs_args *xdr,
                                 guestfs_protobuf_wipefs_args *pbc);
void
convert_wipefs_args_protobuf_to_xdr (                                 guestfs_protobuf_wipefs_args *pbc,
                                 guestfs_wipefs_args *xdr);
void
convert_ntfsfix_args_xdr_to_protobuf (                                 guestfs_ntfsfix_args *xdr,
                                 guestfs_protobuf_ntfsfix_args *pbc);
void
convert_ntfsfix_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsfix_args *pbc,
                                 guestfs_ntfsfix_args *xdr);
void
convert_ntfsclone_out_args_xdr_to_protobuf (                                 guestfs_ntfsclone_out_args *xdr,
                                 guestfs_protobuf_ntfsclone_out_args *pbc);
void
convert_ntfsclone_out_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsclone_out_args *pbc,
                                 guestfs_ntfsclone_out_args *xdr);
void
convert_ntfsclone_in_args_xdr_to_protobuf (                                 guestfs_ntfsclone_in_args *xdr,
                                 guestfs_protobuf_ntfsclone_in_args *pbc);
void
convert_ntfsclone_in_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsclone_in_args *pbc,
                                 guestfs_ntfsclone_in_args *xdr);
void
convert_set_label_args_xdr_to_protobuf (                                 guestfs_set_label_args *xdr,
                                 guestfs_protobuf_set_label_args *pbc);
void
convert_set_label_args_protobuf_to_xdr (                                 guestfs_protobuf_set_label_args *pbc,
                                 guestfs_set_label_args *xdr);
void
convert_zero_free_space_args_xdr_to_protobuf (                                 guestfs_zero_free_space_args *xdr,
                                 guestfs_protobuf_zero_free_space_args *pbc);
void
convert_zero_free_space_args_protobuf_to_xdr (                                 guestfs_protobuf_zero_free_space_args *pbc,
                                 guestfs_zero_free_space_args *xdr);
void
convert_lvcreate_free_args_xdr_to_protobuf (                                 guestfs_lvcreate_free_args *xdr,
                                 guestfs_protobuf_lvcreate_free_args *pbc);
void
convert_lvcreate_free_args_protobuf_to_xdr (                                 guestfs_protobuf_lvcreate_free_args *pbc,
                                 guestfs_lvcreate_free_args *xdr);
void
convert_isoinfo_device_args_xdr_to_protobuf (                                 guestfs_isoinfo_device_args *xdr,
                                 guestfs_protobuf_isoinfo_device_args *pbc);
void
convert_isoinfo_device_args_protobuf_to_xdr (                                 guestfs_protobuf_isoinfo_device_args *pbc,
                                 guestfs_isoinfo_device_args *xdr);
void
convert_isoinfo_device_ret_xdr_to_protobuf (                                guestfs_isoinfo_device_ret *xdr,
                                guestfs_protobuf_isoinfo_device_ret *pbc);
void
convert_isoinfo_device_ret_protobuf_to_xdr (                                guestfs_protobuf_isoinfo_device_ret *pbc,
                                guestfs_isoinfo_device_ret *xdr);
void
convert_isoinfo_args_xdr_to_protobuf (                                 guestfs_isoinfo_args *xdr,
                                 guestfs_protobuf_isoinfo_args *pbc);
void
convert_isoinfo_args_protobuf_to_xdr (                                 guestfs_protobuf_isoinfo_args *pbc,
                                 guestfs_isoinfo_args *xdr);
void
convert_isoinfo_ret_xdr_to_protobuf (                                guestfs_isoinfo_ret *xdr,
                                guestfs_protobuf_isoinfo_ret *pbc);
void
convert_isoinfo_ret_protobuf_to_xdr (                                guestfs_protobuf_isoinfo_ret *pbc,
                                guestfs_isoinfo_ret *xdr);
void
convert_vgmeta_args_xdr_to_protobuf (                                 guestfs_vgmeta_args *xdr,
                                 guestfs_protobuf_vgmeta_args *pbc);
void
convert_vgmeta_args_protobuf_to_xdr (                                 guestfs_protobuf_vgmeta_args *pbc,
                                 guestfs_vgmeta_args *xdr);
void
convert_vgmeta_ret_xdr_to_protobuf (                                guestfs_vgmeta_ret *xdr,
                                guestfs_protobuf_vgmeta_ret *pbc);
void
convert_vgmeta_ret_protobuf_to_xdr (                                guestfs_protobuf_vgmeta_ret *pbc,
                                guestfs_vgmeta_ret *xdr);
void
convert_md_stat_args_xdr_to_protobuf (                                 guestfs_md_stat_args *xdr,
                                 guestfs_protobuf_md_stat_args *pbc);
void
convert_md_stat_args_protobuf_to_xdr (                                 guestfs_protobuf_md_stat_args *pbc,
                                 guestfs_md_stat_args *xdr);
void
convert_md_stat_ret_xdr_to_protobuf (                                guestfs_md_stat_ret *xdr,
                                guestfs_protobuf_md_stat_ret *pbc);
void
convert_md_stat_ret_protobuf_to_xdr (                                guestfs_protobuf_md_stat_ret *pbc,
                                guestfs_md_stat_ret *xdr);
void
convert_mkfs_btrfs_args_xdr_to_protobuf (                                 guestfs_mkfs_btrfs_args *xdr,
                                 guestfs_protobuf_mkfs_btrfs_args *pbc);
void
convert_mkfs_btrfs_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfs_btrfs_args *pbc,
                                 guestfs_mkfs_btrfs_args *xdr);
void
convert_get_e2attrs_args_xdr_to_protobuf (                                 guestfs_get_e2attrs_args *xdr,
                                 guestfs_protobuf_get_e2attrs_args *pbc);
void
convert_get_e2attrs_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2attrs_args *pbc,
                                 guestfs_get_e2attrs_args *xdr);
void
convert_get_e2attrs_ret_xdr_to_protobuf (                                guestfs_get_e2attrs_ret *xdr,
                                guestfs_protobuf_get_e2attrs_ret *pbc);
void
convert_get_e2attrs_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2attrs_ret *pbc,
                                guestfs_get_e2attrs_ret *xdr);
void
convert_set_e2attrs_args_xdr_to_protobuf (                                 guestfs_set_e2attrs_args *xdr,
                                 guestfs_protobuf_set_e2attrs_args *pbc);
void
convert_set_e2attrs_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2attrs_args *pbc,
                                 guestfs_set_e2attrs_args *xdr);
void
convert_get_e2generation_args_xdr_to_protobuf (                                 guestfs_get_e2generation_args *xdr,
                                 guestfs_protobuf_get_e2generation_args *pbc);
void
convert_get_e2generation_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2generation_args *pbc,
                                 guestfs_get_e2generation_args *xdr);
void
convert_get_e2generation_ret_xdr_to_protobuf (                                guestfs_get_e2generation_ret *xdr,
                                guestfs_protobuf_get_e2generation_ret *pbc);
void
convert_get_e2generation_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2generation_ret *pbc,
                                guestfs_get_e2generation_ret *xdr);
void
convert_set_e2generation_args_xdr_to_protobuf (                                 guestfs_set_e2generation_args *xdr,
                                 guestfs_protobuf_set_e2generation_args *pbc);
void
convert_set_e2generation_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2generation_args *pbc,
                                 guestfs_set_e2generation_args *xdr);
void
convert_btrfs_subvolume_snapshot_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_snapshot_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_snapshot_args *pbc);
void
convert_btrfs_subvolume_snapshot_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_snapshot_args *pbc,
                                 guestfs_btrfs_subvolume_snapshot_args *xdr);
void
convert_btrfs_subvolume_delete_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_delete_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_delete_args *pbc);
void
convert_btrfs_subvolume_delete_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_delete_args *pbc,
                                 guestfs_btrfs_subvolume_delete_args *xdr);
void
convert_btrfs_subvolume_create_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_create_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_create_args *pbc);
void
convert_btrfs_subvolume_create_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_create_args *pbc,
                                 guestfs_btrfs_subvolume_create_args *xdr);
void
convert_btrfs_subvolume_list_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_list_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_list_args *pbc);
void
convert_btrfs_subvolume_list_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_list_args *pbc,
                                 guestfs_btrfs_subvolume_list_args *xdr);
void
convert_btrfs_subvolume_list_ret_xdr_to_protobuf (                                guestfs_btrfs_subvolume_list_ret *xdr,
                                guestfs_protobuf_btrfs_subvolume_list_ret *pbc);
void
convert_btrfs_subvolume_list_ret_protobuf_to_xdr (                                guestfs_protobuf_btrfs_subvolume_list_ret *pbc,
                                guestfs_btrfs_subvolume_list_ret *xdr);
void
convert_btrfs_subvolume_set_default_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_set_default_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_set_default_args *pbc);
void
convert_btrfs_subvolume_set_default_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_set_default_args *pbc,
                                 guestfs_btrfs_subvolume_set_default_args *xdr);
void
convert_btrfs_filesystem_sync_args_xdr_to_protobuf (                                 guestfs_btrfs_filesystem_sync_args *xdr,
                                 guestfs_protobuf_btrfs_filesystem_sync_args *pbc);
void
convert_btrfs_filesystem_sync_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_filesystem_sync_args *pbc,
                                 guestfs_btrfs_filesystem_sync_args *xdr);
void
convert_btrfs_filesystem_balance_args_xdr_to_protobuf (                                 guestfs_btrfs_filesystem_balance_args *xdr,
                                 guestfs_protobuf_btrfs_filesystem_balance_args *pbc);
void
convert_btrfs_filesystem_balance_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_filesystem_balance_args *pbc,
                                 guestfs_btrfs_filesystem_balance_args *xdr);
void
convert_btrfs_device_add_args_xdr_to_protobuf (                                 guestfs_btrfs_device_add_args *xdr,
                                 guestfs_protobuf_btrfs_device_add_args *pbc);
void
convert_btrfs_device_add_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_device_add_args *pbc,
                                 guestfs_btrfs_device_add_args *xdr);
void
convert_btrfs_device_delete_args_xdr_to_protobuf (                                 guestfs_btrfs_device_delete_args *xdr,
                                 guestfs_protobuf_btrfs_device_delete_args *pbc);
void
convert_btrfs_device_delete_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_device_delete_args *pbc,
                                 guestfs_btrfs_device_delete_args *xdr);
void
convert_btrfs_set_seeding_args_xdr_to_protobuf (                                 guestfs_btrfs_set_seeding_args *xdr,
                                 guestfs_protobuf_btrfs_set_seeding_args *pbc);
void
convert_btrfs_set_seeding_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_set_seeding_args *pbc,
                                 guestfs_btrfs_set_seeding_args *xdr);
void
convert_btrfs_fsck_args_xdr_to_protobuf (                                 guestfs_btrfs_fsck_args *xdr,
                                 guestfs_protobuf_btrfs_fsck_args *pbc);
void
convert_btrfs_fsck_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_fsck_args *pbc,
                                 guestfs_btrfs_fsck_args *xdr);
void
convert_filesystem_available_args_xdr_to_protobuf (                                 guestfs_filesystem_available_args *xdr,
                                 guestfs_protobuf_filesystem_available_args *pbc);
void
convert_filesystem_available_args_protobuf_to_xdr (                                 guestfs_protobuf_filesystem_available_args *pbc,
                                 guestfs_filesystem_available_args *xdr);
void
convert_filesystem_available_ret_xdr_to_protobuf (                                guestfs_filesystem_available_ret *xdr,
                                guestfs_protobuf_filesystem_available_ret *pbc);
void
convert_filesystem_available_ret_protobuf_to_xdr (                                guestfs_protobuf_filesystem_available_ret *pbc,
                                guestfs_filesystem_available_ret *xdr);
void
convert_fstrim_args_xdr_to_protobuf (                                 guestfs_fstrim_args *xdr,
                                 guestfs_protobuf_fstrim_args *pbc);
void
convert_fstrim_args_protobuf_to_xdr (                                 guestfs_protobuf_fstrim_args *pbc,
                                 guestfs_fstrim_args *xdr);
void
convert_device_index_args_xdr_to_protobuf (                                 guestfs_device_index_args *xdr,
                                 guestfs_protobuf_device_index_args *pbc);
void
convert_device_index_args_protobuf_to_xdr (                                 guestfs_protobuf_device_index_args *pbc,
                                 guestfs_device_index_args *xdr);
void
convert_device_index_ret_xdr_to_protobuf (                                guestfs_device_index_ret *xdr,
                                guestfs_protobuf_device_index_ret *pbc);
void
convert_device_index_ret_protobuf_to_xdr (                                guestfs_protobuf_device_index_ret *pbc,
                                guestfs_device_index_ret *xdr);
void
convert_nr_devices_ret_xdr_to_protobuf (                                guestfs_nr_devices_ret *xdr,
                                guestfs_protobuf_nr_devices_ret *pbc);
void
convert_nr_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_nr_devices_ret *pbc,
                                guestfs_nr_devices_ret *xdr);
void
convert_xfs_info_args_xdr_to_protobuf (                                 guestfs_xfs_info_args *xdr,
                                 guestfs_protobuf_xfs_info_args *pbc);
void
convert_xfs_info_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_info_args *pbc,
                                 guestfs_xfs_info_args *xdr);
void
convert_xfs_info_ret_xdr_to_protobuf (                                guestfs_xfs_info_ret *xdr,
                                guestfs_protobuf_xfs_info_ret *pbc);
void
convert_xfs_info_ret_protobuf_to_xdr (                                guestfs_protobuf_xfs_info_ret *pbc,
                                guestfs_xfs_info_ret *xdr);
void
convert_pvchange_uuid_args_xdr_to_protobuf (                                 guestfs_pvchange_uuid_args *xdr,
                                 guestfs_protobuf_pvchange_uuid_args *pbc);
void
convert_pvchange_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_pvchange_uuid_args *pbc,
                                 guestfs_pvchange_uuid_args *xdr);
void
convert_vgchange_uuid_args_xdr_to_protobuf (                                 guestfs_vgchange_uuid_args *xdr,
                                 guestfs_protobuf_vgchange_uuid_args *pbc);
void
convert_vgchange_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_vgchange_uuid_args *pbc,
                                 guestfs_vgchange_uuid_args *xdr);
void
convert_utsname_ret_xdr_to_protobuf (                                guestfs_utsname_ret *xdr,
                                guestfs_protobuf_utsname_ret *pbc);
void
convert_utsname_ret_protobuf_to_xdr (                                guestfs_protobuf_utsname_ret *pbc,
                                guestfs_utsname_ret *xdr);
void
convert_xfs_growfs_args_xdr_to_protobuf (                                 guestfs_xfs_growfs_args *xdr,
                                 guestfs_protobuf_xfs_growfs_args *pbc);
void
convert_xfs_growfs_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_growfs_args *pbc,
                                 guestfs_xfs_growfs_args *xdr);
void
convert_rsync_args_xdr_to_protobuf (                                 guestfs_rsync_args *xdr,
                                 guestfs_protobuf_rsync_args *pbc);
void
convert_rsync_args_protobuf_to_xdr (                                 guestfs_protobuf_rsync_args *pbc,
                                 guestfs_rsync_args *xdr);
void
convert_rsync_in_args_xdr_to_protobuf (                                 guestfs_rsync_in_args *xdr,
                                 guestfs_protobuf_rsync_in_args *pbc);
void
convert_rsync_in_args_protobuf_to_xdr (                                 guestfs_protobuf_rsync_in_args *pbc,
                                 guestfs_rsync_in_args *xdr);
void
convert_rsync_out_args_xdr_to_protobuf (                                 guestfs_rsync_out_args *xdr,
                                 guestfs_protobuf_rsync_out_args *pbc);
void
convert_rsync_out_args_protobuf_to_xdr (                                 guestfs_protobuf_rsync_out_args *pbc,
                                 guestfs_rsync_out_args *xdr);
void
convert_ls0_args_xdr_to_protobuf (                                 guestfs_ls0_args *xdr,
                                 guestfs_protobuf_ls0_args *pbc);
void
convert_ls0_args_protobuf_to_xdr (                                 guestfs_protobuf_ls0_args *pbc,
                                 guestfs_ls0_args *xdr);
void
convert_fill_dir_args_xdr_to_protobuf (                                 guestfs_fill_dir_args *xdr,
                                 guestfs_protobuf_fill_dir_args *pbc);
void
convert_fill_dir_args_protobuf_to_xdr (                                 guestfs_protobuf_fill_dir_args *pbc,
                                 guestfs_fill_dir_args *xdr);
void
convert_xfs_admin_args_xdr_to_protobuf (                                 guestfs_xfs_admin_args *xdr,
                                 guestfs_protobuf_xfs_admin_args *pbc);
void
convert_xfs_admin_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_admin_args *pbc,
                                 guestfs_xfs_admin_args *xdr);
void
convert_hivex_open_args_xdr_to_protobuf (                                 guestfs_hivex_open_args *xdr,
                                 guestfs_protobuf_hivex_open_args *pbc);
void
convert_hivex_open_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_open_args *pbc,
                                 guestfs_hivex_open_args *xdr);
void
convert_hivex_root_ret_xdr_to_protobuf (                                guestfs_hivex_root_ret *xdr,
                                guestfs_protobuf_hivex_root_ret *pbc);
void
convert_hivex_root_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_root_ret *pbc,
                                guestfs_hivex_root_ret *xdr);
void
convert_hivex_node_name_args_xdr_to_protobuf (                                 guestfs_hivex_node_name_args *xdr,
                                 guestfs_protobuf_hivex_node_name_args *pbc);
void
convert_hivex_node_name_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_name_args *pbc,
                                 guestfs_hivex_node_name_args *xdr);
void
convert_hivex_node_name_ret_xdr_to_protobuf (                                guestfs_hivex_node_name_ret *xdr,
                                guestfs_protobuf_hivex_node_name_ret *pbc);
void
convert_hivex_node_name_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_name_ret *pbc,
                                guestfs_hivex_node_name_ret *xdr);
void
convert_hivex_node_children_args_xdr_to_protobuf (                                 guestfs_hivex_node_children_args *xdr,
                                 guestfs_protobuf_hivex_node_children_args *pbc);
void
convert_hivex_node_children_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_children_args *pbc,
                                 guestfs_hivex_node_children_args *xdr);
void
convert_hivex_node_children_ret_xdr_to_protobuf (                                guestfs_hivex_node_children_ret *xdr,
                                guestfs_protobuf_hivex_node_children_ret *pbc);
void
convert_hivex_node_children_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_children_ret *pbc,
                                guestfs_hivex_node_children_ret *xdr);
void
convert_hivex_node_get_child_args_xdr_to_protobuf (                                 guestfs_hivex_node_get_child_args *xdr,
                                 guestfs_protobuf_hivex_node_get_child_args *pbc);
void
convert_hivex_node_get_child_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_get_child_args *pbc,
                                 guestfs_hivex_node_get_child_args *xdr);
void
convert_hivex_node_get_child_ret_xdr_to_protobuf (                                guestfs_hivex_node_get_child_ret *xdr,
                                guestfs_protobuf_hivex_node_get_child_ret *pbc);
void
convert_hivex_node_get_child_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_get_child_ret *pbc,
                                guestfs_hivex_node_get_child_ret *xdr);
void
convert_hivex_node_parent_args_xdr_to_protobuf (                                 guestfs_hivex_node_parent_args *xdr,
                                 guestfs_protobuf_hivex_node_parent_args *pbc);
void
convert_hivex_node_parent_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_parent_args *pbc,
                                 guestfs_hivex_node_parent_args *xdr);
void
convert_hivex_node_parent_ret_xdr_to_protobuf (                                guestfs_hivex_node_parent_ret *xdr,
                                guestfs_protobuf_hivex_node_parent_ret *pbc);
void
convert_hivex_node_parent_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_parent_ret *pbc,
                                guestfs_hivex_node_parent_ret *xdr);
void
convert_hivex_node_values_args_xdr_to_protobuf (                                 guestfs_hivex_node_values_args *xdr,
                                 guestfs_protobuf_hivex_node_values_args *pbc);
void
convert_hivex_node_values_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_values_args *pbc,
                                 guestfs_hivex_node_values_args *xdr);
void
convert_hivex_node_values_ret_xdr_to_protobuf (                                guestfs_hivex_node_values_ret *xdr,
                                guestfs_protobuf_hivex_node_values_ret *pbc);
void
convert_hivex_node_values_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_values_ret *pbc,
                                guestfs_hivex_node_values_ret *xdr);
void
convert_hivex_node_get_value_args_xdr_to_protobuf (                                 guestfs_hivex_node_get_value_args *xdr,
                                 guestfs_protobuf_hivex_node_get_value_args *pbc);
void
convert_hivex_node_get_value_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_get_value_args *pbc,
                                 guestfs_hivex_node_get_value_args *xdr);
void
convert_hivex_node_get_value_ret_xdr_to_protobuf (                                guestfs_hivex_node_get_value_ret *xdr,
                                guestfs_protobuf_hivex_node_get_value_ret *pbc);
void
convert_hivex_node_get_value_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_get_value_ret *pbc,
                                guestfs_hivex_node_get_value_ret *xdr);
void
convert_hivex_value_key_args_xdr_to_protobuf (                                 guestfs_hivex_value_key_args *xdr,
                                 guestfs_protobuf_hivex_value_key_args *pbc);
void
convert_hivex_value_key_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_value_key_args *pbc,
                                 guestfs_hivex_value_key_args *xdr);
void
convert_hivex_value_key_ret_xdr_to_protobuf (                                guestfs_hivex_value_key_ret *xdr,
                                guestfs_protobuf_hivex_value_key_ret *pbc);
void
convert_hivex_value_key_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_value_key_ret *pbc,
                                guestfs_hivex_value_key_ret *xdr);
void
convert_hivex_value_type_args_xdr_to_protobuf (                                 guestfs_hivex_value_type_args *xdr,
                                 guestfs_protobuf_hivex_value_type_args *pbc);
void
convert_hivex_value_type_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_value_type_args *pbc,
                                 guestfs_hivex_value_type_args *xdr);
void
convert_hivex_value_type_ret_xdr_to_protobuf (                                guestfs_hivex_value_type_ret *xdr,
                                guestfs_protobuf_hivex_value_type_ret *pbc);
void
convert_hivex_value_type_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_value_type_ret *pbc,
                                guestfs_hivex_value_type_ret *xdr);
void
convert_hivex_value_value_args_xdr_to_protobuf (                                 guestfs_hivex_value_value_args *xdr,
                                 guestfs_protobuf_hivex_value_value_args *pbc);
void
convert_hivex_value_value_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_value_value_args *pbc,
                                 guestfs_hivex_value_value_args *xdr);
void
convert_hivex_value_value_ret_xdr_to_protobuf (                                guestfs_hivex_value_value_ret *xdr,
                                guestfs_protobuf_hivex_value_value_ret *pbc);
void
convert_hivex_value_value_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_value_value_ret *pbc,
                                guestfs_hivex_value_value_ret *xdr);
void
convert_hivex_commit_args_xdr_to_protobuf (                                 guestfs_hivex_commit_args *xdr,
                                 guestfs_protobuf_hivex_commit_args *pbc);
void
convert_hivex_commit_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_commit_args *pbc,
                                 guestfs_hivex_commit_args *xdr);
void
convert_hivex_node_add_child_args_xdr_to_protobuf (                                 guestfs_hivex_node_add_child_args *xdr,
                                 guestfs_protobuf_hivex_node_add_child_args *pbc);
void
convert_hivex_node_add_child_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_add_child_args *pbc,
                                 guestfs_hivex_node_add_child_args *xdr);
void
convert_hivex_node_add_child_ret_xdr_to_protobuf (                                guestfs_hivex_node_add_child_ret *xdr,
                                guestfs_protobuf_hivex_node_add_child_ret *pbc);
void
convert_hivex_node_add_child_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_add_child_ret *pbc,
                                guestfs_hivex_node_add_child_ret *xdr);
void
convert_hivex_node_delete_child_args_xdr_to_protobuf (                                 guestfs_hivex_node_delete_child_args *xdr,
                                 guestfs_protobuf_hivex_node_delete_child_args *pbc);
void
convert_hivex_node_delete_child_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_delete_child_args *pbc,
                                 guestfs_hivex_node_delete_child_args *xdr);
void
convert_hivex_node_set_value_args_xdr_to_protobuf (                                 guestfs_hivex_node_set_value_args *xdr,
                                 guestfs_protobuf_hivex_node_set_value_args *pbc);
void
convert_hivex_node_set_value_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_set_value_args *pbc,
                                 guestfs_hivex_node_set_value_args *xdr);
void
convert_xfs_repair_args_xdr_to_protobuf (                                 guestfs_xfs_repair_args *xdr,
                                 guestfs_protobuf_xfs_repair_args *pbc);
void
convert_xfs_repair_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_repair_args *pbc,
                                 guestfs_xfs_repair_args *xdr);
void
convert_xfs_repair_ret_xdr_to_protobuf (                                guestfs_xfs_repair_ret *xdr,
                                guestfs_protobuf_xfs_repair_ret *pbc);
void
convert_xfs_repair_ret_protobuf_to_xdr (                                guestfs_protobuf_xfs_repair_ret *pbc,
                                guestfs_xfs_repair_ret *xdr);
void
convert_rm_ff_args_xdr_to_protobuf (                                 guestfs_rm_ff_args *xdr,
                                 guestfs_protobuf_rm_ff_args *pbc);
void
convert_rm_ff_args_protobuf_to_xdr (                                 guestfs_protobuf_rm_ff_args *pbc,
                                 guestfs_rm_ff_args *xdr);
void
convert_mke2fs_args_xdr_to_protobuf (                                 guestfs_mke2fs_args *xdr,
                                 guestfs_protobuf_mke2fs_args *pbc);
void
convert_mke2fs_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_args *pbc,
                                 guestfs_mke2fs_args *xdr);
void
convert_list_disk_labels_ret_xdr_to_protobuf (                                guestfs_list_disk_labels_ret *xdr,
                                guestfs_protobuf_list_disk_labels_ret *pbc);
void
convert_list_disk_labels_ret_protobuf_to_xdr (                                guestfs_protobuf_list_disk_labels_ret *pbc,
                                guestfs_list_disk_labels_ret *xdr);
void
convert_internal_hot_add_drive_args_xdr_to_protobuf (                                 guestfs_internal_hot_add_drive_args *xdr,
                                 guestfs_protobuf_internal_hot_add_drive_args *pbc);
void
convert_internal_hot_add_drive_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_hot_add_drive_args *pbc,
                                 guestfs_internal_hot_add_drive_args *xdr);
void
convert_internal_hot_remove_drive_precheck_args_xdr_to_protobuf (                                 guestfs_internal_hot_remove_drive_precheck_args *xdr,
                                 guestfs_protobuf_internal_hot_remove_drive_precheck_args *pbc);
void
convert_internal_hot_remove_drive_precheck_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_hot_remove_drive_precheck_args *pbc,
                                 guestfs_internal_hot_remove_drive_precheck_args *xdr);
void
convert_internal_hot_remove_drive_args_xdr_to_protobuf (                                 guestfs_internal_hot_remove_drive_args *xdr,
                                 guestfs_protobuf_internal_hot_remove_drive_args *pbc);
void
convert_internal_hot_remove_drive_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_hot_remove_drive_args *pbc,
                                 guestfs_internal_hot_remove_drive_args *xdr);
void
convert_mktemp_args_xdr_to_protobuf (                                 guestfs_mktemp_args *xdr,
                                 guestfs_protobuf_mktemp_args *pbc);
void
convert_mktemp_args_protobuf_to_xdr (                                 guestfs_protobuf_mktemp_args *pbc,
                                 guestfs_mktemp_args *xdr);
void
convert_mktemp_ret_xdr_to_protobuf (                                guestfs_mktemp_ret *xdr,
                                guestfs_protobuf_mktemp_ret *pbc);
void
convert_mktemp_ret_protobuf_to_xdr (                                guestfs_protobuf_mktemp_ret *pbc,
                                guestfs_mktemp_ret *xdr);
void
convert_mklost_and_found_args_xdr_to_protobuf (                                 guestfs_mklost_and_found_args *xdr,
                                 guestfs_protobuf_mklost_and_found_args *pbc);
void
convert_mklost_and_found_args_protobuf_to_xdr (                                 guestfs_protobuf_mklost_and_found_args *pbc,
                                 guestfs_mklost_and_found_args *xdr);
void
convert_acl_get_file_args_xdr_to_protobuf (                                 guestfs_acl_get_file_args *xdr,
                                 guestfs_protobuf_acl_get_file_args *pbc);
void
convert_acl_get_file_args_protobuf_to_xdr (                                 guestfs_protobuf_acl_get_file_args *pbc,
                                 guestfs_acl_get_file_args *xdr);
void
convert_acl_get_file_ret_xdr_to_protobuf (                                guestfs_acl_get_file_ret *xdr,
                                guestfs_protobuf_acl_get_file_ret *pbc);
void
convert_acl_get_file_ret_protobuf_to_xdr (                                guestfs_protobuf_acl_get_file_ret *pbc,
                                guestfs_acl_get_file_ret *xdr);
void
convert_acl_set_file_args_xdr_to_protobuf (                                 guestfs_acl_set_file_args *xdr,
                                 guestfs_protobuf_acl_set_file_args *pbc);
void
convert_acl_set_file_args_protobuf_to_xdr (                                 guestfs_protobuf_acl_set_file_args *pbc,
                                 guestfs_acl_set_file_args *xdr);
void
convert_acl_delete_def_file_args_xdr_to_protobuf (                                 guestfs_acl_delete_def_file_args *xdr,
                                 guestfs_protobuf_acl_delete_def_file_args *pbc);
void
convert_acl_delete_def_file_args_protobuf_to_xdr (                                 guestfs_protobuf_acl_delete_def_file_args *pbc,
                                 guestfs_acl_delete_def_file_args *xdr);
void
convert_cap_get_file_args_xdr_to_protobuf (                                 guestfs_cap_get_file_args *xdr,
                                 guestfs_protobuf_cap_get_file_args *pbc);
void
convert_cap_get_file_args_protobuf_to_xdr (                                 guestfs_protobuf_cap_get_file_args *pbc,
                                 guestfs_cap_get_file_args *xdr);
void
convert_cap_get_file_ret_xdr_to_protobuf (                                guestfs_cap_get_file_ret *xdr,
                                guestfs_protobuf_cap_get_file_ret *pbc);
void
convert_cap_get_file_ret_protobuf_to_xdr (                                guestfs_protobuf_cap_get_file_ret *pbc,
                                guestfs_cap_get_file_ret *xdr);
void
convert_cap_set_file_args_xdr_to_protobuf (                                 guestfs_cap_set_file_args *xdr,
                                 guestfs_protobuf_cap_set_file_args *pbc);
void
convert_cap_set_file_args_protobuf_to_xdr (                                 guestfs_protobuf_cap_set_file_args *pbc,
                                 guestfs_cap_set_file_args *xdr);
void
convert_list_ldm_volumes_ret_xdr_to_protobuf (                                guestfs_list_ldm_volumes_ret *xdr,
                                guestfs_protobuf_list_ldm_volumes_ret *pbc);
void
convert_list_ldm_volumes_ret_protobuf_to_xdr (                                guestfs_protobuf_list_ldm_volumes_ret *pbc,
                                guestfs_list_ldm_volumes_ret *xdr);
void
convert_list_ldm_partitions_ret_xdr_to_protobuf (                                guestfs_list_ldm_partitions_ret *xdr,
                                guestfs_protobuf_list_ldm_partitions_ret *pbc);
void
convert_list_ldm_partitions_ret_protobuf_to_xdr (                                guestfs_protobuf_list_ldm_partitions_ret *pbc,
                                guestfs_list_ldm_partitions_ret *xdr);
void
convert_ldmtool_scan_ret_xdr_to_protobuf (                                guestfs_ldmtool_scan_ret *xdr,
                                guestfs_protobuf_ldmtool_scan_ret *pbc);
void
convert_ldmtool_scan_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_scan_ret *pbc,
                                guestfs_ldmtool_scan_ret *xdr);
void
convert_ldmtool_scan_devices_args_xdr_to_protobuf (                                 guestfs_ldmtool_scan_devices_args *xdr,
                                 guestfs_protobuf_ldmtool_scan_devices_args *pbc);
void
convert_ldmtool_scan_devices_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_scan_devices_args *pbc,
                                 guestfs_ldmtool_scan_devices_args *xdr);
void
convert_ldmtool_scan_devices_ret_xdr_to_protobuf (                                guestfs_ldmtool_scan_devices_ret *xdr,
                                guestfs_protobuf_ldmtool_scan_devices_ret *pbc);
void
convert_ldmtool_scan_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_scan_devices_ret *pbc,
                                guestfs_ldmtool_scan_devices_ret *xdr);
void
convert_ldmtool_diskgroup_name_args_xdr_to_protobuf (                                 guestfs_ldmtool_diskgroup_name_args *xdr,
                                 guestfs_protobuf_ldmtool_diskgroup_name_args *pbc);
void
convert_ldmtool_diskgroup_name_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_diskgroup_name_args *pbc,
                                 guestfs_ldmtool_diskgroup_name_args *xdr);
void
convert_ldmtool_diskgroup_name_ret_xdr_to_protobuf (                                guestfs_ldmtool_diskgroup_name_ret *xdr,
                                guestfs_protobuf_ldmtool_diskgroup_name_ret *pbc);
void
convert_ldmtool_diskgroup_name_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_diskgroup_name_ret *pbc,
                                guestfs_ldmtool_diskgroup_name_ret *xdr);
void
convert_ldmtool_diskgroup_volumes_args_xdr_to_protobuf (                                 guestfs_ldmtool_diskgroup_volumes_args *xdr,
                                 guestfs_protobuf_ldmtool_diskgroup_volumes_args *pbc);
void
convert_ldmtool_diskgroup_volumes_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_diskgroup_volumes_args *pbc,
                                 guestfs_ldmtool_diskgroup_volumes_args *xdr);
void
convert_ldmtool_diskgroup_volumes_ret_xdr_to_protobuf (                                guestfs_ldmtool_diskgroup_volumes_ret *xdr,
                                guestfs_protobuf_ldmtool_diskgroup_volumes_ret *pbc);
void
convert_ldmtool_diskgroup_volumes_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_diskgroup_volumes_ret *pbc,
                                guestfs_ldmtool_diskgroup_volumes_ret *xdr);
void
convert_ldmtool_diskgroup_disks_args_xdr_to_protobuf (                                 guestfs_ldmtool_diskgroup_disks_args *xdr,
                                 guestfs_protobuf_ldmtool_diskgroup_disks_args *pbc);
void
convert_ldmtool_diskgroup_disks_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_diskgroup_disks_args *pbc,
                                 guestfs_ldmtool_diskgroup_disks_args *xdr);
void
convert_ldmtool_diskgroup_disks_ret_xdr_to_protobuf (                                guestfs_ldmtool_diskgroup_disks_ret *xdr,
                                guestfs_protobuf_ldmtool_diskgroup_disks_ret *pbc);
void
convert_ldmtool_diskgroup_disks_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_diskgroup_disks_ret *pbc,
                                guestfs_ldmtool_diskgroup_disks_ret *xdr);
void
convert_ldmtool_volume_type_args_xdr_to_protobuf (                                 guestfs_ldmtool_volume_type_args *xdr,
                                 guestfs_protobuf_ldmtool_volume_type_args *pbc);
void
convert_ldmtool_volume_type_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_volume_type_args *pbc,
                                 guestfs_ldmtool_volume_type_args *xdr);
void
convert_ldmtool_volume_type_ret_xdr_to_protobuf (                                guestfs_ldmtool_volume_type_ret *xdr,
                                guestfs_protobuf_ldmtool_volume_type_ret *pbc);
void
convert_ldmtool_volume_type_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_volume_type_ret *pbc,
                                guestfs_ldmtool_volume_type_ret *xdr);
void
convert_ldmtool_volume_hint_args_xdr_to_protobuf (                                 guestfs_ldmtool_volume_hint_args *xdr,
                                 guestfs_protobuf_ldmtool_volume_hint_args *pbc);
void
convert_ldmtool_volume_hint_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_volume_hint_args *pbc,
                                 guestfs_ldmtool_volume_hint_args *xdr);
void
convert_ldmtool_volume_hint_ret_xdr_to_protobuf (                                guestfs_ldmtool_volume_hint_ret *xdr,
                                guestfs_protobuf_ldmtool_volume_hint_ret *pbc);
void
convert_ldmtool_volume_hint_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_volume_hint_ret *pbc,
                                guestfs_ldmtool_volume_hint_ret *xdr);
void
convert_ldmtool_volume_partitions_args_xdr_to_protobuf (                                 guestfs_ldmtool_volume_partitions_args *xdr,
                                 guestfs_protobuf_ldmtool_volume_partitions_args *pbc);
void
convert_ldmtool_volume_partitions_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_volume_partitions_args *pbc,
                                 guestfs_ldmtool_volume_partitions_args *xdr);
void
convert_ldmtool_volume_partitions_ret_xdr_to_protobuf (                                guestfs_ldmtool_volume_partitions_ret *xdr,
                                guestfs_protobuf_ldmtool_volume_partitions_ret *pbc);
void
convert_ldmtool_volume_partitions_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_volume_partitions_ret *pbc,
                                guestfs_ldmtool_volume_partitions_ret *xdr);
void
convert_part_set_gpt_type_args_xdr_to_protobuf (                                 guestfs_part_set_gpt_type_args *xdr,
                                 guestfs_protobuf_part_set_gpt_type_args *pbc);
void
convert_part_set_gpt_type_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_gpt_type_args *pbc,
                                 guestfs_part_set_gpt_type_args *xdr);
void
convert_part_get_gpt_type_args_xdr_to_protobuf (                                 guestfs_part_get_gpt_type_args *xdr,
                                 guestfs_protobuf_part_get_gpt_type_args *pbc);
void
convert_part_get_gpt_type_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_gpt_type_args *pbc,
                                 guestfs_part_get_gpt_type_args *xdr);
void
convert_part_get_gpt_type_ret_xdr_to_protobuf (                                guestfs_part_get_gpt_type_ret *xdr,
                                guestfs_protobuf_part_get_gpt_type_ret *pbc);
void
convert_part_get_gpt_type_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_gpt_type_ret *pbc,
                                guestfs_part_get_gpt_type_ret *xdr);
void
convert_rename_args_xdr_to_protobuf (                                 guestfs_rename_args *xdr,
                                 guestfs_protobuf_rename_args *pbc);
void
convert_rename_args_protobuf_to_xdr (                                 guestfs_protobuf_rename_args *pbc,
                                 guestfs_rename_args *xdr);
void
convert_is_whole_device_args_xdr_to_protobuf (                                 guestfs_is_whole_device_args *xdr,
                                 guestfs_protobuf_is_whole_device_args *pbc);
void
convert_is_whole_device_args_protobuf_to_xdr (                                 guestfs_protobuf_is_whole_device_args *pbc,
                                 guestfs_is_whole_device_args *xdr);
void
convert_is_whole_device_ret_xdr_to_protobuf (                                guestfs_is_whole_device_ret *xdr,
                                guestfs_protobuf_is_whole_device_ret *pbc);
void
convert_is_whole_device_ret_protobuf_to_xdr (                                guestfs_protobuf_is_whole_device_ret *pbc,
                                guestfs_is_whole_device_ret *xdr);
void
convert_internal_parse_mountable_args_xdr_to_protobuf (                                 guestfs_internal_parse_mountable_args *xdr,
                                 guestfs_protobuf_internal_parse_mountable_args *pbc);
void
convert_internal_parse_mountable_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_parse_mountable_args *pbc,
                                 guestfs_internal_parse_mountable_args *xdr);
void
convert_internal_parse_mountable_ret_xdr_to_protobuf (                                guestfs_internal_parse_mountable_ret *xdr,
                                guestfs_protobuf_internal_parse_mountable_ret *pbc);
void
convert_internal_parse_mountable_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_parse_mountable_ret *pbc,
                                guestfs_internal_parse_mountable_ret *xdr);
void
convert_internal_rhbz914931_args_xdr_to_protobuf (                                 guestfs_internal_rhbz914931_args *xdr,
                                 guestfs_protobuf_internal_rhbz914931_args *pbc);
void
convert_internal_rhbz914931_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_rhbz914931_args *pbc,
                                 guestfs_internal_rhbz914931_args *xdr);
void
convert_feature_available_args_xdr_to_protobuf (                                 guestfs_feature_available_args *xdr,
                                 guestfs_protobuf_feature_available_args *pbc);
void
convert_feature_available_args_protobuf_to_xdr (                                 guestfs_protobuf_feature_available_args *pbc,
                                 guestfs_feature_available_args *xdr);
void
convert_feature_available_ret_xdr_to_protobuf (                                guestfs_feature_available_ret *xdr,
                                guestfs_protobuf_feature_available_ret *pbc);
void
convert_feature_available_ret_protobuf_to_xdr (                                guestfs_protobuf_feature_available_ret *pbc,
                                guestfs_feature_available_ret *xdr);
void
convert_syslinux_args_xdr_to_protobuf (                                 guestfs_syslinux_args *xdr,
                                 guestfs_protobuf_syslinux_args *pbc);
void
convert_syslinux_args_protobuf_to_xdr (                                 guestfs_protobuf_syslinux_args *pbc,
                                 guestfs_syslinux_args *xdr);
void
convert_extlinux_args_xdr_to_protobuf (                                 guestfs_extlinux_args *xdr,
                                 guestfs_protobuf_extlinux_args *pbc);
void
convert_extlinux_args_protobuf_to_xdr (                                 guestfs_protobuf_extlinux_args *pbc,
                                 guestfs_extlinux_args *xdr);
void
convert_cp_rr_args_xdr_to_protobuf (                                 guestfs_cp_rr_args *xdr,
                                 guestfs_protobuf_cp_rr_args *pbc);
void
convert_cp_rr_args_protobuf_to_xdr (                                 guestfs_protobuf_cp_rr_args *pbc,
                                 guestfs_cp_rr_args *xdr);
void
convert_remount_args_xdr_to_protobuf (                                 guestfs_remount_args *xdr,
                                 guestfs_protobuf_remount_args *pbc);
void
convert_remount_args_protobuf_to_xdr (                                 guestfs_protobuf_remount_args *pbc,
                                 guestfs_remount_args *xdr);
void
convert_set_uuid_args_xdr_to_protobuf (                                 guestfs_set_uuid_args *xdr,
                                 guestfs_protobuf_set_uuid_args *pbc);
void
convert_set_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_set_uuid_args *pbc,
                                 guestfs_set_uuid_args *xdr);
void
convert_journal_open_args_xdr_to_protobuf (                                 guestfs_journal_open_args *xdr,
                                 guestfs_protobuf_journal_open_args *pbc);
void
convert_journal_open_args_protobuf_to_xdr (                                 guestfs_protobuf_journal_open_args *pbc,
                                 guestfs_journal_open_args *xdr);
void
convert_journal_next_ret_xdr_to_protobuf (                                guestfs_journal_next_ret *xdr,
                                guestfs_protobuf_journal_next_ret *pbc);
void
convert_journal_next_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_next_ret *pbc,
                                guestfs_journal_next_ret *xdr);
void
convert_journal_skip_args_xdr_to_protobuf (                                 guestfs_journal_skip_args *xdr,
                                 guestfs_protobuf_journal_skip_args *pbc);
void
convert_journal_skip_args_protobuf_to_xdr (                                 guestfs_protobuf_journal_skip_args *pbc,
                                 guestfs_journal_skip_args *xdr);
void
convert_journal_skip_ret_xdr_to_protobuf (                                guestfs_journal_skip_ret *xdr,
                                guestfs_protobuf_journal_skip_ret *pbc);
void
convert_journal_skip_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_skip_ret *pbc,
                                guestfs_journal_skip_ret *xdr);
void
convert_journal_get_data_threshold_ret_xdr_to_protobuf (                                guestfs_journal_get_data_threshold_ret *xdr,
                                guestfs_protobuf_journal_get_data_threshold_ret *pbc);
void
convert_journal_get_data_threshold_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_get_data_threshold_ret *pbc,
                                guestfs_journal_get_data_threshold_ret *xdr);
void
convert_journal_set_data_threshold_args_xdr_to_protobuf (                                 guestfs_journal_set_data_threshold_args *xdr,
                                 guestfs_protobuf_journal_set_data_threshold_args *pbc);
void
convert_journal_set_data_threshold_args_protobuf_to_xdr (                                 guestfs_protobuf_journal_set_data_threshold_args *pbc,
                                 guestfs_journal_set_data_threshold_args *xdr);
void
convert_aug_setm_args_xdr_to_protobuf (                                 guestfs_aug_setm_args *xdr,
                                 guestfs_protobuf_aug_setm_args *pbc);
void
convert_aug_setm_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_setm_args *pbc,
                                 guestfs_aug_setm_args *xdr);
void
convert_aug_setm_ret_xdr_to_protobuf (                                guestfs_aug_setm_ret *xdr,
                                guestfs_protobuf_aug_setm_ret *pbc);
void
convert_aug_setm_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_setm_ret *pbc,
                                guestfs_aug_setm_ret *xdr);
void
convert_aug_label_args_xdr_to_protobuf (                                 guestfs_aug_label_args *xdr,
                                 guestfs_protobuf_aug_label_args *pbc);
void
convert_aug_label_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_label_args *pbc,
                                 guestfs_aug_label_args *xdr);
void
convert_aug_label_ret_xdr_to_protobuf (                                guestfs_aug_label_ret *xdr,
                                guestfs_protobuf_aug_label_ret *pbc);
void
convert_aug_label_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_label_ret *pbc,
                                guestfs_aug_label_ret *xdr);
void
convert_internal_upload_args_xdr_to_protobuf (                                 guestfs_internal_upload_args *xdr,
                                 guestfs_protobuf_internal_upload_args *pbc);
void
convert_internal_upload_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_upload_args *pbc,
                                 guestfs_internal_upload_args *xdr);
void
convert_copy_attributes_args_xdr_to_protobuf (                                 guestfs_copy_attributes_args *xdr,
                                 guestfs_protobuf_copy_attributes_args *pbc);
void
convert_copy_attributes_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_attributes_args *pbc,
                                 guestfs_copy_attributes_args *xdr);
void
convert_part_get_name_args_xdr_to_protobuf (                                 guestfs_part_get_name_args *xdr,
                                 guestfs_protobuf_part_get_name_args *pbc);
void
convert_part_get_name_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_name_args *pbc,
                                 guestfs_part_get_name_args *xdr);
void
convert_part_get_name_ret_xdr_to_protobuf (                                guestfs_part_get_name_ret *xdr,
                                guestfs_protobuf_part_get_name_ret *pbc);
void
convert_part_get_name_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_name_ret *pbc,
                                guestfs_part_get_name_ret *xdr);
void
convert_blkdiscard_args_xdr_to_protobuf (                                 guestfs_blkdiscard_args *xdr,
                                 guestfs_protobuf_blkdiscard_args *pbc);
void
convert_blkdiscard_args_protobuf_to_xdr (                                 guestfs_protobuf_blkdiscard_args *pbc,
                                 guestfs_blkdiscard_args *xdr);
void
convert_blkdiscardzeroes_args_xdr_to_protobuf (                                 guestfs_blkdiscardzeroes_args *xdr,
                                 guestfs_protobuf_blkdiscardzeroes_args *pbc);
void
convert_blkdiscardzeroes_args_protobuf_to_xdr (                                 guestfs_protobuf_blkdiscardzeroes_args *pbc,
                                 guestfs_blkdiscardzeroes_args *xdr);
void
convert_blkdiscardzeroes_ret_xdr_to_protobuf (                                guestfs_blkdiscardzeroes_ret *xdr,
                                guestfs_protobuf_blkdiscardzeroes_ret *pbc);
void
convert_blkdiscardzeroes_ret_protobuf_to_xdr (                                guestfs_protobuf_blkdiscardzeroes_ret *pbc,
                                guestfs_blkdiscardzeroes_ret *xdr);
void
convert_cpio_out_args_xdr_to_protobuf (                                 guestfs_cpio_out_args *xdr,
                                 guestfs_protobuf_cpio_out_args *pbc);
void
convert_cpio_out_args_protobuf_to_xdr (                                 guestfs_protobuf_cpio_out_args *pbc,
                                 guestfs_cpio_out_args *xdr);
void
convert_journal_get_realtime_usec_ret_xdr_to_protobuf (                                guestfs_journal_get_realtime_usec_ret *xdr,
                                guestfs_protobuf_journal_get_realtime_usec_ret *pbc);
void
convert_journal_get_realtime_usec_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_get_realtime_usec_ret *pbc,
                                guestfs_journal_get_realtime_usec_ret *xdr);
void
convert_statns_args_xdr_to_protobuf (                                 guestfs_statns_args *xdr,
                                 guestfs_protobuf_statns_args *pbc);
void
convert_statns_args_protobuf_to_xdr (                                 guestfs_protobuf_statns_args *pbc,
                                 guestfs_statns_args *xdr);
void
convert_statns_ret_xdr_to_protobuf (                                guestfs_statns_ret *xdr,
                                guestfs_protobuf_statns_ret *pbc);
void
convert_statns_ret_protobuf_to_xdr (                                guestfs_protobuf_statns_ret *pbc,
                                guestfs_statns_ret *xdr);
void
convert_lstatns_args_xdr_to_protobuf (                                 guestfs_lstatns_args *xdr,
                                 guestfs_protobuf_lstatns_args *pbc);
void
convert_lstatns_args_protobuf_to_xdr (                                 guestfs_protobuf_lstatns_args *pbc,
                                 guestfs_lstatns_args *xdr);
void
convert_lstatns_ret_xdr_to_protobuf (                                guestfs_lstatns_ret *xdr,
                                guestfs_protobuf_lstatns_ret *pbc);
void
convert_lstatns_ret_protobuf_to_xdr (                                guestfs_protobuf_lstatns_ret *pbc,
                                guestfs_lstatns_ret *xdr);
void
convert_internal_lstatnslist_args_xdr_to_protobuf (                                 guestfs_internal_lstatnslist_args *xdr,
                                 guestfs_protobuf_internal_lstatnslist_args *pbc);
void
convert_internal_lstatnslist_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_lstatnslist_args *pbc,
                                 guestfs_internal_lstatnslist_args *xdr);
void
convert_internal_lstatnslist_ret_xdr_to_protobuf (                                guestfs_internal_lstatnslist_ret *xdr,
                                guestfs_protobuf_internal_lstatnslist_ret *pbc);
void
convert_internal_lstatnslist_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_lstatnslist_ret *pbc,
                                guestfs_internal_lstatnslist_ret *xdr);
#endif /* GUESTFS_PROTOCOL_CONVERTERS_H_ */
