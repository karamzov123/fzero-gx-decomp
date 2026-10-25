#include "types.h"

extern u32 lbl_801A684C;
extern int OSGetConsoleType(void);
extern u32 lbl_801A6848;
extern u32 lbl_801A6840;
extern u32 lbl_801A6844;

int InitializeUART(void) {
    if (lbl_801A684C == 0xA5FF005A) {
        return 0;
    }

    if ((OSGetConsoleType() & 0x10000000) == 0) {
        lbl_801A6848 = 0;
        return 2;
    }

    lbl_801A6848 = 0xA5FF005A;
    lbl_801A6840 = 0;
    lbl_801A6844 = 1;
    return 0;
}
