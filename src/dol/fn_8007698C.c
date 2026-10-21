#include "types.h"
struct fn_8007698C_lbl_801A3220 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x28];
    u32 unk_3C;
    u8 pad_40[0x4];
    u32 unk_44;
    u8 pad_48[0x4];
    u32 unk_4C;
};
struct fn_8007698C_lbl_801A6D00_T {
    u8 pad_0[0xC]; f32 unk_C;
    u8 pad_10[0xC]; f32 unk_1C;
    u8 pad_20[0xC]; f32 unk_2C;
};
struct Color { u8 r,g,b,a; };
extern f32 lbl_801A6D68, lbl_801A6D6C, lbl_801A6D70;
extern const f32 lbl_801A7480;
extern const f64 lbl_801A7490;
extern u8 lbl_801A3220[96];
extern struct fn_8007698C_lbl_801A6D00_T *lbl_801A6D00;
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_800736C0(u32, struct Color *);
extern void lbl_8006DAEC(void);
extern u8 lbl_8019F200[16416];
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80076790(void);
extern void lbl_8006DB30(void);
void fn_8007698C(void *arg0, void *arg1) {
    struct fn_8007698C_lbl_801A3220 *p_lbl_801A3220;
    s32 v9;
    u32 v10;
    struct Color color;
    struct Color loc;
    p_lbl_801A3220 = (struct fn_8007698C_lbl_801A3220 *)lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_4C == 0) {
        color = *(struct Color *)&p_lbl_801A3220->unk_10;
        if (color.r == 0 && color.g == 0 && color.b == 0) {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }
        color.r *= lbl_801A6D70;
        color.g *= lbl_801A6D6C;
        color.b *= lbl_801A6D68;
        loc = color;
        fn_800736C0(1, &loc);
        p_lbl_801A3220->unk_4C = 1;
    }
    p_lbl_801A3220 = (struct fn_8007698C_lbl_801A3220 *)lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_3C == 0) {
        lbl_8006DAEC();
        lbl_801A6D00->unk_C = lbl_801A7480;
        lbl_801A6D00->unk_1C = lbl_801A7480;
        lbl_801A6D00->unk_2C = lbl_801A7480;
        GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
        lbl_8006DB30();
        p_lbl_801A3220->unk_3C = 1;
    }
    if ((s32)((struct fn_8007698C_lbl_801A3220 *)lbl_801A3220)->unk_44 == 0) {
        fn_80073778(lbl_8019F200, 0);
        fn_80076790();
    }
    v9 = *(u32 *)((u8 *)arg0 + 0);
    fn_80073C6C(v9);
    fn_80072AB0(v9, 0, 0);
    fn_800735C8(v9, 13);
    fn_800745A4(*(u32 *)((u8 *)arg0 + 4), 0, 1, 30, 1, 70);
    fn_800734A8(v9, *(u32 *)((u8 *)arg0 + 4), 0, 4);
    fn_80072C24(v9, 15, 8, 14, 15);
    fn_80072D64(v9, 0, 0, 0, 1, 3);
    fn_80072CC4(v9, 7, 7, 7, *(u32 *)((u8 *)arg1 + 12));
    fn_80072E20(v9, 0, 0, 0, 1, 3);
    fn_80073C6C(v9 + 1);
    fn_80072AB0(v9 + 1, 0, 0);
    fn_800735C8(v9 + 1, 13);
    fn_800745A4(*(u32 *)((u8 *)arg0 + 4) + 1, 0, 1, 30, 1, 67);
    fn_800734A8(v9 + 1, *(u32 *)((u8 *)arg0 + 4) + 1, *(u32 *)((u8 *)arg0 + 12), 4);
    fn_80072C24(v9 + 1, 15, 8, 6, *(u32 *)((u8 *)arg1 + 8));
    fn_80072D64(v9 + 1, 0, 0, 0, 1, 0);
    fn_80072CC4(v9 + 1, 7, 7, 7, *(u32 *)((u8 *)arg1 + 12));
    fn_80072E20(v9 + 1, 0, 0, 0, 1, 0);
    *(u32 *)((u8 *)arg0 + 0) += 2;
    v10 = *(u32 *)((u8 *)arg0 + 4);
    *(u32 *)((u8 *)arg0 + 4) = v10 + 2;
}
