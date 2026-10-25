#include "types.h"

extern u16 lbl_801A6CC4;
extern u16 lbl_801A6CC6;
extern u32 VISetBlack(u32);
extern u32 GXDrawDone(void);
extern u32 fn_80034444(u32);
extern u32 fn_8007001C(void);
extern u32 fn_80070100(void);
extern u32 lbl_801A6CCC;
extern u32 lbl_801A6CD0;
extern u32 lbl_801A6CD4;
extern u8 lbl_801A6CB4;
extern void fn_800700F4(void);

void fn_8006FCB4(void) {
    VISetBlack(0);
    fn_80034444((u32)fn_800700F4);
    lbl_801A6CB4 = 0;
    GXDrawDone();
    lbl_801A6CD0 = 1;
    lbl_801A6CCC = -1;
    lbl_801A6CC6 = 0;
    lbl_801A6CC4 = 0;
    fn_80070100();
    fn_8007001C();
    lbl_801A6CD4 = 0;
}
