#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <inttypes.h>

#define MAX 100

typedef struct {
  
	uint8_t memory[MAX];
	uint8_t write_pointer;
	uint8_t read_pointer;
	uint8_t counter;
	
} queue_t;

//els objectes cua son del tipus uint8_t, el nombre maxim d'elements es fix i afitat

void queue_init(queue_t *const q);//crea cua buida
bool queue_is_empty(const queue_t *const q);//mira si cua esta buida
bool queue_is_full(const queue_t *const q);//mira si cua esta plena
void queue_enqueue(queue_t *const q, uint8_t v);//encua l'element v a la cua c, si la cua esta plena no es pot encuar res
void queue_dequeue(queue_t *const q);//desencua l'element davant de la cua q, si la cua es buida no fa res
uint8_t queue_front(const queue_t *const q);//retorna l'element del davant de la cua q, si la cua es buida retorna un valor arbitrari


#endif
