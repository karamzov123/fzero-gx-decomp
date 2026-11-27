#include "types.h"
#include "sofdec/sfd.h"


/* --- rel/movie_module/fn_12_2FC40.c --- */
/* --- rel/movie_module/fn_12_2FC40.c --- */
extern void fn_12_24A88(void*, u32);

void fn_12_2FC40(void* arg0) {
    fn_12_24A88(arg0, 0xff000701);
}

/* --- rel/movie_module/fn_12_2FC68.c --- */
// fn_12_2FC68: returns a constant.
int fn_12_2FC68(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FC70.c --- */
// fn_12_2FC70: returns a constant.
int fn_12_2FC70(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FC78.c --- */
// fn_12_2FC78: returns a constant.
int fn_12_2FC78(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FC80.c --- */
// fn_12_2FC80: returns a constant.
int fn_12_2FC80(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FC88.c --- */
// fn_12_2FC88: returns a constant.
int fn_12_2FC88(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FC90.c --- */
// fn_12_2FC90: returns a constant.
int fn_12_2FC90(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FC98.c --- */
typedef struct MovieModule {
    u8 _pad[0x1c48];
    int movie_id;
} MovieModule;

extern int fn_12_2D73C(MovieModule *, int);
extern int fn_12_2F1D0(MovieModule *, int);
extern int fn_12_21D30(MovieModule *, int);
extern int fn_12_2DABC(MovieModule *);
extern void fn_12_2F1E0(MovieModule *, int, int);
extern int fn_12_2F1F0(MovieModule *, int);
extern int fn_12_21D50(MovieModule *, int);
extern void fn_12_2F200(MovieModule *, int, int);

int fn_12_2FC98(MovieModule *movie_module) {
    int ready;

    if (fn_12_2D73C(movie_module, 5) == 0) {
        return 0;
    }

    if (fn_12_2F1D0(movie_module, 6) != 1 &&
        fn_12_21D30(movie_module, movie_module->movie_id) == 1) {
        if (fn_12_2D73C(movie_module, 15) == 0) {
            ready = 1;
        } else if (fn_12_2DABC(movie_module) == 0) {
            ready = 0;
        } else {
            ready = 1;
        }

        if (ready != 0) {
            fn_12_2F1E0(movie_module, 6, 1);
        }
    }

    if (fn_12_2F1F0(movie_module, 6) != 1 &&
        fn_12_21D50(movie_module, movie_module->movie_id) == 1) {
        fn_12_2F200(movie_module, 6, 1);
    }

    return 0;
}

/* --- rel/movie_module/fn_12_2FD8C.c --- */
// fn_12_2FD8C: returns a constant.
int fn_12_2FD8C(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2FD94.c --- */
// fn_12_2FD94: returns a constant.
int fn_12_2FD94(void) {
    return 0;
}

/* --- rel/movie_module/SFTMR_AddTsum.c --- */
void SFTMR_AddTsum(SfdTimerSummary *summary, long long elapsed);

/* --- rel/movie_module/fn_12_2FE30.c --- */
struct fn_12_2FE30_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

void fn_12_2FE30(struct fn_12_2FE30_Arg0 *arg0);

/* --- rel/movie_module/fn_12_2FE60.c --- */
typedef struct Sig_fn_12_2FE60_Int64Pair {
    s64 a;
    s64 b;
} Sig_fn_12_2FE60_Int64Pair;

typedef struct Sig_fn_12_2FE60_State {
    s32 enabled;
    s32 mode;
    s32 active;
    s32 follow;
    s32 count;
    s32 index;
    s32 history[60];
    Sig_fn_12_2FE60_Int64Pair input;
    Sig_fn_12_2FE60_Int64Pair external;
    Sig_fn_12_2FE60_Int64Pair output;
    Sig_fn_12_2FE60_Int64Pair period;
    Sig_fn_12_2FE60_Int64Pair tolerance;
    Sig_fn_12_2FE60_Int64Pair initial;
    Sig_fn_12_2FE60_Int64Pair resume;
    s64 anchorExternal;
    s64 anchorInput;
    s64 maximum;
    s32 resyncs;
    s32 positive;
    s32 negative;
    s32 resets;
    s32 jumps;
    s32 average;
    s32 adjusted;
    s32 maxInactive;
    s32 minInactive;
    s32 maxActive;
    s32 minActive;
} Sig_fn_12_2FE60_State;

extern u8 lbl_12_bss_1B740[];
extern u32 lbl_12_bss_6988;
extern const f64 lbl_12_rodata_1020;
extern const f64 lbl_12_rodata_1018;
extern char lbl_12_rodata_1028[117];
extern void *memset(void *, int, u32);
extern f64 fn_80079D74(s64);
extern int sprintf(char *, const char *, ...);
extern char *strcpy(char *, const char *);

static inline s32 fn_12_2FE60_average(Sig_fn_12_2FE60_State *state) {
    s32 i;
    s32 sum = 0;
    for (i = 0; i < state->count; i++) {
        sum += state->history[i];
    }
    return sum / state->count;
}

extern s64 __div2i(s64, s64);




static inline void fn_12_2FE60_shift(Sig_fn_12_2FE60_State *state, s32 amount, s32 i) {
    for (; i < state->count; i++) {
        state->history[i] -= amount;
    }
}


void fn_12_2FE60(Sig_fn_12_2FE60_State *state, Sig_fn_12_2FE60_Int64Pair *arg1, Sig_fn_12_2FE60_Int64Pair *arg2, Sig_fn_12_2FE60_Int64Pair *arg3, f32 arg4);
