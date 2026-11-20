#include "types.h"

extern u32 lbl_801A6B14;
extern u64 lbl_801A6B18;
extern u64 OSGetTime(void);
extern void fn_80021930(u32);
extern u8 lbl_80160C80[16544];
extern void fn_80028E88(void *);

void fn_80021AB8(void) {

    if (lbl_801A6B14 == 0) {
        lbl_801A6B18 = OSGetTime();
    }

    if (lbl_801A6B14 == 1) {
        lbl_801A6B14 = 0;
        fn_80021930(0);
    } else {
        lbl_801A6B14 = 2;
        fn_80028E88(&lbl_80160C80);
    }
}
