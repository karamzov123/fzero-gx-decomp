#include "types.h"
#include "dolphin/types.h"
#define lbl_1_bss_4B9CC globals_h_lbl_1_bss_4B9CC
#include "rel/main_rel/globals.h"
#undef lbl_1_bss_4B9CC
#include "runtime/va_list.h"
#include "font.h"
#include "game/vec3.h"
#include "dolphin/hw_regs.h"
#include "mathutil_mtxA_translate_col.h"

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

/* fn_1_49794 */
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[0x10];
    f32 unk_28;
} UnkArg1;

/* font table entry, .data 1AEA8[44] */
typedef struct FontInfo {
    s32 image;
    u8 width;
    u8 height;
    s32 first;
    s32 last;
    s8 columns;
    s8 rows;
    f32 cell_w;
    f32 cell_h;
    f32 unk_1C;
    f32 unk_20;
    char *name;
    u16 tex_size;
    u16 *kana;
    s16 *kana_image;
    f32 scale;
} FontInfo;

/* character spacing table entry (.rodata 1100..2668) */
typedef struct FontKern {
    const char *glyph;
    s8 x;
    s8 width;
} FontKern;

/* fn_1_4A0D8 */
typedef struct FontState {
    f32 home_x;
    f32 x;
    f32 y;
    s16 font;
    s16 rotation;
    FontColor color;
    FontColor color_add;
    f32 z;
    f32 scale_x;
    f32 scale_y;
    f32 space_scale;
    f32 alpha;
    u32 flags;
    s16 width;
    s16 shadow_x;
    s16 shadow_y;
    u8 align;
    s8 page;
    f32 shadow_alpha;
    f32 spacing;
    f32 line_spacing;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    s16 unk_48;
    s16 unk_4A;
    s16 unk_4C;
    s16 unk_4E;
    f32 unk_50;
    u32 unk_54;
    u32 unk_58;
} FontState;

/* fn_1_4A0D8 */
typedef struct FontPacket {
    s32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    FontColor color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    u32 vertex_callback;
    f32 unk_54;
} FontPacket;

/* fn_1_4A0D8 */
typedef struct FontToggle {
    s32 enabled;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
} FontToggle;

/* fn_1_4AC20 */
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

/* fn_1_4B83C */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
} MsgData;

/* fn_1_4B83C */
typedef void (*ARQCallback)(u32);

/* fn_1_4B83C */
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

/* fn_1_4C16C */
typedef struct FontViewer {
    s8 font;
    s8 prev_font;
    s8 bold;
    s8 style;
    s8 page;
    u8 pad_5[3];
    s32 cursor;
} FontViewer;

/* fn_1_4D10C */
typedef struct fn_1_547F8_node_fn_1_4D10C {
    struct fn_1_547F8_node_fn_1_4D10C *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_4D10C *);
} fn_1_547F8_node_fn_1_4D10C;

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

/* fn_1_519FC */
typedef struct fn_1_547F8_node_fn_1_51E60 {
    struct fn_1_547F8_node_fn_1_51E60 *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_51E60 *);
} fn_1_547F8_node_fn_1_51E60;

/* fn_1_5233C */
typedef struct fn_1_547F8_node_fn_1_5233C {
    struct fn_1_547F8_node_fn_1_5233C *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_5233C *);
} fn_1_547F8_node_fn_1_5233C;

/* fn_1_52968 */
typedef struct fn_1_547F8_node_fn_1_535A0 {
    struct fn_1_547F8_node_fn_1_535A0 *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_535A0 *);
} fn_1_547F8_node_fn_1_535A0;

/* fn_1_549F4 */
typedef struct {
    f32 zero;
    f32 deg;
    f32 half;
    f32 pad_c;
    f64 one;
    f64 degd;
    f64 halfd;
} K;

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

extern u32 ARGetDMAStatus(void);
extern void ARQPostRequest(ARQRequest *, u32, u32, u32, void *, u32, u32, ARQCallback);
extern void DCFlushRange(void *, u32);
extern void DCInvalidateRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern u32 OSAllocFromArenaHi(u32, u32);
extern u32 OSAllocFromArenaLo(u32, u32);
extern u32 OSGetArenaHi(void);
extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);
extern void OSSetArenaHi(u32);
extern int __abs(int);
extern const FontPacket lbl_1_rodata_26F8;
extern u32 fn_1_45D0(void *, void *, char *, int);
extern void fn_1_46B4(u32, u32, void *, int);
extern void fn_1_47F74(s32);
extern void fn_1_48140(u16);
void fn_1_4B6D4(const FontPacket *pkt, const FontState *state, const FontInfo *font, f32 advance);
void fn_1_4B788(const FontPacket *pkt, const FontState *state, const FontInfo *font, f32 advance);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A6F1C(void);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8E78(const char *);
extern void fn_1_A8EB0(int, int);
extern s32 fn_80006B70(void *, void *);
extern u32 fn_80006D1C(MsgData *, void *, u32, u32);
extern u32 fn_80006DE8(MsgData *);
extern void *fn_80008BA8(void *, const void *, u32);
extern void fn_80008BEC(void *dst, int value, u32 size);
extern u32 fn_800206FC(u32);
extern u32 fn_8002071C(void);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800371F8(u32, FontColor);
extern void fn_80073778(void *, s32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern int fn_8008077C(char *buf, const char *format, __va_list args);
extern u16 lbl_1_bss_96A;
extern u16 lbl_1_bss_D58[12];
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(Vec3 *, Vec3 *);
extern u8 lbl_8015B100[];
extern s32 lbl_801A6410;
extern void mathutil_mtxA_rotate_z(s16);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *, const char *);
extern size_t strlen(const char *str);
extern int strncmp(const char *, const char *, size_t);

void fn_1_487EC(void);
int fn_1_48A0C(int ch, s32 idx, FontInfo *font, int noLoad);
void fn_1_48C28(int index);
void fn_1_48D80(fn_1_48D80_Sprite *sprite);
void fn_1_492F0(ShapeParams *arg, f32 out[4][3]);
void fn_1_49410(void);
void fn_1_494CC(u8 value);
void fn_1_494DC(s16 index);
void fn_1_49514(const FontColor *value);
void fn_1_49528(const FontColor *value);
void fn_1_4953C(s16 value);
void fn_1_4954C(f32 value);
void fn_1_4955C(f32 value1, f32 value2);
void fn_1_49590(f32 value);
void fn_1_495A0(f32 value);
void fn_1_495B0(u32 value);
void fn_1_495C8(u8 value);
void fn_1_495D8(u16 value1, u16 value2, f32 value3);
void fn_1_495FC(void);
void fn_1_49614(void);
void fn_1_4962C(void);
void fn_1_49644(void);
void fn_1_4965C(u8 value);
void fn_1_4966C(f32 value1, f32 value2);
void fn_1_49680(f32 value1, f32 value2);
void fn_1_496FC(f32 value1, f32 value2);
void fn_1_49714(f32 value1, f32 value2, f32 value3);
void fn_1_49728(u8 value);
void fn_1_49738(u32 value);
void fn_1_49748(f32 value);
void fn_1_49758(u8 value);
void fn_1_49768(u8 value);
void fn_1_49778(s16 value1, s16 value2, s16 value3, s16 value4);
u32 fn_1_49794(u32 c);
s32 fn_1_499BC(const u8 *value);
s32 fn_1_49B70(u8 *arg0, FontState *arg1);
u32 fn_1_49F08(u32 c, FontState *state, const FontInfo *font);
void fn_1_4AC20(FontPacket *value);
void fn_1_4AEB4(f32 value);
u32 fn_1_4AEC0(u32 value);
u32 fn_1_4AEE8(u32 value);
void fn_1_4AF10(const char *text);
void fn_1_4AF64(const char *format, ...);
f32 fn_1_4B040(const char *text);
f32 fn_1_4B068(const char *text);
f32 fn_1_4B090(const char *text);
s32 fn_1_4B16C(const char *text);
s32 fn_1_4B1A0(const char *text);
f32 fn_1_4B1D4(s32 mode, const char *str);
void fn_1_4B83C(void *arg0, void *arg1, u32 arg2, const char *arg3);
void fn_1_4B8BC(void);
void fn_1_4B8CC(void);
void fn_1_4B8DC(void);
void fn_1_4BA24(u8 arg0, s32 arg1, void *arg2);
void fn_1_4BB5C(void);
void fn_1_4BD48(void);
void fn_1_4BD4C(u32 unused0, u32 unused1, u32 unused2);
void fn_1_4C16C(void);
void fn_1_4CDE4(f32 *x, f32 *y);
void fn_1_4CE48(f32 limit, const char *text);
void fn_1_4CF3C(const char *format, f32 x, ...);
void fn_1_4D0A0(void);
void fn_1_4D0D4(FontColor *color, f32 value);
void fn_1_4D10C(FontColor *color, f32 p1, f32 p2);
void fn_1_4D274(FontColor *color, f32 value);
void fn_1_4D2AC(FontColor arg0, f32 arg1, f32 arg2);
void fn_1_4D494(void);
void fn_1_4D4C8(FontColor *color, f32 z, f32 ofs);
u8 *fn_1_4D784(s32 wordWrap, s32 hyphenate, s32 kinsoku, s32 width, u8 *out, const char *fmt, ...);
void fn_1_4DC20(void);
void fn_1_4DC6C(void);
u32 fn_1_4DCB8(u32 value);
void fn_1_4E0F4(void);
void fn_1_4E500(void);
void fn_1_4E638(s32 arg);
void fn_1_4E6F4(void);
s32 fn_1_4E724(FontParams *arg);
void fn_1_50164(f32 width, f32 height, f32 a, f32 b, FontPacket *packet);
f32 fn_1_519FC(f32 value);
f32 fn_1_51AC0(f32 value);
f32 fn_1_51B84(f32 value);
f32 fn_1_51BFC(f32 value);
void fn_1_53B14(FontColor *color, f32 a, f32 b, f32 c, f32 d, f32 e);

/* TU A .bss (tentative definitions: MWCC places them in first-access order) */
s32 lbl_1_bss_3E058 = 0;
f32 lbl_1_bss_3E05C = 0.0f;
u32 lbl_1_bss_3E060[0x56B];
s32 lbl_1_bss_3F60C[0x56B];
s32 lbl_1_bss_40BB8;
s32 lbl_1_bss_40BBC[0x2C];
GXTexObj lbl_1_bss_40C6C[0x56B];
FontState lbl_1_bss_4B9CC;
s32 lbl_1_bss_4BA28[2];
FontToggle lbl_1_bss_4BA30;
FontToggle lbl_1_bss_4BA44;
volatile s32 lbl_1_bss_4BA58; /* AR DMA completion flag, set by the ARQ callback and polled */
volatile s32 lbl_1_bss_4BA5C; /* AR DMA completion flag, set by the ARQ callback and polled */
u8 lbl_1_bss_4BA60[0x20];
u32 lbl_1_bss_4BA80[0x2C];
FontViewer lbl_1_bss_4BB30;
u8 lbl_1_bss_4BB3C;
FontState lbl_1_bss_4BB40;
/* never accessed by code: MWCC emits these last, in reverse definition order */
s16 lbl_1_bss_4BBA0[0x56C];
s16 lbl_1_bss_4BB9C[2];

/* TU A .data, retail order (base 1A3B8) */
u16 lbl_1_data_1A3B8[0x56C] = {
    0x8140, 0x8141, 0x8142, 0x8143, 0x8144, 0x8145, 0x8146, 0x8147, 0x8148, 0x8149, 0x814A, 0x814B,
    0x814C, 0x814D, 0x814F, 0x8151, 0x8158, 0x815B, 0x815E, 0x815F, 0x8160, 0x8162, 0x8163, 0x8165,
    0x8166, 0x8167, 0x8168, 0x8169, 0x816A, 0x816D, 0x816E, 0x816F, 0x8170, 0x8171, 0x8172, 0x8175,
    0x8176, 0x8177, 0x8178, 0x817B, 0x817C, 0x817E, 0x8181, 0x8183, 0x8184, 0x818F, 0x8190, 0x8193,
    0x8194, 0x8195, 0x8196, 0x8197, 0x819A, 0x81A0, 0x81A3, 0x81E7, 0x81E8, 0x81F4, 0x824F, 0x8250,
    0x8251, 0x8252, 0x8253, 0x8254, 0x8255, 0x8256, 0x8257, 0x8258, 0x8260, 0x8261, 0x8262, 0x8263,
    0x8264, 0x8265, 0x8266, 0x8267, 0x8268, 0x8269, 0x826A, 0x826B, 0x826C, 0x826D, 0x826E, 0x826F,
    0x8270, 0x8271, 0x8272, 0x8273, 0x8274, 0x8275, 0x8276, 0x8277, 0x8278, 0x8279, 0x8281, 0x8282,
    0x8283, 0x8284, 0x8285, 0x8286, 0x8287, 0x8288, 0x8289, 0x828A, 0x828B, 0x828C, 0x828D, 0x828E,
    0x828F, 0x8290, 0x8291, 0x8292, 0x8293, 0x8294, 0x8295, 0x8296, 0x8297, 0x8298, 0x8299, 0x829A,
    0x829F, 0x82A0, 0x82A1, 0x82A2, 0x82A3, 0x82A4, 0x82A5, 0x82A6, 0x82A7, 0x82A8, 0x82A9, 0x82AA,
    0x82AB, 0x82AC, 0x82AD, 0x82AE, 0x82AF, 0x82B0, 0x82B1, 0x82B2, 0x82B3, 0x82B4, 0x82B5, 0x82B6,
    0x82B7, 0x82B8, 0x82B9, 0x82BA, 0x82BB, 0x82BC, 0x82BD, 0x82BE, 0x82BF, 0x82C0, 0x82C1, 0x82C2,
    0x82C3, 0x82C4, 0x82C5, 0x82C6, 0x82C7, 0x82C8, 0x82C9, 0x82CA, 0x82CB, 0x82CC, 0x82CD, 0x82CE,
    0x82CF, 0x82D0, 0x82D1, 0x82D2, 0x82D3, 0x82D4, 0x82D5, 0x82D6, 0x82D7, 0x82D8, 0x82D9, 0x82DA,
    0x82DB, 0x82DC, 0x82DD, 0x82DE, 0x82DF, 0x82E0, 0x82E1, 0x82E2, 0x82E3, 0x82E4, 0x82E5, 0x82E6,
    0x82E7, 0x82E8, 0x82E9, 0x82EA, 0x82EB, 0x82EC, 0x82ED, 0x82EE, 0x82EF, 0x82F0, 0x82F1, 0x8340,
    0x8341, 0x8342, 0x8343, 0x8344, 0x8345, 0x8346, 0x8347, 0x8348, 0x8349, 0x834A, 0x834B, 0x834C,
    0x834D, 0x834E, 0x834F, 0x8350, 0x8351, 0x8352, 0x8353, 0x8354, 0x8355, 0x8356, 0x8357, 0x8358,
    0x8359, 0x835A, 0x835B, 0x835C, 0x835D, 0x835E, 0x835F, 0x8360, 0x8361, 0x8362, 0x8363, 0x8364,
    0x8365, 0x8366, 0x8367, 0x8368, 0x8369, 0x836A, 0x836B, 0x836C, 0x836D, 0x836E, 0x836F, 0x8370,
    0x8371, 0x8372, 0x8373, 0x8374, 0x8375, 0x8376, 0x8377, 0x8378, 0x8379, 0x837A, 0x837B, 0x837C,
    0x837D, 0x837E, 0x8380, 0x8381, 0x8382, 0x8383, 0x8384, 0x8385, 0x8386, 0x8387, 0x8388, 0x8389,
    0x838A, 0x838B, 0x838C, 0x838D, 0x838E, 0x838F, 0x8390, 0x8391, 0x8392, 0x8393, 0x8394, 0x8395,
    0x8396, 0x839F, 0x83A0, 0x83A1, 0x83A4, 0x83A6, 0x83AD, 0x83AF, 0x83B0, 0x83B2, 0x83B4, 0x83B5,
    0x83BF, 0x83D0, 0x88A4, 0x88AB, 0x88AC, 0x88B3, 0x88B5, 0x88B6, 0x88C0, 0x88C3, 0x88C8, 0x88CA,
    0x88CB, 0x88CC, 0x88CD, 0x88CF, 0x88D3, 0x88D5, 0x88D9, 0x88DA, 0x88DB, 0x88E1, 0x88E3, 0x88E6,
    0x88E7, 0x88EA, 0x88F3, 0x88F5, 0x88F6, 0x88F8, 0x88F9, 0x8940, 0x8941, 0x8945, 0x8946, 0x894A,
    0x895C, 0x895E, 0x8963, 0x8965, 0x8966, 0x8968, 0x8969, 0x8970, 0x897A, 0x897E, 0x8980, 0x8983,
    0x8984, 0x8985, 0x8987, 0x8989, 0x898A, 0x898E, 0x898F, 0x8993, 0x899C, 0x899E, 0x899F, 0x89A1,
    0x89A3, 0x89A4, 0x89AD, 0x89AE, 0x89AF, 0x89B1, 0x89B4, 0x89B7, 0x89B8, 0x89B9, 0x89BA, 0x89BB,
    0x89BC, 0x89BD, 0x89BF, 0x89C1, 0x89C2, 0x89C5, 0x89C6, 0x89C8, 0x89C9, 0x89CA, 0x89CC, 0x89CD,
    0x89D2, 0x89D4, 0x89D7, 0x89D8, 0x89DC, 0x89DD, 0x89DF, 0x89E4, 0x89E5, 0x89E6, 0x89EE, 0x89EF,
    0x89F0, 0x89F1, 0x89F3, 0x89F5, 0x89F6, 0x89F7, 0x89F9, 0x89FC, 0x8A42, 0x8A43, 0x8A44, 0x8A45,
    0x8A4A, 0x8A4D, 0x8A4F, 0x8A51, 0x8A58, 0x8A65, 0x8A67, 0x8A69, 0x8A6C, 0x8A6D, 0x8A6F, 0x8A70,
    0x8A77, 0x8A79, 0x8A7A, 0x8A7C, 0x8A84, 0x8A87, 0x8A88, 0x8AA3, 0x8AA8, 0x8AA9, 0x8AAA, 0x8AAC,
    0x8AAE, 0x8AAF, 0x8AB1, 0x8AB4, 0x8AB5, 0x8AB7, 0x8ABB, 0x8ABD, 0x8AC2, 0x8AC7, 0x8AC8, 0x8ACD,
    0x8ACF, 0x8AD3, 0x8AD4, 0x8AD6, 0x8AD7, 0x8AD9, 0x8ADB, 0x8ADC, 0x8AE2, 0x8AE6, 0x8AE7, 0x8AE8,
    0x8AE9, 0x8AEB, 0x8AEC, 0x8AED, 0x8AEE, 0x8AEF, 0x8AF0, 0x8AF1, 0x8AF3, 0x8AF6, 0x8AFA, 0x8AFC,
    0x8B40, 0x8B41, 0x8B43, 0x8B49, 0x8B4B, 0x8B4C, 0x8B4D, 0x8B4E, 0x8B51, 0x8B53, 0x8B56, 0x8B5A,
    0x8B5E, 0x8B60, 0x8B63, 0x8B6C, 0x8B71, 0x8B74, 0x8B78, 0x8B79, 0x8B7B, 0x8B7D, 0x8B7E, 0x8B81,
    0x8B85, 0x8B86, 0x8B89, 0x8B8B, 0x8B8C, 0x8B8E, 0x8B90, 0x8B91, 0x8B93, 0x8B96, 0x8B97, 0x8B9F,
    0x8BA3, 0x8BA4, 0x8BA5, 0x8BA6, 0x8BAD, 0x8BAF, 0x8BB0, 0x8BB3, 0x8BB5, 0x8BB6, 0x8BB9, 0x8BBB,
    0x8BBD, 0x8BBE, 0x8BBF, 0x8BC1, 0x8BC3, 0x8BC6, 0x8BC7, 0x8BC8, 0x8BC9, 0x8BCF, 0x8BD8, 0x8BD9,
    0x8BDE, 0x8BDF, 0x8BE0, 0x8BE2, 0x8BE3, 0x8BE5, 0x8BE6, 0x8BEA, 0x8BEC, 0x8BEF, 0x8BF0, 0x8BF2,
    0x8BF3, 0x8BF4, 0x8BF6, 0x8BFC, 0x8C4A, 0x8C4D, 0x8C4E, 0x8C50, 0x8C51, 0x8C52, 0x8C57, 0x8C59,
    0x8C5A, 0x8C5E, 0x8C5F, 0x8C60, 0x8C62, 0x8C68, 0x8C69, 0x8C6E, 0x8C6F, 0x8C70, 0x8C76, 0x8C78,
    0x8C79, 0x8C7C, 0x8C7D, 0x8C82, 0x8C83, 0x8C86, 0x8C87, 0x8C88, 0x8C8B, 0x8C8C, 0x8C8D, 0x8C8F,
    0x8C92, 0x8C95, 0x8C96, 0x8C99, 0x8C9A, 0x8CA0, 0x8CA4, 0x8CA8, 0x8CA9, 0x8CAB, 0x8CAD, 0x8CAF,
    0x8CB0, 0x8CB1, 0x8CB3, 0x8CB4, 0x8CB5, 0x8CB6, 0x8CB8, 0x8CB9, 0x8CBB, 0x8CBE, 0x8CC0, 0x8CC2,
    0x8CC3, 0x8CC4, 0x8CC5, 0x8CC7, 0x8CC8, 0x8CCB, 0x8CCC, 0x8CD6, 0x8CD9, 0x8CDD, 0x8CE2, 0x8CE3,
    0x8CE5, 0x8CEB, 0x8CF0, 0x8CF3, 0x8CF5, 0x8CF6, 0x8CF7, 0x8CF8, 0x8CFB, 0x8CFC, 0x8D44, 0x8D48,
    0x8D49, 0x8D4B, 0x8D4C, 0x8D4E, 0x8D52, 0x8D55, 0x8D58, 0x8D5A, 0x8D5C, 0x8D62, 0x8D6C, 0x8D72,
    0x8D73, 0x8D75, 0x8D77, 0x8D7E, 0x8D80, 0x8D82, 0x8D86, 0x8D87, 0x8D8B, 0x8D8F, 0x8D90, 0x8D91,
    0x8D93, 0x8D95, 0x8D96, 0x8D9C, 0x8D9E, 0x8DA0, 0x8DA1, 0x8DA2, 0x8DA5, 0x8DA6, 0x8DAA, 0x8DB0,
    0x8DB6, 0x8DB7, 0x8DB8, 0x8DC3, 0x8DC4, 0x8DC5, 0x8DC8, 0x8DCB, 0x8DCE, 0x8DCF, 0x8DD0, 0x8DD3,
    0x8DD5, 0x8DD7, 0x8DDA, 0x8DDB, 0x8DDD, 0x8DDE, 0x8DDF, 0x8DE0, 0x8DEC, 0x8DED, 0x8E40, 0x8E42,
    0x8E45, 0x8E4F, 0x8E51, 0x8E52, 0x8E59, 0x8E5A, 0x8E5D, 0x8E5E, 0x8E63, 0x8E64, 0x8E67, 0x8E68,
    0x8E69, 0x8E6A, 0x8E6C, 0x8E6D, 0x8E6E, 0x8E70, 0x8E71, 0x8E74, 0x8E75, 0x8E76, 0x8E77, 0x8E78,
    0x8E7B, 0x8E7E, 0x8E80, 0x8E84, 0x8E8A, 0x8E8B, 0x8E8E, 0x8E91, 0x8E95, 0x8E96, 0x8E97, 0x8E99,
    0x8E9A, 0x8E9D, 0x8E9E, 0x8E9F, 0x8EA1, 0x8EA6, 0x8EA9, 0x8EAB, 0x8EAE, 0x8EAF, 0x8EB8, 0x8EBA,
    0x8EBF, 0x8EC0, 0x8ECA, 0x8ECB, 0x8ECC, 0x8ECD, 0x8ED0, 0x8ED2, 0x8ED3, 0x8ED4, 0x8ED7, 0x8EDF,
    0x8EE1, 0x8EE3, 0x8EE5, 0x8EE6, 0x8EE7, 0x8EE8, 0x8EEA, 0x8EEB, 0x8EED, 0x8EEF, 0x8EF1, 0x8EF3,
    0x8EF5, 0x8EF6, 0x8EFB, 0x8EFC, 0x8F43, 0x8F45, 0x8F47, 0x8F49, 0x8F4B, 0x8F50, 0x8F51, 0x8F57,
    0x8F5A, 0x8F5B, 0x8F5C, 0x8F5D, 0x8F5F, 0x8F61, 0x8F62, 0x8F63, 0x8F64, 0x8F68, 0x8F6A, 0x8F6B,
    0x8F6E, 0x8F6F, 0x8F70, 0x8F74, 0x8F75, 0x8F80, 0x8F84, 0x8F87, 0x8F88, 0x8F89, 0x8F8A, 0x8F8F,
    0x8F91, 0x8F94, 0x8F95, 0x8F97, 0x8F98, 0x8F9C, 0x8F9D, 0x8F9E, 0x8F9F, 0x8FA4, 0x8FA7, 0x8FAA,
    0x8FAB, 0x8FAC, 0x8FAD, 0x8FB2, 0x8FB3, 0x8FB8, 0x8FBB, 0x8FC1, 0x8FC4, 0x8FC6, 0x8FC8, 0x8FCC,
    0x8FCD, 0x8FCE, 0x8FD0, 0x8FD5, 0x8FD8, 0x8FDA, 0x8FDC, 0x8FE1, 0x8FE3, 0x8FE4, 0x8FE6, 0x8FE8,
    0x8FEA, 0x8FED, 0x8FEE, 0x8FF3, 0x8FFC, 0x9041, 0x9044, 0x9045, 0x9046, 0x9047, 0x9048, 0x904A,
    0x904B, 0x904D, 0x9053, 0x9054, 0x9055, 0x9056, 0x905B, 0x905E, 0x905F, 0x9065, 0x9067, 0x9069,
    0x906C, 0x906E, 0x9073, 0x907D, 0x9084, 0x9085, 0x9087, 0x9088, 0x908B, 0x908C, 0x9094, 0x909D,
    0x90A2, 0x90A3, 0x90A6, 0x90A7, 0x90A8, 0x90AA, 0x90AB, 0x90AC, 0x90AD, 0x90AE, 0x90AF, 0x90B3,
    0x90B6, 0x90B7, 0x90B8, 0x90BA, 0x90BB, 0x90C0, 0x90C2, 0x90C3, 0x90C8, 0x90C9, 0x90CC, 0x90CD,
    0x90CE, 0x90CF, 0x90D1, 0x90D4, 0x90D5, 0x90D8, 0x90DA, 0x90DC, 0x90DD, 0x90E0, 0x90E1, 0x90E2,
    0x90E6, 0x90E7, 0x90E8, 0x90E9, 0x90EA, 0x90ED, 0x90F2, 0x90F3, 0x90F4, 0x90F5, 0x90F9, 0x90FC,
    0x9144, 0x9149, 0x914F, 0x9150, 0x9152, 0x9153, 0x915E, 0x915F, 0x9161, 0x9163, 0x9166, 0x9167,
    0x9168, 0x916E, 0x9172, 0x9177, 0x917A, 0x917B, 0x917D, 0x9180, 0x9181, 0x9188, 0x918A, 0x918D,
    0x9190, 0x9193, 0x9195, 0x9196, 0x9197, 0x9198, 0x919C, 0x919D, 0x91A0, 0x91A2, 0x91A4, 0x91A5,
    0x91A6, 0x91A7, 0x91A9, 0x91AA, 0x91AB, 0x91AC, 0x91AE, 0x91AF, 0x91B0, 0x91B1, 0x91B6, 0x91B8,
    0x91B9, 0x91BC, 0x91BD, 0x91C5, 0x91CA, 0x91CC, 0x91CE, 0x91D2, 0x91D4, 0x91D6, 0x91D8, 0x91DC,
    0x91DD, 0x91DE, 0x91DF, 0x91E0, 0x91E3, 0x91E4, 0x91E5, 0x91E6, 0x91E8, 0x91EC, 0x91F0, 0x91F5,
    0x9240, 0x9242, 0x9244, 0x9245, 0x924E, 0x9250, 0x9253, 0x9254, 0x9255, 0x9261, 0x9262, 0x9263,
    0x9265, 0x9266, 0x9269, 0x926A, 0x926B, 0x926D, 0x926E, 0x9270, 0x9275, 0x9276, 0x927A, 0x9281,
    0x9285, 0x9286, 0x9287, 0x9288, 0x9289, 0x928D, 0x9298, 0x9299, 0x92A1, 0x92A3, 0x92A6, 0x92A7,
    0x92AD, 0x92AE, 0x92B2, 0x92B4, 0x92B7, 0x92B8, 0x92BC, 0x92C0, 0x92C7, 0x92C9, 0x92CA, 0x92CD,
    0x92D7, 0x92E1, 0x92E8, 0x92E9, 0x92EA, 0x92ED, 0x92EF, 0x92F6, 0x9340, 0x9347, 0x9349, 0x934B,
    0x9353, 0x9354, 0x9356, 0x9357, 0x9358, 0x9359, 0x935C, 0x935D, 0x935F, 0x9360, 0x9364, 0x936E,
    0x936F, 0x9371, 0x9372, 0x9373, 0x9377, 0x9378, 0x937A, 0x937C, 0x9380, 0x9381, 0x938B, 0x9390,
    0x9396, 0x9399, 0x939A, 0x939D, 0x939E, 0x93A5, 0x93A6, 0x93AA, 0x93AC, 0x93AD, 0x93AE, 0x93AF,
    0x93B0, 0x93B7, 0x93B9, 0x93BA, 0x93BE, 0x93BF, 0x93C1, 0x93C6, 0x93C7, 0x93CB, 0x93CD, 0x93DD,
    0x93DF, 0x93E0, 0x93E4, 0x93EE, 0x93EF, 0x93F1, 0x93F7, 0x93FA, 0x93FC, 0x9440, 0x9443, 0x9445,
    0x9446, 0x944D, 0x944E, 0x944F, 0x9452, 0x9459, 0x945C, 0x945D, 0x9465, 0x9468, 0x946A, 0x9470,
    0x9472, 0x9473, 0x9474, 0x9477, 0x9479, 0x947A, 0x947B, 0x947C, 0x9483, 0x9484, 0x948E, 0x9492,
    0x9497, 0x949A, 0x94A0, 0x94AD, 0x94AF, 0x94B1, 0x94B2, 0x94B4, 0x94BA, 0x94BB, 0x94BC, 0x94BD,
    0x94C4, 0x94C5, 0x94C6, 0x94CC, 0x94D4, 0x94DA, 0x94DB, 0x94DE, 0x94DF, 0x94E2, 0x94E3, 0x94E4,
    0x94E5, 0x94E6, 0x94E9, 0x94ED, 0x94EF, 0x94F0, 0x94F1, 0x94F2, 0x94F5, 0x94F6, 0x94FC, 0x9543,
    0x954B, 0x9550, 0x9557, 0x9559, 0x955C, 0x955D, 0x9561, 0x9562, 0x9569, 0x956E, 0x9571, 0x9573,
    0x9574, 0x9576, 0x9577, 0x9578, 0x957A, 0x957B, 0x957C, 0x9581, 0x9582, 0x9583, 0x9584, 0x9589,
    0x958B, 0x9590, 0x9591, 0x9594, 0x9595, 0x9597, 0x959C, 0x959D, 0x959E, 0x95A0, 0x95A1, 0x95A5,
    0x95A8, 0x95AA, 0x95B1, 0x95B6, 0x95B7, 0x95BA, 0x95BD, 0x95BF, 0x95C0, 0x95C2, 0x95C7, 0x95CA,
    0x95CF, 0x95D0, 0x95D4, 0x95D9, 0x95DB, 0x95DF, 0x95E0, 0x95E2, 0x95E5, 0x95E6, 0x95EF, 0x95F1,
    0x95F3, 0x95F6, 0x95F8, 0x95F9, 0x95FA, 0x95FB, 0x9640, 0x964A, 0x964B, 0x964D, 0x964F, 0x9652,
    0x9653, 0x9656, 0x9657, 0x9659, 0x965C, 0x965D, 0x965F, 0x9660, 0x9666, 0x9668, 0x966C, 0x966E,
    0x9676, 0x967A, 0x967B, 0x9681, 0x9682, 0x9683, 0x9684, 0x9687, 0x9688, 0x9695, 0x9696, 0x969C,
    0x969D, 0x969E, 0x969F, 0x96A1, 0x96A2, 0x96A3, 0x96A7, 0x96AD, 0x96AF, 0x96B0, 0x96B1, 0x96B2,
    0x96B3, 0x96B6, 0x96BC, 0x96BD, 0x96BE, 0x96C5, 0x96CA, 0x96CD, 0x96D2, 0x96D7, 0x96D8, 0x96D9,
    0x96DA, 0x96DF, 0x96E2, 0x96E5, 0x96E9, 0x96EC, 0x96F0, 0x96F1, 0x96F3, 0x96F4, 0x96FC, 0x9741,
    0x9744, 0x9745, 0x9746, 0x974C, 0x9752, 0x9754, 0x9756, 0x9759, 0x975C, 0x975D, 0x975E, 0x975F,
    0x9761, 0x9763, 0x9765, 0x976C, 0x9770, 0x9774, 0x9776, 0x9778, 0x977A, 0x977B, 0x977D, 0x977E,
    0x9781, 0x9783, 0x9788, 0x978A, 0x978B, 0x978D, 0x978E, 0x9791, 0x9797, 0x9798, 0x979D, 0x97A0,
    0x97A3, 0x97A5, 0x97A6, 0x97A7, 0x97AC, 0x97AF, 0x97B3, 0x97B7, 0x97B9, 0x97BC, 0x97BF, 0x97C3,
    0x97C7, 0x97CA, 0x97CC, 0x97CD, 0x97CE, 0x97D6, 0x97DC, 0x97DE, 0x97DF, 0x97E1, 0x97E2, 0x97E7,
    0x97ED, 0x97EE, 0x97F0, 0x97F1, 0x97F3, 0x97F6, 0x97FB, 0x9841, 0x9843, 0x9849, 0x984A, 0x9851,
    0x9854, 0x9856, 0x9859, 0x985E, 0x985F, 0x9861, 0x9862, 0x9863, 0x9865, 0x9866, 0x9872, 0x9C66,
    0x9C72, 0x9D7C, 0xE0A3, 0xE0F8, 0xE3A9, 0xE690, 0xE8A6, 0x0000,
};
u16 lbl_1_data_1AE90[2] = {0, 0};
FontInfo lbl_1_data_1AEA8[44] = {
    {0x201, 28, 24, 0x30, 0x3A, 11, 1, 0.09090909f, 1.0f, 0.0032467532f, 0.041666668f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x205, 28, 24, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.007142857f, 0.020833334f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0xF, 8, 16, 0x20, 0x7A, 16, 6, 0.0625f, 0.125f, 0.0078125f, 0.0078125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0xE, 12, 12, 0x0, 0x7F, 16, 8, 0.0625f, 0.125f, 0.0052083335f, 0.010416667f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x7, 12, 14, 0x41, 0x5A, 8, 4, 0.125f, 0.25f, 0.010416667f, 0.017857144f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x8, 18, 18, 0x20, 0x73, 12, 7, 0.083333336f, 0.140625f, 0.0046296297f, 0.0078125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x8, 18, 18, 0x20, 0x73, 12, 7, 0.083333336f, 0.140625f, 0.0046296297f, 0.0078125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x3, 12, 16, 0x20, 0x7A, 12, 8, 0.083333336f, 0.125f, 0.0069444445f, 0.0078125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x4, 24, 24, 0x20, 0x7A, 12, 8, 0.083333336f, 0.125f, 0.0034722222f, 0.0052083335f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x890E, 8, 10, 0x41, 0x5A, 8, 4, 0.125f, 0.25f, 0.015625f, 0.025f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x944E, 24, 32, 0x30, 0x3D, 5, 3, 0.2f, 0.33333334f, 0.008333334f, 0.010416667f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9452, 24, 24, 0x31, 0x36, 3, 2, 0.33333334f, 0.5f, 0.013888889f, 0.020833334f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9427, 44, 56, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.0045454544f, 0.008928572f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9428, 16, 20, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.0125f, 0.025f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9433, 20, 20, 0x30, 0x3D, 5, 3, 0.2f, 0.33333334f, 0.01f, 0.016666668f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x942C, 24, 32, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.008333334f, 0.015625f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x942E, 60, 52, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.0033333334f, 0.009615385f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x943D, 72, 64, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.0027777778f, 0.0078125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9703, 16, 20, 0x30, 0x3B, 12, 1, 0.083333336f, 1.0f, 0.0052083335f, 0.05f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9731, 24, 32, 0x30, 0x3D, 5, 3, 0.2f, 0.33333334f, 0.008333334f, 0.010416667f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9733, 24, 24, 0x31, 0x36, 3, 2, 0.33333334f, 0.5f, 0.013888889f, 0.020833334f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x971A, 18, 20, 0x2C, 0x5A, 12, 4, 0.083333336f, 0.25f, 0.0046296297f, 0.0125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x971B, 12, 12, 0x2C, 0x5A, 12, 4, 0.083333336f, 0.25f, 0.0069444445f, 0.020833334f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x972D, 32, 36, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.00625f, 0.013888889f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x972E, 40, 44, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.005f, 0.011363637f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9811, 32, 24, 0x30, 0x3C, 5, 3, 0.2f, 0.33333334f, 0.00625f, 0.013888889f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9902, 8, 12, 0x30, 0x39, 10, 1, 0.1f, 1.0f, 0.0125f, 0.083333336f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9905, 10, 16, 0x30, 0x39, 10, 1, 0.08928572f, 1.0f, 0.008928572f, 0.0625f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9906, 12, 26, 0x2C, 0x5A, 12, 4, 0.083333336f, 0.25f, 0.0069444445f, 0.009615385f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x990A, 24, 32, 0x41, 0x5A, 10, 3, 0.1f, 0.33333334f, 0.004166667f, 0.010416667f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x990B, 12, 16, 0x41, 0x5A, 10, 4, 0.1f, 0.25f, 0.008333334f, 0.015625f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x990D, 8, 12, 0x30, 0x39, 10, 1, 0.1f, 1.0f, 0.0125f, 0.083333336f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9725, 20, 20, 0x30, 0x3D, 5, 3, 0.2f, 0.33333334f, 0.01f, 0.016666668f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9A1E, 16, 16, 0x41, 0x5A, 8, 4, 0.125f, 0.25f, 0.0078125f, 0.015625f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9A26, 16, 16, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.0125f, 0.03125f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9A07, 12, 26, 0x2C, 0x5A, 12, 4, 0.083333336f, 0.25f, 0.0069444445f, 0.009615385f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9E29, 24, 16, 0x30, 0x3C, 5, 3, 0.2f, 0.33333334f, 0.008333334f, 0.020833334f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9E22, 40, 52, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.005f, 0.009615385f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9E27, 56, 68, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.0035714286f, 0.007352941f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0x9F0A, 32, 24, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.00625f, 0.020833334f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0xBB02, 48, 36, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.004166667f, 0.013888889f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0xBB04, 32, 24, 0x30, 0x3C, 5, 3, 0.2f, 0.33333334f, 0.00625f, 0.013888889f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
    {0xFFFFFFFF, 24, 24, 0x0, 0x0, 1, 1, 1.0f, 1.0f, 0.041666668f, 0.041666668f, "asc_24x24", 0x120, lbl_1_data_1A3B8, lbl_1_bss_4BBA0, 1.0f},
    {0x9603, 24, 32, 0x30, 0x39, 5, 2, 0.2f, 0.5f, 0.008333334f, 0.015625f, "NULL", 0x0, lbl_1_data_1AE90, lbl_1_bss_4BB9C, 1.0f},
};
char *lbl_1_data_1BBC4[44] = {
    "FONT_ADVAC_CREDIT_NUM",
    "FONT_ADVAC_START_NUM",
    "FONT_ASC_8x16",
    "FONT_ASC_12x12",
    "FONT_ASC_14x16",
    "FONT_ASC_18x18",
    "FONT_ASC_18x18_TIME",
    "FONT_ASC_SEL_12x16",
    "FONT_ASC_SEL_24x24",
    "FONT_GAR_ASC_8x10",
    "FONT_RAC_ASC_TIME_NUM",
    "FONT_RAC_FACE_NUM",
    "FONT_RAC_RANK_NUM",
    "FONT_RAC_RANK_NUM_S",
    "FONT_RAC_VS_RANK_NUM",
    "FONT_RAC_SPEED_NUM",
    "FONT_RAC_TIME_AC",
    "FONT_RAC_TIME_AC_S",
    "FONT_RES_ASC",
    "FONT_RES_ASC_TIME_NUM",
    "FONT_RES_FACE_NUM",
    "FONT_RES_NAME_ASC",
    "FONT_RES_NAME_ASC_S",
    "FONT_RES_TIME_NUM",
    "FONT_RES_TIME_NUM_S",
    "FONT_RESAC_NUM",
    "FONT_RESGC_ASC_SS",
    "FONT_RESGC_ASC_Y",
    "FONT_RESGC_CUSTOM_FONT",
    "FONT_RESGC_PLATE_ASC",
    "FONT_RESGC_PLATE_ASC_S",
    "FONT_RESGC_V_ASC",
    "FONT_RES_VS_RANK_NUM",
    "FONT_SEL_NAME_ASC",
    "FONT_SEL_WEIGHT_NUM",
    "FONT_SEL_CUSTOM_FONT",
    "FONT_SELAC_DATA_NUM",
    "FONT_SELAC_TIME_NUM",
    "FONT_SELAC_TIME_NUM_S",
    "FONT_SELAF_COIN_NUM",
    "FONT_VIEW_LAP_NUM",
    "FONT_VIEW_NUM",
    "FONT_ASC_24x24",
    "FONT_REP_SPEED_NUM",
};
char *lbl_1_data_1BCAC[6] = {
    "ORIGINAL",
    "REGULAR",
    "BOLD",
    "ITALIC",
    "BOLD ITALIC",
    "TEGAKI",
};
s32 lbl_1_data_1BCC4 = 1;

/* fzgx:begin fn_1_487EC */
/* sprite corner offsets per shape (row 0 and 1: none), .rodata FD0 */
static const f32 lbl_1_rodata_FD0[6][8] = {
    {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {-1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f},
    {2.6f, 0.0f, 2.6f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {1.6f, -1.0f, 3.6f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f},
    {-1.4f, 3.7f, 1.3f, 0.0f, 1.6f, 0.5f, -0.9f, -0.8f},
};

void fn_1_487EC(void) {
    FontInfo *group;
    s32 i;
    FontInfo *target;
    s32 n;
    u16 key;
    u16 *q;
    u16 *p;
    s32 k;

    for (i = 0; i < 0x56B; i++) {
        lbl_1_bss_3E060[i] = 0;
        lbl_1_bss_3F60C[i] = -1;
    }

    /* count the entries of every terminator-marked group and reset their slots */
    lbl_1_bss_40BB8 = 0;
    group = lbl_1_data_1AEA8;
    for (i = 0; i < 0x2C; i++, group++) {
        lbl_1_bss_40BBC[i] = 0;
        if (group->image == -1) {
            p = group->kana;
            k = 0;
            while (*p != 0) {
                group->kana_image[k] = -1;
                p++;
                k++;
                lbl_1_bss_40BBC[i]++;
            }
        }
    }

    target = &lbl_1_data_1AEA8[42];
    for (i = 0; i < 0x56B; i++) {
        key = lbl_1_data_1A3B8[i];
        n = 0;
        q = target->kana;
        while (*q != 0) {
            if (*q == key && fn_1_48A0C(n, 0x2A, target, 1) != 0) {
                lbl_1_bss_40BB8++;
                break;
            }
            n++;
            q++;
        }
    }
}
/* fzgx:end fn_1_487EC */

/* fzgx:begin fn_1_48A0C */
int fn_1_48A0C(int ch, s32 idx, FontInfo *font, int noLoad) {
    s16 *slots;
    FontInfo *table;
    int tex;
    int i;
    u16 code;
    int fmt;

    slots = font->kana_image;
    if (slots[ch] != -1) {
        return 0;
    }
    table = lbl_1_data_1AEA8;
    for (i = 1; i < 44; i++) {
        FontInfo *other = &table[i];
        if (i != idx && other->image == -1 && other->kana_image[ch] != -1) {
            slots[ch] = other->kana_image[ch];
            return 0;
        }
    }

    tex = -1;
    for (i = 0; i < 0x56B; i++) {
        if (lbl_1_bss_3E060[i] == 0) {
            tex = i;
            break;
        }
    }
    if (tex == -1) {
        return 0;
    }

    if (noLoad) {
        lbl_1_bss_3E060[tex] = OSAllocFromArenaLo(font->tex_size, 0x20);
    } else {
        lbl_1_bss_3E060[tex] = fn_1_45D0((void *)lbl_801A6410, (void *)font->tex_size, "font.c", 0x14E);
    }
    if (lbl_1_bss_3E060[tex] == 0) {
        OSPanic("font.c", 0x150, "cannot OSAlloc at font_test_init\n");
    }
    fn_1_4BA24(idx, ch, (void *)lbl_1_bss_3E060[tex]);

    fmt = 0;
    code = font->kana[ch];
    if ((code >= 0x839F && code <= 0x83BE) || code == 0x8452) {
        fmt = 0xE;
    }
    GXInitTexObj(&lbl_1_bss_40C6C[tex], (void *)lbl_1_bss_3E060[tex], font->width, font->height, fmt, 0, 0, 0);
    font->kana_image[ch] = tex;
    if (noLoad) {
        lbl_1_bss_3F60C[tex] = -1;
    } else {
        lbl_1_bss_3F60C[tex] = lbl_801A6410;
    }
    return 1;
}
/* fzgx:end fn_1_48A0C */

/* fzgx:begin fn_1_48C28 */
void fn_1_48C28(int index) {
    s32 j;
    u16 *scan;
    FontInfo *entry;
    int i;

    entry = &lbl_1_data_1AEA8[index];
    if (entry->image != -1) {
        return;
    }

    scan = entry->kana;
    j = 0;
    while (*scan) {
        int found = 0;
        int id = entry->kana_image[j];
        if (id != -1 && lbl_1_bss_3F60C[id] != -1) {
            for (i = 1; i != 0x2c; i++) {
                FontInfo *other = &lbl_1_data_1AEA8[i];
                if (i == index) {
                    continue;
                }
                if (other->image == -1 && other->kana_image[j] != -1) {
                    found = 1;
                    break;
                }
            }
            if (found != 0) {
                entry->kana_image[j] = -1;
            } else {
                fn_1_46B4(lbl_801A6410, lbl_1_bss_3E060[id], "font.c", 0x217);
                id = entry->kana_image[j];
                lbl_1_bss_3E060[id] = 0;
                entry->kana_image[j] = -1;
            }
        }
        j++;
        scan = scan + 1;
    }
}
/* fzgx:end fn_1_48C28 */

/* fzgx:begin fn_1_48D80 */
/* Unreferenced in retail (no relocation reaches it): the printable ASCII set, .data 1BCF4 */
char lbl_1_data_1BCF4[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";


/* GX write-gather pipe: every store is a FIFO write */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)


void fn_1_48D80(fn_1_48D80_Sprite *sprite) {
    /* the font data block also holds the texture table and the assert strings */
    Vec3 *p2;
    Vec3 *p3;
    Vec3 *p1;
    u32 texId;
    u32 mode = sprite->flags;
    Vec3 v3;
    Vec3 v2;
    Vec3 v1;
    Vec3 v0;
    static const Vec3 initialV0 = {0.0f, 0.0f, 0.0f};
    static const Vec3 initialV1 = {0.0f, 0.0f, 0.0f};
    static const Vec3 initialV2 = {0.0f, 0.0f, 0.0f};
    static const Vec3 initialV3 = {0.0f, 0.0f, 0.0f};
    FontColor addColor;
    FontColor color;
    u32 id;
    u32 flags;
    f32 x;
    f32 y;
    f32 z;
    f32 width;
    f32 height;
    f32 u0;
    f32 u1;
    f32 t0;
    f32 t1;
    f64 half;

    v0 = initialV0;
    v1 = initialV1;
    v2 = initialV2;
    v3 = initialV3;
    p1 = &v1;
    p2 = &v2;
    p3 = &v3;
    fn_1_4E638(mode & 0x40000);
    id = sprite->id;
    z = -sprite->z;
{
    FontInfo *font;
    font = &lbl_1_data_1AEA8[(id >> 16) & 0xFF];
    texId = id & 0xFFFF;
    x = sprite->x;
    width = font->width;
    y = sprite->y;
    height = font->height;
}

    switch (sprite->flags & 3) {
    case 1:
    default:
        v3.x = width;
        v2.x = 0.0f;
        v0.x = 0.0f;
        v1.x = width;
        break;
    case 2:
        half = 0.5;
        v0.x = v2.x = -width * half;
        v1.x = v3.x = width * half;
        break;
    case 3:
        v3.x = 0.0f;
        v2.x = -width;
        v0.x = -width;
        v1.x = 0.0f;
        break;
    }

    switch ((sprite->flags >> 2) & 3) {
    case 1:
    default:
        v3.y = height;
        v1.y = 0.0f;
        v0.y = 0.0f;
        v2.y = height;
        break;
    case 2:
        half = 0.5;
        v0.y = v1.y = -height * half;
        v2.y = v3.y = height * half;
        break;
    case 3:
        v3.y = 0.0f;
        v1.y = -height;
        v0.y = -height;
        v2.y = 0.0f;
        break;
    }

    if ((sprite->flags & 0x8000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(sprite->offsetX, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        mathutil_mtxA_translate_x(-sprite->offsetX);
        lbl_8006E0B4(x, y, 0.0f);
    } else {
        lbl_8006D7F4(x, y, 0.0f);
    }
    mathutil_mtxA_rotate_z(-sprite->rot);
    lbl_8006E15C(sprite->scaleX, sprite->scaleY, 1.0f);
    lbl_8006E1B0(&v0, &v0);
    lbl_8006E1B0(p1, p1);
    lbl_8006E1B0(p2, p2);
    lbl_8006E1B0(p3, p3);
    fn_1_492F0((void *)sprite, (void *)&v0);
    fn_80073778(&lbl_1_bss_40C6C[texId], 0);

    if (sprite->flags & 0x10000000) {
        color.r = sprite->color.r;
        color.g = sprite->color.g;
        color.b = sprite->color.b;
        color.a = 255.0f * sprite->alpha;
        fn_800371F8(1, color);
        fn_800371F8(2, sprite->addColor);
    } else {
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 255.0f * sprite->alpha;
        addColor.r = sprite->color.r + sprite->addColor.r;
        addColor.g = sprite->color.g + sprite->addColor.g;
        addColor.b = sprite->color.b + sprite->addColor.b;
        addColor.a = 0;
        fn_800371F8(1, color);
        fn_800371F8(2, addColor);
    }

    u0 = sprite->u0;
    u1 = sprite->u1;
    t0 = sprite->v0;
    t1 = sprite->v1;
    if (sprite->flags & 0x4000000) {
        if (sprite->draw != NULL) {
            sprite->draw(sprite, &v0);
        } else {
            OSPanic("font.c", 740, "TEXSprPut_Sub : No registration of CALL_BACK.\n");
        }
    }

    fn_8003462C(0x80, 7, 4);
    /* WARNING: compiler-diff device, not original code (carried from main): the two volatile reads
     * order the first coordinate and the flag snapshot with the FIFO submission. */
    {
        f32 firstX = *(volatile f32 *)&v0.x; /* ordered submission snapshot */
        flags = *(volatile u32 *)&sprite->flags; /* ordered submission snapshot */
        GX_FIFO_F32 = firstX;
    }
    GX_FIFO_F32 = v0.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u0;
    GX_FIFO_F32 = t0;
    GX_FIFO_F32 = v1.x;
    GX_FIFO_F32 = v1.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u1;
    GX_FIFO_F32 = t0;
    GX_FIFO_F32 = v3.x;
    GX_FIFO_F32 = v3.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u1;
    GX_FIFO_F32 = t1;
    GX_FIFO_F32 = v2.x;
    GX_FIFO_F32 = v2.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u0;
    GX_FIFO_F32 = t1;

    if (flags & 0x4000000) {
        fn_1_4E0F4();
        fn_80074188(0, 0, fn_1_A5D88(), fn_1_A5DB0());
    }
}
#undef GX_FIFO_F32
/* fzgx:end fn_1_48D80 */

/* fzgx:begin fn_1_492F0 */
void fn_1_492F0(ShapeParams *arg, f32 out[4][3])
{
    f32 width = 1.0f + arg->width;
    f32 height = 1.0f + arg->height;
    s32 index = (s8)(arg->flags >> 24);
    if (index) {
        const f32 *row = lbl_1_rodata_FD0[index];
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
static const FontColor lbl_1_rodata_10E8 = {0xFF, 0xFF, 0xFF, 0xFF};
static const FontColor lbl_1_rodata_10EC = {0x00, 0x00, 0x00, 0x00};

void fn_1_49410(void) {
    lbl_1_bss_4B9CC.font = 42;
    lbl_1_bss_4B9CC.color = lbl_1_rodata_10E8;
    lbl_1_bss_4B9CC.color_add = lbl_1_rodata_10EC;
    lbl_1_bss_4B9CC.rotation = 0;
    lbl_1_bss_4B9CC.z = 0.05f;
    lbl_1_bss_4B9CC.scale_x = 1.0f;
    lbl_1_bss_4B9CC.scale_y = 1.0f;
    lbl_1_bss_4B9CC.space_scale = 1.0f;
    lbl_1_bss_4B9CC.alpha = 1.0f;
    lbl_1_bss_4B9CC.flags = 0;
    lbl_1_bss_4B9CC.align = 0;
    lbl_1_bss_4B9CC.width = 0;
    lbl_1_bss_4B9CC.shadow_x = 2;
    lbl_1_bss_4B9CC.shadow_y = 2;
    lbl_1_bss_4B9CC.shadow_alpha = 0.75f;
    lbl_1_bss_4B9CC.page = 0;
    lbl_1_bss_4B9CC.spacing = 0.0f;
    lbl_1_bss_4B9CC.line_spacing = 0.0f;
    lbl_1_bss_4B9CC.unk_44 = 1;
    lbl_1_bss_4B9CC.unk_45 = 0;
    lbl_1_bss_4B9CC.unk_54 = 0;
    lbl_1_bss_4B9CC.unk_50 = 0.0f;
    lbl_1_bss_4B9CC.unk_46 = 0;
    lbl_1_bss_4B9CC.unk_47 = 0;
    lbl_1_bss_4B9CC.unk_48 = 0;
    lbl_1_bss_4B9CC.unk_4A = 0;
    lbl_1_bss_4B9CC.unk_4C = 640;
    lbl_1_bss_4B9CC.unk_4E = 480;
    lbl_1_bss_4B9CC.unk_58 = 5;
}
/* fzgx:end fn_1_49410 */

/* fzgx:begin fn_1_494CC */
void fn_1_494CC(u8 value) {
    lbl_1_bss_4B9CC.unk_44 = value;
}
/* fzgx:end fn_1_494CC */

/* fzgx:begin fn_1_494DC */
void fn_1_494DC(s16 index) {
    lbl_1_bss_4B9CC.font = index;
    fn_1_4955C(1.0f, 1.0f);
}
/* fzgx:end fn_1_494DC */

/* fzgx:begin fn_1_49514 */
void fn_1_49514(const FontColor *value) {
    lbl_1_bss_4B9CC.color = *value;
}
/* fzgx:end fn_1_49514 */

/* fzgx:begin fn_1_49528 */
void fn_1_49528(const FontColor *value) {
    lbl_1_bss_4B9CC.color_add = *value;
}
/* fzgx:end fn_1_49528 */

/* fzgx:begin fn_1_4953C */
void fn_1_4953C(s16 value) {
    lbl_1_bss_4B9CC.rotation = value;
}
/* fzgx:end fn_1_4953C */

/* fzgx:begin fn_1_4954C */
void fn_1_4954C(f32 value) {
    lbl_1_bss_4B9CC.z = value;
}
/* fzgx:end fn_1_4954C */

/* fzgx:begin fn_1_4955C */
void fn_1_4955C(f32 value1, f32 value2) {
    FontInfo *font = &lbl_1_data_1AEA8[lbl_1_bss_4B9CC.font];

    // Scale both font dimensions using the active font's metrics.
    lbl_1_bss_4B9CC.scale_x = value1 * font->scale;
    lbl_1_bss_4B9CC.scale_y = value2 * font->scale;
}
/* fzgx:end fn_1_4955C */

/* fzgx:begin fn_1_49590 */
void fn_1_49590(f32 value) {
    lbl_1_bss_4B9CC.space_scale = value;
}
/* fzgx:end fn_1_49590 */

/* fzgx:begin fn_1_495A0 */
void fn_1_495A0(f32 value) {
    lbl_1_bss_4B9CC.alpha = value;
}
/* fzgx:end fn_1_495A0 */

/* fzgx:begin fn_1_495B0 */
void fn_1_495B0(u32 value) {
    lbl_1_bss_4B9CC.flags |= value;
}
/* fzgx:end fn_1_495B0 */

/* fzgx:begin fn_1_495C8 */
void fn_1_495C8(u8 value) {
    // Update the current font state flag.
    lbl_1_bss_4B9CC.align = value;
}
/* fzgx:end fn_1_495C8 */

/* fzgx:begin fn_1_495D8 */
void fn_1_495D8(u16 value1, u16 value2, f32 value3) {
    lbl_1_bss_4B9CC.shadow_x = value1;
    lbl_1_bss_4B9CC.flags |= 0x40000000;
    lbl_1_bss_4B9CC.shadow_y = value2;
    lbl_1_bss_4B9CC.shadow_alpha = value3;
}
/* fzgx:end fn_1_495D8 */

/* fzgx:begin fn_1_495FC */
void fn_1_495FC(void) {
    lbl_1_bss_4B9CC.flags |= 0x40000000;
}
/* fzgx:end fn_1_495FC */

/* fzgx:begin fn_1_49614 */
void fn_1_49614(void) {
    lbl_1_bss_4B9CC.flags &= 0xBFFFFFFF;
}
/* fzgx:end fn_1_49614 */

/* fzgx:begin fn_1_4962C */
void fn_1_4962C(void) {
    lbl_1_bss_4B9CC.flags |= 0x20000000;
}
/* fzgx:end fn_1_4962C */

/* fzgx:begin fn_1_49644 */
void fn_1_49644(void) {
    lbl_1_bss_4B9CC.flags &= 0xDFFFFFFF;
}
/* fzgx:end fn_1_49644 */

/* fzgx:begin fn_1_4965C */
void fn_1_4965C(u8 value) {
    lbl_1_bss_4B9CC.page = value;
}
/* fzgx:end fn_1_4965C */

/* fzgx:begin fn_1_4966C */
void fn_1_4966C(f32 value1, f32 value2) {
    // Store the two font scale values used by the renderer.
    lbl_1_bss_4B9CC.spacing = value1;
    lbl_1_bss_4B9CC.line_spacing = value2;
}
/* fzgx:end fn_1_4966C */

/* fzgx:begin fn_1_49680 */
// Scale the active font entry's byte dimensions into the shared bounds.

void fn_1_49680(f32 value1, f32 value2) {
    FontInfo *entry;
    s16 index;
    f32 result1;
    f32 result2;

    index = lbl_1_bss_4B9CC.font;
    entry = &lbl_1_data_1AEA8[index];
    result1 = entry->scale * (value1 * entry->width);
    result2 = entry->scale * (value2 * entry->height);
    lbl_1_bss_4B9CC.x = result1;
    lbl_1_bss_4B9CC.home_x = result1;
    lbl_1_bss_4B9CC.y = result2;
}
/* fzgx:end fn_1_49680 */

/* fzgx:begin fn_1_496FC */
// Store the two font coordinates in the shared state.

void fn_1_496FC(f32 value1, f32 value2) {
    lbl_1_bss_4B9CC.x = value1;
    lbl_1_bss_4B9CC.home_x = value1;
    lbl_1_bss_4B9CC.y = value2;
}
/* fzgx:end fn_1_496FC */

/* fzgx:begin fn_1_49714 */
void fn_1_49714(f32 value1, f32 value2, f32 value3) {
    lbl_1_bss_4B9CC.home_x = value3;
    lbl_1_bss_4B9CC.x = value1;
    lbl_1_bss_4B9CC.y = value2;
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
        if (lbl_1_bss_3E058 == 0) {
            return 0x816D;
        }
        break;
    case '\\':
        return 0x815F;
    case ']':
        if (lbl_1_bss_3E058 == 0) {
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
s32 fn_1_499BC(const u8 *value) {
    s32 result;
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
            break;
        case '1':
            result = (result | (1 << shift)) & 0xFFFF;
            break;
        case '2':
            result = (result | (2 << shift)) & 0xFFFF;
            break;
        case '3':
            result = (result | (3 << shift)) & 0xFFFF;
            break;
        case '4':
            result = (result | (4 << shift)) & 0xFFFF;
            break;
        case '5':
            result = (result | (5 << shift)) & 0xFFFF;
            break;
        case '6':
            result = (result | (6 << shift)) & 0xFFFF;
            break;
        case '7':
            result = (result | (7 << shift)) & 0xFFFF;
            break;
        case '8':
            result = (result | (8 << shift)) & 0xFFFF;
            break;
        case '9':
            result = (result | (9 << shift)) & 0xFFFF;
            break;
        case 'a':
            result = (result | (10 << shift)) & 0xFFFF;
            break;
        case 'b':
            result = (result | (11 << shift)) & 0xFFFF;
            break;
        case 'c':
            result = (result | (12 << shift)) & 0xFFFF;
            break;
        case 'd':
            result = (result | (13 << shift)) & 0xFFFF;
            break;
        case 'e':
            result = (result | (14 << shift)) & 0xFFFF;
            break;
        case 'f':
            result = (result | (15 << shift)) & 0xFFFF;
            break;
        default:
            break;
        }
        shift -= 4;
    }
    return result;
}
/* fzgx:end fn_1_499BC */

/* fzgx:begin fn_1_49B70 */
s32 fn_1_49B70(u8 *arg0, FontState *arg1) {
    u32 flags;
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
        mode = (((0x62 - c1) | (c1 - 0x62)) >> 31);
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
            arg1->color = *(FontColor *)&flags;
        }
        break;
    case 1:
        if (arg1 != NULL) {
            arg1->color_add = *(FontColor *)&flags;
        }
        break;
    case 2:
        if (arg1 != NULL) {
            arg1->alpha = flags / 255.0f;
        }
        break;
    }
    return ret;
}
/* fzgx:end fn_1_49B70 */

/* fzgx:begin fn_1_49F08 */
/* Placeholder: retail function stripped by the link; body reconstructed from its literals */
/* Its only trace is the signed int-to-float constant .rodata 10F8, emitted before fn_1_49F08's tables. */
static f32 font_int_to_float(s32 value) {
    return value;
}

/* The advance of character c: the font width, scaled for a space; with flag bit 31 the entry of c in the
 * spacing table of the current font, as (x << 16) | width. */
u32 fn_1_49F08(u32 c, FontState *state, const FontInfo *font) {
    static const FontKern lbl_1_rodata_1100[] = {
        {" ", 0, 13}, {"'", 7, 13}, {"\201A", 1, 11}, {"\201B", 1, 12}, {"\201C", 2, 7}, {"\201D", 2, 7},
        {"\201E", 8, 9}, {"\201L", 8, 9}, {"\201e", 16, 8}, {"\201f", 1, 8}, {"\201g", 13, 11}, {"\201h", 1, 11},
        {"\201j", 1, 10}, {"\201i", 12, 10}, {"\201|", 6, 14}, {"\202\201", 5, 15}, {"\202\202", 5, 15}, {"\202\203", 5, 15},
        {"\202\204", 4, 16}, {"\202\205", 5, 15}, {"\202\206", 7, 11}, {"\202\207", 4, 16}, {"\202\210", 5, 15}, {"\202\211", 9, 7},
        {"\202\212", 6, 10}, {"\202\213", 6, 15}, {"\202\214", 9, 7}, {"\202\215", 3, 20}, {"\202\216", 5, 15}, {"\202\217", 4, 16},
        {"\202\220", 5, 15}, {"\202\221", 4, 16}, {"\202\222", 7, 11}, {"\202\223", 5, 14}, {"\202\224", 7, 11}, {"\202\225", 5, 15},
        {"\202\226", 5, 15}, {"\202\227", 2, 21}, {"\202\230", 5, 15}, {"\202\231", 5, 15}, {"\202\232", 5, 15}, {"\202`", 4, 17},
        {"\202a", 5, 16}, {"\202b", 4, 17}, {"\202c", 4, 18}, {"\202d", 5, 15}, {"\202e", 5, 15}, {"\202f", 4, 17},
        {"\202g", 4, 17}, {"\202h", 9, 7}, {"\202i", 5, 12}, {"\202j", 5, 17}, {"\202k", 6, 14}, {"\202l", 2, 20},
        {"\202m", 4, 17}, {"\202n", 4, 18}, {"\202o", 5, 16}, {"\202p", 4, 18}, {"\202q", 5, 16}, {"\202r", 6, 15},
        {"\202s", 6, 14}, {"\202t", 4, 17}, {"\202u", 5, 17}, {"\202v", 1, 23}, {"\202w", 3, 18}, {"\202x", 4, 17},
        {"\202y", 4, 16}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1320[] = {
        {"0", 0, 22}, {"1", 0, 22}, {"2", 0, 22}, {"3", 0, 22}, {"4", 0, 22}, {"5", 0, 22},
        {"6", 0, 22}, {"7", 0, 22}, {"8", 0, 22}, {"9", 0, 22}, {":", 0, 22}, {";", 0, 22},
        {"<", 0, 9}, {"=", 0, 13}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1398[] = {
        {"0", 0, 22}, {"1", 0, 22}, {"2", 0, 22}, {"3", 0, 22}, {"4", 0, 22}, {"5", 0, 22},
        {"6", 0, 22}, {"7", 0, 22}, {"8", 0, 22}, {"9", 0, 22}, {":", 0, 22}, {";", 0, 22},
        {"<", 0, 9}, {"=", 0, 13}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1410[] = {
        {"A", 1, 14}, {"B", 2, 12}, {"C", 2, 12}, {"D", 2, 12}, {"E", 2, 12}, {"F", 2, 12},
        {"G", 2, 12}, {"H", 1, 14}, {"I", 4, 8}, {"J", 2, 12}, {"K", 1, 14}, {"L", 2, 12},
        {"M", 1, 14}, {"N", 1, 14}, {"O", 2, 12}, {"P", 2, 12}, {"Q", 2, 12}, {"R", 2, 12},
        {"S", 2, 12}, {"T", 2, 12}, {"U", 1, 14}, {"V", 1, 14}, {"W", 1, 14}, {"X", 1, 14},
        {"Y", 1, 14}, {"Z", 2, 12}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_14E8[] = {
        {"A", 0, 25}, {"B", 0, 23}, {"C", 0, 23}, {"D", 0, 23}, {"E", 0, 18}, {"F", 0, 17},
        {"G", 0, 23}, {"H", 0, 23}, {"I", 0, 11}, {"J", 0, 15}, {"K", 0, 24}, {"L", 0, 17},
        {"M", 0, 29}, {"N", 0, 21}, {"O", 0, 23}, {"P", 0, 21}, {"Q", 0, 23}, {"R", 0, 22},
        {"S", 0, 24}, {"T", 0, 23}, {"U", 0, 23}, {"V", 0, 25}, {"W", 0, 31}, {"X", 0, 24},
        {"Y", 0, 23}, {"Z", 0, 19}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_15C0[] = {
        {"A", 0, 11}, {"B", 0, 11}, {"C", 0, 11}, {"D", 0, 11}, {"E", 0, 9}, {"F", 0, 9},
        {"G", 0, 11}, {"H", 0, 11}, {"I", 0, 6}, {"J", 0, 8}, {"K", 0, 11}, {"L", 0, 8},
        {"M", 0, 13}, {"N", 0, 11}, {"O", 0, 11}, {"P", 0, 11}, {"Q", 0, 11}, {"R", 0, 11},
        {"S", 0, 11}, {"T", 0, 11}, {"U", 0, 11}, {"V", 0, 11}, {"W", 0, 15}, {"X", 0, 11},
        {"Y", 0, 11}, {"Z", 0, 9}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1698[] = {
        {"0", 0, 16}, {"1", 0, 16}, {"2", 0, 16}, {"3", 0, 16}, {"4", 0, 16}, {"5", 0, 16},
        {"6", 0, 16}, {"7", 0, 16}, {"8", 0, 16}, {"9", 0, 16}, {":", 0, 8}, {";", 0, 14},
        {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1700[] = {
        {",", 0, 13}, {"-", 0, 13}, {".", 0, 13}, {"/", 0, 13}, {"0", 0, 13}, {"1", 0, 13},
        {"2", 0, 13}, {"3", 0, 13}, {"4", 0, 13}, {"5", 0, 13}, {"6", 0, 13}, {"7", 0, 13},
        {"8", 0, 13}, {"9", 0, 13}, {":", 0, 13}, {";", 0, 13}, {"[", 0, 13}, {"]", 0, 13},
        {"_", 0, 13}, {"?", 0, 13}, {" ", 0, 13}, {"A", 0, 13}, {"B", 0, 13}, {"C", 0, 13},
        {"D", 0, 13}, {"E", 0, 13}, {"F", 0, 13}, {"G", 0, 13}, {"H", 0, 13}, {"I", 0, 6},
        {"J", 0, 13}, {"K", 0, 13}, {"L", 0, 13}, {"M", 0, 15}, {"N", 0, 13}, {"O", 0, 13},
        {"P", 0, 13}, {"Q", 0, 13}, {"R", 0, 13}, {"S", 0, 13}, {"T", 0, 13}, {"U", 0, 13},
        {"V", 0, 13}, {"W", 0, 15}, {"X", 0, 13}, {"Y", 0, 13}, {"Z", 0, 13}, {"[", 0, 5},
        {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1888[] = {
        {",", 0, 9}, {"-", 0, 9}, {".", 0, 9}, {"/", 0, 9}, {"0", 0, 9}, {"1", 0, 9},
        {"2", 0, 9}, {"3", 0, 9}, {"4", 0, 9}, {"5", 0, 9}, {"6", 0, 9}, {"7", 0, 9},
        {"8", 0, 9}, {"9", 0, 9}, {":", 0, 9}, {";", 0, 9}, {"[", 0, 9}, {"]", 0, 9},
        {"_", 0, 9}, {"?", 0, 9}, {" ", 0, 9}, {"A", 0, 9}, {"B", 0, 9}, {"C", 0, 9},
        {"D", 0, 9}, {"E", 0, 9}, {"F", 0, 9}, {"G", 0, 9}, {"H", 0, 9}, {"I", 0, 5},
        {"J", 0, 9}, {"K", 0, 9}, {"L", 0, 9}, {"M", 0, 11}, {"N", 0, 9}, {"O", 0, 9},
        {"P", 0, 9}, {"Q", 0, 9}, {"R", 0, 9}, {"S", 0, 9}, {"T", 0, 9}, {"U", 0, 9},
        {"V", 0, 9}, {"W", 0, 11}, {"X", 0, 9}, {"Y", 0, 9}, {"Z", 0, 9}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1A08[] = {
        {"0", 0, 25}, {"1", 0, 25}, {"2", 0, 25}, {"3", 0, 25}, {"4", 0, 25}, {"5", 0, 25},
        {"6", 0, 25}, {"7", 0, 25}, {"8", 0, 25}, {"9", 0, 25}, {":", -3, 7}, {";", -3, 5},
        {"<", -3, 9}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1A78[] = {
        {"0", 0, 17}, {"1", 0, 17}, {"2", 0, 17}, {"3", 0, 17}, {"4", 0, 17}, {"5", 0, 17},
        {"6", 0, 17}, {"7", 0, 17}, {"8", 0, 17}, {"9", 0, 17}, {":", -2, 5}, {";", -2, 3},
        {"<", -2, 6}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1AE8[] = {
        {"0", 0, 26}, {"1", 0, 26}, {"2", 0, 26}, {"3", 0, 26}, {"4", 0, 26}, {"5", 0, 26},
        {"6", 0, 26}, {"7", 0, 26}, {"8", 0, 26}, {"9", 0, 26}, {":", -3, 12}, {";", -3, 8},
        {"<", -3, 10}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1B58[] = {
        {" ", 0, 12}, {"!", 0, 2}, {" ", 0, 12}, {" ", 0, 12}, {" ", 0, 12}, {" ", 0, 12},
        {"&", 0, 10}, {"'", 0, 2}, {"(", 0, 4}, {")", 0, 4}, {" ", 0, 12}, {" ", 0, 12},
        {",", 0, 2}, {"-", 0, 6}, {".", 0, 2}, {"/", 0, 6}, {"0", 0, 8}, {"1", 0, 6},
        {"2", 0, 8}, {"3", 0, 8}, {"4", 0, 8}, {"5", 0, 8}, {"6", 0, 8}, {"7", 0, 8},
        {"8", 0, 8}, {"9", 0, 8}, {":", 0, 2}, {";", 0, 2}, {"[", 0, 4}, {"]", 0, 4},
        {"_", 0, 6}, {"?", 0, 6}, {" ", 0, 12}, {"A", 0, 10}, {"B", 0, 8}, {"C", 0, 8},
        {"D", 0, 8}, {"E", 0, 6}, {"F", 0, 6}, {"G", 0, 8}, {"H", 0, 8}, {"I", 0, 6},
        {"J", 0, 6}, {"K", 0, 8}, {"L", 0, 6}, {"M", 0, 8}, {"N", 0, 8}, {"O", 0, 8},
        {"P", 0, 8}, {"Q", 0, 8}, {"R", 0, 8}, {"S", 0, 8}, {"T", 0, 8}, {"U", 0, 8},
        {"V", 0, 10}, {"W", 0, 10}, {"X", 0, 8}, {"Y", 0, 8}, {"Z", 0, 8}, {" ", 0, 12},
        {" ", 0, 12}, {" ", 0, 12}, {" ", 0, 12}, {" ", 0, 12}, {" ", 0, 12}, {"a", 0, 8},
        {"b", 0, 8}, {"c", 0, 8}, {"d", 0, 8}, {"e", 0, 8}, {"f", 0, 6}, {"g", 0, 8},
        {"h", 0, 6}, {"i", 0, 2}, {"j", 0, 4}, {"k", 0, 8}, {"l", 0, 6}, {"m", 0, 10},
        {"n", 0, 8}, {"o", 0, 8}, {"p", 0, 8}, {"q", 0, 8}, {"r", 0, 6}, {"s", 0, 6},
        {"t", 0, 6}, {"u", 0, 6}, {"v", 0, 8}, {"w", 0, 8}, {"x", 0, 8}, {"y", 0, 8},
        {"z", 0, 6}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_1E38[] = {
        {" ", 0, 12}, {"!", 10, 4}, {" ", 0, 24}, {" ", 0, 24}, {" ", 0, 24}, {" ", 0, 24},
        {"&", 4, 16}, {"'", 0, 6}, {"(", 8, 8}, {")", 8, 8}, {" ", 0, 24}, {" ", 0, 24},
        {",", 9, 6}, {"-", 5, 14}, {".", 10, 4}, {"/", 5, 14}, {"0", 4, 16}, {"1", 7, 10},
        {"2", 3, 18}, {"3", 4, 16}, {"4", 3, 18}, {"5", 4, 16}, {"6", 4, 16}, {"7", 4, 16},
        {"8", 4, 16}, {"9", 4, 16}, {" ", 10, 4}, {" ", 10, 4}, {" ", 9, 6}, {" ", 9, 6},
        {" ", 5, 14}, {" ", 4, 16}, {" ", 4, 16}, {"A", 1, 22}, {"B", 2, 20}, {"C", 3, 18},
        {"D", 2, 20}, {"E", 3, 18}, {"F", 3, 18}, {"G", 2, 20}, {"H", 1, 22}, {"I", 7, 10},
        {"J", 2, 20}, {"K", 1, 22}, {"L", 3, 18}, {"M", 1, 22}, {"N", 1, 22}, {"O", 3, 18},
        {"P", 2, 20}, {"Q", 2, 20}, {"R", 1, 22}, {"S", 4, 16}, {"T", 3, 18}, {"U", 1, 22},
        {"V", 1, 22}, {"W", 1, 22}, {"X", 1, 22}, {"Y", 1, 22}, {"Z", 3, 18}, {" ", 3, 18},
        {" ", 0, 24}, {" ", 0, 24}, {" ", 0, 24}, {" ", 0, 24}, {" ", 0, 24}, {"a", 3, 18},
        {"b", 3, 18}, {"c", 5, 14}, {"d", 3, 18}, {"e", 5, 14}, {"f", 5, 14}, {"g", 4, 16},
        {"h", 2, 20}, {"i", 8, 8}, {"j", 7, 10}, {"k", 3, 18}, {"l", 8, 8}, {"m", 1, 22},
        {"n", 2, 20}, {"o", 4, 16}, {"p", 3, 18}, {"q", 3, 18}, {"r", 4, 16}, {"s", 6, 14},
        {"t", 6, 12}, {"u", 2, 20}, {"v", 3, 18}, {"w", 1, 22}, {"x", 2, 20}, {"y", 2, 20},
        {"z", 5, 14}, {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_2118[] = {
        {" ", 0, 18}, {"!", 6, 6}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18},
        {"&", 1, 15}, {"'", 6, 6}, {"(", 6, 6}, {")", 6, 6}, {" ", 0, 18}, {"+", 3, 12},
        {",", 0, 18}, {"-", 3, 12}, {".", 0, 14}, {"/", 5, 8}, {"0", 1, 16}, {"1", 6, 6},
        {"2", 1, 16}, {"3", 1, 16}, {"4", 1, 16}, {"5", 1, 16}, {"6", 1, 16}, {"7", 1, 16},
        {"8", 1, 16}, {"9", 1, 16}, {":", 6, 6}, {";", 6, 6}, {"[", 6, 6}, {"]", 6, 6},
        {"_", 2, 14}, {"?", 1, 16}, {" ", 0, 18}, {"A", 1, 16}, {"B", 1, 16}, {"C", 1, 16},
        {"D", 1, 16}, {"E", 1, 16}, {"F", 1, 16}, {"G", 1, 16}, {"H", 1, 16}, {"I", 6, 6},
        {"J", 1, 16}, {"K", 1, 16}, {"L", 1, 16}, {"M", 1, 16}, {"N", 1, 16}, {"O", 1, 16},
        {"P", 1, 16}, {"Q", 1, 16}, {"R", 1, 16}, {"S", 1, 16}, {"T", 1, 16}, {"U", 1, 16},
        {"V", 1, 16}, {"W", 1, 16}, {"X", 1, 16}, {"Y", 1, 16}, {"Z", 1, 16}, {" ", 0, 18},
        {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {"a", 0, 18},
        {"b", 0, 18}, {"c", 4, 10}, {"d", 0, 18}, {"e", 0, 18}, {"f", 0, 18}, {"g", 0, 18},
        {"h", 0, 18}, {"i", 6, 6}, {"j", 0, 18}, {"k", 0, 18}, {"l", 0, 18}, {"m", 0, 18},
        {"n", 4, 10}, {"o", 0, 18}, {"p", 0, 18}, {"q", 0, 18}, {"r", 0, 18}, {"s", 0, 18},
        {"", 0, 0},
    };
    static const FontKern lbl_1_rodata_23C0[] = {
        {" ", 0, 18}, {"!", 7, 4}, {"\"", 4, 10}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18},
        {"&", 1, 15}, {"'", 6, 8}, {"(", 6, 6}, {")", 6, 6}, {" ", 0, 18}, {"+", 3, 12},
        {",", 0, 18}, {"-", 3, 12}, {".", 0, 14}, {"/", 5, 8}, {"0", 1, 16}, {"1", 1, 16},
        {"2", 1, 16}, {"3", 1, 16}, {"4", 1, 16}, {"5", 1, 16}, {"6", 1, 16}, {"7", 1, 16},
        {"8", 1, 16}, {"9", 1, 16}, {":", 7, 4}, {";", 7, 4}, {"[", 6, 6}, {"]", 6, 6},
        {"_", 2, 14}, {"?", 1, 16}, {" ", 0, 18}, {"A", 1, 16}, {"B", 1, 16}, {"C", 1, 16},
        {"D", 1, 16}, {"E", 1, 16}, {"F", 1, 16}, {"G", 1, 16}, {"H", 1, 16}, {"I", 6, 6},
        {"J", 1, 16}, {"K", 1, 16}, {"L", 1, 16}, {"M", 1, 16}, {"N", 1, 16}, {"O", 1, 16},
        {"P", 1, 16}, {"Q", 1, 16}, {"R", 1, 16}, {"S", 1, 16}, {"T", 1, 16}, {"U", 1, 16},
        {"V", 1, 16}, {"W", 1, 16}, {"X", 1, 16}, {"Y", 1, 16}, {"Z", 1, 16}, {" ", 0, 18},
        {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {" ", 0, 18}, {"a", 0, 18},
        {"b", 0, 18}, {"c", 4, 10}, {"d", 0, 18}, {"e", 0, 18}, {"f", 0, 18}, {"g", 0, 18},
        {"h", 0, 18}, {"i", 7, 4}, {"j", 0, 18}, {"k", 0, 18}, {"l", 0, 18}, {"m", 0, 18},
        {"n", 4, 10}, {"o", 0, 18}, {"p", 0, 18}, {"q", 0, 18}, {"r", 0, 18}, {"s", 0, 18},
        {"", 0, 0},
    };
    const FontKern *entry;
    u32 adv;
    s32 found;
    const u8 *str;
    u8 b;

    adv = font->width;
    if ((u16)c == ' ') {
        return adv * state->space_scale;
    }
    if (!(state->flags & 0x80000000)) {
        return adv;
    }
    entry = NULL;
    found = 0;
    switch (state->font) {
    case 5: entry = lbl_1_rodata_2118; break;
    case 6: entry = lbl_1_rodata_23C0; break;
    case 42: entry = lbl_1_rodata_1100; break;
    case 7: entry = lbl_1_rodata_1B58; break;
    case 8: entry = lbl_1_rodata_1E38; break;
    case 33: entry = lbl_1_rodata_1410; break;
    case 10: entry = lbl_1_rodata_1320; break;
    case 29: entry = lbl_1_rodata_14E8; break;
    case 30: entry = lbl_1_rodata_15C0; break;
    case 18: entry = lbl_1_rodata_1698; break;
    case 21: entry = lbl_1_rodata_1700; break;
    case 22: entry = lbl_1_rodata_1888; break;
    case 19: entry = lbl_1_rodata_1398; break;
    case 25: entry = lbl_1_rodata_1A08; break;
    case 41: entry = lbl_1_rodata_1AE8; break;
    case 36: entry = lbl_1_rodata_1A78; break;
    }
    if (entry != NULL) {
        if ((u16)c > 0x80) {
            /* a two-byte character: match both bytes */
            for (; entry->width != 0; entry++) {
                str = (const u8 *)entry->glyph;
                if (str[0] >= 0x80 && (u16)c == (u16)((str[0] << 8) | str[1])) {
                    found = 1;
                    break;
                }
            }
        } else {
            for (; entry->width != 0; entry++) {
                b = entry->glyph[0];
                if (b <= 0x80 && b == (u16)c) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            adv = (entry->x << 16) | entry->width;
        }
    }
    return adv;
}
/* fzgx:end fn_1_49F08 */

/* fzgx:begin fn_1_4A0D8 */
/* Placeholder: retail function stripped by the link; body reconstructed from its literals */
/* Named by its error string (.data 1C39C); the search is the glyph lookup fn_1_4A0D8 open-codes. */
static s32 get_tex_id(FontInfo *font, u16 ch) {
    s32 i;
    u16 *code;

    for (i = 0, code = font->kana; *code != 0; i++, code++) {
        if (*code == ch) {
            return font->kana_image[i];
        }
    }
    OSReport("ARAM FONT SEARCH ERROR at get_tex_id [ch:%d]\n", ch);
    return -1;
}

void fn_1_4A0D8(const char *s) {
    static const FontColor shadow_color = {0, 0, 0, 0};
    FontPacket pkt;
    FontState saved;
    char buf[32];
    FontState *state;
    FontInfo *font;
    s32 first;
    FontState *state2;
    u16 *p;
    f32 width;
    f32 spacing;
    f32 lastX;
    f32 lastY;
    f32 x;
    f32 y;
    f32 offset;
    f32 advance;
    f32 u;
    f32 v;
    u32 c;
    u16 ch;
    u32 adv;
    u8 len;
    s16 count;
    s32 idx;
    s32 row;
    s32 col;
    s32 n;
    FontInfo *fs;

    p = NULL;
    if (s == NULL && lbl_1_bss_4BA28[0] == 0) {
        lbl_1_bss_4BA28[0] = 1;
        return;
    }
    state = &lbl_1_bss_4B9CC;
    font = &lbl_1_data_1AEA8[state->font];
    fn_80008BEC(&pkt, 0, sizeof(pkt));
    state2 = &lbl_1_bss_4B9CC;
    pkt.image = font->image;
    pkt.z = state->z;
    pkt.alpha = state->alpha;
    pkt.rotation_z = state->rotation;
    pkt.color = state->color;
    pkt.color_add = state->color_add;
    pkt.flags = state->unk_58 | (state->flags & ~0xF);
    if (pkt.image == -1) {
        pkt.flags |= 0x400000;
    }
    first = 1;
    switch (state->align & 0x18) {
    case 0:
        break;
    case 8:
        state->y -= fn_1_4B090(s) / 2.0f;
        break;
    case 0x10:
        state->y -= fn_1_4B090(s);
        break;
    }

    for (; *(const u8 *)s != 0; s++) {
        if (state->flags & 0x10000) {
            pkt.z += 0.01f;
        }
        if (first) {
            first = 0;
            width = fn_1_4B040(s);
            count = fn_1_4B1A0(s);
            if ((state->align & 4) && state->width > width) {
                spacing = (state->width - width) / (count - 1);
            } else {
                spacing = 0.0f;
            }
        }
        ch = *(const u8 *)s;
        c = ch;
        if ((state->flags & 0x20000000) && (u16)c >= 'a' && (u16)c <= 'z') {
            c = ch - 0x20;
        }
        if ((u16)c < 0x80) {
            if ((pkt.flags & 0x400000) && (u16)c != '\n' && (u16)c != ' ' &&
                (lbl_1_bss_3E058 == 0 || ((u16)c != '[' && (u16)c != ']'))) {
                c = fn_1_499BC((const u8 *)s);
                if ((u16)c >= 0x80) {
                    s += 6;
                } else {
                    if ((u16)c == '/' && (s8)(n = fn_1_49B70((u8 *)s, state)) != 0) {
                        s += (s8)n;
                        pkt.color = state->color;
                        pkt.color_add = state->color_add;
                        continue;
                    }
                    c = fn_1_49794(c);
                }
            }
            if ((u16)c < 0x80) {
                if ((u16)c == '/' && (s8)(n = fn_1_49B70((u8 *)s, state)) != 0) {
                    s += (s8)n;
                    pkt.color = state->color;
                    pkt.color_add = state->color_add;
                    continue;
                }
                adv = fn_1_49F08(c, state, font);
                if ((u16)c == '\n') {
                    first = 1;
                    state->x = state->home_x;
                    state->y += state->line_spacing + font->height * state->scale_y;
                    continue;
                }
                if ((u16)c == ' ') {
                    state->x += state->spacing + (s32)(adv & 0xFFFF) * state->scale_x;
                    continue;
                }
                if (lbl_1_bss_3E058 != 0 && (u16)c == '[') {
                    len = 0;
                    do {
                        s++;
                        c = fn_1_499BC((const u8 *)s);
                        if ((u16)c >= 0x80) {
                            fn_80008BA8((void *)&buf[len], (void *)s, 2);
                            s++;
                            len += 2;
                        } else if ((u16)c != ']') {
                            buf[len++] = *(const u8 *)s;
                        }
                    } while ((u16)c != ']');
                    buf[len] = 0;
                    if (lbl_1_data_1BCC4 != 0) {
                        fn_80008BA8((void *)&saved, (void *)state, sizeof(saved));
                        fs = &lbl_1_data_1AEA8[saved.font];
                        state2->z = saved.z - 0.01f;
                        lbl_1_bss_4B9CC.spacing = 0.0f;
                        lbl_1_bss_4B9CC.line_spacing = 0.0f;
                        lbl_1_bss_4B9CC.x = lastX;
                        lbl_1_bss_4B9CC.home_x = lastX;
                        lbl_1_bss_4B9CC.align = 0x11;
                        lbl_1_bss_4B9CC.space_scale = 1.0f;
                        lbl_1_bss_4B9CC.y = lastY - 1.0f + lbl_1_bss_3E05C;
                        fn_1_4955C(0.5f * saved.scale_x / fs->scale, 0.5f * saved.scale_y / fs->scale);
                        lbl_1_bss_3E058 = 0;
                        fn_1_4A0D8(buf);
                        lbl_1_bss_3E058 = 1;
                        fn_80008BA8((void *)state, (void *)&saved, sizeof(saved));
                    }
                    continue;
                }
                if ((u16)c < font->first || (u16)c > font->last) {
                    state->x += state->spacing + (s32)(adv & 0xFFFF) * state->scale_x;
                    continue;
                }
            } else {
                u16 *q;
                s32 i;

                pkt.image = -2;
                q = font->kana;
                for (i = 0; *q != 0; i++, q++) {
                    if (*q == (u16)c) {
                        adv = fn_1_49F08(c, state, font);
                        pkt.image = font->kana_image[i];
                        if (pkt.image != -1) {
                            c = 0;
                        }
                        break;
                    }
                }
                p = q;
            }
        } else {
            u16 *q;
            s32 i;

            c = (((u16)c << 8) | *(const u8 *)++s) & 0xFFFF;
            if (c == 0x8140) {
                adv = fn_1_49F08(c, state, font);
                state->x += state->spacing + (s32)(adv & 0xFFFF) * state->scale_x;
                continue;
            }
            pkt.image = -2;
            q = font->kana;
            for (i = 0; *q != 0; i++, q++) {
                if (*q == c) {
                    adv = fn_1_49F08(c, state, font);
                    pkt.image = font->kana_image[i];
                    if (pkt.image != -1) {
                        c = 0;
                    }
                    break;
                }
            }
            p = q;
        }

        if (pkt.image < 0) {
            /* WARNING: compiler-diff device, not original code (owner-approved 2026-11-09, carried from main).
             * No glyph drawn: the ruby anchor stays on the previous glyph.
             * Retail keeps an empty arm here (bge +8; b); carrying the anchor through x/y
             * reproduces it. The carry changes no value. */
            x = lastX;
            y = lastY;
        } else {
            if (pkt.flags & 0x400000) {
                pkt.image &= 0xFFFF;
                pkt.image |= (state->font & 0xFF) << 16;
                pkt.image |= state->page << 24;
            }
            idx = (u16)c - font->first;
            row = idx / font->columns;
            col = idx % font->columns;
            if ((state->align & 3) == 2) {
                pkt.x = state->x - width;
            } else if ((state->align & 3) == 1) {
                pkt.x = state->x - width / 2.0f;
            } else {
                pkt.x = state->x;
            }
            pkt.y = state->y;
            y = state->y;
            offset = (s16)(adv >> 16) * state->scale_x;
            advance = (s32)(adv & 0xFFFF);
            pkt.x -= offset;
            x = pkt.x + 0.5f * (state->scale_x * (s32)(adv & 0xFFFF));
            u = font->cell_w * col;
            v = font->cell_h * row;
            pkt.u0 = u;
            pkt.v0 = v;
            pkt.u1 = u + font->cell_w;
            pkt.v1 = v + font->cell_h;
            pkt.scale_x = state->scale_x * font->cell_w;
            pkt.scale_y = state->scale_y * font->cell_h;
            if (state->unk_54 != 0) {
                pkt.vertex_callback = state->unk_54;
                pkt.unk_54 = state->unk_50;
                pkt.flags |= 0x4000000;
            }
            if (lbl_1_bss_4BA30.enabled != 0) {
                pkt.x += offset;
                fn_1_4B6D4(&pkt, state, font, advance);
                pkt.x -= offset;
            }
            if (lbl_1_bss_4BA44.enabled != 0) {
                pkt.x += offset;
                fn_1_4B788(&pkt, state, font, advance);
                pkt.x -= offset;
            }
            if (p != NULL && *p >= 0x839F && *p <= 0x83B8) {
                pkt.flags |= 0x10000000;
            } else {
                pkt.flags &= ~0x10000000;
            }
            if ((pkt.flags & 0x400000) && (state->flags & 0x40000000)) {
                pkt.x += state->shadow_x;
                pkt.y += state->shadow_y;
                pkt.z += 0.02f;
                pkt.alpha = state->alpha * state->shadow_alpha;
                pkt.color = shadow_color;
                fn_1_4AC20(&pkt);
                pkt.x -= state->shadow_x;
                pkt.y -= state->shadow_y;
                pkt.z -= 0.02f;
                pkt.alpha = state->alpha;
                pkt.color = state->color;
            }
            fn_1_4AC20(&pkt);
        }
        lastX = x;
        lastY = y;
        state->x += spacing + (state->spacing + (s32)(adv & 0xFFFF) * state->scale_x);
    }

    switch (state->align & 0x18) {
    case 0:
        break;
    case 8:
        state->y += fn_1_4B090(s) / 2.0f;
        break;
    case 0x10:
        state->y += fn_1_4B090(s);
        break;
    }
}
/* fzgx:end fn_1_4A0D8 */

/* fzgx:begin fn_1_4AC20 */
void fn_1_4AC20(FontPacket *value) {
    FontPacket local = *value;
    int x_ok;
    int y_ok;

    if (lbl_1_bss_4B9CC.unk_45 != 0) {
        local.x = fn_1_519FC(local.x);
        local.y = fn_1_51AC0(local.y);
        local.scale_x = fn_1_51B84(local.scale_x);
        local.scale_y = fn_1_51BFC(local.scale_y);
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
    } else if ((local.flags & 0x400000) != 0) {
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E500();
        }
        fn_1_48D80((void *)&local);
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
    fn_8008077C(buffer, format, args);
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

    lbl_1_bss_3E05C = 0.0f;
    lbl_1_bss_3E058 = value;

    return previous;
}
/* fzgx:end fn_1_4AEC0 */

/* fzgx:begin fn_1_4AEE8 */
u32 fn_1_4AEE8(u32 value) {
    u32 previous = lbl_1_data_1BCC4;

    lbl_1_bss_3E05C = 0.0f;
    lbl_1_data_1BCC4 = value;

    return previous;
}
/* fzgx:end fn_1_4AEE8 */

/* fzgx:begin fn_1_4AF10 */
void fn_1_4AF10(const char *text) {
    u32 v0;
    v0 = lbl_1_bss_3E058;
    lbl_1_bss_3E05C = 0.0f;
    lbl_1_bss_3E058 = 1;
    fn_1_4A0D8(text);
    lbl_1_bss_3E058 = v0;
}
/* fzgx:end fn_1_4AF10 */

/* fzgx:begin fn_1_4AF64 */
void fn_1_4AF64(const char *format, ...) {
    __va_list args;
    char buffer[512];
    u32 previous = lbl_1_bss_3E058;

    __builtin_va_info(&args);
    fn_8008077C(buffer, format, args);

    lbl_1_bss_3E058 = 1;
    lbl_1_bss_3E05C = 0.0f;
    fn_1_4A0D8(buffer);
    lbl_1_bss_3E058 = previous;
}
/* fzgx:end fn_1_4AF64 */

/* fzgx:begin fn_1_4B040 */
f32 fn_1_4B040(const char *text) {
    return fn_1_4B1D4(0, text);
}
/* fzgx:end fn_1_4B040 */

/* fzgx:begin fn_1_4B068 */
f32 fn_1_4B068(const char *text) {
    return fn_1_4B1D4(1, text);
}
/* fzgx:end fn_1_4B068 */

/* fzgx:begin fn_1_4B090 */
f32 fn_1_4B090(const char *text) {
    s32 count;
    s32 index;
    FontInfo *entry;
    f32 a;
    f32 b;

    index = lbl_1_bss_4B9CC.font;
    entry = &lbl_1_data_1AEA8[index];
    count = fn_1_4B16C(text);
    if (count - 1 > 0) {
        count = fn_1_4B16C(text) - 1;
    } else {
        count = 0;
    }
    a = lbl_1_bss_4B9CC.scale_y *
        (entry->scale * (entry->height * fn_1_4B16C(text)));
    b = lbl_1_bss_4B9CC.line_spacing * count;
    return a + b;
}
/* fzgx:end fn_1_4B090 */

/* fzgx:begin fn_1_4B16C */
s32 fn_1_4B16C(const char *text) {
    return fn_1_4B1D4(2, text);
}
/* fzgx:end fn_1_4B16C */

/* fzgx:begin fn_1_4B1A0 */
s32 fn_1_4B1A0(const char *text) {
    return fn_1_4B1D4(3, text);
}
/* fzgx:end fn_1_4B1A0 */

/* fzgx:begin fn_1_4B1D4 */
f32 fn_1_4B1D4(s32 mode, const char *str) {
    FontState * p;
    s32 i;
    FontState *state;
    FontInfo *font;
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

    s = (u8 *)str;
    p = &lbl_1_bss_4B9CC;
    maxWidth = 0.0f;
    width = -p->spacing;
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
    font = &lbl_1_data_1AEA8[lbl_1_bss_4B9CC.font];
    /* `goto next` is the loop's continue: it skips the width accumulation */
    while ((ch = *(cp = s + i)) != 0) {
        state = &lbl_1_bss_4B9CC;
        c = ch;
        if ((state->flags & 0x20000000) && (u16)c >= 'a' && (u16)c <= 'z') {
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
            if (font->image == -1) {
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
                            width = -p->spacing;
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
                        width = -p->spacing;
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
            width += p->spacing + (f32)(state->scale_x * (adv * font->scale));
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

/* fzgx:begin fn_1_4B6D4 */
/* grow the clip box lbl_1_bss_4BA30 to the glyph cell (vertex pass of fn_1_4A0D8) */
void fn_1_4B6D4(const FontPacket *pkt, const FontState *state, const FontInfo *font, f32 advance) {
    if (pkt->x < lbl_1_bss_4BA30.unk_4) {
        lbl_1_bss_4BA30.unk_4 = pkt->x;
    }
    if (pkt->x + advance * state->scale_x > lbl_1_bss_4BA30.unk_8) {
        lbl_1_bss_4BA30.unk_8 = pkt->x + advance * state->scale_x;
    }
    if (pkt->y < lbl_1_bss_4BA30.unk_C) {
        lbl_1_bss_4BA30.unk_C = pkt->y;
    }
    if (pkt->y + font->height * state->scale_y > lbl_1_bss_4BA30.unk_10) {
        lbl_1_bss_4BA30.unk_10 = pkt->y + font->height * state->scale_y;
    }
}
/* fzgx:end fn_1_4B6D4 */

/* fzgx:begin fn_1_4B788 */
/* the same for the second box lbl_1_bss_4BA44 */
void fn_1_4B788(const FontPacket *pkt, const FontState *state, const FontInfo *font, f32 advance) {
    if (pkt->x < lbl_1_bss_4BA44.unk_4) {
        lbl_1_bss_4BA44.unk_4 = pkt->x;
    }
    if (pkt->x + advance * state->scale_x > lbl_1_bss_4BA44.unk_8) {
        lbl_1_bss_4BA44.unk_8 = pkt->x + advance * state->scale_x;
    }
    if (pkt->y < lbl_1_bss_4BA44.unk_C) {
        lbl_1_bss_4BA44.unk_C = pkt->y;
    }
    if (pkt->y + font->height * state->scale_y > lbl_1_bss_4BA44.unk_10) {
        lbl_1_bss_4BA44.unk_10 = pkt->y + font->height * state->scale_y;
    }
}
/* fzgx:end fn_1_4B788 */

/* fzgx:begin fn_1_4B83C */
void fn_1_4B83C(void *arg0, void *arg1, u32 arg2, const char *arg3) {
    u32 length;
    s32 converted;

    length = strlen(arg3);
    converted = fn_1_4B1D4(3, (void *)((u8 *)(arg2 + length)));
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

/* fzgx:begin fn_1_4B8DC */
void fn_1_4B8DC(void)
{
    u32 size;
    char *src = "./font/fnt_asc_24x24.bin";
    MsgData msg;
    u32 arenaHi;
    void *p;
    u32 q;
    s32 flag;
    s32 tmp_call2;

    arenaHi = OSGetArenaHi();

    tmp_call2 = fn_80006B70(src, &msg);
    if (tmp_call2 == 0) {
        OSReport("dvdopen err %s\n", src);
        OSPanic("font.c", 0xA77, "Stopped...\n");
    }

    size = (fn_80006DE8(&msg) + 0x1F) & ~0x1F;
    p = (void *)OSAllocFromArenaHi(size, 0x20);
    fn_80006D1C(&msg, p, size, 0);
    flag = 1;
    q = fn_8002071C();

    while (ARGetDMAStatus() != 0) {
    }

    fn_800206FC(size);
    lbl_1_bss_4BA58 = 1;
    DCFlushRange(p, size);
    ARQPostRequest((ARQRequest *)&lbl_1_bss_4BA60[0], 1, 0, 1, p, 0xF96000,
        size, (ARQCallback)fn_1_4B8BC);

    while (flag == 1 && lbl_1_bss_4BA58 != 0) {
    }

    fn_800206FC(q);
    OSSetArenaHi(arenaHi);
}
/* fzgx:end fn_1_4B8DC */

/* fzgx:begin fn_1_4BA24 */
void fn_1_4BA24(u8 arg0, s32 arg1, void *arg2)
{
    u32 saved;
    u32 dest;
    u16 len;

    if (arg0 >= 0x2C) {
        OSReport("Type = %d (Max %d)\n", arg0, 0x2C);
        OSPanic("font.c", 0xAB4, "Font Type Error");
    }

    len = lbl_1_data_1AEA8[arg0 & 0xFF].tex_size;
    dest = lbl_1_bss_4BA80[arg0 & 0xFF] + 0xF96000 + len * arg1;

    saved = fn_8002071C();
    fn_800206FC(0x20);

    lbl_1_bss_4BA5C = 1;

    while (ARGetDMAStatus() != 0) {
    }

    DCInvalidateRange(arg2, len);
    ARQPostRequest((ARQRequest *)lbl_1_bss_4BA60, 1, 1, 1, (void *)dest, (u32)arg2,
        len, (ARQCallback)fn_1_4B8CC);

    while (lbl_1_bss_4BA5C != 0) {
    }

    fn_800206FC(saved);
}
/* fzgx:end fn_1_4BA24 */

/* fzgx:begin fn_1_4BB5C */
/* one 0x38-byte record of the lbl_1_data_1AEA8 font table */

/* for every font with unk_0 == -1: clear each character slot whose lbl_1_bss_3F60C entry is not -1,
 * and count the font's characters into lbl_1_bss_40BBC */

static inline void reset_font_slots(FontInfo *table) {
    s32 i;
    s32 ch;
    FontInfo *font;
    u16 *code;
    s32 *count = lbl_1_bss_40BBC;

    for (i = 0, font = table; i < 44; i++, font++) {
        count[i] = 0;
        if (font->image == -1) {
            for (ch = 0, code = font->kana; *code != 0; ch++, code++) {
                s16 slot = font->kana_image[ch];
                if (slot != -1 && lbl_1_bss_3F60C[slot] != -1) {
                    font->kana_image[ch] = -1;
                }
                count[i]++;
            }
        }
    }
}

/* the s8 is read through a pointer, as retail loads it straight into the index register */

static inline void load_font_chars(s8 *selected) {
    s32 index = *selected;
    s32 ch;
    u16 *code;
    FontInfo *font;

    font = &lbl_1_data_1AEA8[index];
    if (font->image == -1) {
        for (ch = 0, code = font->kana; *code != 0; ch++, code++) {
            if (font->kana_image[ch] == -1) {
                fn_1_48A0C(ch, index, font, 0);
            }
        }
    }
}

void fn_1_4BB5C(void) {
    FontViewer *state = &lbl_1_bss_4BB30;
    FontInfo *prev = &lbl_1_data_1AEA8[state->font];

    state->prev_font = 3;
    state->font = 3;
    state->bold = 0;
    state->style = 0;
    state->page = 0;
    state->cursor = 0;
    reset_font_slots(lbl_1_data_1AEA8);
    if (prev->image == -1) {
        load_font_chars(&state->font);
    } else {
        fn_1_47F74((prev->image >> 8) & 0xFFFF);
    }
}
/* fzgx:end fn_1_4BB5C */

/* fzgx:begin fn_1_4BD48 */
// fn_1_4BD48: empty in retail (single blr).

void fn_1_4BD48(void) {
}
/* fzgx:end fn_1_4BD48 */

/* fzgx:begin fn_1_4BD4C */
void fn_1_4BD4C(u32 unused0, u32 unused1, u32 unused2) {
    u16 *p_d58;
    s32 page_size;
    FontInfo *elem;
    s32 cols;
    s32 rows;
    s32 prev_unk_0;
    s32 prev_unk_4;
    s32 prev_unk_8;
    s32 count;
    s32 max_page;
    FontViewer *sp30;

    sp30 = &lbl_1_bss_4BB30;
    elem = &lbl_1_data_1AEA8[sp30->font];
    if (elem->image == -1) {
        cols = 16;
        rows = 8;
    } else {
        cols = elem->columns;
        rows = elem->rows;
    }

    prev_unk_0 = sp30->font;
    p_d58 = lbl_1_bss_D58;

    if (((p_d58[8] >> 1) & 1) != 0) {
        if ((s8)++sp30->font > 43) {
            sp30->font = 0;
        }
    }
    if ((p_d58[8] & 1) != 0) {
        if ((s8)--sp30->font < 0) {
            sp30->font = 43;
        }
    }

    elem = &lbl_1_data_1AEA8[sp30->font];
    if (prev_unk_0 != sp30->font) {
        sp30->page = 0;
        if (elem->image == -1) {
            fn_1_48C28(sp30->prev_font);
            load_font_chars(&sp30->font);
        } else {
            fn_1_48140((lbl_1_data_1AEA8[sp30->prev_font].image >> 8) & 0xFFFF);
            fn_1_47F74((elem->image >> 8) & 0xFFFF);
        }
        sp30->prev_font = sp30->font;
    }

    if (elem->image == -1) {
        page_size = cols * rows;
        prev_unk_4 = sp30->page;
        max_page = ((s32 *)&lbl_1_bss_40BBC)[sp30->font] / page_size;
        if (((p_d58[8] >> 2) & 1) != 0) {
            if ((s8)++sp30->page > max_page) {
                sp30->page = 0;
            }
        }
        if (((p_d58[8] >> 3) & 1) != 0) {
            if ((s8)--sp30->page < 0) {
                sp30->page = max_page;
            }
        }
        if (prev_unk_4 != sp30->page) {
            if (sp30->page != sp30->cursor / page_size) {
                sp30->cursor = sp30->page * page_size;
            }
        }
    }

    prev_unk_8 = sp30->cursor;
    if (elem->image == -1) {
        count = ((s32 *)&lbl_1_bss_40BBC)[sp30->font];
    } else {
        count = elem->last + 1;
    }

    if (((lbl_1_bss_D58[9] >> 5) & 1) != 0) {
        if (++sp30->cursor > count - 1) {
            sp30->cursor = 0;
        }
    }
    if (((lbl_1_bss_D58[9] >> 4) & 1) != 0) {
        if (--sp30->cursor < 0) {
            sp30->cursor = count - 1;
        }
    }
    if (((lbl_1_bss_D58[9] >> 6) & 1) != 0) {
        sp30->cursor += cols;
        if (sp30->cursor > count - 1) {
            sp30->cursor %= cols;
        }
    }
    if (((lbl_1_bss_D58[9] >> 7) & 1) != 0) {
        sp30->cursor -= cols;
        if (sp30->cursor < 0) {
            sp30->cursor = (sp30->cursor % cols) + ((count - 1) / cols + 1) * cols;
        }
        if (sp30->cursor > count - 1) {
            sp30->cursor -= cols;
        }
    }

    if (prev_unk_8 != sp30->cursor) {
        if (sp30->page != sp30->cursor / (cols * rows)) {
            sp30->page = sp30->cursor / (cols * rows);
        }
    }

    if (elem->image == -1) {
        if (((lbl_1_bss_D58[4] >> 10) & 1) != 0) {
            sp30->bold ^= 1;
        }
        if (((lbl_1_bss_D58[4] >> 11) & 1) != 0) {
            if ((s8)++sp30->style == 6) {
                sp30->style = 0;
            }
        }
    }

    if (((lbl_1_bss_D58[4] >> 12) & 1) != 0) {
        lbl_1_bss_96A = 52;
    }

    fn_1_4C16C();
}
/* fzgx:end fn_1_4BD4C */

/* fzgx:begin fn_1_4C16C */
/* clip box reset, inlined in fn_1_4C16C, fn_1_4D0A0 and fn_1_4D494 */
static void font_clip_reset(FontToggle *clip) {
    clip->enabled = 1;
    clip->unk_4 = 640.0f;
    clip->unk_8 = 0.0f;
    clip->unk_C = 480.0f;
    clip->unk_10 = 0.0f;
}

static inline void font_draw_glyph(s32 code) {
    FontPacket pkt;
    FontInfo *font = &lbl_1_data_1AEA8[lbl_1_bss_4B9CC.font];
    s32 idx = code - font->first;
    s32 row = idx / font->columns;
    s32 col = idx % font->columns;
    f32 u;
    f32 v;

    pkt.image = font->image;
    pkt.x = lbl_1_bss_4B9CC.x;
    pkt.y = lbl_1_bss_4B9CC.y;
    pkt.z = lbl_1_bss_4B9CC.z;
    u = font->cell_w * col;
    v = font->cell_h * row;
    pkt.u0 = u;
    pkt.v0 = v;
    pkt.u1 = u + font->cell_w;
    pkt.v1 = v + font->cell_h;
    pkt.scale_x = lbl_1_bss_4B9CC.scale_x * font->cell_w;
    pkt.scale_y = lbl_1_bss_4B9CC.scale_y * font->cell_h;
    pkt.rotation_z = lbl_1_bss_4B9CC.rotation;
    pkt.alpha = lbl_1_bss_4B9CC.alpha;
    pkt.flags = lbl_1_bss_4B9CC.unk_58 | (lbl_1_bss_4B9CC.flags & ~0xF);
    pkt.color = lbl_1_bss_4B9CC.color;
    pkt.color_add = lbl_1_bss_4B9CC.color_add;
    if (lbl_1_bss_4B9CC.unk_54 != 0) {
        pkt.vertex_callback = lbl_1_bss_4B9CC.unk_54;
        pkt.flags |= 0x4000000;
    }
    fn_1_4AC20(&pkt);
}

void fn_1_4C16C(void) {
    FontViewer *viewer = &lbl_1_bss_4BB30;
    s32 i;
    s32 j;
    s32 page_size;
    s32 rows;
    FontInfo *font;
    s32 cols;

    font = &lbl_1_data_1AEA8[viewer->font];
    if (font->image == -1) {
        cols = 16;
        rows = 8;
    } else {
        cols = font->columns;
        rows = font->rows;
    }

    fn_1_A8EB0(1, 3);
    if (font->image == -1) {
        fn_1_A8DD4("\"%s\" %12s %d/%d\n", lbl_1_data_1BBC4[viewer->font], lbl_1_data_1BCAC[viewer->style], viewer->style, 5);
    } else {
        fn_1_A8DD4("\"%s\"\n", lbl_1_data_1BBC4[viewer->font]);
    }
    fn_1_A8E78("\n");
    fn_1_A8E78("LR:font select\n");
    if (font->image == -1) {
        fn_1_A8E78("DU:page next/prev\n");
    }
    fn_1_A8E78("3D:charactor select\n");
    if (font->image == -1) {
        fn_1_A8E78("X :fixed/proportional\n");
        fn_1_A8E78("Y :style change\n");
    }

    fn_1_49410();
    fn_1_494DC(viewer->font);
    lbl_1_bss_4B9CC.home_x = lbl_1_bss_4B9CC.x = 320.0f - font->scale * (font->width * cols) / 2.0f;
    lbl_1_bss_4B9CC.y = 150.0f;
    if (viewer->bold) {
        fn_1_495B0(0x80000000);
    }
    fn_1_4965C(viewer->style);

    if (font->image == -1) {
        char buf[3];
        u16 *p;

        page_size = cols * rows;
        buf[2] = 0;
        font_clip_reset(&lbl_1_bss_4BA30);
        for (i = 0, p = font->kana; *p != 0; i++, p++) {
            if (i < viewer->page * page_size) {
                continue;
            }
            if (i >= viewer->page * page_size + page_size) {
                break;
            }
            buf[0] = *p >> 8;
            buf[1] = *p;
            {
                FontColor color = {0x80, 0x80, 0x80, 0x00};
                fn_1_49514(&color);
            }
            {
                FontColor color = {0xFF, 0xFF, 0xFF, 0x00};
                for (j = 0; j < 0x56B; j++) {
                    if (*p == lbl_1_data_1A3B8[j]) {
                        fn_1_49514(&color);
                    }
                }
            }
            if (viewer->cursor == i) {
                FontColor color = {0xFF, 0xFF, 0x00, 0x00};
                fn_1_49514(&color);
            }
            {
                if (font->kana_image[i] == -1) {
                    fn_1_4A0D8("\201E");
                    fn_1_494DC(viewer->font);
                } else {
                    fn_1_4A0D8((void *)buf);
                }
                if (i % cols == cols - 1) {
                    fn_1_4A0D8((void *)("\n"));
                }
            }
            {
                FontColor color = {0xFF, 0xFF, 0xFF, 0x00};
                fn_1_49514(&color);
            }
        }
        lbl_1_bss_4BA30.enabled = 0;
        lbl_1_bss_4B9CC.flags &= ~0x80000000;
        if (font->kana_image[viewer->cursor] != -1) {
            buf[0] = (font->kana[viewer->cursor] >> 8) & 0xFF;
            buf[1] = font->kana[viewer->cursor];
            fn_1_496FC(12.0f, 150.0f);
            fn_1_4955C(2.0f, 2.0f);
            fn_1_4A0D8((void *)buf);
        }
        fn_1_494DC(3);
        fn_1_496FC(12.0f, (font->height * 2 + 162));
        fn_1_4955C(1.0f, 1.0f);
        fn_1_4AE0C("%X\n", font->kana[viewer->cursor]);
        if (font->kana_image[viewer->cursor] == -1) {
            fn_1_4A0D8((void *)("is no load.\n"));
        } else {
            fn_1_4AE0C("aram:%d\n", font->kana_image[viewer->cursor]);
        }
        fn_1_4AE0C("\npage:%d/%d\n", viewer->page, lbl_1_bss_40BBC[viewer->font] / page_size);
    } else {
        char buf[2];

        buf[1] = 0;
        font_clip_reset(&lbl_1_bss_4BA30);
        for (i = font->first, j = 0; i < font->last + 1; i++, j++) {
            if (viewer->cursor == i) {
                FontColor color = {0xFF, 0xFF, 0x00, 0x00};
                fn_1_49514(&color);
            }
            if (i == 0) {
                FontColor color = {0xFF, 0x00, 0x00, 0x00};
                fn_1_49528(&color);
                font_draw_glyph(0);
                fn_1_4A0D8(" ");
            } else if (i == 10) {
                FontColor color = {0xFF, 0x00, 0x00, 0x00};
                fn_1_49528(&color);
                font_draw_glyph(10);
                fn_1_4A0D8(" ");
            } else {
                buf[0] = i;
                fn_1_4A0D8((void *)buf);
            }
            if (j % cols == cols - 1) {
                fn_1_4A0D8((void *)("\n"));
            }
            {
                FontColor color = {0xFF, 0xFF, 0xFF, 0x00};
                FontColor color_add = {0x00, 0x00, 0x00, 0x00};
                fn_1_49514(&color);
                fn_1_49528(&color_add);
            }
        }
        lbl_1_bss_4BA30.enabled = 0;
        lbl_1_bss_4B9CC.flags &= ~0x80000000;
        buf[0] = viewer->cursor;
        fn_1_496FC(12.0f, 150.0f);
        fn_1_4955C(2.0f, 2.0f);
        fn_1_4A0D8((void *)buf);
        fn_1_494DC(3);
        fn_1_496FC(12.0f, (font->height * 2 + 162));
        fn_1_4955C(1.0f, 1.0f);
        fn_1_4AE0C("%X", viewer->cursor);
    }
}
/* fzgx:end fn_1_4C16C */

/* fzgx:begin fn_1_4CDE4 */
/* Convert the selected font entry's byte metrics to floating-point coordinates. */

void fn_1_4CDE4(f32 *x, f32 *y) {
    FontInfo *entry;
    s16 index;

    index = lbl_1_bss_4B9CC.font;
    entry = &lbl_1_data_1AEA8[index];
    *x = (f32)(u32)entry->width;
    *y = (f32)(u32)entry->height;
}
/* fzgx:end fn_1_4CDE4 */

/* fzgx:begin fn_1_4CE48 */
void fn_1_4CE48(f32 limit, const char *text) {
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    saved = lbl_1_bss_4B9CC.scale_x;
    first = fn_1_4B1D4(1, text);
    count = fn_1_4B1D4(3, text);
    count = count - 1;
    adjusted = lbl_1_bss_4B9CC.spacing * count;
    adjusted = first + adjusted;
    if (adjusted > limit) {
        lbl_1_bss_4B9CC.scale_x =
            lbl_1_bss_4B9CC.scale_x * (limit / adjusted);
    }
    fn_1_4A0D8(text);
    lbl_1_bss_4B9CC.scale_x = saved;
}
/* fzgx:end fn_1_4CE48 */

/* fzgx:begin fn_1_4CF3C */
void fn_1_4CF3C(const char *format, f32 x, ...) {
    FontState *p_lbl_1_bss_4B9CC;
    char buffer[512];
    __va_list list;
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    __builtin_va_info(&list);

    fn_8008077C(buffer, format, list);

    p_lbl_1_bss_4B9CC = &lbl_1_bss_4B9CC;
    saved = p_lbl_1_bss_4B9CC->scale_x;
    first = fn_1_4B1D4(1, buffer);
    count = fn_1_4B1D4(3, buffer);
    count = count - 1;
    adjusted = p_lbl_1_bss_4B9CC->spacing * count;
    adjusted = first + adjusted;
    if (adjusted > x) {
        p_lbl_1_bss_4B9CC->scale_x = p_lbl_1_bss_4B9CC->scale_x * (x / adjusted);
    }
    fn_1_4A0D8(buffer);
    p_lbl_1_bss_4B9CC->scale_x = saved;
}
/* fzgx:end fn_1_4CF3C */

/* fzgx:begin fn_1_4D0A0 */
void fn_1_4D0A0(void) {
    font_clip_reset(&lbl_1_bss_4BA30);
}
/* fzgx:end fn_1_4D0A0 */

/* fzgx:begin fn_1_4D0D4 */
/* WARNING: compiler-diff device, not original code. Carried from main (an extern non-const f32 view of .rodata
 * 26B8): retail loads 0.1f after the colour copy, as a non-const object load. Measured honest spellings that
 * schedule it first: literal, const / static const / extern const object, const array, local, inline helper,
 * by-value copy, forced memory read. A non-const object closes both functions; the section keeps it at .rodata 26B8. */
__declspec(section ".rodata") f32 lbl_1_rodata_26B8 = 0.1f;

void fn_1_4D0D4(FontColor *color, f32 value) {
    FontColor c = *color;
    fn_1_4D10C(&c, lbl_1_rodata_26B8, value);
}
/* fzgx:end fn_1_4D0D4 */

/* fzgx:begin fn_1_4D10C */
void fn_1_4D10C(FontColor *color, f32 p1, f32 p2) {
    s32 w, h, cx, cy;
    if (lbl_1_bss_4BA30.enabled != 0) {
        lbl_1_bss_4BA30.enabled = 0;
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
            w = __abs((right - left));
            h = __abs((top - bottom));
            cx = ((left + right) / 2.0f);
            cy = ((top + bottom) / 2.0f);
        }
        fn_1_53B14(color, cx, cy, w + p2, h + p2, p1);
    }
}
/* fzgx:end fn_1_4D10C */

/* fzgx:begin fn_1_4D274 */
void fn_1_4D274(FontColor *color, f32 value) {
    FontColor c = *color;
    /* WARNING: compiler-diff device, not original code (see lbl_1_rodata_26B8 before fn_1_4D0D4) */
    fn_1_4D2AC(c, lbl_1_rodata_26B8, value);
}
/* fzgx:end fn_1_4D274 */

/* fzgx:begin fn_1_4D2AC */
void fn_1_4D2AC(FontColor arg0, f32 arg1, f32 arg2) {
    f32 left, bottom, top, right;
    s32 x, y;
    f32 alpha;
    u32 a;
    s32 width, height;
    FontPacket draw;
    if (lbl_1_bss_4BA30.enabled != 0) {
        lbl_1_bss_4BA30.enabled = 0;
        if (640.0f == (left = lbl_1_bss_4BA30.unk_4) && 0.0 == lbl_1_bss_4BA30.unk_8 &&
            480.0f == lbl_1_bss_4BA30.unk_C && 0.0 == lbl_1_bss_4BA30.unk_10) return;
        top = lbl_1_bss_4BA30.unk_C;
        bottom = lbl_1_bss_4BA30.unk_10;
        if (top > bottom) return;
        right = lbl_1_bss_4BA30.unk_8;
        if (left > right) return;
        width = __abs((right-left));
        height = __abs((top-bottom));
        draw = lbl_1_rodata_26F8;
        x = ((left+right)/2.0f);
        y = ((top+bottom)/2.0f);
        a = arg0.a;
        draw.image = 2;
        draw.x = x;
        draw.y = y;
        draw.z = arg1;
        alpha = a / 255.0f;
        draw.flags = 10;
        draw.color = arg0;
        draw.alpha = alpha;
        fn_1_50164(width+arg2, height+arg2, 13.0f, 26.0f, &draw);
    }
}
/* fzgx:end fn_1_4D2AC */

/* fzgx:begin fn_1_4D494 */
void fn_1_4D494(void) {
    font_clip_reset(&lbl_1_bss_4BA44);
}
/* fzgx:end fn_1_4D494 */

/* fzgx:begin fn_1_4D4C8 */
void fn_1_4D4C8(FontColor *color, f32 z, f32 ofs) {
    FontPacket s;
    FontColor c;
    s32 w;
    s32 h;
    f32 y;
    f32 x;
    f32 left;
    f32 right;
    f32 bottom;
    f32 top;

    if (lbl_1_bss_4BA44.enabled == 0) {
        return;
    }
    lbl_1_bss_4BA44.enabled = 0;
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
    w = __abs((right - left));
    h = __abs((top - bottom));
    s = lbl_1_rodata_26F8;
    s.z = z;
    s.image = 18;
    s.alpha = 0.1882353f;
    s.flags = 10;
    s.color = c;
    s.x = (s32)((left + right) / 2.0f);
    s.y = (s32)((top + bottom) / 2.0f);
    x = w + ofs;
    y = h + ofs;
    fn_1_50164(x, y, 2.0f, 2.0f, &s);
    s.alpha *= 0.8f;
    fn_1_50164(4.0f + x, 2.0f + y, 2.0f, 2.0f, &s);
    s.alpha *= 0.8f;
    fn_1_50164(8.0f + x, 4.0f + y, 2.0f, 2.0f, &s);
    s.alpha *= 0.8f;
    fn_1_50164(12.0f + x, 6.0f + y, 2.0f, 2.0f, &s);
    s.alpha *= 0.8f;
    fn_1_50164(16.0f + x, 8.0f + y, 2.0f, 2.0f, &s);
}
/* fzgx:end fn_1_4D4C8 */

/* fzgx:begin fn_1_4D784 */
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

    __builtin_va_info(&args);
    fn_8008077C((char *)text, fmt, args);
    q = line;
    i = 0;
    while ((c = *(p = text + i)) != 0) {
        start = i;
        hyphen = 0;
        flag = 0;
        if (c < 0x80) {
            if (kinsoku == 1) {
                if (strncmp((char *)p, ".", 1) == 0 || strncmp((char *)p, ",", 1) == 0) {
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
                if (strncmp((char *)p, "\201B", 2) == 0 || strncmp((char *)p, "\201A", 2) == 0 ||
                    strncmp((char *)p, "\201v", 2) == 0) {
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
        if (fn_1_4B1D4(1, (char *)line) > (s16)width) {
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
            strcpy((char *)out, (char *)line);
            out += strlen((char *)line);
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
    strcpy((char *)out, (char *)line);
    out += strlen((char *)line);
    out[1] = 0;
    return out;
}
/* fzgx:end fn_1_4D784 */

/* fzgx:begin fn_1_4DC20 */
/* the saved-state flag, inlined in fn_1_4DC20 and fn_1_4DC6C. Evidence is the .bss order only: 4BB3C precedes
 * 4BB40, and .bss is laid out in first-access order, so a function writing 4BB3C precedes fn_1_4DC20 in the file
 * (a static helper, stripped after inlining; strip_allow entry). */
static void font_set_saved(u8 saved) {
    lbl_1_bss_4BB3C = saved;
}

void fn_1_4DC20(void) {
    lbl_1_bss_4BB40 = lbl_1_bss_4B9CC;
    font_set_saved(1);
}
/* fzgx:end fn_1_4DC20 */

/* fzgx:begin fn_1_4DC6C */
void fn_1_4DC6C(void) {
    lbl_1_bss_4B9CC = lbl_1_bss_4BB40;
    font_set_saved(0);
}
/* fzgx:end fn_1_4DC6C */

/* fzgx:begin fn_1_4DCB8 */
// Replaces the stored font state value and returns its previous value.

u32 fn_1_4DCB8(u32 value) {
    u32 old_value = lbl_1_bss_4B9CC.unk_58;
    lbl_1_bss_4B9CC.unk_58 = value;
    return old_value;
}

/* Placeholder: retail function stripped by the link; body reconstructed from its literals */
/* Its traces: .rodata 26E8 (a magenta FontColor) 240.0f 0.09f 0.095f and .data "%s" "It's Font\nTest." */
static void font_test(void) {
    static const FontColor color = {0xFF, 0x00, 0xFF, 0xFF};

    fn_1_49410();
    fn_1_49514((FontColor *)&color);
    fn_1_496FC(0.0f, 240.0f);
    fn_1_4955C(0.09f, 0.095f);
    fn_1_4AE0C("%s", "It's Font\nTest.");
}
/* fzgx:end fn_1_4DCB8 */
