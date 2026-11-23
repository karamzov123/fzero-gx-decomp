#include "msl/decimal_internal.h"


/* --- dol/__num2dec.c --- */
typedef struct decform {
    char style;
    char reserved;
    s16 digits;
} decform;

extern double exp(double);

void __num2dec_internal(decimal *d, f64 x);

static inline int __must_round(const decimal *d, int digits) {
    u8 const *i = d->sig.text + digits;
    if (*i > 5) {
        return 1;
    }
    if (*i < 5) {
        return -1;
    }
    {
        u8 const *e = d->sig.text + d->sig.length;
        for (i++; i < e; i++) {
            if (*i != 0) {
                return 1;
            }
        }
    }
    if (d->sig.text[digits - 1] & 1) {
        return 1;
    }
    return -1;
}

static inline void __rounddec(decimal *d, int digits) {
    if (digits > 0 && digits < d->sig.length) {
        int round_direction = __must_round(d, digits);
        d->sig.length = digits;
        if (round_direction >= 0) {
            __dorounddecup(d, digits);
        }
    }
}

void __num2dec(const decform *form, f64 x, decimal *d) {
    s16 digits = form->digits;
    int i;
    __num2dec_internal(d, x);
    if (d->sig.text[0] > 9) {
        return;
    }
    if (digits > 36) {
        digits = 36;
    }
    __rounddec(d, digits);
    while (d->sig.length < digits) {
        d->sig.text[d->sig.length++] = 0;
    }
    d->exp -= d->sig.length - 1;
    for (i = 0; i < d->sig.length; i++) {
        d->sig.text[i] += '0';
    }
}

/* --- dol/__num2dec_internal.c --- */
extern double frexp(double, int *);

extern double ldexp(double, int);

extern double modf(double, double *);

static inline int __fpclassifyf(f32 x) {
    switch ((*(s32 *)&x) & 0x7F800000) {
    case 0x7F800000: {
        if ((*(s32 *)&x) & 0x007FFFFF)
            return 1;
        return 2;
    }
    case 0: {
        if ((*(s32 *)&x) & 0x007FFFFF)
            return 5;
        return 3;
    }
    }
    return 4;
}

static inline int __fpclassifyd(f64 x) {
    switch (*(int *)&x & 0x7FF00000) {
    case 0x7FF00000: {
        if ((*(int *)&x & 0x000FFFFF) || (*(1 + (int *)&x) & 0xFFFFFFFF))
            return 1;
        return 2;
    }
    case 0: {
        if ((*(int *)&x & 0x000FFFFF) || (*(1 + (int *)&x) & 0xFFFFFFFF))
            return 5;
        return 3;
    }
    }
    return 4;
}

void fn_8007CF18(decimal *result, s32 exp);

void fn_8007E69C(decimal *result, const decimal *x, const decimal *y);

static inline int __count_trailing_zerol(u32 x) {
    int result = 0;
    int bits_not_checked = sizeof(u32) * 8;
    int n = bits_not_checked / 2;
    int mask_size = n;
    u32 mask = (~0UL) >> (bits_not_checked - n);
    while (bits_not_checked) {
        if (!(x & mask)) {
            result += mask_size;
            x >>= mask_size;
            bits_not_checked -= mask_size;
        } else if (mask == 1) {
            break;
        }
        if (n > 1) {
            n /= 2;
        }
        if (mask > 1) {
            mask >>= n;
            mask_size -= n;
        }
    }
    return result;
}

static inline int __count_trailing_zero(f64 x) {
    u32 *l = (u32 *)&x;
    if (l[1] != 0) {
        return __count_trailing_zerol(l[1]);
    }
    return (int)(sizeof(u32) * 8 + __count_trailing_zerol(l[0] | 0x00100000));
}

static inline void __ull2dec(decimal *result, u64 val) {
    result->sign = 0;
    if (val == 0) {
        result->exp = 0;
        result->sig.length = 1;
        result->sig.text[0] = 0;
        return;
    }
    result->sig.length = 0;
    for (; val != 0; val /= 10) {
        result->sig.text[result->sig.length++] = (u8)(val % 10);
    }
    {
        u8 *i = result->sig.text;
        u8 *j = result->sig.text + result->sig.length;
        for (; i < --j; ++i) {
            u8 t = *i;
            *i = *j;
            *j = t;
        }
    }
    result->exp = result->sig.length - 1;
}

void __num2dec_internal(decimal *d, f64 x) {
    s8 sign = (s8)(((int)(*(int *)&x & 0x80000000)) != 0);
    if (x == 0) {
        d->sign = sign;
        d->exp = 0;
        d->sig.length = 1;
        d->sig.text[0] = 0;
        return;
    }
    if (!(((sizeof(x) == sizeof(f32)) ? __fpclassifyf((f32)(x)) : __fpclassifyd((f64)(x))) > 2)) {
        d->sign = sign;
        d->exp = 0;
        d->sig.length = 1;
        d->sig.text[0] =
            ((sizeof(x) == sizeof(f32)) ? __fpclassifyf((f32)(x)) : __fpclassifyd((f64)(x))) == 1
                ? 'N'
                : 'I';
        return;
    }
    if (sign != 0) {
        x = -x;
    }
    {
        int exp;
        f64 frac = frexp(x, &exp);
        s32 num_bits_extract = 53 - __count_trailing_zero(frac);
        f64 integer;
        decimal int_d, pow2_d;
        fn_8007CF18(&pow2_d, exp - num_bits_extract);
        modf(ldexp(frac, num_bits_extract), &integer);
        __ull2dec(&int_d, (u64)integer);
        fn_8007E69C(d, &int_d, &pow2_d);
        d->sign = sign;
    }
}

/* --- dol/fn_8007C910.c --- */
/* --- dol/fn_8007C910.c --- */

void fn_8007C910(decimal *z, const decimal *x, const decimal *y);


extern double jn(int, double);

void fn_8007C910(decimal *z, const decimal *x, const decimal *y) {
    int zlen, dexp;
    u8 *ib, *i, *ie;
    u8 const *jb, *j, *jn;
    {
        u32 a, b;
        const u32 *src = (const u32 *)x;
        u32 *dst = (u32 *)z;
        a = src[0];
        b = src[1];
        dst[0] = a;
        a = src[2];
        dst[1] = b;
        b = src[3];
        dst[2] = a;
        a = src[4];
        dst[3] = b;
        b = src[5];
        dst[4] = a;
        a = src[6];
        dst[5] = b;
        b = src[7];
        dst[6] = a;
        a = src[8];
        dst[7] = b;
        b = src[9];
        dst[8] = a;
        {
            u16 h = ((const u16 *)x)[20];
            dst[9] = b;
            ((u16 *)z)[20] = h;
        }
    }
    if ((*((y->sig.text) + (0))) == 0)
        return;
    zlen = z->sig.length;
    if (zlen < y->sig.length)
        zlen = y->sig.length;
    dexp = z->exp - y->exp;
    zlen += dexp;
    if (zlen > 36)
        zlen = 36;
    while (z->sig.length < zlen) {
        (*((z->sig.text) + (z->sig.length++))) = 0;
    }
    ib = z->sig.text;
    i = ib + zlen;
    if (y->sig.length + dexp < zlen) {
        i = ib + (y->sig.length + dexp);
    }
    jb = y->sig.text;
    j = jb + (i - ib - dexp);
    jn = j;
    while (i > ib && j > jb) {
        j--;
        i--;
        if (*i < *j) {
            u8 *k = i - 1;
            while (*k == 0)
                k--;
            while (k != i) {
                --*k;
                *++k += 10;
            }
        }
        *i -= *j;
    }
    if (jn - jb < y->sig.length) {
        BOOL round_down = 0;
        if (*jn < 5)
            round_down = 1;
        else if (*jn == 5) {
            u8 const *ibPtr = y->sig.text + y->sig.length;
            ibPtr = y->sig.text + y->sig.length;
            for (j = jn + 1; j < ibPtr; j++) {
                if (*j != 0)
                    goto round_done; /* 5 + trailing zeros: not a round-up case */
            }
            i = ib + (jn - jb) + dexp - 1;
            if (*i & 1)
                round_down = 1;
        }
        if (round_down) {
            if (*i < 1) {
                u8 *k = i - 1;
                while (*k == 0)
                    k--;
                while (k != i) {
                    --*k;
                    *++k += 10;
                }
            }
            *i -= 1;
        }
round_done: ;
    }
    for (i = ib; *i == 0; ++i) {
    }
    if (i > ib) {
        u8 dl = (u8)(i - ib);
        z->exp -= dl;
        ie = ib + z->sig.length;
        for (; i < ie; ++i, ++ib)
            *ib = *i;
        z->sig.length -= dl;
    }
    ib = z->sig.text;
    for (i = ib + z->sig.length; i > ib;) {
        i--;
        if (*i != 0)
            break;
    }
    z->sig.length = (u8)(i - ib + 1);
}

/* --- dol/__equals_dec.c --- */
BOOL __equals_dec(const decimal *x, const decimal *y) {
    if (x->sig.text[0] == 0) {
        if (y->sig.text[0] == 0)
            return 1;
        return 0;
    }
    if (y->sig.text[0] == 0) {
        if (x->sig.text[0] == 0)
            return 1;
        return 0;
    }
    if (x->exp == y->exp) {
        int i;
        int l = x->sig.length;
        if (l > y->sig.length) {
            l = y->sig.length;
        }
        for (i = 0; i < l; i++) {
            if (x->sig.text[i] != y->sig.text[i]) {
                return 0;
            }
        }
        if (l == x->sig.length) {
            for (; i < y->sig.length; ++i) {
                if (y->sig.text[i] != 0) {
                    return 0;
                }
            }
        } else {
            for (; i < x->sig.length; ++i) {
                if (x->sig.text[i] != 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}
