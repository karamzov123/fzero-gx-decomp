#include "types.h"


/* --- dol/OSGetArenaHi.c --- */
extern u32 __OSArenaHi;

u32 OSGetArenaHi(void) {
    return __OSArenaHi;
}

/* --- dol/OSGetArenaLo.c --- */
extern void* __OSArenaLo;

void* OSGetArenaLo(void) {
    return __OSArenaLo;
}

/* --- dol/OSSetArenaHi.c --- */
void OSSetArenaHi(u32 arg0) {
    __OSArenaHi = arg0;
}
