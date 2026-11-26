/* the TU defines these objects; header declarations are renamed out of the way */
#define lbl_1_bss_716C0 hdr_bss_716C0
#define lbl_1_bss_716C8 hdr_bss_716C8
#define lbl_1_bss_71808 hdr_bss_71808
#define lbl_1_bss_718B1 hdr_bss_718B1
#define lbl_1_bss_718B4 hdr_bss_718B4
#define lbl_1_bss_718C0 hdr_bss_718C0
#define lbl_1_bss_718E0 hdr_bss_718E0
#define lbl_1_bss_7730A hdr_bss_7730A
#define lbl_1_bss_77380 hdr_bss_77380
#define lbl_1_bss_7A380 hdr_bss_7A380
#define lbl_1_data_35AC8 hdr_data_35AC8
#define lbl_1_data_3B74C hdr_data_3B74C
#define lbl_1_data_3C1E4 hdr_data_3C1E4
#define lbl_1_data_3C7B8 hdr_data_3C7B8
#define lbl_1_data_3C7C4 hdr_data_3C7C4
#define lbl_1_data_3C89C hdr_data_3C89C
#define lbl_1_data_3CF40 hdr_data_3CF40
#define lbl_1_data_3D108 hdr_data_3D108
#define lbl_1_data_3D11C hdr_data_3D11C
#define lbl_1_data_3D124 hdr_data_3D124
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/memcard.h"
#include "rel/main_rel/driver.h"
#include "rel/main_rel/prog.h"
#include "rel/main_rel/car.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "dolphin/card.h"
#include "dolphin/card/CARDPriv.h"
#include "dolphin/dvd.h"
#include "dolphin/os/OSTime.h"
#include "game/vec3.h"
#include "psvec.h"
#include "font.h"
#undef lbl_1_bss_716C0
#undef lbl_1_bss_716C8
#undef lbl_1_bss_71808
#undef lbl_1_bss_718B1
#undef lbl_1_bss_718B4
#undef lbl_1_bss_718C0
#undef lbl_1_bss_718E0
#undef lbl_1_bss_7730A
#undef lbl_1_bss_77380
#undef lbl_1_bss_7A380
#undef lbl_1_data_35AC8
#undef lbl_1_data_3B74C
#undef lbl_1_data_3C1E4
#undef lbl_1_data_3C7B8
#undef lbl_1_data_3C7C4
#undef lbl_1_data_3C89C
#undef lbl_1_data_3CF40
#undef lbl_1_data_3D108
#undef lbl_1_data_3D11C
#undef lbl_1_data_3D124

typedef f32 Mtx[3][4];

typedef struct Fn195158Object Fn195158Object;
typedef struct Fn195158Data Fn195158Data;
typedef struct Fn195158Car Fn195158Car;
typedef struct Fn1967A8Resource Fn1967A8Resource;
typedef struct Fn196968Object Fn196968Object;
typedef struct Fn1969E8Owner Fn1969E8Owner;
typedef struct Fn196BC0Object Fn196BC0Object;
typedef struct Fn196A68Object Fn196A68Object;
typedef struct MemcardState_ACD04 MemcardState_ACD04;
typedef struct Sig_DVDOpen_DVDFileInfo Sig_DVDOpen_DVDFileInfo;
typedef struct CardTask CardTask;
typedef struct CardMgr CardMgr;
typedef struct GhostFileNode GhostFileNode;

typedef s32 (*fn_1_8D210_callback)(u32);
typedef void (*Sig_DVDOpen_DVDCallback)(s32 result, Sig_DVDOpen_DVDFileInfo *fileInfo);
typedef u32 (*fn_1_B4AC0_Fn0)(u32);
typedef u32 (*fn_1_B4AC0_Fn1)(u32);
typedef u32 (*fn_1_B4AC0_Fn2)(u32);
typedef void (*CARDCallback)(s32 chan, s32 result);

/* fn_1_AA590 */
struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};

/* fn_1_AA590 */
struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};

/* fn_1_AA590 */
typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

/* fn_1_AA590 */
struct fn_1_A9868_lbl_1_rodata_4AA0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
};

/* fn_1_AA590 */
struct FzgxCopy_88 { u32 words[22]; };

/* fn_1_AA590 */
typedef struct FnA861CVehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 pad_bc[0xc0 - 0xbc];
    f32 unk_c0;
} FnA861CVehicle;

/* fn_1_AA590 */
typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

/* fn_1_AA590 */
struct Sig_fn_800737E4_fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
};

/* fn_1_AA590 */
typedef struct {
    u8 kind;
    u8 callback;
    u8 flags;
    u8 pad3;
    s16 x;
    s16 y;
    s16 z;
    s16 padA;
    void *data;
} Fn1A9250Entry;

/* fn_1_AA590 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

/* fn_1_AA590 */
typedef struct FnA8834Camera {
    u8 pad_0[0x90];
    u8 unk_90[0x48];
    f32 unk_d8;
    f32 unk_dc;
    u8 pad_e0[4];
    f32 unk_e4;
    u8 pad_e8[0x18c - 0xe8];
    u8 unk_18c[4];
} FnA8834Camera;

/* fn_1_AA590 */
struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

/* fn_1_AA590 */
typedef struct FnA8834Vehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xc0 - 0xb4];
    f32 unk_c0;
    u8 pad_c4[0x1fc - 0xc4];
    f32 unk_1fc;
} FnA8834Vehicle;

/* fn_1_AA590 */
struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

/* fn_1_AA590 */
struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

/* fn_1_AA590 */
typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;

/* fn_1_AA590 */
typedef struct Sig_fn_80015EE8_Fn80015EE8Out {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
} Sig_fn_80015EE8_Fn80015EE8Out;

/* fn_1_AA590 */
typedef struct FnA861CCamera {
    u8 pad_0[0xdc];
    f32 yaw;      /* 0xdc */
    f32 roll;     /* 0xe0 */
    f32 pitch;    /* 0xe4 */
    u8 unk_e8;
    u8 unk_e9;
    u8 pad_ea[0x15c - 0xea];
    u8 unk_15c[4];
} FnA861CCamera;

/* fn_1_AA590 */
typedef union {
    u8 u8;
    f32 f32;
} PPCWGPipe;

/* fn_1_AA590 */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

/* fn_1_AA590 */
typedef struct FnA7E60Object {
    u8 pad_fc[0xfc];
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    void *unk_108;
} FnA7E60Object;

/* fn_1_AA590 */
typedef struct Resource {
    u8 pad_0[8];
    void *unk_8;
} Resource;

/* fn_1_AA590 */
typedef struct {
    u8 pad_0[0x8];
    void *unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
} Fn1A75dcResult;

/* fn_1_AA590 */
struct fn_1_A8270_Entry {
	u32 unk_0;
	u32 unk_4;
	u32 unk_8;
	u8 pad_C[0x18];
};

/* fn_1_AA590 */
struct fn_1_A8270_Arg0 {
	u8 pad_0[0xE8];
	u8 unk_E8;
	u8 unk_E9;
	s16 unk_EA;
	s16 unk_EC;
	s16 unk_EE;
	void *unk_F0;
	u8 pad_F4[8];
	struct fn_1_A8270_Entry *unk_FC;
	s32 unk_100;
	u32 unk_104;
	u8 pad_108[0x24];
	u32 *unk_12C[12];
};

/* fn_1_AA590 */
typedef struct {
    u32 w[45];
} Unk_23800000;

/* fn_1_AA590 */
typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Sig_fn_1_55628_Fn1_55628Object;

/* fn_1_AA590 */
struct fn_1_A8270_Rec {
	u8 pad_0[4];
	u32 unk_4;
	u8 pad_8[0x16];
	u8 count;
};

/* fn_1_AA590 */
typedef struct fn_1_8D210_car {
    f32 position[6];
    f32 scale_z;
    f32 scale_y;
    f32 scale_x;
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
    u8 field_40;
    u8 pad_41[3];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} fn_1_8D210_car;

/* fn_1_AA590 */
typedef struct {
    u8 pad[0x15];
    u8 code;
} State;

/* fn_1_AA590 */
typedef struct {
    u8 pad[4];
    State *state;
} fn_1_8E3A4_Object;

/* fn_1_AA590 */
struct Sig_fn_800713E0_fn_800713E0_Entry {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_AA590 */
struct Sig_fn_800713E0_fn_800713E0_Arg0 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry **entries;
};

/* fn_1_AA590 */
struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_AA590 */
struct Fn195158Data {
    u8 unk_00[0x08];
    Fn195158Object *unk_08;
};

/* fn_1_AA590 */
struct Fn195158Car {
    u8 unk_00[0xA0];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 unk_A6[0x02];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    u8 unk_BC[0x94];
    Fn195158Data *unk_150;
};

/* fn_1_AA590 */
typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[0x8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} EventNode;

/* fn_1_AA590 */
typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

/* fn_1_AA590 */
struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_AA590 */
struct Fn196968Object {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_AA590 */
struct Fn1969E8Owner {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_AA590 */
struct Fn196BC0Object {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_AA590 */
struct Fn196A68Object {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_AA590 */
typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

/* fn_1_AA590 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

/* fn_1_AA590 */
typedef struct {
    u8 **unk_00;
    void *unk_04;
    u32 pad_08;
} Fn1_87448_Slot;

/* fn_1_AA590 */
typedef struct {
    u8 pad_00[0x330];
    u32 unk_330;
    Fn1_87448_Slot unk_334[1];
} Fn1_87448_Obj;

/* fn_1_AA590 */
typedef struct {
    u8 pad_00[2];
    s8 unk_02;
} Fn1_87448_Arg1;

/* fn_1_AA590 */
typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Fn1_8F45C_Object;

/* fn_1_AA590 */
typedef struct {
    s32 active;
    s32 entries[5];
} Fn1_8F494_Object;

/* fn_1_AA590 */
typedef struct {
    u8 pad_0[0x148];
    u8 pad_148[0x20];
    u8 pad_168[0x40];
    u8 pad_1a8[0x20];
    u8 pad_1c8[0x20];
    u8 pad_1e8[0x20];
    u8 entries[0x14][0x20];
} Fn1_8F5A4_Object;

/* fn_1_AA590 */
typedef struct Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Fn935E4Slot;

/* fn_1_AA590 */
typedef struct Fn935E4Node {
    u8 pad0[0xa];
    u16 field_a;
    u8 pad_c[6];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    u8 pad27[1];
    Fn935E4Slot *field_28;
    u8 pad2c[8];
    Fn935E4Slot *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Fn935E4Node;

/* fn_1_AA590 */
typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

/* fn_1_AA590 */
typedef struct A7B5C_Mtx {
u8 pad[0x30];
} A7B5C_Mtx;

/* fn_1_AA590 */
typedef struct A7B5C_Obj {
A7B5C_Mtx mtx[4];
f32 unk_c0;
f32 unk_c4;
f32 unk_c8;
f32 unk_cc;
f32 unk_d0;
f32 unk_d4;
f32 unk_d8;
f32 unk_dc;
f32 unk_e0;
f32 unk_e4;
s8 unk_e8;
u8 unk_e9;
u8 pad_ea[0x10c - 0xea];
f32 unk_10c;
f32 unk_110;
Vec3 unk_114;
f32 unk_120;
f32 unk_124;
f32 unk_128;
A7B5C_Mtx parts[10];
} A7B5C_Obj;

/* fn_1_AA590 */
typedef struct A7B5C_Src {
u8 pad[8];
u8 *data;
} A7B5C_Src;

/* fn_1_AA590 */
typedef struct fn_1_A89B0_Obj {
    Mtx mtx;           /* 0x000 */
    Vec3 pos[2][4];     /* 0x030, 0x060 */
    u8 pad_90[0xC0 - 0x90];
    Vec3 ofs[2];        /* 0x0C0, 0x0CC */
    u8 pad_d8[0x10C - 0xD8];
    f32 len1;               /* 0x10C */
    f32 len2;               /* 0x110 */
    u8 pad_114[0x12C - 0x114];
    Mtx joints[7];     /* 0x12C */
} fn_1_A89B0_Obj;

/* fn_1_AA590 */
typedef struct fn_1_A89B0_Arg1 {
    u8 pad_0[0x1FC];
    f32 unk_1FC;
} fn_1_A89B0_Arg1;

/* fn_1_AA590 */
typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x32];
} fn_1_A948C_Font;

/* fn_1_AA590 */
typedef struct DriverDesc {
    u8 pad_0[0x40];
    u32 unk_40;
    s32 unk_44;
    u32 unk_48;
} DriverDesc;

/* fn_1_AA590 */
typedef struct Ent {
    u8 a0; s8 a1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    s16 s8_; s16 sa; s32 c; u8 pad10[0x14];
    s32 w24; u8 pad28[2]; u8 b2a; s8 b2b; s32 w2c0;
    s32 w30; f32 f34; f32 f38; s32 w3c; s32 w40; u8 pad44[4];
    s32 w48; s32 w4c; s32 w50; u8 pad54[0x4c];
} Ent;

/* fn_1_AA590 */
typedef struct G {
    u8 pad0[8];
    Ent e[2];
    s32 n148; s32 n14c;
    Ent c;
    u8 b1f0; u8 b1f1; u8 b1f2; u8 pad1f3;
    s32 w1f4; u8 b1f8; u8 b1f9; u8 pad1fa[2];
    s32 w1fc; void *p200;
    u8 pad204[0x5c00 - 0x204];
    s32 n5c00; s32 n5c04;
} G;

/* fn_1_AA6D8 */
typedef struct DriverSub {
    s32 unk_0;
    u8 unk_4;
    u8 pad_5[0x3];
    DriverDesc *unk_8;
    u8 pad_C[0x20];
    u32 unk_2C;
} DriverSub;

/* fn_1_AA6D8 */
typedef struct DriverObj {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x7C];
    DriverDesc *unk_8C;
    u8 pad_90[0x4];
    DriverSub *unk_94;
    char unk_98[0x20];
    u32 unk_B8;
    char unk_BC[0x24];
    s32 unk_E0;
    u32 unk_E4;
    u32 unk_E8;
} DriverObj;

/* fn_1_AA6D8 */
typedef struct DriverParam {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u8 pad_8[0x4];
    DriverSub *unk_C;
    u32 unk_10;
    char *unk_14;
    char *unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
} DriverParam;

/* fn_1_AA6D8 */
typedef struct DriverEntry {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 pad_3[0x21];
    DriverObj *unk_24;
    u8 pad_28[0x78];
} DriverEntry;

/* fn_1_AA6D8 */
typedef struct DriverState {
    u8 unk_0;
    u8 pad_1[0x7];
    DriverEntry unk_8[2];
    u8 pad_148[0x8];
    DriverEntry unk_150;
    u8 pad_1F0;
    u8 unk_1F1;
    u8 unk_1F2;
    u8 pad_1F3[0x5];
    u8 unk_1F8;
    u8 unk_1F9;
    u8 pad_1FA[0x5A0E];
    char unk_5C08[0x20];
} DriverState;

/* fn_1_AA6D8 */
typedef void (*DriverFunc)(DriverParam *, DriverEntry *);

/* fn_1_AA6D8 */
typedef struct DriverData {
    u8 pad_0[0x6B68];
    DriverFunc handlers[0x62];
    char file[0xC];
    char suffix[0x4];
} DriverData;

/* fn_1_AAB98 */
typedef struct {
    u8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
    s32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x6C];
    struct AAF1C_Info *unk_8C;
    u8 pad_90[4];
    void *unk_94;
    u8 pad_98[0x44];
    void *unk_DC;
} fn_1_AAB98_Obj;

/* fn_1_AAB98 */
typedef struct {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s16 unk_8;
    s16 unk_A;
    void *unk_C;
    u8 pad_10[0x14];
    fn_1_AAB98_Obj *unk_24;
    s8 unk_28;
    u8 pad_29;
    u8 unk_2A;
    u8 pad_2B[5];
    s32 unk_30;
    f32 unk_34;
    f32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    u8 pad_44[0xC];
    s32 unk_50;
    char unk_54[32];
    u8 pad_74[0x24];
    u64 unk_98;
} fn_1_AAB98_Entry;

/* fn_1_AAB98 */
struct fn_1_AAEB0_Arg0 {
    u8 unk_0;
    u8 pad_1[0x4];
    u8 unk_5;
    u8 pad_6[0x1E];
    u32 unk_24;
};

/* fn_1_AAB98 */
struct fn_1_AAEB0_lbl_1_data_35AC8 {
    u8 pad_0[0x6AC4];
    u32 unk_6AC4[1];
};

/* fn_1_AAB98 */
typedef struct AAF1C_Info {
u8 pad_0[0x3F];
u8 unk_3F;
} AAF1C_Info;

/* fn_1_AAB98 */
typedef struct {
u8 pad_0[0x2];
s16 unk_2;
s32 unk_4;
u32 unk_8;
u8 pad_C[0x80];
AAF1C_Info *unk_8C;
} AAF1C_State;

/* fn_1_AAB98 */
typedef struct {
u8 pad_0[0x2];
u8 unk_2;
u8 pad_3[0x5];
s16 unk_8;
s16 unk_A;
u8 pad_C[0x18];
AAF1C_State *unk_24;
u8 pad_28[0x2];
u8 unk_2A;
} AAF1C_Obj;

/* fn_1_AAB98 */
typedef struct Fn1AB438Data {
    u8 pad_00[8];
    s16 field_08;
    s16 field_0A;
    u8 pad_0C[0x1e];
    u8 field_2A;
} Fn1AB438Data;

/* fn_1_AB478 */
typedef struct {
    u8 pad_0[2];
    u16 unk_2;
} Fn1AB478Sub;

/* fn_1_AB478 */
typedef struct {
    u8 unk_0;
    u8 pad_1[6];
    u8 unk_7;
    u8 pad_8[4];
    u32 unk_C;
    u8 pad_10[0x14];
    Fn1AB478Sub *unk_24;
} Fn1AB478Obj;

/* fn_1_AB478 */
typedef struct {
    u8 pad[0x2];
    s16 field_0x2;
    int field_0x4;
} StatusStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    s8 byte_1;
    u8 pad[0x22];
    StatusStruct *ptr_0x24;
    u8 pad2[0x70];
    int field_0x98;
    int field_0x9c;
} fn_1_AB4F4_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
} fn_1_AB598_OffsetStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad[0x23];
    fn_1_AB598_OffsetStruct *ptr_0x24;
} fn_1_AB598_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
    s32 field_0x4;
} fn_1_AB5CC_OffsetStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad[0x23];
    fn_1_AB5CC_OffsetStruct *ptr_0x24;
} fn_1_AB5CC_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 pad[1];
    u8 field_0x1;
} fn_1_AB61C_MemcardState;

/* fn_1_AB478 */
typedef struct {
    u8 pad_0x24[0x24];
    fn_1_AB61C_MemcardState *state;
    u8 pad_0x2a[0x2];
    u8 field_0x2a;
} fn_1_AB61C_MemcardArg;

/* fn_1_AB478 */
typedef struct {
    u8 pad_0[0x24];
    void *unk_24;
    u8 pad_28[0x2];
    u8 unk_2A;
} MemcardArg;

/* fn_1_AB478 */
typedef struct {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x2];
    s32 unk_4;
} MemcardState;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x23];
    fn_1_AB598_OffsetStruct *ptr_0x24;
    u8 pad_0x28[0x2];
    u8 flags_0x2a;
    u8 pad_0x2b[0x5];
    s32 field_0x30;
    u8 pad_0x34[0x4];
    f32 field_0x38;
} fn_1_AB75C_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x23];
    fn_1_AB5CC_OffsetStruct *ptr_0x24;
    u8 pad_0x28[0x2];
    u8 flags_0x2a;
    u8 pad_0x2b[0x5];
    s32 field_0x30;
    u8 pad_0x34[0x4];
    f32 field_0x38;
} fn_1_AB7C4_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 pad[0x24];
    fn_1_AB598_OffsetStruct *ptr_0x24;
} fn_1_AB870_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x23];
    void *ptr_0x24;
} fn_1_AB8D8_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
    s32 field_0x4;
    s32 field_0x8;
    u8 pad_0xc[0x4];
    u8 data[0x8];
} fn_1_AB99C_OffsetStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad[0x23];
    fn_1_AB99C_OffsetStruct *ptr_0x24;
} fn_1_AB99C_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0xf];
    u8 data_0x10[0x14];
    fn_1_AB5CC_OffsetStruct *ptr_0x24;
} fn_1_ABAAC_ArgStruct;

/* fn_1_AB478 */
typedef struct {
    u8 pad_0x0[0x1];
    u8 field_0x1;
    u8 pad_0x2[0x6];
    s16 field_0x8;
    s16 field_0xa;
} fn_1_ABB24_MemcardState;

/* fn_1_AB478 */
typedef struct {
    u8 pad_0x0[0x8];
    s16 field_0x8;
    s16 field_0xa;
    u8 pad_0xc[0x18];
    fn_1_ABB24_MemcardState *ptr_0x24;
    u8 pad_0x28[0x2];
    u8 field_0x2a;
} fn_1_ABB24_MemcardArg;

/* fn_1_ABB4C */
typedef struct {
u16 unk_0; /* 22 loads, 0 stores */
u16 unk_2; /* 35 loads, 0 stores */
u8 pad_4[0x4];
u16 unk_8; /* 108 loads, 0 stores */
u16 unk_A; /* 22 loads, 0 stores */
u8 pad_C[0x4];
u16 unk_10; /* 56 loads, 0 stores */
u16 unk_12; /* 53 loads, 0 stores */
u8 pad_14[0x3C];
} Obj_1_bss_9F8_fn_1_ABB4C;

/* fn_1_ABB4C */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x13];
    void *field_0x14;
} fn_1_ABC5C_ArgStruct;

/* fn_1_ABB4C */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x23];
    fn_1_AB5CC_OffsetStruct *ptr_0x24;
} fn_1_ABC98_ArgStruct;

/* fn_1_ABB4C */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
    u8 pad_0x4[0x8];
    void *ptr_0xc;
} fn_1_ABCE8_ResultStruct;

/* fn_1_ABB4C */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0xf];
    u8 data_0x10[0x14];
    fn_1_ABCE8_ResultStruct *ptr_0x24;
} fn_1_ABCE8_ArgStruct;

/* fn_1_ABB4C */
typedef struct {
    u8 pad_0x0[0x2];
    u16 unk_0x2;
    s32 unk_0x4;
    u8 pad_0x8[0x18];
    u8 unk_0x20[1];
} fn_1_ABDB8_ResultStruct;

/* fn_1_ABB4C */
typedef struct {
    u8 byte_0x0;
    u8 pad_0x1[0x13];
    void *ptr_0x14;
    u8 pad_0x18[0xc];
    fn_1_ABDB8_ResultStruct *ptr_0x24;
} fn_1_ABDB8_ArgStruct;

/* fn_1_ABB4C */
typedef struct Fn1ABE14Sub {
    u8 pad_00[0x2];
    u16 value;
    u8 pad_04[0x8];
    void *arg_0xC;
    u8 pad_10[0x84];
    void *arg_0x94;
} Fn1ABE14Sub;

/* fn_1_ABB4C */
typedef struct Fn1ABE14Arg {
    u8 id;
    u8 pad_01[0x23];
    Fn1ABE14Sub *sub;
    u8 pad_28[0x2];
    u8 flags;
    u8 pad_2B[0x4];
    s32 result;
    u8 pad_34[0x4];
    f32 value;
    u8 pad_3C[0x58];
} Fn1ABE14Arg;

/* fn_1_ABE88 */
struct fn_1_ABE88_Arg0 {
    u8 unk_0;
};

/* fn_1_ABE88 */
typedef struct {
    u8 pad_00[0x2];
    u16 field_0x2;
    s32 field_0x4;
    u8 pad_08[0x84];
    void *field_0x8c;
    s32 field_0x90;
    s32 field_0x94;
    u8 field_0x98[0x10];
} Fn1ABF44State;

/* fn_1_ABE88 */
typedef struct {
    u8 id;
    u8 pad_01[0xF];
    u8 data_0x10[0x14];
    Fn1ABF44State *state;
    u8 pad_28[0x2];
    u8 flags_0x2a;
    u8 pad_2b[0x5];
    s32 value_0x30;
    u8 pad_34[0x4];
    f32 value_0x38;
} Fn1ABF44Object;

/* fn_1_ABE88 */
typedef struct Fn1AC000Table {
    u8 pad_00[0x48];
    u32 value_0x48;
} Fn1AC000Table;

/* fn_1_ABE88 */
typedef struct Fn1AC000State {
    u8 pad_00[0x2];
    u16 value_0x2;
    s32 value_0x4;
    u8 pad_08[0x84];
    Fn1AC000Table *table;
} Fn1AC000State;

/* fn_1_ABE88 */
typedef struct Fn1AC000Target {
    u8 id;
    u8 pad_01[0x23];
    Fn1AC000State *state;
    u8 pad_28[0x2];
    u8 flags;
    u8 pad_2b[0x5];
    s32 start;
    u8 pad_34[0x4];
    f32 ratio;
} Fn1AC000Target;

/* fn_1_AC12C */
typedef struct MemcardRequestState {
    u8 pad_00[0x2];
    u16 value;
    u8 pad_04[0x90];
    void *data;
} MemcardRequestState;

/* fn_1_AC12C */
typedef struct fn_1_AC12C_MemcardRequest {
    u8 id;
    u8 pad_01[0xF];
    u8 buffer[0x14];
    MemcardRequestState *state;
    u8 pad_28[0x8];
    void *result;
} fn_1_AC12C_MemcardRequest;

/* fn_1_AC188 */
typedef struct Fn1AC188Config {
    u8 pad_00[0x48];
    int value;
} Fn1AC188Config;

/* fn_1_AC188 */
typedef struct Fn1AC188State {
    u8 pad_00[0x2];
    u16 value;
    int result;
    u8 pad_08[0x84];
    Fn1AC188Config *config;
} Fn1AC188State;

/* fn_1_AC188 */
typedef struct Fn1AC188Target {
    u8 id;
    u8 pad_01[0x23];
    Fn1AC188State *state;
    u8 pad_28[0x2];
    u8 flags;
    u8 pad_2b[0x5];
    int start;
    u8 pad_34[0x4];
    f32 value;
} Fn1AC188Target;

/* fn_1_AC188 */
typedef struct Fn1AC294State {
    u8 pad_00[0x2];
    u16 value;
} Fn1AC294State;

/* fn_1_AC188 */
typedef struct Fn1AC294Target {
    u8 id;
    u8 pad_01[0x13];
    void *arg;
    u8 pad_18[0xC];
    Fn1AC294State *state;
} Fn1AC294Target;

/* fn_1_AC188 */
typedef struct Fn1AC2D8State {
    u8 pad_00[0x2];
    u16 value;
    s32 status;
} Fn1AC2D8State;

/* fn_1_AC188 */
typedef struct Fn1AC2D8Target {
    u8 id;
    u8 pad_01[0x23];
    Fn1AC2D8State *state;
} Fn1AC2D8Target;

/* fn_1_AC188 */
typedef struct Fn1AC328State {
    u8 pad_00[0x2];
    u16 value;
    u8 pad_04[0x94];
} Fn1AC328State;

/* fn_1_AC188 */
typedef struct Fn1AC328Target {
    u8 id;
    u8 pad_01[0x23];
    Fn1AC328State *state;
} Fn1AC328Target;

/* fn_1_AC188 */
typedef struct Fn1AC38Data {
    u8 pad_00[0x2];
    u16 value;
    int status;
} Fn1AC38Data;

/* fn_1_AC188 */
typedef struct Fn1AC38Target {
    u8 id;
    u8 pad_01[0x23];
    Fn1AC38Data *data;
} Fn1AC38Target;

/* fn_1_AC188 */
typedef struct Fn1AC464State {
    u16 pad_00;
    u16 value;
    s32 result;
} Fn1AC464State;

/* fn_1_AC188 */
typedef struct Fn1AC464Target {
    u8 value;
    u8 pad_01[0x23];
    Fn1AC464State *state;
} Fn1AC464Target;

/* fn_1_AC188 */
typedef struct Fn1AC4B4Target {
    u8 pad_00[0x24];
    struct Fn1AC294State *state;
} Fn1AC4B4Target;

/* fn_1_AC188 */
typedef struct Fn1AC4C4State {
    u16 pad_00;
    u16 value_02;
    s32 result;
    u32 flags;
    u8 pad_0c[0x4];
    u8 data_10[0x4];
    u8 data_14[0x4];
} Fn1AC4C4State;

/* fn_1_AC188 */
typedef struct Fn1AC4C4Target {
    u8 value;
    u8 pad_01[0x23];
    Fn1AC4C4State *state;
} Fn1AC4C4Target;

/* fn_1_AC188 */
struct fn_1_AC53C_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_AC188 */
struct fn_1_AC53C_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_AC188 */
struct fn_1_AC53C_lbl_1_bss_716C0 {
    u8 unk_0;
};

/* fn_1_AC188 */
typedef struct {
    u8 unk0[8];
    u16 unk8;
    u16 unka;
    u8 unkC[0x1e];
    u8 unk2a;
} Fn1AC6A8Data;

/* fn_1_AC188 */
typedef struct fn_1_AC6CC_MemCardState {
    u8 padding[0x2a];
    u8 flags;
} fn_1_AC6CC_MemCardState;

/* fn_1_AC188 */
struct fn_1_AC79C_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_AC188 */
struct fn_1_AC79C_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_AC188 */
struct fn_1_AC79C_lbl_1_bss_716C0 {
    u8 unk_0;
};

/* fn_1_AC188 */
typedef struct {
    u8 unk0[8];
    u16 field8;
    u16 fieldA;
    u8 unkC[0x1e];
    u8 flags;
} Fn1AC908State;

/* fn_1_AC188 */
struct fn_1_AC92C_Arg0 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x2];
    u8 unk_2A;
    u8 pad_2B[0x1];
    u8 unk_2C;
    u8 unk_2D;
    u8 pad_2E[0xA];
    f32 unk_38;
};

/* fn_1_AC188 */
struct MemcardData {
    u8 pad0[2];
    u16 status;
    s32 result;
};

/* fn_1_AC188 */
struct MemcardObject {
    u8 id;
    u8 pad1[0x23];
    struct MemcardData *data;
    u8 pad28[2];
    u8 flags;
    u8 pad2b;
    u8 state;
    u8 pad2d[0xb];
    f32 progress;
};

/* fn_1_ACA00 */
typedef struct Fn1Aca00Child {
    u8 _pad00[2];
    u16 value;
} Fn1Aca00Child;

/* fn_1_ACA00 */
typedef struct Fn1Aca00Target {
    u8 _pad00[0x24];
    struct Fn1Aca00Child *child;
    u8 _pad28[4];
    u8 flag_2c;
    u8 flag_2d;
} Fn1Aca00Target;

/* fn_1_ACA00 */
typedef struct MemCardData {
    u8 pad0[4];
    s32 value;
    u8 pad8[0x18];
} MemCardData;

/* fn_1_ACA00 */
typedef struct fn_1_ACA1C_MemCardState {
    u8 id;
    u8 pad1[0x23];
    MemCardData *data;
    u8 pad28[4];
    u8 slot;
} fn_1_ACA1C_MemCardState;

/* fn_1_ACA00 */
struct fn_1_ACA78_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

/* fn_1_ACA00 */
struct fn_1_ACA78_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_ACA00 */
struct fn_1_ACA78_lbl_1_bss_716C0 {
    u8 unk_0;
};

/* fn_1_ACD04 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_c[0x4];
    s32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u8 pad_20[0x74];
    void *unk_94;
    u8 pad_98[0x44];
    void *unk_dc;
} Fn1Acd04Inner;

/* fn_1_ACD04 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x1];
    u8 unk_2;
    u8 pad_3[0x4];
    u8 unk_7;
    u16 unk_8;
    u16 unk_a;
    void *unk_c;
    u8 pad_10[0x14];
    Fn1Acd04Inner *unk_24;
    u8 pad_28[0x2];
    u8 unk_2a;
    u8 pad_2b[0x11];
    s32 unk_3c;
    s32 unk_40;
} Fn1Acd04Obj;

/* fn_1_ACD04 */
typedef struct {
    u8 field_0;
    u8 pad_1[0x23];
    void* field_24;
} fn_1_ACE80_SomeObject;

/* fn_1_ACD04 */
typedef struct {
    u8 pad_0[0x8];
    u16 field_8;
    u16 field_A;
    u8 pad_C[0x1E];
    u8 flags_2A;
} Object;

/* fn_1_ACD04 */
struct MemcardState_ACD04 {
    u8 pad_0[0x8];
    u32 flags_8;
    u8 pad_C[0x4];
    s32 value_10;
    s32 value_14;
    u32 field_18;
    u32 field_1C;
    u8 pad_20[0x74];
    void* value_94;
    u8 pad_98[0x44];
    void* value_DC;
};

/* fn_1_ACD04 */
typedef struct {
    u8 id;
    u8 pad_1;
    u8 type;
    u8 pad_3[0x4];
    u8 ready;
    u16 field_8;
    u16 field_A;
    void* card;
    u8 pad_10[0x14];
    MemcardState_ACD04* sub;
    u8 pad_28[0x2];
    u8 flags_2A;
    u8 pad_2B[0x11];
    s32 value_3C;
    s32 value_40;
} MemcardObject_ACD04;

/* fn_1_AD0A0 */
struct fn_1_AD0A0_Arg0 {
    u8 pad_0[0x2C];
    u8 unk_2C;
};

/* fn_1_AD140 */
typedef struct Fn1AD168Obj {
    u8 field0;
    u8 _pad1[0x13];
    void *field14;
    u8 _pad18[0xc];
    u8 *field24;
} Fn1AD168Obj;

/* fn_1_AD140 */
typedef struct Fn1AD1ACOutput {
    u8 unk_00[4];
    void *unk_04;
} Fn1AD1ACOutput;

/* fn_1_AD140 */
typedef struct Fn1AD1ACObject {
    u8 unk_00;
    u8 unk_01[0x23];
    Fn1AD1ACOutput *unk_24;
} Fn1AD1ACObject;

/* fn_1_AD140 */
typedef struct Fn1AD1E4State {
    u8 unk_00[8];
    void *unk_08;
    void *unk_0C;
} Fn1AD1E4State;

/* fn_1_AD140 */
typedef struct Fn1AD1E4Data {
    u8 unk_00[8];
    u32 unk_08;
    u8 unk_0C[0x88];
    void *unk_94;
    u8 unk_98[0x20];
    void *unk_B8;
} Fn1AD1E4Data;

/* fn_1_AD140 */
typedef struct Fn1AD1E4Object {
    u8 unk_00[3];
    u8 unk_03;
    u8 unk_04[0x20];
    Fn1AD1E4Data *unk_24;
} Fn1AD1E4Object;

/* fn_1_AD264 */
struct Sig_DVDOpen_DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    Sig_DVDOpen_DVDCallback callback;
};

/* fn_1_AD264 */
typedef struct Sig_fn_800174D0_Fn800174D0Object {
    u8 pad30[0x30];
    u32 field30;
    u32 field34;
    void *field38;
} Sig_fn_800174D0_Fn800174D0Object;

/* fn_1_AD264 */
typedef struct CardSlotInfo {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
} CardSlotInfo;

/* fn_1_AD264 */
struct CardTask {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s16 unk_08;
    s16 unk_0A;
    void *unk_0C;
    u8 pad_10[0x14];
    CardMgr *unk_24;
    s8 unk_28;
    u8 pad_29;
    u8 unk_2A;
    u8 pad_2B[5];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
    u8 pad_3C[0xC];
    u64 unk_48;
    s32 unk_50;
    u8 pad_54[0x4C];
};

/* fn_1_AD264 */
struct CardMgr {
    u8 unk_00;
    u8 unk_01;
    u8 pad_02[2];
    s32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    s32 unk_14;
    u64 unk_18;
    u8 pad_20[0x1E];
    u8 unk_3E;
    u8 pad_3F[0xF];
    u8 unk_4E;
    u8 pad_4F;
    u32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 pad_5C[0x2C];
    u32 unk_88;
    GhostFileNode *unk_8C;
    u8 pad_90[4];
    u8 *unk_94;
    u8 unk_98[0x24];
    u8 unk_BC[0x20];
};

/* fn_1_AD264 */
struct GhostFileNode {
    u8 pad_00[0x20];
    char unk_20[0x1E];
    u8 unk_3E;
};

/* fn_1_AD264 */
typedef struct GhostRegs {
    u16 unk_0;
    u8 pad_2[4];
    u16 unk_6;
    u8 pad_8[0x198];
    u16 unk_1A0;
    u8 pad_1A2[0x537E];
    u16 unk_5520;
    u8 pad_5522[0x4C6];
} GhostRegs;

/* fn_1_AD264 */
typedef struct MgrRoot {
    u32 unk_0;
} MgrRoot;

/* fn_1_AEC34 */
typedef struct Fn1AEC34A {
    u8 pad0[8];
    void *payload;
    void *result;
} Fn1AEC34A;

/* fn_1_AEC34 */
typedef struct Fn1AEC34P {
    u8 pad0[8];
    u32 flags;
    u8 padC[0x88];
    void *buffer;
    u8 pad98[0x4c];
    void *length;
} Fn1AEC34P;

/* fn_1_AEC34 */
typedef struct Fn1AEC34B {
    u8 pad0[3];
    u8 state;
    u8 pad4[0x20];
    Fn1AEC34P *card;
} Fn1AEC34B;

/* fn_1_AECCC */
typedef struct MemcardHeader {
    u8 pad_0[0x20];
    u8 name[0x20];
} MemcardHeader;

/* fn_1_AECCC */
typedef struct MemcardCard {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    s32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x20];
    u32 unk_40;
    u8 pad_44[0xA];
    u8 unk_4E;
    u8 pad_4F;
    u32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 pad_5C[0x30];
    MemcardHeader *unk_8C;
    u8 pad_90[4];
    u32 unk_94;
    u8 pad_98[0x48];
    u32 unk_E0;
    u32 unk_E4;
} MemcardCard;

/* fn_1_AECCC */
typedef struct MemcardObj {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s16 unk_8;
    s16 unk_A;
    u32 unk_C;
    u8 pad_10[0x14];
    MemcardCard *unk_24;
    s8 unk_28;
    u8 pad_29;
    u8 unk_2A;
    u8 pad_2B[5];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
} MemcardObj;

/* fn_1_AECCC */
typedef struct MemcardSlot {
    u8 pad_0[0xA0];
} MemcardSlot;

/* fn_1_AECCC */
typedef struct MemcardWork {
    u8 unk_0;
    u8 pad_1[7];
    MemcardSlot slot[2];
    u8 pad_148[0xA9];
    u8 unk_1F1;
    u8 pad_1F2[0x2];
    /* polled by the state machine while the async card path writes it */
    u32 unk_1F4;
    u8 unk_1F8;
    u8 pad_1F9[0x5A0F];
    u8 unk_5C08;
    u8 pad_5C09[0x40];
    u8 unk_5C49;
    u8 unk_5C4A;
    u8 pad_5C4B;
    u32 unk_5C4C;
    s32 unk_5C50;
} MemcardWork;

/* fn_1_AECCC */
typedef struct MemcardDvdState {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0x3C];
} MemcardDvdState;

/* fn_1_AECCC */
typedef struct MemcardDvdFileInfo {
    u8 pad_0[0x3C];
} MemcardDvdFileInfo;

/* fn_1_AECCC */
typedef struct MemcardPathBuf {
    u32 w[0x13];
} MemcardPathBuf;

/* fn_1_AECCC */
typedef struct B03CC_File {
    u8 pad_0[0x3E];
    u8 unk_3E;
    u8 pad_3F[5];
    s32 unk_44;
} B03CC_File;

/* fn_1_AECCC */
typedef struct B03CC_Work {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    s32 unk_4;
    u32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x20];
    u32 unk_40;
    s32 unk_44;
    u8 pad_48[0x44];
    B03CC_File *unk_8C;
    u32 unk_90;
    u8 *unk_94;
    u8 pad_98[0x20];
    u32 unk_B8;
    u8 pad_BC[0x20];
    u32 unk_DC;
    u32 unk_E0;
    u32 unk_E4;
} B03CC_Work;

/* fn_1_AECCC */
typedef struct B03CC_State {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s16 unk_8;
    s16 unk_a;
    u32 unk_C;
    u8 pad_10[0x14];
    B03CC_Work *unk_24;
    s8 unk_28;
    u8 pad_29[1];
    u8 unk_2A;
    u8 pad_2B[5];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
    s32 unk_3C;
    u32 unk_40;
    u8 pad_44[4];
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u8 unk_54[0x20];
} B03CC_State;

/* fn_1_B171C */
typedef struct FileEntry {
 u8 unk_0, unk_1; char name[0x22]; u32 unk_24, unk_28; u8 pad[4];
} FileEntry;

/* fn_1_B171C */
typedef struct CardState {
 u8 unk_0, unk_1; u8 pad_2[2]; s32 unk_4; u32 unk_8;
 u8 pad_C[0xC]; u32 unk_18, unk_1C;
 char unk_20[0x20]; u32 unk_40, unk_44; char unk_48[4], unk_4C[2];
 u8 pad_4E[0x46]; FileEntry *unk_94; u8 pad_98[0x50]; u32 unk_E8;
} CardState;

/* fn_1_B171C */
typedef struct CardContext {
 u8 unk_0; s8 unk_1; u8 unk_2, unk_3, unk_4, unk_5, unk_6, unk_7;
 s16 unk_8, unk_A; void *unk_C; u8 pad_10[0x14]; CardState *unk_24;
 s8 unk_28; u8 unk_29, unk_2A, unk_2B, unk_2C, unk_2D; u8 pad_2E[2];
 u32 unk_30; f32 unk_34, unk_38;
} CardContext;

/* fn_1_B171C */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    char name[0x22];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
} MemcardEntry;

/* fn_1_B171C */
typedef struct {
    u8 pad_00[0x08];
    u32 unk_08;
    u32 unk_0C;
    u8 pad_10[0x10];
    char unk_20[0x20];
    u32 unk_40;
    u32 unk_44;
    char unk_48[4];
    char unk_4C[0x48];
    MemcardEntry *unk_94;
    char unk_98[0x20];
    u32 unk_B8;
    u8 pad_BC[0x20];
    u32 unk_DC;
} MemcardWork_B171C;

/* fn_1_B171C */
typedef struct {
    u8 pad_00[0x24];
    MemcardWork_B171C *unk_24;
    u8 pad_28[0x05];
    u8 unk_2D;
} MemcardCtx;

/* fn_1_B171C */
typedef struct UnkWork_1_B277C {
    u8 pad_00[0x04];
    s32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u8 pad_10[0x08];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x74];
    u8 *unk_94;
    u8 pad_98[0x20];
    u32 unk_B8;
    u8 pad_BC[0x20];
    u8 *unk_DC;
    u8 pad_E0[0x08];
    u32 unk_E8;
} UnkWork_1_B277C;

/* fn_1_B171C */
typedef struct UnkCtx_1_B277C {
    u8 unk_00;
    s8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s16 unk_08;
    s16 unk_0A;
    u32 unk_0C;
    u8 pad_10[0x14];
    UnkWork_1_B277C *unk_24;
    s8 unk_28;
    u8 pad_29;
    u8 unk_2A;
    u8 pad_2B;
    u8 unk_2C;
    u8 unk_2D;
    u8 pad_2E[0x02];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
} UnkCtx_1_B277C;

/* fn_1_B171C */
typedef struct Unk716C0_1_B277C {
    u8 unk_00;
    u8 pad_01[0x1F0];
    u8 unk_1F1;
    u8 pad_1F2[0x02];
    u32 unk_1F4;
    u8 unk_1F8;
    u8 unk_1F9;
    u8 pad_1FA[0x5A0E];
    u8 unk_5C08;
    u8 pad_5C09[0x40];
    u8 unk_5C49;
} Unk716C0_1_B277C;

/* fn_1_B171C */
typedef struct UnkBuf8_1_B277C {
    u8 m0;
    u8 m1;
    u8 m2;
    u8 m3;
    u8 m4;
    u8 m5;
    u8 m6;
    u8 m7;
} UnkBuf8_1_B277C;

/* fn_1_B171C */
typedef struct UnkHdr10_1_B277C {
    u8 m0;
    u8 m1;
    u8 m2;
    u8 m3;
    u16 m4;
    u8 m5;
    u8 m6;
    u8 m7;
    u8 m8;
    u8 pad[2];
} UnkHdr10_1_B277C;

/* fn_1_B171C */
typedef struct UnkOut16_1_B277C {
    u8 m0;
    u8 m1;
    u8 m2;
    u8 m3;
    u8 m4;
    u8 m5;
    u8 pad6[3];
    u8 m9;
    u8 pad10[3];
    u8 m13;
    u8 m14;
    u8 m15;
} UnkOut16_1_B277C;

/* fn_1_B3900 */
typedef struct B40Entry {
    s32 unk_0;
    u8 pad_4[4];
    const char *unk_8;
    u8 unk_C[32];
    s32 unk_2C;
} B40Entry;

/* fn_1_B3900 */
typedef struct B40Work {
    u8 unk_0;
    u8 unk_1;
    u16 unk_2;
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[12];
    u32 unk_18;
    u32 unk_1C;
    CARDStat unk_20;
    u8 pad_8C[8];
    B40Entry *unk_94;
} B40Work;

/* fn_1_B3900 */
typedef struct B40State {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s16 unk_8;
    s16 unk_A;
    u32 unk_C;
    u8 pad_10[20];
    B40Work *unk_24;
    s8 unk_28;
    u8 unk_29;
    u8 unk_2A;
    u8 unk_2B;
    u8 unk_2C;
    u8 pad_2D[3];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
} B40State;

/* fn_1_B3900 */
typedef union B40InputBits {
    struct { u16 pad : 7; u16 value : 9; } a;
    struct { u16 pad : 4; u16 value : 12; } b;
    struct { u16 pad : 5; u16 value : 11; } c;
} B40InputBits;

/* fn_1_B4AC0 */
typedef struct {
    u16 unk_0, unk_2;
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[4];
    s32 unk_10;
    u32 unk_14, unk_18, unk_1C;
    u8 pad_20[0x74];
    u32 unk_94;
    u8 pad_98[0x44];
    u32 unk_DC;
} fn_1_B4AC0_Detail;

/* fn_1_B4AC0 */
typedef struct {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2, unk_3, unk_4, unk_5, unk_6, unk_7;
    s16 unk_8, unk_A;
    u32 unk_C;
    u8 pad_10[0x14];
    u32 unk_24;
    u8 pad_28[2];
    u8 unk_2A;
    s8 unk_2B;
    u8 pad_2C[4];
    u32 unk_30;
    f32 unk_34, unk_38;
    s32 unk_3C;
    u32 unk_40;
    u8 pad_44[0x5C];
} fn_1_B4AC0_Channel;

/* fn_1_B5310 */
typedef struct {
    u8 r, g, b, a;
} Color;

/* fn_1_B5310 */
typedef struct {
    u8 pad_0[0x2A];
    u8 unk_2A;          /* 0x2A */
    u8 pad_2B[0x76];
} McTaskView;

/* fn_1_B5A3C */
typedef struct {
    u8 pad0[0x54];
    f32 value;
} B5F00Source;

/* fn_1_B5A3C */
typedef struct {
    f32 value0;
    u8 pad4[8];
    f32 valueC;
} B5F00Dest;

/* fn_1_B5F20 */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 pad_5[0x25];
    u8 unk_2A;
    u8 pad_2B[0xD];
    f32 unk_38;
    u8 pad_3C[0x64];
} MemcardSlot_B5F20;

/* fn_1_B6B28 */
typedef struct {
u8 unk_0;
u8 pad_1[7];
u32 unk_8;
u32 unk_C;
s32 unk_10;
u8 pad_14[0x78];
AAF1C_Info *unk_8C;
} CardWork_1_B6B28;

/* fn_1_B6B28 */
typedef struct {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u8 unk_4;
u8 pad_5[3];
s16 unk_8;
s16 unk_A;
u8 pad_C[0x18];
CardWork_1_B6B28 *unk_24;
u8 pad_28[2];
u8 unk_2A;
u8 pad_2B[0x11];
u32 unk_3C;
u8 pad_40[0x60];
} CardCtx_1_B6B28;

/* fn_1_B6B28 */
typedef struct {
    char *pad[0x25 * 6];
    char *slot_a;
    char *pad_a[5];
    char *slot_b;
    char *pad_b[5];
} CardSlotStrings_1_B6B28;

/* fn_1_B7CD4 */
typedef struct {
    u8 pad_0[0xc];
    u32 hour;
    u32 min;
    s32 msec;
    u8 pad_18[0x10];
} CalTime_1_B7CE4;

/* fn_1_B7CD4 */
typedef struct {
    u8 pad_0[0x750];
    u32 lang[6];
} QStruct;

/* fn_1_B7F08 */
typedef struct {
    u8 pad_0[0x48];
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u8 pad_54[0x94];
    u32 unk_E8;
    u32 unk_EC;
    u32 unk_F0;
} MemcardResetView;

/* fn_1_B8338 */
typedef struct {
    u8 pad_0;
    s8 state;
    u8 pad_2[0xA];
    void *work;
    u8 pad_10[0x2C];
    s32 freeBytes;
    s32 freeFiles;
    u8 pad_44[0x5C];
} MemcardChan;

/* fn_1_B8338 */
typedef struct {
    u8 pad_0[0x1F];
    u8 type;
    u8 pad_20[0x20];
    u32 size;
    u8 pad_44[8];
} MemcardFile;

/* fn_1_B88C4 */
typedef struct Slot { u8 a[1]; s8 state; u8 b[10]; void *work; u8 c[44]; s32 blocks; s32 files; u8 d[92]; } Slot;

/* fn_1_B8E84 */
typedef struct CardEntry {
    u8 pad_00[0x3C];
    u32 unk_3C;
    u32 unk_40;
    u8 pad_44[0x5C];
} CardEntry;

/* fn_1_B8EDC */
typedef struct {
    u8 pad[0x5c7c];
    u32 flags[2];
} MemcardFlagView;

/* fn_1_B9904 */
typedef struct {
    u8 type;
    u8 pad_1[3];
    u32 unk_4;
    u32 flags;
    u8 pad_C[4];
    s32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x6C];
    void *unk_8C;
    u8 pad_90[4];
    void *unk_94;
    u8 pad_98[0x44];
    void *unk_DC;
} MemcardWork_B9904;

/* fn_1_B9904 */
typedef struct {
    u8 chan;
    u8 pad_1;
    u8 state;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s16 unk_8;
    s16 unk_A;
    void *unk_C;
    u8 pad_10[0x14];
    MemcardWork_B9904 *work;
    u8 pad_28[2];
    u8 unk_2A;
    u8 pad_2B[5];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
    s32 unk_3C;
    u32 unk_40;
    u8 pad_44[0x5C];
} MemcardSlot_B9904;

/* fn_1_B9BE0 */
typedef struct {
    u8 pad_0[0x1];
    s8 unk_1;
    u8 pad_2[0x9E];
} MemcardEntry_B9BE0;

/* fn_1_B9BE0 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x0B];
    Obj_1_bss_77380 *unk_0C;
    u8 pad_10[0x10];
    u32 unk_20;
} MemcardRequest;

/* fn_1_B9DE8 */
typedef struct {
    u8 pad_0[0xC];
    void *unk_C;
    u8 pad_10[0x88];
    u64 unk_98;
} MemcardSlot_B9DE8;

/* fn_1_B9DE8 */
typedef struct {
    u8 pad_0[0x1A];
    s16 unk_1A;
    s16 unk_1C;
    u8 pad_1E[4];
    u8 unk_22;
    u8 pad_23[0x19];
    u8 unk_3C;
    u8 unk_3D;
} MemcardArg_B9DE8;

/* fn_1_B9DE8 */
typedef struct {
    u8 pad_0[0x94];
    s32 unk_94[16];
    s32 unk_D4[16];
    s32 unk_114[16];
} MemcardData_B9DE8;

/* fn_1_BA144 */
typedef unsigned long long u64_L;

/* fn_1_BA144 */
typedef struct {
u32 unk_0;
u8 unk_4;
u8 pad_5[0xF];
u8 unk_14;
u8 pad_15[0x33];
} fn_1_EF4F8_Obj_1_bss_7ECB4;

/* fn_1_BA144 */
typedef struct CARDFileInfo_L {
s32 chan;
s32 fileNo;
s32 offset;
s32 length;
u16 iBlock;
u16 __padding;
} CARDFileInfo_L;

/* fn_1_BA144 */
typedef struct CARDStat_L {
char fileName[32];
u32 length;
u32 time;
u8 gameName[4];
u8 company[2];
u8 bannerFormat;
u8 __padding;
u32 iconAddr;
u16 iconFormat;
u16 iconSpeed;
u32 commentAddr;
u32 offsetBanner;
u32 offsetBannerTlut;
u32 offsetIcon[8];
u32 offsetIconTlut;
u32 offsetData;
} CARDStat_L;

/* fn_1_BA144 */
typedef struct BAPort {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 pad_3[9];
void *unk_C;
u8 pad_10[0x2C];
s32 unk_3C;
s32 unk_40;
u8 pad_44[0x54];
u64_L unk_98;
} BAPort;

/* fn_1_BA144 */
typedef struct fn_1_BA144_file {
u8 unk_0, unk_1, unk_2;
u8 pad_3[0x21];
void *unk_24;
u32 unk_28;
void *unk_2C;
} BAFile;

/* fn_1_BA144 */
struct fn_1_BA144_lbl_801A6410 { u32 unk_0; };

/* fn_1_BA144 */
typedef struct BAState {
u32 unk_0;
u8 unk_4;
s8 unk_5;
u8 pad_6[0xE];
s8 unk_14;
u8 pad_15;
s16 unk_16, unk_18, unk_1A, unk_1C;
u8 unk_1E[2];
u8 unk_20[2];
u8 unk_22;
u8 pad_23[0xD];
s16 unk_30[2];
s32 unk_34;
u8 pad_38[4];
u8 unk_3C, unk_3D, unk_3E;
u8 pad_3F;
s32 unk_40[2];
} BAState;

/* fn_1_BA144 */
typedef struct BARequest {
u8 unk_0;
u8 pad_1[0xB];
struct McFile *unk_C;
u8 pad_10[0x10];
u32 unk_20;
} BARequest;

/* fn_1_BB974 */
typedef struct McFile {
    u8 used;            /* 0x00 */
    u8 type;            /* 0x01 */
    u8 unk_2;
    u8 pad_3[0x21];
    u32 size;           /* 0x24 */
    u32 time;           /* 0x28: seconds */
    void *info;         /* 0x2C */
} McFile;

/* fn_1_BB974 */
typedef struct {
    u8 unk_0, unk_1, unk_2, unk_3, unk_4, unk_5, unk_6, unk_7;
} McFileKey;

/* fn_1_BC29C */
typedef struct {
    u8 pad_0;
    s8 status;          /* 0x01: negative on a card error */
    u8 busy;            /* 0x02: 0xFF when idle */
    u8 pad_3[0x39];
    s32 free_blocks;    /* 0x3C */
    u8 pad_40[0x60];
} McSlot;

/* fn_1_BC29C */
typedef struct {
    u8 pad_0[2];
    u8 busy;            /* 0x02: 0xFF when idle */
    u8 pad_3[0x9E];
} McTask;

/* fn_1_BC29C */
typedef struct {
    u8 unk_0, unk_1, unk_2, unk_3;
    u16 unk_4;
    u8 unk_6, unk_7, unk_8, unk_9;
} McGhostA;

/* fn_1_BC29C */
typedef struct {
    u8 unk_0, unk_1;
    u8 pad_2[2];
    u8 unk_4, unk_5, unk_6, unk_7;
    u8 pad_8[0x1C];
    u8 unk_24, unk_25;
    u16 unk_26;
} McGhostB;

/* fn_1_BC29C */
typedef struct {
    u32 flags;                  /* 0x00 */
    s8 options;                 /* 0x04 */
    u8 pad_5[0xF];
    s8 option_lit;              /* 0x14 */
    u8 pad_15;
    s16 card;                   /* 0x16 */
    s16 cursor;                 /* 0x18 */
    s16 mark_card;              /* 0x1A */
    s16 mark_index;             /* 0x1C */
    u8 unk_1E[2];               /* 0x1E */
    u8 unk_20[2];               /* 0x20 */
    s8 state;                   /* 0x22 */
    u8 pad_23[9];
    s16 top[2];                 /* 0x2C */
    s16 count[2];               /* 0x30 */
    u8 pad_34[8];
    u8 sort;                    /* 0x3C */
    u8 sort_request;            /* 0x3D */
    u8 hidden;                  /* 0x3E */
    u8 pad_3F;
    s32 result[2];              /* 0x40 */
} McMenu;

/* fn_1_BED04 */
typedef struct {
    u8 pad_0[0x14];
    s8 type;
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Fn1C0510Obj;

/* fn_1_BED04 */
typedef struct {
    u8 unk0[0x16];
    s16 unk16;
} Fn1C132CObject;

/* fn_1_BED04 */
typedef struct TimeParts {
    u32 unused;
    u32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 spare_18;
    u32 spare_1C;
} TimeParts;

/* fn_1_BF198 */
struct BF198_Pkt {
	s32 kind;
	f32 x;
	f32 y;
	f32 z;
	f32 sx;
	f32 sy;
	f32 u0;
	f32 u1;
	f32 v0;
	f32 v1;
	u8 pad_28[0x14];
	s32 flag;
	u8 pad_40[0x18];
};

/* fn_1_BF198 */
struct BF198_Arg4 {
	s32 value;
};

/* fn_1_BF520 */
struct fn_1_BF520_Arg4 {
    u32 unk_0;
};

/* fn_1_BF520 */
struct fn_1_BF520_Copy88 { u32 a[22]; };

/* fn_1_BF520 */
struct fn_1_BF520_lbl_1_rodata_4CB0 {
    f64 unk_0;
};

/* fn_1_BF600 */
struct fn_1_BF600_Copy88 { u32 words[22]; };

/* fn_1_BF9C4 */
typedef struct {
    void *unk[6];
} Fn1BF9C4_Data;

/* fn_1_BFE20 */
struct fn_1_BFE20_Copy88 {
    u32 unk_0;
    f32 x;
    f32 y;
    f32 z;
    u32 pad_10[8];
    u32 unk_30;
    u32 pad_34[9];
};

/* fn_1_C023C */
typedef struct {
    u8 pad0[0x3e4];
    f32 f_3e4;
    u8 pad1[0x554 - 0x3e8];
    f32 f_554;
    u8 pad2[0x600 - 0x558];
    u32 u_600;
} Fn1C023CPool;

/* fn_1_C023C */
typedef struct {
    u32 w[16];
} Fn1C023CBuf;

/* fn_1_C062C */
typedef struct {
    s32 sec;
    s32 min;
    s32 hour;
    s32 mday;
    s32 mon;
    s32 year;
    s32 wday;
    s32 yday;
    s32 msec;
    s32 usec;
} CalTime;

/* fn_1_C062C */
typedef struct {
    u8 kind;
    u8 pad_1[7];
    char *date;
    void *buffer;
    u32 size;
    char *name;
    u8 pad_18[0xC];
} SaveInfo;

/* fn_1_C062C */
typedef struct {
    u8 pad_0[0x5C];
} FileInfo;

/* fn_1_C062C */
typedef struct {
    u8 pad_0[8];
    void *unk_8;
    u32 unk_C;
    s32 unk_10;
    u8 pad_14[2];
    s16 unk_16;
    u8 pad_18[2];
    s16 unk_1A;
    s16 unk_1C;
    u8 pad_1E[0x12];
    s16 unk_30[4];
} SaveReq;

/* fn_1_C062C */
typedef struct { u8 unk_0; u8 unk_1; char text[0x2E]; } Slot_C062C;

/* fn_1_C0B0C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0xA];
    s16 unk_1A;
    s16 unk_1C;
} MemcardRequest_C0B0C;

/* fn_1_C0B0C */
typedef struct {
    u8 unk_0;
    u8 state;
    u8 text[0x2A];
    u32 unk_2C;
} MemcardEntry_C0B0C;

/* fn_1_C0E00 */
typedef struct { u8 unk_0; u8 unk_1; u8 text[0x22]; u32 unk_24; u8 pad_28[4]; void *unk_2C; } Slot_C0E00;

/* fn_1_C1394 */
typedef struct McEntry {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x21];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
} McEntry;

/* fn_1_C1394 */
typedef struct McName {
    u32 unk_0;
    u32 unk_4;
} McName;

/* fn_1_C1394 */
typedef struct McState {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0xE];
    s8 unk_14;
    u8 pad_15;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u8 pad_20[2];
    u8 unk_22;
    u8 pad_23[0x19];
    u8 unk_3C;
    u8 unk_3D;
} McState;

/* fn_1_C17CC */
typedef struct {
	u8 unk_0;
	u8 unk_1;
	u8 unk_2[0x20];
	u32 unk_24;
	u32 unk_28;
	void *unk_2c;
} MemCardFile;

/* fn_1_C1ACC */
typedef struct {
    u32 unk_0[11];
    u32 unk_2C;
} MemcardEntry_C1ACC;

/* fn_1_C24A4 */
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;  // 1 loads, 0 stores
} Obj_1_bss_8B3A0_AtA4_L;

/* fn_1_C24A4 */
typedef struct {
    s16 unk_0;  // 12 loads, 2 stores
    u8 pad_2[0x2];
    s16 unk_4;  // 13 loads, 0 stores
    u8 pad_6[0x2];
    s16 unk_8;  // 7 loads, 2 stores
    u8 pad_A[0x4];
    s16 unk_E;  // 24 loads, 0 stores
    u8 pad_10[0x4];
    u8 unk_14;  // 7 loads, 2 stores
    u8 pad_15[0x19];
    s16 unk_2E;  // 1 loads, 0 stores
    u8 pad_30[0x5C];
    s16 unk_8C;  // 2 loads, 0 stores
    u8 pad_8E[0x2];
    s16 unk_90;  // 15 loads, 0 stores
    s16 unk_92;  // 1 loads, 0 stores
    u32 unk_94;  // 60 loads, 3 stores
    u8 pad_98[0x6];
    u8 unk_9E;  // 7 loads, 0 stores
    u8 unk_9F;  // 8 loads, 3 stores
    u8 pad_A0[0x4];
    Obj_1_bss_8B3A0_AtA4_L *unk_A4;  // 4 loads, 0 stores
    u8 pad_A8[0x8];
    s16 unk_B0;  // 1 loads, 1 stores
    s16 unk_B2;  // 1 loads, 1 stores
    u8 pad_B4[0xC];
    s16 unk_C0;  // 2 loads, 4 stores
    s16 unk_C2;  // 2 loads, 4 stores
    u8 pad_C4[0xC];
    s16 unk_D0;  // 1 loads, 2 stores
    s16 unk_D2;  // 1 loads, 2 stores
    u8 pad_D4[0xC];
    u32 unk_E0;  // 0 loads, 2 stores
    u32 unk_E4;  // 0 loads, 1 stores
    u32 unk_E8;  // 0 loads, 1 stores
    u32 unk_EC;  // 0 loads, 1 stores
    u32 unk_F0;  // 2 loads, 2 stores
    u32 unk_F4;  // 0 loads, 1 stores
    u32 unk_F8;  // 0 loads, 1 stores
    u32 unk_FC;  // 0 loads, 1 stores
    u32 unk_100;  // 2 loads, 2 stores
    u32 unk_104;  // 0 loads, 1 stores
    u32 unk_108;  // 0 loads, 1 stores
    u32 unk_10C;  // 0 loads, 1 stores
    u32 unk_110;  // 2 loads, 2 stores
    u32 unk_114;  // 0 loads, 1 stores
    u32 unk_118;  // 0 loads, 1 stores
    u32 unk_11C;  // 0 loads, 1 stores
    u32 unk_120;  // 0 loads, 2 stores
    u32 unk_124;  // 1 loads, 2 stores
    u8 unk_128;  // 0 loads, 1 stores
    u8 unk_129;  // 1 loads, 2 stores
    u8 pad_12A[0x2];
    s16 unk_12C;  // 4 loads, 0 stores
    s16 unk_12E;  // 1 loads, 0 stores
    s16 unk_130;  // 1 loads, 0 stores
    s16 unk_132;  // 1 loads, 0 stores
    s16 unk_134;  // 1 loads, 0 stores
    s16 unk_136;  // 1 loads, 0 stores
    s16 unk_138;  // 1 loads, 0 stores
    s16 unk_13A;  // 1 loads, 0 stores
    s16 unk_13C;  // 1 loads, 0 stores
    u8 pad_13E[0x2];
    u32 unk_140;  // 3 loads, 0 stores
    u8 pad_144[0x2];
    s16 unk_146;  // 4 loads, 0 stores
    s16 unk_148;  // 2 loads, 0 stores
    u8 pad_14A[0x2];
} Obj_1_bss_8B3A0_L;

/* fn_1_C24A4 */
typedef struct {
    u32 unk_0;  // 4 loads, 0 stores
    u8 pad_4[0xA94];
} Obj_1_data_3B74C_L;

/* fn_1_C24A4 */
struct fn_1_C24A4_Copy88 { u32 a[22]; };

/* fn_1_C24A4 */
struct fn_1_C24A4_Port {
    u8 pad_0; s8 mode; u8 type; u8 pad_3; u8 busy;
    u8 pad_5[0x25]; u8 flags; u8 pad_2B[0x25];
    s32 present; char name[32]; u8 pad_74[0x2C];
};

/* fn_1_C24A4 */
struct fn_1_C24A4_Request {
    u8 type; u8 pad_1[3]; u32 flags; void *name; void *data; u32 a[5];
};

/* fn_1_C24A4 */
struct fn_1_C24A4_Color { u8 r, g, b, a; };

/* fn_1_C3378 */
typedef struct {
    u8 pad_0[0x10];
    s16 unk_10;
    u8 pad_12[0x4];
    u8 unk_16;
    u8 pad_17[0x9];
} Obj_1_bss_718C0_Entry;

/* fn_1_C3378 */
typedef struct CARDFileInfo_L_C3378 {
    s32 chan;
    s32 fileNo;
    s32 offset;
    s32 length;
    u16 iBlock;
    u16 padding;
} CARDFileInfo_L_C3378;

extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49514(); /* font.c: callers pass a GXColor by value or a u32 pointer */
extern void fn_1_46B4(); /* alloc.c heap free (heap, ptr, file, line) */
extern u32 fn_1_4630(); /* alloc.c heap alloc (heap, size, file, line) */
extern void *fn_1_45D0(); /* alloc.c heap alloc (heap, size, file, line); callers disagree on pointer/int classes */
extern void CARDFormatAsync(u8 byte, int value);
extern f32 C_MTXOrtho(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern s32 DVDClose(u32);
extern BOOL DVDOpen(const char *, Sig_DVDOpen_DVDFileInfo *);
extern void GXGetProjectionv(f32* out);
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern u32 GXGetTexBufferSize(u16 width, u16 height, u32 arg2, u32 arg3, u32 arg4);
extern void GXInvalidateTexAll(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void GXSetCurrentMtx(u32 value);
extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);
extern void OSTicksToCalendarTime(OSTime, OSCalendarTime *);
extern s32 __cvt_fp2unsigned(f32);
extern u64 __div2i(u64, u32, u32);
extern void _restgpr_23(void);
extern void _restgpr_27(void);
extern void _savegpr_23(void);
extern void _savegpr_27(void);
extern void *camera_get_state_object(void);
extern void camera_update_state(void *);
extern void fn_1_107C4C(void *arg);
extern void fn_1_12A2B8(u32 value);
extern void fn_1_12A2C4(u32 value);
extern void fn_1_12A2D0(s32 value);
extern void fn_1_12A734(s32 idx);
extern s32 fn_1_12A8A4(u32 arg0, void *arg1);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_12AC00(void *arg0);
extern s32 fn_1_12ADA0(void *arg0, void *arg1);
extern s16 fn_1_12C930(s16 arg0);
extern s16 fn_1_12CCB0(s16 arg0, s16 arg1);
extern void fn_1_1358BC(s32, s32, s32, s32, s16, s32, s32, s32, f32, f32, f32);
extern void fn_1_135D7C(s32, s32, s32, s32, s16, s32, s32, f32, f32, f32);
extern void *fn_1_14DD68(void *arg0);
extern u8 * fn_1_14F04(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern void fn_1_14FEAC(u8, u8, u8, u32 *, s16);
extern void fn_1_150464(u32 arg0);
extern u32 fn_1_154E34(s32 *);
extern u32 fn_1_1563E8(u32, u32);
extern void fn_1_1596DC(u32);
extern void fn_1_17920(s32 index, void *arg1, f32 t);
extern int fn_1_20A5C(f32 *, f32 *);
extern void *fn_1_21644(void *arg0, f32 *arg1, void *arg2);
extern void fn_1_23500();
extern u8* fn_1_36AD0(void);
extern void fn_1_3920(void);
extern void fn_1_3B34(void);
extern u8 fn_1_3F854(void);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_41328(void *arg0);
extern s32 fn_1_41418(void *resource, u16 id);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_426C(u32 arg0);
extern void fn_1_426E4(void *arg0, void *arg1);
extern void fn_1_4270C(void *arg0, s32 arg1, u32 arg2);
extern void fn_1_42AD0(void *, s32, u16, s32, u16);
extern u32 fn_1_435C(u32 value);
extern void fn_1_43E8(u32 arg0);
extern void fn_1_43F4(void);
extern u32 fn_1_44884(void *);
extern u32 fn_1_451C(void);
extern int fn_1_45730(void *, FileInfo *);
extern int fn_1_45850(FileInfo *);
extern int fn_1_458A0(FileInfo *, void *, u32, u32);

extern s32 fn_1_465D0(s32, s32);

extern s32 fn_1_46C70(void);
extern void fn_1_484CC(u32);
extern s32 fn_1_485A8(s32);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);

extern void fn_1_49528(Color);
extern void fn_1_4953C(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49680(f32 value1, f32 value2);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49714(f32 value1, f32 value2, f32 value3);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4AEB4(f32);
extern u32 fn_1_4AEC0(u32);
extern f32 fn_1_4B068(const char *);
extern void fn_1_4B16C(char *text);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);
extern void fn_1_4CF3C(const char *, f32, ...);
extern void fn_1_4D0A0(void);
extern void fn_1_4D274(Color color, f32 arg1);
extern void fn_1_4D2AC(void *, f32, f32);
extern void fn_1_4D494(void);
extern u32 fn_1_4D4C8(Color, f32, f32);
extern s32 fn_1_4FC50(FontDrawPacket *, s32, s32, s32, void *);
extern void fn_1_4FD64(void);

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern void fn_1_52270(void *, void *);
extern void fn_1_5233C(void);
extern void fn_1_53BD8(Color *, f32, f32, f32, f32, f32);
extern void fn_1_54278(s32 arg0, s32 arg1);
extern void fn_1_5428C(f32 arg0);
extern void fn_1_545B8(void);
extern void fn_1_550A8(void);
extern void fn_1_550E0(void);
extern void fn_1_55210(void *value);
extern void fn_1_55628(Sig_fn_1_55628_Fn1_55628Object *);
extern void fn_1_556B8(void *value);
extern void fn_1_55FC4(f32 value);
extern void fn_1_55FF0(f32 value);
extern u32 fn_1_56018(s32 value);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_1_56858(void *, int);
extern u8 fn_1_5910(void);
extern void fn_1_591A0(s32 id);
extern void fn_1_681C(u32 index, u32 *output);
extern void fn_1_6914(u32 index, u32 *output);
extern void fn_1_7F49C(u8, s16, u32 *);
extern void fn_1_7F658(void *arg0);
extern void fn_1_801F8(s16 arg0, void *arg1);
extern void fn_1_80294(void *arg0, void *arg1, s32 arg2);
extern void fn_1_810E4(u32 arg0);
extern s32 fn_1_8171C(s32 value);
extern void fn_1_850C4(void);
extern void fn_1_854D4(void);
extern void fn_1_85688(void);
extern void fn_1_85934(f32 arg);
extern f32 fn_1_86A2C(void *);
extern void fn_1_87448(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, int flag, f32 f);
extern void fn_1_892FC(void *arg0, int arg1, int arg2);
extern void fn_1_8A1B4(void *arg0, void *arg1, int arg2);
extern void fn_1_8B8A4(void *arg);
extern void fn_1_8B9B8(void *);
extern s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
extern void fn_1_8E1E8(void);
extern void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
extern void fn_1_8E7D0(Fn1_8F45C_Object *obj);
extern void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
extern void fn_1_92554(void *arg0, s32 arg1);
extern void fn_1_93734(CarObject *car, void *name);
extern void fn_1_943F8(Fn935E4Car *, f32, void *);
extern void fn_1_95158(Fn195158Car *car);
extern void fn_1_95210(void *arg0);
extern void fn_1_95EF0(void *arg0, s32 arg_sp0);
extern void fn_1_961F0(void *obj);
extern void fn_1_966A0(Fn1_8F494_Object *obj);
extern void fn_1_968FC(Fn1_8F5A4_Object *obj);
extern u16 fn_1_96968(Fn196968Object *object, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
extern void fn_1_96AE8(void *base, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_9724C(void);
extern void fn_1_A2DC4(u32);
extern void fn_1_A5AA0(void *buffer, void *destination);
extern void fn_1_A5C98(void *);
extern void fn_1_A6840(u8 value);
extern u32 fn_1_A6F1C(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern f32 fn_1_A71AC(void);
extern void fn_1_A7B5C(A7B5C_Obj *obj, A7B5C_Src *src, s8 kind, s8 type, Vec3 *pos);
extern void fn_1_A7E60(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_1_A7F84(void *arg0, u32 arg1);
extern void fn_1_A8270(struct fn_1_A8270_Arg0 *self, s32 arg1);
extern void fn_1_A8528(void *, void *);
extern void fn_1_A861C(void *, void *);
extern void fn_1_A8834(void *, void *);
extern void fn_1_A89B0(void *, void *, s32);
extern void fn_1_A8D4C(void);
extern void fn_1_A8D64(void);
extern void fn_1_A8DD4(const char *format, ...);
extern void fn_1_A8F40(u8 arg0);
extern void fn_1_A93C4(u32 arg0);
extern void fn_1_A9420(u8 value);
extern void fn_1_A942C(u8 value);
extern void fn_1_A943C(int, int);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A948C(int);
extern void fn_1_A96BC(void);
extern void fn_1_A9FFC(s16 x, s16 y, s16 w, s16 h, GXColor color);
extern void fn_1_B81C(Vec3 *, Vec3 *, s32);
extern void fn_1_C40A0(Obj_1_bss_6D838_Target *);
extern void fn_1_C487C(void);
extern void fn_1_C489C(void *arg0);
extern void fn_1_C4ABC(void);
extern void *fn_1_D3884();
extern u32 fn_1_F4810(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7, void *a8);
extern void fn_1_F755C(u8 value);
extern s32 fn_1_F7904(void);
extern s32 fn_1_F7954(void);
extern void fn_1_F79C8(void);
extern s32 fn_1_F7BE4(s16 arg0);
extern void fn_1_FDFF4(void);
extern s32 fn_80006354(void *, void *, u32, u32);
extern void fn_80006E10(u32 arg0);
extern void fn_80007AB4(u8 *arg0);
extern u32 fn_80007CDC(f32 *arg0);
extern u32 fn_80007D58(f32 *arg0);
extern Color fn_80007F70(Color, Color, f32, u32);
extern Color fn_800081C8(Color, Color, f32);
extern void fn_80008204(void *);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *dst, s32 value, s32 size);
extern u32 fn_80008E84(u32 arg0);
extern const char *fn_80019C48(void);
extern void fn_8001A78C(void (*func)(void));
extern void fn_8001A7D0(void (*func)(void));
extern int fn_8002A744(void);
extern void fn_8002A74C(u16 value);
extern s32 fn_8002C0A0(s32);
extern s32 fn_8002DFE0(s32, void *, CARDCallback);
extern s32 fn_8002FC14(s32 chan, void *fileName);
extern s32 fn_80030338(s32 chan, void *oldName, void *newName);
extern void fn_80030754(u8 value, void *data, int size, int mode);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_8003526C(u32, u8);
extern u32 fn_80038EEC(void);
extern void fn_80038F10(f32* out);
extern void fn_8006E250(Vec3 *, Vec3 *);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_8006F6A8(void *arg0);
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_800711A8(void *value);
extern CarR29 *fn_80071268(void *, void *);
extern void fn_800712E4(void *arg0, u32 arg1, void *arg2);
extern void fn_800713E0(struct Sig_fn_800713E0_fn_800713E0_Arg0 *, u32);
extern u32 fn_80071470(u32, u32);
extern void fn_80071718(void *value);
extern void fn_800720B0(s32 arg0);
extern void fn_80072270(void *);
extern void fn_8007245C(u32 value);
extern void fn_80072558(void);
extern void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32, f32);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80074300(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u32 lab_unused0);
extern void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80074660(u32 arg0);
extern void fn_800746A8();
extern void fn_80074718(u8 value, s32 arg);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern u32 fn_80074918(u32, u32, u32);
extern u32 fn_80074A7C(u32 arg0);
extern u32 fn_80077A18(void);
extern void fn_80077A20(struct fn_1_A8270_Rec *, void *);
extern u32 fn_80077D40();
extern u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_bss_6D828;
extern u32 lbl_1_bss_6D850;
extern u32 lbl_1_bss_6D86C[34];
extern u32 lbl_1_bss_6D8F4[31];
extern u32 lbl_1_bss_6D970;
extern u32 lbl_1_bss_6D974;
extern u32 lbl_1_bss_6D978;
extern u32 lbl_1_bss_6D97C;
extern u8 lbl_1_bss_6DA5C[30];
extern u32 lbl_1_bss_6E978[3];
extern s32 lbl_1_bss_6E984;
extern u32 lbl_1_bss_6E98C;
extern Fn1A9250Entry lbl_1_bss_70658[];
extern u32 lbl_1_bss_71658[6];
extern u32 lbl_1_bss_71670;
extern u8 lbl_1_bss_8CA28;
extern fn_1_A948C_Font lbl_1_data_1AEA8[];
extern void *lbl_1_data_2AA24[];
extern u8 lbl_1_data_2B0D4[];
extern u32 lbl_1_rodata_26F8;
extern f32 lbl_1_rodata_3508[];
extern f32 lbl_1_rodata_3518[6];
extern f32 lbl_1_rodata_3530[22];
extern u8 lbl_1_rodata_3590[984];
extern u8 lbl_1_rodata_3968[232];
extern u32 lbl_1_rodata_3A94[7];
extern u32 lbl_1_rodata_3B20[3];
extern f32 lbl_1_rodata_3B2C[47];
extern Triple lbl_1_rodata_3BE8;
extern u32 lbl_1_rodata_3BF4[14];
extern f32 lbl_1_rodata_3C2C[33];
extern u8 lbl_1_rodata_3D34[164];
extern u8 lbl_1_rodata_3DD8[84];
extern const f32 lbl_1_rodata_3E48[];
extern const f32 lbl_1_rodata_3F6C;
extern f32 lbl_1_rodata_3F70[12];
extern u32 lbl_1_rodata_3FA0[28];
extern f32 lbl_1_rodata_4010[60];
extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern f32 lbl_1_rodata_4A34[25];
extern const f64 lbl_1_rodata_4A98;
extern struct fn_1_A9868_lbl_1_rodata_4AA0 lbl_1_rodata_4AA0;
extern f32 lbl_1_rodata_4AC4[4];
extern Unk_23800000 lbl_23800000[];
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D188(s16);
extern f32 lbl_8006D21C(s32);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern void lbl_8006D668(void *);
extern void lbl_8006D758(void);
extern void lbl_8006D784(void *);
extern void lbl_8006D7DC(void *value);
extern void lbl_8006D7F4(f32, f32, f32);
extern u32 lbl_8006D91C(u32);
extern u32 lbl_8006D998(u32);
extern void lbl_8006D9D8(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *arg0);
extern u32 lbl_8006DBE4(void);
extern void lbl_8006DC6C(void *, u32, u32);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *pos);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *arg0);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void lbl_8006E2C0(Vec3 *, f32, f32, f32);
extern void *lbl_801A6410;
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern u32 lbl_801A66C8;
extern FnA8528Config *lbl_801A6D00;
extern void mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_z(s32);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void *memset(void *, int, u32);
extern int sprintf(char *, const char *, ...);
extern void strcat(void *dst, void *src);
extern char *strchr(const char *str, int c);
extern s32 strcmp(void *, void *);
extern void strcpy(void *dst, void *src);
extern size_t strlen(const char *);
extern char *strncat(char *, const char *, unsigned long);
extern s32 strncmp(const char *, const char *, size_t);
extern void strncpy(void *arg0, void *arg1, int arg2);
extern char *strrchr(const char *str, int c);
extern void *strstr(void *, void *);

void fn_1_AA590(void);
void fn_1_AA6D8(u8 kind, u8 slot, DriverParam *param);
void fn_1_AAB98(void);
void fn_1_AAEB0(struct fn_1_AAEB0_Arg0 *arg0);
void fn_1_AAF18(void);
void fn_1_AAF1C(fn_1_AAB98_Entry *obj);
void fn_1_AB434(void);
void fn_1_AB438(Fn1AB438Data *data);
void fn_1_AB458(void);
void fn_1_AB45C(int index);
void fn_1_AB478(Fn1AB478Obj *obj);
void fn_1_AB4F4(fn_1_AB4F4_ArgStruct *arg);
void fn_1_AB598(fn_1_AB598_ArgStruct *arg);
void fn_1_AB5CC(fn_1_AB5CC_ArgStruct *arg);
void fn_1_AB61C(fn_1_AB61C_MemcardArg *arg);
void fn_1_AB64C(MemcardArg *arg);
void fn_1_AB75C(fn_1_AB75C_ArgStruct *arg);
void fn_1_AB7C4(fn_1_AB7C4_ArgStruct *arg);
void fn_1_AB870(fn_1_AB870_ArgStruct *arg);
void fn_1_AB880(fn_1_AB5CC_ArgStruct *arg);
void fn_1_AB8D8(fn_1_AB8D8_ArgStruct *arg);
void fn_1_AB93C(fn_1_AB5CC_ArgStruct *arg);
void fn_1_AB98C(fn_1_AB870_ArgStruct *arg);
void fn_1_AB99C(fn_1_AB99C_ArgStruct *arg);
void fn_1_ABA14(fn_1_AB870_ArgStruct *arg);
void fn_1_ABA24(fn_1_AB99C_ArgStruct *arg);
void fn_1_ABA9C(fn_1_AB870_ArgStruct *arg);
void fn_1_ABAAC(fn_1_ABAAC_ArgStruct *arg);
void fn_1_ABB24(fn_1_ABB24_MemcardArg *arg);
void fn_1_ABB4C(MemcardArg *arg);
void fn_1_ABC5C(fn_1_ABC5C_ArgStruct *arg);
void fn_1_ABC98(fn_1_ABC98_ArgStruct *arg);
void fn_1_ABCE8(fn_1_ABCE8_ArgStruct *arg);
void fn_1_ABD58(fn_1_ABC98_ArgStruct *arg);
void fn_1_ABDA8(fn_1_AB870_ArgStruct *arg);
void fn_1_ABDB8(fn_1_ABDB8_ArgStruct *arg);
void fn_1_ABE14(Fn1ABE14Arg *arg);
void fn_1_ABE88(void *arg0);
void fn_1_ABF44(Fn1ABF44Object *arg);
void fn_1_AC000(Fn1AC000Target *target);
void fn_1_AC12C(fn_1_AC12C_MemcardRequest *request);
void fn_1_AC188(Fn1AC188Target *target);
void fn_1_AC294(Fn1AC294Target *target);
void fn_1_AC2D8(Fn1AC2D8Target *target);
void fn_1_AC328(Fn1AC328Target *target);
void fn_1_AC38C(Fn1AC38Target *target);
void fn_1_AC3DC(Fn1AC328Target *target);
void fn_1_AC464(Fn1AC464Target *target);
void fn_1_AC4B4(Fn1AC4B4Target *target);
void fn_1_AC4C4(Fn1AC4C4Target *target);
void fn_1_AC53C(void *arg0);
void fn_1_AC6A4(void);
void fn_1_AC6A8(Fn1AC6A8Data *data);
void fn_1_AC6C8(void);
void fn_1_AC6CC(fn_1_AC6CC_MemCardState *self);
void fn_1_AC6DC(void);
void fn_1_AC6E0(void *r3);
void fn_1_AC700(void);
void fn_1_AC704(void *r3);
void fn_1_AC74C(void *r3);
void fn_1_AC79C(void *arg0);
void fn_1_AC904(void);
void fn_1_AC908(Fn1AC908State *state);
void fn_1_AC928(void);
u32 fn_1_AC92C(struct fn_1_AC92C_Arg0 *arg0);
void fn_1_AC960(struct MemcardObject *obj);
void fn_1_ACA00(Fn1Aca00Target *self);
void fn_1_ACA1C(fn_1_ACA1C_MemCardState *state);
void fn_1_ACA78(void *arg0);
void fn_1_ACD00(void);
void fn_1_ACD04(Fn1Acd04Obj *obj);
void fn_1_ACE7C(void);
void fn_1_ACE80(fn_1_ACE80_SomeObject* obj);
void fn_1_ACEBC(fn_1_ACE80_SomeObject* obj);
void fn_1_ACF0C(Object* obj);
void fn_1_ACF2C(void);
void fn_1_ACF30(MemcardObject_ACD04* obj);
void fn_1_AD098(void);
void fn_1_AD09C(void);
void fn_1_AD0A0(void *arg0);
void fn_1_AD140(const u8 *status_byte);
void fn_1_AD164(void);
void fn_1_AD168(Fn1AD168Obj *obj);
void fn_1_AD1AC(Fn1AD1ACObject *object);
void fn_1_AD1E4(Fn1AD1E4State *state, Fn1AD1E4Object *object);
void fn_1_AD264(CardTask *a);
void fn_1_AEC34(Fn1AEC34A *request, Fn1AEC34B *operation);
void fn_1_AECCC(MemcardObj *arg0, u32 unused);
void fn_1_B03A8(void *arg0, void *arg1);
void fn_1_B03CC(B03CC_State *arg0);
void fn_1_B1710(int unused, void *ptr);
void fn_1_B171C(void *arg0);
void fn_1_B22AC(MemcardCtx *ctx, s32 kind);
void fn_1_B2770(int unused, void *ptr);
void fn_1_B277C(UnkCtx_1_B277C *ctx);
void fn_1_B38F4(int unused, void *ptr);
void fn_1_B3900(u8 *arg0);
void fn_1_B40B4(int unused, void *ptr);
void fn_1_B40C0(void *arg0);
void fn_1_B4AC0(void);
void fn_1_B5258(char *destination, void *unused, const char *source, const char *suffix);
void fn_1_B5310(void);
void fn_1_B5654(void);
void fn_1_B5A3C(void);
void fn_1_B5F00(B5F00Source *source, B5F00Dest *dest);
void fn_1_B5F20(void);
void fn_1_B6B28(void);
u8 fn_1_B7C00(void);
u32 fn_1_B7C5C(void);
s32 fn_1_B7C6C(u32 arg0);
u8 fn_1_B7CD4(void);
void fn_1_B7CE4(s32 arg0, char *arg1);
void fn_1_B7E14(void *memory_card_state);
int fn_1_B7E48(void);
int fn_1_B7E98(int index);
int fn_1_B7EC4(int index);
s32 fn_1_B7EF8(void);
u32 fn_1_B7F08(void);
void fn_1_B7F24(void);
int fn_1_B7F58(s64 *time);
u32 fn_1_B7FC8(void);
void fn_1_B7FDC(u8 unused);
int fn_1_B800C(s32 index);
void fn_1_B80F0(s32 index);
u32 fn_1_B8170(s32 card);
s32 fn_1_B8338(s32 chan);
int fn_1_B88C4(void);
void fn_1_B8E84(s32 card, u8 *out_flags, u32 *out_a, u32 *out_b);
s32 fn_1_B8EDC(s32 index);
void fn_1_B9904(s32 idx, u8 state, s32 type, u32 arg3);
void fn_1_B9BE0(void);
void fn_1_B9C0C(void);
void fn_1_B9C38(s32 index);
void fn_1_B9CCC(s32 index, u32 flags);
void fn_1_B9DE8(MemcardArg_B9DE8 *arg0);
s32 fn_1_BA144(fn_1_EF4F8_Obj_1_bss_7ECB4 *arg0);
void fn_1_BB974(void *unused);
void fn_1_BC29C(void);
void fn_1_BC310(McMenu *menu);
void fn_1_BE978(s32 x, s32 y, s32 width, s32 height, u32 *color);
void fn_1_BED04(s32 x, s32 y, s32 width, s32 height, u32 *color, s32 flip);
void fn_1_BF198(s32 a0, s32 a1, s32 a2, s32 a3, struct BF198_Arg4 *a4);
void fn_1_BF520(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4);
void fn_1_BF600(s32 a, s32 b, s32 c, s32 d, u32 *source, f32 initial);
void fn_1_BF700(s32 index, s32 cell, s32 mode, s32 x, s32 y, f32 scale_x, f32 scale_y, f32 z);
void fn_1_BF9C4(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4);
void fn_1_BFBF4(s32 arg0, s32 arg3, s32 arg4, f32 arg1, f32 arg2);
void fn_1_BFCF8(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6);
void fn_1_BFE20(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void fn_1_C00EC(u8 a, u8 b, s32 x, s32 y, f32 scale);
void fn_1_C023C(s32 a, s32 b, f32 value, s32 c, s32 d, s32 e, s32 f, s32 g, f32 unused);
void fn_1_C0374(s32 arg0, s32 arg1, f32 value, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, f32 unused);
void fn_1_C0510(Fn1C0510Obj *obj);
void fn_1_C062C(SaveReq *req, Slot_C062C *first, Slot_C062C *second);
void fn_1_C0B0C(MemcardRequest_C0B0C *req, void *unused1, void *unused2);
void fn_1_C0E00(SaveReq *req, Slot_C0E00 *first, Slot_C0E00 *second);
void fn_1_C132C(Fn1C132CObject *object, u8 *data, void *unused2);
void fn_1_C1394(McState *state);
void fn_1_C17CC(void *unused0, void *unused1, void *unused2);
void fn_1_C17D0(void *arg0, MemCardFile *file, MemCardFile *prev);
void fn_1_C1ACC(u32 arg0, MemcardEntry_C1ACC *arg1, void *unused2);
void *fn_1_C1CFC(void *src, u32 w, u32 h, f32 scale);
void fn_1_C23CC(void *base0, u32 stride0, u32 arg2, void *base1, u32 stride1, u32 count_add, u32 offset, u32 count);
void fn_1_C2454(void);
s32 fn_1_C24A4(void);
void fn_1_C3378(void);
void fn_1_C34F0(void);
u32 fn_1_C3688(void);
void fn_1_C36EC(void);
void fn_1_C37A0(void);

/* TU M data objects (mkdefs.py) */
typedef struct MemcardKind {
    char name[31];
    u8 index;
    char file[28];
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 caption; /* row of the caption table lbl_1_data_3B74C */
    u32 unk_40;
    s32 unk_44;
    s32 unk_48;
} MemcardKind;

static const MemcardKind lbl_1_rodata_4AE0[6] = {
    { "f_zero_debug", 0, "sys_e.bin", 0, 0, 0x03, 0x50, 4, -1, -1 },
    { "f_zero", 1, "sys_e.bin", 0, 0, 0x0B, 0x4F, 0x59E0, -1, -1 },
    { "fzg", 2, "gho_e.bin", 0, 0, 0x01, 0x53, 0, -1, -1 },
    { "fzc", 3, "gar_e.bin", 0, 0, 0x01, 0x54, 0x20700, -1, -1 },
    { "fze", 4, "emb_e.bin", 0, 0, 0x01, 0x52, 0, -1, -1 },
    { "fzr", 5, "rep_e.bin", 0, 0, 0x04, 0x51, 0, -1, -1 },
};
/* card buffer swap flag: tested and cleared throughout the TU, never set here */
static u8 lbl_1_bss_716C0 = 0;
/* Unknown retail object: 4 unread bytes */
static u32 lbl_1_bss_716C4 = 0;
static fn_1_AAB98_Entry lbl_1_bss_716C8[2];
static u32 lbl_1_bss_71808;
s32 lbl_1_bss_7180C;
static fn_1_AAB98_Entry lbl_1_bss_71810;
static u8 lbl_1_bss_718B0;
static u8 lbl_1_bss_718B1;
static u16 lbl_1_bss_718B2;
static s32 lbl_1_bss_718B4;
static u8 lbl_1_bss_718B8;
static u8 lbl_1_bss_718B9;
static s32 lbl_1_bss_718BC;
u8 lbl_1_bss_718C0[32];
u8 lbl_1_bss_718E0[23008];
static s32 lbl_1_bss_772C0[2];
static char lbl_1_bss_772C8[0x40];
static u8 lbl_1_bss_77308;
static u8 lbl_1_bss_77309;
static s8 lbl_1_bss_7730A;
u32 lbl_1_bss_7730C;
s32 lbl_1_bss_77310;
static u32 lbl_1_bss_77314;
static s32 lbl_1_bss_77318;
static s32 lbl_1_bss_7731C;
static s32 lbl_1_bss_77320;
static s32 lbl_1_bss_77324;
static u8 lbl_1_bss_77328[12];
static s32 lbl_1_bss_77334;
static u8 lbl_1_bss_77338;
static u8 lbl_1_bss_77339;
static u32 lbl_1_bss_7733C[2];
static s32 lbl_1_bss_77344[2][6];
/* 32-byte aligned (retail leaves 12 bytes after lbl_1_bss_77344): CARD transfers need 32-byte aligned buffers */
McFile lbl_1_bss_77380[2][128] __attribute__((aligned(32)));
static void * lbl_1_bss_7A380[2];
static u64 lbl_1_bss_7A388[2];
static u8 lbl_1_bss_7A398;
static u8 lbl_1_bss_7A39C[2032];
static u8 lbl_1_bss_7AB8C;
static u32 lbl_1_bss_7AB90;
static char lbl_1_bss_7AB94[0x20];
static u32 lbl_1_bss_7ABB4;
static u32 lbl_1_bss_7ABB8;
/* accepted shortcut: only byte 0 is read or written; the next object starts 8 bytes on (Unknown retail object) */
static u8 lbl_1_bss_7ABBC[8];
static u8 lbl_1_bss_7ABC4;
static u32 lbl_1_bss_7ABC8;
/* accepted shortcut: only byte 0 is read or written; the rest of the extent to the TU end is unread (Unknown retail object) */
static u8 lbl_1_bss_7ABCC[84];
static u32 lbl_1_data_35AC8 = 67371008;
static char lbl_1_data_35ACC[12] = "OVERTAKE";
static char lbl_1_data_35AD8[8] = "JUMP";
static char lbl_1_data_35AE0[12] = "ENEMYHIT";
static char lbl_1_data_35AEC[8] = "WALLHIT";
static char lbl_1_data_35AF4[12] = "SIDEBYSIDE";
static char lbl_1_data_35B00[8] = "START";
static char lbl_1_data_35B08[8] = "GOAL";
static char lbl_1_data_35B10[4] = "LAP";
static char *lbl_1_data_35B14[8] = {lbl_1_data_35ACC, lbl_1_data_35AD8, lbl_1_data_35AE0, lbl_1_data_35AEC, lbl_1_data_35AF4, lbl_1_data_35B00, lbl_1_data_35B08, lbl_1_data_35B10};
static char lbl_1_data_35B34[20] = "./memcard/emb_e.bin";
static char lbl_1_data_35B48[20] = "./memcard/emb.bin";
static char *lbl_1_data_35B5C[6] = {lbl_1_data_35B34, lbl_1_data_35B34, lbl_1_data_35B34, lbl_1_data_35B34, lbl_1_data_35B34, lbl_1_data_35B48};
static char lbl_1_data_35B74[20] = "./memcard/gho_e.bin";
static char lbl_1_data_35B88[20] = "./memcard/gho.bin";
static char *lbl_1_data_35B9C[6] = {lbl_1_data_35B74, lbl_1_data_35B74, lbl_1_data_35B74, lbl_1_data_35B74, lbl_1_data_35B74, lbl_1_data_35B88};
static char lbl_1_data_35BB4[20] = "./memcard/rep_e.bin";
static char lbl_1_data_35BC8[20] = "./memcard/rep.bin";
static char *lbl_1_data_35BDC[6] = {lbl_1_data_35BB4, lbl_1_data_35BB4, lbl_1_data_35BB4, lbl_1_data_35BB4, lbl_1_data_35BB4, lbl_1_data_35BC8};
static char lbl_1_data_35BF4[80] = "A Memory Card is not inserted in SLOT.\nPlease properly insert a Memory Card.";
static char lbl_1_data_35C44[12] = "NOCARD GER";
static char lbl_1_data_35C50[12] = "NOCARD FRA";
static char lbl_1_data_35C5C[12] = "NOCARD SPA";
static char lbl_1_data_35C68[12] = "NOCARD ITA";
static char lbl_1_data_35C74[108] = "SLOT\202\311\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251[\202\335]\202\302\202\251\202\350\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\314\220\332[\202\271\202\302]\221\261[\202\274\202\255]\202\360\212m[\202\251\202\255]\224F[\202\311\202\361]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_35CE0[68] = "The device in SLOT is not supported.\nPlease insert a Memory Card.";
static char lbl_1_data_35D24[16] = "WRONGDEVICE GER";
static char lbl_1_data_35D34[16] = "WRONGDEVICE FRA";
static char lbl_1_data_35D44[16] = "WRONGDEVICE SPA";
static char lbl_1_data_35D54[16] = "WRONGDEVICE ITA";
static char lbl_1_data_35D64[96] = "SLOT\202\311\202\315\n\203\201\203\202\203\212\201[\203J\201[\203h\210\310[\202\242]\212O[\202\252\202\242]\202\314\202\340\202\314\202\252\202\263\202\263\202\301\202\304\202\242\202\334\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\202\263\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_35DC4[112] = "A fatal error has occured.\nTurn the power off and refer to the Nintendo GameCube\nhardware manual for details. ";
static char lbl_1_data_35E34[12] = "FATAL GER";
static char lbl_1_data_35E40[12] = "FATAL FRA";
static char lbl_1_data_35E4C[12] = "FATAL SPA";
static char lbl_1_data_35E58[12] = "FATAL ITA";
static char lbl_1_data_35E64[232] = "\222v[\202\277]\226\275[\202\337\202\242]\223I[\202\304\202\253]\202\310\203G\203\211\201[\202\252\213N[\202\250]\202\261\202\350\202\334\202\265\202\275\201B\n\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203p\203\217\201[\203{\203^\203\223\202\360\211\237[\202\250]\202\265\202\304\n\223d[\202\305\202\361]\214\271[\202\260\202\361]\202\360\202n\202e\202e\202\311\202\265\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\216\346[\202\306]\202\350\210\265[\202\240\202\302\202\251]\202\242\220\340[\202\271\202\302]\226\276[\202\337\202\242]\217\221[\202\265\202\345]\202\314\n\216w[\202\265]\216\246[\202\266]\202\311\217][\202\265\202\275\202\252]\202\301\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_35F4C[88] = "This data version is incorrect.\nSave game data again in the Game Data menu in Options. ";
static char lbl_1_data_35FA4[12] = "VERSION GER";
static char lbl_1_data_35FB0[12] = "VERSION FRA";
static char lbl_1_data_35FBC[12] = "VERSION SPA";
static char lbl_1_data_35FC8[12] = "VERSION ITA";
static char lbl_1_data_35FD4[104] = "\203f\201[\203^\202\314\203o\201[\203W\203\207\203\223\202\252\210\341[\202\277\202\252]\202\242\202\334\202\267\201B\n\203I\203v\203V\203\207\203\223\202\314\203Q\201[\203\200\203f\201[\203^\202\305\n\203f\201[\203^\202\360\203Z\201[\203u\202\265\222\274[\202\310\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_3603C[52] = "\203\237 \201c Continue without loading\n  \203\262 \201c Try again ";
static char lbl_1_data_36070[24] = "CAPTION_LOAD_RETRY GER";
static char lbl_1_data_36088[24] = "CAPTION_LOAD_RETRY FRA";
static char lbl_1_data_360A0[24] = "CAPTION_LOAD_RETRY SPA";
static char lbl_1_data_360B8[24] = "CAPTION_LOAD_RETRY ITA";
static char lbl_1_data_360D0[40] = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_360F8[48] = "\203\237 \201c Continue without saving\n\203\262 \201c Try again ";
static char lbl_1_data_36128[24] = "CAPTION_SAVE_RETRY GER";
static char lbl_1_data_36140[24] = "CAPTION_SAVE_RETRY FRA";
static char lbl_1_data_36158[24] = "CAPTION_SAVE_RETRY SPA";
static char lbl_1_data_36170[24] = "CAPTION_SAVE_RETRY ITA";
static char lbl_1_data_36188[40] = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_361B0[48] = "\203\237 \201c Continue without saving\n\203\262 \201c Try again";
static char lbl_1_data_361E0[24] = "CAPTION_LIST_RETRY GER";
static char lbl_1_data_361F8[24] = "CAPTION_LIST_RETRY FRA";
static char lbl_1_data_36210[24] = "CAPTION_LIST_RETRY SPA";
static char lbl_1_data_36228[24] = "CAPTION_LIST_RETRY ITA";
static char lbl_1_data_36240[48] = "\203\237\201c\203\212\203X\203g\202\360\216\346[\202\306]\202\347\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_36270[48] = "\203\237 \201c Continue without erasing\n\203\262 \201c Try again ";
static char lbl_1_data_362A0[28] = "CAPTION_DELETE_RETRY GER";
static char lbl_1_data_362BC[28] = "CAPTION_DELETE_RETRY FRA";
static char lbl_1_data_362D8[28] = "CAPTION_DELETE_RETRY SPA";
static char lbl_1_data_362F4[28] = "CAPTION_DELETE_RETRY ITA";
static char lbl_1_data_36310[40] = "\203\237\201c\217\301[\202\257]\202\263\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_36338[52] = "\203\237 \201c Continue without checking\n\203\262 \201c Try again ";
static char lbl_1_data_3636C[28] = "CAPTION_DELETE_RETRY GER";
static char lbl_1_data_36388[28] = "CAPTION_DELETE_RETRY FRA";
static char lbl_1_data_363A4[28] = "CAPTION_DELETE_RETRY SPA";
static char lbl_1_data_363C0[28] = "CAPTION_DELETE_RETRY ITA";
static char lbl_1_data_363DC[44] = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_36408[68] = "\203\237 \201c Continue without loading\n\203\262 \201c Try again\n\203\264 \201c Choose Slot ";
static char lbl_1_data_3644C[32] = "CAPTION_LOAD_RETRY_CHOICE GER";
static char lbl_1_data_3646C[32] = "CAPTION_LOAD_RETRY_CHOICE FRA";
static char lbl_1_data_3648C[32] = "CAPTION_LOAD_RETRY_CHOICE SPA";
static char lbl_1_data_364AC[32] = "CAPTION_LOAD_RETRY_CHOICE ITA";
static char lbl_1_data_364CC[68] = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36510[68] = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\n\203\264 \201c Choose Slot ";
static char lbl_1_data_36554[32] = "CAPTION_SAVE_RETRY_CHOICE GER";
static char lbl_1_data_36574[32] = "CAPTION_SAVE_RETRY_CHOICE FRA";
static char lbl_1_data_36594[32] = "CAPTION_SAVE_RETRY_CHOICE SPA";
static char lbl_1_data_365B4[32] = "CAPTION_SAVE_RETRY_CHOICE ITA";
static char lbl_1_data_365D4[68] = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36618[48] = "\203\237 \201c Continue without saving\n\203\262 \201c Try again ";
static char lbl_1_data_36648[32] = "CAPTION_LIST_RETRY_CHOICE GER";
static char lbl_1_data_36668[32] = "CAPTION_LIST_RETRY_CHOICE FRA";
static char lbl_1_data_36688[32] = "CAPTION_LIST_RETRY_CHOICE SPA";
static char lbl_1_data_366A8[32] = "CAPTION_LIST_RETRY_CHOICE ITA";
static char lbl_1_data_366C8[48] = "\203\237\201c\203\212\203X\203g\202\360\216\346[\202\306]\202\347\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_366F8[68] = "\203\237 \201c Continue without erasing\n\203\262 \201c Try again\n\203\264 \201c Choose Slot ";
static char lbl_1_data_3673C[32] = "CAPTION_DELETE_RETRY_CHOICE GER";
static char lbl_1_data_3675C[32] = "CAPTION_DELETE_RETRY_CHOICE FRA";
static char lbl_1_data_3677C[32] = "CAPTION_DELETE_RETRY_CHOICE SPA";
static char lbl_1_data_3679C[32] = "CAPTION_DELETE_RETRY_CHOICE ITA";
static char lbl_1_data_367BC[68] = "\203\237\201c\217\301[\202\257]\202\263\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36800[68] = "\203\237 \201c Continue without checking\n\203\262 \201c Try again\n\203\264 \201c Choose Slot ";
static char lbl_1_data_36844[32] = "CAPTION_DELETE_RETRY_CHOICE GER";
static char lbl_1_data_36864[32] = "CAPTION_DELETE_RETRY_CHOICE FRA";
static char lbl_1_data_36884[32] = "CAPTION_DELETE_RETRY_CHOICE SPA";
static char lbl_1_data_368A4[32] = "CAPTION_DELETE_RETRY_CHOICE ITA";
static char lbl_1_data_368C4[68] = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36908[32] = "Please press the \203\237 Button. ";
static char lbl_1_data_36928[16] = "CAPTION_A GER";
static char lbl_1_data_36938[16] = "CAPTION_A FRA";
static char lbl_1_data_36948[16] = "CAPTION_A SPA";
static char lbl_1_data_36958[16] = "CAPTION_A ITA";
static char lbl_1_data_36968[28] = "\203\237\202\360\211\237[\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_36984[20] = "\203\237 \201c Delete file";
static char lbl_1_data_36998[16] = "CAPTION_A GER";
static char lbl_1_data_369A8[16] = "CAPTION_A FRA";
static char lbl_1_data_369B8[16] = "CAPTION_A SPA";
static char lbl_1_data_369C8[16] = "CAPTION_A ITA";
static char lbl_1_data_369D8[16] = "\203\237\201c\217\301[\202\257]\202\267";
static char lbl_1_data_369E8[52] = "\203\237 \201c Continue without loading\n\203\264 \201c Choose a Slot ";
static char lbl_1_data_36A1C[24] = "CAPTION_LOAD_CHOICE GER";
static char lbl_1_data_36A34[24] = "CAPTION_LOAD_CHOICE FRA";
static char lbl_1_data_36A4C[24] = "CAPTION_LOAD_CHOICE SPA";
static char lbl_1_data_36A64[24] = "CAPTION_LOAD_CHOICE ITA";
static char lbl_1_data_36A7C[52] = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36AB0[52] = "\203\237 \201c Continue without saving\n\203\264 \201c Choose a Slot ";
static char lbl_1_data_36AE4[24] = "CAPTION_SAVE_CHOICE GER";
static char lbl_1_data_36AFC[24] = "CAPTION_SAVE_CHOICE FRA";
static char lbl_1_data_36B14[24] = "CAPTION_SAVE_CHOICE SPA";
static char lbl_1_data_36B2C[24] = "CAPTION_SAVE_CHOICE ITA";
static char lbl_1_data_36B44[52] = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36B78[32] = "\203\237 \201c Continue without saving";
static char lbl_1_data_36B98[24] = "CAPTION_LIST_CHOICE GER";
static char lbl_1_data_36BB0[24] = "CAPTION_LIST_CHOICE FRA";
static char lbl_1_data_36BC8[24] = "CAPTION_LIST_CHOICE SPA";
static char lbl_1_data_36BE0[24] = "CAPTION_LIST_CHOICE ITA";
static char lbl_1_data_36BF8[36] = "\203\237\201c\203\212\203X\203g\202\360\216\346[\202\306]\202\347\202\270\202\311\217I[\202\250]\202\355\202\351";
static char lbl_1_data_36C1C[52] = "\203\237 \201c Continue without erasing\n\203\264 \201c Choose a Slot ";
static char lbl_1_data_36C50[28] = "CAPTION_DELETE_CHOICE GER";
static char lbl_1_data_36C6C[28] = "CAPTION_DELETE_CHOICE FRA";
static char lbl_1_data_36C88[28] = "CAPTION_DELETE_CHOICE SPA";
static char lbl_1_data_36CA4[28] = "CAPTION_DELETE_CHOICE ITA";
static char lbl_1_data_36CC0[48] = "\203\237\201c\202\257\202\263\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36CF0[56] = "\203\237 \201c Continue without checking\n\203\264 \201c Choose a Slot ";
static char lbl_1_data_36D28[28] = "CAPTION_DELETE_CHOICE GER";
static char lbl_1_data_36D44[28] = "CAPTION_DELETE_CHOICE FRA";
static char lbl_1_data_36D60[28] = "CAPTION_DELETE_CHOICE SPA";
static char lbl_1_data_36D7C[28] = "CAPTION_DELETE_CHOICE ITA";
static char lbl_1_data_36D98[56] = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
static char lbl_1_data_36DD0[64] = "\203\237 \201c Continue without loading\n\203\262 \201c Try again\n\203\264 \201c Format ";
static char lbl_1_data_36E10[32] = "CAPTION_LOAD_RETRY_FORMAT GER";
static char lbl_1_data_36E30[32] = "CAPTION_LOAD_RETRY_FORMAT FRA";
static char lbl_1_data_36E50[32] = "CAPTION_LOAD_RETRY_FORMAT SPA";
static char lbl_1_data_36E70[32] = "CAPTION_LOAD_RETRY_FORMAT ITA";
static char lbl_1_data_36E90[64] = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351";
static char lbl_1_data_36ED0[60] = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\n\203\264 \201c Format ";
static char lbl_1_data_36F0C[32] = "CAPTION_SAVE_RETRY_FORMAT GER";
static char lbl_1_data_36F2C[32] = "CAPTION_SAVE_RETRY_FORMAT FRA";
static char lbl_1_data_36F4C[32] = "CAPTION_SAVE_RETRY_FORMAT SPA";
static char lbl_1_data_36F6C[32] = "CAPTION_SAVE_RETRY_FORMAT ITA";
static char lbl_1_data_36F8C[64] = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351";
static char lbl_1_data_36FCC[60] = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\n\203\264 \201c Format ";
static char lbl_1_data_37008[32] = "CAPTION_LIST_RETRY_FORMAT GER";
static char lbl_1_data_37028[32] = "CAPTION_LIST_RETRY_FORMAT FRA";
static char lbl_1_data_37048[32] = "CAPTION_LIST_RETRY_FORMAT SPA";
static char lbl_1_data_37068[32] = "CAPTION_LIST_RETRY_FORMAT ITA";
static char lbl_1_data_37088[68] = "\203\237\201c\203\212\203X\203g\202\360\202\306\202\347\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351";
static char lbl_1_data_370CC[64] = "\203\237 \201c Continue without erasing\n\203\262 \201c Try again\n\203\264 \201c Format ";
static char lbl_1_data_3710C[32] = "CAPTION_DELETE_RETRY_FORMAT GER";
static char lbl_1_data_3712C[32] = "CAPTION_DELETE_RETRY_FORMAT FRA";
static char lbl_1_data_3714C[32] = "CAPTION_DELETE_RETRY_FORMAT SPA";
static char lbl_1_data_3716C[32] = "CAPTION_DELETE_RETRY_FORMAT ITA";
static char lbl_1_data_3718C[60] = "\203\237\201c\202\257\202\263\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351";
static char lbl_1_data_371C8[64] = "\203\237 \201c Continue without checking\n\203\262 \201c Try again\n\203\264 \201c Format ";
static char lbl_1_data_37208[32] = "CAPTION_DELETE_RETRY_FORMAT GER";
static char lbl_1_data_37228[32] = "CAPTION_DELETE_RETRY_FORMAT FRA";
static char lbl_1_data_37248[32] = "CAPTION_DELETE_RETRY_FORMAT SPA";
static char lbl_1_data_37268[32] = "CAPTION_DELETE_RETRY_FORMAT ITA";
static char lbl_1_data_37288[64] = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351";
static char lbl_1_data_372C8[44] = "\203\237 \201c Begin without saveing\n\203\262 \201c Try again";
static char lbl_1_data_372F4[24] = "CAPTION_SAVE_RETRY GER";
static char lbl_1_data_3730C[24] = "CAPTION_SAVE_RETRY FRA";
static char lbl_1_data_37324[24] = "CAPTION_SAVE_RETRY SPA";
static char lbl_1_data_3733C[24] = "CAPTION_SAVE_RETRY ITA";
static char lbl_1_data_37354[44] = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\216n[\202\315\202\266]\202\337\202\351 \203\262\201c\203\212\203g\203\211\203C";
static char lbl_1_data_37380[92] = "\203\237 \201c Begin without saving\n\203\262 \201c Try again\n\203\264 \201c Reset and access system Memory Card screen";
static char lbl_1_data_373DC[24] = "CAPTION_SAVE_RETRY GER";
static char lbl_1_data_373F4[24] = "CAPTION_SAVE_RETRY FRA";
static char lbl_1_data_3740C[24] = "CAPTION_SAVE_RETRY SPA";
static char lbl_1_data_37424[24] = "CAPTION_SAVE_RETRY ITA";
static char lbl_1_data_3743C[108] = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\216n[\202\315\202\266]\202\337\202\351 \203\262\201c\203\212\203g\203\211\203C\n\203\264\201c\203\212\203Z\203b\203g\202\265\202\304\226{[\202\331\202\361]\221\314[\202\275\202\242]\203\201\203\202\203\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\326";
static char lbl_1_data_374A8[48] = "Choose the Slot with the Memory Card inserted. ";
static char lbl_1_data_374D8[16] = "CHOICE_SLOT GER";
static char lbl_1_data_374E8[16] = "CHOICE_SLOT FRA";
static char lbl_1_data_374F8[16] = "CHOICE_SLOT SPA";
static char lbl_1_data_37508[16] = "CHOICE_SLOT ITA";
static char lbl_1_data_37518[56] = "\203\201\203\202\203\212\201[\203J\201[\203h\202\360\202\263\202\265\202\275\203X\203\215\203b\203g\202\360\n\221I[\202\246\202\347]\202\361\202\305\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_37550[84] = "Use  \203\255 or \203\265to select.\nPress the \203\237 Button to confirm and the \203\240 Button cancel. ";
static char lbl_1_data_375A4[20] = "CAPTION_CHOICE GER";
static char lbl_1_data_375B8[20] = "CAPTION_CHOICE FRA";
static char lbl_1_data_375CC[20] = "CAPTION_CHOICE SPA";
static char lbl_1_data_375E0[20] = "CAPTION_CHOICE ITA";
static char lbl_1_data_375F4[72] = "\203\255\202\251\203\265\202\305\221I[\202\246\202\347]\202\361\202\305\201A\203\237\202\305\214\210[\202\253]\202\337\202\304\202\255\202\276\202\263\202\242\201B\n\203\240\202\305\203L\203\203\203\223\203Z\203\213\202\265\202\334\202\267\201B";
static char lbl_1_data_3763C[68] = "The FILE Data save to the Memory Card\nin SLOT has been cancelled.";
static char lbl_1_data_37680[16] = "NOSAVE_EXIT GER";
static char lbl_1_data_37690[16] = "NOSAVE_EXIT FRA";
static char lbl_1_data_376A0[16] = "NOSAVE_EXIT SPA";
static char lbl_1_data_376B0[16] = "NOSAVE_EXIT ITA";
static char lbl_1_data_376C0[68] = "FILE\203f\201[\203^\202\314\n\203\201\203\202\203\212\201[\203J\201[\203h\202\326\202\314\203Z\201[\203u\202\360\222\206[\202\277\202\343\202\244]\216~[\202\265]\202\265\202\334\202\265\202\275\201B";
static char lbl_1_data_37704[56] = "The Memory Card in SLOT\nis damaged and cannot be used.";
static char lbl_1_data_3773C[20] = "WRONG_SECTOR GER";
static char lbl_1_data_37750[20] = "WRONG_SECTOR FRA";
static char lbl_1_data_37764[20] = "WRONG_SECTOR SPA";
static char lbl_1_data_37778[20] = "WRONG_SECTOR ITA";
static char lbl_1_data_3778C[68] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\n\202\261\202\355\202\352\202\304\202\242\202\351\202\314\202\305\216g[\202\265]\227p[\202\346\202\244]\202\305\202\253\202\334\202\271\202\361\201B";
static char lbl_1_data_377D0[56] = "The Memory Card in SLOT\nis damaged and cannot be used.";
static char lbl_1_data_37808[16] = "WRONG_CARD GER";
static char lbl_1_data_37818[16] = "WRONG_CARD FRA";
static char lbl_1_data_37828[16] = "WRONG_CARD SPA";
static char lbl_1_data_37838[16] = "WRONG_CARD ITA";
static char lbl_1_data_37848[68] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\n\202\261\202\355\202\352\202\304\202\242\202\351\202\314\202\305\216g[\202\265]\227p[\202\346\202\244]\202\305\202\253\202\334\202\271\202\361\201B";
static char lbl_1_data_3788C[96] = "The Memory Card in SLOT\nis corrupted and must be formatted.\nOK to format the Memory Card now?";
static char lbl_1_data_378EC[16] = "ENCODING GER";
static char lbl_1_data_378FC[16] = "ENCODING FRA";
static char lbl_1_data_3790C[16] = "ENCODING SPA";
static char lbl_1_data_3791C[16] = "ENCODING ITA";
static char lbl_1_data_3792C[88] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\216g[\202\302\202\251]\202\246\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\223\374[\202\242]\202\352\222\274[\202\310\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_37984[60] = "The Memory Card in SLOT\nis corrupted and must be formatted.";
static char lbl_1_data_379C0[16] = "ENCODING GER";
static char lbl_1_data_379D0[16] = "ENCODING FRA";
static char lbl_1_data_379E0[16] = "ENCODING SPA";
static char lbl_1_data_379F0[16] = "ENCODING ITA";
static char lbl_1_data_37A00[88] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\216g[\202\302\202\251]\202\246\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\223\374[\202\242]\202\352\222\274[\202\310\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_37A58[96] = "The Memory Card in SLOT\nis corrupted and must be formatted.\nOK to format the Memory Card now?";
static char lbl_1_data_37AB8[20] = "FORMAT_QUERY GER";
static char lbl_1_data_37ACC[20] = "FORMAT_QUERY FRA";
static char lbl_1_data_37AE0[20] = "FORMAT_QUERY SPA";
static char lbl_1_data_37AF4[20] = "FORMAT_QUERY ITA";
static char lbl_1_data_37B08[108] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\203f\201[\203^\202\252\n\202\261\202\355\202\352\202\304\202\242\202\351\202\314\202\305\203t\203H\201[\203}\203b\203g\202\252\225K\227v\202\305\202\267\201B\n\203t\203H\201[\203}\203b\203g\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H";
static char lbl_1_data_37B74[40] = "OK to format the\nMemory Card in SLOT?";
static char lbl_1_data_37B9C[20] = "FORMAT_QUERY2 GER";
static char lbl_1_data_37BB0[20] = "FORMAT_QUERY2 FRA";
static char lbl_1_data_37BC4[20] = "FORMAT_QUERY2 SPA";
static char lbl_1_data_37BD8[20] = "FORMAT_QUERY2 ITA";
static char lbl_1_data_37BEC[60] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\360\n\203t\203H\201[\203}\203b\203g\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H";
static char lbl_1_data_37C28[8] = "Slot A";
static char lbl_1_data_37C30[12] = "SLOT_A GER";
static char lbl_1_data_37C3C[12] = "SLOT_A FRA";
static char lbl_1_data_37C48[12] = "SLOT_A SPA";
static char lbl_1_data_37C54[12] = "SLOT_A ITA";
static char lbl_1_data_37C60[12] = "\203X\203\215\203b\203g\202`";
static char lbl_1_data_37C6C[8] = "Slot B";
static char lbl_1_data_37C74[12] = "SLOT_B GER";
static char lbl_1_data_37C80[12] = "SLOT_B FRA";
static char lbl_1_data_37C8C[12] = "SLOT_B SPA";
static char lbl_1_data_37C98[12] = "SLOT_B ITA";
static char lbl_1_data_37CA4[12] = "\203X\203\215\203b\203g\202a";
static char lbl_1_data_37CB0[4] = "YES";
static char lbl_1_data_37CB4[8] = "HAI GER";
static char lbl_1_data_37CBC[8] = "HAI FRA";
static char lbl_1_data_37CC4[8] = "HAI SPA";
static char lbl_1_data_37CCC[8] = "HAI ITA";
static char lbl_1_data_37CD4[8] = "\202\315\202\242";
static char lbl_1_data_37CDC[4] = "NO";
static char lbl_1_data_37CE0[8] = "IIE GER";
static char lbl_1_data_37CE8[8] = "IIE FRA";
static char lbl_1_data_37CF0[8] = "IIE SPA";
static char lbl_1_data_37CF8[8] = "IIE ITA";
static char lbl_1_data_37D00[8] = "\202\242\202\242\202\246";
static char lbl_1_data_37D08[60] = "Formatting of the Memory Card in SLOT\nhas been cancelled.";
static char lbl_1_data_37D44[20] = "FORMAT_CANCEL GER";
static char lbl_1_data_37D58[20] = "FORMAT_CANCEL FRA";
static char lbl_1_data_37D6C[20] = "FORMAT_CANCEL SPA";
static char lbl_1_data_37D80[20] = "FORMAT_CANCEL ITA";
static char lbl_1_data_37D94[64] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203t\203H\201[\203}\203b\203g\202\360\222\206[\202\277\202\343]\216~[\202\244\202\265]\202\265\202\334\202\265\202\275\201B";
static char lbl_1_data_37DD4[400] = "The Memory Card in SLOT does not have\nenough free space. F-ZERO GX requires the\nfollowing to save its different types of data:\n(To manage files on the Memory Card,\nplease go to the Nintendo GameCube\nMemory Card management screen.)\nGame Data: 1 File and 4 Blocks\nGarage Data: 1 File and 18 Blocks\nGhost Data: 1 File and 3 Blocks\nEmblem Data: 1 File and 3 Blocks\nReplay Data: 1 File and 3\201`13 Blocks";
static char lbl_1_data_37F64[12] = "NOENT GER";
static char lbl_1_data_37F70[12] = "NOENT FRA";
static char lbl_1_data_37F7C[12] = "NOENT SPA";
static char lbl_1_data_37F88[12] = "NOENT ITA";
static char lbl_1_data_37F94[592] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nF-ZERO GX\202\314\212e[\202\251\202\255]\203t\203@\203C\203\213\202\360\203Z\201[\203u\202\267\202\351\202\311\202\315\n\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\210\310[\202\242]\211\272[\202\251]\202\314\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\n  \203Q\201[\203\200\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202S\203u\203\215\203b\203N\n \203K\203\214\201[\203W\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202P\202W\203u\203\215\203b\203N\n \203S\201[\203X\203g\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\203u\203\215\203b\203N\n\203G\203\223\203u\203\214\203\200\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\203u\203\215\203b\203N\n  \203\212\203v\203\214\203C\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\201`\202P\202R\203u\203\215\203b\203N\n";
static char lbl_1_data_381E4[228] = "There is not enough free space on the\nMemory Card in SLOT. To save FILE Data,\nyou need at least 1 file and REQUIRED blocks.\n(To manage files on the Memory Card,\nplease go to the Nintendo GameCube\nMemory Card management screen.)";
static char lbl_1_data_382C8[12] = "NOENT GER";
static char lbl_1_data_382D4[12] = "NOENT FRA";
static char lbl_1_data_382E0[12] = "NOENT SPA";
static char lbl_1_data_382EC[12] = "NOENT ITA";
static char lbl_1_data_382F8[348] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nFILE\203f\201[\203^\202\360\203Z\201[\203u\202\267\202\351\202\311\202\315\n\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\203t\203@\203C\203\2131\202\302\202\306REQUIRED\203u\203\215\203b\203N\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\n";
static char lbl_1_data_38454[400] = "The Memory Card in SLOT does not have\nenough free space. F-ZERO GX requires the\nfollowing to save its different types of data:\n(To manage files on the Memory Card,\nplease go to the Nintendo GameCube\nMemory Card management screen.)\nGame Data: 1 File and 4 Blocks\nGarage Data: 1 File and 18 Blocks\nGhost Data: 1 File and 3 Blocks\nEmblem Data: 1 File and 3 Blocks\nReplay Data: 1 File and 3\201`13 Blocks";
static char lbl_1_data_385E4[16] = "INSSPACE GER";
static char lbl_1_data_385F4[16] = "INSSPACE FRA";
static char lbl_1_data_38604[16] = "INSSPACE SPA";
static char lbl_1_data_38614[16] = "INSSPACE ITA";
static char lbl_1_data_38624[592] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nF-ZERO GX\202\314\212e[\202\251\202\255]\203t\203@\203C\203\213\202\360\203Z\201[\203u\202\267\202\351\202\311\202\315\n\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\210\310[\202\242]\211\272[\202\251]\202\314\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\n  \203Q\201[\203\200\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202S\203u\203\215\203b\203N\n \203K\203\214\201[\203W\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202P\202W\203u\203\215\203b\203N\n \203S\201[\203X\203g\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\203u\203\215\203b\203N\n\203G\203\223\203u\203\214\203\200\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\203u\203\215\203b\203N\n  \203\212\203v\203\214\203C\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\201`\202P\202R\203u\203\215\203b\203N\n";
static char lbl_1_data_38874[228] = "The Memory Card in SLOT does not\nhave enough free space. At least 1 file\nand REQUIRED blocks are needed to save\nFILE Data. (To manage files on the Memory\nCard, please go to the Nintendo GameCube\nMemory Card management screen.)";
static char lbl_1_data_38958[20] = "INSSPACE_REPLAY GER";
static char lbl_1_data_3896C[20] = "INSSPACE_REPLAY FRA";
static char lbl_1_data_38980[20] = "INSSPACE_REPLAY SPA";
static char lbl_1_data_38994[20] = "INSSPACE_REPLAY ITA";
static char lbl_1_data_389A8[348] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nFILE\203f\201[\203^\202\360\203Z\201[\203u\202\267\202\351\202\311\202\315\n\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\203t\203@\203C\203\2131\202\302\202\306REQUIRED\203u\203\215\203b\203N\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\n";
static char lbl_1_data_38B04[84] = "There is already FILE Data\non the Memory Card in SLOT.\nOK to save over this data?";
static char lbl_1_data_38B58[20] = "OVERWRITE_QUERY GER";
static char lbl_1_data_38B6C[20] = "OVERWRITE_QUERY FRA";
static char lbl_1_data_38B80[20] = "OVERWRITE_QUERY SPA";
static char lbl_1_data_38B94[20] = "OVERWRITE_QUERY ITA";
static char lbl_1_data_38BA8[96] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\n\202\267\202\305\202\311FILE\203f\201[\203^\202\252\202\240\202\350\202\334\202\267\201B\n\217\343[\202\244\202\355]\217\221[\202\252]\202\253\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H";
static char lbl_1_data_38C08[40] = "The FILE Data overwrite\nwas canceled.";
static char lbl_1_data_38C30[24] = "OVERWRITE_CANCEL GER";
static char lbl_1_data_38C48[24] = "OVERWRITE_CANCEL FRA";
static char lbl_1_data_38C60[24] = "OVERWRITE_CANCEL SPA";
static char lbl_1_data_38C78[24] = "OVERWRITE_CANCEL ITA";
static char lbl_1_data_38C90[60] = "FILE\203f\201[\203^\202\314\n\217\343[\202\244\202\355]\217\221[\202\252]\202\253\202\360\222\206[\202\277\202\343]\216~[\202\244\202\265]\202\265\202\334\202\265\202\275\201B";
static char lbl_1_data_38CCC[52] = "FILE Data was saved to\nthe Memory Card in SLOT. ";
static char lbl_1_data_38D00[16] = "SAVE_END GER";
static char lbl_1_data_38D10[16] = "SAVE_END FRA";
static char lbl_1_data_38D20[16] = "SAVE_END SPA";
static char lbl_1_data_38D30[16] = "SAVE_END ITA";
static char lbl_1_data_38D40[64] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\326\nFILE\203f\201[\203^\202\314\203Z\201[\203u\202\252\217I[\202\250]\202\355\202\350\202\334\202\265\202\275\201B";
static char lbl_1_data_38D80[24] = "Free blocks in SLOT:";
static char lbl_1_data_38D98[20] = "REMAIN_BLOCKS GER";
static char lbl_1_data_38DAC[20] = "REMAIN_BLOCKS FRA";
static char lbl_1_data_38DC0[20] = "REMAIN_BLOCKS SPA";
static char lbl_1_data_38DD4[20] = "REMAIN_BLOCKS ITA";
static char lbl_1_data_38DE8[28] = "SLOT\202\314\213\363[\202\240]\202\253\203u\203\215\203b\203N\201F";
static char lbl_1_data_38E04[8] = "Blocks:";
static char lbl_1_data_38E0C[12] = "BLOCKS GER";
static char lbl_1_data_38E18[12] = "BLOCKS FRA";
static char lbl_1_data_38E24[12] = "BLOCKS SPA";
static char lbl_1_data_38E30[12] = "BLOCKS ITA";
static char lbl_1_data_38E3C[12] = "\203u\203\215\203b\203N\201F";
static char lbl_1_data_38E48[56] = "Loading FILE Data from\nthe Memory Card was cancelled. ";
static char lbl_1_data_38E80[16] = "NOLOAD_EXIT GER";
static char lbl_1_data_38E90[16] = "NOLOAD_EXIT FRA";
static char lbl_1_data_38EA0[16] = "NOLOAD_EXIT SPA";
static char lbl_1_data_38EB0[16] = "NOLOAD_EXIT ITA";
static char lbl_1_data_38EC0[68] = "FILE\203f\201[\203^\202\314\n\203\201\203\202\203\212\201[\203J\201[\203h\202\251\202\347\202\314\203\215\201[\203h\202\360\222\206[\202\277\202\343\202\244]\216~[\202\265]\202\265\202\334\202\265\202\275\201B";
static char lbl_1_data_38F04[44] = "The Memory Card in SLOT has been formatted.";
static char lbl_1_data_38F30[16] = "FORMAT_END GER";
static char lbl_1_data_38F40[16] = "FORMAT_END FRA";
static char lbl_1_data_38F50[16] = "FORMAT_END SPA";
static char lbl_1_data_38F60[16] = "FORMAT_END ITA";
static char lbl_1_data_38F70[56] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203t\203H\201[\203}\203b\203g\202\252\217I[\202\250]\202\355\202\350\202\334\202\265\202\275\201B";
static char lbl_1_data_38FA8[64] = "The FILE Data has been loaded\nfrom the Memory Card in SLOT. ";
static char lbl_1_data_38FE8[16] = "LOAD_END GER";
static char lbl_1_data_38FF8[16] = "LOAD_END FRA";
static char lbl_1_data_39008[16] = "LOAD_END SPA";
static char lbl_1_data_39018[16] = "LOAD_END ITA";
static char lbl_1_data_39028[68] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\251\202\347\202\314\nFILE\203f\201[\203^\202\314\203\215\201[\203h\202\252\217I[\202\250]\202\355\202\350\202\334\202\265\202\275\201B";
static char lbl_1_data_3906C[88] = "The F-ZERO GX FILE Data on\nthe Memory Card in SLOT\nis corrupted and must be deleted.";
static char lbl_1_data_390C4[16] = "DATA_BROKEN GER";
static char lbl_1_data_390D4[16] = "DATA_BROKEN FRA";
static char lbl_1_data_390E4[16] = "DATA_BROKEN SPA";
static char lbl_1_data_390F4[16] = "DATA_BROKEN ITA";
static char lbl_1_data_39104[68] = "FILE\203f\201[\203^\202\252\202\261\202\355\202\352\202\304\202\242\202\334\202\267\201B\n\203t\203@\203C\203\213\202\360\217\301[\202\265\202\345\202\244]\213\216[ \202\253\202\345]\202\265\202\334\202\267\201B";
static char lbl_1_data_39148[72] = "The Memory Card in SLOT was removed.\nMemory Card access was stopped. ";
static char lbl_1_data_39190[12] = "DETACH GER";
static char lbl_1_data_3919C[12] = "DETACH FRA";
static char lbl_1_data_391A8[12] = "DETACH SPA";
static char lbl_1_data_391B4[12] = "DETACH ITA";
static char lbl_1_data_391C0[84] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\252\224\262[\202\312]\202\251\202\352\202\334\202\265\202\275\201B\n\215\354[\202\263\202\254]\213\306[\202\345\202\244]\202\360\222\206[\202\277\202\343]\216~[\202\244\202\265]\202\265\202\334\202\267\201B";
static char lbl_1_data_39214[52] = "There is no FILE Data on\nthe Memory Card in SLOT. ";
static char lbl_1_data_39248[12] = "NOFILE GER";
static char lbl_1_data_39254[12] = "NOFILE FRA";
static char lbl_1_data_39260[12] = "NOFILE SPA";
static char lbl_1_data_3926C[12] = "NOFILE ITA";
static char lbl_1_data_39278[52] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^\202\252\202\240\202\350\202\334\202\271\202\361\201B";
static char lbl_1_data_392AC[56] = "There is no Replay Data on\nthe Memory Card in SLOT. ";
static char lbl_1_data_392E4[12] = "NOFILE GER";
static char lbl_1_data_392F0[12] = "NOFILE FRA";
static char lbl_1_data_392FC[12] = "NOFILE SPA";
static char lbl_1_data_39308[12] = "NOFILE ITA";
static char lbl_1_data_39314[52] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^\202\252\202\240\202\350\202\334\202\271\202\361\201B";
static char lbl_1_data_39348[52] = "There is no Ghost Data on\nthe Memory Card in SLOT. ";
static char lbl_1_data_3937C[12] = "NOFILE GER";
static char lbl_1_data_39388[12] = "NOFILE FRA";
static char lbl_1_data_39394[12] = "NOFILE SPA";
static char lbl_1_data_393A0[12] = "NOFILE ITA";
static char lbl_1_data_393AC[52] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^\202\252\202\240\202\350\202\334\202\271\202\361\201B";
static char lbl_1_data_393E0[56] = "There is no Emblem Data on\nthe Memory Card in SLOT. ";
static char lbl_1_data_39418[12] = "NOFILE GER";
static char lbl_1_data_39424[12] = "NOFILE FRA";
static char lbl_1_data_39430[12] = "NOFILE SPA";
static char lbl_1_data_3943C[12] = "NOFILE ITA";
static char lbl_1_data_39448[52] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^\202\252\202\240\202\350\202\334\202\271\202\361\201B";
static char lbl_1_data_3947C[60] = "Unable to get the data list\non the Memory Card in SLOT. ";
static char lbl_1_data_394B8[16] = "NOLIST_EXIT GER";
static char lbl_1_data_394C8[16] = "NOLIST_EXIT FRA";
static char lbl_1_data_394D8[16] = "NOLIST_EXIT SPA";
static char lbl_1_data_394E8[16] = "NOLIST_EXIT ITA";
static char lbl_1_data_394F8[40] = "SLOT\202\314\203f\201[\203^\203\212\203X\203g\202\252\n\202\306\202\352\202\334\202\271\202\361\202\305\202\265\202\275\201B";
static char lbl_1_data_39520[48] = "There is no data on\nthe Memory Card in SLOT. ";
static char lbl_1_data_39550[20] = "LIST_NO_EXIST GER";
static char lbl_1_data_39564[20] = "LIST_NO_EXIST FRA";
static char lbl_1_data_39578[20] = "LIST_NO_EXIST SPA";
static char lbl_1_data_3958C[20] = "LIST_NO_EXIST ITA";
static char lbl_1_data_395A0[60] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\n\203f\201[\203^\202\2521\202\302\202\340\202\240\202\350\202\334\202\271\202\361\202\305\202\265\202\275\201B";
static char lbl_1_data_395DC[60] = "The data list on the Memory Card\nin SLOT has been loaded.";
static char lbl_1_data_39618[16] = "LIST_END GER";
static char lbl_1_data_39628[16] = "LIST_END FRA";
static char lbl_1_data_39638[16] = "LIST_END SPA";
static char lbl_1_data_39648[16] = "LIST_END ITA";
static char lbl_1_data_39658[60] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203f\201[\203^\203\212\203X\203g\202\360\223\307[\202\346]\202\335\202\261\202\335\202\334\202\265\202\275\201B";
static char lbl_1_data_39694[40] = "Done checking the Memory Card in SLOT.";
static char lbl_1_data_396BC[16] = "CHECK_END GER";
static char lbl_1_data_396CC[16] = "CHECK_END FRA";
static char lbl_1_data_396DC[16] = "CHECK_END SPA";
static char lbl_1_data_396EC[16] = "CHECK_END ITA";
static char lbl_1_data_396FC[68] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203`\203F\203b\203N\202\252[\202\265]\217I[\202\343\202\244]\227\271[\202\350\202\345]\202\265[\202\244]\202\334\202\265\202\275\201B";
static char lbl_1_data_39740[64] = "FILE Data deletion on the Memory Card\nin SLOT was cancelled.";
static char lbl_1_data_39780[16] = "NODEL_EXIT GER";
static char lbl_1_data_39790[16] = "NODEL_EXIT FRA";
static char lbl_1_data_397A0[16] = "NODEL_EXIT SPA";
static char lbl_1_data_397B0[16] = "NODEL_EXIT ITA";
static char lbl_1_data_397C0[64] = "SLOT\202\314FILE\203f\201[\203^\202\314\215\355[\202\263\202\255]\217\234[\202\266\202\345]\202\360\222\206[\202\277\202\343\202\244]\216~[\202\265]\202\265\202\334\202\265\202\275\201B";
static char lbl_1_data_39800[56] = "1 FILE Data was erased from the Memory Card in SLOT.";
static char lbl_1_data_39838[16] = "DELETE_END GER";
static char lbl_1_data_39848[16] = "DELETE_END FRA";
static char lbl_1_data_39858[16] = "DELETE_END SPA";
static char lbl_1_data_39868[16] = "DELETE_END ITA";
static char lbl_1_data_39878[40] = "SLOT\202\314FILE\203f\201[\203^\202\360\202P\202\302\217\301[\202\257]\202\265\202\334\202\265\202\275\201B";
static char lbl_1_data_398A0[16] = "NOW FORMATTING";
static char lbl_1_data_398B0[16] = "FORMAT_NOW GER";
static char lbl_1_data_398C0[16] = "FORMAT_NOW FRA";
static char lbl_1_data_398D0[16] = "FORMAT_NOW SPA";
static char lbl_1_data_398E0[16] = "FORMAT_NOW ITA";
static char lbl_1_data_398F0[16] = "NOW FORMATTING";
static char lbl_1_data_39900[12] = "NOW SAVING";
static char lbl_1_data_3990C[16] = "SAVE_NOW GER";
static char lbl_1_data_3991C[16] = "SAVE_NOW FRA";
static char lbl_1_data_3992C[16] = "SAVE_NOW SPA";
static char lbl_1_data_3993C[16] = "SAVE_NOW ITA";
static char lbl_1_data_3994C[12] = "NOW SAVING";
static char lbl_1_data_39958[16] = "NOW MAKING LIST";
static char lbl_1_data_39968[16] = "LIST_NOW GER";
static char lbl_1_data_39978[16] = "LIST_NOW FRA";
static char lbl_1_data_39988[16] = "LIST_NOW SPA";
static char lbl_1_data_39998[16] = "LIST_NOW ITA";
static char lbl_1_data_399A8[16] = "NOW MAKING LIST";
static char lbl_1_data_399B8[16] = "NOW CHECKING";
static char lbl_1_data_399C8[16] = "LIST_NOW GER";
static char lbl_1_data_399D8[16] = "LIST_NOW FRA";
static char lbl_1_data_399E8[16] = "LIST_NOW SPA";
static char lbl_1_data_399F8[16] = "LIST_NOW ITA";
static char lbl_1_data_39A08[16] = "NOW CHECKING";
static char lbl_1_data_39A18[84] = "Accessing the Memory Card in SLOT.\nDo not touch the Memory Card or POWER Button.";
static char lbl_1_data_39A6C[12] = "ACCESS GER";
static char lbl_1_data_39A78[12] = "ACCESS FRA";
static char lbl_1_data_39A84[12] = "ACCESS SPA";
static char lbl_1_data_39A90[12] = "ACCESS ITA";
static char lbl_1_data_39A9C[104] = "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203A\203N\203Z\203X\222\206[\202\277\202\343\202\244]\202\305\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\342\223d[\202\305\202\361]\214\271[\202\260\202\361]\202\311\220G[\202\263\202\355]\202\347\202\310\202\242\202\305\202\255\202\276\202\263\202\242\201B\n";
static char lbl_1_data_39B04[84] = "Accessing the Memory Card in SLOT.\nDo not touch the Memory Card or POWER Button.";
static char lbl_1_data_39B58[12] = "ACCESS GER";
static char lbl_1_data_39B64[12] = "ACCESS FRA";
static char lbl_1_data_39B70[12] = "ACCESS SPA";
static char lbl_1_data_39B7C[12] = "ACCESS ITA";
static char lbl_1_data_39B88[104] = "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203A\203N\203Z\203X\222\206[\202\277\202\343\202\244]\202\305\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\342\223d[\202\305\202\361]\214\271[\202\260\202\361]\202\311\220G[\202\263\202\355]\202\347\202\310\202\242\202\305\202\255\202\276\202\263\202\242\201B\n";
static char lbl_1_data_39BF0[44] = "OK to save FILE to the Memory Card in SLOT?";
static char lbl_1_data_39C1C[16] = "SAVE_QUERY GER";
static char lbl_1_data_39C2C[16] = "SAVE_QUERY FRA";
static char lbl_1_data_39C3C[16] = "SAVE_QUERY SPA";
static char lbl_1_data_39C4C[16] = "SAVE_QUERY ITA";
static char lbl_1_data_39C5C[44] = "SLOT\202\311FILE\202\360\203Z\201[\203u\202\265\202\304\202\340\n\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H";
static char lbl_1_data_39C88[48] = "If you start now,\nyou will not be able to save.";
static char lbl_1_data_39CB8[16] = "CANNOT_SAVE GER";
static char lbl_1_data_39CC8[16] = "CANNOT_SAVE FRA";
static char lbl_1_data_39CD8[16] = "CANNOT_SAVE SPA";
static char lbl_1_data_39CE8[16] = "CANNOT_SAVE ITA";
static char lbl_1_data_39CF8[52] = "\202\261\202\314\202\334\202\334\216n[\202\315\202\266]\202\337\202\275\217\352[\202\316]\215\207[\202\240\202\242]\n\203Z\201[\203u\202\305\202\253\202\334\202\271\202\361";
static char lbl_1_data_39D2C[152] = "There are no Memory Cards inserted properly.\nPlease check connections or insert a Memory Card.\nIf you start now, you will not be able to save the game.";
static char lbl_1_data_39DC4[24] = "CANNOT_SAVE_NOCARD GER";
static char lbl_1_data_39DDC[24] = "CANNOT_SAVE_NOCARD FRA";
static char lbl_1_data_39DF4[24] = "CANNOT_SAVE_NOCARD SPA";
static char lbl_1_data_39E0C[24] = "CANNOT_SAVE_NOCARD ITA";
static char lbl_1_data_39E24[140] = "\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251[\202\335]\202\302\202\251\202\350\202\334\202\271\202\361\201B\n\220\332[\202\271\202\302]\221\261[\202\274\202\255]\202\360\212m[\202\251\202\255]\224F[\202\311\202\361]\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\202\261\202\314\202\334\202\334\216n[\202\315\202\266]\202\337\202\275\217\352[\202\316]\215\207[\202\240\202\242]\n\203Z\201[\203u\202\305\202\253\202\334\202\271\202\361";
static char lbl_1_data_39EB0[68] = "The device in SLOT is not supported.\nPlease insert a Memory Card.";
static char lbl_1_data_39EF4[24] = "CANNOT_SAVE_NOCARD GER";
static char lbl_1_data_39F0C[24] = "CANNOT_SAVE_NOCARD FRA";
static char lbl_1_data_39F24[24] = "CANNOT_SAVE_NOCARD SPA";
static char lbl_1_data_39F3C[24] = "CANNOT_SAVE_NOCARD ITA";
static char lbl_1_data_39F54[80] = "\203\201\203\202\203\212\201[\203J\201[\203h\210\310\212O\202\314\202\340\202\314\202\252\214\251[\202\335]\202\302\202\251\202\350\202\334\202\265\202\275\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\202\263\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_39FA4[116] = "Either Game Data was not loaded\nor the original Memory Card,\nfrom which the Game data was loaded,\nhas been removed.";
static char lbl_1_data_3A018[4] = "GER";
static char lbl_1_data_3A01C[4] = "FRA";
static char lbl_1_data_3A020[4] = "SPA";
static char lbl_1_data_3A024[4] = "ITA";
static char lbl_1_data_3A028[188] = "\203Q\201[\203\200\203f\201[\203^\202\252\203\215\201[\203h\202\263\202\352\202\304\202\242\202\310\202\242\202\251\n\203Q\201[\203\200\203f\201[\203^\202\360\203\215\201[\203h\202\265\202\275\203\201\203\202\203\212\201[\203J\201[\203h\n\202\305\202\315\202\240\202\350\202\334\202\271\202\361\201B(\203Q\201[\203\200\203f\201[\203^\202\314\203Z\201[\203u\201A\n\203\215\201[\203h\202\315\201A\203I\203v\203V\203\207\203\223\202\314\203\201\203\202\203\212\201[\203J\201[\203h\n\203\201\203j\203\205\201[\202\251\202\347\211\302[\202\251]\224\\[\202\314\202\244]\202\305\202\267\201B)";
static char lbl_1_data_3A0E4[120] = "Either Game Data was not loaded\nor the original Memory Card,\nfrom which the Game data was loaded,\n has been removed.";
static char lbl_1_data_3A15C[4] = "GER";
static char lbl_1_data_3A160[4] = "FRA";
static char lbl_1_data_3A164[4] = "SPA";
static char lbl_1_data_3A168[4] = "ITA";
static char lbl_1_data_3A16C[92] = "\203Q\201[\203\200\203f\201[\203^\202\252\203\215\201[\203h\202\263\202\352\202\304\202\242\202\310\202\242\202\251\n\203Q\201[\203\200\203f\201[\203^\202\360\203\215\201[\203h\202\265\202\275\203\201\203\202\203\212\201[\203J\201[\203h\n\202\305\202\315\202\240\202\350\202\334\202\271\202\361\201B";
static char lbl_1_data_3A1C8[8] = "Data";
static char lbl_1_data_3A1D0[12] = "File GER";
static char lbl_1_data_3A1DC[12] = "File FRA";
static char lbl_1_data_3A1E8[12] = "File SPA";
static char lbl_1_data_3A1F4[12] = "File ITA";
static char lbl_1_data_3A200[8] = "\203f\201[\203^";
static char lbl_1_data_3A208[8] = "Game";
static char lbl_1_data_3A210[12] = "System GER";
static char lbl_1_data_3A21C[12] = "System FRA";
static char lbl_1_data_3A228[12] = "System SPA";
static char lbl_1_data_3A234[12] = "System ITA";
static char lbl_1_data_3A240[8] = "\203Q\201[\203\200";
static char lbl_1_data_3A248[8] = "Debug";
static char lbl_1_data_3A250[12] = "Debug GER";
static char lbl_1_data_3A25C[12] = "Debug FRA";
static char lbl_1_data_3A268[12] = "Debug SPA";
static char lbl_1_data_3A274[12] = "Debug ITA";
static char lbl_1_data_3A280[12] = "\203f\203o\203b\203O";
static char lbl_1_data_3A28C[8] = "Replay";
static char lbl_1_data_3A294[12] = "Replay GER";
static char lbl_1_data_3A2A0[12] = "Replay FRA";
static char lbl_1_data_3A2AC[12] = "Replay SPA";
static char lbl_1_data_3A2B8[12] = "Replay ITA";
static char lbl_1_data_3A2C4[12] = "\203\212\203v\203\214\203C";
static char lbl_1_data_3A2D0[8] = "Emblem";
static char lbl_1_data_3A2D8[12] = "Emblem GER";
static char lbl_1_data_3A2E4[12] = "Emblem FRA";
static char lbl_1_data_3A2F0[12] = "Emblem SPA";
static char lbl_1_data_3A2FC[12] = "Emblem ITA";
static char lbl_1_data_3A308[12] = "\203G\203\223\203u\203\214\203\200";
static char lbl_1_data_3A314[8] = "Ghost";
static char lbl_1_data_3A31C[12] = "Ghost GER";
static char lbl_1_data_3A328[12] = "Ghost FRA";
static char lbl_1_data_3A334[12] = "Ghost SPA";
static char lbl_1_data_3A340[12] = "Ghost ITA";
static char lbl_1_data_3A34C[12] = "\203S\201[\203X\203g";
static char lbl_1_data_3A358[8] = "Garage";
static char lbl_1_data_3A360[12] = "Custom GER";
static char lbl_1_data_3A36C[12] = "Custom FRA";
static char lbl_1_data_3A378[12] = "Custom SPA";
static char lbl_1_data_3A384[12] = "Custom ITA";
static char lbl_1_data_3A390[12] = "\203K\203\214\201[\203W";
static char lbl_1_data_3A39C[8] = "Game";
static char lbl_1_data_3A3A4[12] = "Game GER";
static char lbl_1_data_3A3B0[12] = "Game FRA";
static char lbl_1_data_3A3BC[12] = "Game SPA";
static char lbl_1_data_3A3C8[12] = "Game ITA";
static char lbl_1_data_3A3D4[8] = "\203Q\201[\203\200";
static char lbl_1_data_3A3DC[324] = "There is not enough free space on the Memory Card\nin %s to save all types of new files.\nExisting F-ZERO GX files may be erased or overwritten.\n(To manage files on the Memory Card, please go to\nthe Memory Card management screen.) In order to save\na new file, the following number of free files\nand blocks must be available:";
static char lbl_1_data_3A520[4] = "GER";
static char lbl_1_data_3A524[4] = "FRA";
static char lbl_1_data_3A528[4] = "SPA";
static char lbl_1_data_3A52C[4] = "ITA";
static char lbl_1_data_3A530[368] = "\202\242\202\255\202\302\202\251\202\314\203f\201[\203^\202\315\203Z\201[\203u\202\305\202\253\202\334\202\271\202\361\201B\n%s\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e\227\312\202\252\202\310\202\242\202\251\201A\n\203t\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\n\203Z\201[\203u\202\267\202\351\202\311\202\315\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\210\310[\202\242]\211\272[\202\251]\202\314\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\n";
static char lbl_1_data_3A6A0[68] = "/bcffa0a0/1/bcffffff/ File and /bcffa0a0/        /bcffffff/ Blocks";
static char lbl_1_data_3A6E4[4] = "GER";
static char lbl_1_data_3A6E8[4] = "FRA";
static char lbl_1_data_3A6EC[4] = "SPA";
static char lbl_1_data_3A6F0[4] = "ITA";
static char lbl_1_data_3A6F4[68] = "\203t\203@\203C\203\213/bcffa0a0/1/bcffffff/\202\302 \202\306/bcffa0a0/%4d/bcffffff/\203u\203\215\203b\203N";
static char lbl_1_data_3A738[68] = "/bcffa0a0/1/bcffffff/ File and /bcffa0a0/\202R\201`%2d/bcffffff/ Blocks";
static char lbl_1_data_3A77C[4] = "GER";
static char lbl_1_data_3A780[4] = "FRA";
static char lbl_1_data_3A784[4] = "SPA";
static char lbl_1_data_3A788[4] = "ITA";
static char lbl_1_data_3A78C[72] = "\203t\203@\203C\203\213/bcffa0a0/1/bcffffff/\202\302 \202\306/bcffa0a0/\202R\201`%2d/bcffffff/\203u\203\215\203b\203N";
static char lbl_1_data_3A7D4[56] = "No Memory Card in SLOT.\nPlease insert a Memory Card.";
static char lbl_1_data_3A80C[4] = "GER";
static char lbl_1_data_3A810[4] = "FRA";
static char lbl_1_data_3A814[4] = "SPA";
static char lbl_1_data_3A818[4] = "ITA";
static char lbl_1_data_3A81C[88] = "\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251[\202\335]\202\302\202\251\202\350\202\334\202\271\202\361\201B\n\220\332[\202\271\202\302]\221\261[\202\274\202\255]\202\360\212m[\202\251\202\255]\224F[\202\311\202\361]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_3A874[8] = "SAVE";
static char lbl_1_data_3A87C[4] = "GER";
static char lbl_1_data_3A880[4] = "FRA";
static char lbl_1_data_3A884[4] = "SPA";
static char lbl_1_data_3A888[4] = "ITA";
static char lbl_1_data_3A88C[8] = "\203Z\201[\203u";
static char lbl_1_data_3A894[8] = "LOAD";
static char lbl_1_data_3A89C[4] = "GER";
static char lbl_1_data_3A8A0[4] = "FRA";
static char lbl_1_data_3A8A4[4] = "SPA";
static char lbl_1_data_3A8A8[4] = "ITA";
static char lbl_1_data_3A8AC[8] = "\203\215\201[\203h";
static char lbl_1_data_3A8B4[8] = "COPY";
static char lbl_1_data_3A8BC[4] = "GER";
static char lbl_1_data_3A8C0[4] = "FRA";
static char lbl_1_data_3A8C4[4] = "SPA";
static char lbl_1_data_3A8C8[4] = "ITA";
static char lbl_1_data_3A8CC[8] = "\203R\203s\201[";
static char lbl_1_data_3A8D4[8] = "ERASE";
static char lbl_1_data_3A8DC[4] = "GER";
static char lbl_1_data_3A8E0[4] = "FRA";
static char lbl_1_data_3A8E4[4] = "SPA";
static char lbl_1_data_3A8E8[4] = "ITA";
static char lbl_1_data_3A8EC[8] = "\202\257 \202\267";
static char lbl_1_data_3A8F4[52] = "This Memory Card cannot be used.\nPlease remove it. ";
static char lbl_1_data_3A928[4] = "GER";
static char lbl_1_data_3A92C[4] = "FRA";
static char lbl_1_data_3A930[4] = "SPA";
static char lbl_1_data_3A934[4] = "ITA";
static char lbl_1_data_3A938[84] = "\202\261\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\216g[\202\265]\227p[\202\346\202\244]\202\305\202\253\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\224\262[\202\312]\202\242\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_3A98C[84] = "Accessing the Memory Card in Slot A. Do not touch the Memory Card or POWER Button.";
static char lbl_1_data_3A9E0[4] = "GER";
static char lbl_1_data_3A9E4[4] = "FRA";
static char lbl_1_data_3A9E8[4] = "SPA";
static char lbl_1_data_3A9EC[4] = "ITA";
static char lbl_1_data_3A9F0[76] = "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203A\203N\203Z\203X\222\206\202\305\202\267\201B\203\201\203\202\203\212\201[\203J\201[\203h\202\342\223d\214\271\202\311\220G\202\347\202\310\202\242\202\305\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_3AA3C[8] = "Saving";
static char lbl_1_data_3AA44[4] = "GER";
static char lbl_1_data_3AA48[4] = "FRA";
static char lbl_1_data_3AA4C[4] = "SPA";
static char lbl_1_data_3AA50[4] = "ITA";
static char lbl_1_data_3AA54[12] = "\203Z\201[\203u\222\206";
static char lbl_1_data_3AA60[64] = "Some F-ZERO GX files on\nthe Memory Card in SLOT are corrupted.\n";
static char lbl_1_data_3AAA0[20] = "LIST_NO_EXIST GER";
static char lbl_1_data_3AAB4[20] = "LIST_NO_EXIST FRA";
static char lbl_1_data_3AAC8[20] = "LIST_NO_EXIST SPA";
static char lbl_1_data_3AADC[20] = "LIST_NO_EXIST ITA";
static char lbl_1_data_3AAF0[220] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\n\203f\201[\203^\202\2521\202\302\202\340\202\240\202\350\202\334\202\271\202\361\202\305\202\265\202\275\201B\n(\202\261\202\355\202\352\202\275\203f\201[\203^\202\252\221\266[\202\273\202\361]\215\335[\202\264\202\242]\202\265\202\304\202\242\202\334\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346\226\312\202\305\202\250\202\261\202\310\202\301\202\304\202\255\202\276\202\263\202\242)";
static char lbl_1_data_3ABCC[124] = "The data list on the Memory Card in SLOT\nhas been read. (Some F-ZERO GX files on\nthe Memory Card in SLOT are corrupted.)";
static char lbl_1_data_3AC48[16] = "LIST_END GER";
static char lbl_1_data_3AC58[16] = "LIST_END FRA";
static char lbl_1_data_3AC68[16] = "LIST_END SPA";
static char lbl_1_data_3AC78[16] = "LIST_END ITA";
static char lbl_1_data_3AC88[224] = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203f\201[\203^\203\212\203X\203g\202\360\223\307[\202\346]\202\335\202\261\202\335\202\334\202\265\202\275\201B\n(\202\261\202\355\202\352\202\275\203f\201[\203^\202\252\221\266[\202\273\202\361]\215\335[\202\264\202\242]\202\265\202\304\202\242\202\334\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346\226\312\202\305\202\250\202\261\202\310\202\301\202\304\202\255\202\276\202\263\202\242)";
static char lbl_1_data_3AD68[112] = "Some F-ZERO GX files on\nthe Memory Card in SLOT are corrupted.\nPlease go to Options to manage the Memory Card.";
static char lbl_1_data_3ADD8[20] = "LIST_NO_EXIST GER";
static char lbl_1_data_3ADEC[20] = "LIST_NO_EXIST FRA";
static char lbl_1_data_3AE00[20] = "LIST_NO_EXIST SPA";
static char lbl_1_data_3AE14[20] = "LIST_NO_EXIST ITA";
static u8 lbl_1_data_3AE28[4] = {0x00, 0x00, 0x00, 0x00};
static char lbl_1_data_3AE2C[168] = "The data list on the Memory Card in SLOT\nhas been read. (Some F-ZERO GX files on\nthe Memory Card in SLOT are corrupted.\nPlease go to Options manage the Memory Card.)";
static char lbl_1_data_3AED4[16] = "LIST_END GER";
static char lbl_1_data_3AEE4[16] = "LIST_END FRA";
static char lbl_1_data_3AEF4[16] = "LIST_END SPA";
static char lbl_1_data_3AF04[16] = "LIST_END ITA";
static u8 lbl_1_data_3AF14[4] = {0x00, 0x00, 0x00, 0x00};
static char lbl_1_data_3AF18[168] = "No Memory Card found in Slot A. Please re-insert the\noriginal Memory Card from which the Game data was loaded.\n\203\237 Button \201c Retry\n\203\240 Button \201c Continue without saving";
static char lbl_1_data_3AFC0[16] = "LIST_END GER";
static char lbl_1_data_3AFD0[16] = "LIST_END FRA";
static char lbl_1_data_3AFE0[16] = "LIST_END SPA";
static char lbl_1_data_3AFF0[16] = "LIST_END ITA";
static char lbl_1_data_3B000[184] = "\203X\203\215\203b\203g\202`\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\252\224\262[\202\312]\202\251\202\352\202\304\202\242\202\334\202\267\201B\n\203Q\201[\203\200\203f\201[\203^\202\360\203\215\201[\203h\202\265\202\275\203\201\203\202\203\212\201[\203J\201[\203h\202\360\n\203X\203\215\203b\203g\202`\202\311\202\263\202\265\202\304\203\237\203{\203^\203\223\202\360\211\237[\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\203L\203\203\203\223\203Z\203\213\202\267\202\351\202\311\202\315\203\240\202\360\211\237[\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
static char lbl_1_data_3B0B8[40] = "Are you sure you\nwant to delete this?";
static char lbl_1_data_3B0E0[16] = "LIST_END GER";
static char lbl_1_data_3B0F0[16] = "LIST_END FRA";
static char lbl_1_data_3B100[16] = "LIST_END SPA";
static char lbl_1_data_3B110[16] = "LIST_END ITA";
static char lbl_1_data_3B120[48] = "\226{[\202\331\202\361]\223\226[\202\306\202\244]\202\311\217\301[\202\257]\202\265\202\304\202\340\n\202\346\202\353\202\265\202\242\202\305\202\267\202\251?";
static char lbl_1_data_3B150[72] = "The device in SLOT is not a Memory Card.\nPlease insert a Memory Card.";
static char lbl_1_data_3B198[16] = "LIST_END GER";
static char lbl_1_data_3B1A8[16] = "LIST_END FRA";
static char lbl_1_data_3B1B8[16] = "LIST_END SPA";
static char lbl_1_data_3B1C8[16] = "LIST_END ITA";
static char lbl_1_data_3B1D8[104] = "\203\201\203\202\203\212\201[\203J\201[\203h\210\310\212O\202\314\202\340\202\314\202\252\214\251[\202\335]\202\302\202\251\202\350\202\334\202\265\202\275\201B\n\202\261\202\314\202\334\202\334\202\305\202\315\215\354[\202\263\202\254]\213\306[\202\345\202\244]\202\252\225\333[\202\331]\221\266[\202\274\202\361]\202\305\202\253\202\334\202\271\202\361\201B";
static char lbl_1_data_3B240[56] = "Created Emblems cannot be\nsaved to this Memory Card.";
static char lbl_1_data_3B278[16] = "LIST_END GER";
static char lbl_1_data_3B288[16] = "LIST_END FRA";
static char lbl_1_data_3B298[16] = "LIST_END SPA";
static char lbl_1_data_3B2A8[16] = "LIST_END ITA";
static char lbl_1_data_3B2B8[72] = "\202\261\202\314\202\334\202\334\202\305\202\315\203G\203\223\203u\203\214\203\200\202\314\215\354[\202\263\202\254]\213\306[\202\345\202\244]\202\252\225\333[\202\331]\221\266[\202\274\202\361]\202\305\202\253\202\334\202\271\202\361\201B";
static char lbl_1_data_3B300[44] = "The FILE Data exists in SLOT. \nOverwrite?";
static char lbl_1_data_3B32C[20] = "OVERWRITE_QUERY GER";
static char lbl_1_data_3B340[20] = "OVERWRITE_QUERY FRA";
static char lbl_1_data_3B354[20] = "OVERWRITE_QUERY SPA";
static char lbl_1_data_3B368[20] = "OVERWRITE_QUERY ITA";
static char lbl_1_data_3B37C[48] = "    \217\343[\202\244\202\355]\217\221[\202\252]\202\253\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H    ";
static char lbl_1_data_3B3AC[20] = "Create a New File";
static char lbl_1_data_3B3C0[16] = "NEW_CREATE GER";
static char lbl_1_data_3B3D0[16] = "NEW_CREATE FRA";
static char lbl_1_data_3B3E0[16] = "NEW_CREATE SPA";
static char lbl_1_data_3B3F0[16] = "NEW_CREATE ITA";
static char lbl_1_data_3B400[12] = "\220V\213K\215\354\220\254";
static char lbl_1_data_3B40C[20] = "Create a new file.";
static char lbl_1_data_3B420[20] = "NEW_CREATE_DO GER";
static char lbl_1_data_3B434[20] = "NEW_CREATE_DO FRA";
static char lbl_1_data_3B448[20] = "NEW_CREATE_DO SPA";
static char lbl_1_data_3B45C[20] = "NEW_CREATE_DO ITA";
static char lbl_1_data_3B470[32] = "\220V\213K\202\311\203t\203@\203C\203\213\202\360\215\354\220\254\202\265\202\334\202\267\201B";
static char lbl_1_data_3B490[28] = "Cannot create a new file.";
static char lbl_1_data_3B4AC[20] = "NEW_CREATE_DONT GER";
static char lbl_1_data_3B4C0[20] = "NEW_CREATE_DONT FRA";
static char lbl_1_data_3B4D4[20] = "NEW_CREATE_DONT SPA";
static char lbl_1_data_3B4E8[20] = "NEW_CREATE_DONT ITA";
static char lbl_1_data_3B4FC[36] = "\220V\213K\202\311\203t\203@\203C\203\213\202\360\215\354\220\254\202\305\202\253\202\334\202\271\202\361\201B";
static char lbl_1_data_3B520[32] = "%d block(s) of space available.";
static char lbl_1_data_3B540[16] = "FREE_SPACE GER";
static char lbl_1_data_3B550[16] = "FREE_SPACE FRA";
static char lbl_1_data_3B560[16] = "FREE_SPACE SPA";
static char lbl_1_data_3B570[16] = "FREE_SPACE ITA";
static char lbl_1_data_3B580[20] = "\213\363\202\253\227e\227\312 %d\203u\203\215\203b\203N";
static char lbl_1_data_3B594[52] = "%d block(s) needed. (%d free block(s) available)";
static char lbl_1_data_3B5C8[20] = "FREE_NEED_SPACE GER";
static char lbl_1_data_3B5DC[20] = "FREE_NEED_SPACE FRA";
static char lbl_1_data_3B5F0[20] = "FREE_NEED_SPACE SPA";
static char lbl_1_data_3B604[20] = "FREE_NEED_SPACE ITA";
static char lbl_1_data_3B618[36] = "%d\203u\203\215\203b\203N\225K\227v(\213\363\202\253\227e\227\312 %d\203u\203\215\203b\203N)";
static char lbl_1_data_3B63C[16] = "Corrupt File";
static char lbl_1_data_3B64C[16] = "BROKEN_FILE GER";
static char lbl_1_data_3B65C[16] = "BROKEN_FILE FRA";
static char lbl_1_data_3B66C[16] = "BROKEN_FILE SPA";
static char lbl_1_data_3B67C[16] = "BROKEN_FILE ITA";
static char lbl_1_data_3B68C[16] = "\211\363\202\352\202\275\203t\203@\203C\203\213";
static char lbl_1_data_3B69C[44] = "This file is corrupted and must be deleted.";
static char lbl_1_data_3B6C8[20] = "BROKEN_FILE_DEL GER";
static char lbl_1_data_3B6DC[20] = "BROKEN_FILE_DEL FRA";
static char lbl_1_data_3B6F0[20] = "BROKEN_FILE_DEL SPA";
static char lbl_1_data_3B704[20] = "BROKEN_FILE_DEL ITA";
static char lbl_1_data_3B718[52] = "\202\261\202\314\203t\203@\203C\203\213\202\315\211\363\202\352\202\304\202\242\202\351\202\314\202\305\217\301\202\267\225K\227v\202\252\202\240\202\350\202\334\202\267\201B";
static char *lbl_1_data_3B74C[113][6] = {lbl_1_data_35BF4, lbl_1_data_35C44, lbl_1_data_35C50, lbl_1_data_35C5C, lbl_1_data_35C68, lbl_1_data_35C74, lbl_1_data_35CE0, lbl_1_data_35D24, lbl_1_data_35D34, lbl_1_data_35D44, lbl_1_data_35D54, lbl_1_data_35D64, lbl_1_data_35DC4, lbl_1_data_35E34, lbl_1_data_35E40, lbl_1_data_35E4C, lbl_1_data_35E58, lbl_1_data_35E64, lbl_1_data_35F4C, lbl_1_data_35FA4, lbl_1_data_35FB0, lbl_1_data_35FBC, lbl_1_data_35FC8, lbl_1_data_35FD4, lbl_1_data_3603C, lbl_1_data_36070, lbl_1_data_36088, lbl_1_data_360A0, lbl_1_data_360B8, lbl_1_data_360D0, lbl_1_data_360F8, lbl_1_data_36128, lbl_1_data_36140, lbl_1_data_36158, lbl_1_data_36170, lbl_1_data_36188, lbl_1_data_361B0, lbl_1_data_361E0, lbl_1_data_361F8, lbl_1_data_36210, lbl_1_data_36228, lbl_1_data_36240, lbl_1_data_36270, lbl_1_data_362A0, lbl_1_data_362BC, lbl_1_data_362D8, lbl_1_data_362F4, lbl_1_data_36310, lbl_1_data_36338, lbl_1_data_3636C, lbl_1_data_36388, lbl_1_data_363A4, lbl_1_data_363C0, lbl_1_data_363DC, lbl_1_data_36408, lbl_1_data_3644C, lbl_1_data_3646C, lbl_1_data_3648C, lbl_1_data_364AC, lbl_1_data_364CC, lbl_1_data_36510, lbl_1_data_36554, lbl_1_data_36574, lbl_1_data_36594, lbl_1_data_365B4, lbl_1_data_365D4, lbl_1_data_36618, lbl_1_data_36648, lbl_1_data_36668, lbl_1_data_36688, lbl_1_data_366A8, lbl_1_data_366C8, lbl_1_data_366F8, lbl_1_data_3673C, lbl_1_data_3675C, lbl_1_data_3677C, lbl_1_data_3679C, lbl_1_data_367BC, lbl_1_data_36800, lbl_1_data_36844, lbl_1_data_36864, lbl_1_data_36884, lbl_1_data_368A4, lbl_1_data_368C4, lbl_1_data_36908, lbl_1_data_36928, lbl_1_data_36938, lbl_1_data_36948, lbl_1_data_36958, lbl_1_data_36968, lbl_1_data_36984, lbl_1_data_36998, lbl_1_data_369A8, lbl_1_data_369B8, lbl_1_data_369C8, lbl_1_data_369D8, lbl_1_data_369E8, lbl_1_data_36A1C, lbl_1_data_36A34, lbl_1_data_36A4C, lbl_1_data_36A64, lbl_1_data_36A7C, lbl_1_data_36AB0, lbl_1_data_36AE4, lbl_1_data_36AFC, lbl_1_data_36B14, lbl_1_data_36B2C, lbl_1_data_36B44, lbl_1_data_36B78, lbl_1_data_36B98, lbl_1_data_36BB0, lbl_1_data_36BC8, lbl_1_data_36BE0, lbl_1_data_36BF8, lbl_1_data_36C1C, lbl_1_data_36C50, lbl_1_data_36C6C, lbl_1_data_36C88, lbl_1_data_36CA4, lbl_1_data_36CC0, lbl_1_data_36CF0, lbl_1_data_36D28, lbl_1_data_36D44, lbl_1_data_36D60, lbl_1_data_36D7C, lbl_1_data_36D98, lbl_1_data_36DD0, lbl_1_data_36E10, lbl_1_data_36E30, lbl_1_data_36E50, lbl_1_data_36E70, lbl_1_data_36E90, lbl_1_data_36ED0, lbl_1_data_36F0C, lbl_1_data_36F2C, lbl_1_data_36F4C, lbl_1_data_36F6C, lbl_1_data_36F8C, lbl_1_data_36FCC, lbl_1_data_37008, lbl_1_data_37028, lbl_1_data_37048, lbl_1_data_37068, lbl_1_data_37088, lbl_1_data_370CC, lbl_1_data_3710C, lbl_1_data_3712C, lbl_1_data_3714C, lbl_1_data_3716C, lbl_1_data_3718C, lbl_1_data_371C8, lbl_1_data_37208, lbl_1_data_37228, lbl_1_data_37248, lbl_1_data_37268, lbl_1_data_37288, lbl_1_data_372C8, lbl_1_data_372F4, lbl_1_data_3730C, lbl_1_data_37324, lbl_1_data_3733C, lbl_1_data_37354, lbl_1_data_37380, lbl_1_data_373DC, lbl_1_data_373F4, lbl_1_data_3740C, lbl_1_data_37424, lbl_1_data_3743C, lbl_1_data_374A8, lbl_1_data_374D8, lbl_1_data_374E8, lbl_1_data_374F8, lbl_1_data_37508, lbl_1_data_37518, lbl_1_data_37550, lbl_1_data_375A4, lbl_1_data_375B8, lbl_1_data_375CC, lbl_1_data_375E0, lbl_1_data_375F4, lbl_1_data_3763C, lbl_1_data_37680, lbl_1_data_37690, lbl_1_data_376A0, lbl_1_data_376B0, lbl_1_data_376C0, lbl_1_data_37704, lbl_1_data_3773C, lbl_1_data_37750, lbl_1_data_37764, lbl_1_data_37778, lbl_1_data_3778C, lbl_1_data_377D0, lbl_1_data_37808, lbl_1_data_37818, lbl_1_data_37828, lbl_1_data_37838, lbl_1_data_37848, lbl_1_data_3788C, lbl_1_data_378EC, lbl_1_data_378FC, lbl_1_data_3790C, lbl_1_data_3791C, lbl_1_data_3792C, lbl_1_data_37984, lbl_1_data_379C0, lbl_1_data_379D0, lbl_1_data_379E0, lbl_1_data_379F0, lbl_1_data_37A00, lbl_1_data_37A58, lbl_1_data_37AB8, lbl_1_data_37ACC, lbl_1_data_37AE0, lbl_1_data_37AF4, lbl_1_data_37B08, lbl_1_data_37B74, lbl_1_data_37B9C, lbl_1_data_37BB0, lbl_1_data_37BC4, lbl_1_data_37BD8, lbl_1_data_37BEC, lbl_1_data_37C28, lbl_1_data_37C30, lbl_1_data_37C3C, lbl_1_data_37C48, lbl_1_data_37C54, lbl_1_data_37C60, lbl_1_data_37C6C, lbl_1_data_37C74, lbl_1_data_37C80, lbl_1_data_37C8C, lbl_1_data_37C98, lbl_1_data_37CA4, lbl_1_data_37CB0, lbl_1_data_37CB4, lbl_1_data_37CBC, lbl_1_data_37CC4, lbl_1_data_37CCC, lbl_1_data_37CD4, lbl_1_data_37CDC, lbl_1_data_37CE0, lbl_1_data_37CE8, lbl_1_data_37CF0, lbl_1_data_37CF8, lbl_1_data_37D00, lbl_1_data_37D08, lbl_1_data_37D44, lbl_1_data_37D58, lbl_1_data_37D6C, lbl_1_data_37D80, lbl_1_data_37D94, lbl_1_data_37DD4, lbl_1_data_37F64, lbl_1_data_37F70, lbl_1_data_37F7C, lbl_1_data_37F88, lbl_1_data_37F94, lbl_1_data_381E4, lbl_1_data_382C8, lbl_1_data_382D4, lbl_1_data_382E0, lbl_1_data_382EC, lbl_1_data_382F8, lbl_1_data_38454, lbl_1_data_385E4, lbl_1_data_385F4, lbl_1_data_38604, lbl_1_data_38614, lbl_1_data_38624, lbl_1_data_38874, lbl_1_data_38958, lbl_1_data_3896C, lbl_1_data_38980, lbl_1_data_38994, lbl_1_data_389A8, lbl_1_data_38B04, lbl_1_data_38B58, lbl_1_data_38B6C, lbl_1_data_38B80, lbl_1_data_38B94, lbl_1_data_38BA8, lbl_1_data_38C08, lbl_1_data_38C30, lbl_1_data_38C48, lbl_1_data_38C60, lbl_1_data_38C78, lbl_1_data_38C90, lbl_1_data_38CCC, lbl_1_data_38D00, lbl_1_data_38D10, lbl_1_data_38D20, lbl_1_data_38D30, lbl_1_data_38D40, lbl_1_data_38D80, lbl_1_data_38D98, lbl_1_data_38DAC, lbl_1_data_38DC0, lbl_1_data_38DD4, lbl_1_data_38DE8, lbl_1_data_38E04, lbl_1_data_38E0C, lbl_1_data_38E18, lbl_1_data_38E24, lbl_1_data_38E30, lbl_1_data_38E3C, lbl_1_data_38E48, lbl_1_data_38E80, lbl_1_data_38E90, lbl_1_data_38EA0, lbl_1_data_38EB0, lbl_1_data_38EC0, lbl_1_data_38F04, lbl_1_data_38F30, lbl_1_data_38F40, lbl_1_data_38F50, lbl_1_data_38F60, lbl_1_data_38F70, lbl_1_data_38FA8, lbl_1_data_38FE8, lbl_1_data_38FF8, lbl_1_data_39008, lbl_1_data_39018, lbl_1_data_39028, lbl_1_data_3906C, lbl_1_data_390C4, lbl_1_data_390D4, lbl_1_data_390E4, lbl_1_data_390F4, lbl_1_data_39104, lbl_1_data_39148, lbl_1_data_39190, lbl_1_data_3919C, lbl_1_data_391A8, lbl_1_data_391B4, lbl_1_data_391C0, lbl_1_data_39214, lbl_1_data_39248, lbl_1_data_39254, lbl_1_data_39260, lbl_1_data_3926C, lbl_1_data_39278, lbl_1_data_392AC, lbl_1_data_392E4, lbl_1_data_392F0, lbl_1_data_392FC, lbl_1_data_39308, lbl_1_data_39314, lbl_1_data_39348, lbl_1_data_3937C, lbl_1_data_39388, lbl_1_data_39394, lbl_1_data_393A0, lbl_1_data_393AC, lbl_1_data_393E0, lbl_1_data_39418, lbl_1_data_39424, lbl_1_data_39430, lbl_1_data_3943C, lbl_1_data_39448, lbl_1_data_3947C, lbl_1_data_394B8, lbl_1_data_394C8, lbl_1_data_394D8, lbl_1_data_394E8, lbl_1_data_394F8, lbl_1_data_39520, lbl_1_data_39550, lbl_1_data_39564, lbl_1_data_39578, lbl_1_data_3958C, lbl_1_data_395A0, lbl_1_data_395DC, lbl_1_data_39618, lbl_1_data_39628, lbl_1_data_39638, lbl_1_data_39648, lbl_1_data_39658, lbl_1_data_39694, lbl_1_data_396BC, lbl_1_data_396CC, lbl_1_data_396DC, lbl_1_data_396EC, lbl_1_data_396FC, lbl_1_data_39740, lbl_1_data_39780, lbl_1_data_39790, lbl_1_data_397A0, lbl_1_data_397B0, lbl_1_data_397C0, lbl_1_data_39800, lbl_1_data_39838, lbl_1_data_39848, lbl_1_data_39858, lbl_1_data_39868, lbl_1_data_39878, lbl_1_data_398A0, lbl_1_data_398B0, lbl_1_data_398C0, lbl_1_data_398D0, lbl_1_data_398E0, lbl_1_data_398F0, lbl_1_data_39900, lbl_1_data_3990C, lbl_1_data_3991C, lbl_1_data_3992C, lbl_1_data_3993C, lbl_1_data_3994C, lbl_1_data_39958, lbl_1_data_39968, lbl_1_data_39978, lbl_1_data_39988, lbl_1_data_39998, lbl_1_data_399A8, lbl_1_data_399B8, lbl_1_data_399C8, lbl_1_data_399D8, lbl_1_data_399E8, lbl_1_data_399F8, lbl_1_data_39A08, lbl_1_data_39A18, lbl_1_data_39A6C, lbl_1_data_39A78, lbl_1_data_39A84, lbl_1_data_39A90, lbl_1_data_39A9C, lbl_1_data_39B04, lbl_1_data_39B58, lbl_1_data_39B64, lbl_1_data_39B70, lbl_1_data_39B7C, lbl_1_data_39B88, lbl_1_data_39BF0, lbl_1_data_39C1C, lbl_1_data_39C2C, lbl_1_data_39C3C, lbl_1_data_39C4C, lbl_1_data_39C5C, lbl_1_data_39C88, lbl_1_data_39CB8, lbl_1_data_39CC8, lbl_1_data_39CD8, lbl_1_data_39CE8, lbl_1_data_39CF8, lbl_1_data_39D2C, lbl_1_data_39DC4, lbl_1_data_39DDC, lbl_1_data_39DF4, lbl_1_data_39E0C, lbl_1_data_39E24, lbl_1_data_39EB0, lbl_1_data_39EF4, lbl_1_data_39F0C, lbl_1_data_39F24, lbl_1_data_39F3C, lbl_1_data_39F54, lbl_1_data_39FA4, lbl_1_data_3A018, lbl_1_data_3A01C, lbl_1_data_3A020, lbl_1_data_3A024, lbl_1_data_3A028, lbl_1_data_3A0E4, lbl_1_data_3A15C, lbl_1_data_3A160, lbl_1_data_3A164, lbl_1_data_3A168, lbl_1_data_3A16C, lbl_1_data_3A1C8, lbl_1_data_3A1D0, lbl_1_data_3A1DC, lbl_1_data_3A1E8, lbl_1_data_3A1F4, lbl_1_data_3A200, lbl_1_data_3A208, lbl_1_data_3A210, lbl_1_data_3A21C, lbl_1_data_3A228, lbl_1_data_3A234, lbl_1_data_3A240, lbl_1_data_3A248, lbl_1_data_3A250, lbl_1_data_3A25C, lbl_1_data_3A268, lbl_1_data_3A274, lbl_1_data_3A280, lbl_1_data_3A28C, lbl_1_data_3A294, lbl_1_data_3A2A0, lbl_1_data_3A2AC, lbl_1_data_3A2B8, lbl_1_data_3A2C4, lbl_1_data_3A2D0, lbl_1_data_3A2D8, lbl_1_data_3A2E4, lbl_1_data_3A2F0, lbl_1_data_3A2FC, lbl_1_data_3A308, lbl_1_data_3A314, lbl_1_data_3A31C, lbl_1_data_3A328, lbl_1_data_3A334, lbl_1_data_3A340, lbl_1_data_3A34C, lbl_1_data_3A358, lbl_1_data_3A360, lbl_1_data_3A36C, lbl_1_data_3A378, lbl_1_data_3A384, lbl_1_data_3A390, lbl_1_data_3A39C, lbl_1_data_3A3A4, lbl_1_data_3A3B0, lbl_1_data_3A3BC, lbl_1_data_3A3C8, lbl_1_data_3A3D4, lbl_1_data_3A3DC, lbl_1_data_3A520, lbl_1_data_3A524, lbl_1_data_3A528, lbl_1_data_3A52C, lbl_1_data_3A530, lbl_1_data_3A6A0, lbl_1_data_3A6E4, lbl_1_data_3A6E8, lbl_1_data_3A6EC, lbl_1_data_3A6F0, lbl_1_data_3A6F4, lbl_1_data_3A738, lbl_1_data_3A77C, lbl_1_data_3A780, lbl_1_data_3A784, lbl_1_data_3A788, lbl_1_data_3A78C, lbl_1_data_3A7D4, lbl_1_data_3A80C, lbl_1_data_3A810, lbl_1_data_3A814, lbl_1_data_3A818, lbl_1_data_3A81C, lbl_1_data_3A874, lbl_1_data_3A87C, lbl_1_data_3A880, lbl_1_data_3A884, lbl_1_data_3A888, lbl_1_data_3A88C, lbl_1_data_3A894, lbl_1_data_3A89C, lbl_1_data_3A8A0, lbl_1_data_3A8A4, lbl_1_data_3A8A8, lbl_1_data_3A8AC, lbl_1_data_3A8B4, lbl_1_data_3A8BC, lbl_1_data_3A8C0, lbl_1_data_3A8C4, lbl_1_data_3A8C8, lbl_1_data_3A8CC, lbl_1_data_3A8D4, lbl_1_data_3A8DC, lbl_1_data_3A8E0, lbl_1_data_3A8E4, lbl_1_data_3A8E8, lbl_1_data_3A8EC, lbl_1_data_3A8F4, lbl_1_data_3A928, lbl_1_data_3A92C, lbl_1_data_3A930, lbl_1_data_3A934, lbl_1_data_3A938, lbl_1_data_3A98C, lbl_1_data_3A9E0, lbl_1_data_3A9E4, lbl_1_data_3A9E8, lbl_1_data_3A9EC, lbl_1_data_3A9F0, lbl_1_data_3AA3C, lbl_1_data_3AA44, lbl_1_data_3AA48, lbl_1_data_3AA4C, lbl_1_data_3AA50, lbl_1_data_3AA54, lbl_1_data_3AA60, lbl_1_data_3AAA0, lbl_1_data_3AAB4, lbl_1_data_3AAC8, lbl_1_data_3AADC, lbl_1_data_3AAF0, lbl_1_data_3ABCC, lbl_1_data_3AC48, lbl_1_data_3AC58, lbl_1_data_3AC68, lbl_1_data_3AC78, lbl_1_data_3AC88, lbl_1_data_3AD68, lbl_1_data_3ADD8, lbl_1_data_3ADEC, lbl_1_data_3AE00, lbl_1_data_3AE14, (char *)lbl_1_data_3AE28, lbl_1_data_3AE2C, lbl_1_data_3AED4, lbl_1_data_3AEE4, lbl_1_data_3AEF4, lbl_1_data_3AF04, (char *)lbl_1_data_3AF14, lbl_1_data_3AF18, lbl_1_data_3AFC0, lbl_1_data_3AFD0, lbl_1_data_3AFE0, lbl_1_data_3AFF0, lbl_1_data_3B000, lbl_1_data_3B0B8, lbl_1_data_3B0E0, lbl_1_data_3B0F0, lbl_1_data_3B100, lbl_1_data_3B110, lbl_1_data_3B120, lbl_1_data_3B150, lbl_1_data_3B198, lbl_1_data_3B1A8, lbl_1_data_3B1B8, lbl_1_data_3B1C8, lbl_1_data_3B1D8, lbl_1_data_3B240, lbl_1_data_3B278, lbl_1_data_3B288, lbl_1_data_3B298, lbl_1_data_3B2A8, lbl_1_data_3B2B8, lbl_1_data_3B300, lbl_1_data_3B32C, lbl_1_data_3B340, lbl_1_data_3B354, lbl_1_data_3B368, lbl_1_data_3B37C, lbl_1_data_3B3AC, lbl_1_data_3B3C0, lbl_1_data_3B3D0, lbl_1_data_3B3E0, lbl_1_data_3B3F0, lbl_1_data_3B400, lbl_1_data_3B40C, lbl_1_data_3B420, lbl_1_data_3B434, lbl_1_data_3B448, lbl_1_data_3B45C, lbl_1_data_3B470, lbl_1_data_3B490, lbl_1_data_3B4AC, lbl_1_data_3B4C0, lbl_1_data_3B4D4, lbl_1_data_3B4E8, lbl_1_data_3B4FC, lbl_1_data_3B520, lbl_1_data_3B540, lbl_1_data_3B550, lbl_1_data_3B560, lbl_1_data_3B570, lbl_1_data_3B580, lbl_1_data_3B594, lbl_1_data_3B5C8, lbl_1_data_3B5DC, lbl_1_data_3B5F0, lbl_1_data_3B604, lbl_1_data_3B618, lbl_1_data_3B63C, lbl_1_data_3B64C, lbl_1_data_3B65C, lbl_1_data_3B66C, lbl_1_data_3B67C, lbl_1_data_3B68C, lbl_1_data_3B69C, lbl_1_data_3B6C8, lbl_1_data_3B6DC, lbl_1_data_3B6F0, lbl_1_data_3B704, lbl_1_data_3B718};
static s32 lbl_1_data_3C1E4 = 100;
static char lbl_1_data_3C1E8[16] = "MEMMODE_SAVE";
static char lbl_1_data_3C1F8[20] = "MEMMODE_SAVE_SECTOR";
static char lbl_1_data_3C20C[16] = "MEMMODE_LOAD";
static char lbl_1_data_3C21C[16] = "MEMMODE_LIST";
static char lbl_1_data_3C22C[24] = "MEMMODE_LIST_AND_LOAD";
static char lbl_1_data_3C244[16] = "MEMMODE_DELETE";
static char lbl_1_data_3C254[16] = "MEMMODE_CHECK";
static char *lbl_1_data_3C264[8] = {lbl_1_data_3C1E8, lbl_1_data_3C1F8, lbl_1_data_3C20C, lbl_1_data_3C21C, lbl_1_data_3C22C, lbl_1_data_3C244, lbl_1_data_3C254, 0};
static char lbl_1_data_3C284[12] = "MEMSUB_HALT";
static char lbl_1_data_3C290[16] = "MEMSUB_ERROR";
static char lbl_1_data_3C2A0[20] = "MEMSUB_NOSAVE_EXIT";
static char lbl_1_data_3C2B4[16] = "MEMSUB_MOUNT";
static char lbl_1_data_3C2C4[16] = "MEMSUB_CHECK";
static char lbl_1_data_3C2D4[20] = "MEMSUB_FORMAT_QUERY";
static char lbl_1_data_3C2E8[16] = "MEMSUB_FORMAT";
static char lbl_1_data_3C2F8[20] = "MEMSUB_GET_SERIAL";
static char lbl_1_data_3C30C[20] = "MEMSUB_DELETE_TMP";
static char lbl_1_data_3C320[20] = "MEMSUB_CHECK_FREE";
static char lbl_1_data_3C334[20] = "MEMSUB_CHECK_EXIST";
static char lbl_1_data_3C348[24] = "MEMSUB_OVERWRITE_QUERY";
static char lbl_1_data_3C360[20] = "MEMSUB_DELETE_FILE";
static char lbl_1_data_3C374[20] = "MEMSUB_CREATE_TMP";
static char lbl_1_data_3C388[16] = "MEMSUB_GET_STAT";
static char lbl_1_data_3C398[16] = "MEMSUB_SAVE_TMP";
static char lbl_1_data_3C3A8[16] = "MEMSUB_SET_STAT";
static char lbl_1_data_3C3B8[20] = "MEMSUB_DELETE_OLD";
static char lbl_1_data_3C3CC[16] = "MEMSUB_RENAME";
static char lbl_1_data_3C3DC[24] = "MEMSUB_CHECK_FREE_LAST";
static char lbl_1_data_3C3F4[16] = "MEMSUB_SAVE_END";
static char lbl_1_data_3C404[20] = "MEMSUB_NOLOAD_EXIT";
static char lbl_1_data_3C418[20] = "MEMSUB_FORMAT_END";
static char lbl_1_data_3C42C[20] = "MEMSUB_LOAD_FILE";
static char lbl_1_data_3C440[16] = "MEMSUB_LOAD_END";
static char lbl_1_data_3C450[16] = "MEMSUB_GET_LIST";
static char lbl_1_data_3C460[16] = "MEMSUB_LIST_END";
static char lbl_1_data_3C470[20] = "MEMSUB_NOLIST_EXIT";
static char lbl_1_data_3C484[20] = "MEMSUB_DELETE_NAME";
static char lbl_1_data_3C498[20] = "MEMSUB_DELETE_END";
static char lbl_1_data_3C4AC[20] = "MEMSUB_NODEL_EXIT";
static char lbl_1_data_3C4C0[24] = "MEMSUB_NOFILE_CHECKFREE";
static char lbl_1_data_3C4D8[28] = "MEMSUB_NOLOAD_EXIT_NOMSG";
static char lbl_1_data_3C4F4[24] = "MEMSUB_GET_LIST_MIDDLE";
static char lbl_1_data_3C50C[20] = "MEMSUB_CHECK_END";
static char lbl_1_data_3C520[24] = "MEMSUB_GET_LIST_NOBAR";
static char lbl_1_data_3C538[24] = "MEMSUB_SAVE_SECTOR_TMP";
static char lbl_1_data_3C550[24] = "MEMSUB_SAVE_HEADER_TMP";
static char lbl_1_data_3C568[16] = "MEMSUB_ENCODING";
static char lbl_1_data_3C578[20] = "MEMSUB_ATTRIBUTE";
static char *lbl_1_data_3C58C[41] = {lbl_1_data_3C284, lbl_1_data_3C290, lbl_1_data_3C2A0, lbl_1_data_3C2B4, lbl_1_data_3C2C4, lbl_1_data_3C2D4, lbl_1_data_3C2E8, lbl_1_data_3C2F8, lbl_1_data_3C30C, lbl_1_data_3C320, lbl_1_data_3C334, lbl_1_data_3C348, lbl_1_data_3C360, lbl_1_data_3C374, lbl_1_data_3C388, lbl_1_data_3C398, lbl_1_data_3C3A8, lbl_1_data_3C3B8, lbl_1_data_3C3CC, lbl_1_data_3C3DC, lbl_1_data_3C3F4, lbl_1_data_3C404, lbl_1_data_3C418, lbl_1_data_3C42C, lbl_1_data_3C440, lbl_1_data_3C450, lbl_1_data_3C460, lbl_1_data_3C470, lbl_1_data_3C484, lbl_1_data_3C498, lbl_1_data_3C4AC, lbl_1_data_3C4C0, lbl_1_data_3C4D8, lbl_1_data_3C4F4, lbl_1_data_3C50C, lbl_1_data_3C520, lbl_1_data_3C538, lbl_1_data_3C550, lbl_1_data_3C568, lbl_1_data_3C578, 0};
static void *lbl_1_data_3C630[8] = {(void *)fn_1_AD1E4, (void *)fn_1_AEC34, (void *)fn_1_B03A8, (void *)fn_1_B1710, (void *)fn_1_B2770, (void *)fn_1_B38F4, (void *)fn_1_B40B4, 0};
static void *lbl_1_data_3C650[8] = {(void *)fn_1_AD264, (void *)fn_1_AECCC, (void *)fn_1_B03CC, (void *)fn_1_B171C, (void *)fn_1_B277C, (void *)fn_1_B3900, (void *)fn_1_B40C0, 0};
static void *lbl_1_data_3C670[41] = {(void *)fn_1_AAEB0, (void *)fn_1_AAF1C, (void *)fn_1_AB438, (void *)fn_1_AB478, (void *)fn_1_AB598, (void *)fn_1_AB61C, (void *)fn_1_AB75C, (void *)fn_1_AB870, (void *)fn_1_AB8D8, (void *)fn_1_AB98C, (void *)fn_1_ABA9C, (void *)fn_1_ABB24, (void *)fn_1_ABC5C, (void *)fn_1_ABCE8, (void *)fn_1_ABDA8, (void *)fn_1_ABE14, (void *)fn_1_AC294, (void *)fn_1_AC328, (void *)fn_1_AC3DC, (void *)fn_1_AC4B4, (void *)fn_1_AC53C, (void *)fn_1_AC6A8, (void *)fn_1_AC6E0, (void *)fn_1_AC704, (void *)fn_1_AC79C, (void *)fn_1_AC92C, (void *)fn_1_ACA78, (void *)fn_1_AC908, (void *)fn_1_ACE80, (void *)fn_1_ACF30, (void *)fn_1_ACF0C, (void *)fn_1_ABA14, (void *)fn_1_AC6CC, (void *)fn_1_AD09C, (void *)fn_1_ACD04, (void *)fn_1_ACA00, (void *)fn_1_ABF44, (void *)fn_1_AC12C, (void *)fn_1_AD140, (void *)fn_1_AD168, 0};
static void *lbl_1_data_3C714[41] = {(void *)fn_1_AAF18, (void *)fn_1_AB434, (void *)fn_1_AB458, (void *)fn_1_AB4F4, (void *)fn_1_AB5CC, (void *)fn_1_AB64C, (void *)fn_1_AB7C4, (void *)fn_1_AB880, (void *)fn_1_AB93C, (void *)fn_1_AB99C, (void *)fn_1_ABAAC, (void *)fn_1_ABB4C, (void *)fn_1_ABC98, (void *)fn_1_ABD58, (void *)fn_1_ABDB8, (void *)fn_1_ABE88, (void *)fn_1_AC2D8, (void *)fn_1_AC38C, (void *)fn_1_AC464, (void *)fn_1_AC4C4, (void *)fn_1_AC6A4, (void *)fn_1_AC6C8, (void *)fn_1_AC700, (void *)fn_1_AC74C, (void *)fn_1_AC904, (void *)fn_1_AC960, (void *)fn_1_ACD00, (void *)fn_1_AC928, (void *)fn_1_ACEBC, (void *)fn_1_AD098, (void *)fn_1_ACF2C, (void *)fn_1_ABA24, (void *)fn_1_AC6DC, (void *)fn_1_AD0A0, (void *)fn_1_ACE7C, (void *)fn_1_ACA1C, (void *)fn_1_AC000, (void *)fn_1_AC188, (void *)fn_1_AD164, (void *)fn_1_AD1AC, 0};
/* lbl_1_data_3C8E0..3CB50: jump table (compiler-generated) */
/* lbl_1_data_3CB68..3CC04: jump table (compiler-generated) */
/* lbl_1_data_3CC0C..3CDE0: jump table (compiler-generated) */
/* lbl_1_data_3CEF4..3CF18: jump table (compiler-generated) */

/* fzgx:begin fn_1_AA590 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Ent (*)[2])&lbl_1_bss_716C8)
#define lbl_1_bss_71808 (*(s32 *)&lbl_1_bss_71808)
#define lbl_1_bss_71810 (*(Ent *)&lbl_1_bss_71810)
#define lbl_1_bss_718B2 (*(u8 *)&lbl_1_bss_718B2)
#define lbl_1_bss_718C0 (*(void * *)&lbl_1_bss_718C0)
#define lbl_1_bss_718E0 (*(u8 *)&lbl_1_bss_718E0)
void fn_1_AA590(void)
{

    int i;
    Ent *e = lbl_1_bss_716C8;
    lbl_1_bss_71808 = 0;
    lbl_1_bss_7180C = 1;
    for (i = 0; i < 2; i++, e++) {
        e->c = 0;
        e->w24 = 0;
        e->a0 = i;
        e->b2 = 0xff; e->b3 = 0xff; e->b4 = 0xff; e->b5 = 0xff; e->b6 = 0xff;
        e->b7 = 0;
        e->s8_ = -1;
        e->sa = -1;
        e->w30 = 0;
        e->f34 = 0.0f;
        e->f38 = 0.0f;
        e->b2a = 0;
        e->a1 = -3;
        e->b2b = -3;
        e->w3c = -1;
        e->w40 = -1;
        e->w4c = 0;
        e->w48 = 0;
        e->w50 = 0;
    }
    lbl_1_bss_71810 = lbl_1_bss_716C8[0];
    lbl_1_bss_71810.a0 = 2;
    lbl_1_bss_718B0 = 0xff;
    lbl_1_bss_718B1 = 5;
    lbl_1_bss_718B2 = 0xff;
    lbl_1_bss_718B4 = 0;
    lbl_1_bss_718B8 = 0;
    lbl_1_bss_718B9 = 0;
    lbl_1_bss_718BC = 0;
    fn_1_C3378();
    lbl_1_bss_718C0 = &lbl_1_bss_718E0 + 0x55c2;
    lbl_1_data_3C1E4 = 100;
    lbl_1_bss_772C0[0] = -1;
    lbl_1_bss_772C0[1] = -1;
}
#undef lbl_1_bss_716C8
#undef lbl_1_bss_71808
#undef lbl_1_bss_71810
#undef lbl_1_bss_718B2
#undef lbl_1_bss_718C0
#undef lbl_1_bss_718E0
#undef lbl_1_data_3C1E4
/* fzgx:end fn_1_AA590 */

/* fzgx:begin fn_1_AA6D8 */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
#define lbl_1_bss_716C8 (*(DriverEntry (*)[2])&lbl_1_bss_716C8)
#define lbl_1_bss_71810 (*(DriverEntry *)&lbl_1_bss_71810)
#define lbl_1_bss_718B2 (*(u8 *)&lbl_1_bss_718B2)
#define lbl_1_bss_772C8 (*(char (*)[0x20])&lbl_1_bss_772C8)
#define lbl_1_data_3C630 (*(u32 (*)[1])&lbl_1_data_3C630)
#define lbl_1_rodata_4AE0 ((DriverDesc *)&lbl_1_rodata_4AE0)
void fn_1_AA6D8(u8 kind, u8 slot, DriverParam *param) {
    DriverEntry *entry;
    s32 has0;
    s32 has1;
    s32 v;

    if (param->unk_0 == 1) {
        slot = 0;
    }
    switch (slot) {
    case 0:
    case 1:
        entry = lbl_1_bss_716C8;
        lbl_1_bss_718B1 = slot;
        entry += slot;
        break;
    case 4:
        if (lbl_1_bss_718B1 == 0 || lbl_1_bss_718B1 == 1) {
            entry = lbl_1_bss_716C8;
            entry += lbl_1_bss_718B1;
            break;
        }
        {
            DriverEntry *pair = lbl_1_bss_716C8;
            has0 = pair[0].unk_1 != -3;
            has1 = pair[1].unk_1 != -3;
            if (has0 && !has1) {
                lbl_1_bss_718B1 = 0;
                entry = pair;
                break;
            }
        }
        if (has1 && !has0) {
            lbl_1_bss_718B1 = 1;
            entry = lbl_1_bss_716C8;
            entry += 1;
            break;
        }
        lbl_1_bss_718B1 = 0;
        /* fallthrough */
    case 2:
    use_extra:
        lbl_1_bss_718B2 = 2;
        entry = &lbl_1_bss_71810;
        break;
    case 3:
        if (lbl_1_bss_718B1 == 0 || lbl_1_bss_718B1 == 1) {
            entry = lbl_1_bss_716C8;
            entry += lbl_1_bss_718B1;
            break;
        }
        goto use_extra; /* fzgx-allow: S1 case 3 shares case 2's tail; retail jumps into it rather than duplicating the block */
    }

    entry->unk_24 = ((void *)fn_1_4630(lbl_801A6410, 0xF0, (void *)((char *)((u8 *)"memcard.c")), 0x33C));
    if (param->unk_0 == 0) {
        param->unk_4 = 4;
    }
    entry->unk_24->unk_8 = param->unk_4;
    entry->unk_24->unk_0 = param->unk_0;
    entry->unk_24->unk_8C = &lbl_1_rodata_4AE0[param->unk_0];
    {
        DriverObj *obj = entry->unk_24;
        v = obj->unk_8C->unk_44;
        if (v == -1) {
            obj->unk_E0 = 0;
        } else {
            obj->unk_E0 = v;
        }
    }
    entry->unk_2 = kind;
    lbl_1_bss_718B8 = 0;
    lbl_1_bss_718B9 = 0;
    lbl_1_bss_772C8[0] = 0;

    if (kind == 6) {
        s32 i;
        entry->unk_24->unk_8 |= 0x20;
        entry->unk_24->unk_94 = param->unk_C;
        for (i = 0; i < 0x7F; i++) {
            DriverSub *sub = &entry->unk_24->unk_94[i];
            if (sub->unk_0 != 0) {
                sub->unk_8 = &lbl_1_rodata_4AE0[sub->unk_4];
                sub->unk_2C = 0;
            }
        }
    } else if (kind == 3 || kind == 4) {
        entry->unk_24->unk_8 |= 0x20;
        entry->unk_24->unk_E8 = param->unk_20;
        entry->unk_24->unk_94 = param->unk_C;
        lbl_1_bss_716C0 = 0;
    } else if (kind == 5) {
        entry->unk_24->unk_8 |= 0x20;
        strcpy((void *)entry->unk_24->unk_98, (void *)((char *)entry->unk_24->unk_8C));
        strncat(entry->unk_24->unk_98, param->unk_14, 0x1F - ((unsigned long)strlen(entry->unk_24->unk_98)));
        strcat((void *)entry->unk_24->unk_98, (void *)((char *)((u8 *)".dat")));
    } else {
        DriverObj *obj = entry->unk_24;
        u32 size = obj->unk_8C->unk_40;
        if (size == 0) {
            obj->unk_8 |= 0x20;
            entry->unk_24->unk_B8 = param->unk_10;
            entry->unk_24->unk_C = (param->unk_10 + 0x405F) & ~0x1FFF;
            entry->unk_24->unk_E4 = entry->unk_24->unk_C;
            strcpy((void *)entry->unk_24->unk_98, (void *)((char *)entry->unk_24->unk_8C));
            strncat(entry->unk_24->unk_98, param->unk_14, 0x1F - ((unsigned long)strlen(entry->unk_24->unk_98)));
            if (kind == 0) {
                strcpy((void *)lbl_1_bss_772C8, (void *)entry->unk_24->unk_98);
            }
            if (entry->unk_24->unk_8 & 0x1000) {
                strcpy((void *)entry->unk_24->unk_BC, (void *)((char *)entry->unk_24->unk_8C));
                strncat(entry->unk_24->unk_BC, param->unk_18, 0x1F - ((unsigned long)strlen(entry->unk_24->unk_BC)));
            }
            entry->unk_24->unk_94 = param->unk_C;
        } else {
            obj->unk_B8 = size;
            entry->unk_24->unk_C = (entry->unk_24->unk_8C->unk_40 + 0x405F) & ~0x1FFF;
            if (entry->unk_24->unk_8C->unk_44 != -1) {
                entry->unk_24->unk_E4 = entry->unk_24->unk_8C->unk_48;
            } else {
                entry->unk_24->unk_E4 = entry->unk_24->unk_C;
            }
            strcpy((void *)entry->unk_24->unk_98, (void *)((char *)entry->unk_24->unk_8C));
            if (kind == 0) {
                strcpy((void *)lbl_1_bss_772C8, (void *)entry->unk_24->unk_98);
            }
            entry->unk_24->unk_94 = fn_1_45D0((u32)lbl_801A6410, entry->unk_24->unk_C, (void *)((char *)((u8 *)"memcard.c")), 0x3A8);
            fn_80008BEC((void *)entry->unk_24->unk_94, 0, entry->unk_24->unk_C);
        }
    }

    ((DriverFunc *)(((u8 *)lbl_1_data_3C630)))[kind](param, entry);
}
#undef lbl_1_bss_716C0
#undef lbl_1_bss_716C8
#undef lbl_1_bss_71810
#undef lbl_1_bss_718B2
#undef lbl_1_bss_772C8
#undef lbl_1_data_3C630
#undef lbl_1_rodata_4AE0
/* fzgx:end fn_1_AA6D8 */

/* fzgx:begin fn_1_AAB98 */
/* VIEWS */
#define lbl_1_bss_718B2 (*(u8 *)&lbl_1_bss_718B2)
static inline int fn_1_AAB98_confirm(void) {
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        fn_1_A2DC4(0xA9011100);
        return 1;
    }
    return 0;
}

static inline void fn_1_AAB98_setTone(fn_1_AAB98_Entry *e) {
    switch (e->unk_2) {
    case 2:
        e->unk_3 = 0x20;
        break;
    case 0:
    case 1:
        e->unk_3 = 2;
        break;
    case 3:
    case 4:
        e->unk_3 = 0x1B;
        break;
    case 5:
        e->unk_3 = 0x1E;
        break;
    }
}

static inline int fn_1_AAB98_tick(fn_1_AAB98_Entry *e) {
    if (!(e->unk_2A & 1)) {
        e->unk_28 = 12;
        e->unk_2A |= 1;
        return 0;
    }
    if (e->unk_28 > 0) {
        e->unk_28--;
        return 0;
    }
    return 1;
}

static inline void fn_1_AAB98_clear(fn_1_AAB98_Entry *e) {
    e->unk_4 = 0xFF;
    e->unk_5 = 0xFF;
    e->unk_6 = 0xFF;
    e->unk_7 = 0;
    e->unk_8 = -1;
    e->unk_A = -1;
    e->unk_30 = 0;
    e->unk_34 = 0.0f;
    e->unk_38 = 0.0f;
    e->unk_2A &= ~4;
    e->unk_3C = -1;
    e->unk_40 = -1;
}

static inline void fn_1_AAB98_commit(void) {
    fn_1_AAB98_Entry *e = &lbl_1_bss_716C8[lbl_1_bss_718B2];
    fn_1_AAB98_Entry *cur = &lbl_1_bss_71810;

    e->unk_2 = cur->unk_2;
    e->unk_3 = cur->unk_3;
    e->unk_4 = 0xFF;
    e->unk_5 = 0xFF;
    e->unk_6 = 0xFF;
    e->unk_7 = 0;
    lbl_1_bss_718B1 = lbl_1_bss_718B2;
    e->unk_24 = cur->unk_24;
    if (lbl_1_bss_77308 == 2) {
        e->unk_2A |= 4;
        if (e->unk_24 != NULL) {
            e->unk_24->unk_8 &= ~4;
            e->unk_24->unk_4 = -120;
        }
    }
    cur->unk_24->unk_8 &= ~2;
    cur->unk_24 = NULL;
    cur->unk_2 = 0xFF;
    cur->unk_3 = 0xFF;
    fn_1_AAB98_clear(&lbl_1_bss_71810);
    lbl_1_bss_718B2 = 0xFF;
}

void fn_1_AAB98(void) {
    u8 idx;
    int active;
    Obj_1_bss_9F8 *input;

    idx = lbl_1_bss_718B1;
    active = 0;
    if (idx == 0 && lbl_1_bss_716C8[0].unk_24 != NULL) {
        if (((fn_1_AAB98_Entry *)(lbl_1_bss_716C8))[0].unk_24->unk_0 == 1) {
            active = 1;
        } else {
            active = 0;
        }
    }

    if (idx == 0 && active) {
        lbl_1_bss_77308 = 1;
        lbl_1_bss_718B2 = 0;
    } else if (lbl_1_bss_77308 == 0) {
        input = &lbl_1_bss_9F8;
        if (((input->unk_10 & 1) || (input->unk_12 & 1)) && lbl_1_bss_718B2 == 1) {
            fn_1_A2DC4(0xA9011300);
            lbl_1_bss_718B2 = 0;
        } else if ((((input->unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) &&
                   lbl_1_bss_718B2 == 0) {
            fn_1_A2DC4(0xA9011300);
            lbl_1_bss_718B2 = 1;
        }
        lbl_1_bss_77308 = fn_1_AAB98_confirm();
    }

    switch (lbl_1_bss_77308) {
    case 2:
        fn_1_AAB98_setTone(&lbl_1_bss_71810);
        lbl_1_bss_718B2 = 0;
        /* fallthrough */
    case 1:
        if (lbl_1_bss_77308 == 1 && !fn_1_AAB98_tick(&lbl_1_bss_71810)) {
            break;
        }
        fn_1_AAB98_commit();
        break;
    case 0:
    default:
        break;
    }
}
/* fzgx:end fn_1_AAB98 */

/* fzgx:begin fn_1_AAEB0 */
static char lbl_1_data_3C7CC[12] = "F-ZERO GX";
static char lbl_1_data_3C7D8[12] = "./memcard/";
static char lbl_1_data_3C7E4[8] = "sys.bin";
static char lbl_1_data_3C7EC[12] = "sys_e.bin";
static char lbl_1_data_3C7F8[24] = "DVDOpen: cannot open.\n";
static char lbl_1_data_3C810[24] = "avDVDRead: cannot read";

void fn_1_AAEB0(struct fn_1_AAEB0_Arg0 *arg0) {
    OSReport("%1d Wrong Submode.\nresult: %d\nsubmode:%s\n", arg0->unk_0, *(u32 *)(arg0->unk_24 + 4), lbl_1_data_3C58C[arg0->unk_5]);
    OSPanic("memcard.c", 1322, "halt.\n");
}
/* fzgx:end fn_1_AAEB0 */

/* fzgx:begin fn_1_AAF18 */
// fn_1_AAF18: empty in retail (single blr).

void fn_1_AAF18(void) {
}
/* fzgx:end fn_1_AAF18 */

/* fzgx:begin fn_1_AAF1C */
void fn_1_AAF1C(fn_1_AAB98_Entry *obj)
{
switch (obj->unk_24 ->unk_4) {
case -2:
obj->unk_8 = 1;
break;
case -3:
obj->unk_8 = 0;
break;
case -6:
case -5:
obj->unk_8 = 0x20;
break;
case -0xd:
obj->unk_8 = 0x21;
break;
case -8:
switch (obj->unk_24 ->unk_8C->unk_3F) {
case 0x50:
default:
obj->unk_8 = 0x2b;
break;
case 0x4F:
case 0x51:
case 0x52:
case 0x53:
case 0x54:
obj->unk_8 = 0x2a;
break;
}
break;
case -9:
switch (obj->unk_24 ->unk_8C->unk_3F) {
case 0x50:
default:
obj->unk_8 = 0x2d;
break;
case 0x4F:
case 0x51:
case 0x52:
case 0x53:
case 0x54:
obj->unk_8 = 0x2c;
break;
}
break;
case -4:
obj->unk_8 = 0x38;
break;
case -0x7b:
obj->unk_8 = 0x37;
break;
case -0x7c:
obj->unk_8 = 0x36;
break;
case -0x7d:
obj->unk_8 = 0x2f;
break;
case -0x7e:
obj->unk_8 = 0x29;
break;
case -0x7f:
obj->unk_8 = 0x1f;
break;
case -0x77:
if ((*((s16 *)&lbl_1_bss_960)) == 3) {
obj->unk_8 = 0x4d;
} else {
obj->unk_8 = 0x4c;
}
break;
case -0x80:
obj->unk_8 = 2;
break;
case -0x7a:
obj->unk_8 = 3;
break;
default:
OSReport("result: %d\n", obj->unk_24 ->unk_4);
OSPanic("memcard.c", 0x5a3, "Wrong error occured.\n");
break;
}
switch (obj->unk_2) {
case 2:
switch (obj->unk_24->unk_8 & 0xc03) {
case 0x802:
obj->unk_A = 0xf;
break;
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 4;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x15;
break;
default:
obj->unk_A = 4;
break;
}
break;
case 0:
case 1:
switch (obj->unk_24->unk_8 & 0x403) {
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 5;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x16;
break;
default:
obj->unk_A = 5;
break;
}
break;
case 3:
case 4:
switch (obj->unk_24->unk_8 & 0x403) {
case 0x800:
obj->unk_A = 0xf;
break;
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 6;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x17;
break;
default:
obj->unk_A = 6;
break;
}
break;
case 5:
switch (obj->unk_24->unk_8 & 0x403) {
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 7;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x18;
break;
default:
obj->unk_A = 7;
break;
}
break;
case 6:
switch (obj->unk_24->unk_8 & 0x403) {
case 3:
obj->unk_A = 0xe;
break;
case 1:
obj->unk_A = 8;
break;
case 2:
obj->unk_A = 0xe;
break;
case 0x400:
obj->unk_A = 0x19;
break;
default:
obj->unk_A = 8;
break;
}
break;
default:
OSPanic("memcard.c", 0x627, "Please make caption list.\n");
break;
}
obj->unk_2A |= 4;
obj->unk_24->unk_8 &= ~4;
obj->unk_24->unk_2 = 0;
}
/* fzgx:end fn_1_AAF1C */

/* fzgx:begin fn_1_AB434 */
// fn_1_AB434: empty in retail (single blr).

void fn_1_AB434(void) {
}
/* fzgx:end fn_1_AB434 */

/* fzgx:begin fn_1_AB438 */
void fn_1_AB438(Fn1AB438Data *data) {
    data->field_08 = 30;
    data->field_0A = 14;
    data->field_2A |= 4;
}
/* fzgx:end fn_1_AB438 */

/* fzgx:begin fn_1_AB458 */
// fn_1_AB458: empty in retail (single blr).

void fn_1_AB458(void) {
}
/* fzgx:end fn_1_AB458 */

/* fzgx:begin fn_1_AB45C */
void fn_1_AB45C(int index) {
    lbl_1_bss_716C8[index].unk_7 = 1;
}
#undef lbl_1_bss_718B2
/* fzgx:end fn_1_AB45C */

/* fzgx:begin fn_1_AB478 */
/* VIEWS */
void fn_1_AB478(Fn1AB478Obj *obj) {
    obj->unk_C = ((int)fn_1_45D0((u32)lbl_801A6410, 0xA000,
                           (void *)"memcard.c", 0x657));
    obj->unk_24->unk_2 = 0x12c;
    obj->unk_7 = 0;
    CARDMountAsync(obj->unk_0, (void *)obj->unk_C, (CARDCallback)fn_1_AB45C, 0);
}
/* fzgx:end fn_1_AB478 */

/* fzgx:begin fn_1_AB4F4 */
void fn_1_AB4F4(fn_1_AB4F4_ArgStruct *arg) {
    int status;

    status = CARDGetResultCode(arg->byte_0);
    arg->ptr_0x24->field_0x4 = status;
    if (arg->ptr_0x24->field_0x4 == -3 && arg->byte_1 == -2) {
        arg->ptr_0x24->field_0x4 = arg->byte_1;
    }
    if (arg->ptr_0x24->field_0x4 != -1 &&
        CARDGetSerialNo(arg->byte_0, (u64 *)&arg->field_0x98)) {
        arg->field_0x9c = 0;
        arg->field_0x98 = 0;
    }
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_AB4F4 */

/* fzgx:begin fn_1_AB598 */
void fn_1_AB598(fn_1_AB598_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 300;
    CARDCheckAsync(arg->byte_0, 0);
}
/* fzgx:end fn_1_AB598 */

/* fzgx:begin fn_1_AB5CC */
// fn_1_AB5CC: main_rel .text:0x000AB5CC size 0x50

// Load byte from arg, call CARDGetResultCode, store result at struct offset 0x4, clear offset 0x2 if not -1.

void fn_1_AB5CC(fn_1_AB5CC_ArgStruct *arg) {
    u8 byte_val = arg->byte_0;
    int result = CARDGetResultCode(byte_val);

    fn_1_AB5CC_OffsetStruct *s = arg->ptr_0x24;
    s->field_0x4 = result;

    s = arg->ptr_0x24;
    if (s->field_0x4 != -1) {
        s->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_AB5CC */

/* fzgx:begin fn_1_AB61C */
void fn_1_AB61C(fn_1_AB61C_MemcardArg *arg) {
    fn_1_AB61C_MemcardState *state = arg->state;
    state->field_0x1 = 1;
    *(s16 *)((u8 *)arg + 0x8) = -1;
    *(s16 *)((u8 *)arg + 0xa) = -1;
    arg->field_0x2a = arg->field_0x2a & 0xFE;
    arg->field_0x2a = 0;
}
/* fzgx:end fn_1_AB61C */

/* fzgx:begin fn_1_AB64C */
/* fzgx-allow: A1 absolute retail data address */

#define DATA_A9011300 0xA9011300

/* fzgx-allow: A1 absolute retail data address */

#define DATA_A9011100 0xA9011100

void fn_1_AB64C(MemcardArg *arg) {
    MemcardState *state;
    s32 value;

    if ((arg->unk_2A & 1) == 0) {
        state = (MemcardState *)arg->unk_24;
        if ((PAD_BIT(lbl_1_bss_9F8.unk_10, 0) != 0 ||
             PAD_BIT(lbl_1_bss_9F8.unk_12, 0) != 0) &&
            state->unk_1 == 1) {
            fn_1_A2DC4(DATA_A9011300);
            state->unk_1 = 0;
        /* Volatile prevents the compiler from reusing the first status read. */
        } else if ((PAD_BIT(lbl_1_bss_9F8.unk_10, 1) != 0 ||
                    PAD_BIT(lbl_1_bss_9F8.unk_12, 1) != 0) &&
                   state->unk_1 == 0) {
            fn_1_A2DC4(DATA_A9011300);
            state->unk_1 = 1;
        }

        if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8) != 0) {
            fn_1_A2DC4(DATA_A9011100);
            value = 1;
        } else {
            value = 0;
        }
        state = (MemcardState *)arg->unk_24;
        state->unk_4 = value;
        state = (MemcardState *)arg->unk_24;
        if (state->unk_4 == 2) {
            state->unk_1 = 1;
        }
    }
}
/* fzgx:end fn_1_AB64C */

/* fzgx:begin fn_1_AB75C */
// fn_1_AB75C: main_rel .text:0x000AB75C size 0x68

void fn_1_AB75C(fn_1_AB75C_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 0x12c;
    arg->field_0x30 = fn_8002C0A0(arg->byte_0);
    arg->field_0x38 = 0.0f;
    arg->flags_0x2a |= 2;
    CARDFormatAsync(arg->byte_0, 0);
}
/* fzgx:end fn_1_AB75C */

/* fzgx:begin fn_1_AB7C4 */
void fn_1_AB7C4(fn_1_AB7C4_ArgStruct *arg) {
    arg->ptr_0x24->field_0x4 = CARDGetResultCode(arg->byte_0);
    arg->field_0x38 = (fn_8002C0A0(arg->byte_0) - arg->field_0x30) / 40960.0f;
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->flags_0x2a &= ~2;
        arg->ptr_0x24->field_0x2 = 0;
        arg->flags_0x2a &= ~16;
    }
}
/* fzgx:end fn_1_AB7C4 */

/* fzgx:begin fn_1_AB870 */
// fn_1_AB870: main_rel .text:0x000AB870 size 0x10

void fn_1_AB870(fn_1_AB870_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 0x12c;
}
/* fzgx:end fn_1_AB870 */

/* fzgx:begin fn_1_AB880 */
// fn_1_AB880: main_rel .text:0x000AB880 size 0x58

void fn_1_AB880(fn_1_AB5CC_ArgStruct *arg) {
    fn_1_AB5CC_OffsetStruct *s = arg->ptr_0x24;
    int result = CARDGetSerialNo(arg->byte_0, (u64 *)((u8 *)s + 0x18));

    s = arg->ptr_0x24;
    s->field_0x4 = result;

    s = arg->ptr_0x24;
    if (s->field_0x4 != -1) {
        s->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_AB880 */

/* fzgx:begin fn_1_AB8D8 */
void fn_1_AB8D8(fn_1_AB8D8_ArgStruct *arg) {
    u8 data[0x40];

    strcpy(data, (u8 *)arg->ptr_0x24 + 0x98);
    strcat(data, ".000");
    ((u16 *)arg->ptr_0x24)[1] = 0x12c;
    CARDDeleteAsync(arg->byte_0, (const char *)data, 0);
}
/* fzgx:end fn_1_AB8D8 */

/* fzgx:begin fn_1_AB93C */
// fn_1_AB93C: main_rel .text:0x000AB93C size 0x50

void fn_1_AB93C(fn_1_AB5CC_ArgStruct *arg) {
    u8 byte_val = arg->byte_0;
    int result = CARDGetResultCode(byte_val);

    fn_1_AB5CC_OffsetStruct *s = arg->ptr_0x24;
    s->field_0x4 = result;

    s = arg->ptr_0x24;
    if (s->field_0x4 != -1) {
        s->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_AB93C */

/* fzgx:begin fn_1_AB98C */
void fn_1_AB98C(fn_1_AB870_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 300;
}
/* fzgx:end fn_1_AB98C */

/* fzgx:begin fn_1_AB99C */
void fn_1_AB99C(fn_1_AB99C_ArgStruct *arg) {
    s32 result = CARDFreeBlocks(arg->byte_0, (s32 *)arg->ptr_0x24->data,
        (s32 *)&arg->ptr_0x24->data[0x4]);
    arg->ptr_0x24->field_0x4 = result;
    if (arg->ptr_0x24->field_0x4 == 0) {
        arg->ptr_0x24->field_0x8 |= 0x80;
    }
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_AB99C */

/* fzgx:begin fn_1_ABA14 */
void fn_1_ABA14(fn_1_AB870_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 0x12c;
}
/* fzgx:end fn_1_ABA14 */

/* fzgx:begin fn_1_ABA24 */
void fn_1_ABA24(fn_1_AB99C_ArgStruct *arg) {
    s32 result = CARDFreeBlocks(arg->byte_0, (s32 *)arg->ptr_0x24->data,
        (s32 *)&arg->ptr_0x24->data[0x4]);
    arg->ptr_0x24->field_0x4 = result;
    if (arg->ptr_0x24->field_0x4 == 0) {
        arg->ptr_0x24->field_0x8 |= 0x80;
    }
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABA24 */

/* fzgx:begin fn_1_ABA9C */
void fn_1_ABA9C(fn_1_AB870_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 0x12c;
}
/* fzgx:end fn_1_ABA9C */

/* fzgx:begin fn_1_ABAAC */
void fn_1_ABAAC(fn_1_ABAAC_ArgStruct *arg) {
    u8 local[0x40];

    strcpy(local, (u8 *)arg->ptr_0x24 + 0x98);
    strcat(local, ".dat");
    arg->ptr_0x24->field_0x4 =
        CARDOpen(arg->byte_0, (const char *)local, (CARDFileInfo *)arg->data_0x10);
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABAAC */

/* fzgx:begin fn_1_ABB24 */
void fn_1_ABB24(fn_1_ABB24_MemcardArg *arg) {
    arg->ptr_0x24->field_0x1 = 1;
    arg->field_0x8 = -1;
    arg->field_0xa = -1;
    arg->field_0x2a &= 0xfe;
}
#undef DATA_A9011300
#undef DATA_A9011100
/* fzgx:end fn_1_ABB24 */

/* fzgx:begin fn_1_ABB4C */
/* VIEWS */
/* lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 301} */

/* fzgx-allow: A1 absolute retail data address */

/* fzgx-allow: A1 absolute retail data address */

void fn_1_ABB4C(MemcardArg *arg) {
MemcardState *state;
s32 value;
if ((arg->unk_2A & 1) == 0) {
state = (MemcardState *)arg->unk_24;
if (((((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_10 & 1) != 0 ||
(((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_12 & 1) != 0) &&
state->unk_1 == 1) {
fn_1_A2DC4(0xA9011300 );
state->unk_1 = 0;
/* Volatile prevents the compiler from reusing the first status read. */
} else if ((((*((u16 *)&((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_10) >> 1) & 1) != 0 ||
((((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_12 >> 1) & 1) != 0) &&
state->unk_1 == 0) {
fn_1_A2DC4(0xA9011300 );
state->unk_1 = 1;
}
if (((((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_8 >> 8) & 1) != 0) {
fn_1_A2DC4(0xA9011100 );
value = 1;
} else {
value = 0;
}
state = (MemcardState *)arg->unk_24;
state->unk_4 = value;
state = (MemcardState *)arg->unk_24;
if (state->unk_4 == 2) {
state->unk_1 = 1;
}
}
}
/* fzgx:end fn_1_ABB4C */

/* fzgx:begin fn_1_ABC5C */
void fn_1_ABC5C(fn_1_ABC5C_ArgStruct *arg) {
    fn_1_AB870_ArgStruct *state;

    state = (fn_1_AB870_ArgStruct *)arg;
    state->ptr_0x24->field_0x2 = 0x12c;
    CARDFastDeleteAsync(arg->byte_0, (s32)arg->field_0x14, 0);
}
/* fzgx:end fn_1_ABC5C */

/* fzgx:begin fn_1_ABC98 */
void fn_1_ABC98(fn_1_ABC98_ArgStruct *arg) {
    arg->ptr_0x24->field_0x4 = CARDGetResultCode(arg->byte_0);
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABC98 */

/* fzgx:begin fn_1_ABCE8 */
void fn_1_ABCE8(fn_1_ABCE8_ArgStruct *arg) {
    u8 local[0x40];

    strcpy(local, (u8 *)arg->ptr_0x24 + 0x98);
    strcat(local, ".000");
    arg->ptr_0x24->field_0x2 = 0x12c;
    CARDCreateAsync(arg->byte_0, (const char *)local, (u32)arg->ptr_0x24->ptr_0xc,
        (CARDFileInfo *)arg->data_0x10, 0);
}
/* fzgx:end fn_1_ABCE8 */

/* fzgx:begin fn_1_ABD58 */
void fn_1_ABD58(fn_1_ABC98_ArgStruct *arg) {
    arg->ptr_0x24->field_0x4 = CARDGetResultCode(arg->byte_0);
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABD58 */

/* fzgx:begin fn_1_ABDA8 */
void fn_1_ABDA8(fn_1_AB870_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 0x12c;
}
/* fzgx:end fn_1_ABDA8 */

/* fzgx:begin fn_1_ABDB8 */
// Loads the payload into its result buffer and clears the stale offset on success.

void fn_1_ABDB8(fn_1_ABDB8_ArgStruct *arg) {
    arg->ptr_0x24->unk_0x4 =
        CARDGetStatus(arg->byte_0x0, (s32)arg->ptr_0x14, (CARDStat *)arg->ptr_0x24->unk_0x20);
    if (arg->ptr_0x24->unk_0x4 != -1) {
        arg->ptr_0x24->unk_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABDB8 */

/* fzgx:begin fn_1_ABE14 */
void fn_1_ABE14(Fn1ABE14Arg *arg) {
    arg->sub->value = 300;
    arg->result = ((s32)fn_8002C0A0(arg->id));
    arg->value = 0.0f;
    arg->flags |= 2;
    CARDWriteAsync((CARDFileInfo *)((u8 *)arg + 0x10), (const void *)arg->sub->arg_0x94, (s32)arg->sub->arg_0xC, 0, 0);
}
/* fzgx:end fn_1_ABE14 */

/* fzgx:begin fn_1_ABE88 */
/* VIEWS */
void fn_1_ABE88(void *arg0) {
    (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 4)) = CARDGetResultCode(((*(u8 *)(arg0))));
    (*(f32 *)((u8 *)(arg0) + 56)) = (f32) (s32) (fn_8002C0A0(((*(u8 *)(arg0)))) - (*(s32 *)((u8 *)(arg0) + 48))) / (u32) ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 12)) + 0x2000);
    if ((s32) (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 4)) != -1) {
        (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) & 0xFFFFFFFD);
        (*(s16 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 2)) = 0;
    }
}
/* fzgx:end fn_1_ABE88 */

/* fzgx:begin fn_1_ABF44 */
void fn_1_ABF44(Fn1ABF44Object *arg) {
    u8 work[0x40];
    s32 value;
    s32 size;
    s32 aligned;

    arg->state->field_0x2 = 300;
    strcpy(work, (u8 *)arg->state + 0x98);
    strcat(work, ".dat");
    value = CARDOpen(arg->id, (const char *)work, (CARDFileInfo *)arg->data_0x10);
    arg->state->field_0x4 = value;
    arg->value_0x30 = fn_8002C0A0(arg->id);
    arg->value_0x38 = 0.0f;
    arg->flags_0x2a |= 2;
    size = arg->state->field_0x94 +
        *(s32 *)((u8 *)arg->state->field_0x8c + 0x44);
    aligned = (*(s32 *)((u8 *)arg->state->field_0x8c + 0x48) + 0x1fff) &
        ~0x1fff;
    CARDWriteAsync((CARDFileInfo *)arg->data_0x10, (const void *)size, aligned,
                *(s32 *)((u8 *)arg->state->field_0x8c + 0x44), 0);
}
/* fzgx:end fn_1_ABF44 */

/* fzgx:begin fn_1_AC000 */
void fn_1_AC000(Fn1AC000Target *target) {
    f32 numerator;
    f32 denominator;
    f32 ratio;

    target->state->value_0x4 = CARDGetResultCode(target->id);

    ratio = ((target->state->table->value_0x48 + 0x1fff) & ~0x1fff);
    denominator = (((target->state->table->value_0x48 + 0x1fff) & ~0x1fff) + 0x4000);
    ratio = ratio / denominator;

    numerator = (s32)(fn_8002C0A0(target->id) - target->start);
    denominator = (((target->state->table->value_0x48 + 0x1fff) & ~0x1fff) + 0x2000);
    target->ratio = ratio * numerator / denominator;

    if (target->state->value_0x4 != -1 && target->state->value_0x4 != 0) {
        target->flags = target->flags & 0xfffffffd;
        target->state->value_0x2 = 0;
    }
}
/* fzgx:end fn_1_AC000 */

/* fzgx:begin fn_1_AC12C */
// Initializes the request state, records the backing resource, and starts its transfer.

void fn_1_AC12C(fn_1_AC12C_MemcardRequest *request) {
    request->state->value = 300;
    request->result = ((void *)fn_8002C0A0(request->id));
    CARDWriteAsync((CARDFileInfo *)request->buffer, (const void *)request->state->data, 0x4000, 0, 0);
}
/* fzgx:end fn_1_AC12C */

/* fzgx:begin fn_1_AC188 */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
void fn_1_AC188(Fn1AC188Target *target) {
    f32 fraction;
    int rounded;

    rounded = (target->state->config->value + 0x1fff) & ~0x1fff;
    fraction = (u32)rounded;
    fraction = fraction / (u32)(rounded + 0x4000);
    target->state->result = CARDGetResultCode(target->id);
    target->value = fraction + (1.0f - fraction) *
        (s32)(fn_8002C0A0(target->id) - target->start) / 24576.0f;
    if (target->state->result != -1) {
        target->flags = target->flags & ~2;
        target->state->value = 0;
    }
}
/* fzgx:end fn_1_AC188 */

/* fzgx:begin fn_1_AC294 */
void fn_1_AC294(Fn1AC294Target *target) {
    target->state->value = 300;
    CARDSetStatusAsync(target->id, (s32)target->arg, (CARDStat *)((u8 *)target->state + 0x20), 0);
}
/* fzgx:end fn_1_AC294 */

/* fzgx:begin fn_1_AC2D8 */
void fn_1_AC2D8(Fn1AC2D8Target *target) {
    target->state->status = CARDGetResultCode(target->id);
    if (target->state->status != -1) {
        target->state->value = 0;
    }
}
/* fzgx:end fn_1_AC2D8 */

/* fzgx:begin fn_1_AC328 */
void fn_1_AC328(Fn1AC328Target *target) {
    u8 data[0x40];

    strcpy(data, (u8 *)target->state + 0x98);
    strcat(data, ".dat");
    target->state->value = 300;
    CARDDeleteAsync(target->id, (const char *)data, 0);
}
/* fzgx:end fn_1_AC328 */

/* fzgx:begin fn_1_AC38C */
void fn_1_AC38C(Fn1AC38Target *target) {
    target->data->status = CARDGetResultCode(target->id);
    if (target->data->status != -1) {
        target->data->value = 0;
    }
}
/* fzgx:end fn_1_AC38C */

/* fzgx:begin fn_1_AC3DC */
void fn_1_AC3DC(Fn1AC328Target *target) {
    u8 data1[0x40];
    u8 data2[0x40];

    strcpy(data1, (u8 *)target->state + 0x98);
    strcpy(data2, (u8 *)target->state + 0x98);
    strcat(data1, ".000");
    strcat(data2, ".dat");
    target->state->value = 300;
    CARDRenameAsync(target->id, (const char *)data1, (const char *)data2, 0);
}
/* fzgx:end fn_1_AC3DC */

/* fzgx:begin fn_1_AC464 */
void fn_1_AC464(Fn1AC464Target *target) {
    target->state->result = CARDGetResultCode(target->value);
    if (target->state->result != -1) {
        target->state->value = 0;
    }
}
/* fzgx:end fn_1_AC464 */

/* fzgx:begin fn_1_AC4B4 */
void fn_1_AC4B4(Fn1AC4B4Target *target) {
    target->state->value = 300;
}
/* fzgx:end fn_1_AC4B4 */

/* fzgx:begin fn_1_AC4C4 */
void fn_1_AC4C4(Fn1AC4C4Target *target) {
    target->state->result =
        CARDFreeBlocks(target->value, (s32 *)&target->state->data_10, (s32 *)&target->state->data_14);
    if (target->state->result == 0) {
        target->state->flags |= 0x80;
    }
    if (target->state->result != -1) {
        target->state->value_02 = 0;
    }
}
/* fzgx:end fn_1_AC4C4 */

/* fzgx:begin fn_1_AC53C */
void fn_1_AC53C(void *arg0) {
    u32 temp_r4;
    u32 temp_r5_2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r5;
    void *temp_r6;

    if ((*(u32 *)((u8 *)(arg0) + 12)) != 0) {
        do {

        } while (CARDUnmount((s32)((void *)(((*(u8 *)(arg0)))))) == -1);
        fn_1_46B4((*(struct fn_1_AC53C_lbl_801A6410 *)&lbl_801A6410).unk_0, *(u32 *)((u8 *)(arg0) + 12), (const char *)("memcard.c"), 0x3C8);
        (*((u8 *)(arg0) + 7)) = 0;
        (*(u32 *)((u8 *)(arg0) + 12)) = 0U;
        temp_r3 = (*(void **)((u8 *)(arg0) + 36));
        (*(s32 *)((u8 *)(temp_r3) + 28)) = 0;
        (*(s32 *)((u8 *)(temp_r3) + 24)) = 0;
    }
    temp_r3_2 = (*(void **)((u8 *)(arg0) + 36));
    if ((*(s32 *)((u8 *)(temp_r3_2) + 8)) & 0x80) {
        (*(s32 *)((u8 *)(arg0) + 60)) = ((*(s32 *)((u8 *)(temp_r3_2) + 16)) / 8192);
        (*(s32 *)((u8 *)(arg0) + 64)) = (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 20));
    }
    temp_r5 = (*(void **)((u8 *)(arg0) + 36));
    if (!((*(s32 *)((u8 *)(temp_r5) + 8)) & 0x20)) {
        fn_1_46B4((*(struct fn_1_AC53C_lbl_801A6410 *)&lbl_801A6410).unk_0, *(u32 *)((u8 *)(temp_r5) + 148), (const char *)("memcard.c"), 0x3D4);
    }
    if ((*((u8 *)(arg0) + 2)) == 4) {
        if ((*(struct fn_1_AC53C_lbl_1_bss_716C0 *)&lbl_1_bss_716C0).unk_0 != 0) {
            temp_r6 = (*(void **)((u8 *)(arg0) + 36));
            temp_r5_2 = *(u32 *)((u8 *)(temp_r6) + 148);
            (*(u32 *)((u8 *)(temp_r6) + 148)) = (*(u32 *)((u8 *)(temp_r6) + 220));
            (*(u32 *)((u8 *)(temp_r6) + 220)) = temp_r5_2;
            (*(struct fn_1_AC53C_lbl_1_bss_716C0 *)&lbl_1_bss_716C0).unk_0 = 0;
        }
        temp_r4 = *(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 220);
        if (temp_r4 != 0) {
            fn_1_46B4((*(struct fn_1_AC53C_lbl_801A6410 *)&lbl_801A6410).unk_0, temp_r4, (const char *)("memcard.c"), 0x3DE);
            (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 220)) = 0U;
        }
    }
    (*(s16 *)((u8 *)(arg0) + 8)) = 0x30;
    (*(s16 *)((u8 *)(arg0) + 10)) = 0xE;
    (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) | 4);
}
/* fzgx:end fn_1_AC53C */

/* fzgx:begin fn_1_AC6A4 */
// fn_1_AC6A4: empty in retail (single blr).

void fn_1_AC6A4(void) {
}
/* fzgx:end fn_1_AC6A4 */

/* fzgx:begin fn_1_AC6A8 */
void fn_1_AC6A8(Fn1AC6A8Data *data) {
    data->unk8 = 0x33;
    data->unka = 0xe;
    data->unk2a |= 4;
}
/* fzgx:end fn_1_AC6A8 */

/* fzgx:begin fn_1_AC6C8 */
// fn_1_AC6C8: empty in retail (single blr).

void fn_1_AC6C8(void) {
}
/* fzgx:end fn_1_AC6C8 */

/* fzgx:begin fn_1_AC6CC */
void fn_1_AC6CC(fn_1_AC6CC_MemCardState *self) {
    self->flags |= 4;
}
/* fzgx:end fn_1_AC6CC */

/* fzgx:begin fn_1_AC6DC */
// fn_1_AC6DC: empty in retail (single blr).

void fn_1_AC6DC(void) {
}
/* fzgx:end fn_1_AC6DC */

/* fzgx:begin fn_1_AC6E0 */
// fn_1_AC6E0: Write struct fields at offsets 0x8, 0xa, and 0x2a (with OR).

void fn_1_AC6E0(void *r3) {
    *(u16 *)((u8 *)r3 + 0x8) = 0x34;
    *(u16 *)((u8 *)r3 + 0xa) = 0xe;
    *(((u8 *)r3) + 0x2a) |= 0x4;
}
/* fzgx:end fn_1_AC6E0 */

/* fzgx:begin fn_1_AC700 */
// fn_1_AC700: empty in retail (single blr).

void fn_1_AC700(void) {
}
/* fzgx:end fn_1_AC700 */

/* fzgx:begin fn_1_AC704 */
void fn_1_AC704(void *r3) {
    *(u16 *)((u8 *)*(void **)((u8 *)r3 + 0x24) + 0x2) = 0x12c;
    CARDReadAsync((CARDFileInfo *)((u8 *)r3 + 0x10),
                (void *)(*(void **)((u8 *)*(void **)((u8 *)r3 + 0x24) + 0x94)),
                *(s32 *)((u8 *)*(void **)((u8 *)r3 + 0x24) + 0xc),
                0,
                0);
}
/* fzgx:end fn_1_AC704 */

/* fzgx:begin fn_1_AC74C */
void fn_1_AC74C(void *r3) {
    s32 result;

    result = CARDGetResultCode(*(u8 *)r3);
    *(s32 *)((u8 *)*(void **)((u8 *)r3 + 0x24) + 0x4) = result;
    if (*(s32 *)((u8 *)*(void **)((u8 *)r3 + 0x24) + 0x4) != -1) {
        *(u16 *)((u8 *)*(void **)((u8 *)r3 + 0x24) + 0x2) = 0;
    }
}
/* fzgx:end fn_1_AC74C */

/* fzgx:begin fn_1_AC79C */
void fn_1_AC79C(void *arg0) {
    u32 temp_r4;
    u32 temp_r5_2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r5;
    void *temp_r6;

    if ((*(u32 *)((u8 *)(arg0) + 12)) != 0) {
        do {

        } while (CARDUnmount((s32)((void *)(((*(u8 *)(arg0)))))) == -1);
        fn_1_46B4((*(struct fn_1_AC79C_lbl_801A6410 *)&lbl_801A6410).unk_0, *(u32 *)((u8 *)(arg0) + 12), (const char *)("memcard.c"), 0x3C8);
        (*((u8 *)(arg0) + 7)) = 0;
        (*(u32 *)((u8 *)(arg0) + 12)) = 0U;
        temp_r3 = (*(void **)((u8 *)(arg0) + 36));
        (*(s32 *)((u8 *)(temp_r3) + 28)) = 0;
        (*(s32 *)((u8 *)(temp_r3) + 24)) = 0;
    }
    temp_r3_2 = (*(void **)((u8 *)(arg0) + 36));
    if ((*(s32 *)((u8 *)(temp_r3_2) + 8)) & 0x80) {
        (*(s32 *)((u8 *)(arg0) + 60)) = ((*(s32 *)((u8 *)(temp_r3_2) + 16)) / 8192);
        (*(s32 *)((u8 *)(arg0) + 64)) = (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 20));
    }
    temp_r5 = (*(void **)((u8 *)(arg0) + 36));
    if (!((*(s32 *)((u8 *)(temp_r5) + 8)) & 0x20)) {
        fn_1_46B4((*(struct fn_1_AC79C_lbl_801A6410 *)&lbl_801A6410).unk_0, *(u32 *)((u8 *)(temp_r5) + 148), (const char *)("memcard.c"), 0x3D4);
    }
    if ((*((u8 *)(arg0) + 2)) == 4) {
        if ((*(struct fn_1_AC79C_lbl_1_bss_716C0 *)&lbl_1_bss_716C0).unk_0 != 0) {
            temp_r6 = (*(void **)((u8 *)(arg0) + 36));
            temp_r5_2 = *(u32 *)((u8 *)(temp_r6) + 148);
            (*(u32 *)((u8 *)(temp_r6) + 148)) = (*(u32 *)((u8 *)(temp_r6) + 220));
            (*(u32 *)((u8 *)(temp_r6) + 220)) = temp_r5_2;
            (*(struct fn_1_AC79C_lbl_1_bss_716C0 *)&lbl_1_bss_716C0).unk_0 = 0;
        }
        temp_r4 = *(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 220);
        if (temp_r4 != 0) {
            fn_1_46B4((*(struct fn_1_AC79C_lbl_801A6410 *)&lbl_801A6410).unk_0, temp_r4, (const char *)("memcard.c"), 0x3DE);
            (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 220)) = 0U;
        }
    }
    (*(s16 *)((u8 *)(arg0) + 8)) = 0x35;
    (*(s16 *)((u8 *)(arg0) + 10)) = 0xE;
    (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) | 4);
}
/* fzgx:end fn_1_AC79C */

/* fzgx:begin fn_1_AC904 */
// fn_1_AC904: empty in retail (single blr).

void fn_1_AC904(void) {
}
/* fzgx:end fn_1_AC904 */

/* fzgx:begin fn_1_AC908 */
void fn_1_AC908(Fn1AC908State *state) {
    state->field8 = 0x3c;
    state->fieldA = 0xe;
    state->flags |= 4;
}
/* fzgx:end fn_1_AC908 */

/* fzgx:begin fn_1_AC928 */
// fn_1_AC928: empty in retail (single blr).

void fn_1_AC928(void) {
}
/* fzgx:end fn_1_AC928 */

/* fzgx:begin fn_1_AC92C */
u32 fn_1_AC92C(struct fn_1_AC92C_Arg0 *arg0) {
    u32 v0;
    arg0->unk_2C = 0;
    arg0->unk_2D = 0;
    arg0->unk_38 = 0.0f;
    arg0->unk_2A = (arg0->unk_2A | 2);
    v0 = arg0->unk_24;
    *(u16 *)((u8 *)v0 + 2) = 300;
    return v0;
}
/* fzgx:end fn_1_AC92C */

/* fzgx:begin fn_1_AC960 */
void fn_1_AC960(struct MemcardObject *obj) {
    s32 result;

    result = CARDGetStatus(obj->id, obj->state,
                          (CARDStat *)(((u8 *)obj->data + 0x20)));
    obj->data->result = result;
    obj->progress = (obj->state / 126.0);
    if (obj->state == 0x7e) {
        obj->flags = obj->flags & 0xfffffffd;
        obj->data->status = 0;
    }
}
#undef lbl_1_bss_716C0
/* fzgx:end fn_1_AC960 */

/* fzgx:begin fn_1_ACA00 */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
void fn_1_ACA00(Fn1Aca00Target *self) {
    self->flag_2c = 0;
    self->flag_2d = 0;
    self->child->value = 300;
}
/* fzgx:end fn_1_ACA00 */

/* fzgx:begin fn_1_ACA1C */
void fn_1_ACA1C(fn_1_ACA1C_MemCardState *state) {
    state->data->value = CARDGetStatus(state->id, state->slot,
        (CARDStat *)((u8 *)state->data + 0x20));
    if (state->slot == 0x7e) {
        *(u16 *)((u8 *)state->data + 2) = 0;
    }
}
/* fzgx:end fn_1_ACA1C */

/* fzgx:begin fn_1_ACA78 */
void fn_1_ACA78(void *arg0) {
    s32 var_r30;
    u32 temp_r4;
    u32 temp_r5_2;
    u32 var_r3;
    u8 temp_r0;
    u8 temp_r0_2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r5;
    void *temp_r6;

    if ((*(u32 *)((u8 *)(arg0) + 12)) != 0) {
        do {

        } while (CARDUnmount((*(u8 *)(arg0))) == -1);
        fn_1_46B4((*(struct fn_1_ACA78_lbl_801A6410 *)&lbl_801A6410).unk_0, *(u32 *)((u8 *)(arg0) + 12), (const char *)("memcard.c"), 0x3C8);
        (*((u8 *)(arg0) + 7)) = 0;
        (*(u32 *)((u8 *)(arg0) + 12)) = 0U;
        temp_r3 = (*(void **)((u8 *)(arg0) + 36));
        (*(s32 *)((u8 *)(temp_r3) + 28)) = 0;
        (*(s32 *)((u8 *)(temp_r3) + 24)) = 0;
    }
    temp_r3_2 = (*(void **)((u8 *)(arg0) + 36));
    if ((*(s32 *)((u8 *)(temp_r3_2) + 8)) & 0x80) {
        (*(s32 *)((u8 *)(arg0) + 60)) = ((*(s32 *)((u8 *)(temp_r3_2) + 16)) / 8192);
        (*(s32 *)((u8 *)(arg0) + 64)) = (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 20));
    }
    temp_r5 = (*(void **)((u8 *)(arg0) + 36));
    if (!((*(s32 *)((u8 *)(temp_r5) + 8)) & 0x20)) {
        fn_1_46B4((*(struct fn_1_ACA78_lbl_801A6410 *)&lbl_801A6410).unk_0, *(u32 *)((u8 *)(temp_r5) + 148), (const char *)("memcard.c"), 0x3D4);
    }
    if ((*((u8 *)(arg0) + 2)) == 4) {
        if ((*(struct fn_1_ACA78_lbl_1_bss_716C0 *)&lbl_1_bss_716C0).unk_0 != 0) {
            temp_r6 = (*(void **)((u8 *)(arg0) + 36));
            temp_r5_2 = *(u32 *)((u8 *)(temp_r6) + 148);
            (*(u32 *)((u8 *)(temp_r6) + 148)) = (*(u32 *)((u8 *)(temp_r6) + 220));
            (*(u32 *)((u8 *)(temp_r6) + 220)) = temp_r5_2;
            (*(struct fn_1_ACA78_lbl_1_bss_716C0 *)&lbl_1_bss_716C0).unk_0 = 0;
        }
        temp_r4 = *(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 220);
        if (temp_r4 != 0) {
            fn_1_46B4((*(struct fn_1_ACA78_lbl_801A6410 *)&lbl_801A6410).unk_0, temp_r4, (const char *)("memcard.c"), 0x3DE);
            (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 220)) = 0U;
        }
    }
    var_r30 = 0;
    temp_r0 = *((u8 *)(arg0) + 45);
    var_r3 = *(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 148);
    {
        s32 n = temp_r0;
        s32 i;
        for (i = 0; i < n; i++) {
            if ((*(u8 *)(var_r3)) == 0) {
                var_r30 += 1;
            }
            var_r3 += 0x30;
        }
    }
    if (fn_1_B7EF8() != 0) {
        temp_r3_3 = (*(void **)((u8 *)(arg0) + 36));
        (*(s32 *)((u8 *)(temp_r3_3) + 8)) = ((*(s32 *)((u8 *)(temp_r3_3) + 8)) & 0xFFFFFFFB);
        if (var_r30 == 0) {
            if ((*(s16 *)(&lbl_1_bss_960)) == 1) {
                (*(s16 *)((u8 *)(arg0) + 8)) = 0x63;
            } else {
                (*(s16 *)((u8 *)(arg0) + 8)) = 0x61;
            }
        } else if ((*(s16 *)(&lbl_1_bss_960)) == 1) {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x64;
        } else {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x62;
        }
    } else {
        temp_r3_4 = (*(void **)((u8 *)(arg0) + 36));
        (*(s32 *)((u8 *)(temp_r3_4) + 8)) = ((*(s32 *)((u8 *)(temp_r3_4) + 8)) | 4);
        if (var_r30 == 0) {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x3D;
        } else {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x3E;
        }
    }
    if ((*(s16 *)((u8 *)(arg0) + 8)) == 0x3D) {
        temp_r0_2 = *(u8 *)(((*(void **)((u8 *)(arg0) + 36))));
        if (temp_r0_2 == 5) {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x39;
        } else if (temp_r0_2 == 2) {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x3A;
        } else if (temp_r0_2 == 4) {
            (*(s16 *)((u8 *)(arg0) + 8)) = 0x3B;
        }
    }
    (*(s16 *)((u8 *)(arg0) + 10)) = 0xE;
    (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) | 4);
}
/* fzgx:end fn_1_ACA78 */

/* fzgx:begin fn_1_ACD00 */
// fn_1_ACD00: empty in retail (single blr).

void fn_1_ACD00(void) {
}
#undef lbl_1_bss_716C0
/* fzgx:end fn_1_ACD00 */

/* fzgx:begin fn_1_ACD04 */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
// Reset completed card work and mark the operation ready for its next state.

void fn_1_ACD04(Fn1Acd04Obj *obj) {
    int result;

    if (obj->unk_c != 0) {
        do {
            result = CARDUnmount(obj->unk_0);
        } while (result == -1);

        fn_1_46B4(lbl_801A6410, obj->unk_c, "memcard.c", 0x3c8);
        obj->unk_7 = 0;
        obj->unk_c = 0;

        {
            Fn1Acd04Inner *card_state = obj->unk_24;

            card_state->unk_1c = 0;
            card_state->unk_18 = 0;
        }
    }

    if ((obj->unk_24->unk_8 & 0x80) != 0) {
        obj->unk_3c = obj->unk_24->unk_10 / 8192;
        obj->unk_40 = obj->unk_24->unk_14;
    }

    if ((obj->unk_24->unk_8 & 0x20) == 0) {
        fn_1_46B4(lbl_801A6410, obj->unk_24->unk_94,
                  "memcard.c", 0x3d4);
    }

    if (obj->unk_2 == 4) {
        if (lbl_1_bss_716C0 != 0) {
            void *previous_buffer;
            Fn1Acd04Inner *card_state;

            card_state = obj->unk_24;
            previous_buffer = card_state->unk_94;
            card_state->unk_94 = card_state->unk_dc;
            card_state->unk_dc = previous_buffer;
            lbl_1_bss_716C0 = 0;
        }

        if (obj->unk_24->unk_dc != 0) {
            fn_1_46B4(lbl_801A6410, obj->unk_24->unk_dc,
                      "memcard.c", 0x3de);
            obj->unk_24->unk_dc = 0;
        }
    }

    obj->unk_8 = 0x3f;
    obj->unk_a = 0xe;
    obj->unk_2a |= 4;
    obj->unk_24->unk_8 |= 4;
}
/* fzgx:end fn_1_ACD04 */

/* fzgx:begin fn_1_ACE7C */
// fn_1_ACE7C: empty in retail (single blr).

void fn_1_ACE7C(void) {
}
/* fzgx:end fn_1_ACE7C */

/* fzgx:begin fn_1_ACE80 */
// fn_1_ACE80: writes 0x12c to pointed structure, then calls CARDDeleteAsync

void fn_1_ACE80(fn_1_ACE80_SomeObject* obj) {
    *(u16*)((u8*)obj->field_24 + 0x2) = 0x12c;
    CARDDeleteAsync(obj->field_0, (const char *)((u8*)obj->field_24 + 0x98), 0);
}
/* fzgx:end fn_1_ACE80 */

/* fzgx:begin fn_1_ACEBC */
void fn_1_ACEBC(fn_1_ACE80_SomeObject* obj) {
    s32 value;
    value = CARDGetResultCode(obj->field_0);
    *(s32*)((u8*)obj->field_24 + 0x4) = value;
    if (*(s32*)((u8*)obj->field_24 + 0x4) != -1) {
        *(u16*)((u8*)obj->field_24 + 0x2) = 0;
    }
}
/* fzgx:end fn_1_ACEBC */

/* fzgx:begin fn_1_ACF0C */
void fn_1_ACF0C(Object* obj) {
    obj->field_8 = 0x40;
    obj->field_A = 0xE;
    obj->flags_2A |= 0x4;
}
/* fzgx:end fn_1_ACF0C */

/* fzgx:begin fn_1_ACF2C */
// fn_1_ACF2C: empty in retail (single blr).

void fn_1_ACF2C(void) {
}
/* fzgx:end fn_1_ACF2C */

/* fzgx:begin fn_1_ACF30 */
// Cleans up pending card data, updates state values, and marks the object ready.

void fn_1_ACF30(MemcardObject_ACD04* obj) {
    if (obj->card != 0) {
        do {
            if (CARDUnmount(obj->id) != -1) {
                fn_1_46B4(lbl_801A6410, obj->card, "memcard.c", 0x3C8);
                obj->ready = 0;
                obj->card = 0;
                {
                    MemcardState_ACD04* state = obj->sub;
                    state->field_1C = 0;
                    state->field_18 = 0;
                }
                break;
            }
        } while (1);
    }

    if ((obj->sub->flags_8 & 0x80) != 0) {
        obj->value_3C = obj->sub->value_10 / 0x2000;
        obj->value_40 = obj->sub->value_14;
    }
    if ((obj->sub->flags_8 & 0x20) == 0) {
        fn_1_46B4(lbl_801A6410, obj->sub->value_94, "memcard.c", 0x3D4);
    }
    if (obj->type == 4) {
        if (lbl_1_bss_716C0 != 0) {
            void* temp;
            MemcardState_ACD04* state;
            state = obj->sub;
            temp = state->value_94;
            state->value_94 = state->value_DC;
            state->value_DC = temp;
            lbl_1_bss_716C0 = 0;
        }
        if (obj->sub->value_DC != 0) {
            fn_1_46B4(lbl_801A6410, obj->sub->value_DC, "memcard.c", 0x3DE);
            obj->sub->value_DC = 0;
        }
    }
    obj->field_8 = 0x41;
    obj->field_A = 0xE;
    obj->flags_2A |= 0x4;
}
/* fzgx:end fn_1_ACF30 */

/* fzgx:begin fn_1_AD098 */
// fn_1_AD098: empty in retail (single blr).

void fn_1_AD098(void) {
}
/* fzgx:end fn_1_AD098 */

/* fzgx:begin fn_1_AD09C */
// fn_1_AD09C: empty in retail (single blr).

void fn_1_AD09C(void) {
}
#undef lbl_1_bss_716C0
/* fzgx:end fn_1_AD09C */

/* fzgx:begin fn_1_AD0A0 */
void fn_1_AD0A0(void *arg0) {
    u8 temp_r4;

    temp_r4 = *((u8 *)(arg0) + 44);
    if (temp_r4 < 0x7FU) {
        (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 4)) = CARDGetStatus((*(u8 *)(arg0)), temp_r4, (CARDStat *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 0x20));
    }
    (*(f32 *)((u8 *)(arg0) + 56)) = ((*((u8 *)(arg0) + 44)) / 126.0f);
    if ((*((u8 *)(arg0) + 44)) == 0x7E) {
        (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) & 0xFFFFFFFD);
        (*(s16 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 2)) = 0;
    }
}
/* fzgx:end fn_1_AD0A0 */

/* fzgx:begin fn_1_AD140 */
// Dispatches the memory-card status byte to the shared status handler.

void fn_1_AD140(const u8 *status_byte) {
    fn_1_B7FDC(*status_byte);
}
/* fzgx:end fn_1_AD140 */

/* fzgx:begin fn_1_AD164 */
// fn_1_AD164: empty in retail (single blr).

void fn_1_AD164(void) {
}
/* fzgx:end fn_1_AD164 */

/* fzgx:begin fn_1_AD168 */
void fn_1_AD168(Fn1AD168Obj *obj) {
    if (obj->field24[0] == 1) {
        fn_80030754(obj->field0, obj->field14, 0x1c, 0);
    }
}
/* fzgx:end fn_1_AD168 */

/* fzgx:begin fn_1_AD1AC */
// Store the generated value in the object's output record.

void fn_1_AD1AC(Fn1AD1ACObject *object) {
    object->unk_24->unk_04 = ((void *)CARDGetResultCode(object->unk_00));
}
/* fzgx:end fn_1_AD1AC */

/* fzgx:begin fn_1_AD1E4 */
// Copy pending data when the object is not already marked, then advance its state.

void fn_1_AD1E4(Fn1AD1E4State *state, Fn1AD1E4Object *object) {
    if ((object->unk_24->unk_08 & 0x20) == 0) {
        if (state->unk_08 != 0) {
            strncpy((u8 *)object->unk_24->unk_94 + 0x24,
                        state->unk_08, 0x20);
        }
        fn_80008BA8((u8 *)object->unk_24->unk_94 + 0x2060,
                    state->unk_0C, (u32)object->unk_24->unk_B8);
    }
    object->unk_03 = 3;
}
/* fzgx:end fn_1_AD1E4 */

/* fzgx:begin fn_1_AD264 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(CardTask (*)[2])&lbl_1_bss_716C8)
#define lbl_1_bss_718B4 (*(u32 *)&lbl_1_bss_718B4)
#define lbl_1_bss_718E0 (*(GhostRegs *)&lbl_1_bss_718E0)
#define lbl_1_bss_772C8 (*(u8 *)&lbl_1_bss_772C8)
#define lbl_1_bss_7730A (*(u8 *)&lbl_1_bss_7730A)
/* VIEWS */
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)
#define lbl_1_bss_9F8 (*(CardSlotInfo *)&lbl_1_bss_9F8)
#define lbl_801A6410 (*(MgrRoot *)&lbl_801A6410)
void fn_1_AD264(CardTask *a)
{
    s32 wait;
    s8 timer;
    char path1[0x40];
    Sig_DVDOpen_DVDFileInfo info1;
    char path2[0x40];
    Sig_DVDOpen_DVDFileInfo info2;
    char path3[0x40];
    Sig_DVDOpen_DVDFileInfo info3;
    char path4[0x40];
    Sig_DVDOpen_DVDFileInfo info4;
    char path5[0x40];
    Sig_DVDOpen_DVDFileInfo info5;

    if (a->unk_04 == 0xFF) {
        return;
    }

    switch (a->unk_04) {
    default:
        OSReport(("submode    : %d\n"), a->unk_04);
        OSReport(("submode req: %d\n"), a->unk_03);
        OSPanic(("memcard.c"), 2653, ("submode error!!\n"));
        break;

    case 1: {
        a->unk_24->unk_08 &= ~0x200;
        if (a->unk_24->unk_08 & 0x8000) {
            a->unk_03 = 2;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8) && (a->unk_24->unk_08 & 0x800)) {
            a->unk_03 = 12;
            a->unk_24->unk_08 &= ~0x800;
            a->unk_24->unk_08 &= ~2;
            a->unk_24->unk_08 |= 0x200;
            a->unk_2A &= ~4;
            a->unk_08 = -1;
            a->unk_0A = -1;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            a->unk_03 = 2;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 11) && !((*(CardMgr **)&a->unk_24)->unk_08 & 2)) {
            if (a->unk_0C != 0) {
                while (CARDUnmount(a->unk_00) == -1) {
                }
                fn_1_46B4(lbl_801A6410.unk_0, (u32)a->unk_0C, ("memcard.c"), 2681);
                a->unk_07 = 0;
                a->unk_0C = 0;
                {
                    CardMgr *mgr = a->unk_24;
                    mgr->unk_18 = 0;
                }
            }
            a->unk_03 = 3;
            a->unk_08 = -1;
            a->unk_0A = -1;
            a->unk_2A &= ~4;
            if (a->unk_24->unk_00 == 1) {
                s16 mode = lbl_1_bss_960;
                if (mode != 10 && mode != 3 && mode != 1) {
                    a->unk_24->unk_08 |= 0x2000;
                    a->unk_24->unk_08 |= 4;
                    lbl_1_bss_718B1 = 0;
                } else {
                    if (mode != 1) {
                        a->unk_24->unk_08 &= ~0x4000;
                        a->unk_24->unk_08 &= ~4;
                    } else {
                        a->unk_24->unk_08 |= 0x4000;
                        a->unk_24->unk_08 |= 4;
                    }
                    a->unk_24->unk_08 &= ~0x2000;
                    lbl_1_bss_718B1 = 0;
                }
            } else {
                CardTask *base = &lbl_1_bss_716C8[0];

                if (a == base) {
                    lbl_1_bss_718B1 = 0;
                } else if (a == base + 1) {
                    lbl_1_bss_718B1 = 1;
                }
            }
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 10) && (a->unk_24->unk_08 & 0x400)) {
            a->unk_03 = 5;
            a->unk_24->unk_08 &= ~0x400;
            a->unk_24->unk_08 |= 0x200;
            a->unk_2A &= ~4;
            a->unk_2A |= 0x10;
        }
        lbl_1_bss_77309 = 0;
        break;
    }

    case 2:
        if (a->unk_24->unk_08 & 0x8000) {
            a->unk_02 = 0xFE;
            break;
        }
        if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            a->unk_02 = 0xFE;
        }
        break;

    case 3:
        if ((s8)a->unk_01 == -127) {
            a->unk_24->unk_04 = (s8)a->unk_01;
            a->unk_03 = 1;
            break;
        }
        switch (a->unk_24->unk_04) {
        case -128:
        case -5:
        case -3:
        case -2:
            a->unk_03 = 1;
            a->unk_06 = 3;
            break;
        case -13:
            if (a->unk_24->unk_08 & 0x8000) {
                a->unk_2A |= 4;
                a->unk_02 = 0xFE;
                break;
            }
            if (lbl_801A66B4 == 5) {
                a->unk_03 = 5;
                break;
            }
            a->unk_24->unk_08 |= 0x400;
            a->unk_03 = 1;
            break;
        case -6:
        case 0:
            a->unk_03 = 4;
            break;
        case -1:
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 38:
        a->unk_03 = 3;
        break;

    case 4:
        switch (a->unk_24->unk_04) {
        case -128:
        case -5:
        case -3:
            a->unk_03 = 1;
            break;
        case -6:
            if (a->unk_24->unk_08 & 0x8000) {
                a->unk_2A |= 4;
                a->unk_02 = 0xFE;
                break;
            }
            a->unk_03 = 5;
            break;
        case -13:
            if (a->unk_24->unk_08 & 0x8000) {
                a->unk_2A |= 4;
                a->unk_02 = 0xFE;
                break;
            }
            if (lbl_801A66B4 == 5) {
                a->unk_03 = 5;
                break;
            }
            a->unk_24->unk_08 |= 0x400;
            a->unk_03 = 1;
            break;
        case 0:
            a->unk_03 = 7;
            break;
        case -1:
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 5:
        if (a->unk_24->unk_04 == 0) {
            break;
        }
        if (!(a->unk_2A & 1)) {
            a->unk_28 = 12;
            a->unk_2A |= 1;
            wait = 0;
        } else {
            timer = a->unk_28;
            if (timer > 0) {
                a->unk_28 = timer - 1;
                wait = 0;
            } else {
                wait = 1;
            }
        }
        if (wait == 0) {
            break;
        }
        if (a->unk_24->unk_04 == 2 || a->unk_24->unk_01 == 1) {
            a->unk_24->unk_04 = -126;
            a->unk_03 = 1;
            break;
        }
        a->unk_03 = 6;
        a->unk_24->unk_08 |= 0x200;
        break;

    case 6:
        switch (a->unk_24->unk_04) {
        case -128:
        case -5:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 7;
            a->unk_24->unk_08 &= ~0x200;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 7: {
        CardMgr *m = a->unk_24;
        switch (m->unk_04) {
        case -128:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            if (m->unk_00 == 1) {
                u8 *buf;
                if (a->unk_24->unk_08 & 0x10000) {
                    buf = m->unk_94;
                    *(u16 *)(buf + 0x2200) = m->unk_18;
                    m = (*(CardMgr * *)&a->unk_24);
                    *(u16 *)(buf + 0x7580) = m->unk_18 >> 16;
                    m = (*(CardMgr * *)&a->unk_24);
                    *(u16 *)(buf + 0x2060) = m->unk_18 >> 32;
                    m = a->unk_24;
                    *(u16 *)(buf + 0x2066) = m->unk_18 >> 48;
                    lbl_1_bss_718E0.unk_1A0 = *(u16 *)(buf + 0x2200);
                    lbl_1_bss_718E0.unk_5520 = *(u16 *)(buf + 0x7580);
                    lbl_1_bss_718E0.unk_0 = *(u16 *)(buf + 0x2060);
                    lbl_1_bss_718E0.unk_6 = *(u16 *)(buf + 0x2066);
                    a->unk_50 = 1;
                    a->unk_48 = a->unk_24->unk_18;
                    lbl_1_bss_7730A = a->unk_00;
                }
                if (a->unk_50 != 0) {
                    CardMgr *m = a->unk_24;
                    if (a->unk_48 == m->unk_18) {
                        a->unk_03 = 8;
                    } else {
                        m->unk_04 = -119;
                        a->unk_03 = 1;
                    }
                } else {
                    a->unk_24->unk_04 = -119;
                    a->unk_03 = 1;
                }
            } else {
                a->unk_03 = 8;
            }
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;
    }

    case 8:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -10:
        case -3:
            a->unk_03 = 1;
            break;
        case -4:
        case 0:
            a->unk_03 = 9;
            break;
        case -1:
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 9:
        switch (a->unk_24->unk_04) {
        case -128:
        case -6:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            if (a->unk_24->unk_08 & 0x1000) {
                char *tmp;
                u8 *p98;
                u8 *pBC;
                pBC = a->unk_24->unk_BC;
                p98 = a->unk_24->unk_98;
                tmp = fn_1_45D0(lbl_801A6410.unk_0, 0x20, (void *)((u32)("memcard.c")), 499);
                strncpy((void *)tmp, (void *)((const char *)p98), 0x20);
                strncpy((void *)((char *)p98), (void *)((const char *)pBC), 0x20);
                strncpy((void *)((char *)pBC), (void *)tmp, 0x20);
                fn_1_46B4(lbl_801A6410.unk_0, (u32)tmp, ("memcard.c"), 503);
            }
            a->unk_03 = 10;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 10:
        switch (a->unk_24->unk_04) {
        case -128:
        case -10:
        case -6:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case -4:
            if (a->unk_24->unk_14 == 0) {
                a->unk_24->unk_04 = -8;
                a->unk_03 = 1;
                break;
            }
            if (a->unk_24->unk_10 < a->unk_24->unk_0C) {
                a->unk_24->unk_04 = -9;
                a->unk_03 = 1;
                break;
            }
            a->unk_03 = 13;
            {
                GhostFileNode *node = a->unk_24->unk_8C;
                a->unk_24->unk_94[2] = a->unk_24->unk_00;
                a->unk_24->unk_94[3] = node->unk_3E;
                strncpy((void *)((char *)a->unk_24->unk_94 + 4), (void *)((lbl_1_data_3C7CC)), 0x20);
                strcpy((void *)((u32)path1), (void *)((u32)(lbl_1_data_3C7D8)));
                if (lbl_801A66B4 != 5 && strcmp(node->unk_20, (lbl_1_data_3C7E4)) == 0) {
                    strcat((void *)path1, (void *)((lbl_1_data_3C7EC)));
                } else {
                    strcat((void *)path1, (void *)node->unk_20);
                }
                if (!DVDOpen(path1, &info1)) {
                    OSPanic(("memcard.c"), 1290, (lbl_1_data_3C7F8));
                }
                if (a->unk_24->unk_08 & 0x20) {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info1), a->unk_24->unk_94 + 0x1860, 0x800, 0x1800) == 0) {
                        OSPanic(("memcard.c"), 1295, (lbl_1_data_3C810));
                    }
                } else {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info1), a->unk_24->unk_94 + 0x60, 0x2000, 0) == 0) {
                        OSPanic(("memcard.c"), 1299, (lbl_1_data_3C810));
                    }
                }
                DVDClose((u32)&info1);
                a->unk_24->unk_08 |= 0x200;
            }
            break;
        case 0:
            if ((a->unk_24->unk_08 & 4) || (a->unk_24->unk_08 & 0x4000)) {
                if (a->unk_24->unk_10 < a->unk_24->unk_0C || a->unk_24->unk_14 == 0) {
                    a->unk_03 = 12;
                    break;
                }
                a->unk_03 = 13;
                {
                    GhostFileNode *node = a->unk_24->unk_8C;
                    a->unk_24->unk_94[2] = a->unk_24->unk_00;
                    a->unk_24->unk_94[3] = node->unk_3E;
                    strncpy((void *)((char *)a->unk_24->unk_94 + 4), (void *)((lbl_1_data_3C7CC)), 0x20);
                    strcpy((void *)((u32)path2), (void *)((u32)(lbl_1_data_3C7D8)));
                    if (lbl_801A66B4 != 5 && strcmp(node->unk_20, (lbl_1_data_3C7E4)) == 0) {
                        strcat((void *)path2, (void *)((lbl_1_data_3C7EC)));
                    } else {
                        strcat((void *)path2, (void *)node->unk_20);
                    }
                    if (!DVDOpen(path2, &info2)) {
                        OSPanic(("memcard.c"), 1290, (lbl_1_data_3C7F8));
                    }
                    if (a->unk_24->unk_08 & 0x20) {
                        if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info2), a->unk_24->unk_94 + 0x1860, 0x800, 0x1800) == 0) {
                            OSPanic(("memcard.c"), 1295, (lbl_1_data_3C810));
                        }
                    } else {
                        if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info2), a->unk_24->unk_94 + 0x60, 0x2000, 0) == 0) {
                            OSPanic(("memcard.c"), 1299, (lbl_1_data_3C810));
                        }
                    }
                    DVDClose((u32)&info2);
                    a->unk_24->unk_08 |= 0x200;
                }
                break;
            }
            a->unk_03 = 11;
            break;
        case -5:
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 11:
        if (a->unk_24->unk_04 == 0) {
            break;
        }
        if (!(a->unk_2A & 1)) {
            a->unk_28 = 12;
            a->unk_2A |= 1;
            wait = 0;
        } else {
            timer = a->unk_28;
            if (timer > 0) {
                a->unk_28 = timer - 1;
                wait = 0;
            } else {
                wait = 1;
            }
        }
        if (wait == 0) {
            break;
        }
        if (a->unk_24->unk_04 == 2 || a->unk_24->unk_01 == 1) {
            a->unk_24->unk_04 = -125;
            a->unk_03 = 1;
            break;
        }
        if (a->unk_24->unk_10 < a->unk_24->unk_0C || a->unk_24->unk_14 == 0) {
            a->unk_03 = 12;
            break;
        }
        if (a->unk_24->unk_08 & 0x1000) {
            a->unk_03 = 13;
            {
                GhostFileNode *node = a->unk_24->unk_8C;
                a->unk_24->unk_94[2] = a->unk_24->unk_00;
                a->unk_24->unk_94[3] = node->unk_3E;
                strncpy((void *)((char *)a->unk_24->unk_94 + 4), (void *)((lbl_1_data_3C7CC)), 0x20);
                strcpy((void *)((u32)path3), (void *)((u32)(lbl_1_data_3C7D8)));
                if (lbl_801A66B4 != 5 && strcmp(node->unk_20, (lbl_1_data_3C7E4)) == 0) {
                    strcat((void *)path3, (void *)((lbl_1_data_3C7EC)));
                } else {
                    strcat((void *)path3, (void *)node->unk_20);
                }
                if (!DVDOpen(path3, &info3)) {
                    OSPanic(("memcard.c"), 1290, (lbl_1_data_3C7F8));
                }
                if (a->unk_24->unk_08 & 0x20) {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info3), a->unk_24->unk_94 + 0x1860, 0x800, 0x1800) == 0) {
                        OSPanic(("memcard.c"), 1295, (lbl_1_data_3C810));
                    }
                } else {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info3), a->unk_24->unk_94 + 0x60, 0x2000, 0) == 0) {
                        OSPanic(("memcard.c"), 1299, (lbl_1_data_3C810));
                    }
                }
                DVDClose((u32)&info3);
                a->unk_24->unk_08 |= 0x200;
            }
        } else {
            a->unk_03 = 13;
            {
                GhostFileNode *node = a->unk_24->unk_8C;
                a->unk_24->unk_94[2] = a->unk_24->unk_00;
                a->unk_24->unk_94[3] = node->unk_3E;
                strncpy((void *)((char *)a->unk_24->unk_94 + 4), (void *)((lbl_1_data_3C7CC)), 0x20);
                strcpy((void *)((u32)path4), (void *)((u32)(lbl_1_data_3C7D8)));
                if (lbl_801A66B4 != 5 && strcmp(node->unk_20, (lbl_1_data_3C7E4)) == 0) {
                    strcat((void *)path4, (void *)((lbl_1_data_3C7EC)));
                } else {
                    strcat((void *)path4, (void *)node->unk_20);
                }
                if (!DVDOpen(path4, &info4)) {
                    OSPanic(("memcard.c"), 1290, (lbl_1_data_3C7F8));
                }
                if (a->unk_24->unk_08 & 0x20) {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info4), a->unk_24->unk_94 + 0x1860, 0x800, 0x1800) == 0) {
                        OSPanic(("memcard.c"), 1295, (lbl_1_data_3C810));
                    }
                } else {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info4), a->unk_24->unk_94 + 0x60, 0x2000, 0) == 0) {
                        OSPanic(("memcard.c"), 1299, (lbl_1_data_3C810));
                    }
                }
                DVDClose((u32)&info4);
                a->unk_24->unk_08 |= 0x200;
            }
        }
        break;

    case 12:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -10:
        case -4:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 13;
            {
                GhostFileNode *node = a->unk_24->unk_8C;
                a->unk_24->unk_94[2] = a->unk_24->unk_00;
                a->unk_24->unk_94[3] = node->unk_3E;
                strncpy((void *)((char *)a->unk_24->unk_94 + 4), (void *)((lbl_1_data_3C7CC)), 0x20);
                strcpy((void *)((u32)path5), (void *)((u32)(lbl_1_data_3C7D8)));
                if (lbl_801A66B4 != 5 && strcmp(node->unk_20, (lbl_1_data_3C7E4)) == 0) {
                    strcat((void *)path5, (void *)((lbl_1_data_3C7EC)));
                } else {
                    strcat((void *)path5, (void *)node->unk_20);
                }
                if (!DVDOpen(path5, &info5)) {
                    OSPanic(("memcard.c"), 1290, (lbl_1_data_3C7F8));
                }
                if (a->unk_24->unk_08 & 0x20) {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info5), a->unk_24->unk_94 + 0x1860, 0x800, 0x1800) == 0) {
                        OSPanic(("memcard.c"), 1295, (lbl_1_data_3C810));
                    }
                } else {
                    if (fn_80006354((void *)((Sig_fn_800174D0_Fn800174D0Object *)&info5), a->unk_24->unk_94 + 0x60, 0x2000, 0) == 0) {
                        OSPanic(("memcard.c"), 1299, (lbl_1_data_3C810));
                    }
                }
                DVDClose((u32)&info5);
                a->unk_24->unk_08 |= 0x200;
            }
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 13:
        switch (a->unk_24->unk_04) {
        case -128:
        case -12:
        case -9:
        case -8:
        case -7:
        case -5:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 39;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 39:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -12:
        case -9:
        case -8:
        case -7:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 14;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 14:
        switch (a->unk_24->unk_04) {
        case -128:
        case -10:
        case -4:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_24->unk_58 = (u32)(a->unk_24->unk_94 + 4) - (u32)a->unk_24->unk_94;
            a->unk_24->unk_4E = (a->unk_24->unk_4E & ~3) | 2;
            a->unk_24->unk_50 = (u32)(a->unk_24->unk_94 + 0x60) - (u32)a->unk_24->unk_94;
            a->unk_24->unk_54 = (a->unk_24->unk_54 & ~3) | 2;
            a->unk_24->unk_56 = (a->unk_24->unk_56 & ~3) | 3;
            a->unk_24->unk_56 &= ~0xC;
            a->unk_24->unk_4E &= ~4;
            *(u16 *)a->unk_24->unk_94 = (u16)fn_1_1563E8((u32)(a->unk_24->unk_94 + 2), a->unk_24->unk_0C - 2);
            a->unk_03 = 15;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 15:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -14:
        case -11:
        case -10:
        case -4:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 16;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 16:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -10:
        case -4:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            if (a->unk_24->unk_08 & 0x1000) {
                char *tmp;
                u8 *p98;
                u8 *pBC;
                a->unk_03 = 17;
                pBC = a->unk_24->unk_BC;
                p98 = a->unk_24->unk_98;
                tmp = fn_1_45D0(lbl_801A6410.unk_0, 0x20, (void *)((u32)("memcard.c")), 499);
                strncpy((void *)tmp, (void *)((const char *)p98), 0x20);
                strncpy((void *)((char *)p98), (void *)((const char *)pBC), 0x20);
                strncpy((void *)((char *)pBC), (void *)tmp, 0x20);
                fn_1_46B4(lbl_801A6410.unk_0, (u32)tmp, ("memcard.c"), 503);
            } else {
                a->unk_03 = 17;
            }
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 17:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -10:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case -4:
        case 0:
            if (a->unk_24->unk_08 & 0x1000) {
                char *tmp;
                u8 *p98;
                u8 *pBC;
                pBC = a->unk_24->unk_BC;
                p98 = a->unk_24->unk_98;
                tmp = fn_1_45D0(lbl_801A6410.unk_0, 0x20, (void *)((u32)("memcard.c")), 499);
                strncpy((void *)tmp, (void *)((const char *)p98), 0x20);
                strncpy((void *)((char *)p98), (void *)((const char *)pBC), 0x20);
                strncpy((void *)((char *)pBC), (void *)tmp, 0x20);
                fn_1_46B4(lbl_801A6410.unk_0, (u32)tmp, ("memcard.c"), 503);
                a->unk_03 = 18;
                a->unk_24->unk_08 &= ~0x200;
            } else {
                a->unk_03 = 18;
            }
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 18:
        switch (a->unk_24->unk_04) {
        case -5:
            a->unk_24->unk_08 |= 2;
        case -128:
        case -12:
        case -10:
        case -7:
        case -4:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 19;
            a->unk_24->unk_08 &= ~0x200;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 19:
        switch (a->unk_24->unk_04) {
        case -128:
        case -6:
        case -3:
            a->unk_03 = 1;
            break;
        case -1:
            break;
        case 0:
            a->unk_03 = 20;
            break;
        default:
            a->unk_03 = 0;
            break;
        }
        break;

    case 20:
        if (a->unk_24->unk_08 & 4) {
            if (!(a->unk_24->unk_08 & 8)) {
                a->unk_28 = 45;
                a->unk_24->unk_08 |= 8;
                wait = 0;
            } else {
                timer = a->unk_28;
                if (timer > 0) {
                    a->unk_28 = timer - 1;
                    wait = 0;
                } else {
                    wait = 1;
                }
            }
            if (wait == 0) {
                break;
            }
            lbl_1_bss_718B4 = a->unk_24->unk_04;
            fn_1_46B4(lbl_801A6410.unk_0, (u32)(*(CardMgr * *)&a->unk_24), ("memcard.c"), 1004);
            a->unk_24 = 0;
            a->unk_02 = 0xFF;
            a->unk_03 = 0xFF;
            a->unk_04 = 0xFF;
            a->unk_05 = 0xFF;
            a->unk_06 = 0xFF;
            a->unk_07 = 0;
            a->unk_08 = -1;
            a->unk_0A = -1;
            a->unk_30 = 0;
            a->unk_34 = (0.0f);
            a->unk_38 = (0.0f);
            a->unk_2A &= ~4;
            lbl_1_bss_772C8 = 0;
            lbl_1_bss_718B8 = 1;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            lbl_1_bss_718B4 = a->unk_24->unk_04;
            fn_1_46B4(lbl_801A6410.unk_0, (u32)(*(CardMgr * *)&a->unk_24), ("memcard.c"), 1004);
            a->unk_24 = 0;
            a->unk_02 = 0xFF;
            a->unk_03 = 0xFF;
            a->unk_04 = 0xFF;
            a->unk_05 = 0xFF;
            a->unk_06 = 0xFF;
            a->unk_07 = 0;
            a->unk_08 = -1;
            a->unk_0A = -1;
            a->unk_30 = 0;
            a->unk_34 = (0.0f);
            a->unk_38 = (0.0f);
            a->unk_2A &= ~4;
            lbl_1_bss_772C8 = 0;
            lbl_1_bss_718B8 = 1;
        }
        break;

    }

    if (a->unk_24 != 0) {
        lbl_1_bss_718B4 = a->unk_24->unk_04;
    }
}
#undef lbl_1_bss_960
#undef lbl_1_bss_9F8
#undef lbl_801A6410
#undef lbl_1_bss_716C8
#undef lbl_1_bss_718B4
#undef lbl_1_bss_718E0
#undef lbl_1_bss_772C8
#undef lbl_1_bss_7730A
/* fzgx:end fn_1_AD264 */

/* fzgx:begin fn_1_AEC34 */
/* VIEWS */
/* Copies the backup buffer back over the card image unless the card is flagged 0x20 (the restore
   half of fn_1_AEC34's copy). MWCC auto-inlines it into fn_1_AECCC (the retail code there is this body)
   and the link strips the out-of-line copy. Its out-of-line definition here is the first access to
   lbl_1_bss_7730C, which is why retail lays 7730C out before 77310 although fn_1_AEC34 stores 77310
   first. The helper's existence is inferred from that .bss order.
   WARNING: compiler-diff device, not original code (circumstantial: the helper boundary is inferred only from
   the .bss order; its body is fn_1_AECCC's retail code) */
static void memcard_restore_backup(MemcardCard *card) {
    if ((card->unk_8 & 0x20) == 0) {
        if (lbl_1_bss_7730C != 0) {
            fn_80008BA8((void *)(card->unk_94 + card->unk_E0), (void *)lbl_1_bss_7730C, card->unk_E4);
        }
    }
}

// Finalize the card operation and publish its completion state.

void fn_1_AEC34(Fn1AEC34A *request, Fn1AEC34B *operation) {
    if ((operation->card->flags & 0x20) == 0) {
        if (request->payload != 0) {
            strncpy((u8 *)operation->card->buffer + 0x24,
                        request->payload, 0x20);
        }
        fn_80008BA8((u8 *)operation->card->buffer + 0x2060,
                    request->result, (u32)operation->card->length);
    }
    operation->state = 3;
    lbl_1_bss_77310 = 1;
    lbl_1_bss_7730C = 0;
}
/* fzgx:end fn_1_AEC34 */

/* fzgx:begin fn_1_AECCC */
/* VIEWS */
/* VIEWS */
#define lbl_1_bss_9F8 (*(MemcardDvdState *)&lbl_1_bss_9F8)
/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

void fn_1_AECCC(MemcardObj *arg0, u32 unused) {
    s32 delayed;
    s32 res;

    if (arg0->unk_4 != 0xFF) {
        if (lbl_1_bss_77310 != 0) {
            switch (arg0->unk_4) {
            default:
                OSReport("submode    : %d\n");
                OSReport("submode req: %d\n", arg0->unk_3);
                OSPanic("memcard.c", 3575, "submode error!!\n");
                break;

            case 1:
                arg0->unk_24->unk_8 &= ~0x200;
                if (arg0->unk_24->unk_8 & 0x8000) {
                    arg0->unk_3 = 0x15;
                } else {
                    MemcardDvdState *dvd = &lbl_1_bss_9F8;
                    if (((dvd->unk_8 >> 8) & 1) && (arg0->unk_24->unk_8 & 0x800)) {
                        arg0->unk_3 = 0xC;
                        arg0->unk_24->unk_8 &= ~0x800;
                        arg0->unk_24->unk_8 &= ~0x2;
                        arg0->unk_24->unk_8 |= 0x200;
                        arg0->unk_2A &= ~0x4;
                        arg0->unk_8 = -1;
                        arg0->unk_A = -1;
                    } else if ((dvd->unk_8 >> 8) & 1) {
                        if ((dvd->unk_8 >> 8) & 1)
                            arg0->unk_3 = 0x15;
                        else
                            arg0->unk_3 = 0x20;
                    } else if (((dvd->unk_8 >> 11) & 1) && (arg0->unk_24->unk_8 & 2) == 0) {
                        if (arg0->unk_5 == 3 && arg0->unk_C != 0) {
                            do {
                                res = CARDUnmount(arg0->unk_0);
                            } while (res == -1);
                            fn_1_46B4((u32)lbl_801A6410, (u32)((void *)arg0->unk_C), "memcard.c", 3613);
                            arg0->unk_7 = 0;
                            arg0->unk_C = 0;
                            {
                                MemcardCard *card = arg0->unk_24;
                                card->unk_1C = 0;
                                card->unk_18 = 0;
                            }
                        }
                        if (arg0->unk_6 != 0xFF) {
                            arg0->unk_3 = arg0->unk_6;
                            arg0->unk_6 = 0xFF;
                        } else {
                            arg0->unk_3 = arg0->unk_5;
                        }
                        arg0->unk_8 = -1;
                        arg0->unk_A = -1;
                        arg0->unk_2A &= ~0x4;
                    } else if (((dvd->unk_8 >> 10) & 1) && (arg0->unk_24->unk_8 & 0x400)) {
                        arg0->unk_3 = 5;
                        arg0->unk_24->unk_8 &= ~0x400;
                        arg0->unk_24->unk_8 |= 0x200;
                        arg0->unk_2A &= ~0x4;
                        arg0->unk_2A |= 0x10;
                    }
                }
                lbl_1_bss_77309 = 0;
                break;

            case 21:
                if (arg0->unk_24->unk_8 & 0x8000)
                    arg0->unk_2 = 0xFE;
                else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1)
                    arg0->unk_2 = 0xFE;
                break;

            case 32:
                arg0->unk_2 = 0xFE;
                break;

            case 3: {
                s8 cmd = arg0->unk_1;
                if (cmd == -127) {
                    arg0->unk_24->unk_4 = cmd;
                    arg0->unk_3 = 1;
                } else {
                    MemcardCard *card = arg0->unk_24;
                    switch (card->unk_4) {
                    case -5:
                        card->unk_8 |= 2;
                    case -128:
                    case -3:
                    case -2:
                        arg0->unk_3 = 1;
                        break;
                    case -13:
                        if (card->unk_8 & 0x8000) {
                            arg0->unk_2A |= 4;
                            arg0->unk_2 = 0xFE;
                        } else if (lbl_801A66B4 == 5) {
                            arg0->unk_3 = 5;
                        } else {
                            card->unk_8 |= 0x400;
                            arg0->unk_3 = 1;
                        }
                        break;
                    case -6:
                    case 0:
                        arg0->unk_3 = 4;
                        break;
                    case -1:
                        break;
                    default:
                        arg0->unk_3 = 0;
                        break;
                    }
                }
                break;
            }

            case 38:
                arg0->unk_3 = 3;
                break;

            case 4: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -6:
                    if (card->unk_8 & 0x8000) {
                        arg0->unk_2A |= 4;
                        arg0->unk_2 = 0xFE;
                    } else {
                        arg0->unk_3 = 5;
                    }
                    break;
                case -13:
                    if (card->unk_8 & 0x8000) {
                        arg0->unk_2A |= 4;
                        arg0->unk_2 = 0xFE;
                    } else if (lbl_801A66B4 == 5) {
                        arg0->unk_3 = 5;
                    } else {
                        card->unk_8 |= 0x400;
                        arg0->unk_3 = 1;
                    }
                    break;
                case -1:
                    break;
                case 0:
                    arg0->unk_3 = 7;
                    break;
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 5:
                if (arg0->unk_24->unk_4 == 0)
                    break;
                if ((arg0->unk_2A & 1) == 0) {
                    arg0->unk_28 = 12;
                    arg0->unk_2A |= 1;
                    delayed = 0;
                } else if (arg0->unk_28 > 0) {
                    arg0->unk_28 -= 1;
                    delayed = 0;
                } else {
                    delayed = 1;
                }
                if (delayed == 0)
                    break;
                {
                    MemcardCard *card = arg0->unk_24;
                    if (card->unk_4 == 2 || card->unk_1 == 1) {
                        card->unk_4 = -126;
                        arg0->unk_3 = 1;
                    } else {
                        arg0->unk_3 = 6;
                        arg0->unk_24->unk_8 |= 0x200;
                    }
                }
                break;

            case 6: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    arg0->unk_3 = 0x16;
                    arg0->unk_24->unk_8 &= ~0x200;
                    break;
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 22:
                if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
                    arg0->unk_3 = 0x15;
                    arg0->unk_24->unk_4 = -0x79;
                }
                break;

            case 7: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    arg0->unk_3 = 0xA;
                    break;
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 10: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -10:
                case -6:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -4:
                    arg0->unk_3 = 0x12;
                    break;
                case 0:
                    arg0->unk_3 = 0xE;
                    break;
                case -5:
                default:
                    arg0->unk_3 = 0;
                    break;
                case -1:
                    break;
                }
                break;
            }

            case 18: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -12:
                case -10:
                case -7:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -4:
                    if (card->unk_8 & 0x100)
                        arg0->unk_3 = 0x1F;
                    else
                        arg0->unk_3 = 1;
                    break;
                case 0:
                    arg0->unk_3 = 0xA;
                    break;
                case -6:
                case -11:
                case -9:
                case -8:
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                case -1:
                    break;
                }
                break;
            }

            case 31: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -6:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case 0:
                    if (card->unk_14 == 0) {
                        card->unk_4 = -8;
                        arg0->unk_3 = 1;
                    } else if (card->unk_10 < card->unk_C) {
                        card->unk_4 = -9;
                        arg0->unk_3 = 1;
                    } else {
                        card->unk_4 = -4;
                        arg0->unk_3 = 1;
                    }
                    break;
                case -1:
                    break;
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 14: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    if (lbl_1_bss_7730C == 0) {
                        u32 p = (u32)fn_1_45D0((u32)lbl_801A6410, card->unk_E4, "memcard.c", 4000);
                        lbl_1_bss_7730C = p;
                        fn_80008BA8((void *)p, (void *)(arg0->unk_24->unk_94 + 0x2060), arg0->unk_24->unk_E4);
                    }
                    if (arg0->unk_24->unk_40 < arg0->unk_24->unk_C) {
                        lbl_1_bss_718B4 = arg0->unk_24->unk_4;
                        arg0->unk_7 = 0;
                        arg0->unk_8 = -1;
                        arg0->unk_A = -1;
                        arg0->unk_30 = 0;
                        arg0->unk_34 = 0.0f;
                        arg0->unk_38 = 0.0f;
                        lbl_1_bss_718B8 = 1;
                        arg0->unk_3 = 8;
                        lbl_1_bss_77310 = 0;
                    } else {
                        arg0->unk_3 = 0x17;
                    }
                    break;
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 23: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -14:
                case -11:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0: {
                    u16 sum = fn_1_1563E8(card->unk_94 + 2, card->unk_C - 2);
                    MemcardCard *card2 = arg0->unk_24;
                    if (*(u16 *)card2->unk_94 != sum) {
                        card2->unk_4 = -0x7C;
                        arg0->unk_24->unk_8 |= 2;
                        arg0->unk_24->unk_8 |= 0x800;
                        arg0->unk_3 = 1;
                    } else if (*(u8 *)(card2->unk_94 + 3) != card2->unk_8C->name[0x1E]) {
                        lbl_1_bss_718B4 = card2->unk_4;
                        arg0->unk_7 = 0;
                        arg0->unk_8 = -1;
                        arg0->unk_A = -1;
                        arg0->unk_30 = 0;
                        arg0->unk_34 = 0.0f;
                        arg0->unk_38 = 0.0f;
                        lbl_1_bss_718B8 = 1;
                        arg0->unk_3 = 8;
                        lbl_1_bss_77310 = 0;
                    } else {
                        memcard_restore_backup(card2);
                        arg0->unk_3 = 8;
                    }
                    break;
                }
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                if (arg0->unk_24->unk_4 != -1 && lbl_1_bss_7730C != 0) {
                    fn_1_46B4((u32)lbl_801A6410, (u32)((void *)lbl_1_bss_7730C), "memcard.c", 4095);
                    lbl_1_bss_7730C = 0;
                }
                break;
            }

            case 8: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -10:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -4:
                case 0:
                    arg0->unk_3 = 9;
                    break;
                case -1:
                    break;
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 12: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    card->unk_4 = -4;
                    arg0->unk_3 = 1;
                    break;
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 9: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -6:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    lbl_1_bss_718B4 = card->unk_4;
                    arg0->unk_7 = 0;
                    arg0->unk_8 = -1;
                    arg0->unk_A = -1;
                    arg0->unk_30 = 0;
                    arg0->unk_34 = 0.0f;
                    arg0->unk_38 = 0.0f;
                    lbl_1_bss_718B8 = 1;
                    arg0->unk_3 = 8;
                    lbl_1_bss_77310 = 0;
                    break;
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }
            }
        } else {
            switch (arg0->unk_4) {
            default:
                OSReport("submode    : %d\n");
                OSReport("submode req: %d\n", arg0->unk_3);
                OSPanic("memcard.c", 4203, "submode error!!\n");
                break;

            case 1:
                arg0->unk_24->unk_8 &= ~0x200;
                if (arg0->unk_24->unk_8 & 0x8000) {
                    arg0->unk_3 = 2;
                } else {
                    MemcardDvdState *dvd = &lbl_1_bss_9F8;
                    if ((dvd->unk_8 >> 8) & 1) {
                        arg0->unk_3 = 2;
                    } else if (((dvd->unk_8 >> 11) & 1) && (arg0->unk_24->unk_8 & 2) == 0) {
                        if (arg0->unk_5 == 3 && arg0->unk_C != 0) {
                            do {
                                res = CARDUnmount(arg0->unk_0);
                            } while (res == -1);
                            fn_1_46B4((u32)lbl_801A6410, (u32)((void *)arg0->unk_C), "memcard.c", 4221);
                            arg0->unk_7 = 0;
                            arg0->unk_C = 0;
                            {
                                MemcardCard *card = arg0->unk_24;
                                card->unk_1C = 0;
                                card->unk_18 = 0;
                            }
                        }
                        if (arg0->unk_6 != 0xFF) {
                            arg0->unk_3 = arg0->unk_6;
                            arg0->unk_6 = 0xFF;
                        } else {
                            arg0->unk_3 = arg0->unk_5;
                        }
                        arg0->unk_8 = -1;
                        arg0->unk_A = -1;
                        arg0->unk_2A &= ~0x4;
                    } else if (((dvd->unk_8 >> 10) & 1) && (arg0->unk_24->unk_8 & 0x400)) {
                        arg0->unk_3 = 5;
                        arg0->unk_24->unk_8 &= ~0x400;
                        arg0->unk_24->unk_8 |= 0x200;
                        arg0->unk_2A &= ~0x4;
                        arg0->unk_2A |= 0x10;
                    }
                }
                lbl_1_bss_77309 = 0;
                break;

            case 2:
                if (arg0->unk_24->unk_8 & 0x8000)
                    arg0->unk_2 = 0xFE;
                else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1)
                    arg0->unk_2 = 0xFE;
                break;

            case 8: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -10:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -4:
                case 0:
                    arg0->unk_3 = 9;
                    break;
                case -1:
                    break;
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 9: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -6:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0: {
                    MemcardHeader *hdr;
                    MemcardDvdFileInfo fileInfo;
                    MemcardPathBuf path;

                    if ((card->unk_8 & 4) || (card->unk_8 & 0x4000)) {
                        arg0->unk_3 = 0xE;
                        hdr = arg0->unk_24->unk_8C;
                        *(u8 *)(arg0->unk_24->unk_94 + 2) = arg0->unk_24->unk_0;
                        *(u8 *)(arg0->unk_24->unk_94 + 3) = hdr->name[0x1E];
                        strncpy((void *)((char *)(arg0->unk_24->unk_94 + 4)), (void *)(lbl_1_data_3C7CC), 0x20);
                        strcpy((void *)((char *)path.w), (void *)(lbl_1_data_3C7D8));
                        if (lbl_801A66B4 != 5 && strcmp((void *)((const char *)hdr->name), (void *)(lbl_1_data_3C7E4)) == 0) {
                            strcat((void *)((char *)path.w), (void *)(lbl_1_data_3C7EC));
                        } else {
                            strcat((void *)((char *)path.w), (void *)((const char *)hdr->name));
                        }
                        if (!((s32)DVDOpen((char *)path.w, (void *)&fileInfo))) {
                            OSPanic("memcard.c", 1290, lbl_1_data_3C7F8);
                        }
                        if (arg0->unk_24->unk_8 & 0x20) {
                            if (!fn_80006354((void *)&fileInfo, (void *)(arg0->unk_24->unk_94 + 0x1860), 0x800, 0x1800)) {
                                OSPanic("memcard.c", 1295, lbl_1_data_3C810);
                            }
                        } else {
                            if (!fn_80006354((void *)&fileInfo, (void *)(arg0->unk_24->unk_94 + 0x60), 0x2000, 0)) {
                                OSPanic("memcard.c", 1299, lbl_1_data_3C810);
                            }
                        }
                        DVDClose((u32)&fileInfo);
                        arg0->unk_24->unk_8 |= 0x200;
                    } else {
                        arg0->unk_3 = 0xB;
                    }
                    break;
                }
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 11:
                if (arg0->unk_24->unk_4 == 0)
                    break;
                if ((arg0->unk_2A & 1) == 0) {
                    arg0->unk_28 = 12;
                    arg0->unk_2A |= 1;
                    delayed = 0;
                } else if (arg0->unk_28 > 0) {
                    arg0->unk_28 -= 1;
                    delayed = 0;
                } else {
                    delayed = 1;
                }
                if (delayed == 0)
                    break;
                {
                    MemcardCard *card = arg0->unk_24;
                    if (card->unk_4 == 2 || card->unk_1 == 1) {
                        card->unk_4 = -125;
                        arg0->unk_3 = 1;
                    } else {
                        arg0->unk_3 = 0xE;
                    }
                }
                break;

            case 14: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0: {
                    u8 *p = (u8 *)arg0->unk_24->unk_94;
                    arg0->unk_24->unk_58 = (u32)(p + 4) - (u32)p;
                }
                    arg0->unk_24->unk_4E = (arg0->unk_24->unk_4E & ~3) | 2;
                    arg0->unk_24->unk_50 = (u32)(arg0->unk_24->unk_94 + 0x60) - arg0->unk_24->unk_94;
                    arg0->unk_24->unk_54 = (arg0->unk_24->unk_54 & ~3) | 2;
                    arg0->unk_24->unk_56 = (arg0->unk_24->unk_56 & ~3) | 3;
                    arg0->unk_24->unk_56 &= ~0xC;
                    arg0->unk_24->unk_4E &= ~0x4;
                    *(u16 *)arg0->unk_24->unk_94 = fn_1_1563E8(arg0->unk_24->unk_94 + 2, arg0->unk_24->unk_C - 2);
                    arg0->unk_3 = 0x24;
                    break;
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 36: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -14:
                case -11:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case 0:
                    arg0->unk_3 = 0x25;
                    break;
                case -9:
                case -8:
                case -7:
                case -6:
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                case -1:
                    break;
                }
                break;
            }

            case 37: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -14:
                case -11:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case 0:
                    arg0->unk_3 = 0x10;
                    break;
                case -9:
                case -8:
                case -7:
                case -6:
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                case -1:
                    break;
                }
                break;
            }

            case 16: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -5:
                    card->unk_8 |= 2;
                case -128:
                case -10:
                case -4:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    arg0->unk_3 = 0x13;
                    arg0->unk_24->unk_8 &= ~0x200;
                    break;
                case -2:
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 19: {
                MemcardCard *card = arg0->unk_24;
                switch (card->unk_4) {
                case -128:
                case -6:
                case -3:
                    arg0->unk_3 = 1;
                    break;
                case -1:
                    break;
                case 0:
                    arg0->unk_3 = 0x14;
                    break;
                default:
                    arg0->unk_3 = 0;
                    break;
                }
                break;
            }

            case 20:
                if (arg0->unk_24->unk_8 & 4) {
                    if ((arg0->unk_24->unk_8 & 8) == 0) {
                        arg0->unk_28 = 0x2D;
                        arg0->unk_24->unk_8 |= 8;
                        delayed = 0;
                    } else if (arg0->unk_28 > 0) {
                        arg0->unk_28 -= 1;
                        delayed = 0;
                    } else {
                        delayed = 1;
                    }
                    if (delayed == 0)
                        break;
                    lbl_1_bss_718B4 = arg0->unk_24->unk_4;
                    fn_1_46B4((u32)lbl_801A6410, (u32)arg0->unk_24, "memcard.c", 1004);
                    arg0->unk_24 = 0;
                    arg0->unk_2 = 0xFF;
                    arg0->unk_3 = 0xFF;
                    arg0->unk_4 = 0xFF;
                    arg0->unk_5 = 0xFF;
                    arg0->unk_6 = 0xFF;
                    arg0->unk_7 = 0;
                    arg0->unk_8 = -1;
                    arg0->unk_A = -1;
                    arg0->unk_30 = 0;
                    arg0->unk_34 = 0.0f;
                    arg0->unk_38 = 0.0f;
                    arg0->unk_2A &= ~0x4;
                    lbl_1_bss_772C8[0] = 0;
                    lbl_1_bss_718B8 = 1;
                } else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
                    lbl_1_bss_718B4 = arg0->unk_24->unk_4;
                    fn_1_46B4((u32)lbl_801A6410, (u32)arg0->unk_24, "memcard.c", 1004);
                    arg0->unk_24 = 0;
                    arg0->unk_2 = 0xFF;
                    arg0->unk_3 = 0xFF;
                    arg0->unk_4 = 0xFF;
                    arg0->unk_5 = 0xFF;
                    arg0->unk_6 = 0xFF;
                    arg0->unk_7 = 0;
                    arg0->unk_8 = -1;
                    arg0->unk_A = -1;
                    arg0->unk_30 = 0;
                    arg0->unk_34 = 0.0f;
                    arg0->unk_38 = 0.0f;
                    arg0->unk_2A &= ~0x4;
                    lbl_1_bss_772C8[0] = 0;
                    lbl_1_bss_718B8 = 1;
                }
                break;
            }
        }

        if (arg0->unk_24 != 0)
            lbl_1_bss_718B4 = arg0->unk_24->unk_4;
    }
}
/* fzgx:end fn_1_AECCC */

/* fzgx:begin fn_1_B03A8 */
#pragma opt_common_subs reset

void fn_1_B03A8(void *arg0, void *arg1) {
    void *child = *(void **)((u8 *)arg1 + 0x24);
    if ((*(u32 *)((u8 *)child + 0x8) & 0x20) == 0) {
        *(u32 *)((u8 *)child + 0x90) = *(u32 *)((u8 *)arg0 + 0xc);
    }
    *(u8 *)((u8 *)arg1 + 0x3) = 0x3;
}
/* fzgx:end fn_1_B03A8 */

/* fzgx:begin fn_1_B03CC */
void fn_1_B03CC(B03CC_State *arg0) {
    u8 *slot0;

    if (arg0->unk_4 == 0xff) {
        return;
    }
    switch (arg0->unk_4) {
    default:
        OSReport("submode    : %d\n", arg0->unk_4);
        OSReport("submode req: %d\n", arg0->unk_3);
        OSPanic("memcard.c", 0x11f2, "submode error!!\n");
        break;

    case 1: {
        arg0->unk_24->unk_8 &= ~0x200;
        if (lbl_1_bss_962 == 100 && arg0->unk_24->unk_0 == 3) {
            arg0->unk_24->unk_8 |= 2;
        }
        if (arg0->unk_24->unk_8 & 0x8000) {
            arg0->unk_3 = 0x15;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8) && (arg0->unk_24->unk_8 & 0x800)) {
            arg0->unk_3 = 0xc;
            arg0->unk_24->unk_8 &= ~0x800;
            arg0->unk_24->unk_8 &= ~2;
            arg0->unk_24->unk_8 |= 0x200;
            arg0->unk_2A &= ~4;
            arg0->unk_8 = -1;
            arg0->unk_a = -1;
        } else if (lbl_1_bss_962 == 100 && ((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_0 == 3) {
            if (((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_4 == -4) {
                arg0->unk_8 = -1;
                arg0->unk_a = -1;
                arg0->unk_3 = 0x20;
            } else if (((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_4 == -13) {
                arg0->unk_a = 0x16;
                arg0->unk_24->unk_8 &= ~2;
                if (PAD_BIT(lbl_1_bss_9F8.unk_8, 11)) {
                    if (arg0->unk_5 == 3 && arg0->unk_C != 0) {
                        B03CC_Work *wA;
                        while (CARDUnmount(arg0->unk_0) == -1) {
                        }
                        fn_1_46B4((u32)lbl_801A6410, (u32)((void *)arg0->unk_C), "memcard.c", 0x121e);
                        arg0->unk_7 = 0;
                        arg0->unk_C = 0;
                        wA = arg0->unk_24;
                        wA->unk_1C = 0;
                        wA->unk_18 = 0;
                    }
                    if (arg0->unk_6 != 0xff) {
                        arg0->unk_3 = arg0->unk_6;
                        arg0->unk_6 = 0xff;
                    } else {
                        arg0->unk_3 = arg0->unk_5;
                    }
                    slot0 = (u8 *)&lbl_1_bss_716C8[0];
                    arg0->unk_8 = -1;
                    arg0->unk_a = -1;
                    arg0->unk_2A &= ~4;
                    if ((u8 *)arg0 == slot0) {
                        lbl_1_bss_718B1 = 0;
                    } else if ((u8 *)arg0 == slot0 + 0xa0) {
                        lbl_1_bss_718B1 = 1;
                    }
                }
                if ((PAD_BIT(lbl_1_bss_9F8.unk_8, 10)) && (arg0->unk_24->unk_8 & 0x400)) {
                    arg0->unk_3 = 5;
                    arg0->unk_24->unk_8 &= ~0x400;
                    arg0->unk_24->unk_8 |= 0x200;
                    arg0->unk_2A &= ~4;
                    arg0->unk_2A |= 0x10;
                }
                if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
                    arg0->unk_3 = 0x15;
                }
            } else {
                arg0->unk_a = 0xe;
                if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
                    arg0->unk_3 = 0x15;
                }
            }
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
                arg0->unk_3 = 0x15;
            } else {
                arg0->unk_3 = 0x20;
            }
        } else if ((PAD_BIT(lbl_1_bss_9F8.unk_8, 11)) && (((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_8 & 2) == 0) {
            if (arg0->unk_5 == 3 && arg0->unk_C != 0) {
                B03CC_Work *wB;
                while (CARDUnmount(arg0->unk_0) == -1) {
                }
                fn_1_46B4((u32)lbl_801A6410, (u32)((void *)arg0->unk_C), "memcard.c", 0x1251);
                arg0->unk_7 = 0;
                arg0->unk_C = 0;
                wB = arg0->unk_24;
                wB->unk_1C = 0;
                wB->unk_18 = 0;
            }
            if (arg0->unk_6 != 0xff) {
                arg0->unk_3 = arg0->unk_6;
                arg0->unk_6 = 0xff;
            } else {
                arg0->unk_3 = arg0->unk_5;
            }
            slot0 = (u8 *)&lbl_1_bss_716C8[0];
            arg0->unk_8 = -1;
            arg0->unk_a = -1;
            arg0->unk_2A &= ~4;
            if ((u8 *)arg0 == slot0) {
                lbl_1_bss_718B1 = 0;
            } else if ((u8 *)arg0 == slot0 + 0xa0) {
                lbl_1_bss_718B1 = 1;
            }
        } else if ((PAD_BIT(lbl_1_bss_9F8.unk_8, 10)) && (((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_8 & 0x400)) {
            arg0->unk_3 = 5;
            ((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_8 &= ~0x400;
            ((B03CC_Work *)*(void **)((u8 *)arg0 + 0x24))->unk_8 |= 0x200;
            arg0->unk_2A &= ~4;
            arg0->unk_2A |= 0x10;
        }
        lbl_1_bss_77309 = 0;
        break;
    }

    case 21: {
        if (lbl_1_bss_962 == 100 && arg0->unk_24->unk_0 == 3) {
            if (arg0->unk_24->unk_4 == -121) {
                arg0->unk_2 = 0xfe;
            } else {
                arg0->unk_8 = 0x68;
                arg0->unk_a = 0xe;
                arg0->unk_24->unk_8 &= ~0x2000;
                arg0->unk_24->unk_8 |= 2;
            }
        }
        if (arg0->unk_24->unk_8 & 0x8000) {
            arg0->unk_2 = 0xfe;
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            arg0->unk_2 = 0xfe;
        }
        break;
    }

    case 32: {
        arg0->unk_2 = 0xfe;
        break;
    }

    case 3: {
        s8 v = arg0->unk_1;
        if (v == -127) {
            arg0->unk_24->unk_4 = v;
            arg0->unk_3 = 1;
        } else {
            B03CC_Work *work = arg0->unk_24;
            switch (work->unk_4) {
            case -5:
                work->unk_8 |= 2;
            case -128:
            case -3:
            case -2:
                arg0->unk_3 = 1;
                break;
            case -13:
                if (work->unk_8 & 0x8000) {
                    arg0->unk_2A |= 4;
                    arg0->unk_2 = 0xfe;
                } else if (lbl_801A66B4 == 5) {
                    arg0->unk_3 = 5;
                } else {
                    work->unk_8 |= 0x400;
                    arg0->unk_3 = 1;
                }
                break;
            case -6:
            case 0:
                arg0->unk_3 = 4;
                break;
            case -1:
                break;
            default:
                arg0->unk_3 = 0;
                break;
            }
        }
        break;
    }

    case 38: {
        arg0->unk_3 = 3;
        break;
    }

    case 4: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -5:
            work->unk_8 |= 2;
        case -128:
        case -3:
            arg0->unk_3 = 1;
            break;
        case -6:
            if (work->unk_8 & 0x8000) {
                arg0->unk_2A |= 4;
                arg0->unk_2 = 0xfe;
            } else {
                arg0->unk_3 = 5;
            }
            break;
        case -13:
            if (work->unk_8 & 0x8000) {
                arg0->unk_2A |= 4;
                arg0->unk_2 = 0xfe;
            } else if (lbl_801A66B4 == 5) {
                arg0->unk_3 = 5;
            } else {
                work->unk_8 |= 0x400;
                arg0->unk_3 = 1;
            }
            break;
        case 0:
            arg0->unk_3 = 7;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 5: {
        if (arg0->unk_24->unk_4 != 0) {
            s32 flag;
            if ((arg0->unk_2A & 1) == 0) {
                arg0->unk_28 = 0xc;
                arg0->unk_2A |= 1;
                flag = 0;
            } else if (arg0->unk_28 > 0) {
                arg0->unk_28--;
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag == 0) {
                break;
            }
            if (arg0->unk_24->unk_4 == 2 || arg0->unk_24->unk_1 == 1) {
                arg0->unk_24->unk_4 = -126;
                arg0->unk_3 = 1;
            } else {
                arg0->unk_3 = 6;
                arg0->unk_24->unk_8 |= 0x200;
                if (lbl_1_bss_962 == 100 && arg0->unk_24->unk_0 == 3) {
                    arg0->unk_24->unk_8 &= ~0x2000;
                }
            }
        }
        break;
    }

    case 6: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -5:
            work->unk_8 |= 2;
        case -128:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0:
            arg0->unk_3 = 0x16;
            arg0->unk_24->unk_8 &= ~0x200;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 22: {
        if (arg0->unk_24->unk_8 & 4) {
            s32 flag;
            if ((arg0->unk_24->unk_8 & 8) == 0) {
                arg0->unk_28 = 0x2d;
                arg0->unk_24->unk_8 |= 8;
                flag = 0;
            } else if (arg0->unk_28 > 0) {
                arg0->unk_28--;
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag != 0) {
                arg0->unk_3 = 0x20;
            }
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            arg0->unk_3 = 0x15;
        }
        arg0->unk_24->unk_4 = -121;
        break;
    }

    case 7: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -128:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0:
            arg0->unk_3 = 0xa;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 10: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -128:
        case -10:
        case -6:
        case -3:
            arg0->unk_3 = 1;
            break;
        case -4:
            arg0->unk_3 = 0x12;
            break;
        case 0:
            arg0->unk_3 = 0xe;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 18: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -5:
            work->unk_8 |= 2;
        case -128:
        case -12:
        case -10:
        case -7:
        case -3:
            arg0->unk_3 = 1;
            break;
        case -4:
            if (work->unk_8 & 0x100) {
                arg0->unk_3 = 0x1f;
            } else {
                arg0->unk_3 = 1;
            }
            break;
        case 0:
            arg0->unk_3 = 0xa;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 31: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -128:
        case -6:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0:
            work->unk_4 = -4;
            arg0->unk_3 = 1;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 14: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -128:
        case -10:
        case -4:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0:
            if (work->unk_40 < work->unk_C) {
                work->unk_4 = -122;
                lbl_1_bss_718B4 = -122;
                arg0->unk_3 = 1;
            } else {
                arg0->unk_3 = 0x17;
            }
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 23: {
        switch (arg0->unk_24->unk_4) {
        case -128:
        case -14:
        case -11:
        case -10:
        case -4:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0: {
            u32 res = (u16)fn_1_1563E8((u32)(arg0->unk_24->unk_94 + 2), arg0->unk_24->unk_C - 2);
            if (*(u16 *)arg0->unk_24->unk_94 != res) {
                arg0->unk_24->unk_4 = -124;
                arg0->unk_24->unk_8 |= 2;
                arg0->unk_24->unk_8 |= 0x800;
                arg0->unk_3 = 1;
                break;
            } else if (*(arg0->unk_24->unk_94 + 3) != *((u8 *)arg0->unk_24->unk_8C + 0x3e)) {
                arg0->unk_24->unk_4 = -122;
                arg0->unk_3 = 1;
                break;
            } else if ((arg0->unk_24->unk_8 & 0x20) == 0) {
                if (arg0->unk_24->unk_0 == 1) {
                    if ((s64)(s32) * (u16 *)(arg0->unk_24->unk_94 + 0x2200)
                            + ((u64)*(u16 *)(arg0->unk_24->unk_94 + 0x7580) << 16)
                            + ((u64)*(u16 *)(arg0->unk_24->unk_94 + 0x2060) << 32)
                            + ((u64)*(u16 *)(arg0->unk_24->unk_94 + 0x2066) << 48)
                        != *(u64 *)((u8 *)arg0->unk_24 + 0x18)) {
                        arg0->unk_24->unk_4 = -124;
                        arg0->unk_24->unk_8 |= 2;
                        arg0->unk_24->unk_8 |= 0x800;
                        arg0->unk_3 = 1;
                        break;
                    }
                }
                if (arg0->unk_24->unk_8C->unk_44 == -1) {
                    fn_80008BA8((void *)arg0->unk_24->unk_90, arg0->unk_24->unk_94 + 0x2060, arg0->unk_24->unk_B8);
                    if (arg0->unk_24->unk_0 == 1) {
                        fn_80008BA8(arg0->unk_54, arg0->unk_24->unk_94 + 0x24, 0x20);
                    }
                } else {
                    fn_80008BA8((void *)arg0->unk_24->unk_90, arg0->unk_24->unk_94 + arg0->unk_24->unk_E0, arg0->unk_24->unk_E4);
                    if (arg0->unk_24->unk_0 == 1) {
                        fn_80008BA8(arg0->unk_54, arg0->unk_24->unk_94 + 0x24, 0x20);
                    }
                }
            }
            arg0->unk_3 = 8;
            break;
        }
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 8: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -5:
            work->unk_8 |= 2;
        case -128:
        case -10:
        case -3:
            arg0->unk_3 = 1;
            break;
        case -4:
        case 0:
            arg0->unk_3 = 9;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 12: {
        B03CC_Work *work = arg0->unk_24;
        switch (work->unk_4) {
        case -5:
            work->unk_8 |= 2;
        case -128:
        case -10:
        case -4:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0:
            work->unk_4 = -4;
            arg0->unk_3 = 0x20;
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 9: {
        switch (arg0->unk_24->unk_4) {
        case -128:
        case -6:
        case -3:
            arg0->unk_3 = 1;
            break;
        case 0:
            if (arg0->unk_24->unk_0 == 1) {
                arg0->unk_50 = 1;
                *(u64 *)((u8 *)arg0 + 0x48) = *(u64 *)((u8 *)arg0->unk_24 + 0x18);
                lbl_1_bss_7730A = arg0->unk_0;
            }
            if (arg0->unk_24->unk_8 & 0x2000) {
                lbl_1_bss_718B4 = arg0->unk_24->unk_4;
                if (arg0->unk_C != 0) {
                    B03CC_Work *wC;
                    while (CARDUnmount(arg0->unk_0) == -1) {
                    }
                    fn_1_46B4((u32)lbl_801A6410, (u32)((void *)arg0->unk_C), "memcard.c", 0x3c8);
                    arg0->unk_7 = 0;
                    arg0->unk_C = 0;
                    wC = arg0->unk_24;
                    wC->unk_1C = 0;
                    wC->unk_18 = 0;
                }
                if (arg0->unk_24->unk_8 & 0x80) {
                    arg0->unk_3C = arg0->unk_24->unk_10 / 8192;
                    arg0->unk_40 = arg0->unk_24->unk_14;
                }
                if ((arg0->unk_24->unk_8 & 0x20) == 0) {
                    fn_1_46B4((u32)lbl_801A6410, (u32)arg0->unk_24->unk_94, "memcard.c", 0x3d4);
                }
                if (arg0->unk_2 == 4) {
                    if (lbl_1_bss_716C0 != 0) {
                        u32 t;
                        B03CC_Work *wD;
                        wD = arg0->unk_24;
                        t = (u32)wD->unk_94;
                        wD->unk_94 = (u8 *)wD->unk_DC;
                        wD->unk_DC = t;
                        lbl_1_bss_716C0 = 0;
                    }
                    if (arg0->unk_24->unk_DC != 0) {
                        fn_1_46B4((u32)lbl_801A6410, (u32)((void *)arg0->unk_24->unk_DC), "memcard.c", 0x3de);
                        arg0->unk_24->unk_DC = 0;
                    }
                }
                fn_1_46B4((u32)lbl_801A6410, (u32)arg0->unk_24, "memcard.c", 0x3ec);
                arg0->unk_24 = 0;
                arg0->unk_2 = 0xff;
                arg0->unk_3 = 0xff;
                arg0->unk_4 = 0xff;
                arg0->unk_5 = 0xff;
                arg0->unk_6 = 0xff;
                arg0->unk_7 = 0;
                arg0->unk_8 = -1;
                arg0->unk_a = -1;
                arg0->unk_30 = 0;
                arg0->unk_34 = 0.0f;
                arg0->unk_38 = 0.0f;
                arg0->unk_2A &= ~4;
                lbl_1_bss_772C8[0] = 0;
                lbl_1_bss_718B8 = 1;
            } else {
                arg0->unk_3 = 0x18;
            }
            break;
        case -1:
            break;
        default:
            arg0->unk_3 = 0;
            break;
        }
        break;
    }

    case 24: {
        if (arg0->unk_24->unk_8 & 4) {
            s32 flag;
            if ((arg0->unk_24->unk_8 & 8) == 0) {
                arg0->unk_28 = 0x2d;
                arg0->unk_24->unk_8 |= 8;
                flag = 0;
            } else if (arg0->unk_28 > 0) {
                arg0->unk_28--;
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag != 0) {
                lbl_1_bss_718B4 = arg0->unk_24->unk_4;
                fn_1_46B4((u32)lbl_801A6410, (u32)(arg0->unk_24), "memcard.c", 0x3ec);
                arg0->unk_24 = 0;
                arg0->unk_2 = 0xff;
                arg0->unk_3 = 0xff;
                arg0->unk_4 = 0xff;
                arg0->unk_5 = 0xff;
                arg0->unk_6 = 0xff;
                arg0->unk_7 = 0;
                arg0->unk_8 = -1;
                arg0->unk_a = -1;
                arg0->unk_30 = 0;
                arg0->unk_34 = 0.0f;
                arg0->unk_38 = 0.0f;
                arg0->unk_2A &= ~4;
                lbl_1_bss_772C8[0] = 0;
                lbl_1_bss_718B8 = 1;
            }
        } else if (PAD_BIT(lbl_1_bss_9F8.unk_8, 8)) {
            lbl_1_bss_718B4 = arg0->unk_24->unk_4;
            fn_1_46B4((u32)lbl_801A6410, (u32)(arg0->unk_24), "memcard.c", 0x3ec);
            arg0->unk_24 = 0;
            arg0->unk_2 = 0xff;
            arg0->unk_3 = 0xff;
            arg0->unk_4 = 0xff;
            arg0->unk_5 = 0xff;
            arg0->unk_6 = 0xff;
            arg0->unk_7 = 0;
            arg0->unk_8 = -1;
            arg0->unk_a = -1;
            arg0->unk_30 = 0;
            arg0->unk_34 = 0.0f;
            arg0->unk_38 = 0.0f;
            arg0->unk_2A &= ~4;
            lbl_1_bss_772C8[0] = 0;
            lbl_1_bss_718B8 = 1;
        }
        break;
    }
    }
    if (arg0->unk_24 != 0) {
        lbl_1_bss_718B4 = arg0->unk_24->unk_4;
    }
}
#undef lbl_1_bss_9F8
/* fzgx:end fn_1_B03CC */

/* fzgx:begin fn_1_B1710 */
void fn_1_B1710(int unused, void *ptr) {
    *(u8 *)((u8 *)ptr + 3) = 0x3;
}
/* fzgx:end fn_1_B1710 */

/* fzgx:begin fn_1_B171C */
/* VIEWS */
#define lbl_1_rodata_4AE0 (*(const MemcardKind (*)[6])&lbl_1_rodata_4AE0)
/* VIEWS */
#define lbl_801A6410 (*(u32 *)&lbl_801A6410)
static inline void reset_context(CardContext *p) {
 p->unk_24 = 0;
 p->unk_2 = 255; p->unk_3 = 255; p->unk_4 = 255; p->unk_5 = 255; p->unk_6 = 255;
 p->unk_7 = 0; p->unk_8 = -1; p->unk_A = -1;
 p->unk_30 = 0; p->unk_34 = 0.0f; p->unk_38 = 0.0f;
 p->unk_2A &= ~4;
 lbl_1_bss_772C8[0] = 0; lbl_1_bss_718B8 = 1;
}

static char lbl_1_data_3CB50[4] = "8P";
void fn_1_B171C(void *arg0) {
 CardContext *p = arg0;
 u32 v0;
 OSReport("sl->submode : %d\n", p->unk_4);
 v0 = p->unk_4;
 if (v0 == 255) return;
 switch (v0) {
 default:
 OSReport("submode    : %d\n", v0);
 OSReport("submode req: %d\n", p->unk_3);
 OSPanic("memcard.c", 0x151C, "submode error!!\n");
 break;
 case 1: {
 u32 flags;
 Obj_1_bss_9F8 *input;
 p->unk_24->unk_8 &= ~0x200;
 flags = p->unk_24->unk_8;
 if (flags & 0x8000) p->unk_3 = 27;
 else {
 input = &lbl_1_bss_9F8;
 if ((input->unk_8 >> 8) & 1) p->unk_3 = 27;
 else if (((input->unk_8 >> 11) & 1) && !(flags & 2)) {
 if (p->unk_5 == 3 && p->unk_C != 0) {
 do {} while (CARDUnmount(p->unk_0) == -1);
 fn_1_46B4(lbl_801A6410, (u32)p->unk_C, "memcard.c", 0x152E);
 p->unk_7 = 0; p->unk_C = 0;
 { CardState *s = p->unk_24; s->unk_1C = 0; s->unk_18 = 0; }
 }
 if (p->unk_6 != 255) { p->unk_3 = p->unk_6; p->unk_6 = 255; }
 else p->unk_3 = p->unk_5;
 p->unk_8 = -1; p->unk_A = -1; p->unk_2A &= ~4;
 /* The alternate action resamples the live input rather than using the earlier snapshot. */
 } else if ((((Obj_1_bss_9F8 *)input)->unk_8 >> 10) & 1) {
 /* Fetch the current card-state pointer when processing the newly sampled action. */
 if (((CardContext *)p)->unk_24->unk_8 & 0x400) {
 p->unk_3 = 5; p->unk_24->unk_8 &= ~0x400; p->unk_24->unk_8 |= 0x200;
 p->unk_2A &= ~4; p->unk_2A |= 0x10;
 }
 }
 }
 lbl_1_bss_77309 = 0;
 break;
 }
 case 27:
 if (p->unk_24->unk_8 & 0x8000) p->unk_2 = 254;
 else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) p->unk_2 = 254;
 break;
 case 3:
 if (p->unk_1 == -127) {
 p->unk_24->unk_4 = p->unk_1; p->unk_3 = 1; break;
 }
 switch (p->unk_24->unk_4) {
 case -5: p->unk_24->unk_8 |= 2;
 case -128: case -3: case -2: p->unk_3 = 1; break;
 case -13:
 if (p->unk_24->unk_8 & 0x8000) { p->unk_2A |= 4; p->unk_2 = 254; }
 else if (lbl_801A66B4 == 5) p->unk_3 = 5;
 else { p->unk_24->unk_8 |= 0x400; p->unk_3 = 1; }
 break;
 case -1: break;
 case -6: case 0: p->unk_3 = 4; break;
 default: p->unk_3 = 0; break;
 }
 break;
 case 38: p->unk_3 = 3; break;
 case 4:
 switch (p->unk_24->unk_4) {
 case -5: p->unk_24->unk_8 |= 2;
 case -128: case -3: p->unk_3 = 1; break;
 case -6:
 if (p->unk_24->unk_8 & 0x8000) { p->unk_2A |= 4; p->unk_2 = 254; }
 else p->unk_3 = 5;
 break;
 case -13:
 if (p->unk_24->unk_8 & 0x8000) { p->unk_2A |= 4; p->unk_2 = 254; }
 else if (lbl_801A66B4 == 5) p->unk_3 = 5;
 else { p->unk_24->unk_8 |= 0x400; p->unk_3 = 1; }
 break;
 case -1: break;
 case 0: p->unk_3 = 7; break;
 default: p->unk_3 = 0; break;
 }
 break;
 case 5:
 if (p->unk_24->unk_4 != 0) {
 int done;
 if (!(p->unk_2A & 1)) { p->unk_28 = 12; p->unk_2A |= 1; done = 0; }
 else if (p->unk_28 > 0) { p->unk_28--; done = 0; }
 else done = 1;
 if (done) {
 if (p->unk_24->unk_4 == 2 || p->unk_24->unk_1 == 1) { p->unk_24->unk_4 = -126; p->unk_3 = 1; }
 else { p->unk_3 = 6; p->unk_24->unk_8 |= 0x200; }
 }
 }
 break;
 case 6:
 switch (p->unk_24->unk_4) {
 case -5: p->unk_24->unk_8 |= 2;
 case -128: case -3: p->unk_3 = 1; break;
 case -1: break;
 case 0: p->unk_3 = 22; p->unk_24->unk_8 &= ~0x200; break;
 default: p->unk_3 = 0; break;
 }
 break;
 case 22:
 if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) { p->unk_3 = 27; p->unk_24->unk_4 = -121; }
 break;
 case 7:
 switch (p->unk_24->unk_4) {
 case -128: case -3: p->unk_3 = 1; break;
 case -1: break;
 case 0: p->unk_3 = 25; break;
 default: p->unk_3 = 0; break;
 }
 break;
 case 25:
 switch (p->unk_24->unk_4) {
 case -128: case -3: p->unk_3 = 1; break;
 case -4: case -10: p->unk_2C++; break;
 case -1: break;
 case 0:
 if (p->unk_24->unk_E8 & 4) {
 const char *prefix;
 u32 size;
 u32 len;
 const char *game;
 char *end;
 game = fn_80019C48();
 prefix = lbl_1_rodata_4AE0[2].name;
 len = strlen(prefix);
 end = ((char *)strstr((void *)p->unk_24->unk_20, (void *)(".dat")));
 if (!strncmp(p->unk_24->unk_48, game, 4) &&
 !strncmp(p->unk_24->unk_4C, lbl_1_data_3CB50, 2) &&
 !strncmp(p->unk_24->unk_20, prefix, len) && end != 0) {
 FileEntry *entry;
 char *start;
 entry = &p->unk_24->unk_94[p->unk_2D];
 start = p->unk_24->unk_20 + len;
 size = end - start;
 strncpy((void *)entry->name, (void *)start, size); entry->name[size] = 0;
 entry->unk_1 = 2; entry->unk_24 = p->unk_24->unk_40; entry->unk_28 = p->unk_24->unk_44;
 p->unk_2D++;
 }
 }
 if (p->unk_24->unk_E8 & 0x10) {
 const char *prefix;
 u32 len;
 const char *game;
 char *end;
 game = fn_80019C48();
 prefix = lbl_1_rodata_4AE0[4].name;
 len = strlen(prefix);
 end = ((char *)strstr((void *)p->unk_24->unk_20, (void *)(".dat")));
 if (!strncmp(p->unk_24->unk_48, game, 4) &&
 !strncmp(p->unk_24->unk_4C, lbl_1_data_3CB50, 2) &&
 !strncmp(p->unk_24->unk_20, prefix, len) && end != 0) {
 u32 size;
 FileEntry *entry;
 char *start;
 entry = &p->unk_24->unk_94[p->unk_2D];
 start = p->unk_24->unk_20 + len;
 size = end - start;
 strncpy((void *)entry->name, (void *)start, size); entry->name[size] = 0;
 entry->unk_1 = 4; entry->unk_24 = p->unk_24->unk_40; entry->unk_28 = p->unk_24->unk_44;
 p->unk_2D++;
 }
 }
 if (p->unk_24->unk_E8 & 0x20) {
 const char *prefix;
 u32 len;
 const char *game;
 char *end;
 game = fn_80019C48();
 prefix = lbl_1_rodata_4AE0[5].name;
 len = strlen(prefix);
 end = ((char *)strstr((void *)p->unk_24->unk_20, (void *)(".dat")));
 if (!strncmp(p->unk_24->unk_48, game, 4) &&
 !strncmp(p->unk_24->unk_4C, lbl_1_data_3CB50, 2) &&
 !strncmp(p->unk_24->unk_20, prefix, len) && end != 0) {
 u32 size;
 FileEntry *entry;
 char *start;
 entry = &p->unk_24->unk_94[p->unk_2D];
 start = p->unk_24->unk_20 + len;
 size = end - start;
 strncpy((void *)entry->name, (void *)start, size); entry->name[size] = 0;
 entry->unk_1 = 5; entry->unk_24 = p->unk_24->unk_40; entry->unk_28 = p->unk_24->unk_44;
 p->unk_2D++;
 }
 }
 p->unk_2C++;
 break;
 default: p->unk_3 = 0; break;
 }
 if (p->unk_2C == 127 || p->unk_3 != 255) {
 *(u32 *)((u8 *)p->unk_24->unk_94 + p->unk_2D * 0x30 + 0x24) = 0;
 if (p->unk_3 == 255) p->unk_3 = 26;
 }
 break;
 case 26:
 if (p->unk_24->unk_8 & 4) {
 int done;
 if (!(p->unk_24->unk_8 & 8)) { p->unk_28 = 45; p->unk_24->unk_8 |= 8; done = 0; }
 else if (p->unk_28 > 0) { p->unk_28--; done = 0; }
 else done = 1;
 if (done) {
 lbl_1_bss_718B4 = p->unk_24->unk_4;
 fn_1_46B4(lbl_801A6410, (u32)p->unk_24, "memcard.c", 0x3EC);
 reset_context(p);
 }
 } else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
 lbl_1_bss_718B4 = p->unk_24->unk_4;
 fn_1_46B4(lbl_801A6410, (u32)p->unk_24, "memcard.c", 0x3EC);
 reset_context(p);
 }
 break;
 }
 if (p->unk_24 != 0) lbl_1_bss_718B4 = p->unk_24->unk_4;
}
/* fzgx:end fn_1_B171C */

/* fzgx:begin fn_1_B22AC */
static inline u32 parseHex(u8 *s, int n) {
    int i;
    u32 c;
    u32 sum = 0;

    for (i = 0; i < n; i++, s++) {
        c = *s;
        if (c >= 'A' && c <= 'F') {
            c -= 'A' - 10;
        } else {
            c -= '0';
        }
        sum += c << ((n - 1 - i) * 4);
    }
    return sum;
}

void fn_1_B22AC(MemcardCtx *ctx, s32 kind) {
    MemcardEntry *entry;
    const char *code;
    const MemcardKind *info;
    size_t len;
    char *p1;
    size_t n_2;
    char *p2;
    u32 value;
    size_t n;

    code = fn_80019C48();
    info = &lbl_1_rodata_4AE0[kind];
    len = strlen(info->name);
    p1 = ((char *)strstr((void *)ctx->unk_24->unk_20, ".dat"));
    p2 = ((char *)strstr((void *)ctx->unk_24->unk_20, ".000"));
    if (strncmp(ctx->unk_24->unk_48, code, 4) != 0) {
        return;
    }
    if (strncmp(ctx->unk_24->unk_4C, lbl_1_data_3CB50, 2) != 0) {
        return;
    }
    if (strncmp(ctx->unk_24->unk_20, info->name, len) != 0) {
        return;
    }
    if (p1 == NULL && p2 == NULL) {
        return;
    }

    entry = &ctx->unk_24->unk_94[ctx->unk_2D];
    if (p1 != NULL) {
        n = p1 - (ctx->unk_24->unk_20 + len);
        strncpy((void *)entry->name, (void *)(ctx->unk_24->unk_20 + len), n);
        entry->name[n] = 0;
    } else {
        n_2 = p2 - (ctx->unk_24->unk_20 + len);
        strncpy((void *)entry->name, (void *)(ctx->unk_24->unk_20 + len), n_2);
        entry->name[n_2] = 0;
    }
    entry->unk_1 = kind;
    value = info->unk_40;
    entry->unk_24 = (*(MemcardWork_B171C **)&ctx->unk_24)->unk_40;
    entry->unk_28 = ctx->unk_24->unk_44;
    ctx->unk_2D++;
    ctx->unk_24->unk_08 |= 0x20;
    ctx->unk_24->unk_08 |= 0x4;

    if (value == 0 && kind == 4) {
        ctx->unk_24->unk_B8 = parseHex((u8 *)entry->name, 5);
    } else if (value == 0 && kind == 5) {
        ctx->unk_24->unk_B8 = parseHex((u8 *)entry->name, 8);
    } else if (value == 0 && kind == 2) {
        ctx->unk_24->unk_B8 = 16040;
    } else {
        ctx->unk_24->unk_B8 = value;
    }

    ctx->unk_24->unk_0C = entry->unk_24;
    sprintf(ctx->unk_24->unk_98, "%s%s", info->name, entry->name);
    if (entry->unk_2C != 0) {
        fn_1_46B4(lbl_801A6410, entry->unk_2C, "memcard.c", 0x16f4);
        entry->unk_2C = 0;
    }
    entry->unk_2C = fn_1_4630((void *)lbl_801A6410, ctx->unk_24->unk_B8, "memcard.c", 0x16f7);
    if (ctx->unk_24->unk_DC != 0) {
        fn_1_46B4(lbl_801A6410, ctx->unk_24->unk_DC, "memcard.c", 0x16f9);
        ctx->unk_24->unk_DC = 0;
    }
    ctx->unk_24->unk_DC = fn_1_4630((void *)lbl_801A6410, ctx->unk_24->unk_0C, "memcard.c", 0x16fc);
}
/* fzgx:end fn_1_B22AC */

/* fzgx:begin fn_1_B2770 */
/* the sprintf format above (base + 0x713C) */

// fn_1_B2770: main_rel .text:0x000B2770 size 0xC

// Store byte 0x3 at offset 3 of the pointer argument

void fn_1_B2770(int unused, void *ptr) {
    *(u8 *)((u8 *)ptr + 3) = 0x3;
}
/* fzgx:end fn_1_B2770 */

/* fzgx:begin fn_1_B277C */
void fn_1_B277C(UnkCtx_1_B277C *ctx) {
    u8 *rec;
    u32 state = ctx->unk_04;

    if (state != 0xff) {
        switch (state) {
        default:
            OSReport("submode    : %d\n", state);
            OSReport("submode req: %d\n", ctx->unk_03);
            OSPanic("memcard.c", 0x1724, "submode error!!\n");
            break;
        case 1: {
            UnkWork_1_B277C *w;
            ctx->unk_24->unk_08 &= 0xfffffdff;
            w = ctx->unk_24;
            if ((w->unk_08 & 0x8000) != 0) {
                ctx->unk_03 = 0x1b;
            } else {
                Obj_1_bss_9F8 *s9 = &lbl_1_bss_9F8;
                u32 t9 = (u16)(s9->unk_8);
                if ((PAD_BIT(t9, 8)) != 0) {
                ctx->unk_03 = 0x1b;
            } else if ((PAD_BIT(t9, 11)) != 0 && (w->unk_08 & 2) == 0) {
                if (ctx->unk_05 == 3 && ctx->unk_0C != 0) {
                    s32 r;
                    do {
                        r = CARDUnmount(ctx->unk_00);
                    } while (r == -1);
                    fn_1_46B4(lbl_801A6410, ctx->unk_0C, "memcard.c", 0x1736);
                    ctx->unk_07 = 0;
                    ctx->unk_0C = 0;
                    {
                        UnkWork_1_B277C *wp = ctx->unk_24;
                        wp->unk_1C = 0;
                        wp->unk_18 = 0;
                    }
                }
                if (ctx->unk_06 != 0xff) {
                    ctx->unk_03 = ctx->unk_06;
                    ctx->unk_06 = 0xff;
                } else {
                    ctx->unk_03 = ctx->unk_05;
                }
                ctx->unk_08 = -1;
                ctx->unk_0A = -1;
                ctx->unk_2A &= ~4;
                if ((void *)ctx == &lbl_1_bss_716C8[0]) {
                    lbl_1_bss_718B1 = 0;
                } else if ((void *)ctx == &lbl_1_bss_716C8[1]) {
                    lbl_1_bss_718B1 = 1;
                }
            } else if (((s9->unk_8 >> 10) & 1) != 0) {
                UnkWork_1_B277C *w3 = ctx->unk_24;
                if ((w3->unk_08 & 0x400) != 0) {
                    ctx->unk_03 = 5;
                    ctx->unk_24->unk_08 &= 0xfffffbff;
                    ctx->unk_24->unk_08 |= 0x200;
                    ctx->unk_2A &= ~4;
                    ctx->unk_2A |= 0x10;
                }
            }
            }
            lbl_1_bss_77309 = 0;
            break;
        }
        case 27:
            ctx->unk_02 = 0xfe;
            break;
        case 3: {
            s8 v1 = ctx->unk_01;
            if (v1 == -0x7f) {
                ctx->unk_24->unk_04 = v1;
                ctx->unk_03 = 1;
            } else {
                UnkWork_1_B277C *w = ctx->unk_24;
                switch (w->unk_04) {
                case -5:
                    w->unk_08 |= 2;
                case -128:
                case -3:
                case -2:
                    ctx->unk_03 = 1;
                    break;
                case -13:
                    if ((w->unk_08 & 0x8000) != 0) {
                        ctx->unk_2A |= 4;
                        ctx->unk_02 = 0xfe;
                    } else if (lbl_801A66B4 == 5) {
                        ctx->unk_03 = 5;
                    } else {
                        w->unk_08 |= 0x400;
                        ctx->unk_03 = 1;
                    }
                    break;
                case -6:
                case 0:
                    ctx->unk_03 = 4;
                    break;
                case -1:
                    break;
                default:
                    ctx->unk_03 = 0;
                    break;
                }
            }
            break;
        }
        case 38:
            ctx->unk_03 = 3;
            break;
        case 4: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -5:
                w->unk_08 |= 2;
            case -128:
            case -3:
                ctx->unk_03 = 1;
                break;
            case -6:
                if ((w->unk_08 & 0x8000) != 0) {
                    ctx->unk_2A |= 4;
                    ctx->unk_02 = 0xfe;
                } else {
                    ctx->unk_03 = 5;
                }
                break;
            case -13:
                if ((w->unk_08 & 0x8000) != 0) {
                    ctx->unk_2A |= 4;
                    ctx->unk_02 = 0xfe;
                } else if (lbl_801A66B4 == 5) {
                    ctx->unk_03 = 5;
                } else {
                    w->unk_08 |= 0x400;
                    ctx->unk_03 = 1;
                }
                break;
            case 0:
                ctx->unk_03 = 7;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 5: {
            UnkWork_1_B277C *w = ctx->unk_24;
            if (w->unk_04 != 0) {
                s32 flag;
                if ((ctx->unk_2A & 1) == 0) {
                    ctx->unk_28 = 0x0c;
                    flag = 0;
                    ctx->unk_2A |= 1;
                } else {
                    s8 c = ctx->unk_28;
                    if (c > 0) {
                        ctx->unk_28 = c - 1;
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                }
                if (flag != 0) {
                    w = ctx->unk_24;
                    if (w->unk_04 == 2 || *((u8 *)w + 1) == 1) {
                        w->unk_04 = -0x7e;
                        ctx->unk_03 = 1;
                    } else {
                        ctx->unk_03 = 6;
                        ctx->unk_24->unk_08 |= 0x200;
                    }
                }
            }
            break;
        }
        case 6: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -5:
                w->unk_08 |= 2;
            case -128:
            case -3:
                ctx->unk_03 = 1;
                break;
            case 0:
                ctx->unk_03 = 0x16;
                ctx->unk_24->unk_08 &= 0xfffffdff;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 22: {
            UnkWork_1_B277C *w = ctx->unk_24;
            u32 v = w->unk_08;
            if ((v & 4) != 0) {
                s32 flag;
                if ((v & 8) == 0) {
                    ctx->unk_28 = 0x2d;
                    flag = 0;
                    ctx->unk_24->unk_08 |= 8;
                } else {
                    s8 c = ctx->unk_28;
                    if (c > 0) {
                        ctx->unk_28 = c - 1;
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                }
                if (flag != 0) {
                    ctx->unk_03 = 0x1b;
                }
            } else if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) != 0) {
                ctx->unk_03 = 0x1b;
            }
            ctx->unk_24->unk_04 = -0x79;
            break;
        }
        case 7: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -3:
                ctx->unk_03 = 1;
                break;
            case 0:
                ctx->unk_03 = 0x19;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 25:
        case 33: {
            UnkWork_1_B277C *w = ctx->unk_24;
            w->unk_B8 = 0xffffffff;
            w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -3:
                ctx->unk_03 = 1;
                break;
            case -10:
            case -4:
                ctx->unk_2C++;
                break;
            case 0:
                if (ctx->unk_2C < 0x7f) {
                    if ((ctx->unk_24->unk_E8 & 4) != 0) {
                        fn_1_B22AC((MemcardCtx *)ctx, 2);
                    }
                    if ((ctx->unk_24->unk_E8 & 0x10) != 0) {
                        fn_1_B22AC((MemcardCtx *)ctx, 4);
                    }
                    if ((ctx->unk_24->unk_E8 & 0x20) != 0) {
                        fn_1_B22AC((MemcardCtx *)ctx, 5);
                    }
                    ctx->unk_2C++;
                }
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            if (ctx->unk_2C >= 0x7f || ctx->unk_03 != 0xff) {
                w = ctx->unk_24;
                *(u32 *)(((((((((ctx->unk_2D * 0x30)))) + (((((0x24)))) + (((((u8 *)w->unk_94)))))))))) = 0;
                if (ctx->unk_03 == 0xff) {
                    ctx->unk_03 = 0x13;
                }
            }
            w = ctx->unk_24;
            if (w->unk_B8 != 0xffffffff) {
                ctx->unk_03 = 0xa;
            }
            break;
        }
        case 10: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -10:
            case -6:
            case -3:
                ctx->unk_03 = 1;
                if (ctx->unk_24->unk_04 == -6) {
                    lbl_1_bss_718B9 = 1;
                }
                break;
            case -4:
                ctx->unk_03 = 0x12;
                break;
            case 0:
                ctx->unk_03 = 0x0e;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 18: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -5:
                w->unk_08 |= 2;
            case -128:
            case -12:
            case -10:
            case -7:
            case -3:
                ctx->unk_03 = 1;
                break;
            case -4:
                if ((w->unk_08 & 0x100) != 0) {
                    ctx->unk_03 = 0x1f;
                } else {
                    ctx->unk_03 = 1;
                }
                break;
            case 0:
                ctx->unk_03 = 0x0a;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 31: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -6:
            case -3:
                ctx->unk_03 = 1;
                break;
            case 0:
                w->unk_04 = -4;
                ctx->unk_03 = 1;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 14: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -10:
            case -4:
            case -3:
                ctx->unk_03 = 1;
                break;
            case 0: {
                u8 *a;
                UnkWork_1_B277C *p2;
                ctx->unk_03 = 0x17;
                p2 = ctx->unk_24;
                a = p2->unk_94;
                p2->unk_94 = p2->unk_DC;
                p2->unk_DC = a;
                lbl_1_bss_716C0 = 1;
                break;
            }
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 23: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -14:
            case -11:
            case -10:
            case -4:
            case -3: {
                u8 *a;
                UnkWork_1_B277C *p2;
                ctx->unk_03 = 1;
                p2 = ctx->unk_24;
                a = p2->unk_94;
                p2->unk_94 = p2->unk_DC;
                p2->unk_DC = a;
                lbl_1_bss_716C0 = 0;
                break;
            }
            case 0: {
                u16 r;
                w = ctx->unk_24;
                r = fn_1_1563E8((u32)w->unk_94 + 2, w->unk_0C - 2);
                if (*(u16 *)ctx->unk_24->unk_94 != r ||
                    ((ctx->unk_24->unk_94)[2] == 5 &&
                     (ctx->unk_24->unk_94)[3] != ((const u8 *)lbl_1_rodata_4AE0)[0x1ba])) {
                    ctx->unk_03 = 0x21;
rec = ctx->unk_24->unk_DC + ctx->unk_2D * 0x30 - 0x30;
                    if (*(s16 *)&lbl_1_bss_960 != 1) {
                        rec[0] = 1;
                    } else {
                        fn_1_46B4(lbl_801A6410, *(u32 *)(rec + 0x2c), "memcard.c", 0x1933);
                        *(u32 *)(rec + 0x2c) = 0;
                        if (ctx->unk_24->unk_94 != 0) {
                            fn_1_46B4(lbl_801A6410, (u32)ctx->unk_24->unk_94, "memcard.c", 0x1936);
                            ctx->unk_24->unk_94 = 0;
                        }
                        fn_80008BEC(rec, 0, 0x30);
                        ctx->unk_2D--;
                    }
                    lbl_1_bss_718B9 = 1;
                } else {
((u8 *)ctx->unk_24->unk_DC)[ctx->unk_2D * 0x30 - 0x30] = 0;
                    ctx->unk_03 = 8;
                }
                {
                    u8 *a;
                    UnkWork_1_B277C *p2;
                    p2 = ctx->unk_24;
                    a = p2->unk_94;
                    p2->unk_94 = p2->unk_DC;
                    p2->unk_DC = a;
                    lbl_1_bss_716C0 = 0;
                }
                break;
            }
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 8: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -5:
                w->unk_08 |= 2;
            case -128:
            case -10:
            case -3:
                ctx->unk_03 = 1;
                break;
            case -4:
            case 0:
                ctx->unk_03 = 9;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 9: {
            UnkBuf8_1_B277C buf8;
            UnkOut16_1_B277C out;
            UnkHdr10_1_B277C hdr10;

            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -6:
            case -3:
                ctx->unk_03 = 1;
                break;
            case 0: {
                u8 *dc;
                rec = w->unk_94 + ctx->unk_2D * 0x30 - 0x30;
                ctx->unk_03 = 0x21;
                dc = ctx->unk_24->unk_DC;
                if (*(s16 *)&lbl_1_bss_960 == 2) {
                    if (rec[1] == 2) {
                        hdr10.m0 = dc[0x2060];
                        hdr10.m1 = dc[0x2061];
                        hdr10.m2 = dc[0x2084];
                        hdr10.m3 = dc[0x2085];
                        hdr10.m4 = *(u16 *)(dc + 0x2086);
                        hdr10.m5 = dc[0x2064];
                        hdr10.m6 = dc[0x2065];
                        hdr10.m7 = dc[0x2066];
                        hdr10.m8 = dc[0x2067];
                        if (dc != 0) {
                            fn_1_46B4(lbl_801A6410, (u32)dc, "memcard.c", 0x19aa);
                            ctx->unk_24->unk_DC = 0;
                        }
                        if (*(u32 *)(rec + 0x2c) != 0) {
                            fn_1_46B4(lbl_801A6410, *(u32 *)(rec + 0x2c), "memcard.c", 0x19ae);
                            *(u32 *)(rec + 0x2c) = 0;
                        }
                        *(u32 *)(rec + 0x2c) = fn_1_4630((void *)lbl_801A6410, 0x0a, "memcard.c", 0x19b1);
                        fn_80008BA8((void *)(*(u32 *)(rec + 0x2c)), (void *)((u32)&hdr10), 0x0a);
                    } else if (rec[1] == 5) {
                        if (*(u32 *)(rec + 0x2c) != 0) {
                            fn_1_F4810(dc + 0x2060, &out.m0, &out.m5, &out.m2, &out.m3,
                                       &out.m4, &out.m1, &out.m9, &out.m13);
                            buf8.m0 = out.m0;
                            buf8.m1 = out.m3;
                            buf8.m2 = out.m4;
                            buf8.m3 = out.m5;
                            buf8.m4 = out.m9;
                            buf8.m5 = out.m13;
                            buf8.m6 = out.m14;
                            buf8.m7 = out.m15;
                            if (ctx->unk_24->unk_DC != 0) {
                                fn_1_46B4(lbl_801A6410, (u32)ctx->unk_24->unk_DC, "memcard.c", 0x19cb);
                                ctx->unk_24->unk_DC = 0;
                            }
                            fn_1_46B4(lbl_801A6410, *(u32 *)(rec + 0x2c), "memcard.c", 0x19ce);
                            *(u32 *)(rec + 0x2c) = 0;
                        }
                        *(u32 *)(rec + 0x2c) = fn_1_4630((void *)lbl_801A6410, 8, "memcard.c", 0x19d1);
                        fn_80008BA8((void *)(*(u32 *)(rec + 0x2c)), (void *)((u32)&buf8), 8);
                    }
                } else {
                    fn_80008BA8((void *)(*(u32 *)(rec + 0x2c)), (void *)((u32)(dc + 0x2060)), ctx->unk_24->unk_B8);
                    if (ctx->unk_24->unk_DC != 0) {
                        fn_1_46B4(lbl_801A6410, (u32)ctx->unk_24->unk_DC, "memcard.c", 0x19d9);
                        ctx->unk_24->unk_DC = 0;
                    }
                }
                break;
            }
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 19: {
            UnkWork_1_B277C *w = ctx->unk_24;
            switch (w->unk_04) {
            case -128:
            case -6:
            case -3:
                ctx->unk_03 = 1;
                break;
            case 0:
                ctx->unk_03 = 0x1a;
                break;
            case -1:
                break;
            default:
                ctx->unk_03 = 0;
                break;
            }
            break;
        }
        case 26: {
            UnkWork_1_B277C *w = ctx->unk_24;
            u32 v = w->unk_08;
            if ((v & 4) != 0) {
                s32 flag;
                if ((v & 8) == 0) {
                    ctx->unk_28 = 0x2d;
                    flag = 0;
                    ctx->unk_24->unk_08 |= 8;
                } else {
                    s8 c = ctx->unk_28;
                    if (c > 0) {
                        ctx->unk_28 = c - 1;
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                }
                if (flag != 0) {
                    u32 t4 = ctx->unk_24->unk_04;
                    lbl_1_bss_718B4 = t4;
                    fn_1_46B4(lbl_801A6410, (u32)(*(UnkWork_1_B277C * *)&ctx->unk_24), "memcard.c", 0x3ec);
                    ctx->unk_24 = 0;
                    ctx->unk_02 = 0xff;
                    ctx->unk_03 = 0xff;
                    ctx->unk_04 = 0xff;
                    ctx->unk_05 = 0xff;
                    ctx->unk_06 = 0xff;
                    ctx->unk_07 = 0;
                    ctx->unk_08 = -1;
                    ctx->unk_0A = -1;
                    ctx->unk_30 = 0;
                    ctx->unk_34 = 0.0f;
                    ctx->unk_38 = 0.0f;
                    ctx->unk_2A &= ~4;
                    lbl_1_bss_772C8[0] = 0;
                    lbl_1_bss_718B8 = 1;
                }
            } else if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) != 0) {
                lbl_1_bss_718B4 = ctx->unk_24->unk_04;
                fn_1_46B4(lbl_801A6410, (u32)(*(UnkWork_1_B277C * *)&ctx->unk_24), "memcard.c", 0x3ec);
                ctx->unk_24 = 0;
                ctx->unk_02 = 0xff;
                ctx->unk_03 = 0xff;
                ctx->unk_04 = 0xff;
                ctx->unk_05 = 0xff;
                ctx->unk_06 = 0xff;
                ctx->unk_07 = 0;
                ctx->unk_08 = -1;
                ctx->unk_0A = -1;
                ctx->unk_30 = 0;
                ctx->unk_34 = 0.0f;
                ctx->unk_38 = 0.0f;
                ctx->unk_2A &= ~4;
                lbl_1_bss_772C8[0] = 0;
                lbl_1_bss_718B8 = 1;
            }
            break;
        }
        }
        if (ctx->unk_24 != 0) {
            lbl_1_bss_718B4 = ctx->unk_24->unk_04;
        }
    }
}

#undef lbl_801A6410
#undef lbl_1_rodata_4AE0
/* fzgx:end fn_1_B277C */

/* fzgx:begin fn_1_B38F4 */
void fn_1_B38F4(int unused, void *ptr) {
    *(u8 *)((u8 *)ptr + 3) = 0x3;
}
/* fzgx:end fn_1_B38F4 */

/* fzgx:begin fn_1_B3900 */
/* VIEWS */
/* VIEWS */
#define lbl_801A6410 (*(u32 *)&lbl_801A6410)
void fn_1_B3900(u8 *arg0) {
    Obj_1_bss_9F8 *global;
    u8 *state;
    u32 f;

    if (((arg0)[4]) == 0xFF) {
        return;
    }

    switch (((arg0)[4])) {
    default:
        OSReport("submode    : %d\n", ((arg0)[4]));
        OSReport("submode req: %d\n", ((arg0)[3]));
        OSPanic("memcard.c", 0x1A40, "submode error!!\n");
        break;

    case 1: {
        state = *(u8 **)(arg0 + 0x24);
        *(u32 *)(state + 8) &= ~0x200;
        state = *(u8 **)(arg0 + 0x24);
        f = *(u32 *)(state + 8);
        if (f & 0x8000) {
            arg0[3] = 0x1E;
        } else {
            global = (Obj_1_bss_9F8 *)(u32)&lbl_1_bss_9F8;
            if (((u16)global->unk_8 >> 8) & 1) {
                arg0[3] = 0x1E;
        } else if ((((u16)global->unk_8 >> 11) & 1) && !(f & 2)) {
            if (((arg0)[5]) == 3 && *(u32 *)(arg0 + 0xC) != 0) {
                while (CARDUnmount(((arg0)[0])) == -1) {
                }
                fn_1_46B4(lbl_801A6410, *(u32 *)(arg0 + 0xC), "memcard.c", 0x1A52);
                arg0[7] = 0;
                *(u32 *)(arg0 + 0xC) = 0;
                state = *(u8 **)(arg0 + 0x24);
                *(u32 *)(state + 0x1C) = 0;
                *(u32 *)(state + 0x18) = 0;
            }
            if (((arg0)[6]) != 0xFF) {
                arg0[3] = ((arg0)[6]);
                arg0[6] = 0xFF;
            } else {
                arg0[3] = ((arg0)[5]);
            }
            {
                *(s16 *)(arg0 + 8) = -1;
            *(s16 *)(arg0 + 0xA) = -1;
            arg0[0x2A] &= ~4;
            if ((void *)arg0 == &lbl_1_bss_716C8[0]) {
                lbl_1_bss_718B1 = 0;
            } else if ((void *)arg0 == &lbl_1_bss_716C8[1]) {
                lbl_1_bss_718B1 = 1;
            }
            }
        } else if (((((Obj_1_bss_9F8 *)(u32)&lbl_1_bss_9F8)->unk_8 >> 10) & 1) && (*(u32 *)((state = (u8 *)*(u32 *)(arg0 + 0x24)) + 8) & 0x400)) {
            arg0[3] = 5;
            *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) &= ~0x400;
            *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) |= 0x200;
            arg0[0x2A] &= ~4;
            arg0[0x2A] |= 0x10;
        }
        }
        lbl_1_bss_77309 = 0;
        break;
    }

    case 0x1E:
        if (*(u32 *)(*(u8 **)(arg0 + 0x24) + 8) & 0x8000) {
            arg0[2] = 0xFE;
        } else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
            arg0[2] = 0xFE;
        }
        break;

    case 3:
        if ((s8)((arg0)[1]) == -0x7F) {
            *(u32 *)(*(u8 **)(arg0 + 0x24) + 4) = (s8)((arg0)[1]);
            arg0[3] = 1;
        } else {
            switch (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4)) {
            case -5:
                *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) |= 2;
                /* fallthrough */
            case -0x80:
            case -3:
            case -2:
                arg0[3] = 1;
                break;
            case -0xD:
                if (*(u32 *)(*(u8 **)(arg0 + 0x24) + 8) & 0x8000) {
                    arg0[0x2A] |= 4;
                    arg0[2] = 0xFE;
                } else if (lbl_801A66B4 == 5) {
                    arg0[3] = 5;
                } else {
                    *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) |= 0x400;
                    arg0[3] = 1;
                }
                break;
            case -6:
            case 0:
                arg0[3] = 4;
                break;
            case -1:
                break;
            default:
                arg0[3] = 0;
                break;
            }
        }
        break;

    case 0x26:
        arg0[3] = 3;
        break;

    case 4: {
        u8 *state = *(u8 **)(arg0 + 0x24);
        switch (*(s32 *)(state + 4)) {
        case -5:
            *(u32 *)(state + 8) |= 2;
            /* fallthrough */
        case -3:
        case -0x80:
            arg0[3] = 1;
            break;
        case -6:
            if (*(u32 *)(state + 8) & 0x8000) {
                arg0[0x2A] |= 4;
                arg0[2] = 0xFE;
            } else {
                arg0[3] = 5;
            }
            break;
        case -0xD:
            f = *(u32 *)(state + 8);
            if (f & 0x8000) {
                arg0[0x2A] |= 4;
                arg0[2] = 0xFE;
            } else if (lbl_801A66B4 == 5) {
                arg0[3] = 5;
            } else {
                *(u32 *)(state + 8) = f | 0x400;
                arg0[3] = 1;
            }
            break;
        case 0:
            arg0[3] = 7;
            break;
        case -1:
            break;
        default:
            arg0[3] = 0;
            break;
        }
        break;
    }

    case 5:
        if (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4) != 0) {
            s32 done;
            if (!(((arg0)[0x2A]) & 1)) {
                done = 0;
                arg0[0x28] = 0xC;
                arg0[0x2A] |= 1;
            } else {
                u8 c = ((arg0)[0x28]);
                if ((s8)c > 0) {
                    done = 0;
                    arg0[0x28] = c - 1;
                } else {
                    done = 1;
                }
            }
            if (done != 0) {
                if (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4) == 2 || *(*(u8 **)(arg0 + 0x24) + 1) == 1) {
                    *(u32 *)(*(u8 **)(arg0 + 0x24) + 4) = -0x7E;
                    arg0[3] = 1;
                } else {
                    arg0[3] = 6;
                    *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) |= 0x200;
                }
            }
        }
        break;

    case 6:
        switch (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4)) {
        case -5:
            *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) |= 2;
            /* fallthrough */
        case -3:
        case -0x80:
            arg0[3] = 1;
            break;
        case 0:
            arg0[3] = 7;
            *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) &= ~0x200;
            break;
        case -1:
            break;
        default:
            arg0[3] = 0;
            break;
        }
        break;

    case 7:
        switch (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4)) {
        case -0x80:
        case -3:
            arg0[3] = 1;
            break;
        case 0:
            arg0[3] = 0x1C;
            break;
        case -1:
            break;
        default:
            arg0[3] = 0;
            break;
        }
        break;

    case 0x1C:
        switch (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4)) {
        case -5:
            *(u32 *)(*(u8 **)(arg0 + 0x24) + 8) |= 2;
            /* fallthrough */
        case -0x80:
        case -0xA:
        case -4:
        case -3:
            arg0[3] = 1;
            break;
        case -1:
            break;
        case 0:
            arg0[3] = 0x13;
            break;
        default:
            arg0[3] = 0;
            break;
        }
        break;

    case 0x13:
        switch (*(s32 *)(*(u8 **)(arg0 + 0x24) + 4)) {
        case -0x80:
        case -6:
        case -3:
            arg0[3] = 1;
            break;
        case 0:
            arg0[3] = 0x1D;
            break;
        case -1:
            break;
        default:
            arg0[3] = 0;
            break;
        }
        break;

    case 0x1D:
        if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
            lbl_1_bss_718B4 = *(u32 *)(*(u8 **)(arg0 + 0x24) + 4);
            fn_1_46B4(lbl_801A6410, *(u32 *)(arg0 + 0x24), "memcard.c", 0x3EC);
            *(u32 *)(arg0 + 0x24) = 0;
            arg0[2] = 0xFF;
            arg0[3] = 0xFF;
            arg0[4] = 0xFF;
            arg0[5] = 0xFF;
            arg0[6] = 0xFF;
            arg0[7] = 0;
            *(s16 *)(arg0 + 8) = -1;
            *(s16 *)(arg0 + 0xA) = -1;
            *(u32 *)(arg0 + 0x30) = 0;
            *(f32 *)(arg0 + 0x34) = 0.0f;
            *(f32 *)(arg0 + 0x38) = 0.0f;
            arg0[0x2A] &= ~4;
            lbl_1_bss_772C8[0] = 0;
            lbl_1_bss_718B8 = 1;
        }
        break;
    }

    f = *(u32 *)(arg0 + 0x24);
    if (f != 0) {
        lbl_1_bss_718B4 = *(u32 *)(f + 4);
    }
}
/* fzgx:end fn_1_B3900 */

/* fzgx:begin fn_1_B40B4 */
void fn_1_B40B4(int unused, void *ptr) {
    *(u8 *)((u8 *)ptr + 3) = 0x3;
}
/* fzgx:end fn_1_B40B4 */

/* fzgx:begin fn_1_B40C0 */
void fn_1_B40C0(void *arg0)
{
    u8 *p_jumptable_1_data_3CD44;
    B40State *s = arg0;
    u8 *end;
    u32 suffix_len;
    B40Entry *entry;
    const char *game;
    u32 len;
    s32 done;
    u32 i;
    p_jumptable_1_data_3CD44 = jumptable_1_data_3CD44;
    for (;;) {
        if (s->unk_4 == 255)
            return;
        switch (s->unk_4) {
        default:
            OSReport("submode    : %d\n", s->unk_4);
            OSReport("submode req: %d\n", s->unk_3);
            OSPanic("memcard.c", 0x1bbe, "submode error!!\n");
            break;
        case 1:
            s->unk_24->unk_8 &= ~0x200;
            if ((done = s->unk_24->unk_8) & 0x8000) {
                s->unk_3 = 27;
            /* Sample controller input independently of work-state writes. */
            } else if (((((B40InputBits *)&lbl_1_bss_9F8.unk_8)->a.value >> 8) & 1)) {
                s->unk_3 = 27;
            } else if (((((B40InputBits *)&lbl_1_bss_9F8.unk_8)->b.value >> 11) & 1) && !(done & 2)) {
                if (s->unk_5 == 3 && s->unk_C != 0) {
                    while (CARDUnmount(s->unk_0) == -1) {}
                    fn_1_46B4(lbl_801A6410, s->unk_C, "memcard.c", 0x1bd0);
                    s->unk_7 = 0;
                    s->unk_C = 0;
                    { B40Work *w = s->unk_24; w->unk_1C = 0; w->unk_18 = 0; }
                }
                if (s->unk_6 != 255) {
                    s->unk_3 = s->unk_6;
                    s->unk_6 = 255;
                } else {
                    s->unk_3 = s->unk_5;
                }
                s->unk_8 = -1;
                s->unk_A = -1;
                s->unk_2A &= ~4;
            /* Sample the input and work pointer again for the format action. */
            } else if ((((((B40InputBits *)&lbl_1_bss_9F8.unk_8)->c.value >> 10) & 1)) && ((*(B40Work **)&s->unk_24)->unk_8 & 0x400)) {
                s->unk_3 = 5;
                s->unk_24->unk_8 &= ~0x400;
                s->unk_24->unk_8 |= 0x200;
                s->unk_2A &= ~4;
                s->unk_2A |= 0x10;
            }
            lbl_1_bss_77309 = 0;
            break;
        case 27:
            if (s->unk_24->unk_8 & 0x8000) {
                s->unk_2 = 254;
            } else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
                s->unk_2 = 254;
            }
            break;
        case 3:
            if (s->unk_1 == -127) {
                s->unk_24->unk_4 = s->unk_1;
                s->unk_3 = 1;
                break;
            }
            switch (s->unk_24->unk_4) {
            case -1: break;
            case -5:
                s->unk_24->unk_8 |= 2;
            case -128: case -3: case -2:
                s->unk_3 = 1;
                break;
            case -13:
                if (s->unk_24->unk_8 & 0x8000) {
                    s->unk_2A |= 4;
                    s->unk_2 = 254;
                } else if (lbl_801A66B4 == 5) {
                    s->unk_3 = 5;
                } else {
                    s->unk_24->unk_8 |= 0x400;
                    s->unk_3 = 1;
                }
                break;
            case 0: case -6:
                s->unk_3 = 4;
                break;
            default:
                s->unk_3 = 0;
                break;
            }
            break;
        case 38:
            s->unk_3 = 3;
            break;
        case 4:
            switch (s->unk_24->unk_4) {
            case -1: break;
            case -5: s->unk_24->unk_8 |= 2;
            case -128: case -3:
                s->unk_3 = 1;
                break;
            case -6:
                if (s->unk_24->unk_8 & 0x8000) {
                    s->unk_2A |= 4;
                    s->unk_2 = 254;
                } else {
                    s->unk_3 = 5;
                }
                break;
            case -13:
                if (s->unk_24->unk_8 & 0x8000) {
                    s->unk_2A |= 4;
                    s->unk_2 = 254;
                } else if (lbl_801A66B4 == 5) {
                    s->unk_3 = 5;
                } else {
                    s->unk_24->unk_8 |= 0x400;
                    s->unk_3 = 1;
                }
                break;
            case 0: s->unk_3 = 7; break;
            default: s->unk_3 = 0; break;
            }
            break;
        case 5:
            if (s->unk_24->unk_4 != 0) {
                if (!(s->unk_2A & 1)) {
                    s->unk_28 = 12;
                    s->unk_2A |= 1;
                    done = 0;
                } else if (s->unk_28 > 0) {
                    s->unk_28--;
                    done = 0;
                } else {
                    done = 1;
                }
                if (done) {
                    if (s->unk_24->unk_4 == 2 || s->unk_24->unk_1 == 1) {
                        s->unk_24->unk_4 = -126;
                        s->unk_3 = 1;
                    } else {
                        s->unk_3 = 6;
                        s->unk_24->unk_8 |= 0x200;
                    }
                }
            }
            break;
        case 6:
            switch (s->unk_24->unk_4) {
            case -1: break;
            case -5: s->unk_24->unk_8 |= 2;
            case -128: case -3: s->unk_3 = 1; break;
            case 0:
                s->unk_3 = 22;
                s->unk_24->unk_8 &= ~0x200;
                break;
            default: s->unk_3 = 0; break;
            }
            break;
        case 22:
            if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
                s->unk_3 = 27;
                s->unk_24->unk_4 = -121;
            }
            break;
        case 7:
            switch (s->unk_24->unk_4) {
            case -1: break;
            case -128: case -3: s->unk_3 = 1; break;
            case 0: s->unk_3 = 35; break;
            default: s->unk_3 = 0; break;
            }
            break;
        case 35:
            switch (s->unk_24->unk_4) {
            case -1: break;
            case -128: case -3: s->unk_3 = 1; break;
            case -4: case -10: s->unk_2C++; break;
            case 0:
                game = fn_80019C48();
                end = ((u8 *)strstr((void *)((u8 *)&s->unk_24->unk_20), ".dat"));
                if (strncmp((char *)s->unk_24->unk_20.gameName, game, 4) == 0 &&
                    strncmp((char *)s->unk_24->unk_20.company, lbl_1_data_3CB50, 2) == 0) {
                    for (i = 0; i < 127; i++) {
                        entry = &s->unk_24->unk_94[i];
                        if (entry != 0 && entry->unk_0 != 0) {
                            len = ((u32)strlen(entry->unk_8));
                            suffix_len = end - ((u8 *)s->unk_24 + 0x20 + len);
                            if (strncmp((char *)&s->unk_24->unk_20, entry->unk_8, len) == 0) {
                                if (entry->unk_C[0] == 0) {
                                    entry->unk_2C = 1;
                                } else if (strncmp((char *)entry->unk_C, (char *)s->unk_24 + 0x20 + len, suffix_len) == 0) {
                                    entry->unk_2C = 1;
                                }
                            }
                        }
                    }
                }
                done = 1;
                for (i = 0; i < 127; i++) {
                    entry = &s->unk_24->unk_94[i];
                    if (entry->unk_0 != 0 && entry->unk_2C == 0) {
                        done = 0;
                    }
                }
                s->unk_2C++;
                if (done) {
                    s->unk_2C = 127;
                    s->unk_3 = 255;
                }
                break;
            default: s->unk_3 = 0; break;
            }
            if (s->unk_3 != 1) {
                if (s->unk_2C == 127 || s->unk_3 != 255) {
                    if (s->unk_3 == 255)
                        s->unk_3 = 34;
                } else if (s->unk_4 == 35 && s->unk_24->unk_4 == 0) {
                    s->unk_24->unk_4 = CARDGetStatus(s->unk_0, s->unk_2C, (CARDStat *)&s->unk_24->unk_20);
                    if (s->unk_2C == 126)
                        s->unk_24->unk_2 = 0;
                    continue;
                }
            }
            break;
        case 34:
            if (s->unk_24->unk_8 & 4) {
                if (!(s->unk_24->unk_8 & 8)) {
                    s->unk_28 = 45;
                    s->unk_24->unk_8 |= 8;
                    done = 0;
                } else if (s->unk_28 > 0) {
                    s->unk_28--;
                    done = 0;
                } else {
                    done = 1;
                }
                if (done) {
                    lbl_1_bss_718B4 = s->unk_24->unk_4;
                    fn_1_46B4(lbl_801A6410, (u32)s->unk_24, "memcard.c", 0x3ec);
                    s->unk_24 = 0;
                    s->unk_2 = 255;
                    s->unk_3 = 255;
                    s->unk_4 = 255;
                    s->unk_5 = 255;
                    s->unk_6 = 255;
                    s->unk_7 = 0;
                    s->unk_8 = -1;
                    s->unk_A = -1;
                    s->unk_30 = 0;
                    s->unk_34 = 0.0f;
                    s->unk_38 = 0.0f;
                    s->unk_2A &= ~4;
                    lbl_1_bss_772C8[0] = 0;
                    lbl_1_bss_718B8 = 1;
                }
            } else if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
                lbl_1_bss_718B4 = s->unk_24->unk_4;
                fn_1_46B4(lbl_801A6410, (u32)s->unk_24, "memcard.c", 0x3ec);
                s->unk_24 = 0;
                s->unk_2 = 255;
                s->unk_3 = 255;
                s->unk_4 = 255;
                s->unk_5 = 255;
                s->unk_6 = 255;
                s->unk_7 = 0;
                s->unk_8 = -1;
                s->unk_A = -1;
                s->unk_30 = 0;
                s->unk_34 = 0.0f;
                s->unk_38 = 0.0f;
                s->unk_2A &= ~4;
                lbl_1_bss_772C8[0] = 0;
                lbl_1_bss_718B8 = 1;
            }
            break;
        }
        break;
    }
    if (s->unk_24 != 0)
        lbl_1_bss_718B4 = s->unk_24->unk_4;
}
#undef lbl_801A6410
/* fzgx:end fn_1_B40C0 */

/* fzgx:begin fn_1_B4AC0 */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
#define lbl_1_bss_716C8 (*(u8 *)&lbl_1_bss_716C8)
#define lbl_1_bss_71810 (*(u8 *)&lbl_1_bss_71810)
#define lbl_1_bss_718B2 (*(u8 *)&lbl_1_bss_718B2)
#define lbl_1_bss_772C8 (*(u8 *)&lbl_1_bss_772C8)
/* VIEWS */
#define lbl_1_bss_D58 ((u8 *)&lbl_1_bss_D58)
#define lbl_801A6410 (*(u32 *)&lbl_801A6410)
/* WARNING: compiler-diff device, not original code */
#pragma opt_loop_invariants off

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off


/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

/* card in slot `chan` is usable (ready, or busy) */

static inline s32 fn_1_B4AC0_cardReady(s32 chan) {
    fn_1_B4AC0_Channel *c = &((fn_1_B4AC0_Channel *)&lbl_1_bss_716C8)[chan];
    if ((s8)c->unk_1 == 0 || (s8)c->unk_1 == -1) {
        return 1;
    }
    return 0;
}

void fn_1_B4AC0(void) {

    s32 v1;
    fn_1_B4AC0_Channel *v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v7;
    u32 v8;
    u32 unk_1;
    s32 v12;
    u32 unk_2;
    u8 v15;
    u32 v16;
    u32 v17;
    u8 v18;
    fn_1_B4AC0_Channel *v20;
    /* WARNING: compiler-diff device, not original code */
    struct { u32 value; } v21;
    u32 v22;
    u32 v23;
    f32 v24;
    u8 v25;
    u32 v26;
    u32 v27;
    u32 v28;
    u8 v29;
    u8 v30;
    u32 v31;
    u8 v32;
    struct { u32 a[2]; } loc_8;
    /* frame */
    s32 t0;
    u32 t1;
    u32 t2;
    s32 t3;
    s32 t8;
    u32 t12;
    u32 t13;
    s32 t14;
    v2 = (fn_1_B4AC0_Channel *)(&lbl_1_bss_716C8);
    v1 = 0;
    do {
    t0 = CARDProbeEx((s32)((void *)v1), (s32 *)0, (s32 *)&loc_8);
    v2->unk_1 = t0;
    if (v2->unk_1 == 0 && (s32)loc_8.a[0] != 8192) {
    v2->unk_1 = -127;
    }
    v3 = (u8)v2->unk_2B;
    if ((s8)v3 != v2->unk_1) {
    if ((s8)v3 == 0) {
    v2->unk_3C = -1;
    v2->unk_40 = -1;
    }
    v2->unk_2B = v2->unk_1;
    }
    v1++;
    v2++;
    } while (v1 < 2);
    v4 = v3;
    if ((s8)*(u8 *)((u8 *)(((u8 *)&lbl_1_bss_716C8)) + 1) == 0 || (s8)*(u8 *)((u8 *)(((u8 *)&lbl_1_bss_716C8)) + 1) == -1) {
    v4 = 1;
    } else {
    v4 = 0;
    }
    v5 = fn_1_B4AC0_cardReady(1);
    if (v4 == 0 && lbl_1_bss_718B1 == 0) {
    lbl_1_bss_718B1 = 5;
    }
    if (v5 == 0 && lbl_1_bss_718B1 == 1) {
    lbl_1_bss_718B1 = 5;
    }
    {
    typedef struct { u8 high:4; u8 low:4; } InputBits;
    lbl_1_bss_77309 = 0;
    v22 = lbl_1_bss_718B0;
    if (v22 == 255) {
    v7 = (u32)lbl_1_bss_D58;
    v22 = *(u16 *)(v7 + 8);
    v8 = 0;
    v8 = (v8 & ~0xFU) | (v22 & 0xF);
    lbl_1_bss_77309 = v8;
    lbl_1_bss_77309 = ((v22 >> 4) & 0xF0) | (lbl_1_bss_77309 & ~0xF0U);
    v8 = *(u16 *)(v7 + 10) & 0xF;
    } else {
    v12 = v22 * 20;
    v7 = (u32)&lbl_1_bss_9F8;
    v22 = (v7 + 8);
    v22 = *(u16 *)(v22 + v12);
    v7 = (v7 + v12);
    v8 = 0;
    v8 = (v8 & ~0xFU) | (v22 & 0xF);
    lbl_1_bss_77309 = v8;
    lbl_1_bss_77309 = ((v22 >> 4) & 0xF0) | (lbl_1_bss_77309 & ~0xF0U);
    v8 = *(u16 *)(v7 + 10) & 0xF;
    }
    if (v8 != 0) {
    ((InputBits *)(&lbl_1_bss_77309))->low = v8;
    }
    }
    v15 = lbl_1_bss_718B2;
    v16 = v7;
    v17 = v8;
    if (v15 != 255) {
    if (v15 == 2) {
    v18 = lbl_1_bss_718B1;
    if (v18 == 0 || v18 == 1) {
    lbl_1_bss_718B2 = v18;
    } else {
    lbl_1_bss_718B2 = 0;
    }
    v26 = (u32)&lbl_1_bss_71810;
    lbl_1_bss_77308 = 0;
    ((fn_1_B4AC0_Channel *)v26)->unk_2A &= 0xFE;
    }
    fn_1_AAB98();
    if (lbl_1_bss_718B2 != 255) return;
    }
    v20 = (fn_1_B4AC0_Channel *)(&lbl_1_bss_716C8);
    v21.value = 0;
    do {
    v25 = v20->unk_2;
    v26 = v16;
    v27 = v17;
    if (v25 != 255) {
    v28 = (u32)lbl_1_data_3C650[v25];
    v26 = (u32)v20;
    t2 = ((fn_1_B4AC0_Fn0)v28)(v26);
    v26 = t2;
    if (v20->unk_2 == 254) {
    if (v20->unk_C != 0) {
    do {
    v26 = v20->unk_0;
    t3 = CARDUnmount((s32)((void *)v26));
    v26 = t3;
    } while ((s32)v26 == -1);
    v27 = v20->unk_C;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 968;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v20->unk_7 = 0;
    v20->unk_C = 0;
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_1C = 0;
    ((fn_1_B4AC0_Detail *)v26)->unk_18 = 0;
    }
    v26 = v20->unk_24;
    if ((((fn_1_B4AC0_Detail *)v26)->unk_8 & 0x80) != 0) {
    v20->unk_3C = (((fn_1_B4AC0_Detail *)v26)->unk_10 / 8192);
    v26 = v20->unk_24;
    v20->unk_40 = ((fn_1_B4AC0_Detail *)v26)->unk_14;
    }
    v27 = v20->unk_24;
    if ((((fn_1_B4AC0_Detail *)v27)->unk_8 & 0x20) == 0) {
    v27 = ((fn_1_B4AC0_Detail *)v27)->unk_94;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 980;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    }
    if (v20->unk_2 == 4) {
    if (lbl_1_bss_716C0 != 0) {
    v22 = v20->unk_24;
    v27 = ((fn_1_B4AC0_Detail *)v22)->unk_94;
    v26 = ((fn_1_B4AC0_Detail *)v22)->unk_DC;
    ((fn_1_B4AC0_Detail *)v22)->unk_94 = v26;
    ((fn_1_B4AC0_Detail *)v22)->unk_DC = v27;
    lbl_1_bss_716C0 = 0;
    }
    v26 = v20->unk_24;
    v27 = ((fn_1_B4AC0_Detail *)v26)->unk_DC;
    if (v27 != 0) {
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = (u32)&lbl_801A6410;
    v23 = 990;
    v26 = *(u32 *)(v26);
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_DC = 0;
    }
    }
    v27 = v20->unk_24;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 1004;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v22 = 0;
    v20->unk_24 = v22;
    v27 = 255;
    v20->unk_2 = v27;
    v20->unk_3 = v27;
    v20->unk_4 = v27;
    v20->unk_5 = v27;
    v20->unk_6 = v27;
    v20->unk_7 = v22;
    v20->unk_8 = -1;
    v20->unk_A = -1;
    v20->unk_30 = v22;
    v20->unk_34 = 0.0f;
    v20->unk_38 = 0.0f;
    v29 = v20->unk_2A;
    lbl_1_bss_772C8 = v22;
    v20->unk_2A = (v29 & 0xFFFFFFFB);
    } else {
    if (v20->unk_7 != 0) {
    v20->unk_7 = 0;
    if (v20->unk_C != 0) {
    do {
    v26 = v20->unk_0;
    t8 = CARDUnmount((s32)((void *)v26));
    v26 = t8;
    } while ((s32)v26 == -1);
    v27 = v20->unk_C;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 7643;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v20->unk_C = 0;
    }
    v20->unk_2A = (v20->unk_2A & 0xFFFFFFFD);
    if (v20->unk_4 == 1 && (v26 = ((fn_1_B4AC0_Detail *)v20->unk_24)->unk_8, (v26 & 0x2) == 0) && (v26 & 0x800) == 0) {
    v20->unk_6 = 3;
    } else {
    v27 = v20->unk_24;
    v22 = -123;
    v26 = 1;
    ((fn_1_B4AC0_Detail *)v27)->unk_4 = v22;
    v20->unk_3 = v26;
    v20->unk_6 = 3;
    }
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_8 = (((fn_1_B4AC0_Detail *)v26)->unk_8 & 0xFFFFFBFF);
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_8 = (((fn_1_B4AC0_Detail *)v26)->unk_8 & 0xFFFFF7FF);
    if (v20->unk_2 == 4) {
    if (lbl_1_bss_716C0 != 0) {
    v22 = v20->unk_24;
    v27 = ((fn_1_B4AC0_Detail *)v22)->unk_94;
    v26 = ((fn_1_B4AC0_Detail *)v22)->unk_DC;
    ((fn_1_B4AC0_Detail *)v22)->unk_94 = v26;
    ((fn_1_B4AC0_Detail *)v22)->unk_DC = v27;
    lbl_1_bss_716C0 = 0;
    }
    v26 = v20->unk_24;
    v27 = ((fn_1_B4AC0_Detail *)v26)->unk_DC;
    if (v27 != 0) {
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = (u32)&lbl_801A6410;
    v23 = 7670;
    v26 = *(u32 *)(v26);
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_DC = 0;
    }
    v26 = v21.value;
    fn_1_B9C38(v26);
    }
    }
    v27 = v20->unk_24;
    if (v27 != 0) {
    v26 = ((fn_1_B4AC0_Detail *)v27)->unk_2;
    if (v26 != 0) {
    v24 = v20->unk_34;
    if (v24 == v20->unk_38) {
    ((fn_1_B4AC0_Detail *)v27)->unk_2 = (v26 - 1);
    }
    v20->unk_34 = v20->unk_38;
    v27 = v20->unk_24;
    if (((fn_1_B4AC0_Detail *)v27)->unk_2 == 0) {
    v26 = -5;
    ((fn_1_B4AC0_Detail *)v27)->unk_4 = v26;
    v20->unk_3 = 1;
    v20->unk_2A = (v20->unk_2A & 0xFFFFFFFD);
    }
    }
    }
    if (v20->unk_3 != 255) {
    v22 = v20->unk_4;
    v27 = (u32)((u8 *)(u32)((u8 *)((u32 *)&lbl_1_data_3C670)));
    v26 = (u32)v20;
    v20->unk_5 = v22;
    v22 = v20->unk_3;
    v20->unk_4 = v22;
    v20->unk_3 = 255;
    t12 = ((fn_1_B4AC0_Fn1)*(u32 *)(v27 + (v20->unk_4 << 2)))(v26);
    v26 = t12;
    }
    v30 = v20->unk_4;
    if (v30 != 255) {
    v31 = (u32)lbl_1_data_3C714[v30];
    v26 = (u32)v20;
    t13 = ((fn_1_B4AC0_Fn2)v31)(v26);
    v26 = t13;
    }
    if (v20->unk_2 == 254) {
    if (v20->unk_C != 0) {
    do {
    v26 = v20->unk_0;
    t14 = CARDUnmount((s32)((void *)v26));
    v26 = t14;
    } while ((s32)v26 == -1);
    v27 = v20->unk_C;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 968;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v20->unk_7 = 0;
    v20->unk_C = 0;
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_1C = 0;
    ((fn_1_B4AC0_Detail *)v26)->unk_18 = 0;
    }
    v26 = v20->unk_24;
    if ((((fn_1_B4AC0_Detail *)v26)->unk_8 & 0x80) != 0) {
    v20->unk_3C = (((fn_1_B4AC0_Detail *)v26)->unk_10 / 8192);
    v26 = v20->unk_24;
    v20->unk_40 = ((fn_1_B4AC0_Detail *)v26)->unk_14;
    }
    v27 = v20->unk_24;
    if ((((fn_1_B4AC0_Detail *)v27)->unk_8 & 0x20) == 0) {
    v27 = ((fn_1_B4AC0_Detail *)v27)->unk_94;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 980;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    }
    if (v20->unk_2 == 4) {
    if (lbl_1_bss_716C0 != 0) {
    v22 = v20->unk_24;
    v27 = ((fn_1_B4AC0_Detail *)v22)->unk_94;
    v26 = ((fn_1_B4AC0_Detail *)v22)->unk_DC;
    ((fn_1_B4AC0_Detail *)v22)->unk_94 = v26;
    ((fn_1_B4AC0_Detail *)v22)->unk_DC = v27;
    lbl_1_bss_716C0 = 0;
    }
    v26 = v20->unk_24;
    v27 = ((fn_1_B4AC0_Detail *)v26)->unk_DC;
    if (v27 != 0) {
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = (u32)&lbl_801A6410;
    v23 = 990;
    v26 = *(u32 *)(v26);
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v26 = v20->unk_24;
    ((fn_1_B4AC0_Detail *)v26)->unk_DC = 0;
    }
    }
    v27 = v20->unk_24;
    v26 = (u32)&lbl_801A6410;
    v22 = (u32)((u8 *)(u32)((u8 *)((u32 *)"memcard.c")));
    v26 = *(u32 *)(v26);
    v23 = 1004;
    fn_1_46B4(v26, v27, (const char *)v22, v23);
    v22 = 0;
    v20->unk_24 = v22;
    v27 = 255;
    v20->unk_2 = v27;
    v20->unk_3 = v27;
    v20->unk_4 = v27;
    v20->unk_5 = v27;
    v20->unk_6 = v27;
    v20->unk_7 = v22;
    v20->unk_8 = -1;
    v20->unk_A = -1;
    v20->unk_30 = v22;
    v20->unk_34 = 0.0f;
    v20->unk_38 = 0.0f;
    v32 = v20->unk_2A;
    lbl_1_bss_772C8 = v22;
    v20->unk_2A = (v32 & 0xFFFFFFFB);
    }
    }
    }
    v21.value++;
    v20++;
    } while (v21.value < 2);
}

#pragma opt_loop_invariants reset
#undef lbl_1_bss_D58
#undef lbl_801A6410
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#undef lbl_1_bss_716C0
#undef lbl_1_bss_716C8
#undef lbl_1_bss_71810
#undef lbl_1_bss_718B2
#undef lbl_1_bss_772C8
/* fzgx:end fn_1_B4AC0 */

/* fzgx:begin fn_1_B5258 */
void fn_1_B5258(char *destination, void *unused, const char *source, const char *suffix) {
    char buffer[0x400];
    char *prefix;
    unsigned int source_length;
    unsigned int prefix_length;

    strcpy((void *)buffer, (void *)unused);
    prefix = ((char *)strstr((void *)buffer, (void *)source));
    if (prefix == 0) {
        strcpy((void *)destination, (void *)buffer);
    } else {
        source_length = ((unsigned int)strlen((void *)source));
        if (prefix != buffer) {
            prefix_length = (unsigned int)(prefix - buffer);
            strncpy((void *)destination, (void *)buffer, prefix_length);
            destination[prefix_length] = 0;
        } else {
            destination[0] = 0;
        }
        strcat((void *)destination, (void *)suffix);
        strcat((void *)destination, (void *)(prefix + source_length));
    }
}
/* fzgx:end fn_1_B5258 */

/* fzgx:begin fn_1_B5310 */
/* VIEWS */
#define lbl_1_bss_71810 (*(McTaskView *)&lbl_1_bss_71810)
#define lbl_1_bss_718B2 (*(u8 *)&lbl_1_bss_718B2)
/* a message table row: one string per language */

/* FILE-SCOPE */ typedef const char *MsgRow[6];

/* fzgx-allow: S2 pool primer sink */

/* a black-to-white pulse (fn_80007F70), fast or slow; defined here so its colours land at .rodata 0x4CD4,
 * where fn_1_B5310 and fn_1_B5654 read the same pairs */

static Color pulse_color(s32 fast) {
    if (fast) {
        Color from = {0x00, 0x00, 0x00, 0x00};
        Color to = {0xFF, 0xFF, 0xFF, 0x00};
        return fn_80007F70(from, to, 10.0f, lbl_1_bss_71808);
    } else {
        Color from = {0x00, 0x00, 0x00, 0x00};
        Color to = {0xFF, 0xFF, 0xFF, 0x00};
        return fn_80007F70(from, to, 1.0f, lbl_1_bss_71808);
    }
}

void fn_1_B5310(void) {
    Color from = {0xA0, 0x50, 0x50, 0x00};
    Color to = {0xA0, 0xA0, 0xA0, 0x00};
    Color color;
    Color pulse;

    color = fn_80007F70(from, to, 1.0f, lbl_1_bss_71808);
    fn_1_49410();
    fn_1_494DC(0x2A);
    fn_1_495C8(9);
    fn_1_4954C(0.0010000000474974513f);
    {
        Color white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(white);
    }
    fn_1_49614();
    fn_1_4955C(0.800000011920929f, 0.800000011920929f);
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    fn_1_496FC(320.0f, 152.0f);
    fn_1_4A0D8((void *)lbl_1_data_3B74C[28][lbl_801A66B4]);
    /* WARNING: compiler-diff device, not original code: retail keeps the rotate by a zero register */
    pulse = pulse_color(__rlwnm(lbl_1_bss_71810.unk_2A, 0, 31, 31));
    fn_1_496FC(288.0f, 280.0f);
    fn_1_495C8(10);
    if (lbl_1_bss_718B2 == 0) {
        fn_1_4D494();
        fn_1_49514(pulse);
        fn_1_4AE0C("%s", lbl_1_data_3B74C[37][lbl_801A66B4]);
        fn_1_4D4C8(color, 0.10500000417232513f, 10.0f);
    } else {
        {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey);
        }
        {
            Color black = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black);
        }
        fn_1_4AE0C("%s", lbl_1_data_3B74C[37][lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 280.0f);
    fn_1_495C8(8);
    if (lbl_1_bss_718B2 == 0) {
        {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey);
        }
        {
            Color black = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black);
        }
        fn_1_4AE0C("%s", lbl_1_data_3B74C[38][lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514(pulse);
        fn_1_4AE0C("%s", lbl_1_data_3B74C[38][lbl_801A66B4]);
        fn_1_4D4C8(color, 0.10500000417232513f, 10.0f);
    }
    {
        Color white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(white);
    }
    {
        Color black = {0x00, 0x00, 0x00, 0x00};
        fn_1_49528(black);
    }
    fn_1_495C8(9);
    fn_1_495FC();
    fn_1_496FC(320.0f, 350.0f);
    fn_1_495A0(0.009999999776482582f);
    fn_1_4A0D8((void *)("A"));
    fn_1_49410();
}

#undef lbl_1_bss_71810
#undef lbl_1_bss_718B2
/* fzgx:end fn_1_B5310 */

/* fzgx:begin fn_1_B5654 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
/* a message table row: one string per language */

/* FILE-SCOPE */ typedef const char *MsgRow[6];

/* fzgx-allow: S2 pool primer sink */

/* a black-to-white pulse (fn_80007F70), fast or slow; defined here so its colours land at .rodata 0x4CD4,
 * where fn_1_B5310 and fn_1_B5654 read the same pairs */

void fn_1_B5654(void) {
    Color from = {0xA0, 0x50, 0x50, 0x00};
    Color to = {0xA0, 0xA0, 0xA0, 0x00};
    Color color;
    Color pulse;
    Obj_1_bss_716C8 *card;
    char buf[0x400];

    color = fn_80007F70(from, to, 1.0f, lbl_1_bss_71808);
    /* lbl_1_bss_716C8 holds two 0xA0-byte records; the second is used unless the first's unk_4 is 11 */
    card = lbl_1_bss_716C8.unk_4 == 5 ? &lbl_1_bss_716C8 : (Obj_1_bss_716C8 *)((u8 *)&lbl_1_bss_716C8 + 0xA0);
    fn_1_49410();
    fn_1_494DC(0x2A);
    fn_1_495C8(9);
    fn_1_4954C(0.001f);
    {
        Color white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(white);
    }
    fn_1_49614();
    fn_1_4955C(0.8f, 0.8f);
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    fn_1_496FC(320.0f, 198.0f);
    fn_1_B5258((void *)buf, (void *)lbl_1_data_3B74C[35][lbl_801A66B4], (void *)("SLOT"),
               (void *)(card->unk_0 == 0 ? lbl_1_data_3B74C[37][lbl_801A66B4]
                                : lbl_1_data_3B74C[38][lbl_801A66B4]));
    fn_1_B5258((void *)buf, (void *)buf, (void *)("SLOT"),
               (void *)(card->unk_0 == 0 ? lbl_1_data_3B74C[37][lbl_801A66B4]
                                : lbl_1_data_3B74C[38][lbl_801A66B4]));
    fn_1_4A0D8((void *)buf);
    pulse = pulse_color(card->unk_2A);
    fn_1_496FC(288.0f, 298.0f);
    fn_1_495C8(10);
    if (card->unk_24->unk_1 == 0) {
        fn_1_4D494();
        fn_1_49514(pulse);
        fn_1_4AE0C("%s", lbl_1_data_3B74C[39][lbl_801A66B4]);
        fn_1_4D4C8(color, 0.095f, 10.0f);
    } else {
        {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey);
        }
        {
            Color black = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black);
        }
        fn_1_4AE0C("%s", lbl_1_data_3B74C[39][lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 298.0f);
    fn_1_495C8(8);
    if (card->unk_24->unk_1 == 0) {
        {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey);
        }
        {
            Color black = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black);
        }
        fn_1_4AE0C("%s", lbl_1_data_3B74C[40][lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514(pulse);
        fn_1_4AE0C("%s", lbl_1_data_3B74C[40][lbl_801A66B4]);
        fn_1_4D4C8(color, 0.095f, 10.0f);
    }
    {
        Color white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(white);
    }
    {
        Color black = {0x00, 0x00, 0x00, 0x00};
        fn_1_49528(black);
    }
    fn_1_495C8(9);
    fn_1_495FC();
    fn_1_496FC(320.0f, 350.0f);
    fn_1_495A0(0.01f);
    fn_1_4A0D8((void *)("A"));
    fn_1_49410();
}

#undef lbl_1_bss_716C8
/* fzgx:end fn_1_B5654 */

/* fzgx:begin fn_1_B5A3C */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
/* a message table row: one string per language */

/* FILE-SCOPE */ typedef const char *MsgRow[6];

/* fzgx-allow: S2 pool primer sink */

/* a black-to-white pulse (fn_80007F70), fast or slow; defined here so its colours land at .rodata 0x4CD4,
 * where fn_1_B5310 and fn_1_B5654 read the same pairs */

void fn_1_B5A3C(void) {
    Color from = {0xA0, 0x50, 0x50, 0x00};
    Color to = {0xA0, 0xA0, 0xA0, 0x00};
    Color color;
    Color pulse;
    Obj_1_bss_716C8 *card;
    char buf[0x400];

    color = fn_80007F70(from, to, 1.0f, lbl_1_bss_71808);
    /* lbl_1_bss_716C8 holds two 0xA0-byte records; the second is used unless the first's unk_4 is 11 */
    card = lbl_1_bss_716C8.unk_4 == 11 ? &lbl_1_bss_716C8 : (Obj_1_bss_716C8 *)((u8 *)&lbl_1_bss_716C8 + 0xA0);
    fn_1_49410();
    fn_1_494DC(0x2A);
    fn_1_495C8(9);
    fn_1_4954C(0.001f);
    {
        Color white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(white);
    }
    fn_1_49614();
    fn_1_4955C(0.8f, 0.8f);
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    fn_1_496FC(320.0f, 192.0f);
    if (card->unk_24->unk_0 == 4) {
        fn_1_B5258((void *)buf, (void *)lbl_1_data_3B74C[105][lbl_801A66B4], (void *)("SLOT"),
                   (void *)(card->unk_0 == 0 ? lbl_1_data_3B74C[37][lbl_801A66B4]
                                    : lbl_1_data_3B74C[38][lbl_801A66B4]));
        fn_1_B5258((void *)buf, (void *)buf, (void *)("SLOT"),
                   (void *)(card->unk_0 == 0 ? lbl_1_data_3B74C[37][lbl_801A66B4]
                                    : lbl_1_data_3B74C[38][lbl_801A66B4]));
    } else {
        fn_1_B5258((void *)buf, (void *)lbl_1_data_3B74C[46][lbl_801A66B4], (void *)("SLOT"),
                   (void *)(card->unk_0 == 0 ? lbl_1_data_3B74C[37][lbl_801A66B4]
                                    : lbl_1_data_3B74C[38][lbl_801A66B4]));
        fn_1_B5258((void *)buf, (void *)buf, (void *)("SLOT"),
                   (void *)(card->unk_0 == 0 ? lbl_1_data_3B74C[37][lbl_801A66B4]
                                    : lbl_1_data_3B74C[38][lbl_801A66B4]));
    }
    fn_1_B5258((void *)buf, (void *)buf, (void *)("FILE"),
               (void *)(lbl_1_data_3B74C[((u8 *)card->unk_24->unk_8C)[0x3F]][lbl_801A66B4]));
    fn_1_4A0D8((void *)buf);
    pulse = pulse_color(card->unk_2A);
    fn_1_496FC(288.0f, 280.0f);
    fn_1_495C8(10);
    if (card->unk_24->unk_1 == 0) {
        fn_1_4D494();
        fn_1_49514(pulse);
        fn_1_4AE0C("%s", lbl_1_data_3B74C[39][lbl_801A66B4]);
        fn_1_4D4C8(color, 0.095f, 10.0f);
    } else {
        {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey);
        }
        {
            Color black = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black);
        }
        fn_1_4AE0C("%s", lbl_1_data_3B74C[39][lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 280.0f);
    fn_1_495C8(8);
    if (card->unk_24->unk_1 == 0) {
        {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(grey);
        }
        {
            Color black = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(black);
        }
        fn_1_4AE0C("%s", lbl_1_data_3B74C[40][lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514(pulse);
        fn_1_4AE0C("%s", lbl_1_data_3B74C[40][lbl_801A66B4]);
        fn_1_4D4C8(color, 0.095f, 10.0f);
    }
    {
        Color white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(white);
    }
    {
        Color black = {0x00, 0x00, 0x00, 0x00};
        fn_1_49528(black);
    }
    fn_1_495C8(9);
    fn_1_495FC();
    fn_1_496FC(320.0f, 350.0f);
    fn_1_495A0(0.01f);
    fn_1_4A0D8((void *)("A"));
    fn_1_49410();
}
/* fzgx:end fn_1_B5A3C */

/* fzgx:begin fn_1_B5F00 */

void fn_1_B5F00(B5F00Source *source, B5F00Dest *dest) {
    f32 value = dest->value0;
    f32 increment = source->value;
    value += increment;
    dest->value0 = value;
    value = dest->valueC;
    value += increment;
    dest->valueC = value;
}
#undef lbl_1_bss_716C8
/* fzgx:end fn_1_B5F00 */

/* fzgx:begin fn_1_B5F20 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(MemcardSlot_B5F20 (*)[2])&lbl_1_bss_716C8)
#define lbl_1_bss_77314 (*(u8 *)&lbl_1_bss_77314)
/* VIEWS */
#define lbl_1_rodata_26F8 (*(FontDrawPacket *)&lbl_1_rodata_26F8)
/* a message table row: one string per language */

/* FILE-SCOPE */ typedef const char *MsgRow[6];

/* fzgx-allow: S2 pool primer sink */

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_B5F20(void) {
    MemcardSlot_B5F20 *slot;
    f32 center_x = 320.0f;
    s32 msg;
    f32 progress;
    f32 phase1;
    f32 phase2;
    f32 phase3;
    FontDrawPacket packet;

    slot = (lbl_1_bss_716C8[0].unk_2A & 2) ? &lbl_1_bss_716C8[0] : &lbl_1_bss_716C8[1];
    if (slot->unk_2 == 4) {
        msg = 0x44;
    } else if (slot->unk_2 == 6) {
        msg = 0x45;
    } else {
        switch (slot->unk_4) {
        case 6:
            msg = 0x42;
            break;
        case 15:
        case 36:
        case 37:
            msg = 0x43;
            break;
        case 25:
            msg = 0x44;
            break;
        default:
            msg = 0x43;
            break;
        }
    }
    fn_1_49410();
    fn_1_494DC(0x2A);
    fn_1_495C8(9);
    fn_1_4954C(1e-7f);
    fn_1_49614();
    fn_1_4955C(0.8f, 0.8f);
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    progress = slot->unk_38;
    if (slot->unk_2 == 0 || slot->unk_2 == 1) {
        progress = 1.8 * progress;
        progress = CLAMP(progress, 0.0, 1.0);
    }
    if (slot->unk_2 == 4) {
        progress = 1.3 * progress;
        progress = CLAMP(progress, 0.0, 1.0);
    }
    phase1 = CLAMP(progress / 0.5, 0.0, 1.0);
    phase2 = CLAMP((progress - 0.5) / 0.2, 0.0, 1.0);
    phase3 = CLAMP((progress - 0.7) / 0.3, 0.0, 1.0);
    if (phase1 < 0.5f) {
        lbl_1_bss_77314 = 0;
    }
    if (phase1 >= 1.0f && !(lbl_1_bss_77314 & 1)) {
        fn_1_A2DC4(0xA9010300);
        lbl_1_bss_77314 |= 1;
    }
    if (phase2 >= 1.0f && !(lbl_1_bss_77314 & 2)) {
        fn_1_A2DC4(0xA9010300);
        lbl_1_bss_77314 |= 2;
    }
    if (phase3 >= 1.0f && !(lbl_1_bss_77314 & 4)) {
        fn_1_A2DC4(0xA9010300);
        lbl_1_bss_77314 |= 4;
    }
    if (phase3 < 1.0f) {
        if ((lbl_801A66C8 & 63) < 48) {
            fn_1_49410();
            fn_1_49614();
            fn_1_494DC(5);
            fn_1_495B0(0x80000000);
            fn_1_49738(fn_1_B5F00);
            fn_1_49748(4.0f);
            fn_1_49590(0.5f);
            fn_1_495C8(9);
            fn_1_496FC(center_x, 225.0f);
            fn_1_4954C(0.09f);
            {
                Color color = {0xF0, 0xF0, 0xF0, 0x00};
                fn_1_49514(color);
            }
            fn_1_4AE0C(lbl_1_data_3B74C[msg][lbl_801A66B4]);
        }
        lbl_1_bss_77318 = 0;
    } else {
        f32 alpha;
        if (++lbl_1_bss_77318 == 10) {
            fn_1_A2DC4(0xA9010B00);
        }
        alpha = CLAMP(lbl_1_bss_77318 / 10.0f, 0.0f, 1.0f);
        fn_1_49410();
        fn_1_49614();
        fn_1_494DC(5);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_B5F00);
        fn_1_49748(4.0f);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_496FC(center_x, 225.0f);
        alpha *= alpha;
        fn_1_495A0(alpha);
        fn_1_4954C(0.09f);
        {
            Color color = {0x90, 0x90, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4955C(1.0f, alpha);
        fn_1_4AE0C("ACCESS COMPLETE");
        fn_1_4955C(1.0f, 1.0f);
    }

    /* phase 1 */
    fn_1_49410();
    fn_1_49614();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_B5F00);
    fn_1_49748(4.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(0.09f);
    {
        Color color = {0xFF, 0xFF, 0x60, 0x00};
        fn_1_49514(color);
    }
    fn_1_496FC(center_x - 125.0 - 45.0, 310.0f);
    fn_1_4AE0C("PHASE1");
    packet = lbl_1_rodata_26F8;
    packet.image = 11;
    packet.x = center_x;
    packet.y = 310.0f;
    packet.flags = 10;
    packet.z = 0.09f;
    fn_1_50164(258.0f, 17.0f, 8.0f, 8.0f, (void *)&packet);
    packet = lbl_1_rodata_26F8;
    packet.image = 16;
    packet.x = center_x - 125.0;
    packet.y = 310.0f;
    packet.flags = 9;
    packet.scale_x = 15.625f * phase1;
    packet.scale_y = 0.5625f;
    packet.z = 0.09f;
    fn_1_4F734(&packet);
    fn_1_49410();
    fn_1_49614();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_B5F00);
    fn_1_49748(4.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    {
        Color color = {0xFF, 0xFF, 0x60, 0x00};
        fn_1_49514(color);
    }
    fn_1_496FC(center_x + 125.0 + 40.0, 310.0f);
    if (phase1 == 0.0f) {
        {
            Color color = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("WAIT");
    } else if (phase1 < 1.0f) {
        {
            Color color = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("NOW");
    } else {
        {
            Color color = {0xFF, 0xA0, 0xA0, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("OK");
    }

    /* phase 2 */
    fn_1_49410();
    fn_1_49614();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_B5F00);
    fn_1_49748(4.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(0.09f);
    {
        Color color = {0xFF, 0xFF, 0x60, 0x00};
        fn_1_49514(color);
    }
    fn_1_496FC(center_x - 125.0 - 45.0, 340.0f);
    fn_1_4AE0C("PHASE2");
    packet = lbl_1_rodata_26F8;
    packet.image = 11;
    packet.x = center_x;
    packet.y = 340.0f;
    packet.flags = 10;
    packet.z = 0.09f;
    fn_1_50164(258.0f, 17.0f, 8.0f, 8.0f, (void *)&packet);
    packet = lbl_1_rodata_26F8;
    packet.image = 16;
    packet.x = center_x - 125.0;
    packet.y = 340.0f;
    packet.flags = 9;
    packet.scale_x = 15.625f * phase2;
    packet.scale_y = 0.5625f;
    packet.z = 0.09f;
    fn_1_4F734(&packet);
    fn_1_49410();
    fn_1_49614();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_B5F00);
    fn_1_49748(4.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    {
        Color color = {0xFF, 0xFF, 0x60, 0x00};
        fn_1_49514(color);
    }
    fn_1_496FC(center_x + 125.0 + 40.0, 340.0f);
    if (phase2 == 0.0f) {
        {
            Color color = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("WAIT");
    } else if (phase2 < 1.0f) {
        {
            Color color = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("NOW");
    } else {
        {
            Color color = {0xFF, 0xA0, 0xA0, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("OK");
    }

    /* phase 3 */
    fn_1_49410();
    fn_1_49614();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_B5F00);
    fn_1_49748(4.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(0.09f);
    {
        Color color = {0xFF, 0xFF, 0x60, 0x00};
        fn_1_49514(color);
    }
    fn_1_496FC(center_x - 125.0 - 45.0, 370.0f);
    fn_1_4AE0C("PHASE3");
    packet = lbl_1_rodata_26F8;
    packet.image = 11;
    packet.x = center_x;
    packet.y = 370.0f;
    packet.flags = 10;
    packet.z = 0.09f;
    fn_1_50164(258.0f, 17.0f, 8.0f, 8.0f, (void *)&packet);
    packet = lbl_1_rodata_26F8;
    packet.image = 16;
    packet.x = center_x - 125.0;
    packet.y = 370.0f;
    packet.flags = 9;
    packet.scale_x = 15.625f * phase3;
    packet.scale_y = 0.5625f;
    packet.z = 0.09f;
    fn_1_4F734(&packet);
    fn_1_49410();
    fn_1_49614();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_B5F00);
    fn_1_49748(4.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    fn_1_496FC(center_x + 125.0 + 40.0, 370.0f);
    if (phase3 == 0.0f) {
        {
            Color color = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("WAIT");
    } else if (phase3 < 1.0f) {
        {
            Color color = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("NOW");
    } else {
        {
            Color color = {0xFF, 0xA0, 0xA0, 0x00};
            fn_1_49514(color);
        }
        fn_1_4AE0C("OK");
    }
    fn_1_4955C(10.416667f, 1.0f);
    fn_1_496FC(center_x, 380.0f);
    fn_1_495A0(0.01f);
    fn_1_4AE0C("A");
}

#undef lbl_1_rodata_26F8
#undef CLAMP
#undef lbl_1_bss_716C8
#undef lbl_1_bss_77314
/* fzgx:end fn_1_B5F20 */

/* fzgx:begin fn_1_B6B28 */
/* VIEWS */
#define lbl_1_bss_71810 (*(u8 (*)[0xA1])&lbl_1_bss_71810)
#define lbl_1_bss_718B2 (*(u8 *)&lbl_1_bss_718B2)
#define lbl_1_bss_718B4 (*(u32 *)&lbl_1_bss_718B4)
#define lbl_1_bss_77328 (*(s32 *)&lbl_1_bss_77328)
/* FILE-SCOPE */ typedef char *StrRow_1_B6B28[6];

/* fzgx-allow: A1 absolute retail data address */

/* Tint colour for the overlay text: pool colour with full alpha. */

static inline Color tint_color(u32 rgb) {
Color c;
*(u32 *)&c = rgb;
c.a = 0xff;
return c;
}

#define draw_tint(rgb, scale) do { Color tint; *(u32 *)&tint = (rgb); tint.a = 0xff; fn_1_4D274(tint, (scale)); } while (0)

#define SLOT_TEXT_A (((CardSlotStrings_1_B6B28 *)((char **)lbl_1_data_3B74C + lbl_801A66B4))->slot_a)

#define SLOT_TEXT_B (((CardSlotStrings_1_B6B28 *)((char **)lbl_1_data_3B74C + lbl_801A66B4))->slot_b)

static inline Color card_tint_4(u32 rgb) {
    ((Color *)&rgb)->a = 0xff;
    return *(Color *)&rgb;
}

#define draw_tint_4(rgb, scale) fn_1_4D274(card_tint_4(rgb), scale)

static inline Color card_tint_3(u32 rgb) {
    ((Color *)&rgb)->a = 0xff;
    return *(Color *)&rgb;
}

#define draw_tint_3(rgb, scale) fn_1_4D274(card_tint_3(rgb), scale)

static inline Color card_tint_2(u32 rgb) {
    ((Color *)&rgb)->a = 0xff;
    return *(Color *)&rgb;
}

#define draw_tint_2(rgb, scale) fn_1_4D274(card_tint_2(rgb), scale)

static inline Color card_tint_1(u32 rgb) {
    ((Color *)&rgb)->a = 0xff;
    return *(Color *)&rgb;
}

#define draw_tint_1(rgb, scale) fn_1_4D274(card_tint_1(rgb), scale)

static inline const char *card_slot_a(void) {
    return (const char *)lbl_1_data_3B74C[0x25][lbl_801A66B4];
}

static inline const char *card_slot_b(void) {
    return (const char *)lbl_1_data_3B74C[0x26][lbl_801A66B4];
}

#undef SLOT_TEXT_A

#undef SLOT_TEXT_B

#define SLOT_TEXT_A card_slot_a()

#define SLOT_TEXT_B card_slot_b()

#undef draw_tint

#define draw_tint(rgb, scale) fn_1_4D274(tint_color(rgb), scale)

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

/* WARNING: compiler-diff device, not original code */
static inline Color tint_level4(Color c) {
    c.a = 0xff;
    return c;
}

static inline Color tint_level3(Color rgb) { return tint_level4(rgb); }

static inline Color tint_level2(Color rgb) { return tint_level3(rgb); }

static inline Color tint_level1(Color rgb) { return tint_level2(rgb); }

#undef draw_tint_1

#undef draw_tint_2

#undef draw_tint_3

#undef draw_tint_4

#define draw_tint_1(rgb, scale) fn_1_4D274(tint_level1(rgb), scale)

#define draw_tint_2(rgb, scale) fn_1_4D274(tint_level2(rgb), scale)

#define draw_tint_3(rgb, scale) fn_1_4D274(tint_level3(rgb), scale)

#define draw_tint_4(rgb, scale) fn_1_4D274(tint_level4(rgb), scale)

void fn_1_B6B28(void) {
static const Color white_0 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E70 */
static const Color white_1 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E74 */
static const Color white_2 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E78 */
static const Color white_3 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E7C */
static const Color white_4 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E80 */
static const Color white_5 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E84 */
static const Color white_6 = {0xFF, 0xFF, 0xFF, 0x00}; /* .rodata 4E88 */

char buf[0x400];
char line[0x400];
char num1[0x10];
char num2[0x10];
s32 ids[2];
s32 subs[2];
s32 names[2];
Color color;
/* WARNING: compiler-diff device, not original code */
struct { u32 value; } first;
u32 cardmask;
s32 nameidx;
u8 avail;
fn_1_AAB98_Entry *cards;
s32 title;
s32 flag;
u32 bits;
f32 t;
u8 idx;
s32 ready;
u32 status0, status1;
Color tint4, tint3, tint2, tint1;
if ((*(s16 *)&lbl_1_bss_960) == 9) {
if (fn_1_B7C00() != 0) {
fn_1_4FD64();
}
}
lbl_1_bss_71808 ++;
fn_1_4D0A0();
fn_1_4AEC0(1);
fn_1_4AEB4(1.5f );
idx = lbl_1_bss_718B1 ;
if (idx != 5 && lbl_1_bss_716C8 [idx].unk_24 != 0) {
u32 flags = lbl_1_bss_716C8 [idx].unk_24->unk_8;
if (flags & 0x2000) {
u8 st = lbl_1_bss_716C8 [idx].unk_4;
if (st != 1 && st != 5 && st != 2) {
fn_1_54278(0, 0);
fn_1_5428C(1.0f );
return;
}
}
if ((flags & 0x8000) && lbl_1_bss_716C8 [idx].unk_4 == 1) {
fn_1_54278(0, 0);
fn_1_5428C(1.0f );
return;
}
}
if (lbl_1_bss_718B2 != 0xff && lbl_1_bss_718B2 != 2) {
if ((lbl_1_bss_7731C) <= 10) { if ((lbl_1_bss_7731C) == 0) { fn_1_A2DC4(0xA9010600); } t = (f32)(lbl_1_bss_7731C) / 10.0f; fn_1_54278((s32)(320.0f * (1.0f - t) * (1.0f - t)), 0); fn_1_5428C(t * t); } else { fn_1_54278(0, 0); fn_1_5428C(1.0f); } (lbl_1_bss_7731C)++ ;
fn_1_B5310();
color = white_0 ;
color.a = 0xff;
fn_1_4D274(color, 40.0f );
fn_1_54278(0, 0);
fn_1_5428C(1.0f );
return;
}
lbl_1_bss_7731C = ready = 0;
avail = fn_1_B7C00(); if (avail & 1) { if (lbl_1_bss_716C8[0].unk_2 == 2) { if (!(lbl_1_bss_716C8[0].unk_2A & 8) && !(lbl_1_bss_716C8[0].unk_2A & 4)) { ready |= 1; } } else if (!(lbl_1_bss_716C8[0].unk_2A & 4)) { ready |= 1; } } if (avail & 2) { if (lbl_1_bss_716C8[1].unk_2 == 2) { if (!(lbl_1_bss_716C8[1].unk_2A & 8) && !(lbl_1_bss_716C8[1].unk_2A & 4)) { ready |= 1; } } else if (!(lbl_1_bss_716C8[1].unk_2A & 4)) { ready |= 1; } } ;
if (ready != 0) {
fn_1_49410(); fn_1_494DC(0x2a); fn_1_495C8(9); fn_1_49514((white_1)); fn_1_4954C(0.0000001f); fn_1_49614(); fn_1_4955C(0.8f, 0.8f); fn_1_4966C(-1.0f, 8.0f); if (lbl_801A66B4 != 5) { fn_1_495B0(0x80000000); fn_1_49590(0.5f); fn_1_4966C(-1.0f, 4.0f); } ;
flag = 0;
nameidx = 0x4f;
avail = fn_1_B7C00();
if (avail & 1) {
if (lbl_1_bss_716C8 [0].unk_2 == 2) {
switch (lbl_1_bss_716C8 [0].unk_4) {
case 5:
case 6:
case 0x16:
break;
default:
flag = 1;
break;
}
}
if (lbl_1_bss_716C8 [0].unk_24 != 0) {
nameidx = lbl_1_bss_716C8 [0].unk_24->unk_8C->unk_3F;
}
} else if (avail & 2) {
if (lbl_1_bss_716C8 [1].unk_2 == 2) {
switch (lbl_1_bss_716C8 [0].unk_4) {
case 5:
case 6:
case 0x16:
break;
default:
flag = 1;
break;
}
}
if (lbl_1_bss_716C8 [1].unk_24 != 0) {
nameidx = lbl_1_bss_716C8 [1].unk_24->unk_8C->unk_3F;
}
}
title = 0x47;
if (flag) {
title = 0x46;
}
avail = fn_1_B7C00();
first.value = avail & 1;
if (first.value) {
if (lbl_1_bss_716C8 [0].unk_24->unk_0 == 4 && lbl_1_bss_716C8 [0].unk_2 == 0 && lbl_1_bss_716C8 [0].unk_4 == 0xb) {
title = -1;
}
} else if (avail & 2) {
if (lbl_1_bss_716C8 [1].unk_24->unk_0 == 4 && lbl_1_bss_716C8 [1].unk_2 == 0 && lbl_1_bss_716C8 [1].unk_4 == 0xb) {
title = -1;
}
}
if (title != -1) {
fn_1_B5258((void *)buf, (void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [title][lbl_801A66B4]), (void *)((char *)(((u8 *)"FILE"))), (void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [nameidx][lbl_801A66B4]));
if (first.value) {
fn_1_B5258((void *)buf, (void *)buf, (void *)((char *)(((u8 *)"SLOT"))), (void *)SLOT_TEXT_A);
} else if (avail & 2) {
fn_1_B5258((void *)buf, (void *)buf, (void *)((char *)(((u8 *)"SLOT"))), (void *)SLOT_TEXT_B);
}
} else {
buf[0] = 0;
}
}
cards = lbl_1_bss_716C8 ;
if ((status0 = cards[0].unk_4) == 5 || (status1 = cards[1].unk_4) == 5) {
if ((lbl_1_bss_77320) <= 10) { if ((lbl_1_bss_77320) == 0) { fn_1_A2DC4(0xA9010600); } t = (f32)(lbl_1_bss_77320) / 10.0f; fn_1_54278((s32)(320.0f * (1.0f - t) * (1.0f - t)), 0); fn_1_5428C(t * t); } else { fn_1_54278(0, 0); fn_1_5428C(1.0f); } (lbl_1_bss_77320)++ ;
ready = 0;
avail = fn_1_B7C00(); if (avail & 1) { if (lbl_1_bss_716C8[0].unk_2 == 2) { if (!(lbl_1_bss_716C8[0].unk_2A & 8) && !(lbl_1_bss_716C8[0].unk_2A & 4)) { ready |= 1; } } else if (!(lbl_1_bss_716C8[0].unk_2A & 4)) { ready |= 1; } } if (avail & 2) { if (lbl_1_bss_716C8[1].unk_2 == 2) { if (!(lbl_1_bss_716C8[1].unk_2A & 8) && !(lbl_1_bss_716C8[1].unk_2A & 4)) { ready |= 1; } } else if (!(lbl_1_bss_716C8[1].unk_2A & 4)) { ready |= 1; } } ;
if (ready != 0) {
fn_1_496FC(320.0f , 120.0f );
fn_1_4A0D8((void *)buf);
}
fn_1_B5654(); draw_tint_1(white_2, 40.0f); fn_1_54278(0, 0); fn_1_5428C(1.0f) ;
return;
}
lbl_1_bss_77320 = 0;
if (status0 == 0xb || status1 == 0xb) {
if ((lbl_1_bss_77324) <= 10) { if ((lbl_1_bss_77324) == 0) { fn_1_A2DC4(0xA9010600); } t = (f32)(lbl_1_bss_77324) / 10.0f; fn_1_54278((s32)(320.0f * (1.0f - t) * (1.0f - t)), 0); fn_1_5428C(t * t); } else { fn_1_54278(0, 0); fn_1_5428C(1.0f); } (lbl_1_bss_77324)++ ;
ready = 0;
avail = fn_1_B7C00(); if (avail & 1) { if (lbl_1_bss_716C8[0].unk_2 == 2) { if (!(lbl_1_bss_716C8[0].unk_2A & 8) && !(lbl_1_bss_716C8[0].unk_2A & 4)) { ready |= 1; } } else if (!(lbl_1_bss_716C8[0].unk_2A & 4)) { ready |= 1; } } if (avail & 2) { if (lbl_1_bss_716C8[1].unk_2 == 2) { if (!(lbl_1_bss_716C8[1].unk_2A & 8) && !(lbl_1_bss_716C8[1].unk_2A & 4)) { ready |= 1; } } else if (!(lbl_1_bss_716C8[1].unk_2A & 4)) { ready |= 1; } } ;
if (ready != 0) {
fn_1_AAB98_Entry *cur = (cards[0].unk_4 == 0xb) ? &lbl_1_bss_716C8 [0] : &lbl_1_bss_716C8 [1];
if (cur->unk_24->unk_0 == 4) {
fn_1_496FC(320.0f , 120.0f );
fn_1_495A0(0.0001f );
fn_1_4A0D8((void *)((char *)(((u8 *)"A"))));
fn_1_495A0(1.0f );
fn_1_496FC(320.0f , 180.0f );
fn_1_4A0D8((void *)buf);
} else {
fn_1_496FC(320.0f , 120.0f );
fn_1_4A0D8((void *)buf);
}
}
fn_1_B5A3C(); draw_tint_2(white_3, 40.0f); fn_1_54278(0, 0); fn_1_5428C(1.0f) ;
return;
}
lbl_1_bss_77324 = 0;
if ((cards[0].unk_2A | cards[1].unk_2A) & 2) {
if ((lbl_1_bss_77328) <= 10) { if ((lbl_1_bss_77328) == 0) { fn_1_A2DC4(0xA9010600); } t = (f32)(lbl_1_bss_77328) / 10.0f; fn_1_54278((s32)(320.0f * (1.0f - t) * (1.0f - t)), 0); fn_1_5428C(t * t); } else { fn_1_54278(0, 0); fn_1_5428C(1.0f); } (lbl_1_bss_77328)++ ;
ready = 0;
avail = fn_1_B7C00(); if (avail & 1) { if (lbl_1_bss_716C8[0].unk_2 == 2) { if (!(cards[0].unk_2A & 8) && !(cards[0].unk_2A & 4)) { ready |= 1; } } else if (!(cards[0].unk_2A & 4)) { ready |= 1; } } if (avail & 2) { if (lbl_1_bss_716C8[1].unk_2 == 2) { if (!(cards[1].unk_2A & 8) && !(cards[1].unk_2A & 4)) { ready |= 1; } } else if (!(cards[1].unk_2A & 4)) { ready |= 1; } } ;
if (ready != 0) {
fn_1_496FC(320.0f , 120.0f );
fn_1_4A0D8((void *)buf);
}
fn_1_B5F20(); draw_tint_3(white_4, 40.0f); fn_1_54278(0, 0); fn_1_5428C(1.0f) ;
return;
}
lbl_1_bss_77328 = 0;
cardmask = 0;
bits = 0;
ids[0] = -1;
ids[1] = -1;
if (cards[0].unk_8 != -1) {
fn_1_AAB98_Obj *w = cards[0].unk_24;
cardmask |= 1;
ids[0] = cards[0].unk_8;
subs[0] = cards[0].unk_A;
names[0] = w->unk_8C->unk_3F;
bits |= w->unk_8;
}
if (lbl_1_bss_716C8 [1].unk_8 != -1) {
fn_1_AAB98_Obj *w = lbl_1_bss_716C8 [1].unk_24;
cardmask |= 2;
ids[1] = lbl_1_bss_716C8 [1].unk_8;
subs[1] = lbl_1_bss_716C8 [1].unk_A;
names[1] = w->unk_8C->unk_3F;
bits |= w->unk_8;
}
if (lbl_1_bss_772C0 [0] != ids[0]) {
lbl_1_data_3C1E4 = 0;
}
if (lbl_1_bss_772C0 [1] != ids[1]) {
lbl_1_data_3C1E4 = 0;
}
lbl_1_bss_772C0 [0] = ids[0];
lbl_1_bss_772C0 [1] = ids[1];
if ((lbl_1_data_3C1E4) <= 10) { if ((lbl_1_data_3C1E4) == 0) { fn_1_A2DC4(0xA9010600); } t = (f32)(lbl_1_data_3C1E4) / 10.0f; fn_1_54278((s32)(320.0f * (1.0f - t) * (1.0f - t)), 0); fn_1_5428C(t * t); } else { fn_1_54278(0, 0); fn_1_5428C(1.0f); } (lbl_1_data_3C1E4)++ ;
ready = 0;
avail = fn_1_B7C00(); if (avail & 1) { if (lbl_1_bss_716C8[0].unk_2 == 2) { if (!(cards[0].unk_2A & 8) && !(cards[0].unk_2A & 4)) { ready |= 1; } } else if (!(cards[0].unk_2A & 4)) { ready |= 1; } } if (avail & 2) { if (lbl_1_bss_716C8[1].unk_2 == 2) { if (!(cards[1].unk_2A & 8) && !(cards[1].unk_2A & 4)) { ready |= 1; } } else if (!(cards[1].unk_2A & 4)) { ready |= 1; } } ;
if (ready != 0) {
fn_1_496FC(320.0f , 120.0f );
fn_1_4A0D8((void *)buf);
}
if (cardmask != 0) {
fn_1_49410(); fn_1_494DC(0x2a); fn_1_495C8(9); fn_1_49514((white_5)); fn_1_4954C(0.0000001f); fn_1_49614(); fn_1_4955C(0.8f, 0.8f); fn_1_4966C(-1.0f, 8.0f); if (lbl_801A66B4 != 5) { fn_1_495B0(0x80000000); fn_1_49590(0.5f); fn_1_4966C(-1.0f, 4.0f); } ;
if (cardmask < 3) {
if (ids[cardmask - 1] == 0x2a || ids[cardmask - 1] == 0x2c) {
fn_1_4955C(0.7f , 0.7f );
}
fn_1_B5258((void *)line, (void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [ids[cardmask - 1]][lbl_801A66B4]), (void *)((char *)(((u8 *)"SLOT"))),
(void *)((cardmask - 1 == 0) ? SLOT_TEXT_A : SLOT_TEXT_B));
fn_1_B5258((void *)line, (void *)line, (void *)((char *)(((u8 *)"SLOT"))),
(void *)((cardmask - 1 == 0) ? SLOT_TEXT_A : SLOT_TEXT_B));
fn_1_B5258((void *)line, (void *)line, (void *)((char *)(((u8 *)"FILE"))), (void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [names[cardmask - 1]][lbl_801A66B4]));
if (lbl_1_bss_716C8 [cardmask - 1].unk_24 != 0) {
sprintf((void *)num1, (void *)((char *)(((u8 *)"%d"))), lbl_1_bss_716C8 [cardmask - 1].unk_24->unk_10 / 0x2000);
fn_1_B5258((void *)line, (void *)line, (void *)((char *)(((u8 *)"FREE"))), (void *)num1);
} else {
sprintf((void *)num1, (void *)((char *)(((u8 *)"%d"))), lbl_1_bss_716C8 [cardmask - 1].unk_3C);
fn_1_B5258((void *)line, (void *)line, (void *)((char *)(((u8 *)"FREE"))), (void *)num1);
}
if (lbl_1_bss_716C8 [cardmask - 1].unk_24 != 0) {
sprintf((void *)num2, (void *)((char *)(((u8 *)"%d"))), lbl_1_bss_716C8 [cardmask - 1].unk_24->unk_C >> 13);
fn_1_B5258((void *)line, (void *)line, (void *)((char *)(((u8 *)"REQUIRED"))), (void *)num2);
}
if (bits & 4) {
fn_1_496FC(320.0f , 240.0f );
fn_1_4A0D8((void *)line);
} else if (ids[cardmask - 1] == 0x2a || ids[cardmask - 1] == 0x2c) {
fn_1_496FC(320.0f , 220.0f );
fn_1_4A0D8((void *)line);
fn_1_496FC(320.0f , 370.0f );
if (subs[cardmask - 1] != -1) {
fn_1_4A0D8((void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [subs[cardmask - 1]][lbl_801A66B4]));
}
} else {
fn_1_4B16C(line);
fn_1_496FC(320.0f , 190.0f );
fn_1_4A0D8((void *)line);
fn_1_496FC(320.0f , 340.0f );
if (subs[cardmask - 1] != -1) {
fn_1_4A0D8((void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [subs[cardmask - 1]][lbl_801A66B4]));
}
}
} else {
fn_1_AAB98_Obj *w;
fn_1_496FC(320.0f , 120.0f );
fn_1_4A0D8((void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [ids[0]][lbl_801A66B4]));
w = lbl_1_bss_716C8 [cardmask - 1].unk_24;
if (!(w->unk_8 & 4)) {
fn_1_496FC(320.0f , 200.0f );
if (subs[0] != -1) {
fn_1_4A0D8((void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [subs[0]][lbl_801A66B4]));
}
}
fn_1_496FC(320.0f , 280.0f );
fn_1_4A0D8((void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [ids[1]][lbl_801A66B4]));
w = lbl_1_bss_716C8 [cardmask - 1].unk_24;
if (!(w->unk_8 & 4)) {
fn_1_496FC(320.0f , 360.0f );
if (subs[1] != -1) {
fn_1_4A0D8((void *)(((StrRow_1_B6B28 *)(((u8 *)lbl_1_data_3B74C))) [subs[1]][lbl_801A66B4]));
}
}
}
fn_1_49410();
}
draw_tint_4(white_6 , 40.0f );
fn_1_4AEC0(0);
fn_1_4AEB4(0.0f );
fn_1_54278(0, 0);
fn_1_5428C(1.0f );
}
/* fzgx:end fn_1_B6B28 */

/* fzgx:begin fn_1_B7C00 */
#pragma opt_lifetimes reset

u8 fn_1_B7C00(void) {
    u8 result = 0;

    if (((Obj_1_bss_716C8 *)&lbl_1_bss_716C8)->unk_2 != 0xff) {
        result |= 1;
    }
    if (((Obj_1_bss_716C8 *)&lbl_1_bss_716C8)->pad_A0[2] != 0xff) {
        result |= 2;
    }
    if (lbl_1_bss_71810[2] != 0xff) {
        result |= 4;
    }

    return result;
}
/* fzgx:end fn_1_B7C00 */

/* fzgx:begin fn_1_B7C5C */
u32 fn_1_B7C5C(void) {
    return lbl_1_bss_718B4;
}
#undef lbl_1_bss_71810
#undef lbl_1_bss_718B2
#undef lbl_1_bss_718B4
#undef lbl_1_bss_77328
/* fzgx:end fn_1_B7C5C */

/* fzgx:begin fn_1_B7C6C */
/* VIEWS */
s32 fn_1_B7C6C(u32 arg0) {
    u32 index = arg0 & 0xff;
    switch (index) {
    case 0:
    case 1:
        return lbl_1_bss_716C8[index].unk_1;
    default:
        break;
    }

    if (lbl_1_bss_718B1 == 5) {
        return 0;
    }
    return lbl_1_bss_716C8[lbl_1_bss_718B1].unk_1;
}
/* fzgx:end fn_1_B7C6C */

/* fzgx:begin fn_1_B7CD4 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
#define lbl_1_bss_7730A (*(u8 *)&lbl_1_bss_7730A)
/* VIEWS */
u8 fn_1_B7CD4(void) {
    return lbl_1_bss_718B8;
}
/* fzgx:end fn_1_B7CD4 */

/* fzgx:begin fn_1_B7CE4 */
void fn_1_B7CE4(s32 arg0, char *arg1) {
    const MemcardKind *kind;
    char *sep;
    s32 sec;

    if (arg0 != 1) {
        kind = &lbl_1_rodata_4AE0[arg0];
        if (lbl_801A66B4 == 5) {
            sep = "";
        } else {
            sep = " ";
        }
        sprintf(arg1, "%s%s%s", lbl_1_data_3B74C[kind->caption][lbl_801A66B4], sep,
                lbl_1_data_3B74C[78][lbl_801A66B4]);
    } else {
        OSCalendarTime ct;
        u8 buf[0x20];

        strncpy(arg1, ((u8 *)&lbl_1_bss_716C8 +
                ((s8)lbl_1_bss_7730A * 0xa0) + 0x54), 0x20);
        OSTicksToCalendarTime(OSGetTime(), &ct);
        sec = ((CalTime_1_B7CE4 *)&ct)->msec % 100;
        sprintf((char *)buf, "%02d/%02d/%02d ",
                sec, ((CalTime_1_B7CE4 *)&ct)->min + 1,
                ((CalTime_1_B7CE4 *)&ct)->hour);
        strncpy(arg1, buf, 8);
    }
}
/* fzgx:end fn_1_B7CE4 */

/* fzgx:begin fn_1_B7E14 */
// Save the current memory-card state in the global work buffer.

/* Unknown retail object: 4 unread zero bytes of .data after fn_1_B7CE4's strings */
static u8 lbl_1_data_3CE68[4] = {0};

void fn_1_B7E14(void *memory_card_state) {
    strncpy(lbl_1_bss_716C8.pad_54, memory_card_state, 0x20);
}
/* fzgx:end fn_1_B7E14 */

/* fzgx:begin fn_1_B7E48 */
// Return whether either tracked object has its active flag set.

int fn_1_B7E48(void) {
    int result = 0;
    Obj_1_bss_716C8_At24 *object = lbl_1_bss_716C8.unk_24;

    if (object != 0 && (object->unk_8 & 0x200) != 0) {
        result = 1;
    }

    object = *(Obj_1_bss_716C8_At24 **)(lbl_1_bss_716C8.pad_A0 + 0x24);
    if (object != 0 && (object->unk_8 & 0x200) != 0) {
        result = 1;
    }

    return result;
}
/* fzgx:end fn_1_B7E48 */

/* fzgx:begin fn_1_B7E98 */
// Return whether the indexed memory-card entry is not in the unavailable state.

#undef lbl_1_bss_716C8
int fn_1_B7E98(int index) {
    return lbl_1_bss_716C8[index].unk_1 != -3;
}
/* fzgx:end fn_1_B7E98 */

/* fzgx:begin fn_1_B7EC4 */
int fn_1_B7EC4(int index) {
    int result = 0;
    s8 value = lbl_1_bss_716C8[index].unk_1;

    if (value != -1 && value != -3) {
        result = 1;
    }
    return result;
}
#undef lbl_1_bss_7730A
/* fzgx:end fn_1_B7EC4 */

/* fzgx:begin fn_1_B7EF8 */
/* VIEWS */
#define lbl_1_bss_718B9 (*(u8 (*)[7])&lbl_1_bss_718B9)
// fn_1_B7EF8: Load and return first byte from lbl_1_bss_718B9

s32 fn_1_B7EF8(void) {
    return lbl_1_bss_718B9[0];
}
#undef lbl_1_bss_718B9
/* fzgx:end fn_1_B7EF8 */

/* fzgx:begin fn_1_B7F08 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
#define lbl_1_bss_718B4 (*(u32 *)&lbl_1_bss_718B4)
#define lbl_1_bss_718C0 (*(Obj_1_bss_718C0 *)&lbl_1_bss_718C0)
#define lbl_1_bss_7730A (*(u8 *)&lbl_1_bss_7730A)
u32 fn_1_B7F08(void) {
    return lbl_1_bss_718B4 != 0;
}
/* fzgx:end fn_1_B7F08 */

/* fzgx:begin fn_1_B7F24 */
// Clear the operation state and mark the memory card as unavailable.

void fn_1_B7F24(void) {
#define reset_state (*(MemcardResetView *)&lbl_1_bss_716C8)

    reset_state.unk_50 = 0;
    reset_state.unk_F0 = 0;
    reset_state.unk_4C = 0;
    reset_state.unk_48 = 0;
    reset_state.unk_EC = 0;
    reset_state.unk_E8 = 0;
    *(s8 *)&lbl_1_bss_7730A = -1;
}
/* fzgx:end fn_1_B7F24 */

/* fzgx:begin fn_1_B7F58 */
int fn_1_B7F58(s64 *time) {
    s8 index = lbl_1_bss_7730A;
    Obj_1_bss_716C8 *entry;

    if (index == -1) {
        *time = 0;
        return 0;
    }
    entry = (Obj_1_bss_716C8 *)((u8 *)&lbl_1_bss_716C8 + index * 0xa0);
    if ((s32)entry->unk_50 == 0) {
        *time = 0;
        return 0;
    }
    /* unk_48/unk_4C hold one s64 (the generated header splits it into two words) */
    *time = *(s64 *)&entry->unk_48;
    return 1;
}
/* fzgx:end fn_1_B7F58 */

/* fzgx:begin fn_1_B7FC8 */
u32 fn_1_B7FC8(void) {
    return lbl_1_bss_718C0.unk_0->unk_0;
}
/* fzgx:end fn_1_B7FC8 */

/* fzgx:begin fn_1_B7FDC */
// Toggles the low 16-bit status value and stores the result.

void fn_1_B7FDC(u8 unused) {
    u16 value = fn_8002A744();
    value = (value ^ 1);
    fn_8002A74C(value);
}
/* fzgx:end fn_1_B7FDC */

/* fzgx:begin fn_1_B800C */
// Loads a memory-card slot, retrying transient operations and cleaning up failures.

#undef lbl_1_bss_716C8
int fn_1_B800C(s32 index) {
    int status;
    fn_1_AAB98_Entry *card;

    card = &lbl_1_bss_716C8[index];
    card->unk_C = (fn_1_45D0((u32)lbl_801A6410, 0xA000, (void *)"memcard.c", 0x256D));
    do {
        status = fn_8002DFE0(index, card->unk_C, 0);
    } while (status == -1);
    if (status != 0 && status != -6) {
        if (card->unk_C != 0) {
            fn_1_46B4(lbl_801A6410, card->unk_C, "memcard.c", 0x2573);
            card->unk_C = 0;
        }
        return status;
    }
    do {
        status = CARDCheck(index);
    } while (status == -1);
    return status;
}
/* fzgx:end fn_1_B800C */

/* fzgx:begin fn_1_B80F0 */
// Wait for the card operation to finish, then release its temporary result.

void fn_1_B80F0(s32 index) {
    fn_1_AAB98_Entry *entry = &lbl_1_bss_716C8[index];

    for (;;) {
        if (CARDUnmount(index) != -1) {
            break;
        }
    }

    if (entry->unk_C != 0) {
        fn_1_46B4(lbl_801A6410, entry->unk_C,
                  "memcard.c", 0x258c);
        entry->unk_C = 0;
    }
}
#undef reset_state
#undef lbl_1_bss_718B4
#undef lbl_1_bss_718C0
#undef lbl_1_bss_7730A
/* fzgx:end fn_1_B80F0 */

/* fzgx:begin fn_1_B8170 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
static inline s32 wait_card(s32 card, void *work, void *entry) {
    s32 result;

    do {
        result = CARDOpen(card, (const char *)work, (CARDFileInfo *)entry);
    } while (result == -1);
    return result;
}

static inline s32 wait_write(void *entry) {
    s32 result;

    do {
        result = CARDClose((CARDFileInfo *)entry);
    } while (result == -1);
    return result;
}

u32 fn_1_B8170(s32 card) {
    u8 work1[0x40];
    u8 work2[0x40];
    const char *table;
    u32 flags;
    u8 *entry;

    entry = (u8 *)&lbl_1_bss_716C8 + card * 0xa0;
    table = lbl_1_rodata_4AE0[1].name;
    flags = 0;

    strcpy(work1, (void *)table);
    strcat(work1, ".dat");
    if (wait_card(card, work1, entry + 0x10) == 0) {
        wait_write(entry + 0x10);
        flags |= 2;
    } else {
        strcpy(work2, (void *)table);
        strcat(work2, ".000");
        if (wait_card(card, work2, entry + 0x10) == 0) {
            wait_write(entry + 0x10);
            flags |= 2;
        } else {
            flags &= ~2;
        }
    }

    table = lbl_1_rodata_4AE0[3].name;
    strcpy(work1, (void *)table);
    strcat(work1, ".dat");
    if (wait_card(card, work1, entry + 0x10) == 0) {
        wait_write(entry + 0x10);
        flags |= 8;
    } else {
        strcpy(work2, (void *)table);
        strcat(work2, ".000");
        if (wait_card(card, work2, entry + 0x10) == 0) {
            wait_write(entry + 0x10);
            flags |= 8;
        } else {
            flags &= ~8;
        }
    }
    return flags;
}
#undef lbl_1_bss_716C8
/* fzgx:end fn_1_B8170 */

/* fzgx:begin fn_1_B8338 */
/* VIEWS */
/* VIEWS */
#define lbl_801A6410 (*(u32 *)&lbl_801A6410)
static inline s32 fileBlocks(fn_1_AAB98_Entry *c, s32 i)
{
    s32 freeBytes = c->unk_3C;
    s32 n = (lbl_1_rodata_4AE0[i].unk_40 + 0x405F) & ~0x1FFF;
    n /= 0x2000;
    if (lbl_1_rodata_4AE0[i].unk_40 == 0) {
        if (lbl_1_rodata_4AE0[i].index == 4) {
            n = 3;
        } else if (lbl_1_rodata_4AE0[i].index == 5) {
            n = 13;
        } else if (lbl_1_rodata_4AE0[i].index == 2) {
            n = 3;
        }
    }
    if (c->unk_40 <= 0) {
        return -n;
    }
    if (freeBytes - n >= 0) {
        return n;
    }
    return -n;
}

s32 fn_1_B8338(s32 chan)
{
    fn_1_AAB98_Entry *c;
    s32 result;
    BOOL ok;

    lbl_1_bss_77334 = 0;
    lbl_1_bss_77338 = 1;
    lbl_1_bss_77339 = chan;
    ok = FALSE;
    if (lbl_1_bss_716C8[chan].unk_1 != -1 && lbl_1_bss_716C8[chan].unk_1 != -3) {
        ok = TRUE;
    }
    if (!ok) {
        return 0;
    }
    c = &lbl_1_bss_716C8[chan];
    c->unk_C = fn_1_45D0(lbl_801A6410, 0xA000, "memcard.c", 0x256D);
    while ((result = fn_8002DFE0(chan, c->unk_C, NULL)) == -1) {
    }
    if (result != 0 && result != -6) {
        if (c->unk_C != NULL) {
            fn_1_46B4(lbl_801A6410, (u32)c->unk_C, "memcard.c", 0x2573);
            c->unk_C = NULL;
        }
    } else {
        s32 r;
        while ((r = CARDCheck(chan)) == -1) {
        }
        result = r;
    }
    if (result != 0) {
        while (CARDUnmount(chan) == -1) {
        }
        if (c->unk_C != NULL) {
            fn_1_46B4(lbl_801A6410, (u32)c->unk_C, "memcard.c", 0x258C);
            c->unk_C = NULL;
        }
        return 0;
    }
    while ((result = CARDFreeBlocks(chan, (s32 *)&c->unk_3C, (s32 *)&c->unk_40)) == -1) {
    }
    if (result != 0) {
        c->unk_3C = -1;
        c->unk_40 = -1;
    } else {
        c->unk_3C /= 0x2000;
    }
    lbl_1_bss_7733C[chan] = fn_1_B8170(chan);
    lbl_1_bss_77344[chan][1] = fileBlocks(c, 1);
    lbl_1_bss_77344[chan][3] = fileBlocks(c, 3);
    lbl_1_bss_77344[chan][2] = fileBlocks(c, 2);
    lbl_1_bss_77344[chan][4] = fileBlocks(c, 4);
    lbl_1_bss_77344[chan][5] = fileBlocks(c, 5);
    while (CARDUnmount(chan) == -1) {
    }
    if (c->unk_C != NULL) {
        fn_1_46B4(lbl_801A6410, (u32)c->unk_C, "memcard.c", 0x258C);
        c->unk_C = NULL;
    }
    if (lbl_1_bss_962 == 100) {
        if ((lbl_1_bss_77344[chan][4] < 0 && !(lbl_1_bss_7733C[chan] & 0x10)) || c->unk_40 <= 0) {
            return 1;
        }
        return 0;
    }
    if ((lbl_1_bss_77344[chan][1] < 0 && !(lbl_1_bss_7733C[chan] & 0x2)) ||
        (lbl_1_bss_77344[chan][3] < 0 && !(lbl_1_bss_7733C[chan] & 0x8)) ||
        (lbl_1_bss_77344[chan][2] < 0 && !(lbl_1_bss_7733C[chan] & 0x4)) ||
        (lbl_1_bss_77344[chan][4] < 0 && !(lbl_1_bss_7733C[chan] & 0x10)) ||
        (lbl_1_bss_77344[chan][5] < 0 && !(lbl_1_bss_7733C[chan] & 0x20)) ||
        c->unk_40 <= 0) {
        return 1;
    }
    return 0;
}
#undef lbl_801A6410
/* fzgx:end fn_1_B8338 */

/* fzgx:begin fn_1_B88C4 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Slot (*)[2])&lbl_1_bss_716C8)
/* VIEWS */
#define lbl_801A6410 (*(u32 *)&lbl_801A6410)
#define REL_MAIN_REL_MEMCARD_H

#define REL_MAIN_REL_GLOBALS_H

// "memcard.c": .data size 0xA, referenced by 21 functions, shape {'object': 52}

// lbl_1_bss_962: .bss size 0x2, 4 refs from memcard.c

/* end rel/main_rel/memcard.h */

static inline int valid(Slot *slots, s32 chan) { int v=0; s8 state = slots[chan].state; if(state!=-1 && state!=-3) v=1; return v; }

static inline void cleanup(Slot *p,int line) { if(p->work) { fn_1_46B4(lbl_801A6410,(u32)p->work,"memcard.c",line); p->work=0; } }

static inline s32 need(int off,Slot *p) {
 u8 *r=(u8 *)lbl_1_rodata_4AE0;
 s32 free=p->blocks;
 u32 size=*(u32 *)(r+off+0x24);
 s32 n=((size+0x405f)&~0x1fff);
 n/=8192;
 if(size==0) { u8 kind=r[off+3]; if(kind==4)n=3; else if(kind==5)n=13; else if(kind==2)n=3; }
 if(p->files<=0) return -n;
 if(free-n>=0) return n;
 return -n;
}

static inline s32 need_large(int off,Slot *p) {
 u8 *r=(u8 *)lbl_1_rodata_4AE0;
 u32 size=*(u32 *)(r+off+0x24);
 s32 n=((size+0x405f)&~0x1fff);
 s32 free=p->blocks;
 n/=8192;
 if(size==0) { u8 kind=r[off+3]; if(kind==4)n=3; else if(kind==5)n=13; else if(kind==2)n=3; }
 if(p->files<=0) return -n;
 if(free-n>=0) return n;
 return -n;
}

int fn_1_B88C4(void) {

 Slot *p;
 s32 result;
 /* WARNING: compiler-diff device, not original code */
 struct { s32 value; } chan;
 lbl_1_bss_77334=0; lbl_1_bss_77338=1;
 if(!valid(lbl_1_bss_716C8,0) && !valid(lbl_1_bss_716C8,1)) return 0;
 chan.value=lbl_1_bss_718B1;
 if((u32)chan.value>1)return 0;
 p=lbl_1_bss_716C8; p+=chan.value;
 p->work=fn_1_45D0(lbl_801A6410,0xa000,"memcard.c",0x256d);
 do {result=fn_8002DFE0(chan.value,p->work,0);}while(result==-1);
 if(result!=0 && result!=-6) {cleanup(p,0x2573);}
 else { s32 check; do{check=CARDCheck(chan.value);}while(check==-1); result=check; }
 if(result!=0) {
 do{result=CARDUnmount(chan.value);}while(result==-1);
 cleanup(p,0x258c); return 0;
 }
 do{result=CARDFreeBlocks(chan.value,(s32 *)&p->blocks,(s32 *)&p->files);}while(result==-1);
 if(result!=0) {p->blocks=-1;p->files=-1;}else p->blocks/=8192;
 lbl_1_bss_7733C[chan.value]=fn_1_B8170(chan.value);
 lbl_1_bss_77344[chan.value][1]=need(0x68,p);
 lbl_1_bss_77344[chan.value][3]=need(0x100,p);
 lbl_1_bss_77344[chan.value][2]=need(0xb4,p);
 lbl_1_bss_77344[chan.value][4]=need_large(0x14c,p);
 lbl_1_bss_77344[chan.value][5]=need_large(0x198,p);
 do{result=CARDUnmount(chan.value);}while(result==-1);
 cleanup(p,0x258c);
 if(lbl_1_bss_962==100) {
 if((lbl_1_bss_77344[chan.value][4]<0 && !(lbl_1_bss_7733C[chan.value]&16)) || p->files<=0)return 1;
 return 0;
 }
 if((lbl_1_bss_77344[chan.value][1]<0 && !(lbl_1_bss_7733C[chan.value]&2)) ||
 (lbl_1_bss_77344[chan.value][3]<0 && !(lbl_1_bss_7733C[chan.value]&8)) ||
 (lbl_1_bss_77344[chan.value][2]<0 && !(lbl_1_bss_7733C[chan.value]&4)) ||
 (lbl_1_bss_77344[chan.value][4]<0 && !(lbl_1_bss_7733C[chan.value]&16)) ||
 (lbl_1_bss_77344[chan.value][5]<0 && !(lbl_1_bss_7733C[chan.value]&32)) || p->files<=0)return 1;
 return 0;
}
#undef lbl_801A6410
#undef REL_MAIN_REL_MEMCARD_H
#undef REL_MAIN_REL_GLOBALS_H
#undef lbl_1_bss_716C8
/* fzgx:end fn_1_B88C4 */

/* fzgx:begin fn_1_B8E84 */
/* VIEWS */
#define lbl_1_bss_7733C (*(u32 (*)[17])&lbl_1_bss_7733C)
void fn_1_B8E84(s32 card, u8 *out_flags, u32 *out_a, u32 *out_b) {
    *out_flags = (1 << card) & lbl_1_bss_7733C[lbl_1_bss_77339];
    *out_a = lbl_1_bss_716C8[lbl_1_bss_77339].unk_3C;
    *out_b = lbl_1_bss_716C8[lbl_1_bss_77339].unk_40;
}
#undef lbl_1_bss_7733C
/* fzgx:end fn_1_B8E84 */

/* fzgx:begin fn_1_B8EDC */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u32 (*)[2])&lbl_1_bss_716C0)
#define lbl_1_bss_77334 (*(u8 *)&lbl_1_bss_77334)
#define lbl_1_bss_7733C (*(u8 *)&lbl_1_bss_7733C)
#define lbl_1_bss_77344 (*(u8 *)&lbl_1_bss_77344)
/* Overlay for the per-slot flag words inside lbl_1_bss_716C0. */

s32 fn_1_B8EDC(s32 index)
{
    static const u32 color_header[1] = {0xFF402000};
    static const u32 color_fade[1] = {0xFFFFFF00};

s32 *a;
s32 *b;
s32 *c;
s32 *d;
s32 *e;
s32 y;
s32 slide;
u32 fade;
f32 t;
f32 alpha;
u32 color;
s32 count;
s32 old;
t = (*(s32 *)(&lbl_1_bss_77334)) / 15.0f ;
alpha = t * t;
if (lbl_1_bss_77338) {
slide = (320.0f * (1.0f - alpha));
} else {
slide = (320.0f * -(1.0f - alpha));
}
fn_1_4D0A0();
fn_1_4AEC0(1);
fn_1_4AEB4(1.5f );
fn_1_49410();
if (lbl_801A66B4 != 5) {
fn_1_49590(0.5f );
fn_1_495B0(0x80000000);
}
fn_1_49614();
fn_1_494DC(5);
fn_1_495B0(0x80000000);
fn_1_49738((void *)((u32)fn_1_B5F00));
fn_1_49748(5.0f );
fn_1_49590(0.5f );
fn_1_495C8(9);
fn_1_496FC((slide + 320), 100.0f );
fn_1_4954C(0.09f );
color = ((0x3d4)==0x3d4 ? color_header[0] : color_fade[0]) ;
fn_1_49514(&color);
fn_1_4955C(1.1111111640930176f , 1.1111111640930176f );
if ((lbl_801A66C8 & 63) < 48) {
fn_1_495A0(alpha);
} else {
fn_1_495A0(0.01f * alpha);
}
fn_1_4AE0C((const char *)(((u8 *)((u32 *)"WARNING"))));
fn_1_49410();
fn_1_4966C(0.0f , 8.0f );
if (lbl_801A66B4 != 5) {
fn_1_49590(0.5f );
fn_1_495B0(0x80000000);
fn_1_4966C(0.0f , 3.0f );
}
fn_1_495FC();
fn_1_4955C(0.7f , 0.7f );
fn_1_495C8(9);
fn_1_495A0(alpha);
fn_1_496FC((slide + 320), 185.0f );
if (index == 0) {
fn_1_4AE0C(lbl_1_data_3B74C[86][lbl_801A66B4],
           lbl_1_data_3B74C[37][lbl_801A66B4]);
} else {
fn_1_4AE0C(lbl_1_data_3B74C[86][lbl_801A66B4],
           lbl_1_data_3B74C[38][lbl_801A66B4]);
}
count = 0;
a = (s32 *)(&lbl_1_bss_77344 + 8) + index * 6;
if (*(a -= 1) < 0 && !(((u32 *)(&lbl_1_bss_7733C))[index] & 2)) count = 1;
b = (s32 *)(&lbl_1_bss_77344 + 16) + index * 6;
if (*(b -= 1) < 0 && !(((u32 *)(&lbl_1_bss_7733C))[index] & 8)) count++;
c = (s32 *)(&lbl_1_bss_77344 + 12) + index * 6;
if (*(c -= 1) < 0 && !(((u32 *)(&lbl_1_bss_7733C))[index] & 4)) count++;
d = (s32 *)(&lbl_1_bss_77344 + 20) + index * 6;
if (*(d -= 1) < 0 && !(((u32 *)(&lbl_1_bss_7733C))[index] & 16)) count++;
e = (s32 *)(&lbl_1_bss_77344 + 24) + index * 6;
if (*(e -= 1) < 0 && !(((u32 *)(&lbl_1_bss_7733C))[index] & 32)) count++;
y = 330 - (count - 1) * 25 / 2;
fn_1_495C8(8);
fn_1_4955C(0.7f , 0.7f );
if (*a < 0 && !((((u32 *)(&lbl_1_bss_7733C))[index]) & 2) && lbl_1_bss_962 != 100) {
fn_1_496FC((slide + 130), y);
fn_1_4AE0C(lbl_1_data_3B74C[85][lbl_801A66B4]);
fn_1_496FC((slide + 255), y);
fn_1_4AE0C(lbl_1_data_3B74C[87][lbl_801A66B4]);
fn_1_496FC((slide + 360), y);
fn_1_4AE0C((const char *)((u32 *)"/bcffa0a0/      \202S/bcffffff/"));
y += 25;
}
if (*b < 0 && !((((u32 *)(&lbl_1_bss_7733C))[index]) & 8) && lbl_1_bss_962 != 100) {
fn_1_496FC((slide + 130), y);
fn_1_4AE0C(lbl_1_data_3B74C[84][lbl_801A66B4]);
fn_1_496FC((slide + 255), y);
fn_1_4AE0C(lbl_1_data_3B74C[87][lbl_801A66B4]);
fn_1_496FC((slide + 360), y);
fn_1_4AE0C((const char *)((u32 *)"/bcffa0a0/    \202P\202W/bcffffff/"));
y += 25;
}
if (*c < 0 && !((((u32 *)(&lbl_1_bss_7733C))[index]) & 4) && lbl_1_bss_962 != 100) {
fn_1_496FC((slide + 130), y);
fn_1_4AE0C(lbl_1_data_3B74C[83][lbl_801A66B4]);
fn_1_496FC((slide + 255), y);
fn_1_4AE0C(lbl_1_data_3B74C[87][lbl_801A66B4]);
fn_1_496FC((slide + 360), y);
fn_1_4AE0C((const char *)((u32 *)"/bcffa0a0/      \202R/bcffffff/"));
y += 25;
}
if (*d < 0 && !((((u32 *)(&lbl_1_bss_7733C))[index]) & 16)) {
fn_1_496FC((slide + 130), y);
fn_1_4AE0C(lbl_1_data_3B74C[82][lbl_801A66B4]);
fn_1_496FC((slide + 255), y);
fn_1_4AE0C(lbl_1_data_3B74C[87][lbl_801A66B4]);
fn_1_496FC((slide + 360), y);
fn_1_4AE0C((const char *)((u32 *)"/bcffa0a0/      \202R/bcffffff/"));
y += 25;
}
if (*e < 0 && !((((u32 *)(&lbl_1_bss_7733C))[index]) & 32) && lbl_1_bss_962 != 100) {
fn_1_496FC((slide + 130), y);
fn_1_4AE0C(lbl_1_data_3B74C[81][lbl_801A66B4]);
fn_1_496FC((slide + 255), y);
fn_1_4AE0C(lbl_1_data_3B74C[87][lbl_801A66B4]);
fn_1_496FC((slide + 360), y);
fn_1_4AE0C((const char *)((u32 *)"/bcffa0a0/\202R\201`\202P\202R/bcffffff/"));
}
fade = ((0x3d8)==0x3d4 ? color_header[0] : color_fade[0]) ;
((u8 *)&fade)[3] = (255.0f * alpha);
fn_1_4D274(*(Color *)&fade, 40.0f );
fn_1_4AEC0(0);
fn_1_4AEB4(0.0f );
if (lbl_1_bss_77338) {
old = (*(s32 *)(&lbl_1_bss_77334)) ;
(*(s32 *)(&lbl_1_bss_77334)) = old + 1;
if (old >= 15) (*(s32 *)(&lbl_1_bss_77334)) = 15;
if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) && (*(s32 *)(&lbl_1_bss_77334)) >= 15)
lbl_1_bss_77338 = 0;
} else {
old = (*(s32 *)(&lbl_1_bss_77334)) ;
(*(s32 *)(&lbl_1_bss_77334)) = old - 1;
if (old < 0) return 1;
}
return 0;
}
#undef lbl_1_bss_716C0
#undef lbl_1_bss_77334
#undef lbl_1_bss_7733C
#undef lbl_1_bss_77344
/* fzgx:end fn_1_B8EDC */

/* fzgx:begin fn_1_B9904 */
void fn_1_B9904(s32 idx, u8 state, s32 type, u32 arg3) {
    fn_1_AAB98_Obj *work;

    lbl_1_bss_716C8[idx].unk_24 = (void *)fn_1_4630(lbl_801A6410, 0xF0, "memcard.c", 0x2744);
    lbl_1_bss_716C8[idx].unk_2 = state;
    lbl_1_bss_716C8[idx].unk_24->unk_4 = arg3;
    lbl_1_bss_716C8[idx].unk_24->unk_0 = type;
    lbl_1_bss_716C8[idx].unk_24->unk_8C = (AAF1C_Info *)&lbl_1_rodata_4AE0[type];
    lbl_1_bss_716C8[idx].unk_24->unk_94 = (void *)fn_1_4630(lbl_801A6410, 0xF0, "memcard.c", 0x2749);
    lbl_1_bss_716C8[idx].unk_24->unk_8 = 4;
    fn_1_AAF1C(&lbl_1_bss_716C8[idx]);
    lbl_1_bss_716C8[idx].unk_A = -1;
    fn_1_B6B28();

    if (lbl_1_bss_716C8[idx].unk_C != 0) {
        while (CARDUnmount(lbl_1_bss_716C8[idx].unk_0) == -1) {
        }
        fn_1_46B4(lbl_801A6410, lbl_1_bss_716C8[idx].unk_C, "memcard.c", 0x3C8);
        lbl_1_bss_716C8[idx].unk_7 = 0;
        lbl_1_bss_716C8[idx].unk_C = 0;
        work = lbl_1_bss_716C8[idx].unk_24;
        work->unk_1C = 0;
        work->unk_18 = 0;
    }
    if (lbl_1_bss_716C8[idx].unk_24->unk_8 & 0x80) {
        lbl_1_bss_716C8[idx].unk_3C = lbl_1_bss_716C8[idx].unk_24->unk_10 / 8192;
        lbl_1_bss_716C8[idx].unk_40 = lbl_1_bss_716C8[idx].unk_24->unk_14;
    }
    if (!(lbl_1_bss_716C8[idx].unk_24->unk_8 & 0x20)) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_716C8[idx].unk_24->unk_94, "memcard.c", 0x3D4);
    }
    if (lbl_1_bss_716C8[idx].unk_2 == 4) {
        if (lbl_1_bss_716C0 != 0) {
            void *tmp;
            fn_1_AAB98_Obj *w = lbl_1_bss_716C8[idx].unk_24;
            tmp = w->unk_94;
            w->unk_94 = w->unk_DC;
            w->unk_DC = tmp;
            lbl_1_bss_716C0 = 0;
        }
        if (lbl_1_bss_716C8[idx].unk_24->unk_DC != 0) {
            fn_1_46B4(lbl_801A6410, lbl_1_bss_716C8[idx].unk_24->unk_DC, "memcard.c", 0x3DE);
            lbl_1_bss_716C8[idx].unk_24->unk_DC = 0;
        }
    }
    fn_1_46B4(lbl_801A6410, lbl_1_bss_716C8[idx].unk_24, "memcard.c", 0x3EC);
    lbl_1_bss_716C8[idx].unk_24 = 0;
    lbl_1_bss_716C8[idx].unk_2 = 0xFF;
    lbl_1_bss_716C8[idx].unk_3 = 0xFF;
    lbl_1_bss_716C8[idx].unk_4 = 0xFF;
    lbl_1_bss_716C8[idx].unk_5 = 0xFF;
    lbl_1_bss_716C8[idx].unk_6 = 0xFF;
    lbl_1_bss_716C8[idx].unk_7 = 0;
    lbl_1_bss_716C8[idx].unk_8 = -1;
    lbl_1_bss_716C8[idx].unk_A = -1;
    lbl_1_bss_716C8[idx].unk_30 = 0;
    lbl_1_bss_716C8[idx].unk_34 = 0.0f;
    lbl_1_bss_716C8[idx].unk_38 = 0.0f;
    lbl_1_bss_772C8[0] = 0;
    lbl_1_bss_716C8[idx].unk_2A &= ~4;

    if (lbl_1_bss_716C8[idx].unk_24 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_716C8[idx].unk_24, "memcard.c", 0x2750);
        lbl_1_bss_716C8[idx].unk_24 = 0;
    }
}
/* fzgx:end fn_1_B9904 */

/* fzgx:begin fn_1_B9BE0 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
#define lbl_1_bss_77380 (*(Obj_1_bss_77380 *)&lbl_1_bss_77380)
void fn_1_B9BE0(void) {
    fn_1_B9C38(0);
    fn_1_B9C38(1);
}
/* fzgx:end fn_1_B9BE0 */

/* fzgx:begin fn_1_B9C0C */
void fn_1_B9C0C(void) {
    fn_1_B9C38(0);
    fn_1_B9C38(1);
}
/* fzgx:end fn_1_B9C0C */

/* fzgx:begin fn_1_B9C38 */
// Saves populated slots before resetting each slot for reuse.

void fn_1_B9C38(s32 index) {
    Obj_1_bss_77380 *slot;
    u8 *slot_bytes;
    s32 slot_index;

    slot = (Obj_1_bss_77380 *)((u8 *)&lbl_1_bss_77380 + index * 0x1800);
    for (slot_index = 0; slot_index < 0x7f; slot_index++) {
        slot_bytes = (u8 *)slot;
        if (slot->unk_2C != 0) {
            fn_1_46B4(lbl_801A6410, slot->unk_2C, "memcard.c", 0x2776);
        }

        slot_bytes[1] = 0;
        slot_bytes[2] = 0;
        slot->unk_24 = 0;
        slot->unk_28 = 0;
        slot->unk_2C = 0;
        slot = (Obj_1_bss_77380 *)(slot_bytes + 0x30);
    }
}
/* fzgx:end fn_1_B9C38 */

/* fzgx:begin fn_1_B9CCC */
void fn_1_B9CCC(s32 index, u32 flags) {
    u8 *table;
    MemcardRequest request;
    s32 valid;
    s32 bit_27;
    s32 bit_29;
    s32 bit_26;
    s32 count;
    u32 offset;
    MemcardEntry_B9BE0 *entry;

    valid = 0;
    offset = index * 0xA0;
    entry = (MemcardEntry_B9BE0 *)&lbl_1_bss_716C8;
    entry = (MemcardEntry_B9BE0 *)((u8 *)entry + offset);
    if (entry->unk_1 != -1 && entry->unk_1 != -3) {
        valid = 1;
    }
    if (valid) {
        count = 0;
        bit_27 = flags & 0x10;
        if (bit_27) {
            count = 1;
        }
        bit_26 = flags & 0x20;
        if (bit_26) {
            count += 1;
        }
        bit_29 = flags & 0x04;
        if (bit_29) {
            count += 1;
        }
        fn_80008BEC(&request, 0, 0x24);
        table = (u8 *)&lbl_1_bss_77380 + index * 0x1800;
        fn_80008BEC(table, 0, 0x30);
        request.unk_0C = (Obj_1_bss_77380 *)table;
        request.unk_20 = flags;
        if (count == 1) {
            if (bit_27) {
                request.unk_0 = 4;
            } else if (bit_29) {
                request.unk_0 = 2;
            } else if (bit_26) {
                request.unk_0 = 5;
            }
        }
        fn_1_AA6D8(4, (u8)index, (void *)&request);
    }
}
#undef lbl_1_bss_716C8
#undef lbl_1_bss_77380
/* fzgx:end fn_1_B9CCC */

/* fzgx:begin fn_1_B9DE8 */
/* VIEWS */
#define lbl_1_bss_716C8 (*(Obj_1_bss_716C8 *)&lbl_1_bss_716C8)
#define lbl_1_bss_7A380 (*(u32 *)&lbl_1_bss_7A380)
#define lbl_1_bss_7A388 (*(u32 (*)[5])&lbl_1_bss_7A388)
#define lbl_1_data_35AC8 (*(u8 (*)[0x4])&lbl_1_data_35AC8)
#define lbl_1_data_35B5C (*(u8 (*)[0x40])&lbl_1_data_35B5C)
#define lbl_1_data_35B9C (*(u8 (*)[0x40])&lbl_1_data_35B9C)
#define lbl_1_data_35BDC (*(u8 (*)[0x18])&lbl_1_data_35BDC)
/* VIEWS */
#define lbl_801A6410 (*(u32 *)&lbl_801A6410)
#define lbl_801A66B4 (*(u32 *)&lbl_801A66B4)
#define FILE_STR ((const char *)"memcard.c")

static inline s32 fn_1_B9DE8_mount(u32 data, s32 chan) {
    s32 result;
    MemcardSlot_B9DE8 *slot = (MemcardSlot_B9DE8 *)&lbl_1_bss_716C8 + chan;
    slot->unk_C = fn_1_45D0(lbl_801A6410, 0xA000, FILE_STR, 0x256D);
    do {
        result = fn_8002DFE0(chan, slot->unk_C, 0);
    } while (result == -1);
    if (result != 0 && result != -6) {
        if (slot->unk_C != 0) {
            fn_1_46B4(lbl_801A6410, (u32)slot->unk_C, FILE_STR, 0x2573);
            slot->unk_C = 0;
        }
    } else {
        s32 tmp;
        do {
            tmp = CARDCheck(chan);
        } while (tmp == -1);
        result = tmp;
    }
    return result;
}

static inline void fn_1_B9DE8_unmount(u32 data, s32 chan) {
    MemcardSlot_B9DE8 *slot = (MemcardSlot_B9DE8 *)&lbl_1_bss_716C8 + chan;
    do {
    } while (CARDUnmount(chan) == -1);
    if ((slot->unk_C) != 0) {
        fn_1_46B4(lbl_801A6410, (u32)slot->unk_C, FILE_STR, 0x258C);
        slot->unk_C = 0;
    }
}

/* expanded in place: both slots share the caller's serial pointer */

#define fn_1_B9DE8_slot(data, chan) do { \
    if (fn_1_B9DE8_mount(data, chan) == 0) { \
        serial = &((MemcardSlot_B9DE8 *)&lbl_1_bss_716C8)[chan].unk_98; \
        if (CARDGetSerialNo(chan, (u64 *)serial) != 0) { \
            *serial = 0; \
        } \
        ((u64 *)lbl_1_bss_7A388)[chan] = *serial; \
    } else { \
        ((u64 *)lbl_1_bss_7A388)[chan] = 0; \
    } \
    fn_1_B9DE8_unmount(data, chan); \
} while (0)

void fn_1_B9DE8(MemcardArg_B9DE8 *arg0) {
    u32 data = (u32)&lbl_1_data_35AC8;
    u32 *lang = &lbl_801A66B4;
    u32 *flag = &lbl_1_bss_7A380;
    u64 *serial;
    fn_80008BEC((void *)arg0, 0, 0x48);
    arg0->unk_22 = 3;
    arg0->unk_1A = -1;
    arg0->unk_1C = -1;
    *flag = 0;
    fn_1_465D0(((s32 *)lbl_1_data_35B5C)[lbl_801A66B4], 1);
    fn_1_465D0(((s32 *)lbl_1_data_35B9C)[lbl_801A66B4], 1);
    fn_1_465D0(((s32 *)lbl_1_data_35BDC)[lbl_801A66B4], 1);
    arg0->unk_3C = 0xFF;
    arg0->unk_3D = 0;
    fn_1_B9DE8_slot(data, 0);
    fn_1_B9DE8_slot(data, 1);
}
#undef lbl_801A6410
#undef lbl_801A66B4
#undef FILE_STR
#undef fn_1_B9DE8_slot
#undef lbl_1_bss_716C8
#undef lbl_1_bss_7A380
#undef lbl_1_bss_7A388
#undef lbl_1_data_35AC8
#undef lbl_1_data_35B5C
#undef lbl_1_data_35B9C
#undef lbl_1_data_35BDC
/* fzgx:end fn_1_B9DE8 */

/* fzgx:begin fn_1_BA144 */
/* VIEWS */
/* VIEWS */
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)
#define lbl_1_bss_9F8 (*(Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)
#define lbl_801A6410 (*(struct fn_1_BA144_lbl_801A6410 *)&lbl_801A6410)

#define gMeta (*(u8 (*)[2][127][8])&lbl_1_bss_7A39C)

static inline u8 BA_pending(void) {
u8 bits = 0;
if (lbl_1_bss_716C8[0].unk_2 != 255) bits |= 1;
if (lbl_1_bss_716C8[1].unk_2 != 255) bits |= 2;
if (lbl_1_bss_71810.unk_2 != 255) bits |= 4;
return bits;
}

static inline s8 BA_status(s32 chan) {
return lbl_1_bss_716C8[chan].unk_1;
}

static inline s32 BA_busy(void) {
return lbl_1_bss_718B8;
}

static inline s32 BA_available(s32 chan) {
s32 result = 0;
if ((s8)lbl_1_bss_716C8[chan].unk_1 != -1 && (s8)lbl_1_bss_716C8[chan].unk_1 != -3) result = 1;
return result;
}

static inline void BA_clear(s32 chan) {
s32 i;
for (i = 0; i < 127; i++) {
if (lbl_1_bss_77380[chan][i].info)
fn_1_46B4(lbl_801A6410.unk_0, (u32)lbl_1_bss_77380[chan][i].info, "memcard.c", 0x2776);
lbl_1_bss_77380[chan][i].type = 0;
lbl_1_bss_77380[chan][i].unk_2 = 0;
lbl_1_bss_77380[chan][i].size = 0;
lbl_1_bss_77380[chan][i].time = 0;
lbl_1_bss_77380[chan][i].info = 0;
}
}

static inline s32 BA_start_mount(s32 chan) {
s32 result;
fn_1_AAB98_Entry *port = &lbl_1_bss_716C8[chan];
port->unk_C = fn_1_45D0(lbl_801A6410.unk_0, 0xA000, "memcard.c", 0x256D);
do { result = fn_8002DFE0(chan, port->unk_C, 0); } while (result == -1);
if (result != 0 && result != -6) {
if (port->unk_C) {
fn_1_46B4(lbl_801A6410.unk_0, (u32)port->unk_C, "memcard.c", 0x2573);
port->unk_C = 0;
}
} else {
s32 check;
do { check = ((s32)CARDCheck(chan)); } while (check == -1);
result = check;
}
return result;
}

static inline void BA_finish_mount(s32 chan) {
fn_1_AAB98_Entry *port = &lbl_1_bss_716C8[chan];
while (CARDUnmount(chan) == -1) {}
if (port->unk_C) {
fn_1_46B4(lbl_801A6410.unk_0, (u32)port->unk_C, "memcard.c", 0x258C);
port->unk_C = 0;
}
}

static inline void BA_mount_into(u64_L **serialp, s32 chan) {
s32 result = BA_start_mount(chan);
if (result == 0) {
*serialp = (u64_L *)((u8 *)lbl_1_bss_716C8 + (0x98 + chan * sizeof(fn_1_AAB98_Entry)));
if (((s32)CARDGetSerialNo(chan, (u64 *)((void *)(*serialp)))) != 0) **serialp = 0;
lbl_1_bss_7A388[chan] = **serialp;
} else lbl_1_bss_7A388[chan] = 0;
BA_finish_mount(chan);
}

static inline void BA_request_flags(s32 chan, u32 *flagsp) {
s32 flags = *flagsp;
s32 count;
BARequest request;
if (BA_available(chan)) {
count = 0;
if (flags & 0x10) count = 1;
if (flags & 0x20) count++;
if (flags & 4) count++;
fn_80008BEC((void *)&request, 0, 0x24);
fn_80008BEC((void *)&lbl_1_bss_77380[chan][0], 0, 0x30);
request.unk_C = &lbl_1_bss_77380[chan][0];
request.unk_20 = flags;
if (count == 1) {
if (flags & 0x10) request.unk_0 = 4;
else if (flags & 4) request.unk_0 = 2;
else if (flags & 0x20) request.unk_0 = 5;
}
fn_1_AA6D8(4, chan, (void *)&request);
}
}

static inline s32 BA_enabled_state(s32 chan, s32 flags) {
return flags & (1 << chan);
}


s32 fn_1_BA144(fn_1_EF4F8_Obj_1_bss_7ECB4 *arg0) {
BAState *st = (BAState *)arg0;
u32 i;
u32 count;
s32 rank;
struct { u8 a, b, c; u8 pad[9]; } out20;
u32 out1c, out18, out14;
u8 out13, out12, out11, out10;
s16 n;
u64_L *serial;
if (BA_pending()) {
if ((s8)lbl_1_bss_716C8[st->unk_16].unk_1 == -3) {
if (st->unk_16 == 0) st->unk_1E[0] = 0;
else st->unk_1E[1] = 0;
}
}
if (BA_pending()) return 2;
if (BA_available(0) && lbl_1_bss_716C8[0].unk_98 != lbl_1_bss_7A388[0]) {
lbl_1_bss_7A388[0] = lbl_1_bss_716C8[0].unk_98;
BA_clear(0);
st->unk_5 &= ~1;
st->unk_40[0] = 0;
st->unk_1E[0] = 0;
st->unk_20[0] = 0;
st->unk_22 = 3;
st->unk_3E &= ~1;
return 2;
}
if (BA_available(1) && lbl_1_bss_716C8[1].unk_98 != lbl_1_bss_7A388[1]) {
lbl_1_bss_7A388[1] = lbl_1_bss_716C8[1].unk_98;
BA_clear(1);
st->unk_5 &= ~2;
st->unk_40[1] = 0;
st->unk_1E[1] = 0;
st->unk_20[1] = 0;
st->unk_22 = 3;
st->unk_3E &= ~1;
return 2;
}
if (BA_available(st->unk_16) &&
lbl_1_bss_716C8[st->unk_16].unk_3C == -1 &&
lbl_1_bss_716C8[st->unk_16].unk_40 == -1) fn_1_B8338(st->unk_16);
if (st->unk_3E & 1) {
if (BA_busy() && (st->unk_3E & 1)) {
if (st->unk_16 == 0) st->unk_1E[0] = 1;
else st->unk_1E[1] = 1;
}
st->unk_40[st->unk_16] = lbl_1_bss_718B4;
if (lbl_1_bss_718B4 == -123) {
BA_clear(st->unk_16);
st->unk_5 &= ~(1 << st->unk_16);
if (st->unk_16 == 0) st->unk_1E[0] = 0;
if (st->unk_16 == 1) st->unk_1E[1] = 0;
st->unk_3E &= ~1;
return 2;
}
}
if (!BA_busy() && (st->unk_3E & 1) &&
(st->unk_5 & (1 << st->unk_16))) {
BA_clear(st->unk_16);
st->unk_5 &= ~(1 << st->unk_16);
st->unk_3E &= ~1;
if (lbl_1_bss_718B4 == -121) {
if (st->unk_16 == 0) { st->unk_20[0] = 0; st->unk_1E[0] = 0; }
else { st->unk_20[1] = 0; st->unk_1E[1] = 0; }
}
return 2;
}
if ((s8)st->unk_22 != 1 && (s8)st->unk_22 != 2) {
st->unk_20[0] = st->unk_1E[0];
if (BA_available(0)) st->unk_1E[0] = 1;
else st->unk_1E[0] = 0;
if (st->unk_20[0] != 0 || st->unk_1E[0] != 0) {
if (st->unk_20[0] == 0 && st->unk_1E[0] == 1) {
BA_clear(0);
BA_mount_into(&serial, 0) ;
BA_request_flags(0, &st->unk_0) ;
st->unk_5 |= 1;
st->unk_16 = 0;
st->unk_3C = 255;
st->unk_3D = 0;
st->unk_22 = 1;
st->unk_3E |= 1;
return 2;
} else if (st->unk_20[0] == 1 && st->unk_1E[0] == 0) {
BA_clear(0);
st->unk_5 &= ~1;
st->unk_40[0] = 0;
st->unk_20[0] = 0;
if (st->unk_16 == 0) st->unk_22 = 4;
return 2;
} else if (st->unk_20[0] == 1 && st->unk_1E[0] == 1) st->unk_3E &= ~1;
}
} else if (st->unk_1E[0] == 1 && BA_status(0) == -3) {
BA_clear(0);
st->unk_5 &= ~1;
st->unk_40[0] = 0;
st->unk_1E[0] = 0;
st->unk_20[0] = 0;
st->unk_22 = 3;
st->unk_3E &= ~1;
return 2;
}
if ((s8)st->unk_22 != 1 && (s8)st->unk_22 != 2) {
st->unk_20[1] = st->unk_1E[1];
if (BA_available(1)) st->unk_1E[1] = 1;
else st->unk_1E[1] = 0;
if (st->unk_20[1] != 0 || st->unk_1E[1] != 0) {
if (st->unk_20[1] == 0 && st->unk_1E[1] == 1) {
BA_clear(1);
BA_mount_into(&serial, 1) ;
BA_request_flags(1, &st->unk_0) ;
st->unk_5 |= 2;
st->unk_16 = 1;
st->unk_3C = 255;
st->unk_3D = 0;
st->unk_22 = 1;
st->unk_3E |= 1;
return 2;
} else if (st->unk_20[1] == 1 && st->unk_1E[1] == 0) {
BA_clear(1);
st->unk_5 &= ~2;
st->unk_40[1] = 0;
st->unk_20[1] = 0;
if (st->unk_16 == 1) st->unk_22 = 4;
return 2;
} else if (st->unk_20[1] == 1 && st->unk_1E[1] == 1) st->unk_3E &= ~1;
}
} else if (st->unk_1E[1] == 1 && BA_status(1) == -3) {
BA_clear(1);
st->unk_5 &= ~2;
st->unk_40[1] = 0;
st->unk_1E[1] = 0;
st->unk_20[1] = 0;
st->unk_22 = 3;
st->unk_3E &= ~1;
return 2;
}
switch ((s8)st->unk_22) {
case 1:
if (((s32)fn_1_B88C4()) && lbl_1_bss_960 != 12 && (lbl_1_bss_960 != 5 || !(st->unk_4 & 2))) {
lbl_1_bss_7A398 = 0;
st->unk_22 = 2;
} else st->unk_22 = 3;
break;
case 2:
if (lbl_1_bss_7A398 != 0) st->unk_22 = 3;
break;
case 3:
{
s32 j;
for (j = 0; j < 127; j++) {
if (lbl_1_bss_77380[0][j].type == 5) {
if (lbl_1_bss_960 == 2)
fn_80008BA8(gMeta[0][j], lbl_1_bss_77380[0][j].info, 8);
else {
fn_1_F4810((void *)lbl_1_bss_77380[0][j].info, (void *)&out14, (void *)&out1c, (void *)&out12, (void *)&out11, (void *)&out10, (void *)&out13, (void *)&out18, (void *)&out20);
gMeta[0][j][0] = *(u8 *)&out14;
gMeta[0][j][1] = out11;
gMeta[0][j][2] = out10;
gMeta[0][j][3] = *(u8 *)&out1c;
gMeta[0][j][4] = *(u8 *)&out18;
gMeta[0][j][5] = out20.a;
gMeta[0][j][6] = out20.b;
gMeta[0][j][7] = out20.c;
}
}
}
for (j = 0; j < 127; j++) {
if (lbl_1_bss_77380[1][j].type == 5) {
if (lbl_1_bss_960 == 2)
fn_80008BA8(gMeta[1][j], lbl_1_bss_77380[1][j].info, 8);
else {
fn_1_F4810((void *)lbl_1_bss_77380[1][j].info, (void *)&out14, (void *)&out1c, (void *)&out12, (void *)&out11, (void *)&out10, (void *)&out13, (void *)&out18, (void *)&out20);
gMeta[1][j][0] = *(u8 *)&out14;
gMeta[1][j][1] = out11;
gMeta[1][j][2] = out10;
gMeta[1][j][3] = *(u8 *)&out1c;
gMeta[1][j][4] = *(u8 *)&out18;
gMeta[1][j][5] = out20.a;
gMeta[1][j][6] = out20.b;
gMeta[1][j][7] = out20.c;
}
}
}
}
st->unk_22 = 4;
break;
case 4:
st->unk_30[0] = 0;
st->unk_30[1] = 0;
for (i = 0; i < 127; i++) {
if (lbl_1_bss_77380[0][i].size) st->unk_30[0]++;
if (lbl_1_bss_77380[1][i].size) st->unk_30[1]++;
}
st->unk_30[0]++;
st->unk_30[1]++;
if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) { st->unk_18--; fn_1_A2DC4(0xA9011300); }
if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) { st->unk_18++; fn_1_A2DC4(0xA9011300); }
if ((lbl_1_bss_9F8.unk_10 & 1) || (lbl_1_bss_9F8.unk_12 & 1)) { st->unk_16 = 0; fn_1_A2DC4(0xA9011300); }
if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) { st->unk_16 = 1; fn_1_A2DC4(0xA9011300); }
n = st->unk_30[st->unk_16];
st->unk_18 = (st->unk_18 + n) % n;
count = lbl_1_bss_9F8.unk_8;
if (PAD_BIT(count, 9)) { fn_1_A2DC4(0xA9011000); return 1; }
if (BA_enabled_state(st->unk_16, st->unk_5) && PAD_BIT(count, 8)) {
if (st->unk_30[st->unk_16] - 1 != st->unk_18 || (st->unk_4 & 1)) {
fn_1_A2DC4(0xA9011100);
st->unk_22 = 6;
}
}
break;
case 6: {
u32 count;
count = 0;
for (i = 0; i < 4; i++) if ((s8)st->unk_4 & (1 << i)) count++;
if (count == 1) {
st->unk_1A = st->unk_16;
st->unk_1C = st->unk_18;
st->unk_14 = st->unk_4;
if (st->unk_4 & 0x10) st->unk_22 = 5;
else return 0;
break;
}
if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) { st->unk_34--; fn_1_A2DC4(0xA9011300); }
if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) { st->unk_34++; fn_1_A2DC4(0xA9011300); }
if (st->unk_34 < 0) st->unk_34 = 0;
if (st->unk_34 > count - 1) st->unk_34 = count - 1;
rank = 0;
for (i = 0; i < 4; i++) {
if ((s8)st->unk_4 & (1 << i)) {
if (rank == st->unk_34) st->unk_14 = 1 << i;
rank++;
}
}
if (lbl_1_bss_960 == 2 && (st->unk_0 & 0x20) && st->unk_14 == 1 &&
st->unk_30[st->unk_16] - 1 != st->unk_18) st->unk_14 = 8;
if (st->unk_30[st->unk_16] - 1 == st->unk_18) st->unk_14 = 1;
if (lbl_1_bss_77380[st->unk_16][st->unk_18].used != 0 &&
st->unk_18 < st->unk_30[st->unk_16] - 1) st->unk_14 = 8;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
fn_1_A2DC4(0xA9011100);
st->unk_1A = st->unk_16;
st->unk_1C = st->unk_18;
if (st->unk_14 == 4) st->unk_22 = 5;
else if (st->unk_14 == 8) {
st->unk_22 = 7;
lbl_1_bss_7AB8C = 1;
} else return 0;
} else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
fn_1_A2DC4(0xA9011000);
st->unk_22 = 4;
}
break;
}
case 7:
if ((lbl_1_bss_9F8.unk_10 & 1) || (lbl_1_bss_9F8.unk_12 & 1)) { lbl_1_bss_7AB8C = 0; fn_1_A2DC4(0xA9011300); }
if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) { lbl_1_bss_7AB8C = 1; fn_1_A2DC4(0xA9011300); }
if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) *(u8 *)(&lbl_1_bss_7AB8C) = 1;
if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) || ((lbl_1_bss_9F8.unk_8 >> 9) & 1)) {
if (lbl_1_bss_7AB8C == 0) { fn_1_A2DC4(0xA9011100); return 0; }
fn_1_A2DC4(0xA9011000);
st->unk_22 = 6;
}
break;
case 5:
if ((lbl_1_bss_9F8.unk_10 & 1) || (lbl_1_bss_9F8.unk_12 & 1)) { st->unk_16 = 0; fn_1_A2DC4(0xA9011300); }
if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) { st->unk_16 = 1; fn_1_A2DC4(0xA9011300); }
st->unk_18 = st->unk_30[st->unk_16] - 1;
if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
if (st->unk_16 != st->unk_1A || st->unk_18 != st->unk_1C) { fn_1_A2DC4(0xA9011100); return 0; }
} else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
fn_1_A2DC4(0xA9011000);
st->unk_16 = st->unk_1A;
st->unk_18 = st->unk_1C;
st->unk_1A = -1;
st->unk_1C = -1;
st->unk_22 = 4;
}
break;
case 8:
if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) st->unk_34--;
if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) st->unk_34++;
if (st->unk_34 < 0) st->unk_34 = 0;
if (st->unk_34 > 1) st->unk_34 = 1;
break;
}
return 2;
}

#undef lbl_1_bss_960
#undef lbl_1_bss_9F8
#undef lbl_801A6410
#undef gMeta
/* fzgx:end fn_1_BA144 */

/* fzgx:begin fn_1_BB974 */
/* VIEWS */
#define lbl_1_bss_7A39C (*(McFileKey (*)[2][127])&lbl_1_bss_7A39C)
/* one save file in a card's directory listing */

// Sorts both cards' directory listings: type 2 files first, then type 4, then the rest;

// the type 2, 4 and 5 groups are each ordered by time.

void fn_1_BB974(void *unused) {
    s32 i;
    s32 j;
    s32 count;
    s32 start;
    s32 n;
    s32 card;
    McFile *files;
    McFileKey *keys;
    McFile file1;
    McFile file5;
    McFile file4;
    McFile file3;
    McFile file2;
    McFileKey key1;
    McFileKey key5;
    McFileKey key4;
    McFileKey key3;
    McFileKey key2;

    for (card = 0; card < 2; card++) {
        files = lbl_1_bss_77380[card];
        keys = lbl_1_bss_7A39C[card];

        count = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].size != 0) {
                count++;
            }
        }

        /* type 2 files to the front */
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (files[i].type != 2 && files[j].type == 2) {
                    file1 = files[i];
                    files[i] = files[j];
                    files[j] = file1;
                    key1 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key1;
                }
            }
        }

        /* type 4 files right after them */
        start = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 2) {
                start++;
            }
        }
        for (i = start; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (files[i].type != 4 && files[j].type == 4) {
                    file2 = files[i];
                    files[i] = files[j];
                    files[j] = file2;
                    key2 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key2;
                }
            }
        }

        /* each group by time */
        start = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 2) {
                start++;
            }
        }
        for (i = 0; i < start - 1; i++) {
            for (j = i + 1; j < start; j++) {
                if (files[i].time > files[j].time) {
                    file3 = files[i];
                    files[i] = files[j];
                    files[j] = file3;
                    key3 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key3;
                }
            }
        }

        n = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 4) {
                n++;
            }
        }
        for (i = start; i < start + n - 1; i++) {
            for (j = i + 1; j < start + n; j++) {
                if (files[i].time > files[j].time) {
                    file4 = files[i];
                    files[i] = files[j];
                    files[j] = file4;
                    key4 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key4;
                }
            }
        }
        start += n;

        n = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 5) {
                n++;
            }
        }
        for (i = start; i < start + n - 1; i++) {
            for (j = i + 1; j < start + n; j++) {
                if (files[i].time > files[j].time) {
                    file5 = files[i];
                    files[i] = files[j];
                    files[j] = file5;
                    key5 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key5;
                }
            }
        }
    }
}
#undef lbl_1_bss_7A39C
/* fzgx:end fn_1_BB974 */

/* fzgx:begin fn_1_BC29C */
/* VIEWS */
#define lbl_1_bss_71810 (*(McTask *)&lbl_1_bss_71810)
#define lbl_1_bss_7A380 (*(u32 (*)[2])&lbl_1_bss_7A380)
#define lbl_1_bss_7A39C (*(McFileKey (*)[2][127])&lbl_1_bss_7A39C)
/* VIEWS */
#define lbl_1_rodata_26F8 (*(const FontDrawPacket *)&lbl_1_rodata_26F8)
// Completes the pending memory-card operation and resets the card state when needed.

void fn_1_BC29C(void) {
    if (lbl_1_bss_7A380[0] != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_7A380[0], "memcard.c", 0x2ad4);
        lbl_1_bss_7A380[0] = 0;
    }
    if (*(s16 *)&lbl_1_bss_960 != 2) {
        fn_1_1596DC(2);
        fn_1_484CC(2);
    }
}
/* fzgx:end fn_1_BC29C */

/* fzgx:begin fn_1_BC310 */
/* a message table row: one string per language */

/* FILE-SCOPE */ typedef const char *MsgRow[6];

#define MSG(row) (lbl_1_data_3B74C[row][lbl_801A66B4])

/* |sin| of the frame timer, scaled to a 16-bit angle */

#define WAVE(shift) __fabs(lbl_8006D188(lbl_1_bss_718BC << (shift)))

/* top of list row i: rows are 19 units apart */

#define ROW_Y(i) ((i) * 19 + 120)

/* the question above the Yes / No prompt */

static void draw_question(const char *question) {
    fn_1_4AEC0(1);
    fn_1_4AEB4(1.5f);
    fn_1_49410();
    if (lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
    }
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.02f);
    fn_1_495C8(9);
    fn_1_496FC(320.0f, 220.0f);
    fn_1_4966C(-1.0f, 8.0f);
    fn_1_4A0D8(question);
    fn_1_4AEC0(0);
    fn_1_4AEB4(0.0f);
}

/* the Yes / No prompt drawn over the file list; the highlighted answer pulses */

static void draw_confirm(f32 z) {
    Color pulse = fn_800081C8((Color){0xA0, 0x50, 0x50, 0x00}, (Color){0xA0, 0xA0, 0xA0, 0x00}, 1.0f);

    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(z);
    fn_1_495C8(9);
    fn_1_496FC(288.0f, 270.0f);
    fn_1_495C8(10);
    if (lbl_1_bss_7AB8C == 0) {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", MSG(39));
        fn_1_4D4C8(pulse, z + 0.00005f, 10.0f);
    } else {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", MSG(39));
    }
    fn_1_496FC(352.0f, 270.0f);
    fn_1_495C8(8);
    if (lbl_1_bss_7AB8C == 0) {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", MSG(40));
    } else {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", MSG(40));
        fn_1_4D4C8(pulse, z + 0.00005f, 10.0f);
    }
    draw_question(MSG(102));
}

/* bubble-sort both cards' listings (and their keys) by save time, oldest first */

static inline void sort_listings(void) {
    McFile *files;
    McFileKey *keys;
    s32 card;
    McFile swap;
    McFileKey swap_key;
    s32 i;
    s32 j;
    s32 count;

    for (card = 0; card < 2; card++) {
        files = lbl_1_bss_77380[card];
        keys = lbl_1_bss_7A39C[card];

        count = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].size != 0) {
                count++;
            }
        }
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (files[i].time > files[j].time) {
                    swap = files[i];
                    files[i] = files[j];
                    files[j] = swap;
                    swap_key = keys[i];
                    keys[i] = keys[j];
                    keys[j] = swap_key;
                }
            }
        }
    }
}

/* pulse a colour's red and green with the frame timer */

static inline Color pulse_red_green(Color c) {
    c.r = 255.0 * WAVE(9);
    c.g = 255.0 * WAVE(9);
    return c;
}

void fn_1_BC310(McMenu *menu) {
    char text[0x104];
    FontDrawPacket packet;
    OSCalendarTime date;
    Color tab_on = {0x32, 0x00, 0x00, 0x00};
    Color tab_off = {0x00, 0x32, 0x00, 0x00};
    Color frame = {0x00, 0x00, 0x00, 0x00};
    Color lit;
    McFile *file;
    s32 index;
    u8 busy;
    s8 state;
    McFile *list;
    Color *tab;
    s32 i;
    s32 first;
    s32 y;
    u32 shown;
    s32 ok;
    McGhostA *ghost_a;
    McGhostB *ghost_b;
    McFileKey *key;
    s16 *top;

    busy = 0;
    if (lbl_1_bss_716C8[0].unk_2 != 0xFF) {
        busy |= 1;
    }
    if (lbl_1_bss_716C8[1].unk_2 != 0xFF) {
        busy |= 2;
    }
    if (lbl_1_bss_71810.busy != 0xFF) {
        busy |= 4;
    }
    if (busy) {
        return;
    }

    state = menu->state;
    if (state == 2) {
        lbl_1_bss_7A398 = fn_1_B8EDC(menu->card);
        return;
    }
    if (menu->hidden & 1) {
        return;
    }
    if (state == 3) {
        return;
    }
    if (state == 7) {
        {
            Color white = {0xFF, 0xFF, 0xFF, 0xFF};
            fn_1_53BD8(&white, 320.0f, 240.0f, 300.0f, 200.0f, 0.021f);
        }
        draw_confirm(0.0204999987f);
    }

    /* re-sort both cards' listings by time when the sort mode changes */
    if (menu->sort != menu->sort_request) {
        menu->sort = menu->sort_request;
        switch (menu->sort) {
        default:
            fn_1_BB974(menu);
            break;
        case 1:
            sort_listings();
            break;
        }
    }

    list = lbl_1_bss_77380[menu->card];
    if (menu->card == 0) {
        top = &menu->top[0];
    } else {
        top = &menu->top[1];
    }

    /* header: the two slot tabs */
    fn_1_49410();
    fn_1_495FC();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_495C8(0);
    fn_1_4966C(-2.0f, 0.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        fn_1_495C8(1);
        fn_1_4966C(-1.0f, 0.0f);
    }
    if (lbl_801A66B4 != 5) {
        fn_1_496FC(95.0f, 80.0f);
    } else {
        fn_1_496FC(54.0f, 80.0f);
    }
    if (menu->card == 0) {
        Color yellow = {0xFF, 0xFF, 0xA0, 0x00};
        fn_1_49514(yellow);
    } else {
        Color grey = {0x80, 0x80, 0x80, 0x00};
        fn_1_49514(grey);
    }
    fn_1_4CF3C(MSG(37), 73.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_496FC(203.0f, 80.0f);
    } else {
        fn_1_496FC(164.0f, 80.0f);
    }
    if (menu->card == 1) {
        Color yellow = {0xFF, 0xFF, 0xA0, 0x00};
        fn_1_49514(yellow);
    } else {
        Color grey = {0x80, 0x80, 0x80, 0x00};
        fn_1_49514(grey);
    }
    fn_1_4CF3C(MSG(38), 73.0f);
    fn_1_495C8(0);
    fn_1_4955C(0.7f, 0.7f);

    /* free space on the selected card */
    if (lbl_1_bss_716C8[menu->card].unk_1 == 0) {
        s32 blocks;

        if (menu->options & 1) {
            if (menu->flags & 4) {
                blocks = 3;
            } else if (menu->flags & 0x10) {
                blocks = 3;
            } else if (menu->flags & 0x20) {
                fn_1_154E34(&blocks);
                blocks = (blocks + 0x405F) & ~0x1FFF;
                blocks = blocks / 0x2000;
                if (blocks < 3) {
                    blocks = 3;
                }
            }
            fn_1_496FC(280.0f, 80.0f);
            {
                Color white = {0xFF, 0xFF, 0xFF, 0x00};
                fn_1_49514(white);
            }
            if (lbl_1_bss_716C8[menu->card].unk_3C >= 0) {
                fn_1_4CF3C(MSG(110), 300.0f, blocks, lbl_1_bss_716C8[menu->card].unk_3C);
            }
        } else {
            fn_1_496FC(300.0f, 80.0f);
            {
                Color white = {0xFF, 0xFF, 0xFF, 0x00};
                fn_1_49514(white);
            }
            if (lbl_1_bss_716C8[menu->card].unk_3C >= 0) {
                fn_1_4CF3C(MSG(109), 300.0f, lbl_1_bss_716C8[menu->card].unk_3C);
            }
        }
    }

    fn_1_BE978(0x25, 0x46, 0x70, 0x23, (void *)&tab_on);
    fn_1_BE978(0x93, 0x46, 0x70, 0x23, (void *)&tab_off);
    tab = menu->card == 0 ? &tab_on : &tab_off;
    fn_1_BED04(0x25, 0x69, 0xDC, 0xD9, (void *)tab, menu->card);
    fn_1_BF198(0x101, 0x69, 0x174, 0xD9, (void *)tab);

    /* a card error: show its message and nothing else */
    if (menu->result[menu->card] != 0) {
        ok = 0;
        if (lbl_1_bss_716C8[menu->card].unk_1 != -1 && lbl_1_bss_716C8[menu->card].unk_1 != -3) {
            ok = 1;
        }
        if (ok) {
            fn_1_49410();
            if (lbl_801A66B4 != 5) {
                fn_1_49590(0.5f);
                fn_1_495B0(0x80000000);
            }
            fn_1_495FC();
            {
                Color yellow = {0xFF, 0xFF, 0xA0, 0x00};
                fn_1_49514(yellow);
            }
            fn_1_4955C(0.75f, 0.75f);
            fn_1_496FC(333.0f, 215.0f);
            fn_1_495C8(9);
            fn_1_4966C(0.0f, 8.0f);
            fn_1_4AEC0(1);
            fn_1_4AEB4(1.5f);
            if (menu->result[menu->card] == -2) {
                if (menu->card == 0) {
                    fn_1_B5258((void *)text, (void *)(MSG(75)), (void *)("SLOT"), (void *)(MSG(37)));
                } else if (menu->card == 1) {
                    fn_1_B5258((void *)text, (void *)(MSG(75)), (void *)("SLOT"), (void *)(MSG(38)));
                }
                fn_1_4AE0C(text);
            } else if (menu->result[menu->card] == -13 || menu->result[menu->card] == -126) {
                if (menu->card == 0) {
                    fn_1_B5258((void *)text, (void *)(MSG(34)), (void *)("SLOT"), (void *)(MSG(37)));
                } else if (menu->card == 1) {
                    fn_1_B5258((void *)text, (void *)(MSG(34)), (void *)("SLOT"), (void *)(MSG(38)));
                }
                fn_1_4AE0C(text);
            } else if (menu->result[menu->card] == -6) {
                if (menu->card == 0) {
                    fn_1_B5258((void *)text, (void *)(MSG(54)), (void *)("SLOT"), (void *)(MSG(37)));
                } else if (menu->card == 1) {
                    fn_1_B5258((void *)text, (void *)(MSG(54)), (void *)("SLOT"), (void *)(MSG(38)));
                }
                fn_1_4AE0C(text);
            } else {
                if (menu->card == 0) {
                    fn_1_B5258((void *)text, (void *)(MSG(31)), (void *)("SLOT"), (void *)(MSG(37)));
                } else if (menu->card == 1) {
                    fn_1_B5258((void *)text, (void *)(MSG(31)), (void *)("SLOT"), (void *)(MSG(38)));
                }
                fn_1_4AE0C(text);
            }
            fn_1_4AEC0(0);
            fn_1_4AEB4(0.0f);
            return;
        }
    }

    /* no card in the slot */
    if (menu->card == 0) {
        if (menu->unk_20[0] == 0 && menu->unk_1E[0] == 0) {
            fn_1_49410();
            if (lbl_801A66B4 != 5) {
                fn_1_49590(0.5f);
                fn_1_495B0(0x80000000);
            }
            fn_1_495FC();
            {
                Color yellow = {0xFF, 0xFF, 0xA0, 0x00};
                fn_1_49514(yellow);
            }
            fn_1_4955C(0.75f, 0.75f);
            fn_1_496FC(333.0f, 215.0f);
            fn_1_495C8(9);
            fn_1_4966C(0.0f, 8.0f);
            fn_1_4AEC0(1);
            fn_1_4AEB4(1.5f);
            fn_1_B5258((void *)text, (void *)(MSG(89)), (void *)("SLOT"), (void *)(MSG(37)));
            fn_1_4AE0C(text);
            fn_1_4AEC0(0);
            fn_1_4AEB4(0.0f);
            return;
        }
    } else if (menu->card == 1) {
        if (menu->unk_20[1] == 0 && menu->unk_1E[1] == 0) {
            fn_1_49410();
            if (lbl_801A66B4 != 5) {
                fn_1_49590(0.5f);
                fn_1_495B0(0x80000000);
            }
            fn_1_495FC();
            {
                Color yellow = {0xFF, 0xFF, 0xA0, 0x00};
                fn_1_49514(yellow);
            }
            fn_1_4955C(0.75f, 0.75f);
            fn_1_496FC(333.0f, 215.0f);
            fn_1_495C8(9);
            fn_1_4966C(0.0f, 8.0f);
            fn_1_4AEC0(1);
            fn_1_4AEB4(1.5f);
            fn_1_B5258((void *)text, (void *)(MSG(89)), (void *)("SLOT"), (void *)(MSG(38)));
            fn_1_4AE0C(text);
            fn_1_4AEC0(0);
            fn_1_4AEB4(0.0f);
            return;
        }
    }

    /* keep the cursor inside the ten visible rows */
    if (*top > menu->cursor) {
        *top = menu->cursor;
    } else if (*top + 10 <= menu->cursor) {
        *top = menu->cursor - 9;
    }
    first = *top;
    fn_1_49614();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(1.0f);

    for (i = 0; i < 10; i++) {
        file = &list[first] + i;
        index = i + first;
        if (index >= menu->count[menu->card]) {
            continue;
        }
        if (file->used != 0 && index < menu->count[menu->card] - 1) {
            if (menu->cursor == index) {
                if (menu->state != 6) {
                    lit.r = 112.0 + (f64)(64.0 * WAVE(9));
                    lit.g = 112.0 + (f64)(64.0 * WAVE(9));
                    lit.b = 112.0 + (f64)(64.0 * WAVE(9));
                    lit.a = 0;
                } else {
                    Color grey = {0x70, 0x70, 0x70, 0x00};
                    lit = grey;
                }
                fn_1_BF600(0x3C, ROW_Y(i) - 3, 0x222, 0x18, (void *)&lit, 0.09f);
            }
            {
                Color pink = {0xA0, 0x80, 0x80, 0x00};
                fn_1_49514(pink);
            }
            fn_1_496FC(86.0f, ROW_Y(i));
            fn_1_4CF3C(MSG(111), 100.0f);
            {
                Color white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_49514(white);
            }
            if (file->type != 0) {
                fn_1_495C8(9);
                fn_1_496FC(73.0f, ROW_Y(i) + 8.399999999999999);
                fn_1_4955C(0.99f, 0.9f);
                fn_1_4AE0C("\x81\xA0");
                fn_1_496FC(73.0f, ROW_Y(i) + 8.399999999999999);
                fn_1_4955C(0.54f, 0.54f);
                fn_1_4966C(-4.0f, 0.0f);
                fn_1_4CF3C("%d", 16.0f, (file->size + 0x1FFF) >> 13);
                fn_1_4966C(-2.0f, 0.0f);
                fn_1_495C8(0);
                fn_1_4955C(0.7f, 0.7f);
                if (lbl_801A66B4 != 5) {
                    fn_1_4966C(-1.0f, 0.0f);
                }
            }
            continue;
        }

        if (menu->state != 6) {
            lit.r = 112.0 + (f64)(64.0 * WAVE(9));
            lit.g = 112.0 + (f64)(64.0 * WAVE(9));
            lit.b = 112.0 + (f64)(64.0 * WAVE(9));
            lit.a = 0;
        } else {
            Color grey = {0x70, 0x70, 0x70, 0x00};
            lit = grey;
        }
        if (menu->state == 5) {
            if (i + first == menu->count[menu->card] - 1) {
                fn_1_BF600(0x40, ROW_Y(i) - 3, 0x222, 0x18, (void *)&lit, 0.09f);
                {
                    Color yellow = {0xFF, 0xFF, 0x40, 0x00};
                    fn_1_49514(yellow);
                }
            } else if (menu->mark_index == index && menu->card == menu->mark_card) {
                Color cyan = {0x00, 0xFF, 0xFF, 0x00};
                fn_1_49514(cyan);
            } else {
                Color grey = {0x80, 0x80, 0x80, 0x00};
                fn_1_49514(grey);
            }
        } else if (menu->cursor == index) {
            fn_1_BF600(0x3C, ROW_Y(i) - 3, 0x222, 0x18, (void *)&lit, 0.09f);
            {
                Color yellow = {0xFF, 0xFF, 0x40, 0x00};
                fn_1_49514(yellow);
            }
        } else {
            Color white = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(white);
        }

        OSTicksToCalendarTime(OS_TIMER_CLOCK * (OSTime)file->time, &date);
        fn_1_496FC(86.0f, ROW_Y(i));
        if (file->type == 2) {
            fn_1_4955C(0.7f, 0.7f);
            {
                Color tint = {0xFF, 0xFF, 0xA0, 0xFF};
                fn_1_49514(tint);
            }
            fn_1_4CF3C(MSG(83), 55.0f);
            if ((*(s16 *)&lbl_1_bss_960) == 2) {
                ghost_a = file->info;
                ghost_b = NULL;
            } else {
                ghost_a = NULL;
                ghost_b = file->info;
            }
            if (ghost_a != NULL) {
                fn_1_BF700(ghost_a->unk_0, 0, 1, 0xBE, ROW_Y(i) - 1, 0.3f, 0.3f, 0.08f);
                fn_1_BFBF4(ghost_a->unk_1, 0x152, ROW_Y(i) + 3, 0.8f, 0.08f);
                fn_1_C023C(0xD5, ROW_Y(i) + 9, 0.55f, ghost_a->unk_0, ghost_a->unk_6, ghost_a->unk_7, ghost_a->unk_8, ghost_a->unk_9, 0.0600000024f);
            }
            if (ghost_b != NULL) {
                fn_1_BF700(ghost_b->unk_0, 0, 1, 0xBE, ROW_Y(i) - 1, 0.3f, 0.3f, 0.08f);
                fn_1_BFBF4(ghost_b->unk_1, 0x152, ROW_Y(i) + 3, 0.8f, 0.08f);
                fn_1_C023C(0xD5, ROW_Y(i) + 9, 0.55f, ghost_b->unk_0, ghost_b->unk_4, ghost_b->unk_5, ghost_b->unk_6, ghost_b->unk_7, 0.0600000024f);
            }
        } else if (file->type == 4) {
            {
                Color tint = {0xA0, 0xA0, 0xFF, 0xFF};
                fn_1_49514(tint);
            }
            fn_1_4955C(0.7f, 0.7f);
            fn_1_4CF3C(MSG(82), 55.0f);
            if (file->info != NULL) {
                packet = lbl_1_rodata_26F8;
                packet.x = 190.0f;
                packet.y = ROW_Y(i) - 1;
                packet.z = 0.08f;
                packet.scale_x = 0.3f;
                packet.scale_y = 0.3f;
                fn_1_4FC50(&packet, 5, 0x40, 0x40, file->info);
            }
        } else if (file->type == 5) {
            fn_1_4955C(0.7f, 0.7f);
            {
                Color tint = {0xFF, 0xA0, 0xA0, 0xFF};
                fn_1_49514(tint);
            }
            fn_1_4CF3C(MSG(81), 55.0f);
            key = &lbl_1_bss_7A39C[menu->card][index];
            fn_1_C00EC(key->unk_1, key->unk_2, 0xBE, ROW_Y(i) + 2, 0.55f);
            fn_1_BFBF4(key->unk_0, 0x152, ROW_Y(i) + 3, 0.8f, 0.08f);
        } else {
            fn_1_4955C(0.7f, 0.7f);
            fn_1_496FC(64.0f, ROW_Y(i));
            if (!(menu->options & 1)) {
                if ((menu->options & 4) && menu->state == 5) {
                    Color white = {0xFF, 0xFF, 0xFF, 0xFF};
                    fn_1_49514(white);
                } else {
                    Color grey = {0x80, 0x80, 0x80, 0xFF};
                    fn_1_49514(grey);
                }
            } else {
                Color white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_49514(white);
            }
            fn_1_4AE0C(MSG(106));
        }

        {
            Color white = {0xFF, 0xFF, 0xFF, 0xFF};
            fn_1_49514(white);
        }
        if (file->type != 0) {
            fn_1_495C8(9);
            fn_1_496FC(73.0f, ROW_Y(i) + 8.399999999999999);
            fn_1_4955C(0.99f, 0.9f);
            fn_1_4AE0C("\x81\xA0");
            fn_1_496FC(73.0f, ROW_Y(i) + 8.399999999999999);
            fn_1_4955C(0.54f, 0.54f);
            fn_1_4966C(-4.0f, 0.0f);
            fn_1_4CF3C("%d", 16.0f, (file->size + 0x1FFF) >> 13);
            fn_1_4966C(-2.0f, 0.0f);
            fn_1_495C8(0);
            fn_1_4955C(0.7f, 0.7f);
            if (lbl_801A66B4 != 5) {
                fn_1_4966C(-1.0f, 0.0f);
            }
        }
        {
            Color white = {0xFF, 0xFF, 0xFF, 0xFF};
            fn_1_49514(white);
        }
        fn_1_496FC(460.0f, ROW_Y(i) + 2);
        fn_1_4955C(1.0f, 0.65f);
        if (file->type != 0) {
            fn_1_4CF3C("%04d/%02d/%02d %02d:%02d", 130.0f, date.year, date.mon + 1, date.mday, date.hour,
                       date.min);
        }
    }

    /* scroll arrows */
    fn_1_49410();
    if (lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
    }
    fn_1_4955C(0.75f, 0.75f);
    fn_1_495C8(0);
    fn_1_49614();
    if (menu->count[menu->card] > 10) {
        if (*top != 0) {
            fn_1_496FC(60.0 - (f64)(6.0 * WAVE(9)), (110.0 - (f64)(10.0 * WAVE(10))));
            {
                Color black = {0x00, 0x00, 0x00, 0x00};

                fn_1_49514((pulse_red_green(black)));
            }
            fn_1_4955C(0.5 * WAVE(9), 0.5f);
            fn_1_4A0D8("\x81\xA3");
        }
        if (*top != menu->count[menu->card] - 10) {
            fn_1_496FC(60.0 + (f64)(6.0 * WAVE(9)), (320.0 + (f64)(10.0 * WAVE(10))));
            {
                Color black = {0x00, 0x00, 0x00, 0x00};

                fn_1_49514((pulse_red_green(black)));
            }
            fn_1_4955C(0.5 * WAVE(9), 0.5f);
            fn_1_4953C(-0x8000);
            fn_1_4A0D8("\x81\xA3");
        }
    }

    fn_1_49410();
    if (lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
    }
    fn_1_495FC();
    {
        Color yellow = {0xFF, 0xFF, 0xA0, 0x00};
        fn_1_49514(yellow);
    }
    fn_1_4955C(0.75f, 0.75f);
    fn_1_495C8(0);

    /* the options panel of the selected file */
    if (menu->state == 6) {
        shown = 0;
        for (i = 0; i < 4; i++) {
            if (menu->options & (1 << i)) {
                shown++;
            }
        }
        if (shown > 1) {
            s32 panel_y = (menu->cursor - *top) * 19 + 120;
            s32 lit_panel;

            fn_1_496FC(380.0f, panel_y);
            if ((*(s16 *)&lbl_1_bss_960) == 2 && ((menu->flags & 0x20) || (menu->flags & 4))) {
                lit_panel = 1;
            } else {
                lit_panel = 0;
            }
            y = panel_y;
            for (i = 0; i < 4; i++) {
                lit.r = 112.0 + (f64)(64.0 * WAVE(9));
                lit.g = 112.0 + (f64)(64.0 * WAVE(9));
                lit.b = 112.0 + (f64)(64.0 * WAVE(9));
                lit.a = 0;
                if (lit_panel) {
                    if (menu->count[menu->card] - 1 != menu->cursor) {
                        if (menu->option_lit & (1 << i)) {
                            fn_1_BF600(0x17A, y, 0x38, 0x12, (void *)&lit, 0.065f);
                            {
                                Color cyan = {0x00, 0xFF, 0xFF, 0x00};
                                fn_1_49514(cyan);
                            }
                        } else if (lbl_1_bss_77380[menu->card][menu->cursor].used != 0 &&
                                   menu->cursor < menu->count[menu->card] - 1) {
                            Color grey = {0x80, 0x80, 0x80, 0x00};
                            fn_1_49514(grey);
                        } else if ((*(s16 *)&lbl_1_bss_960) == 2 && (menu->flags & 0x20)) {
                            Color grey = {0x80, 0x80, 0x80, 0x00};
                            fn_1_49514(grey);
                        } else {
                            Color white = {0xFF, 0xFF, 0xFF, 0x00};
                            fn_1_49514(white);
                        }
                    } else if (menu->option_lit & (1 << i)) {
                        fn_1_BF600(0x17A, y, 0x38, 0x12, (void *)&lit, 0.065f);
                        {
                            Color cyan = {0x00, 0xFF, 0xFF, 0x00};
                            fn_1_49514(cyan);
                        }
                    } else {
                        Color grey = {0x80, 0x80, 0x80, 0x00};
                        fn_1_49514(grey);
                    }
                } else if (menu->option_lit & (1 << i)) {
                    fn_1_BF600(0x17A, y, 0x38, 0x12, (void *)&lit, 0.065f);
                    {
                        Color cyan = {0x00, 0xFF, 0xFF, 0x00};
                        fn_1_49514(cyan);
                    }
                } else {
                    Color white = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(white);
                }
                if (menu->options & (1 << i)) {
                    if ((1 << i) & 1) {
                        fn_1_4AE0C("%s\n", MSG(90));
                    } else if ((1 << i) & 2) {
                        fn_1_4AE0C("%s\n", MSG(91));
                    } else if ((1 << i) & 4) {
                        fn_1_4AE0C("%s\n", MSG(92));
                    } else if ((1 << i) & 8) {
                        fn_1_4CF3C("%s\n", 53.0f, MSG(93));
                    }
                    y += 18;
                }
            }
            fn_1_BF520(0x174, panel_y - 6, 0x44, shown * 18 + 12, (void *)&frame);
        }
    }

    /* scroll bar */
    fn_1_BFE20(0x268, 0x70, 0.07f, 16.0f, 204.0f, (f32)*top / menu->count[menu->card],
               10.0f / menu->count[menu->card]);

    /* details of the file under the cursor */
    if (lbl_1_bss_77380[menu->card][menu->cursor].used != 0 &&
        menu->cursor < menu->count[menu->card] - 1) {
        fn_1_BF520(0x26, 0x14A, 0x24E, 0x50, (void *)&frame);
        fn_1_49410();
        if (lbl_801A66B4 != 5) {
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
        }
        fn_1_495FC();
        {
            Color white = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(white);
        }
        fn_1_4955C(0.75f, 0.75f);
        fn_1_495C8(0);
        fn_1_496FC(64.0f, 340.0f);
        fn_1_4AE0C("%s\n", MSG(112));
    } else {
        fn_1_BF520(0x26, 0x14A, 0x24E, 0x50, (void *)&frame);
        fn_1_49410();
        if (lbl_801A66B4 != 5) {
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
        }
        fn_1_495FC();
        {
            Color white = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(white);
        }
        fn_1_4955C(0.75f, 0.75f);
        fn_1_495C8(0);
        fn_1_496FC(64.0f, 340.0f);
        if (lbl_1_bss_77380[menu->card][menu->cursor].type == 2) {
            if ((*(s16 *)&lbl_1_bss_960) == 2) {
                ghost_a = lbl_1_bss_77380[menu->card][menu->cursor].info;
                ghost_b = NULL;
            } else {
                ghost_a = NULL;
                ghost_b = lbl_1_bss_77380[menu->card][menu->cursor].info;
            }
            fn_1_4AE0C("%s\n", MSG(83));
            if (ghost_a != NULL) {
                fn_1_BF700(ghost_a->unk_0, 0, 1, 0x166, 0x14A, 1.2f, 1.2f, 0.0600000024f);
                fn_1_BF9C4(ghost_a->unk_1, 0xFD, 0x15E, 0.75f, 0.0600000024f);
                fn_1_BFCF8((void *)ghost_a->unk_2, (void *)ghost_a->unk_3, (void *)ghost_a->unk_4, 0x214, 0x176, 1.0f, 0.0600000024f);
                if ((*(s16 *)&lbl_1_bss_960) == 2) {
                    fn_1_C0374(0x214, 0x160, 0.6f, ghost_a->unk_0, ghost_a->unk_6, ghost_a->unk_7, ghost_a->unk_8, ghost_a->unk_9, 0.0600000024f);
                } else if (ghost_a->unk_0 >= 0x29 && ghost_a->unk_6 != 0) {
                    fn_1_1358BC(0x214, 0x160, 10, ghost_a->unk_0, lbl_801A66B4, ghost_a->unk_7, ghost_a->unk_8,
                                ghost_a->unk_9, 0.65f, 0.65f, 0.0600000024f);
                } else {
                    fn_1_135D7C(0x214, 0x160, 10, ghost_a->unk_0, lbl_801A66B4, 0, 0, 0.65f, 0.65f, 0.0600000024f);
                }
            }
            if (ghost_b != NULL) {
                fn_1_BF700(ghost_b->unk_0, 0, 1, 0x166, 0x14A, 1.2f, 1.2f, 0.0600000024f);
                fn_1_BF9C4(ghost_b->unk_1, 0xFD, 0x15E, 0.75f, 0.0600000024f);
                fn_1_BFCF8((void *)ghost_b->unk_24, (void *)ghost_b->unk_25, (void *)ghost_b->unk_26, 0x214, 0x176, 1.0f, 0.0600000024f);
                if ((*(s16 *)&lbl_1_bss_960) == 2) {
                    fn_1_C0374(0x214, 0x160, 0.6f, ghost_b->unk_0, ghost_b->unk_4, ghost_b->unk_5, ghost_b->unk_6, ghost_b->unk_7, 0.0600000024f);
                } else if (ghost_b->unk_0 >= 0x29 && ghost_b->unk_4 != 0) {
                    fn_1_1358BC(0x214, 0x160, 10, ghost_b->unk_0, lbl_801A66B4, ghost_b->unk_5, ghost_b->unk_6,
                                ghost_b->unk_7, 0.65f, 0.65f, 0.0600000024f);
                } else {
                    fn_1_135D7C(0x214, 0x160, 10, ghost_b->unk_0, lbl_801A66B4, 0, 0, 0.65f, 0.65f, 0.0600000024f);
                }
            }
        } else if (lbl_1_bss_77380[menu->card][menu->cursor].type == 4) {
            if (lbl_1_bss_77380[menu->card][menu->cursor].info != NULL) {
                packet = lbl_1_rodata_26F8;
                packet.x = 308.0f;
                packet.y = 337.0f;
                packet.z = 0.0600000024f;
                packet.scale_x = 1.0714285f;
                packet.scale_y = 1.0714285f;
                fn_1_4FC50(&packet, 5, 0x40, 0x40, lbl_1_bss_77380[menu->card][menu->cursor].info);
                fn_1_4AE0C(MSG(82));
            }
        } else if (lbl_1_bss_77380[menu->card][menu->cursor].type == 5) {
            fn_1_4AE0C(MSG(81));
            key = &lbl_1_bss_7A39C[menu->card][menu->cursor];
            fn_1_BF9C4(key->unk_0, 0xFD, 0x15E, 0.75f, 0.0600000024f);
            fn_1_BF700(key->unk_3, i, 1, 0x16A, 0x14A, 1.2f, 1.2f, 0.0600000024f);
            if ((*(s16 *)&lbl_1_bss_960) == 2) {
                fn_1_C0374(0x214, 0x172, 0.6f, key->unk_3, key->unk_4, key->unk_5, key->unk_6, key->unk_7, 0.0600000024f);
            } else if (key->unk_3 >= 0x29 && key->unk_4 != 0) {
                fn_1_1358BC(0x214, 0x172, 10, key->unk_3, lbl_801A66B4, key->unk_5, key->unk_6, key->unk_7,
                            0.65f, 0.65f, 0.0600000024f);
            } else {
                fn_1_135D7C(0x214, 0x172, 10, key->unk_3, lbl_801A66B4, 0, 0, 0.65f, 0.65f, 0.0600000024f);
            }
        } else if (!(menu->options & 1)) {
            if ((menu->options & 4) && menu->state == 5) {
                {
                    Color white = {0xFF, 0xFF, 0xFF, 0xFF};
                    fn_1_49514(white);
                }
                fn_1_4AE0C(MSG(107));
            } else {
                {
                    Color grey = {0x80, 0x80, 0x80, 0xFF};
                    fn_1_49514(grey);
                }
                fn_1_4AE0C(MSG(108));
            }
        } else {
            {
                Color white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_49514(white);
            }
            fn_1_4AE0C(MSG(107));
        }
    }
    lbl_1_bss_718BC++;
}

#undef lbl_1_rodata_26F8
#undef MSG
#undef WAVE
#undef ROW_Y
#undef lbl_1_bss_71810
#undef lbl_1_bss_7A380
#undef lbl_1_bss_7A39C
/* fzgx:end fn_1_BC310 */

/* fzgx:begin fn_1_BE978 */
/* VIEWS */
#define lbl_1_rodata_26F8 (*(FontDrawPacket *)&lbl_1_rodata_26F8)
/* Draws a 3x2 sliced frame: corner tiles of 8 pixels, stretched middle. */

void fn_1_BE978(s32 x, s32 y, s32 width, s32 height, u32 *color) {
    s32 w;
    s32 h;
    s32 right;
    f32 scaleW;
    f32 scaleH;
    FontDrawPacket pkt;

    w = width - 16;
    h = height - 8;
    if (w < 0) {
        w = 0;
    }
    if (h < 0) {
        h = 0;
    }
    pkt = lbl_1_rodata_26F8;
    pkt.image = 12;
    *(u32 *)pkt.color_add = *color;
    pkt.z = 0.11f;

    pkt.u0 = 0.0f;
    pkt.u1 = 0.33333334f;
    pkt.v0 = 0.0f;
    pkt.v1 = 0.33333334f;
    pkt.x = x;
    pkt.y = y;
    pkt.scale_x = 0.33333334f;
    pkt.scale_y = 0.33333334f;
    fn_1_4F734(&pkt);

    pkt.u0 = 0.33333334f;
    pkt.u1 = 0.6666667f;
    pkt.v0 = 0.0f;
    pkt.v1 = 0.33333334f;
    pkt.x = x + 8;
    pkt.y = y;
    pkt.scale_x = 0.33333334f;
    pkt.scale_y = 0.33333334f;
    scaleW = w / 8.0f;
    pkt.scale_x *= scaleW;
    fn_1_4F734(&pkt);

    pkt.u0 = 0.6666667f;
    pkt.u1 = 1.0f;
    pkt.v0 = 0.0f;
    pkt.v1 = 0.33333334f;
    right = (((x) + (8)) + w);
    pkt.x = right;
    pkt.y = y;
    pkt.scale_x = 0.33333334f;
    pkt.scale_y = 0.33333334f;
    fn_1_4F734(&pkt);

    pkt.u0 = 0.0f;
    pkt.u1 = 0.33333334f;
    pkt.v0 = 0.33333334f;
    pkt.v1 = 0.6666667f;
    pkt.x = x;
    pkt.y = y + 8;
    pkt.scale_x = 0.33333334f;
    pkt.scale_y = 0.33333334f;
    scaleH = h / 8.0f;
    pkt.scale_y *= scaleH;
    fn_1_4F734(&pkt);

    pkt.u0 = 0.33333334f;
    pkt.u1 = 0.6666667f;
    pkt.v0 = 0.33333334f;
    pkt.v1 = 0.6666667f;
    pkt.x = x + 8;
    pkt.y = y + 8;
    pkt.scale_x = 0.33333334f;
    pkt.scale_y = 0.33333334f;
    pkt.scale_x *= scaleW;
    pkt.scale_y *= scaleH;
    fn_1_4F734(&pkt);

    pkt.u0 = 0.6666667f;
    pkt.u1 = 1.0f;
    pkt.v0 = 0.33333334f;
    pkt.v1 = 0.6666667f;
    pkt.x = right;
    pkt.y = y + 8;
    pkt.scale_x = 0.33333334f;
    pkt.scale_y = 0.33333334f;
    pkt.scale_y *= scaleH;
    fn_1_4F734(&pkt);
}
#undef lbl_1_rodata_26F8
/* fzgx:end fn_1_BE978 */

/* fzgx:begin fn_1_BED04 */
/* begin game/main_rel/memcard_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_MEMCARD_TYPES_H

/* MWCC may commute a constant to the left of a product; routing the product
 * through a helper keeps retail's operand order. */


/* Draws a nine-slice style frame: top edge, left edge, bottom edge, then the
 * two halves of the right edge, then the interior fill. */

void fn_1_BED04(s32 x, s32 y, s32 width, s32 height, u32 *color, s32 flip) {
    f32 inner_w;
    f32 half_w;
    FontDrawPacket packet;
    s32 bottom;
    s32 inner_width;
    s32 inner_height;

    inner_width = width - 8;
    inner_height = height - 8;
    if (inner_width < 0) {
        inner_width = 0;
    }
    if (inner_height < 0) {
        inner_height = 0;
    }
    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0xC;
    *(u32 *)packet.color_add = *color;
    packet.z = 0.11f;
    packet.u0 = 0.0f;
    packet.scale_y = 0.33333334f;
    packet.u1 = 0.33333334f;
    packet.v0 = 0.33333334f;
    packet.v1 = 0.6666667f;
    packet.x = x;
    packet.y = y;
    packet.scale_x = 0.33333334f;
    packet.scale_y *= inner_height / 8.0f;
    fn_1_4F734(&packet);

    bottom = y + inner_height;
    packet.u0 = 0.0f;
    packet.u1 = 0.33333334f;
    packet.v0 = 0.6666667f;
    packet.v1 = 1.0f;
    packet.x = x;
    packet.y = bottom;
    packet.scale_x = 0.33333334f;
    packet.scale_y = 0.33333334f;
    fn_1_4F734(&packet);

    packet.scale_x = 0.33333334f;
    packet.u0 = 0.33333334f;
    packet.u1 = 0.6666667f;
    packet.v0 = 0.6666667f;
    packet.v1 = 1.0f;
    packet.x = (x + 8);
    packet.y = bottom;
    inner_w = inner_width / 8.0f;
    packet.scale_y = 0.33333334f;
    packet.scale_x *= inner_w;
    fn_1_4F734(&packet);

    packet.u0 = 0.33333334f;
    packet.u1 = 0.6666667f;
    packet.v0 = 0.0f;
    packet.v1 = 0.33333334f;
    if (flip == 0) {
        packet.x = (x + (inner_width + 8) / 2 + 1);
    } else {
        packet.x = (x + 2);
    }
    packet.y = y;
    packet.z -= 0.01f;
    packet.scale_x = 0.33333334f;
    packet.scale_y = 0.33333334f;
    half_w = (inner_width + 8) / 8.0f / 2.0f;
    packet.scale_x *= half_w;
    fn_1_4F734(&packet);

    packet.u0 = 0.33333334f;
    packet.u1 = 0.6666667f;
    packet.v0 = 0.33333334f;
    packet.v1 = 0.6666667f;
    if (flip == 0) {
        packet.x = (x + 2);
    } else {
        packet.x = (x + (inner_width + 8) / 2 + 1);
    }
    packet.y = y;
    packet.scale_x = 0.33333334f;
    packet.scale_y = 0.33333334f;
    packet.scale_x *= half_w;
    fn_1_4F734(&packet);

    packet.scale_x = 0.33333334f;
    packet.scale_y = 0.33333334f;
    packet.u0 = 0.33333334f;
    packet.u1 = 0.6666667f;
    packet.v0 = 0.33333334f;
    packet.v1 = 0.6666667f;
    packet.x = (x + 8);
    packet.y = (y + 8);
    packet.scale_x *= inner_w;
    packet.scale_y *= (inner_height - 8) / 8.0f;
    packet.z = 0.11f;
    fn_1_4F734(&packet);
}

#undef GAME_MAIN_REL_MEMCARD_TYPES_H
/* fzgx:end fn_1_BED04 */

/* fzgx:begin fn_1_BF198 */
/* VIEWS */
#define lbl_1_rodata_26F8 (*(f32 (*)[22])&lbl_1_rodata_26F8)


void fn_1_BF198(s32 a0, s32 a1, s32 a2, s32 a3, struct BF198_Arg4 *a4)
{
	s32 w = a2 - 8;
	s32 x0 = a0;
	s32 y0 = a1;
	s32 h = a3 - 16;
	f32 ws, hs;
	struct BF198_Pkt p;

	if (w < 0) {
		w = 0;
	}
	if (h < 0) {
		h = 0;
	}
	p = *(struct BF198_Pkt *)&lbl_1_rodata_26F8;

	p.kind = 12;
	p.flag = a4->value;
	p.z = 0.11f;
	p.sx = 0.33333334;
	p.u0 = 0.33333334;
	p.v0 = 0.6666667;
	p.u1 = 0.0;
	p.v1 = 0.33333334;
	p.x = x0;
	p.y = y0;
	p.sy = 0.33333334;
	ws = w / 8.0f;
	p.sx *= ws;
	fn_1_4F734((FontDrawPacket *)&p);

	w = x0 + w;
	p.u0 = 0.6666667;
	p.v0 = 1.0;
	p.u1 = 0.0;
	p.v1 = 0.33333334;
	p.x = w;
	p.y = y0;
	p.sx = 0.33333334;
	p.sy = 0.33333334;
	fn_1_4F734((FontDrawPacket *)&p);

	p.u0 = 0.6666667;
	p.v0 = 1.0;
	p.sy = 0.33333334;
	p.u1 = 0.33333334;
	p.v1 = 0.6666667;
	p.x = w;
	p.y = (y0 + 8);
	p.sx = 0.33333334;
	hs = h / 8.0f;
	p.sy *= hs;
	fn_1_4F734((FontDrawPacket *)&p);

	h = (((y0) + (8)) + h);
	p.u0 = 0.6666667;
	*(&p.v0) = 1.0;
	p.u1 = 0.6666667;
	p.v1 = 1.0;
	p.x = w;
	p.y = h;
	p.sx = 0.33333334;
	p.sy = 0.33333334;
	fn_1_4F734((FontDrawPacket *)&p);

	p.sx = 0.33333334;
	*(&p.u0) = 0.33333334;
	p.v0 = 0.6666667;
	p.u1 = 0.6666667;
	p.v1 = 1.0;
{
	*(&p.x) = (f32)x0;
}
	p.y = h;
	p.sy = 0.33333334;
	p.sx *= ws;
	fn_1_4F734((FontDrawPacket *)&p);

	p.sx = 0.33333334;
	p.sy = 0.33333334;
	p.u0 = 0.33333334;
	p.v0 = 0.6666667;
	p.u1 = 0.33333334;
	p.v1 = 0.6666667;
	p.x = x0;
	p.y = (y0 + 8);
	p.sx *= ws;
	p.sy *= hs;
	fn_1_4F734((FontDrawPacket *)&p);
}

#undef lbl_1_rodata_26F8
/* fzgx:end fn_1_BF198 */

/* fzgx:begin fn_1_BF520 */
void fn_1_BF520(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4) {
    struct FzgxCopy_88 loc_8;

    loc_8 = *(const struct FzgxCopy_88 *)((((((&lbl_1_rodata_26F8) + -4))) + 4));
    loc_8.words[0] = 0xC;
    loc_8.words[0xF] = *arg4;
    (*(f32 *)((u8 *)(&loc_8) + 12)) = 0.07f;
    (*(f32 *)((u8 *)(&loc_8) + 4)) = arg0;
    (*(f32 *)((u8 *)(&loc_8) + 8)) = arg1;
    fn_1_50164(arg2, arg3, 8.0f, 8.0f, &loc_8);
}
/* fzgx:end fn_1_BF520 */

/* fzgx:begin fn_1_BF600 */
void fn_1_BF600(s32 a, s32 b, s32 c, s32 d, u32 *source, f32 initial) {
    struct fn_1_BF600_Copy88 data;
    f32 oneEighth;

    data = *(const struct fn_1_BF600_Copy88 *)((((((&lbl_1_rodata_26F8) + -4))) + 4));
    data.words[0] = 0xC;
    data.words[15] = *source;
    (*(f32 *)((u8 *)(&data) + 12)) = initial;
    (*(f32 *)((u8 *)(&data) + 4)) = a;
    (*(f32 *)((u8 *)(&data) + 8)) = b;
    (*(f32 *)((u8 *)(&data) + 24)) = 0.3333333432674408f;
    (*(f32 *)((u8 *)(&data) + 32)) = 0.6666666865348816f;
    (*(f32 *)((u8 *)(&data) + 28)) = 0.3333333432674408f;
    (*(f32 *)((u8 *)(&data) + 36)) = 0.6666666865348816f;
    oneEighth = 0.125f;
    (*(f32 *)((u8 *)(&data) + 16)) = 0.3333333432674408f * c * oneEighth;
    (*(f32 *)((u8 *)(&data) + 20)) = 0.3333333432674408f * d * oneEighth;
    fn_1_4F734((FontDrawPacket *)&data);
}
/* fzgx:end fn_1_BF600 */

/* fzgx:begin fn_1_BF700 */
/* VIEWS */
#define lbl_1_rodata_26F8 (*(f32 (*)[22])&lbl_1_rodata_26F8)
void fn_1_BF700(s32 index, s32 cell, s32 mode, s32 x, s32 y, f32 scale_x, f32 scale_y, f32 z) {
    FontDrawPacket packet;
    s32 n;
    s32 col;
    s32 row;
    s16 state = *(s16 *)&lbl_1_bss_960;

    if (state != 12 && (u16)(state - 2) > 1) {
        return;
    }
    if (state == 2 && fn_1_485A8(0x97) == 0) {
        return;
    }
    n = index >= 41 ? 41 : index;
    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    if (*(s16 *)&lbl_1_bss_960 == 3 || *(s16 *)&lbl_1_bss_960 == 12) {
        packet.image = 0x9012;
    } else {
        packet.image = 0x973A;
    }
    row = n / 6;
    col = n - row * 6;
    packet.u0 = 0.16666667f * col;
    packet.u1 = 0.16666667f * (col + 1);
    packet.v0 = 0.14285715f * row;
    packet.v1 = 0.14285715f * (row + 1);
    packet.x = x;
    packet.y = y;
    packet.scale_x = 0.16666667f * scale_x;
    packet.scale_y = 0.14285715f * scale_y;
    packet.z = z;
    if (mode == 2 && cell == 1) {
        cell = 3;
    }
    if (mode >= 2) {
        packet.scale_x = packet.scale_x / 2.0f;
        packet.scale_y = packet.scale_y / 2.0f;
        packet.x = packet.x + ((cell % 2) * 38);
        packet.y = packet.y + ((cell / 2) * 38);
    }
    fn_1_4F734(&packet);
}
#undef lbl_1_rodata_26F8
/* fzgx:end fn_1_BF700 */

/* fzgx:begin fn_1_BF9C4 */
/* fzgx-allow: S2 pool primer sink */

static const f32 C_1C8 = 0.0f;

static const f32 C_1E0 = 1.0f;

static const f32 C_23C = 0.5f;

static const f32 C_540 = 16.0f;

static const f32 C_5D4 = 22.0f;

static const f32 C_5D8 = 24.0f;

static const f32 C_5DC = 2.0f;

static const f32 C_5E0 = 38.0f;

void fn_1_BF9C4(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4) {
    f32 var_f31;
    f32 temp;
    f32 y_off;

    var_f31 = C_5D4 * arg3;
    fn_1_49410();
    if (lbl_801A66B4 != 5) {
        fn_1_49590(C_23C);
        fn_1_495B0(0x80000000); // fzgx-allow: A1 bitmask
    }
    fn_1_494DC(8);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(C_1C8);
    fn_1_495B0(0x80000000); // fzgx-allow: A1 bitmask
    fn_1_495C8(1);
    temp = var_f31 / C_5D8;
    fn_1_4955C(temp, temp);
    fn_1_4966C(C_5DC, C_1C8);
    fn_1_496FC(arg1, arg2);
    fn_1_4954C(arg4);
    fn_1_4A0D8(lbl_1_data_2AA24[lbl_1_data_2B0D4[arg0]]);

    var_f31 = C_540 * arg3;
    fn_1_49410();
    if (lbl_801A66B4 != 5) {
        fn_1_49590(C_23C);
        fn_1_495B0(0x80000000); // fzgx-allow: A1 bitmask
    }
    fn_1_49738(fn_1_5233C);
    fn_1_49748(C_1E0);
    fn_1_495B0(0x80000000); // fzgx-allow: A1 bitmask
    fn_1_495C8(1);
    fn_1_4966C(C_5DC, C_1C8);
    temp = var_f31 / C_5D8;
    fn_1_4955C(temp, temp);
    y_off = C_5E0 * arg3;
    fn_1_496FC(arg1, arg2 + y_off);
    fn_1_4954C(arg4);
    fn_1_4A0D8(((Fn1BF9C4_Data *)lbl_1_data_2BD54)[arg0].unk[lbl_801A66B4]);
}
/* fzgx:end fn_1_BF9C4 */

/* fzgx:begin fn_1_BFBF4 */
/* VIEWS */
#define lbl_801A66B4 (*(u32 *)&lbl_801A66B4)
/* fzgx-allow: S2 pool primer sink */

/* parameter order from the callers (BC310 passes the two ints in r4/r5 and the floats in f1/f2) */
void fn_1_BFBF4(s32 arg0, s32 arg3, s32 arg4, f32 arg1, f32 arg2)
{
    static const u32 color_word[1] = {0xB0FFB000};
    u32 pool_word = color_word[0];
    fn_1_49514(&pool_word);

    fn_1_4955C(16.0f * arg1 / 24.0f, 16.0f * arg1 / 24.0f);

    fn_1_496FC(arg3, arg4);

    fn_1_4954C(arg2);

    fn_1_4CE48(*(Obj_1_bss_4B9CC **)(lbl_1_data_2BD54 + arg0 * 0x18
                                    + ((4) * lbl_801A66B4)),
               100.0f);
}
#undef lbl_801A66B4
/* fzgx:end fn_1_BFBF4 */

/* fzgx:begin fn_1_BFCF8 */
/* VIEWS */
void fn_1_BFCF8(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    fn_1_49410();

    if (lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        // fzgx-allow: A1 target uses the absolute sentinel address.
        fn_1_495B0((s32)0x80000000);
    }

    fn_1_494DC(6);
    // fzgx-allow: A1 target uses the absolute sentinel address.
    fn_1_495B0((s32)0x80000000);
    fn_1_495C8(1);
    fn_1_4955C(0.9f * arg5, (1.2 * arg5));
    fn_1_4966C(2.0f, 0.0f);
    fn_1_496FC(arg3, arg4);
    fn_1_4954C(arg6);
    fn_1_4AE0C("%02d'%02d\"%03d", arg0, arg1, arg2);
}
/* fzgx:end fn_1_BFCF8 */

/* fzgx:begin fn_1_BFE20 */
/* VIEWS */
/* VIEWS */
#define lbl_1_rodata_26F8 (*(struct fn_1_BFE20_Copy88 *)&lbl_1_rodata_26F8)
#define lbl_801A66B4 (*(u32 *)&lbl_801A66B4)
#define CLAMP01(v) ((v) < 0.0f ? 0.0f : ((v) > 1.0f ? 1.0f : (v)))

#define X (4.0f + (f32)(v30 * CLAMP01(arg5)))

void fn_1_BFE20(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    struct fn_1_BFE20_Copy88 dst;
    s32 i0;
    s32 i1;
    f32 v31;
    f32 v30;
    f32 v2;
    f32 v6;

    i0 = arg0;
    i1 = arg1;
    v31 = arg4 - 4.0f;
    v30 = v31 - 4.0f;
    dst = lbl_1_rodata_26F8;
    dst.unk_0 = 12;
    dst.x = (s16)i0;
    dst.y = (s16)i1;
    dst.z = arg2;
    dst.unk_30 = 6;
    fn_1_50190(&dst, arg3, arg4, 7.0f, 7.0f, 7.0f, 7.0f);

    v2 = v30 * CLAMP01(arg6);
    dst = lbl_1_rodata_26F8;
    dst.unk_0 = 0;
    dst.x = (s16)i0;
    v6 = (X < 4.0f) ? 4.0f : ((X > (v31 - v2)) ? (v31 - v2) : X);
    dst.y = (s16)i1 + v6;
    dst.z = arg2 - 0.01f;
    dst.unk_30 = 6;
    fn_1_50164(12.0f, v2, 5.0f, 5.0f, &dst);
}
/* fzgx:end fn_1_BFE20 */

/* fzgx:begin fn_1_C00EC */
/* memcard.c's .data objects this function uses, at their retail offsets, so MWCC addresses them off one section
 * base; the fzgx_pool_gap_ objects span the retail objects in between */

/* per language: "VS BATTLE", "GRAND PRIX", "TIME ATTACK" */

/* per language: "Novice", "Standard", "Expert", "Master" */

/* retail allocates the size of the second call apart from its table lookup: a temporary kept by
 * opt_propagation off */

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_C00EC(u8 a, u8 b, s32 x, s32 y, f32 scale) {
    static char *lbl_1_data_3CF9C[6][3] = {"VS BATTLE", "GRAND PRIX", "TIME ATTACK", "", "", "", "", "", "", "", "", "", "", "", "", "VS\203o\203g\203\213", "\203O\203\211\203\223\203v\203\212", "\203^\203C\203\200\203A\203^\203b\203N"};
    static char *lbl_1_data_3D040[6][4] = {"Novice", "Standard", "Expert", "Master", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "\203m\201[\203r\203X", "\203X\203^\203\223\203_\201[\203h", "\203G\203L\203X\203p\201[\203g", "\203}\203X\203^\201["};
    f32 size;

    if (a <= 2 && b <= 3) {
        fn_1_496FC(x, y);
        {
            Color color = {0xFF, 0xB0, 0xB0, 0xFF};
            fn_1_49514(&color);
        }
        fn_1_4955C(scale, scale);
        if (a == 1) {
            fn_1_4CF3C("%s(%s)", 117.0f, lbl_1_data_3CF9C[lbl_801A66B4][a], lbl_1_data_3D040[lbl_801A66B4][b]);
        } else {
            size = 117.0f;
            fn_1_4CF3C(lbl_1_data_3CF9C[lbl_801A66B4][a], size);
        }
    }
}

#pragma opt_propagation reset
#undef lbl_1_rodata_26F8
#undef lbl_801A66B4
#undef CLAMP01
#undef X
/* fzgx:end fn_1_C00EC */

/* fzgx:begin fn_1_C023C */
/* fzgx-allow: S2 pool primer sink */

void fn_1_C023C(s32 a, s32 b, f32 value, s32 c, s32 d, s32 e, s32 f, s32 g, f32 unused) {
    static const u32 color_t29[1] = {0xFFFFA0FF};
    Fn1C023CBuf local_b;
    u32 local_a;

    local_a = color_t29[0];
    fn_1_49514(&local_a);
    fn_1_495C8(8);
    fn_1_496FC(a, b);
    fn_1_4955C(value, value);
    fn_1_4954C((0.0600000024f));

    if ((u8)c >= 0x29 && (u8)d != 0) {
        fn_1_14FEAC(e, f, g, local_b.w, lbl_801A66B4);
        fn_1_4CF3C((void *)local_b.w, 100.0f);
    } else {
        fn_1_7F49C(c, lbl_801A66B4, local_b.w);
        fn_1_4CF3C((void *)local_b.w, 100.0f);
    }
}
/* fzgx:end fn_1_C023C */

/* fzgx:begin fn_1_C0374 */
/* VIEWS */
#define lbl_1_bss_77380 (*(Obj_1_bss_77380 *)&lbl_1_bss_77380)
#define lbl_1_bss_7AB90 (*(u32 (*)[36])&lbl_1_bss_7AB90)
/* fzgx-allow: S2 pool primer sink */

void fn_1_C0374(s32 arg0, s32 arg1, f32 value, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, f32 unused) {
    static const u32 color_t30[1] = {0xFFFFA0FF};
    u32 local;
    u8 buffer[0x40];

    fn_1_49410();

    if (lbl_801A66B4 != 5) {
        fn_1_49590((0.5f));
        fn_1_495B0(-2147483648);
    }

    fn_1_49614();
    fn_1_49738(fn_1_5233C);
    fn_1_49748((1.0f));
    local = color_t30[0];
    fn_1_49514(&local);
    fn_1_495C8(9);
    fn_1_496FC(arg0, arg1);
    fn_1_4955C(value, value);
    fn_1_4966C((-2.0f), (0.0f));

    if (lbl_801A66B4 != 5) {
        fn_1_4966C((-1.0f), (0.0f));
    }

    fn_1_4954C((0.0600000024f));

    if ((u8)arg2 >= 0x29 && (u8)arg3 != 0) {
        fn_1_14FEAC((u8)arg4, (u8)arg5, (u8)arg6, (void *)buffer, lbl_801A66B4);
        fn_1_4CF3C((void *)buffer, 120.0f);
    } else {
        fn_1_7F49C((u8)arg2, lbl_801A66B4, (void *)buffer);
        fn_1_4CF3C((void *)buffer, 120.0f);
    }
}
/* fzgx:end fn_1_C0374 */

/* fzgx:begin fn_1_C0510 */
void fn_1_C0510(Fn1C0510Obj *obj) {
    u64 time;
    void *first;
    void *second;

    time = OSGetTime();
    // fzgx-allow: A1 fixed SDK OS global
    // fzgx-allow: A2 fixed SDK OS global
    lbl_1_bss_7AB90[0] = __div2i(time, 0, (*(u32 *)0x800000F8) >> 2);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */

    if (obj->first != -1 && obj->second != -1) {
        first = (*(u8 (*)[])&lbl_1_bss_77380) + obj->first * 0x1800 + obj->second * 0x30;
    } else {
        first = 0;
    }

    if (obj->third != -1 && obj->fourth != -1) {
        second = (*(u8 (*)[])&lbl_1_bss_77380) + obj->third * 0x1800 + obj->fourth * 0x30;
    } else {
        second = 0;
    }

    switch (obj->type) {
    case 1:
        fn_1_C062C((void *)obj, (void *)first, (void *)second);
        break;
    case 2:
        fn_1_C0B0C((void *)obj, first, second);
        break;
    case 4:
        fn_1_C0E00((void *)obj, (void *)first, (void *)second);
        break;
    case 8:
        fn_1_C132C((void *)obj, (void *)first, (void *)second);
        break;
    }
}
#undef lbl_1_bss_77380
#undef lbl_1_bss_7AB90
/* fzgx:end fn_1_C0510 */

/* fzgx:begin fn_1_C062C */
/* VIEWS */
#define lbl_1_bss_77380 (*(Slot_C062C (*)[2][128])&lbl_1_bss_77380)
#define lbl_1_data_35B5C (*(u8 (*)[0x40])&lbl_1_data_35B5C)
#define lbl_1_data_35B9C (*(u8 (*)[0x40])&lbl_1_data_35B9C)
#define lbl_1_data_35BDC (*(u8 (*)[0x6BDC])&lbl_1_data_35BDC)
void fn_1_C062C(SaveReq *req, Slot_C062C *first, Slot_C062C *second) {
    u8 *buf;
    u32 size2;
    u8 small;
    s32 size;
    void *icon;
    char date[0x100];
    FileInfo file;
    SaveInfo info;
    CalTime ct;
    char name[0x20];

    size = (req->unk_C + 0x405F) & ~0x1FFF;
    if (size >= 0x6000) {
        small = 0;
        lbl_1_bss_7A380[0] = ((void *)fn_1_4630((void *)lbl_801A6410, size, (void *)((const char *)"memcard.c"), 0x316F));
    } else {
        small = 1;
        lbl_1_bss_7A380[0] = ((void *)fn_1_4630((void *)lbl_801A6410, 0x6000, (void *)((const char *)"memcard.c"), 0x3172));
    }
    buf = lbl_1_bss_7A380[0];
    OSTicksToCalendarTime(OSGetTime(), (void *)&ct);

    switch (req->unk_10) {
    case 2:
        sprintf(date, (const char *)"%02d/%02d/%02d %02d:%02d", ct.year % 100, ct.mon + 1, ct.mday, ct.hour, ct.min);
        if (req->unk_30[req->unk_1A] - 1 != req->unk_1C) {
            strcpy((void *)name, (void *)lbl_1_bss_77380[req->unk_1A][req->unk_1C].text);
        } else {
            sprintf(name, (const char *)"%08x%08x", (u32)(OSGetTime() >> 32), (u32)OSGetTime());
        }
        size2 = 0x3EA8;
        { char **names = ((char **)lbl_1_data_35B9C);
        if (fn_1_45730(names[lbl_801A66B4], &file) != 0) {
            fn_1_458A0(&file, buf + 0x60, 0x2000, 0);
            fn_1_45850(&file);
        }}
        break;
    case 4:
        sprintf(date, (const char *)"%02d/%02d/%02d %02d:%02d", ct.year % 100, ct.mon + 1, ct.mday, ct.hour, ct.min);
        size2 = req->unk_C;
        if (req->unk_30[req->unk_1A] - 1 != req->unk_1C) {
            strcpy((void *)name, (void *)lbl_1_bss_77380[req->unk_1A][req->unk_1C].text);
        } else {
            sprintf(name, (const char *)"%05X%05X%06X%08X", size2, size2, (u32)(((OSGetTime() >> 32) << 2) >> 2), OSGetTick());
        }
        { char **names = ((char **)lbl_1_data_35B5C);
        if (fn_1_45730(names[lbl_801A66B4], &file) != 0) {
            fn_1_458A0(&file, buf + 0x60, 0x2000, 0);
            fn_1_45850(&file);
        }}
        icon = fn_1_C1CFC((void *)req->unk_8, 0x40, 0x40, 0.5f);
        fn_1_C23CC((void *)(buf + 0x60), 0x60, 0x20, (void *)icon, 0x20, 0x20, 0x40, 0);
        fn_80008BA8(buf + 0x1860, icon, 0x800);
        fn_1_46B4((u32)lbl_801A6410, (u32)icon, (const char *)"memcard.c", 0x31A3);
        break;
    case 5:
        sprintf(date, (const char *)"%02d/%02d/%02d %02d:%02d", ct.year % 100, ct.mon + 1, ct.mday, ct.hour, ct.min);
        sprintf(name, (const char *)"%08X", req->unk_C);
        if (small) {
            size2 = 0x3F80;
        } else {
            size2 = req->unk_C;
        }
        sprintf(name, (const char *)"%s%05X%08X", name, (u32)(((OSGetTime() >> 32) << 12) >> 12), OSGetTick());
        { char **names = ((char **)lbl_1_data_35BDC);
        if (fn_1_45730(names[lbl_801A66B4], &file) != 0) {
            fn_1_458A0(&file, buf + 0x60, 0x2000, 0);
            fn_1_45850(&file);
        }}
        break;
    }

    strncpy((void *)((char *)(buf + 0x24)), (void *)date, 0x20);
    sprintf(lbl_1_bss_7AB94, (const char *)"%s", name);
    lbl_1_bss_7ABB4 = second->unk_1;
    lbl_1_bss_7ABB8 = (size2 + 0x405F) & ~0x1FFF;
    fn_80008BA8(buf + 0x2060, req->unk_8, req->unk_C);
    fn_80008BEC((void *)&info, 0, 0x24);
    info.kind = req->unk_10;
    info.size = size2;
    info.buffer = lbl_1_bss_7A380[0];
    info.name = lbl_1_bss_7AB94;
    info.date = date;
    fn_1_AA6D8(0, req->unk_16, (void *)&info);
}
#undef lbl_1_bss_77380
#undef lbl_1_data_35B5C
#undef lbl_1_data_35B9C
#undef lbl_1_data_35BDC
/* fzgx:end fn_1_C062C */

/* fzgx:begin fn_1_C0B0C */
/* VIEWS */
#define lbl_1_bss_77380 (*(Obj_1_bss_77380 *)&lbl_1_bss_77380)
// Reads `len` uppercase hexadecimal digits, most significant first.

static inline u32 parse_hex(u8 *text, s32 len) {
    s32 i;
    u32 c;
    u32 value;

    value = 0;
    for (i = 0; i < len; i++, text++) {
        c = *text;
        if (c >= 'A' && c <= 'F') {
            c -= 'A' - 10;
        } else {
            c -= '0';
        }
        value += c << ((len - 1 - i) << 2);
    }
    return value;
}

// Parses the entry's hexadecimal size field and reallocates the request buffer.

void fn_1_C0B0C(MemcardRequest_C0B0C *req, void *unused1, void *unused2) {
    MemcardEntry_C0B0C *entry;
    u32 value;
    s32 i;

    entry = (MemcardEntry_C0B0C *)((u8 *)&lbl_1_bss_77380 + req->unk_1A * 0x1800 + req->unk_1C * 0x30);
    if (entry->state == 2) {
        req->unk_C = 0x3ea8;
    } else if (entry->state == 4) {
        req->unk_C = parse_hex(entry->text, 5);
    } else if (entry->state == 5) {
        req->unk_C = parse_hex(entry->text, 8);
    }

    if (req->unk_8 != 0) {
        fn_1_46B4(lbl_801A6410, req->unk_8, "memcard.c", 0x31ea);
        req->unk_8 = 0;
    }
    if (entry->unk_2C != 0) {
        req->unk_8 = fn_1_4630(lbl_801A6410, req->unk_C, "memcard.c", 0x31ef);
        fn_80008BA8((void *)req->unk_8, (void *)entry->unk_2C, req->unk_C);
    } else {
        req->unk_8 = 0;
    }
}
#undef lbl_1_bss_77380
/* fzgx:end fn_1_C0B0C */

/* fzgx:begin fn_1_C0E00 */
/* VIEWS */
#define lbl_1_data_35B5C (*(u8 (*)[0x40])&lbl_1_data_35B5C)
#define lbl_1_data_35B9C (*(u8 (*)[0x40])&lbl_1_data_35B9C)
#define lbl_1_data_35BDC (*(u8 (*)[0x6BDC])&lbl_1_data_35BDC)
void fn_1_C0E00(SaveReq *req, Slot_C0E00 *first, Slot_C0E00 *second) {
    void *icon;
    u32 c;
    s32 i;
    u32 size;
    u8 *buf;
    char name[0x100];
    char date[0x100];
    FileInfo file;
    SaveInfo info;
    CalTime ct;

    size = second->unk_24 >= 0x6000 ? second->unk_24 : 0x6000;
    buf = ((void *)fn_1_4630((void *)lbl_801A6410, size, (void *)((const char *)"memcard.c"), 0x320C));
    lbl_1_bss_7A380[0] = buf;
    OSTicksToCalendarTime(OSGetTime(), (void *)&ct);

    if (second->unk_1 == 2) {
        sprintf(date, (const char *)"%02d/%02d/%02d %02d:%02d", ct.year % 100, ct.mon + 1, ct.mday, ct.hour, ct.min);
        sprintf(name, (const char *)"%08x%08x", (u32)(OSGetTime() >> 32), (u32)OSGetTime());
        size = 0x3EA8;
        if (fn_1_45730(((char **)lbl_1_data_35B9C)[lbl_801A66B4], &file) != 0) {
            fn_1_458A0(&file, buf + 0x60, 0x2000, 0);
            fn_1_45850(&file);
        }
    } else if (second->unk_1 == 4) {
        sprintf(date, (const char *)"%02d/%02d/%02d %02d:%02d", ct.year % 100, ct.mon + 1, ct.mday, ct.hour, ct.min);
        size = 0;
        for (i = 0; i < 5; i++) {
            c = second->text[i];
            if (c >= 'A' && c <= 'F') {
                c -= 0x37;
            } else {
                c -= 0x30;
            }
            size += c << ((4 - i) * 4);
        }
        sprintf(name, (const char *)"%05X%05X%06X%08X", size, size, (u32)(((OSGetTime() >> 32) << 2) >> 2), OSGetTick());
        if (fn_1_45730(((char **)lbl_1_data_35B5C)[lbl_801A66B4], &file) != 0) {
            fn_1_458A0(&file, buf + 0x60, 0x2000, 0);
            fn_1_45850(&file);
        }
        icon = fn_1_C1CFC((void *)second->unk_2C, 0x40, 0x40, 0.5f);
        fn_1_C23CC((void *)(buf + 0x60), 0x60, 0x20, (void *)icon, 0x20, 0x20, 0x40, 0);
        fn_80008BA8(buf + 0x1860, icon, 0x800);
        fn_1_46B4((u32)lbl_801A6410, (u32)icon, (const char *)"memcard.c", 0x322E);
    } else {
        sprintf(date, (const char *)"%02d/%02d/%02d %02d:%02d", ct.year % 100, ct.mon + 1, ct.mday, ct.hour, ct.min);
        strncpy((void *)name, (void *)((char *)second->text), 8);
        name[8] = 0;
        size -= 0x2060;
        sprintf(name, (const char *)"%s%05X%08X", name, (u32)(((OSGetTime() >> 32) << 12) >> 12), OSGetTick());
        if (fn_1_45730(((char **)lbl_1_data_35BDC)[lbl_801A66B4], &file) != 0) {
            fn_1_458A0(&file, buf + 0x60, 0x2000, 0);
            fn_1_45850(&file);
        }
    }

    strncpy((void *)((char *)(buf + 0x24)), (void *)date, 0x20);
    sprintf(lbl_1_bss_7AB94, (const char *)"%s", name);
    lbl_1_bss_7ABB4 = second->unk_1;
    lbl_1_bss_7ABB8 = (size + 0x405F) & ~0x1FFF;
    if (second->unk_2C != 0) {
        OSReport((const char *)"mem_size: %d\n", size);
        fn_80008BA8(buf + 0x2060, second->unk_2C, size);
    }
    fn_80008BEC((void *)&info, 0, 0x24);
    info.kind = second->unk_1;
    info.size = size;
    info.buffer = lbl_1_bss_7A380[0];
    info.name = name;
    info.date = date;
    fn_1_AA6D8(0, req->unk_16, (void *)&info);
}
#undef lbl_1_data_35B5C
#undef lbl_1_data_35B9C
#undef lbl_1_data_35BDC
/* fzgx:end fn_1_C0E00 */

/* fzgx:begin fn_1_C132C */
void fn_1_C132C(Fn1C132CObject *object, u8 *data, void *unused2) {
    u8 local[0x24];

    fn_80008BEC(local, 0, 0x24);
    local[0] = data[1];
    *(u8 **)(local + 0x14) = data + 2;
    fn_1_AA6D8(5, (u8)object->unk16, (void *)local);
}
/* fzgx:end fn_1_C132C */

/* fzgx:begin fn_1_C1394 */
/* VIEWS */
#define lbl_1_bss_77380 (*(McEntry (*)[2][128])&lbl_1_bss_77380)
#define lbl_1_bss_7A380 (*(void * *)&lbl_1_bss_7A380)
#define lbl_1_bss_7A39C (*(McName (*)[2][127])&lbl_1_bss_7A39C)
/* sort the used entries of one card by their unk_28 key (bubble sort), names alongside */

static inline void SortEntries(McEntry *entries, McName *names) {
    McEntry tmp;
    McName tmpName;
    s32 j;
    s32 i;
    s32 count;

    count = 0;
    for (i = 0; i < 127; i++) {
        if (entries[i].unk_24 != 0) {
            count++;
        }
    }
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (entries[i].unk_28 > entries[j].unk_28) {
                tmp = entries[i];
                entries[i] = entries[j];
                entries[j] = tmp;
                tmpName = names[i];
                names[i] = names[j];
                names[j] = tmpName;
            }
        }
    }
}

void fn_1_C1394(McState *state) {
    McEntry *src;
    McEntry *dst;
    /* WARNING: compiler-diff device, not original code */
    struct { u32 value; } slot;
    struct { u32 value; } card;

    if (state->unk_16 != -1 && state->unk_18 != -1) {
        src = &lbl_1_bss_77380[state->unk_16][state->unk_18];
    } else {
        src = NULL;
    }
    if (state->unk_1A != -1 && state->unk_1C != -1) {
        dst = &lbl_1_bss_77380[state->unk_1A][state->unk_1C];
    } else {
        dst = NULL;
    }
    state->unk_16 = state->unk_1A;
    state->unk_18 = 0;
    state->unk_1A = -1;
    state->unk_1C = -1;
    state->unk_22 = 3;

    if (lbl_1_bss_7A380 != NULL) {
        fn_1_46B4((u32)lbl_801A6410, (u32)lbl_1_bss_7A380, "memcard.c", 0x3291);
        lbl_1_bss_7A380 = NULL;
    }

    if ((s32)lbl_1_bss_718B8 == 0) {
        OSReport("result_code: %d\n", lbl_1_bss_718B4);
        if (lbl_1_bss_718B4 == -123) {
            card.value = state->unk_16;
            for (slot.value = 0; (s32)slot.value < 127; slot.value++) {
                if (lbl_1_bss_77380[card.value][slot.value].unk_2C != 0) {
                    fn_1_46B4((u32)lbl_801A6410, (u32)((void *)lbl_1_bss_77380[card.value][slot.value].unk_2C), "memcard.c", 0x2776);
                }
                lbl_1_bss_77380[card.value][slot.value].unk_1 = 0;
                lbl_1_bss_77380[card.value][slot.value].unk_2 = 0;
                lbl_1_bss_77380[card.value][slot.value].unk_24 = 0;
                lbl_1_bss_77380[card.value][slot.value].unk_28 = 0;
                lbl_1_bss_77380[card.value][slot.value].unk_2C = 0;
            }
            state->unk_5 &= ~(1 << state->unk_16);
            if (state->unk_16 == 0) {
                state->unk_1E = 0;
            }
            if (state->unk_16 == 1) {
                state->unk_1F = 0;
            }
        }
        return;
    }

    switch (state->unk_14) {
    case 1:
        fn_1_C17CC((void *)state, (void *)src, (void *)dst);
        break;
    case 2:
        break;
    case 4:
        fn_1_C17D0((void *)state, (void *)src, (void *)dst);
        break;
    case 8:
        fn_1_C1ACC((u32)state, (void *)src, (void *)dst);
        break;
    }

    card.value = 0;
    state->unk_3C = 0;
    state->unk_3D = 0;
    if ((s32)state->unk_3C != 1) {
        fn_1_BB974(state);
        return;
    }

    for (; (s32)card.value < 2; card.value++) {
        SortEntries(lbl_1_bss_77380[card.value], lbl_1_bss_7A39C[card.value]);
    }
}
#undef lbl_1_bss_77380
#undef lbl_1_bss_7A380
#undef lbl_1_bss_7A39C
/* fzgx:end fn_1_C1394 */

/* fzgx:begin fn_1_C17CC */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
// fn_1_C17CC: empty in retail (single blr).

void fn_1_C17CC(void *unused0, void *unused1, void *unused2) {
}
/* fzgx:end fn_1_C17CC */

/* fzgx:begin fn_1_C17D0 */
static inline u32 fn_1_hexnum(u8 *s, u32 len) {
	u32 i;
	u32 c;
	u32 v;

	v = 0;
	for (i = 0; i < len; i++) {
		c = s[i];
		if (c >= 0x41 && c <= 0x46) {
			c -= 0x37;
		} else {
			c -= 0x30;
		}
		v += c << ((len - 1 - i) * 4);
	}
	return v;
}

static inline u32 fn_1_hexnum2(u8 *s, u32 len) {
	u8 *p;
	u32 i;
	u32 c;
	u32 v;

	v = 0;
	for (i = 0, p = s; i < len; i++, p++) {
		c = *p;
		if (c >= 0x41 && c <= 0x46) {
			c -= 0x37;
		} else {
			c -= 0x30;
		}
		v += c << ((len - 1 - i) * 4);
	}
	return v;
}

void fn_1_C17D0(void *arg0, MemCardFile *file, MemCardFile *prev) {
	u32 val;

	file->unk_1 = lbl_1_bss_7ABB4;
	file->unk_24 = lbl_1_bss_7ABB8;
	file->unk_28 = lbl_1_bss_7AB90;
	strncpy(file->unk_2, lbl_1_bss_7AB94, 0x20);

	if (file->unk_1 == 2) {
		val = 0x3EA8;
	} else if (4 == file->unk_1) {
		val = fn_1_hexnum(file->unk_2, 5);
	} else if (file->unk_1 == 5) {
		val = fn_1_hexnum2(file->unk_2, 8);
	}

	if ((file->unk_2c) != 0) {
		fn_1_46B4((u32)(*(void **)&lbl_801A6410), (u32)file->unk_2c, "memcard.c", 0x32E5);
		file->unk_2c = 0;
	}
	file->unk_2c = (void *)fn_1_4630(*(void **)&lbl_801A6410, val, "memcard.c", 0x32E8);
	if (prev->unk_2c != 0) {
		fn_80008BA8((void *)((u32)(file->unk_2c)), (void *)((u32)prev->unk_2c), val);
	}
}

#undef lbl_1_bss_716C0
/* fzgx:end fn_1_C17D0 */

/* fzgx:begin fn_1_C1ACC */
/* VIEWS */
#define lbl_1_bss_77380 (*(Obj_1_bss_77380 *)&lbl_1_bss_77380)
void fn_1_C1ACC(u32 arg0, MemcardEntry_C1ACC *arg1, void *unused2) {
    int i;
    int idx;
    int which;
    MemcardEntry_C1ACC (*tbl)[127];

    if (arg1->unk_2C != 0) {
        fn_1_46B4((u32)lbl_801A6410, arg1->unk_2C, (void *)"memcard.c", 0x32F8);
        arg1->unk_2C = 0;
    }
    tbl = (MemcardEntry_C1ACC (*)[127])(&lbl_1_bss_77380);
    for (i = 0; i < 127; i++) {
        if (&((MemcardEntry_C1ACC *)&lbl_1_bss_77380)[i] == arg1) {
            idx = i;
            which = 0;
            break;
        }
        if ((MemcardEntry_C1ACC *)((u8 *)&((MemcardEntry_C1ACC *)&lbl_1_bss_77380)[i] + 0x1800) == arg1) {
            idx = i;
            which = 1;
            break;
        }
    }
    for (i = idx; i < 126; i++) {
        ((MemcardEntry_C1ACC *)((u8 *)&lbl_1_bss_77380 + which * 0x1800))[i] =
            ((MemcardEntry_C1ACC *)((u8 *)&lbl_1_bss_77380 + which * 0x1800))[i + 1];
    }
    fn_80008BEC(&((MemcardEntry_C1ACC *)((u8 *)&lbl_1_bss_77380 + which * 0x1800))[126], 0, 0x30);
}
#undef lbl_1_bss_77380
/* fzgx:end fn_1_C1ACC */

/* fzgx:begin fn_1_C1CFC */
/* VIEWS */
static inline u32 GetA3(s16 texel) { return (texel >> 12) & 7; }

/* Rescales an RGB5A3 tiled texture of w x h texels by scale (box filter). */

void *fn_1_C1CFC(void *src, u32 w, u32 h, f32 scale) {
    u8 *tmp;
    u8 *q;
    u32 c;
    u32 y;
    u32 *red;
    u32 *green;
    u32 n;
    u32 *blue;
    u32 by;
    u32 bx;
    u32 r;
    u32 x;
    u32 j;
    u32 k;
    u32 *alpha;
    u32 a;
    u8 *out;
    u32 i;
    u32 idx;
    u32 nh;
    u16 px;
    u8 *dst;
    u32 g;
    u32 b;
    u32 nw;
    u32 row;
    u32 size;
    u32 sr;
    u32 sg;
    u8 *p;
    u32 sb;
    u32 sa;

    n = w * h;
    size = scale * (scale * n);
    out = fn_1_45D0((u32)lbl_801A6410, size * 2, (void *)"memcard.c", 0x3328);
    tmp = fn_1_45D0((u32)lbl_801A6410, size * 2, (void *)"memcard.c", 0x3329);
    red = fn_1_45D0((u32)lbl_801A6410, n * 4, (void *)"memcard.c", 0x332B);
    green = fn_1_45D0((u32)lbl_801A6410, n * 4, (void *)"memcard.c", 0x332C);
    blue = fn_1_45D0((u32)lbl_801A6410, n * 4, (void *)"memcard.c", 0x332D);
    alpha = fn_1_45D0((u32)lbl_801A6410, n * 4, (void *)"memcard.c", 0x332E);

    dst = tmp;
    p = src;
    for (by = 0; by < w / 4; by++) {
        for (bx = 0; bx < h / 4; bx++) {
            for (k = 0; k < 16; k++) {
                memcpy(&px, p, 2);
                p += 2;
                c = px;
                if (c & 0x8000) {
                    row = by * 4 + k / 4;
                    idx = bx * 4 + k % 4 + row * h;
                    alpha[idx] = 255;
                    red[idx] = ((c & 0x7C00) >> 10) * 255 / 31;
                    green[idx] = ((c >> 5) & 0x1F) * 255 / 31;
                    blue[idx] = (c & 0x1F) * 255 / 31;
                } else {
                    row = by * 4 + k / 4;
                    idx = bx * 4 + k % 4 + row * h;
                    alpha[idx] = GetA3(c) * 255 / 7;
                    red[idx] = ((c & 0xF00) >> 8) * 255 / 15;
                    green[idx] = ((c & 0xF0) >> 4) * 255 / 15;
                    blue[idx] = (c & 0xF) * 255 / 15;
                }
            }
        }
    }

    for (y = 0; y < w * scale; y++) {
        for (x = 0; x < h * scale; x++) {
            sa = 0;
            sb = 0;
            sg = 0;
            sr = 0;
            for (j = 0; j < 1.0f / scale; j++) {
                for (i = 0; i < 1.0f / scale; i++) {
                    idx = ((u32)(y / scale) + j) * h + (i + (u32)(x / scale));
                    sr += red[idx];
                    sg += green[idx];
                    sb += blue[idx];
                    sa += alpha[idx];
                }
            }
            r = sr * (scale * scale);
            g = sg * (scale * scale);
            b = sb * (scale * scale);
            a = sa * (scale * scale);
            c = (((r >> 4) & 0xF) << 8) | (((g >> 4) & 0xF) << 4) | ((b >> 4) & 0xF) | (((a >> 5) & 7) << 12);
            if (a >= 0xE0) {
                c = (((r >> 3) & 0x1F) << 10) | (((g >> 3) & 0x1F) << 5) | ((b >> 3) & 0x1F) | 0x8000;
            }
            px = c;
            memcpy(dst, &px, 2);
            dst += 2;
        }
    }

    nw = h * scale;
    nh = w * scale;
    q = out;
    for (by = 0; by < nh; by += 4) {
        for (bx = 0; bx < nw; bx += 4) {
            p = tmp + (by * nw + bx) * 2;
            memcpy(q, p, 8);
            p = tmp + ((by + 1) * nw + bx) * 2;
            memcpy(q + 8, p, 8);
            p = tmp + ((by + 2) * nw + bx) * 2;
            memcpy(q + 16, p, 8);
            p = tmp + ((by + 3) * nw + bx) * 2;
            memcpy(q + 24, p, 8);
            q += 32;
        }
    }

    fn_1_46B4((u32)lbl_801A6410, (u32)alpha, (void *)"memcard.c", 0x3380);
    fn_1_46B4((u32)lbl_801A6410, (u32)blue, (void *)"memcard.c", 0x3381);
    fn_1_46B4((u32)lbl_801A6410, (u32)green, (void *)"memcard.c", 0x3382);
    fn_1_46B4((u32)lbl_801A6410, (u32)red, (void *)"memcard.c", 0x3383);
    fn_1_46B4((u32)lbl_801A6410, (u32)tmp, (void *)"memcard.c", 0x3385);
    return out;
}
/* fzgx:end fn_1_C1CFC */

/* fzgx:begin fn_1_C23CC */
/* VIEWS */
#define lbl_1_bss_716C0 (*(u8 *)&lbl_1_bss_716C0)
void fn_1_C23CC(void *base0, u32 stride0, u32 arg2, void *base1,
                u32 stride1, u32 count_add, u32 offset, u32 count) {
    s32 i;
    u32 size;
    u32 end;
    u32 p;

    i = count >> 2;
    size = (stride1 & 0x7FFFFFF) << 3;
    end = count + count_add;
    p = count;
    while (p < end) {
        fn_80008BA8((void *)((u8 *)base0 + (((offset + i * stride0) & 0x7FFFFFF) << 3)),
                    (void *)((u8 *)base1 + (((i * stride1) & 0x7FFFFFF) << 3)),
                    size);
        i++;
        p += 4;
    }
}
/* fzgx:end fn_1_C23CC */

/* fzgx:begin fn_1_C2454 */
void fn_1_C2454(void) {
    lbl_1_bss_7ABBC[0] = 0;
    lbl_1_bss_7ABC4 = 0;
    fn_1_C36EC();
    lbl_1_bss_7ABC8 = 3;
    lbl_1_bss_7ABCC[0] = 0;
}
#undef lbl_1_bss_716C0
/* fzgx:end fn_1_C2454 */

/* fzgx:begin fn_1_C24A4 */
/* VIEWS */
#define lbl_1_bss_718C0 (*(u32 *)&lbl_1_bss_718C0)
#define lbl_1_bss_718E0 (*(u8 (*)[0x59E8])&lbl_1_bss_718E0)
#define lbl_1_bss_7ABBC (*(u8 *)&lbl_1_bss_7ABBC)
#define lbl_1_bss_7ABCC (*(u8 *)&lbl_1_bss_7ABCC)
#define lbl_1_data_3B74C (*(Obj_1_data_3B74C_L *)&lbl_1_data_3B74C)
/* VIEWS */
#define lbl_1_bss_8B3A0 (*(Obj_1_bss_8B3A0_L *)&lbl_1_bss_8B3A0)
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)
#define lbl_1_bss_9F8 (*(Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)
#define lbl_1_rodata_26F8 (*(struct fn_1_C24A4_Copy88 *)&lbl_1_rodata_26F8)
#define lbl_801A66B4 (*(u32 *)&lbl_801A66B4)
/* begin rel/main_rel/driver.h (fork-deltawave784/windows-and-types@b1e6f2df) */

#define REL_MAIN_REL_DRIVER_H

/* begin rel/main_rel/globals.h (fork-deltawave784/windows-and-types@b1e6f2df) */

#define REL_MAIN_REL_GLOBALS_H

#define PCB (*(void (**)(void *, void *))((u8 *)&packet + 0x50))

#define PF(off) (*(f32 *)((u8 *)&packet + (off)))

#define PW(off) (*(u32 *)((u8 *)&packet + (off)))

#define PH(off) (*(s16 *)((u8 *)&packet + (off)))

static inline const char *fn_1_C24A4_string(u32 off) {
    u32 address = (u32)&lbl_1_data_3B74C;
    address += lbl_801A66B4 << 2;
    return *(const char **)(address + off);
}

#define STR(off) fn_1_C24A4_string(off)

/* nonzero when a card that is not busy can take a write (the per-card check of the save prompt) */
static inline s32 card_writable(void) {
    u8 slot1;
    u8 slot0;
    u8 mask;
    s32 present;

    slot0 = lbl_1_bss_716C8[0].unk_2;
    present = 0;
    mask = present;
    if (slot0 != 0xFF) mask |= 1;
    slot1 = lbl_1_bss_716C8[1].unk_2;
    if (slot1 != 0xFF) mask |= 2;
    if (lbl_1_bss_71810.unk_2 != 0xFF) mask |= 4;
    if (mask & 1) {
        if (slot0 == 2) {
            if (!(lbl_1_bss_716C8[0].unk_2A & 8) &&
                !(lbl_1_bss_716C8[0].unk_2A & 4)) present |= 1;
        } else {
            if (!(lbl_1_bss_716C8[0].unk_2A & 4)) present |= 1;
        }
    }
    if (mask & 2) {
        if (slot1 == 2) {
            if (!(lbl_1_bss_716C8[1].unk_2A & 8) &&
                !(lbl_1_bss_716C8[1].unk_2A & 4)) present |= 1;
        } else {
            if (!(lbl_1_bss_716C8[1].unk_2A & 4)) present |= 1;
        }
    }
    return present;
}

s32 fn_1_C24A4(void) {
    static const u32 color_608[1] = {0xFFFFFFFF};
    static const u32 color_60C[1] = {0x0000FF00};
    static const u32 color_610[1] = {0x00FFFF00};
    static const u32 color_614[1] = {0x0000FF00};
    static const u32 color_618[1] = {0x00FFFF00};
    static const u32 color_61C[1] = {0x0000FF00};
    static const u32 color_620[1] = {0x00FFFF00};
    static const u32 color_624[1] = {0x0000FF00};
    static const u32 color_628[1] = {0x00FFFF00};
    static const u32 color_62C[1] = {0x000000FF};
    static const u32 color_630[1] = {0x000000FF};
    static const u32 color_634[1] = {0x000000FF};
    static const u32 color_638[1] = {0x000000FF};
    static const u32 color_63C[1] = {0xFFFF00FF};
    f32 v2;
    u32 v3;
    u32 v4;
    struct { char text[256]; } loc_F4;
    struct fn_1_C24A4_Copy88 packet;
    struct fn_1_C24A4_Request request;
    OSCalendarTime loc_50;
    struct { char text[32]; } date;

    s32 present;
    s32 y;
    f32 width;
    f32 x;

    if (lbl_1_bss_7ABCC != 0) return 0;
    if (lbl_1_bss_7ABC4 != 0) {
        fn_1_4AEC0(1);
        fn_1_4AEB4(1.5f);
        fn_1_4D0A0();
        fn_1_49410();
        if ((s32)lbl_801A66B4 != 5) {
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
        }
        fn_1_495FC();
        fn_1_4966C(0.0f, 8.0f);
        v2 = 0.7f;
        fn_1_4955C(v2, v2);
        fn_1_4954C(0.02f);
        fn_1_495C8(9);
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4AE0C(STR(0x978));
        {
        struct fn_1_C24A4_Color loc_2C;
        loc_2C = *(const struct fn_1_C24A4_Color *)color_608;
        fn_1_4D2AC(&loc_2C, 0.0201f, 40.0f);
        }
        fn_1_4AEC0(0);
        fn_1_4AEB4(0.0f);
        if (lbl_1_bss_716C8[0].unk_1 != -3 && ((lbl_1_bss_9F8.unk_8 >> 8) & 1)) {
            lbl_1_bss_7ABC4 = 0;
        } else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
            lbl_1_bss_7ABC4 = 0;
            lbl_1_bss_718B4 = -125;
            lbl_1_bss_7ABCC = 1;
            return 0;
        }
        return 1;
    }
    if (lbl_1_bss_716C8[0].unk_1 == -3) {
        if (!fn_1_F7904()) return 0;
        if (lbl_1_bss_7730A == -1) {
            present = 0;
        } else if (lbl_1_bss_716C8[lbl_1_bss_7730A].unk_50 == 0) {
            present = 0;
        } else {
            present = 1;
        }
        if (!present) return 0;
        if (lbl_1_bss_718B4 == -123) {
            lbl_1_bss_7ABC4 = 0;
            return 0;
        }
        lbl_1_bss_7ABC4 = 1;
        return 1;
    }
    if (lbl_1_bss_7ABBC == 0) {
        if (fn_1_F7954()) {
            v3 = lbl_1_bss_718C0;
            v4 = v3 + 4;
            fn_80008BA8((void *)v4, (void *)((u32)&lbl_1_bss_8B3A0.unk_9F), 4);
            fn_80008BA8((void *)(v4 + 4), (void *)((u32)&lbl_1_bss_8B3A0.unk_8C), 6);
            fn_80008BA8((void *)(v4 + 10), (void *)((u32)((u8 *)&lbl_1_bss_8B3A0 + 0xC)), 128);
            strncpy((void *)loc_F4.text, (void *)lbl_1_bss_716C8[lbl_1_bss_7730A].unk_54, 32);
            OSTicksToCalendarTime(OSGetTime(), &loc_50);
            sprintf(date.text, (const char *)"%02d/%02d/%02d ",
                loc_50.year % 100, loc_50.mon + 1, loc_50.mday);
            strncpy((void *)loc_F4.text, (void *)date.text, 8);
            memset(&request, 0, 0x24);
            request.flags = 4;
            request.type = 1;
            request.flags |= 0x2000;
            request.data = lbl_1_bss_718E0;
            request.name = &loc_F4;
            fn_1_AA6D8(0, 0, (void *)&request);
        }
        lbl_1_bss_7ABBC = 1;
        return 1;
    }
    present = card_writable();
    if (!present) {
        lbl_1_bss_7ABC8 = 3;
        return 0;
    }
    if (lbl_1_bss_716C8[0].unk_4 == 5 || lbl_1_bss_716C8[1].unk_4 == 5) {
        lbl_1_bss_7ABC8 = 3;
        return 0;
    }
    if (lbl_1_bss_7ABC8 != 0) {
        lbl_1_bss_7ABC8--;
        return 0;
    }
    if (lbl_1_bss_960 == 9) y = 360;
    else if (lbl_1_bss_960 == 5) y = 380;
    else y = 420;
    fn_1_520A0();
    fn_1_52070(560);
    v2 = (lbl_801A66C8 % 40) / 40.0f;
    packet = lbl_1_rodata_26F8;
    PW(0) = 1;
    PF(4) = 580.0f;
    PF(8) = y;
    PF(0x10) = 1.0f;
    PF(0x14) = 1.0f;
    PF(0xC) = 0.05f;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    {
    struct fn_1_C24A4_Color color1;
    struct fn_1_C24A4_Color color2;
    PW(0) = 10;
    PF(4) = 565.0f;
    PF(8) = (y + 20);
    PF(0x10) = 0.7f;
    PF(0x14) = 0.5f;
    color1 = *(const struct fn_1_C24A4_Color *)color_60C;
    color1.r = (127.0f * v2);
    color1.g = (127.0f * v2);
    color2 = *(const struct fn_1_C24A4_Color *)color_610;
    color2.r = (127.0f * v2);
    PW(0x38) = *(u32 *)&color1;
    PW(0x3C) = *(u32 *)&color2;
    PCB = fn_1_52270;
    PF(0xC) = 0.05f;
    fn_1_4F734((FontDrawPacket *)&packet);
    }
    v2 += 0.2;
    if (v2 > 1.0f) v2 -= 1.0f;

    packet = lbl_1_rodata_26F8;
    {
    struct fn_1_C24A4_Color color3;
    struct fn_1_C24A4_Color color4;
    PW(0) = 9;
    PF(4) = 555.0f;
    PF(8) = (y + 20);
    PF(0x10) = 0.4f;
    PF(0x14) = 0.5f;
    color3 = *(const struct fn_1_C24A4_Color *)color_614;
    color3.r = (127.0f * v2);
    color3.g = (127.0f * v2);
    color4 = *(const struct fn_1_C24A4_Color *)color_618;
    color4.r = (127.0f * v2);
    PW(0x38) = *(u32 *)&color3;
    PW(0x3C) = *(u32 *)&color4;
    PCB = fn_1_52270;
    PF(0x2C) = 0.8f;
    PF(0xC) = 0.05f;
    fn_1_4F734((FontDrawPacket *)&packet);
    }
    v2 += 0.2;
    if (v2 > 1.0f) v2 -= 1.0f;

    packet = lbl_1_rodata_26F8;
    {
    struct fn_1_C24A4_Color color5;
    struct fn_1_C24A4_Color color6;
    PW(0) = 9;
    PF(4) = 545.0f;
    PF(8) = (y + 20);
    PF(0x10) = 0.4f;
    PF(0x14) = 0.5f;
    color5 = *(const struct fn_1_C24A4_Color *)color_61C;
    color5.r = (127.0f * v2);
    color5.g = (127.0f * v2);
    color6 = *(const struct fn_1_C24A4_Color *)color_620;
    color6.r = (127.0f * v2);
    PW(0x38) = *(u32 *)&color5;
    PW(0x3C) = *(u32 *)&color6;
    PCB = fn_1_52270;
    PF(0x2C) = 0.5f;
    PF(0xC) = 0.05f;
    fn_1_4F734((FontDrawPacket *)&packet);
    }
    v2 += 0.2;
    if (v2 > 1.0f) v2 -= 1.0f;

    packet = lbl_1_rodata_26F8;
    {
    struct fn_1_C24A4_Color color7;
    struct fn_1_C24A4_Color color8;
    PW(0) = 9;
    PF(4) = 535.0f;
    PF(8) = (y + 20);
    PF(0x10) = 0.4f;
    PF(0x14) = 0.5f;
    color7 = *(const struct fn_1_C24A4_Color *)color_624;
    color7.r = (127.0f * v2);
    color7.g = (127.0f * v2);
    color8 = *(const struct fn_1_C24A4_Color *)color_628;
    color8.r = (127.0f * v2);
    PW(0x38) = *(u32 *)&color7;
    PW(0x3C) = *(u32 *)&color8;
    PCB = fn_1_52270;
    PF(0x2C) = 0.2f;
    PF(0xC) = 0.05f;
    fn_1_4F734((FontDrawPacket *)&packet);
    }

    if ((lbl_801A66C8 & 63) < 48) {
        fn_1_49410();
        if ((s32)lbl_801A66B4 != 5) {
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
        }
        fn_1_495C8(18);
        fn_1_496FC(577.0f, (y + 18));
        v2 = 0.7f;
        fn_1_4955C(v2, v2);
        fn_1_49738((void *)((u32)fn_1_5233C));
        fn_1_49748(5.0f);
        fn_1_4966C(-2.0f, 0.0f);
        if ((s32)lbl_801A66B4 != 5) fn_1_4966C(-1.0f, 0.0f);
        fn_1_4954C(0.05f);
        fn_1_4AE0C(STR(0x900));
    }
    packet = lbl_1_rodata_26F8;
    PW(0) = 18;
    PF(4) = 570.0f;
    PF(8) = (y + 18);
    PW(0x30) = 10;
    PW(0x38) = color_62C[0];
    PF(0x2C) = 0.5f;
    fn_1_50164(120.0f, 50.0f, 2.0f, 2.0f, &packet);

    packet = lbl_1_rodata_26F8;
    PW(0) = 5;
    PF(4) = 510.0f;
    PF(8) = (y + 18);
    PW(0x30) = 11;
    PW(0x38) = color_630[0];
    PF(0x10) *= 24.0f / fn_1_48690(5);
    PF(0x14) *= 50.0f / fn_1_486C4(PW(0));
    PF(0x2C) = 0.5f;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = lbl_1_rodata_26F8;
    PW(0) = 5;
    PF(4) = 654.0f;
    PF(8) = (y + 18);
    PW(0x30) = 9;
    PH(0x28) = (s16)-32768;
    PW(0x38) = color_634[0];
    PF(0x10) *= 24.0f / fn_1_48690(5);
    PF(0x14) *= 50.0f / fn_1_486C4(PW(0));
    PF(0x2C) = 0.5f;
    fn_1_4F734((FontDrawPacket *)&packet);
    fn_1_520CC();
    fn_1_520A0();
    fn_1_52070(320);

    packet = lbl_1_rodata_26F8;
    PW(0) = 18;
    PF(4) = 320.0f;
    PF(8) = (y + 18);
    PW(0x30) = 10;
    PW(0x38) = color_638[0];
    PF(0x2C) = 0.3f;
    fn_1_50164(1000.0f, 50.0f, 2.0f, 2.0f, &packet);
    fn_1_49410();
    if ((s32)lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
    }
    fn_1_495C8(8);
    v2 = 0.75f;
    fn_1_4955C(v2, v2);
    fn_1_4954C(0.11f);
    {
    struct fn_1_C24A4_Color color9;
    color9 = *(const struct fn_1_C24A4_Color *)color_63C;
    fn_1_49514((u32 *)&color9);
    }
    width = fn_1_4B068(STR(0x8E8));
    width += 30.0f;
    x = -width + (width - (lbl_801A66A0 % (u32)width));
    while (x < 640.0f) {
        fn_1_496FC(x, (y + 18));
        fn_1_4AE0C(((const char **)&lbl_1_data_3B74C)[lbl_801A66B4 + 0x23A]);
        x += width;
    }
    fn_1_520CC();
    return 0;
}
#undef lbl_1_bss_8B3A0
#undef lbl_1_bss_960
#undef lbl_1_bss_9F8
#undef lbl_1_rodata_26F8
#undef lbl_801A66B4
#undef REL_MAIN_REL_DRIVER_H
#undef REL_MAIN_REL_GLOBALS_H
#undef PCB
#undef PF
#undef PW
#undef PH
#undef STR
#undef lbl_1_bss_718C0
#undef lbl_1_bss_718E0
#undef lbl_1_bss_7ABBC
#undef lbl_1_bss_7ABCC
#undef lbl_1_data_3B74C
/* fzgx:end fn_1_C24A4 */

/* fzgx:begin fn_1_C3378 */
/* VIEWS */
#define lbl_1_bss_718C0 (*(Obj_1_bss_718C0 *)&lbl_1_bss_718C0)
#define lbl_1_bss_718E0 (*(Obj_1_bss_718E0 *)&lbl_1_bss_718E0)
#define lbl_1_bss_772C8 (*(u8 (*)[66])&lbl_1_bss_772C8)
/* the 0x20-byte entries of the block lbl_1_bss_718C0.unk_0 points to; unk_10 is s16 like the table copied into it */

// Sets the save block's defaults: clears it, then copies in the game's controller options, the button settings

// after fn_1_3B34 has put the stock ones back.

void fn_1_C3378(void) {
    static s16 lbl_1_data_3D11C[4] = {6, 2, 5, 4};
    Obj_1_bss_718C0_Entry *entry;
    u8 *bytes;
    s16 *src;
    s32 i;

    fn_80008BEC(&lbl_1_bss_718E0, 0, 0x59E0);
    lbl_1_bss_718C0.unk_0 = (Obj_1_bss_718C0_At0 *)((u8 *)&lbl_1_bss_718E0 + 0x55C2);
    /* retail stores halfwords at 0x0, 0x6, 0x1A0 and 0x5520 (sth), though symbols.txt types lbl_1_bss_718E0 as
     * byte data */
    lbl_1_bss_718E0.unk_1A0 = 0;
    lbl_1_bss_718E0.unk_5520 = 0;
    lbl_1_bss_718E0.unk_0 = 0;
    lbl_1_bss_718E0.unk_6 = 0;
    lbl_1_bss_718E0.unk_2 = 0xF;
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_718E0 + 0x8), (void *)lbl_1_data_2AC0, 0x40);
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_718E0 + 0x48), (void *)lbl_1_data_2B40, 0x8);
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_718E0 + 0x5542), (void *)&lbl_1_data_2B50, 0x8);
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_718E0 + 0x554A), (void *)&lbl_1_data_2B58, 0x8);
    lbl_1_bss_718E0.unk_3 = fn_1_A6F1C();
    fn_1_3B34();
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_718E0 + 0x50), (void *)lbl_1_bss_AA0, 0x150);
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_718E0 + 0x5556), (void *)&lbl_1_data_2B60, 0x4);

    bytes = &lbl_1_bss_718C0.unk_0->unk_4;
    for (i = 0; i < 4; i++) {
        bytes[i] = 50;
    }
    entry = (Obj_1_bss_718C0_Entry *)lbl_1_bss_718C0.unk_0;
    src = lbl_1_data_3D11C;
    for (i = 0; i < 4; i++, src++) {
        entry[i].unk_10 = *src;
        entry[i].unk_16 = 1;
    }
}
/* fzgx:end fn_1_C3378 */

/* fzgx:begin fn_1_C34F0 */
// Initializes the memory-card state and restores the persistent card data.

void fn_1_C34F0(void) {
    Obj_1_bss_718C0_At0 *card_buffer;
    u8 *serialized_data;

    fn_1_F755C(lbl_1_bss_718E0.unk_2);
    fn_80008BA8((void *)lbl_1_data_2AC0, (void *)((u8 *)&lbl_1_bss_718E0 + 0x8), 0x40);
    fn_80008BA8((void *)lbl_1_data_2B40, (void *)((u8 *)&lbl_1_bss_718E0 + 0x48), 0x8);
    fn_80008BA8((void *)&lbl_1_data_2B50, (void *)((u8 *)&lbl_1_bss_718E0 + 0x5542), 0x8);
    fn_80008BA8((void *)&lbl_1_data_2B58, (void *)((u8 *)&lbl_1_bss_718E0 + 0x554A), 0x8);
    fn_80008BA8((void *)lbl_1_bss_AA0, (void *)((u8 *)&lbl_1_bss_718E0 + 0x50), 0x150);
    fn_80008BA8((void *)&lbl_1_data_2B60, (void *)((u8 *)&lbl_1_bss_718E0 + 0x5556), 0x4);

    fn_1_A6840(lbl_1_bss_718E0.unk_3 <= 1 ? lbl_1_bss_718E0.unk_3 : 1);

    card_buffer = lbl_1_bss_718C0.unk_0;
    serialized_data = (u8 *)card_buffer + 0x4;
    fn_80008BA8((void *)&lbl_1_bss_8B3A0.unk_9F, (void *)serialized_data, 0x4);
    fn_80008BA8((void *)&lbl_1_bss_8B3A0.unk_8C, (void *)(serialized_data + 0x4), 0x6);
    fn_80008BA8((void *)((u8 *)&lbl_1_bss_8B3A0 + 0xC), (void *)(serialized_data + 0xA), 0x80);

    if ((u32)(serialized_data + 0x8A -
              ((u8 *)lbl_1_bss_718C0.unk_0 + 0x4)) != 0x8A) {
        OSPanic((void *)"memcard.c", 0x3532, (void *)"OKASII by tokieda\n");
    }
    fn_1_F79C8();
}
/* fzgx:end fn_1_C34F0 */

/* fzgx:begin fn_1_C3688 */
u32 fn_1_C3688(void) {
    TimeParts parts;
    u64 time;
    u32 result;

    time = OSGetTime();
    OSTicksToCalendarTime(time, (OSCalendarTime *)&parts);
    result = (parts.field_4 & 0x3F) + ((parts.field_8 & 0x1F) << 6);
    result += (parts.field_C & 0x1F) << 11;
    result += (parts.field_10 & 0x0F) << 16;
    result += ((parts.field_14 - 0x7D3) & 0x3F) << 20;
    return result;
}
/* fzgx:end fn_1_C3688 */

/* fzgx:begin fn_1_C36EC */
// Writes the in-memory card fields to the active serialized card buffer.

void fn_1_C36EC(void) {
    u8 *serialized_data = &lbl_1_bss_718C0.unk_0->unk_4;

    fn_80008BA8((void *)serialized_data, (void *)&lbl_1_bss_8B3A0.unk_9F, 4);
    fn_80008BA8((void *)(serialized_data + 4), (void *)&lbl_1_bss_8B3A0.unk_8C, 6);
    fn_80008BA8((void *)(serialized_data + 0xA), (void *)((u8 *)&lbl_1_bss_8B3A0 + 0xC), 0x80);

    if ((u32)(serialized_data + 0x8A -
              ((u8 *)lbl_1_bss_718C0.unk_0 + 4)) != 0x8A) {
        OSPanic((void *)"memcard.c", 0x3578, (void *)"OKASII by tokieda\n");
    }
}
/* fzgx:end fn_1_C36EC */

/* fzgx:begin fn_1_C37A0 */
// Unmount the memory card, repair its save-file names, and release its work area.

void fn_1_C37A0(void) {
    CARDFileInfo_L_C3378 fileInfo;
    char sp28[32];
    char sp8[32];
    s32 chan;
    u32 workArea;
    s32 res;

    if (lbl_1_bss_772C8[0] == 0) {
        return;
    }

    chan = lbl_1_bss_718B1;
    workArea = fn_1_4630(lbl_801A6410, 0xA000, "memcard.c", 0x3594);

    do {
        res = ((s32)CARDGetResultCode(chan));
    } while (res == -1);

    do {
        res = CARDUnmount(chan);
    } while (res == -1);

    do {
        res = ((int)fn_8002DFE0(chan, (void *)workArea, 0));
    } while (res == -1);

    if (res != 0) {
        if (workArea != 0) {
            fn_1_46B4((u32)lbl_801A6410, workArea, "memcard.c", 0x35ab);
        }
        lbl_1_bss_772C8[0] = 0;
        return;
    }

    strcpy(sp28, lbl_1_bss_772C8);
    strcat(sp28, ".000");

    do {
        res = CARDOpen(chan, (const char *)sp28, (CARDFileInfo *)&fileInfo);
    } while (res == -1);

    if (res != 0) {
        do {
            res = CARDUnmount(chan);
        } while (res == -1);

        if (workArea != 0) {
            fn_1_46B4((u32)lbl_801A6410, workArea, "memcard.c", 0x35c2);
        }
        lbl_1_bss_772C8[0] = 0;
        return;
    }

    strcpy(sp28, lbl_1_bss_772C8);
    strcat(sp28, ".dat");

    do {
        res = CARDOpen(chan, (const char *)sp28, (CARDFileInfo *)&fileInfo);
    } while (res == -1);

    if (res == 0) {
        strcpy(sp28, lbl_1_bss_772C8);
        strcat(sp28, ".000");

        while (fn_8002FC14(chan, sp28) == -1) {
        }
    } else if (res == -4) {
        strcpy(sp8, lbl_1_bss_772C8);
        strcat(sp8, ".000");

        while (fn_80030338(chan, sp8, sp28) == -1) {
        }
    }

    do {
        res = CARDUnmount(chan);
    } while (res == -1);

    if (workArea != 0) {
        fn_1_46B4((u32)lbl_801A6410, workArea, "memcard.c", 0x35ef);
    }
    lbl_1_bss_772C8[0] = 0;
}
#undef lbl_1_bss_718C0
#undef lbl_1_bss_718E0
#undef lbl_1_bss_772C8
/* fzgx:end fn_1_C37A0 */
