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

mchar_iter_t mchar_iter()





}