/* Non-matching: best partial attempt (62.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Obj {
    u8 pad_0[4];
    void *resource;
    u8 pad_8[4];
    void *file;
    u8 pad_10[0x78];
    s32 unk_88;
    u8 pad_8c[0x10];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
} Obj;

extern u8 lbl_800909C0[];
extern u32 lbl_8017E568;
extern u32 lbl_80178CB8;
extern u32 lbl_8012B910[2];
extern s32 fn_800474E4(u32);
extern u32 fn_800415F4(Obj *);
extern u32 fn_80041684(Obj *);
extern u32 fn_800416F8(Obj *);
extern u32 fn_8004163C(Obj *);
extern s32 fn_8004EE84(void *);
extern u32 __cvt_fp2unsigned(f32);

void fn_8004C164(Obj *arg0, s32 *arg1, s32 *arg2) {
    s32 v0, v1, v2, v3;
    f32 f0;
    u32 temp;
    if (arg0 == 0 || arg1 == 0 || arg2 == 0) {
        fn_800474E4((u32)(lbl_800909C0 + 0x5d0));
        return;
    }
    if (lbl_8017E568 == 0) {
        if ((s8)((u8 *)arg0)[1] == 3 || (s8)((u8 *)arg0)[1] == 4) {
            *arg2 = fn_80041684(arg0);
            v1 = fn_800416F8(arg0);
            if (arg0 == 0) {
                fn_800474E4((u32)(lbl_800909C0 + 0x320));
                v2 = -1;
            } else if (arg0->file != 0) {
                v2 = ((s32 (*)(void *, s32))(*(void ***)arg0->file)[4])(arg0->file, 1);
                v2 = (v2 + (v2 >> 31)) >> 1;
            } else {
                v2 = 0;
            }
            *arg1 = arg0->unk_a4 + v1 - (fn_8004EE84(arg0->resource) + v2);
        } else if ((s8)((u8 *)arg0)[1] == 5) {
            *arg1 = fn_800415F4(arg0);
            *arg2 = fn_80041684(arg0);
            v0 = fn_8004163C(arg0);
            *arg1 = (*arg1 * (16 / v0)) + arg0->unk_a4;
        } else {
            *arg1 = 0;
            *arg2 = 1;
        }
        *arg1 += arg0->unk_88;
        return;
    }
    *(f32 *)(lbl_800909C0 + 0x264) = 0.0f;
    if ((s8)((u8 *)arg0)[1] == 3 || (s8)((u8 *)arg0)[1] == 4) {
        if ((s8)((u8 *)arg0)[0x72] == 0)
            *arg1 = arg0->unk_9c + (lbl_80178CB8 - arg0->unk_a0) * 100;
        else
            *arg1 = arg0->unk_9c;

        *arg2 = fn_80041684(arg0);
        v1 = fn_800416F8(arg0);
        if (arg0 == 0) {
            fn_800474E4((u32)(lbl_800909C0 + 0x320));
            v2 = -1;
        } else if (arg0->file != 0) {
            v2 = ((s32 (*)(void *, s32))(*(void ***)arg0->file)[4])(arg0->file, 1);
            v2 = (v2 + (v2 >> 31)) >> 1;
        } else {
            v2 = 0;
        }
        v0 = arg0->unk_a4 + v1 - (fn_8004EE84(arg0->resource) + v2);
        v0 += arg0->unk_88;
        v3 = *arg2;
        v1 = *(s32 *)((u8 *)&lbl_8017E568 + 0x2c);
        f0 = 1000.0f * (((f32)v0 / (f32)v3) - ((f32)v1 / (f32)*(s32 *)((u8 *)&lbl_8017E568 + 0x2c)));
        *(f32 *)((u8 *)&lbl_8017E568 + 0x28) = f0;
        if (f0 > 60.0f || f0 < -60.0f) {
            if (lbl_8012B910[0] == 1) {
                temp = lbl_8017E568;
                lbl_8017E568 = 0;
                fn_8004C164(arg0, &v0, &v3);
                lbl_8017E568 = temp;
                *(u32 *)((u8 *)&lbl_8017E568 + 8) += 1;
            }
            f0 = (f32)(u32)*(s32 *)((u8 *)&lbl_8017E568 + 0x2c) * ((f32)v0 / (f32)v3);
            arg0->unk_9c = __cvt_fp2unsigned(f0);
            arg0->unk_a0 = lbl_80178CB8;
        }
    } else if ((s8)((u8 *)arg0)[1] == 5) {
        v0 = fn_800415F4(arg0);
        v1 = fn_80041684(arg0);
        v2 = fn_8004163C(arg0);
        v0 *= 16 / v2;
        f0 = (f32)(v0 * 1) * ((f32)*(s32 *)((u8 *)&lbl_8017E568 + 0x2c) / (f32)v1);
        *arg1 = (s32)f0 + arg0->unk_9c + 1;
    } else {
        *arg1 = 0;
    }
    *arg1 += arg0->unk_88;
    *arg2 = *(s32 *)((u8 *)&lbl_8017E568 + 0x2c);
}
