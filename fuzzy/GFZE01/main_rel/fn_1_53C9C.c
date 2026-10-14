/* Non-matching: best partial attempt (98.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(s32);
extern f32 fn_1_4B090(s32);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30;
    u8 unk_34[4];
    u32 unk_38;
    u8 unk_3C[0x1C];
} UnkData;

typedef union {
    f64 d;
    u32 w[2];
} F64Bits;

#pragma opt_propagation on
#pragma opt_common_subs off
void fn_1_53C9C(void *arg0, const char *arg1, f32 a, f32 b, f32 c, f32 p4, f32 p5)
{
    f32 eight;
    f32 d = p4;
    f32 e = p5;
    f32 t;
    f32 w;
    u8 *pool = (u8 *)&lbl_1_rodata_26F8;
    UnkData data;

    if (c < *(f32 *)(pool + 0x164)) {
        c = *(f32 *)(pool + 0x164);
    }
    fn_1_496FC(a, b);
    fn_1_4954C((f32)(c - *(f64 *)(pool + 0x168)));
    fn_1_4955C(e, e);
    fn_1_495C8(9);
    fn_1_4A0D8(arg1);
    t = fn_1_4B068((s32)arg1);
    d = ((d) * (e));
    e = d + t;
    w = d + fn_1_4B090((s32)arg1);
    data = *(UnkData *)pool;
    data.unk_00 = 12;
    data.unk_04 = a;
    data.unk_08 = b;
    data.unk_0C = c;
    if (arg0 != 0) {
        F64Bits cv;
        cv.w[0] = 0x43300000;
        cv.w[1] = *(u8 *)((u8 *)arg0 + 3);
        data.unk_2C = (f32)((cv.d - *(f64 *)(pool + 0x60)) / *(f64 *)(pool + 0x150));
        data.unk_38 = *(u32 *)arg0;
    }
    eight = *(f32 *)(pool + 0x158);
    data.unk_30 = 10;
    fn_1_50190(&data, e, w, eight, eight, eight, eight);
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
