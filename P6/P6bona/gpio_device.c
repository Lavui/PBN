#include "gpio_device.h"


#define DDR(p) (p-1)

pin_t pin_bind(volatile uint8_t *port, uint8_t pin, pin_direction_t d){
  pin_t t;
  t.port=port;
  t.pin=pin;

  if(d==Input)
    *(t.port+1)&=~(_BV(pin));
  else if(d==Output)
    *(t.port-1)|=(_BV(pin));
  return t;
}

void pin_w(pin_t p, bool v){
  if(bit_is_set(*DDR(p.port),p.pin)){
    if(v)
      *(p.port)=*(p.port)|_BV(p.pin);
    else
      *(p.port)=((*(p.port))&~_BV(p.pin));
  }
}

bool pin_r(pin_t p){
  return(*(p.port)&_BV(p.pin));
  }

void pin_toggle(pin_t p){
  if(bit_is_set(*p.port,p.pin))
    *(p.port) = ((*(p.port))&~_BV(p.pin));
  else
    *(p.port) = ((*(p.port))|_BV(p.pin));
}

void pin_unbind(pin_t *const p){
  (*p).port=NULL;
}
