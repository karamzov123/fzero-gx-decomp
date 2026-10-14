/* Non-matching: best partial attempt (40.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_1_57DC0(u32 flags);
extern u32 GXLoadPosMtxImm(u32 mtx, u32 id);
extern void fn_8003462C(u32 size, u32 heap, u32 flags);
extern u32 *lbl_801A6D00;

typedef struct {
	f32 x;
	f32 y;
	f32 z;
} Vec3;

typedef union {
	u32 rgba;
	struct {
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	} c;
} Color;

/* vertex data is pushed into the graphics FIFO */
#define FIFO_F *(volatile f32 *)0xCC008000
#define FIFO_B *(volatile u8 *)0xCC008000

#pragma opt_propagation off

void fn_1_57810(u32 flags, Vec3 *pts, u32 *colorArg) {
	Color color;
	Vec3 *q;
	u32 i;
	u32 n;
	u32 f = flags;
	Vec3 *p = pts;
	u32 *ca = colorArg;

	if ((flags & 0xFFFF) < 2) {
		return;
	}
	fn_1_57DC0(flags);
	color.rgba = *ca;
	GXLoadPosMtxImm(*lbl_801A6D00, 0);
	fn_8003462C(0xB0, 0, f);
	n = f & 0xFFFF;
	q = p;
	if (n > 0) {
		for (i = n >> 2; i != 0; i--) {
			{
				f32 vx = q[0].x;
				f32 vy = q[0].y;
				f32 vz = q[0].z;
				FIFO_F = vx;
				FIFO_F = vy;
				FIFO_F = vz;
				FIFO_B = color.c.r;
				FIFO_B = color.c.g;
				FIFO_B = color.c.b;
				FIFO_B = color.c.a;
			}
			{
				f32 vx = q[1].x;
				f32 vy = q[1].y;
				f32 vz = q[1].z;
				FIFO_F = vx;
				FIFO_F = vy;
				FIFO_F = vz;
				FIFO_B = color.c.r;
				FIFO_B = color.c.g;
				FIFO_B = color.c.b;
				FIFO_B = color.c.a;
			}
			{
				f32 vx = q[2].x;
				f32 vy = q[2].y;
				f32 vz = q[2].z;
				FIFO_F = vx;
				FIFO_F = vy;
				FIFO_F = vz;
				FIFO_B = color.c.r;
				FIFO_B = color.c.g;
				FIFO_B = color.c.b;
				FIFO_B = color.c.a;
			}
			{
				f32 vx = q[3].x;
				f32 vy = q[3].y;
				f32 vz = q[3].z;
				FIFO_F = vx;
				FIFO_F = vy;
				FIFO_F = vz;
				FIFO_B = color.c.r;
				FIFO_B = color.c.g;
				FIFO_B = color.c.b;
				FIFO_B = color.c.a;
			}
			q += 4;
		}
		for (i = n & 3; i != 0; i--) {
			f32 vx = q[0].x;
			f32 vy = q[0].y;
			f32 vz = q[0].z;
			FIFO_F = vx;
			FIFO_F = vy;
			FIFO_F = vz;
			FIFO_B = color.c.r;
			FIFO_B = color.c.g;
			FIFO_B = color.c.b;
			FIFO_B = color.c.a;
			q += 1;
		}
	}
}
