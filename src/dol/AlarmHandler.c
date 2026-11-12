#include "types.h"

extern void DVDReset(void);
extern u32 lbl_8015CE60[];
extern void DCInvalidateRange(void *, u32);
extern void stateCoverClosed_CMD(u32);
extern u32 executing;
extern u32 lbl_801A6904;

void AlarmHandler(u32 unused1, u32 unused2) {
    DVDReset();
    DCInvalidateRange(lbl_8015CE60, 32);
    lbl_801A6904 = (u32)stateCoverClosed_CMD;
    stateCoverClosed_CMD(executing);
}
