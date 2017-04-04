#include "gpio_device.h"

int main(){
  pin_t LVERD;
  pin_t LTARONJA;
  pin_t LVERMELL;

  LVERD = pin_bind(&PORTD,5,Output);
  LTARONJA = pin_bind(&PORTD,6,Output);
  LVERMELL = pin_bind(&PORTD,7,Output);

  while(1){
    pin_w(LVERD,true);
    _delay_ms(500);
    pin_w(LVERD,false);

    pin_w(LTARONJA,true);
    _delay_ms(500);
    pin_w(LTARONJA,false);

    pin_w(LVERMELL,true);
    _delay_ms(3000);
    pin_w(LVERMELL,false);
  }


  return 0;
}
