#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

extern struct GXTevData lbl_8012B368;

void GXSetTevOp(GXTevStageID stage, GXTevMode mode) {
    struct GXTevData *data = &lbl_8012B368;

    u32 *color;
    u32 *alpha;
    u32 tevReg;
    if (stage == GX_TEVSTAGE0) {
        color = ((u32 *)((u8 *)data + (u32) & ((struct GXTevData *)0)->TEVCOpTableST0) + mode);
        alpha = ((u32 *)((u8 *)data + (u32) & ((struct GXTevData *)0)->TEVAOpTableST0) + mode);
    } else {
        color = ((u32 *)((u8 *)data + (u32) & ((struct GXTevData *)0)->TEVCOpTableST1) + mode);
        alpha = ((u32 *)((u8 *)data + (u32) & ((struct GXTevData *)0)->TEVAOpTableST1) + mode);
    }
    tevReg = gx->tevc[stage];
    tevReg = (*color & ~0xFF000000) | (tevReg & 0xFF000000);
    do {
        GXFIFO.u8 = (u8)(0x61);
        GXFIFO.u32 = (u32)(tevReg);
        ;
    } while (0);
    gx->tevc[stage] = tevReg;
    tevReg = gx->teva[stage];
    tevReg = (*alpha & ~0xFF00000F) | (tevReg & 0xFF00000F);
    do {
        GXFIFO.u8 = (u8)(0x61);
        GXFIFO.u32 = (u32)(tevReg);
        ;
    } while (0);
    gx->teva[stage] = tevReg;
    gx->bpSentNot = ((GXBool)0);
}
