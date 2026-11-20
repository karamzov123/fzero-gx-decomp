#include "types.h"

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

void fn_80023394(u32 arg0, u32 arg1) {
    u32 *v0;
    u32 *v1;

    v0 = (u32 *)(arg0 + 438);
    v1 = (u32 *)arg1;
    OSDisableInterrupts();
    v0[0] = v1[0];
    v0[1] = v1[1];
    v0[2] = v1[2];
    v0[3] = v1[3];
    v0[4] = v1[4];
    v0[5] = v1[5];
    v0[6] = v1[6];
    v0[7] = v1[7];
    v0[8] = v1[8];
    v0[9] = v1[9];
    *(u32 *)((u8 *)arg0 + 28) |= 0x20000;
    OSRestoreInterrupts();
}
