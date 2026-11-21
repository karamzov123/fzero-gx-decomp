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

void CreateCallbackFat(s32 chan, s32 result);

s32 CARDCreateAsync(s32 chan, const char *fileName, u32 size, CARDFileInfo *fileInfo,
                    CARDCallback callback);

s32 CARDCreate(s32 channel, const char *fileName, u32 size, CARDFileInfo *fileInfo);

/* --- dol/__CARDSeek.c --- */
CARDDir *fn_8002C4BC(CARDControl *card);
u16 *fn_8002C0B8(CARDControl *card);

s32 __CARDSeek(CARDFileInfo *fileInfo, s32 length, s32 offset, CARDControl **pcard) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    s32 result;
    u16 *fat;
    result = __CARDGetControlBlock(fileInfo->chan, &card);
    if (result < 0) {
        return result;
    }
    if (!(5 <= (fileInfo->iBlock) && (fileInfo->iBlock) < (card)->cBlock) ||
        card->cBlock * card->sectorSize <= fileInfo->offset) {
        return __CARDPutControlBlock(card, -128);
    }
    dir = fn_8002C4BC(card);
    ent = &dir[fileInfo->fileNo];
    if (ent->length * card->sectorSize <= offset ||
        ent->length * card->sectorSize < offset + length) {
        return __CARDPutControlBlock(card, -11);
    }
    card->fileInfo = fileInfo;
    fileInfo->length = length;
    if (offset < fileInfo->offset) {
        fileInfo->offset = 0;
        fileInfo->iBlock = ent->startBlock;
        if (!(5 <= (fileInfo->iBlock) && (fileInfo->iBlock) < (card)->cBlock)) {
            return __CARDPutControlBlock(card, -6);
        }
    }
    fat = fn_8002C0B8(card);
    while (fileInfo->offset < (((u32)(offset)) & ~((card->sectorSize) - 1))) {
        fileInfo->offset += card->sectorSize;
        fileInfo->iBlock = fat[fileInfo->iBlock];
        if (!(5 <= (fileInfo->iBlock) && (fileInfo->iBlock) < (card)->cBlock)) {
            return __CARDPutControlBlock(card, -6);
        }
    }
    fileInfo->offset = offset;
    *pcard = card;
    return 0;
}

/* --- dol/ReadCallback.c --- */
u16 *fn_8002C0B8(CARDControl *card);


void ReadCallback(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    u16 *fat;
    CARDFileInfo *fileInfo;
    s32 length;
    card = &lbl_80177960[chan];
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    fileInfo = card->fileInfo;
    if (fileInfo->length < 0) {
        result = -14;
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    length = (s32)(((u32)(fileInfo->offset + card->sectorSize)) & ~((card->sectorSize) - 1)) -
             fileInfo->offset;
    fileInfo->length -= length;
    if (fileInfo->length <= 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    fat = fn_8002C0B8(card);
    fileInfo->offset += length;
    fileInfo->iBlock = fat[fileInfo->iBlock];
    if (!(5 <= (fileInfo->iBlock) && (fileInfo->iBlock) < (card)->cBlock)) {
        result = -6;
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    result = __CARDRead(chan, card->sectorSize * (u32)fileInfo->iBlock,
                        (fileInfo->length < card->sectorSize) ? fileInfo->length : card->sectorSize,
                        card->buffer, ReadCallback);
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

/* --- dol/CARDReadAsync.c --- */
extern CARDDir *fn_8002C4BC(CARDControl *card);

void DCInvalidateRange(void *start, u32 nBytes);
extern void fn_80029824(s32 chan, s32 result);
void ReadCallback(s32 chan, s32 result);

s32 CARDReadAsync(CARDFileInfo *fileInfo, void *buf, s32 length, s32 offset,
                  CARDCallback callback) {
    CARDControl *card;
    s32 result;
    CARDDir *dir;
    CARDDir *ent;
    (void)0;
    (void)0;
    (void)0;
    if ((((u32)(offset) & ((0x200u) - 1))) != 0 || (((u32)(length) & ((0x200u) - 1))) != 0)
        return -128;
    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0)
        return result;
    dir = fn_8002C4BC(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDAccess(card, ent);
    if (result == -10) {
        result = __CARDIsPublic(ent);
    }
    if (result < 0)
        return __CARDPutControlBlock(card, result);
    DCInvalidateRange(buf, (u32)length);
    card->apiCallback = callback ? callback : fn_80029824;
    offset = (s32)(((u32)(fileInfo->offset) & ((card->sectorSize) - 1)));
    length = (length < card->sectorSize - offset) ? length : card->sectorSize - offset;
    result = __CARDRead(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock + offset, length,
                        buf, ReadCallback);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}
