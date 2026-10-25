#include "types.h"

extern u32 DVDLowReadDiskID(u32, u32);
extern u32 lbl_8015CE60[];
extern void cbForStateCoverClosed(void);

void stateCoverClosed_CMD(void) {
    DVDLowReadDiskID((u32)&lbl_8015CE60, (u32)cbForStateCoverClosed);
}
