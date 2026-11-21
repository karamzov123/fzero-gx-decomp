#include "types.h"
#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"


/* --- dol/DVDLowBreak.c --- */
extern u32 StopAtNextInt;
extern u32 lbl_801A6878;

s32 DVDLowBreak(void) {
    StopAtNextInt = 1;
    lbl_801A6878 = 1;
    return 1;
}

/* --- dol/DVDLowClearCallback.c --- */
typedef void (*DVDLowCallback)(u32 intType);

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern DVDLowCallback Callback;

DVDLowCallback DVDLowClearCallback() {
    DVDLowCallback old;
    __DIRegs[1] = 0;
    old = Callback;
    Callback = ((void *)0);
    return old;
}

/* --- dol/__DVDLowSetWAType.c --- */
extern u32 OSDisableInterrupts(u32, u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 WorkAroundSeekLocation;
extern u32 WorkAroundType;

void __DVDLowSetWAType(u32 arg0, u32 arg1) {
    u32 t0;
    t0 = OSDisableInterrupts(arg0, arg1);
    WorkAroundType = (arg0 + 0);
    WorkAroundSeekLocation = (arg1 + 0);
    OSRestoreInterrupts(t0);
}
