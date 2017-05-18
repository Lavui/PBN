#include "ether.h"
#include "queue.h"
#include "mchar.h"
#include "modulator.h"
#include "timer.h"
#include "mtbl.h"

#define DOT 50
#define DASH 150
#define GAP 50
#define LETTERGAP 150

static queue_t tx;
static mchar_t m;
static mchar_iter_t miter;

static void automat(void);
static void dot(void);
static void dash(void);
static void silenci(void);

void ether_init(void) {
  modulator_init();
  timer_init();
  queue_init(&tx);
}

void ether_put(uint8_t c) {
  while(queue_is_full(&tx));
  if (queue_is_empty(&tx)) {          
      queue_enqueue(&tx, c);
      automat();
    }
  else
    queue_enqueue(&tx, c);
}

static void automat(void) {
  if (!queue_is_empty(&tx)) {
    m=mtbl_a2m(queue_front(&tx)); // traduim a morse
    miter=mchar_iter(m);
    if (mchar_next(&miter)==MDot) dot();
    else dash();
  }
}

static void silenci(void) {
  modulator_set(false);
  /* Si no hem arribat al final del caracter fem silenci de caracter
     i seguim enviant caracters    */
  if(mchar_valid(miter)) {
    if (mchar_next(&miter)==MDot)
      timer_after(TIMER_MS(GAP), dot);
    else timer_after(TIMER_MS(GAP), dash);
  }  
  /* En cas contrari silenci de lletra i tornem a automat */
  else {
    queue_dequeue(&tx);
    timer_after(TIMER_MS(LETTERGAP), automat);
  }
}

static void dot(void) {
  modulator_set(true);
  timer_after(TIMER_MS(DOT), silenci);
}

static void dash(void) {
  modulator_set(true);
  timer_after(TIMER_MS(DASH), silenci);
}


