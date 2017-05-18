
#include <avr/io.h>
//#include <avr/interrupt.h>
#include "control.h"


#define CLEAR 80
#define APPROACH 20
#define OFF 0

static street_t carrer;
static estat_general estatgen;
static uint8_t ticks;
static semaph_t semafor1,semafor2;

void cont(void);

void cont(void){
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
      semaphore_set(&semafor1,SemApproach);
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
      ticks=APPROACH;
      break;
    }
  else
    ticks--;
}

void control_init(void){
  semaph_init(&semafor1,&PORTD,5,&PORTD,6,&PORTD,7);
  semaph_init(&semafor2,&PORTD,4,&PORTC,3,&PORTC,2);
  estatgen=ABoff;
  ticks=OFF;
}

void control_on(void){
  if(estatgen==ABoff){
    estatgen=Aclear;
    ticks=OFF;
  }
  timer_every(TIMER_MS(100),cont);
}

void control_off(void){
  estatgen = ABoff;
  ticks = OFF;
  semaphore_set(&semafor1,SemOff);
  semaphore_set(&semafor2,SemOff);
}

semaph_state_t control_get_state(street_t s){
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

    case StreetB:
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
