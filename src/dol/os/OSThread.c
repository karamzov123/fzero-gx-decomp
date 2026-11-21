#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef volatile s32 vs32; /* fzgx-allow: S2 SDK state mutated by exception handlers */
typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);
typedef void *(*OSThreadStartFunction)(void *);

enum OS_THREAD_STATE {
    OS_THREAD_STATE_NULL = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_RUNNING = 2,
    OS_THREAD_STATE_WAITING = 4,
    OS_THREAD_STATE_MORIBUND = 8,
};

struct SDK_OSThread____bss_0 {
    OSThreadQueue sdk_RunQueue[32];
    unsigned char sdk_padding_256[792];
    OSThread sdk_DefaultThread;
    OSContext sdk_IdleContext;
};

extern vu32 RunQueueBits;
extern volatile BOOL RunQueueHint; /* fzgx-allow: S2 SDK asynchronous state */
extern vs32 Reschedule;
extern OSSwitchThreadCallback SwitchThreadCallback;
extern u8 _stack_addr[];
extern u8 _stack_end[];
extern struct SDK_OSThread____bss_0 RunQueue;
extern OSErrorHandler __OSErrorTable[17];
extern u32 lbl_801A6430;

OSThread *__OSCurrentThread : FZGX_ADDR___OSCurrentThread;
OSThreadQueue __OSActiveThreadQueue : FZGX_ADDR___OSActiveThreadQueue;
OSContext *__OSFPUContext : FZGX_ADDR___OSFPUContext;

void OSInitThreadQueue(OSThreadQueue *queue);
void UnsetRun(OSThread *thread);
OSPriority __OSGetEffectivePriority(OSThread *thread);
OSThread *SetEffectivePriority(OSThread *thread, OSPriority priority);
OSThread *SelectThread(BOOL yield);
void __OSReschedule(void);
void OSExitThread(void *val);
void OSWakeupThread(OSThreadQueue *queue);
u32 fn_8000BFC0(void);
OSContext *fn_8000BE5C(void);
void __OSUnlockAllMutex(OSThread *thread);
void OSLoadContext(OSContext *context);
u32 OSSaveContext(OSContext *context);
void OSSetCurrentContext(OSContext *context);
void OSClearContext(OSContext *context);
void OSInitContext(OSContext *context, u32 pc, u32 sp);
void __OSPromoteThread(OSThread *thread, OSPriority priority);

static inline void OSInitMutexQueue(OSMutexQueue *queue) {
    queue->head = queue->tail = 0;
}

static inline void InitThreadQueueInline(OSThreadQueue *queue) {
    queue->head = queue->tail = 0;
}

static inline void OSSetCurrentThread(OSThread *thread) {
    SwitchThreadCallback(__OSCurrentThread, thread);
    __OSCurrentThread = thread;
}

static inline OSThread *OSGetCurrentThread(void) {
    return __OSCurrentThread;
}

static inline void __OSSwitchThread(OSThread *nextThread) {
    OSSetCurrentThread(nextThread);
    OSSetCurrentContext(&nextThread->context);
    OSLoadContext(&nextThread->context);
}

static inline void SetRun(OSThread *thread) {
    thread->queue = &RunQueue.sdk_RunQueue[thread->priority];
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
    RunQueueBits |= 1u << (31 - thread->priority);
    RunQueueHint = 1;
}

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

static inline OSPriority __OSGetEffectivePriority_inline(OSThread *thread) {
    OSPriority priority;
    OSMutex *mutex;
    OSThread *blocked;
    priority = thread->base;
    for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
        blocked = mutex->queue.head;
        if (blocked && blocked->priority < priority) {
            priority = blocked->priority;
        }
    }
    return priority;
}

static inline void RescheduleInline(void) {
    if (!RunQueueHint) {
        return;
    }
    SelectThread(0);
}


void __OSThreadInit() {
    struct SDK_OSThread____bss_0 *sdk_storage____bss_0 = &RunQueue;

    OSThread *thread = &(sdk_storage____bss_0->sdk_DefaultThread);
    int prio;
    thread->state = OS_THREAD_STATE_RUNNING;
    thread->attr = 0x0001u;
    thread->priority = thread->base = 16;
    thread->suspend = 0;
    thread->val = (void *)-1;
    thread->mutex = ((void *)0);
    OSInitThreadQueue(&thread->queueJoin);
    OSInitMutexQueue(&RunQueue.sdk_DefaultThread.queueMutex);
    __OSFPUContext = &thread->context;
    OSClearContext(&thread->context);
    OSSetCurrentContext(&thread->context);
    RunQueue.sdk_DefaultThread.stackBase = (void *)_stack_addr;
    RunQueue.sdk_DefaultThread.stackEnd = (void *)_stack_end;
    *(RunQueue.sdk_DefaultThread.stackEnd) = 0xDEADBABE;
    OSSetCurrentThread(thread);
    OSClearStack(0);
    RunQueueBits = 0;
    RunQueueHint = 0;
    for (prio = 0; prio <= 31; ++prio) {
        OSInitThreadQueue(&(sdk_storage____bss_0->sdk_RunQueue)[prio]);
    }
    OSInitThreadQueue(&__OSActiveThreadQueue);
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
    OSClearContext(&(sdk_storage____bss_0->sdk_IdleContext));
    Reschedule = 0;
}

void OSInitThreadQueue(OSThreadQueue *queue) {
    queue->head = queue->tail = 0;
}

u32 fn_800102AC(void) {
    return *(u32 *)0x800000E4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

BOOL OSIsThreadTerminated(OSThread *thread) {
    return thread->state == 8 || thread->state == 0 ? 1 : 0;
}

s32 OSDisableScheduler(void) {
    BOOL enabled;
    s32 count;
    enabled = OSDisableInterrupts();
    count = Reschedule++;
    OSRestoreInterrupts(enabled);
    return count;
}

s32 OSEnableScheduler(void) {
    BOOL enabled;
    s32 count;
    enabled = OSDisableInterrupts();
    count = Reschedule--;
    OSRestoreInterrupts(enabled);
    return count;
}

void UnsetRun(OSThread *thread) {
    OSThreadQueue *queue;
    OSThread *next;
    OSThread *prev;
    queue = thread->queue;
    next = thread->link.next;
    prev = thread->link.prev;
    if (next == 0) {
        queue->tail = prev;
    } else {
        next->link.prev = prev;
    }
    if (prev == 0) {
        queue->head = next;
    } else {
        prev->link.next = next;
    }
    if (queue->head == 0) {
        RunQueueBits &= ~(1u << (31 - thread->priority));
    }
    thread->queue = 0;
}

OSPriority __OSGetEffectivePriority(OSThread *thread) {
    OSPriority priority;
    OSMutex *mutex;
    OSThread *blocked;
    priority = thread->base;
    for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
        blocked = mutex->queue.head;
        if (blocked && blocked->priority < priority) {
            priority = blocked->priority;
        }
    }
    return priority;
}

OSThread *SetEffectivePriority(OSThread *thread, OSPriority priority) {
    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        UnsetRun(thread);
        thread->priority = priority;
        SetRun(thread);
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
        thread->priority = priority;
        do {
            OSThread *prev, *next;
            for (next = (thread->queue)->head; next && next->priority <= thread->priority;
                 next = next->link.next)
                ;
            if (next == ((void *)0))
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
            else {
                (thread)->link.next = next;
                prev = next->link.prev;
                next->link.prev = (thread);
                (thread)->link.prev = prev;
                if (prev == ((void *)0))
                    (thread->queue)->head = (thread);
                else
                    prev->link.next = (thread);
            }
        } while (0);
        if (thread->mutex) {
            return thread->mutex->thread;
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = 1;
        thread->priority = priority;
        break;
    }
    return ((void *)0);
}

OSThread *SelectThread(BOOL yield) {
    struct SDK_OSThread____bss_0 *sdk_storage____bss_0 = &RunQueue;

    OSContext *currentContext;
    OSThread *currentThread;
    OSThread *nextThread;
    OSPriority priority;
    OSThreadQueue *queue;
    if (0 < Reschedule) {
        return 0;
    }
    currentContext = fn_8000BE5C();
    currentThread = OSGetCurrentThread();
    if (currentContext != &currentThread->context) {
        return 0;
    }
    if (currentThread) {
        if (currentThread->state == OS_THREAD_STATE_RUNNING) {
            if (!yield) {
                priority = __cntlzw(RunQueueBits);
                if (currentThread->priority <= priority) {
                    return 0;
                }
            }
            currentThread->state = OS_THREAD_STATE_READY;
            currentThread->queue = &(sdk_storage____bss_0->sdk_RunQueue)[currentThread->priority];
            do {
                OSThread *prev;
                prev = (currentThread->queue)->tail;
                if (prev == ((void *)0))
                    (currentThread->queue)->head = (currentThread);
                else
                    prev->link.next = (currentThread);
                (currentThread)->link.prev = prev;
                (currentThread)->link.next = ((void *)0);
                (currentThread->queue)->tail = (currentThread);
            } while (0);
            RunQueueBits |= 1u << (31 - currentThread->priority);
            RunQueueHint = 1;
        }
        if (!(currentThread->context.state & 0x02u) && OSSaveContext(&currentThread->context)) {
            return 0;
        }
    }
    if (RunQueueBits == 0) {
        SwitchThreadCallback(__OSCurrentThread, 0);
        __OSCurrentThread = 0;
        OSSetCurrentContext(&(sdk_storage____bss_0->sdk_IdleContext));
        do {
            OSEnableInterrupts();
            while (RunQueueBits == 0)
                ;
            OSDisableInterrupts();
        } while (RunQueueBits == 0);
        OSClearContext(&(sdk_storage____bss_0->sdk_IdleContext));
    }
    RunQueueHint = 0;
    priority = __cntlzw(RunQueueBits);
    queue = &(sdk_storage____bss_0->sdk_RunQueue)[priority];
    do {
        OSThread *__next;
        (nextThread) = (queue)->head;
        __next = (nextThread)->link.next;
        if (__next == ((void *)0))
            (queue)->tail = ((void *)0);
        else
            __next->link.prev = ((void *)0);
        (queue)->head = __next;
    } while (0);
    if (queue->head == 0) {
        RunQueueBits &= ~(1u << (31 - priority));
    }
    nextThread->queue = ((void *)0);
    nextThread->state = OS_THREAD_STATE_RUNNING;
    __OSSwitchThread(nextThread);
    return nextThread;
}

void __OSReschedule(void) {
    if (!RunQueueHint) {
        return;
    }
    SelectThread(0);
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
    InitThreadQueueInline(&thread->queueJoin);
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

void OSExitThread(void *val) {
    OSThread *thread;
    BOOL enable;
    enable = OSDisableInterrupts();
    thread = __OSCurrentThread;
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
        thread->state = OS_THREAD_STATE_NULL;
    } else {
        thread->state = OS_THREAD_STATE_MORIBUND;
        thread->val = val;
    }
    __OSUnlockAllMutex(thread);
    OSWakeupThread(&thread->queueJoin);
    RunQueueHint = 1;
    if (RunQueueHint != 0) {
        SelectThread(0);
    }
    OSRestoreInterrupts(enable);
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
    RescheduleInline();
    OSRestoreInterrupts(enabled);
    return;
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
        RescheduleInline();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
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
        RescheduleInline();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

void OSSleepThread(OSThreadQueue *queue) {
    BOOL enabled;
    OSThread *currentThread;
    enabled = OSDisableInterrupts();
    currentThread = OSGetCurrentThread();
    currentThread->state = OS_THREAD_STATE_WAITING;
    currentThread->queue = queue;
    do {
        OSThread *prev, *next;
        for (next = (queue)->head; next && next->priority <= currentThread->priority;
             next = next->link.next)
            ;
        if (next == ((void *)0))
            do {
                OSThread *prev;
                prev = (queue)->tail;
                if (prev == ((void *)0))
                    (queue)->head = (currentThread);
                else
                    prev->link.next = (currentThread);
                (currentThread)->link.prev = prev;
                (currentThread)->link.next = ((void *)0);
                (queue)->tail = (currentThread);
            } while (0);
        else {
            (currentThread)->link.next = next;
            prev = next->link.prev;
            next->link.prev = (currentThread);
            (currentThread)->link.prev = prev;
            if (prev == ((void *)0))
                (queue)->head = (currentThread);
            else
                prev->link.next = (currentThread);
        }
    } while (0);
    RunQueueHint = 1;
    RescheduleInline();
    OSRestoreInterrupts(enabled);
}

void OSWakeupThread(OSThreadQueue *queue) {
    BOOL enabled;
    OSThread *thread;
    enabled = OSDisableInterrupts();
    while (queue->head) {
        do {
            OSThread *__next;
            (thread) = (queue)->head;
            __next = (thread)->link.next;
            if (__next == ((void *)0))
                (queue)->tail = ((void *)0);
            else
                __next->link.prev = ((void *)0);
            (queue)->head = __next;
        } while (0);
        thread->state = OS_THREAD_STATE_READY;
        if (!(0 < thread->suspend)) {
            SetRun(thread);
        }
    }
    RescheduleInline();
    OSRestoreInterrupts(enabled);
}

BOOL OSSetThreadPriority(OSThread *thread, OSPriority priority) {
    BOOL enabled;
    if (priority < 0 || priority > 31) {
        return 0;
    }
    enabled = OSDisableInterrupts();
    if (thread->base != priority) {
        thread->base = priority;
        UpdatePriority(thread);
        RescheduleInline();
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

OSPriority fn_80011358(OSThread *thread) {
    return thread->base;
}

void OSClearStack(u8 val) {
    register u32 sp;
    register u32 *p;
    register u32 pattern;
    pattern = ((u32)val << 24) | ((u32)val << 16) | ((u32)val << 8) | (u32)val;
    sp = fn_8000BFC0();
    for (p = __OSCurrentThread->stackEnd + 1; p < (u32 *)sp; ++p) {
        *p = pattern;
    }
}
