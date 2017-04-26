#include "semaph.h"


void semaph_init(semaph_t *const s,
		 volatile uint8_t *port_green, uint8_t pin_green,
		 volatile uint8_t *port_yell, uint8_t pin_yell,
		 volatile uint8_t *port_red, uint8_t pin_red){
  lamp_init((&s->l),
	    port_green,
	    pin_green,
	    port_yell,
	    pin_yell,
	    port_red,
	    pin_red);
  s->s = SemOff;
}


void semaphore_set(semaph_t *const sem, semaph_state_t s){
  sem->s = s;
  switch(s){
  case SemOff:
    lamp_off(sem->l,Green);
    lamp_off(sem->l,Yellow);
    lamp_off(sem->l,Red);
    break;
  case SemClear:
    lamp_on(sem->l,Green);
    lamp_off(sem->l,Yellow);
    lamp_off(sem->l,Red);
    break;
  case SemApproach:
    lamp_off(sem->l,Green);
    lamp_on(sem->l,Yellow);
    lamp_off(sem->l,Red);
    break;
  case SemStop:
    lamp_off(sem->l,Green);
    lamp_off(sem->l,Yellow);
    lamp_on(sem->l,Red);
    break;
  default:
    lamp_off(sem->l,Green);
    lamp_off(sem->l,Yellow);
    lamp_off(sem->l,Red);
    break;
  }
}

semaph_state_t semaph_get(const semaph_t sem){
  return sem.s;
}
