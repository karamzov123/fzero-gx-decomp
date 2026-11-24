#include "types.h"


/* --- dol/fn_80087C44.c --- */
static const double one = 1.00000000000000000000e+00;

static const double pio4 = 7.85398163397448278999e-01;

static const double pio4lo = 3.06161699786838301793e-17;

/* fdlibm lbl_800955E0[]: the kernel_tan polynomial coefficients (13 doubles). */
extern const double lbl_800955E0[];

static inline double fabs(double x) {
    return __fabs(x);
}

double fn_80087C44(double x, double y, int iy);

/* --- dol/fn_80087E58.c --- */
/* --- dol/fn_80087E58.c --- */
typedef union {
    f64 value;
    struct {
        u32 hi;
        u32 lo;
    } words;
} DoubleBits;

f64 fn_80087E58(f64 a, f64 b);

/* --- dol/fn_80087E80.c --- */
extern const f64 lbl_801A78A8;
extern f64 __kernel_cos(f64, f64);
extern u32 __ieee754_rem_pio2(f64 *, f64);
extern f64 fn_80087BA4(u32, f64, f64);

f64 fn_80087E80(f64 value) {
    f64 parts[2];
    s32 bits;
    u32 quadrant;

    bits = *(s32 *)&value;
    bits &= 0x7fffffff;
    if (bits <= 0x3fe921fb) {
        return __kernel_cos(value, lbl_801A78A8);
    }
    if (bits >= 0x7ff00000) {
        return value - value;
    }

    quadrant = __ieee754_rem_pio2(parts, value) & 3;
    switch (quadrant) {
    case 0:
        return __kernel_cos(parts[0], parts[1]);
    case 1:
        return -fn_80087BA4(1, parts[0], parts[1]);
    case 2:
        return -__kernel_cos(parts[0], parts[1]);
    default:
        return fn_80087BA4(1, parts[0], parts[1]);
    }
}
