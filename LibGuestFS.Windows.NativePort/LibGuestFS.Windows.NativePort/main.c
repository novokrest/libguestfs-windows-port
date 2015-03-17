#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    time_t t_start, t_end;
    if (lib_init() == -1) {
        printf("Some error occured while libs initialization\n");
        return 1;
    }

    test_pcre();
    test_xdr();
    test_libxml();
    test_libintl();

    time(&t_start);
    test_guestfs();
    time(&t_end);

    printf("time: %f\n", difftime(t_end, t_start)); /* 86-90 seconds */

    return 0;
}
