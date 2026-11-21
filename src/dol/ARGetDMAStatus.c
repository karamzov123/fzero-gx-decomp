#include <types.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include "types.h"
#pragma peephole off

/* --- dol/__AI_SRC_INIT.c --- */
vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;

extern OSTime lbl_801A69B8;

extern OSTime lbl_801A69C0;

extern OSTime lbl_801A69C8;

extern OSTime lbl_801A69D0;

extern OSTime lbl_801A69D8;

void __AI_SRC_INIT(void);

/* --- dol/fn_8001E7E4.c --- */
extern u32 lbl_801A69E0;
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 state);

u32 fn_8001E7E4(u32 value);

/* --- dol/ARGetDMAStatus.c --- */
u32 ARGetDMAStatus(void) {
    u32 v0;
    u32 t0;
    t0 = OSDisableInterrupts();
    v0 = (*(u16 *)0xCC00500A & 0x200);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    OSRestoreInterrupts(t0);
    return v0;
}
