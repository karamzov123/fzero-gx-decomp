#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u8 pad_004[0xa4];
    u32 amb_color[2];
    u32 mat_color[2];
} GXData;

typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} PPCWGPipe;

extern GXData *const gx;
volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | (val << shift))

void fn_80035828(s32 chan, GXColor color) {
    u32 reg;
    u32 rgb;
    u32 index;

    switch (chan) {
    case 0:
        reg = gx->mat_color[0];
        rgb = *(u32 *)&color >> 8;
        SET_REG_FIELD(reg, 24, 8, rgb);
        index = 0;
        break;
    case 1:
        reg = gx->mat_color[1];
        rgb = *(u32 *)&color >> 8;
        SET_REG_FIELD(reg, 24, 8, rgb);
        index = 1;
        break;
    case 2:
        reg = gx->mat_color[0];
        SET_REG_FIELD(reg, 8, 0, color.a);
        index = 0;
        break;
    case 3:
        reg = gx->mat_color[1];
        SET_REG_FIELD(reg, 8, 0, color.a);
        index = 1;
        break;
    case 4:
        reg = *(u32 *)&color;
        index = 0;
        break;
    case 5:
        reg = *(u32 *)&color;
        index = 1;
        break;
    default:
        return;
    }
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = index + 0x100c;
    GXWGFifo.u32 = reg;
    gx->bp_sent_not = 1;
    gx->mat_color[index] = reg;
}
