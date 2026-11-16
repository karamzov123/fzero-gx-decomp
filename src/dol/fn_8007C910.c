
#include "types.h"

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

void fn_8007C910(decimal *z, const decimal *x, const decimal *y);

extern double exp(double);

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

