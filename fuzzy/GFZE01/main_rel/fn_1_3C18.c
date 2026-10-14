/* Non-matching: best partial attempt (65.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
extern u32 OSGetTick(u32);
extern u32 lbl_1_bss_D7C;

u32 fn_1_3C18(volatile s32 arg0) {
    u32 tick = OSGetTick(arg0);
    return ((tick - *(u32 *)((u8 *)&lbl_1_bss_D7C + (arg0 << 2))) << 3) / ((*(volatile u32 *)0x800000F8 >> 2) / 125000);
}
