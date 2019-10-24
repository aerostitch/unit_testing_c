#include "CppUTest/TestHarness.h"
#include "search.h"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, search_fix_spaces)
{
    const char *in = " Hello, world/!  ";
    STRCMP_EQUAL(search_fix_spaces(in), "Hello world !");
    // Explicit cast is necessary here because cpputest runs with -Wwrite-strings which assumes ISO C++ is respected
    char *non_const = (char *)"Spaces after string...  ";
    STRCMP_EQUAL(search_fix_spaces(non_const), "Spaces after string...");
    STRCMP_EQUAL(search_fix_spaces("   Spaces before string."), "Spaces before string.");
    STRCMP_EQUAL(search_fix_spaces("Don't change a thing!"), "Don't change a thing!");
    STRCMP_EQUAL(search_fix_spaces(""), "");
    STRCMP_EQUAL(search_fix_spaces(", / "), "");
    STRCMP_EQUAL(search_fix_spaces(", */ "), "*");
}
