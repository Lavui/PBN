#include "lamp.h"
#include <util/delay.h>

int main(){

	lamp_t semafor1;
	lamp_t semafor2;
	lamp_init(&semafor1,&PORTD,5,&PORTD,6,&PORTD,7);
	lamp_init(&semafor2,&PORTD,4,&PORTC,3,&PORTC,2);

	while(1){
	lamp_on(semafor1,Red);
	lamp_toggle(semafor2,Green);
	_delay_ms(700);

	lamp_toggle(semafor1,Red);
	lamp_toggle(semafor1,Yellow);
	lamp_off(semafor2,Green);
	lamp_toggle(semafor2,Yellow);
	_delay_ms(700);

	lamp_toggle(semafor1,Yellow);
	lamp_toggle(semafor1,Green);
	lamp_toggle(semafor2,Yellow);
	lamp_toggle(semafor2,Red);
	_delay_ms(700);

	lamp_toggle(semafor1,Green);
	lamp_toggle(semafor2,Red);
	}
	return 0;
}

