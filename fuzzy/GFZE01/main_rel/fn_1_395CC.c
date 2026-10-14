/* Non-matching: best partial attempt (57.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_395CC_lbl_1_bss_3C00 {
    u8 pad_0[0x30];
    u32 unk_30;
};
extern struct fn_1_395CC_lbl_1_bss_3C00 lbl_1_bss_3C00;
extern u32 lbl_1_data_3D544[];
extern u32 lbl_1_bss_6EAB4;
struct fn_1_395CC_bss_7EFD8 { u32 unk_0; u32 unk_4; };
extern struct fn_1_395CC_bss_7EFD8 lbl_1_bss_7EFD8;
extern u16 lbl_1_bss_960;
extern u32 lbl_1_bss_381F8;
extern u32 fn_1_35BC4(void);
extern u32 fn_1_A0D20(void);
extern u8 lbl_1_bss_17AC;
extern u8 lbl_1_data_5730[];
extern void * fn_1_435C(void *);
extern void fn_1_4310(u32);
extern void fn_1_D0790(void);
extern void fn_1_D0728(void);
extern u32 fn_1_58C4(void);
extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);
extern u32 fn_1_F2F34(void);
extern void fn_1_F3AB0(void *);
extern u32 fn_1_F2F58(void);
extern void fn_1_F326C(void);
extern void fn_1_F2F84(void);
extern void fn_1_F38C0(void);
extern void fn_1_4811C(int);
extern void fn_1_48004(s32, s32);
extern void fn_1_EA314(u32);
extern void fn_1_46EA8(u32);
extern void fn_1_104710(void);
extern void fn_1_43E8(u32);
extern void fn_1_34924(void *);
extern void fn_1_1049E0(void *);
extern void fn_1_1050D0(void *);
extern void fn_1_43F4(void);
extern void fn_1_15E27C(void);
extern void fn_1_A11EC(void);
extern void fn_1_A1DCC(u32);
extern void fn_1_3F5F8(void);
extern void fn_1_F23E8(void);
extern void fn_1_F23D8(void);
extern void * fn_1_3F8C(void *, void *, void *, s32);

void fn_1_395CC(u32 arg0, u32 arg1) {
    struct fn_1_395CC_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
    u8 *p_lbl_1_data_5730;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t5;
    u32 ret;
    u32 i;
    u32 j;
    u32 n;
    u32 flags;
    u32 ordinal;
    u8 *table;
    u8 *manager;
    u8 *entry;
    u8 *dst;

    p_lbl_1_bss_3C00 = &lbl_1_bss_3C00;
    v0 = (u32)p_lbl_1_bss_3C00 + 0x20000;
    manager = (u8 *)v0;
    p_lbl_1_data_5730 = (u8 *)&lbl_1_data_5730;
    fn_1_435C(*(void **)(manager + 0x1f88));
    fn_1_4310(0);
    fn_1_435C(*(void **)(manager + 0x20a4));
    fn_1_4310(0);
    fn_1_A0D20();
    lbl_1_bss_17AC = 1;
    t5 = fn_1_35BC4();
    if ((p_lbl_1_bss_3C00->unk_30 & 0x800) != 0) {
        fn_1_D0790();
    } else {
        fn_1_D0728();
        if (*((u8 *)p_lbl_1_bss_3C00 + 0x35) == 3) {
            table = (u8 *)&lbl_1_data_3D544;
            i = 0;
            while (i < fn_1_58C4()) {
                *(u32 *)(table + i * 4) &= ~0x04000000;
                i++;
            }
        }
        if (*((u8 *)p_lbl_1_bss_3C00 + 0x39) == 1) {
            table = (u8 *)&lbl_1_data_3D544;
            i = 0;
            while (i < fn_1_58C4()) {
                *(u32 *)(table + i * 4) &= ~0x20000000;
                i++;
            }
        }
    }

    if (*(s32 *)((u8 *)p_lbl_1_bss_3C00 + 0xC) == 0) {
        *(u32 *)(manager + 0x1f9c) = 0;
        v1 = *(u32 *)((u8 *)p_lbl_1_bss_3C00 + 0xDC);
        if (v1 != 0) {
            ret = ((u32 (*)(void))v1)();
            flags = ret;
            if ((flags & 4) != 0)
                *(u32 *)(manager + 0x1f9c) = 1;
            if ((flags & 2) != 0 && *(s32 *)(manager + 0x1fa0) == 0) {
                entry = (u8 *)p_lbl_1_bss_3C00 + 0x30;
                *(u16 *)((u8 *)p_lbl_1_bss_3C00 + 0x17f4) = entry[7];
                n = entry[8];
                if (entry[5] == 0 && (s32)n > 0) {
                    for (i = 0; i < n; i++) {
                        if (*(u32 *)(entry + 0x1480 + i * 4) == 0)
                            continue;
                        if ((p_lbl_1_bss_3C00->unk_30 & 0x200) != 0)
                            break;
                        fn_1_3F2A0();
                        ordinal = 0;
                        for (j = 0; j < n; j++) {
                            if (*(s16 *)((u8 *)p_lbl_1_bss_3C00 + 0x2a) <= 41)
                                v2 = entry[0x157 + j * 0xA0];
                            else
                                v2 = entry[0xDC + j * 0xA0];
                            dst = (u8 *)p_lbl_1_bss_3C00 + 0x165c + v2 * 8;
                            dst[4] = entry[0x154 + j * 0xA0];
                            dst[6] = *((u8 *)p_lbl_1_bss_3C00 + 0x163c + j);
                            *((u8 *)p_lbl_1_bss_3C00 + 0x17f0 + v2) = ordinal++;
                        }
                        dst = (u8 *)p_lbl_1_bss_3C00 + 0x165c;
                        flags = *(u32 *)((u8 *)p_lbl_1_bss_3C00 + 0x30) | 0x00400000;
                        dst[0x191] |= 2;
                        dst[0x192] = (u8)n;
                        dst[0x190] = entry[7];
                        *(u32 *)((u8 *)p_lbl_1_bss_3C00 + 0x30) = flags;
                        *(u16 *)((u8 *)p_lbl_1_bss_3C00 + 0x17f4) = 14;
                        break;
                    }
                }
                fn_1_4A00(0, 30, *(void **)((u8 *)p_lbl_1_bss_3C00 + 0x1500));
                *(u32 *)(manager + 0x1fa0) = 1;
                lbl_1_bss_6EAB4 |= 0x2c;
                if (entry[5] == 0)
                    p_lbl_1_data_5730[0x454] = 1;
                fn_1_469BC();
                fn_1_8DBA4(0);
            }
            if ((flags & 1) == 0)
                *(s32 *)((u8 *)p_lbl_1_bss_3C00 + 0xC) = 1;
        } else {
            *(s32 *)((u8 *)p_lbl_1_bss_3C00 + 0xC) = 1;
        }
    }

    *(u32 *)(manager + 0x3028) = 0x3c;
    fn_1_435C(*(void **)(manager + 0x1f88));
    if ((p_lbl_1_bss_3C00->unk_30 & 0x100) != 0) {
        if (fn_1_F2F34()) {
            *(u32 *)&lbl_1_bss_7EFD8 = (u32)fn_1_3F8C((void *)(p_lbl_1_data_5730 + 0xe58), fn_1_F3AB0, &lbl_1_bss_7EFD8, 0);
            fn_1_F38C0();
        } else if (fn_1_F2F58()) {
            *(u32 *)&lbl_1_bss_7EFD8 = (u32)fn_1_3F8C((void *)(p_lbl_1_data_5730 + 0xe6c), fn_1_F326C, &lbl_1_bss_7EFD8, 0);
            fn_1_F2F84();
        } else {
            *(u32 *)&lbl_1_bss_7EFD8 = 0;
        }
        lbl_1_bss_7EFD8.unk_4 = 0;
    }
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_4811C(0xbb);
        fn_1_48004(0x94, 1);
    }
    fn_1_EA314(1);
    if ((p_lbl_1_bss_3C00->unk_30 & 1) == 0) {
        *(u16 *)(manager + 0x3068) = 0x1a4;
        fn_1_46EA8(1);
        fn_1_104710();
        fn_1_46EA8(0);
        fn_1_435C(*(void **)(manager + 0x1f88));
        fn_1_43E8(1);
        fn_1_435C(*(void **)(manager + 0x1f88));
        *(u32 *)(manager + 0x227c) = (u32)fn_1_3F8C(p_lbl_1_data_5730 + 0xe80, fn_1_34924, manager + 0x3068, 0xd);
        *(u32 *)(manager + 0x2280) = (u32)fn_1_3F8C(p_lbl_1_data_5730 + 0xe90, fn_1_1049E0, manager + 0x3068, 0xd);
        fn_1_435C(*(void **)(manager + 0x20a4));
        *(u32 *)(manager + 0x2284) = (u32)fn_1_3F8C(p_lbl_1_data_5730 + 0xe98, fn_1_1050D0, 0, 0x1a);
        fn_1_43F4();
    } else {
        *(u16 *)(manager + 0x3068) = 0;
        *(u32 *)(manager + 0x227c) = -1;
        *(u32 *)(manager + 0x2280) = -1;
        *(u32 *)(manager + 0x2284) = -1;
        fn_1_435C(*(void **)(manager + 0x1f88));
        fn_1_4310(0);
    }
    fn_1_15E27C();
    fn_1_A11EC();
    fn_1_A1DCC(*((u8 *)p_lbl_1_bss_3C00 + 0x36));
    fn_1_3F5F8();
    lbl_1_bss_381F8 = -1;
    fn_1_435C(*(void **)(manager + 0x20a4));
    lbl_1_bss_381F8 = (u32)fn_1_3F8C(p_lbl_1_data_5730 + 0xea4, fn_1_F23E8, 0, 0x1a);
    fn_1_F23D8();
}
