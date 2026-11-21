#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"
#include "types.h"

OSTime OSGetTime(void);
CARDDir *fn_8002C4BC(CARDControl *card);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

s32 CARDRenameAsync(s32 chan, const char *old, const char *new, CARDCallback callback) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    s32 result;
    int fileNo;
    int newNo;
    int oldNo;
    if (*old == 0xff || *new == 0xff || *old == 0x00 || *new == 0x00) {
        return -128;
    }
    if (32 < (u32)strlen(old) || 32 < (u32)strlen(new)) {
        return -12;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    newNo = oldNo = -1;
    dir = fn_8002C4BC(card);
    for (fileNo = 0; fileNo < 127; fileNo++) {
        ent = &dir[fileNo];
        if (ent->gameName[0] == 0xff) {
            continue;
        }
        if (fn_8008023C(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) != 0 ||
            fn_8008023C(ent->company, card->diskID->company, sizeof(ent->company)) != 0) {
            continue;
        }
        if (__CARDCompareFileName(ent, old)) {
            oldNo = fileNo;
        }
        if (__CARDCompareFileName(ent, new)) {
            newNo = fileNo;
        }
    }
    if (oldNo == -1) {
        return __CARDPutControlBlock(card, -4);
    }
    if (newNo != -1) {
        return __CARDPutControlBlock(card, -7);
    }
    ent = &dir[oldNo];
    result = __CARDAccess(card, ent);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    strncpy((char *)ent->fileName, new, 32);
    ent->time = (u32)((OSGetTime()) / ((u32)__OSBusClock / 4));
    result = __CARDUpdateDir(chan, callback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 fn_80030338(u32 arg0, u32 arg1, u32 arg2) {
    s32 status;

    status = CARDRenameAsync(arg0, (void *)arg1, (void *)arg2, __CARDSyncCallback);
    if (status < 0) {
        return status;
    }
    status = __CARDSync(arg0);
    return status;
}
