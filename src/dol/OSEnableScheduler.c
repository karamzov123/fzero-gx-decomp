#include "types.h"

extern int Reschedule;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int OSEnableScheduler(void) {
    int level;
    int reschedule;

    level = OSDisableInterrupts();
    reschedule = Reschedule;
    Reschedule = reschedule - 1;
    OSRestoreInterrupts(level);
    return reschedule;
}
