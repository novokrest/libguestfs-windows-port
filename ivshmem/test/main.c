#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define prfmt(fmt) "%s:%d:: " fmt, __func__, __LINE__
#define prinfo(fmt, ...) printf(prfmt(fmt), ##__VA_ARGS__)
#define prerr(fmt, ...) fprintf(stderr, prfmt(fmt), ##__VA_ARGS__)

int
main (int argc, char *argv[])
{
    void *map = NULL;
    int fd;
    char *filename = "testshm";
    size_t filesize = 0x100000;
    
    if ((fd = shm_open(filename, O_RDWR | O_CREAT, (mode_t) 0666)) < 0) {
        prerr("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((ftruncate(fd, filesize)) < 0) {
        prerr("%s\n", strerror(errno));
        close(fd);
        exit(EXIT_FAILURE);
    }

    if ((map =
             mmap(0, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
            0)) == (caddr_t) - 1) {
        prerr("%s\n", strerror(errno));
        close(fd);
        exit(EXIT_FAILURE);
    }

    prinfo("read \"%s\"\n", (char *)map);
    
    if ((munmap(map, filesize)) < 0)
        prerr("WARNING: Failed to unmap \"%s\"\n", filename);

    close(fd);

    return 0;
  return 0;
}
