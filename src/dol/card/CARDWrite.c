#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"

OSTime OSGetTime(void);
CARDDir *fn_8002C4BC(CARDControl *card);
u16 *fn_8002C0B8(CARDControl *card);
void DCStoreRange(void *addr, u32 nBytes);
void fn_80029824(s32 chan, s32 result);
extern u32 __OSBusClock : FZGX_ADDR___OSBusClock;
extern CARDControl lbl_80177960[2];

void EraseCallback_CARDWrite(s32 chan, s32 result);

void WriteCallback_CARDWrite(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    u16 *fat;
    CARDDir *dir;
    CARDDir *ent;
    CARDFileInfo *fileInfo;
    card = &lbl_80177960[chan];
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    fileInfo = card->fileInfo;
    if (fileInfo->length < 0) {
        result = -14;
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    fileInfo->length -= card->sectorSize;
    if (fileInfo->length <= 0) {
        dir = fn_8002C4BC(card);
        ent = &dir[fileInfo->fileNo];
        ent->time = (u32)((OSGetTime()) / ((u32)__OSBusClock / 4));
        callback = card->apiCallback;
        card->apiCallback = 0;
        result = __CARDUpdateDir(chan, callback);
    } else {
        fat = fn_8002C0B8(card);
        fileInfo->offset += card->sectorSize;
        fileInfo->iBlock = fat[fileInfo->iBlock];
        if (!(5 <= (fileInfo->iBlock) && (fileInfo->iBlock) < (card)->cBlock)) {
            result = -6;
            goto error; // fzgx-allow: S1 SDK error cleanup path
        }
        result = __CARDEraseSector(chan, card->sectorSize * (u32)fileInfo->iBlock,
                                   EraseCallback_CARDWrite);
    }
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    return;
error:
    callback = card->apiCallback;
    card->apiCallback = 0;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

void EraseCallback_CARDWrite(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    CARDFileInfo *fileInfo;

    card = &lbl_80177960[chan];
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    fileInfo = card->fileInfo;
    result = __CARDWrite(chan, card->sectorSize * (u32)fileInfo->iBlock, card->sectorSize, card->buffer,
                         WriteCallback_CARDWrite);
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    return;
error:
    callback = card->apiCallback;
    card->apiCallback = 0;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

s32 CARDWriteAsync(CARDFileInfo *fileInfo, const void *buf, s32 length, s32 offset,
                   CARDCallback callback) {
    CARDControl *card;
    s32 result;
    CARDDir *dir;
    CARDDir *ent;
    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0) {
        return result;
    }
    if ((((u32)(offset)) & ((card->sectorSize) - 1)) != 0 ||
        (((u32)(length)) & ((card->sectorSize) - 1)) != 0) {
        return __CARDPutControlBlock(card, -128);
    }
    dir = fn_8002C4BC(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    DCStoreRange((void *)buf, (u32)length);
    card->apiCallback = callback ? callback : fn_80029824;
    card->buffer = (void *)buf;
    result = __CARDEraseSector(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock,
                               EraseCallback_CARDWrite);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}
