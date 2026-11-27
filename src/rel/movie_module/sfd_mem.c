#include "types.h"

/* fzgx:begin fn_12_24D78 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_24D78.c --- */
// fn_12_24D78: returns a constant.
int fn_12_24D78(void) {
    return 0;
}
/* fzgx:end fn_12_24D78 */

/* fzgx:begin fn_12_24D80 noprologue */

/* --- rel/movie_module/fn_12_24D80.c --- */
extern void fn_12_24A88(int arg0, int arg1);

void fn_12_24D80(int arg0) {
    fn_12_24A88(arg0, 0xff000501);
}
/* fzgx:end fn_12_24D80 */

/* fzgx:begin fn_12_24DA8 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_24DA8.c --- */
extern void fn_12_24A88(void *arg0, int arg1);

void fn_12_24DA8(void *arg0) {
    fn_12_24A88(arg0, -16775935);
}
/* fzgx:end fn_12_24DA8 */

/* fzgx:begin fn_12_24DD0 noprologue */

/* --- rel/movie_module/fn_12_24DD0.c --- */
extern u32 fn_12_22254(u32, u32, u32, u32);

struct fn_12_24DD0_Arg0 {
    u8 pad_0[0x1AB4];
    u32 unk_1AB4;
};

void fn_12_24DD0(struct fn_12_24DD0_Arg0 *arg0, u32 arg1, u32 arg2) {
    fn_12_22254((u32)arg0, arg0->unk_1AB4, arg1, arg2);
}
/* fzgx:end fn_12_24DD0 */

/* fzgx:begin fn_12_24E00 noprologue */

/* --- rel/movie_module/fn_12_24E00.c --- */
typedef struct MovieContext {
    u8 pad_0000[0x1ab4];
    void *movie;
} MovieContext;

extern void fn_12_224FC(void *context, void *movie, void *argument);

void fn_12_24E00(MovieContext *context, void *argument) {
    fn_12_224FC(context, context->movie, argument);
}
/* fzgx:end fn_12_24E00 */

/* fzgx:begin fn_12_24E28 noprologue */

/* --- rel/movie_module/fn_12_24E28.c --- */
// fn_12_24E28: returns a constant.
int fn_12_24E28(void) {
    return 0;
}
/* fzgx:end fn_12_24E28 */

/* fzgx:begin fn_12_24E30 noprologue */

/* --- rel/movie_module/fn_12_24E30.c --- */
// fn_12_24E30: returns a constant.
int fn_12_24E30(void) {
    return 0;
}
/* fzgx:end fn_12_24E30 */

/* fzgx:begin fn_12_24E38 noprologue */

/* --- rel/movie_module/fn_12_24E38.c --- */
// fn_12_24E38: returns a constant.
int fn_12_24E38(void) {
    return 0;
}
/* fzgx:end fn_12_24E38 */

/* fzgx:begin fn_12_24E40 noprologue */

/* --- rel/movie_module/fn_12_24E40.c --- */
// fn_12_24E40: returns a constant.
int fn_12_24E40(void) {
    return 0;
}
/* fzgx:end fn_12_24E40 */

/* fzgx:begin fn_12_24E48 noprologue */

/* --- rel/movie_module/fn_12_24E48.c --- */
// fn_12_24E48: returns a constant.
int fn_12_24E48(void) {
    return 0;
}
/* fzgx:end fn_12_24E48 */

/* fzgx:begin fn_12_24E50 noprologue */

/* --- rel/movie_module/fn_12_24E50.c --- */
// fn_12_24E50: returns a constant.
int fn_12_24E50(void) {
    return 0;
}
/* fzgx:end fn_12_24E50 */

/* fzgx:begin fn_12_24E58 noprologue */

/* --- rel/movie_module/fn_12_24E58.c --- */
extern u32 fn_12_21D60(u32, u32, u32);

struct fn_12_24E58_Arg0 {
    u8 pad_0[0x1AB4];
    u32 unk_1AB4;
};

s32 fn_12_24E58(struct fn_12_24E58_Arg0 *arg0) {
    fn_12_21D60((u32)arg0, arg0->unk_1AB4, 1);
    return 0;
}
/* fzgx:end fn_12_24E58 */

/* fzgx:begin fn_12_24E84 noprologue */

/* --- rel/movie_module/fn_12_24E84.c --- */
// fn_12_24E84: returns a constant.
int fn_12_24E84(void) {
    return 0;
}
/* fzgx:end fn_12_24E84 */

/* fzgx:begin fn_12_24E8C noprologue */

/* --- rel/movie_module/fn_12_24E8C.c --- */
// fn_12_24E8C: returns a constant.
int fn_12_24E8C(void) {
    return 0;
}
/* fzgx:end fn_12_24E8C */
