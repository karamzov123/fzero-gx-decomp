#include "types.h"
#include "rel/title/globals.h"

struct fn_8_704_lbl_1_bss_9C8 {
    u8 pad_0[2];
    u8 fzgx_pad_before_unk_A[0x8];
    s8 unk_A;
};
struct fn_8_704_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
};
struct fn_8_704_lbl_1_bss_8B3A0 {
    u8 pad_0[0x9E];
    s8 unk_9E;
};
extern struct fn_8_704_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_8_704_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern struct fn_8_704_lbl_1_bss_9F8 lbl_1_bss_9F8;

#pragma opt_propagation off
extern u8 lbl_8_bss_0;

int fn_8_704(void) {
    u8 zero = 0;
    struct { struct fn_8_704_lbl_1_bss_9F8 *value; } g;
    s8 v;
    lbl_8_bss_0 = 1;
    v = (s8)lbl_1_bss_9C8.unk_A;
    g.value = &lbl_1_bss_9F8;
    if (v == 0 && (g.value->unk_8 & 0x1000) != 0) {
        lbl_1_bss_8B3A0.unk_9E = zero;
    }
    return 6;
}
#pragma opt_propagation reset
