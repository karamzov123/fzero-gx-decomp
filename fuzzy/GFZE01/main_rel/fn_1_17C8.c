/* Non-matching: best partial attempt (41.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_17C8_rodata {
	s8 tab[0x38];
	f64 eps;
	f32 one;
	f32 zero;
	f64 bias;
};

extern struct fn_1_17C8_rodata lbl_1_rodata_70;
extern f64 __fabs(f64);
extern s32 abs(s32);

void fn_1_17C8(s8 *out_x, s8 *out_y, s8 *pts, s8 *pct) {
	s32 i;
	s32 t;
	s32 a;
	s32 sgn;
	f32 x0;
	f32 y0;
	f32 x1;
	f32 y1;
	f32 det;
	f32 k;
	f32 px;
	f32 py;
	f32 sa;
	f32 sb;
	f32 w0;
	f32 w1;
	f32 w2;
	f32 w3;

	for (i = 0; i < 8; i++) {
		x0 = pts[i * 2 + 0];
		y0 = pts[i * 2 + 1];
		x1 = pts[i * 2 + 2];
		y1 = pts[i * 2 + 3];
		det = x0 * y1 - y0 * x1;
		if (__fabs((f64)det) < lbl_1_rodata_70.eps) {
			continue;
		}
		k = lbl_1_rodata_70.one / det;
		px = (f32)out_x[0];
		py = (f32)out_y[0];
		sa = (y1 * px - x1 * py) * k;
		sb = (x0 * py - y0 * px) * k;
		if (sa < lbl_1_rodata_70.zero) {
			continue;
		}
		if (sb < lbl_1_rodata_70.zero) {
			continue;
		}
		w0 = lbl_1_rodata_70.tab[i * 2 + 0];
		w1 = lbl_1_rodata_70.tab[i * 2 + 2];
		t = (s32)(sa * w0 + sb * w1);
		a = 100 * (pct[0] - abs(t)) / (100 - pct[0]);
		if (a < 0) {
			a = 0;
		}
		if (a > 100) {
			a = 100;
		}
		sgn = (t < 0) ? -1 : 1;
		out_x[0] = sgn * a;
		w2 = lbl_1_rodata_70.tab[i * 2 + 1];
		w3 = lbl_1_rodata_70.tab[i * 2 + 3];
		t = (s32)(sa * w2 + sb * w3);
		a = 100 * (pct[1] - abs(t)) / (100 - pct[1]);
		if (a < 0) {
			a = 0;
		}
		if (a > 100) {
			a = 100;
		}
		sgn = (t < 0) ? -1 : 1;
		out_y[0] = sgn * a;
		break;
	}
}
