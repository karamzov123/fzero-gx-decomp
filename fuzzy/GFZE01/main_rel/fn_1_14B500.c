/* Non-matching: best partial attempt (93.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern int fn_1_3F864(void);
extern void fn_1_A2D84(u32 value);

typedef struct {
	u32 unk_0;
	u32 unk_4;
	u8 pad_8[0x10];
	u16 unk_18;
	u8 unk_1A;
	u8 unk_1B;
	u8 unk_1C;
	u8 pad_1D[0x1B];
} DstPart_1_14B500;

typedef struct {
	DstPart_1_14B500 part[2];
} DstEnt_1_14B500;

typedef struct {
	u32 unk_0;
} Frame_1_14B500;

extern Frame_1_14B500 lbl_801A66A4;

static inline u8 fn_1_14B500_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_common_subs off
#pragma opt_propagation off
static inline DstPart_1_14B500 *fn_1_14B500_array_read_(DstPart_1_14B500 *array) { return array; }
#pragma opt_propagation reset

#pragma opt_lifetimes off
#pragma opt_propagation off
void fn_1_14B500(void) {
	Obj_1_bss_3C30 *obj;
	u32 off24;
	u32 off38;
	u32 off18;
	DstEnt_1_14B500 *dst;
	u8 *p;
	u8 *slot;
	u8 *rec;
	u8 b;
	s32 i;
	s32 flag;

	obj = &lbl_1_bss_3C30;
	dst = (DstEnt_1_14B500 *)&lbl_1_bss_8EF68;
	off24 = obj->unk_A7 * 4 + 0x24;
	off38 = obj->unk_A7 * 4 + 0x38;
	off18 = obj->unk_A7 * 2 + 0x18;
	p = (u8 *)obj;
	for (i = 0; i < 5; i++) {
		(*((0) + (dst->part))).unk_1A = fn_1_14B500_array_read(0xE, p);
		b = fn_1_14B500_array_read(0xF, p);
		p += 2;
		slot = (u8 *)obj + (*((0) + (dst->part))).unk_1A * 0xA0;
		rec = slot + 0xD4;
		(*((0) + (dst->part))).unk_0 = *(u32 *)(rec + off24);
		(*((0) + (dst->part))).unk_4 = *(u32 *)(rec + off38);
		(*((0) + (dst->part))).unk_18 = *(u16 *)(rec + off18);
		(*((0) + (dst->part))).unk_1B = fn_1_14B500_array_read(0x80, rec);
		(*((0) + (dst->part))).unk_1C = fn_1_14B500_array_read(0x81, rec);
		(*((1) + (dst->part))).unk_1A = b;
		slot = (u8 *)obj + (*((1) + (dst->part))).unk_1A * 0xA0;
		rec = slot + 0xD4;
		(*((1) + (dst->part))).unk_0 = *(u32 *)(rec + off24);
		(*((1) + (dst->part))).unk_4 = *(u32 *)(rec + off38);
		(*((1) + (dst->part))).unk_18 = *(u16 *)(rec + off18);
		(*((1) + (dst->part))).unk_1B = fn_1_14B500_array_read(0x80, rec);
		(*((1) + (dst->part))).unk_1C = fn_1_14B500_array_read(0x81, rec);
		dst++;
	}
	if (fn_1_3F864() != 0) {
		fn_1_A2D84(0xA9070000);
	}
	flag = lbl_1_bss_8E540;
	if (flag != 0) {
		lbl_1_bss_8E528 = lbl_801A66A4.unk_0 - 0xBE;
	}
	if (flag == 0) {
		lbl_1_bss_8E540 = 1;
	}
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset

