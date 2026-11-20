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

/* --- dol/ErrorCode2Num.c --- */
extern u32 lbl_80124110[18];

u8 ErrorCode2Num(u32 errorCode) {
    u32 i;
    for (i = 0; i < 18; i++) {
        if (errorCode == lbl_80124110[i]) {
            (void)0;
            return i;
        }
    }
    if (errorCode >= 0x100000 && errorCode <= 0x100008) {
        return 17;
    }
    return 29;
}
