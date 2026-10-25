#include "types.h"

extern volatile u32 PauseFlag_801A68CC; /* fzgx-allow: S2 global flags may change asynchronously */
extern volatile s32 PausingFlag_801A68D0; /* fzgx-allow: S2 global flags may change asynchronously */
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void stateReady(void);

void DVDResume(void) {
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    PauseFlag_801A68CC = 0;
    if (PausingFlag_801A68D0) {
        PausingFlag_801A68D0 = 0;
        stateReady();
    }
    OSRestoreInterrupts(interrupts);
}
