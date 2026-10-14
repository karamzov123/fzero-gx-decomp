/* Non-matching: best partial attempt (86.54% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

struct obj_81164 {
	u32 unk_0;
    u8 fzgx_pad_before_unk_8[0x4];
	u32 unk_8;
};

struct car_81164 {
	u8 pad_0[0x328];
	u8 unk_328;
	u8 pad_329[0x53];
	u32 unk_37c[5];
	u32 unk_390;
	u8 pad_394[0x14];
	u32 unk_3a8;
	u8 pad_3ac[0xC];
	u16 unk_3b8;
};

extern void fn_80006E10(void *);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern u32 fn_1_D3884(void *);
extern u32 fn_80077D40(void *);
extern u32 fn_80071470(void *, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80071718(void *);

#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_1_81164(struct car_81164 *self, u16 arg1, u32 arg2) {
	u8 *base = (u8 *)&lbl_1_data_1F1D8;
	s8 idx;
	u32 *pb;
	s32 flag;
	u32 t1;
	struct obj_81164 *obj;
	u32 *pa;
	u32 t2;
	char buf[0x48];
	u32 * tmp_cse1;
    void * lab_t0;
	s32 a, b, qa, qb, ra, rb;

	if (self->unk_390 & 0x20) {
		self->unk_3b8 = arg2;
		return;
	}
	a = (s16)arg1;
	b = (s16)arg2;
	if (a == b) {
		return;
	}
	qa = a / 4;
	qb = b / 4;
	ra = a % 4;
	rb = b % 4;
	if (qa != qb) {
		return;
	}
	pa = &self->unk_37c[ra];
	if (*pa != 0) {
		return;
	}
	pb = &self->unk_37c[rb];
	(void) pb;  /* fzgx: keeps the web at its definition */
	if (*pb != 0) {
		return;
	}
	lab_t0 = (void *)(base + 0xe0c);
	flag = 0;
	fn_80006E10(lab_t0);
	if (self->unk_390 & 0x800) {
		flag = 1;
	}
	idx = (s8)self->unk_328;
	tmp_cse1 = (u32 *)(base + 0x324);
	fn_80083DB0(buf, (const char *)(*((tmp_cse1) + (idx))));
	if (flag == 1) {
		switch (idx) {
		case 0:
			fn_80083DB0(buf, (const char *)(base + 0x13E4));
			break;
		case 1:
			fn_80083DB0(buf, (const char *)(base + 0x13EC));
			break;
		case 6:
			fn_80083DB0(buf, (const char *)(base + 0x13F4));
			break;
		}
	}
	fn_80006E10(buf);
	idx = (s8)self->unk_328;
	fn_80083DB0(buf, (const char *)(*((tmp_cse1) + (idx))));
	if (flag == 1) {
		switch (idx) {
		case 0:
			fn_80083DB0(buf, (const char *)(base + 0x13E4));
			break;
		case 1:
			fn_80083DB0(buf, (const char *)(base + 0x13EC));
			break;
		case 6:
			fn_80083DB0(buf, (const char *)(base + 0x13F4));
			break;
		}
	}
	if ((arg2 & 0xFF) != 0) {
		if ((arg2 & 0xFF) >= 4) {
			sprintf(buf, (const char *)(base + 0x1358), buf, (arg2 & 0xFF) - 4);
		} else {
			sprintf(buf, (const char *)(base + 0x1364), buf);
		}
	} else {
		sprintf(buf, (const char *)(base + 0x1370), buf);
	}
	obj = (struct obj_81164 *)fn_1_D3884(buf);
	fn_80006E10((void *)(base + 0x147c));
	self->unk_3a8 = fn_80077D40(obj);
	t1 = fn_80071470((void *)obj->unk_8, 0);
	t2 = fn_80071470((void *)((struct obj_81164 *)(*pa))->unk_8, 0);
	fn_80008BA8(t2, t1, self->unk_3a8);
	fn_80071718(obj);
	*pb = *pa;
	*pa = 0;
	self->unk_3b8 = arg2;
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

