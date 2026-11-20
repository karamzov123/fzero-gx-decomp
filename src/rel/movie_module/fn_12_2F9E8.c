#include "types.h"


/* --- rel/movie_module/fn_12_2F9E8.c --- */
typedef struct MovieModule {
    u8 pad_0000[0x1cd0];
    int movie_state;
} MovieModule;

extern int fn_12_2F1D0(MovieModule *, int);
extern int fn_12_21D30(MovieModule *, int);
extern void fn_12_2F1E0(MovieModule *, int, int);
extern int fn_12_2F1F0(MovieModule *, int);
extern int fn_12_21D50(MovieModule *, int);
extern void fn_12_2F200(MovieModule *, int, int);

int fn_12_2F9E8(MovieModule *module) {
    if (fn_12_2F1D0(module, 8) != 1 &&
        fn_12_21D30(module, module->movie_state) == 1) {
        fn_12_2F1E0(module, 8, 1);
    }

    if (fn_12_2F1F0(module, 8) != 1 &&
        fn_12_21D50(module, module->movie_state) == 1) {
        fn_12_2F200(module, 8, 1);
    }

    return 0;
}

/* --- rel/movie_module/fn_12_2FA80.c --- */
// fn_12_2FA80: returns a constant.
int fn_12_2FA80(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FA88.c --- */
// fn_12_2FA88: returns a constant.
int fn_12_2FA88(void) {
    return 0;
}
