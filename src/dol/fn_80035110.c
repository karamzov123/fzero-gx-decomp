#include "sdk_addresses.h"
#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>

void fn_80035110(void *dest, GXBool doClear);

void fn_80035110(void *dest, GXBool doClear) {
    u32 newDest;
    GXBool check;
    if (doClear) {
        u32 reg;
        reg = gx->zmode;
        reg = (reg & ~(((1 << ((31 - 31 + 1))) - 1) << (31 - (31) - ((31 - 31 + 1)) + 1))) |
                ((1) << (31 - (31) - ((31 - 31 + 1)) + 1));
        reg = (reg & ~(((1 << ((30 - 28 + 1))) - 1) << (31 - (28) - ((30 - 28 + 1)) + 1))) |
                ((7) << (31 - (28) - ((30 - 28 + 1)) + 1));
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg);
        ;
        reg = gx->cmode0;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = reg & 0xFFFFFFFC;
        ;
    }
    check = ((GXBool)0);
    if (doClear || (gx->peCtrl & 0x7) == 3) {
        if ((gx->peCtrl >> 6 & 0x1) == 1) {
            check = ((GXBool)1);
            GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
            GXWGFifo.s32 = (gx->peCtrl & 0xFFFFFFBF);
            ;
        }
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDispSrc);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDispSize);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDispStride);
    ;
    newDest = (u32)dest & 0x3FFFFFFF;
    {
        u32 reg;
        reg = 0;
    reg = (reg & ~(((1 << ((31 - 11 + 1))) - 1) << (31 - (11) - ((31 - 11 + 1)) + 1))) |
            ((newDest >> 5) << (31 - (11) - ((31 - 11 + 1)) + 1));
    reg = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((0x4B) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (reg);
    ;
    }
    gx->cpDisp =
        (gx->cpDisp & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
        (doClear << (31 - (20) - ((20 - 20 + 1)) + 1));
    gx->cpDisp =
        (gx->cpDisp & ~(((1 << ((17 - 17 + 1))) - 1) << (31 - (17) - ((17 - 17 + 1)) + 1))) |
        ((1) << (31 - (17) - ((17 - 17 + 1)) + 1));
    gx->cpDisp = (gx->cpDisp & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                   ((0x52) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDisp);
    ;
    if (doClear) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->zmode);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->cmode0);
        ;
    }
    if (check) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->peCtrl);
        ;
    }
    gx->bpSentNot = ((GXBool)0);
}

void fn_8003526C(void *dest, GXBool doClear);

void fn_8003526C(void *dest, GXBool doClear) {
    u32 reg;
    u32 reg2;
    u32 newDest;
    GXBool check;
    if (doClear) {
        reg = gx->zmode;
        reg = (reg & ~(((1 << ((31 - 31 + 1))) - 1) << (31 - (31) - ((31 - 31 + 1)) + 1))) |
                ((1) << (31 - (31) - ((31 - 31 + 1)) + 1));
        reg = (reg & ~(((1 << ((30 - 28 + 1))) - 1) << (31 - (28) - ((30 - 28 + 1)) + 1))) |
                ((7) << (31 - (28) - ((30 - 28 + 1)) + 1));
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg);
        ;
        reg = gx->cmode0;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg & ~3u);
        ;
    }
    check = ((GXBool)0);
    reg2 = gx->peCtrl;
    if (gx->cpTexZ && (reg2 & 0x7) != 3) {
        check = ((GXBool)1);
        reg2 = (reg2 & ~(((1 << ((31 - 29 + 1))) - 1) << (31 - (29) - ((31 - 29 + 1)) + 1))) |
                 ((3) << (31 - (29) - ((31 - 29 + 1)) + 1));
    }
    if ((doClear || (reg2 & 0x7) == 3) && (reg2 >> 6 & 0x1) == 1) {
        check = ((GXBool)1);
        reg2 = (reg2 & ~(((1 << ((25 - 25 + 1))) - 1) << (31 - (25) - ((25 - 25 + 1)) + 1))) |
                 ((0) << (31 - (25) - ((25 - 25 + 1)) + 1));
    }
    if (check) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg2);
        ;
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTexSrc);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTexSize);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTexStride);
    ;
    newDest = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    reg = (reg & ~(((1 << ((31 - 11 + 1))) - 1) << (31 - (11) - ((31 - 11 + 1)) + 1))) |
            ((newDest >> 5) << (31 - (11) - ((31 - 11 + 1)) + 1));
    reg = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((0x4B) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (reg);
    ;
    gx->cpTex =
        (gx->cpTex & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
        (doClear << (31 - (20) - ((20 - 20 + 1)) + 1));
    gx->cpTex =
        (gx->cpTex & ~(((1 << ((17 - 17 + 1))) - 1) << (31 - (17) - ((17 - 17 + 1)) + 1))) |
        ((0) << (31 - (17) - ((17 - 17 + 1)) + 1));
    gx->cpTex = (gx->cpTex & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                  ((0x52) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTex);
    ;
    if (doClear) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->zmode);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->cmode0);
        ;
    }
    if (check) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->peCtrl);
        ;
    }
    gx->bpSentNot = ((GXBool)0);
}

static inline void set_x2(u16 value) { gx->bpSentNot = value; }

void GXClearBoundingBox(void) {
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x550003FF;
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x560003FF;
    set_x2(((GXBool)0));
}
