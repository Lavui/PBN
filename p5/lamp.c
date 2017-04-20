#include "lamp.h"

void lamp_init(
	       lamp_t *const l,
	       volatile uint8_t *prtg, uint8_t pg,
	       volatile uint8_t *prty, uint8_t py,
	       volatile uint8_t *prtr, uint8_t pr){

  l->green = pin_bind(prtg, pg, Output);
  l->yellow = pin_bind(prty, py, Output); 
  l->red = pin_bind(prtr, pr, Output);
  pin_w(l->green,0);
  pin_w(l->yellow,0);
  pin_w(l->red,0);
}


void lamp_on(lamp_t l, color_t c){
  switch (c){
  case Green:
    pin_w(l.green,true);
    break;
  case Red:
    pin_w(l.red,true);
    break;
  case Yellow:
    pin_w(l.yellow,true);
    break;
  default:
    break; //Catch all condition, no es complira.
  }
}



void lamp_off(lamp_t l, color_t c){
  switch (c){
  case Green:
    pin_w(l.green,false);
    break;
  case Red:
    pin_w(l.red,false);
    break;
  case Yellow:
    pin_w(l.yellow,false);
    break;
  default:
    break; //Catch all condition, no es complira.
  }
}


void lamp_toggle(lamp_t l, color_t c){
  switch (c){
  case Green:
    pin_toggle(l.green);
    break;
  case Red:
    pin_toggle(l.red);
    break;
  case Yellow:
    pin_toggle(l.yellow);
    break;
  default:
    break; //Catch all condition, no es complira.
  }
}


bool lamp_is_on(lamp_t l, color_t c){
  switch (c){
  case Green:
    bit_is_set(l.green.port,l.green.pin);
    break;
  case Red:
    pin_toggle(l.red.port,l.red.pin);
    break;
  case Yellow:
    pin_toggle(l.yellow.port,l.yellow.pin);
    break;
  default:
    break; //Catch all condition, no es complira.
  }
}


