#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetFieldMask(GXBool enableEven, GXBool enableOdd) {
    u32 fieldMaskReg = 0;
    (fieldMaskReg) =
        (fieldMaskReg & ~(((1 << ((GX_BP_FIELDMASK_ODD_END - GX_BP_FIELDMASK_ODD_ST + 1))) - 1)
                          << (31 - (GX_BP_FIELDMASK_ODD_ST) -
                              ((GX_BP_FIELDMASK_ODD_END - GX_BP_FIELDMASK_ODD_ST + 1)) + 1))) |
        ((int)(enableOdd) << (31 - (GX_BP_FIELDMASK_ODD_ST) -
                              ((GX_BP_FIELDMASK_ODD_END - GX_BP_FIELDMASK_ODD_ST + 1)) + 1));
    (fieldMaskReg) =
        (fieldMaskReg & ~(((1 << ((GX_BP_FIELDMASK_EVEN_END - GX_BP_FIELDMASK_EVEN_ST + 1))) - 1)
                          << (31 - (GX_BP_FIELDMASK_EVEN_ST) -
                              ((GX_BP_FIELDMASK_EVEN_END - GX_BP_FIELDMASK_EVEN_ST + 1)) + 1))) |
        ((int)(enableEven) << (31 - (GX_BP_FIELDMASK_EVEN_ST) -
                               ((GX_BP_FIELDMASK_EVEN_END - GX_BP_FIELDMASK_EVEN_ST + 1)) + 1));
    (fieldMaskReg) =
        (fieldMaskReg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(GX_BP_REG_FIELDMASK) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (fieldMaskReg);
    ;
    gx->bpSentNot = ((GXBool)0);
}
