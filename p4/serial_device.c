

/*#include <stdbool.h>
  #include <stdin.h>*/

#include <avr/sfr_defs.h>
#include <avr/io.h>
#include "serial_device.h"



void serial_init(void){

  UBRR0H = 0b00000000;
  UBRR0L = 0b01100111;  

  UCSR0A &= ~_BV(U2X0);

  UCSR0B = _BV(RXEN0) | _BV(TXEN0);

  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00) &
    ~_BV(UMSEL01) & ~_BV(UMSEL00) &
    ~_BV(UPM01) & ~_BV(UPM00) &
    ~ _BV(USBS0);



}

uint8_t serial_get(void){
  loop_until_bit_is_set(UCSR0A,RXC0);
  return UDR0;
}

void serial_put(uint8_t c){
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0=c;
}

bool serial_can_read(void){
  if(bit_is_set(UCSR0A,RXC0))
    return true;
  else
    return false;
}

