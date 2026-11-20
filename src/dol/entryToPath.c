#include <types.h>


/* --- dol/entryToPath.c --- */
typedef struct FSTEntry FSTEntry;

struct FSTEntry {
    unsigned int isDirAndStringOff;
    unsigned int parentOrPosition;
    unsigned int nextEntryOrLength;
};

extern FSTEntry *FstStart;

extern char *FstStringStart;

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

/* --- dol/DVDGetCurrentDir.c --- */
extern u32 lbl_801A68B0;

u32 entryToPath(u32 entry, char *path, u32 maxlen);

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

/* --- dol/DVDChangeDir.c --- */
s32 DVDConvertPathToEntrynum(const char *pathPtr);



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
