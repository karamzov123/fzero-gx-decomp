#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include "sdk_addresses.h"

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

void OSWakeupThread(OSThreadQueue *queue);

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
