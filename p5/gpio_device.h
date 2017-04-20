#ifndef GPIO_DEVICE_H
#define GPIO_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

#define NULL 0


typedef enum {Input, Output} pin_direction_t;

typedef struct{
  volatile uint8_t *port;
  uint8_t pin;
}pin_t;

pin_t pin_bind(volatile uint8_t *port, uint8_t pin, pin_direction_t d);
//Retorna un objecte pin_t associat al pin numero PIN del port PORT i inicialitza en mode D

void pin_w(pin_t p, bool v);
//Escriu un valor en el pin p, el pin ha de estar associat i en mode output

bool pin_r(pin_t p);
//llegeix un valor del pin p

void pin_toogle(pin_t p);
//conmuta el valor del pin p

void pin_unbind(pin_t *const p);
//desasocia el pin p

#endif
