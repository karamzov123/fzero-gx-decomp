/* Non-matching: best partial attempt (94.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rep_memcard.h"

extern u32 lbl_801A6410;
extern u32 fn_1_B7C00(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, u8 *arg2, s32 arg3);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_B9C0C(void);
extern void fn_1_BC29C(void *arg0);
extern u32 fn_1_C1394(void *arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);

typedef struct {
	u32 pad_0[2];
	u32 unk_8;
	s32 unk_C;
	u32 unk_10;
	s8 unk_14;
} Obj_154A08_tow;

typedef struct {
	u32 unk_0;
	u32 unk_4;
	u32 unk_8;
	s32 unk_C;
	u32 unk_10;
	Obj_154A08_tow unk_14;
} Obj_154A08_root;

#pragma opt_propagation off
void fn_1_154A08(void) {
	Obj_154A08_root *p = (Obj_154A08_root *)&lbl_1_bss_8ED90;
	Obj_154A08_tow *t;
	s8 mode;
	u32 v;
	u32 c;
	u32 res;

	if (fn_1_B7C00() & 0xFF) {
		return;
	}

	if (p->unk_8 != 0) {
		fn_1_46B4(lbl_801A6410, p->unk_8, lbl_1_data_49AC8, 0xcd);
	}

	{
		Obj_154A08_tow *mt = &p->unk_14;
		mode = mt->unk_14;
	}

	if (mode == 1) {
		fn_1_B9C0C();
		fn_1_BC29C(&p->unk_14);
		lbl_1_data_49AB4.unk_0 = 4;
	} else if (mode == 2) {
		if (p->unk_0 != 0) {
			fn_1_46B4(lbl_801A6410, p->unk_0, lbl_1_data_49AC8, 0xda);
		}

		t = &p->unk_14;

		if (t->unk_C != 0) {
			v = fn_1_4630(lbl_801A6410, t->unk_C, lbl_1_data_49AC8, 0xdf);
			fn_80008BA8(v, t->unk_8, t->unk_C);
			fn_1_B9C0C();
			if (t->unk_8 != 0) {
				fn_1_46B4(lbl_801A6410, t->unk_8, lbl_1_data_49AC8, 0xe9);
				t->unk_8 = 0;
			}
			res = fn_1_4630(lbl_801A6410, t->unk_C, lbl_1_data_49AC8, 0xee);
			c = t->unk_C;
			p->unk_0 = res;
			p->unk_4 = c;
			t->unk_C = 0;
			fn_80008BA8(res, v, c);
			fn_1_46B4(lbl_801A6410, v, lbl_1_data_49AC8, 0xf9);
		}

		lbl_1_data_49AB4.unk_0 = 4;
		fn_1_BC29C(t);
	} else if (mode == 8) {
		fn_1_C1394(&p->unk_14);
		lbl_1_data_49AB4.unk_0 = 1;
	}
}
#pragma opt_propagation reset
