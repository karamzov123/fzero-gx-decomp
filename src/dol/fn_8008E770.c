#include "types.h"
#include "dolphin/types.h"
#include "dolphin/os/OSInterrupt.h"

struct fn_8008E770_lbl_801A6678_T {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
    s32 length;
    void *buffer;
};
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask);
extern struct fn_8008E770_lbl_801A6678_T *lbl_801A6678;
extern void fn_8008EB4C(s32, s32);
#include "sdk_addresses.h"
extern vu32 __EXIRegs[] : FZGX_ADDR___EXIRegs;

#pragma opt_propagation off
BOOL fn_8008E770(void *arg0, s32 arg1, u32 arg2, u32 arg3) {
    s32 chan = 2;
    BOOL old;
    u32 data;
    s32 i;
    volatile u32 *state; // fzgx-allow: S2 SDK asynchronous state
    volatile u32 padding[2];
    old = OSDisableInterrupts() + 0;
    state = &lbl_801A6678->unk_C;
    if ((*state & 3) || !(*state & 4)) {
        OSRestoreInterrupts(old);
        return 0;
    }
    lbl_801A6678->unk_4 = arg3;
    if (lbl_801A6678->unk_4 != 0) {
        fn_8008EB4C(0, 1);
        __OSUnmaskInterrupts(0x200000u >> (chan * 3));
    }
    lbl_801A6678->unk_C |= 2;
    if (arg2 != 0) {
        i = 0;
        data = 0;
        for (; i < arg1; i++) {
            data |= ((u8 *)arg0)[i] << ((3 - i) * 8);
        }
        __EXIRegs[14] = data;
    }
    lbl_801A6678->buffer = arg0;
    lbl_801A6678->length = arg2 != 1 ? arg1 : 0;
    __EXIRegs[13] = (arg2 << 2) | 1 | ((arg1 - 1) << 4);
    OSRestoreInterrupts(old);
    return 1;
}
