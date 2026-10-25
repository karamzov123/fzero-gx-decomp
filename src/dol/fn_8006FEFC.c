#include "types.h"

extern u32 fn_8001BE6C(void);
extern u32 lbl_801A6CCC;
extern u32 lbl_801A6CD0;
extern u32 *lbl_801A6D30;
extern void VISetNextFrameBuffer(u32 value);
extern void VIFlush(void);
extern void VIWaitForRetrace(void);
extern u32 lbl_801A6CE0;

void fn_8006FEFC(void) {
    while (fn_8001BE6C() - lbl_801A6CCC < lbl_801A6CD0 - 1) {
    }

    VISetNextFrameBuffer(*lbl_801A6D30);
    VIFlush();
    VIWaitForRetrace();

    if ((lbl_801A6CE0 & 0x20) == 0) {
        lbl_801A6D30[0] = lbl_801A6D30[1 + lbl_801A6D30[4]];
        lbl_801A6D30[4] ^= 1;
    }

    lbl_801A6D30[3]++;
}
