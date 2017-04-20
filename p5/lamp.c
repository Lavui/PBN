#include "lamp.h"
#include "gpio_device.h"

void lamp_init(
	       lamp_t *const l,
	       volatile uint8_t *prtg, uint8_t pg,
	       volatile uint8_t *prty, uint8_t pg,
	       volatile uint8_t *prtr, uint8_t pr){

  l->green = pin_bind(prtg, pg, Output);
  l->yellow = pin_bind(prty, py, Output); 
  l->red = pin_bind(prtr, pr, Output);
  pin_w(l->green,0);
  pin_w(l->yellow,0);
  pin_w(l->red,0);
}


void lamp_on(lamp_t l, color_t c){
  l->c
}


void lamp_off(lamp_t l, color_t c);{

}


void lamp_toggle(lamp_t l, color_t c);{

}


bool lamp_is_on(lamp_t l, color_t c);{

}

