/* Non-matching: best partial attempt (77.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern void fn_80008BEC(void *, int, u32);

void fn_1_2F04(void) {
	u8 *chk = lbl_1_bss_978 + 0x50;
	u8 *a = lbl_1_bss_978 + 0x34c;
	u8 *b = lbl_1_bss_978 + 0x380;
	u8 *c = lbl_1_bss_978 + 0x3b0;
	u8 *d = (u8 *)&lbl_1_data_2B78;
	u16 *e = (u16 *)(lbl_1_bss_978 + 0x80);
	u8 *lim = lbl_1_bss_978 + 0xd0;
	s32 i;

	for (i = 0; i < 4; i++) {
		s32 j;
		s32 k;
		u8 *p = a;
		if ((s8)chk[10] == -1) {
			fn_80008BEC(e, 0, 0x14);
		} else {
			for (j = 0; j < 13; j++) {
				s32 f;
				if (31u - (u32)j != 24) {
					if (e[4] & (0x80000000u >> (32 - j))) {
						*p = 0;
						f = 1;
					} else {
						if (*p) {
							(*p)--;
						}
						f = 0;
					}
					if (*p == 0 && (e[0] & (0x80000000u >> (32 - j)))) {
						*p = f ? 20 : 4;
						e[8] |= 0x80000000u >> (31 - j);
					} else {
						e[8] &= ~(0x80000000u >> (31 - j));
					}
				}
				p++;
			}
			p = b;
			for (k = 0; k < 12; k++) {
				u8 *q = c;
				s32 f;
				s32 t;
				u8 v;
				u8 o;
				if (e[5] & (0x40000000u >> (31 - k))) {
					*p = 0;
					f = 1;
				} else {
					if (*p) {
						(*p)--;
					}
					f = 0;
				}
				e[9] &= ~(0x80000000u >> (31 - k));
				if (!*p) {
					if (e[1] & (0x40000000u >> (31 - k))) {
						o = *q;
						switch (k) {
						case 0:
						case 1:
							t = (s8)lim[0];
							v = (t ^ (t >> 31)) - (t >> 31);
							break;
						case 2:
						case 3:
							t = (s8)lim[1];
							v = (t ^ (t >> 31)) - (t >> 31);
							break;
						case 4:
						case 5:
							t = (s8)lim[2];
							v = (t ^ (t >> 31)) - (t >> 31);
							break;
						case 6:
						case 7:
							t = (s8)lim[3];
							v = (t ^ (t >> 31)) - (t >> 31);
							break;
						default:
							v = 0x48;
							break;
						}
						*q = v;
						if (f) {
							*p = 20;
						} else if (v >= 30 && v >= o) {
							if (d[0] == 1) {
								*p = (0x154 - (v << 2)) / 13;
							} else {
								*p = (0x546 - 17 * v) / 42;
							}
						}
						e[9] |= 0x80000000u >> (31 - k);
					}
				}
				p++;
				q++;
			}
			b += 0xc;
			c += 0xc;
		}
		chk += 0xc;
		a += 0xd;
		d++;
		e = (u16 *)((u8 *)e + 0x14);
		lim += 0x10;
	}
}
