/* Non-matching: best partial attempt (97.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/* Packed RGBA is returned as a word and compared by its four channels. */
typedef union {
    s32 w;
    u8 b[4];
} fn_3_149AC_color;

extern u32 fn_3_149AC(void *obj, s16 x, s16 y);
extern void fn_3_146C0(void *obj, s16 x, s16 y, s16 width, u32 *value);
extern void fn_80008BEC(void *dst, int fill, u32 size);

static inline u8 fn_3_1B130_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_strength_reduction on
#pragma opt_lifetimes on
void fn_3_1B130(void *arg0, s16 arg1, s16 arg2, u32 *arg3) {
    u32 tmp_fn_3_1B130_array_read;
    u16 t0;
    u8 t1;
    u8 t2;
    u8 t3;
    s16 xs[4096];
    s16 ys[4096];
    fn_3_149AC_color cur;
    fn_3_149AC_color seed;
    u32 val;
    s16 idx;
    s16 lo;
    s16 hi;
    s16 i = 0;
    s16 n = 1;

    seed.w = fn_3_149AC(arg0, arg1, arg2);
    fn_80008BEC(xs, 255, 8192);
    fn_80008BEC(ys, 255, 8192);
    xs[0] = arg1;
    ys[0] = arg2;
    if ((((s32)fn_3_1B130_array_read(seed.b, 0) >> 3) != ((s32)((u8 *)arg3)[0] >> 3)) ||
        (((s32)fn_3_1B130_array_read(seed.b, 1) >> 3) != ((s32)((u8 *)arg3)[1] >> 3)) ||
        (((s32)fn_3_1B130_array_read(seed.b, 2) >> 3) != ((s32)((u8 *)arg3)[2] >> 3)) ||
        (fn_3_1B130_array_read(seed.b, 3) != ((u8 *)arg3)[3])) {
        t0 = fn_3_1B130_array_read(seed.b, 0);
        t1 = fn_3_1B130_array_read(seed.b, 1);
        t2 = fn_3_1B130_array_read(seed.b, 2);
        t3 = fn_3_1B130_array_read(seed.b, 3);
        while (i != n) {
            idx = (*((xs) + (i)));
            while (idx >= 0) {
                cur.w = fn_3_149AC(arg0, idx, (*((ys) + (i))));
                tmp_fn_3_1B130_array_read = fn_3_1B130_array_read(cur.b, 0);
                if (tmp_fn_3_1B130_array_read != t0 || fn_3_1B130_array_read(cur.b, 1) != t1 || fn_3_1B130_array_read(cur.b, 2) != t2 || fn_3_1B130_array_read(cur.b, 3) != t3) {
                    lo = idx + 1;
                    break;
                }
                idx--;
            }
            if (idx == -1) {
                lo = 1;
            }
            idx = (*((xs) + (i))) + 1;
            while (idx < 0x3f) {
                cur.w = fn_3_149AC(arg0, idx, (*((ys) + (i))));
                tmp_fn_3_1B130_array_read = fn_3_1B130_array_read(cur.b, 0);
                if (tmp_fn_3_1B130_array_read != t0 || fn_3_1B130_array_read(cur.b, 1) != t1 || fn_3_1B130_array_read(cur.b, 2) != t2 || fn_3_1B130_array_read(cur.b, 3) != t3) {
                    hi = idx;
                    break;
                }
                idx++;
            }
            if (idx == 0x3f) {
                hi = 0x3f;
            }
            val = (*((arg3) + (0)));
            fn_3_146C0(arg0, lo, (*((ys) + (i))), (s16)(hi - lo), &val);
            {
    s16 fzgx_loop_idx_2667;
for (fzgx_loop_idx_2667 = lo; fzgx_loop_idx_2667 < hi; fzgx_loop_idx_2667++) {
                if ((*((ys) + (i))) - 1 < 1) {
                    break;
                }
                cur.w = fn_3_149AC(arg0, fzgx_loop_idx_2667, (s16)((*((ys) + (i))) - 1));
                tmp_fn_3_1B130_array_read = fn_3_1B130_array_read(cur.b, 0);
                if (tmp_fn_3_1B130_array_read == t0 && cur.b[1] == t1 && cur.b[2] == t2 && cur.b[3] == t3) {
                    xs[n] = fzgx_loop_idx_2667;
                    ys[n] = (*((ys) + (i))) - 1;
                    n = (n + 1) % 4096;
                }
            }
    idx = fzgx_loop_idx_2667;
}
            {
    s16 fzgx_loop_idx_3218;
for (fzgx_loop_idx_3218 = lo; fzgx_loop_idx_3218 < hi; fzgx_loop_idx_3218++) {
                if ((*((ys) + (i))) + 1 >= 0x3f) {
                    break;
                }
                cur.w = fn_3_149AC(arg0, fzgx_loop_idx_3218, (s16)((*((ys) + (i))) + 1));
                tmp_fn_3_1B130_array_read = fn_3_1B130_array_read(cur.b, 0);
                if (tmp_fn_3_1B130_array_read == t0 && cur.b[1] == t1 && cur.b[2] == t2 && cur.b[3] == t3) {
                    xs[n] = fzgx_loop_idx_3218;
                    ys[n] = (*((ys) + (i))) + 1;
                    n = (n + 1) % 4096;
                }
            }
    idx = fzgx_loop_idx_3218;
}
            i = (i + 1) % 4096;
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset


