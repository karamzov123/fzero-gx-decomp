#include "sdk_addresses.h"

#include "types.h"
#include <dolphin/gx/GXPriv.h>

void fn_80035110(void *dest, GXBool doClear);
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO;

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
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (reg);
        ;
        reg = gx->cmode0;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = reg & 0xFFFFFFFC;
        ;
    }
    check = ((GXBool)0);
    if (doClear || (gx->peCtrl & 0x7) == 3) {
        if ((gx->peCtrl >> 6 & 0x1) == 1) {
            check = ((GXBool)1);
            GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
            GXFIFO.s32 = (gx->peCtrl & 0xFFFFFFBF);
            ;
        }
    }
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpDispSrc);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpDispSize);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpDispStride);
    ;
    newDest = (u32)dest & 0x3FFFFFFF;
    {
        u32 reg;
        reg = 0;
    reg = (reg & ~(((1 << ((31 - 11 + 1))) - 1) << (31 - (11) - ((31 - 11 + 1)) + 1))) |
            ((newDest >> 5) << (31 - (11) - ((31 - 11 + 1)) + 1));
    reg = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((0x4B) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (reg);
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
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->cpDisp);
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
