/* Non-matching: best partial attempt (81.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieContext {
    u32 state;
    u8 *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

#pragma peephole on
#pragma opt_strength_reduction off
s32 fn_12_31CA4(MovieContext *self, u32 code, u32 *result) {
    struct { int value; } kind_ok;
    int kind;
    int ok;
    u8 *found;
    u8 *e;
    u32 i;
    u32 n = 13;
    u8 * e_2;
    u8 *p = self->movie;
    u32 c;
    u32 k;
    s32 v;

    switch (self->state) {
case -1: case 0: case 1: {

        ok = 0;
    
} break;
default: {

        ok = 1;
    
} break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok.value = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok.value = 1;
        }
        if (!(kind_ok.value != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    found = 0;
    if (ok == 0) {
        found = 0;
    } else {
        i = 0;
        c = code & 0xFF;
        do {
            e = p + 0x180;
            if (e[0x18] == c) {
                found = e;
                break;
            }
            e_2 = p + 0x1c0;
            if (e_2[0x18] == c) {
                found = e_2;
                break;
            }
            p += 0x80;
            i++;
        } while (i != n);
    }
    if (found == 0) {
        return 0;
    }

    k = code & 0xFF;
    if (k >= 0xc0 && k <= 0xdf) {
        k = 0xc0;
    } else if (k >= 0xe0 && k <= 0xef) {
        k = 0xe0;
    } else if (k == 0xbd || k == 0xbf) {
        k = 0xbd;
    } else {
        k = 0;
    }
    if (k != 0xc0) {
        return 0;
    }

    v = *(u32 *)(found + 0x1c);
    *result = (((((((v << 24) & 0xFF00))) | (((((v << 8) & 0xFF000000))) | ((((v >> 8) & 0xFF0000)))))) | ((((v >> 24) & 0xFF))));
    return 1;
}
#pragma opt_strength_reduction reset

#pragma peephole reset
