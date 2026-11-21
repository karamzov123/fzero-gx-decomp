#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*OSResetCallback)(void);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;

extern OSResetCallback lbl_801A67D8;

extern BOOL lbl_801A67DC;

extern BOOL lbl_801A67E0;

extern OSTime lbl_801A67F0;

void __OSResetSWInterruptHandler(__OSInterrupt interrupt, OSContext *context) {
    OSResetCallback callback;
    lbl_801A67F0 = __OSGetSystemTime();
    while (__OSGetSystemTime() - lbl_801A67F0 <
               (((100) * (((u32)__OSBusClock / 4) / 125000)) / 8) &&
           !(__PIRegs[0] & 0x00010000)) {
        ;
    }
    if (!(__PIRegs[0] & 0x00010000)) {
        lbl_801A67E0 = lbl_801A67DC = 1;
        __OSMaskInterrupts((0x80000000u >> (22)));
        if (lbl_801A67D8) {
            callback = lbl_801A67D8;
            lbl_801A67D8 = ((void *)0);
            callback();
        }
    }
    __PIRegs[0] = 2;
}

extern OSTime __OSStartTime;

u8 GameChoice : FZGX_ADDR_GameChoice;



extern OSTime lbl_801A67E8;


BOOL OSGetResetButtonState(void) {
    BOOL enabled = OSDisableInterrupts();
    BOOL state;
    OSTime now = __OSGetSystemTime();
    u32 reg = __PIRegs[0];
    if (!(reg & 0x00010000)) {
        if (!lbl_801A67DC) {
            lbl_801A67DC = 1;
            state = lbl_801A67E8 ? 1 : 0;
            lbl_801A67F0 = now;
        } else {
            state = lbl_801A67E8 ||
                            ((((100) * (((__OSBusClock) / 4) / 125000)) / 8) < now - lbl_801A67F0)
                        ? 1
                        : 0;
        }
    } else if (lbl_801A67DC) {
        lbl_801A67DC = 0;
        state = lbl_801A67E0;
        if (state) {
            lbl_801A67E8 = now;
        } else {
            lbl_801A67E8 = 0;
        }
    } else if (lbl_801A67E8 && (now - lbl_801A67E8 < ((40) * (((__OSBusClock) / 4) / 1000)))) {
        state = 1;
    } else {
        state = 0;
        lbl_801A67E8 = 0;
    }
    lbl_801A67E0 = state;
    if (GameChoice & 0x3F) {
        OSTime fire = (GameChoice & 0x3F) * 60;
        fire = __OSStartTime + ((fire) * ((__OSBusClock) / 4));
        if (fire < now) {
            now -= fire;
            now = ((now) / ((__OSBusClock) / 4)) / 2;
            if ((now & 1) == 0) {
                state = 1;
            } else {
                state = 0;
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return state;
}

u32 fn_8000F5F0(void) {
    return OSGetResetButtonState();
}
