/* Non-matching: best partial attempt (97.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80052F30_Arg0 {
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
};
struct fn_80052F30_Arg1 {
    f32 unk_0, unk_4, unk_8, unk_C;
    f32 unk_10, unk_14, unk_18, unk_1C;
    f32 unk_20, unk_24, unk_28, unk_2C;
    f32 unk_30, unk_34, unk_38, unk_3C;
};
struct fn_80052F30_Arg2 { u16 unk_0; };
extern f32 lbl_80091338[6];

#pragma sdata2_size 0
#pragma pool_data on
static const f32 pool_primer[] = {0.0f, 2147483648.0f, -2147483648.0f, 0.0f};
void fn_80052F30(struct fn_80052F30_Arg0 *arg0, struct fn_80052F30_Arg1 *arg1, struct fn_80052F30_Arg2 *arg2) {
    s32 count = 32;
    f32 v;
    f32 *pool = lbl_80091338;
    f64 bias = *(f64 *)(pool + 4);
    f32 upper = pool[1];
    union { f64 d; s32 i[2]; } conv;
    do {
        v = pool[0];
        v = arg1->unk_0 * arg0->unk_0 + v;
        v = arg1->unk_4 * arg0->unk_180 + v;
        v = arg1->unk_8 * arg0->unk_200 + v;
        v = arg1->unk_C * arg0->unk_380 + v;
        v = arg1->unk_10 * arg0->unk_400 + v;
        v = arg1->unk_14 * arg0->unk_580 + v;
        v = arg1->unk_18 * arg0->unk_600 + v;
        v = arg1->unk_1C * arg0->unk_780 + v;
        v = arg1->unk_20 * arg0->unk_800 + v;
        v = arg1->unk_24 * *(f32 *)((u8 *)arg0 - 0x680) + v;
        v = arg1->unk_28 * *(f32 *)((u8 *)arg0 - 0x600) + v;
        v = arg1->unk_2C * *(f32 *)((u8 *)arg0 - 0x480) + v;
        v = arg1->unk_30 * *(f32 *)((u8 *)arg0 - 0x400) + v;
        v = arg1->unk_34 * *(f32 *)((u8 *)arg0 - 0x280) + v;
        v = arg1->unk_38 * *(f32 *)((u8 *)arg0 - 0x200) + v;
        v = arg1->unk_3C * *(f32 *)((u8 *)arg0 - 0x80) + v;
        arg0 = (struct fn_80052F30_Arg0 *)((u8 *)arg0 + 4);
        arg1++;
        if (v > upper) v = upper;
        else if (v < pool[2]) v = pool[2];
        conv.i[0] = 0x43300000;
        conv.i[1] = ((s32)v >> 16) ^ 0x80000000;
        arg2->unk_0 = (s32)(f32)(conv.d - bias);
        arg2++;
    } while (--count);
}
