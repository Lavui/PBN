#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "codif.h"
#include "itu.h"
#include "streamencoder.h"

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
  for (int i=0; i<3; i++) {
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
    /* printf("\n%s\n%s\n",buffer, tests[i].m2); */
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
    {"            RAP           LLUCET      SEITO   "," .-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---   ","RAP LLUCET SEITO",".-. .- .--.  .-.. .-.. ..- -.-. . -  ... . .. - ---"},
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
  for (int i=2; i<3; i++) {
    in  = tmpfile(); out = tmpfile();
    fputs(tests[i].m, in); rewind(in);
    do_descodifica(in, out); rewind(out);
    fgets(buffer, 100, out);
    fprintf(stdout,"\n%s\n",buffer);
    fprintf(stdout,"%s\n",tests[i].a2);


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
   CU_ADD_TEST(pSuite1, test_streamencoder1);


   //Suite_2 (STANDARD)
   /* add a suite to the registry */
   CU_pSuite pSuite2 = CU_add_suite("Suite_2 Standard", NULL, NULL);
   if (NULL == pSuite2) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   /* add the tests to the suite2 */
   CU_ADD_TEST(pSuite2, test_streamencoder2);

   //Suite_3 (IMPLEMENTATION) In general not passed
   /* add a suite to the registry */
   CU_pSuite pSuite3 = CU_add_suite("Suite_3 Implementation", NULL, NULL);
   if (NULL == pSuite3) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   /* add the tests to the suite3 */
   CU_ADD_TEST(pSuite3, test_streamencoder3);
   CU_ADD_TEST(pSuite3, test_streamencoder4);

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();

   return CU_get_error();
}


