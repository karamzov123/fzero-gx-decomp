#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef s32 vs32;

typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

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

void OSInitThreadQueue(OSThreadQueue *queue);

extern vu32 RunQueueBits;

extern volatile BOOL RunQueueHint; // fzgx-allow: S2 SDK asynchronous state

extern vs32 Reschedule;

extern OSSwitchThreadCallback SwitchThreadCallback;

OSThread *__OSCurrentThread : FZGX_ADDR___OSCurrentThread;

OSThreadQueue __OSActiveThreadQueue : FZGX_ADDR___OSActiveThreadQueue;

// fzgx-allow: S2 SDK asynchronous state
volatile OSContext *__OSFPUContext : FZGX_ADDR___OSFPUContext;

extern u8 _stack_addr[];

extern u8 _stack_end[];

extern struct SDK_OSThread____bss_0 RunQueue;

static inline void OSInitMutexQueue(OSMutexQueue *queue) {
    queue->head = queue->tail = ((void *)0);
}

static inline void OSSetCurrentThread(OSThread *thread) {
    SwitchThreadCallback(__OSCurrentThread, thread);
    __OSCurrentThread = thread;
}

void OSInitThreadQueue(OSThreadQueue *queue);

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
