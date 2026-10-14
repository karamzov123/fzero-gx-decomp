/* Non-matching: best partial attempt (90.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
	u8 pad_00[0x10];
	u32 unk_10;
	u8 pad_14[0xDC];
	u32 unk_F0;
} Obj_Bss_0;

typedef struct {
	u32 unk_0;
	u8 pad_4[2];
	u16 unk_6;
	u16 unk_8;
	u16 unk_A;
} Obj_F0;

typedef struct {
	u8 pad_00[0x324];
	u32 unk_324;
	u8 pad_328[0x43C];
	u32 unk_764;
	u8 pad_768[0x43C];
	u32 unk_BA4;
	u8 pad_BA8[0x43C];
	u32 unk_FE4;
	u8 pad_FE8[0x118];
} Obj_Block;

typedef struct {
	u8 pad_000[0x840];
	u32 unk_840;
	u32 unk_844;
	u32 unk_848;
	u32 unk_84C;
	u32 unk_850;
	u8 *unk_854;
	u8 pad_858[8];
	Obj_Block unk_860;
	u8 unk_1960[0x2880];
	u8 pad_41E0[0x190];
	u32 unk_4370;
} Obj_State;

typedef struct {
	u8 pad_00[0x2C];
	u16 width;
	u16 height;
	u8 pad_30[4];
	u32 arg34;
	u8 pad_38[0x28];
	u32 result;
} Obj_Record;

typedef struct {
	u8 pad_00[2];
	s16 unk_2;
	u8 pad_04[2];
	s16 unk_6;
	u8 pad_08[4];
} Obj_Info;

typedef struct {
	u32 unk_0;
	u32 unk_4;
	u32 unk_8;
} Obj_Quad;

typedef struct {
	u8 pad_00[0x48F8];
	u32 unk_48F8;
} Obj_7F0C0;

extern Obj_Bss_0 lbl_3_bss_0;
extern f32 lbl_3_rodata_0[17];
extern u8 lbl_3_data_0[];
extern u32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u32 lbl_801A66C8;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u16 lbl_1_bss_96A;
extern Obj_7F0C0 lbl_1_bss_7F0C0;

extern struct {
	u32 unk_0;
	u8 unk_4;
} lbl_1_bss_970;

extern void fn_80008BEC(void *, int, u32);
extern void fn_1_A0680(void);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, u32, u32, u32);
extern void fn_1_5124(u32, u32);
extern void fn_1_545B8(void);
extern void fn_80074CF4(f32, f32, f32);
extern void OSReport(const char *, ...);
extern void fn_3_1308C(u32, u32, u32);
extern void fn_3_11F60(u32, u32);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern void fn_1_8CED0(void *, u16, u16);
extern void fn_1_8D0A4(Obj_Record *);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u32 fn_1_7BA08(u16, u16, u16);
extern void fn_1_7BA48(void);
extern void fn_1_7BAF8(void);
extern void fn_3_5CE4(void *, void *);
extern s32 fn_1_465D0(void *, s32);
extern void fn_1_F8D5C(s16, void *);
extern int sprintf(char *, const char *, ...);
extern void * memset(void *, int, u32);

extern void fn_3_844(void);
extern void fn_3_8F8(void);
extern void fn_3_BA0(void);

void _prolog(u32 arg0) {
	Obj_State *st = (Obj_State *)((u8 *)&lbl_3_bss_0 + 0x20000);
	u8 *data = (u8 *)&lbl_3_data_0;
	f32 *ro = (f32 *)&lbl_3_rodata_0;
	Obj_Bss_0 *bss = (Obj_Bss_0 *)&lbl_3_bss_0;
	u16 i;
	Obj_Record *rec;
	s16 k;
	Obj_F0 *f0;
	u32 v;
	s16 j;
	char buf2[32];
	char buf1[32];
	Obj_Quad qb;
	Obj_Quad qa;
	Obj_Info info;

	fn_80008BEC(&st->unk_844, 0, 2);
	st->unk_848 = 1;
	fn_1_A0680();
	st->unk_84C = fn_1_45D0(lbl_801A6410, 0x9BC, data + 0x11DC, 0x3BA);
	st->unk_850 = fn_1_45D0(lbl_801A6410, 0x9BC, data + 0x11DC, 0x3BB);
	fn_1_3CF0(st->unk_84C, 0x20);
	fn_1_3CF0(st->unk_850, 0x20);
	lbl_1_bss_970.unk_0 = 0;
	lbl_1_bss_970.unk_4 = 0;
	fn_1_435C(st->unk_84C);
	fn_1_435C(st->unk_850);
	fn_1_3F8C(data + 0x11E8, (u32)fn_1_545B8, 0, 0xE);
	fn_1_5124(st->unk_84C, st->unk_850);
	fn_80074CF4(ro[16], ro[16], ro[16]);
	OSReport((char *)(data + 0x11F4), lbl_801A66C8);
	bss->unk_F0 |= 0x80000000;
	lbl_1_bss_96A = 0x5C;
	lbl_1_bss_7167C = (u32)fn_3_844;
	lbl_1_bss_71680 = (u32)fn_3_8F8;
	lbl_1_bss_71684 = (u32)fn_3_BA0;
	st->unk_854 = (u8 *)fn_1_45D0(lbl_801A6410, 0x10000 - 0x51C0, data + 0x11DC, 0x3ED);

	for (i = 0; i < 41; i++) {
		memset(st->unk_854 + i * 0x440, 0, 0x440);
		*(u32 *)(st->unk_854 + i * 0x440 + 0x324) = -1;
	}

	fn_80008BEC(&st->unk_860, 0, 0x1100);
	st->unk_860.unk_324 = -1;
	st->unk_860.unk_764 = -1;
	st->unk_860.unk_BA4 = -1;
	st->unk_860.unk_FE4 = -1;
	fn_80008BEC(st->unk_1960, 0, 0x2880);
	fn_3_1308C(st->unk_840, st->unk_84C, st->unk_850);
	fn_3_11F60(st->unk_84C, st->unk_850);

	rec = (Obj_Record *)((u8 *)st + 0x41E0);
	for (k = 0; (u32)k < 4; k++) {
		fn_1_8CED0(rec, fn_1_A5D88(), fn_1_A5DB0());
		fn_1_8D0A4(rec);
		rec = (Obj_Record *)((u8 *)rec + 0x64);
	}

	fn_1_47F74(0x9A);
	fn_1_47F74(0xA0);
	fn_1_47F74(0x89);
	fn_1_411A4(1);
	fn_1_411A4(3);
	bss->unk_10 = fn_1_45D0(lbl_801A6410, fn_1_7BA08(0x20, 0x20, 0x40), data + 0x11DC, 0x40F);
	fn_1_7BA48();
	fn_1_435C(st->unk_850);
	fn_1_3F8C(data + 0x120C, (u32)fn_1_7BAF8, bss->unk_10, 2);

	qa.unk_0 = ((u32 *)ro)[13];
	qa.unk_4 = ((u32 *)ro)[14];
	qa.unk_8 = ((u32 *)ro)[15];
	qb.unk_0 = ((u32 *)ro)[10];
	qb.unk_4 = ((u32 *)ro)[11];
	qb.unk_8 = ((u32 *)ro)[12];
	fn_3_5CE4(&qb, &qa);

	v = lbl_1_bss_7F0C0.unk_48F8;
	f0 = (Obj_F0 *)((u8 *)bss + 0xF0);
	f0->unk_6 = 0;
	f0->unk_8 = 0;
	f0->unk_A = lbl_801A66B4;
	if (v > 0x20000 - 0x7961) {
		v = 0x20000 - 0x7961;
	}
	st->unk_4370 = v;

	fn_1_465D0(data + 0x1164, 2);
	fn_1_465D0(data + 0x1180, 2);

	for (j = 0; j < 0x2C; j++) {
		fn_1_F8D5C(j, &info);
		if (info.unk_2 == 1 && info.unk_6 >= 0) {
			sprintf(buf1, (char *)(data + 0x11A0), (char *)(data + 0x11B4), info.unk_6);
			sprintf(buf2, (char *)(data + 0x11BC), (char *)(data + 0x11B4), info.unk_6);
			fn_1_465D0(buf1, 1);
			fn_1_465D0(buf2, 1);
		}
	}
}
