/* Non-matching: best partial attempt (87.30% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

extern const f64 lbl_1_rodata_42F0;
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E8;
extern const f32 lbl_1_rodata_42F8;
extern void fn_8004D18C(void *handle, u32 value);
extern u32 fn_8004BF0C(void *handle, u32 value);

typedef struct {
	u8 pad_0[0x1C];
	u32 unk_1C;
	u8 pad_20[4];
	f32 unk_24;
	f32 unk_28;
	u8 unk_2C;
	u8 pad_2D[0xB];
	u32 unk_38;
	u8 pad_3C[0x846];
	u8 unk_882;
	s16 unk_884;
	s16 unk_886;
	f32 unk_888;
	f32 unk_88C;
} Obj_1_bss_6EA98;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_6EA98;
u8 lbl_1_bss_6EA98_fill_6EA99;
u16 lbl_1_bss_6EA98_fill_6EA9A;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EA98_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6EA98_gap_6EAA7;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&lbl_1_bss_6EA98_fill_6EA99;
    s = *(u8 *)&lbl_1_bss_6EA98_fill_6EA9A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6EA98_gap_6EAA7;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
static inline u32 fn_1_A176C_array_read(s32 index, u32 *array) { return array[index]; }
#pragma opt_lifetimes on
void fn_1_A176C(void *handle, s32 ch) {
    f32 fzgx_value_;
    f32 fzgx_value;
	Obj_1_bss_6EA98 *g = (Obj_1_bss_6EA98 *)(void *)(u32 *)&fzgx_obj_lbl_1_bss_6EA98;
	u32 *chans;
	u32 flags;
	u32 flags_2;
	u32 idx;

	if (g->unk_882 != 0) {
		return;
	}
	if (g->unk_2C != (u8)ch) {
		return;
	}
	if (handle != 0) {
		return;
	}
	if ((u32)handle + 0x10000u != 0xFFFFu) {
		return;
	}

	chans = (u32 *)(void *)g->unk_38;
	if ((u32)handle == fn_1_A176C_array_read(0, chans)) {
		flags = g->unk_1C;
		g->unk_1C = flags & 0x70000000u;
		if (flags & 0x80000000u) {
			g->unk_884 = ((s16 *)&lbl_1_data_2D93C)[(u8)ch];
		} else {
			g->unk_24 = lbl_1_rodata_42E0;
			g->unk_888 = (f32)(s32)((s16 *)&lbl_1_data_2D93C)[(u8)ch];
		}
	}
	if ((u32)handle == (*((chans) + (1)))) {
		flags = g->unk_1C;
		g->unk_1C = flags & 0x38000000u;
		if (flags & 0x40000000u) {
			((s16 *)&g->unk_884)[30] = ((s16 *)&lbl_1_data_2D93C)[(u8)ch];
		} else {
			g->unk_28 = lbl_1_rodata_42F8;
			g->unk_88C = (f32)(s32)((s16 *)&lbl_1_data_2D93C)[(u8)ch];
		}
	}

	idx = (u8)((u8)ch);
	fn_8004D18C(handle, ((u32 *)&lbl_1_data_2D7B8)[(u8)ch]);

	flags_2 = g->unk_1C;
	if (flags_2 & 0x40000000u) {
		if (flags_2 & 0x80000000u) {
			fzgx_value = lbl_1_rodata_42E8;
			fzgx_value_ = fzgx_value;
			g->unk_888 = fzgx_value_;
		}
		if (flags_2 & 0x40000000u) {
			g->unk_88C = lbl_1_rodata_42E8;
		}
		fn_8004BF0C(handle, 0xfffffe70u);
	} else {
		fn_8004BF0C(handle, (u32)((s16 *)&lbl_1_data_2D93C)[idx]);
	}
	g->unk_2C = (u8)ch;
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset

