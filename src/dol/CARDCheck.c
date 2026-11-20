#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"
#include <dolphin/exi.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSRtc.h>


/* --- dol/CARDCheck.c --- */
BOOL OSDisableInterrupts(void);

BOOL OSRestoreInterrupts(BOOL level);

u16 fn_8002A744();

extern CARDControl lbl_80177960[2];

OSSramEx *__OSLockSramEx();

s32 VerifyID(CARDControl *card);

s32 VerifyDir(CARDControl *card, int *outCurrent);

s32 VerifyFAT(CARDControl *card, int *outCurrent);

void __CARDCheckSum(void *ptr, int length, u16 *checksum, u16 *checksumInv) {
    u16 *p;
    int i;
    length /= sizeof(u16);
    *checksum = *checksumInv = 0;
    for (i = 0, p = ptr; i < length; i++, p++) {
        *checksum += *p;
        *checksumInv += ~*p;
    }
    if (*checksum == 0xffff) {
        *checksum = 0;
    }
    if (*checksumInv == 0xffff) {
        *checksumInv = 0;
    }
}

s32 VerifyID(CARDControl *card) {
    CARDID *id;
    u16 checksum;
    u16 checksumInv;
    OSSramEx *sramEx;
    OSTime rand;
    int i;
    id = card->workArea;
    if (id->deviceID != 0 || id->size != card->size) {
        return -6;
    }
    __CARDCheckSum(id, sizeof(CARDID) - sizeof(u32), &checksum, &checksumInv);
    if (id->checkSum != checksum || id->checkSumInv != checksumInv) {
        return -6;
    }
    rand = *(OSTime *)&id->serial[12];
    sramEx = __OSLockSramEx();
    for (i = 0; i < 12; i++) {
        rand = (rand * 1103515245 + 12345) >> 16;
        if (id->serial[i] != (u8)(sramEx->flashID[card - lbl_80177960][i] + rand)) {
            __OSUnlockSramEx(0);
            return -6;
        }
        rand = ((rand * 1103515245 + 12345) >> 16) & 0x7FFF;
    }
    __OSUnlockSramEx(0);
    if (id->encode != fn_8002A744()) {
        return -13;
    }
    return 0;
}

s32 VerifyDir(CARDControl *card, int *outCurrent) {
    CARDDir *dir[2];
    CARDDirCheck *check[2];
    u16 checkSum;
    u16 checkSumInv;
    int i;
    int errors;
    int current;
    current = errors = 0;
    for (i = 0; i < 2; i++) {
        dir[i] = (CARDDir *)((u8 *)card->workArea + (1 + i) * (8 * 1024));
        check[i] = ((CARDDirCheck *)&(dir[i])[127]);
        __CARDCheckSum(dir[i], (8 * 1024) - sizeof(u32), &checkSum, &checkSumInv);
        if (check[i]->checkSum != checkSum || check[i]->checkSumInv != checkSumInv) {
            ++errors;
            current = i;
            card->currentDir = 0;
        }
    }
    if (0 == errors) {
        if (card->currentDir == 0) {
            if ((check[0]->checkCode - check[1]->checkCode) < 0) {
                current = 0;
            } else {
                current = 1;
            }
            card->currentDir = dir[current];
            memcpy(dir[current], dir[current ^ 1], (8 * 1024));
        } else {
            current = (card->currentDir == dir[0]) ? 0 : 1;
        }
    }
    if (outCurrent) {
        *outCurrent = current;
    }
    return errors;
}

s32 VerifyFAT(CARDControl *card, int *outCurrent) {
    u16 *fat[2];
    u16 *fatp;
    u16 nBlock;
    u16 cFree;
    int i;
    u16 checkSum;
    u16 checkSumInv;
    int errors;
    int current;
    current = errors = 0;
    for (i = 0; i < 2; i++) {
        fatp = fat[i] = (u16 *)((u8 *)card->workArea + (3 + i) * (8 * 1024));
        __CARDCheckSum(&fatp[0x0002u], (8 * 1024) - sizeof(u32), &checkSum, &checkSumInv);
        if (fatp[0x0000u] != checkSum || fatp[0x0001u] != checkSumInv) {
            ++errors;
            current = i;
            card->currentFat = 0;
            continue;
        }
        cFree = 0;
        for (nBlock = 5; nBlock < card->cBlock; nBlock++) {
            if (fatp[nBlock] == 0x0000u) {
                cFree++;
            }
        }
        if (cFree != fatp[0x0003u]) {
            ++errors;
            current = i;
            card->currentFat = 0;
            continue;
        }
    }
    if (0 == errors) {
        if (card->currentFat == 0) {
            if (((s16)fat[0][0x0002u] - (s16)fat[1][0x0002u]) < 0) {
                current = 0;
            } else {
                current = 1;
            }
            card->currentFat = fat[current];
            memcpy(fat[current], fat[current ^ 1], (8 * 1024));
        } else {
            current = (card->currentFat == fat[0]) ? 0 : 1;
        }
    }
    if (outCurrent) {
        *outCurrent = current;
    }
    return errors;
}

s32 __CARDVerify(CARDControl *card) {
    s32 result;
    int errors;
    result = VerifyID(card);
    if (result < 0) {
        return result;
    }
    errors = VerifyDir(card, ((void *)0));
    errors += VerifyFAT(card, ((void *)0));
    switch (errors) {
    case 0:
        return 0;
    case 1:
        return -6;
    default:
        return -6;
    }
}

s32 CARDCheckExAsync(s32 chan, s32 *xferBytes, CARDCallback callback) {
    CARDControl *card;
    CARDDir *dir[2];
    u16 *fat[2];
    u16 *map;
    s32 result;
    int errors;
    int currentFat;
    int currentDir;
    s32 fileNo;
    u16 iBlock;
    u16 cBlock;
    u16 cFree;
    BOOL updateFat = 0;
    BOOL updateDir = 0;
    BOOL updateOrphan = 0;
    if (xferBytes) {
        *xferBytes = 0;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    result = VerifyID(card);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    errors = VerifyDir(card, &currentDir);
    errors += VerifyFAT(card, &currentFat);
    if (1 < errors) {
        return __CARDPutControlBlock(card, -6);
    }
    dir[0] = (CARDDir *)((u8 *)card->workArea + (1 + 0) * (8 * 1024));
    dir[1] = (CARDDir *)((u8 *)card->workArea + (1 + 1) * (8 * 1024));
    fat[0] = (u16 *)((u8 *)card->workArea + (3 + 0) * (8 * 1024));
    fat[1] = (u16 *)((u8 *)card->workArea + (3 + 1) * (8 * 1024));
    switch (errors) {
    case 0:
        break;
    case 1:
        if (!card->currentDir) {
            card->currentDir = dir[currentDir];
            memcpy(dir[currentDir], dir[currentDir ^ 1], (8 * 1024));
            updateDir = 1;
        } else {
            card->currentFat = fat[currentFat];
            memcpy(fat[currentFat], fat[currentFat ^ 1], (8 * 1024));
            updateFat = 1;
        }
        break;
    }
    map = fat[currentFat ^ 1];
    memset(map, 0, (8 * 1024));
    for (fileNo = 0; fileNo < 127; fileNo++) {
        CARDDir *ent;
        ent = &card->currentDir[fileNo];
        if (ent->gameName[0] == 0xff) {
            continue;
        }
        for (iBlock = ent->startBlock, cBlock = 0; iBlock != 0xFFFF && cBlock < ent->length;
             iBlock = card->currentFat[iBlock], ++cBlock) {
            if (!(5 <= (iBlock) && (iBlock) < (card)->cBlock) || 1 < ++map[iBlock]) {
                return __CARDPutControlBlock(card, -6);
            }
        }
        if (cBlock != ent->length || iBlock != 0xFFFF) {
            return __CARDPutControlBlock(card, -6);
        }
    }
    cFree = 0;
    for (iBlock = 5; iBlock < card->cBlock; iBlock++) {
        u16 nextBlock;
        nextBlock = card->currentFat[iBlock];
        if (map[iBlock] == 0) {
            if (nextBlock != 0x0000u) {
                card->currentFat[iBlock] = 0x0000u;
                updateOrphan = 1;
            }
            cFree++;
        } else if (!(5 <= (nextBlock) && (nextBlock) < (card)->cBlock) && nextBlock != 0xFFFF) {
            return __CARDPutControlBlock(card, -6);
        }
    }
    if (cFree != card->currentFat[0x0003u]) {
        card->currentFat[0x0003u] = cFree;
        updateOrphan = 1;
    }
    if (updateOrphan) {
        __CARDCheckSum(&card->currentFat[0x0002u], (8 * 1024) - sizeof(u32),
                       &card->currentFat[0x0000u], &card->currentFat[0x0001u]);
    }
    memcpy(fat[currentFat ^ 1], fat[currentFat], (8 * 1024));
    if (updateDir) {
        if (xferBytes) {
            *xferBytes = (8 * 1024);
        }
        return __CARDUpdateDir(chan, callback);
    }
    if (updateFat | updateOrphan) {
        if (xferBytes) {
            *xferBytes = (8 * 1024);
        }
        return __CARDUpdateFatBlock(chan, card->currentFat, callback);
    }
    __CARDPutControlBlock(card, 0);
    if (callback) {
        BOOL enabled = OSDisableInterrupts();
        callback(chan, 0);
        OSRestoreInterrupts(enabled);
    }
    return 0;
}

s32 CARDCheckAsync(s32 chan, CARDCallback callback) {
    s32 xferBytes;
    return CARDCheckExAsync(chan, &xferBytes, callback);
}

s32 CARDCheck(s32 channel) {
    s32 result;
    s32 xferBytes;
    result = CARDCheckExAsync(channel, &xferBytes, __CARDSyncCallback);
    if (result < 0 || &xferBytes == 0) {
        return result;
    }
    return __CARDSync(channel);
}

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
