#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#pragma scheduling off

s32 EXIGetID(s32 chan, u32 dev, u32 *id);

extern EXIControl Ecb[3];

BOOL __EXIProbe(s32 chan);

static inline BOOL EXIProbe(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL rc;
    u32 id;
    rc = __EXIProbe(chan);
    if (rc && exi->idTime == 0) {
        rc = EXIGetID(chan, 0, &id) ? 1 : 0;
    }
    return rc;
}

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

BOOL EXIAttach(s32 chan, EXICallback extCallback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    BOOL rc;
    EXIProbe(chan);
    enabled = OSDisableInterrupts();
    if (exi->idTime == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    rc = __EXIAttach(chan, extCallback);
    OSRestoreInterrupts(enabled);
    return rc;
}
