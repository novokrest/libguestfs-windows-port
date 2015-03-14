#include <stdlib.h>
#include <stdio.h>

void test_pcre(void);
void test_xdr(void);
void test_guestfs(void);
void test_libxml(void);

int main(int args, char* argv[])
{
    test_pcre();
    test_xdr();
    test_libxml();

    test_guestfs();

    return 0;
}
