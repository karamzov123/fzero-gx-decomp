/* Non-matching: best partial attempt (72.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"
#include "psvec.h"

struct fn_1_60D54_lbl_801A6D00 { u32 unk_0; };
extern struct fn_1_60D54_lbl_801A6D00 lbl_801A6D00;
extern void * lbl_8006DC6C(void *);
extern void * memset(void *, int, u32);
extern void fn_1_556B8(void *);
extern void fn_1_55FC4(f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_80072558(void);
extern void lbl_8006E14C(f32);

void fn_1_60D54(void *arg0) {
    u32 v0;
    u32 v1;
    u32 v3;
    f32 v4;
    f32 v5;
    u32 v6;
    f64 v7;
    f32 v8;
    f32 v9;
    f32 v10;
    f64 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 v17;
    f32 v18;
    f32 v19;
    f32 v20;
    f32 v21;
    f32 v22;
    f32 v23;
    f32 v24;
    struct { u8 a[64]; } loc_14;
    v0 = 0x41C64E6D;
    v1 = *(u32 *)((u8 *)arg0 + 52);
    v3 = lbl_1_data_1D628 * v0 + 12345;
    v4 = 0.25f;
    v5 = 32767.0f;
    v6 = v3 * v0 + 12345;
    v7 = 0.2;
    v8 = v4 * (f32)(v4 * *(f32 *)((u8 *)arg0 + 180));
    lbl_1_data_1D628 = v3;
    v9 = 0.125f;
    lbl_1_data_1D628 = v6;
    v10 = 1.0f;
    v11 = 0.800000011920929;
    v12 = *(f32 *)((u8 *)arg0 + 40);
    v13 = v9 + v8;
    v14 = v10 + (f32)((f32)(u32)((v3 >> 16) & 0x7FFF) / v5);
    v15 = v13 * v14;
    v16 = v7 * ((f64)v12 * (v11 + (f64)(v7 * (f64)((f32)(u32)((v6 >> 16) & 0x7FFF) / v5))));
    memset(&loc_14, 0, 64);
    v17 = *(f32 *)((u8 *)arg0 + 32);
    v18 = v15 * *(f32 *)((u8 *)arg0 + 28);
    v19 = v15 * v17;
    v20 = v15 * *(f32 *)((u8 *)arg0 + 36);
    loc_14.a[60] = OSf32tou8(v18);
    loc_14.a[61] = OSf32tou8(v19);
    loc_14.a[62] = OSf32tou8(v20);
    loc_14.a[63] = 255;
    lbl_8006DC6C((void *)(lbl_801A6D00.unk_0 + 48));
    v21 = *(f32 *)((u8 *)arg0 + 60);
    v22 = *(f32 *)((u8 *)arg0 + 64);
    v23 = *(f32 *)((u8 *)arg0 + 68);
    *(f32 *)(0xE0000000 + 0x0C) = v21;
    *(f32 *)(0xE0000000 + 0x1C) = v22;
    *(f32 *)(0xE0000000 + 0x2C) = v23;
    lbl_8006E14C(v16);
    fn_1_55FC4(v16);
    fn_1_56000(1, 3, 0);
    fn_1_5621C(v18, v19, v20, 1.0f);
    fn_80072558();
    fn_1_556B8((void *)v1);
    v24 = 1.0f;
    fn_1_5621C(v24, v24, v24, v24);
    fn_1_56000(1, 3, 1);
}
