/* Non-matching: best partial attempt (74.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct Pool158 {
	u8 pad_0[0x44];
	f32 f44;
	u8 pad_48[0x40];
	f64 f88;
	u8 pad_90[0xA4];
	f32 f134;
	u8 pad_138[0x68];
	f32 f1A0;
	u8 pad_1A4[0xF8];
	f32 f29C;
	u8 pad_2A0[4];
	f32 f2A4;
	u8 pad_2A8[0x298];
	f32 f540;
	u8 pad_544[0x2B4];
	u32 f7F8;
	f32 f7FC;
	f32 f800;
};

extern struct Pool158 lbl_10_rodata_158;
extern int fn_1_4F734(FontDrawPacket *);

struct Pkt {
	u32 f00;
	u32 f04;
	f32 f08;
	f32 f0c;
	f32 f10;
	f32 f14;
	f32 f18;
	u8 pad_1c[0x18];
	u32 f34;
	u32 f38;
	u32 f3c;
	u8 b40[3];
	u8 pad_43[0x15];
};

extern const struct Pkt lbl_1_rodata_26F8;

void fn_10_18C54(s32 a0, s32 a1, s32 a2, f32 a3) {
	struct Pkt p;
	f32 x;
	f32 w;

	p = lbl_1_rodata_26F8;
	p.f04 = 0x9A00;
	p.f10 = lbl_10_rodata_158.f134;
	p.f0c = (f32)a1;
	p.f3c = lbl_10_rodata_158.f7F8;
	p.f14 = p.f14 * ((f32)(lbl_10_rodata_158.f7FC * a3) + lbl_10_rodata_158.f44);
	p.f18 = p.f18 * ((f32)(lbl_10_rodata_158.f7FC * a3) + lbl_10_rodata_158.f44);
	p.b40[0] = p.b40[1] = p.b40[2] = (s32)(lbl_10_rodata_158.f800 * a3);
	if (a2 != 0) {
		p.f34 = 0x800A;
		x = (f32)a0;
		p.f08 = x;
		w = 10.0f * (72.0f * a3 / 255.0f);
		p.f08 = x - w;
	} else {
		p.f34 = 0xA;
		x = 640.0f - (f32)a0;
		p.f08 = x;
		w = 10.0f * (72.0f * a3 / 255.0f);
		p.f08 = x + w;
	}
	fn_1_4F734((FontDrawPacket *)&p);
}
