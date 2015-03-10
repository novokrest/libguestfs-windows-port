#include <stdlib.h>
#include <stdio.h>

void test_pcre(void);
void test_xdr(void);

int main(int args, char* argv[])
{
    test_pcre();
    test_xdr();

    return 0;
}
