#include "ether.h"

////////////////////////////////

static mchar_iter_t iterador;
static queue_t cua;
static timer_handler_t handler;

///////////////////////////////

static void automat(void);
static void so_mdot(void);
static void so_mdash(void);
static void so_gap(void);
static void silenci(void);

void ether_init(void){
  modulator_init();
  timer_init();
  queue_empty(&cua);
}

void ether_put(uint8_t c){
  while (queue_is_full(&cua));
  queue_enqueue(&cua,c);
  if (!queue_is_empty(&cua)){ //!
    if (!mchar_valid(iterador)){
      automat();
    }
  }
}


static void automat(void){
  uint8_t var;
  
  if (queue_is_empty(&cua)){}
  else{
    var=queue_front(&cua);
    iterador=mchar_iter(mtbl_a2m(var));
    queue_dequeue(&cua);
    if (mchar_next(&iterador)==MDot)
      so_mdot();
    else
      so_mdash();
  }

  /*
  iterador = mchar_iter(mtbl_a2m(queue_front(&cua)));
  queue_dequeue(&cua);
  if (mchar_next(&iterador)==MDash){
    modulator_set(true);
    thand_t=timer_after(TIMER_MS(DASH),silenci);
  }
  else {
    modulator_set(true);
    thand_t=timer_after(TIMER_MS(DOT),silenci);
  }*/
}

static void so_mdot(void){
  modulator_set(true);
  timer_after(TIMER_MS(DOT),silenci);
}

static void so_mdash(void){
  modulator_set(true);
  timer_after(TIMER_MS(DASH),silenci);
}

static void so_gap(void){
  if (mchar_next(&iterador)==MDot)
    so_mdot();
  else so_mdash();
}

static void silenci(){
  modulator_set(false);
  if (mchar_valid(iterador)){
    if (mchar_next(&iterador)==MDash){
      timer_after(TIMER_MS(GAP),so_mdash);
      
    }
  }
}
