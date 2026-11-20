#include "types.h"
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"


/* --- dol/fn_800081C8.c --- */
extern u32 lbl_801A66A0;
extern u32 fn_80007F70(u8 *, u8 *, s32, f32);
typedef struct { u8 r, g, b, a; } Color;
u32 fn_800081C8(Color arg0, Color arg1, f32 arg2) {
    Color color0;
    Color color1;
    color1 = arg1;
    color0 = arg0;
    return fn_80007F70((u8 *)&color0, (u8 *)&color1, lbl_801A66A0, arg2);
}

/* --- dol/fn_80008204.c --- */
extern Color lbl_801A7910;
extern Color lbl_801A7914;
extern void *lbl_801A6D00;

extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_80073C6C(s32);
extern void fn_80073620(s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_800736C0(s32, Color);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800725DC(Color);
extern void fn_80072614(Color);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void GXGetProjectionv(f32 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_8003462C(u32, u32, u32);

typedef enum { PROJ_PERSPECTIVE, PROJ_ORTHOGRAPHIC } ProjType;

/* volatile: GX write-gather FIFO, every store is a hardware write */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

void fn_80008204(Color *color) {
    Color c = *color;
    f32 proj[7];
    f32 n;
    f32 x0;
    f32 sx;
    f32 sy;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 z;
    f32 sx_2;

    fn_8007245C(0x200);
    fn_80072864(0);
    fn_80073C6C(0);
    fn_80073620(0, 0x1c);
    fn_800735C8(0, 0xc);
    fn_800736C0(0, c);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_800725DC(lbl_801A7910);
    fn_80072614(lbl_801A7914);
    fn_80072C24(0, 0xf, 0xf, 0xf, 0xe);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 6);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_800728A8(0, 1, 0, 0);
    fn_80074918(1, 7, 1);
    fn_800720B0(0);
    GXGetProjectionv(proj);

    n = proj[6] / proj[5];
    switch ((u32)proj[0]) {
    case 0:
        z = -(n - (n - proj[6] / (proj[5] - 1.0f)) / 16777216.0f);
        sx = z / proj[1];
        x0 = (1.0f - proj[2]) * sx;
        x1 = (-1.0f - proj[2]) * sx;
        sy = z / proj[3];
        y0 = (1.0f - proj[4]) * sy;
        y1 = (-1.0f - proj[4]) * sy;
        break;
    default:
        z = -(n - (n - -(1.0f + proj[6]) / proj[5]) / 16777216.0f);
        sx_2 = 1.0f / proj[1];
        x0 = (1.0f - proj[2]) * sx_2;
        x1 = (-1.0f - proj[2]) * sx_2;
        sy = 1.0f / proj[3];
        y0 = (1.0f - proj[4]) * sy;
        y1 = (-1.0f - proj[4]) * sy;
        break;
    }

    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    fn_8003462C(0x80, 0, 4);
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = z;
}

/* --- dol/fn_800084E8.c --- */
typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

typedef struct fn_800084E8_Vec {
    f32 x;
    f32 y;
    f32 z;
} fn_800084E8_Vec;

typedef struct fn_800084E8_Rect {
    f32 z;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    u8 pad_14[0x8];
    s32 show_corners;
    fn_800084E8_Vec corners[4];
} fn_800084E8_Rect;

extern void fn_800087F4(void *arg0, fn_800084E8_Rect *rect);
extern void fn_80072558(void);
extern void fn_80008A4C(fn_800084E8_Rect *rect);

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXFIFO.f32 = x;
    GXFIFO.f32 = y;
    GXFIFO.f32 = z;
}

static inline void GXTexCoord2f32(f32 s, f32 t) {
    GXFIFO.f32 = s;
    GXFIFO.f32 = t;
}

void fn_800084E8(void *arg0, fn_800084E8_Rect *rect) {
    f32 viewport[6];
    f32 sx;
    f32 sy;
    f32 z;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;

    fn_800087F4(arg0, rect);
    lbl_8006DAEC();
    lbl_8006D758();
    fn_80072558();
    lbl_8006DB30();
    GXGetProjectionv(viewport);
    sx = -1.0f / viewport[1];
    sy = 1.0f / viewport[3];
    left = sx * (rect->left * rect->z);
    right = sx * (rect->right * rect->z);
    top = sy * (rect->top * rect->z);
    bottom = sy * (rect->bottom * rect->z);

    fn_8003462C(0x80, 0, 4);
    GXPosition3f32(left, top, rect->z);
    GXTexCoord2f32(0.0f, 0.0f);
    GXPosition3f32(right, top, rect->z);
    GXTexCoord2f32(1.0f, 0.0f);
    GXPosition3f32(right, bottom, rect->z);
    GXTexCoord2f32(1.0f, 1.0f);
    GXPosition3f32(left, bottom, rect->z);
    GXTexCoord2f32(0.0f, 1.0f);

    fn_80008A4C(rect);
    z = rect->z;
    fn_8003462C(0xB0, 0, 5);
    GXPosition3f32(left, top, z);
    GXPosition3f32(right, top, z);
    GXPosition3f32(right, bottom, z);
    GXPosition3f32(left, bottom, z);
    GXPosition3f32(left, top, z);

    if (rect->show_corners != 0) {
        fn_8003462C(0xB0, 0, 5);
        GXPosition3f32(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);
        GXPosition3f32(rect->corners[1].x, rect->corners[1].y, rect->corners[1].z);
        GXPosition3f32(rect->corners[2].x, rect->corners[2].y, rect->corners[2].z);
        GXPosition3f32(rect->corners[3].x, rect->corners[3].y, rect->corners[3].z);
        GXPosition3f32(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);

        fn_8003462C(0xA8, 0, 8);
        GXPosition3f32(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);
        GXPosition3f32(left, top, z);
        GXPosition3f32(rect->corners[1].x, rect->corners[1].y, rect->corners[1].z);
        GXPosition3f32(right, top, z);
        GXPosition3f32(rect->corners[2].x, rect->corners[2].y, rect->corners[2].z);
        GXPosition3f32(right, bottom, z);
        GXPosition3f32(rect->corners[3].x, rect->corners[3].y, rect->corners[3].z);
        GXPosition3f32(left, bottom, z);
    }
}
