#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>

void DVDPause();

void DVDResume();

BOOL DVDCancelAsync(DVDCommandBlock *block, DVDCBCallback callback);

BOOL DVDCancelAllAsync(DVDCBCallback callback);

void __DVDClearWaitingQueue();

DVDCommandBlock *__DVDPopWaitingQueue();

DVDCommandBlock *__DVDPopWaitingQueue();

extern DVDCommandBlock *executing;

// Hardware or OS state can change asynchronously.
extern volatile BOOL PauseFlag; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile BOOL PausingFlag; // fzgx-allow: S2 SDK asynchronous state

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

void stateReady();

void stateReady();

static inline void DVDPause(void) {
    BOOL level;
    level = OSDisableInterrupts();
    PauseFlag = 1;
    if (executing == (DVDCommandBlock *)0) {
        PausingFlag = 1;
    }
    OSRestoreInterrupts(level);
}

static inline void DVDResume(void) {
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
    DVDResume();
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
