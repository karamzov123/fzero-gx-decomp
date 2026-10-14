/* Non-matching: best partial attempt (97.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
	u32 unk_0;
	f32 unk_4;
	f32 unk_8;
	f32 unk_C;
	u8 pad_10[0x20];
	s32 unk_30;
	u8 pad_34[0x4];
	u8 unk_38;
	u8 unk_39;
	u8 unk_3A;
	u8 pad_3B;
	u8 unk_3C;
	u8 unk_3D;
	u8 unk_3E;
	u8 pad_3F[0x19];
} Pkt;

typedef struct {
	u8 a;
	u8 b;
	u8 c;
	u8 d;
} Quad;

typedef struct {
	u8 pad_0[8];
	u16 unk_8;
	u8 pad_A[0xA];
} E9F8;

extern u32 lbl_801A66A0;
extern u32 lbl_1_bss_8E424;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_8658;
extern f32 lbl_1_rodata_92B8[2];
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8B2C;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_9164;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8D9C;
extern const f32 lbl_1_rodata_8960;
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87F4;
extern const f32 lbl_1_rodata_85F0;
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(void *);
extern void fn_1_49528(u32 *);
extern void fn_1_4A0D8(const char *);
extern u8 fn_1_F8CF0(s32);

void fn_1_141C10(u32 arg0, f32 arg1) {
	s32 flag1 = 0;
	s32 flag2 = 0;
	u8 idx;
	u32 n;
	E9F8 *p9F8;
	Pkt pkt;
	Quad y;
	u32 x;

	n = lbl_1_bss_8B3A0.unk_9E;
	p9F8 = (E9F8 *)&lbl_1_bss_9F8;
	if ((p9F8[n].unk_8 >> 4) & 1) {
		lbl_1_bss_8E424 = lbl_801A66A0;
	}
	idx = arg0;
	if (lbl_1_data_2B0D4.pad_0[idx] == 1 || lbl_1_data_2B0D4.pad_0[idx] == 0x11) {
		if (fn_1_F8CF0(0)) {
			flag1 = 1;
			if (lbl_1_bss_8B5F0 == 1) {
				flag2 = 1;
			} else {
				flag2 = 0;
			}
		}
	}
	if (lbl_1_data_2B0D4.pad_0[idx] == 4) {
		if (fn_1_F8CF0(1)) {
			flag1 = 1;
			if (lbl_1_bss_8B5F1 == 1) {
				flag2 = 1;
			} else {
				flag2 = 0;
			}
		}
	}
	if (flag1) {
		u32 d;
		u32 e;
		f32 t;

		pkt = *(Pkt *)lbl_1_rodata_26F8;
		pkt.unk_0 = 0xA10B;
		pkt.unk_4 = lbl_1_rodata_8658;
		pkt.unk_8 = lbl_1_rodata_92B8[0];
		pkt.unk_C = lbl_1_rodata_8B84;
		pkt.unk_30 = 10;
		if (!flag2) {
			pkt.unk_38 = pkt.unk_39 = pkt.unk_3A = 128;
		}
		if (flag2) {
			d = *(u32 *)&lbl_801A66A0 - lbl_1_bss_8E424;
			if (d < 15) {
				t = lbl_8006D188((s32)(lbl_1_rodata_9164 + lbl_1_rodata_8B2C * (f32)(s32)((s32)d % 60) / lbl_1_rodata_8B30));
				pkt.unk_3C = pkt.unk_3D = pkt.unk_3E = (s32)(lbl_1_rodata_8D9C * t);
			}
		}
		fn_1_4F734((FontDrawPacket *)&pkt);
		fn_1_49410();
		fn_1_496FC(lbl_1_rodata_8658, lbl_1_rodata_8960);
		fn_1_4954C(lbl_1_rodata_8A54);
		fn_1_495C8((void *)9);
		if (!flag2) {
			f32 a;
			e = lbl_1_bss_8E424;
			d = lbl_801A66A0 - e;
			t = lbl_8006D188((s32)(lbl_1_rodata_9164 + lbl_1_rodata_8B2C * (f32)(s32)((s32)d % 60) / lbl_1_rodata_8B30));
			a = lbl_1_rodata_863C + t;
			a = lbl_1_rodata_87F4 * a;
			y.d = 0;
			y.a = y.b = y.c = (s32)(a * lbl_1_rodata_85F0);
			x = *(u32 *)&y;
			fn_1_49528(&x);
		}
		fn_1_4A0D8((const char *)lbl_1_data_41B3C);
	}
}
