#include "types.h"

extern u32 Si[];

s32 SIBusy(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)Si[0] != -1) {
    v0 = 1;
    return v0;
    }
    v0 = 0;
    return v0;
}
