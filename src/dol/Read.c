#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt_801A6858; // fzgx-allow: S2 SDK asynchronous state

extern u32 lbl_801A685C;

extern DVDLowCallback Callback_801A6860;

extern OSTime lbl_801A6890;

// Hardware or OS state can change asynchronously.
extern volatile BOOL lbl_801A6898; // fzgx-allow: S2 SDK asynchronous state

void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);

static unsigned char CommandList[60];

static unsigned char fzgx_pool_gap____bss_0_3c[44];

static OSAlarm AlarmForTimeout;

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&CommandList;
    sink = *(unsigned char *)&fzgx_pool_gap____bss_0_3c;
    sink = *(unsigned char *)&AlarmForTimeout;
}
#pragma section code_type ".text"

static inline void SetTimeoutAlarm(OSTime timeout) {
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout);
}

void Read(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    StopAtNextInt_801A6858 = 0;
    lbl_801A6898 = 1;
    Callback_801A6860 = callback;
    lbl_801A6890 = __OSGetSystemTime();
    __DIRegs[2] = 0xa8000000;
    __DIRegs[3] = offset / 4;
    __DIRegs[4] = length;
    __DIRegs[5] = (u32)addr;
    __DIRegs[6] = length;
    lbl_801A685C = length;
    __DIRegs[7] = 3;
    if (length > 0xa00000) {
        SetTimeoutAlarm(((20) * ((u32)__OSBusClock / 4)));
    } else {
        SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    }
}
