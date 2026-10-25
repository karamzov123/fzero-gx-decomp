#include "types.h"

extern u32 StopAtNextInt_801A6858;
extern u32 lbl_801A6878;

s32 DVDLowBreak(void) {
    StopAtNextInt_801A6858 = 1;
    lbl_801A6878 = 1;
    return 1;
}
