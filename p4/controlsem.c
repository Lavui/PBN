#include "controlsem.h"
#include "serial_device.h"
#include "semaphore.h"

#include <stdint.h>

#define CLEAR 40
#define APPROACH 10
#define STOP 60


static semaphore_state_t estatS;
static uint8_t tick;


void controlsem_init(void){
  semaphore_init();
  serial_init();
  semaphore_set(SemaphoreOff);
  estatS=SemaphoreOff;
  tick=0;
}

void tick_monitor(void){
  uint8_t ordre;
  if (serial_can_read()){ /*si s'ha escrit al port serie*/
    ordre=serial_get(); /*escrivim el valor del buffer a ordre*/

    switch (ordre){
    case 'E':
      if (estatS!=SemaphoreOff){
	semaphore_set(SemaphoreClear);
	estatS=SemaphoreClear;
	tick=CLEAR;
	serial_put('E');
	serial_put('M');
	serial_put('E');
	serial_put('R');
	serial_put('G');
	serial_put('E');
	serial_put('N');
	serial_put('C');
	serial_put('Y');
	serial_put('\n');
      }
      else{
	serial_put('E');
      	serial_put('\n');
      }
      break;

    case 'S':
      if (estatS!=SemaphoreOff){
	semaphore_set(SemaphoreOff);
	estatS=SemaphoreOff;
	tick=0;
	serial_put('S');
	serial_put('H');
	serial_put('U');
	serial_put('T');
	serial_put('D');
	serial_put('O');
	serial_put('W');
	serial_put('N');
	serial_put('\n');
      }
      else{
	serial_put('E');
      	serial_put('\n');
      }
      break;
      
    case 'R':
      if (estatS==SemaphoreOff){
	semaphore_set(SemaphoreClear);
	estatS=SemaphoreClear;
	tick=CLEAR;
	serial_put('R');
	serial_put('E');
	serial_put('S');
	serial_put('T');
	serial_put('A');
	serial_put('R');
	serial_put('T');
	serial_put('\n');
      }
      else{
	serial_put('E');
      	serial_put('\n');
      }
      break;
      
    case '\n':
      serial_put('0');
      break;

    default:
      serial_put('E');
      serial_put('\n');
      
    }
  }
}

void tick_semaphore(void){
  if(estatS!=SemaphoreOff){
    switch (tick){

    case 0:
      semaphore_next();
      switch (estatS){
      case SemaphoreClear:
	estatS=SemaphoreApproach;
	tick=APPROACH;
	break;

      case SemaphoreApproach:
	estatS=SemaphoreStop;
	tick=STOP;
	break;

      case SemaphoreStop:
	estatS=SemaphoreClear;
	tick=CLEAR;
      }
      break;
      
    default:
      tick--;
    }
  }
}

