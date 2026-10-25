#include <types.h>

typedef struct FSTEntry FSTEntry;

struct FSTEntry {
    unsigned int isDirAndStringOff;
    unsigned int parentOrPosition;
    unsigned int nextEntryOrLength;
};

s32 DVDConvertPathToEntrynum(const char *pathPtr);

extern FSTEntry *FstStart;

extern u32 lbl_801A68B0;

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
