#include "types.h"

typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data;

struct fn_800781B8_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};

extern struct fn_800781B8_lbl_801A6D38_T *lbl_801A6D38;
extern u32 lbl_801A6D90;
extern u32 lbl_801A6D9C;
extern u32 fn_800756B0(u32, u32);
extern s32 fn_80078538(Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *);
extern void *fn_800789D8(Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *, Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *, u8 *);
extern s32 fn_80078C28(Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *);
extern s32 fn_80078768(Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *, Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *, u8 *, s32);
extern void fn_80078CDC(s32);

void fn_800781B8(Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *arg0) {
    u32 temp_r3;
    u32 var_r3;
    s32 var_r28;
    Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *var_r30;
    u8 *temp_r29;
    u32 var_b;

    temp_r29 = ((u8 *)(arg0) + 0x40);
    var_r3 = lbl_801A6D38->unk_18;
    var_r30 = (Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)((u8 *)(arg0) + (*(s32 *)((u8 *)(arg0) + 32)));
    if ((s32) var_r3 != 0) {
        var_r3 ^= 3;
    }
    lbl_801A6D9C = var_r3;
    temp_r3 = *(u32 *)((u8 *)(arg0) + 4);
    if (temp_r3 & 4) {
        fn_80078C28(arg0);
    } else if ((temp_r3 & 8) && !(temp_r3 & 0x40)) {
        fn_80078538(var_r30);
    }
    if (lbl_801A6D90 == 0) {
        fn_800756B0((u32)(arg0), (u32)(var_r30));
    }
    if ((*(u32 *)((u8 *)(arg0) + 4)) & 0x18) {
        fn_80078768(arg0, var_r30, temp_r29, 0);
    } else {
        s32 var_i;
        for (var_i = 0; var_i < arg0->count_a; var_i++) {
            u8 *var_p;
            s32 var_j;
            var_p = (u8 *) var_r30 + 0x60;
            for (var_j = 0; var_j < 2; var_j++) {
                if (*((u8 *) var_r30 + 0x13) & (1 << var_j)) {
                    var_p += *(u32 *)((u8 *) var_r30 + 0x28 + var_j * 4);
                }
            }
            if (*((u8 *) var_r30 + 0x13) & 0xC) {
                u32 var_a;
                var_a = *(u32 *)(var_p + 8);
                var_b = *(u32 *)(var_p + 0xc);
                var_p += 0x20;
                var_p += var_a;
                var_p += var_b;
            }
            var_r30 = (Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *) var_p;
        }
        var_r28 = 0;
        while (var_r28 < arg0->count_b) {
            var_r30 = (Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)(fn_800789D8(arg0, var_r30, temp_r29));
            var_r28 += 1;
        }
    }
    (*(u32 *)((u8 *)(arg0) + 4)) = ((*(u32 *)((u8 *)(arg0) + 4)) & 0xFFFFFF9F);
    fn_80078CDC(((*(u32 *)((u8 *)(arg0) + 4)) >> 2U) & 1);
}
