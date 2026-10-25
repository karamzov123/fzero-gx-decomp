#include "types.h"

extern u32 gx;

struct GXState {
    u8 pad_000[0x204];
    u32 state_204;
    u8 pad_208[0x2EC];
    u32 state_4F4;
};

void GXSetNumIndStages(u32 arg0) {
    struct GXState *state = (struct GXState *)gx;
    state->state_204 = (state->state_204 & 0xFFF8FFFF) | ((arg0 & 0xFF) << 16);
    state->state_4F4 |= 6;
}
