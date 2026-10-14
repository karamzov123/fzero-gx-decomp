/* Non-matching: best partial attempt (88.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_800531F0_Arg0 {
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
};
struct fn_800531F0_Arg1 {
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
struct fn_800531F0_Arg2 { u16 unk_0; };

#pragma pool_data on
void fn_800531F0(struct fn_800531F0_Arg0 *arg0, struct fn_800531F0_Arg1 *arg1, struct fn_800531F0_Arg2 *arg2) {
    s32 i = 32;
    f32 sum;
    do {
        sum = 0.0f;
        sum += arg1->unk_0 * arg0->unk_0;
        sum += arg1->unk_4 * arg0->unk_180;
        sum += arg1->unk_8 * arg0->unk_200;
        sum += arg1->unk_C * arg0->unk_380;
        sum += arg1->unk_10 * arg0->unk_400;
        sum += arg1->unk_14 * arg0->unk_580;
        sum += arg1->unk_18 * arg0->unk_600;
        sum += arg1->unk_1C * arg0->unk_780;
        sum += arg1->unk_20 * arg0->unk_800;
        sum += arg1->unk_24 * arg0->unk_980;
        sum += arg1->unk_28 * arg0->unk_A00;
        sum += arg1->unk_2C * *(f32 *)((u8 *)arg0 - 0x480);
        sum += arg1->unk_30 * *(f32 *)((u8 *)arg0 - 0x400);
        sum += arg1->unk_34 * *(f32 *)((u8 *)arg0 - 0x280);
        sum += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 0x200);
        sum += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 0x80);
        if (sum > 2147483648.0f) sum = 2147483648.0f;
        else if (sum < -2147483648.0f) sum = -2147483648.0f;
        arg2->unk_0 = (s32)(f32)((s32)sum >> 16);
        arg0 = (struct fn_800531F0_Arg0 *)((u8 *)arg0 + 4);
        arg1++;
        arg2++;
    } while (--i);
}
