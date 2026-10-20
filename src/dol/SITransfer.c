#include <dolphin/si/SIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include <dolphin/types.h>

struct SIBiosBss {
    SIPacket Packet[4];
    OSAlarm Alarm[4];
    OSTime TypeTime[4];
    OSTime XferTime[4];
    SITypeAndStatusCallback TypeCallback[4][4];
    __OSInterruptHandler RDSTHandler[4];
    BOOL InputBufferValid[4];
    u32 InputBuffer[4][2];
    vu32 InputBufferVcount[4];
};

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

extern SIControl Si;

BOOL __SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                  SICallback callback);

BOOL __SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                  SICallback callback);

void AlarmHandler_SIBios(OSAlarm *alarm, OSContext *context);

extern struct SIBiosBss Packet;

BOOL SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                SICallback callback, OSTime delay) {
    struct SIBiosBss *bss = &Packet;

    BOOL enabled;
    SIPacket *packet = ((SIPacket *)((u8 *)bss + (u32) & ((struct SIBiosBss *)0)->Packet) + chan);
    OSTime now;
    OSTime fire;
    enabled = OSDisableInterrupts();
    if (packet->chan != -1 || Si.chan == chan) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    now = __OSGetSystemTime();
    if (delay == 0) {
        fire = now;
    } else {
        fire = delay + (bss->XferTime)[chan];
    }
    if (now < fire) {
        delay = fire - now;
        OSSetAlarm(((OSAlarm *)((u8 *)bss + (u32) & ((struct SIBiosBss *)0)->Alarm) + chan), delay,
                   AlarmHandler_SIBios);
    } else if (__SITransfer(chan, output, outputBytes, input, inputBytes, callback)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }
    packet->chan = chan;
    packet->output = output;
    packet->outputBytes = outputBytes;
    packet->input = input;
    packet->inputBytes = inputBytes;
    packet->callback = callback;
    packet->fire = fire;
    OSRestoreInterrupts(enabled);
    return 1;
}
