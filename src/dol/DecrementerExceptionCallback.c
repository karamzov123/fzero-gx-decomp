#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSTime.h>

void PPCMtdec(u32 val);

s32 OSDisableScheduler();

s32 OSEnableScheduler();

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

void InsertAlarm(OSAlarm *alarm, OSTime fire, OSAlarmHandler handler);

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
