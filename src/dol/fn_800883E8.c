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

double modf(double x, double *iptr);

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
