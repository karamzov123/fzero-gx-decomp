#include "types.h"


/* --- rel/movie_module/fn_12_34D80.c --- */
extern u32 lbl_12_bss_1B9A4;
extern u32 fn_80059428(u32, u32, u32);

void fn_12_34D80(u32 arg0, u32 arg1) {
    lbl_12_bss_1B9A4 = fn_80059428(6, arg0, arg1);
}

/* --- rel/movie_module/fn_12_34DB4.c --- */
extern struct fn_12_34DB4_lbl_12_bss_1B9A8 lbl_12_bss_1B9A8;
extern u32 fn_800592E0(u32, u32);

struct fn_12_34DB4_lbl_12_bss_1B9A8 {
    u32 unk_0;
};

void fn_12_34DB4(void) {
    fn_800592E0(2, lbl_12_bss_1B9A8.unk_0);
}
