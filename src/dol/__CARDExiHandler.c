#include <dolphin/card/CARDPriv.h>


/* --- dol/__CARDExiHandler.c --- */
void OSCancelAlarm(OSAlarm *alarm);

s32 Retry(s32 chan);

extern CARDControl lbl_80177960[2];

void __CARDExiHandler(s32 chan, OSContext *context) {
    CARDControl *card;
    CARDCallback callback;
    u8 status;
    s32 result;
    card = &lbl_80177960[chan];
    OSCancelAlarm(&card->alarm);
    if (!card->attached) {
        return;
    }
    if (!EXILock(chan, 0, 0)) {
        result = -128;
        goto fatal; // fzgx-allow: S1 SDK error cleanup path
    }
    if ((result = __CARDReadStatus(chan, &status)) < 0 || (result = __CARDClearStatus(chan)) < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    if ((result = (status & 0x18) ? -5 : 0) == -5 && --card->retry > 0) {
        result = Retry(chan);
        if (result >= 0) {
            return;
        }
        goto fatal; // fzgx-allow: S1 SDK error cleanup path
    }
error:
    EXIUnlock(chan);
fatal:
    callback = card->exiCallback;
    if (callback) {
        card->exiCallback = 0;
        callback(chan, result);
    }
}

/* --- dol/__CARDTxHandler.c --- */
BOOL EXIProbe(s32 chan);


void __CARDTxHandler(s32 chan, OSContext *context) {
    CARDControl *card;
    CARDCallback callback;
    BOOL err;
    card = &lbl_80177960[chan];
    err = !EXIDeselect(chan);
    EXIUnlock(chan);
    callback = card->txCallback;
    if (callback) {
        card->txCallback = 0;
        callback(chan, (!err && EXIProbe(chan)) ? 0 : -3);
    }
}
