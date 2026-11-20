#include "types.h"
#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"


/* --- dol/DVDReadDiskID.c --- */
typedef struct DVDCommandBlock {
    u8 _pad00[0x8];
    u32 state;
    u32 status;
    u32 zero10;
    u32 length;
    void *address;
    u8 _pad1c[0x4];
    u32 unk20;
    u8 _pad24[0x4];
    void *callback;
} DVDCommandBlock;

typedef struct DVDExecuting {
    u8 _pad[1];
} DVDExecuting;

extern s32 autoInvalidation;
extern DVDExecuting *executing;
extern s32 PauseFlag;

extern void DCInvalidateRange(void *address, u32 length);
extern u32 OSDisableInterrupts(void);
extern u32 __DVDPushWaitingQueue(u32 prio, DVDCommandBlock *block);
extern void stateReady(void);
extern void OSRestoreInterrupts(u32 interrupts);

u32 DVDReadDiskID(DVDCommandBlock *block, void *address, void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    alignment = 0;
    block->state = 5;
    block->address = address;
    block->length = 0x20;
    block->zero10 = 0;
    block->unk20 = 0;
    block->callback = callback;

    if (autoInvalidation != 0) {
        if (block->state == 1 ||
            (block->state - 4) <= 1 ||
            block->state == 0xe) {
            DCInvalidateRange(block->address, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->status = 2;
    result = __DVDPushWaitingQueue(2, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result + (u32)alignment;
}

/* --- dol/DVDCancelStreamAsync.c --- */
u32 DVDCancelStreamAsync(DVDCommandBlock *block, void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    block->state = 7;
    block->callback = callback;

    if (autoInvalidation != 0) {
        if (block->state == 1 ||
            (block->state - 4) <= 1 ||
            block->state == 0xe) {
            DCInvalidateRange(block->address, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->status = 2;
    result = __DVDPushWaitingQueue(1, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result;
}

/* --- dol/DVDInquiryAsync.c --- */
/* --- dol/DVDInquiryAsync.c --- */




u32 DVDInquiryAsync(DVDCommandBlock *block, void *address, void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    alignment = 0;
    block->state = 0xe;
    block->address = address;
    block->length = 0x20;
    block->unk20 = 0;
    block->callback = callback;

    if (autoInvalidation != 0) {
        if (block->state == 1 ||
            (block->state - 4) <= 1 ||
            block->state == 0xe) {
            DCInvalidateRange(block->address, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->status = 2;
    result = __DVDPushWaitingQueue(2, block);

    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result + (u32)alignment;
}

/* --- dol/DVDReset.c --- */
void DVDLowReset();

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern vu32 ResumeFromHere;

// Hardware or OS state can change asynchronously.
extern volatile BOOL ResetRequired; // fzgx-allow: S2 SDK asynchronous state

void DVDReset(void) {
    DVDLowReset();
    __DIRegs[0] = 0x2a;
    __DIRegs[1] = __DIRegs[1];
    ResetRequired = 0;
    ResumeFromHere = 0;
}
