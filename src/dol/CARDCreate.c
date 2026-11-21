#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"


/* --- dol/CARDCreate.c --- */
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

OSTime OSGetTime(void);

void fn_80029824(s32 chan, s32 result);

CARDDir *fn_8002C4BC(CARDControl *card);

u16 *fn_8002C0B8(CARDControl *card);

extern CARDControl lbl_80177960[2];

void CreateCallbackFat(s32 chan, s32 result);

void CreateCallbackFat(s32 chan, s32 result) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    CARDCallback callback;
    card = &lbl_80177960[chan];
    callback = card->apiCallback;
    card->apiCallback = 0;
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    dir = fn_8002C4BC(card);
    ent = &dir[card->freeNo];
    memcpy(ent->gameName, card->diskID->gameName, sizeof(ent->gameName));
    memcpy(ent->company, card->diskID->company, sizeof(ent->company));
    ent->permission = 0x04u;
    ent->copyTimes = 0;
    ent->startBlock = card->startBlock;
    ent->bannerFormat = 0;
    ent->iconAddr = 0xffffffff;
    ent->iconFormat = 0;
    ent->iconSpeed = 0;
    ent->commentAddr = 0xffffffff;
    ((ent)->iconSpeed = (u16)(((ent)->iconSpeed & ~(3 << (2 * (0)))) | ((1) << (2 * (0)))));
    card->fileInfo->offset = 0;
    card->fileInfo->iBlock = ent->startBlock;
    ent->time = (u32)((OSGetTime()) / ((u32)__OSBusClock / 4));
    result = __CARDUpdateDir(chan, callback);
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    return;
error:
    __CARDPutControlBlock(card, result);
    if (callback) {
        callback(chan, result);
    }
}

s32 CARDCreateAsync(s32 chan, const char *fileName, u32 size, CARDFileInfo *fileInfo,
                    CARDCallback callback) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    s32 result;
    u16 fileNo;
    u16 freeNo;
    u16 *fat;
    if (strlen(fileName) > (u32)32) {
        return -12;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    if (size <= 0 || (size % card->sectorSize) != 0) {
        return -128;
    }
    freeNo = (u16)-1;
    dir = fn_8002C4BC(card);
    for (fileNo = 0; fileNo < 127; fileNo++) {
        ent = &dir[fileNo];
        if (ent->gameName[0] == 0xff) {
            if (freeNo == (u16)-1) {
                freeNo = fileNo;
            }
        } else if (fn_8008023C(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) == 0 &&
                   fn_8008023C(ent->company, card->diskID->company, sizeof(ent->company)) == 0 &&
                   __CARDCompareFileName(ent, fileName)) {
            return __CARDPutControlBlock(card, -7);
        }
    }
    if (freeNo == (u16)-1) {
        return __CARDPutControlBlock(card, -8);
    }
    fat = fn_8002C0B8(card);
    if (card->sectorSize * fat[0x0003u] < size) {
        return __CARDPutControlBlock(card, -9);
    }
    card->apiCallback = callback ? callback : fn_80029824;
    card->freeNo = freeNo;
    ent = &dir[freeNo];
    ent->length = (u16)(size / card->sectorSize);
    strncpy(ent->fileName, fileName, 32);
    card->fileInfo = fileInfo;
    fileInfo->chan = chan;
    fileInfo->fileNo = freeNo;
    result = __CARDAllocBlock(chan, size / card->sectorSize, CreateCallbackFat);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 CARDCreate(s32 channel, const char *fileName, u32 size, CARDFileInfo *fileInfo) {
    s32 result = CARDCreateAsync(channel, fileName, size, fileInfo, __CARDSyncCallback);
    if (result < 0) {
        return result;
    }
    return __CARDSync(channel);
}
