#include "types.h"
#include "dolphin/os/OSThread.h"

extern u32 lbl_8017E980[];
extern u32 fn_800102AC(void);
extern void OSSetThreadPriority(u32, u32);

struct GlobalState {
    u32 unk0[2];
    volatile s32 count;  /* decremented from interrupt context without masking */
    u8 pad_c[0x964];
    u32 unk_970;
    u8 pad_974[0x314];
    u32 unk_c88;
    u32 unk_c8c;
};

void fn_8004EA94(void) {
    struct GlobalState *state;
    u32 value;

    state = (struct GlobalState *)lbl_8017E980;
    state->count--;
    if (state->count == 0) {
        value = fn_800102AC();
        OSSuspendThread((OSThread *)&state->unk_970);
        OSSetThreadPriority(value, state->unk_c88);
    }
}
