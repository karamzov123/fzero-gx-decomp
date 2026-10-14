/* Non-matching: best partial attempt (59.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

struct Sig_fn_8006C190_fn_8006C190_Arg0 {
    u8 unk_0; u8 pad_1[3]; u32 unk_4; u32 unk_8;
    s16 unk_C; u16 unk_E; u16 unk_10; u16 unk_12;
    s16 unk_14; u8 pad_16[0x12]; u32 unk_28;
    u32 unk_2C; u32 unk_30; u32 unk_34; u32 unk_38;
};

extern s32 fn_8006C190(struct Sig_fn_8006C190_fn_8006C190_Arg0 *, s32);
extern u32 OSGetTick(void);
extern vu32 __OSBusClock[];
extern u8 lbl_8019DF90[132];
extern void fn_800139E8(u32, u32, s32);

struct fn_8006C92C_Snd {
    u32 unk_0;
    u8 pad_4[0x43];
    s8 unk_47;
};

struct fn_8006C92C_Obj {
    u8 pad_0[0xF0];
    struct fn_8006C92C_Snd *unk_F0;
    struct Sig_fn_8006C190_fn_8006C190_Arg0 *unk_F4[0x440];
    u32 unk_11F4;
};

struct fn_8006C92C_Arg0 {
    struct fn_8006C92C_Obj *unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10[10];
    s32 unk_38[10];
    s32 unk_60;
    s32 unk_64;
    s32 unk_68[16];
    s32 unk_A8[16];
    s32 unk_E8;
    s32 unk_EC;
};

s32 fn_8006C92C(struct fn_8006C92C_Arg0 *arg0) {
    s32 dt;
    s32 pos;
    s32 neg;
    s32 j;
    s32 i;
    s32 n;
    s32 sumA;
    s32 sumB;
    s32 old8;
    s32 v;
    s32 f;
    s32 res;
    s32 a;
    s32 idx;
    s32 acc;
    u32 now;
    u32 old;
    u32 d;

    pos = 0;
    neg = 0;
    d = 1000;
    now = OSGetTick();
    old = arg0->unk_4;
    now = now / ((__OSBusClock[0] >> 2) / d);
    arg0->unk_4 = now;
    dt = (s32)now - (s32)old;
    old8 = (s32)arg0->unk_8;
    arg0->unk_8 = (u32)arg0->unk_0->unk_F0->unk_47;
    arg0->unk_C = arg0->unk_8 << 12;
    arg0->unk_E8--;
    if (arg0->unk_E8 < 0) {
        arg0->unk_E8 = 15;
    }
    arg0->unk_68[arg0->unk_E8] = old8 - (s32)arg0->unk_8;
    arg0->unk_A8[arg0->unk_E8] = dt;

    n = 0;
    sumA = 0;
    sumB = 0;
    j = arg0->unk_E8;
    while (n < 0x10 && (u32)sumA < 0x10) {
        sumB += arg0->unk_68[j];
        sumA += arg0->unk_A8[j];
        j++;
        if (j == 0x10) {
            j = 0;
        }
        n++;
    }
    if ((u32)sumA > 0x10) {
        idx = j - 1;
        if (idx < 0) {
            idx = 15;
        }
        a = arg0->unk_A8[idx];
        sumB -= ((sumA - 0x10) * arg0->unk_68[idx] + a / 2) / a;
    }
    arg0->unk_38[arg0->unk_60] = sumB;
    arg0->unk_60 = arg0->unk_60 + 1;
    if (arg0->unk_60 > 9) {
        arg0->unk_60 = 0;
    }

    acc = 0;
    for (i = 9; i >= 0; i--) {
        acc += arg0->unk_38[arg0->unk_60] * arg0->unk_10[i];
        arg0->unk_60 = arg0->unk_60 + 1;
        if (arg0->unk_60 > 9) {
            arg0->unk_60 = 0;
        }
    }
    arg0->unk_64 = acc;

    for (i = 0; i < 0x40; i++) {
        struct Sig_fn_8006C190_fn_8006C190_Arg0 *e = arg0->unk_0->unk_F4[i];
        if (e != NULL) {
            if (e->unk_28 & 0x80000000) {
                fn_8006C190(e, dt);
                if ((e->unk_28 & 0x80000000) && e->unk_30 == 0) {
                    v = e->unk_34;
                    if (v < -0x7f) {
                        v = -0x7f;
                    }
                    if (v > 0x7f) {
                        v = 0x7f;
                    }
                    f = e->unk_28 & 0x20000000;
                } else {
                    v = 0;
                    f = 0;
                }
                if (f != 0) {
                    pos += v;
                } else {
                    neg += v;
                }
            }
        }
    }

    if (pos > 0x80) {
        pos = 0x80;
    }
    if (pos < -0x80) {
        pos = -0x80;
    }
    if (pos < 0) {
        v = -lbl_8019DF90[-pos];
    } else {
        v = lbl_8019DF90[pos];
    }
    a = arg0->unk_0->unk_11F4;
    if (a < 0xFF) {
        v = (v * a + (v >= 0 ? 0x7f : -0x7f)) / 0xFF;
        neg = (neg * a + (neg >= 0 ? 0x7f : -0x7f)) / 0xFF;
    }
    res = v + neg;
    if (res > 0x80) {
        res = 0x80;
    }
    if (res < -0x80) {
        res = -0x80;
    }
    if (arg0->unk_EC != res) {
        arg0->unk_EC = res;
        if (res != 0) {
            fn_800139E8(arg0->unk_0->unk_F0->unk_0, 0x600, res);
        } else {
            fn_800139E8(arg0->unk_0->unk_F0->unk_0, 0x400, 0);
        }
    }
    return res;
}
