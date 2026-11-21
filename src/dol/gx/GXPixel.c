#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
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

void fn_80037B94(u8 enable) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD_RLWIMI(reg, 1, 4, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void fn_80037BC0(u8 compare_enable, s32 func, u8 update_enable) {
    u32 reg = gx->zmode;

    SET_REG_FIELD_RLWIMI(reg, 1, 0, compare_enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    SET_REG_FIELD_RLWIMI(reg, 3, 1, func);
    SET_REG_FIELD_RLWIMI(reg, 1, 4, update_enable);
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->zmode = reg;
    gx->bpSentNot = 0;
}

void GXSetZCompLoc(u32 arg0) {
    GXData *state = gx;
    u32 value;

    state->peCtrl = (state->peCtrl & 0xffffffbf) | ((arg0 & 0xff) << 6);
    GXWGFifo.u8 = 0x61;
    value = state->peCtrl;
    GXWGFifo.u32 = value;
    state->bpSentNot = 0;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))

extern u32 lbl_8012B3E0[8];

void fn_80037C2C(s32 pix_fmt, s32 z_fmt) {
    u32 old_pe_ctrl;
    u8 aa;

    old_pe_ctrl = gx->peCtrl;
    SET_REG_FIELD(gx->peCtrl, 3, 0, lbl_8012B3E0[pix_fmt]);
    SET_REG_FIELD(gx->peCtrl, 3, 3, z_fmt);
    if (old_pe_ctrl != gx->peCtrl) {
        GX_WRITE_RAS_REG(gx->peCtrl);
        if (pix_fmt == 2) {
            aa = 1;
        } else {
            aa = 0;
        }
        SET_REG_FIELD(gx->genMode, 1, 9, aa);
        gx->dirtyState |= 4;
    }
    if (lbl_8012B3E0[pix_fmt] == 4) {
        SET_REG_FIELD(gx->cmode1, 2, 9, (pix_fmt - 4) & 3);
        SET_REG_FIELD(gx->cmode1, 8, 24, 0x42);
        GX_WRITE_RAS_REG(gx->cmode1);
    }
    gx->bpSentNot = 0;
}

void fn_80037D14(u8 enable) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD_RLWIMI(reg, 1, 2, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void fn_80037D40(u8 enable, u8 alpha) {
    u32 reg = gx->cmode1;

    SET_REG_FIELD_RLWIMI(reg, 8, 0, alpha);
    SET_REG_FIELD_RLWIMI(reg, 1, 8, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode1 = reg;
    gx->bpSentNot = 0;
}

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
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (fieldMaskReg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

extern void __GXFlushTextureState(void);

struct GXState {
    u8 pad_000[0x7c];
    u32 state_07c;
};

void GXSetFieldMode(u8 arg0, u8 arg1) {
    struct GXState *state = (struct GXState *)gx;
    state->state_07c = (state->state_07c & 0xFFBFFFFF) | ((arg1 & 0xFF) << 22);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = state->state_07c;
    __GXFlushTextureState();
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = ((arg0 & 0xFF) | 0x68000000);
    __GXFlushTextureState();
}
