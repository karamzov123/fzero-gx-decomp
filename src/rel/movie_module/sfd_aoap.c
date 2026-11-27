#include "types.h"

/* fzgx:begin fn_12_2166C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2166C.c --- */
// fn_12_2166C: returns a constant.
int fn_12_2166C(void) {
    return 0;
}
/* fzgx:end fn_12_2166C */

/* fzgx:begin fn_12_21674 noprologue */

/* --- rel/movie_module/fn_12_21674.c --- */
extern void fn_12_24A88(void *arg0, s32 arg1);

void fn_12_21674(void *arg0) {
    fn_12_24A88(arg0, (s32)0xff000a01);
}
/* fzgx:end fn_12_21674 */

/* fzgx:begin fn_12_2169C noprologue */

/* --- rel/movie_module/fn_12_2169C.c --- */
/* --- rel/movie_module/fn_12_2169C.c --- */

void fn_12_2169C(void *arg0) {
    fn_12_24A88(arg0, 0xff000a01);
}
/* fzgx:end fn_12_2169C */

/* fzgx:begin fn_12_216C4 noprologue */

/* --- rel/movie_module/fn_12_216C4.c --- */
void fn_12_216C4(void *arg0) {
    fn_12_24A88(arg0, 0xFF000A01);
}
/* fzgx:end fn_12_216C4 */

/* fzgx:begin fn_12_216EC noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_216EC.c --- */
extern int fn_12_24A88(int arg0, int arg1);

int fn_12_216EC(int arg0) {
    return fn_12_24A88(arg0, 0xFF000A01);
}
/* fzgx:end fn_12_216EC */

/* fzgx:begin fn_12_21714 noprologue */

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
/* fzgx:end fn_12_21714 */

/* fzgx:begin fn_12_2178C noprologue */

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

/* fzgx:begin fn_12_217F8 noprologue */
#include "types.h"

extern int fn_12_2D73C(int arg0, int arg1);
extern int fn_12_2F210(int arg0, int arg1, int arg2, int arg3, int arg4);

int fn_12_217F8(int arg0) {
    int result;
    int value;

    if (fn_12_2D73C(arg0, 6) == 0) {
        return 0;
    }

    value = fn_12_2F210(arg0, 3, 6, 0, 0);
    result = 0;
    if (value != 0) {
        result = value;
    }
    return result;
}
/* fzgx:end fn_12_217F8 */

/* fzgx:begin fn_12_21864 noprologue */
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
/* fzgx:end fn_12_21864 */

/* fzgx:begin fn_12_218D0 noprologue */

/* --- rel/movie_module/fn_12_218D0.c --- */
// fn_12_218D0: returns a constant.
int fn_12_218D0(void) {
    return 0;
}
/* fzgx:end fn_12_218D0 */

/* fzgx:begin fn_12_218D8 noprologue */

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
/* fzgx:end fn_12_218D8 */

/* fzgx:begin fn_12_21924 noprologue */

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
/* fzgx:end fn_12_21924 */

/* fzgx:begin fn_12_219D8 noprologue */

/* --- rel/movie_module/fn_12_219D8.c --- */
// fn_12_219D8: returns a constant.
int fn_12_219D8(void) {
    return 0;
}
/* fzgx:end fn_12_219D8 */

/* fzgx:begin fn_12_219E0 noprologue */

/* --- rel/movie_module/fn_12_219E0.c --- */
// fn_12_219E0: returns a constant.
int fn_12_219E0(void) {
    return 0;
}
/* fzgx:end fn_12_219E0 */

/* fzgx:begin fn_12_219E8 noprologue */

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
/* fzgx:end fn_12_219E8 */

/* fzgx:begin fn_12_21A64 noprologue */
#include "types.h"

typedef struct MovieModule MovieModule;
typedef void (*MovieCallback)(MovieModule *, void *);

struct MovieModule {
    u8 _pad[0x1c84];
    struct {
        u8 _pad0[0xc];
        MovieCallback callback;
    } *ops;
};

extern int fn_12_24990(MovieModule *);
extern void fn_12_24A88(int, u32);
extern int fn_12_2D73C(MovieModule *, int);

void fn_12_21A64(MovieModule *module, void *arg) {
    if (fn_12_24990(module) != 0) {
        fn_12_24A88(0, 0xff0001a3);
    } else if (fn_12_2D73C(module, 6) != 0) {
        module->ops->callback(module, arg);
    }
}
/* fzgx:end fn_12_21A64 */

/* fzgx:begin fn_12_21AE4 noprologue */
#include "types.h"

typedef struct Movie Movie;
typedef struct MovieVtable MovieVtable;

struct MovieVtable {
    char _pad[8];
    int (*callback)(Movie *, void *);
};

struct Movie {
    char _pad_0000[0x1c84];
    MovieVtable *vtable;
};

extern int fn_12_24990(void);
extern void fn_12_24A88(int, int);
extern int fn_12_2D73C(Movie *, int);

int fn_12_21AE4(Movie *movie, void *arg) {
    if (fn_12_24990() != 0) {
        fn_12_24A88(0, 0xff0001a2);
        return 0;
    }

    if (fn_12_2D73C(movie, 6) == 0) {
        return 0;
    }

    return movie->vtable->callback(movie, arg);
}
/* fzgx:end fn_12_21AE4 */

/* fzgx:begin fn_12_21B70 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_21B70.c --- */
/* --- rel/movie_module/fn_12_21B70.c --- */
typedef struct MovieModule_u0 MovieModule_u0;
typedef void (*MovieCallback)(MovieModule_u0 *, void *, void *);

struct MovieModule_u0 {
    u8 _pad[0x1c84];
    struct {
        u8 _pad0[4];
        MovieCallback callback;
    } *ops;
};

extern int fn_12_24990(MovieModule_u0 *);
extern void fn_12_24A88(int, u32);
extern int fn_12_2D73C(MovieModule_u0 *, int);

void fn_12_21B70(MovieModule_u0 *module, void *arg0, void *arg1) {
    if (fn_12_24990(module) != 0) {
        fn_12_24A88(0, 0xff0001a1);
    } else if (fn_12_2D73C(module, 6) != 0) {
        module->ops->callback(module, arg0, arg1);
    }
}
/* fzgx:end fn_12_21B70 */
