/* Non-matching: best partial attempt (83.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"

u8 *fn_4_A82C(u8 *arg0) {
	u8 *base;
	u8 *res;
	u8 *tbl;
	s32 idx;

	base = (u8 *)&lbl_4_data_0;
	res = base + 0x2E94;
	tbl = base + 0x2DCC;
	for (idx = 0; idx < 54; idx += 2, tbl += 2) {
		if (arg0[0] == tbl[0] && arg0[1] == tbl[1]) {
			return res + idx / 2;
		}
	}
	res = base + 0x2EB0;
	tbl = base + 0x2E04;
	for (idx = 0; idx < 54; idx += 2, tbl += 2) {
		if (arg0[0] == tbl[0] && arg0[1] == tbl[1]) {
			return res + idx / 2;
		}
	}
	res = base + 0x2ECC;
	tbl = base + 0x2E3C;
	for (idx = 0; idx < 64; idx += 2, tbl += 2) {
		if (arg0[0] == tbl[0] && arg0[1] == tbl[1]) {
			return res + idx / 2;
		}
	}
	res = base + 0x2EF0;
	tbl = base + 0x2E7C;
	for (idx = 0; idx < 22; idx += 2, tbl += 2) {
		if (arg0[0] == tbl[0] && arg0[1] == tbl[1]) {
			return res + idx / 2;
		}
	}
	return 0;
}
