#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetTevSwapMode(GXTevStageID stage, GXTevSwapSel rasSel, GXTevSwapSel texSel) {
    u32 *reg = &gx->teva[stage];
    (*reg) = (*reg & ~(((1 << ((31 - 30 + 1))) - 1) << (31 - (30) - ((31 - 30 + 1)) + 1))) |
             ((int)(rasSel) << (31 - (30) - ((31 - 30 + 1)) + 1));
    (*reg) = (*reg & ~(((1 << ((29 - 28 + 1))) - 1) << (31 - (28) - ((29 - 28 + 1)) + 1))) |
             ((int)(texSel) << (31 - (28) - ((29 - 28 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}
