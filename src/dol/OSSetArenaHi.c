#include "types.h"

extern u32 __OSArenaHi;

void OSSetArenaHi(u32 arg0) {
    __OSArenaHi = arg0;
}
