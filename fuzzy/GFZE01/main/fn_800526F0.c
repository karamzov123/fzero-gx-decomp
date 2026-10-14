/* Non-matching: best partial attempt (97.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_800526F0_Arg0 {
    f32 unk_0;
    u8 pad_4[0x17C];
    f32 unk_180;
    u8 pad_184[0x7C];
    f32 unk_200;
};

struct fn_800526F0_Arg1 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};

struct fn_800526F0_Arg2 {
    u16 unk_0;
};

extern f32 lbl_80091338[6];

void fn_800526F0(struct fn_800526F0_Arg0 *arg0, struct fn_800526F0_Arg1 *arg1, struct fn_800526F0_Arg2 *arg2) {
    s32 i;
    s32 n;
    s32 t;
    f32 v2;
    f64 v0;
    f32 v3;
    f32 v1;
    union {
        f64 d;
        struct {
            u32 hi;
            u32 lo;
        } w;
    } convert;

    i = 0;
    n = 32;
    v0 = *(f64 *)&lbl_80091338[4];
    v1 = lbl_80091338[1];
    do {
        v2 = lbl_80091338[0];
        v2 += arg1->unk_0 * arg0->unk_0;
        v2 += arg1->unk_4 * ((f32 *)arg0)[0x60];
        v2 += arg1->unk_8 * ((f32 *)arg0)[0x80];
        v2 += arg1->unk_C * ((f32 *)arg0)[-0x320];
        v2 += arg1->unk_10 * ((f32 *)arg0)[-0x300];
        v2 += arg1->unk_14 * ((f32 *)arg0)[-0x2A0];
        v2 += arg1->unk_18 * ((f32 *)arg0)[-0x280];
        v2 += arg1->unk_1C * ((f32 *)arg0)[-0x220];
        v2 += arg1->unk_20 * ((f32 *)arg0)[-0x200];
        v2 += arg1->unk_24 * ((f32 *)arg0)[-0x1A0];
        v2 += arg1->unk_28 * ((f32 *)arg0)[-0x180];
        v2 += arg1->unk_2C * ((f32 *)arg0)[-0x120];
        v2 += arg1->unk_30 * ((f32 *)arg0)[-0x100];
        v2 += arg1->unk_34 * ((f32 *)arg0)[-0xA0];
        v2 += arg1->unk_38 * ((f32 *)arg0)[-0x80];
        v2 += arg1->unk_3C * ((f32 *)arg0)[-0x20];
        arg1++;
        arg0 = (struct fn_800526F0_Arg0 *)((f32 *)arg0 + 1);
        if (v2 > v1) {
            v2 = v1;
        } else {
            v3 = lbl_80091338[2];
            if (v2 < v3) {
                v2 = v3;
            }
        }
        t = (s32)v2;
        convert.w.hi = 0x43300000;
        convert.w.lo = (t >> 16) ^ 0x8000;
        arg2[i].unk_0 = convert.d - v0;
        i++;
    } while (--n != 0);
}
