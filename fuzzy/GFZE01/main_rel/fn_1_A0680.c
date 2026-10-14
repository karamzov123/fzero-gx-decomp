/* Non-matching: best partial attempt (91.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "rel/main_rel/sound.h"
struct fn_1_A0680_state {
    u8 pad_0[8];
    u32 unk_8;
    u8 unk_C, unk_D, unk_E;
    u8 pad_F[0xD];
    u32 unk_1C;
    u8 pad_20[0xC];
    u8 unk_2C;
    u8 pad_2D;
    u8 unk_2E;
    u8 pad_2F[9];
    u32 unk_38;
    u8 pad_3C[4];
    u8 unk_40[0x700];
    u8 pad_740[12];
    struct { u8 unk_0, unk_1, unk_2; u8 pad_3[17]; } unk_74C[4];
    u8 unk_79C[4];
    u8 unk_7A0, unk_7A1;
    u8 pad_7A2[2];
    u32 unk_7A4;
    s8 unk_7A8, unk_7A9, unk_7AA, unk_7AB, unk_7AC, unk_7AD;
    u8 pad_7AE[2];
    u8 unk_7B0;
};
extern u32 OSGetTick(void);
extern u32 fn_1_A0D7C(void);
extern u32 fn_8004CD70(u32, u32, u32);
extern void fn_1_A04C4(void);
extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_1_A2E24(u32, u32, s32);
extern void fn_80008BEC(void *, int, u32);
extern vu32 __OSBusClock;
#define __OSBusClock (&__OSBusClock)

#pragma opt_common_subs off
s16 fn_1_A0680(void) {
    struct fn_1_A0680_state *p_lbl_1_bss_6EA98;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    void *v9;
    void *v10;
    p_lbl_1_bss_6EA98 = (struct fn_1_A0680_state *)&lbl_1_bss_6EA98;
    if (p_lbl_1_bss_6EA98->unk_D == 0) {
        v0 = OSGetTick();
        p_lbl_1_bss_6EA98->unk_8 = v0;
        v0 = 0x10620000;
        p_lbl_1_bss_6EA98->unk_C = 1;
        v1 = v0 + 19923;
        while (p_lbl_1_bss_6EA98->unk_C != 0) {
            v0 = OSGetTick();
            v2 = p_lbl_1_bss_6EA98->unk_8;
            v0 = v0 - v2;
            if (v0 >= ((__OSBusClock[0] / 4 / 1000) * 100)) {
                p_lbl_1_bss_6EA98->unk_C = 0;
                p_lbl_1_bss_6EA98->unk_D = 1;
                fn_1_A04C4();
            }
        }
        fn_1_A0D7C();
        v0 = OSGetTick();
        p_lbl_1_bss_6EA98->unk_8 = v0;
        v0 = 0x10620000;
        p_lbl_1_bss_6EA98->unk_C = 1;
        v3 = v0 + 19923;
        while (p_lbl_1_bss_6EA98->unk_C != 0) {
            v0 = OSGetTick();
            v4 = p_lbl_1_bss_6EA98->unk_8;
            v0 = v0 - v4;
            if (v0 >= ((__OSBusClock[0] / 4 / 1000) * 100)) {
                p_lbl_1_bss_6EA98->unk_C = 0;
                p_lbl_1_bss_6EA98->unk_D = 1;
                fn_1_A04C4();
            }
        }
        v5 = p_lbl_1_bss_6EA98->unk_38;
        if (v5 != 0) {
            if (*(u32 *)v5 == 0) {
                v0 = 0x50000;
                v6 = v0 - 23992;
                v0 = 2;
                v0 = fn_8004CD70(v0, v5 + 16, v6);
                *(u32 *)p_lbl_1_bss_6EA98->unk_38 = v0;
            }
            v0 = p_lbl_1_bss_6EA98->unk_38;
            if (*(u32 *)(v0 + 4) == 0) {
                v7 = v0 + 0x50000;
                v0 = 0x50000;
                v8 = v0 - 23992;
                v0 = 2;
                v0 = fn_8004CD70(v0, v7 - 23976, v8);
                *(u32 *)(p_lbl_1_bss_6EA98->unk_38 + 4) = v0;
            }
        }
        p_lbl_1_bss_6EA98->unk_2E = 1;
        p_lbl_1_bss_6EA98->unk_E = 1;
        fn_80008BEC((u8 *)p_lbl_1_bss_6EA98 + 1868, 0, 80);
        for (v0 = 0; v0 < 4; v0++) {
            p_lbl_1_bss_6EA98->unk_74C[v0].unk_1 = 255;
            p_lbl_1_bss_6EA98->unk_74C[v0].unk_2 = 0;
            p_lbl_1_bss_6EA98->unk_79C[v0] = 0;
        }
        fn_80008BEC((u8 *)p_lbl_1_bss_6EA98 + 64, 0, 1792);
        v2 = (u8)p_lbl_1_bss_6EA98->unk_7AD;
        p_lbl_1_bss_6EA98->unk_1C = 0;
        p_lbl_1_bss_6EA98->unk_7A0 = 0;
        p_lbl_1_bss_6EA98->unk_7A1 = 0;
        p_lbl_1_bss_6EA98->unk_7A4 = 0;
        p_lbl_1_bss_6EA98->unk_2C = 255;
        p_lbl_1_bss_6EA98->unk_7A8 = 0;
        p_lbl_1_bss_6EA98->unk_7A9 = 0;
        p_lbl_1_bss_6EA98->unk_7AA = 0;
        p_lbl_1_bss_6EA98->unk_7AB = 0;
        p_lbl_1_bss_6EA98->unk_7AC = 1;
        if (v2 != 0) {
            fn_1_A2E24(16, 0xA0010000, 0);
        } else {
            fn_1_A2E24(16, 0xA0010000, 127);
        }
        fn_1_A2E24(16, 0xA0100000, 127);
        fn_1_A2DF4(16, (void *)0xA5100000, 0);
        fn_1_A2DF4(0, (void *)0xA6000000, 0);
        fn_1_A2DF4(1, (void *)0xA6000000, 0);
        fn_1_A2DF4(2, (void *)0xA6000000, 0);
        fn_1_A2DF4(3, (void *)0xA6000000, 0);
        fn_1_A2DF4(6, (void *)0xA6000000, 0);
        fn_1_A2DF4(7, (void *)0xA6000000, 0);
        fn_1_A2DF4(5, (void *)0xA6000000, 0);
        fn_1_A2DF4(4, (void *)0xA6000000, 0);
        v0 = (u32)((u8 *)p_lbl_1_bss_6EA98 + 1968);
        p_lbl_1_bss_6EA98->unk_7B0 = 9;
        *(u8 *)(v0 + 1) = 9;
        *(u8 *)(v0 + 2) = 9;
        *(u8 *)(v0 + 3) = 9;
    }
    return (u32)v0;
}
#pragma opt_common_subs reset

