#include "modulator.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void){
  modulator_init();
  
  _delay_ms(2000);
  modulator_set(true);
  _delay_ms(3000);
  modulator_set(false);
  _delay_ms(2000);
  modulator_set(true);
  _delay_ms(2000);
  modulator_set(false);
  
  return 0;
  
}
