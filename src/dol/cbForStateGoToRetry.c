#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/types.h>

// Hardware or OS state can change asynchronously.
typedef volatile s32 vs32;

typedef void (*DVDLowCallback)(u32 intType);

void DVDReset();

void __DVDStoreErrorCode(u32 error);

BOOL DVDLowStopMotor(DVDLowCallback callback);

extern DVDCommandBlock *executing;

extern vu32 CurrCommand;

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

extern vu32 ResumeFromHere;

extern vs32 lbl_801A68F4;

// Hardware or OS state can change asynchronously.
extern volatile BOOL ResetRequired; // fzgx-allow: S2 SDK asynchronous state

extern DVDCommandBlock DummyCommandBlock;

static void stateTimeout();

void fn_800186C0();

void stateReady();

void cbForStateError(u32 intType);

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

static inline BOOL CheckCancel(u32 resume) {
    DVDCommandBlock *finished;
    if (lbl_801A68E0) {
        ResumeFromHere = resume;
        lbl_801A68E0 = 0;
        finished = executing;
        executing = &DummyCommandBlock;
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

void fn_800186C0(void);

void stateReady();

void DVDReset(void);

void cbForStateGoToRetry(u32 intType) {
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
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
