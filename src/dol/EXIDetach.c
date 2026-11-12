#include <dolphin/exi/EXIPriv.h>
#pragma scheduling off

extern EXIControl Ecb[3];

BOOL EXIDetach(s32 chan) {
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
