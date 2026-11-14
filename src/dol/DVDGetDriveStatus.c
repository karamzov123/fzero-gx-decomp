#include "types.h"

extern u32 DummyCommandBlock[];
extern u32 FatalErrorFlag;
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 PausingFlag;
extern u32 executing;

s32 DVDGetDriveStatus(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2;
    t0 = OSDisableInterrupts();
    v0 = (t0 + 0);
    v2 = t0;
    if ((s32)FatalErrorFlag != 0) {
    v1 = -1;
    } else {
    if ((s32)PausingFlag != 0) {
    v1 = 8;
    } else {
    v1 = executing;
    if (v1 == 0) {
    v1 = 0;
    } else {
    if (v1 == (u32)&DummyCommandBlock) {
    v1 = 0;
    } else {
    t1 = OSDisableInterrupts();
    v2 = t1;
    v1 = *(u32 *)((u8 *)v1 + 12);
    if ((s32)v1 == 3) {
    v1 = 1;
    }
    t2 = OSRestoreInterrupts(v2);
    v2 = t2;
    }
    }
    }
    }
    OSRestoreInterrupts(v0);
    return v1;
}
