#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSTime.h>


/* --- dol/OSCreateAlarm.c --- */
struct OSCreateAlarm_Arg0 {
    u32 unk_0;
    u32 unk_4;
};

void OSCreateAlarm(struct OSCreateAlarm_Arg0 *arg0) {
    arg0->unk_0 = 0;
    arg0->unk_4 = 0;
}

/* --- dol/InsertAlarm.c --- */
void PPCMtdec(u32 val);

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
