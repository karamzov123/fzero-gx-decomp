/* Non-matching: best partial attempt (89.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct A50_obj {
	u32 pad0[0x23];
	s16 f8c;
	u8 pad1[0x10];
	u8 idx9e;
	u8 pad2[0x41];
	u32 times[4];
};

struct A50_ent9C8 {
	u8 pad0[10];
	s8 flag;
	u8 pad1[1];
};

struct A50_ent9F8 {
	u8 pad0[0x10];
	u16 a;
	u16 b;
};

extern struct A50_ent9C8 lbl_1_bss_9C8[4];
extern struct A50_ent9F8 lbl_1_bss_9F8[4];
extern volatile u32 lbl_1_bss_8B3A0[0x27];
extern u32 lbl_801A66A0[1];
extern s16 lbl_10_bss_55AE0;
extern const f32 lbl_10_rodata_1A4[15];
extern s16 fn_1_12F028(s16);
extern u32 fn_10_18C54(u32, u32, u32, f32);
extern f32 lbl_8006D188(u32);

#pragma opt_common_subs off
static inline u32 fn_10_18A50_call_fn_10_18C54(u32 a0, u32 a1, u32 a2, f32 a3) { return fn_10_18C54(a0, a1, a2, a3); }
void fn_10_18A50(struct A50_obj *arg0, u32 arg1, u32 unused) {
	s16 v;
	s32 m;
	s32 i;
	struct { s32 value; } n;
	f32 t;
    u32 lab_t1;

	if (fn_1_12F028(arg0->f8c) < 2) {
		return;
	}
	v = (s16)(*((arg0->times) + (arg0->idx9e)));
	for (i = 0; i < 4; i++) {
		if ((*((lbl_1_bss_9C8) + (i))).flag == -1) {
			continue;
		}
		if (!((*((lbl_1_bss_8B3A0) + (0x26))) & (0x80000000u >> (i + 1)))) {
			continue;
		}
		if ((((*((lbl_1_bss_9F8) + (i))).a >> 1) & 1) || (((*((lbl_1_bss_9F8) + (i))).b >> 1) & 1)
			|| ((*((lbl_1_bss_9F8) + (i))).a & 1) || ((*((lbl_1_bss_9F8) + (i))).b & 1)) {
			v = (s16)(*((arg0->times) + (i)));
			if ((((*((lbl_1_bss_9F8) + (i))).a >> 1) & 1) || (((*((lbl_1_bss_9F8) + (i))).b >> 1) & 1)) {
				lbl_10_bss_55AE0 = 0;
			}
			if (((*((lbl_1_bss_9F8) + (i))).a & 1) || ((*((lbl_1_bss_9F8) + (i))).b & 1)) {
				lbl_10_bss_55AE0 = 1;
			}
		}
	}
	m = (s32)(*((lbl_801A66A0) + (0))) - v;
	m = m * 21;
	n.value = 180;
	if ((u32)m <= 180) {
		n.value = m;
	}
	t = lbl_8006D188((s32)(182.04444885253906f * (f32)(u32)n.value));
	fn_10_18C54(0x26, arg1, 1, lbl_10_bss_55AE0 == 1 ? t : (*((lbl_10_rodata_1A4) + (0))));
	lab_t1 = arg1;
	fn_10_18A50_call_fn_10_18C54(0x26, lab_t1, 0, lbl_10_bss_55AE0 == 0 ? t : (*((lbl_10_rodata_1A4) + (0))));
}
#pragma opt_common_subs reset

