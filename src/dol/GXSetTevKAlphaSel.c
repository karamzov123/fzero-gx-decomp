#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetTevKAlphaSel(GXTevStageID stage, GXTevKAlphaSel sel) {
    u32 *reg;
    reg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        (*reg) = (*reg & ~(((1 << ((12 - 8 + 1))) - 1) << (31 - (8) - ((12 - 8 + 1)) + 1))) |
                 ((int)(sel) << (31 - (8) - ((12 - 8 + 1)) + 1));
    } else {
        (*reg) = (*reg & ~(((1 << ((22 - 18 + 1))) - 1) << (31 - (18) - ((22 - 18 + 1)) + 1))) |
                 ((int)(sel) << (31 - (18) - ((22 - 18 + 1)) + 1));
    }
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}
