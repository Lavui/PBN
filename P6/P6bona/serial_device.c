#include "serial_device.h"
#include "queue.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/* Definim les cues de transmissió i recepció */
static queue_t tx, rx;
  
void serial_open(void) {
  UBRR0H = 0;
  UBRR0L = 103;		                             /* set BAUD RATE 9600              */
  UCSR0A &= _BV(UDRE0);
  UCSR0B =  _BV(RXCIE0) | _BV(RXEN0) | _BV(TXEN0);   /* Enable RX, TX, and RX interrupt */
  UCSR0C =  _BV(UCSZ01) | _BV(UCSZ00);               /* 8-bit data                      */

  /* No se si aquest és el millor lloc per inicialitzar les cues */
  queue_init(&tx); 
  queue_init(&rx);
}

void serial_close(void) {
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UCSR0B &= ~(_BV(RXCIE0) | _BV(RXEN0) | _BV(TXEN0));
}

uint8_t serial_get(void) {
  uint8_t e;
  while (queue_is_empty(&rx));  /* Bloquejat mentre la cua rx estigui buida */
  e=queue_front(&rx);
  queue_dequeue(&rx);
  return e;
}

void serial_put(uint8_t c) {
  while (queue_is_full(&tx));  /* Bloquejat mentre la cua tx estigui plena */
  queue_enqueue(&tx, c);
  UCSR0B |= _BV(UDRIE0);       /* Activem el DATA REGISTER EMPTY INTERRUPT */
}

bool serial_can_read(void) {
  return queue_is_empty(&rx) ? false : true;
}

ISR(USART_RX_vect) {
  queue_enqueue(&rx, UDR0);
}

ISR(USART_UDRE_vect) {
  if (!(queue_is_empty(&tx))) {
    UDR0=queue_front(&tx);
    queue_dequeue(&tx);
  }
  else {                      /* Un cop transmes tot desactivem el DATA REGISTER EMPTY INTERRUPT */
    UCSR0B &= ~(_BV(UDRIE0)); 
  }
}
