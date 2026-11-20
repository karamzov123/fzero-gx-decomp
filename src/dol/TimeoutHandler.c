#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"


/* --- dol/TimeoutHandler.c --- */
void TimeoutHandler(OSAlarm *alarm, OSContext *context);

extern CARDControl lbl_80177960[2];

void TimeoutHandler(OSAlarm *alarm, OSContext *context) {
    s32 chan;
    CARDControl *card;
    CARDCallback callback;
    for (chan = 0; chan < 2; ++chan) {
        card = &lbl_80177960[chan];
        if (alarm == &card->alarm) {
            break;
        }
    }
    if (!card->attached) {
        return;
    }
    EXISetExiCallback(chan, ((void *)0));
    callback = card->exiCallback;
    if (callback) {
        card->exiCallback = 0;
        callback(chan, -5);
    }
}

/* --- dol/Retry.c --- */
void OSCancelAlarm(OSAlarm *alarm);

s32 Retry(s32 chan);

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void TimeoutHandler(OSAlarm *alarm, OSContext *context);


u32 __OSBusClock : FZGX_ADDR___OSBusClock;


static inline void SetupTimeoutAlarm(CARDControl *card) {
    OSCancelAlarm(&card->alarm);
    switch (card->cmd[0]) {
    case 0xF2:
        OSSetAlarm(&card->alarm, ((100) * (((u32)__OSBusClock / 4) / 1000)), TimeoutHandler);
        break;
    case 0xF3:
        break;
    case 0xF4:
    case 0xF1:
        OSSetAlarm(&card->alarm,
                   (((OSTime)2) * ((u32)__OSBusClock / 4)) * (card->sectorSize / 0x2000),
                   TimeoutHandler);
        break;
    }
}

s32 Retry(s32 chan) {
    CARDControl *card;
    card = &lbl_80177960[chan];
    if (!EXISelect(chan, 0, 4)) {
        EXIUnlock(chan);
        return -3;
    }
    SetupTimeoutAlarm(card);
    if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return -3;
    }
    if (card->cmd[0] == 0x52 &&
        !EXIImmEx(chan, (u8 *)card->workArea + sizeof(CARDID), card->latency, 1)) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return -3;
    }
    if (card->mode == 0xffffffff) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return 0;
    }
    if (!EXIDma(chan, card->buffer, (s32)((card->cmd[0] == 0x52) ? 512 : 128), card->mode,
                __CARDTxHandler)) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return -3;
    }
    return 0;
}

/* --- dol/UnlockedCallback.c --- */
s32 Retry(s32 chan);

void UnlockedCallback(s32 chan, s32 result);


void UnlockedCallback(s32 chan, s32 result) {
    CARDCallback callback;
    CARDControl *card;
    card = &lbl_80177960[chan];
    if (result >= 0) {
        card->unlockCallback = UnlockedCallback;
        if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
            result = 0;
        } else {
            card->unlockCallback = 0;
            result = Retry(chan);
        }
    }
    if (result < 0) {
        switch (card->cmd[0]) {
        case 0x52:
            callback = card->txCallback;
            if (callback) {
                card->txCallback = 0;
                callback(chan, result);
            }
            break;
        case 0xF2:
        case 0xF4:
        case 0xF1:
            callback = card->exiCallback;
            if (callback) {
                card->exiCallback = 0;
                callback(chan, result);
            }
            break;
        }
    }
}

/* --- dol/__CARDStart.c --- */
void OSCancelAlarm(OSAlarm *alarm);

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void TimeoutHandler(OSAlarm *alarm, OSContext *context);

BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);
void UnlockedCallback(s32 chan, s32 result);





s32 __CARDStart(s32 chan, CARDCallback txCallback, CARDCallback exiCallback) {
    BOOL enabled;
    CARDControl *card;
    s32 result;
    enabled = OSDisableInterrupts();
    card = &lbl_80177960[chan];
    if (!card->attached) {
        result = -3;
    } else {
        if (txCallback) {
            card->txCallback = txCallback;
        }
        if (exiCallback) {
            card->exiCallback = exiCallback;
        }
        card->unlockCallback = UnlockedCallback;
        if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
            result = -1;
        } else {
            card->unlockCallback = 0;
            if (!EXISelect(chan, 0, 4)) {
                EXIUnlock(chan);
                result = -3;
            } else {
                SetupTimeoutAlarm(card);
                result = 0;
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return result;
}

/* --- dol/__CARDReadSegment.c --- */
s32 __CARDReadSegment(s32 chan, CARDCallback callback) {
    CARDControl *card;
    s32 result;
    card = &lbl_80177960[chan];
    card->cmd[0] = 0x52;
    card->cmd[1] = ((u8)(((card->addr) >> 17) & 0x7f));
    card->cmd[2] = ((u8)(((card->addr) >> 9) & 0xff));
    card->cmd[3] = ((u8)(((card->addr) >> 7) & 0x03));
    card->cmd[4] = ((u8)((card->addr) & 0x7f));
    card->cmdlen = 5;
    card->mode = 0;
    card->retry = 0;
    result = __CARDStart(chan, callback, 0);
    if (result == -1) {
        result = 0;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1) ||
            !EXIImmEx(chan, (u8 *)card->workArea + sizeof(CARDID), card->latency, 1) ||
            !EXIDma(chan, card->buffer, 512, card->mode, __CARDTxHandler)) {
            card->txCallback = 0;
            EXIDeselect(chan);
            EXIUnlock(chan);
            result = -3;
        } else {
            result = 0;
        }
    }
    return result;
}

/* --- dol/__CARDWritePage.c --- */
s32 __CARDWritePage(s32 chan, CARDCallback callback) {
    CARDControl *card;
    s32 result;
    card = &lbl_80177960[chan];
    card->cmd[0] = 0xF2;
    card->cmd[1] = ((u8)(((card->addr) >> 17) & 0x7f));
    card->cmd[2] = ((u8)(((card->addr) >> 9) & 0xff));
    card->cmd[3] = ((u8)(((card->addr) >> 7) & 0x03));
    card->cmd[4] = ((u8)((card->addr) & 0x7f));
    card->cmdlen = 5;
    card->mode = 1;
    card->retry = 3;
    result = __CARDStart(chan, 0, callback);
    if (result == -1) {
        result = 0;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1) ||
            !EXIDma(chan, card->buffer, 128, card->mode, __CARDTxHandler)) {
            card->exiCallback = 0;
            EXIDeselect(chan);
            EXIUnlock(chan);
            result = -3;
        } else {
            result = 0;
        }
    }
    return result;
}

/* --- dol/__CARDEraseSector.c --- */
s32 __CARDEraseSector(s32 chan, u32 addr, CARDCallback callback) {
    CARDControl *card;
    s32 result;
    card = &lbl_80177960[chan];
    card->cmd[0] = 0xF1;
    card->cmd[1] = ((u8)(((addr) >> 17) & 0x7f));
    card->cmd[2] = ((u8)(((addr) >> 9) & 0xff));
    card->cmdlen = 3;
    card->mode = -1;
    card->retry = 3;
    result = __CARDStart(chan, 0, callback);
    if (result == -1) {
        result = 0;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)) {
            card->exiCallback = ((void *)0);
            result = -3;
        } else {
            result = 0;
        }
        EXIDeselect(chan);
        EXIUnlock(chan);
    }
    return result;
}
