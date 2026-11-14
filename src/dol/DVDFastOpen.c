#include <types.h>
#include <dolphin/dvd.h>

typedef struct DVDFileInfo DVDFileInfo;

typedef void (*DVDCallback)(s32 result, DVDFileInfo *fileInfo);

struct DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    DVDCallback callback;
};

typedef struct FSTEntry FSTEntry;

struct FSTEntry {
    unsigned int isDirAndStringOff;
    unsigned int parentOrPosition;
    unsigned int nextEntryOrLength;
};

extern FSTEntry *FstStart;

extern u32 MaxEntryNum;

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
