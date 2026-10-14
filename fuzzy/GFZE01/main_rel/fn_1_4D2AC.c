/* Non-matching: best partial attempt (70.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/font.h"

typedef struct {
	u32 unk_0;
	f32 unk_4;
	f32 unk_8;
	f32 unk_C;
	f32 unk_10;
	u8 pad_14[0x18];
	f32 unk_2C;
	u32 unk_30;
	u32 pad_34;
	u32 unk_38;
	u8 pad_3C[0x1C];
} Obj_1_T;

extern Obj_1_T lbl_1_rodata_26F8;
extern void fn_1_50164(f32, f32, f32, f32, void *);

void fn_1_4D2AC(void *arg0, f32 arg1, f32 arg2) {
	Obj_1_T v;
	s32 w;
	s32 x;
	s32 y;
	s32 z;

	if ((s32)lbl_1_bss_4BA30.unk_0 == 0) {
		return;
	}
	lbl_1_bss_4BA30.unk_0 = 0;
	if (640.0f == lbl_1_bss_4BA30.unk_4 && 0.0 == lbl_1_bss_4BA30.unk_8
	    && 480.0f == lbl_1_bss_4BA30.unk_C && 0.0 == lbl_1_bss_4BA30.unk_10) {
		return;
	}
	if (lbl_1_bss_4BA30.unk_C > lbl_1_bss_4BA30.unk_10) {
		return;
	}
	if (lbl_1_bss_4BA30.unk_4 > lbl_1_bss_4BA30.unk_8) {
		return;
	}
	w = (s32)(lbl_1_bss_4BA30.unk_8 - lbl_1_bss_4BA30.unk_4);
	x = (s32)(lbl_1_bss_4BA30.unk_C - lbl_1_bss_4BA30.unk_10);
	w = (w < 0) ? -w : w;
	x = (x < 0) ? -x : x;
	v = lbl_1_rodata_26F8;
	v.unk_2C = (f32)(u32)(*(u8 *)((u8 *)arg0 + 3)) / 255.0f;
	y = (s32)(0.5f * (lbl_1_bss_4BA30.unk_4 + lbl_1_bss_4BA30.unk_8));
	z = (s32)(0.5f * (lbl_1_bss_4BA30.unk_C + lbl_1_bss_4BA30.unk_10));
	v.unk_C = arg1;
	v.unk_4 = (f32)(s32)y;
	v.unk_8 = (f32)(s32)z;
	v.unk_0 = 2;
	v.unk_30 = 10;
	v.unk_38 = *(u32 *)arg0;
	fn_1_50164((f32)(s32)w + arg2, (f32)(s32)x + arg2, 13.0f, 26.0f, &v);
}
