/* Non-matching: best partial attempt (50.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { u8 pad[0xC]; u32 unk_C; u8 pad10[0x1A]; s16 unk_2A; u8 pad2c[4]; u32 unk_30; u8 pad34[0x14B4]; u16 unk_14E8; u8 pad14ea[0x16]; u32 unk_1500; u8 pad1504[0x2F0]; u16 unk_17F4; } Manager;
typedef struct { u8 pad[0x454]; u8 unk_454; u8 pad455[3]; s32 unk_458; s32 unk_45C; } Data;
extern u8 lbl_1_bss_3C00;
extern Data lbl_1_data_5730;
extern u32 lbl_1_bss_7EFD8;
extern u32 lbl_1_bss_7F04C;
extern u32 lbl_1_bss_6EAB4;
extern void *fn_1_434C(void);
extern u32 fn_1_F2F58(void);
extern void fn_1_F37F4(void);
extern void *fn_1_435C(void *);
extern u32 fn_1_426C(u32);
extern void fn_1_F7308(void);
extern u32 fn_1_F2E50(u32);
extern s8 fn_1_5370(s8, s32);
extern u32 fn_1_E3778(void);
extern u32 fn_1_EA314(u32);
extern void fn_1_D1F88(void);
extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);
extern u32 fn_1_4060(void);

void fn_1_30D84(void) {
    u8 *base = (u8 *)&lbl_1_bss_3C00;
    Manager *m = (Manager *)base;
    u8 *state = base + 0x20000;
    u8 *d = (u8 *)&lbl_1_data_5730;
    void *handle;
    u32 flags;
    u32 i, j, count;
    u8 *item;
    u8 *dest;
    u8 *order;
    u8 *src;
    u8 *arrays;
    s32 idx;
    if (--*(u32 *)(state + 0x228c) == 0) {
        m->unk_14E8 = 0x25;
        handle = fn_1_434C();
        if ((m->unk_30 & 0x800000) && lbl_1_bss_7EFD8) {
            if (fn_1_F2F58()) fn_1_F37F4();
            fn_1_435C(*(void **)(state + 0x1f88));
            fn_1_426C(lbl_1_bss_7EFD8);
            lbl_1_bss_7EFD8 = 0;
        }
        if (lbl_1_bss_7F04C) {
            fn_1_435C(*(void **)(state + 0x1f88));
            fn_1_426C(lbl_1_bss_7F04C);
            fn_1_F7308();
            lbl_1_bss_7F04C = 0;
        }
        if (m->unk_30 & 0x800000) {
            if (*(s32 *)(state + 0x2278) != 0) {
                fn_1_F2E50(1);
            } else {
                fn_1_F2E50(0);
            }
        }
        fn_1_435C(handle);
        fn_1_5370(0, 0);
        fn_1_E3778();
        fn_1_EA314(0);
        if (*(s32 *)(state + 0x2288)) {
            fn_1_435C(*(void **)(state + 0x1f88));
            if (*(s32 *)(d + 0x458) != -1) {
                fn_1_426C(*(u32 *)(d + 0x458));
                *(s32 *)(d + 0x458) = -1;
            }
            fn_1_435C(*(void **)(state + 0x20a4));
            if (*(s32 *)(d + 0x45c) != -1) {
                fn_1_426C(*(u32 *)(d + 0x45c));
                *(s32 *)(d + 0x45c) = -1;
            }
            fn_1_D1F88();
            *(u32 *)(state + 0x2288) = 0;
        }
        *(u32 *)(base + 0x1474 + 0x30) = 0;
        if (m->unk_C) {
            *(u32 *)(state + 0x1f9c) = 0;
            if (*(u32 *)(base + 0xf0)) {
                flags = ((u32 (*)(void))*(u32 *)(base + 0xf0))();
                if (flags & 4) *(u32 *)(state + 0x1f9c) = 1;
                if ((flags & 2) && !*(s32 *)(state + 0x1fa0)) {
                    item = base + 0x30;
                    m->unk_17F4 = item[7];
                    count = item[8];
                    if (!item[5]) {
                        arrays = base + 0x165c;
                        order = base + 0x17c1;
                        if (count) {
                            for (i = 0; i < count; i++) {
                                src = item + i * 0xa0;
                                if (*(u32 *)(src + 0x1480)) {
                                    if (m->unk_30 & 0x400000) break;
                                    fn_1_3F2A0();
                                    idx = 0;
                                    for (j = 0; j < count; j++) {
                                        u32 lane;
                                        for (lane = 0; lane < 4; lane++) {
                                            u32 off = (m->unk_2A <= 0x29)
                                                ? (0x157 + lane * 0xa0)
                                                : (lane == 0 ? 0xdc : lane == 1 ? 0x17c : lane == 2 ? 0x21c : 0x2bc);
                                            u32 valoff = lane * 0xa0 + 0x154;
                                            u8 n = src[valoff + (j * 0xa0)];
                                            u8 key = src[off + j * 0xa0];
                                            dest = arrays + key * 8;
                                            dest[4] = n;
                                            dest[6] = item[j];
                                            order[key + 0x194] = idx++;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        dest = arrays + 0x190;
                        dest[0] = item[7];
                        dest[1] |= 2;
                        dest[2] = count;
                        m->unk_30 |= 0x400000;
                        m->unk_17F4 = 14;
                    }
                    fn_1_4A00(0, 30, (void *)m->unk_1500);
                    *(u32 *)(state + 0x1fa0) = 1;
                    lbl_1_bss_6EAB4 |= 0x2c;
                    if (!item[5]) lbl_1_data_5730.unk_454 = 1;
                    fn_1_469BC();
                    fn_1_8DBA4(0);
                }
                if (!(flags & 1)) *(u32 *)(base + 0xc) = 0;
            } else *(u32 *)(base + 0xc) = 0;
        }
        fn_1_4060();
    }
}
