#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);

typedef void (*stateFunc)(DVDCommandBlock *block);

void DVDReset();

void __DVDStoreErrorCode(u32 error);

BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);

BOOL DVDLowStopMotor(DVDLowCallback callback);

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern stateFunc lbl_801A6904;

extern DVDCommandBlock *executing_801A68C0;

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

extern vu32 ResumeFromHere_801A68E8;

extern DVDCommandBlock DummyCommandBlock_8015CE80;

static void stateTimeout();

void fn_80017EA8();

void stateCoverClosed();

void fn_800186C0();

void stateReady();

void cbForStateError(u32 intType);

void cbForUnrecoveredError(u32 intType);

static inline void stateError(u32 error) {
    __DVDStoreErrorCode(error);
    DVDLowStopMotor(cbForStateError);
}

void cbForStateError(u32 intType);

static inline void stateTimeout() {
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
}

u32 CategorizeError(u32 error);

static inline BOOL CheckCancel(u32 resume) {
    DVDCommandBlock *finished;
    if (lbl_801A68E0) {
        ResumeFromHere_801A68E8 = resume;
        lbl_801A68E0 = 0;
        finished = executing_801A68C0;
        executing_801A68C0 = &DummyCommandBlock_8015CE80;
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

void cbForUnrecoveredError(u32 intType);

void fn_80017EA8();

void stateCoverClosed();

void fn_800186C0(void);

void stateReady();

void DVDReset(void);

void cbForStateGettingError(u32 intType) {
    u32 error;
    u32 status;
    u32 errorCategory;
    u32 resume;
    if (intType == 16) {
        executing_801A68C0->state = -1;
        stateTimeout();
        return;
    }
    if (intType & 2) {
        executing_801A68C0->state = -1;
        stateError(0x1234567);
        return;
    }
    error = __DIRegs[8];
    status = error & 0xff000000;
    errorCategory = CategorizeError(error);
    if (errorCategory == 1) {
        executing_801A68C0->state = -1;
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
            DVDLowSeek(executing_801A68C0->offset, cbForUnrecoveredError);
        } else {
            lbl_801A6904(executing_801A68C0);
        }
        return;
    }
    if (status == 0x01000000) {
        executing_801A68C0->state = 5;
        fn_800186C0();
        return;
    } else if (status == 0x02000000) {
        executing_801A68C0->state = 3;
        stateCoverClosed();
        return;
    } else if (status == 0x03000000) {
        executing_801A68C0->state = 4;
        fn_800186C0();
        return;
    } else {
        executing_801A68C0->state = -1;
        stateError(0x1234567);
        return;
    }
}
