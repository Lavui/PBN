#ifndef SERIAL_DEVICE_H
#define SERIAL_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

void serial_open(void);

/* Inicialitza el modul i deixa la UART a punt per enviar/rebre caracters de 8bit a 9600bits^-1, amb 1 bit d’stop, sense paritat i en mode asíncron. */

void serial_close(void);

/* Deshabilita la UART per no rebre ni transmetre res. En cas que quedin caràcters al buffer de sortida, s’espera fins que acabin de sortir abans de deshabilitar la UART. */

uint8_t serial_get(void);

/* Retorna un byte llegit de la cua de recepció del port sèrie. Es bloqueja indefinidament fins que hi ha un caràcter disponible per a ser llegit. En cas que no es llegeixi 
prou sovint es poden perdre caràcters. */

void serial_put(uint8_t c);

/* Envia un byte pel port sèrie. En cas que la cua de transmissió estigui plena, es bloqueja fins que el byte es pugui afegir a la cua.*/

bool serial_can_read(void);

/* Retorna true sii hi ha un caràcter disponible per a ser llegit. Si aquesta funció retorna true es garanteix que una posterior crida a serial_get() no es bloquejarà. */

#endif
