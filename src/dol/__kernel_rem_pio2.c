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

int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2) {
    int jz;
    int jx;
    int jv;
    int jp;
    int jk;
    int carry;
    int n;
    int iq[20];
    int i;
    int j;
    int k;
    int m;
    int q0;
    int ih;
    double z;
    double fw;
    double f[20];
    double fq[20];
    double q[20];
    jk = lbl_80095590[prec];
    jp = jk;
    jx = nx - 1;
    jv = (e0 - 3) / 24;
    if (jv < 0)
        jv = 0;
    q0 = e0 - 24 * (jv + 1);
    j = jv - jx;
    m = jx + jk;
    for (i = 0; i <= m; ++i, ++j)
        f[i] = j < 0 ? zero : (double)ipio2[j];
    for (i = 0; i <= jk; ++i) {
        fw = 0.0;
        for (j = 0; j <= jx; ++j)
            fw += x[j] * f[jx + i - j];
        q[i] = fw;
    }
    jz = jk;
    for (;;) {
        for (i = 0, j = jz, z = q[jz]; j > 0; ++i, --j) {
            fw = (double)(int)(twon24 * z);
            iq[i] = (int)(z - two24 * fw);
            z = q[j - 1] + fw;
        }
        z = ldexp(z, q0);
        z -= 8.0 * floor(z * 0.125);
        n = (int)z;
        z -= (double)n;
        ih = 0;
        if (q0 > 0) {
            i = iq[jz - 1] >> (24 - q0);
            n += i;
            iq[jz - 1] -= i << (24 - q0);
            ih = iq[jz - 1] >> (23 - q0);
        } else if (q0 == 0) {
            ih = iq[jz - 1] >> 23;
        } else if (z >= 0.5) {
            ih = 2;
        }
        if (ih > 0) {
            ++n;
            carry = 0;
            for (i = 0; i < jz; ++i) {
                j = iq[i];
                if (carry == 0) {
                    if (j != 0) {
                        carry = 1;
                        iq[i] = 0x1000000 - j;
                    }
                } else {
                    iq[i] = 0xFFFFFF - j;
                }
            }
            if (q0 > 0) {
                switch (q0) {
                case 1:
                    iq[jz - 1] &= 0x7FFFFF;
                    break;
                case 2:
                    iq[jz - 1] &= 0x3FFFFF;
                    break;
                }
            }
            if (ih == 2) {
                z = one - z;
                if (carry != 0)
                    z -= ldexp(one, q0);
            }
        }
        if (z == zero) {
            j = 0;
            for (i = jz - 1; i >= jk; --i)
                j |= iq[i];
            if (j == 0) {
                for (k = 1; iq[jk - k] == 0; ++k) {
                }
                for (i = jz + 1; i <= jz + k; ++i) {
                    f[jx + i] = (double)ipio2[jv + i];
                    fw = 0.0;
                    for (j = 0; j <= jx; ++j)
                        fw += x[j] * f[jx + i - j];
                    q[i] = fw;
                }
                jz += k;
                continue;
            }
        }
        break;
    }
    if (z == 0.0) {
        --jz;
        q0 -= 24;
        while (iq[jz] == 0) {
            --jz;
            q0 -= 24;
        }
    } else {
        z = ldexp(z, -q0);
        if (z >= two24) {
            fw = (double)(int)(twon24 * z);
            iq[jz] = (int)(z - two24 * fw);
            ++jz;
            q0 += 24;
            iq[jz] = (int)fw;
        } else {
            iq[jz] = (int)z;
        }
    }
    fw = ldexp(one, q0);
    for (i = jz; i >= 0; --i) {
        q[i] = fw * (double)iq[i];
        fw *= twon24;
    }
    for (i = jz; i >= 0; --i) {
        fw = 0.0;
        for (k = 0; k <= jp && k <= jz - i; ++k)
            fw += lbl_800955A0[k] * q[i + k];
        fq[jz - i] = fw;
    }
    switch (prec) {
    case 0:
        fw = 0.0;
        for (i = jz; i >= 0; --i)
            fw += fq[i];
        y[0] = ih == 0 ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = 0.0;
        for (i = jz; i >= 0; --i)
            fw += fq[i];
        y[0] = ih == 0 ? fw : -fw;
        fw = fq[0] - fw;
        for (i = 1; i <= jz; ++i)
            fw += fq[i];
        y[1] = ih == 0 ? fw : -fw;
        break;
    case 3:
        for (i = jz; i > 0; --i) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (i = jz; i > 1; --i) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        fw = 0.0;
        for (i = jz; i >= 2; --i)
            fw += fq[i];
        if (ih == 0) {
            y[0] = fq[0];
            y[1] = fq[1];
            y[2] = fw;
        } else {
            y[0] = -fq[0];
            y[1] = -fq[1];
            y[2] = -fw;
        }
        break;
    }
    return n & 7;
}

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
