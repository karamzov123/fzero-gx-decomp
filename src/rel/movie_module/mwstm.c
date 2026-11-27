#include "types.h"
extern u32 fn_8004AEE4(void);
extern void fn_8004AD84(void);
extern void fn_8004B0EC(void *);
extern s32 fn_8004ADF4();
extern u32 fn_8004AC04(u32, u32);
extern void fn_8004B180(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void fn_8004B1DC(void);
extern void fn_8004B4E0(int, int);
extern void fn_8004A550(void *);

/* fzgx:begin fn_12_34E90 */
/* --- rel/movie_module/fn_12_34E90.c --- */

void fn_12_34E90(void) {
    fn_8004AEE4();
}
/* fzgx:end fn_12_34E90 */

/* fzgx:begin fn_12_34EB0 */
/* --- rel/movie_module/fn_12_34EB0.c --- */

void fn_12_34EB0(void *arg) {
    fn_8004AD84();
    fn_8004B0EC(arg);
}
/* fzgx:end fn_12_34EB0 */

/* fzgx:begin fn_12_34EE4 */
/* --- rel/movie_module/fn_12_34EE4.c --- */

void fn_12_34EE4(void) {
    fn_8004ADF4();
}
/* fzgx:end fn_12_34EE4 */

/* fzgx:begin fn_12_34F04 */
/* --- rel/movie_module/fn_12_34F04.c --- */

void fn_12_34F04(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    fn_8004B0EC((void *)arg0);
    fn_8004B180(arg0, arg1, arg2, arg3, arg4);
    fn_8004AC04(arg0, arg4);
}
/* fzgx:end fn_12_34F04 */

/* fzgx:begin fn_12_34F64 */
#pragma dont_inline on

/* --- rel/movie_module/fn_12_34F64.c --- */
/* --- rel/movie_module/fn_12_34F64.c --- */

void fn_12_34F64(void) {
    fn_8004B1DC();
}
/* fzgx:end fn_12_34F64 */

/* fzgx:begin fn_12_34F84 */
/* --- rel/movie_module/fn_12_34F84.c --- */

void fn_12_34F84(int arg) {
    fn_8004B4E0(arg, 0);
}
/* fzgx:end fn_12_34F84 */

/* fzgx:begin fn_12_34FA8 */
/* --- rel/movie_module/fn_12_34FA8.c --- */

void fn_12_34FA8(void *arg) {
    if (arg != 0) {
        fn_8004A550(arg);
    }
}
/* fzgx:end fn_12_34FA8 */

/* fzgx:begin fn_12_34FD0 */
/* --- rel/movie_module/fn_12_34FD0.c --- */

u32 fn_12_34FD0(void) {
    u32 t0;
    t0 = fn_8004AEE4();
    return ((u32)__cntlzw((4 - t0)) >> 5);
}
/* fzgx:end fn_12_34FD0 */

/* fzgx:begin fn_12_34FFC */
/* --- rel/movie_module/fn_12_34FFC.c --- */
// fn_12_34FFC: returns a constant.
int fn_12_34FFC(void) {
    return 0;
}
/* fzgx:end fn_12_34FFC */

/* fzgx:begin fn_12_35004 */
/* --- rel/movie_module/fn_12_35004.c --- */
// fn_12_35004: returns a constant.
int fn_12_35004(void) {
    return 0;
}
/* fzgx:end fn_12_35004 */
