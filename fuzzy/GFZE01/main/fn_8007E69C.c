/* Non-matching: best partial attempt (83.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/*types*/

extern int signgam;
enum fdversion { fdlibm_ieee = -1, fdlibm_svid, fdlibm_xopen, fdlibm_posix };
extern enum fdversion _fdlib_version;
struct exception {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
};
extern double acos(double);
extern double asin(double);
extern double atan(double);
extern double atan2(double, double);
extern double cos(double);
extern double sin(double);
extern double tan(double);
extern double cosh(double);
extern double sinh(double);
extern double tanh(double);
extern double exp(double);
extern double frexp(double, int *);
extern double ldexp(double, int);
extern double log(double);
extern double log10(double);
extern double modf(double, double *);
extern double pow(double, double);
extern double sqrt(double);
extern double ceil(double);
extern double fabs(double);
extern double floor(double);
extern double fmod(double, double);
extern double erf(double);
extern double erfc(double);
extern double gamma(double);
extern double hypot(double, double);
extern int isnan(double);
extern int finite(double);
extern double j0(double);
extern double j1(double);
extern double jn(int, double);
extern double lgamma(double);
extern double y0(double);
extern double y1(double);
extern double yn(int, double);
extern double acosh(double);
extern double asinh(double);
extern double atanh(double);
extern double cbrt(double);
extern double logb(double);
extern double nextafter(double, double);
extern double remainder(double, double);
extern double scalb(double, double);
extern int matherr(struct exception *);
extern double significand(double);
extern double copysign(double, double);
extern int ilogb(double);
extern double rint(double);
extern double scalbn(double, int);
extern double expm1(double);
extern double log1p(double);
extern double __ieee754_sqrt(double);
extern double __ieee754_acos(double);
extern double __ieee754_acosh(double);
extern double __ieee754_log(double);
extern double __ieee754_atanh(double);
extern double __ieee754_asin(double);
extern double __ieee754_atan2(double, double);
extern double __ieee754_exp(double);
extern double __ieee754_cosh(double);
extern double __ieee754_fmod(double, double);
extern double __ieee754_pow(double, double);
extern double __ieee754_lgamma_r(double, int *);
extern double __ieee754_gamma_r(double, int *);
extern double __ieee754_lgamma(double);
extern double __ieee754_gamma(double);
extern double __ieee754_log10(double);
extern double __ieee754_sinh(double);
extern double __ieee754_hypot(double, double);
extern double __ieee754_j0(double);
extern double __ieee754_j1(double);
extern double __ieee754_y0(double);
extern double __ieee754_y1(double);
extern double __ieee754_jn(int, double);
extern double __ieee754_yn(int, double);
extern double __ieee754_remainder(double, double);
extern int __ieee754_rem_pio2(double, double *);
extern double __ieee754_scalb(double, double);
extern double __kernel_standard(double, double, int);
extern double __kernel_sin(double, double, int);
extern double __kernel_cos(double, double);
extern double __kernel_tan(double, double, int);
extern int __kernel_rem_pio2(double *, double *, int, int, int, const int *);
extern int __double_max[];
extern int __float_huge[];
typedef struct decimal {
    char sign;
    char reserved;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 reserved;
    } sig;
} decimal;
typedef struct decform {
    char style;
    char reserved;
    s16 digits;
} decform;
void __num2dec(const decform *, f64, decimal *);
f64 __dec2num(const decimal *);
extern unsigned char __ctype_map[];
extern unsigned char __lower_map[];
extern unsigned char __upper_map[];
int tolower(int c);
extern void __num2dec_internal(decimal *d, f64 x);
extern void __minus_dec(decimal *z, const decimal *x, const decimal *y);
extern BOOL __equals_dec(const decimal *x, const decimal *y);
extern void __two_exp(decimal *result, s32 exp);

static inline void __dorounddecup(decimal *d, int digits) {
    u8 *b = d->sig.text;
    u8 *i = b + digits - 1;
    while (1) {
        if (*i < 9) {
            *i += 1;
            break;
        }
        if (i == b) {
            *i = 1;
            d->exp++;
            break;
        }
        *i-- = 0;
    }
}

static inline u8 fn_8007E69C_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_common_subs off
void fn_8007E69C(decimal *result, const decimal *x, const decimal *y) {
    int i;
    u8 mantissa[36 * 2];
    u32 lab_v;
    u8 *ip = mantissa + i + 1;
    u8 *ep = ip;
    u32 accumulator = 0;
    const u8 * kp_2;
    const u8 * kp;
    lab_v = x->sig.length;
    result->sign = 0;
    i = lab_v + y->sig.length - 1;
    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        s32 j = i - k - 1;
        int l;
        int t;
        const u8 *jp;
        if (j < 0) {
            j = 0;
            k = i - 1;
        }
        jp = x->sig.text + j;
        kp = y->sig.text;
        kp_2 = kp_2 + k;
        l = k + 1;
        t = lab_v - j;
        if (l > t)
            l = t;
        for (; l > 0; l--, jp++, kp_2--) {
            accumulator += *jp * *kp_2;
        }
        *--ip = (u8)(accumulator % 10);
        accumulator /= 10;
    }
    result->exp = (s16)(x->exp + y->exp);
    if (accumulator) {
        *--ip = (u8)(accumulator);
        result->exp++;
    }
    for (i = 0; i < 36 && ip < ep; i++, ip++) {
        result->sig.text[i] = *ip;
    }
    result->sig.length = (u8)(i);
    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            u8 *jp;
            for (jp = ip + 1; jp < ep; jp++) {
                if (*jp != 0)
                    goto round;
            }
            if ((fn_8007E69C_array_read(-1, ip) & 1) == 0)
                return;
        }
    round:
        __dorounddecup(result, result->sig.length);
    }
}
#pragma opt_common_subs reset

