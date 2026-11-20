#include "types.h"
typedef u32 (*fn_80070F44_Fn0)(u32, u32);
typedef u32 (*fn_80070F44_Fn1)(u32, u32);
typedef u32 (*fn_80070F44_Fn2)(u32);
typedef u32 (*fn_80070F44_Fn3)(u32);
typedef u32 (*fn_80070F44_Fn4)(u32, u32, u32, u32);
typedef u32 (*fn_80070F44_Fn5)(u32);
typedef u32 (*fn_80070F44_Fn6)(u32);
extern u32 lbl_8015AB70[];
extern u32 lbl_801A6D0C;
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;
extern void fn_8007174C(u32, u32);
extern void fn_80078DA8(void *, void *, u32);


void *fn_80070F44(u32 arg0, u32 arg1, s32 arg_sp0) {
    void *temp_r31;
    s32 temp_r3_3;
    void *temp_r3;
    s32 temp_r3_2;

    temp_r3_2 = ((s32 (*)())(lbl_801A6D24))();
    if (((s32 (*)(u32, s32))(lbl_801A6D20))(arg0, temp_r3_2) == 0) {
        return NULL;
    }
    temp_r3_3 = ((s32 (*)(s32))(lbl_801A6D1C))(temp_r3_2);
    temp_r3 = (((void *(*)(s32))(lbl_801A6D0C))(((temp_r3_3 + 0x1F) & 0xFFFFFFE0) + 0x20));
    if (temp_r3 == NULL) {
        fn_8007174C((u32)(lbl_8015AB70), arg0);
    }
    temp_r31 = ((u8 *)(temp_r3) + 0x20);
    ((s32 (*)(s32, void *, s32, s32))(lbl_801A6D18))(temp_r3_2, temp_r31, temp_r3_3, 0);
    ((s32 (*)(s32))(lbl_801A6D14))(temp_r3_2);
    ((s32 (*)(s32))(lbl_801A6D10))(temp_r3_2);
    fn_80078DA8(temp_r3, temp_r31, arg1);
    return temp_r3;
}
