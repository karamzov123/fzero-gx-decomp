#include "types.h"

typedef struct MovieVtable MovieVtable;

typedef struct Movie Movie;

struct MovieVtable {
    char _pad[8];
    int (*callback)(Movie *, void *);
};

struct Movie {
    char _pad_0000[0x1c84];
    MovieVtable *vtable;
};

typedef struct MovieModule_u0 MovieModule_u0;

typedef void (*fn_12_21B70_MovieCallback)(MovieModule_u0 *, void *, void *);

struct MovieModule_u0 {
    u8 _pad[0x1c84];
    struct {
        u8 _pad0[4];
        fn_12_21B70_MovieCallback callback;
    } *ops;
};

typedef struct fn_12_21A64_MovieModule fn_12_21A64_MovieModule;

typedef void (*fn_12_21A64_MovieCallback)(fn_12_21A64_MovieModule *, void *);

struct fn_12_21A64_MovieModule {
    u8 _pad[0x1c84];
    struct {
        u8 _pad0[0xc];
        fn_12_21A64_MovieCallback callback;
    } *ops;
};

typedef struct MovieModule_u1 {
    u8 pad_0000[0x1c8c];
    int field_1c8c;
} MovieModule_u1;
extern int fn_12_24A88(int arg0, int arg1);
extern int fn_12_2D73C(void *arg, int value);
extern int fn_12_2F210(void *arg0, int arg1, int arg2, int arg3, int arg4);
extern int fn_12_2F1F0(MovieModule_u1 *module, int value);
extern int fn_12_21D50(MovieModule_u1 *module, int index);
extern void fn_12_2F200(MovieModule_u1 *module, int value, int flag);
extern int fn_12_2F1D0(MovieModule_u1 *module, int value);
extern int fn_12_21D30(MovieModule_u1 *module, int value);
extern void fn_12_2F1E0(MovieModule_u1 *module, int value, int flag);
extern s32 fn_12_24990();

/* fzgx:begin fn_12_2166C */
/* --- rel/movie_module/fn_12_2166C.c --- */
// fn_12_2166C: returns a constant.
int fn_12_2166C(void) {
    return 0;
}
/* fzgx:end fn_12_2166C */

/* fzgx:begin fn_12_21674 */
/* --- rel/movie_module/fn_12_21674.c --- */

void fn_12_21674(void *arg0) {
    fn_12_24A88( (int)(void *)(arg0), (s32)0xff000a01);
}
/* fzgx:end fn_12_21674 */

/* fzgx:begin fn_12_2169C */
/* --- rel/movie_module/fn_12_21674.c --- */

/* --- rel/movie_module/fn_12_2169C.c --- */
/* --- rel/movie_module/fn_12_2169C.c --- */

void fn_12_2169C(void *arg0) {
    fn_12_24A88( (int)(void *)(arg0), 0xff000a01);
}
/* fzgx:end fn_12_2169C */

/* fzgx:begin fn_12_216C4 */
/* --- rel/movie_module/fn_12_21674.c --- */

/* --- rel/movie_module/fn_12_216C4.c --- */
void fn_12_216C4(void *arg0) {
    fn_12_24A88( (int)(void *)(arg0), 0xFF000A01);
}
/* fzgx:end fn_12_216C4 */

/* fzgx:begin fn_12_216EC */
/* --- rel/movie_module/fn_12_216EC.c --- */

int fn_12_216EC(int arg0) {
    return fn_12_24A88(arg0, 0xFF000A01);
}
/* fzgx:end fn_12_216EC */

/* fzgx:begin fn_12_21714 */
/* --- rel/movie_module/fn_12_21714.c --- */

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
/* fzgx:end fn_12_21714 */

/* fzgx:begin fn_12_2178C */
/* --- rel/movie_module/fn_12_21714.c --- */

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
/* fzgx:end fn_12_2178C */

/* fzgx:begin fn_12_217F8 */

int fn_12_217F8(int arg0) {
    int result;
    int value;

    if (fn_12_2D73C( (void *)(int)(arg0), 6) == 0) {
        return 0;
    }

    value = fn_12_2F210( (void *)(int)(arg0), 3, 6, 0, 0);
    result = 0;
    if (value != 0) {
        result = value;
    }
    return result;
}
/* fzgx:end fn_12_217F8 */

/* fzgx:begin fn_12_21864 */
/* --- rel/movie_module/fn_12_21864.c --- */
/* --- rel/movie_module/fn_12_21864.c --- */

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
/* fzgx:end fn_12_21864 */

/* fzgx:begin fn_12_218D0 */
/* --- rel/movie_module/fn_12_218D0.c --- */
// fn_12_218D0: returns a constant.
int fn_12_218D0(void) {
    return 0;
}
/* fzgx:end fn_12_218D0 */

/* fzgx:begin fn_12_218D8 */
/* --- rel/movie_module/fn_12_21864.c --- */
/* --- rel/movie_module/fn_12_21864.c --- */

/* --- rel/movie_module/fn_12_218D8.c --- */

typedef struct fn_12_218D8_MovieModule {
    u8 pad_0000[0x1c84];
    void *field_1c84;
} fn_12_218D8_MovieModule;

int fn_12_218D8(fn_12_218D8_MovieModule *self) {
    if (fn_12_2D73C(self, 6) == 0) {
        return 0;
    }
    self->field_1c84 = (u8 *)self + 0x28b8;
    return 0;
}
/* fzgx:end fn_12_218D8 */

/* fzgx:begin fn_12_21924 */
/* --- rel/movie_module/fn_12_21864.c --- */
/* --- rel/movie_module/fn_12_21864.c --- */

/* --- rel/movie_module/fn_12_21924.c --- */
/* --- rel/movie_module/fn_12_21924.c --- */


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
/* fzgx:end fn_12_21924 */

/* fzgx:begin fn_12_219D8 */
/* --- rel/movie_module/fn_12_219D8.c --- */
// fn_12_219D8: returns a constant.
int fn_12_219D8(void) {
    return 0;
}
/* fzgx:end fn_12_219D8 */

/* fzgx:begin fn_12_219E0 */
/* --- rel/movie_module/fn_12_219E0.c --- */
// fn_12_219E0: returns a constant.
int fn_12_219E0(void) {
    return 0;
}
/* fzgx:end fn_12_219E0 */

/* fzgx:begin fn_12_219E8 */
/* --- rel/movie_module/fn_12_21864.c --- */
/* --- rel/movie_module/fn_12_21864.c --- */

/* --- rel/movie_module/fn_12_219E8.c --- */

typedef int (*fn_12_219E8_MovieCallback)(void *);

typedef struct MovieModule_u2 {
    u8 pad[0x1c84];
    struct {
        u8 pad[0x10];
        fn_12_219E8_MovieCallback callback;
    } *vtable;
} MovieModule_u2;

int fn_12_219E8(MovieModule_u2 *self) {
    if (fn_12_24990() != 0) {
        fn_12_24A88(0, (int)((void *)((0xff00 << 16) | 0x1a4)));
        return 0;
    }
    if (fn_12_2D73C(self, 6) == 0) {
        return 0;
    }
    return self->vtable->callback(self);
}
/* fzgx:end fn_12_219E8 */

/* fzgx:begin fn_12_21A64 */

void fn_12_21A64(fn_12_21A64_MovieModule *module, void *arg) {
    if (fn_12_24990( (u32)(fn_12_21A64_MovieModule *)(module)) != 0) {
        fn_12_24A88(0, 0xff0001a3);
    } else if (fn_12_2D73C( (void *)(fn_12_21A64_MovieModule *)(module), 6) != 0) {
        module->ops->callback(module, arg);
    }
}
/* fzgx:end fn_12_21A64 */

/* fzgx:begin fn_12_21AE4 */

int fn_12_21AE4(Movie *movie, void *arg) {
    if (fn_12_24990() != 0) {
        fn_12_24A88(0, 0xff0001a2);
        return 0;
    }

    if (fn_12_2D73C( (void *)(Movie *)(movie), 6) == 0) {
        return 0;
    }

    return movie->vtable->callback(movie, arg);
}
/* fzgx:end fn_12_21AE4 */

/* fzgx:begin fn_12_21B70 */
/* --- rel/movie_module/fn_12_21B70.c --- */
/* --- rel/movie_module/fn_12_21B70.c --- */

void fn_12_21B70(MovieModule_u0 *module, void *arg0, void *arg1) {
    if (fn_12_24990( (u32)(MovieModule_u0 *)(module)) != 0) {
        fn_12_24A88(0, 0xff0001a1);
    } else if (fn_12_2D73C( (void *)(MovieModule_u0 *)(module), 6) != 0) {
        module->ops->callback(module, arg0, arg1);
    }
}
/* fzgx:end fn_12_21B70 */
