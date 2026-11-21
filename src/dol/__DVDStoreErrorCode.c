#include "types.h"
#include <types.h>
#include <dolphin/dvd.h>


/* --- dol/__DVDStoreErrorCode.c --- */
extern u32 ErrorCode2Num(u32);
extern u32 __OSLockSramEx(void);
extern u32 __OSUnlockSramEx(u32);

u32 __DVDStoreErrorCode(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2;
    v0 = (arg0 - 0x1230000);
    v2 = arg0;
    if (v0 == 17767) {
    v1 = 255;
    } else {
    if (v0 == 17768) {
    v1 = 254;
    } else {
    v1 = ((u32)v2 >> 24);
    v2 = (v2 & 0xFFFFFF);
    t0 = ErrorCode2Num(v2);
    v2 = t0;
    if (v1 >= 6) {
    v1 = 6;
    }
    v2 = (v2 & 0xFF);
    v1 = (v2 + (v1 * 30));
    }
    }
    t1 = __OSLockSramEx();
    v2 = t1;
    *(u8 *)((u8 *)v2 + 36) = v1;
    v2 = 1;
    t2 = __OSUnlockSramEx(v2);
    v2 = t2;
    return v2;
}
