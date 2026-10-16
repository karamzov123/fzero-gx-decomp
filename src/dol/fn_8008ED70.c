#include "types.h"
#include "dolphin/types.h"
#include "sdk_addresses.h"

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;
vu32 __SIRegs[16] : FZGX_ADDR___SIRegs;
extern u8 lbl_801A6398[24];
extern void *memset(void *, int, u32);

void fn_8008ED70(void) {
    memset(lbl_801A6398, 0, 0x18);
    __EXIRegs[10] = 0;
    __SIRegs[15] = 0;
}
