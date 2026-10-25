#include "types.h"

extern u32 DVDReadPrio(u32, u32, u32, u32, u32);

void fn_80071CE8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    DVDReadPrio(arg0, arg1, arg2, arg3, 2);
}
