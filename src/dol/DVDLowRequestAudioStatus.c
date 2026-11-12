#include <types.h>
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
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state

extern DVDLowCallback Callback;

extern OSAlarm AlarmForTimeout;

void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);

static inline void SetTimeoutAlarm(OSTime timeout) {
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout);
}

BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = subcmd | 0xe2000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}
