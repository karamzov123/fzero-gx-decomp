/* Non-matching: best partial attempt (93.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
	unsigned char pad[8];
	void **value;
} Inner;

typedef struct {
	s16 unk_0;
	unsigned char pad_2[0x226];
	void *unk_228;
	unsigned char pad_22C[0x10];
	void *unk_23C;
	unsigned char pad_240[0x104];
	Inner *inner;
	unsigned char pad_348[0x18];
} Record;

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(f32);
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_151C78(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);

#pragma opt_lifetimes off
#pragma opt_common_subs off
void fn_1_14E5E4(Record *arg0, s16 arg1, f32 arg2) {
	Record *base;
	void *hit1;
	void *hit2;
	void *value;
	Record *q;
	unsigned char *p;
	s16 i;
	s16 k;
	int same;
    int lab_t0;
    int lab_t0_;

	hit1 = 0;
	hit2 = 0;
	if (lbl_1_rodata_9C30 != arg2) {
		fn_1_55FF0(arg2);
	}
	base = (Record *)((unsigned char *)arg0 + arg1 * 4);
	p = (unsigned char *)arg0;
	q = base;
	for (i = 0; (u32)(s32)i < 3; i++) {
		if (fn_1_14F344(*(s16 *)p) == 0) {
			value = *q->inner->value;
			if (value != 0) {
				fn_80072558();
				lab_t0 = 0;
				lab_t0_ = lab_t0;
				fn_1_151C3C(lab_t0_, arg0[i].unk_0);
				fn_1_556B8(value);
				fn_1_151C78();
				for (i = 0; (u32)(s32)i < 3; i++) {
					if (fn_1_14F344(arg0[i].unk_0) == 0) {
						hit1 = &arg0[i].unk_23C;
						break;
					}
				}
				hit2 = 0;
				for (i = 0; (u32)(s32)i < 3; i++) {
					if (fn_1_14F344(arg0[i].unk_0) == 0) {
						hit2 = &arg0[i].unk_228;
						break;
					}
				}
			}
		}
		p += 0x360;
		q = (Record *)((unsigned char *)q + 0x360);
	}
	lbl_8006DAEC();
	same = (lbl_1_rodata_9C30 == arg2);
	if (hit1 != 0) {
		if (same == 0) {
			fn_1_55FF0(arg2);
		}
		for (k = 0; (u32)(s32)k < 3; k++) {
			if (fn_1_14F344(arg0[k].unk_0) == 1) {
				value = *base[k].inner->value;
				if (value != 0) {
					lbl_8006E0A4(hit1);
					fn_80072558();
					lab_t0 = 1;
					lab_t0_ = lab_t0;
					fn_1_151C3C(lab_t0_, arg0[k].unk_0);
					fn_1_556B8(value);
					fn_1_151C78();
				}
			}
		}
	}
	lbl_8006DBE4();
	same = (lbl_1_rodata_9C30 == arg2);
	if (hit2 != 0) {
		if (same == 0) {
			fn_1_55FF0(arg2);
		}
		for (k = 0; (u32)(s32)k < 3; k++) {
			if (fn_1_14F344(((k)[arg0]).unk_0) == 2) {
				value = *base[k].inner->value;
				if (value != 0) {
					lbl_8006E0A4(hit2);
					fn_80072558();
					lab_t0 = 2;
					lab_t0_ = lab_t0;
					fn_1_151C3C(lab_t0_, arg0[k].unk_0);
					fn_1_556B8(value);
					fn_1_151C78();
				}
			}
		}
	}
	lbl_8006DC20();
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset

