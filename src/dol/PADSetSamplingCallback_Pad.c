#include "types.h"
#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include "sdk_addresses.h"


/* --- dol/PADSetSamplingCallback_Pad.c --- */
extern u32 SIRegisterPollingHandler(u32);
extern u32 SIUnregisterPollingHandler(u32);
extern u32 lbl_801A6994;
extern void SamplingHandler_Pad(void);

u32 PADSetSamplingCallback_Pad(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6994;
    lbl_801A6994 = arg0;
    if (arg0 != 0) {
    SIRegisterPollingHandler((u32)SamplingHandler_Pad);
    } else {
    SIUnregisterPollingHandler((u32)SamplingHandler_Pad);
    }
    return v0;
}

/* --- dol/__PADDisableRecalibration.c --- */
extern u8 __gUnknown800030E3 : FZGX_ADDR___gUnknown800030E3;

BOOL __PADDisableRecalibration(BOOL disable) {
    BOOL enabled;
    BOOL prev;
    enabled = OSDisableInterrupts();
    prev = (__gUnknown800030E3 & 0x40) ? 1 : 0;
    __gUnknown800030E3 &= (u8)~0x40;
    if (disable) {
        __gUnknown800030E3 |= 0x40;
    }
    OSRestoreInterrupts(enabled);
    return prev;
}
