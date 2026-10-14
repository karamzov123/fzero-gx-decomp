/* Non-matching: best partial attempt (80.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "psvec.h"

extern void fn_8006E2B0(void *in, void *out);

typedef struct {
	f32 x;
	f32 y;
	f32 z;
} Vec3;

typedef struct {
	Vec3 a;
	Vec3 r;
	Vec3 b;
	Vec3 o;
} S;

typedef struct {
	u8 pad_0[0x8];
	f32 unk_8;
	u8 pad_c[0x70];
	u32 unk_7c;
	u32 unk_80;
	u32 unk_84;
	u8 pad_88[0x18];
	Vec3 unk_a0;
	u8 pad_ac[0x178];
	u32 unk_224;
} St;

void fn_1_2B524(St *p) {
	S s;
	u32 h;
	f32 y;
	f32 t;

	h = p->unk_7c ^ p->unk_80 ^ p->unk_84 ^ p->unk_224;
	t = (f32)(2.0f * ((f32)(u16)(h ^ *(u32 *)&p->unk_a0.x) / 65536.0f)) - 1.0f;
	y = (f32)(1.5f * ((f32)(u16)(h ^ *(u32 *)&p->unk_a0.y) / 65536.0f));
	s.b.z = 0.5f + y;
	s.b.x = (t > 0.0f) ? (t + 0.5f) : (t - 0.5f);
	s.o.x = 0.0f;
	s.o.y = 0.0162037037037037037 * p->unk_8;
	s.o.z = 0.0f;
	s.b.y = 0.0f;
	fn_8006E2B0(&s.o, &s);
	s.r.x = (f32)(s.b.y * s.a.z) - s.b.z * s.a.y;
	s.r.y = (f32)(s.b.z * s.a.x) - s.b.x * s.a.z;
	s.r.z = (f32)(s.b.x * s.a.y) - s.b.y * s.a.x;
	psvec_add(&p->unk_a0, &s.r, &p->unk_a0);
}
