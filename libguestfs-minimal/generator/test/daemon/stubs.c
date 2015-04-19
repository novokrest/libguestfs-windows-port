/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

#include "daemon.h"
#include "c-ctype.h"
#include "guestfs_protocol.h"
#include "actions.h"
#include "optgroups.h"

/* Some macros to make resolving devices easier.  These used to
 * be available in daemon.h but now they are only used by stubs.
 */

/* All functions that need an argument that is a device or partition name
 * must call this macro.  It checks that the device exists and does
 * device name translation (described in the guestfs(3) manpage).
 * Note that the "path" argument may be modified.
 *
 * NB. Cannot be used for FileIn functions.
 */
#define RESOLVE_DEVICE(path,path_out,cancel_stmt,fail_stmt)             \
  do {									\
    if (STRNEQLEN ((path), "/dev/", 5)) {				\
      cancel_stmt;                                                      \
      reply_with_error ("%s: %s: expecting a device name", __func__, (path)); \
      fail_stmt;							\
    }									\
    if (is_root_device (path)) {                                        \
      cancel_stmt;                                                      \
      reply_with_error ("%s: %s: device not found", __func__, path);    \
      fail_stmt;                                                        \
    }                                                                   \
    (path_out) = device_name_translation ((path));                      \
    if ((path_out) == NULL) {                                           \
      int err = errno;                                                  \
      cancel_stmt;                                                      \
      errno = err;                                                      \
      reply_with_perror ("%s: %s", __func__, path);                     \
      fail_stmt;							\
    }                                                                   \
  } while (0)

/* All functions that take a mountable argument must call this macro.
 * It parses the mountable into a mountable_t, ensures any
 * underlying device exists, and does device name translation
 * (described in the guestfs(3) manpage).
 *
 * Note that the "string" argument may be modified.
 */
#define RESOLVE_MOUNTABLE(string,mountable,cancel_stmt,fail_stmt)       \
  do {                                                                  \
    if (STRPREFIX ((string), "btrfsvol:")) {                            \
      if (parse_btrfsvol ((string) + strlen ("btrfsvol:"), &(mountable)) == -1)\
      {                                                                 \
        cancel_stmt;                                                    \
        reply_with_error ("%s: %s: expecting a btrfs volume",           \
                          __func__, (string));                          \
        fail_stmt;                                                      \
      }                                                                 \
    }                                                                   \
    else {                                                              \
      (mountable).type = MOUNTABLE_DEVICE;                              \
      (mountable).device = NULL;                                        \
      (mountable).volume = NULL;                                        \
      RESOLVE_DEVICE ((string), (mountable).device, cancel_stmt, fail_stmt); \
    }                                                                   \
  } while (0)

/* Helper for functions which need either an absolute path in the
 * mounted filesystem, OR a /dev/ device which exists.
 *
 * NB. Cannot be used for FileIn functions.
 *
 * NB #2: Functions which mix filenames and device paths should be
 * avoided, and existing functions should be deprecated.  This is
 * because we intend in future to make device parameters a distinct
 * type from filenames.
 */
#define REQUIRE_ROOT_OR_RESOLVE_DEVICE(path,path_out,cancel_stmt,fail_stmt) \
  do {									\
    if (STREQLEN ((path), "/dev/", 5))                                  \
      RESOLVE_DEVICE ((path), (path_out), cancel_stmt, fail_stmt);      \
    else {								\
      NEED_ROOT (cancel_stmt, fail_stmt);                               \
      ABS_PATH ((path), cancel_stmt, fail_stmt);                        \
      (path_out) = strdup ((path));                                     \
      if ((path_out) == NULL) {                                         \
        cancel_stmt;                                                    \
        reply_with_perror ("strdup");                                   \
        fail_stmt;                                                      \
      }                                                                 \
    }									\
  } while (0)

/* Helper for functions which need either an absolute path in the
 * mounted filesystem, OR a valid mountable description.
 */
#define REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE(string, mountable,            \
                                          cancel_stmt, fail_stmt)       \
  do {                                                                  \
    if (STRPREFIX ((string), "/dev/") || (string)[0] != '/') {\
      RESOLVE_MOUNTABLE (string, mountable, cancel_stmt, fail_stmt);    \
    }                                                                   \
    else {                                                              \
      NEED_ROOT (cancel_stmt, fail_stmt);                               \
      /* NB: It's a path, not a device. */                              \
      (mountable).type = MOUNTABLE_PATH;                                \
      (mountable).device = strdup ((string));                           \
      (mountable).volume = NULL;                                        \
      if ((mountable).device == NULL) {                                 \
        cancel_stmt;                                                    \
        reply_with_perror ("strdup");                                   \
        fail_stmt;                                                      \
      }                                                                 \
    }                                                                   \
  } while (0)                                                           \

/* Free the mountable.device & mountable.volume fields which are
 * allocated by the above macros.
 */
#ifdef HAVE_ATTRIBUTE_CLEANUP
#define CLEANUP_FREE_MOUNTABLE __attribute__((cleanup(cleanup_free_mountable)))
#else
#define CLEANUP_FREE_MOUNTABLE
#endif

static void
cleanup_free_mountable (mountable_t *mountable)
{
  if (mountable) {
    free (mountable->device);
    free (mountable->volume);
  }
}

static void
mount_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mount_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mount_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);
  mountpoint = args->mountpoint;

  r = do_mount (&mountable, mountpoint);
  if (r == -1)
    /* do_mount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sync_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_sync ();
  if (r == -1)
    /* do_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
touch_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_touch_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = touch_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_touch (path);
  if (r == -1)
    /* do_touch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ll_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_ll_args *args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ll_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_ll (directory);
  if (r == NULL)
    /* do_ll has already called reply_with_error */
    goto done;

  guestfs_Ll_ret ret;
  char *bufret;
  size_t lenret;
  ll__init (&ret);
  ret.listing = r;
  lenret = ll__get_packed_size (&ret);
  bufret = malloc (lenret);
  ll__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
list_devices_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_devices ();
  if (r == NULL)
    /* do_list_devices has already called reply_with_error */
    goto done;

  guestfs_ListDevices_ret ret;
  char *bufret;
  size_t lenret;
  list_devices__init (&ret);
  ret.n_devices = count_strings (r);
  ret.devices = r;
  lenret = list_devices__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_devices__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
list_partitions_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_partitions ();
  if (r == NULL)
    /* do_list_partitions has already called reply_with_error */
    goto done;

  guestfs_ListPartitions_ret ret;
  char *bufret;
  size_t lenret;
  list_partitions__init (&ret);
  ret.n_partitions = count_strings (r);
  ret.partitions = r;
  lenret = list_partitions__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_partitions__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
pvs_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvs ();
  if (r == NULL)
    /* do_pvs has already called reply_with_error */
    goto done;

  guestfs_Pvs_ret ret;
  char *bufret;
  size_t lenret;
  pvs__init (&ret);
  ret.n_physvols = count_strings (r);
  ret.physvols = r;
  lenret = pvs__get_packed_size (&ret);
  bufret = malloc (lenret);
  pvs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
vgs_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgs ();
  if (r == NULL)
    /* do_vgs has already called reply_with_error */
    goto done;

  guestfs_Vgs_ret ret;
  char *bufret;
  size_t lenret;
  vgs__init (&ret);
  ret.n_volgroups = count_strings (r);
  ret.volgroups = r;
  lenret = vgs__get_packed_size (&ret);
  bufret = malloc (lenret);
  vgs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
lvs_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvs ();
  if (r == NULL)
    /* do_lvs has already called reply_with_error */
    goto done;

  guestfs_Lvs_ret ret;
  char *bufret;
  size_t lenret;
  lvs__init (&ret);
  ret.n_logvols = count_strings (r);
  ret.logvols = r;
  lenret = lvs__get_packed_size (&ret);
  bufret = malloc (lenret);
  lvs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
pvs_full_stub (char const *data, size_t datalen)
{
  guestfs_int_lvm_pv_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvs_full ();
  if (r == NULL)
    /* do_pvs_full has already called reply_with_error */
    goto done;

  guestfs_pvs_full_ret ret;
  char *bufret;
  size_t lenret;
  pvs_full__init (&ret);
  ret.physvols = r;
  lenret = pvs_full__get_packed_size (&ret);
  bufret = malloc (lenret);
  pvs_full__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
vgs_full_stub (char const *data, size_t datalen)
{
  guestfs_int_lvm_vg_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgs_full ();
  if (r == NULL)
    /* do_vgs_full has already called reply_with_error */
    goto done;

  guestfs_vgs_full_ret ret;
  char *bufret;
  size_t lenret;
  vgs_full__init (&ret);
  ret.volgroups = r;
  lenret = vgs_full__get_packed_size (&ret);
  bufret = malloc (lenret);
  vgs_full__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
lvs_full_stub (char const *data, size_t datalen)
{
  guestfs_int_lvm_lv_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvs_full ();
  if (r == NULL)
    /* do_lvs_full has already called reply_with_error */
    goto done;

  guestfs_lvs_full_ret ret;
  char *bufret;
  size_t lenret;
  lvs_full__init (&ret);
  ret.logvols = r;
  lenret = lvs_full__get_packed_size (&ret);
  bufret = malloc (lenret);
  lvs_full__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
aug_init_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_init_args *args;
  const char *root;
  int flags;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_init_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  root = args->root;
  ABS_PATH (root, , goto done);
  flags = args->flags;

  NEED_ROOT (, goto done);
  r = do_aug_init (root, flags);
  if (r == -1)
    /* do_aug_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_close_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_close ();
  if (r == -1)
    /* do_aug_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
aug_defvar_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_defvar_args *args;
  const char *name;
  const char *expr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_defvar_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args->name;
  expr = args->expr ? *args->expr : NULL;

  r = do_aug_defvar (name, expr);
  if (r == -1)
    /* do_aug_defvar has already called reply_with_error */
    goto done;

  guestfs_AugDefvar_ret ret;
  char *bufret;
  size_t lenret;
  aug_defvar__init (&ret);
  ret.nrnodes = r;
  lenret = aug_defvar__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_defvar__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_defnode_stub (char const *data, size_t datalen)
{
  guestfs_int_int_bool *r;
  struct guestfs_aug_defnode_args *args;
  const char *name;
  const char *expr;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_defnode_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args->name;
  expr = args->expr;
  val = args->val;

  r = do_aug_defnode (name, expr, val);
  if (r == NULL)
    /* do_aug_defnode has already called reply_with_error */
    goto done;

  guestfs_aug_defnode_ret ret;
  char *bufret;
  size_t lenret;
  aug_defnode__init (&ret);
  ret.nrnodescreated = r;
  lenret = aug_defnode__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_defnode__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_get_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_aug_get_args *args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_get_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;

  r = do_aug_get (augpath);
  if (r == NULL)
    /* do_aug_get has already called reply_with_error */
    goto done;

  guestfs_AugGet_ret ret;
  char *bufret;
  size_t lenret;
  aug_get__init (&ret);
  ret.val = r;
  lenret = aug_get__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_get__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_set_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_set_args *args;
  const char *augpath;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_set_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;
  val = args->val;

  r = do_aug_set (augpath, val);
  if (r == -1)
    /* do_aug_set has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_insert_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_insert_args *args;
  const char *augpath;
  const char *label;
  int before;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_insert_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;
  label = args->label;
  before = args->before;

  r = do_aug_insert (augpath, label, before);
  if (r == -1)
    /* do_aug_insert has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_rm_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_rm_args *args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_rm_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;

  r = do_aug_rm (augpath);
  if (r == -1)
    /* do_aug_rm has already called reply_with_error */
    goto done;

  guestfs_AugRm_ret ret;
  char *bufret;
  size_t lenret;
  aug_rm__init (&ret);
  ret.nrnodes = r;
  lenret = aug_rm__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_rm__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_mv_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_mv_args *args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_mv_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  dest = args->dest;

  r = do_aug_mv (src, dest);
  if (r == -1)
    /* do_aug_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_match_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_aug_match_args *args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_match_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;

  r = do_aug_match (augpath);
  if (r == NULL)
    /* do_aug_match has already called reply_with_error */
    goto done;

  guestfs_AugMatch_ret ret;
  char *bufret;
  size_t lenret;
  aug_match__init (&ret);
  ret.n_matches = count_strings (r);
  ret.matches = r;
  lenret = aug_match__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_match__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_save_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_save ();
  if (r == -1)
    /* do_aug_save has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
aug_load_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_load ();
  if (r == -1)
    /* do_aug_load has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
aug_ls_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_aug_ls_args *args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_ls_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;

  r = do_aug_ls (augpath);
  if (r == NULL)
    /* do_aug_ls has already called reply_with_error */
    goto done;

  guestfs_AugLs_ret ret;
  char *bufret;
  size_t lenret;
  aug_ls__init (&ret);
  ret.n_matches = count_strings (r);
  ret.matches = r;
  lenret = aug_ls__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_ls__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rm_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rm_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = rm_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm (path);
  if (r == -1)
    /* do_rm has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rmdir_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rmdir_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = rmdir_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rmdir (path);
  if (r == -1)
    /* do_rmdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rm_rf_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rm_rf_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = rm_rf_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm_rf (path);
  if (r == -1)
    /* do_rm_rf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkdir_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkdir_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkdir_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdir (path);
  if (r == -1)
    /* do_mkdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkdir_p_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkdir_p_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkdir_p_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdir_p (path);
  if (r == -1)
    /* do_mkdir_p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
chmod_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_chmod_args *args;
  int mode;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = chmod_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args->mode;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_chmod (mode, path);
  if (r == -1)
    /* do_chmod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
chown_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_chown_args *args;
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = chown_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  owner = args->owner;
  group = args->group;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_chown (owner, group, path);
  if (r == -1)
    /* do_chown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
exists_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_exists_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = exists_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_exists (path);
  if (r == -1)
    /* do_exists has already called reply_with_error */
    goto done;

  guestfs_Exists_ret ret;
  char *bufret;
  size_t lenret;
  exists__init (&ret);
  ret.existsflag = r;
  lenret = exists__get_packed_size (&ret);
  bufret = malloc (lenret);
  exists__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_file_args *args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = is_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  followsymlinks = args->followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_file (path, followsymlinks);
  if (r == -1)
    /* do_is_file has already called reply_with_error */
    goto done;

  guestfs_IsFile_ret ret;
  char *bufret;
  size_t lenret;
  is_file__init (&ret);
  ret.fileflag = r;
  lenret = is_file__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_file__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_dir_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_dir_args *args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = is_dir_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  followsymlinks = args->followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_dir (path, followsymlinks);
  if (r == -1)
    /* do_is_dir has already called reply_with_error */
    goto done;

  guestfs_IsDir_ret ret;
  char *bufret;
  size_t lenret;
  is_dir__init (&ret);
  ret.dirflag = r;
  lenret = is_dir__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_dir__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvcreate_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pvcreate_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pvcreate_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_pvcreate (device);
  if (r == -1)
    /* do_pvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgcreate_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_vgcreate_args *args;
  const char *volgroup;
  CLEANUP_FREE_STRING_LIST char **physvols = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vgcreate_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  volgroup = args->volgroup;
  /* Copy the string list and apply device name translation
   * to each one.
   */
  physvols = calloc (args->n_physvols+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_physvols; ++i)
      RESOLVE_DEVICE (args->physvols[i], physvols[i],
                      , goto done);
    physvols[i] = NULL;
  }

  r = do_vgcreate (volgroup, physvols);
  if (r == -1)
    /* do_vgcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvcreate_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvcreate_args *args;
  const char *logvol;
  const char *volgroup;
  int mbytes;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvcreate_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args->logvol;
  volgroup = args->volgroup;
  mbytes = args->mbytes;

  r = do_lvcreate (logvol, volgroup, mbytes);
  if (r == -1)
    /* do_lvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sfdisk_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_sfdisk_args *args;
  CLEANUP_FREE char *device = NULL;
  int cyls;
  int heads;
  int sectors;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sfdisk_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  cyls = args->cyls;
  heads = args->heads;
  sectors = args->sectors;
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args->lines,
                sizeof (char *) * (args->n_lines+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  lines[args->n_lines] = NULL;
  args->lines = lines;

  r = do_sfdisk (device, cyls, heads, sectors, lines);
  if (r == -1)
    /* do_sfdisk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
write_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_write_file_args *args;
  const char *path;
  const char *content;
  int size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = write_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  content = args->content;
  size = args->size;

  NEED_ROOT (, goto done);
  r = do_write_file (path, content, size);
  if (r == -1)
    /* do_write_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
umount_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_umount_args *args;
  CLEANUP_FREE char *pathordevice = NULL;
  int force;
  int lazyunmount;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = umount_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->pathordevice, pathordevice, , goto done);
  force = args->force;
  lazyunmount = args->lazyunmount;

  r = do_umount (pathordevice, force, lazyunmount);
  if (r == -1)
    /* do_umount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mounts_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_mounts ();
  if (r == NULL)
    /* do_mounts has already called reply_with_error */
    goto done;

  guestfs_Mounts_ret ret;
  char *bufret;
  size_t lenret;
  mounts__init (&ret);
  ret.n_devices = count_strings (r);
  ret.devices = r;
  lenret = mounts__get_packed_size (&ret);
  bufret = malloc (lenret);
  mounts__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
umount_all_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_umount_all ();
  if (r == -1)
    /* do_umount_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
lvm_remove_all_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvm_remove_all ();
  if (r == -1)
    /* do_lvm_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
file_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_file_args *args;
  CLEANUP_FREE char *path = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->path, path, , goto done);

  r = do_file (path);
  if (r == NULL)
    /* do_file has already called reply_with_error */
    goto done;

  guestfs_File_ret ret;
  char *bufret;
  size_t lenret;
  file__init (&ret);
  ret.description = r;
  lenret = file__get_packed_size (&ret);
  bufret = malloc (lenret);
  file__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
command_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_command_args *args;
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = command_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  arguments = realloc (args->arguments,
                sizeof (char *) * (args->n_arguments+1));
  if (arguments == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  arguments[args->n_arguments] = NULL;
  args->arguments = arguments;

  r = do_command (arguments);
  if (r == NULL)
    /* do_command has already called reply_with_error */
    goto done;

  guestfs_Command_ret ret;
  char *bufret;
  size_t lenret;
  command__init (&ret);
  ret.output = r;
  lenret = command__get_packed_size (&ret);
  bufret = malloc (lenret);
  command__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
command_lines_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_command_lines_args *args;
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = command_lines_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  arguments = realloc (args->arguments,
                sizeof (char *) * (args->n_arguments+1));
  if (arguments == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  arguments[args->n_arguments] = NULL;
  args->arguments = arguments;

  r = do_command_lines (arguments);
  if (r == NULL)
    /* do_command_lines has already called reply_with_error */
    goto done;

  guestfs_CommandLines_ret ret;
  char *bufret;
  size_t lenret;
  command_lines__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = command_lines__get_packed_size (&ret);
  bufret = malloc (lenret);
  command_lines__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
statvfs_stub (char const *data, size_t datalen)
{
  guestfs_int_statvfs *r;
  struct guestfs_statvfs_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = statvfs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_statvfs (path);
  if (r == NULL)
    /* do_statvfs has already called reply_with_error */
    goto done;

  guestfs_statvfs_ret ret;
  char *bufret;
  size_t lenret;
  statvfs__init (&ret);
  ret.statbuf = r;
  lenret = statvfs__get_packed_size (&ret);
  bufret = malloc (lenret);
  statvfs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tune2fs_l_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_tune2fs_l_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = tune2fs_l_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_tune2fs_l (device);
  if (r == NULL)
    /* do_tune2fs_l has already called reply_with_error */
    goto done;

  guestfs_Tune2fsL_ret ret;
  char *bufret;
  size_t lenret;
  tune2fs_l__init (&ret);
  ret.n_superblock = count_strings (r);
  ret.superblock = r;
  lenret = tune2fs_l__get_packed_size (&ret);
  bufret = malloc (lenret);
  tune2fs_l__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_setro_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_setro_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_setro_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_setro (device);
  if (r == -1)
    /* do_blockdev_setro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_setrw_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_setrw_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_setrw_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_setrw (device);
  if (r == -1)
    /* do_blockdev_setrw has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_getro_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_getro_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_getro_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_getro (device);
  if (r == -1)
    /* do_blockdev_getro has already called reply_with_error */
    goto done;

  guestfs_BlockdevGetro_ret ret;
  char *bufret;
  size_t lenret;
  blockdev_getro__init (&ret);
  ret.ro = r;
  lenret = blockdev_getro__get_packed_size (&ret);
  bufret = malloc (lenret);
  blockdev_getro__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_getss_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_getss_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_getss_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_getss (device);
  if (r == -1)
    /* do_blockdev_getss has already called reply_with_error */
    goto done;

  guestfs_BlockdevGetss_ret ret;
  char *bufret;
  size_t lenret;
  blockdev_getss__init (&ret);
  ret.sectorsize = r;
  lenret = blockdev_getss__get_packed_size (&ret);
  bufret = malloc (lenret);
  blockdev_getss__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_getbsz_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_getbsz_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_getbsz_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_getbsz (device);
  if (r == -1)
    /* do_blockdev_getbsz has already called reply_with_error */
    goto done;

  guestfs_BlockdevGetbsz_ret ret;
  char *bufret;
  size_t lenret;
  blockdev_getbsz__init (&ret);
  ret.blocksize = r;
  lenret = blockdev_getbsz__get_packed_size (&ret);
  bufret = malloc (lenret);
  blockdev_getbsz__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_setbsz_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_setbsz_args *args;
  CLEANUP_FREE char *device = NULL;
  int blocksize;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_setbsz_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  blocksize = args->blocksize;

  r = do_blockdev_setbsz (device, blocksize);
  if (r == -1)
    /* do_blockdev_setbsz has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_getsz_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_blockdev_getsz_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_getsz_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_getsz (device);
  if (r == -1)
    /* do_blockdev_getsz has already called reply_with_error */
    goto done;

  guestfs_BlockdevGetsz_ret ret;
  char *bufret;
  size_t lenret;
  blockdev_getsz__init (&ret);
  ret.sizeinsectors = r;
  lenret = blockdev_getsz__get_packed_size (&ret);
  bufret = malloc (lenret);
  blockdev_getsz__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_getsize64_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_blockdev_getsize64_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_getsize64_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_getsize64 (device);
  if (r == -1)
    /* do_blockdev_getsize64 has already called reply_with_error */
    goto done;

  guestfs_BlockdevGetsize64_ret ret;
  char *bufret;
  size_t lenret;
  blockdev_getsize64__init (&ret);
  ret.sizeinbytes = r;
  lenret = blockdev_getsize64__get_packed_size (&ret);
  bufret = malloc (lenret);
  blockdev_getsize64__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_flushbufs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_flushbufs_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_flushbufs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_flushbufs (device);
  if (r == -1)
    /* do_blockdev_flushbufs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blockdev_rereadpt_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blockdev_rereadpt_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blockdev_rereadpt_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blockdev_rereadpt (device);
  if (r == -1)
    /* do_blockdev_rereadpt has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
upload_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_upload_args *args;
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = upload_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->remotefilename, remotefilename, cancel_receive (), goto done);

  r = do_upload (remotefilename);
  if (r == -1)
    /* do_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
download_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_download_args *args;
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = download_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->remotefilename, remotefilename, , goto done);

  r = do_download (remotefilename);
  if (r == -1)
    /* do_download has already called reply_with_error */
    goto done;

  /* do_download has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
checksum_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_checksum_args *args;
  const char *csumtype;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = checksum_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args->csumtype;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_checksum (csumtype, path);
  if (r == NULL)
    /* do_checksum has already called reply_with_error */
    goto done;

  guestfs_Checksum_ret ret;
  char *bufret;
  size_t lenret;
  checksum__init (&ret);
  ret.checksum = r;
  lenret = checksum__get_packed_size (&ret);
  bufret = malloc (lenret);
  checksum__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tar_in_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_tar_in_args *args;
  const char *directory;
  const char *compress;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    cancel_receive ();
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = tar_in_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, cancel_receive (), goto done);
  compress = args->compress;

  NEED_ROOT (cancel_receive (), goto done);
  r = do_tar_in (directory, compress);
  if (r == -1)
    /* do_tar_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tar_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_tar_out_args *args;
  const char *directory;
  const char *compress;
  int numericowner;
  char **excludes;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = tar_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  compress = args->compress;
  numericowner = args->numericowner;
  /* Ugly, but safe and avoids copying the strings. */
  excludes = realloc (args->excludes,
                sizeof (char *) * (args->n_excludes+1));
  if (excludes == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  excludes[args->n_excludes] = NULL;
  args->excludes = excludes;

  r = do_tar_out (directory, compress, numericowner, excludes);
  if (r == -1)
    /* do_tar_out has already called reply_with_error */
    goto done;

  /* do_tar_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
tgz_in_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_tgz_in_args *args;
  const char *directory;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = tgz_in_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_tgz_in (directory);
  if (r == -1)
    /* do_tgz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tgz_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_tgz_out_args *args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = tgz_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_tgz_out (directory);
  if (r == -1)
    /* do_tgz_out has already called reply_with_error */
    goto done;

  /* do_tgz_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
mount_ro_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mount_ro_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mount_ro_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);
  mountpoint = args->mountpoint;

  r = do_mount_ro (&mountable, mountpoint);
  if (r == -1)
    /* do_mount_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mount_options_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mount_options_args *args;
  const char *options;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mount_options_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  options = args->options;
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);
  mountpoint = args->mountpoint;

  r = do_mount_options (options, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_options has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mount_vfs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mount_vfs_args *args;
  const char *options;
  const char *vfstype;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mount_vfs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  options = args->options;
  vfstype = args->vfstype;
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);
  mountpoint = args->mountpoint;

  r = do_mount_vfs (options, vfstype, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_vfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
debug_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_debug_args *args;
  const char *subcmd;
  char **extraargs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = debug_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subcmd = args->subcmd;
  /* Ugly, but safe and avoids copying the strings. */
  extraargs = realloc (args->extraargs,
                sizeof (char *) * (args->n_extraargs+1));
  if (extraargs == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  extraargs[args->n_extraargs] = NULL;
  args->extraargs = extraargs;

  r = do_debug (subcmd, extraargs);
  if (r == NULL)
    /* do_debug has already called reply_with_error */
    goto done;

  guestfs_Debug_ret ret;
  char *bufret;
  size_t lenret;
  debug__init (&ret);
  ret.result = r;
  lenret = debug__get_packed_size (&ret);
  bufret = malloc (lenret);
  debug__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvremove_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvremove_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvremove_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_lvremove (device);
  if (r == -1)
    /* do_lvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgremove_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_vgremove_args *args;
  const char *vgname;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vgremove_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args->vgname;

  r = do_vgremove (vgname);
  if (r == -1)
    /* do_vgremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvremove_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pvremove_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pvremove_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_pvremove (device);
  if (r == -1)
    /* do_pvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
set_e2label_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_set_e2label_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = set_e2label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  label = args->label;

  r = do_set_e2label (device, label);
  if (r == -1)
    /* do_set_e2label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
get_e2label_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_get_e2label_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = get_e2label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_get_e2label (device);
  if (r == NULL)
    /* do_get_e2label has already called reply_with_error */
    goto done;

  guestfs_GetE2label_ret ret;
  char *bufret;
  size_t lenret;
  get_e2label__init (&ret);
  ret.label = r;
  lenret = get_e2label__get_packed_size (&ret);
  bufret = malloc (lenret);
  get_e2label__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
set_e2uuid_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_set_e2uuid_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = set_e2uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  uuid = args->uuid;

  r = do_set_e2uuid (device, uuid);
  if (r == -1)
    /* do_set_e2uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
get_e2uuid_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_get_e2uuid_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = get_e2uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_get_e2uuid (device);
  if (r == NULL)
    /* do_get_e2uuid has already called reply_with_error */
    goto done;

  guestfs_GetE2uuid_ret ret;
  char *bufret;
  size_t lenret;
  get_e2uuid__init (&ret);
  ret.uuid = r;
  lenret = get_e2uuid__get_packed_size (&ret);
  bufret = malloc (lenret);
  get_e2uuid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
fsck_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fsck_args *args;
  const char *fstype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fsck_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args->fstype;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_fsck (fstype, device);
  if (r == -1)
    /* do_fsck has already called reply_with_error */
    goto done;

  guestfs_Fsck_ret ret;
  char *bufret;
  size_t lenret;
  fsck__init (&ret);
  ret.status = r;
  lenret = fsck__get_packed_size (&ret);
  bufret = malloc (lenret);
  fsck__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zero_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_zero_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zero_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_zero (device);
  if (r == -1)
    /* do_zero has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
grub_install_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_grub_install_args *args;
  const char *root;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_grub_available ()) {
    reply_with_unavailable_feature ("grub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = grub_install_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  root = args->root;
  ABS_PATH (root, , goto done);
  RESOLVE_DEVICE (args->device, device, , goto done);

  NEED_ROOT (, goto done);
  r = do_grub_install (root, device);
  if (r == -1)
    /* do_grub_install has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
cp_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_cp_args *args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = cp_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp (src, dest);
  if (r == -1)
    /* do_cp has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
cp_a_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_cp_a_args *args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = cp_a_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp_a (src, dest);
  if (r == -1)
    /* do_cp_a has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mv_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mv_args *args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mv_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_mv (src, dest);
  if (r == -1)
    /* do_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
drop_caches_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_drop_caches_args *args;
  int whattodrop;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = drop_caches_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  whattodrop = args->whattodrop;

  r = do_drop_caches (whattodrop);
  if (r == -1)
    /* do_drop_caches has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
dmesg_stub (char const *data, size_t datalen)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_dmesg ();
  if (r == NULL)
    /* do_dmesg has already called reply_with_error */
    goto done;

  guestfs_Dmesg_ret ret;
  char *bufret;
  size_t lenret;
  dmesg__init (&ret);
  ret.kmsgs = r;
  lenret = dmesg__get_packed_size (&ret);
  bufret = malloc (lenret);
  dmesg__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
ping_daemon_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ping_daemon ();
  if (r == -1)
    /* do_ping_daemon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
equal_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_equal_args *args;
  const char *file1;
  const char *file2;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = equal_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file1 = args->file1;
  ABS_PATH (file1, , goto done);
  file2 = args->file2;
  ABS_PATH (file2, , goto done);

  NEED_ROOT (, goto done);
  r = do_equal (file1, file2);
  if (r == -1)
    /* do_equal has already called reply_with_error */
    goto done;

  guestfs_Equal_ret ret;
  char *bufret;
  size_t lenret;
  equal__init (&ret);
  ret.equality = r;
  lenret = equal__get_packed_size (&ret);
  bufret = malloc (lenret);
  equal__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
strings_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_strings_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = strings_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_strings (path);
  if (r == NULL)
    /* do_strings has already called reply_with_error */
    goto done;

  guestfs_Strings_ret ret;
  char *bufret;
  size_t lenret;
  strings__init (&ret);
  ret.n_stringsout = count_strings (r);
  ret.stringsout = r;
  lenret = strings__get_packed_size (&ret);
  bufret = malloc (lenret);
  strings__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
strings_e_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_strings_e_args *args;
  const char *encoding;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = strings_e_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  encoding = args->encoding;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_strings_e (encoding, path);
  if (r == NULL)
    /* do_strings_e has already called reply_with_error */
    goto done;

  guestfs_StringsE_ret ret;
  char *bufret;
  size_t lenret;
  strings_e__init (&ret);
  ret.n_stringsout = count_strings (r);
  ret.stringsout = r;
  lenret = strings_e__get_packed_size (&ret);
  bufret = malloc (lenret);
  strings_e__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hexdump_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_hexdump_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hexdump_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_hexdump (path);
  if (r == NULL)
    /* do_hexdump has already called reply_with_error */
    goto done;

  guestfs_Hexdump_ret ret;
  char *bufret;
  size_t lenret;
  hexdump__init (&ret);
  ret.dump = r;
  lenret = hexdump__get_packed_size (&ret);
  bufret = malloc (lenret);
  hexdump__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zerofree_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_zerofree_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_zerofree_available ()) {
    reply_with_unavailable_feature ("zerofree");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zerofree_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_zerofree (device);
  if (r == -1)
    /* do_zerofree has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvresize_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pvresize_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pvresize_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_pvresize (device);
  if (r == -1)
    /* do_pvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sfdisk_N_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_sfdisk_N_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sfdisk_N_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;
  cyls = args->cyls;
  heads = args->heads;
  sectors = args->sectors;
  line = args->line;

  r = do_sfdisk_N (device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    /* do_sfdisk_N has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sfdisk_l_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_sfdisk_l_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sfdisk_l_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_sfdisk_l (device);
  if (r == NULL)
    /* do_sfdisk_l has already called reply_with_error */
    goto done;

  guestfs_SfdiskL_ret ret;
  char *bufret;
  size_t lenret;
  sfdisk_l__init (&ret);
  ret.partitions = r;
  lenret = sfdisk_l__get_packed_size (&ret);
  bufret = malloc (lenret);
  sfdisk_l__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sfdisk_kernel_geometry_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_sfdisk_kernel_geometry_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sfdisk_kernel_geometry_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_sfdisk_kernel_geometry (device);
  if (r == NULL)
    /* do_sfdisk_kernel_geometry has already called reply_with_error */
    goto done;

  guestfs_SfdiskKernelGeometry_ret ret;
  char *bufret;
  size_t lenret;
  sfdisk_kernel_geometry__init (&ret);
  ret.partitions = r;
  lenret = sfdisk_kernel_geometry__get_packed_size (&ret);
  bufret = malloc (lenret);
  sfdisk_kernel_geometry__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sfdisk_disk_geometry_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_sfdisk_disk_geometry_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sfdisk_disk_geometry_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_sfdisk_disk_geometry (device);
  if (r == NULL)
    /* do_sfdisk_disk_geometry has already called reply_with_error */
    goto done;

  guestfs_SfdiskDiskGeometry_ret ret;
  char *bufret;
  size_t lenret;
  sfdisk_disk_geometry__init (&ret);
  ret.partitions = r;
  lenret = sfdisk_disk_geometry__get_packed_size (&ret);
  bufret = malloc (lenret);
  sfdisk_disk_geometry__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vg_activate_all_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_vg_activate_all_args *args;
  int activate;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vg_activate_all_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  activate = args->activate;

  r = do_vg_activate_all (activate);
  if (r == -1)
    /* do_vg_activate_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vg_activate_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_vg_activate_args *args;
  int activate;
  char **volgroups;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vg_activate_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  activate = args->activate;
  /* Ugly, but safe and avoids copying the strings. */
  volgroups = realloc (args->volgroups,
                sizeof (char *) * (args->n_volgroups+1));
  if (volgroups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  volgroups[args->n_volgroups] = NULL;
  args->volgroups = volgroups;

  r = do_vg_activate (activate, volgroups);
  if (r == -1)
    /* do_vg_activate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvresize_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvresize_args *args;
  CLEANUP_FREE char *device = NULL;
  int mbytes;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvresize_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  mbytes = args->mbytes;

  r = do_lvresize (device, mbytes);
  if (r == -1)
    /* do_lvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
resize2fs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_resize2fs_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = resize2fs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_resize2fs (device);
  if (r == -1)
    /* do_resize2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
e2fsck_f_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_e2fsck_f_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = e2fsck_f_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_e2fsck_f (device);
  if (r == -1)
    /* do_e2fsck_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sleep_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_sleep_args *args;
  int secs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sleep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  secs = args->secs;

  r = do_sleep (secs);
  if (r == -1)
    /* do_sleep has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ntfs_3g_probe_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ntfs_3g_probe_args *args;
  int rw;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ntfs_3g_probe_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  rw = args->rw;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_ntfs_3g_probe (rw, device);
  if (r == -1)
    /* do_ntfs_3g_probe has already called reply_with_error */
    goto done;

  guestfs_Ntfs3gProbe_ret ret;
  char *bufret;
  size_t lenret;
  ntfs_3g_probe__init (&ret);
  ret.status = r;
  lenret = ntfs_3g_probe__get_packed_size (&ret);
  bufret = malloc (lenret);
  ntfs_3g_probe__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sh_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_sh_args *args;
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sh_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  command = args->command;

  r = do_sh (command);
  if (r == NULL)
    /* do_sh has already called reply_with_error */
    goto done;

  guestfs_Sh_ret ret;
  char *bufret;
  size_t lenret;
  sh__init (&ret);
  ret.output = r;
  lenret = sh__get_packed_size (&ret);
  bufret = malloc (lenret);
  sh__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sh_lines_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_sh_lines_args *args;
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sh_lines_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  command = args->command;

  r = do_sh_lines (command);
  if (r == NULL)
    /* do_sh_lines has already called reply_with_error */
    goto done;

  guestfs_ShLines_ret ret;
  char *bufret;
  size_t lenret;
  sh_lines__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = sh_lines__get_packed_size (&ret);
  bufret = malloc (lenret);
  sh_lines__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
glob_expand_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_glob_expand_args *args;
  const char *pattern;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = glob_expand_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args->pattern;
  ABS_PATH (pattern, , goto done);

  NEED_ROOT (, goto done);
  r = do_glob_expand (pattern);
  if (r == NULL)
    /* do_glob_expand has already called reply_with_error */
    goto done;

  guestfs_GlobExpand_ret ret;
  char *bufret;
  size_t lenret;
  glob_expand__init (&ret);
  ret.n_paths = count_strings (r);
  ret.paths = r;
  lenret = glob_expand__get_packed_size (&ret);
  bufret = malloc (lenret);
  glob_expand__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
scrub_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_scrub_device_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = scrub_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_scrub_device (device);
  if (r == -1)
    /* do_scrub_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
scrub_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_scrub_file_args *args;
  const char *file;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = scrub_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_scrub_file (file);
  if (r == -1)
    /* do_scrub_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
scrub_freespace_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_scrub_freespace_args *args;
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = scrub_freespace_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args->dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_scrub_freespace (dir);
  if (r == -1)
    /* do_scrub_freespace has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkdtemp_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_mkdtemp_args *args;
  const char *tmpl;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkdtemp_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpl = args->tmpl;
  ABS_PATH (tmpl, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdtemp (tmpl);
  if (r == NULL)
    /* do_mkdtemp has already called reply_with_error */
    goto done;

  guestfs_Mkdtemp_ret ret;
  char *bufret;
  size_t lenret;
  mkdtemp__init (&ret);
  ret.dir = r;
  lenret = mkdtemp__get_packed_size (&ret);
  bufret = malloc (lenret);
  mkdtemp__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
wc_l_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_wc_l_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = wc_l_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_l (path);
  if (r == -1)
    /* do_wc_l has already called reply_with_error */
    goto done;

  guestfs_WcL_ret ret;
  char *bufret;
  size_t lenret;
  wc_l__init (&ret);
  ret.lines = r;
  lenret = wc_l__get_packed_size (&ret);
  bufret = malloc (lenret);
  wc_l__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
wc_w_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_wc_w_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = wc_w_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_w (path);
  if (r == -1)
    /* do_wc_w has already called reply_with_error */
    goto done;

  guestfs_WcW_ret ret;
  char *bufret;
  size_t lenret;
  wc_w__init (&ret);
  ret.words = r;
  lenret = wc_w__get_packed_size (&ret);
  bufret = malloc (lenret);
  wc_w__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
wc_c_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_wc_c_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = wc_c_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_c (path);
  if (r == -1)
    /* do_wc_c has already called reply_with_error */
    goto done;

  guestfs_WcC_ret ret;
  char *bufret;
  size_t lenret;
  wc_c__init (&ret);
  ret.chars = r;
  lenret = wc_c__get_packed_size (&ret);
  bufret = malloc (lenret);
  wc_c__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
head_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_head_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = head_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_head (path);
  if (r == NULL)
    /* do_head has already called reply_with_error */
    goto done;

  guestfs_Head_ret ret;
  char *bufret;
  size_t lenret;
  head__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = head__get_packed_size (&ret);
  bufret = malloc (lenret);
  head__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
head_n_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_head_n_args *args;
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = head_n_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nrlines = args->nrlines;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_head_n (nrlines, path);
  if (r == NULL)
    /* do_head_n has already called reply_with_error */
    goto done;

  guestfs_HeadN_ret ret;
  char *bufret;
  size_t lenret;
  head_n__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = head_n__get_packed_size (&ret);
  bufret = malloc (lenret);
  head_n__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tail_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_tail_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = tail_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_tail (path);
  if (r == NULL)
    /* do_tail has already called reply_with_error */
    goto done;

  guestfs_Tail_ret ret;
  char *bufret;
  size_t lenret;
  tail__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = tail__get_packed_size (&ret);
  bufret = malloc (lenret);
  tail__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tail_n_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_tail_n_args *args;
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = tail_n_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nrlines = args->nrlines;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_tail_n (nrlines, path);
  if (r == NULL)
    /* do_tail_n has already called reply_with_error */
    goto done;

  guestfs_TailN_ret ret;
  char *bufret;
  size_t lenret;
  tail_n__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = tail_n__get_packed_size (&ret);
  bufret = malloc (lenret);
  tail_n__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
df_stub (char const *data, size_t datalen)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_df ();
  if (r == NULL)
    /* do_df has already called reply_with_error */
    goto done;

  guestfs_Df_ret ret;
  char *bufret;
  size_t lenret;
  df__init (&ret);
  ret.output = r;
  lenret = df__get_packed_size (&ret);
  bufret = malloc (lenret);
  df__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
df_h_stub (char const *data, size_t datalen)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_df_h ();
  if (r == NULL)
    /* do_df_h has already called reply_with_error */
    goto done;

  guestfs_DfH_ret ret;
  char *bufret;
  size_t lenret;
  df_h__init (&ret);
  ret.output = r;
  lenret = df_h__get_packed_size (&ret);
  bufret = malloc (lenret);
  df_h__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
du_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_du_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = du_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_du (path);
  if (r == -1)
    /* do_du has already called reply_with_error */
    goto done;

  guestfs_Du_ret ret;
  char *bufret;
  size_t lenret;
  du__init (&ret);
  ret.sizekb = r;
  lenret = du__get_packed_size (&ret);
  bufret = malloc (lenret);
  du__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
initrd_list_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_initrd_list_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = initrd_list_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_initrd_list (path);
  if (r == NULL)
    /* do_initrd_list has already called reply_with_error */
    goto done;

  guestfs_InitrdList_ret ret;
  char *bufret;
  size_t lenret;
  initrd_list__init (&ret);
  ret.n_filenames = count_strings (r);
  ret.filenames = r;
  lenret = initrd_list__get_packed_size (&ret);
  bufret = malloc (lenret);
  initrd_list__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mount_loop_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mount_loop_args *args;
  const char *file;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mount_loop_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);
  mountpoint = args->mountpoint;
  ABS_PATH (mountpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_mount_loop (file, mountpoint);
  if (r == -1)
    /* do_mount_loop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkswap_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkswap_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *label;
  const char *uuid;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = mkswap_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  label = args->label;
  uuid = args->uuid;

  r = do_mkswap (device, label, uuid);
  if (r == -1)
    /* do_mkswap has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkswap_L_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkswap_L_args *args;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkswap_L_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_mkswap_L (label, device);
  if (r == -1)
    /* do_mkswap_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkswap_U_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkswap_U_args *args;
  const char *uuid;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkswap_U_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args->uuid;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_mkswap_U (uuid, device);
  if (r == -1)
    /* do_mkswap_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mknod_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mknod_args *args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mknod_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args->mode;
  devmajor = args->devmajor;
  devminor = args->devminor;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkfifo_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkfifo_args *args;
  int mode;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkfifo_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args->mode;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkfifo (mode, path);
  if (r == -1)
    /* do_mkfifo has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mknod_b_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mknod_b_args *args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mknod_b_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args->mode;
  devmajor = args->devmajor;
  devminor = args->devminor;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod_b (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mknod_c_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mknod_c_args *args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mknod_c_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args->mode;
  devmajor = args->devmajor;
  devminor = args->devminor;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod_c (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_c has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
umask_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_umask_args *args;
  int mask;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = umask_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mask = args->mask;

  r = do_umask (mask);
  if (r == -1)
    /* do_umask has already called reply_with_error */
    goto done;

  guestfs_Umask_ret ret;
  char *bufret;
  size_t lenret;
  umask__init (&ret);
  ret.oldmask = r;
  lenret = umask__get_packed_size (&ret);
  bufret = malloc (lenret);
  umask__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
readdir_stub (char const *data, size_t datalen)
{
  guestfs_int_dirent_list *r;
  struct guestfs_readdir_args *args;
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = readdir_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args->dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_readdir (dir);
  if (r == NULL)
    /* do_readdir has already called reply_with_error */
    goto done;

  guestfs_readdir_ret ret;
  char *bufret;
  size_t lenret;
  readdir__init (&ret);
  ret.entries = r;
  lenret = readdir__get_packed_size (&ret);
  bufret = malloc (lenret);
  readdir__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
sfdiskM_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_sfdiskM_args *args;
  CLEANUP_FREE char *device = NULL;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = sfdiskM_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args->lines,
                sizeof (char *) * (args->n_lines+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  lines[args->n_lines] = NULL;
  args->lines = lines;

  r = do_sfdiskM (device, lines);
  if (r == -1)
    /* do_sfdiskM has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zfile_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_zfile_args *args;
  const char *meth;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zfile_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  meth = args->meth;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfile (meth, path);
  if (r == NULL)
    /* do_zfile has already called reply_with_error */
    goto done;

  guestfs_Zfile_ret ret;
  char *bufret;
  size_t lenret;
  zfile__init (&ret);
  ret.description = r;
  lenret = zfile__get_packed_size (&ret);
  bufret = malloc (lenret);
  zfile__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
getxattrs_stub (char const *data, size_t datalen)
{
  guestfs_int_xattr_list *r;
  struct guestfs_getxattrs_args *args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = getxattrs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_getxattrs (path);
  if (r == NULL)
    /* do_getxattrs has already called reply_with_error */
    goto done;

  guestfs_getxattrs_ret ret;
  char *bufret;
  size_t lenret;
  getxattrs__init (&ret);
  ret.xattrs = r;
  lenret = getxattrs__get_packed_size (&ret);
  bufret = malloc (lenret);
  getxattrs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lgetxattrs_stub (char const *data, size_t datalen)
{
  guestfs_int_xattr_list *r;
  struct guestfs_lgetxattrs_args *args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lgetxattrs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lgetxattrs (path);
  if (r == NULL)
    /* do_lgetxattrs has already called reply_with_error */
    goto done;

  guestfs_lgetxattrs_ret ret;
  char *bufret;
  size_t lenret;
  lgetxattrs__init (&ret);
  ret.xattrs = r;
  lenret = lgetxattrs__get_packed_size (&ret);
  bufret = malloc (lenret);
  lgetxattrs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
setxattr_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_setxattr_args *args;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = setxattr_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args->xattr;
  val = args->val;
  vallen = args->vallen;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_setxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_setxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lsetxattr_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lsetxattr_args *args;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lsetxattr_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args->xattr;
  val = args->val;
  vallen = args->vallen;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lsetxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_lsetxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
removexattr_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_removexattr_args *args;
  const char *xattr;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = removexattr_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args->xattr;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_removexattr (xattr, path);
  if (r == -1)
    /* do_removexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lremovexattr_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lremovexattr_args *args;
  const char *xattr;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lremovexattr_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args->xattr;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lremovexattr (xattr, path);
  if (r == -1)
    /* do_lremovexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mountpoints_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_mountpoints ();
  if (r == NULL)
    /* do_mountpoints has already called reply_with_error */
    goto done;

  guestfs_Mountpoints_ret ret;
  char *bufret;
  size_t lenret;
  mountpoints__init (&ret);
  ret.n_mps = count_strings (r);
  ret.mps = r;
  lenret = mountpoints__get_packed_size (&ret);
  bufret = malloc (lenret);
  mountpoints__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
mkmountpoint_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkmountpoint_args *args;
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkmountpoint_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  exemptpath = args->exemptpath;

  r = do_mkmountpoint (exemptpath);
  if (r == -1)
    /* do_mkmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rmmountpoint_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rmmountpoint_args *args;
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = rmmountpoint_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  exemptpath = args->exemptpath;

  r = do_rmmountpoint (exemptpath);
  if (r == -1)
    /* do_rmmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
grep_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_grep_args *args;
  const char *regex;
  const char *path;
  int extended;
  int fixed;
  int insensitive;
  int compressed;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = grep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);
  extended = args->extended;
  fixed = args->fixed;
  insensitive = args->insensitive;
  compressed = args->compressed;

  NEED_ROOT (, goto done);
  r = do_grep (regex, path, extended, fixed, insensitive, compressed);
  if (r == NULL)
    /* do_grep has already called reply_with_error */
    goto done;

  guestfs_Grep_ret ret;
  char *bufret;
  size_t lenret;
  grep__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = grep__get_packed_size (&ret);
  bufret = malloc (lenret);
  grep__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
egrep_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_egrep_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = egrep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_egrep (regex, path);
  if (r == NULL)
    /* do_egrep has already called reply_with_error */
    goto done;

  guestfs_Egrep_ret ret;
  char *bufret;
  size_t lenret;
  egrep__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = egrep__get_packed_size (&ret);
  bufret = malloc (lenret);
  egrep__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
fgrep_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_fgrep_args *args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fgrep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args->pattern;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fgrep (pattern, path);
  if (r == NULL)
    /* do_fgrep has already called reply_with_error */
    goto done;

  guestfs_Fgrep_ret ret;
  char *bufret;
  size_t lenret;
  fgrep__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = fgrep__get_packed_size (&ret);
  bufret = malloc (lenret);
  fgrep__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
grepi_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_grepi_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = grepi_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_grepi (regex, path);
  if (r == NULL)
    /* do_grepi has already called reply_with_error */
    goto done;

  guestfs_Grepi_ret ret;
  char *bufret;
  size_t lenret;
  grepi__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = grepi__get_packed_size (&ret);
  bufret = malloc (lenret);
  grepi__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
egrepi_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_egrepi_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = egrepi_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_egrepi (regex, path);
  if (r == NULL)
    /* do_egrepi has already called reply_with_error */
    goto done;

  guestfs_Egrepi_ret ret;
  char *bufret;
  size_t lenret;
  egrepi__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = egrepi__get_packed_size (&ret);
  bufret = malloc (lenret);
  egrepi__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
fgrepi_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_fgrepi_args *args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fgrepi_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args->pattern;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fgrepi (pattern, path);
  if (r == NULL)
    /* do_fgrepi has already called reply_with_error */
    goto done;

  guestfs_Fgrepi_ret ret;
  char *bufret;
  size_t lenret;
  fgrepi__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = fgrepi__get_packed_size (&ret);
  bufret = malloc (lenret);
  fgrepi__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zgrep_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_zgrep_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zgrep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zgrep (regex, path);
  if (r == NULL)
    /* do_zgrep has already called reply_with_error */
    goto done;

  guestfs_Zgrep_ret ret;
  char *bufret;
  size_t lenret;
  zgrep__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = zgrep__get_packed_size (&ret);
  bufret = malloc (lenret);
  zgrep__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zegrep_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_zegrep_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zegrep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zegrep (regex, path);
  if (r == NULL)
    /* do_zegrep has already called reply_with_error */
    goto done;

  guestfs_Zegrep_ret ret;
  char *bufret;
  size_t lenret;
  zegrep__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = zegrep__get_packed_size (&ret);
  bufret = malloc (lenret);
  zegrep__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zfgrep_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_zfgrep_args *args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zfgrep_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args->pattern;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfgrep (pattern, path);
  if (r == NULL)
    /* do_zfgrep has already called reply_with_error */
    goto done;

  guestfs_Zfgrep_ret ret;
  char *bufret;
  size_t lenret;
  zfgrep__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = zfgrep__get_packed_size (&ret);
  bufret = malloc (lenret);
  zfgrep__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zgrepi_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_zgrepi_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zgrepi_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zgrepi (regex, path);
  if (r == NULL)
    /* do_zgrepi has already called reply_with_error */
    goto done;

  guestfs_Zgrepi_ret ret;
  char *bufret;
  size_t lenret;
  zgrepi__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = zgrepi__get_packed_size (&ret);
  bufret = malloc (lenret);
  zgrepi__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zegrepi_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_zegrepi_args *args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zegrepi_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args->regex;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zegrepi (regex, path);
  if (r == NULL)
    /* do_zegrepi has already called reply_with_error */
    goto done;

  guestfs_Zegrepi_ret ret;
  char *bufret;
  size_t lenret;
  zegrepi__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = zegrepi__get_packed_size (&ret);
  bufret = malloc (lenret);
  zegrepi__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zfgrepi_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_zfgrepi_args *args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zfgrepi_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args->pattern;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfgrepi (pattern, path);
  if (r == NULL)
    /* do_zfgrepi has already called reply_with_error */
    goto done;

  guestfs_Zfgrepi_ret ret;
  char *bufret;
  size_t lenret;
  zfgrepi__init (&ret);
  ret.n_lines = count_strings (r);
  ret.lines = r;
  lenret = zfgrepi__get_packed_size (&ret);
  bufret = malloc (lenret);
  zfgrepi__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
realpath_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_realpath_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = realpath_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_realpath (path);
  if (r == NULL)
    /* do_realpath has already called reply_with_error */
    goto done;

  guestfs_Realpath_ret ret;
  char *bufret;
  size_t lenret;
  realpath__init (&ret);
  ret.rpath = r;
  lenret = realpath__get_packed_size (&ret);
  bufret = malloc (lenret);
  realpath__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ln_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ln_args *args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ln_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args->target;
  linkname = args->linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln (target, linkname);
  if (r == -1)
    /* do_ln has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ln_f_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ln_f_args *args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ln_f_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args->target;
  linkname = args->linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_f (target, linkname);
  if (r == -1)
    /* do_ln_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ln_s_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ln_s_args *args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ln_s_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args->target;
  linkname = args->linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_s (target, linkname);
  if (r == -1)
    /* do_ln_s has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ln_sf_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ln_sf_args *args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ln_sf_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args->target;
  linkname = args->linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_sf (target, linkname);
  if (r == -1)
    /* do_ln_sf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
readlink_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_readlink_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = readlink_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_readlink (path);
  if (r == NULL)
    /* do_readlink has already called reply_with_error */
    goto done;

  guestfs_Readlink_ret ret;
  char *bufret;
  size_t lenret;
  readlink__init (&ret);
  ret.link = r;
  lenret = readlink__get_packed_size (&ret);
  bufret = malloc (lenret);
  readlink__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
fallocate_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fallocate_args *args;
  const char *path;
  int len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fallocate_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  len = args->len;

  NEED_ROOT (, goto done);
  r = do_fallocate (path, len);
  if (r == -1)
    /* do_fallocate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapon_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapon_device_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapon_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_swapon_device (device);
  if (r == -1)
    /* do_swapon_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapoff_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapoff_device_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapoff_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_swapoff_device (device);
  if (r == -1)
    /* do_swapoff_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapon_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapon_file_args *args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapon_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_swapon_file (file);
  if (r == -1)
    /* do_swapon_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapoff_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapoff_file_args *args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapoff_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_swapoff_file (file);
  if (r == -1)
    /* do_swapoff_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapon_label_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapon_label_args *args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapon_label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;

  r = do_swapon_label (label);
  if (r == -1)
    /* do_swapon_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapoff_label_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapoff_label_args *args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapoff_label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;

  r = do_swapoff_label (label);
  if (r == -1)
    /* do_swapoff_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapon_uuid_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapon_uuid_args *args;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapon_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args->uuid;

  r = do_swapon_uuid (uuid);
  if (r == -1)
    /* do_swapon_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
swapoff_uuid_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_swapoff_uuid_args *args;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = swapoff_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args->uuid;

  r = do_swapoff_uuid (uuid);
  if (r == -1)
    /* do_swapoff_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkswap_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkswap_file_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkswap_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkswap_file (path);
  if (r == -1)
    /* do_mkswap_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
inotify_init_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_inotify_init_args *args;
  int maxevents;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = inotify_init_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  maxevents = args->maxevents;

  r = do_inotify_init (maxevents);
  if (r == -1)
    /* do_inotify_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
inotify_add_watch_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_inotify_add_watch_args *args;
  const char *path;
  int mask;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = inotify_add_watch_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  mask = args->mask;

  NEED_ROOT (, goto done);
  r = do_inotify_add_watch (path, mask);
  if (r == -1)
    /* do_inotify_add_watch has already called reply_with_error */
    goto done;

  guestfs_InotifyAddWatch_ret ret;
  char *bufret;
  size_t lenret;
  inotify_add_watch__init (&ret);
  ret.wd = r;
  lenret = inotify_add_watch__get_packed_size (&ret);
  bufret = malloc (lenret);
  inotify_add_watch__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
inotify_rm_watch_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_inotify_rm_watch_args *args;
  int wd;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = inotify_rm_watch_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  wd = args->wd;

  r = do_inotify_rm_watch (wd);
  if (r == -1)
    /* do_inotify_rm_watch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
inotify_read_stub (char const *data, size_t datalen)
{
  guestfs_int_inotify_event_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_read ();
  if (r == NULL)
    /* do_inotify_read has already called reply_with_error */
    goto done;

  guestfs_inotify_read_ret ret;
  char *bufret;
  size_t lenret;
  inotify_read__init (&ret);
  ret.events = r;
  lenret = inotify_read__get_packed_size (&ret);
  bufret = malloc (lenret);
  inotify_read__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
inotify_files_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_files ();
  if (r == NULL)
    /* do_inotify_files has already called reply_with_error */
    goto done;

  guestfs_InotifyFiles_ret ret;
  char *bufret;
  size_t lenret;
  inotify_files__init (&ret);
  ret.n_paths = count_strings (r);
  ret.paths = r;
  lenret = inotify_files__get_packed_size (&ret);
  bufret = malloc (lenret);
  inotify_files__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
inotify_close_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_close ();
  if (r == -1)
    /* do_inotify_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
setcon_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_setcon_args *args;
  const char *context;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = setcon_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  context = args->context;

  r = do_setcon (context);
  if (r == -1)
    /* do_setcon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
getcon_stub (char const *data, size_t datalen)
{
  char *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_getcon ();
  if (r == NULL)
    /* do_getcon has already called reply_with_error */
    goto done;

  guestfs_Getcon_ret ret;
  char *bufret;
  size_t lenret;
  getcon__init (&ret);
  ret.context = r;
  lenret = getcon__get_packed_size (&ret);
  bufret = malloc (lenret);
  getcon__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
mkfs_b_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkfs_b_args *args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkfs_b_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args->fstype;
  blocksize = args->blocksize;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_mkfs_b (fstype, blocksize, device);
  if (r == -1)
    /* do_mkfs_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2journal_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2journal_args *args;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mke2journal_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args->blocksize;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_mke2journal (blocksize, device);
  if (r == -1)
    /* do_mke2journal has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2journal_L_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2journal_L_args *args;
  int blocksize;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mke2journal_L_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args->blocksize;
  label = args->label;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_mke2journal_L (blocksize, label, device);
  if (r == -1)
    /* do_mke2journal_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2journal_U_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2journal_U_args *args;
  int blocksize;
  const char *uuid;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mke2journal_U_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args->blocksize;
  uuid = args->uuid;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_mke2journal_U (blocksize, uuid, device);
  if (r == -1)
    /* do_mke2journal_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2fs_J_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2fs_J_args *args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  CLEANUP_FREE char *journal = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mke2fs_J_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args->fstype;
  blocksize = args->blocksize;
  RESOLVE_DEVICE (args->device, device, , goto done);
  RESOLVE_DEVICE (args->journal, journal, , goto done);

  r = do_mke2fs_J (fstype, blocksize, device, journal);
  if (r == -1)
    /* do_mke2fs_J has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2fs_JL_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2fs_JL_args *args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mke2fs_JL_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args->fstype;
  blocksize = args->blocksize;
  RESOLVE_DEVICE (args->device, device, , goto done);
  label = args->label;

  r = do_mke2fs_JL (fstype, blocksize, device, label);
  if (r == -1)
    /* do_mke2fs_JL has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2fs_JU_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2fs_JU_args *args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mke2fs_JU_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args->fstype;
  blocksize = args->blocksize;
  RESOLVE_DEVICE (args->device, device, , goto done);
  uuid = args->uuid;

  r = do_mke2fs_JU (fstype, blocksize, device, uuid);
  if (r == -1)
    /* do_mke2fs_JU has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
modprobe_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_modprobe_args *args;
  const char *modulename;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxmodules_available ()) {
    reply_with_unavailable_feature ("linuxmodules");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = modprobe_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  modulename = args->modulename;

  r = do_modprobe (modulename);
  if (r == -1)
    /* do_modprobe has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
echo_daemon_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_echo_daemon_args *args;
  char **words;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = echo_daemon_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  words = realloc (args->words,
                sizeof (char *) * (args->n_words+1));
  if (words == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  words[args->n_words] = NULL;
  args->words = words;

  r = do_echo_daemon (words);
  if (r == NULL)
    /* do_echo_daemon has already called reply_with_error */
    goto done;

  guestfs_EchoDaemon_ret ret;
  char *bufret;
  size_t lenret;
  echo_daemon__init (&ret);
  ret.output = r;
  lenret = echo_daemon__get_packed_size (&ret);
  bufret = malloc (lenret);
  echo_daemon__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
find0_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_find0_args *args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = find0_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_find0 (directory);
  if (r == -1)
    /* do_find0 has already called reply_with_error */
    goto done;

  /* do_find0 has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
case_sensitive_path_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_case_sensitive_path_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = case_sensitive_path_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_case_sensitive_path (path);
  if (r == NULL)
    /* do_case_sensitive_path has already called reply_with_error */
    goto done;

  guestfs_CaseSensitivePath_ret ret;
  char *bufret;
  size_t lenret;
  case_sensitive_path__init (&ret);
  ret.rpath = r;
  lenret = case_sensitive_path__get_packed_size (&ret);
  bufret = malloc (lenret);
  case_sensitive_path__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vfs_type_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_vfs_type_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vfs_type_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);

  r = do_vfs_type (&mountable);
  if (r == NULL)
    /* do_vfs_type has already called reply_with_error */
    goto done;

  guestfs_VfsType_ret ret;
  char *bufret;
  size_t lenret;
  vfs_type__init (&ret);
  ret.fstype = r;
  lenret = vfs_type__get_packed_size (&ret);
  bufret = malloc (lenret);
  vfs_type__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
truncate_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_truncate_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = truncate_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_truncate (path);
  if (r == -1)
    /* do_truncate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
truncate_size_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_truncate_size_args *args;
  const char *path;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = truncate_size_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  size = args->size;

  NEED_ROOT (, goto done);
  r = do_truncate_size (path, size);
  if (r == -1)
    /* do_truncate_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
utimens_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_utimens_args *args;
  const char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = utimens_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  atsecs = args->atsecs;
  atnsecs = args->atnsecs;
  mtsecs = args->mtsecs;
  mtnsecs = args->mtnsecs;

  NEED_ROOT (, goto done);
  r = do_utimens (path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    /* do_utimens has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkdir_mode_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkdir_mode_args *args;
  const char *path;
  int mode;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mkdir_mode_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  mode = args->mode;

  NEED_ROOT (, goto done);
  r = do_mkdir_mode (path, mode);
  if (r == -1)
    /* do_mkdir_mode has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lchown_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lchown_args *args;
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lchown_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  owner = args->owner;
  group = args->group;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lchown (owner, group, path);
  if (r == -1)
    /* do_lchown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_lxattrlist_stub (char const *data, size_t datalen)
{
  guestfs_int_xattr_list *r;
  struct guestfs_internal_lxattrlist_args *args;
  const char *path;
  char **names;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_lxattrlist_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args->names,
                sizeof (char *) * (args->n_names+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args->n_names] = NULL;
  args->names = names;

  NEED_ROOT (, goto done);
  r = do_internal_lxattrlist (path, names);
  if (r == NULL)
    /* do_internal_lxattrlist has already called reply_with_error */
    goto done;

  guestfs_internal_lxattrlist_ret ret;
  char *bufret;
  size_t lenret;
  internal_lxattrlist__init (&ret);
  ret.xattrs = r;
  lenret = internal_lxattrlist__get_packed_size (&ret);
  bufret = malloc (lenret);
  internal_lxattrlist__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_readlinklist_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_internal_readlinklist_args *args;
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_readlinklist_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args->names,
                sizeof (char *) * (args->n_names+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args->n_names] = NULL;
  args->names = names;

  NEED_ROOT (, goto done);
  r = do_internal_readlinklist (path, names);
  if (r == NULL)
    /* do_internal_readlinklist has already called reply_with_error */
    goto done;

  guestfs_InternalReadlinklist_ret ret;
  char *bufret;
  size_t lenret;
  internal_readlinklist__init (&ret);
  ret.n_links = count_strings (r);
  ret.links = r;
  lenret = internal_readlinklist__get_packed_size (&ret);
  bufret = malloc (lenret);
  internal_readlinklist__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pread_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_args *args;
  const char *path;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pread_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  count = args->count;
  offset = args->offset;

  NEED_ROOT (, goto done);
  r = do_pread (path, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread has already called reply_with_error */
    goto done;

  guestfs_Pread_ret ret;
  char *bufret;
  size_t lenret;
  pread__init (&ret);
  ret.content.data = r;
  ret.content.len = size;
  lenret = pread__get_packed_size (&ret);
  bufret = malloc (lenret);
  pread__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_init_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_init_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_init_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  parttype = args->parttype;

  r = do_part_init (device, parttype);
  if (r == -1)
    /* do_part_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_add_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_add_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *prlogex;
  int64_t startsect;
  int64_t endsect;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_add_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  prlogex = args->prlogex;
  startsect = args->startsect;
  endsect = args->endsect;

  r = do_part_add (device, prlogex, startsect, endsect);
  if (r == -1)
    /* do_part_add has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_disk_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_disk_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_disk_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  parttype = args->parttype;

  r = do_part_disk (device, parttype);
  if (r == -1)
    /* do_part_disk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_set_bootable_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_set_bootable_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int bootable;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_set_bootable_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;
  bootable = args->bootable;

  r = do_part_set_bootable (device, partnum, bootable);
  if (r == -1)
    /* do_part_set_bootable has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_set_name_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_set_name_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *name;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_set_name_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;
  name = args->name;

  r = do_part_set_name (device, partnum, name);
  if (r == -1)
    /* do_part_set_name has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_list_stub (char const *data, size_t datalen)
{
  guestfs_int_partition_list *r;
  struct guestfs_part_list_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_list_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_part_list (device);
  if (r == NULL)
    /* do_part_list has already called reply_with_error */
    goto done;

  guestfs_part_list_ret ret;
  char *bufret;
  size_t lenret;
  part_list__init (&ret);
  ret.partitions = r;
  lenret = part_list__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_list__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_get_parttype_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_part_get_parttype_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_get_parttype_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_part_get_parttype (device);
  if (r == NULL)
    /* do_part_get_parttype has already called reply_with_error */
    goto done;

  guestfs_PartGetParttype_ret ret;
  char *bufret;
  size_t lenret;
  part_get_parttype__init (&ret);
  ret.parttype = r;
  lenret = part_get_parttype__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_get_parttype__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
fill_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fill_args *args;
  int c;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fill_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  c = args->c;
  len = args->len;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fill (c, len, path);
  if (r == -1)
    /* do_fill has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
available_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_available_args *args;
  char **groups;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = available_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  groups = realloc (args->groups,
                sizeof (char *) * (args->n_groups+1));
  if (groups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  groups[args->n_groups] = NULL;
  args->groups = groups;

  r = do_available (groups);
  if (r == -1)
    /* do_available has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
dd_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_dd_args *args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = dd_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->src, src, , goto done);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->dest, dest, , goto done);

  r = do_dd (src, dest);
  if (r == -1)
    /* do_dd has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
filesize_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_filesize_args *args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = filesize_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_filesize (file);
  if (r == -1)
    /* do_filesize has already called reply_with_error */
    goto done;

  guestfs_Filesize_ret ret;
  char *bufret;
  size_t lenret;
  filesize__init (&ret);
  ret.size = r;
  lenret = filesize__get_packed_size (&ret);
  bufret = malloc (lenret);
  filesize__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvrename_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvrename_args *args;
  const char *logvol;
  const char *newlogvol;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvrename_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args->logvol;
  newlogvol = args->newlogvol;

  r = do_lvrename (logvol, newlogvol);
  if (r == -1)
    /* do_lvrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgrename_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_vgrename_args *args;
  const char *volgroup;
  const char *newvolgroup;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vgrename_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  volgroup = args->volgroup;
  newvolgroup = args->newvolgroup;

  r = do_vgrename (volgroup, newvolgroup);
  if (r == -1)
    /* do_vgrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
initrd_cat_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_initrd_cat_args *args;
  const char *initrdpath;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = initrd_cat_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  initrdpath = args->initrdpath;
  ABS_PATH (initrdpath, , goto done);
  filename = args->filename;

  NEED_ROOT (, goto done);
  r = do_initrd_cat (initrdpath, filename, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_initrd_cat has already called reply_with_error */
    goto done;

  guestfs_InitrdCat_ret ret;
  char *bufret;
  size_t lenret;
  initrd_cat__init (&ret);
  ret.content.data = r;
  ret.content.len = size;
  lenret = initrd_cat__get_packed_size (&ret);
  bufret = malloc (lenret);
  initrd_cat__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvuuid_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_pvuuid_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pvuuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_pvuuid (device);
  if (r == NULL)
    /* do_pvuuid has already called reply_with_error */
    goto done;

  guestfs_Pvuuid_ret ret;
  char *bufret;
  size_t lenret;
  pvuuid__init (&ret);
  ret.uuid = r;
  lenret = pvuuid__get_packed_size (&ret);
  bufret = malloc (lenret);
  pvuuid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vguuid_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_vguuid_args *args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vguuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args->vgname;

  r = do_vguuid (vgname);
  if (r == NULL)
    /* do_vguuid has already called reply_with_error */
    goto done;

  guestfs_Vguuid_ret ret;
  char *bufret;
  size_t lenret;
  vguuid__init (&ret);
  ret.uuid = r;
  lenret = vguuid__get_packed_size (&ret);
  bufret = malloc (lenret);
  vguuid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvuuid_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_lvuuid_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvuuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_lvuuid (device);
  if (r == NULL)
    /* do_lvuuid has already called reply_with_error */
    goto done;

  guestfs_Lvuuid_ret ret;
  char *bufret;
  size_t lenret;
  lvuuid__init (&ret);
  ret.uuid = r;
  lenret = lvuuid__get_packed_size (&ret);
  bufret = malloc (lenret);
  lvuuid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgpvuuids_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_vgpvuuids_args *args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vgpvuuids_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args->vgname;

  r = do_vgpvuuids (vgname);
  if (r == NULL)
    /* do_vgpvuuids has already called reply_with_error */
    goto done;

  guestfs_Vgpvuuids_ret ret;
  char *bufret;
  size_t lenret;
  vgpvuuids__init (&ret);
  ret.n_uuids = count_strings (r);
  ret.uuids = r;
  lenret = vgpvuuids__get_packed_size (&ret);
  bufret = malloc (lenret);
  vgpvuuids__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vglvuuids_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_vglvuuids_args *args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vglvuuids_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args->vgname;

  r = do_vglvuuids (vgname);
  if (r == NULL)
    /* do_vglvuuids has already called reply_with_error */
    goto done;

  guestfs_Vglvuuids_ret ret;
  char *bufret;
  size_t lenret;
  vglvuuids__init (&ret);
  ret.n_uuids = count_strings (r);
  ret.uuids = r;
  lenret = vglvuuids__get_packed_size (&ret);
  bufret = malloc (lenret);
  vglvuuids__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
copy_size_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_copy_size_args *args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = copy_size_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->src, src, , goto done);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->dest, dest, , goto done);
  size = args->size;

  r = do_copy_size (src, dest, size);
  if (r == -1)
    /* do_copy_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zero_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_zero_device_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zero_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_zero_device (device);
  if (r == -1)
    /* do_zero_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
txz_in_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_txz_in_args *args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("xz");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = txz_in_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_txz_in (directory);
  if (r == -1)
    /* do_txz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
txz_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_txz_out_args *args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    reply_with_unavailable_feature ("xz");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = txz_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_txz_out (directory);
  if (r == -1)
    /* do_txz_out has already called reply_with_error */
    goto done;

  /* do_txz_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgscan_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgscan ();
  if (r == -1)
    /* do_vgscan has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
part_del_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_del_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_del_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;

  r = do_part_del (device, partnum);
  if (r == -1)
    /* do_part_del has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_get_bootable_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_get_bootable_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_get_bootable_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;

  r = do_part_get_bootable (device, partnum);
  if (r == -1)
    /* do_part_get_bootable has already called reply_with_error */
    goto done;

  guestfs_PartGetBootable_ret ret;
  char *bufret;
  size_t lenret;
  part_get_bootable__init (&ret);
  ret.bootable = r;
  lenret = part_get_bootable__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_get_bootable__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_get_mbr_id_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_get_mbr_id_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_get_mbr_id_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;

  r = do_part_get_mbr_id (device, partnum);
  if (r == -1)
    /* do_part_get_mbr_id has already called reply_with_error */
    goto done;

  guestfs_PartGetMbrId_ret ret;
  char *bufret;
  size_t lenret;
  part_get_mbr_id__init (&ret);
  ret.idbyte = r;
  lenret = part_get_mbr_id__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_get_mbr_id__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_set_mbr_id_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_set_mbr_id_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int idbyte;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_set_mbr_id_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;
  idbyte = args->idbyte;

  r = do_part_set_mbr_id (device, partnum, idbyte);
  if (r == -1)
    /* do_part_set_mbr_id has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
checksum_device_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_checksum_device_args *args;
  const char *csumtype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = checksum_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args->csumtype;
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_checksum_device (csumtype, device);
  if (r == NULL)
    /* do_checksum_device has already called reply_with_error */
    goto done;

  guestfs_ChecksumDevice_ret ret;
  char *bufret;
  size_t lenret;
  checksum_device__init (&ret);
  ret.checksum = r;
  lenret = checksum_device__get_packed_size (&ret);
  bufret = malloc (lenret);
  checksum_device__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvresize_free_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvresize_free_args *args;
  CLEANUP_FREE char *lv = NULL;
  int percent;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvresize_free_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->lv, lv, , goto done);
  percent = args->percent;

  r = do_lvresize_free (lv, percent);
  if (r == -1)
    /* do_lvresize_free has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_clear_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_clear_args *args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_clear_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;

  r = do_aug_clear (augpath);
  if (r == -1)
    /* do_aug_clear has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
get_umask_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_get_umask ();
  if (r == -1)
    /* do_get_umask has already called reply_with_error */
    goto done;

  guestfs_GetUmask_ret ret;
  char *bufret;
  size_t lenret;
  get_umask__init (&ret);
  ret.mask = r;
  lenret = get_umask__get_packed_size (&ret);
  bufret = malloc (lenret);
  get_umask__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
done_no_free:
  return;
}

static void
debug_upload_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_debug_upload_args *args;
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = debug_upload_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpname = args->tmpname;
  mode = args->mode;

  r = do_debug_upload (tmpname, mode);
  if (r == -1)
    /* do_debug_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
base64_in_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_base64_in_args *args;
  const char *filename;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = base64_in_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args->filename;
  ABS_PATH (filename, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_base64_in (filename);
  if (r == -1)
    /* do_base64_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
base64_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_base64_out_args *args;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = base64_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args->filename;
  ABS_PATH (filename, , goto done);

  NEED_ROOT (, goto done);
  r = do_base64_out (filename);
  if (r == -1)
    /* do_base64_out has already called reply_with_error */
    goto done;

  /* do_base64_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
checksums_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_checksums_out_args *args;
  const char *csumtype;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = checksums_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args->csumtype;
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_checksums_out (csumtype, directory);
  if (r == -1)
    /* do_checksums_out has already called reply_with_error */
    goto done;

  /* do_checksums_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
fill_pattern_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fill_pattern_args *args;
  const char *pattern;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fill_pattern_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args->pattern;
  len = args->len;
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fill_pattern (pattern, len, path);
  if (r == -1)
    /* do_fill_pattern has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_write_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_write_args *args;
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_write_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  content = args->content.data;
  content_size = args->content.len;

  NEED_ROOT (, goto done);
  r = do_internal_write (path, content, content_size);
  if (r == -1)
    /* do_internal_write has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pwrite_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pwrite_args *args;
  const char *path;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pwrite_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  content = args->content.data;
  content_size = args->content.len;
  offset = args->offset;

  NEED_ROOT (, goto done);
  r = do_pwrite (path, content, content_size, offset);
  if (r == -1)
    /* do_pwrite has already called reply_with_error */
    goto done;

  guestfs_Pwrite_ret ret;
  char *bufret;
  size_t lenret;
  pwrite__init (&ret);
  ret.nbytes = r;
  lenret = pwrite__get_packed_size (&ret);
  bufret = malloc (lenret);
  pwrite__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
resize2fs_size_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_resize2fs_size_args *args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = resize2fs_size_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  size = args->size;

  r = do_resize2fs_size (device, size);
  if (r == -1)
    /* do_resize2fs_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvresize_size_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pvresize_size_args *args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pvresize_size_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  size = args->size;

  r = do_pvresize_size (device, size);
  if (r == -1)
    /* do_pvresize_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ntfsresize_size_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ntfsresize_size_args *args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ntfsresize_size_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  size = args->size;

  r = do_ntfsresize_size (device, size);
  if (r == -1)
    /* do_ntfsresize_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
available_all_groups_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_available_all_groups ();
  if (r == NULL)
    /* do_available_all_groups has already called reply_with_error */
    goto done;

  guestfs_AvailableAllGroups_ret ret;
  char *bufret;
  size_t lenret;
  available_all_groups__init (&ret);
  ret.n_groups = count_strings (r);
  ret.groups = r;
  lenret = available_all_groups__get_packed_size (&ret);
  bufret = malloc (lenret);
  available_all_groups__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
fallocate64_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fallocate64_args *args;
  const char *path;
  int64_t len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fallocate64_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  len = args->len;

  NEED_ROOT (, goto done);
  r = do_fallocate64 (path, len);
  if (r == -1)
    /* do_fallocate64 has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vfs_label_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_vfs_label_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vfs_label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);

  r = do_vfs_label (&mountable);
  if (r == NULL)
    /* do_vfs_label has already called reply_with_error */
    goto done;

  guestfs_VfsLabel_ret ret;
  char *bufret;
  size_t lenret;
  vfs_label__init (&ret);
  ret.label = r;
  lenret = vfs_label__get_packed_size (&ret);
  bufret = malloc (lenret);
  vfs_label__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vfs_uuid_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_vfs_uuid_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vfs_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);

  r = do_vfs_uuid (&mountable);
  if (r == NULL)
    /* do_vfs_uuid has already called reply_with_error */
    goto done;

  guestfs_VfsUuid_ret ret;
  char *bufret;
  size_t lenret;
  vfs_uuid__init (&ret);
  ret.uuid = r;
  lenret = vfs_uuid__get_packed_size (&ret);
  bufret = malloc (lenret);
  vfs_uuid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvm_set_filter_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvm_set_filter_args *args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvm_set_filter_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args->n_devices+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_devices; ++i)
      RESOLVE_DEVICE (args->devices[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }

  r = do_lvm_set_filter (devices);
  if (r == -1)
    /* do_lvm_set_filter has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvm_clear_filter_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvm_clear_filter ();
  if (r == -1)
    /* do_lvm_clear_filter has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
luks_open_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_open_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_open_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  key = args->key;
  mapname = args->mapname;

  r = do_luks_open (device, key, mapname);
  if (r == -1)
    /* do_luks_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
luks_open_ro_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_open_ro_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_open_ro_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  key = args->key;
  mapname = args->mapname;

  r = do_luks_open_ro (device, key, mapname);
  if (r == -1)
    /* do_luks_open_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
luks_close_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_close_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_close_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_luks_close (device);
  if (r == -1)
    /* do_luks_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
luks_format_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_format_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_format_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  key = args->key;
  keyslot = args->keyslot;

  r = do_luks_format (device, key, keyslot);
  if (r == -1)
    /* do_luks_format has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
luks_format_cipher_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_format_cipher_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;
  const char *cipher;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_format_cipher_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  key = args->key;
  keyslot = args->keyslot;
  cipher = args->cipher;

  r = do_luks_format_cipher (device, key, keyslot, cipher);
  if (r == -1)
    /* do_luks_format_cipher has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
luks_add_key_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_add_key_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *newkey;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_add_key_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  key = args->key;
  newkey = args->newkey;
  keyslot = args->keyslot;

  r = do_luks_add_key (device, key, newkey, keyslot);
  if (r == -1)
    /* do_luks_add_key has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
luks_kill_slot_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_luks_kill_slot_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = luks_kill_slot_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  key = args->key;
  keyslot = args->keyslot;

  r = do_luks_kill_slot (device, key, keyslot);
  if (r == -1)
    /* do_luks_kill_slot has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_lv_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_lv_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = is_lv_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_is_lv (device);
  if (r == -1)
    /* do_is_lv has already called reply_with_error */
    goto done;

  guestfs_IsLv_ret ret;
  char *bufret;
  size_t lenret;
  is_lv__init (&ret);
  ret.lvflag = r;
  lenret = is_lv__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_lv__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
findfs_uuid_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_findfs_uuid_args *args;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = findfs_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args->uuid;

  r = do_findfs_uuid (uuid);
  if (r == NULL)
    /* do_findfs_uuid has already called reply_with_error */
    goto done;

  guestfs_FindfsUuid_ret ret;
  char *bufret;
  size_t lenret;
  findfs_uuid__init (&ret);
  ret.device = r;
  lenret = findfs_uuid__get_packed_size (&ret);
  bufret = malloc (lenret);
  findfs_uuid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
findfs_label_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_findfs_label_args *args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = findfs_label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;

  r = do_findfs_label (label);
  if (r == NULL)
    /* do_findfs_label has already called reply_with_error */
    goto done;

  guestfs_FindfsLabel_ret ret;
  char *bufret;
  size_t lenret;
  findfs_label__init (&ret);
  ret.device = r;
  lenret = findfs_label__get_packed_size (&ret);
  bufret = malloc (lenret);
  findfs_label__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_chardev_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_chardev_args *args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = is_chardev_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  followsymlinks = args->followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_chardev (path, followsymlinks);
  if (r == -1)
    /* do_is_chardev has already called reply_with_error */
    goto done;

  guestfs_IsChardev_ret ret;
  char *bufret;
  size_t lenret;
  is_chardev__init (&ret);
  ret.flag = r;
  lenret = is_chardev__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_chardev__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_blockdev_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_blockdev_args *args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = is_blockdev_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  followsymlinks = args->followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_blockdev (path, followsymlinks);
  if (r == -1)
    /* do_is_blockdev has already called reply_with_error */
    goto done;

  guestfs_IsBlockdev_ret ret;
  char *bufret;
  size_t lenret;
  is_blockdev__init (&ret);
  ret.flag = r;
  lenret = is_blockdev__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_blockdev__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_fifo_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_fifo_args *args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = is_fifo_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  followsymlinks = args->followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_fifo (path, followsymlinks);
  if (r == -1)
    /* do_is_fifo has already called reply_with_error */
    goto done;

  guestfs_IsFifo_ret ret;
  char *bufret;
  size_t lenret;
  is_fifo__init (&ret);
  ret.flag = r;
  lenret = is_fifo__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_fifo__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_symlink_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_symlink_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = is_symlink_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_is_symlink (path);
  if (r == -1)
    /* do_is_symlink has already called reply_with_error */
    goto done;

  guestfs_IsSymlink_ret ret;
  char *bufret;
  size_t lenret;
  is_symlink__init (&ret);
  ret.flag = r;
  lenret = is_symlink__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_symlink__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_socket_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_socket_args *args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = is_socket_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  followsymlinks = args->followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_socket (path, followsymlinks);
  if (r == -1)
    /* do_is_socket has already called reply_with_error */
    goto done;

  guestfs_IsSocket_ret ret;
  char *bufret;
  size_t lenret;
  is_socket__init (&ret);
  ret.flag = r;
  lenret = is_socket__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_socket__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_to_dev_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_part_to_dev_args *args;
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_to_dev_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->partition, partition, , goto done);

  r = do_part_to_dev (partition);
  if (r == NULL)
    /* do_part_to_dev has already called reply_with_error */
    goto done;

  guestfs_PartToDev_ret ret;
  char *bufret;
  size_t lenret;
  part_to_dev__init (&ret);
  ret.device = r;
  lenret = part_to_dev__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_to_dev__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
upload_offset_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_upload_offset_args *args;
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = upload_offset_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->remotefilename, remotefilename, cancel_receive (), goto done);
  offset = args->offset;

  r = do_upload_offset (remotefilename, offset);
  if (r == -1)
    /* do_upload_offset has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
download_offset_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_download_offset_args *args;
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = download_offset_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->remotefilename, remotefilename, , goto done);
  offset = args->offset;
  size = args->size;

  r = do_download_offset (remotefilename, offset, size);
  if (r == -1)
    /* do_download_offset has already called reply_with_error */
    goto done;

  /* do_download_offset has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
pwrite_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pwrite_device_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pwrite_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  content = args->content.data;
  content_size = args->content.len;
  offset = args->offset;

  r = do_pwrite_device (device, content, content_size, offset);
  if (r == -1)
    /* do_pwrite_device has already called reply_with_error */
    goto done;

  guestfs_PwriteDevice_ret ret;
  char *bufret;
  size_t lenret;
  pwrite_device__init (&ret);
  ret.nbytes = r;
  lenret = pwrite_device__get_packed_size (&ret);
  bufret = malloc (lenret);
  pwrite_device__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pread_device_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_device_args *args;
  CLEANUP_FREE char *device = NULL;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pread_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  count = args->count;
  offset = args->offset;

  r = do_pread_device (device, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread_device has already called reply_with_error */
    goto done;

  guestfs_PreadDevice_ret ret;
  char *bufret;
  size_t lenret;
  pread_device__init (&ret);
  ret.content.data = r;
  ret.content.len = size;
  lenret = pread_device__get_packed_size (&ret);
  bufret = malloc (lenret);
  pread_device__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvm_canonical_lv_name_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_lvm_canonical_lv_name_args *args;
  CLEANUP_FREE char *lvname = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvm_canonical_lv_name_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->lvname, lvname, , goto done);

  r = do_lvm_canonical_lv_name (lvname);
  if (r == NULL)
    /* do_lvm_canonical_lv_name has already called reply_with_error */
    goto done;

  guestfs_LvmCanonicalLvName_ret ret;
  char *bufret;
  size_t lenret;
  lvm_canonical_lv_name__init (&ret);
  ret.lv = r;
  lenret = lvm_canonical_lv_name__get_packed_size (&ret);
  bufret = malloc (lenret);
  lvm_canonical_lv_name__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkfs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkfs_args *args;
  const char *fstype;
  CLEANUP_FREE char *device = NULL;
  int blocksize;
  const char *features;
  int inode;
  int sectorsize;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = mkfs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args->fstype;
  RESOLVE_DEVICE (args->device, device, , goto done);
  blocksize = args->blocksize;
  features = args->features;
  inode = args->inode;
  sectorsize = args->sectorsize;

  r = do_mkfs (fstype, device, blocksize, features, inode, sectorsize);
  if (r == -1)
    /* do_mkfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
getxattr_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_getxattr_args *args;
  const char *path;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = getxattr_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  name = args->name;

  NEED_ROOT (, goto done);
  r = do_getxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_getxattr has already called reply_with_error */
    goto done;

  guestfs_Getxattr_ret ret;
  char *bufret;
  size_t lenret;
  getxattr__init (&ret);
  ret.xattr.data = r;
  ret.xattr.len = size;
  lenret = getxattr__get_packed_size (&ret);
  bufret = malloc (lenret);
  getxattr__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lgetxattr_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_lgetxattr_args *args;
  const char *path;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lgetxattr_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  name = args->name;

  NEED_ROOT (, goto done);
  r = do_lgetxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_lgetxattr has already called reply_with_error */
    goto done;

  guestfs_Lgetxattr_ret ret;
  char *bufret;
  size_t lenret;
  lgetxattr__init (&ret);
  ret.xattr.data = r;
  ret.xattr.len = size;
  lenret = lgetxattr__get_packed_size (&ret);
  bufret = malloc (lenret);
  lgetxattr__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
resize2fs_M_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_resize2fs_M_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = resize2fs_M_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_resize2fs_M (device);
  if (r == -1)
    /* do_resize2fs_M has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_autosync_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_autosync ();
  if (r == -1)
    /* do_internal_autosync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
is_zero_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_zero_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = is_zero_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_is_zero (path);
  if (r == -1)
    /* do_is_zero has already called reply_with_error */
    goto done;

  guestfs_IsZero_ret ret;
  char *bufret;
  size_t lenret;
  is_zero__init (&ret);
  ret.zeroflag = r;
  lenret = is_zero__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_zero__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_zero_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_zero_device_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = is_zero_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_is_zero_device (device);
  if (r == -1)
    /* do_is_zero_device has already called reply_with_error */
    goto done;

  guestfs_IsZeroDevice_ret ret;
  char *bufret;
  size_t lenret;
  is_zero_device__init (&ret);
  ret.zeroflag = r;
  lenret = is_zero_device__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_zero_device__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
list_9p_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_9p ();
  if (r == NULL)
    /* do_list_9p has already called reply_with_error */
    goto done;

  guestfs_List9p_ret ret;
  char *bufret;
  size_t lenret;
  list_9p__init (&ret);
  ret.n_mounttags = count_strings (r);
  ret.mounttags = r;
  lenret = list_9p__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_9p__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
mount_9p_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mount_9p_args *args;
  const char *mounttag;
  const char *mountpoint;
  const char *options;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = mount_9p_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mounttag = args->mounttag;
  mountpoint = args->mountpoint;
  options = args->options;

  r = do_mount_9p (mounttag, mountpoint, options);
  if (r == -1)
    /* do_mount_9p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
list_dm_devices_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_dm_devices ();
  if (r == NULL)
    /* do_list_dm_devices has already called reply_with_error */
    goto done;

  guestfs_ListDmDevices_ret ret;
  char *bufret;
  size_t lenret;
  list_dm_devices__init (&ret);
  ret.n_devices = count_strings (r);
  ret.devices = r;
  lenret = list_dm_devices__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_dm_devices__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
ntfsresize_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ntfsresize_args *args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = ntfsresize_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  size = args->size;
  force = args->force;

  r = do_ntfsresize (device, size, force);
  if (r == -1)
    /* do_ntfsresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_filesystem_resize_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_filesystem_resize_args *args;
  const char *mountpoint;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = btrfs_filesystem_resize_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args->mountpoint;
  ABS_PATH (mountpoint, , goto done);
  size = args->size;

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_resize (mountpoint, size);
  if (r == -1)
    /* do_btrfs_filesystem_resize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_write_append_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_write_append_args *args;
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_write_append_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  content = args->content.data;
  content_size = args->content.len;

  NEED_ROOT (, goto done);
  r = do_internal_write_append (path, content, content_size);
  if (r == -1)
    /* do_internal_write_append has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
compress_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_compress_out_args *args;
  const char *ctype;
  const char *file;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = compress_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  ctype = args->ctype;
  file = args->file;
  ABS_PATH (file, , goto done);
  level = args->level;

  NEED_ROOT (, goto done);
  r = do_compress_out (ctype, file, level);
  if (r == -1)
    /* do_compress_out has already called reply_with_error */
    goto done;

  /* do_compress_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
compress_device_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_compress_device_out_args *args;
  const char *ctype;
  CLEANUP_FREE char *device = NULL;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = compress_device_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  ctype = args->ctype;
  RESOLVE_DEVICE (args->device, device, , goto done);
  level = args->level;

  r = do_compress_device_out (ctype, device, level);
  if (r == -1)
    /* do_compress_device_out has already called reply_with_error */
    goto done;

  /* do_compress_device_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_to_partnum_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_to_partnum_args *args;
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_to_partnum_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->partition, partition, , goto done);

  r = do_part_to_partnum (partition);
  if (r == -1)
    /* do_part_to_partnum has already called reply_with_error */
    goto done;

  guestfs_PartToPartnum_ret ret;
  char *bufret;
  size_t lenret;
  part_to_partnum__init (&ret);
  ret.partnum = r;
  lenret = part_to_partnum__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_to_partnum__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
copy_device_to_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_copy_device_to_device_args *args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = copy_device_to_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->src, src, , goto done);
  RESOLVE_DEVICE (args->dest, dest, , goto done);
  srcoffset = args->srcoffset;
  destoffset = args->destoffset;
  size = args->size;
  sparse = args->sparse;

  r = do_copy_device_to_device (src, dest, srcoffset, destoffset, size, sparse);
  if (r == -1)
    /* do_copy_device_to_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
copy_device_to_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_copy_device_to_file_args *args;
  CLEANUP_FREE char *src = NULL;
  const char *dest;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = copy_device_to_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->src, src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);
  srcoffset = args->srcoffset;
  destoffset = args->destoffset;
  size = args->size;
  sparse = args->sparse;

  NEED_ROOT (, goto done);
  r = do_copy_device_to_file (src, dest, srcoffset, destoffset, size, sparse);
  if (r == -1)
    /* do_copy_device_to_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
copy_file_to_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_copy_file_to_device_args *args;
  const char *src;
  CLEANUP_FREE char *dest = NULL;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = copy_file_to_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  RESOLVE_DEVICE (args->dest, dest, , goto done);
  srcoffset = args->srcoffset;
  destoffset = args->destoffset;
  size = args->size;
  sparse = args->sparse;

  NEED_ROOT (, goto done);
  r = do_copy_file_to_device (src, dest, srcoffset, destoffset, size, sparse);
  if (r == -1)
    /* do_copy_file_to_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
copy_file_to_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_copy_file_to_file_args *args;
  const char *src;
  const char *dest;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = copy_file_to_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);
  srcoffset = args->srcoffset;
  destoffset = args->destoffset;
  size = args->size;
  sparse = args->sparse;

  NEED_ROOT (, goto done);
  r = do_copy_file_to_file (src, dest, srcoffset, destoffset, size, sparse);
  if (r == -1)
    /* do_copy_file_to_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
tune2fs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_tune2fs_args *args;
  CLEANUP_FREE char *device = NULL;
  int force;
  int maxmountcount;
  int mountcount;
  const char *errorbehavior;
  int64_t group;
  int intervalbetweenchecks;
  int reservedblockspercentage;
  const char *lastmounteddirectory;
  int64_t reservedblockscount;
  int64_t user;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = tune2fs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  force = args->force;
  maxmountcount = args->maxmountcount;
  mountcount = args->mountcount;
  errorbehavior = args->errorbehavior;
  group = args->group;
  intervalbetweenchecks = args->intervalbetweenchecks;
  reservedblockspercentage = args->reservedblockspercentage;
  lastmounteddirectory = args->lastmounteddirectory;
  reservedblockscount = args->reservedblockscount;
  user = args->user;

  r = do_tune2fs (device, force, maxmountcount, mountcount, errorbehavior, group, intervalbetweenchecks, reservedblockspercentage, lastmounteddirectory, reservedblockscount, user);
  if (r == -1)
    /* do_tune2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
md_create_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_md_create_args *args;
  const char *name;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  int64_t missingbitmap;
  int nrdevices;
  int spare;
  int64_t chunk;
  const char *level;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = md_create_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args->name;
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args->n_devices+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_devices; ++i)
      RESOLVE_DEVICE (args->devices[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  missingbitmap = args->missingbitmap;
  nrdevices = args->nrdevices;
  spare = args->spare;
  chunk = args->chunk;
  level = args->level;

  r = do_md_create (name, devices, missingbitmap, nrdevices, spare, chunk, level);
  if (r == -1)
    /* do_md_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
list_md_devices_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_md_devices ();
  if (r == NULL)
    /* do_list_md_devices has already called reply_with_error */
    goto done;

  guestfs_ListMdDevices_ret ret;
  char *bufret;
  size_t lenret;
  list_md_devices__init (&ret);
  ret.n_devices = count_strings (r);
  ret.devices = r;
  lenret = list_md_devices__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_md_devices__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
md_detail_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_md_detail_args *args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = md_detail_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->md, md, , goto done);

  r = do_md_detail (md);
  if (r == NULL)
    /* do_md_detail has already called reply_with_error */
    goto done;

  guestfs_MdDetail_ret ret;
  char *bufret;
  size_t lenret;
  md_detail__init (&ret);
  ret.n_info = count_strings (r);
  ret.info = r;
  lenret = md_detail__get_packed_size (&ret);
  bufret = malloc (lenret);
  md_detail__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
md_stop_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_md_stop_args *args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = md_stop_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->md, md, , goto done);

  r = do_md_stop (md);
  if (r == -1)
    /* do_md_stop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blkid_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_blkid_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blkid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blkid (device);
  if (r == NULL)
    /* do_blkid has already called reply_with_error */
    goto done;

  guestfs_Blkid_ret ret;
  char *bufret;
  size_t lenret;
  blkid__init (&ret);
  ret.n_info = count_strings (r);
  ret.info = r;
  lenret = blkid__get_packed_size (&ret);
  bufret = malloc (lenret);
  blkid__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
e2fsck_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_e2fsck_args *args;
  CLEANUP_FREE char *device = NULL;
  int correct;
  int forceall;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = e2fsck_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  correct = args->correct;
  forceall = args->forceall;

  r = do_e2fsck (device, correct, forceall);
  if (r == -1)
    /* do_e2fsck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
llz_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_llz_args *args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = llz_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_llz (directory);
  if (r == NULL)
    /* do_llz has already called reply_with_error */
    goto done;

  guestfs_Llz_ret ret;
  char *bufret;
  size_t lenret;
  llz__init (&ret);
  ret.listing = r;
  lenret = llz__get_packed_size (&ret);
  bufret = malloc (lenret);
  llz__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
wipefs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_wipefs_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_wipefs_available ()) {
    reply_with_unavailable_feature ("wipefs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = wipefs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_wipefs (device);
  if (r == -1)
    /* do_wipefs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ntfsfix_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ntfsfix_args *args;
  CLEANUP_FREE char *device = NULL;
  int clearbadsectors;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = ntfsfix_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  clearbadsectors = args->clearbadsectors;

  r = do_ntfsfix (device, clearbadsectors);
  if (r == -1)
    /* do_ntfsfix has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ntfsclone_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ntfsclone_out_args *args;
  CLEANUP_FREE char *device = NULL;
  int metadataonly;
  int rescue;
  int ignorefscheck;
  int preservetimestamps;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = ntfsclone_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  metadataonly = args->metadataonly;
  rescue = args->rescue;
  ignorefscheck = args->ignorefscheck;
  preservetimestamps = args->preservetimestamps;
  force = args->force;

  r = do_ntfsclone_out (device, metadataonly, rescue, ignorefscheck, preservetimestamps, force);
  if (r == -1)
    /* do_ntfsclone_out has already called reply_with_error */
    goto done;

  /* do_ntfsclone_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
ntfsclone_in_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ntfsclone_in_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ntfsclone_in_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, cancel_receive (), goto done);

  r = do_ntfsclone_in (device);
  if (r == -1)
    /* do_ntfsclone_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
set_label_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_set_label_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = set_label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);
  label = args->label;

  r = do_set_label (&mountable, label);
  if (r == -1)
    /* do_set_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
zero_free_space_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_zero_free_space_args *args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = zero_free_space_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_zero_free_space (directory);
  if (r == -1)
    /* do_zero_free_space has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lvcreate_free_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_lvcreate_free_args *args;
  const char *logvol;
  const char *volgroup;
  int percent;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lvcreate_free_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args->logvol;
  volgroup = args->volgroup;
  percent = args->percent;

  r = do_lvcreate_free (logvol, volgroup, percent);
  if (r == -1)
    /* do_lvcreate_free has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
isoinfo_device_stub (char const *data, size_t datalen)
{
  guestfs_int_isoinfo *r;
  struct guestfs_isoinfo_device_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = isoinfo_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_isoinfo_device (device);
  if (r == NULL)
    /* do_isoinfo_device has already called reply_with_error */
    goto done;

  guestfs_isoinfo_device_ret ret;
  char *bufret;
  size_t lenret;
  isoinfo_device__init (&ret);
  ret.isodata = r;
  lenret = isoinfo_device__get_packed_size (&ret);
  bufret = malloc (lenret);
  isoinfo_device__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
isoinfo_stub (char const *data, size_t datalen)
{
  guestfs_int_isoinfo *r;
  struct guestfs_isoinfo_args *args;
  const char *isofile;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = isoinfo_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  isofile = args->isofile;
  ABS_PATH (isofile, , goto done);

  NEED_ROOT (, goto done);
  r = do_isoinfo (isofile);
  if (r == NULL)
    /* do_isoinfo has already called reply_with_error */
    goto done;

  guestfs_isoinfo_ret ret;
  char *bufret;
  size_t lenret;
  isoinfo__init (&ret);
  ret.isodata = r;
  lenret = isoinfo__get_packed_size (&ret);
  bufret = malloc (lenret);
  isoinfo__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgmeta_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_vgmeta_args *args;
  const char *vgname;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vgmeta_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args->vgname;

  r = do_vgmeta (vgname, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_vgmeta has already called reply_with_error */
    goto done;

  guestfs_Vgmeta_ret ret;
  char *bufret;
  size_t lenret;
  vgmeta__init (&ret);
  ret.metadata.data = r;
  ret.metadata.len = size;
  lenret = vgmeta__get_packed_size (&ret);
  bufret = malloc (lenret);
  vgmeta__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
md_stat_stub (char const *data, size_t datalen)
{
  guestfs_int_mdstat_list *r;
  struct guestfs_md_stat_args *args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = md_stat_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->md, md, , goto done);

  r = do_md_stat (md);
  if (r == NULL)
    /* do_md_stat has already called reply_with_error */
    goto done;

  guestfs_md_stat_ret ret;
  char *bufret;
  size_t lenret;
  md_stat__init (&ret);
  ret.devices = r;
  lenret = md_stat__get_packed_size (&ret);
  bufret = malloc (lenret);
  md_stat__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mkfs_btrfs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mkfs_btrfs_args *args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  int64_t allocstart;
  int64_t bytecount;
  const char *datatype;
  int leafsize;
  const char *label;
  const char *metadata;
  int nodesize;
  int sectorsize;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = mkfs_btrfs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args->n_devices+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_devices; ++i)
      RESOLVE_DEVICE (args->devices[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  allocstart = args->allocstart;
  bytecount = args->bytecount;
  datatype = args->datatype;
  leafsize = args->leafsize;
  label = args->label;
  metadata = args->metadata;
  nodesize = args->nodesize;
  sectorsize = args->sectorsize;

  r = do_mkfs_btrfs (devices, allocstart, bytecount, datatype, leafsize, label, metadata, nodesize, sectorsize);
  if (r == -1)
    /* do_mkfs_btrfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
get_e2attrs_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_get_e2attrs_args *args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = get_e2attrs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_get_e2attrs (file);
  if (r == NULL)
    /* do_get_e2attrs has already called reply_with_error */
    goto done;

  guestfs_GetE2attrs_ret ret;
  char *bufret;
  size_t lenret;
  get_e2attrs__init (&ret);
  ret.attrs = r;
  lenret = get_e2attrs__get_packed_size (&ret);
  bufret = malloc (lenret);
  get_e2attrs__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
set_e2attrs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_set_e2attrs_args *args;
  const char *file;
  const char *attrs;
  int clear;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = set_e2attrs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);
  attrs = args->attrs;
  clear = args->clear;

  NEED_ROOT (, goto done);
  r = do_set_e2attrs (file, attrs, clear);
  if (r == -1)
    /* do_set_e2attrs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
get_e2generation_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_get_e2generation_args *args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = get_e2generation_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_get_e2generation (file);
  if (r == -1)
    /* do_get_e2generation has already called reply_with_error */
    goto done;

  guestfs_GetE2generation_ret ret;
  char *bufret;
  size_t lenret;
  get_e2generation__init (&ret);
  ret.generation = r;
  lenret = get_e2generation__get_packed_size (&ret);
  bufret = malloc (lenret);
  get_e2generation__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
set_e2generation_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_set_e2generation_args *args;
  const char *file;
  int64_t generation;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = set_e2generation_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args->file;
  ABS_PATH (file, , goto done);
  generation = args->generation;

  NEED_ROOT (, goto done);
  r = do_set_e2generation (file, generation);
  if (r == -1)
    /* do_set_e2generation has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_subvolume_snapshot_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_subvolume_snapshot_args *args;
  const char *source;
  const char *dest;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_subvolume_snapshot_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  source = args->source;
  ABS_PATH (source, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_snapshot (source, dest);
  if (r == -1)
    /* do_btrfs_subvolume_snapshot has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_subvolume_delete_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_subvolume_delete_args *args;
  const char *subvolume;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_subvolume_delete_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args->subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_delete (subvolume);
  if (r == -1)
    /* do_btrfs_subvolume_delete has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_subvolume_create_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_subvolume_create_args *args;
  const char *dest;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_subvolume_create_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dest = args->dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_create (dest);
  if (r == -1)
    /* do_btrfs_subvolume_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_subvolume_list_stub (char const *data, size_t datalen)
{
  guestfs_int_btrfssubvolume_list *r;
  struct guestfs_btrfs_subvolume_list_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_subvolume_list_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args->fs, fs, , goto done);

  r = do_btrfs_subvolume_list (&fs);
  if (r == NULL)
    /* do_btrfs_subvolume_list has already called reply_with_error */
    goto done;

  guestfs_btrfs_subvolume_list_ret ret;
  char *bufret;
  size_t lenret;
  btrfs_subvolume_list__init (&ret);
  ret.subvolumes = r;
  lenret = btrfs_subvolume_list__get_packed_size (&ret);
  bufret = malloc (lenret);
  btrfs_subvolume_list__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_subvolume_set_default_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_subvolume_set_default_args *args;
  int64_t id;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_subvolume_set_default_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  id = args->id;
  fs = args->fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_set_default (id, fs);
  if (r == -1)
    /* do_btrfs_subvolume_set_default has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_filesystem_sync_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_filesystem_sync_args *args;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_filesystem_sync_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fs = args->fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_sync (fs);
  if (r == -1)
    /* do_btrfs_filesystem_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_filesystem_balance_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_filesystem_balance_args *args;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_filesystem_balance_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fs = args->fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_balance (fs);
  if (r == -1)
    /* do_btrfs_filesystem_balance has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_device_add_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_device_add_args *args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_device_add_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args->n_devices+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_devices; ++i)
      RESOLVE_DEVICE (args->devices[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  fs = args->fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_device_add (devices, fs);
  if (r == -1)
    /* do_btrfs_device_add has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_device_delete_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_device_delete_args *args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_device_delete_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args->n_devices+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_devices; ++i)
      RESOLVE_DEVICE (args->devices[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  fs = args->fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_device_delete (devices, fs);
  if (r == -1)
    /* do_btrfs_device_delete has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_set_seeding_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_set_seeding_args *args;
  CLEANUP_FREE char *device = NULL;
  int seeding;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = btrfs_set_seeding_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  seeding = args->seeding;

  r = do_btrfs_set_seeding (device, seeding);
  if (r == -1)
    /* do_btrfs_set_seeding has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
btrfs_fsck_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_btrfs_fsck_args *args;
  CLEANUP_FREE char *device = NULL;
  int64_t superblock;
  int repair;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = btrfs_fsck_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  superblock = args->superblock;
  repair = args->repair;

  r = do_btrfs_fsck (device, superblock, repair);
  if (r == -1)
    /* do_btrfs_fsck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
filesystem_available_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_filesystem_available_args *args;
  const char *filesystem;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = filesystem_available_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filesystem = args->filesystem;

  r = do_filesystem_available (filesystem);
  if (r == -1)
    /* do_filesystem_available has already called reply_with_error */
    goto done;

  guestfs_FilesystemAvailable_ret ret;
  char *bufret;
  size_t lenret;
  filesystem_available__init (&ret);
  ret.fsavail = r;
  lenret = filesystem_available__get_packed_size (&ret);
  bufret = malloc (lenret);
  filesystem_available__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
fstrim_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fstrim_args *args;
  const char *mountpoint;
  int64_t offset;
  int64_t length;
  int64_t minimumfreeextent;

  /* The caller should have checked before calling this. */
  if (! optgroup_fstrim_available ()) {
    reply_with_unavailable_feature ("fstrim");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = fstrim_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args->mountpoint;
  ABS_PATH (mountpoint, , goto done);
  offset = args->offset;
  length = args->length;
  minimumfreeextent = args->minimumfreeextent;

  NEED_ROOT (, goto done);
  r = do_fstrim (mountpoint, offset, length, minimumfreeextent);
  if (r == -1)
    /* do_fstrim has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
device_index_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_device_index_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = device_index_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_device_index (device);
  if (r == -1)
    /* do_device_index has already called reply_with_error */
    goto done;

  guestfs_DeviceIndex_ret ret;
  char *bufret;
  size_t lenret;
  device_index__init (&ret);
  ret.index = r;
  lenret = device_index__get_packed_size (&ret);
  bufret = malloc (lenret);
  device_index__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
nr_devices_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_nr_devices ();
  if (r == -1)
    /* do_nr_devices has already called reply_with_error */
    goto done;

  guestfs_NrDevices_ret ret;
  char *bufret;
  size_t lenret;
  nr_devices__init (&ret);
  ret.nrdisks = r;
  lenret = nr_devices__get_packed_size (&ret);
  bufret = malloc (lenret);
  nr_devices__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
done_no_free:
  return;
}

static void
xfs_info_stub (char const *data, size_t datalen)
{
  guestfs_int_xfsinfo *r;
  struct guestfs_xfs_info_args *args;
  CLEANUP_FREE char *pathordevice = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = xfs_info_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->pathordevice, pathordevice, , goto done);

  r = do_xfs_info (pathordevice);
  if (r == NULL)
    /* do_xfs_info has already called reply_with_error */
    goto done;

  guestfs_xfs_info_ret ret;
  char *bufret;
  size_t lenret;
  xfs_info__init (&ret);
  ret.info = r;
  lenret = xfs_info__get_packed_size (&ret);
  bufret = malloc (lenret);
  xfs_info__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvchange_uuid_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_pvchange_uuid_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = pvchange_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_pvchange_uuid (device);
  if (r == -1)
    /* do_pvchange_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
pvchange_uuid_all_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvchange_uuid_all ();
  if (r == -1)
    /* do_pvchange_uuid_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
vgchange_uuid_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_vgchange_uuid_args *args;
  const char *vg;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = vgchange_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vg = args->vg;

  r = do_vgchange_uuid (vg);
  if (r == -1)
    /* do_vgchange_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
vgchange_uuid_all_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgchange_uuid_all ();
  if (r == -1)
    /* do_vgchange_uuid_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
utsname_stub (char const *data, size_t datalen)
{
  guestfs_int_utsname *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_utsname ();
  if (r == NULL)
    /* do_utsname has already called reply_with_error */
    goto done;

  guestfs_utsname_ret ret;
  char *bufret;
  size_t lenret;
  utsname__init (&ret);
  ret.uts = r;
  lenret = utsname__get_packed_size (&ret);
  bufret = malloc (lenret);
  utsname__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
done_no_free:
  return;
}

static void
xfs_growfs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_xfs_growfs_args *args;
  const char *path;
  int datasec;
  int logsec;
  int rtsec;
  int64_t datasize;
  int64_t logsize;
  int64_t rtsize;
  int64_t rtextsize;
  int maxpct;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = xfs_growfs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  datasec = args->datasec;
  logsec = args->logsec;
  rtsec = args->rtsec;
  datasize = args->datasize;
  logsize = args->logsize;
  rtsize = args->rtsize;
  rtextsize = args->rtextsize;
  maxpct = args->maxpct;

  NEED_ROOT (, goto done);
  r = do_xfs_growfs (path, datasec, logsec, rtsec, datasize, logsize, rtsize, rtextsize, maxpct);
  if (r == -1)
    /* do_xfs_growfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rsync_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rsync_args *args;
  const char *src;
  const char *dest;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = rsync_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);
  archive = args->archive;
  deletedest = args->deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync (src, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rsync_in_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rsync_in_args *args;
  const char *remote;
  const char *dest;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = rsync_in_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  remote = args->remote;
  dest = args->dest;
  ABS_PATH (dest, , goto done);
  archive = args->archive;
  deletedest = args->deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync_in (remote, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rsync_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rsync_out_args *args;
  const char *src;
  const char *remote;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = rsync_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  remote = args->remote;
  archive = args->archive;
  deletedest = args->deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync_out (src, remote, archive, deletedest);
  if (r == -1)
    /* do_rsync_out has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ls0_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_ls0_args *args;
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ls0_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args->dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_ls0 (dir);
  if (r == -1)
    /* do_ls0 has already called reply_with_error */
    goto done;

  /* do_ls0 has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
fill_dir_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_fill_dir_args *args;
  const char *dir;
  int nr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = fill_dir_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args->dir;
  ABS_PATH (dir, , goto done);
  nr = args->nr;

  NEED_ROOT (, goto done);
  r = do_fill_dir (dir, nr);
  if (r == -1)
    /* do_fill_dir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
xfs_admin_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_xfs_admin_args *args;
  CLEANUP_FREE char *device = NULL;
  int extunwritten;
  int imgfile;
  int v2log;
  int projid32bit;
  int lazycounter;
  const char *label;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff80)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = xfs_admin_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  extunwritten = args->extunwritten;
  imgfile = args->imgfile;
  v2log = args->v2log;
  projid32bit = args->projid32bit;
  lazycounter = args->lazycounter;
  label = args->label;
  uuid = args->uuid;

  r = do_xfs_admin (device, extunwritten, imgfile, v2log, projid32bit, lazycounter, label, uuid);
  if (r == -1)
    /* do_xfs_admin has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_open_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_hivex_open_args *args;
  const char *filename;
  int verbose;
  int debug;
  int write;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = hivex_open_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args->filename;
  ABS_PATH (filename, , goto done);
  verbose = args->verbose;
  debug = args->debug;
  write = args->write;

  NEED_ROOT (, goto done);
  r = do_hivex_open (filename, verbose, debug, write);
  if (r == -1)
    /* do_hivex_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_close_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_hivex_close ();
  if (r == -1)
    /* do_hivex_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
hivex_root_stub (char const *data, size_t datalen)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_hivex_root ();
  if (r == -1)
    /* do_hivex_root has already called reply_with_error */
    goto done;

  guestfs_HivexRoot_ret ret;
  char *bufret;
  size_t lenret;
  hivex_root__init (&ret);
  ret.nodeh = r;
  lenret = hivex_root__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_root__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
done_no_free:
  return;
}

static void
hivex_node_name_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_hivex_node_name_args *args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_name_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;

  r = do_hivex_node_name (nodeh);
  if (r == NULL)
    /* do_hivex_node_name has already called reply_with_error */
    goto done;

  guestfs_HivexNodeName_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_name__init (&ret);
  ret.name = r;
  lenret = hivex_node_name__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_name__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_children_stub (char const *data, size_t datalen)
{
  guestfs_int_hivex_node_list *r;
  struct guestfs_hivex_node_children_args *args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_children_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;

  r = do_hivex_node_children (nodeh);
  if (r == NULL)
    /* do_hivex_node_children has already called reply_with_error */
    goto done;

  guestfs_hivex_node_children_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_children__init (&ret);
  ret.nodehs = r;
  lenret = hivex_node_children__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_children__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_get_child_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_hivex_node_get_child_args *args;
  int64_t nodeh;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_get_child_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;
  name = args->name;

  r = do_hivex_node_get_child (nodeh, name);
  if (r == -1)
    /* do_hivex_node_get_child has already called reply_with_error */
    goto done;

  guestfs_HivexNodeGetChild_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_get_child__init (&ret);
  ret.child = r;
  lenret = hivex_node_get_child__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_get_child__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_parent_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_hivex_node_parent_args *args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_parent_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;

  r = do_hivex_node_parent (nodeh);
  if (r == -1)
    /* do_hivex_node_parent has already called reply_with_error */
    goto done;

  guestfs_HivexNodeParent_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_parent__init (&ret);
  ret.parent = r;
  lenret = hivex_node_parent__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_parent__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_values_stub (char const *data, size_t datalen)
{
  guestfs_int_hivex_value_list *r;
  struct guestfs_hivex_node_values_args *args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_values_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;

  r = do_hivex_node_values (nodeh);
  if (r == NULL)
    /* do_hivex_node_values has already called reply_with_error */
    goto done;

  guestfs_hivex_node_values_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_values__init (&ret);
  ret.valuehs = r;
  lenret = hivex_node_values__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_values__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_get_value_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_hivex_node_get_value_args *args;
  int64_t nodeh;
  const char *key;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_get_value_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;
  key = args->key;

  r = do_hivex_node_get_value (nodeh, key);
  if (r == -1)
    /* do_hivex_node_get_value has already called reply_with_error */
    goto done;

  guestfs_HivexNodeGetValue_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_get_value__init (&ret);
  ret.valueh = r;
  lenret = hivex_node_get_value__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_get_value__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_value_key_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_hivex_value_key_args *args;
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_value_key_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args->valueh;

  r = do_hivex_value_key (valueh);
  if (r == NULL)
    /* do_hivex_value_key has already called reply_with_error */
    goto done;

  guestfs_HivexValueKey_ret ret;
  char *bufret;
  size_t lenret;
  hivex_value_key__init (&ret);
  ret.key = r;
  lenret = hivex_value_key__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_value_key__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_value_type_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_hivex_value_type_args *args;
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_value_type_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args->valueh;

  r = do_hivex_value_type (valueh);
  if (r == -1)
    /* do_hivex_value_type has already called reply_with_error */
    goto done;

  guestfs_HivexValueType_ret ret;
  char *bufret;
  size_t lenret;
  hivex_value_type__init (&ret);
  ret.datatype = r;
  lenret = hivex_value_type__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_value_type__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_value_value_stub (char const *data, size_t datalen)
{
  size_t size = 1;
  char *r;
  struct guestfs_hivex_value_value_args *args;
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_value_value_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args->valueh;

  r = do_hivex_value_value (valueh, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_hivex_value_value has already called reply_with_error */
    goto done;

  guestfs_HivexValueValue_ret ret;
  char *bufret;
  size_t lenret;
  hivex_value_value__init (&ret);
  ret.databuf.data = r;
  ret.databuf.len = size;
  lenret = hivex_value_value__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_value_value__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_commit_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_hivex_commit_args *args;
  const char *filename;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_commit_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args->filename ? *args->filename : NULL;

  r = do_hivex_commit (filename);
  if (r == -1)
    /* do_hivex_commit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_add_child_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_hivex_node_add_child_args *args;
  int64_t parent;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_add_child_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  parent = args->parent;
  name = args->name;

  r = do_hivex_node_add_child (parent, name);
  if (r == -1)
    /* do_hivex_node_add_child has already called reply_with_error */
    goto done;

  guestfs_HivexNodeAddChild_ret ret;
  char *bufret;
  size_t lenret;
  hivex_node_add_child__init (&ret);
  ret.nodeh = r;
  lenret = hivex_node_add_child__get_packed_size (&ret);
  bufret = malloc (lenret);
  hivex_node_add_child__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_delete_child_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_hivex_node_delete_child_args *args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_delete_child_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;

  r = do_hivex_node_delete_child (nodeh);
  if (r == -1)
    /* do_hivex_node_delete_child has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
hivex_node_set_value_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_hivex_node_set_value_args *args;
  int64_t nodeh;
  const char *key;
  int64_t t;
  const char *val;
  size_t val_size;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = hivex_node_set_value_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args->nodeh;
  key = args->key;
  t = args->t;
  val = args->val.data;
  val_size = args->val.len;

  r = do_hivex_node_set_value (nodeh, key, t, val, val_size);
  if (r == -1)
    /* do_hivex_node_set_value has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
xfs_repair_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_xfs_repair_args *args;
  CLEANUP_FREE char *device = NULL;
  int forcelogzero;
  int nomodify;
  int noprefetch;
  int forcegeometry;
  int64_t maxmem;
  int64_t ihashsize;
  int64_t bhashsize;
  int64_t agstride;
  const char *logdev;
  const char *rtdev;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = xfs_repair_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args->device, device, , goto done);
  forcelogzero = args->forcelogzero;
  nomodify = args->nomodify;
  noprefetch = args->noprefetch;
  forcegeometry = args->forcegeometry;
  maxmem = args->maxmem;
  ihashsize = args->ihashsize;
  bhashsize = args->bhashsize;
  agstride = args->agstride;
  logdev = args->logdev;
  rtdev = args->rtdev;

  r = do_xfs_repair (device, forcelogzero, nomodify, noprefetch, forcegeometry, maxmem, ihashsize, bhashsize, agstride, logdev, rtdev);
  if (r == -1)
    /* do_xfs_repair has already called reply_with_error */
    goto done;

  guestfs_XfsRepair_ret ret;
  char *bufret;
  size_t lenret;
  xfs_repair__init (&ret);
  ret.status = r;
  lenret = xfs_repair__get_packed_size (&ret);
  bufret = malloc (lenret);
  xfs_repair__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rm_f_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rm_f_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = rm_f_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm_f (path);
  if (r == -1)
    /* do_rm_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mke2fs_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mke2fs_args *args;
  CLEANUP_FREE char *device = NULL;
  int64_t blockscount;
  int64_t blocksize;
  int64_t fragsize;
  int64_t blockspergroup;
  int64_t numberofgroups;
  int64_t bytesperinode;
  int64_t inodesize;
  int64_t journalsize;
  int64_t numberofinodes;
  int64_t stridesize;
  int64_t stripewidth;
  int64_t maxonlineresize;
  int reservedblockspercentage;
  int mmpupdateinterval;
  const char *journaldevice;
  const char *label;
  const char *lastmounteddir;
  const char *creatoros;
  const char *fstype;
  const char *usagetype;
  const char *uuid;
  int forcecreate;
  int writesbandgrouponly;
  int lazyitableinit;
  int lazyjournalinit;
  int testfs;
  int discard;
  int quotatype;
  int extent;
  int filetype;
  int flexbg;
  int hasjournal;
  int journaldev;
  int largefile;
  int quota;
  int resizeinode;
  int sparsesuper;
  int uninitbg;

  if (optargs_bitmask & UINT64_C(0xffffffc000000000)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = mke2fs_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  blockscount = args->blockscount;
  blocksize = args->blocksize;
  fragsize = args->fragsize;
  blockspergroup = args->blockspergroup;
  numberofgroups = args->numberofgroups;
  bytesperinode = args->bytesperinode;
  inodesize = args->inodesize;
  journalsize = args->journalsize;
  numberofinodes = args->numberofinodes;
  stridesize = args->stridesize;
  stripewidth = args->stripewidth;
  maxonlineresize = args->maxonlineresize;
  reservedblockspercentage = args->reservedblockspercentage;
  mmpupdateinterval = args->mmpupdateinterval;
  journaldevice = args->journaldevice;
  label = args->label;
  lastmounteddir = args->lastmounteddir;
  creatoros = args->creatoros;
  fstype = args->fstype;
  usagetype = args->usagetype;
  uuid = args->uuid;
  forcecreate = args->forcecreate;
  writesbandgrouponly = args->writesbandgrouponly;
  lazyitableinit = args->lazyitableinit;
  lazyjournalinit = args->lazyjournalinit;
  testfs = args->testfs;
  discard = args->discard;
  quotatype = args->quotatype;
  extent = args->extent;
  filetype = args->filetype;
  flexbg = args->flexbg;
  hasjournal = args->hasjournal;
  journaldev = args->journaldev;
  largefile = args->largefile;
  quota = args->quota;
  resizeinode = args->resizeinode;
  sparsesuper = args->sparsesuper;
  uninitbg = args->uninitbg;

  r = do_mke2fs (device, blockscount, blocksize, fragsize, blockspergroup, numberofgroups, bytesperinode, inodesize, journalsize, numberofinodes, stridesize, stripewidth, maxonlineresize, reservedblockspercentage, mmpupdateinterval, journaldevice, label, lastmounteddir, creatoros, fstype, usagetype, uuid, forcecreate, writesbandgrouponly, lazyitableinit, lazyjournalinit, testfs, discard, quotatype, extent, filetype, flexbg, hasjournal, journaldev, largefile, quota, resizeinode, sparsesuper, uninitbg);
  if (r == -1)
    /* do_mke2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
list_disk_labels_stub (char const *data, size_t datalen)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_disk_labels ();
  if (r == NULL)
    /* do_list_disk_labels has already called reply_with_error */
    goto done;

  guestfs_ListDiskLabels_ret ret;
  char *bufret;
  size_t lenret;
  list_disk_labels__init (&ret);
  ret.n_labels = count_strings (r);
  ret.labels = r;
  lenret = list_disk_labels__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_disk_labels__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
internal_hot_add_drive_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_hot_add_drive_args *args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_hot_add_drive_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;

  r = do_internal_hot_add_drive (label);
  if (r == -1)
    /* do_internal_hot_add_drive has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_hot_remove_drive_precheck_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_hot_remove_drive_precheck_args *args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_hot_remove_drive_precheck_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;

  r = do_internal_hot_remove_drive_precheck (label);
  if (r == -1)
    /* do_internal_hot_remove_drive_precheck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_hot_remove_drive_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_hot_remove_drive_args *args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_hot_remove_drive_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args->label;

  r = do_internal_hot_remove_drive (label);
  if (r == -1)
    /* do_internal_hot_remove_drive has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mktemp_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_mktemp_args *args;
  const char *tmpl;
  const char *suffix;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = mktemp_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpl = args->tmpl;
  ABS_PATH (tmpl, , goto done);
  suffix = args->suffix;

  NEED_ROOT (, goto done);
  r = do_mktemp (tmpl, suffix);
  if (r == NULL)
    /* do_mktemp has already called reply_with_error */
    goto done;

  guestfs_Mktemp_ret ret;
  char *bufret;
  size_t lenret;
  mktemp__init (&ret);
  ret.path = r;
  lenret = mktemp__get_packed_size (&ret);
  bufret = malloc (lenret);
  mktemp__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
mklost_and_found_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_mklost_and_found_args *args;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = mklost_and_found_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args->mountpoint;
  ABS_PATH (mountpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_mklost_and_found (mountpoint);
  if (r == -1)
    /* do_mklost_and_found has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
acl_get_file_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_acl_get_file_args *args;
  const char *path;
  const char *acltype;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = acl_get_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  acltype = args->acltype;

  NEED_ROOT (, goto done);
  r = do_acl_get_file (path, acltype);
  if (r == NULL)
    /* do_acl_get_file has already called reply_with_error */
    goto done;

  guestfs_AclGetFile_ret ret;
  char *bufret;
  size_t lenret;
  acl_get_file__init (&ret);
  ret.acl = r;
  lenret = acl_get_file__get_packed_size (&ret);
  bufret = malloc (lenret);
  acl_get_file__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
acl_set_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_acl_set_file_args *args;
  const char *path;
  const char *acltype;
  const char *acl;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = acl_set_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  acltype = args->acltype;
  acl = args->acl;

  NEED_ROOT (, goto done);
  r = do_acl_set_file (path, acltype, acl);
  if (r == -1)
    /* do_acl_set_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
acl_delete_def_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_acl_delete_def_file_args *args;
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = acl_delete_def_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args->dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_acl_delete_def_file (dir);
  if (r == -1)
    /* do_acl_delete_def_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
cap_get_file_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_cap_get_file_args *args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = cap_get_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_cap_get_file (path);
  if (r == NULL)
    /* do_cap_get_file has already called reply_with_error */
    goto done;

  guestfs_CapGetFile_ret ret;
  char *bufret;
  size_t lenret;
  cap_get_file__init (&ret);
  ret.cap = r;
  lenret = cap_get_file__get_packed_size (&ret);
  bufret = malloc (lenret);
  cap_get_file__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
cap_set_file_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_cap_set_file_args *args;
  const char *path;
  const char *cap;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = cap_set_file_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  cap = args->cap;

  NEED_ROOT (, goto done);
  r = do_cap_set_file (path, cap);
  if (r == -1)
    /* do_cap_set_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
list_ldm_volumes_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_ldm_volumes ();
  if (r == NULL)
    /* do_list_ldm_volumes has already called reply_with_error */
    goto done;

  guestfs_ListLdmVolumes_ret ret;
  char *bufret;
  size_t lenret;
  list_ldm_volumes__init (&ret);
  ret.n_devices = count_strings (r);
  ret.devices = r;
  lenret = list_ldm_volumes__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_ldm_volumes__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
list_ldm_partitions_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_ldm_partitions ();
  if (r == NULL)
    /* do_list_ldm_partitions has already called reply_with_error */
    goto done;

  guestfs_ListLdmPartitions_ret ret;
  char *bufret;
  size_t lenret;
  list_ldm_partitions__init (&ret);
  ret.n_devices = count_strings (r);
  ret.devices = r;
  lenret = list_ldm_partitions__get_packed_size (&ret);
  bufret = malloc (lenret);
  list_ldm_partitions__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
ldmtool_create_all_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_create_all ();
  if (r == -1)
    /* do_ldmtool_create_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
ldmtool_remove_all_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_remove_all ();
  if (r == -1)
    /* do_ldmtool_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
ldmtool_scan_stub (char const *data, size_t datalen)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_scan ();
  if (r == NULL)
    /* do_ldmtool_scan has already called reply_with_error */
    goto done;

  guestfs_LdmtoolScan_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_scan__init (&ret);
  ret.n_guids = count_strings (r);
  ret.guids = r;
  lenret = ldmtool_scan__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_scan__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
ldmtool_scan_devices_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_ldmtool_scan_devices_args *args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_scan_devices_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args->n_devices+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args->n_devices; ++i)
      RESOLVE_DEVICE (args->devices[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }

  r = do_ldmtool_scan_devices (devices);
  if (r == NULL)
    /* do_ldmtool_scan_devices has already called reply_with_error */
    goto done;

  guestfs_LdmtoolScanDevices_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_scan_devices__init (&ret);
  ret.n_guids = count_strings (r);
  ret.guids = r;
  lenret = ldmtool_scan_devices__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_scan_devices__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ldmtool_diskgroup_name_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_ldmtool_diskgroup_name_args *args;
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_diskgroup_name_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args->diskgroup;

  r = do_ldmtool_diskgroup_name (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_name has already called reply_with_error */
    goto done;

  guestfs_LdmtoolDiskgroupName_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_diskgroup_name__init (&ret);
  ret.name = r;
  lenret = ldmtool_diskgroup_name__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_diskgroup_name__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ldmtool_diskgroup_volumes_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_ldmtool_diskgroup_volumes_args *args;
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_diskgroup_volumes_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args->diskgroup;

  r = do_ldmtool_diskgroup_volumes (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_volumes has already called reply_with_error */
    goto done;

  guestfs_LdmtoolDiskgroupVolumes_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_diskgroup_volumes__init (&ret);
  ret.n_volumes = count_strings (r);
  ret.volumes = r;
  lenret = ldmtool_diskgroup_volumes__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_diskgroup_volumes__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ldmtool_diskgroup_disks_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_ldmtool_diskgroup_disks_args *args;
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_diskgroup_disks_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args->diskgroup;

  r = do_ldmtool_diskgroup_disks (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_disks has already called reply_with_error */
    goto done;

  guestfs_LdmtoolDiskgroupDisks_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_diskgroup_disks__init (&ret);
  ret.n_disks = count_strings (r);
  ret.disks = r;
  lenret = ldmtool_diskgroup_disks__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_diskgroup_disks__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ldmtool_volume_type_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_ldmtool_volume_type_args *args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_volume_type_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args->diskgroup;
  volume = args->volume;

  r = do_ldmtool_volume_type (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_type has already called reply_with_error */
    goto done;

  guestfs_LdmtoolVolumeType_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_volume_type__init (&ret);
  ret.voltype = r;
  lenret = ldmtool_volume_type__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_volume_type__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ldmtool_volume_hint_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_ldmtool_volume_hint_args *args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_volume_hint_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args->diskgroup;
  volume = args->volume;

  r = do_ldmtool_volume_hint (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_hint has already called reply_with_error */
    goto done;

  guestfs_LdmtoolVolumeHint_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_volume_hint__init (&ret);
  ret.hint = r;
  lenret = ldmtool_volume_hint__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_volume_hint__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
ldmtool_volume_partitions_stub (char const *data, size_t datalen)
{
  char **r;
  struct guestfs_ldmtool_volume_partitions_args *args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = ldmtool_volume_partitions_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args->diskgroup;
  volume = args->volume;

  r = do_ldmtool_volume_partitions (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_partitions has already called reply_with_error */
    goto done;

  guestfs_LdmtoolVolumePartitions_ret ret;
  char *bufret;
  size_t lenret;
  ldmtool_volume_partitions__init (&ret);
  ret.n_partitions = count_strings (r);
  ret.partitions = r;
  lenret = ldmtool_volume_partitions__get_packed_size (&ret);
  bufret = malloc (lenret);
  ldmtool_volume_partitions__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free_strings (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_set_gpt_type_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_part_set_gpt_type_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *guid;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_set_gpt_type_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;
  guid = args->guid;

  r = do_part_set_gpt_type (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_type has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_get_gpt_type_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_part_get_gpt_type_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_get_gpt_type_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;

  r = do_part_get_gpt_type (device, partnum);
  if (r == NULL)
    /* do_part_get_gpt_type has already called reply_with_error */
    goto done;

  guestfs_PartGetGptType_ret ret;
  char *bufret;
  size_t lenret;
  part_get_gpt_type__init (&ret);
  ret.guid = r;
  lenret = part_get_gpt_type__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_get_gpt_type__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
rename_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_rename_args *args;
  const char *oldpath;
  const char *newpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = rename_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  oldpath = args->oldpath;
  ABS_PATH (oldpath, , goto done);
  newpath = args->newpath;
  ABS_PATH (newpath, , goto done);

  NEED_ROOT (, goto done);
  r = do_rename (oldpath, newpath);
  if (r == -1)
    /* do_rename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
is_whole_device_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_is_whole_device_args *args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = is_whole_device_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_is_whole_device (device);
  if (r == -1)
    /* do_is_whole_device has already called reply_with_error */
    goto done;

  guestfs_IsWholeDevice_ret ret;
  char *bufret;
  size_t lenret;
  is_whole_device__init (&ret);
  ret.flag = r;
  lenret = is_whole_device__get_packed_size (&ret);
  bufret = malloc (lenret);
  is_whole_device__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_parse_mountable_stub (char const *data, size_t datalen)
{
  guestfs_int_internal_mountable *r;
  struct guestfs_internal_parse_mountable_args *args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_parse_mountable_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args->mountable, mountable, , goto done);

  r = do_internal_parse_mountable (&mountable);
  if (r == NULL)
    /* do_internal_parse_mountable has already called reply_with_error */
    goto done;

  guestfs_internal_parse_mountable_ret ret;
  char *bufret;
  size_t lenret;
  internal_parse_mountable__init (&ret);
  ret.mountable = r;
  lenret = internal_parse_mountable__get_packed_size (&ret);
  bufret = malloc (lenret);
  internal_parse_mountable__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_rhbz914931_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_rhbz914931_args *args;
  int count;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_rhbz914931_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  count = args->count;

  r = do_internal_rhbz914931 (count);
  if (r == -1)
    /* do_internal_rhbz914931 has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
feature_available_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_feature_available_args *args;
  char **groups;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = feature_available_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  groups = realloc (args->groups,
                sizeof (char *) * (args->n_groups+1));
  if (groups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  groups[args->n_groups] = NULL;
  args->groups = groups;

  r = do_feature_available (groups);
  if (r == -1)
    /* do_feature_available has already called reply_with_error */
    goto done;

  guestfs_FeatureAvailable_ret ret;
  char *bufret;
  size_t lenret;
  feature_available__init (&ret);
  ret.isavailable = r;
  lenret = feature_available__get_packed_size (&ret);
  bufret = malloc (lenret);
  feature_available__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
syslinux_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_syslinux_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_syslinux_available ()) {
    reply_with_unavailable_feature ("syslinux");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = syslinux_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  directory = args->directory;

  r = do_syslinux (device, directory);
  if (r == -1)
    /* do_syslinux has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
extlinux_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_extlinux_args *args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_extlinux_available ()) {
    reply_with_unavailable_feature ("extlinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = extlinux_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_extlinux (directory);
  if (r == -1)
    /* do_extlinux has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
cp_r_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_cp_r_args *args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = cp_r_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp_r (src, dest);
  if (r == -1)
    /* do_cp_r has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
remount_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_remount_args *args;
  const char *mountpoint;
  int rw;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = remount_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args->mountpoint;
  ABS_PATH (mountpoint, , goto done);
  rw = args->rw;

  NEED_ROOT (, goto done);
  r = do_remount (mountpoint, rw);
  if (r == -1)
    /* do_remount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
set_uuid_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_set_uuid_args *args;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = set_uuid_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  uuid = args->uuid;

  r = do_set_uuid (device, uuid);
  if (r == -1)
    /* do_set_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
journal_open_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_journal_open_args *args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = journal_open_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_journal_open (directory);
  if (r == -1)
    /* do_journal_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
journal_close_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_close ();
  if (r == -1)
    /* do_journal_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
journal_next_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_next ();
  if (r == -1)
    /* do_journal_next has already called reply_with_error */
    goto done;

  guestfs_JournalNext_ret ret;
  char *bufret;
  size_t lenret;
  journal_next__init (&ret);
  ret.more = r;
  lenret = journal_next__get_packed_size (&ret);
  bufret = malloc (lenret);
  journal_next__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
done_no_free:
  return;
}

static void
journal_skip_stub (char const *data, size_t datalen)
{
  int64_t r;
  struct guestfs_journal_skip_args *args;
  int64_t skip;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = journal_skip_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  skip = args->skip;

  r = do_journal_skip (skip);
  if (r == -1)
    /* do_journal_skip has already called reply_with_error */
    goto done;

  guestfs_JournalSkip_ret ret;
  char *bufret;
  size_t lenret;
  journal_skip__init (&ret);
  ret.rskip = r;
  lenret = journal_skip__get_packed_size (&ret);
  bufret = malloc (lenret);
  journal_skip__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_journal_get_stub (char const *data, size_t datalen)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_journal_get ();
  if (r == -1)
    /* do_internal_journal_get has already called reply_with_error */
    goto done;

  /* do_internal_journal_get has already sent a reply */
done:
done_no_free:
  return;
}

static void
journal_get_data_threshold_stub (char const *data, size_t datalen)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_get_data_threshold ();
  if (r == -1)
    /* do_journal_get_data_threshold has already called reply_with_error */
    goto done;

  guestfs_JournalGetDataThreshold_ret ret;
  char *bufret;
  size_t lenret;
  journal_get_data_threshold__init (&ret);
  ret.threshold = r;
  lenret = journal_get_data_threshold__get_packed_size (&ret);
  bufret = malloc (lenret);
  journal_get_data_threshold__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
done_no_free:
  return;
}

static void
journal_set_data_threshold_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_journal_set_data_threshold_args *args;
  int64_t threshold;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = journal_set_data_threshold_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  threshold = args->threshold;

  r = do_journal_set_data_threshold (threshold);
  if (r == -1)
    /* do_journal_set_data_threshold has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_setm_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_aug_setm_args *args;
  const char *bbase;
  const char *sub;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_setm_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  bbase = args->bbase;
  sub = args->sub ? *args->sub : NULL;
  val = args->val;

  r = do_aug_setm (bbase, sub, val);
  if (r == -1)
    /* do_aug_setm has already called reply_with_error */
    goto done;

  guestfs_AugSetm_ret ret;
  char *bufret;
  size_t lenret;
  aug_setm__init (&ret);
  ret.nodes = r;
  lenret = aug_setm__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_setm__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
aug_label_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_aug_label_args *args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = aug_label_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args->augpath;

  r = do_aug_label (augpath);
  if (r == NULL)
    /* do_aug_label has already called reply_with_error */
    goto done;

  guestfs_AugLabel_ret ret;
  char *bufret;
  size_t lenret;
  aug_label__init (&ret);
  ret.label = r;
  lenret = aug_label__get_packed_size (&ret);
  bufret = malloc (lenret);
  aug_label__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_upload_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_internal_upload_args *args;
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_upload_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpname = args->tmpname;
  mode = args->mode;

  r = do_internal_upload (tmpname, mode);
  if (r == -1)
    /* do_internal_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_exit_stub (char const *data, size_t datalen)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_exit ();
  if (r == -1)
    /* do_internal_exit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
copy_attributes_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_copy_attributes_args *args;
  const char *src;
  const char *dest;
  int all;
  int mode;
  int xattributes;
  int ownership;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = copy_attributes_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args->src;
  ABS_PATH (src, , goto done);
  dest = args->dest;
  ABS_PATH (dest, , goto done);
  all = args->all;
  mode = args->mode;
  xattributes = args->xattributes;
  ownership = args->ownership;

  NEED_ROOT (, goto done);
  r = do_copy_attributes (src, dest, all, mode, xattributes, ownership);
  if (r == -1)
    /* do_copy_attributes has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
part_get_name_stub (char const *data, size_t datalen)
{
  char *r;
  struct guestfs_part_get_name_args *args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = part_get_name_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);
  partnum = args->partnum;

  r = do_part_get_name (device, partnum);
  if (r == NULL)
    /* do_part_get_name has already called reply_with_error */
    goto done;

  guestfs_PartGetName_ret ret;
  char *bufret;
  size_t lenret;
  part_get_name__init (&ret);
  ret.name = r;
  lenret = part_get_name__get_packed_size (&ret);
  bufret = malloc (lenret);
  part_get_name__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blkdiscard_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blkdiscard_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscard_available ()) {
    reply_with_unavailable_feature ("blkdiscard");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blkdiscard_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blkdiscard (device);
  if (r == -1)
    /* do_blkdiscard has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  free (bufret);
done_no_free:
  return;
}

static void
blkdiscardzeroes_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_blkdiscardzeroes_args *args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscardzeroes_available ()) {
    reply_with_unavailable_feature ("blkdiscardzeroes");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = blkdiscardzeroes_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args->device, device, , goto done);

  r = do_blkdiscardzeroes (device);
  if (r == -1)
    /* do_blkdiscardzeroes has already called reply_with_error */
    goto done;

  guestfs_Blkdiscardzeroes_ret ret;
  char *bufret;
  size_t lenret;
  blkdiscardzeroes__init (&ret);
  ret.zeroes = r;
  lenret = blkdiscardzeroes__get_packed_size (&ret);
  bufret = malloc (lenret);
  blkdiscardzeroes__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
  free (bufret);
done_no_free:
  return;
}

static void
cpio_out_stub (char const *data, size_t datalen)
{
  int r;
  struct guestfs_cpio_out_args *args;
  const char *directory;
  const char *format;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  if (!(args = cpio_out_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args->directory;
  format = args->format;

  r = do_cpio_out (directory, format);
  if (r == -1)
    /* do_cpio_out has already called reply_with_error */
    goto done;

  /* do_cpio_out has already sent a reply */
done:
  free (bufret);
done_no_free:
  return;
}

static void
journal_get_realtime_usec_stub (char const *data, size_t datalen)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_get_realtime_usec ();
  if (r == -1)
    /* do_journal_get_realtime_usec has already called reply_with_error */
    goto done;

  guestfs_JournalGetRealtimeUsec_ret ret;
  char *bufret;
  size_t lenret;
  journal_get_realtime_usec__init (&ret);
  ret.usec = r;
  lenret = journal_get_realtime_usec__get_packed_size (&ret);
  bufret = malloc (lenret);
  journal_get_realtime_usec__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
done:
done_no_free:
  return;
}

static void
statns_stub (char const *data, size_t datalen)
{
  guestfs_int_statns *r;
  struct guestfs_statns_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = statns_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_statns (path);
  if (r == NULL)
    /* do_statns has already called reply_with_error */
    goto done;

  guestfs_statns_ret ret;
  char *bufret;
  size_t lenret;
  statns__init (&ret);
  ret.statbuf = r;
  lenret = statns__get_packed_size (&ret);
  bufret = malloc (lenret);
  statns__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
lstatns_stub (char const *data, size_t datalen)
{
  guestfs_int_statns *r;
  struct guestfs_lstatns_args *args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = lstatns_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lstatns (path);
  if (r == NULL)
    /* do_lstatns has already called reply_with_error */
    goto done;

  guestfs_lstatns_ret ret;
  char *bufret;
  size_t lenret;
  lstatns__init (&ret);
  ret.statbuf = r;
  lenret = lstatns__get_packed_size (&ret);
  bufret = malloc (lenret);
  lstatns__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

static void
internal_lstatnslist_stub (char const *data, size_t datalen)
{
  guestfs_int_statns_list *r;
  struct guestfs_internal_lstatnslist_args *args;
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  if (!(args = internal_lstatnslist_args__unpack (NULL, datalen, (const uint8_t *)data))) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args->path;
  ABS_PATH (path, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args->names,
                sizeof (char *) * (args->n_names+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args->n_names] = NULL;
  args->names = names;

  NEED_ROOT (, goto done);
  r = do_internal_lstatnslist (path, names);
  if (r == NULL)
    /* do_internal_lstatnslist has already called reply_with_error */
    goto done;

  guestfs_internal_lstatnslist_ret ret;
  char *bufret;
  size_t lenret;
  internal_lstatnslist__init (&ret);
  ret.statbufs = r;
  lenret = internal_lstatnslist__get_packed_size (&ret);
  bufret = malloc (lenret);
  internal_lstatnslist__pack (NULL, lenret, bufret);
  reply (bufret, lenret);
  free (bufret);
  free (r);
done:
  free (bufret);
done_no_free:
  return;
}

void dispatch_incoming_message (const char *data, size_t datalen)
{
  switch (proc_nr) {
    case GUESTFS_PROC_MOUNT:
      mount_stub (data, datalen);
      break;
    case GUESTFS_PROC_SYNC:
      sync_stub (data, datalen);
      break;
    case GUESTFS_PROC_TOUCH:
      touch_stub (data, datalen);
      break;
    case GUESTFS_PROC_LL:
      ll_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_DEVICES:
      list_devices_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_PARTITIONS:
      list_partitions_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVS:
      pvs_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGS:
      vgs_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVS:
      lvs_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVS_FULL:
      pvs_full_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGS_FULL:
      vgs_full_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVS_FULL:
      lvs_full_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_INIT:
      aug_init_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_CLOSE:
      aug_close_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_DEFVAR:
      aug_defvar_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_DEFNODE:
      aug_defnode_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_GET:
      aug_get_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_SET:
      aug_set_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_INSERT:
      aug_insert_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_RM:
      aug_rm_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_MV:
      aug_mv_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_MATCH:
      aug_match_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_SAVE:
      aug_save_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_LOAD:
      aug_load_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_LS:
      aug_ls_stub (data, datalen);
      break;
    case GUESTFS_PROC_RM:
      rm_stub (data, datalen);
      break;
    case GUESTFS_PROC_RMDIR:
      rmdir_stub (data, datalen);
      break;
    case GUESTFS_PROC_RM_RF:
      rm_rf_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKDIR:
      mkdir_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKDIR_P:
      mkdir_p_stub (data, datalen);
      break;
    case GUESTFS_PROC_CHMOD:
      chmod_stub (data, datalen);
      break;
    case GUESTFS_PROC_CHOWN:
      chown_stub (data, datalen);
      break;
    case GUESTFS_PROC_EXISTS:
      exists_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_FILE:
      is_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_DIR:
      is_dir_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVCREATE:
      pvcreate_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGCREATE:
      vgcreate_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVCREATE:
      lvcreate_stub (data, datalen);
      break;
    case GUESTFS_PROC_SFDISK:
      sfdisk_stub (data, datalen);
      break;
    case GUESTFS_PROC_WRITE_FILE:
      write_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_UMOUNT:
      umount_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNTS:
      mounts_stub (data, datalen);
      break;
    case GUESTFS_PROC_UMOUNT_ALL:
      umount_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVM_REMOVE_ALL:
      lvm_remove_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_FILE:
      file_stub (data, datalen);
      break;
    case GUESTFS_PROC_COMMAND:
      command_stub (data, datalen);
      break;
    case GUESTFS_PROC_COMMAND_LINES:
      command_lines_stub (data, datalen);
      break;
    case GUESTFS_PROC_STATVFS:
      statvfs_stub (data, datalen);
      break;
    case GUESTFS_PROC_TUNE2FS_L:
      tune2fs_l_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRO:
      blockdev_setro_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRW:
      blockdev_setrw_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETRO:
      blockdev_getro_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSS:
      blockdev_getss_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETBSZ:
      blockdev_getbsz_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETBSZ:
      blockdev_setbsz_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSZ:
      blockdev_getsz_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSIZE64:
      blockdev_getsize64_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_FLUSHBUFS:
      blockdev_flushbufs_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLOCKDEV_REREADPT:
      blockdev_rereadpt_stub (data, datalen);
      break;
    case GUESTFS_PROC_UPLOAD:
      upload_stub (data, datalen);
      break;
    case GUESTFS_PROC_DOWNLOAD:
      download_stub (data, datalen);
      break;
    case GUESTFS_PROC_CHECKSUM:
      checksum_stub (data, datalen);
      break;
    case GUESTFS_PROC_TAR_IN:
      tar_in_stub (data, datalen);
      break;
    case GUESTFS_PROC_TAR_OUT:
      tar_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_TGZ_IN:
      tgz_in_stub (data, datalen);
      break;
    case GUESTFS_PROC_TGZ_OUT:
      tgz_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNT_RO:
      mount_ro_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNT_OPTIONS:
      mount_options_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNT_VFS:
      mount_vfs_stub (data, datalen);
      break;
    case GUESTFS_PROC_DEBUG:
      debug_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVREMOVE:
      lvremove_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGREMOVE:
      vgremove_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVREMOVE:
      pvremove_stub (data, datalen);
      break;
    case GUESTFS_PROC_SET_E2LABEL:
      set_e2label_stub (data, datalen);
      break;
    case GUESTFS_PROC_GET_E2LABEL:
      get_e2label_stub (data, datalen);
      break;
    case GUESTFS_PROC_SET_E2UUID:
      set_e2uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_GET_E2UUID:
      get_e2uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_FSCK:
      fsck_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZERO:
      zero_stub (data, datalen);
      break;
    case GUESTFS_PROC_GRUB_INSTALL:
      grub_install_stub (data, datalen);
      break;
    case GUESTFS_PROC_CP:
      cp_stub (data, datalen);
      break;
    case GUESTFS_PROC_CP_A:
      cp_a_stub (data, datalen);
      break;
    case GUESTFS_PROC_MV:
      mv_stub (data, datalen);
      break;
    case GUESTFS_PROC_DROP_CACHES:
      drop_caches_stub (data, datalen);
      break;
    case GUESTFS_PROC_DMESG:
      dmesg_stub (data, datalen);
      break;
    case GUESTFS_PROC_PING_DAEMON:
      ping_daemon_stub (data, datalen);
      break;
    case GUESTFS_PROC_EQUAL:
      equal_stub (data, datalen);
      break;
    case GUESTFS_PROC_STRINGS:
      strings_stub (data, datalen);
      break;
    case GUESTFS_PROC_STRINGS_E:
      strings_e_stub (data, datalen);
      break;
    case GUESTFS_PROC_HEXDUMP:
      hexdump_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZEROFREE:
      zerofree_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVRESIZE:
      pvresize_stub (data, datalen);
      break;
    case GUESTFS_PROC_SFDISK_N:
      sfdisk_N_stub (data, datalen);
      break;
    case GUESTFS_PROC_SFDISK_L:
      sfdisk_l_stub (data, datalen);
      break;
    case GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY:
      sfdisk_kernel_geometry_stub (data, datalen);
      break;
    case GUESTFS_PROC_SFDISK_DISK_GEOMETRY:
      sfdisk_disk_geometry_stub (data, datalen);
      break;
    case GUESTFS_PROC_VG_ACTIVATE_ALL:
      vg_activate_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_VG_ACTIVATE:
      vg_activate_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVRESIZE:
      lvresize_stub (data, datalen);
      break;
    case GUESTFS_PROC_RESIZE2FS:
      resize2fs_stub (data, datalen);
      break;
    case GUESTFS_PROC_E2FSCK_F:
      e2fsck_f_stub (data, datalen);
      break;
    case GUESTFS_PROC_SLEEP:
      sleep_stub (data, datalen);
      break;
    case GUESTFS_PROC_NTFS_3G_PROBE:
      ntfs_3g_probe_stub (data, datalen);
      break;
    case GUESTFS_PROC_SH:
      sh_stub (data, datalen);
      break;
    case GUESTFS_PROC_SH_LINES:
      sh_lines_stub (data, datalen);
      break;
    case GUESTFS_PROC_GLOB_EXPAND:
      glob_expand_stub (data, datalen);
      break;
    case GUESTFS_PROC_SCRUB_DEVICE:
      scrub_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_SCRUB_FILE:
      scrub_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_SCRUB_FREESPACE:
      scrub_freespace_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKDTEMP:
      mkdtemp_stub (data, datalen);
      break;
    case GUESTFS_PROC_WC_L:
      wc_l_stub (data, datalen);
      break;
    case GUESTFS_PROC_WC_W:
      wc_w_stub (data, datalen);
      break;
    case GUESTFS_PROC_WC_C:
      wc_c_stub (data, datalen);
      break;
    case GUESTFS_PROC_HEAD:
      head_stub (data, datalen);
      break;
    case GUESTFS_PROC_HEAD_N:
      head_n_stub (data, datalen);
      break;
    case GUESTFS_PROC_TAIL:
      tail_stub (data, datalen);
      break;
    case GUESTFS_PROC_TAIL_N:
      tail_n_stub (data, datalen);
      break;
    case GUESTFS_PROC_DF:
      df_stub (data, datalen);
      break;
    case GUESTFS_PROC_DF_H:
      df_h_stub (data, datalen);
      break;
    case GUESTFS_PROC_DU:
      du_stub (data, datalen);
      break;
    case GUESTFS_PROC_INITRD_LIST:
      initrd_list_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNT_LOOP:
      mount_loop_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKSWAP:
      mkswap_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKSWAP_L:
      mkswap_L_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKSWAP_U:
      mkswap_U_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKNOD:
      mknod_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKFIFO:
      mkfifo_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKNOD_B:
      mknod_b_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKNOD_C:
      mknod_c_stub (data, datalen);
      break;
    case GUESTFS_PROC_UMASK:
      umask_stub (data, datalen);
      break;
    case GUESTFS_PROC_READDIR:
      readdir_stub (data, datalen);
      break;
    case GUESTFS_PROC_SFDISKM:
      sfdiskM_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZFILE:
      zfile_stub (data, datalen);
      break;
    case GUESTFS_PROC_GETXATTRS:
      getxattrs_stub (data, datalen);
      break;
    case GUESTFS_PROC_LGETXATTRS:
      lgetxattrs_stub (data, datalen);
      break;
    case GUESTFS_PROC_SETXATTR:
      setxattr_stub (data, datalen);
      break;
    case GUESTFS_PROC_LSETXATTR:
      lsetxattr_stub (data, datalen);
      break;
    case GUESTFS_PROC_REMOVEXATTR:
      removexattr_stub (data, datalen);
      break;
    case GUESTFS_PROC_LREMOVEXATTR:
      lremovexattr_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNTPOINTS:
      mountpoints_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKMOUNTPOINT:
      mkmountpoint_stub (data, datalen);
      break;
    case GUESTFS_PROC_RMMOUNTPOINT:
      rmmountpoint_stub (data, datalen);
      break;
    case GUESTFS_PROC_GREP:
      grep_stub (data, datalen);
      break;
    case GUESTFS_PROC_EGREP:
      egrep_stub (data, datalen);
      break;
    case GUESTFS_PROC_FGREP:
      fgrep_stub (data, datalen);
      break;
    case GUESTFS_PROC_GREPI:
      grepi_stub (data, datalen);
      break;
    case GUESTFS_PROC_EGREPI:
      egrepi_stub (data, datalen);
      break;
    case GUESTFS_PROC_FGREPI:
      fgrepi_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZGREP:
      zgrep_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZEGREP:
      zegrep_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZFGREP:
      zfgrep_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZGREPI:
      zgrepi_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZEGREPI:
      zegrepi_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZFGREPI:
      zfgrepi_stub (data, datalen);
      break;
    case GUESTFS_PROC_REALPATH:
      realpath_stub (data, datalen);
      break;
    case GUESTFS_PROC_LN:
      ln_stub (data, datalen);
      break;
    case GUESTFS_PROC_LN_F:
      ln_f_stub (data, datalen);
      break;
    case GUESTFS_PROC_LN_S:
      ln_s_stub (data, datalen);
      break;
    case GUESTFS_PROC_LN_SF:
      ln_sf_stub (data, datalen);
      break;
    case GUESTFS_PROC_READLINK:
      readlink_stub (data, datalen);
      break;
    case GUESTFS_PROC_FALLOCATE:
      fallocate_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPON_DEVICE:
      swapon_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPOFF_DEVICE:
      swapoff_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPON_FILE:
      swapon_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPOFF_FILE:
      swapoff_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPON_LABEL:
      swapon_label_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPOFF_LABEL:
      swapoff_label_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPON_UUID:
      swapon_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_SWAPOFF_UUID:
      swapoff_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKSWAP_FILE:
      mkswap_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_INOTIFY_INIT:
      inotify_init_stub (data, datalen);
      break;
    case GUESTFS_PROC_INOTIFY_ADD_WATCH:
      inotify_add_watch_stub (data, datalen);
      break;
    case GUESTFS_PROC_INOTIFY_RM_WATCH:
      inotify_rm_watch_stub (data, datalen);
      break;
    case GUESTFS_PROC_INOTIFY_READ:
      inotify_read_stub (data, datalen);
      break;
    case GUESTFS_PROC_INOTIFY_FILES:
      inotify_files_stub (data, datalen);
      break;
    case GUESTFS_PROC_INOTIFY_CLOSE:
      inotify_close_stub (data, datalen);
      break;
    case GUESTFS_PROC_SETCON:
      setcon_stub (data, datalen);
      break;
    case GUESTFS_PROC_GETCON:
      getcon_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKFS_B:
      mkfs_b_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2JOURNAL:
      mke2journal_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_L:
      mke2journal_L_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_U:
      mke2journal_U_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2FS_J:
      mke2fs_J_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2FS_JL:
      mke2fs_JL_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2FS_JU:
      mke2fs_JU_stub (data, datalen);
      break;
    case GUESTFS_PROC_MODPROBE:
      modprobe_stub (data, datalen);
      break;
    case GUESTFS_PROC_ECHO_DAEMON:
      echo_daemon_stub (data, datalen);
      break;
    case GUESTFS_PROC_FIND0:
      find0_stub (data, datalen);
      break;
    case GUESTFS_PROC_CASE_SENSITIVE_PATH:
      case_sensitive_path_stub (data, datalen);
      break;
    case GUESTFS_PROC_VFS_TYPE:
      vfs_type_stub (data, datalen);
      break;
    case GUESTFS_PROC_TRUNCATE:
      truncate_stub (data, datalen);
      break;
    case GUESTFS_PROC_TRUNCATE_SIZE:
      truncate_size_stub (data, datalen);
      break;
    case GUESTFS_PROC_UTIMENS:
      utimens_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKDIR_MODE:
      mkdir_mode_stub (data, datalen);
      break;
    case GUESTFS_PROC_LCHOWN:
      lchown_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_LXATTRLIST:
      internal_lxattrlist_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_READLINKLIST:
      internal_readlinklist_stub (data, datalen);
      break;
    case GUESTFS_PROC_PREAD:
      pread_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_INIT:
      part_init_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_ADD:
      part_add_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_DISK:
      part_disk_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_SET_BOOTABLE:
      part_set_bootable_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_SET_NAME:
      part_set_name_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_LIST:
      part_list_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_GET_PARTTYPE:
      part_get_parttype_stub (data, datalen);
      break;
    case GUESTFS_PROC_FILL:
      fill_stub (data, datalen);
      break;
    case GUESTFS_PROC_AVAILABLE:
      available_stub (data, datalen);
      break;
    case GUESTFS_PROC_DD:
      dd_stub (data, datalen);
      break;
    case GUESTFS_PROC_FILESIZE:
      filesize_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVRENAME:
      lvrename_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGRENAME:
      vgrename_stub (data, datalen);
      break;
    case GUESTFS_PROC_INITRD_CAT:
      initrd_cat_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVUUID:
      pvuuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGUUID:
      vguuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVUUID:
      lvuuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGPVUUIDS:
      vgpvuuids_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGLVUUIDS:
      vglvuuids_stub (data, datalen);
      break;
    case GUESTFS_PROC_COPY_SIZE:
      copy_size_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZERO_DEVICE:
      zero_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_TXZ_IN:
      txz_in_stub (data, datalen);
      break;
    case GUESTFS_PROC_TXZ_OUT:
      txz_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGSCAN:
      vgscan_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_DEL:
      part_del_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_GET_BOOTABLE:
      part_get_bootable_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_GET_MBR_ID:
      part_get_mbr_id_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_SET_MBR_ID:
      part_set_mbr_id_stub (data, datalen);
      break;
    case GUESTFS_PROC_CHECKSUM_DEVICE:
      checksum_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVRESIZE_FREE:
      lvresize_free_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_CLEAR:
      aug_clear_stub (data, datalen);
      break;
    case GUESTFS_PROC_GET_UMASK:
      get_umask_stub (data, datalen);
      break;
    case GUESTFS_PROC_DEBUG_UPLOAD:
      debug_upload_stub (data, datalen);
      break;
    case GUESTFS_PROC_BASE64_IN:
      base64_in_stub (data, datalen);
      break;
    case GUESTFS_PROC_BASE64_OUT:
      base64_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_CHECKSUMS_OUT:
      checksums_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_FILL_PATTERN:
      fill_pattern_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_WRITE:
      internal_write_stub (data, datalen);
      break;
    case GUESTFS_PROC_PWRITE:
      pwrite_stub (data, datalen);
      break;
    case GUESTFS_PROC_RESIZE2FS_SIZE:
      resize2fs_size_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVRESIZE_SIZE:
      pvresize_size_stub (data, datalen);
      break;
    case GUESTFS_PROC_NTFSRESIZE_SIZE:
      ntfsresize_size_stub (data, datalen);
      break;
    case GUESTFS_PROC_AVAILABLE_ALL_GROUPS:
      available_all_groups_stub (data, datalen);
      break;
    case GUESTFS_PROC_FALLOCATE64:
      fallocate64_stub (data, datalen);
      break;
    case GUESTFS_PROC_VFS_LABEL:
      vfs_label_stub (data, datalen);
      break;
    case GUESTFS_PROC_VFS_UUID:
      vfs_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVM_SET_FILTER:
      lvm_set_filter_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVM_CLEAR_FILTER:
      lvm_clear_filter_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_OPEN:
      luks_open_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_OPEN_RO:
      luks_open_ro_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_CLOSE:
      luks_close_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_FORMAT:
      luks_format_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_FORMAT_CIPHER:
      luks_format_cipher_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_ADD_KEY:
      luks_add_key_stub (data, datalen);
      break;
    case GUESTFS_PROC_LUKS_KILL_SLOT:
      luks_kill_slot_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_LV:
      is_lv_stub (data, datalen);
      break;
    case GUESTFS_PROC_FINDFS_UUID:
      findfs_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_FINDFS_LABEL:
      findfs_label_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_CHARDEV:
      is_chardev_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_BLOCKDEV:
      is_blockdev_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_FIFO:
      is_fifo_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_SYMLINK:
      is_symlink_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_SOCKET:
      is_socket_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_TO_DEV:
      part_to_dev_stub (data, datalen);
      break;
    case GUESTFS_PROC_UPLOAD_OFFSET:
      upload_offset_stub (data, datalen);
      break;
    case GUESTFS_PROC_DOWNLOAD_OFFSET:
      download_offset_stub (data, datalen);
      break;
    case GUESTFS_PROC_PWRITE_DEVICE:
      pwrite_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_PREAD_DEVICE:
      pread_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVM_CANONICAL_LV_NAME:
      lvm_canonical_lv_name_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKFS:
      mkfs_stub (data, datalen);
      break;
    case GUESTFS_PROC_GETXATTR:
      getxattr_stub (data, datalen);
      break;
    case GUESTFS_PROC_LGETXATTR:
      lgetxattr_stub (data, datalen);
      break;
    case GUESTFS_PROC_RESIZE2FS_M:
      resize2fs_M_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_AUTOSYNC:
      internal_autosync_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_ZERO:
      is_zero_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_ZERO_DEVICE:
      is_zero_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_9P:
      list_9p_stub (data, datalen);
      break;
    case GUESTFS_PROC_MOUNT_9P:
      mount_9p_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_DM_DEVICES:
      list_dm_devices_stub (data, datalen);
      break;
    case GUESTFS_PROC_NTFSRESIZE:
      ntfsresize_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE:
      btrfs_filesystem_resize_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_WRITE_APPEND:
      internal_write_append_stub (data, datalen);
      break;
    case GUESTFS_PROC_COMPRESS_OUT:
      compress_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_COMPRESS_DEVICE_OUT:
      compress_device_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_TO_PARTNUM:
      part_to_partnum_stub (data, datalen);
      break;
    case GUESTFS_PROC_COPY_DEVICE_TO_DEVICE:
      copy_device_to_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_COPY_DEVICE_TO_FILE:
      copy_device_to_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_COPY_FILE_TO_DEVICE:
      copy_file_to_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_COPY_FILE_TO_FILE:
      copy_file_to_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_TUNE2FS:
      tune2fs_stub (data, datalen);
      break;
    case GUESTFS_PROC_MD_CREATE:
      md_create_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_MD_DEVICES:
      list_md_devices_stub (data, datalen);
      break;
    case GUESTFS_PROC_MD_DETAIL:
      md_detail_stub (data, datalen);
      break;
    case GUESTFS_PROC_MD_STOP:
      md_stop_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLKID:
      blkid_stub (data, datalen);
      break;
    case GUESTFS_PROC_E2FSCK:
      e2fsck_stub (data, datalen);
      break;
    case GUESTFS_PROC_LLZ:
      llz_stub (data, datalen);
      break;
    case GUESTFS_PROC_WIPEFS:
      wipefs_stub (data, datalen);
      break;
    case GUESTFS_PROC_NTFSFIX:
      ntfsfix_stub (data, datalen);
      break;
    case GUESTFS_PROC_NTFSCLONE_OUT:
      ntfsclone_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_NTFSCLONE_IN:
      ntfsclone_in_stub (data, datalen);
      break;
    case GUESTFS_PROC_SET_LABEL:
      set_label_stub (data, datalen);
      break;
    case GUESTFS_PROC_ZERO_FREE_SPACE:
      zero_free_space_stub (data, datalen);
      break;
    case GUESTFS_PROC_LVCREATE_FREE:
      lvcreate_free_stub (data, datalen);
      break;
    case GUESTFS_PROC_ISOINFO_DEVICE:
      isoinfo_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_ISOINFO:
      isoinfo_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGMETA:
      vgmeta_stub (data, datalen);
      break;
    case GUESTFS_PROC_MD_STAT:
      md_stat_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKFS_BTRFS:
      mkfs_btrfs_stub (data, datalen);
      break;
    case GUESTFS_PROC_GET_E2ATTRS:
      get_e2attrs_stub (data, datalen);
      break;
    case GUESTFS_PROC_SET_E2ATTRS:
      set_e2attrs_stub (data, datalen);
      break;
    case GUESTFS_PROC_GET_E2GENERATION:
      get_e2generation_stub (data, datalen);
      break;
    case GUESTFS_PROC_SET_E2GENERATION:
      set_e2generation_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SNAPSHOT:
      btrfs_subvolume_snapshot_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_DELETE:
      btrfs_subvolume_delete_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_CREATE:
      btrfs_subvolume_create_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_LIST:
      btrfs_subvolume_list_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SET_DEFAULT:
      btrfs_subvolume_set_default_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_SYNC:
      btrfs_filesystem_sync_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_BALANCE:
      btrfs_filesystem_balance_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_DEVICE_ADD:
      btrfs_device_add_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_DEVICE_DELETE:
      btrfs_device_delete_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_SET_SEEDING:
      btrfs_set_seeding_stub (data, datalen);
      break;
    case GUESTFS_PROC_BTRFS_FSCK:
      btrfs_fsck_stub (data, datalen);
      break;
    case GUESTFS_PROC_FILESYSTEM_AVAILABLE:
      filesystem_available_stub (data, datalen);
      break;
    case GUESTFS_PROC_FSTRIM:
      fstrim_stub (data, datalen);
      break;
    case GUESTFS_PROC_DEVICE_INDEX:
      device_index_stub (data, datalen);
      break;
    case GUESTFS_PROC_NR_DEVICES:
      nr_devices_stub (data, datalen);
      break;
    case GUESTFS_PROC_XFS_INFO:
      xfs_info_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVCHANGE_UUID:
      pvchange_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_PVCHANGE_UUID_ALL:
      pvchange_uuid_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGCHANGE_UUID:
      vgchange_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_VGCHANGE_UUID_ALL:
      vgchange_uuid_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_UTSNAME:
      utsname_stub (data, datalen);
      break;
    case GUESTFS_PROC_XFS_GROWFS:
      xfs_growfs_stub (data, datalen);
      break;
    case GUESTFS_PROC_RSYNC:
      rsync_stub (data, datalen);
      break;
    case GUESTFS_PROC_RSYNC_IN:
      rsync_in_stub (data, datalen);
      break;
    case GUESTFS_PROC_RSYNC_OUT:
      rsync_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_LS0:
      ls0_stub (data, datalen);
      break;
    case GUESTFS_PROC_FILL_DIR:
      fill_dir_stub (data, datalen);
      break;
    case GUESTFS_PROC_XFS_ADMIN:
      xfs_admin_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_OPEN:
      hivex_open_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_CLOSE:
      hivex_close_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_ROOT:
      hivex_root_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_NAME:
      hivex_node_name_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_CHILDREN:
      hivex_node_children_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_GET_CHILD:
      hivex_node_get_child_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_PARENT:
      hivex_node_parent_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_VALUES:
      hivex_node_values_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_GET_VALUE:
      hivex_node_get_value_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_KEY:
      hivex_value_key_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_TYPE:
      hivex_value_type_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_VALUE:
      hivex_value_value_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_COMMIT:
      hivex_commit_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_ADD_CHILD:
      hivex_node_add_child_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_DELETE_CHILD:
      hivex_node_delete_child_stub (data, datalen);
      break;
    case GUESTFS_PROC_HIVEX_NODE_SET_VALUE:
      hivex_node_set_value_stub (data, datalen);
      break;
    case GUESTFS_PROC_XFS_REPAIR:
      xfs_repair_stub (data, datalen);
      break;
    case GUESTFS_PROC_RM_F:
      rm_f_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKE2FS:
      mke2fs_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_DISK_LABELS:
      list_disk_labels_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_ADD_DRIVE:
      internal_hot_add_drive_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK:
      internal_hot_remove_drive_precheck_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE:
      internal_hot_remove_drive_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKTEMP:
      mktemp_stub (data, datalen);
      break;
    case GUESTFS_PROC_MKLOST_AND_FOUND:
      mklost_and_found_stub (data, datalen);
      break;
    case GUESTFS_PROC_ACL_GET_FILE:
      acl_get_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_ACL_SET_FILE:
      acl_set_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_ACL_DELETE_DEF_FILE:
      acl_delete_def_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_CAP_GET_FILE:
      cap_get_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_CAP_SET_FILE:
      cap_set_file_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_LDM_VOLUMES:
      list_ldm_volumes_stub (data, datalen);
      break;
    case GUESTFS_PROC_LIST_LDM_PARTITIONS:
      list_ldm_partitions_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_CREATE_ALL:
      ldmtool_create_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_REMOVE_ALL:
      ldmtool_remove_all_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_SCAN:
      ldmtool_scan_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_SCAN_DEVICES:
      ldmtool_scan_devices_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_NAME:
      ldmtool_diskgroup_name_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_VOLUMES:
      ldmtool_diskgroup_volumes_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS:
      ldmtool_diskgroup_disks_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_TYPE:
      ldmtool_volume_type_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_HINT:
      ldmtool_volume_hint_stub (data, datalen);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_PARTITIONS:
      ldmtool_volume_partitions_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_SET_GPT_TYPE:
      part_set_gpt_type_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_GET_GPT_TYPE:
      part_get_gpt_type_stub (data, datalen);
      break;
    case GUESTFS_PROC_RENAME:
      rename_stub (data, datalen);
      break;
    case GUESTFS_PROC_IS_WHOLE_DEVICE:
      is_whole_device_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_PARSE_MOUNTABLE:
      internal_parse_mountable_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_RHBZ914931:
      internal_rhbz914931_stub (data, datalen);
      break;
    case GUESTFS_PROC_FEATURE_AVAILABLE:
      feature_available_stub (data, datalen);
      break;
    case GUESTFS_PROC_SYSLINUX:
      syslinux_stub (data, datalen);
      break;
    case GUESTFS_PROC_EXTLINUX:
      extlinux_stub (data, datalen);
      break;
    case GUESTFS_PROC_CP_R:
      cp_r_stub (data, datalen);
      break;
    case GUESTFS_PROC_REMOUNT:
      remount_stub (data, datalen);
      break;
    case GUESTFS_PROC_SET_UUID:
      set_uuid_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_OPEN:
      journal_open_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_CLOSE:
      journal_close_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_NEXT:
      journal_next_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_SKIP:
      journal_skip_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_JOURNAL_GET:
      internal_journal_get_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_GET_DATA_THRESHOLD:
      journal_get_data_threshold_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_SET_DATA_THRESHOLD:
      journal_set_data_threshold_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_SETM:
      aug_setm_stub (data, datalen);
      break;
    case GUESTFS_PROC_AUG_LABEL:
      aug_label_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_UPLOAD:
      internal_upload_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_EXIT:
      internal_exit_stub (data, datalen);
      break;
    case GUESTFS_PROC_COPY_ATTRIBUTES:
      copy_attributes_stub (data, datalen);
      break;
    case GUESTFS_PROC_PART_GET_NAME:
      part_get_name_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLKDISCARD:
      blkdiscard_stub (data, datalen);
      break;
    case GUESTFS_PROC_BLKDISCARDZEROES:
      blkdiscardzeroes_stub (data, datalen);
      break;
    case GUESTFS_PROC_CPIO_OUT:
      cpio_out_stub (data, datalen);
      break;
    case GUESTFS_PROC_JOURNAL_GET_REALTIME_USEC:
      journal_get_realtime_usec_stub (data, datalen);
      break;
    case GUESTFS_PROC_STATNS:
      statns_stub (data, datalen);
      break;
    case GUESTFS_PROC_LSTATNS:
      lstatns_stub (data, datalen);
      break;
    case GUESTFS_PROC_INTERNAL_LSTATNSLIST:
      internal_lstatnslist_stub (data, datalen);
      break;
    default:
      reply_with_error ("dispatch_incoming_message: unknown procedure number %d, set LIBGUESTFS_PATH to point to the matching libguestfs appliance directory", proc_nr);
  }
}

static const char *lvm_pv_cols = "pv_name,pv_uuid,pv_fmt,pv_size,dev_size,pv_free,pv_used,pv_attr,pv_pe_count,pv_pe_alloc_count,pv_tags,pe_start,pv_mda_count,pv_mda_free";

static int lvm_tokenize_pv (char *str, guestfs_int_lvm_pv *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_name");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_name = strdup (tok);
  if (r->pv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_uuid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->pv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_fmt");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_fmt = strdup (tok);
  if (r->pv_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "dev_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->dev_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "dev_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_used");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_used) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_used");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_attr");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_attr = strdup (tok);
  if (r->pv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_pe_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_alloc_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_pe_alloc_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_alloc_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_tags");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_tags = strdup (tok);
  if (r->pv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pe_start");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pe_start) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pe_start");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_pv_list *
parse_command_line_pvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i, j;
  guestfs_int_lvm_pv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->n_vals = 0;
  ret->val = NULL;

  r = command (&out, &err,
	       "lvm", "pvs",
	       "-o", lvm_pv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ",", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->vals,
		    sizeof (guestfs_int_lvm_pv *) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->vals);
      free (ret);
      free (out);
      return NULL;
    }
    ret->vals = newp;

    /* Tokenize the next entry. */
    ret->vals[i] = malloc (sizeof (guestfs_int_lvm_pv))    guestfs_int_lvm_pv__init (ret->vals[i]);    r = lvm_tokenize_pv (p, ret->vals[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'pvs' command");
      for (j = 0; j < i; ++j)
        free (ret->vals[i])      free (ret->vals);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->n_vals = i;

  free (out);
  return ret;
}
static const char *lvm_vg_cols = "vg_name,vg_uuid,vg_fmt,vg_attr,vg_size,vg_free,vg_sysid,vg_extent_size,vg_extent_count,vg_free_count,max_lv,max_pv,pv_count,lv_count,snap_count,vg_seqno,vg_tags,vg_mda_count,vg_mda_free";

static int lvm_tokenize_vg (char *str, guestfs_int_lvm_vg *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_name");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_name = strdup (tok);
  if (r->vg_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_uuid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->vg_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_fmt");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_fmt = strdup (tok);
  if (r->vg_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_attr");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_attr = strdup (tok);
  if (r->vg_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_sysid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_sysid = strdup (tok);
  if (r->vg_sysid == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_extent_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_extent_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_extent_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_extent_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_free_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_free_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_lv");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->max_lv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_lv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_pv");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->max_pv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_pv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->snap_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "snap_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_seqno");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_seqno) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_seqno");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_tags");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_tags = strdup (tok);
  if (r->vg_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_vg_list *
parse_command_line_vgs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i, j;
  guestfs_int_lvm_vg_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->n_vals = 0;
  ret->val = NULL;

  r = command (&out, &err,
	       "lvm", "vgs",
	       "-o", lvm_vg_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ",", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->vals,
		    sizeof (guestfs_int_lvm_vg *) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->vals);
      free (ret);
      free (out);
      return NULL;
    }
    ret->vals = newp;

    /* Tokenize the next entry. */
    ret->vals[i] = malloc (sizeof (guestfs_int_lvm_vg))    guestfs_int_lvm_vg__init (ret->vals[i]);    r = lvm_tokenize_vg (p, ret->vals[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'vgs' command");
      for (j = 0; j < i; ++j)
        free (ret->vals[i])      free (ret->vals);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->n_vals = i;

  free (out);
  return ret;
}
static const char *lvm_lv_cols = "lv_name,lv_uuid,lv_attr,lv_major,lv_minor,lv_kernel_major,lv_kernel_minor,lv_size,seg_count,origin,snap_percent,copy_percent,move_pv,lv_tags,mirror_log,modules";

static int lvm_tokenize_lv (char *str, guestfs_int_lvm_lv *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_name");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_name = strdup (tok);
  if (r->lv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_uuid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->lv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_attr");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_attr = strdup (tok);
  if (r->lv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_major");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_minor");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_major");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_kernel_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_minor");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_kernel_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->lv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "lv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "seg_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->seg_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "seg_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "origin");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->origin = strdup (tok);
  if (r->origin == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_percent");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->snap_percent = -1;
  else if (sscanf (tok, "%f", &r->snap_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "snap_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "copy_percent");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->copy_percent = -1;
  else if (sscanf (tok, "%f", &r->copy_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "copy_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "move_pv");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->move_pv = strdup (tok);
  if (r->move_pv == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_tags");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_tags = strdup (tok);
  if (r->lv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "mirror_log");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->mirror_log = strdup (tok);
  if (r->mirror_log == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "modules");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->modules = strdup (tok);
  if (r->modules == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_lv_list *
parse_command_line_lvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i, j;
  guestfs_int_lvm_lv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->n_vals = 0;
  ret->val = NULL;

  r = command (&out, &err,
	       "lvm", "lvs",
	       "-o", lvm_lv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ",", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->vals,
		    sizeof (guestfs_int_lvm_lv *) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->vals);
      free (ret);
      free (out);
      return NULL;
    }
    ret->vals = newp;

    /* Tokenize the next entry. */
    ret->vals[i] = malloc (sizeof (guestfs_int_lvm_lv))    guestfs_int_lvm_lv__init (ret->vals[i]);    r = lvm_tokenize_lv (p, ret->vals[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'lvs' command");
      for (j = 0; j < i; ++j)
        free (ret->vals[i])      free (ret->vals);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->n_vals = i;

  free (out);
  return ret;
}
