/* Non-matching: best partial attempt (69.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
struct Sig_fn_8004E270_fn_8004E270_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};
typedef void (*fn_80042D24_Fn0)(u32, s32 *, s32 *, s32 *);
typedef void (*fn_80042D24_Fn1)(u32, s32, s32);
struct fn_80042D24_Arg0 {
    u8 pad_0[4];
    s32 unk_4;
    struct Sig_fn_8004E270_fn_8004E270_Arg0 *unk_8;
    u8 pad_C[2];
    s8 unk_E;
    u8 pad_F[0x39];
    u16 *unk_48;
    s32 unk_4C;
    u8 pad_50[0xC];
    u16 *unk_5C;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
    u8 pad_74[4];
    fn_80042D24_Fn0 unk_78;
    u32 unk_7C;
    fn_80042D24_Fn1 unk_80;
    u32 unk_84;
    u8 pad_88[8];
    s32 unk_90;
    s32 unk_94;
};
extern u32 fn_8004E270(struct Sig_fn_8004E270_fn_8004E270_Arg0 *);

void fn_80042D24(struct fn_80042D24_Arg0 *arg0) {
    u16 *v0 = arg0->unk_48;
    s32 v1;
    u16 *v10;
    u16 *v4;
    s32 v3;
    if (arg0->unk_4 == 1 && fn_8004E270(arg0->unk_8) == 0) {
        arg0->unk_78(arg0->unk_7C, &arg0->unk_68, &arg0->unk_6C, &arg0->unk_70);
        v1 = arg0->unk_60 - arg0->unk_68;
        if (v1 > arg0->unk_6C) v1 = arg0->unk_6C;
        if (v1 > arg0->unk_4C) v1 = arg0->unk_4C;
        v10 = arg0->unk_5C + arg0->unk_68;
        if (arg0->unk_E == 2) {
            v4 = arg0->unk_5C + arg0->unk_64 + arg0->unk_68;
            for (v3 = 0; v3 < v1; v3++) {
                __sthbrx(v0[v3 * 2], v10 + v3, 0);
                __sthbrx(v0[v3 * 2 + 1], v4 + v3, 0);
            }
        } else {
            for (v3 = 0; v3 < v1; v3++) {
                __sthbrx(v0[v3], v10 + v3, 0);
            }
        }
        arg0->unk_90 = v1;
        arg0->unk_94 = arg0->unk_E * (v1 * 2);
        arg0->unk_4 = 2;
    }
    if (arg0->unk_4 == 2) {
        arg0->unk_80(arg0->unk_84, arg0->unk_94, arg0->unk_90);
        arg0->unk_4 = 3;
    }
}
