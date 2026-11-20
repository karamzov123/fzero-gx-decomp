#include "types.h"


/* --- rel/movie_module/fn_12_24D68.c --- */
int fn_12_24D68(int unused, int value) {
    return value == 0x29d8;
}

/* --- rel/movie_module/fn_12_24D78.c --- */
// fn_12_24D78: returns a constant.
int fn_12_24D78(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_24D80.c --- */
extern void fn_12_24A88(int arg0, int arg1);

void fn_12_24D80(int arg0) {
    fn_12_24A88(arg0, 0xff000501);
}
