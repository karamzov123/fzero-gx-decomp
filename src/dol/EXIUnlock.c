#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSRtc.h>
#pragma scheduling off

extern EXIControl Ecb[3];

void SetExiInterruptMask(s32 chan, EXIControl *exi);

BOOL EXIUnlock(s32 chan) {
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
