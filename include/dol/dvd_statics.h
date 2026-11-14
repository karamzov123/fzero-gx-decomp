#ifndef DOL_DVD_STATICS_H
#define DOL_DVD_STATICS_H

#include <dolphin/os/OSAlarm.h>

/* dvdlow.c's third file-scope alarm, between AlarmForTimeout and Prev in .bss. No code in
 * this build arms it, so dtk had no symbol for it; the name is the SDK's. */
extern OSAlarm AlarmForBreak;

#endif
