#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetTevIndirect(GXTevStageID tevStage, GXIndTexStageID texStage, GXIndTexFormat texFmt,
                 GXIndTexBiasSel biasSel, GXIndTexMtxID mtxID, GXIndTexWrap wrapS,
                 GXIndTexWrap wrapT, u8 addPrev, u8 utcLod, GXIndTexAlphaSel alphaSel) {
    u32 field = 0;
    (field) = (field & ~(((1 << (2)) - 1) << (31 - (30) - (2) + 1))) |
              ((int)(texStage) << (31 - (30) - (2) + 1));
    (field) = (field & ~(((1 << (2)) - 1) << (31 - (28) - (2) + 1))) |
              ((int)(texFmt) << (31 - (28) - (2) + 1));
    (field) = (field & ~(((1 << (3)) - 1) << (31 - (25) - (3) + 1))) |
              ((int)(biasSel) << (31 - (25) - (3) + 1));
    (field) = (field & ~(((1 << (2)) - 1) << (31 - (23) - (2) + 1))) |
              ((int)(alphaSel) << (31 - (23) - (2) + 1));
    (field) = (field & ~(((1 << (4)) - 1) << (31 - (19) - (4) + 1))) |
              ((int)(mtxID) << (31 - (19) - (4) + 1));
    (field) = (field & ~(((1 << (3)) - 1) << (31 - (16) - (3) + 1))) |
              ((int)(wrapS) << (31 - (16) - (3) + 1));
    (field) = (field & ~(((1 << (3)) - 1) << (31 - (13) - (3) + 1))) |
              ((int)(wrapT) << (31 - (13) - (3) + 1));
    (field) = (field & ~(((1 << (1)) - 1) << (31 - (12) - (1) + 1))) |
              ((int)(utcLod) << (31 - (12) - (1) + 1));
    (field) = (field & ~(((1 << (1)) - 1) << (31 - (11) - (1) + 1))) |
              ((int)(addPrev) << (31 - (11) - (1) + 1));
    (field) = (field & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
              ((int)(tevStage + 0x10) << (31 - (0) - (8) + 1));
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = field;
    gx->bpSentNot = 0;
}
