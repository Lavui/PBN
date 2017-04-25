#include "queue.h"
#include <util/atomic.h>


void queue_empty(queue_t * const q){
  q->llegir=0;
  q->escriure=0;
  q->nombreelements=0;
}

bool queue_is_empty(const queue_t *const q){
  return (q->nombreelements)==0;
}

bool queue_is_full(const queue_t *const q){
  return (q->nombreelements)==ELEMENTS;
}

void queue_enqueue(queue_t *const q, uint8_t v){
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
    if(!(queue_is_full(q))){
      q->cua[q->escriure] = v;
      q->nombreelements++;
      if(q->escriure == ELEMENTS-1)
	q->escriure=0;
      else
	q->escriure++;		
    }
  }
}

void queue_dequeue(queue_t *const q){
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
    if(!(queue_is_empty(q))){
      q->llegir++;
      q->nombreelements--;
      if(q->llegir == ELEMENTS)
	q->llegir = 0;
    }
  }
}

uint8_t queue_front(const queue_t *const q){
  return (q->cua[q->llegir]);
}


