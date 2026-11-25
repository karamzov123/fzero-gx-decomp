#include "types.h"
#include "sdk_addresses.h"
#include <dolphin/os.h>
#include <dolphin/os/OSTime.h>

#pragma peephole off

/* Original SDK assembly, not a C reconstruction: retail 8001140C..8001142C are the
 * time-base leaves (OSGetTime rereads the upper half until it is stable). The
 * corresponding Sunshine OSTime.c also writes OSGetTime and OSGetTick as asm/nofralloc;
 * see docs/RECONSTRUCTION_STANDARDS.md. */
asm OSTime OSGetTime(void) {
    nofralloc
@1:
    mftbu r3
    mftb r4
    mftbu r5
    cmpw r3, r5
    bne @1
    blr
}

asm u32 OSGetTick(void) {
    nofralloc
    mftb r3, 268
    blr
}

OSTime __OSGetSystemTime(void) {
    BOOL enabled;
    OSTime *timeAdjustAddr = (OSTime *)FZGX_ADDR___OSTimeAdjust;
    OSTime result;
    enabled = OSDisableInterrupts();
    result = *timeAdjustAddr + OSGetTime();
    OSRestoreInterrupts(enabled);
    return result;
}

OSTime __OSTimeToSystemTime(OSTime time) {
    BOOL enabled;
    OSTime *timeAdjustAddr = (OSTime *)FZGX_ADDR___OSTimeAdjust;
    OSTime result;
    enabled = OSDisableInterrupts();
    result = *timeAdjustAddr + time;
    OSRestoreInterrupts(enabled);
    return result;
}

extern s32 lbl_80123AF0[12];
extern s32 lbl_80123B20[12];

static inline BOOL IsLeapYear(s32 year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static inline s32 GetLeapDays(s32 year) {
    if (year < 1) {
        return 0;
    }
    return (year + 3) / 4 - (year - 1) / 100 + (year - 1) / 400;
}

void GetDates(s32 days, OSCalendarTime *cal) {
    s32 year;
    s32 totalDays;
    s32 *p_days;
    s32 month;
    cal->wday = (days + 6) % 7;
    for (year = days / 365; days < (totalDays = year * 365 + GetLeapDays(year));) {
        year--;
    }
    days -= totalDays;
    cal->year = year;
    cal->yday = days;
    p_days = IsLeapYear(year) ? lbl_80123B20 : lbl_80123AF0;
    month = 12;
    while (days < p_days[--month]) {
        ;
    }
    cal->mon = month;
    cal->mday = days - p_days[month] + 1;
}

#pragma dont_inline on
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

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
#pragma dont_inline reset
