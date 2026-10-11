#include "types.h"

struct fn_8003D42C_Arg0 {
    u8 pad_0[0x400];
    u32 unk_400;
    u8 pad_404[0xC];
    u32 unk_410;
    u32 unk_414;
};

#pragma opt_propagation off
#pragma peephole off
u32 fn_8003D42C(struct fn_8003D42C_Arg0 *arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1_2;
    u32 v1;
    u32 v2;
    v0 = arg2;
    if ((s32)arg0->unk_414 == 33) {
        v1 = arg0->unk_400;
        {
            u32 state = 26;
            /* Preserve the ordered input-byte read before updating the state. */
            v0 = *(volatile u8 *)v1;
            arg0->unk_414 = state;
        }
        if (v0 != 255) {
            v2 = v1 + 1;
            arg0->unk_410 = v0;
            v0 = (v0 >> 7) & 1;
            arg0->unk_400 = v2;
        } else {
            /* Resume marker scanning at its shared test. */
            goto test;
retry:
            v1--;
test:
            if (*(u8 *)(v1 + 1) != 0) {
                v0 = *(u8 *)(v1 + 2);
                v1 += 3;
                if (v0 == 255) {
                    /* Skip another marker triple. */
                    goto retry;
                }
                arg0->unk_410 = v0;
                v0 = (v0 >> 7) & 1;
                arg0->unk_400 = v1;
            } else {
                v1 += 2;
                arg0->unk_410 = v0;
                v0 = (v0 >> 7) & 1;
                arg0->unk_400 = v1;
            }
        }
    } else {
        v1_2 = arg0->unk_414;
        v0 = arg0->unk_410;
        arg0->unk_414 = v1_2 + 1;
        v0 = __rlwnm(v0, v1_2, 31, 31);
    }
    return v0;
}
#pragma peephole reset

