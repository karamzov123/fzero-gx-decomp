#include "types.h"

#define SIGDIGLEN 36

typedef struct decimal {
    char sign;
    char unk1;
    s16 exp;
    struct {
        u8 length;
        u8 text[SIGDIGLEN];
        u8 unk41;
    } sig;
} decimal;

/* MSL ansi_fp.c __timesdec: decimal significand multiplication with round-half-even */
void fn_8007E69C(decimal *result, const decimal *x, const decimal *y) {
    u32 accumulator = 0;
    u8 mantissa[SIGDIGLEN * 2];
    int i = x->sig.length + y->sig.length - 1;
    u8 *pDigit;
    u8 *text;
    u8 *ip = mantissa + i + 1;
    u8 *ep = ip;

    result->sign = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const u8 *jp;
        const u8 *kp;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        jp = x->sig.text + j;
        kp = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;

        if (l > t) {
            l = t;
        }

        for (; l > 0; l--, jp++, kp--) {
            accumulator += *jp * *kp;
        }

        *--ip = (u8)(accumulator % 10);
        accumulator /= 10;
    }

    result->exp = (s16)(x->exp + y->exp);

    if (accumulator > 0) {
        *--ip = (u8)accumulator;
        result->exp++;
    }

    for (i = 0; i < SIGDIGLEN && ip < ep; i++, ip++) {
        result->sig.text[i] = *ip;
    }
    result->sig.length = (u8)i;

    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            u8 *iq = ip + 1;

            for (; iq < ep; iq++) {
                if (*iq != 0) {
                    /* goto: MSL source shape; skips the round-half-even test into rounding */
                    goto round;
                }
            }

            if ((*(ip - 1) & 1) == 0) {
                return;
            }
        }

    round:
        text = result->sig.text;
        pDigit = text + result->sig.length - 1;

        while (1) {
            if (*pDigit < 9) {
                (*pDigit)++;
                break;
            } else if (pDigit == text) {
                *pDigit = 1;
                result->exp++;
                break;
            } else {
                *pDigit-- = 0;
            }
        }
    }
}
