#include "types.h"

struct fn_80036388_gx_T {
    u8 pad_0[0x410];
    u32 (*unk_410)(u32, u32);
};

extern struct fn_80036388_gx_T *gx;
extern void fn_800361F0(u32, u32, u32);

void GXLoadTexObj(u32 arg0, u32 arg1) {
    u32 value;

    value = gx->unk_410(arg0, arg1);
    fn_800361F0(arg0, value, arg1);
}
