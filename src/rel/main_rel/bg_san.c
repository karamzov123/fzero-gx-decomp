#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"

extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_9A508(void);
extern void *fn_1_9D260();
extern void fn_1_72648(void);
extern void fn_1_103090(void *);
extern void fn_1_1030A4(void *);
extern void *fn_1_54448(s32);
extern void *fn_1_548AC(s32);
extern void fn_1_5489C(void *, void *);
extern void lbl_8006DCA4();
extern void fn_1_103264(void *, void *);

/* fzgx:begin fn_1_D720C */
#include "rel/main_rel/bg_lig.h"

extern void fn_80008BA8(void *arg0, void *arg1, int arg2);
extern u32 lbl_801A63D0;
extern u32 fn_1_76504(s32, void *, s32);
extern void fn_1_7269C(u32, s32, u32);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388(void *obj);
extern void fn_1_627C(s32 index);
struct LigDrawEntry;
extern void fn_1_D7B7C(struct LigDrawEntry *base);
extern void *memset(void *dst, int value, u32 size);
extern s32 fn_1_54E34(void *obj, f32 value);
struct LigLightObj;
extern void fn_1_D83E4(struct LigLightObj *obj, u32 index);
struct LigSeg;
extern void fn_1_D7A10(struct LigSeg *obj);

extern void fn_1_D9224();
extern void fn_1_D9D8C();
extern void fn_1_DA3A0(void *state);
extern void fn_1_E87FC(void);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66A0;
extern void fn_1_4404(void);
extern void fn_1_DA6A8(void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_446C(void);
extern void fn_1_76BF8(void);

void fn_1_D720C(void) {
    u32 local[4] = {0, 0x0280012C, 0, 1};
    u32 result;

    result = fn_1_76504(0x1d, local, 0);
    fn_1_7269C(result, 0, lbl_801A63D0);
}
/* fzgx:end fn_1_D720C */

/* fzgx:begin fn_1_D7274 */
#include "rel/main_rel/bg_lig.h"

extern s32 fn_1_58C4(void);
extern void fn_1_D79E4(void *);
extern u8 fn_1_5300(void);
extern void fn_1_77B80(u32);
extern void fn_1_76BF8(void);

extern void fn_1_4404(void);
extern void fn_1_DA6A8(void *, u32);
extern void fn_1_D9224();
extern void fn_1_446C(void);
extern void fn_1_D9D8C();
extern void fn_1_DA3A0(void *state);
extern void fn_80008BEC(void *, int, u32);

#pragma opt_pointer_analysis on
void fn_1_D7274(void) {
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_bss_7AD78 *state;
    Obj_1_bss_7AD78 *state2;
    s32 i;
    s32 mode;

    mode = fn_1_58C4();
    obj = lbl_1_data_2A7E0.unk_3C;
    obj->unk_6D4 = 0;
    fn_1_9A508();
    obj->unk_6C0 = (0.0f);
    fn_1_D79E4(obj);

    if (obj->unk_6CC != 0
        && (mode == 1 || (mode == 2 && fn_1_5300() == 1))) {
        fn_1_77B80(obj->unk_6CC);
    } else {
        fn_1_76BF8();
        fn_1_72648();
    }

    fn_1_D8CA8((fn_1_D8CA8_LigObject *)obj);
    fn_1_4404();

    if (lbl_1_bss_7AD78.unk_14 != 0) {
        fn_1_DA6A8(&lbl_1_bss_7AD78, obj->unk_1C58);
        fn_80008BEC(&lbl_1_bss_7AD78, 0, 0x20);
    }

    if (lbl_1_bss_7AD78.unk_34 != 0) {
        state = &lbl_1_bss_7AD78;
        state2 = (Obj_1_bss_7AD78 *)((u8 *)state + 0x20);
        fn_1_DA6A8(state2, obj->unk_1C5C);
        fn_80008BEC(state2, 0, 0x20);
    }

    if (obj->unk_1C58 != 0) {
        fn_80008BEC(&lbl_1_bss_7AD78, 0, 0x20);
        fn_1_D9224(&lbl_1_bss_7AD78, obj->unk_1C58);
    }

    if (obj->unk_1C5C) {
        state2 = (Obj_1_bss_7AD78 *)((u8 *)&lbl_1_bss_7AD78 + 0x20);
        fn_80008BEC(state2, 0, 0x20);
        fn_1_D9224(state2, obj->unk_1C5C);
    }

    fn_1_446C();
    state = &lbl_1_bss_7AD78;
    state2 = (Obj_1_bss_7AD78 *)((u8 *)state + 0x20);
    for (i = 0; i < 0x78; i++) {
        if (obj->unk_1C58 != 0) {
            fn_1_D9D8C(state, obj->unk_1C58, 0);
            fn_1_DA3A0(&lbl_1_bss_7AD78);
        }
        if (obj->unk_1C5C != 0) {
            fn_1_D9D8C(state2, obj->unk_1C5C, 1);
            fn_1_DA3A0(state2);
        }
    }
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_1_D7274 */

/* fzgx:begin fn_1_D744C */
extern void fn_80008BA8(void *arg0, void *arg1, int arg2);
extern u32 lbl_801A63D0;
extern u32 fn_1_76504(s32, void *, s32);
extern void fn_1_7269C(u32, s32, u32);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388(void *obj);
extern void fn_1_627C(s32 index);
struct LigDrawEntry;
extern void fn_1_D7B7C(struct LigDrawEntry *base);
extern void *memset(void *dst, int value, u32 size);


extern s32 fn_1_54E34(void *obj, f32 value);

extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388();
extern void fn_1_627C(s32 index);

// Initializes each available background-light entry.
void fn_1_D744C(void) {
    Obj_1_data_2A7E0_At3C *obj;
    s32 count;
    s32 i;

    obj = lbl_1_data_2A7E0.unk_3C;
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D8388(obj, i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_D744C */

/* fzgx:begin fn_1_D74C4 */
// Initializes background-light data and installs the completion callback.
void fn_1_D74C4(void) {
    Obj_1_bss_7AD78 *tmp;
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_data_2A7E0_At3C *arg;
    s32 count;
    s32 i;

    obj = lbl_1_data_2A7E0.unk_3C;
    arg = (Obj_1_data_2A7E0_At3C *)fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D83E4((struct LigLightObj *)obj, i);
        fn_1_627C(i);
    }

    fn_1_D7A10((struct LigSeg *)obj);
    fn_1_D8D58((fn_1_D8D58_LigObject *)obj, arg);
    if (obj->unk_1C58 != 0) {
        fn_1_D9D8C(&lbl_1_bss_7AD78, obj->unk_1C58, 0);
        fn_1_DA3A0(&lbl_1_bss_7AD78);
    }
    if (obj->unk_1C5C != 0) {
        tmp = (Obj_1_bss_7AD78 *)((u8 *)&lbl_1_bss_7AD78 + 0x20);
        fn_1_D9D8C(tmp, obj->unk_1C5C, 1);
        fn_1_DA3A0(tmp);
    }
    lbl_1_data_2A7E0.unk_2C = (u32)fn_1_E87FC;
}
/* fzgx:end fn_1_D74C4 */

/* fzgx:begin fn_1_D75CC */
struct fn_1_D75CC_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

void fn_1_D75CC(void) {
    u32 *temp_r31;
    u32 temp_r30;
    u32 temp_r4;
    u32 temp_r4_2;

    temp_r30 = (*(struct fn_1_D75CC_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0).unk_3C;
    fn_1_4404();
    temp_r4 = *(u32 *)((u8 *)(temp_r30) + 7256);
    if (temp_r4 != 0) {
        fn_1_DA6A8(&lbl_1_bss_7AD78, temp_r4);
        fn_80008BEC(&lbl_1_bss_7AD78, 0, 0x20U);
        (*(u32 *)((u8 *)(temp_r30) + 7256)) = 0U;
    }
    temp_r4_2 = *(u32 *)((u8 *)(temp_r30) + 7260);
    if (temp_r4_2 != 0) {
        temp_r31 = (u32 *)((u8 *)(&lbl_1_bss_7AD78) + 0x20);
        fn_1_DA6A8(temp_r31, temp_r4_2);
        fn_80008BEC(temp_r31, 0, 0x20U);
        (*(u32 *)((u8 *)(temp_r30) + 7260)) = 0U;
    }
    fn_1_446C();
    fn_1_76BF8();
    fn_1_72648();
    fn_1_D8D08((LigContainer *)temp_r30);
}
/* fzgx:end fn_1_D75CC */

/* fzgx:begin fn_1_D7688 */
void fn_1_D7688(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    void *value = fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_D8784((fn_1_D8784_LigObject *)obj);
    fn_1_D7B7C((struct LigDrawEntry *)obj);
    fn_1_D8EEC((LigContainer *)obj, value);
    fn_1_9AD88();
}
/* fzgx:end fn_1_D7688 */

/* fzgx:begin fn_1_D76EC */
// fn_1_D76EC: empty in retail (single blr).
void fn_1_D76EC(void) {
}
/* fzgx:end fn_1_D76EC */

/* fzgx:begin fn_1_D76F0 */
// Copies a three-component float vector into the indexed light buffer entry.
void fn_1_D76F0(const f32 *src, s16 index) {
    f32 *dst = (f32 *)lbl_1_data_2A7E0.unk_3C;

    dst[index * 3] = src[0];
    dst += index * 3;
    dst[1] = src[1];
    dst[2] = src[2];
}
/* fzgx:end fn_1_D76F0 */

/* fzgx:begin fn_1_D7724 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3Bits;

// Copies the indexed three-word light entry to the caller-provided buffer.
void fn_1_D7724(Vec3Bits *dst, s16 index) {
    u32 *base = (u32 *)lbl_1_data_2A7E0.unk_3C;
    Vec3Bits *src = (Vec3Bits *)(base + index * 3);

    *dst = *src;
}
/* fzgx:end fn_1_D7724 */

/* fzgx:begin fn_1_D7758 */
typedef Vec3 Vec;

/* one of the 20 records of 0x30 bytes from lbl_1_data_2A7E0.unk_3C + 0x30 (fn_1_D79E4 clears them) */
typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    Vec unk_3C;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    s16 unk_58;
    s16 unk_5A;
    s16 unk_5C;
} Rec;

extern u32 lbl_801A63C0;
extern void lbl_8006D8D8(s32);
extern void lbl_8006E1C0(Vec *, Vec *);

/* one step of the executable's random generator, lbl_801A63C0 */
static inline s32 rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#pragma fp_contract off
void fn_1_D7758(Vec *pos, f32 scale) {
    f32 size = 100.0f * scale;
    f32 speed = 3.0f * scale;
    u8 *base = (u8 *)lbl_1_data_2A7E0.unk_3C;
    Rec *rec;
    s32 n = 0;
    s32 i = 0;
    f32 t;

    while (n < 5) {
        /* retail keeps the unreachable branch this if/else leaves (b; b) */
        if (i < 20) {
            rec = (Rec *)(base + i * 0x30);
        } else {
            return;
        }
        if (rec->unk_5C <= 0) {
            t = 0.7 + 0.3 * (rand() / 32767.0f);
            rec->unk_30 = pos->x;
            rec->unk_34 = pos->y;
            rec->unk_38 = pos->z;
            rec->unk_48 = 235.0f * t;
            rec->unk_4C = 80.0f * t;
            rec->unk_50 = 30.0f * t;
            rec->unk_54 = size;
            rec->unk_58 = 0;
            rec->unk_5A = 512.0 * ((rand() / 32767.0f) - 0.5);
            rec->unk_5C = scale * (300.0 * (0.7 + 0.3 * (rand() / 32767.0f)));
            rec->unk_3C.x = 0.0f;
            rec->unk_3C.z = speed;
            rec->unk_3C.y = scale * (17.0 * (0.3 + 0.7 * (rand() / 32767.0f)));
            lbl_8006D8D8(3276.8f * n);
            lbl_8006E1C0(&rec->unk_3C, &rec->unk_3C);
            n++;
        }
        i++;
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_D7758 */

/* fzgx:begin fn_1_D79E4 */
void fn_1_D79E4(void *obj) {
    memset((u8 *)obj + 0x30, 0, 0x3c0);
}
/* fzgx:end fn_1_D79E4 */

/* fzgx:begin fn_1_D7A10 */
typedef struct LigSeg {
	u8 pad0[0x30];
	f32 f30;
	f32 f34;
	f32 f38;
	f32 f3c;
	f32 f40;
	f32 f44;
	f32 f48;
	f32 f4c;
	f32 f50;
	f32 f54;
	s16 s58;
	s16 s5a;
	s16 s5c;
} LigSeg;

static inline f64 fn_1_D7A10_operand(f64 right, f64 left) { return left * right; }
static inline f64 fn_1_D7A10_operand_(f64 right, f64 left) { return left * right; }


void fn_1_D7A10(LigSeg *obj) {
	s32 i;

	for (i = 0; i < 0x14; i++) {
		if (obj->s5c > 0) {
			f64 t;

			obj->f3c = (fn_1_D7A10_operand((0.98), obj->f3c));
			{
			    f64 product_value = obj->f40;
			    product_value *= ((0.98));
			    obj->f40 = product_value;
			}
			{
			    f64 product = obj->f44;
			    product *= ((0.98));
			    obj->f44 = product;
			}
			obj->f40 = obj->f40 - 0.08f;
			obj->f30 = obj->f30 + obj->f3c;
			obj->f34 = obj->f34 + obj->f40;
			obj->f38 = obj->f38 + obj->f44;
			obj->s58 = obj->s58 + obj->s5a;
			obj->s5a = (fn_1_D7A10_operand_((0.99), obj->s5a));
			t = 0.02 * (400.0f - obj->f54);
			obj->f54 = obj->f54 + t;
			if (obj->s5c < 0x50) {
				f32 t = obj->s5c / 80.0f;

				obj->f48 = obj->f48 * t;
				obj->f4c = obj->f4c * t;
				obj->f50 = obj->f50 * t;
			}
			if (obj->s5c > 0) {
				obj->s5c--;
			}
		}
		obj = (LigSeg *)((u8 *)obj + 0x30);
	}
}
/* fzgx:end fn_1_D7A10 */

/* fzgx:begin fn_1_D7B7C */
typedef struct LigDrawEntry {
    u8 pad0[0x24];
    f32 value;
    u8 pad28[0x4];
    s16 count;
    u8 pad2e[0x2];
} LigDrawEntry;

struct LigEvt;
typedef struct {
    u8 pad0[0x4];
    void (*callback)(struct LigEvt *);
    LigDrawEntry *entry;
} LigEvent;



extern s32 fn_1_54E34(void *obj, f32 value);
extern void *fn_1_5448C(LigDrawEntry *entry);
extern void fn_1_D7C44(struct LigEvt *);

void fn_1_D7B7C(LigDrawEntry *base) {
    void *data;
    LigDrawEntry *entry;
    s32 i;
    LigEvent *event;

    lbl_8006DCA4();

    for (i = 0; i < 0x14; i++) {
        entry = base + i + 1;
        if (entry->count > 0 &&
            fn_1_54E34(entry, 0.70710677f * entry->value)) {
            data = fn_1_5448C(entry);
            event = fn_1_548AC(0xc);
            if (event != 0) {
                event->callback = fn_1_D7C44;
                event->entry = entry;
                fn_1_5489C(data, event);
            }
        }
    }
}
/* fzgx:end fn_1_D7B7C */

/* fzgx:begin fn_1_D7C44 */
#include "rel/main_rel/background.h"

typedef struct {
	u8 pad_0[0x18];
	f32 unk_18;
	f32 unk_1c;
	f32 unk_20;
	f32 unk_24;
	s16 unk_28;
} LigSrc;

typedef struct LigEvt {
	u8 pad_0[8];
	LigSrc *unk_8;
} LigEvt;

extern void *memset(void *dst, int value, u32 size);
extern void lbl_8006E1B0(void *a, void *b);
extern void lbl_8006D7DC(void *a);
extern void lbl_8006DB74(void *a);
extern void mathutil_mtxA_rotate_z(s16 angle);
extern void fn_80074788(u32);
extern void fn_80072864(u32);
extern void fn_80073778(void *, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006D758(void);

/* Retail emits this conversion inline at each of its three call sites: fn_1_D7C44's
   172 instructions contain no call to a scaling helper, and the symbol does not exist in
   symbols.txt. A plain `static` would emit it out of line and add 28 bytes of .text,
   which is what failed the 16-target link. Matches fn_1_D7C44_array_read below. */
static inline u8 scale_to_byte(f32 value, f32 scale) {
	return (value * scale);
}

static inline u32 fn_1_D7C44_array_read(s32 index, u32 *array) { return array[index]; }
void fn_1_D7C44(LigEvt *arg0) {
	BackgroundQuad obj;
	u32 stackbuf[3];
	LigSrc *src;
	u32 *unk;
	u32 handle;

	src = arg0->unk_8;
	unk = *(u32 **)(lbl_1_bss_38458->unk_8 + 0x170);
	lbl_8006DCA4();
	lbl_8006E1B0(src, stackbuf);
	lbl_8006D7DC(stackbuf);
	mathutil_mtxA_rotate_z(src->unk_28);
	memset(&obj, 0, 0x40);
	lbl_8006DB74(obj.mtx);
	obj.width = 0.70710677f * src->unk_24;
	obj.color.bytes[0] = scale_to_byte((u8)src->unk_18, 1.0f);
	obj.color.bytes[1] = scale_to_byte((u8)src->unk_1c, 1.0f);
	obj.color.bytes[2] = scale_to_byte((u8)src->unk_20, 1.0f);
	obj.color.bytes[3] = 0xFF;
	obj.flags |= 2;
	obj.height = 2.0 * obj.width;
	handle = fn_1_D7C44_array_read(9, unk);
	fn_80074788(0);
	fn_80072864(1);
	fn_80073778((void *)handle, 0);
	fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
	fn_800734A8(0, 0, 0, 0xff);
	fn_80072AB0(0, 0, 0);
	fn_800735C8(0, 0xc);
	fn_80073620(0, 0x1c);
	fn_80073C6C(0);
	fn_80072C24(0, 0xf, 0xe, 8, 0xf);
	fn_80072D64(0, 0, 0, 0, 1, 0);
	fn_80072CC4(0, 7, 6, 4, 7);
	fn_80072E20(0, 0, 0, 0, 1, 0);
	fn_80073678(1);
	fn_80074660(1);
	fn_80074918(1, 7, 0);
	fn_800720B0(0);
	fn_800728A8(1, 3, 1, 7);
	fn_80074918(1, 3, 0);
	lbl_8006D758();
	fn_1_9EDE8(&obj);
}
/* fzgx:end fn_1_D7C44 */

/* fzgx:begin fn_1_D7EF4 */
#include "mathutil_vec_cross_prod.h"
#include "rel/main_rel/bg_lig.h"

extern u32 lbl_801A63C0;
extern void *lbl_801A6D00;
extern void fn_1_681C(u8 index, void *out);
extern void fn_1_6898(u8, Vec3 *);
extern void fn_1_6914(u8, Vec3 *);
extern void fn_1_6990(u8, Vec3 *);
extern s16 camera_get_mode(void);
extern f32 fn_1_8652C(s32);
extern void fn_1_8636C(s32, void *);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern f32 fn_1_A71AC(void);
/* SMB1 mathutil_mtxA_tf_vec / mathutil_vec_normalize_len (DOL mathutil asm) */
extern void lbl_8006E1C0(Vec3 *src, Vec3 *dst);
extern f32 lbl_8006D668(void *);

#define LIG_CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

static inline s32 rand15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

// A rand15() value as a float in [-0.5, 0.5].
static inline f32 lig_randf(s32 r) {
    return r / 32767.0f - 0.5f;
}

// out = base + dir * len
static inline void lig_offset(Vec3 *out, Vec3 *base, Vec3 *dir, f32 len) {
    out->x = base->x + (f32)(dir->x * len);
    out->y = base->y + (f32)(dir->y * len);
    out->z = base->z + (f32)(dir->z * len);
}

// max scaled down by t
static inline f32 lig_fade(f32 t, f32 max) {
    return max - (f32)(t * max);
}

// Respawns a lighting entry at a random point in front of the camera.
void fn_1_D7EF4(LigParticle *e, u32 index) {
    Vec3 eye;
    Vec3 at;
    Vec3 target;
    Vec3 dir;
    Vec3 up;
    Vec3 side;
    Vec3 pos;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 mode;
    f32 scale;
    f32 base;
    f32 dist;
    f32 t;
    f32 s;
    f32 k;
    s32 r;

    fn_1_681C(index, &eye);
    fn_1_6898(index, &at);
    fn_1_6914(index, &target);
    fn_1_6990(index, &up);
    mode = camera_get_mode();
    if (mode < 0) {
        return;
    }
    scale = fn_1_8652C(mode);
    {
        Vec3 zero = {0.0f, 0.0f, 0.0f};
        pos = zero;
    }
    {
        Vec3 down = {0.0f, 0.0f, -1.0f};
        dir = down;
    }
    fn_1_8636C(mode, lbl_801A6D00);
    lbl_8006E1C0(&dir, &dir);
    lbl_8006D668(&dir);
    fn_1_A714C(&a, &b, &c, &d);
    pos = eye;
    t = (f32)(1.5f * (rand15() / 32767.0f)) - 0.5f;
    base = scale / 10.0f;
    r = rand15();
    dist = base + (c + (f32)(t * (100.0f - c)));
    lig_offset(&pos, &pos, &dir, dist);
    s = (dist / 10.0f) * fn_1_A71AC() * lig_randf(r);
    r = rand15();
    lig_offset(&pos, &pos, &up, s);
    mathutil_vec_cross_prod(&dir, &up, &side);
    s = b * (dist * fn_1_A71AC()) * lig_randf(r);
    lig_offset(&pos, &pos, &side, s);
    pos.x += 5.0f;
    e->pos = pos;
    k = LIG_CLAMP(lig_fade(t, 1.0f), 0.0f, 0.6f);
    e->scale.x = 170.0f * k;
    e->scale.y = 120.0f * k;
    e->scale.z = 32.0f * k;
    e->value = (90.0f + base) * (0.6f + (f32)(0.4f * (rand15() / 32767.0f)));
    e->phase = rand15();
    e->step = 768.0f * lig_randf(rand15());
    e->count = 15;
}
/* fzgx:end fn_1_D7EF4 */

/* fzgx:begin fn_1_D8388 */
extern s32 fn_1_58C4(void);

// Initializes each lighting entry while the lighting system is available.
void fn_1_D8388(void *obj) {
    u8 *entry = obj;
    s32 i;

    if ((u32)fn_1_58C4() < 2) {
        i = 0;
        do {
            fn_1_D7EF4((LigParticle *)(entry + 0x3f0), 0);
            i++;
            entry += 0x30;
        } while (i < 0xf);
    }
}
/* fzgx:end fn_1_D8388 */

/* fzgx:begin fn_1_D83E4 */
#include "rel/main_rel/bg_lig.h"
#include "rel/main_rel/bg_lig.h"

/* begin game/main_rel/bg_lig_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_LIG_TYPES_H
#define GAME_MAIN_REL_BG_LIG_TYPES_H

// Types (and the externs that name them) of bg_lig.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).



extern void fn_1_1030D4(fn_1_D8D58_LigEntry *entry, void *arg);

#endif  // GAME_MAIN_REL_BG_LIG_TYPES_H

/* end game/main_rel/bg_lig_types.h */

typedef Vec3 LigVec;

typedef struct LigLightObj {
    u8 pad_000[0x3f0];
    LigParticle entries[14];
    LigVec target;
    u8 pad_69c[0xc];
    f32 unk_6a8;
    f32 unk_6ac;
    f32 unk_6b0;
    f32 unk_6b4;
    u8 pad_6b8[0x4];
    s16 unk_6bc;
    u8 pad_6be[0x2];
    f32 unk_6c0;
} LigLightObj;

extern void fn_1_681C(u8 index, void *out);
extern void fn_1_6898(u8, LigVec *);
extern void fn_1_6914(u8, LigVec *);
extern s16 camera_get_mode(void);
extern s32 fn_1_58C4(void);
extern f32 fn_1_8652C(s32);
extern u32 fn_1_1FB80(LigVec *, s32);
extern s32 fn_1_66B8(void *, f32);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);

// Distance between an entry's position and a probe point.
static inline f32 lig_dist(LigParticle *e, LigVec *v) {
    f32 dx = e->pos.x;
    f32 dy = e->pos.y;
    f32 dz = e->pos.z;
    dx -= v->x;
    dy -= v->y;
    dz -= v->z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return lbl_8006D0B4(dx);
}

// out = base + dir * len
static inline void lig_target_offset(LigVec *out, LigVec *base, LigVec *dir, f32 len) {
    out->x = base->x + (f32)(dir->x * len);
    out->y = base->y + (f32)(dir->y * len);
    out->z = base->z + (f32)(dir->z * len);
}

// Updates the lighting entries and the light target for the current camera.
#pragma opt_propagation off
void fn_1_D83E4(LigLightObj *obj, u32 index) {
    LigVec cam;
    LigVec eye;
    LigVec from;
    LigVec to;
    LigVec dir;
    LigVec probe;
    u32 count;
    u32 j;
    LigLightObj *e;
    s32 i;
    s32 mode;
    u32 flags;
    f32 best;
    f32 drift_z;
    f32 drift_x;
    f32 scale;

    fn_1_681C(index, &cam);
    fn_1_6898(index, &eye);
    mode = camera_get_mode();
    if (mode < 0) {
        return;
    }
    if ((u32)fn_1_58C4() >= 2) {
        return;
    }
    scale = fn_1_8652C(mode);
    flags = fn_1_1FB80(&cam, 3);
    if (flags & 1) {
        obj->unk_6c0 = obj->unk_6c0 + (f64)(0.05 * (1.0f - obj->unk_6c0));
    } else if (flags & 2) {
        obj->unk_6c0 = obj->unk_6c0 + (f64)(0.05 * (0.5f - obj->unk_6c0));
    } else {
        obj->unk_6c0 = obj->unk_6c0 + (f64)(0.05 * -obj->unk_6c0);
    }

    drift_x = 2.5f;
    e = obj;
    drift_z = 0.1f;
    for (i = 0; i < 14; i++) {
        e->entries[0].pos.x += drift_x;
        e->entries[0].pos.z += drift_z;
        e->entries[0].phase += e->entries[0].step;
        count = fn_1_58C4();
        fn_1_681C(0, &probe);
        best = lig_dist(e->entries, &probe);
        for (j = 1; j < count; j++) {
            fn_1_681C(j, &probe);
            if (best < lig_dist(e->entries, &probe)) {
                best = best;
            } else {
                best = lig_dist(e->entries, &probe);
            }
        }
        if (fn_1_66B8(e->entries, e->entries[0].value) == 0) {
            e->entries[0].count++;
        } else if (best > 50.0f + scale / 10.0f) {
            e->entries[0].count++;
        } else if (e->entries[0].count > 0) {
            e->entries[0].count--;
        }
        if (e->entries[0].count > 15) {
            fn_1_D7EF4(e->entries, index);
        }
        e = (LigLightObj *)((u8 *)e + sizeof(LigParticle));
    }

    if (obj->unk_6bc > 0) {
        obj->unk_6bc--;
    }
    fn_1_681C(index, &from);
    fn_1_6914(index, &to);
    dir.x = to.x - from.x;
    dir.y = to.y - from.y;
    dir.z = to.z - from.z;
    lbl_8006D668(&dir);
    lig_target_offset(&obj->target, &from, &dir, 20.0f);
    obj->unk_6b4 = 70.0f;
    obj->unk_6a8 = 170.0f;
    obj->unk_6ac = 120.0f;
    obj->unk_6b0 = 33.0f;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_D83E4 */

/* fzgx:begin fn_1_D8784 */
struct LigSource;
extern void fn_1_D8878(struct LigSource *);
typedef void (*LigCallback)(struct LigSource *);

typedef struct {
    u32 unk_00;
    LigCallback callback;
    void *data;
} LigCallbackObject;

typedef struct {
    u8 pad_000[0x3f0];
    u8 callback_data[0x24];
    f32 scale;
} fn_1_D8784_LigEntry;

extern s32 fn_1_58C4(void);

// Queues callbacks for eligible lig entries.
void fn_1_D8784(fn_1_D8784_LigObject *obj) {
    void *callback_data;
    void *owner;
    u8 i;
    f32 factor;
    fn_1_D8784_LigEntry *entry;

    if ((u32)fn_1_58C4() >= 2) {
        return;
    }
    if (obj->threshold < 0.1f) {
        return;
    }

    factor = 0.70710677f;
    i = 0;
    for (; i < 0xf; i++) {
        lbl_8006DCA4();
        entry = (fn_1_D8784_LigEntry *)((u8 *)obj + (i * 0x30));
        callback_data = entry->callback_data;
        if (fn_1_54E34(callback_data, factor * entry->scale) != 0) {
            owner = fn_1_54448(0);
            {
                LigCallbackObject *callback = (LigCallbackObject *)fn_1_548AC(0xc);
                if (callback != 0) {
                    callback->callback = fn_1_D8878;
                    callback->data = callback_data;
                    fn_1_5489C(owner, callback);
                }
            }
        }
    }
}
/* fzgx:end fn_1_D8784 */

/* fzgx:begin fn_1_D8878 */
#include "rel/main_rel/background.h"

typedef Vec3 LigVec;

typedef struct LigSource {
    LigVec pos;      /* 0x00 */
    u8 pad_C[0xC];
    f32 r;           /* 0x18 */
    f32 g;           /* 0x1C */
    f32 b;           /* 0x20 */
    f32 size;        /* 0x24 */
    s16 angle;       /* 0x28 */
    u8 pad_2A[0x2];
    s16 fade;        /* 0x2C */
} LigSource;

typedef struct {
    u8 pad_0[0x8];
    LigSource *source;
} LigObject;

extern f32 lbl_8006D0B4(f32);
extern void lbl_8006E1B0(void *src, void *dst);
extern void lbl_8006D7DC(void *vec);
extern void mathutil_mtxA_rotate_z(s16 angle);
extern s32 fn_1_58C4(void);
extern void fn_1_681C(u8 index, void *out);
extern void lbl_8006DB74(void *matrix);
extern void lbl_8006D758(void);
extern void *memset(void *, int, u32);
extern void fn_80074788(u32);
extern void fn_80072864(u32);
extern void fn_80073778(void *, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(s32);
extern void fn_800728A8(s32, s32, s32, s32);

#define LIG_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIG_CLAMP01(x) ((x) < 0.0f ? 0.0f : ((x) > 1.0f ? 1.0f : (x)))

/* squared distance between two points, accumulated into len
 * (the first distance accumulates straight into the caller's variable) */
#define LIG_LEN2(len, a, b)      \
    do {                         \
        f32 x;                   \
        f32 z;                   \
        f32 y;                   \
        x = (a)->x;              \
        y = (a)->y;              \
        z = (a)->z;              \
        x -= (b)->x;             \
        y -= (b)->y;             \
        z -= (b)->z;             \
        len = x * x;           \
        (len) += y * y;          \
        (len) += z * z;          \
    } while (0)

/* distance between two points */
static inline f32 lig_source_dist(LigVec *a, LigVec *b) {
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    f32 len;

    x -= b->x;
    y -= b->y;
    z -= b->z;
    len = x * x;
    len += y * y;
    len += z * z;
    return lbl_8006D0B4(len);
}

/* src arrives as the owning object; its light source entry sits at +8 */
void fn_1_D8878(LigSource *src) {
    BackgroundQuad packet;
    LigVec tmp;
    LigVec cam;
    void *scene;
    int count;
    u32 i;
    void *view;
    Obj_1_data_2A7E0_At3C *env;
    f32 dist;
    f32 size;
    f32 bright;
    f32 scale;
    s16 fade;

    env = lbl_1_data_2A7E0.unk_3C;
    scene = *(void **)(lbl_1_bss_38458->unk_8 + 0x170);
    src = ((LigObject *)src)->source;

    lbl_8006DCA4();
    lbl_8006E1B0(&src->pos, &tmp);
    lbl_8006D7DC(&tmp);
    mathutil_mtxA_rotate_z(src->angle);

    count = fn_1_58C4();
    fn_1_681C(0, &cam);
    LIG_LEN2(dist, &src->pos, &cam);
    dist = lbl_8006D0B4(dist);
    for (i = 1; i < count; i++) {
        fn_1_681C(i, &cam);
        dist = LIG_MIN(dist, lig_source_dist(&src->pos, &cam));
    }

    if (dist < 20.0f) {
        dist = dist / 20.0f;
    } else {
        dist = 1.0f;
    }

    fade = src->fade;
    if (fade > 0) {
        dist *= 1.0f - fade / 15.0f;
    }

    memset(&packet, 0, sizeof(packet));
    lbl_8006DB74(packet.mtx);

    size = src->size;
    scale = LIG_CLAMP01(dist);
    bright = env->unk_6C0;
    packet.width = 0.70710677f * size;
    packet.color.bytes[0] = (bright * ((u8)src->r * scale));
    packet.color.bytes[1] = (bright * ((u8)src->g * scale));
    packet.color.bytes[2] = (bright * ((u8)src->b * scale));
    packet.color.bytes[3] = 0xFF;

    if (scale * bright < 0.1f) {
        return;
    }

    packet.flags |= 2;
    packet.height = 2.0 * packet.width;
    view = *(void **)((u8 *)scene + 0x24);
    fn_80074788(0);
    fn_80072864(1);
    fn_80073778(view, 0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 0xC);
    fn_80073620(0, 0x1C);
    fn_80073C6C(0);
    fn_80072C24(0, 0xF, 0xE, 8, 0xF);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_800728A8(1, 3, 1, 7);
    lbl_8006D758();
    fn_1_9EDE8(&packet);
}
/* fzgx:end fn_1_D8878 */

/* fzgx:begin fn_1_D8CA8 */
void fn_1_D8CA8(fn_1_D8CA8_LigObject *obj) {
    s32 count = obj->count;
    fn_1_D8CA8_LigEntry *entry = obj->entries;

    while (count > 0) {
        entry->field_68 = 1;
        fn_1_103090(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8CA8 */

/* fzgx:begin fn_1_D8D08 */
void fn_1_D8D08(LigContainer *container) {
    s32 count = container->count;
    fn_1_D8D08_LigEntry *entry = container->entries;

    while (count > 0) {
        fn_1_1030A4(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8D08 */

/* fzgx:begin fn_1_D8D58 */
#include "rel/main_rel/bg_lig.h"

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32 value);
extern void fn_1_1030D4(fn_1_D8D58_LigEntry *entry, void *arg);

void fn_1_D8D58(fn_1_D8D58_LigObject *obj, void *arg) {
    s32 count = obj->count;
    fn_1_D8D58_LigEntry *entry = obj->entries;

    while (count > 0) {
        u32 flags = entry->flags;

        if ((flags >> 28) & 1) {
            f32 x = 0.65f;
            f32 y = 0.75f;
            entry->x = x;
            entry->y = y;
            entry->z = 1.0f;
        } else if ((flags >> 29) & 1) {
            f32 y = 0.0f;
            f32 x = 1.0f;
            entry->x = x;
            entry->y = y;
            entry->z = y;
        } else {
            entry->x = __fabs(lbl_8006D188(
                (lbl_801A66A0 * 182.04444885253906f)));
            entry->y = __fabs(lbl_8006D188(
                (lbl_801A66A0 * 182.04444885253906f * 0.5)));
            entry->z = __fabs(lbl_8006D188(
                (lbl_801A66A0 * 182.04444885253906f * 2.0)));
        }

        fn_1_1030D4(entry, arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8D58 */

/* fzgx:begin fn_1_D8EEC */
// Applies the operation to each entry in the object.
void fn_1_D8EEC(LigContainer *obj, void *arg) {
    s32 count = obj->count;
    fn_1_D8D08_LigEntry *entry = obj->entries;

    while (count > 0) {
        fn_1_103264(entry, arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8EEC */

/* fzgx:begin fn_1_D8F4C */
typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
} FnInputData;

typedef struct {
    FnInputData *unk_0;
} FnInput;

u32 fn_1_D8F4C(s32 index, FnInput *input) {
    FnInputData *data = input->unk_0;
    Obj_1_data_2A7E0_At3C *state = lbl_1_data_2A7E0.unk_3C;
    u32 value = data->unk_24;

    switch (index) {
    case 0:
        state->unk_6CC = value;
        break;
    case 1:
        state->unk_6D0 = value;
        break;
    case 2:
        if (state->unk_1C58 == 0) {
            state->unk_1C58 = (u32)data;
        }
        break;
    case 3:
        if (state->unk_1C5C == 0) {
            state->unk_1C5C = (u32)data;
        }
        break;
    }

    return 1;
}
/* fzgx:end fn_1_D8F4C */

/* fzgx:begin fn_1_D8FC4 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x4];
    u32 unk_8;
    u8 pad_C[0xA0];
} fn_1_D8FC4_Entry;

typedef struct {
    u8 pad_0[0x6D4];
    s32 unk_6D4;
    fn_1_D8FC4_Entry unk_6D8[1];
} fn_1_D8FC4_Container;

s32 fn_1_D8FC4(s32 arg0, s32 arg1) {
    fn_1_D8FC4_Container *base = (fn_1_D8FC4_Container *)lbl_1_data_2A7E0.unk_3C;

    switch (arg0) {
    case 0:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x10000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic("bg_san.c", 0x4E7, "SPOT LIGHT OVER!");
        }
        break;
    case 1:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x20000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic("bg_san.c", 0x4EE, "SPOT LIGHT OVER!");
        }
        break;
    case 2:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x10000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x08000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic("bg_san.c", 0x4F6, "SPOT LIGHT OVER!");
        }
        break;
    case 3:
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x40000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x20000000;
        base->unk_6D8[base->unk_6D4].unk_8 |= 0x08000000;
        base->unk_6D8[base->unk_6D4].unk_0 = arg1;
        base->unk_6D4 += 1;
        if (base->unk_6D4 >= 0x20) {
            OSPanic("bg_san.c", 0x4FE, "SPOT LIGHT OVER!");
        }
        break;
    }
    return 1;
}
/* fzgx:end fn_1_D8FC4 */

/* fzgx:begin fn_1_D9224 */
#include "mathutil.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_D9224_Vec;

/* one 0x44-byte node of the state's node array */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4[4];
    u8 pad_C[4];
    fn_1_D9224_Vec unk_10;
    fn_1_D9224_Vec unk_1C;
    fn_1_D9224_Vec unk_28;
    fn_1_D9224_Vec unk_34;
    f32 unk_40;
} fn_1_D9224_Node;

/* one 0xC-byte link between two nodes */
typedef struct {
    fn_1_D9224_Node *unk_0;
    fn_1_D9224_Node *unk_4;
    f32 unk_8;
} fn_1_D9224_Link;

typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    fn_1_D9224_Node *unk_14;
    fn_1_D9224_Link *unk_18;
    fn_1_D9224_Vec *unk_1C;
} fn_1_D9224_State;

/* 0x40-byte vertex of the model returned by fn_80077B14 */
typedef struct {
    fn_1_D9224_Vec unk_0;
    u8 pad_C[0x29];
    u8 unk_35;
    u8 pad_36[0xA];
} fn_1_D9224_Vertex;

struct fn_1_D9224_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_D9224_lbl_801A6410 lbl_801A6410;
extern void *fn_1_4630(u32, u32, const char *, s32);
extern void *fn_80077B64(void *);
extern void *fn_80077B14(void *);
extern void fn_80008BEC(void *, int, u32);
extern f32 lbl_8006D0B4(f32);

static inline f32 sqdist_D9224(fn_1_D9224_Vec *a, fn_1_D9224_Vec *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;
    dx -= b->x;
    dy -= b->y;
    dz -= b->z;
    dx = dx * dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

#define CLAMP_D9224(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_D9224(fn_1_D9224_State *state, void *model) {
    u32 *count;
    fn_1_D9224_Vertex *verts;
    u32 i;
    u32 j;
    u32 k;
    u32 c;
    fn_1_D9224_Node *a;
    fn_1_D9224_Node *b;
    fn_1_D9224_Node *p;
    fn_1_D9224_Node *first;
    fn_1_D9224_Node *best;
    f32 min;
    f32 d;
    f32 f;
    fn_1_D9224_Vec ref;
    fn_1_D9224_Node t1;
    fn_1_D9224_Node tmp;
    fn_1_D9224_Node t6;
    fn_1_D9224_Node t5;
    fn_1_D9224_Node t4;
    fn_1_D9224_Node t3;
    fn_1_D9224_Node t2;

    if (model != NULL) {
        state->unk_C = 0;
        state->unk_10 = 0;
        count = fn_80077B64(model);
        verts = fn_80077B14(model);
        state->unk_14 = fn_1_4630(lbl_801A6410.unk_0, *count * sizeof(fn_1_D9224_Node), "bg_san.c", 0x516);
        state->unk_1C = fn_1_4630(lbl_801A6410.unk_0, *count * sizeof(fn_1_D9224_Vec), "bg_san.c", 0x517);
        for (i = 0; i < *count; i++) {
            state->unk_1C[i] = verts->unk_0;
            verts++;
        }

        verts = fn_80077B14(model);
        state->unk_C = 0;
        for (i = 0; i < *count; i++, verts++) {
            fn_1_D9224_Node *nodes = state->unk_14;
            u32 found = -1;
            u32 m = state->unk_C;
            fn_1_D9224_Node *g = nodes;

            for (j = 0; j < m; j++, g++) {
                if (sqdist_D9224(&g->unk_10, &verts->unk_0) < 1e-05) {
                    found = j;
                    break;
                }
            }

            if (found != -1) {
                g = &nodes[found];
                g->unk_4[g->unk_2] = i;
                state->unk_14[found].unk_2++;
            } else {
                g = &nodes[state->unk_C];
                g->unk_28 = verts->unk_0;
                g->unk_1C = g->unk_28;
                g->unk_10 = g->unk_1C;
                {
                    fn_1_D9224_Vec zero = {0.0f, 0.0f, 0.0f};
                    g->unk_34 = zero;
                }
                g->unk_0 = verts->unk_35;
                fn_80008BEC(g->unk_4, 0xFF, sizeof(g->unk_4));
                g->unk_2 = 1;
                g->unk_4[0] = i;
                g->unk_1 = 0;
                state->unk_C++;
            }
        }

        p = state->unk_14;
        for (i = 0; i < state->unk_C; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_40 = -1.0f;
                p->unk_0 = 0;
            } else {
                p->unk_40 = 0.0f;
                p->unk_0 = 1;
            }
        }

        a = state->unk_14;
        for (i = 0; i < state->unk_C - 1; i++, a++) {
            b = &state->unk_14[i] + 1;
            for (j = i + 1; j < state->unk_C; j++, b++) {
                if (!(a->unk_0 & 1) && (b->unk_0 & 1)) {
                    t1 = *a;
                    *a = *b;
                    *b = t1;
                }
            }
        }

        a = state->unk_14;
        for (i = 0; i < state->unk_C - 1; i++, a++) {
            b = &state->unk_14[i] + 1;
            for (j = i + 1; j < state->unk_C; j++, b++) {
                if (!(a->unk_0 & 1) && !(b->unk_0 & 1) && a->unk_10.x > b->unk_10.x) {
                    t2 = *a;
                    *a = *b;
                    *b = t2;
                }
            }
        }

        a = state->unk_14;
        for (i = 0; i < state->unk_C; i++, a++) {
            if (!(a->unk_0 & 1)) {
                break;
            }
        }

        first = a;
        for (i = 0; i < 8; i++, a++) {
            for (j = i + 1, b = a + 1; j < 9; j++, b++) {
                if (a->unk_10.y < b->unk_10.y) {
                    t3 = *a;
                    *a = *b;
                    *b = t3;
                }
            }
        }

        for (k = 0, first += 9; k < 10; k++, first += 11) {
            for (i = 0, a = first; i < 10; i++, a++) {
                for (j = i + 1, b = a + 1; j < 11; j++, b++) {
                    if (a->unk_10.y < b->unk_10.y) {
                        t4 = *a;
                        *a = *b;
                        *b = t4;
                    }
                }
            }
        }

        best = state->unk_14;
        min = 100000.0f;
        ref.x = best[33].unk_10.x;
        ref.y = best[42].unk_10.y;
        for (i = 0, a = best; i < state->unk_C - 1; i++, a++) {
            if (a->unk_0 & 1) {
                /* Planar distance through the 3D kernel: z is a literal 0.0f, which retail squares. */
                d = lbl_8006D0B4(mathutil_sum_of_sq_3(a->unk_10.x - ref.x, a->unk_10.y - ref.y, 0.0f));
                if (min > d) {
                    min = d;
                    best = a;
                }
            }
        }
        t5 = state->unk_14[31];
        state->unk_14[31] = *best;
        *best = t5;

        best = state->unk_14;
        min = 100000.0f;
        ref.x = best[41].unk_10.x;
        ref.y = best[52].unk_10.y;
        for (i = 0, a = best; i < state->unk_C; i++, a++) {
            if (a->unk_0 & 1) {
                d = lbl_8006D0B4(mathutil_sum_of_sq_3(a->unk_10.x - ref.x, a->unk_10.y - ref.y, 0.0f));
                if (min > d) {
                    min = d;
                    best = a;
                }
            }
        }
        t6 = state->unk_14[32];
        state->unk_14[32] = *best;
        *best = t6;

        tmp = state->unk_14[32];
        for (i = 33, a = &state->unk_14[33]; i < 42; i++, a++) {
            a[-1] = a[0];
        }
        state->unk_14[41] = tmp;

        for (i = 0, a = &state->unk_14[31]; i < state->unk_C - 31; i++, a++) {
            f = ((s32)i / 11 + 1) / 12.0f;
            a->unk_40 = -CLAMP_D9224(f, 0.0f, 1.0f);
            if (i == 0 || i == 10) {
                a->unk_40 = 0.0f;
            }
        }

        state->unk_10 = 220;
        state->unk_18 = fn_1_4630(lbl_801A6410.unk_0, state->unk_10 * sizeof(fn_1_D9224_Link), "bg_san.c", 0x5C7);

        c = 0;
        for (i = 0, a = &state->unk_14[31]; i < state->unk_C - 32; i++, a++) {
            if ((i + 1) % 11 != 0) {
                state->unk_18[c].unk_0 = a;
                state->unk_18[c].unk_4 = a + 1;
                state->unk_18[c].unk_8 = mathutil_sum_of_sq_3(a->unk_10.x - (a + 1)->unk_10.x, a->unk_10.y - (a + 1)->unk_10.y, a->unk_10.z - (a + 1)->unk_10.z);
                c++;
            }
        }
        for (i = 0, a = &state->unk_14[31]; i < state->unk_C - 42; i++, a++) {
            state->unk_18[c].unk_0 = a;
            state->unk_18[c].unk_4 = a + 11;
            state->unk_18[c].unk_8 = mathutil_sum_of_sq_3(a->unk_10.x - (a + 11)->unk_10.x, a->unk_10.y - (a + 11)->unk_10.y, a->unk_10.z - (a + 11)->unk_10.z);
            c++;
        }
    }
}
/* fzgx:end fn_1_D9224 */

/* fzgx:begin fn_1_D9D8C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_D9D8C_Vec;

/* one 0x44-byte node of the state's node array */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4[6];
    fn_1_D9D8C_Vec unk_10;
    fn_1_D9D8C_Vec unk_1C;
    fn_1_D9D8C_Vec unk_28;
    fn_1_D9D8C_Vec unk_34;
    f32 unk_40;
} fn_1_D9D8C_Node;

/* one 0xC-byte link between two nodes */
typedef struct {
    fn_1_D9D8C_Node *unk_0;
    fn_1_D9D8C_Node *unk_4;
    f32 unk_8;
} fn_1_D9D8C_Link;

typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    fn_1_D9D8C_Node *unk_14;
    fn_1_D9D8C_Link *unk_18;
} fn_1_D9D8C_State;

/* 0x40-byte vertex of the model returned by fn_80077B14 */
typedef struct {
    fn_1_D9D8C_Vec unk_0;
    u8 pad_C[0x34];
} fn_1_D9D8C_Vertex;


extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D0B4(f32);
extern u32 lbl_801A63C0;

/* one step of the executable's random generator, lbl_801A63C0, scaled to [0, 1]; returned as f64 so the
 * callers' scale and offset are applied in double precision, as retail does */
static inline f64 randf_D9D8C(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f;
}

static inline f32 sqlen_D9D8C(f32 x, f32 y, f32 z) {
    x *= x;
    x += y * y;
    x += z * z;
    return x;
}

/* random push added to a node's velocity */
static inline void jitter_D9D8C(fn_1_D9D8C_Node *node) {
    node->unk_34.x += (f64)(0.02f * randf_D9D8C()) - 0.005f;
    node->unk_34.y += (f32)(0.004f * (f32)randf_D9D8C());
    node->unk_34.z += (f64)(0.02f * 10.0 * randf_D9D8C()) - 0.02f * 5.0;
}
/* Steps the node and link arrays of `state`: moves free nodes by their velocity, relaxes the links four
 * times, damps the velocities and adds a random push, then copies each node's position into the model's
 * vertices listed in the node. The casts keep products unfused, as retail has no fused multiply-adds there. */
void fn_1_D9D8C(fn_1_D9D8C_State *state, void *model, s32 index) {
    fn_1_D9D8C_Vertex *verts;
    u32 j;
    u32 pass;
    fn_1_D9D8C_Link *link;
    fn_1_D9D8C_Node *a;
    fn_1_D9D8C_Node *b;
    u32 i;
    fn_1_D9D8C_Node *node;
    f32 len;
    fn_1_D9D8C_Vec d;
    fn_1_D9D8C_Vec *dp = &d;
    f32 inv;
    f32 r;
    f32 wa;
    f32 wb;
    f32 fa;
    f32 fb;

    if (state != NULL && model != NULL) {
        verts = (fn_1_D9D8C_Vertex *)fn_80077B14(model);

        for (i = 0, node = state->unk_14; i < state->unk_C; i++, node++) {
            if (!(node->unk_0 & 1)) {
                node->unk_1C = node->unk_10;
                node->unk_10.x += node->unk_34.x;
                node->unk_10.y += node->unk_34.y;
                node->unk_10.z += node->unk_34.z;
                node->unk_10.y -= 0.0013611111376020642;
                node->unk_34.y -= 0.0027222223579883575f;
            }
        }

        for (pass = 0; pass < 4; pass++) {
            for (j = 0, link = state->unk_18; j < state->unk_10; j++, link++) {
                a = link->unk_0;
                b = link->unk_4;
                if (a != NULL && b != NULL) {
                    dp->x = a->unk_10.x - b->unk_10.x;
                    dp->y = a->unk_10.y - b->unk_10.y;
                    dp->z = a->unk_10.z - b->unk_10.z;
                    len = sqlen_D9D8C(dp->x, dp->y, dp->z);
                    if (len - 0.0001f > link->unk_8) {
                        inv = lbl_8006D118(len, &len);
                        r = lbl_8006D0B4(link->unk_8);
                        len = inv * (len - r);
                        dp->x *= len;
                        dp->y *= len;
                        dp->z *= len;
                        wa = a->unk_40;
                        wb = b->unk_40;
                        r = 1.0f / (wa + wb);
                        fa = wa * r;
                        fb = wb * r;
                        a->unk_10.x -= (f32)(dp->x * fa);
                        a->unk_10.y -= (f32)(dp->y * fa);
                        a->unk_10.z -= (f32)(dp->z * fa);
                        b->unk_10.x += (f32)(dp->x * fb);
                        b->unk_10.y += (f32)(dp->y * fb);
                        b->unk_10.z += (f32)(dp->z * fb);
                    }
                }
            }
        }

        for (i = 0, node = state->unk_14; i < state->unk_C; i++, node++) {
            node->unk_34.x *= 0.9;
            node->unk_34.y *= 0.9;
            node->unk_34.z *= 0.9;
            node->unk_34.x += (f64)(0.1 * (node->unk_10.x - node->unk_1C.x));
            node->unk_34.y += (f64)(0.1 * (node->unk_10.y - node->unk_1C.y));
            node->unk_34.z += (f64)(0.1 * (node->unk_10.z - node->unk_1C.z));
            /* retail repeats the same push on both paths of index (the loop is compiled twice) */
            if (index == 0) {
                jitter_D9D8C(node);
            } else {
                jitter_D9D8C(node);
            }
        }

        for (i = 0, node = state->unk_14; i < state->unk_C; i++, node++) {
            for (j = 0; j < node->unk_2; j++) {
                verts[node->unk_4[j]].unk_0 = node->unk_10;
            }
        }
    }
}
/* fzgx:end fn_1_D9D8C */

/* fzgx:begin fn_1_DA3A0 */
#include "psvec.h"
#include "rel/main_rel/bg_lig.h"

extern f32 lbl_8006D668(void *);

struct VecLocal { f32 a[3]; };
struct VertexLocal { u8 pad[12]; struct VecLocal normal; u8 rest[40]; };
static inline void cross(const struct VecLocal *a, const struct VecLocal *b, struct VecLocal *out) {
 f32 ax, ay, az, bx, bz, by;
 f32 x, y, z;
 ay = a->a[1];
 bz = b->a[2];
 az = a->a[2];
 bx = b->a[0];
 by = b->a[1];
 ax = a->a[0];
 x = ay * bz;
 y = az * bx;
 z = ax * by;
 x = x - az * by;
 y = y - ax * bz;
 z = z - ay * bx;
 out->a[0] = x;
 out->a[1] = y;
 out->a[2] = z;
}
void fn_1_DA3A0(void *arg0) {
 u32 v0;
 s32 v1;
 u32 v2;
 u8 *v3;
 u8 *v16;
 u32 v17;
 s32 v18;
 s32 v19;
 struct VecLocal loc_20;
 struct VecLocal loc_14;
 struct VecLocal loc_8;
 if (arg0 != 0) {
  v0 = *(u32 *)((u8 *)arg0 + 4);
  if (v0 != 0) {
   v1 = (s32)fn_80077B14((void *)v0);
   v2 = 0;
   v3 = (u8 *)(*(u32 *)((u8 *)arg0 + 20) + 2108);
   while (v2 < (*(u32 *)((u8 *)arg0 + 12) - 31)) {
    if (v2 > (*(u32 *)((u8 *)arg0 + 12) - 12)) {
     if (v2 + 1 == 11) {
      psvec_sub(v3 + -52, v3 + 16, &loc_20);
      psvec_sub(v3 + -732, v3 + 16, &loc_14);
      lbl_8006D668(&loc_20);
      lbl_8006D668(&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     } else {
      psvec_sub(v3 + -732, v3 + 16, &loc_20);
      psvec_sub(v3 + 84, v3 + 16, &loc_14);
      lbl_8006D668(&loc_20);
      lbl_8006D668(&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     }
    } else {
     if (v2 + 1 == 11) {
      psvec_sub(v3 + 764, v3 + 16, &loc_20);
      psvec_sub(v3 + -52, v3 + 16, &loc_14);
      lbl_8006D668(&loc_20);
      lbl_8006D668(&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     } else {
      psvec_sub(v3 + 84, v3 + 16, &loc_20);
      psvec_sub(v3 + 764, v3 + 16, &loc_14);
      lbl_8006D668(&loc_20);
      lbl_8006D668(&loc_14);
      cross(&loc_20, &loc_14, &loc_8);
     }
    }
    v16 = v3;
    v17 = 0;
    while (v17 < *(v3 + 2)) {
     v18 = *(u16 *)(v16 + 4);
     v16 += 2;
     v17++;
     v19 = v1 + ((v18 << 6) + 12);
     ((struct VertexLocal *)v1)[v18].normal = loc_8;
    }
    v2++;
    v3 += 68;
   }
  }
 }
}
/* fzgx:end fn_1_DA3A0 */

/* fzgx:begin fn_1_DA6A8 */
extern void fn_1_46B4(u32, u32, const char *, int);
struct fn_1_DA6A8_Copy12 { u32 a[3]; };
struct fn_1_DA6A8_lbl_801A6410 {
    u32 unk_0;
};

struct FzgxCopy_12 { u32 words[3]; };
void fn_1_DA6A8(void *arg0, u32 arg1) {
    s32 temp_r5;
    s32 var_r3;
    s32 var_r6;
    u32 *temp_r30;
    u32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r4_3;
    u32 var_r7;

    if (arg0 != NULL) {
        temp_r30 = (fn_80077B64((void *)arg1));
        var_r3 = (s32)fn_80077B14((void *)arg1);
        var_r7 = 0U;
        var_r6 = 0;
        while (var_r7 < (*temp_r30)) {
            var_r7 += 1;
            temp_r5 = (*(u32 *)((u8 *)(arg0) + 28)) + var_r6;
            var_r6 += 0xC;
            *(struct FzgxCopy_12 *)(var_r3) = *(const struct FzgxCopy_12 *)(temp_r5);
            var_r3 += 0x40;
                    }
        temp_r4 = *(u32 *)((u8 *)(arg0) + 20);
        if (temp_r4 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4, "bg_san.c", 0x6B6);
        }
        temp_r4_2 = *(u32 *)((u8 *)(arg0) + 24);
        if (temp_r4_2 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, "bg_san.c", 0x6B9);
        }
        temp_r4_3 = *(u32 *)((u8 *)(arg0) + 28);
        if (temp_r4_3 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, "bg_san.c", 0x6BC);
        }
    }
}

Obj_1_bss_7AD78 lbl_1_bss_7AD78;
/* fzgx:end fn_1_DA6A8 */
