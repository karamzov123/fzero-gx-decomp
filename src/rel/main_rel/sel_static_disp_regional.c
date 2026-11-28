/* Previously matched Japan/PAL units of sel_static_disp.c, retained until that TU matches those releases as one unit. */
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
