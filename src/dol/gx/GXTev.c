#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
#include "dolphin/hw_regs.h"

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
        GXWGFifo.u8 = (u8)(0x61);
        GXWGFifo.u32 = (u32)(tevReg);
        ;
    } while (0);
    gx->tevc[stage] = tevReg;
    tevReg = gx->teva[stage];
    tevReg = (*alpha & ~0xFF00000F) | (tevReg & 0xFF00000F);
    do {
        GXWGFifo.u8 = (u8)(0x61);
        GXWGFifo.u32 = (u32)(tevReg);
        ;
    } while (0);
    gx->teva[stage] = tevReg;
    gx->bpSentNot = ((GXBool)0);
}

#define SET_REG_FIELD_RLWIMI(reg, size, shift, val) \
    ((reg) = __rlwimi((reg), (val), (shift), 32 - (shift) - (size), 31 - (shift)))

void fn_800370A0(s32 stage, s32 a, s32 b, s32 c, s32 d) {
    u32 reg = gx->tevc[stage];

    SET_REG_FIELD_RLWIMI(reg, 4, 12, a);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    SET_REG_FIELD_RLWIMI(reg, 4, 8, b);
    SET_REG_FIELD_RLWIMI(reg, 4, 4, c);
    SET_REG_FIELD_RLWIMI(reg, 4, 0, d);
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->tevc[stage] = reg;
    gx->bpSentNot = 0;
}

void fn_800370E4(s32 stage, s32 a, s32 b, s32 c, s32 d) {
    u32 reg = gx->teva[stage];

    SET_REG_FIELD_RLWIMI(reg, 3, 13, a);
    SET_REG_FIELD_RLWIMI(reg, 3, 10, b);
    SET_REG_FIELD_RLWIMI(reg, 3, 7, c);
    SET_REG_FIELD_RLWIMI(reg, 3, 4, d);
    GX_WRITE_RAS_REG(reg);
    gx->teva[stage] = reg;
    gx->bpSentNot = 0;
}

void fn_80037128(s32 stage, s32 op, s32 bias, s32 scale, u8 clamp, s32 out_reg) {
    u32 reg = gx->tevc[stage];

    SET_REG_FIELD_RLWIMI(reg, 1, 18, op & 1);
    if (op <= 1) {
        SET_REG_FIELD_RLWIMI(reg, 2, 20, scale);
        SET_REG_FIELD_RLWIMI(reg, 2, 16, bias);
    } else {
        SET_REG_FIELD_RLWIMI(reg, 2, 20, (op >> 1) & 3);
        SET_REG_FIELD_RLWIMI(reg, 2, 16, 3);
    }
    SET_REG_FIELD_RLWIMI(reg, 1, 19, clamp);
    SET_REG_FIELD_RLWIMI(reg, 2, 22, out_reg);
    GX_WRITE_RAS_REG(reg);
    gx->tevc[stage] = reg;
    gx->bpSentNot = 0;
}

void fn_80037190(s32 stage, s32 op, s32 bias, s32 scale, u8 clamp, s32 out_reg) {
    u32 reg = gx->teva[stage];

    SET_REG_FIELD_RLWIMI(reg, 1, 18, op & 1);
    if (op <= 1) {
        SET_REG_FIELD_RLWIMI(reg, 2, 20, scale);
        SET_REG_FIELD_RLWIMI(reg, 2, 16, bias);
    } else {
        SET_REG_FIELD_RLWIMI(reg, 2, 20, (op >> 1) & 3);
        SET_REG_FIELD_RLWIMI(reg, 2, 16, 3);
    }
    SET_REG_FIELD_RLWIMI(reg, 1, 19, clamp);
    SET_REG_FIELD_RLWIMI(reg, 2, 22, out_reg);
    GX_WRITE_RAS_REG(reg);
    gx->teva[stage] = reg;
    gx->bpSentNot = 0;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))

void fn_800371F8(s32 id, GXColor color) {
    u32 reg_ra = 0;
    u32 reg_bg = 0;

    SET_REG_FIELD(reg_ra, 11, 0, color.r);
    SET_REG_FIELD(reg_ra, 11, 12, color.a);
    SET_REG_FIELD(reg_ra, 8, 24, 0xe0 + id * 2);
    SET_REG_FIELD(reg_bg, 11, 0, color.b);
    SET_REG_FIELD(reg_bg, 11, 12, color.g);
    SET_REG_FIELD(reg_bg, 8, 24, 0xe1 + id * 2);
    GX_WRITE_RAS_REG(reg_ra);
    GX_WRITE_RAS_REG(reg_bg);
    GX_WRITE_RAS_REG(reg_bg);
    GX_WRITE_RAS_REG(reg_bg);
    gx->bpSentNot = 0;
}

typedef struct GXColorS10 {
    s16 r, g, b, a;
} GXColorS10;

void fn_8003726C(s32 id, GXColorS10 color) {
    u32 reg_ra = 0;
    u32 reg_bg = 0;

    SET_REG_FIELD(reg_ra, 11, 0, color.r & 0x7ff);
    SET_REG_FIELD(reg_ra, 11, 12, color.a & 0x7ff);
    SET_REG_FIELD(reg_ra, 8, 24, 0xe0 + id * 2);
    SET_REG_FIELD(reg_bg, 11, 0, color.b & 0x7ff);
    SET_REG_FIELD(reg_bg, 11, 12, color.g & 0x7ff);
    SET_REG_FIELD(reg_bg, 8, 24, 0xe1 + id * 2);
    GX_WRITE_RAS_REG(reg_ra);
    GX_WRITE_RAS_REG(reg_bg);
    GX_WRITE_RAS_REG(reg_bg);
    GX_WRITE_RAS_REG(reg_bg);
    gx->bpSentNot = 0;
}

void fn_800372E0(s32 id, GXColor color) {
    u32 reg_ra = 0;
    u32 reg_bg = 0;

    SET_REG_FIELD(reg_ra, 8, 0, color.r);
    SET_REG_FIELD(reg_ra, 8, 12, color.a);
    SET_REG_FIELD(reg_ra, 4, 20, 8);
    SET_REG_FIELD(reg_ra, 8, 24, 0xe0 + id * 2);
    SET_REG_FIELD(reg_bg, 8, 0, color.b);
    SET_REG_FIELD(reg_bg, 8, 12, color.g);
    SET_REG_FIELD(reg_bg, 4, 20, 8);
    SET_REG_FIELD(reg_bg, 8, 24, 0xe1 + id * 2);
    GX_WRITE_RAS_REG(reg_ra);
    GX_WRITE_RAS_REG(reg_bg);
    gx->bpSentNot = 0;
}

void GXSetTevKColorSel(GXTevStageID stage, GXTevKColorSel sel) {
    u32 *reg;
    reg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        (*reg) = (*reg & ~(((1 << ((17 - 13 + 1))) - 1) << (31 - (13) - ((17 - 13 + 1)) + 1))) |
                 ((int)(sel) << (31 - (13) - ((17 - 13 + 1)) + 1));
    } else {
        (*reg) = (*reg & ~(((1 << ((27 - 23 + 1))) - 1) << (31 - (23) - ((27 - 23 + 1)) + 1))) |
                 ((int)(sel) << (31 - (23) - ((27 - 23 + 1)) + 1));
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

void GXSetTevKAlphaSel(GXTevStageID stage, GXTevKAlphaSel sel) {
    u32 *reg;
    reg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        (*reg) = (*reg & ~(((1 << ((12 - 8 + 1))) - 1) << (31 - (8) - ((12 - 8 + 1)) + 1))) |
                 ((int)(sel) << (31 - (8) - ((12 - 8 + 1)) + 1));
    } else {
        (*reg) = (*reg & ~(((1 << ((22 - 18 + 1))) - 1) << (31 - (18) - ((22 - 18 + 1)) + 1))) |
                 ((int)(sel) << (31 - (18) - ((22 - 18 + 1)) + 1));
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

void GXSetTevSwapMode(GXTevStageID stage, GXTevSwapSel rasSel, GXTevSwapSel texSel) {
    u32 *reg = &gx->teva[stage];
    (*reg) = (*reg & ~(((1 << ((31 - 30 + 1))) - 1) << (31 - (30) - ((31 - 30 + 1)) + 1))) |
             ((int)(rasSel) << (31 - (30) - ((31 - 30 + 1)) + 1));
    (*reg) = (*reg & ~(((1 << ((29 - 28 + 1))) - 1) << (31 - (28) - ((29 - 28 + 1)) + 1))) |
             ((int)(texSel) << (31 - (28) - ((29 - 28 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

void GXSetTevSwapModeTable(GXTevSwapSel table, GXTevColorChan red, GXTevColorChan green, GXTevColorChan blue,
                 GXTevColorChan alpha) {
    u32 *reg;
    reg = &gx->tevKsel[table << 1];
    (*reg) = (*reg & ~(((1 << ((31 - 30 + 1))) - 1) << (31 - (30) - ((31 - 30 + 1)) + 1))) |
             ((int)(red) << (31 - (30) - ((31 - 30 + 1)) + 1));
    (*reg) = (*reg & ~(((1 << ((29 - 28 + 1))) - 1) << (31 - (28) - ((29 - 28 + 1)) + 1))) |
             ((int)(green) << (31 - (28) - ((29 - 28 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (*reg);
    ;
    reg = &gx->tevKsel[(table << 1) + 1];
    (*reg) = (*reg & ~(((1 << ((31 - 30 + 1))) - 1) << (31 - (30) - ((31 - 30 + 1)) + 1))) |
             ((int)(blue) << (31 - (30) - ((31 - 30 + 1)) + 1));
    (*reg) = (*reg & ~(((1 << ((29 - 28 + 1))) - 1) << (31 - (28) - ((29 - 28 + 1)) + 1))) |
             ((int)(alpha) << (31 - (28) - ((29 - 28 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

void GXSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1) {
    u32 reg = 0xF3000000;
    (reg) = (reg & ~(((1 << ((31 - 24 + 1))) - 1) << (31 - (24) - ((31 - 24 + 1)) + 1))) |
            ((int)(ref0) << (31 - (24) - ((31 - 24 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((23 - 16 + 1))) - 1) << (31 - (16) - ((23 - 16 + 1)) + 1))) |
            ((int)(ref1) << (31 - (16) - ((23 - 16 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((15 - 13 + 1))) - 1) << (31 - (13) - ((15 - 13 + 1)) + 1))) |
            ((int)(comp0) << (31 - (13) - ((15 - 13 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((12 - 10 + 1))) - 1) << (31 - (10) - ((12 - 10 + 1)) + 1))) |
            ((int)(comp1) << (31 - (10) - ((12 - 10 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((9 - 8 + 1))) - 1) << (31 - (8) - ((9 - 8 + 1)) + 1))) |
            ((int)(op) << (31 - (8) - ((9 - 8 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (reg);
    ;
    gx->bpSentNot = ((GXBool)0);
}

void GXSetZTexture(GXZTexOp op, GXTexFmt format, u32 bias) {
    u32 val1;
    u32 val2;
    u32 val3;
    val1 = 0;
    (val1) = (val1 & ~(((1 << ((31 - 8 + 1))) - 1) << (31 - (8) - ((31 - 8 + 1)) + 1))) |
             ((int)(bias) << (31 - (8) - ((31 - 8 + 1)) + 1));
    (val1) = (val1 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
             ((int)(0xF4) << (31 - (0) - ((7 - 0 + 1)) + 1));
    val2 = 0;
    switch (format) {
    case GX_TF_Z8:
        val3 = 0;
        break;
    case GX_TF_Z16:
        val3 = 1;
        break;
    case GX_TF_Z24X8:
        val3 = 2;
        break;
    default:
        val3 = 2;
        break;
    }
    (val2) = (val2 & ~(((1 << ((31 - 30 + 1))) - 1) << (31 - (30) - ((31 - 30 + 1)) + 1))) |
             ((int)(val3) << (31 - (30) - ((31 - 30 + 1)) + 1));
    (val2) = (val2 & ~(((1 << ((29 - 28 + 1))) - 1) << (31 - (28) - ((29 - 28 + 1)) + 1))) |
             ((int)(op) << (31 - (28) - ((29 - 28 + 1)) + 1));
    (val2) = (val2 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
             ((int)(0xF5) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (val1);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (val2);
    ;
    gx->bpSentNot = ((GXBool)0);
}

extern int lbl_8012B3B8[];

void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color) {

    u32 *reg;
    u32 tempMap;
    u32 tempCoord;
    reg = &gx->tref[stage / 2];
    gx->texmapId[stage] = map;
    tempMap = map & ~0x100;
    tempMap = (tempMap >= GX_MAX_TEXMAP) ? GX_TEXMAP0 : tempMap;
    if (coord >= GX_MAXCOORD) {
        tempCoord = GX_TEXCOORD0;
        gx->tevTcEnab = gx->tevTcEnab & ~(1 << stage);
    } else {
        tempCoord = coord;
        gx->tevTcEnab = gx->tevTcEnab | (1 << stage);
    }
    if (stage & 1) {
        (*reg) = (*reg & ~(((1 << ((19 - 17 + 1))) - 1) << (31 - (17) - ((19 - 17 + 1)) + 1))) |
                 ((int)(tempMap) << (31 - (17) - ((19 - 17 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((16 - 14 + 1))) - 1) << (31 - (14) - ((16 - 14 + 1)) + 1))) |
                 ((int)(tempCoord) << (31 - (14) - ((16 - 14 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((12 - 10 + 1))) - 1) << (31 - (10) - ((12 - 10 + 1)) + 1))) |
                 ((int)((color == GX_COLOR_NULL ? 7 : lbl_8012B3B8[color]))
                  << (31 - (10) - ((12 - 10 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((13 - 13 + 1))) - 1) << (31 - (13) - ((13 - 13 + 1)) + 1))) |
                 ((int)(((map != GX_TEXMAP_NULL) && !(map & 0x100)))
                  << (31 - (13) - ((13 - 13 + 1)) + 1));
    } else {
        (*reg) = (*reg & ~(((1 << ((31 - 29 + 1))) - 1) << (31 - (29) - ((31 - 29 + 1)) + 1))) |
                 ((int)(tempMap) << (31 - (29) - ((31 - 29 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((28 - 26 + 1))) - 1) << (31 - (26) - ((28 - 26 + 1)) + 1))) |
                 ((int)(tempCoord) << (31 - (26) - ((28 - 26 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((24 - 22 + 1))) - 1) << (31 - (22) - ((24 - 22 + 1)) + 1))) |
                 ((int)((color == GX_COLOR_NULL ? 7 : lbl_8012B3B8[color]))
                  << (31 - (22) - ((24 - 22 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((25 - 25 + 1))) - 1) << (31 - (25) - ((25 - 25 + 1)) + 1))) |
                 ((int)(((map != GX_TEXMAP_NULL) && !(map & 0x100)))
                  << (31 - (25) - ((25 - 25 + 1)) + 1));
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
    gx->dirtyState |= 1;
}

void GXSetNumTevStages(u32 arg0) {
    GXData *state = gx;
    u32 value;
    value = (state->genMode & 0xFFFFC3FF) | (((arg0 & 0xFF) - 1) << 10);
    state->genMode = value;
    state->dirtyState |= 4;
}
