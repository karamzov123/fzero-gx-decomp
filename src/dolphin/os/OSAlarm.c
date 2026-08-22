typedef int BOOL;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define NULL ((void*) 0)

typedef struct OSContext {
    u64 fields[0x59];
} OSContext;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern s64 __OSGetSystemTime(void);
extern void PPCMtdec(s32 value);
extern void OSLoadContext(OSContext* context);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void __OSReschedule(void);
extern s64 __OSTimeToSystemTime(s64 ticks);
extern void* __OSGetExceptionHandler(s32 exception);
extern void* __OSSetExceptionHandler(s32 exception, void* handler);

typedef void (*OSAlarmHandler)(struct OSAlarm* alarm, OSContext* context);

typedef struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    s64 fire;
    struct OSAlarm* prev;
    struct OSAlarm* next;
    s64 period;
    s64 start;
} OSAlarm;

struct AlarmQueueStruct {
    OSAlarm* head;
    OSAlarm* tail;
};

extern struct AlarmQueueStruct AlarmQueue;

static void SetTimer(OSAlarm* alarm);
static asm void DecrementerExceptionHandler(register s32 exception,
                                           register OSContext* context);

void OSInitAlarm(void)
{
    if (__OSGetExceptionHandler(8) != DecrementerExceptionHandler) {
        AlarmQueue.head = AlarmQueue.tail = NULL;
        __OSSetExceptionHandler(8, DecrementerExceptionHandler);
    }
}

void OSCreateAlarm(OSAlarm* alarm)
{
    alarm->handler = 0;
    alarm->tag = 0;
}

static __inline void SetTimer(OSAlarm* alarm)
{
    s64 delta = alarm->fire - __OSGetSystemTime();

    if (delta < 0) {
        PPCMtdec(0);
    } else if (delta < 0x80000000LL) {
        PPCMtdec((u32) delta);
    } else {
        PPCMtdec(0x7fffffff);
    }
}

static void InsertAlarm(OSAlarm* alarm, s64 fire, OSAlarmHandler handler)
{
    OSAlarm* next;
    OSAlarm* prev;

    if (0 < alarm->period) {
        s64 time = __OSGetSystemTime();

        fire = alarm->start;
        if (alarm->start < time) {
            fire += alarm->period * ((time - alarm->start) / alarm->period + 1);
        }
    }

    alarm->handler = handler;
    alarm->fire = fire;

    for (next = AlarmQueue.head; next; next = next->next) {
        if (next->fire <= fire) {
            continue;
        }

        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;

        if (prev) {
            prev->next = alarm;
        } else {
            AlarmQueue.head = alarm;
            SetTimer(alarm);
        }

        return;
    }

    alarm->next = 0;
    prev = AlarmQueue.tail;
    AlarmQueue.tail = alarm;
    alarm->prev = prev;

    if (prev) {
        prev->next = alarm;
    } else {
        AlarmQueue.head = AlarmQueue.tail = alarm;
        SetTimer(alarm);
    }
}

void OSSetAlarm(OSAlarm* alarm, s64 tick, OSAlarmHandler handler)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    alarm->period = 0;
    InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);
    OSRestoreInterrupts(enabled);
}

void OSSetPeriodicAlarm(OSAlarm* alarm, s64 start, s64 period,
                        OSAlarmHandler handler)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = __OSTimeToSystemTime(start);
    InsertAlarm(alarm, 0, handler);
    OSRestoreInterrupts(enabled);
}

void OSCancelAlarm(OSAlarm* alarm)
{
    OSAlarm* next;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (alarm->handler == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;
    if (next == 0) {
        AlarmQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }
    if (alarm->prev) {
        alarm->prev->next = next;
    } else {
        AlarmQueue.head = next;
        if (next) {
            SetTimer(next);
        }
    }
    alarm->handler = 0;
    OSRestoreInterrupts(enabled);
}

static void DecrementerExceptionCallback(register s32 exception,
                                         register OSContext* context)
{
    OSAlarm* alarm;
    OSAlarm* next;
    OSAlarmHandler handler;
    s64 time;
    OSContext exceptionContext;

    time = __OSGetSystemTime();
    alarm = AlarmQueue.head;
    if (alarm == 0) {
        OSLoadContext(context);
    }

    if (time < alarm->fire) {
        SetTimer(alarm);
        OSLoadContext(context);
    }

    next = alarm->next;
    AlarmQueue.head = next;
    if (next == 0) {
        AlarmQueue.tail = 0;
    } else {
        next->prev = 0;
    }
    handler = alarm->handler;
    alarm->handler = 0;
    if (0 < alarm->period) {
        InsertAlarm(alarm, 0, handler);
    }

    if (AlarmQueue.head) {
        SetTimer(AlarmQueue.head);
    }

    OSDisableScheduler();
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    handler(alarm, context);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
    OSEnableScheduler();
    __OSReschedule();
    OSLoadContext(context);
}

#pragma push
#pragma force_active on

static asm void DecrementerExceptionHandler(register s32 exception,
                                           register OSContext* context)
{
    nofralloc
    stw     r0, 0x0(r4)
    stw     r1, 0x4(r4)
    stw     r2, 0x8(r4)
    stmw    r6, 0x18(r4)
    mfspr   r0, 913
    stw     r0, 0x1a8(r4)
    mfspr   r0, 914
    stw     r0, 0x1ac(r4)
    mfspr   r0, 915
    stw     r0, 0x1b0(r4)
    mfspr   r0, 916
    stw     r0, 0x1b4(r4)
    mfspr   r0, 917
    stw     r0, 0x1b8(r4)
    mfspr   r0, 918
    stw     r0, 0x1bc(r4)
    mfspr   r0, 919
    stw     r0, 0x1c0(r4)
    stwu    r1, -0x8(r1)
    b       DecrementerExceptionCallback
}
#pragma pop
