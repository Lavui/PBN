#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "codif.h"

void test_codif1(void) {
  morse_table_t t;
  // set translation table
  empty_morse_table(t);
  set_translation(t,'A',".-");
  set_translation(t,'V',"...-");
  set_translation(t,'5',".....");
  // check to_ascii()
  CU_ASSERT_EQUAL('A',to_ascii(t,".-"));
  CU_ASSERT_EQUAL('V',to_ascii(t,"...-"));
  CU_ASSERT_EQUAL('5',to_ascii(t,"....."));
  // check to_morse()
  morse_char_t m;
  to_morse(t,'A',m);
  CU_ASSERT_STRING_EQUAL(m,".-");
  to_morse(t,'V',m);
  CU_ASSERT_STRING_EQUAL(m, "...-");
  to_morse(t,'5',m);
  CU_ASSERT_STRING_EQUAL(m,".....");
}

void test_codif2(void) {
  morse_table_t t;
  // set translation table
  empty_morse_table(t);
  set_translation(t,'C',"-.-.");
  set_translation(t,'Z',"--..");
  set_translation(t,'9',"----.");
  // check to_ascii()
  CU_ASSERT_EQUAL('C',to_ascii(t,"-.-."));
  CU_ASSERT_EQUAL('Z',to_ascii(t,"--.."));
  CU_ASSERT_EQUAL('9',to_ascii(t,"----."));
  CU_ASSERT_EQUAL('@',to_ascii(t,".-.-"));//no ascii for ".-.-"
  CU_ASSERT_EQUAL('@',to_ascii(t,"."));//no set_translation for E
  // check to_morse()
  morse_char_t m;
  to_morse(t,'C',m);
  CU_ASSERT_STRING_EQUAL(m,"-.-.");
  to_morse(t,'Z',m);
  CU_ASSERT_STRING_EQUAL(m, "--..");
  to_morse(t,'9',m);
  CU_ASSERT_STRING_EQUAL(m,"----.");
  to_morse(t,'@',m);
  CU_ASSERT_STRING_EQUAL(m,"");//'@' is not on the table
  to_morse(t,'E',m);
  CU_ASSERT_STRING_EQUAL(m,"");//no set_translation for E
  to_morse(t,'\0',m);
  CU_ASSERT_STRING_EQUAL(m,"");//'\0' is not on the table
  to_morse(t,'a',m);
  CU_ASSERT_STRING_EQUAL(m,"");//'a' is not on the table
}

void test_codif3(void) {
  morse_table_t t;
  // set translation table
  empty_morse_table(t);
  set_translation(t,'A',".-");
  set_translation(t,'B',"-...");
  set_translation(t,'C',"-.-.");
  set_translation(t,'D',"-..");
  set_translation(t,'E',".");
  set_translation(t,'F',"..-.");
  set_translation(t,'G',"--.");
  set_translation(t,'H',"....");
  set_translation(t,'I',"..");
  set_translation(t,'J',".---");
  set_translation(t,'K',"-.-");
  set_translation(t,'L',".-..");
  set_translation(t,'M',"--");
  set_translation(t,'N',"-.");
  set_translation(t,'O',"---");
  set_translation(t,'P',".--.");
  set_translation(t,'Q',"--.-");
  set_translation(t,'R',".-.");
  set_translation(t,'S',"...");
  set_translation(t,'T',"-");
  set_translation(t,'U',"..-");
  set_translation(t,'V',"...-");
  set_translation(t,'W',".--");
  set_translation(t,'X',"-..-");
  set_translation(t,'Y',"-.--");
  set_translation(t,'Z',"--..");
  set_translation(t,'1',".----");
  set_translation(t,'2',"..---");
  set_translation(t,'3',"...--");
  set_translation(t,'4',"....-");
  set_translation(t,'5',".....");
  set_translation(t,'6',"-....");
  set_translation(t,'7',"--...");
  set_translation(t,'8',"---..");
  set_translation(t,'9',"----.");
  set_translation(t,'0',"-----");
  // check to_ascii()
  //if m is not a MORSE chain anything is possible (NOT EQUAL is VALID)
  CU_ASSERT_EQUAL('A',to_ascii(t,"a-"));//if '-', else
  CU_ASSERT_EQUAL('A',to_ascii(t,".a"));//if '.', else
  
  CU_ASSERT_EQUAL('\0',to_ascii(t,"------"));//tree[64] if search does not stop at length_tree
  CU_ASSERT_EQUAL('0',to_ascii(t,"------"));//equal if search stops at length_morse
  CU_ASSERT_EQUAL('0',to_ascii(t,"----------"));
  CU_ASSERT_EQUAL('@',to_ascii(t,""));//equal if we consider "" a MORSE chain
  // check to_morse()
  morse_char_t m;
  //EQUAL if table filled with '@' (empty_morse_table) and finished with '\0'
  CU_ASSERT_STRING_EQUAL(t,"@TEMNAIOGKDWRUS@@QZYCXBJP@L@FVH09@8@@@7@@@@@@@61@@@@@@@2@@@3@45");
  //fprintf(stdout,"\n%s\n",t);
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
  CU_ADD_TEST(pSuite1, test_codif1);

  //Suite_2 (STANDARD)
  /* add a suite to the registry */
  CU_pSuite pSuite2 = CU_add_suite("Suite_2 Standard", NULL, NULL);
  if (NULL == pSuite2) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  /* add the tests to the suite2 */
  CU_ADD_TEST(pSuite2, test_codif2);

  //Suite_3 (IMPLEMENTATION) In general not passed
  /* add a suite to the registry */
  CU_pSuite pSuite3 = CU_add_suite("Suite_3 Implementation", NULL, NULL);
  if (NULL == pSuite3) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  /* add the tests to the suite3 */
  CU_ADD_TEST(pSuite3, test_codif3);

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}


