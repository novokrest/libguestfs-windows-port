#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "shared-memory.h"

struct posix_shared_memory
{
  struct shared_memory_ops *ops;
  
  const char *name;
  uint64_t size;
  int fd;
  void *ptr;
};

static int
posix_shared_memory__open (struct shared_memory *shmemv)
{
  struct posix_shared_memory *shmem = (struct posix_shared_memory *) shmemv;
  uint64_t size;
  int fd;
  void *map = NULL;
  struct stat st;

  if ((fd = open (shmem->name, O_RDWR)) < 0) {
    perror ("shared memory open: shm_open");
    return -1;
  }
  
  if (fstat (fd, &st) == -1) {
    perror ("shared memory open: fstat");
    close (fd);
    return -1;
  }
  
#if 0
  size = st.st_size;
  shmem->size = shmem->size < size ? shmem->size : size;
  if (ftruncate (shmem->size) == -1) {
    perror ("shared memory open: ftruncate");
    close (fd);
    return -1;
  }
#endif

  map = mmap (0, shmem->size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 1 * getpagesize());
  if (map == MAP_FAILED) {
    perror ("shared memory open: mmap");
    close (fd);
    return -1;
  }

  shmem->fd = fd;
  shmem->ptr = map;

  return 0;
}

static int
posix_shared_memory__close (struct shared_memory *shmemv)
{
  struct posix_shared_memory *shmem = (struct posix_shared_memory *) shmemv;
  
  if ((munmap (shmem->ptr, shmem->size)) < 0) {
    perror ("shared memory close: munmap");
    return -1;
  }

  if (close (shmem->fd)) {
    perror ("shared memory close: close");
    return -1;
  }
  
  shmem->ptr = NULL;
  shmem->fd = 0;
  
  return 0;
}

static uint64_t
posix_shared_memory__get_size (struct shared_memory *shmemv)
{
  struct posix_shared_memory *shmem = (struct posix_shared_memory *) shmemv;
  
  return shmem->size;
}

static void *
posix_shared_memory__get_ptr (struct shared_memory *shmemv)
{
  struct posix_shared_memory *shmem = (struct posix_shared_memory *) shmemv;
  
  return shmem->ptr;
}

static void
posix_shared_memory__print (struct shared_memory *shmemv, int n)
{
  struct posix_shared_memory *shmem = (struct posix_shared_memory *) shmemv;
  char *buf;
  
  buf = malloc (n + 1);
  if (!buf)
    return;

  memcpy (buf, (char *) shmem->ptr, n);
  buf[n] = '\0';
  
  printf ("shared memory print: %s\n", buf);
  free (buf);
}

static struct shared_memory_ops ops = {
  .open = posix_shared_memory__open,
  .close = posix_shared_memory__close,
  .get_size = posix_shared_memory__get_size,
  .get_ptr = posix_shared_memory__get_ptr,
  .print = posix_shared_memory__print,
};

struct shared_memory *
new_shared_memory (const char *name, uint64_t size)
{
  struct posix_shared_memory *shmem;
  
  if (size == 0) {
    return NULL;
  }
  
  shmem = malloc (sizeof (struct posix_shared_memory));
  if (!shmem) {
    return NULL;
  }
  
  shmem->ops = &ops;
  shmem->name = strdup (name);
  shmem->size = size;
  shmem->fd = -1;
  shmem->ptr = NULL;
  
  return (struct shared_memory *) shmem;
}

void
free_shared_memory (struct shared_memory *shmemv)
{
  struct posix_shared_memory *shmem = (struct posix_shared_memory *) shmemv;

  free (shmem->name);
  free (shmem);
}



