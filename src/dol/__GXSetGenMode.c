#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/__GXSetGenMode.c --- */
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXSetGenMode(void) {
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = gx->genMode;
    gx->bpSentNot = 0;
}
