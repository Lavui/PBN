

/*#include <stdbool.h>
  #include <stdin.h>*/

#include <avr/sfr_defs.h>
#include <avr/io.h>
#include "serial_device.h"



void serial_init(void){

//Ubr0 indica la velocitat de transmisio del UART (el cable blau)
  UBRR0H = 0b00000000;
  UBRR0L = 0b01100111; //103 Mb/s  


  //!IMPORTANT!//
  //L'arduino te tres registres de configuracio, el UCR0A,B,C.
  //Per tal de no inferir amb els altres bits de la configuracio fem masqueres.
  
  UCSR0A &= ~_BV(U2X0); //Aqui, els noms raros u2x0,rxen... nomes son bits del registre UCSR0A, aquest en concret (U2X0)
  //duplica la teva velocitat de transmisio, aqui fem una mascara per ficara a 0 aquell element

  UCSR0B = _BV(RXEN0) | _BV(TXEN0);//REXN I TEXN son els de transmisio i recepcio, aqui fem una mascara per ficar a 1 aquests dos en
  //el registre UCSRB

  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00) &
    ~_BV(UMSEL01) & ~_BV(UMSEL00) &
    ~_BV(UPM01) & ~_BV(UPM00) &
    ~ _BV(USBS0);
  //Olrait, posat a plorar: Els dos primers UCSZ ens indiquen el tamany de caracter que rebra l'arudino
  //ELs dos UML a 0 fiquen el arduino a mode asincron
  //I finalment en el USBS fiquem els bits de stop

}

uint8_t serial_get(void){
  loop_until_bit_is_set(UCSR0A,RXC0); //Observem si s'ha activat el bit de recepcio
  return UDR0;
}

void serial_put(uint8_t c){
  loop_until_bit_is_set(UCSR0A, UDRE0); //Observem si el registre esta buit. Quan esta buit carrega el caracter al registre.
  UDR0=c;
}

bool serial_can_read(void){
  if(bit_is_set(UCSR0A,RXC0)) // Mirem si la recepcio esta lliure. Retorna boolea.
    return true;
  else
    return false;
}

