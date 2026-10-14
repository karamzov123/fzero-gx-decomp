/* Non-matching: best partial attempt (87.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8;
    s16 unk_A;
    u8 unk_C;
    u8 pad_D[7];
    u32 unk_10;
} Obj_10_bss_0;

typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0xA8];
    u32 unk_140;
} GState;

extern Obj_10_bss_0 lbl_10_bss_0;
extern u32 lbl_10_bss_3C0[74736];
extern GState lbl_1_bss_8B3A0;
extern u16 lbl_1_bss_96A;

extern s32 fn_1_1310E0(void);
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_12F10C(void *);
extern void fn_1_131084(u32, u32);

void fn_10_C328(void) {
    s32 v;
    s16 dir;
    struct {
        u8 *base;
    } mgr;
    Obj_10_bss_0 *sel = &lbl_10_bss_0;

    mgr.base = (u8 *)&lbl_10_bss_0 + 0x5000;

    if (fn_1_1310E0() != 0) {
        return;
    }

    if ((s32)sel->unk_10 == -1) {
        fn_1_4C10();
    }

    {
        s32 ok;
        if ((lbl_1_bss_8B3A0.unk_140 & 0x80000000)
            && !(lbl_1_bss_8B3A0.unk_140 & 0x40000000)
            && !(lbl_1_bss_8B3A0.unk_94 & 0x8)) {
            ok = 1;
        } else if (fn_1_4C10() != 0) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok != 0) {
            return;
        }
    }

    v = sel->unk_10;
    if (v != -1) {
        sel->unk_10 = -1;
        lbl_1_bss_96A = (u16)v;
        return;
    }

    if (*(s32 *)(mgr.base + 0x5660) != 0) {
        s16 a = sel->unk_A;
        *(s32 *)(mgr.base + 0x5660) = 0;
        if (a != 0) {
            sel->unk_10 = 0x14;
            fn_1_1280(1);
        } else {
            sel->unk_10 = 0x10;
            fn_1_4A00(0, *(s16 *)(mgr.base - 0x6c74), *(u32 *)(mgr.base - 0x6c78));
            *(s32 *)(mgr.base + 0x1744) = 0;
        }
        fn_1_12F10C(lbl_10_bss_3C0);
    } else {
        u32 a = sel->unk_A;
        *(s32 *)(mgr.base + 0x5660) = 1;
        dir = 4;
        if (a & 0x80000000) {
            sel->unk_A = ((~1) & (a));
            dir = 0;
        } else if (a & 2) {
            sel->unk_A = a & 0xE0000001;
            dir = 1;
        }
        fn_1_131084(*(u32 *)(mgr.base + 0x565c), dir);
    }
}
