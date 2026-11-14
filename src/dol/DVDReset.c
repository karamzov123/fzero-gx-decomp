#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

void DVDLowReset();

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern vu32 ResumeFromHere;

// Hardware or OS state can change asynchronously.
extern volatile BOOL ResetRequired; // fzgx-allow: S2 SDK asynchronous state

void DVDReset(void) {
    DVDLowReset();
    __DIRegs[0] = 0x2a;
    __DIRegs[1] = __DIRegs[1];
    ResetRequired = 0;
    ResumeFromHere = 0;
}
