#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include "sdk_addresses.h"


/* --- dol/__OSReschedule.c --- */
extern u32 RunQueueHint;
extern u32 SelectThread(u32);

void __OSReschedule(void) {
    if ((s32)RunQueueHint != 0) {
    SelectThread(0);
    }
}

/* --- dol/OSCreateThread.c --- */
typedef void *(*OSThreadStartFunction)(void *);

enum OS_THREAD_STATE {
    OS_THREAD_STATE_NULL = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_RUNNING = 2,
    OS_THREAD_STATE_WAITING = 4,
    OS_THREAD_STATE_MORIBUND = 8,
};

extern OSErrorHandler __OSErrorTable[(16 + 1)];

extern u32 lbl_801A6430;

void OSInitThreadQueue(OSThreadQueue *queue);

void OSExitThread(void *val);

OSThreadQueue __OSActiveThreadQueue : FZGX_ADDR___OSActiveThreadQueue;

static inline void OSInitMutexQueue(OSMutexQueue *queue) {
    queue->head = queue->tail = ((void *)0);
}

static inline void OSInitThreadQueue(OSThreadQueue *queue) {
    queue->head = queue->tail = ((void *)0);
}

BOOL OSCreateThread(OSThread *thread, OSThreadStartFunction func, void *param, void *stack,
                 u32 stackSize, OSPriority priority, u16 attr) {
    BOOL enable;
    u32 stackThing;
    int i;
    u32 tmp[2];
    if (priority < 0 || priority > 31) {
        return 0;
    }
    stackThing = ((u32)stack & 0xFFFFFFF8);
    thread->state = OS_THREAD_STATE_READY;
    thread->attr = attr & 0x0001u;
    thread->base = priority;
    thread->priority = priority;
    thread->suspend = 1;
    thread->val = (void *)-1;
    thread->mutex = 0;
    OSInitThreadQueue(&thread->queueJoin);
    OSInitMutexQueue(&thread->queueMutex);
    *(u32 *)(stackThing - 8) = 0;
    *(u32 *)(stackThing - 4) = 0;
    OSInitContext(&thread->context, (u32)func, (u32)(stackThing - 8));
    thread->context.lr = (u32)&OSExitThread;
    thread->context.gpr[3] = (u32)param;
    thread->stackBase = stack;
    thread->stackEnd = (u32 *)((u32)stack - stackSize);
    *(thread->stackEnd) = 0xDEADBABE;
    thread->error = 0;
    thread->specific[0] = 0;
    thread->specific[1] = 0;
    enable = OSDisableInterrupts();
    if (__OSErrorTable[16] != 0) {
        thread->context.srr1 |= 0x900;
        thread->context.state |= 0x01u;
        thread->context.fpscr = (lbl_801A6430 & 0xF8) | 0x4;
        for (i = 0; i < 32; i++) {
            *(u64 *)&thread->context.fpr[i] = -1;
            *(u64 *)&thread->context.psf[i] = -1;
        }
    }
    do {
        OSThread *prev;
        prev = (&__OSActiveThreadQueue)->tail;
        if (prev == ((void *)0))
            (&__OSActiveThreadQueue)->head = (thread);
        else
            prev->linkActive.next = (thread);
        (thread)->linkActive.prev = prev;
        (thread)->linkActive.next = ((void *)0);
        (&__OSActiveThreadQueue)->tail = (thread);
    } while (0);
    OSRestoreInterrupts(enable);
    return 1;
}
