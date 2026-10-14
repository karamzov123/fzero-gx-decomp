/* Non-matching: best partial attempt (98.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_9DDA8_Arg1 {
    s32 type;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
};
extern f32 lbl_1_rodata_42A0[8];

#pragma opt_common_subs off
static inline f32 fn_1_9DDA8_operand(f32 right, f32 left) { return left + right; }
#pragma peephole off
static inline f32 fn_1_9DDA8_operand_(f32 left, f32 right) { return left + right; }
#pragma opt_strength_reduction off
static inline f32 fn_1_9DDA8_operand__(f32 right, f32 left) { return left * right; }
#pragma opt_loop_invariants on
static inline f32 fn_1_9DDA8_read_pointer(struct fn_1_9DDA8_Arg1 * owner) { return owner->unk_10; }
f32 fn_1_9DDA8(s32 arg0, struct fn_1_9DDA8_Arg1 *arg1, s32 arg2, f32 arg3) {
#pragma fp_contract off
    f32 *pool = lbl_1_rodata_42A0;
#define lbl_1_rodata_42A0 pool
    f32 t;
    struct fn_1_9DDA8_Arg1 *v1;
    f32 t2;
    f32 h11;
    f32 h;
    f32 dx;
    f32 d;
    f32 a;
    f32 b;
    f32 sum;
    f32 previousTime;
    f32 numerator;
    if (arg0 < 2 || arg3 <= arg1->unk_4) {
        return arg2 ? fn_1_9DDA8_read_pointer(arg1) : arg1->unk_8;
    }
    v1 = ((arg0) + (arg1));
    if (arg3 >= ((-1)[v1]).unk_4) {
        return arg2 ? ((-1)[v1]).unk_C : ((-1)[v1]).unk_8;
    }
    arg1++;
    arg0--;
    for (; arg0 > 1; arg0--) {
        if (arg1->unk_4 > arg3) break;
        arg1++;
    }
    if (arg2) {
        switch (((-1)[arg1]).type) {
        case 0: return ((0)[lbl_1_rodata_42A0]);
        case 1: return arg1->unk_8 - ((-1)[arg1]).unk_8;
        default:
            previousTime = ((-1)[arg1]).unk_4;
            numerator = arg3 - previousTime;
            dx = arg1->unk_4 - previousTime;
            t = numerator / dx;
            d = ((-1)[arg1]).unk_8 - arg1->unk_8;
            a = ((((dx)) * ((((-1)[arg1]).unk_10))));
            b = dx * arg1->unk_C;
            sum = a + b;
            return a + ((f32)(t * t * ((fn_1_9DDA8_operand((sum), (((1)[lbl_1_rodata_42A0]) * d))) / ((2)[lbl_1_rodata_42A0]))) - (f32)(t * ((a + fn_1_9DDA8_operand(sum, ((2)[lbl_1_rodata_42A0]) * d)) * ((3)[lbl_1_rodata_42A0]))));
        }
    }
    switch (((-1)[arg1]).type) {
    case 0: return ((-1)[arg1]).unk_8;
    case 1:
        t = (arg3 - ((-1)[arg1]).unk_4) / (arg1->unk_4 - ((-1)[arg1]).unk_4);
        return ((-1)[arg1]).unk_8 * (((f64 *)lbl_1_rodata_42A0)[2] - t) + (f32)(arg1->unk_8 * t);
    default:
        t = (arg3 - ((-1)[arg1]).unk_4) / (arg1->unk_4 - ((-1)[arg1]).unk_4);
        t2 = t * t;
        dx = arg1->unk_4 - ((-1)[arg1]).unk_4;
        h11 = (f32)(t2 * t) - t2;
        h = (f32)(((1)[lbl_1_rodata_42A0]) * h11) - t2;
        return (f32)(fn_1_9DDA8_operand__((((-1)[arg1]).unk_8), ((((6)[lbl_1_rodata_42A0]) + h)))) - (f32)(h * arg1->unk_8)
            + (f32)(dx * (fn_1_9DDA8_operand_(((f32)(((-1)[arg1]).unk_10 * (t + (h11 - t2)))), ((f32)(h11 * arg1->unk_C)))));
    }
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset
#pragma peephole reset
#pragma opt_common_subs reset
