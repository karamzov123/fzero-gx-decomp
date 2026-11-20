#include "types.h"
typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_800786B0_Fn800786B0Arg0;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_800786B0_Fn800786B0Data;

struct fn_80077E7C_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};
struct fn_80077E7C_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};
extern struct fn_80077E7C_lbl_801A6D38_T *lbl_801A6D38;
extern u32 lbl_801A6D94;
extern u32 lbl_801A6D9C;
extern void * fn_800786B0(Sig_fn_800786B0_Fn800786B0Arg0 *, Sig_fn_800786B0_Fn800786B0Data *, u8 *);
extern void fn_80078CDC(s32);


s32 fn_80078538(Sig_fn_800786B0_Fn800786B0Data *); /* extern */
Sig_fn_800786B0_Fn800786B0Data *fn_800789D8(Sig_fn_800786B0_Fn800786B0Arg0 *, Sig_fn_800786B0_Fn800786B0Data *, u8 *); /* extern */
s32 fn_80078C28(Sig_fn_800786B0_Fn800786B0Arg0 *); /* extern */

void fn_80077E7C(Sig_fn_800786B0_Fn800786B0Arg0 *arg0) {
    Sig_fn_800786B0_Fn800786B0Data *var_r30;
    u32 temp_r3;
    u32 var_r3;
    u8 *temp_r29;
    s32 var_r28;

    temp_r29 = ((u8 *)(arg0) + 0x40);
    var_r3 = (*(struct fn_80077E7C_lbl_801A6D38_T **)(&lbl_801A6D38))->unk_18;
    var_r30 = (Sig_fn_800786B0_Fn800786B0Data *)((u8 *)(arg0) + (*(s32 *)((u8 *)(arg0) + 32)));
    if ((s32) var_r3 != 0) {
        var_r3 ^= 3;
    }
    lbl_801A6D9C = var_r3;
    temp_r3 = *(u32 *)((u8 *)(arg0) + 4);
    if (temp_r3 & 4) {
        fn_80078C28((Sig_fn_800786B0_Fn800786B0Arg0 *)(arg0));
    } else if ((temp_r3 & 8) && !(temp_r3 & 0x40)) {
        fn_80078538((Sig_fn_800786B0_Fn800786B0Data *)(var_r30));
    }
    lbl_801A6D94 = 1;
    if ((*(u32 *)((u8 *)(arg0) + 4)) & 0x18) {
        fn_800786B0((Sig_fn_800786B0_Fn800786B0Arg0 *)(arg0), (Sig_fn_800786B0_Fn800786B0Data *)(var_r30), temp_r29);
    } else {
        var_r28 = 0;
        while (var_r28 < (arg0->count_a + arg0->count_b)) {
            var_r30 = (Sig_fn_800786B0_Fn800786B0Data *)(fn_800789D8((Sig_fn_800786B0_Fn800786B0Arg0 *)(arg0), (Sig_fn_800786B0_Fn800786B0Data *)(var_r30), temp_r29));
            var_r28 += 1;
                    }
    }
    lbl_801A6D94 = 0;
    (*(u32 *)((u8 *)(arg0) + 4)) = ((*(u32 *)((u8 *)(arg0) + 4)) & 0xFFFFFF9F);
    fn_80078CDC(((*(u32 *)((u8 *)(arg0) + 4)) >> 2U) & 1);
}
