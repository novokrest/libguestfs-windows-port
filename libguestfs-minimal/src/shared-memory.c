#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

#define GUESTFS_SHARED_MEMORY_DEFAULT_SIZE 512
#define GUESTFS_SHARED_MEMORY_DEFAULT_NAME "guestfs_shm"

static int
is_power_of_2 (int v)
{
  return v && (v & (v - 1)) == 0;
}

int
guestfs__set_shared_memory (guestfs_h *g, int enable,
                            const struct guestfs_set_shared_memory_argv *optargs)
{
  g->enable_shm = !!enable;
  
  if (optargs->bitmask & GUESTFS_SET_SHARED_MEMORY_SIZE_BITMASK) {
    if (!is_power_of_2 (optargs->size)) {
      error (g, _("size of shared memory must be power of 2"));
      return -1;
    }
  }
  
  g->shm.size = optargs->bitmask & GUESTFS_SET_SHARED_MEMORY_SIZE_BITMASK ? optargs->size : GUESTFS_SHARED_MEMORY_DEFAULT_SIZE;
  
  g->shm.name = optargs->bitmask & GUESTFS_SET_SHARED_MEMORY_NAME_BITMASK ? optargs->name : GUESTFS_SHARED_MEMORY_DEFAULT_NAME;
  
  g->shm.fd = -1;
  g->shm.map = NULL;
  
  return 0;
}

int
guestfs__get_shared_memory (guestfs_h *g)
{
  return g->enable_shm;
}

