/* Non-matching: best partial attempt (51.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { u32 hi : 24; u32 lo : 8; } F24;

extern u32 lbl_801A6C80;
extern s32 fn_80063EF4(u8, u8);
extern const f64 lbl_801A7218;
extern const f64 lbl_801A7220;
extern const f64 lbl_801A7228;

void fn_8005C478(s32 idx) {
    u8 *base;
    u32 off;
    u32 o2;
    u8 *e;
    u8 *t;
    u8 *p;
    u8 *q;
    u32 w;
    s32 k;
    s32 a;
    s32 b;
    s32 v;

    base = (u8 *)lbl_801A6C80;
    off = idx * 0x118;
    o2 = off + 0x1414;
    e = base + off;
    k = e[0x140A];
    t = base + (k << 5);
    w = *(u32 *)(t + 0x5A4);
    if (w == 0) {
        return;
    }
    k = *(u8 *)w;
    k = -k | k;
    p = *(u8 **)(e + 0x1424);
    v = ((F24 *)(e + 0x1420))->hi;
    a = (s8)t[0x596] + ((v - 0x3C) & ~(k >> 31)) + (s8)p[0x0A];
    b = (s8)p[0x0B] + (s8)t[0x597];
    if (p[0x14] != 0) {
        b += *(s16 *)((u8 *)base + o2);
    } else {
        *(s16 *)((u8 *)base + o2) = 0;
    }
    q = *(u8 **)(e + 0x1428);
    v = fn_80063EF4(q[0x19], q[0x1A]);
    b += (v >> 6) & 0xFF;
    a += v >> 8;
    *(u32 *)((u8 *)base + off + 0x1480) = (u32)(u16)(s16)(1.5625 * b + 100.0 * a) << 16;
}
