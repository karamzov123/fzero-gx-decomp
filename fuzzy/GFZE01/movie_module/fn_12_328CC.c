/* Non-matching: best partial attempt (98.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
extern char lbl_12_rodata_10DC[];
#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
} MovieContext;

extern void * memset(void *, int, u32);
extern void * memcpy(void *, const void *, u32);
extern u8 * fn_80083970(u8 *, const u8 *);

static inline s32 fn_12_328CC_isdigit(s32 c) {
    s32 r;
    r = 0;
    if (c >= '0' && c <= '9') {
        r = 1;
    }
    return r;
}

#pragma peephole off
#pragma opt_dead_assignments off
s32 fn_12_328CC(MovieContext *self, u32 *res_x, u32 *res_y) {
    s32 n;
    s32 ok;
    u8 buf[0x21];
    u8 *src = (u8 *)self->movie + 0x60;
    s8 *p;
    s32 c;
    void * lab_t0;

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
        lab_t0 = buf;
        memset(lab_t0, 0, 0x21);
        memcpy(buf, src, 0x20);
        ok = 1;
    }

    if (ok == 0) {
        return 0;
    }

    p = (s8 *)fn_80083970(buf, (const u8 *)"Ver.");
    if (p == 0) {
        ok = 0;
    } else {
        p += 4;
        n = 0;
        for (;;) {
            c = *p;
            if ((('.') == (c)) || c == ' ' || c == 0) {
                break;
            }
            if (fn_12_328CC_isdigit(c) == 0) {
                break;
            }
            n = ((c) + (n * 10));
            n -= '0';
            p++;
        }
        *res_x = n;
        p++;
        n = 0;
        for (;;) {
            c = *p;
            if (c == '.' || c == ' ' || c == 0) {
                break;
            }
            if (fn_12_328CC_isdigit(c) == 0) {
                break;
            }
            n = ((c) + (n * 10));
            n -= '0';
            p++;
        }
        *res_y = n;
        ok = 1;
    }
    if (!(ok)) {
        return 0;
    }
    return 1;
}
#pragma opt_dead_assignments reset

#pragma peephole reset
