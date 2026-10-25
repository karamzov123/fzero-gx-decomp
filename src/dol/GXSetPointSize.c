#include "types.h"

struct fn_800347EC_gx_T {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x78];
    u32 unk_7C;
};

extern struct fn_800347EC_gx_T *gx;

void GXSetPointSize(u32 arg0, u32 arg1) {
    struct fn_800347EC_gx_T *reg;
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
    reg->unk_7C = ((reg->unk_7C & 0xFFFF00FF) & ~0xFF00) | ((arg0 << 8) & 0xFF00);
    zero = 0;
    reg->unk_7C = (reg->unk_7C & 0xFFC7FFFF) | shifted;
    *fifo = command;
    // The FIFO write is volatile because it accesses memory-mapped hardware.
    *(volatile u32 *)fifo = reg->unk_7C;
    reg->unk_2 = zero;
}
