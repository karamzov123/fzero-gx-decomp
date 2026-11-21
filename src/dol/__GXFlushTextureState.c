#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXFlushTextureState(void) {
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = gx->bpMask;
    gx->bpSentNot = 0;
}
