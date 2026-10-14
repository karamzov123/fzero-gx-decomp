/* Non-matching: best partial attempt (50.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/driver.h"

extern f32 lbl_1_rodata_4AC4[4];
extern void fn_8003462C(u32, u32, u32);
extern vu32 __PERegs[];

/* write-gather pipe at 0xCC008000: every store goes to the same FIFO address */
#define fifo ((volatile u8 *)__PERegs - 0x8000)

void fn_1_AA350(s16 *pa, s16 *pb, u8 *pc, u32 n) {
	u32 i;

	if ((s32)lbl_1_bss_71690.unk_0 == 0) {
		return;
	}
	fn_8003462C(0x98, 0, n & 0xFFFF);
	for (i = 0; i < n; i++) {
		*(volatile f32 *)fifo = (f32)pa[i];
		*(volatile f32 *)fifo = (f32)pb[i];
		*(volatile f32 *)fifo = lbl_1_rodata_4AC4[0];
		*(volatile u8 *)fifo = pc[i * 4 + 0];
		*(volatile u8 *)fifo = pc[i * 4 + 1];
		*(volatile u8 *)fifo = pc[i * 4 + 2];
		*(volatile u8 *)fifo = pc[i * 4 + 3];
	}
}
