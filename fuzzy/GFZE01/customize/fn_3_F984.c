/* Non-matching: best partial attempt (97.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/emb_paste_editor.h"

extern u8 lbl_3_bss_9F664;
extern u8 lbl_3_bss_9F665[43];
extern u8 lbl_1_bss_77380[];
extern u32 lbl_801A6410;
extern void fn_1_B9BE0(void);
extern u8 fn_1_B7C00(void);
extern int fn_1_B7E98(int);
extern void fn_1_B9CCC(s32, u32);
extern int fn_1_B7CD4(void);
extern s32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_1_B9C0C(void);
extern void fn_1_FE004(void);

#define PA1(s) (*(volatile u32 *)((u8 *)(s) + 0x8))
#define FL1(s) (*(u32 *)((u8 *)(s) + 0x4))
#define PA2(s) (*(volatile u32 *)((u8 *)(s) + 0x14))
#define FL2(s) (*(u32 *)((u8 *)(s) + 0x10))

static inline u32 fn_3_F984_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_propagation off
void fn_3_F984(void) {
	u8 *sp;
	struct { Obj_3_bss_87000 *value; } st;
	struct { u8 value; } count;
	struct { u8 value; } i;
	struct { u32 value; } k;
	u16 v;
	u8 s1;
	u8 s2;

	if (lbl_3_bss_9F664 == 0) {
		fn_1_B9BE0();
		lbl_3_bss_9F664 = 1;
		return;
	}
	if ((fn_1_B7C00() & 0xFF) != 0) {
		return;
	}
	sp = &lbl_3_data_32F0;
	if (fn_3_F984_array_read(0, sp) < 2) {
		if (fn_1_B7E98(0) != 0) {
			if (lbl_3_data_32F0 == 0) {
				fn_1_B9CCC(0, 0x10);
				s1 = 1;
				lbl_3_data_32F0 = s1;
			} else if ((fn_1_B7CD4() != 0) && (lbl_3_data_32F0 == 1)) {
				count.value = 0;
				st.value = &lbl_3_bss_87000;
				for (i.value = 0; i.value < 0x80; i.value++) {
					k.value = i.value;
					if (*(u32 *)(lbl_1_bss_77380 + k.value * 0x30 + 0x24) == 0 || *(u32 *)(lbl_1_bss_77380 + k.value * 0x30 + 0x2C) == 0) {
						((u32 *)PA1(st.value))[k.value] = 0;
					} else {
						((u32 *)PA1(st.value))[k.value] = fn_1_45D0(lbl_801A6410, 0x2000, lbl_3_data_32DC, 0x61B);
						fn_80008BA8(((u32 *)PA1(st.value))[k.value], *(u32 *)(lbl_1_bss_77380 + k.value * 0x30 + 0x2C), 0x2000);
						*(volatile u8 *)((u8 *)FL1(st.value) + k.value) = 1;
						count.value++;
					}
				}
				v = (count.value < 9) ? 9 : ((count.value > 0x80) ? 0x80 : count.value);
				s1 = 2;
				lbl_3_bss_87000.unk_0 = v;
				lbl_3_data_32F0 = s1;
			} else {
				lbl_3_bss_87000.unk_0 = 9;
				s1 = 2;
			}
		} else {
			s1 = 2;
		}
		lbl_3_data_32F0 = s1;
	} else if (fn_3_F984_array_read(1, sp) < 2) {
		if (fn_1_B7E98(1) != 0) {
			if (fn_3_F984_array_read(1, sp) == 0) {
				fn_1_B9CCC(1, 0x10);
				s2 = 1;
				sp[1] = s2;
			} else if ((fn_1_B7CD4() != 0) && (fn_3_F984_array_read(1, sp) == 1)) {
				count.value = 0;
				st.value = &lbl_3_bss_87000;
				for (i.value = 0; i.value < 0x80; i.value++) {
					k.value = i.value;
					if (*(u32 *)(lbl_1_bss_77380 + k.value * 0x30 + 0x1824) == 0 || *(u32 *)(lbl_1_bss_77380 + k.value * 0x30 + 0x182C) == 0) {
						((u32 *)PA2(st.value))[k.value] = 0;
					} else {
						((u32 *)PA2(st.value))[k.value] = fn_1_45D0(lbl_801A6410, 0x2000, lbl_3_data_32DC, 0x61B);
						fn_80008BA8(((u32 *)PA2(st.value))[k.value], *(u32 *)(lbl_1_bss_77380 + k.value * 0x30 + 0x182C), 0x2000);
						*(volatile u8 *)((u8 *)FL2(st.value) + k.value) = 1;
						count.value++;
					}
				}
				v = (count.value < 9) ? 9 : ((count.value > 0x80) ? 0x80 : count.value);
				s2 = 2;
				sp[1] = s2;
				*(u16 *)((u8 *)&lbl_3_bss_87000 + 0xC) = v;
			} else {
				*(u16 *)((u8 *)&lbl_3_bss_87000 + 0xC) = 9;
				s2 = 2;
			}
		} else {
			s2 = 2;
		}
		sp[1] = s2;
	} else {
		if (fn_3_F984_array_read(0, lbl_3_bss_9F665) == 0) {
			fn_1_B9C0C();
			lbl_3_bss_9F665[0] = 1;
		} else {
			sp[1] = 0;
			sp[0] = 0;
			lbl_3_bss_7EDD8.unk_C = 0x40000000;
			lbl_3_bss_9F664 = 0;
			lbl_3_bss_9F665[0] = 0;
			fn_1_FE004();
		}
	}
}
#pragma opt_propagation reset
