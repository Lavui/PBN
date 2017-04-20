#include <stdio.h>
#include <stdint.h>


int read_byte(void) {
  uint8_t n;

  printf("byte en hec (2 simb): ");
  scanf("%2hhx",&n);
  
  printf("%d \n",n);
  return n;

}

void write_byte(uint8_t b) {
  printf("Write_byte -> %x \n",b);
  return ;
}

int main(void) {
  uint8_t s;
  s=read_byte();
  write_byte(s);
  return 0;
}
