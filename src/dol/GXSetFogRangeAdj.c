#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"
#include "dolphin/hw_regs.h"

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
            GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
            GXWGFifo.s32 = (fogRangeRegK);
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
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (fogRangeReg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

#define SET_REG_FIELD_RLWIMI(reg, size, shift, val) \
    ((reg) = __rlwimi((reg), (val), (shift), 32 - (shift) - (size), 31 - (shift)))

void fn_80037B14(s32 type, s32 src_factor, s32 dst_factor, s32 op) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD_RLWIMI(reg, 1, 11, type == 3);
    SET_REG_FIELD_RLWIMI(reg, 1, 0, type);
    SET_REG_FIELD_RLWIMI(reg, 1, 1, type == 2);
    SET_REG_FIELD_RLWIMI(reg, 4, 12, op);
    SET_REG_FIELD_RLWIMI(reg, 3, 8, src_factor);
    SET_REG_FIELD_RLWIMI(reg, 3, 5, dst_factor);
    GX_WRITE_RAS_REG(reg);
    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void fn_80037B68(u8 enable) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD_RLWIMI(reg, 1, 3, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}
