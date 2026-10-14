/* Non-matching: best partial attempt (68.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/toolkit.h"

typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;

struct fn_3_1F958_lbl_3_rodata_768 {
    f32 unk_0;
    u8 pad_4[0x1CC];
    f32 unk_1D0;
    u8 pad_1D4[0x24];
    f64 unk_1F8;
    u8 pad_200[0x24];
    f32 unk_224;
    f32 unk_228;
    u8 pad_22C[0x28];
    u32 unk_254;
    u32 unk_258;
    u32 unk_25C;
    u32 unk_260;
    u32 unk_264;
    u32 unk_268;
};
struct fn_3_1F958_lbl_1_data_1E5C0 {
    u32 unk_0; u32 unk_4; u32 unk_8; f32 unk_C; f32 unk_10;
    f32 unk_14; u32 unk_18; u32 unk_1C; u32 unk_20; u32 unk_24;
    u32 unk_28; u32 unk_2C; u32 unk_30;
};
struct fn_3_1F958_lbl_801A66A0 { u32 unk_0; };
struct fn_3_1F958_lbl_1_bss_38460 { u8 pad_0[0xC]; u32 unk_C; };

extern struct fn_3_1F958_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern struct fn_3_1F958_lbl_3_rodata_768 lbl_3_rodata_768;
extern struct fn_3_1F958_lbl_801A66A0 lbl_801A66A0;
extern struct fn_3_1F958_lbl_1_bss_38460 lbl_1_bss_38460;
extern u32 lbl_1_bss_9F8[];
extern u32 lbl_3_bss_7EC04;
extern u32 lbl_3_bss_20848;
extern s16 lbl_3_bss_18;
extern u8 lbl_3_bss_6DE20[];
extern void *lbl_801A6D00;
extern void fn_1_56018(s32);
extern void fn_1_560F0(s32, void *);
extern void lbl_8006D784(void *);
extern f32 lbl_8006D188(s16);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void lbl_8006DB74(void *);
extern void fn_80072558(void);
extern void fn_1_55210(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBAC(void *);
extern void fn_1_151BDC(void *);
extern void fn_1_14DEA4(void *, void *, void *, s16, f32);
extern void fn_1_14E078(void *, void *, s16, f32);
extern void fn_1_14E1BC(void *, void *, s16, f32);
extern void fn_1_FCFA4(void *);

typedef struct { f32 a[3]; } Vec3Tmp;
typedef struct { u32 a[13]; } BoundsTmp;

void fn_3_1F958(void) {
    s16 v0, v1;
    struct fn_3_1F958_lbl_3_rodata_768 *pool;
    struct fn_3_1F958_lbl_1_data_1E5C0 *data;
    u32 loc_1C[3];
    u32 loc_10[3];
    BoundsTmp bounds;
    Vec3Tmp vec;
    s32 i, j;
    Obj_3_bss_20 *entry;
    Obj_3_bss_140 *base;
    u8 *asset0;
    u8 *asset1;
    u8 *asset2;
    f32 frac;
    s32 idx;
    u32 flag;
    u32 angle;
    u32 n;

    v0 = lbl_3_bss_F0.unk_8;
    v1 = lbl_3_bss_F0.unk_6;
    pool = &lbl_3_rodata_768;
    fn_80008BEC((u8 *)&lbl_3_bss_A2468 + 4, 0, 12);
    fn_80008BEC((u8 *)&lbl_3_bss_A2468 + 16, 0, 12);
    loc_1C[0] = pool->unk_254;
    loc_1C[1] = pool->unk_258;
    loc_1C[2] = pool->unk_25C;
    fn_80008BA8((u32)((u8 *)&lbl_3_bss_A2468 + 4), (u32)loc_1C, 12);
    loc_10[0] = pool->unk_260;
    loc_10[1] = pool->unk_264;
    loc_10[2] = pool->unk_268;
    fn_80008BA8((u32)((u8 *)&lbl_3_bss_A2468 + 16), (u32)loc_10, 12);
    fn_8006F038((Sig_fn_8006F038_Vec3 *)((u8 *)&lbl_3_bss_A2468 + 4),
                (Sig_fn_8006F038_Vec3 *)((u8 *)&lbl_3_bss_A2468 + 16), 0);
    lbl_8006DCDC();

    data = &lbl_1_data_1E5C0;
    frac = (f32)(data->unk_C * pool->unk_0);
    bounds.a[3] = data->unk_C;
    bounds.a[4] = data->unk_10;
    bounds.a[5] = data->unk_14;
    bounds.a[0] = data->unk_0;
    bounds.a[1] = data->unk_4;
    bounds.a[2] = data->unk_8;
    bounds.a[6] = data->unk_18;
    bounds.a[7] = data->unk_1C;
    bounds.a[8] = data->unk_20;
    bounds.a[9] = data->unk_24;
    bounds.a[10] = data->unk_28;
    bounds.a[11] = data->unk_2C;
    bounds.a[12] = data->unk_30;
    ((f32 *)&bounds)[3] = (f32)(frac - (f32)(data->unk_10 * pool->unk_0));
    ((f32 *)&bounds)[4] = (f32)(frac + (f32)(data->unk_10 * pool->unk_0));
    ((f32 *)&bounds)[5] = data->unk_14;
    fn_1_F7870(&bounds);
    lbl_8006DCA4();
    lbl_8006E0B4(pool->unk_1D0, pool->unk_224, pool->unk_1D0);
    mathutil_mtxA_rotate_x(0x2000);
    angle = lbl_801A66A0.unk_0;
    mathutil_mtxA_rotate_y((s32)(pool->unk_228 * (f32)(360 - angle % 360)));

    base = (Obj_3_bss_140 *)((u8 *)&lbl_1_bss_38460 + 0xC);
    base = (Obj_3_bss_140 *)*(u32 *)((u8 *)base + 0x8);
    base = (Obj_3_bss_140 *)*(u32 *)((u8 *)base + 0x8);
    i = 0;
    entry = (Obj_3_bss_20 *)((u8 *)base + 0x40);
    while ((s16)i < (s32)*(u16 *)((u8 *)base + 0x18)) {
        if (*(u32 *)entry & 0x20000) {
            fn_1_56018(1);
            lbl_8006D784((u8 *)lbl_801A6D00 + 0x60);
            angle = lbl_801A66A0.unk_0;
            mathutil_mtxA_rotate_y((s32)(pool->unk_228 *
                (f32)(180 - angle % 180)) + 0x4000);
            lbl_8006D188((s16)0);
            fn_1_560F0(0, (u8 *)lbl_801A6D00 + 0x60);
        }
        i++;
        entry = (Obj_3_bss_20 *)((u8 *)entry + 0x20);
    }
    fn_80072558();
    fn_1_55210(base);
    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    angle = lbl_801A66A0.unk_0;
    mathutil_mtxA_rotate_y((s32)(pool->unk_228 * (f32)(360 - angle % 360)));
    lbl_8006DB74(&vec);

    asset0 = (u8 *)&lbl_3_bss_20;
    asset1 = (u8 *)&lbl_3_bss_140;
    asset2 = (u8 *)&lbl_1_bss_9F8;
    i = 0;
    while (i < 25) {
        entry = (Obj_3_bss_20 *)(asset0 + 0x1a);
        if (entry->unk_1A == i) {
            u16 bits = *(u16 *)(asset2 + (s32)v0 * 0x14);
            s16 slot = lbl_3_bss_18;
            frac = ((f32)slot - 0.0f) / 10.0f;
            flag = (bits >> 10) & 1;
            if (flag && lbl_3_bss_7EC04 == 0)
                flag = 1;
            else if (flag)
                flag = 0;
            if ((*(u32 *)asset1 & (3U << 30)) != 0)
                j = 1;
            else
                j = 0;
            fn_1_151BDC(0);
            if (j == 1 && *(u8 *)((u8 *)asset0 + 0xA) == *(u8 *)asset1)
                fn_1_151BDC(asset1);
            if (entry->unk_18 == 0)
                frac = frac;
            else if (flag)
                frac = 1.0f;
            else
                frac = 0.25f;
            idx = entry->unk_1A;
            fn_1_14DEA4(lbl_3_bss_6DE20 + idx * 0xA20, (u8 *)&vec + 0x10,
                        (u8 *)&vec + 8, (s16)lbl_3_bss_20848, frac);
            lbl_8006DAEC();
            fn_1_151BDC(0);
            if (j == 1 && *(u8 *)((u8 *)asset0 + 8) == *(u8 *)(asset1 - 8))
                fn_1_151BDC(asset1);
            if (entry->unk_18 == 1)
                frac = frac;
            else if (flag)
                frac = 1.0f;
            else
                frac = 0.25f;
            idx = entry->unk_1C;
            fn_1_14E078(lbl_3_bss_6DE20 + idx * 0xA20,
                        (u8 *)&vec + 0x10, (s16)lbl_3_bss_20848, frac);
            lbl_8006DB30();
            fn_1_151BDC(0);
            if (j == 1 && *(u8 *)((u8 *)asset0 + 0x10) == *(u8 *)(asset1 - 0x10))
                fn_1_151BDC(asset1);
            if (entry->unk_18 == 2)
                frac = frac;
            else if (flag)
                frac = 1.0f;
            else
                frac = 0.25f;
            idx = entry->unk_1E;
            fn_1_14E1BC(lbl_3_bss_6DE20 + idx * 0xA20,
                        (u8 *)&vec + 8, (s16)lbl_3_bss_20848, frac);
        }
        i++;
        asset1 += 0x14;
        asset2 += 8;
        asset0 += 8;
    }
    if (((Obj_3_bss_20 *)asset0)->unk_18 < 3) {
        lbl_8006DBAC(&vec);
        fn_80072558();
        fn_1_FCFA4((u8 *)&lbl_3_bss_2C7C0 + v1 * 0x10440);
    }
}
