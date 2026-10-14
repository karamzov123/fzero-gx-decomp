/* Non-matching: best partial attempt (39.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Arg0 {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
};
struct Pool {
    u8 pad_0[0x10];
    f32 unk_10;
    f32 unk_14;
    f64 unk_18;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f64 unk_48;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};
extern struct Pool lbl_1_rodata_CF40;
extern u32 lbl_801A66A0;
extern u32 lbl_801A63C0[];
extern u32 lbl_8006DCA4(void);
extern u32 lbl_8006E1B0(struct Arg0 *, void *);
extern s32 fn_1_54E34(struct Arg0 *, f32);
extern f32 fn_1_A71AC(void);
extern u32 lbl_8006D5F0(void *, f32);
extern s16 fn_1_58E3C(void *);
extern void *memset(void *, int, u32);

s16 fn_1_1507C4(struct Arg0 *arg0, void *arg1) {
    struct Pool *p = &lbl_1_rodata_CF40;
    u32 state;
    u32 a, b, c, d, e;
    u32 i;
    f32 xyz0, xyz1, xyz2;
    f32 ratio;
    f32 t;
    f32 f21, f22, f23, f24, f26, f27, f28, f29, f30;
    f64 f25;
    f32 f15, f16, f17, f18, f19, f20;
    f64 n0, n1, n2, n3, n4;
    struct { u32 words[58]; } out;

    lbl_8006DCA4();
    if (fn_1_54E34(arg0, p->unk_10) == 0)
        return 0;
    lbl_8006E1B0(arg0, &ratio);
    if (ratio > p->unk_20)
        return 0;
    ratio = p->unk_24 / (-ratio * fn_1_A71AC());
    if (ratio < p->unk_10) {
        if (lbl_801A66A0 % 3 != 0)
            return 0;
    } else if (ratio < p->unk_28 && (lbl_801A66A0 & 1) != 0) {
        return 0;
    }

    f21 = p->unk_2C;
    f22 = p->unk_30;
    f23 = p->unk_34;
    f24 = p->unk_38;
    f25 = p->unk_18;
    f26 = p->unk_14;
    f27 = p->unk_10;
    f28 = p->unk_3C;
    f29 = p->unk_40;
    f30 = p->unk_44;
    f15 = p->unk_50;
    f16 = p->unk_54;
    f17 = p->unk_58;
    f18 = p->unk_5C;
    f19 = p->unk_60;
    f20 = p->unk_64;
    memset(&out, 0, 0xE8);
    *(u32 *)((u8 *)&out + 8) |= 0x1000;
    *(u16 *)((u8 *)&out + 0xC) = 15;
    *(u16 *)((u8 *)&out + 0x1A) = 0xFFFF;
    i = 2;
    while (i != 0) {
        state = lbl_801A63C0[0];
        a = state * 0x676A4B6B + 0x33CB;
        b = a * 0x676A4B6B + 0x33CB;
        xyz0 = *(f32 *)arg0;
        xyz1 = *(f32 *)((u8 *)arg0 + 4);
        xyz2 = *(f32 *)((u8 *)arg0 + 8);
        lbl_801A63C0[0] = a;
        lbl_801A63C0[0] = b;
        t = (f32)((a >> 16) & 0x7FFF) / f26;
        t = f24 * t;
        t = f23 + t;
        t = f22 * t;
        *(s32 *)((u8 *)&out + 0x10) = (s32)(f21 * t);
        lbl_8006D5F0(arg1, f27 * (f28 + f29 * ((f32)((b >> 16) & 0x7FFF) / f26)));

        state = lbl_801A63C0[0];
        a = state * 0x676A4B6B + 0x33CB;
        b = a * 0x676A4B6B + 0x33CB;
        c = b * 0x676A4B6B + 0x33CB;
        d = c * 0x676A4B6B + 0x33CB;
        e = d * 0x676A4B6B + 0x33CB;
        lbl_801A63C0[0] = a;
        lbl_801A63C0[0] = b;
        lbl_801A63C0[0] = c;
        lbl_801A63C0[0] = d;
        lbl_801A63C0[0] = e;
        n0 = (f64)(f32)((a >> 16) & 0x7FFF) / f26;
        n1 = (f64)(f32)((b >> 16) & 0x7FFF) / f26;
        n2 = (f64)(f32)((c >> 16) & 0x7FFF) / f26;
        n3 = (f64)(f32)((d >> 16) & 0x7FFF) / f26;
        n4 = (f64)(f32)((e >> 16) & 0x7FFF) / f26;
        *(f32 *)((u8 *)&out + 0x5C) = xyz0 + (f32)(f30 * (n0 - 0.5));
        *(f32 *)((u8 *)&out + 0x60) = xyz1 + (f32)(f30 * (n1 - 0.5));
        *(f32 *)((u8 *)&out + 0x64) = xyz2 + (f32)(f30 * (n2 - 0.5));
        *(f32 *)((u8 *)&out + 0x50) = xyz0 - *(f32 *)((u8 *)&out + 0x5C);
        *(f32 *)((u8 *)&out + 0x54) = xyz1 - *(f32 *)((u8 *)&out + 0x60);
        *(f32 *)((u8 *)&out + 0x58) = xyz2 - *(f32 *)((u8 *)&out + 0x64);
        *(f32 *)((u8 *)&out + 0x30) = f19 * (f32)n4;
        *(f32 *)((u8 *)&out + 0x34) = f20 * (f32)n3;
        return fn_1_58E3C(&out) + (i--, 0);
    }
    return 0;
}
