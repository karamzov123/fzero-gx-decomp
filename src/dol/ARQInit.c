#include "types.h"

extern u32 OSRegisterVersion(u32);
extern u32 fn_8001E7E4(u32);
extern u32 lbl_801A64E0;
extern u32 lbl_801A6A00;
extern u32 lbl_801A6A08;
extern u32 lbl_801A6A10;
extern u32 lbl_801A6A14;
extern u32 lbl_801A6A18;
extern u32 lbl_801A6A1C;
extern u32 lbl_801A6A20;
extern u32 lbl_801A6A24;
extern void __ARQInterruptServiceRoutine(void);

void ARQInit(void) {
    if ((s32)lbl_801A6A24 != 1) {
    OSRegisterVersion(lbl_801A64E0);
    lbl_801A6A08 = 0;
    lbl_801A6A00 = 0;
    lbl_801A6A20 = 4096;
    fn_8001E7E4((u32)__ARQInterruptServiceRoutine);
    lbl_801A6A10 = 0;
    lbl_801A6A14 = 0;
    lbl_801A6A18 = 0;
    lbl_801A6A1C = 0;
    lbl_801A6A24 = 1;
    }
}
