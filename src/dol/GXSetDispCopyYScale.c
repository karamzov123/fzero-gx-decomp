#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

static inline u32 __GXGetNumXfbLines(u32 height, u32 scale) {
    u32 numLines;
    u32 actualHeight;
    u32 newScale;
    numLines = (height - 1) * 0x100;
    actualHeight = (numLines / scale) + 1;
    newScale = scale;
    if (newScale > 0x80 && newScale < 0x100) {
        while (newScale % 2 == 0) {
            newScale /= 2;
        }
        if (height % newScale == 0) {
            actualHeight++;
        }
    }
    if (actualHeight > 0x400) {
        actualHeight = 0x400;
    }
    return actualHeight;
}

u32 GXSetDispCopyYScale(f32 vertScale) {
    u32 scale;
    GXBool check;
    u32 height;
    u32 reg;
    scale = (u32)(256.0f / vertScale) & 0x1FF;
    check = (scale != 0x100);
    reg = 0;
    (reg) = (reg & ~(((1 << ((31 - 23 + 1))) - 1) << (31 - (23) - ((31 - 23 + 1)) + 1))) |
            ((int)(scale) << (31 - (23) - ((31 - 23 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(0x4E) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (reg);
    ;
    gx->bpSentNot = ((GXBool)0);
    (gx->cpDisp) =
        (gx->cpDisp & ~(((1 << ((21 - 21 + 1))) - 1) << (31 - (21) - ((21 - 21 + 1)) + 1))) |
        ((int)(check) << (31 - (21) - ((21 - 21 + 1)) + 1));
    height = (gx->cpDispSize >> 10 & 0x3FF) + 1;
    return __GXGetNumXfbLines(height, scale);
}
