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

double fn_80087C44(double x, double y, int iy) {
    double z;
    double r;
    double v;
    double w;
    double s;
    int ix;
    int hx;
    hx = *(int *)&x;
    ix = hx & 0x7fffffff;
    if (ix < 0x3e300000) {
        if ((int)x == 0) {
            if (((ix | *(1 + (int *)&x)) | (iy + 1)) == 0)
                return one / fabs(x);
            else
                return (iy == 1) ? x : -one / x;
        }
    }
    if (ix >= 0x3FE59428) {
        if (hx < 0) {
            x = -x;
            y = -y;
        }
        z = pio4 - x;
        w = pio4lo - y;
        x = z + w;
        y = 0.0;
    }
    z = x * x;
    w = z * z;
    r = lbl_800955E0[1] + w * (lbl_800955E0[3] + w * (lbl_800955E0[5] + w * (lbl_800955E0[7] + w * (lbl_800955E0[9] + w * lbl_800955E0[11]))));
    v = z * (lbl_800955E0[2] + w * (lbl_800955E0[4] + w * (lbl_800955E0[6] + w * (lbl_800955E0[8] + w * (lbl_800955E0[10] + w * lbl_800955E0[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += lbl_800955E0[0] * s;
    w = x + r;
    if (ix >= 0x3FE59428) {
        v = (double)iy;
        return (double)(1 - ((hx >> 30) & 2)) * (v - 2.0 * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1)
        return w;
    else {
        double a;
        double t;
        z = w;
        *(1 + (int *)&z) = 0;
        v = r - (z - x);
        t = a = -1.0 / w;
        *(1 + (int *)&t) = 0;
        s = 1.0 + t * z;
        return t + a * (s + t * v);
    }
}

/* --- dol/fn_80087E58.c --- */
/* --- dol/fn_80087E58.c --- */
typedef union {
    f64 value;
    struct {
        u32 hi;
        u32 lo;
    } words;
} DoubleBits;

f64 fn_80087E58(f64 a, f64 b) {
    DoubleBits other;
    DoubleBits result;

    result.value = a;
    other.value = b;
    result.words.hi = (result.words.hi & 0x7FFFFFFF) | (other.words.hi & 0x80000000);
    return result.value;
}

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
