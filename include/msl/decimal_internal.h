#ifndef MSL_DECIMAL_INTERNAL_H
#define MSL_DECIMAL_INTERNAL_H

#include "msl/decimal.h"

static inline void __dorounddecup(decimal *d, int digits) {
    u8 *b = d->sig.text;
    u8 *i = b + digits - 1;
    while (1) {
        if (*i < 9) {
            *i += 1;
            break;
        }
        if (i == b) {
            *i = 1;
            d->exp++;
            break;
        }
        *i-- = 0;
    }
}

#endif
