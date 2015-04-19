#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

#define GUESTFS_SHARED_MEMORY_DEFAULT_SIZE 512

#define GUESTFS_SHARED_MEMORY_DEFAULT_NAME "GuestfsShm"

static int
is_power_of_2(int v)
{
    return v && (v & (v - 1)) == 0;
}

int
guestfs__set_shared_memory(guestfs_h *g, int enable,
                           const struct guestfs_set_shared_memory_argv *optargs)
{
    int size;
    char *name;

    if (g->shm) {
      guestfs___free_shared_memory(g);
    }

    g->enable_shm = !!enable;
    
    if (!g->enable_shm) {
      return 0;
    }

    if (optargs->bitmask & GUESTFS_SET_SHARED_MEMORY_SIZE_BITMASK) {
        if (!is_power_of_2(optargs->size)) {
            error(g, _("size of shared memory must be power of 2"));
            return -1;
        }
    }

    size = optargs->bitmask & GUESTFS_SET_SHARED_MEMORY_SIZE_BITMASK ? optargs->size : GUESTFS_SHARED_MEMORY_DEFAULT_SIZE;
    name = optargs->bitmask & GUESTFS_SET_SHARED_MEMORY_NAME_BITMASK ? optargs->name : GUESTFS_SHARED_MEMORY_DEFAULT_NAME;

    g->shm = guestfs___new_shared_memory(g, size, safe_strdup(g, name));

    return 0;
}

int
guestfs__get_shared_memory(guestfs_h *g)
{
    return g->enable_shm;
}

void
guestfs___free_shared_memory(guestfs_h *g)
{
    struct shared_memory *shm = g->shm;

    if (shm == NULL)
      return;

    if (shm->hMapFile)
      shm->ops->close(g, shm);

    if (shm->name)
      free(shm->name);

    free (shm);

    g->shm = NULL;
}

static int
open_shared_memory(guestfs_h *g, struct shared_memory *shm)
{
    HANDLE hMapFile;
    void *pMapView;
    char shm_global_name[MAX_PATH];

    sprintf(shm_global_name, "Global\\%s", shm->name);

    hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,
        FALSE,
        shm_global_name);

    if (hMapFile == NULL) {
      perrorf_win(g, _("could not open file mapping object '%s'"), shm_global_name);
      return -1;
    }

    pMapView = MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        shm->size * 1024 * 1024);

    if (pMapView == NULL) {
      perrorf_win(g, _("could not map view of file '%s'"), shm_global_name);
      return -1;
    }

    shm->hMapFile = hMapFile;
    shm->pMapView = pMapView;

    return 0;
}

static int
close_shared_memory(guestfs_h *g, struct shared_memory *shm)
{
    UnmapViewOfFile(shm->pMapView);
    CloseHandle(shm->hMapFile);

    shm->hMapFile = NULL;
    shm->pMapView = NULL;

    return 0;
}

static int
get_shared_memory_size(guestfs_h *g, struct shared_memory *shm)
{
    return shm->size;
}

static const char *
get_shared_memory_name(guestfs_h *g, struct shared_memory *shm)
{
    return shm->name;
}

static void *
get_shared_memory_ptr(guestfs_h *g, struct shared_memory *shm)
{
    return shm->pMapView;
}

static void
print_shared_memory(guestfs_h *g, struct shared_memory *shm, int n)
{
    char *buf;

    buf = malloc(n + 1);
    strcpy(buf, (char *) (shm->pMapView), n);
    buf[n] = '\0';

    printf("SHARED_MEMORY_CONTENTS: %s", buf);
}

static struct shared_memory_ops ops = {
    .open = open_shared_memory,
    .close = close_shared_memory,
    .get_size = get_shared_memory_size,
    .get_name = get_shared_memory_name,
    .get_ptr = get_shared_memory_ptr,
    .print = print_shared_memory,
};

struct shared_memory *
guestfs___new_shared_memory(guestfs_h *g,
                            int size,
                            const char *name)
{
    struct shared_memory *shm;

    shm = safe_malloc(g, sizeof(struct shared_memory));
    shm->ops = &ops;
    shm->size = size;
    shm->name = name;

    shm->hMapFile = NULL;
    shm->pMapView = NULL;

    return shm;
}