#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetIndTexCoordScale(GXIndTexStageID texStage, GXIndTexScale scaleS, GXIndTexScale scaleT) {
    GXData *data;
    switch (texStage) {
    case GX_INDTEXSTAGE0:
        data = gx;
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (28) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (28) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (24) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (24) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x25) << (31 - (0) - (8) + 1));
        GXFIFO.u8 = 0x61;
        GXFIFO.s32 = data->IndTexScale0;
        break;
    case GX_INDTEXSTAGE1:
        data = gx;
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (20) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (20) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (16) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (16) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x25) << (31 - (0) - (8) + 1));
        GXFIFO.u8 = 0x61;
        GXFIFO.s32 = data->IndTexScale0;
        break;
    case GX_INDTEXSTAGE2:
        data = gx;
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (28) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (28) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (24) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (24) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x26) << (31 - (0) - (8) + 1));
        GXFIFO.u8 = 0x61;
        GXFIFO.s32 = data->IndTexScale1;
        break;
    case GX_INDTEXSTAGE3:
        data = gx;
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (20) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (20) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (16) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (16) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x26) << (31 - (0) - (8) + 1));
        GXFIFO.u8 = 0x61;
        GXFIFO.s32 = data->IndTexScale1;
        break;
    }
    gx->bpSentNot = 0;
}
