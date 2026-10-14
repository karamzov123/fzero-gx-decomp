/* Non-matching: best partial attempt (93.25% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_16_1A24_Rec {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};

struct fn_16_1A24_Mgr {
    s16 unk_0;
    u8 pad_2[0x6];
    s16 unk_8;
    u8 pad_A[0x2];
    s16 unk_C;
    s16 unk_E;
    u8 pad_10[0x20];
    s16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u8 pad_56[0x2];
    s16 unk_58;
};

typedef struct {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Data;

typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
} Sig_fn_1_41488_Owner;

extern const char *lbl_16_data_82B34[8];
extern struct fn_16_1A24_Rec lbl_1_bss_9F8[];
extern struct fn_16_1A24_Mgr lbl_1_bss_8B614;
extern s16 lbl_16_bss_860B8[4];
extern void fn_1_A2D84(u32);
extern s32 fn_1_FA1A8(s32);
extern s32 fn_1_95120(void *);
extern int fn_1_41488(Sig_fn_1_41488_Data *, const char *);
extern void fn_1_933D8(void *, void *, u32);
extern s16 fn_1_12CB04(s16);

s32 fn_16_1A24(void) {
    s16 delta;
    s16 ridx;
    s32 v;
    s16 max;
    s16 old;
    u32 id;
    s16 i;
    u8 *p;
    u8 *b;

    delta = 0;
    ridx = lbl_1_bss_8B614.unk_8;

    if (((lbl_1_bss_9F8[ridx].unk_8 >> 9) & 1) != 0) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    if (((lbl_1_bss_9F8[ridx].unk_8 >> 10) & 1) != 0) {
        fn_1_A2D84(0xA9010100);
        return 1;
    }
    if (((lbl_1_bss_9F8[ridx].unk_8 >> 11) & 1) != 0 &&
        fn_1_FA1A8(lbl_1_bss_8B614.unk_C) == 1) {
        fn_1_A2D84(0xA9010100);
        return 2;
    }

    if (((lbl_1_bss_9F8[ridx].unk_12 >> 8) & 1) != 0) {
        delta = 1;
    }
    if (((lbl_1_bss_9F8[ridx].unk_12 >> 9) & 1) != 0) {
        delta--;
    }

    v = lbl_1_bss_8B614.unk_30 + delta;
    v = (v > 3) ? 0 : ((v < 0) ? 3 : v);
    lbl_1_bss_8B614.unk_30 = (s16)v;
    if (delta != 0) {
        fn_1_A2D84(0xA9010000);
    }

    max = (s16)(lbl_16_bss_860B8[0] - 10);
    old = lbl_1_bss_8B614.unk_E;
    if (max > 0) {
        delta = 0;
        if (((lbl_1_bss_9F8[ridx].unk_10 >> 2) & 1) != 0 ||
            ((lbl_1_bss_9F8[ridx].unk_12 >> 2) & 1) != 0) {
            delta = 1;
        }
        if (((lbl_1_bss_9F8[ridx].unk_10 >> 3) & 1) != 0 ||
            ((lbl_1_bss_9F8[ridx].unk_12 >> 3) & 1) != 0) {
            delta--;
        }
        v = lbl_1_bss_8B614.unk_E + delta;
        v = (v < 0) ? 0 : ((v > max) ? max : v);
        lbl_1_bss_8B614.unk_E = (s16)v;
    } else {
        lbl_1_bss_8B614.unk_E = 0;
    }

    if (old != lbl_1_bss_8B614.unk_E) {
        if ((lbl_1_bss_8B614.unk_4C & 0x80000000) == 0) {
            lbl_1_bss_8B614.unk_50 = delta;
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_4C |= 0x02000000;
            lbl_1_bss_8B614.unk_4C |= 1;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = (u16)(delta * 5);
        }
        fn_1_A2D84(0xA9010000);
    }

    if (lbl_1_bss_8B614.unk_58 == 4) {
        p = (u8 *)&lbl_1_bss_8B614 + 0x74;
        if (fn_1_95120(p + 0x148) != 0) {
            id = (u32)fn_1_41488(
                (Sig_fn_1_41488_Data *)(*(Sig_fn_1_41488_Owner **)(p + 0x150))->unk_24,
                lbl_16_data_82B34[lbl_1_bss_8B614.unk_0]);
            fn_1_933D8(p, p + 0x148, id & 0xFFFF);
            b = (u8 *)&lbl_1_bss_8B614;
            for (i = 0; i < fn_1_12CB04(lbl_1_bss_8B614.unk_C); i++) {
                fn_1_933D8(b + i * 0x4E8 + 0x55C, b + i * 0x4E8 + 0x6A4, id & 0xFFFF);
            }
            lbl_1_bss_8B614.unk_0 = (s16)(lbl_1_bss_8B614.unk_0 + 1);
            lbl_1_bss_8B614.unk_0 = (s16)(lbl_1_bss_8B614.unk_0 & 7);
        }
    }
    return 0;
}
