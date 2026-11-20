#include "types.h"


/* --- dol/fn_80021B20.c --- */
extern u32 lbl_801A6B24;

void fn_80021B20(void) {
    lbl_801A6B24 = 1;
}

/* --- dol/fn_80021B2C.c --- */
typedef signed long long OSTime;

typedef struct DSPTaskInfo DSPTaskInfo;

typedef void (*DSPCallback)(DSPTaskInfo *task);

struct DSPTaskInfo {
// Hardware or OS state can change asynchronously.
    volatile unsigned long state;
// Hardware or OS state can change asynchronously.
    volatile unsigned long priority;
// Hardware or OS state can change asynchronously.
    volatile unsigned long flags;
    unsigned short *iramMemoryAddress;
    unsigned long iramLength;
    unsigned long iramAddress;
    unsigned short *dramMemoryAddress;
    unsigned long dramLength;
    unsigned long dramAddress;
    unsigned short initVector;
    unsigned short resumeVector;
    DSPCallback initCallback;
    DSPCallback resumeCallback;
    DSPCallback doneCallback;
    DSPCallback requestCallback;
    struct DSPTaskInfo *next;
    struct DSPTaskInfo *previous;
    OSTime contextTime;
    OSTime taskTime;
};

void fn_80021B2C(DSPTaskInfo *task);

void fn_80021930(u32 less_dsp_cycles);

OSTime OSGetTime(void);

// Hardware or OS state can change asynchronously.
extern volatile u32 lbl_801A6B14;

// Hardware or OS state can change asynchronously.
extern volatile OSTime lbl_801A6B18;

void fn_80021930(u32 lessDspCycles);

void fn_80021B2C(DSPTaskInfo *task) {
    if (lbl_801A6B14 == 2) {
        lbl_801A6B14 = 0;
        fn_80021930((u32)(OSGetTime() - lbl_801A6B18) / 4);
        return;
    }
    lbl_801A6B14 = 1;
}

/* --- dol/cbForCancelAllSync.c --- */
extern u32 OSWakeupThread(u32);
extern u32 lbl_801A6B28;
extern u32 lbl_801A6B30;

void cbForCancelAllSync(void) {
    lbl_801A6B28 = 1;
    OSWakeupThread((u32)&lbl_801A6B30);
}
