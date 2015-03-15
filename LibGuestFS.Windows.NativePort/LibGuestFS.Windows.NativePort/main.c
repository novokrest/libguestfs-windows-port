#include <stdlib.h>
#include <stdio.h>

#include <Windows.h>

void test_pcre(void);
void test_xdr(void);
void test_libxml(void);
void test_libintl(void);

void test_guestfs(void);

int
lib_init()
{
    fprintf(stdout, "INIT: WSA\n");
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0) {
        fprintf(stderr, "ERROR: WSAStartUp\n");
        return -1;
    }
}

int
lib_close()
{
    fprintf(stdout, "CLOSE: WSA\n");
    WSACleanup();
}

int main(int args, char* argv[])
{
    if (lib_init() == -1) {
        printf("Some error occured while libs initialization\n");
        return 1;
    }

    test_pcre();
    test_xdr();
    test_libxml();
    test_libintl();

    test_guestfs();

    return 0;
}
