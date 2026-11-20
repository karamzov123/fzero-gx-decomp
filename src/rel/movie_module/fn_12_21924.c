#include "types.h"


/* --- rel/movie_module/fn_12_21924.c --- */
typedef struct MovieModule {
    u8 pad_0000[0x1c8c];
    int field_1c8c;
} MovieModule;

extern int fn_12_2D73C(MovieModule *module, int value);
extern int fn_12_2F1F0(MovieModule *module, int value);
extern int fn_12_21D50(MovieModule *module, int value);
extern void fn_12_2F200(MovieModule *module, int value, int flag);
extern int fn_12_2F1D0(MovieModule *module, int value);
extern int fn_12_21D30(MovieModule *module, int value);
extern void fn_12_2F1E0(MovieModule *module, int value, int flag);

int fn_12_21924(MovieModule *module) {
    if (fn_12_2D73C(module, 6) == 0) {
        return 0;
    }

    if (fn_12_2F1F0(module, 7) != 1) {
        if (fn_12_21D50(module, module->field_1c8c) == 1) {
            fn_12_2F200(module, 7, 1);
        }
    }

    if (fn_12_2F1D0(module, 7) != 1) {
        if (fn_12_21D30(module, module->field_1c8c) == 1) {
            fn_12_2F1E0(module, 7, 1);
        }
    }

    return 0;
}

/* --- rel/movie_module/fn_12_219D8.c --- */
// fn_12_219D8: returns a constant.
int fn_12_219D8(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_219E0.c --- */
// fn_12_219E0: returns a constant.
int fn_12_219E0(void) {
    return 0;
}
