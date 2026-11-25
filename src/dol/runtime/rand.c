#include "types.h"

static u32 lbl_801A6638 = 1;

int rand(void) {
    lbl_801A6638 = lbl_801A6638 * 1103515245 + 12345;
    return (lbl_801A6638 >> 16) & 0x7FFF;
}
