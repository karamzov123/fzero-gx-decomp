/* Non-matching: best partial attempt (94.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80053610_Arg0 {
    f32 unk_0;
    u8 pad_4[0x17C];
    f32 unk_180;
    u8 pad_184[0x7C];
    f32 unk_200;
    u8 pad_204[0x17C];
    f32 unk_380;
    u8 pad_384[0x7C];
    f32 unk_400;
    u8 pad_404[0x17C];
    f32 unk_580;
    u8 pad_584[0x7C];
    f32 unk_600;
    u8 pad_604[0x17C];
    f32 unk_780;
    u8 pad_784[0x7C];
    f32 unk_800;
    u8 pad_804[0x17C];
    f32 unk_980;
    u8 pad_984[0x7C];
    f32 unk_A00;
    u8 pad_A04[0x17C];
    f32 unk_B80;
    u8 pad_B84[0x7C];
    f32 unk_C00;
    u8 pad_C04[0x17C];
    f32 unk_D80;
};
struct fn_80053610_Arg1 {
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
struct fn_80053610_Arg2 { u16 unk_0; };

extern f32 lbl_80091338[6];

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
void fn_80053610(struct fn_80053610_Arg0 *arg0, struct fn_80053610_Arg1 *arg1, struct fn_80053610_Arg2 *arg2) {
    f32 fzgx_live;
    f32 vmax = (2.14748365e+09f);
    s32 n = 32;
    f32 v;
    do {
        v = (0.0f);
        v += arg1->unk_0 * arg0->unk_0;
        v += arg1->unk_4 * arg0->unk_180;
        v += arg1->unk_8 * arg0->unk_200;
        v += arg1->unk_C * arg0->unk_380;
        v += arg1->unk_10 * arg0->unk_400;
        v += arg1->unk_14 * arg0->unk_580;
        v += arg1->unk_18 * arg0->unk_600;
        v += arg1->unk_1C * arg0->unk_780;
        v += arg1->unk_20 * arg0->unk_800;
        v += arg1->unk_24 * arg0->unk_980;
        v += arg1->unk_28 * arg0->unk_A00;
        v += arg1->unk_2C * arg0->unk_B80;
        fzgx_live = arg1->unk_30;
        v += fzgx_live * arg0->unk_C00;
        v += arg1->unk_34 * arg0->unk_D80;
        v += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 512);
        v += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 128);
        arg0 = (struct fn_80053610_Arg0 *)(((4) + ((u8 *)arg0)));
        arg1++;
        if (v > vmax) v = vmax;
        else if (v < (-2.14748365e+09f)) v = (-2.14748365e+09f);
        arg2->unk_0 = (s32)(f32)((s32)v >> 16);
        arg2++;
    } while (--n != 0);
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

