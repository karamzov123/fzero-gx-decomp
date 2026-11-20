#include "types.h"

struct fn_80034834_gx_T {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0xb4];
    u32 unk_b8[1];
};

extern struct fn_80034834_gx_T *gx;

void fn_80034834(u32 arg0, u32 arg1, u32 arg2) {
    struct fn_80034834_gx_T *reg;
    u32 command;
    // The GX write-gather FIFO is memory-mapped hardware.
    volatile u8 *fifo;

    reg = gx;
    reg->unk_b8[arg0] = (reg->unk_b8[arg0] & 0xFFFBFFFF) | ((arg1 & 0xFF) << 18);
    reg->unk_b8[arg0] = (reg->unk_b8[arg0] & 0xFFF7FFFF) | ((arg2 & 0xFF) << 19);
    command = 0x61;
    fifo = (volatile u8 *)((u8 *)0xCC010000 + -32768); /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *fifo = command;
    // The FIFO data write is volatile because it accesses memory-mapped hardware.
    *(volatile u32 *)fifo = *(u32 *)((u8 *)reg->unk_b8 + arg0 * 4);
    reg->unk_2 = 0;
}
