#include "types.h"


/* --- dol/fn_8004EB00.c --- */
extern u32 lbl_8017E980[];
extern u32 OSDisableInterrupts(void);
extern void OSDisableScheduler(void);
extern u32 fn_800102AC(void);
extern u32 fn_80011358(void);
extern u32 lbl_8012B918[];
extern void OSSetThreadPriority(u32, u32);
extern void OSEnableScheduler(void);
extern void OSRestoreInterrupts(u32);
extern void OSResumeThread(void *);

struct GlobalState {
    u32 unk0[2];
    s32 count;
    u8 pad_c[0x964];
    u32 unk_970;
    u8 pad_974[0x314];
    u32 unk_c88;
    u32 unk_c8c;
};

void fn_8004EB00(void) {
    struct GlobalState *state;
    u32 interrupts;
    u32 value;
    u32 result;

    state = (struct GlobalState *)lbl_8017E980;
    if (state->count == 0) {
        interrupts = OSDisableInterrupts();
        OSDisableScheduler();
        state->unk_c8c = 1;
        value = fn_800102AC();
        result = fn_80011358();
        OSSetThreadPriority(value, lbl_8012B918[0]);
        state->unk_c88 = result;
        state->unk_c8c = 0;
        OSEnableScheduler();
        OSRestoreInterrupts(interrupts);
        OSResumeThread(&state->unk_970);
    }
    state->count++;
}

/* --- dol/fn_8004EBB4.c --- */
extern u32 fn_80059AB4(void);

void fn_8004EBB4(void) {
    fn_80059AB4();
}

/* --- dol/fn_8004EBD4.c --- */
extern u32 fn_80059B44(void);

void fn_8004EBD4(void) {
    fn_80059B44();
}

/* --- dol/fn_8004EBF4.c --- */
extern u32 fn_80058D24(void);

void fn_8004EBF4(void) {
    fn_80058D24();
}

/* --- dol/fn_8004EC14.c --- */
extern u32 VIWaitForRetrace(void);

void fn_8004EC14(void) {
    VIWaitForRetrace();
}
