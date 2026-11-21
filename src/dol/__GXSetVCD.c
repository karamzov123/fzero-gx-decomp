#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXXfVtxSpecs(void);

void __GXSetVCD(void) {
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_CP_REG;
    GXFIFO.s8 = (GX_CP_REG_VCD_LO);
    GXFIFO.s32 = (gx->vcdLo);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_CP_REG;
    GXFIFO.s8 = (GX_CP_REG_VCD_HI);
    GXFIFO.s32 = (gx->vcdHi);
    ;
    __GXXfVtxSpecs();
}
