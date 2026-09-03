/* hard2 candidate: adapted from dolsdk2001 dvdqueue.c:13 */
typedef int BOOL;
typedef unsigned int u32;
typedef signed int s32;
typedef struct DVDCommandBlock DVDCommandBlock;
struct DVDCommandBlock {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
};
typedef struct {
    DVDCommandBlock* next;
    DVDCommandBlock* prev;
} WaitingQueueElem;

#pragma force_active on

extern WaitingQueueElem WaitingQueue[4];
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);

void __DVDClearWaitingQueue(void) {
    // provenance: dolsdk2001:src/dvd/dvdqueue.c:13
    unsigned int i;
    DVDCommandBlock *q;

    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock *)&WaitingQueue[i];
        q->next = q;
        q->prev = q;
    }
}

// provenance: melee:src/dolphin/dvd/dvdqueue.c
BOOL __DVDPushWaitingQueue(int prio, DVDCommandBlock* block) {
    BOOL enabled = OSDisableInterrupts();
    DVDCommandBlock* q = (DVDCommandBlock*)&WaitingQueue[prio];

    q->prev->next = block;
    block->prev = q->prev;
    block->next = q;
    q->prev = block;
    OSRestoreInterrupts(enabled);
    return 1;
}

static inline DVDCommandBlock* PopWaitingQueuePrio(s32 prio) {
    DVDCommandBlock* tmp;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    q = (DVDCommandBlock*)&WaitingQueue[prio];
    tmp = q->next;
    q->next = tmp->next;
    tmp->next->prev = q;
    OSRestoreInterrupts(enabled);
    tmp->next = 0;
    tmp->prev = 0;
    return tmp;
}

// provenance: melee:src/dolphin/dvd/dvdqueue.c
DVDCommandBlock* __DVDPopWaitingQueue(void) {
    u32 i;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return PopWaitingQueuePrio(i);
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

// provenance: melee:src/dolphin/dvd/dvdqueue.c
BOOL __DVDCheckWaitingQueue(void) {
    u32 i;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

// provenance: melee:src/dolphin/dvd/dvdqueue.c
BOOL fn_80019FFC(DVDCommandBlock* block) {
    BOOL enabled = OSDisableInterrupts();
    DVDCommandBlock* prev = block->prev;
    DVDCommandBlock* next = block->next;

    if (prev == 0 || next == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    prev->next = next;
    next->prev = prev;
    OSRestoreInterrupts(enabled);
    return 1;
}
