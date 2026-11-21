#include "sdk_addresses.h"

#include "types.h"
#include <dolphin/gx/GXPriv.h>

void fn_8003526C(void *dest, GXBool doClear);
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO;

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
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (reg);
        ;
        reg = gx->cmode0;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (reg & ~3u);
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
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (reg2);
        ;
    }
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpTexSrc);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpTexSize);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpTexStride);
    ;
    newDest = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    reg = (reg & ~(((1 << ((31 - 11 + 1))) - 1) << (31 - (11) - ((31 - 11 + 1)) + 1))) |
            ((newDest >> 5) << (31 - (11) - ((31 - 11 + 1)) + 1));
    reg = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((0x4B) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (reg);
    ;
    gx->cpTex =
        (gx->cpTex & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
        (doClear << (31 - (20) - ((20 - 20 + 1)) + 1));
    gx->cpTex =
        (gx->cpTex & ~(((1 << ((17 - 17 + 1))) - 1) << (31 - (17) - ((17 - 17 + 1)) + 1))) |
        ((0) << (31 - (17) - ((17 - 17 + 1)) + 1));
    gx->cpTex = (gx->cpTex & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                  ((0x52) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpTex);
    ;
    if (doClear) {
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (gx->zmode);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (gx->cmode0);
        ;
    }
    if (check) {
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (gx->peCtrl);
        ;
    }
    gx->bpSentNot = ((GXBool)0);
}
