#include <dolphin/exi/EXIPriv.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

OSTime OSGetTime(void);

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

extern EXIControl Ecb[3];

s32 __EXIProbeStartTime[2] : FZGX_ADDR___EXIProbeStartTime;

static inline u32 EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext) {
    u32 cpr;
    u32 prev;
    prev = cpr = (__EXIRegs[((chan) * 5) + (0)]);
    cpr &= 0x7f5;
    if (exi)
        cpr |= 2;
    if (tc)
        cpr |= 8;
    if (ext)
        cpr |= 0x800;
    (__EXIRegs[((chan) * 5) + (0)]) = cpr;
    return prev;
}

BOOL __EXIProbe(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    BOOL rc;
    u32 cpr;
    s32 t;
    if (chan == 2) {
        return 1;
    }
    rc = 1;
    enabled = OSDisableInterrupts();
    cpr = (__EXIRegs[((chan) * 5) + (0)]);
    if (!(exi->state & 0x08)) {
        if (cpr & 0x00000800) {
            EXIClearInterrupts(chan, 0, 0, 1);
            __EXIProbeStartTime[chan] = exi->idTime = 0;
        }
        if (cpr & 0x00001000) {
            t = (s32)(((OSGetTime()) / (((u32)__OSBusClock / 4) / 1000)) / 100) + 1;
            if (__EXIProbeStartTime[chan] == 0) {
                __EXIProbeStartTime[chan] = t;
            }
            if (t - __EXIProbeStartTime[chan] < 300 / 100) {
                rc = 0;
            }
        } else {
            __EXIProbeStartTime[chan] = exi->idTime = 0;
            rc = 0;
        }
    } else if (!(cpr & 0x00001000) || (cpr & 0x00000800)) {
        __EXIProbeStartTime[chan] = exi->idTime = 0;
        rc = 0;
    }
    OSRestoreInterrupts(enabled);
    return rc;
}
