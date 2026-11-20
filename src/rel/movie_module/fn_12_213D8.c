#include "types.h"


/* --- rel/movie_module/fn_12_213D8.c --- */
extern void fn_12_2105C(void);

void fn_12_213D8(void) {
    fn_12_2105C();
}

/* --- rel/movie_module/fn_12_213F8.c --- */
extern void fn_80047834(void);
extern void ADXT_Finish(void);

int fn_12_213F8(void) {
    fn_80047834();
    ADXT_Finish();
    return 0;
}

/* --- rel/movie_module/fn_12_21420.c --- */
extern void fn_800411F4(void);
extern void fn_8004784C(void);
extern u32 lbl_12_bss_6990[8];
extern void fn_12_33428(u32 *, int, int);

int fn_12_21420(void) {
    fn_800411F4();
    fn_8004784C();
    fn_12_33428(lbl_12_bss_6990, 0, 7);
    return 0;
}
