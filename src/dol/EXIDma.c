#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

extern EXIControl Ecb[3];

BOOL EXIDma(s32 chan, void *buf, s32 len, u32 type, EXICallback callback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & (0x01 | 0x02)) || !(exi->state & 0x04)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->tcCallback = callback;
    if (exi->tcCallback) {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts((0x80000000u >> (10)) >> (3 * chan));
    }
    exi->state |= 0x01;
    (__EXIRegs[((chan) * 5) + (1)]) = (u32)buf & 0x3ffffe0;
    (__EXIRegs[((chan) * 5) + (2)]) = (u32)len;
    (__EXIRegs[((chan) * 5) + (3)]) =
        ((((u32)(1)) << 0) | (((u32)(1)) << 1) | (((u32)(type)) << 2) | (((u32)(0)) << 4));
    OSRestoreInterrupts(enabled);
    return 1;
}
