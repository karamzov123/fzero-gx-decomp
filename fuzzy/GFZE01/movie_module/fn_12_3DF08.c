/* Non-matching: best partial attempt (97.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_12_3DF08_MovieMatrix {
    s32 x;
    s32 y;
    s32 z;
    s32 width;
    s32 height;
    s32 depth;
    s32 pad_18;
} Sig_fn_12_3DF08_MovieMatrix;
typedef struct Sig_fn_12_3DF08_MovieSource {
    s32 object;
    s32 field_04;
    s32 field_08;
    u32 field_0c;
    s32 pad_10;
    s32 pad_14;
} Sig_fn_12_3DF08_MovieSource;

static inline u32 fn_12_3DF08_operand(u32 left, u32 right) { left &= right; return left; }
#pragma opt_dead_assignments off
static inline u32 fn_12_3DF08_operand_(s32 left, u32 right) { return left & right; }
static inline u32 fn_12_3DF08_operand__(u32 right, u32 left) { return ((right) & (left)); }
void fn_12_3DF08(Sig_fn_12_3DF08_MovieMatrix *arg0, Sig_fn_12_3DF08_MovieSource *arg1) {
    u32 v0;
    s32 v1;
    s32 v2;
    u32 v11;
    s32 v4;
    u32 v5;
    u32 v6;
    s32 v7;
    s32 v8;
    s32 v9;
    s32 v10;
    s32 unk_1;
    u32 v12;
    u32 mask0;
    s32 v13;
    struct { u32 value; } mask1;
    v8 = 0;
    v0 = arg0->width;
    v1 = arg1->field_04;
    unk_1 = v1 / 4;
{
    s32 fzgx_loop_v9_1045;
    s32 fzgx_loop_v7_1045;
    v13 = arg1->field_08 / 4;
    v12 = ((arg1->field_0c - v1) << 2) & 0xFFFFFFC0;
    fzgx_loop_v9_1045 = arg1->object;
    fzgx_loop_v7_1045 = arg0->x;
{
    u32 fzgx_loop_v5_1272;
    fzgx_loop_v5_1272 = v0;
    fzgx_loop_v5_1272 = fn_12_3DF08_operand_((fzgx_loop_v5_1272), (~3));
    v6 = (v0 << 4) & 0xFFFFFFF0;
    while (v8 < v13) {
        for (v10 = 0; v10 < unk_1; v10++) {
#define MASK0(x) (((x) & 0xFF000000) | (((x) >> 8) & 0xFF00) | 0x00FF00FF)
#define MASK1(x) ((((x) << 16) & 0xFF000000) | (((x) & 0xFF) << 8) | 0x00FF00FF)
#define APPLY(off) mask1.value = (((v11 << 16) & 0xFF000000) | ((v11 & 0xFF) << 8)); mask0 = MASK0(v11); mask0 = fn_12_3DF08_operand((*(u32 *)(fzgx_loop_v9_1045 + off)), (mask0)); *(u32 *)(fzgx_loop_v9_1045 + off) = mask0; mask0 = mask1.value | 0x00FF00FF; mask0 = fn_12_3DF08_operand__((mask0), (*(u32 *)(fzgx_loop_v9_1045 + off + 4))); *(u32 *)(fzgx_loop_v9_1045 + off + 4) = mask0
            v11 = *(u32 *)fzgx_loop_v7_1045;
{
    u32 fzgx_loop_v5_1272 = v0 & ~3;
            fzgx_loop_v7_1045 += fzgx_loop_v5_1272;
            APPLY(0);
            v11 = *(u32 *)fzgx_loop_v7_1045;
            fzgx_loop_v7_1045 += fzgx_loop_v5_1272;
            APPLY(8);
            v11 = *(u32 *)fzgx_loop_v7_1045;
            fzgx_loop_v7_1045 += fzgx_loop_v5_1272;
            APPLY(16);
            v11 = *(u32 *)fzgx_loop_v7_1045;
            fzgx_loop_v7_1045 += fzgx_loop_v5_1272;
}
            fzgx_loop_v7_1045 -= v6;
            fzgx_loop_v7_1045 += 4;
            APPLY(24);
            fzgx_loop_v9_1045 += 64;
        }
        fzgx_loop_v7_1045 += (v0 >> 2) * 12;
        fzgx_loop_v9_1045 += v12;
        v8++;
    }
    v5 = fzgx_loop_v5_1272;
}
    v9 = fzgx_loop_v9_1045;
    v7 = fzgx_loop_v7_1045;
}

}
#pragma opt_dead_assignments reset

