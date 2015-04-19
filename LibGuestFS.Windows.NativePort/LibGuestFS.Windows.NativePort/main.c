#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "test-guestfs.h"

#define DISK_IMG "C:/GuestFS/appliance/disk.img"
#define SMALL_FILES_COUNT 100
#define SHARED_MEMORY_SIZE 256
#define SHARED_MEMORY_NAME "MyShm"
#define REPORT_FILENAME "report.txt"

#ifdef _WIN32
#include <Windows.h>
#include <win-dll.h>

int
dll_init()
{
    if (dll_wsa_init() == -1) {
        return FALSE;
    }

    dll_init_libguestfs();
    dll_init_backend_direct();
    //dll_init_backend_uml();
    //dll_init_backend_unix();
    //dll_init_backend_libvirt();

    dll_compile_regexps_launch_direct();
    dll_compile_regexps_inspect_fs();
    dll_compile_regexps_inspect_fs_unix();
    dll_compile_regexps_inspect_fs_windows();
    dll_compile_regexps_osinfo();
    dll_compile_regexps_drives();
    //dll_compile_regexps_filearch();
}

int
dll_close()
{
    dll_wsa_close();

    dll_free_regexps_launch_direct();
    dll_free_regexps_inspect_fs();
    dll_free_regexps_inspect_fs_unix();
    dll_free_regexps_inspect_fs_windows();
    dll_free_regexps_osinfo();
    dll_free_regexps_drives();
    //dll_free_regexps_filearch();
}

#endif /* _WIN32 */

int main(int args, char* argv[])
{
#ifdef _WIN32

    dll_init();

#endif /* _WIN32 */

    int i = 0;
    char buf[256];
    char *path;
    struct test_guestfs *test;

    test = new_test_guestfs();
    if (!test) {
        printf("ERROR: fail to create test\n");
        exit(EXIT_FAILURE);
    }

    test->protocol = PROTOBUF;
    test->ops->set_shared_memory(test, 0, SHARED_MEMORY_SIZE, SHARED_MEMORY_NAME);
    test->ops->add_drive(test, DISK_IMG);
    
    test->ops->add_download(test, "/home/novokrestdeb/subdisk.img", "subdisk.img");
    test->ops->add_download(test, "/home/novokrestdeb/video.mp4", "video.mp4");
    
    for (i = 0; i < SMALL_FILES_COUNT; ++i) {
        sprintf(buf, "/home/novokrestdeb/%d", i);
        test->ops->add_read(test, buf, NULL);
    }

    test->ops->set_report(test, REPORT_FILENAME, "GUESTFS_TEST", false);

    test->ops->run(test);

    free_test_guestfs(test);

#ifdef _WIN32

    dll_close();

#endif /* _WIN32 */

    return 0;
}
