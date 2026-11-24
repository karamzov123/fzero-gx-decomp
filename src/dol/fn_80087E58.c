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

f64 fn_80087E58(f64 a, f64 b) {
    DoubleBits other;
    DoubleBits result;

    result.value = a;
    other.value = b;
    result.words.hi = (result.words.hi & 0x7FFFFFFF) | (other.words.hi & 0x80000000);
    return result.value;
}
