
#include <avr/io.h>
#include "queue.h"
#include "serial_device.h"


static queue_t cua_rx,cua_tx; /*Inicialitzem les variables, ja que seran utilitzades en tot el modul*/

ISR(USART_RX_vect){
  queue_enqueue(&cua_rx, UDR0); /* Encuem el valor escrit a UDR0. No fa falta desactivar la interrupció  */
}

ISR(USART_UDRE_vect){
  if(queue_is_empty(&cua_tx))
    UCSR0B &= ~(1 << UDRIE0); /* Si no tenim valors a la cua de tranmissió, desactivem aquesta rutina d'interrupció. La tornarem a activar si fem un serial_put */
  else{
    UDR0 = queue_front(&cua_tx); /* Fiquem el primer valor de la cua i desencuem */
    queue_dequeue(&cua_tx);
  }
}

void serial_open(void){
  UBRR0H = UBRR0H & 0; /* Baud rate 9600 */
  UBRR0L = 103; 

  UCSR0A = UCSR0A & ~_BV(U2X0); /*Desactivem USART Double Transmission Speed*/
  UCSR0A = UCSR0A | _BV(UDRE0); /* Podem transmetre a l'inici */
  UCSR0B = 184; /* Activem TX i RX amb rutina d'interrupció RX i interrupcio UDR Empty. 0b10111000*/
  /*UCSR0B = 152; Activem TX i RX amb rutina d'interrupció RX */
  UCSR0C = 6; /*8 dades. Frame size 8 bit. 2 bits*/

  queue_empty(&cua_rx);
  queue_empty(&cua_tx); /*Inicialitzem les cues de transmissió i recepció*/
}

void serial_close(void){
  loop_until_bit_is_set(UCSR0A,UDRE0); /* Esperem que el buffer estigui buit */
  UCSR0B = UCSR0B & ~(_BV(RXCIE0)); /* Desactivem rutina recepció */

}

uint8_t serial_get(void){
  while(queue_is_empty(&cua_rx)); /* Si la cua esta buida no podem retornar res */
  uint8_t valor_rx = queue_front(&cua_rx); /* Agafem el primer valor i desencuem */
  queue_dequeue(&cua_rx);
  return valor_rx;
}

void serial_put(uint8_t c){
  while(queue_is_full(&cua_tx)); /* Si la cua de transmissió està plena, no podem afegir més valors */
  queue_enqueue(&cua_tx,c);
  UCSR0B |= _BV(UDRIE0); /* Activem la tranmissió UDR empty */
}

bool serial_can_read(void)
{
  return bit_is_set(UCSR0A,RXC0);
}
