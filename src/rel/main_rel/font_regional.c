/* Retained Japan/PAL compiler inputs pending a verified whole-TU regional build. */
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
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void OSReport(const char *format, ...);
extern f32 fn_1_4B1D4(s32 mode, u8 *text);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern f32 lbl_1_rodata_26F8[22];
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);

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
    result1 = entry->unk_34 * (value1 * entry->unk_4);
    result2 = entry->unk_34 * (value2 * entry->unk_5);
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
    int x_ok;
    int y_ok;

    if (lbl_1_bss_4B9CC.unk_45 != 0) {
        local.x = fn_1_519FC(local.x);
        local.y = fn_1_51AC0(local.y);
        local.z = fn_1_51B84(local.z);
        local.w = fn_1_51BFC(local.w);
    }

    if (lbl_1_bss_4B9CC.unk_47 != 0) {
        x_ok = (local.x > (lbl_1_bss_4B9CC.unk_48 + lbl_1_bss_4B9CC.unk_4C))
                   ? 0
                   : ((local.x < lbl_1_bss_4B9CC.unk_48) ? 0 : 1);
        if (x_ok == 0 ||
            (y_ok = (local.y > (lbl_1_bss_4B9CC.unk_4A + lbl_1_bss_4B9CC.unk_4E))
                        ? 0
                        : ((local.y < lbl_1_bss_4B9CC.unk_4A) ? 0 : 1)) == 0) {
            return;
        }
    }

    if (lbl_1_bss_4B9CC.unk_44 != 0) {
        fn_1_4F734( (FontDrawPacket *)(&local));
    } else if ((local.flag & 0x400000) != 0) {
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E500();
        }
        fn_1_48D80(&local);
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E6F4();
        }
    } else {
        fn_1_4E724( (FontParams *)(&local));
    }
}
/* fzgx:end fn_1_4AC20 */

/* fzgx:begin fn_1_4AE0C */
void fn_1_4AE0C(const char* format, ...) {
    char buffer[512];
    __va_list args;
    __builtin_va_info(&args);
    fn_8008077C( (u32)(buffer), (u32)(format), (u32)(args));
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

/* fzgx:begin fn_1_4AEE8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern void fn_1_48214(int index, int enabled);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern s32 lbl_801A6410;
extern void OSPanic(const unsigned char *, ...);
extern int fn_1_45D0(int, int, const unsigned char *, int);
extern int fn_80008F88(int, int);
extern void fn_8006FDEC(void);
extern void fn_80009064(u32 value);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, s32 arg3);
extern void *fn_1_48730(u32 value);
extern void fn_1_47AD4(BitmapResource *obj, u8 value, int arg2, int arg3);
extern f32 lbl_1_rodata_10C0[5];
extern f32 lbl_1_bss_3E05C;

extern void *fn_1_48730(u32 value);

u32 fn_1_4AEE8(u32 value) {
    u32 previous = lbl_1_data_1BCC4;

    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    lbl_1_data_1BCC4 = value;

    return previous;
}
/* fzgx:end fn_1_4AEE8 */

/* fzgx:begin fn_1_4AF10 */
struct fn_1_4AF10_lbl_1_bss_3E058 {
    u32 unk_0;
};






void fn_1_4AF10(u32 arg0) {
    u32 v0;
    v0 = (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0;
    lbl_1_bss_3E05C = (0.0f);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = 1;
    fn_1_4A0D8((const char *)arg0);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = v0;
}
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
    fn_8008077C( (u32)(buffer), (u32)(format), (u32)(va_list *)(&args));

    lbl_1_bss_3E058 = 1;
    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    fn_1_4A0D8(buffer);
    lbl_1_bss_3E058 = previous;
}
/* fzgx:end fn_1_4AF64 */

/* fzgx:begin fn_1_4B040 */
void fn_1_4B040(s32 value) {
    fn_1_4B1D4(0, (u8 *)value);
}
/* fzgx:end fn_1_4B040 */

/* fzgx:begin fn_1_4B068 */
void fn_1_4B068(s32 value) {
    fn_1_4B1D4(1, (u8 *)value);
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
        (entry->unk_34 * (entry->unk_5 * fn_1_4B16C(value)));
    b = lbl_1_bss_4B9CC.unk_40 * count;
    return a + b;
}
/* fzgx:end fn_1_4B090 */

/* fzgx:begin fn_1_4B16C */
s32 fn_1_4B16C(s32 value) {
    return fn_1_4B1D4(2, (u8 *)value);
}
/* fzgx:end fn_1_4B16C */

/* fzgx:begin fn_1_4B1A0 */
s32 fn_1_4B1A0(s32 value) {
    return fn_1_4B1D4(3, (u8 *)value);
}
/* fzgx:end fn_1_4B1A0 */

/* fzgx:begin fn_1_4B1D4 */
typedef struct FontEntry_4B1D4 {
    s32 unk_0;
    u8 pad_4[0x30];
    f32 unk_34;
} FontEntry_4B1D4;

extern s32 lbl_1_bss_4BA28[2];

f32 fn_1_4B1D4(s32 mode, u8 *str) {
    Obj_1_bss_4B9CC * p;
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
    p = &lbl_1_bss_4B9CC;
    maxWidth = 0.0f;
    width = -p->unk_3C;
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
                            width = -p->unk_3C;
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
                        width = -p->unk_3C;
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
            width += p->unk_3C + (f32)(state->unk_1C * (adv * font->unk_34));
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
        return lines;
    case 3:
        return count;
    case 4:
        return maxCount;
    default:
        return -1.0f;
    }
}
/* fzgx:end fn_1_4B1D4 */

/* fzgx:begin fn_1_4BD4C */
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

    prev_unk_0 = *(s8 *)&sp30->unk_0;
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
            fn_1_48140((((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_1].unk_0 >> 8) & 0xFFFF);
            fn_1_47F74((elem->unk_0 >> 8) & 0xFFFF);
        }
        sp30->unk_1 = sp30->unk_0;
    }

    if (elem->unk_0 == -1) {
        page_size = cols * rows;
        prev_unk_4 = sp30->unk_4;
        max_page = ((s32 *)&lbl_1_bss_40BBC)[sp30->unk_0] / page_size;
        if (((p_d58[8] >> 2) & 1) != 0) {
            if ((s8)++sp30->unk_4 > max_page) {
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
