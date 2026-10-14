/* Non-matching: best partial attempt (92.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/driver.h"

extern const f32 lbl_1_rodata_4CA8;
extern u32 fn_1_C3378(void);

typedef struct {
	u8 unk_0;
	s8 unk_1;
	u8 unk_2;
	u8 unk_3;
	u8 unk_4;
	u8 unk_5;
	u8 unk_6;
	u8 unk_7;
	s16 unk_8;
	s16 unk_A;
	s32 unk_C;
	u8 unk_10[0x14];
	s32 unk_24;
	u8 unk_28[2];
	u8 unk_2A;
	s8 unk_2B;
	u8 unk_2C[4];
	s32 unk_30;
	f32 unk_34;
	f32 unk_38;
	s32 unk_3C;
	s32 unk_40;
	u8 unk_44[4];
	s32 unk_48;
	s32 unk_4C;
	s32 unk_50;
	u8 unk_54[0x4C];
} Unk_1_AA590_Entry;

typedef struct {
	u8 unk_0[8];
	Unk_1_AA590_Entry unk_8[2];
	s32 unk_148;
	s32 unk_14C;
	Unk_1_AA590_Entry unk_150;
	u8 unk_1F0;
	u8 unk_1F1;
	u8 unk_1F2;
	u8 unk_1F3;
	s32 unk_1F4;
	u8 unk_1F8;
	u8 unk_1F9;
	u8 unk_1FA[2];
	s32 unk_1FC;
	s32 unk_200;
	u8 unk_204[0x1C];
	u8 unk_220[0x55C2];
	u8 unk_57E2[0x41E];
	s32 unk_5C00;
	s32 unk_5C04;
} Obj_1_bss_716C0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_716C0[2];
Unk_1_AA590_Entry fzgx_obj_lbl_1_bss_716C8[2];
s32 fzgx_obj_lbl_1_bss_71808;
s32 lbl_1_bss_7180C;
Unk_1_AA590_Entry lbl_1_bss_71810;
u8 lbl_1_bss_71810__fzgx_offset_A0;
u8 fzgx_obj_lbl_1_bss_718B1;
u8 fzgx_pool_lbl_1_bss_716C0_gap_718B2;
u8 fzgx_pool_lbl_1_bss_716C0_gap_718B2_fill_718B3;
s32 fzgx_obj_lbl_1_bss_718B4;
u8 lbl_1_bss_718B8;
u8 lbl_1_bss_718B9;
u16 lbl_1_bss_718B9__fzgx_offset_1;
s32 lbl_1_bss_718B9__fzgx_offset_3;
s32 fzgx_obj_lbl_1_bss_718C0;
u32 lbl_1_bss_718C0__fzgx_offset_4[7];
u8 fzgx_obj_lbl_1_bss_718E0[0x55C2];
u16 lbl_1_bss_718E0__fzgx_offset_55C2;
u32 lbl_1_bss_718E0__fzgx_offset_55C4[263];
s16 lbl_1_bss_718E0__fzgx_offset_59E0;
u32 lbl_1_bss_718E0__fzgx_offset_59E4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_716C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_71808;
    s = *(u8 *)&lbl_1_bss_7180C;
    s = *(u8 *)&lbl_1_bss_71810;
    s = *(u8 *)&lbl_1_bss_71810__fzgx_offset_A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718B1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_716C0_gap_718B2;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_716C0_gap_718B2_fill_718B3;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718B4;
    s = *(u8 *)&lbl_1_bss_718B8;
    s = *(u8 *)&lbl_1_bss_718B9;
    s = *(u8 *)&lbl_1_bss_718B9__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_718B9__fzgx_offset_3;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718C0;
    s = *(u8 *)&lbl_1_bss_718C0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_718E0;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_55C2;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_55C4;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_59E0;
    s = *(u8 *)&lbl_1_bss_718E0__fzgx_offset_59E4;
}
#pragma section code_type ".text"

#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_AA590(void) {

	s32 i;
	Unk_1_AA590_Entry *e;
	struct {
    u8 _pad_pre[0x1];
		u8 *value;
	} mgr;

	e = fzgx_obj_lbl_1_bss_716C8;
	fzgx_obj_lbl_1_bss_71808 = 0;
	lbl_1_bss_7180C = 1;

	for (i = 0; i < 2; i++) {
		e->unk_C = 0;
		e->unk_24 = 0;
		e->unk_0 = i;
		e->unk_2 = 0xFF;
		e->unk_3 = 0xFF;
		e->unk_4 = 0xFF;
		e->unk_5 = 0xFF;
		e->unk_6 = 0xFF;
		e->unk_7 = 0;
		e->unk_8 = -1;
		e->unk_A = -1;
		e->unk_30 = 0;
		e->unk_34 = lbl_1_rodata_4CA8;
		e->unk_38 = lbl_1_rodata_4CA8;
		e->unk_2A = 0;
		e->unk_1 = -3;
		e->unk_2B = -3;
		e->unk_3C = -1;
		e->unk_40 = -1;
		e->unk_4C = 0;
		e->unk_48 = 0;
		e->unk_50 = 0;
		e++;
	}

	lbl_1_bss_71810 = (*((fzgx_obj_lbl_1_bss_716C8) + (0)));

	lbl_1_bss_71810.unk_0 = 2;
	lbl_1_bss_71810__fzgx_offset_A0 = 0xFF;
	fzgx_obj_lbl_1_bss_718B1 = 5;
	fzgx_pool_lbl_1_bss_716C0_gap_718B2 = 0xFF;
	fzgx_obj_lbl_1_bss_718B4 = 0;
	lbl_1_bss_718B8 = 0;
	lbl_1_bss_718B9 = 0;
	lbl_1_bss_718B9__fzgx_offset_3 = 0;

	fn_1_C3378();

	mgr.value = &fzgx_obj_lbl_1_bss_718E0[0];
	lbl_1_data_3C1E4 = 100;
	fzgx_obj_lbl_1_bss_718C0 = (s32)(u32)(mgr.value + 0x55C2);
	*(volatile s32 *)&lbl_1_bss_718E0__fzgx_offset_59E0 = -1;
	mgr.value = (u8 *)&lbl_1_bss_718E0__fzgx_offset_59E0;
	*(s32 *)(mgr.value + 4) = -1;
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

#pragma opt_loop_invariants reset

