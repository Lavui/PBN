#include <stdio.h>
#include <stdbool.h>
#include <util/atomic.h>
#include "queue.h"

/* No se si falten atomic_blocks en alguna altra funcio */

void queue_init(queue_t *const q){ // Inicialitzem una cua a 0
  q-> counter=0;
  q-> write_pointer=0;
  q-> read_pointer=0;
}

bool queue_is_empty(const queue_t *const q){ //retornem true si la llista esta buida, si te algun element retorna false
  return (q->counter==0);
}

bool queue_is_full(const queue_t *const q){ //si la llista esta full retornem true
  return (q->counter==MAX);
}

void queue_enqueue(queue_t *const q, uint8_t v){ //encua elements a la cua
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if(!(queue_is_full(q))){
      q->memory[q->write_pointer]=v;
      q->counter++;
      if(q->write_pointer==MAX-1)
	q->write_pointer=0;
      else
      	q->write_pointer++;
    }
  }
}
void queue_dequeue(queue_t *const q){ //desencua l'element de la cua
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if(!(queue_is_empty(q))){
      q->read_pointer++;
      q->counter--;
      if(q->read_pointer==MAX)
	q->read_pointer=0;
      
    }
  }
}

uint8_t queue_front(const queue_t *const q){ 
  return (q->memory)[q->read_pointer];
}




	

	
	
