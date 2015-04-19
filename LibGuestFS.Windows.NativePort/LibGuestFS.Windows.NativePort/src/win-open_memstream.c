/*
 * There is mock implementation. Must be research and implemented.
 * https://cells-source.cs.columbia.edu/plugins/gitiles/platform/system/core/+/a570312a56938f6ebfcadc3ec9830ab8a2407654/libcutils/open_memstream.c
 * http://stackoverflow.com/questions/10305095/can-i-replace-a-call-to-open-memstream-with-a-malloc-and-an-implicit-cast?answertab=votes#tab-top
 * http://stackoverflow.com/questions/10339473/using-mapviewoffile-pointer-eventually-walks-out-of-memory-space
 *
 * Windows file streams:
 * https://msdn.microsoft.com/ru-ru/library/windows/desktop/aa364404(v=vs.85).aspx
 * https://msdn.microsoft.com/ru-ru/library/windows/desktop/aa366761(v=vs.85).aspx
*/

#include <stdlib.h>
#include <stdio.h>

FILE* 
open_memstream(char **ptr, size_t *sizeloc)
{
    return NULL;
}