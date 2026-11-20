#include "types.h"


/* --- dol/fn_8002A744.c --- */
extern u16 lbl_801A6BC0;

u16 fn_8002A744(void) {
    return lbl_801A6BC0;
}

/* --- dol/fn_8002A74C.c --- */
u16 fn_8002A74C(u32 arg0) {
    u32 v0;
    u16 v1;
    v0 = (arg0 & 0xFFFF);
    v1 = lbl_801A6BC0;
    switch ((s32)v0) {
case 0: case 1: {

        lbl_801A6BC0 = arg0;
    
} break;
default: {

} break;
}
    return v1;
}
