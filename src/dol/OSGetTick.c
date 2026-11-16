#include "types.h"

/* Original SDK assembly, not a C reconstruction: retail 80011424..8001142C
 * is the time-base leaf. The corresponding Sunshine OSTime.c also uses an
 * asm/nofralloc OSGetTick; see docs/RECONSTRUCTION_STANDARDS.md. */
asm u32 OSGetTick(void) {
    nofralloc
    mftb r3, 268
    blr
}
