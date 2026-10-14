/* Non-matching: best partial attempt (95.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

struct fn_1_14F18_Arg4 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
};
struct fn_1_14F18_lbl_801A66CC {
    u32 unk_0;
};
extern f32 fn_1_1FFA0(void *, void *, void *, void *, void *, void *);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6D4[5];
extern struct fn_1_14F18_lbl_801A66CC lbl_801A66CC;

#pragma opt_common_subs off
#pragma opt_dead_assignments off
s32 fn_1_14F18(void *arg0, void *arg1, void *arg2, void *arg3, struct fn_1_14F18_Arg4 *arg4, s32 arg5, u32 arg6, f32 arg7) {
    s32 v20;
    f32 fzgx_live;
    void ** v21;
    f32 * v19_2;
    struct fn_1_14F18_lbl_801A66CC *p_lbl_801A66CC;
    f32 v0, v3, v4, v5, v6, v7, v22;
    f32 *v10;
    f32 *v16;
    f32 *v18;
    void *loc_34[5];
    f32 loc_28[3];
    f32 loc_1C[3];
    f32 loc_10[3];
    f32 loc_C;
    f32 loc_8;
    s32 i;
    v0 = arg4->unk_4 * ((f32 *)arg2)[0];
    v0 = arg4->unk_8 * ((f32 *)arg2)[1] + v0;
    v0 = arg4->unk_C * ((f32 *)arg2)[2] + v0;
    if (v0 > lbl_1_rodata_6D0 && !(arg6 & 0x400000)) return 0;
    v3 = arg4->unk_4 * ((f32 *)arg0)[0];
    v3 = arg4->unk_8 * ((f32 *)arg0)[1] + v3;
    v3 = arg4->unk_C * ((f32 *)arg0)[2] + v3;
    v4 = v3 + arg4->unk_0;
    v5 = v4;
    v5 /= v0;
    if (lbl_1_rodata_6D4[0] < v5 || ((loc_C = v5), (*(u32 *)&loc_C & 0x7F800000) == 0x7F800000)) return 0;
    v6 = (v4 - arg7) / v0;
    v7 = v5;
    if (v6 < lbl_1_rodata_6D0 || ((loc_8 = v6), (*(u32 *)&loc_8 & 0x7F800000) == 0x7F800000)) return 0;
    if (v5 < lbl_1_rodata_6D0) v7 = lbl_1_rodata_6D0;
    psvec_scale_add(arg0, arg2, -v7, loc_28);
    v21 = &loc_34[1];
{
    f32 * v19;
    v19 = (f32 *)(arg4 + 1);
    if (arg5 > 1) {
        u32 count;
        for (count = arg5 - 1; count != 0; count--) {
            *v21++ = v19;
            v19 += 3;
        }
    }
    }
    v16 = (f32 *)(arg4 + 1);
    loc_34[arg5] = v16;
    v18 = v16 + arg5 * 3;
    v19_2 = v16;
    v20 = 0;
    v21 = loc_34;
    v22 = arg7 * arg7;
    p_lbl_801A66CC = &lbl_801A66CC;
    while (v20 < arg5) {
        psvec_sub(loc_28, v19_2, (u8 *)p_lbl_801A66CC->unk_0 + 212);
        {
            f32 *p = (f32 *)p_lbl_801A66CC->unk_0;
            f32 v29;
            v29 = p[53] * v18[0];
            v29 = p[54] * v18[1] + v29;
            v29 = p[55] * v18[2] + v29;
            if (v29 < lbl_1_rodata_6D0) {
                if (fn_1_1FFA0(arg0, arg1, v19_2, v21[1], loc_1C, loc_10) > v22) return 0;
            }
        }
        v21++;
        v20++;
        v19_2 += 3;
        v18 += 3;
    }
    if (v6 > lbl_1_rodata_6D4[0]) v6 = lbl_1_rodata_6D4[0];
    {
        f32 v30 = lbl_1_rodata_6D4[0];
        psvec_scale_add(arg0, arg2, -v6, arg0);
        *(f32 *)arg3 = v30 - v6;
    }
    return 1;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

