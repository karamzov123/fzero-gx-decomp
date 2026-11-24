#include "types.h"


/* --- dol/floor.c --- */
extern double j0(double);

static const double huge = 1.0e300;

double floor(double x);

/* --- dol/frexp.c --- */
static const double two54 = 1.80143985094819840000e+16;

double frexp(double x, int *eptr) {
    int hx;
    int ix;
    int lx;
    hx = *(int *)&x;
    ix = hx & 0x7fffffff;
    lx = *(1 + (int *)&x);
    *eptr = 0;
    if (ix >= 0x7ff00000 || ((ix | lx) == 0))
        return x;
    if (ix < 0x00100000) {
        x *= two54;
        hx = *(int *)&x;
        ix = hx & 0x7fffffff;
        *eptr = -54;
    }
    *eptr += (ix >> 20) - 1022;
    hx = (hx & 0x800fffff) | 0x3fe00000; // fzgx-allow: A1 IEEE-754 sign and mantissa mask
    *(int *)&x = hx;
    return x;
}
