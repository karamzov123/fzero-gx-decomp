/* Compile settings (units.json): GC/2.5 with -fp_contract off. The flag is this TU's measured setting, not
 * per-function steering: with contraction on, fn_1_530C8 and fn_1_539CC fuse multiply-adds that retail does
 * not have (289 and 80 words off), and no function of the TU needs it on. font.c shows the same in five
 * functions (fn_1_492F0, fn_1_4A0D8, fn_1_4B6D4, fn_1_4B788, fn_1_4C16C). */
#include "types.h"
#include "dolphin/types.h"
#define lbl_1_bss_4C688 globals_h_lbl_1_bss_4C688
#include "rel/main_rel/globals.h"
#undef lbl_1_bss_4C688
#include "runtime/va_list.h"
#include "font.h"
#include "game/vec3.h"
#include "dolphin/hw_regs.h"
#include "rel/main_rel/bitmap_resource.h"
#include "psvec_fill.h"

typedef struct FontColor {
    u8 r, g, b, a;
} FontColor;

/* fn_1_487EC */
typedef struct { u32 dummy[8]; } GXTexObj;

/* fn_1_48C28 */
typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

/* fn_1_48C28 */
typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

/* fn_1_48C28 */
typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

/* fn_1_48D80 */
typedef struct fn_1_48D80_Sprite {
    u32 id;
    f32 x;
    f32 y;
    f32 z;
    f32 scaleX;
    f32 scaleY;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    s16 rot;
    u8 pad_2A[2];
    f32 alpha;
    u32 flags;
    f32 offsetX;
    FontColor color;
    FontColor addColor;
    u8 pad_40[0x10];
    void (*draw)(struct fn_1_48D80_Sprite *, Vec3 *);
} fn_1_48D80_Sprite;

/* fn_1_492F0 */
typedef struct ShapeParams {
    u32 flags;
    u8 pad[12];
    f32 width;
    f32 height;
} ShapeParams;

/* fn_1_4D10C */
typedef struct fn_1_547F8_node_fn_1_4D10C {
    struct fn_1_547F8_node_fn_1_4D10C *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_4D10C *);
} fn_1_547F8_node_fn_1_4D10C;

/* sprite object, .bss 4C688[64] */
typedef struct Sprite {
    s32 active;
    u8 unk_4;
    u16 unk_6;
    FontDrawPacket packet;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    void (*update)(struct Sprite *);
    void (*draw)(struct Sprite *);
} Sprite;

/* fn_1_4E220 */
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

/* fn_1_4E220 */
typedef enum {
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,
    GX_MAX_TEXWRAPMODE,
} GXTexWrapMode;

/* fn_1_4E220 */
typedef struct {
    f32 m[12];
} Mtx;

/* fn_1_4E220 */
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

/* fn_1_4EDAC */
typedef struct DrawFields {
    u32 id;
    f32 x, y, depth;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 angle_z, angle_y;
    f32 alpha;
    u32 flags;
    f32 pivot;
    FontColor color, add_color;
    s32 format;
    u16 width, height;
    u32 image;
    FontDrawPacket *texture;
    void (*callback)(FontDrawPacket *, Vec3 *);
} DrawFields;

/* fn_1_4FC50 */
typedef struct {
    u32 unk_0;
} InputObject;

/* fn_1_50190 */
struct Pkt88 { u32 words[22]; };

/* fn_1_508C4 */
typedef struct fn_1_508C4_FontObject {
    u32 unk0;
    f32 start_x;
    f32 start_y;
    f32 pos_x;
    f32 scale_x;
    f32 scale_y;
    u8 data[0x40];
} fn_1_508C4_FontObject;

/* fn_1_508C4 */
struct fn_1_50A90_Copy88 { u32 a[22]; };

/* fn_1_51914 */
typedef struct {
    u32 words[22];
} fn_1_51914_state;

/* fn_1_519FC */
typedef struct {
    u8 pad0[0xc];
    f32 x;
    f32 y;
    u8 pad1[4];
    f32 z;
    f32 w;
} fn_1_51C74_FontData;

/* fn_1_519FC */
typedef struct fn_1_547F8_node_fn_1_51E60 {
    struct fn_1_547F8_node_fn_1_51E60 *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_51E60 *);
} fn_1_547F8_node_fn_1_51E60;

/* fn_1_519FC */
struct fn_1_52250_Arg0 {
    u8 pad_0[0x54];
    f32 unk_54;
};

/* fn_1_519FC */
struct fn_1_52250_Arg1 {
    f32 unk_0;
    u8 pad_4[0x8];
    f32 unk_C;
};

/* fn_1_5233C */
typedef struct fn_1_547F8_node_fn_1_5233C {
    struct fn_1_547F8_node_fn_1_5233C *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_5233C *);
} fn_1_547F8_node_fn_1_5233C;

/* fn_1_5233C */
struct fn_1_5233C_Copy88 { u32 a[22]; };

/* fn_1_5233C */
struct ShadowEntry { FontColor color; f32 x, y; };

/* fn_1_52718 */
typedef struct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x4];
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x10];
    s16 unk_28;
} FontState_52718;

/* fn_1_52968 */
typedef struct fn_1_547F8_node_fn_1_535A0 {
    struct fn_1_547F8_node_fn_1_535A0 *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_535A0 *);
} fn_1_547F8_node_fn_1_535A0;

/* fn_1_53B14 */
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

/* fn_1_53BD8 */
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

/* fn_1_53C9C */
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

/* fn_1_53E40 */
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

/* fn_1_53FE4 */
typedef struct {
    u32 p;
    u8 pad[0xC];
    f32 f10, f14, f18, f1c, f20, f24;
} Fn53Obj;

/* fn_1_55210 */
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

extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);
extern u32 __cvt_fp2unsigned(f32);
extern int fn_1_159588(int arg);
extern s32 fn_1_3F164(void);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern s32 fn_1_486F8(u32);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4();
extern s32 fn_1_A6F1C(void);
extern f32 fn_1_A6FE8(void);
extern void fn_1_A71CC(void);
extern void fn_1_A722C(void);
extern void *fn_80008BA8(void *, const void *, u32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800371F8(u32, FontColor);
extern void fn_80038F10(f32* out);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_800737E4(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern int fn_8008077C(char *buf, const char *format, __va_list args);
extern f32 lbl_8006D188(s16);
extern void lbl_8006D758(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(Vec3 *, Vec3 *);
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern u8 *lbl_801A66CC;
extern u8 *lbl_801A6D00;
extern u32 mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s16);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));

void fn_1_48D80(FontDrawPacket *packet);
void fn_1_492F0(ShapeParams *arg, f32 out[4][3]);
void fn_1_4954C(f32 value);
void fn_1_4955C(f32 value1, f32 value2);
void fn_1_495C8(u8 value);
void fn_1_496FC(f32 value1, f32 value2);
void fn_1_49738(u32 value);
f32 fn_1_4B068(const char *text);
f32 fn_1_4B090(const char *text);
f32 *fn_1_4DCD0(void);
f32 *fn_1_4DCE0(void);
f32 *fn_1_4DCF0(void);
f32 *fn_1_4DD00(void);
f32 *fn_1_4DD10(void);
s16 *fn_1_4DD20(void);
f32 *fn_1_4DD30(void);
u8 *fn_1_4DD40(void);
u8 *fn_1_4DD50(void);
u8 *fn_1_4DD60(void);
u8 *fn_1_4DD70(void);
u8 *fn_1_4DD80(void);
u8 *fn_1_4DD90(void);
u16 *fn_1_4DDA0(void);
u32 *fn_1_4DDB0(void);
void fn_1_4DDC0(void);
Sprite *fn_1_4DE04(void);
void fn_1_4DE44(void);
void fn_1_4DEC0(void);
Sprite *fn_1_4DF60(void);
void fn_1_4E060(void);
int fn_1_4E0A4(u16 *left, u16 *right);
void fn_1_4E0F4(void);
void fn_1_4E220(FontDrawPacket *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
void fn_1_4E500(void);
void fn_1_4E638(s32 arg);
void fn_1_4E6F4(void);
s32 fn_1_4E724(FontDrawPacket *arg);
s32 fn_1_4E92C(const FontDrawPacket *src, u32 format, s16 width, s16 height, void *pixels);
s32 fn_1_4EB74(const FontDrawPacket *self);
s32 fn_1_4EC74(const FontDrawPacket *packet);
void fn_1_4F724(void);
s32 fn_1_4FC50(const FontDrawPacket *obj, u32 format, u16 width, u16 height, void *pixels);
void fn_1_4FD64(f32 arg0);
void fn_1_50164(FontDrawPacket *packet, f32 width, f32 height, f32 a, f32 b);
void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5);
void fn_1_508C4(fn_1_508C4_FontObject *obj, f32 dx, f32 dy);
void fn_1_50A90(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y);
void fn_1_51914(const FontDrawPacket *src);
void fn_1_51990(FontDrawPacket *packet);
f32 fn_1_519AC(u32 format);
f32 fn_1_519FC(f32 x);
f32 fn_1_51AC0(f32 y);
f32 fn_1_51B84(f32 w);
f32 fn_1_51BFC(f32 h);
void fn_1_51C74(fn_1_51C74_FontData *obj);
void fn_1_51E60(FontDrawPacket *src);
void fn_1_52070(u32 value);
void fn_1_52088(void);
void fn_1_520A0(void);
void fn_1_520CC(void);
f32 fn_1_520F8(s32 value);
f32 fn_1_521B8(s32 value);
void fn_1_52250(struct fn_1_52250_Arg0 *arg0, struct fn_1_52250_Arg1 *arg1);
void fn_1_52270(const FontDrawPacket *packet);
void fn_1_5233C(void *arg0, void *arg1);
void fn_1_52690(const FontDrawPacket *packet);
void fn_1_52718(const FontDrawPacket *packet);
void fn_1_527B4(void);
void fn_1_52968(s32 x, s32 y, f32 depth, const char *format, ...);
void fn_1_52B68(void *arg0, void *arg1);
void fn_1_52B8C(void *arg0, void *arg1);
void fn_1_52BB0(void *arg0, void *arg1);
void fn_1_52BD4(void *arg0, void *arg1);
void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
void fn_1_530C8(void * arg0);
void fn_1_535A0(FontColor color, f32 x, f32 y, f32 z, f32 width, f32 height, f32 thickness);
void fn_1_53830(u32 period, f32 x, u8 val, volatile u8 *a, volatile u8 *b); /* volatile: carried device, see the definition */
FontColor fn_1_539CC(const FontColor *a, const FontColor *b, f32 t);
void fn_1_53B14(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e);
void fn_1_53BD8(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e);
void fn_1_53C9C(u8 *color, const char *id, f32 x, f32 y, f32 z, f32 s, f32 t);
void fn_1_53E40(u8 *color, const char *name, f32 x, f32 y, f32 z, f32 w, f32 h);
void fn_1_53FE4(Fn53Obj *arg, u8 idx);
char *fn_1_5415C(u32 number, s32 column);
char *fn_1_5417C(u32 number);
char *fn_1_541A8(u32 number, s32 column);
void fn_1_54278(s32 arg0, s32 arg1);
void fn_1_5428C(f32 value);
s32 fn_1_54298(void);
s32 fn_1_542A8(void);
f32 fn_1_542B8(void);

/* TU B (sprite.c) .bss */
FontDrawPacket *lbl_1_bss_4C678 = NULL;
s32 lbl_1_bss_4C67C = 0;
s32 lbl_1_bss_4C680 = 0;
s32 lbl_1_bss_4C684 = 0;
Sprite lbl_1_bss_4C688[64];
GXTexObj lbl_1_bss_4E688;
s32 lbl_1_bss_4E6A8;
s32 lbl_1_bss_4E6AC;
GXTexObj lbl_1_bss_4E6B0;
s16 lbl_1_bss_646D4;
s16 lbl_1_bss_646D6;
s16 lbl_1_bss_646D8;
s16 lbl_1_bss_646DA;
s16 lbl_1_bss_646DC;
s16 lbl_1_bss_646DE;
s32 lbl_1_bss_646E0;
s32 lbl_1_bss_646E4;
GXTexObj lbl_1_bss_646E8;
extern FontDrawPacket *lbl_1_data_1C504;

/* TU B .rodata: the default sprite packet */
const FontDrawPacket lbl_1_rodata_26F8 = {
    0, 0.0f, 0.0f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0, 0, 1.0f, 5, 0.0f,
    {0xFF, 0xFF, 0xFF, 0xFF}, {0, 0, 0, 0},
};

/* fzgx:begin fn_1_4DCD0 */
/* accessors of the first sprite object's packet fields */

f32 *fn_1_4DCD0(void) {
    return &lbl_1_bss_4C688[0].packet.x;
}
/* fzgx:end fn_1_4DCD0 */

/* fzgx:begin fn_1_4DCE0 */
f32 *fn_1_4DCE0(void) {
    return &lbl_1_bss_4C688[0].packet.y;
}
/* fzgx:end fn_1_4DCE0 */

/* fzgx:begin fn_1_4DCF0 */
f32 *fn_1_4DCF0(void) {
    return &lbl_1_bss_4C688[0].packet.z;
}
/* fzgx:end fn_1_4DCF0 */

/* fzgx:begin fn_1_4DD00 */
f32 *fn_1_4DD00(void) {
    return &lbl_1_bss_4C688[0].packet.scale_x;
}
/* fzgx:end fn_1_4DD00 */

/* fzgx:begin fn_1_4DD10 */
f32 *fn_1_4DD10(void) {
    return &lbl_1_bss_4C688[0].packet.scale_y;
}
/* fzgx:end fn_1_4DD10 */

/* fzgx:begin fn_1_4DD20 */
s16 *fn_1_4DD20(void) {
    return &lbl_1_bss_4C688[0].packet.rotation_z;
}
/* fzgx:end fn_1_4DD20 */

/* fzgx:begin fn_1_4DD30 */
f32 *fn_1_4DD30(void) {
    return &lbl_1_bss_4C688[0].packet.alpha;
}
/* fzgx:end fn_1_4DD30 */

/* fzgx:begin fn_1_4DD40 */
u8 *fn_1_4DD40(void) {
    return &lbl_1_bss_4C688[0].packet.color[0];
}
/* fzgx:end fn_1_4DD40 */

/* fzgx:begin fn_1_4DD50 */
u8 *fn_1_4DD50(void) {
    return &lbl_1_bss_4C688[0].packet.color[1];
}
/* fzgx:end fn_1_4DD50 */

/* fzgx:begin fn_1_4DD60 */
u8 *fn_1_4DD60(void) {
    return &lbl_1_bss_4C688[0].packet.color[2];
}
/* fzgx:end fn_1_4DD60 */

/* fzgx:begin fn_1_4DD70 */
u8 *fn_1_4DD70(void) {
    return &lbl_1_bss_4C688[0].packet.color_add[0];
}
/* fzgx:end fn_1_4DD70 */

/* fzgx:begin fn_1_4DD80 */
u8 *fn_1_4DD80(void) {
    return &lbl_1_bss_4C688[0].packet.color_add[1];
}
/* fzgx:end fn_1_4DD80 */

/* fzgx:begin fn_1_4DD90 */
u8 *fn_1_4DD90(void) {
    return &lbl_1_bss_4C688[0].packet.color_add[2];
}
/* fzgx:end fn_1_4DD90 */

/* fzgx:begin fn_1_4DDA0 */
u16 *fn_1_4DDA0(void) {
    return &lbl_1_bss_4C688[0].unk_6;
}
/* fzgx:end fn_1_4DDA0 */

/* fzgx:begin fn_1_4DDB0 */
u32 *fn_1_4DDB0(void) {
    return &lbl_1_bss_4C688[0].unk_60;
}
/* fzgx:end fn_1_4DDB0 */

/* fzgx:begin fn_1_4DDC0 */
void fn_1_4DDC0(void) {
    Sprite *sprite = lbl_1_bss_4C688;
    s32 i;

    for (i = 0; i < 64; i++, sprite++) {
        sprite->active = 0;
    }
}
/* fzgx:end fn_1_4DDC0 */

/* fzgx:begin fn_1_4DE04 */
Sprite *fn_1_4DE04(void) {
    Sprite *sprite = lbl_1_bss_4C688;
    s32 i;

    for (i = 0; i < 64; i++, sprite++) {
        sprite->active = 0;
    }
    return sprite;
}
/* fzgx:end fn_1_4DE04 */

/* fzgx:begin fn_1_4DE44 */
void fn_1_4DE44(void) {
    int i;
    Sprite *sprite;

    if (fn_1_3F164() == 0) {
        sprite = lbl_1_bss_4C688;
        for (i = 0; i < 64; i++, sprite++) {
            if (sprite->active != 0 && sprite->update != NULL) {
                sprite->update(sprite);
            }
        }
    }
}
/* fzgx:end fn_1_4DE44 */

/* fzgx:begin fn_1_4DEC0 */
void fn_1_4DEC0(void) {
    FontDrawPacket packet;
    void (*draw)(Sprite *);
    s32 i;
    Sprite *sprite;

    i = 0;
    sprite = lbl_1_bss_4C688;
    do {
        if (sprite->active != 0) {
            draw = sprite->draw;
            if (draw == NULL) {
                packet = sprite->packet;
                fn_1_4F734(&packet);
            } else {
                draw(sprite);
            }
        }
        i += 1;
        sprite++;
    } while (i < 64);
}
/* fzgx:end fn_1_4DEC0 */

/* fzgx:begin fn_1_4DF60 */
Sprite *fn_1_4DF60(void) {
    int i;
    Sprite *sprite;

    sprite = lbl_1_bss_4C688;
    for (i = 0; i < 64; i++, sprite++) {
        if (sprite->active == 0) {
            break;
        }
    }

    if (sprite->active != 0) {
        return NULL;
    }

    sprite->active = 1;
    sprite->packet = lbl_1_rodata_26F8;
    sprite->unk_6 = 0;
    sprite->unk_68 = 0;
    sprite->unk_64 = 0;
    sprite->unk_60 = 0;
    sprite->unk_74 = 0.0f;
    sprite->unk_70 = 0.0f;
    sprite->unk_6C = 0.0f;
    sprite->draw = NULL;
    sprite->update = NULL;
    sprite->unk_4 = 0;
    return sprite;
}
/* fzgx:end fn_1_4DF60 */

/* fzgx:begin fn_1_4E060 */
void fn_1_4E060(void) {
    Sprite *sprite = lbl_1_bss_4C688;
    u32 i;

    for (i = 0; i < 64; i++, sprite++) {
        sprite->active = 0;
    }
}
/* fzgx:end fn_1_4E060 */

/* fzgx:begin fn_1_4E0A4 */
int fn_1_4E0A4(u16 *left, u16 *right) {
    u16 left_index;
    FontDrawPacket *packets;
    u16 right_index;
    f32 left_value;
    f32 right_value;

    left_index = *left;
    packets = lbl_1_data_1C504;
    right_index = *right;

    left_value = packets[left_index].z;
    right_value = packets[right_index].z;
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

/* fzgx:begin fn_1_4E220 */
void fn_1_4E220(FontDrawPacket *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    Mtx mtx;
    u32 v1;
    s32 v2;
    u32 image;
    BitmapImages *images;
    u32 v7;
    f32 size;
    f32 width;
    f32 height;

    lbl_8006D7F4(arg0->x, arg0->y, 0.0f);
    lbl_8006E15C(arg0->scale_x, arg0->scale_y, 1.0f);
    if (arg0->rotation_z != 0) {
        mathutil_mtxA_rotate_z(arg0->rotation_z);
    }
    lbl_8006DD7C();
    lbl_8006DB74(&mtx);
    v1 = arg2 & 0xFF;
    v2 = arg4 & 0xFF;
    fn_800745A4(v1, 1, 4, v2, 0, 125);
    GXLoadTexMtxImm((u32)&mtx, v2, 1);
    if (arg0->flags & 0x800000) {
        size = fn_1_519AC(arg0->format);
        width = arg0->width;
        height = arg0->height;
        size = width * size;
        size = height * size;
        DCFlushRange(arg0->pixels, __cvt_fp2unsigned(size));
        {
            u32 w = arg0->width, h = arg0->height;
            GXInitTexObj(&lbl_1_bss_4E688, arg0->pixels, w, h, (GXTexFmt)arg0->format, GX_CLAMP, GX_CLAMP, 0);
        }
        fn_80073778(&lbl_1_bss_4E688, arg3 & 0xFF);
    } else {
        image = arg0->image;
        images = lbl_1_data_FCD4[(image >> 8) & 0xFFFF].images;
        if (!(0.0f != arg0->scale_x && 0.0f != arg0->scale_y && images != 0)) {
            return;
        } else {
            fn_80073778(images->textures[image & 0xFF], arg3 & 0xFF);
        }
    }
    v7 = arg1 & 0xFF;
    fn_80073C6C(v7);
    fn_800734A8(v7, v1, arg3 & 0xFF, 255);
    if ((GXTexFmt)arg0->format == GX_TF_I4 || (GXTexFmt)arg0->format == GX_TF_I8) {
        fn_80072C24(v7, 15, 15, 15, 0);
        fn_80072D64(v7, 0, 0, 0, 1, 0);
        fn_80072CC4(v7, 7, 0, 4, 7);
        fn_80072E20(v7, 0, 0, 0, 1, 0);
    } else {
        fn_800729B0(2, 0, 0, 0, 0);
        fn_80072AB0(v7, 0, 2);
        fn_80072C24(v7, 8, 15, 0, 15);
        fn_80072D64(v7, 8, 0, 0, 1, 0);
        fn_80072CC4(v7, 4, 7, 0, 7);
        fn_80072E20(v7, 14, 0, 0, 1, 0);
    }
}
/* fzgx:end fn_1_4E220 */

/* fzgx:begin fn_1_4E500 */
void fn_1_4E500(void) {
    fn_1_A71CC();
    fn_1_4E0F4();
    lbl_8006D758();
    fn_80072558();
}
/* fzgx:end fn_1_4E500 */

/* fzgx:begin fn_1_4E638 */
void fn_1_4E638(s32 arg) {

    if (arg != 0) {
        C_MTXPerspective( (void *)((f32 *)((u8 *)lbl_801A6D00 + 0xc8)),
                    55.0f, fn_1_A6FE8(), 0.1f, 90000.0f);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 0);
    } else {
        C_MTXOrtho((u8 *)lbl_801A6D00 + 0xc8,
                    0.0f, 480.0f, 0.0f, 640.0f,
                    0.0f, 90000.0f);
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
s32 fn_1_4E724(FontDrawPacket *arg) {
    FontDrawPacket local = *arg;
    s32 ret;

    fn_1_4E500();

    if (lbl_1_bss_4E6A8 != 0) {
        local.flags |= 0x08000000;
        local.depth = lbl_1_bss_4E6AC;
    }

    ((u8 *)lbl_801A6D00)[0x197] = 0xff;

    if (local.flags & 0x00800000) {
        ret = fn_1_4EC74(&local);
    } else {
        ret = fn_1_4EB74(&local);
    }

    fn_1_A722C();
    fn_80074918(1, 3, 1);

    return ret;
}
/* fzgx:end fn_1_4E724 */

/* fzgx:begin fn_1_4E92C */
s32 fn_1_4E92C(const FontDrawPacket *src, u32 format, s16 width, s16 height, void *pixels) {
    FontDrawPacket packet = *src;

    packet.format = format;
    packet.flags |= 0x800000;
    packet.width = width;
    packet.height = height;
    packet.pixels = pixels;
    return fn_1_4E724(&packet);
}
/* fzgx:end fn_1_4E92C */

/* fzgx:begin fn_1_4EB74 */
s32 fn_1_4EB74(const FontDrawPacket *self) {
    u32 index;
    BitmapImageInfo *info;
    f32 x;
    f32 y;

    if (self->flags & 0x02000000) {
        return 0;
    }

    fn_1_159588(self->image);

    index = (self->image >> 8) & 0xffff;
    if (lbl_1_data_FCD4[index].loaded == 0) {
        return 0;
    }

    info = &lbl_1_data_FCD4[index].images->info[self->image & 0xff];
    x = info->width;
    y = info->height;
    fn_80073778((void *)(lbl_1_data_FCD4[index].images->textures[self->image & 0xff]), 0);
    fn_1_4EDAC((FontDrawPacket *)self, x, y);
    return 1;
}
/* fzgx:end fn_1_4EB74 */

/* fzgx:begin fn_1_4EC74 */
/* the const packet lets MWCC (GC/2.x) load packet->flags ahead of the r31 save, as retail does */

s32 fn_1_4EC74(const FontDrawPacket *packet) {
    if (packet->flags & 0x2000000) {
        return 0;
    }
    DCFlushRange(packet->pixels,
                 (packet->height * (packet->width * fn_1_519AC(packet->format))));
    {
        u32 width = packet->width, height = packet->height;
        GXInitTexObj(&lbl_1_bss_4E6B0, packet->pixels, width, height, packet->format, 0, 0, 0);
    }
    GXInitTexObjLOD(&lbl_1_bss_4E6B0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80073778(&lbl_1_bss_4E6B0, 0);
    fn_1_4EDAC((FontDrawPacket *)packet, packet->width, packet->height);
    return 1;
}
/* fzgx:end fn_1_4EC74 */

/* fzgx:begin fn_1_4EDAC */
/* GX write-gather pipe: every store is a FIFO write */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

static inline void draw_vertex(Vec3 *v, f32 u, f32 t) {
    f32 z = v->z;
    f32 y = v->y;
    f32 x = v->x;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u;
    GX_FIFO_F32 = t;
}

static inline u32 draw_perspective(FontDrawPacket *packet) {
    u32 result = (packet->flags >> 18) & 1;
    return result;
}

static inline u8 draw_min255(s32 value) {
    u8 result = value < 255 ? value : 255;
    return result;
}

void fn_1_4EDAC(FontDrawPacket *arg0, f32 arg1, f32 arg2) {
    u32 v0;
    f32 v1;
    Vec3 *v2;
    u8 perspective;
    f32 y, depth, u0, u1, t0, t1;
    FontColor add_color, color;
    u32 flags;
    DrawFields *packet = (DrawFields *)arg0;
    perspective = draw_perspective(arg0);
    v0 = (u32)lbl_801A6D00;
    v1 = 0.0f;
    v2 = (Vec3 *)(v0 + 152);
    psvec_fill4(v2, v1);
    if (perspective) {
        C_MTXPerspective((void *)((u32)lbl_801A6D00 + 0xc8), 55.0f, fn_1_A6FE8(),
            0.1f, 90000.0f);
        fn_800737E4((void *)((u32)lbl_801A6D00 + 0xc8), 0);
    } else {
        C_MTXOrtho((void *)((u32)lbl_801A6D00 + 0xc8), v1, 480.0f,
            v1, 640.0f, v1, 90000.0f);
        fn_800737E4((void *)((u32)lbl_801A6D00 + 0xc8), 1);
    }
    flags = arg0->flags;
    *(u8 *)((u32)lbl_801A6D00 + 0x197) = perspective;
    if ((flags & 0x1000000) && packet->texture) {
        fn_80074660(2);
        fn_80073678(2);
        fn_1_4E220((void *)packet->texture, 1, 1, 1, 0x21);
    } else {
        fn_80073678(1);
    }
    v1 = packet->x;
    y = packet->y;
    depth = -packet->depth;
    u0 = packet->u0;
    u1 = packet->u1;
    t0 = packet->v0;
    t1 = packet->v1;
    switch (arg0->flags & 3) {
    case 0:
    case 1:
    default:
        v2[0].x = v2[2].x = 0.0f;
        v2[1].x = v2[3].x = arg1;
        break;
    case 2: {
        f32 right;
        f32 left;
        left = -arg1 / 2.0;
        right = arg1 / 2.0;
        v2[0].x = v2[2].x = left;
        v2[1].x = v2[3].x = right;
        break;
    }
    case 3: {
        f32 right;
        f32 left;
        left = -arg1;
        right = 0.0f;
        v2[0].x = v2[2].x = left;
        v2[1].x = v2[3].x = right;
        break;
    }
    }
    switch ((arg0->flags >> 2) & 3) {
    case 0:
    case 1:
    default:
        v2[0].y = v2[1].y = 0.0f;
        v2[2].y = v2[3].y = arg2;
        break;
    case 2: {
        f32 right;
        f32 left;
        left = -arg2 / 2.0;
        right = arg2 / 2.0;
        v2[0].y = v2[1].y = left;
        v2[2].y = v2[3].y = right;
        break;
    }
    case 3: {
        f32 right;
        f32 left;
        left = -arg2;
        right = 0.0f;
        v2[0].y = v2[1].y = left;
        v2[2].y = v2[3].y = right;
        break;
    }
    }
    if ((arg0->flags & 0x8000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(packet->pivot, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        lbl_8006E0B4(v1 - packet->pivot, y, 0.0f);
    } else {
        lbl_8006D7F4(v1, y, 0.0f);
    }
    if (packet->angle_z)
        mathutil_mtxA_rotate_z((s16)-packet->angle_z);
    if (packet->angle_y)
        mathutil_mtxA_rotate_y((s16)-packet->angle_y);
    lbl_8006E15C(packet->scale_x, packet->scale_y, 1.0f);
    lbl_8006E1B0((void *)&v2[0], (void *)&v2[0]);
    lbl_8006E1B0((void *)&v2[1], (void *)&v2[1]);
    lbl_8006E1B0((void *)&v2[2], (void *)&v2[2]);
    lbl_8006E1B0((void *)&v2[3], (void *)&v2[3]);
    fn_1_492F0((void *)arg0, (void *)v2);
    if (perspective) {
        f32 scratch;
        f32 scale;
        f32 cy;
        f32 cx;
        f32 vx;
        scale = 0.002405626 * packet->depth;
        vx = v2[0].x;
        cx = 320.0f;
        cy = 240.0f;
        scratch = vx - cx;
        v2[0].x = scratch * scale;
        scratch = v2[0].y - cy;
        v2[0].y = -(scratch * scale);
        scratch = v2[1].x - cx;
        v2[1].x = scratch * scale;
        scratch = v2[1].y - cy;
        v2[1].y = -(scratch * scale);
        scratch = v2[2].x - cx;
        v2[2].x = scratch * scale;
        scratch = v2[2].y - cy;
        v2[2].y = -(scratch * scale);
        scratch = v2[3].x - cx;
        v2[3].x = scratch * scale;
        scratch = v2[3].y - cy;
        v2[3].y = -(scratch * scale);
    }
    if (arg0->flags & 0x80000) {
        u0 = packet->u1;
        u1 = packet->u0;
    }
    if (arg0->flags & 0x100000) {
        t0 = packet->v1;
        t1 = packet->v0;
    }
    if (!(arg0->flags & 0x800000) && !(arg0->flags & 0x10000000) &&
        (fn_1_486F8(packet->id) == 0 || fn_1_486F8(packet->id) == 1)) {
        u32 sum;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = (255.0f * packet->alpha);
        sum = packet->color.r + packet->add_color.r;
        add_color.r = (s32)sum < 255 ? sum : 255;
        sum = packet->color.g + packet->add_color.g;
        add_color.g = (s32)sum < 255 ? sum : 255;
        sum = packet->color.b + packet->add_color.b;
        add_color.b = draw_min255(sum);
        add_color.a = 0;
        fn_800371F8(1, color);
        fn_800371F8(2, add_color);
    } else {
        color.r = packet->color.r;
        color.g = packet->color.g;
        color.b = packet->color.b;
        color.a = (255.0f * packet->alpha);
        fn_800371F8(1, color);
        fn_800371F8(2, packet->add_color);
    }
    if ((arg0->flags & 0x4000000) && packet->callback)
        packet->callback(arg0, v2);
    if (!perspective) {
        v2[0].z = v2[1].z = v2[2].z = v2[3].z = depth;
    }
    fn_8003462C(0x80, 7, 4);
    draw_vertex(&v2[0], u0, t0);
    draw_vertex(&v2[1], u1, t0);
    draw_vertex(&v2[3], u1, t1);
    draw_vertex(&v2[2], u0, t1);
    fn_80072AB0(1, 0, 0);
    if ((arg0->flags & 0x1000000) && packet->texture) {
        fn_1_4E0F4();
        fn_80074660(1);
        fn_80072AB0(1, 0, 0);
    }
    if (arg0->flags & 0x4000000) {
        u32 height;
        fn_1_4E0F4();
        height = fn_1_A5DB0();
        fn_80074188(0, 0, fn_1_A5D88(), height);
    }
}
/* fzgx:end fn_1_4EDAC */

/* fzgx:begin fn_1_4F724 */
/* sprite packet buffer */
FontDrawPacket lbl_1_bss_4E6D0[0x400];
u32 lbl_1_data_1C500 = 0x400;
FontDrawPacket *lbl_1_data_1C504 = lbl_1_bss_4E6D0;
f32 lbl_1_data_1C508 = 1.0f;
u16 lbl_1_bss_646D0;
u16 lbl_1_bss_646D2;

/* Placeholder: retail function stripped by the link; only its assert strings (.data 1C50C "sprite.c", 1C518) and
   its .bss footprint survive (the buffer 4E6D0 and the halfword 646D0 are first used here, before 4F724's count).
   Named by its message; the body is a guess. */
static void SprBufChg(void) {
    if (lbl_1_data_1C504 != lbl_1_bss_4E6D0) {
        OSPanic("sprite.c", 0, "You must do SprBufUnChg() before using SprBufChg()");
    }
    lbl_1_bss_646D0 = lbl_1_bss_646D2;
}

// Clear the font state value before the next initialization.

void fn_1_4F724(void) {
    lbl_1_bss_646D2 = 0;
}
/* fzgx:end fn_1_4F724 */

/* fzgx:begin fn_1_4F734 */
int fn_1_4F734(FontDrawPacket *input) {
    if (input->image >= 0xffff0000u)
        return 0;
    if (input->flags & 0x20000) {
        return fn_1_4E724(input);
    } else {
        u16 count = lbl_1_bss_646D2;
        FontDrawPacket *dst;
        if (count >= lbl_1_data_1C500) {
            if (!lbl_1_bss_4C67C) {
                OSReport("*** SprToBuf : SPRITE BUFFER OVER !! ***\n");
                lbl_1_bss_4C67C = 1;
            }
            return 0;
        }
        dst = &lbl_1_data_1C504[count];
        fn_80008BA8(dst, input, 0x58);
        dst->x += fn_1_54298();
        dst->y += fn_1_542A8();
        dst->alpha *= fn_1_542B8();
        if (lbl_1_bss_4E6A8) {
            dst->flags |= 0x08000000;
            dst->depth = lbl_1_bss_4E6AC;
        }
        lbl_1_bss_646D2++;
        return 1;
    }
}
/* fzgx:end fn_1_4F734 */

/* fzgx:begin fn_1_4FC50 */
s32 fn_1_4FC50(const FontDrawPacket *obj, u32 format, u16 width, u16 height, void *pixels) {
    FontDrawPacket *entry;
    u16 index;

    if (obj->image >= 0xffff0000) {
        return 0;
    }
    index = lbl_1_bss_646D2;
    if (index >= lbl_1_data_1C500) {
        return 0;
    }

    entry = &lbl_1_data_1C504[index];
    fn_80008BA8(entry, obj, 0x58);
    entry->flags |= (u32)1 << 23;
    entry->format = format;
    entry->width = width;
    entry->height = height;
    entry->pixels = pixels;

    if (lbl_1_bss_4E6A8 != 0) {
        entry->flags |= (u32)1 << 27;
        entry->depth = lbl_1_bss_4E6AC;
    }

    lbl_1_bss_646D2++;
    return 1;
}
/* fzgx:end fn_1_4FC50 */

/* fzgx:begin fn_1_4FD64 */
void fn_1_4FD64(f32 arg0) {
    u16 *a;
    s32 i;
    a = (u16 *)(lbl_801A66CC + 0x8B8);
    for (i = 0; i < lbl_1_bss_646D2; i++) {
        a[i] = i;
    }
    qsort(a, lbl_1_bss_646D2, 2, (int (*)(const void *, const void *))fn_1_4E0A4);
    fn_1_4E500();
    lbl_801A6D00[0x197] = 0xFF;
    for (i = 0; i < lbl_1_bss_646D2; i++) {
        FontDrawPacket *e = &lbl_1_data_1C504[a[i]];
        if (e->flags & 0x2000000) continue;
        if (e->flags & 0x400000) {
            fn_1_48D80(e);
        } else if (e->flags & 0x800000) {
            fn_1_4EC74(e);
        } else {
            fn_1_4EB74(e);
        }
    }
    fn_1_A722C();
    fn_80074918(1, 3, 1);
    lbl_1_bss_646D2 = 0;
}
/* fzgx:end fn_1_4FD64 */

/* fzgx:begin fn_1_50164 */
void fn_1_50164(FontDrawPacket *packet, f32 width, f32 height, f32 a, f32 b) {
    fn_1_50190(packet, width, height, a, a, b, b);
}
/* fzgx:end fn_1_50164 */

/* fzgx:begin fn_1_50190 */

void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    struct Pkt88 loc_8;
    f32 temp_f31;
    f32 var_f30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f28_2;
    f32 temp_f30_2;
    f32 half;
    f32 temp_f24;
    f32 temp_f23;
    f32 inner_h;
    f32 var_f22;
    f32 temp_f30;
    u32 temp_r4;
    u32 temp_r0;
    u32 temp_r0_2;

    temp_f23 = fn_1_48690((*(u32 *)(arg0)));
    temp_f24 = (fn_1_486C4((*(u32 *)(arg0))) - farg4) - farg5;
    temp_f25 = (temp_f23 - farg2) - farg3;
    temp_f26 = (farg0 - farg2) - farg3;
    inner_h = (farg1 - farg4) - farg5;
    if (farg0 <= 0.0f || farg1 <= 0.0f || temp_f25 <= 0.0f || temp_f24 <= 0.0f || temp_f26 <= 0.0f || inner_h <= 0.0f || farg2 < 0.0f || farg3 < 0.0f || farg4 < 0.0f || farg5 < 0.0f) {
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
            half = farg0 / 2.0f;
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - half;
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
            half = farg1 / 2.0f;
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - half;
            break;
        case 3:
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - farg1;
            break;
        }
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), (0), (0), farg2, farg4);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), farg2, (0), temp_f25, farg4);
        temp_f29 = temp_f26;
        temp_f29 /= temp_f25;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        temp_f31 = var_f22 + farg2;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f27 = farg2;
        temp_f27 += temp_f25;
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), temp_f27, (0), farg3, farg4);
        temp_f26 = temp_f26 + temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), (0), farg4, farg2, temp_f24);
        temp_f28 = inner_h / temp_f24;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        temp_f30 = var_f30 + farg4;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), farg2, farg4, temp_f25, temp_f24);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), temp_f27, farg4, farg3, temp_f24);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f28_2 = farg4 + temp_f24;
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), (0), temp_f28_2, farg2, farg5);
        temp_f30_2 = inner_h + temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), farg2, temp_f28_2, temp_f25, farg5);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)), (*(u32 *)(arg0)), temp_f27, temp_f28_2, farg3, farg5);
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((void *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    }
}

/* fzgx:end fn_1_50190 */

/* fzgx:begin fn_1_508C4 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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

    x_start = obj->start_x;
    x_end = (obj->start_x + dx);
    y_start = obj->start_y;
    y_end = (obj->start_y + dy);

    width = (obj->scale_x * fn_1_48690(obj->unk0));
    height = (obj->scale_y * fn_1_486C4(obj->unk0));

    for (y = y_start; y < y_end; y += height) {
        for (x = x_start; x < x_end; x += width) {
            s32 h;
            s32 w;

            work = *obj;
            h = MIN(y_end - y, height);
            w = MIN(x_end - x, width);
            fn_1_51678((void *)((FontDrawPacket *)&work), obj->unk0, 0, 0, w, h);
            work.start_x = x;
            work.start_y = y;
            fn_1_4F734((FontDrawPacket *)&work);
        }
    }
}
/* fzgx:end fn_1_508C4 */

/* fzgx:begin fn_1_50A90 */

#define PF(o) (*(f32 *)((u8 *)&packet + (o)))

#define FLAGS (*(u32 *)((u8 *)&packet + 48))

#define COPY() (packet = *(struct fn_1_50A90_Copy88 *)arg0)

#define SETUP(a,b,c,d) fn_1_51678((void *)((FontDrawPacket *)&packet), *(u32 *)arg0, (s16)(a), (s16)(b), (s16)(c), (s16)(d))

#define DRAW() fn_1_4F734((FontDrawPacket *)&packet)

/* WARNING: compiler-diff device, not original code (carried from main: 3 words in fn_1_50A90 without it) */
#pragma opt_lifetimes off

void fn_1_50A90(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v6;
    u32 v4;
    s32 v0;
    u32 v1;
    u32 v3;
    u32 v2;
    u32 v5;
    f32 texRight;
    f32 rightX;
    f32 bottomY;
    f32 innerX;
    f32 innerY;
    f32 endTex;
    f32 v13;
    f32 ratioY;
    f32 endTexY;
    f32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 v17;
    f32 v18;
    f32 y;
    f32 texBottom;
    f32 ratioX;
    f32 remainderY;
    f32 posX;
    f32 posRX;
    f32 posY;
    f32 posRY;
    s16 i;
    s16 count;
    struct fn_1_50A90_Copy88 packet;
    u16 t0;
    u16 t1;
    v0 = ((s32)((-arg1) & ~arg1) >> 31);
    v1 = (arg1 & v0);
    v2 = (v1 << 1);
    v3 = (arg2 & ((s32)((-arg2) & ~arg2) >> 31));
    v4 = v2;
    if ((s32)arg3 > (s32)v2) {
        v4 = arg3;
    }
    v5 = (v3 << 1);
    v6 = v5;
    if ((s32)arg4 > (s32)v5) {
        v6 = arg4;
    }
    t0 = fn_1_48690(*(u32 *)(arg0));
    v8 = (u32)(t0 & 0xFFFF);
    t1 = fn_1_486C4(*(u32 *)(arg0));
    v9 = (t1 & 0xFFFF);
    v10 = *(u32 *)((u8 *)arg0 + 48);
    v11 = (v10 & 0x3);
    v13 = v9;
    v14 = (v8 - (s32)v2);
    v15 = (v13 - (s32)v5);
    v16 = (s32)(v4 - v2);
    v17 = (s32)(v6 - v5);
    switch (v11) {
    case 1:
    default: v18 = *(f32 *)((u8 *)arg0 + 4); break;
    case 2: v18 = *(f32 *)((u8 *)arg0 + 4) - ((s32)v4 / 2); break;
    case 3: v18 = *(f32 *)((u8 *)arg0 + 4) - (s32)v4; break;
    }
    switch ((v10 >> 2) & 3) {
    case 1:
    default: y = *(f32 *)((u8 *)arg0 + 8); break;
    case 2: y = *(f32 *)((u8 *)arg0 + 8) - ((s32)v6 / 2); break;
    case 3: y = *(f32 *)((u8 *)arg0 + 8) - (s32)v6; break;
    }
    COPY();
    SETUP(0, 0, v1, v3);
    PF(4) = v18;
    PF(8) = y;
    FLAGS &= ~15;
    DRAW();

    COPY();
    texRight = v8 - (s32)v1;
    SETUP(texRight, 0, v1, v3);
    innerX = v18 + (s32)v1;
    rightX = v16 + innerX;
    PF(4) = rightX;
    PF(8) = y;
    FLAGS &= ~15;
    DRAW();

    COPY();
    texBottom = v13 - (s32)v3;
    SETUP(0, texBottom, v1, v3);
    innerY = y + (s32)v3;
    bottomY = v17 + innerY;
    PF(4) = v18;
    PF(8) = bottomY;
    FLAGS &= ~15;
    DRAW();

    COPY();
    SETUP(texRight, texBottom, v1, v3);
    PF(4) = rightX;
    PF(8) = bottomY;
    FLAGS &= ~15;
    DRAW();

    COPY();
    SETUP(v1, v3, v14, v15);
    ratioX = v16 / v14;
    ratioY = v17 / v15;
    PF(4) = innerX;
    PF(8) = innerY;
    FLAGS &= ~15;
    PF(16) *= ratioX;
    PF(20) *= ratioY;
    DRAW();

    if ((0.0f) != v16) {
        count = ratioX;
        i = 0;
        endTex = (s32)v3 + v15;
        while (i < count) {
            COPY();
            SETUP(v1, 0, v14, v3);
            posX = innerX + (f32)(i * v14);
            PF(4) = posX;
            PF(8) = y;
            FLAGS &= ~15;
            DRAW();
            COPY();
            SETUP(v1, endTex, v14, v3);
            PF(4) = posX;
            PF(8) = bottomY;
            FLAGS &= ~15;
            DRAW();
            i++;
        }
        texRight = v16 - (f32)(v14 * count);
        COPY();
        SETUP(v1, 0, texRight, v3);
        posRX = innerX + (f32)(i * v14);
        PF(4) = posRX;
        PF(8) = y;
        FLAGS &= ~15;
        DRAW();
        COPY();
        SETUP(v1, endTex, texRight, v3);
        PF(4) = posRX;
        PF(8) = bottomY;
        FLAGS &= ~15;
        DRAW();
    }
    if ((0.0f) != v17) {
        s16 iY;
        s16 countY;
        countY = ratioY;
        iY = 0;
        endTexY = (s32)v1 + v14;
        while (iY < countY) {
            COPY();
            SETUP(0, v3, v1, v15);
            posY = innerY + (f32)(iY * v15);
            PF(4) = v18;
            PF(8) = posY;
            FLAGS &= ~15;
            DRAW();
            COPY();
            SETUP(endTexY, v3, v1, v15);
            PF(4) = rightX;
            PF(8) = posY;
            FLAGS &= ~15;
            DRAW();
            iY++;
        }
        remainderY = v17 - (f32)(v15 * countY);
        COPY();
        SETUP(0, v3, v1, remainderY);
        posRY = innerY + (f32)(iY * v15);
        PF(4) = v18;
        PF(8) = posRY;
        FLAGS &= ~15;
        DRAW();
        COPY();
        SETUP(endTexY, v3, v1, remainderY);
        PF(4) = rightX;
        PF(8) = posRY;
        FLAGS &= ~15;
        DRAW();
    }
}
/* fzgx:end fn_1_50A90 */

/* fzgx:begin fn_1_51564 */
#pragma opt_lifetimes reset

// Update the six halfwords that define the active font state.

void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth) {
    lbl_1_bss_646D4 = first;
    lbl_1_bss_646D6 = second;
    lbl_1_bss_646D8 = third;
    lbl_1_bss_646DA = fourth;
    lbl_1_bss_646DC = fifth;
    lbl_1_bss_646DE = sixth;
}
/* fzgx:end fn_1_51564 */

/* fzgx:begin fn_1_5158C */
static inline int in_range(int value, int lower, int upper)
{
    if (value > upper) {
        return 0;
    }
    return value >= lower;
}

void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y)
{
    int max_x = lbl_1_bss_646DC - 1;
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
    max_y = lbl_1_bss_646DE - 1;
    coordinate = y;
    if (!in_range(coordinate, 0, max_y)) {
        if (y < 0) {
            coordinate = 0;
        } else if (coordinate > max_y) {
            coordinate = max_y;
        }
        y = coordinate;
    }
    fn_1_51678((void *)packet, color, lbl_1_bss_646D4 + x * lbl_1_bss_646D8,
        lbl_1_bss_646D6 + y * lbl_1_bss_646DA,
        lbl_1_bss_646D8, lbl_1_bss_646DA);
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
        sx = width * inv_width;
        sy = height * inv_height;
        u = x * inv_width;
        v = y * inv_height;
        p->scale_x *= sx;
        p->scale_y *= sy;
        p->u0 = u;
        p->v0 = v;
    }
    p->u1 = inv_width * (x + width);
    p->v1 = inv_height * (y + height);
}
/* fzgx:end fn_1_51678 */

/* fzgx:begin fn_1_517EC */
void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height) { f32 inv_height, inv_width;
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    p->scale_x *= width * inv_width;
    p->scale_y *= height * inv_height;
    p->u0 = x * inv_width;
    p->v0 = y * inv_height;
    p->u1 = inv_width * (x + width);
    p->v1 = inv_height * (y + height);
}
#undef PF
#undef FLAGS
#undef COPY
#undef SETUP
#undef DRAW
/* fzgx:end fn_1_517EC */

/* fzgx:begin fn_1_51914 */
void fn_1_51914(const FontDrawPacket *src) {
    FontDrawPacket packet = *src;

    lbl_1_bss_4C678 = &lbl_1_data_1C504[lbl_1_bss_646D2];
    packet.flags |= 0x2000000;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_51914 */

/* fzgx:begin fn_1_51990 */
void fn_1_51990(FontDrawPacket *packet) {
    packet->secondary = lbl_1_bss_4C678;
    packet->flags |= 0x01000000;
}
/* fzgx:end fn_1_51990 */

/* fzgx:begin fn_1_519AC */
f32 fn_1_519AC(u32 format) {
    switch (format) {
    case 0:
    case 14:
        return 0.5f;
    case 1:
    case 2:
    case 17:
        return 1.0f;
    case 3:
    case 4:
    case 5:
    case 19:
        return 2.0f;
    case 6:
    case 22:
        return 4.0f;
    default:
        return 0.0f;
    }
}

/* ordinal suffixes: rows 1st, 2nd, 3rd, nth; one column per language */

char *font_ordinal_suffix[4][6] = {
    {"st", ".", ".", ".", ".", ""},
    {"nd", ".", ".", ".", ".", ""},
    {"rd", ".", ".", ".", ".", ""},
    {"th", ".", ".", ".", ".", ""},
};
/* fzgx:end fn_1_519AC */

/* fzgx:begin fn_1_519FC */
f32 fn_1_519FC(f32 x) {
    f32 viewport[6];
    f32 left;
    f32 width;

    fn_80038F10(viewport);
    left = viewport[0];
    width = viewport[2];
    return x * width / fn_1_A5D88() + 640.0f * left / fn_1_A5D88();
}
/* fzgx:end fn_1_519FC */

/* fzgx:begin fn_1_51AC0 */
f32 fn_1_51AC0(f32 y) {
    f32 viewport[6];
    f32 top;
    f32 height;

    fn_80038F10(viewport);
    top = viewport[1];
    height = viewport[3];
    return y * height / fn_1_A5DB0() + 480.0f * top / fn_1_A5DB0();
}
/* fzgx:end fn_1_51AC0 */

/* fzgx:begin fn_1_51B84 */
f32 fn_1_51B84(f32 w) {
    f32 viewport[6];
    f32 width;

    fn_80038F10(viewport);
    width = viewport[2];
    return w * width / fn_1_A5D88();
}
/* fzgx:end fn_1_51B84 */

/* fzgx:begin fn_1_51BFC */
f32 fn_1_51BFC(f32 h) {
    f32 viewport[6];
    f32 height;

    fn_80038F10(viewport);
    height = viewport[3];
    return h * height / fn_1_A5DB0();
}
/* fzgx:end fn_1_51BFC */

/* fzgx:begin fn_1_51C74 */
void fn_1_51C74(fn_1_51C74_FontData *obj) {
    obj->x = fn_1_519FC(obj->x);
    obj->y = fn_1_51AC0(obj->y);
    obj->z = fn_1_51B84(obj->z);
    obj->w = fn_1_51BFC(obj->w);
}
/* fzgx:end fn_1_51C74 */

/* fzgx:begin fn_1_51E60 */
void fn_1_51E60(FontDrawPacket *src) {
    FontDrawPacket packet;

    packet = *src;
    packet.x = fn_1_519FC(packet.x);
    packet.y = fn_1_51AC0(packet.y);
    packet.scale_x = fn_1_51B84(packet.scale_x);
    packet.scale_y = fn_1_51BFC(packet.scale_y);
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

    if ((s8)fn_1_A5DC4(value) && lbl_1_bss_4E6A8 != 0) {
        base = lbl_1_bss_4E6AC;
        scaled = (value - base) * 0.75f;
        return base + scaled;
    }
    return value;
}
/* fzgx:end fn_1_520F8 */

/* fzgx:begin fn_1_521B8 */
// Convert a font value to its scaled coordinate when the font system is active.

f32 fn_1_521B8(s32 value) {
    if ((s8)fn_1_A5DC4(value) && lbl_1_bss_4E6A8 != 0) {
        return 0.75f * value;
    }

    return value;
}
/* fzgx:end fn_1_521B8 */

/* fzgx:begin fn_1_52250 */
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

/* fzgx:begin fn_1_52270 */
void fn_1_52270(const FontDrawPacket *packet) {
    FontColor add;
    FontColor color;

    color.r = packet->color[0];
    color.g = packet->color[1];
    color.b = packet->color[2];
    color.a = 255.0f * packet->alpha;
    add.r = packet->color_add[0];
    add.g = packet->color_add[1];
    add.b = packet->color_add[2];
    add.a = 0;
    fn_800371F8(1, color);
    fn_800371F8(2, add);
    fn_80072C24(0, 4, 2, 8, 15);
    fn_80072CC4(0, 7, 7, 7, 1);
}
/* fzgx:end fn_1_52270 */

/* fzgx:begin fn_1_5233C */
static inline void pos(f32 x, f32 y, f32 z) { GX_FIFO_F32=x; GX_FIFO_F32=y; GX_FIFO_F32=z; }

static inline void xy(f32 x, f32 y) { GX_FIFO_F32=x; GX_FIFO_F32=y; }

#define VERT(X,Y,U,V) pos((X),(Y),z); GX_FIFO_F32=(U); GX_FIFO_F32=(V)

void fn_1_5233C(void *arg0, void *arg1) {
    struct ShadowEntry table[9] = {
        {{0x00, 0x00, 0x00, 0x00}, 2.0f, 2.0f},
        {{0x00, 0x00, 0x00, 0x00}, 1.0f, 1.0f},
        {{0x9B, 0x00, 0x00, 0x00}, 2.0f, 2.0f},
        {{0x9B, 0x00, 0x00, 0x00}, 1.0f, 1.0f},
        {{0x00, 0x00, 0xFF, 0x00}, 2.0f, 2.0f},
        {{0x00, 0x00, 0xFF, 0x00}, 1.0f, 1.0f},
        {{0xFF, 0xF2, 0x00, 0x00}, 1.0f, 1.0f},
        {{0xFF, 0x80, 0x00, 0x00}, 1.0f, 1.0f},
        {{0x00, 0x00, 0x80, 0x00}, 2.0f, 2.0f},
    };
    struct fn_1_5233C_Copy88 copy;
    FontColor color;
    FontColor c0;
    FontColor c1;
    struct ShadowEntry *entry;
    f32 dx,dy,z,v0,u1,u0,v1;
    f32 *p = arg1;
    entry = &table[(u32)*(f32 *)((u8 *)arg0+0x54)];
    if (!(*(u32 *)((u8 *)arg0+0x30) & 0x10000000)) {
        copy = *(struct fn_1_5233C_Copy88 *)arg0;
        c0 = entry->color;
        dx = entry->x;
        dy = entry->y;
        fn_800371F8(2, c0);
        fn_8003462C(0x80,7,16);
        xy(p[0],p[1]-dy);
        z = -(0.1f+*(f32 *)((u8 *)&copy+0xc)); GX_FIFO_F32=z;
        u0=*(f32 *)((u8 *)&copy+0x18); GX_FIFO_F32=u0;
        v0=*(f32 *)((u8 *)&copy+0x1c); GX_FIFO_F32=v0;
        pos(p[3],p[4]-dy,z);
        u1=*(f32 *)((u8 *)&copy+0x20); GX_FIFO_F32=u1; GX_FIFO_F32=v0;
        pos(p[9],p[10]-dy,z); GX_FIFO_F32=u1;
        v1=*(f32 *)((u8 *)&copy+0x24); GX_FIFO_F32=v1;
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
        fn_800371F8(2, c1);
    }
}
/* fzgx:end fn_1_5233C */

/* fzgx:begin fn_1_52690 */
void fn_1_52690(const FontDrawPacket *packet) {
    u32 width = packet->width, height = packet->height;

    GXInitTexObj(&lbl_1_bss_646E8, packet->pixels, width, height, packet->format, 0, 0, 0);
    GXInitTexObjLOD(&lbl_1_bss_646E8, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80073778(&lbl_1_bss_646E8, 0);
}
#undef VERT
/* fzgx:end fn_1_52690 */

/* fzgx:begin fn_1_52718 */
void fn_1_52718(const FontDrawPacket *packet) {
    FontColor color;

    color.r = packet->color[0];
    color.g = packet->color[1];
    color.b = packet->color[2];
    color.a = 255.0f * packet->alpha;
    fn_800371F8(1, color);
    fn_800371F8(2, *(FontColor *)packet->color_add);
    fn_800728A8(1, 1, 1, 0);
}
/* fzgx:end fn_1_52718 */

/* fzgx:begin fn_1_527B4 */
void fn_1_527B4(void) {
    u8 scratch[0x30];
    FontState_52718 *state;
    BitmapResource *entry;
    BitmapImages *obj;
    u32 value;
    u32 index;

    state = (FontState_52718 *)lbl_1_bss_4C678;
    if (state != 0) {
        fn_80074918(1, 3, 1);
        lbl_8006D7F4(state->unk_4, state->unk_8, 0.0f);
        lbl_8006E15C(state->unk_10, state->unk_14, 1.0f);
        mathutil_mtxA_rotate_z(state->unk_28);
        lbl_8006DD7C();
        lbl_8006DB74((void *)&scratch[0]);
        fn_800745A4(1, 1, 4, 0x21, 0, 0x7d);
        GXLoadTexMtxImm( (u32)(&scratch[0]), 0x21, 1);
        value = state->unk_0;
        index = (value >> 8) & 0xffff;
        entry = lbl_1_data_FCD4;
        entry += index;
        obj = entry->images;
        if (0.0f == state->unk_10 ||
            0.0f == state->unk_14 ||
            obj == 0) {
            return;
        }
        fn_80073778((void *)(((u8 *)obj->textures + ((value & 0xff) << 5))), 1);
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

/* fzgx:begin fn_1_52968 */
// Draw formatted text as four rotated layers (one vertex callback each, each

// slightly deeper), then the top layer through fn_1_530C8 unless mode 5.

void fn_1_52968(s32 x, s32 y, f32 depth, const char *format, ...) {
    char buffer[4096];
    __va_list args;
    void (*callbacks[4])(void *, void *) = { fn_1_52B68, fn_1_52B8C, fn_1_52BB0, fn_1_52BD4 };
    u32 i;
    f32 step;

    __builtin_va_info(&args);
    fn_8008077C(buffer, format, args);

    for (i = 0; i < 4; i++) {
        fn_1_496FC(x, y);
        fn_1_49738((u32)callbacks[i]);
        step = 0.1f * (s32)i;
        fn_1_4954C(depth + step);
        fn_1_4A0D8(buffer);
    }

    if ((s32)(lbl_801A66B4) != 5) {
        fn_1_496FC(x, (y + 3));
        fn_1_49738((u32)fn_1_530C8);
        fn_1_4954C(0.5f + depth);
        fn_1_4A0D8(buffer);
    }
}
/* fzgx:end fn_1_52968 */

/* fzgx:begin fn_1_52B68 */
void fn_1_52B68(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0);
}
/* fzgx:end fn_1_52B68 */

/* fzgx:begin fn_1_52B8C */
void fn_1_52B8C(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0x1000);
}
/* fzgx:end fn_1_52B8C */

/* fzgx:begin fn_1_52BB0 */
void fn_1_52BB0(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0x2000);
}
/* fzgx:end fn_1_52BB0 */

/* fzgx:begin fn_1_52BD4 */
void fn_1_52BD4(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(arg1), 0x3000);
}
/* fzgx:end fn_1_52BD4 */

/* fzgx:begin fn_1_52BF8 */
void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2) {
    s16 s = arg2;
    s32 t1;
    s32 t2;

    (void)arg1;
    lbl_8006D758();
    t1 = s + 0x4000;
    (*(f32 *)(((u32)lbl_801A6D00) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)(((u32)lbl_801A6D00) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(arg2));
    GXLoadTexMtxImm(((u32)lbl_801A6D00), (0x1EU), (1U));
    t2 = s + 0x8000;
    (*(f32 *)(((u32)lbl_801A6D00) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    (*(f32 *)(((u32)lbl_801A6D00) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm(((u32)lbl_801A6D00), (0x21U), (1U));
    t1 = s + 0xC000;
    (*(f32 *)(((u32)lbl_801A6D00) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)(((u32)lbl_801A6D00) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    GXLoadTexMtxImm(((u32)lbl_801A6D00), (0x24U), (1U));
    (*(f32 *)(((u32)lbl_801A6D00) + 12)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188((s + 0x10000)));
    (*(f32 *)(((u32)lbl_801A6D00) + 28)) = ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm(((u32)lbl_801A6D00), (0x27U), (1U));
    fn_8007245C((0x2200U));
    fn_80073678((5U));
    fn_80074660((4U));
    fn_800745A4((0U), (1), (4), (0x1EU), (0U), (0x7DU));
    fn_800745A4((1U), (1), (4), (0x21U), (0U), (0x7DU));
    fn_800745A4((2U), (1), (4), (0x24U), (0U), (0x7DU));
    fn_800745A4((3U), (1), (4), (0x27U), (0U), (0x7DU));
    fn_80073C6C((0));
    fn_80073C6C((1));
    fn_80073C6C((2));
    fn_80073C6C((3));
    fn_80073C6C((4));
    fn_800734A8((0U), (0U), (0U), (0xFFU));
    fn_800734A8((1U), (1U), (0U), (0xFFU));
    fn_800734A8((2U), (2U), (0U), (0xFFU));
    fn_800734A8((3U), (3U), (0U), (0xFFU));
    fn_800734A8((4U), (0xFFU), (0xFFU), (0xFFU));
    fn_80072C24((0), (0xF), (0xF), (0xF), (8));
    fn_80072D64((0U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((0U), (7U), (7U), (7U), (4U));
    fn_80072E20((0), (0), (0), (0), (1U), (0));
    fn_80072C24((1), (0xF), (8), (0xC), (0));
    fn_80072D64((1U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((1U), (4U), (7U), (7U), (0U));
    fn_80072E20((1), (0), (0), (0), (1U), (0));
    fn_80072C24((2), (0xF), (8), (0xC), (0));
    fn_80072D64((2U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((2U), (4U), (7U), (7U), (0U));
    fn_80072E20((2), (0), (0), (0), (1U), (0));
    fn_80072C24((3), (0xF), (8), (0xC), (0));
    fn_80072D64((3U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((3U), (4U), (7U), (7U), (0U));
    fn_80072E20((3), (0), (0), (0), (1U), (0));
    fn_80072C24((4), (0xF), (2), (0), (4));
    fn_80072D64((4U), (0U), (0U), (0U), (1U), (0U));
    fn_80072CC4((4U), (7U), (1U), (0U), (2U));
    fn_80072E20((4), (0), (0), (0), (1U), (0));
    fn_80074918((1U), (3), (1U));
}
/* fzgx:end fn_1_52BF8 */

/* fzgx:begin fn_1_530C8 */
void fn_1_530C8(void *arg0) {
    lbl_8006D758();
    *(f32 *)((u8 *)lbl_801A6D00 + 12) = *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(-6144);
    *(f32 *)((u8 *)lbl_801A6D00 + 28) = 0.125f + *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(-22528);
    GXLoadTexMtxImm((u32)lbl_801A6D00, 30, 1);
    *(f32 *)((u8 *)lbl_801A6D00 + 12) = *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(-2048);
    *(f32 *)((u8 *)lbl_801A6D00 + 28) = 0.125f + *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(-18432);
    GXLoadTexMtxImm((u32)lbl_801A6D00, 33, 1);
    *(f32 *)((u8 *)lbl_801A6D00 + 12) = *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(2048);
    *(f32 *)((u8 *)lbl_801A6D00 + 28) = 0.125f + *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(-14336);
    GXLoadTexMtxImm((u32)lbl_801A6D00, 36, 1);
    *(f32 *)((u8 *)lbl_801A6D00 + 12) = *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(6144);
    *(f32 *)((u8 *)lbl_801A6D00 + 28) = 0.125f + *(f32 *)((u8 *)arg0 + 84) * lbl_8006D188(-10240);
    GXLoadTexMtxImm((u32)lbl_801A6D00, 39, 1);
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
/* fzgx:end fn_1_530C8 */

/* fzgx:begin fn_1_535A0 */

/* font.h declares the packet colour as u8[4]; it holds a GXColor */

#define FN_1_535A0_COLOR(packet) (*(FontColor *)(packet).color)

void fn_1_535A0(FontColor color, f32 x, f32 y, f32 z, f32 width, f32 height, f32 thickness) {
    FontDrawPacket packet;

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y + height;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    packet.flags = 0xD;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
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
#undef FN_1_535A0_COLOR
/* fzgx:end fn_1_535A0 */

/* fzgx:begin fn_1_53830 */
/* WARNING: compiler-diff device, not original code (carried from main: 28 words without it). The volatile
   colour pointers and the volatile packed read keep retail's order (component stores, then the constant colour
   word loaded and stored); FontColor pointers with a plain struct copy, static/local/const constants and other
   spellings all hoist the constant load (vb/53830_v*.c). */

void fn_1_53830(u32 period, f32 x, u8 val, volatile u8 *a, volatile u8 *b) { /* volatile: carried device (WARNING above) */
    u32 t = lbl_801A66A0 % period;
    f32 f;
    u8 c;
    if (t < period / 2) {
        static const FontColor white = {0xFF, 0xFF, 0xFF, 0x00};
        f = lbl_8006D188((65536.0f * t / period));
        c = (val * f);
        a[2] = c;
        a[1] = c;
        a[0] = c;
        a[3] = 0;
        *(u32 *)b = *(volatile u32 *)&white; /* volatile: carried device (WARNING above) */
    } else {
        static const FontColor black = {0x00, 0x00, 0x00, 0x00};
        f = lbl_8006D188((65536.0f * t / period));
        f = ((1.0f - x) * f);
        f = 1.0f + f;
        c = (255.0f * f);
        b[2] = c;
        b[1] = c;
        b[0] = c;
        b[3] = 0;
        *(u32 *)a = *(volatile u32 *)&black; /* volatile: carried device (WARNING above) */
    }
}
/* fzgx:end fn_1_53830 */

/* fzgx:begin fn_1_539CC */
/* Placeholder: retail function stripped by the link; only its literals survive (.rodata 283C 80.0f and 2840
   60.0f, first used after fn_1_53830 and referenced by no retail code). Body unknown. */
static f32 sprite_scale_80_60(f32 x) {
    return x * 80.0f / 60.0f;
}

FontColor fn_1_539CC(const FontColor *a, const FontColor *b, f32 t) {
    FontColor color;
    color.r = a->r * t + b->r * ((1.0f) - t);
    color.g = a->g * t + b->g * ((1.0f) - t);
    color.b = a->b * t + b->b * ((1.0f) - t);
    color.a = a->a * t + b->a * ((1.0f) - t);
    return color;
}
/* fzgx:end fn_1_539CC */

/* fzgx:begin fn_1_53B14 */
void fn_1_53B14(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
    Fn53B14Params params = *(const Fn53B14Params *)&lbl_1_rodata_26F8;

    params.unk0 = 12;
    params.unk4 = a;
    params.unk8 = b;
    params.unkC = e;
    if (color != NULL) {
        params.unk2C = color[3] / 255.0;
        params.unk38 = *(u32 *)color;
    }
    params.unk30 = 10;
    fn_1_50190((void *)&params, c, d, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53B14 */

/* fzgx:begin fn_1_53BD8 */
void fn_1_53BD8(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
	Fn53BD8Params params = *(const Fn53BD8Params *)&lbl_1_rodata_26F8;

	params.unk0 = 2;
	params.unk4 = a;
	params.unk8 = b;
	params.unkC = e;
	if (color != NULL) {
		params.unk2C = ((f64)*(color + 3) / 255.0);
		params.unk38 = *(u32 *)color;
	}
	params.unk30 = 10;
	fn_1_50190((void *)&params, c, d, 13.0f, 13.0f, 26.0f, 26.0f);
}
/* fzgx:end fn_1_53BD8 */

/* fzgx:begin fn_1_53C9C */
void fn_1_53C9C(u8 *color, const char *id, f32 x, f32 y, f32 z, f32 s, f32 t)
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
    fn_1_4A0D8(id);
    tmp_call5 = fn_1_4B068(id);
    a = tmp_call5;
    s_local = s_local * t;
    a = s_local + a;
    b = s_local + fn_1_4B090(id);
    p = *(const Pk *)&lbl_1_rodata_26F8;
    p.a = 12;
    p.x = x;
    p.y = y;
    p.z = z;
    if (color != 0) {
        p.al = color[3] / 255.0;
        p.col = *(s32 *)color;
    }
    p.b = 10;
    fn_1_50190((void *)&p, a, b, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53C9C */

/* fzgx:begin fn_1_53E40 */
void fn_1_53E40(u8 *color, const char *name, f32 x, f32 y, f32 z, f32 w, f32 h)
{
	f32 total;
	f32 delta;

	if (z < 0.01f) {
		z = 0.01f;
	}
	fn_1_496FC(x, y);
	fn_1_4954C((z - 0.0005));
	fn_1_4955C(h, h);
	fn_1_495C8(9);
	fn_1_4A0D8(name);
	total = w * h + fn_1_4B068(name);
	delta = w * h + fn_1_4B090(name);

	{
		Record rec = *(const Record *)&lbl_1_rodata_26F8;

		rec.field_0 = 2;
		rec.field_4 = x;
		rec.field_8 = y;
		rec.field_c = z;
		if (color != 0) {
			rec.field_2c = (color[3] / 255.0);
			rec.field_38 = *(u32 *)color;
		}
		rec.field_30 = 10;

		fn_1_50190((void *)&rec, total, delta, 13.0f, 13.0f, 26.0f, 26.0f);
	}
}
/* fzgx:end fn_1_53E40 */

/* fzgx:begin fn_1_53FE4 */
/* WARNING: compiler-diff device, not original code (carried from main: 22 words in fn_1_53FE4 without it).
   Retail is the auto-inlined call fn_1_51678(packet, packet->image, x, y, 20, 20): that natural form is
   instruction-identical but 21 words off (packet/image and inv_width/inv_height registers swapped; the
   declaration orders that fix the inlined copy break fn_1_51678 itself). */
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
    ih = 1.0f / h;
    iw = 1.0f / w;
    obj->f10 = obj->f10 * (20.0f * ih);
    obj->f14 = obj->f14 * (20.0f * iw);
    obj->f18 = x * ih;
    obj->f1c = y * iw;
    obj->f20 = ih * (x + 20);
    obj->f24 = iw * (y + 20);
    fn_1_4F734((void *)((FontDrawPacket *)obj));
}

#pragma opt_propagation reset
/* fzgx:end fn_1_53FE4 */

/* fzgx:begin fn_1_5415C */
char *fn_1_5415C(u32 number, s32 column) {
    return fn_1_541A8(number, column);
}
/* fzgx:end fn_1_5415C */

/* fzgx:begin fn_1_5417C */
char *fn_1_5417C(u32 number) {
    return fn_1_541A8(number, lbl_801A66B4);
}
/* fzgx:end fn_1_5417C */

/* fzgx:begin fn_1_541A8 */
// Select the localized form for a number and column, including the special 10–20 range.

char *fn_1_541A8(u32 number, s32 column) {
    s32 is_special;
    u32 remainder;
    s32 row_index;
    char **row;

    if (number == 0) {
        return "";
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

    row = font_ordinal_suffix[row_index];
    return row[column < 0 ? 0 : (column > 5 ? 5 : column)];
}
/* fzgx:end fn_1_541A8 */

/* fzgx:begin fn_1_54278 */
void fn_1_54278(s32 arg0, s32 arg1) {
    lbl_1_bss_4C680 = arg0;
    lbl_1_bss_4C684 = arg1;
}
/* fzgx:end fn_1_54278 */

/* fzgx:begin fn_1_5428C */
void fn_1_5428C(f32 value) {
    lbl_1_data_1C508 = value;
}
/* fzgx:end fn_1_5428C */

/* fzgx:begin fn_1_54298 */
s32 fn_1_54298(void) {
    return lbl_1_bss_4C680;
}
/* fzgx:end fn_1_54298 */

/* fzgx:begin fn_1_542A8 */
s32 fn_1_542A8(void) {
    return lbl_1_bss_4C684;
}
/* fzgx:end fn_1_542A8 */

/* fzgx:begin fn_1_542B8 */
f32 fn_1_542B8(void) {
    return lbl_1_data_1C508;
}
/* fzgx:end fn_1_542B8 */
