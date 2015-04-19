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

/* This file defines convert functions from structs used in xdr
 * to structs (aka messages) used in protobuf-c
 */

#include "guestfs_protocol_converters.h"
/* Converters for structs
 * from xdr to protobuf representation and vice versa.
*/

#define strdup _strdup

void
convert_guestfs_int_int_bool_xdr_to_protobuf (
                                    guestfs_int_int_bool *xdr,
                                    guestfs_protobuf_int_int_bool *pbc)
{
  pbc->i = xdr->i;
  pbc->b = xdr->b;
}

void
convert_guestfs_int_int_bool_protobuf_to_xdr (
                                    guestfs_protobuf_int_int_bool *pbc,
                                    guestfs_int_int_bool *xdr)
{
  xdr->i = pbc->i;
  xdr->b = pbc->b;
}

void
convert_guestfs_int_int_bool_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_int_bool_list *pbc,
                                         guestfs_int_int_bool_list *xdr)
{
  int i;
  xdr->guestfs_int_int_bool_list_val = malloc (sizeof (guestfs_int_int_bool) * pbc->n_vals);
  xdr->guestfs_int_int_bool_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_int_bool_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_int_bool_list_val[i]);
  }
}
void
convert_guestfs_int_int_bool_list_xdr_to_protobuf (
                                         guestfs_int_int_bool_list *xdr,
                                         guestfs_protobuf_int_int_bool_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_int_bool *) * xdr->guestfs_int_int_bool_list_len);
  pbc->n_vals = xdr->guestfs_int_int_bool_list_len;
  for (i = 0; i < xdr->guestfs_int_int_bool_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_int_bool));
    convert_guestfs_int_int_bool_xdr_to_protobuf (&xdr->guestfs_int_int_bool_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_lvm_pv_xdr_to_protobuf (
                                    guestfs_int_lvm_pv *xdr,
                                    guestfs_protobuf_int_lvm_pv *pbc)
{
  pbc->pv_name = strdup (xdr->pv_name);
  pbc->pv_uuid.data = malloc (32);
  memcpy (pbc->pv_uuid.data, xdr->pv_uuid, 32);
  pbc->pv_uuid.len = 32;
  pbc->pv_fmt = strdup (xdr->pv_fmt);
  pbc->pv_size = xdr->pv_size;
  pbc->dev_size = xdr->dev_size;
  pbc->pv_free = xdr->pv_free;
  pbc->pv_used = xdr->pv_used;
  pbc->pv_attr = strdup (xdr->pv_attr);
  pbc->pv_pe_count = xdr->pv_pe_count;
  pbc->pv_pe_alloc_count = xdr->pv_pe_alloc_count;
  pbc->pv_tags = strdup (xdr->pv_tags);
  pbc->pe_start = xdr->pe_start;
  pbc->pv_mda_count = xdr->pv_mda_count;
  pbc->pv_mda_free = xdr->pv_mda_free;
}

void
convert_guestfs_int_lvm_pv_protobuf_to_xdr (
                                    guestfs_protobuf_int_lvm_pv *pbc,
                                    guestfs_int_lvm_pv *xdr)
{
  xdr->pv_name = strdup (pbc->pv_name);
  memcpy (xdr->pv_uuid, pbc->pv_uuid.data, 32);
  xdr->pv_fmt = strdup (pbc->pv_fmt);
  xdr->pv_size = pbc->pv_size;
  xdr->dev_size = pbc->dev_size;
  xdr->pv_free = pbc->pv_free;
  xdr->pv_used = pbc->pv_used;
  xdr->pv_attr = strdup (pbc->pv_attr);
  xdr->pv_pe_count = pbc->pv_pe_count;
  xdr->pv_pe_alloc_count = pbc->pv_pe_alloc_count;
  xdr->pv_tags = strdup (pbc->pv_tags);
  xdr->pe_start = pbc->pe_start;
  xdr->pv_mda_count = pbc->pv_mda_count;
  xdr->pv_mda_free = pbc->pv_mda_free;
}

void
convert_guestfs_int_lvm_pv_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_lvm_pv_list *pbc,
                                         guestfs_int_lvm_pv_list *xdr)
{
  int i;
  xdr->guestfs_int_lvm_pv_list_val = malloc (sizeof (guestfs_int_lvm_pv) * pbc->n_vals);
  xdr->guestfs_int_lvm_pv_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_lvm_pv_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_lvm_pv_list_val[i]);
  }
}
void
convert_guestfs_int_lvm_pv_list_xdr_to_protobuf (
                                         guestfs_int_lvm_pv_list *xdr,
                                         guestfs_protobuf_int_lvm_pv_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_lvm_pv *) * xdr->guestfs_int_lvm_pv_list_len);
  pbc->n_vals = xdr->guestfs_int_lvm_pv_list_len;
  for (i = 0; i < xdr->guestfs_int_lvm_pv_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_lvm_pv));
    convert_guestfs_int_lvm_pv_xdr_to_protobuf (&xdr->guestfs_int_lvm_pv_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_lvm_vg_xdr_to_protobuf (
                                    guestfs_int_lvm_vg *xdr,
                                    guestfs_protobuf_int_lvm_vg *pbc)
{
  pbc->vg_name = strdup (xdr->vg_name);
  pbc->vg_uuid.data = malloc (32);
  memcpy (pbc->vg_uuid.data, xdr->vg_uuid, 32);
  pbc->vg_uuid.len = 32;
  pbc->vg_fmt = strdup (xdr->vg_fmt);
  pbc->vg_attr = strdup (xdr->vg_attr);
  pbc->vg_size = xdr->vg_size;
  pbc->vg_free = xdr->vg_free;
  pbc->vg_sysid = strdup (xdr->vg_sysid);
  pbc->vg_extent_size = xdr->vg_extent_size;
  pbc->vg_extent_count = xdr->vg_extent_count;
  pbc->vg_free_count = xdr->vg_free_count;
  pbc->max_lv = xdr->max_lv;
  pbc->max_pv = xdr->max_pv;
  pbc->pv_count = xdr->pv_count;
  pbc->lv_count = xdr->lv_count;
  pbc->snap_count = xdr->snap_count;
  pbc->vg_seqno = xdr->vg_seqno;
  pbc->vg_tags = strdup (xdr->vg_tags);
  pbc->vg_mda_count = xdr->vg_mda_count;
  pbc->vg_mda_free = xdr->vg_mda_free;
}

void
convert_guestfs_int_lvm_vg_protobuf_to_xdr (
                                    guestfs_protobuf_int_lvm_vg *pbc,
                                    guestfs_int_lvm_vg *xdr)
{
  xdr->vg_name = strdup (pbc->vg_name);
  memcpy (xdr->vg_uuid, pbc->vg_uuid.data, 32);
  xdr->vg_fmt = strdup (pbc->vg_fmt);
  xdr->vg_attr = strdup (pbc->vg_attr);
  xdr->vg_size = pbc->vg_size;
  xdr->vg_free = pbc->vg_free;
  xdr->vg_sysid = strdup (pbc->vg_sysid);
  xdr->vg_extent_size = pbc->vg_extent_size;
  xdr->vg_extent_count = pbc->vg_extent_count;
  xdr->vg_free_count = pbc->vg_free_count;
  xdr->max_lv = pbc->max_lv;
  xdr->max_pv = pbc->max_pv;
  xdr->pv_count = pbc->pv_count;
  xdr->lv_count = pbc->lv_count;
  xdr->snap_count = pbc->snap_count;
  xdr->vg_seqno = pbc->vg_seqno;
  xdr->vg_tags = strdup (pbc->vg_tags);
  xdr->vg_mda_count = pbc->vg_mda_count;
  xdr->vg_mda_free = pbc->vg_mda_free;
}

void
convert_guestfs_int_lvm_vg_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_lvm_vg_list *pbc,
                                         guestfs_int_lvm_vg_list *xdr)
{
  int i;
  xdr->guestfs_int_lvm_vg_list_val = malloc (sizeof (guestfs_int_lvm_vg) * pbc->n_vals);
  xdr->guestfs_int_lvm_vg_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_lvm_vg_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_lvm_vg_list_val[i]);
  }
}
void
convert_guestfs_int_lvm_vg_list_xdr_to_protobuf (
                                         guestfs_int_lvm_vg_list *xdr,
                                         guestfs_protobuf_int_lvm_vg_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_lvm_vg *) * xdr->guestfs_int_lvm_vg_list_len);
  pbc->n_vals = xdr->guestfs_int_lvm_vg_list_len;
  for (i = 0; i < xdr->guestfs_int_lvm_vg_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_lvm_vg));
    convert_guestfs_int_lvm_vg_xdr_to_protobuf (&xdr->guestfs_int_lvm_vg_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_lvm_lv_xdr_to_protobuf (
                                    guestfs_int_lvm_lv *xdr,
                                    guestfs_protobuf_int_lvm_lv *pbc)
{
  pbc->lv_name = strdup (xdr->lv_name);
  pbc->lv_uuid.data = malloc (32);
  memcpy (pbc->lv_uuid.data, xdr->lv_uuid, 32);
  pbc->lv_uuid.len = 32;
  pbc->lv_attr = strdup (xdr->lv_attr);
  pbc->lv_major = xdr->lv_major;
  pbc->lv_minor = xdr->lv_minor;
  pbc->lv_kernel_major = xdr->lv_kernel_major;
  pbc->lv_kernel_minor = xdr->lv_kernel_minor;
  pbc->lv_size = xdr->lv_size;
  pbc->seg_count = xdr->seg_count;
  pbc->origin = strdup (xdr->origin);
  pbc->snap_percent = xdr->snap_percent;
  pbc->copy_percent = xdr->copy_percent;
  pbc->move_pv = strdup (xdr->move_pv);
  pbc->lv_tags = strdup (xdr->lv_tags);
  pbc->mirror_log = strdup (xdr->mirror_log);
  pbc->modules = strdup (xdr->modules);
}

void
convert_guestfs_int_lvm_lv_protobuf_to_xdr (
                                    guestfs_protobuf_int_lvm_lv *pbc,
                                    guestfs_int_lvm_lv *xdr)
{
  xdr->lv_name = strdup (pbc->lv_name);
  memcpy (xdr->lv_uuid, pbc->lv_uuid.data, 32);
  xdr->lv_attr = strdup (pbc->lv_attr);
  xdr->lv_major = pbc->lv_major;
  xdr->lv_minor = pbc->lv_minor;
  xdr->lv_kernel_major = pbc->lv_kernel_major;
  xdr->lv_kernel_minor = pbc->lv_kernel_minor;
  xdr->lv_size = pbc->lv_size;
  xdr->seg_count = pbc->seg_count;
  xdr->origin = strdup (pbc->origin);
  xdr->snap_percent = pbc->snap_percent;
  xdr->copy_percent = pbc->copy_percent;
  xdr->move_pv = strdup (pbc->move_pv);
  xdr->lv_tags = strdup (pbc->lv_tags);
  xdr->mirror_log = strdup (pbc->mirror_log);
  xdr->modules = strdup (pbc->modules);
}

void
convert_guestfs_int_lvm_lv_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_lvm_lv_list *pbc,
                                         guestfs_int_lvm_lv_list *xdr)
{
  int i;
  xdr->guestfs_int_lvm_lv_list_val = malloc (sizeof (guestfs_int_lvm_lv) * pbc->n_vals);
  xdr->guestfs_int_lvm_lv_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_lvm_lv_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_lvm_lv_list_val[i]);
  }
}
void
convert_guestfs_int_lvm_lv_list_xdr_to_protobuf (
                                         guestfs_int_lvm_lv_list *xdr,
                                         guestfs_protobuf_int_lvm_lv_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_lvm_lv *) * xdr->guestfs_int_lvm_lv_list_len);
  pbc->n_vals = xdr->guestfs_int_lvm_lv_list_len;
  for (i = 0; i < xdr->guestfs_int_lvm_lv_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_lvm_lv));
    convert_guestfs_int_lvm_lv_xdr_to_protobuf (&xdr->guestfs_int_lvm_lv_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_stat_xdr_to_protobuf (
                                    guestfs_int_stat *xdr,
                                    guestfs_protobuf_int_stat *pbc)
{
  pbc->dev = xdr->dev;
  pbc->ino = xdr->ino;
  pbc->mode = xdr->mode;
  pbc->nlink = xdr->nlink;
  pbc->uid = xdr->uid;
  pbc->gid = xdr->gid;
  pbc->rdev = xdr->rdev;
  pbc->size = xdr->size;
  pbc->blksize = xdr->blksize;
  pbc->blocks = xdr->blocks;
  pbc->atime = xdr->atime;
  pbc->mtime = xdr->mtime;
  pbc->ctime = xdr->ctime;
}

void
convert_guestfs_int_stat_protobuf_to_xdr (
                                    guestfs_protobuf_int_stat *pbc,
                                    guestfs_int_stat *xdr)
{
  xdr->dev = pbc->dev;
  xdr->ino = pbc->ino;
  xdr->mode = pbc->mode;
  xdr->nlink = pbc->nlink;
  xdr->uid = pbc->uid;
  xdr->gid = pbc->gid;
  xdr->rdev = pbc->rdev;
  xdr->size = pbc->size;
  xdr->blksize = pbc->blksize;
  xdr->blocks = pbc->blocks;
  xdr->atime = pbc->atime;
  xdr->mtime = pbc->mtime;
  xdr->ctime = pbc->ctime;
}

void
convert_guestfs_int_stat_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_stat_list *pbc,
                                         guestfs_int_stat_list *xdr)
{
  int i;
  xdr->guestfs_int_stat_list_val = malloc (sizeof (guestfs_int_stat) * pbc->n_vals);
  xdr->guestfs_int_stat_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_stat_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_stat_list_val[i]);
  }
}
void
convert_guestfs_int_stat_list_xdr_to_protobuf (
                                         guestfs_int_stat_list *xdr,
                                         guestfs_protobuf_int_stat_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_stat *) * xdr->guestfs_int_stat_list_len);
  pbc->n_vals = xdr->guestfs_int_stat_list_len;
  for (i = 0; i < xdr->guestfs_int_stat_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_stat));
    convert_guestfs_int_stat_xdr_to_protobuf (&xdr->guestfs_int_stat_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_statns_xdr_to_protobuf (
                                    guestfs_int_statns *xdr,
                                    guestfs_protobuf_int_statns *pbc)
{
  pbc->st_dev = xdr->st_dev;
  pbc->st_ino = xdr->st_ino;
  pbc->st_mode = xdr->st_mode;
  pbc->st_nlink = xdr->st_nlink;
  pbc->st_uid = xdr->st_uid;
  pbc->st_gid = xdr->st_gid;
  pbc->st_rdev = xdr->st_rdev;
  pbc->st_size = xdr->st_size;
  pbc->st_blksize = xdr->st_blksize;
  pbc->st_blocks = xdr->st_blocks;
  pbc->st_atime_sec = xdr->st_atime_sec;
  pbc->st_atime_nsec = xdr->st_atime_nsec;
  pbc->st_mtime_sec = xdr->st_mtime_sec;
  pbc->st_mtime_nsec = xdr->st_mtime_nsec;
  pbc->st_ctime_sec = xdr->st_ctime_sec;
  pbc->st_ctime_nsec = xdr->st_ctime_nsec;
  pbc->st_spare1 = xdr->st_spare1;
  pbc->st_spare2 = xdr->st_spare2;
  pbc->st_spare3 = xdr->st_spare3;
  pbc->st_spare4 = xdr->st_spare4;
  pbc->st_spare5 = xdr->st_spare5;
  pbc->st_spare6 = xdr->st_spare6;
}

void
convert_guestfs_int_statns_protobuf_to_xdr (
                                    guestfs_protobuf_int_statns *pbc,
                                    guestfs_int_statns *xdr)
{
  xdr->st_dev = pbc->st_dev;
  xdr->st_ino = pbc->st_ino;
  xdr->st_mode = pbc->st_mode;
  xdr->st_nlink = pbc->st_nlink;
  xdr->st_uid = pbc->st_uid;
  xdr->st_gid = pbc->st_gid;
  xdr->st_rdev = pbc->st_rdev;
  xdr->st_size = pbc->st_size;
  xdr->st_blksize = pbc->st_blksize;
  xdr->st_blocks = pbc->st_blocks;
  xdr->st_atime_sec = pbc->st_atime_sec;
  xdr->st_atime_nsec = pbc->st_atime_nsec;
  xdr->st_mtime_sec = pbc->st_mtime_sec;
  xdr->st_mtime_nsec = pbc->st_mtime_nsec;
  xdr->st_ctime_sec = pbc->st_ctime_sec;
  xdr->st_ctime_nsec = pbc->st_ctime_nsec;
  xdr->st_spare1 = pbc->st_spare1;
  xdr->st_spare2 = pbc->st_spare2;
  xdr->st_spare3 = pbc->st_spare3;
  xdr->st_spare4 = pbc->st_spare4;
  xdr->st_spare5 = pbc->st_spare5;
  xdr->st_spare6 = pbc->st_spare6;
}

void
convert_guestfs_int_statns_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_statns_list *pbc,
                                         guestfs_int_statns_list *xdr)
{
  int i;
  xdr->guestfs_int_statns_list_val = malloc (sizeof (guestfs_int_statns) * pbc->n_vals);
  xdr->guestfs_int_statns_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_statns_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_statns_list_val[i]);
  }
}
void
convert_guestfs_int_statns_list_xdr_to_protobuf (
                                         guestfs_int_statns_list *xdr,
                                         guestfs_protobuf_int_statns_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_statns *) * xdr->guestfs_int_statns_list_len);
  pbc->n_vals = xdr->guestfs_int_statns_list_len;
  for (i = 0; i < xdr->guestfs_int_statns_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_statns));
    convert_guestfs_int_statns_xdr_to_protobuf (&xdr->guestfs_int_statns_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_statvfs_xdr_to_protobuf (
                                    guestfs_int_statvfs *xdr,
                                    guestfs_protobuf_int_statvfs *pbc)
{
  pbc->bsize = xdr->bsize;
  pbc->frsize = xdr->frsize;
  pbc->blocks = xdr->blocks;
  pbc->bfree = xdr->bfree;
  pbc->bavail = xdr->bavail;
  pbc->files = xdr->files;
  pbc->ffree = xdr->ffree;
  pbc->favail = xdr->favail;
  pbc->fsid = xdr->fsid;
  pbc->flag = xdr->flag;
  pbc->namemax = xdr->namemax;
}

void
convert_guestfs_int_statvfs_protobuf_to_xdr (
                                    guestfs_protobuf_int_statvfs *pbc,
                                    guestfs_int_statvfs *xdr)
{
  xdr->bsize = pbc->bsize;
  xdr->frsize = pbc->frsize;
  xdr->blocks = pbc->blocks;
  xdr->bfree = pbc->bfree;
  xdr->bavail = pbc->bavail;
  xdr->files = pbc->files;
  xdr->ffree = pbc->ffree;
  xdr->favail = pbc->favail;
  xdr->fsid = pbc->fsid;
  xdr->flag = pbc->flag;
  xdr->namemax = pbc->namemax;
}

void
convert_guestfs_int_statvfs_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_statvfs_list *pbc,
                                         guestfs_int_statvfs_list *xdr)
{
  int i;
  xdr->guestfs_int_statvfs_list_val = malloc (sizeof (guestfs_int_statvfs) * pbc->n_vals);
  xdr->guestfs_int_statvfs_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_statvfs_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_statvfs_list_val[i]);
  }
}
void
convert_guestfs_int_statvfs_list_xdr_to_protobuf (
                                         guestfs_int_statvfs_list *xdr,
                                         guestfs_protobuf_int_statvfs_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_statvfs *) * xdr->guestfs_int_statvfs_list_len);
  pbc->n_vals = xdr->guestfs_int_statvfs_list_len;
  for (i = 0; i < xdr->guestfs_int_statvfs_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_statvfs));
    convert_guestfs_int_statvfs_xdr_to_protobuf (&xdr->guestfs_int_statvfs_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_dirent_xdr_to_protobuf (
                                    guestfs_int_dirent *xdr,
                                    guestfs_protobuf_int_dirent *pbc)
{
  pbc->ino = xdr->ino;
  pbc->ftyp = xdr->ftyp;
  pbc->name = strdup (xdr->name);
}

void
convert_guestfs_int_dirent_protobuf_to_xdr (
                                    guestfs_protobuf_int_dirent *pbc,
                                    guestfs_int_dirent *xdr)
{
  xdr->ino = pbc->ino;
  xdr->ftyp = pbc->ftyp;
  xdr->name = strdup (pbc->name);
}

void
convert_guestfs_int_dirent_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_dirent_list *pbc,
                                         guestfs_int_dirent_list *xdr)
{
  int i;
  xdr->guestfs_int_dirent_list_val = malloc (sizeof (guestfs_int_dirent) * pbc->n_vals);
  xdr->guestfs_int_dirent_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_dirent_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_dirent_list_val[i]);
  }
}
void
convert_guestfs_int_dirent_list_xdr_to_protobuf (
                                         guestfs_int_dirent_list *xdr,
                                         guestfs_protobuf_int_dirent_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_dirent *) * xdr->guestfs_int_dirent_list_len);
  pbc->n_vals = xdr->guestfs_int_dirent_list_len;
  for (i = 0; i < xdr->guestfs_int_dirent_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_dirent));
    convert_guestfs_int_dirent_xdr_to_protobuf (&xdr->guestfs_int_dirent_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_version_xdr_to_protobuf (
                                    guestfs_int_version *xdr,
                                    guestfs_protobuf_int_version *pbc)
{
  pbc->major = xdr->major;
  pbc->minor = xdr->minor;
  pbc->release = xdr->release;
  pbc->extra = strdup (xdr->extra);
}

void
convert_guestfs_int_version_protobuf_to_xdr (
                                    guestfs_protobuf_int_version *pbc,
                                    guestfs_int_version *xdr)
{
  xdr->major = pbc->major;
  xdr->minor = pbc->minor;
  xdr->release = pbc->release;
  xdr->extra = strdup (pbc->extra);
}

void
convert_guestfs_int_version_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_version_list *pbc,
                                         guestfs_int_version_list *xdr)
{
  int i;
  xdr->guestfs_int_version_list_val = malloc (sizeof (guestfs_int_version) * pbc->n_vals);
  xdr->guestfs_int_version_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_version_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_version_list_val[i]);
  }
}
void
convert_guestfs_int_version_list_xdr_to_protobuf (
                                         guestfs_int_version_list *xdr,
                                         guestfs_protobuf_int_version_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_version *) * xdr->guestfs_int_version_list_len);
  pbc->n_vals = xdr->guestfs_int_version_list_len;
  for (i = 0; i < xdr->guestfs_int_version_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_version));
    convert_guestfs_int_version_xdr_to_protobuf (&xdr->guestfs_int_version_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_xattr_xdr_to_protobuf (
                                    guestfs_int_xattr *xdr,
                                    guestfs_protobuf_int_xattr *pbc)
{
  pbc->attrname = strdup (xdr->attrname);
  pbc->attrval.data = malloc (xdr->attrval.attrval_len);
  memcpy (pbc->attrval.data, xdr->attrval.attrval_val, xdr->attrval.attrval_len);
  pbc->attrval.len = xdr->attrval.attrval_len; 
}

void
convert_guestfs_int_xattr_protobuf_to_xdr (
                                    guestfs_protobuf_int_xattr *pbc,
                                    guestfs_int_xattr *xdr)
{
  xdr->attrname = strdup (pbc->attrname);
  xdr->attrval.attrval_val = malloc (pbc->attrval.len);
  memcpy (xdr->attrval.attrval_val, pbc->attrval.data, pbc->attrval.len); 
  xdr->attrval.attrval_len = pbc->attrval.len; 
}

void
convert_guestfs_int_xattr_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_xattr_list *pbc,
                                         guestfs_int_xattr_list *xdr)
{
  int i;
  xdr->guestfs_int_xattr_list_val = malloc (sizeof (guestfs_int_xattr) * pbc->n_vals);
  xdr->guestfs_int_xattr_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_xattr_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_xattr_list_val[i]);
  }
}
void
convert_guestfs_int_xattr_list_xdr_to_protobuf (
                                         guestfs_int_xattr_list *xdr,
                                         guestfs_protobuf_int_xattr_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_xattr *) * xdr->guestfs_int_xattr_list_len);
  pbc->n_vals = xdr->guestfs_int_xattr_list_len;
  for (i = 0; i < xdr->guestfs_int_xattr_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_xattr));
    convert_guestfs_int_xattr_xdr_to_protobuf (&xdr->guestfs_int_xattr_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_inotify_event_xdr_to_protobuf (
                                    guestfs_int_inotify_event *xdr,
                                    guestfs_protobuf_int_inotify_event *pbc)
{
  pbc->in_wd = xdr->in_wd;
  pbc->in_mask = xdr->in_mask;
  pbc->in_cookie = xdr->in_cookie;
  pbc->in_name = strdup (xdr->in_name);
}

void
convert_guestfs_int_inotify_event_protobuf_to_xdr (
                                    guestfs_protobuf_int_inotify_event *pbc,
                                    guestfs_int_inotify_event *xdr)
{
  xdr->in_wd = pbc->in_wd;
  xdr->in_mask = pbc->in_mask;
  xdr->in_cookie = pbc->in_cookie;
  xdr->in_name = strdup (pbc->in_name);
}

void
convert_guestfs_int_inotify_event_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_inotify_event_list *pbc,
                                         guestfs_int_inotify_event_list *xdr)
{
  int i;
  xdr->guestfs_int_inotify_event_list_val = malloc (sizeof (guestfs_int_inotify_event) * pbc->n_vals);
  xdr->guestfs_int_inotify_event_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_inotify_event_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_inotify_event_list_val[i]);
  }
}
void
convert_guestfs_int_inotify_event_list_xdr_to_protobuf (
                                         guestfs_int_inotify_event_list *xdr,
                                         guestfs_protobuf_int_inotify_event_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_inotify_event *) * xdr->guestfs_int_inotify_event_list_len);
  pbc->n_vals = xdr->guestfs_int_inotify_event_list_len;
  for (i = 0; i < xdr->guestfs_int_inotify_event_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_inotify_event));
    convert_guestfs_int_inotify_event_xdr_to_protobuf (&xdr->guestfs_int_inotify_event_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_partition_xdr_to_protobuf (
                                    guestfs_int_partition *xdr,
                                    guestfs_protobuf_int_partition *pbc)
{
  pbc->part_num = xdr->part_num;
  pbc->part_start = xdr->part_start;
  pbc->part_end = xdr->part_end;
  pbc->part_size = xdr->part_size;
}

void
convert_guestfs_int_partition_protobuf_to_xdr (
                                    guestfs_protobuf_int_partition *pbc,
                                    guestfs_int_partition *xdr)
{
  xdr->part_num = pbc->part_num;
  xdr->part_start = pbc->part_start;
  xdr->part_end = pbc->part_end;
  xdr->part_size = pbc->part_size;
}

void
convert_guestfs_int_partition_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_partition_list *pbc,
                                         guestfs_int_partition_list *xdr)
{
  int i;
  xdr->guestfs_int_partition_list_val = malloc (sizeof (guestfs_int_partition) * pbc->n_vals);
  xdr->guestfs_int_partition_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_partition_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_partition_list_val[i]);
  }
}
void
convert_guestfs_int_partition_list_xdr_to_protobuf (
                                         guestfs_int_partition_list *xdr,
                                         guestfs_protobuf_int_partition_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_partition *) * xdr->guestfs_int_partition_list_len);
  pbc->n_vals = xdr->guestfs_int_partition_list_len;
  for (i = 0; i < xdr->guestfs_int_partition_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_partition));
    convert_guestfs_int_partition_xdr_to_protobuf (&xdr->guestfs_int_partition_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_application_xdr_to_protobuf (
                                    guestfs_int_application *xdr,
                                    guestfs_protobuf_int_application *pbc)
{
  pbc->app_name = strdup (xdr->app_name);
  pbc->app_display_name = strdup (xdr->app_display_name);
  pbc->app_epoch = xdr->app_epoch;
  pbc->app_version = strdup (xdr->app_version);
  pbc->app_release = strdup (xdr->app_release);
  pbc->app_install_path = strdup (xdr->app_install_path);
  pbc->app_trans_path = strdup (xdr->app_trans_path);
  pbc->app_publisher = strdup (xdr->app_publisher);
  pbc->app_url = strdup (xdr->app_url);
  pbc->app_source_package = strdup (xdr->app_source_package);
  pbc->app_summary = strdup (xdr->app_summary);
  pbc->app_description = strdup (xdr->app_description);
}

void
convert_guestfs_int_application_protobuf_to_xdr (
                                    guestfs_protobuf_int_application *pbc,
                                    guestfs_int_application *xdr)
{
  xdr->app_name = strdup (pbc->app_name);
  xdr->app_display_name = strdup (pbc->app_display_name);
  xdr->app_epoch = pbc->app_epoch;
  xdr->app_version = strdup (pbc->app_version);
  xdr->app_release = strdup (pbc->app_release);
  xdr->app_install_path = strdup (pbc->app_install_path);
  xdr->app_trans_path = strdup (pbc->app_trans_path);
  xdr->app_publisher = strdup (pbc->app_publisher);
  xdr->app_url = strdup (pbc->app_url);
  xdr->app_source_package = strdup (pbc->app_source_package);
  xdr->app_summary = strdup (pbc->app_summary);
  xdr->app_description = strdup (pbc->app_description);
}

void
convert_guestfs_int_application_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_application_list *pbc,
                                         guestfs_int_application_list *xdr)
{
  int i;
  xdr->guestfs_int_application_list_val = malloc (sizeof (guestfs_int_application) * pbc->n_vals);
  xdr->guestfs_int_application_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_application_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_application_list_val[i]);
  }
}
void
convert_guestfs_int_application_list_xdr_to_protobuf (
                                         guestfs_int_application_list *xdr,
                                         guestfs_protobuf_int_application_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_application *) * xdr->guestfs_int_application_list_len);
  pbc->n_vals = xdr->guestfs_int_application_list_len;
  for (i = 0; i < xdr->guestfs_int_application_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_application));
    convert_guestfs_int_application_xdr_to_protobuf (&xdr->guestfs_int_application_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_application2_xdr_to_protobuf (
                                    guestfs_int_application2 *xdr,
                                    guestfs_protobuf_int_application2 *pbc)
{
  pbc->app2_name = strdup (xdr->app2_name);
  pbc->app2_display_name = strdup (xdr->app2_display_name);
  pbc->app2_epoch = xdr->app2_epoch;
  pbc->app2_version = strdup (xdr->app2_version);
  pbc->app2_release = strdup (xdr->app2_release);
  pbc->app2_arch = strdup (xdr->app2_arch);
  pbc->app2_install_path = strdup (xdr->app2_install_path);
  pbc->app2_trans_path = strdup (xdr->app2_trans_path);
  pbc->app2_publisher = strdup (xdr->app2_publisher);
  pbc->app2_url = strdup (xdr->app2_url);
  pbc->app2_source_package = strdup (xdr->app2_source_package);
  pbc->app2_summary = strdup (xdr->app2_summary);
  pbc->app2_description = strdup (xdr->app2_description);
  pbc->app2_spare1 = strdup (xdr->app2_spare1);
  pbc->app2_spare2 = strdup (xdr->app2_spare2);
  pbc->app2_spare3 = strdup (xdr->app2_spare3);
  pbc->app2_spare4 = strdup (xdr->app2_spare4);
}

void
convert_guestfs_int_application2_protobuf_to_xdr (
                                    guestfs_protobuf_int_application2 *pbc,
                                    guestfs_int_application2 *xdr)
{
  xdr->app2_name = strdup (pbc->app2_name);
  xdr->app2_display_name = strdup (pbc->app2_display_name);
  xdr->app2_epoch = pbc->app2_epoch;
  xdr->app2_version = strdup (pbc->app2_version);
  xdr->app2_release = strdup (pbc->app2_release);
  xdr->app2_arch = strdup (pbc->app2_arch);
  xdr->app2_install_path = strdup (pbc->app2_install_path);
  xdr->app2_trans_path = strdup (pbc->app2_trans_path);
  xdr->app2_publisher = strdup (pbc->app2_publisher);
  xdr->app2_url = strdup (pbc->app2_url);
  xdr->app2_source_package = strdup (pbc->app2_source_package);
  xdr->app2_summary = strdup (pbc->app2_summary);
  xdr->app2_description = strdup (pbc->app2_description);
  xdr->app2_spare1 = strdup (pbc->app2_spare1);
  xdr->app2_spare2 = strdup (pbc->app2_spare2);
  xdr->app2_spare3 = strdup (pbc->app2_spare3);
  xdr->app2_spare4 = strdup (pbc->app2_spare4);
}

void
convert_guestfs_int_application2_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_application2_list *pbc,
                                         guestfs_int_application2_list *xdr)
{
  int i;
  xdr->guestfs_int_application2_list_val = malloc (sizeof (guestfs_int_application2) * pbc->n_vals);
  xdr->guestfs_int_application2_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_application2_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_application2_list_val[i]);
  }
}
void
convert_guestfs_int_application2_list_xdr_to_protobuf (
                                         guestfs_int_application2_list *xdr,
                                         guestfs_protobuf_int_application2_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_application2 *) * xdr->guestfs_int_application2_list_len);
  pbc->n_vals = xdr->guestfs_int_application2_list_len;
  for (i = 0; i < xdr->guestfs_int_application2_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_application2));
    convert_guestfs_int_application2_xdr_to_protobuf (&xdr->guestfs_int_application2_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_isoinfo_xdr_to_protobuf (
                                    guestfs_int_isoinfo *xdr,
                                    guestfs_protobuf_int_isoinfo *pbc)
{
  pbc->iso_system_id = strdup (xdr->iso_system_id);
  pbc->iso_volume_id = strdup (xdr->iso_volume_id);
  pbc->iso_volume_space_size = xdr->iso_volume_space_size;
  pbc->iso_volume_set_size = xdr->iso_volume_set_size;
  pbc->iso_volume_sequence_number = xdr->iso_volume_sequence_number;
  pbc->iso_logical_block_size = xdr->iso_logical_block_size;
  pbc->iso_volume_set_id = strdup (xdr->iso_volume_set_id);
  pbc->iso_publisher_id = strdup (xdr->iso_publisher_id);
  pbc->iso_data_preparer_id = strdup (xdr->iso_data_preparer_id);
  pbc->iso_application_id = strdup (xdr->iso_application_id);
  pbc->iso_copyright_file_id = strdup (xdr->iso_copyright_file_id);
  pbc->iso_abstract_file_id = strdup (xdr->iso_abstract_file_id);
  pbc->iso_bibliographic_file_id = strdup (xdr->iso_bibliographic_file_id);
  pbc->iso_volume_creation_t = xdr->iso_volume_creation_t;
  pbc->iso_volume_modification_t = xdr->iso_volume_modification_t;
  pbc->iso_volume_expiration_t = xdr->iso_volume_expiration_t;
  pbc->iso_volume_effective_t = xdr->iso_volume_effective_t;
}

void
convert_guestfs_int_isoinfo_protobuf_to_xdr (
                                    guestfs_protobuf_int_isoinfo *pbc,
                                    guestfs_int_isoinfo *xdr)
{
  xdr->iso_system_id = strdup (pbc->iso_system_id);
  xdr->iso_volume_id = strdup (pbc->iso_volume_id);
  xdr->iso_volume_space_size = pbc->iso_volume_space_size;
  xdr->iso_volume_set_size = pbc->iso_volume_set_size;
  xdr->iso_volume_sequence_number = pbc->iso_volume_sequence_number;
  xdr->iso_logical_block_size = pbc->iso_logical_block_size;
  xdr->iso_volume_set_id = strdup (pbc->iso_volume_set_id);
  xdr->iso_publisher_id = strdup (pbc->iso_publisher_id);
  xdr->iso_data_preparer_id = strdup (pbc->iso_data_preparer_id);
  xdr->iso_application_id = strdup (pbc->iso_application_id);
  xdr->iso_copyright_file_id = strdup (pbc->iso_copyright_file_id);
  xdr->iso_abstract_file_id = strdup (pbc->iso_abstract_file_id);
  xdr->iso_bibliographic_file_id = strdup (pbc->iso_bibliographic_file_id);
  xdr->iso_volume_creation_t = pbc->iso_volume_creation_t;
  xdr->iso_volume_modification_t = pbc->iso_volume_modification_t;
  xdr->iso_volume_expiration_t = pbc->iso_volume_expiration_t;
  xdr->iso_volume_effective_t = pbc->iso_volume_effective_t;
}

void
convert_guestfs_int_isoinfo_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_isoinfo_list *pbc,
                                         guestfs_int_isoinfo_list *xdr)
{
  int i;
  xdr->guestfs_int_isoinfo_list_val = malloc (sizeof (guestfs_int_isoinfo) * pbc->n_vals);
  xdr->guestfs_int_isoinfo_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_isoinfo_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_isoinfo_list_val[i]);
  }
}
void
convert_guestfs_int_isoinfo_list_xdr_to_protobuf (
                                         guestfs_int_isoinfo_list *xdr,
                                         guestfs_protobuf_int_isoinfo_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_isoinfo *) * xdr->guestfs_int_isoinfo_list_len);
  pbc->n_vals = xdr->guestfs_int_isoinfo_list_len;
  for (i = 0; i < xdr->guestfs_int_isoinfo_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_isoinfo));
    convert_guestfs_int_isoinfo_xdr_to_protobuf (&xdr->guestfs_int_isoinfo_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_mdstat_xdr_to_protobuf (
                                    guestfs_int_mdstat *xdr,
                                    guestfs_protobuf_int_mdstat *pbc)
{
  pbc->mdstat_device = strdup (xdr->mdstat_device);
  pbc->mdstat_index = xdr->mdstat_index;
  pbc->mdstat_flags = strdup (xdr->mdstat_flags);
}

void
convert_guestfs_int_mdstat_protobuf_to_xdr (
                                    guestfs_protobuf_int_mdstat *pbc,
                                    guestfs_int_mdstat *xdr)
{
  xdr->mdstat_device = strdup (pbc->mdstat_device);
  xdr->mdstat_index = pbc->mdstat_index;
  xdr->mdstat_flags = strdup (pbc->mdstat_flags);
}

void
convert_guestfs_int_mdstat_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_mdstat_list *pbc,
                                         guestfs_int_mdstat_list *xdr)
{
  int i;
  xdr->guestfs_int_mdstat_list_val = malloc (sizeof (guestfs_int_mdstat) * pbc->n_vals);
  xdr->guestfs_int_mdstat_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_mdstat_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_mdstat_list_val[i]);
  }
}
void
convert_guestfs_int_mdstat_list_xdr_to_protobuf (
                                         guestfs_int_mdstat_list *xdr,
                                         guestfs_protobuf_int_mdstat_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_mdstat *) * xdr->guestfs_int_mdstat_list_len);
  pbc->n_vals = xdr->guestfs_int_mdstat_list_len;
  for (i = 0; i < xdr->guestfs_int_mdstat_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_mdstat));
    convert_guestfs_int_mdstat_xdr_to_protobuf (&xdr->guestfs_int_mdstat_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_btrfssubvolume_xdr_to_protobuf (
                                    guestfs_int_btrfssubvolume *xdr,
                                    guestfs_protobuf_int_btrfssubvolume *pbc)
{
  pbc->btrfssubvolume_id = xdr->btrfssubvolume_id;
  pbc->btrfssubvolume_top_level_id = xdr->btrfssubvolume_top_level_id;
  pbc->btrfssubvolume_path = strdup (xdr->btrfssubvolume_path);
}

void
convert_guestfs_int_btrfssubvolume_protobuf_to_xdr (
                                    guestfs_protobuf_int_btrfssubvolume *pbc,
                                    guestfs_int_btrfssubvolume *xdr)
{
  xdr->btrfssubvolume_id = pbc->btrfssubvolume_id;
  xdr->btrfssubvolume_top_level_id = pbc->btrfssubvolume_top_level_id;
  xdr->btrfssubvolume_path = strdup (pbc->btrfssubvolume_path);
}

void
convert_guestfs_int_btrfssubvolume_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_btrfssubvolume_list *pbc,
                                         guestfs_int_btrfssubvolume_list *xdr)
{
  int i;
  xdr->guestfs_int_btrfssubvolume_list_val = malloc (sizeof (guestfs_int_btrfssubvolume) * pbc->n_vals);
  xdr->guestfs_int_btrfssubvolume_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_btrfssubvolume_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_btrfssubvolume_list_val[i]);
  }
}
void
convert_guestfs_int_btrfssubvolume_list_xdr_to_protobuf (
                                         guestfs_int_btrfssubvolume_list *xdr,
                                         guestfs_protobuf_int_btrfssubvolume_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_btrfssubvolume *) * xdr->guestfs_int_btrfssubvolume_list_len);
  pbc->n_vals = xdr->guestfs_int_btrfssubvolume_list_len;
  for (i = 0; i < xdr->guestfs_int_btrfssubvolume_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_btrfssubvolume));
    convert_guestfs_int_btrfssubvolume_xdr_to_protobuf (&xdr->guestfs_int_btrfssubvolume_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_xfsinfo_xdr_to_protobuf (
                                    guestfs_int_xfsinfo *xdr,
                                    guestfs_protobuf_int_xfsinfo *pbc)
{
  pbc->xfs_mntpoint = strdup (xdr->xfs_mntpoint);
  pbc->xfs_inodesize = xdr->xfs_inodesize;
  pbc->xfs_agcount = xdr->xfs_agcount;
  pbc->xfs_agsize = xdr->xfs_agsize;
  pbc->xfs_sectsize = xdr->xfs_sectsize;
  pbc->xfs_attr = xdr->xfs_attr;
  pbc->xfs_blocksize = xdr->xfs_blocksize;
  pbc->xfs_datablocks = xdr->xfs_datablocks;
  pbc->xfs_imaxpct = xdr->xfs_imaxpct;
  pbc->xfs_sunit = xdr->xfs_sunit;
  pbc->xfs_swidth = xdr->xfs_swidth;
  pbc->xfs_dirversion = xdr->xfs_dirversion;
  pbc->xfs_dirblocksize = xdr->xfs_dirblocksize;
  pbc->xfs_cimode = xdr->xfs_cimode;
  pbc->xfs_logname = strdup (xdr->xfs_logname);
  pbc->xfs_logblocksize = xdr->xfs_logblocksize;
  pbc->xfs_logblocks = xdr->xfs_logblocks;
  pbc->xfs_logversion = xdr->xfs_logversion;
  pbc->xfs_logsectsize = xdr->xfs_logsectsize;
  pbc->xfs_logsunit = xdr->xfs_logsunit;
  pbc->xfs_lazycount = xdr->xfs_lazycount;
  pbc->xfs_rtname = strdup (xdr->xfs_rtname);
  pbc->xfs_rtextsize = xdr->xfs_rtextsize;
  pbc->xfs_rtblocks = xdr->xfs_rtblocks;
  pbc->xfs_rtextents = xdr->xfs_rtextents;
}

void
convert_guestfs_int_xfsinfo_protobuf_to_xdr (
                                    guestfs_protobuf_int_xfsinfo *pbc,
                                    guestfs_int_xfsinfo *xdr)
{
  xdr->xfs_mntpoint = strdup (pbc->xfs_mntpoint);
  xdr->xfs_inodesize = pbc->xfs_inodesize;
  xdr->xfs_agcount = pbc->xfs_agcount;
  xdr->xfs_agsize = pbc->xfs_agsize;
  xdr->xfs_sectsize = pbc->xfs_sectsize;
  xdr->xfs_attr = pbc->xfs_attr;
  xdr->xfs_blocksize = pbc->xfs_blocksize;
  xdr->xfs_datablocks = pbc->xfs_datablocks;
  xdr->xfs_imaxpct = pbc->xfs_imaxpct;
  xdr->xfs_sunit = pbc->xfs_sunit;
  xdr->xfs_swidth = pbc->xfs_swidth;
  xdr->xfs_dirversion = pbc->xfs_dirversion;
  xdr->xfs_dirblocksize = pbc->xfs_dirblocksize;
  xdr->xfs_cimode = pbc->xfs_cimode;
  xdr->xfs_logname = strdup (pbc->xfs_logname);
  xdr->xfs_logblocksize = pbc->xfs_logblocksize;
  xdr->xfs_logblocks = pbc->xfs_logblocks;
  xdr->xfs_logversion = pbc->xfs_logversion;
  xdr->xfs_logsectsize = pbc->xfs_logsectsize;
  xdr->xfs_logsunit = pbc->xfs_logsunit;
  xdr->xfs_lazycount = pbc->xfs_lazycount;
  xdr->xfs_rtname = strdup (pbc->xfs_rtname);
  xdr->xfs_rtextsize = pbc->xfs_rtextsize;
  xdr->xfs_rtblocks = pbc->xfs_rtblocks;
  xdr->xfs_rtextents = pbc->xfs_rtextents;
}

void
convert_guestfs_int_xfsinfo_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_xfsinfo_list *pbc,
                                         guestfs_int_xfsinfo_list *xdr)
{
  int i;
  xdr->guestfs_int_xfsinfo_list_val = malloc (sizeof (guestfs_int_xfsinfo) * pbc->n_vals);
  xdr->guestfs_int_xfsinfo_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_xfsinfo_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_xfsinfo_list_val[i]);
  }
}
void
convert_guestfs_int_xfsinfo_list_xdr_to_protobuf (
                                         guestfs_int_xfsinfo_list *xdr,
                                         guestfs_protobuf_int_xfsinfo_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_xfsinfo *) * xdr->guestfs_int_xfsinfo_list_len);
  pbc->n_vals = xdr->guestfs_int_xfsinfo_list_len;
  for (i = 0; i < xdr->guestfs_int_xfsinfo_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_xfsinfo));
    convert_guestfs_int_xfsinfo_xdr_to_protobuf (&xdr->guestfs_int_xfsinfo_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_utsname_xdr_to_protobuf (
                                    guestfs_int_utsname *xdr,
                                    guestfs_protobuf_int_utsname *pbc)
{
  pbc->uts_sysname = strdup (xdr->uts_sysname);
  pbc->uts_release = strdup (xdr->uts_release);
  pbc->uts_version = strdup (xdr->uts_version);
  pbc->uts_machine = strdup (xdr->uts_machine);
}

void
convert_guestfs_int_utsname_protobuf_to_xdr (
                                    guestfs_protobuf_int_utsname *pbc,
                                    guestfs_int_utsname *xdr)
{
  xdr->uts_sysname = strdup (pbc->uts_sysname);
  xdr->uts_release = strdup (pbc->uts_release);
  xdr->uts_version = strdup (pbc->uts_version);
  xdr->uts_machine = strdup (pbc->uts_machine);
}

void
convert_guestfs_int_utsname_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_utsname_list *pbc,
                                         guestfs_int_utsname_list *xdr)
{
  int i;
  xdr->guestfs_int_utsname_list_val = malloc (sizeof (guestfs_int_utsname) * pbc->n_vals);
  xdr->guestfs_int_utsname_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_utsname_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_utsname_list_val[i]);
  }
}
void
convert_guestfs_int_utsname_list_xdr_to_protobuf (
                                         guestfs_int_utsname_list *xdr,
                                         guestfs_protobuf_int_utsname_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_utsname *) * xdr->guestfs_int_utsname_list_len);
  pbc->n_vals = xdr->guestfs_int_utsname_list_len;
  for (i = 0; i < xdr->guestfs_int_utsname_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_utsname));
    convert_guestfs_int_utsname_xdr_to_protobuf (&xdr->guestfs_int_utsname_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_hivex_node_xdr_to_protobuf (
                                    guestfs_int_hivex_node *xdr,
                                    guestfs_protobuf_int_hivex_node *pbc)
{
  pbc->hivex_node_h = xdr->hivex_node_h;
}

void
convert_guestfs_int_hivex_node_protobuf_to_xdr (
                                    guestfs_protobuf_int_hivex_node *pbc,
                                    guestfs_int_hivex_node *xdr)
{
  xdr->hivex_node_h = pbc->hivex_node_h;
}

void
convert_guestfs_int_hivex_node_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_hivex_node_list *pbc,
                                         guestfs_int_hivex_node_list *xdr)
{
  int i;
  xdr->guestfs_int_hivex_node_list_val = malloc (sizeof (guestfs_int_hivex_node) * pbc->n_vals);
  xdr->guestfs_int_hivex_node_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_hivex_node_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_hivex_node_list_val[i]);
  }
}
void
convert_guestfs_int_hivex_node_list_xdr_to_protobuf (
                                         guestfs_int_hivex_node_list *xdr,
                                         guestfs_protobuf_int_hivex_node_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_hivex_node *) * xdr->guestfs_int_hivex_node_list_len);
  pbc->n_vals = xdr->guestfs_int_hivex_node_list_len;
  for (i = 0; i < xdr->guestfs_int_hivex_node_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_hivex_node));
    convert_guestfs_int_hivex_node_xdr_to_protobuf (&xdr->guestfs_int_hivex_node_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_hivex_value_xdr_to_protobuf (
                                    guestfs_int_hivex_value *xdr,
                                    guestfs_protobuf_int_hivex_value *pbc)
{
  pbc->hivex_value_h = xdr->hivex_value_h;
}

void
convert_guestfs_int_hivex_value_protobuf_to_xdr (
                                    guestfs_protobuf_int_hivex_value *pbc,
                                    guestfs_int_hivex_value *xdr)
{
  xdr->hivex_value_h = pbc->hivex_value_h;
}

void
convert_guestfs_int_hivex_value_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_hivex_value_list *pbc,
                                         guestfs_int_hivex_value_list *xdr)
{
  int i;
  xdr->guestfs_int_hivex_value_list_val = malloc (sizeof (guestfs_int_hivex_value) * pbc->n_vals);
  xdr->guestfs_int_hivex_value_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_hivex_value_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_hivex_value_list_val[i]);
  }
}
void
convert_guestfs_int_hivex_value_list_xdr_to_protobuf (
                                         guestfs_int_hivex_value_list *xdr,
                                         guestfs_protobuf_int_hivex_value_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_hivex_value *) * xdr->guestfs_int_hivex_value_list_len);
  pbc->n_vals = xdr->guestfs_int_hivex_value_list_len;
  for (i = 0; i < xdr->guestfs_int_hivex_value_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_hivex_value));
    convert_guestfs_int_hivex_value_xdr_to_protobuf (&xdr->guestfs_int_hivex_value_list_val[i], pbc->vals[i]);
  }
}

void
convert_guestfs_int_internal_mountable_xdr_to_protobuf (
                                    guestfs_int_internal_mountable *xdr,
                                    guestfs_protobuf_int_internal_mountable *pbc)
{
  pbc->im_type = xdr->im_type;
  pbc->im_device = strdup (xdr->im_device);
  pbc->im_volume = strdup (xdr->im_volume);
}

void
convert_guestfs_int_internal_mountable_protobuf_to_xdr (
                                    guestfs_protobuf_int_internal_mountable *pbc,
                                    guestfs_int_internal_mountable *xdr)
{
  xdr->im_type = pbc->im_type;
  xdr->im_device = strdup (pbc->im_device);
  xdr->im_volume = strdup (pbc->im_volume);
}

void
convert_guestfs_int_internal_mountable_list_protobuf_to_xdr (
                                         guestfs_protobuf_int_internal_mountable_list *pbc,
                                         guestfs_int_internal_mountable_list *xdr)
{
  int i;
  xdr->guestfs_int_internal_mountable_list_val = malloc (sizeof (guestfs_int_internal_mountable) * pbc->n_vals);
  xdr->guestfs_int_internal_mountable_list_len = pbc->n_vals;
  for (i = 0; i < pbc->n_vals; ++i) {
    convert_guestfs_int_internal_mountable_protobuf_to_xdr (pbc->vals[i], &xdr->guestfs_int_internal_mountable_list_val[i]);
  }
}
void
convert_guestfs_int_internal_mountable_list_xdr_to_protobuf (
                                         guestfs_int_internal_mountable_list *xdr,
                                         guestfs_protobuf_int_internal_mountable_list *pbc)
{
  int i;
  pbc->vals = malloc (sizeof (guestfs_protobuf_int_internal_mountable *) * xdr->guestfs_int_internal_mountable_list_len);
  pbc->n_vals = xdr->guestfs_int_internal_mountable_list_len;
  for (i = 0; i < xdr->guestfs_int_internal_mountable_list_len; ++i) {
    pbc->vals[i] = malloc (sizeof (guestfs_protobuf_int_internal_mountable));
    convert_guestfs_int_internal_mountable_xdr_to_protobuf (&xdr->guestfs_int_internal_mountable_list_val[i], pbc->vals[i]);
  }
}

/* Converters for function arguments and return values
 * from xdr to protobuf representation and vice versa.
*/

void
convert_mount_args_xdr_to_protobuf (                                 guestfs_mount_args *xdr,
                                 guestfs_protobuf_mount_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
  pbc->mountpoint = strdup (xdr->mountpoint);
}

void
convert_mount_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_args *pbc,
                                 guestfs_mount_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
  xdr->mountpoint = strdup (pbc->mountpoint);
}

void
convert_touch_args_xdr_to_protobuf (                                 guestfs_touch_args *xdr,
                                 guestfs_protobuf_touch_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_touch_args_protobuf_to_xdr (                                 guestfs_protobuf_touch_args *pbc,
                                 guestfs_touch_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_ll_args_xdr_to_protobuf (                                 guestfs_ll_args *xdr,
                                 guestfs_protobuf_ll_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_ll_args *pbc,
                                 guestfs_ll_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_ll_ret_xdr_to_protobuf (                                guestfs_ll_ret *xdr,
                                guestfs_protobuf_ll_ret *pbc)
{
  pbc->listing = strdup (xdr->listing);
}

void
convert_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_ll_ret *pbc,
                                guestfs_ll_ret *xdr)
{
  xdr->listing = strdup (pbc->listing);
}

void
convert_list_devices_ret_xdr_to_protobuf (                                guestfs_list_devices_ret *xdr,
                                guestfs_protobuf_list_devices_ret *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) {
    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_list_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_list_devices_ret *pbc,
                                guestfs_list_devices_ret *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) {
    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_list_partitions_ret_xdr_to_protobuf (                                guestfs_list_partitions_ret *xdr,
                                guestfs_protobuf_list_partitions_ret *pbc)
{
  pbc->partitions = malloc (xdr->partitions.partitions_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->partitions.partitions_len; ++i) {
    pbc->n_partitions = i;
    pbc->partitions[i] = xdr->partitions.partitions_val[i] ? strdup (xdr->partitions.partitions_val[i]) : NULL;
  }
}

void
convert_list_partitions_ret_protobuf_to_xdr (                                guestfs_protobuf_list_partitions_ret *pbc,
                                guestfs_list_partitions_ret *xdr)
{
  xdr->partitions.partitions_val = malloc (pbc->n_partitions * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_partitions; ++i) {
    xdr->partitions.partitions_len = i;
    xdr->partitions.partitions_val[i] = pbc->partitions[i] ? strdup (pbc->partitions[i]) : NULL;
  }
}

void
convert_pvs_ret_xdr_to_protobuf (                                guestfs_pvs_ret *xdr,
                                guestfs_protobuf_pvs_ret *pbc)
{
  pbc->physvols = malloc (xdr->physvols.physvols_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->physvols.physvols_len; ++i) {
    pbc->n_physvols = i;
    pbc->physvols[i] = xdr->physvols.physvols_val[i] ? strdup (xdr->physvols.physvols_val[i]) : NULL;
  }
}

void
convert_pvs_ret_protobuf_to_xdr (                                guestfs_protobuf_pvs_ret *pbc,
                                guestfs_pvs_ret *xdr)
{
  xdr->physvols.physvols_val = malloc (pbc->n_physvols * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_physvols; ++i) {
    xdr->physvols.physvols_len = i;
    xdr->physvols.physvols_val[i] = pbc->physvols[i] ? strdup (pbc->physvols[i]) : NULL;
  }
}

void
convert_vgs_ret_xdr_to_protobuf (                                guestfs_vgs_ret *xdr,
                                guestfs_protobuf_vgs_ret *pbc)
{
  pbc->volgroups = malloc (xdr->volgroups.volgroups_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->volgroups.volgroups_len; ++i) {
    pbc->n_volgroups = i;
    pbc->volgroups[i] = xdr->volgroups.volgroups_val[i] ? strdup (xdr->volgroups.volgroups_val[i]) : NULL;
  }
}

void
convert_vgs_ret_protobuf_to_xdr (                                guestfs_protobuf_vgs_ret *pbc,
                                guestfs_vgs_ret *xdr)
{
  xdr->volgroups.volgroups_val = malloc (pbc->n_volgroups * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_volgroups; ++i) {
    xdr->volgroups.volgroups_len = i;
    xdr->volgroups.volgroups_val[i] = pbc->volgroups[i] ? strdup (pbc->volgroups[i]) : NULL;
  }
}

void
convert_lvs_ret_xdr_to_protobuf (                                guestfs_lvs_ret *xdr,
                                guestfs_protobuf_lvs_ret *pbc)
{
  pbc->logvols = malloc (xdr->logvols.logvols_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->logvols.logvols_len; ++i) {
    pbc->n_logvols = i;
    pbc->logvols[i] = xdr->logvols.logvols_val[i] ? strdup (xdr->logvols.logvols_val[i]) : NULL;
  }
}

void
convert_lvs_ret_protobuf_to_xdr (                                guestfs_protobuf_lvs_ret *pbc,
                                guestfs_lvs_ret *xdr)
{
  xdr->logvols.logvols_val = malloc (pbc->n_logvols * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_logvols; ++i) {
    xdr->logvols.logvols_len = i;
    xdr->logvols.logvols_val[i] = pbc->logvols[i] ? strdup (pbc->logvols[i]) : NULL;
  }
}

void
convert_pvs_full_ret_xdr_to_protobuf (                                guestfs_pvs_full_ret *xdr,
                                guestfs_protobuf_pvs_full_ret *pbc)
{
  pbc->physvols = malloc (sizeof (guestfs_protobuf_int_lvm_pv_list));
  convert_guestfs_int_lvm_pv_list_xdr_to_protobuf (&xdr->physvols, pbc->physvols);
}

void
convert_pvs_full_ret_protobuf_to_xdr (                                guestfs_protobuf_pvs_full_ret *pbc,
                                guestfs_pvs_full_ret *xdr)
{
  convert_guestfs_int_lvm_pv_list_protobuf_to_xdr (pbc->physvols, &xdr->physvols);
}

void
convert_vgs_full_ret_xdr_to_protobuf (                                guestfs_vgs_full_ret *xdr,
                                guestfs_protobuf_vgs_full_ret *pbc)
{
  pbc->volgroups = malloc (sizeof (guestfs_protobuf_int_lvm_vg_list));
  convert_guestfs_int_lvm_vg_list_xdr_to_protobuf (&xdr->volgroups, pbc->volgroups);
}

void
convert_vgs_full_ret_protobuf_to_xdr (                                guestfs_protobuf_vgs_full_ret *pbc,
                                guestfs_vgs_full_ret *xdr)
{
  convert_guestfs_int_lvm_vg_list_protobuf_to_xdr (pbc->volgroups, &xdr->volgroups);
}

void
convert_lvs_full_ret_xdr_to_protobuf (                                guestfs_lvs_full_ret *xdr,
                                guestfs_protobuf_lvs_full_ret *pbc)
{
  pbc->logvols = malloc (sizeof (guestfs_protobuf_int_lvm_lv_list));
  convert_guestfs_int_lvm_lv_list_xdr_to_protobuf (&xdr->logvols, pbc->logvols);
}

void
convert_lvs_full_ret_protobuf_to_xdr (                                guestfs_protobuf_lvs_full_ret *pbc,
                                guestfs_lvs_full_ret *xdr)
{
  convert_guestfs_int_lvm_lv_list_protobuf_to_xdr (pbc->logvols, &xdr->logvols);
}

void
convert_aug_init_args_xdr_to_protobuf (                                 guestfs_aug_init_args *xdr,
                                 guestfs_protobuf_aug_init_args *pbc)
{
  pbc->root = strdup (xdr->root);
  pbc->flags = xdr->flags;
}

void
convert_aug_init_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_init_args *pbc,
                                 guestfs_aug_init_args *xdr)
{
  xdr->root = strdup (pbc->root);
  xdr->flags = pbc->flags;
}

void
convert_aug_defvar_args_xdr_to_protobuf (                                 guestfs_aug_defvar_args *xdr,
                                 guestfs_protobuf_aug_defvar_args *pbc)
{
  pbc->name = strdup (xdr->name);
  char *tmp = xdr->expr ? strdup (*xdr->expr) : NULL;
  pbc->expr = tmp ? &tmp : NULL;
}

void
convert_aug_defvar_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_defvar_args *pbc,
                                 guestfs_aug_defvar_args *xdr)
{
  xdr->name = strdup (pbc->name);
  char *tmp = pbc->expr ? strdup (*pbc->expr) : NULL;
  xdr->expr = tmp ? &tmp : NULL;
}

void
convert_aug_defvar_ret_xdr_to_protobuf (                                guestfs_aug_defvar_ret *xdr,
                                guestfs_protobuf_aug_defvar_ret *pbc)
{
  pbc->nrnodes = xdr->nrnodes;
}

void
convert_aug_defvar_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_defvar_ret *pbc,
                                guestfs_aug_defvar_ret *xdr)
{
  xdr->nrnodes = pbc->nrnodes;
}

void
convert_aug_defnode_args_xdr_to_protobuf (                                 guestfs_aug_defnode_args *xdr,
                                 guestfs_protobuf_aug_defnode_args *pbc)
{
  pbc->name = strdup (xdr->name);
  pbc->expr = strdup (xdr->expr);
  pbc->val = strdup (xdr->val);
}

void
convert_aug_defnode_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_defnode_args *pbc,
                                 guestfs_aug_defnode_args *xdr)
{
  xdr->name = strdup (pbc->name);
  xdr->expr = strdup (pbc->expr);
  xdr->val = strdup (pbc->val);
}

void
convert_aug_defnode_ret_xdr_to_protobuf (                                guestfs_aug_defnode_ret *xdr,
                                guestfs_protobuf_aug_defnode_ret *pbc)
{
  pbc->nrnodescreated = malloc (sizeof (guestfs_protobuf_int_int_bool));
  convert_guestfs_int_int_bool_xdr_to_protobuf (&xdr->nrnodescreated, pbc->nrnodescreated);
}

void
convert_aug_defnode_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_defnode_ret *pbc,
                                guestfs_aug_defnode_ret *xdr)
{
  convert_guestfs_int_int_bool_protobuf_to_xdr (pbc->nrnodescreated, &xdr->nrnodescreated);
}

void
convert_aug_get_args_xdr_to_protobuf (                                 guestfs_aug_get_args *xdr,
                                 guestfs_protobuf_aug_get_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
}

void
convert_aug_get_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_get_args *pbc,
                                 guestfs_aug_get_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
}

void
convert_aug_get_ret_xdr_to_protobuf (                                guestfs_aug_get_ret *xdr,
                                guestfs_protobuf_aug_get_ret *pbc)
{
  pbc->val = strdup (xdr->val);
}

void
convert_aug_get_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_get_ret *pbc,
                                guestfs_aug_get_ret *xdr)
{
  xdr->val = strdup (pbc->val);
}

void
convert_aug_set_args_xdr_to_protobuf (                                 guestfs_aug_set_args *xdr,
                                 guestfs_protobuf_aug_set_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
  pbc->val = strdup (xdr->val);
}

void
convert_aug_set_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_set_args *pbc,
                                 guestfs_aug_set_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
  xdr->val = strdup (pbc->val);
}

void
convert_aug_insert_args_xdr_to_protobuf (                                 guestfs_aug_insert_args *xdr,
                                 guestfs_protobuf_aug_insert_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
  pbc->label = strdup (xdr->label);
  pbc->before = xdr->before;
}

void
convert_aug_insert_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_insert_args *pbc,
                                 guestfs_aug_insert_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
  xdr->label = strdup (pbc->label);
  xdr->before = pbc->before;
}

void
convert_aug_rm_args_xdr_to_protobuf (                                 guestfs_aug_rm_args *xdr,
                                 guestfs_protobuf_aug_rm_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
}

void
convert_aug_rm_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_rm_args *pbc,
                                 guestfs_aug_rm_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
}

void
convert_aug_rm_ret_xdr_to_protobuf (                                guestfs_aug_rm_ret *xdr,
                                guestfs_protobuf_aug_rm_ret *pbc)
{
  pbc->nrnodes = xdr->nrnodes;
}

void
convert_aug_rm_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_rm_ret *pbc,
                                guestfs_aug_rm_ret *xdr)
{
  xdr->nrnodes = pbc->nrnodes;
}

void
convert_aug_mv_args_xdr_to_protobuf (                                 guestfs_aug_mv_args *xdr,
                                 guestfs_protobuf_aug_mv_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
}

void
convert_aug_mv_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_mv_args *pbc,
                                 guestfs_aug_mv_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
}

void
convert_aug_match_args_xdr_to_protobuf (                                 guestfs_aug_match_args *xdr,
                                 guestfs_protobuf_aug_match_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
}

void
convert_aug_match_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_match_args *pbc,
                                 guestfs_aug_match_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
}

void
convert_aug_match_ret_xdr_to_protobuf (                                guestfs_aug_match_ret *xdr,
                                guestfs_protobuf_aug_match_ret *pbc)
{
  pbc->matches = malloc (xdr->matches.matches_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->matches.matches_len; ++i) {
    pbc->n_matches = i;
    pbc->matches[i] = xdr->matches.matches_val[i] ? strdup (xdr->matches.matches_val[i]) : NULL;
  }
}

void
convert_aug_match_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_match_ret *pbc,
                                guestfs_aug_match_ret *xdr)
{
  xdr->matches.matches_val = malloc (pbc->n_matches * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_matches; ++i) {
    xdr->matches.matches_len = i;
    xdr->matches.matches_val[i] = pbc->matches[i] ? strdup (pbc->matches[i]) : NULL;
  }
}

void
convert_aug_ls_args_xdr_to_protobuf (                                 guestfs_aug_ls_args *xdr,
                                 guestfs_protobuf_aug_ls_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
}

void
convert_aug_ls_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_ls_args *pbc,
                                 guestfs_aug_ls_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
}

void
convert_aug_ls_ret_xdr_to_protobuf (                                guestfs_aug_ls_ret *xdr,
                                guestfs_protobuf_aug_ls_ret *pbc)
{
  pbc->matches = malloc (xdr->matches.matches_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->matches.matches_len; ++i) {
    pbc->n_matches = i;
    pbc->matches[i] = xdr->matches.matches_val[i] ? strdup (xdr->matches.matches_val[i]) : NULL;
  }
}

void
convert_aug_ls_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_ls_ret *pbc,
                                guestfs_aug_ls_ret *xdr)
{
  xdr->matches.matches_val = malloc (pbc->n_matches * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_matches; ++i) {
    xdr->matches.matches_len = i;
    xdr->matches.matches_val[i] = pbc->matches[i] ? strdup (pbc->matches[i]) : NULL;
  }
}

void
convert_rm_args_xdr_to_protobuf (                                 guestfs_rm_args *xdr,
                                 guestfs_protobuf_rm_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_rm_args_protobuf_to_xdr (                                 guestfs_protobuf_rm_args *pbc,
                                 guestfs_rm_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_rmdir_args_xdr_to_protobuf (                                 guestfs_rmdir_args *xdr,
                                 guestfs_protobuf_rmdir_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_rmdir_args_protobuf_to_xdr (                                 guestfs_protobuf_rmdir_args *pbc,
                                 guestfs_rmdir_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_rm_rf_args_xdr_to_protobuf (                                 guestfs_rm_rf_args *xdr,
                                 guestfs_protobuf_rm_rf_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_rm_rf_args_protobuf_to_xdr (                                 guestfs_protobuf_rm_rf_args *pbc,
                                 guestfs_rm_rf_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_mkdir_args_xdr_to_protobuf (                                 guestfs_mkdir_args *xdr,
                                 guestfs_protobuf_mkdir_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_mkdir_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdir_args *pbc,
                                 guestfs_mkdir_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_mkdir_pp_args_xdr_to_protobuf (                                 guestfs_mkdir_pp_args *xdr,
                                 guestfs_protobuf_mkdir_pp_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_mkdir_pp_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdir_pp_args *pbc,
                                 guestfs_mkdir_pp_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_chmod_args_xdr_to_protobuf (                                 guestfs_chmod_args *xdr,
                                 guestfs_protobuf_chmod_args *pbc)
{
  pbc->mode = xdr->mode;
  pbc->path = strdup (xdr->path);
}

void
convert_chmod_args_protobuf_to_xdr (                                 guestfs_protobuf_chmod_args *pbc,
                                 guestfs_chmod_args *xdr)
{
  xdr->mode = pbc->mode;
  xdr->path = strdup (pbc->path);
}

void
convert_chown_args_xdr_to_protobuf (                                 guestfs_chown_args *xdr,
                                 guestfs_protobuf_chown_args *pbc)
{
  pbc->owner = xdr->owner;
  pbc->group = xdr->group;
  pbc->path = strdup (xdr->path);
}

void
convert_chown_args_protobuf_to_xdr (                                 guestfs_protobuf_chown_args *pbc,
                                 guestfs_chown_args *xdr)
{
  xdr->owner = pbc->owner;
  xdr->group = pbc->group;
  xdr->path = strdup (pbc->path);
}

void
convert_exists_args_xdr_to_protobuf (                                 guestfs_exists_args *xdr,
                                 guestfs_protobuf_exists_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_exists_args_protobuf_to_xdr (                                 guestfs_protobuf_exists_args *pbc,
                                 guestfs_exists_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_exists_ret_xdr_to_protobuf (                                guestfs_exists_ret *xdr,
                                guestfs_protobuf_exists_ret *pbc)
{
  pbc->existsflag = xdr->existsflag;
}

void
convert_exists_ret_protobuf_to_xdr (                                guestfs_protobuf_exists_ret *pbc,
                                guestfs_exists_ret *xdr)
{
  xdr->existsflag = pbc->existsflag;
}

void
convert_is_file_args_xdr_to_protobuf (                                 guestfs_is_file_args *xdr,
                                 guestfs_protobuf_is_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->followsymlinks = xdr->followsymlinks;
}

void
convert_is_file_args_protobuf_to_xdr (                                 guestfs_protobuf_is_file_args *pbc,
                                 guestfs_is_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->followsymlinks = pbc->followsymlinks;
}

void
convert_is_file_ret_xdr_to_protobuf (                                guestfs_is_file_ret *xdr,
                                guestfs_protobuf_is_file_ret *pbc)
{
  pbc->fileflag = xdr->fileflag;
}

void
convert_is_file_ret_protobuf_to_xdr (                                guestfs_protobuf_is_file_ret *pbc,
                                guestfs_is_file_ret *xdr)
{
  xdr->fileflag = pbc->fileflag;
}

void
convert_is_dir_args_xdr_to_protobuf (                                 guestfs_is_dir_args *xdr,
                                 guestfs_protobuf_is_dir_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->followsymlinks = xdr->followsymlinks;
}

void
convert_is_dir_args_protobuf_to_xdr (                                 guestfs_protobuf_is_dir_args *pbc,
                                 guestfs_is_dir_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->followsymlinks = pbc->followsymlinks;
}

void
convert_is_dir_ret_xdr_to_protobuf (                                guestfs_is_dir_ret *xdr,
                                guestfs_protobuf_is_dir_ret *pbc)
{
  pbc->dirflag = xdr->dirflag;
}

void
convert_is_dir_ret_protobuf_to_xdr (                                guestfs_protobuf_is_dir_ret *pbc,
                                guestfs_is_dir_ret *xdr)
{
  xdr->dirflag = pbc->dirflag;
}

void
convert_pvcreate_args_xdr_to_protobuf (                                 guestfs_pvcreate_args *xdr,
                                 guestfs_protobuf_pvcreate_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_pvcreate_args_protobuf_to_xdr (                                 guestfs_protobuf_pvcreate_args *pbc,
                                 guestfs_pvcreate_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_vgcreate_args_xdr_to_protobuf (                                 guestfs_vgcreate_args *xdr,
                                 guestfs_protobuf_vgcreate_args *pbc)
{
  pbc->volgroup = strdup (xdr->volgroup);
  pbc->physvols = malloc (xdr->physvols.physvols_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->physvols.physvols_len; ++i) 
{    pbc->n_physvols = i;
    pbc->physvols[i] = xdr->physvols.physvols_val[i] ? strdup (xdr->physvols.physvols_val[i]) : NULL;
  }
}

void
convert_vgcreate_args_protobuf_to_xdr (                                 guestfs_protobuf_vgcreate_args *pbc,
                                 guestfs_vgcreate_args *xdr)
{
  xdr->volgroup = strdup (pbc->volgroup);
  xdr->physvols.physvols_val = malloc (pbc->n_physvols * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_physvols; ++i) 
{    xdr->physvols.physvols_len = i;
    xdr->physvols.physvols_val[i] = pbc->physvols[i] ? strdup (pbc->physvols[i]) : NULL;
  }
}

void
convert_lvcreate_args_xdr_to_protobuf (                                 guestfs_lvcreate_args *xdr,
                                 guestfs_protobuf_lvcreate_args *pbc)
{
  pbc->logvol = strdup (xdr->logvol);
  pbc->volgroup = strdup (xdr->volgroup);
  pbc->mbytes = xdr->mbytes;
}

void
convert_lvcreate_args_protobuf_to_xdr (                                 guestfs_protobuf_lvcreate_args *pbc,
                                 guestfs_lvcreate_args *xdr)
{
  xdr->logvol = strdup (pbc->logvol);
  xdr->volgroup = strdup (pbc->volgroup);
  xdr->mbytes = pbc->mbytes;
}

void
convert_sfdisk_args_xdr_to_protobuf (                                 guestfs_sfdisk_args *xdr,
                                 guestfs_protobuf_sfdisk_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->cyls = xdr->cyls;
  pbc->heads = xdr->heads;
  pbc->sectors = xdr->sectors;
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) 
{    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_sfdisk_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_args *pbc,
                                 guestfs_sfdisk_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->cyls = pbc->cyls;
  xdr->heads = pbc->heads;
  xdr->sectors = pbc->sectors;
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) 
{    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_write_file_args_xdr_to_protobuf (                                 guestfs_write_file_args *xdr,
                                 guestfs_protobuf_write_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->content = strdup (xdr->content);
  pbc->size = xdr->size;
}

void
convert_write_file_args_protobuf_to_xdr (                                 guestfs_protobuf_write_file_args *pbc,
                                 guestfs_write_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->content = strdup (pbc->content);
  xdr->size = pbc->size;
}

void
convert_umount_args_xdr_to_protobuf (                                 guestfs_umount_args *xdr,
                                 guestfs_protobuf_umount_args *pbc)
{
  pbc->pathordevice = strdup (xdr->pathordevice);
  pbc->force = xdr->force;
  pbc->lazyunmount = xdr->lazyunmount;
}

void
convert_umount_args_protobuf_to_xdr (                                 guestfs_protobuf_umount_args *pbc,
                                 guestfs_umount_args *xdr)
{
  xdr->pathordevice = strdup (pbc->pathordevice);
  xdr->force = pbc->force;
  xdr->lazyunmount = pbc->lazyunmount;
}

void
convert_mounts_ret_xdr_to_protobuf (                                guestfs_mounts_ret *xdr,
                                guestfs_protobuf_mounts_ret *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) {
    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_mounts_ret_protobuf_to_xdr (                                guestfs_protobuf_mounts_ret *pbc,
                                guestfs_mounts_ret *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) {
    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_file_args_xdr_to_protobuf (                                 guestfs_file_args *xdr,
                                 guestfs_protobuf_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_file_args_protobuf_to_xdr (                                 guestfs_protobuf_file_args *pbc,
                                 guestfs_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_file_ret_xdr_to_protobuf (                                guestfs_file_ret *xdr,
                                guestfs_protobuf_file_ret *pbc)
{
  pbc->description = strdup (xdr->description);
}

void
convert_file_ret_protobuf_to_xdr (                                guestfs_protobuf_file_ret *pbc,
                                guestfs_file_ret *xdr)
{
  xdr->description = strdup (pbc->description);
}

void
convert_command_args_xdr_to_protobuf (                                 guestfs_command_args *xdr,
                                 guestfs_protobuf_command_args *pbc)
{
  pbc->arguments = malloc (xdr->arguments.arguments_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->arguments.arguments_len; ++i) 
{    pbc->n_arguments = i;
    pbc->arguments[i] = xdr->arguments.arguments_val[i] ? strdup (xdr->arguments.arguments_val[i]) : NULL;
  }
}

void
convert_command_args_protobuf_to_xdr (                                 guestfs_protobuf_command_args *pbc,
                                 guestfs_command_args *xdr)
{
  xdr->arguments.arguments_val = malloc (pbc->n_arguments * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_arguments; ++i) 
{    xdr->arguments.arguments_len = i;
    xdr->arguments.arguments_val[i] = pbc->arguments[i] ? strdup (pbc->arguments[i]) : NULL;
  }
}

void
convert_command_ret_xdr_to_protobuf (                                guestfs_command_ret *xdr,
                                guestfs_protobuf_command_ret *pbc)
{
  pbc->output = strdup (xdr->output);
}

void
convert_command_ret_protobuf_to_xdr (                                guestfs_protobuf_command_ret *pbc,
                                guestfs_command_ret *xdr)
{
  xdr->output = strdup (pbc->output);
}

void
convert_command_lines_args_xdr_to_protobuf (                                 guestfs_command_lines_args *xdr,
                                 guestfs_protobuf_command_lines_args *pbc)
{
  pbc->arguments = malloc (xdr->arguments.arguments_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->arguments.arguments_len; ++i) 
{    pbc->n_arguments = i;
    pbc->arguments[i] = xdr->arguments.arguments_val[i] ? strdup (xdr->arguments.arguments_val[i]) : NULL;
  }
}

void
convert_command_lines_args_protobuf_to_xdr (                                 guestfs_protobuf_command_lines_args *pbc,
                                 guestfs_command_lines_args *xdr)
{
  xdr->arguments.arguments_val = malloc (pbc->n_arguments * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_arguments; ++i) 
{    xdr->arguments.arguments_len = i;
    xdr->arguments.arguments_val[i] = pbc->arguments[i] ? strdup (pbc->arguments[i]) : NULL;
  }
}

void
convert_command_lines_ret_xdr_to_protobuf (                                guestfs_command_lines_ret *xdr,
                                guestfs_protobuf_command_lines_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_command_lines_ret_protobuf_to_xdr (                                guestfs_protobuf_command_lines_ret *pbc,
                                guestfs_command_lines_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_statvfs_args_xdr_to_protobuf (                                 guestfs_statvfs_args *xdr,
                                 guestfs_protobuf_statvfs_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_statvfs_args_protobuf_to_xdr (                                 guestfs_protobuf_statvfs_args *pbc,
                                 guestfs_statvfs_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_statvfs_ret_xdr_to_protobuf (                                guestfs_statvfs_ret *xdr,
                                guestfs_protobuf_statvfs_ret *pbc)
{
  pbc->statbuf = malloc (sizeof (guestfs_protobuf_int_statvfs));
  convert_guestfs_int_statvfs_xdr_to_protobuf (&xdr->statbuf, pbc->statbuf);
}

void
convert_statvfs_ret_protobuf_to_xdr (                                guestfs_protobuf_statvfs_ret *pbc,
                                guestfs_statvfs_ret *xdr)
{
  convert_guestfs_int_statvfs_protobuf_to_xdr (pbc->statbuf, &xdr->statbuf);
}

void
convert_tune2fs_ll_args_xdr_to_protobuf (                                 guestfs_tune2fs_ll_args *xdr,
                                 guestfs_protobuf_tune2fs_ll_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_tune2fs_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_tune2fs_ll_args *pbc,
                                 guestfs_tune2fs_ll_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_tune2fs_ll_ret_xdr_to_protobuf (                                guestfs_tune2fs_ll_ret *xdr,
                                guestfs_protobuf_tune2fs_ll_ret *pbc)
{
  pbc->superblock = malloc (xdr->superblock.superblock_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->superblock.superblock_len; ++i) {
    pbc->n_superblock = i;
    pbc->superblock[i] = xdr->superblock.superblock_val[i] ? strdup (xdr->superblock.superblock_val[i]) : NULL;
  }
}

void
convert_tune2fs_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_tune2fs_ll_ret *pbc,
                                guestfs_tune2fs_ll_ret *xdr)
{
  xdr->superblock.superblock_val = malloc (pbc->n_superblock * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_superblock; ++i) {
    xdr->superblock.superblock_len = i;
    xdr->superblock.superblock_val[i] = pbc->superblock[i] ? strdup (pbc->superblock[i]) : NULL;
  }
}

void
convert_blockdev_setro_args_xdr_to_protobuf (                                 guestfs_blockdev_setro_args *xdr,
                                 guestfs_protobuf_blockdev_setro_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_setro_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_setro_args *pbc,
                                 guestfs_blockdev_setro_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_setrw_args_xdr_to_protobuf (                                 guestfs_blockdev_setrw_args *xdr,
                                 guestfs_protobuf_blockdev_setrw_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_setrw_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_setrw_args *pbc,
                                 guestfs_blockdev_setrw_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_getro_args_xdr_to_protobuf (                                 guestfs_blockdev_getro_args *xdr,
                                 guestfs_protobuf_blockdev_getro_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_getro_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getro_args *pbc,
                                 guestfs_blockdev_getro_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_getro_ret_xdr_to_protobuf (                                guestfs_blockdev_getro_ret *xdr,
                                guestfs_protobuf_blockdev_getro_ret *pbc)
{
  pbc->ro = xdr->ro;
}

void
convert_blockdev_getro_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getro_ret *pbc,
                                guestfs_blockdev_getro_ret *xdr)
{
  xdr->ro = pbc->ro;
}

void
convert_blockdev_getss_args_xdr_to_protobuf (                                 guestfs_blockdev_getss_args *xdr,
                                 guestfs_protobuf_blockdev_getss_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_getss_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getss_args *pbc,
                                 guestfs_blockdev_getss_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_getss_ret_xdr_to_protobuf (                                guestfs_blockdev_getss_ret *xdr,
                                guestfs_protobuf_blockdev_getss_ret *pbc)
{
  pbc->sectorsize = xdr->sectorsize;
}

void
convert_blockdev_getss_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getss_ret *pbc,
                                guestfs_blockdev_getss_ret *xdr)
{
  xdr->sectorsize = pbc->sectorsize;
}

void
convert_blockdev_getbsz_args_xdr_to_protobuf (                                 guestfs_blockdev_getbsz_args *xdr,
                                 guestfs_protobuf_blockdev_getbsz_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_getbsz_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getbsz_args *pbc,
                                 guestfs_blockdev_getbsz_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_getbsz_ret_xdr_to_protobuf (                                guestfs_blockdev_getbsz_ret *xdr,
                                guestfs_protobuf_blockdev_getbsz_ret *pbc)
{
  pbc->blocksize = xdr->blocksize;
}

void
convert_blockdev_getbsz_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getbsz_ret *pbc,
                                guestfs_blockdev_getbsz_ret *xdr)
{
  xdr->blocksize = pbc->blocksize;
}

void
convert_blockdev_setbsz_args_xdr_to_protobuf (                                 guestfs_blockdev_setbsz_args *xdr,
                                 guestfs_protobuf_blockdev_setbsz_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->blocksize = xdr->blocksize;
}

void
convert_blockdev_setbsz_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_setbsz_args *pbc,
                                 guestfs_blockdev_setbsz_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->blocksize = pbc->blocksize;
}

void
convert_blockdev_getsz_args_xdr_to_protobuf (                                 guestfs_blockdev_getsz_args *xdr,
                                 guestfs_protobuf_blockdev_getsz_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_getsz_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getsz_args *pbc,
                                 guestfs_blockdev_getsz_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_getsz_ret_xdr_to_protobuf (                                guestfs_blockdev_getsz_ret *xdr,
                                guestfs_protobuf_blockdev_getsz_ret *pbc)
{
  pbc->sizeinsectors = xdr->sizeinsectors;
}

void
convert_blockdev_getsz_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getsz_ret *pbc,
                                guestfs_blockdev_getsz_ret *xdr)
{
  xdr->sizeinsectors = pbc->sizeinsectors;
}

void
convert_blockdev_getsize64_args_xdr_to_protobuf (                                 guestfs_blockdev_getsize64_args *xdr,
                                 guestfs_protobuf_blockdev_getsize64_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_getsize64_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_getsize64_args *pbc,
                                 guestfs_blockdev_getsize64_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_getsize64_ret_xdr_to_protobuf (                                guestfs_blockdev_getsize64_ret *xdr,
                                guestfs_protobuf_blockdev_getsize64_ret *pbc)
{
  pbc->sizeinbytes = xdr->sizeinbytes;
}

void
convert_blockdev_getsize64_ret_protobuf_to_xdr (                                guestfs_protobuf_blockdev_getsize64_ret *pbc,
                                guestfs_blockdev_getsize64_ret *xdr)
{
  xdr->sizeinbytes = pbc->sizeinbytes;
}

void
convert_blockdev_flushbufs_args_xdr_to_protobuf (                                 guestfs_blockdev_flushbufs_args *xdr,
                                 guestfs_protobuf_blockdev_flushbufs_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_flushbufs_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_flushbufs_args *pbc,
                                 guestfs_blockdev_flushbufs_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blockdev_rereadpt_args_xdr_to_protobuf (                                 guestfs_blockdev_rereadpt_args *xdr,
                                 guestfs_protobuf_blockdev_rereadpt_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blockdev_rereadpt_args_protobuf_to_xdr (                                 guestfs_protobuf_blockdev_rereadpt_args *pbc,
                                 guestfs_blockdev_rereadpt_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_upload_args_xdr_to_protobuf (                                 guestfs_upload_args *xdr,
                                 guestfs_protobuf_upload_args *pbc)
{
  pbc->remotefilename = strdup (xdr->remotefilename);
}

void
convert_upload_args_protobuf_to_xdr (                                 guestfs_protobuf_upload_args *pbc,
                                 guestfs_upload_args *xdr)
{
  xdr->remotefilename = strdup (pbc->remotefilename);
}

void
convert_download_args_xdr_to_protobuf (                                 guestfs_download_args *xdr,
                                 guestfs_protobuf_download_args *pbc)
{
  pbc->remotefilename = strdup (xdr->remotefilename);
}

void
convert_download_args_protobuf_to_xdr (                                 guestfs_protobuf_download_args *pbc,
                                 guestfs_download_args *xdr)
{
  xdr->remotefilename = strdup (pbc->remotefilename);
}

void
convert_checksum_args_xdr_to_protobuf (                                 guestfs_checksum_args *xdr,
                                 guestfs_protobuf_checksum_args *pbc)
{
  pbc->csumtype = strdup (xdr->csumtype);
  pbc->path = strdup (xdr->path);
}

void
convert_checksum_args_protobuf_to_xdr (                                 guestfs_protobuf_checksum_args *pbc,
                                 guestfs_checksum_args *xdr)
{
  xdr->csumtype = strdup (pbc->csumtype);
  xdr->path = strdup (pbc->path);
}

void
convert_checksum_ret_xdr_to_protobuf (                                guestfs_checksum_ret *xdr,
                                guestfs_protobuf_checksum_ret *pbc)
{
  pbc->checksum = strdup (xdr->checksum);
}

void
convert_checksum_ret_protobuf_to_xdr (                                guestfs_protobuf_checksum_ret *pbc,
                                guestfs_checksum_ret *xdr)
{
  xdr->checksum = strdup (pbc->checksum);
}

void
convert_tar_in_args_xdr_to_protobuf (                                 guestfs_tar_in_args *xdr,
                                 guestfs_protobuf_tar_in_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
  pbc->compress = strdup (xdr->compress);
}

void
convert_tar_in_args_protobuf_to_xdr (                                 guestfs_protobuf_tar_in_args *pbc,
                                 guestfs_tar_in_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
  xdr->compress = strdup (pbc->compress);
}

void
convert_tar_out_args_xdr_to_protobuf (                                 guestfs_tar_out_args *xdr,
                                 guestfs_protobuf_tar_out_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
  pbc->compress = strdup (xdr->compress);
  pbc->numericowner = xdr->numericowner;
  pbc->excludes = malloc (xdr->excludes.excludes_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->excludes.excludes_len; ++i) 
{    pbc->n_excludes = i;
    pbc->excludes[i] = xdr->excludes.excludes_val[i] ? strdup (xdr->excludes.excludes_val[i]) : NULL;
  }
}

void
convert_tar_out_args_protobuf_to_xdr (                                 guestfs_protobuf_tar_out_args *pbc,
                                 guestfs_tar_out_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
  xdr->compress = strdup (pbc->compress);
  xdr->numericowner = pbc->numericowner;
  xdr->excludes.excludes_val = malloc (pbc->n_excludes * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_excludes; ++i) 
{    xdr->excludes.excludes_len = i;
    xdr->excludes.excludes_val[i] = pbc->excludes[i] ? strdup (pbc->excludes[i]) : NULL;
  }
}

void
convert_tgz_in_args_xdr_to_protobuf (                                 guestfs_tgz_in_args *xdr,
                                 guestfs_protobuf_tgz_in_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_tgz_in_args_protobuf_to_xdr (                                 guestfs_protobuf_tgz_in_args *pbc,
                                 guestfs_tgz_in_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_tgz_out_args_xdr_to_protobuf (                                 guestfs_tgz_out_args *xdr,
                                 guestfs_protobuf_tgz_out_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_tgz_out_args_protobuf_to_xdr (                                 guestfs_protobuf_tgz_out_args *pbc,
                                 guestfs_tgz_out_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_mount_ro_args_xdr_to_protobuf (                                 guestfs_mount_ro_args *xdr,
                                 guestfs_protobuf_mount_ro_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
  pbc->mountpoint = strdup (xdr->mountpoint);
}

void
convert_mount_ro_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_ro_args *pbc,
                                 guestfs_mount_ro_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
  xdr->mountpoint = strdup (pbc->mountpoint);
}

void
convert_mount_options_args_xdr_to_protobuf (                                 guestfs_mount_options_args *xdr,
                                 guestfs_protobuf_mount_options_args *pbc)
{
  pbc->options = strdup (xdr->options);
  pbc->mountable = strdup (xdr->mountable);
  pbc->mountpoint = strdup (xdr->mountpoint);
}

void
convert_mount_options_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_options_args *pbc,
                                 guestfs_mount_options_args *xdr)
{
  xdr->options = strdup (pbc->options);
  xdr->mountable = strdup (pbc->mountable);
  xdr->mountpoint = strdup (pbc->mountpoint);
}

void
convert_mount_vfs_args_xdr_to_protobuf (                                 guestfs_mount_vfs_args *xdr,
                                 guestfs_protobuf_mount_vfs_args *pbc)
{
  pbc->options = strdup (xdr->options);
  pbc->vfstype = strdup (xdr->vfstype);
  pbc->mountable = strdup (xdr->mountable);
  pbc->mountpoint = strdup (xdr->mountpoint);
}

void
convert_mount_vfs_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_vfs_args *pbc,
                                 guestfs_mount_vfs_args *xdr)
{
  xdr->options = strdup (pbc->options);
  xdr->vfstype = strdup (pbc->vfstype);
  xdr->mountable = strdup (pbc->mountable);
  xdr->mountpoint = strdup (pbc->mountpoint);
}

void
convert_debug_args_xdr_to_protobuf (                                 guestfs_debug_args *xdr,
                                 guestfs_protobuf_debug_args *pbc)
{
  pbc->subcmd = strdup (xdr->subcmd);
  pbc->extraargs = malloc (xdr->extraargs.extraargs_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->extraargs.extraargs_len; ++i) 
{    pbc->n_extraargs = i;
    pbc->extraargs[i] = xdr->extraargs.extraargs_val[i] ? strdup (xdr->extraargs.extraargs_val[i]) : NULL;
  }
}

void
convert_debug_args_protobuf_to_xdr (                                 guestfs_protobuf_debug_args *pbc,
                                 guestfs_debug_args *xdr)
{
  xdr->subcmd = strdup (pbc->subcmd);
  xdr->extraargs.extraargs_val = malloc (pbc->n_extraargs * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_extraargs; ++i) 
{    xdr->extraargs.extraargs_len = i;
    xdr->extraargs.extraargs_val[i] = pbc->extraargs[i] ? strdup (pbc->extraargs[i]) : NULL;
  }
}

void
convert_debug_ret_xdr_to_protobuf (                                guestfs_debug_ret *xdr,
                                guestfs_protobuf_debug_ret *pbc)
{
  pbc->result = strdup (xdr->result);
}

void
convert_debug_ret_protobuf_to_xdr (                                guestfs_protobuf_debug_ret *pbc,
                                guestfs_debug_ret *xdr)
{
  xdr->result = strdup (pbc->result);
}

void
convert_lvremove_args_xdr_to_protobuf (                                 guestfs_lvremove_args *xdr,
                                 guestfs_protobuf_lvremove_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_lvremove_args_protobuf_to_xdr (                                 guestfs_protobuf_lvremove_args *pbc,
                                 guestfs_lvremove_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_vgremove_args_xdr_to_protobuf (                                 guestfs_vgremove_args *xdr,
                                 guestfs_protobuf_vgremove_args *pbc)
{
  pbc->vgname = strdup (xdr->vgname);
}

void
convert_vgremove_args_protobuf_to_xdr (                                 guestfs_protobuf_vgremove_args *pbc,
                                 guestfs_vgremove_args *xdr)
{
  xdr->vgname = strdup (pbc->vgname);
}

void
convert_pvremove_args_xdr_to_protobuf (                                 guestfs_pvremove_args *xdr,
                                 guestfs_protobuf_pvremove_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_pvremove_args_protobuf_to_xdr (                                 guestfs_protobuf_pvremove_args *pbc,
                                 guestfs_pvremove_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_set_e2label_args_xdr_to_protobuf (                                 guestfs_set_e2label_args *xdr,
                                 guestfs_protobuf_set_e2label_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->label = strdup (xdr->label);
}

void
convert_set_e2label_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2label_args *pbc,
                                 guestfs_set_e2label_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->label = strdup (pbc->label);
}

void
convert_get_e2label_args_xdr_to_protobuf (                                 guestfs_get_e2label_args *xdr,
                                 guestfs_protobuf_get_e2label_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_get_e2label_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2label_args *pbc,
                                 guestfs_get_e2label_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_get_e2label_ret_xdr_to_protobuf (                                guestfs_get_e2label_ret *xdr,
                                guestfs_protobuf_get_e2label_ret *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_get_e2label_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2label_ret *pbc,
                                guestfs_get_e2label_ret *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_set_e2uuid_args_xdr_to_protobuf (                                 guestfs_set_e2uuid_args *xdr,
                                 guestfs_protobuf_set_e2uuid_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_set_e2uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2uuid_args *pbc,
                                 guestfs_set_e2uuid_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_get_e2uuid_args_xdr_to_protobuf (                                 guestfs_get_e2uuid_args *xdr,
                                 guestfs_protobuf_get_e2uuid_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_get_e2uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2uuid_args *pbc,
                                 guestfs_get_e2uuid_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_get_e2uuid_ret_xdr_to_protobuf (                                guestfs_get_e2uuid_ret *xdr,
                                guestfs_protobuf_get_e2uuid_ret *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_get_e2uuid_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2uuid_ret *pbc,
                                guestfs_get_e2uuid_ret *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_fsck_args_xdr_to_protobuf (                                 guestfs_fsck_args *xdr,
                                 guestfs_protobuf_fsck_args *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
  pbc->device = strdup (xdr->device);
}

void
convert_fsck_args_protobuf_to_xdr (                                 guestfs_protobuf_fsck_args *pbc,
                                 guestfs_fsck_args *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
  xdr->device = strdup (pbc->device);
}

void
convert_fsck_ret_xdr_to_protobuf (                                guestfs_fsck_ret *xdr,
                                guestfs_protobuf_fsck_ret *pbc)
{
  pbc->status = xdr->status;
}

void
convert_fsck_ret_protobuf_to_xdr (                                guestfs_protobuf_fsck_ret *pbc,
                                guestfs_fsck_ret *xdr)
{
  xdr->status = pbc->status;
}

void
convert_zero_args_xdr_to_protobuf (                                 guestfs_zero_args *xdr,
                                 guestfs_protobuf_zero_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_zero_args_protobuf_to_xdr (                                 guestfs_protobuf_zero_args *pbc,
                                 guestfs_zero_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_grub_install_args_xdr_to_protobuf (                                 guestfs_grub_install_args *xdr,
                                 guestfs_protobuf_grub_install_args *pbc)
{
  pbc->root = strdup (xdr->root);
  pbc->device = strdup (xdr->device);
}

void
convert_grub_install_args_protobuf_to_xdr (                                 guestfs_protobuf_grub_install_args *pbc,
                                 guestfs_grub_install_args *xdr)
{
  xdr->root = strdup (pbc->root);
  xdr->device = strdup (pbc->device);
}

void
convert_cp_args_xdr_to_protobuf (                                 guestfs_cp_args *xdr,
                                 guestfs_protobuf_cp_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
}

void
convert_cp_args_protobuf_to_xdr (                                 guestfs_protobuf_cp_args *pbc,
                                 guestfs_cp_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
}

void
convert_cp_aa_args_xdr_to_protobuf (                                 guestfs_cp_aa_args *xdr,
                                 guestfs_protobuf_cp_aa_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
}

void
convert_cp_aa_args_protobuf_to_xdr (                                 guestfs_protobuf_cp_aa_args *pbc,
                                 guestfs_cp_aa_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
}

void
convert_mv_args_xdr_to_protobuf (                                 guestfs_mv_args *xdr,
                                 guestfs_protobuf_mv_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
}

void
convert_mv_args_protobuf_to_xdr (                                 guestfs_protobuf_mv_args *pbc,
                                 guestfs_mv_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
}

void
convert_drop_caches_args_xdr_to_protobuf (                                 guestfs_drop_caches_args *xdr,
                                 guestfs_protobuf_drop_caches_args *pbc)
{
  pbc->whattodrop = xdr->whattodrop;
}

void
convert_drop_caches_args_protobuf_to_xdr (                                 guestfs_protobuf_drop_caches_args *pbc,
                                 guestfs_drop_caches_args *xdr)
{
  xdr->whattodrop = pbc->whattodrop;
}

void
convert_dmesg_ret_xdr_to_protobuf (                                guestfs_dmesg_ret *xdr,
                                guestfs_protobuf_dmesg_ret *pbc)
{
  pbc->kmsgs = strdup (xdr->kmsgs);
}

void
convert_dmesg_ret_protobuf_to_xdr (                                guestfs_protobuf_dmesg_ret *pbc,
                                guestfs_dmesg_ret *xdr)
{
  xdr->kmsgs = strdup (pbc->kmsgs);
}

void
convert_equal_args_xdr_to_protobuf (                                 guestfs_equal_args *xdr,
                                 guestfs_protobuf_equal_args *pbc)
{
  pbc->file1 = strdup (xdr->file1);
  pbc->file2 = strdup (xdr->file2);
}

void
convert_equal_args_protobuf_to_xdr (                                 guestfs_protobuf_equal_args *pbc,
                                 guestfs_equal_args *xdr)
{
  xdr->file1 = strdup (pbc->file1);
  xdr->file2 = strdup (pbc->file2);
}

void
convert_equal_ret_xdr_to_protobuf (                                guestfs_equal_ret *xdr,
                                guestfs_protobuf_equal_ret *pbc)
{
  pbc->equality = xdr->equality;
}

void
convert_equal_ret_protobuf_to_xdr (                                guestfs_protobuf_equal_ret *pbc,
                                guestfs_equal_ret *xdr)
{
  xdr->equality = pbc->equality;
}

void
convert_strings_args_xdr_to_protobuf (                                 guestfs_strings_args *xdr,
                                 guestfs_protobuf_strings_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_strings_args_protobuf_to_xdr (                                 guestfs_protobuf_strings_args *pbc,
                                 guestfs_strings_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_strings_ret_xdr_to_protobuf (                                guestfs_strings_ret *xdr,
                                guestfs_protobuf_strings_ret *pbc)
{
  pbc->stringsout = malloc (xdr->stringsout.stringsout_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->stringsout.stringsout_len; ++i) {
    pbc->n_stringsout = i;
    pbc->stringsout[i] = xdr->stringsout.stringsout_val[i] ? strdup (xdr->stringsout.stringsout_val[i]) : NULL;
  }
}

void
convert_strings_ret_protobuf_to_xdr (                                guestfs_protobuf_strings_ret *pbc,
                                guestfs_strings_ret *xdr)
{
  xdr->stringsout.stringsout_val = malloc (pbc->n_stringsout * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_stringsout; ++i) {
    xdr->stringsout.stringsout_len = i;
    xdr->stringsout.stringsout_val[i] = pbc->stringsout[i] ? strdup (pbc->stringsout[i]) : NULL;
  }
}

void
convert_strings_ee_args_xdr_to_protobuf (                                 guestfs_strings_ee_args *xdr,
                                 guestfs_protobuf_strings_ee_args *pbc)
{
  pbc->encoding = strdup (xdr->encoding);
  pbc->path = strdup (xdr->path);
}

void
convert_strings_ee_args_protobuf_to_xdr (                                 guestfs_protobuf_strings_ee_args *pbc,
                                 guestfs_strings_ee_args *xdr)
{
  xdr->encoding = strdup (pbc->encoding);
  xdr->path = strdup (pbc->path);
}

void
convert_strings_ee_ret_xdr_to_protobuf (                                guestfs_strings_ee_ret *xdr,
                                guestfs_protobuf_strings_ee_ret *pbc)
{
  pbc->stringsout = malloc (xdr->stringsout.stringsout_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->stringsout.stringsout_len; ++i) {
    pbc->n_stringsout = i;
    pbc->stringsout[i] = xdr->stringsout.stringsout_val[i] ? strdup (xdr->stringsout.stringsout_val[i]) : NULL;
  }
}

void
convert_strings_ee_ret_protobuf_to_xdr (                                guestfs_protobuf_strings_ee_ret *pbc,
                                guestfs_strings_ee_ret *xdr)
{
  xdr->stringsout.stringsout_val = malloc (pbc->n_stringsout * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_stringsout; ++i) {
    xdr->stringsout.stringsout_len = i;
    xdr->stringsout.stringsout_val[i] = pbc->stringsout[i] ? strdup (pbc->stringsout[i]) : NULL;
  }
}

void
convert_hexdump_args_xdr_to_protobuf (                                 guestfs_hexdump_args *xdr,
                                 guestfs_protobuf_hexdump_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_hexdump_args_protobuf_to_xdr (                                 guestfs_protobuf_hexdump_args *pbc,
                                 guestfs_hexdump_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_hexdump_ret_xdr_to_protobuf (                                guestfs_hexdump_ret *xdr,
                                guestfs_protobuf_hexdump_ret *pbc)
{
  pbc->dump = strdup (xdr->dump);
}

void
convert_hexdump_ret_protobuf_to_xdr (                                guestfs_protobuf_hexdump_ret *pbc,
                                guestfs_hexdump_ret *xdr)
{
  xdr->dump = strdup (pbc->dump);
}

void
convert_zerofree_args_xdr_to_protobuf (                                 guestfs_zerofree_args *xdr,
                                 guestfs_protobuf_zerofree_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_zerofree_args_protobuf_to_xdr (                                 guestfs_protobuf_zerofree_args *pbc,
                                 guestfs_zerofree_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_pvresize_args_xdr_to_protobuf (                                 guestfs_pvresize_args *xdr,
                                 guestfs_protobuf_pvresize_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_pvresize_args_protobuf_to_xdr (                                 guestfs_protobuf_pvresize_args *pbc,
                                 guestfs_pvresize_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_sfdisk_nn_args_xdr_to_protobuf (                                 guestfs_sfdisk_nn_args *xdr,
                                 guestfs_protobuf_sfdisk_nn_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
  pbc->cyls = xdr->cyls;
  pbc->heads = xdr->heads;
  pbc->sectors = xdr->sectors;
  pbc->line = strdup (xdr->line);
}

void
convert_sfdisk_nn_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_nn_args *pbc,
                                 guestfs_sfdisk_nn_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
  xdr->cyls = pbc->cyls;
  xdr->heads = pbc->heads;
  xdr->sectors = pbc->sectors;
  xdr->line = strdup (pbc->line);
}

void
convert_sfdisk_ll_args_xdr_to_protobuf (                                 guestfs_sfdisk_ll_args *xdr,
                                 guestfs_protobuf_sfdisk_ll_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_sfdisk_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_ll_args *pbc,
                                 guestfs_sfdisk_ll_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_sfdisk_ll_ret_xdr_to_protobuf (                                guestfs_sfdisk_ll_ret *xdr,
                                guestfs_protobuf_sfdisk_ll_ret *pbc)
{
  pbc->partitions = strdup (xdr->partitions);
}

void
convert_sfdisk_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_sfdisk_ll_ret *pbc,
                                guestfs_sfdisk_ll_ret *xdr)
{
  xdr->partitions = strdup (pbc->partitions);
}

void
convert_sfdisk_kernel_geometry_args_xdr_to_protobuf (                                 guestfs_sfdisk_kernel_geometry_args *xdr,
                                 guestfs_protobuf_sfdisk_kernel_geometry_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_sfdisk_kernel_geometry_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_kernel_geometry_args *pbc,
                                 guestfs_sfdisk_kernel_geometry_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_sfdisk_kernel_geometry_ret_xdr_to_protobuf (                                guestfs_sfdisk_kernel_geometry_ret *xdr,
                                guestfs_protobuf_sfdisk_kernel_geometry_ret *pbc)
{
  pbc->partitions = strdup (xdr->partitions);
}

void
convert_sfdisk_kernel_geometry_ret_protobuf_to_xdr (                                guestfs_protobuf_sfdisk_kernel_geometry_ret *pbc,
                                guestfs_sfdisk_kernel_geometry_ret *xdr)
{
  xdr->partitions = strdup (pbc->partitions);
}

void
convert_sfdisk_disk_geometry_args_xdr_to_protobuf (                                 guestfs_sfdisk_disk_geometry_args *xdr,
                                 guestfs_protobuf_sfdisk_disk_geometry_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_sfdisk_disk_geometry_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdisk_disk_geometry_args *pbc,
                                 guestfs_sfdisk_disk_geometry_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_sfdisk_disk_geometry_ret_xdr_to_protobuf (                                guestfs_sfdisk_disk_geometry_ret *xdr,
                                guestfs_protobuf_sfdisk_disk_geometry_ret *pbc)
{
  pbc->partitions = strdup (xdr->partitions);
}

void
convert_sfdisk_disk_geometry_ret_protobuf_to_xdr (                                guestfs_protobuf_sfdisk_disk_geometry_ret *pbc,
                                guestfs_sfdisk_disk_geometry_ret *xdr)
{
  xdr->partitions = strdup (pbc->partitions);
}

void
convert_vg_activate_all_args_xdr_to_protobuf (                                 guestfs_vg_activate_all_args *xdr,
                                 guestfs_protobuf_vg_activate_all_args *pbc)
{
  pbc->activate = xdr->activate;
}

void
convert_vg_activate_all_args_protobuf_to_xdr (                                 guestfs_protobuf_vg_activate_all_args *pbc,
                                 guestfs_vg_activate_all_args *xdr)
{
  xdr->activate = pbc->activate;
}

void
convert_vg_activate_args_xdr_to_protobuf (                                 guestfs_vg_activate_args *xdr,
                                 guestfs_protobuf_vg_activate_args *pbc)
{
  pbc->activate = xdr->activate;
  pbc->volgroups = malloc (xdr->volgroups.volgroups_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->volgroups.volgroups_len; ++i) 
{    pbc->n_volgroups = i;
    pbc->volgroups[i] = xdr->volgroups.volgroups_val[i] ? strdup (xdr->volgroups.volgroups_val[i]) : NULL;
  }
}

void
convert_vg_activate_args_protobuf_to_xdr (                                 guestfs_protobuf_vg_activate_args *pbc,
                                 guestfs_vg_activate_args *xdr)
{
  xdr->activate = pbc->activate;
  xdr->volgroups.volgroups_val = malloc (pbc->n_volgroups * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_volgroups; ++i) 
{    xdr->volgroups.volgroups_len = i;
    xdr->volgroups.volgroups_val[i] = pbc->volgroups[i] ? strdup (pbc->volgroups[i]) : NULL;
  }
}

void
convert_lvresize_args_xdr_to_protobuf (                                 guestfs_lvresize_args *xdr,
                                 guestfs_protobuf_lvresize_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->mbytes = xdr->mbytes;
}

void
convert_lvresize_args_protobuf_to_xdr (                                 guestfs_protobuf_lvresize_args *pbc,
                                 guestfs_lvresize_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->mbytes = pbc->mbytes;
}

void
convert_resize2fs_args_xdr_to_protobuf (                                 guestfs_resize2fs_args *xdr,
                                 guestfs_protobuf_resize2fs_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_resize2fs_args_protobuf_to_xdr (                                 guestfs_protobuf_resize2fs_args *pbc,
                                 guestfs_resize2fs_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_e2fsck_ff_args_xdr_to_protobuf (                                 guestfs_e2fsck_ff_args *xdr,
                                 guestfs_protobuf_e2fsck_ff_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_e2fsck_ff_args_protobuf_to_xdr (                                 guestfs_protobuf_e2fsck_ff_args *pbc,
                                 guestfs_e2fsck_ff_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_sleep_args_xdr_to_protobuf (                                 guestfs_sleep_args *xdr,
                                 guestfs_protobuf_sleep_args *pbc)
{
  pbc->secs = xdr->secs;
}

void
convert_sleep_args_protobuf_to_xdr (                                 guestfs_protobuf_sleep_args *pbc,
                                 guestfs_sleep_args *xdr)
{
  xdr->secs = pbc->secs;
}

void
convert_ntfs3g_probe_args_xdr_to_protobuf (                                 guestfs_ntfs3g_probe_args *xdr,
                                 guestfs_protobuf_ntfs3g_probe_args *pbc)
{
  pbc->rw = xdr->rw;
  pbc->device = strdup (xdr->device);
}

void
convert_ntfs3g_probe_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfs3g_probe_args *pbc,
                                 guestfs_ntfs3g_probe_args *xdr)
{
  xdr->rw = pbc->rw;
  xdr->device = strdup (pbc->device);
}

void
convert_ntfs3g_probe_ret_xdr_to_protobuf (                                guestfs_ntfs3g_probe_ret *xdr,
                                guestfs_protobuf_ntfs3g_probe_ret *pbc)
{
  pbc->status = xdr->status;
}

void
convert_ntfs3g_probe_ret_protobuf_to_xdr (                                guestfs_protobuf_ntfs3g_probe_ret *pbc,
                                guestfs_ntfs3g_probe_ret *xdr)
{
  xdr->status = pbc->status;
}

void
convert_sh_args_xdr_to_protobuf (                                 guestfs_sh_args *xdr,
                                 guestfs_protobuf_sh_args *pbc)
{
  pbc->command = strdup (xdr->command);
}

void
convert_sh_args_protobuf_to_xdr (                                 guestfs_protobuf_sh_args *pbc,
                                 guestfs_sh_args *xdr)
{
  xdr->command = strdup (pbc->command);
}

void
convert_sh_ret_xdr_to_protobuf (                                guestfs_sh_ret *xdr,
                                guestfs_protobuf_sh_ret *pbc)
{
  pbc->output = strdup (xdr->output);
}

void
convert_sh_ret_protobuf_to_xdr (                                guestfs_protobuf_sh_ret *pbc,
                                guestfs_sh_ret *xdr)
{
  xdr->output = strdup (pbc->output);
}

void
convert_sh_lines_args_xdr_to_protobuf (                                 guestfs_sh_lines_args *xdr,
                                 guestfs_protobuf_sh_lines_args *pbc)
{
  pbc->command = strdup (xdr->command);
}

void
convert_sh_lines_args_protobuf_to_xdr (                                 guestfs_protobuf_sh_lines_args *pbc,
                                 guestfs_sh_lines_args *xdr)
{
  xdr->command = strdup (pbc->command);
}

void
convert_sh_lines_ret_xdr_to_protobuf (                                guestfs_sh_lines_ret *xdr,
                                guestfs_protobuf_sh_lines_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_sh_lines_ret_protobuf_to_xdr (                                guestfs_protobuf_sh_lines_ret *pbc,
                                guestfs_sh_lines_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_glob_expand_args_xdr_to_protobuf (                                 guestfs_glob_expand_args *xdr,
                                 guestfs_protobuf_glob_expand_args *pbc)
{
  pbc->pattern = strdup (xdr->pattern);
}

void
convert_glob_expand_args_protobuf_to_xdr (                                 guestfs_protobuf_glob_expand_args *pbc,
                                 guestfs_glob_expand_args *xdr)
{
  xdr->pattern = strdup (pbc->pattern);
}

void
convert_glob_expand_ret_xdr_to_protobuf (                                guestfs_glob_expand_ret *xdr,
                                guestfs_protobuf_glob_expand_ret *pbc)
{
  pbc->paths = malloc (xdr->paths.paths_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->paths.paths_len; ++i) {
    pbc->n_paths = i;
    pbc->paths[i] = xdr->paths.paths_val[i] ? strdup (xdr->paths.paths_val[i]) : NULL;
  }
}

void
convert_glob_expand_ret_protobuf_to_xdr (                                guestfs_protobuf_glob_expand_ret *pbc,
                                guestfs_glob_expand_ret *xdr)
{
  xdr->paths.paths_val = malloc (pbc->n_paths * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_paths; ++i) {
    xdr->paths.paths_len = i;
    xdr->paths.paths_val[i] = pbc->paths[i] ? strdup (pbc->paths[i]) : NULL;
  }
}

void
convert_scrub_device_args_xdr_to_protobuf (                                 guestfs_scrub_device_args *xdr,
                                 guestfs_protobuf_scrub_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_scrub_device_args_protobuf_to_xdr (                                 guestfs_protobuf_scrub_device_args *pbc,
                                 guestfs_scrub_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_scrub_file_args_xdr_to_protobuf (                                 guestfs_scrub_file_args *xdr,
                                 guestfs_protobuf_scrub_file_args *pbc)
{
  pbc->file = strdup (xdr->file);
}

void
convert_scrub_file_args_protobuf_to_xdr (                                 guestfs_protobuf_scrub_file_args *pbc,
                                 guestfs_scrub_file_args *xdr)
{
  xdr->file = strdup (pbc->file);
}

void
convert_scrub_freespace_args_xdr_to_protobuf (                                 guestfs_scrub_freespace_args *xdr,
                                 guestfs_protobuf_scrub_freespace_args *pbc)
{
  pbc->dir = strdup (xdr->dir);
}

void
convert_scrub_freespace_args_protobuf_to_xdr (                                 guestfs_protobuf_scrub_freespace_args *pbc,
                                 guestfs_scrub_freespace_args *xdr)
{
  xdr->dir = strdup (pbc->dir);
}

void
convert_mkdtemp_args_xdr_to_protobuf (                                 guestfs_mkdtemp_args *xdr,
                                 guestfs_protobuf_mkdtemp_args *pbc)
{
  pbc->tmpl = strdup (xdr->tmpl);
}

void
convert_mkdtemp_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdtemp_args *pbc,
                                 guestfs_mkdtemp_args *xdr)
{
  xdr->tmpl = strdup (pbc->tmpl);
}

void
convert_mkdtemp_ret_xdr_to_protobuf (                                guestfs_mkdtemp_ret *xdr,
                                guestfs_protobuf_mkdtemp_ret *pbc)
{
  pbc->dir = strdup (xdr->dir);
}

void
convert_mkdtemp_ret_protobuf_to_xdr (                                guestfs_protobuf_mkdtemp_ret *pbc,
                                guestfs_mkdtemp_ret *xdr)
{
  xdr->dir = strdup (pbc->dir);
}

void
convert_wc_ll_args_xdr_to_protobuf (                                 guestfs_wc_ll_args *xdr,
                                 guestfs_protobuf_wc_ll_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_wc_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_wc_ll_args *pbc,
                                 guestfs_wc_ll_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_wc_ll_ret_xdr_to_protobuf (                                guestfs_wc_ll_ret *xdr,
                                guestfs_protobuf_wc_ll_ret *pbc)
{
  pbc->lines = xdr->lines;
}

void
convert_wc_ll_ret_protobuf_to_xdr (                                guestfs_protobuf_wc_ll_ret *pbc,
                                guestfs_wc_ll_ret *xdr)
{
  xdr->lines = pbc->lines;
}

void
convert_wc_ww_args_xdr_to_protobuf (                                 guestfs_wc_ww_args *xdr,
                                 guestfs_protobuf_wc_ww_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_wc_ww_args_protobuf_to_xdr (                                 guestfs_protobuf_wc_ww_args *pbc,
                                 guestfs_wc_ww_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_wc_ww_ret_xdr_to_protobuf (                                guestfs_wc_ww_ret *xdr,
                                guestfs_protobuf_wc_ww_ret *pbc)
{
  pbc->words = xdr->words;
}

void
convert_wc_ww_ret_protobuf_to_xdr (                                guestfs_protobuf_wc_ww_ret *pbc,
                                guestfs_wc_ww_ret *xdr)
{
  xdr->words = pbc->words;
}

void
convert_wc_cc_args_xdr_to_protobuf (                                 guestfs_wc_cc_args *xdr,
                                 guestfs_protobuf_wc_cc_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_wc_cc_args_protobuf_to_xdr (                                 guestfs_protobuf_wc_cc_args *pbc,
                                 guestfs_wc_cc_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_wc_cc_ret_xdr_to_protobuf (                                guestfs_wc_cc_ret *xdr,
                                guestfs_protobuf_wc_cc_ret *pbc)
{
  pbc->chars = xdr->chars;
}

void
convert_wc_cc_ret_protobuf_to_xdr (                                guestfs_protobuf_wc_cc_ret *pbc,
                                guestfs_wc_cc_ret *xdr)
{
  xdr->chars = pbc->chars;
}

void
convert_head_args_xdr_to_protobuf (                                 guestfs_head_args *xdr,
                                 guestfs_protobuf_head_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_head_args_protobuf_to_xdr (                                 guestfs_protobuf_head_args *pbc,
                                 guestfs_head_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_head_ret_xdr_to_protobuf (                                guestfs_head_ret *xdr,
                                guestfs_protobuf_head_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_head_ret_protobuf_to_xdr (                                guestfs_protobuf_head_ret *pbc,
                                guestfs_head_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_head_nn_args_xdr_to_protobuf (                                 guestfs_head_nn_args *xdr,
                                 guestfs_protobuf_head_nn_args *pbc)
{
  pbc->nrlines = xdr->nrlines;
  pbc->path = strdup (xdr->path);
}

void
convert_head_nn_args_protobuf_to_xdr (                                 guestfs_protobuf_head_nn_args *pbc,
                                 guestfs_head_nn_args *xdr)
{
  xdr->nrlines = pbc->nrlines;
  xdr->path = strdup (pbc->path);
}

void
convert_head_nn_ret_xdr_to_protobuf (                                guestfs_head_nn_ret *xdr,
                                guestfs_protobuf_head_nn_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_head_nn_ret_protobuf_to_xdr (                                guestfs_protobuf_head_nn_ret *pbc,
                                guestfs_head_nn_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_tail_args_xdr_to_protobuf (                                 guestfs_tail_args *xdr,
                                 guestfs_protobuf_tail_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_tail_args_protobuf_to_xdr (                                 guestfs_protobuf_tail_args *pbc,
                                 guestfs_tail_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_tail_ret_xdr_to_protobuf (                                guestfs_tail_ret *xdr,
                                guestfs_protobuf_tail_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_tail_ret_protobuf_to_xdr (                                guestfs_protobuf_tail_ret *pbc,
                                guestfs_tail_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_tail_nn_args_xdr_to_protobuf (                                 guestfs_tail_nn_args *xdr,
                                 guestfs_protobuf_tail_nn_args *pbc)
{
  pbc->nrlines = xdr->nrlines;
  pbc->path = strdup (xdr->path);
}

void
convert_tail_nn_args_protobuf_to_xdr (                                 guestfs_protobuf_tail_nn_args *pbc,
                                 guestfs_tail_nn_args *xdr)
{
  xdr->nrlines = pbc->nrlines;
  xdr->path = strdup (pbc->path);
}

void
convert_tail_nn_ret_xdr_to_protobuf (                                guestfs_tail_nn_ret *xdr,
                                guestfs_protobuf_tail_nn_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_tail_nn_ret_protobuf_to_xdr (                                guestfs_protobuf_tail_nn_ret *pbc,
                                guestfs_tail_nn_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_df_ret_xdr_to_protobuf (                                guestfs_df_ret *xdr,
                                guestfs_protobuf_df_ret *pbc)
{
  pbc->output = strdup (xdr->output);
}

void
convert_df_ret_protobuf_to_xdr (                                guestfs_protobuf_df_ret *pbc,
                                guestfs_df_ret *xdr)
{
  xdr->output = strdup (pbc->output);
}

void
convert_df_hh_ret_xdr_to_protobuf (                                guestfs_df_hh_ret *xdr,
                                guestfs_protobuf_df_hh_ret *pbc)
{
  pbc->output = strdup (xdr->output);
}

void
convert_df_hh_ret_protobuf_to_xdr (                                guestfs_protobuf_df_hh_ret *pbc,
                                guestfs_df_hh_ret *xdr)
{
  xdr->output = strdup (pbc->output);
}

void
convert_du_args_xdr_to_protobuf (                                 guestfs_du_args *xdr,
                                 guestfs_protobuf_du_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_du_args_protobuf_to_xdr (                                 guestfs_protobuf_du_args *pbc,
                                 guestfs_du_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_du_ret_xdr_to_protobuf (                                guestfs_du_ret *xdr,
                                guestfs_protobuf_du_ret *pbc)
{
  pbc->sizekb = xdr->sizekb;
}

void
convert_du_ret_protobuf_to_xdr (                                guestfs_protobuf_du_ret *pbc,
                                guestfs_du_ret *xdr)
{
  xdr->sizekb = pbc->sizekb;
}

void
convert_initrd_list_args_xdr_to_protobuf (                                 guestfs_initrd_list_args *xdr,
                                 guestfs_protobuf_initrd_list_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_initrd_list_args_protobuf_to_xdr (                                 guestfs_protobuf_initrd_list_args *pbc,
                                 guestfs_initrd_list_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_initrd_list_ret_xdr_to_protobuf (                                guestfs_initrd_list_ret *xdr,
                                guestfs_protobuf_initrd_list_ret *pbc)
{
  pbc->filenames = malloc (xdr->filenames.filenames_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->filenames.filenames_len; ++i) {
    pbc->n_filenames = i;
    pbc->filenames[i] = xdr->filenames.filenames_val[i] ? strdup (xdr->filenames.filenames_val[i]) : NULL;
  }
}

void
convert_initrd_list_ret_protobuf_to_xdr (                                guestfs_protobuf_initrd_list_ret *pbc,
                                guestfs_initrd_list_ret *xdr)
{
  xdr->filenames.filenames_val = malloc (pbc->n_filenames * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_filenames; ++i) {
    xdr->filenames.filenames_len = i;
    xdr->filenames.filenames_val[i] = pbc->filenames[i] ? strdup (pbc->filenames[i]) : NULL;
  }
}

void
convert_mount_loop_args_xdr_to_protobuf (                                 guestfs_mount_loop_args *xdr,
                                 guestfs_protobuf_mount_loop_args *pbc)
{
  pbc->file = strdup (xdr->file);
  pbc->mountpoint = strdup (xdr->mountpoint);
}

void
convert_mount_loop_args_protobuf_to_xdr (                                 guestfs_protobuf_mount_loop_args *pbc,
                                 guestfs_mount_loop_args *xdr)
{
  xdr->file = strdup (pbc->file);
  xdr->mountpoint = strdup (pbc->mountpoint);
}

void
convert_mkswap_args_xdr_to_protobuf (                                 guestfs_mkswap_args *xdr,
                                 guestfs_protobuf_mkswap_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->label = strdup (xdr->label);
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_mkswap_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_args *pbc,
                                 guestfs_mkswap_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->label = strdup (pbc->label);
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_mkswap_ll_args_xdr_to_protobuf (                                 guestfs_mkswap_ll_args *xdr,
                                 guestfs_protobuf_mkswap_ll_args *pbc)
{
  pbc->label = strdup (xdr->label);
  pbc->device = strdup (xdr->device);
}

void
convert_mkswap_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_ll_args *pbc,
                                 guestfs_mkswap_ll_args *xdr)
{
  xdr->label = strdup (pbc->label);
  xdr->device = strdup (pbc->device);
}

void
convert_mkswap_uu_args_xdr_to_protobuf (                                 guestfs_mkswap_uu_args *xdr,
                                 guestfs_protobuf_mkswap_uu_args *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
  pbc->device = strdup (xdr->device);
}

void
convert_mkswap_uu_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_uu_args *pbc,
                                 guestfs_mkswap_uu_args *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
  xdr->device = strdup (pbc->device);
}

void
convert_mknod_args_xdr_to_protobuf (                                 guestfs_mknod_args *xdr,
                                 guestfs_protobuf_mknod_args *pbc)
{
  pbc->mode = xdr->mode;
  pbc->devmajor = xdr->devmajor;
  pbc->devminor = xdr->devminor;
  pbc->path = strdup (xdr->path);
}

void
convert_mknod_args_protobuf_to_xdr (                                 guestfs_protobuf_mknod_args *pbc,
                                 guestfs_mknod_args *xdr)
{
  xdr->mode = pbc->mode;
  xdr->devmajor = pbc->devmajor;
  xdr->devminor = pbc->devminor;
  xdr->path = strdup (pbc->path);
}

void
convert_mkfifo_args_xdr_to_protobuf (                                 guestfs_mkfifo_args *xdr,
                                 guestfs_protobuf_mkfifo_args *pbc)
{
  pbc->mode = xdr->mode;
  pbc->path = strdup (xdr->path);
}

void
convert_mkfifo_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfifo_args *pbc,
                                 guestfs_mkfifo_args *xdr)
{
  xdr->mode = pbc->mode;
  xdr->path = strdup (pbc->path);
}

void
convert_mknod_bb_args_xdr_to_protobuf (                                 guestfs_mknod_bb_args *xdr,
                                 guestfs_protobuf_mknod_bb_args *pbc)
{
  pbc->mode = xdr->mode;
  pbc->devmajor = xdr->devmajor;
  pbc->devminor = xdr->devminor;
  pbc->path = strdup (xdr->path);
}

void
convert_mknod_bb_args_protobuf_to_xdr (                                 guestfs_protobuf_mknod_bb_args *pbc,
                                 guestfs_mknod_bb_args *xdr)
{
  xdr->mode = pbc->mode;
  xdr->devmajor = pbc->devmajor;
  xdr->devminor = pbc->devminor;
  xdr->path = strdup (pbc->path);
}

void
convert_mknod_cc_args_xdr_to_protobuf (                                 guestfs_mknod_cc_args *xdr,
                                 guestfs_protobuf_mknod_cc_args *pbc)
{
  pbc->mode = xdr->mode;
  pbc->devmajor = xdr->devmajor;
  pbc->devminor = xdr->devminor;
  pbc->path = strdup (xdr->path);
}

void
convert_mknod_cc_args_protobuf_to_xdr (                                 guestfs_protobuf_mknod_cc_args *pbc,
                                 guestfs_mknod_cc_args *xdr)
{
  xdr->mode = pbc->mode;
  xdr->devmajor = pbc->devmajor;
  xdr->devminor = pbc->devminor;
  xdr->path = strdup (pbc->path);
}

void
convert_umask_args_xdr_to_protobuf (                                 guestfs_umask_args *xdr,
                                 guestfs_protobuf_umask_args *pbc)
{
  pbc->mask = xdr->mask;
}

void
convert_umask_args_protobuf_to_xdr (                                 guestfs_protobuf_umask_args *pbc,
                                 guestfs_umask_args *xdr)
{
  xdr->mask = pbc->mask;
}

void
convert_umask_ret_xdr_to_protobuf (                                guestfs_umask_ret *xdr,
                                guestfs_protobuf_umask_ret *pbc)
{
  pbc->oldmask = xdr->oldmask;
}

void
convert_umask_ret_protobuf_to_xdr (                                guestfs_protobuf_umask_ret *pbc,
                                guestfs_umask_ret *xdr)
{
  xdr->oldmask = pbc->oldmask;
}

void
convert_readdir_args_xdr_to_protobuf (                                 guestfs_readdir_args *xdr,
                                 guestfs_protobuf_readdir_args *pbc)
{
  pbc->dir = strdup (xdr->dir);
}

void
convert_readdir_args_protobuf_to_xdr (                                 guestfs_protobuf_readdir_args *pbc,
                                 guestfs_readdir_args *xdr)
{
  xdr->dir = strdup (pbc->dir);
}

void
convert_readdir_ret_xdr_to_protobuf (                                guestfs_readdir_ret *xdr,
                                guestfs_protobuf_readdir_ret *pbc)
{
  pbc->entries = malloc (sizeof (guestfs_protobuf_int_dirent_list));
  convert_guestfs_int_dirent_list_xdr_to_protobuf (&xdr->entries, pbc->entries);
}

void
convert_readdir_ret_protobuf_to_xdr (                                guestfs_protobuf_readdir_ret *pbc,
                                guestfs_readdir_ret *xdr)
{
  convert_guestfs_int_dirent_list_protobuf_to_xdr (pbc->entries, &xdr->entries);
}

void
convert_sfdiskm_args_xdr_to_protobuf (                                 guestfs_sfdiskm_args *xdr,
                                 guestfs_protobuf_sfdiskm_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) 
{    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_sfdiskm_args_protobuf_to_xdr (                                 guestfs_protobuf_sfdiskm_args *pbc,
                                 guestfs_sfdiskm_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) 
{    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zfile_args_xdr_to_protobuf (                                 guestfs_zfile_args *xdr,
                                 guestfs_protobuf_zfile_args *pbc)
{
  pbc->meth = strdup (xdr->meth);
  pbc->path = strdup (xdr->path);
}

void
convert_zfile_args_protobuf_to_xdr (                                 guestfs_protobuf_zfile_args *pbc,
                                 guestfs_zfile_args *xdr)
{
  xdr->meth = strdup (pbc->meth);
  xdr->path = strdup (pbc->path);
}

void
convert_zfile_ret_xdr_to_protobuf (                                guestfs_zfile_ret *xdr,
                                guestfs_protobuf_zfile_ret *pbc)
{
  pbc->description = strdup (xdr->description);
}

void
convert_zfile_ret_protobuf_to_xdr (                                guestfs_protobuf_zfile_ret *pbc,
                                guestfs_zfile_ret *xdr)
{
  xdr->description = strdup (pbc->description);
}

void
convert_getxattrs_args_xdr_to_protobuf (                                 guestfs_getxattrs_args *xdr,
                                 guestfs_protobuf_getxattrs_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_getxattrs_args_protobuf_to_xdr (                                 guestfs_protobuf_getxattrs_args *pbc,
                                 guestfs_getxattrs_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_getxattrs_ret_xdr_to_protobuf (                                guestfs_getxattrs_ret *xdr,
                                guestfs_protobuf_getxattrs_ret *pbc)
{
  pbc->xattrs = malloc (sizeof (guestfs_protobuf_int_xattr_list));
  convert_guestfs_int_xattr_list_xdr_to_protobuf (&xdr->xattrs, pbc->xattrs);
}

void
convert_getxattrs_ret_protobuf_to_xdr (                                guestfs_protobuf_getxattrs_ret *pbc,
                                guestfs_getxattrs_ret *xdr)
{
  convert_guestfs_int_xattr_list_protobuf_to_xdr (pbc->xattrs, &xdr->xattrs);
}

void
convert_lgetxattrs_args_xdr_to_protobuf (                                 guestfs_lgetxattrs_args *xdr,
                                 guestfs_protobuf_lgetxattrs_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_lgetxattrs_args_protobuf_to_xdr (                                 guestfs_protobuf_lgetxattrs_args *pbc,
                                 guestfs_lgetxattrs_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_lgetxattrs_ret_xdr_to_protobuf (                                guestfs_lgetxattrs_ret *xdr,
                                guestfs_protobuf_lgetxattrs_ret *pbc)
{
  pbc->xattrs = malloc (sizeof (guestfs_protobuf_int_xattr_list));
  convert_guestfs_int_xattr_list_xdr_to_protobuf (&xdr->xattrs, pbc->xattrs);
}

void
convert_lgetxattrs_ret_protobuf_to_xdr (                                guestfs_protobuf_lgetxattrs_ret *pbc,
                                guestfs_lgetxattrs_ret *xdr)
{
  convert_guestfs_int_xattr_list_protobuf_to_xdr (pbc->xattrs, &xdr->xattrs);
}

void
convert_setxattr_args_xdr_to_protobuf (                                 guestfs_setxattr_args *xdr,
                                 guestfs_protobuf_setxattr_args *pbc)
{
  pbc->xattr = strdup (xdr->xattr);
  pbc->val = strdup (xdr->val);
  pbc->vallen = xdr->vallen;
  pbc->path = strdup (xdr->path);
}

void
convert_setxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_setxattr_args *pbc,
                                 guestfs_setxattr_args *xdr)
{
  xdr->xattr = strdup (pbc->xattr);
  xdr->val = strdup (pbc->val);
  xdr->vallen = pbc->vallen;
  xdr->path = strdup (pbc->path);
}

void
convert_lsetxattr_args_xdr_to_protobuf (                                 guestfs_lsetxattr_args *xdr,
                                 guestfs_protobuf_lsetxattr_args *pbc)
{
  pbc->xattr = strdup (xdr->xattr);
  pbc->val = strdup (xdr->val);
  pbc->vallen = xdr->vallen;
  pbc->path = strdup (xdr->path);
}

void
convert_lsetxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_lsetxattr_args *pbc,
                                 guestfs_lsetxattr_args *xdr)
{
  xdr->xattr = strdup (pbc->xattr);
  xdr->val = strdup (pbc->val);
  xdr->vallen = pbc->vallen;
  xdr->path = strdup (pbc->path);
}

void
convert_removexattr_args_xdr_to_protobuf (                                 guestfs_removexattr_args *xdr,
                                 guestfs_protobuf_removexattr_args *pbc)
{
  pbc->xattr = strdup (xdr->xattr);
  pbc->path = strdup (xdr->path);
}

void
convert_removexattr_args_protobuf_to_xdr (                                 guestfs_protobuf_removexattr_args *pbc,
                                 guestfs_removexattr_args *xdr)
{
  xdr->xattr = strdup (pbc->xattr);
  xdr->path = strdup (pbc->path);
}

void
convert_lremovexattr_args_xdr_to_protobuf (                                 guestfs_lremovexattr_args *xdr,
                                 guestfs_protobuf_lremovexattr_args *pbc)
{
  pbc->xattr = strdup (xdr->xattr);
  pbc->path = strdup (xdr->path);
}

void
convert_lremovexattr_args_protobuf_to_xdr (                                 guestfs_protobuf_lremovexattr_args *pbc,
                                 guestfs_lremovexattr_args *xdr)
{
  xdr->xattr = strdup (pbc->xattr);
  xdr->path = strdup (pbc->path);
}

void
convert_mountpoints_ret_xdr_to_protobuf (                                guestfs_mountpoints_ret *xdr,
                                guestfs_protobuf_mountpoints_ret *pbc)
{
  pbc->mps = malloc (xdr->mps.mps_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->mps.mps_len; ++i) {
    pbc->n_mps = i;
    pbc->mps[i] = xdr->mps.mps_val[i] ? strdup (xdr->mps.mps_val[i]) : NULL;
  }
}

void
convert_mountpoints_ret_protobuf_to_xdr (                                guestfs_protobuf_mountpoints_ret *pbc,
                                guestfs_mountpoints_ret *xdr)
{
  xdr->mps.mps_val = malloc (pbc->n_mps * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_mps; ++i) {
    xdr->mps.mps_len = i;
    xdr->mps.mps_val[i] = pbc->mps[i] ? strdup (pbc->mps[i]) : NULL;
  }
}

void
convert_mkmountpoint_args_xdr_to_protobuf (                                 guestfs_mkmountpoint_args *xdr,
                                 guestfs_protobuf_mkmountpoint_args *pbc)
{
  pbc->exemptpath = strdup (xdr->exemptpath);
}

void
convert_mkmountpoint_args_protobuf_to_xdr (                                 guestfs_protobuf_mkmountpoint_args *pbc,
                                 guestfs_mkmountpoint_args *xdr)
{
  xdr->exemptpath = strdup (pbc->exemptpath);
}

void
convert_rmmountpoint_args_xdr_to_protobuf (                                 guestfs_rmmountpoint_args *xdr,
                                 guestfs_protobuf_rmmountpoint_args *pbc)
{
  pbc->exemptpath = strdup (xdr->exemptpath);
}

void
convert_rmmountpoint_args_protobuf_to_xdr (                                 guestfs_protobuf_rmmountpoint_args *pbc,
                                 guestfs_rmmountpoint_args *xdr)
{
  xdr->exemptpath = strdup (pbc->exemptpath);
}

void
convert_grep_args_xdr_to_protobuf (                                 guestfs_grep_args *xdr,
                                 guestfs_protobuf_grep_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
  pbc->extended = xdr->extended;
  pbc->fixed = xdr->fixed;
  pbc->insensitive = xdr->insensitive;
  pbc->compressed = xdr->compressed;
}

void
convert_grep_args_protobuf_to_xdr (                                 guestfs_protobuf_grep_args *pbc,
                                 guestfs_grep_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
  xdr->extended = pbc->extended;
  xdr->fixed = pbc->fixed;
  xdr->insensitive = pbc->insensitive;
  xdr->compressed = pbc->compressed;
}

void
convert_grep_ret_xdr_to_protobuf (                                guestfs_grep_ret *xdr,
                                guestfs_protobuf_grep_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_grep_ret_protobuf_to_xdr (                                guestfs_protobuf_grep_ret *pbc,
                                guestfs_grep_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_egrep_args_xdr_to_protobuf (                                 guestfs_egrep_args *xdr,
                                 guestfs_protobuf_egrep_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_egrep_args_protobuf_to_xdr (                                 guestfs_protobuf_egrep_args *pbc,
                                 guestfs_egrep_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_egrep_ret_xdr_to_protobuf (                                guestfs_egrep_ret *xdr,
                                guestfs_protobuf_egrep_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_egrep_ret_protobuf_to_xdr (                                guestfs_protobuf_egrep_ret *pbc,
                                guestfs_egrep_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_fgrep_args_xdr_to_protobuf (                                 guestfs_fgrep_args *xdr,
                                 guestfs_protobuf_fgrep_args *pbc)
{
  pbc->pattern = strdup (xdr->pattern);
  pbc->path = strdup (xdr->path);
}

void
convert_fgrep_args_protobuf_to_xdr (                                 guestfs_protobuf_fgrep_args *pbc,
                                 guestfs_fgrep_args *xdr)
{
  xdr->pattern = strdup (pbc->pattern);
  xdr->path = strdup (pbc->path);
}

void
convert_fgrep_ret_xdr_to_protobuf (                                guestfs_fgrep_ret *xdr,
                                guestfs_protobuf_fgrep_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_fgrep_ret_protobuf_to_xdr (                                guestfs_protobuf_fgrep_ret *pbc,
                                guestfs_fgrep_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_grepi_args_xdr_to_protobuf (                                 guestfs_grepi_args *xdr,
                                 guestfs_protobuf_grepi_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_grepi_args_protobuf_to_xdr (                                 guestfs_protobuf_grepi_args *pbc,
                                 guestfs_grepi_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_grepi_ret_xdr_to_protobuf (                                guestfs_grepi_ret *xdr,
                                guestfs_protobuf_grepi_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_grepi_ret_protobuf_to_xdr (                                guestfs_protobuf_grepi_ret *pbc,
                                guestfs_grepi_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_egrepi_args_xdr_to_protobuf (                                 guestfs_egrepi_args *xdr,
                                 guestfs_protobuf_egrepi_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_egrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_egrepi_args *pbc,
                                 guestfs_egrepi_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_egrepi_ret_xdr_to_protobuf (                                guestfs_egrepi_ret *xdr,
                                guestfs_protobuf_egrepi_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_egrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_egrepi_ret *pbc,
                                guestfs_egrepi_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_fgrepi_args_xdr_to_protobuf (                                 guestfs_fgrepi_args *xdr,
                                 guestfs_protobuf_fgrepi_args *pbc)
{
  pbc->pattern = strdup (xdr->pattern);
  pbc->path = strdup (xdr->path);
}

void
convert_fgrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_fgrepi_args *pbc,
                                 guestfs_fgrepi_args *xdr)
{
  xdr->pattern = strdup (pbc->pattern);
  xdr->path = strdup (pbc->path);
}

void
convert_fgrepi_ret_xdr_to_protobuf (                                guestfs_fgrepi_ret *xdr,
                                guestfs_protobuf_fgrepi_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_fgrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_fgrepi_ret *pbc,
                                guestfs_fgrepi_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zgrep_args_xdr_to_protobuf (                                 guestfs_zgrep_args *xdr,
                                 guestfs_protobuf_zgrep_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_zgrep_args_protobuf_to_xdr (                                 guestfs_protobuf_zgrep_args *pbc,
                                 guestfs_zgrep_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_zgrep_ret_xdr_to_protobuf (                                guestfs_zgrep_ret *xdr,
                                guestfs_protobuf_zgrep_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_zgrep_ret_protobuf_to_xdr (                                guestfs_protobuf_zgrep_ret *pbc,
                                guestfs_zgrep_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zegrep_args_xdr_to_protobuf (                                 guestfs_zegrep_args *xdr,
                                 guestfs_protobuf_zegrep_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_zegrep_args_protobuf_to_xdr (                                 guestfs_protobuf_zegrep_args *pbc,
                                 guestfs_zegrep_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_zegrep_ret_xdr_to_protobuf (                                guestfs_zegrep_ret *xdr,
                                guestfs_protobuf_zegrep_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_zegrep_ret_protobuf_to_xdr (                                guestfs_protobuf_zegrep_ret *pbc,
                                guestfs_zegrep_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zfgrep_args_xdr_to_protobuf (                                 guestfs_zfgrep_args *xdr,
                                 guestfs_protobuf_zfgrep_args *pbc)
{
  pbc->pattern = strdup (xdr->pattern);
  pbc->path = strdup (xdr->path);
}

void
convert_zfgrep_args_protobuf_to_xdr (                                 guestfs_protobuf_zfgrep_args *pbc,
                                 guestfs_zfgrep_args *xdr)
{
  xdr->pattern = strdup (pbc->pattern);
  xdr->path = strdup (pbc->path);
}

void
convert_zfgrep_ret_xdr_to_protobuf (                                guestfs_zfgrep_ret *xdr,
                                guestfs_protobuf_zfgrep_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_zfgrep_ret_protobuf_to_xdr (                                guestfs_protobuf_zfgrep_ret *pbc,
                                guestfs_zfgrep_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zgrepi_args_xdr_to_protobuf (                                 guestfs_zgrepi_args *xdr,
                                 guestfs_protobuf_zgrepi_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_zgrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_zgrepi_args *pbc,
                                 guestfs_zgrepi_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_zgrepi_ret_xdr_to_protobuf (                                guestfs_zgrepi_ret *xdr,
                                guestfs_protobuf_zgrepi_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_zgrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_zgrepi_ret *pbc,
                                guestfs_zgrepi_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zegrepi_args_xdr_to_protobuf (                                 guestfs_zegrepi_args *xdr,
                                 guestfs_protobuf_zegrepi_args *pbc)
{
  pbc->regex = strdup (xdr->regex);
  pbc->path = strdup (xdr->path);
}

void
convert_zegrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_zegrepi_args *pbc,
                                 guestfs_zegrepi_args *xdr)
{
  xdr->regex = strdup (pbc->regex);
  xdr->path = strdup (pbc->path);
}

void
convert_zegrepi_ret_xdr_to_protobuf (                                guestfs_zegrepi_ret *xdr,
                                guestfs_protobuf_zegrepi_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_zegrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_zegrepi_ret *pbc,
                                guestfs_zegrepi_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_zfgrepi_args_xdr_to_protobuf (                                 guestfs_zfgrepi_args *xdr,
                                 guestfs_protobuf_zfgrepi_args *pbc)
{
  pbc->pattern = strdup (xdr->pattern);
  pbc->path = strdup (xdr->path);
}

void
convert_zfgrepi_args_protobuf_to_xdr (                                 guestfs_protobuf_zfgrepi_args *pbc,
                                 guestfs_zfgrepi_args *xdr)
{
  xdr->pattern = strdup (pbc->pattern);
  xdr->path = strdup (pbc->path);
}

void
convert_zfgrepi_ret_xdr_to_protobuf (                                guestfs_zfgrepi_ret *xdr,
                                guestfs_protobuf_zfgrepi_ret *pbc)
{
  pbc->lines = malloc (xdr->lines.lines_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->lines.lines_len; ++i) {
    pbc->n_lines = i;
    pbc->lines[i] = xdr->lines.lines_val[i] ? strdup (xdr->lines.lines_val[i]) : NULL;
  }
}

void
convert_zfgrepi_ret_protobuf_to_xdr (                                guestfs_protobuf_zfgrepi_ret *pbc,
                                guestfs_zfgrepi_ret *xdr)
{
  xdr->lines.lines_val = malloc (pbc->n_lines * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_lines; ++i) {
    xdr->lines.lines_len = i;
    xdr->lines.lines_val[i] = pbc->lines[i] ? strdup (pbc->lines[i]) : NULL;
  }
}

void
convert_realpath_args_xdr_to_protobuf (                                 guestfs_realpath_args *xdr,
                                 guestfs_protobuf_realpath_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_realpath_args_protobuf_to_xdr (                                 guestfs_protobuf_realpath_args *pbc,
                                 guestfs_realpath_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_realpath_ret_xdr_to_protobuf (                                guestfs_realpath_ret *xdr,
                                guestfs_protobuf_realpath_ret *pbc)
{
  pbc->rpath = strdup (xdr->rpath);
}

void
convert_realpath_ret_protobuf_to_xdr (                                guestfs_protobuf_realpath_ret *pbc,
                                guestfs_realpath_ret *xdr)
{
  xdr->rpath = strdup (pbc->rpath);
}

void
convert_ln_args_xdr_to_protobuf (                                 guestfs_ln_args *xdr,
                                 guestfs_protobuf_ln_args *pbc)
{
  pbc->target = strdup (xdr->target);
  pbc->linkname = strdup (xdr->linkname);
}

void
convert_ln_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_args *pbc,
                                 guestfs_ln_args *xdr)
{
  xdr->target = strdup (pbc->target);
  xdr->linkname = strdup (pbc->linkname);
}

void
convert_ln_ff_args_xdr_to_protobuf (                                 guestfs_ln_ff_args *xdr,
                                 guestfs_protobuf_ln_ff_args *pbc)
{
  pbc->target = strdup (xdr->target);
  pbc->linkname = strdup (xdr->linkname);
}

void
convert_ln_ff_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_ff_args *pbc,
                                 guestfs_ln_ff_args *xdr)
{
  xdr->target = strdup (pbc->target);
  xdr->linkname = strdup (pbc->linkname);
}

void
convert_ln_ss_args_xdr_to_protobuf (                                 guestfs_ln_ss_args *xdr,
                                 guestfs_protobuf_ln_ss_args *pbc)
{
  pbc->target = strdup (xdr->target);
  pbc->linkname = strdup (xdr->linkname);
}

void
convert_ln_ss_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_ss_args *pbc,
                                 guestfs_ln_ss_args *xdr)
{
  xdr->target = strdup (pbc->target);
  xdr->linkname = strdup (pbc->linkname);
}

void
convert_ln_sf_args_xdr_to_protobuf (                                 guestfs_ln_sf_args *xdr,
                                 guestfs_protobuf_ln_sf_args *pbc)
{
  pbc->target = strdup (xdr->target);
  pbc->linkname = strdup (xdr->linkname);
}

void
convert_ln_sf_args_protobuf_to_xdr (                                 guestfs_protobuf_ln_sf_args *pbc,
                                 guestfs_ln_sf_args *xdr)
{
  xdr->target = strdup (pbc->target);
  xdr->linkname = strdup (pbc->linkname);
}

void
convert_readlink_args_xdr_to_protobuf (                                 guestfs_readlink_args *xdr,
                                 guestfs_protobuf_readlink_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_readlink_args_protobuf_to_xdr (                                 guestfs_protobuf_readlink_args *pbc,
                                 guestfs_readlink_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_readlink_ret_xdr_to_protobuf (                                guestfs_readlink_ret *xdr,
                                guestfs_protobuf_readlink_ret *pbc)
{
  pbc->link = strdup (xdr->link);
}

void
convert_readlink_ret_protobuf_to_xdr (                                guestfs_protobuf_readlink_ret *pbc,
                                guestfs_readlink_ret *xdr)
{
  xdr->link = strdup (pbc->link);
}

void
convert_fallocate_args_xdr_to_protobuf (                                 guestfs_fallocate_args *xdr,
                                 guestfs_protobuf_fallocate_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->len = xdr->len;
}

void
convert_fallocate_args_protobuf_to_xdr (                                 guestfs_protobuf_fallocate_args *pbc,
                                 guestfs_fallocate_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->len = pbc->len;
}

void
convert_swapon_device_args_xdr_to_protobuf (                                 guestfs_swapon_device_args *xdr,
                                 guestfs_protobuf_swapon_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_swapon_device_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_device_args *pbc,
                                 guestfs_swapon_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_swapoff_device_args_xdr_to_protobuf (                                 guestfs_swapoff_device_args *xdr,
                                 guestfs_protobuf_swapoff_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_swapoff_device_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_device_args *pbc,
                                 guestfs_swapoff_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_swapon_file_args_xdr_to_protobuf (                                 guestfs_swapon_file_args *xdr,
                                 guestfs_protobuf_swapon_file_args *pbc)
{
  pbc->file = strdup (xdr->file);
}

void
convert_swapon_file_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_file_args *pbc,
                                 guestfs_swapon_file_args *xdr)
{
  xdr->file = strdup (pbc->file);
}

void
convert_swapoff_file_args_xdr_to_protobuf (                                 guestfs_swapoff_file_args *xdr,
                                 guestfs_protobuf_swapoff_file_args *pbc)
{
  pbc->file = strdup (xdr->file);
}

void
convert_swapoff_file_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_file_args *pbc,
                                 guestfs_swapoff_file_args *xdr)
{
  xdr->file = strdup (pbc->file);
}

void
convert_swapon_label_args_xdr_to_protobuf (                                 guestfs_swapon_label_args *xdr,
                                 guestfs_protobuf_swapon_label_args *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_swapon_label_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_label_args *pbc,
                                 guestfs_swapon_label_args *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_swapoff_label_args_xdr_to_protobuf (                                 guestfs_swapoff_label_args *xdr,
                                 guestfs_protobuf_swapoff_label_args *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_swapoff_label_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_label_args *pbc,
                                 guestfs_swapoff_label_args *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_swapon_uuid_args_xdr_to_protobuf (                                 guestfs_swapon_uuid_args *xdr,
                                 guestfs_protobuf_swapon_uuid_args *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_swapon_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_swapon_uuid_args *pbc,
                                 guestfs_swapon_uuid_args *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_swapoff_uuid_args_xdr_to_protobuf (                                 guestfs_swapoff_uuid_args *xdr,
                                 guestfs_protobuf_swapoff_uuid_args *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_swapoff_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_swapoff_uuid_args *pbc,
                                 guestfs_swapoff_uuid_args *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_mkswap_file_args_xdr_to_protobuf (                                 guestfs_mkswap_file_args *xdr,
                                 guestfs_protobuf_mkswap_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_mkswap_file_args_protobuf_to_xdr (                                 guestfs_protobuf_mkswap_file_args *pbc,
                                 guestfs_mkswap_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_inotify_init_args_xdr_to_protobuf (                                 guestfs_inotify_init_args *xdr,
                                 guestfs_protobuf_inotify_init_args *pbc)
{
  pbc->maxevents = xdr->maxevents;
}

void
convert_inotify_init_args_protobuf_to_xdr (                                 guestfs_protobuf_inotify_init_args *pbc,
                                 guestfs_inotify_init_args *xdr)
{
  xdr->maxevents = pbc->maxevents;
}

void
convert_inotify_add_watch_args_xdr_to_protobuf (                                 guestfs_inotify_add_watch_args *xdr,
                                 guestfs_protobuf_inotify_add_watch_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->mask = xdr->mask;
}

void
convert_inotify_add_watch_args_protobuf_to_xdr (                                 guestfs_protobuf_inotify_add_watch_args *pbc,
                                 guestfs_inotify_add_watch_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->mask = pbc->mask;
}

void
convert_inotify_add_watch_ret_xdr_to_protobuf (                                guestfs_inotify_add_watch_ret *xdr,
                                guestfs_protobuf_inotify_add_watch_ret *pbc)
{
  pbc->wd = xdr->wd;
}

void
convert_inotify_add_watch_ret_protobuf_to_xdr (                                guestfs_protobuf_inotify_add_watch_ret *pbc,
                                guestfs_inotify_add_watch_ret *xdr)
{
  xdr->wd = pbc->wd;
}

void
convert_inotify_rm_watch_args_xdr_to_protobuf (                                 guestfs_inotify_rm_watch_args *xdr,
                                 guestfs_protobuf_inotify_rm_watch_args *pbc)
{
  pbc->wd = xdr->wd;
}

void
convert_inotify_rm_watch_args_protobuf_to_xdr (                                 guestfs_protobuf_inotify_rm_watch_args *pbc,
                                 guestfs_inotify_rm_watch_args *xdr)
{
  xdr->wd = pbc->wd;
}

void
convert_inotify_read_ret_xdr_to_protobuf (                                guestfs_inotify_read_ret *xdr,
                                guestfs_protobuf_inotify_read_ret *pbc)
{
  pbc->events = malloc (sizeof (guestfs_protobuf_int_inotify_event_list));
  convert_guestfs_int_inotify_event_list_xdr_to_protobuf (&xdr->events, pbc->events);
}

void
convert_inotify_read_ret_protobuf_to_xdr (                                guestfs_protobuf_inotify_read_ret *pbc,
                                guestfs_inotify_read_ret *xdr)
{
  convert_guestfs_int_inotify_event_list_protobuf_to_xdr (pbc->events, &xdr->events);
}

void
convert_inotify_files_ret_xdr_to_protobuf (                                guestfs_inotify_files_ret *xdr,
                                guestfs_protobuf_inotify_files_ret *pbc)
{
  pbc->paths = malloc (xdr->paths.paths_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->paths.paths_len; ++i) {
    pbc->n_paths = i;
    pbc->paths[i] = xdr->paths.paths_val[i] ? strdup (xdr->paths.paths_val[i]) : NULL;
  }
}

void
convert_inotify_files_ret_protobuf_to_xdr (                                guestfs_protobuf_inotify_files_ret *pbc,
                                guestfs_inotify_files_ret *xdr)
{
  xdr->paths.paths_val = malloc (pbc->n_paths * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_paths; ++i) {
    xdr->paths.paths_len = i;
    xdr->paths.paths_val[i] = pbc->paths[i] ? strdup (pbc->paths[i]) : NULL;
  }
}

void
convert_setcon_args_xdr_to_protobuf (                                 guestfs_setcon_args *xdr,
                                 guestfs_protobuf_setcon_args *pbc)
{
  pbc->context = strdup (xdr->context);
}

void
convert_setcon_args_protobuf_to_xdr (                                 guestfs_protobuf_setcon_args *pbc,
                                 guestfs_setcon_args *xdr)
{
  xdr->context = strdup (pbc->context);
}

void
convert_getcon_ret_xdr_to_protobuf (                                guestfs_getcon_ret *xdr,
                                guestfs_protobuf_getcon_ret *pbc)
{
  pbc->context = strdup (xdr->context);
}

void
convert_getcon_ret_protobuf_to_xdr (                                guestfs_protobuf_getcon_ret *pbc,
                                guestfs_getcon_ret *xdr)
{
  xdr->context = strdup (pbc->context);
}

void
convert_mkfs_bb_args_xdr_to_protobuf (                                 guestfs_mkfs_bb_args *xdr,
                                 guestfs_protobuf_mkfs_bb_args *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
  pbc->blocksize = xdr->blocksize;
  pbc->device = strdup (xdr->device);
}

void
convert_mkfs_bb_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfs_bb_args *pbc,
                                 guestfs_mkfs_bb_args *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
  xdr->blocksize = pbc->blocksize;
  xdr->device = strdup (pbc->device);
}

void
convert_mke2journal_args_xdr_to_protobuf (                                 guestfs_mke2journal_args *xdr,
                                 guestfs_protobuf_mke2journal_args *pbc)
{
  pbc->blocksize = xdr->blocksize;
  pbc->device = strdup (xdr->device);
}

void
convert_mke2journal_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2journal_args *pbc,
                                 guestfs_mke2journal_args *xdr)
{
  xdr->blocksize = pbc->blocksize;
  xdr->device = strdup (pbc->device);
}

void
convert_mke2journal_ll_args_xdr_to_protobuf (                                 guestfs_mke2journal_ll_args *xdr,
                                 guestfs_protobuf_mke2journal_ll_args *pbc)
{
  pbc->blocksize = xdr->blocksize;
  pbc->label = strdup (xdr->label);
  pbc->device = strdup (xdr->device);
}

void
convert_mke2journal_ll_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2journal_ll_args *pbc,
                                 guestfs_mke2journal_ll_args *xdr)
{
  xdr->blocksize = pbc->blocksize;
  xdr->label = strdup (pbc->label);
  xdr->device = strdup (pbc->device);
}

void
convert_mke2journal_uu_args_xdr_to_protobuf (                                 guestfs_mke2journal_uu_args *xdr,
                                 guestfs_protobuf_mke2journal_uu_args *pbc)
{
  pbc->blocksize = xdr->blocksize;
  pbc->uuid = strdup (xdr->uuid);
  pbc->device = strdup (xdr->device);
}

void
convert_mke2journal_uu_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2journal_uu_args *pbc,
                                 guestfs_mke2journal_uu_args *xdr)
{
  xdr->blocksize = pbc->blocksize;
  xdr->uuid = strdup (pbc->uuid);
  xdr->device = strdup (pbc->device);
}

void
convert_mke2fs_jj_args_xdr_to_protobuf (                                 guestfs_mke2fs_jj_args *xdr,
                                 guestfs_protobuf_mke2fs_jj_args *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
  pbc->blocksize = xdr->blocksize;
  pbc->device = strdup (xdr->device);
  pbc->journal = strdup (xdr->journal);
}

void
convert_mke2fs_jj_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_jj_args *pbc,
                                 guestfs_mke2fs_jj_args *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
  xdr->blocksize = pbc->blocksize;
  xdr->device = strdup (pbc->device);
  xdr->journal = strdup (pbc->journal);
}

void
convert_mke2fs_jl_args_xdr_to_protobuf (                                 guestfs_mke2fs_jl_args *xdr,
                                 guestfs_protobuf_mke2fs_jl_args *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
  pbc->blocksize = xdr->blocksize;
  pbc->device = strdup (xdr->device);
  pbc->label = strdup (xdr->label);
}

void
convert_mke2fs_jl_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_jl_args *pbc,
                                 guestfs_mke2fs_jl_args *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
  xdr->blocksize = pbc->blocksize;
  xdr->device = strdup (pbc->device);
  xdr->label = strdup (pbc->label);
}

void
convert_mke2fs_ju_args_xdr_to_protobuf (                                 guestfs_mke2fs_ju_args *xdr,
                                 guestfs_protobuf_mke2fs_ju_args *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
  pbc->blocksize = xdr->blocksize;
  pbc->device = strdup (xdr->device);
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_mke2fs_ju_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_ju_args *pbc,
                                 guestfs_mke2fs_ju_args *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
  xdr->blocksize = pbc->blocksize;
  xdr->device = strdup (pbc->device);
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_modprobe_args_xdr_to_protobuf (                                 guestfs_modprobe_args *xdr,
                                 guestfs_protobuf_modprobe_args *pbc)
{
  pbc->modulename = strdup (xdr->modulename);
}

void
convert_modprobe_args_protobuf_to_xdr (                                 guestfs_protobuf_modprobe_args *pbc,
                                 guestfs_modprobe_args *xdr)
{
  xdr->modulename = strdup (pbc->modulename);
}

void
convert_echo_daemon_args_xdr_to_protobuf (                                 guestfs_echo_daemon_args *xdr,
                                 guestfs_protobuf_echo_daemon_args *pbc)
{
  pbc->words = malloc (xdr->words.words_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->words.words_len; ++i) 
{    pbc->n_words = i;
    pbc->words[i] = xdr->words.words_val[i] ? strdup (xdr->words.words_val[i]) : NULL;
  }
}

void
convert_echo_daemon_args_protobuf_to_xdr (                                 guestfs_protobuf_echo_daemon_args *pbc,
                                 guestfs_echo_daemon_args *xdr)
{
  xdr->words.words_val = malloc (pbc->n_words * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_words; ++i) 
{    xdr->words.words_len = i;
    xdr->words.words_val[i] = pbc->words[i] ? strdup (pbc->words[i]) : NULL;
  }
}

void
convert_echo_daemon_ret_xdr_to_protobuf (                                guestfs_echo_daemon_ret *xdr,
                                guestfs_protobuf_echo_daemon_ret *pbc)
{
  pbc->output = strdup (xdr->output);
}

void
convert_echo_daemon_ret_protobuf_to_xdr (                                guestfs_protobuf_echo_daemon_ret *pbc,
                                guestfs_echo_daemon_ret *xdr)
{
  xdr->output = strdup (pbc->output);
}

void
convert_find0_args_xdr_to_protobuf (                                 guestfs_find0_args *xdr,
                                 guestfs_protobuf_find0_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_find0_args_protobuf_to_xdr (                                 guestfs_protobuf_find0_args *pbc,
                                 guestfs_find0_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_case_sensitive_path_args_xdr_to_protobuf (                                 guestfs_case_sensitive_path_args *xdr,
                                 guestfs_protobuf_case_sensitive_path_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_case_sensitive_path_args_protobuf_to_xdr (                                 guestfs_protobuf_case_sensitive_path_args *pbc,
                                 guestfs_case_sensitive_path_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_case_sensitive_path_ret_xdr_to_protobuf (                                guestfs_case_sensitive_path_ret *xdr,
                                guestfs_protobuf_case_sensitive_path_ret *pbc)
{
  pbc->rpath = strdup (xdr->rpath);
}

void
convert_case_sensitive_path_ret_protobuf_to_xdr (                                guestfs_protobuf_case_sensitive_path_ret *pbc,
                                guestfs_case_sensitive_path_ret *xdr)
{
  xdr->rpath = strdup (pbc->rpath);
}

void
convert_vfs_type_args_xdr_to_protobuf (                                 guestfs_vfs_type_args *xdr,
                                 guestfs_protobuf_vfs_type_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
}

void
convert_vfs_type_args_protobuf_to_xdr (                                 guestfs_protobuf_vfs_type_args *pbc,
                                 guestfs_vfs_type_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
}

void
convert_vfs_type_ret_xdr_to_protobuf (                                guestfs_vfs_type_ret *xdr,
                                guestfs_protobuf_vfs_type_ret *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
}

void
convert_vfs_type_ret_protobuf_to_xdr (                                guestfs_protobuf_vfs_type_ret *pbc,
                                guestfs_vfs_type_ret *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
}

void
convert_truncate_args_xdr_to_protobuf (                                 guestfs_truncate_args *xdr,
                                 guestfs_protobuf_truncate_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_truncate_args_protobuf_to_xdr (                                 guestfs_protobuf_truncate_args *pbc,
                                 guestfs_truncate_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_truncate_size_args_xdr_to_protobuf (                                 guestfs_truncate_size_args *xdr,
                                 guestfs_protobuf_truncate_size_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->size = xdr->size;
}

void
convert_truncate_size_args_protobuf_to_xdr (                                 guestfs_protobuf_truncate_size_args *pbc,
                                 guestfs_truncate_size_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->size = pbc->size;
}

void
convert_utimens_args_xdr_to_protobuf (                                 guestfs_utimens_args *xdr,
                                 guestfs_protobuf_utimens_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->atsecs = xdr->atsecs;
  pbc->atnsecs = xdr->atnsecs;
  pbc->mtsecs = xdr->mtsecs;
  pbc->mtnsecs = xdr->mtnsecs;
}

void
convert_utimens_args_protobuf_to_xdr (                                 guestfs_protobuf_utimens_args *pbc,
                                 guestfs_utimens_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->atsecs = pbc->atsecs;
  xdr->atnsecs = pbc->atnsecs;
  xdr->mtsecs = pbc->mtsecs;
  xdr->mtnsecs = pbc->mtnsecs;
}

void
convert_mkdir_mode_args_xdr_to_protobuf (                                 guestfs_mkdir_mode_args *xdr,
                                 guestfs_protobuf_mkdir_mode_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->mode = xdr->mode;
}

void
convert_mkdir_mode_args_protobuf_to_xdr (                                 guestfs_protobuf_mkdir_mode_args *pbc,
                                 guestfs_mkdir_mode_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->mode = pbc->mode;
}

void
convert_lchown_args_xdr_to_protobuf (                                 guestfs_lchown_args *xdr,
                                 guestfs_protobuf_lchown_args *pbc)
{
  pbc->owner = xdr->owner;
  pbc->group = xdr->group;
  pbc->path = strdup (xdr->path);
}

void
convert_lchown_args_protobuf_to_xdr (                                 guestfs_protobuf_lchown_args *pbc,
                                 guestfs_lchown_args *xdr)
{
  xdr->owner = pbc->owner;
  xdr->group = pbc->group;
  xdr->path = strdup (pbc->path);
}

void
convert_internal_lxattrlist_args_xdr_to_protobuf (                                 guestfs_internal_lxattrlist_args *xdr,
                                 guestfs_protobuf_internal_lxattrlist_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->names = malloc (xdr->names.names_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->names.names_len; ++i) 
{    pbc->n_names = i;
    pbc->names[i] = xdr->names.names_val[i] ? strdup (xdr->names.names_val[i]) : NULL;
  }
}

void
convert_internal_lxattrlist_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_lxattrlist_args *pbc,
                                 guestfs_internal_lxattrlist_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->names.names_val = malloc (pbc->n_names * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_names; ++i) 
{    xdr->names.names_len = i;
    xdr->names.names_val[i] = pbc->names[i] ? strdup (pbc->names[i]) : NULL;
  }
}

void
convert_internal_lxattrlist_ret_xdr_to_protobuf (                                guestfs_internal_lxattrlist_ret *xdr,
                                guestfs_protobuf_internal_lxattrlist_ret *pbc)
{
  pbc->xattrs = malloc (sizeof (guestfs_protobuf_int_xattr_list));
  convert_guestfs_int_xattr_list_xdr_to_protobuf (&xdr->xattrs, pbc->xattrs);
}

void
convert_internal_lxattrlist_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_lxattrlist_ret *pbc,
                                guestfs_internal_lxattrlist_ret *xdr)
{
  convert_guestfs_int_xattr_list_protobuf_to_xdr (pbc->xattrs, &xdr->xattrs);
}

void
convert_internal_readlinklist_args_xdr_to_protobuf (                                 guestfs_internal_readlinklist_args *xdr,
                                 guestfs_protobuf_internal_readlinklist_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->names = malloc (xdr->names.names_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->names.names_len; ++i) 
{    pbc->n_names = i;
    pbc->names[i] = xdr->names.names_val[i] ? strdup (xdr->names.names_val[i]) : NULL;
  }
}

void
convert_internal_readlinklist_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_readlinklist_args *pbc,
                                 guestfs_internal_readlinklist_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->names.names_val = malloc (pbc->n_names * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_names; ++i) 
{    xdr->names.names_len = i;
    xdr->names.names_val[i] = pbc->names[i] ? strdup (pbc->names[i]) : NULL;
  }
}

void
convert_internal_readlinklist_ret_xdr_to_protobuf (                                guestfs_internal_readlinklist_ret *xdr,
                                guestfs_protobuf_internal_readlinklist_ret *pbc)
{
  pbc->links = malloc (xdr->links.links_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->links.links_len; ++i) {
    pbc->n_links = i;
    pbc->links[i] = xdr->links.links_val[i] ? strdup (xdr->links.links_val[i]) : NULL;
  }
}

void
convert_internal_readlinklist_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_readlinklist_ret *pbc,
                                guestfs_internal_readlinklist_ret *xdr)
{
  xdr->links.links_val = malloc (pbc->n_links * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_links; ++i) {
    xdr->links.links_len = i;
    xdr->links.links_val[i] = pbc->links[i] ? strdup (pbc->links[i]) : NULL;
  }
}

void
convert_pread_args_xdr_to_protobuf (                                 guestfs_pread_args *xdr,
                                 guestfs_protobuf_pread_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->count = xdr->count;
  pbc->offset = xdr->offset;
}

void
convert_pread_args_protobuf_to_xdr (                                 guestfs_protobuf_pread_args *pbc,
                                 guestfs_pread_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->count = pbc->count;
  xdr->offset = pbc->offset;
}

void
convert_pread_ret_xdr_to_protobuf (                                guestfs_pread_ret *xdr,
                                guestfs_protobuf_pread_ret *pbc)
{
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
}

void
convert_pread_ret_protobuf_to_xdr (                                guestfs_protobuf_pread_ret *pbc,
                                guestfs_pread_ret *xdr)
{
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
}

void
convert_part_init_args_xdr_to_protobuf (                                 guestfs_part_init_args *xdr,
                                 guestfs_protobuf_part_init_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->parttype = strdup (xdr->parttype);
}

void
convert_part_init_args_protobuf_to_xdr (                                 guestfs_protobuf_part_init_args *pbc,
                                 guestfs_part_init_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->parttype = strdup (pbc->parttype);
}

void
convert_part_add_args_xdr_to_protobuf (                                 guestfs_part_add_args *xdr,
                                 guestfs_protobuf_part_add_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->prlogex = strdup (xdr->prlogex);
  pbc->startsect = xdr->startsect;
  pbc->endsect = xdr->endsect;
}

void
convert_part_add_args_protobuf_to_xdr (                                 guestfs_protobuf_part_add_args *pbc,
                                 guestfs_part_add_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->prlogex = strdup (pbc->prlogex);
  xdr->startsect = pbc->startsect;
  xdr->endsect = pbc->endsect;
}

void
convert_part_disk_args_xdr_to_protobuf (                                 guestfs_part_disk_args *xdr,
                                 guestfs_protobuf_part_disk_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->parttype = strdup (xdr->parttype);
}

void
convert_part_disk_args_protobuf_to_xdr (                                 guestfs_protobuf_part_disk_args *pbc,
                                 guestfs_part_disk_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->parttype = strdup (pbc->parttype);
}

void
convert_part_set_bootable_args_xdr_to_protobuf (                                 guestfs_part_set_bootable_args *xdr,
                                 guestfs_protobuf_part_set_bootable_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
  pbc->bootable = xdr->bootable;
}

void
convert_part_set_bootable_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_bootable_args *pbc,
                                 guestfs_part_set_bootable_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
  xdr->bootable = pbc->bootable;
}

void
convert_part_set_name_args_xdr_to_protobuf (                                 guestfs_part_set_name_args *xdr,
                                 guestfs_protobuf_part_set_name_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
  pbc->name = strdup (xdr->name);
}

void
convert_part_set_name_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_name_args *pbc,
                                 guestfs_part_set_name_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
  xdr->name = strdup (pbc->name);
}

void
convert_part_list_args_xdr_to_protobuf (                                 guestfs_part_list_args *xdr,
                                 guestfs_protobuf_part_list_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_part_list_args_protobuf_to_xdr (                                 guestfs_protobuf_part_list_args *pbc,
                                 guestfs_part_list_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_part_list_ret_xdr_to_protobuf (                                guestfs_part_list_ret *xdr,
                                guestfs_protobuf_part_list_ret *pbc)
{
  pbc->partitions = malloc (sizeof (guestfs_protobuf_int_partition_list));
  convert_guestfs_int_partition_list_xdr_to_protobuf (&xdr->partitions, pbc->partitions);
}

void
convert_part_list_ret_protobuf_to_xdr (                                guestfs_protobuf_part_list_ret *pbc,
                                guestfs_part_list_ret *xdr)
{
  convert_guestfs_int_partition_list_protobuf_to_xdr (pbc->partitions, &xdr->partitions);
}

void
convert_part_get_parttype_args_xdr_to_protobuf (                                 guestfs_part_get_parttype_args *xdr,
                                 guestfs_protobuf_part_get_parttype_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_part_get_parttype_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_parttype_args *pbc,
                                 guestfs_part_get_parttype_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_part_get_parttype_ret_xdr_to_protobuf (                                guestfs_part_get_parttype_ret *xdr,
                                guestfs_protobuf_part_get_parttype_ret *pbc)
{
  pbc->parttype = strdup (xdr->parttype);
}

void
convert_part_get_parttype_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_parttype_ret *pbc,
                                guestfs_part_get_parttype_ret *xdr)
{
  xdr->parttype = strdup (pbc->parttype);
}

void
convert_fill_args_xdr_to_protobuf (                                 guestfs_fill_args *xdr,
                                 guestfs_protobuf_fill_args *pbc)
{
  pbc->c = xdr->c;
  pbc->len = xdr->len;
  pbc->path = strdup (xdr->path);
}

void
convert_fill_args_protobuf_to_xdr (                                 guestfs_protobuf_fill_args *pbc,
                                 guestfs_fill_args *xdr)
{
  xdr->c = pbc->c;
  xdr->len = pbc->len;
  xdr->path = strdup (pbc->path);
}

void
convert_available_args_xdr_to_protobuf (                                 guestfs_available_args *xdr,
                                 guestfs_protobuf_available_args *pbc)
{
  pbc->groups = malloc (xdr->groups.groups_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->groups.groups_len; ++i) 
{    pbc->n_groups = i;
    pbc->groups[i] = xdr->groups.groups_val[i] ? strdup (xdr->groups.groups_val[i]) : NULL;
  }
}

void
convert_available_args_protobuf_to_xdr (                                 guestfs_protobuf_available_args *pbc,
                                 guestfs_available_args *xdr)
{
  xdr->groups.groups_val = malloc (pbc->n_groups * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_groups; ++i) 
{    xdr->groups.groups_len = i;
    xdr->groups.groups_val[i] = pbc->groups[i] ? strdup (pbc->groups[i]) : NULL;
  }
}

void
convert_dd_args_xdr_to_protobuf (                                 guestfs_dd_args *xdr,
                                 guestfs_protobuf_dd_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
}

void
convert_dd_args_protobuf_to_xdr (                                 guestfs_protobuf_dd_args *pbc,
                                 guestfs_dd_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
}

void
convert_filesize_args_xdr_to_protobuf (                                 guestfs_filesize_args *xdr,
                                 guestfs_protobuf_filesize_args *pbc)
{
  pbc->file = strdup (xdr->file);
}

void
convert_filesize_args_protobuf_to_xdr (                                 guestfs_protobuf_filesize_args *pbc,
                                 guestfs_filesize_args *xdr)
{
  xdr->file = strdup (pbc->file);
}

void
convert_filesize_ret_xdr_to_protobuf (                                guestfs_filesize_ret *xdr,
                                guestfs_protobuf_filesize_ret *pbc)
{
  pbc->size = xdr->size;
}

void
convert_filesize_ret_protobuf_to_xdr (                                guestfs_protobuf_filesize_ret *pbc,
                                guestfs_filesize_ret *xdr)
{
  xdr->size = pbc->size;
}

void
convert_lvrename_args_xdr_to_protobuf (                                 guestfs_lvrename_args *xdr,
                                 guestfs_protobuf_lvrename_args *pbc)
{
  pbc->logvol = strdup (xdr->logvol);
  pbc->newlogvol = strdup (xdr->newlogvol);
}

void
convert_lvrename_args_protobuf_to_xdr (                                 guestfs_protobuf_lvrename_args *pbc,
                                 guestfs_lvrename_args *xdr)
{
  xdr->logvol = strdup (pbc->logvol);
  xdr->newlogvol = strdup (pbc->newlogvol);
}

void
convert_vgrename_args_xdr_to_protobuf (                                 guestfs_vgrename_args *xdr,
                                 guestfs_protobuf_vgrename_args *pbc)
{
  pbc->volgroup = strdup (xdr->volgroup);
  pbc->newvolgroup = strdup (xdr->newvolgroup);
}

void
convert_vgrename_args_protobuf_to_xdr (                                 guestfs_protobuf_vgrename_args *pbc,
                                 guestfs_vgrename_args *xdr)
{
  xdr->volgroup = strdup (pbc->volgroup);
  xdr->newvolgroup = strdup (pbc->newvolgroup);
}

void
convert_initrd_cat_args_xdr_to_protobuf (                                 guestfs_initrd_cat_args *xdr,
                                 guestfs_protobuf_initrd_cat_args *pbc)
{
  pbc->initrdpath = strdup (xdr->initrdpath);
  pbc->filename = strdup (xdr->filename);
}

void
convert_initrd_cat_args_protobuf_to_xdr (                                 guestfs_protobuf_initrd_cat_args *pbc,
                                 guestfs_initrd_cat_args *xdr)
{
  xdr->initrdpath = strdup (pbc->initrdpath);
  xdr->filename = strdup (pbc->filename);
}

void
convert_initrd_cat_ret_xdr_to_protobuf (                                guestfs_initrd_cat_ret *xdr,
                                guestfs_protobuf_initrd_cat_ret *pbc)
{
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
}

void
convert_initrd_cat_ret_protobuf_to_xdr (                                guestfs_protobuf_initrd_cat_ret *pbc,
                                guestfs_initrd_cat_ret *xdr)
{
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
}

void
convert_pvuuid_args_xdr_to_protobuf (                                 guestfs_pvuuid_args *xdr,
                                 guestfs_protobuf_pvuuid_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_pvuuid_args_protobuf_to_xdr (                                 guestfs_protobuf_pvuuid_args *pbc,
                                 guestfs_pvuuid_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_pvuuid_ret_xdr_to_protobuf (                                guestfs_pvuuid_ret *xdr,
                                guestfs_protobuf_pvuuid_ret *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_pvuuid_ret_protobuf_to_xdr (                                guestfs_protobuf_pvuuid_ret *pbc,
                                guestfs_pvuuid_ret *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_vguuid_args_xdr_to_protobuf (                                 guestfs_vguuid_args *xdr,
                                 guestfs_protobuf_vguuid_args *pbc)
{
  pbc->vgname = strdup (xdr->vgname);
}

void
convert_vguuid_args_protobuf_to_xdr (                                 guestfs_protobuf_vguuid_args *pbc,
                                 guestfs_vguuid_args *xdr)
{
  xdr->vgname = strdup (pbc->vgname);
}

void
convert_vguuid_ret_xdr_to_protobuf (                                guestfs_vguuid_ret *xdr,
                                guestfs_protobuf_vguuid_ret *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_vguuid_ret_protobuf_to_xdr (                                guestfs_protobuf_vguuid_ret *pbc,
                                guestfs_vguuid_ret *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_lvuuid_args_xdr_to_protobuf (                                 guestfs_lvuuid_args *xdr,
                                 guestfs_protobuf_lvuuid_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_lvuuid_args_protobuf_to_xdr (                                 guestfs_protobuf_lvuuid_args *pbc,
                                 guestfs_lvuuid_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_lvuuid_ret_xdr_to_protobuf (                                guestfs_lvuuid_ret *xdr,
                                guestfs_protobuf_lvuuid_ret *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_lvuuid_ret_protobuf_to_xdr (                                guestfs_protobuf_lvuuid_ret *pbc,
                                guestfs_lvuuid_ret *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_vgpvuuids_args_xdr_to_protobuf (                                 guestfs_vgpvuuids_args *xdr,
                                 guestfs_protobuf_vgpvuuids_args *pbc)
{
  pbc->vgname = strdup (xdr->vgname);
}

void
convert_vgpvuuids_args_protobuf_to_xdr (                                 guestfs_protobuf_vgpvuuids_args *pbc,
                                 guestfs_vgpvuuids_args *xdr)
{
  xdr->vgname = strdup (pbc->vgname);
}

void
convert_vgpvuuids_ret_xdr_to_protobuf (                                guestfs_vgpvuuids_ret *xdr,
                                guestfs_protobuf_vgpvuuids_ret *pbc)
{
  pbc->uuids = malloc (xdr->uuids.uuids_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->uuids.uuids_len; ++i) {
    pbc->n_uuids = i;
    pbc->uuids[i] = xdr->uuids.uuids_val[i] ? strdup (xdr->uuids.uuids_val[i]) : NULL;
  }
}

void
convert_vgpvuuids_ret_protobuf_to_xdr (                                guestfs_protobuf_vgpvuuids_ret *pbc,
                                guestfs_vgpvuuids_ret *xdr)
{
  xdr->uuids.uuids_val = malloc (pbc->n_uuids * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_uuids; ++i) {
    xdr->uuids.uuids_len = i;
    xdr->uuids.uuids_val[i] = pbc->uuids[i] ? strdup (pbc->uuids[i]) : NULL;
  }
}

void
convert_vglvuuids_args_xdr_to_protobuf (                                 guestfs_vglvuuids_args *xdr,
                                 guestfs_protobuf_vglvuuids_args *pbc)
{
  pbc->vgname = strdup (xdr->vgname);
}

void
convert_vglvuuids_args_protobuf_to_xdr (                                 guestfs_protobuf_vglvuuids_args *pbc,
                                 guestfs_vglvuuids_args *xdr)
{
  xdr->vgname = strdup (pbc->vgname);
}

void
convert_vglvuuids_ret_xdr_to_protobuf (                                guestfs_vglvuuids_ret *xdr,
                                guestfs_protobuf_vglvuuids_ret *pbc)
{
  pbc->uuids = malloc (xdr->uuids.uuids_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->uuids.uuids_len; ++i) {
    pbc->n_uuids = i;
    pbc->uuids[i] = xdr->uuids.uuids_val[i] ? strdup (xdr->uuids.uuids_val[i]) : NULL;
  }
}

void
convert_vglvuuids_ret_protobuf_to_xdr (                                guestfs_protobuf_vglvuuids_ret *pbc,
                                guestfs_vglvuuids_ret *xdr)
{
  xdr->uuids.uuids_val = malloc (pbc->n_uuids * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_uuids; ++i) {
    xdr->uuids.uuids_len = i;
    xdr->uuids.uuids_val[i] = pbc->uuids[i] ? strdup (pbc->uuids[i]) : NULL;
  }
}

void
convert_copy_size_args_xdr_to_protobuf (                                 guestfs_copy_size_args *xdr,
                                 guestfs_protobuf_copy_size_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->size = xdr->size;
}

void
convert_copy_size_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_size_args *pbc,
                                 guestfs_copy_size_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->size = pbc->size;
}

void
convert_zero_device_args_xdr_to_protobuf (                                 guestfs_zero_device_args *xdr,
                                 guestfs_protobuf_zero_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_zero_device_args_protobuf_to_xdr (                                 guestfs_protobuf_zero_device_args *pbc,
                                 guestfs_zero_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_txz_in_args_xdr_to_protobuf (                                 guestfs_txz_in_args *xdr,
                                 guestfs_protobuf_txz_in_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_txz_in_args_protobuf_to_xdr (                                 guestfs_protobuf_txz_in_args *pbc,
                                 guestfs_txz_in_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_txz_out_args_xdr_to_protobuf (                                 guestfs_txz_out_args *xdr,
                                 guestfs_protobuf_txz_out_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_txz_out_args_protobuf_to_xdr (                                 guestfs_protobuf_txz_out_args *pbc,
                                 guestfs_txz_out_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_part_del_args_xdr_to_protobuf (                                 guestfs_part_del_args *xdr,
                                 guestfs_protobuf_part_del_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
}

void
convert_part_del_args_protobuf_to_xdr (                                 guestfs_protobuf_part_del_args *pbc,
                                 guestfs_part_del_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
}

void
convert_part_get_bootable_args_xdr_to_protobuf (                                 guestfs_part_get_bootable_args *xdr,
                                 guestfs_protobuf_part_get_bootable_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
}

void
convert_part_get_bootable_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_bootable_args *pbc,
                                 guestfs_part_get_bootable_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
}

void
convert_part_get_bootable_ret_xdr_to_protobuf (                                guestfs_part_get_bootable_ret *xdr,
                                guestfs_protobuf_part_get_bootable_ret *pbc)
{
  pbc->bootable = xdr->bootable;
}

void
convert_part_get_bootable_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_bootable_ret *pbc,
                                guestfs_part_get_bootable_ret *xdr)
{
  xdr->bootable = pbc->bootable;
}

void
convert_part_get_mbr_id_args_xdr_to_protobuf (                                 guestfs_part_get_mbr_id_args *xdr,
                                 guestfs_protobuf_part_get_mbr_id_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
}

void
convert_part_get_mbr_id_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_mbr_id_args *pbc,
                                 guestfs_part_get_mbr_id_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
}

void
convert_part_get_mbr_id_ret_xdr_to_protobuf (                                guestfs_part_get_mbr_id_ret *xdr,
                                guestfs_protobuf_part_get_mbr_id_ret *pbc)
{
  pbc->idbyte = xdr->idbyte;
}

void
convert_part_get_mbr_id_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_mbr_id_ret *pbc,
                                guestfs_part_get_mbr_id_ret *xdr)
{
  xdr->idbyte = pbc->idbyte;
}

void
convert_part_set_mbr_id_args_xdr_to_protobuf (                                 guestfs_part_set_mbr_id_args *xdr,
                                 guestfs_protobuf_part_set_mbr_id_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
  pbc->idbyte = xdr->idbyte;
}

void
convert_part_set_mbr_id_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_mbr_id_args *pbc,
                                 guestfs_part_set_mbr_id_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
  xdr->idbyte = pbc->idbyte;
}

void
convert_checksum_device_args_xdr_to_protobuf (                                 guestfs_checksum_device_args *xdr,
                                 guestfs_protobuf_checksum_device_args *pbc)
{
  pbc->csumtype = strdup (xdr->csumtype);
  pbc->device = strdup (xdr->device);
}

void
convert_checksum_device_args_protobuf_to_xdr (                                 guestfs_protobuf_checksum_device_args *pbc,
                                 guestfs_checksum_device_args *xdr)
{
  xdr->csumtype = strdup (pbc->csumtype);
  xdr->device = strdup (pbc->device);
}

void
convert_checksum_device_ret_xdr_to_protobuf (                                guestfs_checksum_device_ret *xdr,
                                guestfs_protobuf_checksum_device_ret *pbc)
{
  pbc->checksum = strdup (xdr->checksum);
}

void
convert_checksum_device_ret_protobuf_to_xdr (                                guestfs_protobuf_checksum_device_ret *pbc,
                                guestfs_checksum_device_ret *xdr)
{
  xdr->checksum = strdup (pbc->checksum);
}

void
convert_lvresize_free_args_xdr_to_protobuf (                                 guestfs_lvresize_free_args *xdr,
                                 guestfs_protobuf_lvresize_free_args *pbc)
{
  pbc->lv = strdup (xdr->lv);
  pbc->percent = xdr->percent;
}

void
convert_lvresize_free_args_protobuf_to_xdr (                                 guestfs_protobuf_lvresize_free_args *pbc,
                                 guestfs_lvresize_free_args *xdr)
{
  xdr->lv = strdup (pbc->lv);
  xdr->percent = pbc->percent;
}

void
convert_aug_clear_args_xdr_to_protobuf (                                 guestfs_aug_clear_args *xdr,
                                 guestfs_protobuf_aug_clear_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
}

void
convert_aug_clear_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_clear_args *pbc,
                                 guestfs_aug_clear_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
}

void
convert_get_umask_ret_xdr_to_protobuf (                                guestfs_get_umask_ret *xdr,
                                guestfs_protobuf_get_umask_ret *pbc)
{
  pbc->mask = xdr->mask;
}

void
convert_get_umask_ret_protobuf_to_xdr (                                guestfs_protobuf_get_umask_ret *pbc,
                                guestfs_get_umask_ret *xdr)
{
  xdr->mask = pbc->mask;
}

void
convert_debug_upload_args_xdr_to_protobuf (                                 guestfs_debug_upload_args *xdr,
                                 guestfs_protobuf_debug_upload_args *pbc)
{
  pbc->tmpname = strdup (xdr->tmpname);
  pbc->mode = xdr->mode;
}

void
convert_debug_upload_args_protobuf_to_xdr (                                 guestfs_protobuf_debug_upload_args *pbc,
                                 guestfs_debug_upload_args *xdr)
{
  xdr->tmpname = strdup (pbc->tmpname);
  xdr->mode = pbc->mode;
}

void
convert_base64_in_args_xdr_to_protobuf (                                 guestfs_base64_in_args *xdr,
                                 guestfs_protobuf_base64_in_args *pbc)
{
  pbc->filename = strdup (xdr->filename);
}

void
convert_base64_in_args_protobuf_to_xdr (                                 guestfs_protobuf_base64_in_args *pbc,
                                 guestfs_base64_in_args *xdr)
{
  xdr->filename = strdup (pbc->filename);
}

void
convert_base64_out_args_xdr_to_protobuf (                                 guestfs_base64_out_args *xdr,
                                 guestfs_protobuf_base64_out_args *pbc)
{
  pbc->filename = strdup (xdr->filename);
}

void
convert_base64_out_args_protobuf_to_xdr (                                 guestfs_protobuf_base64_out_args *pbc,
                                 guestfs_base64_out_args *xdr)
{
  xdr->filename = strdup (pbc->filename);
}

void
convert_checksums_out_args_xdr_to_protobuf (                                 guestfs_checksums_out_args *xdr,
                                 guestfs_protobuf_checksums_out_args *pbc)
{
  pbc->csumtype = strdup (xdr->csumtype);
  pbc->directory = strdup (xdr->directory);
}

void
convert_checksums_out_args_protobuf_to_xdr (                                 guestfs_protobuf_checksums_out_args *pbc,
                                 guestfs_checksums_out_args *xdr)
{
  xdr->csumtype = strdup (pbc->csumtype);
  xdr->directory = strdup (pbc->directory);
}

void
convert_fill_pattern_args_xdr_to_protobuf (                                 guestfs_fill_pattern_args *xdr,
                                 guestfs_protobuf_fill_pattern_args *pbc)
{
  pbc->pattern = strdup (xdr->pattern);
  pbc->len = xdr->len;
  pbc->path = strdup (xdr->path);
}

void
convert_fill_pattern_args_protobuf_to_xdr (                                 guestfs_protobuf_fill_pattern_args *pbc,
                                 guestfs_fill_pattern_args *xdr)
{
  xdr->pattern = strdup (pbc->pattern);
  xdr->len = pbc->len;
  xdr->path = strdup (pbc->path);
}

void
convert_internal_write_args_xdr_to_protobuf (                                 guestfs_internal_write_args *xdr,
                                 guestfs_protobuf_internal_write_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
}

void
convert_internal_write_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_write_args *pbc,
                                 guestfs_internal_write_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
}

void
convert_pwrite_args_xdr_to_protobuf (                                 guestfs_pwrite_args *xdr,
                                 guestfs_protobuf_pwrite_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
  pbc->offset = xdr->offset;
}

void
convert_pwrite_args_protobuf_to_xdr (                                 guestfs_protobuf_pwrite_args *pbc,
                                 guestfs_pwrite_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
  xdr->offset = pbc->offset;
}

void
convert_pwrite_ret_xdr_to_protobuf (                                guestfs_pwrite_ret *xdr,
                                guestfs_protobuf_pwrite_ret *pbc)
{
  pbc->nbytes = xdr->nbytes;
}

void
convert_pwrite_ret_protobuf_to_xdr (                                guestfs_protobuf_pwrite_ret *pbc,
                                guestfs_pwrite_ret *xdr)
{
  xdr->nbytes = pbc->nbytes;
}

void
convert_resize2fs_size_args_xdr_to_protobuf (                                 guestfs_resize2fs_size_args *xdr,
                                 guestfs_protobuf_resize2fs_size_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->size = xdr->size;
}

void
convert_resize2fs_size_args_protobuf_to_xdr (                                 guestfs_protobuf_resize2fs_size_args *pbc,
                                 guestfs_resize2fs_size_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->size = pbc->size;
}

void
convert_pvresize_size_args_xdr_to_protobuf (                                 guestfs_pvresize_size_args *xdr,
                                 guestfs_protobuf_pvresize_size_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->size = xdr->size;
}

void
convert_pvresize_size_args_protobuf_to_xdr (                                 guestfs_protobuf_pvresize_size_args *pbc,
                                 guestfs_pvresize_size_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->size = pbc->size;
}

void
convert_ntfsresize_size_args_xdr_to_protobuf (                                 guestfs_ntfsresize_size_args *xdr,
                                 guestfs_protobuf_ntfsresize_size_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->size = xdr->size;
}

void
convert_ntfsresize_size_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsresize_size_args *pbc,
                                 guestfs_ntfsresize_size_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->size = pbc->size;
}

void
convert_available_all_groups_ret_xdr_to_protobuf (                                guestfs_available_all_groups_ret *xdr,
                                guestfs_protobuf_available_all_groups_ret *pbc)
{
  pbc->groups = malloc (xdr->groups.groups_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->groups.groups_len; ++i) {
    pbc->n_groups = i;
    pbc->groups[i] = xdr->groups.groups_val[i] ? strdup (xdr->groups.groups_val[i]) : NULL;
  }
}

void
convert_available_all_groups_ret_protobuf_to_xdr (                                guestfs_protobuf_available_all_groups_ret *pbc,
                                guestfs_available_all_groups_ret *xdr)
{
  xdr->groups.groups_val = malloc (pbc->n_groups * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_groups; ++i) {
    xdr->groups.groups_len = i;
    xdr->groups.groups_val[i] = pbc->groups[i] ? strdup (pbc->groups[i]) : NULL;
  }
}

void
convert_fallocate64_args_xdr_to_protobuf (                                 guestfs_fallocate64_args *xdr,
                                 guestfs_protobuf_fallocate64_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->len = xdr->len;
}

void
convert_fallocate64_args_protobuf_to_xdr (                                 guestfs_protobuf_fallocate64_args *pbc,
                                 guestfs_fallocate64_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->len = pbc->len;
}

void
convert_vfs_label_args_xdr_to_protobuf (                                 guestfs_vfs_label_args *xdr,
                                 guestfs_protobuf_vfs_label_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
}

void
convert_vfs_label_args_protobuf_to_xdr (                                 guestfs_protobuf_vfs_label_args *pbc,
                                 guestfs_vfs_label_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
}

void
convert_vfs_label_ret_xdr_to_protobuf (                                guestfs_vfs_label_ret *xdr,
                                guestfs_protobuf_vfs_label_ret *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_vfs_label_ret_protobuf_to_xdr (                                guestfs_protobuf_vfs_label_ret *pbc,
                                guestfs_vfs_label_ret *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_vfs_uuid_args_xdr_to_protobuf (                                 guestfs_vfs_uuid_args *xdr,
                                 guestfs_protobuf_vfs_uuid_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
}

void
convert_vfs_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_vfs_uuid_args *pbc,
                                 guestfs_vfs_uuid_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
}

void
convert_vfs_uuid_ret_xdr_to_protobuf (                                guestfs_vfs_uuid_ret *xdr,
                                guestfs_protobuf_vfs_uuid_ret *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_vfs_uuid_ret_protobuf_to_xdr (                                guestfs_protobuf_vfs_uuid_ret *pbc,
                                guestfs_vfs_uuid_ret *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_lvm_set_filter_args_xdr_to_protobuf (                                 guestfs_lvm_set_filter_args *xdr,
                                 guestfs_protobuf_lvm_set_filter_args *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) 
{    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_lvm_set_filter_args_protobuf_to_xdr (                                 guestfs_protobuf_lvm_set_filter_args *pbc,
                                 guestfs_lvm_set_filter_args *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) 
{    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_luks_open_args_xdr_to_protobuf (                                 guestfs_luks_open_args *xdr,
                                 guestfs_protobuf_luks_open_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->key = strdup (xdr->key);
  pbc->mapname = strdup (xdr->mapname);
}

void
convert_luks_open_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_open_args *pbc,
                                 guestfs_luks_open_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->key = strdup (pbc->key);
  xdr->mapname = strdup (pbc->mapname);
}

void
convert_luks_open_ro_args_xdr_to_protobuf (                                 guestfs_luks_open_ro_args *xdr,
                                 guestfs_protobuf_luks_open_ro_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->key = strdup (xdr->key);
  pbc->mapname = strdup (xdr->mapname);
}

void
convert_luks_open_ro_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_open_ro_args *pbc,
                                 guestfs_luks_open_ro_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->key = strdup (pbc->key);
  xdr->mapname = strdup (pbc->mapname);
}

void
convert_luks_close_args_xdr_to_protobuf (                                 guestfs_luks_close_args *xdr,
                                 guestfs_protobuf_luks_close_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_luks_close_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_close_args *pbc,
                                 guestfs_luks_close_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_luks_format_args_xdr_to_protobuf (                                 guestfs_luks_format_args *xdr,
                                 guestfs_protobuf_luks_format_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->key = strdup (xdr->key);
  pbc->keyslot = xdr->keyslot;
}

void
convert_luks_format_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_format_args *pbc,
                                 guestfs_luks_format_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->key = strdup (pbc->key);
  xdr->keyslot = pbc->keyslot;
}

void
convert_luks_format_cipher_args_xdr_to_protobuf (                                 guestfs_luks_format_cipher_args *xdr,
                                 guestfs_protobuf_luks_format_cipher_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->key = strdup (xdr->key);
  pbc->keyslot = xdr->keyslot;
  pbc->cipher = strdup (xdr->cipher);
}

void
convert_luks_format_cipher_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_format_cipher_args *pbc,
                                 guestfs_luks_format_cipher_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->key = strdup (pbc->key);
  xdr->keyslot = pbc->keyslot;
  xdr->cipher = strdup (pbc->cipher);
}

void
convert_luks_add_key_args_xdr_to_protobuf (                                 guestfs_luks_add_key_args *xdr,
                                 guestfs_protobuf_luks_add_key_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->key = strdup (xdr->key);
  pbc->newkey = strdup (xdr->newkey);
  pbc->keyslot = xdr->keyslot;
}

void
convert_luks_add_key_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_add_key_args *pbc,
                                 guestfs_luks_add_key_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->key = strdup (pbc->key);
  xdr->newkey = strdup (pbc->newkey);
  xdr->keyslot = pbc->keyslot;
}

void
convert_luks_kill_slot_args_xdr_to_protobuf (                                 guestfs_luks_kill_slot_args *xdr,
                                 guestfs_protobuf_luks_kill_slot_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->key = strdup (xdr->key);
  pbc->keyslot = xdr->keyslot;
}

void
convert_luks_kill_slot_args_protobuf_to_xdr (                                 guestfs_protobuf_luks_kill_slot_args *pbc,
                                 guestfs_luks_kill_slot_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->key = strdup (pbc->key);
  xdr->keyslot = pbc->keyslot;
}

void
convert_is_lv_args_xdr_to_protobuf (                                 guestfs_is_lv_args *xdr,
                                 guestfs_protobuf_is_lv_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_is_lv_args_protobuf_to_xdr (                                 guestfs_protobuf_is_lv_args *pbc,
                                 guestfs_is_lv_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_is_lv_ret_xdr_to_protobuf (                                guestfs_is_lv_ret *xdr,
                                guestfs_protobuf_is_lv_ret *pbc)
{
  pbc->lvflag = xdr->lvflag;
}

void
convert_is_lv_ret_protobuf_to_xdr (                                guestfs_protobuf_is_lv_ret *pbc,
                                guestfs_is_lv_ret *xdr)
{
  xdr->lvflag = pbc->lvflag;
}

void
convert_findfs_uuid_args_xdr_to_protobuf (                                 guestfs_findfs_uuid_args *xdr,
                                 guestfs_protobuf_findfs_uuid_args *pbc)
{
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_findfs_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_findfs_uuid_args *pbc,
                                 guestfs_findfs_uuid_args *xdr)
{
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_findfs_uuid_ret_xdr_to_protobuf (                                guestfs_findfs_uuid_ret *xdr,
                                guestfs_protobuf_findfs_uuid_ret *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_findfs_uuid_ret_protobuf_to_xdr (                                guestfs_protobuf_findfs_uuid_ret *pbc,
                                guestfs_findfs_uuid_ret *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_findfs_label_args_xdr_to_protobuf (                                 guestfs_findfs_label_args *xdr,
                                 guestfs_protobuf_findfs_label_args *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_findfs_label_args_protobuf_to_xdr (                                 guestfs_protobuf_findfs_label_args *pbc,
                                 guestfs_findfs_label_args *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_findfs_label_ret_xdr_to_protobuf (                                guestfs_findfs_label_ret *xdr,
                                guestfs_protobuf_findfs_label_ret *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_findfs_label_ret_protobuf_to_xdr (                                guestfs_protobuf_findfs_label_ret *pbc,
                                guestfs_findfs_label_ret *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_is_chardev_args_xdr_to_protobuf (                                 guestfs_is_chardev_args *xdr,
                                 guestfs_protobuf_is_chardev_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->followsymlinks = xdr->followsymlinks;
}

void
convert_is_chardev_args_protobuf_to_xdr (                                 guestfs_protobuf_is_chardev_args *pbc,
                                 guestfs_is_chardev_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->followsymlinks = pbc->followsymlinks;
}

void
convert_is_chardev_ret_xdr_to_protobuf (                                guestfs_is_chardev_ret *xdr,
                                guestfs_protobuf_is_chardev_ret *pbc)
{
  pbc->flag = xdr->flag;
}

void
convert_is_chardev_ret_protobuf_to_xdr (                                guestfs_protobuf_is_chardev_ret *pbc,
                                guestfs_is_chardev_ret *xdr)
{
  xdr->flag = pbc->flag;
}

void
convert_is_blockdev_args_xdr_to_protobuf (                                 guestfs_is_blockdev_args *xdr,
                                 guestfs_protobuf_is_blockdev_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->followsymlinks = xdr->followsymlinks;
}

void
convert_is_blockdev_args_protobuf_to_xdr (                                 guestfs_protobuf_is_blockdev_args *pbc,
                                 guestfs_is_blockdev_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->followsymlinks = pbc->followsymlinks;
}

void
convert_is_blockdev_ret_xdr_to_protobuf (                                guestfs_is_blockdev_ret *xdr,
                                guestfs_protobuf_is_blockdev_ret *pbc)
{
  pbc->flag = xdr->flag;
}

void
convert_is_blockdev_ret_protobuf_to_xdr (                                guestfs_protobuf_is_blockdev_ret *pbc,
                                guestfs_is_blockdev_ret *xdr)
{
  xdr->flag = pbc->flag;
}

void
convert_is_fifo_args_xdr_to_protobuf (                                 guestfs_is_fifo_args *xdr,
                                 guestfs_protobuf_is_fifo_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->followsymlinks = xdr->followsymlinks;
}

void
convert_is_fifo_args_protobuf_to_xdr (                                 guestfs_protobuf_is_fifo_args *pbc,
                                 guestfs_is_fifo_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->followsymlinks = pbc->followsymlinks;
}

void
convert_is_fifo_ret_xdr_to_protobuf (                                guestfs_is_fifo_ret *xdr,
                                guestfs_protobuf_is_fifo_ret *pbc)
{
  pbc->flag = xdr->flag;
}

void
convert_is_fifo_ret_protobuf_to_xdr (                                guestfs_protobuf_is_fifo_ret *pbc,
                                guestfs_is_fifo_ret *xdr)
{
  xdr->flag = pbc->flag;
}

void
convert_is_symlink_args_xdr_to_protobuf (                                 guestfs_is_symlink_args *xdr,
                                 guestfs_protobuf_is_symlink_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_is_symlink_args_protobuf_to_xdr (                                 guestfs_protobuf_is_symlink_args *pbc,
                                 guestfs_is_symlink_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_is_symlink_ret_xdr_to_protobuf (                                guestfs_is_symlink_ret *xdr,
                                guestfs_protobuf_is_symlink_ret *pbc)
{
  pbc->flag = xdr->flag;
}

void
convert_is_symlink_ret_protobuf_to_xdr (                                guestfs_protobuf_is_symlink_ret *pbc,
                                guestfs_is_symlink_ret *xdr)
{
  xdr->flag = pbc->flag;
}

void
convert_is_socket_args_xdr_to_protobuf (                                 guestfs_is_socket_args *xdr,
                                 guestfs_protobuf_is_socket_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->followsymlinks = xdr->followsymlinks;
}

void
convert_is_socket_args_protobuf_to_xdr (                                 guestfs_protobuf_is_socket_args *pbc,
                                 guestfs_is_socket_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->followsymlinks = pbc->followsymlinks;
}

void
convert_is_socket_ret_xdr_to_protobuf (                                guestfs_is_socket_ret *xdr,
                                guestfs_protobuf_is_socket_ret *pbc)
{
  pbc->flag = xdr->flag;
}

void
convert_is_socket_ret_protobuf_to_xdr (                                guestfs_protobuf_is_socket_ret *pbc,
                                guestfs_is_socket_ret *xdr)
{
  xdr->flag = pbc->flag;
}

void
convert_part_to_dev_args_xdr_to_protobuf (                                 guestfs_part_to_dev_args *xdr,
                                 guestfs_protobuf_part_to_dev_args *pbc)
{
  pbc->partition = strdup (xdr->partition);
}

void
convert_part_to_dev_args_protobuf_to_xdr (                                 guestfs_protobuf_part_to_dev_args *pbc,
                                 guestfs_part_to_dev_args *xdr)
{
  xdr->partition = strdup (pbc->partition);
}

void
convert_part_to_dev_ret_xdr_to_protobuf (                                guestfs_part_to_dev_ret *xdr,
                                guestfs_protobuf_part_to_dev_ret *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_part_to_dev_ret_protobuf_to_xdr (                                guestfs_protobuf_part_to_dev_ret *pbc,
                                guestfs_part_to_dev_ret *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_upload_offset_args_xdr_to_protobuf (                                 guestfs_upload_offset_args *xdr,
                                 guestfs_protobuf_upload_offset_args *pbc)
{
  pbc->remotefilename = strdup (xdr->remotefilename);
  pbc->offset = xdr->offset;
}

void
convert_upload_offset_args_protobuf_to_xdr (                                 guestfs_protobuf_upload_offset_args *pbc,
                                 guestfs_upload_offset_args *xdr)
{
  xdr->remotefilename = strdup (pbc->remotefilename);
  xdr->offset = pbc->offset;
}

void
convert_download_offset_args_xdr_to_protobuf (                                 guestfs_download_offset_args *xdr,
                                 guestfs_protobuf_download_offset_args *pbc)
{
  pbc->remotefilename = strdup (xdr->remotefilename);
  pbc->offset = xdr->offset;
  pbc->size = xdr->size;
}

void
convert_download_offset_args_protobuf_to_xdr (                                 guestfs_protobuf_download_offset_args *pbc,
                                 guestfs_download_offset_args *xdr)
{
  xdr->remotefilename = strdup (pbc->remotefilename);
  xdr->offset = pbc->offset;
  xdr->size = pbc->size;
}

void
convert_pwrite_device_args_xdr_to_protobuf (                                 guestfs_pwrite_device_args *xdr,
                                 guestfs_protobuf_pwrite_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
  pbc->offset = xdr->offset;
}

void
convert_pwrite_device_args_protobuf_to_xdr (                                 guestfs_protobuf_pwrite_device_args *pbc,
                                 guestfs_pwrite_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
  xdr->offset = pbc->offset;
}

void
convert_pwrite_device_ret_xdr_to_protobuf (                                guestfs_pwrite_device_ret *xdr,
                                guestfs_protobuf_pwrite_device_ret *pbc)
{
  pbc->nbytes = xdr->nbytes;
}

void
convert_pwrite_device_ret_protobuf_to_xdr (                                guestfs_protobuf_pwrite_device_ret *pbc,
                                guestfs_pwrite_device_ret *xdr)
{
  xdr->nbytes = pbc->nbytes;
}

void
convert_pread_device_args_xdr_to_protobuf (                                 guestfs_pread_device_args *xdr,
                                 guestfs_protobuf_pread_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->count = xdr->count;
  pbc->offset = xdr->offset;
}

void
convert_pread_device_args_protobuf_to_xdr (                                 guestfs_protobuf_pread_device_args *pbc,
                                 guestfs_pread_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->count = pbc->count;
  xdr->offset = pbc->offset;
}

void
convert_pread_device_ret_xdr_to_protobuf (                                guestfs_pread_device_ret *xdr,
                                guestfs_protobuf_pread_device_ret *pbc)
{
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
}

void
convert_pread_device_ret_protobuf_to_xdr (                                guestfs_protobuf_pread_device_ret *pbc,
                                guestfs_pread_device_ret *xdr)
{
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
}

void
convert_lvm_canonical_lv_name_args_xdr_to_protobuf (                                 guestfs_lvm_canonical_lv_name_args *xdr,
                                 guestfs_protobuf_lvm_canonical_lv_name_args *pbc)
{
  pbc->lvname = strdup (xdr->lvname);
}

void
convert_lvm_canonical_lv_name_args_protobuf_to_xdr (                                 guestfs_protobuf_lvm_canonical_lv_name_args *pbc,
                                 guestfs_lvm_canonical_lv_name_args *xdr)
{
  xdr->lvname = strdup (pbc->lvname);
}

void
convert_lvm_canonical_lv_name_ret_xdr_to_protobuf (                                guestfs_lvm_canonical_lv_name_ret *xdr,
                                guestfs_protobuf_lvm_canonical_lv_name_ret *pbc)
{
  pbc->lv = strdup (xdr->lv);
}

void
convert_lvm_canonical_lv_name_ret_protobuf_to_xdr (                                guestfs_protobuf_lvm_canonical_lv_name_ret *pbc,
                                guestfs_lvm_canonical_lv_name_ret *xdr)
{
  xdr->lv = strdup (pbc->lv);
}

void
convert_mkfs_args_xdr_to_protobuf (                                 guestfs_mkfs_args *xdr,
                                 guestfs_protobuf_mkfs_args *pbc)
{
  pbc->fstype = strdup (xdr->fstype);
  pbc->device = strdup (xdr->device);
  pbc->blocksize = xdr->blocksize;
  pbc->features = strdup (xdr->features);
  pbc->inode = xdr->inode;
  pbc->sectorsize = xdr->sectorsize;
}

void
convert_mkfs_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfs_args *pbc,
                                 guestfs_mkfs_args *xdr)
{
  xdr->fstype = strdup (pbc->fstype);
  xdr->device = strdup (pbc->device);
  xdr->blocksize = pbc->blocksize;
  xdr->features = strdup (pbc->features);
  xdr->inode = pbc->inode;
  xdr->sectorsize = pbc->sectorsize;
}

void
convert_getxattr_args_xdr_to_protobuf (                                 guestfs_getxattr_args *xdr,
                                 guestfs_protobuf_getxattr_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->name = strdup (xdr->name);
}

void
convert_getxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_getxattr_args *pbc,
                                 guestfs_getxattr_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->name = strdup (pbc->name);
}

void
convert_getxattr_ret_xdr_to_protobuf (                                guestfs_getxattr_ret *xdr,
                                guestfs_protobuf_getxattr_ret *pbc)
{
  pbc->xattr.data = malloc (xdr->xattr.xattr_len);
  memcpy (pbc->xattr.data, xdr->xattr.xattr_val, xdr->xattr.xattr_len);
  pbc->xattr.len = xdr->xattr.xattr_len; 
}

void
convert_getxattr_ret_protobuf_to_xdr (                                guestfs_protobuf_getxattr_ret *pbc,
                                guestfs_getxattr_ret *xdr)
{
  xdr->xattr.xattr_val = malloc (pbc->xattr.len);
  memcpy (xdr->xattr.xattr_val, pbc->xattr.data, pbc->xattr.len); 
  xdr->xattr.xattr_len = pbc->xattr.len; 
}

void
convert_lgetxattr_args_xdr_to_protobuf (                                 guestfs_lgetxattr_args *xdr,
                                 guestfs_protobuf_lgetxattr_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->name = strdup (xdr->name);
}

void
convert_lgetxattr_args_protobuf_to_xdr (                                 guestfs_protobuf_lgetxattr_args *pbc,
                                 guestfs_lgetxattr_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->name = strdup (pbc->name);
}

void
convert_lgetxattr_ret_xdr_to_protobuf (                                guestfs_lgetxattr_ret *xdr,
                                guestfs_protobuf_lgetxattr_ret *pbc)
{
  pbc->xattr.data = malloc (xdr->xattr.xattr_len);
  memcpy (pbc->xattr.data, xdr->xattr.xattr_val, xdr->xattr.xattr_len);
  pbc->xattr.len = xdr->xattr.xattr_len; 
}

void
convert_lgetxattr_ret_protobuf_to_xdr (                                guestfs_protobuf_lgetxattr_ret *pbc,
                                guestfs_lgetxattr_ret *xdr)
{
  xdr->xattr.xattr_val = malloc (pbc->xattr.len);
  memcpy (xdr->xattr.xattr_val, pbc->xattr.data, pbc->xattr.len); 
  xdr->xattr.xattr_len = pbc->xattr.len; 
}

void
convert_resize2fs_mm_args_xdr_to_protobuf (                                 guestfs_resize2fs_mm_args *xdr,
                                 guestfs_protobuf_resize2fs_mm_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_resize2fs_mm_args_protobuf_to_xdr (                                 guestfs_protobuf_resize2fs_mm_args *pbc,
                                 guestfs_resize2fs_mm_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_is_zero_args_xdr_to_protobuf (                                 guestfs_is_zero_args *xdr,
                                 guestfs_protobuf_is_zero_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_is_zero_args_protobuf_to_xdr (                                 guestfs_protobuf_is_zero_args *pbc,
                                 guestfs_is_zero_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_is_zero_ret_xdr_to_protobuf (                                guestfs_is_zero_ret *xdr,
                                guestfs_protobuf_is_zero_ret *pbc)
{
  pbc->zeroflag = xdr->zeroflag;
}

void
convert_is_zero_ret_protobuf_to_xdr (                                guestfs_protobuf_is_zero_ret *pbc,
                                guestfs_is_zero_ret *xdr)
{
  xdr->zeroflag = pbc->zeroflag;
}

void
convert_is_zero_device_args_xdr_to_protobuf (                                 guestfs_is_zero_device_args *xdr,
                                 guestfs_protobuf_is_zero_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_is_zero_device_args_protobuf_to_xdr (                                 guestfs_protobuf_is_zero_device_args *pbc,
                                 guestfs_is_zero_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_is_zero_device_ret_xdr_to_protobuf (                                guestfs_is_zero_device_ret *xdr,
                                guestfs_protobuf_is_zero_device_ret *pbc)
{
  pbc->zeroflag = xdr->zeroflag;
}

void
convert_is_zero_device_ret_protobuf_to_xdr (                                guestfs_protobuf_is_zero_device_ret *pbc,
                                guestfs_is_zero_device_ret *xdr)
{
  xdr->zeroflag = pbc->zeroflag;
}

void
convert_list9p_ret_xdr_to_protobuf (                                guestfs_list9p_ret *xdr,
                                guestfs_protobuf_list9p_ret *pbc)
{
  pbc->mounttags = malloc (xdr->mounttags.mounttags_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->mounttags.mounttags_len; ++i) {
    pbc->n_mounttags = i;
    pbc->mounttags[i] = xdr->mounttags.mounttags_val[i] ? strdup (xdr->mounttags.mounttags_val[i]) : NULL;
  }
}

void
convert_list9p_ret_protobuf_to_xdr (                                guestfs_protobuf_list9p_ret *pbc,
                                guestfs_list9p_ret *xdr)
{
  xdr->mounttags.mounttags_val = malloc (pbc->n_mounttags * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_mounttags; ++i) {
    xdr->mounttags.mounttags_len = i;
    xdr->mounttags.mounttags_val[i] = pbc->mounttags[i] ? strdup (pbc->mounttags[i]) : NULL;
  }
}

void
convert_mount9p_args_xdr_to_protobuf (                                 guestfs_mount9p_args *xdr,
                                 guestfs_protobuf_mount9p_args *pbc)
{
  pbc->mounttag = strdup (xdr->mounttag);
  pbc->mountpoint = strdup (xdr->mountpoint);
  pbc->options = strdup (xdr->options);
}

void
convert_mount9p_args_protobuf_to_xdr (                                 guestfs_protobuf_mount9p_args *pbc,
                                 guestfs_mount9p_args *xdr)
{
  xdr->mounttag = strdup (pbc->mounttag);
  xdr->mountpoint = strdup (pbc->mountpoint);
  xdr->options = strdup (pbc->options);
}

void
convert_list_dm_devices_ret_xdr_to_protobuf (                                guestfs_list_dm_devices_ret *xdr,
                                guestfs_protobuf_list_dm_devices_ret *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) {
    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_list_dm_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_list_dm_devices_ret *pbc,
                                guestfs_list_dm_devices_ret *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) {
    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_ntfsresize_args_xdr_to_protobuf (                                 guestfs_ntfsresize_args *xdr,
                                 guestfs_protobuf_ntfsresize_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->size = xdr->size;
  pbc->force = xdr->force;
}

void
convert_ntfsresize_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsresize_args *pbc,
                                 guestfs_ntfsresize_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->size = pbc->size;
  xdr->force = pbc->force;
}

void
convert_btrfs_filesystem_resize_args_xdr_to_protobuf (                                 guestfs_btrfs_filesystem_resize_args *xdr,
                                 guestfs_protobuf_btrfs_filesystem_resize_args *pbc)
{
  pbc->mountpoint = strdup (xdr->mountpoint);
  pbc->size = xdr->size;
}

void
convert_btrfs_filesystem_resize_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_filesystem_resize_args *pbc,
                                 guestfs_btrfs_filesystem_resize_args *xdr)
{
  xdr->mountpoint = strdup (pbc->mountpoint);
  xdr->size = pbc->size;
}

void
convert_internal_write_append_args_xdr_to_protobuf (                                 guestfs_internal_write_append_args *xdr,
                                 guestfs_protobuf_internal_write_append_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->content.data = malloc (xdr->content.content_len);
  memcpy (pbc->content.data, xdr->content.content_val, xdr->content.content_len);
  pbc->content.len = xdr->content.content_len; 
}

void
convert_internal_write_append_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_write_append_args *pbc,
                                 guestfs_internal_write_append_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->content.content_val = malloc (pbc->content.len);
  memcpy (xdr->content.content_val, pbc->content.data, pbc->content.len); 
  xdr->content.content_len = pbc->content.len; 
}

void
convert_compress_out_args_xdr_to_protobuf (                                 guestfs_compress_out_args *xdr,
                                 guestfs_protobuf_compress_out_args *pbc)
{
  pbc->ctype = strdup (xdr->ctype);
  pbc->file = strdup (xdr->file);
  pbc->level = xdr->level;
}

void
convert_compress_out_args_protobuf_to_xdr (                                 guestfs_protobuf_compress_out_args *pbc,
                                 guestfs_compress_out_args *xdr)
{
  xdr->ctype = strdup (pbc->ctype);
  xdr->file = strdup (pbc->file);
  xdr->level = pbc->level;
}

void
convert_compress_device_out_args_xdr_to_protobuf (                                 guestfs_compress_device_out_args *xdr,
                                 guestfs_protobuf_compress_device_out_args *pbc)
{
  pbc->ctype = strdup (xdr->ctype);
  pbc->device = strdup (xdr->device);
  pbc->level = xdr->level;
}

void
convert_compress_device_out_args_protobuf_to_xdr (                                 guestfs_protobuf_compress_device_out_args *pbc,
                                 guestfs_compress_device_out_args *xdr)
{
  xdr->ctype = strdup (pbc->ctype);
  xdr->device = strdup (pbc->device);
  xdr->level = pbc->level;
}

void
convert_part_to_partnum_args_xdr_to_protobuf (                                 guestfs_part_to_partnum_args *xdr,
                                 guestfs_protobuf_part_to_partnum_args *pbc)
{
  pbc->partition = strdup (xdr->partition);
}

void
convert_part_to_partnum_args_protobuf_to_xdr (                                 guestfs_protobuf_part_to_partnum_args *pbc,
                                 guestfs_part_to_partnum_args *xdr)
{
  xdr->partition = strdup (pbc->partition);
}

void
convert_part_to_partnum_ret_xdr_to_protobuf (                                guestfs_part_to_partnum_ret *xdr,
                                guestfs_protobuf_part_to_partnum_ret *pbc)
{
  pbc->partnum = xdr->partnum;
}

void
convert_part_to_partnum_ret_protobuf_to_xdr (                                guestfs_protobuf_part_to_partnum_ret *pbc,
                                guestfs_part_to_partnum_ret *xdr)
{
  xdr->partnum = pbc->partnum;
}

void
convert_copy_device_to_device_args_xdr_to_protobuf (                                 guestfs_copy_device_to_device_args *xdr,
                                 guestfs_protobuf_copy_device_to_device_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->srcoffset = xdr->srcoffset;
  pbc->destoffset = xdr->destoffset;
  pbc->size = xdr->size;
  pbc->sparse = xdr->sparse;
}

void
convert_copy_device_to_device_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_device_to_device_args *pbc,
                                 guestfs_copy_device_to_device_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->srcoffset = pbc->srcoffset;
  xdr->destoffset = pbc->destoffset;
  xdr->size = pbc->size;
  xdr->sparse = pbc->sparse;
}

void
convert_copy_device_to_file_args_xdr_to_protobuf (                                 guestfs_copy_device_to_file_args *xdr,
                                 guestfs_protobuf_copy_device_to_file_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->srcoffset = xdr->srcoffset;
  pbc->destoffset = xdr->destoffset;
  pbc->size = xdr->size;
  pbc->sparse = xdr->sparse;
}

void
convert_copy_device_to_file_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_device_to_file_args *pbc,
                                 guestfs_copy_device_to_file_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->srcoffset = pbc->srcoffset;
  xdr->destoffset = pbc->destoffset;
  xdr->size = pbc->size;
  xdr->sparse = pbc->sparse;
}

void
convert_copy_file_to_device_args_xdr_to_protobuf (                                 guestfs_copy_file_to_device_args *xdr,
                                 guestfs_protobuf_copy_file_to_device_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->srcoffset = xdr->srcoffset;
  pbc->destoffset = xdr->destoffset;
  pbc->size = xdr->size;
  pbc->sparse = xdr->sparse;
}

void
convert_copy_file_to_device_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_file_to_device_args *pbc,
                                 guestfs_copy_file_to_device_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->srcoffset = pbc->srcoffset;
  xdr->destoffset = pbc->destoffset;
  xdr->size = pbc->size;
  xdr->sparse = pbc->sparse;
}

void
convert_copy_file_to_file_args_xdr_to_protobuf (                                 guestfs_copy_file_to_file_args *xdr,
                                 guestfs_protobuf_copy_file_to_file_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->srcoffset = xdr->srcoffset;
  pbc->destoffset = xdr->destoffset;
  pbc->size = xdr->size;
  pbc->sparse = xdr->sparse;
}

void
convert_copy_file_to_file_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_file_to_file_args *pbc,
                                 guestfs_copy_file_to_file_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->srcoffset = pbc->srcoffset;
  xdr->destoffset = pbc->destoffset;
  xdr->size = pbc->size;
  xdr->sparse = pbc->sparse;
}

void
convert_tune2fs_args_xdr_to_protobuf (                                 guestfs_tune2fs_args *xdr,
                                 guestfs_protobuf_tune2fs_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->force = xdr->force;
  pbc->maxmountcount = xdr->maxmountcount;
  pbc->mountcount = xdr->mountcount;
  pbc->errorbehavior = strdup (xdr->errorbehavior);
  pbc->group = xdr->group;
  pbc->intervalbetweenchecks = xdr->intervalbetweenchecks;
  pbc->reservedblockspercentage = xdr->reservedblockspercentage;
  pbc->lastmounteddirectory = strdup (xdr->lastmounteddirectory);
  pbc->reservedblockscount = xdr->reservedblockscount;
  pbc->user = xdr->user;
}

void
convert_tune2fs_args_protobuf_to_xdr (                                 guestfs_protobuf_tune2fs_args *pbc,
                                 guestfs_tune2fs_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->force = pbc->force;
  xdr->maxmountcount = pbc->maxmountcount;
  xdr->mountcount = pbc->mountcount;
  xdr->errorbehavior = strdup (pbc->errorbehavior);
  xdr->group = pbc->group;
  xdr->intervalbetweenchecks = pbc->intervalbetweenchecks;
  xdr->reservedblockspercentage = pbc->reservedblockspercentage;
  xdr->lastmounteddirectory = strdup (pbc->lastmounteddirectory);
  xdr->reservedblockscount = pbc->reservedblockscount;
  xdr->user = pbc->user;
}

void
convert_md_create_args_xdr_to_protobuf (                                 guestfs_md_create_args *xdr,
                                 guestfs_protobuf_md_create_args *pbc)
{
  pbc->name = strdup (xdr->name);
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) 
{    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
  pbc->missingbitmap = xdr->missingbitmap;
  pbc->nrdevices = xdr->nrdevices;
  pbc->spare = xdr->spare;
  pbc->chunk = xdr->chunk;
  pbc->level = strdup (xdr->level);
}

void
convert_md_create_args_protobuf_to_xdr (                                 guestfs_protobuf_md_create_args *pbc,
                                 guestfs_md_create_args *xdr)
{
  xdr->name = strdup (pbc->name);
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) 
{    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
  xdr->missingbitmap = pbc->missingbitmap;
  xdr->nrdevices = pbc->nrdevices;
  xdr->spare = pbc->spare;
  xdr->chunk = pbc->chunk;
  xdr->level = strdup (pbc->level);
}

void
convert_list_md_devices_ret_xdr_to_protobuf (                                guestfs_list_md_devices_ret *xdr,
                                guestfs_protobuf_list_md_devices_ret *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) {
    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_list_md_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_list_md_devices_ret *pbc,
                                guestfs_list_md_devices_ret *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) {
    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_md_detail_args_xdr_to_protobuf (                                 guestfs_md_detail_args *xdr,
                                 guestfs_protobuf_md_detail_args *pbc)
{
  pbc->md = strdup (xdr->md);
}

void
convert_md_detail_args_protobuf_to_xdr (                                 guestfs_protobuf_md_detail_args *pbc,
                                 guestfs_md_detail_args *xdr)
{
  xdr->md = strdup (pbc->md);
}

void
convert_md_detail_ret_xdr_to_protobuf (                                guestfs_md_detail_ret *xdr,
                                guestfs_protobuf_md_detail_ret *pbc)
{
  pbc->info = malloc (xdr->info.info_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->info.info_len; ++i) {
    pbc->n_info = i;
    pbc->info[i] = xdr->info.info_val[i] ? strdup (xdr->info.info_val[i]) : NULL;
  }
}

void
convert_md_detail_ret_protobuf_to_xdr (                                guestfs_protobuf_md_detail_ret *pbc,
                                guestfs_md_detail_ret *xdr)
{
  xdr->info.info_val = malloc (pbc->n_info * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_info; ++i) {
    xdr->info.info_len = i;
    xdr->info.info_val[i] = pbc->info[i] ? strdup (pbc->info[i]) : NULL;
  }
}

void
convert_md_stop_args_xdr_to_protobuf (                                 guestfs_md_stop_args *xdr,
                                 guestfs_protobuf_md_stop_args *pbc)
{
  pbc->md = strdup (xdr->md);
}

void
convert_md_stop_args_protobuf_to_xdr (                                 guestfs_protobuf_md_stop_args *pbc,
                                 guestfs_md_stop_args *xdr)
{
  xdr->md = strdup (pbc->md);
}

void
convert_blkid_args_xdr_to_protobuf (                                 guestfs_blkid_args *xdr,
                                 guestfs_protobuf_blkid_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blkid_args_protobuf_to_xdr (                                 guestfs_protobuf_blkid_args *pbc,
                                 guestfs_blkid_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blkid_ret_xdr_to_protobuf (                                guestfs_blkid_ret *xdr,
                                guestfs_protobuf_blkid_ret *pbc)
{
  pbc->info = malloc (xdr->info.info_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->info.info_len; ++i) {
    pbc->n_info = i;
    pbc->info[i] = xdr->info.info_val[i] ? strdup (xdr->info.info_val[i]) : NULL;
  }
}

void
convert_blkid_ret_protobuf_to_xdr (                                guestfs_protobuf_blkid_ret *pbc,
                                guestfs_blkid_ret *xdr)
{
  xdr->info.info_val = malloc (pbc->n_info * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_info; ++i) {
    xdr->info.info_len = i;
    xdr->info.info_val[i] = pbc->info[i] ? strdup (pbc->info[i]) : NULL;
  }
}

void
convert_e2fsck_args_xdr_to_protobuf (                                 guestfs_e2fsck_args *xdr,
                                 guestfs_protobuf_e2fsck_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->correct = xdr->correct;
  pbc->forceall = xdr->forceall;
}

void
convert_e2fsck_args_protobuf_to_xdr (                                 guestfs_protobuf_e2fsck_args *pbc,
                                 guestfs_e2fsck_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->correct = pbc->correct;
  xdr->forceall = pbc->forceall;
}

void
convert_llz_args_xdr_to_protobuf (                                 guestfs_llz_args *xdr,
                                 guestfs_protobuf_llz_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_llz_args_protobuf_to_xdr (                                 guestfs_protobuf_llz_args *pbc,
                                 guestfs_llz_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_llz_ret_xdr_to_protobuf (                                guestfs_llz_ret *xdr,
                                guestfs_protobuf_llz_ret *pbc)
{
  pbc->listing = strdup (xdr->listing);
}

void
convert_llz_ret_protobuf_to_xdr (                                guestfs_protobuf_llz_ret *pbc,
                                guestfs_llz_ret *xdr)
{
  xdr->listing = strdup (pbc->listing);
}

void
convert_wipefs_args_xdr_to_protobuf (                                 guestfs_wipefs_args *xdr,
                                 guestfs_protobuf_wipefs_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_wipefs_args_protobuf_to_xdr (                                 guestfs_protobuf_wipefs_args *pbc,
                                 guestfs_wipefs_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_ntfsfix_args_xdr_to_protobuf (                                 guestfs_ntfsfix_args *xdr,
                                 guestfs_protobuf_ntfsfix_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->clearbadsectors = xdr->clearbadsectors;
}

void
convert_ntfsfix_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsfix_args *pbc,
                                 guestfs_ntfsfix_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->clearbadsectors = pbc->clearbadsectors;
}

void
convert_ntfsclone_out_args_xdr_to_protobuf (                                 guestfs_ntfsclone_out_args *xdr,
                                 guestfs_protobuf_ntfsclone_out_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->metadataonly = xdr->metadataonly;
  pbc->rescue = xdr->rescue;
  pbc->ignorefscheck = xdr->ignorefscheck;
  pbc->preservetimestamps = xdr->preservetimestamps;
  pbc->force = xdr->force;
}

void
convert_ntfsclone_out_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsclone_out_args *pbc,
                                 guestfs_ntfsclone_out_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->metadataonly = pbc->metadataonly;
  xdr->rescue = pbc->rescue;
  xdr->ignorefscheck = pbc->ignorefscheck;
  xdr->preservetimestamps = pbc->preservetimestamps;
  xdr->force = pbc->force;
}

void
convert_ntfsclone_in_args_xdr_to_protobuf (                                 guestfs_ntfsclone_in_args *xdr,
                                 guestfs_protobuf_ntfsclone_in_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_ntfsclone_in_args_protobuf_to_xdr (                                 guestfs_protobuf_ntfsclone_in_args *pbc,
                                 guestfs_ntfsclone_in_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_set_label_args_xdr_to_protobuf (                                 guestfs_set_label_args *xdr,
                                 guestfs_protobuf_set_label_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
  pbc->label = strdup (xdr->label);
}

void
convert_set_label_args_protobuf_to_xdr (                                 guestfs_protobuf_set_label_args *pbc,
                                 guestfs_set_label_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
  xdr->label = strdup (pbc->label);
}

void
convert_zero_free_space_args_xdr_to_protobuf (                                 guestfs_zero_free_space_args *xdr,
                                 guestfs_protobuf_zero_free_space_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_zero_free_space_args_protobuf_to_xdr (                                 guestfs_protobuf_zero_free_space_args *pbc,
                                 guestfs_zero_free_space_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_lvcreate_free_args_xdr_to_protobuf (                                 guestfs_lvcreate_free_args *xdr,
                                 guestfs_protobuf_lvcreate_free_args *pbc)
{
  pbc->logvol = strdup (xdr->logvol);
  pbc->volgroup = strdup (xdr->volgroup);
  pbc->percent = xdr->percent;
}

void
convert_lvcreate_free_args_protobuf_to_xdr (                                 guestfs_protobuf_lvcreate_free_args *pbc,
                                 guestfs_lvcreate_free_args *xdr)
{
  xdr->logvol = strdup (pbc->logvol);
  xdr->volgroup = strdup (pbc->volgroup);
  xdr->percent = pbc->percent;
}

void
convert_isoinfo_device_args_xdr_to_protobuf (                                 guestfs_isoinfo_device_args *xdr,
                                 guestfs_protobuf_isoinfo_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_isoinfo_device_args_protobuf_to_xdr (                                 guestfs_protobuf_isoinfo_device_args *pbc,
                                 guestfs_isoinfo_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_isoinfo_device_ret_xdr_to_protobuf (                                guestfs_isoinfo_device_ret *xdr,
                                guestfs_protobuf_isoinfo_device_ret *pbc)
{
  pbc->isodata = malloc (sizeof (guestfs_protobuf_int_isoinfo));
  convert_guestfs_int_isoinfo_xdr_to_protobuf (&xdr->isodata, pbc->isodata);
}

void
convert_isoinfo_device_ret_protobuf_to_xdr (                                guestfs_protobuf_isoinfo_device_ret *pbc,
                                guestfs_isoinfo_device_ret *xdr)
{
  convert_guestfs_int_isoinfo_protobuf_to_xdr (pbc->isodata, &xdr->isodata);
}

void
convert_isoinfo_args_xdr_to_protobuf (                                 guestfs_isoinfo_args *xdr,
                                 guestfs_protobuf_isoinfo_args *pbc)
{
  pbc->isofile = strdup (xdr->isofile);
}

void
convert_isoinfo_args_protobuf_to_xdr (                                 guestfs_protobuf_isoinfo_args *pbc,
                                 guestfs_isoinfo_args *xdr)
{
  xdr->isofile = strdup (pbc->isofile);
}

void
convert_isoinfo_ret_xdr_to_protobuf (                                guestfs_isoinfo_ret *xdr,
                                guestfs_protobuf_isoinfo_ret *pbc)
{
  pbc->isodata = malloc (sizeof (guestfs_protobuf_int_isoinfo));
  convert_guestfs_int_isoinfo_xdr_to_protobuf (&xdr->isodata, pbc->isodata);
}

void
convert_isoinfo_ret_protobuf_to_xdr (                                guestfs_protobuf_isoinfo_ret *pbc,
                                guestfs_isoinfo_ret *xdr)
{
  convert_guestfs_int_isoinfo_protobuf_to_xdr (pbc->isodata, &xdr->isodata);
}

void
convert_vgmeta_args_xdr_to_protobuf (                                 guestfs_vgmeta_args *xdr,
                                 guestfs_protobuf_vgmeta_args *pbc)
{
  pbc->vgname = strdup (xdr->vgname);
}

void
convert_vgmeta_args_protobuf_to_xdr (                                 guestfs_protobuf_vgmeta_args *pbc,
                                 guestfs_vgmeta_args *xdr)
{
  xdr->vgname = strdup (pbc->vgname);
}

void
convert_vgmeta_ret_xdr_to_protobuf (                                guestfs_vgmeta_ret *xdr,
                                guestfs_protobuf_vgmeta_ret *pbc)
{
  pbc->metadata.data = malloc (xdr->metadata.metadata_len);
  memcpy (pbc->metadata.data, xdr->metadata.metadata_val, xdr->metadata.metadata_len);
  pbc->metadata.len = xdr->metadata.metadata_len; 
}

void
convert_vgmeta_ret_protobuf_to_xdr (                                guestfs_protobuf_vgmeta_ret *pbc,
                                guestfs_vgmeta_ret *xdr)
{
  xdr->metadata.metadata_val = malloc (pbc->metadata.len);
  memcpy (xdr->metadata.metadata_val, pbc->metadata.data, pbc->metadata.len); 
  xdr->metadata.metadata_len = pbc->metadata.len; 
}

void
convert_md_stat_args_xdr_to_protobuf (                                 guestfs_md_stat_args *xdr,
                                 guestfs_protobuf_md_stat_args *pbc)
{
  pbc->md = strdup (xdr->md);
}

void
convert_md_stat_args_protobuf_to_xdr (                                 guestfs_protobuf_md_stat_args *pbc,
                                 guestfs_md_stat_args *xdr)
{
  xdr->md = strdup (pbc->md);
}

void
convert_md_stat_ret_xdr_to_protobuf (                                guestfs_md_stat_ret *xdr,
                                guestfs_protobuf_md_stat_ret *pbc)
{
  pbc->devices = malloc (sizeof (guestfs_protobuf_int_mdstat_list));
  convert_guestfs_int_mdstat_list_xdr_to_protobuf (&xdr->devices, pbc->devices);
}

void
convert_md_stat_ret_protobuf_to_xdr (                                guestfs_protobuf_md_stat_ret *pbc,
                                guestfs_md_stat_ret *xdr)
{
  convert_guestfs_int_mdstat_list_protobuf_to_xdr (pbc->devices, &xdr->devices);
}

void
convert_mkfs_btrfs_args_xdr_to_protobuf (                                 guestfs_mkfs_btrfs_args *xdr,
                                 guestfs_protobuf_mkfs_btrfs_args *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) 
{    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
  pbc->allocstart = xdr->allocstart;
  pbc->bytecount = xdr->bytecount;
  pbc->datatype = strdup (xdr->datatype);
  pbc->leafsize = xdr->leafsize;
  pbc->label = strdup (xdr->label);
  pbc->metadata = strdup (xdr->metadata);
  pbc->nodesize = xdr->nodesize;
  pbc->sectorsize = xdr->sectorsize;
}

void
convert_mkfs_btrfs_args_protobuf_to_xdr (                                 guestfs_protobuf_mkfs_btrfs_args *pbc,
                                 guestfs_mkfs_btrfs_args *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) 
{    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
  xdr->allocstart = pbc->allocstart;
  xdr->bytecount = pbc->bytecount;
  xdr->datatype = strdup (pbc->datatype);
  xdr->leafsize = pbc->leafsize;
  xdr->label = strdup (pbc->label);
  xdr->metadata = strdup (pbc->metadata);
  xdr->nodesize = pbc->nodesize;
  xdr->sectorsize = pbc->sectorsize;
}

void
convert_get_e2attrs_args_xdr_to_protobuf (                                 guestfs_get_e2attrs_args *xdr,
                                 guestfs_protobuf_get_e2attrs_args *pbc)
{
  pbc->file = strdup (xdr->file);
}

void
convert_get_e2attrs_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2attrs_args *pbc,
                                 guestfs_get_e2attrs_args *xdr)
{
  xdr->file = strdup (pbc->file);
}

void
convert_get_e2attrs_ret_xdr_to_protobuf (                                guestfs_get_e2attrs_ret *xdr,
                                guestfs_protobuf_get_e2attrs_ret *pbc)
{
  pbc->attrs = strdup (xdr->attrs);
}

void
convert_get_e2attrs_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2attrs_ret *pbc,
                                guestfs_get_e2attrs_ret *xdr)
{
  xdr->attrs = strdup (pbc->attrs);
}

void
convert_set_e2attrs_args_xdr_to_protobuf (                                 guestfs_set_e2attrs_args *xdr,
                                 guestfs_protobuf_set_e2attrs_args *pbc)
{
  pbc->file = strdup (xdr->file);
  pbc->attrs = strdup (xdr->attrs);
  pbc->clear = xdr->clear;
}

void
convert_set_e2attrs_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2attrs_args *pbc,
                                 guestfs_set_e2attrs_args *xdr)
{
  xdr->file = strdup (pbc->file);
  xdr->attrs = strdup (pbc->attrs);
  xdr->clear = pbc->clear;
}

void
convert_get_e2generation_args_xdr_to_protobuf (                                 guestfs_get_e2generation_args *xdr,
                                 guestfs_protobuf_get_e2generation_args *pbc)
{
  pbc->file = strdup (xdr->file);
}

void
convert_get_e2generation_args_protobuf_to_xdr (                                 guestfs_protobuf_get_e2generation_args *pbc,
                                 guestfs_get_e2generation_args *xdr)
{
  xdr->file = strdup (pbc->file);
}

void
convert_get_e2generation_ret_xdr_to_protobuf (                                guestfs_get_e2generation_ret *xdr,
                                guestfs_protobuf_get_e2generation_ret *pbc)
{
  pbc->generation = xdr->generation;
}

void
convert_get_e2generation_ret_protobuf_to_xdr (                                guestfs_protobuf_get_e2generation_ret *pbc,
                                guestfs_get_e2generation_ret *xdr)
{
  xdr->generation = pbc->generation;
}

void
convert_set_e2generation_args_xdr_to_protobuf (                                 guestfs_set_e2generation_args *xdr,
                                 guestfs_protobuf_set_e2generation_args *pbc)
{
  pbc->file = strdup (xdr->file);
  pbc->generation = xdr->generation;
}

void
convert_set_e2generation_args_protobuf_to_xdr (                                 guestfs_protobuf_set_e2generation_args *pbc,
                                 guestfs_set_e2generation_args *xdr)
{
  xdr->file = strdup (pbc->file);
  xdr->generation = pbc->generation;
}

void
convert_btrfs_subvolume_snapshot_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_snapshot_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_snapshot_args *pbc)
{
  pbc->source = strdup (xdr->source);
  pbc->dest = strdup (xdr->dest);
}

void
convert_btrfs_subvolume_snapshot_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_snapshot_args *pbc,
                                 guestfs_btrfs_subvolume_snapshot_args *xdr)
{
  xdr->source = strdup (pbc->source);
  xdr->dest = strdup (pbc->dest);
}

void
convert_btrfs_subvolume_delete_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_delete_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_delete_args *pbc)
{
  pbc->subvolume = strdup (xdr->subvolume);
}

void
convert_btrfs_subvolume_delete_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_delete_args *pbc,
                                 guestfs_btrfs_subvolume_delete_args *xdr)
{
  xdr->subvolume = strdup (pbc->subvolume);
}

void
convert_btrfs_subvolume_create_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_create_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_create_args *pbc)
{
  pbc->dest = strdup (xdr->dest);
}

void
convert_btrfs_subvolume_create_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_create_args *pbc,
                                 guestfs_btrfs_subvolume_create_args *xdr)
{
  xdr->dest = strdup (pbc->dest);
}

void
convert_btrfs_subvolume_list_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_list_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_list_args *pbc)
{
  pbc->fs = strdup (xdr->fs);
}

void
convert_btrfs_subvolume_list_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_list_args *pbc,
                                 guestfs_btrfs_subvolume_list_args *xdr)
{
  xdr->fs = strdup (pbc->fs);
}

void
convert_btrfs_subvolume_list_ret_xdr_to_protobuf (                                guestfs_btrfs_subvolume_list_ret *xdr,
                                guestfs_protobuf_btrfs_subvolume_list_ret *pbc)
{
  pbc->subvolumes = malloc (sizeof (guestfs_protobuf_int_btrfssubvolume_list));
  convert_guestfs_int_btrfssubvolume_list_xdr_to_protobuf (&xdr->subvolumes, pbc->subvolumes);
}

void
convert_btrfs_subvolume_list_ret_protobuf_to_xdr (                                guestfs_protobuf_btrfs_subvolume_list_ret *pbc,
                                guestfs_btrfs_subvolume_list_ret *xdr)
{
  convert_guestfs_int_btrfssubvolume_list_protobuf_to_xdr (pbc->subvolumes, &xdr->subvolumes);
}

void
convert_btrfs_subvolume_set_default_args_xdr_to_protobuf (                                 guestfs_btrfs_subvolume_set_default_args *xdr,
                                 guestfs_protobuf_btrfs_subvolume_set_default_args *pbc)
{
  pbc->id = xdr->id;
  pbc->fs = strdup (xdr->fs);
}

void
convert_btrfs_subvolume_set_default_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_subvolume_set_default_args *pbc,
                                 guestfs_btrfs_subvolume_set_default_args *xdr)
{
  xdr->id = pbc->id;
  xdr->fs = strdup (pbc->fs);
}

void
convert_btrfs_filesystem_sync_args_xdr_to_protobuf (                                 guestfs_btrfs_filesystem_sync_args *xdr,
                                 guestfs_protobuf_btrfs_filesystem_sync_args *pbc)
{
  pbc->fs = strdup (xdr->fs);
}

void
convert_btrfs_filesystem_sync_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_filesystem_sync_args *pbc,
                                 guestfs_btrfs_filesystem_sync_args *xdr)
{
  xdr->fs = strdup (pbc->fs);
}

void
convert_btrfs_filesystem_balance_args_xdr_to_protobuf (                                 guestfs_btrfs_filesystem_balance_args *xdr,
                                 guestfs_protobuf_btrfs_filesystem_balance_args *pbc)
{
  pbc->fs = strdup (xdr->fs);
}

void
convert_btrfs_filesystem_balance_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_filesystem_balance_args *pbc,
                                 guestfs_btrfs_filesystem_balance_args *xdr)
{
  xdr->fs = strdup (pbc->fs);
}

void
convert_btrfs_device_add_args_xdr_to_protobuf (                                 guestfs_btrfs_device_add_args *xdr,
                                 guestfs_protobuf_btrfs_device_add_args *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) 
{    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
  pbc->fs = strdup (xdr->fs);
}

void
convert_btrfs_device_add_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_device_add_args *pbc,
                                 guestfs_btrfs_device_add_args *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) 
{    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
  xdr->fs = strdup (pbc->fs);
}

void
convert_btrfs_device_delete_args_xdr_to_protobuf (                                 guestfs_btrfs_device_delete_args *xdr,
                                 guestfs_protobuf_btrfs_device_delete_args *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) 
{    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
  pbc->fs = strdup (xdr->fs);
}

void
convert_btrfs_device_delete_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_device_delete_args *pbc,
                                 guestfs_btrfs_device_delete_args *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) 
{    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
  xdr->fs = strdup (pbc->fs);
}

void
convert_btrfs_set_seeding_args_xdr_to_protobuf (                                 guestfs_btrfs_set_seeding_args *xdr,
                                 guestfs_protobuf_btrfs_set_seeding_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->seeding = xdr->seeding;
}

void
convert_btrfs_set_seeding_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_set_seeding_args *pbc,
                                 guestfs_btrfs_set_seeding_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->seeding = pbc->seeding;
}

void
convert_btrfs_fsck_args_xdr_to_protobuf (                                 guestfs_btrfs_fsck_args *xdr,
                                 guestfs_protobuf_btrfs_fsck_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->superblock = xdr->superblock;
  pbc->repair = xdr->repair;
}

void
convert_btrfs_fsck_args_protobuf_to_xdr (                                 guestfs_protobuf_btrfs_fsck_args *pbc,
                                 guestfs_btrfs_fsck_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->superblock = pbc->superblock;
  xdr->repair = pbc->repair;
}

void
convert_filesystem_available_args_xdr_to_protobuf (                                 guestfs_filesystem_available_args *xdr,
                                 guestfs_protobuf_filesystem_available_args *pbc)
{
  pbc->filesystem = strdup (xdr->filesystem);
}

void
convert_filesystem_available_args_protobuf_to_xdr (                                 guestfs_protobuf_filesystem_available_args *pbc,
                                 guestfs_filesystem_available_args *xdr)
{
  xdr->filesystem = strdup (pbc->filesystem);
}

void
convert_filesystem_available_ret_xdr_to_protobuf (                                guestfs_filesystem_available_ret *xdr,
                                guestfs_protobuf_filesystem_available_ret *pbc)
{
  pbc->fsavail = xdr->fsavail;
}

void
convert_filesystem_available_ret_protobuf_to_xdr (                                guestfs_protobuf_filesystem_available_ret *pbc,
                                guestfs_filesystem_available_ret *xdr)
{
  xdr->fsavail = pbc->fsavail;
}

void
convert_fstrim_args_xdr_to_protobuf (                                 guestfs_fstrim_args *xdr,
                                 guestfs_protobuf_fstrim_args *pbc)
{
  pbc->mountpoint = strdup (xdr->mountpoint);
  pbc->offset = xdr->offset;
  pbc->length = xdr->length;
  pbc->minimumfreeextent = xdr->minimumfreeextent;
}

void
convert_fstrim_args_protobuf_to_xdr (                                 guestfs_protobuf_fstrim_args *pbc,
                                 guestfs_fstrim_args *xdr)
{
  xdr->mountpoint = strdup (pbc->mountpoint);
  xdr->offset = pbc->offset;
  xdr->length = pbc->length;
  xdr->minimumfreeextent = pbc->minimumfreeextent;
}

void
convert_device_index_args_xdr_to_protobuf (                                 guestfs_device_index_args *xdr,
                                 guestfs_protobuf_device_index_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_device_index_args_protobuf_to_xdr (                                 guestfs_protobuf_device_index_args *pbc,
                                 guestfs_device_index_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_device_index_ret_xdr_to_protobuf (                                guestfs_device_index_ret *xdr,
                                guestfs_protobuf_device_index_ret *pbc)
{
  pbc->index = xdr->index;
}

void
convert_device_index_ret_protobuf_to_xdr (                                guestfs_protobuf_device_index_ret *pbc,
                                guestfs_device_index_ret *xdr)
{
  xdr->index = pbc->index;
}

void
convert_nr_devices_ret_xdr_to_protobuf (                                guestfs_nr_devices_ret *xdr,
                                guestfs_protobuf_nr_devices_ret *pbc)
{
  pbc->nrdisks = xdr->nrdisks;
}

void
convert_nr_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_nr_devices_ret *pbc,
                                guestfs_nr_devices_ret *xdr)
{
  xdr->nrdisks = pbc->nrdisks;
}

void
convert_xfs_info_args_xdr_to_protobuf (                                 guestfs_xfs_info_args *xdr,
                                 guestfs_protobuf_xfs_info_args *pbc)
{
  pbc->pathordevice = strdup (xdr->pathordevice);
}

void
convert_xfs_info_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_info_args *pbc,
                                 guestfs_xfs_info_args *xdr)
{
  xdr->pathordevice = strdup (pbc->pathordevice);
}

void
convert_xfs_info_ret_xdr_to_protobuf (                                guestfs_xfs_info_ret *xdr,
                                guestfs_protobuf_xfs_info_ret *pbc)
{
  pbc->info = malloc (sizeof (guestfs_protobuf_int_xfsinfo));
  convert_guestfs_int_xfsinfo_xdr_to_protobuf (&xdr->info, pbc->info);
}

void
convert_xfs_info_ret_protobuf_to_xdr (                                guestfs_protobuf_xfs_info_ret *pbc,
                                guestfs_xfs_info_ret *xdr)
{
  convert_guestfs_int_xfsinfo_protobuf_to_xdr (pbc->info, &xdr->info);
}

void
convert_pvchange_uuid_args_xdr_to_protobuf (                                 guestfs_pvchange_uuid_args *xdr,
                                 guestfs_protobuf_pvchange_uuid_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_pvchange_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_pvchange_uuid_args *pbc,
                                 guestfs_pvchange_uuid_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_vgchange_uuid_args_xdr_to_protobuf (                                 guestfs_vgchange_uuid_args *xdr,
                                 guestfs_protobuf_vgchange_uuid_args *pbc)
{
  pbc->vg = strdup (xdr->vg);
}

void
convert_vgchange_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_vgchange_uuid_args *pbc,
                                 guestfs_vgchange_uuid_args *xdr)
{
  xdr->vg = strdup (pbc->vg);
}

void
convert_utsname_ret_xdr_to_protobuf (                                guestfs_utsname_ret *xdr,
                                guestfs_protobuf_utsname_ret *pbc)
{
  pbc->uts = malloc (sizeof (guestfs_protobuf_int_utsname));
  convert_guestfs_int_utsname_xdr_to_protobuf (&xdr->uts, pbc->uts);
}

void
convert_utsname_ret_protobuf_to_xdr (                                guestfs_protobuf_utsname_ret *pbc,
                                guestfs_utsname_ret *xdr)
{
  convert_guestfs_int_utsname_protobuf_to_xdr (pbc->uts, &xdr->uts);
}

void
convert_xfs_growfs_args_xdr_to_protobuf (                                 guestfs_xfs_growfs_args *xdr,
                                 guestfs_protobuf_xfs_growfs_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->datasec = xdr->datasec;
  pbc->logsec = xdr->logsec;
  pbc->rtsec = xdr->rtsec;
  pbc->datasize = xdr->datasize;
  pbc->logsize = xdr->logsize;
  pbc->rtsize = xdr->rtsize;
  pbc->rtextsize = xdr->rtextsize;
  pbc->maxpct = xdr->maxpct;
}

void
convert_xfs_growfs_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_growfs_args *pbc,
                                 guestfs_xfs_growfs_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->datasec = pbc->datasec;
  xdr->logsec = pbc->logsec;
  xdr->rtsec = pbc->rtsec;
  xdr->datasize = pbc->datasize;
  xdr->logsize = pbc->logsize;
  xdr->rtsize = pbc->rtsize;
  xdr->rtextsize = pbc->rtextsize;
  xdr->maxpct = pbc->maxpct;
}

void
convert_rsync_args_xdr_to_protobuf (                                 guestfs_rsync_args *xdr,
                                 guestfs_protobuf_rsync_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->archive = xdr->archive;
  pbc->deletedest = xdr->deletedest;
}

void
convert_rsync_args_protobuf_to_xdr (                                 guestfs_protobuf_rsync_args *pbc,
                                 guestfs_rsync_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->archive = pbc->archive;
  xdr->deletedest = pbc->deletedest;
}

void
convert_rsync_in_args_xdr_to_protobuf (                                 guestfs_rsync_in_args *xdr,
                                 guestfs_protobuf_rsync_in_args *pbc)
{
  pbc->remote = strdup (xdr->remote);
  pbc->dest = strdup (xdr->dest);
  pbc->archive = xdr->archive;
  pbc->deletedest = xdr->deletedest;
}

void
convert_rsync_in_args_protobuf_to_xdr (                                 guestfs_protobuf_rsync_in_args *pbc,
                                 guestfs_rsync_in_args *xdr)
{
  xdr->remote = strdup (pbc->remote);
  xdr->dest = strdup (pbc->dest);
  xdr->archive = pbc->archive;
  xdr->deletedest = pbc->deletedest;
}

void
convert_rsync_out_args_xdr_to_protobuf (                                 guestfs_rsync_out_args *xdr,
                                 guestfs_protobuf_rsync_out_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->remote = strdup (xdr->remote);
  pbc->archive = xdr->archive;
  pbc->deletedest = xdr->deletedest;
}

void
convert_rsync_out_args_protobuf_to_xdr (                                 guestfs_protobuf_rsync_out_args *pbc,
                                 guestfs_rsync_out_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->remote = strdup (pbc->remote);
  xdr->archive = pbc->archive;
  xdr->deletedest = pbc->deletedest;
}

void
convert_ls0_args_xdr_to_protobuf (                                 guestfs_ls0_args *xdr,
                                 guestfs_protobuf_ls0_args *pbc)
{
  pbc->dir = strdup (xdr->dir);
}

void
convert_ls0_args_protobuf_to_xdr (                                 guestfs_protobuf_ls0_args *pbc,
                                 guestfs_ls0_args *xdr)
{
  xdr->dir = strdup (pbc->dir);
}

void
convert_fill_dir_args_xdr_to_protobuf (                                 guestfs_fill_dir_args *xdr,
                                 guestfs_protobuf_fill_dir_args *pbc)
{
  pbc->dir = strdup (xdr->dir);
  pbc->nr = xdr->nr;
}

void
convert_fill_dir_args_protobuf_to_xdr (                                 guestfs_protobuf_fill_dir_args *pbc,
                                 guestfs_fill_dir_args *xdr)
{
  xdr->dir = strdup (pbc->dir);
  xdr->nr = pbc->nr;
}

void
convert_xfs_admin_args_xdr_to_protobuf (                                 guestfs_xfs_admin_args *xdr,
                                 guestfs_protobuf_xfs_admin_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->extunwritten = xdr->extunwritten;
  pbc->imgfile = xdr->imgfile;
  pbc->v2log = xdr->v2log;
  pbc->projid32bit = xdr->projid32bit;
  pbc->lazycounter = xdr->lazycounter;
  pbc->label = strdup (xdr->label);
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_xfs_admin_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_admin_args *pbc,
                                 guestfs_xfs_admin_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->extunwritten = pbc->extunwritten;
  xdr->imgfile = pbc->imgfile;
  xdr->v2log = pbc->v2log;
  xdr->projid32bit = pbc->projid32bit;
  xdr->lazycounter = pbc->lazycounter;
  xdr->label = strdup (pbc->label);
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_hivex_open_args_xdr_to_protobuf (                                 guestfs_hivex_open_args *xdr,
                                 guestfs_protobuf_hivex_open_args *pbc)
{
  pbc->filename = strdup (xdr->filename);
  pbc->verbose = xdr->verbose;
  pbc->debug = xdr->debug;
  pbc->write = xdr->write;
}

void
convert_hivex_open_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_open_args *pbc,
                                 guestfs_hivex_open_args *xdr)
{
  xdr->filename = strdup (pbc->filename);
  xdr->verbose = pbc->verbose;
  xdr->debug = pbc->debug;
  xdr->write = pbc->write;
}

void
convert_hivex_root_ret_xdr_to_protobuf (                                guestfs_hivex_root_ret *xdr,
                                guestfs_protobuf_hivex_root_ret *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_root_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_root_ret *pbc,
                                guestfs_hivex_root_ret *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_name_args_xdr_to_protobuf (                                 guestfs_hivex_node_name_args *xdr,
                                 guestfs_protobuf_hivex_node_name_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_node_name_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_name_args *pbc,
                                 guestfs_hivex_node_name_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_name_ret_xdr_to_protobuf (                                guestfs_hivex_node_name_ret *xdr,
                                guestfs_protobuf_hivex_node_name_ret *pbc)
{
  pbc->name = strdup (xdr->name);
}

void
convert_hivex_node_name_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_name_ret *pbc,
                                guestfs_hivex_node_name_ret *xdr)
{
  xdr->name = strdup (pbc->name);
}

void
convert_hivex_node_children_args_xdr_to_protobuf (                                 guestfs_hivex_node_children_args *xdr,
                                 guestfs_protobuf_hivex_node_children_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_node_children_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_children_args *pbc,
                                 guestfs_hivex_node_children_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_children_ret_xdr_to_protobuf (                                guestfs_hivex_node_children_ret *xdr,
                                guestfs_protobuf_hivex_node_children_ret *pbc)
{
  pbc->nodehs = malloc (sizeof (guestfs_protobuf_int_hivex_node_list));
  convert_guestfs_int_hivex_node_list_xdr_to_protobuf (&xdr->nodehs, pbc->nodehs);
}

void
convert_hivex_node_children_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_children_ret *pbc,
                                guestfs_hivex_node_children_ret *xdr)
{
  convert_guestfs_int_hivex_node_list_protobuf_to_xdr (pbc->nodehs, &xdr->nodehs);
}

void
convert_hivex_node_get_child_args_xdr_to_protobuf (                                 guestfs_hivex_node_get_child_args *xdr,
                                 guestfs_protobuf_hivex_node_get_child_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
  pbc->name = strdup (xdr->name);
}

void
convert_hivex_node_get_child_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_get_child_args *pbc,
                                 guestfs_hivex_node_get_child_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
  xdr->name = strdup (pbc->name);
}

void
convert_hivex_node_get_child_ret_xdr_to_protobuf (                                guestfs_hivex_node_get_child_ret *xdr,
                                guestfs_protobuf_hivex_node_get_child_ret *pbc)
{
  pbc->child = xdr->child;
}

void
convert_hivex_node_get_child_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_get_child_ret *pbc,
                                guestfs_hivex_node_get_child_ret *xdr)
{
  xdr->child = pbc->child;
}

void
convert_hivex_node_parent_args_xdr_to_protobuf (                                 guestfs_hivex_node_parent_args *xdr,
                                 guestfs_protobuf_hivex_node_parent_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_node_parent_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_parent_args *pbc,
                                 guestfs_hivex_node_parent_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_parent_ret_xdr_to_protobuf (                                guestfs_hivex_node_parent_ret *xdr,
                                guestfs_protobuf_hivex_node_parent_ret *pbc)
{
  pbc->parent = xdr->parent;
}

void
convert_hivex_node_parent_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_parent_ret *pbc,
                                guestfs_hivex_node_parent_ret *xdr)
{
  xdr->parent = pbc->parent;
}

void
convert_hivex_node_values_args_xdr_to_protobuf (                                 guestfs_hivex_node_values_args *xdr,
                                 guestfs_protobuf_hivex_node_values_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_node_values_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_values_args *pbc,
                                 guestfs_hivex_node_values_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_values_ret_xdr_to_protobuf (                                guestfs_hivex_node_values_ret *xdr,
                                guestfs_protobuf_hivex_node_values_ret *pbc)
{
  pbc->valuehs = malloc (sizeof (guestfs_protobuf_int_hivex_value_list));
  convert_guestfs_int_hivex_value_list_xdr_to_protobuf (&xdr->valuehs, pbc->valuehs);
}

void
convert_hivex_node_values_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_values_ret *pbc,
                                guestfs_hivex_node_values_ret *xdr)
{
  convert_guestfs_int_hivex_value_list_protobuf_to_xdr (pbc->valuehs, &xdr->valuehs);
}

void
convert_hivex_node_get_value_args_xdr_to_protobuf (                                 guestfs_hivex_node_get_value_args *xdr,
                                 guestfs_protobuf_hivex_node_get_value_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
  pbc->key = strdup (xdr->key);
}

void
convert_hivex_node_get_value_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_get_value_args *pbc,
                                 guestfs_hivex_node_get_value_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
  xdr->key = strdup (pbc->key);
}

void
convert_hivex_node_get_value_ret_xdr_to_protobuf (                                guestfs_hivex_node_get_value_ret *xdr,
                                guestfs_protobuf_hivex_node_get_value_ret *pbc)
{
  pbc->valueh = xdr->valueh;
}

void
convert_hivex_node_get_value_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_get_value_ret *pbc,
                                guestfs_hivex_node_get_value_ret *xdr)
{
  xdr->valueh = pbc->valueh;
}

void
convert_hivex_value_key_args_xdr_to_protobuf (                                 guestfs_hivex_value_key_args *xdr,
                                 guestfs_protobuf_hivex_value_key_args *pbc)
{
  pbc->valueh = xdr->valueh;
}

void
convert_hivex_value_key_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_value_key_args *pbc,
                                 guestfs_hivex_value_key_args *xdr)
{
  xdr->valueh = pbc->valueh;
}

void
convert_hivex_value_key_ret_xdr_to_protobuf (                                guestfs_hivex_value_key_ret *xdr,
                                guestfs_protobuf_hivex_value_key_ret *pbc)
{
  pbc->key = strdup (xdr->key);
}

void
convert_hivex_value_key_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_value_key_ret *pbc,
                                guestfs_hivex_value_key_ret *xdr)
{
  xdr->key = strdup (pbc->key);
}

void
convert_hivex_value_type_args_xdr_to_protobuf (                                 guestfs_hivex_value_type_args *xdr,
                                 guestfs_protobuf_hivex_value_type_args *pbc)
{
  pbc->valueh = xdr->valueh;
}

void
convert_hivex_value_type_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_value_type_args *pbc,
                                 guestfs_hivex_value_type_args *xdr)
{
  xdr->valueh = pbc->valueh;
}

void
convert_hivex_value_type_ret_xdr_to_protobuf (                                guestfs_hivex_value_type_ret *xdr,
                                guestfs_protobuf_hivex_value_type_ret *pbc)
{
  pbc->datatype = xdr->datatype;
}

void
convert_hivex_value_type_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_value_type_ret *pbc,
                                guestfs_hivex_value_type_ret *xdr)
{
  xdr->datatype = pbc->datatype;
}

void
convert_hivex_value_value_args_xdr_to_protobuf (                                 guestfs_hivex_value_value_args *xdr,
                                 guestfs_protobuf_hivex_value_value_args *pbc)
{
  pbc->valueh = xdr->valueh;
}

void
convert_hivex_value_value_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_value_value_args *pbc,
                                 guestfs_hivex_value_value_args *xdr)
{
  xdr->valueh = pbc->valueh;
}

void
convert_hivex_value_value_ret_xdr_to_protobuf (                                guestfs_hivex_value_value_ret *xdr,
                                guestfs_protobuf_hivex_value_value_ret *pbc)
{
  pbc->databuf.data = malloc (xdr->databuf.databuf_len);
  memcpy (pbc->databuf.data, xdr->databuf.databuf_val, xdr->databuf.databuf_len);
  pbc->databuf.len = xdr->databuf.databuf_len; 
}

void
convert_hivex_value_value_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_value_value_ret *pbc,
                                guestfs_hivex_value_value_ret *xdr)
{
  xdr->databuf.databuf_val = malloc (pbc->databuf.len);
  memcpy (xdr->databuf.databuf_val, pbc->databuf.data, pbc->databuf.len); 
  xdr->databuf.databuf_len = pbc->databuf.len; 
}

void
convert_hivex_commit_args_xdr_to_protobuf (                                 guestfs_hivex_commit_args *xdr,
                                 guestfs_protobuf_hivex_commit_args *pbc)
{
  char *tmp = xdr->filename ? strdup (*xdr->filename) : NULL;
  pbc->filename = tmp ? &tmp : NULL;
}

void
convert_hivex_commit_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_commit_args *pbc,
                                 guestfs_hivex_commit_args *xdr)
{
  char *tmp = pbc->filename ? strdup (*pbc->filename) : NULL;
  xdr->filename = tmp ? &tmp : NULL;
}

void
convert_hivex_node_add_child_args_xdr_to_protobuf (                                 guestfs_hivex_node_add_child_args *xdr,
                                 guestfs_protobuf_hivex_node_add_child_args *pbc)
{
  pbc->parent = xdr->parent;
  pbc->name = strdup (xdr->name);
}

void
convert_hivex_node_add_child_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_add_child_args *pbc,
                                 guestfs_hivex_node_add_child_args *xdr)
{
  xdr->parent = pbc->parent;
  xdr->name = strdup (pbc->name);
}

void
convert_hivex_node_add_child_ret_xdr_to_protobuf (                                guestfs_hivex_node_add_child_ret *xdr,
                                guestfs_protobuf_hivex_node_add_child_ret *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_node_add_child_ret_protobuf_to_xdr (                                guestfs_protobuf_hivex_node_add_child_ret *pbc,
                                guestfs_hivex_node_add_child_ret *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_delete_child_args_xdr_to_protobuf (                                 guestfs_hivex_node_delete_child_args *xdr,
                                 guestfs_protobuf_hivex_node_delete_child_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
}

void
convert_hivex_node_delete_child_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_delete_child_args *pbc,
                                 guestfs_hivex_node_delete_child_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
}

void
convert_hivex_node_set_value_args_xdr_to_protobuf (                                 guestfs_hivex_node_set_value_args *xdr,
                                 guestfs_protobuf_hivex_node_set_value_args *pbc)
{
  pbc->nodeh = xdr->nodeh;
  pbc->key = strdup (xdr->key);
  pbc->t = xdr->t;
  pbc->val.data = malloc (xdr->val.val_len);
  memcpy (pbc->val.data, xdr->val.val_val, xdr->val.val_len);
  pbc->val.len = xdr->val.val_len; 
}

void
convert_hivex_node_set_value_args_protobuf_to_xdr (                                 guestfs_protobuf_hivex_node_set_value_args *pbc,
                                 guestfs_hivex_node_set_value_args *xdr)
{
  xdr->nodeh = pbc->nodeh;
  xdr->key = strdup (pbc->key);
  xdr->t = pbc->t;
  xdr->val.val_val = malloc (pbc->val.len);
  memcpy (xdr->val.val_val, pbc->val.data, pbc->val.len); 
  xdr->val.val_len = pbc->val.len; 
}

void
convert_xfs_repair_args_xdr_to_protobuf (                                 guestfs_xfs_repair_args *xdr,
                                 guestfs_protobuf_xfs_repair_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->forcelogzero = xdr->forcelogzero;
  pbc->nomodify = xdr->nomodify;
  pbc->noprefetch = xdr->noprefetch;
  pbc->forcegeometry = xdr->forcegeometry;
  pbc->maxmem = xdr->maxmem;
  pbc->ihashsize = xdr->ihashsize;
  pbc->bhashsize = xdr->bhashsize;
  pbc->agstride = xdr->agstride;
  pbc->logdev = strdup (xdr->logdev);
  pbc->rtdev = strdup (xdr->rtdev);
}

void
convert_xfs_repair_args_protobuf_to_xdr (                                 guestfs_protobuf_xfs_repair_args *pbc,
                                 guestfs_xfs_repair_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->forcelogzero = pbc->forcelogzero;
  xdr->nomodify = pbc->nomodify;
  xdr->noprefetch = pbc->noprefetch;
  xdr->forcegeometry = pbc->forcegeometry;
  xdr->maxmem = pbc->maxmem;
  xdr->ihashsize = pbc->ihashsize;
  xdr->bhashsize = pbc->bhashsize;
  xdr->agstride = pbc->agstride;
  xdr->logdev = strdup (pbc->logdev);
  xdr->rtdev = strdup (pbc->rtdev);
}

void
convert_xfs_repair_ret_xdr_to_protobuf (                                guestfs_xfs_repair_ret *xdr,
                                guestfs_protobuf_xfs_repair_ret *pbc)
{
  pbc->status = xdr->status;
}

void
convert_xfs_repair_ret_protobuf_to_xdr (                                guestfs_protobuf_xfs_repair_ret *pbc,
                                guestfs_xfs_repair_ret *xdr)
{
  xdr->status = pbc->status;
}

void
convert_rm_ff_args_xdr_to_protobuf (                                 guestfs_rm_ff_args *xdr,
                                 guestfs_protobuf_rm_ff_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_rm_ff_args_protobuf_to_xdr (                                 guestfs_protobuf_rm_ff_args *pbc,
                                 guestfs_rm_ff_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_mke2fs_args_xdr_to_protobuf (                                 guestfs_mke2fs_args *xdr,
                                 guestfs_protobuf_mke2fs_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->blockscount = xdr->blockscount;
  pbc->blocksize = xdr->blocksize;
  pbc->fragsize = xdr->fragsize;
  pbc->blockspergroup = xdr->blockspergroup;
  pbc->numberofgroups = xdr->numberofgroups;
  pbc->bytesperinode = xdr->bytesperinode;
  pbc->inodesize = xdr->inodesize;
  pbc->journalsize = xdr->journalsize;
  pbc->numberofinodes = xdr->numberofinodes;
  pbc->stridesize = xdr->stridesize;
  pbc->stripewidth = xdr->stripewidth;
  pbc->maxonlineresize = xdr->maxonlineresize;
  pbc->reservedblockspercentage = xdr->reservedblockspercentage;
  pbc->mmpupdateinterval = xdr->mmpupdateinterval;
  pbc->journaldevice = strdup (xdr->journaldevice);
  pbc->label = strdup (xdr->label);
  pbc->lastmounteddir = strdup (xdr->lastmounteddir);
  pbc->creatoros = strdup (xdr->creatoros);
  pbc->fstype = strdup (xdr->fstype);
  pbc->usagetype = strdup (xdr->usagetype);
  pbc->uuid = strdup (xdr->uuid);
  pbc->forcecreate = xdr->forcecreate;
  pbc->writesbandgrouponly = xdr->writesbandgrouponly;
  pbc->lazyitableinit = xdr->lazyitableinit;
  pbc->lazyjournalinit = xdr->lazyjournalinit;
  pbc->testfs = xdr->testfs;
  pbc->discard = xdr->discard;
  pbc->quotatype = xdr->quotatype;
  pbc->extent = xdr->extent;
  pbc->filetype = xdr->filetype;
  pbc->flexbg = xdr->flexbg;
  pbc->hasjournal = xdr->hasjournal;
  pbc->journaldev = xdr->journaldev;
  pbc->largefile = xdr->largefile;
  pbc->quota = xdr->quota;
  pbc->resizeinode = xdr->resizeinode;
  pbc->sparsesuper = xdr->sparsesuper;
  pbc->uninitbg = xdr->uninitbg;
}

void
convert_mke2fs_args_protobuf_to_xdr (                                 guestfs_protobuf_mke2fs_args *pbc,
                                 guestfs_mke2fs_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->blockscount = pbc->blockscount;
  xdr->blocksize = pbc->blocksize;
  xdr->fragsize = pbc->fragsize;
  xdr->blockspergroup = pbc->blockspergroup;
  xdr->numberofgroups = pbc->numberofgroups;
  xdr->bytesperinode = pbc->bytesperinode;
  xdr->inodesize = pbc->inodesize;
  xdr->journalsize = pbc->journalsize;
  xdr->numberofinodes = pbc->numberofinodes;
  xdr->stridesize = pbc->stridesize;
  xdr->stripewidth = pbc->stripewidth;
  xdr->maxonlineresize = pbc->maxonlineresize;
  xdr->reservedblockspercentage = pbc->reservedblockspercentage;
  xdr->mmpupdateinterval = pbc->mmpupdateinterval;
  xdr->journaldevice = strdup (pbc->journaldevice);
  xdr->label = strdup (pbc->label);
  xdr->lastmounteddir = strdup (pbc->lastmounteddir);
  xdr->creatoros = strdup (pbc->creatoros);
  xdr->fstype = strdup (pbc->fstype);
  xdr->usagetype = strdup (pbc->usagetype);
  xdr->uuid = strdup (pbc->uuid);
  xdr->forcecreate = pbc->forcecreate;
  xdr->writesbandgrouponly = pbc->writesbandgrouponly;
  xdr->lazyitableinit = pbc->lazyitableinit;
  xdr->lazyjournalinit = pbc->lazyjournalinit;
  xdr->testfs = pbc->testfs;
  xdr->discard = pbc->discard;
  xdr->quotatype = pbc->quotatype;
  xdr->extent = pbc->extent;
  xdr->filetype = pbc->filetype;
  xdr->flexbg = pbc->flexbg;
  xdr->hasjournal = pbc->hasjournal;
  xdr->journaldev = pbc->journaldev;
  xdr->largefile = pbc->largefile;
  xdr->quota = pbc->quota;
  xdr->resizeinode = pbc->resizeinode;
  xdr->sparsesuper = pbc->sparsesuper;
  xdr->uninitbg = pbc->uninitbg;
}

void
convert_list_disk_labels_ret_xdr_to_protobuf (                                guestfs_list_disk_labels_ret *xdr,
                                guestfs_protobuf_list_disk_labels_ret *pbc)
{
  pbc->labels = malloc (xdr->labels.labels_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->labels.labels_len; ++i) {
    pbc->n_labels = i;
    pbc->labels[i] = xdr->labels.labels_val[i] ? strdup (xdr->labels.labels_val[i]) : NULL;
  }
}

void
convert_list_disk_labels_ret_protobuf_to_xdr (                                guestfs_protobuf_list_disk_labels_ret *pbc,
                                guestfs_list_disk_labels_ret *xdr)
{
  xdr->labels.labels_val = malloc (pbc->n_labels * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_labels; ++i) {
    xdr->labels.labels_len = i;
    xdr->labels.labels_val[i] = pbc->labels[i] ? strdup (pbc->labels[i]) : NULL;
  }
}

void
convert_internal_hot_add_drive_args_xdr_to_protobuf (                                 guestfs_internal_hot_add_drive_args *xdr,
                                 guestfs_protobuf_internal_hot_add_drive_args *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_internal_hot_add_drive_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_hot_add_drive_args *pbc,
                                 guestfs_internal_hot_add_drive_args *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_internal_hot_remove_drive_precheck_args_xdr_to_protobuf (                                 guestfs_internal_hot_remove_drive_precheck_args *xdr,
                                 guestfs_protobuf_internal_hot_remove_drive_precheck_args *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_internal_hot_remove_drive_precheck_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_hot_remove_drive_precheck_args *pbc,
                                 guestfs_internal_hot_remove_drive_precheck_args *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_internal_hot_remove_drive_args_xdr_to_protobuf (                                 guestfs_internal_hot_remove_drive_args *xdr,
                                 guestfs_protobuf_internal_hot_remove_drive_args *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_internal_hot_remove_drive_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_hot_remove_drive_args *pbc,
                                 guestfs_internal_hot_remove_drive_args *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_mktemp_args_xdr_to_protobuf (                                 guestfs_mktemp_args *xdr,
                                 guestfs_protobuf_mktemp_args *pbc)
{
  pbc->tmpl = strdup (xdr->tmpl);
  pbc->suffix = strdup (xdr->suffix);
}

void
convert_mktemp_args_protobuf_to_xdr (                                 guestfs_protobuf_mktemp_args *pbc,
                                 guestfs_mktemp_args *xdr)
{
  xdr->tmpl = strdup (pbc->tmpl);
  xdr->suffix = strdup (pbc->suffix);
}

void
convert_mktemp_ret_xdr_to_protobuf (                                guestfs_mktemp_ret *xdr,
                                guestfs_protobuf_mktemp_ret *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_mktemp_ret_protobuf_to_xdr (                                guestfs_protobuf_mktemp_ret *pbc,
                                guestfs_mktemp_ret *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_mklost_and_found_args_xdr_to_protobuf (                                 guestfs_mklost_and_found_args *xdr,
                                 guestfs_protobuf_mklost_and_found_args *pbc)
{
  pbc->mountpoint = strdup (xdr->mountpoint);
}

void
convert_mklost_and_found_args_protobuf_to_xdr (                                 guestfs_protobuf_mklost_and_found_args *pbc,
                                 guestfs_mklost_and_found_args *xdr)
{
  xdr->mountpoint = strdup (pbc->mountpoint);
}

void
convert_acl_get_file_args_xdr_to_protobuf (                                 guestfs_acl_get_file_args *xdr,
                                 guestfs_protobuf_acl_get_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->acltype = strdup (xdr->acltype);
}

void
convert_acl_get_file_args_protobuf_to_xdr (                                 guestfs_protobuf_acl_get_file_args *pbc,
                                 guestfs_acl_get_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->acltype = strdup (pbc->acltype);
}

void
convert_acl_get_file_ret_xdr_to_protobuf (                                guestfs_acl_get_file_ret *xdr,
                                guestfs_protobuf_acl_get_file_ret *pbc)
{
  pbc->acl = strdup (xdr->acl);
}

void
convert_acl_get_file_ret_protobuf_to_xdr (                                guestfs_protobuf_acl_get_file_ret *pbc,
                                guestfs_acl_get_file_ret *xdr)
{
  xdr->acl = strdup (pbc->acl);
}

void
convert_acl_set_file_args_xdr_to_protobuf (                                 guestfs_acl_set_file_args *xdr,
                                 guestfs_protobuf_acl_set_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->acltype = strdup (xdr->acltype);
  pbc->acl = strdup (xdr->acl);
}

void
convert_acl_set_file_args_protobuf_to_xdr (                                 guestfs_protobuf_acl_set_file_args *pbc,
                                 guestfs_acl_set_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->acltype = strdup (pbc->acltype);
  xdr->acl = strdup (pbc->acl);
}

void
convert_acl_delete_def_file_args_xdr_to_protobuf (                                 guestfs_acl_delete_def_file_args *xdr,
                                 guestfs_protobuf_acl_delete_def_file_args *pbc)
{
  pbc->dir = strdup (xdr->dir);
}

void
convert_acl_delete_def_file_args_protobuf_to_xdr (                                 guestfs_protobuf_acl_delete_def_file_args *pbc,
                                 guestfs_acl_delete_def_file_args *xdr)
{
  xdr->dir = strdup (pbc->dir);
}

void
convert_cap_get_file_args_xdr_to_protobuf (                                 guestfs_cap_get_file_args *xdr,
                                 guestfs_protobuf_cap_get_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_cap_get_file_args_protobuf_to_xdr (                                 guestfs_protobuf_cap_get_file_args *pbc,
                                 guestfs_cap_get_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_cap_get_file_ret_xdr_to_protobuf (                                guestfs_cap_get_file_ret *xdr,
                                guestfs_protobuf_cap_get_file_ret *pbc)
{
  pbc->cap = strdup (xdr->cap);
}

void
convert_cap_get_file_ret_protobuf_to_xdr (                                guestfs_protobuf_cap_get_file_ret *pbc,
                                guestfs_cap_get_file_ret *xdr)
{
  xdr->cap = strdup (pbc->cap);
}

void
convert_cap_set_file_args_xdr_to_protobuf (                                 guestfs_cap_set_file_args *xdr,
                                 guestfs_protobuf_cap_set_file_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->cap = strdup (xdr->cap);
}

void
convert_cap_set_file_args_protobuf_to_xdr (                                 guestfs_protobuf_cap_set_file_args *pbc,
                                 guestfs_cap_set_file_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->cap = strdup (pbc->cap);
}

void
convert_list_ldm_volumes_ret_xdr_to_protobuf (                                guestfs_list_ldm_volumes_ret *xdr,
                                guestfs_protobuf_list_ldm_volumes_ret *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) {
    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_list_ldm_volumes_ret_protobuf_to_xdr (                                guestfs_protobuf_list_ldm_volumes_ret *pbc,
                                guestfs_list_ldm_volumes_ret *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) {
    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_list_ldm_partitions_ret_xdr_to_protobuf (                                guestfs_list_ldm_partitions_ret *xdr,
                                guestfs_protobuf_list_ldm_partitions_ret *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) {
    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_list_ldm_partitions_ret_protobuf_to_xdr (                                guestfs_protobuf_list_ldm_partitions_ret *pbc,
                                guestfs_list_ldm_partitions_ret *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) {
    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_ldmtool_scan_ret_xdr_to_protobuf (                                guestfs_ldmtool_scan_ret *xdr,
                                guestfs_protobuf_ldmtool_scan_ret *pbc)
{
  pbc->guids = malloc (xdr->guids.guids_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->guids.guids_len; ++i) {
    pbc->n_guids = i;
    pbc->guids[i] = xdr->guids.guids_val[i] ? strdup (xdr->guids.guids_val[i]) : NULL;
  }
}

void
convert_ldmtool_scan_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_scan_ret *pbc,
                                guestfs_ldmtool_scan_ret *xdr)
{
  xdr->guids.guids_val = malloc (pbc->n_guids * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_guids; ++i) {
    xdr->guids.guids_len = i;
    xdr->guids.guids_val[i] = pbc->guids[i] ? strdup (pbc->guids[i]) : NULL;
  }
}

void
convert_ldmtool_scan_devices_args_xdr_to_protobuf (                                 guestfs_ldmtool_scan_devices_args *xdr,
                                 guestfs_protobuf_ldmtool_scan_devices_args *pbc)
{
  pbc->devices = malloc (xdr->devices.devices_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->devices.devices_len; ++i) 
{    pbc->n_devices = i;
    pbc->devices[i] = xdr->devices.devices_val[i] ? strdup (xdr->devices.devices_val[i]) : NULL;
  }
}

void
convert_ldmtool_scan_devices_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_scan_devices_args *pbc,
                                 guestfs_ldmtool_scan_devices_args *xdr)
{
  xdr->devices.devices_val = malloc (pbc->n_devices * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_devices; ++i) 
{    xdr->devices.devices_len = i;
    xdr->devices.devices_val[i] = pbc->devices[i] ? strdup (pbc->devices[i]) : NULL;
  }
}

void
convert_ldmtool_scan_devices_ret_xdr_to_protobuf (                                guestfs_ldmtool_scan_devices_ret *xdr,
                                guestfs_protobuf_ldmtool_scan_devices_ret *pbc)
{
  pbc->guids = malloc (xdr->guids.guids_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->guids.guids_len; ++i) {
    pbc->n_guids = i;
    pbc->guids[i] = xdr->guids.guids_val[i] ? strdup (xdr->guids.guids_val[i]) : NULL;
  }
}

void
convert_ldmtool_scan_devices_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_scan_devices_ret *pbc,
                                guestfs_ldmtool_scan_devices_ret *xdr)
{
  xdr->guids.guids_val = malloc (pbc->n_guids * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_guids; ++i) {
    xdr->guids.guids_len = i;
    xdr->guids.guids_val[i] = pbc->guids[i] ? strdup (pbc->guids[i]) : NULL;
  }
}

void
convert_ldmtool_diskgroup_name_args_xdr_to_protobuf (                                 guestfs_ldmtool_diskgroup_name_args *xdr,
                                 guestfs_protobuf_ldmtool_diskgroup_name_args *pbc)
{
  pbc->diskgroup = strdup (xdr->diskgroup);
}

void
convert_ldmtool_diskgroup_name_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_diskgroup_name_args *pbc,
                                 guestfs_ldmtool_diskgroup_name_args *xdr)
{
  xdr->diskgroup = strdup (pbc->diskgroup);
}

void
convert_ldmtool_diskgroup_name_ret_xdr_to_protobuf (                                guestfs_ldmtool_diskgroup_name_ret *xdr,
                                guestfs_protobuf_ldmtool_diskgroup_name_ret *pbc)
{
  pbc->name = strdup (xdr->name);
}

void
convert_ldmtool_diskgroup_name_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_diskgroup_name_ret *pbc,
                                guestfs_ldmtool_diskgroup_name_ret *xdr)
{
  xdr->name = strdup (pbc->name);
}

void
convert_ldmtool_diskgroup_volumes_args_xdr_to_protobuf (                                 guestfs_ldmtool_diskgroup_volumes_args *xdr,
                                 guestfs_protobuf_ldmtool_diskgroup_volumes_args *pbc)
{
  pbc->diskgroup = strdup (xdr->diskgroup);
}

void
convert_ldmtool_diskgroup_volumes_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_diskgroup_volumes_args *pbc,
                                 guestfs_ldmtool_diskgroup_volumes_args *xdr)
{
  xdr->diskgroup = strdup (pbc->diskgroup);
}

void
convert_ldmtool_diskgroup_volumes_ret_xdr_to_protobuf (                                guestfs_ldmtool_diskgroup_volumes_ret *xdr,
                                guestfs_protobuf_ldmtool_diskgroup_volumes_ret *pbc)
{
  pbc->volumes = malloc (xdr->volumes.volumes_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->volumes.volumes_len; ++i) {
    pbc->n_volumes = i;
    pbc->volumes[i] = xdr->volumes.volumes_val[i] ? strdup (xdr->volumes.volumes_val[i]) : NULL;
  }
}

void
convert_ldmtool_diskgroup_volumes_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_diskgroup_volumes_ret *pbc,
                                guestfs_ldmtool_diskgroup_volumes_ret *xdr)
{
  xdr->volumes.volumes_val = malloc (pbc->n_volumes * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_volumes; ++i) {
    xdr->volumes.volumes_len = i;
    xdr->volumes.volumes_val[i] = pbc->volumes[i] ? strdup (pbc->volumes[i]) : NULL;
  }
}

void
convert_ldmtool_diskgroup_disks_args_xdr_to_protobuf (                                 guestfs_ldmtool_diskgroup_disks_args *xdr,
                                 guestfs_protobuf_ldmtool_diskgroup_disks_args *pbc)
{
  pbc->diskgroup = strdup (xdr->diskgroup);
}

void
convert_ldmtool_diskgroup_disks_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_diskgroup_disks_args *pbc,
                                 guestfs_ldmtool_diskgroup_disks_args *xdr)
{
  xdr->diskgroup = strdup (pbc->diskgroup);
}

void
convert_ldmtool_diskgroup_disks_ret_xdr_to_protobuf (                                guestfs_ldmtool_diskgroup_disks_ret *xdr,
                                guestfs_protobuf_ldmtool_diskgroup_disks_ret *pbc)
{
  pbc->disks = malloc (xdr->disks.disks_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->disks.disks_len; ++i) {
    pbc->n_disks = i;
    pbc->disks[i] = xdr->disks.disks_val[i] ? strdup (xdr->disks.disks_val[i]) : NULL;
  }
}

void
convert_ldmtool_diskgroup_disks_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_diskgroup_disks_ret *pbc,
                                guestfs_ldmtool_diskgroup_disks_ret *xdr)
{
  xdr->disks.disks_val = malloc (pbc->n_disks * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_disks; ++i) {
    xdr->disks.disks_len = i;
    xdr->disks.disks_val[i] = pbc->disks[i] ? strdup (pbc->disks[i]) : NULL;
  }
}

void
convert_ldmtool_volume_type_args_xdr_to_protobuf (                                 guestfs_ldmtool_volume_type_args *xdr,
                                 guestfs_protobuf_ldmtool_volume_type_args *pbc)
{
  pbc->diskgroup = strdup (xdr->diskgroup);
  pbc->volume = strdup (xdr->volume);
}

void
convert_ldmtool_volume_type_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_volume_type_args *pbc,
                                 guestfs_ldmtool_volume_type_args *xdr)
{
  xdr->diskgroup = strdup (pbc->diskgroup);
  xdr->volume = strdup (pbc->volume);
}

void
convert_ldmtool_volume_type_ret_xdr_to_protobuf (                                guestfs_ldmtool_volume_type_ret *xdr,
                                guestfs_protobuf_ldmtool_volume_type_ret *pbc)
{
  pbc->voltype = strdup (xdr->voltype);
}

void
convert_ldmtool_volume_type_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_volume_type_ret *pbc,
                                guestfs_ldmtool_volume_type_ret *xdr)
{
  xdr->voltype = strdup (pbc->voltype);
}

void
convert_ldmtool_volume_hint_args_xdr_to_protobuf (                                 guestfs_ldmtool_volume_hint_args *xdr,
                                 guestfs_protobuf_ldmtool_volume_hint_args *pbc)
{
  pbc->diskgroup = strdup (xdr->diskgroup);
  pbc->volume = strdup (xdr->volume);
}

void
convert_ldmtool_volume_hint_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_volume_hint_args *pbc,
                                 guestfs_ldmtool_volume_hint_args *xdr)
{
  xdr->diskgroup = strdup (pbc->diskgroup);
  xdr->volume = strdup (pbc->volume);
}

void
convert_ldmtool_volume_hint_ret_xdr_to_protobuf (                                guestfs_ldmtool_volume_hint_ret *xdr,
                                guestfs_protobuf_ldmtool_volume_hint_ret *pbc)
{
  pbc->hint = strdup (xdr->hint);
}

void
convert_ldmtool_volume_hint_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_volume_hint_ret *pbc,
                                guestfs_ldmtool_volume_hint_ret *xdr)
{
  xdr->hint = strdup (pbc->hint);
}

void
convert_ldmtool_volume_partitions_args_xdr_to_protobuf (                                 guestfs_ldmtool_volume_partitions_args *xdr,
                                 guestfs_protobuf_ldmtool_volume_partitions_args *pbc)
{
  pbc->diskgroup = strdup (xdr->diskgroup);
  pbc->volume = strdup (xdr->volume);
}

void
convert_ldmtool_volume_partitions_args_protobuf_to_xdr (                                 guestfs_protobuf_ldmtool_volume_partitions_args *pbc,
                                 guestfs_ldmtool_volume_partitions_args *xdr)
{
  xdr->diskgroup = strdup (pbc->diskgroup);
  xdr->volume = strdup (pbc->volume);
}

void
convert_ldmtool_volume_partitions_ret_xdr_to_protobuf (                                guestfs_ldmtool_volume_partitions_ret *xdr,
                                guestfs_protobuf_ldmtool_volume_partitions_ret *pbc)
{
  pbc->partitions = malloc (xdr->partitions.partitions_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->partitions.partitions_len; ++i) {
    pbc->n_partitions = i;
    pbc->partitions[i] = xdr->partitions.partitions_val[i] ? strdup (xdr->partitions.partitions_val[i]) : NULL;
  }
}

void
convert_ldmtool_volume_partitions_ret_protobuf_to_xdr (                                guestfs_protobuf_ldmtool_volume_partitions_ret *pbc,
                                guestfs_ldmtool_volume_partitions_ret *xdr)
{
  xdr->partitions.partitions_val = malloc (pbc->n_partitions * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_partitions; ++i) {
    xdr->partitions.partitions_len = i;
    xdr->partitions.partitions_val[i] = pbc->partitions[i] ? strdup (pbc->partitions[i]) : NULL;
  }
}

void
convert_part_set_gpt_type_args_xdr_to_protobuf (                                 guestfs_part_set_gpt_type_args *xdr,
                                 guestfs_protobuf_part_set_gpt_type_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
  pbc->guid = strdup (xdr->guid);
}

void
convert_part_set_gpt_type_args_protobuf_to_xdr (                                 guestfs_protobuf_part_set_gpt_type_args *pbc,
                                 guestfs_part_set_gpt_type_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
  xdr->guid = strdup (pbc->guid);
}

void
convert_part_get_gpt_type_args_xdr_to_protobuf (                                 guestfs_part_get_gpt_type_args *xdr,
                                 guestfs_protobuf_part_get_gpt_type_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
}

void
convert_part_get_gpt_type_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_gpt_type_args *pbc,
                                 guestfs_part_get_gpt_type_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
}

void
convert_part_get_gpt_type_ret_xdr_to_protobuf (                                guestfs_part_get_gpt_type_ret *xdr,
                                guestfs_protobuf_part_get_gpt_type_ret *pbc)
{
  pbc->guid = strdup (xdr->guid);
}

void
convert_part_get_gpt_type_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_gpt_type_ret *pbc,
                                guestfs_part_get_gpt_type_ret *xdr)
{
  xdr->guid = strdup (pbc->guid);
}

void
convert_rename_args_xdr_to_protobuf (                                 guestfs_rename_args *xdr,
                                 guestfs_protobuf_rename_args *pbc)
{
  pbc->oldpath = strdup (xdr->oldpath);
  pbc->newpath = strdup (xdr->newpath);
}

void
convert_rename_args_protobuf_to_xdr (                                 guestfs_protobuf_rename_args *pbc,
                                 guestfs_rename_args *xdr)
{
  xdr->oldpath = strdup (pbc->oldpath);
  xdr->newpath = strdup (pbc->newpath);
}

void
convert_is_whole_device_args_xdr_to_protobuf (                                 guestfs_is_whole_device_args *xdr,
                                 guestfs_protobuf_is_whole_device_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_is_whole_device_args_protobuf_to_xdr (                                 guestfs_protobuf_is_whole_device_args *pbc,
                                 guestfs_is_whole_device_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_is_whole_device_ret_xdr_to_protobuf (                                guestfs_is_whole_device_ret *xdr,
                                guestfs_protobuf_is_whole_device_ret *pbc)
{
  pbc->flag = xdr->flag;
}

void
convert_is_whole_device_ret_protobuf_to_xdr (                                guestfs_protobuf_is_whole_device_ret *pbc,
                                guestfs_is_whole_device_ret *xdr)
{
  xdr->flag = pbc->flag;
}

void
convert_internal_parse_mountable_args_xdr_to_protobuf (                                 guestfs_internal_parse_mountable_args *xdr,
                                 guestfs_protobuf_internal_parse_mountable_args *pbc)
{
  pbc->mountable = strdup (xdr->mountable);
}

void
convert_internal_parse_mountable_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_parse_mountable_args *pbc,
                                 guestfs_internal_parse_mountable_args *xdr)
{
  xdr->mountable = strdup (pbc->mountable);
}

void
convert_internal_parse_mountable_ret_xdr_to_protobuf (                                guestfs_internal_parse_mountable_ret *xdr,
                                guestfs_protobuf_internal_parse_mountable_ret *pbc)
{
  pbc->mountable = malloc (sizeof (guestfs_protobuf_int_internal_mountable));
  convert_guestfs_int_internal_mountable_xdr_to_protobuf (&xdr->mountable, pbc->mountable);
}

void
convert_internal_parse_mountable_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_parse_mountable_ret *pbc,
                                guestfs_internal_parse_mountable_ret *xdr)
{
  convert_guestfs_int_internal_mountable_protobuf_to_xdr (pbc->mountable, &xdr->mountable);
}

void
convert_internal_rhbz914931_args_xdr_to_protobuf (                                 guestfs_internal_rhbz914931_args *xdr,
                                 guestfs_protobuf_internal_rhbz914931_args *pbc)
{
  pbc->count = xdr->count;
}

void
convert_internal_rhbz914931_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_rhbz914931_args *pbc,
                                 guestfs_internal_rhbz914931_args *xdr)
{
  xdr->count = pbc->count;
}

void
convert_feature_available_args_xdr_to_protobuf (                                 guestfs_feature_available_args *xdr,
                                 guestfs_protobuf_feature_available_args *pbc)
{
  pbc->groups = malloc (xdr->groups.groups_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->groups.groups_len; ++i) 
{    pbc->n_groups = i;
    pbc->groups[i] = xdr->groups.groups_val[i] ? strdup (xdr->groups.groups_val[i]) : NULL;
  }
}

void
convert_feature_available_args_protobuf_to_xdr (                                 guestfs_protobuf_feature_available_args *pbc,
                                 guestfs_feature_available_args *xdr)
{
  xdr->groups.groups_val = malloc (pbc->n_groups * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_groups; ++i) 
{    xdr->groups.groups_len = i;
    xdr->groups.groups_val[i] = pbc->groups[i] ? strdup (pbc->groups[i]) : NULL;
  }
}

void
convert_feature_available_ret_xdr_to_protobuf (                                guestfs_feature_available_ret *xdr,
                                guestfs_protobuf_feature_available_ret *pbc)
{
  pbc->isavailable = xdr->isavailable;
}

void
convert_feature_available_ret_protobuf_to_xdr (                                guestfs_protobuf_feature_available_ret *pbc,
                                guestfs_feature_available_ret *xdr)
{
  xdr->isavailable = pbc->isavailable;
}

void
convert_syslinux_args_xdr_to_protobuf (                                 guestfs_syslinux_args *xdr,
                                 guestfs_protobuf_syslinux_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->directory = strdup (xdr->directory);
}

void
convert_syslinux_args_protobuf_to_xdr (                                 guestfs_protobuf_syslinux_args *pbc,
                                 guestfs_syslinux_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->directory = strdup (pbc->directory);
}

void
convert_extlinux_args_xdr_to_protobuf (                                 guestfs_extlinux_args *xdr,
                                 guestfs_protobuf_extlinux_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_extlinux_args_protobuf_to_xdr (                                 guestfs_protobuf_extlinux_args *pbc,
                                 guestfs_extlinux_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_cp_rr_args_xdr_to_protobuf (                                 guestfs_cp_rr_args *xdr,
                                 guestfs_protobuf_cp_rr_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
}

void
convert_cp_rr_args_protobuf_to_xdr (                                 guestfs_protobuf_cp_rr_args *pbc,
                                 guestfs_cp_rr_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
}

void
convert_remount_args_xdr_to_protobuf (                                 guestfs_remount_args *xdr,
                                 guestfs_protobuf_remount_args *pbc)
{
  pbc->mountpoint = strdup (xdr->mountpoint);
  pbc->rw = xdr->rw;
}

void
convert_remount_args_protobuf_to_xdr (                                 guestfs_protobuf_remount_args *pbc,
                                 guestfs_remount_args *xdr)
{
  xdr->mountpoint = strdup (pbc->mountpoint);
  xdr->rw = pbc->rw;
}

void
convert_set_uuid_args_xdr_to_protobuf (                                 guestfs_set_uuid_args *xdr,
                                 guestfs_protobuf_set_uuid_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->uuid = strdup (xdr->uuid);
}

void
convert_set_uuid_args_protobuf_to_xdr (                                 guestfs_protobuf_set_uuid_args *pbc,
                                 guestfs_set_uuid_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->uuid = strdup (pbc->uuid);
}

void
convert_journal_open_args_xdr_to_protobuf (                                 guestfs_journal_open_args *xdr,
                                 guestfs_protobuf_journal_open_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
}

void
convert_journal_open_args_protobuf_to_xdr (                                 guestfs_protobuf_journal_open_args *pbc,
                                 guestfs_journal_open_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
}

void
convert_journal_next_ret_xdr_to_protobuf (                                guestfs_journal_next_ret *xdr,
                                guestfs_protobuf_journal_next_ret *pbc)
{
  pbc->more = xdr->more;
}

void
convert_journal_next_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_next_ret *pbc,
                                guestfs_journal_next_ret *xdr)
{
  xdr->more = pbc->more;
}

void
convert_journal_skip_args_xdr_to_protobuf (                                 guestfs_journal_skip_args *xdr,
                                 guestfs_protobuf_journal_skip_args *pbc)
{
  pbc->skip = xdr->skip;
}

void
convert_journal_skip_args_protobuf_to_xdr (                                 guestfs_protobuf_journal_skip_args *pbc,
                                 guestfs_journal_skip_args *xdr)
{
  xdr->skip = pbc->skip;
}

void
convert_journal_skip_ret_xdr_to_protobuf (                                guestfs_journal_skip_ret *xdr,
                                guestfs_protobuf_journal_skip_ret *pbc)
{
  pbc->rskip = xdr->rskip;
}

void
convert_journal_skip_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_skip_ret *pbc,
                                guestfs_journal_skip_ret *xdr)
{
  xdr->rskip = pbc->rskip;
}

void
convert_journal_get_data_threshold_ret_xdr_to_protobuf (                                guestfs_journal_get_data_threshold_ret *xdr,
                                guestfs_protobuf_journal_get_data_threshold_ret *pbc)
{
  pbc->threshold = xdr->threshold;
}

void
convert_journal_get_data_threshold_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_get_data_threshold_ret *pbc,
                                guestfs_journal_get_data_threshold_ret *xdr)
{
  xdr->threshold = pbc->threshold;
}

void
convert_journal_set_data_threshold_args_xdr_to_protobuf (                                 guestfs_journal_set_data_threshold_args *xdr,
                                 guestfs_protobuf_journal_set_data_threshold_args *pbc)
{
  pbc->threshold = xdr->threshold;
}

void
convert_journal_set_data_threshold_args_protobuf_to_xdr (                                 guestfs_protobuf_journal_set_data_threshold_args *pbc,
                                 guestfs_journal_set_data_threshold_args *xdr)
{
  xdr->threshold = pbc->threshold;
}

void
convert_aug_setm_args_xdr_to_protobuf (                                 guestfs_aug_setm_args *xdr,
                                 guestfs_protobuf_aug_setm_args *pbc)
{
  pbc->bbase = strdup (xdr->bbase);
  char *tmp = xdr->sub ? strdup (*xdr->sub) : NULL;
  pbc->sub = tmp ? &tmp : NULL;
  pbc->val = strdup (xdr->val);
}

void
convert_aug_setm_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_setm_args *pbc,
                                 guestfs_aug_setm_args *xdr)
{
  xdr->bbase = strdup (pbc->bbase);
  char *tmp = pbc->sub ? strdup (*pbc->sub) : NULL;
  xdr->sub = tmp ? &tmp : NULL;
  xdr->val = strdup (pbc->val);
}

void
convert_aug_setm_ret_xdr_to_protobuf (                                guestfs_aug_setm_ret *xdr,
                                guestfs_protobuf_aug_setm_ret *pbc)
{
  pbc->nodes = xdr->nodes;
}

void
convert_aug_setm_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_setm_ret *pbc,
                                guestfs_aug_setm_ret *xdr)
{
  xdr->nodes = pbc->nodes;
}

void
convert_aug_label_args_xdr_to_protobuf (                                 guestfs_aug_label_args *xdr,
                                 guestfs_protobuf_aug_label_args *pbc)
{
  pbc->augpath = strdup (xdr->augpath);
}

void
convert_aug_label_args_protobuf_to_xdr (                                 guestfs_protobuf_aug_label_args *pbc,
                                 guestfs_aug_label_args *xdr)
{
  xdr->augpath = strdup (pbc->augpath);
}

void
convert_aug_label_ret_xdr_to_protobuf (                                guestfs_aug_label_ret *xdr,
                                guestfs_protobuf_aug_label_ret *pbc)
{
  pbc->label = strdup (xdr->label);
}

void
convert_aug_label_ret_protobuf_to_xdr (                                guestfs_protobuf_aug_label_ret *pbc,
                                guestfs_aug_label_ret *xdr)
{
  xdr->label = strdup (pbc->label);
}

void
convert_internal_upload_args_xdr_to_protobuf (                                 guestfs_internal_upload_args *xdr,
                                 guestfs_protobuf_internal_upload_args *pbc)
{
  pbc->tmpname = strdup (xdr->tmpname);
  pbc->mode = xdr->mode;
}

void
convert_internal_upload_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_upload_args *pbc,
                                 guestfs_internal_upload_args *xdr)
{
  xdr->tmpname = strdup (pbc->tmpname);
  xdr->mode = pbc->mode;
}

void
convert_copy_attributes_args_xdr_to_protobuf (                                 guestfs_copy_attributes_args *xdr,
                                 guestfs_protobuf_copy_attributes_args *pbc)
{
  pbc->src = strdup (xdr->src);
  pbc->dest = strdup (xdr->dest);
  pbc->all = xdr->all;
  pbc->mode = xdr->mode;
  pbc->xattributes = xdr->xattributes;
  pbc->ownership = xdr->ownership;
}

void
convert_copy_attributes_args_protobuf_to_xdr (                                 guestfs_protobuf_copy_attributes_args *pbc,
                                 guestfs_copy_attributes_args *xdr)
{
  xdr->src = strdup (pbc->src);
  xdr->dest = strdup (pbc->dest);
  xdr->all = pbc->all;
  xdr->mode = pbc->mode;
  xdr->xattributes = pbc->xattributes;
  xdr->ownership = pbc->ownership;
}

void
convert_part_get_name_args_xdr_to_protobuf (                                 guestfs_part_get_name_args *xdr,
                                 guestfs_protobuf_part_get_name_args *pbc)
{
  pbc->device = strdup (xdr->device);
  pbc->partnum = xdr->partnum;
}

void
convert_part_get_name_args_protobuf_to_xdr (                                 guestfs_protobuf_part_get_name_args *pbc,
                                 guestfs_part_get_name_args *xdr)
{
  xdr->device = strdup (pbc->device);
  xdr->partnum = pbc->partnum;
}

void
convert_part_get_name_ret_xdr_to_protobuf (                                guestfs_part_get_name_ret *xdr,
                                guestfs_protobuf_part_get_name_ret *pbc)
{
  pbc->name = strdup (xdr->name);
}

void
convert_part_get_name_ret_protobuf_to_xdr (                                guestfs_protobuf_part_get_name_ret *pbc,
                                guestfs_part_get_name_ret *xdr)
{
  xdr->name = strdup (pbc->name);
}

void
convert_blkdiscard_args_xdr_to_protobuf (                                 guestfs_blkdiscard_args *xdr,
                                 guestfs_protobuf_blkdiscard_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blkdiscard_args_protobuf_to_xdr (                                 guestfs_protobuf_blkdiscard_args *pbc,
                                 guestfs_blkdiscard_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blkdiscardzeroes_args_xdr_to_protobuf (                                 guestfs_blkdiscardzeroes_args *xdr,
                                 guestfs_protobuf_blkdiscardzeroes_args *pbc)
{
  pbc->device = strdup (xdr->device);
}

void
convert_blkdiscardzeroes_args_protobuf_to_xdr (                                 guestfs_protobuf_blkdiscardzeroes_args *pbc,
                                 guestfs_blkdiscardzeroes_args *xdr)
{
  xdr->device = strdup (pbc->device);
}

void
convert_blkdiscardzeroes_ret_xdr_to_protobuf (                                guestfs_blkdiscardzeroes_ret *xdr,
                                guestfs_protobuf_blkdiscardzeroes_ret *pbc)
{
  pbc->zeroes = xdr->zeroes;
}

void
convert_blkdiscardzeroes_ret_protobuf_to_xdr (                                guestfs_protobuf_blkdiscardzeroes_ret *pbc,
                                guestfs_blkdiscardzeroes_ret *xdr)
{
  xdr->zeroes = pbc->zeroes;
}

void
convert_cpio_out_args_xdr_to_protobuf (                                 guestfs_cpio_out_args *xdr,
                                 guestfs_protobuf_cpio_out_args *pbc)
{
  pbc->directory = strdup (xdr->directory);
  pbc->format = strdup (xdr->format);
}

void
convert_cpio_out_args_protobuf_to_xdr (                                 guestfs_protobuf_cpio_out_args *pbc,
                                 guestfs_cpio_out_args *xdr)
{
  xdr->directory = strdup (pbc->directory);
  xdr->format = strdup (pbc->format);
}

void
convert_journal_get_realtime_usec_ret_xdr_to_protobuf (                                guestfs_journal_get_realtime_usec_ret *xdr,
                                guestfs_protobuf_journal_get_realtime_usec_ret *pbc)
{
  pbc->usec = xdr->usec;
}

void
convert_journal_get_realtime_usec_ret_protobuf_to_xdr (                                guestfs_protobuf_journal_get_realtime_usec_ret *pbc,
                                guestfs_journal_get_realtime_usec_ret *xdr)
{
  xdr->usec = pbc->usec;
}

void
convert_statns_args_xdr_to_protobuf (                                 guestfs_statns_args *xdr,
                                 guestfs_protobuf_statns_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_statns_args_protobuf_to_xdr (                                 guestfs_protobuf_statns_args *pbc,
                                 guestfs_statns_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_statns_ret_xdr_to_protobuf (                                guestfs_statns_ret *xdr,
                                guestfs_protobuf_statns_ret *pbc)
{
  pbc->statbuf = malloc (sizeof (guestfs_protobuf_int_statns));
  convert_guestfs_int_statns_xdr_to_protobuf (&xdr->statbuf, pbc->statbuf);
}

void
convert_statns_ret_protobuf_to_xdr (                                guestfs_protobuf_statns_ret *pbc,
                                guestfs_statns_ret *xdr)
{
  convert_guestfs_int_statns_protobuf_to_xdr (pbc->statbuf, &xdr->statbuf);
}

void
convert_lstatns_args_xdr_to_protobuf (                                 guestfs_lstatns_args *xdr,
                                 guestfs_protobuf_lstatns_args *pbc)
{
  pbc->path = strdup (xdr->path);
}

void
convert_lstatns_args_protobuf_to_xdr (                                 guestfs_protobuf_lstatns_args *pbc,
                                 guestfs_lstatns_args *xdr)
{
  xdr->path = strdup (pbc->path);
}

void
convert_lstatns_ret_xdr_to_protobuf (                                guestfs_lstatns_ret *xdr,
                                guestfs_protobuf_lstatns_ret *pbc)
{
  pbc->statbuf = malloc (sizeof (guestfs_protobuf_int_statns));
  convert_guestfs_int_statns_xdr_to_protobuf (&xdr->statbuf, pbc->statbuf);
}

void
convert_lstatns_ret_protobuf_to_xdr (                                guestfs_protobuf_lstatns_ret *pbc,
                                guestfs_lstatns_ret *xdr)
{
  convert_guestfs_int_statns_protobuf_to_xdr (pbc->statbuf, &xdr->statbuf);
}

void
convert_internal_lstatnslist_args_xdr_to_protobuf (                                 guestfs_internal_lstatnslist_args *xdr,
                                 guestfs_protobuf_internal_lstatnslist_args *pbc)
{
  pbc->path = strdup (xdr->path);
  pbc->names = malloc (xdr->names.names_len * sizeof (char*));
  int i;
  for (i = 0; i < xdr->names.names_len; ++i) 
{    pbc->n_names = i;
    pbc->names[i] = xdr->names.names_val[i] ? strdup (xdr->names.names_val[i]) : NULL;
  }
}

void
convert_internal_lstatnslist_args_protobuf_to_xdr (                                 guestfs_protobuf_internal_lstatnslist_args *pbc,
                                 guestfs_internal_lstatnslist_args *xdr)
{
  xdr->path = strdup (pbc->path);
  xdr->names.names_val = malloc (pbc->n_names * sizeof (char*));
  int i;
  for (i = 0; i < pbc->n_names; ++i) 
{    xdr->names.names_len = i;
    xdr->names.names_val[i] = pbc->names[i] ? strdup (pbc->names[i]) : NULL;
  }
}

void
convert_internal_lstatnslist_ret_xdr_to_protobuf (                                guestfs_internal_lstatnslist_ret *xdr,
                                guestfs_protobuf_internal_lstatnslist_ret *pbc)
{
  pbc->statbufs = malloc (sizeof (guestfs_protobuf_int_statns_list));
  convert_guestfs_int_statns_list_xdr_to_protobuf (&xdr->statbufs, pbc->statbufs);
}

void
convert_internal_lstatnslist_ret_protobuf_to_xdr (                                guestfs_protobuf_internal_lstatnslist_ret *pbc,
                                guestfs_internal_lstatnslist_ret *xdr)
{
  convert_guestfs_int_statns_list_protobuf_to_xdr (pbc->statbufs, &xdr->statbufs);
}

