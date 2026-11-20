#include "types.h"


/* --- rel/movie_module/fn_12_3530C.c --- */
typedef struct MovieModuleState {
    u8 pad_a8[0xa8];
    void *movie_resource;
    u8 pad_ac[0x3c];
    u8 *movie_data;
    u8 pad_ec[0x18];
    u32 value_104;
    u32 value_108;
} MovieModuleState;

extern void mwsftag_GetAinfFromSj(MovieModuleState *self);
extern void fn_12_818(void *resource, u32 value0, u32 value1);
extern void *SJ_SearchTag(void *input, const f64 *constant, u8 *table, void *output);
extern const f64 lbl_12_rodata_1778;
extern u8 lbl_12_rodata_1780[64];

void fn_12_3530C(MovieModuleState *self) {
    u32 output[2];
    u32 input[2];
    void *resource;

    if (self->movie_data != 0) {
        mwsftag_GetAinfFromSj(self);
        resource = self->movie_resource;
        if (self->value_104 == 0) {
            fn_12_818(resource, 0, 0);
        } else {
            input[0] = self->value_104;
            input[1] = self->value_108;
            if (SJ_SearchTag(input, &lbl_12_rodata_1778,
                            lbl_12_rodata_1780, output) == 0) {
                fn_12_818(resource, 0, 0);
            } else {
                fn_12_818(resource, output[0], output[1]);
            }
        }
    }
}

/* --- rel/movie_module/fn_12_353C4.c --- */
typedef struct Movie Movie;
typedef struct MovieVTable MovieVTable;

struct MovieVTable {
    u8 pad_00[0x14];
    void (*method_14)(Movie *self);
};

struct Movie {
    MovieVTable *vtable;
};

typedef struct MovieModuleState_u1 {
    u8 pad_e8[0xe8];
    Movie *movie;
} MovieModuleState_u1;

void fn_12_353C4(MovieModuleState_u1 *self) {
    Movie *movie = self->movie;

    if (movie != 0) {
        movie->vtable->method_14(movie);
    }
}

/* --- rel/movie_module/fn_12_353FC.c --- */
typedef struct MovieModuleState_u2 {
    u8 pad_fc[0xfc];
    s32 status;
    s32 value_100;
    s32 value_104;
    s32 value_108;
} MovieModuleState_u2;

void fn_12_353FC(MovieModuleState_u2 *self) {
    self->value_100 = 0;
    self->value_104 = 0;
    self->value_108 = 0;
    self->status = -1;
}

/* --- rel/movie_module/fn_12_35418.c --- */
typedef struct MovieModuleState_u3 {
    u8 pad_0c[0x0c];
    s32 status;
    u8 pad_10[0x30];
    s32 value_40;
    u8 pad_44[0xa4];
    void *movie;
} MovieModuleState_u3;

extern s32 fn_12_2FA90(s32 arg0, s32 arg1, void *arg2, s32 arg3);

s32 fn_12_35418(MovieModuleState_u3 *self) {
    s32 status_eq;

    status_eq = self->status == 2;
    if (status_eq == 1) {
        return 0;
    }

    if (self->movie == 0) {
        return 0;
    }

    return fn_12_2FA90(self->value_40, 2, self->movie, 0) ? -1 : 0;
}
