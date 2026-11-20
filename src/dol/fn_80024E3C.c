#include "types.h"

struct fn_80024E3C_Arg1 {
    u8 pad_0[0x13C];
    u8 unk_13C;
};

extern u32 fn_800248D4(u32, u32);

u32 fn_80024E3C(u32 arg0, struct fn_80024E3C_Arg1 *arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg1->unk_13C == 0) {
    v0 = *(u32 *)(v0);
    t0 = fn_800248D4(v0, (u32)arg1);
    v0 = t0;
    }
    return v0;
}
