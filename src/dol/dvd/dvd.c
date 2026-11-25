#include <dolphin/types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/dvd.h>
#include "sdk_addresses.h"

typedef volatile s32 vs32; /* fzgx-allow: S2 SDK asynchronous state */
typedef void (*DVDLowCallback)(u32 intType);
typedef struct DVDDriveInfo {
    u16 revisionLevel;
    u16 deviceCode;
    u32 releaseDate;
    u8 padding[24];
} DVDDriveInfo;

typedef struct OSBootInfo {
    DVDDiskID DVDDiskID;
    u32 magic;
    u32 version;
    u32 memorySize;
    u32 consoleSimulatedMemSize;
    void *arenaLo;
    void *arenaHi;
    void *FSTLocation;
    u32 FSTMaxLength;
} OSBootInfo;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;
extern volatile struct { u32 reg[16]; } __DVDRegs; /* fzgx-allow: S2 hardware register */
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

extern OSBootInfo *bootInfo;
extern DVDCommandBlock *executing;
extern DVDDiskID *IDShouldBe;
extern volatile BOOL DVDInitialized; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL lbl_801A68C8; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL lbl_801A68CC; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL lbl_801A68D0; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL lbl_801A68D4; /* fzgx-allow: S2 SDK asynchronous state */
extern vu32 CurrCommand;
extern volatile BOOL lbl_801A68DC; /* fzgx-allow: S2 SDK asynchronous state */
extern vu32 lbl_801A68E0;
extern DVDCBCallback lbl_801A68E4;
extern vu32 ResumeFromHere;
extern vu32 NumInternalRetry;
extern vu32 LastError;
extern vs32 lbl_801A68F4;
extern volatile BOOL ResetRequired; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL CancelAllSyncComplete; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL PausingFlag; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL autoInvalidation; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL FatalErrorFlag; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL PauseFlag; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL Canceling; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL WaitingForCoverOpen; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL WaitingForCoverClose; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL MotorStopped; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL ChangedDisc; /* fzgx-allow: S2 SDK asynchronous state */
extern volatile BOOL PreparingCover; /* fzgx-allow: S2 SDK asynchronous state */
extern OSThreadQueue __DVDThreadQueue;
extern OSAlarm ResetAlarm;
extern DVDDiskID CurrDiskID;
extern u32 lbl_801A6478;
extern u32 lbl_801A647C;
typedef void (*DVDOptionalCommandChecker)(DVDCommandBlock *block, DVDLowCallback cb);
extern DVDOptionalCommandChecker lbl_801A6480;
extern const char lbl_801A6484[8];
extern const char *lbl_801A6474;

struct dvdBss {
    unsigned char BB2[32];
    DVDDiskID CurrDiskID;
    DVDCommandBlock DummyCommandBlock;
    OSAlarm ResetAlarm;
};

static unsigned char BB2_8015CE40[32];
static unsigned char lbl_8015CE60__fzgx_offset_0[32];
static DVDCommandBlock DummyCommandBlock;

typedef void (*stateFunc)(DVDCommandBlock *block);
extern stateFunc lbl_801A6904;
extern const char *__DVDVersion;
extern volatile BOOL FirstTimeInBootrom; // fzgx-allow: S2 SDK asynchronous state
extern u32 lbl_801A648C[1];
extern vu32 CancelLastError;
extern u32 lbl_801A68F0;
extern void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext *context);
extern void OSPanic(const char *file, int line, const char *msg, ...);
#define BB2 ((u32 *)BB2_8015CE40)
typedef DVDCommandBlock CommandBlock;

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
    volatile unsigned char sink; /* fzgx-allow: S2 BSS layout primer */
    sink = *(unsigned char *)&BB2_8015CE40;
    sink = *(unsigned char *)&lbl_8015CE60__fzgx_offset_0;
    sink = *(unsigned char *)&DummyCommandBlock;
}
#pragma section code_type ".text"

void __DVDFSInit(void);
void __DVDInitWA(void);
void __DVDClearWaitingQueue(void);
BOOL __DVDPushWaitingQueue(s32 prio, DVDCommandBlock *block);
DVDCommandBlock *__DVDPopWaitingQueue(void);
BOOL __DVDCheckWaitingQueue(void);
BOOL __DVDDequeueWaitingQueue(DVDCommandBlock *block);
void __DVDStoreErrorCode(u32 error);
BOOL DVDCompareDiskID(const DVDDiskID *id1, const DVDDiskID *id2);
void DCInvalidateRange(void *addr, u32 nBytes);
void *memcpy(void *dst, const void *src, unsigned long n);
void OSReport(const char *msg, ...);
void OSCreateAlarm(OSAlarm *alarm);
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);
void OSRegisterVersion(const char *id);
void OSSleepThread(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);
BOOL DVDLowRead(void *addr, u32 length, u32 offset, DVDLowCallback callback);
BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);
BOOL DVDLowWaitCoverClose(DVDLowCallback callback);
BOOL DVDLowReadDiskID(DVDDiskID *diskID, DVDLowCallback callback);
BOOL DVDLowStopMotor(DVDLowCallback callback);
BOOL DVDLowRequestError(DVDLowCallback callback);
BOOL DVDLowInquiry(DVDDriveInfo *info, DVDLowCallback callback);
BOOL DVDLowAudioStream(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback);
BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback);
BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback);
void DVDLowReset(void);
BOOL DVDLowBreak(void);
DVDLowCallback DVDLowClearCallback(void);
void __DVDLowSetWAType(u32 type, s32 seekLoc);

void DVDInit(void);
void fn_80017838(void);
void cbForStateReadingFST(u32 intType);
void cbForStateError(u32 intType);
void stateTimeout(void);
void _epilog_rel_sample(void);
int CategorizeError(u32 error);
void cbForStateGettingError(u32 intType);
void cbForUnrecoveredError(u32 intType);
void cbForUnrecoveredErrorRetry(u32 intType);
void fn_80017EA8(void);
void cbForStateGoToRetry(u32 intType);
void stateCheckID(void);
void fn_80018108(DVDCommandBlock *block);
void fn_8001813C(DVDCommandBlock *block);
void cbForStateCheckID2a(u32 intType);
void stateCheckID2(DVDCommandBlock *block);
void cbForStateCheckID1(u32 intType);
void fn_80018330(u32 intType);
void cbForStateCheckID3(u32 intType);
void AlarmHandler(OSAlarm *alarm, OSContext *context);
void stateCoverClosed(void);
void stateCoverClosed_CMD(DVDCommandBlock *block);
void cbForStateCoverClosed(u32 intType);
void fn_800186C0(void);
void cbForStateMotorStopped(u32 intType);
void stateReady(void);
void stateBusy(DVDCommandBlock *block);
void cbForStateBusy(u32 intType);
void DVDReset(void);
s32 DVDGetCommandBlockStatus(const DVDCommandBlock *block);
s32 DVDGetDriveStatus(void);
BOOL fn_8001989C(BOOL autoInval);
void DVDResume(void);
BOOL DVDCancelAsync(DVDCommandBlock *block, DVDCBCallback callback);
s32 DVDCancel(DVDCommandBlock *block);
void fn_80019C24(s32 result, DVDCommandBlock *block);
DVDDiskID *fn_80019C48(void);
BOOL DVDCheckDisk(void);
void __DVDPrepareResetAsync(DVDCBCallback callback);

static inline void stateError(u32 error) {
    __DVDStoreErrorCode(error);
    DVDLowStopMotor(cbForStateError);
}

static inline void stateTimeoutInline(void) {
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
}

static inline void stateGettingErrorInline(void) {
    DVDLowRequestError(cbForStateGettingError);
}

static inline void stateMotorStoppedInline(void) {
    DVDLowWaitCoverClose(cbForStateMotorStopped);
}

static inline void stateGoToRetryInline(void) {
    DVDLowStopMotor(cbForStateGoToRetry);
}

static inline BOOL CheckCancel(u32 resume) {
    DVDCommandBlock *finished;
    if (lbl_801A68E0) {
        ResumeFromHere = resume;
        lbl_801A68E0 = 0;
        finished = executing;
        executing = &DummyCommandBlock;
        finished->state = 10;
        if (finished->callback) {
            finished->callback(-3, finished);
        }
        if (lbl_801A68E4) {
            lbl_801A68E4(0, finished);
        }
        stateReady();
        return TRUE;
    }
    return FALSE;
}


void DVDInit() {
    if (DVDInitialized) {
        return;
    }
    OSRegisterVersion(__DVDVersion);
    DVDInitialized = 1;
    __DVDFSInit();
    __DVDClearWaitingQueue();
    __DVDInitWA();
    bootInfo = (OSBootInfo *)((void *)((u32)(0x0000) + (0x8000 << 16)));
    IDShouldBe = &(bootInfo->DVDDiskID);
    __OSSetInterruptHandler(21, __DVDInterruptHandler);
    __OSUnmaskInterrupts(0x400);
    OSInitThreadQueue(&__DVDThreadQueue);
    __DIRegs[0] = 0x2a;
    __DIRegs[1] = 0;
    if (bootInfo->magic == 0xE5207C22) {
        OSReport("load fst\n");
        __fstLoad();
    } else if (bootInfo->magic != 0xD15EA5E) {
        FirstTimeInBootrom = 1;
    }
}

void fn_80017838(void) {
    lbl_801A6904 = (stateFunc)fn_80017838;
    if (bootInfo->FSTMaxLength < BB2[2]) {
        OSPanic(lbl_801A6484, 0x287, "DVDChangeDisk(): FST in the new disc is too big.   ");
    }
    DVDLowRead(bootInfo->FSTLocation, (BB2[2] + 0x1f) & ~0x1f,
                BB2[1], cbForStateReadingFST);
}

void cbForStateReadingFST(u32 intType) {
    CommandBlock *old;

    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
    } else if ((intType & 1) != 0) {
        lbl_801A68F4 = 0;
        __DVDFSInit();
        old = executing;
        executing = &DummyCommandBlock;
        old->state = 0;
        if (old->callback != 0) {
            old->callback(0, old);
        }
        stateReady();
    } else {
        _epilog_rel_sample();
    }
}

void cbForStateError(u32 intType) {
    DVDCommandBlock *block;

    if (intType == 16) {
        block = executing;
        *(s32 *)((u8 *)block + 12) = -1;
        stateTimeout();
    } else {
        __DVDPrintFatalMessage();
        block = executing;
        FatalErrorFlag = 1;
        executing = (DVDCommandBlock *)&DummyCommandBlock;
        if (block->callback != 0) {
            block->callback(-1, block);
        }
        if (lbl_801A68E0 != 0) {
            lbl_801A68E0 = 0;
            if (lbl_801A68E4 != 0) {
                ((void (*)(s32, DVDCommandBlock *))lbl_801A68E4)(0, block);
            }
        }
        stateReady();
    }
}

void stateTimeout(void) {
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
}

void _epilog_rel_sample(void) {
    DVDLowRequestError(cbForStateGettingError);
}

int CategorizeError(u32 value) {
    u32 masked;
    if (value - 0x20000 == 0x400) {
        lbl_801A68F0 = value;
        return 1;
    }

    masked = value & 0x00ffffff;
    if (masked - 0x60000 == 0x2800 ||
        masked - 0x20000 == 0x3a00 ||
        masked - 0xb0000 == 0x5a01) {
        return 0;
    }

    lbl_801A68F4++;
    if (lbl_801A68F4 == 2) {
        if (masked == lbl_801A68F0) {
            lbl_801A68F0 = masked;
            return 1;
        }
        lbl_801A68F0 = masked;
        return 2;
    }

    lbl_801A68F0 = masked;
    if (masked - 0x30000 == 0x1100 ||
        executing->command == 5) {
        return 2;
    }
    return 3;
}

void cbForStateGettingError(u32 intType) {
    u32 error;
    u32 status;
    u32 errorCategory;
    u32 resume;
    if (intType == 16) {
        executing->state = -1;
        stateTimeoutInline();
        return;
    }
    if (intType & 2) {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }
    error = __DIRegs[8];
    status = error & 0xff000000;
    errorCategory = CategorizeError(error);
    if (errorCategory == 1) {
        executing->state = -1;
        stateError(error);
        return;
    }
    if ((errorCategory == 2) || (errorCategory == 3)) {
        resume = 0;
    } else {
        if (status == 0x01000000)
            resume = 4;
        else if (status == 0x02000000)
            resume = 6;
        else if (status == 0x03000000)
            resume = 3;
        else
            resume = 5;
    }
    if (CheckCancel(resume))
        return;
    if (errorCategory == 2) {
        __DVDStoreErrorCode(error);
        fn_80017EA8();
        return;
    }
    if (errorCategory == 3) {
        if ((error & 0x00ffffff) == 0x00031100) {
            DVDLowSeek(executing->offset, cbForUnrecoveredError);
        } else {
            lbl_801A6904(executing);
        }
        return;
    }
    if (status == 0x01000000) {
        executing->state = 5;
        fn_800186C0();
        return;
    } else if (status == 0x02000000) {
        executing->state = 3;
        stateCoverClosed();
        return;
    } else if (status == 0x03000000) {
        executing->state = 4;
        fn_800186C0();
        return;
    } else {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }
}

void cbForUnrecoveredError(u32 state) {
    if (state == 0x10) {
        executing->state = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (state & 1) {
        fn_80017EA8();
    } else {
        DVDLowRequestError(cbForUnrecoveredErrorRetry);
    }
}

void cbForUnrecoveredErrorRetry(u32 state) {
    if (state == 0x10) {
        executing->state = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else {
        executing->state = -1;
        if (state & 2) {
            __DVDStoreErrorCode(0x01234567);
            DVDLowStopMotor(cbForStateError);
        } else {
            __DVDStoreErrorCode(__DVDRegs.reg[8]);
            DVDLowStopMotor(cbForStateError);
        }
    }
}

void fn_80017EA8(void) {
    DVDLowStopMotor(cbForStateGoToRetry);
}

void cbForStateGoToRetry(u32 intType) {
    if (intType == 16) {
        executing->state = -1;
        stateTimeoutInline();
        return;
    }
    if (intType & 2) {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }
    lbl_801A68F4 = 0;
    if ((CurrCommand == 4) || (CurrCommand == 5) ||
        (CurrCommand == 13) || (CurrCommand == 15)) {
        ResetRequired = 1;
    }
    if (!CheckCancel(2)) {
        executing->state = 11;
        fn_800186C0();
    }
}

void stateCheckID(void) {
    struct dvdBss *bb = (struct dvdBss *)BB2_8015CE40;
    switch (CurrCommand) {
    case 3:
        if (DVDCompareDiskID(&bb->CurrDiskID, executing->id)) {
            memcpy(IDShouldBe, &((struct dvdBss *)BB2_8015CE40)->CurrDiskID, 0x20);
            executing->state = 1;
            DCInvalidateRange(bb, 0x20);
            lbl_801A6904 = (stateFunc)fn_8001813C;
            fn_8001813C(executing);
        } else {
            DVDLowStopMotor(cbForStateCheckID1);
        }
        break;
    default:
        if (memcmp(&((struct dvdBss *)BB2_8015CE40)->CurrDiskID, IDShouldBe, 0x20)) {
            DVDLowStopMotor(cbForStateCheckID1);
        } else {
            lbl_801A6904 = (stateFunc)fn_80018108;
            fn_80018108(executing);
        }
        break;
    }
}

void fn_80018108(DVDCommandBlock *block) {
    (void)block;
    DVDLowAudioBufferConfig(IDShouldBe->streaming, 10, cbForStateCheckID3);
}

void fn_8001813C(DVDCommandBlock *block) {
    (void)block;
    DVDLowAudioBufferConfig(IDShouldBe->streaming, 10, cbForStateCheckID2a);
}

void cbForStateCheckID2a(u32 state) {
    if (state == 0x10) {
        executing->state = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (state & 1) {
        lbl_801A68F4 = 0;
        stateCheckID2(executing);
    } else {
        DVDLowRequestError(cbForStateGettingError);
    }
}

void stateCheckID2(DVDCommandBlock *block) {
    (void)block;
    DVDLowRead(BB2_8015CE40, 32, 1056, fn_80018330);
}

void cbForStateCheckID1(u32 intType) {
    if (intType == 16) {
        executing->state = -1;
        stateTimeoutInline();
        return;
    }
    if (intType & 2) {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }
    lbl_801A68F4 = 0;
    if (!CheckCancel(1)) {
        executing->state = 6;
        fn_800186C0();
    }
}

void fn_80018330(u32 state) {
    if (state == 0x10) {
        executing->state = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (state & 1) {
        lbl_801A68F4 = 0;
        lbl_801A6904 = (stateFunc)fn_80017838;
        if (bootInfo->FSTMaxLength < BB2[2]) {
            OSPanic(lbl_801A6484, 0x287, "DVDChangeDisk(): FST in the new disc is too big.   ");
        }
        DVDLowRead(bootInfo->FSTLocation,
                    (BB2[2] + 0x1f) & ~0x1f,
                    BB2[1],
                    cbForStateReadingFST);
    } else {
        DVDLowRequestError(cbForStateGettingError);
    }
}

void cbForStateCheckID3(u32 intType) {
    if (intType == 16) {
        executing->state = -1;
        stateTimeoutInline();
        return;
    }
    if (intType & 1) {
        lbl_801A68F4 = 0;
        if (!CheckCancel(0)) {
            executing->state = 1;
            stateBusy(executing);
        }
    } else {
        stateGettingErrorInline();
    }
}

void AlarmHandler(OSAlarm *alarm, OSContext *context) {
    (void)alarm;
    (void)context;
    DVDReset();
    DCInvalidateRange(lbl_8015CE60__fzgx_offset_0, 32);
    lbl_801A6904 = (stateFunc)stateCoverClosed_CMD;
    stateCoverClosed_CMD(executing);
}

void stateCoverClosed() {
    struct dvdBss *bss = (struct dvdBss *)BB2_8015CE40;

    DVDCommandBlock *finished;
    switch (CurrCommand) {
    case 5:
    case 4:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        finished = executing;
        executing = &(bss->DummyCommandBlock);
        if (finished->callback) {
            (finished->callback)(-4, finished);
        }
        stateReady();
        break;
    default:
        DVDReset();
        OSCreateAlarm(&(bss->ResetAlarm));
        OSSetAlarm(&(bss->ResetAlarm), ((1150) * (((u32)__OSBusClock / 4) / 1000)), AlarmHandler);
        break;
    }
}

void stateCoverClosed_CMD(DVDCommandBlock *block) {
    (void)block;
    DVDLowReadDiskID((DVDDiskID *)lbl_8015CE60__fzgx_offset_0, cbForStateCoverClosed);
}

void cbForStateCoverClosed(u32 state) {
    if (state == 0x10) {
        executing->state = -1;
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (state & 1) {
        lbl_801A68F4 = 0;
        stateCheckID();
    } else {
        DVDLowRequestError(cbForStateGettingError);
    }
}

void fn_800186C0(void) {
    DVDLowWaitCoverClose(cbForStateMotorStopped);
}

void cbForStateMotorStopped(u32 intType) {
    struct dvdBss *bss = (struct dvdBss *)BB2_8015CE40;
    DVDCommandBlock *finished;

    __DIRegs[1] = 0;
    executing->state = 3;
    switch (CurrCommand) {
    case 5:
    case 4:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        finished = executing;
        executing = &(bss->DummyCommandBlock);
        if (finished->callback) {
            (finished->callback)(-4, finished);
        }
        stateReady();
        break;
    default:
        DVDReset();
        OSCreateAlarm(&(bss->ResetAlarm));
        OSSetAlarm(&(bss->ResetAlarm),
                   ((1150) * (((u32)__OSBusClock / 4) / 1000)), AlarmHandler);
        break;
    }
}

static inline void stateCoverClosed_inline(struct dvdBss *bss) {

    DVDCommandBlock *finished;
    switch (CurrCommand) {
    case 5:
    case 4:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        finished = executing;
        executing = &(bss->DummyCommandBlock);
        if (finished->callback) {
            (finished->callback)(-4, finished);
        }
        stateReady();
        break;
    default:
        DVDReset();
        OSCreateAlarm(&(bss->ResetAlarm));
        OSSetAlarm(&(bss->ResetAlarm), ((1150) * (((u32)__OSBusClock / 4) / 1000)), AlarmHandler);
        break;
    }
}

void stateReady() {
    struct dvdBss *bss = (struct dvdBss *)BB2_8015CE40;

    DVDCommandBlock *finished;
    if (!__DVDCheckWaitingQueue()) {
        executing = (DVDCommandBlock *)0;
        return;
    }
    if (PauseFlag) {
        PausingFlag = 1;
        executing = (DVDCommandBlock *)0;
        return;
    }
    executing = __DVDPopWaitingQueue();
    if (FatalErrorFlag) {
        executing->state = -1;
        finished = executing;
        executing = &(bss->DummyCommandBlock);
        if (finished->callback) {
            (finished->callback)(-1, finished);
        }
        stateReady();
        return;
    }
    CurrCommand = executing->command;
    if (ResumeFromHere) {
        switch (ResumeFromHere) {
        case 2:
            executing->state = 11;
            stateMotorStoppedInline();
            break;
        case 3:
            executing->state = 4;
            stateMotorStoppedInline();
            break;
        case 4:
            executing->state = 5;
            stateMotorStoppedInline();
            break;
        case 1:
        case 7:
        case 6:
            executing->state = 3;
            stateCoverClosed_inline(bss);
            break;
        case 5:
            executing->state = -1;
            stateError(CancelLastError);
            break;
        }
        ResumeFromHere = 0;
    } else {
        executing->state = 1;
        stateBusy(executing);
    }
}

void stateBusy(DVDCommandBlock *block) {
    DVDCommandBlock *finished;
    lbl_801A6904 = stateBusy;
    switch (block->command) {
    case 5:
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = sizeof(DVDDiskID);
        DVDLowReadDiskID(block->addr, cbForStateBusy);
        break;
    case 1:
    case 4:
        if (!block->length) {
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                finished->callback(0, finished);
            }
            stateReady();
        } else {
            __DIRegs[1] = __DIRegs[1];
            block->currTransferSize = block->length - block->transferredSize > 0x80000
                                          ? 0x80000
                                          : block->length - block->transferredSize;
            DVDLowRead((void *)((u8 *)block->addr + block->transferredSize),
                        block->currTransferSize, block->offset + block->transferredSize,
                        cbForStateBusy);
        }
        break;
    case 2:
        __DIRegs[1] = __DIRegs[1];
        DVDLowSeek(block->offset, cbForStateBusy);
        break;
    case 3:
        DVDLowStopMotor(cbForStateBusy);
        break;
    case 15:
        DVDLowStopMotor(cbForStateBusy);
        break;
    case 6:
        __DIRegs[1] = __DIRegs[1];
        if (lbl_801A68D4) {
            executing->currTransferSize = 0;
            DVDLowRequestAudioStatus(0, cbForStateBusy);
        } else {
            executing->currTransferSize = 1;
            DVDLowAudioStream(0, block->length, block->offset, cbForStateBusy);
        }
        break;
    case 7:
        __DIRegs[1] = __DIRegs[1];
        DVDLowAudioStream(0x10000, 0, 0, cbForStateBusy);
        break;
    case 8:
        __DIRegs[1] = __DIRegs[1];
        lbl_801A68D4 = 1;
        DVDLowAudioStream(0, 0, 0, cbForStateBusy);
        break;
    case 9:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0, cbForStateBusy);
        break;
    case 10:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0x10000, cbForStateBusy);
        break;
    case 11:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0x20000, cbForStateBusy);
        break;
    case 12:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0x30000, cbForStateBusy);
        break;
    case 13:
        __DIRegs[1] = __DIRegs[1];
        DVDLowAudioBufferConfig(block->offset, block->length, cbForStateBusy);
        break;
    case 14:
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = sizeof(DVDDriveInfo);
        DVDLowInquiry(block->addr, cbForStateBusy);
        break;
    default:
        lbl_801A6480(block, cbForStateBusy);
        break;
    }
}

static inline BOOL IsImmCommandWithResult(u32 command) {
    static u32 lbl_80124058_tbl[20] = {
        0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU,
        0x44564443U, 0x68616E67U, 0x65446973U, 0x6B417379U, 0x6E632829U,
        0x3A20596FU, 0x75206361U, 0x6E277420U, 0x73706563U, 0x69667920U,
        0x4E554C4CU, 0x20746F20U, 0x636F6D70U, 0x616E7920U, 0x6E616D65U,
        0x2E20200AU, 0x00000000U
    };
    u32 i;
    if (command == 9 || command == 10 || command == 11 || command == 12) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        if (command == lbl_80124058_tbl[i])
            return 1;
    }
    return 0;
}

static inline BOOL IsDmaCommand(u32 command) {
    u32 i;
    if (command == 1 || command == 4 || command == 5 || command == 14)
        return 1;
    for (i = 0; i < sizeof(lbl_801A648C) / sizeof(lbl_801A648C[0]); i++) {
        if (command == lbl_801A648C[i])
            return 1;
    }
    return 0;
}

void cbForStateBusy(u32 intType) {
    DVDCommandBlock *finished;
    if (intType == 16) {
        executing->state = -1;
        stateTimeoutInline();
        return;
    }
    if ((CurrCommand == 3) || (CurrCommand == 15)) {
        if (intType & 2) {
            executing->state = -1;
            stateError(0x1234567);
            return;
        }
        lbl_801A68F4 = 0;
        if (CurrCommand == 15) {
            ResetRequired = 1;
        }
        if (CheckCancel(7)) {
            return;
        }
        executing->state = 7;
        stateMotorStoppedInline();
        return;
    }
    if (IsDmaCommand(CurrCommand)) {
        executing->transferredSize += executing->currTransferSize - __DIRegs[6];
    }
    if (intType & 8) {
        lbl_801A68E0 = 0;
        finished = executing;
        executing = &DummyCommandBlock;
        finished->state = 10;
        if (finished->callback)
            (*finished->callback)(-3, finished);
        if (lbl_801A68E4)
            (lbl_801A68E4)(0, finished);
        stateReady();
        return;
    }
    if (intType & 1) {
        lbl_801A68F4 = 0;
        if (CheckCancel(0))
            return;
        if (IsDmaCommand(CurrCommand)) {
            if (executing->transferredSize != executing->length) {
                stateBusy(executing);
                return;
            }
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)((s32)finished->transferredSize, finished);
            }
            stateReady();
        } else if (IsImmCommandWithResult(CurrCommand)) {
            s32 result;
            if ((CurrCommand == 11) || (CurrCommand == 10)) {
                result = (s32)(__DIRegs[8] << 2);
            } else {
                result = (s32)__DIRegs[8];
            }
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)(result, finished);
            }
            stateReady();
        } else if (CurrCommand == 6) {
            if (executing->currTransferSize == 0) {
                if (__DIRegs[8] & 1) {
                    finished = executing;
                    executing = &DummyCommandBlock;
                    finished->state = 9;
                    if (finished->callback) {
                        (finished->callback)(-2, finished);
                    }
                    stateReady();
                } else {
                    lbl_801A68D4 = 0;
                    executing->currTransferSize = 1;
                    DVDLowAudioStream(0, executing->length, executing->offset,
                                      cbForStateBusy);
                }
            } else {
                finished = executing;
                executing = &DummyCommandBlock;
                finished->state = 0;
                if (finished->callback) {
                    (finished->callback)(0, finished);
                }
                stateReady();
            }
        } else {
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)(0, finished);
            }
            stateReady();
        }
    } else {
        if (CurrCommand == 14) {
            executing->state = -1;
            stateError(0x01234567);
            return;
        }
        if ((CurrCommand == 1 || CurrCommand == 4 || CurrCommand == 5 ||
             CurrCommand == 14) &&
            (executing->transferredSize == executing->length)) {
            if (CheckCancel(0)) {
                return;
            }
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)((s32)finished->transferredSize, finished);
            }
            stateReady();
            return;
        }
        stateGettingErrorInline();
    }
}

u32 DVDReadAbsAsyncPrio(DVDCommandBlock *block, void *addr, u32 length, u32 zero10, void *callback, u32 prio) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    alignment = 0;
    block->command = 1;
    block->addr = addr;
    block->length = length;
    block->offset = zero10;
    block->transferredSize = 0;
    block->callback = (DVDCBCallback)callback;

    if (autoInvalidation != 0) {
        if (block->command == 1 ||
            (block->command - 4) <= 1 ||
            block->command == 0xe) {
            DCInvalidateRange(block->addr, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->state = 2;
    result = __DVDPushWaitingQueue(prio, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result;
}

u32 DVDReadAbsAsyncForBS(DVDCommandBlock *block, void *addr, u32 length, u32 unk10,
                void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    block->command = 4;
    block->addr = addr;
    block->length = length;
    block->offset = unk10;
    block->transferredSize = 0;
    block->callback = (DVDCBCallback)callback;

    if (autoInvalidation != 0) {
        if (block->command == 1 ||
            (block->command - 4) <= 1 ||
            block->command == 0xe) {
            DCInvalidateRange(block->addr, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->state = 2;
    result = __DVDPushWaitingQueue(2, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result;
}

u32 DVDReadDiskID(DVDCommandBlock *block, void *addr, void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    alignment = 0;
    block->command = 5;
    block->addr = addr;
    block->length = 0x20;
    block->offset = 0;
    block->transferredSize = 0;
    block->callback = (DVDCBCallback)callback;

    if (autoInvalidation != 0) {
        if (block->command == 1 ||
            (block->command - 4) <= 1 ||
            block->command == 0xe) {
            DCInvalidateRange(block->addr, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->state = 2;
    result = __DVDPushWaitingQueue(2, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result + (u32)alignment;
}

u32 DVDCancelStreamAsync(DVDCommandBlock *block, void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    block->command = 7;
    block->callback = (DVDCBCallback)callback;

    if (autoInvalidation != 0) {
        if (block->command == 1 ||
            (block->command - 4) <= 1 ||
            block->command == 0xe) {
            DCInvalidateRange(block->addr, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->state = 2;
    result = __DVDPushWaitingQueue(1, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result;
}

u32 DVDInquiryAsync(DVDCommandBlock *block, void *addr, void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    alignment = 0;
    block->command = 0xe;
    block->addr = addr;
    block->length = 0x20;
    block->transferredSize = 0;
    block->callback = (DVDCBCallback)callback;

    if (autoInvalidation != 0) {
        if (block->command == 1 ||
            (block->command - 4) <= 1 ||
            block->command == 0xe) {
            DCInvalidateRange(block->addr, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->state = 2;
    result = __DVDPushWaitingQueue(2, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result + (u32)alignment;
}

void DVDReset(void) {
    DVDLowReset();
    __DIRegs[0] = 0x2a;
    __DIRegs[1] = __DIRegs[1];
    ResetRequired = 0;
    ResumeFromHere = 0;
}

s32 DVDGetCommandBlockStatus(const DVDCommandBlock *block) {
    BOOL enabled;
    s32 retVal;
    enabled = OSDisableInterrupts();
    if (block->state == 3) {
        retVal = 1;
    } else {
        retVal = block->state;
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

s32 DVDGetDriveStatus(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2;
    t0 = OSDisableInterrupts();
    v0 = (t0 + 0);
    v2 = t0;
    if ((s32)FatalErrorFlag != 0) {
    v1 = -1;
    } else {
    if ((s32)PausingFlag != 0) {
    v1 = 8;
    } else {
    v1 = (u32)executing;
    if (v1 == 0) {
    v1 = 0;
    } else {
    if (v1 == (u32)&DummyCommandBlock) {
    v1 = 0;
    } else {
    t1 = OSDisableInterrupts();
    v2 = t1;
    v1 = *(u32 *)((u8 *)v1 + 12);
    if ((s32)v1 == 3) {
    v1 = 1;
    }
    t2 = OSRestoreInterrupts(v2);
    v2 = t2;
    }
    }
    }
    }
    OSRestoreInterrupts(v0);
    return v1;
}

BOOL fn_8001989C(BOOL autoInval) {
    BOOL prev;
    prev = autoInvalidation;
    autoInvalidation = autoInval;
    return prev;
}

void DVDResume(void) {
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    PauseFlag = 0;
    if (PausingFlag) {
        PausingFlag = 0;
        stateReady();
    }
    OSRestoreInterrupts(interrupts);
}

BOOL DVDCancelAsync(DVDCommandBlock *block, DVDCBCallback callback) {
    BOOL enabled;
    DVDLowCallback old;
    DVDCommandBlock *finished;
    enabled = OSDisableInterrupts();
    switch (block->state) {
    case -1:
    case 0:
    case 10:
        if (callback)
            (*callback)(0, block);
        break;
    case 1:
        if (lbl_801A68E0) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        lbl_801A68E0 = 1;
        lbl_801A68E4 = callback;
        if (block->command == 4 || block->command == 1) {
            DVDLowBreak();
        }
        break;
    case 2:
        __DVDDequeueWaitingQueue(block);
        block->state = 10;
        if (block->callback)
            (block->callback)(-3, block);
        if (callback)
            (*callback)(0, block);
        break;
    case 3:
        switch (block->command) {
        case 5:
        case 4:
        case 13:
        case 15:
            if (callback)
                (*callback)(0, block);
            break;
        default:
            if (lbl_801A68E0) {
                OSRestoreInterrupts(enabled);
                return 0;
            }
            lbl_801A68E0 = 1;
            lbl_801A68E4 = callback;
            break;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        old = DVDLowClearCallback();
        if (old != cbForStateMotorStopped) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        if (block->state == 4)
            ResumeFromHere = 3;
        if (block->state == 5)
            ResumeFromHere = 4;
        if (block->state == 6)
            ResumeFromHere = 1;
        if (block->state == 11)
            ResumeFromHere = 2;
        if (block->state == 7)
            ResumeFromHere = 7;
        executing = &DummyCommandBlock;
        block->state = 10;
        if (block->callback) {
            (block->callback)(-3, block);
        }
        if (callback) {
            (callback)(0, block);
        }
        stateReady();
        break;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

s32 DVDCancel(DVDCommandBlock *block) {
    BOOL interrupt_state;
    s32 status;
    u32 state;

    if (DVDCancelAsync(block, fn_80019C24) == 0) {
        return -1;
    }

    interrupt_state = OSDisableInterrupts();
    for (;;) {
        status = block->state;
        if ((u32)(status + 1) <= 1 || status == 10) {
            break;
        }
        if (status == 3) {
            state = block->command;
            if ((state - 4) <= 1 || state == 13 || state == 15) {
                break;
            }
        }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupt_state);
    return 0;
}

void fn_80019C24(s32 result, DVDCommandBlock *block) {
    OSWakeupThread(&__DVDThreadQueue);
}

DVDDiskID *fn_80019C48(void) {
    return (DVDDiskID *)0x80000000; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

BOOL DVDCheckDisk(void) {
    BOOL enabled;
    s32 retVal;
    s32 state;
    u32 coverReg;
    enabled = OSDisableInterrupts();
    if (FatalErrorFlag) {
        state = -1;
    } else if (PausingFlag) {
        state = 8;
    } else {
        if (executing == (DVDCommandBlock *)0) {
            state = 0;
        } else if (executing == &DummyCommandBlock) {
            state = 0;
        } else {
            state = executing->state;
        }
    }
    switch (state) {
    case 1:
    case 9:
    case 10:
    case 2:
        retVal = 1;
        break;
    case -1:
    case 11:
    case 7:
    case 3:
    case 4:
    case 5:
    case 6:
        retVal = 0;
        break;
    case 0:
    case 8:
        coverReg = __DIRegs[1];
        if (((coverReg >> 2) & 1) || (coverReg & 1)) {
            retVal = 0;
        } else if (ResumeFromHere) {
            retVal = 0;
        } else {
            retVal = 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

static inline void DVDPause(void) {
    BOOL level;
    level = OSDisableInterrupts();
    PauseFlag = 1;
    if (executing == (DVDCommandBlock *)0) {
        PausingFlag = 1;
    }
    OSRestoreInterrupts(level);
}

static inline void DVDResume_inline(void) {
    BOOL level;
    level = OSDisableInterrupts();
    PauseFlag = 0;
    if (PausingFlag) {
        PausingFlag = 0;
        stateReady();
    }
    OSRestoreInterrupts(level);
}

static inline BOOL DVDCancelAllAsync(DVDCBCallback callback) {
    BOOL enabled;
    DVDCommandBlock *p;
    BOOL retVal;
    enabled = OSDisableInterrupts();
    DVDPause();
    while ((p = __DVDPopWaitingQueue()) != 0) {
        DVDCancelAsync(p, 0);
    }
    if (executing)
        retVal = DVDCancelAsync(executing, callback);
    else {
        retVal = 1;
        if (callback)
            (*callback)(0, 0);
    }
    DVDResume_inline();
    OSRestoreInterrupts(enabled);
    return retVal;
}

void __DVDPrepareResetAsync(DVDCBCallback callback) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    __DVDClearWaitingQueue();
    if (lbl_801A68E0) {
        lbl_801A68E4 = callback;
    } else {
        if (executing) {
            executing->callback = 0;
        }
        DVDCancelAllAsync(callback);
    }
    OSRestoreInterrupts(enabled);
}
