#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>

void PPCMtdec(u32 val);
s32 OSDisableScheduler();
s32 OSEnableScheduler();
extern void *__OSGetExceptionHandler(u32 exception);
extern void __OSSetExceptionHandler(u32 exception, void *handler);
static void DecrementerExceptionHandler(register __OSException exception, register OSContext *context);

extern struct OSAlarmQueue {
    OSAlarm *head;
    OSAlarm *tail;
} AlarmQueue;

static inline void SetTimer(OSAlarm *alarm) {
    OSTime delta;
    delta = alarm->fire - __OSGetSystemTime();
    if (delta < 0) {
        PPCMtdec(0);
    } else if (delta < 0x80000000) {
        PPCMtdec((u32)delta);
    } else {
        PPCMtdec(0x7fffffff);
    }
}

void OSInitAlarm(void) {
    if (__OSGetExceptionHandler(8) != (void *)DecrementerExceptionHandler) {
        AlarmQueue.head = AlarmQueue.tail = 0;
        __OSSetExceptionHandler(8, (void *)DecrementerExceptionHandler);
    }
}

void OSCreateAlarm(OSAlarm *alarm) {
    alarm->handler = 0;
    alarm->tag = 0;
}

void InsertAlarm(OSAlarm *alarm, OSTime fire, OSAlarmHandler handler) {
    OSAlarm *next;
    OSAlarm *prev;
    if (0 < alarm->period) {
        OSTime time = __OSGetSystemTime();
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

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    alarm->period = 0;
    InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);
    OSRestoreInterrupts(enabled);
}

void OSSetPeriodicAlarm(OSAlarm *alarm, OSTime start, OSTime period, OSAlarmHandler handler) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = __OSTimeToSystemTime(start);
    InsertAlarm(alarm, 0, handler);
    OSRestoreInterrupts(enabled);
}

void OSCancelAlarm(OSAlarm *alarm) {
    OSAlarm *next;
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

void DecrementerExceptionCallback(register __OSException exception, register OSContext *context) {
    OSAlarm *alarm;
    OSAlarm *next;
    OSAlarmHandler handler;
    OSTime time;
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

/* Dolphin SDK os/OSAlarm.c: the decrementer exception entry is a CodeWarrior asm function
 * (it saves the interrupted context's GPRs and GQRs without a compiler frame, then branches
 * to the C callback). */
static asm void DecrementerExceptionHandler(register __OSException exception, register OSContext *context) {
    nofralloc
    stw r0, 0x0(context)
    stw r1, 0x4(context)
    stw r2, 0x8(context)
    stmw r6, 0x18(context)
    mfspr r0, GQR1
    stw r0, 0x1a8(context)
    mfspr r0, GQR2
    stw r0, 0x1ac(context)
    mfspr r0, GQR3
    stw r0, 0x1b0(context)
    mfspr r0, GQR4
    stw r0, 0x1b4(context)
    mfspr r0, GQR5
    stw r0, 0x1b8(context)
    mfspr r0, GQR6
    stw r0, 0x1bc(context)
    mfspr r0, GQR7
    stw r0, 0x1c0(context)
    stwu r1, -0x8(r1)
    b DecrementerExceptionCallback
}
