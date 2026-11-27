#include "types.h"
extern void fn_12_24A88(int arg0, int arg1);
extern u32 fn_12_22254(u32, u32, u32, u32);
extern s32 fn_12_224FC(u8 *arg0, int arg1, u32 *arg2);
extern u32 fn_12_21D60(u32, u32, u32);

/* fzgx:begin fn_12_24D78 */
/* --- rel/movie_module/fn_12_24D78.c --- */
// fn_12_24D78: returns a constant.
int fn_12_24D78(void) {
    return 0;
}
/* fzgx:end fn_12_24D78 */

/* fzgx:begin fn_12_24D80 */
/* --- rel/movie_module/fn_12_24D80.c --- */

void fn_12_24D80(int arg0) {
    fn_12_24A88(arg0, 0xff000501);
}
/* fzgx:end fn_12_24D80 */

/* fzgx:begin fn_12_24DA8 */
/* --- rel/movie_module/fn_12_24DA8.c --- */

void fn_12_24DA8(void *arg0) {
    fn_12_24A88( (int)(void *)(arg0), -16775935);
}
/* fzgx:end fn_12_24DA8 */

/* fzgx:begin fn_12_24DD0 */
/* --- rel/movie_module/fn_12_24DD0.c --- */

struct fn_12_24DD0_Arg0 {
    u8 pad_0[0x1AB4];
    u32 unk_1AB4;
};

void fn_12_24DD0(struct fn_12_24DD0_Arg0 *arg0, u32 arg1, u32 arg2) {
    fn_12_22254((u32)arg0, arg0->unk_1AB4, arg1, arg2);
}
/* fzgx:end fn_12_24DD0 */

/* fzgx:begin fn_12_24E00 */
/* --- rel/movie_module/fn_12_24E00.c --- */
typedef struct MovieContext {
    u8 pad_0000[0x1ab4];
    void *movie;
} MovieContext;


void fn_12_24E00(MovieContext *context, void *argument) {
    fn_12_224FC( (u8 *)(void *)(context), (int)(void *)(context->movie), (u32 *)(void *)(argument));
}
/* fzgx:end fn_12_24E00 */

/* fzgx:begin fn_12_24E28 */
/* --- rel/movie_module/fn_12_24E28.c --- */
// fn_12_24E28: returns a constant.
int fn_12_24E28(void) {
    return 0;
}
/* fzgx:end fn_12_24E28 */

/* fzgx:begin fn_12_24E30 */
/* --- rel/movie_module/fn_12_24E30.c --- */
// fn_12_24E30: returns a constant.
int fn_12_24E30(void) {
    return 0;
}
/* fzgx:end fn_12_24E30 */

/* fzgx:begin fn_12_24E38 */
/* --- rel/movie_module/fn_12_24E38.c --- */
// fn_12_24E38: returns a constant.
int fn_12_24E38(void) {
    return 0;
}
/* fzgx:end fn_12_24E38 */

/* fzgx:begin fn_12_24E40 */
/* --- rel/movie_module/fn_12_24E40.c --- */
// fn_12_24E40: returns a constant.
int fn_12_24E40(void) {
    return 0;
}
/* fzgx:end fn_12_24E40 */

/* fzgx:begin fn_12_24E48 */
/* --- rel/movie_module/fn_12_24E48.c --- */
// fn_12_24E48: returns a constant.
int fn_12_24E48(void) {
    return 0;
}
/* fzgx:end fn_12_24E48 */

/* fzgx:begin fn_12_24E50 */
/* --- rel/movie_module/fn_12_24E50.c --- */
// fn_12_24E50: returns a constant.
int fn_12_24E50(void) {
    return 0;
}
/* fzgx:end fn_12_24E50 */

/* fzgx:begin fn_12_24E58 */
/* --- rel/movie_module/fn_12_24E58.c --- */

struct fn_12_24E58_Arg0 {
    u8 pad_0[0x1AB4];
    u32 unk_1AB4;
};

s32 fn_12_24E58(struct fn_12_24E58_Arg0 *arg0) {
    fn_12_21D60((u32)arg0, arg0->unk_1AB4, 1);
    return 0;
}
/* fzgx:end fn_12_24E58 */

/* fzgx:begin fn_12_24E84 */
/* --- rel/movie_module/fn_12_24E84.c --- */
// fn_12_24E84: returns a constant.
int fn_12_24E84(void) {
    return 0;
}
/* fzgx:end fn_12_24E84 */

/* fzgx:begin fn_12_24E8C */
/* --- rel/movie_module/fn_12_24E8C.c --- */
// fn_12_24E8C: returns a constant.
int fn_12_24E8C(void) {
    return 0;
}
/* fzgx:end fn_12_24E8C */
