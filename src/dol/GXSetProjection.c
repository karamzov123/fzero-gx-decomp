#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
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

extern void __GXSetMatrixIndex(u32);

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
