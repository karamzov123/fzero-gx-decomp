#include "types.h"


/* --- dol/__DVDPushWaitingQueue.c --- */
typedef struct DVDCommandBlock {
    struct DVDCommandBlock *next;
    struct DVDCommandBlock *prev;
} DVDCommandBlock;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern DVDCommandBlock WaitingQueue[];

u32 __DVDPushWaitingQueue(u32 index, DVDCommandBlock *block) {
    u32 interrupts;
    DVDCommandBlock *queue;

    interrupts = OSDisableInterrupts();
    queue = &WaitingQueue[index];
    queue->prev->next = block;
    block->prev = queue->prev;
    block->next = queue;
    queue->prev = block;
    OSRestoreInterrupts(interrupts);
    return 1;
}

/* --- dol/__DVDPopWaitingQueue.c --- */
extern DVDCommandBlock WaitingQueue[4];


DVDCommandBlock *__DVDPopWaitingQueue(void) {
    u32 interrupts;
    s32 i;
    DVDCommandBlock *block;

    interrupts = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        if (WaitingQueue[i].next != &WaitingQueue[i]) {
            OSRestoreInterrupts(interrupts);
            interrupts = OSDisableInterrupts();
            block = WaitingQueue[i].next;
            WaitingQueue[i].next = block->next;
            block->next->prev = &WaitingQueue[i];
            OSRestoreInterrupts(interrupts);
            block->next = NULL;
            block->prev = NULL;
            return block;
        }
    }
    OSRestoreInterrupts(interrupts);
    return NULL;
}
