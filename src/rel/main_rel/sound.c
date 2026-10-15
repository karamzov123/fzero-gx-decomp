#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

extern void *lbl_801A6410;
extern void fn_1_44A4(void);
extern void *fn_80008E84(void *arg);
extern u32 fn_1_45D0(void *arg0, void *arg1, u32 *arg2, int arg3);
extern void fn_1_46B4(u32, void *, void *, u32);
extern s8 lbl_1_bss_6EAA6;
extern u8 lbl_1_bss_6EAA4;
extern void fn_80067974(void);
extern void fn_800280F0(void);
extern void fn_80026FE0(void);
extern u8 lbl_1_bss_6EAA8[8];
extern u8 lbl_1_bss_6EAB0;
extern void ARInit(u8 *arg0, int arg1);
extern void fn_80020530(void);
extern u8 lbl_1_bss_6F1E1;
extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_1_A2E24(u32 arg0, u32 arg1, s32 arg2);
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_A0680(void);
extern void fn_80067898(u32);
extern void fn_800674FC(u16 arg0, u32 arg1, s16 arg2);
extern s32 camera_get_mode(void);
extern u8 lbl_1_bss_6F2D8[62];
extern void fn_80067344(s32, s32, u32, s32);
extern void fn_1_A5470(s32 value);
extern u32 fn_1_3F13C(void);
extern u32 fn_1_EB0B0(void);
extern s32 fn_1_F1B94(void);
extern u32 lbl_1_rodata_45D0[];
extern u32 lbl_1_rodata_4718[];
extern u32 lbl_1_rodata_4730[];
extern u32 lbl_1_rodata_47A8[];
extern u8 lbl_1_bss_6F41C[260];
extern s32 fn_1_86690(s32 value);
extern void *lbl_1_rodata_4820[41];
extern int fn_8004C658(u32 obj);
extern int fn_8004BBCC(u32 obj);
extern void ADXT_Pause(u32 obj, int arg);
extern int fn_1_3FC38(void);

extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_80008BEC(void *, s32, s32);
extern s32 fn_1_86690(s32 value);
extern void fn_80067344(s32 arg0, s32 arg1, u32 arg2, s32 arg3);
extern void fn_80067898(u32 value);
extern void *lbl_1_rodata_4820[41];

extern void *lbl_801A6410;
extern void *fn_80008E84();
extern void fn_1_44A4(void);

extern void *lbl_801A6410;
extern void fn_1_44A4(void);
extern void *fn_80008E84();
extern u32 fn_1_45D0(void *arg0, void *arg1, u32 *arg2, int arg3);
extern void fn_80063094(s32 arg0, void *arg1, s32 arg2);
extern void fn_80065D70(int);

/* fzgx:begin fn_1_9FE74 */
// Initialize the sound resource and register it with the sound system.
u32 fn_1_9FE74(void *arg) {
    u32 result;

    fn_1_44A4();
    lbl_1_bss_6EA9C = (u32)fn_80008E84();
    result = fn_1_45D0(lbl_801A6410, arg, &lbl_1_data_33F1C, 0x94);
    fn_80008E84((void *)lbl_1_bss_6EA9C);
    return result;
}
/* fzgx:end fn_1_9FE74 */

/* fzgx:begin fn_1_9FEE8 */
// Initialize the sound resource and register it with the sound manager.
void fn_1_9FEE8(void *arg) {
    fn_1_44A4();
    lbl_1_bss_6EA9C = (u32)fn_80008E84();
    fn_1_46B4((u32)lbl_801A6410, arg, &lbl_1_data_33F1C, 0x9c);
    fn_80008E84((void *)lbl_1_bss_6EA9C);
}
/* fzgx:end fn_1_9FEE8 */

/* fzgx:begin fn_1_9FF50 */
// fn_1_9FF50: empty in retail (single blr).
void fn_1_9FF50(void) {
}
/* fzgx:end fn_1_9FF50 */

/* fzgx:begin fn_1_9FF54 */
// fn_1_9FF54: empty in retail (single blr).
void fn_1_9FF54(void) {
}
/* fzgx:end fn_1_9FF54 */

/* fzgx:begin fn_1_9FF58 */
void fn_1_9FF58(void) {
    if (lbl_1_bss_6EAA6) {
        fn_80067974();
        fn_800280F0();
        fn_80026FE0();
    }
    lbl_1_bss_6EAA4 = 0;
}
/* fzgx:end fn_1_9FF58 */

/* fzgx:begin fn_1_9FF9C */
void fn_1_9FF9C(void) {
    ARInit(lbl_1_bss_6EAA8, 2);
    fn_80020530();
    lbl_1_bss_6EAB0 = 0;
}
/* fzgx:end fn_1_9FF9C */

/* fzgx:begin fn_1_9FFD8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

struct fn_1_9FFD8_lbl_1_bss_6EA98 {
    u32 unk_0;
    u8 pad_4[0x9];
    u8 unk_D;
    u8 unk_E;
    u8 pad_F[0x9];
    u8 unk_18;
    u8 pad_19[0x3];
    u32 unk_1C;
    u16 unk_20;
    u8 pad_22[0x2];
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 pad_2F[0x1];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
};
struct fn_1_9FFD8_lbl_801A6410 {
    u32 unk_0;
};

extern const f32 lbl_1_rodata_42E0;
extern void *lbl_801A6410;
extern u32 lbl_1_data_33F1C;
extern u32 OSGetSoundMode(void);
extern u32 fn_1_44A4(void);
extern u32 fn_8001E954(u32);
extern u32 fn_80020778(void);
extern u32 fn_80025E18(void);
extern u32 fn_8004CD70(u32, u32, u32);
extern u32 fn_8004E59C(u32);
extern u32 fn_8004EC34(u32);
extern u32 fn_80068BFC(u32, u32, u32, u32, u32);
extern u32 fn_1_45D0(void *arg0, u32 arg1, u32 *arg2, int arg3);
extern void AIInit(u8 *arg0);
extern void fn_1_4438(void);
extern void fn_1_9FE74(void);
extern void fn_1_9FEE8(void);
extern void fn_1_9FF50(void);
extern void fn_1_9FF54(void);
extern void fn_1_9FF58(void);
extern void fn_1_A04AC(void);
extern void fn_1_A2E24(u32, u32, s32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80020724(void);
extern void fn_80022014(u32);
extern void fn_8002361C(u32, u32);
extern void fn_80025D50(u32, u32);
extern void fn_8002805C(void);
extern void fn_800411F4(void);
extern void fn_8004B7D4(u32);
extern void fn_8004BBA4(u32, u32);
extern void fn_80065890(u32);
extern void fn_8006589C(u32);
extern void fn_800658A8(u32);

#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u16 lbl_1_bss_6EAB4__fzgx_offset_4;
u16 lbl_1_bss_6EAB4__fzgx_offset_6;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0__fzgx_offset_4;
u8 lbl_1_bss_6EAD0__fzgx_offset_8;
u8 lbl_1_bss_6EAD0__fzgx_offset_9;
u16 lbl_1_bss_6EAD0__fzgx_offset_A;
u32 lbl_1_bss_6EAD0__fzgx_offset_C[447];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_9;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_C;
}
#pragma section code_type ".text"

void fn_1_9FFD8(void) {
    u32 fzgx_value;
    f32 f0;
    u32 v0;
    u32 v1;
    int lab_t1;
    u32 t11;
    u32 t12;
    u32 t17;
    u32 t19;
    u32 t21;
    u32 t22;
    u32 t23;
    
    AIInit(0);
    fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5 = 0;
    lbl_1_bss_6EAA6 = 0;
    fn_80025D50((u32)fn_1_9FE74, (u32)fn_1_9FEE8);
    fn_80020778();
    fn_8002805C();
    fn_80025E18();
    fn_80022014((u32)fn_1_9FF58);
    fn_8004EC34(0);
    fn_8004E59C(0);
    fn_800411F4();
    fn_8004BBA4((u32)fn_1_9FF50, 0);
    fzgx_value = 0;
    fzgx_obj_lbl_1_bss_6EAB4 = fzgx_value;
    lbl_1_bss_6EAB4__fzgx_offset_4 = 0;
    fzgx_obj_lbl_1_bss_6EAB4 = 0;
    lbl_1_bss_6EAB4__fzgx_offset_4 = 0;
    f0 = lbl_1_rodata_42E0;
    lbl_1_bss_6EAB4__fzgx_offset_8 = f0;
    lbl_1_bss_6EAB4__fzgx_offset_C = f0;
    lbl_1_bss_6EAB4__fzgx_offset_10 = 0xff;
    lbl_1_bss_6EAB4__fzgx_offset_11 = 0;
    fzgx_obj_lbl_1_bss_6EAC6 = 0;
    fn_1_4438();
    t11 = fn_1_45D0(lbl_801A6410, 0x28000, &lbl_1_data_33F1C, 0xf4);
    lbl_1_bss_6EAC6__fzgx_offset_2 = t11;
    t12 = fn_8001E954(0x6be000);
    lbl_1_bss_6EAC6__fzgx_offset_6 = t12;
    lab_t1 = 0;
    fn_80008BEC((void *)lbl_1_bss_6EAC6__fzgx_offset_2, lab_t1, 0x28000);
    fn_80068BFC(1, 0x28000, 0x6be000, lbl_1_bss_6EAC6__fzgx_offset_2, lbl_1_bss_6EAC6__fzgx_offset_6);
    fn_800658A8((u32)fn_1_A04AC);
    fn_8006589C((u32)fn_1_9FF54);
    t17 = fn_1_44A4();
    fn_80065890(t17);
    t19 = fn_1_45D0(lbl_801A6410, 0x974a0, &lbl_1_data_33F1C, 0x10b);
    fzgx_obj_lbl_1_bss_6EAD0 = t19;
    lab_t1 = 0;
    fn_80008BEC((void *)t19, lab_t1, 0x974a0);
    t21 = fn_8004CD70(2, (fzgx_obj_lbl_1_bss_6EAD0 + 16), 0x4a248);
    v0 = fzgx_obj_lbl_1_bss_6EAD0;
    *(u32 *)((u8 *)v0 + 0) = t21;
    t22 = fn_8004CD70(2, ((fzgx_obj_lbl_1_bss_6EAD0 + 0x50000) - 0x5da8), 0x4a248);
    v1 = fzgx_obj_lbl_1_bss_6EAD0;
    *(u32 *)((u8 *)v1 + 4) = t22;
    *(u32 *)((u8 *)fzgx_obj_lbl_1_bss_6EAD0 + 8) = 0;
    *(u32 *)((u8 *)fzgx_obj_lbl_1_bss_6EAD0 + 12) = 0;
    t23 = OSGetSoundMode();
    if (t23 == 0) {
        fn_1_A2E24(0, 0xa0000900, 0);
        fn_8004B7D4(1);
    } else {
        fn_1_A2E24(0, 0xa0000800, 0);
    }
    fn_80020724();
    fn_8002361C((u32)((u8 *)&lbl_1_bss_6EAD0__fzgx_offset_8), 32);
    fzgx_obj_lbl_1_bss_6EA98 = 0;
    lbl_1_bss_6EAB0 = 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9FFD8 */

/* fzgx:begin fn_1_A0214 pool */
typedef struct SoundEntry {
    u32 unk_0;
    u8 pad_4[0x2C];
    u32 unk_30;
    u32 unk_34;
} SoundEntry;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EAA4__fzgx_offset_1;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u8 fzgx_obj_lbl_1_bss_6EAB4[18];
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b1;
u8 fzgx_obj_lbl_1_bss_6EAC6__b2;
u8 fzgx_obj_lbl_1_bss_6EAC6__b3;
u8 fzgx_obj_lbl_1_bss_6EAC6__b4;
u8 fzgx_obj_lbl_1_bss_6EAC6__b5;
u8 fzgx_obj_lbl_1_bss_6EAC6__b6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b7;
u8 fzgx_obj_lbl_1_bss_6EAC6__b8;
u8 fzgx_obj_lbl_1_bss_6EAC6__b9;
u32 fzgx_obj_lbl_1_bss_6EAD0[2];
SoundEntry lbl_1_bss_6EAD0__fzgx_offset_8[32];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6EA98;
    s = fzgx_obj_lbl_1_bss_6EA9C[0];
    s = fzgx_obj_lbl_1_bss_6EAA4;
    s = lbl_1_bss_6EAA4__fzgx_offset_1;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b1;
    s = fzgx_obj_lbl_1_bss_6EAC6__b2;
    s = fzgx_obj_lbl_1_bss_6EAC6__b3;
    s = fzgx_obj_lbl_1_bss_6EAC6__b4;
    s = fzgx_obj_lbl_1_bss_6EAC6__b5;
    s = fzgx_obj_lbl_1_bss_6EAC6__b6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b7;
    s = fzgx_obj_lbl_1_bss_6EAC6__b8;
    s = fzgx_obj_lbl_1_bss_6EAC6__b9;
    s = fzgx_obj_lbl_1_bss_6EAD0[0];
    s = lbl_1_bss_6EAD0__fzgx_offset_8[0].unk_0;
    s = fzgx_obj_lbl_1_bss_6F1D8;
    s = fzgx_obj_lbl_1_bss_6F1DC;
}
#pragma section code_type ".text"

extern u32 fn_1_A266C(void);
extern u32 fn_1_3F1AC(u32);
extern void fn_8004EBF4(void);
extern u32 fn_80023638(void);

void fn_1_A0214(void) {
    u32 i;
    u32 count;

    if (lbl_1_bss_6EAA4__fzgx_offset_1 == 0) {
        fzgx_obj_lbl_1_bss_6F1D8 = fn_1_3F1AC(fn_1_A266C()) != 0;
        if (fzgx_obj_lbl_1_bss_6EAD0[0] != 0) {
            fn_8004EBF4();
            count = fn_80023638();
            for (i = 0; i < count; i++) {
                fzgx_obj_lbl_1_bss_6F1DC = lbl_1_bss_6EAD0__fzgx_offset_8[i].unk_30;
            }
        }
    }
}
/* fzgx:end fn_1_A0214 */

/* fzgx:begin fn_1_A04AC */
void fn_1_A04AC(void) {
    lbl_1_bss_6F1E0 = 1;
    lbl_1_bss_6F1E1 = 1;
}
/* fzgx:end fn_1_A04AC */

/* fzgx:begin fn_1_A04C4 noprologue */
#include "types.h"

struct fn_1_A04C4_lbl_1_bss_6EA98 {
    u8 pad_0[0xD];
    u8 unk_D;
    u8 unk_E;
    u8 pad_F[0x9];
    u8 unk_18;
    u8 pad_19[0x3];
    u32 unk_1C;
    u16 unk_20;
    u8 pad_22[0x2];
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 pad_2E[0x2];
    u32 unk_30;
    u8 pad_34[0x4];
    u32 unk_38;
};

extern f32 lbl_1_rodata_42E0;
extern struct fn_1_A04C4_lbl_1_bss_6EA98 lbl_1_bss_6EA98;
extern u32 OSGetSoundMode(void);
extern u32 fn_1_44A4(void);
extern u32 fn_1_A2E24(u32, u32, u32);
extern u32 fn_80008BEC(u32, u32, u32);
extern u32 fn_80022014(u32);
extern u32 fn_80025D50(u32, u32);
extern u32 fn_8004B7D4(u32);
extern u32 fn_8004BBA4(u32, u32);
extern u32 ADXT_Stop(u32);
extern u32 fn_8004CAC8(u32);
extern u32 fn_8004CD70(u32, u32, u32);
extern u32 fn_8004E59C(u32);
extern u32 fn_8004EC34(u32);
extern u32 fn_80065890(void);
extern u32 fn_8006589C(u32);
extern u32 fn_800658A8(u32);
extern void fn_1_9FE74(void);
extern void fn_1_9FEE8(void);
extern void fn_1_9FF50(void);
extern void fn_1_9FF54(void);
extern void fn_1_9FF58(void);
extern void fn_1_A04AC(void);

void fn_1_A04C4(void) {
    struct fn_1_A04C4_lbl_1_bss_6EA98 *p_lbl_1_bss_6EA98;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 t1, t2, t15, t16, t17, t18, t19, t20;
    p_lbl_1_bss_6EA98 = (struct fn_1_A04C4_lbl_1_bss_6EA98 *)&lbl_1_bss_6EA98;
    p_lbl_1_bss_6EA98->unk_E = 0;
    fn_80025D50((u32)fn_1_9FE74, (u32)fn_1_9FEE8);
    t1 = fn_80022014((u32)fn_1_9FF58);
    t2 = fn_8004EC34(0);
    fn_8004E59C(0);
    fn_8004BBA4((u32)fn_1_9FF50, 0);
    p_lbl_1_bss_6EA98->unk_1C = 0;
    p_lbl_1_bss_6EA98->unk_20 = 0;
    p_lbl_1_bss_6EA98->unk_24 = lbl_1_rodata_42E0;
    p_lbl_1_bss_6EA98->unk_28 = lbl_1_rodata_42E0;
    p_lbl_1_bss_6EA98->unk_2C = 255;
    p_lbl_1_bss_6EA98->unk_2D = 0;
    fn_80008BEC((p_lbl_1_bss_6EA98->unk_30), 0, (0x30000 + -32768));
    fn_800658A8((u32)fn_1_A04AC);
    fn_8006589C((u32)fn_1_9FF54);
    fn_1_44A4();
    fn_80065890();
    ADXT_Stop(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 0));
    fn_8004CAC8(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 0));
    ADXT_Stop(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 4));
    fn_8004CAC8(*(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 4));
    fn_80008BEC(p_lbl_1_bss_6EA98->unk_38, 0, (0x90000 + 29856));
    t15 = fn_8004CD70(2, (p_lbl_1_bss_6EA98->unk_38 + 16), (0x50000 - 23992));
    v1 = p_lbl_1_bss_6EA98->unk_38;
    *(u32 *)((u8 *)v1 + 0) = t15;
    t16 = fn_8004CD70(2, ((p_lbl_1_bss_6EA98->unk_38 + 0x50000) - 23976), (0x50000 - 23992));
    v2 = p_lbl_1_bss_6EA98->unk_38;
    *(u32 *)((u8 *)v2 + 4) = t16;
    *(u32 *)((u8 *)p_lbl_1_bss_6EA98->unk_38 + 8) = 0;
    v3 = p_lbl_1_bss_6EA98->unk_38;
    *(u32 *)((u8 *)v3 + 12) = 0;
    t17 = OSGetSoundMode();
    v4 = t17;
    if (t17 == 0) {
    v4 = 0;
    t18 = fn_1_A2E24(v4, (0xA0000000 + 2304), 0);
    v4 = t18;
    v4 = 1;
    t19 = fn_8004B7D4(v4);
    v4 = t19;
    } else {
    v4 = 0;
    t20 = fn_1_A2E24(v4, (0xA0000000 + 2048), 0);
    v4 = t20;
    }
    p_lbl_1_bss_6EA98->unk_18 = 1;
    p_lbl_1_bss_6EA98->unk_D = 0;
}
/* fzgx:end fn_1_A04C4 */

/* fzgx:begin fn_1_A0978 pool */
typedef struct SoundEntry {
    u32 unk_0;
    u8 pad_4[0x2C];
    u32 unk_30;
    u32 unk_34;
} SoundEntry;

typedef struct SoundSlot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x11];
} SoundSlot;

typedef struct SoundPair {
    s8 a;
    s8 b;
} SoundPair;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C;
u32 lbl_1_bss_6EA9C__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EAA4__fzgx_offset_1;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b1;
u8 fzgx_obj_lbl_1_bss_6EAC6__b2;
u8 fzgx_obj_lbl_1_bss_6EAC6__b3;
u8 fzgx_obj_lbl_1_bss_6EAC6__b4;
u8 fzgx_obj_lbl_1_bss_6EAC6__b5;
u8 fzgx_obj_lbl_1_bss_6EAC6__b6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b7;
u8 fzgx_obj_lbl_1_bss_6EAC6__b8;
u8 fzgx_obj_lbl_1_bss_6EAC6__b9;
u32 fzgx_obj_lbl_1_bss_6EAD0[2];
SoundEntry lbl_1_bss_6EAD0__fzgx_offset_8[32];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
SoundSlot fzgx_obj_lbl_1_bss_6F1E4[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_50[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_54;
u8 fzgx_obj_lbl_1_bss_6F239;
u32 fzgx_obj_lbl_1_bss_6F23C;
u8 lbl_1_bss_6F23C__fzgx_offset_4;
u8 lbl_1_bss_6F23C__fzgx_offset_5;
u8 lbl_1_bss_6F23C__fzgx_offset_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244;
u8 lbl_1_bss_6F244__fzgx_offset_1;
u8 lbl_1_bss_6F244__fzgx_offset_1__b1;
u8 lbl_1_bss_6F244__fzgx_offset_1__b2;
u8 lbl_1_bss_6F244__fzgx_offset_4[4];
SoundPair lbl_1_bss_6F244__fzgx_offset_8[30];
SoundPair lbl_1_bss_6F244__fzgx_offset_44[30];
s8 fzgx_obj_lbl_1_bss_6F2C4;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6EA98;
    s = fzgx_obj_lbl_1_bss_6EA9C;
    s = lbl_1_bss_6EA9C__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_6EAA4;
    s = lbl_1_bss_6EAA4__fzgx_offset_1;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = lbl_1_bss_6EAB4__fzgx_offset_10;
    s = lbl_1_bss_6EAB4__fzgx_offset_11;
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b1;
    s = fzgx_obj_lbl_1_bss_6EAC6__b2;
    s = fzgx_obj_lbl_1_bss_6EAC6__b3;
    s = fzgx_obj_lbl_1_bss_6EAC6__b4;
    s = fzgx_obj_lbl_1_bss_6EAC6__b5;
    s = fzgx_obj_lbl_1_bss_6EAC6__b6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b7;
    s = fzgx_obj_lbl_1_bss_6EAC6__b8;
    s = fzgx_obj_lbl_1_bss_6EAC6__b9;
    s = fzgx_obj_lbl_1_bss_6EAD0[0];
    s = lbl_1_bss_6EAD0__fzgx_offset_8[0].unk_0;
    s = fzgx_obj_lbl_1_bss_6F1D8;
    s = fzgx_obj_lbl_1_bss_6F1DC;
    s = fzgx_obj_lbl_1_bss_6F1E0;
    s = fzgx_obj_lbl_1_bss_6F1E1;
    s = fzgx_obj_lbl_1_bss_6F1E4[0].unk_0;
    s = lbl_1_bss_6F1E4__fzgx_offset_50[0];
    s = lbl_1_bss_6F1E4__fzgx_offset_54;
    s = fzgx_obj_lbl_1_bss_6F239;
    s = fzgx_obj_lbl_1_bss_6F23C;
    s = lbl_1_bss_6F23C__fzgx_offset_4;
    s = lbl_1_bss_6F23C__fzgx_offset_5;
    s = lbl_1_bss_6F23C__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_6F243;
    s = fzgx_obj_lbl_1_bss_6F244;
    s = lbl_1_bss_6F244__fzgx_offset_1;
    s = lbl_1_bss_6F244__fzgx_offset_1__b1;
    s = lbl_1_bss_6F244__fzgx_offset_1__b2;
    s = lbl_1_bss_6F244__fzgx_offset_4[0];
    s = lbl_1_bss_6F244__fzgx_offset_8[0].a;
    s = lbl_1_bss_6F244__fzgx_offset_44[0].a;
    s = fzgx_obj_lbl_1_bss_6F2C4;
}
#pragma section code_type ".text"

extern s32 fn_1_3F864(void);
extern void fn_1_A3A1C(void);
extern void fn_1_A31E4(void);
extern u32 fn_1_864E8(u8);
extern void fn_1_A54FC(void);
extern void fn_1_A5590(void);
extern void fn_1_A24CC(void);

void fn_1_A0978(void) {
    SoundSlot *slot;
    s32 i;
    s32 id;
    u32 flags;

    if (fn_1_3F864() == 0 || lbl_1_bss_6EAA4__fzgx_offset_1 != 0) {
        return;
    }
    fn_1_A3A1C();
    fn_1_A31E4();
    slot = fzgx_obj_lbl_1_bss_6F1E4;
    for (i = 0; i < fzgx_obj_lbl_1_bss_6F2C4; slot++, i++) {
        id = slot->unk_1;
        flags = fn_1_864E8(id);
        if (!(flags & 0x800000)) {
            s8 *count;
            SoundPair *pair;
            pair = &lbl_1_bss_6F244__fzgx_offset_8[id];
            count = &pair->b;
            (*count)++;
            if (*count > 10) {
                pair->a = 0;
                *count = 10;
            }
        }
        if (!(flags & 0x2000000)) {
            s8 *count;
            SoundPair *pair;
            pair = &lbl_1_bss_6F244__fzgx_offset_44[id];
            count = &pair->b;
            (*count)++;
            if (*count > 30) {
                pair->a = 0;
                *count = 30;
            }
        }
    }
    fn_1_A54FC();
    fn_1_A5590();
    fn_1_A24CC();
}
/* fzgx:end fn_1_A0978 */

/* fzgx:begin fn_1_A0C68 */
enum {
    ADDR_A6000000 = 0xA6000000,
    ADDR_A5100000 = 0xA5100000,
    ADDR_A0000300 = 0xA0000300,
    ADDR_A0000400 = 0xA0000400
};

typedef struct fn_1_A0C68_SoundState {
    u8 pad_2e[0x2e];
    u8 unk_2e;
    u8 pad_74c[0x74c - 0x2f];
    u8 unk_74c[0x50];
    u8 pad_7ac[0x7ac - 0x79c];
    u8 unk_7ac;
} fn_1_A0C68_SoundState;

// Initialize the sound resources once the sound system is enabled.
void fn_1_A0C68(void) {
    fn_1_A0C68_SoundState *state;
    s32 i;

    state = (fn_1_A0C68_SoundState *)&lbl_1_bss_6EA98;
    if (state->unk_2e != 0) {
        fn_1_A2DF4(0x10, (void *)ADDR_A6000000, 0);
        fn_1_A2DF4(0x10, (void *)ADDR_A5100000, 0);

        for (i = 1; i < 4; i++) {
            fn_1_A2E24(i, ADDR_A0000300, 0);
        }

        fn_1_A2E24(0x10, ADDR_A0000400, 0);
        fn_80008BEC(&state->unk_74c, 0, 0x50);
        state->unk_7ac = 0;
    }
}
/* fzgx:end fn_1_A0C68 */

/* fzgx:begin fn_1_A116C */
#include "types.h"

extern s16 lbl_1_bss_962;

void fn_1_A116C(void) {
    switch ((*(s16 *)&lbl_1_bss_960)) {
    case 2:
    case 8:
    case 9:
    case 12:
        fn_80065D70(1);
        break;
    case 1:
    case 5:
    case 13:
        fn_80065D70(2);
        break;
    case 4:
        if (lbl_1_bss_962 != 0x3D) {
            fn_80065D70(3);
        }
        break;
    case 14:
    case 16:
        fn_80065D70(3);
        break;
    }
}
/* fzgx:end fn_1_A116C */

/* fzgx:begin fn_1_A11EC pool noprologue */
#include "types.h"

typedef struct SoundEntry {
    u32 unk_0;
    u8 pad_4[0x2C];
    u32 unk_30;
    u32 unk_34;
} SoundEntry;

typedef struct SoundSlot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x11];
} SoundSlot;

typedef struct SoundPair {
    s8 a;
    s8 b;
} SoundPair;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C;
u32 lbl_1_bss_6EA9C__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EAA4__fzgx_offset_1;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b1;
u8 fzgx_obj_lbl_1_bss_6EAC6__b2;
u8 fzgx_obj_lbl_1_bss_6EAC6__b3;
u8 fzgx_obj_lbl_1_bss_6EAC6__b4;
u8 fzgx_obj_lbl_1_bss_6EAC6__b5;
u8 fzgx_obj_lbl_1_bss_6EAC6__b6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b7;
u8 fzgx_obj_lbl_1_bss_6EAC6__b8;
u8 fzgx_obj_lbl_1_bss_6EAC6__b9;
u32 fzgx_obj_lbl_1_bss_6EAD0[2];
SoundEntry lbl_1_bss_6EAD0__fzgx_offset_8[32];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
SoundSlot fzgx_obj_lbl_1_bss_6F1E4[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_50[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_54;
u8 fzgx_obj_lbl_1_bss_6F239;
u32 fzgx_obj_lbl_1_bss_6F23C;
u8 lbl_1_bss_6F23C__fzgx_offset_4;
u8 lbl_1_bss_6F23C__fzgx_offset_5;
u8 lbl_1_bss_6F23C__fzgx_offset_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244;
u8 lbl_1_bss_6F244__fzgx_offset_1;
u8 lbl_1_bss_6F244__fzgx_offset_1__b1;
u8 lbl_1_bss_6F244__fzgx_offset_1__b2;
u8 lbl_1_bss_6F244__fzgx_offset_4[4];
SoundPair lbl_1_bss_6F244__fzgx_offset_8[30];
SoundPair lbl_1_bss_6F244__fzgx_offset_44[30];
s8 fzgx_obj_lbl_1_bss_6F2C4;
u32 fzgx_obj_lbl_1_bss_6F2C8[4];
u32 fzgx_obj_lbl_1_bss_6F2D8[15];
u8 lbl_1_bss_6F2D8__fzgx_offset_3C;
u8 lbl_1_bss_6F2D8__fzgx_offset_3D;
u8 fzgx_obj_lbl_1_bss_6F316;
u8 fzgx_obj_lbl_1_bss_6F317;
s16 lbl_1_bss_6F316__fzgx_offset_2;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6EA98;
    s = fzgx_obj_lbl_1_bss_6EA9C;
    s = lbl_1_bss_6EA9C__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_6EAA4;
    s = lbl_1_bss_6EAA4__fzgx_offset_1;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = lbl_1_bss_6EAB4__fzgx_offset_10;
    s = lbl_1_bss_6EAB4__fzgx_offset_11;
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b1;
    s = fzgx_obj_lbl_1_bss_6EAC6__b2;
    s = fzgx_obj_lbl_1_bss_6EAC6__b3;
    s = fzgx_obj_lbl_1_bss_6EAC6__b4;
    s = fzgx_obj_lbl_1_bss_6EAC6__b5;
    s = fzgx_obj_lbl_1_bss_6EAC6__b6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b7;
    s = fzgx_obj_lbl_1_bss_6EAC6__b8;
    s = fzgx_obj_lbl_1_bss_6EAC6__b9;
    s = fzgx_obj_lbl_1_bss_6EAD0[0];
    s = lbl_1_bss_6EAD0__fzgx_offset_8[0].unk_0;
    s = fzgx_obj_lbl_1_bss_6F1D8;
    s = fzgx_obj_lbl_1_bss_6F1DC;
    s = fzgx_obj_lbl_1_bss_6F1E0;
    s = fzgx_obj_lbl_1_bss_6F1E1;
    s = fzgx_obj_lbl_1_bss_6F1E4[0].unk_0;
    s = lbl_1_bss_6F1E4__fzgx_offset_50[0];
    s = lbl_1_bss_6F1E4__fzgx_offset_54;
    s = fzgx_obj_lbl_1_bss_6F239;
    s = fzgx_obj_lbl_1_bss_6F23C;
    s = lbl_1_bss_6F23C__fzgx_offset_4;
    s = lbl_1_bss_6F23C__fzgx_offset_5;
    s = lbl_1_bss_6F23C__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_6F243;
    s = fzgx_obj_lbl_1_bss_6F244;
    s = lbl_1_bss_6F244__fzgx_offset_1;
    s = lbl_1_bss_6F244__fzgx_offset_1__b1;
    s = lbl_1_bss_6F244__fzgx_offset_1__b2;
    s = lbl_1_bss_6F244__fzgx_offset_4[0];
    s = lbl_1_bss_6F244__fzgx_offset_8[0].a;
    s = lbl_1_bss_6F244__fzgx_offset_44[0].a;
    s = fzgx_obj_lbl_1_bss_6F2C4;
    s = fzgx_obj_lbl_1_bss_6F2C8[0];
    s = fzgx_obj_lbl_1_bss_6F2D8[0];
    s = lbl_1_bss_6F2D8__fzgx_offset_3C;
    s = lbl_1_bss_6F2D8__fzgx_offset_3D;
    s = fzgx_obj_lbl_1_bss_6F316;
    s = fzgx_obj_lbl_1_bss_6F317;
    s = lbl_1_bss_6F316__fzgx_offset_2;
}
#pragma section code_type ".text"

extern void fn_80008BEC(void *, s32, u32);
extern void fn_1_A2E24(u32, u32, u32);
extern void fn_1_A2DF4(u32, u32, u32);

void fn_1_A11EC(void) {
    s32 i;

    if (lbl_1_bss_6EAA4__fzgx_offset_1 != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        fzgx_obj_lbl_1_bss_6F1E4[i].unk_2 = 0;
    }
    fn_80008BEC(fzgx_obj_lbl_1_bss_6F2D8, 0, sizeof(fzgx_obj_lbl_1_bss_6F2D8));
    fn_80008BEC(fzgx_obj_lbl_1_bss_6F1E4, 0, sizeof(fzgx_obj_lbl_1_bss_6F1E4));
    for (i = 0; i < 4; i++) {
        fzgx_obj_lbl_1_bss_6F1E4[i].unk_1 = 0xFF;
        fzgx_obj_lbl_1_bss_6F1E4[i].unk_2 = 0;
    }
    fzgx_obj_lbl_1_bss_6EAB4[0] = 0;
    lbl_1_bss_6F2D8__fzgx_offset_3C = 0;
    lbl_1_bss_6F2D8__fzgx_offset_3D = 0;
    fzgx_obj_lbl_1_bss_6F316 = 1;
    fzgx_obj_lbl_1_bss_6F317 = 1;
    fzgx_obj_lbl_1_bss_6F239 = 0;
    fzgx_obj_lbl_1_bss_6F23C = 0;
    lbl_1_bss_6F316__fzgx_offset_2 = 0;
    lbl_1_bss_6F23C__fzgx_offset_4 = 0;
    lbl_1_bss_6F23C__fzgx_offset_5 = 0;
    lbl_1_bss_6F23C__fzgx_offset_6 = 0;
    fzgx_obj_lbl_1_bss_6F243 = 0;
    fzgx_obj_lbl_1_bss_6F244 = 1;
    fn_1_A2E24(0x10, 0xA0000300, 0);
    fn_1_A2DF4(6, 0xA6000000, 0);
    fn_1_A2DF4(7, 0xA6000000, 0);
    fn_1_A2DF4(5, 0xA6000000, 0);
    fn_1_A2DF4(4, 0xA6000000, 0);
    fn_1_A2E24(0x10, 0xA0100000, 0x7F);
    for (i = 0; i < 4; i++) {
        lbl_1_bss_6F244__fzgx_offset_4[i] = 9;
    }
}
/* fzgx:end fn_1_A11EC */

/* fzgx:begin fn_1_A1340 */
void fn_1_A1340(void) {
    fn_1_A0680();
}
/* fzgx:end fn_1_A1340 */

/* fzgx:begin fn_1_A1360 */
// fn_1_A1360: empty in retail (single blr).
void fn_1_A1360(void) {
}
/* fzgx:end fn_1_A1360 */

/* fzgx:begin fn_1_A2A70 pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x43300000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table2[1] = {0x80000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_1_A2A70_lbl_1_bss_6EA98 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[0x4];
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[0xC];
    void **unk_38;
    u8 pad_3C[0x774];
    u8 unk_7B0[4];
    u8 pad_7B4[0xD4];
    f32 unk_888;
    f32 unk_88C;
};
extern const f64 lbl_1_rodata_42F0;
extern const f32 lbl_1_rodata_446C;
extern const f32 lbl_1_rodata_4470;
extern const f32 lbl_1_rodata_4474;
extern s32 fn_800672E4(u32, s32);
extern u32 fn_8004BED0(void *);

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 lbl_1_bss_6EA98_gap_6EAB1;
u16 lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4_fill_6EAB8;
f32 lbl_1_bss_6EAB4_8;
f32 lbl_1_bss_6EAB4_C;
u16 lbl_1_bss_6EAB4_fill_6EAC4;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
void **fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0_fill_6EAD4[449];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6EA98_gap_6F1D9;
u16 lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 lbl_1_bss_6EA98_gap_6F1E2;
u32 fzgx_obj_lbl_1_bss_6F1E4[21];
u8 lbl_1_bss_6F1E4_fill_6F238;
u8 lbl_1_bss_6F239;
u16 lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C_fill_6F240;
u8 lbl_1_bss_6F23C_fill_6F242;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244_fill_6F244;
u8 lbl_1_bss_6F244_4[4];
u32 lbl_1_bss_6F244_fill_6F24C[30];
u8 lbl_1_bss_6F2C4;
u8 lbl_1_bss_6EA98_gap_6F2C5;
u16 lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u32 lbl_1_bss_6F2D8[15];
u16 lbl_1_bss_6F2D8_fill_6F314;
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 lbl_1_bss_6EA98_gap_6F318;
u16 lbl_1_bss_6F31A_fill_6F31A;
u32 lbl_1_bss_6F31A_fill_6F31C;
f32 lbl_1_bss_6F31A_6;
f32 lbl_1_bss_6F31A_A;
u32 lbl_1_bss_6F31A_fill_6F328[31];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAB8;
    s = *(u8 *)&lbl_1_bss_6EAB4_8;
    s = *(u8 *)&lbl_1_bss_6EAB4_C;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAC4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6_fill_6EAC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0_fill_6EAD4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F238;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F240;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F242;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244_fill_6F244;
    s = *(u8 *)&lbl_1_bss_6F244_4;
    s = *(u8 *)&lbl_1_bss_6F244_fill_6F24C;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F2C5;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F2D8_fill_6F314;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6F318;
    s = *(u8 *)&lbl_1_bss_6F31A_fill_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A_fill_6F31C;
    s = *(u8 *)&lbl_1_bss_6F31A_6;
    s = *(u8 *)&lbl_1_bss_6F31A_A;
    s = *(u8 *)&lbl_1_bss_6F31A_fill_6F328;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
void fn_1_A2A70(u32 arg0, s32 arg1) {
    s32 v0_2;
    f32 v1;
    s32 v0;
    volatile s32 loc_8;  /* fzgx-allow: S2 retail round-trips the float through a stack slot */
    u8 *v11;
    s32 i;
    
    if (arg1 > 0) {
        if (arg0 & 1) {
            fzgx_obj_lbl_1_bss_6EAB4 &= ~4;
            lbl_1_bss_6EAB4_8 = lbl_1_rodata_446C / (f32)arg1;
        }
        if (arg0 & 2) {
            fzgx_obj_lbl_1_bss_6EAB4 &= ~8;
            lbl_1_bss_6EAB4_C = lbl_1_rodata_446C / (f32)arg1;
        }
        if (arg0 & 4) {
            lbl_1_bss_6F31A_6 = (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[0]);
            v1 = lbl_1_rodata_446C + (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[0]);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~1;
            lbl_1_bss_6EAB4_8 = v1 / (f32)arg1;
        }
        if (arg0 & 8) {
            lbl_1_bss_6F31A_A = (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[1]);
            v1 = lbl_1_rodata_446C + (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[1]);
            lbl_1_bss_6EAB4_C = v1 / (f32)arg1;
            if (arg0 & 0x40) {
                v0 = (s32)(fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[1]) + 600) / arg1;
                loc_8 = (s32)(lbl_1_bss_6EAB4_C = (f32)v0);
                lbl_1_bss_6EAB4_C = (f32)loc_8;
                if (lbl_1_bss_6EAB4_C < lbl_1_rodata_4470) {
                    lbl_1_bss_6EAB4_C = lbl_1_rodata_4470;
                }
            }
            fzgx_obj_lbl_1_bss_6EAB4 &= ~2;
        }
        i = 0;
        v11 = lbl_1_bss_6F244_4;
        for (; i < 4; i++) {
            v0_2 = fn_800672E4(i, 0xA0100000) / arg1;
            if (v0_2 <= 0) v0_2 = 0;
            *v11++ = v0_2 + 1;
        }
        if (lbl_1_bss_6EAB4_8 < lbl_1_rodata_4474)
            lbl_1_bss_6EAB4_8 = lbl_1_rodata_4470;
        if (lbl_1_bss_6EAB4_C < lbl_1_rodata_4474)
            lbl_1_bss_6EAB4_C = lbl_1_rodata_4470;
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_A2A70 */

/* fzgx:begin fn_1_A2D84 */
void fn_1_A2D84(u32 arg0) {
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(arg0);
    }
}
/* fzgx:end fn_1_A2D84 */

/* fzgx:begin fn_1_A2DC4 */
void fn_1_A2DC4(u32 arg0) {
    if (lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(arg0);
    }
}
/* fzgx:end fn_1_A2DC4 */

/* fzgx:begin fn_1_A2DF4 */
// Forwards the sound event while sound processing is enabled.
void fn_1_A2DF4(s32 arg0, void *arg1, s32 arg2) {
    if (lbl_1_bss_6EAC6.unk_0 != 0) {
        fn_80063094(arg0, arg1, arg2);
    }
}
/* fzgx:end fn_1_A2DF4 */

/* fzgx:begin fn_1_A2E24 */
// Notifies the sound system when sound processing is enabled.
void fn_1_A2E24(u32 arg0, u32 arg1, s32 arg2) {
    if (lbl_1_bss_6EAC6.unk_0 != 0) {
        fn_800674FC(arg0, arg1, arg2);
    }
}
/* fzgx:end fn_1_A2E24 */

/* fzgx:begin fn_1_A2E5C noprologue */
#include "types.h"

typedef struct {
    u8 unk_0[0x740];
    u8 unk_740;
    u8 unk_741[3];
    u32 unk_744;
    u8 unk_748[4];
    u8 unk_74C[0xE0];
    u8 unk_82C;
} SoundState;

typedef struct {
    u8 unk_0[0x3A0];
    void *unk_3A0;
} SoundObject;

typedef struct {
    u8 unk_0[0x6C0];
    s16 unk_6C0;
} SoundData;

extern SoundState lbl_1_bss_6EA98;

extern s32 fn_1_3F864(void);
extern s8 fn_1_86690(s8 arg0);
extern SoundObject *fn_1_86854(s8 arg0);
extern void fn_1_14E9E4(s16 arg0, void *arg1);
extern void fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80067898(u32 arg0);

extern u32 lbl_1_rodata_451C[5];
extern u32 lbl_1_rodata_4478[41];

void fn_1_A2E5C(s32 arg0, s32 arg1) {
    SoundState *state = &lbl_1_bss_6EA98;
    s16 local[8];
    u8 *entry;
    s8 i;

    if (fn_1_3F864() != 0) {
        entry = &state->unk_74C[0];
        i = 0;
        while (i < (s8)state->unk_82C) {
            if (arg0 == entry[1] && entry[2] != 0) {
                fn_80067344(1, 0x10, 0xB0270000, entry[2]);
                if (arg1 != 0) {
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(0xA9090B00);
                    }
                } else if (fn_1_86690(arg0) > 0x28) {
                    SoundData *data;
                    u32 snd;
                    s16 half;
                    data = (SoundData *)fn_1_86854(fn_1_86690(arg0))->unk_3A0;
                    fn_1_14E9E4(data->unk_6C0, local);
                    half = (s16)(local[4] >> 1);
                    snd = lbl_1_rodata_451C[half];
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(snd);
                    }
                } else {
                    u32 snd = lbl_1_rodata_4478[fn_1_86690(arg0)];
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(snd);
                    }
                }
            }
            entry += 0x14;
            i++;
        }
    }
}
/* fzgx:end fn_1_A2E5C */

/* fzgx:begin fn_1_A2FC8 pool noprologue */
#include "types.h"
#include "rel/main_rel/sound.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3[0x11];
} SoundEntry;

typedef struct {
    s8 unk_0;
    s8 unk_1;
} CounterPair;

extern u32 fn_1_864E8(u32 arg0);
extern void fn_80067344(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
extern void fn_80067898(u32 arg0);

extern const f32 lbl_1_rodata_4530;
extern const f32 lbl_1_rodata_4474;
extern const f32 lbl_1_rodata_4470;
extern const f32 lbl_1_rodata_4534;
extern const f32 lbl_1_rodata_4538;
extern const f32 lbl_1_rodata_453C;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u16 lbl_1_bss_6EAB4__fzgx_offset_10;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2[2];
u32 fzgx_obj_lbl_1_bss_6EAD0[450];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
u8 fzgx_obj_lbl_1_bss_6F1E4;
u8 lbl_1_bss_6F1E4__fzgx_offset_1;
u16 lbl_1_bss_6F1E4__fzgx_offset_2;
u32 lbl_1_bss_6F1E4__fzgx_offset_4[20];
u8 lbl_1_bss_6F1E4__fzgx_offset_54;
u8 lbl_1_bss_6F239;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C__fzgx_offset_4;
u8 lbl_1_bss_6F23C__fzgx_offset_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244__fzgx_offset_0[2];
u16 lbl_1_bss_6F244__fzgx_offset_8;
u8 lbl_1_bss_6F244__fzgx_offset_A;
u16 lbl_1_bss_6F244__fzgx_offset_C;
u32 lbl_1_bss_6F244_fill_6F250[28];
s8 lbl_1_bss_6F2C4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_54;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F23C__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6F244_fill_6F250;
    s = *(u8 *)&lbl_1_bss_6F2C4;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
#pragma opt_common_subs off
void fn_1_A2FC8(s32 arg0, f32 arg1, u32 unused2, u32 unused3, u32 unused4) {
    
    s32 id = arg0;
    u8 snd;
    s32 i;
    s32 found = 0;
    s32 idx;
    struct { f32 value; } f0;
    struct { f32 value; } f1;

    for (i = 0; i < (s8)lbl_1_bss_6F2C4; i++) {
        if (id == (s32)((SoundEntry *)&fzgx_obj_lbl_1_bss_6F1E4)[i].unk_1) {
            idx = i;
            found = 1;
        }
    }
    if (found == 0) {
        return;
    }
    {
        u8 *tab = (u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
        s32 off = idx * 0x14;

        snd = tab[off + 2];
    }
    if (snd == 0) {
        /* fzgx-allow: S1 no sound assigned: join the shared counter-update tail */
        goto tail;
    }
    if (((CounterPair *)&lbl_1_bss_6F244__fzgx_offset_8)[id].unk_0 != 0) {
        /* fzgx-allow: S1 already counting: join the shared counter-update tail */
        goto tail;
    }
    if (fn_1_864E8(id) & 0x880) {
        return;
    }
    fn_80067344(1, 0x10, 0xB0270000, snd);

    f0.value = arg1 * lbl_1_rodata_4530;
    if (f0.value < lbl_1_rodata_4474) {
        f1.value = lbl_1_rodata_4474;
    } else if (f0.value > lbl_1_rodata_4470) {
        f1.value = lbl_1_rodata_4470;
    } else {
        f1.value = f0.value;
    }

    if (f1.value < lbl_1_rodata_4534) {
        if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9090000);
        }
    } else if (f1.value < lbl_1_rodata_4538) {
        if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9090200);
        }
    } else if (f1.value < lbl_1_rodata_453C) {
        if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9090500);
        }
    } else {
        if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9090600);
        }
    }

tail:
    /* fzgx-allow: S1 shared tail reached from three exits */
    {
        s32 k = id * 2;
        s8 *p = (s8 *)&lbl_1_bss_6F244__fzgx_offset_8;

        p[k] = (s8)((*((k) + (p))) + 1);
        p[k + 1] = 0;
        if (p[k] > 6) {
            p[k] = 0;
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset
/* fzgx:end fn_1_A2FC8 */

/* fzgx:begin fn_1_A31E4 noprologue */
#include "types.h"

extern const struct fn_1_A31E4_lbl_1_rodata_4540_pool {
    f32 unk_0;
} lbl_1_rodata_4540;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3[7];
    u8 unk_A;
    u8 unk_B[9];
} SoundEntry;

typedef struct {
    u8 unk_0[0x1C];
    u32 unk_1C;
    s8 unk_20[0x720];
    u8 unk_740;
    u8 unk_741[3];
    u32 unk_744;
    u8 unk_748[4];
    SoundEntry unk_74C[4];
    u8 unk_79C[0xC];
    s8 unk_7A8;
    s8 unk_7A9;
} SoundState;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
    u8 pad[5];
} BssA88;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
} BssCC0;

extern SoundState lbl_1_bss_6EA98;
extern BssA88 lbl_1_bss_A88[4];
extern BssCC0 lbl_1_bss_CC0[152];

extern s32 fn_1_3F864(void);
extern s32 fn_1_3F854(void);
extern u32 fn_1_864E8(s32 arg0);
extern u32 fn_1_86514(s32 arg0);
extern f32 fn_1_8652C(s32 arg0);
extern s16 fn_1_3F0C8(void);
extern void fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80067898(u32 arg0);

static inline SoundEntry * fn_1_A31E4_read_pointer(SoundState * owner) { return owner->unk_74C; }
#pragma opt_common_subs off
void fn_1_A31E4(void) {
    SoundState *state = &lbl_1_bss_6EA98;
    SoundEntry *tbl;
    s32 n;
    s32 count = 0;
    u8 count2;
    s32 id;
    u32 flags;
    f32 f;
    s32 i;
    count2 = 0;

    if (fn_1_3F864() != 0) {
        n = fn_1_3F854();
        tbl = fn_1_A31E4_read_pointer(state);
        for (i = 0; i < n; i++) {
            id = tbl[i].unk_1;
            flags = fn_1_864E8(id);
            if (id != 0xFF && !(flags & 0x280)) {
                if ((fn_1_86514(id) >> 27) & 1) {
                    if (!(state->unk_1C & 0x20)) {
                        fn_80067344(1, 7, 0xB0070000, tbl[i].unk_A);
                    }
                    count++;
                }
                if (lbl_1_bss_A88[i].b4) {
                    count2++;
                }
                f = fn_1_8652C(id);
                if (lbl_1_bss_CC0[i].b4 && f > lbl_1_rodata_4540.unk_0 && fn_1_3F0C8() != 0x28) {
                    fn_80067344(1, 0x10, 0xB0270000, tbl[i].unk_2);
                    if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                        fn_80067898(0xA9091500);
                    }
                }
            }
        }
        if (state->unk_7A8 < (u8)count) {
            if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                fn_80067898(0xA9090C00);
            }
        } else if (state->unk_7A8 > (u8)count && (u8)count == 0) {
            if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                fn_80067898(0xA9090D00);
            }
        }
        if (state->unk_7A9 > count2 && count2 == 0) {
            if (state->unk_740 == 0 && state->unk_744 <= 0x2D) {
                fn_80067898(0xA9091600);
            }
        }
        state->unk_7A8 = count;
        state->unk_7A9 = count2;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_A31E4 */

/* fzgx:begin fn_1_A33F0 noprologue */
#include "types.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
} CounterEntry;

typedef struct {
    u8 unk_0[0x740];
    u8 unk_740;
    u8 unk_741[3];
    u32 unk_744;
    u8 unk_748[4];
    u8 unk_74C[0xA4];
    CounterEntry unk_7F0[0x800];
} SoundState;

extern SoundState lbl_1_bss_6EA98;
extern s32 fn_1_3F864(void);
extern void fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80067898(u32 arg0);
extern const f32 lbl_1_rodata_4544;
extern const f32 lbl_1_rodata_4548;

#pragma opt_propagation off
void fn_1_A33F0(s32 arg0, f32 arg1) {
    SoundState *st = (SoundState *)&lbl_1_bss_6EA98;
    u8 *row;
    u8 *entry;
    u8 *counter_entry;
    s32 off;
    s8 i;
    s8 count;

    count = 0;
    if (fn_1_3F864() == 0) {
        return;
    }

    off = arg0 * 2;
    counter_entry = (u8 *)&st->unk_7F0[0];
    counter_entry += off;
    row = &st->unk_74C[0];
    entry = counter_entry + 1;
    i = 0;
    while (i < *(s8 *)((u8 *)st + 0x82C)) {
        if (arg0 == ((1)[row])) {
            if (count > 2) {
                return;
            }
            if (((2)[row]) != 0) {
                if ((s8)((0)[counter_entry]) == 0) {
                    fn_80067344(1, 0x10, 0xB0270000, ((2)[row]));
                    if (arg1 <= lbl_1_rodata_4544) {
                        if (st->unk_740 == 0 && st->unk_744 <= 0x2D) {
                            fn_80067898(0xA9090200);
                        }
                    } else if (arg1 <= lbl_1_rodata_4548) {
                        if (st->unk_740 == 0 && st->unk_744 <= 0x2D) {
                            fn_80067898(0xA9090200);
                        }
                    } else {
                        if (st->unk_740 == 0 && st->unk_744 <= 0x2D) {
                            fn_80067898(0xA9090600);
                        }
                    }
                    count++;
                }
            }
            counter_entry[0]++;
            entry[0] = 0;
            if ((s8)((0)[counter_entry]) > 6) {
                counter_entry[0] = 0;
            }
        }
        row += 0x14;
        i++;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_A33F0 */

/* fzgx:begin fn_1_A358C */
extern u32 lbl_1_bss_6EA98;
extern s32 fn_1_3F864(void);
extern u32 fn_1_864E8(s32 arg0);
extern void fn_80067898(u32 arg0);
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_A358C(s32 arg0) {
    u8* base = (u8*)&lbl_1_bss_6EA98;
    u8* entry;
    u32* flags;
    s32 id = arg0;
    s32 i;
    if (fn_1_3F864() != 0) {
        entry = base + 0x74C;
        flags = (u32*)(base + 0x830);
        i = 0;
        while (i < (s8)base[0x82C]) {
            if (id == entry[1] && entry[2] != 0 && (fn_1_864E8(id) & 0x400) != 0 &&
                (*flags & 0x400) == 0 && base[0x740] == 0 && *(u32*)(base + 0x744) <= 0x2D) {
                fn_80067898(0xA9091000);
            }
            entry += 0x14;
            flags++;
            i++;
        }
    }
}
/* fzgx:end fn_1_A358C */

/* fzgx:begin fn_1_A3C78 noprologue */
#include "types.h"
#include "rel/main_rel/sound.h"

extern s32 fn_1_3F864(s32 arg0, s32 arg1);
extern u32 fn_1_864E8(s32 arg0);
extern void fn_80067344(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
extern void fn_80067898(u32 arg0);

void fn_1_A3C78(s32 arg0, s32 arg1) {
    u8 *base;
    u8 *entry;

    base = (u8 *)&lbl_1_bss_6EA98;
    if (fn_1_3F864(arg0, arg1) != 0) {
        switch (arg1) {
        case 0:
            if ((fn_1_864E8(arg0) & 0x280) == 0) {
                entry = base + 0x74C;
                arg1 = 0;
                while (arg1 < *(s8 *)(base + 0x82C)) {
                    if (arg0 == *(u8 *)(entry + 1) && *(u8 *)(entry + 2) != 0) {
                        fn_80067344(1, 0x10, 0xB0270000, *(u8 *)(entry + 2));
                        if (base[0x740] == 0 && *(u32 *)(base + 0x744) <= 0x2D) {
                            fn_80067898(0xA9090F00);
                        }
                    }
                    entry += 0x14;
                    arg1++;
                }
            }
            break;
        }
    }
}
/* fzgx:end fn_1_A3C78 */

/* fzgx:begin fn_1_A4BC8 noprologue */
#include "types.h"

extern u32 fn_1_864E8(int);
extern void *fn_1_86254(int);
extern u32 fn_80067898(u32);
extern u8 lbl_1_bss_6F1D8;
extern u32 lbl_1_bss_6F1DC;

typedef struct {
    u8 pad[0x10C];
    s32 field_10C;
    s32 field_110;
} FnA4BC8State;

void fn_1_A4BC8(void *arg0, void *arg1, FnA4BC8State *state) {
    u32 flags;

    flags = fn_1_864E8((int)arg0);
    fn_1_86254((int)arg0);

    if (!(flags & 0x00010880)) {
        if (state->field_10C && state->field_110 &&
            !lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9061800);
        }

        if ((flags & 0x00040000) &&
            !lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(0xA9092000);
        }
    }
}
/* fzgx:end fn_1_A4BC8 */

/* fzgx:begin fn_1_A4C9C */
void fn_1_A4C9C(s32 index, u8 value) {
    s16 mode;

    mode = camera_get_mode();
    if (value == lbl_1_bss_6F2D8[index * 2]) {
        return;
    }

    fn_80067344(1, 2, 0xB0270000, 0x7F);

    switch (value) {
    case 2:
        fn_1_A5470(mode);
        lbl_1_bss_6F2D8[index * 2] = value;
        break;
    case 1:
        lbl_1_bss_6F2D8[index * 2] = value;
        break;
    case 3:
        if ((fn_1_3F13C() & 0xFF) == 2 && fn_1_EB0B0() != 0) {
            if (fn_1_F1B94() == 1) {
                if (lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9064E00);
                }
                lbl_1_bss_6F2D8[index * 2] = value;
            } else if (fn_1_F1B94() == 3) {
                if (lbl_1_bss_6F1DC <= 0x2D) {
                    fn_80067898(0xA9064F00);
                }
                lbl_1_bss_6F2D8[index * 2] = value;
            }
        } else {
            if (lbl_1_bss_6F1DC <= 0x2D) {
                fn_80067898(0xA9062200);
            }
            lbl_1_bss_6F2D8[index * 2] = value;
        }
        break;
    }
}
/* fzgx:end fn_1_A4C9C */

/* fzgx:begin fn_1_A4DF4 noprologue */
#include "types.h"

extern u32 fn_80067898(u32);
extern u32 lbl_1_bss_6F1DC;
extern u8 lbl_1_bss_6F1D8;

void fn_1_A4DF4(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v0 = 0xA9090000;
    v0 += 4608;
    fn_80067898(v0);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v1 = 0xA9090000;
    v1 += 5632;
    fn_80067898(v1);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v2 = 0xA9090000;
    v2 += 7168;
    fn_80067898(v2);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v3 = 0xA9090000;
    v3 += 9216;
    fn_80067898(v3);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v4 = 0xA9090000;
    v4 += 11776;
    fn_80067898(v4);
    }
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
    v5 = 0xA9090000;
    v5 += 3328;
    fn_80067898(v5);
    }
}
/* fzgx:end fn_1_A4DF4 */

/* fzgx:begin fn_1_A4F18 */
void fn_1_A4F18(s32 value) {
    u8 *state = (u8 *)&lbl_1_bss_6EA98;

    if (state[0x7A0] != (u8)value) {
        fn_80067344(1, 0x10, 0xB0270000, 0x7F);

        switch ((u8)value) {
        case 3:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060000);
            }
            break;
        case 2:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060100);
            }
            break;
        case 1:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060200);
            }
            break;
        case 0:
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9091A00);
            }
            if (!state[0x740] && *(u32 *)(state + 0x744) <= 0x2D) {
                fn_80067898(0xA9060300);
            }
            break;
        }
    }

    state[0x7A0] = value;
}
/* fzgx:end fn_1_A4F18 */

/* fzgx:begin fn_1_A50C8 */
void fn_1_A50C8(s32 index) {
    u32 value;

    if (index > 0x28) {
        value = 0xA9100700;
    } else {
        value = lbl_1_rodata_45D0[index * 2];
    }

    fn_80067344(2, 0xF, 0xB0270000, 0x7F);

    if (!lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(value);
    }
}
/* fzgx:end fn_1_A50C8 */

/* fzgx:begin fn_1_A514C */
extern u32 lbl_1_rodata_45D0[82];
extern u8 lbl_1_bss_6F1D8;
extern u32 lbl_1_bss_6F1DC;

extern void fn_80067344(s32, s32, u32, s32);
extern void fn_80067898(u32);

void fn_1_A514C(s32 index) {
    u32 offset;
    u32 value;

    if (index <= 0x28) {
        value = lbl_1_rodata_45D0[index * 2 + 1];
        fn_80067344(2, 0xf, 0xb0270000, 0x7f);
        if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2d) {
            fn_80067898(value);
        }
    }
}
/* fzgx:end fn_1_A514C */

/* fzgx:begin fn_1_A51C8 */
void fn_1_A51C8(s16 index) {
    u32 value;

    if (index <= 6) {
        value = lbl_1_rodata_4718[index];
        fn_80067344(2, 0xF, 0xB0270000, 0x7F);

        if (!lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(value);
        }
    }
}
/* fzgx:end fn_1_A51C8 */

/* fzgx:begin fn_1_A5244 */
void fn_1_A5244(u8 index) {
    u32 value;

    if (index <= 0x1D) {
        value = lbl_1_rodata_4730[index];
        fn_80067344(1, 2, 0xB0270000, 0x7F);

        if (lbl_1_bss_6F1DC <= 0x2D) {
            fn_80067898(value);
        }
    }
}
/* fzgx:end fn_1_A5244 */

/* fzgx:begin fn_1_A52B0 */
void fn_1_A52B0(s32 index) {
    u32 value;

    if ((u8)index > 0x1E) {
        return;
    }

    value = lbl_1_rodata_47A8[(u8)index - 1];

    fn_80067344(1, 0xF, 0xB0270000, 0x7F);

    if (!lbl_1_bss_6F1D8 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(value);
    }
}
/* fzgx:end fn_1_A52B0 */

/* fzgx:begin fn_1_A5330 */
void fn_1_A5330(u8 value, s16 index) {
    lbl_1_bss_6F41C[index] = value;
}
/* fzgx:end fn_1_A5330 */

/* fzgx:begin fn_1_A5344 */
#include "types.h"


extern void fn_80067898(u32 value);

#pragma opt_dead_assignments off
void fn_1_A5344(u8 value, s16 index) {
    u8 *table;
    s32 i;

    table = (*(u8 (*)[])&lbl_1_bss_6EA98) + 0x984;
    if (table[index] > value) {
        for (i = 0; i < (s32)(table[index] - value); i++) {
            if ((value - i) % 10 == 0 &&
                (*(u8 (*)[])&lbl_1_bss_6EA98)[0x740] == 0 &&
                *(u32 *)((*(u8 (*)[])&lbl_1_bss_6EA98) + 0x744) <= 0x2d) {
                fn_80067898(0xa9010300);
            }
        }
    } else if (table[index] < value) {
        for (i = 0; i < (s32)(value - table[index]); i++) {
            if ((value - i) % 10 == 0 &&
                (*(u8 (*)[])&lbl_1_bss_6EA98)[0x740] == 0 &&
                *(u32 *)((*(u8 (*)[])&lbl_1_bss_6EA98) + 0x744) <= 0x2d) {
                fn_80067898(0xa9010300);
            }
        }
    }

    table[index] = value;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_A5344 */

/* fzgx:begin fn_1_A5470 */
// Starts the requested sound and suppresses playback when the channel limit is reached.
void fn_1_A5470(s32 value) {
    s32 sound_id;
    u32 sound_resource;

    if (value == -1) {
        return;
    }

    sound_id = (s8)value;
    sound_id = fn_1_86690(sound_id);
    sound_resource = (u32)lbl_1_rodata_4820[(s8)sound_id];

    fn_80067344(1, 0x10, 0xB0270000, 0x7F);
    if (sound_resource != 0 && lbl_1_bss_6F1D8 == 0 &&
        lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(sound_resource);
    }
}
/* fzgx:end fn_1_A5470 */

/* fzgx:begin fn_1_A54FC noprologue */
#include "types.h"

typedef struct SoundData {
    u8 pad_000[0x740];
    u8 unk_740;
    u8 pad_741[3];
    u32 unk_744;
    u8 pad_748[0x5c];
    u32 unk_7a4;
    u8 pad_7a8[0xd8];
    s16 unk_880;
} SoundData;

extern SoundData lbl_1_bss_6EA98;
extern void fn_80067898(u32 value);

void fn_1_A54FC(void) {
    u32 flags;

    if ((lbl_1_bss_6EA98.unk_7a4 & 1) == 0 ||
        lbl_1_bss_6EA98.unk_740 != 0) {
        return;
    }

    lbl_1_bss_6EA98.unk_880++;
    if (lbl_1_bss_6EA98.unk_880 == 0x78) {
        if (lbl_1_bss_6EA98.unk_740 == 0 &&
            lbl_1_bss_6EA98.unk_744 <= 0x2d) {
            fn_80067898(0xA9065100);
        }
        flags = lbl_1_bss_6EA98.unk_7a4;
        lbl_1_bss_6EA98.unk_880 = 0;
        lbl_1_bss_6EA98.unk_7a4 = flags & ~1;
    }
}
/* fzgx:end fn_1_A54FC */

/* fzgx:begin fn_1_A5590 */
// fn_1_A5590: empty in retail (single blr).
void fn_1_A5590(void) {
}
/* fzgx:end fn_1_A5590 */

/* fzgx:begin fn_1_A5848 */
u8 fn_1_A5848(void) {
    return lbl_1_bss_6F1E0;
}
/* fzgx:end fn_1_A5848 */

/* fzgx:begin fn_1_A5858 */
void fn_1_A5858(u8 value) {
    lbl_1_bss_6F1E0 = value;
}
/* fzgx:end fn_1_A5858 */

/* fzgx:begin fn_1_A5864 */
void fn_1_A5864(void) {
    if (lbl_1_bss_6EAD0.unk_0 != 0) {
        if (lbl_1_bss_6EAD0.unk_0->unk_0 != 0 &&
            fn_8004C658(lbl_1_bss_6EAD0.unk_0->unk_0) == 3) {
            if (fn_8004BBCC(lbl_1_bss_6EAD0.unk_0->unk_0) == 0) {
                ADXT_Pause(lbl_1_bss_6EAD0.unk_0->unk_0, 1);
            }
        }

        if (lbl_1_bss_6EAD0.unk_0->unk_4 != 0 &&
            fn_8004C658(lbl_1_bss_6EAD0.unk_0->unk_4) == 3) {
            if (fn_8004BBCC(lbl_1_bss_6EAD0.unk_0->unk_4) == 0) {
                ADXT_Pause(lbl_1_bss_6EAD0.unk_0->unk_4, 1);
            }
        }

        if (fn_1_3FC38() != 0) {
            if (lbl_1_bss_6EAC6.unk_0 != 0) {
                fn_800674FC(0x10, 0xA0000300, 0);
            }
            if (lbl_1_bss_6EAC6.unk_0 != 0) {
                fn_800674FC(0x10, 0xA0000400, 0);
            }
            if (lbl_1_bss_6EAC6.unk_0 != 0) {
                fn_800674FC(0, 0xA0020000, 0);
            }
        }
    }
}
/* fzgx:end fn_1_A5864 */

/* fzgx:begin fn_1_A59AC */
// Updates active sound handles and emits the sound-system notification when enabled.
void fn_1_A59AC(void) {
    u8 *sound = (u8 *)&lbl_1_bss_6EA98;

    if (*(u32 *)(sound + 0x38) != 0) {
        if (*(u32 *)(*(u32 *)(sound + 0x38)) != 0 &&
            fn_8004C658(*(u32 *)(*(u32 *)(sound + 0x38))) == 3 &&
            fn_8004BBCC(*(u32 *)(*(u32 *)(sound + 0x38))) != 0) {
            ADXT_Pause(*(u32 *)(*(u32 *)(sound + 0x38)), 0);
        }

        if (fn_1_3FC38() == 0 || *(u8 *)(sound + 0x749) == 0) {
            if (*(u32 *)(*(u32 *)(sound + 0x38) + 4) != 0 &&
                fn_8004C658(*(u32 *)(*(u32 *)(sound + 0x38) + 4)) == 3 &&
                fn_8004BBCC(*(u32 *)(*(u32 *)(sound + 0x38) + 4)) != 0) {
                ADXT_Pause(*(u32 *)(*(u32 *)(sound + 0x38) + 4), 0);
            }
        }

        if (fn_1_3FC38() != 0 && *(u8 *)(sound + 0x2e) != 0) {
            fn_800674FC(0, 0xA0030000, 0);
        }
    }
}
/* fzgx:end fn_1_A59AC */

/* fzgx:begin fn_1_A5AA0 noprologue */
#include "types.h"
#include "rel/main_rel/sound.h"

extern u32 lbl_1_bss_6F5C0;
extern u8 lbl_1_bss_6F5C4[44];
extern u8 *lbl_801A6410;

extern s32 fn_1_45D0(void *, u32, const char *, u32);
extern s32 fn_80006B70(const char *, void *);
extern void *fn_80006DE8(void *);
extern u32 fn_80006D1C(void *, u32, s32, u32);
extern void fn_80006CE4(void *);
extern s32 fn_80009CD4(void *, u32, const char *, u32);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern void OSLink(void *, void *);
extern void OSLinkFixed(void *, void *);

typedef struct Fn1A5AA0Section {
    u8 pad_0[0x20];
    u32 unk20;
    u8 pad_24[0x10];
    void (*unk34)(void);
    u8 pad_38[0x10];
    u32 unk48;
} Fn1A5AA0Section;

typedef struct Fn1A5AA0Object {
    void *unk0;
    void *unk4;
} Fn1A5AA0Object;

void fn_1_A5AA0(const char *arg0, Fn1A5AA0Object *arg1) {
    u8 *p = (u8 *)&lbl_1_data_33FF0;
    u32 buf[18];
    u32 count;
    s32 flag;
    u32 avail;
    u32 link;
    Fn1A5AA0Section *s;
    u32 sz;
    void *b;

    if ((s32)lbl_1_bss_6F5C0 >= 10) {
        OSReport((const char *)(p + 0x148), arg0);
        OSPanic((const char *)(p + 0x150), 0x3b, (const char *)(p + 0x160));
    }

    count = lbl_1_bss_6F5C0;
    lbl_1_bss_6F5C0 = count + 1;
    *(u32 *)((u8 *)&lbl_1_bss_6F5C4 + (count << 2)) = (u32)arg1;
    arg1->unk0 = 0;
    arg1->unk4 = 0;

    if (fn_80006B70(arg0, buf) != 0) {
        avail = ((u32)fn_80006DE8(buf) + 0x1f) & ~0x1f;
        flag = (s32)avail;
        arg1->unk0 = (void *)fn_1_45D0(lbl_801A6410, avail, (const char *)(p + 0x150), 0x48);
        flag = fn_80006D1C(buf, (u32)arg1->unk0, flag, 0);
        fn_80006CE4(buf);

        if (flag != 0) {
            s = (Fn1A5AA0Section *)arg1->unk0;
            link = ((((0x1f) + ((u32)s)) + (s->unk48))) & ~0x1f;
            sz = (link + s->unk20) - (u32)s;

            if (sz > avail) {
                flag = fn_80009CD4(s, sz, (const char *)(p + 0x150), 0x55);
                if (flag == 0) {
                    b = (void *)fn_1_45D0(lbl_801A6410, ((Fn1A5AA0Section *)arg1->unk0)->unk20, (const char *)(p + 0x150), 0x58);
                    arg1->unk4 = b;
                    link = (u32)b;
                }
            }

            if (flag != 0) {
                OSLinkFixed(arg1->unk0, (void *)link);
            } else {
                OSLink(arg1->unk0, (void *)link);
            }

            ((Fn1A5AA0Section *)arg1->unk0)->unk34();
        } else {
            OSReport((const char *)(p + 0x148), arg0);
            OSPanic((const char *)(p + 0x150), 0x64, (const char *)(p + 0x17c));
        }
    } else {
        OSReport((const char *)(p + 0x148), arg0);
        OSPanic((const char *)(p + 0x150), 0x69, (const char *)(p + 0x190));
    }
}
/* fzgx:end fn_1_A5AA0 */
