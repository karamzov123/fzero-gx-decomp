#include "types.h"
#pragma opt_propagation off

/* --- dol/fn_80074D88.c --- */
struct fn_80074D88_lbl_8019F008 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x4];
    f32 unk_C;
};
extern f32 lbl_801A6D4C;
extern const f32 lbl_801A7480;
extern const f32 lbl_801A7488;
extern const f32 lbl_801A748C;
extern struct fn_80074D88_lbl_8019F008 lbl_8019F008[];
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_800736C0(u32, void *);
extern void lbl_8006DAEC(u32, u32);
extern u32 lbl_8019F040[];
extern u32 lbl_8019F158[];
extern f32 *lbl_801A6D00;
extern u32 lbl_801A6D50;
extern u32 lbl_801A6D54;
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80073B50(u32, s32, s32, s32, s32, s32, s32, u8, u8, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);

void fn_80074D88(u32 arg0, u32 arg1) {
    u32 v0;
    f32 *matrix;
    f32 v2;
    f32 v1;
    f32 half;
    f32 scale;
    struct { f32 a[6]; } loc_14;
    u32 loc_10;
    v0 = arg0;
    if (lbl_801A6D54 != 0) {
    lbl_8006DAEC(v0, arg1);
    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
    v1 = lbl_801A7488;
    lbl_801A6D00[8] = lbl_801A7480;
    lbl_801A6D00[9] = lbl_801A7480;
    lbl_801A6D00[10] = lbl_801A7480;
    matrix = (f32 *)(0xE0000000 + 0x00);
    matrix[3] = lbl_801A7480;
    matrix[7] = lbl_801A7480;
    matrix[11] = v1;
    GXLoadTexMtxImm(lbl_801A6D00, 45, 0);
    lbl_8006D758();
    v1 = lbl_801A748C;
    lbl_801A6D00[0] = (v1 * (-lbl_8019F008[0].unk_4));
    lbl_801A6D00[5] = (v1 * lbl_8019F008[0].unk_C);
    lbl_801A6D00[2] = v1;
    lbl_801A6D00[6] = v1;
    GXLoadTexMtxImm(lbl_801A6D00, 76, 0);
    lbl_8006D758();
    lbl_801A6D00[0] = lbl_801A748C;
    lbl_801A6D00[5] = lbl_801A748C;
    lbl_801A6D00[2] = lbl_801A748C;
    lbl_801A6D00[6] = lbl_801A748C;
    GXLoadTexMtxImm(lbl_801A6D00, 73, 0);
    lbl_8006DB30();
    fn_80073778(lbl_8019F158, *(u32 *)((u8 *)arg1 + 12));
    fn_800738E0(*(u32 *)((u8 *)arg1 + 16), *(u32 *)((u8 *)arg1 + 4), *(u32 *)(arg1 + 12));
    fn_800745A4(*(u32 *)(arg1 + 4), 0, 1, 45, 0, 73);
    scale = lbl_801A6D4C;
    v1 = lbl_801A7480;
    loc_14.a[0] = v1;
    loc_14.a[1] = v1;
    v2 = (*(f32 *)(arg0 + 60) * scale);
    loc_14.a[3] = v1;
    loc_14.a[5] = v1;
    half = lbl_801A748C;
    v1 = (-v2);
    v1 = (half * v1);
    loc_14.a[4] = (half * v2);
    loc_14.a[2] = v1;
    fn_80073A58(1, &loc_14, 1);
    fn_80073B50(*(u32 *)(arg1), *(u32 *)((u8 *)arg1 + 16), 0, 7, 1, 0, 0, 0, 0, 0);
    (*(u32 *)(arg1 + 16))++;
    (*(u32 *)(arg1 + 4))++;
    (*(u32 *)(arg1 + 12))++;
    fn_80073778(lbl_8019F040, *(u32 *)(arg1 + 12));
    fn_800745A4(*(u32 *)(arg1 + 4), 0, 0, 30, 0, 76);
    loc_10 = lbl_801A6D50;
    fn_800736C0(1, &loc_10);
    fn_800735C8(*(u32 *)(arg1), 13);
    fn_80072AB0(*(u32 *)(arg1), 0, 0);
    fn_800734A8(*(u32 *)(arg1), *(u32 *)(arg1 + 4), *(u32 *)(arg1 + 12), 4);
    fn_80072C24(*(u32 *)(arg1), 0, 8, 14, 15);
    fn_80072D64(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    fn_80072CC4(*(u32 *)(arg1), 0, 6, 6, 7);
    fn_80072E20(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    v0 = *(u32 *)(arg1);
    *(u32 *)((u8 *)arg1 + 0) = (v0 + 1);
    v0 = *(u32 *)(arg1 + 4);
    *(u32 *)((u8 *)arg1 + 4) = (v0 + 1);
    v0 = *(u32 *)(arg1 + 12);
    *(u32 *)((u8 *)arg1 + 12) = (v0 + 1);
    }
}

/* --- dol/fn_80075080.c --- */
struct fn_80075080_Arg0 {
    u32 unk_0;
};
struct fn_80075080_lbl_8019F130 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
};
extern f32 lbl_801A7484;
extern f64 lbl_801A7490;
extern struct fn_80075080_lbl_8019F130 lbl_8019F130[];
extern u32 fn_80072614(void *);
extern u32 fn_800725DC(void *);

struct FzgxCopy_4 { u32 words[1]; };
void fn_80075080(void *arg0) {
    struct FzgxCopy_4 loc_14;
    struct FzgxCopy_4 loc_10;
    u32 spC;
    u32 sp8;
    f32 temp_f31;
    f32 var_f4;
    f32 var_f5;
    f32 var_f6;
    s32 temp_r3;
    s32 var_r31;
    s32 var_r4;

    temp_r3 = *(s32 *)((u8 *)(arg0));
    var_r31 = 0;
    var_r4 = 0;
    if (temp_r3 & 8) {
        var_r4 = 1;
        var_r31 = 1;
    } else if (temp_r3 & 0x80) {
        var_r31 = 1;
    }
    temp_f31 = lbl_8019F130->unk_C;
    if (var_r4 != 0) {
        var_f4 = (*((u8 *)(arg0) + 8));
        var_f5 = (*((u8 *)(arg0) + 9));
        var_f6 = (*((u8 *)(arg0) + 10));
    } else {
        var_f4 = lbl_801A7484;
        var_f5 = var_f4;
        var_f6 = var_f4;
    }
    (*((u8 *)(&loc_10) + 3)) = ((lbl_801A7484) * temp_f31);
    (*(s8 *)(&loc_10)) = (var_f4 * lbl_8019F130->unk_0);
    (*((u8 *)(&loc_10) + 1)) = (var_f5 * lbl_8019F130->unk_4);
    (*((u8 *)(&loc_10) + 2)) = (var_f6 * lbl_8019F130->unk_8);
    spC = loc_10.words[0];
    fn_80072614(&spC);
    if (var_r31 != 0) {
        (*(u8 *)(&loc_14)) = *((u8 *)(arg0) + 4);
        (*((u8 *)(&loc_14) + 1)) = *((u8 *)(arg0) + 5);
        (*((u8 *)(&loc_14) + 2)) = *((u8 *)(arg0) + 6);
    } else {
        (*(u8 *)(&loc_14)) = 0xFF;
        (*((u8 *)(&loc_14) + 1)) = 0xFF;
        (*((u8 *)(&loc_14) + 2)) = 0xFF;
    }
    (*((u8 *)(&loc_14) + 3)) = (temp_f31 * (*((u8 *)(arg0) + 17)));
    sp8 = loc_14.words[0];
    fn_800725DC(&sp8);
}
