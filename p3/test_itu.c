#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "codif.h"
#include "itu.h"

void test_itu1(void) {
  itu_init();
  // check to_ascii()
  CU_ASSERT_EQUAL('A',to_ascii(itu_table,".-"));
  CU_ASSERT_EQUAL('V',to_ascii(itu_table,"...-"));
  CU_ASSERT_EQUAL('5',to_ascii(itu_table,"....."));
  // check to_morse()
  morse_char_t m;
  to_morse(itu_table,'A',m);
  CU_ASSERT_STRING_EQUAL(m,".-");
  to_morse(itu_table,'V',m);
  CU_ASSERT_STRING_EQUAL(m, "...-");
  to_morse(itu_table,'5',m);
  CU_ASSERT_STRING_EQUAL(m,".....");
}

void test_itu2(void) {
  itu_init();
  // check to_ascii()
  CU_ASSERT_EQUAL('C',to_ascii(itu_table,"-.-."));
  CU_ASSERT_EQUAL('Z',to_ascii(itu_table,"--.."));
  CU_ASSERT_EQUAL('9',to_ascii(itu_table,"----."));
  CU_ASSERT_EQUAL('@',to_ascii(itu_table,".-.-"));//no ascii for ".-.-"
  CU_ASSERT_EQUAL('E',to_ascii(itu_table,"."));
  // check to_morse()
  morse_char_t m;
  to_morse(itu_table,'C',m);
  CU_ASSERT_STRING_EQUAL(m,"-.-.");
  to_morse(itu_table,'Z',m);
  CU_ASSERT_STRING_EQUAL(m, "--..");
  to_morse(itu_table,'9',m);
  CU_ASSERT_STRING_EQUAL(m,"----.");
  to_morse(itu_table,'@',m);
  CU_ASSERT_STRING_EQUAL(m,"");//'@' is not on the table
  to_morse(itu_table,'E',m);
  CU_ASSERT_STRING_EQUAL(m,".");
  to_morse(itu_table,'\0',m);
  CU_ASSERT_STRING_EQUAL(m,"");//'\0' is not on the table
  to_morse(itu_table,'a',m);
  CU_ASSERT_STRING_EQUAL(m,"");//'a' is not on the table
}

void test_itu3(void) {
  itu_init();
  //EQUAL if table filled with '@' (empty_morse_table) and finished with '\0'
  CU_ASSERT_STRING_EQUAL(itu_table,"@TEMNAIOGKDWRUS@@QZYCXBJP@L@FVH09@8@@@7@@@@@@@61@@@@@@@2@@@3@45");
  //  fprintf(stdout,"\n%s\n",itu_table);
}

int main()
{
  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  
  //Suite_1 (BASIC)
  /* add a suite to the registry */
  CU_pSuite pSuite1 = CU_add_suite("Suite_1 Basic", NULL, NULL);
  if (NULL == pSuite1) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  /* add the tests to the suite1 */
  CU_ADD_TEST(pSuite1, test_itu1);
  
  //Suite_2 (STANDARD)
  /* add a suite to the registry */
  CU_pSuite pSuite2 = CU_add_suite("Suite_2 Standard", NULL, NULL);
  if (NULL == pSuite2) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  /* add the tests to the suite2 */
  CU_ADD_TEST(pSuite2, test_itu2);
  
  //Suite_3 (IMPLEMENTATION) In general not passed
  /* add a suite to the registry */
  CU_pSuite pSuite3 = CU_add_suite("Suite_3 Implementation", NULL, NULL);
  if (NULL == pSuite3) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  /* add the tests to the suite3 */
  CU_ADD_TEST(pSuite3, test_itu3);
  
  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  
  return CU_get_error();
}


