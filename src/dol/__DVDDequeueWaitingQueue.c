#include "types.h"
#include <types.h>


/* --- dol/__DVDDequeueWaitingQueue.c --- */
typedef struct DVDCommandBlock {
    struct DVDCommandBlock *next;
    struct DVDCommandBlock *prev;
} DVDCommandBlock;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 interrupts);

u32 __DVDDequeueWaitingQueue(DVDCommandBlock *block) {
    u32 interrupts = OSDisableInterrupts();
    DVDCommandBlock *prev = block->prev;
    DVDCommandBlock *next = block->next;

    if (prev == NULL || next == NULL) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }

    prev->next = next;
    next->prev = prev;
    OSRestoreInterrupts(interrupts);
    return 1;
}
