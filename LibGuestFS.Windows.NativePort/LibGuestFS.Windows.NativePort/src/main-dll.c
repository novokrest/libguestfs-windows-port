#include <windows.h>
#include <win-dll.h>

int
dll_wsa_init()
{
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0) {
        return -1;
    }

    return 0;
}

void
dll_wsa_close()
{
    WSACleanup();
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        /* equivalent of __attribute__((constructor))... */

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

        return TRUE;
    }
    else if (fdwReason == DLL_PROCESS_DETACH)
    {
        /* equivalent of __attribute__((destructor))... */

        dll_wsa_close();

        dll_free_regexps_launch_direct();
        dll_free_regexps_inspect_fs();
        dll_free_regexps_inspect_fs_unix();
        dll_free_regexps_inspect_fs_windows();
        dll_free_regexps_osinfo();
        dll_free_regexps_drives();
        //dll_free_regexps_filearch();
    }

    return TRUE;
}