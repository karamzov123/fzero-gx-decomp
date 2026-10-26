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
extern void ARQInit(void);
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
    ARQInit();
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
extern u32 ARAlloc(u32);
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
    t12 = ARAlloc(0x6be000);
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

/* fzgx:begin fn_1_A0214 */
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
extern void ARQInit(void);
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
u8 lbl_1_bss_6EAA5__fzgx_offset_0;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u8 fzgx_obj_lbl_1_bss_6EAB4[18];
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u8 lbl_1_bss_6EAC6__fzgx_offset_2;
u8 lbl_1_bss_6EAC6__fzgx_offset_3;
u8 lbl_1_bss_6EAC6__fzgx_offset_4;
u8 lbl_1_bss_6EAC6__fzgx_offset_5;
u8 lbl_1_bss_6EAC6__fzgx_offset_6;
u8 lbl_1_bss_6EAC6__fzgx_offset_7;
u8 lbl_1_bss_6EAC6__fzgx_offset_8;
u8 lbl_1_bss_6EAC6__fzgx_offset_9;
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
    s = lbl_1_bss_6EAA5__fzgx_offset_0;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = lbl_1_bss_6EAC6__fzgx_offset_1;
    s = lbl_1_bss_6EAC6__fzgx_offset_2;
    s = lbl_1_bss_6EAC6__fzgx_offset_3;
    s = lbl_1_bss_6EAC6__fzgx_offset_4;
    s = lbl_1_bss_6EAC6__fzgx_offset_5;
    s = lbl_1_bss_6EAC6__fzgx_offset_6;
    s = lbl_1_bss_6EAC6__fzgx_offset_7;
    s = lbl_1_bss_6EAC6__fzgx_offset_8;
    s = lbl_1_bss_6EAC6__fzgx_offset_9;
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

    if (lbl_1_bss_6EAA5__fzgx_offset_0 == 0) {
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

/* fzgx:begin fn_1_A0978 */
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
extern void ARQInit(void);
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
u8 lbl_1_bss_6EAA5__fzgx_offset_0;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u8 lbl_1_bss_6EAC6__fzgx_offset_2;
u8 lbl_1_bss_6EAC6__fzgx_offset_3;
u8 lbl_1_bss_6EAC6__fzgx_offset_4;
u8 lbl_1_bss_6EAC6__fzgx_offset_5;
u8 lbl_1_bss_6EAC6__fzgx_offset_6;
u8 lbl_1_bss_6EAC6__fzgx_offset_7;
u8 lbl_1_bss_6EAC6__fzgx_offset_8;
u8 lbl_1_bss_6EAC6__fzgx_offset_9;
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
u8 lbl_1_bss_6F244__fzgx_offset_2;
u8 lbl_1_bss_6F244__fzgx_offset_3;
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
    s = lbl_1_bss_6EAA5__fzgx_offset_0;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = lbl_1_bss_6EAB4__fzgx_offset_10;
    s = lbl_1_bss_6EAB4__fzgx_offset_11;
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = lbl_1_bss_6EAC6__fzgx_offset_1;
    s = lbl_1_bss_6EAC6__fzgx_offset_2;
    s = lbl_1_bss_6EAC6__fzgx_offset_3;
    s = lbl_1_bss_6EAC6__fzgx_offset_4;
    s = lbl_1_bss_6EAC6__fzgx_offset_5;
    s = lbl_1_bss_6EAC6__fzgx_offset_6;
    s = lbl_1_bss_6EAC6__fzgx_offset_7;
    s = lbl_1_bss_6EAC6__fzgx_offset_8;
    s = lbl_1_bss_6EAC6__fzgx_offset_9;
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
    s = lbl_1_bss_6F244__fzgx_offset_2;
    s = lbl_1_bss_6F244__fzgx_offset_3;
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

    if (fn_1_3F864() == 0 || lbl_1_bss_6EAA5__fzgx_offset_0 != 0) {
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

/* fzgx:begin fn_1_A0D20 */
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
extern void ARQInit(void);
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
u8 fzgx_pool_lbl_1_bss_6EAA4__fzgx_offset_1;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b9;
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
u8 fzgx_pool_lbl_1_bss_6F244__fzgx_offset_1__b1;
u8 fzgx_pool_lbl_1_bss_6F244__fzgx_offset_1__b2;
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
s16 fzgx_pool_lbl_1_bss_6F316__fzgx_offset_2;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6EA98;
    s = fzgx_obj_lbl_1_bss_6EA9C;
    s = lbl_1_bss_6EA9C__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_6EAA4;
    s = fzgx_pool_lbl_1_bss_6EAA4__fzgx_offset_1;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = lbl_1_bss_6EAB4__fzgx_offset_10;
    s = lbl_1_bss_6EAB4__fzgx_offset_11;
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_6EAC6__b9;
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
    s = fzgx_pool_lbl_1_bss_6F244__fzgx_offset_1__b1;
    s = fzgx_pool_lbl_1_bss_6F244__fzgx_offset_1__b2;
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
    s = fzgx_pool_lbl_1_bss_6F316__fzgx_offset_2;
}
#pragma section code_type ".text"

void fn_1_A0D20(void) {
    s32 i;

    if (fzgx_obj_lbl_1_bss_6EAC6 == 0) {
        return;
    }
    fzgx_obj_lbl_1_bss_6F244 = 1;
    lbl_1_bss_6F23C__fzgx_offset_4 = 0;
    for (i = 0; i < 4; i++) {
        fzgx_obj_lbl_1_bss_6F2C8[i] &= ~0x80;
    }
}
/* fzgx:end fn_1_A0D20 */

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

/* fzgx:begin fn_1_A11EC noprologue */
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
u8 lbl_1_bss_6EAA5__fzgx_offset_0;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u8 lbl_1_bss_6EAC6__fzgx_offset_2;
u8 lbl_1_bss_6EAC6__fzgx_offset_3;
u8 lbl_1_bss_6EAC6__fzgx_offset_4;
u8 lbl_1_bss_6EAC6__fzgx_offset_5;
u8 lbl_1_bss_6EAC6__fzgx_offset_6;
u8 lbl_1_bss_6EAC6__fzgx_offset_7;
u8 lbl_1_bss_6EAC6__fzgx_offset_8;
u8 lbl_1_bss_6EAC6__fzgx_offset_9;
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
u8 lbl_1_bss_6F244__fzgx_offset_2;
u8 lbl_1_bss_6F244__fzgx_offset_3;
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
s16 lbl_1_bss_6F318__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6EA98;
    s = fzgx_obj_lbl_1_bss_6EA9C;
    s = lbl_1_bss_6EA9C__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_6EAA4;
    s = lbl_1_bss_6EAA5__fzgx_offset_0;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = lbl_1_bss_6EAB4__fzgx_offset_10;
    s = lbl_1_bss_6EAB4__fzgx_offset_11;
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = lbl_1_bss_6EAC6__fzgx_offset_1;
    s = lbl_1_bss_6EAC6__fzgx_offset_2;
    s = lbl_1_bss_6EAC6__fzgx_offset_3;
    s = lbl_1_bss_6EAC6__fzgx_offset_4;
    s = lbl_1_bss_6EAC6__fzgx_offset_5;
    s = lbl_1_bss_6EAC6__fzgx_offset_6;
    s = lbl_1_bss_6EAC6__fzgx_offset_7;
    s = lbl_1_bss_6EAC6__fzgx_offset_8;
    s = lbl_1_bss_6EAC6__fzgx_offset_9;
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
    s = lbl_1_bss_6F244__fzgx_offset_2;
    s = lbl_1_bss_6F244__fzgx_offset_3;
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
    s = lbl_1_bss_6F318__fzgx_offset_0;
}
#pragma section code_type ".text"

extern void fn_80008BEC(void *, s32, u32);
extern void fn_1_A2E24(u32, u32, u32);
extern void fn_1_A2DF4(u32, u32, u32);

void fn_1_A11EC(void) {
    s32 i;

    if (lbl_1_bss_6EAA5__fzgx_offset_0 != 0) {
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
    lbl_1_bss_6F318__fzgx_offset_0 = 0;
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

/* fzgx:begin fn_1_A1588 */
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
extern void ARQInit(void);
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

extern u32 fn_1_F2F34(void);
extern u8 lbl_1_rodata_437C[48];
extern s8 lbl_1_rodata_43AC[8];
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42E8;
extern void fn_8004D18C(void *, const char *);
extern u32 fn_8004BF0C(void *, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u8 fzgx_obj_lbl_1_bss_6EA9C[0x8];
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 fzgx_pool_fzgx_pad_6EAA5;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u8 fzgx_obj_lbl_1_bss_6EAA8[0x8];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4__fzgx_offset_4;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
s16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
void **fzgx_obj_lbl_1_bss_6EAD0;
u8 lbl_1_bss_6EAD0__fzgx_offset_4[0x704];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u8 fzgx_obj_lbl_1_bss_6F1E4[0x55];
u8 fzgx_obj_lbl_1_bss_6F239;
u8 fzgx_obj_lbl_1_bss_6F23C[0x7];
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244[0x80];
u8 fzgx_obj_lbl_1_bss_6F2C4;
u8 fzgx_obj_lbl_1_bss_6F2C8[0x10];
u8 fzgx_obj_lbl_1_bss_6F2D8[0x3E];
u8 fzgx_obj_lbl_1_bss_6F316;
u8 fzgx_obj_lbl_1_bss_6F317;
u8 fzgx_pool_fzgx_pad_6F318;
u8 fzgx_pool_fzgx_pad_6F319;
u8 fzgx_obj_lbl_1_bss_6F31A;
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];
f32 lbl_1_bss_6F31A__fzgx_offset_6;
f32 lbl_1_bss_6F31A__fzgx_offset_A;
u8 lbl_1_bss_6F31A__fzgx_offset_E;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6EAA5;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F23C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F244;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F316;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F318;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F319;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_E;
}
#pragma section code_type ".text"

#define S_FLAGS fzgx_obj_lbl_1_bss_6EAB4
#define S_FADE0 lbl_1_bss_6EAB4__fzgx_offset_8
#define S_FADE1 lbl_1_bss_6EAB4__fzgx_offset_C
#define S_TRACK lbl_1_bss_6EAB4__fzgx_offset_10
#define S_HANDLES fzgx_obj_lbl_1_bss_6EAD0
#define S_DISABLED fzgx_obj_lbl_1_bss_6F31A
#define S_VOLUME lbl_1_bss_6F31A__fzgx_offset_2
#define S_TARGET0 lbl_1_bss_6F31A__fzgx_offset_6
#define S_TARGET1 lbl_1_bss_6F31A__fzgx_offset_A
#define S_CYCLE lbl_1_bss_6F31A__fzgx_offset_E

void fn_1_A1588(void *h, u8 track) {
    void **handles;
    u32 index;
    u32 flags;
    if (S_DISABLED || !h || h == (void *)-1) return;
    handles = S_HANDLES;
    if (h == handles[0]) {
        u32 flags = S_FLAGS;
        S_FLAGS = flags & ~4;
        if (flags & 1) S_VOLUME[0] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];
        else {
            S_FADE0 = lbl_1_rodata_42E0;
            S_TARGET0 = (f32)((s16 *)&lbl_1_data_2D93C)[(u8)track];
        }
    }
    if (h == handles[1]) {
        u32 flags = S_FLAGS;
        S_FLAGS = flags & ~8;
        if (flags & 2) {
            S_VOLUME[1] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];
        } else {
            S_FADE1 = lbl_1_rodata_42E4;
            S_TARGET1 = (f32)((s16 *)&lbl_1_data_2D93C)[(u8)track];
        }
    }
    index = (u8)track;
    fn_8004D18C(h, ((const char **)&lbl_1_data_2D7B8)[(u8)track]);
    flags = S_FLAGS;
    if (flags & 3) {
        if (flags & 1) S_TARGET0 = lbl_1_rodata_42E8;
        if (flags & 2) S_TARGET1 = lbl_1_rodata_42E8;
        fn_8004BF0C(h, -400);
    } else {
        fn_8004BF0C(h, ((s16 *)&lbl_1_data_2D93C)[index]);
    }
    S_TRACK = track;
}
/* fzgx:end fn_1_A1588 */

/* fzgx:begin fn_1_A176C */
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
extern void ARQInit(void);
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

extern u32 fn_1_F2F34(void);
extern u8 lbl_1_rodata_437C[48];
extern s8 lbl_1_rodata_43AC[8];
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42F8;
extern const f32 lbl_1_rodata_42E8;
extern void fn_8004D18C(void *, const char *);
extern u32 fn_8004BF0C(void *, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u8 fzgx_obj_lbl_1_bss_6EA9C[0x8];
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 fzgx_pool_fzgx_pad_6EAA5;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u8 fzgx_obj_lbl_1_bss_6EAA8[0x8];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4__fzgx_offset_4;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
s16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
void **fzgx_obj_lbl_1_bss_6EAD0;
u8 lbl_1_bss_6EAD0__fzgx_offset_4[0x704];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u8 fzgx_obj_lbl_1_bss_6F1E4[0x55];
u8 fzgx_obj_lbl_1_bss_6F239;
u8 fzgx_obj_lbl_1_bss_6F23C[0x7];
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244[0x80];
u8 fzgx_obj_lbl_1_bss_6F2C4;
u8 fzgx_obj_lbl_1_bss_6F2C8[0x10];
u8 fzgx_obj_lbl_1_bss_6F2D8[0x3E];
u8 fzgx_obj_lbl_1_bss_6F316;
u8 fzgx_obj_lbl_1_bss_6F317;
u8 fzgx_pool_fzgx_pad_6F318;
u8 fzgx_pool_fzgx_pad_6F319;
u8 fzgx_obj_lbl_1_bss_6F31A;
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];
f32 lbl_1_bss_6F31A__fzgx_offset_6;
f32 lbl_1_bss_6F31A__fzgx_offset_A;
u8 lbl_1_bss_6F31A__fzgx_offset_E;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6EAA5;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F23C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F244;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F316;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F318;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F319;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_E;
}
#pragma section code_type ".text"

#define S_FLAGS fzgx_obj_lbl_1_bss_6EAB4
#define S_FADE0 lbl_1_bss_6EAB4__fzgx_offset_8
#define S_FADE1 lbl_1_bss_6EAB4__fzgx_offset_C
#define S_TRACK lbl_1_bss_6EAB4__fzgx_offset_10
#define S_HANDLES fzgx_obj_lbl_1_bss_6EAD0
#define S_DISABLED fzgx_obj_lbl_1_bss_6F31A
#define S_VOLUME lbl_1_bss_6F31A__fzgx_offset_2
#define S_TARGET0 lbl_1_bss_6F31A__fzgx_offset_6
#define S_TARGET1 lbl_1_bss_6F31A__fzgx_offset_A
#define S_CYCLE lbl_1_bss_6F31A__fzgx_offset_E

void fn_1_A176C(void *h, s32 track) {
    void **handles;
    u32 index;
    u32 flags;
    if (S_DISABLED || S_TRACK == (u8)track) return;
    if (!h || h == (void *)-1) return;
    handles = S_HANDLES;
    if (h == handles[0]) {
        u32 flags = S_FLAGS;
        S_FLAGS = flags & ~4;
        if (flags & 1) S_VOLUME[0] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];
        else {
            S_FADE0 = lbl_1_rodata_42E0;
            S_TARGET0 = (f32)((s16 *)&lbl_1_data_2D93C)[(u8)track];
        }
    }
    if (h == handles[1]) {
        u32 flags = S_FLAGS;
        S_FLAGS = flags & ~8;
        if (flags & 2) {
            S_VOLUME[1] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];
        } else {
            S_FADE1 = lbl_1_rodata_42F8;
            S_TARGET1 = (f32)((s16 *)&lbl_1_data_2D93C)[(u8)track];
        }
    }
    index = (u8)track;
    fn_8004D18C(h, ((const char **)&lbl_1_data_2D7B8)[(u8)track]);
    flags = S_FLAGS;
    if (flags & 3) {
        if (flags & 1) S_TARGET0 = lbl_1_rodata_42E8;
        if (flags & 2) S_TARGET1 = lbl_1_rodata_42E8;
        fn_8004BF0C(h, -400);
    } else {
        fn_8004BF0C(h, ((s16 *)&lbl_1_data_2D93C)[index]);
    }
    S_TRACK = track;
}
/* fzgx:end fn_1_A176C */

/* fzgx:begin fn_1_A1964 */
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
extern void ARQInit(void);
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

extern char lbl_1_rodata_42FC[42];
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42E8;
extern void fn_8004D18C(u32, u32);
extern u32 fn_8004BF0C(u32, u32);
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u8 fzgx_obj_lbl_1_bss_6EA9C[0x8];
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 fzgx_pool_fzgx_pad_6EAA5;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u8 fzgx_obj_lbl_1_bss_6EAA8[0x8];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4__fzgx_offset_4;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
s16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
void **fzgx_obj_lbl_1_bss_6EAD0;
u8 lbl_1_bss_6EAD0__fzgx_offset_4[0x704];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u8 fzgx_obj_lbl_1_bss_6F1E4[0x55];
u8 fzgx_obj_lbl_1_bss_6F239;
u8 fzgx_obj_lbl_1_bss_6F23C[0x7];
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244[0x80];
u8 fzgx_obj_lbl_1_bss_6F2C4;
u8 fzgx_obj_lbl_1_bss_6F2C8[0x10];
u8 fzgx_obj_lbl_1_bss_6F2D8[0x3E];
u8 fzgx_obj_lbl_1_bss_6F316;
u8 fzgx_obj_lbl_1_bss_6F317;
u8 fzgx_pool_fzgx_pad_6F318;
u8 fzgx_pool_fzgx_pad_6F319;
u8 fzgx_obj_lbl_1_bss_6F31A;
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];
f32 lbl_1_bss_6F31A__fzgx_offset_6;
f32 lbl_1_bss_6F31A__fzgx_offset_A;
u8 lbl_1_bss_6F31A__fzgx_offset_E;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6EAA5;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F23C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F244;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F316;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F318;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F319;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_E;
}
#pragma section code_type ".text"

#define S_FLAGS fzgx_obj_lbl_1_bss_6EAB4
#define S_FADE0 lbl_1_bss_6EAB4__fzgx_offset_8
#define S_FADE1 lbl_1_bss_6EAB4__fzgx_offset_C
#define S_TRACK lbl_1_bss_6EAB4__fzgx_offset_10
#define S_HANDLES fzgx_obj_lbl_1_bss_6EAD0
#define S_DISABLED fzgx_obj_lbl_1_bss_6F31A
#define S_VOLUME lbl_1_bss_6F31A__fzgx_offset_2
#define S_TARGET0 lbl_1_bss_6F31A__fzgx_offset_6
#define S_TARGET1 lbl_1_bss_6F31A__fzgx_offset_A

#pragma opt_propagation off

#pragma opt_propagation off
static inline void setup(s32 h, u32 *handles, u8 id) {
 u32 flags;
 if (h == handles[0]) {
  flags = S_FLAGS; S_FLAGS = flags & ~4;
  if (flags & 1) S_VOLUME[0] = ((s16 *)&lbl_1_data_2D93C)[id];
  else {
   { f32 speed = lbl_1_rodata_42E0; f32 converted = (f32)((s16 *)&lbl_1_data_2D93C)[id]; S_FADE0 = speed; S_TARGET0 = converted; }
  }
 }
 if (h == handles[1]) {
  flags = S_FLAGS; S_FLAGS = flags & ~8;
  if (flags & 2) S_VOLUME[1] = ((s16 *)&lbl_1_data_2D93C)[id];
  else {
   { f32 speed = lbl_1_rodata_42E4; f32 converted = (f32)((s16 *)&lbl_1_data_2D93C)[id]; S_FADE1 = speed; S_TARGET1 = converted; }
  }
 }
 fn_8004D18C(h, ((u32 *)&lbl_1_data_2D7B8)[id]);
 flags = S_FLAGS;
 if (flags & 3) {
  if (flags & 1) S_TARGET0 = lbl_1_rodata_42E8;
  if (flags & 2) S_TARGET1 = lbl_1_rodata_42E8;
  fn_8004BF0C(h, -400);
 } else fn_8004BF0C(h, ((s16 *)&lbl_1_data_2D93C)[id]);
 S_TRACK = id;
}
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void fn_1_A1964(u8 arg) {
 u32 *handles = (u32 *)S_HANDLES;
 s8 id;
 u32 h;
 if (!handles) return;
 if (arg >= 41) id = -1;
 else id = lbl_1_rodata_42FC[arg];
 if (id == -1) {
  h = handles[0];
  if (!S_DISABLED && h != 0 && h != -1) setup(h, handles, 66);
 } else {
  h = handles[0];
  if (!S_DISABLED && h != 0 && h != -1) setup(h, handles, (u8)id);
 }
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_A1964 */

/* fzgx:begin fn_1_A1CE8 */
extern u8 lbl_1_bss_6F243;
extern u16 lbl_1_rodata_4328[42];

void fn_1_A1CE8(u32 arg0) {
    s16 v;
    if (lbl_1_bss_6EAD0.unk_0 == NULL || (u8)arg0 >= 0x2D || lbl_1_bss_6F243 != 0) {
        return;
    }
    if (fn_8004C658(lbl_1_bss_6EAD0.unk_0->unk_0) == 3) {
        if ((u8)arg0 < 0x29) {
            v = lbl_1_rodata_4328[(u8)arg0];
        } else if ((u8)arg0 == 0x29) {
            v = 0x100;
        } else if ((u8)arg0 == 0x2A) {
            v = 0;
        } else if ((u8)arg0 == 0x2B) {
            v = 0x200;
        } else if ((u8)arg0 == 0x2C) {
            v = 0x300;
        }
        fn_80067898(0xA8000000 | (s16)v);
        lbl_1_bss_6F243 = 1;
    }
}
/* fzgx:end fn_1_A1CE8 */

/* fzgx:begin fn_1_A1DCC */
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
extern void ARQInit(void);
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

extern u32 fn_1_F2F34(void);
extern u8 lbl_1_rodata_437C[48];
extern s8 lbl_1_rodata_43AC[8];
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42E8;
extern void fn_8004D18C(void *, const char *);
extern u32 fn_8004BF0C(void *, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u8 fzgx_obj_lbl_1_bss_6EA9C[0x8];
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 fzgx_pool_fzgx_pad_6EAA5;
u8 fzgx_obj_lbl_1_bss_6EAA6;
u8 fzgx_obj_lbl_1_bss_6EAA8[0x8];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4__fzgx_offset_4;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
s16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
void **fzgx_obj_lbl_1_bss_6EAD0;
u8 lbl_1_bss_6EAD0__fzgx_offset_4[0x704];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u8 fzgx_obj_lbl_1_bss_6F1E4[0x55];
u8 fzgx_obj_lbl_1_bss_6F239;
u8 fzgx_obj_lbl_1_bss_6F23C[0x7];
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244[0x80];
u8 fzgx_obj_lbl_1_bss_6F2C4;
u8 fzgx_obj_lbl_1_bss_6F2C8[0x10];
u8 fzgx_obj_lbl_1_bss_6F2D8[0x3E];
u8 fzgx_obj_lbl_1_bss_6F316;
u8 fzgx_obj_lbl_1_bss_6F317;
u8 fzgx_pool_fzgx_pad_6F318;
u8 fzgx_pool_fzgx_pad_6F319;
u8 fzgx_obj_lbl_1_bss_6F31A;
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];
f32 lbl_1_bss_6F31A__fzgx_offset_6;
f32 lbl_1_bss_6F31A__fzgx_offset_A;
u8 lbl_1_bss_6F31A__fzgx_offset_E;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA4;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6EAA5;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F23C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F244;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2D8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F316;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F318;
    s = *(u8 *)&fzgx_pool_fzgx_pad_6F319;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_E;
}
#pragma section code_type ".text"

#define S_FLAGS fzgx_obj_lbl_1_bss_6EAB4
#define S_FADE0 lbl_1_bss_6EAB4__fzgx_offset_8
#define S_FADE1 lbl_1_bss_6EAB4__fzgx_offset_C
#define S_TRACK lbl_1_bss_6EAB4__fzgx_offset_10
#define S_HANDLES fzgx_obj_lbl_1_bss_6EAD0
#define S_DISABLED fzgx_obj_lbl_1_bss_6F31A
#define S_VOLUME lbl_1_bss_6F31A__fzgx_offset_2
#define S_TARGET0 lbl_1_bss_6F31A__fzgx_offset_6
#define S_TARGET1 lbl_1_bss_6F31A__fzgx_offset_A
#define S_CYCLE lbl_1_bss_6F31A__fzgx_offset_E

static inline void play(u8 track) {
    void **handles = S_HANDLES;
    void *h = handles[0];
    u32 index;
    u32 flags;
    if (S_DISABLED || !h || h == (void *)-1) return;
    if (h == handles[0]) {
        u32 flags = S_FLAGS;
        S_FLAGS = flags & ~4;
        if (flags & 1) S_VOLUME[0] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];
        else {
            f32 fade = lbl_1_rodata_42E0;
            f32 volume = (f32)((s16 *)&lbl_1_data_2D93C)[(u8)track];
            S_FADE0 = fade;
            S_TARGET0 = volume;
        }
    }
    if (h == handles[1]) {
        u32 flags = S_FLAGS;
        S_FLAGS = flags & ~8;
        if (flags & 2) {
            S_VOLUME[1] = ((s16 *)&lbl_1_data_2D93C)[(u8)track];
        } else {
            f32 fade = lbl_1_rodata_42E4;
            f32 volume = (f32)((s16 *)&lbl_1_data_2D93C)[(u8)track];
            S_FADE1 = fade;
            S_TARGET1 = volume;
        }
    }
    index = (u8)track;
    fn_8004D18C(h, ((const char **)&lbl_1_data_2D7B8)[(u8)track]);
    flags = S_FLAGS;
    if (flags & 3) {
        if (flags & 1) S_TARGET0 = lbl_1_rodata_42E8;
        if (flags & 2) S_TARGET1 = lbl_1_rodata_42E8;
        fn_8004BF0C(h, -400);
    } else {
        fn_8004BF0C(h, ((s16 *)&lbl_1_data_2D93C)[index]);
    }
    S_TRACK = track;
}
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
static inline u8 fn_1_A1DCC_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_lifetimes off
void fn_1_A1DCC(u8 arg0) {
    s8 track;
    /* All guards share the retail epilogue. */
    if (*(s16 *)&lbl_1_bss_960 == 10 || !S_HANDLES || (s32)fn_1_F2F34() != 0) goto end;
    S_TRACK = 255;
    if (arg0 > 45) track = -1;
    else if (lbl_1_bss_8CA24 || lbl_1_bss_8B5F0) track = 44;
    else if (lbl_1_bss_8B5F1) track = 43;
    else track = (s8)fn_1_A1DCC_array_read(arg0, lbl_1_rodata_437C);
    if (track == -1) {
        if (++S_CYCLE > 5) S_CYCLE = 0;
        play(lbl_1_rodata_43AC[S_CYCLE]);
    } else {
        play((u8)track);
    }
end:
    return;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_A1DCC */

/* fzgx:begin fn_1_A2210 noprologue */
#include "dolphin/types.h"
#include "sofdec/sj.h"

/* begin sofdec/adxt.h (deltawave784/fzgx, CC0) */
#ifndef SOFDEC_ADXT_H
#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (deltawave784/fzgx, CC0) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

CHECK_OFFSET(ADXTHandle, decoder, 0x4);
CHECK_OFFSET(ADXTHandle, output_volume, 0x40);
CHECK_OFFSET(ADXTHandle, error_code, 0x60);
CHECK_OFFSET(ADXTHandle, stream_loop_enabled, 0x6C);
CHECK_OFFSET(ADXTHandle, amplifier, 0x74);
CHECK_OFFSET(ADXTHandle, linked_stream_controller, 0x94);
CHECK_OFFSET(ADXTHandle, playback_time, 0x9C);
CHECK_OFFSET(ADXTHandle, pending_file_sectors, 0xBC);
CHECK_SIZE(ADXTHandle, 0xC0);

#endif

/* end sofdec/adxt.h */

extern u8 lbl_1_bss_8CA24;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern s16 lbl_1_data_2D93C[];
extern const char *lbl_1_data_2D7B8[];

extern s32 fn_1_F2F34(void);
extern u8 lbl_1_rodata_43B4[184];
extern const f64 lbl_1_rodata_42F0;
extern f32 lbl_1_rodata_42E0;
extern f32 lbl_1_rodata_42E4;
extern f32 lbl_1_rodata_42E8;
extern s32 fn_8004C658(char *);
extern void fn_8004D18C(u32, const char *);
extern u32 fn_8004BF0C(u32, u32);
extern void ADXT_Pause(ADXTHandle *, s32);
extern s32 fn_80067898(u32);

typedef struct {
    s8 id;      /* voice line index, -1 = none */
    u8 pad;
    s16 se;     /* sound effect id */
} CueEntry;

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
u32 lbl_1_bss_6EAB4__fzgx_offset_4;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2[2];
u32 *fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0__fzgx_offset_4[449];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
u32 fzgx_obj_lbl_1_bss_6F1E4[21];
u8 lbl_1_bss_6F1E4__fzgx_offset_54;
u8 lbl_1_bss_6F239;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C__fzgx_offset_4;
u8 lbl_1_bss_6F23C__fzgx_offset_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244[32];
u8 lbl_1_bss_6F2C4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u32 lbl_1_bss_6F2D8[15];
u16 lbl_1_bss_6F2D8__fzgx_offset_3C;
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
u8 lbl_1_bss_6F31A;
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];
f32 lbl_1_bss_6F31A__fzgx_offset_6;  /* retail addresses both floats base-relative: two scalars, not an array */
f32 lbl_1_bss_6F31A__fzgx_offset_A;
u32 lbl_1_bss_6F31A__fzgx_offset_E[31];

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
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_54;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F23C__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F2D8__fzgx_offset_3C;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
    s = *(u8 *)&lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_E;
}
#pragma section code_type ".text"

void fn_1_A2210(u8 cue)
{
    u32 handle;
    s16 se;
    s8 id;
    u32 *handles;
    u32 flags;
    const CueEntry *entry;

    if (fzgx_obj_lbl_1_bss_6EAD0 == NULL) {
        return;
    }
    if (lbl_1_bss_8CA24) {
        return;
    }
    if (lbl_1_bss_8B5F0) {
        return;
    }
    if (lbl_1_bss_8B5F1 || lbl_1_bss_6F23C__fzgx_offset_6) {
        return;
    }
    if (fn_1_F2F34() != 0) {
        return;
    }
    if (fn_8004C658((char *)fzgx_obj_lbl_1_bss_6EAD0[0]) != 3) {
        return;
    }

    if (cue > 0x2D) {
        id = -1;
        se = -1;
    } else {
        entry = (const CueEntry *)lbl_1_rodata_43B4;
        id = entry[cue].id;
        se = entry[cue].se;
    }

    if (id != -1) {
        handles = fzgx_obj_lbl_1_bss_6EAD0;
        handle = handles[1];
        if (!lbl_1_bss_6F31A && handle != 0 && handle != 0xFFFFFFFF) {
            if (handle == handles[0]) {
                flags = fzgx_obj_lbl_1_bss_6EAB4;
                fzgx_obj_lbl_1_bss_6EAB4 = flags & ~4;
                if (flags & 1) {
                    lbl_1_bss_6F31A__fzgx_offset_2[0] = lbl_1_data_2D93C[(u8)id];
                } else {
                    s32 v = lbl_1_data_2D93C[(u8)id];
                    lbl_1_bss_6EAB4__fzgx_offset_8 = lbl_1_rodata_42E0;
                    lbl_1_bss_6F31A__fzgx_offset_6 = v;
                }
            }
            if (handle == handles[1]) {
                flags = fzgx_obj_lbl_1_bss_6EAB4;
                fzgx_obj_lbl_1_bss_6EAB4 = flags & ~8;
                if (flags & 2) {
                    lbl_1_bss_6F31A__fzgx_offset_2[1] = lbl_1_data_2D93C[(u8)id];
                } else {
                    lbl_1_bss_6EAB4__fzgx_offset_C = lbl_1_rodata_42E4;
                    lbl_1_bss_6F31A__fzgx_offset_A = lbl_1_data_2D93C[(u8)id];
                }
            }
            fn_8004D18C(handle, lbl_1_data_2D7B8[(u8)id]);
            flags = fzgx_obj_lbl_1_bss_6EAB4;
            if (flags & 3) {
                if (flags & 1) {
                    lbl_1_bss_6F31A__fzgx_offset_6 = lbl_1_rodata_42E8;
                }
                if (flags & 2) {
                    lbl_1_bss_6F31A__fzgx_offset_A = lbl_1_rodata_42E8;
                }
                fn_8004BF0C(handle, -400);
            } else {
                fn_8004BF0C(handle, lbl_1_data_2D93C[(u8)id]);
            }
            lbl_1_bss_6EAB4__fzgx_offset_10 = id;
        }
        ADXT_Pause((ADXTHandle *)fzgx_obj_lbl_1_bss_6EAD0[1], 1);
        fn_80067898(se | 0xA8000000);
    }
    flags = lbl_1_bss_6F23C;
    lbl_1_bss_6F23C__fzgx_offset_6 = 1;
    lbl_1_bss_6F23C = flags | 0x20;
}
/* fzgx:end fn_1_A2210 */

/* fzgx:begin fn_1_A24CC pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"
#include "sofdec/sj.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

/* begin sofdec/adxt.h (deltawave784/fzgx, CC0) */
#ifndef SOFDEC_ADXT_H
#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (deltawave784/fzgx, CC0) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

CHECK_OFFSET(ADXTHandle, decoder, 0x4);
CHECK_OFFSET(ADXTHandle, output_volume, 0x40);
CHECK_OFFSET(ADXTHandle, error_code, 0x60);
CHECK_OFFSET(ADXTHandle, stream_loop_enabled, 0x6C);
CHECK_OFFSET(ADXTHandle, amplifier, 0x74);
CHECK_OFFSET(ADXTHandle, linked_stream_controller, 0x94);
CHECK_OFFSET(ADXTHandle, playback_time, 0x9C);
CHECK_OFFSET(ADXTHandle, pending_file_sectors, 0xBC);
CHECK_SIZE(ADXTHandle, 0xC0);

#endif

/* end sofdec/adxt.h */
/* begin game/main_rel/sound_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SOUND_TYPES_H
#define GAME_MAIN_REL_SOUND_TYPES_H

// Types (and the externs that name them) of sound.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* sofdec/adxt.h: inlined above */

typedef struct {
    u8 unk_0[0x3A0];
    void *unk_3A0;
} SoundObject;

extern SoundObject *fn_1_86854(s8 arg0);

#endif  // GAME_MAIN_REL_SOUND_TYPES_H

/* end game/main_rel/sound_types.h */

extern const f32 lbl_1_rodata_42E0;
extern int OSGetSoundMode(void);
extern u32 fn_1_44A4(void);
extern void fn_1_A2E24(u32 arg0, u32 arg1, s32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_80022014(u32 arg0);
extern void fn_80025D50(u32 arg0, u32 arg1);
extern void fn_8004B7D4();
extern void fn_8004BBA4();
extern void ADXT_Stop(ADXTHandle *handle);
extern void fn_8004CAC8(ADXTHandle *handle);
extern u32 fn_8004CD70(u32, u32, u32);
extern u32 fn_8004E59C(u32);
extern u32 fn_8004EC34(u32);
extern void fn_80065890();
extern void fn_8006589C(u32 value);
extern void fn_800658A8(u32 arg0);
extern u32 fn_1_9FE74(void *arg);
extern void fn_1_9FEE8(void *arg);
extern void fn_1_9FF50(void);
extern void fn_1_9FF54(void);
extern void fn_1_9FF58(void);
extern void fn_1_A04AC(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_3EF14(void *arg1);
extern u32 fn_1_F2F34(void);
extern u32 fn_1_864E8(int index);
extern u8 lbl_1_rodata_43B4[184];
extern void ADXT_Pause(ADXTHandle *handle, s32 paused);
extern u8 lbl_1_bss_A88[24];
extern u8 lbl_1_bss_CC0[152];
extern s32 fn_1_3F864();
extern s32 fn_1_3F854(void);
extern u32 fn_1_86514(int index);
extern f32 fn_1_8652C(int index);
extern s32 fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern s32 fn_80067898(u32 value);
extern void *lbl_801A6410;
extern u32 ARAlloc(u32 value);
extern u32 fn_80020778(void);
extern u32 fn_80025E18(void);
extern u32 fn_80068BFC(u32, u32, u32, u32, u32);
extern s32 fn_1_45D0();
extern void AIInit(u8 *stack);
extern void fn_1_4438(void);
extern void fn_80020724(void);
extern void fn_8002361C(u32 value0, u32 value1);
extern void fn_8002805C(void);
extern void fn_800411F4(void);
extern s8 fn_1_86690(s8 index);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 lbl_1_rodata_451C[5];
extern u32 lbl_1_rodata_4478[41];
extern void *fn_1_86254(int index);
extern u32 lbl_1_rodata_45D0[82];
extern u32 fn_80008E84();
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u8 lbl_1_bss_6EAA6;
extern u8 lbl_1_bss_6EAA4;
extern void fn_80067974(void);
extern void fn_800280F0(void);
extern void fn_80026FE0(void);
extern u32 lbl_1_bss_6EAA8[2];
extern u8 lbl_1_bss_6EAB0;
extern u32 ARInit(u32 *stack_index_addr, u32 num_entries);
extern void ARQInit(void);
extern u8 lbl_1_bss_6F1E1;
extern void fn_1_A2DF4(s32 arg0, void *arg1, s32 arg2);
extern void fn_1_A0680(void);
extern void fn_800674FC(u16 arg0, u32 arg1, s16 arg2);
extern s16 camera_get_mode(void);
extern u8 lbl_1_bss_6F2D8[62];
extern void fn_1_A5470(s32 value);
extern u8 fn_1_3F13C(void);
extern u32 fn_1_EB0B0(void);
extern u32 fn_1_F1B94(void);
extern u32 lbl_1_rodata_4718[];
extern u32 lbl_1_rodata_4730[];
extern u32 lbl_1_rodata_47A8[];
extern u8 lbl_1_bss_6F41C[260];
extern void *lbl_1_rodata_4820[41];
extern s32 fn_8004C658(char *arg0);
extern int fn_8004BBCC(u32 obj);
extern int fn_1_3FC38(void);
extern s32 fn_80063094(s32 arg0, s32 arg1, s32 arg2);
extern s32 fn_80065D70(u32 idx);

typedef struct {
    ADXTHandle *unk_0;
    ADXTHandle *unk_4;
} fn_1_A24CC_AdxPair;

typedef struct {
    u8 pad_0[0x38];
    fn_1_A24CC_AdxPair *unk_38;
    u8 pad_3C[0x748 - 0x3C];
    u8 unk_748;
    u8 unk_749;
    u8 pad_74A[0x7A4 - 0x74A];
    u32 unk_7A4;
} fn_1_A24CC_SoundState;

typedef struct {
    u8 pad_0[0x118];
    s32 unk_118;
} fn_1_A24CC_Entry;

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[7];
    u8 ids[30];
    fn_1_A24CC_Entry *entries[30];
    u8 pad_A4[0x14C0 - 0xA4];
} fn_1_A24CC_RaceInfo;


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
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u16 lbl_1_bss_6EAB4_fill_6EAC4;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
fn_1_A24CC_AdxPair *fzgx_obj_lbl_1_bss_6EAD0;
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
}
#pragma section code_type ".text"

void fn_1_A24CC(void) {
    
    fn_1_A24CC_RaceInfo info;
    fn_1_A24CC_Entry *entry;
    s32 id;
    u32 i;
    u8 first;
    s8 slot;
    u32 flags;

    if (*(s16 *)&lbl_1_bss_960 != 2 && *(s16 *)&lbl_1_bss_960 != 9) {
        return;
    }
    if (fn_1_3F0C8() != 0x29) {
        return;
    }
    fn_1_3EF14(&info);
    if (lbl_1_bss_8CA24 != 0 || lbl_1_bss_8B5F0 != 0 || lbl_1_bss_8B5F1 != 0 || info.unk_5 == 3 ||
        info.unk_5 == 4 || info.unk_4 == 1) {
        return;
    }
    if ((s32)fn_1_F2F34() != 0) {
        return;
    }

    first = info.unk_6;
    for (i = 0; i < 30; i++) {
        id = info.ids[i];
        flags = fn_1_864E8(id);
        entry = info.entries[i];
        if (!(flags & 0x200)) {
            break;
        }
    }

    if (first > 0x2D) {
        slot = -1;
    } else {
        slot = (s8)lbl_1_rodata_43B4[first * 4];
    }

    if (id == 0xFF) {
        return;
    }
    if (entry->unk_118 == (u8)(info.unk_4 - 1) && fzgx_obj_lbl_1_bss_6F1E0 != 0 && lbl_1_bss_6F1E1 != 0 && slot != -1) {
        ADXT_Stop(fzgx_obj_lbl_1_bss_6EAD0->unk_0);
        ADXT_Pause(fzgx_obj_lbl_1_bss_6EAD0->unk_4, 0);
        flags = lbl_1_bss_6F23C;
        lbl_1_bss_6F1E1 = 0;
        lbl_1_bss_6F23C = flags & ~0x20;
    }
    fzgx_obj_lbl_1_bss_6F1E0 = 0;
}
/* fzgx:end fn_1_A24CC */

/* fzgx:begin fn_1_A266C noprologue */
#include "types.h"
#include "sofdec/sj.h"

/* begin sofdec/adxt.h (deltawave784/fzgx, CC0) */
#ifndef SOFDEC_ADXT_H
#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (deltawave784/fzgx, CC0) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

CHECK_OFFSET(ADXTHandle, decoder, 0x4);
CHECK_OFFSET(ADXTHandle, output_volume, 0x40);
CHECK_OFFSET(ADXTHandle, error_code, 0x60);
CHECK_OFFSET(ADXTHandle, stream_loop_enabled, 0x6C);
CHECK_OFFSET(ADXTHandle, amplifier, 0x74);
CHECK_OFFSET(ADXTHandle, linked_stream_controller, 0x94);
CHECK_OFFSET(ADXTHandle, playback_time, 0x9C);
CHECK_OFFSET(ADXTHandle, pending_file_sectors, 0xBC);
CHECK_SIZE(ADXTHandle, 0xC0);

#endif

/* end sofdec/adxt.h */

typedef struct {
    ADXTHandle *unk_0;
    ADXTHandle *unk_4;
} fn_1_A266C_Streams;

typedef struct {
    u8 pad_0[0x2];
    s8 unk_2;
    u8 pad_3[0x11];
} fn_1_A266C_FadeEntry;

extern void fn_1_A2E24(u32, u32, s32);
extern void fn_1_A2DF4(s32, u32, s32);
extern void fn_1_A4DF4(void);
extern void fn_8004BF0C(ADXTHandle *, s32);
extern void ADXT_Stop(ADXTHandle *);
extern s32 fn_800672E4(u32, u32);

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
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;                 /* fade flags */
u16 lbl_1_bss_6EAB4__fzgx_offset_4;
u16 lbl_1_bss_6EAB4__fzgx_offset_6;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;           /* stream 0 fade step */
f32 lbl_1_bss_6EAB4__fzgx_offset_C;           /* stream 1 fade step */
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
u8 fzgx_obj_lbl_1_bss_6EAC6;
u8 lbl_1_bss_6EAC6__fzgx_offset_1;
u32 lbl_1_bss_6EAC6__fzgx_offset_2;
u32 lbl_1_bss_6EAC6__fzgx_offset_6;
fn_1_A266C_Streams *fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0__fzgx_offset_4;
u8 lbl_1_bss_6EAD0__fzgx_offset_8;
u8 lbl_1_bss_6EAD0__fzgx_offset_9;
u16 lbl_1_bss_6EAD0__fzgx_offset_A;
u32 lbl_1_bss_6EAD0__fzgx_offset_C[447];
u8 lbl_1_bss_6F1D8;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1DA;
u32 lbl_1_bss_6F1DC;
u8 lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
fn_1_A266C_FadeEntry fzgx_obj_lbl_1_bss_6F1E4[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_50[5];
u8 lbl_1_bss_6F239;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
u8 lbl_1_bss_6F23C[7];
u8 lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244;
u8 lbl_1_bss_6F244__fzgx_offset_1;
u8 lbl_1_bss_6F244__fzgx_offset_2;
u8 lbl_1_bss_6F244__fzgx_offset_3;
u8 lbl_1_bss_6F244__fzgx_offset_4[4];         /* per-channel volume floor */
u32 lbl_1_bss_6F244__fzgx_offset_8[30];
u8 lbl_1_bss_6F2C4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u8 lbl_1_bss_6F2D8[0x3E];
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
u8 fzgx_obj_lbl_1_bss_6F31A;                  /* fade paused */
u8 lbl_1_bss_6F31A__fzgx_offset_1;
s16 lbl_1_bss_6F31A__fzgx_offset_2[2];        /* fade-in target volumes */
f32 lbl_1_bss_6F31A__fzgx_offset_6;           /* stream 0 fade volume */
f32 lbl_1_bss_6F31A__fzgx_offset_A;           /* stream 1 fade volume */

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
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6EAB2;
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
    s = *(u8 *)&lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1DA;
    s = *(u8 *)&lbl_1_bss_6F1DC;
    s = *(u8 *)&lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_50;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F243;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F244;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_3;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
}
#pragma section code_type ".text"

void fn_1_A266C(void) {
    s32 vol;
    u8 fadedOut;
    u32 i;
    s8 level;
    u8 silent;
    s32 d;
    u32 flags;

    if (fzgx_obj_lbl_1_bss_6EAD0 == 0) {
        return;
    }

    /* stream 0 fade in */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 1) && fzgx_obj_lbl_1_bss_6EAD0->unk_0 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        vol = (s32)(lbl_1_bss_6F31A__fzgx_offset_6 += lbl_1_bss_6EAB4__fzgx_offset_8);
        if (lbl_1_bss_6F31A__fzgx_offset_2[0] > vol) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_0, vol);
        } else {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_0, lbl_1_bss_6F31A__fzgx_offset_2[0]);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~1;
        }
    }
    /* stream 1 fade in (retail reads the stream 0 fader for the volume) */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 2) && fzgx_obj_lbl_1_bss_6EAD0->unk_4 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        lbl_1_bss_6F31A__fzgx_offset_A += lbl_1_bss_6EAB4__fzgx_offset_C;
        vol = (s32)lbl_1_bss_6F31A__fzgx_offset_6;
        if (lbl_1_bss_6F31A__fzgx_offset_2[1] > vol) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_4, vol);
        } else {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_4, lbl_1_bss_6F31A__fzgx_offset_2[1]);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~2;
        }
    }
    /* stream 0 fade out */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 4) && fzgx_obj_lbl_1_bss_6EAD0->unk_0 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        vol = (s32)(lbl_1_bss_6F31A__fzgx_offset_6 -= lbl_1_bss_6EAB4__fzgx_offset_8);
        if (vol > -400) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_0, vol);
        } else {
            ADXT_Stop(fzgx_obj_lbl_1_bss_6EAD0->unk_0);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~4;
        }
    }
    /* stream 1 fade out */
    if ((fzgx_obj_lbl_1_bss_6EAB4 & 8) && fzgx_obj_lbl_1_bss_6EAD0->unk_4 != 0 && fzgx_obj_lbl_1_bss_6F31A == 0) {
        vol = (s32)(lbl_1_bss_6F31A__fzgx_offset_A -= lbl_1_bss_6EAB4__fzgx_offset_C);
        if (vol > -400) {
            fn_8004BF0C(fzgx_obj_lbl_1_bss_6EAD0->unk_4, vol);
        } else {
            ADXT_Stop(fzgx_obj_lbl_1_bss_6EAD0->unk_4);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~8;
        }
    }

    flags = fzgx_obj_lbl_1_bss_6EAB4;
    if (!(flags & 0x20)) {
        return;
    }
    fadedOut = 0;
    silent = 0;
    if (flags & 0x80) {
        for (i = 1; (s32)i < 4; i++) {
            d = fn_800672E4(i, 0xa0100000) - lbl_1_bss_6F244__fzgx_offset_4[i];
            if (d < 0) {
                d = 0;
            }
            fn_1_A2E24(i, 0xa0100000, d);
        }
        i = 1;
        silent = 1;
        fadedOut = 1;
        for (; (s32)i < 4; i++) {
            if (fn_800672E4(i, 0xa0100000) == 0) {
                silent++;
            }
        }
        fzgx_obj_lbl_1_bss_6F244 = 0;
    } else {
        for (i = 0; (s32)i < 4; i++) {
            d = fn_800672E4(i, 0xa0100000) - lbl_1_bss_6F244__fzgx_offset_4[i];
            if (d < 0) {
                d = 0;
            }
            fn_1_A2E24(i, 0xa0100000, d);
        }
        for (i = 0; (s32)i < 4; i++) {
            if (fn_800672E4(i, 0xa0100000) == 0) {
                silent++;
            }
        }
    }

    if (fzgx_obj_lbl_1_bss_6EAC6) {
        for (i = 0; (s32)i < 4; i++) {
            /* fzgx-allow: preserve the signed byte read before the narrowing subtraction. */
            level = *(volatile s8 *)&fzgx_obj_lbl_1_bss_6F1E4[i].unk_2;
            level -= 2;
            if (level < 0) {
                level = 0;
                fn_1_A2DF4(i, 0xa6000000, 0);
                fadedOut++;
            }
            fn_1_A2DF4(i, 0xa5100000, level);
            fzgx_obj_lbl_1_bss_6F1E4[i].unk_2 = level;
        }
        if (fadedOut >= 4) {
            fn_1_A2E24(0x10, 0xa0000400, 0);
        }
    } else {
        fadedOut = 4;
    }

    if (silent >= 4 && fadedOut >= 4) {
        fn_1_A2E24(0x10, 0xa0000300, 0);
        fn_1_A2E24(0x10, 0xa0000100, 0);
        fn_1_A2E24(0x10, 0xa0100000, 0x7f);
        fzgx_obj_lbl_1_bss_6EAB4 &= ~0x20;
        fn_1_A4DF4();
    }
}
/* fzgx:end fn_1_A266C */

/* fzgx:begin fn_1_A2A70 noprologue */
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
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4;
u32 lbl_1_bss_6EAB4__fzgx_offset_4;
f32 lbl_1_bss_6EAB4__fzgx_offset_8;
f32 lbl_1_bss_6EAB4__fzgx_offset_C;
u16 lbl_1_bss_6EAB4__fzgx_offset_10;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6__fzgx_offset_2[2];
void **fzgx_obj_lbl_1_bss_6EAD0;
u32 lbl_1_bss_6EAD0__fzgx_offset_4[449];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
u32 fzgx_obj_lbl_1_bss_6F1E4[21];
u8 lbl_1_bss_6F1E4__fzgx_offset_54;
u8 lbl_1_bss_6F239;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C__fzgx_offset_4;
u8 lbl_1_bss_6F23C__fzgx_offset_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244__fzgx_offset_0;
u8 lbl_1_bss_6F244__fzgx_offset_4[4];
u32 lbl_1_bss_6F244__fzgx_offset_8[30];
u8 lbl_1_bss_6F2C4;
u8 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u32 lbl_1_bss_6F2D8[15];
u16 lbl_1_bss_6F2D8__fzgx_offset_3C;
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
u16 lbl_1_bss_6F31A__fzgx_offset_0;
u32 lbl_1_bss_6F31A__fzgx_offset_2;
f32 lbl_1_bss_6F31A__fzgx_offset_6;
f32 lbl_1_bss_6F31A__fzgx_offset_A;
u32 lbl_1_bss_6F31A__fzgx_offset_E[31];

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
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6EAB4__fzgx_offset_10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&lbl_1_bss_6EAD0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4__fzgx_offset_54;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F23C__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F2C5_fill_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F2D8__fzgx_offset_3C;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA98_gap_6F318;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_6F31A__fzgx_offset_E;
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
            lbl_1_bss_6EAB4__fzgx_offset_8 = lbl_1_rodata_446C / (f32)arg1;
        }
        if (arg0 & 2) {
            fzgx_obj_lbl_1_bss_6EAB4 &= ~8;
            lbl_1_bss_6EAB4__fzgx_offset_C = lbl_1_rodata_446C / (f32)arg1;
        }
        if (arg0 & 4) {
            lbl_1_bss_6F31A__fzgx_offset_6 = (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[0]);
            v1 = lbl_1_rodata_446C + (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[0]);
            fzgx_obj_lbl_1_bss_6EAB4 &= ~1;
            lbl_1_bss_6EAB4__fzgx_offset_8 = v1 / (f32)arg1;
        }
        if (arg0 & 8) {
            lbl_1_bss_6F31A__fzgx_offset_A = (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[1]);
            v1 = lbl_1_rodata_446C + (f32)(s32)fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[1]);
            lbl_1_bss_6EAB4__fzgx_offset_C = v1 / (f32)arg1;
            if (arg0 & 0x40) {
                v0 = (s32)(fn_8004BED0((*(void ** volatile *)&(fzgx_obj_lbl_1_bss_6EAD0)) /* Retail reloads this field. */[1]) + 600) / arg1;
                loc_8 = (s32)(lbl_1_bss_6EAB4__fzgx_offset_C = (f32)v0);
                lbl_1_bss_6EAB4__fzgx_offset_C = (f32)loc_8;
                if (lbl_1_bss_6EAB4__fzgx_offset_C < lbl_1_rodata_4470) {
                    lbl_1_bss_6EAB4__fzgx_offset_C = lbl_1_rodata_4470;
                }
            }
            fzgx_obj_lbl_1_bss_6EAB4 &= ~2;
        }
        i = 0;
        v11 = lbl_1_bss_6F244__fzgx_offset_4;
        for (; i < 4; i++) {
            v0_2 = fn_800672E4(i, 0xA0100000) / arg1;
            if (v0_2 <= 0) v0_2 = 0;
            *v11++ = v0_2 + 1;
        }
        if (lbl_1_bss_6EAB4__fzgx_offset_8 < lbl_1_rodata_4474)
            lbl_1_bss_6EAB4__fzgx_offset_8 = lbl_1_rodata_4470;
        if (lbl_1_bss_6EAB4__fzgx_offset_C < lbl_1_rodata_4474)
            lbl_1_bss_6EAB4__fzgx_offset_C = lbl_1_rodata_4470;
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

/* fzgx:begin fn_1_A2FC8 noprologue */
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
u32 lbl_1_bss_6F244__fzgx_offset_10[28];
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
    s = *(u8 *)&lbl_1_bss_6F244__fzgx_offset_10;
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

/* fzgx:begin fn_1_A3654 noprologue */
#include "types.h"

typedef struct SoundCarEntry {
    u8 unk_0;
    u8 unk_1;
    u8 active;
    u8 pad_3[0x11];
} SoundCarEntry;

typedef struct SoundCar {
    u8 pad_0[0x4B0];
    s16 unk_4B0;
} SoundCar;

extern f32 fn_1_8652C(void *);
extern u32 fn_1_864E8(void *);
extern u32 fn_1_864FC(void *);
extern SoundCar *fn_1_86254(void *);
extern s32 fn_80067898(u32);
extern u32 lbl_801A66C8[];

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_6EA98[4];
u8 fzgx_pool_lbl_1_bss_6EA9C_pad[0x73C];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 fzgx_pool_lbl_1_bss_6F1D9_fill;
u16 fzgx_pool_lbl_1_bss_6F1DA_fill;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
u16 fzgx_pool_lbl_1_bss_6F1E2_fill;
SoundCarEntry fzgx_pool_lbl_1_bss_6F1E4[11];
u32 fzgx_pool_lbl_1_bss_6F1E4_fill[2];
u32 lbl_1_bss_6F2C8[4];
u8 fzgx_obj_lbl_1_bss_6F2D8[0x3E];
u16 fzgx_pool_lbl_1_bss_6F316_fill;
u32 fzgx_pool_lbl_1_bss_6F318_fill[5];
s16 fzgx_pool_lbl_1_bss_6F32C[4];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6EA9C_pad;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F1D9_fill;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F1E2_fill;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F1E4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F1E4_fill;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F2D8;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F316_fill;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F318_fill;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6F32C;
}
#pragma section code_type ".text"

#define PLAY_SE(id)                                                                 \
    if (fzgx_obj_lbl_1_bss_6F1D8 == 0 && fzgx_obj_lbl_1_bss_6F1DC <= 45) {          \
        fn_80067898(id);                                                            \
    }

#define ABS(v) __abs(v)

#pragma opt_propagation off
void fn_1_A3654(void *player, u32 id) {
    f32 speed;
    u32 flags;
    u32 flags2;
    SoundCar *obj;
    void *car = player;

    speed = fn_1_8652C(car);
    flags = fn_1_864E8(car);
    flags2 = fn_1_864FC(car);

    if (fzgx_pool_lbl_1_bss_6F1E4[id].active != 0) {
        if ((flags & 0x8) && !(lbl_1_bss_6F2C8[id] & 0x8)) {
            PLAY_SE(0xA9090E00);
        } else if ((flags & 0x20000) && !(lbl_1_bss_6F2C8[id] & 0x20000)) {
            PLAY_SE(0xA9091D00);
        } else if ((flags & 0x80) && !(lbl_1_bss_6F2C8[id] & 0x80) && !(flags & 0x200)) {
            PLAY_SE(0xA9091100);
        }

        if (flags & 0x100000) {
            PLAY_SE(0xA9091300);
        } else if (flags & 0x80000) {
            PLAY_SE(0xA9091400);
        }

        if (flags & 0x200) {
            return;
        }

        if ((flags & 0x10000) && !(lbl_1_bss_6F2C8[id] & 0x10000)) {
            PLAY_SE(0xA9091C00);
            PLAY_SE(0xA9091600);
        }

        obj = fn_1_86254(car);
        if (ABS((s32)obj->unk_4B0) >= 100 && fzgx_pool_lbl_1_bss_6F32C[id] == 0 && speed > 100.0f) {
            PLAY_SE(0xA9091B00);
            fzgx_pool_lbl_1_bss_6F32C[id] = obj->unk_4B0;
        } else if (ABS((s32)obj->unk_4B0) < 100 && fzgx_pool_lbl_1_bss_6F32C[id] != 0) {
            PLAY_SE(0xA9091C00);
            fzgx_pool_lbl_1_bss_6F32C[id] = 0;
        }
    }

    if ((flags & 0x80) && !(lbl_1_bss_6F2C8[id] & 0x80)) {
        PLAY_SE(0xA9091C00);
        PLAY_SE(0xA9091600);
        fzgx_pool_lbl_1_bss_6F32C[id] = 0;
    }

    if ((flags2 & 0x10) && ((lbl_801A66C8[0] + 1) & 7) == 0) {
        PLAY_SE(0xA9092E00);
        PLAY_SE(0xA9091200);
    }
}
/* fzgx:end fn_1_A3654 */

/* fzgx:begin fn_1_A3A1C noprologue */
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
    u8 unk_74C[0xE0];
    s8 unk_82C;
    u8 pad_82D[0xA3];
    CounterEntry unk_8D0[0x100]; /* per-sound {busy count, idle count} */
} SoundState;

extern SoundState lbl_1_bss_6EA98;
extern u32 fn_1_864E8(s32 arg0);
extern f32 fn_1_8652C(s32 arg0);
extern const f32 lbl_1_rodata_454C;
extern void fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80067898(u32 arg0);
#pragma opt_propagation off /* as the other sound.c blocks */
void fn_1_A3A1C(void) {
    SoundState *st = (SoundState *)&lbl_1_bss_6EA98;
    u8 *row;
    s8 i;
    s32 id;
    u8 *pair;
    u8 *slot;
    u32 flags;
    s32 off;
    u8 volume;
    s32 level;

    row = &st->unk_74C[0];
    i = 0;
    while (i < *(s8 *)((u8 *)st + 0x82C)) {
        id = row[1];
        flags = fn_1_864E8(id);
        if ((flags & 0x10) && fn_1_8652C(id) > lbl_1_rodata_454C) {
            volume = row[2];
            if (volume != 0) {
                off = id * 2;
                slot = (u8 *)&st->unk_8D0[0];
                if ((s8)slot[off] == 0) {
                    if (flags & 0x200) {
                        fn_80067344(1, 0x10, 0xB0270000, volume);
                        if (st->unk_740 == 0 && st->unk_744 <= 0x2D) {
                            fn_80067898(0xA9090700);
                        }
                    } else {
                        level = volume + 50;
                        level = level < 1 ? 1 : level > 127 ? 127 : level;
                        fn_80067344(1, 0x10, 0xB0270000, (u8)level);
                        if (st->unk_740 == 0 && st->unk_744 <= 0x2D) {
                            fn_80067898(0xA9090800);
                        }
                    }
                }
            }
            off = id * 2;
            slot = (u8 *)&st->unk_8D0[0];
            slot += off;
            slot[0]++;
            slot[1] = 0;
            if ((s8)slot[0] > 6) {
                slot[0] = 0;
            }
        } else {
            off = id * 2;
            pair = (u8 *)&st->unk_8D0[0];
            pair += off;
            slot = pair + 1;
            slot[0]++;
            if ((s8)slot[0] > 60) {
                pair[0] = 0;
                slot[0] = 60;
            }
        }
        row += 0x14;
        i++;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_A3A1C */

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

/* fzgx:begin fn_1_A3D5C noprologue */
#include "types.h"
#include "dolphin/os/OSFastCast.h"

typedef struct {
    f32 x, y, z;
} SndVec;

extern s16 camera_get_mode(void);
extern void fn_1_862D4(void *, SndVec *);
extern s32 fn_1_5910(void);
extern void fn_1_681C(u32, SndVec *);
extern f32 fn_1_8652C(void *);
extern s32 fn_1_58C4(void);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(SndVec *, SndVec *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern f32 lbl_8006D188(s32);
extern u32 OSGetSoundMode(void);

#pragma pool_data off

#define ABS(x) __abs(x)
#define SQ(x) ((x) * (x))
static inline f32 CLAMP(f32 x, f32 lo, f32 hi) {
    if (x < lo) {
        return lo;
    }
    if (x > hi) {
        return hi;
    }
    return x;
}

u8 fn_1_A3D5C(void *obj, s8 *pan, s8 *span, u8 *vol) {
    s32 other;
    f32 distSq;
    f32 fade;
    f32 level;
    f32 balance;
    f32 t;
    u8 ret;
    SndVec local;
    SndVec pos;
    SndVec cam;
    s16 pitch;
    s16 yaw;

    other = camera_get_mode();
    fn_1_862D4(obj, &pos);
    fn_1_681C((u8)fn_1_5910(), &cam);
    {
        f32 dz, dy, dx;
        /* load-then-subtract keeps each load in its difference's register (retail: fsubs f3, f3, f0) */
        dx = cam.x;
        dx -= pos.x;
        dy = cam.y;
        dy -= pos.y;
        dz = cam.z;
        dz -= pos.z;
        distSq = dx * dx;
        distSq += dy * dy;
        distSq += dz * dz;
    }
    if (distSq > 90000.0f) {
        *pan = 0;
        *span = 0;
        *vol = 0;
        return 0;
    }

    lbl_8006DCA4();
    lbl_8006E1B0(&pos, &local);
    fn_8006EF10(&local, &pitch, &yaw);

    balance = fn_1_8652C(obj);
    if (other != -1) {
        t = 0.001f * (balance - fn_1_8652C((void *)other));
        t = (t < -1.0f) ? -1.0f : ((t > 1.0f) ? 1.0f : t);
        if (t < 0.0f) {
            balance = 1.0f - lbl_8006D188((s16)(0.5f * (32768.0f * -t)));
        } else {
            balance = 1.0f + lbl_8006D188((s16)(0.5f * (32768.0f * t)));
        }
    } else {
        balance = 1.0f;
    }

    level = 0.5f * (32768.0f * (distSq / 90000.0f));
    level = lbl_8006D188((s16)(__OSf32tou16(level) + 0x4000));
    level = CLAMP(127.0f * (balance * (level * level)), 0.0f, 127.0f);
    fade = 127.0f * CLAMP(1.0f - distSq / 5625.0f, 0.0f, 1.0f);

    switch (fn_1_58C4()) {
    case 1:
        break;
    case 2:
        level *= 0.9f;
        fade *= 0.9f;
        break;
    case 3:
        level *= 0.85f;
        fade *= 0.85f;
        break;
    case 4:
        level *= 0.8f;
        fade *= 0.8f;
        break;
    }

    ret = __OSf32tou8(level);
    *vol = __OSf32tou8(fade);

    if (ABS(yaw) < 0x4000) {
        *pan = (s8)(0.0039f * (f32)(-yaw));
    } else if (yaw > 0) {
        *pan = (s8)(0.0039f * (f32)(-(0x8000 - yaw)));
    } else {
        *pan = (s8)(0.0039f * (f32)(-(-0x8000 - yaw)));
    }
    *span = (s8)(0.0039 * (ABS(yaw) - 0x4000));

    *pan = (*pan < -64) ? -64 : ((*pan > 63) ? 63 : *pan);
    *span = (*span < -64) ? -64 : ((*span > 63) ? 63 : *span);

    if (OSGetSoundMode() == 0) {
        *pan = 0;
    }
    return ret;
}
/* fzgx:end fn_1_A3D5C */

/* fzgx:begin fn_1_A4268 noprologue */
#include "types.h"
#include "dolphin/os/OSFastCast.h"

/* The sound TU's .bss (retail lbl_1_bss_6EA98): retail addresses every
   object below off one section base register, so they are defined here in
   retail order. */
typedef struct {
    u8 flags;
    u8 id;
    u8 unk2;
    u8 vol;
    u8 pad4[0x10];
} fn_1_A4268_Chan;

static u8 fzgx_obj_lbl_1_bss_6EA98[0x4];
static u8 fzgx_pool_obj_sound_pad4[0x2A];
static u8 fzgx_pool_obj_sound_enabled;       /* 0x2E */
static u8 fzgx_pool_obj_sound_pad30[0x710];
static u8 fzgx_pool_obj_sound_740;           /* 0x740 */
static u32 fzgx_pool_obj_sound_744;          /* 0x744 */
static u8 fzgx_pool_obj_sound_pad748[0x4];
static fn_1_A4268_Chan fzgx_pool_obj_sound_chans[4]; /* 0x74C */
static u8 fzgx_pool_obj_sound_active[0x94];  /* 0x79C */
static u32 fzgx_pool_obj_sound_mode[0x37];   /* 0x830 */
static f32 fzgx_pool_obj_sound_level[4];     /* 0x90C */

extern void fzgx_sink(void *);

#pragma section code_type ".fzgxpool"
void fzgx_bss_order(void) {
    fzgx_sink(fzgx_obj_lbl_1_bss_6EA98);
    fzgx_sink(fzgx_pool_obj_sound_pad4);
    fzgx_sink(&fzgx_pool_obj_sound_enabled);
    fzgx_sink(fzgx_pool_obj_sound_pad30);
    fzgx_sink(&fzgx_pool_obj_sound_740);
    fzgx_sink(&fzgx_pool_obj_sound_744);
    fzgx_sink(fzgx_pool_obj_sound_pad748);
    fzgx_sink(fzgx_pool_obj_sound_chans);
    fzgx_sink(fzgx_pool_obj_sound_active);
    fzgx_sink(fzgx_pool_obj_sound_mode);
    fzgx_sink(fzgx_pool_obj_sound_level);
}
#pragma section code_type ".text"

extern f32 fn_1_8652C(void *);
extern const f32 lbl_1_rodata_4474;
extern const f32 lbl_1_rodata_454C;
extern const f32 lbl_1_rodata_4588;
extern const f32 lbl_1_rodata_458C;
extern const f32 lbl_1_rodata_4590;
extern const f32 lbl_1_rodata_4564;
extern s32 fn_1_58C4(void);
extern s32 fn_80063094(s32, void *, s32);
extern s32 fn_80067344(u32, u32, u32, u32);
extern s32 fn_80067898(u32);
extern u32 fn_1_864E8(void *);
extern s32 fn_1_3F864(void);
extern void *fn_1_86254(void *);

/* Number of the car's four units with bit 2 set. */
#define FN_1_A4268_COUNT(n, car)                                   \
    n = 0;                                                         \
    if ((*(u32 *)((u8 *)(car) + 0x244) & 0x4) != 0) { n = 1; }     \
    if ((*(u32 *)((u8 *)(car) + 0x2A0) & 0x4) != 0) { n++; }       \
    if ((*(u32 *)((u8 *)(car) + 0x2FC) & 0x4) != 0) { n++; }       \
    if ((*(u32 *)((u8 *)(car) + 0x358) & 0x4) != 0) { n++; }

static inline u8 fn_1_A4268_CountUnits(void *id) {
    u8 count = 0;
    void *car = fn_1_86254(id);
    u32 unit;
    for (unit = 0; unit < 4; unit++) {
        if ((*(u32 *)((u8 *)car + 0x244 + unit * 0x5C) & 0x4) != 0) {
            count++;
        }
    }
    return count;
}

void fn_1_A4268(void *arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 v0;
    f32 v1;
    u32 j;
    u8 v23;
    u32 v19;
    u8 v12;
    u8 v13;
    u8 v4;
    u8 v5;
    u8 v7;
    u32 i;
    void *v14;
    f32 v15;
    u8 v27;
    s8 v30;
    s32 v31;
    f32 v40;
    u8 loc_C;
    u8 loc_8;
    s32 t0;
    void *t2;

    v12 = 0;
    v13 = 0;
    t0 = fn_1_58C4();
    if (fzgx_pool_obj_sound_enabled == 0) {
        return;
    }
    v4 = 0;
    v5 = 0;
    if ((u32)t0 > 1) {
        for (i = 0; i < (u32)t0; i++) {
            v0 = fzgx_pool_obj_sound_chans[i].id;
            if ((u32)v0 != 255 && (fn_1_864E8((void *)v0) & 0x2) != 0) {
                v4 = i;
                break;
            }
        }
        for (j = 0; j < (u32)t0; j++) {
            v0 = fzgx_pool_obj_sound_chans[j].id;
            if ((u32)v0 != 255) {
                v7 = 0;
                t2 = fn_1_86254((void *)v0);
                for (v31 = 0; v31 < 4; v31++) {
                    if ((*(u32 *)((u8 *)t2 + 0x244 + v31 * 0x5C) & 0x4) != 0) {
                        v7++;
                    }
                }
                if (v7 != 0) {
                    v5 = j;
                    break;
                }
            }
        }
    }
    if (v4 == arg2) {
        v12 = 1;
    }
    if (v5 == arg2) {
        v13 = 1;
    }
    v14 = fn_1_86254(arg0);
    if (v12 != 0) {
        if (fn_1_8652C(arg0) > lbl_1_rodata_454C && fn_1_3F864() != 0 && (arg1 & 0x880) == 0 && (arg1 & 0x2) != 0) {
            v15 = *(f32 *)((u8 *)v14 + 384);
            if (v15 < lbl_1_rodata_4474) {
                v1 = lbl_1_rodata_4588 - (f32)(lbl_1_rodata_458C * v15);
            } else {
                v1 = lbl_1_rodata_4588 + (f32)(lbl_1_rodata_4590 * v15);
            }
            loc_C = __OSf32tou8(v1);
            if (fzgx_pool_obj_sound_enabled != 0) {
                fn_80063094(6, (void *)0xA6000000, loc_C); /* fzgx-allow: A2 sound command code */
            }
            if (fzgx_pool_obj_sound_enabled != 0) {
                fn_80063094(6, (void *)0xA5100000, arg3 & 0xFF); /* fzgx-allow: A2 sound command code */
            }
            fzgx_pool_obj_sound_chans[arg2].flags |= 8;
        }
        v0 = fzgx_pool_obj_sound_mode[arg2];
        if ((v0 & 0x2) == 0 || ((arg1 & 0x80) != 0 && (v0 & 0x80) == 0) || ((arg1 & 0x800) != 0 && (v0 & 0x800) == 0)) {
            if ((fzgx_pool_obj_sound_chans[arg2].flags & 0x8) != 0) {
                if (fzgx_pool_obj_sound_enabled != 0) {
                    fn_80063094(6, (void *)0xA6000000, 0); /* fzgx-allow: A2 sound command code */
                }
                if (fzgx_pool_obj_sound_enabled != 0) {
                    fn_80063094(6, (void *)0xA5100000, 0); /* fzgx-allow: A2 sound command code */
                }
                fzgx_pool_obj_sound_chans[arg2].flags &= ~8;
            }
        }
    }
    v19 = (arg1 & 0x80);
    if (v19 != 0) {
        return;
    }
    FN_1_A4268_COUNT(v23, v14);
    if (v23 != 0) {
        v40 = lbl_1_rodata_4564 * fzgx_pool_obj_sound_level[(u32)arg0];
        loc_8 = __OSf32tou8(v40);
        v27 = fzgx_pool_obj_sound_chans[arg2].vol;
        if (v27 < loc_8) {
            v27++;
        } else if (v27 > loc_8) {
            v27--;
        }
        fzgx_pool_obj_sound_chans[arg2].vol = (v27 > 127) ? 127 : v27;
        if (fzgx_pool_obj_sound_active[arg2] == 0) {
            fn_80067344(1, 16, 0xB0270000, fzgx_pool_obj_sound_chans[arg2].unk2);
            if (fzgx_pool_obj_sound_740 == 0 && fzgx_pool_obj_sound_744 <= 45) {
                fn_80067898(0xA9092900);
            }
        }
        fzgx_pool_obj_sound_active[arg2] = v23;
    } else {
        v30 = (fzgx_pool_obj_sound_chans[arg2].vol = 0);
        if (v30 > 0) {
            v30--;
        }
        fzgx_pool_obj_sound_chans[arg2].vol = v30;
    }
    if (v13 == 0) {
        return;
    }
    if (v23 != 0) {
        v0 = (arg3 & 0xFF) + 50;
        arg3 = ((v0 < 1) ? 1 : ((v0 > 127) ? 127 : v0)) & 0xFF;
        if (v19 != 0 && (fzgx_pool_obj_sound_chans[arg2].flags & 0x10) != 0) {
            if (fzgx_pool_obj_sound_enabled != 0) {
                fn_80063094(7, (void *)0xA6000000, 0); /* fzgx-allow: A2 sound command code */
            }
            if (fzgx_pool_obj_sound_enabled != 0) {
                fn_80063094(7, (void *)0xA5100000, 0); /* fzgx-allow: A2 sound command code */
            }
            fzgx_pool_obj_sound_chans[arg2].flags &= ~16;
            return;
        }
        v27 = fzgx_pool_obj_sound_chans[arg2].vol;
        if (fzgx_pool_obj_sound_enabled != 0) {
            fn_80063094(7, (void *)0xA6000000, v27); /* fzgx-allow: A2 sound command code */
        }
        if (fzgx_pool_obj_sound_enabled != 0) {
            fn_80063094(7, (void *)0xA5100000, arg3); /* fzgx-allow: A2 sound command code */
        }
        fzgx_pool_obj_sound_chans[arg2].flags |= 16;
    } else if ((fzgx_pool_obj_sound_chans[arg2].flags & 0x10) != 0) {
        if (fzgx_pool_obj_sound_enabled != 0) {
            fn_80063094(7, (void *)0xA6000000, 0); /* fzgx-allow: A2 sound command code */
        }
        if (fzgx_pool_obj_sound_enabled != 0) {
            fn_80063094(7, (void *)0xA5100000, 0); /* fzgx-allow: A2 sound command code */
        }
        fzgx_pool_obj_sound_chans[arg2].flags &= ~16;
    }
}
/* fzgx:end fn_1_A4268 */

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

/* fzgx:begin fn_1_A5594 noprologue */
#include "types.h"
#include "dolphin/os/OSFastCast.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "rel/main_rel/sound.h"

/* begin game/main_rel/car_test_types.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

typedef struct {
    u8 pad_0[0x14c];
    Fn183D28Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

typedef struct {
    u8 pad_0[0x8];
    Fn183D28Vec3 dir;
    f32 radius;
} Fn183D28Target;

typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

typedef struct {
    u8 pad_0[0x320];
    s16 index;
    u8 pad_322[0xa];
    Fn183D28Body *body;
    Fn183D28Entry entries[6];
    u8 pad_378[0x18];
    u32 flags;
    u8 pad_394[0xc];
    Fn183D28Alt *alt;
} Fn183D28Car;

typedef struct {
    u32 flags;
    u8 pad_4[0x5];
    u8 count;
    u8 pad_A[0x14AE];
    f64 pad_14B8;
} CarTestInfo;

typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

extern s8 fn_1_84408(CarTestCar *);
extern void fn_1_8E084(CarTestCar *, u32 *, s32);
extern s8 fn_1_84124(Fn183D28Car *, s8, s8, u8 *);
extern void lbl_8006DFE8(Fn183D28Vec3 *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern s8 fn_1_84644(Fn183D28Body *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */

extern s32 fn_1_5910(void);
extern void fn_1_681C(u32, u32 *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern u32 OSGetSoundMode(void);
extern s32 fn_80067344(u32, u32, u32, u32);
extern s32 fn_80067898(u32);

extern const f32 lbl_1_rodata_48C4; /* 250000.0f */
extern const f32 lbl_1_rodata_4470; /* 1.0f */
extern const f32 lbl_1_rodata_4474; /* 0.0f */
extern const f32 lbl_1_rodata_4564; /* 127.0f */
extern const f32 lbl_1_rodata_4578; /* 0.0039f */

static inline f32 clamp_value(f32 x, f32 hi, f32 lo)
{
    return x < lo ? lo : (x > hi ? hi : x);
}

void fn_1_A5594(u32 arg0, Fn183D28Vec3 *pos)
{
    Fn183D28Vec3 rel;
    f32 listener[3];
    s16 dist;
    s16 angle;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 scaled;
    struct { f32 value; } distance;
    f32 t;
    u8 vol;
    s8 raw;
    s8 pan;

    fn_1_681C((u8)fn_1_5910(), (u32 *)listener);
    dx = listener[0];
    dx = dx - pos->x;
    dy = listener[1] - pos->y;
    dz = listener[2] - pos->z;
    distance.value = dx * dx;
    distance.value = dy * dy + distance.value;
    distance.value = dz * dz + distance.value;
    if (distance.value > lbl_1_rodata_48C4) {
        return;
    }
    lbl_8006DCA4();
    lbl_8006E1B0(pos, &rel);
    fn_8006EF10(&rel, &dist, &angle);
    {
        struct { f32 value; } hi;
        hi.value = lbl_1_rodata_4470;
        t = hi.value - distance.value / lbl_1_rodata_48C4;
        t = clamp_value(t, hi.value, lbl_1_rodata_4474);
    }
    /* retail: OSFastCast __OSf32tou8 (psq_st ..., 1, qr2; lbz) */
    scaled = lbl_1_rodata_4564 * t;
    vol = __OSf32tou8(scaled);
    if (__abs(angle) < 0x4000) {
        raw = lbl_1_rodata_4578 * -angle;
    } else if (angle > 0) {
        raw = lbl_1_rodata_4578 * -(0x8000 - angle);
    } else {
        raw = lbl_1_rodata_4578 * -(-0x8000 - angle);
    }
    pan = raw < -64 ? -64 : (raw > 63 ? 63 : raw);
    if (OSGetSoundMode() == 0) {
        pan = 0;
    }
    fn_80067344(1, 16, 0xB0270000, vol);
    fn_80067344(1, 16, 0xB02A0000, pan);
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 45) {
        fn_80067898(arg0);
    }
    fn_80067344(1, 16, 0xB02A0000, 0);
}
/* fzgx:end fn_1_A5594 */

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
