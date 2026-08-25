typedef int BOOL;
typedef unsigned short u16;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern int Reschedule;

typedef struct OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

void OSInitThreadQueue(OSThreadQueue *queue)
{
    queue->tail = 0;
    queue->head = 0;
}

#pragma push
#pragma force_active on

// provenance: original
void* OSGetCurrentThread(void)
{
    return *(void**)0x800000E4;
}

// provenance: original; T9 ternary shape
BOOL OSIsThreadTerminated(void* thread)
{
    u16 state = *(u16*)((char*)thread + 0x2C8);

    return (state == 8 || state == 0) ? 1 : 0;
}
#pragma pop

int OSDisableScheduler(void)
{
    int old;
    BOOL level = OSDisableInterrupts();
    old = Reschedule;
    Reschedule = old + 1;
    OSRestoreInterrupts(level);
    return old;
}

int OSEnableScheduler(void)
{
    int old;
    BOOL level = OSDisableInterrupts();
    old = Reschedule;
    Reschedule = old - 1;
    OSRestoreInterrupts(level);
    return old;
}
