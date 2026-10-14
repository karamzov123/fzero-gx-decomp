/* Non-matching: best partial attempt (69.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

extern void fn_1_789AC(void);
extern u32 fn_1_56B8(void);
extern void fn_1_9A578(void);
extern void fn_1_59290(void);
extern void fn_1_87074(void);
extern void fn_1_98590(void);
extern f32 lbl_1_rodata_BDC[2];
extern void fn_1_15E27C(void);
extern void fn_1_2E268(void);
extern u8 fn_1_86810(s32);

struct S {
	u8 pad_00[0x30];
	u32 unk_30;
	u8 pad_34[0x14B8];
	u16 unk_14EC[4];
	u8 unk_14F4;
	u8 pad_14F5[0x2270F];
};

struct B {
	u8 pad_00[0x2F18];
	u8 unk_2F18;
	u8 unk_2F19;
	u8 unk_2F1A;
	u8 unk_2F1B;
	u8 pad_2F1C[2];
	u8 unk_2F1E;
	u8 pad_2F1F;
	u8 unk_2F20[0x28];
	u32 unk_2F48;
	u8 pad_2F4C[0x1B8];
	f32 unk_2704[4];
};

struct T {
	u32 unk_0;
	u8 pad_04[5];
	u8 unk_9;
	u8 pad_0A[4];
	u8 tab[0x13B4 - 0x0E];
	u32 unk_13B4[3];
	u32 pad_13C0[5];
	u32 unk_13D4[3];
	u8 pad_13E0[0x14];
	u8 unk_13F4[2];
	u8 pad_13F6[0x0F];
	u8 unk_1405;
	u8 pad_1406[0x62];
	u8 unk_1468[4];
};

void fn_1_359B8(void) {
	struct B *b;
	struct S *p;
	struct T *t;
	u16 *h;
	f32 *fv;
	f32 z;
	s32 i;
	s32 n;
	s32 lim;
	s32 j;
	u32 v;
	u8 *m;
	u8 *e;

	p = (struct S *)&lbl_1_bss_3C00;
	lbl_1_bss_17AC = 1;
	b = (struct B *)((u8 *)p + 0x20000);
	fn_1_789AC();
	fn_1_56B8();
	fn_1_9A578();
	fn_1_59290();
	fn_1_87074();
	fn_1_98590();
	t = (struct T *)((u8 *)p + 0x30);
	h = (u16 *)((u8 *)p + 0x14EC);
	fv = (f32 *)((u8 *)b + 0x2704);
	z = lbl_1_rodata_BDC[0];
	b->unk_2F48 = 0;
	v = p->unk_30 & 0xFFF7BF59u;
	b->unk_2F1E = 0;
	p->unk_14F4 = 0;
	b->unk_2F19 = 0;
	b->unk_2F1A = 0;
	b->unk_2F1B = 0;
	b->unk_2F18 = 0;
	h[0] = 0xFFFF;
	fv[0] = z;
	t->unk_1468[0] = 0;
	h[1] = 0xFFFF;
	fv[1] = z;
	t->unk_1468[1] = 0;
	h[2] = 0xFFFF;
	fv[2] = z;
	t->unk_1468[2] = 0;
	h[3] = 0xFFFF;
	fv[3] = z;
	t->unk_1468[3] = 0;
	t->unk_13B4[0] = 0;
	t->unk_13D4[0] = 0;
	t->unk_13B4[1] = 0;
	t->unk_13D4[1] = 0;
	t->unk_13B4[2] = 0;
	t->unk_13D4[2] = 0;
	t->unk_13F4[0] = 0;
	t->unk_13F4[1] = 0;
	t->unk_1405 = 0;
	p->unk_30 = v;
	fn_1_15E27C();
	lbl_1_bss_8E51D = 0;
	if (!(p->unk_30 & 0x800)) {
		fn_1_2E268();
	}
	for (i = 0; i < t->unk_9; i++) {
		t->tab[fn_1_86810(i) + 14] = (u8)i;
	}
	n = (s32)t->unk_9;
	if (!(p->unk_30 & 0x800) && n > 0) {
		m = (u8 *)b + 0x2F20;
		lim = n - 8;
		for (j = 0; j < n; j++) {
			m[j] = 0;
		}
	}
}
