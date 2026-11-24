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
