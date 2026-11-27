
#include "types.h"

extern double __ieee754_log(double);

extern int lbl_801A6DE0;

static const double two54 = 1.80143985094819840000e+16;

static const double ivln10 = 4.34294481903251816668e-01;

static const double log10_2hi = 3.01029995663611771306e-01;

static const double log10_2lo = 3.69423907715893078616e-13;

double lbl_801A6DF8 __attribute__((aligned(8)));

double __ieee754_log10(double x) {
    double y;
    double z;
    int i;
    int k;
    int hx;
    unsigned int lx;
    hx = *(int *)&x;
    lx = *(1 + (int *)&x);
    k = 0;
    if (hx < 0x00100000) {
        if (((hx & 0x7fffffff) | lx) == 0) {
            lbl_801A6DE0 = 33;
            return -two54 / lbl_801A6DF8;
        }
        if (hx < 0) {
            lbl_801A6DE0 = 33;
            return (x - x) / lbl_801A6DF8;
        }
        k -= 54;
        x *= two54;
        hx = *(int *)&x;
    }
    if (hx >= 0x7ff00000)
        return x + x;
    k += (hx >> 20) - 1023;
    i = ((unsigned int)k & 0x80000000) >> 31;
    hx = (hx & 0x000fffff) | ((0x3ff - i) << 20);
    y = (double)(k + i);
    *(int *)&x = hx;
    z = y * log10_2lo + ivln10 * __ieee754_log(x);
    return z + y * log10_2hi;
}
