/* Non-matching: best partial attempt (85.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_8006AA44(void *, void *, void *);
extern void fn_8006AC44(void *, void *, void *);

typedef struct {
    u32 lo;
    u32 hi;
} Pair;

void fn_8006AE90(void *a, u8 *b, u8 *c, u32 lab_unused0, u32 lab_unused1) {
    s8 v0;
    s8 v1;
    s32 v2;
    u8 v3;
    s32 d;
    s32 r;
    u32 lab_v;

    lab_v = b[3];
    v0 = (s8)lab_v;
    v1 = (s8)c[3];
    v2 = (s8)((0xd)[c]);
    v3 = c[0x17];

    if (v0 < v1) {
        c[3] = lab_v;
        v1 = (s8)lab_v;
    }
    if (v0 > v2) {
        v2 = (s8)lab_v;
        c[0xd] = lab_v;
    }

    d = v2 - v1 - (s8)v3 * 2;
    if (!d) {
        d = 1;
    }

    d = (v0 - ((s8)v3 + v1)) * 0xff / d;
    r = d;
    r -= 0x7f;
    if (r < -0x80) {
        r = -0x80;
    }
    if (r > 0x7f) {
        r = 0x7f;
    }
    ((u8 *)a)[3] = (u8)r;

    fn_8006AA44(a, b, c);
    fn_8006AC44(a, b, c);

    *(u16 *)a = *(u16 *)b;
    ((u8 *)a)[2] = b[2];
    *(Pair *)(c + 0x1e) = *(Pair *)b;
    *(u16 *)(c + 0x26) = *(u16 *)(b + 8);
    ((u8 *)a)[9] = 0;
}
