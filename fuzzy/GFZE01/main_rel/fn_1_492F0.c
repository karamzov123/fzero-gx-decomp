/* Non-matching: best partial attempt (89.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

typedef struct {
    u32 flags;
    u32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
} BlendSrc;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Rec;

typedef struct {
    Rec r[4];
} BlendOut;

typedef struct {
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    f32 v7;
} BlendRow;

extern const f32 lbl_1_rodata_FD0[60];

static inline f64 fn_1_492F0_operand(f64 left, f64 right) { return left * right; }
#pragma opt_common_subs on
static inline f64 fn_1_492F0_operand_(f64 left, f64 right) { return left * right; }
#pragma opt_loop_invariants on
static inline f64 fn_1_492F0_operand__(f64 right, f64 left) { return left * right; }
static inline f64 fn_1_492F0_operand___(f64 left, f64 right) { return ((right) * (left)); }
#pragma opt_strength_reduction on
static inline f64 fn_1_492F0_operand____(f64 right, f64 left) { return left * right; }
static inline f64 fn_1_492F0_operand_____(f64 right, f64 left) { left *= right; return left; }
static inline f64 fn_1_492F0_operand______(f64 left, f64 right) { return left * right; }
void fn_1_492F0(BlendSrc *src, BlendOut *out)
{
    f32 fzgx_live;
    s8 idx;
    f32 s0;
    f64 c0;
    f64 c2;
    f64 c1;
    f64 c3;
    f64 c4;
    f64 c6;
    f64 c5;
    struct { f64 value; } c7;
    f64 half;
    f64 p;
    const BlendRow *row;

    idx = (s8)(src->flags >> 24);
    s0 = lbl_1_rodata_FD0[65] + src->field_10;
{
    f32 s1;
    s1 = lbl_1_rodata_FD0[65] + src->field_14;
    if (idx == 0) {
        return;
    }
    half = ((const f64 *)lbl_1_rodata_FD0)[31];
    row = (const BlendRow *)&lbl_1_rodata_FD0[idx * 8];
    c0 = row->v0;
    c1 = row->v1;
    c2 = row->v2;
    c3 = row->v3;
    fzgx_live = row->v4;
    c4 = fzgx_live;
    c5 = row->v5;
    c6 = row->v6;
    c7.value = row->v7;
    p = (((s0) * (c0)) * (half));
    out->r[0].x = out->r[0].x + p;
    p = fn_1_492F0_operand_____((s1), (half * c1));
    out->r[0].y = out->r[0].y + p;
    p = fn_1_492F0_operand__((s0), (half * c2));
    out->r[1].x = ((1)[out->r]).x + p;
    p = fn_1_492F0_operand____((s1), (((c3) * (half))));
    out->r[1].y = out->r[1].y + p;
    p = (fn_1_492F0_operand______((((s0) * (c4))), ((half))));
    out->r[2].x = out->r[2].x + p;
    p = fn_1_492F0_operand((((c5) * (half))), (s1));
    out->r[2].y = out->r[2].y + p;
    p = (fn_1_492F0_operand___(((half)), (((((c6)) * ((s0)))))));
    out->r[3].x = out->r[3].x + p;
    p = fn_1_492F0_operand_((half * c7.value), (s1));
}
    out->r[3].y = out->r[3].y + p;
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

