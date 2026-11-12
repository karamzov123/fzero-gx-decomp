#include "sdk_addresses.h"

#include "types.h"

#define cbForStateMotorStopped cbForStateMotorStopped

// Hardware or OS state can change asynchronously.
typedef volatile u32 vu32;

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf_pad;
    f64 psf[32];
} OSContext;

typedef s64 OSTime;

typedef struct OSAlarm OSAlarm;

typedef void (*OSAlarmHandler)(OSAlarm *alarm, OSContext *context);

struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTime period;
    OSTime start;
};

typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamingBufSize;
    u8 padding[22];
} DVDDiskID;

typedef struct DVDCommandBlock DVDCommandBlock;

typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock *block);

struct DVDCommandBlock {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
    u32 command;
    s32 state;
    u32 offset;
    u32 length;
    void *addr;
    u32 currTransferSize;
    u32 transferredSize;
    DVDDiskID *id;
    DVDCBCallback callback;
    void *userData;
};

typedef void (*DVDLowCallback)(u32 intType);

void stateReady();

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);

void DVDReset();

void __DVDStoreErrorCode(u32 error);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

BOOL DVDLowWaitCoverClose(DVDLowCallback callback);

BOOL DVDLowStopMotor(DVDLowCallback callback);

void __DVDClearWaitingQueue();

DVDCommandBlock *__DVDPopWaitingQueue();

BOOL __DVDCheckWaitingQueue();

DVDCommandBlock *__DVDPopWaitingQueue();

extern DVDCommandBlock *executing;

// Hardware or OS state can change asynchronously.
extern volatile BOOL PauseFlag;

// Hardware or OS state can change asynchronously.
extern volatile BOOL PausingFlag;

// Hardware or OS state can change asynchronously.
extern volatile BOOL FatalErrorFlag;

extern vu32 CurrCommand;

extern vu32 ResumeFromHere;

extern vu32 CancelLastError;

static void stateCoverClosed();

static void stateMotorStopped();

void stateBusy();

void cbForStateError(u32 intType);

void cbForStateMotorStopped(u32 intType);

struct dvdBss {
    unsigned char padding_0[64];
    DVDCommandBlock DummyCommandBlock;
    OSAlarm ResetAlarm;
};
extern struct dvdBss BB2;

static inline void stateError(u32 error) {
    __DVDStoreErrorCode(error);
    DVDLowStopMotor(cbForStateError);
}

void AlarmHandler(OSAlarm *alarm, OSContext *context);

static inline void stateCoverClosed(struct dvdBss *bss) {

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

static inline void stateMotorStopped(void) { DVDLowWaitCoverClose(cbForStateMotorStopped); }

void stateBusy(DVDCommandBlock *block);

void DVDReset(void);

void stateReady() {
    struct dvdBss *bss = &BB2;

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
            stateMotorStopped();
            break;
        case 3:
            executing->state = 4;
            stateMotorStopped();
            break;
        case 4:
            executing->state = 5;
            stateMotorStopped();
            break;
        case 1:
        case 7:
        case 6:
            executing->state = 3;
            stateCoverClosed(bss);
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
