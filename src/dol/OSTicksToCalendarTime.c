#include <dolphin/os.h>
#include <dolphin/os/OSTime.h>
#include "sdk_addresses.h"
#include "types.h"
#pragma peephole off
#pragma dont_inline on

/* --- dol/OSTicksToCalendarTime.c --- */
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

void GetDates(s32 days, OSCalendarTime *cal);

void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime *td) {
    int days;
    int secs;
    OSTime d;
    d = ticks % ((1) * ((u32)__OSBusClock / 4));
    if (d < 0) {
        d += ((1) * ((u32)__OSBusClock / 4));
    }
    td->usec = (int)((((d) * 8) / (((u32)__OSBusClock / 4) / 125000)) % 1000);
    td->msec = (int)(((d) / (((u32)__OSBusClock / 4) / 1000)) % 1000);
    ticks -= d;
    days = (int)(((ticks) / ((u32)__OSBusClock / 4)) / 86400 +
                 (2000 * 365 + (2000 + 3) / 4 - (2000 - 1) / 100 + (2000 - 1) / 400));
    secs = (int)(((ticks) / ((u32)__OSBusClock / 4)) % 86400);
    if (secs < 0) {
        days -= 1;
        secs += 24 * 60 * 60;
    }
    GetDates(days, td);
    td->hour = secs / 60 / 60;
    td->min = (secs / 60) % 60;
    td->sec = secs % 60;
}
