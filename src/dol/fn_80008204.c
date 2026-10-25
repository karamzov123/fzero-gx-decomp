#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct { u8 r, g, b, a; } Color;

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
