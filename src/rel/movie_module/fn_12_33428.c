#include "types.h"

/* --- rel/movie_module/fn_12_33428.c --- */
void fn_12_33428(u32 *dst, u32 value, u32 count) {
    u32 *p = dst + count;
    u32 n = (count & 0xF) + 1;

    while (--n) {
        *--p = value;
    }

    n = (count >> 4) + 1;
    while (--n) {
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
        *--p = value;
    }
}
