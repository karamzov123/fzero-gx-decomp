#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"

void __GXSendFlushPrim(void) {
    u32 i;
    u32 sz = gx->vNum * gx->vLim;
    GXWGFifo.u8 = 0x98;
    GXWGFifo.u16 = gx->vNum;
    for (i = 0; i < sz; i += 4) {
        GXWGFifo.s32 = 0;
    }
    gx->bpSentNot = 1;
}

void GXSetLineWidth(u8 width, GXTexOffset offsets) {
    GXData *data = gx;
    (data->lpSize) = (data->lpSize & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
                     ((int)(width) << (31 - (24) - (8) + 1));
    (data->lpSize) = (data->lpSize & ~(((1 << (3)) - 1) << (31 - (13) - (3) + 1))) |
                     ((int)(offsets) << (31 - (13) - (3) + 1));
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = data->lpSize;
    data->bpSentNot = 0;
}

void GXSetPointSize(u32 arg0, u32 arg1) {
    GXData *reg;
    u32 shifted;
    u32 command;
    // The FIFO pointer is volatile because it names memory-mapped hardware.
    volatile u8 *fifo;
    u16 zero;

    reg = gx;
    shifted = arg1 << 19;
    command = 0x61;
    // The GX write-gather FIFO is memory-mapped hardware.
    fifo = (volatile u8 *)((u8 *)0xCC010000 + -32768); /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    reg->lpSize = ((reg->lpSize & 0xFFFF00FF) & ~0xFF00) | ((arg0 << 8) & 0xFF00);
    zero = 0;
    reg->lpSize = (reg->lpSize & 0xFFC7FFFF) | shifted;
    *fifo = command;
    // The FIFO write is volatile because it accesses memory-mapped hardware.
    *(volatile u32 *)fifo = reg->lpSize;
    reg->bpSentNot = zero;
}

void fn_80034834(u32 arg0, u32 arg1, u32 arg2) {
    GXData *reg;
    u32 command;
    // The GX write-gather FIFO is memory-mapped hardware.
    volatile u8 *fifo;

    reg = gx;
    reg->suTs0[arg0] = (reg->suTs0[arg0] & 0xFFFBFFFF) | ((arg1 & 0xFF) << 18);
    reg->suTs0[arg0] = (reg->suTs0[arg0] & 0xFFF7FFFF) | ((arg2 & 0xFF) << 19);
    command = 0x61;
    fifo = (volatile u8 *)((u8 *)0xCC010000 + -32768); /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *fifo = command;
    // The FIFO data write is volatile because it accesses memory-mapped hardware.
    *(volatile u32 *)fifo = *(u32 *)((u8 *)reg->suTs0 + arg0 * 4);
    reg->bpSentNot = 0;
}
