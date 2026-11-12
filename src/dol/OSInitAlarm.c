#include "types.h"

typedef struct OSAlarmQueue OSAlarmQueue;

struct OSAlarmQueue {
    u32 first;
    u32 second;
};

extern void* __OSGetExceptionHandler(u32 exception);
extern void __OSSetExceptionHandler(u32 exception, void* handler);
extern void DecrementerExceptionHandler_8000B2C4(void);
extern OSAlarmQueue AlarmQueue;

void OSInitAlarm(void) {
    void* handler;

    handler = __OSGetExceptionHandler(8);
    if (handler != (void*)DecrementerExceptionHandler_8000B2C4) {
        AlarmQueue.second = 0;
        AlarmQueue.first = 0;
        __OSSetExceptionHandler(8, (void*)DecrementerExceptionHandler_8000B2C4);
    }
}
