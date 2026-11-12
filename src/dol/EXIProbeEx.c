#include <dolphin/exi/EXIPriv.h>
#include "sdk_addresses.h"
#pragma scheduling off

s32 EXIGetID(s32 chan, u32 dev, u32 *id);

extern EXIControl Ecb[3];

s32 __EXIProbeStartTime[2] : FZGX_ADDR___EXIProbeStartTime;

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

s32 EXIProbeEx(s32 chan) {
    if (EXIProbe(chan)) {
        return 1;
    } else if (__EXIProbeStartTime[chan] != 0) {
        return 0;
    } else {
        return -1;
    }
}
