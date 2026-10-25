#include "types.h"

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

extern s32 autoInvalidation_801A647C;
extern DVDExecuting *executing_801A68C0;
extern s32 PauseFlag_801A68CC;

extern void DCInvalidateRange(void *address, u32 length);
extern u32 OSDisableInterrupts(void);
extern u32 __DVDPushWaitingQueue(u32 prio, DVDCommandBlock *block);
extern void stateReady(void);
extern void OSRestoreInterrupts(u32 interrupts);

u32 DVDReadAbsAsyncForBS(DVDCommandBlock *block, void *address, u32 length, u32 unk10,
                void *callback) {
    u32 result;
    u32 interrupts;
    u64 alignment;

    block->state = 4;
    block->address = address;
    block->length = length;
    block->zero10 = unk10;
    block->unk20 = 0;
    block->callback = callback;

    if (autoInvalidation_801A647C != 0) {
        if (block->state == 1 ||
            (block->state - 4) <= 1 ||
            block->state == 0xe) {
            DCInvalidateRange(block->address, block->length);
        }
    }

    interrupts = OSDisableInterrupts();
    block->status = 2;
    result = __DVDPushWaitingQueue(2, block);

    if (executing_801A68C0 == NULL && PauseFlag_801A68CC == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);
    return result;
}
