#include "types.h"


/* --- rel/movie_module/fn_12_24DA8.c --- */
extern void fn_12_24A88(void *arg0, int arg1);

void fn_12_24DA8(void *arg0);

/* --- rel/movie_module/fn_12_24DD0.c --- */
extern u32 fn_12_22254(u32, u32, u32, u32);

struct fn_12_24DD0_Arg0 {
    u8 pad_0[0x1AB4];
    u32 unk_1AB4;
};

void fn_12_24DD0(struct fn_12_24DD0_Arg0 *arg0, u32 arg1, u32 arg2);

/* --- rel/movie_module/fn_12_24E00.c --- */
typedef struct MovieContext {
    u8 pad_0000[0x1ab4];
    void *movie;
} MovieContext;

extern void fn_12_224FC(void *context, void *movie, void *argument);

void fn_12_24E00(MovieContext *context, void *argument);

/* --- rel/movie_module/fn_12_24E28.c --- */
// fn_12_24E28: returns a constant.
int fn_12_24E28(void);

/* --- rel/movie_module/fn_12_24E30.c --- */
// fn_12_24E30: returns a constant.
int fn_12_24E30(void);

/* --- rel/movie_module/fn_12_24E38.c --- */
// fn_12_24E38: returns a constant.
int fn_12_24E38(void);

/* --- rel/movie_module/fn_12_24E40.c --- */
// fn_12_24E40: returns a constant.
int fn_12_24E40(void);

/* --- rel/movie_module/fn_12_24E48.c --- */
// fn_12_24E48: returns a constant.
int fn_12_24E48(void);

/* --- rel/movie_module/fn_12_24E50.c --- */
// fn_12_24E50: returns a constant.
int fn_12_24E50(void);

/* --- rel/movie_module/fn_12_24E58.c --- */
extern u32 fn_12_21D60(u32, u32, u32);

struct fn_12_24E58_Arg0 {
    u8 pad_0[0x1AB4];
    u32 unk_1AB4;
};

s32 fn_12_24E58(struct fn_12_24E58_Arg0 *arg0);

/* --- rel/movie_module/fn_12_24E84.c --- */
// fn_12_24E84: returns a constant.
int fn_12_24E84(void);

/* --- rel/movie_module/fn_12_24E8C.c --- */
// fn_12_24E8C: returns a constant.
int fn_12_24E8C(void);

/* --- rel/movie_module/fn_12_24E94.c --- */
typedef struct MovieModule MovieModule;
typedef struct MovieState MovieState;

struct MovieModule {
    u8 pad_0000[0x1aec];
    MovieState *state;
};

struct MovieState {
    u8 pad_0000[0x14];
    u32 value;
};

u32 fn_12_24E94(MovieModule *module) {
    return module->state->value;
}
