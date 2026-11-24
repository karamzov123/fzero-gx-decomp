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

double ldexp(double x, int exponent);

/* --- dol/modf.c --- */
/* --- dol/modf.c --- */
extern double j0(double);

static const double one = 1.0;

double modf(double x, double *iptr) {
    int i0;
    int i1;
    int j0;
    unsigned int i;
    i0 = *(int *)&x;
    i1 = *(1 + (int *)&x);
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            *(int *)iptr = i0 & 0x80000000;
            *(1 + (int *)iptr) = 0;
            return x;
        } else {
            i = 0x000fffff >> j0;
            if (((i0 & i) | i1) == 0) {
                *iptr = x;
                *(int *)&x &= 0x80000000;
                *(1 + (int *)&x) = 0;
                return x;
            } else {
                *(int *)iptr = i0 & ~i;
                *(1 + (int *)iptr) = 0;
                return x - *iptr;
            }
        }
    } else if (j0 > 51) {
        *iptr = x * one;
        *(int *)&x &= 0x80000000;
        *(1 + (int *)&x) = 0;
        return x;
    } else {
        i = (unsigned int)0xffffffff >> (j0 - 20);
        if ((i1 & i) == 0) {
            *iptr = x;
            *(int *)&x &= 0x80000000;
            *(1 + (int *)&x) = 0;
            return x;
        } else {
            *(int *)iptr = i0;
            *(1 + (int *)iptr) = i1 & ~i;
            return x - *iptr;
        }
    }
}
