#include <dolphin/si/SIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

struct SDK_SIBios____bss_0 {
    SIPacket sdk_Packet[4];
    OSAlarm sdk_Alarm[4];
    OSTime sdk_TypeTime[4];
    OSTime sdk_XferTime[4];
    SITypeAndStatusCallback sdk_TypeCallback[4][4];
    __OSInterruptHandler sdk_RDSTHandler[4];
    BOOL sdk_InputBufferValid[4];
    u32 sdk_InputBuffer[4][2];
    vu32 sdk_InputBufferVcount[4];
};

void OSRegisterVersion(const char *id);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

void SISetSamplingRate(u32 msec);

u32 SIGetType(s32 chan);

vu32 __SIRegs[64] : FZGX_ADDR___SIRegs;

extern const char *__SIVersion;

extern SIControl Si;

void SIInterruptHandler(__OSInterrupt interrupt, OSContext *context);

extern struct SDK_SIBios____bss_0 Packet;

#pragma opt_propagation off
void SIInit(void) {
    struct SDK_SIBios____bss_0 *sdk_storage____bss_0 = &Packet;

    OSRegisterVersion(__SIVersion);
    (sdk_storage____bss_0->sdk_Packet)[0].chan = (sdk_storage____bss_0->sdk_Packet)[1].chan =
        (sdk_storage____bss_0->sdk_Packet)[2].chan = (sdk_storage____bss_0->sdk_Packet)[3].chan =
            -1;
    Si.poll = 0;
    SISetSamplingRate(0);
    while (__SIRegs[13] & 1)
        ;
    __SIRegs[13] = 0x80000000;
    __OSSetInterruptHandler(20, SIInterruptHandler);
    __OSUnmaskInterrupts((0x80000000u >> (20)));
    SIGetType(0);
    SIGetType(1);
    SIGetType(2);
    SIGetType(3);
}
#pragma opt_propagation reset

