#include "types.h"
#include "dolphin/types.h"
#include "sdk_addresses.h"

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern vu32 *lbl_801A6678;

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

u32 fn_8008EBF8(u32 arg0) {
    u32 interrupts;
    vu32 *flags;
    u32 value;
    u32 reg;

    interrupts = OSDisableInterrupts();
    flags = &lbl_801A6678[3];
    if (*flags & 4) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }

    *flags |= 4;
    value = (arg0 << 4) | 0x80;
    reg = __EXIRegs[10];
    reg &= 0x405;
    reg |= value;
    __EXIRegs[10] = reg;
    OSRestoreInterrupts(interrupts);
    return 1;
}
