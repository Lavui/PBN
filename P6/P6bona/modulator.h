#ifndef MODULATOR_H
#define MODULATOR_H

#include <stdbool.h>

void modulator_init(void); //Inicialitzem modul i el deixem en estat baix

void modulator_set(bool I );//Canviem la sortida, si la I es true activa la portadora

#endif
