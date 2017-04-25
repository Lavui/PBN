#include "serial_device.h"
#include <avr/interrupt.h>

int main(void){
  serial_open(); /* Iniciem el port serie */
  sei(); /* Activem interrupcions global */
  while(1){
    serial_put(serial_get()); /* Fem un eco */
  }
  serial_close(); /* Tanquem el port serie */
  return 0;
}
