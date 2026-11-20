#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"


/* --- dol/__CARDMountCallback.c --- */
void DoUnmount(s32 chan, s32 result);
s32 DoMount(s32 chan);

extern CARDControl lbl_80177960[2];

void __CARDMountCallback(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    card = &lbl_80177960[chan];
    switch (result) {
    case 0:
        if (++card->mountStep < (5 + 2)) {
            result = DoMount(chan);
            if (0 <= result) {
                return;
            }
        } else {
            result = __CARDVerify(card);
        }
        break;
    case 1:
        card->unlockCallback = __CARDMountCallback;
        if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
            return;
        }
        card->unlockCallback = 0;
        result = DoMount(chan);
        if (0 <= result) {
            return;
        }
        break;
    case -5:
    case -3:
        DoUnmount(chan, result);
        break;
    }
    callback = card->apiCallback;
    card->apiCallback = 0;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

/* --- dol/CARDMountAsync.c --- */
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);

s32 DoMount(s32 chan);
void OSCancelAlarm(OSAlarm *alarm);
void fn_80029824(s32 chan, s32 result);



u8 GameChoice : FZGX_ADDR_GameChoice;

s32 CARDMountAsync(s32 chan, void *workArea, CARDCallback detachCallback,
                   CARDCallback attachCallback) {
    CARDControl *card;
    BOOL enabled;
    if (chan < 0 || 2 <= chan) {
        return -128;
    }
    if (GameChoice & 0x80) {
        return -3;
    }
    card = &lbl_80177960[chan];
    enabled = OSDisableInterrupts();
    if (card->result == -1) {
        OSRestoreInterrupts(enabled);
        return -1;
    }
    if (!card->attached && (EXIGetState(chan) & 0x08)) {
        OSRestoreInterrupts(enabled);
        return -2;
    }
    card->result = -1;
    card->workArea = workArea;
    card->extCallback = detachCallback;
    card->apiCallback = attachCallback ? attachCallback : fn_80029824;
    card->exiCallback = 0;
    if (!card->attached && !EXIAttach(chan, __CARDExtHandler)) {
        card->result = -3;
        OSRestoreInterrupts(enabled);
        return -3;
    }
    card->mountStep = 0;
    card->attached = 1;
    EXISetExiCallback(chan, 0);
    OSCancelAlarm(&card->alarm);
    card->currentDir = 0;
    card->currentFat = 0;
    OSRestoreInterrupts(enabled);
    card->unlockCallback = __CARDMountCallback;
    if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
        return 0;
    }
    card->unlockCallback = 0;
    return DoMount(chan);
}
