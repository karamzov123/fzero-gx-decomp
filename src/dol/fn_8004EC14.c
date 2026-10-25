#include "types.h"

extern u32 VIWaitForRetrace(void);

void fn_8004EC14(void) {
    VIWaitForRetrace();
}
