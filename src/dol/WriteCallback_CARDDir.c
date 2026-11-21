#include <dolphin/card/CARDPriv.h>
#include "types.h"


/* --- dol/EraseCallback.c --- */
/* --- dol/EraseCallback.c --- */
void WriteCallback(s32 chan, s32 result);

void EraseCallback(s32 chan, s32 result);

extern CARDControl lbl_80177960[2];

static inline u16 *__CARDGetFatBlock(CARDControl *card) { return card->currentFat; }

void EraseCallback(s32 chan, s32 result);

/* --- dol/__CARDAllocBlock.c --- */
s32 __CARDAllocBlock(s32 chan, u32 cBlock, CARDCallback callback);

/* --- dol/__CARDFreeBlock.c --- */
s32 __CARDFreeBlock(s32 chan, u16 nBlock, CARDCallback callback);

/* --- dol/__CARDUpdateFatBlock.c --- */
void DCStoreRange(void *addr, u32 nBytes);

void EraseCallback(s32 chan, s32 result);


s32 __CARDUpdateFatBlock(s32 chan, u16 *fat, CARDCallback callback);

/* --- dol/fn_8002C4BC.c --- */
typedef struct {
    u8 pad[0x84];
    u32 value;
} Fn8002C4BCObject;

u32 fn_8002C4BC(Fn8002C4BCObject *object);

/* --- dol/WriteCallback_CARDDir.c --- */
/* --- dol/WriteCallback_CARDDir.c --- */
void WriteCallback_CARDDir(s32 chan, s32 result);


void WriteCallback_CARDDir(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    card = &lbl_80177960[chan];
    if (0 <= result) {
        CARDDir *dir0 = (CARDDir *)((u8 *)card->workArea + 0x2000);
        CARDDir *dir1 = (CARDDir *)((u8 *)card->workArea + 0x4000);
        if (card->currentDir == dir0) {
            card->currentDir = dir1;
            memcpy(dir1, dir0, 0x2000);
        } else {
            card->currentDir = dir0;
            memcpy(dir0, dir1, 0x2000);
        }
    }
error:
    if (card->apiCallback == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = 0;
        callback(chan, result);
    }
}

/* --- dol/EraseCallback_CARDDir.c --- */
void WriteCallback_CARDDir(s32 chan, s32 result);

void EraseCallback_CARDDir(s32 chan, s32 result);


static inline CARDDir *__CARDGetDirBlock(CARDControl *card) { return card->currentDir; }

void EraseCallback_CARDDir(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    CARDDir *dir;
    u32 tmp[2];
    u32 addr;
    card = &lbl_80177960[chan];
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    dir = __CARDGetDirBlock(card);
    addr = ((u32)dir - (u32)card->workArea) / 0x2000 * card->sectorSize;
    result = __CARDWrite(chan, addr, 0x2000, dir, WriteCallback_CARDDir);
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    return;
error:
    if (card->apiCallback == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = 0;
        callback(chan, result);
    }
}

/* --- dol/__CARDUpdateDir.c --- */
void DCStoreRange(void *addr, u32 nBytes);

void EraseCallback_CARDDir(s32 chan, s32 result);



s32 __CARDUpdateDir(s32 chan, CARDCallback callback) {
    CARDControl *card;
    CARDDirCheck *check;
    u32 tmp[2];
    u32 addr;
    CARDDir *dir;
    card = &lbl_80177960[chan];
    if (!card->attached) {
        return -3;
    }
    dir = __CARDGetDirBlock(card);
    check = ((CARDDirCheck *)&(dir)[127]);
    ++check->checkCode;
    __CARDCheckSum(dir, 0x2000 - sizeof(u32), &check->checkSum, &check->checkSumInv);
    DCStoreRange(dir, 0x2000);
    card->eraseCallback = callback;
    addr = ((u32)dir - (u32)card->workArea) / 0x2000 * card->sectorSize;
    return __CARDEraseSector(chan, addr, EraseCallback_CARDDir);
}
