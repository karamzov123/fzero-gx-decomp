#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>

enum OS_THREAD_STATE {
    OS_THREAD_STATE_NULL = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_RUNNING = 2,
    OS_THREAD_STATE_WAITING = 4,
    OS_THREAD_STATE_MORIBUND = 8,
};

// Hardware or OS state can change asynchronously.
extern volatile BOOL RunQueueHint; // fzgx-allow: S2 SDK asynchronous state

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

s32 OSSuspendThread(OSThread *thread) {
    BOOL enabled;
    s32 suspendCount;
    enabled = OSDisableInterrupts();
    suspendCount = thread->suspend++;
    if (suspendCount == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_RUNNING:
            RunQueueHint = 1;
            thread->state = OS_THREAD_STATE_READY;
            break;
        case OS_THREAD_STATE_READY:
            UnsetRun(thread);
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
            thread->priority = 32;
            do {
                OSThread *prev;
                prev = (thread->queue)->tail;
                if (prev == ((void *)0))
                    (thread->queue)->head = (thread);
                else
                    prev->link.next = (thread);
                (thread)->link.prev = prev;
                (thread)->link.next = ((void *)0);
                (thread->queue)->tail = (thread);
            } while (0);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        }
        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}
