#include "types.h"
typedef u32 (*fn_80054AB0_Fn0)(u32, u32, u32);
typedef u32 (*fn_80054AB0_Fn1)(u32);
typedef u32 (*fn_80054AB0_Fn2)(u32, u32, u32);
struct fn_80054AB0_lbl_80187434 {
    u32 unk_0;    u8 pad_4[0x13C];
};
extern struct fn_80054AB0_lbl_80187434 lbl_80187434[];
extern u32 lbl_80091D88[];
extern u32 lbl_80091DA4[];
extern u32 lbl_80187430[];

void fn_80054AB0(void *arg0) {
    s32 (*temp_r12)(s32);

    if (arg0 == NULL) {
        if ((*lbl_80187430) != 0) {
            ((s32 (*)(u32, u32 *, s32))((*lbl_80187430)))(lbl_80187434->unk_0, lbl_80091D88, 0);
        }
    } else {
        temp_r12 = (s32 (*)(s32))(*(s32 (**)(s32))((u8 *)((*(void **)((u8 *)(arg0)))) + 20));
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((u8 *)(arg0) + 4));
            (*(s32 *)((u8 *)(arg0) + 4)) = 0;
            (*(void **)((u8 *)(arg0))) = NULL;
            return;
        }
        if ((*lbl_80187430) != 0) {
            ((s32 (*)(u32, u32 *, s32))((*lbl_80187430)))(lbl_80187434->unk_0, lbl_80091DA4, 0);
        }
    }
}
