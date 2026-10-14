/* Non-matching: best partial attempt (65.54% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/toolkit.h"

typedef struct {
    f32 unk_0;
    u8 pad_4[0x94];
    f64 unk_98;
    u8 pad_A0[0xE8];
    f32 unk_188;
    u8 pad_18C[0x44];
    f32 unk_1D0;
    u8 pad_1D4[0x24];
    f64 unk_1F8;
    u32 unk_200, unk_204, unk_208, unk_20C, unk_210, unk_214, unk_218, unk_21C, unk_220;
    f32 unk_224, unk_228, unk_22C;
} RoTable;

typedef struct {
    u32 unk_0, unk_4, unk_8;
    f32 unk_C, unk_10, unk_14;
    u32 unk_18, unk_1C, unk_20, unk_24, unk_28, unk_2C, unk_30;
} Mat34;

typedef struct {
    u32 unk_0, unk_4, unk_8;
} Vec3u;

extern const RoTable lbl_3_rodata_768;
extern Mat34 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;

extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_1_F7870(u32);
extern void fn_1_55FF0(f32);
extern void fn_3_1F81C(void);
extern s16 fn_1_14F118(s16);
extern void fn_1_14DE80(void *, void *, void *, s16, f32);
extern void fn_1_14E054(void *, void *, s16, f32);
extern void fn_1_14E198(void *, void *, s16, f32);

s32 fn_3_1EC2C(void) {
    const RoTable *ro;
    Mat34 mat;
    Vec3u v3, v1, v2;
    u32 z0, z1;
    Obj_3_bss_7E6F0 *ent;
    s16 id;
    f32 s;
    f32 t;

    ro = &lbl_3_rodata_768;
    ent = (Obj_3_bss_7E6F0 *)((u8 *)&lbl_3_bss_7E6F0 + *(s16 *)((u8 *)&lbl_3_bss_20 + 0xC2) * 16);
    fn_80008BEC((u8 *)&lbl_3_bss_A2468 + 4, 0, 12);
    fn_80008BEC((u8 *)&lbl_3_bss_A2468 + 0x10, 0, 12);
    v1 = *(Vec3u *)&ro->unk_200;
    v2 = *(Vec3u *)&ro->unk_20C;
    fn_80008BA8((u32)((u8 *)&lbl_3_bss_A2468 + 4), (u32)&v1, 12);
    fn_80008BA8((u32)((u8 *)&lbl_3_bss_A2468 + 0x10), (u32)&v2, 12);
    fn_8006F038((void *)((u8 *)&lbl_3_bss_A2468 + 4), (void *)((u8 *)&lbl_3_bss_A2468 + 0x10), 0);
    lbl_8006DCDC();
    s = ro->unk_0;
    mat = lbl_1_data_1E5C0;
    mat.unk_C = lbl_1_data_1E5C0.unk_C * s - lbl_1_data_1E5C0.unk_10 * s;
    mat.unk_10 = lbl_1_data_1E5C0.unk_C * s + lbl_1_data_1E5C0.unk_10 * s;
    mat.unk_14 = lbl_1_data_1E5C0.unk_14;
    fn_1_F7870((u32)&mat);
    lbl_8006DCA4();
    lbl_8006E0B4(ro->unk_1D0, ro->unk_224, ro->unk_1D0);
    mathutil_mtxA_rotate_x(0x2000);
    t = (double)(360 - (s32)(lbl_801A66A0 % 360)) - ro->unk_1F8;
    mathutil_mtxA_rotate_y((s32)(ro->unk_228 * t));
    fn_3_1F81C();
    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    t = (double)(s32)(lbl_801A66A0 % 360) - ro->unk_1F8;
    mathutil_mtxA_rotate_y((s32)(ro->unk_228 * t));
    t = ((double)(2147483648 + lbl_3_bss_18) - ro->unk_98) / ro->unk_22C;
    fn_1_55FF0(t);
    v3 = *(Vec3u *)&ro->unk_218;
    z0 = 0;
    z1 = 0;
    switch (ent->unk_2) {
    case 0:
        id = fn_1_14F118(ent->unk_0);
        fn_1_14DE80((void *)((u8 *)lbl_3_bss_6DE20 + id * 0xa20), (void *)&z0, (void *)&z1, (s16)lbl_3_bss_20848, ro->unk_188);
        break;
    case 1:
        id = fn_1_14F118(ent->unk_0);
        fn_1_14E054((void *)((u8 *)lbl_3_bss_6DE20 + id * 0xa20), (void *)&v3, (s16)lbl_3_bss_20848, ro->unk_188);
        break;
    case 2:
        id = fn_1_14F118(ent->unk_0);
        fn_1_14E198((void *)((u8 *)lbl_3_bss_6DE20 + id * 0xa20), (void *)&v3, (s16)lbl_3_bss_20848, ro->unk_188);
        break;
    }
    return 0;
}
