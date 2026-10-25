#include "types.h"

extern u32 __OSArenaHi_801A6790;

u32 OSAllocFromArenaHi(u32 size, u32 alignment) {
    u32 mask;
    u32 arena_hi;

    mask = ~(alignment - 1);
    arena_hi = __OSArenaHi_801A6790;
    arena_hi &= mask;
    arena_hi = arena_hi - size;
    return __OSArenaHi_801A6790 = arena_hi & mask;
}
