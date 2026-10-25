#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

// Hardware or OS state can change asynchronously.
typedef volatile s32 vs32;

typedef void (*DVDLowCallback)(u32 intType);

void DVDReset();

void __DVDStoreErrorCode(u32 error);

BOOL DVDLowWaitCoverClose(DVDLowCallback callback);

BOOL DVDLowStopMotor(DVDLowCallback callback);

BOOL DVDLowRequestError(DVDLowCallback callback);

BOOL DVDLowAudioStream(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback);

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern DVDCommandBlock *executing_801A68C0;

// Hardware or OS state can change asynchronously.
extern volatile BOOL lbl_801A68D4; // fzgx-allow: S2 SDK asynchronous state

extern vu32 CurrCommand_801A68DC;

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

extern vu32 ResumeFromHere_801A68E8;

extern vs32 lbl_801A68F4;

// Hardware or OS state can change asynchronously.
extern volatile BOOL ResetRequired_801A68F8; // fzgx-allow: S2 SDK asynchronous state

static void stateTimeout();

static void stateGettingError();

static void stateMotorStopped();

void stateReady();

void stateBusy();

void cbForStateError(u32 intType);

void cbForStateGettingError(u32 intType);

void cbForStateMotorStopped(u32 intType);

static unsigned char BB2_8015CE40[32];

static unsigned char lbl_8015CE60__fzgx_offset_0[32];

static DVDCommandBlock DummyCommandBlock;

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&BB2_8015CE40;
    sink = *(unsigned char *)&lbl_8015CE60__fzgx_offset_0;
    sink = *(unsigned char *)&DummyCommandBlock;
}
#pragma section code_type ".text"

static inline void stateError(u32 error) {
    __DVDStoreErrorCode(error);
    DVDLowStopMotor(cbForStateError);
}

static inline void stateTimeout() {
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
}

static inline void stateGettingError() { DVDLowRequestError(cbForStateGettingError); }

static inline BOOL CheckCancel(u32 resume) {
    DVDCommandBlock *finished;
    if (lbl_801A68E0) {
        ResumeFromHere_801A68E8 = resume;
        lbl_801A68E0 = 0;
        finished = executing_801A68C0;
        executing_801A68C0 = &DummyCommandBlock;
        finished->state = 10;
        if (finished->callback)
            (*finished->callback)(-3, finished);
        if (lbl_801A68E4)
            (lbl_801A68E4)(0, finished);
        stateReady();
        return 1;
    }
    return 0;
}

static inline void stateMotorStopped(void) { DVDLowWaitCoverClose(cbForStateMotorStopped); }

void stateBusy(DVDCommandBlock *block);

extern u32 lbl_80124058[3];

extern u32 lbl_801A648C[1];

static inline BOOL IsImmCommandWithResult(u32 command) {
    u32 i;
    if (command == 9 || command == 10 || command == 11 || command == 12) {
        return 1;
    }
    for (i = 0; i < sizeof(lbl_80124058) / sizeof(lbl_80124058[0]); i++) {
        if (command == lbl_80124058[i])
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

void DVDReset(void);

void cbForStateBusy(u32 intType) {
    DVDCommandBlock *finished;
    if (intType == 16) {
        executing_801A68C0->state = -1;
        stateTimeout();
        return;
    }
    if ((CurrCommand_801A68DC == 3) || (CurrCommand_801A68DC == 15)) {
        if (intType & 2) {
            executing_801A68C0->state = -1;
            stateError(0x1234567);
            return;
        }
        lbl_801A68F4 = 0;
        if (CurrCommand_801A68DC == 15) {
            ResetRequired_801A68F8 = 1;
        }
        if (CheckCancel(7)) {
            return;
        }
        executing_801A68C0->state = 7;
        stateMotorStopped();
        return;
    }
    if (IsDmaCommand(CurrCommand_801A68DC)) {
        executing_801A68C0->transferredSize += executing_801A68C0->currTransferSize - __DIRegs[6];
    }
    if (intType & 8) {
        lbl_801A68E0 = 0;
        finished = executing_801A68C0;
        executing_801A68C0 = &DummyCommandBlock;
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
        if (IsDmaCommand(CurrCommand_801A68DC)) {
            if (executing_801A68C0->transferredSize != executing_801A68C0->length) {
                stateBusy(executing_801A68C0);
                return;
            }
            finished = executing_801A68C0;
            executing_801A68C0 = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)((s32)finished->transferredSize, finished);
            }
            stateReady();
        } else if (IsImmCommandWithResult(CurrCommand_801A68DC)) {
            s32 result;
            if ((CurrCommand_801A68DC == 11) || (CurrCommand_801A68DC == 10)) {
                result = (s32)(__DIRegs[8] << 2);
            } else {
                result = (s32)__DIRegs[8];
            }
            finished = executing_801A68C0;
            executing_801A68C0 = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)(result, finished);
            }
            stateReady();
        } else if (CurrCommand_801A68DC == 6) {
            if (executing_801A68C0->currTransferSize == 0) {
                if (__DIRegs[8] & 1) {
                    finished = executing_801A68C0;
                    executing_801A68C0 = &DummyCommandBlock;
                    finished->state = 9;
                    if (finished->callback) {
                        (finished->callback)(-2, finished);
                    }
                    stateReady();
                } else {
                    lbl_801A68D4 = 0;
                    executing_801A68C0->currTransferSize = 1;
                    DVDLowAudioStream(0, executing_801A68C0->length, executing_801A68C0->offset,
                                      cbForStateBusy);
                }
            } else {
                finished = executing_801A68C0;
                executing_801A68C0 = &DummyCommandBlock;
                finished->state = 0;
                if (finished->callback) {
                    (finished->callback)(0, finished);
                }
                stateReady();
            }
        } else {
            finished = executing_801A68C0;
            executing_801A68C0 = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)(0, finished);
            }
            stateReady();
        }
    } else {
        if (CurrCommand_801A68DC == 14) {
            executing_801A68C0->state = -1;
            stateError(0x01234567);
            return;
        }
        if ((CurrCommand_801A68DC == 1 || CurrCommand_801A68DC == 4 || CurrCommand_801A68DC == 5 ||
             CurrCommand_801A68DC == 14) &&
            (executing_801A68C0->transferredSize == executing_801A68C0->length)) {
            if (CheckCancel(0)) {
                return;
            }
            finished = executing_801A68C0;
            executing_801A68C0 = &DummyCommandBlock;
            finished->state = 0;
            if (finished->callback) {
                (finished->callback)((s32)finished->transferredSize, finished);
            }
            stateReady();
            return;
        }
        stateGettingError();
    }
}
