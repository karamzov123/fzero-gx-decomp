#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);

/* fzgx:begin fn_1_48C28 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern u8 lbl_1_bss_3F60C[];
extern u8 lbl_1_bss_3E060[];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, void *, int);

#pragma opt_lifetimes off
void fn_1_48C28(int index) {
    u32 offset;
    u16 *scan;
    Obj_1_data_1AEA8 *entry;
    int i;

    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    if ((s32)entry->unk_0 != -1) {
        return;
    }

    scan = (u16 *)entry->unk_2C;
    offset = 0;
    while (*scan) {
        int found = 0;
        int id = *(s16 *)((u8 *)entry->unk_30 + offset);
        if (id != -1 && ((s32 *)lbl_1_bss_3F60C)[id] != -1) {
            for (i = 1; i != 0x2c; i++) {
                Obj_1_data_1AEA8 *other =
                    (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + i * 0x38);
                if (i == index) {
                    continue;
                }
                if ((s32)other->unk_0 == -1 &&
                    *(s16 *)((u8 *)offset + other->unk_30) != -1) {
                    found = 1;
                    break;
                }
            }
            if (found != 0) {
                *(s16 *)((u8 *)entry->unk_30 + offset) = -1;
            } else {
                fn_1_46B4(lbl_801A6410, ((s32 *)lbl_1_bss_3E060)[id],
                          lbl_1_data_1BCC8, 0x217);
                id = *(s16 *)((u8 *)entry->unk_30 + offset);
                ((s32 *)lbl_1_bss_3E060)[id] = 0;
                *(s16 *)((u8 *)entry->unk_30 + offset) = -1;
            }
        }
        offset += 2;
        scan = scan + 1;
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_48C28 */

/* fzgx:begin fn_1_492F0 noprologue */
#include "dolphin/types.h"

const f32 lbl_1_rodata_FD0[60] = {
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
    -1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,1.0f,1.0f,
    2.6f,0.0f,2.6f,0.0f,0.0f,0.0f,0.0f,0.0f,
    1.6f,-1.0f,3.6f,-1.0f,-1.0f,1.0f,1.0f,1.0f,
    -1.4f,3.7f,1.3f,0.0f,1.6f,0.5f,-0.9f,-0.8f,
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
    0.0f,0.0f,0.0f,0.0f
};
const f32 lbl_1_rodata_10C0[2] = {0.0f, 0.0f};
typedef struct ShapeParams {
    u32 flags;
    u8 pad[12];
    f32 width;
    f32 height;
} ShapeParams;

#pragma push
#pragma section code_type ".fzgxpool"
void fzgx_fn_1_492F0_pool_primer(f64 *p, f32 *q)
{
    p[0] = 0.5;
    q[0] = 0.75f;
    q[1] = 1.0f;
}
#pragma pop

#pragma fp_contract off
void fn_1_492F0(ShapeParams *arg, f32 out[4][3])
{
    f32 width = 1.0f + arg->width;
    f32 height = 1.0f + arg->height;
    s32 index = (s8)(arg->flags >> 24);
    if (index) {
        const f32 *row = &lbl_1_rodata_FD0[index * 8];
        out[0][0] += 0.5 * row[0] * width;
        out[0][1] += 0.5 * row[1] * height;
        out[1][0] += 0.5 * row[2] * width;
        out[1][1] += 0.5 * row[3] * height;
        out[2][0] += 0.5 * row[4] * width;
        out[2][1] += 0.5 * row[5] * height;
        out[3][0] += 0.5 * row[6] * width;
        out[3][1] += 0.5 * row[7] * height;
    }
}
/* fzgx:end fn_1_492F0 */

/* fzgx:begin fn_1_49410 */
struct fn_1_49410_lbl_1_rodata_FD0 {
    u8 pad_0[0xF0];
    f32 unk_F0;
    u8 pad_F4[0xC];
    f32 unk_100;
    f32 unk_104;
    u8 pad_108[0x10];
    u32 unk_118;
    u32 unk_11C;
    f32 unk_120;
};
struct fn_1_49410_lbl_1_bss_4B9CC {
    u8 pad_0[0xC];
    u16 unk_C;
    u16 unk_E;
    u32 unk_10;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u32 unk_2C;
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u8 unk_36;
    u8 unk_37;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    f32 unk_50;
    u32 unk_54;
    u32 unk_58;
};





#pragma opt_propagation off
void fn_1_49410(void) {
    f32 fzgx_live;
    struct fn_1_49410_lbl_1_rodata_FD0 *q = &(*(struct fn_1_49410_lbl_1_rodata_FD0 *)&lbl_1_rodata_FD0);

    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_C = 42;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_10 = q->unk_118;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_14 = q->unk_11C;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_E = 0;
    fzgx_live = q->unk_120;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_18 = fzgx_live;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_1C = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_20 = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_24 = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_28 = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_2C = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_36 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_30 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_32 = 2;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_34 = 2;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_38 = q->unk_100;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_37 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_3C = q->unk_F0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_40 = q->unk_F0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_44 = 1;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_45 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_54 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_50 = q->unk_F0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_46 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_47 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_48 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_4A = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_4C = 640;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_4E = 480;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_58 = 5;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_49410 */

/* fzgx:begin fn_1_494CC */
void fn_1_494CC(u8 value) {
    lbl_1_bss_4B9CC.unk_44 = value;
}
/* fzgx:end fn_1_494CC */

/* fzgx:begin fn_1_494DC */
void fn_1_494DC(s16 index) {
    lbl_1_bss_4B9CC.unk_C = index;
    fn_1_4955C(lbl_1_rodata_10D4, lbl_1_rodata_10D4);
}
/* fzgx:end fn_1_494DC */

/* fzgx:begin fn_1_49514 */
void fn_1_49514(u32 *value) {
    lbl_1_bss_4B9CC.unk_10 = *value;
}
/* fzgx:end fn_1_49514 */

/* fzgx:begin fn_1_49528 */
void fn_1_49528(u32 *value) {
    lbl_1_bss_4B9CC.unk_14 = *value;
}
/* fzgx:end fn_1_49528 */

/* fzgx:begin fn_1_4953C */
void fn_1_4953C(s16 value) {
    lbl_1_bss_4B9CC.unk_E = value;
}
/* fzgx:end fn_1_4953C */

/* fzgx:begin fn_1_4954C */
void fn_1_4954C(f32 value) {
    lbl_1_bss_4B9CC.unk_18 = value;
}
/* fzgx:end fn_1_4954C */

/* fzgx:begin fn_1_4955C */
void fn_1_4955C(f32 value1, f32 value2) {
    s16 index = lbl_1_bss_4B9CC.unk_C;
    Obj_1_data_1AEA8 *font = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    f32 scale = font->unk_34;

    // Scale both font dimensions using the active font's metrics.
    lbl_1_bss_4B9CC.unk_1C = value1 * scale;
    lbl_1_bss_4B9CC.unk_20 = value2 * scale;
}
/* fzgx:end fn_1_4955C */

/* fzgx:begin fn_1_49590 */
void fn_1_49590(f32 value) {
    lbl_1_bss_4B9CC.unk_24 = value;
}
/* fzgx:end fn_1_49590 */

/* fzgx:begin fn_1_495A0 */
void fn_1_495A0(f32 value) {
    lbl_1_bss_4B9CC.unk_28 = value;
}
/* fzgx:end fn_1_495A0 */

/* fzgx:begin fn_1_495B0 */
void fn_1_495B0(u32 value) {
    lbl_1_bss_4B9CC.unk_2C |= value;
}
/* fzgx:end fn_1_495B0 */

/* fzgx:begin fn_1_495C8 */
void fn_1_495C8(u8 value) {
    // Update the current font state flag.
    lbl_1_bss_4B9CC.unk_36 = value;
}
/* fzgx:end fn_1_495C8 */

/* fzgx:begin fn_1_495D8 */
void fn_1_495D8(u16 value1, u16 value2, f32 value3) {
    lbl_1_bss_4B9CC.unk_32 = value1;
    lbl_1_bss_4B9CC.unk_2C |= 0x40000000;
    lbl_1_bss_4B9CC.unk_34 = value2;
    lbl_1_bss_4B9CC.unk_38 = value3;
}
/* fzgx:end fn_1_495D8 */

/* fzgx:begin fn_1_495FC */
void fn_1_495FC(void) {
    lbl_1_bss_4B9CC.unk_2C |= 0x40000000;
}
/* fzgx:end fn_1_495FC */

/* fzgx:begin fn_1_49614 */
void fn_1_49614(void) {
    lbl_1_bss_4B9CC.unk_2C &= 0xBFFFFFFF;
}
/* fzgx:end fn_1_49614 */

/* fzgx:begin fn_1_4962C */
void fn_1_4962C(void) {
    lbl_1_bss_4B9CC.unk_2C |= 0x20000000;
}
/* fzgx:end fn_1_4962C */

/* fzgx:begin fn_1_49644 */
void fn_1_49644(void) {
    lbl_1_bss_4B9CC.unk_2C &= 0xDFFFFFFF;
}
/* fzgx:end fn_1_49644 */

/* fzgx:begin fn_1_4965C */
void fn_1_4965C(u8 value) {
    lbl_1_bss_4B9CC.unk_37 = value;
}
/* fzgx:end fn_1_4965C */

/* fzgx:begin fn_1_4966C */
void fn_1_4966C(f32 value1, f32 value2) {
    // Store the two font scale values used by the renderer.
    lbl_1_bss_4B9CC.unk_3C = value1;
    lbl_1_bss_4B9CC.unk_40 = value2;
}
/* fzgx:end fn_1_4966C */

/* fzgx:begin fn_1_49680 */
// Scale the active font entry's byte dimensions into the shared bounds.
void fn_1_49680(f32 value1, f32 value2) {
    Obj_1_data_1AEA8 *entry;
    s16 index;
    f32 result1;
    f32 result2;

    index = lbl_1_bss_4B9CC.unk_C;
    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    result1 = entry->unk_34 * (value1 * (f32)entry->unk_4);
    result2 = entry->unk_34 * (value2 * (f32)entry->unk_5);
    lbl_1_bss_4B9CC.unk_4 = result1;
    lbl_1_bss_4B9CC.unk_0 = result1;
    lbl_1_bss_4B9CC.unk_8 = result2;
}
/* fzgx:end fn_1_49680 */

/* fzgx:begin fn_1_496FC */
 // Store the two font coordinates in the shared state.
void fn_1_496FC(f32 value1, f32 value2) {
    lbl_1_bss_4B9CC.unk_4 = value1;
    lbl_1_bss_4B9CC.unk_0 = value1;
    lbl_1_bss_4B9CC.unk_8 = value2;
}
/* fzgx:end fn_1_496FC */

/* fzgx:begin fn_1_49714 */
void fn_1_49714(f32 value1, f32 value2, f32 value3) {
    lbl_1_bss_4B9CC.unk_0 = value3;
    lbl_1_bss_4B9CC.unk_4 = value1;
    lbl_1_bss_4B9CC.unk_8 = value2;
}
/* fzgx:end fn_1_49714 */

/* fzgx:begin fn_1_49728 */
void fn_1_49728(u8 value) {
    lbl_1_bss_4B9CC.unk_45 = value;
}
/* fzgx:end fn_1_49728 */

/* fzgx:begin fn_1_49738 */
 // Store the supplied value in the font state used by subsequent rendering.
void fn_1_49738(u32 value) {
    lbl_1_bss_4B9CC.unk_54 = value;
}
/* fzgx:end fn_1_49738 */

/* fzgx:begin fn_1_49748 */
void fn_1_49748(f32 value) {
    lbl_1_bss_4B9CC.unk_50 = value;
}
/* fzgx:end fn_1_49748 */

/* fzgx:begin fn_1_49758 */
void fn_1_49758(u8 value) {
    lbl_1_bss_4B9CC.unk_46 = value;
}
/* fzgx:end fn_1_49758 */

/* fzgx:begin fn_1_49768 */
void fn_1_49768(u8 value) {
    lbl_1_bss_4B9CC.unk_47 = value;
}
/* fzgx:end fn_1_49768 */

/* fzgx:begin fn_1_49778 */
void fn_1_49778(s16 value1, s16 value2, s16 value3, s16 value4) {
    lbl_1_bss_4B9CC.unk_48 = value1;
    lbl_1_bss_4B9CC.unk_4A = value2;
    lbl_1_bss_4B9CC.unk_4C = value3;
    lbl_1_bss_4B9CC.unk_4E = value4;
}
/* fzgx:end fn_1_49778 */

/* fzgx:begin fn_1_49794 */
u32 fn_1_49794(u32 c) {
    if ((u16)c >= 'A' && (u16)c <= 'Z') {
        return c + 0x821F;
    }
    if ((u16)c >= 'a' && (u16)c <= 'z') {
        return c + 0x8220;
    }
    if ((u16)c >= '0' && (u16)c <= '9') {
        return c + 0x821F;
    }

    switch ((u8)c) {
    case '!':
        return 0x8149;
    case '"':
        return 0x8168;
    case '#':
        return 0x8194;
    case '$':
        return 0x8190;
    case '%':
        return 0x8193;
    case '&':
        return 0x8195;
    case '\'':
        return 0x8166;
    case '(':
        return 0x8169;
    case ')':
        return 0x816A;
    case '*':
        return 0x8196;
    case '+':
        return 0x817B;
    case ',':
        return 0x8143;
    case '-':
        return 0x817C;
    case '.':
        return 0x8144;
    case '/':
        return 0x815E;
    case ':':
        return 0x8146;
    case ';':
        return 0x8147;
    case '<':
        return 0x8171;
    case '=':
        return 0x8181;
    case '>':
        return 0x8172;
    case '?':
        return 0x8148;
    case '@':
        return 0x8197;
    case '[':
        if ((s32)lbl_1_bss_3E058 == 0) {
            return 0x816D;
        }
        break;
    case '\\':
        return 0x815F;
    case ']':
        if ((s32)lbl_1_bss_3E058 == 0) {
            return 0x816E;
        }
        break;
    case '^':
        return 0x814F;
    case '_':
        return 0x8151;
    case '`':
        return 0x8165;
    case '{':
        return 0x816F;
    case '|':
        return 0x8162;
    case '}':
        return 0x8170;
    case '~':
        return 0x8160;
    }

    return c;
}
/* fzgx:end fn_1_49794 */

/* fzgx:begin fn_1_499BC */
u16 fn_1_499BC(const u8 *value) {
    u16 result;
    s32 i;
    s32 shift;
    const u8 *p;

    if (value[0] != 'c') {
        return value[0];
    }
    if (value[1] != '0') {
        return value[0];
    }
    p = value + 2;
    if (value[2] != 'x') {
        return value[0];
    }
    result = 0;
    shift = 12;
    for (i = 0; i < 4; i++) {
        switch (p[i + 1]) {
        case '0':
            result |= 1 << shift;
            break;
        case '1':
            result |= 2 << shift;
            break;
        case '2':
            result |= 3 << shift;
            break;
        case '3':
            result |= 4 << shift;
            break;
        case '4':
            result |= 5 << shift;
            break;
        case '5':
            result |= 6 << shift;
            break;
        case '6':
            result |= 7 << shift;
            break;
        case '7':
            result |= 8 << shift;
            break;
        case '8':
            result |= 9 << shift;
            break;
        case '9':
            result |= 10 << shift;
            break;
        case 'A':
        case 'a':
            result |= 11 << shift;
            break;
        case 'B':
        case 'b':
            result |= 12 << shift;
            break;
        case 'C':
        case 'c':
            result |= 13 << shift;
            break;
        case 'D':
        case 'd':
            result |= 14 << shift;
            break;
        case 'E':
        case 'e':
            result |= 15 << shift;
            break;
        case 'F':
        case 'f':
            break;
        default:
            break;
        }
        shift -= 4;
    }
    return result;
}
/* fzgx:end fn_1_499BC */

/* fzgx:begin fn_1_49B70 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[0x10];
    f32 unk_28;
} UnkArg1;

extern f32 lbl_1_rodata_10D8;
extern f64 lbl_1_rodata_10E0[3];

s32 fn_1_49B70(u8 *arg0, UnkArg1 *arg1) {
    /* volatile: retail reloads the accumulator from the frame in every case arm */
    volatile u32 flags;
    u32 c1;
    s32 i;
    s32 shift;
    s32 mode;
    u8 *p;
    s32 n;
    s32 ret;

    flags = 0;
    if (arg0[0] != 0x2F) {
        return 0;
    }
    c1 = arg0[1];
    if (c1 == 0x62 || c1 == 0x6F) {
        mode = (s32)(((0x62 - c1) | (c1 - 0x62)) >> 31);
        p = arg0 + 2;
        if (arg0[2] != 0x63) {
            return 0;
        }
        if (p[7] != 0x2F) {
            return 0;
        }
        n = 3;
        shift = 0x1C;
        ret = 9;
    } else if (c1 == 0x74) {
        p = arg0 + 2;
        if (arg0[2] != 0x72) {
            return 0;
        }
        if (p[3] != 0x2F) {
            return 0;
        }
        mode = 2;
        n = 1;
        shift = 4;
        ret = 5;
    } else {
        return 0;
    }
    for (i = 0; i < n * 2; i++, shift -= 4) {
        switch (p[i + 1]) {
        case 0x30:
            break;
        case 0x31:
            flags |= 1 << shift;
            break;
        case 0x32:
            flags |= 2 << shift;
            break;
        case 0x33:
            flags |= 3 << shift;
            break;
        case 0x34:
            flags |= 4 << shift;
            break;
        case 0x35:
            flags |= 5 << shift;
            break;
        case 0x36:
            flags |= 6 << shift;
            break;
        case 0x37:
            flags |= 7 << shift;
            break;
        case 0x38:
            flags |= 8 << shift;
            break;
        case 0x39:
            flags |= 9 << shift;
            break;
        case 0x61:
            flags |= 0xA << shift;
            break;
        case 0x41:
            flags |= 0xA << shift;
            break;
        case 0x62:
            flags |= 0xB << shift;
            break;
        case 0x42:
            flags |= 0xB << shift;
            break;
        case 0x63:
            flags |= 0xC << shift;
            break;
        case 0x43:
            flags |= 0xC << shift;
            break;
        case 0x64:
            flags |= 0xD << shift;
            break;
        case 0x44:
            flags |= 0xD << shift;
            break;
        case 0x65:
            flags |= 0xE << shift;
            break;
        case 0x45:
            flags |= 0xE << shift;
            break;
        case 0x66:
            flags |= 0xF << shift;
            break;
        case 0x46:
            flags |= 0xF << shift;
            break;
        }
    }
    switch (mode) {
    case 0:
        if (arg1 != NULL) {
            arg1->unk_10 = flags;
        }
        break;
    case 1:
        if (arg1 != NULL) {
            arg1->unk_14 = flags;
        }
        break;
    case 2:
        if (arg1 != NULL) {
            arg1->unk_28 = (f32)flags / lbl_1_rodata_10D8;
        }
        break;
    }
    return ret;
}
/* fzgx:end fn_1_49B70 */

/* fzgx:begin fn_1_4AC20 */
typedef struct {
    u32 unk_0;
    f32 x;
    f32 y;
    u8 pad_C[4];
    f32 z;
    f32 w;
    u8 pad_20[0x18];
    u32 flag;
    u8 tail[0x24];
} fn_1_4AC20_FontData;

void fn_1_4AC20(fn_1_4AC20_FontData *value) {
    fn_1_4AC20_FontData local = *value;
    int x_max;
    int x_ok;
    int y_max;
    int y_ok;

    if (lbl_1_bss_4B9CC.unk_45 != 0) {
        local.x = fn_1_519FC(local.x);
        local.y = fn_1_51AC0(local.y);
        local.z = fn_1_51B84(local.z);
        local.w = fn_1_51BFC(local.w);
    }

    if (lbl_1_bss_4B9CC.unk_47 != 0) {
        x_ok = (local.x > (f32)(lbl_1_bss_4B9CC.unk_48 + lbl_1_bss_4B9CC.unk_4C))
                   ? 0
                   : ((local.x < (f32)lbl_1_bss_4B9CC.unk_48) ? 0 : 1);
        if (x_ok == 0 ||
            (y_ok = (local.y > (f32)(lbl_1_bss_4B9CC.unk_4A + lbl_1_bss_4B9CC.unk_4E))
                        ? 0
                        : ((local.y < (f32)lbl_1_bss_4B9CC.unk_4A) ? 0 : 1)) == 0) {
            return;
        }
    }

    if (lbl_1_bss_4B9CC.unk_44 != 0) {
        fn_1_4F734( (FontDrawPacket *)(void *)(&local));
    } else if ((local.flag & 0x400000) != 0) {
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E500();
        }
        fn_1_48D80(&local);
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E6F4();
        }
    } else {
        fn_1_4E724( (FontParams *)(void *)(&local));
    }
}
/* fzgx:end fn_1_4AC20 */

/* fzgx:begin fn_1_4AE0C */
void fn_1_4AE0C(const char* format, ...) {
    char buffer[512];
    __va_list args;
    __builtin_va_info(&args);
    fn_8008077C( (u32)(char*)(buffer), (u32)(const char*)(format), (u32)(args));
    fn_1_4A0D8(buffer);
}
/* fzgx:end fn_1_4AE0C */

/* fzgx:begin fn_1_4AEB4 */
void fn_1_4AEB4(f32 value) {
    lbl_1_bss_3E05C = value;
}
/* fzgx:end fn_1_4AEB4 */

/* fzgx:begin fn_1_4AEC0 */
u32 fn_1_4AEC0(u32 value) {
    u32 previous = lbl_1_bss_3E058;

    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    lbl_1_bss_3E058 = value;

    return previous;
}
/* fzgx:end fn_1_4AEC0 */

/* fzgx:begin fn_1_4AF10 */
struct fn_1_4AF10_lbl_1_bss_3E058 {
    u32 unk_0;
};






#pragma opt_pointer_analysis off
void fn_1_4AF10(u32 arg0) {
    u32 v0;
    v0 = (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0;
    lbl_1_bss_3E05C = (0.0f);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = 1;
    fn_1_4A0D8((const char *)arg0);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = v0;
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_1_4AF10 */

/* fzgx:begin fn_1_4AF64 */
typedef struct {
    u32 gpr_offset;
    void *overflow_arg_area;
    void *reg_save_area;
} va_list;



void fn_1_4AF64(const char *format, ...) {
    va_list args;
    char buffer[512];
    u32 previous = lbl_1_bss_3E058;

    __builtin_va_info(&args);
    fn_8008077C( (u32)(char *)(buffer), (u32)(const char *)(format), (u32)(va_list *)(&args));

    lbl_1_bss_3E058 = 1;
    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    fn_1_4A0D8(buffer);
    lbl_1_bss_3E058 = previous;
}
/* fzgx:end fn_1_4AF64 */

/* fzgx:begin fn_1_4B040 */
void fn_1_4B040(s32 value) {
    fn_1_4B1D4(0, value);
}
/* fzgx:end fn_1_4B040 */

/* fzgx:begin fn_1_4B068 */
void fn_1_4B068(s32 value) {
    fn_1_4B1D4(1, value);
}
/* fzgx:end fn_1_4B068 */

/* fzgx:begin fn_1_4B090 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2e];
    f32 unk_34;
} FontEntry_38;

f32 fn_1_4B090(s32 value) {
    s32 count;
    s32 index;
    FontEntry_38 *entry;
    f32 a;
    f32 b;

    index = lbl_1_bss_4B9CC.unk_C;
    entry = (FontEntry_38 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    count = fn_1_4B16C(value);
    if (count - 1 > 0) {
        count = fn_1_4B16C(value) - 1;
    } else {
        count = 0;
    }
    a = lbl_1_bss_4B9CC.unk_20 *
        (entry->unk_34 * (f32)(entry->unk_5 * fn_1_4B16C(value)));
    b = lbl_1_bss_4B9CC.unk_40 * (f32)count;
    return a + b;
}
/* fzgx:end fn_1_4B090 */

/* fzgx:begin fn_1_4B16C */
s32 fn_1_4B16C(s32 value) {
    return (s32)fn_1_4B1D4(2, value);
}
/* fzgx:end fn_1_4B16C */

/* fzgx:begin fn_1_4B1A0 */
s32 fn_1_4B1A0(s32 value) {
    return (s32)fn_1_4B1D4(3, value);
}
/* fzgx:end fn_1_4B1A0 */

/* fzgx:begin fn_1_4B1D4 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

typedef struct FontEntry_4B1D4 {
    s32 unk_0;
    u8 pad_4[0x30];
    f32 unk_34;
} FontEntry_4B1D4;

extern s32 lbl_1_bss_4BA28[2];

f32 fn_1_4B1D4(s32 mode, u8 *str) {
    struct {
        Obj_1_bss_4B9CC *value;
    } p;
    s32 i;
    Obj_1_bss_4B9CC *state;
    FontEntry_4B1D4 *font;
    f32 width;
    f32 maxWidth;
    s32 adv;
    s32 count;
    s32 maxCount;
    s32 doWidth;
    s32 doCount;
    s32 doLines;
    s32 doMax;
    s32 newline;
    u8 *s;
    s32 lines;
    u8 *cp;
    u32 c;
    u16 ch;
    s32 n;

    s = str;
    p.value = &lbl_1_bss_4B9CC;
    maxWidth = 0.0f;
    width = -p.value->unk_3C;
    adv = 0;
    count = 0;
    maxCount = 0;
    lines = 1;
    doWidth = 0;
    doCount = 0;
    doLines = 0;
    doMax = 0;
    newline = 0;

    if (s == NULL && lbl_1_bss_4BA28[0] == 0) {
        lbl_1_bss_4BA28[0] = 1;
        return maxWidth;
    }

    switch (mode) {
    case 0:
        doWidth = 1;
        break;
    case 1:
        doWidth = 1;
        doMax = 1;
        break;
    case 2:
        doLines = 1;
        break;
    case 3:
        doCount = 1;
        break;
    case 4:
        doCount = 1;
        doMax = 1;
        break;
    }

    i = 0;
    font = (FontEntry_4B1D4 *)((u8 *)&lbl_1_data_1AEA8 + lbl_1_bss_4B9CC.unk_C * 0x38);
    /* `goto next` is the loop's continue: it skips the width accumulation */
    while ((ch = *(cp = s + i)) != 0) {
        state = &lbl_1_bss_4B9CC;
        c = ch;
        if ((state->unk_2C & 0x20000000) && (u16)c >= 'a' && (u16)c <= 'z') {
            c = ch - 0x20;
        }
        if (newline) {
            newline = 0;
            lines++;
        }
        if (doWidth) {
            adv = fn_1_49F08(c, state, font) & 0xFFFF;
        }
        if ((u16)c < 0x80) {
            if (font->unk_0 == -1) {
                c = fn_1_499BC(cp);
                if ((u16)c >= 0x80) {
                    i += 6;
                } else {
                    if ((u16)c == '/' && (s8)(n = fn_1_49B70(cp, 0)) != 0) {
                        i += (s8)n;
                        /* Skip glyph accumulation for this control sequence. */
                        goto next;
                    }
                    c = fn_1_49794(c);
                }
                if ((s32)lbl_1_bss_3E058 != 0 && (u16)c == '[') {
                    while (s[i] != ']') {
                        i++;
                    }
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
                if ((u16)c == '\n') {
                    if (doLines) {
                        newline = 1;
                    } else {
                        if (!doMax) {
                            break;
                        }
                        if (doWidth) {
                            maxWidth = (maxWidth > width) ? maxWidth : width;
                            width = -p.value->unk_3C;
                        } else if (doCount) {
                            maxCount = (maxCount > count) ? maxCount : count;
                            count = 0;
                        }
                        /* Skip glyph accumulation for this control sequence. */
                        goto next;
                    }
                }
                if (doWidth) {
                    adv = fn_1_49F08(c, state, font) & 0xFFFF;
                }
            } else {
                if ((u16)c == '/' && (s8)(n = fn_1_49B70(cp, 0)) != 0) {
                    i += (s8)n;
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
                if ((s32)lbl_1_bss_3E058 != 0 && (u16)c == '[') {
                    while (s[i] != ']') {
                        i++;
                    }
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
                if ((u16)c == '\n') {
                    if (doLines || !doMax) {
                        break;
                    }
                    if (doWidth) {
                        maxWidth = (maxWidth > width) ? maxWidth : width;
                        width = -p.value->unk_3C;
                    } else if (doCount) {
                        maxCount = (maxCount > count) ? maxCount : count;
                        count = 0;
                    }
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
            }
        } else {
            i++;
            c = (u16)(((u16)c << 8) | s[i]);
            if (doWidth) {
                adv = fn_1_49F08(c, state, font) & 0xFFFF;
            }
        }
        if (doWidth) {
            width += p.value->unk_3C + (f32)(state->unk_1C * ((f32)adv * font->unk_34));
        } else if (doCount) {
            count++;
        }
    next:
        i++;
    }

    if (doMax) {
        if (doWidth) {
            maxWidth = (maxWidth > width) ? maxWidth : width;
        } else if (doCount) {
            maxCount = (maxCount > count) ? maxCount : count;
        }
    }

    switch (mode) {
    case 0:
        return width;
    case 1:
        return maxWidth;
    case 2:
        return (f32)lines;
    case 3:
        return (f32)count;
    case 4:
        return (f32)maxCount;
    default:
        return -1.0f;
    }
}
/* fzgx:end fn_1_4B1D4 */

/* fzgx:begin fn_1_4B83C */
void fn_1_4B83C(void *arg0, void *arg1, u32 arg2, const char *arg3) {
    u32 length;
    s32 converted;

    length = (u32)strlen(arg3);
    converted = (s32)fn_1_4B1D4(3, arg2 + length);
    sprintf(arg0, arg1, length + converted);
}
/* fzgx:end fn_1_4B83C */

/* fzgx:begin fn_1_4B8BC */
void fn_1_4B8BC(void) {
    lbl_1_bss_4BA58 = 0;
}
/* fzgx:end fn_1_4B8BC */

/* fzgx:begin fn_1_4B8CC */
void fn_1_4B8CC(void) {
    lbl_1_bss_4BA5C = 0;
}
/* fzgx:end fn_1_4B8CC */

/* fzgx:begin fn_1_4B8DC noprologue */
#include "rel/main_rel/font.h"

extern void fn_1_4B8BC(void);
extern u32 OSGetArenaHi(void);
extern s32 fn_80006B70(void *, void *);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);

typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
} MsgData;

extern u32 fn_80006DE8(MsgData *);
extern u32 OSAllocFromArenaHi(u32, u32);
extern u32 fn_80006D1C(MsgData *, void *, u32, u32);
extern u32 fn_8002071C(void);
extern u32 ARGetDMAStatus(void);
extern u32 fn_800206FC(u32);
extern void DCFlushRange(void *, u32);

typedef void (*ARQCallback)(u32);

typedef struct {
    void *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

extern void ARQPostRequest(ARQRequest *, u32, u32, u32, void *, u32, u32, ARQCallback);
extern void OSSetArenaHi(u32);

void fn_1_4B8DC(void)
{
    u8 *base = (u8 *)&lbl_1_data_1A3B8;
    u32 size;
    void *src = base + 0x2014;
    MsgData msg;
    u32 arenaHi;
    void *p;
    u32 q;
    s32 flag;
    s32 tmp_call2;

    arenaHi = OSGetArenaHi();

    tmp_call2 = fn_80006B70(src, &msg);
    if (tmp_call2 == 0) {
        OSReport((const char *)base + 0x2030, src);
        OSPanic((const char *)base + 0x1910, 0xA77,
            (const char *)base + 0x2040);
    }

    size = (fn_80006DE8(&msg) + 0x1F) & ~0x1F;
    p = (void *)OSAllocFromArenaHi(size, 0x20);
    fn_80006D1C(&msg, p, size, 0);
    flag = 1;
    (void) flag;  /* fzgx: keeps the web at its definition */
    q = fn_8002071C();

    while (ARGetDMAStatus() != 0) {
    }

    fn_800206FC(size);
    lbl_1_bss_4BA58 = 1;
    DCFlushRange(p, size);
    ARQPostRequest((ARQRequest *)&lbl_1_bss_4BA60[0], 1, 0, 1, p, 0xF96000,
        size, (ARQCallback)fn_1_4B8BC);

    /* the AR completion flag is polled in place; the load must not be hoisted */
    while (flag == 1 && *(volatile s32 *)&lbl_1_bss_4BA58 != 0) {
    }

    fn_800206FC(q);
    OSSetArenaHi(arenaHi);
}
/* fzgx:end fn_1_4B8DC */

/* fzgx:begin fn_1_4BA24 noprologue */
#include "rel/main_rel/font.h"

extern u8 lbl_1_bss_4BA80[0xB0];
extern void fn_1_4B8CC(void);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_8002071C(void);
extern u32 fn_800206FC(u32);
extern u32 ARGetDMAStatus(void);
extern void DCInvalidateRange(void *, u32);

typedef void (*ARQCallback)(u32);

typedef struct {
    void *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

extern void ARQPostRequest(ARQRequest *, u32, u32, u32, void *, void *, u32, ARQCallback);

typedef struct {
    u8 pad_0[0x28];
    u16 unk_28;
    u8 pad_2A[0xE];
} Entry;

#pragma opt_cse off

#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline Entry *fn_1_4BA24_array_read(Entry *array) { return array; }
#pragma opt_strength_reduction off
void fn_1_4BA24(u32 arg0, s32 arg1, void *arg2)
{
    u32 saved;
    u8 *base = (u8 *)&lbl_1_data_1A3B8;
    Entry *tbl;
    u32 dest;
    u16 len;

    if ((arg0 & 0xFF) >= 0x2C) {
        OSReport((const char *)base + 0x204C, arg0 & 0xFF, 0x2C);
        OSPanic((const char *)base + 0x1910, 0xAB4, (const char *)base + 0x2060);
    }

    tbl = (Entry *)(base + 0xAF0);
    len = fn_1_4BA24_array_read(tbl)[arg0 & 0xFF].unk_28;
    dest = ((u32 *)&lbl_1_bss_4BA80)[arg0 & 0xFF] + 0xF96000 + len * arg1;

    saved = fn_8002071C();
    fn_800206FC(0x20);

    lbl_1_bss_4BA5C = 1;

    while (ARGetDMAStatus() != 0) {
    }

    DCInvalidateRange(arg2, len);
    ARQPostRequest((ARQRequest *)&lbl_1_bss_4BA60[0], 1, 1, 1, (void *)dest, arg2,
        len, (ARQCallback)fn_1_4B8CC);

    /* the AR completion flag is polled in place; the load must not be hoisted */
    while (*(volatile s32 *)&lbl_1_bss_4BA5C != 0) {
    }

    fn_800206FC(saved);
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_4BA24 */

/* fzgx:begin fn_1_4BD48 */
// fn_1_4BD48: empty in retail (single blr).
void fn_1_4BD48(void) {
}
/* fzgx:end fn_1_4BD48 */

/* fzgx:begin fn_1_4BD4C noprologue */
#include "rel/main_rel/font.h"

typedef struct FontElement {
    s32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x2];
    u32 unk_8;
    s32 unk_C;
    s8 unk_10;
    s8 unk_11;
    u8 pad_12[0x2];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x10];
    u16 *unk_2C;
    s16 *unk_30;
    f32 unk_34;
} FontElement;

typedef struct AppState {
    s8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    s8 unk_4;
    u8 pad_5[0x3];
    s32 unk_8;
} AppState;

extern u16 lbl_1_bss_D58[12];
extern u16 lbl_1_bss_96A;
extern void fn_1_48C28(int);
extern u32 fn_1_48A0C(s32, s8, void *, u32);
extern void fn_1_48140(u16);
extern void fn_1_47F74(u16);
extern u32 fn_1_4C16C(void);


void fn_1_4BD4C(u32 unused0, u32 unused1, u32 unused2) {
    s8 *fzgx_value;
    u16 *p_d58;
    s32 page_size;
    FontElement *elem;
    s32 cols;
    s32 rows;
    struct {
        FontElement *elem2;
        u16 *p25;
        s32 i;
        s32 idx;
        s32 offset;
    } lp;
    s32 prev_unk_0;
    s32 prev_unk_4;
    s32 prev_unk_8;
    s32 count;
    s32 max_page;
    AppState *sp30;

    lp.elem2 = 0; lp.p25 = 0; lp.i = 0; lp.idx = 0; lp.offset = 0;
    sp30 = (AppState *)&lbl_1_bss_4BB30;
    if (((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0].unk_0 == -1) {
        cols = 16;
        rows = 8;
    } else {
        cols = ((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0].unk_10;
        rows = ((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0].unk_11;
    }

    prev_unk_0 = *(s8 volatile *)&(sp30->unk_0) /* Retail reloads this field. */;
    p_d58 = lbl_1_bss_D58;

    if (((p_d58[8] >> 1) & 1) != 0) {
        if ((s8)++sp30->unk_0 > 43) {
            sp30->unk_0 = 0;
        }
    }
    if ((p_d58[8] & 1) != 0) {
        if ((s8)--sp30->unk_0 < 0) {
            sp30->unk_0 = 43;
        }
    }

    elem = &((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0];
    if (prev_unk_0 != sp30->unk_0) {
        sp30->unk_4 = 0;
        if (elem->unk_0 == -1) {
            fn_1_48C28(sp30->unk_1);
            lp.idx = sp30->unk_0;
            lp.elem2 = &((FontElement *)&lbl_1_data_1AEA8)[lp.idx];
            if (lp.elem2->unk_0 == -1) {
                for (lp.i = 0, lp.p25 = lp.elem2->unk_2C, lp.offset = 0; *lp.p25 != 0; lp.offset += 2, lp.i++, lp.p25++) {
                    if (*(s16 *)((u8 *)lp.elem2->unk_30 + lp.offset) == -1) fn_1_48A0C(lp.i, lp.idx, lp.elem2, 0);
                }
            }
        } else {
            fn_1_48140(((u32)((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_1].unk_0 >> 8) & 0xFFFF);
            fn_1_47F74(((u32)elem->unk_0 >> 8) & 0xFFFF);
        }
        sp30->unk_1 = sp30->unk_0;
    }

    if (elem->unk_0 == -1) {
        page_size = cols * rows;
        prev_unk_4 = sp30->unk_4;
        max_page = ((s32 *)&lbl_1_bss_40BBC)[sp30->unk_0] / page_size;
        if (((p_d58[8] >> 2) & 1) != 0) {
            if ((s8)++(*(s8 volatile *)&(sp30->unk_4)) /* Retail reloads this field. */ > max_page) {
                sp30->unk_4 = 0;
            }
        }
        if (((p_d58[8] >> 3) & 1) != 0) {
            if ((s8)--sp30->unk_4 < 0) {
                sp30->unk_4 = max_page;
            }
        }
        if (prev_unk_4 != sp30->unk_4) {
            if (sp30->unk_4 != sp30->unk_8 / page_size) {
                sp30->unk_8 = sp30->unk_4 * page_size;
            }
        }
    }

    prev_unk_8 = sp30->unk_8;
    if (elem->unk_0 == -1) {
        count = ((s32 *)&lbl_1_bss_40BBC)[sp30->unk_0];
    } else {
        count = elem->unk_C + 1;
    }

    if (((lbl_1_bss_D58[9] >> 5) & 1) != 0) {
        if (++sp30->unk_8 > count - 1) {
            sp30->unk_8 = 0;
        }
    }
    if (((lbl_1_bss_D58[9] >> 4) & 1) != 0) {
        if (--sp30->unk_8 < 0) {
            sp30->unk_8 = count - 1;
        }
    }
    if (((lbl_1_bss_D58[9] >> 6) & 1) != 0) {
        sp30->unk_8 += cols;
        if (sp30->unk_8 > count - 1) {
            sp30->unk_8 %= cols;
        }
    }
    if (((lbl_1_bss_D58[9] >> 7) & 1) != 0) {
        sp30->unk_8 -= cols;
        if (sp30->unk_8 < 0) {
            sp30->unk_8 = (sp30->unk_8 % cols) + ((count - 1) / cols + 1) * cols;
        }
        if (sp30->unk_8 > count - 1) {
            sp30->unk_8 -= cols;
        }
    }

    if (prev_unk_8 != sp30->unk_8) {
        if (sp30->unk_4 != sp30->unk_8 / (cols * rows)) {
            sp30->unk_4 = sp30->unk_8 / (cols * rows);
        }
    }

    if (elem->unk_0 == -1) {
        if (((lbl_1_bss_D58[4] >> 10) & 1) != 0) {
            sp30->unk_2 ^= 1;
        }
        if (((lbl_1_bss_D58[4] >> 11) & 1) != 0) {
            if ((s8)++sp30->unk_3 == 6) {
                sp30->unk_3 = 0;
            }
        }
    }

    if (((lbl_1_bss_D58[4] >> 12) & 1) != 0) {
        lbl_1_bss_96A = 52;
    }

    fn_1_4C16C();
}
/* fzgx:end fn_1_4BD4C */

/* fzgx:begin fn_1_4CDE4 */
/* Convert the selected font entry's byte metrics to floating-point coordinates. */
void fn_1_4CDE4(f32 *x, f32 *y) {
    Obj_1_data_1AEA8 *entry;
    s16 index;

    index = lbl_1_bss_4B9CC.unk_C;
    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    *x = (f32)(u32)entry->unk_4;
    *y = (f32)(u32)entry->unk_5;
}
/* fzgx:end fn_1_4CDE4 */

/* fzgx:begin fn_1_4CE48 */
void fn_1_4CE48(Obj_1_bss_4B9CC *obj, f32 limit) {
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    saved = lbl_1_bss_4B9CC.unk_1C;
    first = fn_1_4B1D4(1, (s32)(Obj_1_bss_4B9CC *)(obj));
    count = (s32)fn_1_4B1D4(3, (s32)(Obj_1_bss_4B9CC *)(obj));
    count = count - 1;
    adjusted = lbl_1_bss_4B9CC.unk_3C * (f32)count;
    adjusted = first + adjusted;
    if (adjusted > limit) {
        lbl_1_bss_4B9CC.unk_1C =
            lbl_1_bss_4B9CC.unk_1C * (limit / adjusted);
    }
    fn_1_4A0D8( (const char*)(Obj_1_bss_4B9CC *)(obj));
    lbl_1_bss_4B9CC.unk_1C = saved;
}
/* fzgx:end fn_1_4CE48 */

/* fzgx:begin fn_1_4CF3C */
typedef struct {
    unsigned char Sig_parse_format_justification_options;
    unsigned char Sig_parse_format_sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char Sig_parse_format_argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} Sig_parse_format_print_format;
typedef struct Sig_parse_format_MkVaListState {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format___va_list[1];
typedef Sig_parse_format___va_list Sig_parse_format_va_list;


#pragma opt_common_subs off
void fn_1_4CF3C(const char *format, f32 x, ...) {
    Obj_1_bss_4B9CC *p_lbl_1_bss_4B9CC;
    char buffer[512];
    Sig_parse_format_va_list list;
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    __builtin_va_info(&list);

    fn_8008077C((u32)buffer, (u32)(const char *)(format), (u32)((Sig_parse_format_va_list *)&list));

    p_lbl_1_bss_4B9CC = &lbl_1_bss_4B9CC;
    saved = p_lbl_1_bss_4B9CC->unk_1C;
    first = fn_1_4B1D4(1, (u32)buffer);
    count = (s32)fn_1_4B1D4(3, (u32)buffer);
    count = count - 1;
    adjusted = p_lbl_1_bss_4B9CC->unk_3C * (f32)count;
    adjusted = first + adjusted;
    if (adjusted > x) {
        p_lbl_1_bss_4B9CC->unk_1C = p_lbl_1_bss_4B9CC->unk_1C * (x / adjusted);
    }
    fn_1_4A0D8((const char *)buffer);
    p_lbl_1_bss_4B9CC->unk_1C = saved;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_4CF3C */

/* fzgx:begin fn_1_4D0A0 */
void fn_1_4D0A0(void) {
    Obj_1_bss_4BA30 *bss = &lbl_1_bss_4BA30;
    f32 *rodata = (f32 *)lbl_1_rodata_FD0;

    bss->unk_0 = 1;
    bss->unk_4 = rodata[0x16ac / 4];
    bss->unk_8 = rodata[0xf0 / 4];
    bss->unk_C = rodata[0x16b0 / 4];
    bss->unk_10 = rodata[0xf0 / 4];
}
/* fzgx:end fn_1_4D0A0 */

/* fzgx:begin fn_1_4D0D4 */
void fn_1_4D0D4(u32 *object, f32 value) {
    u32 data = *object;
    fn_1_4D10C(&data, lbl_1_rodata_26B8[0], value);
}
/* fzgx:end fn_1_4D0D4 */

/* fzgx:begin fn_1_4D10C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "rel/main_rel/font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table5[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5999999046325684f;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table7[6] = {0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.600000023841858f;
}
static const unsigned long fzgx_pool_table9[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5999999046325684f;
}
static const unsigned long fzgx_pool_table11[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.399999976158142f;
    s = 3.700000047683716f;
    s = 1.2999999523162842f;
}
static const unsigned long fzgx_pool_table13[3] = {0x00000000, 0x3FCCCCCD, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.8999999761581421f;
    s = -0.800000011920929f;
}
static const unsigned long fzgx_pool_table15[14] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table17[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table21[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table25[1371] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const unsigned long fzgx_pool_table27[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 640.0f;
    s = 480.0f;
}
static const unsigned long fzgx_pool_table29[9] = {0x80808000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFF000000, 0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 150.0f;
    s = 12.0f;
    s = 2.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table31[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
}
#pragma section code_type ".text"

extern void fn_1_53B14(void *, f32, f32, f32, f32, f32);
extern int __abs(int);

void fn_1_4D10C(void *a, f32 p1, f32 p2) {
    s32 w, h, cx, cy;
    if ((s32)lbl_1_bss_4BA30.unk_0 != 0) {
        lbl_1_bss_4BA30.unk_0 = 0;
        if (640.0f == lbl_1_bss_4BA30.unk_4 && 0.0 == lbl_1_bss_4BA30.unk_8 && 480.0f == lbl_1_bss_4BA30.unk_C && 0.0 == lbl_1_bss_4BA30.unk_10) {
            return;
        }
        if (lbl_1_bss_4BA30.unk_C > lbl_1_bss_4BA30.unk_10) return;
        if (lbl_1_bss_4BA30.unk_4 > lbl_1_bss_4BA30.unk_8) return;
        {
            f32 left = lbl_1_bss_4BA30.unk_4;
            f32 right = lbl_1_bss_4BA30.unk_8;
            f32 bottom = lbl_1_bss_4BA30.unk_10;
            f32 top = lbl_1_bss_4BA30.unk_C;
            w = __abs((s32)(right - left));
            h = __abs((s32)(top - bottom));
            cx = (s32)((left + right) / 2.0f);
            cy = (s32)((top + bottom) / 2.0f);
        }
        fn_1_53B14(a, (f32)cx, (f32)cy, (f32)w + p2, (f32)h + p2, p1);
    }
}
/* fzgx:end fn_1_4D10C */

/* fzgx:begin fn_1_4D274 */
void fn_1_4D274(u32 *object, f32 value) {
    u32 data = *object;
    fn_1_4D2AC(&data, lbl_1_rodata_26B8[0], value);
}
/* fzgx:end fn_1_4D274 */

/* fzgx:begin fn_1_4D2AC noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void fzgx_pool_sink_f32(f32);
extern void fzgx_pool_sink_f64(f64);
const u32 fzgx_pool_table_0[66] = {
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0xBF800000, 0xBF800000, 0x3F800000, 0xBF800000,
0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000,
0x40266666, 0x00000000, 0x40266666, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x3FCCCCCD, 0xBF800000, 0x40666666, 0xBF800000,
0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000,
0xBFB33333, 0x406CCCCD, 0x3FA66666, 0x00000000,
0x3FCCCCCD, 0x3F000000, 0xBF666666, 0xBF4CCCCD,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x3FE00000, 0x00000000,
0x3F400000, 0x3F800000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_108(void) { fzgx_pool_sink_f32(255.0f); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_10c[1] = {
0x00000000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_110(void) { fzgx_pool_sink_f64(4503599627370496.0); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_118[4] = {
0xFFFFFFFF, 0x00000000, 0x3D4CCCCD, 0x00000000,

};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_128(void) { fzgx_pool_sink_f64(4503601774854144.0); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_130[1371] = {
0x00000000, 0x000D0000, 0x00000000, 0x070D0000,
0x00000000, 0x010B0000, 0x00000000, 0x010C0000,
0x00000000, 0x02070000, 0x00000000, 0x02070000,
0x00000000, 0x08090000, 0x00000000, 0x08090000,
0x00000000, 0x10080000, 0x00000000, 0x01080000,
0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000,
0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000,
0x00000000, 0x060E0000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x050F0000,
0x00000000, 0x04100000, 0x00000000, 0x050F0000,
0x00000000, 0x070B0000, 0x00000000, 0x04100000,
0x00000000, 0x050F0000, 0x00000000, 0x09070000,
0x00000000, 0x060A0000, 0x00000000, 0x060F0000,
0x00000000, 0x09070000, 0x00000000, 0x03140000,
0x00000000, 0x050F0000, 0x00000000, 0x04100000,
0x00000000, 0x050F0000, 0x00000000, 0x04100000,
0x00000000, 0x070B0000, 0x00000000, 0x050E0000,
0x00000000, 0x070B0000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x02150000,
0x00000000, 0x050F0000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x04110000,
0x00000000, 0x05100000, 0x00000000, 0x04110000,
0x00000000, 0x04120000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x04110000,
0x00000000, 0x04110000, 0x00000000, 0x09070000,
0x00000000, 0x050C0000, 0x00000000, 0x05110000,
0x00000000, 0x060E0000, 0x00000000, 0x02140000,
0x00000000, 0x04110000, 0x00000000, 0x04120000,
0x00000000, 0x05100000, 0x00000000, 0x04120000,
0x00000000, 0x05100000, 0x00000000, 0x060F0000,
0x00000000, 0x060E0000, 0x00000000, 0x04110000,
0x00000000, 0x05110000, 0x00000000, 0x01170000,
0x00000000, 0x03120000, 0x00000000, 0x04110000,
0x00000000, 0x04100000, 0x00000000, 0x00000000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00090000, 0x00000000, 0x000D0000,
0x00000000, 0x00000000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00090000,
0x00000000, 0x000D0000, 0x00000000, 0x00000000,
0x00000000, 0x010E0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x010E0000,
0x00000000, 0x04080000, 0x00000000, 0x020C0000,
0x00000000, 0x010E0000, 0x00000000, 0x020C0000,
0x00000000, 0x010E0000, 0x00000000, 0x010E0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x010E0000, 0x00000000, 0x010E0000,
0x00000000, 0x010E0000, 0x00000000, 0x010E0000,
0x00000000, 0x010E0000, 0x00000000, 0x020C0000,
0x00000000, 0x00000000, 0x00000000, 0x00190000,
0x00000000, 0x00170000, 0x00000000, 0x00170000,
0x00000000, 0x00170000, 0x00000000, 0x00120000,
0x00000000, 0x00110000, 0x00000000, 0x00170000,
0x00000000, 0x00170000, 0x00000000, 0x000B0000,
0x00000000, 0x000F0000, 0x00000000, 0x00180000,
0x00000000, 0x00110000, 0x00000000, 0x001D0000,
0x00000000, 0x00150000, 0x00000000, 0x00170000,
0x00000000, 0x00150000, 0x00000000, 0x00170000,
0x00000000, 0x00160000, 0x00000000, 0x00180000,
0x00000000, 0x00170000, 0x00000000, 0x00170000,
0x00000000, 0x00190000, 0x00000000, 0x001F0000,
0x00000000, 0x00180000, 0x00000000, 0x00170000,
0x00000000, 0x00130000, 0x00000000, 0x00000000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x000B0000, 0x00000000, 0x00080000,
0x00000000, 0x000D0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000F0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x00090000,
0x00000000, 0x00000000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00080000,
0x00000000, 0x000E0000, 0x00000000, 0x00000000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x00060000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000F0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000F0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x00050000,
0x00000000, 0x00000000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00050000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x000B0000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x000B0000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00000000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0xFD070000,
0x00000000, 0xFD050000, 0x00000000, 0xFD090000,
0x00000000, 0x00000000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0xFE050000,
0x00000000, 0xFE030000, 0x00000000, 0xFE060000,
0x00000000, 0x00000000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000,
0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000,
0x00000000, 0x00000000, 0x00000000, 0x000C0000,
0x00000000, 0x00020000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000A0000,
0x00000000, 0x00020000, 0x00000000, 0x00040000,
0x00000000, 0x00040000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x00020000,
0x00000000, 0x00060000, 0x00000000, 0x00020000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00020000,
0x00000000, 0x00020000, 0x00000000, 0x00040000,
0x00000000, 0x00040000, 0x00000000, 0x00060000,
0x00000000, 0x00060000, 0x00000000, 0x000C0000,
0x00000000, 0x000A0000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00060000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00060000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x000A0000,
0x00000000, 0x000A0000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00020000, 0x00000000, 0x00040000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x000A0000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00060000, 0x00000000, 0x00060000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00000000, 0x00000000, 0x000C0000,
0x00000000, 0x0A040000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x04100000,
0x00000000, 0x00060000, 0x00000000, 0x08080000,
0x00000000, 0x08080000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x09060000,
0x00000000, 0x050E0000, 0x00000000, 0x0A040000,
0x00000000, 0x050E0000, 0x00000000, 0x04100000,
0x00000000, 0x070A0000, 0x00000000, 0x03120000,
0x00000000, 0x04100000, 0x00000000, 0x03120000,
0x00000000, 0x04100000, 0x00000000, 0x04100000,
0x00000000, 0x04100000, 0x00000000, 0x04100000,
0x00000000, 0x04100000, 0x00000000, 0x0A040000,
0x00000000, 0x0A040000, 0x00000000, 0x09060000,
0x00000000, 0x09060000, 0x00000000, 0x050E0000,
0x00000000, 0x04100000, 0x00000000, 0x04100000,
0x00000000, 0x01160000, 0x00000000, 0x02140000,
0x00000000, 0x03120000, 0x00000000, 0x02140000,
0x00000000, 0x03120000, 0x00000000, 0x03120000,
0x00000000, 0x02140000, 0x00000000, 0x01160000,
0x00000000, 0x070A0000, 0x00000000, 0x02140000,
0x00000000, 0x01160000, 0x00000000, 0x03120000,
0x00000000, 0x01160000, 0x00000000, 0x01160000,
0x00000000, 0x03120000, 0x00000000, 0x02140000,
0x00000000, 0x02140000, 0x00000000, 0x01160000,
0x00000000, 0x04100000, 0x00000000, 0x03120000,
0x00000000, 0x01160000, 0x00000000, 0x01160000,
0x00000000, 0x01160000, 0x00000000, 0x01160000,
0x00000000, 0x01160000, 0x00000000, 0x03120000,
0x00000000, 0x03120000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x00180000,
0x00000000, 0x03120000, 0x00000000, 0x03120000,
0x00000000, 0x050E0000, 0x00000000, 0x03120000,
0x00000000, 0x050E0000, 0x00000000, 0x050E0000,
0x00000000, 0x04100000, 0x00000000, 0x02140000,
0x00000000, 0x08080000, 0x00000000, 0x070A0000,
0x00000000, 0x03120000, 0x00000000, 0x08080000,
0x00000000, 0x01160000, 0x00000000, 0x02140000,
0x00000000, 0x04100000, 0x00000000, 0x03120000,
0x00000000, 0x03120000, 0x00000000, 0x04100000,
0x00000000, 0x060E0000, 0x00000000, 0x060C0000,
0x00000000, 0x02140000, 0x00000000, 0x03120000,
0x00000000, 0x01160000, 0x00000000, 0x02140000,
0x00000000, 0x02140000, 0x00000000, 0x050E0000,
0x00000000, 0x00000000, 0x00000000, 0x00120000,
0x00000000, 0x06060000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x010F0000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x06060000, 0x00000000, 0x00120000,
0x00000000, 0x030C0000, 0x00000000, 0x00120000,
0x00000000, 0x030C0000, 0x00000000, 0x000E0000,
0x00000000, 0x05080000, 0x00000000, 0x01100000,
0x00000000, 0x06060000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x06060000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x06060000, 0x00000000, 0x020E0000,
0x00000000, 0x01100000, 0x00000000, 0x00120000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x06060000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x040A0000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x06060000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x040A0000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00000000,
0x00000000, 0x00120000, 0x00000000, 0x07040000,
0x00000000, 0x040A0000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x010F0000, 0x00000000, 0x06080000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x00120000, 0x00000000, 0x030C0000,
0x00000000, 0x00120000, 0x00000000, 0x030C0000,
0x00000000, 0x000E0000, 0x00000000, 0x05080000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x07040000, 0x00000000, 0x07040000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x020E0000, 0x00000000, 0x01100000,
0x00000000, 0x00120000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x06060000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x040A0000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x07040000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x040A0000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00000000, 0x00000000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_169c(void) { fzgx_pool_sink_f32(0.5f); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_16a0[3] = {
0x3C23D70A, 0x3CA3D70A, 0xBF800000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16ac(void) { fzgx_pool_sink_f32(640.0f); }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16b0(void) { fzgx_pool_sink_f32(480.0f); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_16b4[15] = {
0x80808000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00,  /* fzgx-allow: A1 retail pool bytes */
0xFFFF0000, 0xFF000000, 0xFF000000, 0xFFFFFF00,
0x00000000, 0x43A00000, 0x43160000, 0x41400000,
0x40000000, 0x3DCCCCCD, 0x00000000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16f0(void) { fzgx_pool_sink_f64(0.0); }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16f8(void) { fzgx_pool_sink_f32(13.0f); }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16fc(void) { fzgx_pool_sink_f32(26.0f); }
#pragma section code_type ".text"

typedef struct { u8 r, g, b, a; } Color;
typedef struct {
    u32 type;
    f32 x, y, z;
    u8 pad10[0x1c];
    f32 alpha;
    u32 mode;
    u32 unk34;
    Color color;
    u8 tail[0x1c];
} Draw;
extern const Draw lbl_1_rodata_26F8;
extern int __abs(int);
extern void fn_1_50164(f32, f32, f32, f32, void *);
void fn_1_4D2AC(Color arg0, f32 arg1, f32 arg2) {
    f32 left, bottom, top, right;
    s32 x, y;
    f32 alpha;
    u32 a;
    s32 width, height;
    Draw draw;
    if ((s32)lbl_1_bss_4BA30.unk_0 != 0) {
        lbl_1_bss_4BA30.unk_0 = 0;
        if (640.0f == (left = lbl_1_bss_4BA30.unk_4) && 0.0 == lbl_1_bss_4BA30.unk_8 &&
            480.0f == lbl_1_bss_4BA30.unk_C && 0.0 == lbl_1_bss_4BA30.unk_10) return;
        top = lbl_1_bss_4BA30.unk_C;
        bottom = lbl_1_bss_4BA30.unk_10;
        if (top > bottom) return;
        right = lbl_1_bss_4BA30.unk_8;
        if (left > right) return;
        width = __abs((s32)(right-left));
        height = __abs((s32)(top-bottom));
        draw = lbl_1_rodata_26F8;
        x = (s32)((left+right)/2.0f);
        y = (s32)((top+bottom)/2.0f);
        a = arg0.a;
        draw.type = 2;
        draw.x = x;
        draw.y = y;
        draw.z = arg1;
        alpha = (f32)a / 255.0f;
        draw.mode = 10;
        draw.color = arg0;
        draw.alpha = alpha;
        fn_1_50164((f32)width+arg2, (f32)height+arg2, 13.0f, 26.0f, &draw);
    }
}
/* fzgx:end fn_1_4D2AC */

/* fzgx:begin fn_1_4D494 */
void fn_1_4D494(void) {
    Obj_1_bss_4BA44 *bss = &lbl_1_bss_4BA44;
    f32 *rodata = (f32 *)lbl_1_rodata_FD0;
    bss->unk_0 = 1;
    bss->unk_4 = rodata[0x16ac / 4];
    bss->unk_8 = rodata[0xf0 / 4];
    bss->unk_C = rodata[0x16b0 / 4];
    bss->unk_10 = rodata[0xf0 / 4];
}
/* fzgx:end fn_1_4D494 */

/* fzgx:begin fn_1_4D4C8 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table5[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5999999046325684f;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table7[6] = {0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.600000023841858f;
}
static const unsigned long fzgx_pool_table9[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5999999046325684f;
}
static const unsigned long fzgx_pool_table11[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.399999976158142f;
    s = 3.700000047683716f;
    s = 1.2999999523162842f;
}
static const unsigned long fzgx_pool_table13[3] = {0x00000000, 0x3FCCCCCD, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.8999999761581421f;
    s = -0.800000011920929f;
}
static const unsigned long fzgx_pool_table15[14] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table17[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table21[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table25[1371] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const unsigned long fzgx_pool_table27[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 640.0f;
    s = 480.0f;
}
static const unsigned long fzgx_pool_table29[9] = {0x80808000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFF000000, 0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 150.0f;
    s = 12.0f;
    s = 2.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table31[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 13.0f;
    s = 26.0f;
    s = 0.1882352977991104f;
    s = 0.800000011920929f;
    s = 4.0f;
    s = 8.0f;
    s = 6.0f;
    s = 16.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Color4_4D4C8;

typedef struct {
    s32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x1C];
    f32 unk_2C;
    s32 unk_30;
    u8 pad_34[0x4];
    Color4_4D4C8 unk_38;
    u8 pad_3C[0x1C];
} Sprite_4D4C8;

extern Sprite_4D4C8 lbl_1_rodata_26F8;
extern void fn_1_50164(f32, f32, f32, f32, Sprite_4D4C8 *);

void fn_1_4D4C8(Color4_4D4C8 *color, f32 z, f32 ofs) {
    Sprite_4D4C8 s;
    Color4_4D4C8 c;
    s32 w;
    s32 h;
    f32 y;
    f32 x;
    f32 left;
    f32 right;
    f32 bottom;
    f32 top;

    if ((s32)lbl_1_bss_4BA44.unk_0 == 0) {
        return;
    }
    lbl_1_bss_4BA44.unk_0 = 0;
    if (640.0f == lbl_1_bss_4BA44.unk_4 && 0.0 == lbl_1_bss_4BA44.unk_8 &&
        480.0f == lbl_1_bss_4BA44.unk_C && 0.0 == lbl_1_bss_4BA44.unk_10) {
        return;
    }
    left = lbl_1_bss_4BA44.unk_4;
    top = lbl_1_bss_4BA44.unk_C;
    bottom = lbl_1_bss_4BA44.unk_10;
    if (top > bottom) {
        return;
    }
    right = lbl_1_bss_4BA44.unk_8;
    if (left > right) {
        return;
    }
    c = *color;
    w = __abs((s32)(right - left));
    h = __abs((s32)(top - bottom));
    s = lbl_1_rodata_26F8;
    s.unk_C = z;
    s.unk_0 = 18;
    s.unk_2C = 0.1882353f;
    s.unk_30 = 10;
    s.unk_38 = c;
    s.unk_4 = (s32)((left + right) / 2.0f);
    s.unk_8 = (s32)((top + bottom) / 2.0f);
    x = (f32)w + ofs;
    y = (f32)h + ofs;
    fn_1_50164(x, y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(4.0f + x, 2.0f + y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(8.0f + x, 4.0f + y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(12.0f + x, 6.0f + y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(16.0f + x, 8.0f + y, 2.0f, 2.0f, &s);
}
/* fzgx:end fn_1_4D4C8 */

/* fzgx:begin fn_1_4D784 noprologue */
#include "types.h"
#include "runtime/va_list.h"

extern u8 lbl_1_data_1A3B8[];
extern u8 lbl_8015B100[];
extern f32 fn_1_4B1D4(s32 mode, u8 *text);
extern s32 fn_8008077C(u8 *dst, const char *fmt, __va_list args);
extern s32 strncmp(const u8 *, const u8 *, u32);
extern u8 *fn_80083DB0(u8 *, const u8 *);
extern u32 strlen(const u8 *);

/* both characters are alphanumeric or one of - " ' ( ) */
static inline s32 fn_1_4D784_isJoined(u8 a, u8 b) {
    if (((lbl_8015B100[a] & 0xd0) || a == '-' || a == '"' || a == '\'' || a == '(' || a == ')') &&
        ((lbl_8015B100[b] & 0xd0) || b == '-' || b == '"' || b == '\'' || b == '(' || b == ')')) {
        return 1;
    }
    return 0;
}

static inline s32 fn_1_4D784_isAlnumPair(s32 a, s32 b) {
    if ((lbl_8015B100[a] & 0xd0) && (lbl_8015B100[b] & 0xd0)) {
        return 1;
    }
    return 0;
}

u8 *fn_1_4D784(s32 wordWrap, s32 hyphenate, s32 kinsoku, s32 width, u8 *out, const char *fmt, ...) {
    __va_list args;
    u8 line[0x200];
    u8 text[0x400];
    s16 i;
    u8 *q;
    s16 start;
    u8 *p;
    s16 len;
    s32 hyphen;
    s32 flag;
    u8 c;
    s16 count;
    u8 *strs = lbl_1_data_1A3B8;

    __builtin_va_info(&args);
    fn_8008077C(text, fmt, args);
    q = line;
    i = 0;
    while ((c = *(p = text + i)) != 0) {
        start = i;
        hyphen = 0;
        flag = 0;
        if (c < 0x80) {
            if (kinsoku == 1) {
                if (strncmp(p, strs + 0x1eb4, 1) == 0 || strncmp(p, strs + 0x1eac, 1) == 0) {
                    *q++ = text[i++];
                    flag = 1;
                }
            }
            len = 1;
            *q++ = text[i];
            if (hyphenate == 1 && i > 0) {
                if (fn_1_4D784_isAlnumPair(text[i - 1], text[i])) {
                    hyphen = 1;
                }
            }
        } else {
            if (kinsoku == 1) {
                if (strncmp(p, strs + 0x1d08, 2) == 0 || strncmp(p, strs + 0x1d04, 2) == 0 ||
                    strncmp(p, strs + 0x212c, 2) == 0) {
                    q[0] = text[i++];
                    flag = 1;
                    q[1] = text[i++];
                    q += 2;
                }
            }
            q[0] = text[i++];
            len = 2;
            q[1] = text[i];
            q += 2;
        }
        *q = 0;
        if (fn_1_4B1D4(1, line) > (f32)(s16)width) {
            q -= len;
            count = 0;
            if (wordWrap != 0) {
                while (fn_1_4D784_isJoined(q[-1], q[0])) {
                    q--;
                    count++;
                }
            }
            if (hyphen == 1) {
                *q++ = '-';
            }
            q[0] = '\n';
            q[1] = 0;
            fn_80083DB0(out, line);
            out += strlen(line);
            line[0] = 0;
            q = line;
            if (text[start] < 0x80) {
                while (count-- != 0) {
                    *q++ = text[start - count - 1];
                }
                if (flag == 1) {
                    start++;
                }
                c = text[start];
                if (!(lbl_8015B100[c] & 6)) {
                    *q++ = c;
                    start++;
                }
            } else {
                if (flag == 1) {
                    start += 2;
                }
                q[0] = text[start++];
                q[1] = text[start++];
                q += 2;
            }
            if (text[start] == 0) {
                *q = 0;
                break;
            }
        }
        i++;
    }
    fn_80083DB0(out, line);
    out += strlen(line);
    out[1] = 0;
    return out;
}
/* fzgx:end fn_1_4D784 */

/* fzgx:begin fn_1_4DC20 */
typedef struct {
    u32 words[23];
} FontStateCopy;

void fn_1_4DC20(void) {
    *(FontStateCopy *)&lbl_1_bss_4BB40 =
        *(FontStateCopy *)&lbl_1_bss_4B9CC;
    lbl_1_bss_4BB3C = 1;
}
/* fzgx:end fn_1_4DC20 */

/* fzgx:begin fn_1_4DC6C */
void fn_1_4DC6C(void) {
    lbl_1_bss_4B9CC = *(Obj_1_bss_4B9CC *)&lbl_1_bss_4BB40;
    lbl_1_bss_4BB3C = 0;
}
/* fzgx:end fn_1_4DC6C */

/* fzgx:begin fn_1_4DCB8 */
// Replaces the stored font state value and returns its previous value.
u32 fn_1_4DCB8(u32 value) {
    u32 old_value = lbl_1_bss_4B9CC.unk_58;
    lbl_1_bss_4B9CC.unk_58 = value;
    return old_value;
}
/* fzgx:end fn_1_4DCB8 */

/* fzgx:begin fn_1_4DCD0 */
// Returns the address of the font data embedded in the global object.
u8 *fn_1_4DCD0(void) {
    return (u8 *)&lbl_1_bss_4C688.unk_C;
}
/* fzgx:end fn_1_4DCD0 */

/* fzgx:begin fn_1_4DCE0 */
u8 *fn_1_4DCE0(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x10;
}
/* fzgx:end fn_1_4DCE0 */

/* fzgx:begin fn_1_4DCF0 */
u8 *fn_1_4DCF0(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x14;
}
/* fzgx:end fn_1_4DCF0 */

/* fzgx:begin fn_1_4DD00 */
u8 *fn_1_4DD00(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x18;
}
/* fzgx:end fn_1_4DD00 */

/* fzgx:begin fn_1_4DD10 */
u8 *fn_1_4DD10(void) {
    return &lbl_1_bss_4C688.pad_10[0xc];
}
/* fzgx:end fn_1_4DD10 */

/* fzgx:begin fn_1_4DD20 */
u8 *fn_1_4DD20(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x30;
}
/* fzgx:end fn_1_4DD20 */

/* fzgx:begin fn_1_4DD30 */
u8 *fn_1_4DD30(void) {
    return &lbl_1_bss_4C688.pad_4[0x30];
}
/* fzgx:end fn_1_4DD30 */

/* fzgx:begin fn_1_4DD40 */
u8 *fn_1_4DD40(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x40;
}
/* fzgx:end fn_1_4DD40 */

/* fzgx:begin fn_1_4DD50 */
u8 *fn_1_4DD50(void) {
    // Return the byte address used by the font data at offset 0x41.
    return &lbl_1_bss_4C688.pad_4[0x3d];
}
/* fzgx:end fn_1_4DD50 */

/* fzgx:begin fn_1_4DD60 */
u8 *fn_1_4DD60(void) {
    return &lbl_1_bss_4C688.pad_4[0x3e];
}
/* fzgx:end fn_1_4DD60 */

/* fzgx:begin fn_1_4DD70 */
u8 *fn_1_4DD70(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x44;
}
/* fzgx:end fn_1_4DD70 */

/* fzgx:begin fn_1_4DD80 */
u8 *fn_1_4DD80(void) {
    return &lbl_1_bss_4C688.pad_4[0x41];
}
/* fzgx:end fn_1_4DD80 */

/* fzgx:begin fn_1_4DD90 */
u8 *fn_1_4DD90(void) {
    return &lbl_1_bss_4C688.pad_4[0x42];
}
/* fzgx:end fn_1_4DD90 */

/* fzgx:begin fn_1_4DDA0 */
 // Return the byte address six bytes into the shared font state.
u8 *fn_1_4DDA0(void) {
    return &lbl_1_bss_4C688.pad_4[2];
}
/* fzgx:end fn_1_4DDA0 */

/* fzgx:begin fn_1_4DDB0 */
u8 *fn_1_4DDB0(void) {
    return &lbl_1_bss_4C688.pad_10[0x50];
}
/* fzgx:end fn_1_4DDB0 */

/* fzgx:begin fn_1_4DDC0 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

#pragma opt_unroll_loops off
void fn_1_4DDC0(void) {
    Obj_1_bss_4C688 *ptr;
    int count;
    ptr = &lbl_1_bss_4C688;
    for (count = 0; count < 64; count++) {
        ptr->unk_0 = 0;
        ptr = (Obj_1_bss_4C688 *)((u8 *)ptr + 0x80);
    }
}
/* fzgx:end fn_1_4DDC0 */

/* fzgx:begin fn_1_4DE04 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

u32 fn_1_4DE04(void) {
    Obj_1_bss_4C688 *p = &lbl_1_bss_4C688;
    s32 i;

    for (i = 0; i < 64; i++, p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80)) {
        p->unk_0 = 0;
    }
    return (u32)p;
}
/* fzgx:end fn_1_4DE04 */

/* fzgx:begin fn_1_4DE44 */
// Dispatch callbacks for each active font entry.
void fn_1_4DE44(void) {
    int i;
    u32 *entry;

    if (fn_1_3F164() == 0) {
        entry = &lbl_1_bss_4C688.unk_0;
        for (i = 0; i < 0x40; i++, entry += 0x20) {
            if ((int)entry[0] != 0 && entry[0x1e] != 0) {
                ((void (*)(u32 *))entry[0x1e])(entry);
            }
        }
    }
}
/* fzgx:end fn_1_4DE44 */

/* fzgx:begin fn_1_4DEC0 */
typedef u32 (*fn_1_4DEC0_Fn0)(u32);
struct fn_1_4DEC0_Copy88 { u32 a[22]; };



void fn_1_4DEC0(void) {
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 (*temp_r12)(u32 *);
    s32 var_r31;
    u32 *var_r30;

    var_r31 = 0;
    var_r30 = (u32 *)(&(*(u32 *)&lbl_1_bss_4C688));
    do {
        if ((s32) (*(u32 *)((u8 *)(var_r30) + 0)) != 0) {
            temp_r12 = (s32 (*)(u32 *))(*(s32 (**)(u32 *))((u8 *)(var_r30) + 124));
            if (temp_r12 == NULL) {
                loc_8 = *(const struct FzgxCopy_88 *)((((s32)(((u8 *)(var_r30) + 4))) + 4));
                fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
            } else {
                temp_r12((u32 *)(var_r30));
            }
        }
        var_r31 += 1;
        var_r30 = (u32 *)((u8 *)(var_r30) + 0x80);
    } while (var_r31 < 0x40);
}
/* fzgx:end fn_1_4DEC0 */

/* fzgx:begin fn_1_4DF60 */
typedef struct {
    u32 values[22];
} InitData;

typedef struct {
    s32 unk_0;
    u8 pad[0x7c];
} Slot;

Slot *fn_1_4DF60(void) {
    int i;
    Slot *p;

    p = (Slot *)&lbl_1_bss_4C688;
    for (i = 0; i < 64; i++, p++) {
        if (p->unk_0 == 0) {
            break;
        }
    }

    if (p->unk_0 != 0) {
        return 0;
    }

    *(s32 *)((u8 *)p + 0) = 1;
    *(InitData *)((u8 *)p + 8) = *(InitData *)lbl_1_rodata_26F8;
    *(u16 *)((u8 *)p + 6) = 0;
    *(u32 *)((u8 *)p + 0x68) = 0;
    *(u32 *)((u8 *)p + 0x64) = 0;
    *(u32 *)((u8 *)p + 0x60) = 0;
    *(f32 *)((u8 *)p + 0x74) = lbl_1_rodata_2750;
    *(f32 *)((u8 *)p + 0x70) = lbl_1_rodata_2750;
    *(f32 *)((u8 *)p + 0x6c) = lbl_1_rodata_2750;
    *(u32 *)((u8 *)p + 0x7c) = 0;
    *(u32 *)((u8 *)p + 0x78) = 0;
    *(u8 *)((u8 *)p + 4) = 0;
    return p;
}
/* fzgx:end fn_1_4DF60 */

/* fzgx:begin fn_1_4E060 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

#pragma opt_unroll_loops off
void fn_1_4E060(void) {
    Obj_1_bss_4C688 *p;
    u32 count;
    u32 zero;

    p = &lbl_1_bss_4C688;
    zero = 0;
    for (count = 0; count < 64; count++) {
        p->unk_0 = zero;
        p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80);
    }
}
/* fzgx:end fn_1_4E060 */

/* fzgx:begin fn_1_4E0A4 */
typedef struct FontMetric {
    f32 value;
    u8 pad[0x54];
} FontMetric;

int fn_1_4E0A4(u16 *left, u16 *right) {
    u16 left_index;
    FontMetric *metrics;
    u16 right_index;
    f32 left_value;
    f32 right_value;

    left_index = *left;
    metrics = (FontMetric *)(*(u32 *)&lbl_1_data_1C504 + 0xc);
    right_index = *right;

    left_value = metrics[left_index].value;
    right_value = metrics[right_index].value;
    if (left_value > right_value) {
        return -1;
    }
    if (left_value == right_value) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_4E0A4 */

/* fzgx:begin fn_1_4E0F4 */
void fn_1_4E0F4(void) {
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}
/* fzgx:end fn_1_4E0F4 */

/* fzgx:begin fn_1_4E220 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

typedef enum {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CMPR = 0xE,
    GX_CTF_R4 = 0x0 | 0x20,
    GX_CTF_RA4 = 0x2 | 0x20,
    GX_CTF_RA8 = 0x3 | 0x20,
    GX_CTF_YUVA8 = 0x6 | 0x20,
    GX_CTF_A8 = 0x7 | 0x20,
    GX_CTF_R8 = 0x8 | 0x20,
    GX_CTF_G8 = 0x9 | 0x20,
    GX_CTF_B8 = 0xA | 0x20,
    GX_CTF_RG8 = 0xB | 0x20,
    GX_CTF_GB8 = 0xC | 0x20,
    GX_TF_Z8 = 0x1 | 0x10,
    GX_TF_Z16 = 0x3 | 0x10,
    GX_TF_Z24X8 = 0x6 | 0x10,
    GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    GX_TF_A8 = GX_CTF_A8,
} GXTexFmt;

typedef struct {
    u32 dummy[8];
} GXTexObj;

typedef enum {
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,
    GX_MAX_TEXWRAPMODE,
} GXTexWrapMode;

typedef struct {
    f32 m[12];
} Mtx;

struct Arg0 {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    s16 unk_28;
    u8 pad_2A[0x6];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u16 unk_46;
    u32 unk_48;
};

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_2754;
extern const f64 lbl_1_rodata_2758;
extern f32 fn_1_519AC(u32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006DD7C(void);
extern void lbl_8006DB74(Mtx *);
extern void mathutil_mtxA_rotate_z(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern u16 GXLoadTexMtxImm(Mtx *, u32, u32);
extern u32 __cvt_fp2unsigned(f32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, GXTexFmt, GXTexWrapMode, GXTexWrapMode, u8);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_80073C6C(s32);
extern GXTexObj lbl_1_bss_4E688;

static inline f32 fn_1_4E220_operand(f32 left, f32 right) { left *= right; return left; }
#pragma opt_common_subs on
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
static inline void fn_1_4E220_call_GXInitTexObj(GXTexObj * a0, void * a1, u16 a2, u16 a3, GXTexFmt a4, GXTexWrapMode a5, GXTexWrapMode a6, u8 a7) { GXInitTexObj(a0, a1, a2, a3, a4, a5, a6, a7); }
static inline f32 fn_1_4E220_operand_(f32 right, f32 left) { return left * right; }
void fn_1_4E220(struct Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    f32 fzgx_live;
    Mtx loc_8;
    u32 v1;
    s32 v2;
    u32 v5;
    Obj_1_data_FCD4_At20 *v6;
    u32 v7;
    f32 scale;
    f32 f44;
    f32 f46;
    struct { f32 v; } prod;
    struct { f32 v; } total;
    s32 lab_t1;
    u32 lab_t2;
    Mtx * lab_t0;
    s32 lab_t3;
    u32 lab_t3_;

    lbl_8006D7F4(arg0->unk_4, arg0->unk_8, lbl_1_rodata_2750);
    fzgx_live = arg0->unk_14;
    lbl_8006E15C(arg0->unk_10, fzgx_live, lbl_1_rodata_2754);
    if (arg0->unk_28 != 0) {
        mathutil_mtxA_rotate_z(arg0->unk_28);
    }
    lbl_8006DD7C();
    lbl_8006DB74(&loc_8);
    v1 = arg2 & 0xFF;
    v2 = arg4 & 0xFF;
    fn_800745A4(v1, 1, 4, v2, 0, 125);
    lab_t2 = 1;
    lab_t0 = &loc_8;
    GXLoadTexMtxImm(lab_t0, v2, lab_t2);
    if (arg0->unk_30 & 0x800000) {
        scale = fn_1_519AC(arg0->unk_40);
        f44 = (f32)arg0->unk_44;
        f46 = (f32)arg0->unk_46;
        scale = f44 * scale;
        scale = f46 * scale;
        DCFlushRange((void *)arg0->unk_48, __cvt_fp2unsigned(scale));
        lab_t3_ = arg0->unk_46;
        fn_1_4E220_call_GXInitTexObj(&lbl_1_bss_4E688, (void *)arg0->unk_48, ((u16)(arg0->unk_44)), lab_t3_, (GXTexFmt)arg0->unk_40, GX_CLAMP, GX_CLAMP, 0);
        lab_t1 = arg3 & 0xFF;
        fn_80073778(&lbl_1_bss_4E688, lab_t1);
    } else {
        lab_t2 = arg0->unk_0;
        v5 = lab_t2;
        v6 = *(Obj_1_data_FCD4_At20 **)((((u32)&lbl_1_data_FCD4) + 0x20) + (((v5 >> 8) & 0xFFFF) * 0x28));
        if (!(lbl_1_rodata_2750 != arg0->unk_10 && lbl_1_rodata_2750 != arg0->unk_14 && v6 != 0)) {
            return;
        } else {
            fn_80073778((void *)(v6->unk_C + ((v5 & 0xFF) << 5)), arg3 & 0xFF);
        }
    }
    v7 = arg1 & 0xFF;
    fn_80073C6C(v7);
    fn_800734A8(v7, v1, arg3 & 0xFF, 255);
    if (((0) == (arg0->unk_40)) || ((((arg0->unk_40)) == ((1))))) {
        fn_80072C24(v7, 15, 15, 15, 0);
        fn_80072D64(v7, 0, 0, 0, 1, 0);
        fn_80072CC4(v7, 7, 0, 4, 7);
        lab_t3 = 0;
        fn_80072E20(v7, 0, 0, lab_t3, 1, 0);
    } else {
        fn_800729B0(2, 0, 0, 0, 0);
        fn_80072AB0(v7, 0, 2);
        fn_80072C24(v7, 8, 15, 0, 15);
        fn_80072D64(v7, 8, 0, 0, 1, 0);
        fn_80072CC4(v7, 4, 7, 0, 7);
        lab_t3 = 0;
        fn_80072E20(v7, 14, 0, lab_t3, 1, 0);
    }
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_4E220 */

/* fzgx:begin fn_1_4E500 */
void fn_1_4E500(void) {
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();
}
/* fzgx:end fn_1_4E500 */

/* fzgx:begin fn_1_4E638 */
void fn_1_4E638(s32 arg) {
    f32 *values;

    values = lbl_1_rodata_26F8;
    if (arg != 0) {
        C_MTXPerspective( (f32 *)(void *)((u8 *)lbl_801A6D00 + 0xc8),
                    values[26], fn_1_A6FE8(), values[27], values[28]);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 0);
    } else {
        C_MTXOrtho((u8 *)lbl_801A6D00 + 0xc8,
                    values[22], values[29], values[22], values[30],
                    values[22], values[28]);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 1);
    }
}
/* fzgx:end fn_1_4E638 */

/* fzgx:begin fn_1_4E6F4 */
void fn_1_4E6F4(void) {
    fn_1_A722C();
    fn_80074918(1, 3, 1);
}
/* fzgx:end fn_1_4E6F4 */

/* fzgx:begin fn_1_4E724 */
// Initialize the font system and return the selected font resource.
s32 fn_1_4E724(FontParams *arg) {
    FontParams local = *arg;
    s32 ret;

    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();

    if ((s32)lbl_1_bss_4E6A8 != 0) {
        local.unk_30 |= 0x08000000;
        local.unk_34 = (f32)(s32)lbl_1_bss_4E6AC;
    }

    ((u8 *)lbl_801A6D00)[0x197] = 0xff;

    if (local.unk_30 & 0x00800000) {
        ret = fn_1_4EC74(&local);
    } else {
        ret = fn_1_4EB74( (fn_1_4EB74_FontObject *)(FontParams *)(&local));
    }

    fn_1_A722C();
    fn_80074918(1, 3, 1);

    return ret;
}
/* fzgx:end fn_1_4E724 */

/* fzgx:begin fn_1_4E92C */
typedef struct Sig_fn_1_4EC74_FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} Sig_fn_1_4EC74_FontParams;

typedef struct Sig_fn_1_4EB74_FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} Sig_fn_1_4EB74_FontParams;

struct fn_1_4E92C_Copy88 { u32 a[22]; };
struct fn_1_4E92C_lbl_1_bss_4E6AC {
    s32 unk_0;
};
struct fn_1_4E92C_lbl_1_rodata_2778 {
    f64 unk_0;
};
struct fn_1_4E92C_lbl_801A6D00 {
    u32 unk_0;
};

s32 fn_1_4E92C(s32 arg0, u32 arg1, s16 arg2, s16 arg3, u32 arg4) {
    struct FzgxCopy_88 loc_60;
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 var_r31;

    loc_60 = *(const struct FzgxCopy_88 *)((arg0 - 4 + 4));
    loc_60.words[0x10] = arg1;
    loc_60.words[0xC] |= 0x800000;
    (*(s16 *)((u8 *)(&loc_60) + 68)) = arg2;
    (*(s16 *)((u8 *)(&loc_60) + 70)) = arg3;
    loc_60.words[0x12] = arg4;
    loc_8 = *(const struct FzgxCopy_88 *)((((s32)(&loc_8.words[0x15])) + 4));
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C((u32)(0x2200U));
    fn_80074788((u32)(0U));
    fn_80074660((u32)(1U));
    fn_80073678((u32)(1U));
    fn_80073898((u32)(0U));
    fn_80073C6C((s32)(0));
    fn_800745A4((u32)(0U), (s32)(1), (s32)(4), (u32)(0x3CU), (u32)(0U), (u32)(0x7DU));
    fn_800734A8((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0xFFU));
    fn_80072AB0((s32)(0), (s32)(0), (s32)(0));
    fn_80072C24((s32)(0), (s32)(0xF), (s32)(2), (s32)(8), (s32)(4));
    fn_80072D64((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(0U), (u32)(7U), (u32)(1U), (u32)(4U), (u32)(2U));
    fn_80072E20((s32)(0), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80074918((u8)(1U), (s32)(7), (u8)(0U));
    fn_800728A8((s32)(1), (s32)(4), (s32)(5), (s32)(0));
    fn_800720B0((u32)(0U));
    fn_80072864((u32)(2U));
    lbl_8006D758();
    fn_80072558();
    if ((s32) (*(u32 *)((u8 *)(&lbl_1_bss_4E6A8) + 0)) != 0) {
        loc_8.words[0xC] |= 0x08000000;
        (*(f32 *)((u8 *)(&loc_8) + 52)) = (f32) (*((struct fn_1_4E92C_lbl_1_bss_4E6AC *)&lbl_1_bss_4E6AC)).unk_0;
    }
    (*(u8 *)((u8 *)((*((struct fn_1_4E92C_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 407)) = 0xFF;
    if (loc_8.words[0xC] & 0x800000) {
        var_r31 = fn_1_4EC74( (FontParams *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    } else {
        var_r31 = fn_1_4EB74( (fn_1_4EB74_FontObject *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    }
    fn_1_A722C();
    fn_80074918((u8)(1U), (s32)(3), (u8)(1U));
    return var_r31;
}
/* fzgx:end fn_1_4E92C */

/* fzgx:begin fn_1_4EB74 */
/* lbl_1_data_FCD4 is indexed as an array of 0x28-byte records; the header's
   Obj_1_data_FCD4 spans the whole blob, so index through this record view. */
typedef struct TableEntry {
    s32 unk_0;
    u32 unk_4;
    u8 pad_8[0x18];
    Obj_1_data_FCD4_At20 *unk_20;
    u32 unk_24;
} TableEntry;

s32 fn_1_4EB74(fn_1_4EB74_FontObject *self) {
    TableEntry *table;
    Obj_1_data_FCD4_At20 *data;
    u32 value;
    u32 index;
    u16 *row;
    f32 x;
    f32 y;

    if (self->unk_30 & 0x02000000) {
        return 0;
    }

    value = self->unk_0;
    fn_1_159588(value);
    value = self->unk_0;

    index = (value >> 8) & 0xffff;
    table = (TableEntry *)&lbl_1_data_FCD4;
    if (table[index].unk_0 == 0) {
        return 0;
    }

    data = table[index].unk_20;
    row = (u16 *)((u8 *)data->unk_4 + ((value & 0xff) << 4));
    x = (f32)(u32)row[4];
    y = (f32)(u32)row[5];
    fn_80073778((void *)((u8 *)data->unk_C + ((value & 0xff) << 5)), 0);
    fn_1_4EDAC( (FontDrawPacket*)(void *)(self), x, y);
    return 1;
}
/* fzgx:end fn_1_4EB74 */

/* fzgx:begin fn_1_4F724 */
// Clear the font state value before the next initialization.
void fn_1_4F724(void) {
    lbl_1_bss_646D2.unk_0 = 0;
}
/* fzgx:end fn_1_4F724 */

/* fzgx:begin fn_1_4F734 noprologue */
#include "types.h"
#include "font.h"

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;
typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;
typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;
typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;
typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;
extern State lbl_1_bss_4C678;
extern Config lbl_1_data_1C500;
extern u16 lbl_1_bss_646D2;
extern u8 *lbl_801A6D00;
extern Resource lbl_1_data_FCD4[];
extern void fn_1_A71CC(void), fn_800724C8(void), lbl_8006D758(void), fn_80072558(void),
    fn_1_A722C(void);
extern void fn_8007245C(u32), fn_80074788(u32), fn_80074660(u32), fn_80073678(u32),
    fn_80073898(u32), fn_80073C6C(u32), fn_800720B0(u32), fn_80072864(u32);
extern void fn_800745A4(u32, u32, u32, u32, u32, u32), fn_80072D64(u32, u32, u32, u32, u32, u32),
    fn_80072E20(u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32), fn_800728A8(u32, u32, u32, u32);
extern void fn_80072AB0(u32, u32, u32), fn_80074918(u32, u32, u32);
extern void fn_80072C24(u32, u32, u32, u32, u32), fn_80072CC4(u32, u32, u32, u32, u32);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *, u32);
extern void fn_1_4EDAC(FontDrawPacket *, f32, f32);
extern void fn_1_159588(u32);
extern void OSReport(const char *, ...);
extern void *fn_80008BA8(void *, const void *, u32);
extern s32 fn_1_54298(void), fn_1_542A8(void);
extern f32 fn_1_542B8(void);
int fn_1_4F734(FontDrawPacket *input) {
    State *state = &lbl_1_bss_4C678;
    Config *config = &lbl_1_data_1C500;
    if (input->image >= 0xffff0000u)
        return 0;
    if (input->flags & 0x20000) {
        FontDrawPacket local = *input;
        int result;
        fn_1_A71CC();
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(1);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
        fn_800734A8(0, 0, 0, 0xff);
        fn_80072AB0(0, 0, 0);
        fn_80072C24(0, 0xf, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        lbl_8006D758();
        fn_80072558();
        if (state->override_enabled) {
            local.flags |= 0x08000000;
            local.depth = (f32)state->override_value;
        }
        lbl_801A6D00[0x197] = 0xff;
        if (local.flags & 0x800000) {
            if (local.flags & 0x2000000)
                result = 0;
            else {

                DCFlushRange(local.pixels, (u32)((f32)local.height *
                                                 ((f32)local.width * fn_1_519AC(local.format))));
                {
                    u32 width = local.width, height = local.height;
                    GXInitTexObj(state->texture, local.pixels, width, height, local.format, 0, 0, 0);
                }
                GXInitTexObjLOD(state->texture, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
                fn_80073778(state->texture, 0);
                fn_1_4EDAC(&local, (f32)local.width, (f32)local.height);
                result = 1;
            }
        } else {
            if (local.flags & 0x2000000)
                result = 0;
            else {
                Resource *resource;
                Resource *table;
                u32 id, index;
                fn_1_159588(local.image);
                table = lbl_1_data_FCD4;
                id = local.image;
                index = (id >> 8) & 0xffff;
                if (!table[index].loaded)
                    result = 0;
                else {
                    ImageInfo *info;
                    f32 height, width;
                    resource = table;
                    resource += index;
                    info = &resource->images->info[(u8)id];
                    width = (f32)info->width;
                    height = (f32)info->height;
                    fn_80073778(resource->images->textures[(u8)id], 0);
                    fn_1_4EDAC(&local, width, height);
                    result = 1;
                }
            }
        }
        fn_1_A722C();
        fn_80074918(1, 3, 1);
        return result;
    } else {
        u16 count = lbl_1_bss_646D2;
        FontDrawPacket *dst;
        if (count >= config->capacity) {
            if (!state->warned) {
                OSReport(config->warning);
                state->warned = 1;
            }
            return 0;
        }
        dst = &config->packets[count];
        fn_80008BA8(dst, input, 0x58);
        dst->x += (f32)fn_1_54298();
        dst->y += (f32)fn_1_542A8();
        dst->alpha *= fn_1_542B8();
        if (state->override_enabled) {
            dst->flags |= 0x08000000;
            dst->depth = (f32)state->override_value;
        }
        lbl_1_bss_646D2++;
        return 1;
    }
}
/* fzgx:end fn_1_4F734 */

/* fzgx:begin fn_1_4FC50 */
typedef struct {
    u32 unk_0;
} InputObject;

s32 fn_1_4FC50(InputObject *obj, u32 arg1, u16 arg2, u16 arg3, u32 arg4) {
    Obj_1_data_1C504_Target *entry;
    u16 index;

    if (obj->unk_0 >= 0xffff0000) {
        return 0;
    }
    index = lbl_1_bss_646D2.unk_0;
    if (index >= lbl_1_data_1C500) {
        return 0;
    }

    entry = (Obj_1_data_1C504_Target *)((u8 *)lbl_1_data_1C504 + index * 0x58);
    fn_80008BA8( (u32)(void *)(entry), (u32)(void *)(obj), 0x58);
    entry->unk_30 |= (u32)1 << 23;
    entry->unk_40 = arg1;
    entry->unk_44 = arg2;
    entry->unk_46 = arg3;
    entry->unk_48 = arg4;

    if ((s32)lbl_1_bss_4E6A8 != 0) {
        entry->unk_30 |= (u32)1 << 27;
        entry->unk_34 = (f32)(s32)lbl_1_bss_4E6AC;
    }

    lbl_1_bss_646D2.unk_0++;
    return 1;
}
/* fzgx:end fn_1_4FC50 */

/* fzgx:begin fn_1_4FD64 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

typedef void FontDrawPacket;
extern u8 *lbl_801A66CC;
extern u8 *lbl_801A6D00;
extern const f64 lbl_1_rodata_2758;
extern f32 lbl_1_rodata_2750;
extern f32 fn_1_519AC(u32);
extern int fn_1_4E0A4(u16 *, u16 *);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_800720B0(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, u8, u8, int);
extern void fn_80073778(void *, s32);
extern void fn_1_4EDAC(FontDrawPacket *, f32, f32);
extern int fn_1_159588(int);
extern void fn_1_48D80(u32);
extern void fn_1_A71CC(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
static inline void fn_1_4FD64_call_GXInitTexObj(u8 a7, int a6, int a5, int a4, u16 a3, s16 a2, void *a1, void *a0) {
    GXInitTexObj(a0, a1, a2, a3, a4, a5, a6, a7);
}
void fn_1_4FD64(f32 arg0) {
    u16 *a;
    s32 i;
    u32 lab_t4;
    u32 lab_t0;
    a = (u16 *)(lbl_801A66CC + 0x8B8);
    for (i = 0; i < lbl_1_bss_646D2.unk_0; i++) {
        a[i] = i;
    }
    qsort(a, lbl_1_bss_646D2.unk_0, 2, (int (*)(const void *, const void *))fn_1_4E0A4);
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    lab_t0 = 0;
    fn_800734A8(lab_t0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xF, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();
    lbl_801A6D00[0x197] = 0xFF;
    for (i = 0; i < lbl_1_bss_646D2.unk_0; i++) {
        Obj_1_data_1C504_Target *e = (Obj_1_data_1C504_Target *)((u8 *)lbl_1_data_1C504 + a[i] * 0x58);
        u32 fl = *(volatile u32 *)&e->unk_30; // volatile: retail reads packet flags anew in each drawing path.
        if (fl & 0x2000000) continue;
        if (fl & 0x400000) {
            fn_1_48D80((u32)e);
        } else if (fl & 0x800000) {
            if (*(volatile u32 *)&e->unk_30 & 0x2000000) continue; // volatile: preserve retail's second flags load.
            {
                f32 sc = fn_1_519AC(e->unk_40);
                sc = (f32)e->unk_44 * sc;
                sc = (f32)e->unk_46 * sc;
                DCFlushRange((void *)e->unk_48, __cvt_fp2unsigned(sc));
                lab_t4 = e->unk_46;
                fn_1_4FD64_call_GXInitTexObj(0, 0, 0, e->unk_40, lab_t4, e->unk_44, (void *)e->unk_48, lbl_1_bss_4E6B0);
                GXInitTexObjLOD(lbl_1_bss_4E6B0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
                fn_80073778(lbl_1_bss_4E6B0, 0);
                fn_1_4EDAC((FontDrawPacket *)e, (f32)e->unk_44, (f32)e->unk_46);
            }
        } else {
            if (*(volatile u32 *)&e->unk_30 & 0x2000000) continue; // volatile: preserve retail's second flags load.
            {
                u32 pk;
                Obj_1_data_FCD4_At20 *q;
                u8 *p1;
                u8 *p2;
                f32 fh;
                f32 fw;
                Obj_1_data_FCD4 *o;
                fn_1_159588(e->unk_0);
                pk = e->unk_0;
                o = (Obj_1_data_FCD4 *)((u8 *)&lbl_1_data_FCD4 + (u16)(pk >> 8) * 0x28);
                if ((s32)o->unk_0 != 0) {
                    q = o->unk_20;
                    p1 = (u8 *)q->unk_4 + ((pk & 0xFF) << 4);
                    p2 = (u8 *)q->unk_C + ((pk & 0xFF) << 5);
                    fw = (f32)*(u16 *)(p1 + 8);
                    fh = (f32)*(u16 *)(p1 + 0xA);
                    fn_80073778(p2, 0);
                    fn_1_4EDAC((FontDrawPacket *)e, fw, fh);
                }
            }
        }
    }
    fn_1_A722C();
    fn_80074918(1, 3, 1);
    lbl_1_bss_646D2.unk_0 = 0;
}
/* fzgx:end fn_1_4FD64 */

/* fzgx:begin fn_1_50164 */
void fn_1_50164(f32 a, f32 b, f32 c, f32 d) {
    fn_1_50190(a, b, c, c, d, d);
}
/* fzgx:end fn_1_50164 */

/* fzgx:begin fn_1_50190 noprologue */
#include "types.h"
#include "font.h"

struct Pkt88 { u32 words[22]; };

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_27A4;
extern const f64 lbl_1_rodata_2758;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_common_subs off
static inline u32 *fn_1_50190_array_read(u32 *array) { return array; }
#pragma opt_lifetimes off
void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    struct Pkt88 loc_8;
    s32 sp4;
    struct { f32 value; } temp_f31;
    f32 var_f30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f28_2;
    f32 temp_f30_2;
    struct { f32 value; } half;
    f32 temp_f24;
    f32 temp_f23;
    f32 var_f22;
    f32 temp_f30;
    f32 conv_h;
    u32 temp_r4;
    u32 temp_r0;
    u32 temp_r0_2;

    temp_f23 = (f32) fn_1_48690((u32)(*(u32 *)((u8 *)(arg0) + 0)));
    temp_f24 = ((f32) fn_1_486C4((u32)(*(u32 *)((u8 *)(arg0) + 0))) - farg4) - farg5;
    temp_f25 = (temp_f23 - farg2) - farg3;
    temp_f26 = (farg0 - farg2) - farg3;
    temp_f23 = (farg1 - farg4) - farg5;
    if (farg0 <= lbl_1_rodata_2750 || farg1 <= lbl_1_rodata_2750 || temp_f25 <= lbl_1_rodata_2750 || temp_f24 <= lbl_1_rodata_2750 || temp_f26 <= lbl_1_rodata_2750 || temp_f23 <= lbl_1_rodata_2750 || farg2 < lbl_1_rodata_2750 || farg3 < lbl_1_rodata_2750 || farg4 < lbl_1_rodata_2750 || farg5 < lbl_1_rodata_2750) {
        return;
    }
    {
        temp_r4 = *(u32 *)((u8 *)(arg0) + 48);
        temp_r0 = temp_r4 & 3;
        switch (temp_r0) {
        case 1:
        default:
            var_f22 = *(f32 *)((u8 *)(arg0) + 4);
            break;
        case 2:
            half.value = farg0 * (*(f32 *)((u8 *)(&lbl_1_rodata_27A4) + 0));
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - half.value;
            break;
        case 3:
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - farg0;
            break;
        }
        temp_r0_2 = (temp_r4 >> 2U) & 3;
        switch (temp_r0_2) {
        case 1:
        default:
            var_f30 = *(f32 *)((u8 *)(arg0) + 8);
            break;
        case 2:
            half.value = farg1 * (*(f32 *)((u8 *)(&lbl_1_rodata_27A4) + 0));
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - half.value;
            break;
        case 3:
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - farg1;
            break;
        }
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)(0), (s16)((s16) farg2), (s16)((s16) farg4));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)(0), (s16)((s16) temp_f25), (s16)((s16) farg4));
        temp_f29 = temp_f26;
        temp_f29 /= temp_f25;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        temp_f31.value = var_f22 + farg2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f27 = farg2;
        temp_f27 += temp_f25;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)(0), (s16)((s16) farg3), (s16)((s16) farg4));
        temp_f26 = temp_f26 + temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)((s16) farg4), (s16)((s16) farg2), (s16)((s16) temp_f24));
        temp_f28 = temp_f23 / temp_f24;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        temp_f30 = var_f30 + farg4;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)((s16) farg4), (s16)((s16) temp_f25), (s16)((s16) temp_f24));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)((s16) farg4), (s16)((s16) farg3), (s16)((s16) temp_f24));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f28_2 = farg4 + temp_f24;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)((s16) temp_f28_2), (s16)((s16) farg2), (s16)((s16) farg5));
        temp_f30_2 = temp_f23 + temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)((s16) temp_f28_2), (s16)((s16) temp_f25), (s16)((s16) farg5));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)((s16) temp_f28_2), (s16)((s16) farg3), (s16)((s16) farg5));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
    }
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_50190 */

/* fzgx:begin fn_1_508C4 */
typedef struct fn_1_508C4_FontObject {
    u32 unk0;
    f32 start_x;
    f32 start_y;
    f32 pos_x;
    f32 scale_x;
    f32 scale_y;
    u8 data[0x40];
} fn_1_508C4_FontObject;


#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_1_508C4(fn_1_508C4_FontObject *obj, f32 dx, f32 dy) {
    fn_1_508C4_FontObject work;
    s32 x;
    s32 y;
    s32 x_start;
    s32 x_end;
    s32 y_end;
    s32 width;
    s32 height;
    s32 y_start;

    x_start = (s32)obj->start_x;
    x_end = (s32)(obj->start_x + dx);
    y_start = (s32)obj->start_y;
    y_end = (s32)(obj->start_y + dy);

    width = (s32)(obj->scale_x * (f32)fn_1_48690(obj->unk0));
    height = (s32)(obj->scale_y * (f32)fn_1_486C4(obj->unk0));

    for (y = y_start; y < y_end; y += height) {
        for (x = x_start; x < x_end; x += width) {
            s32 h;
            s32 w;

            work = *obj;
            h = y_end - y;
            h = h < height ? h : height;
            w = x_end - x;
            w = w < width ? w : width;
            fn_1_51678((FontDrawPacket *)&work, obj->unk0, 0, 0, (s16)w, (s16)h);
            work.start_x = (f32)x;
            work.start_y = (f32)y;
            fn_1_4F734((FontDrawPacket *)&work);
        }
    }
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_508C4 */

/* fzgx:begin fn_1_51564 */
// Update the six halfwords that define the active font state.
void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth) {
    ((u16 *)&lbl_1_bss_4C678)[0xC02e] = first;
    ((u16 *)&lbl_1_bss_4C678)[0xC02f] = second;
    ((u16 *)&lbl_1_bss_4C678)[0xC030] = third;
    ((u16 *)&lbl_1_bss_4C678)[0xC031] = fourth;
    ((u16 *)&lbl_1_bss_4C678)[0xC032] = fifth;
    ((u16 *)&lbl_1_bss_4C678)[0xC033] = sixth;
}
/* fzgx:end fn_1_51564 */

/* fzgx:begin fn_1_5158C noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/font.h"

typedef struct FontDrawPacket FontDrawPacket;

extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

static inline int in_range(int value, int lower, int upper)
{
    if (value > upper) {
        return 0;
    }
    return value >= lower;
}

static inline int clamp(int value, int lower, int upper)
{
    int result = value;
    if (value < lower) {
        result = lower;
    } else if (result > upper) {
        result = upper;
    }
    return result;
}

void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y)
{
    s16 *state = (s16 *)((u8 *)&lbl_1_bss_4C678 + 0x20000);
    int max_x = state[-0x7f9c / 2] - 1;
    int max_y;
    int coordinate = x;
    if (!in_range(coordinate, 0, max_x)) {
        if (x < 0) {
            coordinate = 0;
        } else if (coordinate > max_x) {
            coordinate = max_x;
        }
        x = coordinate;
    }
    max_y = state[-0x7f9a / 2] - 1;
    coordinate = y;
    if (!in_range(coordinate, 0, max_y)) {
        if (y < 0) {
            coordinate = 0;
        } else if (coordinate > max_y) {
            coordinate = max_y;
        }
        y = coordinate;
    }
    fn_1_51678(packet, color, state[-0x7fa4 / 2] + x * state[-0x7fa0 / 2],
        state[-0x7fa2 / 2] + y * state[-0x7f9e / 2],
        state[-0x7fa0 / 2], state[-0x7f9e / 2]);
}
/* fzgx:end fn_1_5158C */

/* fzgx:begin fn_1_51678 */
void fn_1_51678(FontDrawPacket *p, u32 image, s16 x, s16 y, s16 width, s16 height) {
    f32 inv_height, inv_width;
    s32 texture_height, texture_width;
    p->image = image;
    texture_height = (s16)fn_1_486C4(image);
    texture_width = (s16)fn_1_48690(image);
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    {
        f32 v, u, sy, sx;
        sx = (f32)width * inv_width;
        sy = (f32)height * inv_height;
        u = (f32)x * inv_width;
        v = (f32)y * inv_height;
        p->scale_x *= sx;
        p->scale_y *= sy;
        p->u0 = u;
        p->v0 = v;
    }
    p->u1 = inv_width * (f32)(x + width);
    p->v1 = inv_height * (f32)(y + height);
}
/* fzgx:end fn_1_51678 */

/* fzgx:begin fn_1_517EC */
void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height) { f32 inv_height, inv_width;
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    p->scale_x *= (f32)width * inv_width;
    p->scale_y *= (f32)height * inv_height;
    p->u0 = (f32)x * inv_width;
    p->v0 = (f32)y * inv_height;
    p->u1 = inv_width * (f32)(x + width);
    p->v1 = inv_height * (f32)(y + height);
}
/* fzgx:end fn_1_517EC */

/* fzgx:begin fn_1_51914 */
typedef struct {
    u32 words[22];
} fn_1_51914_state;


void fn_1_51914(const fn_1_51914_state *src) {
    fn_1_51914_state state = *src;

    lbl_1_bss_4C678 = (u32)lbl_1_data_1C504 +
        (u32)lbl_1_bss_646D2.unk_0 * 0x58;
    state.words[12] |= 0x2000000;
    fn_1_4F734( (FontDrawPacket *)(void *)(&state));
}
/* fzgx:end fn_1_51914 */

/* fzgx:begin fn_1_51990 */
// Copy the font state value and enable the corresponding object flag.
void fn_1_51990(void *obj) {
    *(u32 *)((u8 *)obj + 0x4c) = lbl_1_bss_4C678;
    *(u32 *)((u8 *)obj + 0x30) |= 0x01000000;
}
/* fzgx:end fn_1_51990 */

/* fzgx:begin fn_1_519AC */
struct fn_1_519AC_lbl_1_rodata_26F8 {
    u8 pad_0[0x58];
    f32 unk_58;
    f32 unk_5C;
    u8 pad_60[0x4C];
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
};



f32 fn_1_519AC(u32 value) {
    struct fn_1_519AC_lbl_1_rodata_26F8 *base = &(*(struct fn_1_519AC_lbl_1_rodata_26F8 *)&lbl_1_rodata_26F8);

    switch (value) {
    case 0:
    case 14:
        return base->unk_AC;
    case 1:
    case 2:
    case 17:
        return base->unk_5C;
    case 3:
    case 4:
    case 5:
    case 19:
        return base->unk_B0;
    case 6:
    case 22:
        return base->unk_B4;
    default:
        return base->unk_58;
    }
}
/* fzgx:end fn_1_519AC */

/* fzgx:begin fn_1_519FC */
typedef struct {
    f32 width;
    u8 pad0[4];
    f32 height;
    u8 pad1[8];
} FontViewport;

f32 fn_1_519FC(f32 value) {
    FontViewport viewport;
    f32 width;
    f32 height;

    fn_80038F10( (f32*)(void *)(&viewport));

    width = viewport.width;
    height = viewport.height;

    return value * height / (f32)(u32)fn_1_A5D88()
         + lbl_1_rodata_2770 * width / (f32)(u32)fn_1_A5D88();
}
/* fzgx:end fn_1_519FC */

/* fzgx:begin fn_1_51AC0 */
typedef struct {
    u8 unk0[4];
    f32 value0;
    u8 unk10[4];
    f32 value1;
    u8 tail[8];
} FnData;

f32 fn_1_51AC0(f32 value) {
    f32 input = value;
    f32 value0;
    f32 value1;
    f32 part;
    f32 denom;
    f32 result;
    FnData data;
    u64 padding;

    fn_80038F10( (f32*)(void *)(&data));
    value0 = data.value0;
    value1 = data.value1;
    denom = (f32)((u32)fn_1_A5DB0() & 0xffff);
    part = lbl_1_rodata_276C * value0 / denom;
    denom = (f32)((u32)fn_1_A5DB0() & 0xffff);
    result = input * value1 / denom;
    return result + part;
}
/* fzgx:end fn_1_51AC0 */

/* fzgx:begin fn_1_51B84 */
typedef struct Fn151B84Tmp {
    u8 unk[8];
    f32 value;
    u8 rest[12];
} Fn151B84Tmp;

f32 fn_1_51B84(f32 value) {
    Fn151B84Tmp tmp;
    f32 factor;
    f32 input;
    input = value;
    fn_80038F10( (f32*)(void *)(&tmp));
    factor = tmp.value;
    return input * factor / (f32)fn_1_A5D88();
}
/* fzgx:end fn_1_51B84 */

/* fzgx:begin fn_1_51BFC */
typedef struct {
    u8 pad[0x0c];
    f32 value;
    u8 tail[8];
} Fn51BFCData;

f32 fn_1_51BFC(f32 value) {
    Fn51BFCData data;
    f32 factor;
    u32 count;

    fn_80038F10( (f32*)(void *)(&data));
    factor = data.value;
    return value * factor / (f32)((u32)fn_1_A5DB0() & 0xffff);
}
/* fzgx:end fn_1_51BFC */

/* fzgx:begin fn_1_51C74 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    Vec4 value;
    u32 pad[2];
} Temp;


typedef struct {
    u8 pad0[0xc];
    f32 x;
    f32 y;
    u8 pad1[4];
    f32 z;
    f32 w;
} fn_1_51C74_FontData;

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
void fn_1_51C74(fn_1_51C74_FontData *obj) {
    f32 a0;
    f32 fzgx_live;
    f32 fzgx_live_;
    f32 fzgx_live__;
    Temp t0;
    Temp t1;
    Temp t2;
    f32 a1;
    Temp t3;
    struct { f32 value; } x;
    f32 b1;
    f32 w;
    struct { f32 value; } b0;
    f32 fzgx_live___;
    f32 y;
    f32 b2;
    f32 a2;

    fzgx_live___ = obj->x;
    fzgx_live = fzgx_live___;
    x.value = fzgx_live;
    fn_80038F10( (f32*)(Vec4 *)(&t0.value));
    fzgx_live__ = t0.value.x;
    fzgx_live_ = fzgx_live__;
    a0 = fzgx_live_;
{
    f32 z;
    b0.value = t0.value.z;
    obj->x = ((((x.value)) * ((b0.value)))) / (f32)((u32)fn_1_A5D88() & 0xffff)
        + lbl_1_rodata_2770 * a0 / (f32)((u32)fn_1_A5D88() & 0xffff);

    y = obj->y;
    fn_80038F10( (f32*)(Vec4 *)(&t1.value));
    a1 = t1.value.y;
    b1 = t1.value.w;
    obj->y = ((y) * (b1)) / (f32)((u32)fn_1_A5DB0() & 0xffff)
        + lbl_1_rodata_276C * a1 / (f32)((u32)fn_1_A5DB0() & 0xffff);

    z = obj->z;
    fn_80038F10( (f32*)(Vec4 *)(&t2.value));
    a2 = t2.value.z;
    obj->z = z * a2 / (f32)((u32)fn_1_A5D88() & 0xffff);
}

    w = obj->w;
    fn_80038F10( (f32*)(Vec4 *)(&t3.value));
    b2 = t3.value.w;
    obj->w = w * b2 / (f32)((u32)fn_1_A5DB0() & 0xffff);
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_51C74 */

/* fzgx:begin fn_1_51E60 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "types.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern void fn_80038F10(f32 *viewport);

static inline f32 fn_1_51E60_x(f32 x) {
    f32 viewport[6];
    f32 left;
    f32 width;

    fn_80038F10(viewport);
    left = viewport[0];
    width = viewport[2];
    return x * width / fn_1_A5D88() + 640.0f * left / fn_1_A5D88();
}

static inline f32 fn_1_51E60_y(f32 y) {
    f32 viewport[6];
    f32 top;
    f32 height;

    fn_80038F10(viewport);
    top = viewport[1];
    height = viewport[3];
    return y * height / fn_1_A5DB0() + 480.0f * top / fn_1_A5DB0();
}

static inline f32 fn_1_51E60_w(f32 w) {
    f32 viewport[6];
    f32 width;

    fn_80038F10(viewport);
    width = viewport[2];
    return w * width / fn_1_A5D88();
}

static inline f32 fn_1_51E60_h(f32 h) {
    f32 viewport[6];
    f32 height;

    fn_80038F10(viewport);
    height = viewport[3];
    return h * height / fn_1_A5DB0();
}

void fn_1_51E60(FontDrawPacket *src) {
    FontDrawPacket packet;

    packet = *src;
    packet.x = fn_1_51E60_x(packet.x);
    packet.y = fn_1_51E60_y(packet.y);
    packet.scale_x = fn_1_51E60_w(packet.scale_x);
    packet.scale_y = fn_1_51E60_h(packet.scale_y);
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_51E60 */

/* fzgx:begin fn_1_52070 */
void fn_1_52070(u32 value) {
    lbl_1_bss_4E6A8 = 1;
    lbl_1_bss_4E6AC = value;
}
/* fzgx:end fn_1_52070 */

/* fzgx:begin fn_1_52088 */
void fn_1_52088(void) {
    lbl_1_bss_4E6A8 = 0;
    lbl_1_bss_4E6AC = 0;
}
/* fzgx:end fn_1_52088 */

/* fzgx:begin fn_1_520A0 */
void fn_1_520A0(void) {
    u32 value_a;
    u32 value_b;

    value_a = lbl_1_bss_4E6A8;
    value_b = lbl_1_bss_4E6AC;
    lbl_1_bss_646E0 = value_a;
    lbl_1_bss_646E4 = value_b;
}
/* fzgx:end fn_1_520A0 */

/* fzgx:begin fn_1_520CC */
void fn_1_520CC(void) {
    u32 value_a;
    u32 value_b;

    value_a = lbl_1_bss_646E0;
    value_b = lbl_1_bss_646E4;
    lbl_1_bss_4E6A8 = value_a;
    lbl_1_bss_4E6AC = value_b;
}
/* fzgx:end fn_1_520CC */

/* fzgx:begin fn_1_520F8 */
f32 fn_1_520F8(s32 value) {
    s32 base;
    f32 scaled;

    if ((s8)fn_1_A5DC4(value) && (*(s32 *)&lbl_1_bss_4E6A8) != 0) {
        base = (*(s32 *)&lbl_1_bss_4E6AC);
        scaled = (f32)(value - base) * lbl_1_rodata_2788[0];
        return (f32)base + scaled;
    }
    return (f32)value;
}
/* fzgx:end fn_1_520F8 */

/* fzgx:begin fn_1_521B8 */
// Convert a font value to its scaled coordinate when the font system is active.
f32 fn_1_521B8(s32 value) {
    if ((s8)fn_1_A5DC4(value) && (s32)lbl_1_bss_4E6A8 != 0) {
        return lbl_1_rodata_2788[0] * (f32)value;
    }

    return (f32)value;
}
/* fzgx:end fn_1_521B8 */

/* fzgx:begin fn_1_52250 */
struct fn_1_52250_Arg0 {
    u8 pad_0[0x54];
    f32 unk_54;
};

struct fn_1_52250_Arg1 {
    f32 unk_0;
    u8 pad_4[0x8];
    f32 unk_C;
};

void fn_1_52250(struct fn_1_52250_Arg0 *arg0, struct fn_1_52250_Arg1 *arg1) {
    f32 addend;
    f32 current;

    current = arg1->unk_0;
    addend = arg0->unk_54;
    current = current + addend;
    arg1->unk_0 = current;
    current = arg1->unk_C;
    current = current + addend;
    arg1->unk_C = current;
}
/* fzgx:end fn_1_52250 */

/* fzgx:begin fn_1_5233C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "sdk_addresses.h"
#include "types.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


struct fn_1_5233C_Copy88 { u32 a[22]; };
struct ShadowEntry { u32 color; f32 x, y; };
struct ShadowTable { struct ShadowEntry e[9]; };
struct Color { u8 r,g,b,a; };
extern u32 lbl_1_rodata_27B0;
extern f32 lbl_1_rodata_2764[2];
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
#define FIFO (*(volatile f32 *)FZGX_ADDR___GXFifo) /* GX write-gather FIFO */
static inline void pos(f32 x, f32 y, f32 z) { FIFO=x; FIFO=y; FIFO=z; }
static inline f32 xy(f32 x, f32 y, f32 bias) { FIFO=x; FIFO=y; return bias; }
#define VERT(X,Y,U,V) pos((X),(Y),z); FIFO=(U); FIFO=(V)
void fn_1_5233C(void *arg0, void *arg1) {
    struct ShadowTable table;
    struct fn_1_5233C_Copy88 copy;
    struct Color color;
    u32 c0;
    struct Color c1;
    struct ShadowEntry *entry;
    f32 dx,dy,z,v0,u1,u0,v1;
    f32 bias;
    f32 *p = (f32 *)arg1;
    table = *(struct ShadowTable *)&lbl_1_rodata_27B0;
    entry = &table.e[(u32)*(f32 *)((u8 *)arg0+0x54)];
    if (!(*(u32 *)((u8 *)arg0+0x30) & 0x10000000)) {
        copy = *(struct fn_1_5233C_Copy88 *)arg0;
        c0 = entry->color;
        dx = entry->x;
        dy = entry->y;
        fn_800371F8(2, &c0);
        fn_8003462C(0x80,7,16);
        xy(p[0],p[1]-dy,0.0f);
        z = -(0.1f+*(f32 *)((u8 *)&copy+0xc)); FIFO=z;
        u0=*(f32 *)((u8 *)&copy+0x18); FIFO=u0;
        v0=*(f32 *)((u8 *)&copy+0x1c); FIFO=v0;
        pos(p[3],p[4]-dy,z);
        u1=*(f32 *)((u8 *)&copy+0x20); FIFO=u1; FIFO=v0;
        pos(p[9],p[10]-dy,z); FIFO=u1;
        v1=*(f32 *)((u8 *)&copy+0x24); FIFO=v1;
        VERT(p[6],p[7]-dy,u0,v1);
        VERT(p[0],p[1]+dy,u0,v0);
        VERT(p[3],p[4]+dy,u1,v0);
        VERT(p[9],p[10]+dy,u1,v1);
        VERT(p[6],p[7]+dy,u0,v1);
        color.a=0;
        VERT(p[0]-dx,p[1],u0,v0);
        VERT(p[3]-dx,p[4],u1,v0);
        VERT(p[9]-dx,p[10],u1,v1);
        VERT(p[6]-dx,p[7],u0,v1);
        VERT(p[0]+dx,p[1],u0,v0);
        VERT(p[3]+dx,p[4],u1,v0);
        VERT(p[9]+dx,p[10],u1,v1);
        VERT(p[6]+dx,p[7],u0,v1);
        color.r=*((u8 *)&copy+0x38);
        color.g=*((u8 *)&copy+0x39);
        color.b=*((u8 *)&copy+0x3a);
        c1=color;
        fn_800371F8(2,&c1);
    }
}
/* fzgx:end fn_1_5233C */

/* fzgx:begin fn_1_527B4 */
typedef struct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x4];
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x10];
    s16 unk_28;
} FontState;

typedef struct {
    u8 pad_0[0x20];
    Obj_1_data_FCD4_At20 *unk_20;
    u8 pad_24[0x4];
} FontTableEntry;


void fn_1_527B4(void) {
    u8 scratch[0x30];
    FontState *state;
    FontTableEntry *entry;
    Obj_1_data_FCD4_At20 *obj;
    u32 value;
    u32 index;

    state = (FontState *)lbl_1_bss_4C678;
    if (state != 0) {
        fn_80074918(1, 3, 1);
        lbl_8006D7F4(state->unk_4, state->unk_8, lbl_1_rodata_2750);
        lbl_8006E15C(state->unk_10, state->unk_14, lbl_1_rodata_2754);
        mathutil_mtxA_rotate_z(state->unk_28);
        lbl_8006DD7C();
        lbl_8006DB74(&scratch[0]);
        fn_800745A4(1, 1, 4, 0x21, 0, 0x7d);
        GXLoadTexMtxImm( (u32)(void *)(&scratch[0]), 0x21, 1);
        value = state->unk_0;
        index = ((value >> 8) & 0xffff) * 0x28;
        entry = (FontTableEntry *)&lbl_1_data_FCD4;
        entry = (FontTableEntry *)((u8 *)entry + index);
        obj = entry->unk_20;
        if (lbl_1_rodata_2750 == state->unk_10 ||
            lbl_1_rodata_2750 == state->unk_14 ||
            obj == 0) {
            return;
        }
        fn_80073778((void *)((u8 *)obj->unk_C + ((value & 0xff) << 5)), 1);
    }
    fn_80074660(2);
    fn_80073678(2);
    fn_80073C6C(1);
    fn_800734A8(1, 1, 1, 0xff);
    fn_80072C24(0, 0xf, 0xf, 0xf, 0xf);
    fn_80072C24(1, 4, 0xc, 8, 0xf);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 7, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);
}
/* fzgx:end fn_1_527B4 */

/* fzgx:begin fn_1_52968 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table4[19] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 55.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[27] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u32 lbl_801A66B4;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern void fn_1_4954C(f32 value);
extern void fn_1_52B68(void *arg0, void *arg1);
extern void fn_1_52B8C(void *arg0, void *arg1);
extern void fn_1_52BB0(void *arg0, void *arg1);
extern void fn_1_52BD4(void *arg0, void *arg1);
extern void fn_1_530C8(void *arg0);

// Draw formatted text as four rotated layers (one vertex callback each, each
// slightly deeper), then the top layer through fn_1_530C8 unless mode 5.
void fn_1_52968(s32 x, s32 y, f32 depth, const char *format, ...) {
    char buffer[4096];
    __va_list args;
    void (*callbacks[4])(void *, void *) = { fn_1_52B68, fn_1_52B8C, fn_1_52BB0, fn_1_52BD4 };
    u32 i;
    f32 step;

    __builtin_va_info(&args);
    fn_8008077C((u32)(char *)buffer, (u32)format, (u32)&args);

    for (i = 0; i < 4; i++) {
        fn_1_496FC((f32)x, (f32)y);
        fn_1_49738((u32)callbacks[i]);
        step = 0.1f * (f32)(s32)i;
        fn_1_4954C(depth + step);
        fn_1_4A0D8(buffer);
    }

    if ((s32)lbl_801A66B4 != 5) {
        fn_1_496FC((f32)x, (f32)(y + 3));
        fn_1_49738((u32)fn_1_530C8);
        fn_1_4954C(0.5f + depth);
        fn_1_4A0D8(buffer);
    }
}
/* fzgx:end fn_1_52968 */

/* fzgx:begin fn_1_52B68 */
void fn_1_52B68(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0);
}
/* fzgx:end fn_1_52B68 */

/* fzgx:begin fn_1_52B8C */
void fn_1_52B8C(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0x1000);
}
/* fzgx:end fn_1_52B8C */

/* fzgx:begin fn_1_52BB0 */
void fn_1_52BB0(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0x2000);
}
/* fzgx:end fn_1_52BB0 */

/* fzgx:begin fn_1_52BD4 */
void fn_1_52BD4(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0x3000);
}
/* fzgx:end fn_1_52BD4 */

/* fzgx:begin fn_1_52BF8 */
struct fn_1_52BF8_lbl_801A6D00 {
    u32 unk_0;
};




void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2) {
    s16 s = arg2;
    s32 t1;
    s32 t2;

    (void)arg1;
    lbl_8006D758();
    t1 = s + 0x4000;
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(arg2));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x1EU), (u32)(1U));
    t2 = s + 0x8000;
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x21U), (u32)(1U));
    t1 = s + 0xC000;
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x24U), (u32)(1U));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188((s16) (s + 0x10000)));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x27U), (u32)(1U));
    fn_8007245C((u32)(0x2200U));
    fn_80073678((u32)(5U));
    fn_80074660((u32)(4U));
    fn_800745A4((u32)(0U), (s32)(1), (s32)(4), (u32)(0x1EU), (u32)(0U), (u32)(0x7DU));
    fn_800745A4((u32)(1U), (s32)(1), (s32)(4), (u32)(0x21U), (u32)(0U), (u32)(0x7DU));
    fn_800745A4((u32)(2U), (s32)(1), (s32)(4), (u32)(0x24U), (u32)(0U), (u32)(0x7DU));
    fn_800745A4((u32)(3U), (s32)(1), (s32)(4), (u32)(0x27U), (u32)(0U), (u32)(0x7DU));
    fn_80073C6C((s32)(0));
    fn_80073C6C((s32)(1));
    fn_80073C6C((s32)(2));
    fn_80073C6C((s32)(3));
    fn_80073C6C((s32)(4));
    fn_800734A8((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(1U), (u32)(1U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(2U), (u32)(2U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(3U), (u32)(3U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(4U), (u32)(0xFFU), (u32)(0xFFU), (u32)(0xFFU));
    fn_80072C24((s32)(0), (s32)(0xF), (s32)(0xF), (s32)(0xF), (s32)(8));
    fn_80072D64((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(0U), (u32)(7U), (u32)(7U), (u32)(7U), (u32)(4U));
    fn_80072E20((s32)(0), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(1), (s32)(0xF), (s32)(8), (s32)(0xC), (s32)(0));
    fn_80072D64((u32)(1U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(1U), (u32)(4U), (u32)(7U), (u32)(7U), (u32)(0U));
    fn_80072E20((s32)(1), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(2), (s32)(0xF), (s32)(8), (s32)(0xC), (s32)(0));
    fn_80072D64((u32)(2U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(2U), (u32)(4U), (u32)(7U), (u32)(7U), (u32)(0U));
    fn_80072E20((s32)(2), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(3), (s32)(0xF), (s32)(8), (s32)(0xC), (s32)(0));
    fn_80072D64((u32)(3U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(3U), (u32)(4U), (u32)(7U), (u32)(7U), (u32)(0U));
    fn_80072E20((s32)(3), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(4), (s32)(0xF), (s32)(2), (s32)(0), (s32)(4));
    fn_80072D64((u32)(4U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(4U), (u32)(7U), (u32)(1U), (u32)(0U), (u32)(2U));
    fn_80072E20((s32)(4), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80074918((u8)(1U), (s32)(3), (u8)(1U));
}
/* fzgx:end fn_1_52BF8 */

/* fzgx:begin fn_1_530C8 */
struct fn_1_530C8_lbl_801A6D00 {
    u32 unk_0;
};




#pragma opt_propagation off
void fn_1_530C8(void * arg0) {
    u32 v0;
    f32 v1;
    u32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    u32 v6;
    f32 v7;
    f32 t1;
    f32 t2;
    f32 t4;
    f32 t5;
    f32 t7;
    f32 t8;
    f32 t10;
    f32 t11;
    lbl_8006D758();
    t1 = lbl_8006D188(-6144);
    v0 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v0 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t1);
    t2 = lbl_8006D188(-22528);
    v1 = (*(f32 *)((u8 *)arg0 + 84) * t2);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v1)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 30, 1);
    t4 = lbl_8006D188(-2048);
    v2 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v2 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t4);
    t5 = lbl_8006D188(-18432);
    v3 = (*(f32 *)((u8 *)arg0 + 84) * t5);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v3)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 33, 1);
    t7 = lbl_8006D188(2048);
    v4 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v4 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t7);
    t8 = lbl_8006D188(-14336);
    v5 = (*(f32 *)((u8 *)arg0 + 84) * t8);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v5)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 36, 1);
    t10 = lbl_8006D188(6144);
    v6 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v6 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t10);
    t11 = lbl_8006D188(-10240);
    v7 = (*(f32 *)((u8 *)arg0 + 84) * t11);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v7)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 39, 1);
    fn_8007245C(8704);
    fn_80073678(5);
    fn_80074660(4);
    fn_800745A4(0, 1, 4, 30, 0, 125);
    fn_800745A4(1, 1, 4, 33, 0, 125);
    fn_800745A4(2, 1, 4, 36, 0, 125);
    fn_800745A4(3, 1, 4, 39, 0, 125);
    fn_80073C6C(0);
    fn_80073C6C(1);
    fn_80073C6C(2);
    fn_80073C6C(3);
    fn_80073C6C(4);
    fn_800734A8(0, 0, 0, 255);
    fn_800734A8(1, 1, 0, 255);
    fn_800734A8(2, 2, 0, 255);
    fn_800734A8(3, 3, 0, 255);
    fn_800734A8(4, 255, 255, 255);
    fn_80072C24(0, 15, 15, 15, 8);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80072C24(1, 15, 8, 12, 0);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);
    fn_80072C24(2, 15, 8, 12, 0);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 4, 7, 7, 0);
    fn_80072E20(2, 0, 0, 0, 1, 0);
    fn_80072C24(3, 15, 8, 12, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 4, 7, 7, 0);
    fn_80072E20(3, 0, 0, 0, 1, 0);
    fn_80072C24(4, 15, 2, 0, 4);
    fn_80072D64(4, 0, 0, 0, 1, 0);
    fn_80072CC4(4, 7, 1, 0, 2);
    fn_80072E20(4, 0, 0, 0, 1, 0);
    fn_80074918(1, 3, 1);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_530C8 */

/* fzgx:begin fn_1_535A0 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "types.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


typedef struct Fn1_535A0_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn1_535A0_Color;


/* font.h declares the packet colour as u8[4]; it holds a GXColor */
#define FN_1_535A0_COLOR(packet) (*(Fn1_535A0_Color *)(packet).color)

void fn_1_535A0(Fn1_535A0_Color color, f32 x, f32 y, f32 z, f32 width, f32 height, f32 thickness) {
    FontDrawPacket packet;

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y + height;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    packet.flags = 0xD;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x + width;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    packet.flags = 0x7;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_535A0 */

/* fzgx:begin fn_1_53830 noprologue */
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table2[19] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    d = 4503599627370496.0;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const unsigned long fzgx_pool_table12[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
}
#pragma section code_type ".text"

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern u32 lbl_1_rodata_26F8_w138[1];
extern u32 lbl_1_rodata_26F8_w13c[1];

/* Volatile views preserve the order of color updates and pool reads. */
void fn_1_53830(u32 period, f32 x, u8 val, volatile u8 *a, volatile u8 *b) {
    u32 t = lbl_801A66A0 % period;
    struct { f32 value; } f;
    u8 c;
    if (t < period / 2) {
        f.value = lbl_8006D188((s32)(65536.0f * (f32)t / (f32)period));
        c = (s32)((f32)val * f.value);
        a[2] = c;
        a[1] = c;
        a[0] = c;
        a[3] = 0;
        *(u32 *)b = *(volatile u32 *)fzgx_pool_table12; /* fzgx-allow: S2 ordered packed-color read after component stores */
    } else {
        f.value = lbl_8006D188((s32)(65536.0f * (f32)t / (f32)period));
        f.value = (f32)((1.0f - x) * f.value);
        f.value = 1.0f + f.value;
        c = (s32)(255.0f * f.value);
        b[2] = c;
        b[1] = c;
        b[0] = c;
        b[3] = 0;
        *(u32 *)a = *(volatile u32 *)fzgx_pool_table13; /* fzgx-allow: S2 ordered packed-color read after component stores */
    }
}
/* fzgx:end fn_1_53830 */

/* fzgx:begin fn_1_539CC noprologue */
#include "types.h"
#include "font.h"

extern const f32 lbl_1_rodata_2754;

typedef struct FrameColor {
    u8 r, g, b, a;
} FrameColor;

#pragma fp_contract off
FrameColor fn_1_539CC(const FrameColor *a, const FrameColor *b, f32 t) {
    FrameColor color;
    color.r = (f32)a->r * t + (f32)b->r * (lbl_1_rodata_2754 - t);
    color.g = (f32)a->g * t + (f32)b->g * (lbl_1_rodata_2754 - t);
    color.b = (f32)a->b * t + (f32)b->b * (lbl_1_rodata_2754 - t);
    color.a = (f32)a->a * t + (f32)b->a * (lbl_1_rodata_2754 - t);
    return color;
}
/* fzgx:end fn_1_539CC */

/* fzgx:begin fn_1_53B14 noprologue */
#include "types.h"

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[7];
    f32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    s32 unk3C[7];
} Fn53B14Params;

/* retail .rodata block [lbl_1_rodata_26F8, +0x15C): the function copies the 0x58-byte
   record through the pool base and reads its constants at fixed displacements. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 8.0f;
}
#pragma section code_type ".text"

void fn_1_53B14(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
    Fn53B14Params params = *(const Fn53B14Params *)fzgx_pool_table1;

    params.unk0 = 12;
    params.unk4 = a;
    params.unk8 = b;
    params.unkC = e;
    if (color != NULL) {
        params.unk2C = color[3] / 255.0;
        params.unk38 = *(u32 *)color;
    }
    params.unk30 = 10;
    fn_1_50190(&params, c, d, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53B14 */

/* fzgx:begin fn_1_53BD8 noprologue */
#include "types.h"

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[7];
    f32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    s32 unk3C[7];
} Fn53BD8Params;

/* retail .rodata block [lbl_1_rodata_26F8, +0x164): the function copies the 0x58-byte
   record through the pool base and reads its constants at fixed displacements. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
static const u32 fzgx_pool_table4[1] = {
	0x41000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
	s = 13.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
	volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
	s = 26.0f;
}
#pragma section code_type ".text"

void fn_1_53BD8(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
	Fn53BD8Params params = *(const Fn53BD8Params *)fzgx_pool_table1;

	params.unk0 = 2;
	params.unk4 = a;
	params.unk8 = b;
	params.unkC = e;
	if (color != NULL) {
		params.unk2C = (f32)((f64)*((u8 *)color + 3) / 255.0);
		params.unk38 = *(u32 *)color;
	}
	params.unk30 = 10;
	fn_1_50190(&params, c, d, 13.0f, 13.0f, 26.0f, 26.0f);
}
/* fzgx:end fn_1_53BD8 */

/* fzgx:begin fn_1_53C9C noprologue */
#include "dolphin/types.h"

#pragma pool_data on
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table2[24] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const unsigned long fzgx_pool_table12[2] = {0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 255.0;
    s = 8.0f;
    s = 13.0f;
    s = 26.0f;
    s = 0.009999999776482582f;
    d = 0.0005;
}
#pragma section code_type ".text"
typedef struct Pk {
    s32 a;
    f32 x, y, z;
    s32 pad1[7];
    f32 al;
    s32 b;
    s32 pad2;
    s32 col;
    s32 pad3[7];
} Pk;

extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(s32);
extern f32 fn_1_4B090(s32);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

void fn_1_53C9C(u8 *color, s32 id, f32 x, f32 y, f32 z, f32 s, f32 t)
{
    f32 s_local = s;
    Pk p;
    f32 tmp_call5;
    f32 a, b;
    if (z < 0.01f) {
        z = 0.01f;
    }
    fn_1_496FC(x, y);
    fn_1_4954C(z - 0.0005);
    fn_1_4955C(t, t);
    fn_1_495C8(9);
    fn_1_4A0D8((const char *)id);
    tmp_call5 = fn_1_4B068(id);
    a = tmp_call5;
    s_local = s_local * t;
    a = s_local + a;
    b = s_local + fn_1_4B090(id);
    p = *(const Pk *)fzgx_pool_table2;
    p.a = 12;
    p.x = x;
    p.y = y;
    p.z = z;
    if (color != 0) {
        p.al = color[3] / 255.0;
        p.col = *(s32 *)color;
    }
    p.b = 10;
    fn_1_50190(&p, a, b, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53C9C */

/* fzgx:begin fn_1_53E40 noprologue */
#include "types.h"

extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
	u32 field_0;
	f32 field_4;
	f32 field_8;
	f32 field_c;
	u8 pad_10[0x1c];
	f32 field_2c;
	u32 field_30;
	u8 pad_34[4];
	u32 field_38;
	u8 pad_3c[0x1c];
} Record;

/* retail .rodata block [lbl_1_rodata_26F8, +0x170): the function reads the 0x58-byte
   record through the pool base, the share of the TU pool after it is baked below. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
static const u32 fzgx_pool_table4[1] = {
	0x41000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 13.0f;
	s = 26.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 0.009999999776482582f;
	d = 0.0005;
}
#pragma section code_type ".text"

void fn_1_53E40(u8 *color, const char *name, f32 x, f32 y, f32 z, f32 w, f32 h)
{
	f32 total;
	f32 delta;

	if (z < 0.01f) {
		z = 0.01f;
	}
	fn_1_496FC(x, y);
	fn_1_4954C((f32)(z - 0.0005));
	fn_1_4955C(h, h);
	fn_1_495C8(9);
	fn_1_4A0D8(name);
	total = w * h + fn_1_4B068(name);
	delta = w * h + fn_1_4B090(name);

	{
		Record rec = *(const Record *)fzgx_pool_table1;

		rec.field_0 = 2;
		rec.field_4 = x;
		rec.field_8 = y;
		rec.field_c = z;
		if (color != 0) {
			rec.field_2c = (f32)((f64)(u32)color[3] / 255.0);
			rec.field_38 = *(u32 *)color;
		}
		rec.field_30 = 10;

		fn_1_50190(&rec, total, delta, 13.0f, 13.0f, 26.0f, 26.0f);
	}
}
/* fzgx:end fn_1_53E40 */

/* fzgx:begin fn_1_53FE4 noprologue */
#include "font.h"

extern const struct fn_1_53FE4_lbl_1_rodata_2754_pool {
    f32 unk_0;
} lbl_1_rodata_2754;

extern const struct fn_1_53FE4_lbl_1_rodata_2868_pool {
    f32 unk_0;
} lbl_1_rodata_2868;
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

typedef struct {
    u32 p;
    u8 pad[0xC];
    f32 f10, f14, f18, f1c, f20, f24;
} Fn53Obj;

#pragma opt_propagation off
void fn_1_53FE4(Fn53Obj *arg, u8 idx) {
    u32 p;
    s16 h;
    s16 w;
    f32 iw;
    f32 ih;
    s16 x;
    s16 y;
    Fn53Obj *obj;
    obj = arg;
    p = obj->p;
    x = (idx % 10) * 20;
    y = (idx / 10) * 20;
    w = fn_1_486C4(p);
    h = fn_1_48690(p);
    ih = lbl_1_rodata_2754.unk_0 / (f32)h;
    iw = lbl_1_rodata_2754.unk_0 / (f32)w;
    obj->f10 = obj->f10 * (lbl_1_rodata_2868.unk_0 * ih);
    obj->f14 = obj->f14 * (lbl_1_rodata_2868.unk_0 * iw);
    obj->f18 = (f32)x * ih;
    obj->f1c = (f32)y * iw;
    obj->f20 = ih * (f32)(x + 20);
    obj->f24 = iw * (f32)(y + 20);
    fn_1_4F734((FontDrawPacket *)obj);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_53FE4 */

/* fzgx:begin fn_1_5415C */
void fn_1_5415C(void *arg, s32 value) {
    fn_1_541A8(arg, value);
}
/* fzgx:end fn_1_5415C */

/* fzgx:begin fn_1_5417C */
void fn_1_5417C(void *arg) {
    fn_1_541A8(arg, lbl_801A66B4);
}
/* fzgx:end fn_1_5417C */

/* fzgx:begin fn_1_541A8 */
// Select the localized form for a number and column, including the special 10–20 range.
void *fn_1_541A8(void *arg, s32 column) {
    s32 is_special;
    u32 remainder;
    s32 row_index;
    u32 *row;
    u32 number = (u32)arg;

    if (number == 0) {
        return &lbl_1_data_1C5DC;
    }

    remainder = number - (number / 100) * 100;
    is_special = 0;
    if (remainder >= 10 && remainder <= 20) {
        is_special = 1;
    }

    if (is_special != 0) {
        row_index = 3;
    } else {
        number = remainder - (remainder / 10) * 10;
        is_special = 0;
        if (number >= 4 || number == 0) {
            is_special = 1;
        }
        row_index = 3;
        if (is_special == 0) {
            row_index = number - 1;
        }
    }

    row = (u32 *)(lbl_1_data_1C5EC + row_index * 24);
    return (void *)row[column < 0 ? 0 : (column > 5 ? 5 : column)];
}
/* fzgx:end fn_1_541A8 */

/* fzgx:begin fn_1_54278 */
void fn_1_54278(u32 arg0, u32 arg1) {
    lbl_1_bss_4C680 = arg0;
    lbl_1_bss_4C684 = arg1;
}
/* fzgx:end fn_1_54278 */

/* fzgx:begin fn_1_5428C */
void fn_1_5428C(f32 value) {
    lbl_1_data_1C508.unk_0 = value;
}
/* fzgx:end fn_1_5428C */

/* fzgx:begin fn_1_54298 */
u32 fn_1_54298(void) {
    return lbl_1_bss_4C680;
}
/* fzgx:end fn_1_54298 */

/* fzgx:begin fn_1_542A8 */
u32 fn_1_542A8(void) {
    return lbl_1_bss_4C684;
}
/* fzgx:end fn_1_542A8 */

/* fzgx:begin fn_1_542B8 */
f32 fn_1_542B8(void) {
    return lbl_1_data_1C508.unk_0;
}
/* fzgx:end fn_1_542B8 */

/* fzgx:begin fn_1_542C4 */
typedef struct fn_1_542C4_FontState {
    u8 pad30[0x30];
    void *unk_30;
    void *unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    u8 pad44[8];
    f32 unk_4C;
} fn_1_542C4_FontState;

// Volatile preserves the repeated loads of the shared font state.
#define FONT_STATE ((volatile fn_1_542C4_FontState *)lbl_801A66CC)

// Store the current font parameters and notify the font system.
void fn_1_542C4(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4) {
    FONT_STATE->unk_30 = arg0;
    FONT_STATE->unk_34 = arg1;
    FONT_STATE->unk_38 = arg2;
    FONT_STATE->unk_3C = arg3;
    FONT_STATE->unk_40 = arg4;
    FONT_STATE->unk_4C = arg4 - arg3;
    fn_1_54320();
}
/* fzgx:end fn_1_542C4 */

/* fzgx:begin fn_1_54320 */
struct fn_1_54320_lbl_801A66CC {
    u32 unk_0;
};

u32 fn_1_54320(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    fn_1_54668( (fn_1_54668_node *)(u32)(*(u32 *)((u8 *)v0 + 48)), *(u32 *)((u8 *)v0 + 52), 1);
    v1 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    *(u32 *)((u8 *)v1 + 68) = (*(u32 *)((u8 *)v1 + 48) + ((*(u32 *)((u8 *)v1 + 52) - 1) << 3));
    v2 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    *(u32 *)((u8 *)v2 + 72) = *(u32 *)((u8 *)v2 + 48);
    return v2;
}
/* fzgx:end fn_1_54320 */

/* fzgx:begin fn_1_54384 */
typedef struct fn_1_54384_FontState {
    u8 pad_00[0x30];
    u8 *glyphs;
    s32 glyph_count;
    f32 start;
    f32 end;
    u8 pad_40[4];
    u8 *lower;
    u8 *upper;
    f32 step;
} fn_1_54384_FontState;



u8 *fn_1_54384(f32 value) {
    fn_1_54384_FontState *state = (*(fn_1_54384_FontState * *)&lbl_801A66CC);
    f32 pos = -value + state->start;
    f32 adjusted = pos - state->end;
    s32 index;
    s32 count;
    u8 *entry;

    if (adjusted < lbl_1_rodata_2870) {
        index = 0;
    } else {
        count = state->glyph_count;
        index = (s32)((f32)(s32)count * adjusted /
                      (adjusted + state->step));
        if (index >= count) {
            index = count - 1;
        }
    }

    entry = state->glyphs + index * 8;
    if (state->lower > entry) {
        state->lower = entry;
    }
    if ((*(fn_1_54384_FontState * *)&lbl_801A66CC)->upper < entry) {
        (*(fn_1_54384_FontState * *)&lbl_801A66CC)->upper = entry;
    }
    return entry;
}
/* fzgx:end fn_1_54384 */

/* fzgx:begin fn_1_54448 */
struct fn_1_54448_lbl_801A66CC {
    u32 unk_0;
};

void **fn_1_54448(s32 arg0) {
    void **temp_r3;

    temp_r3 = (void **)((*(s32 *)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 48)) + (arg0 * 8));
    if ((void **) (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 68)) > temp_r3) {
        (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 68)) = (void **)(temp_r3);
    }
    if ((void **) (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 72)) < temp_r3) {
        (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 72)) = (void **)(temp_r3);
        return temp_r3;
    }
    return temp_r3;
}
/* fzgx:end fn_1_54448 */

/* fzgx:begin fn_1_5448C */
typedef struct {
    u8 pad_0[0x30];
    u8 *table;
    s32 count;
    f32 value_38;
    f32 clamp_3c;
    u8 pad_40[4];
    u8 *current;
    u8 *maximum;
    f32 value_4c;
} FontGlobals;



#pragma opt_common_subs on
static inline f32 fn_1_5448C_read_pointer(FontGlobals * owner) { return owner->value_4c; }
u32 fn_1_5448C(arg, lab_unused0, lab_unused1, lab_unused2)
void *arg;
u32 lab_unused0;
u32 lab_unused1;
u32 lab_unused2;
{
    f32 fzgx_live_;
    f32 fzgx_live;
    Vec3 vec;
    f32 clamp;
    f32 sum;
    f32 distance;
    s32 index;
    u8 *entry;
    u8 *state;

    lbl_8006E1B0(arg, &vec);
    state = lbl_801A66CC;
    clamp = ((FontGlobals *)state)->clamp_3c;
    fzgx_live = vec.z;
    vec.z = -fzgx_live;
    if (vec.z < clamp) {
        vec.z = clamp;
    }

    sum = vec.x * vec.x;
    fzgx_live_ = vec.y;
    sum += fzgx_live_ * fzgx_live_;
    fzgx_live = vec.z;
    sum += fzgx_live * fzgx_live;
    distance = lbl_8006D0B4(sum);
    state = lbl_801A66CC;
    distance = ((FontGlobals *)state)->value_38 + distance - clamp;

    if (distance < (0.0f)) {
        index = 0;
    } else {
        index = (s32)((f32)((FontGlobals *)state)->count * distance / (distance + fn_1_5448C_read_pointer((FontGlobals *)state)));
        if (index >= ((FontGlobals *)state)->count) {
            index = ((FontGlobals *)state)->count - 1;
        }
    }

    entry = ((FontGlobals *)state)->table + (index << 3);
    if (((FontGlobals *)state)->current > entry) {
        ((FontGlobals *)state)->current = entry;
    }
    if (((FontGlobals *)lbl_801A66CC)->maximum < entry) {
        ((FontGlobals *)lbl_801A66CC)->maximum = entry;
    }
    return (u32)entry;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5448C */

/* fzgx:begin fn_1_545B8 */
typedef struct fn_1_545B8_manager {
    u8 unk_00[0x30];
    void *unk_30;
    u32 unk_34;
    u8 unk_38[0x0C];
    u32 *unk_44;
    u32 *unk_48;
} fn_1_545B8_manager;


// Reset the font manager's node list and process any completed nodes.
void fn_1_545B8(void) {
    if (((fn_1_545B8_manager *)lbl_801A66CC)->unk_48 >=
        ((fn_1_545B8_manager *)lbl_801A66CC)->unk_44) {
        if (((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 >
            (u32 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30) {
            *(((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 - 2) = 0;
        }
        fn_1_547F8( (fn_1_547F8_node *)(void *)(((fn_1_545B8_manager *)lbl_801A66CC)->unk_48));
    }

    fn_1_54668( (fn_1_54668_node *)(void *)(((fn_1_545B8_manager *)lbl_801A66CC)->unk_30),
                ((fn_1_545B8_manager *)lbl_801A66CC)->unk_34, 1);
    ((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 =
        (u32 *)((u8 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30 +
                (((fn_1_545B8_manager *)lbl_801A66CC)->unk_34 - 1) * 8);
    ((fn_1_545B8_manager *)lbl_801A66CC)->unk_48 =
        (u32 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30;
    fn_1_9FA18();
    fn_1_58248();
}
/* fzgx:end fn_1_545B8 */

/* fzgx:begin fn_1_54668 */
// Initialize a forward- or reverse-linked list and notify the allocator.
void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse) {
    s32 i;

    if (reverse == 0) {
        i = count - 1;
        for (; i > 0; i--) {
            node->next = node + 1;
            node->data = 0;
            node++;
        }
        node->next = 0;
        node->data = 0;
    } else {
        i = count - 1;
        node += i;
        for (; i > 0; i--) {
            node->next = node - 1;
            node->data = 0;
            node--;
        }
        node->next = 0;
        node->data = 0;
    }
    fn_1_54848();
}
/* fzgx:end fn_1_54668 */

/* fzgx:begin fn_1_547F8 */
// Invoke each node callback while walking the linked list.
void fn_1_547F8(fn_1_547F8_node *node) {
    while (node != 0) {
        if (node->callback != 0) {
            node->callback(node);
        }
        node = node->next;
    }
}
/* fzgx:end fn_1_547F8 */

/* fzgx:begin fn_1_54848 */
typedef struct fn_1_54848_FontState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
} fn_1_54848_FontState;

// Volatile forces each global-state access to retain the retail load ordering.
typedef volatile fn_1_54848_FontState fn_1_54848_VolatileFontState;

// Synchronize the current and previous font-state values for the next update.
void fn_1_54848(void) {
    ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a0 =
        ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a4;
    ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1ac =
        ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a8;
}
/* fzgx:end fn_1_54848 */

/* fzgx:begin fn_1_54868 */
typedef struct fn_1_54868_FontState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
} fn_1_54868_FontState;



// Copies the current font state's two counter values into its active fields.
void fn_1_54868(u32 arg0, u32 arg1) {
    // Volatile access preserves the first retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a4 = arg0;
    // Volatile access preserves the second retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a8 = arg1;
    // Volatile access preserves the third retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a0 = ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a4;
    // Volatile access preserves the fourth retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1ac = ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a8;
}
/* fzgx:end fn_1_54868 */

/* fzgx:begin fn_1_5489C */
void fn_1_5489C(void **arg0, void **arg1) {
    void *value = *arg0;
    *arg1 = value;
    *arg0 = (void *)arg1;
}
/* fzgx:end fn_1_5489C */

/* fzgx:begin fn_1_548AC */
typedef struct FontCounterState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u8 pad_1a4[8];
    u32 unk_1ac;
} FontCounterState;

/* The shared declaration is opaque; this union gives it the recovered layout. */
typedef union FontCounterStateView {
    u8 *raw;
    FontCounterState *typed;
} FontCounterStateView;

// Advances the font counter when enough capacity remains and returns its prior value.
void * fn_1_548AC(u32 amount) {
    FontCounterStateView view;
    FontCounterState *state;
    u32 previous;

    view.raw = lbl_801A66CC;
    state = view.typed;
    if (state->unk_1ac < amount) {
        return (void *)(0);
    }

    previous = state->unk_1a0;
    state->unk_1a0 = previous + amount;
    view.raw = lbl_801A66CC;
    state = view.typed;
    state->unk_1ac -= amount;
    return (void *)(previous);
}
/* fzgx:end fn_1_548AC */

/* fzgx:begin fn_1_548EC */
typedef struct fn_1_548EC_FontState {
    u8 pad30[0x30];
    u8 *field_30;
} fn_1_548EC_FontState;



s32 fn_1_548EC(void *arg0) {
    u8 *base;
    fn_1_548EC_FontState *fs;
    s32 offset;
    s32 i;

    i = 0;
    offset = 0;
    fs = (*(fn_1_548EC_FontState * *)&lbl_801A66CC);
    while (i < 0x1000) {
        base = fs->field_30;
        if (arg0 == base + offset) {
            return i;
        }
        offset += 8;
        i++;
    }
    return -1;
}
/* fzgx:end fn_1_548EC */

/* fzgx:begin fn_1_549F4 noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Angles;

typedef struct {
    f32 s;
    f32 c;
} Vec2;

typedef struct {
    u8 pad_0[0x50];
    Vec3 v50;
    Vec3 aim[4];
    Vec3 dir[4];
    Angles rot;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
} State;

typedef struct {
    f32 zero;
    f32 deg;
    f32 half;
    f32 pad_c;
    f64 one;
    f64 degd;
    f64 halfd;
} K;

extern State *lbl_801A66CC;
extern K lbl_1_rodata_2880;
extern f32 lbl_8006D21C(s32);
extern s16 lbl_8006D2AC(f32);
extern void lbl_8006D7DC(Vec3 *);
extern u32 mathutil_mtxA_rotate_x(s32);
extern u32 mathutil_mtxA_rotate_y(s32);
extern u32 mathutil_mtxA_rotate_z(s32);
extern void lbl_8006D1B8(s16, Vec2 *);
extern void lbl_8006E1C0(Vec3 *, Vec3 *);

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void fn_1_549F4(Vec3 *arg0, Angles *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 fzgx_live_;
    f32 fzgx_live;
    f32 h;
    K *p = (K *)&lbl_1_rodata_2880;
    s16 t1, t2;
    Angles *a1 = arg1;
    Vec3 *a0 = arg0;
    s16 t3, t4;
    Vec2 v;

    lbl_801A66CC->v50 = *a0;
    lbl_801A66CC->rot = *a1;
    lbl_801A66CC->f1 = arg2;
    lbl_801A66CC->f2 = arg3;
    lbl_801A66CC->f3 = arg4;
    lbl_801A66CC->f4 = arg5;

    if ((0.0f) == arg5) {
        s32 t = (s16)((182.044449f) * arg2);
        t1 = -t / 2;
        t2 = t / 2;
    } else {
        h = lbl_8006D21C((s32)((182.044449f) * ((0.5f) * arg2)));
        t1 = -lbl_8006D2AC(h * ((1.0) - arg5));
        t2 = lbl_8006D2AC(h * ((1.0) + arg5));
    }

    if ((0.0f) == arg4) {
        s16 x = lbl_8006D2AC(arg3 * lbl_8006D21C((s32)((182.04444885253906) * ((0.5) * arg2))));
        s32 t = (s16)(x * 2);
        t3 = t / 2;
        t4 = -t / 2;
    } else {
        f32 s;
        if ((0.0f) == arg5) {
            s = arg3 * lbl_8006D21C((s32)((182.044449f) * ((0.5f) * arg2)));
        } else {
            s = h * arg3;
        }
        t3 = lbl_8006D2AC(s * ((1.0) + arg4));
        t4 = -lbl_8006D2AC(s * ((1.0) - arg4));
    }

    lbl_8006D7DC(a0);
    mathutil_mtxA_rotate_y(a1->y);
    mathutil_mtxA_rotate_x(a1->x);
    mathutil_mtxA_rotate_z(a1->z);

    lbl_8006D1B8((s16)(t3 - 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[0].x = -fzgx_live_;
    lbl_801A66CC->dir[0].y = (0.0f);
    lbl_801A66CC->dir[0].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[0], &lbl_801A66CC->aim[0]);

    lbl_8006D1B8((s16)(t4 + 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[1].x = -fzgx_live_;
    lbl_801A66CC->dir[1].y = (0.0f);
    lbl_801A66CC->dir[1].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[1], &lbl_801A66CC->aim[1]);

    lbl_8006D1B8((s16)(t1 + 0x4000), &v);
    lbl_801A66CC->dir[2].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[2].y = -fzgx_live_;
    lbl_801A66CC->dir[2].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[2], &lbl_801A66CC->aim[2]);

    lbl_8006D1B8((s16)(t2 - 0x4000), &v);
    lbl_801A66CC->dir[3].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[3].y = -fzgx_live_;
    lbl_801A66CC->dir[3].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[3], &lbl_801A66CC->aim[3]);
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_549F4 */

/* fzgx:begin fn_1_54DCC */
void fn_1_54DCC(u8 *data) {
    fn_800794F0(data, (u8 *)lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_54DCC */

/* fzgx:begin fn_1_54E00 */
void fn_1_54E00(void *value) {
    fn_800794F0((u8 *)lbl_801A66CC + 0x50, value, 0x84);
}
/* fzgx:end fn_1_54E00 */

/* fzgx:begin fn_1_54E34 */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
} Fn154E34Data;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector;



s32 fn_1_54E34(void *arg0, f32 arg1) {
    Vector vector;
    Fn154E34Data *data;
    f32 *p;
    f32 x;
    f32 y;
    f32 z;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    lbl_8006E1B0(arg0, (f32 *)&vector, arg1);
    z = vector.z;
    x = vector.x;
    y = vector.y;
    if (z > arg1) {
        return 0;
    }
    arg1 = -arg1;
    data = (Fn154E34Data *)(*(void * *)&lbl_801A66CC);
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = x * p[0];
        m1 = y * p[1];
        m2 = z * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54E34 */

/* fzgx:begin fn_1_54F5C */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
    u8 pad_bc[0x18];
    f32 value_d4;
    f32 value_d8;
    f32 value_dc;
} Fn154F5CData;



s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2) {
    Fn154F5CData *data;
    f32 *p;
    f32 d4;
    f32 d8;
    f32 dc;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    lbl_8006E1B0(arg0, (Vec3 *)(void *)(&data->value_d4));
    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    arg1 = arg1 * arg2;
    dc = data->value_dc;
    if (dc > arg1) {
        return 0;
    }
    d4 = data->value_d4;
    d8 = data->value_d8;
    arg1 = -arg1;
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = d4 * p[0];
        m1 = d8 * p[1];
        m2 = dc * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54F5C */

/* fzgx:begin fn_1_550A8 */
void fn_1_550A8(void) {
    fn_800794F0(lbl_1_bss_6C710, (u8 *)lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_550A8 */

/* fzgx:begin fn_1_550E0 */
void fn_1_550E0(void) {
    fn_800794F0((u8 *)lbl_801A66CC + 0x50, lbl_1_bss_6C710, 0x84);
}
/* fzgx:end fn_1_550E0 */

/* fzgx:begin fn_1_55118 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern u32 lbl_801A6410;
extern const f32 lbl_1_rodata_28A8;
extern void fn_800777D4(void);
extern void fn_1_565F8(void);
extern void fn_80072808(void);
extern void fn_1_56664(void *);
extern void fn_1_566A0(void *);
extern u32 fn_80070DE0(u32);
extern u32 fn_80070DF0(u32);
extern void *memset(void *, int, u32);
extern void fn_1_566EC(int, int);
extern void fn_800749B0(s32, void *);

typedef struct {
    u8 color[4];
    u8 shadow[4];
    f32 scale;
    u8 flags[6];
    u8 pad[0x16];
} InitSettings;
typedef struct {
    u32 initial;
    u32 count;
    f32 scale;
    InitSettings settings;
    u32 last;
} InitState;

static inline void init_settings(InitSettings *settings) {
    memset(settings, 0, 0x28);
    settings->color[0] = 255;
    settings->color[1] = 255;
    settings->color[2] = 255;
    settings->color[3] = 255;
    settings->shadow[0] = 0;
    settings->shadow[1] = 0;
    settings->shadow[2] = 0;
    settings->shadow[3] = 0;
    settings->scale = lbl_1_rodata_28A8;
    settings->flags[0] = 1;
    settings->flags[1] = 3;
    settings->flags[2] = 1;
    settings->flags[3] = 0;
    settings->flags[4] = 0;
    settings->flags[5] = 0;
}

typedef struct lbl_1_bss_6C7CC_t {
    u32 last;
    u8 pad_4[0xc];
} lbl_1_bss_6C7CC_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6C798;
u32 lbl_1_bss_6C79C;
f32 fzgx_obj_lbl_1_bss_6C7A0;
InitSettings fzgx_obj_lbl_1_bss_6C7A4;
lbl_1_bss_6C7CC_t fzgx_obj_lbl_1_bss_6C7CC;
u32 lbl_1_bss_6C7DC[25];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6C798;
    s = *(u8 *)&lbl_1_bss_6C79C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7CC;
    s = *(u8 *)&lbl_1_bss_6C7DC;
}
#pragma section code_type ".text"

void fn_1_55118(void) {
    
    InitSettings *settings;
    lbl_1_bss_6C798 = lbl_801A6410;
    fn_800777D4();
    fn_1_565F8();
    fn_80072808();
    fn_80070DE0((u32)fn_1_56664);
    fn_80070DF0((u32)fn_1_566A0);
    lbl_1_bss_6C79C = 0x60;
    fzgx_obj_lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    init_settings(&fzgx_obj_lbl_1_bss_6C7A4);
    fn_1_566EC(0, 0);
    fn_800749B0(0, 0);
    fzgx_obj_lbl_1_bss_6C7CC.last = 0;
}
/* fzgx:end fn_1_55118 */

/* fzgx:begin fn_1_55210 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_5448C(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_557C4(void *value);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_55210_Object;

static inline void * fn_1_55210_array_read(void * *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_1_55210(void *value) {
    s32 offset;
    Fn1_55210_Object *obj;
    void *result;
    s32 ok;
    s32 i;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if ((0) != (*(u16 *)((u8 *)value + 0x1a))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_5448C((u8 *)value + 8);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (fn_1_55210_array_read(obj->entry, i) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + (((offset)))) + (((0xe0)))))), fn_1_55210_array_read(obj->entry, i));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_557C4(value);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_55210 */

/* fzgx:begin fn_1_553C4 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_54448(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_55924(void *value, void *arg);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_553C4_Object;

static inline void * fn_1_553C4_array_read(void * *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_1_553C4(void *value, void *arg) {
    s32 offset;
    Fn1_553C4_Object *obj;
    void *result;
    s32 ok;
    s32 i;
    u32 bit;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if (((0) != (*(u16 *)((u8 *)value + 0x1a)))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_54448(arg);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (fn_1_553C4_array_read(obj->entry, i) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + (((offset)))) + (((0xe0)))))), fn_1_553C4_array_read(obj->entry, i));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_55924(value, arg);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_553C4 */

/* fzgx:begin fn_1_5557C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5557CObject;

void fn_1_5557C(Fn1_5557CObject *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5557C */

/* fzgx:begin fn_1_555D0 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_555D0Object;

void fn_1_555D0(Fn1_555D0Object *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_555D0 */

/* fzgx:begin fn_1_55628 */
typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Fn1_55628Object;

void fn_1_55628(Fn1_55628Object *value) {
    if (value->unk_1C != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        fn_1_557C4(value);
    } else {
        fn_1_556B8(value);
    }
}
/* fzgx:end fn_1_55628 */

/* fzgx:begin fn_1_55678 */
void fn_1_55678(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
    fn_80077E7C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_55678 */

/* fzgx:begin fn_1_556B8 */
/* Completes the font operation for the supplied value. */
void fn_1_556B8(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
    fn_80077F8C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_556B8 */

/* fzgx:begin fn_1_556F8 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_556F8Object;

/* Finishes the current font operation after testing its scale threshold. */
void fn_1_556F8(Fn1_556F8Object *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_556F8 */

/* fzgx:begin fn_1_5575C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5575CObject;

void fn_1_5575C(Fn1_5575CObject *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5575C */

/* fzgx:begin fn_1_557C4 */
typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1C;
    u32 w20;
    u32 w24;
} Words28;

typedef struct {
    u8 pad_00[4];
    u32 unk_04;
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *unk_68[4];
} Fn1_557C4Object;

#pragma opt_lifetimes off
void fn_1_557C4(void *value) {
    s32 offset;
    Fn1_557C4Object *object;
    void *resource;
    s32 valid;
    s32 i;
    u32 shift;
    u32 word;
    Obj_1_bss_6C7CC *bits;

    resource = (void *)fn_1_5448C((u8 *)value + 8);
    object = fn_1_548AC(0x78);
    if (object != 0) {
        valid = 1;
        object->unk_04 = (u32)fn_1_55C48;
        object->unk_08 = value;
        lbl_8006DB74(((0xC) + ((u8 *)object)));
        object->unk_3C = fn_1_7BE94();
        object->unk_40 = lbl_1_bss_6C7A4;
        bits = &lbl_1_bss_6C7CC;
        for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
            if ((__rlwnm(bits->unk_0, ((i + 1) & 0x1f), 31, 31) != 0)) {
                object->unk_68[i] = fn_1_548AC(0x30);
                if ((*((object->unk_68) + (i))) != 0) {
                    lbl_8006DD14(lbl_801A66CC + offset + 0xE0, (*((object->unk_68) + (i))));
                } else {
                    valid = 0;
                }
            } else {
                object->unk_68[i] = 0;
            }
        }
        if (valid != 0) {
            fn_1_5489C( (void **)(void *)(resource), (void **)(void *)(object));
        }
    }
    fn_1_56530();
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_557C4 */

/* fzgx:begin fn_1_55924 */
typedef struct {
    u8 pad_00[0x4];
    void *vtable;
    void *owner;
    u8 pad_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[0x2];
    Obj_1_bss_6C7A4 settings;
    void *items[4];
} Fn1_55924Object;

void fn_1_55924(void *value, void *arg) {
    Fn1_55924Object *object;
    void *handle;
    s32 ok;
    s32 i;
    Obj_1_bss_6C7CC *flags;

    handle = (void *)fn_1_54448( (s32)(void *)(arg));
    object = (Fn1_55924Object *)fn_1_548AC(0x78);
    if (object != 0) {
        object->vtable = (void *)fn_1_55C48;
        object->owner = value;
        ok = 1;
        lbl_8006DB74((u8 *)object + 0xC);
        object->unk_3C = fn_1_7BE94();
        object->settings = lbl_1_bss_6C7A4;
        flags = &lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (__rlwnm(flags->unk_0, (i + 1) & 31, 31, 31)) {
                object->items[i] = fn_1_548AC(0x30);
                if (object->items[i] != 0) {
                    lbl_8006DD14((((i * 0x30) + ((u8 *)lbl_801A66CC)) + (0xE0)), object->items[i]);
                } else {
                    ok = 0;
                }
            } else {
                object->items[i] = 0;
            }
        }
        if (ok != 0) {
            fn_1_5489C( (void **)(void *)(handle), (void **)(void *)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_55924 */

/* fzgx:begin fn_1_55A84 */
typedef struct {
    u8 pad_00[0x1c];
    u16 unk_1c;
} FontInput;

typedef struct {
    u8 pad_00[0x4];
    void (*destroy)(void);
    void *owner;
    u8 pad_0c[0x30];
    u16 unk_3c;
    u8 pad_3e[0x2];
    Obj_1_bss_6C7A4 settings;
    void *unk_68;
    u8 pad_6c[0xc];
    void *unk_78;
    void *unk_7c;
    void *unk_80;
} FontObject;

typedef void (*FontCallback)(void *, void *, void *);

void fn_1_55A84(FontCallback callback, FontInput *value, void *arg2, void *arg3) {
    u16 fzgx_value;
    FontObject *cursor;
    int offset;
    FontObject *object;
    void *data;
    int ok;
    int i;
    u32 shift;
    u32 *flags;

    if (value->unk_1c != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        data = (void *)fn_1_5448C((u8 *)value + 8);
        object = (FontObject *)fn_1_548AC(0x84);
        if (object != 0) {
            ok = 1;
            object->destroy = fn_1_55D6C;
            object->owner = value;
            lbl_8006DB74((u8 *)object + 0xc);
            fzgx_value = fn_1_7BE94();
            object->unk_3c = fzgx_value;
            object->settings = lbl_1_bss_6C7A4;
            i = 0;
            offset = 0;
            cursor = object;
            flags = (u32 *)&lbl_1_bss_6C7CC;
            while (i < 4) {
                shift = (i + 1) & 31;
                if ((__rlwnm(*flags, shift, 31, 31) != 0)) {
                    cursor->unk_68 = fn_1_548AC(0x30);
                    if (cursor->unk_68 != 0) {
                        lbl_8006DD14(lbl_801A66CC + offset + 0xe0, cursor->unk_68);
                    } else {
                        ok = 0;
                    }
                } else {
                    cursor->unk_68 = 0;
                }
                i++;
                cursor = (FontObject *)((u8 *)cursor + 4);
                offset += 0x30;
            }
            object->unk_78 = arg2;
            object->unk_7c = arg3;
            object->unk_80 = callback;
            if (ok != 0) {
                fn_1_5489C( (void **)(void *)(data), (void **)(void *)(object));
            }
        }
        fn_1_56530();
    } else {
        fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
        callback(value, arg2, arg3);
        fn_1_56530();
    }
}
/* fzgx:end fn_1_55A84 */

/* fzgx:begin fn_1_55C48 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern void fn_80077F8C(void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55C48Object;

#pragma opt_common_subs off
static inline void * fn_1_55C48_read_pointer(Fn1_55C48Object * owner) { return owner->unk_68; }
#pragma opt_common_subs reset

#pragma opt_propagation off
#pragma opt_pointer_analysis off
static inline void * fn_1_55C48_read_pointer_(Fn1_55C48Object * owner) { return owner->unk_08; }
#pragma opt_common_subs off
void fn_1_55C48(Fn1_55C48Object *value) {
    Fn1_55C48Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55C48Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != (fn_1_55C48_read_pointer(entry)))) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, fn_1_55C48_read_pointer(entry));
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55C48Object *)((u8 *)entry + 4);
        }
    }

    fn_80077F8C(fn_1_55C48_read_pointer_(value));
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55C48Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + (offset)));
            } else if (fn_1_55C48_read_pointer(entry_2) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_pointer_analysis reset

#pragma opt_propagation reset
/* fzgx:end fn_1_55C48 */

/* fzgx:begin fn_1_55D6C noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
    u8 unk_70[0xC];
    u32 unk_78;
    u32 unk_7C;
    void (*unk_80)(void *, u32, u32);
} Fn1_55D6CObject;

#pragma opt_common_subs off
static inline void * fn_1_55D6C_read_pointer(Fn1_55D6CObject * owner) { return owner->unk_68; }
#pragma opt_common_subs reset

#pragma opt_propagation off
#pragma opt_pointer_analysis off
static inline void * fn_1_55D6C_read_pointer_(Fn1_55D6CObject * owner) { return owner->unk_08; }
#pragma opt_common_subs off
void fn_1_55D6C(Fn1_55D6CObject *value) {
    Fn1_55D6CObject * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55D6CObject * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != (fn_1_55D6C_read_pointer(entry)))) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, fn_1_55D6C_read_pointer(entry));
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55D6CObject *)((u8 *)entry + 4);
        }
    }

    value->unk_80(fn_1_55D6C_read_pointer_(value), value->unk_78, value->unk_7C);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55D6CObject *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + (offset)));
            } else if (fn_1_55D6C_read_pointer(entry_2) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_pointer_analysis reset

#pragma opt_propagation reset
/* fzgx:end fn_1_55D6C */

/* fzgx:begin fn_1_55EA0 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern void fn_800781B8(void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55EA0Object;

#pragma opt_common_subs off
static inline void * fn_1_55EA0_read_pointer(Fn1_55EA0Object * owner) { return owner->unk_68; }
#pragma opt_common_subs reset

#pragma opt_propagation off
#pragma opt_pointer_analysis off
static inline void * fn_1_55EA0_read_pointer_(Fn1_55EA0Object * owner) { return owner->unk_08; }
#pragma opt_common_subs off
void fn_1_55EA0(Fn1_55EA0Object *value) {
    Fn1_55EA0Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55EA0Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != (fn_1_55EA0_read_pointer(entry)))) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, fn_1_55EA0_read_pointer(entry));
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55EA0Object *)((u8 *)entry + 4);
        }
    }

    fn_800781B8(fn_1_55EA0_read_pointer_(value));
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55EA0Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + (offset)));
            } else if (fn_1_55EA0_read_pointer(entry_2) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_pointer_analysis reset

#pragma opt_propagation reset
/* fzgx:end fn_1_55EA0 */

/* fzgx:begin fn_1_55FC4 */
void fn_1_55FC4(f32 value) {
    lbl_1_bss_6C7A0 = value;
}
/* fzgx:end fn_1_55FC4 */

/* fzgx:begin fn_1_55FD0 */
void fn_1_55FD0(void) {
    fn_80074CF4();
}
/* fzgx:end fn_1_55FD0 */

/* fzgx:begin fn_1_55FF0 */
void fn_1_55FF0(f32 value) {
    lbl_1_bss_6C7A4.unk_8 = value;
}
/* fzgx:end fn_1_55FF0 */

/* fzgx:begin fn_1_56000 */
void fn_1_56000(u8 value0, u8 value1, u8 value2) {
    lbl_1_bss_6C7A4.unk_C = value0;
    lbl_1_bss_6C7A4.unk_D = value1;
    lbl_1_bss_6C7A4.unk_E = value2;
}
/* fzgx:end fn_1_56000 */

/* fzgx:begin fn_1_56018 */
u32 fn_1_56018(s32 value) {
    s32 i;
    u32 result;

    result = (u32)((-(s32)lbl_1_bss_6C7CC.unk_0 | lbl_1_bss_6C7CC.unk_0) >> 31);
    if (value == 0) {
        for (i = 0; i < 4; i++) {
            if (__rlwnm((s32)lbl_1_bss_6C7CC.unk_0, (i + 1) & 31, 31, 31)) {
                fn_800749B0(0, (void *)0);
            }
        }
        lbl_1_bss_6C7CC.unk_0 = 0;
    } else {
        for (i = 0; i < 4; i++) {
            if (__rlwnm((s32)lbl_1_bss_6C7CC.unk_0, (i + 1) & 31, 31, 31)) {
                fn_800749B0(i, (void *)((u8 *)*(void **)&(*(void * *)&lbl_801A66CC) + i * 0x30 + 0xe0));
            }
        }
    }
    return result;
}
/* fzgx:end fn_1_56018 */

/* fzgx:begin fn_1_560F0 */
// Marks the selected font resource as active before handing it to the loader.
void fn_1_560F0(s32 index, void *arg) {
    if (arg != NULL) {
        lbl_1_bss_6C7CC.unk_0 |= (1u << 31) >> index;
        lbl_8006DD14(arg, lbl_801A66CC + index * 0x30 + 0xe0);
    }
    fn_800749B0(index, arg);
}
/* fzgx:end fn_1_560F0 */

/* fzgx:begin fn_1_5616C */
/* 0x30-byte slot in the table lbl_801A66CC points at */
typedef struct {
    f32 unk_0[12];
} FontSlot;

void fn_1_5616C(s32 value, f32 value1, f32 value2) {
    lbl_1_bss_6C7CC.unk_0 |= ((u32)1 << 31) >> value;

    lbl_8006D784(&(*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x38]);

    (*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x3b] = value1;
    (*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x3f] = value2;

    fn_800749B0(value, &(*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x38]);
}
/* fzgx:end fn_1_5616C */

/* fzgx:begin fn_1_5621C */
void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3) {
    ((u8 *)&lbl_1_bss_6C7A4)[0] = (u8)(lbl_1_rodata_28AC * value0);
    ((u8 *)&lbl_1_bss_6C7A4)[1] = (u8)(lbl_1_rodata_28AC * value1);
    ((u8 *)&lbl_1_bss_6C7A4)[2] = (u8)(lbl_1_rodata_28AC * value2);
    ((u8 *)&lbl_1_bss_6C7A4)[3] = (u8)(lbl_1_rodata_28AC * value3);
    fn_80074B40((u8 *)&lbl_1_bss_6C7A4);
}
/* fzgx:end fn_1_5621C */

/* fzgx:begin fn_1_56298 */
void fn_1_56298(f32 value0, f32 value1, f32 value2, f32 value3) {
    f32 scale = lbl_1_rodata_28AC;

    lbl_1_bss_6C7A4.unk_4 = (u8)(scale * value0);
    lbl_1_bss_6C7A4.unk_5 = (u8)(scale * value1);
    lbl_1_bss_6C7A4.unk_6 = (u8)(scale * value2);
    lbl_1_bss_6C7A4.unk_7 = (u8)(scale * value3);
    fn_80074C74(&lbl_1_bss_6C7A4.unk_4);
}
/* fzgx:end fn_1_56298 */

/* fzgx:begin fn_1_5631C */
void fn_1_5631C(const u32 *value) {
    Obj_1_bss_6C7A4 *state = &lbl_1_bss_6C7A4;

    // Store the incoming value in the shared font state before notifying the subsystem.
    *(volatile u32 *)&state->unk_4 = *value;
    fn_80074C74((u8 *)value);
}
/* fzgx:end fn_1_5631C */

/* fzgx:begin fn_1_5634C */
void fn_1_5634C(u8 value) {
    lbl_1_bss_6C7A4.unk_12 = value;
}
/* fzgx:end fn_1_5634C */

/* fzgx:begin fn_1_5635C */
void fn_1_5635C(u8 value, f32 value2, f32 value3) {
    lbl_1_bss_6C7A4.unk_13 = value;
    *(f32 *)&lbl_1_bss_6C7A4.unk_18 = value2;
    *(f32 *)&lbl_1_bss_6C7A4.unk_1C = value3;
}
/* fzgx:end fn_1_5635C */

/* fzgx:begin fn_1_56374 */
void fn_1_56374(u8 value1, u8 value2, u8 value3) {
    lbl_1_bss_6C7A4.unk_14 = value1;
    lbl_1_bss_6C7A4.unk_15 = value2;
    lbl_1_bss_6C7A4.unk_16 = value3;
}
/* fzgx:end fn_1_56374 */

/* fzgx:begin fn_1_5638C */
// Stores the current value for the font subsystem and refreshes its state.
void fn_1_5638C(u32 value) {
    lbl_1_bss_6C7A4.unk_20 = value;
    fn_80074A7C();
}
/* fzgx:end fn_1_5638C */

/* fzgx:begin fn_1_563B8 */
void fn_1_563B8(u32 value) {
    lbl_1_bss_6C7A4.unk_24 = value;
    fn_80077BAC();
}
/* fzgx:end fn_1_563B8 */

/* fzgx:begin fn_1_563E4 */
void fn_1_563E4(fn_1_563E4_FontState *font) {
    u32 value;
    u32 lab_t0;
    u32 lab_t2;

    fn_80077B04(font->scale);
    lab_t0 = font->pad_0C[0];
    lab_t2 = font->pad_0C[2];
    fn_80074918(lab_t0, font->pad_0C[1], lab_t2);
    if (font->state == 0) {
        if (font->enabled != 0) {
            fn_80071ED4(font->color, font->x, font->y);
            value = font->value;
            fn_80072014(&value);
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_563E4 */

/* fzgx:begin fn_1_56470 */
typedef struct fn_1_56470_FontState {
    u8 unk_00[4];
    void *unk_04;
    f32 unk_08;
    s8 unk_0C;
    u8 unk_0D;
    s8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
    u32 unk_24;
} fn_1_56470_FontState;


void fn_1_56470(fn_1_56470_FontState *state) {
    u32 value;

    fn_80077B04( state->unk_08);
    fn_80074B40( (u8 *)(fn_1_56470_FontState *)(state));
    fn_80074C74( (u8 *)(void *)(&state->unk_04));
    fn_80074918(state->unk_0C, state->unk_0D, state->unk_0E);
    fn_80077BBC(state->unk_0F);
    fn_80037D40(state->unk_10, state->unk_11);
    fn_80074A7C(state->unk_20);
    fn_80077BAC(state->unk_24);
    if (state->unk_24 == 0) {
        if (state->unk_12 != 0) {
            fn_80071ED4(state->unk_13, state->unk_18, state->unk_1C);
            value = state->unk_14;
            fn_80072014( (u32 *)(void *)(&value));
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_56470 */

/* fzgx:begin fn_1_56530 */
void fn_1_56530(void) {
    lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    lbl_1_bss_6C7A4.unk_8 = lbl_1_rodata_28A8;
}
/* fzgx:end fn_1_56530 */

/* fzgx:begin fn_1_56554 */
void fn_1_56554(void) {
    u32 lab_t0;
    u32 lab_t2;
    Obj_1_bss_6C7A4 *font = &lbl_1_bss_6C7A4;

    fn_80074B40( (u8 *)(void *)(font));
    fn_80074C74( (u8 *)(void *)(&font->unk_4));
    lab_t0 = font->unk_C;
    lab_t2 = font->unk_E;
    fn_80074918(lab_t0, font->unk_D, lab_t2);
    fn_80077BBC(font->unk_F);
    fn_80037D40(font->unk_10, font->unk_11);
    fn_80074A7C(font->unk_20);
    fn_80077BAC(font->unk_24);
}
/* fzgx:end fn_1_56554 */

/* fzgx:begin fn_1_565E8 */
// Return the font data buffer used by the font subsystem.
u8 *fn_1_565E8(void) {
    return lbl_1_bss_6C7DC;
}
/* fzgx:end fn_1_565E8 */

/* fzgx:begin fn_1_565F4 */
// fn_1_565F4: empty in retail (single blr).
void fn_1_565F4(void) {
}
/* fzgx:end fn_1_565F4 */

/* fzgx:begin fn_1_565F8 */
// Registers the font initialization callbacks with the shared dispatcher.
void fn_1_565F8(void) {
    void (*callbacks[6])(void);

    callbacks[0] = (void (*)(void))fn_1_565E8;
    callbacks[1] = fn_1_45730;
    callbacks[2] = fn_1_45B2C;
    callbacks[3] = fn_1_458A0;
    callbacks[4] = fn_1_45850;
    callbacks[5] = fn_1_565F4;
    fn_80070D60(callbacks);
}
/* fzgx:end fn_1_565F8 */
