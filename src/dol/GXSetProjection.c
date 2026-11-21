#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

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
    GXFIFO.u8 = (u8)(0x10);
    GXFIFO.u32 = (u32)(reg);
    do {
        GXFIFO.f32 = (f32)(gx->projMtx[0]);
        ;
    } while (0);
    do {
        GXFIFO.f32 = (f32)(gx->projMtx[1]);
        ;
    } while (0);
    do {
        GXFIFO.f32 = (f32)(gx->projMtx[2]);
        ;
    } while (0);
    do {
        GXFIFO.f32 = (f32)(gx->projMtx[3]);
        ;
    } while (0);
    do {
        GXFIFO.f32 = (f32)(gx->projMtx[4]);
        ;
    } while (0);
    do {
        GXFIFO.f32 = (f32)(gx->projMtx[5]);
        ;
    } while (0);
    do {
        GXFIFO.u32 = (u32)(gx->projType);
    } while (0);
    gx->bpSentNot = ((GXBool)1);
}
