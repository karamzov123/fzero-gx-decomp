#include "types.h"

typedef u32 (*fn_80055D94_Fn0)(u32, u32, u32);
struct fn_80055D94_lbl_801878C4 {
    u32 unk_0;
};

extern struct fn_80055D94_lbl_801878C4 lbl_801878C4[];
extern u32 lbl_80091F7C[];
extern u32 lbl_801878C8[];

u32 fn_80055D94(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        if (lbl_801878C8[0] != 0) {
            v0 = lbl_801878C4[0].unk_0;
            t0 = ((fn_80055D94_Fn0)lbl_801878C8[0])(v0, (u32)&lbl_80091F7C, 0);
            v0 = t0;
        }
        v0 = 0;
    } else {
        v0 = *(u32 *)(v0 + 28);
    }
    return v0;
}
