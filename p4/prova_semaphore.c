#include "gpio_device.h"
#include "semaphore.h"

semaphore_state_t ara;

int main() {
  semaphore_init();
  _delay_ms(3000);
  semaphore_set(SemaphoreApproach);
  while(1){
    _delay_ms(1000);
    semaphore_next();

    _delay_ms(1000);
    semaphore_next();

    _delay_ms(1000);
    semaphore_next();

    _delay_ms(1000);
    ara=SemaphoreOff;
    semaphore_set(ara);

    _delay_ms(1000);
    ara=SemaphoreStop;
    semaphore_set(ara);

    _delay_ms(1000);
    ara=SemaphoreApproach;
    semaphore_set(ara);

    _delay_ms(1000);
    semaphore_next();

  }
}




