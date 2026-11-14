#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSRtc.h>
#pragma scheduling off

extern EXIControl Ecb[3];

void SetExiInterruptMask(s32 chan, EXIControl *exi);

BOOL EXILock(s32 chan, u32 dev, EXICallback unlockedCallback) {
    EXIControl *exi = &Ecb[chan];
    BOOL enabled;
    int i;
    enabled = OSDisableInterrupts();
    if (exi->state & 0x10) {
        if (unlockedCallback) {
            for (i = 0; i < exi->items; i++) {
                if (exi->queue[i].dev == dev) {
                    OSRestoreInterrupts(enabled);
                    return 0;
                }
            }
            exi->queue[exi->items].callback = unlockedCallback;
            exi->queue[exi->items].dev = dev;
            exi->items++;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }
    exi->state |= 0x10;
    exi->dev = dev;
    SetExiInterruptMask(chan, exi);
    OSRestoreInterrupts(enabled);
    return 1;
}
