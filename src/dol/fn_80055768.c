#include "types.h"

typedef u32 (*fn_80055768_Fn0)(u32, u32, u32);
struct fn_80055768_lbl_801878C4 {
    u32 unk_0;
};

extern struct fn_80055768_lbl_801878C4 lbl_801878C4[];
extern u32 lbl_80091F7C[];
extern u32 lbl_801878C8[];

s32 fn_80055768(u32 arg0) {
    if (arg0 == 0) {
        if (lbl_801878C8[0] != 0) {
            ((fn_80055768_Fn0)lbl_801878C8[0])(
                lbl_801878C4[0].unk_0, (u32)&lbl_80091F7C, 0);
        }
        return 0;
    }
    return *(s8 *)(arg0 + 2);
}
