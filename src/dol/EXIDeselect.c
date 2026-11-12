#include <dolphin/exi/EXIPriv.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

extern EXIControl Ecb[3];

BOOL __EXIProbe(s32 chan);

BOOL EXIDeselect(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    u32 cpr;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x04)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x04;
    cpr = (__EXIRegs[((chan) * 5) + (0)]);
    (__EXIRegs[((chan) * 5) + (0)]) = cpr & 0x405;
    if (exi->state & 0x08) {
        switch (chan) {
        case 0:
            __OSUnmaskInterrupts((0x80000000u >> (11)));
            break;
        case 1:
            __OSUnmaskInterrupts((0x80000000u >> (14)));
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    if (chan != 2 && (cpr & ((1u << (0)) << 7))) {
        return __EXIProbe(chan) ? 1 : 0;
    }
    return 1;
}
