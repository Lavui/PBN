#include <stdbool.h>
#include <stdint.h>


typedef enum {Green, Yellow, Red} color_t;

typedef struct {
  pin_t green;
  pin_t yellow;
  pin_t red;} lamp_t;


void lamp_init(
	       lamp_t *const l,
	       volatile uint8_t *prtg, uint8_t pg,
	       volatile uint8_t *prty, uint8_t pg,
	       volatile uint8_t *prtr, uint8_t pr);

void lamp_on(lamp_t l, color_t c); //Encen el LED de color c de la lampada l
void lamp_off(lamp_t l, color_t c); //Apaga el LED de color c de la lampada l
void lamp_toggle(lamp_t l, color_t c); //Commuta l estat del color c en la lampada l
bool lamp_is_on(lamp_t l, color_t c); //Retorna true sii en la lampada l el color c esta ences
