#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

static char const *IVSHMEM_FILE_NAME = "/dev/uio0"; //"/dev/ivshmem";
static size_t const IVSHMEM_SIZE = 0x100000;

int
ivshmem_write (char const *msg)
{
  int fd;
  void *map = NULL;

  printf ("Open ivshmem: %s\n", IVSHMEM_FILE_NAME);
  if ((fd = open (IVSHMEM_FILE_NAME, O_RDWR)) < 0) {
    fprintf (stderr, "Failure to open %s: %s\n", IVSHMEM_FILE_NAME, strerror (errno));
    return -1;
  }

  printf ("Map ivshmem: %s\n", IVSHMEM_FILE_NAME);
  if ((map = mmap (0, IVSHMEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 1 * getpagesize())) == MAP_FAILED) {
    fprintf (stderr, "Failure to map ivshmem %s: %s \n", IVSHMEM_FILE_NAME, strerror (errno));
    close (fd);
    return -1;
  }

  printf ("Write msg: %s\n", msg);
  strcpy ((char *) map, msg);

  printf ("Unmap ivshmem: %s\n", IVSHMEM_FILE_NAME);
  if ((munmap (map, IVSHMEM_SIZE)) < 0) {
    fprintf (stderr, "Failure during unmap: %s\n", IVSHMEM_FILE_NAME);
    return -1;
  }

  printf ("Close ivshmem: %s\n", IVSHMEM_FILE_NAME);
  close (fd);

  return 0;
}
