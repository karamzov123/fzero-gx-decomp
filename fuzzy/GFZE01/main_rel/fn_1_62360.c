/* Non-matching: best partial attempt (24.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/effect.h"

struct fn_1_62360_pool {
    u8 pad_0[0x38];
    f64 unk_38;
    u8 pad_40[0x10];
    f32 unk_50;
    u8 pad_54[0x2C];
    f32 unk_80;
    u8 pad_84[0x40];
    f32 unk_C4;
    u8 pad_C8[0x200];
    f64 unk_2C8;
    f32 unk_2D0;
    f32 unk_2D4;
};
struct fn_1_62360_801A6D00 {
    u32 unk_0;
};

extern struct fn_1_62360_pool lbl_1_rodata_2950;
extern struct fn_1_62360_801A6D00 lbl_801A6D00;
extern u32 GXLoadPosMtxImm(u32, u32);
extern void fn_1_62794(void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern f32 lbl_8006D188(u32);
extern void lbl_8006D1B8(s32, void *);
extern void lbl_8006DFE8(u32);
extern void lbl_8006E0A4(u32);

extern vu32 __PIRegs[];
extern vu32 __VIRegs[];

void fn_1_62360(void * arg0) {
    struct fn_1_62360_pool *p_lbl_1_rodata_2950;
    u32 v0;
    f32 v1;
    s32 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v12;
    s32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    s32 v22;
    s32 v23;
    s32 v24;
    s32 v25;
    struct { f32 a[2]; } loc_8;

    p_lbl_1_rodata_2950 = &lbl_1_rodata_2950;
    v0 = *(u32 *)((u8 *)arg0 + 56);
    lbl_8006DFE8((u32)((u8 *)arg0 + 184));
    lbl_8006E0A4((u32)((u8 *)arg0 + 60));
    fn_1_62794((void *)v0);

    v1 = lbl_1_data_1D8A4;
    v2 = 60;
    v3 = (f32)lbl_1_rodata_2950.unk_2C8 * (f32)(v2 - (f32)*(u32 *)((u8 *)arg0 + 16)) / v1;
    v4 = lbl_1_rodata_2950.unk_80 * v3;
    v5 = lbl_1_rodata_2950.unk_2D0 * v3;
    v6 = lbl_1_rodata_2950.unk_C4 * (f32)(*(u32 *)((u8 *)arg0 + 16) % v2) / v1;
    lbl_8006D188((s32)v6);

    v1 = lbl_1_rodata_2950.unk_C4 * (f32)(*(u32 *)((u8 *)arg0 + 16) % v2) / lbl_1_data_1D8A4;
    v7 = lbl_8006D188((s32)v1);
    v1 = lbl_1_rodata_2950.unk_2D4 * v7;
    v6 = lbl_1_rodata_2950.unk_C4 * (f32)(*(u32 *)((u8 *)arg0 + 16) % v2) / lbl_1_data_1D8A4;
    lbl_8006D188((s32)v6);

    v1 = (s32)lbl_1_rodata_2950.unk_50;
    fn_800724C8();
    fn_8007245C(2560);
    fn_80074918(1, 7, 0);
    GXLoadPosMtxImm(lbl_801A6D00.unk_0, 0);
    fn_8003462C(152, 0, 42);

    v2 = (s32)v1;
    v3 = v1;
    for (v4 = 0; v4 < 20; v4++) {
        lbl_8006D1B8((s16)(v4 * 360 / 20), &loc_8);
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v4 * loc_8.a[1];
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v4 * loc_8.a[0];
        *(f32 *)((u8 *)__VIRegs + 0) = lbl_1_rodata_2950.unk_50;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = v2;
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v5 * loc_8.a[1];
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v5 * loc_8.a[0];
        *(f32 *)((u8 *)__VIRegs + 0) = lbl_1_rodata_2950.unk_50;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = v1;
    }

    fn_8003462C(152, 0, 42);
    v3 = lbl_1_rodata_2950.unk_50;
    for (v4 = 0; v4 < 20; v4++) {
        lbl_8006D1B8((s16)(v4 * 360 / 20), &loc_8);
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v5 * loc_8.a[1];
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v5 * loc_8.a[0];
        *(f32 *)((u8 *)__VIRegs + 0) = lbl_1_rodata_2950.unk_50;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = v1;
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v6 * loc_8.a[1];
        *(f32 *)((u8 *)__VIRegs + 0) = v3 + v6 * loc_8.a[0];
        *(f32 *)((u8 *)__VIRegs + 0) = lbl_1_rodata_2950.unk_50;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = 0;
        *(u8 *)((u8 *)__VIRegs + 0) = v2;
    }

    fn_80074788(0);
    fn_80073898(0);
    fn_80073C6C(0);
}
