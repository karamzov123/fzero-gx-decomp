/* Non-matching: best partial attempt (92.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_34924_Inner {
    u32 unk_0;
    u8 pad_4[4];
    s16 unk_8;
};

struct fn_1_34924_C {
    u8 pad_0[8];
    u8 unk_8;
};

struct fn_1_34924_S {
    u8 pad_0[0x30];
    struct fn_1_34924_Inner in_30;
    u8 pad_3C[0x1504 - 0x3C];
    s8 unk_1504;
};

struct fn_1_34924_B {
    u8 pad_0[0x1F88];
    u32 unk_1F88;
    u8 pad_1F8C[0x20A4 - 0x1F8C];
    u32 unk_20A4;
    u8 pad_20A8[0x227C - 0x20A8];
    s32 unk_227C;
    s32 unk_2280;
    s32 unk_2284;
    u8 pad_2288[0x2F48 - 0x2288];
    s32 unk_2F48;
};

extern u8 lbl_1_bss_3C00;
extern s32 fn_1_EB200(void);
extern void fn_1_4310(u32);
extern void fn_1_F2EB8(void);
extern void fn_1_A4F18(s32);
extern u32 fn_1_4060(void);
extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void *fn_1_86254(s8);
extern void fn_1_15E540(void *, u32);

#pragma opt_propagation off
#pragma opt_common_subs on
void fn_1_34924(u16 *p) {
    struct fn_1_34924_B *b = (struct fn_1_34924_B *)((u8 *)&lbl_1_bss_3C00 + 0x20000);
    struct fn_1_34924_S *f = (struct fn_1_34924_S *)&lbl_1_bss_3C00;
    u32 t;
    s32 v;
    s8 i;

    if (fn_1_EB200() != 0) {
        return;
    }
    if (!(f->in_30.unk_0 & 0x800) && f->unk_1504 != -1) {
        return;
    }
    v = (u16)(*p - 1);
    *p = v;
    if (v != 0) {
        if (*p > 0x3c && *p < 0xf0) {
            fn_1_4310(0);
            t = f->in_30.unk_0;
            t |= 0x4000;
            f->in_30.unk_0 = t;
            if (t & 0x800000) {
                if (*p == 0xef) {
                    fn_1_F2EB8();
                    b->unk_2F48 = 1;
                }
            } else {
                b->unk_2F48 = 1;
            }
        }
        /* hardware tick counter read: keep the load opaque */
        fn_1_A4F18(*(volatile u16 *)p / 60);
    } else {
        fn_1_4060();
        b->unk_227C = -1;
        fn_1_435C(b->unk_1F88);
        if (b->unk_2280 != -1) {
            fn_1_426C(b->unk_2280);
            fn_1_105724();
        }
        b->unk_2280 = -1;
        fn_1_435C(b->unk_20A4);
        if (b->unk_2284 != -1) {
            fn_1_426C(b->unk_2284);
        }
        b->unk_2284 = -1;
        if (f->in_30.unk_0 & 0x10) {
            struct fn_1_34924_C *g = (struct fn_1_34924_C *)&f->in_30;
            for (i = 0; i < g->unk_8; i++) {
                void *t2 = fn_1_86254((s8)i);
                if (*(s8 *)((u8 *)t2 + 0x475) != -1) {
                    fn_1_15E540(t2, b->unk_1F88);
                }
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_propagation reset

