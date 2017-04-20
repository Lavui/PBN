#include <stdio.h>
#include <stdint.h>


int main(void) {
  uint16_t n;
  char masc;
  masc=0b0111111111111110;

  printf("2 bytes en hex (4 simbols): \n");
  scanf("%x",&n);
  n=masc&n;
  printf("Paraula: %i\n",n);
  return 0;
}
