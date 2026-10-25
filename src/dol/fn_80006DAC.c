#include "types.h"

extern u32 DVDReadAsyncPrio(u32, u32, u32, u32, u32, u32);

struct fn_80006DAC_Arg0 {
    u32 unk_0;
};

u32 fn_80006DAC(struct fn_80006DAC_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg5;
    if ((s32)arg0->unk_0 != 1) {
    v0 += 4;
    v1 = 2;
    t0 = DVDReadAsyncPrio(v0, arg1, arg2, arg3, arg4, v1);
    v0 = t0;
    v1 = v0;
    }
    v0 = v1;
    return v0;
}
