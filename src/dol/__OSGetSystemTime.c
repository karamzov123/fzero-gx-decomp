#include "sdk_addresses.h"
#include <dolphin/os.h>
#include <dolphin/os/OSTime.h>
#pragma peephole off

/* --- dol/__OSGetSystemTime.c --- */
OSTime OSGetTime(void);

asm OSTime OSGetTime(void);

OSTime __OSGetSystemTime(void) {
    BOOL enabled;
    OSTime *timeAdjustAddr = (OSTime *)FZGX_ADDR___OSTimeAdjust;
    OSTime result;
    enabled = OSDisableInterrupts();
    result = *timeAdjustAddr + OSGetTime();
    OSRestoreInterrupts(enabled);
    return result;
}

/* --- dol/__OSTimeToSystemTime.c --- */
OSTime __OSTimeToSystemTime(OSTime time) {
    BOOL enabled;
    OSTime *timeAdjustAddr = (OSTime *)FZGX_ADDR___OSTimeAdjust;
    OSTime result;
    enabled = OSDisableInterrupts();
    result = *timeAdjustAddr + time;
    OSRestoreInterrupts(enabled);
    return result;
}

/* --- dol/GetDates.c --- */
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
