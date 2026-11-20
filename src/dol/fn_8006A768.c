#include "types.h"


/* --- dol/fn_8006A768.c --- */
typedef struct ARCEntry {
    u32 isDirAndStringOff;
    u32 parentOrPosition;
    u32 nextEntryOrLength;
} ARCEntry;

typedef struct ARCHandle {
    void *archiveStartAddr;
    void *FSTStart;
    void *fileStart;
    u32 entryNum;
    char *FSTStringStart;
    u32 FSTLength;
    u32 currDir;
} ARCHandle;

typedef struct ARCFileInfo {
    ARCHandle *handle;
    u32 startOffset;
    u32 length;
} ARCFileInfo;

#define entryIsDir(i) (((FSTEntries[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FSTEntries[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i) (FSTEntries[i].parentOrPosition)
#define nextDir(i) (FSTEntries[i].nextEntryOrLength)

static inline u32 myStrncpy(char *dest, char *src, u32 maxlen) {
    u32 i = maxlen;

    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }
    return (maxlen - i);
}

u32 fn_8006A768(ARCHandle *handle, u32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;
    ARCEntry *FSTEntries;

    FSTEntries = (ARCEntry *)handle->FSTStart;

    if (entry == 0) {
        return 0;
    }

    name = handle->FSTStringStart + stringOff(entry);
    loc = fn_8006A768(handle, parentDir(entry), path, maxlen);

    if (loc == maxlen) {
        return loc;
    }

    *(path + loc++) = '/';
    loc += myStrncpy(path + loc, name, maxlen - loc);
    return loc;
}

/* --- dol/fn_8006A8CC.c --- */
#define entryIsDir(i) (((FSTEntries[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FSTEntries[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i) (FSTEntries[i].parentOrPosition)
#define nextDir(i) (FSTEntries[i].nextEntryOrLength)

extern u32 fn_8006A768(ARCHandle *handle, u32 entry, char *path, u32 maxlen); /* entryToPath */

static inline BOOL ARCConvertEntrynumToPath(ARCHandle *handle, s32 entrynum, char *path, u32 maxlen) {
    u32 loc;
    ARCEntry *FSTEntries;

    FSTEntries = (ARCEntry *)handle->FSTStart;
    loc = fn_8006A768(handle, (u32)entrynum, path, maxlen);

    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }

    if (entryIsDir(entrynum)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }
        path[loc++] = '/';
    }

    path[loc] = '\0';
    return TRUE;
}

BOOL fn_8006A8CC(ARCHandle *handle, char *path, u32 maxlen) {
    return ARCConvertEntrynumToPath(handle, (s32)handle->currDir, path, maxlen);
}
