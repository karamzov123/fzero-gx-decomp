/* Non-matching: best partial attempt (98.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sound.h"

struct Counter { u8 count; u8 idle; };
#define COUNTERS(base) ((struct Counter *)((u32)(base) + 0x8D0))
extern f32 fn_1_8652C(s32);
extern const f32 lbl_1_rodata_454C;
extern void fn_80067344(s32, s32, u32, u32);
extern u32 fn_80067898(u32);
extern u32 fn_1_864E8(s32);

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
void fn_1_A3A1C(void) {
    u8 *v0;
    u8 *v7;
    s32 v1;
    s32 v2;
    u8 v3;
    s32 v4;
    u8 *v5;
    u8 *p_lbl_1_bss_6EA98;
    u32 t0;
    s32 lab_t0;
    s32 lab_t0_;
    u8 *v6;
    u8 *cp;

    p_lbl_1_bss_6EA98 = (u8 *)&lbl_1_bss_6EA98;
    v0 = p_lbl_1_bss_6EA98 + 0x74C;
    v1 = 0;
    while ((s8)v1 < *(s8 *)(p_lbl_1_bss_6EA98 + 0x82C)) {
        v2 = (*((1) + (v0)));
        t0 = fn_1_864E8(v2);
        if ((t0 & 0x10) && fn_1_8652C(v2) > lbl_1_rodata_454C) {
            v3 = (*((2) + (v0)));
            (void) v3;  /* fzgx: keeps the web at its definition */
            if (v3 != 0) {
                cp = (u8 *)p_lbl_1_bss_6EA98;
                cp = cp + 0x8D0;
                if ((s8)cp[v2 * 2] == 0) {
                    if (t0 & 0x200) {
                        lab_t0 = 1;
                        lab_t0_ = lab_t0;
                        fn_80067344(lab_t0_, 16, 0xB0270000, v3);
                        if ((*((0x740) + (p_lbl_1_bss_6EA98))) == 0 && *(u32 *)(((0x744) + (p_lbl_1_bss_6EA98))) <= 45) {
                            fn_80067898(0xA9090700);
                        }
                    } else {
                        v4 = v3 + 50;
                        v4 = v4 < 1 ? 1 : v4 > 127 ? 127 : v4;
                        lab_t0 = 1;
                        fn_80067344(lab_t0, 16, 0xB0270000, (u8)v4);
                        if ((*((0x740) + (p_lbl_1_bss_6EA98))) == 0 && *(u32 *)(((0x744) + (p_lbl_1_bss_6EA98))) <= 45) {
                            fn_80067898(0xA9090800);
                        }
                    }
                }
            }
            lab_t0 = v2 * 2;
            v5 = (u8 *)COUNTERS(p_lbl_1_bss_6EA98);
            v5 += lab_t0;
            v5[0]++;
            v5[1] = 0;
            if ((s8)(*((0) + (v5))) > 6) v5[0] = 0;
        } else {
            lab_t0 = v2 * 2;
            v6 = (u8 *)COUNTERS(p_lbl_1_bss_6EA98);
            v6 += lab_t0;
            v7 = v6;
            v7++;
            v6[1]++;
            if ((s8)v6[1] > 60) {
                v6[0] = 0;
                v7[0] = 60;
            }
        }
        v0 += 20;
        v1++;
    }
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset
