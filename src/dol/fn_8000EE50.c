#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSReset.h>


/* --- dol/fn_8000EE50.c --- */
/* --- dol/fn_8000EE50.c --- */
extern u32 lbl_801A67C0;
extern u32 lbl_801A67C4;

void fn_8000EE50(u32 arg0, u32 arg1) {
    lbl_801A67C0 = arg0;
    lbl_801A67C4 = arg1;
}
