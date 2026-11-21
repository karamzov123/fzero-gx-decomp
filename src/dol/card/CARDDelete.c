#include <dolphin/card/CARDPriv.h>
#include "types.h"

void fn_80029824(s32 chan, s32 result);
CARDDir *fn_8002C4BC(CARDControl *card);

extern CARDControl lbl_80177960[2];
extern s32 __CARDFreeBlock(s32 chan, u16 nBlock, CARDCallback callback);

void DeleteCallback(s32 chan, s32 result) {
    CARDControl *card = &lbl_80177960[chan];
    CARDCallback callback = card->apiCallback;
    card->apiCallback = 0;
    if (result >= 0) {
        result = __CARDFreeBlock(chan, card->startBlock, callback);
        if (result >= 0) {
            return;
        }
    }
    __CARDPutControlBlock(card, result);
    if (callback != 0) {
        callback(chan, result);
    }
}

s32 CARDFastDeleteAsync(s32 chan, s32 fileNo, CARDCallback callback) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    s32 result;
    if (fileNo < 0 || 127 <= fileNo) {
        return -128;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    dir = fn_8002C4BC(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    if (fn_8002EDA0(card, fileNo)) {
        return __CARDPutControlBlock(card, -1);
    }
    card->startBlock = ent->startBlock;
    memset(ent, 0xff, sizeof(CARDDir));
    card->apiCallback = callback ? callback : fn_80029824;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 CARDDeleteAsync(s32 chan, const char *fileName, CARDCallback callback) {
    CARDControl *card;
    s32 fileNo;
    s32 result;
    CARDDir *dir;
    CARDDir *ent;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    result = __CARDGetFileNo(card, fileName, &fileNo);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    if (fn_8002EDA0(card, fileNo)) {
        return __CARDPutControlBlock(card, -1);
    }
    dir = fn_8002C4BC(card);
    ent = &dir[fileNo];
    card->startBlock = ent->startBlock;
    memset(ent, 0xff, sizeof(CARDDir));
    card->apiCallback = callback ? callback : fn_80029824;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 fn_8002FC14(u32 arg0, void *arg1) {
    s32 result;

    result = CARDDeleteAsync(arg0, arg1, __CARDSyncCallback);
    if (result < 0) {
        return result;
    } else {
        result = __CARDSync(arg0);
    }
    return result;
}
