// NATC candidate 1 -- main/dolphin/card/CARDCreate (GFZE01)
// Seed provenance: [local cache]/ref/melee/extern/dolphin/src/dolphin/card/CARDCreate.c
// (exact-name Melee body), adapted to GFZE01 facts from accepted twins
// CARDRename/CARDDelete/CARDStat (this session):
//   - __CARDGetDirBlock takes card*, returns entry array
//   - diskID pointer at card+0x10C; sectorSize u32 at card+0xC
//   - apiCallback @0xD0, freeNo @0xBC, fileBase? fileInfo @0xC0
//   - GFZE01 result codes: NAMETOOLONG -12, EXIST -7, NOENT -8, INSSPACE -9,
//     FATAL -128; CARDFileInfo chan/fileNo/offset/iBlock are 32-bit
// Hypothesis: direct adaptation matches both functions including stmw/lmw
// prologue shape (8 live locals force r23..r31 allocation).

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

typedef struct CARDDir {  u8 gameName[4];  u8 company[2];  u8 _pad0;  u8 bannerFormat;  u8 fileName[32];  u32 time;  u32 iconAddr;  u16 iconFormat;  u16 iconSpeed;  u8 permission;  u8 copyTimes;  u16 startBlock;  u16 length;  u8 _pad1[2];  u32 commentAddr;
u8 _pad1_2[0];
} CARDDir;

typedef struct CARDFileInfo {  s32 chan;  s32 fileNo;  u32 offset;  u16 iBlock;
} CARDFileInfo;

extern u32 strlen(char* s);
extern s32 __CARDGetControlBlock(s32 chan, void** pcard);
extern s32 __CARDPutControlBlock(void* card, s32 err);
extern CARDDir* __CARDGetDirBlock(void* card);
extern void* __CARDGetFatBlock(void* card);
extern s32 __CARDAllocBlock(s32 chn, u32 nBlock, void* callback);
extern s32 __CARDCompareFileName(CARDDir* ent, char* fileName);
extern s32 __CARDSync(s32 chn);
extern s32 strncmp(void* a, void* b, u32 n);
extern s32 strncpy(char* dst, char* src, u32 n);
extern void __CARDDefaultApiCallback(void);
extern void CreateCallbackFat(s32 chan, s32 result);
extern void __CARDSyncCallback(s32 chan, s32 result);

#define SECTOR_SIZE(card) (*(u32*)((char*)(card) + 0xc))
#define DISK_ID(card) (*(void**)((char*)(card) + 0x10c))

#pragma push
#pragma force_active on

s32 CARDCreateAsync(s32 chan, char* fileName, u32 size, CARDFileInfo* fileInfo,
                    void* callback)
{
    void* card;
    CARDDir* dir;
    CARDDir* ent;
    u16 fileNo;
    u16 freeNo;
    u16* fat;
    s32 result;

    if (strlen(fileName) > 0x20)
        return -12;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    if (size == 0 || (size % SECTOR_SIZE(card)) != 0)
        return -128;

    freeNo = 0xffff;
    dir = __CARDGetDirBlock(card);
    for (fileNo = 0; fileNo < 127; fileNo++) {
        ent = &dir[fileNo];
        if (ent->gameName[0] == 0xff) {
            if (freeNo == 0xffff) {
                freeNo = fileNo;
            }
        } else if (strncmp(ent->gameName, DISK_ID(card), 4) == 0 &&
                   strncmp(ent->company, (char*)DISK_ID(card) + 4, 2) == 0 &&
                   __CARDCompareFileName(ent, fileName)) {
            return __CARDPutControlBlock(card, -7);
        }
    }
    if (freeNo == 0xffff)
        return __CARDPutControlBlock(card, -8);

    fat = __CARDGetFatBlock(card);
    if (SECTOR_SIZE(card) * fat[3] < size)
        return __CARDPutControlBlock(card, -9);

    *(void**)((char*)card + 0xd0) = callback ? callback : __CARDDefaultApiCallback;
    *(u16*)((char*)card + 0xbc) = freeNo;
    ent = &dir[freeNo];
    ent->length = (u16)(size / SECTOR_SIZE(card));
    strncpy((char*)ent->fileName, fileName, 0x20);

    *(void**)((char*)card + 0xc0) = fileInfo;
    fileInfo->chan = chan;
    fileInfo->fileNo = freeNo;

    result = __CARDAllocBlock(chan, size / SECTOR_SIZE(card), CreateCallbackFat);
    if (result < 0)
        return __CARDPutControlBlock(card, result);
    return result;
}

s32 CARDCreate(s32 chan, char* fileName, u32 size, CARDFileInfo* fileInfo)
{
    s32 result = CARDCreateAsync(chan, fileName, size, fileInfo, __CARDSyncCallback);

    if (result < 0) {
        return result;
    }
    return __CARDSync(chan);
}
#pragma pop
