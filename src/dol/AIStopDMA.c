#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/os/OSInterrupt.h>


/* --- dol/AIStopDMA.c --- */
vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

void AIStopDMA(void) { __DSPRegs[27] &= ~0x8000; }

/* --- dol/AISetStreamPlayState.c --- */
u32 AIGetStreamPlayState();

u32 AIGetStreamSampleRate();

void AISetStreamVolLeft(u8 vol);

void AISetStreamVolRight(u8 vol);

u8 AIGetStreamVolLeft();

u8 AIGetStreamVolRight();

vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;

void __AI_SRC_INIT(void);

void AISetStreamVolLeft(u8 volume);

void AISetStreamVolRight(u8 volume);

void AISetStreamPlayState(u32 state) {
    s32 oldInts;
    u8 volRight;
    u8 volLeft;
    if (state == AIGetStreamPlayState()) {
        return;
    }
    if ((AIGetStreamSampleRate() == 0U) && (state == 1)) {
        volRight = AIGetStreamVolRight();
        volLeft = AIGetStreamVolLeft();
        AISetStreamVolRight(0);
        AISetStreamVolLeft(0);
        oldInts = OSDisableInterrupts();
        __AI_SRC_INIT();
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~1) | 1;
        OSRestoreInterrupts(oldInts);
        AISetStreamVolLeft(volRight);
        AISetStreamVolRight(volLeft);
    } else {
        __AIRegs[0] = (__AIRegs[0] & ~1) | state;
    }
}
