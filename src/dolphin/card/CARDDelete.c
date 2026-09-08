// NATC candidate 1 — main/dolphin/card/CARDDelete (GFZE01)
// Seed provenance: [local cache]/ref/melee/extern/dolphin/src/dolphin/card/CARDDelete.c
// (exact-name Melee SDK body), adapted to GFZE01 names/layout facts:
//   __CARDBlock .sdata? -> ADDR16_HA/LO array; CARDControl.startBlock @0xBE,
//   apiCallback @0xD0; CARDDir entry stride 0x40, startBlock @0x36.
// provenance: original; type-compatibility repair for this repository; see docs/contributions/card-file-access/CARD.md
#include <dolphin/card_private.h>

#define CARD_RESULT_BUSY (-1)

// dependency slice — externs only
extern s32 __CARDFreeBlock(s32 chan, u16 nBlock, CARDCallback callback);
extern s32 __CARDIsOpened(CARDControl* card, s32 fileNo);
// provenance: original; type-compatibility repair for this repository; see docs/contributions/card-file-access/CARD.md
extern s32 __CARDGetFileNo(CARDControl* card, const char* fileName, s32* pfileNo);
extern void* memset(void* dst, int val, u32 n);

#pragma push
#pragma force_active on

static void DeleteCallback(s32 chan, s32 result) {
    CARDControl* card = &__CARDBlock[chan];
    CARDCallback callback = card->apiCallback;

    card->apiCallback = 0;
    if (result < 0) {
        goto error;
    }

    result = __CARDFreeBlock(chan, card->startBlock, callback);
    if (result < 0) {
        goto error;
    }
    return;

error:
    __CARDPutControlBlock(card, result);
    if (callback != 0) {
        callback(chan, result);
    }
}

s32 CARDFastDeleteAsync(s32 chan, s32 fileNo, CARDCallback callback) {
    CARDControl* card;
    CARDDir* ent;
    s32 result;

    if (fileNo < 0 || CARD_MAX_FILE <= fileNo) {
        return CARD_RESULT_FATAL_ERROR;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }

    ent = &__CARDGetDirBlock(card)[fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    if (__CARDIsOpened(card, fileNo)) {
        return __CARDPutControlBlock(card, CARD_RESULT_BUSY);
    }

    card->startBlock = ent->startBlock;
    memset(ent, 0xFF, sizeof(CARDDir));

    card->apiCallback = callback != 0 ? callback : (CARDCallback)__CARDDefaultApiCallback;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 CARDDeleteAsync(s32 chan, char* fileName, CARDCallback callback) {
    CARDControl* card;
    CARDDir* ent;
    s32 fileNo;
    s32 result;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    result = __CARDGetFileNo(card, fileName, &fileNo);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    if (__CARDIsOpened(card, fileNo)) {
        return __CARDPutControlBlock(card, CARD_RESULT_BUSY);
    }

    ent = &__CARDGetDirBlock(card)[fileNo];
    card->startBlock = ent->startBlock;
    memset(ent, 0xFF, sizeof(CARDDir));

    card->apiCallback = callback != 0 ? callback : (CARDCallback)__CARDDefaultApiCallback;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 CARDFastDelete(s32 chan, s32 fileNo) {
    s32 result = CARDDeleteAsync(chan, (char*)fileNo, (CARDCallback)__CARDSyncCallback);

    if (result < 0) {
        return result;
    }
    return __CARDSync(chan);
}

#pragma pop
