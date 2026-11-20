#include "types.h"


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

/* --- dol/fn_800883E8.c --- */
extern const f64 lbl_801A78F0;
extern f64 fn_80087BA4(s32, f64, f64);
extern s32 __ieee754_rem_pio2(f64 *);
extern f64 __kernel_cos(f64, f64);

f64 fn_800883E8(f64 angle) {
    union {
        f64 value;
        struct {
            s32 hi;
            u32 lo;
        } words;
    } bits;
    f64 values[2];
    s32 quadrant;

    bits.value = angle;
    if ((bits.words.hi & 0x7fffffff) <= 0x3fe921fb) {
        return fn_80087BA4(0, angle, lbl_801A78F0);
    }
    if ((bits.words.hi & 0x7fffffff) >= 0x7ff00000) {
        return angle - angle;
    }

    quadrant = __ieee754_rem_pio2(values);
    switch (quadrant & 3) {
    case 0:
        return fn_80087BA4(1, values[0], values[1]);
    case 1:
        return __kernel_cos(values[0], values[1]);
    case 2:
        return -fn_80087BA4(1, values[0], values[1]);
    default:
        return -__kernel_cos(values[0], values[1]);
    }
}
