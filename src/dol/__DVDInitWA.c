#include "types.h"

extern u32 CommandList[];
extern u32 NextCommandNumber;
extern u32 OSInitAlarm(u32);
extern u32 __DVDLowSetWAType(u32, u32);

u32 __DVDInitWA(void) {
    u32 t0;
    NextCommandNumber = 0;
    CommandList[0] = -1;
    t0 = __DVDLowSetWAType(0, 0);
    return OSInitAlarm(t0);
}
