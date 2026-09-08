// dolphin/card/CARDRead.c -- retail 0x8002F140-0x8002F5B8.
// Adapted from pinned public SDK/Prime references; see docs/contributions/card-read/CARD.md.
#include <dolphin/card_private.h>

extern s32 __CARDRead(s32 chan, u32 address, s32 length, void* buffer,
                      CARDCallback callback);
extern s32 __CARDIsPublic(CARDDir* ent);
extern void DCInvalidateRange(void* addr, unsigned int n);

#define CARD_RESULT_LIMIT (-11)
#define CARD_RESULT_CANCELED (-14)
#define CARD_SEG_SIZE 512
#define CARDIsValidBlockNo(card, block) (5 <= (block) && (block) < (card)->cBlock)
#define TRUNC(n, a) ((u32)(n) & ~((a) - 1))
#define OFFSET(n, a) ((u32)(n) & ((a) - 1))

#pragma push
#pragma force_active on

// provenance: prime:extern/sdk/dolphin/card/CARDRead.c:8
// Signed retail comparisons are explicit; the shared ABI fields stay unsigned.
s32 __CARDSeek(CARDFileInfo* fileInfo, s32 length, s32 offset, CARDControl** pcard) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    u16* fat;

    result = __CARDGetControlBlock(fileInfo->chan, &card);
    if (result < 0) {
        return result;
    }
    if (!CARDIsValidBlockNo(card, fileInfo->iBlock) ||
        (s32)(card->cBlock * card->sectorSize) <= (s32)fileInfo->offset) {
        return __CARDPutControlBlock(card, CARD_RESULT_FATAL_ERROR);
    }
    dir = __CARDGetDirBlock(card);
    ent = &dir[fileInfo->fileNo];
    if ((s32)(ent->length * card->sectorSize) <= offset ||
        (s32)(ent->length * card->sectorSize) < offset + length) {
        return __CARDPutControlBlock(card, CARD_RESULT_LIMIT);
    }
    card->fileInfo = fileInfo;
    fileInfo->length = length;
    if (offset < (s32)fileInfo->offset) {
        fileInfo->offset = 0;
        fileInfo->iBlock = ent->startBlock;
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock)) {
            return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
        }
    }
    fat = __CARDGetFatBlock(card);
    while (fileInfo->offset < TRUNC(offset, card->sectorSize)) {
        fileInfo->offset += card->sectorSize;
        fileInfo->iBlock = fat[fileInfo->iBlock];
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock)) {
            return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
        }
    }
    fileInfo->offset = offset;
    *pcard = card;
    return CARD_RESULT_READY;
}

// provenance: prime:extern/sdk/dolphin/card/CARDRead.c:56
// Single-pass completion scope replaces the reference's reducible goto cleanup.
void CARDRead_ReadCallback(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    u16* fat;
    CARDFileInfo* fileInfo;
    s32 length;

    card = &__CARDBlock[chan];
    do {
        if (result < 0) {
            break;
        }
        fileInfo = card->fileInfo;
        if (fileInfo->length < 0) {
            result = CARD_RESULT_CANCELED;
            break;
        }
        // Signed field interpretation follows retail; keep the shared ABI types.
        length = (s32)TRUNC((s32)fileInfo->offset + (s32)card->sectorSize,
                            (s32)card->sectorSize) - (s32)fileInfo->offset;
        fileInfo->length -= length;
        if (fileInfo->length <= 0) {
            break;
        }
        fat = __CARDGetFatBlock(card);
        fileInfo->offset += length;
        fileInfo->iBlock = fat[fileInfo->iBlock];
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock)) {
            result = CARD_RESULT_BROKEN;
            break;
        }
        result = __CARDRead(chan, card->sectorSize * (u32)fileInfo->iBlock,
                            (fileInfo->length < (s32)card->sectorSize) ? fileInfo->length : (s32)card->sectorSize,
                            card->buffer, CARDRead_ReadCallback);
        if (result < 0) {
            break;
        }
        return;
    } while (0);
    callback = card->apiCallback;
    card->apiCallback = 0;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

// provenance: prime:extern/sdk/dolphin/card/CARDRead.c:104
// GFZE01 uses __CARDIsPublic, as in dolsdk2001:src/card/CARDRead.c:118,
// but retains the two-argument __CARDAccess(card, ent) ABI.
s32 CARDReadAsync(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset,
                  CARDCallback callback) {
    CARDControl* card;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    if (OFFSET(offset, CARD_SEG_SIZE) != 0 || OFFSET(length, CARD_SEG_SIZE) != 0) {
        return CARD_RESULT_FATAL_ERROR;
    }
    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0) {
        return result;
    }
    dir = __CARDGetDirBlock(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDAccess(card, ent);
    if (result == CARD_RESULT_NOPERM) {
        result = __CARDIsPublic(ent);
    }
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    DCInvalidateRange(buf, (unsigned int)length);
    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    offset = (s32)OFFSET(fileInfo->offset, card->sectorSize);
    length = (length < (s32)card->sectorSize - offset) ? length : (s32)card->sectorSize - offset;
    result = __CARDRead(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock + offset,
                        length, buf, CARDRead_ReadCallback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

// provenance: retail 0x8002F570-0x8002F5B8
// CARDRead is the synchronous wrapper around CARDReadAsync.  The callback
// is installed before the read starts; successful submission then waits on
// the channel, while submission errors are returned directly.
s32 CARDRead(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset) {
    s32 result = CARDReadAsync(fileInfo, buf, length, offset, __CARDSyncCallback);

    if (result < 0) {
        return result;
    }
    return __CARDSync(fileInfo->chan);
}

#pragma pop
