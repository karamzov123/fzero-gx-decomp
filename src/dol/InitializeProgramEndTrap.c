#include "types.h"

extern void ICInvalidateRange(void *, u32);
extern void fn_800035C0(void *, void *, u32);
extern void DCFlushRange(void *, u32);
extern void PPCHalt(void);
extern u8 EndofProgramInstruction[];

void InitializeProgramEndTrap(void) {
    u8 *trap = (u8 *)PPCHalt;

    fn_800035C0(trap + 4, EndofProgramInstruction, 4);
    ICInvalidateRange(trap + 4, 4);
    DCFlushRange(trap + 4, 4);
}
