#include "types.h"


/* --- rel/movie_module/fn_12_21864.c --- */
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

/* --- rel/movie_module/fn_12_21924.c --- */
/* --- rel/movie_module/fn_12_21924.c --- */
typedef struct MovieModule_u1 {
    u8 pad_0000[0x1c8c];
    int field_1c8c;
} MovieModule_u1;

extern int fn_12_2F1F0(MovieModule_u1 *module, int value);
extern int fn_12_21D50(MovieModule_u1 *module, int value);
extern void fn_12_2F200(MovieModule_u1 *module, int value, int flag);
extern int fn_12_2F1D0(MovieModule_u1 *module, int value);
extern int fn_12_21D30(MovieModule_u1 *module, int value);
extern void fn_12_2F1E0(MovieModule_u1 *module, int value, int flag);

int fn_12_21924(MovieModule_u1 *module) {
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

/* --- rel/movie_module/fn_12_219E8.c --- */
extern int fn_12_24990(void);
extern void fn_12_24A88(int, void *);

typedef int (*MovieCallback)(void *);

typedef struct MovieModule_u2 {
    u8 pad[0x1c84];
    struct {
        u8 pad[0x10];
        MovieCallback callback;
    } *vtable;
} MovieModule_u2;

int fn_12_219E8(MovieModule_u2 *self) {
    if (fn_12_24990() != 0) {
        fn_12_24A88(0, (void *)((0xff00 << 16) | 0x1a4));
        return 0;
    }
    if (fn_12_2D73C(self, 6) == 0) {
        return 0;
    }
    return self->vtable->callback(self);
}
