#ifndef MSL_DECIMAL_INTERNAL_H
#define MSL_DECIMAL_INTERNAL_H

#include "types.h"

typedef struct decimal {
    char sign;
    char reserved;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 reserved;
    } sig;
} decimal;

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
