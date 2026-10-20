#include <dolphin/si/SIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include "sdk_addresses.h"

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

extern SIControl Si;

extern u32 Type[4];

OSTime TypeTime_8015CB30[4] __attribute__((aligned(8)));

void GetTypeCallback(s32 chan, u32 error, OSContext *context);

void GetTypeCallback(s32 chan, u32 error, OSContext *context);

#pragma opt_propagation off
u32 SIGetType(s32 chan) {
    static u32 cmdTypeAndStatus;
    BOOL enabled;
    u32 type;
    OSTime diff;
    enabled = OSDisableInterrupts();
    type = Type[chan];
    diff = __OSGetSystemTime() - TypeTime_8015CB30[chan];
    if (Si.poll & (0x80 >> chan)) {
        if (type != 0x0008) {
            TypeTime_8015CB30[chan] = __OSGetSystemTime();
            OSRestoreInterrupts(enabled);
            return type;
        } else {
            type = Type[chan] = 0x0080;
        }
    } else if (diff <= ((50) * (((u32)__OSBusClock / 4) / 1000)) && type != 0x0008) {
        OSRestoreInterrupts(enabled);
        return type;
    } else if (diff <= ((75) * (((u32)__OSBusClock / 4) / 1000))) {
        Type[chan] = 0x0080;
    } else {
        type = Type[chan] = 0x0080;
    }
    TypeTime_8015CB30[chan] = __OSGetSystemTime();
    SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback,
               (((65) * (((u32)__OSBusClock / 4) / 125000)) / 8));
    OSRestoreInterrupts(enabled);
    return type;
}
#pragma opt_propagation reset

