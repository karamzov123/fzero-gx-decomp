#include "types.h"

extern u32 __OSArenaHi;

u32 OSGetArenaHi(void) {
    return __OSArenaHi;
}
