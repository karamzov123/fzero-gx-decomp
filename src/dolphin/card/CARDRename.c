// dolphin/card/CARDRename.c -- carved from coarse/text_8002F5B8 (0x8003013C-0x80030380).
// Melee identity: extern/dolphin/src/dolphin/card/CARDRename.c
//   CARDRenameAsync, CARDRename.
// Natural C conversion: 100% objdiff match, relocations byte-identical.
// Notes:
//   - __CARDGetDirBlock takes the control block (retail signature differs from Melee).
//   - CARDEntry stride is 0x40; time field at +0x28; diskID at card+0x10c.
//   - Timestamp = OSGetTime() / (__OSBusClock>>2) via __div2i; __OSBusClock at
//     0x800000F8 is loaded absolute (no reloc in retail).


typedef int s32;
typedef unsigned char u8;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef long long s64;

#define __OSBusClock (*(u32*)0x800000F8)
#define OSTicksToSeconds(t) ((u32)((s64)(t) / (long long)(__OSBusClock >> 2)))

typedef struct CARDEntry {
    u8 gameName[4];
    u8 company[2];
    u8 pad2[2];
    char fileName[32];
    u32 time;
    u8 pad[18];
} CARDEntry;


extern s32 __CARDGetControlBlock(register s32 card, register void** pctrl);
extern s32 __CARDPutControlBlock(register void* ctrl, register s32 err);
extern CARDEntry* __CARDGetDirBlock(register void* ctrl);
extern s32 __CARDAccess(register void* ctrl, register void* ent);
extern s32 __CARDCompareFileName(register void* ent, register char* fileName);
extern s32 strncmp(register void* a, register void* b, register u32 n);
extern u32 strlen(register char* s);
extern s32 strncpy(register char* dst, register char* src, register u32 n);
extern s32 __CARDUpdateDir(register s32 chn, register void* callback);
extern s32 __CARDSync(register s32 chn);
extern unsigned long long OSGetTime(void);
extern void __CARDSyncCallback(void);

#pragma push
#pragma force_active on

s32 CARDRenameAsync(s32 chan, char* oldName, char* newName, void* callback)
{
    s32 res2;
    void* card;
    CARDEntry* ent;
    CARDEntry* dir;
    s32 fileNo;
    s32 newNo;
    s32 oldNo;
    s32 result;

    if (oldName[0] == 0xFF || newName[0] == 0xFF || oldName[0] == 0 || newName[0] == 0)
        return -128;
    if ((u32)strlen(oldName) > 32 || (u32)strlen(newName) > 32)
        return -12;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;
    oldNo = -1;
    newNo = -1;
    dir = __CARDGetDirBlock(card);
    ent = dir;
    for (fileNo = 0; fileNo < 127; fileNo++, ent++)
    {
        if (ent->gameName[0] == 0xFF)
            continue;
        if (strncmp((char*)ent->gameName, *(char**)((char*)card + 0x10c), 4) != 0)
            continue;
        if (strncmp((char*)ent->company, *(char**)((char*)card + 0x10c) + 4, 2) != 0)
            continue;
        if (__CARDCompareFileName(ent, oldName))
            oldNo = fileNo;
        if (__CARDCompareFileName(ent, newName))
            newNo = fileNo;
    }
    if (oldNo == -1)
        return __CARDPutControlBlock(card, -4);
    if (newNo != -1)
        return __CARDPutControlBlock(card, -7);
    ent = &dir[oldNo];
    result = __CARDAccess(card, ent);
    if (result < 0)
        return __CARDPutControlBlock(card, result);
    strncpy(ent->fileName, newName, 32);
    ent->time = OSTicksToSeconds(OSGetTime());
    res2 = __CARDUpdateDir(chan, callback);
    if (res2 < 0)
        __CARDPutControlBlock(card, res2);
    return res2;
}

s32 CARDRename(s32 chan, char* oldName, char* newName)
{
    s32 result = CARDRenameAsync(chan, oldName, newName, __CARDSyncCallback);
    if (result < 0)
        return result;
    return __CARDSync(chan);
}

#pragma pop
