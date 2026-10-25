#include "types.h"

extern const f32 lbl_801A73A8;
extern const f32 lbl_801A73AC;
extern f32 lbl_801A6CA0;
extern f32 lbl_801A6CA4;
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
