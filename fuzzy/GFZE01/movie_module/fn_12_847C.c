/* Non-matching: best partial attempt (94.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn847C_Dest {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1c[4];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
} Fn847C_Dest;

extern void (*lbl_12_bss_4E40[2][4])(void *);

void fn_12_847C(void *obj, u32 arg1, s32 *arg2, u8 *arg3, s32 *arg4) {
    u32 fzgx_value;
    s32 h;
    s32 w;
    s32 x;
    s32 y;
    Fn847C_Dest *d;
    void (*f)(void *);
    void (*g)(void *);
    s32 sel;
    s32 a;
    s32 b;
    s32 v;

    sel = *(s32 *)((u8 *)obj + 0x19C);
    w = *(s16 *)(arg3 + 0xE);
    h = *(s16 *)(arg3 + 0xC);
    (*(void (**)(void *, u32))((u8 *)obj + 0x290))((void *)obj, *(u32 *)((u8 *)obj + 0x308));
    a = arg4[3];
    b = arg4[4];
    x = ((((b / 2) >> 1) * h) + ((arg2[0]) + (((a / 2) >> 1))));
    y = (((b >> 1) * w) + ((arg2[1]) + ((a >> 1))));
    f = lbl_12_bss_4E40[sel][((b / 2) & 1) * 2 + (((1) & ((a / 2))))];
    g = lbl_12_bss_4E40[sel][(b & 1) * 2 + (a & 1)];
    d = (Fn847C_Dest *)((u8 *)obj + 0xCC);
    d->unk_20 = h;
    d->unk_18 = arg1;
    v = *(s32 *)arg3 + x;
    d->unk_24 = v;
    d->unk_28 = h + (v + ((a / 2 & 1) & (sel != 0 ? -1 : 0)));
    f(d);
    d->unk_18 = arg1 + 0x40;
    v = *(s32 *)(arg3 + 4) + x;
    d->unk_24 = v;
    d->unk_28 = h + (v + ((a / 2 & 1) & (sel != 0 ? -1 : 0)));
    f(d);
    d->unk_20 = w;
    d->unk_18 = arg1 + 0x80;
    v = ((y) + (*(s32 *)(arg3 + 8)));
    d->unk_24 = v;
    d->unk_28 = w + (v + ((a & 1) & (sel != 0 ? -1 : 0)));
    g(d);
    d->unk_18 = arg1 + 0xC0;
    d->unk_24 = d->unk_24 + 8;
    d->unk_28 = d->unk_28 + 8;
    g(d);
    d->unk_18 = arg1 + 0x100;
    fzgx_value = d->unk_24 + (w - 1) * 8;
    d->unk_24 = fzgx_value;
    d->unk_28 = d->unk_28 + (w - 1) * 8;
    g(d);
    d->unk_18 = arg1 + 0x140;
    d->unk_24 = d->unk_24 + 8;
    d->unk_28 = d->unk_28 + 8;
    g(d);
}
