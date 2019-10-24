#include <CUnit/Basic.h>
// #include <CUnit/Console.h>
#include "search.h"

int init_suite_search(void)  { return 0; }
int clean_suite_search(void) { return 0; }

void test_search_fix_spaces(void)
{
    const char *in = " Hello, world/!  ";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(in), "Hello world !");

    char *non_const = "Spaces after string...  ";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(non_const), "Spaces after string...");
    non_const = "   Spaces before string.";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(non_const), "Spaces before string.");
    non_const = "Don't change a thing!";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(non_const), "Don't change a thing!");
    non_const = "";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(non_const), "");
    non_const = ", / ";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(non_const), "");
    non_const = ", */ ";
    CU_ASSERT_STRING_EQUAL(search_fix_spaces(non_const), "*");
}


/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Search_Suite", init_suite_search, clean_suite_search);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (NULL == CU_add_test(pSuite, "test of search_fix_spaces()", test_search_fix_spaces)) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // CU_console_run_tests();
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
