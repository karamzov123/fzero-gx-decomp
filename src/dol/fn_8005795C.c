#include "types.h"

typedef u32 (*fn_8005795C_Fn0)(u32, u32);
struct fn_8005795C_Arg2 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);

u32 fn_8005795C(u32 arg0, u32 arg1, struct fn_8005795C_Arg2 *arg2) {
    u32 t1, t2;
    if ((s32)arg2->unk_4 > 0) {
    if (*(u32 *)(arg2) == 0) {
    return arg0;
    }
    fn_80057728();
    if (arg1 > 1) {
    *(u32 *)((u8 *)(u32)arg2 + 4) = 0;
    *(u32 *)((u8 *)(u32)arg2 + 0) = 0;
    if (*(u32 *)(arg0 + 28) != 0) {
    t1 = ((fn_8005795C_Fn0)*(u32 *)(arg0 + 28))(*(u32 *)(arg0 + 32), -3);
    }
    }
    t2 = fn_800576DC();
    return t2;
    }
    return arg0;
}
