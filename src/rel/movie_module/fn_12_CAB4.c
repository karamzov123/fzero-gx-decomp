#include "types.h"

/* --- rel/movie_module/fn_12_CAB4.c --- */
extern u32 lbl_12_bss_5280;

s32 fn_12_CAB4(u32 arg0) {
    u32 v0;
    u32 v1;
    lbl_12_bss_5280 = arg0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = -1;
    return v0;
    }
    v1 = *(u32 *)((u8 *)v0 + 392);
    v0 = (v1 - 2);
    v0 = ((s32)(v0 | (2 - v1)) >> 31);
    return v0;
}
