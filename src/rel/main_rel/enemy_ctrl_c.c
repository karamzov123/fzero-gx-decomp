#include "types.h"
#include "rel/main_rel/globals.h"

#include "rel/main_rel/enemy_ctrl.h"
#include "font.h"
#include "dolphin/hw_regs.h"
#include "lc_mtx.h"

/* _prologue */
typedef signed short s16;

/* _prologue */
typedef unsigned long u32;

/* _prologue */
typedef unsigned short u16;

/* _prologue */
typedef signed long s32;

/* _prologue */
typedef unsigned char u8;

/* _prologue */
typedef float f32;

/* _prologue */
typedef double f64;

/* _prologue */
typedef struct Actor {
    u8 pad_0[0x118];
    s32 unk_118;
    u8 pad_11C[0x58];
    u8 min;
    u8 sec;
    u16 ms;
    u8 pad_178[0x74];
    u8 best_min;
    u8 best_sec;
    u16 best_ms;
} Actor;

/* _prologue */
typedef struct Sprite {
    s32 used;
    u8 pad_4[2];
    s16 state;
    FontDrawPacket packet;
    u8 pad_60[0x18];
    void (*func)(void *);
    u32 unk_7C;
} Sprite;

/* _prologue */
struct FzgxCopy_88 { u32 words[22]; };

/* _prologue */
typedef struct {
    s32 *unk_0;
    f32 *unk_4;
    u8 *unk_8;
    u8 *unk_C;
    u32 unk_10;
    u32 unk_14;
} HudSource;

/* _prologue */
typedef struct {
    u32 flags;
    f32 steer;
    f32 unk_8;
    f32 throttle;
    f32 unk_10;
    f32 unk_14;
    f32 target;
    f32 lateral;
    f32 prev_lateral;
    f32 unk_24;
    u8 state;
    u8 next_state;
    u8 rival;
    u8 zone;
    u8 state_timer;
    u8 unk_2D;
    u8 unk_2E;
    u8 timer;
    u8 blink;
    u8 lane;
    u8 pad_32[2];
    u8 unk_34;
    u8 spin_timer;
    u8 zone_type;
    u8 start_delay;
    u8 param;
    u8 cooldown;
    u8 unk_3A;
    u8 pad_3B;
    u32 unk_3C;
    u8 pad_40[4];
    f32 last_pos;
} CpuBlock;

/* _prologue */
typedef struct {
    u32 flags;
    s16 id;
    u8 pad_6[0x16];
    f32 unk_1C;
    u8 pad_20[0x5C];
    f32 pos[3];
    u8 pad_88[0x64];
    f32 mtx[3][4];
    u8 pad_11C[0x60];
    f32 unk_17C;
    u8 pad_180[4];
    f32 speed;
    u8 pad_188[2];
    u8 unk_18A;
    u8 pad_18B[0x31];
    f32 unk_1BC[3];
    u8 pad_1C8[0x2BC];
    CpuBlock *ai;
    u8 pad_488[0x620 - 0x488];
} Machine;

/* _prologue */
typedef struct {
    u8 pad_0[0x7C];
    u32 unk_7C;
    u8 pad_80[4];
    f32 unk_84;
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x68];
    f32 unk_F8;
    u8 pad_FC[4];
    f32 unk_100;
    u16 unk_104;
    u8 pad_106[2];
    f32 unk_108;
    u8 pad_10C[9];
    u8 unk_115;
    u8 pad_116[2];
    s32 unk_118;
} Progress;

/* _prologue */
typedef struct fn_1_C771C_EnemyCtrl {
    u8 pad_000[0x118];
    int field_118;
    u8 pad_11c[0xd0];
    u8 field_1ec;
    u8 field_1ed;
    u16 field_1ee;
} fn_1_C771C_EnemyCtrl;

/* _prologue */
typedef struct fn_1_C72D4_EnemyCtrl {
    unsigned char pad_000[0x118];
    int field_118;
    unsigned char pad_11c[0xd0];
    unsigned char field_1ec;
    unsigned char field_1ed;
    unsigned short field_1ee;
} fn_1_C72D4_EnemyCtrl;

/* _prologue */
struct CB6D8Color { u8 r, g, b, a; };

/* _prologue */
struct CB6D8Packet {
    s32 glyph;
    f32 x, y, z, width, height;
    u32 unk18, unk1C, unk20, unk24, unk28;
    f32 scale;
    u32 mode, unk34;
    struct CB6D8Color color;
    u32 flags;
    u32 unk40, unk44, unk48, unk4C, unk50, unk54;
};

/* _prologue */
struct fn_1_CBC24_Copy88 { u32 a[1]; f32 x, y, z; u32 rest[18]; };

/* _prologue */
typedef struct fn_1_D07E0_FontVertex {
f32 x, y, z;
} fn_1_D07E0_FontVertex;

/* _prologue */
typedef struct fn_1_D07E0_FontDrawPacket fn_1_D07E0_FontDrawPacket;

/* _prologue */
struct fn_1_D07E0_FontDrawPacket {
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
fn_1_D07E0_FontDrawPacket* secondary;
void (*vertex_callback)(fn_1_D07E0_FontDrawPacket* packet, fn_1_D07E0_FontVertex* vertices);
u32 unk_54;
};

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_5CD4 { f32 unk_0; };

/* _prologue */
struct fn_1_CC280_lbl_1_rodata_5C00 {
    f64 unk_0;
};

/* _prologue */
typedef struct EnemyCtrlEntry {
    s16 x;
    s16 y;
    f32 scale;
    s16 ofs_x;
    s16 ofs_y;
} EnemyCtrlEntry;

/* _prologue */
typedef struct {
	s16 x;
	s16 y;
	f32 scale;
	s16 ofs_x;
	s16 ofs_y;
} fn_1_C6F8C_Entry;

/* _prologue */
typedef struct {
	fn_1_C6F8C_Entry entries[6];
} fn_1_C6F8C_Msg;

/* _prologue */
typedef struct fn_1_C742C_FontVertex {
f32 x, y, z;
} fn_1_C742C_FontVertex;

/* _prologue */
typedef struct fn_1_C742C_FontDrawPacket fn_1_C742C_FontDrawPacket;

/* _prologue */
struct fn_1_C742C_FontDrawPacket {
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
fn_1_C742C_FontDrawPacket* secondary;
void (*vertex_callback)(fn_1_C742C_FontDrawPacket* packet, fn_1_C742C_FontVertex* vertices);
u32 unk_54;
};

/* _prologue */
typedef struct fn_1_C7CBC_FontVertex {
f32 x, y, z;
} fn_1_C7CBC_FontVertex;

/* _prologue */
typedef struct fn_1_C7CBC_FontDrawPacket fn_1_C7CBC_FontDrawPacket;

/* _prologue */
struct fn_1_C7CBC_FontDrawPacket {
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
fn_1_C7CBC_FontDrawPacket* secondary;
void (*vertex_callback)(fn_1_C7CBC_FontDrawPacket* packet, fn_1_C7CBC_FontVertex* vertices);
u32 unk_54;
};

/* _prologue */
typedef struct fn_1_CD7BC_FontVertex {
f32 x, y, z;
} fn_1_CD7BC_FontVertex;

/* _prologue */
typedef struct fn_1_CD7BC_FontDrawPacket fn_1_CD7BC_FontDrawPacket;

/* _prologue */
struct fn_1_CD7BC_FontDrawPacket {
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
fn_1_CD7BC_FontDrawPacket* secondary;
void (*vertex_callback)(fn_1_CD7BC_FontDrawPacket* packet, fn_1_CD7BC_FontVertex* vertices);
u32 unk_54;
};

/* _prologue */
typedef void (*fn_1_C742C_DrawFunc)(s32, s32, s32);
typedef struct fn_1_C742C_Funcs { fn_1_C742C_DrawFunc f[6]; } fn_1_C742C_Funcs;

/* _prologue */
typedef struct fn_1_C742C_Vec {
f32 x;
f32 y;
f32 z;
} fn_1_C742C_Vec;

/* _prologue */
typedef struct fn_1_C742C_Offsets { fn_1_C742C_Vec v[3][4]; } fn_1_C742C_Offsets;

/* _prologue */
typedef struct fn_1_C742C_Positions { fn_1_C742C_Vec v[3][6]; } fn_1_C742C_Positions;

/* _prologue */
typedef struct fn_1_C742C_Values { s32 v[6]; } fn_1_C742C_Values;

/* _prologue */
struct fn_1_C7874_lbl_1_rodata_5C08 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
};

/* _prologue */
struct fn_1_CD36C_lbl_1_rodata_5C48 {
    f32 unk_0;
};

/* _prologue */
struct fn_1_C7AA0_lbl_1_rodata_5C4C {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
};

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_5C88 { f32 unk_0; };

/* _prologue */
typedef struct EnemyCtrlFace {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x10];
    s32 unk_18;
    u8 pad_1C[0x1C];
    u32 unk_38;
    u32 unk_3C;
    u8 pad_40[0x20];
    u32 unk_60;
} EnemyCtrlFace;

/* _prologue */
struct fn_1_CFCA4_Copy88 { u32 a[22]; };

/* _prologue */
typedef struct EnemyCtrl_CA218 {
    u32 value;
    u8 pad4[2];
    s16 state;
    u32 action;
} EnemyCtrl_CA218;

/* _prologue */
struct fn_1_CA440_5D70 {
    u32 a[4];
};

/* _prologue */
typedef struct {
    u8 r, g, b, a;
} CB028Color;

/* _prologue */
struct fn_1_CB6D8_lbl_1_rodata_5E28 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C;
    u32 unk_10; u32 unk_14; u32 unk_18; u32 unk_1C;
    u32 unk_20; u32 unk_24;
};

/* _prologue */
struct fn_1_CB6D8_lbl_1_rodata_5E50 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C;
    u32 unk_10; u32 unk_14; u32 unk_18; u32 unk_1C;
    u32 unk_20; u32 unk_24; u32 unk_28; u32 unk_2C;
};

/* _prologue */
struct fn_1_CBC24_Copy40 { u32 a[10]; };

/* _prologue */
struct fn_1_CC280_lbl_1_rodata_5EC0 {
    u32 unk_0[10];
};

/* _prologue */
typedef struct fn_1_CD6C0_object {
    s32 flags;
    u16 pad4;
    s16 state;
    u8 pad8[0x2c];
    f32 value;
    u8 pad38[0x28];
    void *controller;
} fn_1_CD6C0_object;

/* _prologue */
typedef struct {
    u8 pad_0[0x1E0];
    u8 min;
    u8 sec;
    u16 ms;
} ClearRecord;

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_5FD8 { f32 unk_0; };

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_602C { u32 unk_0; };

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_6030 { u32 unk_0; };

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_6038 { u32 unk_0; };

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_603C { f32 unk_0; };

/* _prologue */
struct fn_1_CFCA4_lbl_1_rodata_6050 { f32 unk_0; };

/* _prologue */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u16 unk_2;
    u8 pad_4[0x14];
    u16 unk_18;
} fn_1_D0428_Record;

/* _prologue */
struct fn_1_D07E0_lbl_1_bss_7ACD0 { s32 unk_0; u32 unk_4; };

/* _prologue */
typedef struct {
f32 x;
f32 y;
f32 z;
} Fn183D28Vec3;

/* _prologue */
typedef struct {
f32 value0;
f32 value1;
f32 value2;
} Sig_fn_8006F78C_Fn8006F78CData;

/* _prologue */
struct fn_1_D0E74_lbl_1_rodata_6080 {
    f64 unk_0;
};

/* _prologue */
struct Sig_fn_8003432C_fn_8003432C_Arg2 {
    u32 unk_0;
};

/* _prologue */
struct Sig_GXPeekZ_GXPeekZ_Arg2 {
    u32 unk_0;
};

/* _prologue */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

/* _prologue */
typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} LoadEntry;

/* _prologue */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    LoadEntry entry;
} LoadResult;

/* fn_1_C489C */
struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 {
    u8 unk_0;
    u8 pad_1[2];
    u8 unk_3;
    u8 pad_4[4];
    u32 unk_8;
};

/* fn_1_C489C */
struct fn_1_C489C_lbl_1_rodata_5168 {
    u8 pad_0[0x40];
    struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 unk_40[41];
};

/* fn_1_C4ABC */
typedef struct {
    u32 zone;
    f32 pos[3];
    u32 mask;
} CpuSlot;

/* fn_1_C4ABC */
typedef struct {
    f32 start;
    f32 end;
    f32 left;
    f32 right;
    u8 type;
    u8 group;
    u8 pad_12[2];
} CpuZone;

/* fn_1_C4ABC */
typedef struct {
    u32 unk_0[30];
    u32 unk_78[30];
    u32 unk_F0[30];
    u32 unk_168[30];
    u8 unk_1E0[30];
    u8 unk_1FE[30];
} CpuPairs;

/* fn_1_C4ABC */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
} CpuLevel;

/* fn_1_C4ABC */
typedef struct {
    u8 lane;
    u8 boost;
    u8 shuffle;
    u8 unk_3;
    u8 attack;
    u8 speed;
    u8 unk_6;
    u8 unk_7;
    u32 flags;
} CpuParams;

/* fn_1_C4ABC */
typedef struct {
    u8 pad_0[0x90];
    f32 *unk_90;
} Course;

/* fn_1_C4ABC */
typedef struct {
    u32 unk_0;
    u8 unk_4;
} GameState;

/* fn_1_C6ED4 */
typedef struct Fn1C6ED4Data {
    u32 flags;
    f32 value_4;
    f32 value_8;
    f32 value_c;
    f32 value_10;
    f32 value_14;
} Fn1C6ED4Data;

/* fn_1_C6ED4 */
typedef struct Fn1C6ED4Enemy {
    u32 flags;
    u8 pad_4[0x1f0];
    f32 output_1f4;
    f32 output_1f8;
    f32 output_1fc;
    f32 output_200;
    f32 output_204;
    u8 pad_208[0x27c];
    Fn1C6ED4Data *data;
} Fn1C6ED4Enemy;

/* fn_1_C6F8C */
typedef struct {
	u8 pad_0[0x2B4];
	u32 w[4];
	f32 unk_2C4;
	f32 unk_2C8;
	f32 unk_2CC;
	f32 unk_2D0;
	f32 unk_2D4;
	f32 unk_2D8;
	f32 unk_2DC;
} fn_1_C6F8C_Ctrl;

/* fn_1_C7224 */
typedef struct {
    u8 padding[0x94];
    u32 flags;
} Fn1C7224State;

/* fn_1_C742C */
typedef signed char s8;

/* fn_1_C7874 */
struct fn_1_C7874_Copy88 { u32 a[22]; };

/* fn_1_C7AA0 */
struct fn_1_C7AA0_Copy88 { u32 a[22]; };

/* fn_1_C8DC0 */
typedef struct Color {
    u8 r, g, b, a;
} Color;

/* fn_1_CA2A4 */
typedef struct {
    u32 x[22];
} fn_1_CA2A4_LocalData;

/* fn_1_CA440 */
struct fn_1_CA440_lbl_1_data_3D544 {
    u32 unk_0[1];
};

/* fn_1_CA690 */
typedef struct {
    u32 x[22];
} fn_1_CA690_LocalData;

/* fn_1_CA8FC */
typedef struct {
    u32 words[22];
} fn_1_CA8FC_Copy88;

/* fn_1_CADC4 */
struct fn_1_CADC4_Copy88 { u32 a[22]; };

/* fn_1_CADC4 */
struct fn_1_CADC4_lbl_1_data_3D544 {
    u32 unk_0[1];
};

/* fn_1_CAEBC */
struct fn_1_CAEBC_Copy88 { u32 a[22]; };

/* fn_1_CAEBC */
struct fn_1_CAEBC_lbl_1_data_3D544 {
    u32 unk_0[1];
};

/* fn_1_CB028 */
typedef struct {
    f32 x;
    f32 y;
    f32 scaleX;
    f32 scaleY;
    f32 alpha;
    u32 image;
    s32 index;
    CB028Color color;
    CB028Color color2;
} CB028Sprite;

/* fn_1_CB028 */
typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[4];
    u8 count;
    u8 pad_9[7];
    u32 images[8];
} CB028List;

/* fn_1_CB028 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
} CB028Entry;

/* fn_1_CB424 */
struct Cb424_msg {
	s32 unk_0;
	f32 unk_4;
	f32 unk_8;
	u32 unk_C[19];
};

/* fn_1_CB424 */
union Cb424_col {
	u32 w;
	struct {
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	} c;
};

/* fn_1_CB424 */
struct Cb424_out {
	f32 unk_0;
	f32 unk_4;
	f32 unk_8;
	f32 unk_C;
	f32 unk_10;
	u32 unk_14;
	s32 unk_18;
	union Cb424_col unk_1C;
	union Cb424_col unk_20;
};

/* fn_1_CB6D8 */
struct CB6D8Input {
    f32 x, y, width, height, scale;
    u32 time;
    s32 rank;
    u32 flags;
    struct CB6D8Color color;
};

/* fn_1_CC280 */
struct fn_1_CC280_Copy88 { u32 a[22]; };

/* fn_1_CC280 */
struct fn_1_CC280_lbl_1_data_3D544 {
    u32 unk_0[1];
};

/* fn_1_CD36C */
struct fn_1_CD36C_Copy88 { u32 a[22]; };

/* fn_1_CD51C */
typedef struct {
    u8 pad_0[0x6];
    u16 unk_6;
    u32 unk_8;
    f32 unk_c;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1c;
    u8 pad_20[0x18];
    u32 unk_38;
    f32 unk_3c;
    GXColor unk_40;
    u8 pad_44[0x1c];
    void *unk_60;
    u8 pad_64[0x14];
    void (*unk_78)(void);
} Fn1Cd51cObject;

/* fn_1_CD6C0 */
typedef struct fn_1_CD6C0_target {
    u8 pad0[0x10c];
    s32 flags;
} fn_1_CD6C0_target;

/* fn_1_CEB38 */
typedef struct {
    u8 r, g, b, a;
} fn_1_CEB38_Color;

/* fn_1_CFA4C */
struct fn_1_CFA4C_Copy88 { u32 a[22]; };

/* fn_1_CFF94 */
struct fn_1_CFF94_Copy88 { u32 a[22]; };

/* fn_1_D0428 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x145D];
    u32 unk_1464;
    u8 pad_1468[0x50];
} fn_1_D0428_Setup;

/* fn_1_D07C4 */
struct fn_1_D07C4_lbl_1_bss_7ACA0_0_E12 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x4];
};

/* fn_1_D07C4 */
struct fn_1_D07C4_lbl_1_bss_7ACA0 {
    struct fn_1_D07C4_lbl_1_bss_7ACA0_0_E12 unk_0[1];
};

/* fn_1_D07E0 */
typedef struct {
u32 unk_0;
u8 unk_4;
u8 unk_5;
u8 unk_6;
u8 unk_7;
u8 unk_8;
u8 unk_9;
u8 pad_A[0x3];
u8 unk_D;
u8 unk_E;
u8 unk_F;
u8 pad_10[0x1C];
u32 unk_2C;
u8 pad_30[0x74];
u16 unk_A4;
u8 unk_A6;
u8 unk_A7;
u8 pad_A8[0x2C];
u32 unk_D4;
u16 unk_D8;
u16 unk_DA;
u8 unk_DC;
u8 unk_DD;
u8 unk_DE;
u8 unk_DF;
u8 unk_E0;
u8 unk_E1;
u8 unk_E2;
u8 pad_E3[0x4];
u8 unk_E7;
u8 pad_E8[0x4];
u16 unk_EC;
u8 pad_EE[0xA];
u32 unk_F8;
u8 pad_FC[0x10];
u32 unk_10C;
u8 pad_110[0x10];
u16 unk_120;
u16 unk_122;
u16 unk_124;
u16 unk_126;
u16 unk_128;
u8 pad_12A[0x2];
u32 unk_12C;
u8 pad_130[0x1C];
u32 unk_14C;
u8 pad_150[0x4];
u8 unk_154;
u8 unk_155;
u8 unk_156;
u8 unk_157;
u8 pad_158[0x1A];
u16 unk_172;
u8 pad_174[0x4];
u16 unk_178;
u8 pad_17A[0x1];
u8 unk_17B;
u8 unk_17C;
u8 pad_17D[0x7A];
u8 unk_1F7;
u8 pad_1F8[0x20];
u16 unk_218;
u8 pad_21A[0x2];
u8 unk_21C;
u8 pad_21D[0x7A];
u8 unk_297;
u8 pad_298[0x20];
u16 unk_2B8;
u8 pad_2BA[0x2];
u8 unk_2BC;
u8 pad_2BD[0x7A];
u8 unk_337;
u8 pad_338[0x20];
u16 unk_358;
u8 pad_35A[0x2];
u8 unk_35C;
u8 pad_35D[0x7A];
u8 unk_3D7;
u8 pad_3D8[0x20];
u16 unk_3F8;
u8 pad_3FA[0x2];
u8 unk_3FC;
u8 pad_3FD[0x7A];
u8 unk_477;
u8 pad_478[0xF1C];
u8 unk_1394;
u8 pad_1395[0x1F];
u32 unk_13B4;
u8 pad_13B8[0x1C];
u32 unk_13D4;
u8 pad_13D8[0x1C];
u8 unk_13F4;
u8 unk_13F5;
u8 unk_13F6;
u8 pad_13F7[0x1];
u16 unk_13F8;
u16 unk_13FA;
u16 unk_13FC;
u16 unk_13FE;
u16 unk_1400;
u8 unk_1402;
u8 pad_1403[0x2];
u8 unk_1405;
u8 pad_1406[0x5E];
u32 unk_1464;
u8 pad_1468[0x4];
u8 unk_146C;
u8 unk_146D;
u16 unk_146E;
u8 unk_1470;
u8 pad_1471[0x3];
u32 unk_1474;
u16 unk_1478;
u16 unk_147A;
u16 unk_147C;
u16 unk_147E;
u32 unk_1480;
u32 unk_1484;
u32 unk_1488;
u32 unk_148C;
u32 unk_1490;
u32 unk_1494;
u32 unk_1498;
u32 unk_149C;
u32 unk_14A0;
u32 unk_14A4;
u32 unk_14A8;
u8 pad_14AC[0x10];
} fn_1_D07E0_Obj_1_bss_3C30;

/* fn_1_D0E74 */
struct fn_1_D0E74_lbl_1_data_3D648 {
    u8 pad_0[0x4];
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u8 pad_A[0x16];
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
};

extern void DCInvalidateRange(void *, void *);
extern u32 GXPeekZ(u32, u32, struct Sig_GXPeekZ_GXPeekZ_Arg2 *);
extern void GXPokeAlphaRead(u32 arg0);
extern void OSReport(const char *msg, ...);
extern int __abs(int);
extern f64 __fabs(f64);
extern s32 camera_get_flags(void);
extern s16 camera_get_mode(void);
extern s32 camera_get_state(void);
extern u32 fn_1_101C0(void);
extern void fn_1_128E8C(u8, fn_1_D0428_Record *);
extern s16 fn_1_12C7B8(s16 arg);
extern s16 fn_1_12C930(s16 arg0);
extern void fn_1_12EF80(s16 value, s16 *row, s16 *column);
extern void fn_1_12F4A8(Machine *m);
extern void fn_1_130C84(Machine *car);
extern s32 fn_1_156218(u32 id, void *out0, void *out1, void *out2);
extern f32 fn_1_15E1D0(u32 arg0);
extern void *fn_1_15F618(s32 index);
extern u32 fn_1_214C4(f32 *out, f32 pos, u32 state);
extern void fn_1_3EF14(void *arg1);
extern s16 fn_1_3F0C8(void);
extern u8 *fn_1_3F0D8(u32 index, f32 *value, u8 *flag);
extern u8 fn_1_3F114(void);
extern s32 fn_1_3F164(void);
extern s32 fn_1_3F1D4(void);
extern u32 fn_1_3F7D0(void);
/* The result is an int for its callers: fn_1_CA2A4 and fn_1_CA690 use r3 as it is (no clrlwi), and face.c and
 * accessory.c declare u32 too. Retail's body (lbz, blr) fits both types. game.c still defines it as u8. */
extern u32 fn_1_3F7E0(void);
extern s32 fn_1_40B20(void);
extern int fn_1_45730(void *arg0, LoadResult *result);
extern void fn_1_45850(void *);
extern void fn_1_458A0(void *, void *, void *, u32);
extern u32 fn_1_45B2C(void *);
extern s32 fn_1_45D0();
extern s32 fn_1_465D0(s32 arg0, s32 arg1);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern s32 fn_1_485A8(s32 index);
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_49514(u32 *value);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_495FC(void);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49728(u8 value);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32 value);
extern Sprite *fn_1_4DF60(void);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_4FC50(FontDrawPacket *, u32, u16, u16, u32);
extern void fn_1_51564(s16, s16, s16, s16, s16, s16);
extern void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y);
extern void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height);
extern void fn_1_51914(const FontDrawPacket *);
extern void fn_1_51990(void *obj);
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern void fn_1_51C74(Sprite *);
extern void fn_1_51E60(FontDrawPacket *src);
extern void fn_1_52070(u32 value);
extern void fn_1_52088(void);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern void fn_1_527B4(void);
extern u32 fn_1_52968(u32, u32, const char *, f32, ...);
extern u8 fn_1_5348(void);
extern void fn_1_53830(u32, f32, u8, volatile u8 *, volatile u8 *);  /* fzgx-allow: S2 prototype matches the definition in font.c */
extern u32 fn_1_584AC(void);
extern u32 fn_1_58C4(void);
extern u32 fn_1_5910();
extern s16 fn_1_7B054(void);
extern int fn_1_8623C(void);
extern Progress *fn_1_8627C(s32 index);
extern u32 fn_1_864E8(int index);
extern f32 fn_1_8652C(int index);
extern u8 fn_1_86624(void);
extern u16 fn_1_8664C(int index);
extern s8 fn_1_86690(s8 index);
extern u32 fn_1_8677C(u32 arg0);
extern f32 fn_1_867F8(int index);
extern u8 fn_1_86810(int index);
extern void *fn_1_868C0(s8 index);
extern u8 fn_1_86A10(u32 arg0);
extern f32 fn_1_8CA70(u32 a, s32 b);
extern f32 fn_1_8CAF4(u32 a, s32 b);
extern u16 fn_1_A5DB0(void);
extern void fn_1_A9868(void);
extern void fn_1_A9B70(s16 x, s16 y, s16 w, s16 h, GXColor color);
extern void fn_1_A9FFC(s16 x, s16 y, s16 w, s16 h, GXColor color);
extern void fn_1_AA538(void);
extern EnemyCtrlFace *fn_1_D2D24(s32);
/* The result is signed for its caller: fn_1_C8294 tests it with cmpwi. face.c defines it as u32 (lwz, blr fits both). */
extern s32 fn_1_D2D38(void);
extern u8 fn_1_D2D48(void);
extern EnemyCtrlFace *fn_1_D2D58(s32);
extern s16 fn_1_E5430(s16 index);
extern s16 fn_1_E5568(s16 id);
extern int fn_1_EB0B0(void);
extern void *fn_1_EB0D8(u32 i);
extern void fn_80006E10(u32 arg0);
extern u32 fn_80008E84(u32 arg0);
extern void fn_8003432C(u16 x, u16 y, u32 *color);
extern void fn_8006E250(f32 *src, f32 *dst);
extern void fn_8006E2B0(f32 *src, f32 *dst);
extern void fn_8006F78C(Fn183D28Vec3 *, Sig_fn_8006F78C_Fn8006F78CData *, f32);
extern u32 fn_80071100(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2);
extern f64 fn_80088598(f64, f64);
extern u32 lbl_1_bss_523C[8];
extern u32 lbl_1_bss_8B4EC[32];
extern u32 lbl_1_bss_8B5CC[8];
extern u8 lbl_1_bss_9C;
extern u8 lbl_1_data_2BD54[0xA68];
extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_5C00;
extern f32 lbl_1_rodata_6078;
extern struct fn_1_D0E74_lbl_1_rodata_6080 lbl_1_rodata_6080;
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D188(s32);
extern f32 lbl_8006D21C(u32);
extern s16 lbl_8006D24C(f32 x, f32 y);
extern void lbl_8006DC6C(f32 (*mtx)[4]);
extern void *lbl_801A6410;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern int sprintf(char *s, const char *format, ...);

void fn_1_C47B4(void);
void fn_1_C487C(void *arg0);
void fn_1_C4ABC(Machine *car);
void fn_1_C6ED4(Fn1C6ED4Enemy *self);
u32 fn_1_C6F70(void);
void fn_1_C6F80(u8 value);
void fn_1_C6F8C(void);
void fn_1_C7224(void);
extern void fn_1_C72D4(void);
extern void fn_1_C742C(void);
extern void fn_1_C771C(void);
extern void fn_1_C7874(void);
extern void fn_1_C7AA0(void);
extern void fn_1_C7CBC(s16 arg0, s16 arg1, s16 arg2, s32 arg3, f32 arg4, f32 arg5);
extern s16 fn_1_C8294(const EnemyCtrlEntry *entries, u8 count, s32 flag);
extern void fn_1_C8DC0(s32 arg0);
void fn_1_C96A4(s32 arg0, s32 x, s32 y);
extern void fn_1_CA218(EnemyCtrl_CA218 *self);
extern void fn_1_CA2A4(int);
void fn_1_CA440(s32 arg0, s32 arg1, s32 arg2);
extern void fn_1_CA690(int, int, int);
extern void fn_1_CA8FC();
extern void fn_1_CAB38(u32 arg0, u32 arg1, s32 y);
extern void fn_1_CADC4(int);
void fn_1_CAEBC(s32 arg0, s32 arg1, s32 arg2);
extern void fn_1_CB028(int, int);
void fn_1_CB404(u8 value);
extern void fn_1_CB6D8(void *);
extern void fn_1_CBC24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void fn_1_CC27C(s32 arg0, s32 arg1, s32 arg2);
void fn_1_CC8E4(s32 arg0, s32 arg1, s32 arg2);
void fn_1_CD36C(s32 arg0, s32 arg1, s32 arg2);
extern void fn_1_CD51C(int);
extern void fn_1_CD6C0(fn_1_CD6C0_object *object);
extern void fn_1_CD7BC(int);
extern void fn_1_CDC8C(void);
extern void fn_1_CEB38(void);
extern void fn_1_CF5B0(s32);
extern u32 fn_1_CFA0C();
extern void fn_1_CFA4C(u32, u32);
extern void fn_1_CFB28(s16 unused, f32 value);
extern void fn_1_CFCA4(f32 arg1, f32 arg2, const char *arg0, f32 arg3);
extern void fn_1_CFF94(u32 arg0, s16 arg1, f32 arg2);
extern void fn_1_D01B0(u32 unused1, s16 unused2, f32 farg0);
extern void fn_1_D0428(void);
void fn_1_D0728(u32 arg0, u32 arg1);
void fn_1_D0790(void);
void fn_1_D07AC(u32 index, u32 value);
void fn_1_D07C4(u32 arg0, u32 arg1);
void fn_1_D07E0(f32 arg0, f32 arg1, f32 arg2);
void fn_1_D0D68(s32 arg0);
u32 fn_1_D0D88(void);
u16* fn_1_D0D98(void);
u8* fn_1_D0DA8(void);
u8* fn_1_D0DB8(void);
u8* fn_1_D0DC8(void);
u8* fn_1_D0DD8(void);
u8* fn_1_D0DE8(void);
u16* fn_1_D0DF8(void);
u8* fn_1_D0E08(void);
u16* fn_1_D0E18(void);
Obj_1_data_3D648* fn_1_D0E28(void);
u8* fn_1_D0E34(void);
u8* fn_1_D0E44(void);
u8* fn_1_D0E54(void);
u8* fn_1_D0E64(void);
void fn_1_D0E74(void);
void fn_1_D0F60(void);

extern void fn_1_C489C(void *arg0);
extern void fn_1_CB424();
extern void fn_1_CC280();

/* main scaffold aliases (temporary) */
extern u8 lbl_1_data_3D290__fzgx_offset_0[];
extern u8 lbl_1_data_3D294__fzgx_offset_0[];
extern u8 lbl_1_data_3D2A0__fzgx_offset_0[];
extern u8 lbl_1_data_3D2AC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2B8__fzgx_offset_0[];
extern u8 lbl_1_data_3D2C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2CC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2D4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2DC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2E4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2F0__fzgx_offset_0[];
extern u8 lbl_1_data_3D300__fzgx_offset_0[];
extern u8 lbl_1_data_3D310__fzgx_offset_0[];
extern u8 lbl_1_data_3D318__fzgx_offset_0[];
extern u8 lbl_1_data_3D320__fzgx_offset_0[];
extern u8 lbl_1_data_3D32C__fzgx_offset_0[];
extern u8 lbl_1_data_3D338__fzgx_offset_0[];
extern u8 lbl_1_data_3D348__fzgx_offset_0[];
extern u8 lbl_1_data_3D350__fzgx_offset_0[];
extern u8 lbl_1_data_3D35C__fzgx_offset_0[];
extern u8 lbl_1_data_3D368__fzgx_offset_0[];
extern u8 lbl_1_data_3D378__fzgx_offset_0[];
extern u8 lbl_1_data_3D380__fzgx_offset_0[];
extern u8 lbl_1_data_3D38C__fzgx_offset_0[];
extern u8 lbl_1_data_3D398__fzgx_offset_0[];
extern u8 lbl_1_data_3D3A8__fzgx_offset_0[];
extern u8 lbl_1_data_3D3B0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3BC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D3D0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3E0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3EC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3F8__fzgx_offset_0[];
extern u8 lbl_1_data_3D400__fzgx_offset_0[];
extern u8 lbl_1_data_3D414__fzgx_offset_0[];
extern u8 lbl_1_data_3D424__fzgx_offset_0[];
extern u8 lbl_1_data_3D434__fzgx_offset_0[];
extern u8 lbl_1_data_3D440__fzgx_offset_0[];
extern u8 lbl_1_data_3D44C__fzgx_offset_0[];
extern u8 lbl_1_data_3D45C__fzgx_offset_0[];
extern u8 lbl_1_data_3D464__fzgx_offset_0[];
extern u8 lbl_1_data_3D470__fzgx_offset_0[];
extern u8 lbl_1_data_3D478__fzgx_offset_0[];
extern u8 lbl_1_data_3D480__fzgx_offset_0[];
extern u8 lbl_1_data_3D488__fzgx_offset_0[];
extern u8 fn_1_CB6D8__fzgx_offset_34C[];
extern u8 fn_1_CB6D8__fzgx_offset_364[];
extern u8 fn_1_CB6D8__fzgx_offset_37C[];
extern u8 fn_1_CB6D8__fzgx_offset_388[];
extern u8 fn_1_CB6D8__fzgx_offset_394[];
extern u8 fn_1_CB6D8__fzgx_offset_3A0[];
extern u8 fn_1_CB6D8__fzgx_offset_3AC[];
extern u8 fn_1_CB6D8__fzgx_offset_3B8[];
extern u8 fn_1_CB6D8__fzgx_offset_3C4[];
extern u8 fn_1_CB6D8__fzgx_offset_3D0[];
extern u8 fn_1_CB6D8__fzgx_offset_3E0[];
extern u8 fn_1_CB6D8__fzgx_offset_3F0[];

Obj_1_data_3D648 lbl_1_data_3D648 = {
    0, 320, 240, 240, {0}, 25, 25, 6, 100, 100, {0}, 0xFF000000, 0, 0, 0, 0, {0}
};

/* fzgx:begin fn_1_D0D88 */
u32 fn_1_D0D88(void) {
    return lbl_1_data_3D648.unk_0;
}
/* fzgx:end fn_1_D0D88 */

/* fzgx:begin fn_1_D0D98 */
u16* fn_1_D0D98(void) {
    return &lbl_1_data_3D648.unk_4;
}
/* fzgx:end fn_1_D0D98 */

/* fzgx:begin fn_1_D0DA8 */
// Return the address of the object's 16-bit field at offset 0x6.

u8* fn_1_D0DA8(void) {
    return (u8*)&lbl_1_data_3D648.unk_6;
}
/* fzgx:end fn_1_D0DA8 */

/* fzgx:begin fn_1_D0DB8 */
// Returns the byte address of the object's field at offset 0x8.

u8* fn_1_D0DB8(void) {
    return (u8*)&lbl_1_data_3D648.unk_8;
}
/* fzgx:end fn_1_D0DB8 */

/* fzgx:begin fn_1_D0DC8 */
u8* fn_1_D0DC8(void) {
    return (u8*)&lbl_1_data_3D648 + 0xc;
}
/* fzgx:end fn_1_D0DC8 */

/* fzgx:begin fn_1_D0DD8 */
// Return the address of the enemy-control value at offset 0x10.

u8* fn_1_D0DD8(void) {
    return (u8*)&lbl_1_data_3D648.unk_10;
}
/* fzgx:end fn_1_D0DD8 */

/* fzgx:begin fn_1_D0DE8 */
// Return the address of the object's field at offset 0x12.

u8* fn_1_D0DE8(void) {
    return (u8*)&lbl_1_data_3D648.unk_12;
}
/* fzgx:end fn_1_D0DE8 */

/* fzgx:begin fn_1_D0DF8 */
// Return the enemy-control field at offset 0x14.

u16* fn_1_D0DF8(void) {
    return &lbl_1_data_3D648.unk_14;
}
/* fzgx:end fn_1_D0DF8 */

/* fzgx:begin fn_1_D0E08 */
// Return the address of the enemy-control field at offset 0x16.

u8* fn_1_D0E08(void) {
    return (u8*)&lbl_1_data_3D648.unk_16;
}
/* fzgx:end fn_1_D0E08 */

/* fzgx:begin fn_1_D0E18 */
// Return the address of the enemy-control field at offset 0x18.

u16* fn_1_D0E18(void) {
    return &lbl_1_data_3D648.unk_18;
}
/* fzgx:end fn_1_D0E18 */

/* fzgx:begin fn_1_D0E28 */
// Return the enemy-control data block.

Obj_1_data_3D648* fn_1_D0E28(void) {
    return &lbl_1_data_3D648;
}
/* fzgx:end fn_1_D0E28 */

/* fzgx:begin fn_1_D0E34 */
// Returns the status-byte array beginning at the shared enemy data block.

u8* fn_1_D0E34(void) {
    return &lbl_1_data_3D648.unk_20;
}
/* fzgx:end fn_1_D0E34 */

/* fzgx:begin fn_1_D0E44 */
// Return the address of the enemy controller's status byte.

u8* fn_1_D0E44(void) {
    return &lbl_1_data_3D648.unk_21;
}
/* fzgx:end fn_1_D0E44 */

/* fzgx:begin fn_1_D0E54 */
// Returns the address of this object's byte flag.

u8* fn_1_D0E54(void) {
    return &lbl_1_data_3D648.unk_22;
}
/* fzgx:end fn_1_D0E54 */

/* fzgx:begin fn_1_D0E64 */
// Returns the address of the enemy-control byte at offset 0x23.

u8* fn_1_D0E64(void) {
    return &lbl_1_data_3D648.unk_23;
}
/* fzgx:end fn_1_D0E64 */

/* fzgx:begin fn_1_D0E74 */
void fn_1_D0E74(void) {
    GXPokeAlphaRead((2U));
    fn_8003432C(((*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_4), ((*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6), (u32 *)((struct Sig_fn_8003432C_fn_8003432C_Arg2 *)((struct Sig_fn_8003432C_fn_8003432C_Arg2 *) (((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)))));
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_20 = ((*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 0x18U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_21 = ((*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 0x10U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_22 = ((*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 8U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_23 = (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28));
    GXPeekZ(((*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_4), ((*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6), (struct Sig_GXPeekZ_GXPeekZ_Arg2 *)((struct Sig_GXPeekZ_GXPeekZ_Arg2 *) (((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 12))));
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_8 = ((480.0f * (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6) / fn_1_A5DB0());
}
/* fzgx:end fn_1_D0E74 */

/* fzgx:begin fn_1_D0F60 */
/* Debug EFB magnifier: reads the (cols+1) x (rows+1) framebuffer pixels around (unk_4, unk_6)
 * with GXPeekARGB (fn_8003432C) and draws each as a cell_w x cell_h square at (x0, y0), outlining
 * the centre cell and the sampled area in white. Off-screen pixels are skipped. */

void fn_1_D0F60(void) {
    s32 cell_w;
    s32 cell_h;
    s32 i;
    s32 j;
    s32 x0;
    s32 y0;
    s32 cols;
    s32 rows;
    s32 hw;
    s32 hh;
    s32 y;
    u32 argb;
    GXColor c;

    cols = lbl_1_data_3D648.unk_10;
    rows = lbl_1_data_3D648.unk_12;
    x0 = lbl_1_data_3D648.unk_16;
    y0 = lbl_1_data_3D648.unk_18;
    cell_w = lbl_1_data_3D648.unk_14;
    cell_h = lbl_1_data_3D648.unk_14;
    hw = cols / 2;
    hh = rows / 2;
    fn_1_A9868();
    for (i = -hw; i <= hw; i++) {
        for (j = -hh; j <= hh; j++) {
            if (((lbl_1_data_3D648.unk_4 + i) > 639.0f ? 0 : (lbl_1_data_3D648.unk_4 + i) >= 0)
                && ((y = lbl_1_data_3D648.unk_6 + j) > fn_1_A5DB0() - 1 ? 0 : y >= 0)) {
                fn_8003432C(lbl_1_data_3D648.unk_4 + i, y, &argb);
                c.a = (argb & 0xFF000000) >> 24;
                c.r = (argb & 0xFF0000) >> 16;
                c.g = (argb & 0xFF00) >> 8;
                c.b = argb & 0xFF;
                fn_1_A9FFC(x0 + i * cell_w + 1, y0 + j * cell_h + 1, cell_w - 1, cell_h - 1, c);
                if (i == 0 && j == 0) {
                    static const GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                    fn_1_A9B70(x0 - 1, y0 - 1, cell_w + 2, cell_h + 2, white);
                }
            }
        }
    }
    {
        static const GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
        fn_1_A9B70(lbl_1_data_3D648.unk_4 - hw - 1,
                   480.0f * (lbl_1_data_3D648.unk_6 - hh - 1) / fn_1_A5DB0(),
                   cols + 2,
                   480.0f * (rows + 2) / fn_1_A5DB0(),
                   white);
    }
    fn_1_AA538();
}
/* fzgx:end fn_1_D0F60 */

/* fzgx:begin fn_1_D123C */
extern u32 lbl_1_bss_7AC48[5];
extern u32 lbl_1_bss_7AC54[4];
extern u8 lbl_1_bss_7AC90[12];
extern u32 lbl_1_rodata_5D40[7];
extern u32 fn_1_3F7E0(void);
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5D18;
extern const f32 lbl_1_rodata_5D5C;
extern const f32 lbl_1_rodata_5D60;
extern const f32 lbl_1_rodata_5D64;
extern const f32 lbl_1_rodata_5D68;
extern const f32 lbl_1_rodata_5D6C;
extern const f32 lbl_1_rodata_5D88;
extern const f32 lbl_1_rodata_5D8C;
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5D90;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E0C;




extern u32 lbl_1_bss_7ACE0;
extern u32 lbl_1_bss_7ACDC;

s32 fn_1_D123C(u32 arg0) {
    u8 *base = (u8 *)&lbl_1_data_3D670;
    char buf[0x78];
    LoadResult res;
    s32 sid;
    void *ptr;
    s16 f;
    u32 v4;
    u8 v1;
    u8 v5;
    u32 *entry;
    u32 *aligned;
    u32 size;
    u32 *aligned2;
    u32 size2;
    u32 *entry2;

    fn_80006E10((u32)(base + 0x2BC));
    sid = (s8)arg0;
    v1 = fn_1_12C7B8(fn_1_86690(sid));
    ptr = fn_1_868C0(sid);
    v4 = ((u32 *)lbl_1_data_20D1C)[(s16)fn_1_12C930(v1)];
    f = *(s16 *)((u8 *)ptr + 0x3B8);
    v5 = f;
    v5 %= 4;
    if (v5 != 0 && v5 != 4) {
        sprintf(buf, (const char *)(base + 0x2C4), v4, v5);
        if (fn_1_45730(buf, &res) == 0) {
            sprintf(buf, (const char *)(base + 0x2D8), v4);
            OSReport((const char *)(base + 0x2E4), v1, v5);
        }
        fn_1_45850(&res);
    } else {
        sprintf(buf, (const char *)(base + 0x2D8), v4);
    }
    if (lbl_1_bss_960 == 9) {
        switch ((s8)lbl_1_bss_9C) {
        case 3:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x318));
            break;
        case 5:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x32C));
            break;
        case 4:
            if (v1 == 0x17 && v5 != 0) {
                switch ((u8)arg0 % 5) {
                case 0: sprintf(buf, (const char *)(base + 0x340)); break;
                case 1: sprintf(buf, (const char *)(base + 0x358)); break;
                case 2: sprintf(buf, (const char *)(base + 0x370)); break;
                case 3: sprintf(buf, (const char *)(base + 0x388)); break;
                default: sprintf(buf, (const char *)(base + 0x3A0)); break;
                }
            }
            break;
        }
    }
    if (fn_1_45730(buf, &res) == 0) {
        fn_80006E10((u32)(base + 0x3B8));
        return 0;
    }
    size = fn_1_45B2C(&res);
    if ((*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0] != 0) {
        entry = (u32 *)(*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0];
    } else {
        entry = (u32 *)fn_1_45D0(*(u32 *)&lbl_801A6410,
                             (((size + 0x1F) & ~0x1F) + 0x20),
                             base + 0x3BC, 0xD2);
    }
    aligned = (u32 *)(((u32)entry + 0x3F) & ~0x1F);
    DCInvalidateRange(aligned, (void *)size);
    fn_1_458A0(&res, aligned, (void *)size, 0);
    entry[0] = aligned[0];
    entry[1] = (u32)&aligned[1];
    entry[2] = (u32)aligned;
    entry[3] = 0;
    (*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0] = (u32)entry;
    sprintf(buf, (const char *)(base + 0x3C4), v4);
    if (lbl_1_bss_960 == 9) {
        switch ((s8)lbl_1_bss_9C) {
        case 3:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x3D0));
            break;
        case 5:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x3E4));
            break;
        case 4:
            if (v1 == 0x17 && v5 != 0) {
                switch ((u8)arg0 % 5) {
                case 0: sprintf(buf, (const char *)(base + 0x3F8)); break;
                case 1: sprintf(buf, (const char *)(base + 0x410)); break;
                case 2: sprintf(buf, (const char *)(base + 0x428)); break;
                case 3: sprintf(buf, (const char *)(base + 0x440)); break;
                default: sprintf(buf, (const char *)(base + 0x458)); break;
                }
            }
            break;
        }
    }
    if (fn_1_45730(buf, &res) == 0) {
        fn_80006E10((u32)(base + 0x3B8));
        return 0;
    }
    size2 = fn_1_45B2C(&res);
    if ((*(u32 **)&lbl_1_bss_7ACDC)[(u8)arg0] != 0) {
        entry2 = (u32 *)(*(u32 **)&lbl_1_bss_7ACDC)[(u8)arg0];
    } else {
        entry2 = (u32 *)fn_1_45D0(*(u32 *)&lbl_801A6410,
                             (((size2 + 0x1F) & ~0x1F) + 0x20),
                             base + 0x3BC, 0x121);
    }
    aligned2 = (u32 *)((u8 *)entry2 + 0x20);
    DCInvalidateRange(aligned2, (void *)size2);
    fn_1_458A0(&res, aligned2, (void *)size2, 0);
    fn_80071100((u32)aligned2, (u32)entry2, (*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0]);
    entry2[4] &= ~1;
    (*(u32 **)&lbl_1_bss_7ACDC)[(u8)arg0] = (u32)entry2;
    fn_80006E10((u32)(base + 0x3B8));
    return 1;
}
/* fzgx:end fn_1_D123C */
