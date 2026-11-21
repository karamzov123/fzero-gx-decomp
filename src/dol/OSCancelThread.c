#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include "sdk_addresses.h"
#include "types.h"

enum OS_THREAD_STATE {
    OS_THREAD_STATE_NULL = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_RUNNING = 2,
    OS_THREAD_STATE_WAITING = 4,
    OS_THREAD_STATE_MORIBUND = 8,
};

void OSWakeupThread(OSThreadQueue *queue);

// Hardware or OS state can change asynchronously.
extern volatile BOOL RunQueueHint; // fzgx-allow: S2 SDK asynchronous state

OSThreadQueue __OSActiveThreadQueue : FZGX_ADDR___OSActiveThreadQueue;

void UnsetRun(OSThread *thread);

OSPriority __OSGetEffectivePriority(OSThread *thread);

OSThread *SetEffectivePriority(OSThread *thread, OSPriority priority);

static inline void UpdatePriority(OSThread *thread) {
    OSPriority priority;
    do {
        if (0 < thread->suspend) {
            break;
        }
        priority = __OSGetEffectivePriority(thread);
        if (thread->priority == priority) {
            break;
        }
        thread = SetEffectivePriority(thread, priority);
    } while (thread);
}

OSThread *SelectThread(BOOL yield);

static inline void __OSReschedule() {
    if (!RunQueueHint) {
        return;
    }
    SelectThread(0);
}

void OSCancelThread(OSThread *thread) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        if (!(0 < thread->suspend)) {
            UnsetRun(thread);
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = 1;
        break;
    case OS_THREAD_STATE_WAITING:
        do {
            OSThread *next, *prev;
            next = (thread)->link.next;
            prev = (thread)->link.prev;
            if (next == ((void *)0))
                (thread->queue)->tail = prev;
            else
                next->link.prev = prev;
            if (prev == ((void *)0))
                (thread->queue)->head = next;
            else
                prev->link.next = next;
        } while (0);
        thread->queue = ((void *)0);
        if (!(0 < thread->suspend) && thread->mutex) {
            UpdatePriority(thread->mutex->thread);
        }
        break;
    default:
        OSRestoreInterrupts(enabled);
        return;
    }
    OSClearContext(&thread->context);
    if (thread->attr & 0x0001u) {
        do {
            OSThread *next, *prev;
            next = (thread)->linkActive.next;
            prev = (thread)->linkActive.prev;
            if (next == ((void *)0))
                (&__OSActiveThreadQueue)->tail = prev;
            else
                next->linkActive.prev = prev;
            if (prev == ((void *)0))
                (&__OSActiveThreadQueue)->head = next;
            else
                prev->linkActive.next = next;
        } while (0);
        thread->state = 0;
    } else {
        thread->state = OS_THREAD_STATE_MORIBUND;
    }
    __OSUnlockAllMutex(thread);
    OSWakeupThread(&thread->queueJoin);
    __OSReschedule();
    OSRestoreInterrupts(enabled);
    return;
}

struct OSThread;

struct OSMutex;

struct OSMutexQueue;

struct OSContext;

long OSResumeThread(OSThread *thread);

void (*DVDLowClearCallback())(u32);

BOOL OSDisableInterrupts(void);

BOOL OSRestoreInterrupts(BOOL level);

void __OSReschedule(void);

extern OSThreadQueue RunQueue[32];

// Hardware or OS state can change asynchronously.
extern volatile unsigned long RunQueueBits;

// Hardware or OS state can change asynchronously.
extern volatile int RunQueueHint;

static void SetRun(OSThread *thread);

static void UpdatePriority(OSThread *thread);

static inline void SetRun(OSThread *thread) {
    (void)0;
    (void)0;
    (void)0;
    thread->queue = &RunQueue[thread->priority];
    do {
        OSThread *__prev = (thread->queue)->tail;
        if (__prev == ((void *)0)) {
            (thread->queue)->head = (thread);
        } else {
            __prev->link.next = (thread);
        }
        (thread)->link.prev = __prev;
        (thread)->link.next = 0;
        (thread->queue)->tail = (thread);
    } while (0);
    ;
    RunQueueBits |= 1 << (0x1F - thread->priority);
    RunQueueHint = 1;
}

static inline long __OSGetEffectivePriority_inline(OSThread *thread) {
    long priority = thread->base;
    struct OSMutex *mutex;
    for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
        OSThread *blocked = mutex->queue.head;
        if (blocked && blocked->priority < priority) {
            priority = blocked->priority;
        }
    }
    return priority;
}

long OSResumeThread(OSThread *thread) {
    int enabled = OSDisableInterrupts();
    long suspendCount;
    (void)0;
    (void)0;
    suspendCount = thread->suspend--;
    if (thread->suspend < 0) {
        thread->suspend = 0;
    } else if (thread->suspend == 0) {
        switch (thread->state) {
        case 1:
            thread->priority = __OSGetEffectivePriority_inline(thread);
            SetRun(thread);
            break;
        case 4:
            (void)0;
            do {
                OSThread *__next = (thread)->link.next;
                OSThread *__prev = (thread)->link.prev;
                if (__next == ((void *)0)) {
                    (thread->queue)->tail = __prev;
                } else {
                    __next->link.prev = __prev;
                }
                if (__prev == ((void *)0)) {
                    (thread->queue)->head = __next;
                } else {
                    __prev->link.next = __next;
                }
            } while (0);
            ;
            thread->priority = __OSGetEffectivePriority_inline(thread);
            do {
                OSThread *__prev;
                OSThread *__next;
                for (__next = (thread->queue)->head;
                     __next && (__next->priority <= (thread)->priority); __next = __next->link.next)
                    ;
                if (__next == ((void *)0)) {
                    do {
                        OSThread *__prev = (thread->queue)->tail;
                        if (__prev == ((void *)0)) {
                            (thread->queue)->head = (thread);
                        } else {
                            __prev->link.next = (thread);
                        }
                        (thread)->link.prev = __prev;
                        (thread)->link.next = 0;
                        (thread->queue)->tail = (thread);
                    } while (0);
                    ;
                } else {
                    (thread)->link.next = __next;
                    __prev = __next->link.prev;
                    __next->link.prev = (thread);
                    (thread)->link.prev = __prev;
                    if (__prev == ((void *)0)) {
                        (thread->queue)->head = (thread);
                    } else {
                        __prev->link.next = (thread);
                    }
                }
            } while (0);
            ;
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
        }
        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}
