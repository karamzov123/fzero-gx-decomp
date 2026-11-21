#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXSendFlushPrim(void) {
    u32 i;
    u32 sz = gx->vNum * gx->vLim;
    GXFIFO.u8 = 0x98;
    GXFIFO.u16 = gx->vNum;
    for (i = 0; i < sz; i += 4) {
        GXFIFO.s32 = 0;
    }
    gx->bpSentNot = 1;
}
