#include "types.h"

extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 Reschedule;

u32 OSDisableScheduler(void) {
    u32 v0;
    u32 t0;
    t0 = OSDisableInterrupts();
    v0 = Reschedule;
    Reschedule = (v0 + 1);
    OSRestoreInterrupts(t0);
    return v0;
}
