#ifndef CONTROL_H
#define CONTROL_H

#include "semaph.h"
#include "timer.h"

typedef enum {StreetA,StreetB} street_t;

typedef enum {Aclear, Bclear, AtoB, BtoA, ABoff} estat_general;

void control_init(void);

//Inicialitza el modul de control, inicien apagats i cal engegarlos

void control_force(street_t t);

//Força el carrer t a l'estat Clear. Respecta els temps de seguretat establers

void control_off(void);

//Apaga els semafors de la cruilla

void control_on(void);

//Engega els semafors de la cruilla

semaph_state_t control_get_state(street_t s);

//Retorna l'estat del semafor del carrer s


#endif
