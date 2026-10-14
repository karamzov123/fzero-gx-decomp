/* Non-matching: best partial attempt (98.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/types.h"

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern vu32 *lbl_801A6678; /* shared interrupt state is hardware-updated */
extern vu32 __EXIRegs[]; /* memory-mapped hardware register block */

u32 fn_8008EBF8(u32 arg0) {
    u32 interrupts;
    vu32 *flags; /* shared flag field is hardware-updated */
    u32 value;
    u32 reg;

    interrupts = OSDisableInterrupts();
    flags = &lbl_801A6678[3];
    if (*flags & 4) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }

    *flags |= 4;
    value = (arg0 << 4) | 0x80;
    reg = __EXIRegs[10];
    reg &= 0x405;
    reg |= value;
    __EXIRegs[10] = reg;
    OSRestoreInterrupts(interrupts);
    return 1;
}
