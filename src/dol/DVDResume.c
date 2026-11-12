#include "types.h"

extern volatile u32 PauseFlag; /* fzgx-allow: S2 global flags may change asynchronously */
extern volatile s32 PausingFlag; /* fzgx-allow: S2 global flags may change asynchronously */
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void stateReady(void);

void DVDResume(void) {
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    PauseFlag = 0;
    if (PausingFlag) {
        PausingFlag = 0;
        stateReady();
    }
    OSRestoreInterrupts(interrupts);
}
