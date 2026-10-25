#include "types.h"

extern u32 __PADSpec;
extern u32 lbl_801A64C4;
extern void SPEC0_MakeStatus(void);
extern void SPEC1_MakeStatus(void);
extern void SPEC2_MakeStatus(void);
extern u32 lbl_801A64C0;

void PADSetSpec(u32 arg0, u32 arg1) {
    __PADSpec = 0;
    switch ((s32)arg0) {
    case 0:
        lbl_801A64C4 = (u32)SPEC0_MakeStatus;
        break;
    case 1:
        lbl_801A64C4 = (u32)SPEC1_MakeStatus;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        lbl_801A64C4 = (u32)SPEC2_MakeStatus;
        break;
    default:
        break;
    }
    lbl_801A64C0 = arg0;
}
