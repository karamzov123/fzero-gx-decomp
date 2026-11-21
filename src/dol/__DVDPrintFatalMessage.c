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

BOOL DVDCompareDiskID(DVDDiskID *id1, DVDDiskID *id2);

/* --- dol/__DVDPrintFatalMessage.c --- */
extern u32 lbl_801A6908;

void __DVDPrintFatalMessage(void) {
    if (lbl_801A6908 != 0) {
        ((void (*)(void))lbl_801A6908)();
    }
}
