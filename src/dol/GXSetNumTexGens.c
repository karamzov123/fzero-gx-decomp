#include "types.h"

struct fn_80033D4C_gx_T {
    u8 pad_0[0x204];
    u32 unk_204;
    u8 pad_208[0x2EC];
    u32 unk_4F4;
};

extern struct fn_80033D4C_gx_T *gx;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
} GXWGFifoReg;

#define GXWGFifoAddress ((u32)(0xCC00 << 16) + 0x8000)
// Hardware FIFO register is intentionally volatile.
#define GXWGFifo (*(volatile GXWGFifoReg *)GXWGFifoAddress)

void GXSetNumTexGens(u32 value) {
    struct fn_80033D4C_gx_T *g;
    u32 masked_value;

    g = gx;
    masked_value = value & 0xFF;
    g->unk_204 = (g->unk_204 & ~0xFu) | masked_value;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x103F;
    GXWGFifo.u32 = masked_value;
    g->unk_4F4 |= 4;
}
