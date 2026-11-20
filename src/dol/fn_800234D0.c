#include "types.h"

extern u32 OSDisableInterrupts(void);
extern f32 lbl_801A6F78[2];
extern u32 __cvt_fp2unsigned(f32 value);
extern void OSRestoreInterrupts(u32 level);

typedef struct Fn800234D0State {
    u8 pad_000[0x1c];
    u32 flags;
    u8 pad_020[0x1be];
    u16 value_high;
    u16 value_low;
} Fn800234D0State;

void fn_800234D0(Fn800234D0State *state, f32 value) {
    f32 scaled;
    u32 value_high;
    u32 value_low;
    u32 level;

    level = OSDisableInterrupts();
    scaled = lbl_801A6F78[0] * value;
    value_high = __cvt_fp2unsigned(scaled);
    value_low = __cvt_fp2unsigned(scaled);
    if (value_low > 0x40000) {
        value_high = 0x40000;
    }
    state->value_high = (value_high >> 16);
    state->value_low = value_high;
    state->flags |= 0x80000;
    OSRestoreInterrupts(level);
}
