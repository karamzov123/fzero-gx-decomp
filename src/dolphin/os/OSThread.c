typedef int BOOL;

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

asm void fn_800102AC(void)
{
    nofralloc
    lis     r3, 0x8000
    lwz     r3, 0xE4(r3)
    blr
}

asm BOOL fn_800102B8(void *param1)
{
    nofralloc
    lhz     r3, 0x2C8(r3)
    li      r0, 1
    cmplwi  r3, 8
    beq     _true
    cmplwi  r3, 0
    beq     _true
    li      r0, 0
_true:
    cmpwi   r0, 0
    beq     _false
    li      r3, 1
    blr
_false:
    li      r3, 0
    blr
}

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
