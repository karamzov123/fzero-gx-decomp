#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "game/pad.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "rel/main_rel/custom_memcard.h"
#include "rel/main_rel/burner.h"
#include "fpscr_trunc.h"


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

struct fn_1_13B548_lbl_1_rodata_85F0 { f32 unk_0; };

struct fn_1_138E44_lbl_1_rodata_8600 {
    f64 unk_0;
};

typedef struct {
    u8 r, g, b, a;
} StatColor;

typedef struct {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    StatColor color;
    u8 color_add[4];
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    void *vertex_callback;
    u32 unk_54;
} StatPacket;

typedef struct {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    u32 color;
    u8 color_add[4];
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    void *vertex_callback;
    u32 unk_54;
} RecordPacket;

typedef struct {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    f32 sx;
    f32 sy;
    u8 pad_18[0x18];
    u32 flags;
    u32 pad_34;
    u32 color;
    u8 pad_3C[0x1C];
} FontPkt;

typedef struct {
    u32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    u8  f18[0x18];
    u32 f30;
    u32 f34;
    u8  f38;
    u8  f39;
    u8  f3A;
    u8  f3B[0x15];
    u32 f50;
    u32 f54;
} fn_1_141360_Pkt;

struct fn_1_1418EC_Pkt {
	u32 index;
	f32 x;
	f32 y;
	f32 z;
	u8 pad[32];
	u32 flags;
	u8 tail[36];
};

struct fn_1_13ABA8_packet {
    u32 flags;
    f32 x, y, z;
    u32 tail[18];
};

struct fn_1_13A460_Loc {
    u32 a0[1];
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    f32 f_10;
    f32 f_14;
    u8 pad_18[0x18];
    u32 n_30;
    u8 pad_34[0x24];
};

typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;

typedef struct fn_1_1358BC_Table { u32 image[41]; } fn_1_1358BC_Table;

typedef struct SelImageTable {
    u32 image[41];
} SelImageTable;

typedef struct Fn1_136174_Entry {
    u32 flags;
    u8 pad_4[0x819C];
    u8 glyph;
    u8 pad_81A1[0x3];
    u8 unk_81A4;
    u8 pad_81A5[0x7];
    u8 unk_81AC;
    u8 pad_81AD[0x7];
    u8 unk_81B4;
    u8 pad_81B5[0xB];
} Fn1_136174_Entry;

typedef struct {
    u32 flags;
    u8 pad_4[0x819C];
    u8 image_index;
    u8 pad_81A1[0x1F];
} MachineEntry;

typedef struct Fn1_136174_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn1_136174_Color;

struct fn_1_1363F0_Color { u32 rgba; };

struct ColorWord { u32 value; };

struct fn_1_13B548_lbl_1_rodata_8B3C { f32 unk_0; };

typedef struct {
    u8 pad_0[0x54];
    f32 unk_54;
} Fn1392E0Arg0;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x1C];
    f32 unk_24;
    f32 unk_28;
} Fn1392E0Arg1;

typedef struct {
    u8 r, g, b, a;
} fn_1_139440_Color;

typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u32 unk_34;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
    u8 unk_40;
    u8 unk_41[3];
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 unk_5C[4];
} fn_1_13A460_Sig_fn_1_8CED0_Fn1_8CED0State;

typedef struct fn_1_13A460_Sig_fn_1_8D3F8_Fn1_8D3F8Car {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40[4];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} fn_1_13A460_Sig_fn_1_8D3F8_Fn1_8D3F8Car;

typedef struct Sig_fn_1_131B90_Obj Sig_fn_1_131B90_Obj;

struct Sig_fn_1_131B90_Obj {
    s16 index;
    u8 pad_2[2];
    u32 field_4;
    u32 field_8;
    u8 pad_c[0x2c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u32 field_48;
    u32 field_4c;
    u32 field_50[1];
};

typedef struct fn_1_13A654_FontVertex {
f32 x, y, z;
} fn_1_13A654_FontVertex;

typedef struct fn_1_13A654_FontDrawPacket fn_1_13A654_FontDrawPacket;

struct fn_1_13A654_FontDrawPacket {
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
fn_1_13A654_FontDrawPacket* secondary;
void (*vertex_callback)(fn_1_13A654_FontDrawPacket* packet, fn_1_13A654_FontVertex* vertices);
u32 unk_54;
};

struct fn_1_13ABA8_lbl_1_rodata_8C14 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C; u32 unk_10; u32 unk_14;
};

struct fn_1_13ABA8_lbl_1_rodata_8C2C {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C; u32 unk_10; u32 unk_14;
};

struct fn_1_13B548_lbl_1_rodata_8C78 { u32 unk_0; };

struct fn_1_13B548_lbl_1_rodata_8C80 { u32 unk_0; };

struct fn_1_13B548_lbl_1_rodata_8C84 { u32 unk_0; };

struct fn_1_13B548_lbl_1_rodata_8C88 { u32 unk_0; };

typedef struct { u8 r, g, b, a; } fn_1_13C5EC_Color;

typedef struct {
    u32 words[22];
} FnData;

typedef struct {
    u8 minutes;
    u8 seconds;
    u16 ms;
    u8 machine[4];  /* [0] machine id (41+ = custom, then three part ids) */
    u8 unk_8;       /* 0-100, the bar position */
    u8 unk_9;       /* cell of the 6x7 sheet at 0xA000 */
    u16 unk_A;
    u8 pad_C[0xC];
    u16 valid;
} RecordTime;

typedef struct {
    char s[17]; } fn_1_13EA9C_Str17;

typedef struct { char s[29]; } fn_1_13EA9C_Str29;

typedef struct { u8 a, b, c, d; } Ent;

typedef struct { Ent e[5]; } Tbl;

struct S16 {
	u32 a;
	u32 b;
	u32 c;
	u16 d;
};

struct fn_1_141A80_Copy { u8 a[111]; };

typedef struct {
    f32 x, y, z;
} StatVec;

typedef struct {
    const char *name;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x10];
    f32 unk_20;
    u8 pad_24[0x20];
    f32 unk_44;
    u8 pad_48[0xC];
    StatVec unk_54;
    u8 pad_60[0xC];
    StatVec unk_6C;
} StatRecord;

typedef struct {
    u16 unk_00;
    u8 unk_02[0x1E];
    u32 unk_20;
    u8 unk_24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} Car;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern u32 lbl_1_rodata_8744[4];
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8678;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_86D0;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_87A4;
extern const f32 lbl_1_rodata_87A8;
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_87B0;
extern const f32 lbl_1_rodata_87B4;
extern const f32 lbl_1_rodata_87BC;
extern const f32 lbl_1_rodata_87C4;
extern const f32 lbl_1_rodata_87D0;
extern const f32 lbl_1_rodata_87D4;
extern const f32 lbl_1_rodata_87D8;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_87E0;
extern const f32 lbl_1_rodata_87EC;
extern const f32 lbl_1_rodata_87F0;
extern const f32 lbl_1_rodata_87F4;
extern const f32 lbl_1_rodata_8800;
extern const f32 lbl_1_rodata_8804;
extern const f32 lbl_1_rodata_8808;
extern const f32 lbl_1_rodata_8824;
extern const f32 lbl_1_rodata_8828;
extern u32 lbl_1_bss_38460[21];
extern const f32 lbl_1_rodata_85F0;
extern const f64 lbl_1_rodata_8600;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8674;
extern u32 lbl_1_rodata_877C[3];
extern u32 lbl_1_rodata_8788[3];
extern u32 lbl_1_rodata_8798;
extern u32 lbl_1_rodata_879C;
extern u32 lbl_1_rodata_87A0;
extern const f32 lbl_1_rodata_87B8;
extern const f32 lbl_1_rodata_87C0;
extern const f32 lbl_1_rodata_87C8;
extern const f32 lbl_1_rodata_87CC;
extern const f32 lbl_1_rodata_87E4;
extern const f32 lbl_1_rodata_87E8;
extern const f32 lbl_1_rodata_87F8;
extern const f32 lbl_1_rodata_87FC;
extern const f32 lbl_1_rodata_880C;
extern const f64 lbl_1_rodata_8810;
extern const f32 lbl_1_rodata_8818;
extern const f32 lbl_1_rodata_881C;
extern const f32 lbl_1_rodata_8820;
extern u32 lbl_801A66A0;
extern f32 fn_1_A6FE8(void);
extern f64 fn_80088598(f64, f64);
extern void fn_1_4E724(void *);
extern s8 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_1_A7024(f32 fovy, f32 aspect, f32 near, f32 far);
extern u32 fn_80074D08(u32 arg0);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_8794;
extern u32 lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E0C8(void *);
extern void fn_1_52070(u32 value);
extern void fn_1_52088(void);
extern void fn_1_556B8(void *value);
extern void fn_1_55FF0(f32 scale);
extern void fn_1_56000(u8 compareEnable, u8 compareFunc, u8 updateEnable);
extern void fn_1_A714C(f32 *fovy, f32 *aspect, f32 *near, f32 *far);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void fn_80072558(void);
extern void fn_800749B0(u32 index, void *transform);
extern void lbl_8006DCDC(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E13C(void *);
extern const f32 lbl_1_rodata_85F4;
extern const f32 lbl_1_rodata_8838;
extern const f32 lbl_1_rodata_883C;
extern const f32 lbl_1_rodata_8840;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_8848;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_8850;
extern const f32 lbl_1_rodata_885C;
extern const f32 lbl_1_rodata_8854;
extern const f32 lbl_1_rodata_8858;
extern fn_1_1358BC_Table lbl_1_rodata_88BC;
extern const f32 lbl_1_rodata_8960;
extern void fn_1_49410(void);
extern void fn_1_495C8(u8 value);
extern void fn_1_494DC(s16 index);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_4962C(void);
extern char *fn_1_14FEAC(s16 arg0, s16 arg1, s16 arg2, char *out, s16 arg4);
extern void fn_1_4CF3C(f32, void*, ...);
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern SelImageTable lbl_1_rodata_8964;
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_49514(u32 *value);
extern void fn_1_5233C(void *arg0, void *arg1);
extern void fn_1_49738(u32 value);
extern void fn_1_49748(f32 value);
extern f32 lbl_1_rodata_8A28;
extern struct fn_1_1363F0_Color lbl_1_rodata_8A0C;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_136714(f32, f32, f32, s32, s32, s32, s32, void *);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern const f32 lbl_1_rodata_8A4C;
extern struct ColorWord lbl_1_rodata_8A48;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y);
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern u8 fn_1_B7CD4(void);
extern u32 fn_1_B7C5C(void);
extern void OSReport(const char *msg, ...);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);
extern u8 lbl_1_rodata_8A5C[156];
extern u32 lbl_1_rodata_8AF8[6];
extern u32 lbl_1_rodata_8B10[6];
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8B28;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8B38;
extern const f32 lbl_1_rodata_8B3C;
extern f32 lbl_1_rodata_8B40;
extern void fn_1_1392E0(Fn1392E0Arg0 *arg0, Fn1392E0Arg1 *arg1);
extern int fn_1_139A3C(int);
extern f32 lbl_8006D188(u32);
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B5C;
extern void fn_1_49768(u8 value);
extern const f32 lbl_1_rodata_8B60;
extern const f32 lbl_1_rodata_88A8;
extern void fn_1_49778(s16 value1, s16 value2, s16 value3, s16 value4);
extern f32 fn_1_4B068(const char *text);
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_8B64;
extern const f32 lbl_1_rodata_8B68;
extern const f32 lbl_1_rodata_8B6C;
extern u32 lbl_1_rodata_8B44;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8B70;
extern u32 lbl_1_rodata_8B48;
extern const f32 lbl_1_rodata_8B74;
extern u32 lbl_1_rodata_8B4C;
extern u32 lbl_1_rodata_8B50;
extern u32 lbl_1_rodata_8B54;
extern u8 fn_1_141F94(u32);
extern void fn_1_135D7C(s16 x, s16 y, u32 format, s16 index, void* arg4, s16 slot, int arg6, f32 scale_x, f32 scale_y, f32 z);
extern void fn_1_136CC4(u32, u32, u32, s16);
extern void fn_1_13A848(s16, s16, s32, s16, s32, f32, f32);
extern void fn_1_13A994();
extern const f32 lbl_1_rodata_85EC;
extern f32 lbl_1_rodata_8A50;
extern const f32 lbl_1_rodata_8B84;
extern u8 fn_1_1358BC__fzgx_offset_108[];
extern u8 fn_1_1358BC__fzgx_offset_114[];
extern u8 fn_1_1358BC__fzgx_offset_120[];
extern u8 fn_1_1358BC__fzgx_offset_128[];
extern u8 fn_1_1358BC__fzgx_offset_C0[];
extern u8 fn_1_1358BC__fzgx_offset_CC[];
extern u8 fn_1_1358BC__fzgx_offset_D8[];
extern u8 fn_1_1358BC__fzgx_offset_E4[];
extern u8 fn_1_1358BC__fzgx_offset_F0[];
extern u8 fn_1_1358BC__fzgx_offset_FC[];
extern u8 fn_1_135B80__fzgx_offset_7C[];
extern u8 fn_1_135B80__fzgx_offset_88[];
extern u8 fn_1_135B80__fzgx_offset_94[];
extern u8 fn_1_135B80__fzgx_offset_A0[];
extern u8 fn_1_135B80__fzgx_offset_AC[];
extern u8 fn_1_135B80__fzgx_offset_B8[];
extern u8 fn_1_135B80__fzgx_offset_C4[];
extern u8 fn_1_135B80__fzgx_offset_D0[];
extern u8 fn_1_135B80__fzgx_offset_DC[];
extern u8 fn_1_135B80__fzgx_offset_E4[];
extern u8 fn_1_135D7C__fzgx_offset_1F0[];
extern u8 fn_1_135D7C__fzgx_offset_1FC[];
extern u8 fn_1_135D7C__fzgx_offset_208[];
extern u8 fn_1_135D7C__fzgx_offset_214[];
extern u8 fn_1_135D7C__fzgx_offset_220[];
extern u8 fn_1_135D7C__fzgx_offset_22C[];
extern u8 fn_1_135D7C__fzgx_offset_238[];
extern u8 fn_1_135D7C__fzgx_offset_244[];
extern u8 fn_1_135D7C__fzgx_offset_250[];
extern u8 fn_1_135D7C__fzgx_offset_258[];
extern u8 fn_1_1373B0__fzgx_offset_AC[];
extern u8 fn_1_1373B0__fzgx_offset_B4[];
extern u8 fn_1_1373B0__fzgx_offset_BC[];
extern u8 fn_1_1373B0__fzgx_offset_C4[];
extern u8 fn_1_1373B0__fzgx_offset_CC[];
extern u8 fn_1_1373B0__fzgx_offset_D4[];
extern u8 fn_1_1373B0__fzgx_offset_DC[];
extern u8 fn_1_1373B0__fzgx_offset_E4[];
extern u8 fn_1_1373B0__fzgx_offset_EC[];
extern u8 fn_1_1373B0__fzgx_offset_F4[];
extern u8 lbl_1_data_40F58__fzgx_offset_0[];
extern u8 lbl_1_data_40F5C__fzgx_offset_0[];
extern u8 lbl_1_data_40F68__fzgx_offset_0[];
extern u8 lbl_1_data_40F74__fzgx_offset_0[];
extern u8 lbl_1_data_40F80__fzgx_offset_0[];
extern u8 lbl_1_data_40F8C__fzgx_offset_0[];
extern u8 lbl_1_data_40F94__fzgx_offset_0[];
extern u8 lbl_1_data_40F9C__fzgx_offset_0[];
extern u8 lbl_1_data_40FA4__fzgx_offset_0[];
extern u8 lbl_1_data_40FAC__fzgx_offset_0[];
extern u8 lbl_1_data_40FB8__fzgx_offset_0[];
extern u8 lbl_1_data_40FC8__fzgx_offset_0[];
extern u8 lbl_1_data_40FD8__fzgx_offset_0[];
extern u8 lbl_1_data_40FE0__fzgx_offset_0[];
extern u8 lbl_1_data_40FE8__fzgx_offset_0[];
extern u8 lbl_1_data_40FF4__fzgx_offset_0[];
extern u8 lbl_1_data_41000__fzgx_offset_0[];
extern u8 lbl_1_data_41010__fzgx_offset_0[];
extern u8 lbl_1_data_41018__fzgx_offset_0[];
extern u8 lbl_1_data_41024__fzgx_offset_0[];
extern u8 lbl_1_data_41030__fzgx_offset_0[];
extern u8 lbl_1_data_41040__fzgx_offset_0[];
extern u8 lbl_1_data_41048__fzgx_offset_0[];
extern u8 lbl_1_data_41054__fzgx_offset_0[];
extern u8 lbl_1_data_41060__fzgx_offset_0[];
extern u8 lbl_1_data_41070__fzgx_offset_0[];
extern u8 lbl_1_data_41078__fzgx_offset_0[];
extern u8 lbl_1_data_41084__fzgx_offset_0[];
extern u8 lbl_1_data_4108C__fzgx_offset_0[];
extern u8 lbl_1_data_41098__fzgx_offset_0[];
extern u8 lbl_1_data_410A8__fzgx_offset_0[];
extern u8 lbl_1_data_410B4__fzgx_offset_0[];
extern u8 lbl_1_data_410C0__fzgx_offset_0[];
extern u8 lbl_1_data_410C8__fzgx_offset_0[];
extern u8 lbl_1_data_410DC__fzgx_offset_0[];
extern u8 lbl_1_data_410EC__fzgx_offset_0[];
extern u8 lbl_1_data_410FC__fzgx_offset_0[];
extern u8 lbl_1_data_41108__fzgx_offset_0[];
extern u8 lbl_1_data_41114__fzgx_offset_0[];
extern u8 lbl_1_data_41124__fzgx_offset_0[];
extern u8 lbl_1_data_4112C__fzgx_offset_0[];
extern u8 lbl_1_data_41138__fzgx_offset_0[];
extern u8 lbl_1_data_41140__fzgx_offset_0[];
extern u8 lbl_1_data_41148__fzgx_offset_0[];
extern u8 lbl_1_data_41150__fzgx_offset_0[];
extern u8 lbl_1_data_4120C__fzgx_offset_0[];
extern u8 lbl_1_data_4122C__fzgx_offset_0[];
extern u8 lbl_1_data_41230__fzgx_offset_0[];
extern u8 lbl_1_data_41274__fzgx_offset_0[];
extern u8 lbl_1_data_41294__fzgx_offset_0[];
extern u8 lbl_1_data_412B8__fzgx_offset_0[];
extern u8 lbl_1_data_412FC__fzgx_offset_0[];
extern u8 lbl_1_data_41340__fzgx_offset_0[];
extern u8 lbl_1_data_41348__fzgx_offset_0[];
extern u8 lbl_1_data_41350__fzgx_offset_0[];
extern u8 lbl_1_data_41358__fzgx_offset_0[];
extern u8 lbl_1_data_41364__fzgx_offset_0[];
extern u8 lbl_1_data_41374__fzgx_offset_0[];
extern u8 lbl_1_data_4137C__fzgx_offset_0[];
extern u8 lbl_1_data_41388__fzgx_offset_0[];
extern u8 lbl_1_data_41390__fzgx_offset_0[];
extern u8 lbl_1_data_4139C__fzgx_offset_0[];
extern u8 lbl_1_data_413A4__fzgx_offset_0[];
extern u8 lbl_1_data_413B0__fzgx_offset_0[];
extern u8 lbl_1_data_413C0__fzgx_offset_0[];
extern u8 lbl_1_data_413D0__fzgx_offset_0[];
extern u8 lbl_1_data_413E0__fzgx_offset_0[];
extern u8 lbl_1_data_413EC__fzgx_offset_0[];
extern u8 lbl_1_data_413F8__fzgx_offset_0[];
extern u8 lbl_1_data_41400__fzgx_offset_0[];
extern u8 lbl_1_data_41408__fzgx_offset_0[];
extern u8 lbl_1_data_41410__fzgx_offset_0[];
extern u8 lbl_1_data_41418__fzgx_offset_0[];
extern u8 lbl_1_data_41420__fzgx_offset_0[];
extern u8 lbl_1_data_41428__fzgx_offset_0[];
extern u8 lbl_1_data_41430__fzgx_offset_0[];
extern u8 lbl_1_data_41438__fzgx_offset_0[];
extern u8 lbl_1_data_41448__fzgx_offset_0[];
extern u8 lbl_1_data_41458__fzgx_offset_0[];
extern u8 lbl_1_data_41468__fzgx_offset_0[];
extern u8 lbl_1_data_41478__fzgx_offset_0[];
extern u8 lbl_1_data_41484__fzgx_offset_0[];
extern u8 lbl_1_data_4148C__fzgx_offset_0[];
extern u8 lbl_1_data_4149C__fzgx_offset_0[];
extern u8 lbl_1_data_414A8__fzgx_offset_0[];
extern u8 lbl_1_data_414C0__fzgx_offset_0[];
extern u8 lbl_1_data_418A4__fzgx_offset_0[];
extern u8 lbl_1_data_418BC__fzgx_offset_0[];
extern const f32 lbl_1_rodata_88B8;
extern const f32 lbl_1_rodata_8B98;
extern void fn_1_14FC80(s16 arg0, u32 arg1);
extern void fn_1_22B10(MachineParameterRecord *, f32);
extern void fn_1_229EC(MachineParameterRecord *, f32 *, f32 *);
extern u32 fn_1_539CC(void *, void *, f32);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_A9868(void);
extern void fn_1_AA350(s16 *x, s16 *y, u8 *color, u32 n);
extern void fn_1_AA538(void);
extern void fn_800724C8(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_800720B0(s32 arg0);
extern void fn_80072864(u32 arg0);
extern fn_1_139440_Color lbl_1_rodata_8B88;
extern fn_1_139440_Color lbl_1_rodata_8B8C;
extern fn_1_139440_Color lbl_1_rodata_8B90;
extern fn_1_139440_Color lbl_1_rodata_8B94;
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_86FC;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern const f32 lbl_1_rodata_8BC0;
extern const f32 lbl_1_rodata_8BC4;
extern const f32 lbl_1_rodata_8BC8;
extern const f32 lbl_1_rodata_8BCC;
extern const f32 lbl_1_rodata_8BD0;
extern const f32 lbl_1_rodata_8BD4;
extern const f32 lbl_1_rodata_8BD8;
extern void _savegpr_27(void);
extern void _restgpr_27(void);
extern const f32 lbl_1_rodata_8BF0;
extern const f32 lbl_1_rodata_8BF4;
extern const f32 lbl_1_rodata_8BF8;
extern const f32 lbl_1_rodata_8BFC;
extern void fn_1_131B90(void);
extern void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height);
extern const f32 lbl_1_rodata_8C00;
extern const f32 lbl_1_rodata_8C04;
extern const f32 lbl_1_rodata_8C08;
extern const f32 lbl_1_rodata_864C;
extern const f32 lbl_1_rodata_8C0C;
extern const f32 lbl_1_rodata_8C10;
extern s16 fn_1_12C930(s16 arg0);
extern u8 lbl_1_data_21078[180];
extern struct fn_1_13ABA8_lbl_1_rodata_8C14 lbl_1_rodata_8C14;
extern struct fn_1_13ABA8_lbl_1_rodata_8C2C lbl_1_rodata_8C2C;
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern s32 fn_1_13B24C(s32, s32, s32, s32, const char*);
extern u32 fn_1_13F7F8(s16, s16);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8C9C;
extern const f64 lbl_1_rodata_8CA0;
extern const f64 lbl_1_rodata_8CA8;
extern struct fn_1_13B548_lbl_1_rodata_8C78 lbl_1_rodata_8C78;
extern struct fn_1_13B548_lbl_1_rodata_8C80 lbl_1_rodata_8C80;
extern struct fn_1_13B548_lbl_1_rodata_8C84 lbl_1_rodata_8C84;
extern struct fn_1_13B548_lbl_1_rodata_8C88 lbl_1_rodata_8C88;
extern u32 lbl_1_rodata_8C7C;
extern u32 lbl_1_rodata_8C8C;
extern u32 lbl_1_rodata_8C90;
extern u32 lbl_1_rodata_8C94;
extern u32 lbl_1_rodata_8C98;
extern void fn_1_141C10(u8);
extern void fn_1_12EF80(s16 value, s16 *row, s16 *column);
extern void fn_1_140EE8(u8, int, int);
extern void fn_1_14108C(s16, s32, s32);
extern void fn_1_141614(s16);
extern void fn_1_141754(s32, s32);
extern u32 fn_1_40F34(void);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern void fn_1_141A80(s16);
extern f32 lbl_1_bss_8E3E0;
extern fn_1_13C5EC_Color lbl_1_rodata_8D80;
extern fn_1_13C5EC_Color lbl_1_rodata_8D84;
extern u32 lbl_1_rodata_8DA0;
extern u32 lbl_1_rodata_8DA4;
extern u32 lbl_1_rodata_8DA8;
extern const f32 lbl_1_rodata_8A2C;
extern const f32 lbl_1_rodata_8D94;
extern const f32 lbl_1_rodata_8DAC;
extern const f32 lbl_1_rodata_8DB0;
extern const f32 lbl_1_rodata_8DB4;
extern const f32 lbl_1_rodata_8DB8;
extern s32 fn_1_12F258(void);
extern const f32 lbl_1_rodata_8DF0;
extern const f32 lbl_1_rodata_8684;
extern u32 lbl_1_rodata_8DE8;
extern const f32 lbl_1_rodata_8DF4;
extern u32 lbl_1_rodata_8DEC;
extern int fn_1_B7E98(int index);
extern f32 lbl_1_rodata_85E8;
extern const u32 lbl_1_rodata_8DF8;
extern const f32 lbl_1_rodata_8E00;
extern const f32 lbl_1_rodata_8E04;
extern const f32 lbl_1_rodata_8E08;
extern const f32 lbl_1_rodata_8E0C;
extern const u32 lbl_1_rodata_8DFC;
extern const f32 lbl_1_rodata_8E10;
extern const f32 lbl_1_rodata_8E14;
extern const f32 lbl_1_rodata_8E1C;
extern const f32 lbl_1_rodata_8E20;
extern const f32 lbl_1_rodata_8E18;
extern const f32 lbl_1_rodata_8E24;
extern const f32 lbl_1_rodata_8E28;
extern const f32 lbl_1_rodata_8E2C;
extern const f32 lbl_1_rodata_8E30;
extern const f32 lbl_1_rodata_8E34;
extern void fn_1_128E8C(u32 unused, FnData *data);
extern void fn_1_50164();
extern void fn_1_52250(void *, void *);
extern void fn_1_1358BC(s16 arg0, s16 arg1, int arg2, s16 arg3, int unused, void* arg5, void* arg6, void* arg7, f32 arg8, f32 arg9, f32 arg10);
extern const fn_1_13EA9C_Str17 lbl_1_rodata_8E38;
extern const fn_1_13EA9C_Str29 lbl_1_rodata_8E4C;
extern const f32 lbl_1_rodata_8648;
extern const f32 lbl_1_rodata_8670;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8E6C;
extern const f32 lbl_1_rodata_8E70;
extern const f32 lbl_1_rodata_8E74;
extern const f32 lbl_1_rodata_8E78;
extern const f32 lbl_1_rodata_8E7C;
extern const f32 lbl_1_rodata_8E80;
extern const f32 lbl_1_rodata_8E84;
extern const f32 lbl_1_rodata_8E88;
extern int fn_1_8623C(void);
extern u32 fn_1_53FE4(FontDrawPacket *, u32);
extern void fn_1_4CE48(char *, f32);
extern u8 lbl_1_rodata_EB4[124];
extern f32 lbl_1_rodata_4104[59];
extern void *fn_1_986A4(void);
extern void fn_800794F0(u8 *dst, u8 *src, s32 len);
extern void fn_1_98804(Obj_1_data_27DE0 *obj);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern s16 fn_1_3F0C8(void);
extern u8 fn_1_7B074(void);
extern s32 fn_8006FDEC(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern void fn_1_9D360(void);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32 arg0, u32 arg1);
extern const f32 lbl_1_rodata_4100;
extern void *memset(void *dest, int value, u32 size);
extern u32 fn_1_584AC(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_862D4(u32 arg0, void *arg1);
extern u32 fn_1_1FB80(void *pos, u32 mask);
extern u32 fn_1_41488(u32 arg0, void *arg1);
extern void fn_1_4270C(void *arg0, u32 arg1, u32 arg2);
extern f32 lbl_1_rodata_4260[16];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D848(f32);
extern u32 lbl_1_rodata_9194[10];
extern u8 lbl_1_rodata_85AC[60];
extern const f32 lbl_1_rodata_91BC;
extern const f32 lbl_1_rodata_8D7C;
extern const f32 lbl_1_rodata_8E90;
extern const f32 lbl_1_rodata_8E9C;
extern const f32 lbl_1_rodata_8E94;
extern const f32 lbl_1_rodata_8EA0;
extern const f32 lbl_1_rodata_8E98;
extern const f32 lbl_1_rodata_8EA4;
extern const f32 lbl_1_rodata_8EA8;
extern const f32 lbl_1_rodata_8EAC;
extern const f32 lbl_1_rodata_8EB0;
extern u32 lbl_1_rodata_8F40;
extern u8 lbl_1_rodata_9018[216];
extern u8 lbl_1_rodata_90F0[96];
extern u32 lbl_801A66A8;
extern u32 lbl_1_rodata_9150;
extern u32 lbl_1_rodata_9154;
extern const f32 lbl_1_rodata_9158;
extern const f32 lbl_1_rodata_85F8;
extern const f32 lbl_1_rodata_9164;
extern const f32 lbl_1_rodata_915C;
extern const f32 lbl_1_rodata_9160;
extern const f32 lbl_1_rodata_9168;
extern const f32 lbl_1_rodata_916C;
extern u32 fn_1_4DCB8(u32 value);
extern void fn_1_4953C(s16 value);
extern u32 lbl_1_rodata_9170;
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern Tbl lbl_1_rodata_91F4;
extern const f32 lbl_1_rodata_8A24;
extern void fn_1_52718(const FontDrawPacket *packet);
extern struct S16 lbl_1_rodata_922C;
extern u32 lbl_1_rodata_923C[3];
extern struct fn_1_141A80_Copy lbl_1_rodata_9248;
extern u32 lbl_1_bss_8E424;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern const f32 lbl_1_rodata_92B8;
extern const f32 lbl_1_rodata_8D9C;
extern u8 fn_1_F8CF0(s32 shift);
extern void fn_1_49528(u32 *);
extern Word8 lbl_1_rodata_86D8;
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 value, s32 x, s32 y, s32 w, s32 h, s16 machine, s16 index);
extern s32 lbl_1_bss_8E3D0[];
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(u32 arg0, s32 arg1, s32 arg2, u32 arg3);
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(s32 arg0, s32 arg1);
extern void fn_1_134AD4(void);
extern void fn_1_13ABA8(u32 arg0);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern void fn_1_7B558(s32 arg0, s32 arg1, u32 x, u32 y, u32 w, u32 h, f32 scale);
extern void fn_1_138144(s32 arg0, s32 arg1);
extern void fn_1_13C5EC(u8 arg0);
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const u32 lbl_1_rodata_8DC0;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern void fn_1_13EE60();
extern void fn_1_13EF64(s16 x, s16 y, s16 z, StatRecord *rec, s32 image, StatColor *colorp, void *callback, f32 alpha);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern void fn_1_141360(u32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);
extern const f32 lbl_1_rodata_9208;
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern void fn_1_1375C0(u32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 r, f32 g, f32 b, f32 a);
extern void fn_1_13E080(s32 x, s32 y, u32 image, s32 height);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_7F3AC();

/* fzgx:begin fn_1_1332FC */
typedef struct {
    u32 v[8];
} Word32;


void fn_1_1332FC(s32 left, s32 top, u8 page) {
    Word32 table;
    FontDrawPacket packet;
    u32 image;
    s32 y;
    s32 j;
    s32 i;
    s32 *entry;

    table = *(Word32 *)&lbl_1_rodata_86D8;
    if (page >= 2U) {
        OSPanic((const char *)(&lbl_1_data_419E0), 0x3E9, (const char *)(&lbl_1_data_419F4));
    }

    image = 0x10000 - 0x62FD;
    y = top;
    for (i = 0; i < 5; i++) {
        packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image = image;
        fn_1_51678(&packet, packet.image, 0, 0, 8, 0x60);
        packet.x = left;
        packet.y = y;
        packet.z = lbl_1_rodata_86F8;
        fn_1_4F734(&packet);
        y += 0x60;
    }

    entry = (s32 *)((u8 *)&table + page * 0x10);
    for (j = 0; j < 4; j++) {
        packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image = image;
        fn_1_51678(&packet, packet.image, 0, 0x60, 8, 0xC);
        packet.x = left;
        packet.y = (top + *entry);
        packet.z = lbl_1_rodata_86FC;
        fn_1_4F734(&packet);
        entry++;
    }
}
/* fzgx:end fn_1_1332FC */

/* fzgx:begin fn_1_13354C */
typedef struct {
    u32 v[16];
} Defaults;

void fn_1_13354C(s32 arg0, s32 arg1, u32 arg2) {
    Defaults defaults;
    FontDrawPacket packet;
    s16 *entry;
    u32 raw;
    s32 i;
    u32 sel;
    s32 acc;
    u32 magic;

    raw = arg2;
    acc = 0;
    defaults = *(Defaults *)lbl_1_rodata_8700;

    if ((u8)arg2 >= 2) {
        OSPanic((const char *)lbl_1_data_419E0, 0x427, (const char *)lbl_1_data_41A10);
    }

    sel = raw & 0xff;
    entry = (s16 *)((u8 *)&defaults + ((raw & 0xff) << 5));
    magic = 0x10000 - 0x62f7;

    for (i = 0; i < 4; i++) {
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x10000 - 0x62f7;
        fn_1_51678(&packet, packet.image, entry[0], entry[1], entry[2], entry[3]);
        packet.x = arg0;
        packet.y = (arg1 + acc);
        acc += entry[3];
        packet.z = lbl_1_rodata_8740;
        if (sel == 1) {
            *(u32 *)((u8 *)&packet + 0x30) = 7;
        } else {
            *(u32 *)((u8 *)&packet + 0x30) = 5;
        }
        fn_1_4F734(&packet);
        entry += 4;
    }
}
/* fzgx:end fn_1_13354C */

/* fzgx:begin fn_1_133748 */
typedef struct {
    u32 v[8];
} Word8_fn_1_133748;

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
} Sp8_fn_1_133748;

typedef struct {
    u32 value[22];
} Fn139F18Data_fn_1_133748;

typedef struct StaticDispParams_fn_1_133748 {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams_fn_1_133748;

struct Struct_26F8_fn_1_133748 {
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
} PtrTab_fn_1_133748;

struct fn_1_13F8C4_lbl_801A6410_fn_1_133748 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_133748 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440_fn_1_133748 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source_fn_1_133748;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display_fn_1_133748;

struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_133748 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_133748 {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_133748 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_133748 **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry_fn_1_133748;

typedef struct fn_1_150C8C_Entry_fn_1_133748 {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry_fn_1_133748;

typedef struct fn_1_150C8C_Object_fn_1_133748 {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry_fn_1_133748 entries[1];
} fn_1_150C8C_Object_fn_1_133748;

typedef struct fn_1_150F30_StaticDisp_fn_1_133748 {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp_fn_1_133748;

typedef struct Fn14E09CValue_fn_1_133748 {
    void *value;
} Fn14E09CValue_fn_1_133748;

typedef struct Fn14E09CRef_fn_1_133748 {
    u8 pad8[8];
    Fn14E09CValue_fn_1_133748 *value;
} Fn14E09CRef_fn_1_133748;

typedef struct Fn14E09CObj_fn_1_133748 {
    u8 pad344[0x344];
    Fn14E09CRef_fn_1_133748 *ref;
} Fn14E09CObj_fn_1_133748;

typedef struct DispNode_fn_1_133748 {
    u8 pad[4];
    f32 value;
} DispNode_fn_1_133748;

typedef struct DispChildList_fn_1_133748 {
    DispNode_fn_1_133748 *child[3];
} DispChildList_fn_1_133748;

typedef struct DispObject_fn_1_133748 {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList_fn_1_133748 *children;
} DispObject_fn_1_133748;

typedef struct fn_1_151668_StaticDispEntry_fn_1_133748 {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject_fn_1_133748 *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry_fn_1_133748;

typedef struct fn_1_151668_StaticDisp_fn_1_133748 {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry_fn_1_133748 entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp_fn_1_133748;


typedef struct { s32 a[4]; } fn_1_133748_Offsets;


void fn_1_133748(s32 x, s32 y) {
    fn_1_133748_Offsets offs;
    FontDrawPacket pkt;
    s32 i;

    offs = *(fn_1_133748_Offsets *)lbl_1_rodata_8744;
    for (i = 0; i < 6; i++) {
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x9D03;
        fn_1_51678(&pkt, pkt.image, 0, 0, 8, 96);
        pkt.x = (x + i * 96);
        pkt.y = y;
        pkt.z = 200.0f;
        pkt.rotation_z = -0x4000;
        pkt.flags = 0x100000;
        fn_1_4F734(&pkt);
    }
    for (i = 0; i < 4; i++) {
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x9D03;
        fn_1_51678(&pkt, pkt.image, 0, 96, 8, 12);
        pkt.x = (x + offs.a[i] - 85);
        pkt.y = y;
        pkt.z = 180.0f;
        pkt.rotation_z = -0x4000;
        pkt.flags = 0x100000;
        fn_1_4F734(&pkt);
    }
}
/* fzgx:end fn_1_133748 */

/* fzgx:begin fn_1_133968 */
typedef struct {
    s16 v[9];
} IdTable;


void fn_1_133968(void) {
    IdTable ids;
    FontDrawPacket packet;
    u32 i;

    ids = *(IdTable *)lbl_1_rodata_8754;

    for (i = 0; i < 9; i++) {
        packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image = (0x10000 - 26096);
        packet.x = ids.v[i];
        packet.y = lbl_1_rodata_8768;
        packet.z = lbl_1_rodata_876C;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_133968 */

/* fzgx:begin fn_1_133A8C */
void fn_1_133A8C(void) {
    FontDrawPacket packet;
    s16 result;

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = (0x10000 - 0x6300);
    result = fn_1_486C4(packet.image);
    fn_1_51678(&packet, packet.image, 0, 0, 0x14, result);
    packet.x = lbl_1_rodata_8770;
    packet.y = lbl_1_rodata_8774;
    packet.z = lbl_1_rodata_86FC;
    *(u32 *)((u8 *)&packet + 0x30) = 0xa;
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = (0x10000 - 0x6300);
    result = fn_1_486C4(packet.image);
    fn_1_51678(&packet, packet.image, 0x32, 0, 0x12, result);
    packet.x = lbl_1_rodata_8778;
    packet.y = lbl_1_rodata_8774;
    packet.z = lbl_1_rodata_86FC;
    *(u32 *)((u8 *)&packet + 0x30) = 0xa;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_133A8C */

/* fzgx:begin fn_1_133BD8 */
typedef union {
    u32 raw[22];
    struct {
        s32 value;
        f32 x;
        f32 y;
        f32 z;
        u8 pad[32];
        s32 count;
    } obj;
} Local;

void fn_1_133BD8(void) {
    Local local;
    s16 result;

    local = *(Local *)lbl_1_rodata_26F8;
    local.obj.value = 0x9d00;
    result = fn_1_486C4(0x9d00);
    fn_1_51678( (FontDrawPacket*)(&local.obj.value), local.obj.value, 0, 0, 0x14, result);
    local.obj.x = lbl_1_rodata_8770;
    local.obj.y = lbl_1_rodata_8774;
    local.obj.z = lbl_1_rodata_86FC;
    local.obj.count = 10;
    fn_1_4F734( (FontDrawPacket*)(&local.obj.value));

    local = *(Local *)lbl_1_rodata_26F8;
    local.obj.value = 0x9d00;
    result = fn_1_486C4(0x9d00);
    fn_1_51678( (FontDrawPacket*)(&local.obj.value), local.obj.value, 0x14, 0, 0x1c, result);
    local.obj.x = lbl_1_rodata_8658;
    local.obj.y = lbl_1_rodata_8774;
    local.obj.z = lbl_1_rodata_86FC;
    local.obj.count = 10;
    fn_1_4F734( (FontDrawPacket*)(&local.obj.value));

    local = *(Local *)lbl_1_rodata_26F8;
    local.obj.value = 0x9d00;
    result = fn_1_486C4(0x9d00);
    fn_1_51678( (FontDrawPacket*)(&local.obj.value), local.obj.value, 0x32, 0, 0x12, result);
    local.obj.x = lbl_1_rodata_8778;
    local.obj.y = lbl_1_rodata_8774;
    local.obj.z = lbl_1_rodata_86FC;
    local.obj.count = 10;
    fn_1_4F734( (FontDrawPacket*)(&local.obj.value));
}
/* fzgx:end fn_1_133BD8 */

/* fzgx:begin fn_1_133DBC */
void fn_1_133DBC(void* arg0) {
    fn_1_133E04( (s32)(void*)(arg0), 0);
}
/* fzgx:end fn_1_133DBC */

/* fzgx:begin fn_1_133DE0 */
void fn_1_133DE0(void* arg0) {
    fn_1_133E04( (s32)(void*)(arg0), 1);
}
/* fzgx:end fn_1_133DE0 */

/* fzgx:begin fn_1_133E04 */


#pragma section code_type ".fzgxpool"
/* primes the TU conversion constants in retail order (signed before unsigned) */
f32 fzgx_pool_conversions(s32 a, u32 b) {
    return (f32)a + b;
}
#pragma section code_type ".text"

#pragma pool_data off
void fn_1_133E04(s32 arg0, s32 arg1) {
    u32 *p_lbl_1_bss_38460;
    const f32 *p_lbl_1_rodata_87E8;
    const f32 *p_lbl_1_rodata_87E4;
    const f64 *p_lbl_1_rodata_8810;
    u32 v4;
    u32 v6;
    u32 v12;
    f32 v14;
    f32 v15;
    u32 v16;
    f32 v20;
    f32 v19;
    f64 v18;
    s32 v21;
    s32 v23;
    f32 v22;
    u32 v24;
    f64 loopCount;
    f32 v31;
    f32 v26;
    f32 v25;
    u32 v27;
    f32 v29;
    s32 v32;
    f32 v33;
    u32 v35;
    f32 v36;
    u32 v37;
    f32 v39;
    f32 v40;
    s32 v42;
    u32 v50;
    u32 v51;
    u32 v54;
    u32 v58;
    u32 v62;
    FontDrawPacket loc_90;
    struct {
        f32 matrix[3][4];
        f32 matrixPad;
        Sig_fn_8006F038_Vec3 cameraPos;
        Sig_fn_8006F038_Vec3 cameraTarget;
        u32 cameraPad[2];
    } scratch;
#define loc_70 scratch.cameraPos
#define loc_7C scratch.cameraTarget
#define loc_3C scratch.matrix
    f32 loc_30[3];
    f32 loc_24[3];
    u32 loc_18[3];
    f32 loc_14;
    f32 loc_10;
    f32 loc_C;
    f32 loc_8;
#define camera_pos (&loc_70)
#define camera_target (&loc_7C)
    /* frame */
    f32 t25;
    s32 t77;
#define v39 loopCount
#define v33 v22
#define v36 v25
    loc_70 = *(Sig_fn_8006F038_Vec3 *)&lbl_1_rodata_877C;
    loc_7C = *(Sig_fn_8006F038_Vec3 *)&lbl_1_rodata_8788;
    fn_8006F038((Sig_fn_8006F038_Vec3 *)camera_pos, (Sig_fn_8006F038_Vec3 *)camera_target, 0);
    lbl_8006DCDC();
    fn_80074D08(0);
    fn_1_A714C(&loc_14, &loc_10, &loc_C, &loc_8);
    fn_1_A7024(lbl_1_rodata_87A4, lbl_1_rodata_87A8, lbl_1_rodata_87AC, lbl_1_rodata_87B0);
    fn_1_56000(0, 7, 0);
    p_lbl_1_bss_38460 = lbl_1_bss_38460;
    loc_30[0] = lbl_1_rodata_861C;
    loc_30[1] = lbl_1_rodata_87B4;
    loc_30[2] = lbl_1_rodata_86D0;
    loc_24[0] = loc_24[1] = loc_24[2] = lbl_1_rodata_87B8;
    v4 = *(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 8);
    *(Sig_fn_8006F038_Vec3 *)loc_18 = *(Sig_fn_8006F038_Vec3 *)((u8 *)v4 + 8);
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(lbl_1_rodata_863C);
    v6 = lbl_801A66A0;
    lbl_8006D7F4((v6 % -3000) / lbl_1_rodata_87BC, (v6 % 4000) / lbl_1_rodata_87C0, lbl_1_rodata_861C);
    lbl_8006DB74(loc_3C);
    fn_800749B0(0, loc_3C);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 8));
    loc_30[0] = lbl_1_rodata_861C;
    loc_30[1] = lbl_1_rodata_87B4;
    loc_30[2] = lbl_1_rodata_86D0;
    loc_24[0] = loc_24[1] = loc_24[2] = lbl_1_rodata_87C4;
    v12 = *(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 16);
    *(Sig_fn_8006F038_Vec3 *)loc_18 = *(Sig_fn_8006F038_Vec3 *)((u8 *)v12 + 8);
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(lbl_1_rodata_863C);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 16));
    v14 = lbl_1_rodata_87B8;
    v15 = lbl_1_rodata_87C8;
    loc_70.y = v14;
    loc_70.z = v15;
    loc_7C.y = lbl_1_rodata_87CC;
    fn_8006F038((Sig_fn_8006F038_Vec3 *)camera_pos, (Sig_fn_8006F038_Vec3 *)camera_target, 0);
    lbl_8006DCDC();
    t25 = fn_1_A6FE8();
    fn_1_A7024(lbl_1_rodata_87D0, t25, lbl_1_rodata_87AC, lbl_1_rodata_87B0);
    loc_30[0] = lbl_1_rodata_861C;
    loc_30[1] = lbl_1_rodata_87D4;
    loc_24[1] = loc_24[0] = lbl_1_rodata_87D8;
    loc_24[2] = lbl_1_rodata_87AC;
    v16 = *(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8));
    *(Sig_fn_8006F038_Vec3 *)loc_18 = *(Sig_fn_8006F038_Vec3 *)((u8 *)v16 + 8);
    if (arg1 != 0) {
    v18 = lbl_1_rodata_87DC;
    } else {
    v18 = lbl_1_rodata_8678;
    }
    v19 = lbl_1_rodata_87E0;
    v21 = v19;
    v20 = 4.0f;
    v23 = 0;
    while ((f32)v23 < v18) {
    v24 = lbl_801A66A0;
    v22 = (v23 - 5);
    v25 = v22 * v20;
    v22 = (v24 % v21);
    v22 = v22 / v19;
    v22 = v20 * v22;
    v22 = v25 - v22;
    loc_30[2] = v22;
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(0.25f);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8)));
    v23++;
    }
    {
/* The final band has its own count. */
#define loopCount v18
#define v29 v19
#define v31 v20
#define v40 v19
    loc_30[0] = lbl_1_rodata_87EC;
    loc_30[1] = lbl_1_rodata_87F0;
    loc_24[2] = loc_24[1] = loc_24[0] = lbl_1_rodata_87B8;
    v27 = *(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 24);
    *(Sig_fn_8006F038_Vec3 *)loc_18 = *(Sig_fn_8006F038_Vec3 *)((u8 *)v27 + 8);
    if (arg1) {
    loopCount = lbl_1_rodata_86C4;
    } else {
    loopCount = lbl_1_rodata_8770;
    }
    v29 = 64.0f;
    v32 = v29;
    v31 = 3.2f;
    v26 = 0.015625f;
    p_lbl_1_rodata_87E8 = &lbl_1_rodata_87E8;
    for (v23 = 0; (f32)v23 < loopCount; v23++) {
    v35 = lbl_801A66A0;
    v36 = (v23 - 5) * v31;
    v33 = (v35 % v32) / v29;
    loc_30[2] = v36 - (v31 * v33);
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(0.25f);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 24));
    loc_30[0] = -loc_30[0];
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(0.25f);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 24));
    loc_30[1] = -loc_30[1];
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(0.25f);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 24));
    loc_30[0] = -loc_30[0];
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(0.25f);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 24));
    }
#undef v39
#define v39 v19
#undef v40
#define v40 v20
    loc_30[0] = lbl_1_rodata_861C;
    loc_30[1] = lbl_1_rodata_8800;
    loc_24[0] = lbl_1_rodata_8804;
    loc_24[1] = lbl_1_rodata_8808;
    loc_24[2] = lbl_1_rodata_85F0;
    v37 = *(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 32);
    *(Sig_fn_8006F038_Vec3 *)loc_18 = *(Sig_fn_8006F038_Vec3 *)((u8 *)v37 + 8);
    if (arg1) {
    v39 = lbl_1_rodata_861C;
    } else {
    v39 = lbl_1_rodata_8678;
    }
    v40 = 160.0f;
    p_lbl_1_rodata_87E4 = &lbl_1_rodata_87E4;
    p_lbl_1_rodata_8810 = &lbl_1_rodata_8810;
    v42 = v40;
    v23 = 0;
    while (v23 < v39) {
    loc_30[2] = (v23 - 5) * fn_80088598(*p_lbl_1_rodata_87E4, *p_lbl_1_rodata_8810) - ((lbl_801A66A0 % v42) / v40) * fn_80088598(*p_lbl_1_rodata_87E4, *p_lbl_1_rodata_8810);
/* Preserve the two separately rounded double products. */
    lbl_8006DCA4();
    lbl_8006E0A4(loc_30);
    lbl_8006E13C(loc_24);
    lbl_8006E0C8(loc_18);
    fn_80072558();
    fn_1_55FF0(0.25f);
    fn_1_556B8((void *)*(u32 *)((u8 *)*(u32 *)(p_lbl_1_bss_38460[1] + 8) + 32));
    v23++;
    }
    }
    fn_1_56000(1, 3, 1);
    fn_1_A7024(loc_14, loc_10, loc_C, loc_8);
    if (arg0 != 0) {
    loc_90 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    *(f32 *)((u8 *)&loc_90 + 4) = lbl_1_rodata_8658;
    v50 = (0x10000 - 26085);
    v51 = (0x100000 + 7);
    *(u32 *)((u8 *)&loc_90 + 0) = v50;
    *(f32 *)((u8 *)&loc_90 + 8) = lbl_1_rodata_8818;
    *(f32 *)((u8 *)&loc_90 + 12) = lbl_1_rodata_881C;
    loc_90.flags = v51;
    *(u32 *)((u8 *)&loc_90 + 56) = lbl_1_rodata_8794;
    *(f32 *)((u8 *)&loc_90 + 44) = lbl_1_rodata_85F0;
    fn_1_4E724( (void *)((FontDrawPacket *)&loc_90));
    loc_90 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    v54 = (0x10000 - 26085);
    *(u32 *)((u8 *)&loc_90 + 0) = v54;
    *(f32 *)((u8 *)&loc_90 + 4) = lbl_1_rodata_8658;
    *(f32 *)((u8 *)&loc_90 + 8) = lbl_1_rodata_8818;
    *(f32 *)((u8 *)&loc_90 + 12) = lbl_1_rodata_881C;
    loc_90.flags = 0x180000;
    *(u32 *)((u8 *)&loc_90 + 56) = lbl_1_rodata_8798;
    *(f32 *)((u8 *)&loc_90 + 44) = lbl_1_rodata_85F0;
    fn_1_4E724( (void *)((FontDrawPacket *)&loc_90));
    loc_90 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    v58 = (0x10000 - 26085);
    *(u32 *)((u8 *)&loc_90 + 0) = v58;
    *(f32 *)((u8 *)&loc_90 + 4) = lbl_1_rodata_8658;
    *(f32 *)((u8 *)&loc_90 + 8) = lbl_1_rodata_8820;
    *(f32 *)((u8 *)&loc_90 + 12) = lbl_1_rodata_881C;
    loc_90.flags = 7;
    *(u32 *)((u8 *)&loc_90 + 56) = lbl_1_rodata_879C;
    *(f32 *)((u8 *)&loc_90 + 44) = lbl_1_rodata_85F0;
    fn_1_4E724( (void *)((FontDrawPacket *)&loc_90));
    loc_90 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    v62 = (0x10000 - 26085);
    *(u32 *)((u8 *)&loc_90 + 0) = v62;
    *(f32 *)((u8 *)&loc_90 + 4) = lbl_1_rodata_8658;
    *(f32 *)((u8 *)&loc_90 + 8) = lbl_1_rodata_8820;
    *(f32 *)((u8 *)&loc_90 + 12) = lbl_1_rodata_881C;
    loc_90.flags = 0x80000;
    *(u32 *)((u8 *)&loc_90 + 56) = lbl_1_rodata_87A0;
    *(f32 *)((u8 *)&loc_90 + 44) = lbl_1_rodata_85F0;
    fn_1_4E724( (void *)((FontDrawPacket *)&loc_90));
    }
    t77 = ((s32)fn_1_A5DC4());
    if ((s8)t77 != 0) {
    fn_1_52088();
    /* full-screen image stretched to 640x480 */
    loc_90 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    loc_90.image = 18;
    loc_90.scale_x *= lbl_1_rodata_8674 / fn_1_48690(18);
    loc_90.scale_y *= lbl_1_rodata_8824 / fn_1_486C4(18);
    loc_90.alpha = lbl_1_rodata_8808;
    loc_90.color[0] = 34;
    loc_90.color[1] = 34;
    loc_90.color[2] = 98;
    loc_90.z = lbl_1_rodata_8828;
    fn_1_4E724( (void *)(FontDrawPacket *)(&loc_90));
    fn_1_52070(320);
    }
}
/* fzgx:end fn_1_133E04 */

/* fzgx:begin fn_1_134A4C */
void fn_1_134A4C(void) {
    StaticDispParams params;

    params = (*((StaticDispParams *)&lbl_1_rodata_26F8));
    params.id = 0x9a14;
    params.x = lbl_1_rodata_882C;
    params.y = lbl_1_rodata_8830;
    params.z = lbl_1_rodata_8834;
    params.count = 10;
    fn_1_4F734( (FontDrawPacket*)(&params.id));
}
/* fzgx:end fn_1_134A4C */

/* fzgx:begin fn_1_134AD4 */

void fn_1_134AD4(void) {
	FontDrawPacket p;

	p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
	p.image = 0x10000 - 0x65FC;
	p.x = lbl_1_rodata_861C;
	p.y = lbl_1_rodata_861C;
	p.z = lbl_1_rodata_85F4;
	fn_1_4F734(&p);

	p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
	p.image = 0x10000 - 0x65FB;
	p.x = lbl_1_rodata_8658;
	p.y = lbl_1_rodata_861C;
	p.z = lbl_1_rodata_8838;
	fn_1_4F734(&p);

	p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
	p.image = 0x10000 - 0x65FF;
	p.x = lbl_1_rodata_861C;
	p.y = lbl_1_rodata_883C;
	p.z = lbl_1_rodata_8840;
	fn_1_4F734(&p);

	if ((s8)fn_1_A5DC4() != 0) {
		p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
		p.image = 0x10000 - 0x65FA;
		fn_1_51678(&p, p.image, 0, 0,
			((((u32)fn_1_48690(p.image)) >> 1) & 0x7FFF),
			fn_1_486C4(p.image));
		p.x = lbl_1_rodata_8844;
		p.y = lbl_1_rodata_861C;
		p.z = lbl_1_rodata_8848;
		fn_1_4F734(&p);

		p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
		p.image = 0x10000 - 0x65FA;
		fn_1_51678(&p, p.image,
			((((u32)fn_1_48690(p.image)) >> 1) & 0x7FFF), 0,
			((((u32)fn_1_48690(p.image)) >> 1) & 0x7FFF),
			fn_1_486C4(p.image));
		p.x = lbl_1_rodata_884C;
		p.y = lbl_1_rodata_861C;
		p.z = lbl_1_rodata_8850;
		p.flags = 7;
		fn_1_4F734(&p);

		p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
		p.image = 0x10000 - 0x65FD;
		fn_1_51678(&p, p.image, 0, 0,
			((((u32)fn_1_48690(p.image)) >> 1) & 0x7FFF),
			fn_1_486C4(p.image));
		p.x = lbl_1_rodata_8844;
		p.y = lbl_1_rodata_8854;
		p.z = lbl_1_rodata_8858;
		p.scale_y = p.scale_y * lbl_1_rodata_885C;
		fn_1_4F734(&p);

		p = (*((FontDrawPacket *)&lbl_1_rodata_26F8));
		p.image = 0x10000 - 0x65FD;
		fn_1_51678(&p, p.image,
			((((u32)fn_1_48690(p.image)) >> 1) & 0x7FFF), 0,
			((((u32)fn_1_48690(p.image)) >> 1) & 0x7FFF),
			fn_1_486C4(p.image));
		p.x = lbl_1_rodata_884C;
		p.y = lbl_1_rodata_8854;
		p.z = lbl_1_rodata_8858;
		p.scale_y = p.scale_y * lbl_1_rodata_885C;
		p.flags = 7;
		fn_1_4F734(&p);
	}
}
/* fzgx:end fn_1_134AD4 */

/* fzgx:begin fn_1_134EE4 noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

void fn_1_134EE4(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    FontDrawPacket packet;
    s16 temp_r21;
    s16 temp_r22;
    FontDrawPacket * lab_t0;
    FontDrawPacket * lab_t0_;

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (arg1 != 0) ? 0x9E03 : 0x9B00;
    packet.x = lbl_1_rodata_861C;
    packet.y = lbl_1_rodata_8890;
    packet.z = lbl_1_rodata_8894;
    fn_1_4F734(&packet);
    if (arg0 != 0) {
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9C02;
        packet.x = ((s8)fn_1_A5DC4() ? 0x48 : 0x58);
        packet.y = lbl_1_rodata_8898;
        packet.z = lbl_1_rodata_889C;
        *(u32 *)((u8 *)&packet + 0x30) = 0xA;
        fn_1_4F734(&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9C03;
        packet.x = lbl_1_rodata_8674 - ((s8)fn_1_A5DC4() ? 0x48 : 0x58);
        packet.y = lbl_1_rodata_8898;
        packet.z = lbl_1_rodata_889C;
        *(u32 *)((u8 *)&packet + 0x30) = 0xA;
        fn_1_4F734(&packet);
        if (farg0 < lbl_1_rodata_85F0) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C00;
            packet.x = (((s8)fn_1_A5DC4() ? 0x48 : 0x58) - 0x39);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A0;
            *(u32 *)((u8 *)&packet + 0x30) = 9;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C01;
            packet.x = (((s8)fn_1_A5DC4() ? 0x48 : 0x58) + 0x3A);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A4;
            *(u32 *)((u8 *)&packet + 0x30) = 0xB;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C00;
            packet.x = lbl_1_rodata_88A8 +
                       ((lbl_1_rodata_8674 - ((s8)fn_1_A5DC4() ? 0x48 : 0x58)) -
                        lbl_1_rodata_88AC);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A0;
            *(u32 *)((u8 *)&packet + 0x30) = 9;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C01;
            packet.x = lbl_1_rodata_88B0 +
                       ((lbl_1_rodata_8674 - ((s8)fn_1_A5DC4() ? 0x48 : 0x58)) -
                        lbl_1_rodata_88AC);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A4;
            *(u32 *)((u8 *)&packet + 0x30) = 0xB;
            fn_1_4F734(&packet);
        }
    }
    if ((s8)fn_1_A5DC4() != 0) {
        if (arg2 != 0) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            temp_r21 = fn_1_486C4(0x9B02);
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, 0, (fn_1_48690(packet.image) >> 1) & 0x7FFF, temp_r21);
            packet.x = lbl_1_rodata_8844;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, 0, 0xA, fn_1_486C4(0x9B02));
            packet.x = lbl_1_rodata_861C;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            temp_r22 = fn_1_486C4(0x9B02);
            temp_r21 = (fn_1_48690(packet.image) >> 1) & 0x7FFF;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, (fn_1_48690(packet.image) >> 1) & 0x7FFF, 0, temp_r21, temp_r22);
            packet.x = lbl_1_rodata_884C;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            *(u32 *)((u8 *)&packet + 0x30) = 7;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, 0, 0xA, fn_1_486C4(0x9B02));
            packet.x = lbl_1_rodata_8674;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            *(u32 *)((u8 *)&packet + 0x30) = 7;
            fn_1_4F734(&packet);
        }
{
    s32 var_r26;
    s32 var_r25;
    struct { u32 * value; } var_r28;
    struct { u32 * value; } var_r27;
        u32 sp20[6] = {0x0, 0x18, 0x18, 0x18, 0x18, 0x28};
        u32 sp8[6] = {0x18, 0x10, 0x10, 0x10, 0x10, 0x20};
        var_r25 = 0x152;
        var_r26 = 0;
        var_r28.value = sp8;
        var_r27.value = sp20;
        for (; var_r26 < 6; var_r26++) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B01;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, var_r27.value[0], (fn_1_48690(packet.image) >> 1) & 0x7FFF, var_r28.value[0]);
            packet.x = lbl_1_rodata_8844;
            packet.y = var_r25;
            packet.z = lbl_1_rodata_88B8;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B01;
            arg0 = (s16)((fn_1_48690(packet.image) >> 1) & 0x7FFF);
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, (fn_1_48690(packet.image) >> 1) & 0x7FFF, var_r27.value[0], arg0, var_r28.value[0]);
            packet.x = lbl_1_rodata_884C;
            packet.y = var_r25;
            packet.z = lbl_1_rodata_88B8;
            *(u32 *)((u8 *)&packet + 0x30) = 7;
            fn_1_4F734(&packet);
            var_r27.value += 1;
            var_r25 += var_r28.value[0];
            var_r28.value += 1;
        }
}
        fn_1_52070(0x140);
    }
}
/* fzgx:end fn_1_134EE4 */

/* fzgx:begin fn_1_135894 noprologue */
void fn_1_135894(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8) { fn_1_135D7C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, lbl_1_rodata_87DC);
}
/* fzgx:end fn_1_135894 */

/* fzgx:begin fn_1_1358BC noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct fn_1_1358BC_Table { u32 image[41]; } fn_1_1358BC_Table;

extern fn_1_1358BC_Table lbl_1_rodata_88BC;
extern FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_8960;
extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_494DC(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern char* fn_1_14FEAC(void*, void*, void*, void*, int);
extern void fn_1_4CF3C(f32, void*, ...);

void fn_1_1358BC(s16 arg0, s16 arg1, int arg2, s16 arg3, int unused, void* arg5,
                 void* arg6, void* arg7, f32 arg8, f32 arg9, f32 arg10) {
    u32 buf[8];
    FontDrawPacket packet;
    fn_1_1358BC_Table table;
    u32 index;

    table = lbl_1_rodata_88BC;

    if (arg3 >= 41 || arg3 < 0) {
        fn_1_49410();
        switch (arg2) {
        case 5: fn_1_495C8(0); break;
        case 9: fn_1_495C8(8); break;
        case 13: fn_1_495C8(0x10); break;
        case 6: fn_1_495C8(1); break;
        case 10: fn_1_495C8(9); break;
        case 14: fn_1_495C8(0x11); break;
        case 7: fn_1_495C8(2); break;
        case 11: fn_1_495C8(0xa); break;
        case 15: fn_1_495C8(0x12); break;
        }
        fn_1_494DC(0x23);
        fn_1_496FC(arg0, arg1);
        fn_1_4954C(arg10);
        fn_1_4955C(arg8, arg9);
        fn_1_4962C();
        {
            const f32* scale = &lbl_1_rodata_8960;
            fn_1_4CF3C(*scale * arg8, "%s\n",
                       fn_1_14FEAC(arg5, arg6, arg7, buf, 0));
        }
    } else {
        packet = lbl_1_rodata_26F8;
        if (arg3 < 0) {
            index = 0;
        } else {
            index = ((u32)arg3 > 40) ? 40 : arg3;
        }
        packet.image = table.image[index];
        packet.x = arg0;
        packet.y = arg1;
        packet.z = arg10;
        packet.scale_x = packet.scale_x * arg8;
        packet.scale_y = packet.scale_y * arg9;
        packet.flags = arg2;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_1358BC */

/* fzgx:begin fn_1_135B80 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_494DC(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern char* fn_1_14FEAC(void*, void*, void*, void*, int);
extern char* fn_1_7F49C(s16, int, void*);
extern void fn_1_4CF3C(f32, void*, ...);

void fn_1_135B80(f32 scale, f32 arg7, f32 arg8, s16 x, s16 y, u32 mode, s16 index,
                 u32 unused, void* a, void* b, void* c) {
    u8 buf1[0x20];
    u8 buf2[0x40];
    char* str;

    fn_1_49410();
    switch (mode) {
    case 5:
        fn_1_495C8(0);
        break;
    case 9:
        fn_1_495C8(8);
        break;
    case 13:
        fn_1_495C8(0x10);
        break;
    case 6:
        fn_1_495C8(1);
        break;
    case 10:
        fn_1_495C8(9);
        break;
    case 14:
        fn_1_495C8(0x11);
        break;
    case 7:
        fn_1_495C8(2);
        break;
    case 11:
        fn_1_495C8(0xa);
        break;
    case 15:
        fn_1_495C8(0x12);
        break;
    }
    fn_1_494DC(0x1c);
    fn_1_496FC(x, y);
    fn_1_4954C(arg8);
    fn_1_4955C(scale, arg7);
    fn_1_4962C();

    if (index >= 0x29 || index < 0) {
        fn_1_4CF3C((lbl_1_rodata_8960 * scale), "%s\n", (str = fn_1_14FEAC(a, b, c, buf1, 0)));
    } else {
        fn_1_4CF3C((lbl_1_rodata_8960 * scale), "%s\n", (str = fn_1_7F49C(index, 0, buf2)));
    }
}
/* fzgx:end fn_1_135B80 */

/* fzgx:begin fn_1_135D7C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

/* 164-byte table of 41 image ids. */
typedef struct SelImageTable {
    u32 image[41];
} SelImageTable;

/* FontDrawPacket layout as this unit's template stores it: the word at 0x30
 * receives the integer format code. */
typedef struct SelImagePacket {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 format;
    u32 flags;
    u8 color[4], color_add[4];
    u32 unk_40;
    u16 width, height;
    void* pixels;
    void* secondary;
    void* vertex_callback;
    u32 unk_54;
} SelImagePacket;

/* 0x81C0-byte machine entry */
typedef struct SelMachineEntry {
    u32 flags;
    u8 pad_4[0x819C];
    u8 image_index;
    u8 pad_81A1[3];
    u8 body;
    u8 pad_81A5[7];
    u8 cockpit;
    u8 pad_81AD[7];
    u8 booster;
    u8 pad_81B5[0xB];
} SelMachineEntry;

extern SelImageTable lbl_1_rodata_8964;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_8960;
extern void* fn_1_12F118(void);
extern u8* fn_1_36AD0(void);
extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_494DC(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern void fn_1_4CF3C(f32, void*, ...);

void fn_1_135D7C(s16 x, s16 y, u32 format, s16 index, void* arg4, s16 slot, int arg6,
                 f32 scale_x, f32 scale_y, f32 z) {
    SelMachineEntry* entry;
    u8* base;
    u8 name[32];
    SelImagePacket packet;
    SelImageTable images;
    s32 i;

    images = lbl_1_rodata_8964;

    if (index < 0) return;
    if (arg6 != 0) return;

    if (index >= 0x29) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            entry = (SelMachineEntry*)base + slot;
        } else {
            entry = (SelMachineEntry*)base + (index - 0x29);
        }
        if (!(entry->flags & 0x40000000)) {
            index = entry->image_index;
            packet = *(SelImagePacket *)&lbl_1_rodata_26F8;
            i = index < 0 ? 0 : ((u32)index > 40 ? 40 : index);
            packet.image = images.image[i];
            packet.x = x;
            packet.y = y;
            packet.z = z;
            packet.scale_x *= scale_x;
            packet.scale_y *= scale_y;
            packet.format = format;
            fn_1_4F734((FontDrawPacket*)&packet);
        } else {
            fn_1_49410();
            switch (format) {
            case 5: fn_1_495C8(0); break;
            case 9: fn_1_495C8(8); break;
            case 13: fn_1_495C8(0x10); break;
            case 6: fn_1_495C8(1); break;
            case 10: fn_1_495C8(9); break;
            case 14: fn_1_495C8(0x11); break;
            case 7: fn_1_495C8(2); break;
            case 11: fn_1_495C8(0xA); break;
            case 15: fn_1_495C8(0x12); break;
            }
            fn_1_494DC(0x23);
            fn_1_496FC(x, y);
            fn_1_4954C(z);
            fn_1_4955C(scale_x, scale_y);
            fn_1_4962C();
            {
                const f32* scale = &lbl_1_rodata_8960;
                fn_1_4CF3C(*scale * scale_x, "%s\n",
                           fn_1_14FEAC((void *)entry->body, (void *)entry->cockpit, (void *)entry->booster, name, (int)arg4));
            }
        }
    } else {
        packet = *(SelImagePacket *)&lbl_1_rodata_26F8;
        i = index < 0 ? 0 : ((u32)index > 40 ? 40 : index);
        packet.image = images.image[i];
        packet.x = x;
        packet.y = y;
        packet.z = z;
        packet.scale_x *= scale_x;
        packet.scale_y *= scale_y;
        packet.format = format;
        fn_1_4F734((FontDrawPacket*)&packet);
    }
}
/* fzgx:end fn_1_135D7C */

/* fzgx:begin fn_1_136174 noprologue */
#include "types.h"

typedef struct Fn1_136174_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn1_136174_Color;

typedef struct Fn1_136174_Entry {
    u32 flags;
    u8 pad_4[0x819C];
    u8 glyph;
    u8 pad_81A1[0x3];
    u8 unk_81A4;
    u8 pad_81A5[0x7];
    u8 unk_81AC;
    u8 pad_81AD[0x7];
    u8 unk_81B4;
    u8 pad_81B5[0xB];
} Fn1_136174_Entry;

extern char lbl_1_data_41A30[]; /* "%s\n" */
extern char lbl_1_data_41AB8[]; /* "?????\n" */
extern const Fn1_136174_Color lbl_1_rodata_8A08; /* {0xB7, 0xCE, 0xEA, 0xFF} */
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(Fn1_136174_Color *);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(s32);
extern void fn_1_4CF3C(f32, const char *, ...);
extern Fn1_136174_Entry *fn_1_12F118(void);
extern Fn1_136174_Entry *fn_1_36AD0(void);
extern char *fn_1_7F49C(s16, s16, char *);
extern void fn_1_4962C(void);
extern char *fn_1_14FEAC(u8, u8, u8, char *, s16);

void fn_1_136174(s16 x, s16 y, s32 type, s16 glyph, s16 id, s16 slot, s32 unknown, f32 scale_x, f32 scale_y) {
    char buf[32];
    Fn1_136174_Entry *base;
    Fn1_136174_Entry *entry;

    if (id == 0) {
        return;
    }
    if (glyph < 0) {
        return;
    }
    fn_1_49410();
    fn_1_496FC(x, y);
    fn_1_4955C(scale_x, scale_y);
    {
        Fn1_136174_Color color = lbl_1_rodata_8A08;

        fn_1_49514(&color);
    }
    fn_1_49738(fn_1_5233C);
    fn_1_49748(1.0f);
    fn_1_4954C(50.0f);
    fn_1_495C8(type);
    if (unknown) {
        fn_1_4CF3C(122.0f, lbl_1_data_41AB8);
        return;
    }
    if (glyph >= 0x29) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            entry = &base[slot];
        } else {
            entry = &base[glyph - 0x29];
        }
        if (!(entry->flags & 0x40000000)) {
            fn_1_4CF3C(122.0f, lbl_1_data_41A30, fn_1_7F49C(entry->glyph, id, buf));
            return;
        }
        fn_1_496FC(x, y);
        fn_1_4962C();
        fn_1_4CF3C(122.0f, lbl_1_data_41A30, fn_1_14FEAC(entry->unk_81A4, entry->unk_81AC, entry->unk_81B4, buf, id));
        return;
    }
    fn_1_4CF3C(122.0f, lbl_1_data_41A30, fn_1_7F49C(glyph, id, buf));
}
/* fzgx:end fn_1_136174 */

/* fzgx:begin fn_1_1363F0 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_1363F0_Copy88 { u32 a[22]; };
struct Record { u8 bytes[0x81C0]; };
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_8A10, lbl_1_rodata_8A14, lbl_1_rodata_8A18, lbl_1_rodata_8A1C;
extern const f32 lbl_1_rodata_8A20, lbl_1_rodata_861C, lbl_1_rodata_8A24, lbl_1_rodata_8A28;
extern const f32 lbl_1_rodata_8668, lbl_1_rodata_85E8, lbl_1_rodata_87AC, lbl_1_rodata_8A2C, lbl_1_rodata_863C;
extern const f64 lbl_1_rodata_8600;
struct Color { u32 rgba; };
extern struct Color lbl_1_rodata_8A0C;
struct Stat { u32 unk_0; f32 value; u8 pad[0xAC]; };
extern struct Stat lbl_1_data_28060[46];
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32, f32);
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern void fn_1_14E9E4(u8, void *);
extern void fn_1_4966C(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_136714(f32,f32,f32,s32,s32,s32,s32,void *);

void fn_1_1363F0(s16 arg0, s32 arg1, s32 arg2) {
    struct fn_1_1363F0_Copy88 packet;
    f32 metrics[4];
    struct Color color;
    struct Color color2;
    s16 value;
    s16 index;
    u8 *base;
    u8 *record;
    s16 i;
    packet = *(struct fn_1_1363F0_Copy88 *)lbl_1_rodata_26F8;
    packet.a[0] = 0x9A24;
    *(f32 *)&packet.a[1] = lbl_1_rodata_8A10;
    *(f32 *)&packet.a[2] = lbl_1_rodata_8A14;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_1_1363F0_Copy88 *)lbl_1_rodata_26F8;
    packet.a[0] = 0x9A25;
    *(f32 *)&packet.a[1] = lbl_1_rodata_8A18;
    *(f32 *)&packet.a[2] = lbl_1_rodata_8A14;
    fn_1_4F734((FontDrawPacket *)&packet);
    fn_1_49410();
    fn_1_494DC(0x22);
    fn_1_496FC(lbl_1_rodata_8A1C, lbl_1_rodata_8A14);
    index = lbl_1_bss_8B3A0.unk_C[(s16)lbl_1_bss_8B3A0.unk_9E].unk_2;
    if (index >= 41) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            s32 stride = 0x81C0;
            s32 slot = arg0;
            record = base + slot * stride;
        } else {
            record = base + (index - 41) * 0x81C0;
        }
        if (*(u32 *)record & 0x40000000) {
            value = 0;
            for (i = 0; (u32)i < 3; i++) {
                fn_1_14E9E4(record[0x81A4 + i * 8], metrics);
                value = value + metrics[1];
            }
        } else {
            value = lbl_1_data_28060[record[0x81A0]].value;
        }
    } else {
        value = lbl_1_data_28060[index].value;
    }
    color = lbl_1_rodata_8A0C;
    fn_1_4966C(lbl_1_rodata_8A20, lbl_1_rodata_861C);
    color2 = color;
    fn_1_49514(&color2.rgba);
    if (arg1) {
        fn_1_49410();
        fn_1_4955C(lbl_1_rodata_8A24, lbl_1_rodata_8A28);
        fn_1_4966C(lbl_1_rodata_8668, lbl_1_rodata_861C);
        fn_1_4954C(lbl_1_rodata_85E8);
        fn_1_4AE0C((char *)&lbl_1_data_41AC0);
    } else {
        fn_1_4AE0C((char *)&lbl_1_data_41AC8, value);
    }
    if (arg2) {
        fn_1_136714(lbl_1_rodata_87AC, lbl_1_rodata_8A2C, lbl_1_rodata_863C, value, 0x8F, 0x197, 9, 0);
    }
}
/* fzgx:end fn_1_1363F0 */

/* fzgx:begin fn_1_136714 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(s32 arg0);
extern void fn_1_4965C(s32 arg0);
extern void fn_1_495C8(s8 arg0);
extern void fn_1_496FC(f32 arg0, f32 arg1);
extern void fn_1_4954C(f32 arg0);
extern void fn_1_4955C(f32 arg0, f32 arg1);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 arg0);
extern void fn_1_49590(f32 arg0);
extern char* fn_1_13F72C(f32 arg0, s16 arg1, void* arg2);
extern void fn_1_4AE0C(const char* arg0, ...);
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern const f64 lbl_1_rodata_8600;
extern s32 lbl_801A66B4;

void fn_1_136714(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5,
                 s32 arg6, void* arg7) {
    f32 value;
    char buffer[64];

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(-2147483647 - 1);
    fn_1_4965C(2);
    fn_1_495C8(arg6);
    fn_1_496FC(arg4, arg5);
    fn_1_4954C(arg0);
    value = arg1 / lbl_1_rodata_85FC;
    fn_1_4955C(value, value);
    if (arg7 != 0) {
        fn_1_49738(arg7);
    }
    fn_1_495A0(arg2);
    switch (lbl_801A66B4) {
    case 5:
        break;
    case 0:
    default:
        fn_1_49590(lbl_1_rodata_85F0);
        fn_1_4955C(lbl_1_rodata_8A30 * arg1 / lbl_1_rodata_85FC, value);
        break;
    }
    fn_1_4AE0C(fn_1_13F72C(arg3, lbl_801A66B4, buffer));
}
/* fzgx:end fn_1_136714 */

/* fzgx:begin fn_1_1368A0 */
struct FzgxCopy_4 { u32 words[1]; };


#pragma opt_propagation off
void fn_1_1368A0(s32 arg0, s16 arg1, s32 arg2, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    FontDrawPacket loc_14;
    struct FzgxCopy_4 sp10;
    s32 spC;
    u8 loc_8[4];
    f32 temp_f29;
    f32 temp_f31;
    FontDrawPacket * lab_t0;
    f32 prod;
    f32 prod2;
    u32 quot;

    sp10 = *(const struct FzgxCopy_4 *)(&lbl_1_rodata_8A34);
    fn_1_137288(arg0, (((u8 *)(&loc_8) + 2)), (((u8 *)(&loc_8) + 1)), &loc_8, arg1);
    loc_14 = *(const FontDrawPacket *)(&lbl_1_rodata_26F8);
    loc_14.x = farg0;
    loc_14.image = 0x9A20;
    loc_14.y = farg1;
    loc_14.z = lbl_1_rodata_87DC;
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    fn_1_4F734((FontDrawPacket *)(&loc_14));
    if (arg2 != 0) {
        fn_1_49410();
        fn_1_4955C(((lbl_1_rodata_8A28) * farg3), ((lbl_1_rodata_8A28) * farg4));
        fn_1_4954C(lbl_1_rodata_85E8);
        fn_1_49738( (u32)(void*)((void (*)(void))(&fn_1_5233C)));
        fn_1_49748(lbl_1_rodata_863C);
        spC = sp10.words[0];
        fn_1_49514((u32 *)(&spC));
        prod = (farg2 * farg3);
        temp_f29 = farg0 + prod;
        prod2 = farg4;
        fn_1_496FC(temp_f29, (farg1 + prod2));
        fn_1_4AE0C((const char *)(&lbl_1_data_41ACC));
        prod2 = (lbl_1_rodata_8A38) * farg4;
        fn_1_496FC(temp_f29, (farg1 + prod2));
        fn_1_4AE0C((const char *)(&lbl_1_data_41ACC));
        prod2 = (lbl_1_rodata_8A3C) * farg4;
        fn_1_496FC(temp_f29, (farg1 + prod2));
        fn_1_4AE0C((const char *)(&lbl_1_data_41ACC));
        return;
    }
    fn_1_51564((0U), (0U), (0x10U), (0x10U), (3U), (2U));
    loc_14 = *(const FontDrawPacket *)(&lbl_1_rodata_26F8);
    prod2 = farg2 * farg3;
    temp_f31 = farg0 + prod2;
    loc_14.x = temp_f31;
    loc_14.image = 0x9A21;
    prod2 = (lbl_1_rodata_8638) * farg4;
    loc_14.y = farg1 + prod2;
    loc_14.z = lbl_1_rodata_87DC;
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    (*(u32 *)((u8 *)(&loc_14) + 56)) = sp10.words[0];
    quot = (loc_8[2] / 3);
    lab_t0 = (FontDrawPacket *)(&loc_14);
    fn_1_5158C(lab_t0, (0x9A21U), (u32)((s16) (loc_8[2] % 3)), quot);
    fn_1_4F734((FontDrawPacket *)(&loc_14));
    loc_14 = *(const FontDrawPacket *)(&lbl_1_rodata_26F8);
    loc_14.x = temp_f31;
    loc_14.image = 0x9A21;
    prod2 = (lbl_1_rodata_8A40) * farg4;
    loc_14.y = farg1 + prod2;
    loc_14.z = lbl_1_rodata_87DC;
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    (*(u32 *)((u8 *)(&loc_14) + 56)) = sp10.words[0];
    quot = (loc_8[1] / 3);
    lab_t0 = (FontDrawPacket *)(&loc_14);
    fn_1_5158C(lab_t0, (0x9A21U), (u32)((s16) (loc_8[1] % 3)), quot);
    fn_1_4F734((FontDrawPacket *)(&loc_14));
    loc_14 = *(const FontDrawPacket *)(&lbl_1_rodata_26F8);
    loc_14.x = temp_f31;
    loc_14.image = 0x9A21;
    prod2 = (lbl_1_rodata_8A44) * farg4;
    loc_14.y = farg1 + prod2;
    loc_14.z = lbl_1_rodata_87DC;
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    (*(u32 *)((u8 *)(&loc_14) + 56)) = (*((0) + sp10.words));
    quot = (loc_8[0] / 3);
    lab_t0 = (FontDrawPacket *)(&loc_14);
    fn_1_5158C(lab_t0, (0x9A21U), (u32)((s16) (loc_8[0] % 3)), quot);
    fn_1_4F734((FontDrawPacket *)(&loc_14));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1368A0 */

/* fzgx:begin fn_1_136CC4 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "font.h"

extern int fn_1_4F734(FontDrawPacket *);
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_8A4C;
extern f32 lbl_1_rodata_26F8[22];
struct ColorWord { u32 value; };
extern struct ColorWord lbl_1_rodata_8A48;
extern void fn_1_137288(s16, u8 *, u8 *, u8 *, s16);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);

void fn_1_136CC4(u32 arg0, u32 arg1, u32 arg2, s16 arg3) {
    FontDrawPacket loc_10;
    struct ColorWord color;
    u8 loc_A;
    u8 loc_9;
    u8 loc_8;
    color = lbl_1_rodata_8A48;
    fn_1_137288(arg2, &loc_A, &loc_9, &loc_8, arg3);
    fn_1_51564(0, 0, 64, 20, 1, 3);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A20;
    loc_10.x = (s32)(arg0 + 2);
    loc_10.y = (s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 9;
    fn_1_5158C(&loc_10, 0x9A20, 0, 0);
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A20;
    loc_10.x = (s32)(arg0 + 91);
    loc_10.y = (s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 9;
    fn_1_5158C(&loc_10, 0x9A20, 0, 1);
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A20;
    loc_10.x = (s32)(arg0 + 179);
    loc_10.y = (s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 9;
    fn_1_5158C(&loc_10, 0x9A20, 0, 2);
    fn_1_4F734(&loc_10);
    fn_1_51564(0, 0, 16, 16, 3, 2);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A21;
    loc_10.x = (s32)(arg0 + 74);
    loc_10.y = (s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 10;
    *(u32 *)((u8 *)&loc_10 + 56) = color.value;
    fn_1_5158C(&loc_10, 0x9A21, (loc_A % 3), (loc_A / 3));
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A21;
    loc_10.x = (s32)(arg0 + 162);
    loc_10.y = (s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 10;
    *(u32 *)((u8 *)&loc_10 + 56) = color.value;
    fn_1_5158C(&loc_10, 0x9A21, (loc_9 % 3), (loc_9 / 3));
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A21;
    loc_10.x = (s32)(arg0 + 250);
    loc_10.y = (s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 10;
    *(u32 *)((u8 *)&loc_10 + 56) = color.value;
    fn_1_5158C(&loc_10, 0x9A21, (loc_8 % 3), (loc_8 / 3));
    fn_1_4F734(&loc_10);
}
/* fzgx:end fn_1_136CC4 */

/* fzgx:begin fn_1_137288 noprologue */
#include "types.h"

extern void* fn_1_12F118(void);
extern void* fn_1_36AD0(void);
extern void fn_1_1373B0(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_137364(int index, void* value0, void* value1, void* value2, s16 selector);

// Selects the display data source and emits either its configured value or the fallback value.
void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector) {
    void* entry;

    if ((s16)index >= 0x29) {
        entry = fn_1_12F118();
        if (entry == fn_1_36AD0()) {
            entry = (char*)entry + selector * 0x81c0;
        } else {
            entry = (char*)entry + ((s16)index - 0x29) * 0x81c0;
        }

        if (*(u32*)entry & 0x40000000) {
            fn_1_1373B0(index, value0, value1, value2, selector);
        } else {
            fn_1_137364(*(u8*)((char*)entry + 0x81a0), value0, value1, value2, selector);
        }
    } else {
        fn_1_137364(index, value0, value1, value2, selector);
    }
}
/* fzgx:end fn_1_137288 */

/* fzgx:begin fn_1_137364 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/custom_memcard.h"

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);
extern void fn_80008BA8(void*, void*, s32);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_80008BA8(void*, void*, s32);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);

// Writes the indexed three-byte value, or the fallback value when the index is out of range.
void fn_1_137364(s16 arg0, u8* arg1, u8* arg2, u8* arg3) {
    if (arg0 < 0x29) {
        u32* values = (u32*)&lbl_1_data_416B8;

        *arg1 = values[arg0 * 3];
        *arg2 = values[arg0 * 3 + 1];
        *arg3 = values[arg0 * 3 + 2];
    } else {
        *arg2 = 2;
        *arg1 = 2;
        *arg3 = 2;
    }
}
/* fzgx:end fn_1_137364 */

/* fzgx:begin fn_1_1373B0 */
void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4) {
    struct { u8* value; } base;
    u8* tmp;
    s16 i;
    int level;
    struct {
        u8 unk[8];
        s16 value;
    } info;

    tmp = (u8*)fn_1_12F118();
    base.value = tmp;
    if (base.value == fn_1_36AD0()) {
        tmp = ((arg4 * 0x81c0) + base.value);
    } else {
        tmp = base.value + (arg0 - 0x29) * 0x81c0;
    }
    base.value = tmp;

    for (i = 0; i < 3u; i++) {
        fn_1_14E9E4(base.value[0x81a4], &info);
        switch (info.value) {
        case 0: level = 1; break;
        case 1: level = 1; break;
        case 2: level = 2; break;
        case 3: level = 2; break;
        case 4: level = 3; break;
        case 5: level = 3; break;
        case 6: level = 4; break;
        case 7: level = 4; break;
        case 8: level = 5; break;
        case 9: level = 5; break;
        }
        switch (i) {
        case 0: *arg1 = level; break;
        case 1: *arg3 = level; break;
        case 2: *arg2 = level; break;
        }
        base.value += 8;
    }
}
/* fzgx:end fn_1_1373B0 */

/* fzgx:begin fn_1_13750C */
void fn_1_13750C(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_1_1375C0(0, (s32)(void*)(arg0), (s32)(void*)(arg1), (u32)(void*)(arg2), (s32)(void*)(arg3));
}
/* fzgx:end fn_1_13750C */

/* fzgx:begin fn_1_137548 */
void fn_1_137548(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_1_1375C0(1, (s32)(void*)(arg0), (s32)(void*)(arg1), (u32)(void*)(arg2), (s32)(void*)(arg3));
}
/* fzgx:end fn_1_137548 */

/* fzgx:begin fn_1_137584 */
void fn_1_137584(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_1_1375C0(2, (s32)(void*)(arg0), (s32)(void*)(arg1), (u32)(void*)(arg2), (s32)(void*)(arg3));
}
/* fzgx:end fn_1_137584 */

/* fzgx:begin fn_1_1375C0 */
struct fn_1_1375C0_Copy88 { u32 a[22]; };
typedef struct {
    u32 id;
    f32 y, bgX, bgY, w, h, x, barY, barH, leftX, rightX, textX, textY;
} PanelConfig;
typedef struct { PanelConfig a[3]; } PanelConfigs;
typedef struct {
    u32 id;
    f32 x, y, z, sx, sy;
    u32 a[5];
    f32 alpha;
    u32 flags;
    u32 b[7];
    void (*callback)(void *, void *);
    f32 user;
} PanelPacket;
typedef struct { s32 a[6]; } PanelWidths;

typedef struct {
    u8 pad_0[0x54];
    f32 unk_54;
} Sig_fn_1_1392E0_Fn1392E0Arg0;
typedef struct {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x1C];
    f32 unk_24;
    f32 unk_28;
} Sig_fn_1_1392E0_Fn1392E0Arg1;

static inline f32 panel_ratio(f32 divisor, f32 numerator) {
    return numerator / divisor;
}
#pragma opt_common_subs off
void fn_1_1375C0(u32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    f32 fzgx_live;
    PanelConfigs table = *(PanelConfigs *)lbl_1_rodata_8A5C;
    PanelPacket back;
    PanelPacket draw;
    PanelWidths left;
    PanelWidths right;
    PanelConfig *p = &table.a[arg0];
    f32 pulse;
    f32 fade;
    s32 position;
    u8 value;
    back = *(PanelPacket *)lbl_1_rodata_26F8;
    back.id = p->id;
    back.x = arg1;
    back.y = arg2 + p->y;
    back.z = lbl_1_rodata_86C4;
    fn_1_4F734((FontDrawPacket *)&back);

    back = *(PanelPacket *)lbl_1_rodata_26F8;
    back.id = 18;
    back.x = arg1 + p->bgX;
    back.y = arg2 + p->bgY;
    back.z = lbl_1_rodata_87DC;
    back.sx *= (p->w - lbl_1_rodata_8B28) / fn_1_48690(18);
    back.sy *= p->h / fn_1_486C4(back.id);
    back.alpha = lbl_1_rodata_861C;
    back.flags = 0x4000000;
    back.user = arg4;
    back.callback = (void (*)(void *, void *))fn_1_1392E0;
    fn_1_4F734((FontDrawPacket *)&back);
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) arg4 = 0;
    if (fn_1_139A3C((s16)arg4)) {
        pulse = lbl_1_rodata_861C;
    } else {
        pulse = lbl_1_rodata_8808 + ((lbl_1_rodata_8664 * (lbl_1_rodata_863C + lbl_8006D188((s32)((lbl_1_rodata_8B2C * (lbl_801A66A0 % 60)) / lbl_1_rodata_8B30)))) / 2.0f);
    }
    value = (&lbl_1_bss_8B3A0.unk_9F)[arg4];
    {
        f32 first = panel_ratio(lbl_1_rodata_85F4, lbl_1_rodata_8B28 * (100 - value));
        f32 x = arg1;
        struct { f32 value; } width;
        width.value = p->w - lbl_1_rodata_8638;
        fzgx_live = p->x;
        position = (first + (x + fzgx_live) + panel_ratio(lbl_1_rodata_85F4, width.value * value));
    }
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A0B;
    draw.x = position;
    draw.y = arg2 + p->barY;
    draw.z = lbl_1_rodata_8B34;
    fade = lbl_1_rodata_863C - (lbl_1_rodata_85F0 * pulse);
    draw.flags = 6;
    draw.alpha = fade;
    fn_1_4F734((FontDrawPacket *)&draw);
    if (position > lbl_1_rodata_8B28 + (arg1 + p->x)) {
        draw = *(PanelPacket *)lbl_1_rodata_26F8;
        draw.id = 0x9A0C;
        draw.x = (position - 12);
        draw.y = arg2 + p->barY;
        draw.z = lbl_1_rodata_8B34;
        draw.flags = 7;
        draw.alpha = pulse;
        fn_1_4F734((FontDrawPacket *)&draw);
    }
    if (position < p->w + (arg1 + p->x) - lbl_1_rodata_8638) {
        draw = *(PanelPacket *)lbl_1_rodata_26F8;
        draw.id = 0x9A0C;
        draw.x = (position + 12);
        draw.y = arg2 + p->barY;
        draw.z = lbl_1_rodata_8B34;
        draw.flags = 0x80005;
        draw.alpha = pulse;
        fn_1_4F734((FontDrawPacket *)&draw);
    }
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A0D;
    draw.x = position;
    draw.y = arg2 + p->barY;
    draw.z = lbl_1_rodata_8B38;
    draw.sy = p->barH / fn_1_486C4(draw.id);
    draw.flags = 14;
    draw.alpha = fade;
    fn_1_4F734((FontDrawPacket *)&draw);
    left = *(PanelWidths *)lbl_1_rodata_8AF8;
    right = *(PanelWidths *)lbl_1_rodata_8B10;
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A23;
    fn_1_51678((FontDrawPacket *)&draw, 0x9A23, 0, 0, left.a[lbl_801A66B4], 20);
    draw.x = arg1 + p->leftX;
    draw.y = arg2 + p->barY;
    draw.z = lbl_1_rodata_8B3C;
    draw.flags = 5;
    if (position < lbl_1_rodata_8B28 + (arg1 + p->x) + left.a[lbl_801A66B4]) draw.alpha = lbl_1_rodata_8808;
    fn_1_4F734((FontDrawPacket *)&draw);
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A23;
    fn_1_51678((FontDrawPacket *)&draw, 0x9A23, (72 - right.a[lbl_801A66B4]), 20, right.a[lbl_801A66B4], 20);
    draw.x = arg1 + p->rightX;
    draw.y = arg2 + p->barY;
    draw.z = lbl_1_rodata_8B3C;
    draw.flags = 7;
    if (position > p->w + (arg1 + p->x) - lbl_1_rodata_8B28 - right.a[lbl_801A66B4]) draw.alpha = lbl_1_rodata_8808;
    fn_1_4F734((FontDrawPacket *)&draw);
    if ((s32)arg0 != 0) {
        fn_1_49410();
        fn_1_494DC(4);
        fn_1_4966C((*((const f32 *)&lbl_1_rodata_8B40)), lbl_1_rodata_861C);
        fn_1_496FC(arg1 + p->textX, arg2 + p->textY);
        fn_1_4A0D8((char *)lbl_1_data_41AF8);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_1375C0 */

/* fzgx:begin fn_1_1380F0 */
void fn_1_1380F0(void* arg0) {
    fn_1_138144( (s32)(void*)(arg0), lbl_1_bss_8B3A0.unk_94 & 0x40000000);
}
/* fzgx:end fn_1_1380F0 */

/* fzgx:begin fn_1_138120 */
void fn_1_138120(void* arg0) {
    fn_1_138144( (s32)(void*)(arg0), 0);
}
/* fzgx:end fn_1_138120 */

/* fzgx:begin fn_1_138144 */


void fn_1_138144(s32 arg0, s32 arg1) {
    FontPkt p;
    s32 v0;
    f32 f31;
    f32 f30;

    v0 = (fn_1_A5DC4() != 0 ? lbl_1_rodata_884C : lbl_1_rodata_8674);
    fn_1_49410();
    fn_1_4954C(lbl_1_rodata_8B58);
    fn_1_4955C(lbl_1_rodata_8B5C, lbl_1_rodata_8B5C);
    fn_1_49768(1);
    fn_1_49778(lbl_1_rodata_8B60, lbl_1_rodata_88A8, (s16)v0 - lbl_1_rodata_8B60, lbl_1_rodata_8B28);
    if ((*((s32 *)&lbl_801A66B4)) != 5) {
        fn_1_49590(lbl_1_rodata_85F0);
        fn_1_495B0(0x80000000);
    }
    f31 = fn_1_4B068( (const char *)(s32)(arg0));
    if ((*((s32 *)&lbl_801A66B4)) != 5 && f31 > lbl_1_rodata_86F8) {
        fn_1_4955C(lbl_1_rodata_8B64, lbl_1_rodata_8B5C);
        f31 = fn_1_4B068( (const char *)(s32)(arg0));
    }
    f31 = f31 + lbl_1_rodata_86D0;
    f30 = (lbl_801A66A0 % (s32)f31);
    if (fn_1_A5DC4() != 0) {
        fn_1_496FC((lbl_1_rodata_8B68 + (lbl_1_rodata_87E4 * f31)) - f30, lbl_1_rodata_88A8);
        fn_1_4A0D8((const char *)arg0);
        fn_1_496FC((lbl_1_rodata_8B68 + (lbl_1_rodata_8B6C * f31)) - f30, lbl_1_rodata_88A8);
        fn_1_4A0D8((const char *)arg0);
    }
    fn_1_496FC((lbl_1_rodata_8B68 + (lbl_1_rodata_8638 * f31)) - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_496FC((lbl_1_rodata_8B68 + f31) - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_496FC(lbl_1_rodata_8B68 - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_496FC((lbl_1_rodata_8B68 - f31) - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_49768(0);
    if (fn_1_A5DC4() != 0) {
        p = (*((const FontPkt *)&lbl_1_rodata_26F8));
        p.type = 5;
        p.x = lbl_1_rodata_8658;
        p.y = lbl_1_rodata_88A8;
        p.color = lbl_1_rodata_8B44;
        p.sx = p.sx * (lbl_1_rodata_8B28 / fn_1_48690(5));
        p.sy = p.sy * (lbl_1_rodata_8B28 / fn_1_486C4(p.type));
        p.z = lbl_1_rodata_8834;
        p.flags = 0x80000;
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));
        p.x = lbl_1_rodata_8B70;
        p.flags = 0;
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));

        p = (*((const FontPkt *)&lbl_1_rodata_26F8));
        p.type = 18;
        p.x = (s16)v0;
        p.y = lbl_1_rodata_88A8;
        p.z = lbl_1_rodata_8834;
        p.color = lbl_1_rodata_8B48;
        p.sx = p.sx * (lbl_1_rodata_8B28 / fn_1_486C4(18));
        p.sy = p.sy * (lbl_1_rodata_8B28 / fn_1_486C4(p.type));
        p.flags = 7;
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));

        p = (*((const FontPkt *)&lbl_1_rodata_26F8));
        p.type = 18;
        p.x = lbl_1_rodata_8B74;
        p.y = lbl_1_rodata_88A8;
        p.z = lbl_1_rodata_8834;
        p.color = lbl_1_rodata_8B4C;
        p.sx = p.sx * (lbl_1_rodata_8838 / fn_1_486C4(18));
        p.sy = p.sy * (lbl_1_rodata_8B28 / fn_1_486C4(p.type));
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));
    } else {
        p = (*((const FontPkt *)&lbl_1_rodata_26F8));
        p.type = 5;
        p.x = lbl_1_rodata_8658;
        p.y = lbl_1_rodata_88A8;
        p.color = lbl_1_rodata_8B50;
        p.sx = p.sx * (lbl_1_rodata_8B28 / fn_1_48690(5));
        p.sy = p.sy * (lbl_1_rodata_8B28 / fn_1_486C4(p.type));
        p.z = lbl_1_rodata_8834;
        p.flags = 0x80000;
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));
        p.x = (arg1 != 0 ? 520 : 616);
        p.flags = 0;
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));

        p = (*((const FontPkt *)&lbl_1_rodata_26F8));
        p.type = 18;
        p.x = lbl_1_rodata_8674;
        p.y = lbl_1_rodata_88A8;
        p.z = lbl_1_rodata_8834;
        p.color = lbl_1_rodata_8B54;
        if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
            p.sx = p.sx * (lbl_1_rodata_8B28 / fn_1_486C4(18));
        }
        p.sy = p.sy * (lbl_1_rodata_8B28 / fn_1_486C4(p.type));
        p.flags = 7;
        fn_1_4F734( (FontDrawPacket*)(FontPkt *)(&p));
    }
}
/* fzgx:end fn_1_138144 */

/* fzgx:begin fn_1_138A04 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

extern FontDrawPacket lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern const f32 lbl_1_rodata_85EC;  /* 0.75f */
extern const f32 lbl_1_rodata_85F4;  /* 100.0f */
extern const f32 lbl_1_rodata_861C;  /* 0.0f */
extern const f32 lbl_1_rodata_863C;  /* 1.0f */
extern const f32 lbl_1_rodata_864C;  /* 0.64f */
extern const f32 lbl_1_rodata_8664;  /* 0.6f */
extern const f32 lbl_1_rodata_86D0;  /* 80.0f */
extern const f32 lbl_1_rodata_87DC;  /* 6.0f */
extern const f32 lbl_1_rodata_8A50;  /* 0.87f */
extern const f32 lbl_1_rodata_8B40;  /* -4.0f */
extern const f32 lbl_1_rodata_8B78;  /* 613.0f */
extern const f32 lbl_1_rodata_8B7C;  /* 519.0f */
extern const f32 lbl_1_rodata_8B80;  /* 591.0f */

extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_486C4(u32);
extern u8 fn_1_141F94(u8);
extern void fn_1_135D7C(s16, s16, s16, s16, s16, s16, s16, f32, f32, f32);
extern void fn_1_136CC4(u32, u32, u32, s16);
extern void fn_1_13A848(s16, s16, s32, s16, s32, f32, f32);
extern void fn_1_13A994(s16, s16, s32, s16, s16, s32, f32, f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(s32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

#define fzgx_pool_data_lbl_1_data_40F58_BA8 (data + 0xBA8)
#define fzgx_pool_data_lbl_1_data_40F58_BB8 (data + 0xBB8)
#define fzgx_pool_data_lbl_1_data_40F58_BC0 (data + 0xBC0)

void fn_1_138A04(s32 x, s32 y, s32 idx) {
    const char *data;
    s32 py;
    s16 kind;
    u8 color;
    s16 w;
    FontDrawPacket pkt;

    data = (const char *)&lbl_1_data_40F58;
    kind = lbl_1_bss_8B3A0.unk_C[idx].unk_2;
    color = fn_1_141F94(idx);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9D0C;
    w = fn_1_486C4(0x9D0C);
    fn_1_51678(&pkt, pkt.image, 0, 0, 285, w);
    pkt.x = x;
    pkt.y = y;
    pkt.z = lbl_1_rodata_85F4;
    fn_1_4F734(&pkt);

    fn_1_51564(0, 0, 24, 20, 2, 2);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9D0B;
    pkt.x = x + 18;
    pkt.y = y + 18;
    pkt.z = 80.0f;
    pkt.flags = 10;
    fn_1_5158C(&pkt, pkt.image, (color % 2), (color / 2));
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9D08;
    pkt.x = x + 7;
    pkt.y = y + 33;
    pkt.z = lbl_1_rodata_86D0;
    fn_1_4F734(&pkt);

    {
        f32 scale = 0.87f;
        fn_1_135D7C(x + 36, y + 18, 9, kind, 0, idx, 0, scale, scale, lbl_1_rodata_87DC);
    }
    fn_1_136CC4(x + 16, y + 42, kind, idx);
    fn_1_13A848(x + 467, y + 129, 1, kind, 0, lbl_1_rodata_8664, lbl_1_rodata_864C);
    fn_1_13A994(x + 467, y + 148, 1, kind, lbl_801A66B4, 0, lbl_1_rodata_8664, lbl_1_rodata_8664);

    fn_1_49410();
    fn_1_495C8(10);
    fn_1_494DC(4);
    fn_1_4966C(lbl_1_rodata_8B40, lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC(lbl_1_rodata_8B78, py = color * 201 + 242);
    fn_1_4A0D8(fzgx_pool_data_lbl_1_data_40F58_BA8);
    fn_1_49410();
    fn_1_495C8(10);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(lbl_1_rodata_8B7C, py);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BB8);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC(lbl_1_rodata_8B80, py);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BC0);
}
/* fzgx:end fn_1_138A04 */

/* fzgx:begin fn_1_138E44 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_138E44_lbl_1_bss_8B3A0_0_E32 {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
};
struct fn_1_138E44_Copy88 { u32 a[22]; };
struct fn_1_138E44_lbl_1_bss_8B3A0 {
    struct fn_1_138E44_lbl_1_bss_8B3A0_0_E32 unk_0[1];
};
struct fn_1_138E44_lbl_1_rodata_8600 {
    f64 unk_0;
};

extern f32 lbl_1_rodata_85EC;
extern f32 lbl_1_rodata_861C;
extern f32 lbl_1_rodata_863C;
extern f32 lbl_1_rodata_86D0;
extern f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A50;
extern f32 lbl_1_rodata_8B40;
extern f32 lbl_1_rodata_8B84;
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_1_138E44_lbl_1_rodata_8600 lbl_1_rodata_8600;
extern u32 lbl_1_rodata_26F8;
extern u8 fn_1_141F94(u32);
extern void fn_1_135D7C(s16, s16, s32, s16, s32, s16, s32, f32, f32, f32);
extern void fn_1_136CC4(u32, u32, u32, s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);

#pragma opt_common_subs off
typedef struct lbl_1_bss_8B3A0_t {
    struct fn_1_138E44_lbl_1_bss_8B3A0_0_E32 unk_0[1];
    u8 pad_20[0x12c];
} lbl_1_bss_8B3A0_t;

extern lbl_1_bss_8B3A0_t lbl_1_bss_8B3A0;

extern u8 fn_1_1358BC__fzgx_offset_108[];
extern u8 fn_1_1358BC__fzgx_offset_114[];
extern u8 fn_1_1358BC__fzgx_offset_120[];
extern u8 fn_1_1358BC__fzgx_offset_128[];
extern u8 fn_1_1358BC__fzgx_offset_C0[];
extern u8 fn_1_1358BC__fzgx_offset_CC[];
extern u8 fn_1_1358BC__fzgx_offset_D8[];
extern u8 fn_1_1358BC__fzgx_offset_E4[];
extern u8 fn_1_1358BC__fzgx_offset_F0[];
extern u8 fn_1_1358BC__fzgx_offset_FC[];
extern u8 fn_1_135B80__fzgx_offset_7C[];
extern u8 fn_1_135B80__fzgx_offset_88[];
extern u8 fn_1_135B80__fzgx_offset_94[];
extern u8 fn_1_135B80__fzgx_offset_A0[];
extern u8 fn_1_135B80__fzgx_offset_AC[];
extern u8 fn_1_135B80__fzgx_offset_B8[];
extern u8 fn_1_135B80__fzgx_offset_C4[];
extern u8 fn_1_135B80__fzgx_offset_D0[];
extern u8 fn_1_135B80__fzgx_offset_DC[];
extern u8 fn_1_135B80__fzgx_offset_E4[];
extern u8 fn_1_135D7C__fzgx_offset_1F0[];
extern u8 fn_1_135D7C__fzgx_offset_1FC[];
extern u8 fn_1_135D7C__fzgx_offset_208[];
extern u8 fn_1_135D7C__fzgx_offset_214[];
extern u8 fn_1_135D7C__fzgx_offset_220[];
extern u8 fn_1_135D7C__fzgx_offset_22C[];
extern u8 fn_1_135D7C__fzgx_offset_238[];
extern u8 fn_1_135D7C__fzgx_offset_244[];
extern u8 fn_1_135D7C__fzgx_offset_250[];
extern u8 fn_1_135D7C__fzgx_offset_258[];
extern u8 fn_1_1373B0__fzgx_offset_AC[];
extern u8 fn_1_1373B0__fzgx_offset_B4[];
extern u8 fn_1_1373B0__fzgx_offset_BC[];
extern u8 fn_1_1373B0__fzgx_offset_C4[];
extern u8 fn_1_1373B0__fzgx_offset_CC[];
extern u8 fn_1_1373B0__fzgx_offset_D4[];
extern u8 fn_1_1373B0__fzgx_offset_DC[];
extern u8 fn_1_1373B0__fzgx_offset_E4[];
extern u8 fn_1_1373B0__fzgx_offset_EC[];
extern u8 fn_1_1373B0__fzgx_offset_F4[];
extern u8 lbl_1_data_40F58__fzgx_offset_0[];
extern u8 lbl_1_data_40F5C__fzgx_offset_0[];
extern u8 lbl_1_data_40F68__fzgx_offset_0[];
extern u8 lbl_1_data_40F74__fzgx_offset_0[];
extern u8 lbl_1_data_40F80__fzgx_offset_0[];
extern u8 lbl_1_data_40F8C__fzgx_offset_0[];
extern u8 lbl_1_data_40F94__fzgx_offset_0[];
extern u8 lbl_1_data_40F9C__fzgx_offset_0[];
extern u8 lbl_1_data_40FA4__fzgx_offset_0[];
extern u8 lbl_1_data_40FAC__fzgx_offset_0[];
extern u8 lbl_1_data_40FB8__fzgx_offset_0[];
extern u8 lbl_1_data_40FC8__fzgx_offset_0[];
extern u8 lbl_1_data_40FD8__fzgx_offset_0[];
extern u8 lbl_1_data_40FE0__fzgx_offset_0[];
extern u8 lbl_1_data_40FE8__fzgx_offset_0[];
extern u8 lbl_1_data_40FF4__fzgx_offset_0[];
extern u8 lbl_1_data_41000__fzgx_offset_0[];
extern u8 lbl_1_data_41010__fzgx_offset_0[];
extern u8 lbl_1_data_41018__fzgx_offset_0[];
extern u8 lbl_1_data_41024__fzgx_offset_0[];
extern u8 lbl_1_data_41030__fzgx_offset_0[];
extern u8 lbl_1_data_41040__fzgx_offset_0[];
extern u8 lbl_1_data_41048__fzgx_offset_0[];
extern u8 lbl_1_data_41054__fzgx_offset_0[];
extern u8 lbl_1_data_41060__fzgx_offset_0[];
extern u8 lbl_1_data_41070__fzgx_offset_0[];
extern u8 lbl_1_data_41078__fzgx_offset_0[];
extern u8 lbl_1_data_41084__fzgx_offset_0[];
extern u8 lbl_1_data_4108C__fzgx_offset_0[];
extern u8 lbl_1_data_41098__fzgx_offset_0[];
extern u8 lbl_1_data_410A8__fzgx_offset_0[];
extern u8 lbl_1_data_410B4__fzgx_offset_0[];
extern u8 lbl_1_data_410C0__fzgx_offset_0[];
extern u8 lbl_1_data_410C8__fzgx_offset_0[];
extern u8 lbl_1_data_410DC__fzgx_offset_0[];
extern u8 lbl_1_data_410EC__fzgx_offset_0[];
extern u8 lbl_1_data_410FC__fzgx_offset_0[];
extern u8 lbl_1_data_41108__fzgx_offset_0[];
extern u8 lbl_1_data_41114__fzgx_offset_0[];
extern u8 lbl_1_data_41124__fzgx_offset_0[];
extern u8 lbl_1_data_4112C__fzgx_offset_0[];
extern u8 lbl_1_data_41138__fzgx_offset_0[];
extern u8 lbl_1_data_41140__fzgx_offset_0[];
extern u8 lbl_1_data_41148__fzgx_offset_0[];
extern u8 lbl_1_data_41150__fzgx_offset_0[];
extern u8 lbl_1_data_4120C__fzgx_offset_0[];
extern u8 lbl_1_data_4122C__fzgx_offset_0[];
extern u8 lbl_1_data_41230__fzgx_offset_0[];
extern u8 lbl_1_data_41274__fzgx_offset_0[];
extern u8 lbl_1_data_41294__fzgx_offset_0[];
extern u8 lbl_1_data_412B8__fzgx_offset_0[];
extern u8 lbl_1_data_412FC__fzgx_offset_0[];
extern u8 lbl_1_data_41340__fzgx_offset_0[];
extern u8 lbl_1_data_41348__fzgx_offset_0[];
extern u8 lbl_1_data_41350__fzgx_offset_0[];
extern u8 lbl_1_data_41358__fzgx_offset_0[];
extern u8 lbl_1_data_41364__fzgx_offset_0[];
extern u8 lbl_1_data_41374__fzgx_offset_0[];
extern u8 lbl_1_data_4137C__fzgx_offset_0[];
extern u8 lbl_1_data_41388__fzgx_offset_0[];
extern u8 lbl_1_data_41390__fzgx_offset_0[];
extern u8 lbl_1_data_4139C__fzgx_offset_0[];
extern u8 lbl_1_data_413A4__fzgx_offset_0[];
extern u8 lbl_1_data_413B0__fzgx_offset_0[];
extern u8 lbl_1_data_413C0__fzgx_offset_0[];
extern u8 lbl_1_data_413D0__fzgx_offset_0[];
extern u8 lbl_1_data_413E0__fzgx_offset_0[];
extern u8 lbl_1_data_413EC__fzgx_offset_0[];
extern u8 lbl_1_data_413F8__fzgx_offset_0[];
extern u8 lbl_1_data_41400__fzgx_offset_0[];
extern u8 lbl_1_data_41408__fzgx_offset_0[];
extern u8 lbl_1_data_41410__fzgx_offset_0[];
extern u8 lbl_1_data_41418__fzgx_offset_0[];
extern u8 lbl_1_data_41420__fzgx_offset_0[];
extern u8 lbl_1_data_41428__fzgx_offset_0[];
extern u8 lbl_1_data_41430__fzgx_offset_0[];
extern u8 lbl_1_data_41438__fzgx_offset_0[];
extern u8 lbl_1_data_41448__fzgx_offset_0[];
extern u8 lbl_1_data_41458__fzgx_offset_0[];
extern u8 lbl_1_data_41468__fzgx_offset_0[];
extern u8 lbl_1_data_41478__fzgx_offset_0[];
extern u8 lbl_1_data_41484__fzgx_offset_0[];
extern u8 lbl_1_data_4148C__fzgx_offset_0[];
extern u8 lbl_1_data_4149C__fzgx_offset_0[];
extern u8 lbl_1_data_414A8__fzgx_offset_0[];
extern u8 lbl_1_data_414C0__fzgx_offset_0[];
extern u8 lbl_1_data_418A4__fzgx_offset_0[];
extern u8 lbl_1_data_418BC__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_40F58[746] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_1_data_40F58__fzgx_offset_0, (u32)lbl_1_data_40F5C__fzgx_offset_0, (u32)lbl_1_data_40F68__fzgx_offset_0, (u32)lbl_1_data_40F74__fzgx_offset_0, (u32)lbl_1_data_40F80__fzgx_offset_0, (u32)lbl_1_data_40F8C__fzgx_offset_0, (u32)lbl_1_data_40F94__fzgx_offset_0, (u32)lbl_1_data_40F9C__fzgx_offset_0,
    (u32)lbl_1_data_40FA4__fzgx_offset_0, (u32)lbl_1_data_40FAC__fzgx_offset_0, (u32)lbl_1_data_40FB8__fzgx_offset_0, (u32)lbl_1_data_40FC8__fzgx_offset_0, (u32)lbl_1_data_40FD8__fzgx_offset_0, (u32)lbl_1_data_40FE0__fzgx_offset_0, (u32)lbl_1_data_40FE8__fzgx_offset_0, (u32)lbl_1_data_40FF4__fzgx_offset_0,
    (u32)lbl_1_data_41000__fzgx_offset_0, (u32)lbl_1_data_41010__fzgx_offset_0, (u32)lbl_1_data_41018__fzgx_offset_0, (u32)lbl_1_data_41024__fzgx_offset_0, (u32)lbl_1_data_41030__fzgx_offset_0, (u32)lbl_1_data_41040__fzgx_offset_0, (u32)lbl_1_data_41048__fzgx_offset_0, (u32)lbl_1_data_41054__fzgx_offset_0,
    (u32)lbl_1_data_41060__fzgx_offset_0, (u32)lbl_1_data_41070__fzgx_offset_0, (u32)lbl_1_data_41078__fzgx_offset_0, (u32)lbl_1_data_41084__fzgx_offset_0, (u32)lbl_1_data_4108C__fzgx_offset_0, (u32)lbl_1_data_41098__fzgx_offset_0, (u32)lbl_1_data_410A8__fzgx_offset_0, (u32)lbl_1_data_410B4__fzgx_offset_0,
    (u32)lbl_1_data_410C0__fzgx_offset_0, (u32)lbl_1_data_410C8__fzgx_offset_0, (u32)lbl_1_data_410DC__fzgx_offset_0, (u32)lbl_1_data_410EC__fzgx_offset_0, (u32)lbl_1_data_410FC__fzgx_offset_0, (u32)lbl_1_data_41108__fzgx_offset_0, (u32)lbl_1_data_41114__fzgx_offset_0, (u32)lbl_1_data_41124__fzgx_offset_0,
    (u32)lbl_1_data_4112C__fzgx_offset_0, (u32)lbl_1_data_41138__fzgx_offset_0, (u32)lbl_1_data_41140__fzgx_offset_0, (u32)lbl_1_data_41148__fzgx_offset_0, (u32)lbl_1_data_41150__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722025,
    0x64206973, 0x20646973, 0x636F6E6E, 0x65637465, 0x640A0000, 0x0, 0x83528393, 0x8367838D,
    0x815B8389, 0x256482AA, 0x82CA82AF, 0x82C482A2, 0x82DC82B7, 0xA835283, 0x93836783, 0x8D815B83,  /* fzgx-allow: A1 retail data bytes */
    0x89837C81, 0x5B836725, 0x6482C982, 0xB382B582, 0xC482AD82, 0xBE82B382, 0xA2000000, 0x506C6561,
    0x73652073, 0x65742075, 0x7020796F, 0x7572206D, 0x61636869, 0x6E652E20, 0x0, 0x837D8356,
    0x839382F0, 0x835A8362, 0x83658342, 0x8393834F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    0x50726573, 0x73207468, 0x6520436F, 0x6E74726F, 0x6C205374, 0x69636B20, 0x4C656674, 0x206F7220,
    0x52696768, 0x7420746F, 0x2073656C, 0x65637420, 0x4D616368, 0x696E6520, 0x53657474, 0x696E6773,
    0x2E000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82CC, 0x8DB68945,  /* fzgx-allow: A1 retail data bytes */
    0x82C58141, 0x837D8356, 0x839382F0, 0x835A8362, 0x83658342, 0x8393834F, 0x82B582C4, 0x82AD82BE,
    0x82B382A2, 0x81420000, 0x20456E74, 0x65720000, 0x208C8892, 0xE8000000, 0x2043616E, 0x63656C00,  /* fzgx-allow: A1 retail data bytes */
    0x20834C83, 0x83839383, 0x5A838B00, 0x20436861, 0x6E676520, 0x436F6C6F, 0x72000000, 0x20904691,
    0xD682A600, 0x20526574, 0x75726E20, 0x0, 0x2096DF82, 0xE9000000, 0x2044656C, 0x65746520,
    0x0, 0x208FC182, 0xB7000000, 0x204C6F61, 0x64204768, 0x6F737400, 0x20835381, 0x5B835883,
    0x67838D81, 0x5B836800, 0x2053656C, 0x65637420, 0x47686F73, 0x74000000, 0x20835381, 0x5B835883,
    0x67914991, 0xF0000000, 0x2050656E, 0x2073697A, 0x65000000, 0x20837983, 0x93835483, 0x43835900,
    0x20526F74, 0x61746500, 0x2089F193, 0x5D000000, 0x20496E76, 0x65727400, 0x2094BD93, 0x5D000000,
    0x2048656C, 0x70000000, 0x20837783, 0x8B837600, 0x20536176, 0x65000000, 0x20835A81, 0x5B837500,
    0x204C6F61, 0x64204761, 0x72616765, 0x0, 0x20834B83, 0x8C815B83, 0x57838D81, 0x5B836800,
    0x2053656C, 0x65637420, 0x736C6F74, 0x0, 0x20835883, 0x8D836283, 0x67914991, 0xF0000000,
    0x20506565, 0x6C206F66, 0x66200000, 0x2082CD82, 0xAA82B700, 0x20446966, 0x66696375, 0x6C747981,
    0x46000000, 0x2093EF88, 0xD5937881, 0x46000000, 0x54686520, 0x4E657874, 0x20436F75, 0x72736520,
    0x69732025, 0x732E0000, 0x8E9F82CC, 0x8352815B, 0x835882CD, 0x257382C5, 0x82B78142, 0x0,
    (u32)lbl_1_data_4120C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41230__fzgx_offset_0, (u32)lbl_1_data_41274__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41294__fzgx_offset_0, (u32)lbl_1_data_412B8__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_412FC__fzgx_offset_0, (u32)lbl_1_data_41340__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41348__fzgx_offset_0,
    (u32)lbl_1_data_41350__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41358__fzgx_offset_0, (u32)lbl_1_data_41364__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41374__fzgx_offset_0, (u32)lbl_1_data_4137C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41388__fzgx_offset_0, (u32)lbl_1_data_41390__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4139C__fzgx_offset_0,
    (u32)lbl_1_data_413A4__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_413B0__fzgx_offset_0, (u32)lbl_1_data_413C0__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_413D0__fzgx_offset_0, (u32)lbl_1_data_413E0__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_413EC__fzgx_offset_0, (u32)lbl_1_data_413F8__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41400__fzgx_offset_0,
    (u32)lbl_1_data_41408__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41410__fzgx_offset_0, (u32)lbl_1_data_41418__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41420__fzgx_offset_0, (u32)lbl_1_data_41428__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41430__fzgx_offset_0, (u32)lbl_1_data_41438__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41448__fzgx_offset_0,
    (u32)lbl_1_data_41458__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41468__fzgx_offset_0, (u32)lbl_1_data_41478__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41484__fzgx_offset_0, (u32)lbl_1_data_4148C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4149C__fzgx_offset_0, (u32)lbl_1_data_414A8__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_414C0__fzgx_offset_0,
    0x5, 0x1, 0x3, 0x3, 0x3, 0x1, 0x4, 0x1,
    0x4, 0x2, 0x4, 0x1, 0x1, 0x4, 0x2, 0x1,
    0x2, 0x3, 0x2, 0x3, 0x2, 0x2, 0x2, 0x3,
    0x5, 0x1, 0x4, 0x5, 0x2, 0x2, 0x2, 0x2,
    0x3, 0x2, 0x3, 0x2, 0x5, 0x1, 0x3, 0x2,
    0x4, 0x1, 0x2, 0x4, 0x1, 0x3, 0x1, 0x4,
    0x1, 0x2, 0x4, 0x3, 0x3, 0x1, 0x3, 0x3,
    0x1, 0x5, 0x2, 0x2, 0x5, 0x2, 0x2, 0x5,
    0x1, 0x3, 0x2, 0x1, 0x5, 0x1, 0x3, 0x3,
    0x2, 0x1, 0x5, 0x4, 0x1, 0x4, 0x3, 0x1,
    0x4, 0x5, 0x2, 0x2, 0x1, 0x2, 0x5, 0x1,
    0x5, 0x1, 0x1, 0x2, 0x4, 0x1, 0x2, 0x5,
    0x5, 0x1, 0x3, 0x3, 0x3, 0x1, 0x2, 0x1,
    0x5, 0x4, 0x1, 0x4, 0x2, 0x3, 0x2, 0x4,
    0x2, 0x1, 0x2, 0x4, 0x2, 0x1, 0x4, 0x2,
    0x2, 0x2, 0x3, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74,
    0x2E200000, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF89BA, 0x82B382A2, 0x81420000, (u32)lbl_1_data_418A4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, 0x82A982BB, 0x82AD82B6, 0x82E382A4,
    0x82B5205B, 0x20302E30, 0x3C2D3E31, 0x2E30205D, 0x2082B382, 0xA282B182, 0xA482BB82, 0xAD82B682,
    0xE382A482, 0xB50A0000, 0x2A0A0000, 0x25640000, 0x4E554C4C, 0xA000000, 0x25645020, 0x834A8389,
    0x815B5B25, 0x645D0A00, 0x82A482B5, 0x82EB82E4, 0x82D182B3, 0x82B382EA, 0x0, 0x82A482B5,  /* fzgx-allow: A1 retail data bytes */
    0x82EB82AA, 0x82DD82D0, 0x82A982EA, 0x0, 0x81F482C9, 0x82E182F1, 0x82AC82E7, 0x82B781F4,
    0x0, 0x8358815B, 0x83558393, 0x819A82AD, 0x82DD82B1, 0x0, 0x82728272, 0x8B898389,
    0x8343835A, 0x83938358, 0x0, 0x837D8358, 0x835E815B, 0x83898343, 0x835A8393, 0x83580000,
    0x83708343, 0x838D8362, 0x83678CF3, 0x95E290B6, 0x0, 0x82528251, 0x8B898389, 0x8343835A,
    0x83938358, 0x0, 0x73656C5F, 0x73746174, 0x69635F64, 0x6973702E, 0x63000000, 0x4572726F,
    0x72213A73, 0x656C735F, 0x64697370, 0x5F746174, 0x65626F75, 0x200A0000, 0x4572726F, 0x72213A73,
    0x656C735F, 0x64697370, 0x5F746174, 0x65626F75, 0x5F6B6167, 0x69200A00, 0x25730A00, (u32)fn_1_1358BC__fzgx_offset_C0,
    (u32)fn_1_1358BC__fzgx_offset_E4, (u32)fn_1_1358BC__fzgx_offset_108, (u32)fn_1_1358BC__fzgx_offset_128, (u32)fn_1_1358BC__fzgx_offset_CC, (u32)fn_1_1358BC__fzgx_offset_F0, (u32)fn_1_1358BC__fzgx_offset_114, (u32)fn_1_1358BC__fzgx_offset_128, (u32)fn_1_1358BC__fzgx_offset_D8,
    (u32)fn_1_1358BC__fzgx_offset_FC, (u32)fn_1_1358BC__fzgx_offset_120, (u32)fn_1_135B80__fzgx_offset_7C, (u32)fn_1_135B80__fzgx_offset_A0, (u32)fn_1_135B80__fzgx_offset_C4, (u32)fn_1_135B80__fzgx_offset_E4, (u32)fn_1_135B80__fzgx_offset_88, (u32)fn_1_135B80__fzgx_offset_AC,
    (u32)fn_1_135B80__fzgx_offset_D0, (u32)fn_1_135B80__fzgx_offset_E4, (u32)fn_1_135B80__fzgx_offset_94, (u32)fn_1_135B80__fzgx_offset_B8, (u32)fn_1_135B80__fzgx_offset_DC, (u32)fn_1_135D7C__fzgx_offset_1F0, (u32)fn_1_135D7C__fzgx_offset_214, (u32)fn_1_135D7C__fzgx_offset_238,
    (u32)fn_1_135D7C__fzgx_offset_258, (u32)fn_1_135D7C__fzgx_offset_1FC, (u32)fn_1_135D7C__fzgx_offset_220, (u32)fn_1_135D7C__fzgx_offset_244, (u32)fn_1_135D7C__fzgx_offset_258, (u32)fn_1_135D7C__fzgx_offset_208, (u32)fn_1_135D7C__fzgx_offset_22C, (u32)fn_1_135D7C__fzgx_offset_250,
    0x3F3F3F3F, 0x3F0A0000, 0x3F3F3F3F, 0x0, 0x25346400, 0x3F000000, (u32)fn_1_1373B0__fzgx_offset_AC, (u32)fn_1_1373B0__fzgx_offset_B4,
    (u32)fn_1_1373B0__fzgx_offset_BC, (u32)fn_1_1373B0__fzgx_offset_C4, (u32)fn_1_1373B0__fzgx_offset_CC, (u32)fn_1_1373B0__fzgx_offset_D4, (u32)fn_1_1373B0__fzgx_offset_DC, (u32)fn_1_1373B0__fzgx_offset_E4, (u32)fn_1_1373B0__fzgx_offset_EC, (u32)fn_1_1373B0__fzgx_offset_F4,
    0x42414C41, 0x4E434500
};
static u32 fzgx_pool_data_lbl_1_data_40F58_BA8[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x20202020, 0x434F4C4F, 0x52202020, 0x204F4B00
};
static u32 fzgx_pool_data_lbl_1_data_40F58_BB8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x83A183AF, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_40F58_BC0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x839F0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_40F58(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58_BA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58_BB8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58_BC0;
}
#pragma section code_type ".text"

void fn_1_138E44(s32 x, s32 y, s32 idx) {
    u8 t;
    s32 tx;
    s32 col;
    s32 tc;
    s32 row;
    s32 ty;
    s16 v;
    FontDrawPacket p;

    v = lbl_1_bss_8B3A0.unk_0[idx].unk_E;
    t = fn_1_141F94(idx & 0xFF);

    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    tc = t;
    p.image = 0x9D0C;
    p.x = x;
    p.y = y;
    p.z = 100 - tc;
    fn_1_4F734(&p);
    fn_1_51564(0, 0, 24, 20, 2, 2);

    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.image = 0x9D0B;
    p.x = x + 18;
    p.y = y + 18;
    p.z = lbl_1_rodata_86D0;
    p.flags = 10;
    col = tc % 2;
    row = t / 2;
    fn_1_5158C(&p, 0x9D0B, col, row);
    fn_1_4F734(&p);

    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.image = 0x9D08;
    p.x = x + 7;
    p.y = y + 33;
    p.z = lbl_1_rodata_86D0;
    fn_1_4F734(&p);

    fn_1_135D7C(x + 36, y + 18, 9, v, 0, idx, 0, lbl_1_rodata_8A50, lbl_1_rodata_8A50, lbl_1_rodata_87DC);
    fn_1_136CC4(x + 16, y + 42, v, idx);

    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_494DC(4);
    fn_1_4966C(lbl_1_rodata_8B40, lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_8B84);
    tx = col * 301;
    fn_1_496FC(tx + 312, ty = row * 201 + 242);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BA8);

    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(tx + 218, ty);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BB8);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC(tx + 290, ty);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BC0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_138E44 */

/* fzgx:begin fn_1_13923C */
struct fn_1_13923C_Copy88 { u32 a[22]; };


void fn_1_13923C(u32 arg0, u32 arg1) {
    f32 v0;
    u32 v1;
    f32 v2;
    FontDrawPacket loc_8;
    /* frame */
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = (s32)arg0;
    v1 = (0x10000 - 25334);
    loc_8.image = v1;
    v2 = (s32)arg1;
    loc_8.x = v0;
    loc_8.y = v2;
    loc_8.z = lbl_1_rodata_8840;
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
/* fzgx:end fn_1_13923C */

/* fzgx:begin fn_1_1392E0 */


typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} Fn1392E0Elem;

void fn_1_1392E0(Fn1392E0Arg0 *arg0, Fn1392E0Arg1 *arg1) {
    Obj_1_bss_8B3A0 *base;
    u8 *ptr;
    s32 index;
    s32 offset;
    f32 value;

    index = arg0->unk_54;
    base = &lbl_1_bss_8B3A0;
    ptr = (u8 *)base + 0x9F;
    value = ptr[index] / lbl_1_rodata_85F4;
    offset = ((Fn1392E0Elem *)(base))[index].unk_E;

    if (base->unk_94 & 0x40000000) {
        if ((u8)fn_1_D6698() == 0) {
            s8 a;
            s8 b;

            fn_1_D66F8(0, (u8 *)(&a), &b);
            offset = a;
            value = ptr[0] / lbl_1_rodata_85F4;
        }
    }

    fn_1_139440(value, arg1->unk_0, arg1->unk_4,
                (arg1->unk_24 - arg1->unk_0),
                (arg1->unk_28 - arg1->unk_4), offset, index);
}
/* fzgx:end fn_1_1392E0 */

/* fzgx:begin fn_1_139440 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"
#include "fpscr_trunc.h"

typedef struct {
    u8 r, g, b, a;
} Color;

/* 0x81C0-byte machine entry */
typedef struct {
    u32 flags;
    u8 pad_4[0x819C];
    u8 image_index;
    u8 pad_81A1[0x1F];
} MachineEntry;

extern u32 lbl_801A66A0;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_88B8;
extern const f32 lbl_1_rodata_8B98;

extern int fn_1_139A3C(s16);
extern MachineEntry *fn_1_36AD0(void);
extern void fn_1_14FC80(s16, MachineParameterRecord *);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_22B10(MachineParameterRecord *, f32);
extern void fn_1_229EC(MachineParameterRecord *, f32 *, f32 *);
extern Color fn_1_539CC(Color, Color, f32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_1_A9868(void);
extern void fn_1_AA350(s16 *, s16 *, Color *, u32);
extern void fn_1_AA538(void);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(s32);
extern void fn_80072864(u32);

extern Color lbl_1_rodata_8B88;
extern Color lbl_1_rodata_8B8C;
extern Color lbl_1_rodata_8B90;
extern Color lbl_1_rodata_8B94;

void fn_1_139440(f32 value, s32 x, s32 y, s32 w, s32 h, s16 machine, s16 index) {
    s16 xs[302];
    s16 ys[302];
    Color colors[602];
    MachineParameterRecord params;
    f32 pos;
    f32 mag;
    Color color;
    s32 i;
    s16 *px;
    s16 *py;
    Color *pc;
    s32 frame;
    s32 slot;
    s32 active;
    f32 phase;
    f32 speed;

    pos = lbl_1_rodata_861C;
    mag = lbl_1_rodata_861C;
    slot = index;
    px = xs;
    py = ys;
    pc = colors;
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
        slot = 0;
    }
    active = fn_1_139A3C(slot);
    if (machine < 41) {
        fn_80008BA8(&params, &lbl_1_data_28060.entries[machine], sizeof(params));
    } else if (!(fn_1_36AD0()[index].flags & 0x40000000)) {
        fn_80008BA8(&params, &lbl_1_data_28060.entries[fn_1_36AD0()[index].image_index], sizeof(params));
    } else {
        fn_1_14FC80(index, &params);
    }
    fn_1_22B10(&params, value);
    for (i = 0; i < 750; i++) {
        Color c0 = lbl_1_rodata_8B88;
        Color c1 = lbl_1_rodata_8B8C;
        Color c2 = lbl_1_rodata_8B90;
        Color c3 = lbl_1_rodata_8B94;
        frame = lbl_801A66A0;
        fn_1_229EC(&params, &pos, &mag);
        speed = pos;
        if (i % 10 == 0 || i == 749) {
            phase = lbl_1_rodata_863C + lbl_1_rodata_85F0 * (i / lbl_1_rodata_8B98) - (frame % 220) / lbl_1_rodata_88B8;
            phase = phase - fpscr_trunc(phase);
            if (active != 0 && (frame - *(u32 *)((u8 *)&lbl_1_bss_8B3A0 + slot * 4 + 0xF0) > i / 50 || *(s32 *)((u8 *)&lbl_1_bss_8B3A0 + slot * 4 + 0x100) == 9)) {
                if (phase < lbl_1_rodata_85F0) {
                    color = fn_1_539CC(c2, c3, lbl_1_rodata_863C - lbl_1_rodata_8638 * phase);
                } else {
                    color = fn_1_539CC(c3, c2, lbl_1_rodata_863C - (lbl_1_rodata_8638 * phase - lbl_1_rodata_863C));
                }
            } else {
                if (phase < lbl_1_rodata_85F0) {
                    color = fn_1_539CC(c0, c1, lbl_1_rodata_863C - lbl_1_rodata_8638 * phase);
                } else {
                    color = fn_1_539CC(c1, c0, lbl_1_rodata_863C - (lbl_1_rodata_8638 * phase - lbl_1_rodata_863C));
                }
            }
            color.a = 0xA0;
            *px++ = x + i * w / 750;
            *py++ = y + h;
            *pc++ = color;
            *px++ = x + i * w / 750;
            *py++ = (y + h) - (f32)h * speed / lbl_1_rodata_87DC;
            *pc++ = color;
        }
    }
    fn_800728A8(1, 4, 5, 0);
    fn_1_A9868();
    fn_1_AA350(xs, ys, colors, 0x98);
    fn_1_AA538();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xF, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}
/* fzgx:end fn_1_139440 */

/* fzgx:begin fn_1_139A3C */
int fn_1_139A3C(int arg0) {
    s32 index = (s16)arg0;

    if (((u32 *)((u8 *)(&lbl_1_bss_8B3A0) + 0xF0))[index] == 0) {
        lbl_1_bss_8E3D0[index] = 0;
    }

    if (((s32 *)((u8 *)(&lbl_1_bss_8B3A0) + 0x100))[index] == 7 &&
        ((s32 *)((u8 *)(&lbl_1_bss_8B3A0) + 0x110))[index] != 0) {
        lbl_1_bss_8E3D0[index] = 1;
    } else if (((s32 *)((u8 *)(&lbl_1_bss_8B3A0) + 0x100))[index] == 8 ||
               ((s32 *)((u8 *)(&lbl_1_bss_8B3A0) + 0x100))[index] == 9) {
        if (((s32 *)((u8 *)(&lbl_1_bss_8B3A0) + 0x110))[index] == 0) {
            lbl_1_bss_8E3D0[index] = 0;
        }
    }

    return lbl_1_bss_8E3D0[index];
}
/* fzgx:end fn_1_139A3C */

/* fzgx:begin fn_1_139AEC noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

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
    u8 pad0[0x20];
    void *unk_20;
    u8 pad24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    u8 pad50[0x14];
    s16 unk_64;
} Arg0Struct;

extern Sp8 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_86FC;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;

extern u8 fn_1_D6740(u8);
extern u8 fn_1_D66B0(void);
extern void fn_1_8CED0(void *, s32, s32);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void *, Sp8 *, void (*)(void), void *);

#pragma opt_common_subs off
void fn_1_139AEC(Arg0Struct *arg0) {
    Sp8 sp8 = lbl_1_rodata_26F8;
    s32 var_r31;
    s16 i;
    s16 var_r29;

    arg0->unk_38 = lbl_1_rodata_85F0;
    arg0->unk_3C = lbl_1_rodata_8B9C;
    arg0->unk_40 = lbl_1_rodata_8BA0;
    arg0->unk_44 = lbl_1_rodata_85F0;
    arg0->unk_48 = lbl_1_rodata_861C;
    arg0->unk_4C = lbl_1_rodata_861C;

    sp8 = lbl_1_rodata_26F8;

    sp8.unk_4 = lbl_1_rodata_8BA4;
    sp8.unk_8 = lbl_1_rodata_8BA8;
    sp8.unk_C = lbl_1_rodata_86FC;
    sp8.unk_30 = 10;

    if (lbl_1_bss_8CA28.unk_0 != 0) {
        sp8.unk_10 *= lbl_1_rodata_8638;
        sp8.unk_14 *= lbl_1_rodata_8638;
    }

    if (!(lbl_1_bss_8B3A0.unk_94 & 0x40000000)) {
        return;
    }

    sp8.unk_10 *= lbl_1_rodata_8664;
    sp8.unk_14 *= lbl_1_rodata_8BAC;
    sp8.unk_10 *= lbl_1_rodata_8BB0;
    sp8.unk_14 *= lbl_1_rodata_8BB0;
    sp8.unk_8 = lbl_1_rodata_8BB4;

    i = 0;
    var_r29 = 1;
    var_r31 = 0x64;
    for (; i < 4; i++) {
        if (!fn_1_D6740(i)) {
            continue;
        }
        if (i == fn_1_D66B0()) {
            continue;
        }

        sp8.unk_4 = (var_r29 - 1) * 87 + 66;
        fn_1_8CED0((u8 *)arg0->unk_20 + var_r31, 140, 100);
        *(f32 *)((u8 *)arg0->unk_20 + var_r31 + 0x44) = lbl_1_rodata_87D0;
        arg0->unk_64 = i;
        fn_1_8D3F8((u8 *)arg0->unk_20 + var_r31, &sp8, fn_1_131C08, arg0);
        var_r31 += 100;
        var_r29++;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_139AEC */

/* fzgx:begin fn_1_139D60 */
/* 0x20-byte stride view of the state table at lbl_1_bss_8B3A0. */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} BssEntry20;

typedef struct {
    u8 pad_0[0x18];
    f32 unk_18;
    f32 unk_1C;
    void *unk_20;
    u8 pad_24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    u8 pad_50[0x14];
    u16 unk_64;
    u8 pad_66[0x1A];
    void *unk_80;
} StaticDispObj;

void fn_1_139D60(StaticDispObj *self) {
    BssEntry20 *entries = (BssEntry20 *)&lbl_1_bss_8B3A0;
    s16 index;
    int offset;
    u8 values[0x58];
    u32 *src;
    u32 *dst;
    int count;

    index = *(s16 *)self;
    offset = entries[index].unk_E;
    self->unk_38 = lbl_1_rodata_85F0;
    self->unk_3C = lbl_1_rodata_8B9C;
    self->unk_40 = lbl_1_rodata_8BA0;
    self->unk_44 = lbl_1_rodata_85F0;
    self->unk_48 = lbl_1_rodata_861C;
    self->unk_4C = lbl_1_rodata_861C;

    src = (u32 *)lbl_1_rodata_26F8 - 1;
    dst = (u32 *)values - 1;
    count = 11;
    while (count--) {
        dst[1] = src[1];
        dst[2] = src[2];
        dst += 2;
        src += 2;
    }

    ((f32 *)((u8 *)values - 4))[2] = lbl_1_rodata_8BA4;
    if (offset < 0x29) {
        offset = ((s16 *)lbl_1_rodata_8558)[offset] + 0xf0;
    } else {
        offset = 0xf0;
    }
    ((f32 *)((u8 *)values - 4))[3] = offset;
    ((f32 *)((u8 *)values - 4))[4] = lbl_1_rodata_86FC;
    ((u32 *)((u8 *)values - 4))[13] = 10;
    if (lbl_1_bss_8CA28.unk_0 != 0) {
        ((f32 *)((u8 *)values - 4))[5] *= lbl_1_rodata_8638;
        ((f32 *)(values - 4))[6] *= lbl_1_rodata_8638;
    }

    self->unk_64 = (u8)fn_1_D66B0();
    fn_1_8CED0(self->unk_20, 0x230, 0x190);
    ((f32 *)self->unk_20)[0x44 / 4] = lbl_1_rodata_87D0;
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0) {
        self->unk_64 = (u8)fn_1_D66B0();
    }
    fn_1_8D3F8(self->unk_20, values, fn_1_131C08, self);
}
/* fzgx:end fn_1_139D60 */

/* fzgx:begin fn_1_139F18 */
typedef struct {
    u8 pad_0[0x44];
    f32 unk_44;
} Fn139F18Child;

typedef struct {
    u8 pad_0[0x24];
    Fn139F18Child* unk_24;
    u8 pad_28[0x10];
    f32 unk_38;
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
} Fn139F18Obj;



void fn_1_139F18(Fn139F18Obj* self) {
    Fn139F18Data local;

    self->unk_38 = lbl_1_rodata_861C;
    self->unk_3c = lbl_1_rodata_85F0;
    self->unk_40 = lbl_1_rodata_8BB8;
    self->unk_44 = lbl_1_rodata_861C;
    self->unk_48 = lbl_1_rodata_85F0;
    self->unk_4c = lbl_1_rodata_861C;

    local = (*((Fn139F18Data *)&lbl_1_rodata_26F8));
    ((f32*)local.value)[1] = lbl_1_rodata_8BBC;
    ((f32*)local.value)[2] = lbl_1_rodata_86F8;
    ((f32*)local.value)[3] = lbl_1_rodata_8B84;
    local.value[12] = 10;

    if (lbl_1_bss_8CA28.unk_0 != 0) {
        ((f32*)local.value)[4] *= lbl_1_rodata_8638;
        ((f32*)local.value)[5] *= lbl_1_rodata_8638;
    }

    fn_1_8CED0(self->unk_24, 0x280, 0x18c);
    self->unk_24->unk_44 = lbl_1_rodata_87D0;
    fn_1_8D3F8(self->unk_24, &local, fn_1_131B90, self);
}
/* fzgx:end fn_1_139F18 */

/* fzgx:begin fn_1_13A038 */
typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u8 unk_34[0x24];
} Track;



typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u32 unk_34;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
    u8 unk_40[4];
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 unk_5C[4];
} fn_1_13A038_Sig_fn_1_8CED0_Fn1_8CED0State;

typedef struct {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40[4];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} fn_1_13A038_Sig_fn_1_8D3F8_Fn1_8D3F8Car;


void fn_1_13A038(Car *car)
{
    f32 *fzgx_value;
    Track v;
    s32 x;
    u32 off;
    s32 i;

    car->unk_38 = lbl_1_rodata_861C;
    car->unk_3C = lbl_1_rodata_8BC0;
    fzgx_value = &car->unk_40;
    *fzgx_value = lbl_1_rodata_8BC4;
    car->unk_44 = lbl_1_rodata_861C;
    car->unk_4C = lbl_1_rodata_861C;

    i = 0;
    x = 140;
    off = 0;

    for (; i < 4; i++) {
        s16 kind = lbl_1_bss_8B3A0.unk_C[i].unk_2;

        if (kind == -1)
            continue;

        car->unk_00 = i;

        if (kind == 0x20)
            car->unk_48 = lbl_1_rodata_8BC8;
        else if (kind == 0x27)
            car->unk_48 = lbl_1_rodata_8BCC;
        else
            car->unk_48 = lbl_1_rodata_8BD0;

        v = (*(Track *)&lbl_1_rodata_26F8);
        v.unk_04 = lbl_1_rodata_8B60;
        v.unk_08 = x;
        v.unk_0C = lbl_1_rodata_8BD4;
        v.unk_30 = 10;

        if (lbl_1_bss_8CA28.unk_0 != 0) {
            v.unk_10 *= lbl_1_rodata_8638;
            v.unk_14 *= lbl_1_rodata_8638;
        }

        v.unk_10 *= lbl_1_rodata_8BD8;
        v.unk_14 *= lbl_1_rodata_8BD8;

        fn_1_8CED0((fn_1_13A038_Sig_fn_1_8CED0_Fn1_8CED0State *)(car->unk_20 + off), 0x1A0, 0xC0);
        *(f32 *)(car->unk_20 + off + 0x44) = (*(const f32 *)&lbl_1_rodata_87D0);
        fn_1_8D3F8((fn_1_13A038_Sig_fn_1_8D3F8_Fn1_8D3F8Car *)(car->unk_20 + off), &v, fn_1_131C08, car);

        x += 201;
        off += 100;
    }
}
/* fzgx:end fn_1_13A038 */

/* fzgx:begin fn_1_13A21C */
typedef struct {
    u32 v[8];
} Word8_fn_1_13A21C;

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
} Sp8_fn_1_13A21C;

typedef struct {
    u32 value[22];
} Fn139F18Data_fn_1_13A21C;

typedef struct StaticDispParams_fn_1_13A21C {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams_fn_1_13A21C;

struct Struct_26F8_fn_1_13A21C {
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
} PtrTab_fn_1_13A21C;

struct fn_1_13F8C4_lbl_801A6410_fn_1_13A21C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_13A21C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440_fn_1_13A21C {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source_fn_1_13A21C;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display_fn_1_13A21C;

struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_13A21C {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_13A21C {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_13A21C {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_13A21C **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry_fn_1_13A21C;

typedef struct fn_1_150C8C_Entry_fn_1_13A21C {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry_fn_1_13A21C;

typedef struct fn_1_150C8C_Object_fn_1_13A21C {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry_fn_1_13A21C entries[1];
} fn_1_150C8C_Object_fn_1_13A21C;

typedef struct fn_1_150F30_StaticDisp_fn_1_13A21C {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp_fn_1_13A21C;

typedef struct Fn14E09CValue_fn_1_13A21C {
    void *value;
} Fn14E09CValue_fn_1_13A21C;

typedef struct Fn14E09CRef_fn_1_13A21C {
    u8 pad8[8];
    Fn14E09CValue_fn_1_13A21C *value;
} Fn14E09CRef_fn_1_13A21C;

typedef struct Fn14E09CObj_fn_1_13A21C {
    u8 pad344[0x344];
    Fn14E09CRef_fn_1_13A21C *ref;
} Fn14E09CObj_fn_1_13A21C;

typedef struct DispNode_fn_1_13A21C {
    u8 pad[4];
    f32 value;
} DispNode_fn_1_13A21C;

typedef struct DispChildList_fn_1_13A21C {
    DispNode_fn_1_13A21C *child[3];
} DispChildList_fn_1_13A21C;

typedef struct DispObject_fn_1_13A21C {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList_fn_1_13A21C *children;
} DispObject_fn_1_13A21C;

typedef struct fn_1_151668_StaticDispEntry_fn_1_13A21C {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject_fn_1_13A21C *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry_fn_1_13A21C;

typedef struct fn_1_151668_StaticDisp_fn_1_13A21C {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry_fn_1_13A21C entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp_fn_1_13A21C;


typedef struct fn_1_13A21C_Player {
    u8 pad_0[0xE];
    s16 character;
    u8 pad_10[0x10];
} fn_1_13A21C_Player;

typedef struct fn_1_13A21C_Obj {
    s16 player;
    u8 pad_2[0x1E];
    u8 *icons;
    u8 pad_24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} fn_1_13A21C_Obj;




void fn_1_13A21C(fn_1_13A21C_Obj *obj) {
    FontDrawPacket packet;
    s32 offset;
    s32 i;
    s16 character;
    u8 slot;

    obj->unk_38 = 0.6f;
    obj->unk_3C = -1.3f;
    obj->unk_40 = -16.0f;
    obj->unk_44 = 0.2f;
    obj->unk_4C = 0.0f;
    for (i = 0, offset = 0; i < 4; i++) {
        character = ((fn_1_13A21C_Player *)&lbl_1_bss_8B3A0)[i].character;
        slot = fn_1_141F94((u8)i);
        if (character == -1) {
            continue;
        }
        obj->player = i;
        if (character == 0x20) {
            obj->unk_48 = 1.12f;
        } else if (character == 0x27) {
            obj->unk_48 = 0.6f;
        } else if (character == 0x1D) {
            obj->unk_48 = 0.12f;
        } else {
            obj->unk_48 = 0.0f;
        }
        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.x = (slot % 2) * 0x12D + 0xE3;
        packet.y = (slot >> 1) * 0xCA + 0xB0;
        packet.z = 161.0f;
        packet.flags = 10;
        if (*(u8 *)&lbl_1_bss_8CA28) {
            packet.scale_x *= 2.0f;
            packet.scale_y *= 2.0f;
        }
        packet.scale_x *= 1.1f;
        packet.scale_y *= 1.1f;
        fn_1_8CED0(obj->icons + offset, 0xA0, 0x78);
        *(f32 *)(obj->icons + offset + 0x44) = 30.0f;
        fn_1_8D3F8(obj->icons + offset, &packet, fn_1_131C08, obj);
        offset += 0x64;
    }
}
/* fzgx:end fn_1_13A21C */

/* fzgx:begin fn_1_13A460 */
struct fn_1_13A460_Arg0 {
    u16 unk_0;
    u8 pad_2[0x22];
    u32 unk_24;
    u8 pad_28[0x10];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
};


struct fn_1_13A460_Ent {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
};






#pragma opt_loop_invariants off
static inline f32 fn_1_13A460_read_pointer(struct fn_1_13A460_Loc * owner) { return owner->f_10; }
void fn_1_13A460(struct fn_1_13A460_Arg0 *arg0) {
    f32 *fzgx_value_;
    struct fn_1_13A460_Loc loc;
    s32 stepC9;
    s32 step64;
    s32 i = 0;
    f32 fzgx_live;
    f32 fzgx_live_;
    f32 fzgx_value;

    stepC9 = 0x9C;
    step64 = 0;

    arg0->unk_38 = lbl_1_rodata_87B8;
    arg0->unk_3C = lbl_1_rodata_85F0;
    arg0->unk_40 = lbl_1_rodata_8BF0;
    fzgx_value_ = &arg0->unk_44;
    *fzgx_value_ = lbl_1_rodata_8BF4;
    arg0->unk_48 = lbl_1_rodata_8664;
    arg0->unk_4C = lbl_1_rodata_861C;

    for (; i < 4; i++) {
        s32 v = (((struct fn_1_13A460_Ent *)&lbl_1_bss_8B3A0)[i].unk_E);
        if (v != -1) {
            arg0->unk_0 = i;
            loc = (*((const struct fn_1_13A460_Loc *)&lbl_1_rodata_26F8));
            loc.f_04 = lbl_1_rodata_8BF8;
            loc.f_08 = stepC9;
            loc.f_0C = lbl_1_rodata_880C;
            loc.n_30 = 10;
            if (lbl_1_bss_8CA28.unk_0 != 0) {
                fzgx_live = fn_1_13A460_read_pointer(&loc);
                fzgx_value = fzgx_live * lbl_1_rodata_8638;
                (void) fzgx_value;  /* fzgx: keeps the web at its definition */
                loc.f_10 = fzgx_value;
                loc.f_14 = loc.f_14 * lbl_1_rodata_8638;
            }
            fzgx_live = fn_1_13A460_read_pointer(&loc);
            loc.f_10 = fzgx_live * lbl_1_rodata_8BFC;
            fzgx_live_ = loc.f_14;
            loc.f_14 = fzgx_live_ * lbl_1_rodata_8BFC;
            if (v == 0x21) {
                loc.f_08 = loc.f_08 - lbl_1_rodata_8B28;
            }
            fn_1_8CED0( (void*)((fn_1_13A460_Sig_fn_1_8CED0_Fn1_8CED0State *)((u8 *)arg0->unk_24 + step64)), 0x1A0, 0xC0);
            *(f32 *)((u8 *)arg0->unk_24 + step64 + 0x44) = lbl_1_rodata_87D0;
            fn_1_8D3F8( (void*)((fn_1_13A460_Sig_fn_1_8D3F8_Fn1_8D3F8Car *)(arg0->unk_24 + step64)), &loc, (void*)((u32 (*)(u32))fn_1_131B90), (void*)((u32)arg0));
            stepC9 += 0xC9;
            step64 += 0x64;
        }
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_13A460 */

/* fzgx:begin fn_1_13A654 */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} fn_1_13A654_Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
fn_1_13A654_Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} fn_1_13A654_Obj_1_bss_8B3A0;


typedef struct {
u8 unk_0;
u8 pad_1[0x17];
} fn_1_13A654_Obj_1_bss_8CA28;




struct Elem { u8 pad_0[0xe]; s16 unk_E; u8 pad_10[0x10]; };
struct Arg { s16 index; u8 pad_2[0x22]; u8 *unk_24; u8 pad_28[0x10]; f32 f[6]; };


struct fn_1_13A654_Copy88 { f32 a[22]; };














void fn_1_13A654(struct Arg *arg0) {
s32 off;
s32 i;
struct fn_1_13A654_Copy88 loc;
i = 0;
arg0->f[0] = lbl_1_rodata_861C;
arg0->f[1] = lbl_1_rodata_8C00;
arg0->f[2] = lbl_1_rodata_8C04;
arg0->f[3] = lbl_1_rodata_8C08;
arg0->f[4] = lbl_1_rodata_864C;
arg0->f[5] = lbl_1_rodata_861C;
off = 0;
for (; i < 4; i++) {
s16 v = (((struct Elem *)&(*((fn_1_13A654_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0))))[i].unk_E;
u8 k = fn_1_141F94((u8)i);
if (v != -1) {
arg0->index = i;
loc = (*((struct fn_1_13A654_Copy88 *)&lbl_1_rodata_26F8));
loc.a[1] = ((k % 2) * 300 + 224);
loc.a[2] = (((k >> 1) & 0x7f) * 200 + 176);
loc.a[3] = lbl_1_rodata_880C;
((s32 *)&loc)[12] = 10;
if ((*((u8 *)&(*((fn_1_13A654_Obj_1_bss_8CA28 *)&lbl_1_bss_8CA28)))) != 0) {
loc.a[4] = loc.a[4] * lbl_1_rodata_8638;
loc.a[5] = loc.a[5] * lbl_1_rodata_8638;
}
loc.a[4] = loc.a[4] * lbl_1_rodata_8C0C;
loc.a[5] = loc.a[5] * lbl_1_rodata_8C0C;
fn_1_8CED0(arg0->unk_24 + off, 0xa0, 0x8c);
*(f32 *)(arg0->unk_24 + off + 0x44) = lbl_1_rodata_87D0;
fn_1_8D3F8(arg0->unk_24 + off, &loc, fn_1_131B90, arg0);
off += 100;
}
}
}
/* fzgx:end fn_1_13A654 */

/* fzgx:begin fn_1_13A848 noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

void fn_1_13A848(s16 arg0, s16 arg1, void* arg2, void* arg3, int arg4, f32 arg5, f32 arg6) {
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_495B0(0x8001 << 16);
    fn_1_49738(&fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_87DC);
    fn_1_495C8(arg2);
    fn_1_4966C(lbl_1_rodata_863C, lbl_1_rodata_861C);
    fn_1_4955C(arg5, arg6);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_496FC(arg0, arg1);
    if (arg4 == 1) {
        fn_1_4A0D8( (const char*)(&lbl_1_data_41B1C));
    } else {
        fn_1_4A0D8( (const char*)(((u32*)&lbl_1_data_212A8)[fn_1_12C930(arg3)]));
    }
}
/* fzgx:end fn_1_13A848 */

/* fzgx:begin fn_1_13A994 noprologue */
void fn_1_13A994(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    fn_1_13A9B8(arg0, arg1, arg2, arg3, arg4, arg5, -1);
}
/* fzgx:end fn_1_13A994 */

/* fzgx:begin fn_1_13A9B8 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_49514(u32*);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*func)(void));
extern const f32 lbl_1_rodata_861C;
extern void fn_1_49748(f32);
extern const f32 lbl_1_rodata_87DC;
extern void fn_1_4954C(f32);
extern void fn_1_495C8(int);
extern void fn_1_4955C(f32, f32);
extern const f32 lbl_1_rodata_85F0;
extern void fn_1_49590(f32);
extern const f64 lbl_1_rodata_8600;
extern void fn_1_496FC(f32, f32);
extern u8 lbl_1_data_41B24[24];
extern void fn_1_4CF3C(void*, ...);
extern s16 fn_1_12C930(void*);
extern u8 lbl_1_data_21078[180];
extern void fn_1_4AE0C(void*, ...);

void fn_1_13A9B8(f32 arg7, f32 arg8, s16 arg0, s16 arg1, int arg2, void* arg3,
                 s16 arg4, int arg5, int arg6) {
    u32 local;

    if (arg4 == 0) return;
    fn_1_49410();
    local = *(u32*)&lbl_1_rodata_8C10;
    fn_1_49514(&local);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_87DC);
    fn_1_495C8(arg2);
    fn_1_4955C(arg7, arg8);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_496FC(arg0, arg1);

    if (arg6 != -1) {
        if (arg5 != 0) {
            fn_1_4CF3C(lbl_1_data_41B24, (f32)arg6);
        } else {
            fn_1_4CF3C(&lbl_1_data_41A30,
                       ((u32*)lbl_1_data_21078)[fn_1_12C930(arg3)], (f32)arg6);
        }
    } else if (arg5 != 0) {
        fn_1_4AE0C(lbl_1_data_41B24);
    } else {
        s16 index = fn_1_12C930(arg3);
        fn_1_4AE0C(&lbl_1_data_41A30, ((u32*)lbl_1_data_21078)[index]);
    }
}
/* fzgx:end fn_1_13A9B8 */

/* fzgx:begin fn_1_13ABA8 */

#define DRAW_CASE(bit,offset,id) \
    case bit: \
        width += fn_1_13B24C(pass, width + start, 439, 21, (const char*)(p_lbl_1_data_40F58 + offset)); \
        width += fn_1_13B24C(pass, width + start, 439, textHeight, (const char*)fn_1_13F7F8(id, (*((s32 *)&lbl_801A66B4)))); \
        break;


u8 lbl_1_data_41AF8[0x24] = {
    0x42U, 0x41U, 0x4CU, 0x41U, 0x4EU, 0x43U, 0x45U, 0x00U, 0x20U, 0x20U, 0x20U, 0x20U, 0x43U, 0x4FU, 0x4CU, 0x4FU, 0x52U, 0x20U, 0x20U, 0x20U, 0x20U, 0x4FU, 0x4BU, 0x00U, 0x83U, 0xA1U, 0x83U, 0xAFU, 0x00U, 0x00U, 0x00U, 0x00U, 0x83U, 0x9FU, 0x00U, 0x00U
};
u8 lbl_1_data_41B1C[0x6] = "\077\077\077\077\077";
u8 lbl_1_data_41B24[0x18] = {
    0x3FU, 0x3FU, 0x3FU, 0x3FU, 0x3FU, 0x3FU, 0x3FU, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x83U, 0xA0U, 0x00U, 0x00U, 0x83U, 0xB2U, 0x00U, 0x00U, 0x83U, 0xB4U, 0x00U, 0x00U
};
u8 lbl_1_data_41B3C[0x18] = {
    0x83U, 0xA4U, 0x00U, 0x00U, 0x83U, 0xADU, 0x83U, 0xB5U, 0x83U, 0xD0U, 0x00U, 0x00U, 0x83U, 0xADU, 0x83U, 0xB5U, 0x00U, 0x00U, 0x00U, 0x00U, 0x83U, 0xB0U, 0x00U, 0x00U
};

void fn_1_13ABA8(u32 arg0) {
    struct fn_1_13ABA8_packet loc_38;
    struct fn_1_13ABA8_lbl_1_rodata_8C14 loc_20;
    struct fn_1_13ABA8_lbl_1_rodata_8C2C loc_8;
    s32 start;
    s32 pass;
    s32 width;
    s32 textHeight;
    u8 *p_lbl_1_data_40F58;
    u32 remaining;
    u32 bit;
    s32 totalWidth;
    u8 nextBit;
    u32 bitMask;
    struct { s32 *ptr; s32 offset; } spacing;
    p_lbl_1_data_40F58 = (u8*)&lbl_1_data_40F58;
    totalWidth = 0;
    loc_20 = lbl_1_rodata_8C14;
    loc_8 = lbl_1_rodata_8C2C;
    loc_38 = (*((struct fn_1_13ABA8_packet *)&lbl_1_rodata_26F8));
    loc_38.flags = 0x9A02;
    loc_38.x = lbl_1_rodata_861C;
    loc_38.y = lbl_1_rodata_8C44;
    loc_38.z = lbl_1_rodata_8C48;
    fn_1_4F734((FontDrawPacket*)&loc_38);
    if (fn_1_B7C00() != 0) return;
    fn_1_49410();
    fn_1_495C8(8);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_495B0(0x80000000);
    spacing.ptr = (s32*)&loc_20;
    for (pass = 0; pass <= 1; pass++) {
        textHeight = ((s32*)&loc_8)[(*((s32 *)&lbl_801A66B4))];
        start = 320 - totalWidth / 2;
        remaining = arg0;
        width = 0;
        nextBit = __cntlzw(arg0);
        for (; remaining != 0;
             nextBit = __cntlzw(remaining)) {
            bit = nextBit;
            switch (bit) {
                DRAW_CASE(4, 0xBC0, 3)
                DRAW_CASE(1, 0xBD8, 4)
                DRAW_CASE(0, 0xBB8, 5)
                DRAW_CASE(8, 0xBDC, 8)
                DRAW_CASE(9, 0xBE0, 9)
                DRAW_CASE(2, 0xBD8, 6)
                DRAW_CASE(5, 0xBE4, 10)
                DRAW_CASE(6, 0xBE8, 11)
                DRAW_CASE(7, 0xBF0, 12)
                DRAW_CASE(10, 0xBF8, 13)
                DRAW_CASE(3, 0xBD8, 7)
                DRAW_CASE(11, 0xBDC, 14)
                DRAW_CASE(12, 0xBDC, 15)
                DRAW_CASE(13, 0xBB8, 16)
                DRAW_CASE(14, 0xBE0, 17)
            }
            bitMask = (*((s32 *)&lbl_801A66B4)) * 4;
            width += *(s32 *)((u8 *)spacing.ptr + bitMask);
            bitMask = 0x80000000U >> bit;
            remaining &= ~bitMask;
        }
        width -= spacing.ptr[(*((s32 *)&lbl_801A66B4))];
        if (pass == 0) totalWidth = width;
    }
}
/* fzgx:end fn_1_13ABA8 */

/* fzgx:begin fn_1_13B24C noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

s32 fn_1_13B24C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, const char* arg4) {
    f32 temp;

    temp = arg3 / lbl_1_rodata_85FC;
    fn_1_4955C(temp, temp);
    if (arg0 != 0) {
        fn_1_496FC(arg1, arg2);
        fn_1_4A0D8(arg4);
    }
    return fn_1_4B068(arg4);
}
/* fzgx:end fn_1_13B24C */

/* fzgx:begin fn_1_13B328 noprologue */
void fn_1_13B328(u32 arg0, s32 arg1) {
    FontDrawPacket packet;
    PtrTab tab;
    const char *temp_r29;
    s32 var_r28;
    s32 var_r27;
    s32 var_r26;
    s32 var_r25;
    u32 var_r24;
    u8 var_r23;

    var_r26 = 0;
    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (arg1 != 0) ? 0x9E02 : 0x9A02;
    packet.x = lbl_1_rodata_861C;
    packet.y = lbl_1_rodata_8C44;
    packet.z = lbl_1_rodata_8C48;
    fn_1_4F734(&packet);

    if (lbl_1_bss_8B3A0.unk_129 != 0) {
        fn_1_49410();
        fn_1_49590(lbl_1_rodata_85F0);
        var_r27 = 0;
        do {
            var_r24 = arg0;
            var_r23 = __cntlzw(arg0);
            var_r25 = 0;
            var_r28 = 320 - var_r26 / 2;
            while (var_r24 != 0) {
                tab = lbl_1_rodata_8C4C;
                var_r25 += fn_1_13B548(var_r27, var_r25 + var_r28, 0x1AC, var_r23);
                if (var_r23 != 6) {
                    temp_r29 = tab.p[var_r23];
                    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
                    if (var_r27 != 0) {
                        fn_1_496FC((var_r25 + var_r28), lbl_1_rodata_8C74);
                        fn_1_4A0D8(temp_r29);
                    }
                    var_r25 += (s32)fn_1_4B068(temp_r29);
                    var_r25 += 0x18;
                }
                var_r24 &= ~(0x80000000U >> var_r23);
                var_r23 = __cntlzw(var_r24);
            }
            if (var_r27 == 0) {
                var_r26 = var_r25 - 0x18;
            }
            var_r27++;
        } while (var_r27 <= 1);
    }
}
/* fzgx:end fn_1_13B328 */

/* fzgx:begin fn_1_13B548 */
struct fn_1_13B548_Copy88 { u32 a[22]; };

#pragma opt_common_subs off
s32 fn_1_13B548(u32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    f32 v0;
    u32 v64;
    u32 v4;
    s32 unk_1;
    s32 v1;
    s32 v10;
    s32 v11;
    s32 v65 = 0;
    s32 v12;
    u32 v13;
    s32 v14;
    u32 v15;
    s32 v16;
    u32 v17;
    s32 v18;
    u32 v19;
    s32 v20;
    u32 v36;
    u32 v37;
    f32 overlay_z;
    FontDrawPacket loc_10;
    struct fn_1_13B548_lbl_1_rodata_8C78 loc_C;
    struct fn_1_13B548_lbl_1_rodata_8C78 loc_8;
    s16 t3;
    if ((s32)arg0 != 0) {
        loc_C = lbl_1_rodata_8C78;
        loc_8.unk_0 = lbl_1_rodata_8C7C;
        loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
        v1 = (u8)arg3;
        loc_10.x = arg1;
        loc_10.y = arg2;
        loc_10.z = lbl_1_rodata_8C9C;
        switch (v1) {
        case 0: case 1: case 2: case 3: case 4: case 6:
            loc_10.image = 0x9E09;
            fn_1_4F734(&loc_10);
            break;
        case 5: case 7: case 8:
            loc_10.image = 0x9E11;
            fn_1_4F734(&loc_10);
            break;
        }
        v64 = lbl_801A66A0;
        v4 = v64 % 60;
        unk_1 = v4 < 30;
        if (unk_1) {
            loc_C = *(struct fn_1_13B548_lbl_1_rodata_8C78 *)&lbl_1_rodata_8C80;
        }
        if (!unk_1) {
            loc_8 = *(struct fn_1_13B548_lbl_1_rodata_8C78 *)&lbl_1_rodata_8C84;
        }
        switch (v1) {
        case 0:
            v10 = 0;
            v11 = 0;
            v12 = 9;
            switch ((s32)(v64 % 240) / 60) {
            case 0:
                v13 = v4 / 3;
                v14 = 11;
                if (v13 < 11) v14 = v13;
                v10 = v14;
                break;
            case 1:
                v15 = v4 / 3;
                v16 = 11;
                if (v15 < 11) v16 = v15;
                v11 = v16;
                break;
            case 2:
                v17 = v4 / 3;
                v18 = 9;
                if (v17 < 9) v18 = v17;
                v12 = 9 - v18;
                break;
            case 3:
                v19 = v4 / 3;
                v20 = 9;
                if (v19 < 9) v20 = v19;
                v12 = v20 + 10;
                break;
            }
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E12;
            loc_10.x = lbl_1_rodata_8CA0 + arg1;
            loc_10.y = (arg2 - 2);
            loc_10.z = lbl_1_rodata_8A54;
            fn_1_4F734(&loc_10);
            t3 = fn_1_48690(loc_10.image);
            fn_1_51678(&loc_10, loc_10.image, 0, v12, t3, 10);
            v0 = loc_10.y + v12;
            loc_10.z = (*((struct fn_1_13B548_lbl_1_rodata_8B3C *)&lbl_1_rodata_8B3C)).unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C88.unk_0;
            loc_10.y = v0;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (arg1 - 8);
            loc_10.y = arg2;
            loc_10.z = lbl_1_rodata_8A54;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, loc_10.image, 0, 0, 8, v10);
            overlay_z = (*((struct fn_1_13B548_lbl_1_rodata_8B3C *)&lbl_1_rodata_8B3C)).unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C8C;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (arg1 + 37);
            loc_10.y = arg2;
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.flags = 0x80000;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, loc_10.image, 0, 0, 8, v11);
            overlay_z = (*((struct fn_1_13B548_lbl_1_rodata_8B3C *)&lbl_1_rodata_8B3C)).unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C90;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            break;
        case 1: case 2:
            v10 = 0;
            v11 = v10;
            switch ((s32)(v64 % 120) / 60) {
            case 0:
                v10 = 11;
                v36 = v4 / 3;
                if (v36 < 11) v10 = v36;
                break;
            case 1:
                v11 = 11;
                v37 = v4 / 3;
                if (v37 < 11) v11 = v37;
                break;
            }
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (arg1 - 8);
            loc_10.y = arg2;
            loc_10.z = lbl_1_rodata_8A54;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, loc_10.image, 0, 0, 8, v10);
            overlay_z = (*((struct fn_1_13B548_lbl_1_rodata_8B3C *)&lbl_1_rodata_8B3C)).unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C94;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (arg1 + 37);
            loc_10.y = arg2;
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.flags = 0x80000;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, loc_10.image, 0, 0, 8, v11);
            overlay_z = (*((struct fn_1_13B548_lbl_1_rodata_8B3C *)&lbl_1_rodata_8B3C)).unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C98;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            break;
        case 3: case 4:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E10;
            loc_10.x = (arg1 + 6);
            loc_10.y = (arg2 + 6);
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E10;
            loc_10.x = (arg1 + 24);
            loc_10.y = (arg2 + 6);
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.flags = 0x80000;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_8.unk_0;
            fn_1_4F734(&loc_10);
            break;
        case 6:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.x = lbl_1_rodata_8CA8 + arg1;
            loc_10.y = (arg2 + 9);
            loc_10.image = 0x9E07;
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E07;
            loc_10.x = (arg1 + 27);
            loc_10.y = (arg2 + 9);
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.scale_x *= (*((struct fn_1_13B548_lbl_1_rodata_85F0 *)&lbl_1_rodata_85F0)).unk_0;
            loc_10.scale_y *= (*((struct fn_1_13B548_lbl_1_rodata_85F0 *)&lbl_1_rodata_85F0)).unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            break;
        case 5:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E08;
            loc_10.x = (arg1 + 3);
            loc_10.y = (arg2 + 5);
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            break;
        case 7: case 8:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E06;
            loc_10.x = (arg1 + 14);
            loc_10.y = (arg2 + 1);
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            break;
        }
    }
    switch ((arg3 & 0xFF)) {
    case 0: case 1: case 2: v65 = 43; break;
    case 3: case 4: v65 = 35; break;
    case 6: v65 = 39; break;
    case 5: case 7: case 8: v65 = 24; break;
    }
    return v65;
}
/* fzgx:end fn_1_13B548 */

/* fzgx:begin fn_1_13C134 */
void fn_1_13C134(void) {
    fn_1_5621C(lbl_1_rodata_861C, lbl_1_rodata_861C,
               lbl_1_rodata_861C, lbl_1_rodata_85EC);
}
/* fzgx:end fn_1_13C134 */

/* fzgx:begin fn_1_13C16C */
void fn_1_13C16C(void) {
    fn_1_5621C(lbl_1_rodata_863C, lbl_1_rodata_863C,
               lbl_1_rodata_863C, lbl_1_rodata_863C);
}
/* fzgx:end fn_1_13C16C */

/* fzgx:begin fn_1_13C1A0 */
struct Copy88 { u32 words[22]; };
struct Copy200 { u32 words[10][5]; };

#pragma opt_common_subs off
void fn_1_13C1A0(u8 *arg0) {
    char buf[256];
    struct Copy88 loc_60;
    struct Copy88 loc_8;
    struct Copy200 loc_B8;
    u32 temp_r31;
    u8 tempbyte;
    u32 temp_r30;
    u32 temp_r28;
    u32 idx;
    f32 var_f31;
    u32 lab_t2;

    fn_1_133E04( (s32)(void*)((void *)1), 0);
    fn_1_134AD4();
    if (lbl_1_bss_960 == 9) {
        loc_B8 = *(struct Copy200 *)lbl_1_rodata_8CB0;
        tempbyte = lbl_1_bss_9C;
        loc_60 = *(struct Copy88 *)(&lbl_1_rodata_26F8);
        (*((0) + loc_60.words)) = 0xBA16;
        *(f32 *)((u8 *)&loc_60 + 4) = lbl_1_rodata_882C;
        *(f32 *)((u8 *)&loc_60 + 8) = lbl_1_rodata_8830;
        *(f32 *)((u8 *)&loc_60 + 12) = lbl_1_rodata_8834;
        *(u32 *)((u8 *)&loc_60 + 0x30) = 0xA;
        fn_1_4F734((FontDrawPacket *)&loc_60);
        fn_1_13ABA8(0x28000000);
        fn_1_140EE8(arg0[0], 0, 1);
        if ((s8)tempbyte == 2 || (u8)(tempbyte - 4) <= 1 || (s8)tempbyte == 6) {
            var_f31 = lbl_1_rodata_8BEC;
        } else {
            var_f31 = lbl_1_rodata_8D78;
        }
        temp_r31 = ((fn_1_A5DB0() - lbl_1_rodata_8B58) - lbl_1_rodata_8B84);
        temp_r28 = (lbl_1_rodata_863C * fn_1_A5D88());
        temp_r30 = lbl_1_rodata_8B58;
        lab_t2 = (lbl_1_rodata_861C * fn_1_A5D88());
        fn_1_7B558(1, 1, lab_t2, temp_r30, temp_r28, temp_r31, var_f31);
        sprintf(buf, (const char *)&lbl_1_data_41DE4, loc_B8.words[(s8)tempbyte][lbl_801A66B4]);
        fn_1_138144( (s32)(void*)(buf), lbl_1_bss_8B3A0.unk_94 & 0x40000000);
        return;
    }
    loc_8 = *(struct Copy88 *)(&lbl_1_rodata_26F8);
    (*((0) + loc_8.words)) = 0x9A12;
    *(f32 *)((u8 *)&loc_8 + 4) = lbl_1_rodata_882C;
    *(f32 *)((u8 *)&loc_8 + 8) = lbl_1_rodata_8830;
    *(f32 *)((u8 *)&loc_8 + 12) = lbl_1_rodata_8834;
    *(u32 *)((u8 *)&loc_8 + 0x30) = 0xA;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_13ABA8(0x08000000);
    fn_1_13C5EC(arg0[0]);
    temp_r31 = (lbl_1_rodata_8A4C * fn_1_A5DB0());
    temp_r30 = (lbl_1_rodata_8A4C * fn_1_A5D88());
    lab_t2 = (lbl_1_rodata_87AC * fn_1_A5D88());
    fn_1_7B558(1, 1, lab_t2, 0, temp_r30, temp_r31, lbl_1_rodata_8D7C);
    idx = lbl_801A66B4;
    sprintf(buf, (const char *)fn_1_13F7F8(0x13, idx),
            *(u32 *)(lbl_1_data_2BD54 + arg0[0] * 0x18 + idx * 4));
    fn_1_138144( (s32)(void*)(buf), lbl_1_bss_8B3A0.unk_94 & 0x40000000);
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_13C1A0 */

/* fzgx:begin fn_1_13C5EC */






#pragma pool_data off
#pragma opt_propagation off
void fn_1_13C5EC(u8 arg0) {
    FontDrawPacket packet;
    fn_1_13C5EC_Color hi;
    fn_1_13C5EC_Color lo;
    s16 group;
    s16 sel;
    s32 y;
    s32 i;
    s16 id;
    s32 selected;
    s32 tick;
    s32 glow;
    f32 frame;
    s32 icon;
    s16 idx;
    f32 alpha;
    f32 pulse;

    sel = 0;
    if (lbl_1_bss_960 != 9) {
        fn_1_141C10(arg0);
    }
    id = arg0;
    fn_1_12EF80(id, &group, &sel);
    fn_1_140EE8(arg0, 0, 0);
    if (fn_1_B7C00() != 0) {
        return;
    }
    fn_1_14108C(group, 0x44, 0x78);
    fn_1_141614(id);
    fn_1_141754(0x4D, 0x15C);
    for (i = 0, y = 154; i < 5; i++, y += 82) {
        hi = lbl_1_rodata_8D80;
        lo = lbl_1_rodata_8D84;
        selected = (i == sel);
        if (selected) {
            pulse = 40.0f * (1.0f + lbl_8006D188((s32)(65536.0f * (lbl_801A66A0 % 60) / 60.0f)));
            hi.r = hi.g = hi.b = (pulse * lbl_1_rodata_85F0);
        }
        if (!selected) {
            lo.r = lo.g = lo.b = 0xA0;
        }
        if (i == sel) {
            if (((s32)fn_1_40F34()) >= 40) {
                lbl_1_bss_8E3E0 = lbl_1_bss_8E3E0 + 0.3f * (lbl_1_bss_8E3E0 - 41.0f);
                lbl_1_bss_8E3E0 = ((lbl_1_bss_8E3E0 < (0.0f)) ? (0.0f) : ((lbl_1_bss_8E3E0 > (40.0f)) ? (40.0f) : lbl_1_bss_8E3E0));
            } else {
                lbl_1_bss_8E3E0 = 40.0f;
            }
            if ((((s32)fn_1_40F34()) > 75) ? 0 : (((s32)fn_1_40F34()) >= 60)) {
                tick = ((s32)fn_1_40F34()) - 60;
                frame = tick % 30;
                glow = (255.0f * lbl_8006D188((s32)(65536.0f * frame / 30.0f)));
            } else {
                glow = 0;
            }
            if (((s32)fn_1_40F34()) >= 190) {
                lbl_1_data_41DE8 = lbl_1_data_41DE8 + 0.5f * (0.05f - lbl_1_data_41DE8);
                lbl_1_data_41DE8 = ((lbl_1_data_41DE8 < (0.05f)) ? (0.05f) : ((lbl_1_data_41DE8 > (1.0f)) ? (1.0f) : lbl_1_data_41DE8));
            } else {
                lbl_1_data_41DE8 = 1.0f;
            }
            alpha = (40.0f - lbl_1_bss_8E3E0) / 40.0f;
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xA10D;
            packet.x = y - (40.0f + lbl_1_bss_8E3E0);
            packet.y = 366.0f - (40.0f + lbl_1_bss_8E3E0);
            packet.z = 35.0f;
            packet.alpha = alpha;
            fn_1_4F734(&packet);

            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xA10D;
            packet.x = y + (40.0f + lbl_1_bss_8E3E0);
            packet.y = 366.0f - (40.0f + lbl_1_bss_8E3E0);
            packet.z = 35.0f;
            packet.flags = 0x80007;
            packet.alpha = alpha;
            fn_1_4F734(&packet);

            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xA10D;
            packet.x = y - (40.0f + lbl_1_bss_8E3E0);
            packet.y = 366.0f + (40.0f + lbl_1_bss_8E3E0);
            packet.z = 35.0f;
            packet.flags = 0x10000D;
            packet.alpha = alpha;
            fn_1_4F734(&packet);

            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xA10D;
            packet.x = y + (40.0f + lbl_1_bss_8E3E0);
            packet.y = 366.0f + (40.0f + lbl_1_bss_8E3E0);
            packet.z = 35.0f;
            packet.flags = 0x18000F;
            packet.alpha = alpha;
            fn_1_4F734(&packet);

            if (lbl_1_data_41DE8 > 0.060000002f) {
                packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
                packet.image = 0xA10C;
                packet.x = y;
                packet.y = 366.0f;
                packet.z = 35.0f;
                packet.scale_x *= (2.0f - alpha) / lbl_1_data_41DE8;
                packet.scale_y *= (2.0f - alpha) * lbl_1_data_41DE8;
                packet.flags = 10;
                packet.alpha = alpha;
                packet.color_add[0] = packet.color_add[1] = packet.color_add[2] = (((128.0f * (1.0f - lbl_1_data_41DE8) + glow) < (0.0f)) ? (0.0f) : (((128.0f * (1.0f - lbl_1_data_41DE8) + glow) > (255.0f)) ? (255.0f) : (128.0f * (1.0f - lbl_1_data_41DE8) + glow)));
                fn_1_4F734(&packet);
            }
        }
        idx = fn_1_12EF24(group, i);
        if (lbl_1_bss_8B3A0.unk_8C == 0) {
            idx = lbl_1_bss_8B3A0.unk_90;
        }
        icon = (((u8 *)&lbl_1_data_2B144))[(((u8 *)&lbl_1_data_2B0D4))[idx]];

        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.x = y;
        packet.y = 366.0f;
        packet.z = 60.0f;
        packet.flags = 10;
        packet.image = 0xA100;
        fn_1_51564(0, 0, 0x48, 0x48, 7, 2);
        fn_1_5158C(&packet, packet.image, (icon - 1) % 7, (icon - 1) / 7);
        *(fn_1_13C5EC_Color *)packet.color_add = hi;
        *(fn_1_13C5EC_Color *)packet.color = lo;
        fn_1_4F734(&packet);

        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0xA10E;
        packet.x = y;
        packet.y = 366.0f;
        packet.z = 50.0f;
        *(fn_1_13C5EC_Color *)packet.color_add = hi;
        packet.flags = 10;
        fn_1_4F734(&packet);

        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0xA12F;
        packet.x = y;
        packet.y = 366.0f;
        packet.z = 40.0f;
        packet.flags = 10;
        fn_1_4F734(&packet);
    }
    if (sel != -1) {
        fn_1_141A80(id);
    }
}
#pragma opt_propagation reset
#pragma pool_data reset
/* fzgx:end fn_1_13C5EC */

/* fzgx:begin fn_1_13D02C */
typedef struct {
    u32 v[8];
} Word8_np_fn_1_13D02C;

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
} Sp8_np_fn_1_13D02C;

typedef struct {
    u32 value[22];
} Fn139F18Data_np_fn_1_13D02C;

typedef struct StaticDispParams_np_fn_1_13D02C {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams_np_fn_1_13D02C;

struct Struct_26F8_np_fn_1_13D02C {
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
} PtrTab_np_fn_1_13D02C;

struct fn_1_13F8C4_lbl_801A6410_np_fn_1_13D02C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C_np_fn_1_13D02C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440_np_fn_1_13D02C {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source_np_fn_1_13D02C;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display_np_fn_1_13D02C;

struct Sig_fn_80071718_fn_80071718_Arg0_np_fn_1_13D02C {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry_np_fn_1_13D02C {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0_np_fn_1_13D02C {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_np_fn_1_13D02C **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry_np_fn_1_13D02C;

typedef struct fn_1_150C8C_Entry_np_fn_1_13D02C {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry_np_fn_1_13D02C;

typedef struct fn_1_150C8C_Object_np_fn_1_13D02C {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry_np_fn_1_13D02C entries[1];
} fn_1_150C8C_Object_np_fn_1_13D02C;

typedef struct fn_1_150F30_StaticDisp_np_fn_1_13D02C {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp_np_fn_1_13D02C;

typedef struct Fn14E09CValue_np_fn_1_13D02C {
    void *value;
} Fn14E09CValue_np_fn_1_13D02C;

typedef struct Fn14E09CRef_np_fn_1_13D02C {
    u8 pad8[8];
    Fn14E09CValue_np_fn_1_13D02C *value;
} Fn14E09CRef_np_fn_1_13D02C;

typedef struct Fn14E09CObj_np_fn_1_13D02C {
    u8 pad344[0x344];
    Fn14E09CRef_np_fn_1_13D02C *ref;
} Fn14E09CObj_np_fn_1_13D02C;

typedef struct DispNode_np_fn_1_13D02C {
    u8 pad[4];
    f32 value;
} DispNode_np_fn_1_13D02C;

typedef struct DispChildList_np_fn_1_13D02C {
    DispNode_np_fn_1_13D02C *child[3];
} DispChildList_np_fn_1_13D02C;

typedef struct DispObject_np_fn_1_13D02C {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList_np_fn_1_13D02C *children;
} DispObject_np_fn_1_13D02C;

typedef struct fn_1_151668_StaticDispEntry_np_fn_1_13D02C {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject_np_fn_1_13D02C *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry_np_fn_1_13D02C;

typedef struct fn_1_151668_StaticDisp_np_fn_1_13D02C {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry_np_fn_1_13D02C entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp_np_fn_1_13D02C;



#pragma opt_propagation off
void fn_1_13D02C(void) {
    s32 v0;
    u32 v1;
    u32 v2;
    f32 v12;
    u32 v13;
    u32 v14;
    s32 v20;
    u32 v21;
    f32 v22;
    u32 v23;
    FontDrawPacket loc_38;
    struct { u32 a[5]; } loc_24;
    u32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    s32 t0;
    s32 t1;
    s32 t2;
    f32 t3;
    u32 t4;
    u32 t5;
    t0 = fn_1_12F258();
    if ((u32)(t0 + 0x10000) != 65535) {
        t1 = fn_1_12F258();
        v0 = (u32)t1 / 60 + 1;
    } else {
        v0 = 0;
    }
    v1 = lbl_1_rodata_8DA0;
    v2 = lbl_1_rodata_8DA4;
    loc_24.a[3] = v1;
    loc_24.a[2] = v2;
    loc_24.a[1] = lbl_1_rodata_8DA8;
    t2 = fn_1_12F258();
    v12 = (t2 % 60 % 120);
    t3 = lbl_8006D188((s32)(lbl_1_rodata_8B2C * v12 / lbl_1_rodata_8838));
    v12 = t3;
    v20 = 0;
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0) {
        if (v0 > 99) {
            v13 = 9;
            v14 = 9;
        } else {
            v13 = (v0 / 10) & 0xFF;
            v14 = (v0 % 10) & 0xFF;
        }
        switch (*(s16 *)&(*((u16 *)&lbl_1_bss_962))) {
        case 16: case 24:
            if (v0 < 10) v20 = 1;
            break;
        case 15: case 18: case 19: case 23:
            if (v0 < 6) v20 = 1;
            break;
        case 14:
            if (v0 < 4) v20 = 1;
            break;
        }
        if (v20 != 0) {
            v12 = (lbl_1_rodata_863C - t3);
            loc_20 = loc_24.a[2];
            loc_24.a[0] = loc_24.a[1];
            t4 = fn_1_539CC(&loc_24, &loc_20, v12);
            loc_24.a[4] = t4;
        } else {
            v12 = (lbl_1_rodata_863C - t3);
            loc_18 = loc_24.a[2];
            loc_1C = loc_24.a[3];
            t5 = fn_1_539CC(&loc_1C, &loc_18, v12);
            loc_24.a[4] = t5;
        }
        loc_38 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_38.image = (0x10000 - 25064);
        loc_38.x = lbl_1_rodata_8DAC;
        loc_38.y = lbl_1_rodata_8B84;
        loc_38.z = lbl_1_rodata_8DB0;
        fn_1_4F734((FontDrawPacket *)&loc_38);
        fn_1_49410();
        v12 = lbl_1_rodata_8DB4;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        fn_1_495C8( (u8)(void*)((void *)9));
        fn_1_494DC(37);
        loc_14 = loc_24.a[4];
        fn_1_49514(&loc_14);
        v12 = lbl_1_rodata_8C9C;
        fn_1_4954C(v12);
        v21 = (v13 & 0xFF);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v21);
        fn_1_494DC(38);
        v12 = lbl_1_rodata_8DB4;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        loc_10 = loc_24.a[3];
        fn_1_49514(&loc_10);
        v12 = lbl_1_rodata_8A2C;
        fn_1_4954C(v12);
        v12 = lbl_1_rodata_87B4;
        v22 = (v12 + (lbl_1_rodata_8808 * t3));
        v12 = v22;
        fn_1_495A0(v12);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v21);
        fn_1_49410();
        v12 = lbl_1_rodata_8DB8;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        fn_1_495C8( (u8)(void*)((void *)9));
        fn_1_494DC(37);
        loc_C = loc_24.a[4];
        fn_1_49514(&loc_C);
        v12 = lbl_1_rodata_8C9C;
        fn_1_4954C(v12);
        v23 = (v14 & 0xFF);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v23);
        fn_1_494DC(38);
        v12 = lbl_1_rodata_8DB8;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        loc_8 = loc_24.a[3];
        fn_1_49514(&loc_8);
        v12 = lbl_1_rodata_8A2C;
        fn_1_4954C(v12);
        v12 = v22;
        fn_1_495A0(v12);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v23);
    }
}

u8 lbl_1_data_41E1C[0x8] = "NO DATA";
u8 lbl_1_data_41E24[0xF] = "%02d;%02d<%03d";
char lbl_1_data_41E34[16] = "Very Heavy Load";
u8 lbl_1_data_41E44[0x9] = {0x92U, 0xB4U, 0x8FU, 0x64U, 0x97U, 0xCAU, 0x8BU, 0x89U, 0x00U};
/* fzgx:end fn_1_13D02C */

/* fzgx:begin fn_1_13D460 */
static inline s32 fn_1_13D460_strip_position(s32 x, s32 y) { return x + y; }
#pragma opt_propagation off
void fn_1_13D460(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    FontDrawPacket setup;
    FontDrawPacket packet;
    s32 total;
    s32 i;
    s32 count;
    s16 lab_t5;
    s16 lab_t2;

    setup = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    setup.image = arg3 ? (0x10000 - 0x61FF) : (0x10000 - 0x68F8);
    setup.y = arg1;
    setup.z = lbl_1_rodata_8B30;

    count = arg2 - 0x18;
    packet = setup;
    packet.x = arg0;
    lab_t5 = 4;
    lab_t2 = 0;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 0xC, lab_t5);
    fn_1_4F734(&packet);

    packet = setup;
    total = arg0 + arg2;
    packet.x = total;
    lab_t5 = 4;
    lab_t2 = 0;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 0xC, lab_t5);
    *(u32 *)((u8 *)&packet + 0x30) = 0x80007;
    fn_1_4F734(&packet);

    i = 0;

    while (i < count / fn_1_48690(setup.image)) {
        packet = setup;
        packet.x = (fn_1_13D460_strip_position(arg0, i * fn_1_48690(setup.image)) + 0xC);
        lab_t5 = 4;
        lab_t2 = 0;
        fn_1_51678(&packet, setup.image, lab_t2, 4, 0x10, lab_t5);
        fn_1_4F734(&packet);
        i++;
    }

    packet = setup;
    packet.x = (fn_1_13D460_strip_position(arg0, i * fn_1_48690(setup.image)) + 0xC);
    lab_t5 = 4;
    lab_t2 = 0;
    fn_1_51678(&packet, setup.image, lab_t2, 4, ((total - 0xC) - packet.x), lab_t5);
    fn_1_4F734(&packet);

    packet = setup;
    packet.x = (arg0 + 0xC);
    packet.z = packet.z - lbl_1_rodata_87AC;
    lab_t5 = 4;
    lab_t2 = 0xC;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 4, lab_t5);
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8DBC;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);

    packet = setup;
    packet.x = (total - 0x34);
    packet.z = packet.z - lbl_1_rodata_87AC;
    lab_t5 = 4;
    lab_t2 = 0xC;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 4, lab_t5);
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8DBC;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);

    if (arg2 > 0x15E) {
        packet = setup;
        packet.x = (arg0 + 0x100);
        packet.z = packet.z - lbl_1_rodata_87AC;
        lab_t5 = 4;
        lab_t2 = 0xC;
        fn_1_51678(&packet, setup.image, lab_t2, 0, 4, lab_t5);
        fn_1_4F734(&packet);
        packet.x = packet.x + lbl_1_rodata_8A54;
        fn_1_4F734(&packet);
        packet.x = packet.x + lbl_1_rodata_8DBC;
        fn_1_4F734(&packet);
        packet.x = packet.x + lbl_1_rodata_8A54;
        fn_1_4F734(&packet);
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_13D460 */

/* fzgx:begin fn_1_13DA0C */
// Register the three groups of static display configurations.
void fn_1_13DA0C(void) {
    struct Struct_26F8 config;

    config = (*((const struct Struct_26F8 *)&lbl_1_rodata_26F8));
    config.unk00 = 0x9E1C;
    config.unk04 = lbl_1_rodata_8658;
    config.unk08 = lbl_1_rodata_8DCC;
    config.unk0C = lbl_1_rodata_8840;
    config.unk2C = lbl_1_rodata_87B4;
    config.unk38 = lbl_1_rodata_8DC0;
    config.unk30 = 0xF;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config.unk30 = 0x8000D;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config.unk30 = 0x100007;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config.unk30 = 0x180005;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config = (*((const struct Struct_26F8 *)&lbl_1_rodata_26F8));
    config.unk00 = 0x9E1D;
    config.unk04 = lbl_1_rodata_8818;
    config.unk08 = lbl_1_rodata_8DCC;
    config.unk0C = lbl_1_rodata_86F8;
    config.unk38 = lbl_1_rodata_8DC4;
    config.unk2C = lbl_1_rodata_87B4;
    config.unk30 = 0xD;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config.unk30 = 0x100005;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config = (*((const struct Struct_26F8 *)&lbl_1_rodata_26F8));
    config.unk00 = 0x9E1E;
    config.unk04 = lbl_1_rodata_8DD0;
    config.unk08 = lbl_1_rodata_8DCC;
    config.unk0C = lbl_1_rodata_86F8;
    config.unk38 = lbl_1_rodata_8DC8;
    config.unk2C = lbl_1_rodata_87B4;
    config.unk30 = 0xF;
    fn_1_4F734( (FontDrawPacket*)(&config));

    config.unk30 = 0x100007;
    fn_1_4F734( (FontDrawPacket*)(&config));
}
/* fzgx:end fn_1_13DA0C */

/* fzgx:begin fn_1_13DC54 */



void fn_1_13DC54(void) {
    FnData data;
    u32 value;

    data = *(FnData *)lbl_1_rodata_26F8;
    *(u32 *)((u8 *)&data + 0) = 0x9E0A;
    *(f32 *)((u8 *)&data + 4) = lbl_1_rodata_8DDC;
    *(f32 *)((u8 *)&data + 8) = lbl_1_rodata_8DE0;
    *(f32 *)((u8 *)&data + 12) = lbl_1_rodata_8B30;
    *(u32 *)((u8 *)&data + 48) = 10;
    fn_1_4F734( (FontDrawPacket*)(&data));

    data = *(FnData *)lbl_1_rodata_26F8;
    *(f32 *)((u8 *)&data + 4) = lbl_1_rodata_8DE4;
    *(f32 *)((u8 *)&data + 8) = lbl_1_rodata_8DE0;
    *(f32 *)((u8 *)&data + 12) = lbl_1_rodata_8B30;
    if (fn_1_B7E98(1) == 0) {
        value = *(u32 *)&lbl_1_rodata_8DD4;
        *(u32 *)((u8 *)&data + 56) = value;
    }

    *(u32 *)((u8 *)&data + 0) = 0x9E0C;
    *(u32 *)((u8 *)&data + 48) = 10;
    fn_1_4F734( (FontDrawPacket*)(&data));
    if (fn_1_B7E98(1) != 0) {
        f32 z;
        z = *(f32 *)((u8 *)&data + 12);
        *(u32 *)((u8 *)&data + 0) = 0x9E26;
        *(u32 *)((u8 *)&data + 56) = *(u32 *)&lbl_1_rodata_8DD8;
        *(f32 *)((u8 *)&data + 44) = lbl_1_rodata_8A58;
        *(f32 *)((u8 *)&data + 12) = z + lbl_1_rodata_8B34;
        fn_1_4F734( (FontDrawPacket*)(&data));
    }
}
/* fzgx:end fn_1_13DC54 */

/* fzgx:begin fn_1_13DDB8 */
typedef struct {
	u32 image;
	f32 x;
	f32 y;
	f32 z;
	u8 pad0[0x1C];
	f32 field_2C;
	u32 flags;
	u8 pad1[4];
	u32 unk_38;
	u8 color_add[3];
	u8 pad2[0x19];
} fn_1_13DDB8_Packet;



#pragma opt_propagation off
void fn_1_13DDB8(void) {
	f32 f;
	fn_1_13DDB8_Packet p;
	f32 s;
	f32 t;
	f32 f_2;
	f32 s_2;

	p = *(fn_1_13DDB8_Packet *)lbl_1_rodata_26F8;
	p.image = 0x10000 - 25055;
	p.x = lbl_1_rodata_8DF0;
	p.y = lbl_1_rodata_8684;
	p.z = lbl_1_rodata_86D0;
	p.field_2C = lbl_1_rodata_87B4;
	p.flags = 10;
	p.unk_38 = lbl_1_rodata_8DE8;
	f = lbl_8006D188((s32)(lbl_1_rodata_8B2C * (lbl_801A66A0 % 120) / lbl_1_rodata_8838));
	s = lbl_1_rodata_863C + f;
	t = lbl_1_rodata_880C * s;
	p.color_add[0] = p.color_add[1] = p.color_add[2] = ((((t) * lbl_1_rodata_85F0)));
	p.field_2C = lbl_1_rodata_87B4;
	fn_1_4F734((FontDrawPacket *)&p);

	if (fn_1_B7E98(1)) {
		p = *(fn_1_13DDB8_Packet *)lbl_1_rodata_26F8;
		p.image = 0x10000 - 25055;
		p.x = lbl_1_rodata_8DF4;
		p.y = lbl_1_rodata_8684;
		p.z = lbl_1_rodata_86D0;
		p.flags = 0x8000A;
		p.unk_38 = lbl_1_rodata_8DEC;
		f_2 = lbl_8006D188((s32)(lbl_1_rodata_8B2C * (lbl_801A66A0 % 120) / lbl_1_rodata_8838));
		s_2 = lbl_1_rodata_863C + f_2;
		t = lbl_1_rodata_86D0 * s_2;
		p.color_add[0] = p.color_add[1] = p.color_add[2] = ((((t) * lbl_1_rodata_85F0)));
		p.field_2C = lbl_1_rodata_87B4;
		fn_1_4F734((FontDrawPacket *)&p);
	}
}
#pragma opt_propagation reset
/* fzgx:end fn_1_13DDB8 */

/* fzgx:begin fn_1_13E054 */
void fn_1_13E054(void* arg0, void* arg1, void* arg2, int arg3) {
    u8* fixed = (u8*)0;
    fixed += 0xA204;
    fn_1_13E080( (s32)(void*)(arg0), (s32)(void*)(arg1), (u32)(void*)(fixed), 31);
}
/* fzgx:end fn_1_13E054 */

/* fzgx:begin fn_1_13E080 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

/* fn_1_128E8C's output: the course record (time, machine and its parts) */
typedef struct {
    u8 minutes;
    u8 seconds;
    u16 ms;
    u8 machine[4];  /* [0] machine id (41+ = custom, then three part ids) */
    u8 unk_8;       /* 0-100, the bar position */
    u8 unk_9;       /* cell of the 6x7 sheet at 0xA000 */
    u16 unk_A;
    u8 pad_C[0xC];
    u16 valid;
} RecordTime;

typedef struct {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    u32 color;
    u8 color_add[4];
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    void *vertex_callback;
    u32 unk_54;
} RecordPacket;

extern u32 lbl_801A66B4;
extern RecordPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_85E8;
extern const u32 lbl_1_rodata_8DF8;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8E00;
extern const f32 lbl_1_rodata_85F4;
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8E04;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8E08;
extern const f32 lbl_1_rodata_8E0C;
extern const u32 lbl_1_rodata_8DFC;
extern const f32 lbl_1_rodata_8E10;
extern const f32 lbl_1_rodata_8E14;
extern const f32 lbl_1_rodata_8E1C;
extern const f32 lbl_1_rodata_8E20;
extern const f32 lbl_1_rodata_8E18;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_8E24;
extern const f32 lbl_1_rodata_8E28;
extern const f32 lbl_1_rodata_8E2C;
extern const f32 lbl_1_rodata_8E30;
extern const f32 lbl_1_rodata_8E34;

extern void fn_1_12EF80(s16, s16 *, s16 *);
extern void fn_1_128E8C(u8, RecordTime *);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_1_50164(f32, f32, f32, f32, RecordPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_52250(void *, void *);
extern void fn_1_49738(void (*)(void *, void *));
extern void fn_1_49748(f32);
extern void fn_1_495C8(s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
/* retail evaluates the scales before the language argument, so they precede it (same registers);
 * sel_static_disp.c's definitions list them later. Both callees still match with this order. */
/* Parameter order from the call sites: retail evaluates the two scale floats before the
 * language argument, so they precede it (the GPR and FPR argument numbering is unchanged;
 * the definitions still match in this order). */
extern void fn_1_135D7C(s16, s16, s16, s16, f32, f32, s16, s16, s16, f32);
extern void fn_1_1358BC(s16, s16, s32, s16, f32, f32, s16, u8, u8, u8, f32);

/* the course record panel at (x, y): with no record (or the default 8'44"287), a box the size of `image`
 * with a centred message; otherwise `image`, the time, the bar, the machine (with its parts when custom)
 * and the cell from unk_9 */
#pragma opt_common_subs off
void fn_1_13E080(s32 x, s32 y, u32 image, s32 height) {
    RecordPacket packet;
    RecordTime rec;
    s16 a;
    s16 b;
    s32 row;
    s32 col;
    u8 machine;
    s32 bottom;
    f32 offset;

    fn_1_12EF80(lbl_1_bss_8B3A0.unk_90, &a, &b);
    fn_1_128E8C((a - 6) * 6 + b, &rec);
    if (rec.valid == 0 || (rec.minutes == 8 && rec.seconds == 44 && rec.ms == 287)) {
        packet = lbl_1_rodata_26F8;
        packet.image = 12;
        packet.x = x;
        bottom = y + height;
        packet.y = bottom;
        packet.z = lbl_1_rodata_85E8;
        packet.color = lbl_1_rodata_8DF8;
        fn_1_50164(fn_1_48690(image), fn_1_486C4(image), lbl_1_rodata_86C4, lbl_1_rodata_86C4, &packet);
        fn_1_49410();
        fn_1_494DC(5);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_52250);
        fn_1_49748(lbl_1_rodata_8B34);
        fn_1_495C8(9);
        fn_1_496FC(x + fn_1_48690(image) / 2, bottom + fn_1_486C4(image) / 2);
        fn_1_4AE0C((const char *)&lbl_1_data_41E1C);
        return;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = image;
    packet.x = x;
    packet.y = y + height;
    packet.z = lbl_1_rodata_85E8;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9E05;
    packet.flags = 5;
    packet.x = x + 169;
    packet.y = y + 37;
    packet.z = lbl_1_rodata_8E00;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9E04;
    packet.flags = 6;
    offset = lbl_1_rodata_85FC * (rec.unk_8 / lbl_1_rodata_85F4);
    packet.x = (x + 173) + offset;
    packet.y = y + 36;
    packet.z = lbl_1_rodata_8E04;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9E28;
    packet.flags = 5;
    packet.u0 = lbl_1_rodata_861C;
    packet.u1 = lbl_1_rodata_863C;
    packet.v0 = lbl_1_rodata_85F0;
    packet.v1 = lbl_1_rodata_8E08;
    packet.x = x + 62;
    packet.y = y + 59;
    packet.scale_x = lbl_1_rodata_863C;
    packet.scale_y = lbl_1_rodata_8E0C;
    packet.z = lbl_1_rodata_8E04;
    packet.color = lbl_1_rodata_8DFC;
    fn_1_4F734((FontDrawPacket *)&packet);

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_495C8(0);
    fn_1_494DC(0x24);
    fn_1_4954C(lbl_1_rodata_8E04);
    fn_1_4955C(lbl_1_rodata_8E10, lbl_1_rodata_8E10);
    fn_1_496FC(x + 74, y + 70);
    fn_1_4AE0C((const char *)lbl_1_data_41E24, rec.minutes, rec.seconds, rec.ms);

    machine = rec.machine[0];
    if (machine < 41) {
        packet = lbl_1_rodata_26F8;
        row = machine / 6;
        col = machine % 6;
        packet.image = 0x9E2D;
        packet.flags = 10;
        packet.u0 = lbl_1_rodata_8E14 * col;
        packet.u1 = lbl_1_rodata_8E14 * (col + 1);
        packet.v0 = lbl_1_rodata_8E18 * row;
        packet.v1 = lbl_1_rodata_8E18 * (row + 1);
        packet.x = x + 29;
        packet.y = y + 60;
        packet.scale_x = lbl_1_rodata_8E1C;
        packet.scale_y = lbl_1_rodata_8E20;
        packet.z = lbl_1_rodata_8E04;
        fn_1_4F734((FontDrawPacket *)&packet);
        fn_1_135D7C(x + 132, y + 45, 10, rec.machine[0], lbl_1_rodata_8664, lbl_1_rodata_8664,
                    lbl_801A66B4, 0, 0, lbl_1_rodata_87DC);
    } else {
        packet = lbl_1_rodata_26F8;
        packet.image = 0x9E2D;
        packet.flags = 10;
        packet.u0 = lbl_1_rodata_8E24;
        packet.u1 = lbl_1_rodata_863C;
        packet.v0 = lbl_1_rodata_8E28;
        packet.v1 = lbl_1_rodata_863C;
        packet.x = x + 29;
        packet.y = y + 60;
        packet.scale_x = lbl_1_rodata_8E1C;
        packet.scale_y = lbl_1_rodata_8E20;
        packet.z = lbl_1_rodata_8E04;
        fn_1_4F734((FontDrawPacket *)&packet);
        fn_1_1358BC(x + 132, y + 46, 10, rec.machine[0], lbl_1_rodata_8E2C, lbl_1_rodata_8E2C,
                    lbl_801A66B4, rec.machine[1], rec.machine[2], rec.machine[3], lbl_1_rodata_87DC);
    }

    packet = lbl_1_rodata_26F8;
    row = rec.unk_9 / 6;
    col = rec.unk_9 % 6;
    packet.image = 0xA000;
    packet.flags = 10;
    packet.u0 = lbl_1_rodata_8E14 * col;
    packet.u1 = lbl_1_rodata_8E14 * (col + 1);
    packet.v0 = lbl_1_rodata_8E18 * row;
    packet.v1 = lbl_1_rodata_8E18 * (row + 1);
    packet.x = x + 226;
    packet.y = y + 60;
    packet.scale_x = lbl_1_rodata_8E30;
    packet.scale_y = lbl_1_rodata_8E34;
    packet.z = lbl_1_rodata_8E04;
    fn_1_4F734((FontDrawPacket *)&packet);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_13E080 */

/* fzgx:begin fn_1_13EA9C */
typedef struct { FontDrawPacket p; } fn_1_13EA9C_Pkt;



#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_13EA9C(void) {
    fn_1_13EA9C_Str17 name = lbl_1_rodata_8E38;
    fn_1_13EA9C_Str29 text = lbl_1_rodata_8E4C;
    FontDrawPacket packet;
    int n;
    char *namep = name.s;
    char *textp = text.s;

    n = fn_1_8623C();

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 12;
    packet.flags = 5;
    packet.x = lbl_1_rodata_8E6C;
    packet.y = lbl_1_rodata_8648;
    packet.z = lbl_1_rodata_8E04;
    fn_1_50164(lbl_1_rodata_8670, lbl_1_rodata_87D0, lbl_1_rodata_86C4, lbl_1_rodata_86C4, &packet);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9E14;
    fn_1_51564(0, 0, 24, 20, 2, 2);
    fn_1_5158C(&packet, packet.image, n % 2, n / 2);
    packet.x = lbl_1_rodata_8E70;
    packet.y = lbl_1_rodata_8E74;
    packet.z = lbl_1_rodata_8E78;
    packet.scale_x *= lbl_1_rodata_85EC;
    packet.scale_y *= lbl_1_rodata_85EC;
    packet.flags = 9;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8820, lbl_1_rodata_8E74);
    fn_1_495C8(8);
    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
    fn_1_4965C(2);
    fn_1_495B0(0x40000000);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_4CE48(namep, lbl_1_rodata_8E7C);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.x = lbl_1_rodata_8E80;
    packet.y = lbl_1_rodata_8E74;
    packet.z = lbl_1_rodata_8E78;
    packet.flags = 10;
    packet.image = 0x9500;
    fn_1_53FE4(&packet, 0);

    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8E84, lbl_1_rodata_8E74);
    fn_1_495C8(8);
    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
    fn_1_4965C(2);
    fn_1_495B0(0x40000000);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_4CE48(textp, lbl_1_rodata_8E88);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_13EA9C */

/* fzgx:begin fn_1_13EDDC noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

// Build the selected display data unless the caller requested the cached path.
void fn_1_13EDDC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4) {
    u32 display_data[47];
    u32 nan_value;

    if (arg4 != 1) {
        fn_1_13EE60(arg2, arg3, display_data, arg3, arg4);
        nan_value = lbl_1_rodata_8E8C;
        fn_1_13EF64(arg0, arg1, 2, display_data, 0x9e20, &nan_value, 0, lbl_1_rodata_85F0);
    }
}
/* fzgx:end fn_1_13EDDC */

/* fzgx:begin fn_1_13EE60 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, Obj_1_bss_6EA04_Target *, u8 *, u32);
extern f32 lbl_1_rodata_4104[59];
extern Obj_1_data_27DE0 *fn_1_986A4(Obj_1_data_27DE0 *obj);
extern void fn_800794F0(Obj_1_data_27DE0 *arg0, Obj_1_data_27DE0 *arg1, s32 arg2);
extern void fn_1_98804(Obj_1_data_27DE0 *obj);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 strlen(const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern s32 fn_1_3F0C8(void);
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_7B074(void);
extern void fn_8006FDEC(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void *fn_1_12F118(void);
extern void *fn_1_36AD0(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern void fn_80008BA8(void *arg0, const void *arg1, int arg2);

extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void fn_1_9D360(void);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern const f32 lbl_1_rodata_4100;
extern void *memset(void *dest, int value, u32 size);
extern u32 fn_1_584AC(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_862D4(u32 arg0, void *arg1);
extern u32 fn_1_1FB80(void *arg0, s32 arg1);
extern u32 fn_1_41488(u32 arg0, void *arg1);
extern void fn_1_4270C(void *arg0, u32 arg1, u32 arg2);
extern f32 lbl_1_rodata_4260[16];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_9194[10];
extern u8 lbl_1_rodata_85AC[60];
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8A4C;
extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_91BC;
extern void fn_1_4E724(void *);

typedef struct {
    u32 flags;
    u8 pad_4[0x819c];
    u8 unk_81a0;
    u8 pad_81a1[3];
    u8 unk_81a4;
    u8 pad_81a5[7];
    u8 unk_81ac;
    u8 pad_81ad[7];
    u8 unk_81b4;
    u8 pad_81b5[0xb];
} fn_1_13EE60_BurnerEntry;

void fn_1_13EE60(s16 arg0, s16 arg1, void *arg2) {
    void *base;
    fn_1_13EE60_BurnerEntry *entry;

    if (arg0 >= 0x29) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            entry = &((fn_1_13EE60_BurnerEntry *)base)[arg1];
        } else {
            entry = &((fn_1_13EE60_BurnerEntry *)base)[arg0 - 0x29];
        }
        if ((entry->flags & 0x40000000) != 0) {
            fn_1_14F6F8(entry->unk_81a4, entry->unk_81ac,
                        entry->unk_81b4, arg2);
        } else {
            fn_80008BA8(arg2,
                        &lbl_1_data_28060.entries[entry->unk_81a0],
                        sizeof(MachineParameterRecord));
        }
    } else {
        fn_80008BA8(arg2, &lbl_1_data_28060.entries[arg0],
                    sizeof(MachineParameterRecord));
    }
}
/* fzgx:end fn_1_13EE60 */

/* fzgx:begin fn_1_13EF64 noprologue */
#include "types.h"
#include "font.h"

typedef struct {
    u8 r, g, b, a;
} StatColor;

typedef struct {
    f32 x, y, z;
} StatVec;

/* machine parameter record (0xB4 bytes, see burner.h MachineParameterRecord) */
typedef struct {
    const char *name;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x10];
    f32 unk_20;
    u8 pad_24[0x20];
    f32 unk_44;
    u8 pad_48[0xC];
    StatVec unk_54;
    u8 pad_60[0xC];
    StatVec unk_6C;
} StatRecord;

typedef struct {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    StatColor color;
    u8 color_add[4];
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    void *vertex_callback;
    u32 unk_54;
} StatPacket;

extern StatPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_8808;
extern const f32 lbl_1_rodata_8D7C;
extern const f32 lbl_1_rodata_8A30;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8BF4;
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_87E8;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8E90;
extern const f32 lbl_1_rodata_8A28;
extern const f32 lbl_1_rodata_8E9C;
extern const f32 lbl_1_rodata_8E94;
extern const f32 lbl_1_rodata_8EA0;
extern const f32 lbl_1_rodata_8E98;
extern const f32 lbl_1_rodata_8EA4;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_8EA8;
extern const f32 lbl_1_rodata_8EAC;
extern const f32 lbl_1_rodata_87B4;
extern const f32 lbl_1_rodata_8EB0;
extern const f32 lbl_1_rodata_8B6C;

extern f32 lbl_8006D0B4(f32);  /* square root */

static inline f32 stat_clamp(f32 x, f32 lo, f32 hi) {
    f32 r;
    if (x < lo) {
        r = lo;
    } else if (x > hi) {
        r = hi;
    } else {
        r = x;
    }
    return r;
}

#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_1_13EF64(s16 x, s16 y, s16 z, StatRecord *rec, s32 image, StatColor *colorp, void *callback, f32 alpha) {
    StatColor color;
    StatPacket packet;
    f32 dx;
    f32 dz;
    f32 t;
    f32 a;
    f32 b;
    f32 d;
    f32 len;    /* sqrt term, then the right-hand level */
    f32 g;
    f32 weight;
    f32 top;
    f32 left;
    f32 h;      /* level from unk_44, then the right-hand scale */
    f32 w;      /* weight term, then the bottom level and scale */

    color = *colorp;

    t = stat_clamp(rec->unk_44, lbl_1_rodata_8808, lbl_1_rodata_8D7C);
    t = (t - lbl_1_rodata_8808) / lbl_1_rodata_8A30;
    t = stat_clamp(t, lbl_1_rodata_861C, lbl_1_rodata_863C);
    t = lbl_1_rodata_863C + lbl_1_rodata_8B34 * (lbl_1_rodata_863C - t);
    h = stat_clamp(t, lbl_1_rodata_861C, lbl_1_rodata_8B34);

    d = lbl_1_rodata_8BF4 - rec->unk_8;
    b = rec->unk_C - lbl_1_rodata_87AC;
    a = d;
    if (d < lbl_1_rodata_861C) {
        a = d * lbl_1_rodata_87E8;
        b *= lbl_1_rodata_85EC;
    }
    a += lbl_1_rodata_863C;
    b += lbl_1_rodata_863C;
    a = b * a - lbl_1_rodata_863C;
    t = lbl_1_rodata_85F0 + lbl_1_rodata_8E90 * a;
    t = stat_clamp(t, lbl_1_rodata_87AC, lbl_1_rodata_863C);
    left = t;
    if (t < lbl_1_rodata_85F0) {
        left = t * lbl_1_rodata_8A28;
    }

    left *= lbl_1_rodata_8B34;
    dx = lbl_1_rodata_85F0 * (rec->unk_54.x + rec->unk_6C.x);
    dz = lbl_1_rodata_85F0 * (rec->unk_6C.z - rec->unk_54.z);
    w = (rec->unk_4 - lbl_1_rodata_8E94) / lbl_1_rodata_8E98;
    g = lbl_1_rodata_863C + (rec->unk_20 - lbl_1_rodata_8E9C) / lbl_1_rodata_8EA0;
    len = lbl_8006D0B4(dx * dx + dz * dz);
    weight = rec->unk_4;
    t = g - w;
    t -= weight * len / lbl_1_rodata_8EA4;
    t = lbl_1_rodata_8A4C * t;
    w = stat_clamp(t, lbl_1_rodata_861C, lbl_1_rodata_863C);
    w *= lbl_1_rodata_8B34;

    t = (weight - lbl_1_rodata_86F8) / lbl_1_rodata_8EA8;
    t = stat_clamp(t, lbl_1_rodata_861C, lbl_1_rodata_85EC);
    t = rec->unk_8 * (lbl_1_rodata_8EAC - t);
    t = stat_clamp(t, lbl_1_rodata_87B4, lbl_1_rodata_8A28);
    t = (t - lbl_1_rodata_87B4) / lbl_1_rodata_8EB0;
    t = stat_clamp(t, lbl_1_rodata_861C, lbl_1_rodata_863C);
    t = lbl_1_rodata_863C + lbl_1_rodata_8B34 * t;
    len = stat_clamp(t, lbl_1_rodata_861C, lbl_1_rodata_8B34);

    if (image == 18) {
        h *= lbl_1_rodata_8B6C;
        left *= lbl_1_rodata_8B6C;
        len *= lbl_1_rodata_8B6C;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = image;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.flags = 0x8000D;
    packet.scale_x = left /= lbl_1_rodata_8B34;
    packet.scale_y = top = h / lbl_1_rodata_8B34;
    packet.color = color;
    packet.alpha = alpha;
    if (callback != NULL) {
        packet.vertex_callback = callback;
        packet.flags |= 0x4000000;
    }
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = image;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.flags = 15;
    packet.scale_x = h = len / lbl_1_rodata_8B34;
    packet.scale_y = top;
    packet.color = color;
    packet.alpha = alpha;
    if (callback != NULL) {
        packet.vertex_callback = callback;
        packet.flags |= 0x4000000;
    }
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = image;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.flags = 0x180005;
    packet.scale_x = left;
    packet.scale_y = w /= lbl_1_rodata_8B34;
    packet.color = color;
    packet.alpha = alpha;
    if (callback != NULL) {
        packet.vertex_callback = callback;
        packet.flags |= 0x4000000;
    }
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = image;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.flags = 0x100007;
    packet.scale_x = h;
    packet.scale_y = w;
    packet.color = color;
    packet.alpha = alpha;
    if (callback != NULL) {
        packet.vertex_callback = callback;
        packet.flags |= 0x4000000;
    }
    fn_1_4F734((FontDrawPacket *)&packet);
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_13EF64 */

/* fzgx:begin fn_1_13F72C noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

typedef struct {
    s16 first;
    u16 pad;
    u32 vals[6];
} fn_1_13F72C_Entry;

typedef struct {
    fn_1_13F72C_Entry e[5];
} EntryTable;


u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0) {
    EntryTable tbl;
    fn_1_13F72C_Entry* p;
    s16 i;

    tbl = *(const EntryTable*)lbl_1_rodata_8EB4;
    p = tbl.e;
    i = 0;
    while (1) {
        if (farg0 >= p->first) {
            strcpy( (char *)(arg1), (const char *)(tbl.e[i].vals[arg0]));
            return arg1;
        }
        p++;
        i++;
    }
}
/* fzgx:end fn_1_13F72C */

/* fzgx:begin fn_1_13F7F8 noprologue */
#include "rel/main_rel/custom_memcard.h"

extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);

u32 fn_1_13F7F8(s16 arg0, s16 arg1) {
    return ((u32 (*)[6])&lbl_1_data_414D8)[arg0][arg1];
}
/* fzgx:end fn_1_13F7F8 */

/* fzgx:begin fn_1_13F81C noprologue */
// Clear the cached display-resource handles before loading a new selection.
void fn_1_13F81C(void) {
    u32 *handles = (u32 *)(&lbl_1_bss_8E3E4);

    handles[0] = 0;
    handles[1] = 0;
    handles[2] = 0;
    handles[3] = 0;
    handles[4] = 0;
    handles[5] = 0;
    handles[6] = 0;
    handles[7] = 0;
}
/* fzgx:end fn_1_13F81C */

/* fzgx:begin fn_1_13F848 noprologue */
// Load the selected display resource, store its handle, and activate it.
void fn_1_13F848(u32 arg0) {
    u32 selected_slot = arg0 & 0xFF;
    u32* handles = (u32*)lbl_1_bss_8E3E4;

    handles[selected_slot] =
        fn_1_45D0(lbl_801A6410, 0x10440, lbl_1_data_419E0, 0x14F9);
    fn_1_FC414( (void *)(handles[selected_slot]), (void *)(1));
}
/* fzgx:end fn_1_13F848 */

/* fzgx:begin fn_1_13F8B0 noprologue */
// Resolve a cached display handle from the key's low-byte slot.
u32 fn_1_13F8B0(u32 key) {
    u32 slot = key & 0xFF;

    return ((u32 *)lbl_1_bss_8E3E4)[slot];
}
/* fzgx:end fn_1_13F8B0 */

/* fzgx:begin fn_1_13F8C4 noprologue */
void fn_1_13F8C4(s32 arg_sp0) {
    s32 temp_r27;
    u8 var_r26;
    void *temp_r4;

    var_r26 = 0;
    while (var_r26 < 8U) {
        temp_r27 = (var_r26 * 4) & 0x3FC;
        temp_r4 = (*(void **)((&(((u8 *)&lbl_1_bss_8E3E4))[temp_r27])));
        if (temp_r4 != NULL) {
            fn_1_46B4((*((struct fn_1_13F8C4_lbl_801A6410 *)&lbl_801A6410)).unk_0, (u32)(temp_r4), (const char *)(&lbl_1_data_419E0), 0x150B);
        }
        (*(s32 *)((&(((u8 *)&lbl_1_bss_8E3E4))[temp_r27]))) = 0;
        var_r26 += 1;
            }
}
/* fzgx:end fn_1_13F8C4 */

/* fzgx:begin fn_1_13F948 noprologue */
// Clear the cached static-display handles before rebuilding the resource set.
void fn_1_13F948(void) {
    ((u32 *)lbl_1_bss_8E404)[0] = 0;
    ((u32 *)lbl_1_bss_8E404)[1] = 0;
    ((u32 *)lbl_1_bss_8E404)[2] = 0;
    ((u32 *)lbl_1_bss_8E404)[3] = 0;
    ((u32 *)lbl_1_bss_8E404)[4] = 0;
    ((u32 *)lbl_1_bss_8E404)[5] = 0;
    ((u32 *)lbl_1_bss_8E404)[6] = 0;
    ((u32 *)lbl_1_bss_8E404)[7] = 0;
}
/* fzgx:end fn_1_13F948 */

/* fzgx:begin fn_1_13F974 noprologue */
// Allocate and initialize the static-display resource for a byte-sized slot.
u32 fn_1_13F974(u32 slot_arg) {
    u32 slot = slot_arg & 0xFF;
    u32* resource_slots = (u32*)lbl_1_bss_8E404;

    resource_slots[slot] =
        fn_1_45D0(lbl_801A6410, 0x440, lbl_1_data_419E0, 0x1528);
    return fn_80008BEC(resource_slots[slot], 0, 0x440);
}
/* fzgx:end fn_1_13F974 */

/* fzgx:begin fn_1_13F9DC noprologue */
// Look up the static-display object stored in the caller-selected byte slot.
u32 fn_1_13F9DC(u32 slot) {
    return ((u32*)lbl_1_bss_8E404)[slot & 0xFF];
}
/* fzgx:end fn_1_13F9DC */

/* fzgx:begin fn_1_13F9F0 noprologue */
typedef struct {
    char pad[0x3A4];
    u32 unk_3A4;
} FnObject;

// Releases each active static-display object before clearing its slot.
void fn_1_13F9F0(void) {
    u8 slot;

    for (slot = 0; slot < 8; slot++) {
        if (((u32 *)lbl_1_bss_8E404)[slot] != 0) {
            if (((FnObject *)((u32 *)lbl_1_bss_8E404)[slot])->unk_3A4 != 0) {
                fn_1_7F3AC((void *)((u32 *)lbl_1_bss_8E404)[slot]);
            }
            fn_1_46B4(lbl_801A6410, (((u32 *)lbl_1_bss_8E404)[slot]), (const char *)(lbl_1_data_419E0), 0x153E);
        }
        ((u32 *)lbl_1_bss_8E404)[slot] = 0;
    }
}
/* fzgx:end fn_1_13F9F0 */

/* fzgx:begin fn_1_13FA88 noprologue */
u32 fn_1_13FA88(s16 arg0) {
    switch (arg0) {
    case 4:
        return 1;
    case 6:
        if (lbl_1_bss_8B3A0.unk_4 == 3) {
            break;
        }
        return 1;
    case 3:
        if (lbl_1_bss_8B3A0.unk_4 == 4) {
            return 1;
        }
        break;
    case 7:
        if (lbl_1_bss_8B3A0.unk_4 == 2) {
            break;
        }
        return 1;
    case 5:
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_13FA88 */

/* fzgx:begin fn_1_13FB24 */
int fn_1_13FB24(u32 arg0) {
    switch ((s16)arg0) {
    case 6:
        return 1;
    case 3:
        return 1;
    case 7:
        return 1;
    case 1:
        return 1;
    case 5:
        if (lbl_1_bss_8B3A0.unk_12C != 0) {
            break;
        }
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_13FB24 */

/* fzgx:begin fn_1_13FB8C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_13FB8C_Copy88 { u32 a[22]; };
struct fn_1_13FB8C_Copy96 { u32 a[24]; };
struct fn_1_13FB8C_Copy216 { u32 a[54]; };

extern u32 lbl_1_rodata_8F40;
extern u8 lbl_1_rodata_9018[216];
extern u8 lbl_1_rodata_90F0[96];
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_801A66A8;
extern s32 lbl_801A66B4;
extern u32 lbl_1_rodata_9150;
extern u32 lbl_1_rodata_9154;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_9158;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_85F8;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_9164;
extern const f32 lbl_1_rodata_915C;
extern const f32 lbl_1_rodata_8818;
extern const f32 lbl_1_rodata_8B6C;
extern const f32 lbl_1_rodata_9160;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_9168;
extern const f32 lbl_1_rodata_916C;
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4954C(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u32);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4DCB8(u32);
extern void fn_1_4953C(u16);
extern f32 lbl_8006D188(u32);
#pragma opt_common_subs off
#pragma opt_loop_invariants off

static inline s16 fn_1_13FB8C_hidden(s16 row, Obj_1_bss_8B3A0 *state) {
    switch (row) {
    case 6: return 1;
    case 3: return 1;
    case 7: return 1;
    case 1: return 1;
    case 5: if (state->unk_12C == 0) return 1;
    default: return 0;
    }
}
static inline s16 fn_1_13FB8C_hidden0(s16 row, Obj_1_bss_8B3A0 *state) {
    switch (row) {
    case 4: return 1;
    case 6: if (state->unk_4 != 3) return 1; break;
    case 3: if (state->unk_4 == 4) return 1; break;
    case 7: if (state->unk_4 != 2) return 1; break;
    case 5: return 1;
    }
    return 0;
}
static inline f32 fn_1_13FB8C_max(f32 a) {
    f32 b = lbl_1_rodata_861C;
    if (a > b) return a;
    return b;
}
static inline void fn_1_13FB8C_fade_in(f32 delta, f32 half, f32 *alpha) {
    if (fn_1_13FB8C_max(delta) / half < lbl_1_rodata_861C) {
        *alpha = lbl_1_rodata_861C;
    } else if (fn_1_13FB8C_max(delta) / half > lbl_1_rodata_863C) {
        *alpha = lbl_1_rodata_863C;
    } else {
        *alpha = (delta > lbl_1_rodata_861C ? delta : lbl_1_rodata_861C) / half;
    }
}
static inline f32 fn_1_13FB8C_clamp(f32 t) {
    if (t < lbl_1_rodata_861C) return lbl_1_rodata_861C;
    if (t > lbl_1_rodata_863C) return lbl_1_rodata_863C;
    return t;
}
#define PANEL_MAX(a,b) fn_1_13FB8C_max((a))
#define PANEL_CLAMP(v,lo,hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))
#define PACKET_F(n) (((f32 *)&packet)[(n)])
#define PACKET_B(n) (((u8 *)&packet)[(n)])
#define PRINT_VALUE(n) fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0xe8c, ((char **)values.a)[(n) * 6 + lbl_801A66B4])

u8 lbl_1_data_42118[28] = {
    0x83U, 0x7DU, 0x83U, 0x58U, 0x83U, 0x5EU, 0x81U, 0x5BU, 0x00U, 0x00U, 0x00U, 0x00U, 0x25U, 0x73U, 0x20U, 0x00U, 0x81U, 0xA3U, 0x00U, 0x00U, 0x25U, 0x30U, 0x32U, 0x64U, 0x00U, 0x00U, 0x00U, 0x00U
};

void fn_1_13FB8C(u32 arg0, u32 arg1, s16 arg2, s16 arg3, s32 arg4, f32 arg5) {
    u8 *p_lbl_1_data_40F58;
    struct fn_1_13FB8C_Copy216 values;
    struct fn_1_13FB8C_Copy216 labels;
    struct fn_1_13FB8C_Copy96 choices;
    char *(*labelRow)[6];
    s32 valueX;
    s16 row;
    s16 originX;
    s16 originY;
    f32 selectedAlpha;
    f32 arrowLeft;
    f32 arrowRight;
    f32 arrowOffset;
    f32 scale;
    f32 alpha;
    f32 half;
    f32 delta;
    u32 oldFont;
    Obj_1_bss_8B3A0 *state;
    p_lbl_1_data_40F58 = (u8 *)&lbl_1_data_40F58;
    values = *(struct fn_1_13FB8C_Copy216 *)&lbl_1_rodata_8F40;
    labels = *(struct fn_1_13FB8C_Copy216 *)lbl_1_rodata_9018;
    choices = *(struct fn_1_13FB8C_Copy96 *)lbl_1_rodata_90F0;
    alpha = lbl_1_rodata_863C;
    scale = lbl_1_rodata_8A4C;
    originX = arg0 + 21 - arg2 / 2;
    originY = arg1 + 21 - arg3 / 2;
    if (lbl_801A66B4 != 5) scale = lbl_1_rodata_9158;
    {
    u32 flags;
    Obj_1_bss_8B3A0 *fadeState;
    fadeState = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    flags = fadeState->unk_140;
    if ((flags & 0x80000000) && (flags & 0x20)) {
        half = fadeState->unk_148 / 2.0f;
        if (flags & 2) {
            fn_1_13FB8C_fade_in(fadeState->unk_146 - half, half, &alpha);
        } else if (flags & 1) {
            f32 t = fadeState->unk_146 / half;
            t = fn_1_13FB8C_clamp(t);
            alpha = lbl_1_rodata_863C - t;
        }
    } else if (lbl_1_bss_8B3A0.unk_0 == -1) {
        return;
    }
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(scale, scale);
    fn_1_495A0(alpha);
    fn_1_4954C(arg5);
    labelRow = (char *(*)[6])labels.a;
    state = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    arrowOffset = lbl_1_rodata_85F8 * scale;
    selectedAlpha = lbl_1_rodata_85F0 * alpha;
    arrowLeft = (originX + 158) + arrowOffset;
    arrowRight = (originX + 301) + arrowOffset;
    valueX = originX + 238;
    for (row = 0; row < 9; labelRow++, row++) {
        u32 color = lbl_1_rodata_9150;
        fn_1_49514(&color);
        if (row == state->unk_92) {
            struct fn_1_13FB8C_Copy88 packet;
            packet = *(struct fn_1_13FB8C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 18;
            PACKET_F(1) = (s16)arg0;
            PACKET_F(2) = (originY - 2);
            PACKET_F(3) = lbl_1_rodata_915C;
            packet.a[12] = 6;
            PACKET_F(4) = PACKET_F(4) * lbl_1_rodata_8818;
            PACKET_F(5) = PACKET_F(5) * lbl_1_rodata_8B6C;
            PACKET_B(0x38) = (lbl_1_rodata_9160 + (lbl_1_rodata_88A8 * lbl_8006D188((s32)(lbl_1_rodata_9164 + (lbl_1_rodata_8B2C * (lbl_801A66A8 % 60)) / lbl_1_rodata_8B30))));
            PACKET_B(0x39) = (lbl_1_rodata_9168 + (lbl_1_rodata_916C * lbl_8006D188((s32)(lbl_1_rodata_9164 + (lbl_1_rodata_8B2C * (lbl_801A66A8 % 60)) / lbl_1_rodata_8B30))));
            PACKET_B(0x3a) = (lbl_1_rodata_9168 + (lbl_1_rodata_916C * lbl_8006D188((s32)(lbl_1_rodata_9164 + (lbl_1_rodata_8B2C * (lbl_801A66A8 % 60)) / lbl_1_rodata_8B30))));
            PACKET_F(11) = selectedAlpha;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        if (arg4 == 1 && fn_1_13FB8C_hidden(row, state) && row != 5) continue;
        if (arg4 == 0 && fn_1_13FB8C_hidden0(row, state)) continue;
        if (row == 8) {
            fn_1_496FC((s16)arg0, originY);
            fn_1_495C8(1);
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11cc, (*labelRow)[lbl_801A66B4]);
        } else {
            if (arg4 == 1 && fn_1_13FB8C_hidden(row, state) && row == 5) {
                u32 disabledColor = lbl_1_rodata_9154;
                fn_1_49514(&disabledColor);
            }
            fn_1_496FC(originX, originY);
            fn_1_495C8(0);
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11cc, (*labelRow)[lbl_801A66B4]);
            {
                alpha = originY + arrowOffset;
                fn_1_496FC(arrowLeft, alpha);
                oldFont = fn_1_4DCB8(10);
                fn_1_4953C(0x4444);
                fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d0);
                fn_1_4DCB8(oldFont);
                fn_1_496FC(arrowRight, alpha);
                oldFont = fn_1_4DCB8(10);
                fn_1_4953C(0xbbbb);
                fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d0);
                fn_1_4DCB8(oldFont);
                fn_1_4953C(0);
            }
        }
        fn_1_496FC(valueX, originY);
        fn_1_495C8(1);
        switch (row) {
        case 4:
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d4, state->unk_12C);
            break;
        case 6:
            if (state->unk_12E == 0) PRINT_VALUE(0);
            else PRINT_VALUE(1);
            break;
        case 3:
            if (state->unk_130 == 0) PRINT_VALUE(5);
            else PRINT_VALUE(4);
            break;
        case 1:
            if (state->unk_132 == 0) PRINT_VALUE(3);
            else PRINT_VALUE(2);
            break;
        case 7:
            if (state->unk_134 == 0) PRINT_VALUE(7);
            else PRINT_VALUE(6);
            break;
        case 2:
            if (arg4 == 1) {
                if (state->unk_136 == 0) PRINT_VALUE(3);
                else PRINT_VALUE(2);
            } else {
                if (state->unk_138 == 0) PRINT_VALUE(3);
                else PRINT_VALUE(2);
            }
            break;
        case 0:
            if (arg4 == 1) {
                s16 count = state->unk_13A;
                if (count == 0) PRINT_VALUE(8);
                else fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d4, count);
            } else fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d4, state->unk_13C);
            break;
        case 5:
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0xe8c, ((char *(*)[6])choices.a)[state->unk_8][lbl_801A66B4]);
            break;
        }
        originY += 23;
    }
}

u32 lbl_1_data_42194 = 0x819A0000U;
/* fzgx:end fn_1_13FB8C */

/* fzgx:begin fn_1_14083C noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

extern const f32 lbl_1_rodata_861C, lbl_1_rodata_8638, lbl_1_rodata_863C, lbl_1_rodata_8818;
extern const f32 lbl_1_rodata_9178, lbl_1_rodata_917C, lbl_1_rodata_9180, lbl_1_rodata_9188, lbl_1_rodata_918C, lbl_1_rodata_9190;
extern const f32 lbl_1_rodata_85F0, lbl_1_rodata_8A30, lbl_1_rodata_9174, lbl_1_rodata_9184;
extern const f64 lbl_1_rodata_8600;
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_9170;
extern void fn_1_50164(FontDrawPacket *, f32, f32, f32, f32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#define CLAMP(x) (f32)((x) < lbl_1_rodata_861C ? lbl_1_rodata_861C : (x) > lbl_1_rodata_863C ? lbl_1_rodata_863C : (x))
#define MAXF(a, b) ((a) > (b) ? (a) : (b))
static inline f32 max_f(f32 a, f32 b) { return a > b ? a : b; }
static inline void inv_clamp(f32 *out, f32 x, f32 d) {
    f32 t = max_f(x, lbl_1_rodata_861C) / d;
    *out = lbl_1_rodata_863C - (t < lbl_1_rodata_861C ? lbl_1_rodata_861C
        : MAXF(x, lbl_1_rodata_861C) / d > lbl_1_rodata_863C ? lbl_1_rodata_863C
        : MAXF(x, lbl_1_rodata_861C) / d);
}
static inline f32 half_f(f32 h) { return h * lbl_1_rodata_85F0; }
static inline f32 clamp_f(f32 x) { return CLAMP(x); }
static inline void position_f(FontDrawPacket *p, f32 x, f32 y, f32 z) { p->x = x; p->y = y; p->z = z; }
#define position(p,x,y,z) position_f((p),(s16)(x),(s16)(y),(z))
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_14083C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, f32 arg5, f32 arg6) {
    u32 v0;
    f32 v2, v3, v5, v6, v7, v8, v9, v10;
    f32 v14, v16, v17, v18, v19, v21, v22, v23, v24, v26, v27, v28, v29, v31, v32, v34, v33;
    FontDrawPacket loc_8;
    f32 v13, v15, v12;
    v3 = lbl_1_rodata_863C;
    v0 = lbl_1_bss_8B3A0.unk_140;
    if ((v0 & 0x80000000) != 0) {
        v2 = lbl_1_bss_8B3A0.unk_148;
        v5 = v2 * lbl_1_rodata_85F0;
        if (v0 & 2) {
            v6 = lbl_1_bss_8B3A0.unk_146 / v5;
            v2 = lbl_1_rodata_861C;
            v2 = v6 < v2 ? v2 : v6 > v3 ? v3 : v6;
            v3 = v2;
        } else if (v0 & 1) {
            inv_clamp(&v3, lbl_1_bss_8B3A0.unk_146 - v5, v5);
        }
    } else if (lbl_1_bss_8B3A0.unk_0 == -1) return;
    loc_8 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_8.image = 0xA109;
    position(&loc_8,arg0,arg1,arg5);
    v12 = (s16)arg2 * v3;
    v13 = v12 / lbl_1_rodata_9174;
    loc_8.alpha = arg6 * clamp_f(v13);
    loc_8.flags = arg4;
    v15 = (s16)arg3 * v3;
    fn_1_50164(&loc_8, v12 > lbl_1_rodata_917C ? v12 : lbl_1_rodata_917C,
        v15 > lbl_1_rodata_9178 ? v15 : lbl_1_rodata_9178,
        lbl_1_rodata_8818, lbl_1_rodata_9180);
    loc_8 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_8.image = 18;
    position(&loc_8,arg0,arg1,lbl_1_rodata_85F0 + arg5);
    v18 = lbl_1_rodata_9184 * v12;
    v19 = v18 / lbl_1_rodata_9174;
    loc_8.flags = arg4;
    loc_8.alpha = lbl_1_rodata_9188 * clamp_f(v19);
    *(u32 *)((u8 *)&loc_8 + 56) = lbl_1_rodata_9170;
    fn_1_50164(&loc_8,
        v18 > lbl_1_rodata_9174 ? v18 : lbl_1_rodata_9174,
        lbl_1_rodata_8A30 * v15 > lbl_1_rodata_918C ? lbl_1_rodata_8A30 * v15 : lbl_1_rodata_918C,
        lbl_1_rodata_8638,lbl_1_rodata_8638);
    loc_8 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_8.image = 0xA109;
    loc_8.flags = 6;
    loc_8.x = (s16)arg0;
    v26 = (s16)arg1;
    v27 = half_f(v15 > lbl_1_rodata_9178 ? v15 : lbl_1_rodata_9178);
    v28 = arg5 - lbl_1_rodata_9190;
    loc_8.z = v28;
    v29 = v26 - v27;
    loc_8.y = v29;
    loc_8.alpha = arg6 * CLAMP(v13);
    fn_1_51678(&loc_8,loc_8.image,68,0,8,28);
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_8.image = 0xA109;
    loc_8.flags = 14;
    loc_8.x = (s16)arg0;
    v31 = (s16)arg1;
    v15 = v15 > lbl_1_rodata_9178 ? v15 : lbl_1_rodata_9178;
    v34 = v15 * lbl_1_rodata_85F0;
    v33 = arg5 - lbl_1_rodata_9190;
    loc_8.z = v33;
    v34 = v31 + v34;
    loc_8.y = v34;
    loc_8.alpha = arg6 * CLAMP(v13);
    fn_1_51678(&loc_8,loc_8.image,68,64,8,28);
    fn_1_4F734(&loc_8);
}
/* fzgx:end fn_1_14083C */

/* fzgx:begin fn_1_140EE8 */
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);


typedef struct {
    u32 words[22];
} LocalObj;

void fn_1_140EE8(u8 arg0, int arg1, int arg2) {
    u32 choices[10];
    LocalObj obj = *(LocalObj *)lbl_1_rodata_26F8;
    int index;
    if (arg2 != 0) {
        choices[0] = lbl_1_rodata_9194[0];
        choices[1] = lbl_1_rodata_9194[1];
        choices[2] = lbl_1_rodata_9194[2];
        choices[3] = lbl_1_rodata_9194[3];
        choices[4] = lbl_1_rodata_9194[4];
        choices[5] = lbl_1_rodata_9194[5];
        choices[6] = lbl_1_rodata_9194[6];
        choices[7] = lbl_1_rodata_9194[7];
        choices[8] = lbl_1_rodata_9194[8];
        choices[9] = lbl_1_rodata_9194[9];
        index = arg0 - 0x24;
        obj.words[0] = choices[index < 0 ? 0 : index > 9 ? 9 : index];
    } else {
        obj.words[0] = ((u32 *)lbl_1_rodata_85AC)[
            (*(u8 (*)[24])&lbl_1_data_2B144)[((u8 *)&lbl_1_data_2B0D4)[arg0]]
        ];
    }
    *(f32 *)&obj.words[1] = lbl_1_rodata_8658;
    *(f32 *)&obj.words[2] = lbl_1_rodata_8BA8;
    if (arg1 == 0) {
        ((u8 *)&obj)[0x3A] = 0xB4;
        ((u8 *)&obj)[0x39] = 0xB4;
        ((u8 *)&obj)[0x38] = 0xB4;
    }
    *(f32 *)&obj.words[11] = lbl_1_rodata_8A4C;
    obj.words[12] = 10;
    if (fn_1_A5DC4() || arg1 != 0) {
        *(f32 *)&obj.words[4] *= lbl_1_rodata_91BC;
        *(f32 *)&obj.words[5] *= lbl_1_rodata_91BC;
    }
    fn_1_4E724(&obj);
}
/* fzgx:end fn_1_140EE8 */

/* fzgx:begin fn_1_14108C noprologue */
#include "types.h"
#include "font.h"

typedef struct {
    u32 words[11];
} U32x11;

typedef struct {
    u32 unk0;      // 0x00
    f32 x;         // 0x04
    f32 y;         // 0x08
    f32 z;         // 0x0c
    f32 unk10;     // 0x10
    f32 unk14;     // 0x14
    u32 unk18[6];  // 0x18
    u32 unk30;     // 0x30
    u32 unk34[9];  // 0x34
} Packet;

extern u32 lbl_1_rodata_91C0[11];
extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_91F0;
extern const f32 lbl_1_rodata_8B30;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_141338(u8, u32, u32, u32, f32);

void fn_1_14108C(s16 arg0, s32 arg1, s32 arg2) {
    U32x11 ids;
    Packet packet;
    f32 v;

    ids = *(U32x11 *)lbl_1_rodata_91C0;

    packet = *(Packet *)lbl_1_rodata_26F8;
    packet.unk0 = ids.words[arg0];
    packet.x = arg1;
    packet.y = arg2;
    packet.z = lbl_1_rodata_85E8;
    packet.unk10 = packet.unk10 * lbl_1_rodata_91EC;
    packet.unk14 = packet.unk14 * lbl_1_rodata_91EC;
    packet.unk30 = 10;
    fn_1_4F734((FontDrawPacket *)&packet);

    v = lbl_1_rodata_8674 - arg1;
    packet.x = v;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = *(Packet *)lbl_1_rodata_26F8;
    packet.unk0 = 0x10000 - 0x5EF7;
    packet.x = arg1;
    packet.y = arg2;
    packet.z = lbl_1_rodata_8B30;
    packet.unk10 = packet.unk10 * lbl_1_rodata_91F0;
    packet.unk14 = packet.unk14 * lbl_1_rodata_91EC;
    packet.unk30 = 10;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet.x = v;
    fn_1_4F734((FontDrawPacket *)&packet);

    fn_1_141338(arg0, arg1, arg2, 0x2D, lbl_1_rodata_91EC);
    fn_1_141338(arg0, (s32)v, arg2, 0x2D, lbl_1_rodata_91EC);
}
/* fzgx:end fn_1_14108C */

/* fzgx:begin fn_1_141338 */
// Pass through the caller's arguments and append the default scale factor.
void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4) {
    fn_1_141360(arg0, arg1, arg2, arg3, arg4, lbl_1_rodata_863C);
}
/* fzgx:end fn_1_141338 */

/* fzgx:begin fn_1_141360 */


#pragma opt_propagation off
static inline f32 fn_1_141360_operand(f32 right, f32 left) { return left * right; }
void fn_1_141360(u32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5)
{
    Tbl tbl;
    fn_1_141360_Pkt pkt;
    s32 idx;
    s32 j;
    f32 t, u, v;

    tbl = lbl_1_rodata_91F4;
    j = (arg0 & 0xFF) - 1;
    if (j < 0) {
        idx = 0;
    } else {
        idx = 4;
        if ((u32)j <= 4) {
            idx = j;
        }
    }
    t = (lbl_1_rodata_87AC) * (lbl_1_rodata_863C + (lbl_8006D188((s32)(fn_1_141360_operand(lbl_1_rodata_87E8, (lbl_1_rodata_8B2C * ((((u32 *)&lbl_801A66A0))[0] & 3)))))));
    u = t * lbl_1_rodata_85F0;
    v = lbl_1_rodata_8A24 + u;
    v = arg5 * v;
    pkt = (*((fn_1_141360_Pkt *)&lbl_1_rodata_26F8));
    pkt.f00 = 0x10000 - 0x5EEE;
    pkt.f04 = arg1;
    pkt.f08 = arg2;
    pkt.f0C = arg3;
    pkt.f10 = pkt.f10 * arg4;
    pkt.f14 = pkt.f14 * arg4;
    pkt.f38 = (v * tbl.e[(u8)idx].a);
    pkt.f39 = (v * tbl.e[(u8)idx].b);
    pkt.f3A = (v * tbl.e[(u8)idx].c);
    pkt.f30 = 0x4000000 + 0xA;
    pkt.f50 = (u32)&fn_1_52718;
    fn_1_4F734( (FontDrawPacket*)(fn_1_141360_Pkt *)(&pkt));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_141360 */

/* fzgx:begin fn_1_141614 noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

void fn_1_141614(s16 arg0) {
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_495B0(1u << 31);
    fn_1_495C8( (void*)(1));
    fn_1_4955C(lbl_1_rodata_9208, lbl_1_rodata_9208);
    fn_1_4966C(lbl_1_rodata_8638, lbl_1_rodata_861C);
    fn_1_496FC(lbl_1_rodata_8658, lbl_1_rodata_920C);
    fn_1_4A0D8( (*(void**)(lbl_1_data_2AA24 +
            4 * ((u8*)&lbl_1_data_2B0D4)[(s16)arg0])));

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_495B0(1u << 31);
    fn_1_495C8( (void*)(1));
    fn_1_4966C(lbl_1_rodata_8638, lbl_1_rodata_861C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(lbl_1_rodata_8658, lbl_1_rodata_9210);
    fn_1_4A0D8( (((void**)(lbl_1_data_2BD54 + (s16)arg0 * 24))[lbl_801A66B4]));
}
/* fzgx:end fn_1_141614 */

/* fzgx:begin fn_1_141754 noprologue */
typedef struct {
    u32 w[3];
} Copy9214;

typedef struct {
    u32 w0;
    u32 w1;
    u16 h;
} Copy9220;

void fn_1_141754(s32 arg0, s32 arg1) {
    FontDrawPacket packet;
    Copy9214 copy9214;
    Copy9220 copy9220;
    u8 *var_r29;
    u8 *var_r28;
    s32 var_r27;
    s32 var_r26;
    u32 i;
    u32 image;
    FontDrawPacket *src;

    copy9214.w[0] = *lbl_1_rodata_9214;
    copy9214.w[1] = *(u32 *)((u8 *)lbl_1_rodata_9214 + 4);
    copy9214.w[2] = *(u32 *)((u8 *)lbl_1_rodata_9214 + 8);
    copy9220.w0 = *(u32 *)(lbl_1_rodata_9220);
    copy9220.w1 = *(u32 *)((u8 *)lbl_1_rodata_9220 + 4);
    copy9220.h = *(u16 *)((u8 *)lbl_1_rodata_9220 + 8);
    image = (0x10000 - 0x5EF1);
    var_r27 = 0;
    var_r26 = 0;
    var_r29 = (u8 *)&copy9214;
    var_r28 = (u8 *)&copy9220;
    i = 0;
    src = (FontDrawPacket *)&lbl_1_rodata_26F8;
    do {
        packet = *src;
        packet.image = image;
        fn_1_51678(&packet, packet.image, var_r26, 0, *(u16 *)var_r29,
                   fn_1_486C4(packet.image));
        packet.x = ((((arg0) + (0x16)) + var_r27));
        packet.y = (arg1 + 0x12);
        packet.z = lbl_1_rodata_8E9C;
        *(u32 *)((u8 *)&packet + 0x30) = 0xa;
        fn_1_4F734(&packet);
        var_r27 += *(u16 *)var_r28;
        var_r26 += *(u16 *)var_r29;
        if (i == 4) {
            var_r26 += 0x14;
        }
        i += 1;
        var_r29 += 2;
        var_r28 += 2;
    } while (i < 6);
}
/* fzgx:end fn_1_141754 */

/* fzgx:begin fn_1_1418EC */



#pragma opt_loop_invariants off
void fn_1_1418EC(u32 arg0, u32 arg1) {
	struct S16 wid;
	u32 ln[3];
	struct fn_1_1418EC_Pkt pkt;
	u32 xoff = 0;
	s32 aoff = 0;
	u32 i;
	u32 a0 = arg0;
	u32 id = 0xA10F;
	s16 w;

	wid.a = lbl_1_rodata_922C.a;
	wid.b = lbl_1_rodata_922C.b;
	wid.c = lbl_1_rodata_922C.c;
	wid.d = lbl_1_rodata_922C.d;

	ln[0] = ((lbl_1_rodata_923C)[0]);
	ln[1] = ((lbl_1_rodata_923C)[1]);
	ln[2] = ((lbl_1_rodata_923C)[2]);

	for (i = 0; i < 7; i++) {
		pkt = (*((struct fn_1_1418EC_Pkt *)&lbl_1_rodata_26F8));
		pkt.index = id;
		w = fn_1_486C4(pkt.index);
		fn_1_51678((FontDrawPacket *)&pkt, pkt.index, aoff, 0,
			((u16 *)&wid)[i], w);
		pkt.x = (s32)((((a0) + (0x16)) + xoff));
		pkt.y = (s32)(arg1 + 0x12);
		pkt.z = lbl_1_rodata_8E9C;
		pkt.flags = 10;
		fn_1_4F734((FontDrawPacket *)&pkt);
		xoff += ((u16 *)ln)[i];
		aoff += ((u16 *)&wid)[i];
	}
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_1418EC */

/* fzgx:begin fn_1_141A80 noprologue */
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
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern s16 fn_1_12C930(void* arg0);
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

struct fn_1_141A80_Copy { u8 a[111]; };

extern Obj_1_bss_4B9CC *lbl_1_data_414D8[120];
extern struct fn_1_141A80_Copy lbl_1_rodata_9248;

extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);

void fn_1_141A80(s16 arg0) {
    struct fn_1_141A80_Copy loc;
    u8 i;
    loc = lbl_1_rodata_9248;
    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(lbl_1_rodata_88B8, lbl_1_rodata_8840);
    fn_1_495B0(0x80000000);
    {
        s32 selection = (&lbl_801A66B4)[0];
        f32 scale = lbl_1_rodata_85F4;
        scale = scale;
        fn_1_4CE48(lbl_1_data_414D8[(s16)selection + 108], scale);
    }
    for (i = 1; i <= loc.a[(arg0 < 0) ? 0 : ((arg0 > 110) ? 110 : arg0)]; i++) {
        fn_1_496FC((i * 18 + 300), lbl_1_rodata_8840);
        fn_1_4A0D8((const char *)&lbl_1_data_42194);
    }
}
/* fzgx:end fn_1_141A80 */

/* fzgx:begin fn_1_141C10 noprologue */
extern u32 lbl_801A66A0;
extern u32 lbl_1_bss_8E424;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_92B8;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_9164;
extern const f32 lbl_1_rodata_8D9C;
extern const f32 lbl_1_rodata_8960;
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87F4;
extern const f32 lbl_1_rodata_85F0;
extern u8 fn_1_F8CF0(s32);
extern f32 lbl_8006D188(u32);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(void *);
extern void fn_1_49528(u32 *);
extern void fn_1_4A0D8(const char *);

static inline s32 fn_1_141C10_elapsed(const u32 *last) {
    s32 elapsed;
    u32 start;
    const u32 *current;
    start = *(volatile const u32 *)last;  /* fzgx-allow: S2 volatile keeps the verified access order */
    current = &lbl_801A66A0;
    elapsed = *(volatile const u32 *)current;  /* fzgx-allow: S2 volatile keeps the verified access order */
    elapsed = elapsed - start;
    return elapsed;
}

void fn_1_141C10(u8 arg0) {
    s32 flag;
    s32 blink;
    u8 *table;
    u32 idx;
    s32 diff;
    f32 wave;
    f32 scaled;
    s32 level;
    FontDrawPacket packet;
    u8 bytes[4];
    u32 color;

    flag = 0;
    blink = 0;
    if ((*(&lbl_1_bss_9F8.unk_8 + lbl_1_bss_8B3A0.unk_9E * 10) >> 4) & 1) {
        lbl_1_bss_8E424 = lbl_801A66A0;
    }
    table = (u8 *)&lbl_1_data_2B0D4;
    idx = arg0;
    if (table[idx] == 1 || table[idx] == 17) {
        if (fn_1_F8CF0(0)) {
            flag = 1;
            if (lbl_1_bss_8B5F0 == 1) {
                blink = 1;
            } else {
                blink = 0;
            }
        }
    }
    if (table[idx] == 4) {
        if (fn_1_F8CF0(1)) {
            flag = 1;
            if (lbl_1_bss_8B5F1 == 1) {
                blink = 1;
            } else {
                blink = 0;
            }
        }
    }
    if (flag == 0) {
        return;
    }

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x10000 - 0x5EF5;
    packet.x = lbl_1_rodata_8658;
    packet.y = lbl_1_rodata_92B8;
    packet.z = lbl_1_rodata_8B84;
    packet.flags = 10;
    if (blink == 0) {
        packet.color[2] = 0x80;
        packet.color[1] = 0x80;
        packet.color[0] = 0x80;
    }
    if (blink != 0) {
        diff = fn_1_141C10_elapsed(&lbl_1_bss_8E424);
        if ((u32)diff < 15) {
            wave = lbl_8006D188((s32)(lbl_1_rodata_9164 + (lbl_1_rodata_8B2C * (diff % 60)) / lbl_1_rodata_8B30));
            level = (lbl_1_rodata_8D9C * wave);
            packet.color_add[2] = level;
            packet.color_add[1] = level;
            packet.color_add[0] = level;
        }
    }
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8658, lbl_1_rodata_8960);
    fn_1_4954C(lbl_1_rodata_8A54);
    fn_1_495C8((void *)9);
    if (blink == 0) {
        diff = lbl_801A66A0 - lbl_1_bss_8E424;
        scaled = lbl_1_rodata_863C + lbl_8006D188((s32)(lbl_1_rodata_9164 + (lbl_1_rodata_8B2C * (diff % 60)) / lbl_1_rodata_8B30));
        bytes[3] = 0;
        level = (lbl_1_rodata_87F4 * scaled / 2.0f);
        bytes[2] = level;
        bytes[1] = level;
        bytes[0] = level;
        color = *(u32 *)bytes;
        fn_1_49528(&color);
    }
    fn_1_4A0D8((const char *)lbl_1_data_41B3C);
}
/* fzgx:end fn_1_141C10 */

/* fzgx:begin fn_1_141F94 noprologue */
typedef struct fn_1_141F94_Entry {
    u8 pad[0x0E];
    s16 value;
    u8 tail[0x10];
} fn_1_141F94_Entry;


u8 fn_1_141F94(u32 arg0) {
    fn_1_141F94_Entry *entry;
    u32 index = arg0 & 0xFF;
    u8 count = 0;

    if (index >= 4) {
        return 0;
    }
    entry = (((fn_1_141F94_Entry *)&lbl_1_bss_8B3A0));
    if ((((fn_1_141F94_Entry *)&lbl_1_bss_8B3A0))[(u8)arg0].value == -1) {
        return 0;
    }
    for (; (s32)index > 0; index--) {
        if (entry->value != -1) {
            count++;
        }
        entry++;
    }
    return count;
}
/* fzgx:end fn_1_141F94 */

/* fzgx:begin fn_1_142004 noprologue */
typedef struct fn_1_142004_Entry {
    u8 pad[0x0E];
    s16 value;
    u8 tail[0x10];
} fn_1_142004_Entry;


int fn_1_142004(u8 arg0) {
    fn_1_142004_Entry *entry = (((fn_1_142004_Entry *)&lbl_1_bss_8B3A0));
    s32 index = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (entry->value != -1) {
            if (++index == arg0) {
                return i;
            }
        }
        entry++;
    }
    return 0;
}
/* fzgx:end fn_1_142004 */

/* fzgx:begin fn_1_1420A4 noprologue */
void fn_1_1420A4(void) {
    ((void (**)(void))lbl_1_data_4244C)[lbl_1_bss_8E51D]();
}
/* fzgx:end fn_1_1420A4 */
