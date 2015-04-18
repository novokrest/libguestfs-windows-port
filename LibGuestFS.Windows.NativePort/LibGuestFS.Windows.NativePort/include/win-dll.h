#ifndef WIN_DLL_H
#define WIN_DLL_H

extern void dll_init_libguestfs();                         /* handle.c */
extern void dll_init_backend_direct();                     /* launch-direct.c */
//extern void dll_init_backend_uml();                        /* launch-uml.c */
//extern void dll_init_backend_unix();                       /* launch-unix.c */
//extern void dll_init_backend_libvirt();                    /* launch-libvirt.c */

extern void dll_compile_regexps_launch_direct();           /* launch-direct.c */
extern void dll_compile_regexps_inspect_fs();              /* inspect-fs.c */
extern void dll_compile_regexps_inspect_fs_unix();         /* inspect-fs-unix.c */
extern void dll_compile_regexps_inspect_fs_windows();      /* inspect-fs-windows.c */
extern void dll_compile_regexps_osinfo();                  /* osinfo.c */
extern void dll_compile_regexps_drives();                  /* drives.c */
extern void dll_compile_regexps_filearch();                /* filearch.c */

extern void dll_free_regexps_launch_direct();              /* launch-direct.c */
extern void dll_free_regexps_inspect_fs();                 /* inspect-fs.c */
extern void dll_free_regexps_inspect_fs_unix();            /* inspect-fs-unix.c */
extern void dll_free_regexps_inspect_fs_windows();         /* inspect-fs-windows.c */
extern void dll_free_regexps_osinfo();                     /* osinfo.c */
extern void dll_free_regexps_drives();                     /* drives.c */
extern void dll_free_regexps_filearch();                   /* filearch.c */

#endif /* WIN_DLL_H */


/*


*/