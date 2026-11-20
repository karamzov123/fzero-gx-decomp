#include "types.h"


/* --- rel/movie_module/fn_12_21864.c --- */
extern int fn_12_2D73C(void *arg, int value);
extern int fn_12_2F210(void *arg, int a, int b, int c, int d);

int fn_12_21864(void *arg) {
    int temp;
    int result;

    if (fn_12_2D73C(arg, 6) == 0) {
        return 0;
    }

    temp = fn_12_2F210(arg, 3, 5, 0, 0);
    result = 0;
    if (temp != 0) {
        result = temp;
    }

    return result;
}

/* --- rel/movie_module/fn_12_218D0.c --- */
// fn_12_218D0: returns a constant.
int fn_12_218D0(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_218D8.c --- */
extern int fn_12_2D73C(void *self, int arg);

typedef struct MovieModule {
    u8 pad_0000[0x1c84];
    void *field_1c84;
} MovieModule;

int fn_12_218D8(MovieModule *self) {
    if (fn_12_2D73C(self, 6) == 0) {
        return 0;
    }
    self->field_1c84 = (u8 *)self + 0x28b8;
    return 0;
}
