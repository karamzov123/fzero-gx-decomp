#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1) {
    u32 reg = 0xF3000000;
    (reg) = (reg & ~(((1 << ((31 - 24 + 1))) - 1) << (31 - (24) - ((31 - 24 + 1)) + 1))) |
            ((int)(ref0) << (31 - (24) - ((31 - 24 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((23 - 16 + 1))) - 1) << (31 - (16) - ((23 - 16 + 1)) + 1))) |
            ((int)(ref1) << (31 - (16) - ((23 - 16 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((15 - 13 + 1))) - 1) << (31 - (13) - ((15 - 13 + 1)) + 1))) |
            ((int)(comp0) << (31 - (13) - ((15 - 13 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((12 - 10 + 1))) - 1) << (31 - (10) - ((12 - 10 + 1)) + 1))) |
            ((int)(comp1) << (31 - (10) - ((12 - 10 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((9 - 8 + 1))) - 1) << (31 - (8) - ((9 - 8 + 1)) + 1))) |
            ((int)(op) << (31 - (8) - ((9 - 8 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}
