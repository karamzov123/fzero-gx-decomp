#include "types.h"

typedef struct MovieEntry {
    u32 unk00;
    void *unk04;
    void *unk08;
    u32 unk0c;
} MovieEntry;

typedef struct MovieModule_u1 {
    u8 unk0000[0x1cc8];
    MovieEntry *entries;
    u8 unk1ccc[4];
    int count;
} MovieModule_u1;

struct Sig_fn_12_2269C_fn_12_2269C_Copy16 { u32 a[4]; };

typedef struct MovieModule {
    u8 pad_0000[0x1cd0];
    int movie_state;
} MovieModule;
extern void fn_12_24A88(void *, int);
extern void fn_12_2269C(MovieModule_u1 *, int, int, void *);
extern int fn_12_2F1D0(MovieModule *, int);
extern int fn_12_21D30(MovieModule *, int);
extern void fn_12_2F1E0(MovieModule *, int, int);
extern int fn_12_2F1F0(MovieModule *, int);
extern int fn_12_21D50(MovieModule_u1 *module, int index);
extern void fn_12_2F200(MovieModule *, int, int);
extern s32 fn_12_24990(u32 arg0);

/* fzgx:begin fn_12_2F8A0 */
/* --- rel/movie_module/fn_12_2F8A0.c --- */
// fn_12_2F8A0: returns a constant.
int fn_12_2F8A0(void) {
    return 0;
}
/* fzgx:end fn_12_2F8A0 */

/* fzgx:begin fn_12_2F8A8 */
/* --- rel/movie_module/fn_12_2F8A8.c --- */

void fn_12_2F8A8(void *arg0) {
    fn_12_24A88(arg0, 0xFF000601);
}
/* fzgx:end fn_12_2F8A8 */

/* fzgx:begin fn_12_2F8D0 */
/* --- rel/movie_module/fn_12_2F8D0.c --- */
void fn_12_2F8D0(void *arg0) {
    fn_12_24A88(arg0, 0xFF000601);
}
/* fzgx:end fn_12_2F8D0 */

/* fzgx:begin fn_12_2F8F8 */
/* --- rel/movie_module/fn_12_2F8F8.c --- */

void fn_12_2F8F8(void *arg) {
    fn_12_24A88(arg, 0xff000601);
}
/* fzgx:end fn_12_2F8F8 */

/* fzgx:begin fn_12_2F920 */
/* --- rel/movie_module/fn_12_2F920.c --- */
/* --- rel/movie_module/fn_12_2F920.c --- */

void fn_12_2F920(void *arg0) {
    fn_12_24A88(arg0, 0xff000601u);
}
/* fzgx:end fn_12_2F920 */

/* fzgx:begin fn_12_2F948 */
/* --- rel/movie_module/fn_12_2F948.c --- */
// fn_12_2F948: returns a constant.
int fn_12_2F948(void) {
    return 0;
}
/* fzgx:end fn_12_2F948 */

/* fzgx:begin fn_12_2F950 */
/* --- rel/movie_module/fn_12_2F950.c --- */
// fn_12_2F950: returns a constant.
int fn_12_2F950(void) {
    return 0;
}
/* fzgx:end fn_12_2F950 */

/* fzgx:begin fn_12_2F958 */
/* --- rel/movie_module/fn_12_2F958.c --- */
// fn_12_2F958: returns a constant.
int fn_12_2F958(void) {
    return 0;
}
/* fzgx:end fn_12_2F958 */

/* fzgx:begin fn_12_2F960 */
/* --- rel/movie_module/fn_12_2F960.c --- */
// fn_12_2F960: returns a constant.
int fn_12_2F960(void) {
    return 0;
}
/* fzgx:end fn_12_2F960 */

/* fzgx:begin fn_12_2F968 */
/* --- rel/movie_module/fn_12_2F968.c --- */
// fn_12_2F968: returns a constant.
int fn_12_2F968(void) {
    return 0;
}
/* fzgx:end fn_12_2F968 */

/* fzgx:begin fn_12_2F970 */
struct MovieSlot { u32 pre; struct Sig_fn_12_2269C_fn_12_2269C_Copy16 copy; };
struct MovieState { u8 pad[0x1cc8]; struct MovieSlot *slots; u8 pad2[4]; s32 value; };
typedef struct Fn122F970Loop { u32 zero; int index; } Fn122F970Loop;
#pragma opt_loop_invariants off
int fn_12_2F970(struct MovieState *arg0) {
    Fn122F970Loop s;
    struct MovieSlot *p;
    u32 *fzgx_live;
    u32 v;
    p = (struct MovieSlot *)((u8 *)arg0 + 0x28d4);
    arg0->slots = p;
    v = arg0->value;
    s.zero = 0;
    p->pre = s.zero;
    s.index = s.zero;
    do {
        fzgx_live = p->copy.a;
        fzgx_live[0] = s.zero;
        fzgx_live = p->copy.a;
        fzgx_live[1] = s.zero;
        fzgx_live = p->copy.a;
        fzgx_live[2] = s.zero;
        fzgx_live = p->copy.a;
        fzgx_live[3] = s.zero;
        fn_12_2269C( (MovieModule_u1 *)((u8 *)arg0), v, s.index, (void *)(struct Sig_fn_12_2269C_fn_12_2269C_Copy16 *)(&p->copy));
        s.index++;
        p = (struct MovieSlot *)((u8 *)p + 0x10);
    } while (s.index < 3);
    return 0;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_12_2F970 */

/* fzgx:begin fn_12_2F9E8 */
/* --- rel/movie_module/fn_12_2F9E8.c --- */
/* --- rel/movie_module/fn_12_2F9E8.c --- */


int fn_12_2F9E8(MovieModule *module) {
    if (fn_12_2F1D0(module, 8) != 1 &&
        fn_12_21D30(module, module->movie_state) == 1) {
        fn_12_2F1E0(module, 8, 1);
    }

    if (fn_12_2F1F0(module, 8) != 1 &&
        fn_12_21D50( (MovieModule_u1 *)(MovieModule *)(module), module->movie_state) == 1) {
        fn_12_2F200(module, 8, 1);
    }

    return 0;
}
/* fzgx:end fn_12_2F9E8 */

/* fzgx:begin fn_12_2FA80 */
/* --- rel/movie_module/fn_12_2FA80.c --- */
// fn_12_2FA80: returns a constant.
int fn_12_2FA80(void) {
    return 0;
}
/* fzgx:end fn_12_2FA80 */

/* fzgx:begin fn_12_2FA88 */
/* --- rel/movie_module/fn_12_2FA88.c --- */
// fn_12_2FA88: returns a constant.
int fn_12_2FA88(void) {
    return 0;
}
/* fzgx:end fn_12_2FA88 */

/* fzgx:begin fn_12_2FA90 */
/* --- rel/movie_module/fn_12_2FA90.c --- */
/* --- rel/movie_module/fn_12_2FA90.c --- */



int fn_12_2FA90(MovieModule_u1 *module, int index, void *arg1, void *arg2) {
    int count;
    MovieEntry *entries;

    if (fn_12_24990( (u32)(MovieModule_u1 *)(module)) != 0) {
        fn_12_24A88(0, 0xff000191);
    } else {
        count = module->count;
        entries = module->entries;
        if (count == 8) {
            fn_12_24A88(module, 0xff000602);
        } else {
            entries[index].unk04 = arg1;
            entries[index].unk08 = arg2;
            entries[index].unk0c = 0;
            entries[index + 1].unk00 = 0;
            fn_12_2269C(module, count, index, &entries[index].unk04);
            return 0;
        }
    }
}
/* fzgx:end fn_12_2FA90 */
