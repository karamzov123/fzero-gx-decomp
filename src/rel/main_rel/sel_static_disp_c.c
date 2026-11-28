#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "game/pad.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "rel/main_rel/game.h"
#include "rel/main_rel/car_test.h"


typedef unsigned long u32;

typedef struct {
    u32 v[8];
} Word8;

typedef float f32;

typedef signed long s32;

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;

typedef unsigned short u16;

typedef struct {
void *value;
} Val;

typedef struct {
u8 pad8[8];
Val *value;
} Ref;

typedef struct {
u8 pad344[0x344];
Ref *ref;
} Obj;

typedef struct CompareEntry {
    s16 index;
    f32 value;
} CompareEntry;

typedef struct fn_1_14DEC8_FontVertex {
f32 x, y, z;
} fn_1_14DEC8_FontVertex;

typedef struct fn_1_14DEC8_FontDrawPacket fn_1_14DEC8_FontDrawPacket;

struct fn_1_14DEC8_FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
fn_1_14DEC8_FontDrawPacket* secondary;
void (*vertex_callback)(fn_1_14DEC8_FontDrawPacket* packet, fn_1_14DEC8_FontVertex* vertices);
u32 unk_54;
};

typedef struct {
    u32 words[3];
} Blend3;

typedef struct {
    u8 *kind;        /* 0x00: descriptor pointer, byte 3 is the blend key */
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u8 b48;
    u8 b49;
    u8 pad4A[2];
    f32 f4C;
    f32 f50;
    Blend3 tail[8];  /* 0x54..0xB4 */
} DispEntry;

typedef s32 (*Sig_fn_8007E96C_fn_8007E96C_Compare)(u32, u32);

struct Names {
	u8 *p[75];
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

typedef struct Pool {
    u8 pad_00[0x48];
    f64 c48;
    u8 pad_50[4];
    f32 c54;
    u8 pad_58[4];
    f32 c5c;
    u8 pad_60[8];
    f32 c68;
    f32 c6c;
    f32 c70;
    u8 pad_74[4];
    f64 c78;
    f64 c80;
} Pool;

typedef struct CameraState151054 {
    u8 pad_0[0x118];
    s32 unk_118;
} CameraState151054;

typedef struct fn_1_150D3C_Entry {
    u8 pad_08[8];
    u32 flags;
    u8 pad_0c[0x20];
    f32 x;
    f32 y;
    f32 z;
    u8 tail[0x74];
} fn_1_150D3C_Entry;

typedef struct Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150D3C_Entry entries[1];
} Object;

typedef struct Rotation151054 {
    u32 unk_0;
    f32 unk_4;
} Rotation151054;

typedef struct Display151054 {
    u32 unk_0;
    u8 pad_4[0xC];
    f32 unk_10;
    u8 pad_14[0x20];
    Rotation151054 **unk_34;
} Display151054;

typedef struct Entry151054 {
    f32 unk_1824;
    f32 unk_1828;
    f32 unk_182C;
    f32 unk_1830;
    f32 unk_1834;
    f32 unk_1838;
    f32 unk_183C;
    f32 unk_1840;
    f32 unk_1844;
    f32 unk_1848;
    f32 unk_184C;
    f32 unk_1850;
    f32 unk_1854;
    Display151054 *unk_1858;
    u8 unk_185C;
    u8 unk_185D;
    u8 unk_185E;
    u8 unk_185F;
} Entry151054;

typedef struct State151054 {
    u8 pad_0[0x1824];
    Entry151054 entries[64];
    s32 unk_2724;
    s32 unk_2728;
    s32 unk_272C;
    f32 unk_2730;
    f32 unk_2734;
    f32 unk_2738;
    f32 unk_273C;
    f32 unk_2740;
    f32 unk_2744;
} State151054;
extern u16 lbl_1_bss_50EC[10];
extern u32 lbl_801A66A4;
extern void fn_1_14A1AC(u8);
extern const f32 lbl_1_rodata_99A4;
extern u32 fn_1_5910(void);
extern u32 fn_1_149FB4(s32 index);
extern u8 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern f64 lbl_1_rodata_99B0;
extern int fn_1_8623C(void);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_3F2A0(void);
extern void fn_1_14A9D0();
extern void fn_1_14CA4C(void);
extern u32 fn_1_14BE30(void);
extern void fn_1_14BFD8(s16 port, u8 *sel, s32 arg2);
extern s32 fn_1_1555B0(s32 value);
extern void fn_1_1556B4(u8 arg0, u8 arg1);
extern u32 lbl_801A66A0;
extern void fn_1_12EF80(s16 value, s16 *row, s16 *column);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u32 fn_1_F89E4(u8 value);
extern u8 lbl_1_bss_718E0[];
extern u32 lbl_801A66B4;
extern u32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);
extern void fn_1_155FB4(char *arg);
extern char *strcpy(char *dst, const char *src);
extern char *strncpy(char *dst, const char *src, size_t n);
extern void fn_1_14CAC8(void);
extern void fn_1_A2DC4(u32 arg0);
extern s32 fn_1_14CEB8(u8 *name);
extern s32 strncmp(const char *s1, const char *s2, size_t n);
extern void OSReport(const char *msg, ...);
extern u8 *lbl_1_bss_25CD0[];
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u8 *strstr(u8 *str, const u8 *needle);
extern u8 lbl_1_bss_8E598[148];
extern u8 lbl_1_bss_8E62C[132];
extern const u8 lbl_1_rodata_9828[172];
extern const u8 lbl_1_rodata_98D4[208];
extern void *fn_1_D3884(void *name);
extern void * fn_1_14F344(void *);
extern void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern void fn_80072558(void);
extern void fn_1_151C3C(s16 index, s16 row);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *value);
extern void fn_1_151C78(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern u8 lbl_1_rodata_A894[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern s32 fn_1_14FDAC(void *, void *, s16, void *);
extern s16 fn_1_14F090(void *, s16);
extern s16 fn_1_14F01C(void *);
extern u32 lbl_1_rodata_99D8[75];
extern void *fn_1_36AD0(s16 arg0, u32 arg1);
extern void *fn_1_14F6F8(void *arg0, void *arg1, void *arg2, DispEntry *out);
extern void fn_1_14FD7C(u32 *, u32);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern u8 lbl_1_bss_8E6B0[308];
extern u16 lbl_1_bss_8E7E4[722];
extern char * fn_1_14EBF8(s16, char *, s16);
extern char * fn_1_14EA74(s16, char *, s16);
extern s32 fn_1_14ED00(s32 arg0, void *arg1, s32 arg2);
extern u32 fn_8007E96C(u32, u32, u32, u32, Sig_fn_8007E96C_fn_8007E96C_Compare);
extern u8 fn_1_14E8A4__fzgx_offset_0[];
extern u8 fn_1_14E8CC__fzgx_offset_0[];
extern u8 fn_1_14E8F4__fzgx_offset_0[];
extern u8 fn_1_14E91C__fzgx_offset_0[];
extern u8 fn_1_14E944__fzgx_offset_0[];
extern u8 fn_1_14E96C__fzgx_offset_0[];
extern u8 fn_1_14E9A8__fzgx_offset_0[];
extern u8 fn_1_14EE00__fzgx_offset_64[];
extern u8 fn_1_14EE00__fzgx_offset_6C[];
extern u8 fn_1_14EE00__fzgx_offset_74[];
extern u8 fn_1_14EE00__fzgx_offset_7C[];
extern u8 fn_1_14EE00__fzgx_offset_84[];
extern u8 fn_1_14EE00__fzgx_offset_88[];
extern u8 lbl_1_data_43E78__fzgx_offset_0[];
extern u8 lbl_1_data_43E84__fzgx_offset_0[];
extern u8 lbl_1_data_43E88__fzgx_offset_0[];
extern u8 lbl_1_data_43E9C__fzgx_offset_0[];
extern u8 lbl_1_data_43EA8__fzgx_offset_0[];
extern u8 lbl_1_data_43EB8__fzgx_offset_0[];
extern u8 lbl_1_data_43EC8__fzgx_offset_0[];
extern u8 lbl_1_data_43EE8__fzgx_offset_0[];
extern u8 lbl_1_data_43EF4__fzgx_offset_0[];
extern u8 lbl_1_data_43F08__fzgx_offset_0[];
extern u8 lbl_1_data_43F18__fzgx_offset_0[];
extern u8 lbl_1_data_43F2C__fzgx_offset_0[];
extern u8 lbl_1_data_43F38__fzgx_offset_0[];
extern u8 lbl_1_data_43F4C__fzgx_offset_0[];
extern u8 lbl_1_data_43F54__fzgx_offset_0[];
extern u8 lbl_1_data_43F64__fzgx_offset_0[];
extern u8 lbl_1_data_43F74__fzgx_offset_0[];
extern u8 lbl_1_data_43F84__fzgx_offset_0[];
extern u8 lbl_1_data_43F90__fzgx_offset_0[];
extern u8 lbl_1_data_43FA0__fzgx_offset_0[];
extern u8 lbl_1_data_43FB0__fzgx_offset_0[];
extern u8 lbl_1_data_43FC8__fzgx_offset_0[];
extern u8 lbl_1_data_43FD8__fzgx_offset_0[];
extern u8 lbl_1_data_43FEC__fzgx_offset_0[];
extern u8 lbl_1_data_43FF8__fzgx_offset_0[];
extern u8 lbl_1_data_44008__fzgx_offset_0[];
extern u8 lbl_1_data_44018__fzgx_offset_0[];
extern u8 lbl_1_data_44030__fzgx_offset_0[];
extern u8 lbl_1_data_44038__fzgx_offset_0[];
extern u8 lbl_1_data_44048__fzgx_offset_0[];
extern u8 lbl_1_data_44054__fzgx_offset_0[];
extern u8 lbl_1_data_44064__fzgx_offset_0[];
extern u8 lbl_1_data_44070__fzgx_offset_0[];
extern u8 lbl_1_data_44084__fzgx_offset_0[];
extern u8 lbl_1_data_44090__fzgx_offset_0[];
extern u8 lbl_1_data_440A4__fzgx_offset_0[];
extern u8 lbl_1_data_440B0__fzgx_offset_0[];
extern u8 lbl_1_data_440C0__fzgx_offset_0[];
extern u8 lbl_1_data_440CC__fzgx_offset_0[];
extern u8 lbl_1_data_440DC__fzgx_offset_0[];
extern u8 lbl_1_data_440EC__fzgx_offset_0[];
extern u8 lbl_1_data_44100__fzgx_offset_0[];
extern u8 lbl_1_data_4410C__fzgx_offset_0[];
extern u8 lbl_1_data_44120__fzgx_offset_0[];
extern u8 lbl_1_data_4412C__fzgx_offset_0[];
extern u8 lbl_1_data_44138__fzgx_offset_0[];
extern u8 lbl_1_data_44144__fzgx_offset_0[];
extern u8 lbl_1_data_44154__fzgx_offset_0[];
extern u8 lbl_1_data_44160__fzgx_offset_0[];
extern u8 lbl_1_data_44170__fzgx_offset_0[];
extern u8 lbl_1_data_4417C__fzgx_offset_0[];
extern u8 lbl_1_data_4418C__fzgx_offset_0[];
extern u8 lbl_1_data_4419C__fzgx_offset_0[];
extern u8 lbl_1_data_441AC__fzgx_offset_0[];
extern u8 lbl_1_data_441B8__fzgx_offset_0[];
extern u8 lbl_1_data_441D0__fzgx_offset_0[];
extern u8 lbl_1_data_441DC__fzgx_offset_0[];
extern u8 lbl_1_data_441EC__fzgx_offset_0[];
extern u8 lbl_1_data_441F8__fzgx_offset_0[];
extern u8 lbl_1_data_4420C__fzgx_offset_0[];
extern u8 lbl_1_data_44220__fzgx_offset_0[];
extern u8 lbl_1_data_4423C__fzgx_offset_0[];
extern u8 lbl_1_data_44244__fzgx_offset_0[];
extern u8 lbl_1_data_44250__fzgx_offset_0[];
extern u8 lbl_1_data_44260__fzgx_offset_0[];
extern u8 lbl_1_data_44270__fzgx_offset_0[];
extern u8 lbl_1_data_4427C__fzgx_offset_0[];
extern u8 lbl_1_data_44290__fzgx_offset_0[];
extern u8 lbl_1_data_4429C__fzgx_offset_0[];
extern u8 lbl_1_data_442AC__fzgx_offset_0[];
extern u8 lbl_1_data_442BC__fzgx_offset_0[];
extern u8 lbl_1_data_442D0__fzgx_offset_0[];
extern u8 lbl_1_data_442E0__fzgx_offset_0[];
extern u8 lbl_1_data_442F4__fzgx_offset_0[];
extern u8 lbl_1_data_44304__fzgx_offset_0[];
extern u8 lbl_1_data_4431C__fzgx_offset_0[];
extern u8 lbl_1_data_44328__fzgx_offset_0[];
extern u8 lbl_1_data_4433C__fzgx_offset_0[];
extern u8 lbl_1_data_4434C__fzgx_offset_0[];
extern u8 lbl_1_data_44360__fzgx_offset_0[];
extern u8 lbl_1_data_4436C__fzgx_offset_0[];
extern u8 lbl_1_data_44378__fzgx_offset_0[];
extern u8 lbl_1_data_44384__fzgx_offset_0[];
extern u8 lbl_1_data_44394__fzgx_offset_0[];
extern u8 lbl_1_data_443A4__fzgx_offset_0[];
extern u8 lbl_1_data_443B8__fzgx_offset_0[];
extern u8 lbl_1_data_443C8__fzgx_offset_0[];
extern u8 lbl_1_data_443DC__fzgx_offset_0[];
extern u8 lbl_1_data_443EC__fzgx_offset_0[];
extern u8 lbl_1_data_44400__fzgx_offset_0[];
extern u8 lbl_1_data_44410__fzgx_offset_0[];
extern u8 lbl_1_data_44424__fzgx_offset_0[];
extern u8 lbl_1_data_44430__fzgx_offset_0[];
extern u8 lbl_1_data_44444__fzgx_offset_0[];
extern u8 lbl_1_data_44450__fzgx_offset_0[];
extern u8 lbl_1_data_4445C__fzgx_offset_0[];
extern u8 lbl_1_data_44468__fzgx_offset_0[];
extern u8 lbl_1_data_44478__fzgx_offset_0[];
extern u8 lbl_1_data_4448C__fzgx_offset_0[];
extern u8 lbl_1_data_444AC__fzgx_offset_0[];
extern u8 lbl_1_data_444BC__fzgx_offset_0[];
extern u8 lbl_1_data_444D0__fzgx_offset_0[];
extern u8 lbl_1_data_444DC__fzgx_offset_0[];
extern u8 lbl_1_data_444F0__fzgx_offset_0[];
extern u8 lbl_1_data_444F8__fzgx_offset_0[];
extern u8 lbl_1_data_44504__fzgx_offset_0[];
extern u8 lbl_1_data_44510__fzgx_offset_0[];
extern u8 lbl_1_data_44520__fzgx_offset_0[];
extern u8 lbl_1_data_4452C__fzgx_offset_0[];
extern u8 lbl_1_data_4453C__fzgx_offset_0[];
extern u8 lbl_1_data_44548__fzgx_offset_0[];
extern u8 lbl_1_data_44558__fzgx_offset_0[];
extern u8 lbl_1_data_44568__fzgx_offset_0[];
extern u8 lbl_1_data_4457C__fzgx_offset_0[];
extern u8 lbl_1_data_4458C__fzgx_offset_0[];
extern u8 lbl_1_data_445A8__fzgx_offset_0[];
extern u8 lbl_1_data_445B8__fzgx_offset_0[];
extern u8 lbl_1_data_445CC__fzgx_offset_0[];
extern u8 lbl_1_data_445D8__fzgx_offset_0[];
extern u8 lbl_1_data_445E8__fzgx_offset_0[];
extern u8 lbl_1_data_445F4__fzgx_offset_0[];
extern u8 lbl_1_data_44608__fzgx_offset_0[];
extern u8 lbl_1_data_44614__fzgx_offset_0[];
extern u8 lbl_1_data_44624__fzgx_offset_0[];
extern u8 lbl_1_data_44630__fzgx_offset_0[];
extern u8 lbl_1_data_44640__fzgx_offset_0[];
extern u8 lbl_1_data_44650__fzgx_offset_0[];
extern u8 lbl_1_data_44664__fzgx_offset_0[];
extern u8 lbl_1_data_44670__fzgx_offset_0[];
extern u8 lbl_1_data_44684__fzgx_offset_0[];
extern u8 lbl_1_data_44690__fzgx_offset_0[];
extern u8 lbl_1_data_446A0__fzgx_offset_0[];
extern u8 lbl_1_data_446B0__fzgx_offset_0[];
extern u8 lbl_1_data_446C8__fzgx_offset_0[];
extern u8 lbl_1_data_446D8__fzgx_offset_0[];
extern u8 lbl_1_data_446EC__fzgx_offset_0[];
extern u8 lbl_1_data_446F8__fzgx_offset_0[];
extern u8 lbl_1_data_44708__fzgx_offset_0[];
extern u8 lbl_1_data_44714__fzgx_offset_0[];
extern u8 lbl_1_data_44728__fzgx_offset_0[];
extern u8 lbl_1_data_44738__fzgx_offset_0[];
extern u8 lbl_1_data_44750__fzgx_offset_0[];
extern u8 lbl_1_data_4475C__fzgx_offset_0[];
extern u8 lbl_1_data_4476C__fzgx_offset_0[];
extern u8 lbl_1_data_44778__fzgx_offset_0[];
extern u8 lbl_1_data_44788__fzgx_offset_0[];
extern u8 lbl_1_data_44794__fzgx_offset_0[];
extern u8 lbl_1_data_447A8__fzgx_offset_0[];
extern u8 lbl_1_data_447B0__fzgx_offset_0[];
extern u8 lbl_1_data_447BC__fzgx_offset_0[];
extern u8 lbl_1_data_447C8__fzgx_offset_0[];
extern u8 lbl_1_data_447DC__fzgx_offset_0[];
extern u8 lbl_1_data_447E8__fzgx_offset_0[];
extern u8 lbl_1_data_447FC__fzgx_offset_0[];
extern u8 lbl_1_data_44808__fzgx_offset_0[];
extern u8 lbl_8015B200[];
extern void fn_1_12AB38(void *arg0);
extern s32 fn_1_12ADA0(void *arg0, void *arg1);
extern void fn_1_8019C(void *arg0);
extern struct Names lbl_1_rodata_CE10;
extern s16 fn_1_3F0C8();
extern void fn_1_1507C4(Fn183D28Vec3 *pos, Fn183D28Vec3 *vel);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern f32 fn_1_A71AC(void);
extern s16 fn_1_58E3C(void *source);
extern u32 lbl_8006DCA4(void);
extern u32 lbl_8006D5F0(void *, void *, f32);
extern void *memset(void *, int, u32);
extern void fn_1_1030D4(void *entry, void *arg);
extern f64 lbl_8006D188(s32 value);
extern const f32 lbl_1_rodata_CF40[];
extern u8 fn_1_58C4(void);
extern void fn_1_5948(u32 arg0);
extern s16 camera_get_mode(void);
extern void fn_1_627C();
extern u32 fn_1_8627C(s32 index);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern s32 fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern s32 fn_1_12A7C4(void *arg0, void *arg1, void *arg2);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern u8 lbl_1_rodata_9CDC[1200];
extern u8 *fn_1_14F608(void *arg0);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern u8 lbl_1_rodata_A18C[1800];
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern u8 lbl_1_rodata_CB98[324];
extern s32 fn_1_465D0(char *path, s32 arg1);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8();
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_9A508();
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Object *obj, void *arg);
extern void fn_1_150654(void);
extern void fn_1_151054(State151054 *arg0);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern void fn_1_150F74(void *self);

/* fzgx:begin fn_1_14A028 noprologue */
#include "types.h"

extern u8 lbl_1_bss_38200;
extern u16 lbl_1_bss_50EC[10];
extern u32 lbl_801A66A4;

typedef struct {
    void (*unk_0)(void *, u32);
    void (*unk_4)(void);
    void (*unk_8)(void);
    u32 unk_C;
} Ent;

extern Ent lbl_1_data_42B94[];

typedef struct {
    u32 unk_0;
    u8 pad_4[4];
    u8 unk_8;
} Obj3C30;
extern Obj3C30 lbl_1_bss_3C30;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[6];
    u8 unk_C;
    u8 pad_D[3];
    u32 unk_10;
    u8 unk_14;
} Obj518;
extern Obj518 lbl_1_bss_8E518;

typedef struct {
    u8 pad_0[8];
    u16 unk_8;
} Obj9F8;
extern Obj9F8 lbl_1_bss_9F8;

extern void fn_1_14A1AC(u8);

void fn_1_14A028(void) {
    u32 fzgx_value;
    Obj518 *s = &lbl_1_bss_8E518;
    int flag = 1;
    u8 tmp_ra2;

    if ((lbl_1_bss_3C30.unk_0 & 0x8) == 0 && (((((0x1000 & lbl_1_bss_3C30.unk_0))) != ((0))))) {
        if ((((lbl_1_bss_38200) != ((0))))) {
            flag = 0;
        } else {
            int n = lbl_1_bss_3C30.unk_8;
            int i = 0;

            while (n > 0) {
                if (lbl_1_bss_50EC[i] != 0) {
                    flag = 0;
                    break;
                }
                i++;
                n--;
            }
        }

        tmp_ra2 = s->unk_C;

        if ((((tmp_ra2) != s->unk_5))) {
            if ((((tmp_ra2) != ((0xFF))))) {
                lbl_1_data_42B94[tmp_ra2].unk_8();
            }

            tmp_ra2 = s->unk_5;
            fzgx_value = lbl_801A66A4;
            s->unk_C = tmp_ra2;
            s->unk_10 = fzgx_value;
            lbl_1_data_42B94[tmp_ra2].unk_0(lbl_1_data_42B94, lbl_801A66A4);
        }

        fn_1_14A1AC(s->unk_5);

        if ((((flag) != ((0))))) {
            lbl_1_data_42B94[s->unk_5].unk_4();
            if (((0) != (((lbl_1_bss_9F8.unk_8 >> 4) & 1)))) {
                s->unk_14 ^= 1;
            }
        }
    }
}
/* fzgx:end fn_1_14A028 */

/* fzgx:begin fn_1_14A17C noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x18];
    f32 unk_18;
    f32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
} fn_1_14A17C_Obj_1_bss_8E518;

extern const f32 lbl_1_rodata_99A4;
extern fn_1_14A17C_Obj_1_bss_8E518 lbl_1_bss_8E518;

// Reset the static display state to its initial values.
void fn_1_14A17C(void) {
    lbl_1_bss_8E518.unk_20 = 0;
    lbl_1_bss_8E518.unk_18 = lbl_1_rodata_99A4;
    lbl_1_bss_8E518.unk_1c = lbl_1_rodata_99A4;
    lbl_1_bss_8E518.unk_24 = 0;
    lbl_1_bss_8E518.unk_28 = 0;
    lbl_1_bss_8E518.unk_2c = 0;
}
/* fzgx:end fn_1_14A17C */

/* fzgx:begin fn_1_14A1AC */
typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 unk_9;
} fn_1_14A1AC_Obj_1_bss_3C30;


void fn_1_14A1AC(u8 arg) {
    if (lbl_1_bss_960 == 1) {
        lbl_1_bss_8E548 = 4;
        return;
    }

    switch (arg) {
    case 5:
    case 6:
        lbl_1_bss_8E548 = 4;
        return;
    case 3:
        lbl_1_bss_8E548 = (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 < 6 ? (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 : 6;
        return;
    case 4:
        lbl_1_bss_8E548 = (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_8 < 6 ? (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_8 : 6;
        return;
    default:
        lbl_1_bss_8E548 = (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 < 6 ? (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 : 6;
        return;
    }
}
/* fzgx:end fn_1_14A1AC */

/* fzgx:begin fn_1_14A278 */
// fn_1_14A278: empty in retail (single blr).
void fn_1_14A278(void) {
}
/* fzgx:end fn_1_14A278 */

/* fzgx:begin fn_1_14A27C */
// fn_1_14A27C: empty in retail (single blr).
void fn_1_14A27C(void) {
}
/* fzgx:end fn_1_14A27C */

/* fzgx:begin fn_1_14A280 */
// fn_1_14A280: empty in retail (single blr).
void fn_1_14A280(void) {
}
/* fzgx:end fn_1_14A280 */

/* fzgx:begin fn_1_14A284 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void *fn_1_5910(void);
extern s32 fn_1_149FB4(void *obj);
extern int fn_1_3F864(void);
extern void fn_1_A52B0(u8 value);
extern void fn_1_A2D84(u32 value);

void fn_1_14A284(void) {
    void *obj;
    s32 value;
    s32 ok;

    obj = fn_1_5910();
    fn_1_149FB4(obj);
    if (fn_1_3F864() != 0) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            value = fn_1_149FB4(obj);
            ok = (value + 1 > 30) ? 0 : (value + 1 >= 1);
            if (ok != 0) {
                fn_1_A52B0((value + 1));
            }
        } else {
            fn_1_A2D84(0xA9071F00);
        }
    }
}
/* fzgx:end fn_1_14A284 */

/* fzgx:begin fn_1_14A328 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"

/* begin rel/main_rel/game.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef REL_MAIN_REL_GAME_H
#define REL_MAIN_REL_GAME_H

/* begin rel/main_rel/globals.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern s16 lbl_1_bss_960;

// lbl_1_bss_3C30: .bss size 0x14BC, referenced by 95 functions, shape {'object': 411}
typedef struct {
    u32 unk_0;  // 35 loads, 5 stores
    u8 unk_4;  // 3 loads, 0 stores
    u8 unk_5;  // 34 loads, 2 stores
    u8 unk_6;  // 12 loads, 0 stores
    u8 unk_7;  // 1 loads, 0 stores
    u8 unk_8;  // 47 loads, 0 stores
    u8 unk_9;  // 55 loads, 0 stores
    u8 pad_A[0x3];
    u8 unk_D;  // 1 loads, 0 stores
    u8 unk_E;  // 4 loads, 0 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 pad_10[0x1C];
    u32 unk_2C;  // 1 loads, 0 stores
    u8 pad_30[0x74];
    u16 unk_A4;  // 2 loads, 0 stores
    u8 unk_A6;  // 3 loads, 0 stores
    u8 unk_A7;  // 39 loads, 0 stores
    u8 pad_A8[0x2C];
    u32 unk_D4;  // 2 loads, 0 stores
    u16 unk_D8;  // 5 loads, 6 stores
    u16 unk_DA;  // 1 loads, 2 stores
    u8 unk_DC;  // 7 loads, 3 stores
    u8 unk_DD;  // 2 loads, 3 stores
    u8 unk_DE;  // 1 loads, 0 stores
    u8 unk_DF;  // 1 loads, 0 stores
    u8 unk_E0;  // 1 loads, 0 stores
    u8 unk_E1;  // 1 loads, 0 stores
    u8 unk_E2;  // 1 loads, 2 stores
    u8 pad_E3[0x4];
    u8 unk_E7;  // 0 loads, 2 stores
    u8 pad_E8[0x4];
    u16 unk_EC;  // 1 loads, 2 stores
    u8 pad_EE[0xA];
    u32 unk_F8;  // 2 loads, 1 stores
    u8 pad_FC[0x10];
    u32 unk_10C;  // 1 loads, 1 stores
    u8 pad_110[0x10];
    u16 unk_120;  // 3 loads, 3 stores
    u16 unk_122;  // 1 loads, 0 stores
    u16 unk_124;  // 1 loads, 0 stores
    u16 unk_126;  // 1 loads, 0 stores
    u16 unk_128;  // 1 loads, 0 stores
    u8 pad_12A[0x2];
    u32 unk_12C;  // 0 loads, 1 stores
    u8 pad_130[0x1C];
    u32 unk_14C;  // 2 loads, 3 stores
    u8 pad_150[0x4];
    u8 unk_154;  // 4 loads, 0 stores
    u8 unk_155;  // 2 loads, 0 stores
    u8 unk_156;  // 3 loads, 0 stores
    u8 unk_157;  // 1 loads, 3 stores
    u8 pad_158[0x1A];
    u16 unk_172;  // 1 loads, 2 stores
    u8 pad_174[0x4];
    u16 unk_178;  // 0 loads, 1 stores
    u8 pad_17A[0x1];
    u8 unk_17B;  // 7 loads, 0 stores
    u8 unk_17C;  // 0 loads, 1 stores
    u8 pad_17D[0x7A];
    u8 unk_1F7;  // 0 loads, 1 stores
    u8 pad_1F8[0x20];
    u16 unk_218;  // 0 loads, 1 stores
    u8 pad_21A[0x2];
    u8 unk_21C;  // 0 loads, 1 stores
    u8 pad_21D[0x7A];
    u8 unk_297;  // 0 loads, 1 stores
    u8 pad_298[0x20];
    u16 unk_2B8;  // 0 loads, 1 stores
    u8 pad_2BA[0x2];
    u8 unk_2BC;  // 0 loads, 1 stores
    u8 pad_2BD[0x7A];
    u8 unk_337;  // 0 loads, 1 stores
    u8 pad_338[0x20];
    u16 unk_358;  // 0 loads, 1 stores
    u8 pad_35A[0x2];
    u8 unk_35C;  // 0 loads, 1 stores
    u8 pad_35D[0x7A];
    u8 unk_3D7;  // 0 loads, 1 stores
    u8 pad_3D8[0x20];
    u16 unk_3F8;  // 0 loads, 1 stores
    u8 pad_3FA[0x2];
    u8 unk_3FC;  // 0 loads, 1 stores
    u8 pad_3FD[0x7A];
    u8 unk_477;  // 0 loads, 1 stores
    u8 pad_478[0xF1C];
    u8 unk_1394;  // 1 loads, 0 stores
    u8 pad_1395[0x1F];
    u32 unk_13B4;  // 2 loads, 1 stores
    u8 pad_13B8[0x1C];
    u32 unk_13D4;  // 1 loads, 1 stores
    u8 pad_13D8[0x1C];
    u8 unk_13F4;  // 4 loads, 1 stores
    u8 unk_13F5;  // 3 loads, 1 stores
    u8 unk_13F6;  // 2 loads, 0 stores
    u8 pad_13F7[0x1];
    u16 unk_13F8;  // 0 loads, 1 stores
    u16 unk_13FA;  // 0 loads, 1 stores
    u16 unk_13FC;  // 0 loads, 1 stores
    u16 unk_13FE;  // 0 loads, 1 stores
    u16 unk_1400;  // 0 loads, 1 stores
    u8 unk_1402;  // 0 loads, 1 stores
    u8 pad_1403[0x2];
    u8 unk_1405;  // 2 loads, 0 stores
    u8 pad_1406[0x5E];
    u32 unk_1464;  // 5 loads, 1 stores
    u8 pad_1468[0x4];
    u8 unk_146C;  // 1 loads, 1 stores
    u8 unk_146D;  // 1 loads, 1 stores
    u16 unk_146E;  // 1 loads, 1 stores
    u8 unk_1470;  // 1 loads, 1 stores
    u8 pad_1471[0x3];
    u32 unk_1474;  // 3 loads, 1 stores
    u16 unk_1478;  // 2 loads, 1 stores
    u16 unk_147A;  // 0 loads, 1 stores
    u16 unk_147C;  // 0 loads, 1 stores
    u16 unk_147E;  // 0 loads, 1 stores
    u32 unk_1480;  // 3 loads, 1 stores
    u32 unk_1484;  // 0 loads, 1 stores
    u32 unk_1488;  // 0 loads, 1 stores
    u32 unk_148C;  // 0 loads, 1 stores
    u32 unk_1490;  // 0 loads, 1 stores
    u32 unk_1494;  // 0 loads, 1 stores
    u32 unk_1498;  // 0 loads, 1 stores
    u32 unk_149C;  // 0 loads, 1 stores
    u32 unk_14A0;  // 0 loads, 1 stores
    u32 unk_14A4;  // 0 loads, 1 stores
    u32 unk_14A8;  // 1 loads, 1 stores
    u8 pad_14AC[0x10];
} Obj_1_bss_3C30;
extern Obj_1_bss_3C30 lbl_1_bss_3C30;

// lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 304}
typedef struct {
    u16 unk_0;  // 25 loads, 0 stores
    u16 unk_2;  // 35 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 108 loads, 0 stores
    u16 unk_A;  // 22 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 56 loads, 0 stores
    u16 unk_12;  // 53 loads, 0 stores
    u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_bss_25BA0: .bss size 0xA8, 5 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

#endif  // REL_MAIN_REL_GAME_H
#ifndef REL_MAIN_REL_SEL_STATIC_DISP_H
#define REL_MAIN_REL_SEL_STATIC_DISP_H

// lbl_1_bss_25BA0: .bss size 0xA8, 7 refs from sel_static_disp.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

#endif  // REL_MAIN_REL_SEL_STATIC_DISP_H

extern f64 lbl_1_rodata_99B0;
extern int fn_1_8623C(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
u8 lbl_1_bss_8E530;
u8 lbl_1_bss_8E530__fzgx_offset_1;
u16 lbl_1_bss_8E530__fzgx_offset_2;
u32 lbl_1_bss_8E534;
u32 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
u32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = lbl_1_bss_8E518__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = lbl_1_bss_8E530;
    s = lbl_1_bss_8E530__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E530__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = fzgx_obj_lbl_1_bss_8E548;
    s = lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
}
#pragma section code_type ".text"

void fn_1_14A328(void) {
    Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
    f32 v0;
    s32 v1;
    u8 v2;
    void * v3;
    void * v4;
    u8 v5;
    u8 v8;
    u32 v9;
    u32 v10;
    void * v12;
    void * v11;
    u8 v13;
    s32 v15;
    u8 v16;
    u8 v17;
    u8 v18;
    void * v19;
    void * v20;
    u8 v21;
    u8 v24;
    u32 v25;
    u32 v26;
    void * v28;
    void * v27;
    u8 v29;
    s32 v31;
    u8 v32;
    u8 v33;
    void * v34;
    void * v35;
    u8 v36;
    u8 v39;
    u32 v40;
    u32 v41;
    void * v43;
    void * v42;
    u8 v44;
    s32 v46;
    u8 v47;
    u8 v48;
    int t0;
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;

    if ((s32)lbl_1_bss_25BA0.unk_0 == 0 && ((lbl_1_bss_9F8.unk_8 >> 8) & 0x1) != 0) {
    p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
    if ((p_lbl_1_bss_3C30->unk_0 & 0x4000000) != 0) {
    v2 = p_lbl_1_bss_3C30->unk_9;
    if (v2 >= 2) {
    fzgx_obj_lbl_1_bss_8E51D = 7;
    lbl_1_bss_8E518__fzgx_offset_4 = 0;
    if (lbl_1_bss_960 == 1) {
    fzgx_obj_lbl_1_bss_8E548 = 4;
    } else {
    fzgx_obj_lbl_1_bss_8E548 = v2 < 6 ? v2 : 6;
    }
    if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
    v3 = &lbl_1_bss_8E530;
    v4 = &lbl_1_bss_8E538;
    t0 = fn_1_8623C();
    v5 = fzgx_obj_lbl_1_bss_8E548;
    v8 = *((u8 *)&lbl_1_bss_3C30 + t0 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v1 = v8 - ((v5 >> 1) - 1);
    lbl_1_bss_8E538 = v8;
    lbl_1_bss_8E538 = v1;
    if (v1 < 0) {
    *(u32 *)((u8 *)v4 + 0) = 0;
    } else {
    v9 = (p_lbl_1_bss_3C30->unk_9 - v5);
    if (v1 >= (s32)v9) {
    *(u32 *)((u8 *)v4 + 0) = v9;
    }
    }
    v10 = *(u32 *)(v4);
    v0 = lbl_1_rodata_99B0;
    *(f32 *)((u8 *)v3 + 0) = (f32)(s32)v10;
    } else {
    v11 = &lbl_1_bss_8E530;
    v12 = (void *)(u32)&lbl_1_bss_8E538;
    t1 = fn_1_8623C();
    v13 = fzgx_obj_lbl_1_bss_8E548;
    v1 = *((u8 *)&lbl_1_bss_3C30 + t1 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v15 = v1 - ((v13 >> 1) - 1);
    lbl_1_bss_8E538 = v1;
    lbl_1_bss_8E538 = v15;
    if (v15 < 0) {
    *(u32 *)((u8 *)v12 + 0) = 0;
    } else {
    v16 = fzgx_obj_lbl_1_bss_8E51D;
    if (*(s32 *)v12 >= (v16 == 4 ? lbl_1_bss_3C30.unk_8 : p_lbl_1_bss_3C30->unk_9) - v13) {
    *(s32 *)v12 = (u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : p_lbl_1_bss_3C30->unk_9) - v13;
    }
    }
    v17 = v16;
    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
    v1 = (u32)&lbl_1_bss_3C30;
    v17 = *(u8 *)(v1 + 8);
    } else {
    v17 = p_lbl_1_bss_3C30->unk_9;
    }
    v1 = 0x43300000;
    v0 = ((u32)(v17 & 0xFF));
    *(f32 *)((u8 *)v11 + 0) = (f32)(v0 - (f32)(u32)fzgx_obj_lbl_1_bss_8E548);
    }
    } else {
    fzgx_obj_lbl_1_bss_8E51D = 8;
    }
    } else {
    v18 = p_lbl_1_bss_3C30->unk_5;
    switch (v18) {
    case 1:
    fzgx_obj_lbl_1_bss_8E51D = 1;
    lbl_1_bss_8E518__fzgx_offset_4 = 0;
    if (lbl_1_bss_960 == 1) {
    fzgx_obj_lbl_1_bss_8E548 = 4;
    } else {
    v1 = p_lbl_1_bss_3C30->unk_9;
    fzgx_obj_lbl_1_bss_8E548 = (u32)v1 < 6 ? v1 : 6;
    }
    if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
    v19 = &lbl_1_bss_8E530;
    v20 = &lbl_1_bss_8E538;
    t2 = fn_1_8623C();
    v21 = fzgx_obj_lbl_1_bss_8E548;
    v24 = *((u8 *)&lbl_1_bss_3C30 + t2 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v1 = v24 - ((v21 >> 1) - 1);
    lbl_1_bss_8E538 = v24;
    lbl_1_bss_8E538 = v1;
    if (v1 < 0) {
    *(u32 *)((u8 *)v20 + 0) = 0;
    } else {
    v25 = (lbl_1_bss_3C30.unk_9 - v21);
    if (v1 >= (s32)v25) {
    *(u32 *)((u8 *)v20 + 0) = v25;
    }
    }
    v26 = *(u32 *)(v20);
    v0 = lbl_1_rodata_99B0;
    *(f32 *)((u8 *)v19 + 0) = (f32)(s32)v26;
    } else {
    v27 = &lbl_1_bss_8E530;
    v28 = &lbl_1_bss_8E538;
    t3 = fn_1_8623C();
    v29 = fzgx_obj_lbl_1_bss_8E548;
    v1 = *((u8 *)&lbl_1_bss_3C30 + t3 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v31 = v1 - ((v29 >> 1) - 1);
    lbl_1_bss_8E538 = v1;
    lbl_1_bss_8E538 = v31;
    if (v31 < 0) {
    *(u32 *)((u8 *)v28 + 0) = 0;
    } else {
    v32 = fzgx_obj_lbl_1_bss_8E51D;
    if (*(s32 *)v28 >= (v32 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v29) {
    *(s32 *)v28 = (u8)(v32 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v29;
    }
    }
    v33 = v32;
    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
    v1 = (u32)&lbl_1_bss_3C30;
    v33 = *(u8 *)(v1 + 8);
    } else {
    v1 = (u32)&lbl_1_bss_3C30;
    v33 = *(u8 *)(v1 + 9);
    }
    v1 = 0x43300000;
    v0 = ((u32)(v33 & 0xFF));
    *(f32 *)((u8 *)v27 + 0) = (f32)(v0 - (f32)(u32)fzgx_obj_lbl_1_bss_8E548);
    break;
    case 2:
    fzgx_obj_lbl_1_bss_8E51D = 6;
    break;
    case 0:
case 6:
    fzgx_obj_lbl_1_bss_8E51D = 3;
    lbl_1_bss_8E518__fzgx_offset_4 = 0;
    if (lbl_1_bss_960 == 1) {
    fzgx_obj_lbl_1_bss_8E548 = 4;
    } else {
    v1 = (u32)&lbl_1_bss_3C30;
    v1 = *(u8 *)(v1 + 9);
    fzgx_obj_lbl_1_bss_8E548 = (u32)v1 < 6 ? v1 : 6;
    }
    if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
    v34 = &lbl_1_bss_8E530;
    v35 = &lbl_1_bss_8E538;
    t4 = fn_1_8623C();
    v36 = fzgx_obj_lbl_1_bss_8E548;
    v39 = *((u8 *)&lbl_1_bss_3C30 + t4 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v1 = v39 - ((v36 >> 1) - 1);
    lbl_1_bss_8E538 = v39;
    lbl_1_bss_8E538 = v1;
    if (v1 < 0) {
    *(u32 *)((u8 *)v35 + 0) = 0;
    } else {
    v40 = (lbl_1_bss_3C30.unk_9 - v36);
    if (v1 >= (s32)v40) {
    *(u32 *)((u8 *)v35 + 0) = v40;
    }
    }
    v41 = *(u32 *)(v35);
    v0 = lbl_1_rodata_99B0;
    *(f32 *)((u8 *)v34 + 0) = (f32)(s32)v41;
    } else {
    v42 = &lbl_1_bss_8E530;
    v43 = &lbl_1_bss_8E538;
    t5 = fn_1_8623C();
    v44 = fzgx_obj_lbl_1_bss_8E548;
    v1 = *((u8 *)&lbl_1_bss_3C30 + t5 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v46 = v1 - ((v44 >> 1) - 1);
    lbl_1_bss_8E538 = v1;
    lbl_1_bss_8E538 = v46;
    if (v46 < 0) {
    *(u32 *)((u8 *)v43 + 0) = 0;
    } else {
    v47 = fzgx_obj_lbl_1_bss_8E51D;
    if (*(s32 *)v43 >= (v47 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v44) {
    *(s32 *)v43 = (u8)(v47 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v44;
    }
    }
    v48 = v47;
    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
    v1 = (u32)&lbl_1_bss_3C30;
    v48 = *(u8 *)(v1 + 8);
    } else {
    v1 = (u32)&lbl_1_bss_3C30;
    v48 = *(u8 *)(v1 + 9);
    }
    v1 = 0x43300000;
    *(f32 *)((u8 *)v42 + 0) = (f32)(((f32)((f32)(u32)(v48 & 0xFF))) - (f32)(u32)fzgx_obj_lbl_1_bss_8E548);
    break;
    default:
    fzgx_obj_lbl_1_bss_8E51D = 8;
    }
    }
    }
    }
    }
    return;
}
/* fzgx:end fn_1_14A328 */

/* fzgx:begin fn_1_14A9CC */
// fn_1_14A9CC: empty in retail (single blr).
void fn_1_14A9CC(void) {
}
/* fzgx:end fn_1_14A9CC */

/* fzgx:begin fn_1_14A9D0 */
typedef double f64;

#pragma section code_type ".fzgxpool"
static const u32 fn_1_14A9D0_fzgx_pool_table1[95] = {0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82A482AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C3, 0x82C582C7, 0x82CE82D1, 0x82D482D7, 0x82DA82CF, 0x82D282D5, 0x82D882DB, 0x829F82A1, 0x82A382A5, 0x82A782C1, 0x82E182E3, 0x82E582EC, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x8377837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x83758378, 0x837B8370, 0x83738376, 0x8379837C, 0x83408342, 0x83448346, 0x83488362, 0x83838385, 0x8387838E, 0x00000000, 0x81968196, 0x81960000, 0x83478374, 0x835B838D, 0x00000000, 0x8265817C, 0x82798264, 0x8271826E, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_14A9D0_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_14A9D0_fzgx_pool_table1; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_14A9D0_fzgx_pool_prime2(void) {
volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
s = 0.0f;
d = 4503599627370496.0;
d = 4503601774854144.0;
s = 0.20000000298023224f;
s = 0.10000000149011612f;
s = 0.05999999865889549f;
s = 0.014999999664723873f;
s = -0.10000000149011612f;
s = 0.05000000074505806f;
s = -0.05000000074505806f;
}
static const u32 fn_1_14A9D0_fzgx_pool_table3[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_14A9D0_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_14A9D0_fzgx_pool_table3; } /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
struct fn_1_14A9D0_lbl_1_bss_8E518 {
u8 pad_0[0x4];
u8 unk_4;
u8 pad_5[0xB];
u32 unk_10;
u8 pad_14[0x4];
f32 unk_18;
f32 unk_1C;
s32 unk_20;
s32 unk_24;
u8 pad_28[0x8];
u8 unk_30;
u8 pad_31[0x3];
f32 unk_34;
u8 unk_38;
u8 pad_39[0x3];
u32 unk_3C;
};
struct fn_1_14A9D0_lbl_1_bss_9F8 {
u8 pad_0[0x10];
u16 unk_10;
u16 unk_12;
};

static const u8 fzgx_pool_fzgx_unused_rodata_9828[172] = {0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xC8,0x82,0xC9,0x82,0xCA,0x82,0xCB,0x82,0xCC,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xDC,0x82,0xDD,0x82,0xDE,0x82,0xDF,0x82,0xE0,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xE7,0x82,0xE8,0x82,0xE9,0x82,0xEA,0x82,0xEB,0x82,0xED,0x82,0xEE,0x82,0xEF,0x82,0xF0,0x82,0xF1,0x82,0xA4,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC3,0x82,0xC5,0x82,0xC7,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xC1,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x82,0xEC,0x00,0x00,0x00,0x00};
const u8 fzgx_pool_lbl_1_rodata_98D4[208] = {0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x69,0x83,0x6A,0x83,0x6B,0x83,0x6C,0x83,0x6D,0x83,0x6E,0x83,0x71,0x83,0x74,0x83,0x77,0x83,0x7A,0x83,0x7D,0x83,0x7E,0x83,0x80,0x83,0x81,0x83,0x82,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x89,0x83,0x8A,0x83,0x8B,0x83,0x8C,0x83,0x8D,0x83,0x8F,0x83,0x90,0x83,0x91,0x83,0x92,0x83,0x93,0x83,0x94,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x64,0x83,0x66,0x83,0x68,0x83,0x6F,0x83,0x72,0x83,0x75,0x83,0x78,0x83,0x7B,0x83,0x70,0x83,0x73,0x83,0x76,0x83,0x79,0x83,0x7C,0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x62,0x83,0x83,0x83,0x85,0x83,0x87,0x83,0x8E,0x00,0x00,0x00,0x00,0x81,0x96,0x81,0x96,0x81,0x96,0x00,0x00,0x83,0x47,0x83,0x74,0x83,0x5B,0x83,0x8D,0x00,0x00,0x00,0x00,0x82,0x65,0x81,0x7C,0x82,0x79,0x82,0x64,0x82,0x71,0x82,0x6E,0x00,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_1_rodata_99A4 = 0.0f;
const u8 fzgx_pool_lbl_1_rodata_99A8[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f64 fzgx_pool_lbl_1_rodata_99B0 = 4503601774854144.0;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_8 = 0.200000003f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_C = 0.100000001f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_10 = 0.0599999987f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_14 = 0.0149999997f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_18 = -0.100000001f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_1C = 0.0500000007f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_20 = -0.0500000007f;
const u8 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_24[4] = {0x00,0x00,0x00,0x00};
/* 1 when x is within eps of n */
/* cursor count that fits on the page */
typedef struct lbl_1_bss_9F8_t {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0x3c];
} lbl_1_bss_9F8_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_9F8_t fzgx_obj_lbl_1_bss_9F8;
u32 fzgx_obj_lbl_1_bss_A48[16];
u32 fzgx_obj_lbl_1_bss_A88[6];
u32 fzgx_obj_lbl_1_bss_AA0[84];
u32 lbl_1_bss_BF0[32];
u32 fzgx_obj_lbl_1_bss_C70[20];

#pragma section code_type ".fzgxpool"
static void fn_1_14A9D0_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_9F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_AA0;
    s = *(u8 *)&lbl_1_bss_BF0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_C70;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
void fn_1_14A9D0(arg0, arg1, arg2, arg3, arg4, arg5, arg6)
u8 arg0;
s32 arg1;
u32 arg2;
u32 arg3;
s32 arg4;
s32 arg5;
u8 arg6;
{
struct fn_1_14A9D0_lbl_1_bss_8E518 *p;
f32 *pos;
s32 *target;
s32 n;
u32 elapsed;
f32 x;
struct { f32 value; } cur;
struct { f32 value; } lo;
f32 k;
f32 step;
f32 delta;
s32 near;
p = &(*((struct fn_1_14A9D0_lbl_1_bss_8E518 *)&lbl_1_bss_8E518));
p->unk_38 = arg0;
p->unk_3C = arg3;
if (arg5 != 0) {
pos = &p->unk_1C;
target = &p->unk_24;
} else {
pos = &p->unk_18;
target = &p->unk_20;
}
if ((lbl_801A66A4 - p->unk_10) > arg3) {
if (((fzgx_obj_lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((fzgx_obj_lbl_1_bss_9F8.unk_12 >> 3) & 1)) {
n = *target;
if (n > 0) {
*target = n - 1;
fn_1_A2D84(0xA9010400U);
}
} else if (((fzgx_obj_lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((fzgx_obj_lbl_1_bss_9F8.unk_12 >> 2) & 1)) {
n = *target;
if (n < (p->unk_38 - p->unk_30)) {
*target = n + 1;
fn_1_A2D84(0xA9010400U);
}
}
}
elapsed = lbl_801A66A4 - p->unk_10;
if (elapsed > arg2) {
if (elapsed >= p->unk_3C) {
cur.value = *pos;
lo.value = 0.0f;
delta = 0.2f * ((f32)*target - cur.value);
*pos = cur.value + delta;
*pos = (((*pos) < (lo.value)) ? (lo.value) : (((*pos) > (((f32)((p)->unk_38 - (p)->unk_30)))) ? (((f32)((p)->unk_38 - (p)->unk_30))) : (*pos))) ;
n = *target;
x = *pos;
near = ((x > (n) + (0.1f)) ? 0 : ((x < (n) - (0.1f)) ? 0 : 1)) ;
if (near != 0) {
*pos = (f32)n;
}
goto done; /* Retail's settled interpolation path skips the scrolling update below. */
} else if (arg1 != 0) {
if (p->unk_4 != 0) {
k = 0.06f;
} else {
k = 0.015f;
}
step = k * ((f32)*target - *pos);
if (step < 0.0f) {
if (step > -0.1f) {
step = -0.1f;
}
} else if (step < 0.1f) {
step = 0.1f;
}
*pos += step;
} else {
n = *target;
x = *pos;
if (n > x) {
x += 0.05f;
*pos = (((x) < ((f32)n)) ? (x) : ((f32)n)) ;
} else if (n < x) {
x += -0.05f;
*pos = (((x) > ((f32)n)) ? (x) : ((f32)n)) ;
}
}
x = *pos;
*pos = (((x) < (0.0f)) ? (0.0f) : (((x) > (((f32)((p)->unk_38 - (p)->unk_30)))) ? (((f32)((p)->unk_38 - (p)->unk_30))) : (x))) ;
if ((s32)p->unk_34 != (s32)*pos) {
fn_1_A2D84(0xA9010500U);
}
p->unk_34 = *pos;
n = *target;
x = *pos;
near = ((x > (n) + (0.1f)) ? 0 : ((x < (n) - (0.1f)) ? 0 : 1)) ;
if (near != 0) {
*pos = (f32)n;
elapsed = (*(u32 volatile *)&p->unk_3C) /* Retail reloads this field. */;
p->unk_10 = (*(volatile u32 *)&lbl_801A66A4) - elapsed;
}
}
done:
if (arg4 != 0) {
return;
}
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_14A9D0 */

/* fzgx:begin fn_1_14AE94 noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

void fn_1_14AE94(void) {
    if ((s32)lbl_1_bss_8E540 != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if ((s32)lbl_1_bss_8E540 == 0) {
        lbl_1_bss_8E540 = 1;
    }
}
/* fzgx:end fn_1_14AE94 */

/* fzgx:begin fn_1_14AED4 noprologue */
typedef struct {
    u32 v[8];
} Word8_fn_1_14AED4;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8_fn_1_14AED4;

typedef struct {
    u32 value[22];
} Fn139F18Data_fn_1_14AED4;

typedef struct StaticDispParams_fn_1_14AED4 {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams_fn_1_14AED4;

struct Struct_26F8_fn_1_14AED4 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab_fn_1_14AED4;

struct fn_1_13F8C4_lbl_801A6410_fn_1_14AED4 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_14AED4 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440_fn_1_14AED4 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source_fn_1_14AED4;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display_fn_1_14AED4;

struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_14AED4 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14AED4 {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_14AED4 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14AED4 **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry_fn_1_14AED4;

typedef struct fn_1_150C8C_Entry_fn_1_14AED4 {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry_fn_1_14AED4;

typedef struct fn_1_150C8C_Object_fn_1_14AED4 {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry_fn_1_14AED4 entries[1];
} fn_1_150C8C_Object_fn_1_14AED4;

typedef struct fn_1_150F30_StaticDisp_fn_1_14AED4 {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp_fn_1_14AED4;

typedef struct Fn14E09CValue_fn_1_14AED4 {
    void *value;
} Fn14E09CValue_fn_1_14AED4;

typedef struct Fn14E09CRef_fn_1_14AED4 {
    u8 pad8[8];
    Fn14E09CValue_fn_1_14AED4 *value;
} Fn14E09CRef_fn_1_14AED4;

typedef struct Fn14E09CObj_fn_1_14AED4 {
    u8 pad344[0x344];
    Fn14E09CRef_fn_1_14AED4 *ref;
} Fn14E09CObj_fn_1_14AED4;

typedef struct DispNode_fn_1_14AED4 {
    u8 pad[4];
    f32 value;
} DispNode_fn_1_14AED4;

typedef struct DispChildList_fn_1_14AED4 {
    DispNode_fn_1_14AED4 *child[3];
} DispChildList_fn_1_14AED4;

typedef struct DispObject_fn_1_14AED4 {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList_fn_1_14AED4 *children;
} DispObject_fn_1_14AED4;

typedef struct fn_1_151668_StaticDispEntry_fn_1_14AED4 {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject_fn_1_14AED4 *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry_fn_1_14AED4;

typedef struct fn_1_151668_StaticDisp_fn_1_14AED4 {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry_fn_1_14AED4 entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp_fn_1_14AED4;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);


extern void fn_1_3F2A0(void);
extern int fn_1_8623C(void);

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
f32 lbl_1_bss_8E534;
s32 lbl_1_bss_8E538;
s32 lbl_1_bss_8E53C;
s32 fzgx_obj_lbl_1_bss_8E540;
s32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;
u8 lbl_1_bss_8E550;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E551;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
u32 lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
u32 lbl_1_bss_8E560[4];
u32 lbl_1_bss_8E570[7];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
u32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fn_1_14AED4_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = lbl_1_bss_8E518__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = fzgx_obj_lbl_1_bss_8E548;
    s = lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
    s = lbl_1_bss_8E550;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = lbl_1_bss_8E554__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"


/* number of selectable entries in the current mode */
static inline u8 fn_1_14AED4_sel_max(void) {
    return fzgx_obj_lbl_1_bss_8E51D == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9;
}

static inline void fn_1_14AED4_set_from_list(f32 *pos, s32 *value) {
    u8 v;
    fn_1_3F2A0();
    v = *((u8 *)&lbl_1_bss_3C30 + fn_1_8623C() * 0xA0 + 0xDC);
    lbl_1_bss_8E53C = v;
    lbl_1_bss_8E53C = lbl_1_bss_8E53C - (fzgx_obj_lbl_1_bss_8E548 / 2 - 1);
    if (*value < 0) {
        *value = 0;
    } else if (*value >= lbl_1_bss_3C30.unk_9 - fzgx_obj_lbl_1_bss_8E548) {
        *value = lbl_1_bss_3C30.unk_9 - fzgx_obj_lbl_1_bss_8E548;
    }
    *pos = *value;
}

static inline void fn_1_14AED4_set_from_max(s32 *value, f32 *pos) {
    u8 v;
    fn_1_3F2A0();
    v = *((u8 *)&lbl_1_bss_3C30 + fn_1_8623C() * 0xA0 + 0xDC);
    lbl_1_bss_8E53C = v;
    lbl_1_bss_8E53C = v - (fzgx_obj_lbl_1_bss_8E548 / 2 - 1);
    if (*value < 0) {
        *value = 0;
    } else {
        s32 limit = fn_1_14AED4_sel_max() - fzgx_obj_lbl_1_bss_8E548;
        if (*value >= limit) {
            *value = fn_1_14AED4_sel_max() - fzgx_obj_lbl_1_bss_8E548;
        }
    }
    *pos = (f32)fn_1_14AED4_sel_max() - (f32)fzgx_obj_lbl_1_bss_8E548;
}

void fn_1_14AED4(void) {
    Obj_1_bss_9F8 *flags;

    fn_1_14A9D0(fn_1_14AED4_sel_max(), 1, 30, 180, 1, 0);
    flags = &lbl_1_bss_9F8;
    if (((flags->unk_8 >> 8) & 1) && !((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
        if ((lbl_801A66A4) - fzgx_obj_lbl_1_bss_8E528 >= 195) {
            fzgx_obj_lbl_1_bss_8E51D = 2;
            lbl_1_bss_8E518__fzgx_offset_4 = 0;
            if (lbl_1_bss_960 == 1) {
                fzgx_obj_lbl_1_bss_8E548 = 4;
            } else {
                fzgx_obj_lbl_1_bss_8E548 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
            }
            if (fzgx_obj_lbl_1_bss_8E544 != 0) {
                f32 *pos = &lbl_1_bss_8E534;
                s32 *value = (s32 *)&lbl_1_bss_8E53C;
                fn_1_14AED4_set_from_list(pos, value);
            } else {
                s32 *value;
                f32 *pos;
                pos = &lbl_1_bss_8E534;
                value = &lbl_1_bss_8E53C;
                fn_1_14AED4_set_from_max(value, pos);
            }
            fn_1_A2D84(0xA9010400);
        } else {
            fn_1_14CA4C();
        }
    } else if ((flags->unk_8 >> 9) & 1) {
        fzgx_obj_lbl_1_bss_8E51D = 0;
        fn_1_A2D84(0xA9010400);
    }
}
/* fzgx:end fn_1_14AED4 */

/* fzgx:begin fn_1_14B1B8 noprologue */
// fn_1_14B1B8: empty in retail (single blr).
void fn_1_14B1B8(void) {
}
/* fzgx:end fn_1_14B1B8 */

/* fzgx:begin fn_1_14B1BC noprologue */
void fn_1_14B1BC(void) {
    int flag = lbl_1_bss_8E544;

    if (flag != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if (flag == 0) {
        lbl_1_bss_8E544 = 1;
    }
}
/* fzgx:end fn_1_14B1BC */

/* fzgx:begin fn_1_14B1FC noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"

/* begin rel/main_rel/game.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef REL_MAIN_REL_GAME_H
#define REL_MAIN_REL_GAME_H

/* begin rel/main_rel/globals.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern s16 lbl_1_bss_960;

// lbl_1_bss_3C30: .bss size 0x14BC, referenced by 95 functions, shape {'object': 411}
typedef struct {
    u32 unk_0;  // 35 loads, 5 stores
    u8 unk_4;  // 3 loads, 0 stores
    u8 unk_5;  // 34 loads, 2 stores
    u8 unk_6;  // 12 loads, 0 stores
    u8 unk_7;  // 1 loads, 0 stores
    u8 unk_8;  // 47 loads, 0 stores
    u8 unk_9;  // 55 loads, 0 stores
    u8 pad_A[0x3];
    u8 unk_D;  // 1 loads, 0 stores
    u8 unk_E;  // 4 loads, 0 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 pad_10[0x1C];
    u32 unk_2C;  // 1 loads, 0 stores
    u8 pad_30[0x74];
    u16 unk_A4;  // 2 loads, 0 stores
    u8 unk_A6;  // 3 loads, 0 stores
    u8 unk_A7;  // 39 loads, 0 stores
    u8 pad_A8[0x2C];
    u32 unk_D4;  // 2 loads, 0 stores
    u16 unk_D8;  // 5 loads, 6 stores
    u16 unk_DA;  // 1 loads, 2 stores
    u8 unk_DC;  // 7 loads, 3 stores
    u8 unk_DD;  // 2 loads, 3 stores
    u8 unk_DE;  // 1 loads, 0 stores
    u8 unk_DF;  // 1 loads, 0 stores
    u8 unk_E0;  // 1 loads, 0 stores
    u8 unk_E1;  // 1 loads, 0 stores
    u8 unk_E2;  // 1 loads, 2 stores
    u8 pad_E3[0x4];
    u8 unk_E7;  // 0 loads, 2 stores
    u8 pad_E8[0x4];
    u16 unk_EC;  // 1 loads, 2 stores
    u8 pad_EE[0xA];
    u32 unk_F8;  // 2 loads, 1 stores
    u8 pad_FC[0x10];
    u32 unk_10C;  // 1 loads, 1 stores
    u8 pad_110[0x10];
    u16 unk_120;  // 3 loads, 3 stores
    u16 unk_122;  // 1 loads, 0 stores
    u16 unk_124;  // 1 loads, 0 stores
    u16 unk_126;  // 1 loads, 0 stores
    u16 unk_128;  // 1 loads, 0 stores
    u8 pad_12A[0x2];
    u32 unk_12C;  // 0 loads, 1 stores
    u8 pad_130[0x1C];
    u32 unk_14C;  // 2 loads, 3 stores
    u8 pad_150[0x4];
    u8 unk_154;  // 4 loads, 0 stores
    u8 unk_155;  // 2 loads, 0 stores
    u8 unk_156;  // 3 loads, 0 stores
    u8 unk_157;  // 1 loads, 3 stores
    u8 pad_158[0x1A];
    u16 unk_172;  // 1 loads, 2 stores
    u8 pad_174[0x4];
    u16 unk_178;  // 0 loads, 1 stores
    u8 pad_17A[0x1];
    u8 unk_17B;  // 7 loads, 0 stores
    u8 unk_17C;  // 0 loads, 1 stores
    u8 pad_17D[0x7A];
    u8 unk_1F7;  // 0 loads, 1 stores
    u8 pad_1F8[0x20];
    u16 unk_218;  // 0 loads, 1 stores
    u8 pad_21A[0x2];
    u8 unk_21C;  // 0 loads, 1 stores
    u8 pad_21D[0x7A];
    u8 unk_297;  // 0 loads, 1 stores
    u8 pad_298[0x20];
    u16 unk_2B8;  // 0 loads, 1 stores
    u8 pad_2BA[0x2];
    u8 unk_2BC;  // 0 loads, 1 stores
    u8 pad_2BD[0x7A];
    u8 unk_337;  // 0 loads, 1 stores
    u8 pad_338[0x20];
    u16 unk_358;  // 0 loads, 1 stores
    u8 pad_35A[0x2];
    u8 unk_35C;  // 0 loads, 1 stores
    u8 pad_35D[0x7A];
    u8 unk_3D7;  // 0 loads, 1 stores
    u8 pad_3D8[0x20];
    u16 unk_3F8;  // 0 loads, 1 stores
    u8 pad_3FA[0x2];
    u8 unk_3FC;  // 0 loads, 1 stores
    u8 pad_3FD[0x7A];
    u8 unk_477;  // 0 loads, 1 stores
    u8 pad_478[0xF1C];
    u8 unk_1394;  // 1 loads, 0 stores
    u8 pad_1395[0x1F];
    u32 unk_13B4;  // 2 loads, 1 stores
    u8 pad_13B8[0x1C];
    u32 unk_13D4;  // 1 loads, 1 stores
    u8 pad_13D8[0x1C];
    u8 unk_13F4;  // 4 loads, 1 stores
    u8 unk_13F5;  // 3 loads, 1 stores
    u8 unk_13F6;  // 2 loads, 0 stores
    u8 pad_13F7[0x1];
    u16 unk_13F8;  // 0 loads, 1 stores
    u16 unk_13FA;  // 0 loads, 1 stores
    u16 unk_13FC;  // 0 loads, 1 stores
    u16 unk_13FE;  // 0 loads, 1 stores
    u16 unk_1400;  // 0 loads, 1 stores
    u8 unk_1402;  // 0 loads, 1 stores
    u8 pad_1403[0x2];
    u8 unk_1405;  // 2 loads, 0 stores
    u8 pad_1406[0x5E];
    u32 unk_1464;  // 5 loads, 1 stores
    u8 pad_1468[0x4];
    u8 unk_146C;  // 1 loads, 1 stores
    u8 unk_146D;  // 1 loads, 1 stores
    u16 unk_146E;  // 1 loads, 1 stores
    u8 unk_1470;  // 1 loads, 1 stores
    u8 pad_1471[0x3];
    u32 unk_1474;  // 3 loads, 1 stores
    u16 unk_1478;  // 2 loads, 1 stores
    u16 unk_147A;  // 0 loads, 1 stores
    u16 unk_147C;  // 0 loads, 1 stores
    u16 unk_147E;  // 0 loads, 1 stores
    u32 unk_1480;  // 3 loads, 1 stores
    u32 unk_1484;  // 0 loads, 1 stores
    u32 unk_1488;  // 0 loads, 1 stores
    u32 unk_148C;  // 0 loads, 1 stores
    u32 unk_1490;  // 0 loads, 1 stores
    u32 unk_1494;  // 0 loads, 1 stores
    u32 unk_1498;  // 0 loads, 1 stores
    u32 unk_149C;  // 0 loads, 1 stores
    u32 unk_14A0;  // 0 loads, 1 stores
    u32 unk_14A4;  // 0 loads, 1 stores
    u32 unk_14A8;  // 1 loads, 1 stores
    u8 pad_14AC[0x10];
} Obj_1_bss_3C30;
extern Obj_1_bss_3C30 lbl_1_bss_3C30;

// lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 304}
typedef struct {
    u16 unk_0;  // 25 loads, 0 stores
    u16 unk_2;  // 35 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 108 loads, 0 stores
    u16 unk_A;  // 22 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 56 loads, 0 stores
    u16 unk_12;  // 53 loads, 0 stores
    u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_bss_25BA0: .bss size 0xA8, 5 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

// lbl_1_bss_D58: .bss size 0x18, 2 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_D58
#define FZGX_TYPES_LBL_1_BSS_D58
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u16 unk_0;  // 5 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58;
#endif
extern Obj_1_bss_D58 lbl_1_bss_D58;

#endif  // REL_MAIN_REL_GAME_H
#ifndef REL_MAIN_REL_SEL_STATIC_DISP_H
#define REL_MAIN_REL_SEL_STATIC_DISP_H

// lbl_1_bss_25BA0: .bss size 0xA8, 7 refs from sel_static_disp.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

// lbl_1_bss_D58: .bss size 0x18, 6 refs from sel_static_disp.c
#ifndef FZGX_TYPES_LBL_1_BSS_D58
#define FZGX_TYPES_LBL_1_BSS_D58
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u16 unk_0;  // 5 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58;
#endif
extern Obj_1_bss_D58 lbl_1_bss_D58;

#endif  // REL_MAIN_REL_SEL_STATIC_DISP_H

/* end rel/main_rel/sel_static_disp.h */

extern u32 lbl_801A66A4;
extern void fn_1_3F2A0(void);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_A2D84(u32);
extern void fn_1_14CA4C(void);
extern int fn_1_8623C(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
u32 lbl_1_bss_8E534;
s32 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
s32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;
u8 lbl_1_bss_8E550;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E551;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
u32 lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
u32 lbl_1_bss_8E560[4];
u32 lbl_1_bss_8E570[7];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
u32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = lbl_1_bss_8E518__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = fzgx_obj_lbl_1_bss_8E548;
    s = lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
    s = lbl_1_bss_8E550;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = lbl_1_bss_8E554__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"

/* row count of the list currently shown */
#define SEL_ROWS() (fzgx_obj_lbl_1_bss_8E51D == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9)

void fn_1_14B1FC(void) {
    Obj_1_bss_9F8 *flags;
    u8 mode;

    fn_1_3F2A0();
    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }

    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
        mode = lbl_1_bss_3C30.unk_8;
    } else {
        mode = lbl_1_bss_3C30.unk_9;
    }
    fn_1_14A9D0(mode, 1, 30, 180, 0, 1);

    flags = &lbl_1_bss_9F8;
    if (((flags->unk_8 >> 8) & 1) != 0) {
        if (((lbl_1_bss_D58.unk_8 >> 12) & 1) == 0) {
            if (lbl_801A66A4 - fzgx_obj_lbl_1_bss_8E528 >= 0xC3) {
                fzgx_obj_lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xA9010400);
            } else {
                fn_1_14CA4C();
            }
            return;
        }
    }
    if (((flags->unk_8 >> 9) & 1) != 0) {
        fzgx_obj_lbl_1_bss_8E51D = 1;
        lbl_1_bss_8E518__fzgx_offset_4 = 0;
        if (lbl_1_bss_960 == 1) {
            fzgx_obj_lbl_1_bss_8E548 = 4;
        } else {
            fzgx_obj_lbl_1_bss_8E548 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
        }
        if (fzgx_obj_lbl_1_bss_8E540 != 0) {
            s32 *idx;
            f32 *pos;
            s32 v;
            u8 n;
            s32 w;
            s32 max;
            pos = &lbl_1_bss_8E530;
            idx = &lbl_1_bss_8E538;
            v = fn_1_8623C();
            n = fzgx_obj_lbl_1_bss_8E548;
            w = *((u8 *)&lbl_1_bss_3C30 + v * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2);
            lbl_1_bss_8E538 = w;
            lbl_1_bss_8E538 = w - ((n / 2) - 1);
            w = lbl_1_bss_8E538;
            if (w < 0) {
                *idx = 0;
            } else {
                max = lbl_1_bss_3C30.unk_9 - n;
                if (w >= max) {
                    *idx = max;
                }
            }
            *pos = (f32)*idx;
        } else {
            s32 *idx;
            f32 *pos;
            s32 v;
            u8 n;
            s32 w;
            pos = &lbl_1_bss_8E530;
            idx = &lbl_1_bss_8E538;
            v = fn_1_8623C();
            n = fzgx_obj_lbl_1_bss_8E548;
            w = *((u8 *)&lbl_1_bss_3C30 + v * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2);
            lbl_1_bss_8E538 = w;
            lbl_1_bss_8E538 = w - ((n / 2) - 1);
            if (lbl_1_bss_8E538 < 0) {
                *idx = 0;
            } else if (*idx >= SEL_ROWS() - n) {
                *idx = (u8)SEL_ROWS() - n;
            }
            *pos = (f32)(u8)SEL_ROWS() - (f32)fzgx_obj_lbl_1_bss_8E548;
        }
        fn_1_A2D84(0xA9010400);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_14B1FC */

/* fzgx:begin fn_1_14B4FC noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

// fn_1_14B4FC: empty in retail (single blr).
void fn_1_14B4FC(void) {
}
/* fzgx:end fn_1_14B4FC */

/* fzgx:begin fn_1_14B500 noprologue */
/* local view of one seat's 0xA0-byte result record at lbl_1_bss_3C30+0xD4 (written by fn_1_2E928) */
typedef struct {
    u8 pad_0[0x18];
    u16 unk_18[6];
    u32 unk_24[5];
    u32 unk_38[18];
    u8 unk_80;
    u8 unk_81;
    u8 pad_82[0x1E];
} fn_1_14B500_Record;

/* local view of lbl_1_bss_3C30: the seat list at +0xE, the index byte at +0xA7, the records at +0xD4 */
typedef struct {
    u8 pad_0[0xE];
    u8 unk_E[30];
    u8 pad_2C[0x7B];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    fn_1_14B500_Record unk_D4[30];
} fn_1_14B500_Setup;

/* local view of one 0x38-byte entry of lbl_1_bss_8EF68 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x10];
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 pad_1D[0x1B];
} fn_1_14B500_Entry;


void fn_1_14B500(void) {
    s32 i;
    fn_1_14B500_Entry *e;
    fn_1_14B500_Record *rec;
    s32 flag;

    /* copy the first 10 seats of the list at +0xE and fields of their records */
    for (i = 0; i < 10; i++) {
        e = &((fn_1_14B500_Entry *)&lbl_1_bss_8EF68)[i];
        e->unk_1A = ((fn_1_14B500_Setup *)&lbl_1_bss_3C30)->unk_E[i];
        rec = &((fn_1_14B500_Setup *)&lbl_1_bss_3C30)->unk_D4[e->unk_1A];
        e->unk_0 = rec->unk_24[((fn_1_14B500_Setup *)&lbl_1_bss_3C30)->unk_A7];
        e->unk_4 = rec->unk_38[((fn_1_14B500_Setup *)&lbl_1_bss_3C30)->unk_A7];
        e->unk_18 = rec->unk_18[((fn_1_14B500_Setup *)&lbl_1_bss_3C30)->unk_A7];
        e->unk_1B = rec->unk_80;
        e->unk_1C = rec->unk_81;
    }
    if (fn_1_3F864() != 0) {
        fn_1_A2D84(0xA9070000);
    }
    flag = lbl_1_bss_8E540;
    if (flag != 0) {
        lbl_1_bss_8E528 = (lbl_801A66A4) - 0xbe;
    }
    if (flag == 0) {
        lbl_1_bss_8E540 = 1;
    }
}
/* fzgx:end fn_1_14B500 */

/* fzgx:begin fn_1_14B62C noprologue */
typedef struct {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0xA];
    u32 unk_10;
    u8 pad_14[0x8];
    f32 unk_1C;
    u8 pad_20[0x4];
    s32 unk_24;
    u8 pad_28[0x4];
    s32 unk_2C;
    u8 unk_30;
} SelState_8E518;

extern void fn_1_3F2A0(void);
extern int fn_1_8623C(void);

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
u32 lbl_1_bss_8E534;
s32 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
s32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;
u8 lbl_1_bss_8E550;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E551;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
u32 lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
u32 lbl_1_bss_8E560[4];
u32 lbl_1_bss_8E570[7];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
u32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fn_1_14B62C_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = lbl_1_bss_8E518__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = fzgx_obj_lbl_1_bss_8E548;
    s = lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
    s = lbl_1_bss_8E550;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = lbl_1_bss_8E554__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"


static inline u8 sel_count(SelState_8E518 *p) {
    return fzgx_obj_lbl_1_bss_8E51D == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9;
}

/* centre the visible window (n rows) on the current entry; the raw index and the
   centred index are distinct values so the raw store can sink below the subtract */
static inline void sel_scroll_a(SelState_8E518 *p, f32 *pos, s32 *top) {
    u8 n;
    s32 raw;
    s32 t;
    fn_1_3F2A0();
    raw = ((u8 *)&lbl_1_bss_3C30)[fn_1_8623C() * 0xA0 + 0xDC];
    n = fzgx_obj_lbl_1_bss_8E548;
    lbl_1_bss_8E53C = raw;
    t = raw - ((n >> 1) - 1);
    lbl_1_bss_8E53C = t;
    if (t < 0) {
        *top = 0;
    } else if (t >= lbl_1_bss_3C30.unk_9 - n) {
        *top = lbl_1_bss_3C30.unk_9 - n;
    }
    *pos = *top;
}

static inline void sel_scroll_b(SelState_8E518 *p, f32 *pos, s32 *top) {
    u8 n;
    s32 raw;
    s32 t;
    fn_1_3F2A0();
    raw = ((u8 *)&lbl_1_bss_3C30)[fn_1_8623C() * 0xA0 + 0xDC];
    n = fzgx_obj_lbl_1_bss_8E548;
    (*(s32 *)&lbl_1_bss_8E53C) = raw;
    t = raw - ((n >> 1) - 1);
    lbl_1_bss_8E53C = t;
    if (t < 0) {
        *top = 0;
    } else if (*top >= sel_count(p) - n) {
        *top = sel_count(p) - n;
    }
    *pos = (f32)sel_count(p) - (f32)fzgx_obj_lbl_1_bss_8E548;
}

void fn_1_14B62C(void) {
    SelState_8E518 *p = (SelState_8E518 *)(&fzgx_obj_lbl_1_bss_8E518);

    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }
    fn_1_14A9D0(sel_count(p), 1, 30, 180, 1, 0);
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        if (!((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
            if ((lbl_801A66A4) - fzgx_obj_lbl_1_bss_8E528 >= 195) {
                fzgx_obj_lbl_1_bss_8E51D = 4;
                lbl_1_bss_8E518__fzgx_offset_4 = 0;
                if (lbl_1_bss_960 == 1) {
                    fzgx_obj_lbl_1_bss_8E548 = 4;
                } else {
                    fzgx_obj_lbl_1_bss_8E548 = lbl_1_bss_3C30.unk_8 < 6 ? lbl_1_bss_3C30.unk_8 : 6;
                }
                if ((*(s32 *)&fzgx_obj_lbl_1_bss_8E544) != 0) {
                    f32 *pos = (f32 *)&lbl_1_bss_8E534;
                    s32 *top = (s32 *)&lbl_1_bss_8E53C;
                    sel_scroll_a(p, pos, top);
                } else {
                    s32 *top;
                    f32 *pos;
                    pos = (f32 *)&lbl_1_bss_8E534;
                    top = (s32 *)&lbl_1_bss_8E53C;
                    sel_scroll_b(p, pos, top);
                }
                fn_1_A2D84(0xA9010400);
            } else {
                fn_1_14CA4C();
            }
        }
    }
}
/* fzgx:end fn_1_14B62C */

/* fzgx:begin fn_1_14B8F8 noprologue */
// fn_1_14B8F8: empty in retail (single blr).
void fn_1_14B8F8(void) {
}
/* fzgx:end fn_1_14B8F8 */

/* fzgx:begin fn_1_14B8FC noprologue */
void fn_1_14B8FC(void) {
    s32 flag = lbl_1_bss_8E544;
    if (flag != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if (flag == 0) {
        lbl_1_bss_8E544 = 1;
    }
}
/* fzgx:end fn_1_14B8FC */

/* fzgx:begin fn_1_14B93C */
struct fn_1_14B93C_state {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[10];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[4];
    s32 unk_28;
    u8 pad_2C[4];
    u8 unk_30;
};
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_8E518[4];
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u32 fzgx_obj_lbl_1_bss_8E530;
u32 fzgx_obj_lbl_1_bss_8E534;
u32 fzgx_obj_lbl_1_bss_8E538;
u32 fzgx_obj_lbl_1_bss_8E53C;
u32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548[0x8];
#pragma section code_type ".fzgxpool"
static void fn_1_14B93C_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = lbl_1_bss_8E518__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E530;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E534;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E538;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
}
#pragma section code_type ".text"


void fn_1_14B93C(void) {
    u32 v0;
    s32 *v4;
    f32 *v3;
    u8 v5;
    s32 v6;
    s32 v7;
    s32 *v12;
    s32 v9;
    f32 *v11;
    u8 v8;
    u8 v13;
    s32 v14;
    s32 v15;
    u16 v16;
    u8 v17;
    fn_1_3F2A0();
    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        if (fzgx_obj_lbl_1_bss_8E51D == 4) v0 = lbl_1_bss_3C30.unk_8;
        else v0 = lbl_1_bss_3C30.unk_9;
        fn_1_14A9D0(v0,1,30,180,0,1);
        if (((*(u16 *)&lbl_1_bss_9F8.unk_8 >> 8) & 1) && !((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
            if (lbl_801A66A4 - fzgx_obj_lbl_1_bss_8E528 >= 195) {
                fzgx_obj_lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xA9010400);
            } else fn_1_14CA4C();
        } else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
            fzgx_obj_lbl_1_bss_8E51D = 3;
            lbl_1_bss_8E518__fzgx_offset_4 = 0;
            if (lbl_1_bss_960 == 1) fzgx_obj_lbl_1_bss_8E548[0] = 4;
            else {
                v0 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
                fzgx_obj_lbl_1_bss_8E548[0] = v0;
            }
            if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
                v3 = (f32 *)&fzgx_obj_lbl_1_bss_8E530;
                v4 = (s32 *)&fzgx_obj_lbl_1_bss_8E538;
                v6 = fn_1_8623C() * 160;
                v5 = fzgx_obj_lbl_1_bss_8E548[0];
                v7 = (v5 >> 1) - 1;
                v8 = *((u8 *)&lbl_1_bss_3C30 + v6 + lbl_1_bss_3C30.unk_A7 + 226);
                v9 = v8 - v7;
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v8;
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v9;
                if (v9 < 0) *v4 = 0;
                else {
                    s32 limit = lbl_1_bss_3C30.unk_9 - v5;
                    if (v9 >= limit) *v4 = limit;
                }
                *v3 = (f32)*v4;
            } else {
                v11 = (f32 *)&fzgx_obj_lbl_1_bss_8E530;
                v12 = (s32 *)&fzgx_obj_lbl_1_bss_8E538;
                v14 = fn_1_8623C() * 160;
                v13 = fzgx_obj_lbl_1_bss_8E548[0];
                v15 = (v13 >> 1) - 1;
                v0 = *((u8 *)&lbl_1_bss_3C30 + v14 + lbl_1_bss_3C30.unk_A7 + 226);
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v0;
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v0 - v15;
                if ((s32)(v0 - v15) < 0) *v12 = 0;
                else {
                    v16 = fzgx_obj_lbl_1_bss_8E51D;
                    if (*v12 >= ((v16 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v13))
                        *v12 = (u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v13;
                }
                if (fzgx_obj_lbl_1_bss_8E51D == 4) v17 = lbl_1_bss_3C30.unk_8;
                else v17 = lbl_1_bss_3C30.unk_9;
                *v11 = (f32)(u32)v17 - (f32)(u32)fzgx_obj_lbl_1_bss_8E548[0];
            }
            fn_1_A2D84(0xA9010400);
        }
    }
}
/* fzgx:end fn_1_14B93C */

/* fzgx:begin fn_1_14BC3C */
// fn_1_14BC3C: empty in retail (single blr).
void fn_1_14BC3C(void) {
}
/* fzgx:end fn_1_14BC3C */

/* fzgx:begin fn_1_14BC40 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    f32 unk_1c;
    s32 unk_20;
    u8 pad_24[0xc];
    u8 unk_30;
} fn_1_14BC40_Obj;
extern fn_1_14BC40_Obj lbl_1_bss_8E518;
extern u32 lbl_801A66A4;
extern const f32 lbl_1_rodata_99A4;
extern u32 fn_1_14BE30(void);

static inline s32 clamp_value(s32 value, s32 minimum, s32 maximum) {
    if (value < minimum) return minimum;
    if (value > maximum) value = maximum;
    return value;
}

void fn_1_14BC40(void) {
    fn_1_14BC40_Obj *p = &lbl_1_bss_8E518;
    s32 value;
    s32 maximum;
    s32 result = 0;
    u32 lab_v;
    p->unk_20 = 0;
    lab_v = p->unk_30;
    p->unk_20 = -(((lab_v >> 1) & 0x7f) - 1);
    p->unk_20 = clamp_value(p->unk_20, 0, 10 - lab_v);
    p->unk_18 = lbl_1_rodata_99A4;
    p->unk_10 = lbl_801A66A4;
    fn_1_14BE30();
}
/* fzgx:end fn_1_14BC40 */

/* fzgx:begin fn_1_14BCBC noprologue */
#include "types.h"

struct fn_1_14BCBC_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xA];
};
struct fn_1_14BCBC_lbl_1_bss_9F8 {
    struct fn_1_14BCBC_lbl_1_bss_9F8_0_E20 unk_0[1];
};
struct fn_1_14BCBC_lbl_1_bss_8E52C {
    u8 unk_0;
};

extern struct fn_1_14BCBC_lbl_1_bss_8E52C lbl_1_bss_8E52C;
extern struct fn_1_14BCBC_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_1_14A9D0(u32, u32, u32, u32, u32, u32);
extern u32 fn_1_14BFD8(u32, u32, u32);

void fn_1_14BCBC(u32 arg0, u32 arg1) {
    fn_1_14BFD8(arg1, arg0, 1);
    if (((lbl_1_bss_9F8.unk_0[(s16)arg1].unk_8 >> 4) & 0x1) != 0) {
    lbl_1_bss_8E52C.unk_0 = (lbl_1_bss_8E52C.unk_0 ^ 1);
    }
    fn_1_14A9D0(10, 1, 30, 180, 0, 0);
}
/* fzgx:end fn_1_14BCBC */

/* fzgx:begin fn_1_14BD44 noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

void fn_1_14BD44(void *arg0, void *arg1) {
    fn_1_14BFD8(arg1, arg0, 0);
}
/* fzgx:end fn_1_14BD44 */

/* fzgx:begin fn_1_14BD74 noprologue */
void fn_1_14BD74(void) {
    fn_1_14BFB8();
}
/* fzgx:end fn_1_14BD74 */

/* fzgx:begin fn_1_14BD94 noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u8 pad_4[0xC];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[0xC];
    u8 unk_30;
    u8 pad_31[0xF];
    u8 unk_40;
    u8 unk_41;
} fn_1_14BD94_Obj;

extern fn_1_14BD94_Obj lbl_1_bss_8E518;
extern const f32 lbl_1_rodata_99A4;
extern u32 lbl_801A66A4;
extern s32 fn_1_1555B0(s32);
extern void fn_1_1556B4(u8, u8);

static inline s32 clamp(s32 value, u8 unk_30) {
    if (value < 0) {
        return 0;
    }
    if (value > 10 - unk_30) {
        value = 10 - unk_30;
    }
    return value;
}

void fn_1_14BD94(const u8 *arg0) {
    fn_1_14BD94_Obj *p = &lbl_1_bss_8E518;
    u8 unk_30;

    p->unk_20 = 0;
    unk_30 = p->unk_30;
    p->unk_20 = -(((unk_30 >> 1) & 0x7F) - 1);
    p->unk_20 = clamp(p->unk_20, unk_30);
    p->unk_18 = lbl_1_rodata_99A4;
    fn_1_1555B0(*arg0);
    fn_1_1556B4(p->unk_40, p->unk_41);
    p->unk_0 = 0;
    p->unk_10 = lbl_801A66A4;
}
/* fzgx:end fn_1_14BD94 */

/* fzgx:begin fn_1_14BE30 noprologue */
#include "types.h"

extern s16 lbl_1_bss_960;
extern struct fn_1_14BE30_lbl_1_bss_8E518 lbl_1_bss_8E518;
extern u32 fn_1_1556B4(u32, u32);
extern u32 fn_1_A2D84(u32);
extern u32 lbl_801A66A4;

struct fn_1_14BE30_lbl_1_bss_8E518 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x14];
    u32 unk_28;
    u8 pad_2C[0x14];
    u8 unk_40;
    u8 unk_41;
};

u32 fn_1_14BE30(void) {
    struct fn_1_14BE30_lbl_1_bss_8E518 *p_lbl_1_bss_8E518;
    u32 v0;
    u32 v1;
    u32 t1;
    p_lbl_1_bss_8E518 = (struct fn_1_14BE30_lbl_1_bss_8E518 *)&lbl_1_bss_8E518;
    p_lbl_1_bss_8E518->unk_40 = 42;
    p_lbl_1_bss_8E518->unk_41 = 0;
    fn_1_1556B4(42, 0);
    p_lbl_1_bss_8E518->unk_10 = lbl_801A66A4;
    v0 = lbl_801A66A4;
    if (lbl_1_bss_960 == 2) {
    v0 = 0xA9070000;
    v0 += 8192;
    t1 = fn_1_A2D84(v0);
    v0 = t1;
    }
    v1 = p_lbl_1_bss_8E518->unk_28;
    if ((s32)v1 != 0) {
    v0 = (u32)&lbl_801A66A4;
    v0 = *(u32 *)(v0);
    p_lbl_1_bss_8E518->unk_10 = (v0 - 190);
    }
    if ((s32)v1 == 0) {
    p_lbl_1_bss_8E518->unk_28 = 1;
    }
    return v0;
}
/* fzgx:end fn_1_14BE30 */

/* fzgx:begin fn_1_14BED0 */
void fn_1_14BED0(void) {
    Obj_1_bss_9F8 *obj_9f8;

    fn_1_14BFD8( (s16)(void *)(0), (u8 *)(void *)(0), 1);
    fn_1_14A9D0(10, 1, 30, 180, 1, 0);

    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        obj_9f8 = &lbl_1_bss_9F8;
        if (((obj_9f8->unk_8 >> 8) & 1) != 0
            && ((lbl_1_bss_D58.unk_8 >> 12) & 1) == 0) {
            if (lbl_801A66A4 - lbl_1_bss_8E528 >= 0xc3) {
                lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xa9010400);
            } else {
                fn_1_14CA4C();
            }
        } else if (((obj_9f8->unk_8 >> 9) & 1) != 0) {
            lbl_1_bss_8E51D = 0;
            fn_1_A2D84(0xa9010400);
        }
    }
}
/* fzgx:end fn_1_14BED0 */

/* fzgx:begin fn_1_14BFB8 */
void fn_1_14BFB8(void) {
    if (lbl_1_bss_8E51D != 0) {
        lbl_1_bss_8E520 = 1;
    }
}
/* fzgx:end fn_1_14BFB8 */

/* fzgx:begin fn_1_14BFD8 noprologue */
#include "types.h"

typedef struct InputButtons {
    u16 button;
    u16 unk_2;
} InputButtons;

typedef struct InputPortButtons {
    InputButtons unk_0;
    InputButtons unk_4;
    InputButtons unk_8;
    InputButtons unk_C;
    InputButtons unk_10;
} InputPortButtons;

typedef struct {
    u32 unk_0;
    u8 pad_4[0xC];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[0xC];
    u8 unk_30;
    u8 pad_31[0xF];
    u8 unk_40;
    u8 unk_41;
    u8 pad_42[2];
    u32 unk_44;
    u32 unk_48;
} fn_1_14BFD8_Obj;

extern InputPortButtons lbl_1_bss_9F8[];
extern fn_1_14BFD8_Obj lbl_1_bss_8E518;
extern const f32 lbl_1_rodata_99A4;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66A4;
extern void fn_1_12EF80(s16, s16 *, s16 *);
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern s32 fn_1_1555B0(s32);
extern void fn_1_1556B4(u8, u8);
extern void fn_1_A2D84(u32);

static inline s32 clamp(s32 value, u8 unk_30) {
    if (value < 0) {
        return 0;
    }
    if (value > 10 - unk_30) {
        value = 10 - unk_30;
    }
    return value;
}

static inline void padPressed(s32 port, InputButtons **out) {
    *out = (InputButtons *)((u8 *)&lbl_1_bss_9F8[0].unk_8 + port * 20);
}

#pragma opt_propagation off
void fn_1_14BFD8(s16 port, u8 *sel, s32 arg2) {
    s32 right;
    s32 left;
    fn_1_14BFD8_Obj *p = &lbl_1_bss_8E518;
    s32 confirm;
    s32 blocked;
    s32 dir;
    s16 result;
    s16 row;
    s16 col;
    s32 changed;
    s32 toggled;
    u32 sound;
    InputButtons *trig;
    u8 unk_30;

    blocked = __rlwinm(lbl_1_bss_9F8[port].unk_0.button, 29, 31, 31) || __rlwinm(lbl_1_bss_9F8[port].unk_0.unk_2, 29, 31, 31) || __rlwinm(lbl_1_bss_9F8[port].unk_0.button, 30, 31, 31) || __rlwinm(lbl_1_bss_9F8[port].unk_0.unk_2, 30, 31, 31);
    padPressed(port, &trig);
    left = (__rlwinm(lbl_1_bss_9F8[port].unk_10.button, 0, 31, 31) || __rlwinm(lbl_1_bss_9F8[port].unk_10.unk_2, 0, 31, 31)) && !blocked;
    right = (__rlwinm(lbl_1_bss_9F8[port].unk_10.button, 31, 31, 31) || __rlwinm(lbl_1_bss_9F8[port].unk_10.unk_2, 31, 31, 31)) && !blocked;
    confirm = (trig->button >> 10) & 1;

    if (sel != NULL) {
        row = 0;
        col = 0;
        dir = 0;
        result = -1;
        fn_1_12EF80(*sel, &row, &col);
        if (left) {
            dir = -1;
            p->unk_44 = lbl_801A66A0;
        } else if (right) {
            dir = 1;
            p->unk_48 = lbl_801A66A0;
        }
        if (dir != 0) {
            for (col += dir; col >= 0 && col <= 5; col += dir) {
                result = fn_1_12EF24(row, col);
                if (row == 5 && ((col == 5 && !fn_1_F89E4(0)) || (col != 5 && !fn_1_F89E4(col + 1)))) {
                    result = -1;
                }
                if (result != -1) {
                    break;
                }
            }
            if (result != -1 && *sel != result) {
                *sel = result;
                p->unk_20 = 0;
                unk_30 = p->unk_30;
                p->unk_20 = -(((unk_30 >> 1) & 0x7F) - 1);
                p->unk_20 = clamp(p->unk_20, unk_30);
                p->unk_18 = lbl_1_rodata_99A4;
                fn_1_1555B0(*sel);
                fn_1_1556B4(p->unk_40, p->unk_41);
                p->unk_0 = 0;
                p->unk_10 = lbl_801A66A4;
                fn_1_A2D84(0xA9010000);
            }
        }
    }

    if (arg2 != 0) {
        changed = 0;
        toggled = 0;
        if (confirm) {
            switch (p->unk_41) {
            case 0:
                p->unk_41 = 2;
                sound = 0xA9121900;
                break;
            case 2:
                p->unk_41 = 1;
                sound = 0xA9121A00;
                break;
            case 1:
                p->unk_41 = 0;
                sound = 0xA9121800;
                break;
            }
            toggled = 1;
            fn_1_A2D84(sound);
        }
        if (changed || toggled) {
            fn_1_1556B4(p->unk_40, p->unk_41);
            p->unk_20 = 0;
            unk_30 = p->unk_30;
            p->unk_20 = -(((unk_30 >> 1) & 0x7F) - 1);
            p->unk_20 = clamp(p->unk_20, unk_30);
            p->unk_18 = lbl_1_rodata_99A4;
            p->unk_10 = lbl_801A66A4;
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_14BFD8 */

/* fzgx:begin fn_1_14C35C */
typedef struct {
    char *unk_0;
    s32 unk_4;
} fn_1_14C35C_Entry;

typedef struct {
    fn_1_14C35C_Entry unk_0[4];
    s32 unk_20;
} fn_1_14C35C_Table;


/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ objects span the retail objects in between */
char fzgx_obj_lbl_1_data_42878[4] = "NON";
u8 fzgx_pool_gap_4[0x5FC] = {1};
/* Shift-JIS full-width letters, punctuation and digits, two bytes per character */
u16 fzgx_obj_lbl_1_data_42E78[30] = {
    0x8260, 0x8261, 0x8262, 0x8263, 0x8264, 0x8265, 0x8266, 0x8267, 0x8268, 0x8269, 0x826A, 0x826B, 0x826C,
    0x826D, 0x826E, 0x826F, 0x8270, 0x8271, 0x8272, 0x8273, 0x8274, 0x8275, 0x8276, 0x8277, 0x8278, 0x8279,
    0x81E7, 0x81E8,
};
u16 fzgx_obj_lbl_1_data_42EB4[30] = {
    0x8281, 0x8282, 0x8283, 0x8284, 0x8285, 0x8286, 0x8287, 0x8288, 0x8289, 0x828A, 0x828B, 0x828C, 0x828D,
    0x828E, 0x828F, 0x8290, 0x8291, 0x8292, 0x8293, 0x8294, 0x8295, 0x8296, 0x8297, 0x8298, 0x8299, 0x829A,
    0x81E7, 0x81E8,
};
u16 fzgx_obj_lbl_1_data_42EF0[34] = {
    0x8143, 0x8144, 0x8148, 0x8149, 0x817B, 0x817C, 0x815E, 0x815F, 0x8181, 0x8183, 0x8184, 0x8146,
    0x8147, 0x814C, 0x814D, 0x814F, 0x8151, 0x8162, 0x8169, 0x816A, 0x816D, 0x816E, 0x816F, 0x8170,
    0x8190, 0x8193, 0x8194, 0x8195, 0x8196, 0x8197, 0x81E7, 0x81E8,
};
u16 fzgx_obj_lbl_1_data_42F34[14] = {
    0x824F, 0x8250, 0x8251, 0x8252, 0x8253, 0x8254, 0x8255, 0x8256, 0x8257, 0x8258, 0x81E7, 0x81E8,
};
/* the ASCII characters each full-width table stands for, in the same order */
u8 lbl_1_data_42F34__fzgx_offset_1C[29] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ  ";
u8 lbl_1_data_42F34__fzgx_offset_3C[29] = "abcdefghijklmnopqrstuvwxyz  ";
u8 lbl_1_data_42F34__fzgx_offset_5C[33] = ",.?!+-/\\=<>:;'`^_|()[]{}$%#&*@  ";
u8 lbl_1_data_42F34__fzgx_offset_80[13] = "0123456789  ";
/* {string, length} tables; retail's 0x90 pointers go to strings inside the gap (lbl_1_data_42C44, 42CC8, 42D18,
 * 42DC4) and stay 0 here: the unit's copy is dropped and bound to the retail table at link */
fn_1_14C35C_Table lbl_1_data_42F34__fzgx_offset_90 = {
    {{NULL, 0x40}, {NULL, 0x26}, {NULL, 0x55}, {NULL, 0x58}}, 4,
};
fn_1_14C35C_Table lbl_1_data_42F34__fzgx_offset_B4 = {
    {{(char *)fzgx_obj_lbl_1_data_42E78, 0x1C},
     {(char *)fzgx_obj_lbl_1_data_42EB4, 0x1C},
     {(char *)fzgx_obj_lbl_1_data_42EF0, 0x20},
     {(char *)fzgx_obj_lbl_1_data_42F34, 0xC}},
    4,
};

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = *(u8 *)&fzgx_obj_lbl_1_data_42878;
    s = *(u8 *)&fzgx_pool_gap_4;
    s = *(u8 *)&fzgx_obj_lbl_1_data_42E78;
    s = *(u8 *)&fzgx_obj_lbl_1_data_42EB4;
    s = *(u8 *)&fzgx_obj_lbl_1_data_42EF0;
    s = *(u8 *)&fzgx_obj_lbl_1_data_42F34;
    s = *(u8 *)&lbl_1_data_42F34__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_data_42F34__fzgx_offset_3C;
    s = *(u8 *)&lbl_1_data_42F34__fzgx_offset_5C;
    s = *(u8 *)&lbl_1_data_42F34__fzgx_offset_80;
    s = *(u8 *)&lbl_1_data_42F34__fzgx_offset_90;
    s = *(u8 *)&lbl_1_data_42F34__fzgx_offset_B4;
}
#pragma section code_type ".text"

/* the retail TU's .bss objects this function uses, at their retail offsets */
u32 fzgx_obj_lbl_1_bss_8E518;
u32 fzgx_pool_gap_8E51C;
s32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_pool_gap_8E524[0xC];
f32 fzgx_obj_lbl_1_bss_8E530;
u32 fzgx_pool_gap_8E534;
s32 fzgx_obj_lbl_1_bss_8E538;
u8 fzgx_pool_gap_8E53C[0xC];
u8 fzgx_obj_lbl_1_bss_8E548;
u8 fzgx_pool_gap_8E549;
u16 fzgx_pool_gap_8E54A;
u8 fzgx_pool_gap_8E54C[8];
u32 fzgx_obj_lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_gap_8E55A;
u32 fzgx_pool_gap_8E55C;
u32 fzgx_obj_lbl_1_bss_8E560;
s32 lbl_1_bss_8E560__fzgx_offset_4;
char *lbl_1_bss_8E560__fzgx_offset_8;
s32 lbl_1_bss_8E560__fzgx_offset_C;
s32 fzgx_obj_lbl_1_bss_8E570;
s32 lbl_1_bss_8E570__fzgx_offset_4;
char lbl_1_bss_8E570__fzgx_offset_8[0x14];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
s32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fn_1_14C35C_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&fzgx_pool_gap_8E51C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_pool_gap_8E524;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E530;
    s = *(u8 *)&fzgx_pool_gap_8E534;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E538;
    s = *(u8 *)&fzgx_pool_gap_8E53C;
    s = fzgx_obj_lbl_1_bss_8E548;
    s = *(u8 *)&fzgx_pool_gap_8E549;
    s = *(u8 *)&fzgx_pool_gap_8E54A;
    s = *(u8 *)&fzgx_pool_gap_8E54C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E554;
    s = lbl_1_bss_8E554__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_gap_8E55A;
    s = *(u8 *)&fzgx_pool_gap_8E55C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E560__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8E560__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_8E560__fzgx_offset_C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"

static inline char *fn_1_14C35C_wide(u8 c) {
    u32 i;

    for (i = 0; i < sizeof(lbl_1_data_42F34__fzgx_offset_1C); i++) {
        if (c == lbl_1_data_42F34__fzgx_offset_1C[i]) {
            return (char *)&fzgx_obj_lbl_1_data_42E78[i];
        }
    }
    for (i = 0; i < sizeof(lbl_1_data_42F34__fzgx_offset_3C); i++) {
        if (c == lbl_1_data_42F34__fzgx_offset_3C[i]) {
            return (char *)&fzgx_obj_lbl_1_data_42EB4[i];
        }
    }
    for (i = 0; i < sizeof(lbl_1_data_42F34__fzgx_offset_5C); i++) {
        if (c == lbl_1_data_42F34__fzgx_offset_5C[i]) {
            return (char *)&fzgx_obj_lbl_1_data_42EF0[i];
        }
    }
    for (i = 0; i < sizeof(lbl_1_data_42F34__fzgx_offset_80); i++) {
        if (c == lbl_1_data_42F34__fzgx_offset_80[i]) {
            return (char *)&fzgx_obj_lbl_1_data_42F34[i];
        }
    }
    return NULL;
}

void fn_1_14C35C(void) {
    char *name;
    u8 *src;
    char *dst;
    char *wide;
    u32 i;
    s32 value;
    u8 buf[0x20];

    lbl_1_bss_8E554__fzgx_offset_4 = 42;
    fzgx_obj_lbl_1_bss_8E559 = 0;
    fn_1_1556B4(42, 0);
    lbl_1_bss_8E560__fzgx_offset_4 = 0;
    if ((*((s32 *)&lbl_801A66B4)) == 5) {
        lbl_1_bss_8E560__fzgx_offset_8 = lbl_1_data_42F34__fzgx_offset_90.unk_0[0].unk_0;
        lbl_1_bss_8E560__fzgx_offset_C = lbl_1_data_42F34__fzgx_offset_90.unk_0[0].unk_4;
    } else {
        lbl_1_bss_8E560__fzgx_offset_8 = lbl_1_data_42F34__fzgx_offset_B4.unk_0[0].unk_0;
        lbl_1_bss_8E560__fzgx_offset_C = lbl_1_data_42F34__fzgx_offset_B4.unk_0[0].unk_4;
    }
    fzgx_obj_lbl_1_bss_8E570 = 0;
    lbl_1_bss_8E570__fzgx_offset_4 = lbl_1_bss_8E560__fzgx_offset_C - 1;
    /* retail clears 0x13 bytes (stb) at 0x8E578, though symbols.txt types lbl_1_bss_8E570 as 4-byte data */
    for (i = 0; i < 0x13; i++) {
        lbl_1_bss_8E570__fzgx_offset_8[i] = 0;
    }

    name = (char *)&lbl_1_bss_718E0[0x5522];
    strncpy(lbl_1_bss_8E570__fzgx_offset_8, name, ((unsigned long)strlen(name)));
    lbl_1_bss_8E560__fzgx_offset_4 = ((unsigned long)strlen(name)) / 2;
    if ((*((s32 *)&lbl_801A66B4)) != 5) {
        lbl_1_bss_8E560__fzgx_offset_4 = ((unsigned long)strlen(name));
        strcpy((char *)buf, lbl_1_bss_8E570__fzgx_offset_8);
        src = buf;
        dst = lbl_1_bss_8E570__fzgx_offset_8;
        while (*src != 0) {
            if (*src < 0x80) {
                wide = fn_1_14C35C_wide(*src);
                if (wide != NULL) {
                    strncpy(dst, wide, 2);
                    dst += 2;
                }
                src++;
            } else {
                strncpy(dst, (char *)src, 2);
                dst += 2;
                src += 2;
            }
        }
        *dst = 0;
    }
    if (lbl_1_bss_8E560__fzgx_offset_4 == 0) {
        lbl_1_bss_8E570__fzgx_offset_4 = 0;
    }
    if (fzgx_obj_lbl_1_bss_8E520 != 0) {
        if (((s32)fn_1_155F7C()) != 0) {
            fzgx_obj_lbl_1_bss_8E520 = 0;
            lbl_1_bss_8E570__fzgx_offset_1C = 1;
            lbl_1_bss_8E570__fzgx_offset_20 = ((s32)fn_1_155F8C());
            fn_1_155FB4("");
            lbl_1_bss_3C04 = 0x744;
            value = lbl_1_bss_8E570__fzgx_offset_20 - 2 < 0 ? 0
                : lbl_1_bss_8E570__fzgx_offset_20 - 2 > 10 - fzgx_obj_lbl_1_bss_8E548 ? 10 - fzgx_obj_lbl_1_bss_8E548
                : lbl_1_bss_8E570__fzgx_offset_20 - 2;
            fzgx_obj_lbl_1_bss_8E538 = value;
            fzgx_obj_lbl_1_bss_8E530 = value;
        } else {
            fzgx_obj_lbl_1_bss_8E520 = 0;
            lbl_1_bss_8E570__fzgx_offset_1C = 0;
            lbl_1_bss_3C04 = 0x294;
        }
    }
}
/* fzgx:end fn_1_14C35C */

/* fzgx:begin fn_1_14C6F8 noprologue */
#include "rel/main_rel/game.h"

extern s32 fn_1_155F8C(void);
extern void fn_1_14CAC8(void);
extern u32 lbl_1_bss_3C04;

/* Offsets recovered from the retail accesses in fn_1_14C6F8. */
typedef struct {
	u32 unk_0;
	u8 unk_4;
	u8 unk_5;
	u8 pad_6[0x12];
	f32 unk_18;
	u32 unk_1C;
	s32 unk_20;
	u32 unk_24;
	s32 unk_28;
	u32 unk_2C;
	u8 unk_30;
	u8 pad_31[0x43];
	s32 unk_74;
} Obj_1_bss_8E518;

extern Obj_1_bss_8E518 lbl_1_bss_8E518;

void fn_1_14C6F8(void)
{
	Obj_1_bss_8E518 *state = (Obj_1_bss_8E518 *)&lbl_1_bss_8E518;
	s32 value;
	f32 scale;

	if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
		return;
	}
	if (state->unk_74 != 0) {
		fn_1_14CAC8();
		return;
	}
	state->unk_5 = 5;
	value = fn_1_155F8C() - 2;
	if (value < 0) {
		value = 0;
	} else {
		if (fn_1_155F8C() - 2 > 10 - state->unk_30) {
			value = 10 - state->unk_30;
		} else {
			value = fn_1_155F8C() - 2;
		}
	}
	state->unk_20 = value;
	if (state->unk_28 != 0) {
		scale = value;
	} else {
		scale = 10 - state->unk_30;
	}
	state->unk_18 = scale;
	lbl_1_bss_3C04 = 0x294;
}
/* fzgx:end fn_1_14C6F8 */

/* fzgx:begin fn_1_14C7F4 noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

// fn_1_14C7F4: empty in retail (single blr).
void fn_1_14C7F4(void) {
}
/* fzgx:end fn_1_14C7F4 */

/* fzgx:begin fn_1_14C7F8 noprologue */
void fn_1_14C7F8(void) {
    s32 state;

    if (fn_1_3F864() != 0) {
        fn_1_A2D84(0xa9070000);
    }

    state = lbl_1_bss_8E540;
    if (state != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if (state == 0) {
        lbl_1_bss_8E540 = 1;
    }
}
/* fzgx:end fn_1_14C7F8 */

/* fzgx:begin fn_1_14C864 noprologue */
void fn_1_14C864(void) {
    Obj_1_bss_9F8 *flags;
    u8 mode;

    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }

    if (lbl_1_bss_8E51D == 4) {
        mode = lbl_1_bss_3C30.unk_8;
    } else {
        mode = lbl_1_bss_3C30.unk_9;
    }

    fn_1_14A9D0(mode, 1, 30, 180, 1, 0);

    flags = &lbl_1_bss_9F8;
    if (((flags->unk_8 >> 8) & 1) != 0) {
        if (((lbl_1_bss_D58.unk_8 >> 12) & 1) == 0) {
            if (lbl_801A66A4 - lbl_1_bss_8E528 >= 0xC3) {
                lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xA9010400);
            } else {
                fn_1_14CA4C();
            }
            return;
        }
    }

    if (((flags->unk_8 >> 9) & 1) == 0) {
        return;
    }

    lbl_1_bss_8E51D = 0;
    fn_1_A2D84(0xA9010400);
}
/* fzgx:end fn_1_14C864 */

/* fzgx:begin fn_1_14C964 noprologue */
// fn_1_14C964: empty in retail (single blr).
void fn_1_14C964(void) {
}
/* fzgx:end fn_1_14C964 */

/* fzgx:begin fn_1_14C968 noprologue */
void fn_1_14C968(void) {
    if (lbl_1_bss_3C30.unk_5 == 2) {
        fn_1_3FF90();
    }
    fn_1_C2454();
}
/* fzgx:end fn_1_14C968 */

/* fzgx:begin fn_1_14C9A0 noprologue */
void fn_1_14C9A0(void) {
    int state = lbl_1_bss_5138[0xe2];

    if (state != 0) {
        s32 bit = (lbl_1_bss_9F8.unk_8 >> 8) & 1;
        if (lbl_1_bss_5138[0xe2] != 0 && bit != 0) {
            if (lbl_1_bss_5138[0xe0] >= 0xf &&
                lbl_1_bss_5138[0xe0] <= 0x78) {
                lbl_1_bss_5138[0xe0] = 0x78;
            }
        }
    }

    if (state == 0 &&
        fn_1_C24A4() == 0 &&
        fn_1_B7C00() == 0) {
        fn_1_320A4();
        lbl_1_bss_8E51D = 0xa;
    }
}
/* fzgx:end fn_1_14C9A0 */

/* fzgx:begin fn_1_14CA3C noprologue */
// fn_1_14CA3C: empty in retail (single blr).
void fn_1_14CA3C(void) {
}
/* fzgx:end fn_1_14CA3C */

/* fzgx:begin fn_1_14CA40 noprologue */
// fn_1_14CA40: empty in retail (single blr).
void fn_1_14CA40(void) {
}
/* fzgx:end fn_1_14CA40 */

/* fzgx:begin fn_1_14CA44 noprologue */
// fn_1_14CA44: empty in retail (single blr).
void fn_1_14CA44(void) {
}
/* fzgx:end fn_1_14CA44 */

/* fzgx:begin fn_1_14CA48 noprologue */
// fn_1_14CA48: empty in retail (single blr).
void fn_1_14CA48(void) {
}
/* fzgx:end fn_1_14CA48 */

/* fzgx:begin fn_1_14CA4C noprologue */
// Arms the display update and refreshes it when the selected value exceeds the current one.
void fn_1_14CA4C(void) {
    u8 *display_state = (u8 *)&lbl_1_bss_8E518;
    u8 selected_limit;

    if (lbl_1_bss_8E518.unk_4 != 0) {
        return;
    }

    lbl_1_bss_8E518.unk_4 = 1;
    selected_limit = display_state[5] == 4
        ? lbl_1_bss_3C30.unk_8
        : lbl_1_bss_3C30.unk_9;

    if (selected_limit > display_state[0x30]) {
        fn_1_A2D84(0xA9010400);
    }
}
/* fzgx:end fn_1_14CA4C */

/* fzgx:begin fn_1_14CAC8 noprologue */
/* one page of the name entry's character grid: two-byte characters and their count */
typedef struct {
    char *unk_0;
    s32 unk_4;
} fn_1_14CAC8_Page;

extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_14CEB8(char *name);
extern void fn_1_155FB4(char *name);
extern char *strncpy(char *dst, const char *src, size_t n);
extern int strncmp(const char *a, const char *b, size_t n);
extern int sprintf(char *s, const char *format, ...);
extern void OSReport(const char *format, ...);
extern u8 *lbl_1_bss_25CD0[];
extern u32 lbl_801A66B4;

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ objects span the retail objects in between */
char fzgx_obj_lbl_1_data_42878[4] = "NON";
u8 fzgx_pool_gap_4287C[0x6B8] = {1};
u8 fzgx_obj_lbl_1_data_42F34[0x90] = {1};
fn_1_14CAC8_Page lbl_1_data_42F34__fzgx_offset_90[4] = {{0, 1}};
s32 lbl_1_data_42F34__fzgx_offset_B0 = 4;
fn_1_14CAC8_Page lbl_1_data_42F34__fzgx_offset_B4[4] = {{0, 1}};
u32 fzgx_pool_gap_43008[2] = {4};

/* the retail TU's .bss objects this function uses (lbl_1_bss_8E518 is the section base) */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 fzgx_pool_gap_8E51C[0x44];
u32 fzgx_obj_lbl_1_bss_8E560;
s32 lbl_1_bss_8E560__fzgx_offset_4;
char *lbl_1_bss_8E560__fzgx_offset_8;
s32 lbl_1_bss_8E560__fzgx_offset_C;
s32 fzgx_obj_lbl_1_bss_8E570;
s32 lbl_1_bss_8E570__fzgx_offset_4;
char lbl_1_bss_8E570__fzgx_offset_8[0x14];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
s32 lbl_1_bss_8E570__fzgx_offset_20;
u8 fzgx_obj_lbl_1_bss_8E594;

#pragma section code_type ".fzgxpool"
/* retail .rodata from lbl_1_rodata_9828: the kana grids, the default names (0x160, 0x16C) and the constants
 * before this function's own initialiser */
static const u32 fzgx_pool_rodata_0[88] = {0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82A482AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C3, 0x82C582C7, 0x82CE82D1, 0x82D482D7, 0x82DA82CF, 0x82D282D5, 0x82D882DB, 0x829F82A1, 0x82A382A5, 0x82A782C1, 0x82E182E3, 0x82E582EC, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x8377837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x83758378, 0x837B8370, 0x83738376, 0x8379837C, 0x83408342, 0x83448346, 0x83488362, 0x83838385, 0x8387838E, 0x00000000, 0x81968196, 0x81960000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_0; }  /* fzgx-allow: S2 pool primer sink */
static const char fzgx_pool_rodata_160[12] = {0x83, 0x47, 0x83, 0x74, 0x83, 0x5B, 0x83, 0x8D, 0x00};  /* fzgx-allow: A1 retail Shift-JIS bytes */
static const char fzgx_pool_rodata_16C[16] = {0x82, 0x65, 0x81, 0x7C, 0x82, 0x79, 0x82, 0x64, 0x82, 0x71, 0x82, 0x6E, 0x00};  /* fzgx-allow: A1 retail Shift-JIS bytes */
static const u32 fzgx_pool_rodata_17C[12] = {0x00000000, 0x43300000, 0x00000000, 0x43300000, 0x80000000, 0x3E4CCCCD, 0x3DCCCCCD, 0x3D75C28F, 0x3C75C28F, 0xBDCCCCCD, 0x3D4CCCCD, 0xBD4CCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_17C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_17C; }  /* fzgx-allow: S2 pool primer sink */

__declspec(section ".fzgxpool") static void fzgx_pool_data_prime(void) {
    void *volatile p;  /* fzgx-allow: S2 pool primer sink */
    p = fzgx_obj_lbl_1_data_42878;
    p = fzgx_pool_gap_4287C;
    p = fzgx_obj_lbl_1_data_42F34;
    p = lbl_1_data_42F34__fzgx_offset_90;
    p = &lbl_1_data_42F34__fzgx_offset_B0;
    p = lbl_1_data_42F34__fzgx_offset_B4;
    p = fzgx_pool_gap_43008;
}
__declspec(section ".fzgxpool") static void fn_1_14CAC8_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)fzgx_pool_gap_8E51C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E560__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8E560__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_8E560__fzgx_offset_C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_4;
    s = *lbl_1_bss_8E570__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
    s = fzgx_obj_lbl_1_bss_8E594;
}
#pragma section code_type ".text"


void fn_1_14CAC8(void) {
    char blank[2] = {0};
    s32 i;
    u16 bits12;  /* lbl_1_bss_9F8.unk_12, declared first: retail colours it r3 */
    u16 bits10;  /* lbl_1_bss_9F8.unk_10 */
    u32 buttons;

    if (PAD_BIT(lbl_1_bss_9F8.unk_8, 12)) {  /* fzgx-allow: S2 retail reloads the buttons after this test */
        lbl_1_bss_8E570__fzgx_offset_4 = lbl_1_bss_8E560__fzgx_offset_C - 1;
    }
    buttons = lbl_1_bss_9F8.unk_8;
    if ((buttons >> 8) & 1) {
        fn_1_A2DC4(0xA9011100);
        if (lbl_1_bss_8E570__fzgx_offset_4 == lbl_1_bss_8E560__fzgx_offset_C - 1) {
            lbl_1_bss_8E570__fzgx_offset_1C = 0;
            strncpy(&lbl_1_bss_8E570__fzgx_offset_8[lbl_1_bss_8E560__fzgx_offset_4 * 2], blank, 2);
            lbl_1_bss_8E570__fzgx_offset_8[lbl_1_bss_8E560__fzgx_offset_4 * 2] = 0;
            if ((u8)lbl_1_bss_8E570__fzgx_offset_8[0] == 0) {
                if ((s32)lbl_801A66B4 == 5) {
                    sprintf(lbl_1_bss_8E570__fzgx_offset_8, "%s", fzgx_pool_rodata_160);
                } else {
                    sprintf(lbl_1_bss_8E570__fzgx_offset_8, "%s", fzgx_pool_rodata_16C);
                }
            }
            fn_1_14CEB8(lbl_1_bss_8E570__fzgx_offset_8);
            OSReport("name_entry_name DEC: %s\n", lbl_1_bss_8E570__fzgx_offset_8);
            strncpy((char *)(lbl_1_bss_25CD0[0] + lbl_1_bss_8E570__fzgx_offset_20 * 32 + 8), lbl_1_bss_8E570__fzgx_offset_8, 16);
            fn_1_155FB4(lbl_1_bss_8E570__fzgx_offset_8);
            return;
        }
        lbl_1_bss_8E560__fzgx_offset_4++;
        if (lbl_1_bss_8E560__fzgx_offset_4 > 8) {
            lbl_1_bss_8E560__fzgx_offset_4 = 8;
        }
        strncpy(&lbl_1_bss_8E570__fzgx_offset_8[lbl_1_bss_8E560__fzgx_offset_4 * 2], lbl_1_bss_8E560__fzgx_offset_8, 2);
    } else if ((buttons >> 9) & 1) {
        fn_1_A2DC4(0xA9011000);
        if (lbl_1_bss_8E560__fzgx_offset_4 > 0) {
            strncpy(&lbl_1_bss_8E570__fzgx_offset_8[lbl_1_bss_8E560__fzgx_offset_4 * 2], blank, 2);
            lbl_1_bss_8E570__fzgx_offset_4 = 0;
            lbl_1_bss_8E560__fzgx_offset_4--;
            for (i = 0; i < lbl_1_bss_8E560__fzgx_offset_C; i++) {
                if (strncmp(&lbl_1_bss_8E570__fzgx_offset_8[lbl_1_bss_8E560__fzgx_offset_4 * 2], &lbl_1_bss_8E560__fzgx_offset_8[i * 2], 2) == 0) {
                    lbl_1_bss_8E570__fzgx_offset_4 = i;
                }
            }
        }
    } else if (((bits10 = lbl_1_bss_9F8.unk_10) & 1) || ((bits12 = lbl_1_bss_9F8.unk_12) & 1) || ((bits10 >> 1) & 1) ||
               ((bits12 >> 1) & 1)) {
        fn_1_A2DC4(0xA9011300);
        if (PAD_BIT(lbl_1_bss_9F8.unk_10, 0) || PAD_BIT(lbl_1_bss_9F8.unk_12, 0)) {
            lbl_1_bss_8E570__fzgx_offset_4--;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_10, 1) || PAD_BIT(lbl_1_bss_9F8.unk_12, 1)) {
            lbl_1_bss_8E570__fzgx_offset_4++;
        }
        lbl_1_bss_8E570__fzgx_offset_4 = (lbl_1_bss_8E570__fzgx_offset_4 + lbl_1_bss_8E560__fzgx_offset_C) % lbl_1_bss_8E560__fzgx_offset_C;
    } else if ((buttons >> 10) & 1) {
        fn_1_A2DC4(0xA9011300);
        lbl_1_bss_8E570__fzgx_offset_4 = 0;
        fzgx_obj_lbl_1_bss_8E570++;
        fzgx_obj_lbl_1_bss_8E570 = (fzgx_obj_lbl_1_bss_8E570 + lbl_1_data_42F34__fzgx_offset_B0) % lbl_1_data_42F34__fzgx_offset_B0;
        if ((s32)lbl_801A66B4 == 5) {
            lbl_1_bss_8E560__fzgx_offset_8 = lbl_1_data_42F34__fzgx_offset_90[fzgx_obj_lbl_1_bss_8E570].unk_0;
            lbl_1_bss_8E560__fzgx_offset_C = lbl_1_data_42F34__fzgx_offset_90[fzgx_obj_lbl_1_bss_8E570].unk_4;
        } else {
            lbl_1_bss_8E560__fzgx_offset_8 = lbl_1_data_42F34__fzgx_offset_B4[fzgx_obj_lbl_1_bss_8E570].unk_0;
            lbl_1_bss_8E560__fzgx_offset_C = lbl_1_data_42F34__fzgx_offset_B4[fzgx_obj_lbl_1_bss_8E570].unk_4;
        }
    }
    if (lbl_1_bss_8E560__fzgx_offset_4 == 8) {
        fzgx_obj_lbl_1_bss_8E594 = 1;
        lbl_1_bss_8E570__fzgx_offset_4 = lbl_1_bss_8E560__fzgx_offset_C - 1;
    } else {
        fzgx_obj_lbl_1_bss_8E594 = 0;
    }
    strncpy(&lbl_1_bss_8E570__fzgx_offset_8[lbl_1_bss_8E560__fzgx_offset_4 * 2], &lbl_1_bss_8E560__fzgx_offset_8[lbl_1_bss_8E570__fzgx_offset_4 * 2], 2);
    strncpy((char *)(lbl_1_bss_25CD0[0] + lbl_1_bss_8E570__fzgx_offset_20 * 32 + 8), lbl_1_bss_8E570__fzgx_offset_8, 16);
    fn_1_155FB4(lbl_1_bss_8E570__fzgx_offset_8);
}
/* fzgx:end fn_1_14CAC8 */

/* fzgx:begin fn_1_14CEB8 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_80008BEC(void *dest, int value, u32 size);
extern u8 *strstr(const u8 *str, const u8 *needle);
extern u8 lbl_1_bss_8E598[148];
extern u8 lbl_1_bss_8E62C[132];
extern const u8 lbl_1_rodata_9828[172];
extern const u8 lbl_1_rodata_98D4[208];

/* the retail TU's .data from lbl_1_data_42878, the section base this function addresses: the symbol page of
 * the name entry grid (42CC8), the ASCII NG words (43410) and the Shift-JIS NG words (43C30); the
 * fzgx_pool_gap_ objects span the retail objects in between */
char fzgx_obj_lbl_1_data_42878[4] = "NON";
u8 fzgx_pool_gap_4287C[0x44C] = {1};
u8 fzgx_obj_lbl_1_data_42CC8[0x50] = {1};
u8 fzgx_pool_gap_42D18[0x6F8] = {1};
u8 *lbl_1_data_4340C__fzgx_offset_4[130] = {0};
u8 fzgx_pool_gap_43618[0x618] = {1};
u8 *lbl_1_data_43C28__fzgx_offset_8[145] = {0};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_data_prime(void) {
    void *volatile p;  /* fzgx-allow: S2 pool primer sink */
    p = fzgx_obj_lbl_1_data_42878;
    p = fzgx_pool_gap_4287C;
    p = fzgx_obj_lbl_1_data_42CC8;
    p = fzgx_pool_gap_42D18;
    p = lbl_1_data_4340C__fzgx_offset_4;
    p = fzgx_pool_gap_43618;
    p = lbl_1_data_43C28__fzgx_offset_8;
}
#pragma section code_type ".text"

/* clears *flag unless the Shift-JIS character at s is the full-width form of the ASCII character c */
static inline void filter_ascii(u8 *flag, const char *s, u8 c) {
    u8 upper;
    u8 lower;

    if (c < 0x40) {
        upper = lower = c + 0x1F;  /* digits */
    } else {
        upper = c - 1;  /* lower-case letter: full-width upper case */
        lower = c + 0x20;
    }
    if (!((u8)s[0] == 0x82 && upper == (u8)s[1]) && !((u8)s[0] == 0x82 && lower == (u8)s[1])) {
        *flag = 0;
    }
}

/* Name entry NG-word filter: name holds up to eight Shift-JIS characters. Returns 1 (and replaces every
 * character with a full-width asterisk) when the name spells an NG word, else 0. */
s32 fn_1_14CEB8(u8 *name) {
    u8 buf[3];
    s32 found = 0;
    s32 symbols_only = 1;
    u32 i;
    u32 j;
    u32 k;
    u8 *p;
    u8 *kana;
    s32 known;

    /* skip leading full-width spaces; an all-space name is cleared */
    for (i = 0; i < 8; i++) {
        if (name[i * 2] != 0x81 || name[i * 2 + 1] != 0x40) {
            break;
        }
    }
    if (i == 8) {
        name[0] = 0;
        return 0;
    }
    /* a lone full-width X */
    if (name[i * 2] == 0x82 && (name[i * 2 + 1] == 0x77 || name[i * 2 + 1] == 0x98)) {
        found = 1;
        i++;
        while (name[i * 2] != 0) {
            if (name[i * 2] == 0x81 && name[i * 2 + 1] == 0x40) {
                i++;
            } else {
                found = 0;
                break;
            }
        }
        if (found) {
            goto mark; /* NG word found: overwrite the whole name */
        }
    }

    fn_80008BEC(lbl_1_bss_8E598, 1, 0x91);
    fn_80008BEC(lbl_1_bss_8E62C, 1, 0x82);
    buf[2] = 0;
    j = 0;
    for (i = 0; i < 8; i++) {
        p = &name[i * 2];
        if (p[0] == 0) {
            break;
        }
        if (p[0] == 0x81 && p[1] == 0x40) {
            continue;
        }
        known = 0;
        for (k = 0; k < 36; k++) {
            if (p[0] == fzgx_obj_lbl_1_data_42CC8[k * 2] && p[1] == fzgx_obj_lbl_1_data_42CC8[k * 2 + 1]) {
                known = 1;
                break;
            }
        }
        if (known) {
            continue;
        }
        symbols_only = 0;
        /* j-th character of every Shift-JIS NG word still in the running; hiragana also match katakana */
        for (k = 0; k < 145; k++) {
            if (lbl_1_bss_8E598[k] == 0) {
                continue;
            }
            buf[0] = lbl_1_data_43C28__fzgx_offset_8[k][j * 2];
            buf[1] = lbl_1_data_43C28__fzgx_offset_8[k][j * 2 + 1];
            kana = strstr(lbl_1_rodata_9828, buf);
            if (kana == NULL) {
                if (!(p[0] == lbl_1_data_43C28__fzgx_offset_8[k][j * 2] && p[1] == lbl_1_data_43C28__fzgx_offset_8[k][j * 2 + 1])) {
                    lbl_1_bss_8E598[k] = 0;
                }
            } else {
                kana = kana + (lbl_1_rodata_98D4 - lbl_1_rodata_9828);
                if (!(p[0] == lbl_1_data_43C28__fzgx_offset_8[k][j * 2] && p[1] == lbl_1_data_43C28__fzgx_offset_8[k][j * 2 + 1]) &&
                    !(kana[0] == p[0] && kana[1] == p[1])) {
                    lbl_1_bss_8E598[k] = 0;
                }
            }
            if (lbl_1_data_43C28__fzgx_offset_8[k][j * 2 + 2] == 0 && lbl_1_bss_8E598[k] != 0) {
                found = 1;
                goto mark; /* NG word found: overwrite the whole name */
            }
        }
        /* j-th character of every ASCII NG word still in the running */
        for (k = 0; k < 130; k++) {
            if (lbl_1_bss_8E62C[k] == 0) {
                continue;
            }
            filter_ascii(&lbl_1_bss_8E62C[k], (char *)p, lbl_1_data_4340C__fzgx_offset_4[k][j]);
            if (lbl_1_data_4340C__fzgx_offset_4[k][j + 1] == 0 && lbl_1_bss_8E62C[k] != 0) {
                found = 1;
                goto mark; /* NG word found: overwrite the whole name */
            }
        }
        j++;
    }
    if (symbols_only) {
        return 0;
    }
    /* a full-length name that is a prefix of an NG word */
    if (j == 8) {
        for (k = 0; k < 145; k++) {
            if (lbl_1_bss_8E598[k] != 0) {
                found = 1;
                goto mark; /* NG word found: overwrite the whole name */
            }
        }
        for (k = 0; k < 130; k++) {
            if (lbl_1_bss_8E62C[k] != 0) {
                found = 1;
                goto mark; /* NG word found: overwrite the whole name */
            }
        }
    }

mark:
    if (found) {
        for (i = 0; i < 8; i++) {
            if (name[i * 2] == 0) {
                break;
            }
            name[i * 2] = 0x81;
            name[i * 2 + 1] = 0x96;
        }
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_14CEB8 */

/* fzgx:begin fn_1_14D5CC noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

// Keep sampling candidates until one satisfies the required and forbidden flags.
s16 fn_1_14D5CC(s16 arg0, u32 required_mask, u32 forbidden_mask) {
    s16 candidate_index;
    s32 random_value;

    do {
        lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        random_value = (lbl_801A63C0 >> 16) & 0x7fff;
        candidate_index =
            fn_1_14F090(arg0, (random_value % fn_1_14F01C(arg0)));
        random_value = fn_1_14D6D8(candidate_index);
    } while ((required_mask & random_value) == 0 ||
             (forbidden_mask & fn_1_14D6D8(candidate_index)) != 0);

    return candidate_index;
}
/* fzgx:end fn_1_14D5CC */

/* fzgx:begin fn_1_14D670 noprologue */
s16 fn_1_14D670(void) {
    u32 value;
    s32 sample;
    s16 result;

    do {
        value = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        lbl_801A63C0 = value;
        sample = (value >> 16) & 0x7fff;
        result = sample % 30;
    } while (result == 2 || (u16)(result - 4) <= 2);

    return result;
}
/* fzgx:end fn_1_14D670 */

/* fzgx:begin fn_1_14D6D8 noprologue */
typedef struct {
    u32 values[75];
} Table75;

u32 fn_1_14D6D8(s16 index) {
    Table75 values = *(Table75 *)lbl_1_rodata_99D8;

    return values.values[index];
}
/* fzgx:end fn_1_14D6D8 */

/* fzgx:begin fn_1_14D728 noprologue */
typedef struct { u32 values[75]; } InitTable;

void fn_1_14D728(Source *source, Display *displays) {
    char * data = (((char *)&lbl_1_data_43E78));
    InitTable table;
    struct { Display * value; } current;
    Source * base;
    struct { s16 * value; } index_ptr;
    s16 group;

    table = *(InitTable *)lbl_1_rodata_9B04;
    base = source;
    index_ptr.value = source->indices;
    current.value = displays;

    for (group = 0; group < 3u; group++) {
        s16 index = *index_ptr.value;
        current.value->index = index;
        if (index != -1) {
            s16 slot;
            s16 pos;
            for (pos = 0; pos < strlen((char *)((table.values)[index])); pos++) {
                u8 *p = (u8 *)((table.values)[index]);
                u8 c = ((p)[pos]);
                p[pos] = (c == -1) ? -1 : (((((u8 *)&lbl_8015B200)))[c]);
            }
            for (slot = 0; slot < 4; slot++) {
                if (current.value->handle[slot] == 0 && (base->flags & (1 << slot)) != 0) {
                    char buffer[0x20];
                    if (slot == 0)
                        sprintf(buffer, data + 0x1338, ((table.values)[index]), slot);
                    else
                        sprintf(buffer, data + 0x1348, ((table.values)[index]), slot + 1);
                    current.value->handle[slot] = fn_1_12ADA0(buffer, current.value->object);
                    fn_1_8019C(((slot)[current.value->handle]));
                }
            }
            {
                char buffer[0x20];
                sprintf(buffer, data + 0x135c, ((table.values)[index]));
                fn_1_12A7C4(buffer, (char *)current.value + 0x20, 0x320);
            }
        }
        index_ptr.value++;
        current.value = (Display *)((u8 *)current.value + 0x360);
    }
}
/* fzgx:end fn_1_14D728 */

/* fzgx:begin fn_1_14D8DC noprologue */
void fn_1_14D8DC(u8 *arg0, u8 *arg1, s16 arg2) {
    u8 *data;
    u8 *p1;
    u8 *p0;
    s16 i;

    data = lbl_1_data_43E78;
    if (lbl_1_bss_6D82C.unk_0 == 0) {
        fn_1_12AB38(data + 0x136c);
        lbl_1_bss_6D82C.unk_0 = (u32)fn_1_D3884(data + 0x1378);
        fn_1_12AB38(data + 0x1388);
    }

    fn_1_12AB38(data + 0x138c);

    p1 = arg1;
    p0 = arg0;
    for (i = 0; i < arg2; i++) {
        fn_1_14D728( (Source *)(p0), (Display *)(p1));
        p1 += 0xa20;
        p0 += 0x10;
    }

    fn_1_12AB38(data + 0x1388);
}
/* fzgx:end fn_1_14D8DC */

/* fzgx:begin fn_1_14D994 noprologue */
#include "rel/main_rel/sel_static_disp.h"

extern void *fn_1_D3884(u32);
typedef struct {
    s16 a;
    s16 b;
    s16 c;
    u8 pad[2];
    u32 v;
    u32 pad2;
} Ent_14D994;

static inline void init_14D994(Ent_14D994 *e, u32 v, s32 i)
{
    e->v = v;
    e->a = i;
    e->b = i + 25;
    e->c = i + 50;
}

void fn_1_14D994(u8 *arg0, u32 arg1, int flag)
{
    Ent_14D994 ents[25];
    Ent_14D994 *p = ents;
    u8 *d = lbl_1_data_43E78;
    struct { s16 value; } j;
    s16 k;
    u8 *q_else;
    struct { u8 *ptr; } q;
    struct { Ent_14D994 *ptr; } e;
    s16 i;
    e.ptr = p;
    for (i = 0; i < 25; i++) {
        init_14D994(e.ptr, arg1, i);
        e.ptr++;
    }
    if (flag) {
        if (lbl_1_bss_6D82C.unk_0 == 0) {
            fn_1_12AB38(d + 0x136c);
            *(void **)&lbl_1_bss_6D82C = fn_1_D3884((u32)(d + 0x1378));
            fn_1_12AB38(d + 0x1388);
        }
        fn_1_12AB38(d + 0x138c);
        j.value = 0;
        q.ptr = arg0;
        for (; j.value < 25; j.value++) {
            fn_1_14D728(p, q.ptr);
            q.ptr += 0xa20;
            p++;
        }
        fn_1_12AB38(d + 0x1388);
    } else {
        fn_1_12AB38(d + 0x138c);
        q_else = arg0;
        for (k = 0; k < 25; k++) {
            fn_1_14D728(p, q_else);
            q_else += 0xa20;
            p++;
        }
        fn_1_12AB38(d + 0x1388);
    }
}
/* fzgx:end fn_1_14D994 */

/* fzgx:begin fn_1_14DB48 */
typedef struct {
    u16 values[3];
    u32 extra;
} StaticDispPacket;

void fn_1_14DB48(u32 *state, void *arg1, u32 arg2) {
    u32 flags = *state;

    if ((flags & (1u << 31)) == 0 || (flags & (1u << 30)) == 0) {
        return;
    }

    {
        u8 *base = (u8 *)state + 0x10000;
        StaticDispPacket packet;

        packet.extra = arg2;
        packet.values[0] = base[0x81a4 - 0x10000];
        packet.values[1] = base[0x81ac - 0x10000];
        packet.values[2] = base[0x81b4 - 0x10000];
        fn_1_12AB38(lbl_1_data_45204);
        fn_1_14D728( (Source *)(&packet), (Display *)(arg1));
        fn_1_12AB38(&lbl_1_data_45200);
    }
}
/* fzgx:end fn_1_14DB48 */

/* fzgx:begin fn_1_14DBCC */
typedef struct {
    u8 pad[0x340];
    void *field_340;
    void *fields_344[4];
    u8 tail[0xc];
} Fn1_14DBCC_Item;

void fn_1_14DBCC(Fn1_14DBCC_Item *arg0) {
    Fn1_14DBCC_Item *base;
    s16 i;
    s16 j;
    Fn1_14DBCC_Item *item;

    base = arg0;
    for (i = 0; (u32)i < 3; i++) {
        item = base;
        for (j = 0; j < 4; j++) {
            if (item->fields_344[j] != 0) {
                fn_800711A8(item->fields_344[j]);
                item->fields_344[j] = 0;
            }
        }
        if (base->field_340 != 0) {
            fn_80071718(base->field_340);
            base->field_340 = 0;
        }
        base++;
    }
}
/* fzgx:end fn_1_14DBCC */

/* fzgx:begin fn_1_14DC68 */
typedef struct {
    u8 pad_0[0x340];
    void *unk_340;
    void *unk_344;
    u8 pad_348[0x18];
} fn_1_14DC68_StaticDispEntry;

void fn_1_14DC68(fn_1_14DC68_StaticDispEntry *arg0, s16 arg1) {
    struct { s16 value; } k;
    s16 j;
    fn_1_14DC68_StaticDispEntry *cursor;
    fn_1_14DC68_StaticDispEntry *base;
    fn_1_14DC68_StaticDispEntry *p;
    s16 i;

    if (lbl_1_bss_6D82C.unk_0 != 0) {
        fn_80071718((void *)lbl_1_bss_6D82C.unk_0);
        lbl_1_bss_6D82C.unk_0 = 0;
    }

    p = arg0;

    fn_1_12AB38(&"vehicle_parts/");

    for (i = 0; i < arg1; i++) {
        base = p;
        for (j = 0; j < 3u; j++) {
            cursor = base;
            for (k.value = 0; k.value < 4; k.value++) {
                if (cursor->unk_344 != 0) {
                    fn_800711A8(cursor->unk_344);
                    cursor->unk_344 = 0;
                }
                cursor = (fn_1_14DC68_StaticDispEntry *)((u8 *)cursor + 4);
            }
            if (base->unk_340 != 0) {
                fn_80071718(base->unk_340);
                base->unk_340 = 0;
            }
            base = (fn_1_14DC68_StaticDispEntry *)((u8 *)base + 0x360);
        }
        p = (fn_1_14DC68_StaticDispEntry *)((u8 *)p + 0xa20);
    }

    fn_1_12AB38(&lbl_1_data_45200);
}
/* fzgx:end fn_1_14DC68 */

/* fzgx:begin fn_1_14DD68 */

static inline u8 *fn_1_14DD68_find(u8 *base) {
    u8 *p;
    u8 *result;
    s16 i;

    result = 0;
    i = 0;
    p = base;

    for (; (u32)i < 3; i++) {
        if (((s16)fn_1_14F344( (void *)(s16)(*(s16 *)p))) == 0) {
            result = base + i * 0x360 + 0x23c;
            break;
        }
        p += 0x360;
    }
    return result;
}

void *fn_1_14DD68(void *arg0) {
    return fn_1_14DD68_find(arg0);
}
/* fzgx:end fn_1_14DD68 */

/* fzgx:begin fn_1_14DDF4 */

static inline u8 *fn_1_14DDF4_find(u8 *base) {
    u8 *p;
    u8 *result;
    s16 i;

    result = 0;
    i = 0;
    p = base;

    for (; (u32)i < 3; i++) {
        if (((s16)fn_1_14F344( (void *)(s16)(*(s16 *)p))) == 0) {
            result = base + i * 0x360 + 0x228;
            break;
        }
        p += 0x360;
    }
    return result;
}

void *fn_1_14DDF4(void *arg0) {
    return fn_1_14DDF4_find(arg0);
}
/* fzgx:end fn_1_14DDF4 */

/* fzgx:begin fn_1_14DE80 */
void fn_1_14DE80(void *arg0, void *arg1, void *arg2, void *arg3) {
    fn_1_14DEC8(arg0, arg1, arg2, arg3, 0);
}
/* fzgx:end fn_1_14DE80 */

/* fzgx:begin fn_1_14DEA4 */
void fn_1_14DEA4(void *arg0, void *arg1, void *arg2, void *arg3) {
    fn_1_14DEC8(arg0, arg1, arg2, arg3, 1);
}
/* fzgx:end fn_1_14DEA4 */

/* fzgx:begin fn_1_14DEC8 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct {
void *value;
} Val;
typedef struct {
u8 pad8[8];
Val *value;
} Ref;
typedef struct {
u8 pad344[0x344];
Ref *ref;
} Obj;
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(f32);
extern s16 fn_1_14F344(s16);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
static inline void *find(void *base, int off) {
s16 *entry = base;
void *r = 0;
s16 i;
for (i = 0; (u32)i < 3; i++) {
if (fn_1_14F344(*entry) == 0) {
r = (u8 *)base + i * 0x360 + off;
break;
}
entry = (s16 *)((u8 *)entry + 0x360);
}
return r;
}
static inline void *find2(void *base, int off) {
void *r = 0;
s16 i;
s16 *entry;
i = 0;
entry = base;
for (; (u32)i < 3; i++) {
if (fn_1_14F344(*entry) == 0) {
r = (u8 *)base + i * 0x360 + off;
break;
}
entry = (s16 *)((u8 *)entry + 0x360);
}
return r;
}
void fn_1_14DEC8(void *arg0, void **arg1, void **arg2, s16 arg3, int arg4, f32 arg5) {
s16 *entry;
Obj *obj;
s16 i;
int same;
void *value;
same = lbl_1_rodata_9C30 == arg5;
if (!same) {
fn_1_55FF0(arg5);
}
i = 0;
entry = arg0;
obj = (Obj *)((u8 *)arg0 + (arg3 << 2));
for (; (u32)i < 3; i++) {
if (fn_1_14F344(*entry) == 0) {
value = obj->ref->value->value;
if (value != 0) {
fn_80072558();
fn_1_151C3C(0, *(s16 *)((u8 *)arg0 + i * 0x360));
if (same || arg4 != 0) {
fn_1_556B8(value);
} else {
fn_1_55210(value);
}
fn_1_151C78();
*arg1 = find(arg0, 0x23c);
*arg2 = find2(arg0, 0x228);
break;
}
}
entry = (s16 *)((u8 *)entry + 0x360);
obj = (Obj *)((u8 *)obj + 0x360);
}
}
/* fzgx:end fn_1_14DEC8 */

/* fzgx:begin fn_1_14E054 */
void fn_1_14E054(void *arg0, void *arg1, void *arg2) {
    fn_1_14E09C(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_14E054 */

/* fzgx:begin fn_1_14E078 */
void fn_1_14E078(void *arg0, void *arg1, void *arg2) {
    fn_1_14E09C(arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_14E078 */

/* fzgx:begin fn_1_14E09C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(void);
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

void fn_1_14E09C(Fn14E09CObj *arg0, void *arg1, s16 arg2, int arg3, f32 arg4) {
    s16 *entry;
    Fn14E09CObj *obj;
    s16 i;
    int same;
    void *value;

    same = lbl_1_rodata_9C30 == arg4;
    if (arg1 != 0) {
        if (!same) {
            fn_1_55FF0();
        }

        entry = (s16 *)arg0;
        obj = (Fn14E09CObj *)((u8 *)arg0 + (arg2 << 2));
        for (i = 0; (u32)i < 3; i++) {
            if (fn_1_14F344(*entry) == 1) {
                value = obj->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(arg1);
                    fn_80072558();
                    fn_1_151C3C(1, *entry);
                    if (same || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            obj = (Fn14E09CObj *)((u8 *)obj + 0x360);
        }
    }
}
/* fzgx:end fn_1_14E09C */

/* fzgx:begin fn_1_14E198 */
void fn_1_14E198(void *arg0, void *arg1, void *arg2) {
    fn_1_14E1E0(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_14E198 */

/* fzgx:begin fn_1_14E1BC */
void fn_1_14E1BC(void *arg0, void *arg1, void *arg2) {
    fn_1_14E1E0(arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_14E1BC */

/* fzgx:begin fn_1_14E1E0 noprologue */
#include "types.h"

typedef struct {
    unsigned char pad[8];
    void **value;
} Inner;

typedef struct {
    unsigned char pad[0x344];
    Inner *inner;
} Record;

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(void);
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);

void fn_1_14E1E0(void *arg0, void *arg1, s16 arg2, int arg3, f32 arg4) {
    unsigned char *p;
    Record *q;
    s16 i;
    int same;
    void *value;

    same = (lbl_1_rodata_9C30 == arg4);
    if (arg1 != 0) {
        if (same == 0) {
            fn_1_55FF0();
        }

        p = (unsigned char *)arg0;
        q = (Record *)(p + arg2 * 4);
        i = 0;
        while ((u32)i < 3) {
            if (fn_1_14F344(*(s16 *)p) == 2) {
                value = *q->inner->value;
                if (value != 0) {
                    lbl_8006E0A4(arg1);
                    fn_80072558();
                    fn_1_151C3C(2, *(s16 *)p);
                    if (same != 0 || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            p += 0x360;
            q = (Record *)((unsigned char *)q + 0x360);
            i++;
        }
    }
}
/* fzgx:end fn_1_14E1E0 */

/* fzgx:begin fn_1_14E2DC noprologue */
#include "types.h"

/* the part record's model pointer chain (+0x344, +0x8, +0x0), as fn_1_14DEC8 and fn_1_14E09C read it */
typedef struct {
    void *value;
} fn_1_14E2DC_Val;
typedef struct {
    u8 pad_0[0x8];
    fn_1_14E2DC_Val *value;
} fn_1_14E2DC_Ref;
typedef struct {
    u8 pad_0[0x344];
    fn_1_14E2DC_Ref *ref;
} fn_1_14E2DC_Obj;

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);

/* fn_1_14DEC8 (the body), inlined with arg4 = 0, its two searches for the record + 0x23C / + 0x228 written out */
static inline void fn_1_14E2DC_body(void *arg0, void **arg1, void **arg2, s16 arg3, f32 arg5) {
    fn_1_14E2DC_Obj *obj;
    s16 *entry;
    void *r;
    s16 *p;
    s16 *p1;
    s16 j;
    s16 i;
    void *r1;
    int same;
    void *value;

    same = lbl_1_rodata_9C30 == arg5;
    if (!same) {
        fn_1_55FF0(arg5);
    }
    entry = arg0;
    obj = (fn_1_14E2DC_Obj *)((u8 *)arg0 + (arg3 << 2));
    for (i = 0; (u32)i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            value = obj->ref->value->value;
            if (value != 0) {
                fn_80072558();
                fn_1_151C3C(0, *(s16 *)((u8 *)arg0 + i * 0x360));
                if (same) {
                    fn_1_556B8(value);
                } else {
                    fn_1_55210(value);
                }
                fn_1_151C78();
                r1 = 0;
                p1 = arg0;
                for (j = 0; (u32)j < 3; j++) {
                    if (fn_1_14F344(*p1) == 0) {
                        r1 = (u8 *)arg0 + j * 0x360 + 0x23C;
                        break;
                    }
                    p1 = (s16 *)((u8 *)p1 + 0x360);
                }
                *arg1 = r1;
                r = 0;
                j = 0;
                p = arg0;
                for (; (u32)j < 3; j++) {
                    if (fn_1_14F344(*p) == 0) {
                        r = (u8 *)arg0 + j * 0x360 + 0x228;
                        break;
                    }
                    p = (s16 *)((u8 *)p + 0x360);
                }
                *arg2 = r;
                break;
            }
        }
        entry = (s16 *)((u8 *)entry + 0x360);
        obj = (fn_1_14E2DC_Obj *)((u8 *)obj + 0x360);
    }
}

/* opt_lifetimes off (as fn_1_13A460 and fn_1_13D460 in this file): retail reuses the body loop's registers in the
 * two searches. The cockpit (kind 1) and booster (kind 2) draws of fn_1_14E09C and fn_1_14E1E0 are written out;
 * the booster loop steps slot itself, as retail steps r31 */
#pragma opt_lifetimes off
void fn_1_14E2DC(void *parts, s16 index, f32 alpha) {
    void *cockpit_point = 0;
    void *booster_point = 0;
    s16 *entry;
    fn_1_14E2DC_Obj *slot;
    fn_1_14E2DC_Obj *obj;
    void *value;
    int same;
    s16 i;

    fn_1_14E2DC_body(parts, &cockpit_point, &booster_point, index, alpha);
    slot = (fn_1_14E2DC_Obj *)((u8 *)parts + (index << 2));
    lbl_8006DAEC();
    same = lbl_1_rodata_9C30 == alpha;
    if (cockpit_point != 0) {
        if (!same) {
            fn_1_55FF0(alpha);
        }
        entry = parts;
        obj = slot;
        for (i = 0; (u32)i < 3; i++) {
            if (fn_1_14F344(*entry) == 1) {
                value = obj->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(cockpit_point);
                    fn_80072558();
                    fn_1_151C3C(1, *entry);
                    if (same) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            obj = (fn_1_14E2DC_Obj *)((u8 *)obj + 0x360);
        }
    }
    lbl_8006DBE4();
    same = lbl_1_rodata_9C30 == alpha;
    if (booster_point != 0) {
        if (!same) {
            fn_1_55FF0(alpha);
        }
        entry = parts;
        for (i = 0; (u32)i < 3; i++) {
            if (fn_1_14F344(*entry) == 2) {
                value = slot->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(booster_point);
                    fn_80072558();
                    fn_1_151C3C(2, *entry);
                    if (same) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            slot = (fn_1_14E2DC_Obj *)((u8 *)slot + 0x360);
        }
    }
    lbl_8006DC20();
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_14E2DC */

/* fzgx:begin fn_1_14E5E4 noprologue */
#include "types.h"
#include "dolphin/types.h"

typedef struct {
    void *value;
} Val;

typedef struct {
    u8 pad8[8];
    Val *value;
} Ref;

typedef struct {
    u8 pad344[0x344];
    Ref *ref;
} Obj;

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(f32);
extern s16 fn_1_14F344(s16);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E0A4(void *);

#pragma opt_lifetimes off

/* Returns base + i * 0x360 + off for the first of three entries whose kind is 0. */
static inline void *find(void *base, int off) {
    s16 i;
    s16 *entry = base;
    void *r = 0;
    for (i = 0; i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            r = (u8 *)base + i * 0x360 + off;
            break;
        }
        entry = (entry + 0x360);
    }
    return r;
}

static inline void *find2(void *base, int off) {
    s16 i;
    s16 *entry;
    void *r = 0;
    i = 0;
    entry = base;
    for (; i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            r = (u8 *)base + i * 0x360 + off;
            break;
        }
        entry = (entry + 0x360);
    }
    return r;
}

/* Same-TU siblings fn_1_14DEC8 / fn_1_14E09C (and its kind-2 twin), inlined here by retail. */
static inline void drawKind0(void *arg0, void **arg1, void **argB, s16 arg3, int arg4, f32 arg5) {
    Obj *obj;
    s16 *entry;
    s16 i;
    int same;
    void *value;
    void *second;

    second = *argB;
    same = lbl_1_rodata_9C30 == arg5;
    if (!same) {
        fn_1_55FF0(arg5);
    }

    i = 0;
    entry = arg0;
    obj = (Obj *)((u8 *)arg0 + (arg3 << 2));
    for (; (u32)i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            value = obj->ref->value->value;
            if (value != 0) {
                fn_80072558();
                fn_1_151C3C(0, *(s16 *)((u8 *)arg0 + i * 0x360));
                if (same || arg4 != 0) {
                    fn_1_556B8(value);
                } else {
                    fn_1_55210(value);
                }
                fn_1_151C78();
                value = 0;
                second = arg0;
                for (i = 0; (u32)i < 3; i++) {
                    if (fn_1_14F344(*(s16 *)second) == 0) {
                        value = (u8 *)arg0 + i * 0x360 + 0x23c;
                        break;
                    }
                    second = (u8 *)second + 0x360;
                }
                second = 0;
                *arg1 = value;
                i = 0;
                value = arg0;
                for (; (u32)i < 3; i++) {
                    if (fn_1_14F344(*(s16 *)value) == 0) {
                        second = (u8 *)arg0 + i * 0x360 + 0x228;
                        break;
                    }
                    value = (u8 *)value + 0x360;
                }
                break;
            }
        }
        entry = (s16 *)((u8 *)entry + 0x360);
        obj = (Obj *)((u8 *)obj + 0x360);
    }
    *argB = second;
}

static inline void drawKinds(void *arg0, void *arg1, void *argB, s16 arg2, int arg3, f32 arg4) {
    s16 i;
    void *value;
    Obj *obj;
    Obj *obj2;
    s16 *entry;
    int same;

    same = lbl_1_rodata_9C30 == arg4;
    if (arg1 != 0) {
        if (!same) {
            fn_1_55FF0(arg4);
        }

        entry = arg0;
        obj = (Obj *)((u8 *)arg0 + (arg2 << 2));
        for (i = 0; (u32)i < 3; i++) {
            if (fn_1_14F344(*entry) == 1) {
                value = obj->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(arg1);
                    fn_80072558();
                    fn_1_151C3C(1, *entry);
                    if (same || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            obj = (Obj *)((u8 *)obj + 0x360);
        }
    }
    lbl_8006DBE4();
    same = lbl_1_rodata_9C30 == arg4;
    if (argB != 0) {
        if (!same) {
            fn_1_55FF0(arg4);
        }

        entry = arg0;
        obj2 = (Obj *)((u8 *)arg0 + (arg2 << 2));
        for (i = 0; (u32)i < 3; i++) {
            if (fn_1_14F344(*entry) == 2) {
                value = obj2->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(argB);
                    fn_80072558();
                    fn_1_151C3C(2, *entry);
                    if (same || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            obj2 = (Obj *)((u8 *)obj2 + 0x360);
        }
    }
}

void fn_1_14E5E4(void *arg0, s16 arg1, f32 arg2) {
    void *a;
    void *b;

    a = 0;
    b = 0;
    drawKind0(arg0, &a, &b, arg1, 1, arg2);
    lbl_8006DAEC();
    drawKinds(arg0, a, b, arg1, 1, arg2);
    lbl_8006DC20();
}
/* fzgx:end fn_1_14E5E4 */

/* fzgx:begin fn_1_14E8A4 */
typedef struct {
    s16 value;
    s16 sort_key;
} Fn1_14E8A4Entry;

int fn_1_14E8A4(const Fn1_14E8A4Entry *arg0, const Fn1_14E8A4Entry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg0->sort_key - arg1->sort_key;
}
/* fzgx:end fn_1_14E8A4 */

/* fzgx:begin fn_1_14E8CC */
typedef struct {
    s16 value;
    u8 pad[8];
    s16 sort_key;
} Fn1_14E8CCEntry;

int fn_1_14E8CC(const Fn1_14E8CCEntry *arg0, const Fn1_14E8CCEntry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg0->sort_key - arg1->sort_key;
}
/* fzgx:end fn_1_14E8CC */

/* fzgx:begin fn_1_14E8F4 */
typedef struct {
    s16 value;
    u8 padding[8];
    s16 sort_key;
} Fn1_14E8F4Entry;

int fn_1_14E8F4(const Fn1_14E8F4Entry *arg0, const Fn1_14E8F4Entry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg1->sort_key - arg0->sort_key;
}
/* fzgx:end fn_1_14E8F4 */

/* fzgx:begin fn_1_14E91C */
typedef struct {
    s16 value;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 sort_key;
} Fn1_14E91CEntry;

int fn_1_14E91C(const Fn1_14E91CEntry *arg0, const Fn1_14E91CEntry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg0->sort_key - arg1->sort_key;
}
/* fzgx:end fn_1_14E91C */

/* fzgx:begin fn_1_14E944 */
typedef struct {
    s16 value;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 sort_key;
} Fn1_14E944Entry;

int fn_1_14E944(const Fn1_14E944Entry *arg0, const Fn1_14E944Entry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg1->sort_key - arg0->sort_key;
}
/* fzgx:end fn_1_14E944 */

/* fzgx:begin fn_1_14E96C */

s32 fn_1_14E96C(const CompareEntry *a, const CompareEntry *b)
{
    if (a->value == b->value) {
        return a->index - b->index;
    }
    return (a->value - b->value);
}
/* fzgx:end fn_1_14E96C */

/* fzgx:begin fn_1_14E9A8 noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

typedef struct CompareEntry {
    s16 index;
    f32 value;
} CompareEntry;

s32 fn_1_14E9A8(const CompareEntry *a, const CompareEntry *b)
{
    if (a->value == b->value) {
        return a->index - b->index;
    }
    return (b->value - a->value);
}
/* fzgx:end fn_1_14E9A8 */

/* fzgx:begin fn_1_14E9E4 noprologue */
typedef struct {
    Fn1_14E9E4Entry entries[75];
} Fn1_14E9E4Blob;


void fn_1_14E9E4(int arg0, void *arg1) {
    Fn1_14E9E4Blob buf;

    buf = *(Fn1_14E9E4Blob *)lbl_1_rodata_9CDC;
    buf.entries[(s16)arg0].value = fn_1_14F608(arg0)->value;
    fn_80008BA8( (u32)(arg1), (u32)(&buf.entries[(s16)arg0]), 16);
}
/* fzgx:end fn_1_14E9E4 */

/* fzgx:begin fn_1_14EA74 noprologue */
typedef struct {
    u8 bytes[0x708];
} Fn1_14EA74Blob;


char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2) {
    char first[0x40];
    u8 second[0x40];
    Fn1_14EA74Blob local;
    const char *data;
    u8 *base;
    s32 index;

    data = (((char *)&lbl_1_data_43E78));
    local = *(const Fn1_14EA74Blob *)lbl_1_rodata_A18C;
    base = local.bytes;
    index = arg0 * 0x18 + arg2 * 4;
    if ((s16)fn_1_14FE48(*(void **)(base + index), (void *)(data + 0x2428)) < 2) {
        sprintf(arg1, data + 0x242c,
                fn_1_14FDAC(*(void **)(base + index), (void *)(data + 0x2428), 0, first));
    } else {
        if (fn_1_14F344(arg0) == 0) {
            fn_1_14FDAC(*(void **)(base + index), (void *)(data + 0x2428), 0, first);
            fn_1_14FDAC(*(void **)(base + index), (void *)(data + 0x2428), 1, second);
            if (second[0] == 0x2d) {
                sprintf(arg1, data + 0x2430, first, second);
            } else {
                sprintf(arg1, data + 0x2438, first, second);
            }
        }
        sprintf(arg1, data + 0x2438,
                fn_1_14FDAC(*(void **)(base + index), (void *)(data + 0x2428), 0, first),
                fn_1_14FDAC(*(void **)(base + index), (void *)(data + 0x2428), 1, second));
    }
    return arg1;
}
/* fzgx:end fn_1_14EA74 */

/* fzgx:begin fn_1_14EBF8 */

typedef struct {
    void *word[75][6];
} Table1800;

char * fn_1_14EBF8(s16 arg0, char *arg1, s16 arg2) {
    char *data = (char *)lbl_1_data_43E78;
    char buf0[64];
    Table1800 table;
    char buf3[64];

    table = *(Table1800 *)lbl_1_rodata_A894;

    if (((s16)fn_1_14FE48(table.word[arg0][arg2], data + 0x2428)) < 2) {
        sprintf((char *)arg1, data + 0x242c,
                fn_1_14FDAC(table.word[arg0][arg2], data + 0x2428, 0, buf0));
    } else {
        sprintf((char *)arg1, data + 0x2438,
                fn_1_14FDAC(table.word[arg0][arg2], data + 0x2428, 2, buf0),
                fn_1_14FDAC(table.word[arg0][arg2], data + 0x2428, 3, buf3));
    }
    return (char *)(arg1);
}
/* fzgx:end fn_1_14EBF8 */

/* fzgx:begin fn_1_14ED00 noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

typedef struct {
    u32 values[5];
    u32 unk0;
} Fn1_14ED00Row;

typedef struct {
    Fn1_14ED00Row rows[75];
} Fn1_14ED00Blob;


s32 fn_1_14ED00(s32 arg0, void *arg1, s32 arg2) {
    u8 buffer[64];
    Fn1_14ED00Blob blob = *(const Fn1_14ED00Blob *)lbl_1_rodata_AF9C;
    s16 type;

    type = fn_1_14FE48( (void *)(blob.rows[(s16)arg0].values[(s16)arg2]), &lbl_1_data_462A0);
    if (type < 2) {
        sprintf(arg1, (const char *)(&lbl_1_data_462A4),
                    fn_1_14FDAC( (void *)(blob.rows[(s16)arg0].values[(s16)arg2]), &lbl_1_data_462A0, 0, buffer));
    } else {
        sprintf(arg1, (const char *)(&lbl_1_data_462A4),
                    fn_1_14FDAC( (void *)(blob.rows[(s16)arg0].values[(s16)arg2]), &lbl_1_data_462A0, 2, buffer));
    }
    return (s32)arg1;
}
/* fzgx:end fn_1_14ED00 */

/* fzgx:begin fn_1_14EE00 noprologue */
typedef struct {
    u32 word[60];
} Table240;

char lbl_1_data_462B8[3] = "A+";
char lbl_1_data_462BC[2] = "A";
char lbl_1_data_462C0[3] = "B+";
char lbl_1_data_462C4[2] = "B";
char lbl_1_data_462C8[3] = "C+";
char lbl_1_data_462CC[3] = "D+";
char lbl_1_data_462D0[2] = "D";
char lbl_1_data_462D4[3] = "E+";
char lbl_1_data_462D8[2] = "E";

int fn_1_14EE00(s16 arg0, void *arg1, s16 arg2) {
    u32 table[60];

    *(Table240 *)table = *(Table240 *)lbl_1_rodata_B794;

    switch (arg0) {
    case 0:
        arg0 = 1;
        break;
    case 2:
        arg0 = 3;
        break;
    case 4:
        arg0 = 5;
        break;
    case 6:
        arg0 = 7;
        break;
    case 8:
        arg0 = 9;
        break;
    default:
        break;
    }

    strcpy( arg1, ((void *)*(u32 *)((u8 *)table + arg0 * 24 + arg2 * 4)));
    return (int)arg1;
}
/* fzgx:end fn_1_14EE00 */

/* fzgx:begin fn_1_14EEC4 noprologue */
typedef struct {
    u32 values[3][6];
} StaticDispTable;

void *fn_1_14EEC4(s16 index, void *obj, s16 subindex) {
    StaticDispTable table;

    table = *(StaticDispTable *)lbl_1_rodata_B884;
    strcpy( obj, (const char *)(table.values[index][subindex]));
    return obj;
}
/* fzgx:end fn_1_14EEC4 */

/* fzgx:begin fn_1_14EF40 noprologue */
typedef struct {
    u8 pad[4];
    f32 value;
    u8 tail[8];
} Fn1_14EF40Value;


s16 fn_1_14EF40(void *arg0, void *arg1, void *arg2) {
    Fn1_14EF40Value value;
    s16 accum;

    fn_1_14E9E4( (int)(arg0), (Fn1_14EF40Value *)(&value));
    accum = value.value;
    fn_1_14E9E4( (int)(arg1), (Fn1_14EF40Value *)(&value));
    accum = (accum + value.value);
    fn_1_14E9E4( (int)(arg2), (Fn1_14EF40Value *)(&value));
    return (accum + value.value);
}
/* fzgx:end fn_1_14EF40 */

/* fzgx:begin fn_1_14F014 noprologue */
// fn_1_14F014: returns a constant.
int fn_1_14F014(void) {
    return 75;
}
/* fzgx:end fn_1_14F014 */

/* fzgx:begin fn_1_14F01C noprologue */
typedef struct {
    u8 unk0[2];
    s16 value;
    u8 unk4[12];
} fn_1_14F01C_Entry;

typedef struct {
    fn_1_14F01C_Entry entries[75];
} fn_1_14F01C_Table;

// Count entries in the static display table whose value matches the argument.
s16 fn_1_14F01C(s16 value) {
    fn_1_14F01C_Table table;
    s16 count;
    s16 i;

    table = *(fn_1_14F01C_Table *)lbl_1_rodata_B8D8;
    i = 0;
    count = 0;
    while (i < 75) {
        if (table.entries[i].value == value) {
            count++;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_1_14F01C */

/* fzgx:begin fn_1_14F090 noprologue */
typedef struct {
    u8 unk0[2];
    s16 value;
    u8 unk4[12];
} fn_1_14F090_Entry;

typedef struct {
    fn_1_14F090_Entry entries[75];
} fn_1_14F090_Table;

// Finds the index of the requested occurrence of a value in the static table.
s16 fn_1_14F090(s16 value, s16 occurrence) {
    fn_1_14F090_Table table;
    s16 i;
    s16 count;

    table = *(fn_1_14F090_Table *)lbl_1_rodata_BD88;
    i = 0;
    count = 0;
    while (i < 75) {
        if (table.entries[i].value == value) {
            if (count == occurrence) {
                return i;
            }
            count++;
        }
        i++;
    }
    return -1;
}
/* fzgx:end fn_1_14F090 */

/* fzgx:begin fn_1_14F118 */

// Returns the index of the first table entry matching the requested value.
s16 fn_1_14F118(s16 value, void *table) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            return index;
        }
    }
    return -1;
}
/* fzgx:end fn_1_14F118 */

/* fzgx:begin fn_1_14F19C noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

typedef struct {
    u32 values[75];
} FlagTable;

// Returns the ordinal among enabled entries for the requested value, or -1 if absent.
s16 fn_1_14F19C(s16 wanted, s16 arg, u32 mask) {
    FlagTable table;
    s16 entry_index;
    s16 enabled_ordinal;

    entry_index = 0;
    enabled_ordinal = 0;
    for (; entry_index < fn_1_14F01C(arg); entry_index++) {
        s16 value;

        value = fn_1_14F090(arg, entry_index);
        table = *(FlagTable *)lbl_1_rodata_99D8;
        if (mask & table.values[value]) {
            if (value == wanted) {
                return enabled_ordinal;
            }
            enabled_ordinal++;
        }
    }
    return -1;
}
/* fzgx:end fn_1_14F19C */

/* fzgx:begin fn_1_14F270 */

typedef struct {
    u32 values[75];
} MaskTable;

s16 fn_1_14F270(s16 wanted, void *arg, u32 mask) {
    MaskTable table;
    const MaskTable *source;
    s16 i;
    s16 count;
    s16 index;

    source = (const MaskTable *)(((f32 *)&lbl_1_rodata_99D8));
    i = 0;
    count = 0;
    for (; i < fn_1_14F01C(arg); i++) {
        index = fn_1_14F090(arg, i);
        table = *source;
        if (mask & table.values[index]) {
            if (count == wanted) {
                return index;
            }
            count++;
        }
    }
    return -1;
}
/* fzgx:end fn_1_14F270 */

/* fzgx:begin fn_1_14F344 noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

typedef struct {
    u8 unk0[2];
    s16 value;
    u8 unk4[12];
} fn_1_14F344_Entry;

typedef struct {
    fn_1_14F344_Entry entries[75];
} fn_1_14F344_Table;

s16 fn_1_14F344(s16 index) {
    fn_1_14F344_Table table;

    table = *(fn_1_14F344_Table *)lbl_1_rodata_C6E8;
    return table.entries[index].value;
}
/* fzgx:end fn_1_14F344 */

/* fzgx:begin fn_1_14F38C noprologue */
typedef struct {
    u8 unk0[2];
    s16 unk2;
    u8 unk4[6];
    u32 flags;
    s16 value;
} fn_1_14F38C_StaticDisp;


static inline s16 find_index(s16 value, s16 table) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (value == fn_1_14F090(table, index)) {
            return index;
        }
    }
    return -1;
}

void fn_1_14F38C(fn_1_14F38C_StaticDisp *disp, u8 *table) {
    s16 j;
    s16 value;
    u8 *p;
    u8 *cur;
    s16 i;

    if (disp->unk2 > 0x28) {
        p = table;
        cur = (u8 *)disp;
        for (i = 0; i < 3u; i++) {
            *(s16 *)(cur + 0x10) = p[0x81a4];
            value = *(s16 *)(cur + 0x10);
            j = find_index(value, i);
            if (j == -1) {
                *(s16 *)(cur + 0x10) = fn_1_14F090(i, 0);
            }
            p += 8;
            cur += 2;
        }
        disp->flags |= 0x04000000;
    }
}
/* fzgx:end fn_1_14F38C */

/* fzgx:begin fn_1_14F46C noprologue */
typedef struct {
    char *entries[75];
} StaticDisplayStrings;

typedef struct {
    u8 unk0[8];
    u32 flags;
} DisplayState;

void fn_1_14F46C(DisplayState *state) {
    StaticDisplayStrings strings;
    char buffer0[32];
    char buffer1[32];
    char buffer2[32];
    char *data;
    s16 entry;
    s16 i;
    s16 j;

    data = (((char *)&lbl_1_data_43E78));
    strings = *(StaticDisplayStrings *)lbl_1_rodata_CB98;

    entry = 0;
    while ((u32)entry < 3) {
        s16 index;
        char *string;
        s16 i;

        index = ((s16 *)state)[entry];
        string = strings.entries[index];
        i = 0;
        while (i < strlen(string)) {
            u8 *p = (u8 *)strings.entries[index];
            int c = p[i];
            if (c == -1) {
                c = -1;
            } else {
                c = lbl_8015B200[c];
            }
            p[i] = c;
            i++;
        }

        sprintf(buffer1, data + 0x24c4, strings.entries[index]);
        fn_1_465D0(buffer1, 1);

        j = 0;
        while (j < 4) {
            if (state->flags & (1 << j)) {
                if (j == 0) {
                    sprintf(buffer0, data + 0x1338, strings.entries[index]);
                } else {
                    sprintf(buffer0, data + 0x1348, strings.entries[index], j + 1);
                }
                fn_1_465D0(buffer0, 1);
            }
            j++;
        }

        sprintf(buffer2, data + 0x135c, strings.entries[index]);
        fn_1_465D0(buffer2, 1);
        entry++;
    }
}
/* fzgx:end fn_1_14F46C */

/* fzgx:begin fn_1_14F608 */

// Index of the first table entry matching value, or -1 when absent.
static inline s16 find_ordinal(void *table, s16 value) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            return index;
        }
    }
    return -1;
}

u8 *fn_1_14F608(void *arg0) {
    u8 *base;
    void *table;

    table = fn_1_14F344(arg0);

    switch ((s16)table) {
    case 0:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 1:
        base = (u8 *)0x23803098; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 2:
        base = (u8 *)0x2380422C; /* fzgx-allow: A2 table base literal matches retail */
        break;
    default:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    }

    return base + find_ordinal(table, (s16)arg0) * 0xb4;
}
/* fzgx:end fn_1_14F608 */

/* fzgx:begin fn_1_14F6F8 */
#pragma section code_type ".fzgxpool"
static const u32 fn_1_14F6F8_fzgx_pool_table1[150] = {0x80000000, 0x10000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x00000000, 0x80000000, 0x10000000, 0x60000000, 0x80000000, 0x90000000, 0x00000000, 0x20000000, 0x20000000, 0x80000000, 0x80000000, 0x10000000, 0x00000000, 0x20000000, 0x20000000, 0x80000000, 0x90000000, 0x00000000, 0x00000000, 0x80000000, 0x10000000, 0x80000000, 0x00000000, 0x80000000, 0x80000000, 0x80000000, 0x20000000, 0x80000000, 0x60000000, 0x80000000, 0x00000000, 0x20000000, 0x10000000, 0x00000000, 0x80000000, 0x00000000, 0x80000000, 0x80000000, 0x10000000, 0x20000000, 0x90000000, 0x00000000, 0x90000000, 0x20000000, 0x80000009, 0x8000001A, 0x10000002, 0x60000001, 0x00000018, 0x8000000A, 0x80000002, 0x90000003, 0x0000000A, 0x8000000B, 0x0000001B, 0x20000010, 0x90000002, 0x80000013, 0x2000001A, 0x0000000B, 0x80000019, 0x20000000, 0x8000001B, 0x20000011, 0x10000012, 0x80000008, 0x80000012, 0x10000003, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_14F6F8_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_14F6F8_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_14F6F8_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const u32 fn_1_14F6F8_fzgx_pool_table3[1831] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00070008, 0x80000000, 0x00010000, 0x00000000, 0x0009000F, 0x10000000, 0x00020000, 0x00000000, 0x00030008, 0x80000000, 0x00030000, 0x00000000, 0x00010008, 0x80000000, 0x00040000, 0x00000000, 0x00090008, 0x80000000, 0x00050000, 0x00000000, 0x00030008, 0x80000000, 0x00060000, 0x00000000, 0x00030004, 0x00000000, 0x00070000, 0x00000000, 0x00050008, 0x80000000, 0x00080000, 0x00000000, 0x0005000F, 0x10000000, 0x00090000, 0x00000000, 0x00070063, 0x60000000, 0x000A0000, 0x00000000, 0x00070008, 0x80000000, 0x000B0000, 0x00000000, 0x0003000F, 0x90000000, 0x000C0000, 0x00000000, 0x00010005, 0x00000000, 0x000D0000, 0x00000000, 0x00010005, 0x20000000, 0x000E0000, 0x00000000, 0x00030003, 0x20000000, 0x000F0000, 0x00000000, 0x00010008, 0x80000000, 0x00100000, 0x00000000, 0x00050008, 0x80000000, 0x00110000, 0x00000000, 0x0007000F, 0x10000000, 0x00120000, 0x00000000, 0x00050005, 0x00000000, 0x00130000, 0x00000000, 0x00050004, 0x20000000, 0x00140000, 0x00000000, 0x00050004, 0x20000000, 0x00150000, 0x00000000, 0x00050008, 0x80000000, 0x00160000, 0x00000000, 0x0003000F, 0x90000000, 0x00170000, 0x00000000, 0x0009000A, 0x00000000, 0x00180000, 0x00000000, 0x00070007, 0x00000000, 0x00190001, 0x00000000, 0x00070008, 0x80000000, 0x001A0001, 0x00000000, 0x0007000F, 0x10000000, 0x001B0001, 0x00000000, 0x00010008, 0x80000000, 0x001C0001, 0x00000000, 0x00050004, 0x00000000, 0x001D0001, 0x00000000, 0x00050008, 0x80000000, 0x001E0001, 0x00000000, 0x00030008, 0x80000000, 0x001F0001, 0x00000000, 0x00090008, 0x80000000, 0x00200001, 0x00000000, 0x00090003, 0x20000000, 0x00210001, 0x00000000, 0x00030008, 0x80000000, 0x00220001, 0x00000000, 0x00070063, 0x60000000, 0x00230001, 0x00000000, 0x00090008, 0x80000000, 0x00240001, 0x00000000, 0x0001000A, 0x00000000, 0x00250001, 0x00000000, 0x00050004, 0x20000000, 0x00260001, 0x00000000, 0x0003000F, 0x10000000, 0x00270001, 0x00000000, 0x00030005, 0x00000000, 0x00280001, 0x00000000, 0x00070008, 0x80000000, 0x00290001, 0x00000000, 0x00090005, 0x00000000, 0x002A0001, 0x00000000, 0x00050008, 0x80000000, 0x002B0001, 0x00000000, 0x00050008, 0x80000000, 0x002C0001, 0x00000000, 0x0001000F, 0x10000000, 0x002D0001, 0x00000000, 0x00070004, 0x20000000, 0x002E0001, 0x00000000, 0x0001000F, 0x90000000, 0x002F0001, 0x00000000, 0x00050007, 0x00000000, 0x00300001, 0x00000000, 0x0005000F, 0x90000000, 0x00310001, 0x00000000, 0x00030005, 0x20000000, 0x00320002, 0x00000000, 0x00090008, 0x80000009, 0x00330002, 0x00000000, 0x00050008, 0x8000001A, 0x00340002, 0x00000000, 0x0005000F, 0x10000002, 0x00350002, 0x00000000, 0x00090063, 0x60000001, 0x00360002, 0x00000000, 0x00070004, 0x00000018, 0x00370002, 0x00000000, 0x00050008, 0x8000000A, 0x00380002, 0x00000000, 0x00010008, 0x80000002, 0x00390002, 0x00000000, 0x0007000F, 0x90000003, 0x003A0002, 0x00000000, 0x00030005, 0x0000000A, 0x003B0002, 0x00000000, 0x00030008, 0x8000000B, 0x003C0002, 0x00000000, 0x0001000A, 0x0000001B, 0x003D0002, 0x00000000, 0x00050005, 0x20000010, 0x003E0002, 0x00000000, 0x0003000F, 0x90000002, 0x003F0002, 0x00000000, 0x00030008, 0x80000013, 0x00400002, 0x00000000, 0x00050004, 0x2000001A, 0x00410002, 0x00000000, 0x00030005, 0x0000000B, 0x00420002, 0x00000000, 0x00070008, 0x80000019, 0x00430002, 0x00000000, 0x00070003, 0x20000000, 0x00440002, 0x00000000, 0x00030008, 0x8000001B, 0x00450002, 0x00000000, 0x00050004, 0x20000011, 0x00460002, 0x00000000, 0x0001000F, 0x10000012, 0x00470002, 0x00000000, 0x00070008, 0x80000008, 0x00480002, 0x00000000, 0x00050008, 0x80000012, 0x00490002, 0x00000000, 0x0007000F, 0x10000003, 0x004A0002, 0x00000000, 0x00010007, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_14F6F8_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_14F6F8_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_14F6F8_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table5[1275] = {0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
    s = 1200.0f;
    s = 0.00022222222469281405f;
    s = 0.0002142857265425846f;
    s = 0.0f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table7[1] = {0x00000434};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"



static inline s16 find_ordinal_1_14F6F8(void *table, s16 value) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            return index;
        }
    }
    return -1;
}

static inline s16 ordinal_via_1_14F6F8(void *table, s16 value) {
    return find_ordinal_1_14F6F8(table, value);
}

static inline u8 *select_entry_1_14F6F8(void *key) {
    u8 *base;
    void *table;

    table = fn_1_14F344(key);

    switch ((s16)table) {
    case 0:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 1:
        base = (u8 *)0x23803098; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 2:
        base = (u8 *)0x2380422C; /* fzgx-allow: A2 table base literal matches retail */
        break;
    default:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    }

    return base + find_ordinal_1_14F6F8(table, (s16)key) * 0xb4;
}

// Blends three static display entries into one output record.
void *fn_1_14F6F8(void *arg0, void *arg1, void *arg2, DispEntry *out) {
    DispEntry *x = (DispEntry *)select_entry_1_14F6F8(arg0);
    DispEntry *y = (DispEntry *)select_entry_1_14F6F8(arg1);
    DispEntry *z;
    void *t3;
    u8 *b3;
    f32 blend;
    s32 i;
    s32 delta;
    f32 rate;

    t3 = fn_1_14F344(arg2);
    switch ((s16)t3) {
    case 0:
        b3 = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 1:
        b3 = (u8 *)0x23803098; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 2:
        b3 = (u8 *)0x2380422C; /* fzgx-allow: A2 table base literal matches retail */
        break;
    default:
        b3 = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    }
    z = (DispEntry *)(b3 + ordinal_via_1_14F6F8(t3, (s16)arg2) * 0xb4);
    delta = x->kind[3] - y->kind[3];
    rate = delta;
    rate /= 8.0f;

    out->kind = (((u8 *)&lbl_1_data_4634C));
    out->f04 = x->f04 + y->f04 + z->f04;

    blend = out->f04;
    blend -= 1200.0f;
    if (blend > 0.0f) {
        blend *= 0.00022222222469281405f;
    } else {
        blend *= 0.0002142857265425846f;
    }
    blend += 1.0f;

    out->f08 = x->f08 + y->f08 + z->f08;
    out->f0C = x->f0C + y->f0C + z->f0C;
    out->f1C = x->f1C + y->f1C + z->f1C;
    out->f18 = x->f18 + y->f18 + z->f18;
    {
        f32 adjust = 0.30000001192092896f * out->f18 * rate;
        out->f18 += adjust;
    }
    out->f20 = x->f20 + y->f20 + z->f20;
    {
        f32 adjust = 0.30000001192092896f * out->f20 * rate;
        out->f20 -= adjust;
    }
    out->f24 = x->f24 + y->f24 + z->f24;
    out->f28 = x->f28 + y->f28 + z->f28;
    out->f2C = x->f2C + y->f2C + z->f2C;
    out->f30 = x->f30 + y->f30 + z->f30;
    out->f34 = (x->f34 + y->f34 + z->f34) * blend;
    out->f38 = x->f38 + y->f38 + z->f38;
    out->f3C = x->f3C + y->f3C + z->f3C;
    out->f40 = x->f40 + y->f40 + z->f40;
    out->f44 = x->f44 * y->f44;
    out->b48 = x->b48 + y->b48 + z->b48;

    {
        f32 scaled = x->f10 * rate;
        out->f10 = x->f10 + scaled;
    }
    {
        f32 scaled = x->f14 * rate;
        out->f14 = x->f14 + scaled;
    }

    out->f4C = y->f4C;
    out->f50 = y->f50;
    out->b49 = x->b49 | y->b49 | z->b49;

    for (i = 0; i < 4; i++) {
        out->tail[i] = x->tail[i];
        out->tail[i + 4] = x->tail[i + 4];
    }

    return out;
}
/* fzgx:end fn_1_14F6F8 */

/* fzgx:begin fn_1_14FC80 */

void fn_1_14FC80(s16 arg0, u32 arg1) {
    u8 *data;

    data = (u8 *)fn_1_36AD0(arg0, arg1) + arg0 * 0x81C0;
    fn_1_14F6F8( (void *)(u8)(data[0x81A4]), (void *)(u8)(data[0x81AC]), (void *)(u8)(data[0x81B4]), (DispEntry *)(u32)(arg1));
}
/* fzgx:end fn_1_14FC80 */

/* fzgx:begin fn_1_14FCE4 */
typedef struct {
    u32 words[77];
} Data;

void fn_1_14FCE4(u32 arg0, s16 arg1) {
    Data data;

    data = *(Data *)lbl_1_rodata_CCDC;
    fn_1_14FD7C(data.words, 77);
    fn_80008BA8( (void *)(u32)(arg0), (void *)((u32)(data.words)), arg1 << 2);
}
/* fzgx:end fn_1_14FCE4 */

/* fzgx:begin fn_1_14FD6C */
s32 fn_1_14FD6C(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}
/* fzgx:end fn_1_14FD6C */

/* fzgx:begin fn_1_14FD7C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_14FD7C(u32 *data, u32 count);

extern void fn_1_14FD6C(void);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);

// Forward a callback and its selector to the dispatch helper.
void fn_1_14FD7C(u32 *arg0, u32 arg1) {
    s16 selector = arg1;
    void (*callback)(void) = fn_1_14FD6C;

    qsort(arg0, selector, 4, callback);
}
/* fzgx:end fn_1_14FD7C */

/* fzgx:begin fn_1_14FDAC noprologue */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);

void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3) {
    u8 local[0x40];
    void *value;
    s16 index;
    void *entry;

    strcpy( (char *)(local), arg0);
    value = local;
    index = 0;
    while ((entry = strtok( value, arg1)) != NULL) {
        if (index == arg2) {
            strcpy( arg3, entry);
            return arg3;
        }
        value = 0;
        index++;
    }
    strcpy( arg3, arg0);
    return arg3;
}
/* fzgx:end fn_1_14FDAC */

/* fzgx:begin fn_1_14FE48 noprologue */
s32 fn_1_14FE48(void *arg0, void *arg1) {
    u8 data[64];
    void *value;
    s32 count;

    strcpy( (char *)(data), arg0);
    value = data;
    count = 0;
    while (strtok( value, arg1) != 0) {
        value = 0;
        count += 1;
    }
    return count;
}
/* fzgx:end fn_1_14FE48 */

/* fzgx:begin fn_1_14FEAC noprologue */
typedef s32 (*Sig_fn_8007E96C_fn_8007E96C_Compare)(u32, u32);

extern u8 lbl_1_bss_8E6B0[308];
extern u16 lbl_1_bss_8E7E4[722];
extern char *fn_1_14EBF8(s16, char *, s16);
extern char *fn_1_14EA74(s16, char *, s16);
extern s32 fn_1_14ED00(s16, char *, s16);
extern u32 fn_8007E96C(u32, u32, u32, u32, Sig_fn_8007E96C_fn_8007E96C_Compare);
extern int sprintf(char *, const char *, ...);

typedef struct {
    s16 id;
    u32 key;
    char str[0x40];
} NameCacheEntry;

typedef struct {
    s16 next;
    NameCacheEntry entries[20];
} NameCache;

typedef struct {
    u32 flags[75];
} NameFlags;

/* The TU's string literals are addressed off one data base in retail; keep each
   base + offset address recomputed at its use instead of CSE'd into a register. */
extern u8 fn_1_14E8A4__fzgx_offset_0[];
extern u8 fn_1_14E8CC__fzgx_offset_0[];
extern u8 fn_1_14E8F4__fzgx_offset_0[];
extern u8 fn_1_14E91C__fzgx_offset_0[];
extern u8 fn_1_14E944__fzgx_offset_0[];
extern u8 fn_1_14E96C__fzgx_offset_0[];
extern u8 fn_1_14E9A8__fzgx_offset_0[];
extern u8 fn_1_14EE00__fzgx_offset_64[];
extern u8 fn_1_14EE00__fzgx_offset_6C[];
extern u8 fn_1_14EE00__fzgx_offset_74[];
extern u8 fn_1_14EE00__fzgx_offset_7C[];
extern u8 fn_1_14EE00__fzgx_offset_84[];
extern u8 fn_1_14EE00__fzgx_offset_88[];
extern u8 lbl_1_data_43E78__fzgx_offset_0[];
extern u8 lbl_1_data_43E84__fzgx_offset_0[];
extern u8 lbl_1_data_43E88__fzgx_offset_0[];
extern u8 lbl_1_data_43E9C__fzgx_offset_0[];
extern u8 lbl_1_data_43EA8__fzgx_offset_0[];
extern u8 lbl_1_data_43EB8__fzgx_offset_0[];
extern u8 lbl_1_data_43EC8__fzgx_offset_0[];
extern u8 lbl_1_data_43EE8__fzgx_offset_0[];
extern u8 lbl_1_data_43EF4__fzgx_offset_0[];
extern u8 lbl_1_data_43F08__fzgx_offset_0[];
extern u8 lbl_1_data_43F18__fzgx_offset_0[];
extern u8 lbl_1_data_43F2C__fzgx_offset_0[];
extern u8 lbl_1_data_43F38__fzgx_offset_0[];
extern u8 lbl_1_data_43F4C__fzgx_offset_0[];
extern u8 lbl_1_data_43F54__fzgx_offset_0[];
extern u8 lbl_1_data_43F64__fzgx_offset_0[];
extern u8 lbl_1_data_43F74__fzgx_offset_0[];
extern u8 lbl_1_data_43F84__fzgx_offset_0[];
extern u8 lbl_1_data_43F90__fzgx_offset_0[];
extern u8 lbl_1_data_43FA0__fzgx_offset_0[];
extern u8 lbl_1_data_43FB0__fzgx_offset_0[];
extern u8 lbl_1_data_43FC8__fzgx_offset_0[];
extern u8 lbl_1_data_43FD8__fzgx_offset_0[];
extern u8 lbl_1_data_43FEC__fzgx_offset_0[];
extern u8 lbl_1_data_43FF8__fzgx_offset_0[];
extern u8 lbl_1_data_44008__fzgx_offset_0[];
extern u8 lbl_1_data_44018__fzgx_offset_0[];
extern u8 lbl_1_data_44030__fzgx_offset_0[];
extern u8 lbl_1_data_44038__fzgx_offset_0[];
extern u8 lbl_1_data_44048__fzgx_offset_0[];
extern u8 lbl_1_data_44054__fzgx_offset_0[];
extern u8 lbl_1_data_44064__fzgx_offset_0[];
extern u8 lbl_1_data_44070__fzgx_offset_0[];
extern u8 lbl_1_data_44084__fzgx_offset_0[];
extern u8 lbl_1_data_44090__fzgx_offset_0[];
extern u8 lbl_1_data_440A4__fzgx_offset_0[];
extern u8 lbl_1_data_440B0__fzgx_offset_0[];
extern u8 lbl_1_data_440C0__fzgx_offset_0[];
extern u8 lbl_1_data_440CC__fzgx_offset_0[];
extern u8 lbl_1_data_440DC__fzgx_offset_0[];
extern u8 lbl_1_data_440EC__fzgx_offset_0[];
extern u8 lbl_1_data_44100__fzgx_offset_0[];
extern u8 lbl_1_data_4410C__fzgx_offset_0[];
extern u8 lbl_1_data_44120__fzgx_offset_0[];
extern u8 lbl_1_data_4412C__fzgx_offset_0[];
extern u8 lbl_1_data_44138__fzgx_offset_0[];
extern u8 lbl_1_data_44144__fzgx_offset_0[];
extern u8 lbl_1_data_44154__fzgx_offset_0[];
extern u8 lbl_1_data_44160__fzgx_offset_0[];
extern u8 lbl_1_data_44170__fzgx_offset_0[];
extern u8 lbl_1_data_4417C__fzgx_offset_0[];
extern u8 lbl_1_data_4418C__fzgx_offset_0[];
extern u8 lbl_1_data_4419C__fzgx_offset_0[];
extern u8 lbl_1_data_441AC__fzgx_offset_0[];
extern u8 lbl_1_data_441B8__fzgx_offset_0[];
extern u8 lbl_1_data_441D0__fzgx_offset_0[];
extern u8 lbl_1_data_441DC__fzgx_offset_0[];
extern u8 lbl_1_data_441EC__fzgx_offset_0[];
extern u8 lbl_1_data_441F8__fzgx_offset_0[];
extern u8 lbl_1_data_4420C__fzgx_offset_0[];
extern u8 lbl_1_data_44220__fzgx_offset_0[];
extern u8 lbl_1_data_4423C__fzgx_offset_0[];
extern u8 lbl_1_data_44244__fzgx_offset_0[];
extern u8 lbl_1_data_44250__fzgx_offset_0[];
extern u8 lbl_1_data_44260__fzgx_offset_0[];
extern u8 lbl_1_data_44270__fzgx_offset_0[];
extern u8 lbl_1_data_4427C__fzgx_offset_0[];
extern u8 lbl_1_data_44290__fzgx_offset_0[];
extern u8 lbl_1_data_4429C__fzgx_offset_0[];
extern u8 lbl_1_data_442AC__fzgx_offset_0[];
extern u8 lbl_1_data_442BC__fzgx_offset_0[];
extern u8 lbl_1_data_442D0__fzgx_offset_0[];
extern u8 lbl_1_data_442E0__fzgx_offset_0[];
extern u8 lbl_1_data_442F4__fzgx_offset_0[];
extern u8 lbl_1_data_44304__fzgx_offset_0[];
extern u8 lbl_1_data_4431C__fzgx_offset_0[];
extern u8 lbl_1_data_44328__fzgx_offset_0[];
extern u8 lbl_1_data_4433C__fzgx_offset_0[];
extern u8 lbl_1_data_4434C__fzgx_offset_0[];
extern u8 lbl_1_data_44360__fzgx_offset_0[];
extern u8 lbl_1_data_4436C__fzgx_offset_0[];
extern u8 lbl_1_data_44378__fzgx_offset_0[];
extern u8 lbl_1_data_44384__fzgx_offset_0[];
extern u8 lbl_1_data_44394__fzgx_offset_0[];
extern u8 lbl_1_data_443A4__fzgx_offset_0[];
extern u8 lbl_1_data_443B8__fzgx_offset_0[];
extern u8 lbl_1_data_443C8__fzgx_offset_0[];
extern u8 lbl_1_data_443DC__fzgx_offset_0[];
extern u8 lbl_1_data_443EC__fzgx_offset_0[];
extern u8 lbl_1_data_44400__fzgx_offset_0[];
extern u8 lbl_1_data_44410__fzgx_offset_0[];
extern u8 lbl_1_data_44424__fzgx_offset_0[];
extern u8 lbl_1_data_44430__fzgx_offset_0[];
extern u8 lbl_1_data_44444__fzgx_offset_0[];
extern u8 lbl_1_data_44450__fzgx_offset_0[];
extern u8 lbl_1_data_4445C__fzgx_offset_0[];
extern u8 lbl_1_data_44468__fzgx_offset_0[];
extern u8 lbl_1_data_44478__fzgx_offset_0[];
extern u8 lbl_1_data_4448C__fzgx_offset_0[];
extern u8 lbl_1_data_444AC__fzgx_offset_0[];
extern u8 lbl_1_data_444BC__fzgx_offset_0[];
extern u8 lbl_1_data_444D0__fzgx_offset_0[];
extern u8 lbl_1_data_444DC__fzgx_offset_0[];
extern u8 lbl_1_data_444F0__fzgx_offset_0[];
extern u8 lbl_1_data_444F8__fzgx_offset_0[];
extern u8 lbl_1_data_44504__fzgx_offset_0[];
extern u8 lbl_1_data_44510__fzgx_offset_0[];
extern u8 lbl_1_data_44520__fzgx_offset_0[];
extern u8 lbl_1_data_4452C__fzgx_offset_0[];
extern u8 lbl_1_data_4453C__fzgx_offset_0[];
extern u8 lbl_1_data_44548__fzgx_offset_0[];
extern u8 lbl_1_data_44558__fzgx_offset_0[];
extern u8 lbl_1_data_44568__fzgx_offset_0[];
extern u8 lbl_1_data_4457C__fzgx_offset_0[];
extern u8 lbl_1_data_4458C__fzgx_offset_0[];
extern u8 lbl_1_data_445A8__fzgx_offset_0[];
extern u8 lbl_1_data_445B8__fzgx_offset_0[];
extern u8 lbl_1_data_445CC__fzgx_offset_0[];
extern u8 lbl_1_data_445D8__fzgx_offset_0[];
extern u8 lbl_1_data_445E8__fzgx_offset_0[];
extern u8 lbl_1_data_445F4__fzgx_offset_0[];
extern u8 lbl_1_data_44608__fzgx_offset_0[];
extern u8 lbl_1_data_44614__fzgx_offset_0[];
extern u8 lbl_1_data_44624__fzgx_offset_0[];
extern u8 lbl_1_data_44630__fzgx_offset_0[];
extern u8 lbl_1_data_44640__fzgx_offset_0[];
extern u8 lbl_1_data_44650__fzgx_offset_0[];
extern u8 lbl_1_data_44664__fzgx_offset_0[];
extern u8 lbl_1_data_44670__fzgx_offset_0[];
extern u8 lbl_1_data_44684__fzgx_offset_0[];
extern u8 lbl_1_data_44690__fzgx_offset_0[];
extern u8 lbl_1_data_446A0__fzgx_offset_0[];
extern u8 lbl_1_data_446B0__fzgx_offset_0[];
extern u8 lbl_1_data_446C8__fzgx_offset_0[];
extern u8 lbl_1_data_446D8__fzgx_offset_0[];
extern u8 lbl_1_data_446EC__fzgx_offset_0[];
extern u8 lbl_1_data_446F8__fzgx_offset_0[];
extern u8 lbl_1_data_44708__fzgx_offset_0[];
extern u8 lbl_1_data_44714__fzgx_offset_0[];
extern u8 lbl_1_data_44728__fzgx_offset_0[];
extern u8 lbl_1_data_44738__fzgx_offset_0[];
extern u8 lbl_1_data_44750__fzgx_offset_0[];
extern u8 lbl_1_data_4475C__fzgx_offset_0[];
extern u8 lbl_1_data_4476C__fzgx_offset_0[];
extern u8 lbl_1_data_44778__fzgx_offset_0[];
extern u8 lbl_1_data_44788__fzgx_offset_0[];
extern u8 lbl_1_data_44794__fzgx_offset_0[];
extern u8 lbl_1_data_447A8__fzgx_offset_0[];
extern u8 lbl_1_data_447B0__fzgx_offset_0[];
extern u8 lbl_1_data_447BC__fzgx_offset_0[];
extern u8 lbl_1_data_447C8__fzgx_offset_0[];
extern u8 lbl_1_data_447DC__fzgx_offset_0[];
extern u8 lbl_1_data_447E8__fzgx_offset_0[];
extern u8 lbl_1_data_447FC__fzgx_offset_0[];
extern u8 lbl_1_data_44808__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_43E78[616] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x476C6164, 0x6961746F, 0x72000000, 0x0, 0x834F8389, 0x83668342, 0x8347815B, 0x835E815B,
    0x0, 0x4A616262, 0x6572776F, 0x636B0000, 0x83578383, 0x836F8345, 0x83488362, 0x834E0000,
    0x46696E61, 0x6C204576, 0x6F6C7574, 0x696F6E00, 0x83748340, 0x83438369, 0x838B8140, 0x8347837B,
    0x838A8385, 0x815B8356, 0x83878393, 0x0, 0x53757065, 0x72204E6F, 0x76610000, 0x8358815B,  /* fzgx-allow: A1 retail data bytes */
    0x8370815B, 0x8140836D, 0x83948340, 0x0, 0x53617465, 0x6C6C6974, 0x65204F72, 0x62000000,  /* fzgx-allow: A1 retail data bytes */
    0x83548365, 0x83898343, 0x83672083, 0x49815B83, 0x75000000, 0x48617264, 0x2042616E, 0x67657200,
    0x836E815B, 0x83688140, 0x836F8393, 0x834B815B, 0x0, 0x42696720, 0x41636500, 0x83728362,
    0x834F8140, 0x8347815B, 0x83580000, 0x48697070, 0x6F706F74, 0x616D7573, 0x0, 0x8371837C,
    0x8370835E, 0x837D8358, 0x0, 0x446F6E20, 0x51756978, 0x6F746500, 0x83688393, 0x8140834C,  /* fzgx-allow: A1 retail data bytes */
    0x837A815B, 0x83650000, 0x52656420, 0x53616C61, 0x6D616E64, 0x65720000, 0x838C8362, 0x83688140,
    0x83548389, 0x837D8393, 0x835F815B, 0x0, 0x51756565, 0x6E205361, 0x70706869, 0x72650000,
    0x834E8343, 0x815B8393, 0x20835483, 0x74834083, 0x43834100, 0x43656E74, 0x61757275, 0x73000000,  /* fzgx-allow: A1 retail data bytes */
    0x83508393, 0x835E8345, 0x838B8358, 0x0, 0x4772616E, 0x6420456C, 0x65706861, 0x6E740000,
    0x834F8389, 0x83938368, 0x20834783, 0x8C837483, 0x40839383, 0x67000000, 0x54726975, 0x6D706800,
    0x83678389, 0x83438341, 0x83938374, 0x0, 0x53636F72, 0x63686572, 0x0, 0x83588352,
    0x83628360, 0x8383815B, 0x0, 0x426C7565, 0x20537472, 0x65616B00, 0x8375838B, 0x815B8358,  /* fzgx-allow: A1 retail data bytes */
    0x81408367, 0x838A815B, 0x834E0000, 0x57686974, 0x65205379, 0x6C706800, 0x837A838F, 0x83438367,  /* fzgx-allow: A1 retail data bytes */
    0x81408356, 0x838B8374, 0x0, 0x43617262, 0x756E636C, 0x65000000, 0x834A815B, 0x836F8393,  /* fzgx-allow: A1 retail data bytes */
    0x834E838B, 0x0, 0x506C6569, 0x61646573, 0x0, 0x8376838C, 0x83418366, 0x8342815B,
    0x83590000, 0x4368726F, 0x6E6F2053, 0x796D7068, 0x6F6E7900, 0x834E838D, 0x836D2083, 0x56839383,
    0x74834883, 0x6A815B00, 0x49636172, 0x75732057, 0x696E6700, 0x8343834A, 0x838D8358, 0x20834583,
    0x43839383, 0x4F000000, 0x47617267, 0x6F796C65, 0x0, 0x834B815B, 0x83538343, 0x838B0000,
    0x4F757420, 0x52696465, 0x72000000, 0x83418345, 0x83678389, 0x8343835F, 0x815B0000, 0x4C696265,  /* fzgx-allow: A1 retail data bytes */
    0x7261746F, 0x72000000, 0x838A8378, 0x838C8343, 0x835E815B, 0x0, 0x54726963, 0x6B737465,
    0x72000000, 0x8367838A, 0x8362834E, 0x8358835E, 0x815B0000, 0x53617661, 0x6E6E6120, 0x42756767,  /* fzgx-allow: A1 retail data bytes */
    0x79000000, 0x8354836F, 0x83938369, 0x20836F83, 0x4D815B00, 0x426C7565, 0x20556E64, 0x696E6500,
    0x8375838B, 0x815B8140, 0x83458393, 0x83668342, 0x815B836C, 0x0, 0x56616C6B, 0x79726965,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83948340, 0x838B834C, 0x838A815B, 0x0, 0x466F7274, 0x69737369, 0x6D6F0000,
    0x83748348, 0x838B8365, 0x83428362, 0x83568382, 0x0, 0x42697264, 0x204F6620, 0x50617261,
    0x64697365, 0x0, 0x836F815B, 0x83688140, 0x83498375, 0x81408370, 0x8389835F, 0x83438358,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x42616861, 0x6D757400, 0x836F836E, 0x8380815B, 0x83670000, 0x536F7574, 0x6865726E,
    0x2043726F, 0x73730000, 0x83548355, 0x83938140, 0x834E838D, 0x83580000, 0x536F636B, 0x646F6C61,
    0x67657200, 0x835C8362, 0x834E8368, 0x838C8343, 0x834B815B, 0x0, 0x48696768, 0x20526F6C,
    0x6C657200, 0x836E8343, 0x20838D81, 0x5B838981, 0x5B000000, 0x5374726F, 0x6E672047, 0x75737461,
    0x76000000, 0x83588367, 0x838D8393, 0x834F2083, 0x4F835883, 0x5E837400, 0x44657365, 0x72742043,
    0x616D656C, 0x0, 0x83668355, 0x815B8367, 0x8140834C, 0x83838381, 0x838B0000, 0x4D616D6D,  /* fzgx-allow: A1 retail data bytes */
    0x6F746820, 0x496D7061, 0x63740000, 0x837D8393, 0x83828358, 0x81408343, 0x83938370, 0x834E8367,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x43757269, 0x6F205269, 0x64657200, 0x834E838A, 0x83498140, 0x83898343, 0x835F815B,
    0x0, 0x4D757363, 0x6C652045, 0x6D707265, 0x73730000, 0x837D8362, 0x8358838B, 0x20834783,
    0x93837683, 0x8C835800, 0x4E696768, 0x746D6172, 0x65000000, 0x83698343, 0x83678381, 0x83410000,
    0x416C6D61, 0x67657374, 0x0, 0x8341838B, 0x837D8351, 0x83588367, 0x0, 0x4B696E67,
    0x204E6570, 0x74756E65, 0x0, 0x834C8393, 0x834F2083, 0x6C837683, 0x60838581, 0x5B839300,
    0x42616E64, 0x6572736E, 0x61746368, 0x0, 0x836F8393, 0x835F815B, 0x83588369, 0x83628360,
    0x0, 0x42656174, 0x20546865, 0x20426561, 0x73740000, 0x8372815B, 0x83672083, 0x55208372,
    0x815B8358, 0x83670000, 0x4C696265, 0x72747920, 0x54726974, 0x6F6E0000, 0x838A836F, 0x83658342,  /* fzgx-allow: A1 retail data bytes */
    0x20836783, 0x8A836783, 0x93000000, 0x46697265, 0x2042616C, 0x6C000000, 0x83748340, 0x83438341,
    0x815B8140, 0x837B815B, 0x838B0000, 0x506F7365, 0x69646F6E, 0x0, 0x837C835A, 0x83438368,  /* fzgx-allow: A1 retail data bytes */
    0x83930000, 0x4C657669, 0x61746861, 0x6E000000, 0x838A836F, 0x83438341, 0x83548393, 0x0,
    0x46696E61, 0x6C205265, 0x766F6C75, 0x74696F6E, 0x0, 0x83748340, 0x83438369, 0x838B8140,
    0x838C837B, 0x838A8385, 0x815B8356, 0x83878393, 0x0, 0x4E6F746F, 0x72696F75, 0x73204765,  /* fzgx-allow: A1 retail data bytes */
    0x61720000, 0x836D815B, 0x8367838A, 0x83418358, 0x8140834D, 0x83410000, 0x54726169, 0x6C626C61,  /* fzgx-allow: A1 retail data bytes */
    0x7A657200, 0x8367838C, 0x8343838B, 0x8375838C, 0x83438355, 0x815B0000, 0x456E6967, 0x6D610000,  /* fzgx-allow: A1 retail data bytes */
    0x8347836A, 0x834F837D, 0x0, 0x416C6578, 0x616E6465, 0x72000000, 0x8341838C, 0x834E8354,
    0x8393835F, 0x815B0000, 0x45786361, 0x6C696275, 0x72000000, 0x8347834E, 0x8358834A, 0x838A836F,  /* fzgx-allow: A1 retail data bytes */
    0x815B0000, 0x4865726D, 0x65732053, 0x74617200, 0x8377838B, 0x83818358, 0x20835883, 0x5E815B00,  /* fzgx-allow: A1 retail data bytes */
    0x5468756E, 0x64657220, 0x53746F72, 0x6D000000, 0x83548393, 0x835F815B, 0x81408358, 0x8367815B,  /* fzgx-allow: A1 retail data bytes */
    0x83800000, 0x4372617A, 0x79204D69, 0x6E6F7461, 0x75720000, 0x834E838C, 0x83438357, 0x815B8140,  /* fzgx-allow: A1 retail data bytes */
    0x837E836D, 0x835E8345, 0x83898358, 0x0, 0x4B616C65, 0x69646F73, 0x636F7065, 0x0,
    0x834A838C, 0x83438368, 0x83588352, 0x815B8376, 0x0, 0x456C696D, 0x696E6174, 0x6F720000,  /* fzgx-allow: A1 retail data bytes */
    0x8347838A, 0x837E836C, 0x8343835E, 0x815B0000, 0x4C6F6E67, 0x2053686F, 0x74000000, 0x838D8393,  /* fzgx-allow: A1 retail data bytes */
    0x834F8140, 0x83568387, 0x83628367, 0x0, 0x53616C76, 0x6174696F, 0x6E000000, 0x8354838B,
    0x83788343, 0x83568387, 0x83930000, 0x536C6569, 0x706E6972, 0x0, 0x8358838C, 0x83438376,
    0x836A838B, 0x0, 0x456D6572, 0x616C6420, 0x50656761, 0x73757300, 0x83478381, 0x8389838B,
    0x83682083, 0x79834B83, 0x54835800, 0x4D617374, 0x65722057, 0x6F726B00, 0x837D8358, 0x835E815B,
    0x8140838F, 0x815B834E, 0x0, 0x56616E20, 0x47756172, 0x64000000, 0x83948340, 0x83938140,  /* fzgx-allow: A1 retail data bytes */
    0x834B815B, 0x83680000, 0x53706C61, 0x7368204D, 0x65726D61, 0x69640000, 0x83588376, 0x83898362,
    0x83568385, 0x20837D81, 0x5B838183, 0x43836800, 0x41717561, 0x20477269, 0x6666696E, 0x0,
    0x8341834E, 0x83418140, 0x834F838A, 0x83748342, 0x83930000, 0x54757262, 0x756C656E, 0x63650000,
    0x835E815B, 0x83728385, 0x83898393, 0x83580000, 0x4865726D, 0x69742043, 0x72616200, 0x836E815B,
    0x837E8362, 0x83672083, 0x4E838983, 0x75000000, 0x41737472, 0x6F205363, 0x6F727069, 0x6F6E0000,
    0x83418358, 0x8367838D, 0x81408358, 0x8352815B, 0x83738349, 0x83930000, 0x50726F6D, 0x696E656E,  /* fzgx-allow: A1 retail data bytes */
    0x63650000, 0x8376838D, 0x837E836C, 0x83938358, 0x0, 0x456C2044, 0x6F726164, 0x6F000000,
    0x8347838B, 0x20836883, 0x89815B83, 0x68000000, 0x50617065, 0x72204372, 0x61667400, 0x8379815B,
    0x8370815B, 0x8140834E, 0x83898374, 0x83670000, 0x44726167, 0x6F6F6E00, 0x83688389, 0x834F815B,  /* fzgx-allow: A1 retail data bytes */
    0x83930000, 0x4A756E6B, 0x20526964, 0x65720000, 0x83578383, 0x8393834E, 0x81408389, 0x8343835F,  /* fzgx-allow: A1 retail data bytes */
    0x815B0000, 0x47726F75, 0x6E642057, 0x61766500, 0x834F8389, 0x83938368, 0x81408345, 0x83468343,  /* fzgx-allow: A1 retail data bytes */
    0x83750000, 0x46616E74, 0x61736973, 0x74610000, 0x83748340, 0x8393835E, 0x83578358, 0x835E0000
};
static u32 fzgx_pool_data_lbl_1_data_43E78_9A0[464] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_43E78__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E88__fzgx_offset_0, (u32)lbl_1_data_43E9C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43EA8__fzgx_offset_0, (u32)lbl_1_data_43EB8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43EC8__fzgx_offset_0, (u32)lbl_1_data_43EE8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43EF4__fzgx_offset_0,
    (u32)lbl_1_data_43F08__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F18__fzgx_offset_0, (u32)lbl_1_data_43F2C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F38__fzgx_offset_0, (u32)lbl_1_data_43F4C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F54__fzgx_offset_0, (u32)lbl_1_data_43F64__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F74__fzgx_offset_0,
    (u32)lbl_1_data_43F84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F90__fzgx_offset_0, (u32)lbl_1_data_43FA0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43FB0__fzgx_offset_0, (u32)lbl_1_data_43FC8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43FD8__fzgx_offset_0, (u32)lbl_1_data_43FEC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43FF8__fzgx_offset_0,
    (u32)lbl_1_data_44008__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44018__fzgx_offset_0, (u32)lbl_1_data_44030__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44038__fzgx_offset_0, (u32)lbl_1_data_44048__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44054__fzgx_offset_0, (u32)lbl_1_data_44064__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44070__fzgx_offset_0,
    (u32)lbl_1_data_44084__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44090__fzgx_offset_0, (u32)lbl_1_data_440A4__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_440B0__fzgx_offset_0, (u32)lbl_1_data_440C0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_440CC__fzgx_offset_0, (u32)lbl_1_data_440DC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_440EC__fzgx_offset_0,
    (u32)lbl_1_data_44100__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4410C__fzgx_offset_0, (u32)lbl_1_data_44120__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4412C__fzgx_offset_0, (u32)lbl_1_data_44138__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44144__fzgx_offset_0, (u32)lbl_1_data_44154__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44160__fzgx_offset_0,
    (u32)lbl_1_data_44170__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4417C__fzgx_offset_0, (u32)lbl_1_data_4418C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4419C__fzgx_offset_0, (u32)lbl_1_data_441AC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_441B8__fzgx_offset_0, (u32)lbl_1_data_441D0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_441DC__fzgx_offset_0,
    (u32)lbl_1_data_441EC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_441F8__fzgx_offset_0, (u32)lbl_1_data_4420C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44220__fzgx_offset_0, (u32)lbl_1_data_4423C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44244__fzgx_offset_0, (u32)lbl_1_data_44250__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44260__fzgx_offset_0,
    (u32)lbl_1_data_44270__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4427C__fzgx_offset_0, (u32)lbl_1_data_44290__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4429C__fzgx_offset_0, (u32)lbl_1_data_442AC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_442BC__fzgx_offset_0, (u32)lbl_1_data_442D0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_442E0__fzgx_offset_0,
    (u32)lbl_1_data_442F4__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44304__fzgx_offset_0, (u32)lbl_1_data_4431C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44328__fzgx_offset_0, (u32)lbl_1_data_4433C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4434C__fzgx_offset_0, (u32)lbl_1_data_44360__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4436C__fzgx_offset_0,
    (u32)lbl_1_data_44378__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44384__fzgx_offset_0, (u32)lbl_1_data_44394__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_443A4__fzgx_offset_0, (u32)lbl_1_data_443B8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_443C8__fzgx_offset_0, (u32)lbl_1_data_443DC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_443EC__fzgx_offset_0,
    (u32)lbl_1_data_44400__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44410__fzgx_offset_0, (u32)lbl_1_data_44424__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44430__fzgx_offset_0, (u32)lbl_1_data_44444__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44450__fzgx_offset_0, (u32)lbl_1_data_4445C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44468__fzgx_offset_0,
    (u32)lbl_1_data_44478__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4448C__fzgx_offset_0, (u32)lbl_1_data_444AC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_444BC__fzgx_offset_0, (u32)lbl_1_data_444D0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_444DC__fzgx_offset_0, (u32)lbl_1_data_444F0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_444F8__fzgx_offset_0,
    (u32)lbl_1_data_44504__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44510__fzgx_offset_0, (u32)lbl_1_data_44520__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4452C__fzgx_offset_0, (u32)lbl_1_data_4453C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44548__fzgx_offset_0, (u32)lbl_1_data_44558__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44568__fzgx_offset_0,
    (u32)lbl_1_data_4457C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4458C__fzgx_offset_0, (u32)lbl_1_data_445A8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_445B8__fzgx_offset_0, (u32)lbl_1_data_445CC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_445D8__fzgx_offset_0, (u32)lbl_1_data_445E8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_445F4__fzgx_offset_0,
    (u32)lbl_1_data_44608__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44614__fzgx_offset_0, (u32)lbl_1_data_44624__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44630__fzgx_offset_0, (u32)lbl_1_data_44640__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44650__fzgx_offset_0, (u32)lbl_1_data_44664__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44670__fzgx_offset_0,
    (u32)lbl_1_data_44684__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44690__fzgx_offset_0, (u32)lbl_1_data_446A0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_446B0__fzgx_offset_0, (u32)lbl_1_data_446C8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_446D8__fzgx_offset_0, (u32)lbl_1_data_446EC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_446F8__fzgx_offset_0,
    (u32)lbl_1_data_44708__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44714__fzgx_offset_0, (u32)lbl_1_data_44728__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44738__fzgx_offset_0, (u32)lbl_1_data_44750__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4475C__fzgx_offset_0, (u32)lbl_1_data_4476C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44778__fzgx_offset_0,
    (u32)lbl_1_data_44788__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44794__fzgx_offset_0, (u32)lbl_1_data_447A8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_447B0__fzgx_offset_0, (u32)lbl_1_data_447BC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_447C8__fzgx_offset_0, (u32)lbl_1_data_447DC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_447E8__fzgx_offset_0,
    (u32)lbl_1_data_447FC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44808__fzgx_offset_0, 0xFFFFFFFF, 0xFFFFFFFF
};
static u32 fzgx_pool_data_lbl_1_data_44F58[1234] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42445930, 0x31000000, 0x42445930, 0x32000000, 0x42445930, 0x33000000, 0x42445930, 0x34000000,
    0x42445930, 0x35000000, 0x42445930, 0x36000000, 0x42445930, 0x37000000, 0x42445930, 0x38000000,
    0x42445930, 0x39000000, 0x42445931, 0x30000000, 0x42445931, 0x31000000, 0x42445931, 0x32000000,
    0x42445931, 0x33000000, 0x42445931, 0x34000000, 0x42445931, 0x35000000, 0x42445931, 0x36000000,
    0x42445931, 0x37000000, 0x42445931, 0x38000000, 0x42445931, 0x39000000, 0x42445932, 0x30000000,
    0x42445932, 0x31000000, 0x42445932, 0x32000000, 0x42445932, 0x33000000, 0x42445932, 0x34000000,
    0x42445932, 0x35000000, 0x43505430, 0x31000000, 0x43505430, 0x32000000, 0x43505430, 0x33000000,
    0x43505430, 0x34000000, 0x43505430, 0x35000000, 0x43505430, 0x36000000, 0x43505430, 0x37000000,
    0x43505430, 0x38000000, 0x43505430, 0x39000000, 0x43505431, 0x30000000, 0x43505431, 0x31000000,
    0x43505431, 0x32000000, 0x43505431, 0x33000000, 0x43505431, 0x34000000, 0x43505431, 0x35000000,
    0x43505431, 0x36000000, 0x43505431, 0x37000000, 0x43505431, 0x38000000, 0x43505431, 0x39000000,
    0x43505432, 0x30000000, 0x43505432, 0x31000000, 0x43505432, 0x32000000, 0x43505432, 0x33000000,
    0x43505432, 0x34000000, 0x43505432, 0x35000000, 0x42535430, 0x31000000, 0x42535430, 0x32000000,
    0x42535430, 0x33000000, 0x42535430, 0x34000000, 0x42535430, 0x35000000, 0x42535430, 0x36000000,
    0x42535430, 0x37000000, 0x42535430, 0x38000000, 0x42535430, 0x39000000, 0x42535431, 0x30000000,
    0x42535431, 0x31000000, 0x42535431, 0x32000000, 0x42535431, 0x33000000, 0x42535431, 0x34000000,
    0x42535431, 0x35000000, 0x42535431, 0x36000000, 0x42535431, 0x37000000, 0x42535431, 0x38000000,
    0x42535431, 0x39000000, 0x42535432, 0x30000000, 0x42535432, 0x31000000, 0x42535432, 0x32000000,
    0x42535432, 0x33000000, 0x42535432, 0x34000000, 0x42535432, 0x35000000, 0x70617274, 0x735F2573,
    0x2E676D61, 0x0, 0x70617274, 0x735F2573, 0x5F302564, 0x2E676D61, 0x0, 0x70617274,
    0x735F2573, 0x2E666D69, 0x0, 0x76656869, 0x636C652F, 0x0, 0x63617263, 0x6D6E7465,
    0x782E7470, 0x6C000000, 0x2E2E0000, 0x76656869, 0x636C655F, 0x70617274, 0x732F0000, (u32)fn_1_14E8A4__fzgx_offset_0,
    (u32)fn_1_14E8CC__fzgx_offset_0, (u32)fn_1_14E8F4__fzgx_offset_0, (u32)fn_1_14E91C__fzgx_offset_0, (u32)fn_1_14E944__fzgx_offset_0, (u32)fn_1_14E96C__fzgx_offset_0, (u32)fn_1_14E9A8__fzgx_offset_0, 0x43000000, 0x83668374,
    0x8348838B, 0x83678F87, 0x0, 0x50000000, 0x837C8343, 0x83938367, 0x8F870000, 0x52500000,
    0x837C8343, 0x83938367, 0x8B748F87, 0x0, 0x90AB945C, 0x8F870000, 0x90AB945C, 0x8B748F87,
    0x0, 0x57000000, 0x83458347, 0x83438367, 0x8F870000, 0x52570000, 0x83458347, 0x83438367,
    0x8B748F87, 0x0, 0x42726176, 0x65204561, 0x676C6520, 0x53747269, 0x6B652043, 0x6F6E646F,
    0x72000000, 0x8375838C, 0x83438375, 0x20834381, 0x5B834F83, 0x8B208358, 0x83678389, 0x8343834E,
    0x20835283, 0x93836883, 0x8B000000, 0x47616C61, 0x78792046, 0x616C636F, 0x6E20436F, 0x736D6F20,
    0x54657263, 0x656C0000, 0x834D8383, 0x8389834E, 0x8356815B, 0x20837483, 0x40838B83, 0x52839320,
    0x83528358, 0x83822083, 0x5E815B83, 0x5A838B00, 0x4769616E, 0x7420506C, 0x616E6574, 0x20436F73,
    0x6D696320, 0x43697263, 0x6C650000, 0x83578383, 0x83438341, 0x83938367, 0x20837683, 0x89836C83,
    0x62836720, 0x83528359, 0x837E8362, 0x834E2083, 0x54815B83, 0x4E838B00, 0x4D656761, 0x6C6F2043,
    0x72756973, 0x65722048, 0x65617679, 0x20427275, 0x69736572, 0x0, 0x8381834B, 0x838D2083,
    0x4E838B81, 0x5B835581, 0x5B208377, 0x8372815B, 0x20837583, 0x8B815B83, 0x55815B00, 0x53706C61,
    0x73682057, 0x68616C65, 0x20466C75, 0x73682047, 0x72616D70, 0x75730000, 0x83588376, 0x83898362,
    0x83568385, 0x20837A83, 0x47815B83, 0x8B208374, 0x83898362, 0x83568385, 0x20834F83, 0x89839383,
    0x70835800, 0x57696C64, 0x20436861, 0x72696F74, 0x20537472, 0x6F6E6720, 0x54616E6B, 0x0,
    0x838F8343, 0x838B8368, 0x20836083, 0x83838A83, 0x49836283, 0x67208358, 0x8367838D, 0x8393834F,
    0x20835E83, 0x93834E00, 0x56616C69, 0x616E7420, 0x4A616775, 0x61722042, 0x65727365, 0x726B2050,
    0x616E7468, 0x65720000, 0x836F838A, 0x83418393, 0x83672083, 0x57838383, 0x4B815B20, 0x836F815B,
    0x8354834E, 0x20837083, 0x93835481, 0x5B000000, 0x486F6C79, 0x20537069, 0x64657220, 0x53616372,
    0x65642047, 0x6C696465, 0x72000000, 0x837A815B, 0x838A815B, 0x20835883, 0x70834383, 0x5F815B20,
    0x835A8343, 0x834E838A, 0x83628368, 0x20834F83, 0x89834383, 0x5F815B00, 0x426C6F6F, 0x64205261,
    0x76656E20, 0x536C6173, 0x68204372, 0x6F770000, 0x83758389, 0x83628368, 0x20838C83, 0x43837583,
    0x93208358, 0x83898362, 0x83568385, 0x20834E83, 0x8D834500, 0x46756E6E, 0x79205377, 0x616C6C6F,
    0x77205072, 0x65747479, 0x20506967, 0x656F6E00, 0x83748340, 0x836A815B, 0x20835883, 0x8F838D81,
    0x5B208376, 0x838A8365, 0x8342815B, 0x20837383, 0x57838783, 0x93000000, 0x4F707469, 0x63616C20,
    0x57696E67, 0x2050686F, 0x746F6E20, 0x426C6164, 0x65000000, 0x83498376, 0x83658342, 0x834A838B,
    0x20834583, 0x42839383, 0x4F208374, 0x83488367, 0x83932083, 0x75838C81, 0x5B836800, 0x4D616420,
    0x42756C6C, 0x20526F77, 0x64792042, 0x6565746C, 0x65000000, 0x837D8362, 0x83682083, 0x75838B20,
    0x83898345, 0x83668342, 0x20837281, 0x5B836783, 0x8B000000, 0x42696720, 0x54797261, 0x6E74204A,
    0x756D626F, 0x20456D70, 0x65726F72, 0x0, 0x83728362, 0x834F2083, 0x5E834383, 0x89839383,
    0x67208357, 0x83838393, 0x837B2083, 0x47839383, 0x79838981, 0x5B000000, 0x4772616E, 0x64204261,
    0x73652047, 0x72656174, 0x2047656E, 0x6572616C, 0x0, 0x834F8389, 0x83938368, 0x20837881,
    0x5B835820, 0x834F838C, 0x815B8367, 0x20835783, 0x46836C83, 0x89838B00, 0x46697265, 0x20576F6C,  /* fzgx-allow: A1 retail data bytes */
    0x66204275, 0x726E696E, 0x6720436F, 0x796F7465, 0x0, 0x83748340, 0x83438384, 0x815B2083,  /* fzgx-allow: A1 retail data bytes */
    0x45838B83, 0x7420836F, 0x815B836A, 0x8393834F, 0x20835283, 0x88815B83, 0x65000000, 0x44726561,  /* fzgx-allow: A1 retail data bytes */
    0x64204861, 0x6D6D6572, 0x2047616C, 0x6C616E74, 0x2047616E, 0x746C6574, 0x0, 0x8368838C,
    0x83628368, 0x20836E83, 0x93837D81, 0x5B20834B, 0x815B8389, 0x83938367, 0x20834B83, 0x93836783,  /* fzgx-allow: A1 retail data bytes */
    0x8C836283, 0x67000000, 0x53696C76, 0x65722053, 0x776F7264, 0x20417263, 0x68204A61, 0x76656C69,
    0x6E000000, 0x8356838B, 0x836F815B, 0x20835C81, 0x5B836820, 0x8341815B, 0x834E2083, 0x57838383,
    0x78838A83, 0x93000000, 0x52616765, 0x204B6E69, 0x67687420, 0x53746F72, 0x6D792042, 0x6F756E63,
    0x65720000, 0x838C8343, 0x83572083, 0x69834383, 0x67208358, 0x8367815B, 0x837E815B, 0x20836F83,
    0x45839383, 0x54815B00, 0x52617069, 0x64204261, 0x7272656C, 0x2053686F, 0x636B204D, 0x61676E75,
    0x6D000000, 0x83898373, 0x83628368, 0x20836F83, 0x8C838B20, 0x83568387, 0x8362834E, 0x20837D83,
    0x4F836983, 0x80000000, 0x536B7920, 0x486F7273, 0x65204163, 0x726F204D, 0x75737461, 0x6E670000,  /* fzgx-allow: A1 retail data bytes */
    0x8358834A, 0x83432083, 0x7A815B83, 0x58208341, 0x834E838D, 0x20838083, 0x58835E83, 0x93834F00,
    0x41717561, 0x20476F6F, 0x73652046, 0x726F7374, 0x20447261, 0x6B650000, 0x8341834E, 0x83412083,
    0x4F815B83, 0x58208374, 0x838D8358, 0x83672083, 0x68838C83, 0x43834E00, 0x53706163, 0x65204361,
    0x6E636572, 0x20417374, 0x726F2043, 0x72616200, 0x83588379, 0x815B8358, 0x20834C83, 0x83839383,  /* fzgx-allow: A1 retail data bytes */
    0x54815B20, 0x83418358, 0x8367838D, 0x20834E83, 0x89837500, 0x4D657461, 0x6C205368, 0x656C6C20,
    0x53746565, 0x6C205475, 0x72746C65, 0x0, 0x8381835E, 0x838B2083, 0x56834683, 0x8B208358,
    0x83658342, 0x815B838B, 0x20835E81, 0x5B836783, 0x8B000000, 0x53706565, 0x64792044, 0x7261676F,  /* fzgx-allow: A1 retail data bytes */
    0x6E205175, 0x69636B20, 0x57797665, 0x726E0000, 0x83588373, 0x815B8366, 0x8342815B, 0x20836883,  /* fzgx-allow: A1 retail data bytes */
    0x89835383, 0x9320834E, 0x83438362, 0x834E2083, 0x8F834383, 0x6F815B83, 0x93000000, 0x4C696265,
    0x72747920, 0x4D616E74, 0x6120466C, 0x79696E67, 0x20537175, 0x69640000, 0x838A836F, 0x83658342,
    0x20837D83, 0x93835E20, 0x83748389, 0x83438393, 0x834F2083, 0x58834E83, 0x43836800, 0x576F6E64,
    0x65722057, 0x6F726D20, 0x4D697261, 0x636C6520, 0x496E7365, 0x63740000, 0x838F8393, 0x835F815B,
    0x20838F81, 0x5B838020, 0x837E8389, 0x834E838B, 0x20834383, 0x93835A83, 0x4E836700, 0x52757368,
    0x20437963, 0x6C6F6E65, 0x20446173, 0x68205477, 0x69737465, 0x72000000, 0x83898362, 0x83568385,
    0x20835483, 0x43834E83, 0x8D839320, 0x835F8362, 0x83568385, 0x20836383, 0x43835883, 0x5E815B00,
    0x436F6D62, 0x61742043, 0x616E6E6F, 0x6E20546F, 0x726E6164, 0x6F204D61, 0x73746572, 0x0,
    0x83528393, 0x836F8362, 0x83672083, 0x4C838383, 0x6D839320, 0x8367838B, 0x836C815B, 0x83682083,
    0x7D835883, 0x5E815B00, 0x4D757363, 0x6C652047, 0x6F72696C, 0x6C612053, 0x70696379, 0x20547573,
    0x6B000000, 0x837D8362, 0x8358838B, 0x20835383, 0x8A838920, 0x83588370, 0x83438356, 0x815B2083,  /* fzgx-allow: A1 retail data bytes */
    0x5E835883, 0x4E000000, 0x43796265, 0x7220466F, 0x78204A65, 0x74205669, 0x78656E00, 0x83548343,
    0x836F815B, 0x20837483, 0x48836283, 0x4E835820, 0x83578346, 0x83628367, 0x20837283, 0x4E835A83,
    0x93000000, 0x48656174, 0x20536E61, 0x6B652046, 0x6C616D65, 0x204C697A, 0x61726400, 0x8371815B,
    0x83672083, 0x58836C81, 0x5B834E20, 0x8374838C, 0x83438380, 0x20838A83, 0x55815B83, 0x68000000,
    0x52617665, 0x20447269, 0x66746572, 0x20416374, 0x69766520, 0x47616D62, 0x6C657200, 0x838C8343,
    0x83752083, 0x68838A83, 0x74835E81, 0x5B208341, 0x834E8365, 0x83428375, 0x20834D83, 0x83839383,
    0x75838981, 0x5B000000, 0x41657269, 0x616C2042, 0x756C6C65, 0x74204169, 0x72205368, 0x6F740000,
    0x83478341, 0x838A8341, 0x838B2083, 0x6F838C83, 0x62836720, 0x83478341, 0x815B2083, 0x56838783,  /* fzgx-allow: A1 retail data bytes */
    0x62836700, 0x53706172, 0x6B204269, 0x72642050, 0x6C61736D, 0x61204B69, 0x74650000, 0x83588370,
    0x815B834E, 0x20836F81, 0x5B836820, 0x83768389, 0x8359837D, 0x20834A83, 0x43836700, 0x426C6173,  /* fzgx-allow: A1 retail data bytes */
    0x74204361, 0x6D656C20, 0x426C617A, 0x65204769, 0x72616666, 0x65000000, 0x83758389, 0x83588367,
    0x20834C83, 0x83838183, 0x8B208375, 0x838C8343, 0x83592083, 0x57838983, 0x74000000, 0x4461726B,
    0x20436861, 0x73657220, 0x53686164, 0x6F772053, 0x6E697065, 0x72000000, 0x835F815B, 0x834E2083,
    0x60834683, 0x43835481, 0x5B208356, 0x83838368, 0x83452083, 0x58836983, 0x43837081, 0x5B000000,
    0x4761726E, 0x65742050, 0x68616E74, 0x6F6D204A, 0x6577656C, 0x204D6972, 0x61676500, 0x834B815B,
    0x836C8362, 0x83672083, 0x74834083, 0x93836783, 0x80208357, 0x83858347, 0x838B2083, 0x7E838981,  /* fzgx-allow: A1 retail data bytes */
    0x5B835783, 0x85000000, 0x42726967, 0x68742053, 0x70656172, 0x20536869, 0x6E696E67, 0x204C616E,
    0x63657200, 0x83758389, 0x83438367, 0x20835883, 0x73834181, 0x5B208356, 0x83838343, 0x836A8393,
    0x834F2083, 0x89839383, 0x54815B00, 0x48797065, 0x72205374, 0x7265616D, 0x20426174, 0x746C6520,
    0x566F7274, 0x65780000, 0x836E8343, 0x8370815B, 0x20835883, 0x67838A81, 0x5B838020, 0x836F8367,
    0x838B2083, 0x7B838B83, 0x65836283, 0x4E835800, 0x53757065, 0x72204C79, 0x6E782055, 0x6C747261,
    0x204C6567, 0x696F6E00, 0x8358815B, 0x8370815B, 0x20838A83, 0x93834E83, 0x58208345, 0x838B8367,
    0x83892083, 0x8C834D83, 0x49839300, 0x43727973, 0x74616C20, 0x45676720, 0x526F7961, 0x6C205269,
    0x64657200, 0x834E838A, 0x8358835E, 0x838B2083, 0x47836283, 0x4F20838D, 0x83438384, 0x838B2083,
    0x89834383, 0x5F815B00, 0x57696E64, 0x79205368, 0x61726B20, 0x536C6173, 0x68205479, 0x70686F6F,
    0x6E000000, 0x83458343, 0x83938366, 0x83422083, 0x56838381, 0x5B834E20, 0x83588389, 0x83628356,
    0x83852083, 0x5E834383, 0x74815B83, 0x93000000, 0x52656420, 0x52657820, 0x4372696D, 0x736F6E20,
    0x4B696E67, 0x0, 0x838C8362, 0x83682083, 0x8C836283, 0x4E835820, 0x834E838A, 0x8380835D,
    0x83932083, 0x4C839383, 0x4F000000, 0x536F6E69, 0x6320536F, 0x6C646965, 0x72204869, 0x67687761,
    0x79204669, 0x67687465, 0x72000000, 0x835C836A, 0x8362834E, 0x20835C83, 0x8B835783, 0x83815B20,
    0x836E8343, 0x83458346, 0x83432083, 0x74834083, 0x43835E81, 0x5B000000, 0x4D617869, 0x6D756D20,
    0x53746172, 0x204F6D65, 0x67612057, 0x697A6172, 0x64000000, 0x837D834C, 0x8356837D, 0x83802083,
    0x58835E81, 0x5B208349, 0x8381834B, 0x20834583, 0x42835581, 0x5B836800, 0x4D6F6F6E, 0x20536E61,
    0x696C204C, 0x756E6172, 0x204C6F62, 0x73746572, 0x0, 0x8380815B, 0x83932083, 0x58836C83,
    0x43838B20, 0x838B8369, 0x815B2083, 0x8D837583, 0x58835E81, 0x5B000000, 0x4372617A, 0x79204275,  /* fzgx-allow: A1 retail data bytes */
    0x6666616C, 0x6F204D69, 0x67687479, 0x20426973, 0x6F6E0000, 0x834E838C, 0x83438357, 0x815B2083,  /* fzgx-allow: A1 retail data bytes */
    0x6F836283, 0x74834083, 0x8D815B20, 0x837D8343, 0x83658342, 0x815B2083, 0x6F834383, 0x5C839300,  /* fzgx-allow: A1 retail data bytes */
    0x53637564, 0x20566970, 0x6572204D, 0x69737479, 0x20536572, 0x70656E74, 0x0, 0x8358834A,
    0x83628368, 0x20836F83, 0x43837081, 0x5B20837E, 0x83588365, 0x83422083, 0x54815B83, 0x79839383,
    0x67000000, 0x526F756E, 0x64204469, 0x736B2046, 0x6C617420, 0x53617563, 0x65720000, 0x83898345,
    0x83938368, 0x20836683, 0x42835883, 0x4E208374, 0x83898362, 0x83672083, 0x5C815B83, 0x54815B00,
    0x456E6572, 0x67792043, 0x72657374, 0x20466576, 0x65722055, 0x6E69636F, 0x726E0000, 0x83478369,
    0x8357815B, 0x20834E83, 0x8C835883, 0x67208374, 0x8342815B, 0x836F815B, 0x20838683, 0x6A835281,
    0x5B839300, 0x4575726F, 0x73202D30, 0x31000000, 0x83478345, 0x838D8358, 0x2D303100, 0x54726961,
    0x6E676C65, 0x202D4754, 0x202D4754, 0x0, 0x83678389, 0x83438341, 0x8393834F, 0x838B2047,
    0x54204754, 0x0, 0x56656C6F, 0x63697479, 0x202D4A20, 0x2D4A0000, 0x8378838D, 0x83568365,
    0x8342204A, 0x204A0000, 0x53756E72, 0x69736520, 0x31343000, 0x83548393, 0x83898343, 0x83592031,
    0x34300000, 0x53617475, 0x726E202D, 0x53470000, 0x8354835E, 0x815B8393, 0x20534700, 0x426C7573,  /* fzgx-allow: A1 retail data bytes */
    0x74657220, 0x2D58202D, 0x58000000, 0x83758389, 0x8358835E, 0x815B2058, 0x20580000, 0x44657669,  /* fzgx-allow: A1 retail data bytes */
    0x6C666973, 0x68202D52, 0x58202D52, 0x58000000, 0x83668372, 0x838B8374, 0x83428362, 0x83568385,
    0x20525820, 0x52580000, 0x4D617273, 0x202D4558, 0x202D4558, 0x0, 0x837D815B, 0x83592045,
    0x58204558, 0x0, 0x54697461, 0x6E202D47, 0x34202D47, 0x34000000, 0x835E8343, 0x835E8393,
    0x20473420, 0x47340000, 0x45787472, 0x656D6520, 0x2D5A5A20, 0x2D5A5A00, 0x8347834E, 0x83588367,
    0x838A815B, 0x8380205A, 0x5A205A5A, 0x0, 0x5468756E, 0x64657262, 0x6F6C7420, 0x2D563220,
    0x2D563200, 0x83548393, 0x835F815B, 0x837B838B, 0x83672056, 0x32205632, 0x0, 0x426F7865,
    0x72202D32, 0x43000000, 0x837B834E, 0x8354815B, 0x20324300, 0x53687574, 0x746C6520, 0x2D4D3220,
    0x2D4D3200, 0x83568383, 0x8367838B, 0x204D3220, 0x4D320000, 0x50756E69, 0x73686572, 0x202D3458,
    0x202D3458, 0x0, 0x8370836A, 0x83568383, 0x815B2034, 0x58203458, 0x0, 0x53636F72,  /* fzgx-allow: A1 retail data bytes */
    0x70696F6E, 0x202D5220, 0x2D520000, 0x83588352, 0x815B8373, 0x83498393, 0x20522052, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x52616964, 0x656E202D, 0x3838202D, 0x38380000, 0x83898343, 0x83668393, 0x20383820, 0x38380000,
    0x496D7075, 0x6C736520, 0x32323000, 0x83438393, 0x8370838B, 0x83582032, 0x32300000, 0x42617A6F,
    0x6F6B6120, 0x2D595300, 0x836F8359, 0x815B834A, 0x20595300, 0x4D657465, 0x6F72202D, 0x5252202D,  /* fzgx-allow: A1 retail data bytes */
    0x52520000, 0x83818365, 0x83492052, 0x52205252, 0x0, 0x54696765, 0x72202D52, 0x5A000000,
    0x835E8343, 0x834B815B, 0x20525A00, 0x486F726E, 0x6574202D, 0x4658202D, 0x46580000, 0x837A815B,
    0x836C8362, 0x83672046, 0x58204658, 0x0, 0x4A757069, 0x74657220, 0x2D510000, 0x83578385,
    0x8373835E, 0x815B2051, 0x0, 0x436F6D65, 0x74202D56, 0x202D5600, 0x83528381, 0x83628367,  /* fzgx-allow: A1 retail data bytes */
    0x20562056, 0x0, 0x43726F77, 0x6E202D37, 0x37202D37, 0x37000000, 0x834E8389, 0x83458393,
    0x20373720, 0x37370000, 0x54726970, 0x6C65202D, 0x5A202D5A, 0x0, 0x8367838A, 0x8376838B,
    0x205A205A, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_462A0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x20000000
};
static u32 fzgx_pool_data_lbl_1_data_462A4[45] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000, 0x25732573, 0x0, 0x25732025, 0x73000000, 0x412B0000, 0x41000000, 0x422B0000,
    0x42000000, 0x432B0000, 0x442B0000, 0x44000000, 0x452B0000, 0x45000000, (u32)fn_1_14EE00__fzgx_offset_64, (u32)fn_1_14EE00__fzgx_offset_88,
    (u32)fn_1_14EE00__fzgx_offset_6C, (u32)fn_1_14EE00__fzgx_offset_88, (u32)fn_1_14EE00__fzgx_offset_74, (u32)fn_1_14EE00__fzgx_offset_88, (u32)fn_1_14EE00__fzgx_offset_7C, (u32)fn_1_14EE00__fzgx_offset_88, (u32)fn_1_14EE00__fzgx_offset_84, 0x426F6479,
    0x0, 0x837B8366, 0x83420000, 0x436F636B, 0x50697400, 0x83528362, 0x834E8373, 0x83628367,
    0x0, 0x426F6F73, 0x74000000, 0x8375815B, 0x83588367, 0x0, 0x70617274, 0x735F2573,
    0x2E74706C, 0x0, 0x43757374, 0x6F6D697A, 0x65000000
};
static u32 fzgx_pool_data_lbl_1_data_43E78_24E0[28] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732025, 0x73257300, 0x70617274, 0x735F2573, 0x5F302564, 0x656D622E, 0x676D6100, 0x70617274,
    0x735F2573, 0x5F656D62, 0x2E676D61, 0x0, 0x505B2564, 0x5D3A2025, 0x73202C20, 0x2573202C,
    0x2025730A, 0x0, 0x505B2564, 0x5D20496E, 0x76616C69, 0x64202E2E, 0x2E0A0000, 0x25336420,
    0x0, 0x2533640A, 0x0, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_43E78(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43E78;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43E78_9A0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_44F58;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_462A0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_462A4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43E78_24E0;
}
#pragma section code_type ".text"

char *fn_1_14FEAC(s16 arg0, s16 arg1, s16 arg2, char *out, s16 arg4) {
    s16 i;
    NameCache *cache;
    s16 k;
    char *p0;
    char *p1;
    char *p2;
    u32 code;
    u32 flags;
    s32 n;
    s16 j;
    char *tok;
    char *str;
    char *s2;
    char *s1;
    u32 found;
    s16 idx;
    NameFlags table;
    char part2[2][0x20];
    char part1[2][0x20];
    char part0[2][0x20];
    char name2[0x40];
    char name1[0x40];
    char name0[0x40];
    char tok0[0x40];
    char tok1[0x40];
    char tok2[0x40];
    s32 key;

    code = (arg0 << 10) | ((arg1 - 25) << 5) | (arg2 - 50);
    key = (s16)code;
    
    found = fn_8007E96C((u32)&key, (u32)lbl_1_bss_8E6B0, 77, 4, (Sig_fn_8007E96C_fn_8007E96C_Compare)fn_1_14FD6C);
    if (found == 0) {
        idx = -1;
    } else {
        idx = ((s32)found - (s32)lbl_1_bss_8E6B0) / 4;
    }
    if (idx != -1) {
        strcpy(out, ((char *(*)[6])fzgx_pool_data_lbl_1_data_43E78_9A0)[idx][arg4]);
        goto done; /* share the final output return with the cache update path */
    }
    cache = (NameCache *)lbl_1_bss_8E7E4;
    for (i = 0; i < 20; i++) {
        if (cache->entries[i].key == code && arg4 == cache->entries[i].id) {
            strcpy(out, cache->entries[i].str);
            return out;
        }
    }
    n = 0;
    table = *(NameFlags *)lbl_1_rodata_99D8;
    flags = table.flags[arg2];
    if (flags & 8) {
        fn_1_14EBF8(arg0, name0, arg4);
    } else {
        fn_1_14EA74(arg0, name0, arg4);
    }
    if (flags & 4) {
        fn_1_14EBF8(arg2, name2, arg4);
    } else {
        fn_1_14EA74(arg2, name2, arg4);
    }
    if (flags & 0x10) {
        fn_1_14EBF8(arg1, name1, arg4);
    } else {
        fn_1_14EA74(arg1, name1, arg4);
    }
    p0 = part0[0];
    p1 = part1[0];
    p2 = part2[0];
    for (k = 0; k < 2; k++) {
        /* take the k-th token of each name, or the whole name if it has fewer */
        strcpy(tok0, name0);
        str = tok0;
        for (j = 0; (tok = strtok(str, (char *)((u8 *)fzgx_pool_data_lbl_1_data_462A0))) != NULL; j++) {
            if (j == k) {
                strcpy(p0, tok);
                goto found0; /* token found: skip the whole-name fallback */
            }
            str = NULL;
        }
        strcpy(p0, name0);
found0:
        strcpy(tok1, name1);
        str = tok1;
        for (j = 0; (tok = strtok(str, (char *)((u8 *)fzgx_pool_data_lbl_1_data_462A0))) != NULL; j++) {
            if (j == k) {
                strcpy(p1, tok);
                goto found1; /* token found: skip the whole-name fallback */
            }
            str = NULL;
        }
        strcpy(p1, name1);
found1:
        strcpy(tok2, name2);
        str = tok2;
        for (j = 0; (tok = strtok(str, (char *)((u8 *)fzgx_pool_data_lbl_1_data_462A0))) != NULL; j++) {
            if (j == k) {
                strcpy(p2, tok);
                goto found2; /* token found: skip the whole-name fallback */
            }
            str = NULL;
        }
        strcpy(p2, name2);
found2:
        p0 += 0x20;
        p1 += 0x20;
        p2 += 0x20;
    }
    s1 = part0[0];
    s2 = part1[1];
    if (flags & 1) {
        s1 = part1[0];
        s2 = part0[1];
    }
    if (flags & 2) {
        n = fn_1_14ED00(arg2, name2, arg4);
    }
    sprintf(out, (char *)((u8 *)fzgx_pool_data_lbl_1_data_43E78_24E0), s1, s2, n);
    strcpy(cache->entries[cache->next].str, out);
    cache->entries[cache->next].key = code;
    cache->entries[cache->next].id = arg4;
    n = cache->next + 1;
    cache->next = (n > 19) ? 0 : ((n < 0) ? 19 : n);
done:
    return out;
}
/* fzgx:end fn_1_14FEAC */

/* fzgx:begin fn_1_1502BC noprologue */
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern u8 lbl_8015B200[];
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);

struct Entry {
	void *a;
	void *b;
};

struct Group {
	struct Entry e[6];
};

struct Names {
	u8 *p[75];
};

extern struct Names lbl_1_rodata_CE10;

static inline void fn_1_1502BC_load(struct Group *g, s16 v, s16 mask, char *data)
{
	s16 j;
	s16 k;
	struct Names names;
	char buf[64];

	names = lbl_1_rodata_CE10;

	for (j = 0; j < strlen((const char *)names.p[v]); j++) {
		u8 c = names.p[v][j];

		names.p[v][j] = (c == -1) ? -1 : lbl_8015B200[c];
	}

	for (k = 0; k < 3; k++) {
		if ((mask & (1 << k)) != 0 && g->e[k].a == 0) {
			if (k != 0) {
				sprintf(buf, data + 0x24e8, names.p[v], k + 1);
			} else {
				sprintf(buf, data + 0x24fc, names.p[v]);
			}
			g->e[k].b = 0;
			g->e[k].a = fn_1_12ADA0(buf, g->e[k].b);
			fn_1_8019C(g->e[k].a);
		}
	}
}

struct Group *fn_1_1502BC(struct Group *arg0, s16 *arg1, s16 arg2)
{
	char *data = (char *)lbl_1_data_43E78;
	s16 i;

	fn_1_12AB38(data + 5004);

	for (i = 0; i < 3; i++) {
		fn_1_1502BC_load(&arg0[i], arg1[i], arg2, data);
	}

	fn_1_12AB38(data + 5000);
	return arg0;
}
/* fzgx:end fn_1_1502BC */

/* fzgx:begin fn_1_150464 noprologue */
void fn_1_150464(u32 arg0) {
    u32 v2;
    u32 v1;
    s32 v0;
    struct { s32 value; } v3;
    u32 v4;
    u32 v5;
    v0 = 0;
    v1 = arg0;
    while ((s16)v0 < 3) {
    v2 = v1;
    v3.value = 0;
    while ((s16)v3.value < 3) {
    v4 = *(u32 *)(v2);
    if (v4 != 0) {
    fn_800711A8( ((struct Sig_fn_800711A8_fn_800711A8_Arg0 *)v4));
    *(u32 *)((u8 *)v2 + 0) = 0;
    }
    v5 = *(u32 *)((u8 *)v2 + 4);
    if (v5 != 0) {
    fn_80071718( ((struct Sig_fn_80071718_fn_80071718_Arg0 *)v5));
    *(u32 *)((u8 *)v2 + 4) = 0;
    }
    v2 += 8;
    v3.value++;
    }
    v1 += 48;
    v0++;
    }
}
/* fzgx:end fn_1_150464 */

/* fzgx:begin fn_1_150500 noprologue */
void fn_1_150500(void) {
    lbl_1_data_2A7E0.unk_3C->unk_0 = 0;
}
/* fzgx:end fn_1_150500 */

/* fzgx:begin fn_1_150518 noprologue */
// Reset the active object's counters and re-run its two setup passes.
void fn_1_150518(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    obj->unk_84 = 0;
    obj->unk_2724 = 0;
    fn_1_9A508(&lbl_1_data_2A7E0);
    fn_1_150C8C( (fn_1_150C8C_Object *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_150F30( (fn_1_150F30_StaticDisp *)(Obj_1_data_2A7E0_At3C *)(obj));
    obj->unk_0 = 1;
}
/* fzgx:end fn_1_150518 */

/* fzgx:begin fn_1_150570 noprologue */
// fn_1_150570: empty in retail (single blr).
void fn_1_150570(void) {
}
/* fzgx:end fn_1_150570 */

/* fzgx:begin fn_1_150574 noprologue */
// Initializes the static display object referenced by the main state.
void fn_1_150574(void) {
    Obj_1_data_2A7E0_At3C *display = lbl_1_data_2A7E0.unk_3C;

    fn_1_150CEC(display);
    fn_1_151668( (fn_1_151668_StaticDisp *)(display));
}
/* fzgx:end fn_1_150574 */

/* fzgx:begin fn_1_1505B4 noprologue */
// Refreshes the static display state and applies the current object selection.
void fn_1_1505B4(void) {
    Obj_1_data_2A7E0_At3C *display_state;
    u32 result;

    display_state = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    result = fn_1_9D260();
    fn_1_150D3C(display_state, result);
    fn_1_150654();
    fn_1_151054(display_state);
}
/* fzgx:end fn_1_1505B4 */

/* fzgx:begin fn_1_150608 noprologue */
// Prepare the static display state and pass it to the display routine.
void fn_1_150608(void) {
    Obj_1_data_2A7E0_At3C *value;
    u32 result;

    value = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD88();
    result = fn_1_9D260();
    fn_1_150ED0(value, result);
}
/* fzgx:end fn_1_150608 */

/* fzgx:begin fn_1_150650 noprologue */
// fn_1_150650: empty in retail (single blr).
void fn_1_150650(void) {
}
/* fzgx:end fn_1_150650 */

/* fzgx:begin fn_1_150654 noprologue */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f64 unk_18;
} PoolCF40;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct {
    u8 pad[0x24];
} Entry24;

extern s16 fn_1_3F0C8(Obj_1_data_2A7E0 *);
extern void fn_1_1507C4(Entry24 *, Vec3 *);

void fn_1_150654(void) {
    s32 *counters;
    s32 i;
    Entry24 *entries;
    s32 *base;
    s32 x;

    base = (s32 *)lbl_1_data_2A7E0.unk_3C;
    if (fn_1_3F0C8(&lbl_1_data_2A7E0) == 40) {
        return;
    }

    counters = base;

    entries = (Entry24 *)lbl_1_bss_3BE0->unk_A8;
    i = 0;
    while (i < (s32)lbl_1_bss_3BE0->unk_A4) {
        u32 n = lbl_801A63C0 * 0x676A4B6B + 0x33CB;

{
    u32 *seed = &lbl_801A63C0;
        *seed = n;
}
        x = (n >> 16) & 0x7FFF;
        if (x % 70 == 0) {
            u32 m = n * 0x676A4B6B + 0x33CB;

            lbl_801A63C0 = m;
            x = (m >> 16) & 0x7FFF;
            counters[1] = (s16)(20.0f + (10.0f * (x / 32767.0f)));
        }
        if (((s32 *)(counters))[1] != 0) {
            counters[1] = ((s32 *)(counters))[1] - 1;
            {
                Vec3 v = {0x00000000u, 0xBF800000u, 0x00000000u};

                fn_1_1507C4(entries, &v);
            }
        }
        counters = counters + 1;
        i = i + 1;
        entries = (Entry24 *)((u8 *)entries + 0x24);
    }
}
/* fzgx:end fn_1_150654 */

/* fzgx:begin fn_1_1507C4 */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@b1e6f2df) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).




#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */


typedef struct {
    u8 pad_0[0x8];
    u32 flags;
    u16 unk_C;
    u8 pad_E[0x2];
    s32 life;
    u8 pad_14[0x6];
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[0x14];
    Fn183D28Vec3 pos;
    Fn183D28Vec3 vel;
    u8 pad_54[0xc];
    Fn183D28Vec3 prev;
    u8 pad_6C[0x1c];
    f32 unk_88;
    f32 unk_8C;
    u8 pad_90[0xe8 - 0x90];
} Fn1507C4Particle;


static inline s32 fn_1_1507C4_rand(void) {
    lbl_801A63C0 = (lbl_801A63C0) * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

/* Pool primer: fixes retail's literal-pool order for this TU (dropped at integration). */
static const u32 fzgx_pool_table_0[4] = {0x00000000, 0xBF800000, 0x00000000, 0x41A00000};

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(f32 *out, f64 *dout, s32 n) {
    out[0] = *(f32 *)&fzgx_pool_table_0[0];
    out[1] = 10.0f;
    out[2] = 32767.0f;
    dout[1] = 4503601774854144.0;
    out[4] = -1.1920929e-07f;
    out[5] = 2400.0f;
    out[6] = 50.0f;
    out[7] = 0.5f;
    out[8] = 60.0f;
    out[9] = 0.2f;
    out[10] = 0.8f;
    out[11] = 0.7f;
    out[12] = 0.3f;
    out[13] = 7.0f;
    dout[0] = 0.5;
    out[14] = 255.0f;
    out[15] = 1.0f;
    out[16] = 102.0f;
    out[17] = 0.0f;
    out[18] = 0.0005f;
    out[19] = 0.003f;
}

static inline f32 RANDF(void) {
    return fn_1_1507C4_rand() / 32767.0f;
}

static inline f32 fn_1_1507C4_random_range(f32 base, f32 range) {
    return base + range * RANDF();
}

static inline void fn_1_1507C4_copy_vec(const Fn183D28Vec3 *src, Fn183D28Vec3 *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

void fn_1_1507C4(Fn183D28Vec3 *pos, Fn183D28Vec3 *vel) {
    Fn183D28Vec3 view;
    Fn1507C4Particle p;
    f32 size;
    f32 t;
    f32 spread;
    u8 i;

    spread = 7.0f;

    lbl_8006DCA4();
    if (fn_1_54E34(pos, 10.0f) == 0) {
        return;
    }
    lbl_8006E1B0(pos, &view);
    if (view.z > -1.1920929e-07f) {
        return;
    }
    size = 2400.0f / (-view.z * fn_1_A71AC());
    if (size < 10.0f) {
        if (lbl_801A66A0 % 3 != 0) {
            return;
        }
    } else if (size < 50.0f) {
        if (lbl_801A66A0 & 1) {
            return;
        }
    }

    memset(&p, 0, sizeof(p));
    p.unk_C = 15;
    p.unk_1A = 0xFFFF;
    p.flags |= 0x1000;
    for (i = 2; i != 0; i--) {
        fn_1_1507C4_copy_vec(pos, &p.pos);
        p.life = 0.5f * (60.0f * fn_1_1507C4_random_range(0.2f, 0.8f));
        p.prev = p.pos;
        t = 10.0f * fn_1_1507C4_random_range(0.7f, 0.3f);
        lbl_8006D5F0(vel, vel, t);
        p.vel.x = vel->x;
        p.vel.y = vel->y;
        p.vel.z = vel->z;
        p.vel.x += spread * (RANDF() - 0.5);
        p.vel.y += spread * (RANDF() - 0.5);
        p.vel.z += spread * (RANDF() - 0.5);
        p.pos.x -= p.vel.x;
        p.pos.y -= p.vel.y;
        p.pos.z -= p.vel.z;
        t = 0.8f + 0.2f * RANDF();
        p.unk_1C = (255.0f * (0.5f * (1.0f + t))) / 255.0f;
        p.unk_20 = (102.0f * t) / 255.0f;
        p.unk_24 = 0.0f;
        p.unk_88 = 0.0005f * RANDF();
        p.unk_8C = 0.003f;
        fn_1_58E3C(&p);
    }
}
/* fzgx:end fn_1_1507C4 */

/* fzgx:begin fn_1_150C8C */
// Marks each static display entry active before updating it.
void fn_1_150C8C(fn_1_150C8C_Object *obj) {
    s32 count;
    fn_1_150C8C_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        entry->active = 1;
        fn_1_103090(entry);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150C8C */

/* fzgx:begin fn_1_150CEC */
typedef struct fn_1_150CEC_Entry {
    u8 data[0xac];
} fn_1_150CEC_Entry;

typedef struct fn_1_150CEC_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150CEC_Entry entries[1];
} fn_1_150CEC_Object;

void fn_1_150CEC(fn_1_150CEC_Object *obj) {
    s32 count;
    fn_1_150CEC_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        fn_1_1030A4(entry);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150CEC */

/* fzgx:begin fn_1_150D3C */
#pragma section code_type ".fzgxpool"
static const u32 fn_1_150D3C_fzgx_pool_table1[3] = {0x00000000, 0xBF800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_150D3C_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_150D3C_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_150D3C_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 10.0f;
    s = 32767.0f;
    d = 4503601774854144.0;
    s = -1.1920928955078125e-07f;
    s = 2400.0f;
    s = 50.0f;
    s = 0.5f;
    s = 60.0f;
    s = 0.20000000298023224f;
    s = 0.800000011920929f;
    s = 0.699999988079071f;
    s = 0.30000001192092896f;
    s = 7.0f;
    d = 0.5;
    s = 255.0f;
    s = 1.0f;
    s = 102.0f;
    s = 0.0f;
    s = 0.0005000000237487257f;
    s = 0.003000000026077032f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 182.04444885253906f;
}
static const u32 fn_1_150D3C_fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_150D3C_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_150D3C_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_150D3C_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"






void fn_1_150D3C(Object *obj, void *arg) {
    s32 count;
    fn_1_150D3C_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        if (((entry->flags >> 28) & 1) != 0) {
            entry->x = (0.649999976f);
            entry->y = (0.75f);
            entry->z = (1.0f);
        } else if (((entry->flags >> 29) & 1) != 0) {
            entry->x = (1.0f);
            entry->y = (0.0f);
            entry->z = (0.0f);
        } else {
            entry->x = __fabs(
                lbl_8006D188(((182.044449f) * lbl_801A66A0)));
            entry->y = __fabs(
                lbl_8006D188(((182.044449f) * lbl_801A66A0 * (0.5))));
            entry->z = __fabs(
                lbl_8006D188(((182.044449f) * lbl_801A66A0 * (2.0))));
        }
        fn_1_1030D4(entry, arg);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150D3C */

/* fzgx:begin fn_1_150ED0 */
typedef struct fn_1_150ED0_Entry {
    u8 data[0xac];
} fn_1_150ED0_Entry;

typedef struct fn_1_150ED0_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150ED0_Entry entries[1];
} fn_1_150ED0_Object;

void fn_1_150ED0(fn_1_150ED0_Object *obj, void *arg) {
    s32 count;
    fn_1_150ED0_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        fn_1_103264(entry, arg);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150ED0 */

/* fzgx:begin fn_1_150F30 */
// Reset the display state before rebuilding its static entries.
void fn_1_150F30(fn_1_150F30_StaticDisp *self) {
    self->unk_2728 = 0;
    self->unk_272c = -1;
    fn_1_150F74(self);
    fn_1_151668( (fn_1_151668_StaticDisp *)(self));
}
/* fzgx:end fn_1_150F30 */

/* fzgx:begin fn_1_150F74 */
typedef struct fn_1_150F74_Object {
    u8 pad_0[0x2730];
    f32 value_2730;
    f32 value_2734;
    f32 value_2738;
    f32 value_273c;
    u8 pad_2740[4];
    f32 value_2744;
} fn_1_150F74_Object;

typedef struct fn_1_150F74_Entry {
    u8 pad_0[0x1824];
    f32 value_1824;
    f32 value_1828;
    f32 value_182c;
    f32 value_1830;
    f32 value_1834;
    f32 value_1838;
    f32 value_183c;
    f32 value_1840;
    f32 value_1844;
    f32 value_1848;
    u8 pad_184c[0xc];
    u32 *bits;
    u8 flag_185c;
    u8 flag_185d;
    u8 flag_185e;
    u8 flag_185f;
} fn_1_150F74_Entry;

// Initialize display values and propagate enabled display flags across all entries.
void fn_1_150F74(void *self) {
    fn_1_150F74_Object *obj;
    const f32 *constants;
    fn_1_150F74_Entry *entry;
    u32 *bit_flags;
    s32 index;

    obj = (fn_1_150F74_Object *)self;
    constants = lbl_1_rodata_CF40;
    obj->value_2730 = constants[58];
    obj->value_2734 = constants[23];
    obj->value_2738 = constants[23];
    obj->value_273c = constants[59];
    obj->value_2744 = constants[60];

    entry = (fn_1_150F74_Entry *)obj;
    for (index = 0; index < 0x40; index++) {
        bit_flags = entry->bits;
        if (entry->flag_185c != 0) {
            entry->value_1824 = obj->value_2730;
            entry->value_1828 = constants[23];
            entry->value_182c = constants[23];
            *bit_flags |= ((u32)1 << 31);
        }
        if (entry->flag_185d != 0) {
            entry->value_1824 = constants[23];
            entry->value_1828 = constants[23];
            entry->value_182c = constants[23];
            entry->value_1830 = constants[23];
        }
        if (entry->flag_185d != 0 || entry->flag_185e != 0) {
            entry->value_1834 = constants[23];
            entry->value_1840 = constants[23];
            entry->value_1838 = constants[23];
            entry->value_1844 = constants[23];
            entry->value_183c = constants[23];
            entry->value_1848 = constants[23];
        }
        if (entry->flag_185f != 0) {
            *bit_flags &= 0x7fffffff;
        }
        entry = (fn_1_150F74_Entry *)((u8 *)entry + 0x3c);
    }
}
/* fzgx:end fn_1_150F74 */

/* fzgx:begin fn_1_151054 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern const f32 lbl_1_rodata_CF40[12];
extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32 index);
extern s16 camera_get_mode(void);
extern void fn_1_627C(s32 index);

typedef struct CameraState151054 {
    u8 pad_0[0x118];
    s32 unk_118;
} CameraState151054;
extern CameraState151054 *fn_1_8627C(s32 mode);

typedef struct Rotation151054 {
    u32 unk_0;
    f32 unk_4;
} Rotation151054;

typedef struct Display151054 {
    u32 unk_0;
    u8 pad_4[0xC];
    f32 unk_10;
    u8 pad_14[0x20];
    Rotation151054 **unk_34;
} Display151054;

typedef struct Entry151054 {
    f32 unk_1824;
    f32 unk_1828;
    f32 unk_182C;
    f32 unk_1830;
    f32 unk_1834;
    f32 unk_1838;
    f32 unk_183C;
    f32 unk_1840;
    f32 unk_1844;
    f32 unk_1848;
    f32 unk_184C;
    f32 unk_1850;
    f32 unk_1854;
    Display151054 *unk_1858;
    u8 unk_185C;
    u8 unk_185D;
    u8 unk_185E;
    u8 unk_185F;
} Entry151054;

typedef struct State151054 {
    u8 pad_0[0x1824];
    Entry151054 entries[64];
    s32 unk_2724;
    s32 unk_2728;
    s32 unk_272C;
    f32 unk_2730;
    f32 unk_2734;
    f32 unk_2738;
    f32 unk_273C;
    f32 unk_2740;
    f32 unk_2744;
} State151054;

#define clamp151054(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))

void fn_1_151054(State151054 *arg0) {
    s32 i;
    s32 count;
    const f32 *pool = lbl_1_rodata_CF40;
    CameraState151054 *camera;

    if (arg0->unk_2728 == 0 && arg0->unk_272C == -1) {
        count = fn_1_58C4();
        if (count == 1) {
            for (i = 0; i < count; i++) {
                fn_1_5948(i);
                {
                    s32 mode = camera_get_mode();
                    if (mode >= 0) {
                        camera = fn_1_8627C(mode);
                        if (camera != 0 && camera->unk_118 + 1 == 3) {
                            arg0->unk_272C = 0;
                            break;
                        }
                    }
                }
                fn_1_627C(i);
            }
        }
    }
    if (arg0->unk_2728 == 0 && arg0->unk_272C != -1) {
        arg0->unk_272C++;
        if (arg0->unk_272C > 1000) {
            arg0->unk_2728 = 1;
            arg0->unk_272C = -1;
        }
    }
    if (arg0->unk_2728 != 0) {
        arg0->unk_2740 = clamp151054(pool[0x54/4] + arg0->unk_2740, pool[0x5C/4], pool[0xF4/4]);
    }
    if (arg0->unk_2728 != 0) {
        for (i = 0; i < arg0->unk_2724; i++) {
            Entry151054 *entry = &arg0->entries[i];
            Display151054 *display = entry->unk_1858;
            if (entry->unk_185C || entry->unk_185D) {
                f32 duration;
                f32 elapsed;
                elapsed = arg0->unk_2740;
                duration = arg0->unk_2744;
                if (elapsed < duration) {
                    entry->unk_1828 = pool[0xF8/4] * elapsed / duration;
                } else {
                    f32 speed = (pool[0xF8/4] * elapsed / duration) +
                        (pool[0x90/4] * (elapsed - duration) / duration);
                    f32 limit = pool[0x5C/4];
                    if (entry->unk_185C) {
                        limit = pool[0xFC/4] * (arg0->unk_2734 - entry->unk_1824);
                    } else if (entry->unk_185D) {
                        limit = pool[0xFC/4] * (arg0->unk_273C - entry->unk_1824);
                    }
                    entry->unk_1828 = speed > limit ? speed : limit;
                }
                if (entry->unk_1828 > pool[0x5C/4] || entry->unk_182C != pool[0x5C/4]) {
                    /* Keep the reset's independent pool read; do not reuse the comparison load. */
                    entry->unk_1828 = *(const f32 *)&pool[0x5C/4];
                }
                if (entry->unk_185C) {
                    entry->unk_1824 = clamp151054(entry->unk_1828 + entry->unk_1824, arg0->unk_2734, arg0->unk_2730);
                    if (entry->unk_1824 == arg0->unk_2734) {
                        entry->unk_182C = pool[0x54/4];
                    }
                } else if (entry->unk_185D) {
                    entry->unk_1824 = clamp151054(entry->unk_1828 + entry->unk_1824, arg0->unk_273C, arg0->unk_2738);
                    if (entry->unk_1824 == arg0->unk_273C) {
                        entry->unk_182C = pool[0x54/4];
                    }
                }
            }
            if (entry->unk_185D || entry->unk_185E) {
                if (entry->unk_185D) {
                    s32 axis;
                    struct { f32 value; } zero;
                    zero.value = pool[0x5C/4];
                    for (axis = 0; axis < 3; axis++) {
                        f32 elapsed = arg0->unk_2740;
                        f32 duration = arg0->unk_2744;
                        if (elapsed < duration) {
                            f32 initial = (&entry->unk_184C)[axis];
                            elapsed = initial * elapsed;
                            elapsed /= duration;
                            elapsed = initial - elapsed;
                            (&entry->unk_1840)[axis] = elapsed;
                        } else {
                            (&entry->unk_1840)[axis] = zero.value;
                        }
                    }
                }
                if (entry->unk_185E) {
                    s32 axis;
                    f32 zero;
                    f32 factor = pool[0x100/4];
                    zero = pool[0x5C/4];
                    for (axis = 0; axis < 3; axis++) {
                        f32 duration = arg0->unk_2744;
                        if (factor * arg0->unk_2740 < duration) {
                            (&entry->unk_1840)[axis] = (&entry->unk_184C)[axis];
                        } else {
                            f32 initial = (&entry->unk_184C)[axis];
                            f32 value = initial - initial * (factor * arg0->unk_2740 - duration) / duration;
                            if (zero > value) value = zero;
                            (&entry->unk_1840)[axis] = value;
                        }
                    }
                }
                {
                    f32 scale = pool[0x30/4];
                    entry->unk_1834 += entry->unk_1840;
                    entry->unk_1838 += entry->unk_1844;
                    entry->unk_183C += entry->unk_1848;
                    if (display->unk_34 != 0 && display->unk_34[0] != 0) {
                        display->unk_34[0]->unk_4 = scale * entry->unk_1834 / lbl_1_data_2A7E0.unk_1C;
                    }
                    if (display->unk_34 != 0 && display->unk_34[1] != 0) {
                        display->unk_34[1]->unk_4 = scale * entry->unk_1838 / lbl_1_data_2A7E0.unk_1C;
                    }
                    if (display->unk_34 != 0 && display->unk_34[2] != 0) {
                        display->unk_34[2]->unk_4 = scale * entry->unk_183C / lbl_1_data_2A7E0.unk_1C;
                    }
                }
            }
            if (entry->unk_185C) {
                display->unk_0 &= 0x7FFFFFFF;
            }
            if (entry->unk_185F) {
                display->unk_0 |= 0x80000000;
            }
        }
    }
    for (i = 0; i < arg0->unk_2724; i++) {}
    for (i = 0; i < arg0->unk_2724; i++) {
        Entry151054 *entry = &arg0->entries[i];
        Display151054 *display = entry->unk_1858;
        if (entry->unk_185C || entry->unk_185D) {
            display->unk_10 = entry->unk_1830 + entry->unk_1824;
        }
    }
}
/* fzgx:end fn_1_151054 */

/* fzgx:begin fn_1_151668 */
void fn_1_151668(fn_1_151668_StaticDisp *self) {
    s32 i;
    s32 j;

    self->value_2728 = 0;
    self->value_272c = -1;
    for (i = 0; i < self->entry_count; i++) {
        fn_1_151668_StaticDispEntry *entry = &self->entries[i];
        DispObject *object = entry->object;

        if (entry->active != 0) {
            object->value = entry->first;
            object->flags |= (u32)1 << 31;
        }
        if (entry->scale_first != 0 || entry->scale_second != 0) {
            f32 scale = lbl_1_rodata_CF70[0];
            for (j = 0; j < 3; j++) {
                if (object->children != 0 && object->children->child[j] != 0) {
                    object->children->child[j]->value = scale * entry->values[j];
                }
            }
        }
        if (entry->clear_flag != 0) {
            object->flags &= ~((u32)1 << 31);
        }
    }
}
/* fzgx:end fn_1_151668 */

/* fzgx:begin fn_1_151764 */
// fn_1_151764: returns a constant.
int fn_1_151764(void) {
    return 1;
}
/* fzgx:end fn_1_151764 */
