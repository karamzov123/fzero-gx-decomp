#include <dolphin/card/CARDPriv.h>
#include "sdk_addresses.h"


/* --- dol/UpdateIconOffsets.c --- */
void UpdateIconOffsets(CARDDir *ent, CARDStat *stat);

void UpdateIconOffsets(CARDDir *ent, CARDStat *stat) {
    u32 offset;
    BOOL iconTlut;
    int i;
    offset = ent->iconAddr;
    if (offset == 0xffffffff) {
        stat->bannerFormat = 0;
        stat->iconFormat = 0;
        stat->iconSpeed = 0;
        offset = 0;
    }
    iconTlut = 0;
    switch ((((ent)->bannerFormat) & 3)) {
    case 1:
        stat->offsetBanner = offset;
        offset += 96 * 32;
        stat->offsetBannerTlut = offset;
        offset += 2 * 256;
        break;
    case 2:
        stat->offsetBanner = offset;
        offset += 2 * 96 * 32;
        stat->offsetBannerTlut = 0xffffffff;
        break;
    default:
        stat->offsetBanner = 0xffffffff;
        stat->offsetBannerTlut = 0xffffffff;
        break;
    }
    for (i = 0; i < 8; ++i) {
        switch ((((ent)->iconFormat >> (2 * (i))) & 3)) {
        case 1:
            stat->offsetIcon[i] = offset;
            offset += 32 * 32;
            iconTlut = 1;
            break;
        case 2:
            stat->offsetIcon[i] = offset;
            offset += 2 * 32 * 32;
            break;
        default:
            stat->offsetIcon[i] = 0xffffffff;
            break;
        }
    }
    if (iconTlut) {
        stat->offsetIconTlut = offset;
        offset += 2 * 256;
    } else {
        stat->offsetIconTlut = 0xffffffff;
    }
    stat->offsetData = offset;
}

/* --- dol/CARDGetStatus.c --- */
extern CARDDir *fn_8002C4BC(CARDControl *card);
void UpdateIconOffsets(CARDDir *ent, CARDStat *stat);

s32 CARDGetStatus(s32 chan, s32 fileNo, CARDStat *stat) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    s32 result;
    (void)0;
    (void)0;
    if (fileNo < 0 || 127 <= fileNo)
        return -128;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;
    dir = fn_8002C4BC(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result == -10) {
        result = __CARDIsPublic(ent);
    }
    if (result >= 0) {
        memcpy(stat->gameName, ent->gameName, sizeof(stat->gameName));
        memcpy(stat->company, ent->company, sizeof(stat->company));
        stat->length = (u32)ent->length * card->sectorSize;
        memcpy(stat->fileName, ent->fileName, 32);
        stat->time = ent->time;
        stat->bannerFormat = ent->bannerFormat;
        stat->iconAddr = ent->iconAddr;
        stat->iconFormat = ent->iconFormat;
        stat->iconSpeed = ent->iconSpeed;
        stat->commentAddr = ent->commentAddr;
        UpdateIconOffsets(ent, stat);
    }
    return __CARDPutControlBlock(card, result);
}

/* --- dol/CARDSetStatusAsync.c --- */
OSTime OSGetTime(void);
CARDDir *fn_8002C4BC(CARDControl *card);

void UpdateIconOffsets(CARDDir *ent, CARDStat *stat);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

s32 CARDSetStatusAsync(s32 chan, s32 fileNo, CARDStat *stat, CARDCallback callback) {
    CARDControl *card;
    CARDDir *dir;
    CARDDir *ent;
    s32 result;
    if (fileNo < 0 || 127 <= fileNo || (stat->iconAddr != 0xffffffff && 512 <= stat->iconAddr) ||
        (stat->commentAddr != 0xffffffff && (8 * 1024) - 64 < stat->commentAddr % (8 * 1024))) {
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
    ent->bannerFormat = stat->bannerFormat;
    ent->iconAddr = stat->iconAddr;
    ent->iconFormat = stat->iconFormat;
    ent->iconSpeed = stat->iconSpeed;
    ent->commentAddr = stat->commentAddr;
    UpdateIconOffsets(ent, stat);
    if (ent->iconAddr == 0xffffffff) {
        ((ent)->iconSpeed = (u16)(((ent)->iconSpeed & ~(3 << (2 * (0)))) | ((1) << (2 * (0)))));
    }
    ent->time = (u32)((OSGetTime()) / ((u32)__OSBusClock / 4));
    result = __CARDUpdateDir(chan, callback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}
