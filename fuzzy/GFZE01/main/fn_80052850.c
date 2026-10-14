/* Non-matching: best partial attempt (94.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80052850_Arg0 {
    f32 unk_0;
    u8 pad_4[0x17C];
    f32 unk_180;
    u8 pad_184[0x7C];
    f32 unk_200;
    u8 pad_204[0x17C];
    f32 unk_380;
};
struct fn_80052850_Arg1 {
    f32 unk_0, unk_4, unk_8, unk_C;
    f32 unk_10, unk_14, unk_18, unk_1C;
    f32 unk_20, unk_24, unk_28, unk_2C;
    f32 unk_30, unk_34, unk_38, unk_3C;
};
struct fn_80052850_Arg2 { u16 unk_0; };
extern f32 lbl_80091338[6];

void fn_80052850(struct fn_80052850_Arg0 *arg0, struct fn_80052850_Arg1 *arg1, struct fn_80052850_Arg2 *arg2) {
    s32 count = 32;
    f32 v;
    f32 max = 2147483648.0f;
    do {
        v = 0.0f;
        v = arg1->unk_0 * arg0->unk_0 + v;
        v = arg1->unk_4 * arg0->unk_180 + v;
        v = arg1->unk_8 * arg0->unk_200 + v;
        v = arg1->unk_C * arg0->unk_380 + v;
        v = arg1->unk_10 * *(f32 *)((u8 *)arg0 - 3072) + v;
        v = arg1->unk_14 * *(f32 *)((u8 *)arg0 - 2688) + v;
        v = arg1->unk_18 * *(f32 *)((u8 *)arg0 - 2560) + v;
        v = arg1->unk_1C * *(f32 *)((u8 *)arg0 - 2176) + v;
        v = arg1->unk_20 * *(f32 *)((u8 *)arg0 - 2048) + v;
        v = arg1->unk_24 * *(f32 *)((u8 *)arg0 - 1664) + v;
        v = arg1->unk_28 * *(f32 *)((u8 *)arg0 - 1536) + v;
        v = arg1->unk_2C * *(f32 *)((u8 *)arg0 - 1152) + v;
        v = arg1->unk_30 * *(f32 *)((u8 *)arg0 - 1024) + v;
        v = arg1->unk_34 * *(f32 *)((u8 *)arg0 - 640) + v;
        v = arg1->unk_38 * *(f32 *)((u8 *)arg0 - 512) + v;
        v = arg1->unk_3C * *(f32 *)((u8 *)arg0 - 128) + v;
        arg0 = (struct fn_80052850_Arg0 *)((u8 *)arg0 + 4);
        arg1++;
        if (v > max) v = max;
        else if (v < -2147483648.0f) v = -2147483648.0f;
        arg2->unk_0 = (s32)(f32)((s32)v >> 16);
        arg2++;
    } while (--count);
}
