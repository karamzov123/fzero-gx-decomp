#include <dolphin/card/CARDPriv.h>
#include "types.h"


/* --- dol/CARDOpen.c --- */
extern DVDDiskID lbl_80177B80;

extern CARDDir *fn_8002C4BC(CARDControl *card);

BOOL __CARDCompareFileName(CARDDir *ent, const char *fileName) {
    char *entName = (char *)ent->fileName;
    char c1;
    char c2;
    int n = 32;
    while (--n >= 0) {
        if ((c1 = *entName++) != (c2 = *fileName++))
            return 0;
        else if (c2 == '\0')
            return 1;
    }
    if (*fileName == '\0')
        return 1;
    return 0;
}

s32 __CARDAccess(CARDControl *card, CARDDir *ent) {
    if (ent->gameName[0] == 0xFF)
        return -4;
    if (card->diskID == &lbl_80177B80 ||
        (fn_8008023C(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) == 0 &&
         fn_8008023C(ent->company, card->diskID->company, sizeof(ent->company)) == 0))
        return 0;
    return -10;
}

s32 __CARDIsPublic(CARDDir *ent) {
    if (ent->gameName[0] == 0xFF)
        return -4;
    if (ent->permission & 4)
        return 0;
    return -10;
}

s32 __CARDGetFileNo(CARDControl *card, const char *fileName, s32 *pfileNo) {
    CARDDir *dir;
    CARDDir *ent;
    s32 fileNo;
    s32 result;
    if (!card->attached)
        return -3;
    dir = fn_8002C4BC(card);
    for (fileNo = 0; fileNo < 127; fileNo++) {
        ent = &dir[fileNo];
        result = __CARDAccess(card, ent);
        if (result < 0)
            continue;
        if (__CARDCompareFileName(ent, fileName)) {
            *pfileNo = fileNo;
            return 0;
        }
    }
    return -4;
}

s32 CARDOpen(s32 chan, const char *fileName, CARDFileInfo *fileInfo) {
    CARDControl *card;
    s32 fileNo;
    s32 result;
    CARDDir *dir;
    CARDDir *ent;
    (void)0;
    fileInfo->chan = -1;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;
    result = __CARDGetFileNo(card, fileName, &fileNo);
    if (result >= 0) {
        dir = fn_8002C4BC(card);
        ent = &dir[fileNo];
        if (!((ent->startBlock) >= 5 && (ent->startBlock) < (card)->cBlock))
            result = -6;
        else {
            fileInfo->chan = chan;
            fileInfo->fileNo = fileNo;
            fileInfo->offset = 0;
            fileInfo->iBlock = ent->startBlock;
        }
    }
    return __CARDPutControlBlock(card, result);
}

s32 CARDClose(CARDFileInfo *fileInfo) {
    CARDControl *card;
    s32 result;
    (void)0;
    (void)0;
    result = __CARDGetControlBlock(fileInfo->chan, &card);
    if (result < 0)
        return result;
    fileInfo->chan = -1;
    return __CARDPutControlBlock(card, 0);
}

/* --- dol/fn_8002EDA0.c --- */
// fn_8002EDA0: returns a constant.
int fn_8002EDA0(void) {
    return 0;
}
