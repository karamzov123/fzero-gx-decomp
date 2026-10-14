/* Non-matching: best partial attempt (74.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_fn_8007E69C_decimal {
    char sign;
    char reserved;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 reserved;
    } sig;
} Sig_fn_8007E69C_decimal;

void fn_8007E69C(Sig_fn_8007E69C_decimal *arg0, const Sig_fn_8007E69C_decimal *arg1, const Sig_fn_8007E69C_decimal *arg2) {
    struct {
        u32 a[21];
    } tmp;
    u8 len1;
    u8 len2;
    u32 acc;
    u32 qd;
    s32 k;
    u8 *pa;
    u8 *pb;
    u8 *cur;
    u8 *end;
    s32 hi;
    s32 lo;
    s32 n;
    s32 j;
    u8 *q;
    s32 len;
    u8 *base;
    u8 *p;

    len1 = arg1->sig.length;
    len2 = arg2->sig.length;
    acc = 0;
    k = (s32)len1 + (s32)len2 - 1;
    end = (u8 *)&tmp + k + 1;
    arg0->sign = 0;
    cur = end;
    for (; k > 0; k--) {
        hi = (s32)len2 - 1;
        lo = k - hi - 1;
        if (lo < 0) {
            lo = 0;
            hi = k - 1;
        }
        n = hi + 1;
        if (n > (s32)len1 - lo) {
            n = (s32)len1 - lo;
        }
        pa = arg1->sig.text + lo;
        pb = arg2->sig.text + hi;
        while (n > 0) {
            acc += *pa++ * *pb--;
            n--;
        }
        qd = acc / 10;
        *--cur = (u8)(acc - qd * 10);
        acc = qd;
    }

    arg0->exp = (s16)(arg1->exp + arg2->exp);
    if (acc != 0) {
        *--cur = (u8)acc;
        arg0->exp = (s16)(arg0->exp + 1);
    }

    for (j = 0; j < 36 && cur < end; j++) {
        arg0->sig.text[j] = *cur++;
    }
    arg0->sig.length = (u8)j;
    if (cur < end) {
        if (*cur >= 5) {
            if (*cur == 5) {
                for (q = cur + 1; q < end; q++) {
                    if (*q != 0) {
                        goto roundup;
                    }
                }
                if ((cur[-1] & 1) == 0) {
                    return;
                }
            }
roundup:
            len = arg0->sig.length;
            base = arg0->sig.text;
            p = base + len - 1;
            for (;;) {
                if (*p < 9) {
                    *p = (u8)(*p + 1);
                    break;
                }
                if (p == base) {
                    *p = 1;
                    arg0->exp = (s16)(arg0->exp + 1);
                    break;
                }
                *p = 0;
                p--;
            }
        }
    }
}
