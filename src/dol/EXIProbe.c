#include <dolphin/exi/EXIPriv.h>
#pragma scheduling off

s32 EXIGetID(s32 chan, u32 dev, u32 *id);

extern EXIControl Ecb[3];

BOOL __EXIProbe(s32 chan);

BOOL EXIProbe(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL rc;
    u32 id;
    rc = __EXIProbe(chan);
    if (rc && exi->idTime == 0) {
        rc = EXIGetID(chan, 0, &id) ? 1 : 0;
    }
    return rc;
}
