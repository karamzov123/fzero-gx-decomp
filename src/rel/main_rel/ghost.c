#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"

extern void fn_1_F23E8(void);
extern void fn_1_EE530(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(Obj_1_bss_7ECB4 *obj);
extern u8 lbl_1_bss_7EA00[56];
extern int fn_1_B7CD4(void);
extern int fn_1_B7C5C(void);
extern u32 lbl_1_bss_7B19C[2];
extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_C1394(void);
extern void OSReport(const char *, ...);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern const f32 lbl_1_rodata_6D20;
extern const f32 lbl_1_rodata_6D24;
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(s32);
extern s32 lbl_1_bss_7B198;
extern void fn_1_4AE0C(void *, ...);
extern u8 lbl_1_bss_7C8CE[70];
extern void fn_1_F1D70(void);
extern u32 lbl_1_bss_7EA38[159];
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6D10;
extern const f32 lbl_1_rodata_6D44;
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_F1950(void);
extern u32 fn_8002071C(void *arg);
extern void fn_800206FC(u32 arg);
extern u32 ARGetDMAStatus(void);
extern void DCFlushRange(void *addr, u32 size);
extern u32 lbl_1_bss_7C848[2];
extern u8 lbl_1_bss_7C8CD;
extern u32 lbl_1_bss_7C948;
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern u32 lbl_1_bss_7B190[2];
extern u32 lbl_1_bss_7ED58[158];

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void OSReport(const char *, ...);
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern f64 lbl_1_rodata_6C88;
extern void fn_80008BA8(u32 *out, const void *value, s32 size);
extern s32 fn_1_F21B8(s32 arg);
extern void fn_1_F0D10(s32, void *);
extern void fn_1_F0B5C(s32, void *);
extern void fn_1_F0E00(s32, void *);
extern s32 fn_1_3F164(void);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);
extern u32 lbl_1_bss_7C914[13];
extern const f32 lbl_1_rodata_6D38;
extern const f32 lbl_1_rodata_6D3C;
extern const f32 lbl_1_rodata_6D40;
extern void lbl_8006DD14(void *a, void *b);
extern f32 lbl_8006D0B4(f32 x);
extern void lbl_8006D7DC(void *a);
extern void lbl_8006DFC4(void *a);
extern void lbl_8006DB74(void *a);
extern const f32 lbl_1_rodata_6BBC;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6D48;
extern const f32 lbl_1_rodata_6D50;
extern f64 fn_80088598(f64, f64);

/* fzgx:begin fn_1_EB330 noprologue */
#include "types.h"
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E62C[128];
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern s32 fn_1_B7E98(s32);
extern void fn_1_B9C0C(void);
extern void fn_1_B9BE0(void);
extern void fn_1_AA6D8(s32, s32, void *);
extern void fn_1_F1D70(void);
extern void fn_80008BEC(void *, s32, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
s32 fzgx_obj_lbl_1_bss_7B1A4;
u32 lbl_1_bss_7B1A4__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7B1AC;
u8 lbl_1_bss_7B1AC__fzgx_offset_1;
u16 lbl_1_bss_7B1AC__fzgx_offset_2;
u32 lbl_1_bss_7B1AC__fzgx_offset_4[1269];
u8 fzgx_obj_lbl_1_bss_7C584;
u8 lbl_1_bss_7C584__fzgx_offset_1;
u16 lbl_1_bss_7C584__fzgx_offset_2;
u32 lbl_1_bss_7C584__fzgx_offset_4[176];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 lbl_1_bss_7E9E8__fzgx_offset_0[4];
s32 lbl_1_bss_7E9E8__fzgx_offset_10;
s32 lbl_1_bss_7E9E8__fzgx_offset_14;
u8 lbl_1_bss_7EA00;
u8 lbl_1_bss_7EA00__fzgx_offset_1;
u16 lbl_1_bss_7EA00__fzgx_offset_2;
s32 lbl_1_bss_7EA00__fzgx_offset_4;
s32 lbl_1_bss_7EA00__fzgx_offset_8;
u8 lbl_1_bss_7EA00__fzgx_offset_C;
u8 lbl_1_bss_7EA00__fzgx_offset_D;
u16 lbl_1_bss_7EA00__fzgx_offset_E;
s32 lbl_1_bss_7EA00__fzgx_offset_10;
u32 lbl_1_bss_7EA00__fzgx_offset_14[9];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&lbl_1_bss_7B1A4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_D;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_14;
}
#pragma section code_type ".text"

void fn_1_EB330(void) {
    
    u8 *entry = (u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s32 i;
    u8 local[0x2c];

    for (i = 0; i < 0x7f; i++, entry += 4) {
        if (*(u32 *)entry != 0) {
            fn_1_46B4(lbl_801A6410, *(u32 *)entry, lbl_1_data_3E62C, 0x626);
        }
    }

    lbl_1_bss_7E9E8__fzgx_offset_10 = -1;
    fzgx_obj_lbl_1_bss_7B1A4 = 1;
    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_7B1AC, 0, 0x13d8);
    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_7C584, 0, 0x1fc);

    if (fn_1_B7E98(0) == 0 && fn_1_B7E98(1) == 0) {
        lbl_1_bss_7E9E8__fzgx_offset_14 = 0;
        return;
    }

    fn_1_B9C0C();
    fn_1_B9BE0();
    fn_80008BEC(local, 0, 0x24);
    fn_80008BEC(&lbl_1_bss_77380, 0, 0x30);
    local[0] = 2;
    *(u32 *)(local + 0xc) = (u32)&lbl_1_bss_77380;
    *(u32 *)(local + 0x20) = 4;

    if (fn_1_B7E98(0) != 0 && fn_1_B7E98(1) != 0) {
        fn_1_AA6D8(4, 2, local);
    } else {
        fn_1_AA6D8(4, 4, local);
    }

    lbl_1_bss_7E9E8__fzgx_offset_14 = 1;
    lbl_1_bss_7EA00 = 0;
    fn_1_F1D70();
    lbl_1_bss_7EA00__fzgx_offset_4 = 0x14;
    lbl_1_bss_7EA00__fzgx_offset_8 = 0;
    lbl_1_bss_7EA00__fzgx_offset_C = 0;
    lbl_1_bss_7EA00__fzgx_offset_10 = 0;
}
/* fzgx:end fn_1_EB330 */

/* fzgx:begin fn_1_EB4BC pool noprologue */
#include "types.h"

typedef struct {
	u32 unk_0[9];
	u8 unk_24;
	u8 unk_25;
	u16 unk_26;
} Entry_28;

typedef struct {
	u32 unk_0[9];
	void* unk_24;
	u32 pad_28;
	void* unk_2C;
} Slot_30;

extern Slot_30 lbl_1_bss_77380[127];
extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern void* fn_1_4630(u32, u32, u8*, s32);
extern void fn_1_46B4(u32, void*, u8*, s32);
extern void fn_80008BA8(void*, void*, s32);
extern void fn_80008BEC(void*, s32, u32);
extern void OSReport(const char*, ...);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
Entry_28 fzgx_obj_lbl_1_bss_7B1AC[127];
void* fzgx_obj_lbl_1_bss_7C584[127];
u32 lbl_1_bss_7C584_fill_7C780[50];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE_fill_7C8D0[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 lbl_1_bss_7E9E8_fill_7E9E8[5];
s32 lbl_1_bss_7E9E8_14;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
	volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
	s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
	s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
	s = *(u8 *)&lbl_1_bss_7B190;
	s = *(u8 *)&lbl_1_bss_7B198;
	s = *(u8 *)&lbl_1_bss_7B19C;
	s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
	s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
	s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
	s = *(u8 *)&lbl_1_bss_7C584_fill_7C780;
	s = *(u8 *)&lbl_1_bss_7C848;
	s = *(u8 *)&lbl_1_bss_7C850;
	s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
	s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
	s = *(u8 *)&lbl_1_bss_7C8CD;
	s = *(u8 *)&lbl_1_bss_7C8CE;
	s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
	s = *(u8 *)&lbl_1_bss_7C914;
	s = *(u8 *)&lbl_1_bss_7C948;
	s = *(u8 *)&lbl_1_bss_7C94C;
	s = *(u8 *)&lbl_1_bss_7CA58;
	s = *(u8 *)&lbl_1_bss_7E9E8_fill_7E9E8;
	s = *(u8 *)&lbl_1_bss_7E9E8_14;
}
#pragma section code_type ".text"

#pragma opt_common_subs on
static inline void* *fn_1_EB4BC_array_read(void* *array) { return array; }
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("ghost.c");
    OSReport("GhostCalc");
    OSReport("GhostDisp");
    OSReport("story_ghost/%s");
    OSReport("StoryGhost : %s  %d\n");
    OSReport("./staff_ghost/ghost%d.dat");
    OSReport("pcarobj[%d]\n");
    OSReport("carobj[%d]\n");
    OSReport("save_???[%d]\n");
    OSReport("vehicle_parts/");
    OSReport("..");
    OSReport("vehicle/%s_e.arc.lz");
    OSReport("vehicle/%s_p.arc.lz");
    OSReport("vehicle/");
    OSReport("result_code: %d\n");
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
s32 fn_1_EB4BC(void) {
	s32 j;
	s32 count;
	Entry_28 tmp;
	void* tmpbuf;
	s32 i;

	if (fn_1_B7C00() != 0) {
		return 1;
	}

	if (lbl_1_bss_7E9E8_14 == 0) {
		return 0;
	}

	if (fn_1_B7CD4() == 0) {
		OSReport((const char*)(u8 *)"result_code: %d\n", fn_1_B7C5C());
		lbl_1_bss_7E9E8_14 = 0;
		return 1;
	}

	for (i = 0; i < 127; i++) {
		if ((*((i) + (lbl_1_bss_77380))).unk_24 != 0 && lbl_1_bss_77380[i].unk_2C != 0) {
			void* src = (*((i) + (lbl_1_bss_77380))).unk_2C;
			void* buf;

			fn_80008BA8(&fzgx_obj_lbl_1_bss_7B1AC[i], src, 0x28);

			if ((*((i) + (fzgx_obj_lbl_1_bss_7C584))) != 0) {
				fn_1_46B4(lbl_801A6410, (*((i) + (fzgx_obj_lbl_1_bss_7C584))), (u8 *)"ghost.c", 0x67c);
			}

			buf = fn_1_4630(lbl_801A6410, 0x3e80, (u8 *)"ghost.c", 0x67e);
			fn_80008BA8(buf, (u8*)src + 0x28, 0x3e80);
			fn_1_46B4(lbl_801A6410, (*((i) + (lbl_1_bss_77380))).unk_2C, (u8 *)"ghost.c", 0x682);
			(*((i) + (lbl_1_bss_77380))).unk_2C = 0;

			fzgx_obj_lbl_1_bss_7C584[i] = fn_1_4630(lbl_801A6410, 0x3e80, (u8 *)"ghost.c", 0x685);
			fn_80008BA8((*((i) + (fzgx_obj_lbl_1_bss_7C584))), buf, 0x3e80);
			fn_1_46B4(lbl_801A6410, buf, (u8 *)"ghost.c", 0x689);
		} else {
			fn_80008BEC(&fzgx_obj_lbl_1_bss_7B1AC[i], 0, 0x28);
			fzgx_obj_lbl_1_bss_7C584[i] = 0;
		}
	}

	count = 0;
	for (i = 0; i < 127; i++) {
		if ((*((i) + (fzgx_obj_lbl_1_bss_7C584))) != 0) {
			count++;
		}
	}

	for (i = 0; i < count - 1; i++) {
		for (j = i; j < count; j++) {
			if ((((*((i) + (fzgx_obj_lbl_1_bss_7B1AC))).unk_26) + (((*((i) + (fzgx_obj_lbl_1_bss_7B1AC))).unk_25 * 1000) + ((*((i) + (fzgx_obj_lbl_1_bss_7B1AC))).unk_24 * 60000))) >
				((((*((j) + (fzgx_obj_lbl_1_bss_7B1AC))).unk_25 * 1000) + (60000 * (*((j) + (fzgx_obj_lbl_1_bss_7B1AC))).unk_24)) + ((*((j) + (fzgx_obj_lbl_1_bss_7B1AC))).unk_26))) {
				tmp = (*((i) + (fzgx_obj_lbl_1_bss_7B1AC)));
				fzgx_obj_lbl_1_bss_7B1AC[i] = (*((j) + (fzgx_obj_lbl_1_bss_7B1AC)));
				fzgx_obj_lbl_1_bss_7B1AC[j] = tmp;

				tmpbuf = (*((i) + (fzgx_obj_lbl_1_bss_7C584)));
				fzgx_obj_lbl_1_bss_7C584[i] = (*((j) + (fzgx_obj_lbl_1_bss_7C584)));
				fzgx_obj_lbl_1_bss_7C584[j] = tmpbuf;
			}
		}
	}

	lbl_1_bss_7E9E8_14 = 0;
	return 1;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_EB4BC */

/* fzgx:begin fn_1_EB85C */
typedef struct {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x26];
} GhostEntry;

int fn_1_EB85C(void) {
    int result;
    GhostEntry *entry;
    int i;

    if (fn_1_B7C00() != 0) {
        return 0;
    }

    if ((s32)lbl_1_bss_7B1A4 == 0) {
        return 0;
    }

    result = fn_1_F21B8(lbl_1_bss_8B3A0.unk_90) != 0;
    entry = (GhostEntry *)&lbl_1_bss_7B1AC;
    for (i = 0; i < 0x7f; i++) {
        if (lbl_1_bss_8B3A0.unk_90 == entry[i].unk_1) {
            result++;
        }
    }

    return result;
}
/* fzgx:end fn_1_EB85C */

/* fzgx:begin fn_1_EC900 */
// Return the current ghost state value.
u32 fn_1_EC900(void) {
    return lbl_1_bss_7B1A4;
}
/* fzgx:end fn_1_EC900 */

/* fzgx:begin fn_1_EC910 noprologue */
#include "dolphin/types.h"

typedef struct {
    u8 kind;          /* 0x00 */
    u8 pad_1[0x3];
    u8 b4;            /* 0x04 */
    u8 b5;            /* 0x05 */
    u8 b6;            /* 0x06 */
    u8 b7;            /* 0x07 */
    u32 w8[4];        /* 0x08 */
    u16 count;        /* 0x18 */
    u16 pad_1A;
    u32 w1C[3];       /* 0x1C */
} GhostRecord;

typedef struct {
    u8 pad_0[0x90];
    s16 unk_90;
} GhostLoadState;

extern GhostLoadState lbl_1_bss_8B3A0;
extern void *lbl_801A6410;

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_F21B8(s32);
extern s32 ghost_test_flag(s32);
extern void fn_1_46B4(void *, void *, const char *, int);
extern void *fn_1_4630(void *, u32, const char *, int);
extern void fn_1_F1960(u32, void *, u32);
extern void fn_1_F1D70(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 lbl_1_bss_7B188__fzgx_offset_0[2];
u32 lbl_1_bss_7B190__fzgx_offset_0[2];
u32 lbl_1_bss_7B198__fzgx_offset_0[1];
u32 lbl_1_bss_7B19C__fzgx_offset_0[2];
s32 lbl_1_bss_7B1A4__fzgx_offset_0;            /* load pending */
u32 lbl_1_bss_7B1A4__fzgx_offset_4;
GhostRecord lbl_1_bss_7B1AC__fzgx_offset_0[127];  /* ghost headers */
void *lbl_1_bss_7C584__fzgx_offset_0[127];      /* ghost data buffers */
void *lbl_1_bss_7C584__fzgx_offset_1FC[5];
void *lbl_1_bss_7C584__fzgx_offset_210[5];
void *lbl_1_bss_7C584__fzgx_offset_224[5];
void *lbl_1_bss_7C584__fzgx_offset_238[5];
void *lbl_1_bss_7C584__fzgx_offset_24C[5];
void *lbl_1_bss_7C584__fzgx_offset_260[5];
void *lbl_1_bss_7C584__fzgx_offset_274[5];
void *lbl_1_bss_7C584__fzgx_offset_288[5];
void *lbl_1_bss_7C584__fzgx_offset_29C[5];
u32 lbl_1_bss_7C584__fzgx_offset_2B0[5];
u32 lbl_1_bss_7C848__fzgx_offset_0[1];
u8 lbl_1_bss_7C848__fzgx_offset_4;
u8 lbl_1_bss_7C848__fzgx_offset_5;
u16 lbl_1_bss_7C848__fzgx_offset_6;
u32 lbl_1_bss_7C850__fzgx_offset_0[3];
u32 lbl_1_bss_7C85C__fzgx_offset_0[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD__fzgx_offset_0;
u8 lbl_1_bss_7C8CE__fzgx_offset_0;           /* loaded ghost count */
u8 lbl_1_bss_7C8CE__fzgx_offset_1;
u32 lbl_1_bss_7C8CE__fzgx_offset_2;
u8 lbl_1_bss_7C8CE__fzgx_offset_6;
u8 lbl_1_bss_7C8CE__fzgx_offset_7;
u16 lbl_1_bss_7C8CE__fzgx_offset_8;
u32 lbl_1_bss_7C8CE__fzgx_offset_A[15];
u32 lbl_1_bss_7C914__fzgx_offset_0[13];
u32 lbl_1_bss_7C948__fzgx_offset_0[1];
u32 lbl_1_bss_7C94C__fzgx_offset_0[1];
struct { s16 value[5]; } lbl_1_bss_7C94C__fzgx_offset_4;
u16 lbl_1_bss_7C94C__fzgx_offset_E;
struct { u32 value[5]; } lbl_1_bss_7C94C__fzgx_offset_10;
struct { u8 value[5][3]; } lbl_1_bss_7C94C__fzgx_offset_24;

extern void fn_1_ECE00(void);
extern void fn_1_ECF68(void);
extern void fn_1_ED540(void);
extern void fn_1_EE530(void);
extern void fn_1_EF0A0(void);
extern void fn_1_EF5E0(void);
extern void fn_1_EF768(void);
extern void fn_1_EF860(void);
extern void fn_1_EF924(void);
extern void fn_1_EF97C(void);
extern void fn_1_EFA1C(void);
extern void fn_1_EF0A8(void);
extern void fn_1_EF488(void);
extern void fn_1_EF4F8(void);
extern void fn_1_EFA8C(void);
extern void ghost_reset(void);
extern void fn_1_F0168(void);

/* the retail TU's .data up to this function's last string: MWCC addresses it off one section base */
u32 fzgx_pool_table_0[55] = {
    0x4F564552, 0x54414B45, 0x00000000, 0x4A554D50,
    0x00000000, 0x454E454D, 0x59484954, 0x00000000,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349,
    0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x00000000, 0x4C415000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x67686F73, 0x7430302E,
    0x62696E00, 0x67686F73, 0x7430312E, 0x62696E00,
    0x67686F73, 0x7430322E, 0x62696E00, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000,
};
u32 fzgx_pool_funcs_DC[17] = { 0 };
u32 fzgx_pool_table_120[5] = { 0x4F726967, 0x696E616C, 0x204D6163, 0x68696E65, 0x00000000 };
u32 fzgx_pool_table_134[1] = { 0x00000000 };
u32 fzgx_pool_table_138[5] = { 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x00000000 };
u32 fzgx_pool_ptrs_14C[6] = { 0 };
u32 fzgx_pool_table_164[3] = { 0x53746166, 0x66204768, 0x6F737400 };
u32 fzgx_pool_table_170[5] = { 0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x00000000 };
u32 fzgx_pool_ptrs_184[6] = { 0 };
u32 fzgx_pool_table_19C[78] = {
    0x53454C45, 0x43542047, 0x484F5354, 0x00000000,
    0x47484F53, 0x54205345, 0x4C454354, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFF0000, 0xFFFFFFFF, 0x0000000C, 0x0000001D,
    0x0000000E, 0x00000017, 0x00000004, 0x00000000,
    0x00000016, 0x0000001D, 0x0000000C, 0x00000017,
    0x00000016, 0x00000000, 0x0000001D, 0x0000001B,
    0x00000004, 0x0000000F, 0x00000004, 0x00000000,
    0x0000001D, 0x00000011, 0x00000015, 0x0000000C,
    0x00000014, 0x00000000, 0x00000027, 0x00000005,
    0x0000001F, 0x00000004, 0x00000028, 0x0000001F,
    0x0003B3C4, 0x000382B3, 0x001382E7, 0x0013B38B,
    0x0020F129, 0x00000000, 0x0010714B, 0x002192B1,
    0x001230A9, 0x0021A322, 0x0011A225, 0x00000000,
    0x0022838D, 0x00218381, 0x0023B075, 0x00232128,
    0x00232328, 0x00000000, 0x0023A28A, 0x00209351,
    0x00206394, 0x0023B04C, 0x0020310C, 0x00000000,
    0x001062B2, 0x001260B2, 0x00206345, 0x00312110,
    0x003322E4, 0x0002E37D,
};
char fzgx_pool_str_2D4[8] = "ghost.c";
char fzgx_pool_str_2DC[12] = "GhostCalc";
char fzgx_pool_str_2E8[12] = "GhostDisp";
char fzgx_pool_str_2F4[16] = "story_ghost/%s";
char fzgx_pool_str_304[24] = "StoryGhost : %s  %d\n";
char fzgx_pool_str_31C[28] = "./staff_ghost/ghost%d.dat";
char fzgx_pool_str_338[16] = "pcarobj[%d]\n";
char fzgx_pool_str_348[12] = "carobj[%d]\n";
char fzgx_pool_str_354[16] = "save_\?\?\?[%d]\n";
char fzgx_pool_str_364[16] = "vehicle_parts/";
char fzgx_pool_str_374[4] = "..";
char fzgx_pool_str_378[20] = "vehicle/%s_e.arc.lz";
char fzgx_pool_str_38C[20] = "vehicle/%s_p.arc.lz";
char fzgx_pool_str_3A0[12] = "vehicle/";
char fzgx_pool_str_3AC[20] = "result_code: %d\n";
char fzgx_pool_str_3C0[16] = "%02d:%02d:%03d";
char fzgx_pool_str_3D0[4] = "%s";
char fzgx_pool_str_3D4[16] = "ghost_data[%d]\n";

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7B190__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7B198__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7B19C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7B1A4__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7B1A4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_1FC;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_210;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_224;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_238;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_24C;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_260;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_274;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_288;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_29C;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2B0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7C848__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_5;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7C850__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7C85C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_7;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_A;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7C914__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7C948__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_7C94C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_24;
}
#pragma section code_type ".text"

#define ghostFile    fzgx_pool_str_2D4
#define ghostPending lbl_1_bss_7B1A4__fzgx_offset_0
#define ghostRecords lbl_1_bss_7B1AC__fzgx_offset_0
#define ghostData    lbl_1_bss_7C584__fzgx_offset_0
#define ghostId      lbl_1_bss_7C848__fzgx_offset_4
#define ghostCount   lbl_1_bss_7C8CE__fzgx_offset_0
#define ghostLoaded  lbl_1_bss_7C8CE__fzgx_offset_6
#define ghostKinds   lbl_1_bss_7C94C__fzgx_offset_4.value
#define ghostVals    lbl_1_bss_7C94C__fzgx_offset_10.value
#define ghostAttrs   lbl_1_bss_7C94C__fzgx_offset_24.value

#define FREE_BUF(arr, line)                                         \
    if (arr[i] != NULL) {                                           \
        fn_1_46B4(lbl_801A6410, arr[i], ghostFile, line);           \
        arr[i] = NULL;                                              \
    }

void fn_1_EC910(void)
{
    char textA[256];
    char textB[256];
    char textC[256];
    GhostLoadState *state;
    GhostRecord *rec;
    u8 *p;
    u32 i;
    u32 n;

    if (ghostPending == 0) {
        return;
    }
    state = &lbl_1_bss_8B3A0;
    ghostCount = 0;
    n = state->unk_90;
    ghostPending = 0;
    ghostId = 0xff;
    if (fn_1_F21B8(n) != 0 && ghost_test_flag(0) != 0) {
        sprintf(textA, fzgx_pool_str_31C, ghostId = state->unk_90);
    }

    for (i = 0; i < 5; i++) {
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_1FC, 0x85a)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_210, 0x85b)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_224, 0x85c)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_238, 0x85d)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_24C, 0x85e)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_260, 0x85f)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_274, 0x860)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_288, 0x861)
        FREE_BUF(lbl_1_bss_7C584__fzgx_offset_29C, 0x862)
        sprintf(textB, fzgx_pool_str_354, i);
    }

    ghostCount = 0;
    for (i = 0; i < 5; i++) {
        ghostKinds[i] = -1;
        ghostVals[i] = 0;
        ghostAttrs[i][0] = 0;
        ghostAttrs[i][1] = 0;
        ghostAttrs[i][2] = 0;
    }

    for (i = 0; i < 127; i++) {
        if (ghost_test_flag(i + 1) != 0) {
            rec = &ghostRecords[i];
            n = ghostCount;
            ghostAttrs[n][0] = rec->b5;
            ghostAttrs[n][1] = rec->b6;
            ghostKinds[n] = rec->kind;
            ghostVals[n] = rec->b4;
            ghostAttrs[n][2] = rec->b7;
            p = fn_1_4630(lbl_801A6410, 0x3ec0, ghostFile, 0x87f);
            fn_80008BEC(p, 0, 0x3ea8);
            *(GhostRecord *)p = *rec;
            fn_80008BA8(p + 0x28, ghostData[i], rec->count << 4);
            fn_1_F1960(0xf24000 + ghostCount * 0x3ec0, p, 0x3ec0);
            fn_1_46B4(lbl_801A6410, p, ghostFile, 0x895);
            ghostCount++;
        }
    }

    ghostLoaded = ghostCount;
    if (fn_1_F21B8(state->unk_90) != 0 && ghost_test_flag(0) != 0) {
        ghostCount++;
    }

    for (i = 0; i < 127; i++) {
        if (ghostData[i] != NULL) {
            fn_1_46B4(lbl_801A6410, ghostData[i], ghostFile, 0x8b0);
            sprintf(textC, fzgx_pool_str_3D4, i);
            ghostData[i] = NULL;
        }
    }
    fn_1_F1D70();
}
/* fzgx:end fn_1_EC910 */

/* fzgx:begin fn_1_ECDFC */
// fn_1_ECDFC: empty in retail (single blr).
void fn_1_ECDFC(void) {
}
/* fzgx:end fn_1_ECDFC */

/* fzgx:begin fn_1_ECE00 */
// fn_1_ECE00: empty in retail (single blr).
void fn_1_ECE00(void) {
}
/* fzgx:end fn_1_ECE00 */

/* fzgx:begin fn_1_ECF68 */
void fn_1_ECF68(void) {
    fn_1_F23E8();
}
/* fzgx:end fn_1_ECF68 */

/* fzgx:begin fn_1_ECF88 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "dolphin/types.h"
#include "types.h"
#include "types.h"

#ifndef REL_MAIN_REL_GHOST_H
#define REL_MAIN_REL_GHOST_H
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H

// lbl_1_bss_7B180: .bss size 0x8, referenced by 29 functions, shape {'object': 873}
// the ghost .bss run from 0x7B180 as one view: retail addresses the TU's objects off this base (dtk sizes it 8; the objects at 7B188..7ED5C are separate symbols). Offsets from base-relative loads/stores in retail; mixed-width offsets are byte arrays.
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u8 pad_28[0x4];
    u8 arr_2C[0x1];
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
    u8 arr_30[0x1];
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 arr_34[0x1];
    u8 unk_35;
    u8 unk_36;
    u8 pad_37[0x1];
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u8 arr_44[0x4];
    u32 unk_48;
    u32 unk_4C;
    u8 arr_50[0x1];
    u8 unk_51;
    u16 unk_52;
    u8 arr_54[0x13B0];
    u32 unk_1404;
    u8 arr_1408[0x1F8];
    u32 unk_1600;
    u8 arr_1604[0x10];
    u32 unk_1614;
    u8 arr_1618[0x10];
    u32 unk_1628;
    u8 arr_162C[0x10];
    u32 unk_163C;
    u8 arr_1640[0x10];
    u32 unk_1650;
    u8 arr_1654[0x10];
    u32 unk_1664;
    u8 arr_1668[0x10];
    u32 unk_1678;
    u8 arr_167C[0x10];
    u32 unk_168C;
    u8 arr_1690[0x10];
    u32 unk_16A0;
    u8 arr_16A4[0x10];
    u32 unk_16B4;
    u8 arr_16B8[0x10];
    u32 unk_16C8;
    u8 unk_16CC;
    u8 pad_16CD[0x3];
    u32 unk_16D0;
    u32 unk_16D4;
    u32 unk_16D8;
    u32 unk_16DC;
    u8 unk_16E0;
    u8 pad_16E1[0x3];
    u32 unk_16E4;
    u32 unk_16E8;
    u32 unk_16EC;
    u32 unk_16F0;
    u32 unk_16F4;
    u32 unk_16F8;
    u32 unk_16FC;
    u32 unk_1700;
    u32 unk_1704;
    u32 unk_1708;
    u32 unk_170C;
    u32 unk_1710;
    u32 unk_1714;
    u32 unk_1718;
    u32 unk_171C;
    u32 unk_1720;
    u32 unk_1724;
    u32 unk_1728;
    u32 unk_172C;
    u32 unk_1730;
    u32 unk_1734;
    u32 unk_1738;
    u32 unk_173C;
    u32 unk_1740;
    u32 unk_1744;
    u32 unk_1748;
    u8 unk_174C;
    u8 unk_174D;
    u8 unk_174E;
    u8 pad_174F[0x1];
    u32 unk_1750;
    u8 unk_1754;
    u8 pad_1755[0x3];
    f32 unk_1758;
    f32 unk_175C;
    f32 unk_1760;
    u8 pad_1764[0x30];
    u32 unk_1794;
    u8 arr_1798[0x10];
    u32 unk_17A8;
    u8 arr_17AC[0x10];
    u32 unk_17BC;
    u32 unk_17C0;
    u32 unk_17C4;
    u32 unk_17C8;
    u32 unk_17CC;
    u16 unk_17D0;
    u16 unk_17D2;
    u16 unk_17D4;
    u16 unk_17D6;
    u16 unk_17D8;
    u8 pad_17DA[0x2];
    u32 unk_17DC;
    u32 unk_17E0;
    u32 unk_17E4;
    u32 unk_17E8;
    u32 unk_17EC;
    u8 unk_17F0;
    u8 unk_17F1;
    u8 unk_17F2;
    u8 unk_17F3;
    u8 unk_17F4;
    u8 unk_17F5;
    u8 unk_17F6;
    u8 unk_17F7;
    u8 unk_17F8;
    u8 unk_17F9;
    u8 unk_17FA;
    u8 unk_17FB;
    u8 unk_17FC;
    u8 unk_17FD;
    u8 unk_17FE;
    u8 pad_17FF[0x1];
    u16 unk_1800;
    u8 arr_1802[0xA];
    u8 arr_180C[0x14];
    u32 unk_1820;
    u32 unk_1824;
    u8 arr_1828[0x10];
    u16 unk_1838;
    s16 unk_183A;
    u32 unk_183C;
    u8 pad_1840[0x18];
    u8 arr_1858[0x80];
    u8 arr_18D8[0x30];
    u8 arr_1908[0xC0];
    u8 arr_19C8[0x620];
    u32 unk_1FE8;
    u16 unk_1FEC;
    u8 pad_1FEE[0x76];
    u32 unk_2064;
    u32 unk_2068;
    u32 unk_206C;
    u8 pad_2070[0x64];
    u8 arr_20D4[0x60];
    u8 arr_2134[0xB4];
    f32 unk_21E8;
    u8 pad_21EC[0x20];
    f32 unk_220C;
    u8 pad_2210[0x24D];
    u8 unk_245D;
    u8 pad_245E[0x141A];
    u32 unk_3878;
    u32 unk_387C;
    u8 unk_3880;
    u8 pad_3881[0x3];
    u32 unk_3884;
    u32 unk_3888;
    u8 unk_388C;
    u8 pad_388D[0x3];
    u32 unk_3890;
    u32 unk_3894;
    u32 unk_3898;
    f32 unk_389C;
    f32 unk_38A0;
    u8 unk_38A4;
    u8 unk_38A5;
    u8 unk_38A6;
    u8 pad_38A7[0x1];
    u32 unk_38A8;
    u32 unk_38AC;
    u32 unk_38B0;
    u32 unk_38B4;
    u32 unk_38B8;
    f32 unk_38BC;
    u32 unk_38C0;
    u8 arr_38C4[0x30];
    u8 arr_38F4[0xC0];
    u32 unk_39B4;
    u32 unk_39B8;
    u32 unk_39BC;
    u8 arr_39C0[0x30];
    u32 unk_39F0;
    u8 arr_39F4[0x10];
    u8 arr_3A04[0x30];
    u8 arr_3A34[0xC0];
    u8 arr_3AF4[0xC];
    u8 arr_3B00[0x30];
    u32 unk_3B30;
    u8 arr_3B34[0x8];
    u32 unk_3B3C;
    u32 unk_3B40;
    u32 unk_3B44;
    u8 pad_3B48[0x2];
    u16 unk_3B4A;
    u8 pad_3B4C[0x30];
    u32 unk_3B7C;
    u8 arr_3B80[0x58];
    u32 unk_3BD8;
} Obj_1_bss_7B180;
extern Obj_1_bss_7B180 lbl_1_bss_7B180;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_data_3E52C: .data size 0x4, 5 refs from ghost.c
extern u32 lbl_1_data_3E52C;

#endif  // REL_MAIN_REL_GHOST_H

/* end rel/main_rel/ghost.h */
/* begin game/main_rel/ghost_types.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef GAME_MAIN_REL_GHOST_TYPES_H
#define GAME_MAIN_REL_GHOST_TYPES_H

// Types (and the externs that name them) of ghost.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* rel/main_rel/globals.h: inlined above */
/* rel/main_rel/ghost.h: inlined above */
/* begin dolphin/ar.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef DOLPHIN_AR_H
#define DOLPHIN_AR_H

/* ARAM DMA request queue (ARQ), Dolphin SDK names. */

/* begin layout_check.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

CHECK_OFFSET(ARQRequest, dest, 0x14);
CHECK_SIZE(ARQRequest, 0x20);

#endif

/* end dolphin/ar.h */

/* begin game/vec3.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct {
    u32 field_0;
    s16 field_4;
    s16 field_6;
    u8 _pad8[0x74];
    Vec3 field_7c;
    u8 _pad88[0x64];
    u8 _pad_ec[0x60];
    u8 field_14c[0xb4];
    f32 field_200;
    u8 _pad204[0x20];
    f32 field_224;
    u8 _pad228[0x24d];
    u8 field_475;
} FnObject;

extern void fn_1_F143C(FnObject *obj, s32 index, const f32 *a, const f32 *b, void *arg5);

#endif  // GAME_MAIN_REL_GHOST_TYPES_H

/* end game/main_rel/ghost_types.h */
/* game/vec3.h: inlined above */

#pragma fp_contract on

extern const f32 lbl_1_rodata_6C94;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6C98;
extern const f64 lbl_1_rodata_6CA0;
/* Volatile: retail reloads the shared lap threshold in the second branch. */
extern const volatile f64 lbl_1_rodata_6CA8;
extern const f64 lbl_1_rodata_6CB0;
extern const f32 lbl_1_rodata_6CB8;
extern f32 lbl_8006D0B4(f32);
extern f32 __fmadds(f32, f32, f32);
extern s32 fn_1_3F164(void);
extern s32 fn_1_F17B4(const void *);
extern u32 fn_1_F1588(void);
extern void *fn_1_86254(int);
extern void fn_1_8645C(int, void *);
extern void fn_1_F0B5C(u32, void *);
extern void fn_1_F0D10(u32, u32);
extern void fn_1_F0E00(u32, void *);
extern void fn_1_F143C(FnObject *, s32, const f32 *, const f32 *, void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006F5C4(s16 *, s16 *, s16 *);
extern void ghost_pack_bits(u32 *, const u32 *, const u32 *, const u32 *);
extern void lbl_8006DBAC(Vec3 *);

#pragma fp_contract on
void fn_1_ECF88(void) {
    Obj_1_bss_7B180 *p_lbl_1_bss_7B180;
    u32 v0;
    u32 v1;
    void *v3;
    u32 v8;
    f32 v9;
    f32 v14;
    void *v37;
    void *v36;
    u32 *v35;
    u32 *v34;
    u32 *v33;
    u16 *v32;
    void *v31;
    void *v30;
    void *v29;
    u32 v28;
    void *v19;
    u32 v38;
    u16 v39;
    u8 v42;
    s32 v46;
    u32 v44;
    f32 loc_1C[3][4];
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    s16 loc_C;
    s16 loc_A;
    s16 loc_8;

    p_lbl_1_bss_7B180 = &lbl_1_bss_7B180;
    v0 = p_lbl_1_bss_7B180->unk_1820;
    v1 = ((v0 / 40 + p_lbl_1_bss_7B180->unk_38B4) << 4) + 40;
    if (v0 >= 28800 || v1 > 16000) {
        p_lbl_1_bss_7B180->unk_10 = 1;
    } else {
        p_lbl_1_bss_7B180->unk_38BC = lbl_1_rodata_6BD0 - (f32)v1 / lbl_1_rodata_6C94;
        v3 = fn_1_86254(0);
        {
            /* These flag reads are separate snapshots in the retail code. */
            u32 mask = -((*(volatile u32 *)v3 >> 2) & 1);
            p_lbl_1_bss_7B180->unk_38C0 = (p_lbl_1_bss_7B180->unk_38C0 + 1) & mask;
        }
        /* Volatile: this flag read is a separate snapshot after the counter update. */
        if ((*(volatile u32 *)v3 & 8) != 0) {
            p_lbl_1_bss_7B180->unk_38B8++;
        } else if (p_lbl_1_bss_7B180->unk_38B8 != 0) {
            p_lbl_1_bss_7B180->unk_38B8 = 0;
        }
        if ((s32)fn_1_F1588() != 0) {
            *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
        } else {
            v1 = *(u32 *)v3;
            if ((v1 & 4) != 0 && (s32)p_lbl_1_bss_7B180->unk_38C0 < 3) {
                for (v8 = p_lbl_1_bss_7B180->unk_0 - 14; v8 < p_lbl_1_bss_7B180->unk_0 - 10; v8++) {
                    if ((s32)v8 > 0) {
                        *(u8 *)(p_lbl_1_bss_7B180->unk_16E8 + v8) = 1;
                    }
                }
                p_lbl_1_bss_7B180->unk_14 = 1;
                *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
            } else {
                if ((v1 & 0x800000) != 0 || (v1 & 0x10) != 0) {
                    f32 y = *(f32 *)((u8 *)v3 + 152);
                    v9 = *(f32 *)((u8 *)v3 + 148) * *(f32 *)((u8 *)v3 + 148);
                    v9 = __fmadds(y, y, v9);
                    v9 = __fmadds(*(f32 *)((u8 *)v3 + 156), *(f32 *)((u8 *)v3 + 156), v9);
                    v9 = lbl_8006D0B4(v9);
                    {
                    f64 speed = v9 / *(f32 *)((u8 *)v3 + 8);
                    if (lbl_1_rodata_6C98 * speed > lbl_1_rodata_6CA0) {
                        p_lbl_1_bss_7B180->unk_14 = 1;
                        *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
                        /* Goto: this successful speed test skips the remaining flag tests. */
                        goto packed_flag;
                    }
                    }
                }
                if (*(u16 *)((u8 *)v3 + 532) == 60) {
                    p_lbl_1_bss_7B180->unk_14 = 1;
                    *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
                } else if ((s32)p_lbl_1_bss_7B180->unk_14 != 0) {
                    p_lbl_1_bss_7B180->unk_14 = 0;
                    *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 1;
                } else {
                    *(u8 *)p_lbl_1_bss_7B180->unk_38B0 = 0;
                }
            }
        }
packed_flag:
        if (*(u8 *)p_lbl_1_bss_7B180->unk_38B0 != 0) {
            p_lbl_1_bss_7B180->unk_38B4++;
        }
        fn_1_8645C(0, loc_1C);
        lbl_8006DBAC((Vec3 *)loc_1C);
        fn_8006F5C4(&loc_8, &loc_A, &loc_C);
        *(u8 *)(p_lbl_1_bss_7B180->unk_38AC + 2) = loc_C >> 8;
        *(u16 *)(p_lbl_1_bss_7B180->unk_38AC + 4) = loc_A;
        *(u8 *)(p_lbl_1_bss_7B180->unk_38AC + 3) = loc_8 >> 8;
        *(u8 *)p_lbl_1_bss_7B180->unk_38AC = p_lbl_1_bss_7B180->unk_0 - p_lbl_1_bss_7B180->unk_4;
        loc_18 = fn_1_F17B4(&loc_1C[0][3]);
        loc_14 = fn_1_F17B4(&loc_1C[1][3]);
        loc_10 = fn_1_F17B4(&loc_1C[2][3]);
        ghost_pack_bits((u32 *)(p_lbl_1_bss_7B180->unk_38AC + 8), &loc_18, &loc_14, &loc_10);

        v14 = *(f32 *)(p_lbl_1_bss_7B180->unk_3898 + 256) / *(f32 *)(p_lbl_1_bss_7B180->unk_3898 + 252);
        p_lbl_1_bss_7B180->unk_38A0 = v14;
        if (lbl_1_rodata_6CA8 < v14 && p_lbl_1_bss_7B180->unk_389C < lbl_1_rodata_6CB0) {
            p_lbl_1_bss_7B180->unk_38A4--;
        } else if (lbl_1_rodata_6CA8 < p_lbl_1_bss_7B180->unk_389C && v14 < lbl_1_rodata_6CB0) {
            p_lbl_1_bss_7B180->unk_38A4++;
        }
        p_lbl_1_bss_7B180->unk_389C = v14;
        *(u8 *)(p_lbl_1_bss_7B180->unk_38AC + 1) = p_lbl_1_bss_7B180->unk_38A4;
        *(u16 *)(p_lbl_1_bss_7B180->unk_38AC + 6) = (s32)(lbl_1_rodata_6CB8 * p_lbl_1_bss_7B180->unk_38A0);
        p_lbl_1_bss_7B180->unk_38AC += 16;
        p_lbl_1_bss_7B180->unk_38B0++;
        p_lbl_1_bss_7B180->unk_1820++;
        p_lbl_1_bss_7B180->unk_4 = p_lbl_1_bss_7B180->unk_0;
        p_lbl_1_bss_7B180->unk_0++;

        if ((s32)lbl_1_data_3E52C == 2) {
            v19 = &p_lbl_1_bss_7B180->unk_39F0;
            v37 = p_lbl_1_bss_7B180->arr_38C4;
            v36 = &p_lbl_1_bss_7B180->unk_39B4;
            v35 = v19;
            v34 = &p_lbl_1_bss_7B180->unk_1600;
            v33 = &p_lbl_1_bss_7B180->unk_1824;
            v32 = &p_lbl_1_bss_7B180->unk_1800;
            v31 = p_lbl_1_bss_7B180->arr_3A04;
            v30 = p_lbl_1_bss_7B180->arr_3AF4;
            v29 = p_lbl_1_bss_7B180->arr_19C8;
            for (v28 = 0; (u32)v28 < p_lbl_1_bss_7B180->unk_174E; v28++) {
                fn_1_F0D10(v28, (u32)v37);
                fn_1_F0B5C(v28, v36);
                fn_1_F0E00(v28, v35);
                if (fn_1_3F164() == 0) {
                    v39 = *v32;
                    if ((f32)v39 < ((f32 *)*v34)[*v33 - 1]) {
                        *v32 = v39 + 1;
                    }
                }
                fn_1_F0D10(v28, (u32)v31);
                fn_1_F0B5C(v28, v30);
                if ((s32)p_lbl_1_bss_7B180->unk_17C8 != 0) {
                    fn_1_F143C((FnObject *)v29, v28, (const f32 *)v30, (const f32 *)v36, v31);
                } else {
                    fn_80008BEC(v29, 0, 1568);
                }
                v37 = (u8 *)v37 + 48;
                v36 = (u8 *)v36 + 12;
                v35++;
                v34++;
                v33++;
                v32++;
                v31 = (u8 *)v31 + 48;
                v30 = (u8 *)v30 + 12;
                v29 = (u8 *)v29 + 1568;
            }
            if ((*(u32 *)v3 & 0x40000) != 0) {
                /* Keep the current-lap snapshot for the following comparisons. */
                s32 currentLap;
                /* Volatile: retain this lap snapshot for both comparisons below. */
                if ((s8)p_lbl_1_bss_7B180->unk_38A5 != (currentLap = *(volatile s8 *)&p_lbl_1_bss_7B180->unk_38A4)) {
                    v42 = p_lbl_1_bss_7B180->unk_38A6;
                    if (currentLap > (s8)v42 && (s8)v42 < 3) {
                        p_lbl_1_bss_7B180->unk_38A6 = v42 + 1;
                        p_lbl_1_bss_7B180->unk_38A8 = 120;
                        v46 = 0xF0000001;
                        p_lbl_1_bss_7B180->unk_3B30 = v46;
                        for (v44 = 0; v44 < p_lbl_1_bss_7B180->unk_174E; v44++) {
                            if (v46 < *(s32 *)v19) {
                                v46 = *(s32 *)v19;
                            }
                            v19 = (u8 *)v19 + 4;
                        }
                        p_lbl_1_bss_7B180->unk_3B30 = v46;
                        if ((s32)p_lbl_1_bss_7B180->unk_16D4 != 0) {
                            p_lbl_1_bss_7B180->unk_3B30 = v46 + p_lbl_1_bss_7B180->unk_16D4;
                        }
                    }
                }
            }
            p_lbl_1_bss_7B180->unk_38A5 = p_lbl_1_bss_7B180->unk_38A4;
        }
    }
}
/* fzgx:end fn_1_ECF88 */

/* fzgx:begin fn_1_EE3F4 */
extern void fn_1_F143C(void *, s32, void *, void *, void *);

void fn_1_EE3F4(void) {
    u8 *base;
    void *unk_38c4;
    void *unk_39b4;
    void *unk_39f0;
    f32 **unk_1600;
    u32 *unk_1824;
    u16 *unk_1800;
    void *unk_3a04;
    void *unk_3af4;
    void *unk_19c8;
    s32 i;
    u16 value;
    f32 converted;
    base = (u8 *)&lbl_1_bss_7B180;
    i = 0;
    unk_38c4 = base + 0x38c4;
    unk_39b4 = base + 0x39b4;
    unk_39f0 = base + 0x39f0;
    unk_1600 = (f32 **)(base + 0x1600);
    unk_1824 = (u32 *)(base + 0x1824);
    unk_1800 = (u16 *)(base + 0x1800);
    unk_3a04 = base + 0x3a04;
    unk_3af4 = base + 0x3af4;
    unk_19c8 = base + 0x19c8;

    while ((u32)i < base[0x174e]) {
        fn_1_F0D10(i, unk_38c4);
        fn_1_F0B5C(i, unk_39b4);
        fn_1_F0E00(i, unk_39f0);
        if (!fn_1_3F164()) {
            value = *unk_1800;
            converted = (f32)(u32)value;
            if (converted < (*unk_1600)[*unk_1824 - 1]) {
                *unk_1800 = value + 1;
            }
        }
        fn_1_F0D10(i, unk_3a04);
        fn_1_F0B5C(i, unk_3af4);
        fn_1_F143C(unk_19c8, i, unk_3af4, unk_39b4, unk_3a04);
        unk_38c4 = (u8 *)unk_38c4 + 0x30;
        unk_39b4 = (u8 *)unk_39b4 + 0xc;
        unk_39f0 = (u8 *)unk_39f0 + 4;
        unk_1600++;
        unk_1824++;
        unk_1800++;
        unk_3a04 = (u8 *)unk_3a04 + 0x30;
        unk_3af4 = (u8 *)unk_3af4 + 0xc;
        unk_19c8 = (u8 *)unk_19c8 + 0x620;
        i++;
    }
}
/* fzgx:end fn_1_EE3F4 */

/* fzgx:begin fn_1_EEB44 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct Vec3 {
f32 x;
f32 y;
f32 z;
} Vec3;


extern s16 lbl_1_bss_960;


typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u32 unk_C;
u32 unk_10;
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u8 pad_28[0x4];
u8 arr_2C[0x1];
u8 unk_2D;
u8 unk_2E;
u8 unk_2F;
u8 arr_30[0x1];
u8 unk_31;
u8 unk_32;
u8 unk_33;
u8 arr_34[0x1];
u8 unk_35;
u8 unk_36;
u8 pad_37[0x1];
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u8 arr_44[0x4];
u32 unk_48;
u32 unk_4C;
u8 arr_50[0x1];
u8 unk_51;
u16 unk_52;
u8 arr_54[0x13B0];
u32 unk_1404;
u8 arr_1408[0x1F8];
u32 unk_1600;
u8 arr_1604[0x10];
u32 unk_1614;
u8 arr_1618[0x10];
u32 unk_1628;
u8 arr_162C[0x10];
u32 unk_163C;
u8 arr_1640[0x10];
u32 unk_1650;
u8 arr_1654[0x10];
u32 unk_1664;
u8 arr_1668[0x10];
u32 unk_1678;
u8 arr_167C[0x10];
u32 unk_168C;
u8 arr_1690[0x10];
u32 unk_16A0;
u8 arr_16A4[0x10];
u32 unk_16B4;
u8 arr_16B8[0x10];
u32 unk_16C8;
u8 unk_16CC;
u8 pad_16CD[0x3];
u32 unk_16D0;
u32 unk_16D4;
u32 unk_16D8;
u32 unk_16DC;
u8 unk_16E0;
u8 pad_16E1[0x3];
u32 unk_16E4;
u32 unk_16E8;
u32 unk_16EC;
u32 unk_16F0;
u32 unk_16F4;
u32 unk_16F8;
u32 unk_16FC;
u32 unk_1700;
u32 unk_1704;
u32 unk_1708;
u32 unk_170C;
u32 unk_1710;
u32 unk_1714;
u32 unk_1718;
u32 unk_171C;
u32 unk_1720;
u32 unk_1724;
u32 unk_1728;
u32 unk_172C;
u32 unk_1730;
u32 unk_1734;
u32 unk_1738;
u32 unk_173C;
u32 unk_1740;
u32 unk_1744;
u32 unk_1748;
u8 unk_174C;
u8 unk_174D;
u8 unk_174E;
u8 pad_174F[0x1];
u32 unk_1750;
u8 unk_1754;
u8 pad_1755[0x3];
f32 unk_1758;
f32 unk_175C;
f32 unk_1760;
u8 pad_1764[0x30];
u32 unk_1794;
u8 arr_1798[0x10];
u32 unk_17A8;
u8 arr_17AC[0x10];
u32 unk_17BC;
u32 unk_17C0;
u32 unk_17C4;
u32 unk_17C8;
u32 unk_17CC;
u16 unk_17D0;
u16 unk_17D2;
u16 unk_17D4;
u16 unk_17D6;
u16 unk_17D8;
u8 pad_17DA[0x2];
u32 unk_17DC;
u32 unk_17E0;
u32 unk_17E4;
u32 unk_17E8;
u32 unk_17EC;
u8 unk_17F0;
u8 unk_17F1;
u8 unk_17F2;
u8 unk_17F3;
u8 unk_17F4;
u8 unk_17F5;
u8 unk_17F6;
u8 unk_17F7;
u8 unk_17F8;
u8 unk_17F9;
u8 unk_17FA;
u8 unk_17FB;
u8 unk_17FC;
u8 unk_17FD;
u8 unk_17FE;
u8 pad_17FF[0x1];
u16 unk_1800;
u8 arr_1802[0xA];
u8 arr_180C[0x14];
u32 unk_1820;
u32 unk_1824;
u8 arr_1828[0x10];
u16 unk_1838;
s16 unk_183A;
u32 unk_183C;
u8 pad_1840[0x18];
u8 arr_1858[0x80];
u8 arr_18D8[0x30];
u8 arr_1908[0xC0];
u8 arr_19C8[0x620];
u32 unk_1FE8;
u16 unk_1FEC;
u8 pad_1FEE[0x76];
u32 unk_2064;
u32 unk_2068;
u32 unk_206C;
u8 pad_2070[0x64];
u8 arr_20D4[0x60];
u8 arr_2134[0xB4];
f32 unk_21E8;
u8 pad_21EC[0x20];
f32 unk_220C;
u8 pad_2210[0x24D];
u8 unk_245D;
u8 pad_245E[0x141A];
u32 unk_3878;
u32 unk_387C;
u8 unk_3880;
u8 pad_3881[0x3];
u32 unk_3884;
u32 unk_3888;
u8 unk_388C;
u8 pad_388D[0x3];
u32 unk_3890;
u32 unk_3894;
u32 unk_3898;
f32 unk_389C;
f32 unk_38A0;
u8 unk_38A4;
u8 unk_38A5;
u8 unk_38A6;
u8 pad_38A7[0x1];
u32 unk_38A8;
u32 unk_38AC;
u32 unk_38B0;
u32 unk_38B4;
u32 unk_38B8;
f32 unk_38BC;
u32 unk_38C0;
u8 arr_38C4[0x30];
u8 arr_38F4[0xC0];
u32 unk_39B4;
u32 unk_39B8;
u32 unk_39BC;
u8 arr_39C0[0x30];
u32 unk_39F0;
u8 arr_39F4[0x10];
u8 arr_3A04[0x30];
u8 arr_3A34[0xC0];
u8 arr_3AF4[0xC];
u8 arr_3B00[0x30];
u32 unk_3B30;
u8 arr_3B34[0x8];
u32 unk_3B3C;
u32 unk_3B40;
u32 unk_3B44;
u8 pad_3B48[0x2];
u16 unk_3B4A;
u8 pad_3B4C[0x30];
u32 unk_3B7C;
u8 arr_3B80[0x58];
u32 unk_3BD8;
} Obj_1_bss_7B180;
extern Obj_1_bss_7B180 lbl_1_bss_7B180;


extern u8 lbl_1_data_3E358[0xC];


typedef struct {
u8 pad0[0x24];
u8 min;
u8 sec;
u16 ms;
} GhostRecord;
typedef struct {
u8 pad0[0x1e0];
u8 min;
u8 sec;
u16 ms;
} GhostPlayer;
typedef struct {
u8 pad0[0x324];
s32 handle;
} GhostObject;
typedef struct {
u8 lapDelta;
u8 flags;
u8 angleY;
u8 angleX;
s16 angleZ;
u16 pad;
u32 packed;
u32 unused;
} GhostFrame;
typedef struct {
u8 pad0[0x1d8];
u32 busy;
u16 course;
u8 pad1[0x2d4 - 0x1de];
char file[0x338 - 0x2d4];
char fmtItem[0x10];
char fmtObj[0x10];
} GhostStrings;
extern void *lbl_801A6410;
extern void fn_80008BEC(void *, int, u32);
extern GhostPlayer *fn_1_3F0D8(u32, f32 *, u8 *);
extern void fn_1_8645C(int, void *);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_8006F5C4(s16 *, s16 *, s16 *);
extern s32 fn_1_F17B4(const void *);
extern void ghost_pack_bits(u32 *, const u32 *, const u32 *, const u32 *);
extern u8 fn_1_3F114(void);
extern s16 *fn_1_86254(int);
extern void fn_1_12A734(s32);
extern void fn_1_7F934(GhostObject *);
extern void fn_1_46B4(void *, void *, const char *, int);
extern int sprintf(char *, const char *, ...);
extern void fn_1_14DBCC(void *);
extern void fn_1_984F0(void *);
void fn_1_EEB44(void)
{
struct { GhostStrings *value; } str;
struct { Obj_1_bss_7B180 *value; } work;
char objName[0x100];
char itemName[0x100];
f32 mtx[3][4];
f32 speed;
u32 packed0;
u32 packed1;
u32 packed2;
s16 angZ;
s16 angY;
s16 angX;
u8 misc;
GhostPlayer *player;
GhostRecord *rec;
GhostRecord **recs;
s16 *course;
u32 ptime;
u32 rtime;
u32 i;
struct { u32 value; } ghostCounter;
union { u8 *slot; GhostObject **objs; } cursor;
union { void **items; u8 *ghost; } otherCursor;
s32 j;
s32 count;
s32 f;
u8 *lapFlags;
u32 ghostIndex;
str.value = (GhostStrings *)lbl_1_data_3E358;
work.value = &lbl_1_bss_7B180;
if ((s32)work.value->unk_8 != 0 && work.value->unk_38AC != 0 ) {
if ((s32)work.value->unk_3894 != 0) {
str.value->busy = 0;
} else {
i = 0;
cursor.slot = work.value->arr_18D8;
for (; i < 5; i++) {
fn_80008BEC(cursor.slot, 0, 0x30);
cursor.slot += 0x30;
}
if (lbl_1_bss_960 == 9) {
if ((s32)work.value->unk_16C8 >= 0 && (s32)work.value->unk_17CC == 0) {
player = fn_1_3F0D8(0, &speed, &misc);
ptime = ((player)->min * 60000 + (player)->sec * 1000 + (player)->ms) ;
rec = (GhostRecord *)work.value->unk_16B4;
if (ptime >= ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ) {
work.value->unk_174C = 3;
} else {
work.value->unk_174C = 1;
}
} else if ((s32)work.value->unk_17CC != 0) {
work.value->unk_174C = 0;
} else if (work.value->unk_174E == 0) {
work.value->unk_174C = 0;
}
} else {
if (work.value->unk_174E != 0 && (s32)work.value->unk_17CC == 0) {
player = fn_1_3F0D8(0, &speed, &misc);
ptime = ((player)->min * 60000 + (player)->sec * 1000 + (player)->ms) ;
count = work.value->unk_174E;
work.value->unk_174C = 1;
recs = (GhostRecord **)&work.value->unk_16B4;
for (j = 0; j < count; j++) {
rec = recs[j];
if (ptime >= ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ) {
work.value->unk_174C = 3;
}
}
} else if ((s32)work.value->unk_17CC != 0) {
work.value->unk_174C = 0;
} else if (work.value->unk_174E == 0) {
work.value->unk_174C = 0;
}
}
if (work.value->unk_16CC != 0xff) {
player = fn_1_3F0D8(0, &speed, &misc);
ptime = ((player)->min * 60000 + (player)->sec * 1000 + (player)->ms) ;
if ((s32)work.value->unk_20 != 0) {
recs = (GhostRecord **)&work.value->unk_16B4;
recs += work.value->unk_174E;
rec = recs[-2];
rtime = ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ;
} else {
recs = (GhostRecord **)&work.value->unk_16B4;
recs += work.value->unk_174E;
rec = recs[-1];
rtime = ((rec)->min * 60000 + (rec)->sec * 1000 + (rec)->ms) ;
}
if (rtime > ptime) {
work.value->unk_174D = 1;
} else {
work.value->unk_174D = 3;
}
} else {
work.value->unk_174D = 0;
}
work.value->unk_3894 = 1;
fn_1_8645C(0, mtx);
for (f = work.value->unk_0 - 3; (u32)f < work.value->unk_0; f++) {
if (f > 0 && f < 0x7080) {
lapFlags = (u8 *)work.value->unk_16E8;
lapFlags[f] = 1;
}
}
lbl_8006DBAC((Vec3 *)mtx);
fn_8006F5C4(&angX, &angY, &angZ);
((GhostFrame *)work.value->unk_38AC)->angleY = angZ >> 8;
((GhostFrame *)work.value->unk_38AC)->angleZ = angY;
((GhostFrame *)work.value->unk_38AC)->angleX = angX >> 8;
((GhostFrame *)work.value->unk_38AC)->lapDelta = work.value->unk_0 - work.value->unk_4;
packed0 = fn_1_F17B4(&mtx[0][3]);
packed1 = fn_1_F17B4(&mtx[1][3]);
packed2 = fn_1_F17B4(&mtx[2][3]);
ghost_pack_bits(&((GhostFrame *)work.value->unk_38AC)->packed, &packed0, &packed1, &packed2);
((GhostFrame *)work.value->unk_38AC)->flags = fn_1_3F114();
((GhostFrame *)work.value->unk_38AC)->pad = 0;
*(u8 *)work.value->unk_38B0 = 1;
work.value->unk_38AC += sizeof(GhostFrame);
work.value->unk_38B0++;
work.value->unk_1820++;
work.value->unk_4 = work.value->unk_0;
work.value->unk_0++;
work.value->unk_C = 1;
str.value->course = 0;
course = fn_1_86254(0);
if (course != ((void *)0) ) {
str.value->course = course[3];
}
cursor.objs = (GhostObject **)&work.value->unk_1794;
otherCursor.items = (void **)&work.value->unk_17A8;
{
for (i = 0; i < 5; i++) {
if (cursor.objs[i] != ((void *)0) ) {
if (cursor.objs[i]->handle != -1) {
fn_1_12A734(cursor.objs[i]->handle);
cursor.objs[i]->handle = -1;
}
fn_1_7F934(cursor.objs[i]);
fn_1_46B4(lbl_801A6410, cursor.objs[i], str.value->file, 0xd89);
sprintf(objName, str.value->fmtObj, i);
cursor.objs[i] = ((void *)0) ;
}
if (otherCursor.items[i] != ((void *)0) ) {
fn_1_14DBCC(otherCursor.items[i]);
fn_1_46B4(lbl_801A6410, otherCursor.items[i], str.value->file, 0xd93);
sprintf(itemName, str.value->fmtItem, i);
otherCursor.items[i] = ((void *)0) ;
}
}
}
otherCursor.ghost = work.value->arr_19C8;
for (ghostCounter.value = 0; ghostCounter.value < work.value->unk_174E; ghostCounter.value++) {
fn_1_984F0(otherCursor.ghost + ghostCounter.value * 0x620);
}
str.value->busy = 0;
}
}
return;
}
/* fzgx:end fn_1_EEB44 */

/* fzgx:begin fn_1_EF0A0 */
// fn_1_EF0A0: empty in retail (single blr).
void fn_1_EF0A0(void) {
}
/* fzgx:end fn_1_EF0A0 */

/* fzgx:begin fn_1_EF0A4 */
// fn_1_EF0A4: empty in retail (single blr).
void fn_1_EF0A4(void) {
}
/* fzgx:end fn_1_EF0A4 */

/* fzgx:begin fn_1_EF484 */
// fn_1_EF484: empty in retail (single blr).
void fn_1_EF484(void) {
}
/* fzgx:end fn_1_EF484 */

/* fzgx:begin fn_1_EF488 */
void fn_1_EF488(void) {
    fn_1_EE530();
    if (!fn_1_B7C00()) {
        fn_1_B9BE0();
        fn_1_B9DE8(&lbl_1_bss_7ECB4);
        lbl_1_bss_7ECB4.unk_0 = 4;
        lbl_1_bss_7ECB4.unk_4 = 9;
        lbl_1_bss_7EA00[0] = 0;
        lbl_1_data_3E52C = 13;
    }
}
/* fzgx:end fn_1_EF488 */

/* fzgx:begin fn_1_EF4F4 */
// fn_1_EF4F4: empty in retail (single blr).
void fn_1_EF4F4(void) {
}
/* fzgx:end fn_1_EF4F4 */

/* fzgx:begin fn_1_EF4F8 */
#include "types.h"

typedef struct {
    u8 pad_000[0x1D4];
    s32 state;
    u8 pad_1D8[0x08];
    s32 saved_state;
    u8 work[0x100];
} MainRelData;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x2C0];
} fn_1_EF4F8_Obj_1_bss_7C584;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0xF];
    u8 unk_14;
    u8 pad_15[0x33];
} fn_1_EF4F8_Obj_1_bss_7ECB4;

extern s32 fn_1_BA144(fn_1_EF4F8_Obj_1_bss_7ECB4 *);
extern void fn_1_BC310(fn_1_EF4F8_Obj_1_bss_7ECB4 *);
extern void fn_1_BC29C(fn_1_EF4F8_Obj_1_bss_7ECB4 *);

void fn_1_EF4F8(void) {
    struct { u32 * value; } entries;
    s32 i;
    MainRelData *data;
    u32 *global;
    s32 zero;
    s32 status;

    data = &(*(MainRelData *)&lbl_1_data_3E358);
    fn_1_EE530();
    status = (s8)fn_1_BA144(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
    if (status == 2) {
        fn_1_BC310(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
        return;
    }
    if (status == 0) {
        data->state = 5;
        return;
    }

    fn_1_BC29C(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
    fn_1_B9C0C();
    entries.value = (u32 *)&(*(fn_1_EF4F8_Obj_1_bss_7C584 *)&lbl_1_bss_7C584);
    global = &(*(u32 *)&lbl_801A6410);
    i = 0;
    zero = 0;
    for (; i < 0x7F; i++) {
        if (*entries.value != 0) {
            fn_1_46B4(*global, *entries.value, &data->work[0xF0], 0xEBA);
            *entries.value = zero;
        }
        entries.value++;
    }
    data->state = data->saved_state;
    fn_1_1596DC(2);
    fn_1_484CC(2);
}
/* fzgx:end fn_1_EF4F8 */

/* fzgx:begin fn_1_EF5DC */
// fn_1_EF5DC: empty in retail (single blr).
void fn_1_EF5DC(void) {
}
/* fzgx:end fn_1_EF5DC */

/* fzgx:begin fn_1_EF764 */
// fn_1_EF764: empty in retail (single blr).
void fn_1_EF764(void) {
}
/* fzgx:end fn_1_EF764 */

/* fzgx:begin fn_1_EF768 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"

extern void fn_1_EE530(void);
extern u32 fn_1_4630(u32, u32, const void *, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_C0510(void *);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u32 lbl_801A6410[];

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_c;
    u32 unk_10;
} Obj_3B34;

typedef struct {
    u8 pad_0[0x1c];
    u32 unk_1c;
    u8 pad_20[0xc];
    u8 unk_2c[0x28];
    u8 pad_54[0x13b0];
    u32 unk_1404[0x7f];
    u8 pad_1600[0x2534];
    Obj_3B34 unk_3b34;
} GhostState;

typedef struct lbl_1_bss_7B19C_t {
    u32 unk_1c;
    u8 pad_4[0x4];
} lbl_1_bss_7B19C_t;

typedef struct lbl_1_bss_7B1AC_t {
    u8 unk_2c[0x28];
    u8 pad_28[0x13b0];
} lbl_1_bss_7B1AC_t;

typedef struct lbl_1_bss_7C584_t {
    u32 unk_1404[0x7f];
    u8 pad_1FC[0xc8];
} lbl_1_bss_7C584_t;

typedef struct lbl_1_bss_7ECB4_t {
    Obj_3B34 unk_3b34;
    u8 pad_14[0x34];
} lbl_1_bss_7ECB4_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
lbl_1_bss_7B19C_t lbl_1_bss_7B19C;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
lbl_1_bss_7B1AC_t fzgx_obj_lbl_1_bss_7B1AC;
lbl_1_bss_7C584_t fzgx_obj_lbl_1_bss_7C584;
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[14];
u32 lbl_1_bss_7EA38[159];
lbl_1_bss_7ECB4_t fzgx_obj_lbl_1_bss_7ECB4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECB4;
}
#pragma section code_type ".text"

void fn_1_EF768(void) {
    u32 *p;
    u32 i;
    u32 v;
    u32 h;
    Obj_3B34 *o;

    
    fn_1_EE530();
    h = fn_1_4630(lbl_801A6410[0], 0x3ea8, lbl_1_data_3E62C, 0xf14);
    lbl_1_bss_7B19C.unk_1c = h;
    fn_80008BA8((void *)h, fzgx_obj_lbl_1_bss_7B1AC.unk_2c, 0x28);
    fn_80008BA8((void *)(lbl_1_bss_7B19C.unk_1c + 0x28), (const void *)fzgx_obj_lbl_1_bss_7C584.unk_1404[0], 0x3e80);
    o = &fzgx_obj_lbl_1_bss_7ECB4.unk_3b34;
    o->unk_8 = lbl_1_bss_7B19C.unk_1c;
    o->unk_c = 0x3ea8;
    o->unk_10 = 2;
    fn_1_C0510(o);
    p = fzgx_obj_lbl_1_bss_7C584.unk_1404;
    for (i = 0; i < 0x7f; i++) {
        v = p[i];
        if (v != 0) {
            fn_1_46B4(lbl_801A6410[0], v, lbl_1_data_3E62C, 0xf28);
            p[i] = 0;
        }
    }
    lbl_1_data_3E52C = 7;
}
/* fzgx:end fn_1_EF768 */

/* fzgx:begin fn_1_EF85C */
// fn_1_EF85C: empty in retail (single blr).
void fn_1_EF85C(void) {
}
/* fzgx:end fn_1_EF85C */

/* fzgx:begin fn_1_EF860 */
void fn_1_EF860(void) {
    u8 *base = lbl_1_data_3E358;
    u32 value;

    fn_1_EE530();
    if (!fn_1_B7C00()) {
        if (!fn_1_B7CD4()) {
            value = fn_1_B7C5C();
            OSReport((const char *)(base + 0x3ac), value);
        }
        if (lbl_1_bss_7B19C[0] != 0) {
            fn_1_46B4(lbl_801A6410[0], lbl_1_bss_7B19C[0],
                      (void *)(base + 0x2d4), 0xf44);
            lbl_1_bss_7B19C[0] = 0;
        }
        if (lbl_1_bss_7ECB4.unk_14 == (s8)8) {
            fn_1_C1394();
            *((u32 *)(base + 0x1d4)) = 0xd;
        } else {
            *((u32 *)(base + 0x1d4)) = 8;
        }
    }
}
/* fzgx:end fn_1_EF860 */

/* fzgx:begin fn_1_EF920 */
// fn_1_EF920: empty in retail (single blr).
void fn_1_EF920(void) {
}
/* fzgx:end fn_1_EF920 */

/* fzgx:begin fn_1_EF978 */
// fn_1_EF978: empty in retail (single blr).
void fn_1_EF978(void) {
}
/* fzgx:end fn_1_EF978 */

/* fzgx:begin fn_1_EF97C */
void fn_1_EF97C(void) {
    u8 *base = lbl_1_data_3E358;

    fn_1_EE530();

    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        *(s32 *)(base + 0x1D4) = 10;
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_496FC(lbl_1_rodata_6D20, lbl_1_rodata_6D24);
    fn_1_495C8(9);

    if (lbl_1_bss_7B198) {
        fn_1_4AE0C(base + 0x40C);
    } else {
        fn_1_4AE0C(base + 0x458);
    }
}
/* fzgx:end fn_1_EF97C */

/* fzgx:begin fn_1_EFA18 */
// fn_1_EFA18: empty in retail (single blr).
void fn_1_EFA18(void) {
}
/* fzgx:end fn_1_EFA18 */

/* fzgx:begin fn_1_EFA4C */
// fn_1_EFA4C: empty in retail (single blr).
void fn_1_EFA4C(void) {
}
/* fzgx:end fn_1_EFA4C */

/* fzgx:begin ghost_reset */
void ghost_reset(void) {
    lbl_1_bss_7C8CE[0] = 0;
    lbl_1_data_3E52C = -1;
    fn_1_F1D70();
}
/* fzgx:end ghost_reset */

/* fzgx:begin fn_1_EFA88 */
// fn_1_EFA88: empty in retail (single blr).
void fn_1_EFA88(void) {
}
/* fzgx:end fn_1_EFA88 */

/* fzgx:begin fn_1_F0164 */
// fn_1_F0164: empty in retail (single blr).
void fn_1_F0164(void) {
}
/* fzgx:end fn_1_F0164 */

/* fzgx:begin fn_1_F0B5C noprologue */
#include "types.h"

typedef struct { f32 x, y, z; } V3;

typedef struct {
    f32 *k[5];
    f32 *a_row0[5]; f32 * a_row1[5]; f32 * a_row2[5];
    u8 pad0[0x16ec - 0x1650];
    f32 *b_row0[5]; f32 * b_row1[5]; f32 * b_row2[5];
    u8 pad1[0x1758 - 0x1728];
    V3 v[14];
    u16 h[18];
    s32 c[5];
} S;

extern const f64 lbl_1_rodata_6B68;
extern V3 lbl_1_rodata_6D28;
extern f32 fn_1_F4E3C(s32, f32 *, f32 *, f32 *, f32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[127];
f32 *lbl_1_bss_7C584__fzgx_offset_1FC[5];
f32 *lbl_1_bss_7C584__fzgx_offset_210[5];
f32 *lbl_1_bss_7C584__fzgx_offset_224[5];
f32 *lbl_1_bss_7C584__fzgx_offset_238[5];
u32 lbl_1_bss_7C584__fzgx_offset_24C[30];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[4];
f32 *lbl_1_bss_7C85C__fzgx_offset_10[5];
f32 *lbl_1_bss_7C85C__fzgx_offset_24[5];
f32 *lbl_1_bss_7C85C__fzgx_offset_38[5];
u32 lbl_1_bss_7C85C__fzgx_offset_4C[9];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[2];
u8 lbl_1_bss_7C8CE__fzgx_offset_A;
u8 lbl_1_bss_7C8CE__fzgx_offset_B;
u16 lbl_1_bss_7C8CE__fzgx_offset_C;
u32 lbl_1_bss_7C8CE__fzgx_offset_E[14];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[13];
u16 lbl_1_bss_7C94C__fzgx_offset_34[18];
s32 lbl_1_bss_7C94C__fzgx_offset_58[5];
u32 lbl_1_bss_7C94C__fzgx_offset_6C[40];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_1FC;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_210;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_224;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_238;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_24C;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_38;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_4C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_B;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_34;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_58;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_6C;
}
#pragma section code_type ".text"

#pragma opt_propagation off
s32 fn_1_F0B5C(s32 i, V3 *out) {
    u16 *frames;
    s32 *counts;
    V3 def = lbl_1_rodata_6D28;
    frames = lbl_1_bss_7C94C__fzgx_offset_34;
    out->x = fn_1_F4E3C((counts = lbl_1_bss_7C94C__fzgx_offset_58)[i], lbl_1_bss_7C584__fzgx_offset_1FC[i], lbl_1_bss_7C584__fzgx_offset_210[i], lbl_1_bss_7C85C__fzgx_offset_10[i], (f32)frames[i]);
    out->y = fn_1_F4E3C(counts[i], lbl_1_bss_7C584__fzgx_offset_1FC[i], lbl_1_bss_7C584__fzgx_offset_224[i], lbl_1_bss_7C85C__fzgx_offset_24[i], (f32)frames[i]);
    out->z = fn_1_F4E3C(counts[i], lbl_1_bss_7C584__fzgx_offset_1FC[i], lbl_1_bss_7C584__fzgx_offset_238[i], lbl_1_bss_7C85C__fzgx_offset_38[i], (f32)frames[i]);
    if ((f32)frames[i] >= lbl_1_bss_7C584__fzgx_offset_1FC[i][counts[i] - 1]) {
        *out = def;
        return 0;
    }
    (*(V3 (*)[14])&lbl_1_bss_7C8CE__fzgx_offset_A)[i] = *out;
    return 1;
}
/* fzgx:end fn_1_F0B5C */

/* fzgx:begin fn_1_F1300 */
extern const f32 lbl_1_rodata_6B60;

extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_z(s16 value);
extern void mathutil_mtxA_rotate_y(s16 value);
extern void mathutil_mtxA_rotate_x(s16 value);
extern void fn_8006E5FC(void *value);

typedef struct GhostVec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} GhostVec4;

#pragma opt_strength_reduction off
void fn_1_F1300(u32 count, GhostVec4 *records, const u8 *xbytes,
                const s16 *values, const u8 *zbytes) {
    f32 fzgx_live_;
    f32 *fzgx_value;
    f32 fzgx_live;
    struct { u32 value; } k;
    const u8 * bytes_b_local = zbytes;
    const s16 * values_local = values;
    s16 sample;
    GhostVec4 *current;
    GhostVec4 *next;
    u32 i;

    current = records;
    next = records + 1;
    i = 0;
    while (i < count) {
        lbl_8006D758();
        sample = (s8)*bytes_b_local << 8;
        mathutil_mtxA_rotate_z(sample);
        mathutil_mtxA_rotate_y(*values_local);
        sample = (s8)xbytes[i] << 8;
        mathutil_mtxA_rotate_x(sample);
        fn_8006E5FC(records);
        values_local++;
        i++;
        bytes_b_local++;
        records++;
    }

    for (k.value = 0; k.value < count - 1; k.value++) {
        f32 a;
        f32 b;
        f32 c;
        f32 d;
        f32 dot;

        a = current->x * next->x;
        b = current->y * next->y;
        fzgx_live_ = next->z;
        c = current->z * fzgx_live_;
        fzgx_live = current->w;
        d = fzgx_live * next->w;
        dot = a + b + c + d;
        if (dot < lbl_1_rodata_6B60) {
            fzgx_value = &(next->x);
            *fzgx_value = -next->x;
            next->y = -next->y;
            next->z = -next->z;
            next->w = -next->w;
        }
        current++;
        next++;
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_F1300 */

/* fzgx:begin fn_1_F143C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 field_0;
    s16 field_4;
    s16 field_6;
    u8 _pad8[0x74];
    Vec3 field_7c;
    u8 _pad88[0x64];
    u8 _pad_ec[0x60];
    u8 field_14c[0xb4];
    f32 field_200;
    u8 _pad204[0x20];
    f32 field_224;
    u8 _pad228[0x24d];
    u8 field_475;
} FnObject;

#pragma opt_common_subs off
void fn_1_F143C(FnObject *obj, s32 index, const f32 *a, const f32 *b, void *arg5) {
    u32 *entry;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 d2;
    f32 t;

    obj->field_4 = -2;
    entry = (u32 *)lbl_1_bss_7C914[index];
    if (entry != 0) {
        obj->field_6 = *((s8 *)entry + 0x328);
    }

    obj->field_7c = *(const Vec3 *)a;
    obj->field_0 = 0x400;
    lbl_8006DD14(arg5, obj->_pad_ec);
    obj->field_475 = 0;

    dx = a[0];
    dx = dx - b[0];
    dy = a[1];
    dy = dy - b[1];
    dz = a[2];
    dz = dz - b[2];
    d2 = dx * dx;
    d2 = d2 + dy * dy;
    d2 = d2 + dz * dz;

    if (d2 < lbl_1_rodata_6D38) {
        t = lbl_8006D0B4(d2 / lbl_1_rodata_6D38);
        t = lbl_8006D0B4(t);
        obj->field_224 = lbl_1_rodata_6D3C * t;
        obj->field_200 = lbl_1_rodata_6D40 * t;
    } else {
        obj->field_224 = lbl_1_rodata_6D3C;
        obj->field_200 = lbl_1_rodata_6D40;
    }

    lbl_8006D7DC((void *)a);
    lbl_8006DFC4(arg5);
    lbl_8006DB74(obj->field_14c);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F143C */

/* fzgx:begin fn_1_F1588 */
u32 fn_1_F1588(void) {
    u32 value = lbl_1_bss_7EA38[0];

    if (value == 0) {
        return 0;
    }

    if ((f32)value < lbl_1_rodata_6D10) {
        return value % 6 == 0;
    }

    if ((f32)value < lbl_1_rodata_6D44) {
        return value % 10 == 0;
    }

    return (value & 0xf) == 0;
}
/* fzgx:end fn_1_F1588 */

/* fzgx:begin fn_1_F1650 */
#include "types.h"

#pragma opt_common_subs off
f32 fn_1_F1650(const u32 *value) {
    s32 i;
    u32 bits = value[0];
    s32 sign = (s32)((bits >> 20) & 1);
    u32 exponent = (bits >> 15) & 0x1f;
    f32 place;
    f32 fraction;

    if ((bits >> 15) & 0x10) {
        exponent = ~(exponent - 16);
        exponent = exponent * -1;
    } else {
        exponent = exponent - 15;
    }

    {
    f32 fraction = lbl_1_rodata_6BD0;
    f32 place = lbl_1_rodata_6BBC;
    u32 mantissa = bits & 0x7fff;

    for (i = 0; i < 15; i++) {
        if (mantissa & (1 << (14 - i))) {
            fraction += place;
        }
        place *= lbl_1_rodata_6BBC;
    }

    fraction *= fn_80088598(lbl_1_rodata_6D48, (f64)(s32)exponent);

    if (sign != 0) {
        fraction *= lbl_1_rodata_6D50;
    }

    return fraction;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F1650 */

/* fzgx:begin fn_1_F17B4 */
#include "types.h"

s32 fn_1_F17B4(const void *value) {
    u32 bits;
    s32 exponent;
    s32 sign;
    s32 fraction;
    f64 converted;
    s32 magnitude;
    s32 result;

    fn_80008BA8(&bits, value, 4);

    exponent = (s32)((bits >> 23) & 0xff) - 0x7f;
    sign = bits >> 31;
    fraction = bits & 0x7fffff;

    if (exponent >= 0) {
        exponent = (exponent << 27) >> 27;
        exponent += 0xf;
    } else {
        converted = (f32)exponent;
        converted = __fabs(converted);
        magnitude = (s32)converted;
        magnitude = (magnitude << 27) >> 27;
        exponent = ~magnitude + 0x10;
        exponent = (exponent << 27) >> 27;
    }

    result = sign << 20;
    result += exponent << 15;
    result += fraction >> 8;
    return result;
}
/* fzgx:end fn_1_F17B4 */

/* fzgx:begin ghost_pack_bits */
void ghost_pack_bits(u32 *out, const u32 *x, const u32 *y, const u32 *z) {
    out[0] = 0;
    out[1] = 0;
    out[0] += x[0] << 10;
    out[0] += y[0] >> 11;
    out[1] += y[0] << 21;
    out[1] += z[0];
}
/* fzgx:end ghost_pack_bits */

/* fzgx:begin fn_1_F18C0 */
void fn_1_F18C0(const u32 *in, u32 *x, u32 *y, u32 *z) {
    x[0] = (in[0] >> 10) & 0x1fffff;
    y[0] = 0;
    y[0] += (in[0] & 0x3ff) << 11;
    y[0] += in[1] >> 21;
    z[0] = in[1] & 0x1fffff;
}
/* fzgx:end fn_1_F18C0 */

/* fzgx:begin fn_1_F190C */
void fn_1_F190C(void) {
    fn_80008BEC(&lbl_1_bss_7B1AC, 0, 0x13d8);
    fn_80008BEC(&lbl_1_bss_7C584, 0, 0x1fc);
}
/* fzgx:end fn_1_F190C */

/* fzgx:begin fn_1_F1950 */
// Set the transfer completion flag for the asynchronous callback.
void fn_1_F1950(void) {
    lbl_1_bss_7ECFC.unk_0 = 1;
}
/* fzgx:end fn_1_F1950 */

/* fzgx:begin fn_1_F1960 */
extern void ARQPostRequest(void *arg0, u32 arg1, u32 arg2, u32 arg3,
                        void *arg4, void *arg5, u32 arg6,
                        void (*callback)(void));

void fn_1_F1960(void *arg0, void *arg1, u32 arg2) {
    u32 result;
    u8 temp[0x20];
    // The completion flag is updated asynchronously by the callback.
    volatile u32 *flag;

    result = fn_8002071C(arg0);
    fn_800206FC(arg2);
    lbl_1_bss_7ECFC.unk_0 = 0;
    while (ARGetDMAStatus() != 0) {
    }
    DCFlushRange(arg1, arg2);
    ARQPostRequest(temp, 1, 0, 1, arg1, arg0, arg2, fn_1_F1950);
    flag = &lbl_1_bss_7ECFC.unk_0;
    while ((s32)*flag == 0) {
    }
    fn_800206FC(result);
}
/* fzgx:end fn_1_F1960 */

/* fzgx:begin fn_1_F1A24 noprologue */
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E358[];
extern void fn_1_F1950(void);
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern u32 fn_8002071C(void);
extern void fn_800206FC(u32);
extern u32 ARGetDMAStatus(void);
extern void DCInvalidateRange(void *, u32);
extern void ARQPostRequest(void *, u32, u32, u32, u32, void *, u32, void (*)(void));
extern void OSReport(const char *, ...);

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
static inline void fn_1_F1A24_read(u8 *bss, void *buf, u32 addr, u32 len) {
    s8 work[0x18];
    u32 old;

    old = fn_8002071C();
    fn_800206FC(len);
    *(u32 *)(bss + 0x3b7c) = 0;
    while (ARGetDMAStatus() != 0) {
    }
    DCInvalidateRange(buf, len);
    ARQPostRequest(work, 1, 1, 1, addr, buf, len, fn_1_F1950);
    while (*(s32 *)(bss + 0x3b7c) == 0) {
    }
    fn_800206FC(old);
}

void fn_1_F1A24(void) {
    u32 *entry;
    u32 size;
    u8 *bss;
    u8 *buffer;
    u8 *data;
    u32 i;

    data = lbl_1_data_3E358;
    bss = (u8 *)&lbl_1_bss_7B180;
    entry = (u32 *)(((0x16b4) + (bss)));
    size = 0xf24000;
    i = 0;
    while (i < bss[0x1754]) {
        if (((0) != (*entry))) {
            fn_1_46B4(lbl_801A6410, *entry, data + 0x2d4, 0x12a7);
        }
        *entry = fn_1_4630(lbl_801A6410, 0x3ec0, data + 0x2d4, 0x12a9);
        fn_1_F1A24_read(bss, (void *)*entry, size, 0x3ec0);
        buffer = (u8 *)(*entry);
        OSReport((const char *)(data + 0x4a0), *buffer);
        OSReport((const char *)(data + 0x4b0), buffer + 8);
        OSReport((const char *)(data + 0x4bc), *(u16 *)(buffer + 0x18));
        entry++;
        size += 0x3ec0;
        i++;
    }
}
#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_F1A24 */

/* fzgx:begin fn_1_F1B78 */
void fn_1_F1B78(u32 value) {
    lbl_1_bss_7C848[0] = value;
}
/* fzgx:end fn_1_F1B78 */

/* fzgx:begin fn_1_F1B84 */
u8 fn_1_F1B84(void) {
    return lbl_1_bss_7C8CD;
}
/* fzgx:end fn_1_F1B84 */

/* fzgx:begin fn_1_F1B94 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


extern s16 lbl_1_bss_960;


typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u32 unk_C;
u32 unk_10;
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u8 pad_28[0x4];
u8 arr_2C[0x1];
u8 unk_2D;
u8 unk_2E;
u8 unk_2F;
u8 arr_30[0x1];
u8 unk_31;
u8 unk_32;
u8 unk_33;
u8 arr_34[0x1];
u8 unk_35;
u8 unk_36;
u8 pad_37[0x1];
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u8 arr_44[0x4];
u32 unk_48;
u32 unk_4C;
u8 arr_50[0x1];
u8 unk_51;
u16 unk_52;
u8 arr_54[0x13B0];
u32 unk_1404;
u8 arr_1408[0x1F8];
u32 unk_1600;
u8 arr_1604[0x10];
u32 unk_1614;
u8 arr_1618[0x10];
u32 unk_1628;
u8 arr_162C[0x10];
u32 unk_163C;
u8 arr_1640[0x10];
u32 unk_1650;
u8 arr_1654[0x10];
u32 unk_1664;
u8 arr_1668[0x10];
u32 unk_1678;
u8 arr_167C[0x10];
u32 unk_168C;
u8 arr_1690[0x10];
u32 unk_16A0;
u8 arr_16A4[0x10];
u32 unk_16B4;
u8 arr_16B8[0x10];
u32 unk_16C8;
u8 unk_16CC;
u8 pad_16CD[0x3];
u32 unk_16D0;
u32 unk_16D4;
u32 unk_16D8;
u32 unk_16DC;
u8 unk_16E0;
u8 pad_16E1[0x3];
u32 unk_16E4;
u32 unk_16E8;
u32 unk_16EC;
u32 unk_16F0;
u32 unk_16F4;
u32 unk_16F8;
u32 unk_16FC;
u32 unk_1700;
u32 unk_1704;
u32 unk_1708;
u32 unk_170C;
u32 unk_1710;
u32 unk_1714;
u32 unk_1718;
u32 unk_171C;
u32 unk_1720;
u32 unk_1724;
u32 unk_1728;
u32 unk_172C;
u32 unk_1730;
u32 unk_1734;
u32 unk_1738;
u32 unk_173C;
u32 unk_1740;
u32 unk_1744;
u32 unk_1748;
u8 unk_174C;
u8 unk_174D;
u8 unk_174E;
u8 pad_174F[0x1];
u32 unk_1750;
u8 unk_1754;
u8 pad_1755[0x3];
f32 unk_1758;
f32 unk_175C;
f32 unk_1760;
u8 pad_1764[0x30];
u32 unk_1794;
u8 arr_1798[0x10];
u32 unk_17A8;
u8 arr_17AC[0x10];
u32 unk_17BC;
u32 unk_17C0;
u32 unk_17C4;
u32 unk_17C8;
u32 unk_17CC;
u16 unk_17D0;
u16 unk_17D2;
u16 unk_17D4;
u16 unk_17D6;
u16 unk_17D8;
u8 pad_17DA[0x2];
u32 unk_17DC;
u32 unk_17E0;
u32 unk_17E4;
u32 unk_17E8;
u32 unk_17EC;
u8 unk_17F0;
u8 unk_17F1;
u8 unk_17F2;
u8 unk_17F3;
u8 unk_17F4;
u8 unk_17F5;
u8 unk_17F6;
u8 unk_17F7;
u8 unk_17F8;
u8 unk_17F9;
u8 unk_17FA;
u8 unk_17FB;
u8 unk_17FC;
u8 unk_17FD;
u8 unk_17FE;
u8 pad_17FF[0x1];
u16 unk_1800;
u8 arr_1802[0xA];
u8 arr_180C[0x14];
u32 unk_1820;
u32 unk_1824;
u8 arr_1828[0x10];
u16 unk_1838;
s16 unk_183A;
u32 unk_183C;
u8 pad_1840[0x18];
u8 arr_1858[0x80];
u8 arr_18D8[0x30];
u8 arr_1908[0xC0];
u8 arr_19C8[0x620];
u32 unk_1FE8;
u16 unk_1FEC;
u8 pad_1FEE[0x76];
u32 unk_2064;
u32 unk_2068;
u32 unk_206C;
u8 pad_2070[0x64];
u8 arr_20D4[0x60];
u8 arr_2134[0xB4];
f32 unk_21E8;
u8 pad_21EC[0x20];
f32 unk_220C;
u8 pad_2210[0x24D];
u8 unk_245D;
u8 pad_245E[0x141A];
u32 unk_3878;
u32 unk_387C;
u8 unk_3880;
u8 pad_3881[0x3];
u32 unk_3884;
u32 unk_3888;
u8 unk_388C;
u8 pad_388D[0x3];
u32 unk_3890;
u32 unk_3894;
u32 unk_3898;
f32 unk_389C;
f32 unk_38A0;
u8 unk_38A4;
u8 unk_38A5;
u8 unk_38A6;
u8 pad_38A7[0x1];
u32 unk_38A8;
u32 unk_38AC;
u32 unk_38B0;
u32 unk_38B4;
u32 unk_38B8;
f32 unk_38BC;
u32 unk_38C0;
u8 arr_38C4[0x30];
u8 arr_38F4[0xC0];
u32 unk_39B4;
u32 unk_39B8;
u32 unk_39BC;
u8 arr_39C0[0x30];
u32 unk_39F0;
u8 arr_39F4[0x10];
u8 arr_3A04[0x30];
u8 arr_3A34[0xC0];
u8 arr_3AF4[0xC];
u8 arr_3B00[0x30];
u32 unk_3B30;
u8 arr_3B34[0x8];
u32 unk_3B3C;
u32 unk_3B40;
u32 unk_3B44;
u8 pad_3B48[0x2];
u16 unk_3B4A;
u8 pad_3B4C[0x30];
u32 unk_3B7C;
u8 arr_3B80[0x58];
u32 unk_3BD8;
} Obj_1_bss_7B180;
extern Obj_1_bss_7B180 lbl_1_bss_7B180;


extern u8 *fn_1_3F0D8(u32 index, f32 *value, u8 *flag);
u32 fn_1_F1B94(void) {
f32 a;
u8 b;
u8 *base = (u8 *)&lbl_1_bss_7B180;
u8 *rec;
u32 result;
u8 *cur;
u32 t0;
u32 t1;
if (*(s16 *)&lbl_1_bss_960 == 9) {
if (*(s32 *)(base + 0x16c8) >= 0) {
rec = fn_1_3F0D8(0, &a, &b);
cur = *(u8 **)(base + 0x16b4);
result = 1;
t0 = rec[0x1e0] * 60000 + rec[0x1e1] * 1000 + *(u16 *)(rec + 0x1e2);
t1 = cur[0x24] * 60000 + cur[0x25] * 1000 + *(u16 *)(cur + 0x26);
if (t0 >= t1) {
result = 3;
}
return result;
}
return 0;
}
return *(u8 *)(base + 0x174c);
}
/* fzgx:end fn_1_F1B94 */

/* fzgx:begin fn_1_F1C54 noprologue */
#include "rel/main_rel/ghost.h"

extern int sprintf(char *, const char *, ...);
typedef struct {
    u8 pad_0[0x20];
    s32 unk_20;
    u8 pad_24[0x16cc - 0x24];
    u8 unk_16CC;
    u8 pad_16cd[0x174e - 0x16cd];
    u8 unk_174E;
    u8 pad_174f[0x3b80 - 0x174f];
    u8 unk_3B80[1][0x11];
} GhostState;
#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C__fzgx_offset_0;
s32 lbl_1_bss_7B19C__fzgx_offset_4;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[177];
u32 lbl_1_bss_7C848__fzgx_offset_0;
u8 lbl_1_bss_7C848__fzgx_offset_4;
u8 lbl_1_bss_7C848__fzgx_offset_5;
u16 lbl_1_bss_7C848__fzgx_offset_6;
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE__fzgx_offset_1;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[14];
u32 lbl_1_bss_7EA38[159];
u32 fzgx_obj_lbl_1_bss_7ECB4[18];
u32 lbl_1_bss_7ECFC__fzgx_offset_0;
u8 lbl_1_bss_7ECFC__fzgx_offset_4[1][0x11];
u8 lbl_1_bss_7ECFC__fzgx_offset_15;
u16 lbl_1_bss_7ECFC__fzgx_offset_16;
u32 lbl_1_bss_7ECFC__fzgx_offset_18[17];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7B19C__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_5;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECB4;
    s = *(u8 *)&lbl_1_bss_7ECFC__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7ECFC__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7ECFC__fzgx_offset_15;
    s = *(u8 *)&lbl_1_bss_7ECFC__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_7ECFC__fzgx_offset_18;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("STAFF");
    OSReport("G%d");
}
#pragma section code_type ".text"

u8 *fn_1_F1C54(s32 index) {
    
    u8 v = lbl_1_bss_7C848__fzgx_offset_4;
    const char *lab_t1;
    if (v != 0xff) {
        if ((index == (s32)lbl_1_bss_7C8CE - 1 && lbl_1_bss_7B19C__fzgx_offset_4 == 0) ||
            (index == (s32)lbl_1_bss_7C8CE - 2 && lbl_1_bss_7B19C__fzgx_offset_4 != 0)) {
            lab_t1 = (const char *)"STAFF";
            sprintf((char *)lbl_1_bss_7ECFC__fzgx_offset_4[index], lab_t1);
            goto done; /* Keep the verified branch to done. */
        }
    }
    if (v != 0xff && index == (s32)lbl_1_bss_7C8CE - 1 && lbl_1_bss_7B19C__fzgx_offset_4 != 0) {
        lab_t1 = (const char *)"G%d";
        sprintf((char *)lbl_1_bss_7ECFC__fzgx_offset_4[index], lab_t1, index);
    } else {
        lab_t1 = (const char *)"G%d";
        sprintf((char *)lbl_1_bss_7ECFC__fzgx_offset_4[index], lab_t1, index + 1);
    }
done:
    return (u8 *)lbl_1_bss_7ECFC__fzgx_offset_4[index];
}
#pragma opt_propagation reset
/* fzgx:end fn_1_F1C54 */

/* fzgx:begin fn_1_F1D60 */
u32 fn_1_F1D60(void) {
    return lbl_1_bss_7C948;
}
/* fzgx:end fn_1_F1D60 */

/* fzgx:begin fn_1_F1D70 */
void fn_1_F1D70(void) {
    lbl_1_bss_7E9E8.unk_0 = 0;
    lbl_1_bss_7E9E8.unk_4 = 0;
    lbl_1_bss_7E9E8.unk_8 = 0;
    lbl_1_bss_7E9E8.unk_C = 0;
}
/* fzgx:end fn_1_F1D70 */

/* fzgx:begin fn_1_F1D8C */
void fn_1_F1D8C(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 |= 1 << index;
        return;
    }
    if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 |= 1 << (index - 0x20);
        return;
    }
    if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 |= 1 << (index - 0x40);
        return;
    }
    lbl_1_bss_7E9E8.unk_C |= 1 << (index - 0x60);
}
/* fzgx:end fn_1_F1D8C */

/* fzgx:begin fn_1_F1E30 */
void fn_1_F1E30(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 &= ~(1 << index);
    } else if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 &= ~(1 << (index - 0x20));
    } else if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 &= ~(1 << (index - 0x40));
    } else {
        lbl_1_bss_7E9E8.unk_C &= ~(1 << (index - 0x60));
    }
}
/* fzgx:end fn_1_F1E30 */

/* fzgx:begin fn_1_F1ED0 */
void fn_1_F1ED0(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 ^= 1 << index;
        return;
    }
    if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 ^= 1 << (index - 0x20);
        return;
    }
    if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 ^= 1 << (index - 0x40);
        return;
    }
    lbl_1_bss_7E9E8.unk_C ^= 1 << (index - 0x60);
}
/* fzgx:end fn_1_F1ED0 */

/* fzgx:begin ghost_test_flag */
// Tests whether a ghost flag is set in the corresponding 32-bit flag word.
u32 ghost_test_flag(s32 index) {
    if (index < 0x20) {
        return lbl_1_bss_7E9E8.unk_0 & (1 << index);
    }
    if (index < 0x40) {
        return lbl_1_bss_7E9E8.unk_4 & (1 << (index - 0x20));
    }
    if (index < 0x60) {
        return lbl_1_bss_7E9E8.unk_8 & (1 << (index - 0x40));
    }
    return lbl_1_bss_7E9E8.unk_C & (1 << (index - 0x60));
}
/* fzgx:end ghost_test_flag */

/* fzgx:begin fn_1_F2008 */
// Records the flag for the ghost entry identified by the decoded pair.
void fn_1_F2008(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *ghost_data;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    ghost_data = (u8 *)&lbl_1_bss_7F0C0;
    ghost_data[0x4938 + index] |= 1;
}
/* fzgx:end fn_1_F2008 */

/* fzgx:begin ghost_test_record_flag0 */
// Tests the record flag selected by the supplied ghost identifier.
u32 ghost_test_record_flag0(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *record_flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    record_flags = (u8 *)&lbl_1_bss_7F0C0;
    return record_flags[0x4938 + index] & 1;
}
/* fzgx:end ghost_test_record_flag0 */

/* fzgx:begin ghost_set_record_flag1 */
// Sets the second record flag for the record associated with arg.
void ghost_set_record_flag1(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *record_flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    record_flags = (u8 *)&lbl_1_bss_7F0C0;
    record_flags[0x4938 + index] |= 2;
}
/* fzgx:end ghost_set_record_flag1 */

/* fzgx:begin fn_1_F210C */
u32 fn_1_F210C(s32 arg) {
    s16 out_a;
    s16 out_b;
    s32 index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &out_a, &out_b);
    index = (out_a - 1) * 6 + out_b;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    return flags[0x4938 + index] & 2;
}
/* fzgx:end fn_1_F210C */

/* fzgx:begin ghost_set_record_flag2 */
// Set the second flag on the record selected by the argument.
void ghost_set_record_flag2(s32 arg) {
    s16 record_group;
    s16 record_index;
    s32 flag_index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &record_group, &record_index);
    flag_index = (record_group - 1) * 6 + record_index;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    flags[0x4938 + flag_index] |= 4;
}
/* fzgx:end ghost_set_record_flag2 */

/* fzgx:begin fn_1_F21B8 */
// Return the selected record's second flag bit after decoding its table position.
s32 fn_1_F21B8(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    return flags[0x4938 + index] & 4;
}
/* fzgx:end fn_1_F21B8 */

/* fzgx:begin fn_1_F220C */
// Logs the resolved course coordinates and marks the corresponding course as visited.
void fn_1_F220C(s32 arg) {
    s16 a;
    s16 b;
    s32 index;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    OSReport((const char *)lbl_1_data_3E8A0, a, b, index);
    ((u8 *)&lbl_1_bss_7F0C0)[0x4938 + index] |= 8;
}
/* fzgx:end fn_1_F220C */

/* fzgx:begin fn_1_F2280 */
// Returns the flag for the state selected by the converted coordinates.
s32 fn_1_F2280(s32 arg) {
    s16 group;
    s16 entry;
    s32 index;
    u8 *state_flags;

    fn_1_12EF80((s16)arg, &group, &entry);
    index = (group - 1) * 6 + entry;
    state_flags = (u8 *)&lbl_1_bss_7F0C0;
    return state_flags[0x4938 + index] & 8;
}
/* fzgx:end fn_1_F2280 */

/* fzgx:begin fn_1_F22D4 */
u32 fn_1_F22D4(void) {
    return lbl_1_bss_7B190[0];
}
/* fzgx:end fn_1_F22D4 */

/* fzgx:begin fn_1_F23D8 */
void fn_1_F23D8(void) {
    lbl_1_bss_7ED58[0] = 0;
}
/* fzgx:end fn_1_F23D8 */

/* fzgx:begin fn_1_F23E8 pool noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} GhostVec;

typedef struct {
    u8 unk_00[0x328];
    s8 unk_328;
    u8 unk_329[0x0B];
    void ***unk_334;
} GhostEntry;

/* One per-player camera record, 0x620 bytes (stride used by fn_1_EE3F4). */
typedef struct {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0x7C - 0x8];
    GhostVec unk_7C;
    u8 pad_88[0xEC - 0x88];
    u8 unk_EC[0x14C - 0xEC];
    u8 unk_14C[0x200 - 0x14C];
    f32 unk_200;
    u8 pad_204[0x224 - 0x204];
    f32 unk_224;
    u8 pad_228[0x475 - 0x228];
    u8 unk_475;
    u8 pad_476[0x620 - 0x476];
} GhostCamera;

typedef struct {
    f32 m[3][4];
} GhostMtx;

typedef struct {
    f32 x, y, z, w;
} GhostQuat;

extern s16 lbl_1_bss_960;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u8 lbl_1_bss_7B180__fzgx_offset_8[0x1600 - 0x8];
u32 lbl_1_bss_7B180__fzgx_offset_1600;
u8 lbl_1_bss_7B180__fzgx_offset_1604[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1614;
u8 lbl_1_bss_7B180__fzgx_offset_1618[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1628;
u8 lbl_1_bss_7B180__fzgx_offset_162C[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_163C;
u8 lbl_1_bss_7B180__fzgx_offset_1640[0x88];
s32 lbl_1_bss_7B180__fzgx_offset_16C8;
u8 lbl_1_bss_7B180__fzgx_offset_16CC[0x20];
u32 lbl_1_bss_7B180__fzgx_offset_16EC;
u8 lbl_1_bss_7B180__fzgx_offset_16F0[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1700;
u8 lbl_1_bss_7B180__fzgx_offset_1704[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1714;
u8 lbl_1_bss_7B180__fzgx_offset_1718[0x10];
u32 lbl_1_bss_7B180__fzgx_offset_1728;
u8 lbl_1_bss_7B180__fzgx_offset_172C[0x68];
GhostEntry *lbl_1_bss_7B180__fzgx_offset_1794;
u8 lbl_1_bss_7B180__fzgx_offset_1798[0x8C];
s32 lbl_1_bss_7B180__fzgx_offset_1824;
u8 lbl_1_bss_7B180__fzgx_offset_1828[0x19C8 - 0x1828];
GhostCamera lbl_1_bss_7B180__fzgx_offset_19C8[4];
u8 lbl_1_bss_7B180__fzgx_offset_3248[0x3BD8 - 0x3248];
s32 lbl_1_bss_7B180__fzgx_offset_3BD8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1600;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1604;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1614;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1618;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1628;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_162C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_163C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1640;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16C8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16CC;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16EC;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_16F0;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1700;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1704;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1714;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1718;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1728;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_172C;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1794;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1798;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1824;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_1828;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_19C8;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_3248;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_3BD8;
}
#pragma section code_type ".text"

#define ghostCameras lbl_1_bss_7B180__fzgx_offset_19C8
#define ghostEntry lbl_1_bss_7B180__fzgx_offset_1794
#define ghostFrame lbl_1_bss_7B180__fzgx_offset_1824
#define ghostTimer lbl_1_bss_7B180__fzgx_offset_3BD8

extern const f32 lbl_1_rodata_6B60;  /* 0.0f */
extern const f32 lbl_1_rodata_6BBC;  /* 0.5f */
extern const f32 lbl_1_rodata_6BD0;  /* 1.0f */
extern const f64 lbl_1_rodata_6C88;  /* 2^52 + 2^31 */
extern const f32 lbl_1_rodata_6C90;  /* 0.3f */
extern const f32 lbl_1_rodata_6D3C;  /* 5.0f */
extern const f32 lbl_1_rodata_6D40;  /* 2.5f */
extern const f32 lbl_1_rodata_6D54;  /* 120.0f */
extern const f32 lbl_1_rodata_6D58;  /* 0.34f */

extern u32 fn_1_F5458(GhostQuat *, s32, u32, u32, f32);
extern f32 fn_1_F4E3C(s32, u32, u32, u32, f32);
extern void fn_1_556B8(void *);
extern void fn_1_55FF0(f32);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_983CC(void *, GhostEntry *);
extern void fn_1_98634(f32);
extern void fn_80072558(void);
extern void fn_80074A60(u32, u32);
extern void fn_80074A6C(void);
extern void lbl_8006D758(void);
extern void lbl_8006D7DC(GhostVec *);
extern void lbl_8006DB74(void *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(GhostVec *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_from_quat(GhostQuat *);

#pragma opt_dead_assignments off
void fn_1_F23E8(void) {
    GhostMtx mtx;
    GhostQuat quat;
    GhostVec pos;
    f32 height;
    f32 scale;
    f32 t;
    f32 lab_t4;
    f32 lab_t4_;

    if (lbl_1_bss_960 == 9 && lbl_1_bss_7B180__fzgx_offset_16C8 != -1) {
        lab_t4_ = lbl_1_rodata_6B60;
        fn_1_F5458(&quat, ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_1728, lab_t4_);
        lab_t4 = lbl_1_rodata_6B60;
        pos.x = fn_1_F4E3C(ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_1614, lbl_1_bss_7B180__fzgx_offset_16EC, lab_t4);
        lab_t4 = lbl_1_rodata_6B60;
        pos.y = fn_1_F4E3C(ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_1628, lbl_1_bss_7B180__fzgx_offset_1700, lab_t4);
        lab_t4 = lbl_1_rodata_6B60;
        pos.z = fn_1_F4E3C(ghostFrame, lbl_1_bss_7B180__fzgx_offset_1600, lbl_1_bss_7B180__fzgx_offset_163C, lbl_1_bss_7B180__fzgx_offset_1714, lab_t4);

        if (ghostTimer > 180 && ghostTimer < 300) {
            height = ghostTimer - 180;
            height /= lbl_1_rodata_6D54;
            scale = height * height;
            height = height * lbl_1_rodata_6D58;
        } else if (ghostTimer >= 300) {
            height = lbl_1_rodata_6D58;
            scale = lbl_1_rodata_6BD0;
        } else {
            height = lbl_1_rodata_6B60;
            scale = height;
        }

        fn_1_56298(lbl_1_rodata_6B60, lbl_1_rodata_6B60, lbl_1_rodata_6B60, lbl_1_rodata_6B60);
        fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
        fn_80074A60(4, 1);
        mathutil_mtxA_from_quat(&quat);
        lbl_8006DB74(&mtx);

        ghostCameras[1].unk_7C = pos;
        ghostCameras[1].unk_7C.y += height;
        lbl_8006D7DC(&ghostCameras[1].unk_7C);
        lbl_8006DB74(ghostCameras[1].unk_14C);
        ghostCameras[1].unk_224 = lbl_1_rodata_6D3C * scale;
        ghostCameras[1].unk_200 = lbl_1_rodata_6D40 * scale;
        lbl_8006DCA4();
        lbl_8006E0A4(&pos);
        lbl_8006E0B4(lbl_1_rodata_6B60, height, lbl_1_rodata_6B60);
        lbl_8006DFC4(&mtx);
        fn_80072558();
        fn_1_55FF0(lbl_1_rodata_6BBC * scale);
        fn_1_556B8(*ghostEntry->unk_334);
        fn_1_55FF0(lbl_1_rodata_6BD0);
        fn_80074A6C();

        if (ghostTimer == 0) {
            ghostCameras[1].unk_4 = -2;
            if (ghostEntry != NULL) {
                ghostCameras[1].unk_6 = ghostEntry->unk_328;
            }
            ghostCameras[1].unk_7C = pos;
            ghostCameras[1].unk_0 = 0x400;
            lbl_8006D758();
            lbl_8006DB74(ghostCameras[1].unk_EC);
            ghostCameras[1].unk_475 = 0;
            ghostCameras[1].unk_224 = lbl_1_rodata_6D3C;
            ghostCameras[1].unk_200 = lbl_1_rodata_6D40;
            lbl_8006D7DC(&pos);
            lbl_8006DB74(ghostCameras[1].unk_14C);
            fn_1_98634(lbl_1_rodata_6C90);
            fn_1_983CC(&ghostCameras[1], ghostEntry);
            fn_1_98634(lbl_1_rodata_6B60);
        }
        ghostTimer++;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_F23E8 */
