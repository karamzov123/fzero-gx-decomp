/* Non-matching: best partial attempt (44.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_80046C28_fn_80046C28_Arg1 { u32 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Arg2 { u16 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Arg3 { u8 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Arg4 { s8 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Arg5 { s8 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Arg6 { u8 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Arg7 { u32 unk_0; };
struct Sig_fn_80046C28_fn_80046C28_Data {
    u8 b0; u8 b1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    u8 b8; u8 b9; u8 b10; u8 b11; u8 b12; u8 b13; u8 b14; u8 b15;
};
extern u8 lbl_800900A0[];
extern u32 lbl_8017A288[5];
extern s32 fn_80046C28(struct Sig_fn_80046C28_fn_80046C28_Data *, u32, struct Sig_fn_80046C28_fn_80046C28_Arg2 *, struct Sig_fn_80046C28_fn_80046C28_Arg3 *, struct Sig_fn_80046C28_fn_80046C28_Arg4 *, struct Sig_fn_80046C28_fn_80046C28_Arg5 *, struct Sig_fn_80046C28_fn_80046C28_Arg6 *, struct Sig_fn_80046C28_fn_80046C28_Arg7 *, struct Sig_fn_80046C28_fn_80046C28_Arg1 *, struct Sig_fn_80046C28_fn_80046C28_Arg1 *);
extern void fn_80047464(u32, u32);
struct B90A { u8 v; };
extern s32 fn_80046B90(u32, u32, struct B90A *, struct B90A *);
extern int sprintf(char *, const char *, ...);
extern void fn_8004E2CC(u32, u32, u32, u32);
extern s32 fn_80046BE0(u32, u32, u16 *);
extern s32 fn_80046AC0(u32, s32, u16 *, u16 *);
extern void fn_8004E324(u32, u32, u32);
extern void fn_8004E300(u32, s16 *, s16 *);
extern int ADX_DecodeInfoExLoop(signed char *, int, int *, short *, short *, int *, int *, int *, int *);
extern int fn_8004683C(u8 *, int, int *, u8 *, s16 *, s16 *);

struct fn_800456A0_Arg0 {
    u8 pad_0[2]; u16 unk_2;
    u8 pad_4[4]; u32 unk_8;
    s8 unk_c; s8 unk_d; s8 unk_e; s8 unk_f;
    s32 unk_10; s16 unk_14; u16 unk_16; u32 unk_18;
    u16 unk_1c; u16 unk_1e; u32 unk_20; u16 unk_24; u16 unk_26;
    u32 unk_28; u32 unk_2c; u32 unk_30; u32 unk_34;
    u8 pad_38[4]; u32 unk_3c; u32 unk_40; u32 unk_44;
    u8 pad_48[8]; s32 unk_50; s32 unk_54; s32 unk_58; s32 unk_5c; s32 unk_60; s32 unk_64;
    u8 pad_68[0x20]; u32 unk_88; u32 unk_8c; u8 pad_90[8]; u16 unk_98; u8 pad_9a[2];
    s16 unk_9c; s16 unk_9e; s16 unk_a0;
    u8 pad_a2[0xe]; u32 unk_b0; u8 pad_b4[8]; u32 unk_bc;
    u32 unk_c0; u8 pad_c4[0xc]; u16 unk_d0; u16 unk_d2;
};

s32 fn_800456A0(struct fn_800456A0_Arg0 *a, u32 arg1, u32 arg2) {
    u8 *base = (u8 *)&lbl_800900A0;
    u32 *state = lbl_8017A288;
    s16 result;
    s16 z;
    char text[8];
    u8 ch, mode;
    u8 tmp;
    u16 x, y;
    int i;
    a->unk_2 = 1;
    if (fn_80046C28((struct Sig_fn_80046C28_fn_80046C28_Data *)a, arg2, (struct Sig_fn_80046C28_fn_80046C28_Arg2 *)&result,
          (struct Sig_fn_80046C28_fn_80046C28_Arg3 *)&a->unk_c,
          (struct Sig_fn_80046C28_fn_80046C28_Arg4 *)&a->unk_d,
          (struct Sig_fn_80046C28_fn_80046C28_Arg5 *)&a->unk_f,
          (struct Sig_fn_80046C28_fn_80046C28_Arg6 *)&a->unk_e,
          (struct Sig_fn_80046C28_fn_80046C28_Arg7 *)&a->unk_14,
          (struct Sig_fn_80046C28_fn_80046C28_Arg1 *)&a->unk_18,
          (struct Sig_fn_80046C28_fn_80046C28_Arg1 *)&a->unk_10) < 0) return 0;
    if (a->unk_c > 4) {
        if (a->unk_b0 == 0) {
            fn_80047464((u32)(u32)(base + 0x838), (u32)(base + 0x858));
            return -1;
        }
        a->unk_d = 8;
        a->unk_f = a->unk_e * 0xc0;
        a->unk_10 = 0x60;
        a->unk_98 = 10;
        a->unk_1c = 0; a->unk_24 = 0; a->unk_26 = 0;
        a->unk_20 = 0; a->unk_28 = 0; a->unk_2c = 0;
        a->unk_30 = 0; a->unk_34 = 0; a->unk_88 = 0;
    } else {
        if (fn_80046B90(arg1, arg2, (struct B90A *)&ch, (struct B90A *)&mode) < 0) return 0;
        if (ch < 4) {
            x = y = 0;
            result = 0;
        } else if (mode >= 16) {
            s8 *nums = (s8 *)text;
            s16 *tab = (s16 *)(lbl_800900A0 + 0x30);
            s16 *mix = (s16 *)(lbl_800900A0 + 0x130);
            s32 v0, v1, v2;
            sprintf(text, (char *)(lbl_800900A0 + 0x830));
            if (lbl_8017A288[0] == 0) lbl_8017A288[0] = 1;
            v0 = tab[0x100] * mix[nums[0]];
            v0 = tab[v0 / 65536] * mix[nums[1]];
            v0 = tab[v0 / 65536] * mix[nums[2]];
            v0 = tab[v0 / 65536] * mix[nums[3]];
            v0 = tab[v0 / 65536] * mix[nums[4]];
            v0 = tab[v0 / 65536] * mix[nums[5]];
            v0 = tab[v0 / 65536] * mix[nums[6]];
            v0 = tab[v0 / 65536] * mix[nums[7]];
            v1 = tab[0x200] * mix[nums[0]];
            v1 = tab[v1 / 65536] * mix[nums[1]];
            v1 = tab[v1 / 65536] * mix[nums[2]];
            v1 = tab[v1 / 65536] * mix[nums[3]];
            v1 = tab[v1 / 65536] * mix[nums[4]];
            v1 = tab[v1 / 65536] * mix[nums[5]];
            v1 = tab[v1 / 65536] * mix[nums[6]];
            v1 = tab[v1 / 65536] * mix[nums[7]];
            v2 = tab[0x300] * mix[nums[0]];
            v2 = tab[v2 / 65536] * mix[nums[1]];
            v2 = tab[v2 / 65536] * mix[nums[2]];
            v2 = tab[v2 / 65536] * mix[nums[3]];
            v2 = tab[v2 / 65536] * mix[nums[4]];
            v2 = tab[v2 / 65536] * mix[nums[5]];
            v2 = tab[v2 / 65536] * mix[nums[6]];
            v2 = tab[v2 / 65536] * mix[nums[7]];
            x = (s16)v0; y = (s16)v1; z = (s16)v2;
        } else if (mode >= 8) {
            if (a->unk_9c == 0 && a->unk_9e == 0 && a->unk_a0 == 0) {
                a->unk_9c = *(s16 *)(lbl_8017A288 + 3);
                a->unk_9e = *(s16 *)(lbl_8017A288 + 3) + 2;
                a->unk_a0 = *(s16 *)(lbl_8017A288 + 4);
            }
            x = a->unk_9c; y = a->unk_9e; result = a->unk_a0;
        } else {
            x = y = 0; result = 0;
        }
        fn_8004E2CC(a->unk_8, x, y, result);
        if (fn_80046BE0(arg1, arg2, &a->unk_1c) < 0) return 0;
        if (fn_80046AC0(arg1, arg2, &x, &y) < 0) return 0;
        fn_8004E324(a->unk_8, a->unk_14, a->unk_1c);
        fn_8004E300(a->unk_8, (s16 *)&x, (s16 *)&y);
        ADX_DecodeInfoExLoop((signed char *)arg1, arg2, (int *)&a->unk_20,
          (short *)&a->unk_24, (short *)&a->unk_26, (int *)&a->unk_28,
          (int *)&a->unk_2c, (int *)&a->unk_30, (int *)&a->unk_34);
        fn_8004683C((u8 *)arg1, arg2, (int *)&a->unk_bc, (u8 *)&a->unk_c0,
          (s16 *)&a->unk_d0, (s16 *)&a->unk_d2);
        a->unk_98 = 0;
    }
    a->unk_50 = a->unk_e;
    a->unk_54 = a->unk_f;
    a->unk_58 = a->unk_10;
    a->unk_5c = a->unk_3c;
    a->unk_60 = a->unk_40;
    a->unk_64 = a->unk_44;
    a->unk_8c = 0;
    return result;
}
