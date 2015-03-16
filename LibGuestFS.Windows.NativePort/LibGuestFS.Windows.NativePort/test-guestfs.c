#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

#include <guestfs.h>

bool check_file_exists(const char* filename)
{
    struct stat buffer;
    return stat(filename, &buffer) == 0;
}

static int
compare_keys_len(const void *p1, const void *p2)
{
    const char *key1 = *(char * const *)p1;
    const char *key2 = *(char * const *)p2;
    return strlen(key1) - strlen(key2);
}

static size_t
count_strings(char *const *argv)
{
    size_t c;

    for (c = 0; argv[c]; ++c)
        ;
    return c;
}

int mount_disks(guestfs_h* gfs)
{
    char **roots, *root, **mountpoints;

    printf("guestfs_inspect_os()...\n");
    roots = guestfs_inspect_os(gfs);
    if (roots == NULL || roots[0] == NULL) {
        printf("ERROR: no roots\n");
        return 1;
    }

    printf("iter over founded roots...\n");
    for (int j = 0; roots[j] != NULL; ++j) {
        root = roots[j];
        printf("root: %s\n", root);

        mountpoints = guestfs_inspect_get_mountpoints(gfs, root);
        if (mountpoints == NULL) {
            printf("ERROR: failed to inspect mountpoints for root: %s\n", root);
            return 1;
        }

        qsort(mountpoints, count_strings(mountpoints) / 2, 2 * sizeof(char*), compare_keys_len);
        for (int i = 0; mountpoints[i] != NULL; i += 2) {
            /* Ignore failures from this call, since bogus entries can appear in the guest's /etc/fstab.*/
            guestfs_mount_ro (gfs, mountpoints[i+1], mountpoints[i]);
            free (mountpoints[i]);
            free (mountpoints[i+1]);
        }
        free (mountpoints);
        free (root);
    }
    free(roots);

    return 0;
}

int read_file(guestfs_h* gfs, char const* remote_file_path)
{
    size_t fsize;
    char* file_content = guestfs_read_file(gfs, remote_file_path, &fsize);
    if (!file_content) {
        printf("ERROR: read file='%s'\n", remote_file_path);
        return 1;
    }
    printf("file's content: %s\n", file_content);
    free(file_content);

    return 0;
}

void
test_guestfs()
{
    guestfs_h *g;

    g = guestfs_create();
    if (g == NULL) {
        printf("ERROR: guestfs_create()\n");
        exit(EXIT_FAILURE);
    }

    printf("guestfs_set_verbose()...\n");
    if (guestfs_set_verbose(g, 1) == -1) {
        printf("ERROR occurred during guestfs_set_verbose()\n");
        exit(EXIT_FAILURE);
    }

    printf("guestfs_get_backend()...\n");
    char* default_backend = guestfs_get_backend(g);
    if (strcmp(default_backend, "direct")) {
        printf("guestfs_set_backend()...\n");
        if (guestfs_set_backend(g, "direct") == -1) {
            printf("ERROR occurred during guestfs_set_backend()\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("backend is direct\n");

    const char* disk_image_path = "C:/GuestFS/disk.img";
    if (!check_file_exists(disk_image_path)) {
        printf("disk_image doesn't exist: %s\n", disk_image_path);
        exit(EXIT_FAILURE);
    }

    if (guestfs_add_drive_opts(g, disk_image_path,
        GUESTFS_ADD_DRIVE_OPTS_FORMAT, "raw",
        GUESTFS_ADD_DRIVE_OPTS_READONLY, 0,
        -1) == -1) {
        printf("ERROR occurred during guestfs_add_drive_opts\n");
        exit(EXIT_FAILURE);
    }

    printf("guestfs_launch()...\n");
    if (guestfs_launch(g) == -1) {
        printf("ERROR occurred during guestfs_launch()\n");
        exit(EXIT_FAILURE);
    }

    if (mount_disks(g) == 0) {
        printf("read_file()...\n");
        read_file(g, "/home/novokrestdeb/123.txt");
    }

    printf("guestfs_close()...\n");
    guestfs_close(g);
}
