#include "types.h"

typedef struct Sig_fn_800371F8_GXColor {
    u8 r, g, b, a;
} Sig_fn_800371F8_GXColor;

typedef f32 Fn80005B10Mtx44[4][4];

extern Sig_fn_800371F8_GXColor lbl_801A6E58;
extern Sig_fn_800371F8_GXColor lbl_801A7908;
extern void *lbl_801A6D00;
extern f32 lbl_801A6E5C;
extern f32 lbl_801A6E60;
extern f32 lbl_801A6E64;
extern f32 lbl_801A6E68;
extern f32 lbl_801A6E6C;
extern f32 lbl_801A6E70;
extern f64 lbl_801A6E78;
extern f32 lbl_801A6E80;
extern f64 lbl_801A6E88;
extern f32 lbl_801A6E90;
extern f32 lbl_801A6E94;

extern void fn_800723F8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_800371F8(s32, Sig_fn_800371F8_GXColor);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800377F8(s32, f32, f32, f32, f32, Sig_fn_800371F8_GXColor);
extern void fn_80072864(u32);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(void *, u32);
extern void C_MTXOrtho(Fn80005B10Mtx44, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(Fn80005B10Mtx44, s32);
extern void fn_80073778(void *, s32);
extern void fn_8003462C(u32, u32, u32);

void fn_80005B10(void *arg0) {
    Fn80005B10Mtx44 mtx;
    Sig_fn_800371F8_GXColor color = lbl_801A6E58;
    f32 cx = 320.0f;
    f32 cy = 240.0f;
    f64 l, t, r, b;

    fn_800723F8();
    fn_8007245C(0x2200);
    fn_800723F8();
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072EDC(0, 0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_800371F8(1, color);
    fn_80074918(1, 1, 1);
    fn_800728A8(1, 4, 5, 0);
    fn_800377F8(0, 0.0f, 100.0f, 0.0f, 100.0f, lbl_801A7908);
    fn_80072864(2);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    C_MTXOrtho(mtx, lbl_801A6E5C, lbl_801A6E64, lbl_801A6E5C, lbl_801A6E68, lbl_801A6E5C, lbl_801A6E6C);
    fn_800737E4(mtx, 1);
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    fn_800371F8(1, color);
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0;
    fn_800371F8(2, color);
    fn_80073778(arg0, 0);
    fn_8003462C(128, 7, 4);

    l = cx - 320.0;
    r = 320.0 + cx;
    t = cy - 240.0;
    b = 240.0 + cy;

    *(f32 *)((u8 *)0xCC010000 + -32768) = l;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = t;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = r;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = t;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = r;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = b;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = l;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = b;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
}
