#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>

typedef struct DVDBB2 {
    u32 bootFilePosition;
    u32 FSTPosition;
    u32 FSTLength;
    u32 FSTMaxLength;
    void *FSTAddress;
    u32 userPosition;
    u32 userLength;
    u32 padding0;
} DVDBB2;

typedef struct OSBootInfo {
    DVDDiskID DVDDiskID;
    u32 magic;
    u32 version;
    u32 memorySize;
    u32 consoleType;
    void *arenaLo;
    void *arenaHi;
    void *FSTLocation;
    u32 FSTMaxLength;
} OSBootInfo;

void DVDReset();

BOOL DVDReadDiskID(DVDCommandBlock *block, DVDDiskID *diskID, DVDCBCallback callback);

s32 DVDGetDriveStatus();

BOOL DVDReadAbsAsyncForBS(DVDCommandBlock *block, void *addr, s32 length, s32 offset,
                 DVDCBCallback callback);

void OSSetArenaHi(void *newHi);

void OSReport(const char *msg, ...);

void OSSetArenaHi(void *addr);

void *memcpy(void *dest, const void *src, size_t n);

extern s32 lbl_801A6910;

extern u8 bb2Buf[((((u32)sizeof(DVDBB2) + 31) & ~31)) + 31];

extern DVDBB2 *bb2;

extern DVDDiskID *idTmp;

void cb(s32 result, DVDCommandBlock *block);

void __fstLoad();

void cb(s32 result, DVDCommandBlock *block) {
    if (result > 0) {
        switch (lbl_801A6910) {
        case 0:
            lbl_801A6910 = 1;
            DVDReadAbsAsyncForBS(block, bb2, ((((u32)sizeof(bb2) + 31) & ~31)), 0x420, cb);
            break;
        case 1:
            lbl_801A6910 = 2;
            DVDReadAbsAsyncForBS(block, bb2->FSTAddress,
                        ((((u32)bb2->FSTLength + 31) & ~31)), bb2->FSTPosition,
                        cb);
        }
    } else if (result == -1) {
    } else if (result == -4) {
        lbl_801A6910 = 0;
        DVDReset();
        DVDReadDiskID(block, idTmp, cb);
    }
}

void __fstLoad() {
    OSBootInfo *bootInfo;
    DVDDiskID *id;
    u8 idTmpBuf[sizeof(DVDDiskID) + 31];
    static DVDCommandBlock block;
    void *arenaHi;
    arenaHi = OSGetArenaHi();
    bootInfo = (OSBootInfo *)((void *)((u32)(0) + (0x8000 << 16)));
    idTmp = (DVDDiskID *)(((((u32)idTmpBuf + 31) & ~31)));
    bb2 = (DVDBB2 *)(((((u32)bb2Buf + 31) & ~31)));
    DVDReset();
    DVDReadDiskID(&block, idTmp, cb);
    while (DVDGetDriveStatus() != 0)
        ;
    bootInfo->FSTLocation = bb2->FSTAddress;
    bootInfo->FSTMaxLength = bb2->FSTMaxLength;
    id = &bootInfo->DVDDiskID;
    memcpy(id, idTmp, sizeof(DVDDiskID));
    OSReport("\n");
    OSReport("  Game Name ... %c%c%c%c\n", id->gameName[0], id->gameName[1], id->gameName[2],
             id->gameName[3]);
    OSReport("  Company ..... %c%c\n", id->company[0], id->company[1]);
    OSReport("  Disk # ...... %d\n", id->diskNumber);
    OSReport("  Game ver .... %d\n", id->gameVersion);
    OSReport("  Streaming ... %s\n", (id->streaming == 0) ? "OFF" : "ON");
    OSReport("\n");
    OSSetArenaHi(bb2->FSTAddress);
}
