#include <dolphin/types.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/dvd.h>
#include "sdk_addresses.h"

typedef unsigned int uint;

typedef struct OSBootInfo {
    u8 pad[0x38];
    void *FSTLocation;
} OSBootInfo;

typedef struct FSTEntry FSTEntry;
struct FSTEntry {
    uint isDirAndStringOff;
    uint parentOrPosition;
    uint nextEntryOrLength;
};

typedef struct DVDFileInfo DVDFileInfo;
typedef void (*DVDCallback)(s32 result, DVDFileInfo *fileInfo);

struct DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    DVDCallback callback;
};

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern OSBootInfo *BootInfo_801A68A0;
extern FSTEntry *FstStart;
extern char *FstStringStart;
extern u32 MaxEntryNum;
extern u32 lbl_801A68B0;
extern u32 __DVDLongFileNameFlag;
extern OSThreadQueue __DVDThreadQueue;
extern u32 lbl_801A68B4;
extern char lbl_801A6470[8];
extern char lbl_80123F28[];

void OSReport(const char *msg, ...);
void OSPanic(const char *file, int line, const char *message, ...);
int fn_8007ED90(int c);
BOOL DVDReadAbsAsyncPrio(DVDCommandBlock *block, void *addr, s32 length, s32 offset,
                         void (*callback)(s32 result, DVDCommandBlock *block), s32 prio);
s32 DVDGetCommandBlockStatus(const DVDCommandBlock *block);
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);
void OSSleepThread(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);

BOOL DVDGetCurrentDir(char *path, u32 maxlen);
void fn_80017590(s32 result, DVDCommandBlock *block);
void fn_800176D8(s32 result, DVDCommandBlock *block);


void __DVDFSInit(void) {
    BootInfo_801A68A0 = (OSBootInfo *)0x80000000; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    FstStart = (FSTEntry *)BootInfo_801A68A0->FSTLocation;
    if (FstStart) {
        MaxEntryNum = FstStart[0].nextEntryOrLength;
        FstStringStart = (char *)&FstStart[MaxEntryNum];
    }
}

static inline BOOL isSame(const char *path, const char *string) {
    while (*string != '\0') {
        if (fn_8007ED90(*path++) != fn_8007ED90(*string++)) {
            return (0);
        }
    }
    if ((*path == '/') || (*path == '\0')) {
        return (1);
    }
    return (0);
}

s32 DVDConvertPathToEntrynum(const char *pathPtr) {
    const char *ptr;
    char *stringPtr;
    BOOL isDir;
    u32 length;
    u32 dirLookAt;
    u32 i;
    const char *origPathPtr = pathPtr;
    const char *extentionStart;
    BOOL illegal;
    BOOL extention;
    dirLookAt = lbl_801A68B0;
    while (1) {
        if (*pathPtr == '\0') {
            return (s32)dirLookAt;
        } else if (*pathPtr == '/') {
            dirLookAt = 0;
            pathPtr++;
            continue;
        } else if (*pathPtr == '.') {
            if (*(pathPtr + 1) == '.') {
                if (*(pathPtr + 2) == '/') {
                    dirLookAt = (FstStart[dirLookAt].parentOrPosition);
                    pathPtr += 3;
                    continue;
                } else if (*(pathPtr + 2) == '\0') {
                    return (s32)(FstStart[dirLookAt].parentOrPosition);
                }
            } else if (*(pathPtr + 1) == '/') {
                pathPtr += 2;
                continue;
            } else if (*(pathPtr + 1) == '\0') {
                return (s32)dirLookAt;
            }
        }
        if (!__DVDLongFileNameFlag) {
            extention = (0);
            illegal = (0);
            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++) {
                if (*ptr == '.') {
                    if ((ptr - pathPtr > 8) || (extention == (1))) {
                        illegal = (1);
                        break;
                    }
                    extention = (1);
                    extentionStart = ptr + 1;
                } else if (*ptr == ' ') {
                    illegal = (1);
                }
            }
            if ((extention == (1)) && (ptr - extentionStart > 3)) {
                illegal = (1);
            }
            if (illegal) {
                OSPanic("dvdfs.c", 379,
                        "DVDConvertEntrynumToPath(possibly DVDOpen or DVDChangeDir or DVDOpenDir): "
                        "specified directory or file (%s) doesn't match standard 8.3 format. This "
                        "is a temporary restriction and will be removed soon\n",
                        origPathPtr);
            }
        } else {
            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++)
                ;
        }
        isDir = (*ptr == '\0') ? (0) : (1);
        length = (u32)(ptr - pathPtr);
        ptr = pathPtr;
        for (i = dirLookAt + 1; i < (FstStart[dirLookAt].nextEntryOrLength);
             i = (((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? (0) : (1))
                     ? (FstStart[i].nextEntryOrLength)
                     : (i + 1)) {
            if (((((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? (0) : (1)) == (0)) &&
                (isDir == (1))) {
                continue;
            }
            stringPtr = FstStringStart + (FstStart[i].isDirAndStringOff & ~0xff000000);
            if (isSame(ptr, stringPtr) == (1)) {
                goto next_hier; // Preserve the verified SDK control flow.
            }
        }
        return -1;
    next_hier:
        if (!isDir) {
            return (s32)i;
        }
        dirLookAt = i;
        pathPtr += length + 1;
    }
}

BOOL DVDFastOpen(s32 entrynum, DVDFileInfo *fileInfo) {
    if ((entrynum < 0) || (entrynum >= MaxEntryNum) ||
        (((FstStart[entrynum].isDirAndStringOff & 0xff000000) == 0) ? 0 : 1)) {
        return 0;
    }
    fileInfo->startAddr = (FstStart[entrynum].parentOrPosition);
    fileInfo->length = (FstStart[entrynum].nextEntryOrLength);
    fileInfo->callback = (DVDCallback)0;
    fileInfo->cb.state = 0;
    return 1;
}

BOOL DVDOpen(const char *fileName, DVDFileInfo *fileInfo) {
    s32 entry;
    char currentDir[128];
    entry = DVDConvertPathToEntrynum(fileName);
    if (0 > entry) {
        DVDGetCurrentDir(currentDir, 128);
        OSReport("Warning: DVDOpen(): file '%s' was not found under %s.\n", fileName, currentDir);
        return 0;
    }
    if ((((FstStart[entry].isDirAndStringOff & 0xff000000) == 0) ? 0 : 1)) {
        return 0;
    }
    fileInfo->startAddr = (FstStart[entry].parentOrPosition);
    fileInfo->length = (FstStart[entry].nextEntryOrLength);
    fileInfo->callback = (DVDCallback)0;
    fileInfo->cb.state = 0;
    return 1;
}

s32 DVDClose(void) {
    DVDCancel();
    return 1;
}

static inline u32 myStrncpy(char *dest, char *src, u32 maxlen) {
    u32 i = maxlen;
    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }
    return (maxlen - i);
}

u32 entryToPath(u32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;
    if (entry == 0) {
        return 0;
    }
    name = FstStringStart + (FstStart[entry].isDirAndStringOff & ~0xff000000);
    loc = entryToPath((FstStart[entry].parentOrPosition), path, maxlen);
    if (loc == maxlen) {
        return loc;
    }
    *(path + loc++) = '/';
    loc += myStrncpy(path + loc, name, maxlen - loc);
    return loc;
}

static inline BOOL DVDConvertEntrynumToPath(s32 entrynum, char *path, u32 maxlen) {
    u32 loc;
    loc = entryToPath((u32)entrynum, path, maxlen);
    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return 0;
    }
    if ((((FstStart[entrynum].isDirAndStringOff & 0xff000000) == 0) ? 0 : 1)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return 0;
        }
        path[loc++] = '/';
    }
    path[loc] = '\0';
    return 1;
}

BOOL DVDGetCurrentDir(char *path, u32 maxlen) {
    return DVDConvertEntrynumToPath((s32)lbl_801A68B0, path, maxlen);
}

BOOL DVDChangeDir(char *dirName) {
    s32 entry;
    entry = DVDConvertPathToEntrynum(dirName);
    if ((entry < 0) ||
        ((((FstStart[entry].isDirAndStringOff & 0xff000000) == 0) ? 0 : 1) == 0)) {
        return 0;
    }
    lbl_801A68B0 = (u32)entry;
    return 1;
}

BOOL DVDReadAsyncPrio(DVDFileInfo *fileInfo, void *addr, int length, int offset,
                      DVDCallback callback, s32 prio) {
    if (offset < 0 || (u32)offset >= fileInfo->length) {
        OSPanic(lbl_801A6470, 0x2e6, lbl_80123F28);
    }
    if (offset + length < 0 || (u32)(offset + length) >= fileInfo->length + 0x20) {
        OSPanic(lbl_801A6470, 0x2ec, lbl_80123F28);
    }
    fileInfo->callback = callback;
    DVDReadAbsAsyncPrio(&fileInfo->cb, addr, length, (s32)(fileInfo->startAddr + offset),
                        fn_80017590, prio);
    return TRUE;
}

BOOL DVDGetCurrentDir(char *path, u32 maxlen);
void fn_80017590(s32 result, DVDCommandBlock *block) {
    DVDFileInfo *fileInfo = (DVDFileInfo *)block;
    if (fileInfo->callback) {
        fileInfo->callback(result, fileInfo);
    }
}

s32 DVDReadPrio(DVDFileInfo *fileInfo, void *addr, s32 length, s32 offset, s32 prio) {
    BOOL result;
    DVDCommandBlock *block;
    s32 state;
    BOOL enabled;
    s32 retVal;
    if (!((0 <= offset) && (offset < fileInfo->length))) {
        OSPanic("dvdfs.c", 812, "DVDRead(): specified area is out of the file  ");
    }
    if (!((0 <= offset + length) && (offset + length < fileInfo->length + 32))) {
        OSPanic("dvdfs.c", 818, "DVDRead(): specified area is out of the file  ");
    }
    block = &fileInfo->cb;
    result =
        DVDReadAbsAsyncPrio(block, addr, length, (fileInfo->startAddr + offset), fn_800176D8, prio);
    if (result == (0)) {
        return -1;
    }
    enabled = OSDisableInterrupts();
    while ((1)) {
// Hardware or OS state can change asynchronously.
        state = ((volatile DVDCommandBlock *)block)->state;
        if (state == 0) {
            retVal = block->transferredSize;
            break;
        }
        if (state == -1) {
            retVal = -1;
            break;
        }
        if (state == 10) {
            retVal = -3;
            break;
        }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

void fn_800176D8(s32 result, DVDCommandBlock *block) {
    (void)result;
    (void)block;
    OSWakeupThread(&__DVDThreadQueue);
}

u32 DVDGetTransferredSize(DVDCommandBlock *block) {
    switch (block->state) {
    case -1:
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
        return block->transferredSize;
    case 2:
        return 0;
    case 1:
        return block->transferredSize + (block->currTransferSize - __DIRegs[6]);
    }
}

void fn_80017768(void) {
}
