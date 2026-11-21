#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
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
