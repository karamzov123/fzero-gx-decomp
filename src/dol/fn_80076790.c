#include "types.h"

struct fn_80076790_Mtx {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

struct fn_80076790_Vec {
    f32 x;
    f32 y;
    f32 z;
};

extern struct fn_80076790_Mtx *lbl_801A6D00;
extern u32 lbl_80094E20[];
extern u32 lbl_8019F14C[];
extern u8 lbl_801A3220[];
extern const f32 lbl_801A7480;
extern const f32 lbl_801A7488;
extern const f32 lbl_801A748C;
extern const f32 lbl_801A749C;
extern f32 lbl_801A74A0;

extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E14C(f32);

#pragma opt_common_subs off
void fn_80076790(void) {
    struct { u32 a[14]; } loc_38;
    u32 loc_2C[3];
    struct fn_80076790_Vec loc_20;
    struct fn_80076790_Vec loc_14;
    struct fn_80076790_Vec loc_8;
    f32 scale;

    loc_2C[0] = lbl_80094E20[0];
    loc_2C[1] = lbl_80094E20[1];
    loc_2C[2] = lbl_80094E20[2];
    lbl_8006DAEC();
    scale = lbl_801A74A0;
    loc_20 = *(struct fn_80076790_Vec *)lbl_8019F14C;
    loc_14 = *(struct fn_80076790_Vec *)&lbl_801A3220[0x50];
    loc_14.x = loc_14.x * scale;
    loc_14.y = loc_14.y * scale;
    loc_14.z = loc_14.z * scale;
    loc_20.x = lbl_801A748C * (loc_14.x + loc_20.x);
    loc_20.y = lbl_801A748C * (loc_14.y + loc_20.y);
    loc_20.z = lbl_801A748C * (loc_14.z + loc_20.z);
    loc_8.x = loc_20.x - loc_14.x;
    loc_8.y = loc_20.y - loc_14.y;
    loc_8.z = loc_20.z - loc_14.z;
    fn_8006F1F0(loc_2C, &loc_8, &loc_20);
    lbl_8006DB74(&loc_38);
    lbl_801A6D00->unk_C = lbl_801A748C;
    lbl_801A6D00->unk_10 = lbl_801A6D00->unk_10 * lbl_801A749C;
    lbl_801A6D00->unk_14 = lbl_801A6D00->unk_14 * lbl_801A749C;
    lbl_801A6D00->unk_18 = lbl_801A6D00->unk_18 * lbl_801A749C;
    lbl_801A6D00->unk_1C = lbl_801A748C;
    lbl_801A6D00->unk_20 = lbl_801A7480;
    lbl_801A6D00->unk_24 = lbl_801A7480;
    lbl_801A6D00->unk_28 = lbl_801A7480;
    lbl_801A6D00->unk_2C = lbl_801A7488;
    lbl_8006E14C(lbl_801A748C);
    GXLoadTexMtxImm(lbl_801A6D00, 67, 0);
    lbl_8006D758();
    lbl_801A6D00->unk_0 = lbl_801A7480;
    lbl_801A6D00->unk_8 = lbl_801A748C;
    lbl_801A6D00->unk_C = lbl_801A748C;
    lbl_801A6D00->unk_14 = lbl_801A7480;
    lbl_801A6D00->unk_28 = lbl_801A7480;
    lbl_801A6D00->unk_2C = lbl_801A7488;
    lbl_8006DFC4(&loc_38);
    GXLoadTexMtxImm(lbl_801A6D00, 70, 0);
    lbl_8006DB30();
    *(u32 *)(lbl_801A3220 + 0x44) = 1;
}
#pragma opt_common_subs reset

