/* Non-matching: best partial attempt (98.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/story/story_mode.h"

extern const f32 lbl_7_rodata_784;
extern f32 lbl_7_rodata_788[4];
extern s32 fn_7_4648(void *, void *);
extern u32 fn_7_4FD0(void *, void *);
extern void OSReport(const char *, ...);

static inline f32 clamp_value(f32 x) {
    if (x < lbl_7_rodata_784) return lbl_7_rodata_784;
    if (x > lbl_7_rodata_788[0]) return lbl_7_rodata_788[0];
    return x;
}

#pragma opt_propagation off
void fn_7_41FC(void *arg0) {
    Obj_7_bss_1960 *p_lbl_7_bss_1960;
    void * v25;
    s32 *v3;
    u32 v4;
    u8 *v14;
    u32 v13;
    void *v0;
    u8 v17;
    s32 v21;
    p_lbl_7_bss_1960 = &lbl_7_bss_1960;
    v0 = arg0;
    v14 = (u8 *)p_lbl_7_bss_1960->unk_30;
    v3 = (s32 *)((u8 *)v0 + 512);
    for (v4 = 0; v4 < 8; v4++, v3++) {
        if (!__rlwnm(p_lbl_7_bss_1960->unk_C, ((31) & ((1 + v4))), 31, 31) && *v3 >= 0)
            (*v3)--;
    }
    v13 = 0;
    while (*(u16 *)v14 != 5) {
        v21 = 1;
        while (*(u16 *)v14 <= 3) {
            if (v13 >= 4096) {
                OSReport((const char *)"Too Many Scenario Trigger\n\n");
                return;
            }
            if (__rlwnm(((u32 *)v0)[v13 >> 5], ((31) & (((31 & v13) + 1))), 31, 31)) {
                v21 = 0;
                break;
            }
            if (*(u16 *)v14 == 2 || *(u16 *)v14 == 3) {
                if (fn_7_4648(v0, v14)) {
                    v21 = 0;
                    break;
                }
            } else {
                if (!fn_7_4648(v0, v14)) {
                    v21 = 0;
                    (void) v21;  /* fzgx: keeps the web at its definition */
                    break;
                }
            }
            v14 += 24;
            v13 = ((1) + (v13));
        }
        if (v21) {
            u8 *v18 = v14 - 24;
            u32 v22 = v13 - 1;
            while (*(u16 *)v18 <= 3 && v22 != -1) {
                if (*(u16 *)v18 == 0 || *(u16 *)v18 == 2)
                    ((u32 *)v0)[v22 >> 5] |= 0x80000000U >> (31 & v22);
                v18 -= 24;
                v22--;
            }
            while (*(u16 *)v14 == 4) {
                fn_7_4FD0(v0, v14);
                v14 += 24;
            }
        } else {
            while (*(u16 *)v14 <= 3) {
                v14 += 24;
                v13 = v13 + 1;
            }
            while (*(u16 *)v14 == 4)
                v14 += 24;
        }
    }
    {
        u8 *v16 = &p_lbl_7_bss_1960->unk_18;
        {
    u8 fzgx_loop_v17_2318;
for (fzgx_loop_v17_2318 = 0; fzgx_loop_v17_2318 < 2; fzgx_loop_v17_2318++) {
            u32 v15_index = fzgx_loop_v17_2318;
            if (v16[v15_index]) {
                u32 v24 = v15_index * 4;
                void *v15 = &p_lbl_7_bss_1960->unk_24;
                v25 = &p_lbl_7_bss_1960->unk_1C;
                *(f32 *)((u8 *)v25 + v24) = *(f32 *)((u8 *)v25 + v24) + *(f32 *)((u8 *)v15 + v24);
                *(f32 *)((u8 *)v25 + v24) = clamp_value(*(f32 *)((u8 *)v25 + v24));
            }
        }
    v17 = fzgx_loop_v17_2318;
}
    }
}
#pragma opt_propagation reset
