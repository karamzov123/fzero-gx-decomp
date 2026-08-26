// NATC candidate 1 — main/dolphin/card/CARDDelete (GFZE01)
// Seed provenance: [local cache]/ref/melee/extern/dolphin/src/dolphin/card/CARDDelete.c
// (exact-name Melee SDK body), adapted to GFZE01 names/layout facts:
//   __CARDBlock .sdata? -> ADDR16_HA/LO array; CARDControl.startBlock @0xBE,
//   apiCallback @0xD0; CARDDir entry stride 0x40, startBlock @0x36.
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#define CARD_MAX_FILE 127
#define CARD_RESULT_FATAL_ERROR (-128)
#define CARD_RESULT_BUSY (-1)

typedef void (*CARDCallback)(s32 chan, s32 result);

typedef struct CARDDir {
    /*0x00*/ u8 gameName[4];
    /*0x04*/ u8 company[2];
    /*0x06*/ u8 _pad0;
    /*0x07*/ u8 bannerFormat;
    /*0x08*/ u8 fileName[32];
    /*0x28*/ u32 time;
    /*0x2C*/ u32 iconAddr;
    /*0x30*/ u16 iconFormat;
    /*0x32*/ u16 iconSpeed;
    /*0x34*/ u8 permission;
    /*0x35*/ u8 copyTimes;
    /*0x36*/ u16 startBlock;
    /*0x38*/ u16 length;
    /*0x3A*/ u8 _pad1[2];
    /*0x3C*/ u32 commentAddr;
} CARDDir; // sizeof == 0x40

typedef struct CARDControl {
    u8 _unk[0xBC];     // attachment/mount state, unused here
    /*0xBC*/ u16 freeNo;
    /*0xBE*/ u16 startBlock;
    u8 _unk2[0x10];    // 0xC0..0xD0
    /*0xD0*/ CARDCallback apiCallback;
    u8 _tail[0x110 - 0xD4]; // retail sizeof(CARDControl) == 0x110 (mulli stride)
} CARDControl;

extern CARDControl __CARDBlock[2];

// dependency slice — externs only
extern s32 __CARDFreeBlock(s32 chan, u16 nBlock, CARDCallback callback);
extern s32 __CARDPutControlBlock(CARDControl* card, s32 result);
extern s32 __CARDGetControlBlock(s32 chan, CARDControl** pcard);
extern CARDDir* __CARDGetDirBlock(CARDControl* card);
extern s32 __CARDAccess(CARDControl* card, CARDDir* ent);
extern s32 __CARDIsOpened(CARDControl* card, s32 fileNo);
extern s32 __CARDGetFileNo(CARDControl* card, const char* fileName, s32* pfileNo);
extern s32 __CARDUpdateDir(s32 chan, CARDCallback callback);
extern s32 __CARDSync(s32 chan);
extern void __CARDDefaultApiCallback(void);  // function decl; &-reference forces ADDR16_HA/LO
extern void __CARDSyncCallback(void);
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
