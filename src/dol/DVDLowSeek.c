#include <types.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/dvd.h>
#include <dolphin/os.h>


/* --- dol/DVDLowSeek.c --- */
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

/* --- dol/DVDLowWaitCoverClose.c --- */
// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state


// Hardware or OS state can change asynchronously.
extern volatile BOOL WaitingCoverClose; // fzgx-allow: S2 SDK asynchronous state

BOOL DVDLowWaitCoverClose(DVDLowCallback callback) {
    Callback = callback;
    WaitingCoverClose = 1;
    StopAtNextInt = 0;
    __DIRegs[1] = 2;
    return 1;
}

/* --- dol/DVDLowReadDiskID.c --- */
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


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

/* --- dol/DVDLowStopMotor.c --- */
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


BOOL DVDLowStopMotor(DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xe3000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

/* --- dol/DVDLowRequestError.c --- */
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


BOOL DVDLowRequestError(DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xe0000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

/* --- dol/DVDLowInquiry.c --- */
typedef struct DVDDriveInfo {
    u16 revisionLevel;
    u16 deviceCode;
    u32 releaseDate;
    u8 padding[24];
} DVDDriveInfo;


void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


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

/* --- dol/DVDLowAudioStream.c --- */
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


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

/* --- dol/DVDLowRequestAudioStatus.c --- */
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = subcmd | 0xe2000000;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

/* --- dol/DVDLowAudioBufferConfig.c --- */
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);



// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state



void AlarmHandlerForTimeout(OSAlarm *alarm, OSContext *context);


BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback) {
    StopAtNextInt = 0;
    Callback = callback;
    __DIRegs[2] = 0xe4000000 | (enable != 0 ? 0x10000 : 0) | size;
    __DIRegs[7] = 1;
    SetTimeoutAlarm(((10) * ((u32)__OSBusClock / 4)));
    return 1;
}

/* --- dol/DVDLowReset.c --- */
vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;


// Hardware or OS state can change asynchronously.
extern volatile OSTime LastResetEnd; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile u32 ResetOccurred; // fzgx-allow: S2 SDK asynchronous state

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
