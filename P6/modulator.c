#include "modulator.h"
#include <stdbool.h>
#include <avr/io.h>

void modulator_init(void){
    TCCR2A=0b00000010;
    TCCR2B=0b00000000;//Deixem timer en off
    OCR2A= 0b00101000;

    DDRD |= ~((1<<DDD0) | (1<<DDD1));
    PIND &= 0b

}