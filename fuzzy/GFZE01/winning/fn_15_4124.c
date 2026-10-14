/* Non-matching: best partial attempt (78.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0x38];
    s16 unk_38;
    u8 pad_3A[0x2E];
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
    u8 pad_74[0x24];
    s16 unk_98;
    u8 pad_9A[0x2E];
} fn_15_4124_St;

typedef struct {
    u8 pad_0[0x1C];
    f32 unk_1C;
} fn_15_4124_Sub;

typedef struct {
    u16 unk_0;
    u8 pad_2[0xE];
    u16 unk_10;
} fn_15_4124_Ctrl;

typedef struct {
    void **unk_0;
    u8 pad_4[0x704];
} fn_15_4124_Holder;

extern fn_15_4124_St lbl_15_bss_0;
extern fn_15_4124_Ctrl lbl_1_bss_D58;
extern fn_15_4124_Holder lbl_1_bss_6EAD0;
extern const f64 lbl_15_rodata_90;
extern f32 lbl_15_rodata_114;
extern f32 lbl_15_rodata_64;
extern fn_15_4124_Sub *camera_get_state_object(void);
extern void fn_1_A1588(void *, u32);

void fn_15_4124(void) {
    fn_15_4124_St *p_st = &lbl_15_bss_0;
    fn_15_4124_Sub *p_sub;
    u32 w;
    s32 v0;
    s32 v5;
    s32 n;
    s32 rem;

    p_sub = camera_get_state_object();

    w = (u32)lbl_1_bss_D58.unk_10;
    v0 = (w & 0x10000000u) ? -1 : ((w & 0x20000000u) ? 1 : 0);

    n = p_st->unk_38;
    rem = (p_st->unk_6C + v0 + n + 3) % (n + 3);
    p_st->unk_6C = rem;
    if (rem < 0) {
        rem = 0;
    } else if (rem > n - 1) {
        rem = n - 1;
    }
    p_st->unk_68 = rem;

    w = (u32)lbl_1_bss_D58.unk_0;
    if ((w & 0x100000u) != 0) {
        v5 = 0;
    } else {
        w = (u32)lbl_1_bss_D58.unk_10;
        v5 = (w & 0x80000000u) ? -1 : ((w & 0x40000000u) ? 1 : 0);
    }

    if (v5 != 0) {
        n = p_st->unk_38;
        switch (p_st->unk_6C - n) {
        case 0:
            p_st->unk_70 = (p_st->unk_70 + v5 + 4) % 4;
            break;
        case 1:
            p_sub->unk_1C = p_sub->unk_1C
                + (f32)((4503601774854144.0 + (f64)v5) - lbl_15_rodata_90);
            if (p_sub->unk_1C > lbl_15_rodata_114) {
                p_sub->unk_1C = lbl_15_rodata_114;
            }
            if (p_sub->unk_1C < lbl_15_rodata_64) {
                p_sub->unk_1C = lbl_15_rodata_64;
            }
            break;
        case 2:
            p_st->unk_98 = (s16)(p_st->unk_98 + v5);
            switch (p_st->unk_98 % 3) {
            case 0:
                fn_1_A1588(lbl_1_bss_6EAD0.unk_0[0], 0x11);
                break;
            case 1:
                fn_1_A1588(lbl_1_bss_6EAD0.unk_0[0], 0x35);
                break;
            default:
                fn_1_A1588(lbl_1_bss_6EAD0.unk_0[0], 0x42);
                break;
            }
            break;
        default:
            break;
        }
    }
}
