/* Non-matching: best partial attempt (94.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80052C70_Arg0 {
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
};
struct fn_80052C70_Arg1 {
    f32 unk_0, unk_4, unk_8, unk_C;
    f32 unk_10, unk_14, unk_18, unk_1C;
    f32 unk_20, unk_24, unk_28, unk_2C;
    f32 unk_30, unk_34, unk_38, unk_3C;
};
struct fn_80052C70_Arg2 { u16 unk_0; };

extern f32 lbl_80091338[6];

#pragma peephole on
static inline f32 fn_80052C70_read_pointer(struct fn_80052C70_Arg0 * owner) { return owner->unk_400; }
void fn_80052C70(struct fn_80052C70_Arg0 *arg0, struct fn_80052C70_Arg1 *arg1, struct fn_80052C70_Arg2 *arg2, u32 unused3, u32 unused4) {
    s32 count = 32;
    f32 v1;
    f32 upper = (2.14748365e+09f);
    do {
        v1 = (0.0f);
        v1 += arg1->unk_0 * arg0->unk_0;
        v1 += arg1->unk_4 * arg0->unk_180;
        v1 += arg1->unk_8 * arg0->unk_200;
        v1 += arg1->unk_C * arg0->unk_380;
        v1 += arg1->unk_10 * fn_80052C70_read_pointer(arg0);
        v1 += arg1->unk_14 * arg0->unk_580;
        v1 += arg1->unk_18 * arg0->unk_600;
        v1 += arg1->unk_1C * *(f32 *)((u8 *)arg0 - 0x880);
        v1 += arg1->unk_20 * *(f32 *)((u8 *)arg0 - 0x800);
        v1 += arg1->unk_24 * *(f32 *)((u8 *)arg0 - 0x680);
        v1 += arg1->unk_28 * *(f32 *)((u8 *)arg0 - 0x600);
        v1 += arg1->unk_2C * *(f32 *)((u8 *)arg0 - 0x480);
        v1 += arg1->unk_30 * *(f32 *)((u8 *)arg0 - 0x400);
        v1 += arg1->unk_34 * *(f32 *)((u8 *)arg0 - 0x280);
        v1 += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 0x200);
        v1 += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 0x80);
        arg0 = (struct fn_80052C70_Arg0 *)((u8 *)arg0 + 4);
        arg1++;
        if (v1 > upper) v1 = upper;
        else if (v1 < (-2.14748365e+09f)) v1 = (-2.14748365e+09f);
        arg2->unk_0 = (s32)(f32)((s32)v1 >> 16);
        arg2++;
    } while (--count);
}
#pragma peephole reset

