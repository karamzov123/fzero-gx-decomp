/* Non-matching: best partial attempt (92.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

typedef struct Sig_fn_1_12F30C_Fn1_12F30CState {
    s32 value;
} Sig_fn_1_12F30C_Fn1_12F30CState;

struct fn_1_385A4_sub {
    u8 pad_6[6];
    u8 unk_6;
    u8 pad_7[1];
    u8 unk_8;
};

void fn_1_385A4(void)
{
    u8 *base = (u8 *)&lbl_1_bss_3C00;
    u32 ctrl = (u32)base + 0x2000;
    u32 saved;

    fn_1_A8F78();
    fn_1_1596DC(2);
    saved = fn_80008E84(*(u32 *)(ctrl + 0x20cc));
    fn_1_12F30C(*(u32 *)(ctrl + 0x20a4),
                (Sig_fn_1_12F30C_Fn1_12F30CState *)(ctrl + 0x306c));
    fn_1_412A0(1);
    fn_1_48140(0xa1);
    fn_1_48140(fn_1_402A4(((struct fn_1_385A4_sub *)((u32)base + 0x30))->unk_6));
    if (((struct fn_1_385A4_sub *)((u32)base + 0x30))->unk_8 == 1) {
        fn_1_48140(0x9b);
    }
    else {
        fn_1_48140(0x9d);
    }
    fn_1_48140(0x9a);
    fn_80008E84(saved);
    fn_1_3F75C();
    if (lbl_1_data_5B7C == 1) {
        *(u8 *)(ctrl + 0x306a) = 1;
    }
}
