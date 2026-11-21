#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
static inline void set_x2(u16 value) { gx->bpSentNot = value; }

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXClearBoundingBox(void) {
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = 0x550003FF;
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = 0x560003FF;
    set_x2(((GXBool)0));
}
