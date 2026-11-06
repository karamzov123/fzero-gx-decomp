#include "types.h"
#include "dol/globals.h"

u8 fzgx_obj_lbl_801932A8[0x60];
u8 fzgx_obj_lbl_80193308[0x60];
u8 fzgx_obj_lbl_80193368[0x9C];
u8 fzgx_obj_lbl_80193404[0x9C];
u8 fzgx_obj_lbl_801934A0[0x1E0];
u8 fzgx_obj_lbl_80193680[0x1E0];
u8 fzgx_obj_lbl_80193860[0x154];
u8 fzgx_obj_lbl_801939B4[0x154];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_801932A8;
    s = *(u8 *)&fzgx_obj_lbl_80193308;
    s = *(u8 *)&fzgx_obj_lbl_80193368;
    s = *(u8 *)&fzgx_obj_lbl_80193404;
    s = *(u8 *)&fzgx_obj_lbl_801934A0;
    s = *(u8 *)&fzgx_obj_lbl_80193680;
    s = *(u8 *)&fzgx_obj_lbl_80193860;
    s = *(u8 *)&fzgx_obj_lbl_801939B4;
}
#pragma section code_type ".text"

extern void fn_8005CBF4(u32);
extern void fn_800622B0(void);
extern s32 fn_80069CE4(u32, s32, s16);

extern u32 lbl_801A6410;
extern void fn_80008E5C(u32, u32);

extern u32 ARFree(u32 *);

extern char lbl_80092C18[29];
extern int sprintf(char *, const char *, ...);

extern u32 fn_80024DF0(void *);
extern u32 fn_80024378(void *);
extern s32 fn_800253F0(void *);
extern s16 fn_80025C70(void *);

extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);

typedef struct Base {
	u8 pad_000[0x100];
	u32 unk_100;
	u8 pad_104[0x138];
	s32 unk_23c;
	u8 pad_240[0x204];
	u32 unk_444;
	u8 pad_448[0xC];
	u32 unk_454;
	u8 pad_458[0x18];
	u8 unk_470;
	u8 unk_471;
} Base;


u32 fn_80067DE4(void) {
	Base *base;
	Base * base_2;
	u32 val;
	char buf[0x404];

	base = (Base *)lbl_801A6C80;
	base->unk_444 = 0xA0000110;

	fn_8005CBF4(0xA0000100);
	fn_800622B0();
	fn_80069CE4(0x10, 0xA0000500, 0);

	base_2 = (Base *)lbl_801A6C80;
	if (base_2->unk_454 == 0) {
		fn_80008E5C(lbl_801A6410, base_2->unk_100);
		ARFree(&val);
		base_2 = (Base *)lbl_801A6C80;
		if (base_2->unk_23c != val) {
			sprintf(buf, lbl_80092C18, val);
			return val;
		}
	}

	base_2 = (Base *)lbl_801A6C80;
	switch ((s32)base_2->unk_470) {
	case 0:
		fn_80024DF0(fzgx_obj_lbl_801939B4);
		break;
	case 1:
		fn_80024378(fzgx_obj_lbl_80193680);
		break;
	case 2:
		fn_800253F0(fzgx_obj_lbl_80193404);
		break;
	case 3:
		fn_80025C70(fzgx_obj_lbl_80193308);
		break;
	}
	fn_800211E0(0, 0);

	base_2 = (Base *)lbl_801A6C80;
	switch ((s32)base_2->unk_471) {
	case 0:
		fn_80024DF0(fzgx_obj_lbl_80193860);
		break;
	case 1:
		fn_80024378(fzgx_obj_lbl_801934A0);
		break;
	case 2:
		fn_800253F0(fzgx_obj_lbl_80193368);
		break;
	case 3:
		fn_80025C70(fzgx_obj_lbl_801932A8);
		break;
	}
	fn_800211EC(0, 0);
	return 0;
}
