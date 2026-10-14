/* Non-matching: best partial attempt (55.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_5FFB0_p {
	u8 pad_0[0x10];
	s32 unk_10;
	s32 unk_14;
	u8 pad_18[0x20];
	s32 unk_38;
	u8 pad_3C[0x18];
	u16 unk_54;
};

extern u32 lbl_1_data_1D628;
extern u32 lbl_1_bss_6C86C;
extern u32 lbl_1_bss_6C870[2];
extern u32 lbl_801A6410;
extern s32 fn_1_45D0(u32, u32);

void fn_1_5FFB0(struct fn_1_5FFB0_p *p) {
	u32 rnd;
	f32 f, g;
	s16 a;

	a = 8;
	lbl_1_bss_6C870[0] = a;
	lbl_1_bss_6C86C = 30;
	g = (f32)a;

	rnd = lbl_1_data_1D628 * 0x41C64E6D + 12345;
	f = (f32)((rnd >> 1) & 0x7FFF) / 32767.0f;
	lbl_1_data_1D628 = rnd;
	f = 0.5f * f;
	f = 0.8f + f;
	p->unk_14 = (s32)(g * f);

	rnd = lbl_1_data_1D628 * 0x41C64E6D + 12345;
	f = (f32)((rnd >> 1) & 0x7FFF) / 32767.0f;
	lbl_1_data_1D628 = rnd;
	g = (f32)(s16)lbl_1_bss_6C86C;
	f = 0.2f * f;
	f = 0.8f + f;
	f = g * f;
	f = f + (f32)(s16)p->unk_14;
	p->unk_10 = (s32)f;

	p->unk_38 = fn_1_45D0(lbl_801A6410, 0xA0);

	rnd = lbl_1_data_1D628 * 0x41C64E6D + 12345;
	lbl_1_data_1D628 = rnd;
	p->unk_54 = (u16)((rnd >> 16) & 3);
}
