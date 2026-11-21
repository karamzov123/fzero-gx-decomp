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

void __AI_SRC_INIT(void) {
    OSTime rising_32khz = 0;
    OSTime rising_48khz = 0;
    OSTime diff = 0;
    OSTime t1 = 0;
    OSTime temp = 0;
    u32 temp0 = 0;
    u32 temp1 = 0;
    u32 done = 0;
    u32 volume = 0;
    u32 Init_Cnt = 0;
    u32 walking = 0;
    walking = 0;
    Init_Cnt = 0;
    temp = 0;
    while (!done) {
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] &= ~2;
        __AIRegs[0] = (__AIRegs[0] & ~1) | 1;
        temp0 = __AIRegs[2];
        while (temp0 == __AIRegs[2])
            ;
        rising_32khz = OSGetTime();
        __AIRegs[0] = (__AIRegs[0] & ~2) | 2;
        __AIRegs[0] = (__AIRegs[0] & ~1) | 1;
        temp1 = __AIRegs[2];
        while (temp1 == __AIRegs[2])
            ;
        rising_48khz = OSGetTime();
        diff = rising_48khz - rising_32khz;
        __AIRegs[0] &= ~2;
        __AIRegs[0] &= ~1;
        if (diff < (lbl_801A69B8 - lbl_801A69D8)) {
            temp = lbl_801A69C8;
            done = 1;
            ++Init_Cnt;
        } else if (diff >= (lbl_801A69B8 + lbl_801A69D8) && diff < (lbl_801A69C0 - lbl_801A69D8)) {
            temp = lbl_801A69D0;
            done = 1;
            ++Init_Cnt;
        } else {
            done = 0;
            walking = 1;
            ++Init_Cnt;
        }
    }
    while ((rising_48khz + temp) > OSGetTime())
        ;
}

/* --- dol/fn_8001E7E4.c --- */
extern u32 lbl_801A69E0;
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 state);

u32 fn_8001E7E4(u32 value) {
    u32 previous = lbl_801A69E0;
    u32 state = OSDisableInterrupts();
    lbl_801A69E0 = value;
    OSRestoreInterrupts(state);
    return previous;
}
