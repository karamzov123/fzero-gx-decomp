/* Non-matching: best partial attempt (85.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
	u8 unk_0;
	u8 pad_4[0xC];
	f32 unk_10;
	f32 unk_14;
	f32 unk_18;
	u8 pad_1C[0x24];
	f32 unk_40;
} Elem;

typedef struct {
	Elem *a;
	Elem *b;
	f32 d;
} Seg;

typedef struct {
	u8 pad_0[0x88];
	s32 unk_88;
} ModeObj;

typedef struct {
	u8 pad_0[0xC];
	ModeObj *unk_0c;
	u8 pad_10[8];
	u32 unk_18;
	u32 unk_1c;
	u8 pad_20[4];
	Elem *unk_24;
	Seg *unk_28;
} Mgr;

extern void fn_1_10846C(Mgr *);
extern void fn_1_128884(Elem *, Elem *, int);
extern f32 fn_1_1289BC(const Elem *, const Elem *);
extern u32 fn_1_4630(u32, u32, void *, u32);
extern u32 lbl_801A6410;
extern const f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20[14];
extern f64 lbl_1_rodata_7B08;

#pragma opt_common_subs off
static inline f32 fn_1_1145C8_array_read(s32 index, f32 *array) { return array[index]; }
#pragma opt_loop_invariants off
static inline Elem * fn_1_1145C8_read_pointer(Mgr * owner) { return owner->unk_24; }
static inline void fn_1_1145C8_call_fn_1_128884(Elem * a0, Elem * a1, int a2) { fn_1_128884(a0, a1, a2); }
void fn_1_1145C8(Mgr *self) {
    Elem * fzgx_live;
	Elem * p_2;
	u32 m;
    Elem * p_2_2;
	f32 zer;
	u32 j;
	u32 i;
	u32 off;
	u32 k;
	Elem *q;
    struct { u32 value; } b;
	Elem *row;
	u32 rows;
	u32 ns;
	f32 f;
	f64 neg;
	Elem *p;

	if (self == 0) {
		return;
	}
	fn_1_10846C(self);
	neg = lbl_1_rodata_7B1C;
	zer = fn_1_1145C8_array_read(0, lbl_1_rodata_7B20);
	fzgx_live = self->unk_24;
	p = fzgx_live;
	for (i = 0; i < self->unk_18; i++, p++) {
		if (p->unk_0 & 1) {
			p->unk_0 = 0;
			p->unk_40 = neg;
		} else {
			p->unk_0 = 1;
			p->unk_40 = zer;
		}
	}
	fzgx_live = fn_1_1145C8_read_pointer(self);
	p_2 = fzgx_live;
	off = 0;
	{
    u32 fzgx_loop_i_1204;
for (fzgx_loop_i_1204 = 0; fzgx_loop_i_1204 < self->unk_18; fzgx_loop_i_1204++, p_2++, off += 0x44) {
		if (self->unk_0c->unk_88 == 4 || self->unk_0c->unk_88 == 0x23) {
			for (j = fzgx_loop_i_1204 + 1, q = (Elem *)((u8 *)self->unk_24 + off + 0x44); j < self->unk_18; j++, q++) {
				if (p_2->unk_10 > q->unk_10) {
					fn_1_128884(p_2, q, 0x44);
				}
			}
		} else {
			for (j = fzgx_loop_i_1204 + 1, q = (Elem *)((u8 *)self->unk_24 + off + 0x44); j < self->unk_18; j++, q++) {
				if (p_2->unk_10 < q->unk_10) {
					fn_1_128884(p_2, q, 0x44);
				}
			}
		}
	}
    i = fzgx_loop_i_1204;
}
	rows = self->unk_18 / 5;
	for (b.value = 0, row = self->unk_24; b.value < rows; b.value++, row += 5) {
		f = -(f32)b.value / (f32)(rows - 1);
		row[0].unk_40 = f;
		row[1].unk_40 = f;
		row[2].unk_40 = f;
		row[3].unk_40 = f;
		row[4].unk_40 = f;
		p_2_2 = row;
		for (m = 0; m < 5; m++, p_2_2++) {
			for (k = m + 1, q = p_2_2 + 1; k < 5; k++, q++) {
				if (p_2_2->unk_18 > q->unk_18) {
					fn_1_1145C8_call_fn_1_128884(p_2_2, q, 0x44);
				}
			}
		}
	}
	self->unk_1c = self->unk_18 / 5 * 4 + (self->unk_18 / 5 - 1) * 5;
	self->unk_28 = (Seg *)fn_1_4630(lbl_801A6410, self->unk_1c * 12,
		&lbl_1_data_40530, 0x1563);
	ns = 0;
	fzgx_live = self->unk_24;
	p_2_2 = fzgx_live;
	for (i = 0; i < self->unk_18 - 1; i++, p_2_2++) {
		if ((i + 1) % 5) {
			self->unk_28[ns].a = p_2_2;
			self->unk_28[ns].b = p_2_2 + 1;
			self->unk_28[ns].d = fn_1_1289BC(p_2_2, p_2_2 + 1);
			ns++;
		}
	}
	fzgx_live = self->unk_24;
	p_2_2 = fzgx_live;
	for (i = 0; i < self->unk_18 - 5; i++, p_2_2++) {
		self->unk_28[ns].a = p_2_2;
		self->unk_28[ns].b = p_2_2 + 5;
		self->unk_28[ns].d = fn_1_1289BC(p_2_2, p_2_2 + 5);
		ns++;
	}
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
