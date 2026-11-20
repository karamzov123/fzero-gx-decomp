#include "types.h"


/* --- dol/__DBIsExceptionMarked.c --- */
extern struct __DBIsExceptionMarked___DBInterface_T *__DBInterface;

struct __DBIsExceptionMarked___DBInterface_T {
    u8 pad_0[0x4];
    u32 unk_4;
};

u32 __DBIsExceptionMarked(u32 arg0) {
    return (__DBInterface->unk_4 & (1 << (arg0 & 0xFF)));
}

/* --- dol/DBPrintf.c --- */
void DBPrintf(const char *format, ...) {
}
