#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetCopyClear(GXColor color, u32 clear_z) {
    u32 r6 = 0;
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
           ((int)(color.r) << (31 - (24) - (8) + 1));
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (16) - (8) + 1))) |
           ((int)(color.a) << (31 - (16) - (8) + 1));
    (r6) =
        (r6 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) | ((int)(0x4f) << (31 - (0) - (8) + 1));
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = r6;
    r6 = 0;
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
           ((int)(color.b) << (31 - (24) - (8) + 1));
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (16) - (8) + 1))) |
           ((int)(color.g) << (31 - (16) - (8) + 1));
    (r6) =
        (r6 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) | ((int)(0x50) << (31 - (0) - (8) + 1));
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = r6;
    r6 = 0;
    (r6) = (r6 & ~(((1 << (24)) - 1) << (31 - (8) - (24) + 1))) |
           ((int)(clear_z) << (31 - (8) - (24) + 1));
    (r6) =
        (r6 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) | ((int)(0x51) << (31 - (0) - (8) + 1));
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = r6;
    gx->bpSentNot = 0;
}
