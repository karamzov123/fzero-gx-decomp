#include "types.h"

typedef u32 (*fn_80059CA4_Fn0)(u32, u32, u32);
struct fn_80059CA4_lbl_8019017C {
    u32 unk_0;
    u8 pad_4[0x9F0];
};

extern struct fn_80059CA4_lbl_8019017C lbl_8019017C[];
extern u32 lbl_80092664[];
extern u32 lbl_80190178[];

u32 fn_80059CA4(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        if (lbl_80190178[0] != 0) {
            v0 = lbl_8019017C[0].unk_0;
            t0 = ((fn_80059CA4_Fn0)lbl_80190178[0])(v0, (u32)&lbl_80092664, 0);
            v0 = t0;
        }
        v0 = 0;
    } else {
        v0 = *(u32 *)(v0 + 4);
    }
    return v0;
}

