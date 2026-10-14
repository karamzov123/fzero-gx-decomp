/* Non-matching: best partial attempt (91.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Big { s16 e[220]; };

struct fz_bss {
    u8 pad_0[0x4900];
    u32 unk_4900;
    u8 pad_4904[0xC];
    u32 unk_4910;
};

extern struct fz_bss lbl_1_bss_7F0C0;
extern void fn_1_F9E38(void);
extern u8 lbl_1_rodata_6E38[440];
extern void fn_80008BA8(void *, void *, s32);
extern s32 ghost_test_record_flag0(s32);
extern void ghost_set_record_flag1(s32);

static inline s16 *fn_1_F9A80_array_read(s16 *array) { return array; }
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void fn_1_F9A80(void) {
    u32 v0, v1;
    s16 j, n, k, key;
    s16 *pC, *pA, *pB;
    s16 i;
    s16 Aout[6], Bout[6], Cout[6];
    struct Big A, B, C;

    fn_1_F9E38();
    v0 = lbl_1_bss_7F0C0.unk_4900;
    v1 = lbl_1_bss_7F0C0.unk_4910;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFFEFFFF;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFFCFFFF;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFF8FFFF;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFF0FFFF;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFE0FFFF;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFC0FFFF;
    lbl_1_bss_7F0C0.unk_4900 = v0 & 0xFFC0FFFF;
    lbl_1_bss_7F0C0.unk_4910 = v1 & 0xBFFFFFFF;
    lbl_1_bss_7F0C0.unk_4910 = lbl_1_bss_7F0C0.unk_4910 & 0xF8FFFFFF;

    pA = A.e;
    pB = B.e;
    for (i = 0; i < 44; i++) {
        A = *(struct Big *)lbl_1_rodata_6E38;
        fn_80008BA8(Aout, pA, 10);
        B = *(struct Big *)lbl_1_rodata_6E38;
        fn_80008BA8(Bout, pB, 10);
        for (j = 0; ; j++) {
            k = 0;
            key = Bout[1];
            n = k;
            pC = C.e;
            while (k < 44) {
                C = *(struct Big *)lbl_1_rodata_6E38;
                fn_80008BA8(Cout, pC, 10);
                if (Cout[1] == key) {
                    if (n != j) {
                        n++;
                    } else {
                        goto L_found;
                    }
                }
                pC += 5;
                k++;
            }
            k = -1;
        L_found:
            if (i == k) break;
        }
        if (fn_1_F9A80_array_read(Aout)[1] != 2) {
            if (ghost_test_record_flag0(fn_1_F9A80_array_read(Aout)[4]))
                ghost_set_record_flag1(fn_1_F9A80_array_read(Aout)[4]);
        }
        pA += 5;
        pB += 5;
    }
}
#pragma opt_propagation reset

#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
