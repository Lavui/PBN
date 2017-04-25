#define CLEAR 80
#define APPROACH 20
#define OFF 0

#include <avr/io.h>
#include <avr/interrupt.h>
#include "semaph.h"
#include "control.h"


static street_t carrer;
static estat_general estatgen;
static uint8_t tick;
static semaph_t semafor1,semafor2;

ISR(TIMER1_COMPA_vect){
  if(ticks==0)
    switch(estatgen){
    case Aclear:
      semaphore_set(&semafor1,SemClear);
      semaphore_set(&semafor2,SemStop);
      estatgen=AtoB;
      ticks=CLEAR;
      break;
    case AtoB:
      semaphore_set(&semafor2,SemStop);
      sempahore_set(&semafor1,SemApproach);
      estatgen=Bclear;
      ticks=APPROACH;
      break;
    case Bclear:
      semaphore_set(&semafor2,SemClear);
      semaphore_set(&semafor1,SemStop);
      estatgen=BtoA;
      ticks=CLEAR;
      break;
    case BtoA:
      semaphore_set(&semafor2,SemApproach);
      semaphore_set(&semafor1,SemStop);
      estatgen=Aclear;
      tick=APPROACH;
      break;
    }
  else
    ticks--;
}

void control_init(void){
  semaph_init(&semafor1,&PORTD,5,&PORTD,6,&PORTD,7);
  semaph_init(&semafor2,&PORTD,4,&PORTC,3,&PORTC,2);

  TCCR1A &= ~(_BV(WGM10)); 
  TCCR1A &= ~(_BV(WGM11)); 
  TCCR1B |= _BV(WGM12); 
  TCCR1B &= ~(_BV(WGM13));

  OCR1A=0x61a7;

  estatgen=ABoff;
  ticks=OFF;
}

void control_on(void){
  if(estatgen==ABoff){
    estatgen=Aclear;
    ticks=OFF;
    TIMSK1 |= _BV(OCIE1A);
    TCCR1B |= _BV(CS10); 
    TCCR1B |= _BV(CS11); 
    TCCR1B &= ~(_BV(CS12)); 
  }
}

void control_off(void){
  
  TCCR1B &= ~(_BV(CS10)); //Matem timer
  TCCR1B &= ~(_BV(CS11)); 
  TCCR1B &= ~(_BV(CS12)); 
  
  TIMSK1 &= ~(_BV(OCIE1A));//Mato la interrupcio
  
  estatgen = ABoff;
  ticks = OFF;
  semaphore_set(&semafor1,SemOff);
  semaphore_set(&semafor2,SemOff);
}

semaph_stat_t control_get_state(street_t s){
  switch(s){
  case StreetA:
    return semaph_get(semafor1);
    break;
  case StreetB:
    return semaph_get(semafor2);
    break;
  }
}

void control_force(street_t t){
  if(estatgen!=ABoff)
    switch(t){
    case StreetA:
      if(semaph_get(semafor1)==SemClear || semaph_get(semafor1) ==SemApproach){
	estatgen=Aclear;
	ticks=0;
      }
      else if(semaph_get(semafor2)!=SemApproach){
	estatgen=BtoA;
	ticks=0;
      }
      break;

    case StreetB_
      if(semaph_get(semafor2)==SemApproach || semaph_get(semafor2) == SemClear){
	estatgen=Bclear;
	ticks=0;
      }
      else if(semaph_get(semafor1)!=SemApproach){
	estatgen=AtoB;
	ticks=0;
      }
    break;
    }
}
z
