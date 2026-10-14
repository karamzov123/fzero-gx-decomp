/* Non-matching: best partial attempt (39.34% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef u32 (*fn_1_3129C_Fn0)(u32);
struct Bss {
    u8 pad0[0xC]; u32 unk_C; u8 pad10[0x1A]; s16 unk_2A; u8 pad2c[4];
    u32 unk_30; u8 pad34[0x14B4]; u16 unk_14E8; u8 pad14ea[0x16];
    u32 unk_1500; u8 pad1504[0x2F0]; u16 unk_17F4;
};
struct Data { u8 pad0[0x454]; u8 unk_454; u8 pad455[3]; u32 unk_458; u32 unk_45C; };
extern u8 lbl_1_bss_3C00;
extern struct Data lbl_1_data_5730;
extern u32 lbl_1_bss_7EFD8;
extern u32 lbl_1_bss_7F04C;
extern u32 lbl_1_bss_6EAB4;
extern void * fn_1_434C(void);
extern u32 fn_1_F2F58(void);
extern void fn_1_F37F4(void);
extern void * fn_1_435C(void *);
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

u32 fn_1_3129C(u32 arg0) {
    struct Bss *b = (struct Bss *)&lbl_1_bss_3C00;
    u8 *mgr = (u8 *)b + 0x20000;
    u8 *cb;
    u32 status, flags, i, n, idx, seq;
    u32 (*callback)(u32);
    u8 *item;
    u8 *map;
    u8 *source;
    u32 x;
    s32 j;
    u32 *p;

    p = (u32 *)(mgr + 0x228c);
    if (--*p == 0) {
        flags = *(u32 *)((u8 *)b + 0x30);
        idx = flags | 0x200;
        status = idx & 0x201;
        *(u32 *)((u8 *)b + 0x30) = idx;
        *(u32 *)((u8 *)b + 0x30) = idx & ~0x200;
        idx = (idx & ~0x200) | (flags & 0x200);
        *(u32 *)((u8 *)b + 0x30) = idx;
        b->unk_14E8 = ((status | -status) >> 31) + 0x27;
        status = (u32)fn_1_434C();
        if ((*(u32 *)((u8 *)b + 0x30) & 0x800000) && lbl_1_bss_7EFD8) {
            if (fn_1_F2F58())
                fn_1_F37F4();
            fn_1_435C(*(void **)(mgr + 0x1f88));
            fn_1_426C(lbl_1_bss_7EFD8);
            lbl_1_bss_7EFD8 = 0;
        }
        if (lbl_1_bss_7F04C) {
            fn_1_435C(*(void **)(mgr + 0x1f88));
            fn_1_426C(lbl_1_bss_7F04C);
            fn_1_F7308();
            lbl_1_bss_7F04C = 0;
        }
        if (*(u32 *)((u8 *)b + 0x30) & 0x800000)
            fn_1_F2E50(*(s32 *)(mgr + 0x2278) != 0);
        fn_1_435C((void *)status);
        fn_1_5370(0, 0);
        fn_1_E3778();
        fn_1_EA314(arg0);
        if (*(s32 *)(mgr + 0x2288) != 0) {
            fn_1_435C(*(void **)(mgr + 0x1f88));
            if ((s32)lbl_1_data_5730.unk_458 != -1) {
                fn_1_426C(lbl_1_data_5730.unk_458);
                lbl_1_data_5730.unk_458 = -1;
            }
            fn_1_435C(*(void **)(mgr + 0x20a4));
            if ((s32)lbl_1_data_5730.unk_45C != -1) {
                fn_1_426C(lbl_1_data_5730.unk_45C);
                lbl_1_data_5730.unk_45C = -1;
            }
            fn_1_D1F88();
            *(u32 *)(mgr + 0x2288) = 0;
        }
        *(u32 *)((u8 *)b + 0x30 + 0x1474) = 0;
        if (b->unk_C != 0) {
            cb = (u8 *)b + 0x30;
            *(u32 *)(mgr + 0x1f9c) = 0;
            callback = *(fn_1_3129C_Fn0 *)(cb + 0xc0);
            if (callback != 0) {
                status = callback((u32)cb);
                if (status & 4)
                    *(u32 *)(mgr + 0x1f9c) = 1;
                if ((status & 2) && *(s32 *)(mgr + 0x1fa0) == 0) {
                    *(u16 *)((u8 *)b + 0x17f4) = cb[7];
                    if (cb[5] == 0) {
                        n = cb[8];
                        seq = 0;
                        map = (u8 *)b + 0x165c;
                        source = (u8 *)b + 0x163c;
                        if (n != 0 && (*(u32 *)((u8 *)b + 0x30) & 0x400000) == 0)
                            fn_1_3F2A0();
                        if (b->unk_2A <= 41) {
                            for (i = 0; i < n; i++) {
                                item = cb + i * 0xa0;
                                idx = item[0x157];
                                map[0x194 + idx] = seq++;
                                map[idx * 8 + 4] = item[0x154];
                                map[idx * 8 + 6] = source[i];
                            }
                        } else {
                            for (i = 0; i < n; i++) {
                                item = cb + i * 0xa0;
                                idx = item[0xdc];
                                map[0x194 + idx] = seq++;
                                map[idx * 8 + 4] = item[0x154];
                                map[idx * 8 + 6] = source[i];
                            }
                        }
                    }
                    map = (u8 *)b + 0x165c;
                    map[0x191] |= 2;
                    map[0x192] = cb[8];
                    map[0x190] = cb[7];
                    *(u32 *)((u8 *)b + 0x30) |= 0x400000;
                    b->unk_17F4 = 14;
                    fn_1_4A00(0, 30, (void *)b->unk_1500);
                    lbl_1_bss_6EAB4 |= 0x2c;
                    *(u32 *)(mgr + 0x1fa0) = 1;
                    if (cb[5] == 0)
                        lbl_1_data_5730.unk_454 = 1;
                    fn_1_469BC();
                    fn_1_8DBA4(0);
                }
                if ((status & 1) == 0)
                    b->unk_C = 0;
            } else {
                b->unk_C = 0;
            }
        }
        if (arg0 == 0 && cb[5] == 1)
            cb[0x13f6]--;
        x = fn_1_4060();
        *(u8 *)(mgr + 0x2290) = 0;
    } else {
        *(u8 *)(mgr + 0x2290) = 1;
    }
    return x;
}
