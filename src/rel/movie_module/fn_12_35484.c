#include "types.h"


/* --- rel/movie_module/fn_12_35484.c --- */
typedef struct Movie Movie;
typedef void (*MovieCallback)(Movie *);

typedef struct MovieVTable {
    u8 pad_0c[0x0c];
    MovieCallback callback;
} MovieVTable;

struct Movie {
    MovieVTable *vtable;
};

typedef struct MovieModuleState {
    u8 pad_e8[0xe8];
    Movie *movie;
} MovieModuleState;

void fn_12_35484(MovieModuleState *self) {
    Movie *movie = self->movie;

    if (movie != 0) {
        movie->vtable->callback(movie);
    }
}

/* --- rel/movie_module/fn_12_354BC.c --- */
typedef struct MovieModuleState_u1 {
    u8 pad_2c[0x2c];
    s32 state;
    u8 pad_30[0xbc];
    void *resource;
    void *resource_end;
} MovieModuleState_u1;

extern u8 lbl_12_rodata_17D0[252];
extern void *fn_80058498(void *resource, void *resource_end, s32 arg2);
extern void MWSFSVM_Error(u8 *message, ...);
extern void mwSfdDestroy(MovieModuleState_u1 *self);

u32 fn_12_354BC(MovieModuleState_u1 *self) {
    s32 valid;

    if (self->state == 0 || self->state == 0x101) {
        valid = 1;
    } else {
        valid = 0;
    }

    if (valid == 0) {
        return 0;
    }

    if (fn_80058498(self->resource, self->resource_end, 0) == 0) {
        MWSFSVM_Error(lbl_12_rodata_17D0);
        mwSfdDestroy(self);
        return 0;
    }
}

/* --- rel/movie_module/fn_12_35548.c --- */
typedef struct MovieModuleState_u2 {
    u8 pad_20[0x20];
    s32 state;
} MovieModuleState_u2;

u32 fn_12_35548(MovieModuleState_u2 *self) {
    if (self->state == 0 || self->state == 0x101) {
        return 1;
    }
    return 0;
}
