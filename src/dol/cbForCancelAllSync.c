#include "types.h"

extern u32 OSWakeupThread(u32);
extern u32 lbl_801A6B28;
extern u32 lbl_801A6B30;

void cbForCancelAllSync(void) {
    lbl_801A6B28 = 1;
    OSWakeupThread((u32)&lbl_801A6B30);
}
