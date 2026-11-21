#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>


/* --- dol/GXSetClipMode.c --- */
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetClipMode(GXClipMode mode) {
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_XF_REG;
    GXFIFO.s32 = (GX_XF_REG_CLIPDISABLE);
    ;
    GXFIFO.s32 = (mode);
    ;
    gx->bpSentNot = ((GXBool)1);
}

/* --- dol/__GXSetMatrixIndex.c --- */
// Hardware or OS state can change asynchronously.

void __GXSetMatrixIndex(GXAttr index) {
    if (index < GX_VA_TEX4MTXIDX) {
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_CP_REG;
        GXFIFO.s8 = (GX_CP_REG_MTXIDXA);
        GXFIFO.s32 = (gx->matIdxA);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_XF_REG;
        GXFIFO.s32 = (GX_XF_REG_MATRIXINDEX0);
        ;
        GXFIFO.s32 = (gx->matIdxA);
        ;
    } else {
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_CP_REG;
        GXFIFO.s8 = (GX_CP_REG_MTXIDXB);
        GXFIFO.s32 = (gx->matIdxB);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_XF_REG;
        GXFIFO.s32 = (GX_XF_REG_MATRIXINDEX1);
        ;
        GXFIFO.s32 = (gx->matIdxB);
        ;
    }
    gx->bpSentNot = ((GXBool)1);
}
