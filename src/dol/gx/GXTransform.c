#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
#include "psvec_fifo.h"
#include "dolphin/hw_regs.h"

void GXSetProjection(const Mtx44 proj, GXProjectionType type) {
// Hardware or OS state can change asynchronously.
    volatile void *fifo; // fzgx-allow: S2 SDK asynchronous state
    u32 reg;
    gx->projType = type;
    gx->projMtx[0] = proj[0][0];
    gx->projMtx[2] = proj[1][1];
    gx->projMtx[4] = proj[2][2];
    gx->projMtx[5] = proj[2][3];
    if (type == GX_ORTHOGRAPHIC) {
        gx->projMtx[1] = proj[0][3];
        gx->projMtx[3] = proj[1][3];
    } else {
        gx->projMtx[1] = proj[0][2];
        gx->projMtx[3] = proj[1][2];
    }
    reg = 0x00061020;
    GXWGFifo.u8 = (u8)(0x10);
    GXWGFifo.u32 = (u32)(reg);
    do {
        GXWGFifo.f32 = (f32)(gx->projMtx[0]);
        ;
    } while (0);
    do {
        GXWGFifo.f32 = (f32)(gx->projMtx[1]);
        ;
    } while (0);
    do {
        GXWGFifo.f32 = (f32)(gx->projMtx[2]);
        ;
    } while (0);
    do {
        GXWGFifo.f32 = (f32)(gx->projMtx[3]);
        ;
    } while (0);
    do {
        GXWGFifo.f32 = (f32)(gx->projMtx[4]);
        ;
    } while (0);
    do {
        GXWGFifo.f32 = (f32)(gx->projMtx[5]);
        ;
    } while (0);
    do {
        GXWGFifo.u32 = (u32)(gx->projType);
    } while (0);
    gx->bpSentNot = ((GXBool)1);
}

#define GX_FIFO_ADDR ((volatile void*)0xCC008000) // fzgx-allow: A1 hardware FIFO register  /* fzgx-allow: A2 unnamed OS/hardware memory */

extern u32 __cvt_fp2unsigned(f32);

void GXSetProjectionv(f32* values) {
    u32 first = __cvt_fp2unsigned(values[0]);
    GXData * context = gx;

    context->projType = first;
    context->projMtx[0] = values[1];
    context->projMtx[1] = values[2];
    context->projMtx[2] = values[3];
    context->projMtx[3] = values[4];
    context->projMtx[4] = values[5];
    context->projMtx[5] = values[6];

    *(volatile u8*)GX_FIFO_ADDR = 0x10;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile u32*)GX_FIFO_ADDR = 0x00061020;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->projMtx[0];  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->projMtx[1];  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->projMtx[2];  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->projMtx[3];  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->projMtx[4];  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->projMtx[5];  /* fzgx-allow: S2 memory-mapped register */
    *(volatile u32*)GX_FIFO_ADDR = context->projType;  /* fzgx-allow: S2 memory-mapped register */
    context->bpSentNot = 1;
}

extern f64 lbl_801A7168;

void GXGetProjectionv(f32* out) {
    GXData * context = gx;
    out[0] = (f32)context->projType;
    out[1] = context->projMtx[0];
    out[2] = context->projMtx[1];
    out[3] = context->projMtx[2];
    out[4] = context->projMtx[3];
    out[5] = context->projMtx[4];
    out[6] = context->projMtx[5];
}

void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 4;
    reg = addr | 0xB0000;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg;
    WriteMTXPS4x3(mtx, &GXWGFifo);
}

void GXLoadNrmMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 3 + 0x400;
    reg = addr | 0x80000;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg;
    WriteMTXPS3x3from3x4(mtx, &GXWGFifo);
}

extern void __GXSetMatrixIndex(GXAttr index);

void GXSetCurrentMtx(u32 value) {
    GXData * context = gx;
    context->matIdxA = (context->matIdxA & ~0x3fu) | value;
    __GXSetMatrixIndex(0);
}

void GXLoadTexMtxImm(const f32 mtx[3][4], u32 id, s32 type) {
    u32 command;
    u32 count;
    u32 addr;

    if (id >= 64) {
        addr = (id - 64) * 4 + 0x500;
    } else {
        addr = id * 4;
    }
    if (type == 1) {
        count = 8;
    } else {
        count = 12;
    }
    command = (count - 1) << 16;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = addr | command;
    if (type == 0) {
        WriteMTXPS4x3(mtx, &GXWGFifo);
    } else {
        WriteMTXPS4x2(mtx, &GXWGFifo);
    }
}

extern void fn_80038878(f32 near_z, f32 side_x);

void fn_80038DE8(f32 left, f32 top, f32 width, f32 height, f32 near_z, f32 far_z, u32 field) {
    f32 sx;
    f32 sy;
    f32 sz;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 zmin;
    f32 zmax;
    f32 half_height;

    if (field == 0) {
        top -= 0.5f;
    }
    sx = width / 2.0f;
    sy = -height / 2.0f;
    ox = 342.0f + (left + (width / 2.0f));
    half_height = height / 2.0f;
    oy = 342.0f + (top + half_height);
    zmin = 1.6777215e7f * near_z;
    zmax = 1.6777215e7f * far_z;
    sz = zmax - zmin;
    oz = zmax;
    gx->vpLeft = left;
    gx->vpTop = top;
    gx->vpWd = width;
    gx->vpHt = height;
    gx->vpNearz = near_z;
    gx->vpFarz = far_z;
    if (gx->fgRange != 0) {
        fn_80038878(near_z, gx->fgSideX);
    }
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x5101a;
    GXWGFifo.f32 = sx;
    GXWGFifo.f32 = sy;
    GXWGFifo.f32 = sz;
    GXWGFifo.f32 = ox;
    GXWGFifo.f32 = oy;
    GXWGFifo.f32 = oz;
    gx->bpSentNot = 1;
}

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
