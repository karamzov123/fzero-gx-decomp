#include "types.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_26664.c --- */
extern void fn_12_26534(void);

void fn_12_26664(void) {
    fn_12_26534();
}

/* --- rel/movie_module/fn_12_26684.c --- */
extern void fn_12_6DE8(void);

int fn_12_26684(void) {
    fn_12_6DE8();
    return 0;
}

/* --- rel/movie_module/fn_12_266A8.c --- */
extern int fn_12_24A88(void *arg0, int code);
extern int fn_12_6ECC(int arg0, void *arg1);
extern u8 lbl_12_bss_7E8C[6164];
extern u32 lbl_12_bss_7E88;

int fn_12_266A8(void) {
    int size = 0x168;
    int result;

    if (size > 0x200) {
        result = fn_12_24A88(0, 0xff000d0c);
    } else {
        result = 0;
    }
    if (result != 0) {
        for (;;) {
        }
    }
    if (fn_12_6ECC(0x20, lbl_12_bss_7E8C) != 0) {
        return fn_12_24A88(0, 0xff000d01);
    }
    lbl_12_bss_7E88 = 0;
    return 0;
}
