#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "codif.h"
#include "itu.h"
#include "streamencoder.h"

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

void test_streamencoder1(void) {
  FILE *in, *out;
  char buffer[100];
  const struct {char *a,*m;} tests[] = {
    {"AGENT 007",".- --. . -. -  ----- ----- --..."},
    {"CATALA A LATAC","-.-. .- - .- .-.. .-  .-  .-.. .- - .- -.-."},
    {"RAP LLUCET SEITO",".-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---"},
  };
  // initialize environment
  streamencoder_init();
  // iterate over tests ascii->morse
  for (int i=0; i<1; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].a, in); rewind(in);
    do_codifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].m);
    fclose(in); fclose(out);
  }
  // iterate over tests morse->ascii
  for (int i=0; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].m, in); rewind(in);
    do_descodifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].a);
    fclose(in); fclose(out);
  }
}

void test_streamencoder2(void) {
  FILE *in, *out;
  char buffer[100];
  const struct {char *a,*m2;} tests[] = {
    {" AGENT 007",".- --. . -. -  ----- ----- --..."},
    {"  CATALA A LATAC","-.-. .- - .- .-.. .-  .-  .-.. .- - .- -.-."},
    {"            RAP LLUCET SEITO",".-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---"},
  };
  // initialize environment
  streamencoder_init();
  // iterate over tests ascii->morse
  for (int i=0; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].a, in); rewind(in);
    do_codifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    //fprintf(stdout,"\n%s\n",buffer);
    //fprintf(stdout,"%s\n",tests[i].m2);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].m2);
    fclose(in); fclose(out);
  }
}

void test_streamencoder3(void) {
  FILE *in, *out;
  char buffer[100];
  const struct {char *a,*m,*a2,*m2;} tests[] = {
    {"    AGENT     007"," .- --. . -. -  ----- ----- --... ","AGENT 007",".- --. . -. -  ----- ----- --..."},
    {"  CATALA  A  LATAC  "," -.-. .- - .- .-.. .-  .-  .-.. .- - .- -.-. ","CATALA A LATAC","-.-. .- - .- .-.. .-  .-  .-.. .- - .- -.-."},
    {"            RAP           LLUCET      SEITO   "," .-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---  ","RAP LLUCET SEITO",".-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---"},
  };
  // initialize environment
  streamencoder_init();
  // iterate over tests ascii->morse
  for (int i=0; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].a, in); rewind(in);
    do_codifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    //fprintf(stdout,"\n%s\n",buffer);
    //fprintf(stdout,"%s\n",tests[i].m2);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].m2);
    fclose(in); fclose(out);
  }
  // iterate over tests morse->ascii
  for (int i=0; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].m, in); rewind(in);
    do_descodifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    //fprintf(stdout,"\n%s\n",buffer);
    //fprintf(stdout,"%s\n",tests[i].a2);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].a2);
    fclose(in); fclose(out);
  }
}

void test_streamencoder4(void) {
  FILE *in, *out;
  char buffer[100];
  const struct {char *a,*m,*a2,*m2;} tests[] = {
    {"afaf AGENTab c007"," .- --.gagag . -. -  ----- ----- --... ","AGENT 007",".- --. . -. -  ----- ----- --..."},
    {"  fdgCATALA  A  LATACsds  "," -.-. .- - .- .-.. .-  .-  .-.. .- - .- -.-.d","CATALA A LATAC","-.-. .- - .- .-.. .-  .-  .-.. .- - .- -.-."},
    {"    dfgsg        RsgAP   LLUCET      SEIsg???TO           "," .-. .dhshsh- .--. ___ .-.. .-.. ..- -.-. . -  ... . .. - --- shs","RAP LLUCET SEITO",".-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---"},
  };
  // initialize environment
  streamencoder_init();
  // iterate over tests ascii->morse
  for (int i=0; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].a, in); rewind(in);
    do_codifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    //fprintf(stdout,"\n%s\n",buffer);
    //fprintf(stdout,"%s\n",tests[i].m2);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].m2);
    fclose(in); fclose(out);
  }
  // iterate over tests morse->ascii
  for (int i=0; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].m, in); rewind(in);
    do_descodifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    //fprintf(stdout,"\n%s\n",buffer);
    //fprintf(stdout,"%s\n",tests[i].a2);
    CU_ASSERT_STRING_EQUAL(buffer, tests[i].a2);
    fclose(in); fclose(out);
  }
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
   CU_ADD_TEST(pSuite1, test_itu1);
   CU_ADD_TEST(pSuite1, test_streamencoder1);

   //Suite_2 (STANDARD)
   /* add a suite to the registry */
   CU_pSuite pSuite2 = CU_add_suite("Suite_2 Standard", NULL, NULL);
   if (NULL == pSuite2) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   /* add the tests to the suite2 */
   CU_ADD_TEST(pSuite2, test_codif2);
   CU_ADD_TEST(pSuite2, test_itu2);
   CU_ADD_TEST(pSuite2, test_streamencoder2);

   //Suite_3 (IMPLEMENTATION) In general not passed
   /* add a suite to the registry */
   CU_pSuite pSuite3 = CU_add_suite("Suite_3 Implementation", NULL, NULL);
   if (NULL == pSuite3) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   /* add the tests to the suite3 */
   CU_ADD_TEST(pSuite3, test_codif3);
   CU_ADD_TEST(pSuite3, test_itu3);
   CU_ADD_TEST(pSuite3, test_streamencoder3);
   CU_ADD_TEST(pSuite3, test_streamencoder4);

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();

   return CU_get_error();
}


