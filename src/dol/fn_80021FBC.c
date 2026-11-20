#include "types.h"


/* --- dol/fn_80021FBC.c --- */
extern u32 AIStopDMA(void);
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 OSSleepThread(u32);
extern u32 fn_80028E48(u32);
extern u32 lbl_80160C80[];
extern u32 lbl_801A6B20;
extern u32 lbl_801A6B30;

void fn_80021FBC(void) {
    u32 v0;
    u32 t0;
    t0 = OSDisableInterrupts();
    lbl_801A6B20 = 0;
    v0 = (t0 + 0);
    fn_80028E48((u32)&lbl_80160C80);
    OSSleepThread((u32)&lbl_801A6B30);
    AIStopDMA();
    OSRestoreInterrupts(v0);
}

/* --- dol/fn_80022014.c --- */
/* --- dol/fn_80022014.c --- */

void fn_80022014(u32 arg0) {
    lbl_801A6B20 = arg0;
}

/* --- dol/fn_8002201C.c --- */
extern u32 lbl_80164D20[];

u32 fn_8002201C(void) {
    return (u32)&lbl_80164D20;
}
