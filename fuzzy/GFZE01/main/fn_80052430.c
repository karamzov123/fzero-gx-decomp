/* Non-matching: best partial attempt (94.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80052430_Arg0 {
    f32 unk_0;
};
struct fn_80052430_Arg1 {
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
struct fn_80052430_Arg2 {
    u16 unk_0;
};
extern f32 lbl_80091338[6];

void fn_80052430(struct fn_80052430_Arg0 *arg0, struct fn_80052430_Arg1 *arg1, struct fn_80052430_Arg2 *arg2) {
    s32 count = 32;
    f32 v2;
    do {
        v2 = 0.0f;
        v2 += arg1->unk_0 * arg0->unk_0;
        v2 += arg1->unk_4 * *(f32 *)((u8 *)arg0 - 3712);
        v2 += arg1->unk_8 * *(f32 *)((u8 *)arg0 - 3584);
        v2 += arg1->unk_C * *(f32 *)((u8 *)arg0 - 3200);
        v2 += arg1->unk_10 * *(f32 *)((u8 *)arg0 - 3072);
        v2 += arg1->unk_14 * *(f32 *)((u8 *)arg0 - 2688);
        v2 += arg1->unk_18 * *(f32 *)((u8 *)arg0 - 2560);
        v2 += arg1->unk_1C * *(f32 *)((u8 *)arg0 - 2176);
        v2 += arg1->unk_20 * *(f32 *)((u8 *)arg0 - 2048);
        v2 += arg1->unk_24 * *(f32 *)((u8 *)arg0 - 1664);
        v2 += arg1->unk_28 * *(f32 *)((u8 *)arg0 - 1536);
        v2 += arg1->unk_2C * *(f32 *)((u8 *)arg0 - 1152);
        v2 += arg1->unk_30 * *(f32 *)((u8 *)arg0 - 1024);
        v2 += arg1->unk_34 * *(f32 *)((u8 *)arg0 - 640);
        v2 += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 512);
        v2 += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 128);
        arg1++;
        arg0++;
        if (v2 > 2147483648.0f) v2 = 2147483648.0f;
        else if (v2 < -2147483648.0f) v2 = -2147483648.0f;
        arg2->unk_0 = (s32)(f32)((s32)v2 >> 16);
        arg2++;
    } while (--count);
}
