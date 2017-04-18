#include "controlsem.h"
#include <util/delay.h>


#define INTERVAL 100

int main(void){
  controlsem_init();
  while(1){
    _delay_ms(INTERVAL);
    tick_semaphore();
    tick_monitor();
  }
  return 0;
}
