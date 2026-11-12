#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state

extern DVDLowCallback Callback;

// Hardware or OS state can change asynchronously.
extern volatile BOOL WaitingCoverClose; // fzgx-allow: S2 SDK asynchronous state

BOOL DVDLowWaitCoverClose(DVDLowCallback callback) {
    Callback = callback;
    WaitingCoverClose = 1;
    StopAtNextInt = 0;
    __DIRegs[1] = 2;
    return 1;
}
