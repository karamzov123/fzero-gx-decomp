#include "types.h"

extern u32 OSDisableInterrupts(void);
extern u32 lbl_801A6924;
extern u8 lbl_801A692C[8];
extern u32 OSSleepThread(u32);
extern u32 OSRestoreInterrupts(u32);

void VIWaitForRetrace(void) {
    u32 interrupts;
    u32 state;

    interrupts = OSDisableInterrupts();
    state = lbl_801A6924;
    do {
        OSSleepThread((u32)&lbl_801A692C);
    } while (state == lbl_801A6924);
    OSRestoreInterrupts(interrupts);
}
