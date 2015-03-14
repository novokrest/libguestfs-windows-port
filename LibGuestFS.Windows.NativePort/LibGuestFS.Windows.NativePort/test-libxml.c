#include <libxml/parser.h>
#include <libxml/xmlversion.h>

void
test_libxml()
{
    xmlInitParser();
    LIBXML_TEST_VERSION;
}