#include "types.h"
#include "dolphin/types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#define lbl_1_bss_8E428 sel_h_lbl_1_bss_8E428
#define lbl_1_data_42198 sel_h_lbl_1_data_42198
#define lbl_1_data_42478 sel_h_lbl_1_data_42478
#define lbl_1_data_4247C sel_h_lbl_1_data_4247C
#define lbl_1_data_42488 sel_h_lbl_1_data_42488
#define lbl_1_data_4244C sel_h_lbl_1_data_4244C
#define lbl_1_data_424CC sel_h_lbl_1_data_424CC
#define lbl_1_data_42808 sel_h_lbl_1_data_42808
#define lbl_1_data_42810 sel_h_lbl_1_data_42810
#define lbl_1_data_424A0 sel_h_lbl_1_data_424A0
#define lbl_1_data_42570 sel_h_lbl_1_data_42570
#define lbl_1_data_424AC sel_h_lbl_1_data_424AC
#define lbl_1_data_42480 sel_h_lbl_1_data_42480
#define lbl_1_data_422B0 sel_h_lbl_1_data_422B0
#define lbl_1_data_425C8 sel_h_lbl_1_data_425C8
#define lbl_1_data_425D8 sel_h_lbl_1_data_425D8
#include "rel/main_rel/sel_static_disp.h"
#undef lbl_1_bss_8E428
#undef lbl_1_data_42198
#undef lbl_1_data_42478
#undef lbl_1_data_4247C
#undef lbl_1_data_42488
#undef lbl_1_data_4244C
#undef lbl_1_data_424CC
#undef lbl_1_data_42808
#undef lbl_1_data_42810
#undef lbl_1_data_424A0
#undef lbl_1_data_42570
#undef lbl_1_data_424AC
#undef lbl_1_data_42480
#undef lbl_1_data_422B0
#undef lbl_1_data_425C8
#undef lbl_1_data_425D8
#include "game/vec3.h"
#include "font.h"
/* TU2b (sel_static_disp mode state) globals read here */
extern f32 lbl_1_bss_8E530;
extern f32 lbl_1_bss_8E534;
extern s32 lbl_1_bss_8E538;
extern s32 lbl_1_bss_8E53C;
extern u8 lbl_1_bss_8E550;
extern u32 lbl_1_bss_8E554;
extern s32 lbl_1_bss_8E570;
extern u8 lbl_1_bss_8E594;
extern u8 lbl_1_bss_26B1E[0x2E];
#include "psvec.h"
#include "fpscr_trunc.h"

/* fn_1_1420A4 */
typedef struct {
    u32 v[8];
} Word8;

/* fn_1_1420A4 */
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

/* fn_1_1420A4 */
typedef struct {
    u32 value[22];
} Fn139F18Data;

/* fn_1_1420A4 */
typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

/* fn_1_1420A4 */
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

/* fn_1_1420A4 */
typedef struct {
    const char *p[9];
} PtrTab;

/* fn_1_1420A4 */
struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_1420A4 */
struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

/* fn_1_1420A4 */
struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

/* fn_1_1420A4 */
typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

/* fn_1_1420A4 */
typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

/* fn_1_1420A4 */
struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_1420A4 */
struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

/* fn_1_1420A4 */
struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

/* fn_1_1420A4 */
typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

/* fn_1_1420A4 */
typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

/* fn_1_1420A4 */
typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

/* fn_1_1420A4 */
typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

/* fn_1_1420A4 */
typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

/* fn_1_1420A4 */
typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

/* fn_1_1420A4 */
typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

/* fn_1_1420A4 */
typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

/* fn_1_1420A4 */
typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

/* fn_1_1420A4 */
typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

/* fn_1_1420A4 */
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

/* fn_1_1420A4 */
typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;

/* fn_1_1420A4 */
struct fn_1_141A80_Copy { u8 a[111]; };

/* fn_1_1420A4 */
typedef struct fn_1_141F94_Entry {
    u8 pad[0x0E];
    s16 value;
    u8 tail[0x10];
} fn_1_141F94_Entry;

/* fn_1_14267C */
typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

/* fn_1_14267C */
typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    Vec3 axis_x;      // 0x08
    Vec3 axis_y;      // 0x14
    Vec3 axis_z;      // 0x20
    Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

/* fn_1_14267C */
typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

/* fn_1_14267C */
typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;

/* fn_1_14267C */
typedef struct Sig_fn_1_144A5C_fn_1_143F5C_Args {
 s32 x,y,w0,h0,w1,h1; u32 *list0; s32 count0; u32 *list1; s32 count1;
} Sig_fn_1_144A5C_fn_1_143F5C_Args;

/* fn_1_14267C */
typedef struct { u8 _pad[6]; s16 field_6; } Sig_fn_1_8472C_Fn18472CObject;

/* fn_1_14267C */
typedef struct Sig_fn_80015EE8_Fn80015EE8Out { f32 f[16]; } Sig_fn_80015EE8_Fn80015EE8Out;

/* fn_1_14267C */
struct Sig_fn_800737E4_fn_800737E4_Arg0 { f32 unk_0; u8 pad_4[4]; f32 unk_8,unk_C; u8 pad_10[4]; f32 unk_14,unk_18,unk_1C; u8 pad_20[8]; f32 unk_28,unk_2C; };

/* fn_1_14267C */
struct Sig_fn_80072270_fn_80072270_Arg0 { f32 unk_0,unk_4,unk_8,unk_c,unk_10,unk_14,unk_18; };

/* fn_1_14267C */
struct fn_1_14267C_Copy88 { u32 a[22]; };

/* fn_1_14267C */
struct fn_1_14267C_lbl_1_rodata_92C0 {
 u8 pad_0[0x108]; f32 unk_108; u8 pad_10C[0x1C]; f64 unk_128; u8 pad_130[8];
 u32 unk_138,unk_13C,unk_140,unk_144,unk_148,unk_14C,unk_150,unk_154,unk_158,unk_15C,unk_160;
 f32 unk_164,unk_168,unk_16C,unk_170,unk_174,unk_178,unk_17C,unk_180,unk_184,unk_188,unk_18C,unk_190,unk_194;
};

/* fn_1_14267C */
struct fn_1_14267C_lbl_1_data_1E5C0 { u32 unk_0,unk_4,unk_8,unk_C,unk_10,unk_14,unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30; };

/* fn_1_14267C */
struct PanelPoolU32 { u32 v; };

/* fn_1_14267C */
struct PanelPoolF32 { f32 v; };

/* fn_1_142BDC */
struct fn_1_142BDC_Copy88 { u32 a[22]; };

/* fn_1_142BDC */
struct fn_1_142BDC_lbl_1_rodata_92C0 {
    u8 pad_0[0x108];
    f32 unk_108;
    u8 pad_10C[0x1C];
    f64 unk_128;
    u8 pad_130[0x68];
    f32 unk_198;
    f32 unk_19C;
    f32 unk_1A0;
    f32 unk_1A4;
    f32 unk_1A8;
    f32 unk_1AC;
    f32 unk_1B0;
};

/* fn_1_142BDC */
struct fn_1_142BDC_lbl_1_bss_3C30 {
    u8 pad_0[0x5];
    u8 unk_5;
};

/* fn_1_14328C */
struct Struct_26F8_fn_1_14328C {
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

/* fn_1_14328C */
struct fn_1_13F8C4_lbl_801A6410_fn_1_14328C {
    u32 unk_0;
};

/* fn_1_14328C */
struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_14328C {
    u32 unk_0;
};

/* fn_1_14328C */
struct fn_1_149C64_lbl_1_bss_8E440_fn_1_14328C {
    u32 unk_0;
};

/* fn_1_14328C */
struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_14328C {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_14328C */
struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14328C {
    u8 pad_00[0x24];
    void *field_24;
};

/* fn_1_14328C */
struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_14328C {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14328C **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

/* fn_1_14328C */
struct fn_1_14328C_Copy88 { u32 a[22]; };

/* fn_1_14328C */
struct fn_1_14328C_lbl_1_bss_26B04 {
    u8 unk_0[1];
};

/* fn_1_143780 */
struct fn_1_143780_lbl_801A66A4 { s32 unk_0; };

/* fn_1_143780 */
struct fn_1_143780_entry { u32 unk_0; f32 unk_4; u8 unk_8, unk_9; u16 unk_A; };

/* fn_1_143780 */
struct fn_1_143780_view { u8 pad_0[0x16C]; struct fn_1_143780_entry entries[10]; };

/* fn_1_143780 */
typedef struct fn_1_143780_Color { u8 c[4]; } Color;

/* fn_1_143F5C */
typedef struct fn_1_143F5C_Args {
    s32 x;
    s32 y;
    s32 w0;
    s32 h0;
    s32 w1;
    s32 h1;
    u32 *list0;
    s32 count0;
    u32 *list1;
    s32 count1;
} fn_1_143F5C_Args;

/* fn_1_144254 */
struct fn_1_144254_Copy16 { u32 a[4]; };

/* fn_1_144254 */
struct fn_1_144254_Copy88 { u32 a[22]; };

/* fn_1_144254 */
struct fn_1_144254_Bounds { s16 x, y; f32 width; s16 x2, y2; };

/* fn_1_144254 */
struct fn_1_144254_lbl_1_rodata_92C0 {
    u8 pad_0[0x114]; f32 unk_114; u8 pad_118[4]; f32 unk_11C;
    u8 pad_120[8]; f64 unk_128; u8 pad_130[0x60];
    f32 unk_190, unk_194; u8 pad_198[0x14]; f32 unk_1AC;
    u8 pad_1B0[4]; f32 unk_1B4, unk_1B8; u8 pad_1BC[0x1C];
    f32 unk_1D8; u8 pad_1DC[4]; f32 unk_1E0, unk_1E4;
    u8 pad_1E8[0x38]; f32 unk_220; u8 pad_224[0x118];
    u32 unk_33C, unk_340, unk_344, unk_348, unk_34C, unk_350, unk_354, unk_358;
    f32 unk_35C, unk_360, unk_364, unk_368, unk_36C, unk_370, unk_374, unk_378, unk_37C, unk_380, unk_384;
};

/* fn_1_144A5C */
typedef struct fn_1_144A5C_Args {
    s32 x;
    s32 y;
    s32 w0;
    s32 h0;
    s32 w1;
    s32 h1;
} fn_1_144A5C_Args;

/* fn_1_144F40 */
typedef struct {
    u8 r, g, b, a;
} Color_144F40;

/* fn_1_144F40 */
typedef struct {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    Color_144F40 color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    FontDrawPacket *secondary;
    void (*vertex_callback)(const FontDrawPacket *packet, FontVertex *vertices);
    u32 unk_54;
} Packet;

/* fn_1_144F40 */
typedef struct {
    s32 x;          /* 0x00 */
    s32 y;          /* 0x04 */
    s32 unk_8;      /* 0x08 */
    s32 unk_C;      /* 0x0C */
    s32 unk_10;     /* 0x10 */
    s32 unk_14;     /* 0x14 */
    f32 unk_18;     /* 0x18 */
    f32 unk_1C;     /* 0x1C */
    s32 unk_20;     /* 0x20 */
    s32 unk_24;     /* 0x24 */
    void *unk_28;   /* 0x28 */
    u32 unk_2C;     /* 0x2C */
    u32 unk_30;     /* 0x30 */
    u8 unk_34;      /* 0x34 */
    u8 unk_35;      /* 0x35 */
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3A[2];
    u32 unk_3C;     /* 0x3C */
    u16 unk_40;     /* 0x40 */
    u16 unk_42[5];  /* 0x42 */
    s32 unk_4C;     /* 0x4C */
    u8 pad_50[4];
    u16 unk_54;     /* 0x54 */
    u8 unk_56[5];   /* 0x56 */
    u8 pad_5B;
    s32 unk_5C;     /* 0x5C */
    u8 unk_60;
    u8 unk_61;
    u16 unk_62;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    FontDrawPacket packet[3]; /* 0x7C */
} Row;

/* fn_1_144F40 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x10];
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u8 pad_20[0x18];
} Entry;

/* fn_1_144F40 */
typedef struct {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[2];
    u8 unk_8;
    u8 unk_9[5];
    u8 unk_E[0x16];
    u32 unk_24[10];
    u16 unk_4C[5];
    u8 pad_56[0x2A];
    u8 unk_80;
    u8 pad_81;
    u8 unk_82;
    u8 unk_83;
    u8 pad_84[0x1A];
    u16 unk_9E;
} Record;

/* fn_1_144F40 */
typedef struct {
    u8 pad_0[6];
    u8 unk_6;
    u8 pad_7[2];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    Record unk_D4[30];
} Setup;

/* fn_1_145C6C */
typedef struct {
    u8 pad_0[0x34];
    u8 unk_34;
} Row_145C6C;

/* fn_1_146550 */
typedef struct {
    u8 pad_0[0x64];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    FontDrawPacket packet[3]; /* 0x7C */
} fn_1_146550_Row;

/* fn_1_146C88 */
typedef struct {
    u8 pad_0[0x24];
    s32 unk_24;
    u8 pad_28[0xD];
    u8 unk_35;
    u8 pad_36[0x16];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    u8 pad_70[0xBC];
    FontDrawPacket unk_12C;
} fn_1_146C88_Obj;

/* fn_1_146C88 */
typedef struct {
    u32 a[4];
} fn_1_146C88_Tbl;

/* fn_1_147188 */
typedef struct {
    u8 pad_0[0x20];
    s32 unk_20;
    u8 pad_24[0x28];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    u8 pad_68[0x4];
    s32 unk_6C;
    u8 pad_70[0xBC];
    FontDrawPacket unk_12C;
} fn_1_147188_Row;

/* fn_1_147508 */
typedef struct fn_1_147508_Entry {
    u8 pad_0[0x20];
    s32 unk_20;
    s32 unk_24;
    u8 pad_28[0xD];
    u8 unk_35;
    u8 pad_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3A[0x12];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    u8 pad_68[0xC];
    s32 unk_74;
    u8 pad_78[0x5C];
    FontDrawPacket packet;
} fn_1_147508_Entry;

/* fn_1_147A04 */
typedef struct {
    f32 value0;
    u8 pad[8];
    f32 value_c;
} Sig_fn_1_149B24_Fn149B24Data;

/* fn_1_147A04 */
struct fn_1_147A04_Copy96 { u32 a[24]; };

/* fn_1_147A04 */
struct fn_1_147A04_Copy24 { const char *a[6]; };

/* fn_1_147A04 */
typedef struct {
    u8 pad_0[0x20];
    s32 unk_20;
    s32 unk_24;
    char *unk_28;
    Obj_1_bss_4B9CC *unk_2C;
    u8 pad_30[0x1C];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[8];
    s32 unk_74;
    s32 unk_78;
} fn_1_147A04_Obj;

/* fn_1_148444 */
typedef struct {
    u8 pad_0[0x56];
    u8 unk_56[6];
    s32 unk_5C;
    u8 pad_60[0x4];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x8];
    s32 unk_74;
} fn_1_148444_Obj;

/* fn_1_148738 */
typedef struct {
    u8 pad_0[0x36];
    u8 unk_36;
    u8 pad_37[0x2D];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x8];
    s32 unk_74;
} fn_1_148738_Row;

/* fn_1_148950 */
struct Struct_26F8_fn_1_148950 {
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

/* fn_1_148950 */
struct fn_1_13F8C4_lbl_801A6410_fn_1_148950 {
    u32 unk_0;
};

/* fn_1_148950 */
struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_148950 {
    u32 unk_0;
};

/* fn_1_148950 */
struct fn_1_149C64_lbl_1_bss_8E440_fn_1_148950 {
    u32 unk_0;
};

/* fn_1_148950 */
struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_148950 {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_148950 */
struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_148950 {
    u8 pad_00[0x24];
    void *field_24;
};

/* fn_1_148950 */
struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_148950 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_148950 **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

/* fn_1_148950 */
typedef struct {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x8];
    u32 unk_3C;
    u16 unk_40;
    u8 pad_42[0x12];
    u16 unk_54;
    u8 pad_56[0x6];
    s32 unk_5C;
    u8 unk_60;
    u8 unk_61;
    u8 pad_62[0x2];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x4];
    s32 unk_70;
    s32 unk_74;
} fn_1_148950_Row;

/* fn_1_1490FC */
typedef struct {
    u8 pad_0[0x62];
    u16 unk_62;
    s32 unk_64;
    u8 pad_68[0xC];
    s32 unk_74;
} fn_1_1490FC_Row;

/* fn_1_1492E0 */
struct fn_1_1492E0_Copy88 { u32 a[22]; };

/* fn_1_1492E0 */
struct Results56 { u32 a[14]; };

/* fn_1_1492E0 */
struct fn_1_1498B8_Copy88 { u32 a[22]; };

/* fn_1_1492E0 */
struct fn_1_1498B8_lbl_801A66A4 { u32 unk_0; };

/* fn_1_149E2C */
typedef struct fn_1_149E2C_Racer {
    u8 pad_0[0xE];
    u8 unk_E;
    u8 pad_F[0x9];
    u16 unk_18;
    u8 pad_1A[0x1E];
    u32 unk_38;
    u8 pad_3C[0x64];
} fn_1_149E2C_Racer;

/* fn_1_149E2C */
typedef struct fn_1_149E2C_Sel {
    u8 pad_0[0x9];
    u8 count;
    u8 pad_A[0x4];
    u8 order[0xC6];
    fn_1_149E2C_Racer racers[1];
} fn_1_149E2C_Sel;

/* fn_1_14A028 */
typedef struct {
    void (*unk_0)(void *, u32);
    void (*unk_4)(void);
    void (*unk_8)(void);
    u32 unk_C;
} Ent;

/* fn_1_14A028 */
typedef struct {
    u32 unk_0;
    u8 pad_4[4];
    u8 unk_8;
} Obj3C30;

/* fn_1_14A028 */
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

/* fn_1_14A028 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
} Obj9F8;

/* fn_1_14A17C */
typedef struct {
    u8 pad_0[0x18];
    f32 unk_18;
    f32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
} fn_1_14A17C_Obj_1_bss_8E518;

/* fn_1_14A1AC */
typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 unk_9;
} fn_1_14A1AC_Obj_1_bss_3C30;

/* fn_1_14A328 */
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
} Obj_1_bss_3C30_L;

/* fn_1_14A328 */
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
} Obj_1_bss_9F8_L;

/* fn_1_14A328 */
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0_L;

/* fn_1_14A9D0 */
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

/* fn_1_14A9D0 */
struct fn_1_14A9D0_lbl_1_bss_9F8 {
u8 pad_0[0x10];
u16 unk_10;
u16 unk_12;
};

/* fn_1_14A9D0 */
typedef struct lbl_1_bss_9F8_t {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0x3c];
} lbl_1_bss_9F8_t;

/* fn_1_14AE94 */
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

/* fn_1_14AE94 */
struct fn_1_13F8C4_lbl_801A6410_fn_1_14AED4 {
    u32 unk_0;
};

/* fn_1_14AE94 */
struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_14AED4 {
    u32 unk_0;
};

/* fn_1_14AE94 */
struct fn_1_149C64_lbl_1_bss_8E440_fn_1_14AED4 {
    u32 unk_0;
};

/* fn_1_14AE94 */
struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_14AED4 {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_14AE94 */
struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14AED4 {
    u8 pad_00[0x24];
    void *field_24;
};

/* fn_1_14AE94 */
struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_14AED4 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14AED4 **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

/* fn_1_14B1FC */
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
} Obj_1_bss_D58_L;

/* fn_1_14B4FC */
typedef struct {
    u8 pad_0[0x18];
    u16 unk_18[6];
    u32 unk_24[5];
    u32 unk_38[18];
    u8 unk_80;
    u8 unk_81;
    u8 pad_82[0x1E];
} fn_1_14B500_Record;

/* fn_1_14B4FC */
typedef struct {
    u8 pad_0[0xE];
    u8 unk_E[30];
    u8 pad_2C[0x7B];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    fn_1_14B500_Record unk_D4[30];
} fn_1_14B500_Setup;

/* fn_1_14B4FC */
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

/* fn_1_14B4FC */
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

/* fn_1_14B93C */
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

/* fn_1_14BC40 */
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

/* fn_1_14BCBC */
struct fn_1_14BCBC_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xA];
};

/* fn_1_14BCBC */
struct fn_1_14BCBC_lbl_1_bss_9F8 {
    struct fn_1_14BCBC_lbl_1_bss_9F8_0_E20 unk_0[1];
};

/* fn_1_14BCBC */
struct fn_1_14BCBC_lbl_1_bss_8E52C {
    u8 unk_0;
};

/* fn_1_14BD94 */
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

/* fn_1_14BE30 */
struct fn_1_14BE30_lbl_1_bss_8E518 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x14];
    u32 unk_28;
    u8 pad_2C[0x14];
    u8 unk_40;
    u8 unk_41;
};

/* fn_1_14BFD8 */
typedef struct InputButtons {
    u16 button;
    u16 unk_2;
} InputButtons;

/* fn_1_14BFD8 */
typedef struct InputPortButtons {
    InputButtons unk_0;
    InputButtons unk_4;
    InputButtons unk_8;
    InputButtons unk_C;
    InputButtons unk_10;
} InputPortButtons;

/* fn_1_14BFD8 */
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

/* fn_1_14C35C */
typedef struct {
    char *unk_0;
    s32 unk_4;
} fn_1_14C35C_Entry;

/* fn_1_14C35C */
typedef struct {
    fn_1_14C35C_Entry unk_0[4];
    s32 unk_20;
} fn_1_14C35C_Table;

/* fn_1_14C6F8 */
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
} Obj_1_bss_8E518_L;

extern void C_MTXOrtho(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void GXGetProjectionv(f32 *);
extern u32 GXGetScissor(void *,void *,void *,void *);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void OSReport(const char *format, ...);
extern u32 __cvt_fp2unsigned(f32);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_12ADA0(char *dst, void *arg);
extern s16 fn_1_12C930(s16);
extern s16 fn_1_12EF24(s16, s16);
extern void fn_1_12EF80(s16, void *, void *);
extern u32 fn_1_12F118(void);
extern void fn_1_131B90(void);
extern void fn_1_131C08(void);
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_137364();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern void fn_1_138144(void* arg0, int arg1);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern void fn_1_13A9B8();
extern u32 fn_1_13ABA8(u32);
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern u32 fn_1_13C5EC(u8);
extern void fn_1_13D460(s32, s32, s32, s32);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern s16 fn_1_14F01C(s16);
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F344(s16);
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern char *fn_1_14FEAC(void *,void *,void *,char *,void *);
extern void fn_1_150654(void);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern void fn_1_150F74(void *self);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern void fn_1_151BDC(void *);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_151C78(void);
extern s32 fn_1_1555B0(s32);
extern void fn_1_1556B4(u8, u8);
extern s32 fn_1_155F7C(void);
extern s32 fn_1_155F8C(void);
extern void fn_1_155FB4(void *);
extern s32 fn_1_156218(u32, void *, void *, void *);
extern void fn_1_320A4(void);
extern u8* fn_1_36AD0();
extern u8 fn_1_3F114(void);
extern void fn_1_3F2A0(void);
extern s32 fn_1_3F864(void);
extern s32 fn_1_45D0();
extern void fn_1_465D0(char *, int);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32 value);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_4962C(void);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_4B068(s32);
extern f32 fn_1_4B090(s32);
extern void fn_1_4CE48(f32, Obj_1_bss_4B9CC *);
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_508C4(FontDrawPacket *packet, f32 dx, f32 dy);
extern void fn_1_50A90(FontDrawPacket *packet, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_51914(FontDrawPacket *);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern f32 fn_1_520F8(s32),fn_1_521B8(s32);
extern f32 fn_1_521B8(s32 value);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_53830(u32, u32, void *, void *, f32);
extern u32 fn_1_53B14(void *, f32, f32, f32, f32, f32);
extern u32 fn_1_53C9C(void *, u32, f32, f32, f32, f32, f32);
extern void fn_1_55210(void *);
extern void fn_1_556B8(void *value);
extern void fn_1_55FF0();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern u32 fn_1_58C4(void);
extern int fn_1_5910(void);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_7F3AC(void* object);
extern void *fn_1_7F49C(s16,void *,void *);
extern void fn_1_8019C(void *arg0);
extern s8 fn_1_8421C(u32,u32);
extern void *fn_1_8472C(Sig_fn_1_8472C_Fn18472CObject *);
extern int fn_1_8623C(void);
extern void *fn_1_868C0(s8);
extern u32 fn_1_86900(u32);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_A2D84(u32);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_A52B0(u8 value);
extern u32 fn_1_A5D88(void);
extern u32 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern u8 fn_1_B7C00(void);
extern int fn_1_B7E98(int index);
extern int fn_1_C24A4(void);
extern s16 fn_1_C8294(struct fn_1_144254_Bounds *, u8, s32);
extern s32 fn_1_D2D38(void);
extern u8 fn_1_D2D48(void);
extern void *fn_1_D3884(void *arg0);
extern int fn_1_D6698(void);
extern int fn_1_D66B0(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern int fn_1_D6740();
extern void fn_1_F7870(u32);
extern s32 fn_1_F89E4(u8);
extern u8 fn_1_F8CF0(s32);
extern void fn_1_FC414(void *arg0, void *arg1);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void *fn_80008BEC(void *, int, u32);
extern s32 fn_8006FC1C(void *, const char *);
extern void fn_800711A8(void *arg0);
extern void fn_80071718(void *arg0);
extern void fn_80072270(struct Sig_fn_80072270_fn_80072270_Arg0 *);
extern void fn_80072558(void),fn_80074918(u8,s32,u8);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern f64 fn_80074188(u32,u32,u32,u32);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern u8 *lbl_1_bss_25CD0[];
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_38200;
extern u16 lbl_1_bss_50EC[10];
extern u8 lbl_1_bss_5138[260];
extern u8 lbl_1_bss_718E0[];
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern s32 lbl_1_bss_8E3D0[];
extern u32 lbl_1_bss_8E424;
extern u8 lbl_1_bss_9C;
extern u8 lbl_1_data_1A2B4[176];
extern struct fn_1_14267C_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern u8 lbl_1_data_21078[180];
extern Obj_1_bss_4B9CC *lbl_1_data_414D8[120];
extern u8 lbl_1_data_424D0[];
extern u8 lbl_1_data_424E4[];
extern u8 lbl_1_data_424F8[];
extern u8 lbl_1_data_4250C[];
extern u8 lbl_1_data_42520[];
extern u8 lbl_1_data_42534[];
extern u8 lbl_1_data_42548[];
extern u8 lbl_1_data_4255C[];
extern f32 lbl_1_rodata_26F8[22];
extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern u8 lbl_1_rodata_8558[84];
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_85F4;
extern const f32 lbl_1_rodata_85FC;
extern const f64 lbl_1_rodata_8600;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_86C8;
extern Word8 lbl_1_rodata_86D8;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_87B4;
extern const f32 lbl_1_rodata_87D0;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_87F4;
extern const f32 lbl_1_rodata_8818;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8840;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_88B8;
extern const f32 lbl_1_rodata_8960;
extern f32 lbl_1_rodata_8A28;
extern const f32 lbl_1_rodata_8A30;
extern s32 lbl_1_rodata_8A34;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8A58;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8C10;
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern PtrTab lbl_1_rodata_8C4C;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern u16 lbl_1_rodata_8CB0[200];
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern const f32 lbl_1_rodata_8D9C;
extern const f32 lbl_1_rodata_8DBC;
extern const u32 lbl_1_rodata_8DC0;
extern const u32 lbl_1_rodata_8DC4;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_8DD0;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern u32 lbl_1_rodata_8E8C;
extern const f32 lbl_1_rodata_8E9C;
extern u8 lbl_1_rodata_8EB4[];
extern const f32 lbl_1_rodata_9164;
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern const f32 lbl_1_rodata_9208;
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern struct fn_1_141A80_Copy lbl_1_rodata_9248;
extern const f32 lbl_1_rodata_92B8;
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_9B04[300];
extern const f32 lbl_1_rodata_9C30;
extern u8 lbl_1_rodata_9CDC[1200];
extern u8 lbl_1_rodata_A18C[1800];
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern u8 lbl_1_rodata_B884[76];
extern const f64 lbl_1_rodata_B8D0;
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern u8 lbl_1_rodata_CB98[324];
extern u8 lbl_1_rodata_CCDC[308];
extern const f32 lbl_1_rodata_CF40[];
extern f32 lbl_1_rodata_CF70[54];
extern f32 lbl_8006D188(u32);
extern u32 lbl_8006D7F4(f32,f32,f32);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32),lbl_8006E15C(f32,f32,f32);
extern u8 lbl_8015B200[];
extern u32 lbl_801A63C0;
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66A4;
extern u32 lbl_801A66B4;
extern u32 mathutil_mtxA_rotate_z(u32),mathutil_mtxA_rotate_x(u32);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern int sprintf(char *, const char *, ...);
extern char *strcpy(void *, void *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern char *strncpy(char *, const char *, size_t);
extern u8 *strstr(const u8 *str, const u8 *needle);
extern char *strtok(char *string, const char *delimiters);

void fn_1_1420A4(void);
void fn_1_1420E0(void);
void fn_1_1421D8(u32 arg0, u32 arg1, u32 arg2);
void fn_1_1424E8(u32 unused, s32 arg1, u32 arg2);
void fn_1_14267C(u32 arg0, u32 arg1, u32 arg2);
void fn_1_142BDC(u32 arg0, u32 arg1, u32 arg2);
void fn_1_14328C(u32 arg0, u32 arg1, u32 arg2);
void fn_1_143780(u32 arg0, u32 arg1, u32 arg2);
void fn_1_143E7C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, void* arg6);
void fn_1_143F5C(s32 x, s32 y, s32 idx);
void fn_1_144254(s32 arg0, s32 arg1, u32 arg2);
void fn_1_144A5C(const fn_1_144A5C_Args *args);
void fn_1_144E90(void);
void fn_1_144EE8(void);
void fn_1_144F40(s32 mode, u8 *arg1);
BOOL fn_1_145B58(s32 arg0, s32 *arg1);
void fn_1_145C6C(s32 mode, Row_145C6C *row);
void fn_1_1461C8(s32 mode, u32 index);
void fn_1_146550(s32 mode, fn_1_146550_Row *__restrict row);
void fn_1_146B5C(s32 unused, u8 *arg1);
void fn_1_146C88(s32 mode, fn_1_146C88_Obj *__restrict obj);
void fn_1_147188(s32 mode, const fn_1_147188_Row *row);
void fn_1_147508(s32 mode, fn_1_147508_Entry *entry);
void fn_1_147A04(s32 arg0, const fn_1_147A04_Obj *arg1);
void fn_1_148444(s32 mode, fn_1_148444_Obj *obj);
void fn_1_148738(s32 mode, const fn_1_148738_Row *row);
void fn_1_148950(s32 mode, const fn_1_148950_Row *row);
void fn_1_1490FC(s32 mode, fn_1_1490FC_Row *__restrict row);
void fn_1_1492E0(s32 arg0, void *arg1);
void fn_1_1498B8(s32 arg0, f32 arg6, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void fn_1_149B24(const FontDrawPacket *packet, FontVertex *vertices);
void fn_1_149B64(const FontDrawPacket *packet, FontVertex *vertices);
void fn_1_149BF4(const FontDrawPacket *packet, FontVertex *vertices);
void fn_1_149C2C(const FontDrawPacket *packet, FontVertex *vertices);
void fn_1_149C64(const FontDrawPacket *packet, FontVertex *vertices);
void fn_1_149CA4(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
void fn_1_149DA4(void);
void fn_1_149DE8(void);
void fn_1_149E2C(void);
void fn_1_149F04(void);
void fn_1_149F5C(void);
u32 fn_1_149FB4(s32 index);
void fn_1_14A000(void);
void fn_1_14A004(void);
void fn_1_14A008(void);
void fn_1_14A00C(void);
void fn_1_14A028(void);
void fn_1_14A17C(void);
void fn_1_14A1AC(u8 arg);
void fn_1_14A278(void);
void fn_1_14A27C(void);
void fn_1_14A280(void);
void fn_1_14A284(void);
void fn_1_14A328(void);
void fn_1_14A9CC(void);
void fn_1_14A9D0(u8 arg0, s32 arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5);
void fn_1_14AE94(void);
void fn_1_14AED4(void);
void fn_1_14B1B8(void);
void fn_1_14B1BC(void);
void fn_1_14B1FC(void);
void fn_1_14B4FC(void);
void fn_1_14B500(void);
void fn_1_14B62C(void);
void fn_1_14B8F8(void);
void fn_1_14B8FC(void);
void fn_1_14B93C(void);
void fn_1_14BC3C(void);
void fn_1_14BC40(void);
void fn_1_14BCBC(u32 arg0, u32 arg1);
void fn_1_14BD44(void *arg0, void *arg1);
void fn_1_14BD74(void);
void fn_1_14BD94(const u8 *arg0);
u32 fn_1_14BE30(void);
void fn_1_14BED0(void);
void fn_1_14BFB8(void);
void fn_1_14BFD8(s16 port, u8 *sel, s32 arg2);
void fn_1_14C35C(void);
void fn_1_14C6F8(void);
void fn_1_14C7F4(void);
void fn_1_14C7F8(void);
void fn_1_14C864(void);
void fn_1_14C964(void);
void fn_1_14C968(void);
void fn_1_14C9A0(void);
void fn_1_14CA3C(void);
void fn_1_14CA40(void);
void fn_1_14CA44(void);
void fn_1_14CA48(void);
void fn_1_14CA4C(void);
void fn_1_14CAC8(void);
s32 fn_1_14CEB8(u8 *name);

/* The result-row packet templates (retail .rodata 92C0, 9318, 9370): one per display callback. */
static const FontDrawPacket lbl_1_rodata_92C0 = {
    0, 0.0f, 0.0f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0, 0, 1.0f, 0x04000000, 0.0f,
    { 0xFF, 0xFF, 0xFF, 0xFF }, { 0, 0, 0, 0 }, 0, 0, 0, NULL, NULL, fn_1_149BF4, 0
};
static const FontDrawPacket lbl_1_rodata_9318 = {
    0, 0.0f, 0.0f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0, 0, 1.0f, 0x04000000, 0.0f,
    { 0xFF, 0xFF, 0xFF, 0xFF }, { 0, 0, 0, 0 }, 0, 0, 0, NULL, NULL, fn_1_149C2C, 0
};
static const FontDrawPacket lbl_1_rodata_9370 = {
    0, 0.0f, 0.0f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0, 0, 1.0f, 0x04000000, 0.0f,
    { 0xFF, 0xFF, 0xFF, 0xFF }, { 0, 0, 0, 0 }, 0, 0, 0, NULL, NULL, fn_1_149C64, 0
};
/* link state names: a static table of a header that the sel_static_disp translation units include (unread here) */
static char *lbl_1_data_42398[45] = {
    "NON", "MASTER RECV", "MASTER SEND", "SLAVE SEND", "SLAVE RECV", "INIT", "TEST", "TESTEND", "SETUP",
    "SETUP_DONE", "SETUP_COUNTER", "SETUP_CNT_DONE", "UNLINK", "COIN", "ENTRY_WAIT", "CHALLENGER",
    "CHALLENGER_OK", "ENTRY", "ENTRY_OK", "SINGLECHECK", "SINGLECHECK_OK", "COURSE", "COURSE_OK", "COURSE_DATA",
    "COURSE_DATA_OK", "MACHINE", "MACHINE_OK", "CONFIG", "CONFIG_OK", "COUNTERADJUST", "LINKWAIT", "LINKWAITOK",
    "LINKSEL", "LINKDELIVERYSTART", "LINKDELIVERY", "LINKDELIVERYOK", "LINKSELOK", "COURSEVIEW", "COURSEVIEW_OK",
    "LINKREQ", "LINKSTANDBY", "LINKOK", "LINK", "PAUSE", "ERROR"
};
/* Display handlers of the result screens, indexed by lbl_1_bss_8E51D. */
void (*lbl_1_data_4244C[11])(void) = {
    fn_1_1420E0, fn_1_144E90, fn_1_144EE8, fn_1_149E2C, fn_1_149F04, fn_1_149DA4,
    fn_1_149DE8, fn_1_149F5C, fn_1_14A000, fn_1_14A004, fn_1_14A008,
};

u8 *lbl_1_bss_8E428 = NULL;
u32 lbl_1_bss_8E42C = 0;
u32 lbl_1_bss_8E430 = 0;
u32 lbl_1_bss_8E434 = 0;
u32 lbl_1_bss_8E438 = 0;
u32 lbl_1_bss_8E43C = 0;
u32 lbl_1_bss_8E440 = 0;
/* Unknown retail object: .bss 8E444..8E517, no retail function reads it (end of the TU's .bss) */
static u8 lbl_1_bss_8E444[0xD4];

/* fzgx:begin fn_1_1420E0 */
void fn_1_1420E0(void) {
    u32 v;
    u8 flag;
    u8 mask;

    v = fn_1_5910();
    flag = lbl_1_bss_3C30.unk_8;
    mask = (1 << v);
    if (flag < 1 || !(lbl_1_bss_26B1E[0] & mask)) {
        return;
    }
    fn_1_52070(0x140);
    if (fn_1_58C4() == 1) {
        fn_1_1421D8(0x25, 0x31, v);
        fn_1_14267C(0x2c, 0x40, v);
        fn_1_14328C(0xdb, 0x14a, v);
        fn_1_142BDC(0x39, 0x128, v);
        fn_1_1424E8(0x25, 0x31, v);
        fn_1_143780(0xf2, 0x40, v);
        fn_1_143F5C(0xf2, 0x122, v);
        fn_1_144254(0x2c, 0x15a, v);
    }
    fn_1_52088();
}
/* fzgx:end fn_1_1420E0 */

/* fzgx:begin fn_1_1421D8 */
void fn_1_1421D8(u32 arg0, u32 arg1, u32 arg2) {
    u32 v8;
    Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
    f32 v0;
    s32 v3;
    u32 v2;
    f32 v4;
    s32 v7;
    f32 v10;
    f32 v11;
    f32 v15;
    f32 t15;
    f32 t23;
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(0.0f);
    fn_1_495C8((void *)8);
    v0 = 0.9583333134651184f;
    fn_1_4955C(v0, v0);
    fn_1_496FC((s32)arg0, (s32)arg1);
    fn_1_4AE0C("[");
    p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
    v2 = ((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[p_lbl_1_bss_3C30->unk_6]];
    v3 = arg0;
    v3 += 23.0f;
    fn_1_4966C(2.0f, 0.0f);
    v4 = 0.6666666865348816f;
    fn_1_4955C(v4, v4);
    fn_1_496FC(v3, (s32)arg1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4A0D8((const char *)v2);
    t15 = fn_1_4B068(v2);
    v3 += t15;
    v3 += 14;
    v7 = p_lbl_1_bss_3C30->unk_6 * 24;
    v8 = ((u32 (*)[6])lbl_1_data_2BD54)[p_lbl_1_bss_3C30->unk_6][lbl_801A66B4];
    fn_1_494DC(42);
    v10 = 0.0f;
    fn_1_4966C(v10, v10);
    v11 = 0.5833333134651184f;
    fn_1_4955C(v11, v11);
    fn_1_496FC(v3, (s32)arg1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4A0D8((const char *)v8);
    t23 = fn_1_4B068(v8);
    v3 += t23;
    fn_1_494DC(8);
    v15 = 0.9583333134651184f;
    fn_1_4955C(v15, v15);
    fn_1_496FC(v3, (s32)arg1);
    fn_1_4AE0C("]");
    v3 += 23.0f;
    fn_1_13D460(v3, arg1 + 8, 596 - v3, 0);
}
/* fzgx:end fn_1_1421D8 */

/* fzgx:begin fn_1_1424E8 */
void fn_1_1424E8(u32 unused, s32 arg1, u32 arg2) {
    FontDrawPacket loc_8;
    s32 mode;

    if (lbl_1_bss_3C30.unk_0 & 0x04000000) {
        mode = 7;
    } else {
        switch (lbl_1_bss_3C30.unk_5) {
        case 1:
            switch (lbl_1_bss_3C30.unk_A6) {
            case 1: mode = 0; break;
            case 2: mode = 1; break;
            case 3: mode = 2; break;
            case 4: mode = 3; break;
            case 5: mode = 4; break;
            default: mode = 0; break;
            }
            break;
        case 0:
        case 6:
            mode = 5;
            break;
        case 2:
            mode = 6;
            break;
        default:
            mode = 7;
            break;
        }
    }

    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = 0x9901;
    fn_1_51564(0, 0, 0xA0, 0x10, 1, 8);
    fn_1_5158C(&loc_8, loc_8.image, 0, mode);
    loc_8.x = 596.0f;
    loc_8.y = (arg1 - 8);
    loc_8.flags = 7;
    fn_1_4F734(&loc_8);
}

/* Unknown retail object: unread literal, likely from stripped code (.rodata 93F4) */
static const f32 lbl_1_rodata_93F4[1] = { 528.0f };
/* fzgx:end fn_1_1424E8 */

/* fzgx:begin fn_1_14267C */
#define lbl_1_rodata_26F8 (*(const FontDrawPacket *)&lbl_1_rodata_26F8)

/* WARNING: compiler-diff device, not original code (carried from main) */
#pragma opt_common_subs off

void fn_1_14267C(u32 arg0, u32 arg1, u32 arg2) {
 u32 v2;
 s32 v3;
 s32 v5;
 s16 t3;
 u32 v8;
 s8 t24;
 u8 *t19;
 struct fn_1_14267C_lbl_1_data_1E5C0 *q;
 FontDrawPacket packet;
 Sig_fn_1_144A5C_fn_1_143F5C_Args loc_114;
 Sig_fn_80015EE8_Fn80015EE8Out loc_D4;
 struct fn_1_14267C_lbl_1_data_1E5C0 loc_A0;
 u32 loc_1C[4] = {26, 35, 156, 165};
 u32 loc_88[6] = {24, 33, 133, 142, 242, 251};
 char loc_68[32],loc_48[32];
 struct Sig_fn_80072270_fn_80072270_Arg0 loc_2C;
 u32 loc_18,loc_14,loc_10,loc_C;
 s32 level;
 loc_114.x=arg0; loc_114.y=arg1; loc_114.w0=192; loc_114.h0=278; loc_114.w1=180; loc_114.h1=270;
 loc_114.list0=loc_1C; loc_114.count0=4; loc_114.list1=loc_88; loc_114.count1=6;
 fn_1_144A5C((void *)&loc_114);
 v2=fn_1_86900((s8)arg2);
 if (!v2) {
  for(v3=0;v3<4;v3++) { v2=fn_1_86900((s8)v3); if(v2) break; }
  if(!v2) return;
 }
 v5=*(s8 *)(v2+0x328);
 t3=fn_1_12C930(v5);
 fn_1_49410(); fn_1_494DC(4); fn_1_4962C();
 fn_1_4966C(-4.0f,0.0f);
 {
  Color_144F40 loc_8 = {0xC0, 0xC0, 0xC0, 0x00};
  fn_1_49514((u32 *)&loc_8);
 }
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+16));
 fn_1_4954C(40.0f);
 fn_1_4AE0C("NAME:");
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+32));
 v8=t3<<2;
 fn_1_4A0D8((char *)*(u32 *)((u8 *)&lbl_1_data_212A8.unk_0+v8));
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+54));
 fn_1_4AE0C("MACHINE");
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+70));
 fn_1_4962C();
 if(v5>40) {
  fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812));
  if(v2) {
   t19=fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812));
   if(t19) fn_1_4A0D8(fn_1_14FEAC((void *)t19[0x81A4],(void *)t19[0x81AC],(void *)t19[0x81B4],loc_48,0));
  }
 } else fn_1_4A0D8(fn_1_7F49C(v5,0,loc_68));
 if(v2) {
  t24=fn_1_8421C(v2,0);
  GXGetProjectionv((f32 *)&loc_2C);
  GXGetScissor(&loc_18,&loc_14,&loc_10,&loc_C);
  C_MTXOrtho((void *)&loc_D4,0.0f,480.0f,0.0f,640.0f,0.0f,90000.0f);
  fn_800737E4((void *)&loc_D4,1);
  q=&lbl_1_data_1E5C0;
  loc_A0=*q;
  *(f32 *)&loc_A0.unk_C=0.3f;
  *(f32 *)&loc_A0.unk_10=0.7f;
  *(f32 *)&loc_A0.unk_14=-1.0f;
  fn_1_F7870((u32)&loc_A0);
  fn_1_149CA4(48,69,180,270);
  lbl_8006D7F4(fn_1_520F8(138),208.0f,-1000.0f);
  lbl_8006E14C(-50.0f);
  { f32 t34=fn_1_521B8(1); lbl_8006E15C(t34,1.0f,1.0f); }
  mathutil_mtxA_rotate_z(32768); mathutil_mtxA_rotate_x(-16384);
  fn_80072558(); fn_80074918(1,3,0);
  fn_1_151BDC(fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812)));
  fn_1_870BC((void *)v2,t24,(void *)v2,0,*(s16 *)(v2+952),1.0f);
  fn_80074188(loc_18,loc_14,loc_10,loc_C);
  fn_80072270(&loc_2C);
 }
 { s16 rawLevel = *(s16 *)(v2+952);
 if(rawLevel<0) level=0; else { level=3; if(rawLevel<=3) level=rawLevel; }
 }
 packet=lbl_1_rodata_26F8;
 packet.image=(s16)level|(*(u32 *)(lbl_1_data_1A2B4+v8)<<8);
 packet.x=(f32)(s32)(arg0+96);
 packet.y=(f32)(s32)(arg1+11);
 packet.z=10.0f;
 packet.alpha=1.0f;
 packet.flags=6;
 fn_1_4F734(&packet);
}
#undef lbl_1_rodata_26F8
#pragma opt_common_subs reset
/* fzgx:end fn_1_14267C */

/* fzgx:begin fn_1_142BDC */
#define lbl_1_bss_3C30 (*(struct fn_1_142BDC_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)
#define lbl_1_rodata_26F8 (*(u32 *)&lbl_1_rodata_26F8)
void fn_1_142BDC(u32 arg0, u32 arg1, u32 arg2) {
    struct fn_1_142BDC_lbl_1_rodata_92C0 *p_lbl_1_rodata_92C0;
    u32 v0;
    f32 v1;
    u32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    u32 v6 = arg0;
    u32 arg0_local = arg0;
    s32 v7;
    s32 v9;
    s32 v13;
    s32 v12;
    s32 v15;
    u32 v18;
    u32 v23;
    f32 v25;
    u32 v36;
    f32 v40;
    f32 v41;
    FontDrawPacket loc_18;
    struct { u32 a[4]; } loc_8;
    /* frame */
    s32 t0;
    f32 t27;

    p_lbl_1_rodata_92C0 = (struct fn_1_142BDC_lbl_1_rodata_92C0 *)&lbl_1_rodata_92C0;
    t0 = fn_1_149FB4(arg2);
    if (t0 != -1) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            if (t0 == 0) {
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v0 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v0;
                fn_1_51678(&loc_18, v0, 0, 0, 116, 32);
                v1 = (140.0f);
                loc_18.x = v1;
                loc_18.y = (224.0f);
                fn_1_4F734((void *)&loc_18);
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v2 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v2;
                fn_1_51678(&loc_18, v2, 0, 32, 160, 32);
                v3 = (140.0f);
                loc_18.x = v3;
                loc_18.y = (254.0f);
                fn_1_4F734((void *)&loc_18);
            } else {
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v4 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v4;
                fn_1_51678(&loc_18, v4, 0, 64, 160, 32);
                v5 = (140.0f);
                loc_18.x = v5;
                loc_18.y = (256.0f);
                fn_1_4F734((void *)&loc_18);
            }
            v6 = arg0_local + 70;
            v7 = arg1 - 3;
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_495C8((void *)2);
            fn_1_496FC((s32)v6, v7);
            sprintf((char *)&loc_8, "%d", (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            v9 = t0 + 1;
            v13 = 0;
            v12 = v9 % 100;
            if (v12 >= 10 && v9 % 100 <= 20) {
                v13 = 1;
            }
            if (v13 != 0) {
                v15 = 3;
            } else {
                v13 = 0;
                if ((v12 % 10) >= 4 || (v12 % 10) == 0) {
                    v13 = 1;
                }
                if (v13 != 0) {
                    v15 = 3;
                } else {
                    v2 = (v12 % 10) - 1;
                    v15 = v2;
                }
            }
            v18 = (v15 & 0xFF);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_18.image = 0x9705;
            fn_1_51564(0, 0, 24, 24, 2, 2);
            v40 = (s32)(v6 - 4);
            v41 = (v7 + 8);
            loc_18.x = v40;
            loc_18.y = v41;
            loc_18.z = (5.0f);
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       ((s32)v18 % 2),
                       ((v18 >> 1) & 0x7F));
            fn_1_4F734((void *)((FontDrawPacket *)&loc_18));
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v23 = 0x9730;
            loc_18.image = v23;
            fn_1_51678((FontDrawPacket *)&loc_18, v23, 116, 0, 44, 32);
            v25 = (s32)(v6 + 26);
            loc_18.x = v25;
            loc_18.y = (v7 + 6);
            fn_1_4F734((void *)((FontDrawPacket *)&loc_18));
        } else {
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_496FC((s32)arg0_local, (s32)arg1);
            sprintf((char *)&loc_8, "%d", (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            t27 = fn_1_4B068((s32)&loc_8);
            v9 = t0 + 1;
            v12 = v9 % 100;
            v13 = 0;
            if (v12 >= 10 && v9 % 100 <= 20) {
                v13 = 1;
            }
            if (v13 != 0) {
                v15 = 3;
            } else {
                v13 = 0;
                if ((v12 % 10) >= 4 || (v12 % 10) == 0) {
                    v13 = 1;
                }
                if (v13 != 0) {
                    v15 = 3;
                } else {
                    v15 = (v12 % 10) - 1;
                }
            }
            v36 = (v15 & 0xFF);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_18.image = 0x9705;
            fn_1_51564(0, 0, 24, 24, 2, 2);
            loc_18.x = (s32)v6 + t27 - 4.0f;
            loc_18.y = (s32)(arg1 + 7);
            loc_18.z = 5.0f;
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       ((s32)v36 % 2),
                       ((v36 >> 1) & 0x7F));
            fn_1_4F734((void *)((FontDrawPacket *)&loc_18));
        }
    }
}
#undef lbl_1_bss_3C30
#undef lbl_1_rodata_26F8
/* fzgx:end fn_1_142BDC */

/* fzgx:begin fn_1_14328C */
void fn_1_14328C(u32 arg0, u32 arg1, u32 arg2) {
    s32 v0;
    s32 v5;
    s32 j;
    s32 i;
    s32 v6;
    struct fn_1_14328C_Copy88 packet;
    f32 size;
    size = 12.0f;
    v0 = lbl_1_bss_26B04[arg2];
    v6 = v0 % 10;
    v5 = v0 / 10;
    packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
    *(f32 *)&packet.a[2] = (f32)(s32)arg1;
    if (v6 >= 6) {
        for (i = 6; i <= v6; i++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9713;
            *(f32 *)&packet.a[1] = (f32)(s32)arg0 - (f32)((i - 1) % 5) * size;
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= size / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= size / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        arg1 = (s32)((s32)arg1 - 15.0f);
    }
    if (v6 >= 1) {
        for (j = 1; j <= v6; j++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9713;
            *(f32 *)&packet.a[1] = (f32)(s32)arg0 - (f32)((j - 1) % 5) * size;
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= size / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= size / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        arg1 = (s32)((s32)arg1 - 15.0f);
    }
    if (v5 >= 1) {
        for (i = 0; i < v5; i++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9712;
            *(f32 *)&packet.a[1] = (f32)((s32)arg0 - i * 12);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= size / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= size / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
    }
}
/* fzgx:end fn_1_14328C */

/* fzgx:begin fn_1_143780 */
/* Placeholder whose retail body is unknown: .rodata 9488..94A7 ("NO NAME", "NO DATA", 100.0f, 350.0f, 44.0f, 8.0f) and
   .data 4248C/42494 ("NAME", "PILOT RANK") are read by no retail code and sits between fn_1_14328C's and fn_1_143780's literals, so it is the pool of a static
   function the REL link strips (strip_allow.txt). Its later users (fn_1_144254, fn_1_148738, fn_1_1490FC) share 100.0f,
   44.0f and 8.0f with it. Only its literals and their order are known. */
static void draw_no_entry_placeholder(void) {
    char name[8] = "NO NAME";
    char data[8] = "NO DATA";

    fn_1_49410();
    fn_1_496FC(100.0f, 350.0f);
    fn_1_4A0D8(name);
    fn_1_496FC(44.0f, 8.0f);
    fn_1_4A0D8(data);
    fn_1_4A0D8("NAME");
    fn_1_4A0D8("PILOT RANK");
}

static inline void draw_color(u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,Color color) {
    fn_1_143E7C(a,b,c,d,e,f,&color);
}

static inline void set_color(Color color) {
    fn_1_49514((void *)((u32 *)&color));
}

/* WARNING: compiler-diff device, not original code (carried from main) */
#pragma opt_loop_invariants off

void fn_1_143780(u32 arg0, u32 arg1, u32 arg2) {
    u32 count;
    u32 y1;
    u32 y0;
    s32 last;
    struct fn_1_143780_entry *cur;
    s32 i;
    Obj_1_bss_26314 *obj;
    struct fn_1_143780_entry *e;
    u32 image;
    f32 scale;
    s32 frame;
    s32 rem;
    u32 a0, b0, a1, b1, a2, b2;
    f32 one;
    f32 t;
    Color loc_40;
    Color loc_3C;
    Color loc_38;
    Color loc_34;
    Color loc_30;
    Color loc_2C;
    Color loc_28;
    Color loc_24;
    Color loc_10;
    Color loc_C;
    Color loc_8;
    struct { u32 a[10]; } loc_6C;
    FontDrawPacket loc_94;
    loc_10 = (Color){{255,255,255,255}};
    loc_40 = loc_2C = loc_10;
    loc_C = (Color){{0,240,230,255}};
    loc_3C = loc_28 = loc_C;
    loc_38 = (Color){{0,120,115,255}};
    loc_8 = (Color){{160,255,0,255}};
    loc_34 = loc_24 = loc_8;
    {
    struct { u32 a[4]; } loc_44 = {{26, 35, 316, 325}};
    struct { u32 a[6]; } loc_54 = {{24, 33, 101, 110, 178, 187}};
    loc_6C.a[0] = arg0;
    loc_6C.a[1] = arg1;
    loc_6C.a[2] = 354;
    loc_6C.a[3] = 222;
    loc_6C.a[4] = 340;
    loc_6C.a[5] = 208;
    loc_6C.a[6] = (u32)&loc_44;
    loc_6C.a[7] = 4;
    loc_6C.a[8] = (u32)&loc_54;
    loc_6C.a[9] = 6;
    fn_1_144A5C((void *)&loc_6C);
    loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    image = 0x9903;
    loc_94.image = image;
    fn_1_51678(&loc_94, image, 0, 108, 96, 36);
    loc_94.x = (s32)(arg0 + 22);
    loc_94.y = (s32)(arg1 + 179);
    loc_94.z = 30.0f;
    loc_94.scale_x *= 0.75f;
    loc_94.scale_y *= 0.75f;
    fn_1_4F734(&loc_94);
    obj = (Obj_1_bss_26314 *)((u8 *)&lbl_1_bss_26314 + arg2 * 508);
    count = fn_1_3F114() & 0xFF;
    if (count <= 5) {
        y1 = arg1 + 18;
        y0 = arg1 + 16;
        last = count - 1;
        for (i = 0; i < (s32)count; i++) {
            if (i < 5) {
                e = &((struct fn_1_143780_view *)obj)->entries[last - i];
                if (e->unk_0 == obj->unk_1CC && e->unk_4 == obj->unk_1D0) {
                    loc_30 = loc_34;
                } else {
                    loc_30 = loc_40;
                }
                draw_color(arg0 + 332, y1, arg2, e->unk_8, e->unk_9, e->unk_A, loc_30);
                loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
                image = 0x9903;
                loc_94.image = image;
                fn_1_51678(&loc_94, image, 0, 36, 96, 36);
                loc_94.x = ((s32)arg0 + 22);
                loc_94.y = (s32)y0;
                loc_94.z = 30.0f;
                loc_94.scale_x *= 0.75f;
                loc_94.scale_y *= 0.75f;
                *(Color *)loc_94.color = loc_30;
                fn_1_4F734(&loc_94);
                fn_1_49410();
                fn_1_494DC(19);
                fn_1_496FC((s32)(arg0 + 80), (s32)y1);
                set_color(loc_30);
                scale = 0.75f;
                fn_1_4955C(scale, scale);
                fn_1_4AE0C("%1d", i + 1);
            }
            y1 += 32;
            y0 += 32;
        }
    } else {
        cur = &((struct fn_1_143780_view *)obj)->entries[8];
        loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
        image = 0x9900;
        loc_94.image = image;
        loc_94.x = ((s32)arg0 + 22);
        loc_94.y = ((s32)arg1 + 7);
        loc_94.z = 30.0f;
        fn_1_4F734(&loc_94);
        draw_color(arg0 + 332, arg1 + 18, arg2, cur->unk_8, cur->unk_9, cur->unk_A, loc_24);
    }
    e = (struct fn_1_143780_entry *)((u32)obj + 0x1d8);
    draw_color(arg0 + 332, arg1 + 179, arg2, e->unk_8, e->unk_9, e->unk_A, loc_2C);
    loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_94.image = 18;
    loc_94.x = ((s32)arg0 + 1);
    loc_94.y = ((s32)arg1 + 176);
    loc_94.z = 54.0f;
    *(Color *)loc_94.color = loc_28;
    loc_94.scale_x *= 343.0f / fn_1_48690(18);
    loc_94.scale_y *= 30.0f / fn_1_486C4(loc_94.image);
    frame = ((struct fn_1_143780_lbl_801A66A4 *)&lbl_801A66A4)->unk_0;
    scale = 65536.0f;
    rem = frame % 120;
    scale = (f32)(scale * rem);
    one = 1.0f;
    t = (one + lbl_8006D188((s32)(scale / 120.0f))) / 2.0f;
    loc_94.color[0] = (loc_3C.c[0] * (one - t)) + (loc_38.c[0] * t);
    loc_94.color[1] = (loc_3C.c[1] * (one - t)) + (loc_38.c[1] * t);
    loc_94.color[2] = (loc_3C.c[2] * (one - t)) + (loc_38.c[2] * t);
    loc_94.alpha = 0.35f;
    fn_1_4F734(&loc_94);
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_143780 */

/* fzgx:begin fn_1_143E7C */
/* Placeholders whose retail bodies are unknown: .rodata 94FC..95A7 is read by no retail code except 20.0f (9568, later
   read by fn_1_145C6C/fn_1_147A04) and 0.8f (95A4, later read by fn_1_148950/fn_1_1492E0), nor .data 424A4 ("%-2d"). It sits between
   fn_1_143780's and fn_1_143E7C's literals, so it is the pool of two static functions the REL link strips
   (strip_allow.txt), panel variants of fn_1_143780/fn_1_143F5C (same colour words and frame lists). Only their local
   initializers, literals and their order are known. */
static void panel_placeholder_a(u32 *out) {
    u8 colors[6][4] = {
        { 0xFF, 0xFF, 0xFF, 0xFF }, { 0x00, 0xF0, 0xE6, 0xFF }, { 0x00, 0x78, 0x73, 0xFF },
        { 0xFF, 0xFF, 0x00, 0xFF }, { 0xFF, 0xFF, 0x00, 0xFF }, { 0x80, 0x80, 0xFF, 0xFF },
    };
    u32 list0[4] = { 26, 35, 316, 325 };
    u32 list1[6] = { 24, 33, 101, 110, 178, 187 };
    u32 shadow[9] = { 0x19FF1900, 0x19FF1900 };

    fn_1_49514((u32 *)colors);
    fn_1_49514(list0);
    fn_1_49514(list1);
    fn_1_49514(shadow);
    fn_1_496FC((f32)(*out * 255.0), 20.0f);
}

static void panel_placeholder_b(void) {
    u32 list0[4] = { 26, 35, 316, 325 };
    u8 color0[4] = { 0xFF, 0xFF, 0xFF, 0x00 };
    u8 shadow0[4] = { 0x19, 0xFF, 0x19, 0x00 };
    u32 list1[4] = { 26, 35, 316, 325 };
    u32 colors[4] = { 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00 };

    fn_1_49514(list0);
    fn_1_49514((u32 *)color0);
    fn_1_49514((u32 *)shadow0);
    fn_1_49514(list1);
    fn_1_49514(colors);
    fn_1_49590(0.8f);
    fn_1_4AE0C("%-2d", 0);
}

void fn_1_143E7C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, void* arg6) {
    u32 local;
    f32 value;

    fn_1_49410();
    fn_1_494DC(0x13);
    fn_1_495B0((u32)0x8000 << 16);
    fn_1_495C8((void *)2);
    local = *(u32*)arg6;
    fn_1_49514((void *)&local);
    fn_1_4966C(-2.0f, 0.0f);
    value = 0.75f;
    fn_1_4955C(value, value);
    fn_1_496FC((s32)arg0, (s32)arg1);
    fn_1_4AE0C("%02d<%02d=%03d", arg3 & 0xFF, arg4 & 0xFF, arg5 & 0xFFFF);
}
/* fzgx:end fn_1_143E7C */

/* fzgx:begin fn_1_143F5C */
/* Placeholder whose retail body is unknown: .data 424BC ("%02d;%02d<%03d") is read by no retail code and sits between
   fn_1_143E7C's and fn_1_143F5C's literals, so it belongs to a static function the REL link strips (strip_allow.txt),
   a twin of fn_1_143E7C with the other time separators (its other literals are fn_1_143E7C's). */
static void draw_time_placeholder(u32 x, u32 y, u32 min, u32 sec, u32 msec) {
    fn_1_496FC((s32)x, (s32)y);
    fn_1_4AE0C("%02d;%02d<%03d", min & 0xFF, sec & 0xFF, msec & 0xFFFF);
}

#define lbl_1_rodata_26F8 (*(FontDrawPacket *)&lbl_1_rodata_26F8)
void fn_1_143F5C(s32 x, s32 y, s32 idx) {
    u8 color[4];
    u32 colorCopy;
    u32 list0[4] = {0x1a, 0x23, 0x13c, 0x145};
    u32 list1[2] = {0x18, 0x21};
    fn_1_143F5C_Args args;
    FontDrawPacket packet;

    args.x = x;
    args.y = y;
    args.w0 = 0x162;
    args.h0 = 0x34;
    args.w1 = 0x154;
    args.h1 = 0x2a;
    args.list0 = list0;
    args.count0 = 4;
    args.list1 = list1;
    args.count1 = 2;
    fn_1_144A5C((void *)&args);

    color[0] = 0xa0;
    color[1] = 0xff;
    color[2] = 0;
    color[3] = 0xff;

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9903;
    fn_1_51678(&packet, 0x9903, 0, 0x90, 0x60, 0x24);
    packet.x = (x + 0x1a);
    packet.y = (y + 0xe);
    packet.z = 30.0f;
    packet.scale_x *= 0.75f;
    packet.scale_y *= 0.75f;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(0x13);
    fn_1_495B0(0x80000000);
    fn_1_495C8((void *)2);
    fn_1_496FC((x + 0x14c - fn_1_48690(0x9904)), (y + 0x10));
    colorCopy = *(u32 *)color;
    fn_1_49514((void *)&colorCopy);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4AE0C("%4d", (s32)lbl_1_bss_26304[idx]);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9904;
    packet.x = (x + 0x14c);
    packet.y = (y + 0x17);
    packet.z = 30.0f;
    packet.flags = 7;
    packet.scale_x *= 0.75f;
    packet.scale_y *= 0.75f;
    fn_1_4F734(&packet);
}
#undef lbl_1_rodata_26F8
/* fzgx:end fn_1_143F5C */

/* fzgx:begin fn_1_144254 */
/* Unknown retail objects: .rodata 95C4..95FB, no retail function reads them (between fn_1_143F5C's and fn_1_144254's
   initializers; the frame lists and colours of a stripped fn_1_143F5C variant) */
static const u32 lbl_1_rodata_95C4[4] = { 26, 35, 316, 325 };
static const u32 lbl_1_rodata_95D4[2] = { 24, 33 };
static const u8 lbl_1_rodata_95DC[4] = { 0xFF, 0xFF, 0x00, 0xFF };
static const u8 lbl_1_rodata_95E0[4] = { 0x19, 0xFF, 0x19, 0x00 };
static const u32 lbl_1_rodata_95E4[1] = { 0 };
static const u32 lbl_1_rodata_95E8[4] = { 26, 35, 316, 325 };
static const u8 lbl_1_rodata_95F8[4] = { 0x19, 0xFF, 0x19, 0x00 };

void fn_1_144254(s32 arg0, s32 arg1, u32 arg2) {
    struct fn_1_144254_Copy88 loc_84;
    struct fn_1_144254_Bounds loc_3C[6];
    u8 loc_28[17];
    s32 v9;
    u8 v14;
    f32 v26, v24;
    void *v10;
    const char *v27;
    s16 v29;
    u8 v31;
    s32 v34, v35;
    s32 v48, v52;

    if (lbl_1_bss_3C30.unk_5 == 1 || lbl_1_bss_3C30.unk_5 == 6) {
    if (lbl_1_bss_3C30.unk_9 > 1) {
    loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
    loc_84.a[0] = fn_1_D2D38() ? 0x9707 : 0x9706;
    *(f32 *)((u8 *)&loc_84 + 4) = (f32)arg0;
    *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 2);
    *(f32 *)((u8 *)&loc_84 + 12) = 5.0f;
    fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
    fn_1_13D460(arg0, arg1 + 18, 596 - arg0, 0);
    v14 = fn_1_D2D48();
    for (v9 = 0; v9 < v14; v9++) {
        loc_3C[v9].x = arg0 + 22 + v9 * 88;
        loc_3C[v9].y = arg1 + 30;
        loc_3C[v9].width = 68.0f;
        loc_3C[v9].x2 = arg0 + 22 + v9 * 88;
        loc_3C[v9].y2 = arg1 + 26;
        if (fn_1_D2D38() != 0) {
            const char *loc_18[4] = { "\203A\203C\203\213\203g\203\223\201@\203Z\203i", "\202`\201D\203`\203F\203U\203\212\203X\201@", "\203l\203\213\203\\\203\223\201@\203s\203P\201@", "\203A\203\211\203\223\201@\203v\203\215\203X\203g" };
            const char *loc_8[4] = { "\203}\203X\203^\201[\203\211\203C\203Z\203\223\203X", "\202R\202Q\213\211\203\211\203C\203Z\203\223\203X", "\203p\203C\203\215\203b\203g\214\363\225\342\220\266", "\202r\202r\213\211\203\211\203C\203Z\203\223\203X" };
            v10 = loc_28;
            v26 = loc_3C[v9].x + loc_3C[v9].width / 2.0f;
            v24 = 10.0f + (loc_3C[v9].y + loc_3C[v9].width / 2.0f);
            fn_80008BEC(v10, 0, 17);
            strncpy(v10, loc_18[v9], 16);
            v27 = loc_8[v9];
            loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
            loc_84.a[0] = 12;
            loc_84.a[12] = 6;
            *(f32 *)((u8 *)&loc_84 + 4) = v26;
            *(f32 *)((u8 *)&loc_84 + 8) = 10.0f + v24;
            *(f32 *)((u8 *)&loc_84 + 12) = 1.0f;
            loc_84.a[12] = 6;
            fn_1_50164(86.0f, 30.0f,
                8.0f, 8.0f, &loc_84);
            if (loc_28[0] != 0) {
                fn_1_49410();
                fn_1_496FC(v26, 15.0f + v24);
                fn_1_495C8((void *)1);
                fn_1_4955C(0.375f, 0.375f);
                fn_1_4965C(2);
                fn_1_495B0(0x40000000);
                fn_1_49590(0.5f);
                fn_1_4CE48(80.0f, (Obj_1_bss_4B9CC *)v10);
                fn_1_49410();
                fn_1_496FC(v26, 12.0f + (14.0f + v24));
                fn_1_495C8((void *)1);
                fn_1_4955C(0.375f, 0.375f);
                fn_1_4965C(2);
                fn_1_49590(0.5f);
                fn_1_495B0((3U << 30));
                fn_1_4CE48(80.0f, (Obj_1_bss_4B9CC *)v27);
            } else {
                fn_1_49410();
                fn_1_496FC(v26, 21.0f + v24);
                fn_1_495C8((void *)1);
                fn_1_4955C(0.375f, 0.375f);
                fn_1_4965C(2);
                fn_1_49590(0.5f);
                fn_1_495B0((3U << 30));
                fn_1_4A0D8("NO DATA");
            }
        }
    }
    v29 = fn_1_C8294(loc_3C, v14, 0);
    v31 = fn_1_D2D38() ? 4 : 6;
    v9 = (u8)v14;
    if ((u32)v9 < v31) {
    for (; v9 < v31; v9++) {
            loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
            loc_84.a[0] = 0x9735;
            *(f32 *)((u8 *)&loc_84 + 4) = (f32)(arg0 + 22 + v9 * 88);
            *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 30);
            *(f32 *)((u8 *)&loc_84 + 12) = 10.0f;
            fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
            loc_84.a[0] = 0x9714;
            *(f32 *)((u8 *)&loc_84 + 4) = (f32)(arg0 + 18 + v9 * 88);
            *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 26);
            *(f32 *)((u8 *)&loc_84 + 12) = 2.0f;
            fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
    }
    }
    loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
    loc_84.a[0] = 0x9726;
    fn_1_51678((FontDrawPacket *)&loc_84, loc_84.a[0], 0, 0, 22, fn_1_486C4(loc_84.a[0]));
    *(f32 *)((u8 *)&loc_84 + 4) = 44.0f;
    *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
    *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
    loc_84.a[12] = 9;
    fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
    v48 = fn_1_D2D38() ? 3 : 5;
    for (v9 = 0; v9 < v48; v9++) {
        loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
        loc_84.a[0] = 0x9709;
        fn_1_51678((FontDrawPacket *)&loc_84, loc_84.a[0], 0, 0, 20, fn_1_486C4(loc_84.a[0]));
        *(f32 *)((u8 *)&loc_84 + 4) = (f32)(144 + v9 * 88);
        *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
        *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
        *(f32 *)((u8 *)&loc_84 + 16) *= 1.1f;
        loc_84.a[12] = 10;
        fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
    }
    loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
    loc_84.a[0] = 0x9726;
    fn_1_51678((FontDrawPacket *)&loc_84, loc_84.a[0], 110, 0, 22, fn_1_486C4(loc_84.a[0]));
    if (fn_1_D2D38() != 0)
        *(f32 *)((u8 *)&loc_84 + 4) = 399.0f;
    else
        *(f32 *)((u8 *)&loc_84 + 4) = 574.0f;
    *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
    *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
    loc_84.a[12] = 9;
    fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
    if (fn_1_D2D38() != 0) {
        loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
        if (v29 == 0) {
            loc_84.a[0] = 0x980A;
            fn_1_53830(60, 50, (u8 *)&loc_84 + 0x3C, (u8 *)&loc_84 + 0x38, 0.85f);
        } else {
            loc_84.a[0] = 0x9808;
        }
        *(f32 *)((u8 *)&loc_84 + 4) = 510.0f;
        *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
        *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
        loc_84.a[12] = 10;
        fn_1_4F734((void *)((FontDrawPacket *)&loc_84));
    }
    }
    }
}
/* fzgx:end fn_1_144254 */

/* fzgx:begin fn_1_144A5C */
/* Unknown retail objects: .rodata 9648..96C7, no retail function reads them (between fn_1_144254's and fn_1_144A5C's
   literals: the shadow and frame colours and the positions of a stripped panel function) */
static const u8 lbl_1_rodata_9648[27][4] = {
    { 0x19, 0xFF, 0x19, 0x00 }, { 0x19, 0xFF, 0x19, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xFF, 0xFF, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 }, { 0xFF, 0xFF, 0xFF, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xFF, 0xFF, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 }, { 0xFF, 0xFF, 0xFF, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xFF, 0xFF, 0x00, 0xFF }, { 0x00, 0x00, 0x00, 0x00 },
    { 0x19, 0xFF, 0x19, 0x00 }, { 0x19, 0xFF, 0x19, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0x80, 0x80, 0xFF, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 }, { 0xFF, 0xFF, 0xFF, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0xF4, 0x96, 0x28, 0x00 }, { 0x80, 0x80, 0xFF, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 }, { 0xFF, 0xFF, 0xFF, 0x00 },
};
static const f32 lbl_1_rodata_96B4[5] = { 354.0f, 84.0f, 22.0f, 0.65f, 192.0f };

void fn_1_144A5C(const fn_1_144A5C_Args *args) {
    FontDrawPacket packet;

    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x970C;
    packet.x = args->x;
    packet.y = args->y;
    packet.z = 48.0f;
    fn_1_50A90(&packet, 0x28, 0x10, args->w0, args->h0);
    if (args->h0 > 0x38) {
        packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x970F;
        packet.z = 46.0f;
        packet.flags = 10;
        packet.x = (args->x + 5);
        packet.y = (args->y + 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + 5);
        packet.y = (args->y + args->h0 - 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + 5);
        packet.y = (args->y + args->h0 / 2);
        fn_1_4F734(&packet);
        packet.x = (args->x + args->w0 - 5);
        packet.y = (args->y + 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + args->w0 - 5);
        packet.y = (args->y + args->h0 - 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + args->w0 - 5);
        packet.y = (args->y + args->h0 / 2);
        fn_1_4F734(&packet);
    }
    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x970D;
    packet.x = (args->x + (args->w0 - args->w1) / 2);
    packet.y = (args->y + (args->h0 - args->h1) / 2);
    packet.z = 55.0f;
    fn_1_508C4(&packet, args->w1, args->h1);
}
/* fzgx:end fn_1_144A5C */

/* fzgx:begin fn_1_144E90 */
void fn_1_144E90(void) {
    lbl_1_bss_8E428 = (u8 *)&lbl_1_bss_3C30 + 0xE;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(0, (void *)0);
    }
}
/* fzgx:end fn_1_144E90 */

/* fzgx:begin fn_1_144EE8 */
void fn_1_144EE8(void) {
    lbl_1_bss_8E428 = (u8 *)&lbl_1_bss_3C30 + 0x1394;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(1, (void *)0);
    }
}
/* fzgx:end fn_1_144EE8 */

/* fzgx:begin fn_1_144F40 */
#define lbl_1_bss_3C30 (*(Setup *)&lbl_1_bss_3C30)
#define lbl_1_bss_8EF68 ((Entry *)&lbl_1_bss_8EF68)
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)
#define lbl_1_rodata_26F8 (*(const FontDrawPacket *)&lbl_1_rodata_26F8)
/* one results row: the layout fn_1_145C6C .. fn_1_1498B8 read */

/* one 0x38-byte entry of lbl_1_bss_8EF68 */

/* one seat's 0xA0-byte result record at lbl_1_bss_3C30+0xD4 */

/* the viewport block: separate TU statics at the start of .bss (dtk splits at 8E43C/8E440): the
 * order table, then two horizontal spans and one vertical */

/* retail .rodata (lbl_1_rodata_92C0) up to this function's own constants at 0x414 */

static inline BOOL in_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}

static inline BOOL in_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5(mode) && mode != 9) r = FALSE;
    return r;
}

static inline BOOL in_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL in_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

static inline BOOL in_8_9(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}

static inline BOOL in_8_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_8_9(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL in_0_1(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) r = FALSE;
    return r;
}

static inline BOOL in_0_2_7_8(s32 mode) {
    BOOL r = FALSE;
    if (mode == 0 || mode == 2 || mode == 8 || mode == 7) r = TRUE;
    return r;
}

static inline BOOL in_range(const Row *row, s32 hi) {
    return row->unk_20 > hi ? FALSE : row->unk_20 >= 0;
}

#define MIN(a, b) ((a) > (b) ? (b) : (a))

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : (x) > (hi) ? (hi) : (x))

#define CLIP(pos, size, x, w, max) \
    pos = MIN(x, max); \
    size = (MIN((pos + w), max) - pos)

static inline BOOL in_any(s32 mode) {
    BOOL r = TRUE;
    if (!in_0_2_7_8(mode) && !in_4_5_6_9_10(mode)) r = FALSE;
    return r;
}

void fn_1_144F40(s32 mode, u8 *arg1) {
    Row rowbuf;
    Row *row = &rowbuf;
    FontDrawPacket packet;
    s32 i;
    Entry *e;
    Record *rec;
    s32 idx;
    u32 left;
    s32 k;

    fn_1_52070(0x140);
    fn_80008BEC(row, 0, sizeof(*row));
    if (in_0_2_7_8(mode) || in_4_5_6_9_10(mode)) {
        row->unk_18 = lbl_1_bss_8E530;
        row->unk_1C = lbl_1_bss_8E538;
    } else {
        row->unk_18 = lbl_1_bss_8E534;
        row->unk_1C = lbl_1_bss_8E53C;
    }
    if (arg1 == NULL) {
        row->unk_34 = lbl_1_bss_3C30.unk_6;
    } else {
        row->unk_34 = arg1[0];
    }
    packet = lbl_1_rodata_26F8;
    packet.image = 0x9437;
    fn_1_51914(&packet);
    fn_1_145C6C(mode, (void *)row);

    row->unk_10 = 0;
    row->unk_14 = 0;
    if (in_4_5_6_9_10(mode)) {
        row->x = 0x9E;
        row->y = 0x48;
        row->unk_8 = 1;
        row->unk_C = 1;
        row->unk_10 = -2;
        row->unk_14 = -4;
    } else if (in_8_9_10(mode)) {
        row->x = 0x68;
        row->y = 0x41;
        row->unk_8 = 1;
        row->unk_C = 1;
    } else if (in_0_1(mode)) {
        row->x = 0x6C;
        row->y = 0x38;
        row->unk_8 = 1;
        row->unk_C = 1;
    } else if (lbl_1_bss_8E548 <= 4) {
        row->x = 0x77;
        row->y = 0x48;
        row->unk_8 = 0;
        row->unk_C = 0;
    } else {
        row->x = 0x6C;
        row->y = 0x38;
        row->unk_8 = 1;
        row->unk_C = 1;
    }
    row->unk_68 = in_any(mode) ? 0 : 10;
    row->unk_78 = lbl_801A66A4 - lbl_1_bss_8E528;
    if (row->unk_78 == 16) {
        fn_1_A2D84(0xA9010600);
    }

    for (i = -row->unk_8; i < lbl_1_bss_8E548 + row->unk_C; i++) {
        row->unk_20 = i + (s32)row->unk_18;
        if (in_4_5_6_9_10(mode)) {
            if (!in_range(row, 9)) {
                continue;
            }
            e = &lbl_1_bss_8EF68[row->unk_20];
            row->unk_24 = e->unk_1B;
            row->unk_28 = e->unk_8;
            row->unk_30 = e->unk_0;
            row->unk_3C = e->unk_4;
            row->unk_40 = e->unk_18;
            row->unk_35 = e->unk_1A;
            row->unk_36 = e->unk_1C;
            row->unk_37 = e->unk_1D;
            row->unk_38 = e->unk_1E;
            row->unk_39 = e->unk_1F;
        } else if (in_8_9_10(mode)) {
            if (!in_range(row, lbl_1_bss_3C30.unk_9 - 1)) {
                continue;
            }
            idx = lbl_1_bss_8E428[row->unk_20];
            row->unk_4C = idx;
            rec = &lbl_1_bss_3C30.unk_D4[idx];
            row->unk_5C = rec->unk_E[lbl_1_bss_3C30.unk_A7];
            row->unk_24 = rec->unk_80;
            row->unk_2C = rec->unk_0;
            row->unk_35 = rec->unk_82;
            row->unk_30 = rec->unk_24[lbl_1_bss_3C30.unk_A7];
        } else {
            if (!in_range(row, lbl_1_bss_3C30.unk_9 - 1)) {
                continue;
            }
            idx = lbl_1_bss_8E428[row->unk_20];
            row->unk_4C = idx;
            rec = &lbl_1_bss_3C30.unk_D4[idx];
            row->unk_5C = rec->unk_E[lbl_1_bss_3C30.unk_A7];
            row->unk_54 = rec->unk_4;
            row->unk_62 = rec->unk_9E;
            row->unk_24 = rec->unk_80;
            row->unk_35 = rec->unk_82;
            row->unk_2C = rec->unk_0;
            for (k = 0; k < 5; k++) {
                row->unk_56[k] = rec->unk_9[k];
                row->unk_42[k] = rec->unk_4C[k];
            }
            row->unk_30 = rec->unk_24[lbl_1_bss_3C30.unk_A7];
            row->unk_60 = rec->unk_8;
            row->unk_61 = rec->unk_83;
        }
        row->packet[0] = lbl_1_rodata_92C0;
        row->packet[1] = lbl_1_rodata_9318;
        row->packet[2] = lbl_1_rodata_9370;
        if (fn_1_145B58(mode, (void *)row)) {
            static const Color_144F40 gold = {0xFA, 0xDC, 0x82, 0xFF};
            Color_144F40 color_add = {0, 0, 0, 0};
            /* Accepted shortcut: font.h types FontDrawPacket.color/color_add as u8[4]; the colours are stored through a
               Color_144F40 view until font.c (FT lane) settles the field type. */
            *(Color_144F40 *)row->packet[2].color = gold;
            *(Color_144F40 *)row->packet[1].color = gold;
            *(Color_144F40 *)row->packet[0].color = gold;
            *(Color_144F40 *)row->packet[2].color_add = color_add;
            *(Color_144F40 *)row->packet[1].color_add = color_add;
            *(Color_144F40 *)row->packet[0].color_add = color_add;
        }
        row->unk_6C = CLAMP(555 - row->unk_78 * 40, 0, 555);
        row->unk_70 = row->unk_6C + CLAMP(610 - row->unk_78 * 40, 0, 55);
        row->unk_74 = row->unk_6C + CLAMP(row->unk_78 * 60 - 1415, -455, 0);
        row->unk_64 = row->x + (row->y * (i - (row->unk_18 - fpscr_trunc(row->unk_18))));
        left = 0;
        lbl_1_bss_8E42C = left;
        lbl_1_bss_8E434 = lbl_1_bss_8E430 = 120 + row->unk_68 + row->unk_6C;
        lbl_1_bss_8E438 = 640;
        lbl_1_bss_8E43C = row->x - 6;
        lbl_1_bss_8E440 = lbl_1_bss_8E548 * row->y;
        CLIP(lbl_1_bss_8E42C, lbl_1_bss_8E430, left, lbl_1_bss_8E430, 639.0f);
        CLIP(lbl_1_bss_8E434, lbl_1_bss_8E438, lbl_1_bss_8E434, 640, 639.0f);
        CLIP(lbl_1_bss_8E43C, lbl_1_bss_8E440, lbl_1_bss_8E43C, lbl_1_bss_8E440, 479.0f);
        fn_1_146550(mode, (void *)row);
        fn_1_146B5C(mode, (void *)row);
        fn_1_146C88(mode, (void *)row);
        fn_1_147188(mode, (void *)row);
        fn_1_147508(mode, (void *)row);
        fn_1_147A04(mode, (void *)row);
        fn_1_148444(mode, (void *)row);
        fn_1_148738(mode, (void *)row);
        fn_1_148950(mode, (void *)row);
        fn_1_1490FC(mode, (void *)row);
    }
    fn_1_1492E0(mode, (void *)row);
    if (lbl_1_bss_960 != 10) {
        fn_1_1498B8(mode, row->unk_1C, lbl_1_bss_8E548, row->y, row->x, row->unk_10, row->unk_14);
    }
    fn_1_52088();
}
#undef lbl_1_bss_3C30
#undef lbl_1_bss_8EF68
#undef lbl_1_bss_960
#undef lbl_1_rodata_26F8
#undef MIN
#undef CLAMP
#undef CLIP
/* fzgx:end fn_1_144F40 */

/* fzgx:begin fn_1_145B58 */
static inline s32 fn_1_145B58_test(s32 arg0, s32 range, s32 one) {
    s32 d, c, b, a;
    b = one; c = one; d = one; a = one;
    if (range == 0) a = 0;
    if (a == 0 && arg0 != 9) d = 0;
    if (d == 0 && arg0 != 10) c = 0;
    if (c == 0 && arg0 != 6) b = 0;
    return b;
}

BOOL fn_1_145B58(s32 arg0, s32 *arg1) {
    u32 r;
    if (arg0 == 10 || arg0 == 6) {
        return arg1[8] == 0;
    }
    if (fn_1_145B58_test(arg0, (u32)(arg0 - 4) <= 1, 1) != 0) {
        r = 0;
        if ((s32)((u32)fn_1_155F7C()) != 0) {
            if (arg1[8] == (s32)((u32)fn_1_155F8C())) {
                r = 1;
            }
        }
        return r;
    }
    return lbl_1_bss_3C30.unk_8 > arg1[19];
}
/* fzgx:end fn_1_145B58 */

/* fzgx:begin fn_1_145C6C */
/* Results header: "[machine name] course text" centred in two passes (pass 0 measures, pass 1 draws),
 * then the four header sprites. Other modes go to fn_1_1461C8. */

/* WARNING: compiler-diff device, not original code (carried from main) */
#pragma opt_loop_invariants off

/* WARNING: compiler-diff device, not original code (carried from main) */
#pragma opt_lifetimes off

/* WARNING: compiler-diff device, not original code: opt_dead_assignments off keeps the dead store to
 * center_src inside the loop (see the two WARNING comments in the body). */

#pragma opt_dead_assignments off

void fn_1_145C6C(s32 mode, Row_145C6C *row) {
    u32 index;
    u8 idx;
    s32 pass;
    s32 width;
    s32 left;
    f32 center_src;
    f32 center;
    const char *name;
    const char *text;
    s16 grid_row;
    s16 grid_col;
    FontDrawPacket packet;

    if (in_8_9_10(mode)) {
        width = 0;
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(1.0f);
        index = row->unk_34;
        idx = index;
        /* WARNING: compiler-diff device, not original code: the screen centre goes through center_src
         * so that the loop preheader holds a float copy (fmr) of the 320.0f load when MWCC first schedules
         * it. Retail's preheader order needs that copy at the first schedule; the post-allocation peephole
         * then folds it into the load, so it emits no code. */
        center_src = 320.0f;
        center = center_src;
        for (pass = 0; pass <= 1; pass++) {
            left = (center - (width / 2));
            width = 0;
            fn_1_494DC(8);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                fn_1_4AE0C("[");
            }
            name = (const char *)((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[idx]];
            width += 12;
            fn_1_494DC(8);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                /* WARNING: compiler-diff device, not original code: dead store. A second definition of
                 * center_src inside the loop stops backend copy propagation from forwarding the preheader
                 * copy above. The store is never read and is deleted at register colouring: no code. */
                center_src = 320.0f;
                fn_1_4A0D8(name);
            }
            width += fn_1_4B068((s32)name);
            fn_1_494DC(8);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                fn_1_4AE0C("]");
            }
            text = (const char *)((u32 *)(lbl_1_data_2BD54 + idx * 0x18))[lbl_801A66B4];
            width += 18;
            fn_1_494DC(0x2a);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                fn_1_4A0D8(text);
            }
            width += fn_1_4B068((s32)text);
        }
        fn_1_12EF80(row->unk_34, (void *)&grid_row, (void *)&grid_col);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x9800;
        fn_1_51564(0, 0, 36, 36, 6, 1);
        fn_1_5158C(&packet, packet.image, grid_col, 0);
        packet.x = 112.0f;
        packet.y = 30.0f;
        packet.z = 5.0f;
        fn_1_4F734(&packet);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x9806;
        fn_1_51564(0, 0, 36, 36, 6, 1);
        fn_1_5158C(&packet, packet.image, grid_col, 0);
        packet.x = 492.0f;
        packet.y = 30.0f;
        packet.z = 5.0f;
        fn_1_4F734(&packet);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = in_4_5_6_9_10(mode) ? 0x9803 : 0x9804;
        packet.x = 320.0f;
        packet.y = 33.0f;
        packet.z = 10.0f;
        packet.flags = 6;
        fn_1_4F734(&packet);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x980B;
        packet.x = 320.0f;
        packet.y = 19.0f;
        packet.z = 20.0f;
        packet.flags = 6;
        fn_1_4F734(&packet);
    } else {
        fn_1_1461C8(mode, row->unk_34);
    }
}

#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

/* fzgx:end fn_1_145C6C */

/* fzgx:begin fn_1_1461C8 */

void fn_1_1461C8(s32 mode, u32 index) {
    u8 idx;
    u8 pass;
    s32 width;
    s32 total;
    FontDrawPacket packet;
    s32 left;
    const char *text;

    total = 0;
    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9909;
    packet.x = 320.0f;
    packet.y = 24.0f;
    packet.z = 50.0f;
    packet.flags = 6;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(0x1d);
    fn_1_496FC(320.0f, 29.0f);
    fn_1_495C8((void *)1);
    fn_1_495B0(0x80000000);
    fn_1_4954C(40.0f);
    fn_1_49590(0.5f);
    switch (mode) {
    case 0:
        fn_1_4AE0C("RESULTS");
        break;
    case 1:
        fn_1_4AE0C("TOTAL RANKING");
        break;
    case 2:
        fn_1_4AE0C("VS RESULTS");
        break;
    case 3:
        fn_1_4AE0C("VS TOTAL RANKING");
        break;
    case 4:
    case 5:
    case 6:
        fn_1_4AE0C("TIME ATTACK");
        break;
    case 7:
        fn_1_4AE0C("PRACTICE");
        break;
    }

    idx = index;
    /* pass 0 measures the line, pass 1 draws it centred */
    for (pass = 0; pass <= 1; pass++) {
        left = (320.0f - (total / 2));
        width = 0;
        text = (const char *)((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[idx]];
        fn_1_49410();
        fn_1_494DC(0x1e);
        fn_1_495B0(0x80000000);
        fn_1_4954C(40.0f);
        fn_1_495C8((void *)8);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        if (pass) {
            fn_1_496FC(left, 72.0f);
            fn_1_4A0D8(text);
        }
        width += fn_1_4B068((s32)text);
        width += 10;

        text = (const char *)((u32 *)(lbl_1_data_2BD54 + idx * 0x18))[lbl_801A66B4];
        fn_1_49410();
        fn_1_494DC(0x2a);
        fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        fn_1_495B0(0x80000000);
        fn_1_4954C(40.0f);
        fn_1_495C8((void *)8);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_49738((void *)fn_1_5233C);
        fn_1_49748(1.0f);
        if (pass) {
            fn_1_496FC((left + width), 72.0f);
            fn_1_4A0D8(text);
        }
        width += fn_1_4B068((s32)text);
        total = width;
    }
}
/* fzgx:end fn_1_1461C8 */

/* fzgx:begin fn_1_146550 */
/* one results row (layout shared with fn_1_144F40's Row) */

static inline BOOL fn_1_146550_isC(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}

/* WARNING: compiler-diff device, not original code (carried from main) */
#pragma opt_lifetimes off

void fn_1_146550(s32 mode, fn_1_146550_Row *__restrict row) {
    FontDrawPacket packet;
    FontDrawPacket sub;
    s32 j;
    s32 x;
    s32 n;
    s32 dx;
    s32 dx2;
    s32 i;

    packet = row->packet[0];
    packet.image = 0x9723;
    packet.x = (32 + row->unk_68 + row->unk_70);
    packet.y = row->unk_64;
    packet.z = 50.0f;
    fn_1_51678(&packet, 0x9723, 0, 0, 18, 48);
    fn_1_4F734(&packet);

    packet = row->packet[1];
    packet.image = 0x9723;
    packet.x = (row->unk_74 + 590);
    packet.y = row->unk_64;
    packet.z = 50.0f;
    fn_1_51678(&packet, 0x9723, 18, 0, 18, 48);
    fn_1_4F734(&packet);

    packet = row->packet[0];
    n = row->unk_70;
    x = row->unk_68;
    packet.image = 0x9709;
    packet.y = row->unk_64;
    packet.z = 50.0f;
    for (i = 0, dx = 0; i < 3; i++, dx += 20) {
        packet.x = (50 + x + dx + n);
        fn_1_4F734(&packet);
    }

    packet = row->packet[1];
    packet.image = 0x9709;
    packet.y = row->unk_64;
    packet.z = 50.0f;
    for (j = 3; j < 10; j++) {
        packet.x = (50 + row->unk_68 + j * 20 + row->unk_74);
        if (j == 9 && fn_1_146550_isC(mode)) {
            sub = packet;
            fn_1_51678(&sub, packet.image, 0, 0, 10, 48);
            fn_1_4F734(&sub);
        } else {
            fn_1_4F734(&packet);
        }
    }

    x = row->unk_74;
    for (n = 0, dx2 = 270; n < 5; n++, dx2 += 20) {
        packet.x = (x + dx2);
        fn_1_4F734(&packet);
    }
    x = row->unk_74;
    for (n = 0, dx2 = 390; n < 5; n++, dx2 += 20) {
        packet.x = (x + dx2);
        fn_1_4F734(&packet);
    }
    x = row->unk_74;
    for (n = 0, dx2 = 510; n < 4; n++, dx2 += 20) {
        packet.x = (x + dx2);
        fn_1_4F734(&packet);
    }

    packet = row->packet[1];
    packet.image = 0x970A;
    packet.x = (row->unk_74 + 250);
    packet.y = row->unk_64;
    packet.z = 50.0f;
    fn_1_4F734(&packet);

    packet = row->packet[1];
    packet.image = 0x970A;
    packet.x = (row->unk_74 + 370);
    packet.y = row->unk_64;
    packet.z = 50.0f;
    fn_1_4F734(&packet);

    packet = row->packet[1];
    packet.image = 0x970A;
    packet.x = (row->unk_74 + 490);
    packet.y = row->unk_64;
    packet.z = 50.0f;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_146550 */

/* fzgx:begin fn_1_146B5C */
#pragma opt_lifetimes reset

void fn_1_146B5C(s32 unused, u8 *arg1) {
    s32 c;
    s32 b;
    s32 a;
    s32 v;
    FontDrawPacket pkt;

    fn_1_51564(0, 0, 0x24, 0x28, 0xa, 4);

    pkt = lbl_1_rodata_92C0;

    v = *(s32 *)(arg1 + 0x20);
    a = *(s32 *)(arg1 + 0x68);
    b = *(s32 *)(arg1 + 0x70);
    c = *(s32 *)(arg1 + 0x64);

    pkt.image = 0x973E;
    pkt.x = a + 0x37 + b;
    pkt.y = c + 4;
    pkt.z = 47.0f;

    fn_1_5158C(&pkt, 0x973E, (v % 10), (v / 10));
    fn_1_4F734(&pkt);
}
/* fzgx:end fn_1_146B5C */

/* fzgx:begin fn_1_146C88 */
/* sel_static_disp.c's .rodata, laid out as retail (base lbl_1_rodata_92C0) */

static inline BOOL fn_1_146C88_in8(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isA(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_in8(mode) && mode != 10) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_in4(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isB1(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_in4(mode) && mode != 9) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isB2(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_isB1(mode) && mode != 10) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isB(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_isB2(mode) && mode != 6) {
        r = FALSE;
    }
    return r;
}

void fn_1_146C88(s32 mode, fn_1_146C88_Obj *__restrict obj) {
    s32 x;
    s32 y;
    u8 idx;
    s32 n;
    void *p;
    FontDrawPacket packet;

    x = (obj->unk_68 + 0x78) + obj->unk_6C;
    y = obj->unk_64 + 0x17;

    if (fn_1_146C88_isA(mode) || fn_1_146C88_isB(mode)) {
        packet = obj->unk_12C;
        packet.image = 0x9718;
        packet.x = x;
        packet.y = y;
        packet.z = 46.0f;
        packet.flags |= 10;
        fn_1_4F734((void *)&packet);
    }

    packet = obj->unk_12C;
    packet.image = 0x9719;
    packet.x = x;
    packet.y = y;
    packet.z = 45.0f;
    packet.flags |= 10;
    fn_1_4F734((void *)&packet);

    packet = obj->unk_12C;
    packet.image = 0x9717;
    packet.x = x;
    packet.y = y;
    packet.z = 40.0f;
    packet.flags |= 10;
    fn_1_4F734((void *)&packet);

    {
        fn_1_146C88_Tbl tblA = {{0x9736, 0x9737, 0x9738, 0x9739}};
        fn_1_146C88_Tbl tblB = {{0x973A, 0x973B, 0x973C, 0x973D}};

        if (fn_1_146C88_isB(mode)) {
            idx = 0;
        } else {
            p = fn_1_868C0(obj->unk_4C);
            if (p != NULL) {
                idx = *(s16 *)((u8 *)p + 0x3B8) % 4;
            } else {
                idx = 0;
            }
        }

        packet = lbl_1_rodata_9370;
        if (lbl_1_bss_8E52C != 0) {
            packet.image = tblA.a[idx];
            fn_1_51564(0, 0, 36, 36, 6, 7);
            packet.x = x;
            packet.y = y;
            packet.z = 42.0f;
            n = obj->unk_24;
        } else {
            packet.image = tblB.a[idx];
            fn_1_51564(0, 0, 64, 64, 6, 7);
            n = obj->unk_35 > 41 ? 41 : obj->unk_35;
            packet.x = x;
            packet.y = (y - 2);
            packet.z = 38.0f;
        }
        fn_1_5158C(&packet, packet.image, n % 6, n / 6);
        packet.flags |= 10;
        fn_1_4F734((void *)&packet);
    }
}
/* fzgx:end fn_1_146C88 */

/* fzgx:begin fn_1_147188 */
/* the badge's colours (black, colour_add 0xC0 grey), retail's 8 bytes at 0x47C */

/* retail tests the mode as this chain of flags, each set to TRUE then cleared (as in fn_1_148738) */

static inline BOOL fn_1_147188_mode_8_9(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}

static inline BOOL fn_1_147188_mode_8_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_8_9(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL fn_1_147188_mode_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}

static inline BOOL fn_1_147188_mode_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_4_5(mode) && mode != 9) r = FALSE;
    return r;
}

static inline BOOL fn_1_147188_mode_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL fn_1_147188_mode_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

void fn_1_147188(s32 mode, const fn_1_147188_Row *row) {
    FontDrawPacket packet;
    s32 show;
    show = FALSE;
    if (mode == 8 || mode == 2 || mode == 3) {
        show = TRUE;
    }
    if (!show) {
        return;
    }
    if (fn_1_147188_mode_8_9_10(mode)) {
        return;
    }
    packet = row->unk_12C;
    packet.image = 0x9907;
    packet.x = (row->unk_6C + 0x8A);
    packet.y = (row->unk_64 + 3);
    packet.z = 41.0f;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_9370;
    if (mode == 10 || mode == 6) {
        show = row->unk_20 == 0;
    } else if (fn_1_147188_mode_4_5_6_9_10(mode)) {
        show = 0;
        if (fn_1_155F7C() != 0 && row->unk_20 == fn_1_155F8C()) {
            show = 1;
        }
    } else {
        show = lbl_1_bss_3C30.unk_8 > row->unk_4C;
    }
    if (show) {
        packet.image = 0x971E;
        fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
        fn_1_5158C(&packet, packet.image, (row->unk_4C % 2), (row->unk_4C / 2));
    } else {
        packet.image = 0x971F;
        fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
        fn_1_5158C(&packet, packet.image, (row->unk_20 % 2), (row->unk_20 / 2 % 2));
        if (lbl_1_bss_8E548 > 4) {
            static const Color_144F40 color = { 0x00, 0x00, 0x00, 0x00 };
            static const Color_144F40 color_add = { 0xC0, 0xC0, 0xC0, 0x00 };
            /* Accepted shortcut: font.h types FontDrawPacket.color/color_add as u8[4]; the colours are stored through a
               Color_144F40 view until font.c (FT lane) settles the field type. */
            *(Color_144F40 *)packet.color = color;
            *(Color_144F40 *)packet.color_add = color_add;
        }
    }
    packet.x = (row->unk_6C + 0xA4);
    packet.y = (row->unk_64 + 0x15);
    packet.z = 33.0f;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_147188 */

/* fzgx:begin fn_1_147508 */
#define lbl_801A66A4 (*(s32 *)&lbl_801A66A4)
/* WARNING: compiler-diff device, not original code (carried from main) */
#pragma opt_propagation off

static inline BOOL fn_1_147508_inRange(s32 m, s32 lo, s32 hi) {
    return m == lo || m == hi;
}

static inline BOOL fn_1_147508_isModeA(s32 m) {
    return fn_1_147508_inRange(m, 8, 9) || m == 10;
}

static inline BOOL fn_1_147508_isModeB2(s32 m) {
    return fn_1_147508_inRange(m, 4, 5) || m == 9;
}

static inline BOOL fn_1_147508_isModeB1(s32 m) {
    return fn_1_147508_isModeB2(m) || m == 10;
}

static inline BOOL fn_1_147508_isModeB(s32 m) {
    return fn_1_147508_isModeB1(m) || m == 6;
}

static inline BOOL fn_1_147508_isValidChar(u32 c) {
    BOOL valid = c <= 74;
    return valid;
}

#define IS_MODE_A(m) fn_1_147508_isModeA(m)

#define IS_MODE_B(m) fn_1_147508_isModeB(m)

#define IS_VALID_CHAR(c) fn_1_147508_isValidChar(c)

static inline void fn_1_147508_setPacket(FontDrawPacket *p, u32 image, f32 x, f32 y) {
    p->image = image;
    p->x = x;
    p->y = y;
    p->z = 48.0f;
}

static inline void set_color_144F40(Color_144F40 color) {
    fn_1_49514((u32 *)&color);
}

void fn_1_147508(s32 mode, fn_1_147508_Entry *entry) {
    u32 x;
    u32 y;
    s32 show;
    s32 iy, ix;
    u32 image;
    FontDrawPacket packet;
    Color_144F40 color;
    char buf[0x100];

    x = entry->unk_74 + 160;
    y = entry->unk_64 + 37;
    if (IS_MODE_A(mode) || IS_MODE_B(mode)) {
        s32 packetIY, packetIX;
        u32 packetImage;
        packet = entry->packet;
        packetImage = 0x9724;
        packetIX = entry->unk_74 + 126;
        packetIY = entry->unk_64 + 32;
        fn_1_147508_setPacket(&packet, packetImage, packetIX, packetIY);
        fn_1_4F734(&packet);
    }
    if (!IS_MODE_B(mode)) {
        return;
    }
    fn_1_49410();
    fn_1_494DC(22);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_149C2C);
    fn_1_4954C(47.0f);
    fn_1_4962C();
    fn_1_49590(0.5f);
    fn_1_496FC(x, y);
    if (mode == 10 || mode == 6) {
        show = entry->unk_20 == 0;
    } else if (IS_MODE_B(mode)) {
        show = 0;
        if (fn_1_155F7C() != 0 && entry->unk_20 == fn_1_155F8C()) {
            show = 1;
        }
    } else {
        show = lbl_1_bss_3C30.unk_8 > entry->unk_4C;
    }
    if (show) {
        color.a = 255;
        color.b = 255;
        color.r = 255;
        color.g = 255.0f * ((1.0f - lbl_8006D188((s32)(65536.0f * (lbl_801A66A4 % 60) / 60.0f))) / 2.0f);
        set_color_144F40(color);
    }
    if (lbl_1_bss_8E52C != 0) {
        if (fn_8006FC1C((void *)(((char **)&lbl_1_data_212A8)[fn_1_12C930(entry->unk_24)]), "GOMAR & SHIOH")) {
            fn_1_4A0D8("GOMAR , SHIOH");
        } else {
            fn_1_4A0D8(((char **)&lbl_1_data_212A8)[fn_1_12C930(entry->unk_24)]);
        }
    } else if (entry->unk_35 < 41) {
        fn_1_4A0D8(((char *)fn_1_7F49C(entry->unk_35, 0, (void *)buf)));
    } else if (IS_VALID_CHAR(entry->unk_37) && IS_VALID_CHAR(entry->unk_38) && IS_VALID_CHAR(entry->unk_39)) {
        fn_1_4A0D8(fn_1_14FEAC((void *)entry->unk_37, (void *)entry->unk_38, (void *)entry->unk_39, buf, 0));
    }
}
#undef lbl_801A66A4
#undef IS_MODE_A
#undef IS_MODE_B
#undef IS_VALID_CHAR
#pragma opt_propagation reset
/* fzgx:end fn_1_147508 */

/* fzgx:begin fn_1_147A04 */
#define lbl_801A66B4 (*(s32 *)&lbl_801A66B4)
static inline BOOL fn_1_147A04_range4(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}

static inline BOOL fn_1_147A04_range49(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range4(mode) && mode != 9) r = FALSE;
    return r;
}

static inline BOOL fn_1_147A04_range49A(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range49(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL fn_1_147A04_special(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range49A(mode) && mode != 6) r = FALSE;
    return r;
}

static inline BOOL fn_1_147A04_range8(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}

static inline BOOL fn_1_147A04_range89A(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range8(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL fn_1_147A04_range0(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) r = FALSE;
    return r;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void fn_1_147A04(s32 arg0, const fn_1_147A04_Obj *arg1) {
    char *v12;
    u32 v10;
    char *v16;
    s32 v6;
    f32 v23;
    f32 v24;
    f32 v7;
    char loc_A8[0x100];
    char loc_34[17];
    Color_144F40 loc_18;

    if (fn_1_147A04_special(arg0)) {
        fn_1_49410();
        fn_1_49738(fn_1_149B64);
        fn_1_49748(0.0f);
        fn_1_495C8((void *)8);
        fn_1_496FC((arg1->unk_68 + 180 + arg1->unk_74), (arg1->unk_64 + 21));
        fn_1_4955C(0.75f, 0.75f);
        fn_1_4954C(48.0f);
        loc_34[16] = 0;
        strncpy(loc_34, ((const fn_1_147A04_Obj *)arg1)->unk_28, 16);
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == (s32)((u32)fn_1_155F8C())) {
            if (lbl_1_bss_8E594 != 0) {
                v10 = strlen(loc_34);
            } else {
                v10 = strlen(loc_34) - 2;
            }
        } else {
            v10 = strlen(loc_34);
        }
        v12 = loc_34;
        for (arg0 = 0; arg0 < v10; arg0 += 2) {
            if (strncmp(v12, "\201\347", 2) == 0) {
                strncpy(v12, "  ", 2);
                strcpy((void *)(v12 + 1), (void *)(v12 + 2));
                v12 += 1;
            } else {
                v12 += 2;
            }
        }
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == (s32)((u32)fn_1_155F8C())) {
            {
                Color_144F40 loc_14 = { 0xFF, 0xFF, 0x00, 0xFF };
                fn_1_49514((u32 *)&loc_14);
            }
            {
                Color_144F40 loc_10;
                Color_144F40 loc_C = { 0x00, 0x00, 0x00, 0x00 };
                loc_C.g = (255.0f * lbl_8006D188((s16)(lbl_801A66A4 << 8)));
                loc_C.b = (255.0f * lbl_8006D188((s16)(lbl_801A66A4 << 8)));
                loc_10 = loc_C;
                fn_1_49528((u32 *)&loc_10);
            }
            if (lbl_1_bss_8E594 != 0) {
                if (lbl_801A66A4 % 60 > 10) {
                    strncpy(loc_34 + strlen(loc_34), "\201\350", 3);
                }
            } else {
                if (lbl_801A66A4 % 60 > 50 && strlen(loc_34) >= 2) {
                    loc_34[strlen(loc_34) - 2] = 0;
                }
            }
        }
        fn_1_4A0D8(loc_34);
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == (s32)((u32)fn_1_155F8C())) {
            const char *loc_48[4][6] = {
                { "Capital Letters", "GER Capital Letters", "FRE Capital Letters", "SPA Capital Letters", "ITA Capital Letters", "\x89p\x90\x94" },
                { " Small Letters ", "GER Small Letters", "FRE Small Letters", "SPA Small Letters", "ITA Small Letters", "\x8BL\x8D\x86" },
                { "     Signs     ", "GER Signs", "FRE Signs", "SPA Signs", "ITA Signs", "\x82\xA9\x82\xC8" },
                { "    Numbers   ", "GER Numbers", "FRE Numbers", "SPA Numbers", "ITA Numbers", "\x83J\x83i" },
            };
            const char *loc_1C[6] = {
                "\x83\xA0 Delete \x83\x9F Enter \x83\xB4[%s]", "GER \x83\xA0 Delete \x83\x9F Enter \x83\xB4[%s]",
                "FRE \x83\xA0 Delete \x83\x9F Enter \x83\xB4[%s]", "SPA \x83\xA0 Delete \x83\x9F Enter \x83\xB4[%s]",
                "ITA \x83\xA0 Delete \x83\x9F Enter \x83\xB4[%s]", "\x83\xA0 \x8F\xC1\x82\xB7 \x83\x9F \x8C\x88\x92\xE8 \x83\xB4[%s]",
            };
            if (arg1->unk_78 > 45.0f) {
                v6 = lbl_1_bss_8E570;
                sprintf(loc_A8, loc_1C[lbl_801A66B4], loc_48[v6 < 0 ? 0 : v6 > 3 ? 3 : v6][lbl_801A66B4]);
            }
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
            if (lbl_801A66B4 != 5) {
                v16 = loc_A8;
                v23 = (arg1->unk_68 + 158);
                v24 = (arg1->unk_64 + 46);
                if (arg1->unk_78 > 45.0f) {
                    fn_1_496FC(v23, v24);
                    v7 = 0.01f;
                    fn_1_4954C(v7 - 0.0005);
                    fn_1_4955C(0.6666667f, 0.6666667f);
                    fn_1_495C8((void *)8);
                    fn_1_4A0D8(v16);
                    v7 = 13.333334f + fn_1_4B090((s32)v16);
                    fn_1_53B14(0, 166.0f + v23, v24, 348.33334f, v7, 0.01f);
                }
            } else {
                fn_1_53C9C(0, (u32)loc_A8, (arg1->unk_68 + 290), (arg1->unk_64 + 46), 0.01f, 20.0f,
                           (9.0f + 7.0f * MIN(1.0f, (arg1->unk_78 - 40.0f) / 5.0f)) / 24.0f);
            }
        }
    } else {
        fn_1_49410();
        fn_1_494DC(21);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        if (fn_1_147A04_range89A(arg0) || fn_1_147A04_special(arg0)) {
            fn_1_496FC((arg1->unk_68 + 166 + arg1->unk_74), (arg1->unk_64 + 11));
        } else if (fn_1_147A04_range0(arg0)) {
            fn_1_496FC((arg1->unk_68 + 150 + arg1->unk_74), (arg1->unk_64 + 13));
        } else {
            fn_1_496FC((arg1->unk_74 + 196), (arg1->unk_64 + 13));
        }
        fn_1_4954C(47.0f);
        fn_1_4962C();
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        if (arg0 == 10 || arg0 == 6) {
            arg0 = arg1->unk_20 == 0;
        } else if (fn_1_147A04_special(arg0)) {
            arg0 = 0;
            if ((s32)((u32)fn_1_155F7C()) != 0 && arg1->unk_20 == (s32)((u32)fn_1_155F8C())) arg0 = 1;
        } else {
            arg0 = arg1->unk_4C < lbl_1_bss_3C30.unk_8;
        }
        if (arg0) {
            loc_18.a = 255;
            loc_18.b = 255;
            loc_18.r = 255;
            loc_18.g = 255.0f * ((1.0f - lbl_8006D188((s32)(65536.0f * ((s32)lbl_801A66A4 % 60) / 60.0f))) / 2.0f);
            {
                Color_144F40 loc_8 = loc_18;
                fn_1_49514((u32 *)&loc_8);
            }
        }
        if (lbl_1_bss_8E52C != 0) {
            if (fn_8006FC1C((void *)(&lbl_1_data_212A8.unk_0)[fn_1_12C930(arg1->unk_24)], "GOMAR & SHIOH") != 0) {
                fn_1_4CE48(170.0f, (Obj_1_bss_4B9CC *)"GOMAR , SHIOH");
            } else {
                fn_1_4CE48(170.0f, (Obj_1_bss_4B9CC *)(&lbl_1_data_212A8.unk_0)[fn_1_12C930(arg1->unk_24)]);
            }
        } else {
            fn_1_4CE48(170.0f, arg1->unk_2C);
        }
    }
}
#undef lbl_801A66B4
#undef MIN
/* fzgx:end fn_1_147A04 */

/* fzgx:begin fn_1_148444 */
static inline BOOL fn_1_148444_isA(s32 mode) {
    BOOL r = FALSE;
    if (mode == 8 || mode == 2 || mode == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL fn_1_148444_isB(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_148444_isC(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}

void fn_1_148444(s32 mode, fn_1_148444_Obj *obj) {
    s32 x;
    s32 y;
    s32 value;
    s32 width;
    FontDrawPacket packet;
    char buf[0x100];

    if (!fn_1_148444_isA(mode) && !fn_1_148444_isB(mode)) {
        return;
    }
    if (!fn_1_148444_isC(mode)) {
        return;
    }
    if (obj->unk_5C == 0xFF) {
        return;
    }
    x = obj->unk_68 + obj->unk_74;
    y = obj->unk_64 + 14;
    x += 0x1A7;
    if (mode == 3) {
        x -= 10;
    }
    fn_1_49410();
    fn_1_494DC(0x1B);
    fn_1_49738(fn_1_149C2C);
    fn_1_496FC(x, y);
    fn_1_4954C(47.0f);
    fn_1_495C8((void *)2);
    if (fn_1_148444_isB(mode)) {
        value = obj->unk_56[lbl_1_bss_3C30.unk_A7];
    } else {
        value = obj->unk_56[0];
    }
    if (fn_1_148444_isA(mode)) {
        sprintf(buf, "%02d", value < 0 ? 0 : (value > 99 ? 99 : value));
    } else {
        sprintf(buf, "%03d", value < 0 ? 0 : (value > 999 ? 999 : value));
    }
    fn_1_4A0D8(buf);
    width = fn_1_4B068((s32)buf);
    packet = lbl_1_rodata_9318;
    packet.image = 0x9905;
    fn_1_51678(&packet, 0x9905, 100, 0, 10, 16);
    packet.x = (x - width);
    packet.y = y;
    packet.z = 47.0f;
    packet.flags |= 7;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_148444 */

/* fzgx:begin fn_1_148738 */
/* retail tests the mode as this chain of flags, each set to TRUE then cleared (the same chain as fn_1_148950) */

static inline BOOL fn_1_148738_mode_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}

static inline BOOL fn_1_148738_mode_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148738_mode_4_5(mode) && mode != 9) r = FALSE;
    return r;
}

static inline BOOL fn_1_148738_mode_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148738_mode_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL fn_1_148738_mode_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148738_mode_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

/* GC/2.5 (2.0 also matches): 1.3.2 schedules the three row loads after the mode test's first steps; the row
 * must be const for 2.x to keep retail's order */

void fn_1_148738(s32 mode, const fn_1_148738_Row *row) {
    s32 x = 0x17F + row->unk_68 + row->unk_74;
    s32 y = row->unk_64 + 0x10;
    FontDrawPacket packet;

    if (fn_1_148738_mode_4_5_6_9_10(mode)) {
        packet = lbl_1_rodata_9318;
        packet.image = 0x971D;
        packet.x = x;
        packet.y = y;
        packet.z = 46.0f;
        fn_1_4F734(&packet);
        packet = lbl_1_rodata_9318;
        packet.image = 0x970B;
        packet.x = (x - 4) + (f32)row->unk_36 * (fn_1_48690(0x971D) - 2) / 100.0f;
        packet.y = (y - 10);
        packet.z = 45.0f;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_148738 */

/* fzgx:begin fn_1_148950 */
static inline BOOL fn_1_148950_mode_1_3(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL fn_1_148950_mode_0_2_7_8(s32 mode) {
    BOOL r = FALSE;
    if (mode == 0 || mode == 2 || mode == 8 || mode == 7) {
        r = TRUE;
    }
    return r;
}

static inline BOOL fn_1_148950_mode_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}

static inline BOOL fn_1_148950_mode_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148950_mode_4_5(mode) && mode != 9) r = FALSE;
    return r;
}

static inline BOOL fn_1_148950_mode_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148950_mode_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}

static inline BOOL fn_1_148950_mode_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148950_mode_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

void fn_1_148950(s32 mode, const fn_1_148950_Row *row) {
    FontDrawPacket packet;
    char buf[0x100];
    s32 x;
    s32 y;
    u8 diff;

    packet = lbl_1_rodata_9318;
    packet.image = 0x9700;
    packet.x = (0x1AB + row->unk_68 + row->unk_74);
    packet.y = (row->unk_64 + 14);
    if (mode == 3) {
        packet.x += -10.0f;
    }
    packet.z = 47.0f;
    fn_1_4F734(&packet);
    x = mode == 3 ? 445 : 455;
    y = row->unk_64 + 12;
    if (!fn_1_148950_mode_1_3(mode) && row->unk_5C == 0xFF) {
        fn_1_49410();
        fn_1_494DC(0x15);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        fn_1_496FC((row->unk_74 + 0x1C0), y);
        fn_1_4954C(47.0f);
        fn_1_4955C(0.8f, 1.0f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_4A0D8("RUNNING");
    } else if (!fn_1_148950_mode_1_3(mode) && row->unk_5C == 0xFE) {
        fn_1_49410();
        fn_1_494DC(0x15);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        fn_1_496FC((row->unk_74 + 0x1C0), y);
        fn_1_4954C(47.0f);
        fn_1_4955C(0.8f, 1.0f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_4A0D8("DISQUALIFIED");
    } else if (fn_1_148950_mode_0_2_7_8(mode) || fn_1_148950_mode_4_5_6_9_10(mode)) {
        if (fn_1_148950_mode_4_5_6_9_10(mode)) {
            switch (lbl_1_bss_8E559) {
            case 0:
            default:
                sprintf(buf, "%02d:%02d;%03d", (row->unk_30 >> 20) & 0xFF,
                        (row->unk_30 >> 12) & 0xFF, row->unk_30 & 0xFFF);
                break;
            case 1:
                sprintf(buf, "%04d", row->unk_40);
                packet = lbl_1_rodata_9318;
                packet.image = 0x9704;
                packet.x = (row->unk_74 + (row->unk_68 + 0x205));
                packet.y = (row->unk_64 + 21);
                packet.z = 47.0f;
                fn_1_4F734(&packet);
                break;
            case 2:
                sprintf(buf, "%02d:%02d;%03d", (row->unk_3C >> 20) & 0xFF,
                        (row->unk_3C >> 12) & 0xFF, row->unk_3C & 0xFFF);
                break;
            }
        } else {
            sprintf(buf, "%02d:%02d;%03d", (row->unk_30 >> 20) & 0xFF,
                    (row->unk_30 >> 12) & 0xFF, row->unk_30 & 0xFFF);
        }
        fn_1_49410();
        fn_1_494DC(0x12);
        fn_1_495B0(0x80000000);
        fn_1_496FC((row->unk_74 + 0x1C0), y);
        fn_1_49738(fn_1_149C2C);
        fn_1_4954C(47.0f);
        fn_1_4A0D8(buf);
    } else {
        fn_1_49410();
        fn_1_494DC(0x12);
        fn_1_496FC((x + row->unk_74), y);
        fn_1_49738(fn_1_149C2C);
        fn_1_4954C(47.0f);
        fn_1_4AE0C("%04d", row->unk_54);
        packet = lbl_1_rodata_9318;
        packet.image = 0x9721;
        packet.x = (0x42 + x + row->unk_74);
        packet.y = (row->unk_64 + 15);
        packet.z = 47.0f;
        fn_1_4F734(&packet);
        if (row->unk_60 != row->unk_61) {
            packet = lbl_1_rodata_92C0;
            packet.x = (row->unk_70 + 24);
            packet.y = (row->unk_64 + 12);
            packet.z = 40.0f;
            packet.alpha = lbl_801A66A4 % 60 > 30 ? 1.0f : 0.0f;
            if (row->unk_60 < row->unk_61) {
                packet.image = 0x9702;
                fn_1_4F734(&packet);
                diff = row->unk_61 - row->unk_60;
            } else {
                packet.image = 0x9701;
                fn_1_4F734(&packet);
                diff = row->unk_60 - row->unk_61;
            }
            fn_1_49410();
            fn_1_494DC(0x1A);
            fn_1_496FC((row->unk_70 + 24), (row->unk_64 + 28));
            fn_1_49738(fn_1_149BF4);
            fn_1_4954C(47.0f);
            fn_1_4AE0C("%2d", diff);
        }
    }
}
/* fzgx:end fn_1_148950 */

/* fzgx:begin fn_1_1490FC */
/* GC/2.5: retail loads row->unk_74 between `mflr` and the LR save, which 1.3.2 never schedules; 2.5 does for
 * a __restrict parameter */

void fn_1_1490FC(s32 mode, fn_1_1490FC_Row *__restrict row) {
    s32 n;
    s32 x = row->unk_74 + 0x21D;
    s32 y = row->unk_64 - 4;
    FontDrawPacket packet;

    if (mode == 3 && (n = row->unk_62) >= 1) {
        packet = lbl_1_rodata_9318;
        packet.image = 0x9908;
        packet.x = x;
        packet.y = y;
        packet.z = 46.0f;
        fn_1_4F734(&packet);
        packet = lbl_1_rodata_9318;
        packet.image = 0x990C;
        packet.x = (x + 11);
        packet.y = (y + 12);
        packet.z = 45.0f;
        fn_1_4F734(&packet);
        fn_1_49410();
        fn_1_494DC(0x1F);
        fn_1_495C8((void *)1);
        fn_1_496FC((x + 0x22), (y + 0x18));
        fn_1_4954C(44.0f);
        fn_1_49738(fn_1_149C2C);
        fn_1_4AE0C("%d", n >= 99 ? 99 : n);
    }
}
/* fzgx:end fn_1_1490FC */

/* fzgx:begin fn_1_1492E0 */
/* Shared literal pool layout of the TU (lbl_1_rodata_92C0 .. +0x54C): tables and
   the literals this function reads, in retail order. */

#define FONT_SETUP(n)            \
    fn_1_49410();                \
    fn_1_494DC(n);               \
    fn_1_495B0(0x80000000);      \
    fn_1_49590(0.5f);            \
    fn_1_4955C(0.8f, 0.8f)

static inline s32 fn_1_1492E0_range(s32 mode) {
    s32 result = 1;
    if (!((u32)(mode - 4) <= 1)) result = 0;
    return result;
}

static inline s32 fn_1_1492E0_mode9(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_range(mode) && mode != 9) result = 0;
    return result;
}

static inline s32 fn_1_1492E0_mode10(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_mode9(mode) && mode != 10) result = 0;
    return result;
}

static inline s32 fn_1_1492E0_visible(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_mode10(mode) && mode != 6) result = 0;
    return result;
}

void fn_1_1492E0(s32 arg0, void *arg1) {

    char buf[256];
    struct fn_1_1492E0_Copy88 packet;
    struct Results56 a;
    struct Results56 b;
    struct Results56 c;
    s32 pos;
    s32 x;
    s32 y;
    s32 z;
    s32 i;

    if (fn_1_1492E0_visible(arg0)) {
        packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9726;
        fn_1_51678((FontDrawPacket *)&packet, 0x9726, 0, 0, 87, 40);
        ((f32 *)packet.a)[1] = 74.0f;
        ((f32 *)packet.a)[2] = 92.0f;
        ((f32 *)packet.a)[3] = 60.0f;
        fn_1_4F734((void *)((FontDrawPacket *)&packet));
        for (i = 0, pos = 161; i < 9; i++, pos += 40) {
            packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9726;
            fn_1_51678((FontDrawPacket *)&packet, packet.a[0], 47, 0, 40, 40);
            ((f32 *)packet.a)[1] = pos;
            ((f32 *)packet.a)[2] = 92.0f;
            ((f32 *)packet.a)[3] = 60.0f;
            fn_1_4F734((void *)((FontDrawPacket *)&packet));
        }
        packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9726;
        fn_1_51678((FontDrawPacket *)&packet, 0x9726, 87, 0, 45, 40);
        ((f32 *)packet.a)[1] = pos;
        ((f32 *)packet.a)[2] = 92.0f;
        ((f32 *)packet.a)[3] = 60.0f;
        fn_1_4F734((void *)((FontDrawPacket *)&packet));
        fn_1_156218(*((u8 *)arg1 + 0x34), &a, &b, &c);
        if (lbl_1_bss_8E559 == 0) { x = -1; y = 115; z = 319; }
        if (lbl_1_bss_8E559 == 1) { x = 101; y = -1; z = 326; }
        if (lbl_1_bss_8E559 == 2) { x = 106; y = 341; z = -1; }
        if (x != -1) { FONT_SETUP(21); fn_1_496FC((f32)x, 105.0f); fn_1_4AE0C("TOTAL TIME"); }
        if (y != -1) { FONT_SETUP(21); fn_1_496FC((f32)y, 105.0f); fn_1_4AE0C("MAX SPEED"); }
        if (z != -1) { FONT_SETUP(21); fn_1_496FC((f32)z, 105.0f); fn_1_4AE0C("BEST LAP"); }
        if (x != -1) {
            FONT_SETUP(18);
            sprintf(buf, "%02d:%02d;%03d", (a.a[0] >> 20) & 255, (a.a[0] >> 12) & 255, a.a[0] & 4095);
            fn_1_496FC((x + 106), 105.0f);
            fn_1_4A0D8(buf);
        }
        if (y != -1) {
            FONT_SETUP(18);
            sprintf(buf, "  %04d", *(u16 *)((u8 *)&b + 0x18));
            fn_1_496FC((y + 89), 105.0f);
            fn_1_4A0D8(buf);
            packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9704;
            ((f32 *)packet.a)[1] = (y + 156);
            ((f32 *)packet.a)[2] = 110.0f;
            fn_1_4F734((void *)((FontDrawPacket *)&packet));
        }
        if (z != -1) {
            FONT_SETUP(18);
            sprintf(buf, "%02d:%02d;%03d", (c.a[1] >> 20) & 255, (c.a[1] >> 12) & 255, c.a[1] & 4095);
            fn_1_496FC((z + 101), 105.0f);
            fn_1_4A0D8(buf);
        }
    }
}
/* fzgx:end fn_1_1492E0 */

/* fzgx:begin fn_1_1498B8 */

void fn_1_1498B8(s32 arg0, f32 arg6, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct fn_1_1498B8_Copy88 loc_8;
    if (((struct fn_1_1498B8_lbl_801A66A4 *)&lbl_801A66A4)->unk_0 - lbl_1_bss_8E528 >= lbl_1_bss_8E554 && arg0 != 5) {
        if (arg6 < (lbl_1_bss_8E550 - arg1)) {
            loc_8 = *(struct fn_1_1498B8_Copy88 *)&lbl_1_rodata_26F8;
            loc_8.a[0] = 0x971C;
            fn_1_51678((FontDrawPacket *)&loc_8, (*((0) + loc_8.a)), 20, 0, 20, 12);
            *(f32 *)((u8 *)&loc_8 + 4) = 302.0f;
            {
                s32 v7 = arg1 * arg2 - 6;
                v7 += arg5;
                *(f32 *)((u8 *)&loc_8 + 8) = (f32)(arg3 + v7);
            }
            *(f32 *)((u8 *)&loc_8 + 12) = 50.0f;
            *(f32 *)((u8 *)&loc_8 + 44) = ((struct fn_1_1498B8_lbl_801A66A4 *)&lbl_801A66A4)->unk_0 % 60 > 30 ? 1.0f : 0.0f;
            fn_1_4F734((void *)((FontDrawPacket *)&loc_8));
        }
        if (arg6 > 0.0f) {
            loc_8 = *(struct fn_1_1498B8_Copy88 *)&lbl_1_rodata_26F8;
            loc_8.a[0] = 0x971C;
            fn_1_51678((FontDrawPacket *)&loc_8, (*((0) + loc_8.a)), 0, 0, 20, 12);
            *(f32 *)((u8 *)&loc_8 + 4) = 302.0f;
            *(f32 *)((u8 *)&loc_8 + 8) = (f32)(arg3 - 16 + arg4);
            *(f32 *)((u8 *)&loc_8 + 12) = 50.0f;
            *(f32 *)((u8 *)&loc_8 + 44) = ((struct fn_1_1498B8_lbl_801A66A4 *)&lbl_801A66A4)->unk_0 % 60 > 30 ? 1.0f : 0.0f;
            fn_1_4F734((void *)((FontDrawPacket *)&loc_8));
        }
    }
}
/* fzgx:end fn_1_1498B8 */

/* fzgx:begin fn_1_149B24 */
void fn_1_149B24(const FontDrawPacket *packet, FontVertex *vertices) {
    f32 increment = 5.0f;

    vertices[0].x += increment;
    vertices[1].x += increment;
    fn_1_149C2C(packet, vertices);
}
#undef FONT_SETUP
/* fzgx:end fn_1_149B24 */

/* fzgx:begin fn_1_149B64 */
// Rebuild the display state and publish the current display and effect IDs.

void fn_1_149B64(const FontDrawPacket *packet, FontVertex *vertices) {
    u32 display_id;
    u32 effect_id;

    fn_1_149CA4(lbl_1_bss_8E434, lbl_1_bss_8E43C, lbl_1_bss_8E438, lbl_1_bss_8E440);
    fn_1_5233C((void *)packet, vertices);

    display_id = fn_1_A5DB0() & 0xffff;
    effect_id = fn_1_A5D88() & 0xffff;
    fn_80074188(0, 0, effect_id, display_id);

    fn_1_149C2C(packet, vertices);
}
/* fzgx:end fn_1_149B64 */

/* fzgx:begin fn_1_149BF4 */
// Load four values from BSS table and pass to fn_1_149CA4.

void fn_1_149BF4(const FontDrawPacket *packet, FontVertex *vertices) {
    fn_1_149CA4(lbl_1_bss_8E42C, lbl_1_bss_8E43C, lbl_1_bss_8E430, lbl_1_bss_8E440);
}
/* fzgx:end fn_1_149BF4 */

/* fzgx:begin fn_1_149C2C */
// Forward the four current static-display values to the display-update routine.

void fn_1_149C2C(const FontDrawPacket *packet, FontVertex *vertices) {
    fn_1_149CA4(lbl_1_bss_8E434, lbl_1_bss_8E43C, lbl_1_bss_8E438, lbl_1_bss_8E440);
}
/* fzgx:end fn_1_149C2C */

/* fzgx:begin fn_1_149C64 */
// Initialize the static display state with the default viewport dimensions.

void fn_1_149C64(const FontDrawPacket *packet, FontVertex *vertices) {
    fn_1_149CA4(0, lbl_1_bss_8E43C, 640, lbl_1_bss_8E440);
}
/* fzgx:end fn_1_149C64 */

/* fzgx:begin fn_1_149CA4 */
void fn_1_149CA4(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_1_520A0();
    fn_1_52070(0x140);
    fn_80074188(__cvt_fp2unsigned(fn_1_520F8(arg0)),
                __cvt_fp2unsigned((arg1 * (fn_1_A5DB0() & 0xffff)) / 480.0f),
                __cvt_fp2unsigned(fn_1_521B8(arg2)),
                __cvt_fp2unsigned((arg3 * (fn_1_A5DB0() & 0xffff)) / 480.0f));
    fn_1_520CC();
}
/* fzgx:end fn_1_149CA4 */

/* fzgx:begin fn_1_149DA4 */
void fn_1_149DA4(void) {
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(4, (void *)0);
    }
}
/* fzgx:end fn_1_149DA4 */

/* fzgx:begin fn_1_149DE8 */
void fn_1_149DE8(void) {
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(5, (void *)0);
    }
}
/* fzgx:end fn_1_149DE8 */

/* fzgx:begin fn_1_149E2C */
void fn_1_149E2C(void) {
    u32 best;
    u32 most;
    u32 i;
    fn_1_149E2C_Racer *racer;

    lbl_1_bss_8E428 = (u8 *)&lbl_1_bss_3C30 + 0xE;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(2, (void *)0);
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8((void *)9);
    best = 0x0633B063;
    most = 0;
    for (i = 0; i < ((fn_1_149E2C_Sel *)&lbl_1_bss_3C30)->count; i++) {
        racer = &((fn_1_149E2C_Sel *)&lbl_1_bss_3C30)->racers[((fn_1_149E2C_Sel *)&lbl_1_bss_3C30)->order[i]];
        if (racer->unk_E != 0xFE) {
            if (best > racer->unk_38) {
                best = racer->unk_38;
            }
            if (most < racer->unk_18) {
                most = racer->unk_18;
            }
        }
    }
    fn_1_49614();
}
/* fzgx:end fn_1_149E2C */

/* fzgx:begin fn_1_149F04 */
void fn_1_149F04(void) {
    lbl_1_bss_8E428 = (u8 *)&lbl_1_bss_3C30 + 0x1394;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(3, (void *)0);
    }
}
/* fzgx:end fn_1_149F04 */

/* fzgx:begin fn_1_149F5C */
void fn_1_149F5C(void) {
    lbl_1_bss_8E428 = (u8 *)&lbl_1_bss_3C30 + 0xE;
    if (lbl_1_bss_8E51D != lbl_1_bss_8E524) {
        return;
    }
    fn_1_144F40(7, (void *)0);
}
/* fzgx:end fn_1_149F5C */

/* fzgx:begin fn_1_149FB4 */
u32 fn_1_149FB4(s32 index) {
    u8 *entry = (u8 *)&lbl_1_bss_26314 + index * 0x1fc;

    if (lbl_1_bss_3C30.unk_5 == 2) {
        return fn_1_155F8C();
    }

    return entry[0x115];
}
/* fzgx:end fn_1_149FB4 */

/* fzgx:begin fn_1_14A000 */
// fn_1_14A000: empty in retail (single blr).

void fn_1_14A000(void) {
}
/* fzgx:end fn_1_14A000 */

/* fzgx:begin fn_1_14A004 */
// fn_1_14A004: empty in retail (single blr).

void fn_1_14A004(void) {
}
/* fzgx:end fn_1_14A004 */

/* fzgx:begin fn_1_14A008 */
// fn_1_14A008: empty in retail (single blr).

void fn_1_14A008(void) {
}

/* Unknown retail objects: .rodata 9810..9827, no retail function reads them (after fn_1_1498B8's literals, at the end
   of the TU's .rodata: the leftovers of stripped code) */
static const u32 lbl_1_rodata_9810[2] = { 0xFA00, 0xFA00 };
static const f32 lbl_1_rodata_9818[4] = { 550.0f, 0.4f, 11.0f, 580.0f };
/* fzgx:end fn_1_14A008 */

/* fzgx:begin fn_1_14A00C */
void fn_1_14A00C(void) {
    lbl_1_bss_8E520 = 1;
    lbl_1_bss_8E524 = 0xff;
}
/* fzgx:end fn_1_14A00C */
