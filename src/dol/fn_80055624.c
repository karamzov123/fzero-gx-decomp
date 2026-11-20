#include "types.h"

typedef u32 (*fn_80055624_Fn0)(u32, u32, u32);
typedef u32 (*fn_80055624_Fn1)(u32, u32, u32);
struct fn_80055624_lbl_801878C4 {
    u32 unk_0;
};

extern struct fn_80055624_lbl_801878C4 lbl_801878C4[];
extern u32 lbl_80091F94[];
extern u32 lbl_80091FAC[];
extern u32 lbl_801878C8[];

void fn_80055624(u32 arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    u32 v4;
    u32 v5;
    u32 t0;

    v0 = arg0;
    if (arg0 == 0) {
        if (lbl_801878C8[0] != 0) {
            v0 = lbl_801878C4[0].unk_0;
            t0 = ((fn_80055624_Fn0)lbl_801878C8[0])(v0, (u32)&lbl_80091F94, 0);
            v0 = t0;
        }
    } else {
        v1 = *(s32 *)(v0 + 16);
        if ((v1 % 32) != 0) {
            if (lbl_801878C8[0] != 0) {
                v0 = lbl_801878C4[0].unk_0;
                t0 = ((fn_80055624_Fn1)lbl_801878C8[0])(v0, (u32)&lbl_80091FAC, 0);
                v0 = t0;
            }
        } else {
            v4 = *(u32 *)(v0 + 28);
            v5 = v4 * v1;
            *(u32 *)((u8 *)v0 + 16) = arg1;
            *(u32 *)((u8 *)v0 + 24) = (*(s32 *)((u8 *)v0 + 16) - 1 + *(s32 *)((u8 *)v0 + 20)) / *(s32 *)((u8 *)v0 + 16);
            *(u32 *)((u8 *)v0 + 28) = (s32)v5 / *(s32 *)((u8 *)v0 + 16);
            *(u32 *)((u8 *)v0 + 32) = *(u32 *)((u8 *)v0 + 36) * arg1;
        }
    }
}
