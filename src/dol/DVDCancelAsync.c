#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>

typedef void (*DVDLowCallback)(u32 intType);

DVDLowCallback DVDLowClearCallback();

BOOL __DVDDequeueWaitingQueue(DVDCommandBlock *block);

extern DVDCommandBlock *executing_801A68C0;

extern vu32 lbl_801A68E0;

extern DVDCBCallback lbl_801A68E4;

extern vu32 ResumeFromHere_801A68E8;

extern DVDCommandBlock DummyCommandBlock_8015CE80;

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
            ResumeFromHere_801A68E8 = 3;
        if (block->state == 5)
            ResumeFromHere_801A68E8 = 4;
        if (block->state == 6)
            ResumeFromHere_801A68E8 = 1;
        if (block->state == 11)
            ResumeFromHere_801A68E8 = 2;
        if (block->state == 7)
            ResumeFromHere_801A68E8 = 7;
        executing_801A68C0 = &DummyCommandBlock_8015CE80;
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
