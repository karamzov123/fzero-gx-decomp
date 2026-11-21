#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"


/* --- dol/OSSetArenaLo.c --- */
extern u32 __OSArenaLo;

void OSSetArenaLo(u32 arg0) {
    __OSArenaLo = arg0;
}

/* --- dol/OSAllocFromArenaLo.c --- */
u32 OSAllocFromArenaLo(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;

    v0 = arg1 - 1;
    v1 = (~(v0 | v0));
    v2 = (v1 & (__OSArenaLo + v0));
    v3 = v2 + arg0;
    v3 = v3 + v0;
    __OSArenaLo = (v1 & v3);
    return v2;
}

/* --- dol/OSAllocFromArenaHi.c --- */
/* --- dol/OSAllocFromArenaHi.c --- */
extern u32 __OSArenaHi;

u32 OSAllocFromArenaHi(u32 size, u32 alignment) {
    u32 mask;
    u32 arena_hi;

    mask = ~(alignment - 1);
    arena_hi = __OSArenaHi;
    arena_hi &= mask;
    arena_hi = arena_hi - size;
    return __OSArenaHi = arena_hi & mask;
}
