
#include "types.h"

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    f64 psf[32];
} OSContext;

typedef s32 OSPriority;

struct OSThread;

struct OSMutex;

struct OSMutexQueue;

typedef struct OSThreadQueue {
    struct OSThread *head;
    struct OSThread *tail;
} OSThreadQueue;

typedef struct OSThreadLink {
    struct OSThread *next;
    struct OSThread *prev;
} OSThreadLink;

typedef struct OSMutexQueue {
    struct OSMutex *head;
    struct OSMutex *tail;
} OSMutexQueue;

typedef struct OSMutexLink {
    struct OSMutex *next;
    struct OSMutex *prev;
} OSMutexLink;

typedef struct OSThread {
    struct OSContext context;
    u16 state;
    u16 attr;
    s32 suspend;
    OSPriority priority;
    OSPriority base;
    void *val;
    struct OSThreadQueue *queue;
    struct OSThreadLink link;
    struct OSThreadQueue queueJoin;
    struct OSMutex *mutex;
    struct OSMutexQueue queueMutex;
    struct OSThreadLink linkActive;
    u8 *stackBase;
    u32 *stackEnd;
} OSThread;

typedef struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
} OSMutex;

struct OSContext;

long OSResumeThread(OSThread *thread);

void (*DVDLowClearCallback())(u32);

BOOL OSDisableInterrupts(void);

BOOL OSRestoreInterrupts(BOOL level);

long __OSGetEffectivePriority(struct OSThread *thread);

void __OSReschedule(void);

extern OSThreadQueue RunQueue[32];

// Hardware or OS state can change asynchronously.
extern volatile unsigned long RunQueueBits;

// Hardware or OS state can change asynchronously.
extern volatile int RunQueueHint;

static void SetRun(OSThread *thread);

OSThread *SetEffectivePriority(OSThread *thread, long priority);

static void UpdatePriority(OSThread *thread);

OSThread *SelectThread(int yield);

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

extern long __OSGetEffectivePriority(OSThread *thread);
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

static inline void UpdatePriority(OSThread *thread) {
    long priority;
    while (1) {
        if (thread->suspend > 0) {
            break;
        }
        priority = __OSGetEffectivePriority(thread);
        if (thread->priority == priority) {
            break;
        }
        thread = SetEffectivePriority(thread, priority);
        if (thread == 0) {
            break;
        }
    }
}

static inline void __OSReschedule(void) {
    if (RunQueueHint != 0) {
        SelectThread(0);
    }
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
