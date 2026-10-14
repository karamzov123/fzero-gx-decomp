/* Non-matching: best partial attempt (21.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f64 lbl_1_rodata_400[15];
extern u8 lbl_1_bss_A48[];
extern f32 lbl_1_bss_1010[];
extern u16 lbl_1_data_4068;
extern u32 fn_1_10780C(void *, void *, u32 *, void *);
extern void fn_80008C20(void *, void *, void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s16);

/* fn_1_BD54: camera update. Converts two signed state bytes through the
 * int->double idiom, folds them into a persistent f32, then runs the
 * matrix pipeline. */
void fn_1_BD54(void) {
    f32 *cam = lbl_1_bss_1010;
    const f64 *tbl = lbl_1_rodata_400;
    s32 a;
    s32 b;
    f64 d;
    f32 v;
    u16 idx;
    u32 flags;
    u32 tmp1;
    u32 tmp2;
    void *tmp3;

    a = (s8)lbl_1_bss_A48[2];
    d = (f64)(s16)(a ^ 0x8000) - tbl[16];
    v = (f32)(tbl[17] * d);
    cam[0] = (f32)((f64)cam[0] + (f64)v);

    b = (s8)lbl_1_bss_A48[3];
    idx = lbl_1_data_4068 + (b << 1);
    lbl_1_data_4068 = idx;

    flags = fn_1_10780C((u8 *)lbl_1_bss_A48 + 0x1C, (u8 *)lbl_1_bss_A48 + 0x28, &tmp1, &tmp3);
    (void)tmp2;

    fn_80008C20((u8 *)lbl_1_bss_A48 + 0x28, (u8 *)lbl_1_bss_A48 + 0x1C, (u8 *)lbl_1_bss_A48 + 0x10);

    if ((flags & 0x140) != 0 && (flags & 1) == 0) {
        lbl_8006E0B4(cam[0], *(f32 *)((u8 *)lbl_1_bss_A48 + 0xC), tbl[18]);
    } else {
        lbl_8006E0B4(cam[0], tbl[19], tbl[18]);
    }

    mathutil_mtxA_rotate_x((s16)lbl_1_data_4068);
}
