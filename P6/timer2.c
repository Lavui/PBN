#include "timer.h"

#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/atomic.h>


#define N 20

typedef struct{
  uint8_t remaining,every,ntimes;
  timer_callback_t callback;
} entry;

static struct{
  entry t[N];
  uint8_t n;
} tt;


ISR(TIMER1_COMPA_vect){
  ATOMIC_BLOCK(ATOMIC_FORCEON){
    for (int i=0 ; i<N ; i++){
      if (tt.t[i].every != 0){
	if (tt.t[i].remaining == 0){
	  tt.t[i].callback();
	  if (tt.t[i].ntimes != 0)
	    tt.t[i].ntimes--;
	  else
	    tt.t[i].remaining == tt.t[i].every;
	}
	else
	  tt.t[i].remaining--;
      }
    }
  }
}

void timer_init(void){
  TCCR1A = 0b00000000;
  TCCR1B = 0b00001011; //WGM12, CS11, CS10. A 1
  OCR1A  = 24999;
  TCNT1  = 0b00000000;
  TIMSK1 = 0b00000010; //Fiquem OCE1A a 1 per activar interr.
  timer_cancel_all();
  
}

timer_handler_t timer_after(uint8_t ticks, timer_callback_t f){
  return timer_ntimes(1,ticks,f); //nomes executem 1 cop
}

timer_handler_t timer_every(uint8_t ticks, timer_callback_t f){
  return timer_ntimes(0,ticks,f); //execucucio indefinidament
}

timer_handler_t timer_ntimes(uint8_t n,uint8_t ticks,timer_callback_t f){
  uint8_t i=0;
  while (i<N){
    if (tt.t[i].every==0){//si a la taula no hi ha res
      tt.n++; //incrementem el nombre d'accions
      tt.t[i].remaining=ticks; //Comptador de ticks de compte enrera
      tt.t[i].every=ticks; //la crida es fara vada tants ticks
      tt.t[i].ntimes=n; //numero de vegades que executem l'accio
      tt.t[i].callback=f; //passem la funcio f
      
      if(tt.n > 0){
	TCNT1  = 0b00000000; //deixem el comptador a 0
	TIMSK1 = 0b00000010; //activem interrupcions
      }
      else{
	return i;
      }
    }
    else{
      return TIMER_ERR; //No queden posicions lliures
    }
    i++;
  }
}

void timer_cancel(timer_handler_t h){
  tt.t[h].every = 0;
}

void timer_cancel_all(void){
  for (int i=0; i<N ; i++)
    tt.t[i].every=0;
}
