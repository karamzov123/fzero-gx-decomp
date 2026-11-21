#include <dolphin/types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/dvd.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);
typedef struct DVDDriveInfo { u16 revisionLevel; u16 deviceCode; u32 releaseDate; u8 padding[24]; } DVDDriveInfo;
typedef struct DVDDiskID DVDDiskID;

typedef struct DVDBuffer {
    void *addr;
    u32 length;
    u32 offset;
} DVDBuffer;

typedef struct DVDCommand {
    s32 cmd;
    void *addr;
    u32 length;
    u32 offset;
    DVDLowCallback callback;
} DVDCommand;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;
vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

extern volatile BOOL StopAtNextInt; /* fzgx-allow: S2 SDK asynchronous state */
extern u32 lbl_801A685C;
extern DVDLowCallback Callback;
extern DVDLowCallback lbl_801A6864;
extern volatile BOOL WaitingCoverClose; /* fzgx-allow: S2 SDK asynchronous state */
extern BOOL Breaking;
extern volatile u32 WorkAroundType; /* fzgx-allow: S2 SDK asynchronous state */
extern u32 WorkAroundSeekLocation;
extern vu32 NextCommandNumber;
extern BOOL lbl_801A6878;
extern u32 lbl_801A687C;
extern u32 lbl_801A6880;
extern u32 lbl_801A6884;
extern volatile OSTime lbl_801A6888; /* fzgx-allow: S2 SDK asynchronous state */
extern u32 lbl_801A688C;
extern OSTime lbl_801A6890;
extern u32 lbl_801A6894;
extern volatile BOOL lbl_801A6898; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile OSTime LastResetEnd; // fzgx-allow: S2 SDK asynchronous state
extern volatile u32 ResetOccurred; // fzgx-allow: S2 SDK asynchronous state
extern BOOL lbl_801A6468;
extern const f32 lbl_801A6F60;
extern const f32 lbl_801A6F64;
extern const f32 lbl_801A6F68;
extern const f32 lbl_801A6F6C;
extern const f32 lbl_801A6F70;
extern const f32 lbl_801A6F74;

static DVDCommand CommandList_8015CD70[3];
static OSAlarm AlarmForWA;
static OSAlarm AlarmForTimeout;
static unsigned char fzgx_pool_gap____bss_0_90[40];
static DVDBuffer Prev;
static DVDBuffer Curr;

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
    volatile unsigned char sink; /* fzgx-allow: S2 layout primer */
    sink = *(unsigned char *)&CommandList_8015CD70;
    sink = *(unsigned char *)&AlarmForWA;
    sink = *(unsigned char *)&AlarmForTimeout;
    sink = *(unsigned char *)&fzgx_pool_gap____bss_0_90;
    sink = *(unsigned char *)&Prev;
    sink = *(unsigned char *)&Curr;
}
#pragma section code_type ".text"

void Read(void *addr, u32 length, u32 offset, DVDLowCallback callback);
BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);
void AlarmHandler_dvdlow(OSAlarm *alarm, OSContext *context);
void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);
void __DVDLowSetWAType(u32 arg0, u32 arg1);
DVDDiskID *fn_80019C48(void);
void SeekTwiceBeforeRead(void *addr, u32 length, u32 offset, DVDLowCallback callback);

static inline BOOL ProcessNextCommand(void) {
    s32 n = NextCommandNumber;
    if (CommandList_8015CD70[n].cmd == 1) {
        ++NextCommandNumber;
        Read(CommandList_8015CD70[n].addr, CommandList_8015CD70[n].length, CommandList_8015CD70[n].offset, CommandList_8015CD70[n].callback);
        return TRUE;
    } else if (CommandList_8015CD70[n].cmd == 2) {
        ++NextCommandNumber;
        DVDLowSeek(CommandList_8015CD70[n].offset, CommandList_8015CD70[n].callback);
        return TRUE;
    }
    return FALSE;
}

static inline void SetTimeoutAlarm(OSTime timeout) {
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout);
}

static inline BOOL HitCache(DVDBuffer *cur, DVDBuffer *prev) {
    u32 uVar1 = (prev->offset + prev->length - 1) >> 15;
    u32 uVar2 = (cur->offset >> 15);
    u32 iVar3 = (fn_80019C48()->streaming ? 1 : 0) ? 5 : 15;
    if ((uVar2 > uVar1 - 2) || (uVar2 < uVar1 + iVar3 + 3)) {
        return 1;
    }
    return 0;
}

static inline void DoJustRead(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    CommandList_8015CD70[0].cmd = -1;
    NextCommandNumber = 0;
    Read(addr, length, offset, callback);
}

static inline void WaitBeforeRead(void *addr, u32 length, u32 offset, DVDLowCallback callback, OSTime timeout) {
    CommandList_8015CD70[0].cmd = 1;
    CommandList_8015CD70[0].addr = addr;
    CommandList_8015CD70[0].length = length;
    CommandList_8015CD70[0].offset = offset;
    CommandList_8015CD70[0].callback = callback;
    CommandList_8015CD70[1].cmd = -1;
    NextCommandNumber = 0;
    OSCreateAlarm(&AlarmForWA);
    OSSetAlarm(&AlarmForWA, timeout, AlarmHandler_dvdlow);
}


void __DVDInitWA(void) {
    NextCommandNumber = 0;
    CommandList_8015CD70[0].cmd = -1;
    __DVDLowSetWAType(0, 0);
    OSInitAlarm();
}

void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext *context) {
    DVDLowCallback cb;
    OSContext exceptionContext;
    u32 cause = 0;
    u32 reg;
    u32 intr;
    u32 mask;
    if (lbl_801A6898) {
        lbl_801A6888 = __OSGetSystemTime();
        lbl_801A6468 = 0;
        Prev.addr = Curr.addr;
        Prev.length = Curr.length;
        Prev.offset = Curr.offset;
        if (StopAtNextInt == 1) {
            cause |= 8;
        }
    }
    lbl_801A6898 = 0;
    StopAtNextInt = 0;
    reg = __DIRegs[0];
    mask = reg & 0x2a;
    intr = (reg & 0x54) & (mask << 1);
    if (intr & 0x40) {
        cause |= 8;
    }
    if (intr & 0x10) {
        cause |= 1;
    }
    if (intr & 4) {
        cause |= 2;
    }
    if (cause) {
        ResetOccurred = 0;
        OSCancelAlarm(&AlarmForTimeout);
    }
    __DIRegs[0] = intr | mask;
    if (ResetOccurred && (__OSGetSystemTime() - LastResetEnd) <
                                      ((200) * (((u32)__OSBusClock / 4) / 1000))) {
        reg = __DIRegs[1];
        mask = reg & 0x2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            if (lbl_801A6864) {
                lbl_801A6864(4);
            }
            lbl_801A6864 = 0;
        }
        __DIRegs[1] = __DIRegs[1];
    } else if (WaitingCoverClose) {
        reg = __DIRegs[1];
        mask = reg & 2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            cause |= 4;
        }
        __DIRegs[1] = intr | mask;
        WaitingCoverClose = 0;
    } else {
        __DIRegs[1] = 0;
    }
    if ((cause & 8) && !lbl_801A6878) {
        cause &= ~8;
    }
    if ((cause & 1)) {
        if (ProcessNextCommand()) {
            return;
        }
    } else {
        CommandList_8015CD70[0].cmd = -1;
        NextCommandNumber = 0;
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (cause) {
        cb = Callback;
        Callback = 0;
        if (cb) {
            cb(cause);
        }
        lbl_801A6878 = 0;
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void AlarmHandler_dvdlow(OSAlarm *alarm, OSContext *context) {
    BOOL error = ProcessNextCommand();
    ((void)0);
}

void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context) {
    OSContext tmpContext;
    DVDLowCallback callback;
    __OSMaskInterrupts(0x400);
    OSClearContext(&tmpContext);
    OSSetCurrentContext(&tmpContext);
    callback = Callback;
    Callback = 0;
    if (callback != 0) {
        callback(0x10);
    }
    OSClearContext(&tmpContext);
    OSSetCurrentContext(context);
}

void Read(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    StopAtNextInt = 0;
    lbl_801A6898 = 1;
    Callback = callback;
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

void __DVDLowSetWAType(u32 arg0, u32 arg1);
DVDDiskID *fn_80019C48(void);
void SeekTwiceBeforeRead(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    u32 newOffset = offset & ~0x7FFF;
    if (!newOffset) {
        newOffset = 0;
    } else {
        newOffset += WorkAroundSeekLocation;
    }
    CommandList_8015CD70[0].cmd = 2;
    CommandList_8015CD70[0].offset = newOffset;
    CommandList_8015CD70[0].callback = callback;
    CommandList_8015CD70[1].cmd = 1;
    CommandList_8015CD70[1].addr = addr;
    CommandList_8015CD70[1].length = length;
    CommandList_8015CD70[1].offset = offset;
    CommandList_8015CD70[1].callback = callback;
    CommandList_8015CD70[2].cmd = -1;
    NextCommandNumber = 0;
    DVDLowSeek(newOffset, callback);
}

BOOL DVDLowRead(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    OSTime diff;
    u32 prev;
    __DIRegs[6] = length;
    Curr.addr = addr;
    Curr.length = length;
    Curr.offset = offset;
    if (WorkAroundType == 0) {
        DoJustRead(addr, length, offset, callback);
    } else if (WorkAroundType == 1) {
        if (lbl_801A6468) {
            SeekTwiceBeforeRead(addr, length, offset, callback);
        } else {
            if (!HitCache(&Curr, &Prev)) {
                DoJustRead(addr, length, offset, callback);
            } else {
                prev = (Prev.offset + Prev.length - 1) >> 15;
                if (prev == Curr.offset >> 15 || prev + 1 == Curr.offset >> 15) {
                    diff = __OSGetSystemTime() - lbl_801A6888;
                    if (((5) * (((u32)__OSBusClock / 4) / 1000)) < diff) {
                        DoJustRead(addr, length, offset, callback);
                    } else {
                        WaitBeforeRead(addr, length, offset, callback,
                                       ((5) * (((u32)__OSBusClock / 4) / 1000)) - diff +
                                           (((500) * (((u32)__OSBusClock / 4) / 125000)) / 8));
                    }
                } else {
                    SeekTwiceBeforeRead(addr, length, offset, callback);
                }
            }
        }
    }
    return 1;
}

BOOL DVDLowSeek(u32 offset, DVDLowCallback callback) {
    ((void)0);
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xab000000;
    __DIRegs[3] = offset / 4;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowWaitCoverClose(DVDLowCallback callback) {
    Callback = callback;
    WaitingCoverClose = 1;
    StopAtNextInt = 0;
    __DIRegs[1] = 2;
    return 1;
}

BOOL DVDLowReadDiskID(DVDDiskID *diskID, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xa8000040;
    __DIRegs[3] = 0;
    __DIRegs[4] = sizeof(DVDDiskID);
    __DIRegs[5] = (u32)diskID;
    __DIRegs[6] = sizeof(DVDDiskID);
    __DIRegs[7] = 3;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowStopMotor(DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xe3000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowRequestError(DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xe0000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowInquiry(DVDDriveInfo *info, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0x12000000;
    __DIRegs[4] = sizeof(DVDDriveInfo);
    __DIRegs[5] = (u32)info;
    __DIRegs[6] = sizeof(DVDDriveInfo);
    __DIRegs[7] = 3;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowAudioStream(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = subcmd | 0xe1000000;
    __DIRegs[3] = offset >> 2;
    __DIRegs[4] = length;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = subcmd | 0xe2000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xe4000000 | (enable != 0 ? 0x10000 : 0) | size;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

void DVDLowReset() {
    u32 reg;
    OSTime resetStart;
    __DIRegs[1] = 2;
    reg = __PIRegs[9];
    __PIRegs[9] = (reg & ~4) | 1;
    resetStart = __OSGetSystemTime();
    while ((__OSGetSystemTime() - resetStart) < (((12) * (((u32)__OSBusClock / 4) / 125000)) / 8))
        ;
    __PIRegs[9] = reg | 5;
    ResetOccurred = 1;
    LastResetEnd = __OSGetSystemTime();
}

s32 DVDLowBreak(void) {
    StopAtNextInt = 1;
    lbl_801A6878 = 1;
    return 1;
}

DVDLowCallback DVDLowClearCallback() {
    DVDLowCallback old;
    __DIRegs[1] = 0;
    old = Callback;
    Callback = ((void *)0);
    return old;
}

void __DVDLowSetWAType(u32 arg0, u32 arg1) {
    u32 t0;
    t0 = OSDisableInterrupts();
    WorkAroundType = (arg0 + 0);
    WorkAroundSeekLocation = (arg1 + 0);
    OSRestoreInterrupts(t0);
}
