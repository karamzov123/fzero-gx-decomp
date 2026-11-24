#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/gx/GXPriv.h"

typedef struct LgRenderMode {
    u8 pad_0[0xE];
    u16 width;
    u16 height;
} LgRenderMode;

extern LgRenderMode *lbl_801A6CF4;
extern void *lbl_801A6D00;
extern f32 lbl_801A6CA0;
extern f32 lbl_801A6CA4;
extern GXColor lbl_801A6CA8;
extern void (*lbl_801A6CAC)(void);

extern void GXLoadPosMtxImm(void *, u32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_8003462C(u32, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern void lbl_8006D758(void);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(u32, u32, u32, u32, u32);
extern void fn_80072D64(u32, u32, u32, u32, u32, u32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80073678(u32);
extern void fn_800737E4(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);

void fn_8006CE44(void);

void fn_8006CCC8(void) {
    LgRenderMode *mode = lbl_801A6CF4;
    GXColor black = {0, 0, 0, 0xFF};
    u16 width;
    u16 height;

    lbl_801A6CAC = 0;
    lbl_801A6CA8 = black;
    width = mode->width;
    lbl_801A6CA4 = width;
    height = mode->height;
    lbl_801A6CA0 = height;
}

void fn_8006CD20(f32 width, f32 height) {
    lbl_801A6CA4 = width;
    lbl_801A6CA0 = height;
}

void fn_8006CD2C(f32 *width, f32 *height) {
    *width = lbl_801A6CA4;
    *height = lbl_801A6CA0;
}

f32 fn_8006CD40(f32 height) {
    f32 previous = lbl_801A6CA0;

    lbl_801A6CA0 = height;
    return previous;
}

void fn_8006CD50(void) {
    struct { u32 a[18]; } projection;

    C_MTXOrtho(&projection, 0.0f, lbl_801A6CA0, 0.0f, lbl_801A6CA4, 0.0f, 1000.0f);
    fn_800737E4(&projection, 1);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
}

void fn_8006CDA8(void) {
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    if (lbl_801A6CAC != 0) {
        lbl_801A6CAC();
    }
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8006CE44();
}

/* WARNING: compiler-diff device, not original code. Retail loads all three bytes before the first store. */
#pragma opt_propagation off
void fn_8006CDFC(GXColor *color) {
    u8 b;
    u8 g;
    u8 r;

    r = color->r;
    g = color->g;
    b = color->b;
    lbl_801A6CA8.r = r;
    lbl_801A6CA8.g = g;
    lbl_801A6CA8.b = b;
}
#pragma opt_propagation reset

void fn_8006CE1C(f32 alpha) {
    lbl_801A6CA8.a = 255.0f * alpha;
}

void fn_8006CE44(void) {
    GXColor color;
    f32 width;
    f32 height;

    if (lbl_801A6CA8.a == 0) {
        return;
    }
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    color = lbl_801A6CA8;
    fn_800371F8(1, &color);
    fn_8003462C(128, 7, 4);

    GX_WRITE_F32(0.0f);
    GX_WRITE_F32(0.0f);
    GX_WRITE_F32(-1.0f);
    width = lbl_801A6CA4;
    GX_WRITE_F32(width);
    GX_WRITE_F32(0.0f);
    GX_WRITE_F32(-1.0f);
    GX_WRITE_F32(width);
    height = lbl_801A6CA0;
    GX_WRITE_F32(height);
    GX_WRITE_F32(-1.0f);
    GX_WRITE_F32(0.0f);
    GX_WRITE_F32(height);
    GX_WRITE_F32(-1.0f);
}
