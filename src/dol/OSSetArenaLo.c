#include "types.h"

extern u32 __OSArenaLo;

void OSSetArenaLo(u32 arg0) {
    __OSArenaLo = arg0;
}
