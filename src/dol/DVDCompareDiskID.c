#include "types.h"
#include <types.h>
#include <dolphin/dvd.h>


/* --- dol/__DVDStoreErrorCode.c --- */
extern u32 ErrorCode2Num(u32);
extern u32 __OSLockSramEx(void);
extern u32 __OSUnlockSramEx(u32);

u32 __DVDStoreErrorCode(u32 arg0);

/* --- dol/dvdidutils.c --- */
BOOL DVDCompareDiskID(DVDDiskID *id1, DVDDiskID *id2);

int strncmp(const char *, const char *, size_t);

BOOL DVDCompareDiskID(DVDDiskID *id1, DVDDiskID *id2) {
    if (id1->gameName[0] && id2->gameName[0] && strncmp(&id1->gameName[0], &id2->gameName[0], 4)) {
        return 0;
    }
    if (!id1->company[0] || !id2->company[0] || strncmp(&id1->company[0], &id2->company[0], 2)) {
        return 0;
    }
    if (id1->diskNumber != 0xff && id2->diskNumber != 0xff && id1->diskNumber != id2->diskNumber) {
        return 0;
    }
    if (id1->gameVersion != 0xff && id2->gameVersion != 0xff &&
        id1->gameVersion != id2->gameVersion) {
        return 0;
    }
    return 1;
}
