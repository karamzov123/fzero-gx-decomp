#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
#include "dolphin/hw_regs.h"

extern void fn_80038DE8(f32 left, f32 top, f32 width, f32 height, f32 near_z, f32 far_z, u32 field);

void fn_80038EEC(f32 left, f32 top, f32 width, f32 height, f32 near_z, f32 far_z) {
    fn_80038DE8(left, top, width, height, near_z, far_z, 1);
}

void fn_80038F10(f32* out) {
    GXData * context = gx;
    out[0] = context->vpLeft;
    out[1] = context->vpTop;
    out[2] = context->vpWd;
    out[3] = context->vpHt;
    out[4] = context->vpNearz;
    out[5] = context->vpFarz;
}

#define MASK(bitCount, bitShift) ((u32)(((1 << (bitCount)) - 1) << (bitShift)))

void GXSetScissor(u32 left, u32 top, u32 width, u32 height) {
    u32 y1, x1, y2, x2;

    y1 = top + 342;
    x1 = left + 342;
    y2 = y1 + height - 1;
    x2 = x1 + width - 1;
    (gx->suScis0) = (gx->suScis0 & ~MASK(11, GX_BP_SCISSORTL_TOP_ST)) | y1;
    (gx->suScis0) = (gx->suScis0 & ~MASK(11, GX_BP_SCISSORTL_LEFT_ST)) | (x1 << GX_BP_SCISSORTL_LEFT_ST);
    (gx->suScis1) = (gx->suScis1 & ~MASK(11, GX_BP_SCISSORBR_BOT_ST)) | y2;
    (gx->suScis1) = (gx->suScis1 & ~MASK(11, GX_BP_SCISSORBR_RIGHT_ST)) | (x2 << GX_BP_SCISSORBR_RIGHT_ST);
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->suScis0);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->suScis1);
    ;
    gx->bpSentNot = 0;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))

void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height) {
    u32 y0 = gx->suScis0 & 0x7ff;
    u32 x0 = (gx->suScis0 & 0x7ff000) >> 12;
    u32 y1 = gx->suScis1 & 0x7ff;
    u32 x1 = (gx->suScis1 & 0x7ff000) >> 12;

    *left = x0 - 342;
    *top = y0 - 342;
    *width = x1 - x0 + 1;
    *height = y1 - y0 + 1;
}

u32 GXSetScissorBoxOffset(s32 x, s32 y) {
    u32 temp = ((u32)(x + 0x156) >> 1) & 0xfff003ff;
    GXData * context = gx;
    u32 value = (temp | (((u32)(y + 0x156) >> 1) << 10)) & 0x00ffffff;
    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = 0x61; /* fzgx-allow: A1,A2 GX FIFO hardware register */
    value |= 0x59000000;
    *(volatile u32 *)((u8 *)0xCC010000 + -32768) = value; /* fzgx-allow: A1,A2 GX FIFO hardware register */
    context->bpSentNot = 0;
    return (u32)context;
}

void GXSetClipMode(GXClipMode mode) {
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_XF_REG;
    GXWGFifo.s32 = (GX_XF_REG_CLIPDISABLE);
    ;
    GXWGFifo.s32 = (mode);
    ;
    gx->bpSentNot = ((GXBool)1);
}

// Hardware or OS state can change asynchronously.

void __GXSetMatrixIndex(GXAttr index) {
    if (index < GX_VA_TEX4MTXIDX) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_CP_REG;
        GXWGFifo.s8 = (GX_CP_REG_MTXIDXA);
        GXWGFifo.s32 = (gx->matIdxA);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_XF_REG;
        GXWGFifo.s32 = (GX_XF_REG_MATRIXINDEX0);
        ;
        GXWGFifo.s32 = (gx->matIdxA);
        ;
    } else {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_CP_REG;
        GXWGFifo.s8 = (GX_CP_REG_MTXIDXB);
        GXWGFifo.s32 = (gx->matIdxB);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_XF_REG;
        GXWGFifo.s32 = (GX_XF_REG_MATRIXINDEX1);
        ;
        GXWGFifo.s32 = (gx->matIdxB);
        ;
    }
    gx->bpSentNot = ((GXBool)1);
}
