#include "modulator.h"
#include <stdbool.h>
#include <avr/io.h>

void modulator_init(void){
  DDRD &= ~_BV(DDD6);//Fiquem el pin 6 com a sortida
  PORTD &= ~_BV(PD6);//Lectura del pin6 del portb
  TCNT1 = 0x00;//interrupcions del timer
  OCR1A = 24999;
  TCCR1A = 0x00 ; //contador del registre a
  TCCR1B = _BV(WGM12) | _BV(CS11) | _BV(CS10); //0b00001011
  OCR0A = 0b00001001;//9
}

void modulator_set(bool l){
  if (l){
    DDRD |= _BV(PD6);
  }
  else{
    DDRD &= ~_BV(PD6);
  }
}

