#include "types.h"

extern void* __OSArenaLo;

void* OSGetArenaLo(void) {
    return __OSArenaLo;
}
