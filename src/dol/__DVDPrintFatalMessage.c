#include "types.h"

extern u32 lbl_801A6908;

void __DVDPrintFatalMessage(void) {
    if (lbl_801A6908 != 0) {
        ((void (*)(void))lbl_801A6908)();
    }
}
