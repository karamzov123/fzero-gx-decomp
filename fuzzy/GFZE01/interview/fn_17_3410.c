/* Non-matching: best partial attempt (12.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_17_3410_bss {
    u8 pad_0[0x58];
    u32 unk_58;
    u16 unk_5C;
    u8 pad_5E[0x112];
    u8 unk_170;
};

struct fn_17_3410_rodata {
    u8 pad_0[0x18];
    f32 unk_18;
    u8 pad_1C[0x44];
    f64 unk_60;
    f64 unk_68;
    u8 pad_70[0xA4];
    f32 unk_114;
    f32 unk_118;
    u8 pad_11C[0xC];
    u32 unk_128;
    u32 unk_12C;
    u32 unk_130;
    u32 unk_134;
    u32 unk_138;
    u32 unk_13C;
    f64 unk_140;
    f64 unk_148;
    f32 unk_150;
    u8 pad_154[4];
    f64 unk_158;
    f64 unk_160;
    f32 unk_168;
    f32 unk_16C;
    f32 unk_170;
    f32 unk_174;
    f32 unk_178;
    f32 unk_17C;
    f32 unk_180;
    f32 unk_184;
    f32 unk_188;
    f32 unk_18C;
};

extern f32 lbl_8006D188(u32);
extern f32 lbl_8006D21C(u32);
extern s32 fn_1_A5DC4(void);
extern struct fn_17_3410_bss lbl_17_bss_0;
extern struct fn_17_3410_rodata lbl_17_rodata_0;
extern u32 lbl_801A66A0;
extern void * memset(void *, int, u32);

f32 fn_17_3410(f32 arg0) {
    struct fn_17_3410_bss *bss;
    struct fn_17_3410_rodata *ro;
    u8 *p;
    u32 flags;
    u16 st;
    f32 x, y, z;
    f64 d;
    f32 f;
    s16 s;
    u32 a;
    f32 t;
    u32 b, c, d2, e;
    f32 g;
    u32 h, i;
    f32 j, k, m, n;

    bss = &lbl_17_bss_0;
    ro = &lbl_17_rodata_0;
    p = (u8 *)bss + 0x170;
    flags = bss->unk_58;
    if ((flags & 0x4000000) == 0) {
        memset(p, 0, 0x28);
        return arg0;
    }

    st = bss->unk_5C;
    bss->unk_170 = 1;
    if (st == 0 && (flags & 1) != 0) {
        t = lbl_8006D21C(0x71c);
        x = *(f32 *)(p + 8);
        y = *(f32 *)(p + 0xC);
        z = *(f32 *)(p + 0x14);
        *(f32 *)(p + 0x10) = ro->unk_150;
        *(f32 *)(p + 8) = (f32)((f64)x + (f64)ro->unk_140 * -(f64)x);
        *(f32 *)(p + 0xC) = (f32)((f64)y + (f64)ro->unk_148 * -(f64)y);
        *(f32 *)(p + 0x14) = (f32)((f64)z + (f64)ro->unk_158 * ((f64)ro->unk_160 - (f64)z));
        s = *(s16 *)(p + 0x1E);
        if (s != 0) {
            a = *(u32 *)(p + 4);
            a = 0x50E90000 - 25405;
            {
                s32 q = (s32)(((s64)a * (s64)(*(u32 *)(p + 4))) >> 32);
                u32 v = (u32)q;
                s32 w = (s32)(v - (s32)(((u32)((s32)q >> 9) + (s32)((u32)((s32)q >> 9) >> 31)) * 1620));
                t = (f32)ro->unk_16C * ((f32)(4503601774854144.0 - (f32)w));
                t = (f32)((f32)ro->unk_170) == 0 ? t : t;
            }
        }
        return t;
    }
    return t;
}
