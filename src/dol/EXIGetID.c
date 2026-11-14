#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include "sdk_addresses.h"
#pragma scheduling off

extern EXIControl Ecb[3];

extern u32 IDSerialPort1;

s32 __EXIProbeStartTime[2] : FZGX_ADDR___EXIProbeStartTime;

void SetExiInterruptMask(s32 chan, EXIControl *exi);

BOOL __EXIProbe(s32 chan);

static inline BOOL __EXIAttach(s32 chan, EXICallback extCallback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if ((exi->state & 0x08) || __EXIProbe(chan) == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    EXIClearInterrupts(chan, 1, 0, 0);
    exi->extCallback = extCallback;
    __OSUnmaskInterrupts((0x80000000u >> (11)) >> (3 * chan));
    exi->state |= 0x08;
    OSRestoreInterrupts(enabled);
    return 1;
}

static inline BOOL EXIDetach(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x08)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }
    if ((exi->state & 0x10) && exi->dev == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x08;
    __OSMaskInterrupts(((0x80000000u >> (11)) | (0x80000000u >> (9))) >> (3 * chan));
    OSRestoreInterrupts(enabled);
    return 1;
}

static inline BOOL EXIUnlock(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    EXICallback unlockedCallback;
    enabled = OSDisableInterrupts();
    if (!(exi->state & 0x10)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state &= ~0x10;
    SetExiInterruptMask(chan, exi);
    if (0 < exi->items) {
        unlockedCallback = exi->queue[0].callback;
        if (0 < --exi->items) {
            memmove(&exi->queue[0], &exi->queue[1], sizeof(exi->queue[0]) * exi->items);
        }
        unlockedCallback(chan, 0);
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

void UnlockedHandler(s32 chan, OSContext *context);

s32 EXIGetID(s32 chan, u32 dev, u32 *id) {
    EXIControl *exi = &Ecb[chan];
    BOOL err;
    u32 cmd;
    s32 startTime;
    BOOL enabled;
    BOOL interrupt;
    if (chan == 0 && dev == 2 && IDSerialPort1) {
        *id = IDSerialPort1;
        return 1;
    }
    if (chan < 2 && dev == 0) {
        if (!__EXIProbe(chan)) {
            return 0;
        }
        if (exi->idTime == __EXIProbeStartTime[chan]) {
            *id = exi->id;
            return exi->idTime;
        }
        if (!__EXIAttach(chan, ((void *)0))) {
            return 0;
        }
        startTime = __EXIProbeStartTime[chan];
    }
    interrupt = OSDisableInterrupts();
    err = !EXILock(chan, dev, (chan < 2 && dev == 0) ? UnlockedHandler : ((void *)0));
    if (!err) {
        err = !EXISelect(chan, dev, 0);
        if (!err) {
            cmd = 0;
            err |= !EXIImm(chan, &cmd, 2, 1, ((void *)0));
            err |= !EXISync(chan);
            err |= !EXIImm(chan, id, 4, 0, ((void *)0));
            err |= !EXISync(chan);
            err |= !EXIDeselect(chan);
        }
        EXIUnlock(chan);
    }
    OSRestoreInterrupts(interrupt);
    if (chan < 2 && dev == 0) {
        EXIDetach(chan);
        enabled = OSDisableInterrupts();
        err |= (startTime != __EXIProbeStartTime[chan]);
        if (!err) {
            exi->id = *id;
            exi->idTime = startTime;
        }
        OSRestoreInterrupts(enabled);
        return err ? 0 : exi->idTime;
    }
    return err ? 0 : !0;
}
