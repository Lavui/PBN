
/*#include <stdbool.h>
  #include <stdin.h>*/

#include <avr/sfr_defs.h>
#include <avr/io.h>
#include "serial_device.h"



void serial_init(void){
  UBRR0H = 0b00000000;
  UBRR0L = 0b01100111;

  UCSR0A = UCSR0A & ~_BV(U2X0);

  UCSR0B = 0b00011000; /* Activem TX i RX */
  UCSR0C = 0b00000110; /*8 dades*/
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

