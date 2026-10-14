/* Non-matching: best partial attempt (97.32% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/ghost.h"

typedef struct {
    u16 unk0;
    s16 unk2;
    u32 unk4;
    u8 pad[0x18];
} F0168_Item;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u32 unk8;
    u32 unkC;
} F0168_Desc;

typedef struct {
    u8 pad_0[0x174E];
    u8 unk174E;
    u8 pad_174F[0x71];
    u32 unk17C0;
} F0168_Bss;

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern void *lbl_801A6410;
extern void *fn_1_4630(void *, u32, const char *, int);
extern void fn_1_F1300(u32, void *, u32, u32, u32);
extern void fn_1_F4F08(u32, void *, u32, void *);
extern void *fn_1_7F518(s16, char *, s32);
extern void fn_1_14F46C(F0168_Desc *, u8 *);
extern void fn_1_46B4(void *, void *, const char *, int);
extern void fn_1_80058(s8, F0168_Item *);
extern void fn_80006E10(const char *);

#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
void fn_1_F0168(void) {
    u8 buf[0xA20] __attribute__((aligned(32)));
    char name[0x30];
    char tmp[0x20];
    F0168_Desc desc;
    u8 *data = (u8 *)lbl_1_data_3E358;
    F0168_Bss *bss = (F0168_Bss *)&lbl_1_bss_7B180;
    F0168_Item *items = (F0168_Item *)((u8 *)bss + 0x1838);
    u32 i;
    u32 n;
    s32 *p17DC = (s32 *)((u8 *)bss + 0x17DC);
    s16 *p17D0 = (s16 *)((u8 *)bss + 0x17D0);
    u32 *p1614 = (u32 *)((u8 *)bss + 0x1614);
    u8 *p17F0 = (u8 *)bss + 0x17F0;
    void **p16EC = (void **)((u8 *)bss + 0x16EC);
    u32 *p1824 = (u32 *)((u8 *)bss + 0x1824);
    void **p1600 = (void **)((u8 *)bss + 0x1600);
    void **p1700 = (void **)((u8 *)bss + 0x1700);
    u32 *p1628 = (u32 *)((u8 *)bss + 0x1628);
    void **p1714 = (void **)((u8 *)bss + 0x1714);
    u32 *p163C = (u32 *)((u8 *)bss + 0x163C);
    void **p1728 = (void **)((u8 *)bss + 0x1728);
    u32 *p1678 = (u32 *)((u8 *)bss + 0x1678);
    u32 *p1664 = (u32 *)((u8 *)bss + 0x1664);
    u32 *p1650 = (u32 *)((u8 *)bss + 0x1650);
    s16 *p1800 = (s16 *)((u8 *)bss + 0x1800);
    void **heap = &lbl_801A6410;

    n = 0;
    for (i = 0; i < bss->unk174E; i++) {
        if (p17DC[i] == 0) {
            fn_1_80058(p17D0[i], &items[n]);
            items[n].unk0 = i;
            if (bss->unk174E <= 1) {
                items[n].unk4 = 1;
            } else if (bss->unk174E <= 3) {
                items[n].unk4 = 2;
            } else {
                items[n].unk4 = 4;
            }
            fn_1_7F518(items[n].unk2, tmp, 0);
            if (items[n].unk4 == 2) {
                sprintf(name, (char *)data + 0x378, tmp);
            } else {
                sprintf(name, (char *)data + 0x38C, tmp);
            }
            fn_1_465D0(name, 1);
            n++;
        } else {
            u8 a, b, c;
            if (bss->unk174E <= 1) {
                desc.unk8 = 1;
            } else if (bss->unk174E <= 3) {
                desc.unk8 = 2;
            } else {
                desc.unk8 = 4;
            }
            a = p17F0[i * 3 + 0];
            b = p17F0[i * 3 + 1];
            c = p17F0[i * 3 + 2];
            desc.unk0 = a;
            desc.unk2 = b;
            desc.unk4 = c;
            fn_80006E10((char *)data + 0x364);
            fn_1_14F46C(&desc, buf);
            fn_80006E10((char *)data + 0x374);
        }
        if (p16EC[i] != NULL) {
            fn_1_46B4(lbl_801A6410, p16EC[i], (char *)data + 0x2D4, 0x1039);
        }
        p16EC[i] = fn_1_4630(*heap, p1824[i] * 4, (char *)data + 0x2D4, 0x103A);
        fn_1_F4F08(p1824[i], p1600[i], p1614[i], p16EC[i]);
        if (p1700[i] != NULL) {
            fn_1_46B4(lbl_801A6410, p1700[i], (char *)data + 0x2D4, 0x103D);
        }
        p1700[i] = fn_1_4630(*heap, p1824[i] * 4, (char *)data + 0x2D4, 0x103E);
        fn_1_F4F08(p1824[i], p1600[i], p1628[i], p1700[i]);
        if (p1714[i] != NULL) {
            fn_1_46B4(lbl_801A6410, p1714[i], (char *)data + 0x2D4, 0x1041);
        }
        p1714[i] = fn_1_4630(*heap, p1824[i] * 4, (char *)data + 0x2D4, 0x1042);
        fn_1_F4F08(p1824[i], p1600[i], p163C[i], p1714[i]);
        if (p1728[i] != NULL) {
            fn_1_46B4(lbl_801A6410, p1728[i], (char *)data + 0x2D4, 0x1047);
        }
        p1728[i] = fn_1_4630(*heap, p1824[i] * 16, (char *)data + 0x2D4, 0x1048);
        fn_1_F1300(p1824[i], p1728[i], p1650[i], p1664[i], p1678[i]);
        p1800[i] = 0;
    }
    bss->unk17C0 = 0;
    *(s32 *)(data + 0x1D4) = -1;
}
#pragma pop
