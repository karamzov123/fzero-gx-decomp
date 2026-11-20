#include "types.h"


/* --- rel/movie_module/fn_12_24EA0.c --- */
typedef struct MovieModule MovieModule;
typedef struct MovieState MovieState;
typedef struct MovieEntry MovieEntry;
typedef struct MovieData MovieData;

struct MovieState {
    u32 base;
    u8 pad_0004[0x08];
    u32 field_000c;
    u8 pad_0010[0x04];
    s32 value;
    u8 pad_0018[0x08];
    u32 field_0020;
    u32 field_0024;
};

struct MovieData {
    u8 pad_0000[0x160];
    void *arg_0160;
    void *arg_0164;
};

struct MovieEntry {
    s32 valid;
    u8 pad_0004[0x10];
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
    MovieData data;
};

struct MovieModule {
    u8 pad_0000[0xdd4];
    u32 field_0dd4;
    u8 pad_0dd8[0xd14];
    MovieState *state;
    u8 pad_0x1af0[0xe18];
    MovieEntry *entry;
};

extern void fn_12_245C4(MovieModule *module);
extern s32 fn_12_654C(void *arg0, MovieData *arg1, void *arg2, u32 *arg3, u32 *arg4);
extern s32 fn_12_24A88(MovieModule *module, u32 code);

s32 fn_12_24EA0(MovieModule *module) {
    MovieEntry *movie;
    MovieData *data;
    void *base;
    MovieState *state;
    s32 first;
    s32 second;
    s32 result;
    u32 local_c;
    u32 local_8;

    movie = module->entry;
    if (movie == 0) {
        movie = 0;
    } else {
        state = module->state;
        if (state->value > 0) {
            movie = 0;
        } else {
            movie = (MovieEntry *)((u8 *)movie + 0x8a0);
        }
    }
    if (movie == 0) {
        return 0;
    }
    if (movie->valid == 0) {
        return 0;
    }

    state = module->state;
    fn_12_245C4(module);
    base = (void *)state->base;
    data = (MovieData *)((u8 *)movie + 0x24);
    first = fn_12_654C(base, data, data->arg_0160, &local_c, &local_8);
    second = fn_12_654C(base, (MovieData *)((u8 *)data + 0xb0),
                        data->arg_0164, &local_c, &local_8);
    if (first != 0 || second != 0) {
        result = fn_12_24A88(module, 0xff000d0d);
    } else {
        result = 0;
    }
    if (result != 0) {
        return result;
    }
    state->field_0020 = movie->field_001c;
    state->field_0024 = movie->field_0020;
    module->field_0dd4 = movie->field_0014;
    state->field_000c = movie->field_0018;
    return 0;
}

/* --- rel/movie_module/fn_12_24FBC.c --- */
/* --- rel/movie_module/fn_12_24FBC.c --- */
/* --- rel/movie_module/fn_12_24FBC.c --- */

void fn_12_24FBC(void *arg0) {
    fn_12_24A88(arg0, 0xff000d0b);
}

/* --- rel/movie_module/fn_12_24FE4.c --- */
void fn_12_24FE4(void *arg0) {
    fn_12_24A88(arg0, (int)0xff000d0b);
}

/* --- rel/movie_module/fn_12_2500C.c --- */
void fn_12_2500C(void *arg0) {
    fn_12_24A88(arg0, (int)0xff000d0b);
}

/* --- rel/movie_module/fn_12_25034.c --- */
/* --- rel/movie_module/fn_12_25034.c --- */

void fn_12_25034(void *arg0) {
    fn_12_24A88(arg0, 0xFF000D0B);
}

/* --- rel/movie_module/fn_12_2505C.c --- */
// fn_12_2505C: returns a constant.
int fn_12_2505C(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_25064.c --- */
// fn_12_25064: returns a constant.
int fn_12_25064(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2506C.c --- */
// fn_12_2506C: returns a constant.
int fn_12_2506C(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_25074.c --- */
// fn_12_25074: returns a constant.
int fn_12_25074(void) {
    return 0;
}
