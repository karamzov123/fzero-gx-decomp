#include "types.h"


/* --- dol/__kernel_rem_pio2.c --- */
extern double ldexp(double, int);

extern double floor(double);

extern const int lbl_80095590[];

extern const double lbl_800955A0[];

static const double zero = 0.0;

static const double one = 1.0;

static const double two24 = 1.67772160000000000000e+07;

static const double twon24 = 5.96046447753906250000e-08;

int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2);

/* --- dol/fn_80087BA4.c --- */
extern f64 lbl_801A7838;
extern f64 lbl_801A7840;
extern f64 lbl_801A7848;
extern f64 lbl_801A7850;
extern f64 lbl_801A7858;
extern f64 lbl_801A7860;
extern f64 lbl_801A7868;

f64 fn_80087BA4(f64 x, f64 y, u32 mode) {
    union {
        f64 d;
        struct {
            u32 hi;
            u32 lo;
        } words;
    } value;
    f64 z;
    f64 x2;
    f64 x3;
    f64 t;
    f64 p;

    value.d = x;
    if ((s32)(value.words.hi & 0x7fffffff) < (s32)0x3e400000) {
        if ((s32)x == 0) {
            return x;
        }
    }

    z = value.d;
    x2 = z * z;
    x3 = x2 * z;
    p = x2 * ((x2 * ((lbl_801A7858 * x2) + lbl_801A7850)) + lbl_801A7848) + lbl_801A7840;
    p = x2 * p + lbl_801A7838;

    if ((s32)mode == 0) {
        p = x3 * (x2 * p + lbl_801A7860) + z;
        return p;
    } else {
        f64 t;
        t = x3 * p;
        return z - ((x2 * (lbl_801A7868 * y - t) - y) - lbl_801A7860 * x3);
    }
}
