#include <dolphin/card/CARDPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/os/OSTime.h>
#include "sdk_addresses.h"

extern CARDControl lbl_80177960[2];
extern u16 lbl_801A6BC0;
extern u32 lbl_801A650C;

void OSCancelAlarm(OSAlarm *alarm);
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);
void __CARDTxHandler(s32 chan, OSContext *context);
void __CARDExtHandler(s32 chan, OSContext *context);
void __CARDUnlockedHandler(s32 chan, OSContext *context);
s32 __CARDReadStatus(s32 chan, u8 *status);
s32 __CARDClearStatus(s32 chan);
s32 __CARDStart(s32 chan, CARDCallback txCallback, CARDCallback exiCallback);
s32 Retry(s32 chan);
s32 CARDUnmount(s32 chan);
u16 *fn_8002C0B8(CARDControl *card);
CARDDir *fn_8002C4BC(CARDControl *card);
u16 fn_8002A744(void);
void __CARDSetDiskID(const DVDDiskID *id);

void __CARDSyncCallback(s32 chan, s32 result) {
    OSWakeupThread(&lbl_80177960[chan].threadQueue);
}

void __CARDExtHandler(s32 chan, OSContext *context) {
    CARDControl *card;
    CARDCallback callback;

    card = &lbl_80177960[chan];
    if (card->attached) {
        card->attached = FALSE;
        EXISetExiCallback(chan, 0);
        OSCancelAlarm(&card->alarm);
        callback = card->exiCallback;
        if (callback) {
            card->exiCallback = 0;
            callback(chan, -3);
        }
        if (card->result != -1) {
            card->result = -3;
        }
        callback = card->extCallback;
        if (callback && card->mountStep >= 7) {
            card->extCallback = 0;
            callback(chan, -3);
        }
    }
}

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


void __CARDUnlockedHandler(s32 chan, OSContext *context) {
    CARDControl *card;
    CARDCallback callback;

    card = &lbl_80177960[chan];
    callback = card->unlockCallback;
    if (callback) {
        card->unlockCallback = 0;
        callback(chan, EXIProbe(chan) ? 1 : -3);
    }
}

s32 __CARDEnableInterrupt(s32 chan, BOOL enable) {
    BOOL err;
    u32 cmd;

    if (!EXISelect(chan, 0, 4)) {
        return -3;
    }
    cmd = enable ? 0x81010000 : 0x81000000; /* fzgx-allow: A1 unnamed OS/hardware memory */
    err = FALSE;
    err |= !EXIImm(chan, &cmd, 2, 1, 0);
    err |= !EXISync(chan);
    err |= !EXIDeselect(chan);
    return err ? -3 : 0;
}

s32 __CARDReadStatus(s32 chan, u8 *status) {
    BOOL err;
    u32 cmd;

    if (!EXISelect(chan, 0, 4)) {
        return -3;
    }
    cmd = 0x83000000;
    err = FALSE;
    err |= !EXIImm(chan, &cmd, 2, 1, 0);
    err |= !EXISync(chan);
    err |= !EXIImm(chan, status, 1, 0, 0);
    err |= !EXISync(chan);
    err |= !EXIDeselect(chan);
    return err ? -3 : 0;
}

s32 __CARDClearStatus(s32 chan) {
    u32 command;
    s32 failed;

    if (!EXISelect(chan, 0, 4)) {
        return -3;
    }

    command = 0x89000000;
    failed = !EXIImm(chan, &command, 1, 1, 0);
    failed |= !EXISync(chan);
    failed |= !EXIDeselect(chan);

    if (failed) {
        return -3;
    }
    return 0;
}

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

extern const char *lbl_801A6508;
extern OSResetFunctionInfo lbl_8012AA50;
extern u16 OSGetFontEncode(void);
extern void OSRegisterVersion(const char *);
extern void DSPInit(void);
extern void OSInitAlarm(void);
extern void OSInitThreadQueue(OSThreadQueue *);
extern void OSCreateAlarm(OSAlarm *);
extern void OSRegisterResetFunction(OSResetFunctionInfo *);

#pragma opt_dead_assignments off
void CARDInit(void) {
    CARDControl *card = lbl_80177960;
    s32 i;

    card = lbl_80177960;
    if (card[0].diskID == 0 || card[1].diskID == 0) {
        lbl_801A6BC0 = OSGetFontEncode();
        OSRegisterVersion(lbl_801A6508);
        DSPInit();
        OSInitAlarm();
        i = 0;
        do {
            card->result = -3;
            OSInitThreadQueue(&card->threadQueue);
            OSCreateAlarm(&card->alarm);
            i++;
            card++;
        } while (i < 2);
        __CARDSetDiskID((const DVDDiskID *)0x80000000); /* fzgx-allow: A1,A2 OS lowmem disk ID */
        OSRegisterResetFunction(&lbl_8012AA50);
    }
}
#pragma opt_dead_assignments reset

u16 fn_8002A744(void) {
    return lbl_801A6BC0;
}

u16 fn_8002A74C(u16 encode) {
    u16 prev = lbl_801A6BC0;
    switch (encode) {
    case 0:
    case 1:
        lbl_801A6BC0 = encode;
        break;
    }
    return prev;
}

void __CARDSetDiskID(const DVDDiskID *id) {
    CARDControl *storage = lbl_80177960;
    storage[0].diskID = id ? id : (const DVDDiskID *)&storage[2];
    storage[1].diskID = id ? id : (const DVDDiskID *)&storage[2];
}

const DVDDiskID *fn_8002A7AC(s32 chan) {
    return lbl_80177960[chan].diskID;
}

s32 fn_8002A7C4(s32 chan, const DVDDiskID *diskID) {
    CARDControl *card;
    BOOL enabled;

    card = &lbl_80177960[chan];
    enabled = OSDisableInterrupts();
    if (card->result == -1) {
        return -1;
    }
    card->diskID = diskID ? diskID : (const DVDDiskID *)0x80000000; /* fzgx-allow: A1,A2 OS lowmem disk ID */
    OSRestoreInterrupts(enabled);
    return 0;
}

s32 __CARDGetControlBlock(s32 chan, CARDControl **pcard) {
    BOOL enabled;
    s32 result;
    CARDControl *card;
    card = &lbl_80177960[chan];
    if (chan < 0 || chan >= 2 || card->diskID == ((void *)0)) {
        return -128;
    }
    enabled = OSDisableInterrupts();
    if (!card->attached) {
        result = -3;
    } else if (card->result == -1) {
        result = -1;
    } else {
        card->result = -1;
        result = 0;
        card->apiCallback = 0;
        *pcard = card;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

s32 __CARDPutControlBlock(CARDControl *card, s32 result) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (card->attached) {
        card->result = result;
    } else if (card->result == -1) {
        card->result = result;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

s32 CARDGetResultCode(s32 chan) {
    CARDControl *card;

    if (chan < 0 || chan >= 2) {
        return -128;
    }
    card = &lbl_80177960[chan];
    return card->result;
}

s32 CARDFreeBlocks(s32 chan, s32 *byteNotUsed, s32 *filesNotUsed) {
    CARDControl *card;
    s32 result;
    u16 *fat;
    CARDDir *dir;
    CARDDir *ent;
    u16 fileNo;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    fat = fn_8002C0B8(card);
    dir = fn_8002C4BC(card);
    if (fat == 0 || dir == 0) {
        return __CARDPutControlBlock(card, -6);
    }
    if (byteNotUsed) {
        *byteNotUsed = (s32)(card->sectorSize * fat[0x0003u]);
    }
    if (filesNotUsed) {
        *filesNotUsed = 0;
        for (fileNo = 0; fileNo < 127; fileNo++) {
            ent = &dir[fileNo];
            if (ent->fileName[0] == 0xff) {
                ++*filesNotUsed;
            }
        }
    }
    return __CARDPutControlBlock(card, 0);
}

void OSSleepThread(OSThreadQueue *queue);

s32 __CARDSync(s32 channel) {
    CARDControl *card;
    s32 result;
    BOOL enabled;
    card = &lbl_80177960[channel];
    enabled = OSDisableInterrupts();
    while ((result = CARDGetResultCode(channel)) == -1) {
        OSSleepThread(&card->threadQueue);
    }
    OSRestoreInterrupts(enabled);
    return result;
}

s32 OnReset_CARDBios(u32 arg0) {
    u32 v0;
    if ((s32)arg0 == 0 && ((s32)CARDUnmount(0) == -1 || (s32)CARDUnmount(1) == -1)) {
    v0 = 0;
    } else {
    v0 = 1;
    }
    return v0;
}

extern u16 lbl_801A6BC0;
