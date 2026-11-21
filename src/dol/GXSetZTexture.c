#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetZTexture(GXZTexOp op, GXTexFmt format, u32 bias) {
    u32 val1;
    u32 val2;
    u32 val3;
    val1 = 0;
    (val1) = (val1 & ~(((1 << ((31 - 8 + 1))) - 1) << (31 - (8) - ((31 - 8 + 1)) + 1))) |
             ((int)(bias) << (31 - (8) - ((31 - 8 + 1)) + 1));
    (val1) = (val1 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
             ((int)(0xF4) << (31 - (0) - ((7 - 0 + 1)) + 1));
    val2 = 0;
    switch (format) {
    case GX_TF_Z8:
        val3 = 0;
        break;
    case GX_TF_Z16:
        val3 = 1;
        break;
    case GX_TF_Z24X8:
        val3 = 2;
        break;
    default:
        val3 = 2;
        break;
    }
    (val2) = (val2 & ~(((1 << ((31 - 30 + 1))) - 1) << (31 - (30) - ((31 - 30 + 1)) + 1))) |
             ((int)(val3) << (31 - (30) - ((31 - 30 + 1)) + 1));
    (val2) = (val2 & ~(((1 << ((29 - 28 + 1))) - 1) << (31 - (28) - ((29 - 28 + 1)) + 1))) |
             ((int)(op) << (31 - (28) - ((29 - 28 + 1)) + 1));
    (val2) = (val2 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
             ((int)(0xF5) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (val1);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (val2);
    ;
    gx->bpSentNot = ((GXBool)0);
}
