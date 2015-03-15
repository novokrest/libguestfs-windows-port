#include <stdlib.h>
#include <guestfs.h>

void
test_guestfs()
{
    guestfs_h *g;

    g = guestfs_create();
    if (g == NULL) {
        printf("ERROR: guestfs_create()\n");
        exit(EXIT_FAILURE);
    }
}
