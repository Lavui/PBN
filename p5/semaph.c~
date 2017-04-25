#ifndef SEMAPH_H
#define SEMAPH_H

#include "lamp.h"
#include <stdint.h>


typedef enum{
  SemOff,
  SemClear,
  SemApproach,
  SemStop,
} semaph_state_t;
//

typedef struct{
  lamp_t l;
  semaph_state_t s;
} semaph_t;
//Representa un semafor implementat per una lampada


void semaph_init(semaph_t *const s,
		 volatile uint8_t *port_green, uint8_t pin_green,
		 volatile uint8_t *port_yell, uint8_t pin_yell,
		 volatile uint8_t *port_red, uint8_t pin_red);
//Inicialitza el modul. Cal cridar-la obligatoriament abans d'usar cap altra funcio del modul. Els parametres port_X i pin_X indiquen on es troba connectada la lampada. Una vegada inicialitzat el modul el semafor es troba en estat SemOff.

void semaphore_set(semaph_t *const sem, semaph_state_t s);
//Força el semafor sem a un estat concret determinat pel parametre s.

semaph_state_t semaph_get(const semaph_t sem);
//Retorna l'estat en que es troba el semafor sem.


#endif
