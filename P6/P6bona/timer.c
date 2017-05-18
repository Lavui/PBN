#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define clk_freq 16000000        // frequencia en Hz
#define prescaler 64
#define target_T 0.01             // periode en segons
#define OCR_value (clk_freq*(target_T/prescaler)-1)

#define N 20

typedef struct {
  uint8_t remaining, every, ntimes;
  timer_callback_t callback;
} entry;

static struct {
  entry t[N];
  uint8_t n;
} tt;

void timer_init(void) {
  timer_cancel_all();

 /* Configuracio del timer */
  TCCR1A &= ~(_BV(WGM10) | _BV(WGM11)); // WGM10 WGM11 = 00
  TCCR1B |= _BV(WGM12);                 // WGM12 = 1
  TCCR1B &= ~(_BV(WGM13));              // WGM13 = 0
  OCR1A  = OCR_value;
}  

timer_handler_t timer_after(uint8_t ticks, timer_callback_t f) {
  return timer_ntimes(1, ticks, f);
}

timer_handler_t timer_every(uint8_t ticks, timer_callback_t f) {
  return timer_ntimes(0, ticks, f);
}

timer_handler_t timer_ntimes(uint8_t n, uint8_t ticks, timer_callback_t f) {
  uint8_t i;
  
  for(i=0;i<N;i++) {
    if(tt.t[i].every==0) {
      tt.n++;
      tt.t[i].remaining=ticks;
      tt.t[i].every=ticks;
      tt.t[i].ntimes=n;
      tt.t[i].callback=f;
      
      /* Si es la primera accio planificada activem el timer */
      if(tt.n==1) {
	TCCR1B |= (_BV(CS10) | _BV(CS11));    // prescaler=64
	TCCR1B &= ~(_BV(CS12));               // CS12 CS11 CS10 = 011
	TIMSK1 |= _BV(OCIE1A);
      }
      return i;
    }
  }
  return TIMER_ERR;  // esta ple
}

void timer_cancel(timer_handler_t h) {
  if(h<N) {
    tt.t[h].every=0;
    if(tt.n) tt.n--; // per evitar n negatiu a causa de repetits timer_cancels
  }

  /* Si hem cancelat la ultima accio planficada parem el timer */
  if (tt.n<1) {
    TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
    TIMSK1 &= ~(_BV(OCIE1A));
  }
}

void timer_cancel_all(void) {
  uint8_t i;
  for(i=0;i<N;i++) {
    tt.t[i].every=0;
  }
  tt.n=0;
  /* Desactivem el timer */
  TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
  TIMSK1 &= ~(_BV(OCIE1A));
}

ISR(TIMER1_COMPA_vect) {
  uint8_t i;
  for(i=0;i<N;i++) {
    if (tt.t[i].every) {
      tt.t[i].remaining--;

      if (tt.t[i].remaining==0) {
	(tt.t[i].callback)();
	
	if (tt.t[i].ntimes==1) tt.t[i].every=0;
	else if (tt.t[i].ntimes==0) tt.t[i].remaining=tt.t[i].every;
	else {
	  tt.t[i].ntimes--;
	  tt.t[i].remaining=tt.t[i].every;
	}
      }
    }
  }
}
 
	
