#include <avr/interrupt.h>
#include <util/delay.h>
#include "control.h"

int main(){
  control_init();
  sei();
  control_on();
  _delay_ms(2000);
  control_force(StreetB);
  while(1){
    /*
      control_on();
      _delay_ms(7000);
      control_off();
      _delay_ms(3000);
    */
  }
  return 1;
}
