#include <stdbool.h>
//#include <util/atomic.h>
#define ELEMENTS 25

typedef struct {
	uint8_t cua[ELEMENTS];
	uint8_t llegir;
	uint8_t escriure;
	uint8_t nombreelements;
	} queue_t;

/* Els objectes d'aquest tipus són cues de uint8_t. El nombre d'elements màxim de la cua és fix i afitat. */

void queue_empty(queue_t * const q);
/* Inicialitza la cua q a l'estat buit. */

bool queue_is_empty(const queue_t *const q);
/* Retorna true ssi q és buida. */

bool queue_is_full(const queue_t *const q);
/* Retorna true ssi q és plena. */

void queue_enqueue(queue_t *const q, uint8_t v);
/* Encua l’element v a la cua q. Si la cua és plena no encua res. */

void queue_dequeue(queue_t *const q);
/* Desencua l'element del davant de la cua q. Si la cua és buida no fa res. */

uint8_t queue_front(const queue_t *const q);
/* Retorna l'element del davant de la cua q. Si la cua és buida retorna un valor arbitrari. */


