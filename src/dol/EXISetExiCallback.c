#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#pragma scheduling off

extern EXIControl Ecb[3];

void SetExiInterruptMask(s32 chan, EXIControl *exi);

EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback) {
    EXIControl *exi = &Ecb[chan];
    EXICallback prev;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    prev = exi->exiCallback;
    exi->exiCallback = exiCallback;
    if (chan != 2) {
        SetExiInterruptMask(chan, exi);
    } else {
        SetExiInterruptMask(0, &Ecb[0]);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}
