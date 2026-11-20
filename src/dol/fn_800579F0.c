#include "types.h"


/* --- dol/fn_800579F0.c --- */
typedef u32 (*fn_800579F0_Fn0)(u32, u32);
extern u32 fn_80057728(void);

s32 fn_800576DC();                              /* extern */

void fn_800579F0(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 var_r0;
    s32 (*temp_r12)(s32, s32);
    s32 temp_r3;

    fn_80057728();
    if (arg1 == 0) {
        (*(s32 *)((u8 *)(arg3) + 4)) = 0;
        (*(s32 *)((u8 *)(arg3) + 0)) = 0;
    } else if (arg1 == 1) {
        temp_r3 = *(s32 *)((u8 *)(arg0) + 12);
        var_r0 = arg2;
        if (temp_r3 < arg2) {
            var_r0 = temp_r3;
        }
        (*(s32 *)((u8 *)(arg3) + 4)) = var_r0;
        (*(s32 *)((u8 *)(arg3) + 0)) = (s32) ((*(s32 *)((u8 *)(arg0) + 20)) + (*(s32 *)((u8 *)(arg0) + 16)));
        (*(s32 *)((u8 *)(arg0) + 16)) = (s32) ((*(s32 *)((u8 *)(arg0) + 16)) + (*(s32 *)((u8 *)(arg3) + 4)));
        (*(s32 *)((u8 *)(arg0) + 12)) = (s32) ((*(s32 *)((u8 *)(arg0) + 12)) - (*(s32 *)((u8 *)(arg3) + 4)));
    } else {
        (*(s32 *)((u8 *)(arg3) + 4)) = 0;
        (*(s32 *)((u8 *)(arg3) + 0)) = 0;
        temp_r12 = (s32 (*)(s32, s32))(*(s32 (**)(s32, s32))((u8 *)(arg0) + 28));
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((u8 *)(arg0) + 32), -3);
        }
    }
    fn_800576DC();
}

/* --- dol/fn_80057AD8.c --- */
typedef void (*fn_80057AD8_Fn0)(u32, s32);

struct fn_80057AD8_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0xC];
    fn_80057AD8_Fn0 unk_1C;
    u32 unk_20;
};

s32 fn_80057AD8(struct fn_80057AD8_Arg0 *arg0, s32 arg1) {
    if (arg1 == 1) {
        return arg0->unk_C;
    } else if (arg1 == 0) {
        return 0;
    } else {
        if (arg0->unk_1C != 0) {
            arg0->unk_1C(arg0->unk_20, -3);
        }
        return 0;
    }
}
