#include "types.h"

extern u32 __OSArenaLo;

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

