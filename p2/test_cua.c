#include <stdio.h>
#include <stdbool.h>
#include "cua.h"


int main(void){
  cua_t c;
  cua_buidar(&c);
  printf("\nfirst=%d, last=%d, valids=%d\n\n", c.first, c.last, c.valids);
  return 0;
}
