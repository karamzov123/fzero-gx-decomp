/* Non-matching: best partial attempt (86.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/types.h"

extern u8 lbl_801A6398[24];
extern void *memset(void *, int, u32);
void fn_8008ED70(void) {
    memset(lbl_801A6398, 0, 0x18);
    *(vu32 *)0xCC006828 = 0;
    *(vu32 *)0xCC00643C = 0;
}
