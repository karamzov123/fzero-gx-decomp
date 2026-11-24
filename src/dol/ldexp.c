#include "types.h"


/* --- dol/ldexp.c --- */
enum { FP_NAN = 1, FP_INFINITE = 2, FP_ZERO = 3, FP_NORMAL = 4, FP_SUBNORMAL = 5 };

extern double fn_80087E58(double, double);

static inline int classify_double(double value) {
    switch (*(int *)&value & 0x7ff00000) {
    case 0x7ff00000:
        if ((*(int *)&value & 0x000fffff) || *(1 + (int *)&value))
            return FP_NAN;
        return FP_INFINITE;
    case 0:
        if ((*(int *)&value & 0x000fffff) || *(1 + (int *)&value))
            return FP_SUBNORMAL;
        return FP_ZERO;
    }
    return FP_NORMAL;
}

static const double two54 = 1.80143985094819840000e+16;

static const double twom54 = 5.55111512312578270212e-17;

static const double big = 1.0e+300;

static const double tiny = 1.0e-300;

double ldexp(double x, int exponent) {
    long k;
    long hx;
    long lx;
    if (!(classify_double(x) > FP_INFINITE) || x == 0.0)
        return x;
    hx = *(int *)&x;
    lx = *(1 + (int *)&x);
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54;
        hx = *(int *)&x;
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (exponent < -50000)
            return tiny * x;
    }
    if (k == 0x7ff)
        return x + x;
    k += exponent;
    if (k > 0x7fe)
        return big * fn_80087E58(big, x);
    if (k > 0) {
        *(int *)&x = (hx & 0x800fffff) | (k << 20); // fzgx-allow: A1 IEEE-754 sign and mantissa mask
        return x;
    }
    if (k <= -54) {
        if (exponent > 50000)
            return big * fn_80087E58(big, x);
        return tiny * fn_80087E58(tiny, x);
    }
    k += 54;
    *(int *)&x = (hx & 0x800fffff) | (k << 20); // fzgx-allow: A1 IEEE-754 sign and mantissa mask
    return x * twom54;
}
