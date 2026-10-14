/* Non-matching: best partial attempt (91.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80053350_pool {
    f32 zero;
    f32 max;
    f32 min;
    s32 pad_C;
    f64 two52;
};

extern struct fn_80053350_pool lbl_80091338;

static inline f32 fn_80053350_read_pointer_read_pointer(struct fn_80053350_pool * owner) { return owner->zero; }
static inline f32 fn_80053350_read_pointer(struct fn_80053350_pool * owner) { return fn_80053350_read_pointer_read_pointer(owner); }
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
void fn_80053350(f32 *arg0, f32 *arg1, u16 *arg2) {
    f32 *p = arg0;
    f32 *w = arg1;
    u16 *o = arg2;
    s32 n;
    n = 0x20;
    while (n != 0) {
        f32 s = fn_80053350_read_pointer(&lbl_80091338);
        s += ((0)[w]) * ((0)[p]);
        s += ((1)[w]) * ((96)[p]);
        s += ((2)[w]) * ((128)[p]);
        s += ((3)[w]) * ((224)[p]);
        s += ((4)[w]) * ((256)[p]);
        s += ((5)[w]) * ((352)[p]);
        s += ((6)[w]) * ((384)[p]);
        s += ((7)[w]) * ((480)[p]);
        s += ((8)[w]) * ((512)[p]);
        s += ((9)[w]) * ((608)[p]);
        s += ((10)[w]) * ((640)[p]);
        s += ((11)[w]) * ((736)[p]);
        s += ((12)[w]) * ((-256)[p]);
        s += ((13)[w]) * ((-160)[p]);
        s += ((14)[w]) * (*((-128) + (p)));
        s += ((15)[w]) * ((-32)[p]);
        if (s > (2.14748365e+09f)) {
            s = (2.14748365e+09f);
        } else if (s < (-2.14748365e+09f)) {
            s = (-2.14748365e+09f);
        }
        *o++ = (u16)(s16)(f32)(s32)s;
        n--;
    }
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

