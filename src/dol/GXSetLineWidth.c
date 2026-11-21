#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetLineWidth(u8 width, GXTexOffset offsets) {
    GXData *data = gx;
    (data->lpSize) = (data->lpSize & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
                     ((int)(width) << (31 - (24) - (8) + 1));
    (data->lpSize) = (data->lpSize & ~(((1 << (3)) - 1) << (31 - (13) - (3) + 1))) |
                     ((int)(offsets) << (31 - (13) - (3) + 1));
    GXFIFO.u8 = 0x61;
    GXFIFO.u32 = data->lpSize;
    data->bpSentNot = 0;
}
