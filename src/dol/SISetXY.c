#include <dolphin/si/SIPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

vu32 __SIRegs[64] : FZGX_ADDR___SIRegs;

extern SIControl Si;

u32 SISetXY(u32 x, u32 y) {
    u32 poll;
    BOOL enabled;
    poll = x << 16;
    poll |= y << 8;
    enabled = OSDisableInterrupts();
    Si.poll &= ~(0x03ff0000 | 0x0000ff00);
    Si.poll |= poll;
    poll = Si.poll;
    __SIRegs[12] = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}
