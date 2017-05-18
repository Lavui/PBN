#ifndef ETHER_H
#define ETHER_H

#include <stdint.h>

void ether_init(void);
/* Inicialitza el mòdul. Cal cridar-la abans d’usar el mòdul i amb
les interrupcions inhibides. Es pot cridar més d’una vegada i
s’obté el mateix efecte. */

void ether_put(uint8_t c);
/* Envia el caràcter c usant el canal morse. c ha de contenir un
dels caràcters que admeten codificació morse: els caràcters A–Z,
els dı́gits 0–9 i el caràcter espai. */

#endif
