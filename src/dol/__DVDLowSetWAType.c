#include "types.h"

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
