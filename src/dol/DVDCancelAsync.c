#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);

DVDLowCallback DVDLowClearCallback();

BOOL __DVDDequeueWaitingQueue(DVDCommandBlock *block);

extern DVDCommandBlock *executing;

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

extern vu32 ResumeFromHere;

extern DVDCommandBlock DummyCommandBlock;

void stateReady();

void cbForStateMotorStopped(u32 intType);

void cbForStateMotorStopped(u32 intType);

void stateReady();

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

extern u32 __DVDThreadQueue;
extern u32 OSSleepThread(u32);
extern u32 OSWakeupThread(u32);
void fn_80019C24(s32 result, DVDCommandBlock *block);

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
        OSSleepThread((u32)&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupt_state);
    return 0;
}

void fn_80019C24(s32 result, DVDCommandBlock *block) {
    OSWakeupThread((u32)&__DVDThreadQueue);
}

u32 fn_80019C48(void) {
    return 0x80000000;
}

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;


// Hardware or OS state can change asynchronously.
extern volatile BOOL PausingFlag; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile BOOL FatalErrorFlag; // fzgx-allow: S2 SDK asynchronous state



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