/* Non-matching: best partial attempt (97.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/shadowmap.h"

extern void fn_800746A8(u32, u32);
extern void fn_8007245C(u32);
extern void fn_800728A8(u32, u32, u32, u32);
extern void fn_800720B0(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, u32);
extern void fn_80073C6C(u32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void GXLoadPosMtxImm(void *, int);
extern void fn_8003462C(u32, u32, u32);

typedef struct {
	u8 pad_0[8];
	f32 posMtx[12];
	u32 unk_38;
	u16 unk_3C;
	u16 unk_3E;
	void *unk_40;
	Obj_1_data_1C670 state;
} ShadowArg;

typedef struct {
	f32 x;
	f32 y;
	f32 z;
	u8 c0;
	u8 c1;
	u8 c2;
	u8 c3;
	f32 nx;
	f32 ny;
	f32 nz;
	u8 d0;
	u8 d1;
	u8 d2;
	u8 d3;
} ShadowVtx;

typedef struct {
	f32 x;
	f32 y;
	f32 z;
	u8 c0;
	u8 c1;
	u8 c2;
	u8 c3;
} ShadowVtx16;

typedef union {
	f32 f;
	u8 b[4];
} FifoSlot;

#define FIFO_F(v) (fifo->f = (v))
#define FIFO_B(v) (fifo->b[0] = (v))

#pragma opt_dead_assignments off
void fn_1_57E84(ShadowArg *arg) {
    f32 fzgx_live;
    u8 cb_2;
	Obj_1_data_1C670 sv;
    u8 ca_2;
	u8 dg;
	s32 i;
	s32 j;
	ShadowVtx *p;
	volatile FifoSlot *fifo;
	f32 fx;
	f32 fy;
	f32 fz;
	u8 cr;
	u8 cg;
	u8 cb;
	u8 ca;
	f32 nx;
	f32 ny;
	f32 nz;
	u8 dr;
	u32 n;
	u8 db;
	u8 da;

	sv = lbl_1_data_1C670;
	lbl_1_data_1C670 = arg->state;
	fn_800746A8(lbl_1_data_1C670.unk_0, arg->state.unk_14);
	fn_8007245C(0xa00);
	fn_800728A8(lbl_1_data_1C670.unk_4, lbl_1_data_1C670.unk_8,
	            lbl_1_data_1C670.unk_C, lbl_1_data_1C670.unk_10);
	fn_800720B0(0);
	fn_800747D0(4, 0, 1, 1, 0, 2, 1);
	fn_800734A8(0, 0xff, 0xff, 4);
	fn_80072EDC(0, 4);
	fn_80073C6C(0);
	fn_80073678(1);
	fn_80074660(0);
	fn_80073898(0);
	fn_80074788(1);
	fn_80074918(1, 3, 1);
	GXLoadPosMtxImm(arg->posMtx, 0);
	fn_8003462C(arg->unk_38, 0, arg->unk_3C);
	n = arg->unk_3C;
	fifo = (volatile FifoSlot *)0xCC008000;
	p = (ShadowVtx *)arg->unk_40;
	if ((s32)n > 0) {
		for (i = n >> 1; i != 0; i--) {
			fz = p->z;
			fy = p->y;
			fx = p->x;
			FIFO_F(fx);
			FIFO_F(fy);
			FIFO_F(fz);
			ca = p->c3;
			cb = p->c2;
			cg = p->c1;
			cr = p->c0;
			FIFO_B(cr);
			FIFO_B(cg);
			FIFO_B(cb);
			FIFO_B(ca);
			nz = p->nz;
			ny = p->ny;
			nx = p->nx;
			FIFO_F(nx);
			FIFO_F(ny);
			FIFO_F(nz);
			da = p->d3;
			db = p->d2;
			dg = p->d1;
			dr = p->d0;
			FIFO_B(dr);
			FIFO_B(dg);
			FIFO_B(db);
			FIFO_B(da);
			p = (ShadowVtx *)((u8 *)p + 0x20);
		}
		j = n & 1;
		if (j != 0) {
			do {
				ShadowVtx16 *q = (ShadowVtx16 *)p;
				fzgx_live = q->z;
				fz = fzgx_live;
				fy = q->y;
				fx = q->x;
				FIFO_F(fx);
				FIFO_F(fy);
				FIFO_F(fz);
				ca_2 = q->c3;
				cb_2 = q->c2;
				cg = q->c1;
				cr = q->c0;
				FIFO_B(cr);
				FIFO_B(cg);
				FIFO_B(cb_2);
				FIFO_B(ca_2);
				p = (ShadowVtx *)((u8 *)p + 0x10);
			} while (--j != 0);
		}
	}
	lbl_1_data_1C670 = sv;
}
#pragma opt_dead_assignments reset

