#include "types.h"

#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS)
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS)

struct fn_80037BF4_gx_T {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x1D8];
    u32 unk_1DC;
};

extern struct fn_80037BF4_gx_T *gx;

void GXSetZCompLoc(u32 arg0) {
    struct fn_80037BF4_gx_T *state = gx;
    u32 value;

    state->unk_1DC = (state->unk_1DC & 0xffffffbf) | ((arg0 & 0xff) << 6);
    GXWGFifo8 = 0x61;
    value = state->unk_1DC;
    GXWGFifo = value;
    state->unk_2 = 0;
}
