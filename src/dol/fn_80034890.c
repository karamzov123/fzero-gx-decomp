#include "types.h"

typedef struct {
    u8 pad0[0x204];
    u32 field204;
    u8 pad208[0x2ec];
    u32 field4f4;
} GxState;

extern u32 gx;

void fn_80034890(s32 mode) {
    GxState *state;

    switch (mode) {
    case 1:
        mode = 2;
        break;
    case 2:
        mode = 1;
        break;
    }

    state = (GxState *)gx;
    state->field204 = (state->field204 & 0xffff3fff) | (mode << 14);
    state->field4f4 |= 4;
}
