/* Non-matching: best partial attempt (58.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern u8 lbl_800929D8[0x160];
extern const f64 lbl_801A7248;
extern const f32 lbl_801A7250;
extern const f64 lbl_801A7238;
extern const f64 lbl_801A7218;
extern const f32 lbl_801A7254;
extern f32 fn_80088578(f32 x);
extern s32 fn_8005D258(u32 a0, void *a1, u8 a2, u8 a3, f32 *a4, s16 *a5);

typedef struct Entry {
	u8 pad0[0x140A];
	u8 f_140A;
	u8 pad1[6];
	u8 f_1411;
	u8 f_1412;
	u8 pad2[9];
	u32 f_141C;
	u32 f_1420;
	void *f_1424;
	u32 f_1428;
	u8 pad4[0x60];
	u32 f_148C;
	u8 pad5[0x8C];
	s32 f_151C;
} Entry;

typedef struct Tables {
	u8 pad0[0x20];
	u8 t20[0x40];
	u8 t40[0x20];
	u8 t60[0x100];
} Tables;

#define EL ((Entry *)((u8 *)lbl_801A6C80 + off))

void fn_8005C9D8(u32 arg0) {
	Tables *tb = (Tables *)lbl_800929D8;
	u32 off = arg0 * 0x118;
	u32 id = arg0;
	u32 idx;
	void *pv = EL->f_1424;
	s16 os;
	f32 of;
	s16 osv;
	f32 ofv;
	f32 fa;
	f32 fb;
	s16 v;
	s16 res;
	s16 x2;
	s16 x1;
	u32 sel;
	u32 fb2;
	s16 q;

	v = fn_8005D258(EL->f_1428, pv, EL->f_140A, (u8)(EL->f_1420 >> 8), &of, &os);
	if (EL->f_1411 != 0xff || EL->f_1412 != 0xff) {
		sel = *(u8 *)((u8 *)pv + 6);
		fb2 = EL->f_140A;
		if (sel & 0xFF000000) {
			sel = *(u8 *)((u8 *)lbl_801A6C80 + fb2 * 32 + 0x590);
		}
		q = (s16)tb->t60[sel & 0xFF];
		osv = os;
		ofv = of;
		idx = ((s32)q / 4 - 1) & 0xFF;
		fa = ofv + (f32)(20.0 * fn_80088578((f32)tb->t20[idx] / 255.0f));
		fb = ofv + (f32)(20.0 * fn_80088578((f32)tb->t40[idx] / 255.0f));
		x1 = (s16)(s32)((f32)osv + 10.0f * fa);
		x2 = (s16)(s32)((f32)osv + 10.0f * fb);
		if (x1 < -960) {
			x1 = -960;
		}
		if (x2 < -960) {
			x2 = -960;
		}
		res = (EL->f_1411 == id) ? x1 : x2;
	} else {
		res = v;
	}
	EL->f_148C = (u32)((s32)res - (EL->f_151C >> 16)) << 16;
	EL->f_141C = res;
}
