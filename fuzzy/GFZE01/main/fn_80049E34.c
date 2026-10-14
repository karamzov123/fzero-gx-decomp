/* Non-matching: best partial attempt (82.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80049E34_Arg0 {
    u8 pad_0[0x44];
    u32 unk_44;
    u8 pad_48[0xC];
    u32 unk_54;
    u8 pad_58[0x28];
    u32 unk_80[1];
};

extern const f64 lbl_80090980;

static inline u32 fn_80049E34_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_80049E34(struct fn_80049E34_Arg0 *arg0, u32 arg1) {
    u32 v0;
    u32 v10;
    u32 v2;
    u32 v6;
    u32 v9;
    s32 v22;
    u32 v11;
    u32 v12;
    s32 v13;
    s32 v23;
    s32 v15;
    s32 v16;
    s32 v28_2;
    s32 v17;
    s32 v18;
    s32 v1;
    s32 v14;
    s32 v25;
    s32 v26;
    s32 v27;
    s32 v28;
    s32 v29;
    s32 v30;
    u32 fzgx_loop_v9_781;
    v0 = ((u32)arg0 + (arg1 << 6));
    v1 = 8 / (s32)arg0->unk_54;
    v2 = fn_80049E34_array_read(arg0->unk_80, arg1);
    v10 = v0 + 272;
{
    u32 fzgx_loop_v6_781;
    v11 = v0 + 400;
    fzgx_loop_v6_781 = ((u32)arg0 + (arg1 << 4) + 680) - 1;
    v12 = v0 + 528;
    fzgx_loop_v9_781 = v2;
    v28 = 0;
    v13 = 0;
    while (v13 < (s32)arg0->unk_44) {
        if (v2 == 0) {
            v14 = 0;
        } else {
            v14 = *(s16 *)(fzgx_loop_v9_781 + 24);
        }
        *(s16 *)v10 = v14;
        v15 = (s32)(*(f64 *)(v2 + 128) * (f64)*(s16 *)v10);
        v16 = -32768;
        if (v15 >= -32768) {
            v16 = v15;
        }
        if (v16 > 32767) {
            v17 = 32767;
        } else {
            v17 = -32768;
            if (v15 >= -32768) {
                v17 = v15;
            }
        }
        *(s16 *)v11 = v17;
        if (*(s16 *)v11 < 0) {
            v18 = (v17 - 2340) / 4681;
        } else {
            v18 = (v17 + 2340) / 4681;
        }
        v22 = -8;
        if (v18 >= -8) {
            v22 = v18;
        }
        if (v22 < 7) {
            v23 = -8;
            if (v18 >= -8) {
                v23 = v18;
            }
        } else {
            v23 = 7;
        }
        v25 = (s32)(*(f64 *)(v2 + 128) * (f64)(v23 * *(s16 *)(v2 + 124)));
        v26 = -32768;
        if (v25 >= -32768) {
            v26 = v25;
        }
        if (v26 > 32767) {
            v27 = 32767;
        } else {
            v27 = -32768;
            if (v25 >= -32768) {
                v27 = v25;
            }
        }
        *(s16 *)v12 = v27;
        if (v13 % v1 == 0) {
            *(u8 *)++fzgx_loop_v6_781 = 0;
            v28_2 = 1;
        }
        v0 = arg0->unk_54;
        v29 = v0;
        v30 = 8 - v29;
        *(u8 *)fzgx_loop_v6_781 |= (s8)(((s32)(u8)(v23 << v30) >> v30) << (v29 * (v1 - v28_2)));
        v28_2++;
        fzgx_loop_v9_781 += 2;
        v10 += 2;
        v11 += 2;
        v12 += 2;
        v13++;
    }
    v6 = fzgx_loop_v6_781;
    v9 = fzgx_loop_v9_781;
}
}
#pragma opt_dead_assignments reset

