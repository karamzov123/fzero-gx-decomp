#include "types.h"

extern u32 StopAtNextInt;
extern u32 lbl_801A6878;

s32 DVDLowBreak(void) {
    StopAtNextInt = 1;
    lbl_801A6878 = 1;
    return 1;
}
