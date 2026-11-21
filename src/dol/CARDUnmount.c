#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"


/* --- dol/CARDUnmount.c --- */
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);

void DoUnmount(s32 chan, s32 result);

void OSCancelAlarm(OSAlarm *alarm);

extern CARDControl lbl_80177960[2];

static inline void DoUnmount(s32 chan, s32 result) {
    CARDControl *card;
    BOOL enabled;
    card = &lbl_80177960[chan];
    enabled = OSDisableInterrupts();
    if (card->attached) {
        EXISetExiCallback(chan, 0);
        EXIDetach(chan);
        OSCancelAlarm(&card->alarm);
        card->attached = 0;
        card->result = result;
        card->mountStep = 0;
    }
    OSRestoreInterrupts(enabled);
}

s32 CARDUnmount(s32 chan) {
    CARDControl *card;
    s32 result;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    DoUnmount(chan, -3);
    return 0;
}
