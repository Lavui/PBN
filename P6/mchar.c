#include <stdint.h>
#include "mchar.h"


mchar_t mchar_add(mchar_t m, msign_t s) {
    if (mchar_len(m) < 5) {//Si complim la longitud
        if (s == Mdot) {//Si tenim punt
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

    return i;
}

msign_t mchar_next(mchar_iter_t *const i) {
    msign_t s;
    if (mchar_valid(*i)) {
        if (i->m != i->mask) {//Si no ehm iterat tota aquesta historia
            s = MDot;
        } else {
            s = MDash;
        }
        return s;
    }
}

bool mchar_valid(mchar_iter_t i){
    int final=1;
    if(i.sentinel==i.mask){
        final=0;
    }
    return final;
}
