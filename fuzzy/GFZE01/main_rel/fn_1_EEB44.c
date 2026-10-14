/* Non-matching: best partial attempt (93.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E358[];

extern int sprintf(char *, const char *, ...);
extern void fn_80008BEC(void *dst, int value, int size);
extern u8 *fn_1_3F0D8(u32, f32 *, u8 *);
extern void fn_1_8645C(int, void *);
extern u32 lbl_8006DBAC(void *);
extern void fn_8006F5C4(s16 *, s16 *, s16 *);
extern s32 fn_1_F17B4(const void *);
extern void ghost_pack_bits(u32 *, const u32 *, const u32 *, const u32 *);
extern u8 fn_1_3F114(void);
extern void *fn_1_86254(int);
extern u32 fn_1_12A734(u32);
extern void fn_1_7F934(void *);
extern void fn_1_46B4(u32, u32, const void *, u32);
extern void fn_1_14DBCC(void *);
extern void fn_1_984F0(void *);

#pragma opt_loop_invariants on
void fn_1_EEB44(void) {
    char sp150[0x100];
    char sp50[0x100];
    u32 sp4C;
    u16 sp3C[0x10];
    u8 sp2C[0x8];
    u8 sp20[3];
    f32 sp1C;
    u32 sp18;
    u32 sp14;
    u32 sp10;
    s16 spE;
    s16 spC;
    s16 spA;
    u16 sp8;

    u8 *bss;
    u8 *data;
    u32 i;
    s32 k;
    void *res;

    data = lbl_1_data_3E358;
    bss = (u8 *)&lbl_1_bss_7B180;

    if (*(s32 *)(bss + 8) == 0 || *(u32 *)(bss + 0x38ac) == 0) {
        return;
    }
    if (*(s32 *)(bss + 0x3894) != 0) {
        *(u32 *)(data + 0x1d8) = 0;
        return;
    }

    for (i = 0; i < 5; i++) {
        fn_80008BEC(bss + 0x18d8 + i * 0x30, 0, 0x30);
    }

    if ((s16)lbl_1_bss_960 == 9) {
        if (*(s32 *)(bss + 0x16c8) >= 0 && *(s32 *)(bss + 0x17cc) == 0) {
            u8 *ptr = fn_1_3F0D8(0, &sp1C, (u8 *)&sp8);
            u8 *r9 = *(u8 **)(bss + 0x16b4);
            u32 t1 = ptr[0x1e0] * 60000 + ptr[0x1e1] * 1000 + *(u16 *)(ptr + 0x1e2);
            u32 t2 = r9[0x24] * 60000 + r9[0x25] * 1000 + *(u16 *)(r9 + 0x26);
            if (t1 >= t2) {
                bss[0x174c] = 3;
            } else {
                bss[0x174c] = 1;
            }
        } else if (*(s32 *)(bss + 0x17cc) != 0) {
            bss[0x174c] = 0;
        } else if (bss[0x174e] == 0) {
            bss[0x174c] = 0;
        }
    } else {
        if (bss[0x174e] != 0 && *(s32 *)(bss + 0x17cc) == 0) {
            u8 *ptr = fn_1_3F0D8(0, &sp1C, (u8 *)&sp8);
            u32 t1 = ptr[0x1e0] * 60000 + ptr[0x1e1] * 1000 + *(u16 *)(ptr + 0x1e2);
            s16 count = bss[0x174e];
            u8 **r8 = (u8 **)(bss + 0x16b4);
            s32 j;
            bss[0x174c] = 1;
            for (j = count; j > 0; j--) {
                u8 *r5 = *r8;
                u32 t2 = r5[0x24] * 60000 + r5[0x25] * 1000 + *(u16 *)(r5 + 0x26);
                if (t1 >= t2) {
                    bss[0x174c] = 3;
                }
                r8++;
            }
        } else if (*(s32 *)(bss + 0x17cc) != 0) {
            bss[0x174c] = 0;
        } else if (bss[0x174e] == 0) {
            bss[0x174c] = 0;
        }
    }

    if (bss[0x16cc] != 0xff) {
        u8 *ptr = fn_1_3F0D8(0, &sp1C, (u8 *)&sp8);
        u32 t1 = ptr[0x1e0] * 60000 + ptr[0x1e1] * 1000 + *(u16 *)(ptr + 0x1e2);
        u8 *r4;
        u32 t2;

        if (*(s32 *)(bss + 0x20) != 0) {
            r4 = ((u8 **)(bss + 0x16b4))[bss[0x174e] - 2];
            t2 = r4[0x24] * 60000 + r4[0x25] * 1000 + *(u16 *)(r4 + 0x26);
        } else {
            r4 = ((u8 **)(bss + 0x16b4))[bss[0x174e] - 1];
            t2 = r4[0x24] * 60000 + r4[0x25] * 1000 + *(u16 *)(r4 + 0x26);
        }
        if (t2 > t1) {
            bss[0x174d] = 1;
        } else {
            bss[0x174d] = 3;
        }
    } else {
        bss[0x174d] = 0;
    }

    *(s32 *)(bss + 0x3894) = 1;
    fn_1_8645C(0, sp20);

    for (k = *(s32 *)bss - 3; (u32)k < *(u32 *)bss; k++) {
        if (k > 0 && k < 0x7080) {
            *(u8 *)(*(u32 *)(bss + 0x16e8) + k) = 1;
        }
    }

    lbl_8006DBAC(sp20);
    fn_8006F5C4(&spA, &spC, &spE);

    (*(u8 **)(bss + 0x38ac))[2] = (s32)spE >> 8;
    *(s16 *)(*(u8 **)(bss + 0x38ac) + 4) = spC;
    (*(u8 **)(bss + 0x38ac))[3] = (s32)spA >> 8;
    (*(u8 **)(bss + 0x38ac))[0] = *(u32 *)bss - *(u32 *)(bss + 4);

    sp18 = fn_1_F17B4(sp2C);
    sp14 = fn_1_F17B4(sp3C);
    sp10 = fn_1_F17B4(&sp4C);

    ghost_pack_bits((u32 *)(*(u8 **)(bss + 0x38ac) + 16), &sp18, &sp14, &sp10);

    (*(u8 **)(bss + 0x38ac))[1] = fn_1_3F114();
    *(u16 *)(*(u8 **)(bss + 0x38ac) + 6) = 0;
    **(u8 **)(bss + 0x38b0) = 1;

    *(u8 **)(bss + 0x38ac) += 0x8;
    *(u8 **)(bss + 0x38b0) += 1;
    *(u32 *)(bss + 0x1820) += 1;
    *(u32 *)(bss + 4) = *(u32 *)bss;
    *(u32 *)bss += 1;
    *(u32 *)(bss + 0xc) = 1;

    *(u16 *)(data + 0x1dc) = 0;
    if ((res = fn_1_86254(0)) != NULL) {
        *(s16 *)(data + 0x1dc) = *(s16 *)((u8 *)res + 6);
    }

    for (i = 0; i < 5; i++) {
        if (((void **)(bss + 0x1794))[i] != NULL) {
            u8 *obj = ((void **)(bss + 0x1794))[i];
            if (*(s32 *)(obj + 0x324) != -1) {
                fn_1_12A734(*(u32 *)(obj + 0x324));
                *(s32 *)(((u8 *)((void **)(bss + 0x1794))[i]) + 0x324) = -1;
            }
            fn_1_7F934(((void **)(bss + 0x1794))[i]);
            fn_1_46B4(lbl_801A6410, (u32)((void **)(bss + 0x1794))[i], data + 0x2d4, 0xd89);
            sprintf(sp150, (char *)(data + 0x348), i);
            ((void **)(bss + 0x1794))[i] = NULL;
        }
        if (((void **)(bss + 0x17a8))[i] != NULL) {
            fn_1_14DBCC(((void **)(bss + 0x17a8))[i]);
            fn_1_46B4(lbl_801A6410, (u32)((void **)(bss + 0x17a8))[i], data + 0x2d4, 0xd93);
            sprintf(sp50, (char *)(data + 0x338), i);
            ((void **)(bss + 0x17a8))[i] = NULL;
        }
    }

    for (i = 0; i < bss[0x174e]; i++) {
        fn_1_984F0((((i * 0x620) + (0x19c8)) + (bss)));
    }

    *(u32 *)(data + 0x1d8) = 0;
}
#pragma opt_loop_invariants reset

