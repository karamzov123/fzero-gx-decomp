#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern DVDLowCallback Callback;

DVDLowCallback DVDLowClearCallback() {
    DVDLowCallback old;
    __DIRegs[1] = 0;
    old = Callback;
    Callback = ((void *)0);
    return old;
}
