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

/* fzgx:begin fn_1_F1C54 pool noprologue */
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
u32 lbl_1_bss_7B19C_fill_7B19C;
s32 lbl_1_bss_7B19C_4;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[177];
u32 lbl_1_bss_7C848_fill_7C848;
u8 lbl_1_bss_7C848_4;
u8 lbl_1_bss_7C848_fill_7C84D;
u16 lbl_1_bss_7C848_fill_7C84E;
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE_fill_7C8CF;
u32 lbl_1_bss_7C8CE_fill_7C8D0[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[14];
u32 lbl_1_bss_7EA38[159];
u32 fzgx_obj_lbl_1_bss_7ECB4[18];
u32 lbl_1_bss_7ECFC_fill_7ECFC;
u8 lbl_1_bss_7ECFC_4[1][0x11];
u8 lbl_1_bss_7ECFC_fill_7ED11;
u16 lbl_1_bss_7ECFC_fill_7ED12;
u32 lbl_1_bss_7ECFC_fill_7ED14[17];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C_fill_7B19C;
    s = *(u8 *)&lbl_1_bss_7B19C_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C848;
    s = *(u8 *)&lbl_1_bss_7C848_4;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84D;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84E;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8CF;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECB4;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ECFC;
    s = *(u8 *)&lbl_1_bss_7ECFC_4;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ED11;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ED12;
    s = *(u8 *)&lbl_1_bss_7ECFC_fill_7ED14;
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
    
    u8 v = lbl_1_bss_7C848_4;
    const char *lab_t1;
    if (v != 0xff) {
        if ((index == (s32)lbl_1_bss_7C8CE - 1 && lbl_1_bss_7B19C_4 == 0) ||
            (index == (s32)lbl_1_bss_7C8CE - 2 && lbl_1_bss_7B19C_4 != 0)) {
            lab_t1 = (const char *)"STAFF";
            sprintf((char *)lbl_1_bss_7ECFC_4[index], lab_t1);
            goto done; /* Keep the verified branch to done. */
        }
    }
    if (v != 0xff && index == (s32)lbl_1_bss_7C8CE - 1 && lbl_1_bss_7B19C_4 != 0) {
        lab_t1 = (const char *)"G%d";
        sprintf((char *)lbl_1_bss_7ECFC_4[index], lab_t1, index);
    } else {
        lab_t1 = (const char *)"G%d";
        sprintf((char *)lbl_1_bss_7ECFC_4[index], lab_t1, index + 1);
    }
done:
    return (u8 *)lbl_1_bss_7ECFC_4[index];
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
