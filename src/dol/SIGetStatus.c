#include "types.h"

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern u32 Type[];

u32 SIGetStatus(s32 channel) {
    u32 status;
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    status = *(u32 *)0xCC006438; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    status >>= ((3 - channel) * 8);
    if ((status & 8) != 0 && (Type[channel] & 0x80) == 0) {
        Type[channel] = 8;
    }
    OSRestoreInterrupts(interrupts);
    return status;
}
