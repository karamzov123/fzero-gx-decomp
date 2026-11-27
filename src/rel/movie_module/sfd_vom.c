#include "types.h"
#include "sofdec/sfd.h"

struct fn_12_2FB5C_MovieModule {
    u8 pad_0x1c48[0x1c48];
    void *field_0x1c48;
};

typedef struct Sig_fn_12_2DEF0_MovieEntry {
    u8 pad_0[0x14];
    s32 value_14;
    s32 value_18;
} Sig_fn_12_2DEF0_MovieEntry;

typedef struct fn_12_2FC98_MovieModule {
    u8 _pad[0x1c48];
    int movie_id;
} fn_12_2FC98_MovieModule;
extern void fn_12_21D70(struct fn_12_2FB5C_MovieModule *, void *, void *);
extern int fn_12_21DD4(void *module, int index, int value);
extern int fn_12_2DEF0(void *, Sig_fn_12_2DEF0_MovieEntry *);
extern void fn_12_24A88(int, int);
extern u32 fn_12_2D73C(u8 *base, int index);
extern int fn_12_2F1D0(fn_12_2FC98_MovieModule *, int);
extern int fn_12_21D30(fn_12_2FC98_MovieModule *, int);
extern int fn_12_2DABC(fn_12_2FC98_MovieModule *);
extern void fn_12_2F1E0(fn_12_2FC98_MovieModule *, int, int);
extern int fn_12_2F1F0(fn_12_2FC98_MovieModule *, int);
extern int fn_12_21D50(fn_12_2FC98_MovieModule *, int);
extern void fn_12_2F200(fn_12_2FC98_MovieModule *, int, int);

/* fzgx:begin fn_12_2FB54 */
/* --- rel/movie_module/fn_12_2FB54.c --- */
// fn_12_2FB54: returns a constant.
int fn_12_2FB54(void) {
    return 0;
}
/* fzgx:end fn_12_2FB54 */

/* fzgx:begin fn_12_2FB5C */
/* --- rel/movie_module/fn_12_2FB5C.c --- */


void fn_12_2FB5C(struct fn_12_2FB5C_MovieModule *module, void *arg) {
    fn_12_21D70(module, module->field_0x1c48, arg);
}
/* fzgx:end fn_12_2FB5C */

/* fzgx:begin fn_12_2FB84 */
/* --- rel/movie_module/fn_12_2FB84.c --- */

s32 fn_12_2FB84(void *arg0, Sig_fn_12_2DEF0_MovieEntry **arg1) {
    s32 temp_r3;

    if ((u32) ((*(s32 *)((u8 *)(arg0) + 72)) - 3) > 1U) {
        (*(Sig_fn_12_2DEF0_MovieEntry **)((u8 *)(arg1) + 0)) = (Sig_fn_12_2DEF0_MovieEntry *)(NULL);
        return 0;
    }
    temp_r3 = fn_12_21DD4((void *)(arg0), *(s32 *)((u8 *)(arg0) + 7240), (s32)(arg1));
    if (temp_r3 != 0) {
        return temp_r3;
    }
    if (fn_12_2DEF0((void *)(arg0), (Sig_fn_12_2DEF0_MovieEntry *)(*(Sig_fn_12_2DEF0_MovieEntry **)((u8 *)(arg1) + 0))) == 0) {
        (*(Sig_fn_12_2DEF0_MovieEntry **)((u8 *)(arg1) + 0)) = (Sig_fn_12_2DEF0_MovieEntry *)(NULL);
        return 0;
    }
    return 0;
}
/* fzgx:end fn_12_2FB84 */

/* fzgx:begin fn_12_2FC18 */
/* --- rel/movie_module/fn_12_2FC18.c --- */

void fn_12_2FC18(int arg0) {
    fn_12_24A88(arg0, 0xff000701);
}
/* fzgx:end fn_12_2FC18 */

/* fzgx:begin fn_12_2FC40 */
/* --- rel/movie_module/fn_12_2FC40.c --- */
/* --- rel/movie_module/fn_12_2FC40.c --- */

void fn_12_2FC40(void* arg0) {
    fn_12_24A88( (int)(void*)(arg0), 0xff000701);
}
/* fzgx:end fn_12_2FC40 */

/* fzgx:begin fn_12_2FC68 */
/* --- rel/movie_module/fn_12_2FC68.c --- */
// fn_12_2FC68: returns a constant.
int fn_12_2FC68(void) {
    return 0;
}
/* fzgx:end fn_12_2FC68 */

/* fzgx:begin fn_12_2FC70 */
/* --- rel/movie_module/fn_12_2FC70.c --- */
// fn_12_2FC70: returns a constant.
int fn_12_2FC70(void) {
    return 0;
}
/* fzgx:end fn_12_2FC70 */

/* fzgx:begin fn_12_2FC78 */
/* --- rel/movie_module/fn_12_2FC78.c --- */
// fn_12_2FC78: returns a constant.
int fn_12_2FC78(void) {
    return 0;
}
/* fzgx:end fn_12_2FC78 */

/* fzgx:begin fn_12_2FC80 */
/* --- rel/movie_module/fn_12_2FC80.c --- */
// fn_12_2FC80: returns a constant.
int fn_12_2FC80(void) {
    return 0;
}
/* fzgx:end fn_12_2FC80 */

/* fzgx:begin fn_12_2FC88 */
/* --- rel/movie_module/fn_12_2FC88.c --- */
// fn_12_2FC88: returns a constant.
int fn_12_2FC88(void) {
    return 0;
}
/* fzgx:end fn_12_2FC88 */

/* fzgx:begin fn_12_2FC90 */
/* --- rel/movie_module/fn_12_2FC90.c --- */
// fn_12_2FC90: returns a constant.
int fn_12_2FC90(void) {
    return 0;
}
/* fzgx:end fn_12_2FC90 */

/* fzgx:begin fn_12_2FC98 */
/* --- rel/movie_module/fn_12_2FC98.c --- */


int fn_12_2FC98(fn_12_2FC98_MovieModule *movie_module) {
    int ready;

    if (((int)fn_12_2D73C( (u8 *)(fn_12_2FC98_MovieModule *)(movie_module), 5)) == 0) {
        return 0;
    }

    if (fn_12_2F1D0(movie_module, 6) != 1 &&
        fn_12_21D30(movie_module, movie_module->movie_id) == 1) {
        if (((int)fn_12_2D73C( (u8 *)(fn_12_2FC98_MovieModule *)(movie_module), 15)) == 0) {
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
/* fzgx:end fn_12_2FC98 */

/* fzgx:begin fn_12_2FD8C */
/* --- rel/movie_module/fn_12_2FD8C.c --- */
// fn_12_2FD8C: returns a constant.
int fn_12_2FD8C(void) {
    return 0;
}
/* fzgx:end fn_12_2FD8C */

/* fzgx:begin fn_12_2FD94 */
/* --- rel/movie_module/fn_12_2FD94.c --- */
// fn_12_2FD94: returns a constant.
int fn_12_2FD94(void) {
    return 0;
}
/* fzgx:end fn_12_2FD94 */
