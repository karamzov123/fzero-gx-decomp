#include "types.h"
#include "dolphin/types.h"
#include "dolphin/os/OSInterrupt.h"
#include "sdk_addresses.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern u8 lbl_801A6E3C;
extern u32 lbl_801A6E38;
extern u32 lbl_801A6E28;

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

void fn_8008F838(u32 *arg0, u32 arg1) {
    BOOL enabled = OSDisableInterrupts();
    lbl_801A6E38 = (u32)&lbl_801A6E3C;
    *arg0 = lbl_801A6E38;
    lbl_801A6E28 = arg1;
    __OSMaskInterrupts(0x18000);
    __EXIRegs[10] = 0;
    OSRestoreInterrupts(enabled);
}
