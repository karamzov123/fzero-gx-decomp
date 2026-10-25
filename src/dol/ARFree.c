#include "types.h"

extern u32 *lbl_801A69F8;
extern u32 lbl_801A69F4;
extern u32 lbl_801A69F0;
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);

u32 ARFree(u32 *arg0) {
    u32 state = OSDisableInterrupts();
    lbl_801A69F8 = (u32 *)((u8 *)lbl_801A69F8 - 4);
    if (arg0 != 0) {
        *arg0 = *lbl_801A69F8;
    }
    {
        u32 value = *lbl_801A69F8;
        lbl_801A69F0 = lbl_801A69F0 - value;
        lbl_801A69F4 = lbl_801A69F4 + 1;
    }
    OSRestoreInterrupts(state);
    return lbl_801A69F0;
}
