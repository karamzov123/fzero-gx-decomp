/* Non-matching: best partial attempt (87.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_80164D60[];
extern u32 lbl_801A6B60;
extern u32 lbl_801A6B64;

struct Sig_fn_800209DC_fn_800209DC_Arg0 {
    u32 unk_0;
    u8 pad_4[0x8];
    u32 unk_C;
    u8 pad_10[0x8];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x4];
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0xFC];
    u32 unk_134;
    u16 unk_138;
    u16 unk_13A;
    u16 unk_13C;
    u16 unk_13E;
    u8 pad_140[0x6];
    u16 unk_146;
    u8 pad_148[0x26];
    u16 unk_16E;
    u16 unk_170;
    u16 unk_172;
    u8 pad_174[0x8];
    u16 unk_17C;
    u16 unk_17E;
    u16 unk_180;
    u16 unk_182;
    u16 unk_184;
    u16 unk_186;
    u16 unk_188;
    u8 pad_18A[0x9A];
};

struct A {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u8 pad_8[0x30];
    u16 unk_38;
    u16 unk_3A;
    u8 pad_3C[0x12];
    u16 unk_4E;
    u16 unk_50;
    u8 pad_52[0x9A];
};

struct B {
    u8 pad_0[0x40];
};

struct C {
    u8 pad_0[0x100];
};

extern void fn_800209DC(struct Sig_fn_800209DC_fn_800209DC_Arg0 *);
extern void DCFlushRange(void *, u32);

void fn_80022EA4(void) {
    u32 base;
    struct A *a;
    struct B *b;
    struct C *c;
    struct Sig_fn_800209DC_fn_800209DC_Arg0 *d;
    u32 *w;
    u32 i;

    lbl_801A6B60 = *(u32 *)0x800000F8 / 400; /* fzgx-allow: A1 A2 fixed system table word */
    lbl_801A6B64 = 0;
    base = (u32)lbl_80164D60;

    {
        u32 n;
        w = (u32 *)base;
        n = 0x1D8;
        do {
            w[0] = 0;
            w[1] = 0;
            w[2] = 0;
            w[3] = 0;
            w[4] = 0;
            w[5] = 0;
            w[6] = 0;
            w[7] = 0;
            w += 8;
        } while (--n);
        w = (u32 *)(base + 0x3B00);
        n = 0x80;
        do {
            w[0] = 0;
            w[1] = 0;
            w[2] = 0;
            w[3] = 0;
            w[4] = 0;
            w[5] = 0;
            w[6] = 0;
            w[7] = 0;
            w += 8;
        } while (--n);
        w = (u32 *)(base + 0x8B00);
        n = 0x448;
        do {
            w[0] = 0;
            w[1] = 0;
            w[2] = 0;
            w[3] = 0;
            w[4] = 0;
            w[5] = 0;
            w[6] = 0;
            w[7] = 0;
            w += 8;
        } while (--n);
    }

    a = (struct A *)base;
    b = (struct B *)(base + 0x3B00);
    c = (struct C *)(base + 0x4B00);
    d = (struct Sig_fn_800209DC_fn_800209DC_Arg0 *)(base + 0x8B00);

    for (i = 0; i < 0x40; i++) {
        u32 pa = (u32)&a[i];
        u32 pb = (u32)&b[i];
        u32 pc = (u32)&c[i];

        d[i].unk_18 = i;
        d[i].unk_30 = (u32)&d[i].unk_34;
        d[i].unk_134 = pb;
        d[i].unk_146 = 0;
        d[i].unk_16E = 0;
        d[i].unk_1C = 0xA4;
        d[i].unk_28 = 0;
        d[i].unk_24 = 0;
        d[i].unk_30 = (u32)&d[i].unk_34;
        d[i].unk_184 = 0;
        d[i].unk_182 = 0;
        d[i].unk_180 = 0;
        d[i].unk_17E = 0;
        d[i].unk_17C = 0;
        if (i == 0x3F) {
            a[i].unk_2 = 0;
            a[i].unk_0 = 0;
            d[i].unk_13A = 0;
            d[i].unk_138 = 0;
        } else {
            d[i].unk_138 = (u16)((pa + 0xEC) >> 16);
            d[i].unk_13A = (u16)(pa + 0xEC);
            a[i].unk_0 = (u16)((pa + 0xEC) >> 16);
            a[i].unk_2 = (u16)(pa + 0xEC);
        }
        d[i].unk_13C = (u16)(pa >> 16);
        d[i].unk_13E = (u16)pa;
        a[i].unk_4 = (u16)(pa >> 16);
        a[i].unk_6 = (u16)pa;
        d[i].unk_170 = (u16)(pb >> 16);
        d[i].unk_172 = (u16)pb;
        a[i].unk_38 = (u16)(pb >> 16);
        a[i].unk_3A = (u16)pb;
        d[i].unk_186 = (u16)(pc >> 16);
        d[i].unk_188 = (u16)pc;
        a[i].unk_4E = (u16)(pc >> 16);
        a[i].unk_50 = (u16)pc;
        d[i].unk_C = 1;
        fn_800209DC(&d[i]);
    }

    DCFlushRange((void *)base, 0x3B00);
}
