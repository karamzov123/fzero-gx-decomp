#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetFogRangeAdj(GXBool enable, u16 center, GXFogAdjTable *table) {
    u32 fogRangeReg;
    u32 fogRangeRegK;
    u32 i;
    if (enable) {
        for (i = 0; i < 10; i += 2) {
            fogRangeRegK = 0;
            (fogRangeRegK) = (fogRangeRegK &
                              ~(((1 << ((GX_BP_FOGRANGEK_HI_END - GX_BP_FOGRANGEK_HI_ST + 1))) - 1)
                                << (31 - (GX_BP_FOGRANGEK_HI_ST) -
                                    ((GX_BP_FOGRANGEK_HI_END - GX_BP_FOGRANGEK_HI_ST + 1)) + 1))) |
                             ((int)(table->fogVals[i])
                              << (31 - (GX_BP_FOGRANGEK_HI_ST) -
                                  ((GX_BP_FOGRANGEK_HI_END - GX_BP_FOGRANGEK_HI_ST + 1)) + 1));
            (fogRangeRegK) = (fogRangeRegK &
                              ~(((1 << ((GX_BP_FOGRANGEK_LO_END - GX_BP_FOGRANGEK_LO_ST + 1))) - 1)
                                << (31 - (GX_BP_FOGRANGEK_LO_ST) -
                                    ((GX_BP_FOGRANGEK_LO_END - GX_BP_FOGRANGEK_LO_ST + 1)) + 1))) |
                             ((int)(table->fogVals[i + 1])
                              << (31 - (GX_BP_FOGRANGEK_LO_ST) -
                                  ((GX_BP_FOGRANGEK_LO_END - GX_BP_FOGRANGEK_LO_ST + 1)) + 1));
            (fogRangeRegK) =
                (fogRangeRegK & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                ((int)(GX_BP_REG_FOGRANGEK0 + (i / 2)) << (31 - (0) - ((7 - 0 + 1)) + 1));
            GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
            GXFIFO.s32 = (fogRangeRegK);
            ;
        }
    }
    fogRangeReg = 0;
    (fogRangeReg) =
        (fogRangeReg & ~(((1 << ((GX_BP_FOGRANGE_CENTER_END - GX_BP_FOGRANGE_CENTER_ST + 1))) - 1)
                         << (31 - (GX_BP_FOGRANGE_CENTER_ST) -
                             ((GX_BP_FOGRANGE_CENTER_END - GX_BP_FOGRANGE_CENTER_ST + 1)) + 1))) |
        ((int)(center + 342) << (31 - (GX_BP_FOGRANGE_CENTER_ST) -
                                 ((GX_BP_FOGRANGE_CENTER_END - GX_BP_FOGRANGE_CENTER_ST + 1)) + 1));
    (fogRangeReg) =
        (fogRangeReg & ~(((1 << ((GX_BP_FOGRANGE_ENABLED_END - GX_BP_FOGRANGE_ENABLED_ST + 1))) - 1)
                         << (31 - (GX_BP_FOGRANGE_ENABLED_ST) -
                             ((GX_BP_FOGRANGE_ENABLED_END - GX_BP_FOGRANGE_ENABLED_ST + 1)) + 1))) |
        ((int)(enable) << (31 - (GX_BP_FOGRANGE_ENABLED_ST) -
                           ((GX_BP_FOGRANGE_ENABLED_END - GX_BP_FOGRANGE_ENABLED_ST + 1)) + 1));
    (fogRangeReg) =
        (fogRangeReg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(GX_BP_REG_FOGRANGE) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (fogRangeReg);
    ;
    gx->bpSentNot = ((GXBool)0);
}
