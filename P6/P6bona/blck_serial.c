#include "blck_serial.h"
#include "serial_device.h"
#include <ctype.h>

void print(char s[]) {
  uint8_t i=0;
  while(s[i] != '\0') {
    serial_put(s[i++]);
  }
  serial_put('\r');
  serial_put('\n');
}
int readline(char s[], uint8_t m) {
  uint8_t i=0, e;
  while (i<m && isgraph(e=serial_get())) {
    s[i++]=e;
  }
  s[i]='\0';
  return i;
}

