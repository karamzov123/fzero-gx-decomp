/* Non-matching: best partial attempt (94.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#pragma pool_data on
const f32 lbl_80091338[4] = {0.0f, 2147483648.0f, -2147483648.0f, 0.0f};

struct fn_800534B0_Arg0 {
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
};
struct fn_800534B0_Arg1 {
    f32 unk_0, unk_4, unk_8, unk_C;
    f32 unk_10, unk_14, unk_18, unk_1C;
    f32 unk_20, unk_24, unk_28, unk_2C;
    f32 unk_30, unk_34, unk_38, unk_3C;
};
struct fn_800534B0_Arg2 { s16 unk_0; };

#pragma opt_strength_reduction off
static inline const f32 *fn_800534B0_array_read(const f32 *array) { return array; }
#pragma opt_strength_reduction reset

#pragma opt_common_subs off
void fn_800534B0(struct fn_800534B0_Arg0 *arg0, struct fn_800534B0_Arg1 *arg1, struct fn_800534B0_Arg2 *arg2) {
    f32 fzgx_live;
    s32 n = 32;

    do {
        f32 v = 0.0f;
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
        fzgx_live = arg1->unk_28;
        v += fzgx_live * arg0->unk_A00;
        v += arg1->unk_2C * arg0->unk_B80;
        v += arg1->unk_30 * arg0->unk_C00;
        v += arg1->unk_34 * *(f32 *)((u8 *)arg0 - 0x280);
        v += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 0x200);
        v += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 0x80);
        arg0 = (struct fn_800534B0_Arg0 *)((u8 *)arg0 + 4);
        arg1++;
        if (v > 2147483648.0f) v = 2147483648.0f;
        else if (v < -2147483648.0f) v = -2147483648.0f;
        arg2->unk_0 = (s32)(f32)((s32)v >> 16);
        arg2++;
    } while (--n);
}
#pragma opt_common_subs reset

