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
