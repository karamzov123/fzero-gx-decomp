/* Non-matching: best partial attempt (97.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct {
    u8 r, g, b, a;
} QuadColor;

extern f32 lbl_801A6F14;
extern f32 lbl_801A6F34;
extern f32 lbl_801A6F38;
extern u32 lbl_801A7910;
extern u32 lbl_801A7914;
extern void *lbl_801A6D00;
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_80073C6C(s32);
extern void fn_80073620(s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_800736C0(u32, void *);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800725DC(void *);
extern void fn_80072614(void *);
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
extern void fn_80038BFC(f32 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(const void *, u32);
extern void lbl_8006DB30(void);
extern void fn_8003462C(u32, u32, u32);

void fn_80008204(const QuadColor *color) {
    f32 view[10];
    QuadColor input;
    QuadColor channel;
    u32 channel0;
    u32 channel1;
    f32 z;
    f32 bottom;
    f32 top;
    f32 left;
    f32 right;
    f32 sx;
    f32 sy;
    /* Writes enqueue individual vertex components in the hardware FIFO. */
    volatile f32 *fifo;

    input = *color;
    fn_8007245C(0x200);
    fn_80072864(0);
    fn_80073C6C(0);
    fn_80073620(0, 0x1c);
    fn_800735C8(0, 0xc);
    channel = input;
    fn_800736C0(0, &channel);
    fn_800734A8(0, 0xff, 0xff, 4);
    channel0 = lbl_801A7910;
    fn_800725DC(&channel0);
    channel1 = lbl_801A7914;
    fn_80072614(&channel1);
    fn_80072C24(0, 15, 15, 15, 14);
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
    fn_80038BFC(view);

    left = view[6];
    top = view[5];
    right = left / top;
    switch ((u32)view[0]) {
    case 0: {
        f32 x0 = lbl_801A6F14 - view[2];
        f32 x1 = lbl_801A6F38 - view[2];
        f32 y0 = lbl_801A6F14 - view[4];
        f32 y1 = lbl_801A6F38 - view[4];
        z = -(right - (right - left / (top - lbl_801A6F14)) / lbl_801A6F34);
        sx = z / view[1];
        sy = z / view[3];
        left = x0 * sx;
        right = x1 * sx;
        top = y0 * sy;
        bottom = y1 * sy;
        break;
    }
    default: {
        f32 x0 = lbl_801A6F14 - view[2];
        f32 x1 = lbl_801A6F38 - view[2];
        f32 y0 = lbl_801A6F14 - view[4];
        f32 y1 = lbl_801A6F38 - view[4];
        z = -(right - (right - (-(lbl_801A6F14 + left) / top)) / lbl_801A6F34);
        sx = lbl_801A6F14 / view[1];
        sy = lbl_801A6F14 / view[3];
        left = x0 * sx;
        right = x1 * sx;
        top = y0 * sy;
        bottom = y1 * sy;
        break;
    }
    }

    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    fn_8003462C(0x80, 0, 4);
    /* Volatile preserves the ordered writes to the hardware FIFO. */
    fifo = (volatile f32 *)GX_FIFO_BASE;
    fifo[0] = right;
    fifo[0] = top;
    fifo[0] = z;
    fifo[0] = left;
    fifo[0] = top;
    fifo[0] = z;
    fifo[0] = left;
    fifo[0] = bottom;
    fifo[0] = z;
    fifo[0] = right;
    fifo[0] = bottom;
    fifo[0] = z;
}
