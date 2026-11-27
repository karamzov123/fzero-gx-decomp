#include "types.h"

/* fzgx:begin fn_12_34E90 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_34E90.c --- */
extern void fn_8004AEE4(void);

void fn_12_34E90(void) {
    fn_8004AEE4();
}
/* fzgx:end fn_12_34E90 */

/* fzgx:begin fn_12_34EB0 noprologue */

/* --- rel/movie_module/fn_12_34EB0.c --- */
extern void fn_8004AD84(void);
extern void fn_8004B0EC(void *);

void fn_12_34EB0(void *arg) {
    fn_8004AD84();
    fn_8004B0EC(arg);
}
/* fzgx:end fn_12_34EB0 */

/* fzgx:begin fn_12_34EE4 noprologue */

/* --- rel/movie_module/fn_12_34EE4.c --- */
extern void fn_8004ADF4(void);

void fn_12_34EE4(void) {
    fn_8004ADF4();
}
/* fzgx:end fn_12_34EE4 */

/* fzgx:begin fn_12_34F04 noprologue */

/* --- rel/movie_module/fn_12_34F04.c --- */
extern u32 fn_8004AC04(u32, u32);
extern u32 fn_8004B180(u32, u32, u32, u32, u32);

void fn_12_34F04(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    fn_8004B0EC((void *)arg0);
    fn_8004B180(arg0, arg1, arg2, arg3, arg4);
    fn_8004AC04(arg0, arg4);
}
/* fzgx:end fn_12_34F04 */

/* fzgx:begin fn_12_34F64 noprologue */
#include "types.h"
#pragma dont_inline on

/* --- rel/movie_module/fn_12_34F64.c --- */
/* --- rel/movie_module/fn_12_34F64.c --- */
extern void fn_8004B1DC(void);

void fn_12_34F64(void) {
    fn_8004B1DC();
}
/* fzgx:end fn_12_34F64 */

/* fzgx:begin fn_12_34F84 noprologue */

/* --- rel/movie_module/fn_12_34F84.c --- */
extern void fn_8004B4E0(int, int);

void fn_12_34F84(int arg) {
    fn_8004B4E0(arg, 0);
}
/* fzgx:end fn_12_34F84 */

/* fzgx:begin fn_12_34FA8 noprologue */

/* --- rel/movie_module/fn_12_34FA8.c --- */
extern void fn_8004A550(void *);

void fn_12_34FA8(void *arg) {
    if (arg != 0) {
        fn_8004A550(arg);
    }
}
/* fzgx:end fn_12_34FA8 */

/* fzgx:begin fn_12_34FD0 noprologue */

/* --- rel/movie_module/fn_12_34FD0.c --- */
extern u32 fn_8004AEE4(void);

u32 fn_12_34FD0(void) {
    u32 t0;
    t0 = fn_8004AEE4();
    return ((u32)__cntlzw((4 - t0)) >> 5);
}
/* fzgx:end fn_12_34FD0 */

/* fzgx:begin fn_12_34FFC noprologue */

/* --- rel/movie_module/fn_12_34FFC.c --- */
// fn_12_34FFC: returns a constant.
int fn_12_34FFC(void) {
    return 0;
}
/* fzgx:end fn_12_34FFC */

/* fzgx:begin fn_12_35004 noprologue */

/* --- rel/movie_module/fn_12_35004.c --- */
// fn_12_35004: returns a constant.
int fn_12_35004(void) {
    return 0;
}
/* fzgx:end fn_12_35004 */
