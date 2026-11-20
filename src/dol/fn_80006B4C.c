#include "types.h"


/* --- dol/fn_80006B4C.c --- */
extern u32 DVDReadPrio(u32, u32, u32, u32, u32);

void fn_80006B4C(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    DVDReadPrio(arg0, arg1, arg2, arg3, 2);
}

/* --- dol/fn_80006B70.c --- */
extern u32 fn_80006BDC(u32, ...);
extern u32 DVDOpen(u32, u32);
extern u32 lbl_801220C0[];
extern u32 lbl_801220CC[];

void fn_80006B70(u32 arg0, u32 arg1) {
    fn_80006BDC((u32)&lbl_801220C0, arg0);
    fn_80006BDC((u32)&lbl_801220CC);
    *(u32 *)((u8 *)arg1 + 0) = 0;
    DVDOpen(arg0, (arg1 + 4));
}
