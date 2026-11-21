#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"
#include <dolphin/exi.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSRtc.h>


/* --- dol/IsCard.c --- */
/* --- dol/CARDCheck.c --- */
BOOL OSDisableInterrupts(void);

BOOL OSRestoreInterrupts(BOOL level);

u16 fn_8002A744();

extern CARDControl lbl_80177960[2];

OSSramEx *__OSLockSramEx();

s32 VerifyID(CARDControl *card);

s32 VerifyDir(CARDControl *card, int *outCurrent);

s32 VerifyFAT(CARDControl *card, int *outCurrent);

void __CARDCheckSum(void *ptr, int length, u16 *checksum, u16 *checksumInv);

s32 VerifyID(CARDControl *card);

s32 VerifyDir(CARDControl *card, int *outCurrent);

s32 VerifyFAT(CARDControl *card, int *outCurrent);

s32 __CARDVerify(CARDControl *card);

s32 CARDCheckExAsync(s32 chan, s32 *xferBytes, CARDCallback callback);

s32 CARDCheckAsync(s32 chan, CARDCallback callback);

s32 CARDCheck(s32 channel);

/* --- dol/IsCard.c --- */
extern u16 lbl_801A6518;

extern u32 lbl_8012ABC0[8];

BOOL IsCard(u32 id) {
    u32 size;
    s32 sectorSize;
    if (id & (0xFFFF0000) && (id != 0x80000004 || lbl_801A6518 == 0xFFFF)) { // fzgx-allow: A1 CARD device identifier, not a pointer
        return 0;
    }
    if ((id & 3) != 0) {
        return 0;
    }
    size = id & 0xfc;
    switch (size) {
    case 4:
    case 8:
    case 16:
    case 32:
    case 64:
    case 128:
        break;
    default:
        return 0;
        break;
    }
    sectorSize = lbl_8012ABC0[(id & 0x00003800) >> 11];
    if (sectorSize == 0) {
        return 0;
    }
    if ((size * 1024 * 1024 / 8) / sectorSize < 8) {
        return 0;
    }
    return 1;
}

/* --- dol/CARDProbeEx.c --- */
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);
s32 EXIProbeEx(s32 chan);
s32 EXIGetID(s32 chan, u32 dev, u32 *id);
BOOL IsCard(u32 id);



u8 GameChoice : FZGX_ADDR_GameChoice;


s32 CARDProbeEx(s32 chan, s32 *memSize, s32 *sectorSize) {
    u32 id;
    CARDControl *card;
    BOOL enabled;
    s32 result;
    int probe;
    if (chan < 0 || 2 <= chan) {
        return -128;
    }
    if (GameChoice & 0x80) {
        return -3;
    }
    card = &lbl_80177960[chan];
    enabled = OSDisableInterrupts();
    probe = EXIProbeEx(chan);
    if (probe == -1) {
        result = -3;
    } else if (probe == 0) {
        result = -1;
    } else if (card->attached) {
        if (card->mountStep < 1) {
            result = -1;
        } else {
            if (memSize) {
                *memSize = card->size;
            }
            if (sectorSize) {
                *sectorSize = card->sectorSize;
            }
            result = 0;
        }
    } else if ((EXIGetState(chan) & 8)) {
        result = -2;
    } else if (!EXIGetID(chan, 0, &id)) {
        result = -1;
    } else if (IsCard(id)) {
        if (memSize) {
            *memSize = (s32)(id & 0xfc);
        }
        if (sectorSize) {
            *sectorSize = lbl_8012ABC0[(id & 0x00003800) >> 11];
        }
        result = 0;
    } else {
        result = -2;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

/* --- dol/DoMount.c --- */
s32 EXIGetID(s32 chan, u32 dev, u32 *id);



OSSramEx *__OSLockSramEx();


extern u32 lbl_8012ABE0[8];

void DoUnmount(s32 chan, s32 result);

BOOL IsCard(u32 id);

void DoUnmount(s32 chan, s32 result);

s32 DoMount(s32 chan) {
    CARDControl *card;
    u32 id;
    u8 status;
    s32 result;
    OSSramEx *sram;
    int i;
    u8 checkSum;
    int step;
    card = &lbl_80177960[chan];
    if (card->mountStep == 0) {
        if (EXIGetID(chan, 0, &id) == 0) {
            result = -3;
        } else if (IsCard(id)) {
            result = 0;
        } else {
            result = -2;
        }
        if (result < 0) {
            goto error; // fzgx-allow: S1 SDK error cleanup path
        }
        card->cid = id;
        card->size = (u16)(id & 0xFC);
        card->sectorSize = lbl_8012ABC0[(id & 0x00003800) >> 11];
        card->cBlock = (u16)((card->size * 1024 * 1024 / 8) / card->sectorSize);
        card->latency = lbl_8012ABE0[(id & 0x00000700) >> 8];
        result = __CARDClearStatus(chan);
        if (result < 0) {
            goto error; // fzgx-allow: S1 SDK error cleanup path
        }
        result = __CARDReadStatus(chan, &status);
        if (result < 0) {
            goto error; // fzgx-allow: S1 SDK error cleanup path
        }
        if (!EXIProbe(chan)) {
            result = -3;
            goto error; // fzgx-allow: S1 SDK error cleanup path
        }
        if (!(status & 0x40)) {
            result = __CARDUnlock(chan, card->id);
            if (result < 0) {
                goto error; // fzgx-allow: S1 SDK error cleanup path
            }
            checkSum = 0;
            sram = __OSLockSramEx();
            for (i = 0; i < 12; i++) {
                sram->flashID[chan][i] = card->id[i];
                checkSum += card->id[i];
            }
            sram->flashIDCheckSum[chan] = (u8)~checkSum;
            __OSUnlockSramEx(1);
            return result;
        } else {
            card->mountStep = 1;
            checkSum = 0;
            sram = __OSLockSramEx();
            for (i = 0; i < 12; i++) {
                checkSum += sram->flashID[chan][i];
            }
            __OSUnlockSramEx(0);
            if (sram->flashIDCheckSum[chan] != (u8)~checkSum) {
                result = -5;
                goto error; // fzgx-allow: S1 SDK error cleanup path
            }
        }
    }
    if (card->mountStep == 1) {
        if (card->cid == 0x80000004) { // fzgx-allow: A1 CARD device identifier, not a pointer
            u16 vendorID;
            sram = __OSLockSramEx();
            vendorID = *(u16 *)sram->flashID[chan];
            __OSUnlockSramEx(0);
            if (lbl_801A6518 == 0xffff || vendorID != lbl_801A6518) {
                result = -2;
                goto error; // fzgx-allow: S1 SDK error cleanup path
            }
        }
        card->mountStep = 2;
        result = __CARDEnableInterrupt(chan, 1);
        if (result < 0) {
            goto error; // fzgx-allow: S1 SDK error cleanup path
        }
        EXISetExiCallback(chan, __CARDExiHandler);
        EXIUnlock(chan);
        DCInvalidateRange(card->workArea, (5 * 8 * 1024));
    }
    step = card->mountStep - 2;
    result = __CARDRead(chan, (u32)card->sectorSize * step, (8 * 1024),
                        (u8 *)card->workArea + ((8 * 1024) * step), __CARDMountCallback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
error:
    EXIUnlock(chan);
    DoUnmount(chan, result);
    return result;
}

/* --- dol/__CARDMountCallback.c --- */
/* --- dol/__CARDMountCallback.c --- */
void DoUnmount(s32 chan, s32 result);
s32 DoMount(s32 chan);


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

extern s32 __CARDSync(s32 chan);
extern void __CARDSyncCallback(s32 chan, s32 result);

s32 fn_8002DFE0(s32 chan, void *workArea, CARDCallback detachCallback) {
    s32 status = CARDMountAsync(chan, workArea, detachCallback, __CARDSyncCallback);
    if (status < 0) {
        return status;
    }
    return __CARDSync(chan);
}

void DoUnmount(s32 chan, s32 result) {
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
