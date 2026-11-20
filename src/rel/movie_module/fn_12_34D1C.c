#include "types.h"


/* --- rel/movie_module/fn_12_34D1C.c --- */
extern u32 lbl_12_bss_1B9A0;
extern u32 fn_80059428(u32, u32, u32);

void fn_12_34D1C(u32 arg0, u32 arg1) {
    lbl_12_bss_1B9A0 = fn_80059428(5, arg0, arg1);
}

/* --- rel/movie_module/fn_12_34D50.c --- */
extern struct fn_12_34D50_lbl_12_bss_1B9A4 lbl_12_bss_1B9A4;
extern u32 fn_800592E0(u32, u32);

struct fn_12_34D50_lbl_12_bss_1B9A4 {
    u32 unk_0;
};

void fn_12_34D50(void) {
    fn_800592E0(6, lbl_12_bss_1B9A4.unk_0);
}
