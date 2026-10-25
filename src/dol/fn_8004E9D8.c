#include "types.h"

struct Fn8004E9D8 {
    u8 pad_0[0xC];
    s32 initialized_C;
    u8 pad_1[0xCA0 - 0x10];
    s32 field_CA0;
};

extern struct Fn8004E9D8 lbl_8017E980;
extern u32 lbl_8012B918[6];
extern char lbl_80091160[49];

extern void OSSetThreadPriority(void* self, u32 value);
extern void OSResumeThread(void* self);
extern void fn_800595A4(const char* message);

void fn_8004E9D8(void) {
    struct Fn8004E9D8* state = &lbl_8017E980;
    s32 i;
    s32 limit;

    if (state->field_CA0 != 1) {
        state->initialized_C = 1;
        OSSetThreadPriority(&state->pad_0[0x28], lbl_8012B918[0]);

        i = 0;
        limit = (s32)0x0bebc200;
        while (i < limit) {
            OSResumeThread(&state->pad_0[0x28]);
            if (state->initialized_C == 0) {
                break;
            }
            i += 1;
        }
        if (i == limit) {
            fn_800595A4(lbl_80091160);
        }
        OSSetThreadPriority(&state->pad_0[0x28], lbl_8012B918[5]);
    }
}
