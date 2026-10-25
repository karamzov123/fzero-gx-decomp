#include "types.h"

typedef struct fn_8004E4DC_state {
    u8 unk_0[4];
    s32 counter;
    u8 unk_8[0x20];
    u8 thread_28[0x318];
    u8 thread_340[0x318];
    u8 thread_658[0x318];
    u8 thread_970[0x330];
    s32 flag_ca0;
    s32 value_ca4;
    s32 flag_ca8;
    s32 value_cac;
} fn_8004E4DC_state;

extern fn_8004E4DC_state lbl_8017E980;
extern void OSSetThreadPriority(void *, s32);
extern void OSResumeThread(void *);
extern void OSCancelThread(void *);
extern void fn_80058B54(void);

void fn_8004E4DC(void) {
    fn_8004E4DC_state *state = &lbl_8017E980;

    if (--state->counter == 0) {
        state->value_ca4 = 0;
        OSSetThreadPriority(&state->thread_28, 1);
        while (state->flag_ca0 == 0) {
            OSResumeThread(&state->thread_28);
        }
        OSCancelThread(&state->thread_340);
        OSCancelThread(&state->thread_658);
        state->value_cac = 0;
        OSResumeThread(&state->thread_970);
        while (state->flag_ca8 == 0) {
            OSResumeThread(&state->thread_970);
        }
        fn_80058B54();
    }
}
