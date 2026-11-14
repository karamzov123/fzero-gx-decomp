#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/types.h>

// Hardware or OS state can change asynchronously.
typedef volatile s32 vs32;

typedef void (*DVDLowCallback)(u32 intType);

void DVDReset();

void __DVDStoreErrorCode(u32 error);

BOOL DVDLowRequestError(DVDLowCallback callback);

extern DVDCommandBlock *executing;

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

extern vu32 ResumeFromHere;

extern vs32 lbl_801A68F4;

extern DVDCommandBlock DummyCommandBlock;

static void stateTimeout();

static void stateGettingError();

void stateReady();

void stateBusy();

void cbForStateError(u32 intType);

void cbForStateGettingError(u32 intType);

void cbForStateError(u32 intType);

static inline void stateTimeout() {
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
}

static inline void stateGettingError() { DVDLowRequestError(cbForStateGettingError); }

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

void cbForStateGettingError(u32 intType);

void stateReady();

void stateBusy(DVDCommandBlock *block);

void DVDReset(void);

void cbForStateCheckID3(u32 intType) {
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }
    if (intType & 1) {
        lbl_801A68F4 = 0;
        if (!CheckCancel(0)) {
            executing->state = 1;
            stateBusy(executing);
        }
    } else {
        stateGettingError();
    }
}
