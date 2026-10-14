/* Non-matching: best partial attempt (93.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/spline.h"
#include "rel/main_rel/bg_for.h"

typedef struct {
	u8 pad_0[0x20];
	u32 unk_20;
} Obj_E3324_E24;

typedef struct {
	u8 pad_0[3];
	u8 unk_3;
	u8 pad_4[0x34];
} Obj_E3324_E38;

typedef struct {
	u8 pad_0[0x1A8];
} Obj_E3324_E1A8;

extern s32 fn_1_7B054(void);
extern Obj_1_bss_84428 * fn_1_FB0A8(void);
extern void fn_1_E1C10(void);
extern s32 fn_1_E5430(s16);
extern void * fn_1_E54A8(s16, s16);
extern void fn_1_E1A00(void *, void *);
extern void fn_1_E2DCC(void);
extern void fn_1_E252C(s16, s16, void *);
extern void fn_1_E2AE8(void);
extern void fn_1_E5930(void *, u64);
extern const f32 lbl_1_rodata_6994;
extern f32 lbl_1_rodata_6998[13];
extern void fn_1_E87A4(f32, f32);
extern u8 lbl_1_bss_9C;

void fn_1_E3324(void) {
	Obj_1_bss_7AE88 *p = (Obj_1_bss_7AE88 *)&lbl_1_bss_7AE88;
	Obj_1_bss_3BE0_Target *t;
	Obj_E3324_E24 *a24;
	Obj_E3324_E38 *a38;
	Obj_E3324_E1A8 *a1a8;
	struct { u32 value; } key;
	s16 i;
	s16 j;
	u16 n;
	struct { u32 value; } count;
	Obj_1_bss_3BE0_Target * t_2;
	s32 tmp_fn_1_E5430;

	switch ((s32)((u8 *)&lbl_1_data_2B0D4)[(s16)fn_1_7B054()]) {
	case 13:
		p->unk_24 = fn_1_FB0A8()->unk_A;
		break;
	}
	t = lbl_1_bss_3BE0;
	p->unk_2C = 0;
	a24 = (Obj_E3324_E24 *)t->unk_A8;
	n = (s16)t->unk_A4;
	for (i = 0; i < n; i++) {
		if (a24[i].unk_20 & 0x80000000) {
			p->unk_2C++;
		}
	}
	if ((s16)fn_1_7B054() == 37) {
		t_2 = lbl_1_bss_3BE0;
		a38 = (Obj_E3324_E38 *)t_2->unk_B8;
		if (*(s16 *)&lbl_1_bss_960 == 9) {
			key.value = (u32)((u8 *)&lbl_1_bss_9C)[1];
		} else {
			key.value = 0;
		}
		count.value = 0;
		for (i = 0; i < (s32)t_2->unk_B4; i++) {
			if (((u32)a38[i].unk_3 & 0xF) == key.value) {
				count.value++;
			}
		}
		p->unk_C = count.value;
		p->unk_14 = 0;
	} else {
		p->unk_C = 0;
		p->unk_14 = lbl_1_bss_3BE0->unk_B4;
	}
	fn_1_E1C10();
	for (i = 0; i < 6; i++) {
		tmp_fn_1_E5430 = fn_1_E5430(i);
		n = (s16)tmp_fn_1_E5430;
		a1a8 = (Obj_E3324_E1A8 *)fn_1_E54A8(i, 0);
		for (j = 0; j < n; j++) {
			fn_1_E1A00(&a1a8[j], lbl_1_data_3DDA8);
		}
	}
	fn_1_E2DCC();
	for (i = 0; i < 6; i++) {
		tmp_fn_1_E5430 = fn_1_E5430(i);
		n = (s16)tmp_fn_1_E5430;
		a1a8 = (Obj_E3324_E1A8 *)fn_1_E54A8(i, 0);
		for (j = 0; j < n; j++) {
			fn_1_E252C(i, j, &a1a8[j]);
		}
	}
	fn_1_E2AE8();
	switch ((s32)((u8 *)&lbl_1_data_2B0D4)[(s16)fn_1_7B054()]) {
	case 13:
		for (j = 0; j < (s16)fn_1_E5430(4); j++) {
			fn_1_E5930(fn_1_E54A8(4, j), (u64)0);
		}
		break;
	}
	tmp_fn_1_E5430 = fn_1_E5430(2);
	if ((s16)tmp_fn_1_E5430) {
		fn_1_E87A4(lbl_1_rodata_6994, lbl_1_rodata_6998[0]);
		*(u32 *)((u8 *)p + 0x30) |= (u32)(s16)0x8000;
	} else {
		*(u32 *)((u8 *)p + 0x30) &= 0xFFFFFFFEu;
	}
}
