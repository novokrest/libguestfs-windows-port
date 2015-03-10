#include <pcre.h>

void
test_pcre()
{
    pcre *re;
    const char *err;
    int offset;

    re = pcre_compile("(\\d+)\\.(\\d+)", 0, &err, &offset, NULL);
    if (re) {
        pcre_free(re);
    }
}