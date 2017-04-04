#include "serial_device.h"
#include <stdint.h>

int main(){
  uint8_t a;
  serial_init();
  while(1){ /*Prova d'eco*/
    a=serial_get();
    serial_put(a);
  }
  return 0;
}
