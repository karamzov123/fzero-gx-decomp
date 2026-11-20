#include "types.h"


/* --- dol/fn_8006CCC8.c --- */
extern f64 lbl_801A73A0;
extern u32 lbl_801A7398;
extern u32 lbl_801A6CF4;
extern u32 lbl_801A6CAC;
extern u32 lbl_801A6CA8;
extern f32 lbl_801A6CA4;
extern f32 lbl_801A6CA0;

struct Fn8006CCC8Data {
    u8 pad0[0xe];
    u16 value_e;
    u16 value_10;
};

void fn_8006CCC8(void) {
    struct Fn8006CCC8Data *data;
    u16 value_e;
    u16 value_10;

    data = (struct Fn8006CCC8Data *)lbl_801A6CF4;
    lbl_801A6CAC = 0;
    lbl_801A6CA8 = lbl_801A7398;
    value_e = data->value_e;
    lbl_801A6CA4 = (f32)value_e;
    value_10 = data->value_10;
    lbl_801A6CA0 = (f32)value_10;
}

/* --- dol/fn_8006CD20.c --- */
/* --- dol/fn_8006CD20.c --- */
/* --- dol/fn_8006CD20.c --- */

void fn_8006CD20(f32 arg0, f32 arg1) {
    lbl_801A6CA4 = arg0;
    lbl_801A6CA0 = arg1;
}

/* --- dol/fn_8006CD2C.c --- */
void fn_8006CD2C(f32 *a, f32 *b) {
    *a = lbl_801A6CA4;
    *b = lbl_801A6CA0;
}

/* --- dol/fn_8006CD40.c --- */
f32 fn_8006CD40(f32 arg0) {
    f32 v0;
    v0 = lbl_801A6CA0;
    lbl_801A6CA0 = arg0;
    return v0;
}

/* --- dol/fn_8006CD50.c --- */
/* --- dol/fn_8006CD50.c --- */
extern const f32 lbl_801A73A8;
extern const f32 lbl_801A73AC;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_801A6D00;
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void lbl_8006D758(void);

void fn_8006CD50(void) {
    struct { u32 a[18]; } loc_8;
    f32 value;

    value = lbl_801A73A8;
    C_MTXOrtho((void *)&loc_8, value, lbl_801A6CA0, value, lbl_801A6CA4, value, lbl_801A73AC);
    fn_800737E4((void *)&loc_8, 1);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
}

/* --- dol/fn_8006CDA8.c --- */
typedef u32 (*fn_8006CDA8_Fn0)(void);

extern u32 fn_8006CE44(void);

void fn_8006CDA8(void) {
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    if (lbl_801A6CAC != 0) {
        ((fn_8006CDA8_Fn0)lbl_801A6CAC)();
    }
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8006CE44();
}
