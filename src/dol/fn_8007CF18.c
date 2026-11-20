#include "types.h"

typedef struct decimal {
    char sign;
    char reserved;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 round;
    } sig;
} decimal;

extern char lbl_80094ED8[];
extern void fn_8007E69C(decimal *, const decimal *, const decimal *);

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

static inline void __dec_parse(decimal *d, char *s) {
    char c;
    char *q;
    int i = 0;

    while (i < 36 && *s)
        d->sig.text[i++] = *s++ - '0';
    d->sig.length = i;
    c = *s;
    if (c == 0)
        return;
    if (c < 5)
        return;
    /* the >5 path and the 5-with-nonzero-tail path share one round-up tail */
    if (c > 5)
        goto round; /* Keep the verified branch to round. */
    for (q = s + 1; *q; q++)
        /* any nonzero digit after the 5 forces a round up */
        if (*q != '0')
            goto round; /* Keep the verified branch to round. */
    if ((d->sig.text[i - 1] & 1) == 0)
        return;
round:
    __dorounddecup(d, d->sig.length);
}

static inline void __dec_str(decimal *d, int exp, char *s) {
    d->exp = exp;
    d->sign = 0;
    __dec_parse(d, s);
}

#pragma opt_dead_assignments off
void fn_8007CF18(decimal *d, s32 n) {
    decimal tmp;
    decimal save;

    switch (n) {
    case -64:
        __dec_str(d, -20, &lbl_80094ED8[37]);
        return;
    case -53:
        __dec_str(d, -16, &lbl_80094ED8[83]);
        return;
    case -32:
        __dec_str(d, -10, &lbl_80094ED8[122]);
        return;
    case -16:
        __dec_str(d, -5, &lbl_80094ED8[146]);
        return;
    case -8:
        __dec_str(d, -3, &lbl_80094ED8[159]);
        return;
    case -7:
        __dec_str(d, -3, &lbl_80094ED8[166]);
        return;
    case -6:
        __dec_str(d, -2, &lbl_80094ED8[172]);
        return;
    case -5:
        __dec_str(d, -2, &lbl_80094ED8[178]);
        return;
    case -4:
        __dec_str(d, -2, &lbl_80094ED8[183]);
        return;
    case -3:
        __dec_str(d, -1, &lbl_80094ED8[187]);
        return;
    case -2:
        __dec_str(d, -1, &lbl_80094ED8[191]);
        return;
    case -1:
        __dec_str(d, -1, &lbl_80094ED8[194]);
        return;
    case 0:
        __dec_str(d, 0, &lbl_80094ED8[196]);
        return;
    case 1:
        __dec_str(d, 0, &lbl_80094ED8[198]);
        return;
    case 2:
        __dec_str(d, 0, &lbl_80094ED8[200]);
        return;
    case 3:
        __dec_str(d, 0, &lbl_80094ED8[202]);
        return;
    case 4:
        __dec_str(d, 1, &lbl_80094ED8[204]);
        return;
    case 5:
        __dec_str(d, 1, &lbl_80094ED8[207]);
        return;
    case 6:
        __dec_str(d, 1, &lbl_80094ED8[210]);
        return;
    case 7:
        __dec_str(d, 2, &lbl_80094ED8[213]);
        return;
    case 8:
        __dec_str(d, 2, &lbl_80094ED8[217]);
        return;
    default:
        fn_8007CF18(&tmp, n / 2);
        fn_8007E69C(d, &tmp, &tmp);
        if (((1) & n)) {
            save = *d;
            if (n > 0) {
                tmp.exp = 0;
                tmp.sign = 0;
                __dec_parse(&tmp, &"179769313486231580793729011405303420"[198]);
            } else {
                char *p;
                tmp.sign = 0;
                p = &"179769313486231580793729011405303420"[194];
                tmp.exp = -1;
                __dec_parse(&tmp, p);
            }
            fn_8007E69C(d, &save, &tmp);
        }
        return;
    }
}
#pragma opt_dead_assignments reset

