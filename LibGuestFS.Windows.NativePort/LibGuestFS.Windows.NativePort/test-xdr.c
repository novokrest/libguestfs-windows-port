#include <rpc/types.h>
#include <rpc/xdr.h>

void
test_xdr()
{
    XDR xdr;
    char buf[4];

    xdrmem_create(&xdr, buf, 4, XDR_ENCODE);
    xdr_destroy(&xdr);
}
