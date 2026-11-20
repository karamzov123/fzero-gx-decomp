#include "types.h"
#include "sofdec/sfd.h"


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
void SFTMR_AddTsum(SfdTimerSummary *summary, long long elapsed) {
    long long minimum;
    long long maximum;
    summary->total += elapsed;
    minimum = summary->minimum;
    if (elapsed < minimum) {
        minimum = elapsed;
    }
    summary->minimum = minimum;
    maximum = summary->maximum;
    elapsed = maximum < elapsed ? elapsed : maximum;
    summary->maximum = elapsed;
    summary->count++;
}

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

void fn_12_2FE30(struct fn_12_2FE30_Arg0 *arg0) {
    arg0->unk_4 = 0;
    arg0->unk_0 = 0;
    arg0->unk_C = -1;
    arg0->unk_8 = (0x80000000 - 1);
    arg0->unk_14 = 0;
    arg0->unk_10 = 0;
    arg0->unk_18 = 0;
}
