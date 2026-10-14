/* Non-matching: best partial attempt (72.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern s32 fn_1_F21B8(s32);
extern u32 ghost_test_flag(s32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4630(u32, u32, const char *, int);
extern void fn_1_F1960(void *, void *, u32);
extern void fn_1_F1D70(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(u32, u32, u32);
extern int sprintf(char *, const char *, ...);

void fn_1_EC910(void) {
    u8 *bss = (u8 *)&lbl_1_bss_7B180;
    u8 *data = lbl_1_data_3E358;
    char tempA[0x100];
    char tempB[0x100];
    char tempC[0x100];
    u32 i;
    u32 j;
    u32 *slot;
    void *buf;

    if (*(u32 *)(bss + 0x24) != 0) {
        *(u8 *)(bss + 0x174e) = 0;
        *(u32 *)(bss + 0x24) = 0;
        *(u8 *)(bss + 0x16cc) = 0xff;
        if (fn_1_F21B8(lbl_1_bss_8B3A0.unk_90) && ghost_test_flag(0)) {
            *(u8 *)(bss + 0x16cc) = lbl_1_bss_8B3A0.unk_90;
            sprintf(tempA, (const char *)(data + 0x31c),
                    (u8)lbl_1_bss_8B3A0.unk_90);
        }

        for (i = 0; i < 5; i++) {
            slot = (u32 *)(bss + 0x1600 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x85a); *slot = 0; }
            slot = (u32 *)(bss + 0x1614 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x85b); *slot = 0; }
            slot = (u32 *)(bss + 0x1628 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x85c); *slot = 0; }
            slot = (u32 *)(bss + 0x163c + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x85d); *slot = 0; }
            slot = (u32 *)(bss + 0x1650 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x85e); *slot = 0; }
            slot = (u32 *)(bss + 0x1664 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x85f); *slot = 0; }
            slot = (u32 *)(bss + 0x1678 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x860); *slot = 0; }
            slot = (u32 *)(bss + 0x168c + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x861); *slot = 0; }
            slot = (u32 *)(bss + 0x16a0 + i * 4);
            if (*slot) { fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x862); *slot = 0; }
            sprintf(tempB, (const char *)(data + 0x354), i);
        }

        *(u8 *)(bss + 0x174e) = 0;
        for (i = 0; i < 5; i++) {
            *(s16 *)(bss + 0x17d0 + i * 2) = -1;
            *(u32 *)(bss + 0x17dc + i * 4) = 0;
            *(u8 *)(bss + 0x17f0 + i * 3) = 0;
        }
        for (i = 0; i < 127; i++) {
            if (ghost_test_flag(i + 1)) {
                u8 *rec = (u8 *)(bss + 0x2c + i * 0x28);
                u8 n = *(u8 *)(bss + 0x174e);
                *(u8 *)(bss + 0x17f0 + n * 3) = rec[5];
                *(u8 *)(bss + 0x17f1 + n * 3) = rec[6];
                *(u16 *)(bss + 0x17d0 + n * 2) = *(u8 *)rec;
                *(u32 *)(bss + 0x17dc + n * 4) = rec[4];
                *(u8 *)(bss + 0x17f2 + n * 3) = rec[7];
                buf = (void *)fn_1_4630(lbl_801A6410, 0x3ec0, (const char *)(data + 0x2d4), 0x87f);
                fn_80008BEC(buf, 0, 0x3ea8);
                {
                    u32 *src = (u32 *)rec;
                    u32 *dst = (u32 *)buf;
                    for (j = 0; j < 10; j++) dst[j] = src[j];
                }
                fn_80008BA8((u32)((u8 *)buf + 0x28), *(u32 *)(bss + 0x1404 + i * 4),
                            *(u16 *)(rec + 0x18) << 4);
                fn_1_F1960((void *)(0xf24000 + n * 0x3ec0), buf, 0x3ec0);
                fn_1_46B4(lbl_801A6410, (u32)buf, (const char *)(data + 0x2d4), 0x895);
                (*(u8 *)(bss + 0x174e))++;
            }
        }
        *(u8 *)(bss + 0x1754) = *(u8 *)(bss + 0x174e);
        if (fn_1_F21B8(lbl_1_bss_8B3A0.unk_90) && ghost_test_flag(0))
            (*(u8 *)(bss + 0x174e))++;

        for (i = 0; i < 127; i++) {
            slot = (u32 *)(bss + 0x1404 + i * 4);
            if (*slot != 0) {
                fn_1_46B4(lbl_801A6410, *slot, (const char *)(data + 0x2d4), 0x8b0);
                sprintf(tempC, (const char *)(data + 0x3d4), i);
                *slot = 0;
            }
        }
        fn_1_F1D70();
    }
}
