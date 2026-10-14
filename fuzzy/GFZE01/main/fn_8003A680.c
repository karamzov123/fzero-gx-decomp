/* Non-matching: best partial attempt (84.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_8003A680_Arg0 {
    u8 pad_0[0x7B4];
    u32 unk_7B4;
};

typedef struct {
    s8 *str;
    s32 *codes;
} Q;

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
s32 fn_8003A680(struct fn_8003A680_Arg0 *arg0, u32 arg1) {
    s32 v0;
    u32 v2;
    Q *v1;
    s32 v3;
    s32 v4;
    u32 v5;
    u32 v7;
    s32 v8;
    s32 v10;
    u32 v11;
{
    s32 fzgx_loop_v3_584;
    s32 fzgx_loop_v4_584;
    v0 = (arg1 & 0xFF) * 168;
    v1 = (Q *)((((u8 *)arg0) + ((1060) + (v0))));
    v2 = (u32)arg0 + v0;
    fzgx_loop_v3_584 = *v1->str;
    fzgx_loop_v4_584 = 0;
    v5 = *(u32 *)(((1060) + ((u8 *)v2)));
    while (*(s8 *)v5) {
        v7 = *(u32 *)(((1060) + ((u8 *)v2))) + fzgx_loop_v4_584;
        while (fzgx_loop_v3_584 == *(s8 *)v7) {
            v7++;
            v5++;
            fzgx_loop_v4_584++;
        }
        fzgx_loop_v3_584++;
    }
    v3 = fzgx_loop_v3_584;
    v4 = fzgx_loop_v4_584;
}
    *(u32 *)((u8 *)(((v0) + ((u32)arg0))) + 1064) = arg0->unk_7B4;
    arg0->unk_7B4 = arg0->unk_7B4 + (v4 << 2);
    v10 = 0;
    v11 = 0;
    v8 = *v1->str;
    while (((s8 *)*(u32 *)(((1060) + ((u8 *)v2))))[v10]) {
        while (((((s8 *)*(u32 *)(((1060) + ((u8 *)v2))))[v10]) == (v8))) {
            ((s32 *)*(u32 *)((u8 *)v2 + 1064))[v10++] = v11;
            v11++;
        }
        v11 <<= 1;
        v8++;
    }
    return 0;
}
#pragma opt_propagation reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

