#include "types.h"


/* --- dol/fn_80023638.c --- */
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(void);
extern u32 lbl_801A6B78;

u32 fn_80023638(void) {
    u32 v0;
    OSDisableInterrupts();
    v0 = lbl_801A6B78;
    if (lbl_801A6B78 != 0) {
    v0--;
    }
    lbl_801A6B78 = 0;
    OSRestoreInterrupts();
    return v0;
}
