#include "types.h"
// fzgx-allow: A1 hardware FIFO register
#define GX_FIFO_ADDRESS 0xCC008000 // fzgx-allow: A1 hardware FIFO register
// fzgx-allow: A2 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo8 (*(volatile u8 *)GX_FIFO_ADDRESS)
// fzgx-allow: A2 hardware FIFO register
// fzgx-allow: S2 hardware FIFO register
#define GXWGFifo (*(volatile u32 *)GX_FIFO_ADDRESS)

extern u32 gx;
extern void __GXFlushTextureState(void);

struct GXState {
    u8 pad_000[0x7c];
    u32 state_07c;
};

void GXSetFieldMode(u8 arg0, u8 arg1) {
    struct GXState *state = (struct GXState *)gx;
    state->state_07c = (state->state_07c & 0xFFBFFFFF) | ((arg1 & 0xFF) << 22);
    GXWGFifo8 = 0x61;
    GXWGFifo = state->state_07c;
    __GXFlushTextureState();
    GXWGFifo8 = 0x61;
    GXWGFifo = ((arg0 & 0xFF) | 0x68000000);
    __GXFlushTextureState();
}
