#ifndef SERIAL_DEVICE_H
#define SERIAL_DEVICE_H

#include <stdint.h>
#include <stdbool.h>

void serial_open(void);
void serial_close(void);
uint8_t serial_get(void);
void serial_put(uint8_t c);
bool serial_can_read(void);

#endif
