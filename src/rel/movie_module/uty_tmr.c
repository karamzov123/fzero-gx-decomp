#include "types.h"
#include "ppc_ops.h"

/* fzgx:begin fn_12_335A4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_335A4.c --- */
extern u32 lbl_12_bss_1B778[2];

u64 fn_12_335A4(void) {
    return *(u64 *)lbl_12_bss_1B778;
}
/* fzgx:end fn_12_335A4 */

/* fzgx:begin fn_12_335B8 noprologue */
#include "types.h"
#include "ppc_ops.h"


/* --- rel/movie_module/fn_12_335B8.c --- */
extern s64 lbl_12_bss_1B778;

s64 fn_12_335B8(void) {
    if (lbl_12_bss_1B778 == 1) {
        return 0;
    }
    return ppc_get_time_base();
}
/* fzgx:end fn_12_335B8 */

/* fzgx:begin fn_12_33604 noprologue */

/* --- rel/movie_module/fn_12_33604.c --- */
extern s32 lbl_12_bss_1B770[4];

void fn_12_33604(s32 movie_id) {
    s32 *state = lbl_12_bss_1B770;
    s32 zero;
    u32 clock;

    if (state[1] != 0 && state[0] == movie_id) {
        return;
    }

    state[1] = 1;
    state[0] = movie_id;
    if (movie_id == -1) {
        state[3] = 1;
        state[2] = 0;
        return;
    } else {
        zero = 0;
        state[3] = (*(u32 *)0x800000F8) >> 2; /* fzgx-allow: A1,A2 unnamed OS memory */
        state[2] = zero;
    }
}
/* fzgx:end fn_12_33604 */
