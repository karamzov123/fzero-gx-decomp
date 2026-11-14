#include "types.h"

typedef struct DVDCommandBlock {
    struct DVDCommandBlock *next;
    struct DVDCommandBlock *prev;
} DVDCommandBlock;

extern DVDCommandBlock WaitingQueue[4];

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 interrupts);

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
