#include "timer.h"
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static timer_handler_t h;
/* static pin_t p; */

static void commuta_led(void){
  PINB|=(_BV(5));
  /* pin_toggle(p); */
}

static void apaga_led(void){ 
  /* pin_w(p,0); */
  PINB &=~(_BV(5));
  
}

static void atura_intermitent(void){
  timer_cancel(h);
  apaga_led();
}
int main(){
  /* p=pin_create(&PORTB,4,Output);  */
  DDRB=255;
  timer_init();
  sei();

  h = timer_every(TIMER_MS(200),commuta_led); 
  timer_after(TIMER_MS(2500),atura_intermitent);
  while(true);
  return 0;
}
