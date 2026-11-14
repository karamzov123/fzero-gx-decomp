#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSInterrupt.h>

typedef struct {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
} DVDQueue;

extern DVDQueue WaitingQueue[4];

BOOL __DVDCheckWaitingQueue(void) {
    u32 i;
    BOOL enabled;
    DVDCommandBlock *q;
    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock *)&(WaitingQueue[i]);
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}
