#include "types.h"
#include "dolphin/os/OSThread.h"

typedef void (*Fn8004E7D4_Callback)(u32);

struct Fn8004E7D4_State {
    u8 pad_0[0xC];
    s32 unk_C;
    u8 pad_10[0xC];
    s32 unk_1C;
    u8 pad_20[8];
    OSThread thread;
    u8 pad_320[0xCA0 - 0x28 - sizeof(OSThread)];
    s32 unk_CA0;
    s32 unk_CA4;
};

extern struct Fn8004E7D4_State lbl_8017E980;
extern u32 lbl_8012B918[6];
extern u32 lbl_8012B930[];

extern s32 fn_80058C94(void);
extern void OSSetThreadPriority(void *thread, u32 value);

void fn_8004E7D4(void) {
    struct Fn8004E7D4_State *state;
    u32 *thread_config;
    u32 *callback;

    state = &lbl_8017E980;
    thread_config = lbl_8012B918;
    callback = lbl_8012B930;

    while (state->unk_CA4 == 1) {
        state->unk_1C += 1;
        if (fn_80058C94() == 0 || state->unk_C == 1) {
            if (state->unk_C == 1) {
                state->unk_C = 0;
                OSSetThreadPriority(&state->thread, thread_config[5]);
            }
            if (lbl_8012B930[0] != 0) {
                ((Fn8004E7D4_Callback)lbl_8012B930[0])(callback[1]);
            }
            OSSuspendThread(&state->thread);
        }
    }
    state->unk_CA0 = 1;
}
