#include "semaphore.h"
#include "gpio_device.h"

#include <stdio.h>
#include <stdbool.h>

semaphore_state_t estatS;
pin_t lverd,ltaro,lverm;

void semaphore_init(void){
  lverd=pin_bind(&PORTD,5,Output);
  ltaro=pin_bind(&PORTD,6,Output);
  lverm=pin_bind(&PORTD,7,Output);

  pin_w(lverd,false);
  pin_w(ltaro,false);
  pin_w(lverm,false);
  
  estatS=SemaphoreOff;
}

void semaphore_next(void){
  switch (estatS){
  case SemaphoreClear:
    pin_w(lverd,false);
    pin_w(ltaro,true);
    estatS=SemaphoreApproach;
    break;
  case SemaphoreApproach:
    pin_w(ltaro,false);
    pin_w(lverm,true);
    estatS=SemaphoreStop;
    break;
  case SemaphoreStop:
    pin_w(lverm,false);
    pin_w(lverd,true);
    estatS=SemaphoreClear;
    break;      
  }
}



void semaphore_set(semaphore_state_t s){
  switch (s){
  case SemaphoreClear:
    pin_w(lverd,true);
    pin_w(ltaro,false);
    pin_w(lverm,false);
    estatS=SemaphoreClear;
    break;
  case SemaphoreApproach:
    pin_w(lverd,false);
    pin_w(ltaro,true);
    pin_w(lverm,false);
    estatS=SemaphoreApproach;
    break;
  case SemaphoreStop:
    pin_w(lverd,false);
    pin_w(ltaro,false);
    pin_w(lverm,true);
    estatS=SemaphoreStop;
    break;  
  case SemaphoreOff:
    pin_w(lverd,false);
    pin_w(ltaro,false);
    pin_w(lverm,false);
    estatS=SemaphoreOff;
  }
}


//Per provarlo executar modul prova_semaphore.c
