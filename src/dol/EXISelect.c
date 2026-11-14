#include <dolphin/exi/EXIPriv.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

extern EXIControl Ecb[3];

BOOL __EXIProbe(s32 chan);

BOOL EXISelect(s32 chan, u32 dev, u32 freq) {
    EXIControl *exi = &Ecb[chan];
    u32 cpr;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & 0x04) ||
        chan != 2 && (dev == 0 && !(exi->state & 0x08) && !__EXIProbe(chan) ||
                      !(exi->state & 0x10) || (exi->dev != dev))) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state |= 0x04;
    cpr = (__EXIRegs[((chan) * 5) + (0)]);
    cpr &= 0x405;
    cpr |= ((1u << (dev)) << 7) | ((freq) << 4);
    (__EXIRegs[((chan) * 5) + (0)]) = cpr;
    if (exi->state & 0x08) {
        switch (chan) {
        case 0:
            __OSMaskInterrupts((0x80000000u >> (11)));
            break;
        case 1:
            __OSMaskInterrupts((0x80000000u >> (14)));
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
