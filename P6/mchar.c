#include "mchar.h"
#include <stdio.h>
#include <inttypes.h>

#include <stdio.h>

#define _BV(p) (1 << p)

mchar_t mchar_add(mchar_t m, msign_t s) {
  if (mchar_len(m) < 5) {//Si complim la longitud
    if (s == MDot) {//Si tenim punt
      m &= _BV(7 - mchar_len(m));
    } else {
      m++;
    }
    return m;
  }
}

mchar_iter_t mchar_iter(mchar_t m){
  mchar_iter_t index;

  index.m=m;
  index.mask=_BV(7);
  index.sentinel=_BV(7-mchar_len(m));
  // index.sentinel=mchar_len(m);
  return index;
}



bool mchar_valid(mchar_iter_t i){
  bool final=true;
  if(i.sentinel==i.mask){
    final=false;
  }
  return final;
}


msign_t mchar_next(mchar_iter_t *const i) {
  msign_t temp;
  if( i->sentinel > 0 ) {
    if( (i->m & i->mask) > 0){
      temp = MDash; //hi havia una ralla
    }
    else {
      temp = MDot;
    }
    // printf("\ni->m = %d\n i->mask = %d\n i->sentinel = %d\n",i->m,i->mask,i->sentinel);
    i->mask >>= 1;
    return temp; 
  }
}
