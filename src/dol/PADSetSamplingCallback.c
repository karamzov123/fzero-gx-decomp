#include "types.h"


/* --- dol/PADSetSamplingCallback.c --- */
extern u32 SIRegisterPollingHandler(u32);
extern u32 SIUnregisterPollingHandler(u32);
extern u32 lbl_801A6830;
extern void SamplingHandler(void);

u32 PADSetSamplingCallback(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6830;
    lbl_801A6830 = arg0;
    if (arg0 != 0) {
    SIRegisterPollingHandler((u32)SamplingHandler);
    } else {
    SIUnregisterPollingHandler((u32)SamplingHandler);
    }
    return v0;
}

/* --- dol/fn_800139E8.c --- */
extern u32 OSDisableInterrupts(void);
extern u32 lbl_801A6834;
extern void SISetCommand(u32 channel, u32 command);
extern void SITransferCommands(void);
extern void OSRestoreInterrupts(u32 state);

void fn_800139E8(u32 channel, u32 command, s32 repeat) {
    u32 state;
    u32 value;
    u32 mask;

    mask = command & 0x600;
    if (repeat <= -0x80) {
        value = 0;
    } else if (repeat >= 0x80) {
        value = 0x100;
    } else {
        value = repeat + 0x80;
    }
    value |= mask;
    value &= 0x7ff;

    state = OSDisableInterrupts();
    if (lbl_801A6834 & (0x80000000u >> channel)) {
        value |= 0x300000;
        SISetCommand(channel, value);
        SITransferCommands();
    }
    OSRestoreInterrupts(state);
}
