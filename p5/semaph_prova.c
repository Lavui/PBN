#include "semaph.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void){
	semaph_state_t estat1;
	semaph_t semafor1;

	semaph_state_t estat2;
	semaph_t semafor2;

	semaph_init(&semafor1,&PORTD,5,&PORTD,6,&PORTD,7);
	semaph_init(&semafor2,&PORTD,4,&PORTC,3,&PORTC,2);

	while(1){
	semaphore_set(&semafor1, SemClear);
	semaphore_set(&semafor2, SemStop);
	_delay_ms(300);
	semaphore_set(&semafor1, SemApproach);
	semaphore_set(&semafor2, SemApproach);
	_delay_ms(300);
	semaphore_set(&semafor1, SemStop);
	semaphore_set(&semafor2, SemClear);
	_delay_ms(300);
}
	return 0;
}
