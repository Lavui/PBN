#ifndef ETHER_H
#define ETHER_H


#include "modulator.h"
#include "timer.h"
#include "mtbl.h"
#include "queue.h"
#include "mchar.h"

#include <stdint.h>


#define DOT 50 //50 ms
#define GAP DOT
#define DASH 3*DOT //150 ms
#define LETTERGAP 3*DOT

void ether_init(void); // Inicialitza el modul.

void ether_put(uint8_t c); //Envia un caracter c usant el canal morse

#endif
