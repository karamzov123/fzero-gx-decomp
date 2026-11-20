#include "types.h"


/* --- dol/fn_8004B7A0.c --- */
extern u32 lbl_8017D708[];
extern u32 memset(u32, u32, u32);

s32 fn_8004B7A0(void) {
    memset((u32)&lbl_8017D708, 0, 3680);
    return 1;
}

/* --- dol/fn_8004B7D4.c --- */
extern u32 fn_80046F7C(void);

void fn_8004B7D4(void) {
    fn_80046F7C();
}
