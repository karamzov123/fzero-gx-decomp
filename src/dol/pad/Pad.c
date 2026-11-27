#include <dolphin/types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/si.h>
#include <dolphin/pad.h>
#include "sdk_addresses.h"

typedef unsigned int uint;

typedef struct PADClampRegion {
    u8 minTrigger;
    u8 maxTrigger;
    s8 minStick;
    s8 maxStick;
    s8 xyStick;
    s8 minSubstick;
    s8 maxSubstick;
    s8 xySubstick;
    s8 radStick;
    s8 radSubstick;
} PADClampRegion;

typedef void (*SPECCallback)(s32, PADStatus *, u32 *);
typedef void (*PADSamplingCallback)(void);

extern u32 __PADSpec;
extern const char *lbl_801A64B0;
extern s32 lbl_801A64B4;
extern u32 lbl_801A64B8;
extern u32 lbl_801A64BC;
extern u32 lbl_801A64C0;
extern SPECCallback lbl_801A64C4;
extern u32 lbl_801A64C8;
extern u32 lbl_801A64CC;
extern u32 lbl_801A6818;
extern BOOL lbl_801A6978;
extern u32 lbl_801A697C;
extern u32 lbl_801A697C__fzgx_offset_4;
extern u32 lbl_801A6984;
extern u32 lbl_801A6988;
extern u32 lbl_801A698C;
extern u32 lbl_801A6990;
extern PADSamplingCallback lbl_801A6994;
extern BOOL lbl_801A6998;
extern u32 lbl_801A699C;
extern u32 lbl_801A69A0;
extern BOOL lbl_801A69A4;
extern OSResetFunctionInfo lbl_801245E0;

u8 __gUnknown800030E3 : FZGX_ADDR___gUnknown800030E3;
u16 __OSWirelessPadFixMode : FZGX_ADDR___OSWirelessPadFixMode;

static u32 lbl_8015D0B0[4];
static PADStatus lbl_8015D0C0__fzgx_offset_0[4];
static u32 lbl_8015D0C0__fzgx_offset_30[4];

void *memset(void *dst, int val, unsigned long size);
void OSRegisterVersion(const char *id);
void OSRegisterResetFunction(OSResetFunctionInfo *info);
void OSClearContext(OSContext *context);
void OSSetCurrentContext(OSContext *context);

void UpdateOrigin(s32 chan);
void PADOriginCallback(s32 chan, u32 error, OSContext *context);
void PADOriginUpdateCallback(s32 chan, u32 error, OSContext *context);
void PADProbeCallback(s32 chan, u32 error, OSContext *context);
void PADTypeAndStatusCallback(s32 chan, u32 type);
void PADReceiveCheckCallback(s32 chan, u32 type);
BOOL PADReset(u32 mask);
BOOL PADRecalibrate(u32 mask);
BOOL PADInit(void);
u32 PADRead(PADStatus *status);
void fn_8001D32C(u32 *commands);
void PADControlMotor(u32 channel, u32 command);
void PADSetSpec(u32 spec);
void SPEC0_MakeStatus(s32 chan, PADStatus *status, u32 data[2]);
void SPEC1_MakeStatus(s32 chan, PADStatus *status, u32 data[2]);
void SPEC2_MakeStatus(s32 chan, PADStatus *status, u32 data[2]);
void PADSetAnalogMode(u32 mode);
BOOL OnReset_Pad(BOOL final);
void SamplingHandler_Pad(__OSInterrupt interrupt, OSContext *context);
PADSamplingCallback PADSetSamplingCallback_Pad(PADSamplingCallback callback);
BOOL __PADDisableRecalibration(BOOL disable);
BOOL fn_8001DF00(BOOL disable);

static inline void PADEnable(s32 chan) {
    u32 cmd;
    u32 chanBit;
    u32 data[2];
    chanBit = 0x80000000 >> chan;
    lbl_801A697C |= chanBit;
    SIGetResponse(chan, data);
    cmd = (0x40 << 16) | lbl_801A64BC;
    SISetCommand(chan, cmd);
    SIEnablePolling(lbl_801A697C);
}

static inline void PADDisable(s32 chan) {
    BOOL enabled;
    u32 chanBit;
    enabled = OSDisableInterrupts();
    chanBit = 0x80000000 >> chan;
    SIDisablePolling(chanBit);
    lbl_801A697C &= ~chanBit;
    lbl_801A6988 &= ~chanBit;
    lbl_801A698C &= ~chanBit;
    lbl_801A6990 &= ~chanBit;
    OSSetWirelessID(chan, 0);
    OSRestoreInterrupts(enabled);
}

static inline void DoReset(void) {
    u32 chanBit;
    lbl_801A64B4 = __cntlzw(lbl_801A697C__fzgx_offset_4);
    if (lbl_801A64B4 == 32) {
        return;
    }
    chanBit = 0x80000000 >> lbl_801A64B4;
    lbl_801A697C__fzgx_offset_4 &= ~chanBit;
    memset(&lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 0, sizeof(PADStatus));
    SIGetTypeAsync(lbl_801A64B4, PADTypeAndStatusCallback);
}

static inline BOOL PADSync(void) {
    return lbl_801A697C__fzgx_offset_4 == 0 && (s32)lbl_801A64B4 == 32 && !SIBusy();
}


void UpdateOrigin(s32 chan) {
    PADStatus *origin;
    u32 chanBit = 0x80000000 >> chan;
    origin = &lbl_8015D0C0__fzgx_offset_0[chan];
    switch (lbl_801A64BC & 0x00000700u) {
    case 0x00000000u:
    case 0x00000500u:
    case 0x00000600u:
    case 0x00000700u:
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000100u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000200u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        break;
    case 0x00000300u:
        break;
    case 0x00000400u:
        break;
    }
    origin->stickX -= 128;
    origin->stickY -= 128;
    origin->substickX -= 128;
    origin->substickY -= 128;
    if (lbl_801A64B8 & chanBit) {
        if (64 < origin->stickX && (SIGetType(chan) & 0xffff0000) == (0x08000000u | 0x01000000)) {
            origin->stickX = 0;
        }
    }
}

void PADOriginCallback(s32 chan, u32 error, OSContext *context) {
    if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004))) {
        UpdateOrigin(lbl_801A64B4);
        PADEnable(lbl_801A64B4);
    }
    DoReset();
}

void PADOriginUpdateCallback(s32 chan, u32 error, OSContext *context) {
    if (!(lbl_801A697C & (0x80000000 >> chan)))
        return;
    if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004)))
        UpdateOrigin(chan);
    if (error & 0x0008) {
        PADDisable(chan);
    }
}

void PADProbeCallback(s32 chan, u32 error, OSContext *context) {
    if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004))) {
        PADEnable(lbl_801A64B4);
        lbl_801A6988 |= 0x80000000u >> lbl_801A64B4;
    }
    DoReset();
}

void PADTypeAndStatusCallback(s32 chan, u32 type) {
    u32 chanBit;
    u32 recalibrate;
    BOOL rc = 1;
    u32 error;
    chanBit = 0x80000000 >> lbl_801A64B4;
    error = type & 0xFF;
    recalibrate = lbl_801A6984 & chanBit;
    lbl_801A6984 &= ~chanBit;
    if (error & (0x0001 | 0x0002 | 0x0008 | 0x0004)) {
        DoReset();
        return;
    }
    type &= ~0xFF;
    lbl_8015D0B0[lbl_801A64B4] = type;
    if ((type & 0x18000000u) != 0x08000000u || !(type & 0x01000000)) {
        DoReset();
        return;
    }
    if (lbl_801A64C0 < 2) {
        PADEnable(lbl_801A64B4);
        DoReset();
        return;
    }
    if (!(type & 0x80000000) || (type & 0x04000000)) {
        if (recalibrate) {
            rc = SITransfer(lbl_801A64B4, &lbl_801A64CC, 3, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 10, PADOriginCallback,
                            0);
        } else {
            rc = SITransfer(lbl_801A64B4, &lbl_801A64C8, 1, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 10, PADOriginCallback,
                            0);
        }
    } else if ((type & 0x00100000) && (type & 0x00080000) == 0x00000000 && !(type & 0x00040000)) {
        if (type & 0x40000000) {
            rc = SITransfer(lbl_801A64B4, &lbl_801A64C8, 1, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4], 10, PADOriginCallback,
                            0);
        } else {
            rc = SITransfer(lbl_801A64B4, &lbl_8015D0C0__fzgx_offset_30[lbl_801A64B4], 3, &lbl_8015D0C0__fzgx_offset_0[lbl_801A64B4],
                            8, PADProbeCallback, 0);
        }
    }
    if (!rc) {
        lbl_801A6990 |= chanBit;
        DoReset();
        return;
    }
}

void PADReceiveCheckCallback(s32 chan, u32 type) {
    u32 error;
    u32 chanBit;
    chanBit = 0x80000000 >> chan;
    if (lbl_801A697C & chanBit) {
        error = type & 0xFF;
        type &= ~0xFF;
        lbl_801A6988 &= ~chanBit;
        lbl_801A698C &= ~chanBit;
        if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004)) && (type & 0x80000000) &&
            (type & 0x00100000) && (type & 0x40000000) && !(type & 0x04000000) &&
            (type & 0x00080000) == 0x00000000 && !(type & 0x00040000)) {
            SITransfer(chan, &lbl_801A64C8, 1, &lbl_8015D0C0__fzgx_offset_0[chan], 10, PADOriginUpdateCallback, 0);
        } else {
            PADDisable(chan);
        }
    }
}

int PADReset(u32 mask) {
    BOOL enabled;
    u32 disableBits;
    enabled = OSDisableInterrupts();
    mask |= lbl_801A6990;
    lbl_801A6990 = 0;
    mask &= ~(lbl_801A6988 | lbl_801A698C);
    lbl_801A697C__fzgx_offset_4 |= mask;
    disableBits = lbl_801A697C__fzgx_offset_4 & lbl_801A697C;
    lbl_801A697C &= ~mask;
    if (lbl_801A64C0 == 4) {
        lbl_801A6984 |= mask;
    }
    SIDisablePolling(disableBits);
    if (lbl_801A64B4 == 0x20) {
        DoReset();
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADRecalibrate(u32 mask) {
    BOOL enabled;
    u32 disableBits;
    enabled = OSDisableInterrupts();
    mask |= lbl_801A6990;
    lbl_801A6990 = 0;
    mask &= ~(lbl_801A6988 | lbl_801A698C);
    lbl_801A697C__fzgx_offset_4 |= mask;
    disableBits = lbl_801A697C__fzgx_offset_4 & lbl_801A697C;
    lbl_801A697C &= ~mask;
    if (!(__gUnknown800030E3 & 0x40)) {
        lbl_801A6984 |= mask;
    }
    SIDisablePolling(disableBits);
    if (lbl_801A64B4 == 32)
        DoReset();
    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADInit() {
    s32 chan;
    if (lbl_801A6978) {
        return 1;
    }
    OSRegisterVersion(lbl_801A64B0);
    if (__PADSpec)
        PADSetSpec(__PADSpec);
    lbl_801A6978 = 1;
    if (lbl_801A6818 != 0) {
        OSTime time = OSGetTime();
        __OSWirelessPadFixMode = (u16)((((time) & 0xffff) + ((time >> 16) & 0xffff) +
                                        ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) &
                                       0x3fffu);
        lbl_801A6984 = 0x80000000 | 0x40000000 | 0x20000000 | 0x10000000;
    }
    for (chan = 0; chan < 4; ++chan) {
        lbl_8015D0C0__fzgx_offset_30[chan] =
            (0x4D << 24) | (chan << 22) | ((__OSWirelessPadFixMode & 0x3fffu) << 8);
    }
    SIRefreshSamplingRate();
    OSRegisterResetFunction(&lbl_801245E0);
    return PADReset(0x80000000 | 0x40000000 | 0x20000000 | 0x10000000);
}

u32 PADRead(PADStatus *status) {
    BOOL enabled;
    s32 chan;
    u32 data[2];
    u32 chanBit;
    u32 sr;
    int chanShift;
    u32 motor;
    enabled = OSDisableInterrupts();
    motor = 0;
    for (chan = 0; chan < 4; chan++, status++) {
        chanBit = 0x80000000 >> chan;
        chanShift = 8 * (4 - 1 - chan);
        if (lbl_801A6990 & chanBit) {
            PADReset(0);
            status->err = -2;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else if ((lbl_801A697C__fzgx_offset_4 & chanBit) || lbl_801A64B4 == chan) {
            status->err = -2;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else if (!(lbl_801A697C & chanBit)) {
            status->err = -1;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else if (SIIsChanBusy(chan)) {
            status->err = -3;
            memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
        } else {
            sr = SIGetStatus(chan);
            if (sr & 0x0008) {
                SIGetResponse(chan, data);
                if (lbl_801A6988 & chanBit) {
                    status->err = 0;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                    if (!(lbl_801A698C & chanBit)) {
                        lbl_801A698C |= chanBit;
                        SIGetTypeAsync(chan, PADReceiveCheckCallback);
                    }
                } else {
                    PADDisable(chan);
                    status->err = -1;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                }
            } else {
                if (!(SIGetType(chan) & 0x20000000)) {
                    motor |= chanBit;
                }
                if (!SIGetResponse(chan, &data)) {
                    status->err = -3;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                } else if (data[0] & 0x80000000) {
                    status->err = -3;
                    memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                } else {
                    lbl_801A64C4(chan, status, data);
                    if (status->button & 0x2000) {
                        status->err = -3;
                        memset(status, 0, ((size_t)&(((PADStatus *)0)->err)));
                        SITransfer(chan, &lbl_801A64C8, 1, &lbl_8015D0C0__fzgx_offset_0[chan], 10,
                                   PADOriginUpdateCallback, 0);
                    } else {
                        status->err = 0;
                        status->button &= ~0x0080;
                    }
                }
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return motor;
}

void fn_8001D32C(u32 *commands) {
    u32 state;
    s32 channel;
    s32 transferred;

    state = OSDisableInterrupts();
    transferred = 0;
    for (channel = 0; channel < 4; channel++, commands++) {
        if (lbl_801A697C & (0x80000000u >> channel)) {
            if ((SIGetType(channel) & 0x20000000u) == 0) {
                u32 command = *commands;
                if (lbl_801A64C0 < 2 && command == 2) {
                    command = 0;
                }
                SISetCommand(channel, lbl_801A64BC | 0x400000 | (command & 3));
                transferred = 1;
            }
        }
    }
    if (transferred) {
        SITransferCommands();
    }
    OSRestoreInterrupts(state);
}

void PADControlMotor(u32 channel, u32 command) {
    u32 state;
    u32 saved_command = command;
    u32 saved_channel = channel;
    u64 pad;

    state = OSDisableInterrupts();

    if (lbl_801A697C & ((0x8000u << 16) >> saved_channel)) {
        if ((SIGetType(saved_channel) & (0x2000u << 16)) == 0) {
            if (lbl_801A64C0 < 2 && saved_command == 2) {
                saved_command = 0;
            }
            SISetCommand(saved_channel, lbl_801A64BC | 0x400000 | (saved_command & 3));
            SITransferCommands();
        }
    }

    OSRestoreInterrupts(state);
}

void PADSetSpec(u32 spec) {
    __PADSpec = 0;
    switch (spec) {
    case 0:
        lbl_801A64C4 = SPEC0_MakeStatus;
        break;
    case 1:
        lbl_801A64C4 = SPEC1_MakeStatus;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        lbl_801A64C4 = SPEC2_MakeStatus;
        break;
    }
    lbl_801A64C0 = spec;
}

void SPEC0_MakeStatus(s32 chan, PADStatus *status, u32 data[2]) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0008) ? 0x0100 : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? 0x0200 : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? 0x0400 : 0;
    status->button |= ((data[0] >> 16) & 0x0001) ? 0x0800 : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? 0x1000 : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (170 <= status->triggerLeft) {
        status->button |= 0x0040;
    }
    if (170 <= status->triggerRight) {
        status->button |= 0x0020;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

void SPEC1_MakeStatus(s32 chan, PADStatus *status, u32 data[2]) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0080) ? 0x0100 : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? 0x0200 : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? 0x0400 : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? 0x0800 : 0;
    status->button |= ((data[0] >> 16) & 0x0200) ? 0x1000 : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (170 <= status->triggerLeft) {
        status->button |= 0x0040;
    }
    if (170 <= status->triggerRight) {
        status->button |= 0x0020;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

static inline s8 ClampS8(s8 var, s8 org) {
    if (0 < org) {
        s8 min = (s8)(-128 + org);
        if (var < min)
            var = min;
    } else if (org < 0) {
        s8 max = (s8)(127 + org);
        if (max < var)
            var = max;
    }
    return var -= org;
}

static inline u8 ClampU8(u8 var, u8 org) {
    if (var < org)
        var = org;
    return var -= org;
}


void SPEC2_MakeStatus(s32 chan, PADStatus *status, u32 data[2]) {
    PADStatus *origin;
    status->button =
        (u16)((data[0] >> 16) & (0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010 | 0x0020 | 0x0040 |
                                 0x0100 | 0x0200 | 0x0400 | 0x0800 | 0x1000 | 0x2000 | 0x0080));
    status->stickX = (s8)(data[0] >> 8);
    status->stickY = (s8)(data[0]);
    switch (lbl_801A64BC & 0x00000700) {
    case 0x00000000:
    case 0x00000500:
    case 0x00000600:
    case 0x00000700:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(((data[1] >> 12) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 8) & 0x0f) << 4);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000100:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(data[1] >> 16);
        status->triggerRight = (u8)(data[1] >> 8);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000200:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(((data[1] >> 20) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 16) & 0x0f) << 4);
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    case 0x00000300:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)(data[1] >> 0);
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x00000400:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = 0;
        status->triggerRight = 0;
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
    origin = &lbl_8015D0C0__fzgx_offset_0[chan];
    status->stickX = ClampS8(status->stickX, origin->stickX);
    status->stickY = ClampS8(status->stickY, origin->stickY);
    status->substickX = ClampS8(status->substickX, origin->substickX);
    status->substickY = ClampS8(status->substickY, origin->substickY);
    status->triggerLeft = ClampU8(status->triggerLeft, origin->triggerLeft);
    status->triggerRight = ClampU8(status->triggerRight, origin->triggerRight);
}

void PADSetAnalogMode(u32 mode) {
    BOOL enabled;
    u32 mask;
    enabled = OSDisableInterrupts();
    lbl_801A64BC = mode << 8;
    mask = lbl_801A697C;
    lbl_801A697C &= ~mask;
    lbl_801A6988 &= ~mask;
    lbl_801A698C &= ~mask;
    SIDisablePolling(mask);
    OSRestoreInterrupts(enabled);
}

BOOL OnReset_Pad(BOOL final) {
    BOOL sync;
    extern BOOL lbl_801A6998;
    if (lbl_801A6994)
        PADSetSamplingCallback_Pad(((void *)0));
    if (!final) {
        sync = PADSync();
        if (!lbl_801A6998 && sync) {
            lbl_801A6998 = PADRecalibrate(0x80000000 | 0x40000000 | 0x20000000 | 0x10000000);
            return 0;
        }
        return sync;
    } else
        lbl_801A6998 = 0;
    return 1;
}

void SamplingHandler_Pad(__OSInterrupt interrupt, OSContext *context) {
    OSContext exceptionContext;
    if (lbl_801A6994) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        lbl_801A6994();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

PADSamplingCallback PADSetSamplingCallback_Pad(PADSamplingCallback callback) {
    PADSamplingCallback prev;
    prev = lbl_801A6994;
    lbl_801A6994 = callback;
    if (callback) {
        SIRegisterPollingHandler(SamplingHandler_Pad);
    } else {
        SIUnregisterPollingHandler(SamplingHandler_Pad);
    }
    return prev;
}

BOOL __PADDisableRecalibration(BOOL disable) {
    BOOL enabled;
    BOOL prev;
    enabled = OSDisableInterrupts();
    prev = (__gUnknown800030E3 & 0x40) ? 1 : 0;
    __gUnknown800030E3 &= (u8)~0x40;
    if (disable) {
        __gUnknown800030E3 |= 0x40;
    }
    OSRestoreInterrupts(enabled);
    return prev;
}

BOOL fn_8001DF00(BOOL disable) {
    BOOL enabled;
    BOOL prev;
    prev = lbl_801A69A4;
    enabled = OSDisableInterrupts();
    lbl_801A69A4 = disable;
    OSRestoreInterrupts(enabled);
    return prev;
}
