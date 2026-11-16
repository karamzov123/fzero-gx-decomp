#include <dolphin/si/SIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

u32 VIGetCurrentLine(void);
void OSRegisterVersion(const char *id);
__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);
void OSCancelAlarm(OSAlarm *alarm);
void SISetSamplingRate(u32 msec);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __SIRegs[64] : FZGX_ADDR___SIRegs;

extern u32 lbl_801A6818;

const char *__SIVersion = "<< Dolphin SDK - SI\trelease build: Sep  5 2002 05:33:08 (0x2301) >>";

static SIControl Si = {
    -1, 0, 0, ((void *)0), ((void *)0),
};

static SIPacket Packet[4];

static OSAlarm Alarm[4];

static u32 Type[4] = {
    0x0008,
    0x0008,
    0x0008,
    0x0008,
};

static OSTime TypeTime[4];

static OSTime XferTime[4];

static SITypeAndStatusCallback TypeCallback[4][4];

static __OSInterruptHandler RDSTHandler[4];

static BOOL InputBufferValid[4];

static u32 InputBuffer[4][2];

static vu32 InputBufferVcount[4];

BOOL __SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                  SICallback callback);
void GetTypeCallback(s32 chan, u32 error, OSContext *context);
u32 SIGetType(s32 chan);

BOOL SIBusy(void) { return Si.chan != -1 ? 1 : 0; }

BOOL SIIsChanBusy(s32 chan) { return (Packet[chan].chan != -1 || Si.chan == chan); }

static inline void SIClearTCInterrupt(void) {
    u32 reg;
    reg = __SIRegs[13];
    reg |= 0x80000000;
    reg &= ~0x00000001;
    __SIRegs[13] = reg;
}

u32 CompleteTransfer(void) {
    u32 sr;
    u32 i;
    u32 rLen;
    u8 *input;
    sr = __SIRegs[14];
    SIClearTCInterrupt();
    if (Si.chan != -1) {
        XferTime[Si.chan] = __OSGetSystemTime();
        input = Si.input;
        rLen = Si.inputBytes / 4;
        for (i = 0; i < rLen; i++) {
            *(u32 *)input = __SIRegs[32 + i];
            input += 4;
        }
        rLen = Si.inputBytes & 3;
        if (rLen) {
            u32 temp = __SIRegs[32 + i];
            for (i = 0; i < rLen; i++) {
                *input++ = (u8)((temp >> ((3 - i) * 8)) & 0xff);
            }
        }
        if (__SIRegs[13] & 0x20000000) {
            sr >>= 8 * (3 - Si.chan);
            sr &= 0xf;
            if ((sr & 0x0008) && !(Type[Si.chan] & 0x0080)) {
                Type[Si.chan] = 0x0008;
            }
            if (sr == 0) {
                sr = 0x0004;
            }
        } else {
            TypeTime[Si.chan] = __OSGetSystemTime();
            sr = 0;
        }
        Si.chan = -1;
    }
    return sr;
}

static inline void SITransferNext(s32 chan) {
    int i;
    SIPacket *packet;
    for (i = 0; i < 4; ++i) {
        ++chan;
        chan %= 4;
        packet = &Packet[chan];
        if (packet->chan != -1 && packet->fire <= __OSGetSystemTime()) {
            if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input,
                             packet->inputBytes, packet->callback)) {
                OSCancelAlarm(&Alarm[chan]);
                packet->chan = -1;
            }
            break;
        }
    }
}

void SIInterruptHandler(__OSInterrupt interrupt, OSContext *context) {
    u32 reg;
    reg = __SIRegs[13];
    if ((reg & 0xc0000000) == 0xc0000000) { /* fzgx-allow: A1 SI transfer-complete interrupt and mask bits, not an address */
        s32 chan;
        u32 sr;
        SICallback callback;
        chan = Si.chan;
        sr = CompleteTransfer();
        callback = Si.callback;
        Si.callback = 0;
        SITransferNext(chan);
        if (callback) {
            callback(chan, sr, context);
        }
        sr = __SIRegs[14];
        sr &= 0xf000000 >> (8 * chan);
        __SIRegs[14] = sr;
        if (Type[chan] == 0x0080 && !SIIsChanBusy(chan)) {
            static u32 cmdTypeAndStatus;
            SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback,
                       (((65) * (((u32)__OSBusClock / 4) / 125000)) / 8));
        }
    }
    if ((reg & 0x18000000) == 0x18000000) {
        int i;
        u32 vcount;
        u32 x;
        vcount = VIGetCurrentLine() + 1;
        x = (Si.poll & 0x03ff0000) >> 16;
        for (i = 0; i < 4; ++i) {
            if (SIGetResponseRaw(i)) {
                InputBufferVcount[i] = vcount;
            }
        }
        for (i = 0; i < 4; ++i) {
            if (!(Si.poll & (0x80000000 >> (31 - 7 + i)))) {
                continue;
            }
            if (InputBufferVcount[i] == 0 || InputBufferVcount[i] + (x / 2) < vcount) {
                return;
            }
        }
        for (i = 0; i < 4; ++i) {
            InputBufferVcount[i] = 0;
        }
        for (i = 0; i < 4; ++i) {
            if (RDSTHandler[i]) {
                RDSTHandler[i](interrupt, context);
            }
        }
    }
}

BOOL SIEnablePollingInterrupt(BOOL enable) {
    BOOL enabled;
    BOOL rc;
    u32 reg;
    int i;
    enabled = OSDisableInterrupts();
    reg = __SIRegs[13];
    rc = (reg & 0x08000000) ? 1 : 0;
    if (enable) {
        reg |= 0x08000000;
        for (i = 0; i < 4; ++i) {
            InputBufferVcount[i] = 0;
        }
    } else {
        reg &= ~0x08000000;
    }
    reg &= ~(SI_COMCSR_TCINT | SI_COMCSR_TSTART);
    __SIRegs[13] = reg;
    OSRestoreInterrupts(enabled);
    return rc;
}

BOOL SIRegisterPollingHandler(__OSInterruptHandler handler) {
    BOOL enabled;
    int i;
    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; ++i) {
        if (RDSTHandler[i] == handler) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    for (i = 0; i < 4; ++i) {
        if (RDSTHandler[i] == 0) {
            RDSTHandler[i] = handler;
            SIEnablePollingInterrupt(1);
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

BOOL SIUnregisterPollingHandler(__OSInterruptHandler handler) {
    BOOL enabled;
    int i;
    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; ++i) {
        if (RDSTHandler[i] == handler) {
            RDSTHandler[i] = 0;
            for (i = 0; i < 4; ++i) {
                if (RDSTHandler[i]) {
                    break;
                }
            }
            if (i == 4) {
                SIEnablePollingInterrupt(0);
            }
            OSRestoreInterrupts(enabled);
            return 1;
            break;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

#pragma opt_propagation off
void SIInit(void) {
    OSRegisterVersion(__SIVersion);
    Packet[0].chan = Packet[1].chan = Packet[2].chan = Packet[3].chan = -1;
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

typedef struct SIComm_s {
    u32 tcint : 1;
    u32 tcintmsk : 1;
    u32 comerr : 1;
    u32 rdstint : 1;
    u32 rdstintmsk : 1;
    u32 pad0 : 4;
    u32 outlngth : 7;
    u32 pad1 : 1;
    u32 inlngth : 7;
    u32 pad2 : 5;
    u32 channel : 2;
    u32 tstart : 1;
} SIComm_s;

typedef union SIComm_u {
    u32 val;
    SIComm_s f;
} SIComm_u;

BOOL __SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                  SICallback callback) {
    BOOL enabled;
    u32 rLen;
    u32 i;
    u32 sr;
    SIComm_u comcsr;
    enabled = OSDisableInterrupts();
    if (Si.chan != -1) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    sr = __SIRegs[14];
    sr &= (0xf000000) >> (8 * chan);
    __SIRegs[14] = sr;
    Si.chan = chan;
    Si.callback = callback;
    Si.inputBytes = inputBytes;
    Si.input = input;
    rLen = (((u32)(outputBytes) + (4) - 1) & ~((4) - 1)) / 4;
    for (i = 0; i < rLen; i++) {
        __SIRegs[32 + i] = ((u32 *)output)[i];
    }
    comcsr.val = __SIRegs[13];
    comcsr.f.tcint = 1;
    comcsr.f.tcintmsk = callback ? 1 : 0;
    comcsr.f.outlngth = (outputBytes == 128) ? 0 : outputBytes;
    comcsr.f.inlngth = (inputBytes == 128) ? 0 : inputBytes;
    comcsr.f.channel = chan;
    comcsr.f.tstart = 1;
    __SIRegs[13] = comcsr.val;
    OSRestoreInterrupts(enabled);
    return 1;
}

u32 SIGetStatus(s32 chan) {
    BOOL enabled;
    u32 sr;
    int chanShift;
    enabled = OSDisableInterrupts();
    sr = __SIRegs[14];
    chanShift = 8 * (4 - 1 - chan);
    sr >>= chanShift;
    if (sr & 0x0008) {
        if (!(Type[chan] & 0x0080)) {
            Type[chan] = 0x0008;
        }
    }
    OSRestoreInterrupts(enabled);
    return sr;
}

void SISetCommand(s32 chan, u32 command) { __SIRegs[3 * chan] = command; }

void SITransferCommands(void) { __SIRegs[14] = 0x80000000; }

u32 SISetXY(u32 x, u32 y) {
    u32 poll;
    BOOL enabled;
    poll = x << 16;
    poll |= y << 8;
    enabled = OSDisableInterrupts();
    Si.poll &= ~(0x03ff0000 | 0x0000ff00);
    Si.poll |= poll;
    poll = Si.poll;
    __SIRegs[12] = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}

u32 SIEnablePolling(u32 poll) {
    BOOL enabled;
    u32 en;
    if (poll == 0) {
        return Si.poll;
    }
    enabled = OSDisableInterrupts();
    poll >>= (31 - 7);
    en = poll & 0xf0;
    poll &= (en >> 4) | 0x03fffff0;
    poll &= ~0x03ffff00;
    Si.poll &= ~(en >> 4);
    Si.poll |= poll;
    poll = Si.poll;
    SITransferCommands();
    __SIRegs[12] = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}

u32 SIDisablePolling(u32 poll) {
    BOOL enabled;
    if (poll == 0) {
        return Si.poll;
    }
    enabled = OSDisableInterrupts();
    poll >>= (31 - 7);
    poll &= 0xf0;
    poll = Si.poll & ~poll;
    __SIRegs[12] = poll;
    Si.poll = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}

BOOL SIGetResponseRaw(s32 chan) {
    u32 sr;
    sr = SIGetStatus(chan);
    if (sr & 0x0020) {
        InputBuffer[chan][0] = __SIRegs[3 * chan + 1];
        InputBuffer[chan][1] = __SIRegs[3 * chan + 2];
        InputBufferValid[chan] = 1;
        return 1;
    }
    return 0;
}

BOOL SIGetResponse(s32 chan, void *data) {
    BOOL rc;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    SIGetResponseRaw(chan);
    rc = InputBufferValid[chan];
    InputBufferValid[chan] = 0;
    if (rc) {
        ((u32 *)data)[0] = InputBuffer[chan][0];
        ((u32 *)data)[1] = InputBuffer[chan][1];
    }
    OSRestoreInterrupts(enabled);
    return rc;
}

void AlarmHandler_SIBios(OSAlarm *alarm, OSContext *context) {
    s32 chan;
    SIPacket *packet;
    chan = alarm - Alarm;
    packet = &Packet[chan];
    if (packet->chan != -1) {
        if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input,
                         packet->inputBytes, packet->callback)) {
            packet->chan = -1;
        }
    }
}

BOOL SITransfer(s32 chan, void *output, u32 outputBytes, void *input, u32 inputBytes,
                SICallback callback, OSTime delay) {
    BOOL enabled;
    SIPacket *packet = &Packet[chan];
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
        fire = delay + XferTime[chan];
    }
    if (now < fire) {
        delay = fire - now;
        OSSetAlarm(&Alarm[chan], delay, AlarmHandler_SIBios);
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

static inline void CallTypeAndStatusCallback(s32 chan, u32 type) {
    SITypeAndStatusCallback callback;
    int i;
    for (i = 0; i < 4; ++i) {
        callback = TypeCallback[chan][i];
        if (callback) {
            TypeCallback[chan][i] = 0;
            callback(chan, type);
        }
    }
}

void GetTypeCallback(s32 chan, u32 error, OSContext *context) {
    static u32 cmdFixDevice[4];
    u32 type;
    u32 chanBit;
    BOOL fix;
    u32 id;
    Type[chan] &= ~0x0080;
    Type[chan] |= error;
    TypeTime[chan] = __OSGetSystemTime();
    type = Type[chan];
    chanBit = 0x80000000 >> chan;
    fix = (BOOL)(lbl_801A6818 & chanBit);
    lbl_801A6818 &= ~chanBit;
    if ((error & (0x0001 | 0x0002 | 0x0008 | 0x0004)) || (type & 0x18000000u) != 0x08000000u ||
        !(type & 0x80000000) || (type & 0x04000000)) {
        OSSetWirelessID(chan, 0);
        CallTypeAndStatusCallback(chan, Type[chan]);
        return;
    }
    id = (u32)(OSGetWirelessID(chan) << 8);
    if (fix && (id & 0x00100000)) {
        cmdFixDevice[chan] = 0x4Eu << 24 | (id & (0x000f0000 | 0x00c0ff00)) | 0x00100000;
        Type[chan] = 0x0080;
        SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
        return;
    }
    if (type & 0x00100000) {
        if ((id & (0x000f0000 | 0x00c0ff00)) != (type & (0x000f0000 | 0x00c0ff00))) {
            if (!(id & 0x00100000)) {
                id = type & (0x000f0000 | 0x00c0ff00);
                id |= 0x00100000;
                OSSetWirelessID(chan, (u16)((id >> 8) & 0xffff));
            }
            cmdFixDevice[chan] = 0x4E << 24 | id;
            Type[chan] = 0x0080;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
            return;
        }
    } else if (type & 0x40000000) {
        id = type & (0x000f0000 | 0x00c0ff00);
        id |= 0x00100000;
        OSSetWirelessID(chan, (u16)((id >> 8) & 0xffff));
        cmdFixDevice[chan] = 0x4E << 24 | id;
        Type[chan] = 0x0080;
        SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
        return;
    } else {
        OSSetWirelessID(chan, 0);
    }
    CallTypeAndStatusCallback(chan, Type[chan]);
}

u32 SIGetType(s32 chan) {
    static u32 cmdTypeAndStatus;
    BOOL enabled;
    u32 type;
    OSTime diff;
    enabled = OSDisableInterrupts();
    type = Type[chan];
    diff = __OSGetSystemTime() - TypeTime[chan];
    if (Si.poll & (0x80 >> chan)) {
        if (type != 0x0008) {
            TypeTime[chan] = __OSGetSystemTime();
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
    TypeTime[chan] = __OSGetSystemTime();
    SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback,
               (((65) * (((u32)__OSBusClock / 4) / 125000)) / 8));
    OSRestoreInterrupts(enabled);
    return type;
}

u32 SIGetTypeAsync(s32 chan, SITypeAndStatusCallback callback) {
    BOOL enabled;
    u32 type;
    enabled = OSDisableInterrupts();
    type = SIGetType(chan);
    if (Type[chan] & 0x0080) {
        int i;
        for (i = 0; i < 4; ++i) {
            if (TypeCallback[chan][i] == callback) {
                break;
            }
            if (TypeCallback[chan][i] == 0) {
                TypeCallback[chan][i] = callback;
                break;
            }
        }
    } else {
        callback(chan, type);
    }
    OSRestoreInterrupts(enabled);
    return type;
}

u32 SIDecodeType(u32 type) {
    u32 error;
    error = type & 0xff;
    type &= ~0xff;
    if (error & 0x0008) {
        return 0x0008;
    }
    if (error & (0x0001 | 0x0002 | 0x0004 | 0x0040)) {
        return 0x0040;
    }
    if (error) {
        return 0x0080;
    }
    if ((type & 0x18000000u) == 0x00000000u) {
        switch (type & 0xffff0000) {
        case (0x00000000u | 0x05000000):
        case (0x00000000u | 0x00010000):
        case (0x00000000u | 0x00020000):
        case (0x00000000u | 0x02000000):
        case (0x00000000u | 0x00040000):
            return type & 0xffff0000;
            break;
        }
        return 0x0040;
    }
    if ((type & 0x18000000u) != 0x08000000u) {
        return 0x0040;
    }
    switch (type & 0xffff0000) {
    case (0x08000000u | 0x01000000):
    case (0x08000000u | 0x00000000):
        return type & 0xffff0000;
        break;
    }
    if ((type & 0xffe00000) == (0x08000000u | 0x00200000)) {
        return (0x08000000u | 0x00200000);
    }
    if ((type & 0x80000000) && !(type & 0x04000000)) {
        if ((type & (0x08000000u | 0x80000000 | 0x01000000 | 0x02000000 | 0x00100000)) ==
            (0x08000000u | 0x80000000 | 0x01000000 | 0x02000000 | 0x00100000)) {
            return (0x08000000u | 0x80000000 | 0x01000000 | 0x02000000 | 0x00100000);
        } else if (!(type & 0x02000000)) {
            return (0x08000000u | 0x80000000);
        }
    }
    if ((type & (0x08000000u | 0x01000000)) == (0x08000000u | 0x01000000)) {
        return (0x08000000u | 0x01000000);
    }
    return 0x0040;
}

u32 SIProbe(s32 chan) { return SIDecodeType(SIGetType(chan)); }

char *fn_8001317C(u32 type) {
    switch (SIDecodeType(type)) {
    case 0x0008:
        return "No response";
    case 0x0080:
        return "Busy";
    case 0x05000000:
        return "N64 controller";
    case 0x00010000:
        return "N64 microphone";
    case 0x00020000:
        return "N64 keyboard";
    case 0x02000000:
        return "N64 mouse";
    case 0x00040000:
        return "GameBoy Advance";
    case 0x09000000:
        return "Standard controller";
    case 0x88000000:
        return "Wireless receiver";
    case 0x8B100000:
        return "WaveBird controller";
    case 0x08200000:
        return "Keyboard";
    case 0x08000000:
        return "Steering";
    case 0x0040:
    default:
        return "Unknown";
    }
}
