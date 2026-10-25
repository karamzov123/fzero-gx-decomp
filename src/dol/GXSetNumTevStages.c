#include "types.h"

struct fn_800377C8_gx_T {
    u8 pad_0[0x204];
    u32 unk_204;
    u8 pad_208[0x2EC];
    u32 unk_4F4;
};

extern struct fn_800377C8_gx_T *gx;

void GXSetNumTevStages(u32 arg0) {
    struct fn_800377C8_gx_T *state = gx;
    u32 value;
    value = (state->unk_204 & 0xFFFFC3FF) | (((arg0 & 0xFF) - 1) << 10);
    state->unk_204 = value;
    state->unk_4F4 |= 4;
}
