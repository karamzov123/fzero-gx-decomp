/* Non-matching: best partial attempt (97.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_2B6B0_Copy64 { u32 a[17]; };
extern int fn_12_24990(u32);
extern int fn_12_24A88(void *, int);
extern int fn_12_2F210(void *, int, int, void *, u32);
extern void fn_12_24970(void *);
extern void fn_12_24950(void *);
extern u32 lbl_12_bss_7C64[137];
extern void fn_12_248D4(void *);
extern void fn_12_22888(u32);
extern int fn_12_2F264(void *, int);
extern void *fn_12_57F0(void *, const void *, u32);
extern s32 fn_12_2BAE0(void *, s32);
extern void fn_12_21D40(void *, int, int);

void fn_12_2B6B0(u32 arg0) {
    u32 *p_lbl_12_bss_7C64;
    int v0;
    u32 v4;
    int v3;
    u32 v5;
    u32 loc_6C[100];
    struct { u32 a[7]; } loc_C;
    struct fn_12_2B6B0_Copy64 loc_28;
    int i;
    u32 loc_8;
    int v3_2;
    if (fn_12_24990(arg0)) {
        fn_12_24A88(0, 0xff000131);
        return;
    }
    if (*(s32 *)(arg0 + 0x48) != 1) {
        if (*(s32 *)(arg0 + 0x48) == 4 &&
            (v0 = fn_12_2F210((void *)arg0, 7, 7, 0, 0)) != 0) {
        } else {
            *(u32 *)(arg0 + 0x48) = 1;
            *(u32 *)(arg0 + 0x4c) = 1;
            v0 = 0;
        }
        if (v0 == 0) {
            fn_12_24970(&loc_8);
            (p_lbl_12_bss_7C64 = lbl_12_bss_7C64)[0x1fc / 4] = 1;
            v4 = 0;
            loc_28 = *(struct fn_12_2B6B0_Copy64 *)arg0;
            v3 = *(s32 *)(arg0 + 0x9c0);
            if (v3 != 0) {
                if (fn_12_24990(arg0)) {
                    fn_12_24A88(0, 0xff000134);
                } else {
                    fn_12_2F210((void *)arg0, 0, 9, &loc_C, 0);
                }
                v4 = loc_C.a[5];
            }
            fn_12_248D4((void *)(arg0 + 0x78));
            fn_12_22888(arg0);
            *(u32 *)(arg0 + 0x48) = 0;
            *(u32 *)(arg0 + 0x4c) = 0;
            if (fn_12_2F264((void *)arg0, 4) == 0) {
                fn_12_57F0(loc_6C, (void *)(arg0 + 0xb30), 0x190);
                v5 = fn_12_2BAE0(&loc_28, 0);
                if (v5 == 0) {
                    fn_12_24A88(0, 0xff000202);
                } else {
                    fn_12_57F0((void *)(v5 + 0x9a0), loc_6C, 0x190);
                    fn_12_57F0((void *)(v5 + 0xb30), loc_6C, 0x190);
                    if (v3 != 0) {
                        if (fn_12_24990(v5)) {
                            v0 = fn_12_24A88(0, 0xff000134);
                        } else {
                            v0 = fn_12_2F210((void *)v5, 0, 9, &loc_C, 0);
                        }
                        if (0 == v0) {
                            v3_2 = loc_C.a[5];
                            if (fn_12_24990(v5)) {
                                v0 = fn_12_24A88(0, 0xff000135);
                            } else {
                                v0 = fn_12_2F210((void *)v5, 0, 10, (void *)v4, v3_2);
                            }
                            if (v0 == 0) {
                                if (fn_12_24990(v5)) {
                                    fn_12_24A88(0, 0xff000135);
                                } else {
                                    fn_12_21D40((void *)v5, *(int *)(v5 + 0x1ab4), 1);
                                    *(u32 *)(v5 + 0x44) = 1;
                                }
                            }
                        }
                    }
                }
            }
            p_lbl_12_bss_7C64[0x1fc / 4] = 0;
            fn_12_24950(&loc_8);
        }
    }
    fn_12_248D4((void *)(arg0 + 0x78));
    fn_12_22888(arg0);
    *(u32 *)(arg0 + 0x48) = 0;
    *(u32 *)(arg0 + 0x4c) = 0;
    fn_12_2F264((void *)arg0, 4);
    {
        u32 *p = &lbl_12_bss_7C64[0x204 / 4];
        for (i = 0; i < 8; i++, p++) {
            if (*p == arg0) *p = 0;
        }
    }
}
