#include "types.h"

extern u32 BB2[];
extern u32 DVDLowRead(u32, u32, u32, u32);
extern void fn_80018330(void);

void stateCheckID2(void) {
    DVDLowRead((u32)&BB2, 32, 1056, (u32)fn_80018330);
}
