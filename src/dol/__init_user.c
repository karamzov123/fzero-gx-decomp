#include <dolphin/os.h>
#include <dolphin/os/OSTime.h>
#include "sdk_addresses.h"
#include "types.h"
#pragma peephole off
#pragma dont_inline on

/* --- dol/OSTicksToCalendarTime.c --- */
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

void GetDates(s32 days, OSCalendarTime *cal);

void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime *td);

/* --- dol/__init_user.c --- */
extern void __init_cpp(void);

void __init_user(void) {
    __init_cpp();
}
