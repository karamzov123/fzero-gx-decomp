/* Non-matching: best partial attempt (97.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct S9F8 {
    u8 pad_0[8];
    u16 f8;
    u8 pad_1[0x14 - 0xA];
} S9F8;

typedef struct S9C8 {
    u8 pad_0[0xA];
    s8 fA;
    u8 pad_1[1];
} S9C8;

typedef struct SelState {
    u8 pad_0[0x94];
    u32 flags_94;
    u32 bits_98;
    u8 pad_9C[2];
    u8 idx_9E;
    u8 pad_9F[0xA1];
    u32 field_140;
} SelState;

extern s32 lbl_10_bss_14;
extern SelState lbl_1_bss_8B3A0;
extern u16 lbl_1_bss_96A;
extern S9C8 lbl_1_bss_9C8[];
extern S9F8 lbl_1_bss_9F8[];
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern u32 lbl_1_bss_6EAB4;

extern s32 fn_1_4C10(void);
extern void fn_1_12F150(s16, u32, u32);
extern void fn_1_12F1E8(s32);
extern s32 fn_1_12F228(void);
extern void fn_1_4A00(s32, u32, u32);

void fn_10_CB20(void) {
    s32 ready;
    s16 i;
    u8 idx;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    if ((lbl_1_bss_8B3A0.field_140 & ((u32)1 << 31)) != 0 &&
        (lbl_1_bss_8B3A0.field_140 & ((u32)1 << 30)) == 0 &&
        (lbl_1_bss_8B3A0.flags_94 & 8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready != 0) {
        return;
    }

    if (lbl_10_bss_14 != -1) {
        s32 state = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        lbl_1_bss_96A = (u16)state;
        return;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].fA != -1) {
            if (((lbl_1_bss_8B3A0.bits_98 << (((u32)i + 1) & 31)) & 0x80000000u) != 0 &&
                ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.idx_9E].f8 >> 8) & 1) != 0) {
                fn_1_12F150(i, 2, 1);
            }
        }
    }

    if (((lbl_1_bss_9F8[lbl_1_bss_8B3A0.idx_9E].f8 >> 8) & 1) != 0) {
        fn_1_12F1E8(0);
    }

    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].fA != -1) {
            if (((lbl_1_bss_8B3A0.bits_98 << (((u32)i + 1) & 31)) & 0x80000000u) != 0 &&
                ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.idx_9E].f8 >> 12) & 1) != 0) {
                fn_1_12F150(i, 2, 1);
            }
        }
    }

    idx = lbl_1_bss_8B3A0.idx_9E;
    if (((lbl_1_bss_9F8[idx].f8 >> 12) & 1) != 0 || fn_1_12F228() != 0) {
        lbl_10_bss_14 = 0x19;
        fn_1_12F1E8(0);
        fn_1_4A00(0, (u32)(u8)lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        if (lbl_10_bss_14 == 0xE) {
            lbl_1_bss_6EAB4 |= 0x24;
        }
    }
}
