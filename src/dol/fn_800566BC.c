#include "types.h"


/* --- dol/fn_800566BC.c --- */
extern u32 lbl_80188970[];
extern u32 lbl_80188974[65];

void fn_800566BC(u32 arg0, u32 arg1) {
    if (arg0 == 0) {
        lbl_80188970[0] = 0;
        lbl_80188974[0] = 0;
    } else {
        lbl_80188970[0] = arg0;
        lbl_80188974[0] = arg1;
    }
}
