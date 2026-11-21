#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
static inline void GXSetWasteFlags() {
    GXData *data = gx;
    data->dirtyState |= GX_DIRTY_SU_TEX | GX_DIRTY_BP_MASK;
    data->bpSentNot = 0;
}

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetIndTexOrder(GXIndTexStageID stage, GXTexCoordID coord, GXTexMapID map) {
    switch (stage) {
    case GX_INDTEXSTAGE0:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (29) - (3) + 1))) |
                     ((int)(map) << (31 - (29) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (26) - (3) + 1))) |
                     ((int)(coord) << (31 - (26) - (3) + 1));
        break;
    case GX_INDTEXSTAGE1:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (23) - (3) + 1))) |
                     ((int)(map) << (31 - (23) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (20) - (3) + 1))) |
                     ((int)(coord) << (31 - (20) - (3) + 1));
        break;
    case GX_INDTEXSTAGE2:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (17) - (3) + 1))) |
                     ((int)(map) << (31 - (17) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (14) - (3) + 1))) |
                     ((int)(coord) << (31 - (14) - (3) + 1));
        break;
    case GX_INDTEXSTAGE3:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (11) - (3) + 1))) |
                     ((int)(map) << (31 - (11) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (8) - (3) + 1))) |
                     ((int)(coord) << (31 - (8) - (3) + 1));
        break;
    }
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = gx->iref;
    GXSetWasteFlags();
}
