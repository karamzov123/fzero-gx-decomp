#include <dolphin/si/SIPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

vu32 __SIRegs[64] : FZGX_ADDR___SIRegs;

extern SIControl Si;

u32 SIDisablePolling(u32 poll) {
    BOOL enabled;
    if (poll == 0) {
        return Si.poll;
    }
    enabled = OSDisableInterrupts();
    poll >>= (31 - 7);
    poll &= 0xf0;
    poll = Si.poll & ~poll;
    __SIRegs[12] = poll;
    Si.poll = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}
