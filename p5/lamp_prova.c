#include "lamp.h"
#include <util/delay.h>

int main(){

	lamp_t semafor1;
	//lamp_t semafor2;
	lamp_init(&semafor1,&PORTD,5,&PORTD,6,&PORTD,7);
	//lamp_init(&semafor2,&PORTD,5,&PORTD,6,&PORTD,7);
	while(1){
	lamp_off(semafor1,Red);
	lamp_on(semafor1,Green);
	_delay_ms(700);
	}
	return 0;
}

