#include "modulator.h"
#include <avr/io.h>
#include "gpio_device.h" 


static pin_t t;

void modulator_init(void){
  /*
  DDRB|=(_BV(3)); // Port a OUTPUT  
  PORTB&=~(_BV(3));
  // TCCR2A&=~(_BV(COM2A0)); // Desconectar timer 2 

  TCCR2A = 0b01000010;
  TCCR2B = 0b11000100;

  OCR2A = 39;

  uint8_t pinBru = 11;
  t = pin_bind(&PORTB,pinBru,Output);
  */

  DDRB|=(_BV(3)); /* Port a OUTPUT  */
  PORTB&=~(_BV(3));
  TCCR2A&=~(_BV(COM2A0)); /* Desconectar timer 2 */
  OCR2A=39; /* 00101000, 40 */  
  TCCR2A|=_BV(WGM21);     /* CTC MODE */
  TCCR2B|=_BV(CS22);  /* PRESCALER 64  */ 
  TCNT2 = 0; /* INICIALITZAR TIMER A 0 */
  

}

void modulator_set(bool l){
  if (l){
    TCCR2A |= _BV(COM2A0);
  }
  else{
    TCCR2A &= ~_BV(COM2A0);
    TCNT2= 0;
    PORTB&=~(_BV(3));
    // pin_w(t,false);
  }
}

