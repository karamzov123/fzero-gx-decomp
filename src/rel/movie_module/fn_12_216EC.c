#include "types.h"


/* --- rel/movie_module/fn_12_216EC.c --- */
extern int fn_12_24A88(int arg0, int arg1);

int fn_12_216EC(int arg0) {
    return fn_12_24A88(arg0, 0xFF000A01);
}

/* --- rel/movie_module/fn_12_21714.c --- */
extern int fn_12_2D73C(void *arg0, int arg1);
extern int fn_12_2F210(void *arg0, int arg1, int arg2, int arg3, int arg4);

int fn_12_21714(void *arg0, int arg1) {
    int result;
    int value;

    if (!fn_12_2D73C(arg0, 6)) {
        return 0;
    }

    value = fn_12_2F210(arg0, 3, 8, arg1, 0);
    result = 0;
    if (value) {
        result = value;
    }
    return result;
}

/* --- rel/movie_module/fn_12_2178C.c --- */
int fn_12_2178C(void *arg0) {
    int result;
    int value;

    if (!fn_12_2D73C(arg0, 6)) {
        return 0;
    }

    value = fn_12_2F210(arg0, 3, 7, 0, 0);
    result = 0;
    if (value) {
        result = value;
    }
    return result;
}
