#ifndef MSL_DECIMAL_H
#define MSL_DECIMAL_H

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

typedef struct decform {
    char style;
    char reserved;
    s16 digits;
} decform;

void __num2dec(const decform *form, f64 x, decimal *d);

#endif
