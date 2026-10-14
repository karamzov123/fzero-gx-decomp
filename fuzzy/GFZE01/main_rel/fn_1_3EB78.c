/* Non-matching: best partial attempt (88.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

static inline u8 fn_1_3EB78_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
u8 *fn_1_3EB78(s32 arg0, u8 *arg1, u8 *arg2, u32 *arg3) {
	u8 *v_base2 = (u8 *)&lbl_1_bss_3C00 + 0x20000;
	u8 *v_in2 = arg2;
	u8 *v_base = &lbl_1_bss_3C00;
	u8 *v_p2 = v_base2 + 0x265C;
	u8 *v_ret;
	u8 *v_p1 = v_base + 0x163C;
	u32 *v_p3 = (u32 *)(v_base2 + 0x267C);
	u32 *v_in3 = arg3;
	u8 *v_p4 = v_base2 + 0x2298;
	u16 *v_p5 = (u16 *)(v_base2 + 0x2048);
	u8 *v_bss = (u8 *)&lbl_1_bss_8B3A0;
	s32 v_j;
	s32 v_i = 0;
	v_j = 0;

	arg0 &= 0xFF;
	while (v_i < arg0 && v_j < 4) {
		u8 c = *arg1;

		if (c != 0xFF) {
			*v_p2 = c;
			if (!(arg2 != 0 && *v_in2 != 0xFF)) {
				*v_p1 = 1;
			} else {
				*v_p1 = *v_in2;
			}
			if (arg3 == 0) {
				*v_p3 = 0;
			} else {
				*v_p3 = *v_in3;
			}
			v_i++;
			*v_p4 = (u8)v_j;
			v_p4++;
			*v_p5 = fn_1_3EB78_array_read(v_bss, 0x9F);
			v_p2++;
			v_p1++;
			v_p5++;
			v_p3++;
		}
		v_in3++;
		v_bss++;
		v_j++;
		v_in2++;
		arg1++;
	}
	v_ret = v_base + 0x30;
	v_base[0] = (u8)v_i;
	v_ret[8] = (u8)v_i;
	return v_ret;
}
#pragma opt_lifetimes reset
