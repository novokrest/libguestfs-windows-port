#include <stdlib.h>
#include <windows.h>
#include <lmcons.h>

char*
getusername()
{
    char* ret;
    int len;
    char buf[UNLEN + 1];

    len = sizeof(buf);

    if (!GetUserName(buf, &len)) {
        return NULL;
    }

    ret = malloc(len);
    if (ret == NULL) {
        return NULL;
    }

    strcpy(ret, buf);
    ret[len - 1] = '\0';

    return ret;
}