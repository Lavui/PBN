#ifndef SEMAPHORE_H
#define SEMAPHORE_H


typedef enum {
  SemaphoreOff=0,
  SemaphoreClear=5,
  SemaphoreApproach=6,
  SemaphoreStop=7,}semaphore_state_t;

void semaphore_init(void);

void semaphore_next(void);

void semaphore_set(semaphore_state_t s);


#endif
