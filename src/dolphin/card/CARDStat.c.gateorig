// NATC candidate 1 -- main/dolphin/card/CARDStat (GFZE01)
// Seed provenance: ~/.cache/natc/ref/melee/extern/dolphin/src/dolphin/card/CARDStat.c
// (exact-name Melee SDK body), adapted to GFZE01 facts from accepted twins
// CARDRename.c / CARDDelete.c:
//   - __CARDGetDirBlock takes the CARDControl* (returns CARDEntry*)
//   - OSTicksToSeconds = OSGetTime() / (__OSBusClock>>2) via __div2i;
//     __OSBusClock at 0x800000F8 absolute, no reloc
//   - CARDEntry stride 0x40; UpdateIconOffsets is a real FUNC symbol here
// Hypothesis: faithful adaptation reproduces all four functions including
// the unrolled icon loop (compiler unrolls ctr=2 loop x2 + peels).

typedef int s32;
typedef int BOOL;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long long s64;
typedef unsigned long long u64;

#define CARD_MAX_FILE 127
#define CARD_FILENAME_MAX 32
#define CARD_READ_SIZE 0x200
#define CARD_SYSTEM_BLOCK_SIZE 0x4000
#define CARD_COMMENT_SIZE 64
#define CARD_RESULT_FATAL_ERROR (-128)
#define CARD_RESULT_NOPERM (-10)

#define __OSBusClock (*(u32*)0x800000F8)
#define OSTicksToSeconds(t) ((u32)((s64)(t) / (long long)(__OSBusClock >> 2)))

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

typedef struct CARDStat {
    /*0x00*/ char fileName[CARD_FILENAME_MAX];
    /*0x20*/ u32 length;
    /*0x24*/ u32 time;
    /*0x28*/ u8 gameName[4];
    /*0x2C*/ u8 company[2];
    /*0x2E*/ u8 bannerFormat;
    /*0x30*/ u32 iconAddr;
    /*0x34*/ u16 iconFormat;
    /*0x36*/ u16 iconSpeed;
    /*0x38*/ u32 commentAddr;
    /*0x3C*/ u32 offsetBanner;
    /*0x40*/ u32 offsetBannerTlut;
    /*0x44*/ u32 offsetIcon[8];
    /*0x64*/ u32 offsetIconTlut;
    /*0x68*/ u32 offsetData;
} CARDStat;

typedef struct CARDControl {
    u8 _unk[0xBC];
    /*0xBC*/ u16 freeNo;
    u8 _unk2[0x12]; // 0xC0..0xD4? sectorSize read at 0xC in CARDGetStatus -> card+0xC
} CARDControl;

extern s32 __CARDGetControlBlock(s32 chan, void** pcard);
extern s32 __CARDPutControlBlock(void* card, s32 err);
extern CARDDir* __CARDGetDirBlock(void* card);
extern s32 __CARDAccess(void* card, CARDDir* ent);
extern s32 __CARDIsPublic(CARDDir* ent);
extern void* memcpy(void* dst, void* src, u32 n);
extern s32 __CARDUpdateDir(s32 chan, CARDCallback callback);
extern s32 __CARDSync(s32 chan);
extern unsigned long long OSGetTime(void);
extern long long __div2i(long long a, long long b);
extern void __CARDSyncCallback(s32 chan, s32 result);

#define CARD_STAT_BANNER_NONE 0
#define CARD_STAT_BANNER_C8 1
#define CARD_STAT_BANNER_RGB5A3 2
#define CARD_ICON_MAX 8

#define CARDGetBannerFormat(ent) ((ent)->bannerFormat & 3)
#define CARDGetIconFormat(ent, n) (((ent)->iconFormat >> (2 * (n))) & 3)
#define CARD_BANNER_WIDTH 96
#define CARD_BANNER_HEIGHT 32
#define CARD_ICON_WIDTH 32
#define CARD_ICON_HEIGHT 32
#define CARD_STAT_SPEED_FAST 1

#pragma push
#pragma force_active on

static void UpdateIconOffsets(CARDDir* ent, CARDStat* stat)
{
    u32 offset;
    BOOL iconTlut;
    int i;

    offset = ent->iconAddr;
    if (offset == 0xffffffff)
    {
        stat->bannerFormat = 0;
        stat->iconFormat = 0;
        stat->iconSpeed = 0;
        offset = 0;
    }

    iconTlut = 0;
    switch (CARDGetBannerFormat(ent))
    {
    case CARD_STAT_BANNER_C8:
        stat->offsetBanner = offset;
        offset += CARD_BANNER_WIDTH * CARD_BANNER_HEIGHT;
        stat->offsetBannerTlut = offset;
        offset += 2 * 256;
        break;
    case CARD_STAT_BANNER_RGB5A3:
        stat->offsetBanner = offset;
        offset += 2 * CARD_BANNER_WIDTH * CARD_BANNER_HEIGHT;
        stat->offsetBannerTlut = 0xffffffff;
        break;
    default:
        stat->offsetBanner = 0xffffffff;
        stat->offsetBannerTlut = 0xffffffff;
        break;
    }
    for (i = 0; i < CARD_ICON_MAX; ++i)
    {
        switch (CARDGetIconFormat(ent, i))
        {
        case CARD_STAT_BANNER_C8:
            stat->offsetIcon[i] = offset;
            offset += CARD_ICON_WIDTH * CARD_ICON_HEIGHT;
            iconTlut = 1;
            break;
        case CARD_STAT_BANNER_RGB5A3:
            stat->offsetIcon[i] = offset;
            offset += 2 * CARD_ICON_WIDTH * CARD_ICON_HEIGHT;
            break;
        default:
            stat->offsetIcon[i] = 0xffffffff;
            break;
        }
    }
    if (iconTlut)
    {
        stat->offsetIconTlut = offset;
        offset += 2 * 256;
    }
    else
    {
        stat->offsetIconTlut = 0xffffffff;
    }
    stat->offsetData = offset;
}

s32 CARDGetStatus(s32 chan, s32 fileNo, CARDStat* stat)
{
    void* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;

    if (fileNo < 0 || CARD_MAX_FILE <= fileNo)
        return CARD_RESULT_FATAL_ERROR;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result == CARD_RESULT_NOPERM)
        result = __CARDIsPublic(ent);

    if (result >= 0)
    {
        memcpy(stat->gameName, ent->gameName, 4);
        memcpy(stat->company, ent->company, 2);
        stat->length = (u32)ent->length * *(u32*)((char*)card + 0xc);
        memcpy(stat->fileName, ent->fileName, CARD_FILENAME_MAX);
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

s32 CARDSetStatusAsync(s32 chan, s32 fileNo, CARDStat* stat, CARDCallback callback)
{
    void* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;

    if (fileNo < 0 || CARD_MAX_FILE <= fileNo ||
        (stat->iconAddr != -1 && CARD_READ_SIZE <= stat->iconAddr) ||
        (stat->commentAddr != -1 &&
         stat->commentAddr % 0x2000 > 0x1fc0))
        return CARD_RESULT_FATAL_ERROR;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0)
        return __CARDPutControlBlock(card, result);

    ent->bannerFormat = stat->bannerFormat;
    ent->iconAddr = stat->iconAddr;
    ent->iconFormat = stat->iconFormat;
    ent->iconSpeed = stat->iconSpeed;
    ent->commentAddr = stat->commentAddr;
    UpdateIconOffsets(ent, stat);

    if (ent->iconAddr == 0xffffffff) {
        ent->iconSpeed = (u16)((ent->iconSpeed & ~3) | CARD_STAT_SPEED_FAST);
    }

    ent->time = OSTicksToSeconds(OSGetTime());
    result = __CARDUpdateDir(chan, callback);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 CARDSetStatus(s32 chan, s32 fileNo, CARDStat* stat)
{
    s32 result = CARDSetStatusAsync(chan, fileNo, stat, __CARDSyncCallback);

    if (result < 0) {
        return result;
    }
    return __CARDSync(chan);
}
#pragma pop
