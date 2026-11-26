#include "types.h"
#define lbl_1_bss_6D820 globals_h_6D820
#define lbl_1_bss_6D838 globals_h_6D838
#include "rel/main_rel/globals.h"
#undef lbl_1_bss_6D820
#undef lbl_1_bss_6D838
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/vec3.h"
#include "psvec.h"
#include "lc_mtx.h"
#include "mathutil_mtxA_set_translate.h"
#include "mathutil_vec_cross_prod.h"
#include "fpscr_floorf.h"
#include "sofdec/sj.h"

/* fn_1_7EB8C */
typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

/* fn_1_7EB8C */
typedef struct CarModel {
    u8 pad_0[8];
    Vec3 center;
    f32 radius;
    u16 ntex;
} CarModel;

/* fn_1_7EB8C */
typedef struct CarModelEntry {
    u32 unk_0;
    char *name;
} CarModelEntry;

/* fn_1_7EB8C */
typedef struct CarModelInfo {
    s32 count;
    CarModel *model;
    CarModelEntry *entries;
} CarModelInfo;

/* fn_1_7EB8C */
typedef struct CarLod {
    CarModel **models;
    CarModelInfo *info;
    u32 unk_8;
} CarLod;

/* fn_1_7EB8C */
typedef struct CarTex {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
} CarTex;

/* fn_1_7EB8C */
typedef struct CarTexList {
    u32 count;
    CarTex *items;
} CarTexList;

/* fn_1_7EB8C */
typedef struct CarBody {
    u8 pad_0[4];
    s16 index;
    u16 unk_6;
    u8 pad_8[0x74];
    Vec3 pos;
    u8 pad_88[0xC4];
    f32 mtx[3][4];
    u8 pad_17C[8];
    f32 unk_184;
    u8 pad_188[0x498];
} CarBody;

/* fn_1_7EB8C */
typedef struct Car {
    u8 pad_0[2];
    s8 limit;
    u8 pad_3[0x325];
    s8 kind;
    u8 pad_329[3];
    CarBody *body;
    u8 *parts;
    CarLod lods[6];
    CarTexList *tex[4];
    u8 lod_mask;
    u8 pad_38D[0x2B];
    s16 cv;
    s16 lod;
    u8 pad_3BC[0x84];
} Car;

/* fn_1_7EB8C */
typedef struct CarTestLight {
    u8 *color;
    f32 distance;
    s16 rot_x;
    s16 rot_y;
} CarTestLight;

/* fn_1_7EB8C */
typedef struct CarTest {
    Car *cars;
    s8 sel;
    s8 channel;
    s8 mode;
    s8 car;
    s8 model;
    u8 pad_9[3];
    u32 *disp_masks;
    char **mode_names;
    char **mode_help;
    u8 *bg_color;
    CarTestLight *lights;
    u32 flags;
    s8 lod;
    u8 lod_level[5];
} CarTest;

/* fn_1_7EB8C */
typedef struct Line3 {
    Vec3 a;
    Vec3 b;
} Line3;

/* fn_1_7EB8C */
typedef struct PadInput {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} PadInput;

/* fn_1_7EB8C */
typedef struct GXLightObj {
    u32 dummy[16];
} GXLightObj;

/* fn_1_7EB8C */
typedef struct BgState {
    u8 pad_0[0x8];
    struct {
        u8 pad_0[0x20];
        void *unk_20;
    } *unk_8;
} BgState;

/* fn_1_7EB8C */
typedef struct lbl_1_bss_6D620_t {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u32 unk_10;
    u8 pad_14[0x124];
} lbl_1_bss_6D620_t;

/* fn_1_7EB8C */
typedef struct lbl_1_bss_6D7F4_t {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    u8 pad_10[0x1c];
} lbl_1_bss_6D7F4_t;

/* fn_1_7EB8C */
typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    s32 unk_10;
    s32 unk_14;
} Entry7E9C4;

/* fn_1_7EB8C */
typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
} Cur7E9C4;

/* fn_1_7EB8C */
typedef struct {
    s8 unk_0;
} SignedByteView;

/* fn_1_7EB8C */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
} LocalBytes;

/* fn_1_7EB8C */
typedef struct {
    void *f_0;
    void *f_4;
} ListEntry;

/* fn_1_7EB8C */
typedef struct {
    u32 f_0;
    u32 f_4;
    void *f_8;
} MidEntry;

/* fn_1_7EB8C */
typedef struct {
    u32 f_0;
    u32 f_4;
    u32 f_8;
} SubEntry;

/* fn_1_7EB8C */
typedef struct {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x67];
    u32 unk_390;
    u8 pad_394[0x10];
    ListEntry *unk_3A4;
    u8 pad_3A8[0x12];
    s16 unk_3BA;
} Object;

/* fn_1_7EB8C */
struct fn_1_7ECB8_lbl_1_rodata_3508 {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x4];
    f64 unk_18;
    u8 pad_20[0x8];
    f32 unk_28;
    u8 pad_2C[0x4];
    f64 unk_30;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    u8 pad_5C[0x4];
    f64 unk_60;
    f32 unk_68;
    u8 pad_6C[0x4];
    f64 unk_70;
    f64 unk_78;
};

/* fn_1_7EB8C */
typedef struct {
    u8 pad[0x208];
    struct { u32 vector[3]; u8 pad[8]; } transforms[2];
} PositionView;

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

/* fn_1_7F3AC */
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

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x24];
    void *field_24;
} EventData;

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

/* fn_1_7F3AC */
struct fn_1_7F954_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_7F3AC */
struct fn_1_7FA04_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x40];
    void *value;
} ResourceHolder;

/* fn_1_7F3AC */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RawVec3;

/* fn_1_7F3AC */
typedef struct {
    u8 _pad_000[0x7c];
    Vec3 field_07c;
    u8 _pad_088[0xc4];
    Vec3 field_14c;
} Fn184644Object;

/* fn_1_7F3AC */
typedef struct Fn195158Object Fn195158Object;

/* fn_1_7F3AC */
struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_7F3AC */
struct TargetObj {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_7F3AC */
struct ModelItem {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_7F3AC */
struct Model {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem items[1];
};

/* fn_1_7F3AC */
typedef struct {
    u32 entries[41];
} FnTable;

/* fn_1_7F3AC */
typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Fn1_8F45C_Object;

/* fn_1_7F3AC */
typedef struct {
    s32 active;
    s32 entries[5];
} Fn1_8F494_Object;

/* fn_1_7F3AC */
typedef struct {
    u8 pad_0[0x148];
    u8 pad_148[0x20];
    u8 pad_168[0x40];
    u8 pad_1a8[0x20];
    u8 pad_1c8[0x20];
    u8 pad_1e8[0x20];
    u8 entries[0x14][0x20];
} Fn1_8F5A4_Object;

/* fn_1_7F3AC */
typedef struct Fn195158Data Fn195158Data;

/* fn_1_7F3AC */
struct Fn195158Data {
    u8 unk_00[0x08];
    Fn195158Object *unk_08;
};

/* fn_1_7F3AC */
typedef struct Fn195158Car Fn195158Car;

/* fn_1_7F3AC */
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

/* fn_1_7F3AC */
typedef struct Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Fn935E4Slot;

/* fn_1_7F3AC */
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

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Node;

/* fn_1_7F3AC */
typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x24];
    void *field_24;
    f32 field_28;
    f32 field_2c;
} OutData;

/* fn_1_7F3AC */
typedef struct {
    u8 pad0[0x1c];
    Node *field_1c;
    u8 pad20[0x128];
    u16 field_148;
    u8 pad14a[6];
    OutData *field_150;
    void *field_154;
} Owner;

/* fn_1_7F3AC */
typedef struct Fn1967A8Resource Fn1967A8Resource;

/* fn_1_7F3AC */
struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_7F3AC */
typedef struct Fn196968Object Fn196968Object;

/* fn_1_7F3AC */
struct Fn196968Object {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_7F3AC */
typedef struct Fn1969E8Owner Fn1969E8Owner;

/* fn_1_7F3AC */
struct Fn1969E8Owner {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_7F3AC */
typedef struct Fn196BC0Object Fn196BC0Object;

/* fn_1_7F3AC */
struct Fn196BC0Object {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_7F3AC */
typedef struct Fn196A68Object Fn196A68Object;

/* fn_1_7F3AC */
struct Fn196A68Object {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_7F3AC */
typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

/* fn_1_7F3AC */
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

/* fn_1_7F3AC */
typedef s32 (*fn_1_8D210_callback)(u32);

/* fn_1_7F3AC */
typedef struct {
    u8 pad[0x15];
    u8 code;
} State;

/* fn_1_7F3AC */
typedef struct {
    u8 pad[4];
    State *state;
} fn_1_8E3A4_Object;

/* fn_1_7F3AC */
typedef struct Sig_fn_1_41418_Fn41418Data {
    u32 count;
    char *strings;
} Sig_fn_1_41418_Fn41418Data;

/* fn_1_7F3AC */
typedef struct {
    u32 w[45];
} Unk_23800000;

/* fn_1_7F3AC */
typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Sig_fn_1_55628_Fn1_55628Object;

/* fn_1_7F3AC */
typedef struct fn_1_8D988_CarObject { u8 pad_0[0x40]; void *unk_40; } fn_1_8D988_CarObject;

/* fn_1_7F3AC */
typedef struct fn_1_8D988_Car {
    u32 unk_0; s16 unk_4; u8 pad_6[0x46e]; s8 unk_474; u8 pad_475[0xf];
    fn_1_8D988_CarObject *unk_484; u8 pad_488[0x86]; u8 unk_50e; u8 pad_50f[0x111];
} fn_1_8D988_Car;

/* fn_1_7F3AC */
struct Sig_fn_800713E0_fn_800713E0_Entry {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_7F3AC */
struct Sig_fn_800713E0_fn_800713E0_Arg0 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry **entries;
};

/* fn_1_7F3AC */
typedef struct Sig_fn_1_97174_Fn197174Owner Sig_fn_1_97174_Fn197174Owner;

/* fn_1_7F3AC */
struct Sig_fn_1_97174_Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_7F3AC */
typedef struct fn_1_95238_lbl_801A6D00 {
    u32 unk_0;
} fn_1_95238_lbl_801A6D00;

/* fn_1_7F3AC */
typedef struct {
    u8 **unk_00;
    void *unk_04;
    u32 pad_08;
} Fn1_87448_Slot;

/* fn_1_7F3AC */
typedef struct {
    u8 pad_00[0x330];
    u32 unk_330;
    Fn1_87448_Slot unk_334[1];
} Fn1_87448_Obj;

/* fn_1_7F3AC */
typedef struct {
    u8 pad_00[2];
    s8 unk_02;
} Fn1_87448_Arg1;

/* fn_1_7F3AC */
typedef struct CarFn_1_7F3AC {
    u8 pad_390[0x390];
    u32 field_390;
    u8 pad_394[0x10];
    u32 field_3A4;
} CarFn_1_7F3AC;

/* fn_1_7F3AC */
typedef struct {
    u32 data[40][6];
    u8 tail[24];
} fn_1_7F49C_CarData;

/* fn_1_7F58C */
typedef struct {
    u8 pad_0[0x14c];
    Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

/* fn_1_7F58C */
typedef struct {
    u8 pad_0[0x8];
    Vec3 dir;
    f32 radius;
} Fn183D28Target;

/* fn_1_7F58C */
typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

/* fn_1_7F58C */
typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

/* fn_1_7F58C */
typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

/* fn_1_7F58C */
typedef struct {
    u8 pad_0[0x320];
    s16 index;
    u8 pad_322[0xa];
    Fn183D28Body *body;
    Fn183D28Entry entries[6];
    u8 pad_378[0x18];
    u32 flags;
    u8 pad_394[0xc];
    Fn183D28Alt *alt;
} Fn183D28Car;

/* fn_1_7F58C */
typedef struct {
    u32 flags;
    u8 pad_4[0x5];
    u8 count;
    u8 pad_A[0x14AE];
    f64 pad_14B8;
} CarTestInfo;

/* fn_1_7F58C */
typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

/* fn_1_7F658 */
struct fn_1_7F658_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_7F658 */
typedef struct {
    s32 a : 25;
    s32 b : 1;
    s32 c : 6;
} Sig_fn_1_7F658_FlagBits;

/* fn_1_7F658 */
typedef struct {
    u8 pad_340[0x340];
    void *field_340;
} Sig_fn_1_7F658_Item;

/* fn_1_7F658 */
typedef struct {
    u8 pad_380[0x380];
    u32 unk_380;
} Sig_fn_1_7F658_Sub;

/* fn_1_7F658 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    void *unk_8;
} Sig_fn_1_7F658_E34;

/* fn_1_7F658 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    void *unk_8;
    u8 pad_C[0x320];
    u32 unk_32C;
    u32 unk_330;
    Sig_fn_1_7F658_E34 unk_334[5];
    u8 pad_370[0xC];
    u32 unk_37C[4];
    u8 pad_38C[4];
    u32 unk_390;
    u32 unk_394;
    u8 pad_398[8];
    Sig_fn_1_7F658_Item *unk_3A0;
    u32 unk_3A4;
    u8 pad_3A8[0x18];
    u32 unk_3C0[8];
    u32 unk_3E0[8];
    u32 unk_400[5];
    u32 unk_414[5];
} Sig_fn_1_7F658_Car;

/* fn_1_7FAA8 */
typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_45730_LoadEntry;

/* fn_1_7FAA8 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    Sig_fn_1_45730_LoadEntry entry;
} Sig_fn_1_45730_LoadResult;

/* fn_1_7FAA8 */
typedef struct {
    u8 unk_0[2];
    s16 id;
    u32 mask4;
    u8 mask8;
    u8 pad_9[3];
    u32 flagsC;
    u8 pad_10[0x10];
} CarListEntry;

/* fn_1_7FD7C */
typedef struct {
    s16 unk_00;
    s16 unk_02;
    u32 unk_04;
    u8 unk_08;
    u32 unk_0C;
} Fn7FD7CArg;

/* fn_1_7FD7C */
typedef struct {
    char *unk_00;
} TblRow;

/* key -> texture slot pairs, 0xFFFF ends the list (fn_800712E4) */
typedef struct CarTexRemap {
    u16 key;
    u16 value;
} CarTexRemap;

typedef struct CarTexRemapTable {
    CarTexRemap entries[58];
} CarTexRemapTable;

/* fn_1_7FD7C */
typedef struct {
    u32 words[58];
} InitData;

/* fn_1_80294 */
typedef struct Fn80294Entry {
    s16 unk_0;
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[0x3];
    u32 unk_C;
    s16 unk_10[3];
    u8 pad_16[0x2];
    u32 unk_18;
} Fn80294Entry;

/* fn_1_80294 */
typedef struct Fn80294Item {
    u32 unk_0;
    u32 unk_4;
} Fn80294Item;

/* fn_1_80294 */
typedef struct Fn80294Model {
    s32 unk_0;
    u8 pad_4[0x4];
    Fn80294Item *unk_8;
} Fn80294Model;

/* fn_1_80294 */
typedef struct Fn80294Part {
    u8 pad_0[0x340];
    void *unk_340;
    void *unk_344[6];
    u8 pad_35C[0x4];
} Fn80294Part;

/* fn_1_80294 */
typedef struct Fn80294Slot {
    u32 *unk_0;
    Fn80294Model *unk_4;
    s16 unk_8;
    u8 pad_A[0x2];
} Fn80294Slot;

/* fn_1_80294 */
typedef struct Fn80294Car {
    u8 pad_0[0x2];
    s8 unk_2;
    u8 pad_3[0x31D];
    s16 unk_320;
    u8 pad_322[0x6];
    u8 unk_328;
    u8 pad_329[0x7];
    void *unk_330;
    Fn80294Slot unk_334[6];
    void *unk_37C[4];
    u8 unk_38C;
    u8 pad_38D[0x3];
    u32 unk_390;
    u8 pad_394[0xC];
    Fn80294Part *unk_3A0;
    u8 pad_3A4[0x4];
    u32 unk_3A8;
    f32 unk_3AC;
    u32 unk_3B0;
    f32 unk_3B4;
    s16 unk_3B8;
    u8 pad_3BA[0x2];
    s32 unk_3BC;
    u32 unk_3C0[8];
    u32 unk_3E0[8];
    u32 unk_400[5];
    u32 unk_414[5];
} Fn80294Car;

/* fn_1_80294 */
typedef struct Fn80294Table {
    u16 unk_0[116];
} Fn80294Table;

/* fn_1_80CC4 */
typedef struct {
    u16 unk_0;
    s16 unk_2;
    s32 unk_4;
    u8 unk_8;
    u8 pad_9[0x17];
} Fn80CC4Info;

/* fn_1_81164 */
typedef struct Fn81164Model {
    u8 pad_0[0x8];
    u32 unk_8;
} Fn81164Model;

/* fn_1_81164 */
typedef struct Fn81164Car {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x37C - 0x329];
    Fn81164Model *unk_37C[4];
    u32 unk_38C;
    u32 unk_390;
    u8 pad_394[0x3A8 - 0x394];
    u32 unk_3A8;
    u8 pad_3AC[0x3B8 - 0x3AC];
    s16 unk_3B8;
} Fn81164Car;

/* fn_1_81808 */
typedef struct {
    u8 pad0[2];
    s16 id;
    u8 pad4[8];
    u32 flags;
} fn_1_81860_Obj;

/* fn_1_81808 */
typedef struct {
    u8 pad0[0x320];
    s16 value;
} fn_1_818AC_Obj;

/* fn_1_818BC */
typedef struct {
    u16 unk_0;
    s16 unk_2;
    s32 unk_4;
    u8 unk_8;
    u8 pad_9[0x3];
    u32 unk_C;
    u8 pad_10[0x10];
} Entry818BC;

/* fn_1_818BC */
typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    s8 unk_328;
    u8 pad_329[0x37C - 0x329];
    Fn81164Model *unk_37C[4];
    u32 unk_38C;
    u32 unk_390;
    u8 pad_394[0x3A0 - 0x394];
    u8 *unk_3A0;
    u8 pad_3A4[0x4];
    u32 unk_3A8;
    u8 pad_3AC[0x3B8 - 0x3AC];
    s16 unk_3B8;
    u8 pad_3BA[0x440 - 0x3BA];
} Car818BC;

/* fn_1_82724 */
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;  // 1 loads, 0 stores
} Obj_1_bss_8B3A0_AtA4_L;

/* fn_1_82724 */
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

/* fn_1_82724 */
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    u8 pad_4[0x1];
    u8 unk_5;  // 1 loads, 0 stores
    u8 pad_6[0x1];
    u8 unk_7;  // 1 loads, 0 stores
    u8 pad_8[0xF0];
    u8 unk_F8;  // 2 loads, 0 stores
    u8 pad_F9[0x98];
    u8 unk_191;  // 2 loads, 0 stores
    u8 unk_192;  // 2 loads, 0 stores
    u8 pad_193[0x5];
} Obj_1_bss_525C;

/* fn_1_82724 */
typedef struct CarInitInput {
    u8 pad0[0xc];
    u32 flags;
    u8 pad10[0x10];
} CarInitInput;

/* fn_1_82724 */
typedef struct CarRuntime {
    u8 pad0[0x474];
    s8 driver;
    u8 pad475[0x1ab];
} CarRuntime;

/* fn_1_82724 */
typedef struct CarInitObject {
    u8 pad0[0x324];
    s32 sentinel;
    u8 pad328[4];
    CarRuntime *runtime;
    u8 pad330[0x60];
    u32 flags;
    u8 pad394[0xc];
    u8 *special;
    u8 pad3a4[0x9c];
} CarInitObject;

/* fn_1_82724 */
typedef struct CarShadow {
    u8 pad[0x4c];
} CarShadow;

/* fn_1_82724 */
typedef struct CarInitEvent {
    u8 pad0[0xc];
    s16 kind;
    u8 pade[0xa];
    s16 index;
    u8 pad1a[0x1e];
    CarRuntime *runtime;
    u8 pad3c[0xac];
} CarInitEvent;

/* fn_1_82C70 */
typedef struct {
    u8 pad_0[0x474];
    s8 unk_474;
} Fn1_82C70_Racer;

/* fn_1_82C70 */
typedef struct {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x3];
    Fn1_82C70_Racer *unk_32C;
    u8 pad_330[0x74];
    void *unk_3A4;
    u8 pad_3A8[0x12];
    s16 unk_3BA;
} Fn1_82C70_Car;

/* fn_1_82C70 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x1];
    u8 unk_5;
    u8 pad_6[0x1];
    u8 unk_7;
    u8 pad_8[0x8198];
    u8 unk_81A0;
} Fn1_82C70_Record;

/* fn_1_82C70 */
typedef struct {
    Fn1_82C70_Car *unk_0;
    u8 unk_4;
    u8 pad_5[0x3];
    f32 unk_8;
    u32 unk_C;
    u8 pad_10[0x10410];
    u32 unk_10420;
    s32 (*unk_10424)(void **);
    void (*unk_10428)(void *, void *, f32);
    void (*unk_1042C)(void *, void *);
    u8 pad_10430[0x10];
} Fn1_82C70_Work;

/* fn_1_82C70 */
typedef struct {
    Fn1_82C70_Record *unk_0;
    u8 pad_4[0x4];
} Fn1_82C70_RecordSlot;

/* fn_1_82C70 */
typedef struct {
    Fn1_82C70_RecordSlot unk_0[0x1F];
    u8 unk_F8;
    u8 pad_F9[0x9F];
} Fn1_82C70_Obj_525C;

/* fn_1_83070 */
typedef struct F83070Desc {
    u32 words[45];
} F83070Desc;

/* fn_1_83070 */
typedef struct F83070Car {
    u32 flags;
    s16 index;
    s16 type;
    u8 pad008[0x34];
    char name[32];
    u8 pad05C[0x418];
    s8 player;
    s8 player2;
    u8 pad476[0xE];
    void *ai;
    void *part[4];
    void *unk498;
    void *unk49C;
    u8 pad4A0[0x6E];
    u8 unk50E;
    u8 pad50F[0x111];
} F83070Car;

/* fn_1_83070 */
typedef struct F83070Setup {
    s16 unk0;
    s16 type;
    u8 pad004[0x1C];
} F83070Setup;

/* fn_1_83858 */
typedef struct Sig_fn_1_C6ED4_Fn1C6ED4Data {
    u32 flags;
    f32 value_4;
    f32 value_8;
    f32 value_c;
    f32 value_10;
    f32 value_14;
} Sig_fn_1_C6ED4_Fn1C6ED4Data;

/* fn_1_83858 */
typedef struct Sig_fn_1_C6ED4_Fn1C6ED4Enemy {
    u32 flags;
    u8 pad_4[0x1f0];
    f32 output_1f4;
    f32 output_1f8;
    f32 output_1fc;
    f32 output_200;
    f32 output_204;
    u8 pad_208[0x27c];
    Sig_fn_1_C6ED4_Fn1C6ED4Data *data;
} Sig_fn_1_C6ED4_Fn1C6ED4Enemy;

/* fn_1_83858 */
typedef struct {
    u8 _pad_00[0x7c];
    f32 field_7c;
    f32 field_80;
    f32 field_84;
    u8 _pad_88[0x64];
    u8 field_ec[0x3b4];
    u8 field_4a0[0x10];
} Sig_fn_1_83CB0_Fn183CB0Object;

/* fn_1_83858 */
typedef u32 (*fn_1_83858_Fn0)(u32);

/* fn_1_83858 */
struct fn_1_83858_lbl_1_bss_A88_0_E6 {
    u8 unk_0;
    u8 pad_1[0x5];
};

/* fn_1_83858 */
struct fn_1_83858_Arg0 {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x1EE];
    f32 accel;
    f32 brake;
    f32 steer;
    f32 pitch;
    f32 side;
    u8 pad_208[0x26C];
    char port;
    u8 pad_475[0xC];
    u8 unk_481;
    u8 pad_482[0x10A];
    u32 unk_58C;
    u8 unk_590;
    u8 pad_591[0x7F];
    f32 unk_610;
    s8 unk_614;
};

/* fn_1_83858 */
struct fn_1_83858_lbl_1_rodata_3508 {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x54C];
    f64 unk_560;
    u8 pad_568[0x18];
    f64 unk_580;
    f32 unk_588;
};

/* fn_1_83858 */
struct fn_1_83858_lbl_1_bss_6D820 {
    u8 unk_0;
    u8 pad_1[0x2F];
    u32 unk_30;
    u8 pad_34[0x124];
    u32 unk_158;
};

/* fn_1_83858 */
struct fn_1_83858_lbl_1_bss_9F8 {
    u8 pad_0[0x1C];
    u16 unk_1C;
};

/* fn_1_83858 */
struct fn_1_83858_lbl_1_bss_CC0 {
    u8 unk_0[1];
};

/* fn_1_83858 */
struct fn_1_83858_lbl_1_bss_A88 {
    struct fn_1_83858_lbl_1_bss_A88_0_E6 unk_0[1];
};

/* fn_1_83858 */
struct fn_1_83858_lbl_1_bss_D70 {
    u8 unk_0[1];
};

/* fn_1_83858 */
typedef struct lbl_1_bss_6D820_t {
    u8 unk_0;
    u8 pad_1[0x3];
} lbl_1_bss_6D820_t;

/* fn_1_83858 */
typedef struct lbl_1_bss_6D8F4_t {
    u8 fzgx_byte_D4;
    u8 pad_1[0x7b];
} lbl_1_bss_6D8F4_t;

/* fn_1_83CB0 */
typedef struct {
    u8 pad[0x200];
    f32 value;
} ProjectionObject;

/* fn_1_83CB0 */
typedef struct {
    u8 pad[8];
    struct { f32 x, y, z; } vector;
    f32 radius;
} DistanceObject;

/* fn_1_83CB0 */
typedef struct {
    u8 pad[0x320];
    s16 index;
    u8 pad322[0xA];
    ProjectionObject *projection;
    struct {
        s16 threshold;
        u8 pad[2];
        DistanceObject **object;
        u8 pad8[4];
    } levels[6];
    u8 pad378[0x18];
    u32 flags;
    u8 pad394[0xC];
    struct {
        u8 pad[0x344];
        struct {
            u8 pad[8];
            DistanceObject **object;
        } *levels[6];
    } *other;
} DistanceState;

/* fn_1_84038 */
typedef struct {
    u8 _pad_32c[0x32c];
    void *field_32c;
    u8 _pad_330[0x70];
    void *field_3a0;
} Fn184038Object;

/* fn_1_84038 */
typedef struct {
    u8 _pad[8];
    f32 value;
} Fn184038Result;

/* fn_1_84038 */
typedef struct {
    u8 _pad[0x344];
    void *field_344;
} Fn184038TableEntry;

/* fn_1_84038 */
typedef struct {
    u8 _pad[0x38c];
    u8 flags;
} Fn184124Object;

/* fn_1_84038 */
struct fn_1_8421C_Arg0 {
    u8 pad_0[0x320];
    s16 unk_320;
    u8 pad_322[0x6A];
    u8 unk_38C;
};

/* fn_1_84038 */
typedef struct {
    u8 _pad[0x32c];
    void *field_32c;
} Fn1843BCObject;

/* fn_1_84644 */
typedef struct {
    u8 _pad[0x6];
    s16 field_6;
} Fn18472CObject;

/* fn_1_84860 */
typedef struct {
    u8 pad_0[0x8];
    f32 dir[3];
    f32 radius;
} BurnerTarget;

/* fn_1_84860 */
typedef struct {
    u8 pad_0[0x8];
    BurnerTarget **target;
} BurnerSlot;

/* fn_1_84860 */
typedef struct {
    u8 pad_0[0x344];
    BurnerSlot *slots[1];
} BurnerAlt;

/* fn_1_84860 */
typedef struct {
    s16 limit;
    s16 pad_2;
    BurnerTarget **target;
    u8 pad_8[4];
} BurnerEntry;

/* fn_1_84860 */
typedef struct {
    u32 flags;
    s16 id;
    s16 kind;
    u8 pad_8[0x7c - 0x8];
    u8 unk_7c[0x14c - 0x7c];
    f32 pos[3];
} BurnerBody;

/* fn_1_84860 */
typedef struct {
    u8 pad_0[0x320];
    s16 index;
    u8 pad_322[0x6];
    s8 unk_328;
    u8 pad_329[0x3];
    BurnerBody *body;
    BurnerEntry entries[6];
    u8 pad_378[0x14];
    u8 unk_38c;
    u8 pad_38d[0x3];
    u32 flags;
    u8 pad_394[0xc];
    BurnerAlt *alt;
    u8 pad_3a4[0x14];
    s16 unk_3b8;
    s16 slot;
} BurnerCar;

/* fn_1_84860 */
typedef struct {
    u8 pad_0[0x18];
    GXColor color;
} BurnerColorDef;

/* fn_1_84860 */
typedef struct {
    s32 count;
    u8 pad_4[0x4];
    void **items;
} BurnerList;

/* fn_1_84860 */
typedef struct {
    u8 data[0x81c0];
} BurnerBig;

/* fn_1_850C4 */
typedef struct CarInfo850C4 {
u8 pad0[0x115];
u8 rank;
u8 pad116[0x2];
s32 lap;
} CarInfo850C4;

/* fn_1_850C4 */
typedef struct Car850C4 {
u32 flags;
s16 id;
u8 pad6[0x76];
Vec3 pos;
u8 pad88[0x64];
Vec3 vecEC;
u8 padF8[0x8c];
f32 f184;
u8 pad188[0x314];
CarInfo850C4 *info;
u8 pad4A0[0xec];
u32 flags58C;
u8 pad590[0x90];
} Car850C4;

/* fn_1_850C4, fn_1_8B9B8: the race state (defined with fn_1_8B9B8) */
typedef struct Race8B9B8 Race8B9B8;

/* fn_1_850C4 */
typedef struct Owner850C4 {
u8 pad1C0[0x390];
u32 flags;
} Owner850C4;

/* fn_1_850C4 */
typedef struct State850C4 {
u8 pad0[0x18];
Car850C4 *cars;
u8 pad1C[0xe];
s8 count;
u8 pad2B[0x125];
void (*carHook)(Car850C4 *);
void (*racerHook)(Race8B9B8 *);
s32 f158;
s32 f15C;
} State850C4;

/* fn_1_854D4 */
typedef struct DS {
    u8 pad0[0xe18];
    char str[0x66c];
    s8 a[4];
    s8 b[4];
    s8 c[4];
} DS;

/* fn_1_854D4 */
typedef struct Car_854D4 {
    u8 pad0[0x484];
    u32 p484;
    u32 p488[4];
    u32 p498;
    u32 p49c;
    u8 pad2[0x620 - 0x4a0];
} Car_854D4;

/* fn_1_854D4 */
typedef struct BS {
    u8 pad0[0x18];
    Car_854D4 *cars;
    u8 pad1[0x2a - 0x1c];
    s8 count;
    u8 pad2[0x14c - 0x2b];
    u8 flag;
} BS;

/* fn_1_85688 */
struct fn_1_7F954_lbl_801A6410_fn_1_85688 {
    u32 unk_0;
};

/* fn_1_85688 */
struct fn_1_7FA04_lbl_801A6410_fn_1_85688 {
    u32 unk_0;
};

/* fn_1_85688 */
typedef struct Fn195158Object_fn_1_85688 Fn195158Object_fn_1_85688;

/* fn_1_85688 */
struct Fn195158Object_fn_1_85688 {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_85688 */
struct TargetObj_fn_1_85688 {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_85688 */
struct ModelItem_fn_1_85688 {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_85688 */
struct Model_fn_1_85688 {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem_fn_1_85688 items[1];
};

/* fn_1_85688 */
typedef struct Fn195158Data_fn_1_85688 Fn195158Data_fn_1_85688;

/* fn_1_85688 */
struct Fn195158Data_fn_1_85688 {
    u8 unk_00[0x08];
    Fn195158Object_fn_1_85688 *unk_08;
};

/* fn_1_85688 */
typedef struct Fn195158Car_fn_1_85688 Fn195158Car_fn_1_85688;

/* fn_1_85688 */
struct Fn195158Car_fn_1_85688 {
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
    Fn195158Data_fn_1_85688 *unk_150;
};

/* fn_1_85688 */
typedef struct Fn1967A8Resource_fn_1_85688 Fn1967A8Resource_fn_1_85688;

/* fn_1_85688 */
struct Fn1967A8Resource_fn_1_85688 {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_85688 */
typedef struct Fn196968Object_fn_1_85688 Fn196968Object_fn_1_85688;

/* fn_1_85688 */
struct Fn196968Object_fn_1_85688 {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_85688 */
typedef struct Fn1969E8Owner_fn_1_85688 Fn1969E8Owner_fn_1_85688;

/* fn_1_85688 */
struct Fn1969E8Owner_fn_1_85688 {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_85688 */
typedef struct Fn196BC0Object_fn_1_85688 Fn196BC0Object_fn_1_85688;

/* fn_1_85688 */
struct Fn196BC0Object_fn_1_85688 {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_85688 */
typedef struct Fn196A68Object_fn_1_85688 Fn196A68Object_fn_1_85688;

/* fn_1_85688 */
struct Fn196A68Object_fn_1_85688 {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_85688 */
struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_85688 {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_85688 */
struct Sig_fn_800713E0_fn_800713E0_Arg0_fn_1_85688 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_85688 **entries;
};

/* fn_1_85688 */
typedef struct Sig_fn_1_97174_Fn197174Owner_fn_1_85688 Sig_fn_1_97174_Fn197174Owner_fn_1_85688;

/* fn_1_85688 */
struct Sig_fn_1_97174_Fn197174Owner_fn_1_85688 {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_85688 */
typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x118];
} Fn85688Car;

/* fn_1_85688 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0xC];
    Fn85688Car *unk_1C;
    u32 unk_20;
    u32 unk_24;
    u16 unk_28;
    s8 unk_2A;
    u8 pad_2B[0xD];
    s32 unk_38;
    Fn80294Item unk_3C;
} Fn85688State;

/* fn_1_85688 */
typedef struct {
    u8 pad_0[0xA7];
    u8 unk_A7;
    u8 pad_A8[0x3A];
    u8 unk_E2[0xA0];
} Fn858A8Data;

/* fn_1_85934 */
typedef struct {
    u8 pad_0[0x390];
    u32 unk_390;
    u8 pad_394[0xAC];
} Fn85934Record;

/* fn_1_85934 */
typedef struct {
    u8 pad[0x468];
    f32 value;
} Fn14F04Result;

/* fn_1_85F70 */
typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11c;
    u8 pad_120[0x20];
    u32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14c;
    f32 unk_150;
} FzgxChild;

/* fn_1_8623C */
typedef struct {
    u8 pad_0[0x49C];
    u32 value;
    u8 pad_4A0[0x180];
} CarEntry_8627C;

/* fn_1_8623C */
struct fn_1_862A8_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

/* fn_1_864FC */
typedef struct {
    u8 pad_0[0x58c];
    u32 value;
    u8 pad_590[0x90];
} Fn864FCEntry;

/* fn_1_866B4 */
struct fn_1_866B4_entry {
    u8 pad_0[4];
    s16 unk_4;
    u8 pad_6[0x46E];
    s8 unk_474;
};

/* fn_1_866B4 */
struct fn_1_866B4_car {
    u8 pad_0[0x32C];
    struct fn_1_866B4_entry *unk_32C;
    u8 pad_330[0x110];
};

/* fn_1_866B4 */
struct fn_1_866B4_state {
    u8 pad_0[0x1C];
    struct fn_1_866B4_car *unk_1C;
    u8 pad_20[0xA];
    s8 unk_2A;
    u8 pad_2B[0x1D];
    u8 unk_48[1];
};

/* fn_1_8677C */
struct fn_1_867CC_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

/* fn_1_86854 */
typedef struct {
    u8 pad_0[0x328];
    u8 id;
    u8 pad_329[0x117];
} fn_1_86854_Entry;

/* fn_1_86900 */
struct fn_1_7F954_lbl_801A6410_fn_1_86900 {
    u32 unk_0;
};

/* fn_1_86900 */
struct fn_1_7FA04_lbl_801A6410_fn_1_86900 {
    u32 unk_0;
};

/* fn_1_86900 */
typedef struct Fn195158Object_fn_1_86900 Fn195158Object_fn_1_86900;

/* fn_1_86900 */
struct Fn195158Object_fn_1_86900 {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_86900 */
struct TargetObj_fn_1_86900 {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_86900 */
struct ModelItem_fn_1_86900 {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_86900 */
struct Model_fn_1_86900 {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem_fn_1_86900 items[1];
};

/* fn_1_86900 */
typedef struct Fn195158Data_fn_1_86900 Fn195158Data_fn_1_86900;

/* fn_1_86900 */
struct Fn195158Data_fn_1_86900 {
    u8 unk_00[0x08];
    Fn195158Object_fn_1_86900 *unk_08;
};

/* fn_1_86900 */
typedef struct Fn195158Car_fn_1_86900 Fn195158Car_fn_1_86900;

/* fn_1_86900 */
struct Fn195158Car_fn_1_86900 {
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
    Fn195158Data_fn_1_86900 *unk_150;
};

/* fn_1_86900 */
typedef struct Fn1967A8Resource_fn_1_86900 Fn1967A8Resource_fn_1_86900;

/* fn_1_86900 */
struct Fn1967A8Resource_fn_1_86900 {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_86900 */
typedef struct Fn196968Object_fn_1_86900 Fn196968Object_fn_1_86900;

/* fn_1_86900 */
struct Fn196968Object_fn_1_86900 {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_86900 */
typedef struct Fn1969E8Owner_fn_1_86900 Fn1969E8Owner_fn_1_86900;

/* fn_1_86900 */
struct Fn1969E8Owner_fn_1_86900 {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_86900 */
typedef struct Fn196BC0Object_fn_1_86900 Fn196BC0Object_fn_1_86900;

/* fn_1_86900 */
struct Fn196BC0Object_fn_1_86900 {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_86900 */
typedef struct Fn196A68Object_fn_1_86900 Fn196A68Object_fn_1_86900;

/* fn_1_86900 */
struct Fn196A68Object_fn_1_86900 {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_86900 */
struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_86900 {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_86900 */
struct Sig_fn_800713E0_fn_800713E0_Arg0_fn_1_86900 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_86900 **entries;
};

/* fn_1_86900 */
typedef struct Sig_fn_1_97174_Fn197174Owner_fn_1_86900 Sig_fn_1_97174_Fn197174Owner_fn_1_86900;

/* fn_1_86900 */
struct Sig_fn_1_97174_Fn197174Owner_fn_1_86900 {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_86900 */
typedef struct {
    u8 pad_0[0x1C];
    u8 *unk_1C;
    u8 pad_20[0xA];
    s8 unk_2A;
    u8 pad_2B[0x1D];
    u16 unk_48[1];
} Manager_1_86900;

/* fn_1_869B0 */
typedef struct {
    u8 pad_0[0x50];
    u32 value_50;
    u32 value_54;
    u32 value_58;
} Data_1_869B0;

/* fn_1_869B0 */
typedef struct {
    u8 pad_0[0x49c];
    Data_1_869B0 *data;
    u8 pad_4a0[0x180];
} Entry_1_869B0;

/* fn_1_869E0 */
typedef struct {
    u8 pad_0[0x5c];
    u32 value_5c;
    u32 value_60;
    u32 value_64;
} CarData;

/* fn_1_869E0 */
typedef struct {
    u8 pad_0[0x49c];
    CarData *unk_49c;
    u8 pad_4a0[0x180];
} Car_869E0;

/* fn_1_869E0 */
typedef struct {
    u32 value_0;
    u32 value_4;
    u32 value_8;
} Copy12;

/* fn_1_86A2C */
typedef struct lbl_1_bss_6D83C_t {
    u8 fzgx_u8_0;
    u8 pad_1[0xd];
} lbl_1_bss_6D83C_t;

/* fn_1_86A2C */
typedef struct fn_1_86A2C_Car {
    u32 flags;          /* 0x000 */
    s16 unk_4;          /* 0x004 */
    u8 pad_6[0x76];
    f32 pos[3];         /* 0x07C */
    u8 pad_88[0x64];
    u8 mtx[0x30];       /* 0x0EC */
    u8 pad_11C[0xF8];
    u16 timer;          /* 0x214 */
    u8 pad_216[0x25F];
    u8 idx;             /* 0x475 */
} fn_1_86A2C_Car;

/* fn_1_86E08 */
typedef struct fn_1_86E08_Car {
    u32 flags;
    s16 id;
    u8 pad_6[0x184 - 0x6];
    f32 speed;
    u8 pad_188[0x4AC - 0x188];
    f32 unk_4AC;
} fn_1_86E08_Car;

/* fn_1_86E08 */
typedef struct fn_1_86E08_Machine {
    u8 pad_0[0x390];
    u32 flags;
    u8 pad_394[0x440 - 0x394];
} fn_1_86E08_Machine;

/* fn_1_86E08 */
typedef struct fn_1_86E08_State {
    u8 pad_0[0x1C];
    fn_1_86E08_Machine *machines;
    u8 pad_20[0xA];
    s8 count;
    u8 pad_2B[0xD4 - 0x2B];
    s32 timer[4];
} fn_1_86E08_State;

/* fn_1_870BC */
typedef struct { u8 b[0xE8]; } Blob870BC;

/* fn_1_870BC */
typedef struct {
    u8 pad0[0x328];
    s8 f328;
    u8 pad1[0x338 - 0x329];
    struct { u32 a, b, c; } slot[2];
    u8 pad2[0x37c - 0x350];
    u32 tab[4];
    u8 pad3[0x390 - 0x38c];
    u32 flags;
    u8 pad4[0x3a0 - 0x394];
    u32 f3a0;
    u8 pad5[0x3b8 - 0x3a4];
    s16 f3b8;
    s16 f3ba;
} Car870BC;

/* fn_1_87238 */
struct CarSlot {
    struct Model **model_ptr;
    char pad[8];
};

/* fn_1_87238 */
struct fn_1_87238_Car {
    char pad[0x328];
    s8 field_0x328;
    char pad1[0xb];
    struct CarSlot slots[1];
    char pad2[0x50];
    u32 flags;
};

/* fn_1_87448 */
typedef struct {
    u32 unk_00;
    u8 *unk_04;
} Fn1_87448_Ent;

/* fn_1_87448 */
typedef struct {
    s32 unk_00;
    u32 pad_04;
    Fn1_87448_Ent *unk_08;
} Fn1_87448_Tab;

/* fn_1_875B4 */
typedef struct Fn187610Object {
    u8 pad_000[0x328];
    s8 field_328;
    u8 pad_329[7];
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187610Object;

/* fn_1_875B4 */
typedef struct Fn187610Data {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x205];
    u8 field_208[0x120];
} Fn187610Data;

/* fn_1_875B4 */
typedef struct Fn187750Inner {
    u32 flags;
    u8 pad_004[0xA0];
    f32 value_A4;
    u8 pad_0A8[0xE2];
    u8 unk_18A;
    u8 pad_18B[0x71];
    f32 value_1FC;
} Fn187750Inner;

/* fn_1_875B4 */
typedef struct Fn187750Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187750Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187750Object;

/* fn_1_892CC */
typedef struct { u32 a, b, c; } V3;

/* fn_1_892FC */
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    Vec3 unk_C;
    u8 pad_18[0xC];
    f32 unk_24;
    Vec3 unk_28;
    u8 pad_34[0xC];
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x5];
    s8 unk_4D;
    u8 pad_4E[0x2];
} Seg892FC;

/* fn_1_892FC */
typedef struct {
    s32 unk_0;
    Seg892FC *unk_4;
    u32 unk_8;
} Entry892FC;

/* fn_1_892FC */
typedef struct {
    u8 pad_0[0x118];
    s32 unk_118;
    s32 unk_11C;
    s32 unk_120[4];
    f32 unk_130[4];
    s32 unk_140;
    f32 unk_144;
    Vec3 unk_148;
    s32 unk_154;
    s32 unk_158;
} Prog892FC;

/* fn_1_892FC */
typedef struct {
    u8 pad_0[0x8];
    Vec3 unk_8;
    u8 pad_14[0x48];
} Corner892FC;

/* fn_1_892FC */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x240];
    Corner892FC unk_244[4];
    u8 pad_3B4[0xE8];
    Prog892FC *unk_49C;
} Car892FC;

/* fn_1_892FC */
typedef struct {
    u8 pad_0[0x1C];
    s32 unk_1C;
    u8 pad_20[0xEC];
    s32 unk_10C;
    s32 unk_110;
    f32 unk_114;
    u8 pad_118[0x2E8];
    u8 unk_400[1][0x80];
} Frame892FC;

/* fn_1_892FC */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 unk_D4;
} Cam892FC;

/* fn_1_8A1B4 */
typedef struct {
    u32 frames;
    f32 frac;
    u8 min;
    u8 sec;
    u16 ms;
} Time8A1B4;

/* fn_1_8A1B4 */
typedef struct {
    u8 pad_0[0x18];
    Vec3 unk_18;
    f32 unk_24;
    Vec3 unk_28;
    Vec3 unk_34;
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x8];
} Seg8A1B4;

/* fn_1_8A1B4 */
typedef struct {
    s32 unk_0;
    Seg8A1B4 *unk_4;
    u32 unk_8;
} Entry8A1B4;

/* fn_1_8A1B4 */
typedef struct {
    u8 pad_0[0x50];
    Vec3 unk_50;
    u8 pad_5C[0x24];
    s32 unk_80;
    u8 pad_84[0x4];
    s32 unk_88;
    s32 unk_8C;
    s32 *unk_90;
    f32 *unk_94;
    s32 unk_98;
    s32 unk_9C[4];
    Vec3 unk_AC;
    s32 unk_B8[4];
    f32 unk_C8[4];
    s32 unk_D8[4];
    f32 unk_E8[4];
    f32 unk_F8;
    f32 unk_FC;
    f32 unk_100;
    u8 pad_104[0x8];
    s32 unk_10C;
    s32 unk_110;
    s8 unk_114;
    u8 unk_115;
    u8 pad_116;
    u8 unk_117;
    s32 unk_118;
    s32 unk_11C;
    s32 unk_120[4];
    f32 unk_130[4];
    s32 unk_140;
    f32 unk_144;
    Vec3 unk_148;
    s32 unk_154;
    s32 unk_158;
    u32 unk_15C;
    Time8A1B4 unk_160[9];
    Time8A1B4 unk_1CC;
    Time8A1B4 unk_1D8;
    Time8A1B4 unk_1E4;
    Vec3 unk_1F0;
} Prog8A1B4;

/* fn_1_8A1B4 */
typedef struct {
    u32 flags;
    u8 pad_4[0x78];
    Vec3 pos;
    Vec3 unk_88;
    u8 pad_94[0x58];
    u8 unk_EC[0xDC];
    f32 unk_1C8;
    s32 unk_1CC;
    f32 unk_1D0;
    u8 pad_1D4[0x2C4];
    s32 unk_498;
    Prog8A1B4 *unk_49C;
    u8 pad_4A0[0xEC];
    u32 flags58C;
} Car8A1B4;

/* fn_1_8A1B4 */
typedef struct {
    u8 pad_0[0x1474];
    u32 unk_1474;
} Racer8A1B4;

/* fn_1_8B880 */
struct fn_1_7F954_lbl_801A6410_fn_1_8B8A4 {
    u32 unk_0;
};

/* fn_1_8B880 */
struct fn_1_7FA04_lbl_801A6410_fn_1_8B8A4 {
    u32 unk_0;
};

/* fn_1_8B880 */
typedef struct Fn195158Object_fn_1_8B8A4 Fn195158Object_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn195158Object_fn_1_8B8A4 {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_8B880 */
struct TargetObj_fn_1_8B8A4 {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_8B880 */
struct ModelItem_fn_1_8B8A4 {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_8B880 */
struct Model_fn_1_8B8A4 {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem_fn_1_8B8A4 items[1];
};

/* fn_1_8B880 */
typedef struct Fn195158Data_fn_1_8B8A4 Fn195158Data_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn195158Data_fn_1_8B8A4 {
    u8 unk_00[0x08];
    Fn195158Object_fn_1_8B8A4 *unk_08;
};

/* fn_1_8B880 */
typedef struct Fn195158Car_fn_1_8B8A4 Fn195158Car_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn195158Car_fn_1_8B8A4 {
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
    Fn195158Data_fn_1_8B8A4 *unk_150;
};

/* fn_1_8B880 */
typedef struct Fn1967A8Resource_fn_1_8B8A4 Fn1967A8Resource_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn1967A8Resource_fn_1_8B8A4 {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_8B880 */
typedef struct Fn196968Object_fn_1_8B8A4 Fn196968Object_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn196968Object_fn_1_8B8A4 {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_8B880 */
typedef struct Fn1969E8Owner_fn_1_8B8A4 Fn1969E8Owner_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn1969E8Owner_fn_1_8B8A4 {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_8B880 */
typedef struct Fn196BC0Object_fn_1_8B8A4 Fn196BC0Object_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn196BC0Object_fn_1_8B8A4 {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_8B880 */
typedef struct Fn196A68Object_fn_1_8B8A4 Fn196A68Object_fn_1_8B8A4;

/* fn_1_8B880 */
struct Fn196A68Object_fn_1_8B8A4 {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_8B880 */
struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_8B8A4 {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_8B880 */
struct Sig_fn_800713E0_fn_800713E0_Arg0_fn_1_8B8A4 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_8B8A4 **entries;
};

/* fn_1_8B880 */
typedef struct Sig_fn_1_97174_Fn197174Owner_fn_1_8B8A4 Sig_fn_1_97174_Fn197174Owner_fn_1_8B8A4;

/* fn_1_8B880 */
struct Sig_fn_1_97174_Fn197174Owner_fn_1_8B8A4 {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_8B880 */
typedef struct CarInfo {
    u8 pad_0[0x115];
    u8 unk_115;
} CarInfo;

/* fn_1_8B880 */
typedef struct CarObj {
    u8 pad_0[0x49C];
    CarInfo *info;
} CarObj;

/* fn_1_8B9B8 */
typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x4];
    f32 unk_3C;
    f32 unk_40;
    u8 pad_44[0x24];
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0xC];
    u32 unk_7C;
    u8 pad_80[0x4];
    f32 unk_84;
    u8 pad_88[0x70];
    f32 unk_F8;
    f32 unk_FC;
    f32 unk_100;
    s16 unk_104;
    u8 pad_106[0x2];
    f32 unk_108;
    u8 pad_10C[0x9];
    u8 unk_115;
    u8 pad_116[0xC2];
    u32 unk_1D8;
    f32 unk_1DC;
} Progress8B9B8;

/* fn_1_8B9B8 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x78];
    Vec3 pos;
    u8 pad_88[0x64];
    u8 unk_EC[0x3B0];
    Progress8B9B8 *unk_49C;
    u8 pad_4A0[0x180];
} Racer8B9B8;

/* fn_1_8B9B8, fn_1_850C4 */
struct Race8B9B8 {
    u32 flags;
    u8 lap;
    u8 pad_5[0x5];
    u8 unk_A;
    u8 unk_B;
    u8 pad_C[0x2];
    u8 unk_E[0x1E];
    Progress8B9B8 *unk_2C[30];
    u8 pad_A4[0x1361];
    u8 slotMask;
    u8 pad_1406[0x2];
    Vec3 slots[5];
};

/* fn_1_8C40C */
typedef struct CarTarget CarTarget;

/* fn_1_8C40C */
typedef struct fn_1_8C40C_CarEntry fn_1_8C40C_CarEntry;

/* fn_1_8C40C */
typedef struct CarTable CarTable;

/* fn_1_8C40C */
struct CarTarget {
    u8 unk_00[0xf8];
    f32 unk_f8;
};

/* fn_1_8C40C */
struct fn_1_8C40C_CarEntry {
    u8 unk_00[0x49c];
    CarTarget *unk_49c;
    u8 unk_4a0[0x180];
};

/* fn_1_8C40C */
struct CarTable {
    u8 unk_00[0x18];
    fn_1_8C40C_CarEntry *unk_18;
    u8 unk_1c[0xe];
    s8 unk_2a;
    u8 unk_2b[0x231];
    u8 unk_25c;
};

/* fn_1_8C40C */
typedef struct Fn1844CValue {
    char pad_0[0xf8];
    f32 value;
} Fn1844CValue;

/* fn_1_8C40C */
typedef struct Fn1844CEntry {
    char pad_0[0x49c];
    Fn1844CValue *value;
    char pad_end[0x180];
} Fn1844CEntry;

/* fn_1_8C40C */
typedef struct Fn1844CRoot {
    char pad_0[0x18];
    Fn1844CEntry *entries;
    char pad_0x1c[0xe];
    s8 threshold;
    char pad_0x2b[0x232];
    u8 index;
} Fn1844CRoot;

/* fn_1_8CA00 */
struct rodata_3508 {
f32 f[4];
u8 pad_10[0x654];
f64 unk_668;
u8 pad_670[0x178];
f64 unk_7E8;
};

/* fn_1_8CB78 */
typedef struct {
    u32 count;
    u8 *data;
} EntryTable;

/* fn_1_8CB78 */
typedef struct {
    u8 pad0[4];
    u32 pointer;
    u16 value8;
    u16 valueA;
} fn_1_8CB78_Entry;

/* fn_1_8CC04 */
typedef struct Sig_fn_80036070_Fn80036070Data Sig_fn_80036070_Fn80036070Data;

/* fn_1_8CC04 */
typedef struct CarDbgEntry {
    u32 flags;
    u16 id;
    u8 pad_06[2];
    Sig_fn_80036070_Fn80036070Data *data;
    u8 pad_0C[0x14];
} CarDbgEntry;

/* fn_1_8CC04 */
typedef struct CarDbgObj {
    u8 pad_00[0x18];
    u16 count;
    u8 pad_1A[0x26];
    CarDbgEntry entries[1];
} CarDbgObj;

/* fn_1_8CC04 */
typedef struct CarDbgRect {
    f32 z;
    f32 x1;
    f32 y1;
    f32 x0;
    f32 y0;
    u32 flag;
    u32 value;
    u8 pad_1C[0x34];
} CarDbgRect;

/* fn_1_8CC04 */
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
} Fn1_8CED0State;

/* fn_1_8CC04 */
typedef struct {
    u8 pad_00[0x2c];
    u16 width;
    u16 height;
    u8 pad_30[4];
    u32 arg34;
    u8 pad_38[0x28];
    u32 result;
} Fn1_8D0A4State;

/* fn_1_8CC04 */
typedef struct Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Fn1_8D168State;

/* fn_1_8D210 */
typedef struct Fn1_8D3F8Car {
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
} Fn1_8D3F8Car;

/* fn_1_8D210 */
typedef struct {
    u32 data[41];
} Table;

/* fn_1_8D210 */
typedef struct {
    s16 values[41];
} Fn1_8D640Table;

/* fn_1_8D72C */
typedef struct {
    u32 w[41];
} Table164;

/* fn_1_8D7C8 */
typedef struct {
    u32 values[41];
} Fn1_8D7C8Data;

/* fn_1_8D988 */
typedef struct CarManager {
    u8 pad_0[0x18]; fn_1_8D988_Car *cars; u8 pad_1c[0xe]; s8 count; u8 pad_2b[0x1d];
    s8 values[4]; fn_1_8D988_CarObject *objects[16];
} CarManager;

/* fn_1_8DAB4 */
typedef struct {
    u8 pad0[0x18];
    void *objects;
    u8 pad1[0x2c];
    u8 pending[4];
    s32 handles[4];
} GlobalState;

/* fn_1_8DAB4 */
typedef struct {
    u8 pad0[0x474];
    u8 active;
    u8 pad1[0x0f];
    ResourceHolder *resource_holder;
} fn_1_8DAB4_Object;

/* fn_1_8DAB4 */
typedef struct {
    u8 pad_0[0x9];
    u8 unk_9;
    u8 pad_A[0x14AE];
} fn_1_8DBB0_Setup;

/* fn_1_8DAB4 */
typedef struct {
    u8 pad_0[0x32C];
    u8 *unk_32C;
    u8 pad_330[0x5C];
    u8 unk_38C;
    u8 pad_38D[0x2D];
    s16 unk_3BA;
    u8 pad_3BC[0x84];
} fn_1_8DBB0_Car;

/* fn_1_8DAB4 */
typedef struct {
    u8 pad_0[0x1C];
    fn_1_8DBB0_Car *unk_1C;
    u8 pad_20[0xA];
    u8 unk_2A;
    u8 pad_2B[0x1ED];
    u8 unk_218;
    u8 pad_219[0xDF3];
    s16 unk_100C[30][5];
} fn_1_8DBB0_Manager;

/* fn_1_8DD54 */
typedef struct {
f32 unk_0;
u8 pad_4[0xC];
} Obj_1_data_1FFE0;

/* fn_1_8DD54 */
typedef struct {
u8 pad_0[0x18];
u32 unk_18;
CarTestCar *cars;
u8 pad_20[0xA];
u8 car_count;
u8 pad_2B[0x9];
u8 unk_34;
u8 pad_35[0x12B];
u8 flags[0xEAC];
u16 costs[0x20][5];
} CarTestManager;

/* fn_1_8E084 */
struct fn_1_7F954_lbl_801A6410_np_fn_1_8E084 {
    u32 unk_0;
};

/* fn_1_8E084 */
struct fn_1_7FA04_lbl_801A6410_np_fn_1_8E084 {
    u32 unk_0;
};

/* fn_1_8E084 */
typedef struct Fn195158Object_np_fn_1_8E084 Fn195158Object_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn195158Object_np_fn_1_8E084 {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_8E084 */
struct TargetObj_np_fn_1_8E084 {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_8E084 */
struct ModelItem_np_fn_1_8E084 {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_8E084 */
struct Model_np_fn_1_8E084 {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem_np_fn_1_8E084 items[1];
};

/* fn_1_8E084 */
typedef struct Fn195158Data_np_fn_1_8E084 Fn195158Data_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn195158Data_np_fn_1_8E084 {
    u8 unk_00[0x08];
    Fn195158Object_np_fn_1_8E084 *unk_08;
};

/* fn_1_8E084 */
typedef struct Fn195158Car_np_fn_1_8E084 Fn195158Car_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn195158Car_np_fn_1_8E084 {
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
    Fn195158Data_np_fn_1_8E084 *unk_150;
};

/* fn_1_8E084 */
typedef struct Fn1967A8Resource_np_fn_1_8E084 Fn1967A8Resource_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn1967A8Resource_np_fn_1_8E084 {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_8E084 */
typedef struct Fn196968Object_np_fn_1_8E084 Fn196968Object_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn196968Object_np_fn_1_8E084 {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_8E084 */
typedef struct Fn1969E8Owner_np_fn_1_8E084 Fn1969E8Owner_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn1969E8Owner_np_fn_1_8E084 {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_8E084 */
typedef struct Fn196BC0Object_np_fn_1_8E084 Fn196BC0Object_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn196BC0Object_np_fn_1_8E084 {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_8E084 */
typedef struct Fn196A68Object_np_fn_1_8E084 Fn196A68Object_np_fn_1_8E084;

/* fn_1_8E084 */
struct Fn196A68Object_np_fn_1_8E084 {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_8E084 */
typedef struct {
    u8 pad_0[0x400];
    u8 mtx[0x70];
    u8 mtx2[0x30];
} CamObj;

/* fn_1_8E084 */
typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11C;
    u8 pad_120[0x20];
    s32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14C;
    f32 unk_150;
} CarSound;

/* fn_1_8E084 */
typedef struct {
    u32 flags;
    u8 pad_4[0x498];
    CarSound *sound;
} fn_1_85F90_Car;

/* fn_1_8E084 */
typedef struct {
    u8 pad0[0x38c];
    u8 slot_mask;      // 0x38c: bit per usable slot
    u8 pad38d[0x2d];
    s16 slot;          // 0x3ba: current slot, -1 when none
} SlotCar;

/* fn_1_8E084 */
typedef struct {
    void *ptr;
    s32 pad_4;
} Elem;

/* fn_1_8E084 */
typedef struct {
    s32 count;
    s32 pad_4;
    Elem *items;
} CarList;

/* fn_1_8E084 */
typedef struct {
    u8 pad[0x3bc];
    u32 value;
} GlobalObject;

/* fn_1_8E4A4 */
struct fn_1_7F954_lbl_801A6410_fn_1_8E4A4 {
    u32 unk_0;
};

/* fn_1_8E4A4 */
struct fn_1_7FA04_lbl_801A6410_fn_1_8E4A4 {
    u32 unk_0;
};

/* fn_1_8E4A4 */
typedef struct Fn195158Object_fn_1_8E4A4 Fn195158Object_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn195158Object_fn_1_8E4A4 {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_8E4A4 */
struct TargetObj_fn_1_8E4A4 {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_8E4A4 */
struct ModelItem_fn_1_8E4A4 {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_8E4A4 */
struct Model_fn_1_8E4A4 {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem_fn_1_8E4A4 items[1];
};

/* fn_1_8E4A4 */
typedef struct Fn195158Data_fn_1_8E4A4 Fn195158Data_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn195158Data_fn_1_8E4A4 {
    u8 unk_00[0x08];
    Fn195158Object_fn_1_8E4A4 *unk_08;
};

/* fn_1_8E4A4 */
typedef struct Fn195158Car_fn_1_8E4A4 Fn195158Car_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn195158Car_fn_1_8E4A4 {
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
    Fn195158Data_fn_1_8E4A4 *unk_150;
};

/* fn_1_8E4A4 */
typedef struct Fn1967A8Resource_fn_1_8E4A4 Fn1967A8Resource_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn1967A8Resource_fn_1_8E4A4 {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_8E4A4 */
typedef struct Fn196968Object_fn_1_8E4A4 Fn196968Object_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn196968Object_fn_1_8E4A4 {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_8E4A4 */
typedef struct Fn1969E8Owner_fn_1_8E4A4 Fn1969E8Owner_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn1969E8Owner_fn_1_8E4A4 {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_8E4A4 */
typedef struct Fn196BC0Object_fn_1_8E4A4 Fn196BC0Object_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn196BC0Object_fn_1_8E4A4 {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_8E4A4 */
typedef struct Fn196A68Object_fn_1_8E4A4 Fn196A68Object_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Fn196A68Object_fn_1_8E4A4 {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_8E4A4 */
struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_8E4A4 {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_8E4A4 */
struct Sig_fn_800713E0_fn_800713E0_Arg0_fn_1_8E4A4 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_8E4A4 **entries;
};

/* fn_1_8E4A4 */
typedef struct Sig_fn_1_97174_Fn197174Owner_fn_1_8E4A4 Sig_fn_1_97174_Fn197174Owner_fn_1_8E4A4;

/* fn_1_8E4A4 */
struct Sig_fn_1_97174_Fn197174Owner_fn_1_8E4A4 {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_8E4A4 */
typedef struct {
    u16 id;
    u16 index;
    char *name;
    u32 pad;
} PartEntry;

/* fn_1_8E4A4 */
struct Unk_1_8E728 {
    u8 pad_0[0x98];
    u8 field_98;
    u8 pad_1[0x3];
    s32 field_9c;
    u8 pad_2[0x44];
    u32 field_e4[5];
    u32 field_f8[5][4];
};

/* fn_1_8E7D0 */
typedef struct Fn8E7D0Part {
    u8 pad_0[0x8];
    void *unk_8;
    void *unk_C;
    u8 pad_10[0x10];
} Fn8E7D0Part;

/* fn_1_8E7D0 */
typedef struct Fn8E7D0Car {
    s32 unk_0;
    s32 unk_4[5];
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x5C];
    u32 unk_88;
    s32 unk_8C;
    s32 unk_90;
    u32 unk_94;
    u8 unk_98;
    u8 pad_99[0x3];
    u32 unk_9C;
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 pad_A6[0x2];
    Vec3 unk_A8;
    f32 unk_B4;
    f32 unk_B8;
    u32 unk_BC[5];
    u32 unk_D0[5];
    u32 unk_E4[5];
    u32 unk_F8[5][4];
    Fn8E7D0Part unk_148;
    Fn8E7D0Part unk_168;
    Fn8E7D0Part unk_188;
    Fn8E7D0Part unk_1A8;
    Fn8E7D0Part unk_1C8;
    Fn8E7D0Part unk_1E8;
    Fn8E7D0Part unk_208[20];
    u8 unk_488[0x30];
    u32 unk_4B8;
    u32 unk_4BC;
    u32 unk_4C0;
    u8 unk_4C4;
} Fn8E7D0Car;

/* fn_1_8E7D0 */
typedef struct Fn8E7D0Rec {
    u16 unk_0;
    u16 unk_2;
    char *unk_4;
    u32 unk_8;
} Fn8E7D0Rec;

/* fn_1_8F198 */
typedef struct {
    u8 pad_0[0x4];
    s32 handles[5];
} Fn1_8F198_Object;

/* fn_1_8F62C */
typedef struct Fn8F62CModel {
    u8 pad_0[0x28];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x10];
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u8 pad_46[0x6];
    f32 unk_4C;
    f32 unk_50;
} Fn8F62CModel;

/* fn_1_8F62C */
typedef struct Fn8F62CResult {
    u16 unk_0;
    u16 unk_2;
    f32 unk_4;
    u16 unk_8;
    u16 unk_A;
} Fn8F62CResult;

/* fn_1_8F62C */
typedef struct Fn8F62CPart {
    u16 unk_0;
    u8 pad_2[0x6];
    Fn8F62CModel *unk_8;
    void *unk_C;
    Fn8F62CResult unk_10;
    s32 unk_1C;
} Fn8F62CPart;

/* fn_1_8F62C */
typedef struct Fn8F62CMotion {
    u8 pad_0[0x8];
    void *unk_8;
} Fn8F62CMotion;

/* fn_1_8F62C */
typedef struct Fn8F62CCar {
    u8 pad_0[0x18];
    u32 unk_18;
    Fn8F62CMotion *unk_1C;
    u8 pad_20[0x6C];
    s32 unk_8C;
    s32 unk_90;
    u8 pad_94[0xC];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 pad_A6[0x2];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    u8 pad_BC[0x8C];
    Fn8F62CPart unk_148;
    Fn8F62CPart unk_168;
    Fn8F62CPart unk_188;
    Fn8F62CPart unk_1A8;
    Fn8F62CPart unk_1C8;
    Fn8F62CPart unk_1E8;
    Fn8F62CPart unk_208[20];
    s8 unk_488;
    u8 pad_489[0xB];
    f32 unk_494;
    u8 pad_498[0x8];
    s32 unk_4A0;
    u8 pad_4A4[0x8];
    s32 unk_4AC;
    u8 pad_4B0[0x8];
    u32 unk_4B8;
    u8 pad_4BC[0x18];
    Vec3 unk_4D4;
} Fn8F62CCar;

/* fn_1_8FE74 */
typedef struct Fn8FE74Sub {
    u8 pad[0x4C];
    f32 unk_4C;
    f32 unk_50;
} Fn8FE74Sub;

/* fn_1_8FE74 */
typedef struct Fn8FE74Entry {
    u16 unk_0;
    u8 pad2[6];
    Fn8FE74Sub *unk_8;
    Sig_fn_1_41418_Fn41418Data *unk_C;
    u8 pad10[0x10];
} Fn8FE74Entry;

/* fn_1_8FE74 */
typedef struct Fn8FE74Obj {
    u8 pad[0x148];
    Fn8FE74Entry unk_148;
    Fn8FE74Entry unk_168;
    Fn8FE74Entry unk_188;
    Fn8FE74Entry unk_1A8;
    Fn8FE74Entry unk_1C8;
    Fn8FE74Entry unk_1E8;
    Fn8FE74Entry unk_208[20];
} Fn8FE74Obj;

/* fn_1_900C4 */
struct fn_1_900C4_lbl_1_bss_6E960 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
};

/* fn_1_900C4 */
struct fn_1_900C4_lbl_1_data_27920 {
    u32 unk_0;
};

/* fn_1_9012C */
typedef struct Fn9012CPart {
    u16 unk_0;
    u8 pad_2[0x6];
    void *unk_8;
    fn_1_95238_lbl_801A6D00 *unk_C;
    u8 pad_10[0xC];
    s32 unk_1C;
} Fn9012CPart;

/* fn_1_9012C */
typedef struct Fn9012CCar {
    s32 unk_0;
    s32 unk_4[5];
    u8 pad_18[0x4];
    void *unk_1C;
    u8 pad_20[0x68];
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x8];
    u8 unk_98;
    u8 pad_99[0x3];
    s32 unk_9C;
    u8 pad_A0[0x8];
    Vec3 unk_A8;
    u8 pad_B4[0x30];
    u32 unk_E4[5];
    u32 unk_F8[5][4];
    Fn9012CPart unk_148;
    Fn9012CPart unk_168;
    Fn9012CPart unk_188;
    Fn9012CPart unk_1A8;
    Fn9012CPart unk_1C8;
    Fn9012CPart unk_1E8;
    Fn9012CPart unk_208[20];
} Fn9012CCar;

/* fn_1_9012C */
typedef struct Fn9012CCamera {
    u8 pad_0[0x1C];
    f32 unk_1C;
} Fn9012CCamera;

/* fn_1_9012C */
typedef struct Fn9012CPad {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x4];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0x4];
} Fn9012CPad;

/* fn_1_9012C */
typedef struct Fn9012CFaceSet {
    char name[12];
    char *lip[5];
    struct Fn9012CFaceSet *self;
} Fn9012CFaceSet;

/* fn_1_913FC */
typedef struct {
    s32 unk_0;
} Fn1913FCResource;

/* fn_1_913FC */
typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    void *unk_8;
    Fn1913FCResource *unk_C;
    u8 pad_10[0x10];
} Fn1913FCSlot;

/* fn_1_913FC */
typedef struct {
    s32 unk_0;
    s32 unk_4[5];
    u8 pad_18[0x4];
    void *unk_1C;
    u8 pad_20[0x68];
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x8];
    u8 unk_98;
    u8 pad_99[0x3];
    u32 unk_9C;
    u8 pad_A0[0x8];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x30];
    void *unk_E4[5];
    void *unk_F8[5][4];
    Fn1913FCSlot unk_148[6];
    Fn1913FCSlot unk_208[20];
} Fn1913FCCar;

/* fn_1_913FC */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u16 unk_2[10];
    u8 pad_16[0x2];
    f32 unk_18[10];
    f32 unk_40[10];
    f32 unk_68;
    f32 unk_6C;
} EventList;

/* fn_1_913FC */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    f32 unk_4;
    u16 unk_8;
} Fn1913FCMotion;

/* fn_1_92554 */
typedef struct {
    u8 pad_0[0x8];
    u8 *unk_8;
    u8 pad_C[0x40];
    f32 unk_4C;
} Model92554;

/* fn_1_92554 */
typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    Model92554 *unk_8;
    void *unk_C;
    u8 pad_10[0x10];
} Slot92554;

/* fn_1_92554 */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    char *unk_4;
    u8 *unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    Vec3 unk_18;
} Part92554;

/* fn_1_92554 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0xC];
    u32 unk_10;
    u8 pad_14[0xC];
} Item92554;

/* fn_1_92554 */
typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    Vec3 unk_8;
    f32 unk_14;
    u16 unk_18;
    u8 pad_1A[0x4];
    u8 unk_1E;
    u8 pad_1F[0x21];
    Item92554 unk_40[1];
} Node92554;

/* fn_1_92554 */
typedef struct {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x6C];
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x10];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 pad_A6[0x2];
    Vec3 unk_A8;
    f32 unk_B4;
    f32 unk_B8;
    Part92554 *unk_BC[5];
    s32 unk_D0[5];
    void *unk_E4[5];
    u8 pad_F8[0x50];
    Slot92554 unk_148[6];
    Slot92554 unk_208[20];
    s8 unk_488;
    u8 pad_489[0x33];
    u32 unk_4BC[4];
} Car92554;

/* fn_1_934CC */
typedef struct Fn935E4Obj {
    u8 pad0[8];
    EventData *field_8;
    void *field_c;
} Fn935E4Obj;

/* fn_1_93734 */
typedef struct {
    u16 id;
    u8 pad2[6];
    EventData *data;
    void *strs;
    u8 pad10[0xc];
    s32 flag;
} Slot;

/* fn_1_93734 */
typedef struct {
    u8 pad0[0x1c];
    EventNode *node;
    u8 pad20[0x88 - 0x20];
    s32 field_88;
    u8 pad8c[0x148 - 0x8c];
    Slot slots[26];
} CarObject_93734;

/* fn_1_93734 */
typedef struct {
    u16 a;
    u16 b;
    u32 c;
    char *name;
} TblEntry;

/* fn_1_950E8 */
typedef struct Fn1950E8Data Fn1950E8Data;

/* fn_1_950E8 */
struct Fn1950E8Data {
    u16 id;
    u8 unk_02[0x0A];
    void *resource;
};

/* fn_1_95120 */
typedef struct Fn195120Data Fn195120Data;

/* fn_1_95120 */
typedef struct Fn195120Owner Fn195120Owner;

/* fn_1_95120 */
struct Fn195120Data {
    u8 unk_00[0x4C];
    f32 value_50;
    f32 value_4C;
};

/* fn_1_95120 */
struct Fn195120Owner {
    u8 unk_00[0x08];
    Fn195120Data *data;
};

/* fn_1_95158 */
typedef struct {
    u8 count;
    u8 field_1;
    u16 field_2;
    u8 pad04[0x3c];
    f32 field_40;
    u8 pad44[0x24];
    f32 field_68;
    f32 field_6c;
} EventList_95158;

/* fn_1_95158 */
typedef struct {
    u8 count;
    u8 current;
    u16 ids[9];
    f32 field_14[11];
    f32 field_40[10];
    f32 value;
} Config;

/* fn_1_95158 */
typedef struct Fn1956B8Data Fn1956B8Data;

/* fn_1_95158 */
struct Fn1956B8Data {
    u8 unk_00[0x68];
    f32 value;
    f32 limit;
};

/* fn_1_95158 */
struct fn_1_7F954_lbl_801A6410_fn_1_956EC {
    u32 unk_0;
};

/* fn_1_95158 */
struct fn_1_7FA04_lbl_801A6410_fn_1_956EC {
    u32 unk_0;
};

/* fn_1_95158 */
typedef struct Fn195158Object_fn_1_956EC Fn195158Object_fn_1_956EC;

/* fn_1_95158 */
struct Fn195158Object_fn_1_956EC {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_95158 */
struct TargetObj_fn_1_956EC {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_95158 */
struct ModelItem_fn_1_956EC {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_95158 */
struct Model_fn_1_956EC {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem_fn_1_956EC items[1];
};

/* fn_1_95158 */
typedef struct Fn195158Data_fn_1_956EC Fn195158Data_fn_1_956EC;

/* fn_1_95158 */
struct Fn195158Data_fn_1_956EC {
    u8 unk_00[0x08];
    Fn195158Object_fn_1_956EC *unk_08;
};

/* fn_1_95158 */
typedef struct Fn195158Car_fn_1_956EC Fn195158Car_fn_1_956EC;

/* fn_1_95158 */
struct Fn195158Car_fn_1_956EC {
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
    Fn195158Data_fn_1_956EC *unk_150;
};

/* fn_1_95158 */
typedef struct Fn1967A8Resource_fn_1_956EC Fn1967A8Resource_fn_1_956EC;

/* fn_1_95158 */
struct Fn1967A8Resource_fn_1_956EC {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_95158 */
typedef struct Fn196968Object_fn_1_956EC Fn196968Object_fn_1_956EC;

/* fn_1_95158 */
struct Fn196968Object_fn_1_956EC {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_95158 */
typedef struct Fn1969E8Owner_fn_1_956EC Fn1969E8Owner_fn_1_956EC;

/* fn_1_95158 */
struct Fn1969E8Owner_fn_1_956EC {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_95158 */
typedef struct Fn196BC0Object_fn_1_956EC Fn196BC0Object_fn_1_956EC;

/* fn_1_95158 */
struct Fn196BC0Object_fn_1_956EC {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_95158 */
typedef struct Fn196A68Object_fn_1_956EC Fn196A68Object_fn_1_956EC;

/* fn_1_95158 */
struct Fn196A68Object_fn_1_956EC {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_95158 */
struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_956EC {
    u8 pad_0[0x18];
    u16 count;
};

/* fn_1_95158 */
struct Sig_fn_800713E0_fn_800713E0_Arg0_fn_1_956EC {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry_fn_1_956EC **entries;
};

/* fn_1_95158 */
typedef struct Sig_fn_1_97174_Fn197174Owner_fn_1_956EC Sig_fn_1_97174_Fn197174Owner_fn_1_956EC;

/* fn_1_95158 */
struct Sig_fn_1_97174_Fn197174Owner_fn_1_956EC {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_95158 */
typedef struct {
    u16 id;
    u16 index;
    char *name;
    u32 unk8;
} CarNameEntry;

/* fn_1_95950 */
typedef struct Sig_fn_1_426AC_Fn1426ACObject {
    u16 count;
    u8 pad2[6];
    u8 *entries;
    u8 padC[0x30];
    void *value;
} Sig_fn_1_426AC_Fn1426ACObject;

/* fn_1_95950 */
struct fn_1_95950_lbl_1_data_209C0 {
    u8 pad_0[0x35c];
    u32 unk_35C[1];
    u8 pad_360[0x5954];
    u32 unk_5CB4[1];
    u8 pad_5CB8[0x1174];
    u32 unk_6E2C;
};

/* fn_1_95EF0 */
struct fn_1_95EF0_Arg0 {
    u8 pad_0[0x14C];
    u32 unk_14C;
};

/* fn_1_95EF0 */
struct fn_1_95EF0_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_9617C */
typedef struct CarResourceState CarResourceState;

/* fn_1_9617C */
struct CarResourceState {
    u8 unk_00[0x08];
    void *unk_08;
    void *unk_0C;
};

/* fn_1_961F0 */
typedef struct Fn1961F0Owner Fn1961F0Owner;

/* fn_1_961F0 */
struct Fn1961F0Owner {
    u8 unk_00[0x0C];
    void *resource;
};

/* fn_1_96230 */
typedef struct Fn196230Obj {
    u8 unk_00[0x4];
    s32 ids[5];
    u8 unk_18[0xE4 - 0x18];
    u32 handles[5];
    void *files[5][4];
} Fn196230Obj;

/* fn_1_96230 */
typedef struct Fn196230Data {
    u8 pad_0[0x35C];
    const char *names[(0x6ED8 - 0x35C) / 4];
    u8 lock_6ED8[8];
    char fmt_6EE0[0xC];
    u8 unlock_6EEC[0x7278 - 0x6EEC];
    char fmt_7278[0xC];
    char fmt_7284[4];
} Fn196230Data;

/* fn_1_96630 */
typedef struct Fn196630Object Fn196630Object;

/* fn_1_96630 */
struct Fn196630Object {
    u8 unk_00[0x88];
    void *value_88;
};

/* fn_1_96630 */
typedef struct Fn1966A0Object Fn1966A0Object;

/* fn_1_96630 */
struct Fn1966A0Object {
    u32 entries[0x39];
    u32 resource_e4;
    u8 unk_E8[0x10];
    u32 resource_f8;
};

/* fn_1_967A8 */
typedef struct Fn1967A8Object Fn1967A8Object;

/* fn_1_967A8 */
struct Fn1967A8Object {
    u8 unk_00[0x1C];
    Fn1967A8Resource *unk_1C;
    void *unk_20;
    u8 unk_24[0x64];
    u32 unk_88;
    u8 unk_8C[0xC0];
    u32 unk_14C;
    u32 unk_150;
    void *unk_154;
};

/* fn_1_968FC */
typedef struct Fn1968FCChild Fn1968FCChild;

/* fn_1_968FC */
typedef struct Fn1968FCObject Fn1968FCObject;

/* fn_1_968FC */
struct Fn1968FCChild {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0c[0x10];
    u32 unk_1c;
};

/* fn_1_968FC */
struct Fn1968FCObject {
    u8 unk_00[0x1c];
    Fn1968FCChild *unk_1c;
    void *unk_20;
};

/* fn_1_96B14 */
typedef struct Fn196B14Entry Fn196B14Entry;

/* fn_1_96B14 */
struct Fn196B14Entry {
    u8 unk_00[0x210];
    void *unk_210;
    void *unk_214;
};

/* fn_1_96F20 */
typedef struct CarSub2 {
    u8 unk_00[0x88];
    u8 unk_88[1];
} CarSub2;

/* fn_1_96F20 */
typedef struct CarSub {
    u8 unk_00[0x8];
    CarSub2 *unk_8;
} CarSub;

/* fn_1_96F20 */
typedef struct CarData_96F20 {
    u8 unk_00[0x8c];
    s32 unk_8c;
    u8 unk_90[0x10];
    s16 unk_a0;
    s16 unk_a2;
    s16 unk_a4;
    u8 unk_a6[2];
    f32 unk_a8;
    f32 unk_ac;
    f32 unk_b0;
    f32 unk_b4;
    f32 unk_b8;
    u8 unk_bc[0x28];
    void *unk_e4[1];
    u8 unk_e8[0x150 - 0xe8];
    CarSub *unk_150;
} CarData_96F20;

/* fn_1_97174 */
typedef struct Fn197174Owner Fn197174Owner;

/* fn_1_97174 */
typedef struct Fn197174Root Fn197174Root;

/* fn_1_97174 */
typedef struct Fn197174Entry Fn197174Entry;

/* fn_1_97174 */
struct Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

/* fn_1_97174 */
struct Fn197174Root {
    u8 unk_00[0x08];
    u16 count;
};

/* fn_1_97174 */
struct Fn197174Entry {
    u8 unk_00[0x1C];
    u32 offset;
};

/* fn_1_97288 */
typedef struct Fn142AD0Pair {
    u32 a;
    u32 b;
} Fn142AD0Pair;

/* fn_1_97288 */
typedef struct Fn142AD0Entry {
    u8 pad0[0x88];
    u8 value88[0x0C];
    f32 x;
    u8 pad98[0x0C];
    f32 y;
    u8 padA8[0x0C];
    f32 z;
    Fn142AD0Pair sourceB8;
    u32 sourceC0;
    Fn142AD0Pair sourceC4;
    u32 sourceCC;
    u8 padD0[4];
    u16 keys[6][2][3];
    u32 keysF[3][2][3];
    u8 quat[0x10];
    Fn142AD0Pair value174;
    u32 value17C;
    Fn142AD0Pair value180;
    u32 value188;
} Fn142AD0Entry;

/* fn_1_97288 */
typedef struct Fn142AD0Key {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn142AD0Key;

/* fn_1_97288 */
typedef struct Fn142AD0Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142AD0Entry *entries;
    u8 padC[0x20];
    f32 value2C;
    f32 value30;
    f32 value34;
    f32 value38;
    u8 pad3C[4];
    Fn142AD0Key cur;
    u8 pad54[4];
    Fn142AD0Key prev;
} Fn142AD0Object;

/* fn_1_97288 */
typedef struct Fn142E74Entry {
    u8 pad0[0xB8];
    Fn142AD0Pair sourceB8;
    u32 sourceC0;
    Fn142AD0Pair sourceC4;
    u32 sourceCC;
    u8 padD0[0xA4];
    Fn142AD0Pair value174;
    u32 value17C;
    Fn142AD0Pair value180;
    u32 value188;
} Fn142E74Entry;

/* fn_1_97288 */
typedef struct Fn142E74Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142E74Entry *entries;
    u8 padC[0x0C];
    f32 value0;
    f32 value1;
    f32 value2;
    u8 pad24[0x1C];
    u16 flags40;
} Fn142E74Object;

/* fn_1_97288 */
typedef struct AdxSjdHandle AdxSjdHandle;

/* fn_1_97288 */
typedef struct ADXStream ADXStream;

/* fn_1_97288 */
typedef struct AXRNAHandle AXRNAHandle;

/* fn_1_97288 */
typedef struct LSCObject LSCObject;

/* fn_1_97288 */
typedef struct ADX_AMP ADX_AMP;

/* fn_1_97288 */
typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

/* fn_1_97288 */
struct fn_1_97288_Arg0 {
    u8 pad_0[0x1E4];
    u32 unk_1E4;
};

/* fn_1_97288 */
struct fn_1_97288_lbl_1_rodata_3E48 {
    u8 pad_0[0x124];
    f32 unk_124;
    u8 pad_128[0x4];
    f32 unk_12C;
    u8 pad_130[0x8];
    f64 unk_138;
    u8 pad_140[0x80];
    f64 unk_1C0;
    u8 pad_1C8[0x74];
    f32 unk_23C;
};

/* fn_1_97288 */
struct fn_1_97288_lbl_1_data_209C0 {
    u8 pad_0[0x6400];
    u32 unk_6400[6];
    f32 unk_6418;
};

/* fn_1_977BC */
typedef struct { u8 pad[0x4C]; f32 frame; } RobMotion;

/* fn_1_977BC */
typedef struct { u16 id; u8 pad[6]; RobMotion *motion; Sig_fn_1_41418_Fn41418Data *names; } RobAnim;

/* fn_1_977BC */
typedef struct {
    u8 pad0[0x8C]; u32 active;
    u8 pad90[0x10]; s16 rot_y, rot_x, rot_z; u8 padA6[2];
    Vec3 pos; f32 height; f32 scale;
    u8 padBC[0x28]; void *models[5];
    u8 padF8[0x50]; RobAnim anim;
} Rob;

/* fn_1_977BC */
typedef struct { u8 pad[0x88]; f32 matrix[3][4]; u8 padB8[0x18C - 0xB8]; } RobJoint;

/* fn_1_977BC */
typedef struct { u8 pad[8]; RobJoint *joints; } RobView;

/* fn_1_977BC */
typedef struct { Vec3 pos; const char *name; } RobPart;

/* fn_1_977BC */
typedef struct { u8 pad[0x7330]; RobPart parts[8]; char names[4][8]; } RobData;

/* fn_1_977BC */
typedef struct { u32 flags; u8 pad[0x1C]; } RobMaterial;

/* fn_1_977BC */
typedef struct { u8 pad[0x18]; u16 count; u8 pad1A[0x26]; RobMaterial materials[1]; } RobModel;

/* fn_1_977BC */
typedef struct {
    u8 unk_000[0x4A4];
    s32 unk_4A4;
} Fn197F1CObject;

/* fn_1_97F80 */
typedef struct Fn197F80Object Fn197F80Object;

/* fn_1_97F80 */
struct Fn197F80Object {
    u8 unk_000[0x488];
    u8 unk_488;
    u8 unk_489;
    u8 unk_48A[0x1A];
    void *unk_4A4;
    void *unk_4A8;
    void *unk_4AC;
    void *unk_4B0;
    void *unk_4B4;
};

/* fn_1_98104 */
typedef struct Fn198104Obj {
    u8 unk_00[0x1C];
    u32 value_1C;
    u8 unk_20[0x0C];
    u32 value_2C;
} Fn198104Obj;

extern void ADXT_Stop(u32 arg0);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void DCFlushRange(void *, u32);
extern void GXGetProjectionv(f32* out);
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern u32 GXGetTexBufferSize(u16 width, u16 height, u32 arg2, u32 arg3, u32 arg4);
extern void GXInitLightDistAttn(GXLightObj *lt, f32 ref_dist, f32 ref_br, s32 fn);
extern void GXInvalidateTexAll(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void OSReport(const char *, ...);
extern s32 __cvt_fp2unsigned(f32);
extern f64 __fabs(f64);
extern void _restgpr_27(void);
extern void _savegpr_27(void);
extern s16 camera_get_entry_field_0xa4(u32);
extern void *camera_get_state_object(void);
extern s32 camera_get_values(f32 *, f32 *);
extern void camera_update_state(void *);
extern u8 fn_15_5864(void);
extern void fn_1_1071C0(void);
extern void fn_1_107930(Fn8E7D0Car *car);
extern void fn_1_107C4C(void *arg);
extern void fn_1_107C74(Fn8F62CCar *car);
extern void fn_1_107F2C(Car92554 *);
extern void fn_1_107F50(Car92554 *);
extern void *fn_1_12A290(s32);
extern void fn_1_12A2B8(u32 value);
extern void fn_1_12A2C4(u32);
extern void fn_1_12A2D0(s32);
extern s32 fn_1_12A32C(char *);
extern u32 fn_1_12A6D8(char *);
extern void fn_1_12A734(s32 value);
extern void fn_1_12A7C4(const char *path, Fn80294Car *car, u32 size);
extern s32 fn_1_12A8A4(void *, void *);
extern s32 fn_1_12A9BC(void *, void *);
extern u32 fn_1_12AAC8(char *);
extern void fn_1_12AB38(void *);
extern void fn_1_12ABB4(void *);
extern u32 fn_1_12AC00(unsigned char *value);
extern void *fn_1_12AC28(const char *path, u32 *arg1, u32 *arg2);
extern Fn80294Model *fn_1_12ADA0(const char *path, void *texture);
extern Fn80294Model *fn_1_12ADC8(const char *path, void *texture, u32 *arg2, u32 *arg3);
extern void fn_1_14D728(s16 *ids, Fn80294Part *parts);
extern void fn_1_14DBCC(Sig_fn_1_7F658_Item *);
extern void * fn_1_14DD68(u32);
extern u32 fn_1_14DDF4(u32);
extern void fn_1_14E2DC(u32, s32, f32);
extern void *fn_1_14F04(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern char *fn_1_14FEAC(s16, s16, s16, char *, s16);
extern void fn_1_1502BC(void *, void *, s16);
extern void fn_1_150464(u32);
extern void fn_1_151BDC(BurnerBig *);
extern s32 fn_1_15578(Vec3 *, Vec3 *, f32 *, Vec3 *, u32, s32 *, s32, s32, s32, Car892FC *);
extern void fn_1_17920(s32 index, f32 t, void *arg1);
extern s32 fn_1_17A9C(Vec3 *);
extern s32 fn_1_17C6C(s32, s32, s32);
extern s32 fn_1_17FCC(s32, s32, s32);
extern s32 fn_1_181CC(s32, s32, s32);
extern s32 fn_1_181F0(s32, s32, s32);
extern u32 fn_1_1FB80(void *, s32);
extern f32 fn_1_1FDB0(Vec3 *, Vec3 *, Vec3 *, Vec3 *);
extern int fn_1_20994(void *arg, f32 *out);
extern int fn_1_20A5C(f32 *, f32 *);
extern s32 fn_1_210A8(Vec3 *, f32 *, s32, s32, Vec3 *);
extern s32 fn_1_214C4(f32 *, s32, f32);
extern void *fn_1_21644(void *arg0, f32 *arg1, void *arg2);
extern s32 fn_1_216C0(Vec3 *, f32 *, s32);
extern s32 fn_1_216F0(Vec3 *, s32, s32);
extern s32 fn_1_224F8(Vec3 *, Vec3 *, u32 *);
extern void fn_1_2277C(F83070Car *, F83070Desc *);
extern void fn_1_23500();
extern u32 fn_1_236CC(u32);
extern s32 fn_1_239C4(Car850C4 *, Car850C4 *);
extern void fn_1_24A4C(Car850C4 *);
extern void fn_1_25004(void *);
extern void fn_1_250F8(Car850C4 *);
extern void fn_1_266A8(Car850C4 *);
extern Fn1_82C70_Record *fn_1_36AD0(void);
extern void fn_1_3BDC(s32);
extern s16 fn_1_3C18(s32);
extern void fn_1_3EF14(void *);
extern s32 fn_1_3EFA8(void);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_3F854(void);
extern s32 fn_1_3F8C(char *name, void *func, void *arg, u32 priority);
extern s32 fn_1_3FC18(void);
extern void fn_1_41328(void *arg0);
extern s32 fn_1_41418(void *resource, u16 id);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41850(void *arg0);
extern Fn197174Entry *fn_1_41B18(Fn197174Owner *owner, void *arg1, s32 index);
extern Fn197174Root *fn_1_41BDC(void);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_41CB8(Fn8F62CMotion *data);
extern void fn_1_41E34(void *, u32, void *);
extern void fn_1_41F58(void *, s32, void (*arg2)(void), void *arg3);
extern u32 fn_1_4247C(void *, u32, void *);
extern void fn_1_426AC(Sig_fn_1_426AC_Fn1426ACObject *, void *);
extern void fn_1_426C(s32 value);
extern void fn_1_426E4(void *arg0, void *arg1);
extern void fn_1_4270C(void *arg0, s32 arg1, u32 arg2);
extern void fn_1_42AD0(void *, s32, u16, s32, u16);
extern void fn_1_42E74(void *);
extern void fn_1_43058(Fn8F62CModel *model, u32 arg1, u32 arg2, f32 value);
extern void fn_1_43120(void *object, u32 index, Vec3 *vector);
extern void *fn_1_435C(void *);
extern void fn_1_43E8(u32);
extern void fn_1_43F4(void);
extern int fn_1_45730(void *, Sig_fn_1_45730_LoadResult *);
extern void fn_1_45850(Sig_fn_1_45730_LoadResult *);
extern s32 fn_1_45B2C(Sig_fn_1_45730_LoadResult *);
extern void *fn_1_45D0(void *, s32, const char *, s32);
extern void *fn_1_4630(u32, u32, void *, u32);
extern s32 fn_1_465D0(char *path, s32 arg1);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern s32 fn_1_46C70();
extern void fn_1_49514(GXColor *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_495D8(s32, s32, f32);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4FC50(u32, u32, u16, u16, u32);
extern void *fn_1_5448C(void *);
extern void fn_1_545B8(void);
extern s32 fn_1_548EC(void);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_550A8(void);
extern void fn_1_550E0(void);
extern void fn_1_55210(void *);
extern void fn_1_55628(Sig_fn_1_55628_Fn1_55628Object *);
extern void fn_1_556B8(void *);
extern void fn_1_557C4(Node92554 *);
extern void fn_1_55924(Node92554 *, s32);
extern void fn_1_55FD0(f32, f32, f32);
extern void fn_1_55FF0(f32);
extern void fn_1_56018(s32);
extern void fn_1_560F0(s32, void *);
extern void fn_1_5616C(s32 value, f32 value1, f32 value2);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_5631C(GXColor *);
extern void fn_1_5634C(u32);
extern void fn_1_5635C(s32 arg0, f32 arg1, f32 arg2);
extern void fn_1_56374(u8 arg0, u8 arg1, u8 arg2);
extern void fn_1_566EC(s32, s32);
extern void fn_1_5672C(void *, int);
extern void fn_1_56858(void *, int);
extern void fn_1_568EC(void *, void *, void *);
extern void fn_1_568F8(void *);
extern void fn_1_56D4C(void *);
extern void fn_1_5745C(void *, GXColor *);
extern void fn_1_57714(s32);
extern void fn_1_57720(s32, s32, s32, s32);
extern void fn_1_5773C(Vec3 *, Vec3 *, GXColor *);
extern void fn_1_57810(s32 n, Vec3 *pts, GXColor *c);
extern s32 fn_1_58C4(void);
extern s16 fn_1_58E3C(void *);
extern u32 fn_1_5910(void);
extern void fn_1_591A0(s32 id);
extern void fn_1_681C(u32, void *);
extern void fn_1_68B6C(s8, s8);
extern void fn_1_6914(u32 index, u32 *output);
extern u32 fn_1_6EC0(u8);
extern s16 fn_1_7B054(void);
extern void fn_1_7BB80(GXLightObj *lt, s32 id);
extern void fn_1_7BCCC(Vec3 *v);
extern void fn_1_7BD6C(s32);
void fn_1_7C13C(Car *cars);
void fn_1_7C1E8(CarTestLight *lights);
extern void fn_1_7EB0C(void);
static void fn_1_96C40_grid(s32 cx, s32 cz);
extern void fn_1_983CC(void *, void *);
extern s32 fn_1_A5DC4(void);
extern void fn_1_A714C(f32 *, s32, s32, f32 *);
extern f32 fn_1_A71AC(void);
extern s32 fn_1_A728C(u8);
extern void fn_1_A7294(void *, u32);
extern void fn_1_A744C(void *, u32);
extern void fn_1_A7728(Sig_fn_1_7F658_Car *);
extern void fn_1_A77DC(void *);
extern void fn_1_A7854(void *, void *);
extern void fn_1_A7B5C(void *arg0, s32 arg1, void *arg2, s8 arg3, void *arg4);
extern void fn_1_A8DD4(const char *format, ...);
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8EF8(s16, s16);
extern void fn_1_A8F40(u8 arg0);
extern void fn_1_B81C(Vec3 *, Vec3 *, s32);
extern void fn_1_C40A0(Obj_1_bss_6D838_Target *);
extern void fn_1_C487C(F83070Car *);
extern void fn_1_C489C(Obj_1_bss_6D838_Target *);
extern void fn_1_C4ABC(void);
extern void fn_1_C6ED4(Sig_fn_1_C6ED4_Fn1C6ED4Enemy *);
extern void fn_1_C6F80(u8);
extern Fn81164Model *fn_1_D3884(char *);
extern int fn_1_F7BE4(s16 arg0);
extern void fn_1_FC414(void *, u32);
extern void fn_1_FCF74(void);
extern void fn_1_FCFA4(void *);
extern u8 fn_1_FD844(Fn1_82C70_Record *record, Fn1_82C70_Work *work);
extern s32 fn_1_FDB40(void **);
extern void fn_1_FDC00(void *, void *, f32);
extern void fn_1_FDD7C(void *, void *);
extern void fn_1_FDFF4(void);
extern void fn_1_FE004(void);
extern void fn_80006E10(const char *path);
extern void fn_80007AB4(u8 *arg0);
extern u32 fn_80007CDC(f32 *arg0);
extern u32 fn_80007D58(f32 *arg0);
extern void fn_80008204(void *);
extern u32 fn_800084E8(Sig_fn_80036070_Fn80036070Data *, void *);
extern void fn_80008BA8(void *dst, const void *src, int size);
extern void fn_80008BEC(void *, int, u32);
extern u32 fn_80008E84(u32);
extern void fn_80009CAC(void *, u32);
extern u32 fn_80009FB4(void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8003526C(u32, u8);
extern void fn_80035420(GXLightObj *lt, f32 cutoff, s32 fn);
extern void fn_80035680(GXLightObj *lt, f32 x, f32 y, f32 z);
extern void fn_80035690(GXLightObj *lt, f32 x, f32 y, f32 z);
extern void fn_800356AC(GXLightObj *lt, GXColor *c);
extern void fn_80036070(Sig_fn_80036070_Fn80036070Data *, u32 *, u16 *, u16 *, u32 *, u32 *, u32 *, u8 *);
extern u32 fn_80038EEC();
extern void fn_80038F10(f32* out);
extern void fn_8004D18C(ADXTHandle *, u32);
extern void fn_8006E250(void *, void *);
extern s16 fn_8006F394(void);
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_800711A8(u32);
extern void *fn_80071268(void *, void *);
extern void fn_800712E4(void *arg0, u32 arg1, void *arg2);
extern void fn_800713E0(u32, u32);
extern u32 fn_80071470(u32, u32);
extern u32 fn_80071718(u32);
extern void fn_80071ED4(s32, f32, f32);
extern void fn_80072014(void *);
extern void fn_800720B0(s32);
extern void fn_80072270(void *);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_800725DC(GXColor *);
extern void fn_80072614(GXColor *);
extern void fn_80072864(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_800737E4(void *, s32);
extern void fn_80073C6C(s32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80074300();
extern void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern u32 fn_80074A7C(u32 arg0);
extern void fn_80074CF4(f32 r, f32 g, f32 b);
extern void fn_80074D68(f32, f32, f32);
extern void fn_80074D78(u32);
extern u32 *fn_80077A18(void);
extern void fn_80077A20(Node92554 *, s32);
extern u32 fn_80077BD4(void *);
extern u32 fn_80077D40(void *);
extern void fn_80077F8C(void *);
extern u32 fn_800793D4(void *, u32, u32);
extern void *strstr(void *, void *);
extern int strcmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern u8 lbl_1_bss_26B80[168];
extern BgState *lbl_1_bss_38454;
extern Obj_1_bss_525C lbl_1_bss_525C;
extern u32 lbl_1_bss_6D758[6];
extern struct fn_1_900C4_lbl_1_bss_6E960 lbl_1_bss_6E960;
extern u32 lbl_1_bss_6E978[3];
extern s32 lbl_1_bss_6E984;
extern s16 lbl_1_bss_6E988;
extern u32 lbl_1_bss_6E98C;
extern u8 lbl_1_bss_6E990[];
extern u8 lbl_1_bss_8CA28;
extern s8 lbl_1_bss_9C;
extern struct fn_1_83858_lbl_1_bss_A88 lbl_1_bss_A88;
typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    u8 pad_14[0x3C];
} Obj_1_bss_C70;
/* one controller's analog input, 0x14 bytes */
typedef struct {
    f32 steer;
    f32 accel;
    f32 brake;
    f32 pitch;
    f32 side;
} PadAnalog;
extern PadAnalog lbl_1_bss_C70[4];
extern struct fn_1_83858_lbl_1_bss_CC0 lbl_1_bss_CC0;
extern Fn9012CPad lbl_1_bss_D58;
extern struct fn_1_83858_lbl_1_bss_D70 lbl_1_bss_D70;
extern u32 lbl_1_data_209C0;
extern char lbl_1_data_209C8[];
extern char lbl_1_data_209D0[];
extern char lbl_1_data_209D8[];
extern char lbl_1_data_209E0[];
extern char lbl_1_data_209E8[];
extern char lbl_1_data_209F0[];
extern char lbl_1_data_209F8[];
extern char lbl_1_data_20A00[];
extern char lbl_1_data_20A04[];
extern char lbl_1_data_20A0C[];
extern char lbl_1_data_20A14[];
extern char lbl_1_data_20A1C[];
extern char lbl_1_data_20A24[];
extern char lbl_1_data_20A2C[];
extern char lbl_1_data_20A30[];
extern char lbl_1_data_20A38[];
extern char lbl_1_data_20A40[];
extern char lbl_1_data_20A4C[];
extern char lbl_1_data_20A54[];
extern char lbl_1_data_20A5C[];
extern char lbl_1_data_20A60[];
extern char lbl_1_data_20A68[];
extern char lbl_1_data_20A70[];
extern char lbl_1_data_20A78[];
extern char lbl_1_data_20A80[];
extern char lbl_1_data_20A88[];
extern char lbl_1_data_20A90[];
extern char lbl_1_data_20A98[];
extern char lbl_1_data_20AA0[];
extern char lbl_1_data_20AA8[];
extern char lbl_1_data_20AB0[];
extern char lbl_1_data_20AB4[];
extern char lbl_1_data_20ABC[];
extern char lbl_1_data_20AC0[];
extern char lbl_1_data_20AC8[];
extern char lbl_1_data_20AD4[];
extern char lbl_1_data_20ADC[];
extern char lbl_1_data_20AE4[];
extern char lbl_1_data_20AE8[];
extern char lbl_1_data_20AEC[];
extern char lbl_1_data_20AF8[];
extern char lbl_1_data_20B00[];
extern char lbl_1_data_20B04[];
extern char lbl_1_data_20B08[];
extern char lbl_1_data_20BC8[];
extern char lbl_1_data_20BD0[];
extern char lbl_1_data_20BD8[];
extern char lbl_1_data_20BE0[];
extern char lbl_1_data_20BE8[];
extern char lbl_1_data_20BF0[];
extern char lbl_1_data_20BF8[];
extern char lbl_1_data_20C00[];
extern char lbl_1_data_20C08[];
extern char lbl_1_data_20C0C[];
extern char lbl_1_data_20C14[];
extern char lbl_1_data_20C1C[];
extern char lbl_1_data_20C24[];
extern char lbl_1_data_20C2C[];
extern char lbl_1_data_20C34[];
extern char lbl_1_data_20C38[];
extern char lbl_1_data_20C40[];
extern char lbl_1_data_20C48[];
extern char lbl_1_data_20C54[];
extern char lbl_1_data_20C5C[];
extern char lbl_1_data_20C64[];
extern char lbl_1_data_20C68[];
extern char lbl_1_data_20C70[];
extern char lbl_1_data_20C78[];
extern char lbl_1_data_20C80[];
extern char lbl_1_data_20C88[];
extern char lbl_1_data_20C90[];
extern char lbl_1_data_20C98[];
extern char lbl_1_data_20CA0[];
extern char lbl_1_data_20CA8[];
extern char lbl_1_data_20CB0[];
extern char lbl_1_data_20CB8[];
extern char lbl_1_data_20CBC[];
extern char lbl_1_data_20CC4[];
extern char lbl_1_data_20CC8[];
extern char lbl_1_data_20CD0[];
extern char lbl_1_data_20CDC[];
extern char lbl_1_data_20CE4[];
extern char lbl_1_data_20CEC[];
extern char lbl_1_data_20CF0[];
extern char lbl_1_data_20CF4[];
extern char lbl_1_data_20D00[];
extern char lbl_1_data_20D08[];
extern char lbl_1_data_20D0C[];
extern char lbl_1_data_20D10[];
extern const char *lbl_1_data_20D1C[];
extern char lbl_1_data_20DD0[];
extern char lbl_1_data_20DE4[];
extern char lbl_1_data_20DF4[];
extern char lbl_1_data_20E0C[];
extern char lbl_1_data_20E14[];
extern char lbl_1_data_20E24[];
extern char lbl_1_data_20E2C[];
extern char lbl_1_data_20E44[];
extern char lbl_1_data_20E50[];
extern char lbl_1_data_20E6C[];
extern char lbl_1_data_20E84[];
extern char lbl_1_data_20E8C[];
extern char lbl_1_data_20E9C[];
extern char lbl_1_data_20EA4[];
extern char lbl_1_data_20EB4[];
extern char lbl_1_data_20EC4[];
extern char lbl_1_data_20ED0[];
extern char lbl_1_data_20EE4[];
extern char lbl_1_data_20EF4[];
extern char lbl_1_data_20EFC[];
extern char lbl_1_data_20F0C[];
extern char lbl_1_data_20F1C[];
extern char lbl_1_data_20F2C[];
extern char lbl_1_data_20F40[];
extern char lbl_1_data_20F54[];
extern char lbl_1_data_20F68[];
extern char lbl_1_data_20F78[];
extern char lbl_1_data_20F80[];
extern char lbl_1_data_20F94[];
extern char lbl_1_data_20FA8[];
extern char lbl_1_data_20FBC[];
extern char lbl_1_data_20FC8[];
extern char lbl_1_data_20FD8[];
extern char lbl_1_data_20FE4[];
extern char lbl_1_data_20FF8[];
extern char lbl_1_data_21004[];
extern char lbl_1_data_21010[];
extern char lbl_1_data_2101C[];
extern char lbl_1_data_21024[];
extern char lbl_1_data_21030[];
extern char lbl_1_data_21040[];
extern char lbl_1_data_21050[];
extern char lbl_1_data_21058[];
extern char lbl_1_data_21060[];
extern char lbl_1_data_21068[];
extern char lbl_1_data_2112C[];
extern char lbl_1_data_2113C[];
extern char lbl_1_data_21148[];
extern char lbl_1_data_21154[];
extern char lbl_1_data_21164[];
extern char lbl_1_data_21174[];
extern char lbl_1_data_2117C[];
extern char lbl_1_data_21184[];
extern char lbl_1_data_21194[];
extern char lbl_1_data_211A0[];
extern char lbl_1_data_211AC[];
extern char lbl_1_data_211B4[];
extern char lbl_1_data_211C0[];
extern char lbl_1_data_211D0[];
extern char lbl_1_data_211DC[];
extern char lbl_1_data_211E8[];
extern char lbl_1_data_211F8[];
extern char lbl_1_data_21208[];
extern char lbl_1_data_21218[];
extern char lbl_1_data_21228[];
extern char lbl_1_data_21234[];
extern char lbl_1_data_21244[];
extern char lbl_1_data_21250[];
extern char lbl_1_data_21260[];
extern char lbl_1_data_2126C[];
extern char lbl_1_data_21278[];
extern char lbl_1_data_21284[];
extern char lbl_1_data_21290[];
extern char lbl_1_data_21298[];
extern char lbl_1_data_212A0[];
extern u8 lbl_1_data_2135C[];
extern u8 lbl_1_data_21384[];
extern u8 lbl_1_data_213A0[];
extern u8 lbl_1_data_213B0[];
extern u8 lbl_1_data_213C4[];
extern u8 lbl_1_data_213D4[];
extern u8 lbl_1_data_213E4[];
extern u8 lbl_1_data_213EC[];
extern u8 lbl_1_data_21414[];
extern u8 lbl_1_data_21434[];
extern u8 lbl_1_data_21444[];
extern u8 lbl_1_data_21454[];
extern u8 lbl_1_data_21464[];
extern u8 lbl_1_data_2146C[];
extern u8 lbl_1_data_21494[];
extern u8 lbl_1_data_214B4[];
extern u8 lbl_1_data_214C4[];
extern u8 lbl_1_data_214D4[];
extern u8 lbl_1_data_214E4[];
extern u8 lbl_1_data_214EC[];
extern u8 lbl_1_data_21514[];
extern u8 lbl_1_data_2153C[];
extern u8 lbl_1_data_2154C[];
extern u8 lbl_1_data_2155C[];
extern u8 lbl_1_data_2156C[];
extern u8 lbl_1_data_21574[];
extern u8 lbl_1_data_2159C[];
extern u8 lbl_1_data_215B8[];
extern u8 lbl_1_data_215C8[];
extern u8 lbl_1_data_215D8[];
extern u8 lbl_1_data_215E8[];
extern u8 lbl_1_data_215F0[];
extern u8 lbl_1_data_21618[];
extern u8 lbl_1_data_21628[];
extern u8 lbl_1_data_21638[];
extern u8 lbl_1_data_21648[];
extern u8 lbl_1_data_21658[];
extern u8 lbl_1_data_21660[];
extern u8 lbl_1_data_216A8[];
extern u8 lbl_1_data_216C0[];
extern u8 lbl_1_data_216D0[];
extern u8 lbl_1_data_216E4[];
extern u8 lbl_1_data_216F8[];
extern u8 lbl_1_data_21700[];
extern u8 lbl_1_data_21728[];
extern u8 lbl_1_data_2174C[];
extern u8 lbl_1_data_2175C[];
extern u8 lbl_1_data_2176C[];
extern u8 lbl_1_data_2177C[];
extern u8 lbl_1_data_2178C[];
extern u8 lbl_1_data_21798[];
extern u8 lbl_1_data_217C0[];
extern u8 lbl_1_data_217E8[];
extern u8 lbl_1_data_217F8[];
extern u8 lbl_1_data_217FC[];
extern u8 lbl_1_data_21810[];
extern u8 lbl_1_data_21824[];
extern u8 lbl_1_data_21830[];
extern u8 lbl_1_data_21860[];
extern u8 lbl_1_data_21878[];
extern u8 lbl_1_data_21888[];
extern u8 lbl_1_data_2189C[];
extern u8 lbl_1_data_218B0[];
extern u8 lbl_1_data_218B8[];
extern u8 lbl_1_data_218D8[];
extern u8 lbl_1_data_21900[];
extern u8 lbl_1_data_21910[];
extern u8 lbl_1_data_21914[];
extern u8 lbl_1_data_21924[];
extern u8 lbl_1_data_21934[];
extern u8 lbl_1_data_2193C[];
extern u8 lbl_1_data_21964[];
extern u8 lbl_1_data_21980[];
extern u8 lbl_1_data_21990[];
extern u8 lbl_1_data_219A4[];
extern u8 lbl_1_data_219B8[];
extern u8 lbl_1_data_219C0[];
extern u8 lbl_1_data_219E8[];
extern u8 lbl_1_data_21A04[];
extern u8 lbl_1_data_21A14[];
extern u8 lbl_1_data_21A24[];
extern u8 lbl_1_data_21A34[];
extern u8 lbl_1_data_21A3C[];
extern u8 lbl_1_data_21A64[];
extern u8 lbl_1_data_21A80[];
extern u8 lbl_1_data_21A90[];
extern u8 lbl_1_data_21AA0[];
extern u8 lbl_1_data_21AB0[];
extern u8 lbl_1_data_21AB8[];
extern u8 lbl_1_data_21AD8[];
extern u8 lbl_1_data_21ADC[];
extern u8 lbl_1_data_21AEC[];
extern u8 lbl_1_data_21AFC[];
extern u8 lbl_1_data_21B0C[];
extern u8 lbl_1_data_21B14[];
extern u8 lbl_1_data_21B3C[];
extern u8 lbl_1_data_21B60[];
extern u8 lbl_1_data_21B70[];
extern u8 lbl_1_data_21B80[];
extern u8 lbl_1_data_21B90[];
extern u8 lbl_1_data_21BA0[];
extern u8 lbl_1_data_21BAC[];
extern u8 lbl_1_data_21BD4[];
extern u8 lbl_1_data_21BF0[];
extern u8 lbl_1_data_21C00[];
extern u8 lbl_1_data_21C10[];
extern u8 lbl_1_data_21C20[];
extern u8 lbl_1_data_21C30[];
extern u8 lbl_1_data_21C38[];
extern u8 lbl_1_data_21C60[];
extern u8 lbl_1_data_21C7C[];
extern u8 lbl_1_data_21C8C[];
extern u8 lbl_1_data_21C9C[];
extern u8 lbl_1_data_21CAC[];
extern u8 lbl_1_data_21CB4[];
extern u8 lbl_1_data_21CDC[];
extern u8 lbl_1_data_21CF4[];
extern u8 lbl_1_data_21D08[];
extern u8 lbl_1_data_21D18[];
extern u8 lbl_1_data_21D28[];
extern u8 lbl_1_data_21D30[];
extern u8 lbl_1_data_21D58[];
extern u8 lbl_1_data_21D70[];
extern u8 lbl_1_data_21D80[];
extern u8 lbl_1_data_21D90[];
extern u8 lbl_1_data_21DA0[];
extern u8 lbl_1_data_21DA8[];
extern u8 lbl_1_data_21DBC[];
extern u8 lbl_1_data_21DD0[];
extern u8 lbl_1_data_21DE0[];
extern u8 lbl_1_data_21DF0[];
extern u8 lbl_1_data_21E00[];
extern u8 lbl_1_data_21E08[];
extern u8 lbl_1_data_21E30[];
extern u8 lbl_1_data_21E54[];
extern u8 lbl_1_data_21E64[];
extern u8 lbl_1_data_21E74[];
extern u8 lbl_1_data_21E84[];
extern u8 lbl_1_data_21E8C[];
extern u8 lbl_1_data_21EB4[];
extern u8 lbl_1_data_21ECC[];
extern u8 lbl_1_data_21EDC[];
extern u8 lbl_1_data_21EEC[];
extern u8 lbl_1_data_21EFC[];
extern u8 lbl_1_data_21F04[];
extern u8 lbl_1_data_21F2C[];
extern u8 lbl_1_data_21F50[];
extern u8 lbl_1_data_21F60[];
extern u8 lbl_1_data_21F70[];
extern u8 lbl_1_data_21F80[];
extern u8 lbl_1_data_21F88[];
extern u8 lbl_1_data_21FB0[];
extern u8 lbl_1_data_21FD4[];
extern u8 lbl_1_data_21FE4[];
extern u8 lbl_1_data_21FF4[];
extern u8 lbl_1_data_22004[];
extern u8 lbl_1_data_2200C[];
extern u8 lbl_1_data_2203C[];
extern u8 lbl_1_data_22058[];
extern u8 lbl_1_data_22068[];
extern u8 lbl_1_data_2207C[];
extern u8 lbl_1_data_22090[];
extern u8 lbl_1_data_22098[];
extern u8 lbl_1_data_220C0[];
extern u8 lbl_1_data_220E8[];
extern u8 lbl_1_data_220F8[];
extern u8 lbl_1_data_22108[];
extern u8 lbl_1_data_22118[];
extern u8 lbl_1_data_22120[];
extern u8 lbl_1_data_22148[];
extern u8 lbl_1_data_22160[];
extern u8 lbl_1_data_22170[];
extern u8 lbl_1_data_22180[];
extern u8 lbl_1_data_22190[];
extern u8 lbl_1_data_22198[];
extern u8 lbl_1_data_221C0[];
extern u8 lbl_1_data_221E4[];
extern u8 lbl_1_data_221F4[];
extern u8 lbl_1_data_22204[];
extern u8 lbl_1_data_22214[];
extern u8 lbl_1_data_2221C[];
extern u8 lbl_1_data_22244[];
extern u8 lbl_1_data_22264[];
extern u8 lbl_1_data_22274[];
extern u8 lbl_1_data_22278[];
extern u8 lbl_1_data_22288[];
extern u8 lbl_1_data_22298[];
extern u8 lbl_1_data_222A0[];
extern u8 lbl_1_data_222D8[];
extern u8 lbl_1_data_222F4[];
extern u8 lbl_1_data_22310[];
extern u8 lbl_1_data_2232C[];
extern u8 lbl_1_data_22334[];
extern u8 lbl_1_data_2235C[];
extern u8 lbl_1_data_22360[];
extern u8 lbl_1_data_22374[];
extern u8 lbl_1_data_22384[];
extern u8 lbl_1_data_22394[];
extern u8 lbl_1_data_223A0[];
extern u8 lbl_1_data_223B4[];
extern u8 lbl_1_data_223CC[];
extern u8 lbl_1_data_223D0[];
extern u8 lbl_1_data_223DC[];
extern u8 lbl_1_data_223EC[];
extern u8 lbl_1_data_223FC[];
extern u8 lbl_1_data_22404[];
extern u8 lbl_1_data_2242C[];
extern u8 lbl_1_data_22454[];
extern u8 lbl_1_data_22464[];
extern u8 lbl_1_data_22474[];
extern u8 lbl_1_data_22484[];
extern u8 lbl_1_data_2248C[];
extern u8 lbl_1_data_224AC[];
extern u8 lbl_1_data_224B4[];
extern u8 lbl_1_data_224B8[];
extern u8 lbl_1_data_224C8[];
extern u8 lbl_1_data_224D8[];
extern u8 lbl_1_data_224E4[];
extern u8 lbl_1_data_22514[];
extern u8 lbl_1_data_22520[];
extern u8 lbl_1_data_22528[];
extern u8 lbl_1_data_2253C[];
extern u8 lbl_1_data_22550[];
extern u8 lbl_1_data_2255C[];
extern u8 lbl_1_data_22584[];
extern u8 lbl_1_data_225AC[];
extern u8 lbl_1_data_225BC[];
extern u8 lbl_1_data_225CC[];
extern u8 lbl_1_data_225DC[];
extern u8 lbl_1_data_225E4[];
extern u8 lbl_1_data_2260C[];
extern u8 lbl_1_data_22630[];
extern u8 lbl_1_data_22640[];
extern u8 lbl_1_data_22650[];
extern u8 lbl_1_data_22660[];
extern u8 lbl_1_data_22670[];
extern u8 lbl_1_data_2267C[];
extern u8 lbl_1_data_226A4[];
extern u8 lbl_1_data_226C0[];
extern u8 lbl_1_data_226D4[];
extern u8 lbl_1_data_226E4[];
extern u8 lbl_1_data_226F4[];
extern u8 lbl_1_data_226FC[];
extern u8 lbl_1_data_22724[];
extern u8 lbl_1_data_22744[];
extern u8 lbl_1_data_22754[];
extern u8 lbl_1_data_22764[];
extern u8 lbl_1_data_22774[];
extern u8 lbl_1_data_2277C[];
extern u8 lbl_1_data_227A4[];
extern u8 lbl_1_data_227C0[];
extern u8 lbl_1_data_227D0[];
extern u8 lbl_1_data_227E0[];
extern u8 lbl_1_data_227F0[];
extern u8 lbl_1_data_22800[];
extern u8 lbl_1_data_22808[];
extern u8 lbl_1_data_2281C[];
extern u8 lbl_1_data_22834[];
extern u8 lbl_1_data_2284C[];
extern u8 lbl_1_data_2285C[];
extern u8 lbl_1_data_2286C[];
extern u8 lbl_1_data_2287C[];
extern u8 lbl_1_data_22884[];
extern u8 lbl_1_data_228AC[];
extern u8 lbl_1_data_228CC[];
extern u8 lbl_1_data_228DC[];
extern u8 lbl_1_data_228EC[];
extern u8 lbl_1_data_228FC[];
extern u8 lbl_1_data_22904[];
extern u8 lbl_1_data_2292C[];
extern u8 lbl_1_data_2294C[];
extern u8 lbl_1_data_2295C[];
extern u8 lbl_1_data_22964[];
extern u8 lbl_1_data_22974[];
extern u8 lbl_1_data_22984[];
extern u8 lbl_1_data_2298C[];
extern u8 lbl_1_data_229B4[];
extern u8 lbl_1_data_229D8[];
extern u8 lbl_1_data_229E8[];
extern u8 lbl_1_data_229F8[];
extern u8 lbl_1_data_22A08[];
extern u8 lbl_1_data_22A10[];
extern char lbl_1_data_22A14[];
extern u8 lbl_1_data_22A18[];
extern char lbl_1_data_22A1C[];
extern char lbl_1_data_22A24[];
extern char lbl_1_data_22A2C[];
extern char lbl_1_data_22A34[];
extern char lbl_1_data_22A3C[];
extern char lbl_1_data_22A44[];
extern char lbl_1_data_22DF4[];
extern char lbl_1_data_22E00[];
extern char lbl_1_data_23190[];
extern char lbl_1_data_23420[];
extern char lbl_1_data_236B0[];
extern char lbl_1_data_24318[];
extern char lbl_1_data_24638[];
extern char lbl_1_data_249E4[];
extern char lbl_1_data_249F4[];
extern char lbl_1_data_24A04[];
extern char lbl_1_data_24A14[];
extern char lbl_1_data_24A24[];
extern char lbl_1_data_24A30[];
extern char lbl_1_data_24A3C[];
extern char lbl_1_data_24A48[];
extern char lbl_1_data_24A54[];
extern char lbl_1_data_24A5C[];
extern char lbl_1_data_24A64[];
extern char lbl_1_data_24A6C[];
extern char lbl_1_data_24A74[];
extern char lbl_1_data_24A7C[];
extern char lbl_1_data_24A84[];
extern char lbl_1_data_24A8C[];
extern char lbl_1_data_24EF0[];
extern u8 lbl_1_data_26C14[];
extern char lbl_1_data_26D50[];
extern char lbl_1_data_26D54[];
extern char lbl_1_data_26D5C[];
extern char lbl_1_data_26D64[];
extern char lbl_1_data_26D6C[];
extern char lbl_1_data_26D74[];
extern char lbl_1_data_26D7C[];
extern char lbl_1_data_26D84[];
extern char lbl_1_data_26D8C[];
extern char lbl_1_data_26D94[];
extern char lbl_1_data_26D9C[];
extern char lbl_1_data_26DA4[];
extern char lbl_1_data_26DAC[];
extern char lbl_1_data_26DDC[];
extern char lbl_1_data_26DE4[];
extern char lbl_1_data_26DEC[];
extern char lbl_1_data_26DF4[];
extern char lbl_1_data_26E00[];
extern char lbl_1_data_26E0C[];
extern char lbl_1_data_26E14[];
extern char lbl_1_data_26E1C[];
extern char lbl_1_data_26E24[];
extern char lbl_1_data_26E2C[];
extern char lbl_1_data_26E34[];
extern char lbl_1_data_26E3C[];
extern char lbl_1_data_26E44[];
extern char lbl_1_data_26E4C[];
extern char lbl_1_data_26E54[];
extern char lbl_1_data_26E5C[];
extern char lbl_1_data_26E64[];
extern char lbl_1_data_26E6C[];
extern char lbl_1_data_26E74[];
extern char lbl_1_data_26E7C[];
extern char lbl_1_data_26E84[];
extern char lbl_1_data_26E8C[];
extern char lbl_1_data_26E94[];
extern char lbl_1_data_26E9C[];
extern char lbl_1_data_26EA4[];
extern char lbl_1_data_26EB0[];
extern char lbl_1_data_26EBC[];
extern char lbl_1_data_26EC8[];
extern char lbl_1_data_26ED4[];
extern char lbl_1_data_26EE0[];
extern char lbl_1_data_26EEC[];
extern char lbl_1_data_26EF8[];
extern char lbl_1_data_26F04[];
extern char lbl_1_data_26F10[];
extern char lbl_1_data_26F1C[];
extern char lbl_1_data_26F28[];
extern char lbl_1_data_26F34[];
extern char lbl_1_data_26F40[];
extern char lbl_1_data_26F4C[];
extern char lbl_1_data_26F58[];
extern char lbl_1_data_26F64[];
extern char lbl_1_data_26F70[];
extern char lbl_1_data_26F7C[];
extern char lbl_1_data_26F88[];
extern char lbl_1_data_27048[];
extern char lbl_1_data_27058[];
extern char lbl_1_data_27060[];
extern char lbl_1_data_2706C[];
extern char lbl_1_data_2707C[];
extern char lbl_1_data_27088[];
extern char lbl_1_data_27094[];
extern char lbl_1_data_270A0[];
extern char lbl_1_data_270B0[];
extern char lbl_1_data_270C0[];
extern char lbl_1_data_270CC[];
extern char lbl_1_data_270D8[];
extern char lbl_1_data_270E4[];
extern char lbl_1_data_270F0[];
extern char lbl_1_data_270FC[];
extern char lbl_1_data_27108[];
extern char lbl_1_data_27114[];
extern char lbl_1_data_27124[];
extern char lbl_1_data_27134[];
extern char lbl_1_data_27144[];
extern char lbl_1_data_27150[];
extern char lbl_1_data_2715C[];
extern char lbl_1_data_27168[];
extern char lbl_1_data_27174[];
extern char lbl_1_data_27184[];
extern char lbl_1_data_27194[];
extern char lbl_1_data_271A0[];
extern char lbl_1_data_271B0[];
extern char lbl_1_data_271BC[];
extern char lbl_1_data_271C8[];
extern char lbl_1_data_271D4[];
extern char lbl_1_data_271E4[];
extern char lbl_1_data_271F0[];
extern char lbl_1_data_271FC[];
extern char lbl_1_data_2720C[];
extern char lbl_1_data_27218[];
extern char lbl_1_data_27224[];
extern char lbl_1_data_27234[];
extern char lbl_1_data_27244[];
extern char lbl_1_data_27250[];
extern char lbl_1_data_2725C[];
extern char lbl_1_data_27268[];
extern char lbl_1_data_27278[];
extern char lbl_1_data_27284[];
extern char lbl_1_data_27290[];
extern char lbl_1_data_2729C[];
extern char lbl_1_data_272A8[];
extern char lbl_1_data_272B0[];
extern char lbl_1_data_272BC[];
extern char lbl_1_data_272C0[];
extern char lbl_1_data_272D0[];
extern char lbl_1_data_272D4[];
extern char lbl_1_data_272E4[];
extern char lbl_1_data_272EC[];
extern char lbl_1_data_272F8[];
extern char lbl_1_data_27300[];
extern char lbl_1_data_27304[];
extern char lbl_1_data_27318[];
extern char lbl_1_data_27324[];
extern char lbl_1_data_27338[];
extern char lbl_1_data_27344[];
extern char lbl_1_data_27358[];
extern char lbl_1_data_27364[];
extern char lbl_1_data_27378[];
extern char lbl_1_data_27384[];
extern char lbl_1_data_27398[];
extern char lbl_1_data_273A8[];
extern char lbl_1_data_273BC[];
extern char lbl_1_data_273CC[];
extern char lbl_1_data_273E0[];
extern char lbl_1_data_273F0[];
extern char lbl_1_data_27404[];
extern char lbl_1_data_27414[];
extern char lbl_1_data_27424[];
extern char lbl_1_data_2742C[];
extern char lbl_1_data_2743C[];
extern char lbl_1_data_27444[];
extern char lbl_1_data_27454[];
extern char lbl_1_data_2745C[];
extern char lbl_1_data_2746C[];
extern char lbl_1_data_27474[];
extern char lbl_1_data_27484[];
extern char lbl_1_data_2748C[];
extern char lbl_1_data_2749C[];
extern char lbl_1_data_274A4[];
extern char lbl_1_data_274B4[];
extern char lbl_1_data_274BC[];
extern u8 lbl_1_data_2785C[];
extern char lbl_1_data_2786C[];
extern char lbl_1_data_27870[];
extern u8 lbl_1_data_27874[];
extern char lbl_1_data_278AC[];
extern struct fn_1_900C4_lbl_1_data_27920 lbl_1_data_27920;
extern u32 lbl_1_data_27924;
extern u8 lbl_1_data_27C00[];
extern BurnerColorDef **lbl_1_data_2A8D8[];
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_34348[12];
extern const f32 lbl_1_rodata_33A8;
extern const f32 lbl_1_rodata_33AC;
extern const f32 lbl_1_rodata_33B0[84];
extern const f32 lbl_1_rodata_3500;
extern const f32 lbl_1_rodata_3504;
extern Unk_23800000 lbl_23800000[];
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D188(s16);
extern f32 lbl_8006D21C(s32);
extern s16 lbl_8006D46C(void);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern f32 lbl_8006D668(Vec3 *);
extern void lbl_8006D6FC(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006D784(void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006D848(f32);
extern void lbl_8006D9D8(Vec3 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void *lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern u32 lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DC6C(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DF44(void);
extern void *lbl_8006DFC4(void *);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1D8(Vec3 *, f32, f32, f32);
extern void lbl_8006E1F0(Vec3 *, f32, f32, f32);
extern void lbl_8006E2C0(Vec3 *, f32, f32, f32);
extern u32 lbl_801A63C0;
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;
extern Cam892FC *lbl_801A66CC;
extern u32 lbl_801A6CE0;
extern u8 *lbl_801A6D00;
extern void mathutil_mtxA_rotate_x(s16 arg0);
extern void mathutil_mtxA_rotate_y(int value);
extern void mathutil_mtxA_rotate_z(int value);
extern void *memcpy(void *, void *, u32);
extern void *memset(void *dst, int value, u32 size);
extern void qsort(void *, u32, u32, void *);
extern int sprintf(char *, const char *, ...);
extern char *strcat(char *, const char *);
extern u32 strlen(const char *);
extern int strncmp(const char *, const char *, u32);
extern char *strncpy(char *, const char *, unsigned long);

void fn_1_7EB8C(Object *arg0);
struct Car7ECB8;
void fn_1_7ECB8(struct Car7ECB8 *car, u32 part, u32 flags, f32 arg3);
void fn_1_7F1E8(void *arg0, u32 arg1, f32 arg2);
void fn_1_7F20C(void *arg0, u32 arg1, f32 arg2);
void fn_1_7F230(void *arg0, u32 arg1, f32 arg2);
void *fn_1_7F254(void *arg0, s16 arg1);
void fn_1_7F3AC(CarFn_1_7F3AC *car, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2);
u32 fn_1_7F428(u32 arg0);
void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
void *fn_1_7F58C(s16 car_type, void *car, u8 suffix, s32 initialize);
void fn_1_7F658(Sig_fn_1_7F658_Car *arg0);
void fn_1_7F934(void *arg0);
void fn_1_7F954(u32 arg0, u32 arg1);
void fn_1_7FA04(u32 arg0);
s32 fn_1_7FAA8(CarListEntry *list, s32 count);
void fn_1_7FD7C(Fn7FD7CArg *arg0);
void fn_1_7FFF0(void);
void fn_1_8001C(void);
void fn_1_80058(s8 arg0, u8 *arg1);
void fn_1_800C4(u16 arg0, u8 *arg1);
void fn_1_80130(u16 arg0, u8 *arg1);
void fn_1_8019C(void *arg0);
void fn_1_801F8(s16 arg0, void *arg1);
void fn_1_80270(void *arg0, void *arg1);
void fn_1_80294(Fn80294Entry *entry, Fn80294Car *car, s32 arg2);
void fn_1_80C18(u8 *arg0, u8 *arg1, s8 arg2);
s32 fn_1_80CC4(s32 id, s32 mode, s32 suffix, void *arg3);
void fn_1_80F1C(s32 arg0, void *arg1);
void fn_1_80F80(u32 *p, s16 idx, s16 mask);
void fn_1_810E4(u32 arg0);
void fn_1_81164(Fn81164Car *car, s16 from, s16 to);
void fn_1_81408(Fn81164Car *car, u8 fromMask, u8 toMask);
s8 fn_1_816E8(u32 base, s8 index);
s32 fn_1_8171C(s32 value);
void fn_1_8176C(u32 value);
void fn_1_81778(void);
void fn_1_817C0(void);
void fn_1_81808(void *arg0);
void fn_1_81834(u8 value, s8 index_a, s8 index_b);
s32 fn_1_81860(fn_1_81860_Obj *a, fn_1_81860_Obj *b);
s32 fn_1_818AC(fn_1_818AC_Obj *a, fn_1_818AC_Obj *b);
void fn_1_818BC(Entry818BC *entries, u32 count, s32 mode);
void fn_1_82724(void *arg0, void *arg1, CarInitInput *input, u32 count, u32 arg4);
void fn_1_82C70(void *manager, u8 index, Fn1_82C70_Car *car, Fn1_82C70_Work *work_base, u8 flag);
void *fn_1_82EDC(s16 arg0, s16 arg1, void *arg2);
F83070Car *fn_1_83070(void *arg0, u32 unused, F83070Setup *items, u32 count);
void fn_1_835E0(void *car_context, void *initial_state, void *callback_context);
void fn_1_8365C(s32 enabled);
void fn_1_83694(u8 *car);
void fn_1_83858(struct fn_1_83858_Arg0 *arg0);
void fn_1_83CB0(Sig_fn_1_83CB0_Fn183CB0Object *obj);
s8 fn_1_83D28(DistanceState *state, f32 scale);
f32 fn_1_84038(Fn184038Object *obj, s16 index, u8 use_table, f32 value);
s8 fn_1_84124(Fn184124Object *obj, s8 direction, s8 index, u8 *count);
s8 fn_1_8421C(struct fn_1_8421C_Arg0 *arg0, s8 arg1);
f32 fn_1_843BC(Fn1843BCObject *obj);
s8 fn_1_84408(CarTestCar *arg0);
s8 fn_1_84644(Fn184644Object *obj);
void *fn_1_8472C(Fn18472CObject *obj);
u8 fn_1_84794(s32 index);
s16 fn_1_847A8(s16 value, s16 divisor);
void fn_1_84860(BurnerCar *car);
void fn_1_850C4(Race8B9B8 *racer);
void fn_1_854D4(void);
void fn_1_85688(void);
void fn_1_85878(void);
void fn_1_8589C(u32 value);
s32 fn_1_858A8(s16 *a, s16 *b);
void fn_1_85934(f32 arg);
void fn_1_85C58(s32 index, f32 arg1);
void fn_1_85F70(void *car, f32 arg);
void fn_1_85F90(void *obj, f32 a, f32 b, f32 c, f32 d, int mode);
void fn_1_8616C(void);
void fn_1_86194(f32 arg);
void fn_1_861B4(void);
int fn_1_8623C(void);
u32 fn_1_86244(void);
void *fn_1_86254(int index);
u32 fn_1_8627C(s32 index);
u32 fn_1_862A8(u32 arg0, struct fn_1_862A8_Arg1 *arg1);
void fn_1_862D4(int index, RawVec3 *out);
void fn_1_8636C(int index, void *arg);
void fn_1_863E4(int index, void *arg);
void fn_1_8645C(int index, void *arg);
u32 fn_1_864E8(int index);
u32 fn_1_864FC(u32 index);
u32 fn_1_86514(int index);
f32 fn_1_8652C(int index);
f32 fn_1_86544(s32 index);
f32 fn_1_8655C(int index);
f32 fn_1_86574(int index);
void fn_1_8658C(int index, RawVec3 *out);
u8 fn_1_86624(void);
u8 fn_1_86634(int index);
u16 fn_1_8664C(int index);
u8 fn_1_86678(int index);
s8 fn_1_86690(s8 index);
s32 fn_1_866B4(u32 arg0);
u32 fn_1_8677C(u32 arg0);
u32 fn_1_867CC(u32 arg0, struct fn_1_867CC_Arg1 *arg1);
f32 fn_1_867F8(int index);
u8 fn_1_86810(int index);
u8 fn_1_8682C(int index);
s16 fn_1_8683C(int index);
fn_1_86854_Entry *fn_1_86854(int id);
void *fn_1_868C0(s8 index);
void *fn_1_86900(s32 arg0);
void fn_1_869B0(int index, u32 *out);
void fn_1_869E0(int index, u32 *out);
u8 fn_1_86A10(u32 arg0);
f32 fn_1_86A2C(fn_1_86A2C_Car *car);
f32 fn_1_86A2C_old(void * arg0);
void fn_1_86E08(fn_1_86E08_Car *car);
void fn_1_87074(void);
void fn_1_870BC(Car870BC *car, s8 a, s32 b, s16 c, u8 d, f32 x);
void fn_1_87238(struct fn_1_87238_Car *car, s8 index, f32 f1);
void fn_1_87448(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, int flag, f32 f);
void fn_1_875B4(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, f32 value);
void fn_1_875EC(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, f32 value);
void fn_1_87610(Fn187610Object *object, Fn187610Data *data);
void fn_1_87750(Fn187750Object *object);
void fn_1_877E8(Fn187750Object *object);
void fn_1_87880(Fn187750Object *object);
void fn_1_87918(Fn187750Object *object);
void fn_1_879B0(Fn187750Object *object);
void fn_1_87AD8(Fn187750Object *object);
void fn_1_87B70(Fn187750Object *object);
void fn_1_87C08(Fn187750Object *object);
void fn_1_87CA0(Fn187750Object *object);
void fn_1_87D38(Fn187750Object *object);
void fn_1_87DD0(Fn187750Object *object);
void fn_1_87E68(Fn187750Object *object);
void fn_1_87F00(Fn187750Object *object);
void fn_1_87F98(Fn187750Object *object);
void fn_1_88030(Fn187750Object *object);
void fn_1_880C8(Fn187750Object *object);
void fn_1_88160(Fn187750Object *object);
void fn_1_881F8(Fn187750Object *object);
void fn_1_88290(Fn187750Object *object);
void fn_1_88328(Fn187750Object *object);
void fn_1_883C0(Fn187750Object *object);
void fn_1_88458(Fn187750Object *object);
void fn_1_8856C(Fn187750Object *object);
void fn_1_88604(Fn187750Object *object);
void fn_1_8869C(Fn187750Object *object);
void fn_1_88734(Fn187750Object *object);
void fn_1_887CC(Fn187750Object *object);
void fn_1_88864(Fn187750Object *object);
void fn_1_888FC(Fn187750Object *object);
void fn_1_88994(Fn187750Object *object);
void fn_1_88A2C(Fn187750Object *object);
void fn_1_88AC4(Fn187750Object *object);
void fn_1_88B5C(Fn187750Object *object);
void fn_1_88BF4(Fn187750Object *object);
void fn_1_88C8C(Fn187750Object *object);
void fn_1_88D24(Fn187750Object *object);
void fn_1_88DBC(Fn187750Object *object);
void fn_1_88E54(Fn187750Object *object);
void fn_1_88EEC(Fn187750Object *object);
void fn_1_88F84(Fn187750Object *object);
void fn_1_8901C(Fn187750Object *car);
void fn_1_892CC(V3 *dst, V3 *src, u32 a, u32 b);
void fn_1_892E8(u32 *p, u32 val);
void fn_1_892FC(Car892FC *car, f32 *out_c, f32 *out_2c);
void fn_1_8A168(void *arg0);
void fn_1_8A190(void *arg0, void *arg1);
void fn_1_8A1B4(Car8A1B4 *car, s32 reset, Racer8A1B4 *racer);
void fn_1_8B880(void);
void fn_1_8B8A4(void *arg);
void fn_1_8B9B8(Race8B9B8 *race);
u8 fn_1_8C3EC(void);
u8 fn_1_8C3FC(void);
f32 fn_1_8C40C(void);
f32 fn_1_8C44C(void);
f32 fn_1_8C48C(u32 index);
f32 fn_1_8C4BC(u32 index);
f32 fn_1_8C4EC(u32 index);
f32 fn_1_8C51C(u32 index);
f32 fn_1_8C54C(u32 index);
f32 fn_1_8C57C(u32 index);
f32 fn_1_8C5AC(u32 index);
u32 fn_1_8C5DC(u32 index);
u32 fn_1_8C60C(u32 index);
u32 fn_1_8C63C(u32 index);
u32 fn_1_8C66C(u32 index);
f32 fn_1_8C6A0(u32 index);
u32 fn_1_8C6D4(u32 index);
u32 fn_1_8C704(u32 index);
f32 fn_1_8C734(u32 index);
f32 fn_1_8C764(u32 index);
f32 fn_1_8C794(u32 index);
u8 fn_1_8C7C4(u32 index);
u8 fn_1_8C7F4(u32 index);
u16 fn_1_8C824(u32 index);
f32 fn_1_8C854(u32 index);
u32 fn_1_8C884(u32 arg0);
f32 fn_1_8C8C4(u32 index);
f32 fn_1_8C8DC(u32 index);
f32 fn_1_8C8F4(u32 index);
f32 fn_1_8C90C(s32 index);
f32 fn_1_8C924(s32 index);
s32 fn_1_8C93C(s32 index);
s32 fn_1_8C968(s32 index);
Obj_1_bss_6D838_Target *fn_1_8C994(void);
u32 fn_1_8C9A4(void);
u32 fn_1_8C9B8(void);
u32 *fn_1_8C9CC(void);
u32 *fn_1_8C9E0(void);
s8 *fn_1_8C9F4(void);
u32 *fn_1_8CA00(void);
u32 fn_1_8CA0C(void);
u32 fn_1_8CA20(void);
u32 fn_1_8CA34(void);
u32 fn_1_8CA48(void);
u32 fn_1_8CA5C(void);
f32 fn_1_8CA70(u32 a, s32 b);
f32 fn_1_8CAF4(u32 a, s32 b);
void fn_1_8CB78(EntryTable *table);
void fn_1_8CC04(CarDbgObj *obj, s8 sel, s16 x, s16 y, u32 value, f32 scale);
void fn_1_8CED0(Fn1_8CED0State *state, u16 arg1, u16 arg2);
void fn_1_8D0A4(Fn1_8D0A4State *state);
void fn_1_8D168(Fn1_8D168State *state);
void fn_1_8D1C8(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg);
void fn_1_8D1EC(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg);
s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
u32 fn_1_8D3F8(Fn1_8D3F8Car *car, u32 arg1, u32 (*callback)(u32), u32 arg3);
u32 fn_1_8D5F0(s16 index);
s16 fn_1_8D640(s16 index);
u32 fn_1_8D690(s16 arg0);
u32 fn_1_8D72C(s16 index);
s16 fn_1_8D7C8(void);
void fn_1_8D894(Obj_1_bss_6D838_Target *car);
void fn_1_8D988(void);
void fn_1_8DAB4(void);
u8 fn_1_8DB94(void);
void fn_1_8DBA4(u8 value);
void fn_1_8DBB0(void);
void fn_1_8DD54(void);
void fn_1_8E084(SlotCar *car, s32 *value, s32 row);
void fn_1_8E188(void);
void fn_1_8E1E8(void);
void fn_1_8E244(void *arg0);
void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
void fn_1_8E448(GlobalObject *obj, u32 value);
void fn_1_8E450(u32 value);
void fn_1_8E480(void);
void fn_1_8E4A4(s32 id, u32 flags, void *arg);
void fn_1_8E728(struct Unk_1_8E728 *p, u8 arg1);
void fn_1_8E7D0(Fn8E7D0Car *car, s32 idx, u32 mask, u32 mask2);
void fn_1_8F198(Fn1_8F198_Object *obj, s32 idx, u32 mask, u32 mask2);
void fn_1_8F45C(Fn1_8F45C_Object *obj);
void fn_1_8F494(Fn1_8F494_Object *obj);
void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
void fn_1_8F62C(Fn8F62CCar *car);
void fn_1_8FE74(Fn8FE74Obj *arg0, Fn8FE74Entry *arg1, s32 arg2);
u32 fn_1_900B4(void);
void fn_1_900C4(void);
void fn_1_9012C(Fn9012CCar *car);
void fn_1_913FC(Fn1913FCCar *car);
void fn_1_924CC(void);
void fn_1_9250C(void *arg0);
void fn_1_92530(void *arg0);
void fn_1_92554(Car92554 *car, s32 arg1);
void fn_1_933D8(CarObject *arg0, EventObject *arg1, u32 arg2);
void fn_1_934CC(CarObject *arg0, EventObject *arg1, u32 arg2);
void fn_1_935E4(Fn935E4Car *arg0, void *arg1, void *arg2, f32 arg3);
void fn_1_93734(CarObject_93734 *car, void *name);
void fn_1_943F8(CarObject *car, void *name, f32 blend);
s32 fn_1_950E8(Fn1950E8Data *data);
s32 fn_1_95120(Fn195120Owner *owner);
void fn_1_95158(Fn195158Car *car);
void fn_1_95210(void *arg0);
void fn_1_95238(u32 arg0, EventList_95158 *arg1);
void fn_1_9550C(Owner *owner, Config *config);
void fn_1_956B8(Fn1956B8Data *data);
void fn_1_956EC(s32 id, u32 mask);
void fn_1_95950(u32 arg0);
void fn_1_95EF0(void *arg0, s32 arg_sp0);
void fn_1_96130(void *arg0);
void fn_1_9617C(CarResourceState *car, void *resource);
void fn_1_961F0(Fn1961F0Owner *owner);
void fn_1_96230(Fn196230Obj *obj, s32 idx, u32 mask1, u32 mask2, s32 flag);
void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2);
void fn_1_96664(void *arg0, void *arg1, void *arg2);
void fn_1_966A0(Fn1966A0Object *object);
void fn_1_967A8(Fn1967A8Object *arg0, void *arg1);
void fn_1_968FC(Fn1968FCObject *object);
u16 fn_1_96968(Fn196968Object *object, void *arg1);
u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
void fn_1_96AE8(void *base, void *arg1);
u16 fn_1_96B14(void *base, void *arg1, s32 index);
u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
void fn_1_96C40(void *arg0);
void fn_1_96F20(CarData_96F20 *car);
s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2);
void fn_1_97204(void *arg0, void *arg1);
void fn_1_9724C(void);
void fn_1_97288(struct fn_1_97288_Arg0 *arg0, f32 arg1);
void fn_1_977BC(Rob *rob, RobView *arg1);
s16 fn_1_97F1C(Fn197F1CObject *object, s16 index);
u32 fn_1_97F80(Fn197F80Object *rob, const char *name);
s32 fn_1_98104(Fn198104Obj *obj);
s32 fn_1_9818C(u32 arg0);

/* TU A data */
/* TU A .rodata objects defined at file scope (parse time, before every literal) */
/* read by coli/game functions (fn_1_239C4, fn_1_29A0C) */
const f32 lbl_1_rodata_3508[4] = {3.0f, 2.0f, 2.0f, 1.5f};
/* TU A .bss (6D820..6E960), retail address order. Types from the uses in main's units (a2 fixes merged). */
static u8 lbl_1_bss_6D820 = 0;
static GlobalObject *lbl_1_bss_6D824 = 0;
static u32 lbl_1_bss_6D828;
u32 lbl_1_bss_6D82C;
static u32 lbl_1_bss_6D830;
static u32 lbl_1_bss_6D834;
static u32 lbl_1_bss_6D850;
static u8 lbl_1_bss_6D854;
static s32 lbl_1_bss_6D858;
static Fn80294Item lbl_1_bss_6D85C;
static u32 lbl_1_bss_6D864;
static u8 lbl_1_bss_6D868[4];
static s32 lbl_1_bss_6D86C[4];
static s32 lbl_1_bss_6D87C[30];
static s32 lbl_1_bss_6D8F4[30];
static u8 lbl_1_bss_6D96C;
static u32 lbl_1_bss_6D970;
static u8 lbl_1_bss_6D980[32];
static u8 lbl_1_bss_6D9A0[0x20];
static s32 lbl_1_bss_6D9C0[0x1E];
static u8 lbl_1_bss_6DA38;
static u8 lbl_1_bss_6DA3C[0x20];
static s8 lbl_1_bss_6DA5C[0x1E];
static f32 lbl_1_bss_6DA80[440];
static f32 lbl_1_bss_6E160[435];
static u16 lbl_1_bss_6E82C[30][5];
static struct { CarList *list; u32 texture; } lbl_1_bss_6E958;

/* TU A .data (1F1D8..209C0), retail order */
static char lbl_1_data_1F1D8[8] = "RGAZE";
static char lbl_1_data_1F1E0[8] = "WCAT";
static char lbl_1_data_1F1E8[8] = "GFOX";
static char lbl_1_data_1F1F0[8] = "ITIGER";
static char lbl_1_data_1F1F8[8] = "FSTING";
static char lbl_1_data_1F200[8] = "WGOOSE";
static char lbl_1_data_1F208[8] = "BFALCON";
static char lbl_1_data_1F210[8] = "DCLAW";
static char lbl_1_data_1F218[8] = "GSTAR";
static char lbl_1_data_1F220[4] = "LWY";
static char lbl_1_data_1F224[8] = "MWOLF";
static char lbl_1_data_1F22C[8] = "SPIRA";
static char lbl_1_data_1F234[8] = "DANC";
static char lbl_1_data_1F23C[8] = "AROBIN";
static char lbl_1_data_1F244[8] = "BFANG";
static char lbl_1_data_1F24C[8] = "SPHAN";
static char lbl_1_data_1F254[8] = "GPAN";
static char lbl_1_data_1F25C[8] = "HSPEED";
static char lbl_1_data_1F264[8] = "SANG";
static char lbl_1_data_1F26C[8] = "KMETE";
static char lbl_1_data_1F274[8] = "QMETE";
static char lbl_1_data_1F27C[8] = "TNORI";
static char lbl_1_data_1F284[8] = "NTHUN";
static char lbl_1_data_1F28C[8] = "WBOAR";
static char lbl_1_data_1F294[8] = "HHAWK";
static char lbl_1_data_1F29C[8] = "WWASP";
static char lbl_1_data_1F2A4[4] = "MTY";
static char lbl_1_data_1F2A8[8] = "MHURR";
static char lbl_1_data_1F2B0[8] = "CBEAR";
static char lbl_1_data_1F2B8[8] = "BBULL";
static char lbl_1_data_1F2C0[8] = "DARKS";
static char lbl_1_data_1F2C8[8] = "FATS";
static char lbl_1_data_1F2D0[8] = "SCARP";
static char lbl_1_data_1F2D8[8] = "PINKS";
static char lbl_1_data_1F2E0[8] = "MGULL";
static char lbl_1_data_1F2E8[8] = "SRAT";
static char lbl_1_data_1F2F0[8] = "SMOON";
static char lbl_1_data_1F2F8[8] = "PRABBIT";
static char lbl_1_data_1F300[8] = "GTAXI";
static char lbl_1_data_1F308[8] = "RROCK";
static char lbl_1_data_1F310[8] = "RAINP";
char *lbl_1_data_1F318[41] = {lbl_1_data_1F1D8, lbl_1_data_1F1E0, lbl_1_data_1F1E8, lbl_1_data_1F1F0, lbl_1_data_1F1F8, lbl_1_data_1F200, lbl_1_data_1F208, lbl_1_data_1F210, lbl_1_data_1F218, lbl_1_data_1F220, lbl_1_data_1F224, lbl_1_data_1F22C, lbl_1_data_1F234, lbl_1_data_1F23C, lbl_1_data_1F244, lbl_1_data_1F24C, lbl_1_data_1F254, lbl_1_data_1F25C, lbl_1_data_1F264, lbl_1_data_1F26C, lbl_1_data_1F274, lbl_1_data_1F27C, lbl_1_data_1F284, lbl_1_data_1F28C, lbl_1_data_1F294, lbl_1_data_1F29C, lbl_1_data_1F2A4, lbl_1_data_1F2A8, lbl_1_data_1F2B0, lbl_1_data_1F2B8, lbl_1_data_1F2C0, lbl_1_data_1F2C8, lbl_1_data_1F2D0, lbl_1_data_1F2D8, lbl_1_data_1F2E0, lbl_1_data_1F2E8, lbl_1_data_1F2F0, lbl_1_data_1F2F8, lbl_1_data_1F300, lbl_1_data_1F308, lbl_1_data_1F310};
static char lbl_1_data_1F3BC[8] = "rgaze";
static char lbl_1_data_1F3C4[8] = "wcat";
static char lbl_1_data_1F3CC[8] = "gfox";
static char lbl_1_data_1F3D4[8] = "itiger";
static char lbl_1_data_1F3DC[8] = "fsting";
static char lbl_1_data_1F3E4[8] = "wgoose";
static char lbl_1_data_1F3EC[8] = "bfalcon";
static char lbl_1_data_1F3F4[8] = "dclaw";
static char lbl_1_data_1F3FC[8] = "gstar";
static char lbl_1_data_1F404[4] = "lwy";
static char lbl_1_data_1F408[8] = "mwolf";
static char lbl_1_data_1F410[8] = "spira";
static char lbl_1_data_1F418[8] = "danc";
static char lbl_1_data_1F420[8] = "arobin";
static char lbl_1_data_1F428[8] = "bfang";
static char lbl_1_data_1F430[8] = "sphan";
static char lbl_1_data_1F438[8] = "gpan";
static char lbl_1_data_1F440[8] = "hspeed";
static char lbl_1_data_1F448[8] = "sang";
static char lbl_1_data_1F450[8] = "kmete";
static char lbl_1_data_1F458[8] = "qmete";
static char lbl_1_data_1F460[8] = "tnori";
static char lbl_1_data_1F468[8] = "nthun";
static char lbl_1_data_1F470[8] = "wboar";
static char lbl_1_data_1F478[8] = "hhawk";
static char lbl_1_data_1F480[8] = "wwasp";
static char lbl_1_data_1F488[4] = "mty";
static char lbl_1_data_1F48C[8] = "mhurr";
static char lbl_1_data_1F494[8] = "cbear";
static char lbl_1_data_1F49C[8] = "bbull";
static char lbl_1_data_1F4A4[8] = "darks";
static char lbl_1_data_1F4AC[8] = "fats";
static char lbl_1_data_1F4B4[8] = "scarp";
static char lbl_1_data_1F4BC[8] = "pinks";
static char lbl_1_data_1F4C4[8] = "mgull";
static char lbl_1_data_1F4CC[8] = "srat";
static char lbl_1_data_1F4D4[8] = "smoon";
static char lbl_1_data_1F4DC[8] = "prabbit";
static char lbl_1_data_1F4E4[8] = "gtaxi";
static char lbl_1_data_1F4EC[8] = "rrock";
static char lbl_1_data_1F4F4[8] = "rainp";
static char *lbl_1_data_1F4FC[41] = {lbl_1_data_1F3BC, lbl_1_data_1F3C4, lbl_1_data_1F3CC, lbl_1_data_1F3D4, lbl_1_data_1F3DC, lbl_1_data_1F3E4, lbl_1_data_1F3EC, lbl_1_data_1F3F4, lbl_1_data_1F3FC, lbl_1_data_1F404, lbl_1_data_1F408, lbl_1_data_1F410, lbl_1_data_1F418, lbl_1_data_1F420, lbl_1_data_1F428, lbl_1_data_1F430, lbl_1_data_1F438, lbl_1_data_1F440, lbl_1_data_1F448, lbl_1_data_1F450, lbl_1_data_1F458, lbl_1_data_1F460, lbl_1_data_1F468, lbl_1_data_1F470, lbl_1_data_1F478, lbl_1_data_1F480, lbl_1_data_1F488, lbl_1_data_1F48C, lbl_1_data_1F494, lbl_1_data_1F49C, lbl_1_data_1F4A4, lbl_1_data_1F4AC, lbl_1_data_1F4B4, lbl_1_data_1F4BC, lbl_1_data_1F4C4, lbl_1_data_1F4CC, lbl_1_data_1F4D4, lbl_1_data_1F4DC, lbl_1_data_1F4E4, lbl_1_data_1F4EC, lbl_1_data_1F4F4};
static void (*lbl_1_data_1F5A0[41])(Fn187750Object *) = {fn_1_87750, fn_1_877E8, fn_1_87880, fn_1_87918, fn_1_879B0, fn_1_87AD8, fn_1_87B70, fn_1_87C08, fn_1_87CA0, fn_1_87D38, fn_1_87DD0, fn_1_87E68, fn_1_87F00, fn_1_87F98, fn_1_88030, fn_1_880C8, fn_1_88160, fn_1_881F8, fn_1_88290, fn_1_88328, fn_1_883C0, fn_1_88458, fn_1_8856C, fn_1_88604, fn_1_8869C, fn_1_88734, fn_1_887CC, fn_1_88864, fn_1_888FC, fn_1_88994, fn_1_88A2C, fn_1_88AC4, fn_1_88B5C, fn_1_88BF4, fn_1_88C8C, fn_1_88D24, fn_1_88DBC, fn_1_88E54, fn_1_88EEC, fn_1_88F84, fn_1_8901C};
static u8 lbl_1_data_1F644[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F650[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F65C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F668[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F674[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F680[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F68C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F698[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6A4[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6B0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6BC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6C8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6D4[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6E0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6EC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F6F8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F704[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F710[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F71C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F728[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F734[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F740[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F74C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F758[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F764[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F770[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F77C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F788[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F794[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F7A0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F7AC[24] = {0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F7C4[24] = {0x00, 0x03, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F7DC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F7E8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F7F4[168] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F89C[168] = {0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x02, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x03, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x05, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x06, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x08, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x09, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0A, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0B, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F944[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F950[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F95C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F968[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F974[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F980[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F98C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F998[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9A4[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9B0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9BC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9C8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9D4[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9E0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9EC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1F9F8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA04[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA10[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA1C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA28[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA34[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA40[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA4C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA58[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA64[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA70[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA7C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA88[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FA94[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAA0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAAC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAB8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAC4[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAD0[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FADC[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAE8[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FAF4[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB00[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB0C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB18[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB24[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB30[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB3C[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB48[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static u8 lbl_1_data_1FB54[12] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
/* 0xFFFF-terminated u16 list, the last entry of lbl_1_data_1FB6C points to it */
static u16 lbl_1_data_1FB60[6] = {0xFFFF, 0, 0, 0, 0, 0};
/* read by car_colchg.rel */
void *lbl_1_data_1FB6C[82] = {lbl_1_data_1F644, lbl_1_data_1F65C, lbl_1_data_1F674, lbl_1_data_1F68C, lbl_1_data_1F6A4, lbl_1_data_1F6BC, lbl_1_data_1F6D4, lbl_1_data_1F6EC, lbl_1_data_1F704, lbl_1_data_1F71C, lbl_1_data_1F734, lbl_1_data_1F74C, lbl_1_data_1F764, lbl_1_data_1F77C, lbl_1_data_1F794, lbl_1_data_1F7AC, lbl_1_data_1F7DC, lbl_1_data_1F7F4, lbl_1_data_1F944, lbl_1_data_1F95C, lbl_1_data_1F974, lbl_1_data_1F98C, lbl_1_data_1F9A4, lbl_1_data_1F9BC, lbl_1_data_1F9D4, lbl_1_data_1F9EC, lbl_1_data_1FA04, lbl_1_data_1FA1C, lbl_1_data_1FA34, lbl_1_data_1FA4C, lbl_1_data_1FA64, lbl_1_data_1FA7C, lbl_1_data_1FA94, lbl_1_data_1FAAC, lbl_1_data_1FAC4, lbl_1_data_1FADC, lbl_1_data_1FAF4, lbl_1_data_1FB0C, lbl_1_data_1FB24, lbl_1_data_1FB3C, lbl_1_data_1FB54, lbl_1_data_1F650, lbl_1_data_1F668, lbl_1_data_1F680, lbl_1_data_1F698, lbl_1_data_1F6B0, lbl_1_data_1F6C8, lbl_1_data_1F6E0, lbl_1_data_1F6F8, lbl_1_data_1F710, lbl_1_data_1F728, lbl_1_data_1F740, lbl_1_data_1F758, lbl_1_data_1F770, lbl_1_data_1F788, lbl_1_data_1F7A0, lbl_1_data_1F7C4, lbl_1_data_1F7E8, lbl_1_data_1F89C, lbl_1_data_1F950, lbl_1_data_1F968, lbl_1_data_1F980, lbl_1_data_1F998, lbl_1_data_1F9B0, lbl_1_data_1F9C8, lbl_1_data_1F9E0, lbl_1_data_1F9F8, lbl_1_data_1FA10, lbl_1_data_1FA28, lbl_1_data_1FA40, lbl_1_data_1FA58, lbl_1_data_1FA70, lbl_1_data_1FA88, lbl_1_data_1FAA0, lbl_1_data_1FAB8, lbl_1_data_1FAD0, lbl_1_data_1FAE8, lbl_1_data_1FB00, lbl_1_data_1FB18, lbl_1_data_1FB30, lbl_1_data_1FB48, lbl_1_data_1FB60};
static char lbl_1_data_1FCB4[4] = "NON";
static char lbl_1_data_1FCB8[12] = "MASTER RECV";
static char lbl_1_data_1FCC4[12] = "MASTER SEND";
static char lbl_1_data_1FCD0[12] = "SLAVE SEND";
static char lbl_1_data_1FCDC[12] = "SLAVE RECV";
static char lbl_1_data_1FCE8[8] = "INIT";
static char lbl_1_data_1FCF0[8] = "TEST";
static char lbl_1_data_1FCF8[8] = "TESTEND";
static char lbl_1_data_1FD00[8] = "SETUP";
static char lbl_1_data_1FD08[12] = "SETUP_DONE";
static char lbl_1_data_1FD14[16] = "SETUP_COUNTER";
static char lbl_1_data_1FD24[16] = "SETUP_CNT_DONE";
static char lbl_1_data_1FD34[8] = "UNLINK";
static char lbl_1_data_1FD3C[8] = "COIN";
static char lbl_1_data_1FD44[12] = "ENTRY_WAIT";
static char lbl_1_data_1FD50[12] = "CHALLENGER";
static char lbl_1_data_1FD5C[16] = "CHALLENGER_OK";
static char lbl_1_data_1FD6C[8] = "ENTRY";
static char lbl_1_data_1FD74[12] = "ENTRY_OK";
static char lbl_1_data_1FD80[12] = "SINGLECHECK";
static char lbl_1_data_1FD8C[16] = "SINGLECHECK_OK";
static char lbl_1_data_1FD9C[8] = "COURSE";
static char lbl_1_data_1FDA4[12] = "COURSE_OK";
static char lbl_1_data_1FDB0[12] = "COURSE_DATA";
static char lbl_1_data_1FDBC[16] = "COURSE_DATA_OK";
static char lbl_1_data_1FDCC[8] = "MACHINE";
static char lbl_1_data_1FDD4[12] = "MACHINE_OK";
static char lbl_1_data_1FDE0[8] = "CONFIG";
static char lbl_1_data_1FDE8[12] = "CONFIG_OK";
static char lbl_1_data_1FDF4[16] = "COUNTERADJUST";
static char lbl_1_data_1FE04[12] = "LINKWAIT";
static char lbl_1_data_1FE10[12] = "LINKWAITOK";
static char lbl_1_data_1FE1C[8] = "LINKSEL";
static char lbl_1_data_1FE24[20] = "LINKDELIVERYSTART";
static char lbl_1_data_1FE38[16] = "LINKDELIVERY";
static char lbl_1_data_1FE48[16] = "LINKDELIVERYOK";
static char lbl_1_data_1FE58[12] = "LINKSELOK";
static char lbl_1_data_1FE64[12] = "COURSEVIEW";
static char lbl_1_data_1FE70[16] = "COURSEVIEW_OK";
static char lbl_1_data_1FE80[8] = "LINKREQ";
static char lbl_1_data_1FE88[12] = "LINKSTANDBY";
static char lbl_1_data_1FE94[8] = "LINKOK";
static char lbl_1_data_1FE9C[8] = "LINK";
static char lbl_1_data_1FEA4[8] = "PAUSE";
static void *lbl_1_data_1FEAC[50] = {(void *)0x4552524F, (void *)0x52000000, lbl_1_data_1FCB4, lbl_1_data_1FCB8, lbl_1_data_1FCC4, lbl_1_data_1FCD0, lbl_1_data_1FCDC, lbl_1_data_1FCE8, lbl_1_data_1FCF0, lbl_1_data_1FCF8, lbl_1_data_1FD00, lbl_1_data_1FD08, lbl_1_data_1FD14, lbl_1_data_1FD24, lbl_1_data_1FD34, lbl_1_data_1FD3C, lbl_1_data_1FD44, lbl_1_data_1FD50, lbl_1_data_1FD5C, lbl_1_data_1FD6C, lbl_1_data_1FD74, lbl_1_data_1FD80, lbl_1_data_1FD8C, lbl_1_data_1FD9C, lbl_1_data_1FDA4, lbl_1_data_1FDB0, lbl_1_data_1FDBC, lbl_1_data_1FDCC, lbl_1_data_1FDD4, lbl_1_data_1FDE0, lbl_1_data_1FDE8, lbl_1_data_1FDF4, lbl_1_data_1FE04, lbl_1_data_1FE10, lbl_1_data_1FE1C, lbl_1_data_1FE24, lbl_1_data_1FE38, lbl_1_data_1FE48, lbl_1_data_1FE58, lbl_1_data_1FE64, lbl_1_data_1FE70, lbl_1_data_1FE80, lbl_1_data_1FE88, lbl_1_data_1FE94, lbl_1_data_1FE9C, lbl_1_data_1FEA4, lbl_1_data_1FEAC, (void *)0x10507, (void *)0x80C0D10, (void *)0x12170000};  /* fzgx-allow: A2 retail table words, not addresses */
static char lbl_1_data_1FF74[12] = "OVERTAKE";
static char lbl_1_data_1FF80[8] = "JUMP";
static char lbl_1_data_1FF88[12] = "ENEMYHIT";
static char lbl_1_data_1FF94[8] = "WALLHIT";
static char lbl_1_data_1FF9C[12] = "SIDEBYSIDE";
static char lbl_1_data_1FFA8[8] = "START";
static char lbl_1_data_1FFB0[8] = "GOAL";
static void *lbl_1_data_1FFB8[9] = {(void *)0x4C415000, lbl_1_data_1FF74, lbl_1_data_1FF80, lbl_1_data_1FF88, lbl_1_data_1FF94, lbl_1_data_1FF9C, lbl_1_data_1FFA8, lbl_1_data_1FFB0, lbl_1_data_1FFB8};  /* fzgx-allow: A2 retail table words, not addresses */
static u8 lbl_1_data_1FFDC[4] = {0x06, 0x08, 0x00, 0x00};
static f32 lbl_1_data_1FFE0 = 5.0f;
static char lbl_1_data_1FFE4[12] = "vehicle/";
static char lbl_1_data_1FFF0[8] = "car.c";
static char lbl_1_data_1FFF8[4] = "..";
static char lbl_1_data_1FFFC[12] = "Red Gazelle";
static char lbl_1_data_20008[16] = "\203\214\203b\203h\203K\203[\203\213";
static char lbl_1_data_20018[12] = "White Cat";
static char lbl_1_data_20024[20] = "\203z\203\217\203C\203g\203L\203\203\203b\203g";
static char lbl_1_data_20038[12] = "Golden Fox";
static char lbl_1_data_20044[24] = "\203S\201[\203\213\203f\203\223\203t\203H\203b\203N\203X";
static char lbl_1_data_2005C[12] = "Iron Tiger";
static char lbl_1_data_20068[20] = "\203A\203C\203A\203\223\203^\203C\203K\201[";
static char lbl_1_data_2007C[16] = "Fire Stingray";
static char lbl_1_data_2008C[24] = "\203t\203@\203C\203A\203X\203e\203B\203\223\203O\203\214\203C";
static char lbl_1_data_200A4[12] = "Wild Goose";
static char lbl_1_data_200B0[16] = "\203\217\203C\203\213\203h\203O\201[\203X";
static char lbl_1_data_200C0[12] = "Blue Falcon";
static char lbl_1_data_200CC[20] = "\203u\203\213\201[\203t\203@\203\213\203R\203\223";
static char lbl_1_data_200E0[12] = "Deep Claw";
static char lbl_1_data_200EC[16] = "\203f\203B\201[\203v\203N\203\215\201[";
static char lbl_1_data_200FC[12] = "Great Star";
static char lbl_1_data_20108[16] = "\203O\203\214\201[\203g\203X\203^\201[";
static char lbl_1_data_20118[16] = "Little Wyvern";
static char lbl_1_data_20128[20] = "\203\212\203g\203\213\203\217\203C\203o\201[\203\223";
static char lbl_1_data_2013C[12] = "Mad Wolf";
static char lbl_1_data_20148[16] = "\203}\203b\203h\203E\203\213\203t";
static char lbl_1_data_20158[16] = "Super Piranha";
static char lbl_1_data_20168[20] = "\203X\201[\203p\201[\203s\203\211\203j\203A";
static char lbl_1_data_2017C[16] = "Death Anchor";
static char lbl_1_data_2018C[16] = "\203f\203X\203A\203\223\203J\201[";
static char lbl_1_data_2019C[12] = "Astro Robin";
static char lbl_1_data_201A8[16] = "\203A\203X\203g\203\215\203\215\203r\203\223";
static char lbl_1_data_201B8[12] = "Big Fang";
static char lbl_1_data_201C4[16] = "\203r\203b\203O\203t\203@\203\223\203O";
static char lbl_1_data_201D4[16] = "Sonic Phantom";
static char lbl_1_data_201E4[20] = "\203\\\203j\203b\203N\203t\203@\203\223\203g\203\200";
static char lbl_1_data_201F8[16] = "Green Panther";
static char lbl_1_data_20208[20] = "\203O\203\212\201[\203\223\203p\203\223\203T\201[";
static char lbl_1_data_2021C[16] = "Hyper Speeder";
static char lbl_1_data_2022C[20] = "\203n\203C\203p\201[\203X\203s\201[\203_\201[";
static char lbl_1_data_20240[16] = "Space Angler";
static char lbl_1_data_20250[20] = "\203X\203y\201[\203X\203A\203\223\203O\203\211\201[";
static char lbl_1_data_20264[12] = "King Meteor";
static char lbl_1_data_20270[16] = "\203L\203\223\203O\203\201\203e\203I";
static char lbl_1_data_20280[16] = "Queen Meteor";
static char lbl_1_data_20290[16] = "\203N\203C\201[\203\223\203\201\203e\203I";
static char lbl_1_data_202A0[16] = "Twin Noritta";
static char lbl_1_data_202B0[16] = "\203c\203C\203\223\203m\203\212\203b\203^";
static char lbl_1_data_202C0[16] = "Night Thunder";
static char lbl_1_data_202D0[16] = "\203i\203C\203g\203T\203\223\203_\201[";
static char lbl_1_data_202E0[12] = "Wild Boar";
static char lbl_1_data_202EC[16] = "\203\217\203C\203\213\203h\203{\203A";
static char lbl_1_data_202FC[12] = "Blood Hawk";
static char lbl_1_data_20308[16] = "\203u\203\211\203b\203h\203z\201[\203N";
static char lbl_1_data_20318[12] = "Wonder Wasp";
static char lbl_1_data_20324[16] = "\203\217\203\223\203_\201[\203\217\203X\203v";
static char lbl_1_data_20334[16] = "Mighty Typhoon";
static char lbl_1_data_20344[24] = "\203}\203C\203e\203B\201[\203^\203C\203t\201[\203\223";
static char lbl_1_data_2035C[20] = "Mighty Hurricane";
static char lbl_1_data_20370[20] = "\203}\203C\203e\203B\203n\203\212\203P\201[\203\223";
static char lbl_1_data_20384[12] = "Crazy Bear";
static char lbl_1_data_20390[16] = "\203N\203\214\203C\203W\201[\203x\203A";
static char lbl_1_data_203A0[12] = "Black Bull";
static char lbl_1_data_203AC[16] = "\203u\203\211\203b\203N\203u\203\213";
static char lbl_1_data_203BC[16] = "Dark Schneider";
static char lbl_1_data_203CC[20] = "\203_\201[\203N\203V\203\205\203i\203C\203_\201[";
static char lbl_1_data_203E0[12] = "Fat Shark";
static char lbl_1_data_203EC[20] = "\203t\203@\203b\203g\203V\203\203\201[\203N";
static char lbl_1_data_20400[16] = "Cosmic Dolphin";
static char lbl_1_data_20410[24] = "\203R\203Y\203~\203b\203N\203h\203\213\203t\203B\203\223";
static char lbl_1_data_20428[12] = "Pink Spider";
static char lbl_1_data_20434[20] = "\203s\203\223\203N\203X\203p\203C\203_\201[";
static char lbl_1_data_20448[16] = "Magic Seagull";
static char lbl_1_data_20458[20] = "\203}\203W\203b\203N\203V\201[\203K\203\213";
static char lbl_1_data_2046C[12] = "Silver Rat";
static char lbl_1_data_20478[16] = "\203V\203\213\203o\201[\203\211\203b\203g";
static char lbl_1_data_20488[12] = "Spark Moon";
static char lbl_1_data_20494[16] = "\203X\203p\201[\203N\203\200\201[\203\223";
static char lbl_1_data_204A4[12] = "Bunny Flash";
static char lbl_1_data_204B0[20] = "\203o\203j\201[\203t\203\211\203b\203V\203\205";
static char lbl_1_data_204C4[12] = "Groovy Taxi";
static char lbl_1_data_204D0[20] = "\203O\203\213\201[\203r\201[\203^\203N\203V\201[";
static char lbl_1_data_204E4[16] = "Rolling Turtle";
static char lbl_1_data_204F4[20] = "\203\215\201[\203\212\203\223\203O\203^\201[\203g\203\213";
static char lbl_1_data_20508[16] = "Rainbow Phoenix";
static char lbl_1_data_20518[24] = "\203\214\203C\203\223\203{\201[\203t\203F\203j\203b\203N\203X";
static char lbl_1_data_20530[12] = "%s_sv%d.tpl";
static char lbl_1_data_2053C[12] = "%s_cv%d.tpl";
static char lbl_1_data_20548[8] = "%s.tpl";
static char lbl_1_data_20550[8] = "%s.gma";
static char lbl_1_data_20558[16] = "%s_crash.gma";
static char lbl_1_data_20568[12] = "%s_0%d.gma";
static char lbl_1_data_20574[8] = "%s.fmi";
static char lbl_1_data_2057C[24] = "vehicle/carcmntex.tpl";
static char lbl_1_data_20594[20] = "init/crashmdl.tpl";
static char lbl_1_data_205A8[20] = "init/crashmdl.gma";
static char lbl_1_data_205BC[8] = "cmn_a";
static char lbl_1_data_205C4[8] = "cmn_b";
static char lbl_1_data_205CC[8] = "cmn_c";
static char lbl_1_data_205D4[16] = "vehicle_parts/";
static char lbl_1_data_205E4[16] = "carcmntex.tpl";
static char lbl_1_data_205F4[20] = "vehicle/%s_e.arc.lz";
static char lbl_1_data_20608[20] = "vehicle/%s_p.arc.lz";
static char lbl_1_data_2061C[16] = "%s_0%demb.tpl";
static char lbl_1_data_2062C[12] = "%s_emb.tpl";
static char lbl_1_data_20638[16] = "%s_0%demb.gma";
static char lbl_1_data_20648[12] = "%s_emb.gma";
static char lbl_1_data_20654[8] = "../..";
static s8 lbl_1_data_2065C[4] = {-1, -1, -1, -1};
static s8 lbl_1_data_20660[4] = {-1, -1, -1, -1};
static s8 lbl_1_data_20664[4] = {-1, -1, -1, -1};
static char lbl_1_data_20668[20] = "[P %2d] %08x %s\n";
static char lbl_1_data_2067C[20] = "[E %2d] %08x %s\n";
static char lbl_1_data_20690[28] = "---- Final Total %08x ----\n";
static char lbl_1_data_206AC[16] = "CarShadowCalc";
static char lbl_1_data_206BC[20] = "CarShadowPreRend";
static char lbl_1_data_206D0[8] = "CarDisp";
static char lbl_1_data_206D8[32] = "EmbProjectionDummyObjPutMain";
static char lbl_1_data_206F8[8] = "CarCalc";
static char lbl_1_data_20700[20] = "EnemyControlMain";
static char lbl_1_data_20714[12] = "CarUpdate";
static char lbl_1_data_20720[8] = "CARCV0";
static char lbl_1_data_20728[8] = "CARCV1";
static char lbl_1_data_20730[8] = "CARCV2";
static char lbl_1_data_20738[8] = "CARCV3";
static char lbl_1_data_20740[8] = "CARSV0";
static char lbl_1_data_20748[8] = "CARSV1";
static char lbl_1_data_20750[8] = "CARSV2";
static char lbl_1_data_20758[8] = "CARSV3";
static char lbl_1_data_20760[12] = "CARLOD_HI";
static char lbl_1_data_2076C[12] = "CARLOD_MHI";
static char lbl_1_data_20778[12] = "CARLOD_MLOW";
static char lbl_1_data_20784[12] = "CARLOD_LOW";
static char lbl_1_data_20790[16] = "CARLOD_CRASH";
static char lbl_1_data_207A0[16] = "CARLOD_NODISP";
static char lbl_1_data_207B0[12] = "%s(%2d)\n";
static char lbl_1_data_207BC[4] = "%s\n";
static char lbl_1_data_207C0[16] = "tex (%2.2f%)\n";
static char lbl_1_data_207D0[16] = "mdl (%2.2f%)\n";
static char lbl_1_data_207E0[16] = "pxl (%2.2f)\n";
/* 207F0..20894: jump table of a switch (compiler-generated) */

/* fzgx:begin fn_1_7EB8C */
/* Plain static helper that the retail link removed (strip.txt). Its literals are the only trace: .rodata 3528 f64 0.1,
   created after 7EB8C's 0.0f / 1.19e-7 and before 1.0f. Body inferred from the depth_fade family below (no retail copy). */
static f32 depth_fade_far(f32 z, f64 absZ) {
    f32 result = 0.0f;
    if (absZ < 1.1920928955078125e-07)
        return result;
    if (z < 0.1)
        result = z;
    return 1.0f - result;
}

/* VIEWS */
#define lbl_801A6410 (*(void * *)&lbl_801A6410)
#define lbl_801A6D00 (*(void * *)&lbl_801A6D00)
/* car_test.c: the machine test scene (main.rel, one translation unit) */

/* one model of a machine */

/* one level of detail of a machine */

/* the body state of a machine (0x620 bytes) */

/* one machine (0x440 bytes) */

/* one light of the test scene (0xC bytes) */

/* the state of the test scene (0x2C bytes) */

/* one pad's button words */

/* degrees to the 0x10000-per-turn angle unit; folds to an int constant (315 gives 0xE000) */

#define DEG_TO_S16(deg) ((s16)(182.04445f * (deg)))

#define lbl_1_bss_9F8 _h_9F8

#define lbl_1_bss_38454 _h_38454


#undef lbl_1_bss_9F8

#undef lbl_1_bss_38454


#define lbl_1_bss_6D7E8 _h_6D7E8

#undef lbl_1_bss_6D7E8

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

#define lbl_1_bss_9F8 _h_9F8

#define lbl_1_bss_38454 _h_38454


#undef lbl_1_bss_9F8

#undef lbl_1_bss_38454


#define lbl_1_bss_6D7E8 _h_6D7E8

#undef lbl_1_bss_6D7E8

// fn_1_7EAE8: main_rel .text:0x0007EAE8 size 0x24

// Wrapper that calls fn_1_5634C with argument 0.

#define lbl_1_bss_9F8 _h_9F8

#define lbl_1_bss_38454 _h_38454


#undef lbl_1_bss_9F8

#undef lbl_1_bss_38454


#define lbl_1_bss_6D7E8 _h_6D7E8

#undef lbl_1_bss_6D7E8

#define HW_F32(off) (*(f32 *)(0xE0000000 + (off)))


void fn_1_7EB8C(Object *arg0) {
    ListEntry *table;
    s8 index;
    u32 value;
    f32 arg_f;
    Vec3 vec;

    table = arg0->unk_3A4;
    index = arg0->unk_3BA;

    if (table == 0) {
        return;
    }

    if (arg0->unk_390 & 0x04000000) {
        value = ((SubEntry *)((MidEntry *)table[index].f_0)->f_8)->f_0;
    } else if (arg0->unk_328 == 4) {
        value = ((SubEntry *)((MidEntry *)table[index].f_0)->f_8)->f_8;
    } else {
        value = ((SubEntry *)((MidEntry *)table[index].f_0)->f_8)->f_0;
    }


    psvec_set(&vec, HW_F32(0x2C), HW_F32(0x1C), HW_F32(0xC));

    arg_f = 0.0f;

    if (__fabsf(HW_F32(0x2C)) < 0.00000011920928955078125) {
        arg_f = 0.0f;
    } else if (HW_F32(0x2C) < 0.15000000074505807) {
        arg_f = 1.0f + 0.05f / HW_F32(0x2C);
    }

    lbl_8006DB74((void *)((u32)((u8 *)lbl_801A6D00 + 0x60)));
    lbl_8006D848(arg_f);
    lbl_8006DFC4((void *)((u32)((u8 *)lbl_801A6D00 + 0x60)));
    fn_80072558();
    fn_1_556B8((void *)value);
}
/* fzgx:end fn_1_7EB8C */

/* fzgx:begin fn_1_7ECB8 */
/* 0 when |z| is below epsilon or z is not below the limit, else 1 + k / z. */
static inline f32 depth_fade(f32 z, f64 absZ, f64 limit, f32 k) {
    f32 result = 0.0f;
    if (absZ < 1.1920928955078125e-07) {
        result = 0.0f;
    } else if (z < limit) {
        result = 1.0f + k / z;
    }
    return result;
}

/* The low bound is the result variable itself: retail keeps both in f3. */

static inline f32 clamp_rotation(f32 x, f32 low, f32 high) {
    if (x < low)
        return low;
    if (x > high)
        return high;
    return x;
}

typedef struct {
    void *model;
    u32 unk_4;
} PartModel7ECB8;

typedef struct {
    u8 pad_0[0x8];
    PartModel7ECB8 *parts;
} ModelSet7ECB8;

typedef struct {
    ModelSet7ECB8 *set;
    u32 unk_4;
} Lod7ECB8;

typedef struct {
    u32 flags;
    u8 pad_4[0xA0];
    f32 unk_A4;
    u8 pad_A8[0xE2];
    u8 unk_18A;
} State7ECB8;

typedef struct {
    Vec3 pos;
    u8 pad_C[0x8];
} Joint7ECB8;

struct Car7ECB8 {
    u8 pad_0[0x208];
    Joint7ECB8 joints[2];
    u8 pad_230[0xF8];
    s8 type;
    u8 pad_329[0x3];
    State7ECB8 *state;
    u8 pad_330[0x8];
    struct { ModelSet7ECB8 *set; u8 pad_4[0x8]; } lods[4];
    u8 pad_368[0x28];
    u32 unk_390;
    u8 pad_394[0xC];
    u32 unk_3A0;
    Lod7ECB8 (*models)[6];
    u8 pad_3A8[0x12];
    s16 lod;
};

/* depth fade of the current matrix's translation */
static inline f32 fn_1_7ECB8_fade(f32 z, f64 limit, f32 k) {
    Vec3 pos;

    psvec_set(&pos, z, HW_F32(0x1C), HW_F32(0xC));
    return depth_fade(z, __fabs(z), limit, k);
}

static inline void fn_1_7ECB8_light(f32 fade) {
    lbl_8006DB74((u8 *)lbl_801A6D00 + 0x60);
    lbl_8006D848(fade);
    lbl_8006DFC4((u8 *)lbl_801A6D00 + 0x60);
}

void fn_1_7ECB8(struct Car7ECB8 *car, u32 part, u32 flags, f32 arg3) {
    Lod7ECB8 (*models)[6];
    void *model;
    f32 lim;
    f32 t;
    f32 rate;
    f32 angle;
    f32 z;

    models = car->models;
    if (car->unk_390 & 0x4000000) {
        if (flags & 0x40000000) {
            model = NULL;
            if ((s16)part == 1) {
                model = fn_1_14DD68(car->unk_3A0);
            } else if ((s16)part == 2) {
                model = (void *)fn_1_14DDF4(car->unk_3A0);
            }
            lbl_8006E0A4(model);
        }
        fn_1_7ECB8_light(fn_1_7ECB8_fade(HW_F32(0x2C), 0.15000000074505807, 0.05000000074505806f));
        fn_80072558();
        fn_80072558();
        fn_1_556B8(models[(s16)part][car->lod].set->parts[0].model);
    } else if (car->type == 4) {
        if (flags & 0x80000000) {
            Vec3 pos;

            fn_80008BA8(&pos, &car->joints[0].pos, sizeof(Vec3));
            lbl_8006E0A4(&pos);
            if (car->state != NULL) {
                lim = 30.0f;
                lim = clamp_rotation(-lim * car->state->unk_A4 / 256.0f, -lim, lim);
                mathutil_mtxA_rotate_y(182.04444885253906f * lim);
            }
        } else if (flags & 0x40000000) {
            Vec3 pos;

            fn_80008BA8(&pos, &car->joints[0].pos, sizeof(Vec3));
            lbl_8006E0A4(&pos);
        }
        fn_1_7ECB8_light(fn_1_7ECB8_fade(HW_F32(0x2C), 0.15000000074505807, 0.05000000074505806f));
        fn_80072558();
        fn_80072558();
        fn_1_556B8(models[0][car->lod].set->parts[0].model);
    } else if (car->type == 40) {
        if (flags & 0xC0000000) {  /* fzgx-allow: A1 flag bits, not an address */
            Vec3 pos;

            fn_80008BA8(&pos, &car->joints[(s16)part - 1].pos, sizeof(Vec3));
            lbl_8006E0A4(&pos);
        }
        if (flags & 0x80000000) {
            t = 0.0f;
            if (car->state != NULL) {
                if (car->state->flags & 0x60) {
                    rate = 180.0f / ((car->state->flags & 0x600000) ? 44.0f : 89.0f);
                    angle = (angle = rate * car->state->unk_18A) < 0.0f ? 0.0f : (angle > 180.0f ? 180.0f : angle);
                    t = lbl_8006D188(DEG_TO_S16((s16)angle));
                }
                rate = 60.0f;
                if ((s16)part == 1) {
                    angle = t * rate;
                    mathutil_mtxA_rotate_y(182.04444885253906f * (s16)(360.0f - angle));
                } else {
                    mathutil_mtxA_rotate_y(182.04444885253906f * (s16)(t * rate));
                }
            }
        }
        if (car->lod == 0) {
            z = HW_F32(0x2C);
            model = models[0][car->lod].set->parts[(s16)part].model;
            fn_1_7ECB8_light(fn_1_7ECB8_fade(z, 0.12999999932944775, 0.029999999329447746f));
            fn_80072558();
        } else {
            model = car->lods[car->lod].set->parts[(s16)part].model;
        }
        fn_80072558();
        fn_1_556B8(model);
    }
}
/* fzgx:end fn_1_7ECB8 */

/* fzgx:begin fn_1_7F1E8 */
void fn_1_7F1E8(void *arg0, u32 arg1, f32 arg2) {
    fn_1_7ECB8((void *)arg0, arg1, 0x80000000, arg2); // fzgx-allow: A1 retail sentinel
}
/* fzgx:end fn_1_7F1E8 */

/* fzgx:begin fn_1_7F20C */
void fn_1_7F20C(void *arg0, u32 arg1, f32 arg2) {
    fn_1_7ECB8((void *)arg0, arg1, 0x40000000, arg2); // fzgx-allow: A1 retail sentinel
}
/* fzgx:end fn_1_7F20C */

/* fzgx:begin fn_1_7F230 */
void fn_1_7F230(void *arg0, u32 arg1, f32 arg2) {
    fn_1_7ECB8((void *)arg0, arg1, 0, arg2);
}
/* fzgx:end fn_1_7F230 */

/* fzgx:begin fn_1_7F254 */
#define lbl_1_bss_9F8 _h_9F8

#define lbl_1_bss_38454 _h_38454


#undef lbl_1_bss_9F8

#undef lbl_1_bss_38454


#define lbl_1_bss_6D7E8 _h_6D7E8

#undef lbl_1_bss_6D7E8

void *fn_1_7F254(void *arg0, s16 arg1) {
    u8 kind = ((u8 *)arg0)[5];
    s16 type;
    void *result;

    if (kind == 4) {
        type = 2;
    } else if (kind == 0x28 || kind >= 0x29) {
        type = 3;
    } else {
        type = 1;
    }

    if ((((u32 *)arg0)[0] & 0x40000000) == 0) {
        fn_1_12AB38(lbl_1_data_1FFE4);
        result = fn_1_45D0(lbl_801A6410, type * 0x30, lbl_1_data_1FFF0, 0x1d5);
        fn_80008BEC(result, 0, type * 0x30);
        fn_1_80F80((void *)result, ((u8 *)arg0)[0x81a0], arg1);
        fn_1_12AB38(lbl_1_data_1FFF8);
    } else {
        struct {
            u16 a;
            u16 b;
            u16 c;
        } info = {0, 0, 0};
        info.a = ((u8 *)arg0)[0x81a4];
        info.b = ((u8 *)arg0)[0x81ac];
        info.c = ((u8 *)arg0)[0x81b4];
        result = fn_1_45D0(lbl_801A6410, 0x90, lbl_1_data_1FFF0, 0x1e2);
        fn_80008BEC(result, 0, 0x90);
        fn_1_1502BC(result, &info, arg1);
    }
    return result;
}
#undef lbl_801A6410
#undef lbl_801A6D00
#undef DEG_TO_S16
#undef HW_F32
/* fzgx:end fn_1_7F254 */

/* fzgx:begin fn_1_7F3AC */
void fn_1_7F3AC(CarFn_1_7F3AC *car, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    u32 shift;
    u32 flags;
    if (car != 0 && car->field_3A4 != 0) {
        shift = 6;
        flags = car->field_390;
        /* WARNING: compiler-diff device, not original code: __rlwnm keeps retail's `li r0,6; rlwnm.` (rotate amount in a
           register); `(flags >> 26) & 1` gives rlwinm. No natural spelling is known (same family as objput.c). */
        if ((__rlwnm(flags, shift, 31, 31) != 0)) {
            fn_1_150464(car->field_3A4);
        } else {
            fn_1_810E4(car->field_3A4);
        }
        fn_1_46B4(lbl_801A6410, car->field_3A4, (const char *)(&lbl_1_data_1FFF0), 0x1F7);
        car->field_3A4 = 0;
    }
}
/* fzgx:end fn_1_7F3AC */

/* fzgx:begin fn_1_7F428 */
u32 fn_1_7F428(u32 arg0) {
    s32 index;

    if (lbl_1_bss_6D828 == 0) {
        return 0;
    }

    index = fn_1_3F854();
    if ((u8)arg0 > index) {
        return 0;
    }

    return lbl_1_bss_6D828 + (u8)arg0 * (0x10000 + 0x440);
}
/* fzgx:end fn_1_7F428 */

/* fzgx:begin fn_1_7F49C */
void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2) {
    char *local[41][6] = {
        {(char *)lbl_1_data_1FFFC, (char *)lbl_1_data_1FFFC, (char *)lbl_1_data_1FFFC, (char *)lbl_1_data_1FFFC, (char *)lbl_1_data_1FFFC, (char *)lbl_1_data_20008},
        {(char *)lbl_1_data_20018, (char *)lbl_1_data_20018, (char *)lbl_1_data_20018, (char *)lbl_1_data_20018, (char *)lbl_1_data_20018, (char *)lbl_1_data_20024},
        {(char *)lbl_1_data_20038, (char *)lbl_1_data_20038, (char *)lbl_1_data_20038, (char *)lbl_1_data_20038, (char *)lbl_1_data_20038, (char *)lbl_1_data_20044},
        {(char *)lbl_1_data_2005C, (char *)lbl_1_data_2005C, (char *)lbl_1_data_2005C, (char *)lbl_1_data_2005C, (char *)lbl_1_data_2005C, (char *)lbl_1_data_20068},
        {(char *)lbl_1_data_2007C, (char *)lbl_1_data_2007C, (char *)lbl_1_data_2007C, (char *)lbl_1_data_2007C, (char *)lbl_1_data_2007C, (char *)lbl_1_data_2008C},
        {(char *)lbl_1_data_200A4, (char *)lbl_1_data_200A4, (char *)lbl_1_data_200A4, (char *)lbl_1_data_200A4, (char *)lbl_1_data_200A4, (char *)lbl_1_data_200B0},
        {(char *)lbl_1_data_200C0, (char *)lbl_1_data_200C0, (char *)lbl_1_data_200C0, (char *)lbl_1_data_200C0, (char *)lbl_1_data_200C0, (char *)lbl_1_data_200CC},
        {(char *)lbl_1_data_200E0, (char *)lbl_1_data_200E0, (char *)lbl_1_data_200E0, (char *)lbl_1_data_200E0, (char *)lbl_1_data_200E0, (char *)lbl_1_data_200EC},
        {(char *)lbl_1_data_200FC, (char *)lbl_1_data_200FC, (char *)lbl_1_data_200FC, (char *)lbl_1_data_200FC, (char *)lbl_1_data_200FC, (char *)lbl_1_data_20108},
        {(char *)lbl_1_data_20118, (char *)lbl_1_data_20118, (char *)lbl_1_data_20118, (char *)lbl_1_data_20118, (char *)lbl_1_data_20118, (char *)lbl_1_data_20128},
        {(char *)lbl_1_data_2013C, (char *)lbl_1_data_2013C, (char *)lbl_1_data_2013C, (char *)lbl_1_data_2013C, (char *)lbl_1_data_2013C, (char *)lbl_1_data_20148},
        {(char *)lbl_1_data_20158, (char *)lbl_1_data_20158, (char *)lbl_1_data_20158, (char *)lbl_1_data_20158, (char *)lbl_1_data_20158, (char *)lbl_1_data_20168},
        {(char *)lbl_1_data_2017C, (char *)lbl_1_data_2017C, (char *)lbl_1_data_2017C, (char *)lbl_1_data_2017C, (char *)lbl_1_data_2017C, (char *)lbl_1_data_2018C},
        {(char *)lbl_1_data_2019C, (char *)lbl_1_data_2019C, (char *)lbl_1_data_2019C, (char *)lbl_1_data_2019C, (char *)lbl_1_data_2019C, (char *)lbl_1_data_201A8},
        {(char *)lbl_1_data_201B8, (char *)lbl_1_data_201B8, (char *)lbl_1_data_201B8, (char *)lbl_1_data_201B8, (char *)lbl_1_data_201B8, (char *)lbl_1_data_201C4},
        {(char *)lbl_1_data_201D4, (char *)lbl_1_data_201D4, (char *)lbl_1_data_201D4, (char *)lbl_1_data_201D4, (char *)lbl_1_data_201D4, (char *)lbl_1_data_201E4},
        {(char *)lbl_1_data_201F8, (char *)lbl_1_data_201F8, (char *)lbl_1_data_201F8, (char *)lbl_1_data_201F8, (char *)lbl_1_data_201F8, (char *)lbl_1_data_20208},
        {(char *)lbl_1_data_2021C, (char *)lbl_1_data_2021C, (char *)lbl_1_data_2021C, (char *)lbl_1_data_2021C, (char *)lbl_1_data_2021C, (char *)lbl_1_data_2022C},
        {(char *)lbl_1_data_20240, (char *)lbl_1_data_20240, (char *)lbl_1_data_20240, (char *)lbl_1_data_20240, (char *)lbl_1_data_20240, (char *)lbl_1_data_20250},
        {(char *)lbl_1_data_20264, (char *)lbl_1_data_20264, (char *)lbl_1_data_20264, (char *)lbl_1_data_20264, (char *)lbl_1_data_20264, (char *)lbl_1_data_20270},
        {(char *)lbl_1_data_20280, (char *)lbl_1_data_20280, (char *)lbl_1_data_20280, (char *)lbl_1_data_20280, (char *)lbl_1_data_20280, (char *)lbl_1_data_20290},
        {(char *)lbl_1_data_202A0, (char *)lbl_1_data_202A0, (char *)lbl_1_data_202A0, (char *)lbl_1_data_202A0, (char *)lbl_1_data_202A0, (char *)lbl_1_data_202B0},
        {(char *)lbl_1_data_202C0, (char *)lbl_1_data_202C0, (char *)lbl_1_data_202C0, (char *)lbl_1_data_202C0, (char *)lbl_1_data_202C0, (char *)lbl_1_data_202D0},
        {(char *)lbl_1_data_202E0, (char *)lbl_1_data_202E0, (char *)lbl_1_data_202E0, (char *)lbl_1_data_202E0, (char *)lbl_1_data_202E0, (char *)lbl_1_data_202EC},
        {(char *)lbl_1_data_202FC, (char *)lbl_1_data_202FC, (char *)lbl_1_data_202FC, (char *)lbl_1_data_202FC, (char *)lbl_1_data_202FC, (char *)lbl_1_data_20308},
        {(char *)lbl_1_data_20318, (char *)lbl_1_data_20318, (char *)lbl_1_data_20318, (char *)lbl_1_data_20318, (char *)lbl_1_data_20318, (char *)lbl_1_data_20324},
        {(char *)lbl_1_data_20334, (char *)lbl_1_data_20334, (char *)lbl_1_data_20334, (char *)lbl_1_data_20334, (char *)lbl_1_data_20334, (char *)lbl_1_data_20344},
        {(char *)lbl_1_data_2035C, (char *)lbl_1_data_2035C, (char *)lbl_1_data_2035C, (char *)lbl_1_data_2035C, (char *)lbl_1_data_2035C, (char *)lbl_1_data_20370},
        {(char *)lbl_1_data_20384, (char *)lbl_1_data_20384, (char *)lbl_1_data_20384, (char *)lbl_1_data_20384, (char *)lbl_1_data_20384, (char *)lbl_1_data_20390},
        {(char *)lbl_1_data_203A0, (char *)lbl_1_data_203A0, (char *)lbl_1_data_203A0, (char *)lbl_1_data_203A0, (char *)lbl_1_data_203A0, (char *)lbl_1_data_203AC},
        {(char *)lbl_1_data_203BC, (char *)lbl_1_data_203BC, (char *)lbl_1_data_203BC, (char *)lbl_1_data_203BC, (char *)lbl_1_data_203BC, (char *)lbl_1_data_203CC},
        {(char *)lbl_1_data_203E0, (char *)lbl_1_data_203E0, (char *)lbl_1_data_203E0, (char *)lbl_1_data_203E0, (char *)lbl_1_data_203E0, (char *)lbl_1_data_203EC},
        {(char *)lbl_1_data_20400, (char *)lbl_1_data_20400, (char *)lbl_1_data_20400, (char *)lbl_1_data_20400, (char *)lbl_1_data_20400, (char *)lbl_1_data_20410},
        {(char *)lbl_1_data_20428, (char *)lbl_1_data_20428, (char *)lbl_1_data_20428, (char *)lbl_1_data_20428, (char *)lbl_1_data_20428, (char *)lbl_1_data_20434},
        {(char *)lbl_1_data_20448, (char *)lbl_1_data_20448, (char *)lbl_1_data_20448, (char *)lbl_1_data_20448, (char *)lbl_1_data_20448, (char *)lbl_1_data_20458},
        {(char *)lbl_1_data_2046C, (char *)lbl_1_data_2046C, (char *)lbl_1_data_2046C, (char *)lbl_1_data_2046C, (char *)lbl_1_data_2046C, (char *)lbl_1_data_20478},
        {(char *)lbl_1_data_20488, (char *)lbl_1_data_20488, (char *)lbl_1_data_20488, (char *)lbl_1_data_20488, (char *)lbl_1_data_20488, (char *)lbl_1_data_20494},
        {(char *)lbl_1_data_204A4, (char *)lbl_1_data_204A4, (char *)lbl_1_data_204A4, (char *)lbl_1_data_204A4, (char *)lbl_1_data_204A4, (char *)lbl_1_data_204B0},
        {(char *)lbl_1_data_204C4, (char *)lbl_1_data_204C4, (char *)lbl_1_data_204C4, (char *)lbl_1_data_204C4, (char *)lbl_1_data_204C4, (char *)lbl_1_data_204D0},
        {(char *)lbl_1_data_204E4, (char *)lbl_1_data_204E4, (char *)lbl_1_data_204E4, (char *)lbl_1_data_204E4, (char *)lbl_1_data_204E4, (char *)lbl_1_data_204F4},
        {(char *)lbl_1_data_20508, (char *)lbl_1_data_20508, (char *)lbl_1_data_20508, (char *)lbl_1_data_20508, (char *)lbl_1_data_20508, (char *)lbl_1_data_20518}
    };
    strcpy( (void *)arg2, local[arg0][arg1]);
    return arg2;
}
/* fzgx:end fn_1_7F49C */

/* fzgx:begin fn_1_7F518 */
// Initializes the car test entry and optionally performs its follow-up setup.

void* fn_1_7F518(s16 car_type, void* car, s32 initialize) {
    strcpy((void *)car, (void *)(((u32 *)lbl_1_data_1F4FC)[car_type]));
    if (initialize == 1) {
        fn_1_801F8(car_type, (void *)car);
    }
    return car;
}
/* fzgx:end fn_1_7F518 */

/* fzgx:begin fn_1_7F58C */
/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

void *fn_1_7F58C(s16 car_type, void *car, u8 suffix, s32 initialize) {

    strcpy((void *)((char *)car), (void *)(((const char **)(((u8 *)lbl_1_data_1F4FC)))[car_type]));
    if (initialize == 1) {
        fn_1_801F8(car_type, car);
    }
    if (suffix) {
        if (suffix >= 4) {
            sprintf((char *)car, (char *)(((u8 *)lbl_1_data_20530)), car, suffix - 4);
        } else {
            sprintf((char *)car, (char *)(((u8 *)lbl_1_data_2053C)), car, suffix);
        }
    } else {
        sprintf((char *)car, (char *)(((u8 *)lbl_1_data_20548)), car);
    }
    return car;
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_7F58C */

/* fzgx:begin fn_1_7F658 */
/* VIEWS2 */
/* VIEWS */
#define lbl_801A6410 (*(struct fn_1_7F658_lbl_801A6410 *)&lbl_801A6410)
static inline s8 fn_1_7F658_busy(Sig_fn_1_7F658_Car *car) {
    s32 i;

    if (car == 0) {
        return 0;
    }
    if ((car->unk_390 & 0x4000000) != 0 && car->unk_3A0->field_340 != 0) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        if (car->unk_37C[i] != 0) {
            return 1;
        }
    }
    return 0;
}

static inline void fn_1_7F658_freeE(Sig_fn_1_7F658_Car *car) {
    s16 i;
    u32 v0;

    car->unk_32C = 0;
    i = 0;
    while (i < 4) {
        v0 = car->unk_37C[i];
        if (v0 != 0) {
            fn_80071718(v0);
            car->unk_37C[i] = 0;
        }
        i++;
    }
}

static inline void fn_1_7F658_freeE2(Sig_fn_1_7F658_Car *car) {
    s16 i;
    u32 v0;

    i = 0;
    while (i < 5) {
        v0 = car->unk_334[i].unk_4;
        if (v0 != 0) {
            fn_800711A8(v0);
            car->unk_334[i].unk_4 = 0;
        }
        v0 = car->unk_334[i].unk_0;
        if (v0 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v0, (void *)((const char *)lbl_1_data_1FFF0), 0x290);
            car->unk_334[i].unk_0 = 0;
        }
        i++;
    }
}

void fn_1_7F658(Sig_fn_1_7F658_Car *arg0) {
    struct fn_1_7F658_lbl_801A6410 *p_lbl_801A6410;
    u32 v0;
    s8 flag;
    s16 v1;

    if (arg0 != 0) {
        flag = fn_1_7F658_busy(arg0);
        if (flag) {
            p_lbl_801A6410 = &lbl_801A6410;
            v1 = 0;
            while (v1 < 8) {
                v0 = arg0->unk_3C0[v1];
                if (v0 != 0) {
                    fn_1_46B4(p_lbl_801A6410->unk_0, v0, (void *)((const char *)lbl_1_data_1FFF0), 0x27D);
                    arg0->unk_3C0[v1] = 0;
                    arg0->unk_3E0[v1] = 0;
                }
                v1++;
            }
            p_lbl_801A6410 = &lbl_801A6410;
            v1 = 0;
            while (v1 < 5) {
                v0 = arg0->unk_400[v1];
                if (v0 != 0) {
                    fn_1_46B4(p_lbl_801A6410->unk_0, v0, (void *)((const char *)lbl_1_data_1FFF0), 0x284);
                    arg0->unk_400[v1] = 0;
                    arg0->unk_414[v1] = 0;
                }
                v1++;
            }
            fn_1_7F658_freeE(arg0);
            fn_1_7F658_freeE2(arg0);
            v0 = arg0->unk_330;
            if (v0 != 0) {
                fn_1_46B4(lbl_801A6410.unk_0, v0, (void *)((const char *)lbl_1_data_1FFF0), 0x292);
                arg0->unk_330 = 0;
            }
            if (((u8 *)arg0 + 0x394) != 0) {
                fn_1_A7728(arg0);
            }
            if ((arg0->unk_390 & 0x4000000) != 0) {
                if (arg0->unk_3A0 != 0) {
                    fn_1_14DBCC(arg0->unk_3A0);
                }
            }
            if (arg0 != 0 && arg0 != 0) {
                if (arg0->unk_3A4 != 0) {
                    /* WARNING: compiler-diff device, not original code: __rlwnm, see fn_1_7F3AC. */
                    if (__rlwnm(arg0->unk_390, 6, 31, 31)) {
                        fn_1_150464(arg0->unk_3A4);
                    } else {
                        fn_1_810E4(arg0->unk_3A4);
                    }
                    fn_1_46B4(lbl_801A6410.unk_0, arg0->unk_3A4, (void *)((const char *)lbl_1_data_1FFF0), 0x1F7);
                    arg0->unk_3A4 = 0;
                }
            }
            arg0->unk_390 &= ~0x400000;
        }
    }
}
#undef lbl_801A6410
/* fzgx:end fn_1_7F658 */

/* fzgx:begin fn_1_7F934 */
// Forwards the caller's context to the common car initialization routine.

void fn_1_7F934(void *arg0) {
    fn_1_7F658((void *)arg0);
}
/* fzgx:end fn_1_7F934 */

/* fzgx:begin fn_1_7F954 */
void fn_1_7F954(u32 arg0, u32 arg1) {
    s8 v0;
    u32 v2;
    u32 v3;
    u32 v4;
    v0 = arg1;
{
    s32 v1;
    v1 = 0;
    v2 = arg0;
    while ((s8)v1 < v0) {
    fn_1_7F658((void *)v2);
    v2 += 1088;
    v1++;
}
    }
    fn_1_46B4((*((struct fn_1_7F954_lbl_801A6410 *)&lbl_801A6410)).unk_0, arg0, (const char *)((u32)&lbl_1_data_1FFF0), 691);
    v3 = lbl_1_bss_6D82C;
    v4 = v3;
    if (v3 != 0) {
    fn_80071718( (v4));
    lbl_1_bss_6D82C = 0;
    }
}
/* fzgx:end fn_1_7F954 */

/* fzgx:begin fn_1_7FA04 */
void fn_1_7FA04(u32 arg0) {
    u32 v1;
    s32 v0;
    u32 v2;
    u32 v3;
    u32 t2;
    v0 = 0;
    v1 = arg0;
    while ((s8)v0 < 41) {
    fn_1_7F658( (void *)(v1));
    v1 += 1088;
    v0++;
    }
    fn_1_46B4((*((struct fn_1_7FA04_lbl_801A6410 *)&lbl_801A6410)).unk_0, arg0, (const char *)((u32)&lbl_1_data_1FFF0), 709);
    v2 = lbl_1_bss_6D82C;
    v3 = v2;
    if (v2 != 0) {
    t2 = fn_80071718(v3);
    v3 = t2;
    lbl_1_bss_6D82C = 0;
    }
}
/* fzgx:end fn_1_7FA04 */

/* fzgx:begin fn_1_7FAA8 */
/* VIEWS2 */
static inline s32 fn_1_7FAA8_impl(CarListEntry *list, s32 count, s32 initial) {
    u8 *base = (u8 *)lbl_1_data_1F1D8;
    s32 total;
    s8 i;
    u8 j;
    s32 slot;
    char **names;
    CarListEntry *entry;
    s32 sub;
    s16 id;
    s32 bit;
    s16 k;
    s32 flag;
    Sig_fn_1_45730_LoadResult res;
    char buf[0x20];

    total = 0;
    fn_80006E10((const char *)(base + 0xe0c));
    entry = list;
    names = (char **)(base + 0x324);
    for (i = 0; i < (s8)count; entry++, i++) {
        sub = initial;
        id = entry->id;
        flag = sub;
        if (entry->flagsC & 0x100000) {
            flag = 1;
        }
        strcpy(buf, names[id]);
        if (flag == 1) {
            fn_1_801F8(id, (void *)buf);
        }
        fn_80006E10(buf);
        for (j = 0; j < 8; j++) {
            bit = j;
            if (entry->mask8 & (1 << bit)) {
                strcpy(buf, names[id]);
                if (flag == 1) {
                    fn_1_801F8(id, (void *)buf);
                }
                if (j != 0) {
                    if (j >= 4) {
                        sprintf(buf, (const char *)(base + 0x1358), buf, bit - 4);
                    } else {
                        sprintf(buf, (const char *)(base + 0x1364), buf, bit);
                    }
                } else {
                    sprintf(buf, (const char *)(base + 0x1370), buf);
                }
                if (fn_1_45730(buf, &res)) {
                    sub += fn_1_45B2C(&res);
                    fn_1_45850(&res);
                }
            }
        }
        for (k = 0; k < 5; k++) {
            slot = k;
            if (entry->mask4 & (1 << slot)) {
                strcpy(buf, names[id]);
                if (flag == 1) {
                    fn_1_801F8(id, (void *)buf);
                }
                if (k == 0) {
                    sprintf(buf, (const char *)(base + 0x1378), buf);
                } else if (k == 4) {
                    sprintf(buf, (const char *)(base + 0x1380), buf);
                } else {
                    sprintf(buf, (const char *)(base + 0x1390), buf, slot + 1);
                }
                if (fn_1_45730(buf, &res)) {
                    sub += fn_1_45B2C(&res);
                    fn_1_45850(&res);
                }
            }
        }
        strcpy(buf, names[id]);
        if (flag == 1) {
            fn_1_801F8(id, (void *)buf);
        }
        sprintf(buf, (const char *)(base + 0x139c), buf);
        if (fn_1_45730(buf, &res)) {
            sub += fn_1_45B2C(&res);
            fn_1_45850(&res);
        }
        fn_80006E10((const char *)(base + 0xe20));
        total += sub;
    }
    fn_80006E10((const char *)(base + 0xe20));
    return total;
}

s32 fn_1_7FAA8(CarListEntry *list, s32 count) {
    return fn_1_7FAA8_impl(list, count, 0);
}
/* fzgx:end fn_1_7FAA8 */

/* fzgx:begin fn_1_7FD7C */
void fn_1_7FD7C(Fn7FD7CArg *entry)
{
    char buf[32];
    s16 id;
    s32 common;
    u8 n;
    s16 i;

    id = entry->unk_02;
    common = 0;
    if (entry->unk_0C & 0x100000) {
        common = 1;
    }
    strcpy(buf, lbl_1_data_1F4FC[id]);
    if (common == 1) {
        fn_1_801F8(id, buf);
    }
    fn_80006E10(buf);
    for (n = 0; n < 8; n++) {
        if (entry->unk_08 & (1 << n)) {
            strcpy(buf, lbl_1_data_1F4FC[id]);
            if (common == 1) {
                fn_1_801F8(id, buf);
            }
            if (n != 0) {
                if (n >= 4) {
                    sprintf(buf, lbl_1_data_20530, buf, n - 4);
                } else {
                    sprintf(buf, lbl_1_data_2053C, buf, n);
                }
            } else {
                sprintf(buf, lbl_1_data_20548, buf);
            }
            if (fn_1_46C70(buf) == 0xFFFFFFFF) {
                fn_1_465D0(buf, 1);
            }
        }
    }
    for (i = 0; i < 5; i++) {
        if (entry->unk_04 & (1 << i)) {
            strcpy(buf, lbl_1_data_1F4FC[id]);
            if (common == 1) {
                fn_1_801F8(id, buf);
            }
            if (i == 0) {
                sprintf(buf, lbl_1_data_20550, buf);
            } else if (i == 4) {
                sprintf(buf, lbl_1_data_20558, buf);
            } else {
                sprintf(buf, lbl_1_data_20568, buf, i + 1);
            }
            if (fn_1_46C70(buf) == 0xFFFFFFFF) {
                fn_1_465D0(buf, 1);
            }
        }
    }
    strcpy(buf, lbl_1_data_1F4FC[id]);
    if (common == 1) {
        fn_1_801F8(id, buf);
    }
    sprintf(buf, lbl_1_data_20574, buf);
    if (fn_1_46C70(buf) == 0xFFFFFFFF) {
        fn_1_465D0(buf, 1);
    }
    fn_80006E10(lbl_1_data_1FFF8);
}
/* fzgx:end fn_1_7FD7C */

/* fzgx:begin fn_1_7FFF0 */


// Installs the default car-data entry used by the car registry.

void fn_1_7FFF0(void) {
    fn_1_465D0(lbl_1_data_2057C, 1);
}
/* fzgx:end fn_1_7FFF0 */

/* fzgx:begin fn_1_8001C */
void fn_1_8001C(void) {
    fn_1_465D0(lbl_1_data_20594, 1);
    fn_1_465D0(lbl_1_data_205A8, 1);
}
/* fzgx:end fn_1_8001C */

/* fzgx:begin fn_1_80058 */
void fn_1_80058(s8 arg0, u8 *arg1) {
    u8 data[0x20];

    fn_80008BEC((void *)data, 0, 0x20);
    *(u32 *)(data + 4) = 0xF;
    data[8] = 1;
    fn_80008BA8(arg1, data, 0x20);
    *(u16 *)(arg1 + 2) = arg0;
}
/* fzgx:end fn_1_80058 */

/* fzgx:begin fn_1_800C4 */
void fn_1_800C4(u16 arg0, u8 *arg1) {
    u8 data[0x20];

    fn_80008BEC((void *)data, 0, 0x20);
    *(u32 *)(data + 4) = fn_1_8171C(1);
    data[8] = 0x10;
    fn_80008BA8(arg1, data, 0x20);
    *(u16 *)(arg1 + 2) = arg0;
}
/* fzgx:end fn_1_800C4 */

/* fzgx:begin fn_1_80130 */
void fn_1_80130(u16 arg0, u8 *arg1) {
    u8 data[0x20];

    fn_80008BEC((void *)data, 0, 0x20);
    *(u32 *)(data + 4) = fn_1_8171C(0);
    data[8] = 1;
    fn_80008BA8(arg1, data, 0x20);
    *(u16 *)(arg1 + 2) = arg0;
}
/* fzgx:end fn_1_80130 */

/* fzgx:begin fn_1_8019C */
/* key -> texture slot pairs, 0xFFFF ends the list (fn_800712E4); copied by fn_1_8019C, fn_1_80294, fn_1_870BC */
static const CarTexRemapTable car_tex_remap = {{
        {51, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 47}, {5, 4}, {6, 5}, {7, 6},
        {8, 7}, {9, 8}, {10, 42}, {11, 9}, {12, 43}, {13, 10}, {14, 44}, {15, 11},
        {16, 45}, {17, 12}, {18, 46}, {19, 13}, {20, 14}, {61, 15}, {62, 16}, {63, 17},
        {64, 18}, {65, 19}, {66, 20}, {67, 21}, {68, 22}, {69, 23}, {70, 24}, {71, 25},
        {72, 26}, {73, 27}, {74, 28}, {75, 29}, {76, 52}, {77, 53}, {78, 54}, {79, 55},
        {31, 30}, {32, 31}, {33, 32}, {34, 33}, {35, 34}, {36, 35}, {37, 36}, {38, 37},
        {39, 38}, {40, 39}, {41, 40}, {42, 41}, {80, 56}, {81, 48}, {82, 49}, {83, 50},
        {84, 51}, {0xFFFF, 0}
}};

void fn_1_8019C(void *arg0) {
    CarTexRemapTable data = car_tex_remap;
    fn_800712E4(arg0, lbl_1_bss_6D82C, data.entries);
}
/* fzgx:end fn_1_8019C */

/* fzgx:begin fn_1_801F8 */
void fn_1_801F8(s16 arg0, void *arg1) {
    u8 *base = (u8 *)&lbl_1_data_1F1D8;

    switch (arg0) {
    case 6:
        strcpy( (void *)arg1, (void *)((const char *)(base + 0x13e4)));
        break;
    case 0:
        strcpy( (void *)arg1, (void *)((const char *)(base + 0x13ec)));
        break;
    case 1:
        strcpy( (void *)arg1, (void *)((const char *)(base + 0x13f4)));
        break;
    }
}
/* fzgx:end fn_1_801F8 */

/* fzgx:begin fn_1_80270 */
void fn_1_80270(void *arg0, void *arg1) {
    fn_1_80294((void *)arg0, (void *)arg1, 0);
}
/* fzgx:end fn_1_80270 */

/* fzgx:begin fn_1_80294 */
/* Unknown retail function: the retail link removed it and no surviving code holds a copy of it.
   Its literal is .rodata 3A50 (100.0f), created before fn_1_80294's local initializer ids[6] (.rodata 3A54).
   The retail body is not known: this placeholder only recreates the literal 3A50 in retail order.
   WARNING: compiler-diff device, not original code (the body is a placeholder that only rebuilds the literals) */
/* WARNING: compiler-diff device, not original code */
static f32 car_literal_order_3A50(f32 x)
{
    return 100.0f * x;
}

/* VIEWS2 */
#define lbl_1_bss_6D82C (*(void * *)&lbl_1_bss_6D82C)
static inline void fn_1_80294_table(Fn80294Model *model) {
    CarTexRemapTable table = car_tex_remap;

    fn_800712E4((void *)model, (u32)lbl_1_bss_6D82C, table.entries);
}

static inline f32 fn_1_80294_share(u32 *size) {
    return 100.0f * (s32)*size / ((u32)OSGetArenaHi() - OSGetArenaLo());
}

static inline void fn_1_80294_name(char *buf, s16 id, s32 common) {
    strcpy((void *)buf, (void *)lbl_1_data_1F4FC[id]);
    if (common == 1) {
        switch (id) {
        case 6:
            strcpy((void *)buf, (void *)lbl_1_data_205BC);
            break;
        case 0:
            strcpy((void *)buf, (void *)lbl_1_data_205C4);
            break;
        case 1:
            strcpy((void *)buf, (void *)lbl_1_data_205CC);
            break;
        }
    }
}

static inline void fn_1_80294_parts(Fn80294Entry *entry, Fn80294Car *car) {
    s16 j;
    s16 k;
    u8 n;

    fn_1_12AB38((void *)lbl_1_data_1FFF8);
    fn_1_12AB38((void *)lbl_1_data_205D4);
    car->unk_38C = entry->unk_18 = entry->unk_4;
    fn_1_14D728(entry->unk_10, car->unk_3A0);
    car->unk_3A8 = 0;
    car->unk_3B0 = 0;
    for (j = 0; j < 3U; j++) {
        if (car->unk_3A0[j].unk_340 != NULL) {
            car->unk_3A8 += fn_80077D40((void *)car->unk_3A0[j].unk_340);
        }
        for (k = 0; k < 6; k++) {
            if ((1 << k) & entry->unk_18) {
                lbl_1_bss_6D830 += fn_80077BD4((void *)car->unk_3A0[j].unk_344[k]);
            }
        }
    }
    lbl_1_bss_6D834 += car->unk_3A8;
    car->unk_3AC = fn_1_80294_share(&car->unk_3A8);
    car->unk_3B4 = fn_1_80294_share(&car->unk_3B0);
    fn_1_12AB38((void *)lbl_1_data_1FFF8);
    fn_1_12AB38((void *)lbl_1_data_1FFE4);
    for (n = 0; n < 8; n++) {
        if ((entry->unk_8 & (1 << n)) && !(car->unk_390 & 0x400000)) {
            car->unk_3B8 = n;
        }
    }
}

void fn_1_80294(Fn80294Entry *entry, Fn80294Car *car, s32 arg2) {
    char name[0x20];
    char buf[0x20];
    char fmi[0x20];
    s16 id;
    s16 j;
    s16 k;
    u8 n;
    s16 i;
    u8 slot;
    void *texture;
    s32 common;
    Fn80294Model *model;
    u32 *list;
    s8 count;
    s8 m;

    common = 0;
    if (entry->unk_C & 0x100000) {
        common = 1;
    }
    if (!(car->unk_390 & 0x400000)) {
        car->unk_320 = entry->unk_0;
        car->unk_390 |= entry->unk_C & 0xF0000000;
        {
            s16 ids[6] = {0x32, 0x1E, 0x14, 0x4, -1, -1};

            car->unk_334[0].unk_8 = ids[0];
            car->unk_334[1].unk_8 = ids[1];
            car->unk_334[2].unk_8 = ids[2];
            car->unk_334[3].unk_8 = ids[3];
            car->unk_334[4].unk_8 = ids[4];
            car->unk_334[5].unk_8 = ids[5];
        }
        car->unk_3BC = -1;
    }
    if (car->unk_390 & 0x04000000) {
        fn_1_80294_parts(entry, car);
        return;
    }
    id = entry->unk_2;
    if (id == -1 || id >= 0x29 || id < 0) {
        return;
    }
    if (lbl_1_bss_6D82C == NULL) {
        lbl_1_bss_6D82C = ((void *)fn_1_12AC00((void *)lbl_1_data_205E4));
    }
    if (entry->unk_C & 0x100000) {
        car->unk_390 |= 0x100000;
        common = 1;
    }
    fn_1_80294_name(name, id, common);
    fn_1_12AB38((void *)name);
    for (n = 0; n < 8; n++) {
        slot = n % 4;
        if (entry->unk_8 & (1 << n)) {
            if (car->unk_37C[slot] != NULL) {
                texture = car->unk_37C[slot];
                continue;
            }
            if (!(car->unk_390 & 0x400000)) {
                car->unk_3B8 = n;
            }
            fn_1_80294_name(buf, id, common);
            if (n != 0) {
                if (n >= 4) {
                    sprintf((void *)buf, (void *)lbl_1_data_20530, buf, n - 4);
                } else {
                    sprintf((void *)buf, (void *)lbl_1_data_2053C, buf, n);
                }
            } else {
                sprintf((void *)buf, (void *)lbl_1_data_20548, buf);
            }
            if (arg2 != 0) {
                texture = fn_1_12AC28(buf, &car->unk_3C0[n], &car->unk_3E0[n]);
            } else {
                car->unk_3C0[n] = 0;
                texture = ((void *)fn_1_12AC00((void *)buf));
            }
            lbl_1_bss_6D834 += car->unk_3A8 = fn_80077D40((void *)texture);
            car->unk_3AC = fn_1_80294_share(&car->unk_3A8);
            car->unk_37C[slot] = texture;
        }
    }
    for (i = 0; i < 5; i++) {
        if (!(entry->unk_4 & (1 << i)) || car->unk_334[i].unk_4 != NULL) {
            continue;
        }
        car->unk_38C |= 1 << i;
        if (car->unk_334[i].unk_4 != NULL) {
            continue;
        }
        fn_1_80294_name(buf, id, common);
        if (i == 0) {
            sprintf((void *)buf, (void *)lbl_1_data_20550, buf);
        } else if (i == 4) {
            sprintf((void *)buf, (void *)lbl_1_data_20558, buf);
        } else {
            sprintf((void *)buf, (void *)lbl_1_data_20568, buf, i + 1);
        }
        if (arg2 != 0) {
            model = fn_1_12ADC8(buf, texture, &car->unk_400[i], &car->unk_414[i]);
        } else {
            car->unk_400[i] = 0;
            model = fn_1_12ADA0(buf, texture);
        }
        lbl_1_bss_6D830 += fn_80077BD4((void *)model);
        car->unk_3B0 = fn_80077BD4((void *)model);
        car->unk_3B4 = fn_1_80294_share(&car->unk_3B0);
        count = model->unk_0;
        list = fn_1_45D0((void *)lbl_801A6410, count * 4, (void *)lbl_1_data_1FFF0, 0x49B);
        for (m = 0; m < count; m++) {
            list[m] = model->unk_8[m].unk_0;
        }
        fn_1_80294_table(model);
        car->unk_328 = id;
        car->unk_334[i].unk_4 = model;
        car->unk_334[i].unk_0 = list;
    }
    if (!(car->unk_390 & 0x400000)) {
        fn_1_80294_name(fmi, id, common);
        sprintf((void *)fmi, (void *)lbl_1_data_20574, fmi);
        fn_1_12A7C4(fmi, car, 0x320);
    }
    if (car->unk_2 != 0 && car->unk_330 == NULL) {
        car->unk_330 = fn_1_45D0((void *)lbl_801A6410, car->unk_2 * 0x30, (void *)lbl_1_data_1FFF0, 0x4C0);
    }
    fn_1_12AB38((void *)lbl_1_data_1FFF8);
    car->unk_390 |= 0x400000;
}
#undef lbl_1_bss_6D82C
/* fzgx:end fn_1_80294 */

/* fzgx:begin fn_1_80C18 */
void fn_1_80C18(u8 *arg0, u8 *arg1, s8 arg2) {
    u8 *data;
    u8 *p0;
    u8 *p1;
    s8 i;

    data = (u8 *)&lbl_1_data_1F1D8;
    fn_1_12AB38((void *)(data + 0xe0c));
    p0 = arg0;
    p1 = arg1;
    if (lbl_1_bss_6D82C == 0) {
        lbl_1_bss_6D82C = fn_1_12AC00( (unsigned char *)(data + 0x140c));
    }

    i = 0;
    while (i < arg2) {
        if (p0 == 0) {
            break;
        }
        fn_1_80294((void *)p1, (void *)p0, 0);
        p0 += 0x440;
        p1 += 0x20;
        i++;
    }

    fn_1_12AB38((void *)(data + 0xe20));
}
/* fzgx:end fn_1_80C18 */

/* fzgx:begin fn_1_80CC4 */
s32 fn_1_80CC4(s32 id, s32 mode, s32 suffix, void *arg3)
{
    s16 result;
    char name[0x20];
    Fn80CC4Info info;
    char path[0x28];

    if (arg3 == NULL) {
        return -1;
    }
    if (mode != 0) {
        Fn80CC4Info tmp;
        fn_80008BEC((void *)&tmp, 0, 0x20);
        tmp.unk_4 = fn_1_8171C(1);
        tmp.unk_8 = 0x10;
        fn_80008BA8(&info, &tmp, 0x20);
        info.unk_2 = id;
        strcpy((void *)name, (void *)(((char **)(((u8 *)lbl_1_data_1F4FC)))[(s16)id]));
        if (suffix == 1) {
            switch ((s16)id) {
            case 6:
                strcpy((void *)name, (void *)((char *)(((u8 *)lbl_1_data_205BC))));
                break;
            case 0:
                strcpy((void *)name, (void *)((char *)(((u8 *)lbl_1_data_205C4))));
                break;
            case 1:
                strcpy((void *)name, (void *)((char *)(((u8 *)lbl_1_data_205CC))));
                break;
            }
        }
        sprintf((void *)path, (void *)((char *)(((u8 *)lbl_1_data_205F4))), name);
    } else {
        Fn80CC4Info tmp;
        fn_80008BEC((void *)&tmp, 0, 0x20);
        tmp.unk_4 = fn_1_8171C(0);
        tmp.unk_8 = 1;
        fn_80008BA8(&info, &tmp, 0x20);
        info.unk_2 = id;
        strcpy((void *)name, (void *)(((char **)(((u8 *)lbl_1_data_1F4FC)))[(s16)id]));
        if (suffix == 1) {
            switch ((s16)id) {
            case 6:
                strcpy((void *)name, (void *)((char *)(((u8 *)lbl_1_data_205BC))));
                break;
            case 0:
                strcpy((void *)name, (void *)((char *)(((u8 *)lbl_1_data_205C4))));
                break;
            case 1:
                strcpy((void *)name, (void *)((char *)(((u8 *)lbl_1_data_205CC))));
                break;
            }
        }
        sprintf((void *)path, (void *)((char *)(((u8 *)lbl_1_data_20608))), name);
    }
    result = fn_1_12A32C(path);
    if (lbl_1_bss_6D82C == 0) {
        fn_1_12AB38((void *)(((u8 *)lbl_1_data_1FFE4)));
        lbl_1_bss_6D82C = fn_1_12AC00(((u8 *)lbl_1_data_205E4));
        fn_1_12AB38((void *)(((u8 *)lbl_1_data_1FFF8)));
    }
    fn_1_12A2B8(1);
    fn_1_12AB38((void *)(((u8 *)lbl_1_data_1FFE4)));
    fn_1_80294((void *)&info, (void *)arg3, 0);
    fn_1_12AB38((void *)(((u8 *)lbl_1_data_1FFF8)));
    fn_1_12A2B8(0);
    return result;
}
/* fzgx:end fn_1_80CC4 */

/* fzgx:begin fn_1_80F1C */
void fn_1_80F1C(s32 arg0, void *arg1) {
    fn_1_7F658((void *)arg1);
    if ((s16)arg0 != -1) {
        fn_1_12A734((s16)arg0);
    }
    if (lbl_1_bss_6D82C != 0) {
        fn_80071718( (lbl_1_bss_6D82C));
        lbl_1_bss_6D82C = 0;
    }
}
/* fzgx:end fn_1_80F1C */

/* fzgx:begin fn_1_80F80 */
void fn_1_80F80(u32 *p, s16 idx, s16 mask)
{
    char buf[0x40];
    char name[0x40];

    char **tbl = (char **)lbl_1_data_1F4FC;
    s32 off = idx;
    u32 *q;
    s16 i;

    strcpy(name, tbl[off]);
    fn_1_12AB38(name);
    for (i = 0; i < 3; i++) {
        s16 j = i;
        q = p + i * 2;
        if ((mask & (1 << j)) && q[0] == 0) {
            if (i != 0) {
                strcpy(name, tbl[off]);
                sprintf(buf, (char *)(((u8 *)lbl_1_data_2061C)), name, j + 1);
            } else {
                strcpy(name, tbl[off]);
                sprintf(buf, (char *)(((u8 *)lbl_1_data_2062C)), name);
            }
            q[1] = fn_1_12AC00((void *)buf);
            if (i != 0) {
                strcpy(name, tbl[off]);
                sprintf(buf, (char *)(((u8 *)lbl_1_data_20638)), name, j + 1);
            } else {
                strcpy(name, tbl[off]);
                sprintf(buf, (char *)(((u8 *)lbl_1_data_20648)), name);
            }
            q[0] = ((u32)fn_1_12ADA0((void *)buf, (void *)q[1]));
        }
    }
    fn_1_12AB38(((u8 *)lbl_1_data_1FFF8));
}
/* fzgx:end fn_1_80F80 */

/* fzgx:begin fn_1_810E4 */
void fn_1_810E4(u32 arg0) {
    u32 v1;
    u32 v2;
    u32 v3;
{
    s32 v0;
    v0 = 0;
    v1 = arg0;
    while ((s16)v0 < 3) {
    v2 = *(u32 *)(v1 + 4);
    if (v2 != 0) {
    fn_80071718( (v2));
    *(u32 *)((u8 *)v1 + 4) = 0;
    }
    v3 = *(u32 *)(v1);
    if (v3 != 0) {
    fn_800711A8( (v3));
    *(u32 *)((u8 *)v1 + 0) = 0;
    }
    v1 += 8;
    v0++;
}
    }
}
/* fzgx:end fn_1_810E4 */

/* fzgx:begin fn_1_81164 */
void fn_1_81164(Fn81164Car *car, s16 from, s16 to) {
    char buf[0x28];
    s16 fromSlot;
    s16 toSlot;
    s32 kindFrom;
    s32 kindTo;
    s32 flag;
    u32 a;
    Fn81164Model *model;

    if (car->unk_390 & 0x04000000) {
        car->unk_3B8 = to;
        return;
    }
    if (from == to) {
        return;
    }
    fromSlot = from % 4;
    toSlot = to % 4;
    if (from / 4 != to / 4) {
        return;
    }
    from = fromSlot;
    if (car->unk_37C[from] == NULL || car->unk_37C[toSlot] != NULL) {
        return;
    }
    flag = 0;
    fn_80006E10((char *)(((u8 *)lbl_1_data_1FFE4)));
    if (car->unk_390 & 0x100000) {
        flag = 1;
    }
    kindFrom = car->unk_328;
    strcpy(buf, ((char **)(((u8 *)lbl_1_data_1F4FC)))[kindFrom]);
    if (flag == 1) {
        switch (kindFrom) {
        case 6:
            strcpy(buf, (char *)(((u8 *)lbl_1_data_205BC)));
            break;
        case 0:
            strcpy(buf, (char *)(((u8 *)lbl_1_data_205C4)));
            break;
        case 1:
            strcpy(buf, (char *)(((u8 *)lbl_1_data_205CC)));
            break;
        }
    }
    fn_80006E10(buf);
    kindTo = car->unk_328;
    strcpy(buf, ((char **)(((u8 *)lbl_1_data_1F4FC)))[kindTo]);
    if (flag == 1) {
        switch (kindTo) {
        case 6:
            strcpy(buf, (char *)(((u8 *)lbl_1_data_205BC)));
            break;
        case 0:
            strcpy(buf, (char *)(((u8 *)lbl_1_data_205C4)));
            break;
        case 1:
            strcpy(buf, (char *)(((u8 *)lbl_1_data_205CC)));
            break;
        }
    }
    if ((u8)to != 0) {
        if ((u8)to >= 4) {
            sprintf(buf, (char *)(((u8 *)lbl_1_data_20530)), buf, (u8)to - 4);
        } else {
            sprintf(buf, (char *)(((u8 *)lbl_1_data_2053C)), buf);
        }
    } else {
        sprintf(buf, (char *)(((u8 *)lbl_1_data_20548)), buf);
    }
    model = fn_1_D3884(buf);
    fn_80006E10((char *)(((u8 *)lbl_1_data_20654)));
    car->unk_3A8 = fn_80077D40((void *)model);
    a = fn_80071470(model->unk_8, 0);
    fn_80008BA8((void *)(fn_80071470(car->unk_37C[from]->unk_8, 0)), (void *)a, car->unk_3A8);
    fn_80071718((u32)model);
    car->unk_37C[toSlot] = car->unk_37C[from];
    car->unk_37C[from] = NULL;
    car->unk_3B8 = to;
}
/* fzgx:end fn_1_81164 */

/* fzgx:begin fn_1_81408 */
static inline void fn81408Finish(Fn81164Car *car, s16 from, s16 toSlot, s16 to, char *buf) {
    Fn81164Model *model;
    u32 a;
        model = fn_1_D3884(buf);
        fn_80006E10((char *)(((u8 *)lbl_1_data_20654)));
        car->unk_3A8 = fn_80077D40((void *)model);
        a = fn_80071470(model->unk_8, 0);
        fn_80008BA8((void *)(fn_80071470(car->unk_37C[from]->unk_8, 0)), (void *)a, car->unk_3A8);
        fn_80071718((u32)model);
        car->unk_37C[toSlot] = car->unk_37C[from];
        car->unk_37C[from] = NULL;
        car->unk_3B8 = to;
}

void fn_1_81408(Fn81164Car *car, u8 fromMask, u8 toMask) {
    s16 i;
    s16 from;
    s16 to;
    char buf[0x28];
    s32 flag;
    s16 toSlot;

    for (i = 0; i < 8; i++) {
        u8 bit = 1 << i;
        if (bit == fromMask) {
            from = i;
        }
        if (bit == toMask) {
            to = i;
        }
    }

    if (car->unk_390 & 0x04000000) {
        car->unk_3B8 = to;
        return;
    }
    if (from == to) {
        return;
    }
    {
        s16 fromSlot = from % 4;
        toSlot = to % 4;
        if (from / 4 != to / 4) {
            return;
        }
        from = fromSlot;
        if (car->unk_37C[from] == NULL) {
            return;
        }
        if (car->unk_37C[toSlot] != NULL) {
            return;
        }
        flag = 0;
        fn_80006E10((char *)(((u8 *)lbl_1_data_1FFE4)));
        if (car->unk_390 & 0x100000) {
            flag = 1;
        }
        {
        s32 kindFrom = car->unk_328;
        strcpy(buf, ((char **)(((u8 *)lbl_1_data_1F4FC)))[kindFrom]);
        if (flag == 1) {
            switch (kindFrom) {
            case 6:
                strcpy(buf, (char *)(((u8 *)lbl_1_data_205BC)));
                break;
            case 0:
                strcpy(buf, (char *)(((u8 *)lbl_1_data_205C4)));
                break;
            case 1:
                strcpy(buf, (char *)(((u8 *)lbl_1_data_205CC)));
                break;
            }
        }
        }
        fn_80006E10(buf);
        {
        s32 kindTo = car->unk_328;
        strcpy(buf, ((char **)(((u8 *)lbl_1_data_1F4FC)))[kindTo]);
        if (flag == 1) {
            switch (kindTo) {
            case 6:
                strcpy(buf, (char *)(((u8 *)lbl_1_data_205BC)));
                break;
            case 0:
                strcpy(buf, (char *)(((u8 *)lbl_1_data_205C4)));
                break;
            case 1:
                strcpy(buf, (char *)(((u8 *)lbl_1_data_205CC)));
                break;
            }
        }
        }
        if ((u8)to != 0) {
            if ((u8)to >= 4) {
                sprintf(buf, (char *)(((u8 *)lbl_1_data_20530)), buf, (u8)to - 4);
            } else {
                sprintf(buf, (char *)(((u8 *)lbl_1_data_2053C)), buf);
            }
        } else {
            sprintf(buf, (char *)(((u8 *)lbl_1_data_20548)), buf);
        }
        fn81408Finish(car, from, toSlot, to, buf);
    }
}
/* fzgx:end fn_1_81408 */

/* fzgx:begin fn_1_816E8 */
/* TU A .bss defined here (retail .bss order) */
static Obj_1_bss_6D838_Target *lbl_1_bss_6D838 = 0;
static void *lbl_1_bss_6D83C = 0;
static void *lbl_1_bss_6D840 = 0;
static void *lbl_1_bss_6D844 = 0;
static s16 lbl_1_bss_6D848 = 0;
static s8 lbl_1_bss_6D84A = 0;
static u8 lbl_1_bss_6D84B = 0;
static u8 lbl_1_bss_6D84C = 0;

s8 fn_1_816E8(u32 base, s8 index) {
    if (base == 0) {
        /* shared failure block is required by the retail control flow */
        goto fail;
    }
    base += index * 12;
    base = *(u32 *)(base + 824);
    if (base != 0) {
        /* shared success block preserves the retail branch layout */
        goto success;
    }
fail: /* shared failure block is required by the retail control flow */
    return -1;
success: /* success is reached only after the non-null entry check */
    return (s8)*(u32 *)base;
}
/* fzgx:end fn_1_816E8 */

/* fzgx:begin fn_1_8171C */
// Maps a car mode to its corresponding status code.

s32 fn_1_8171C(s32 value) {
    switch (value) {
    case 0:
        return 0xD;
    case 1:
        return 0xE;
    case 2:
        return 0xE;
    case 3:
        return 0xF;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_8171C */

/* fzgx:begin fn_1_8176C */
void fn_1_8176C(u32 value) {
    lbl_1_bss_6D850 = value;
}
/* fzgx:end fn_1_8176C */

/* fzgx:begin fn_1_81778 */
void fn_1_81778(void) {
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    while (i < *(s8 *)&lbl_1_bss_6D84A) {
        *((u32 *)((u8 *)lbl_1_bss_6D838 + offset)) |= 0x8000;
        i++;
        offset += 0x620;
    }
}
/* fzgx:end fn_1_81778 */

/* fzgx:begin fn_1_817C0 */
void fn_1_817C0(void) {
    s32 offset;
    s32 i;

    i = 0;
    offset = 0;
    while (i < (s8)lbl_1_bss_6D84A) {
        u32 *value = (u32 *)((u8 *)lbl_1_bss_6D838 + offset);
        *value &= 0xFFFF7FFF;
        i++;
        offset += 0x620;
    }
}
/* fzgx:end fn_1_817C0 */

/* fzgx:begin fn_1_81808 */
void fn_1_81808(void *arg0) {
    fn_80008BA8(arg0, &lbl_1_data_2065C, 4);
}
/* fzgx:end fn_1_81808 */

/* fzgx:begin fn_1_81834 */
void fn_1_81834(u8 value, s8 index_a, s8 index_b) {
    if (index_a != -1) {
        *((u8 *)&lbl_1_data_2065C + index_a) = value;
    }
    *((u8 *)&lbl_1_data_20660 + index_b) = value;
}
/* fzgx:end fn_1_81834 */

/* fzgx:begin fn_1_81860 */
s32 fn_1_81860(fn_1_81860_Obj *a, fn_1_81860_Obj *b) {
    u32 flags_a = a->flags & 0xF0000000;
    if (flags_a != 0 && (b->flags & 0xF0000000) == 0) {
        return 1;
    }
    if ((b->flags & 0xF0000000) != 0 && flags_a == 0) {
        return -1;
    }
    return a->id - b->id;
}
/* fzgx:end fn_1_81860 */

/* fzgx:begin fn_1_818AC */
s32 fn_1_818AC(fn_1_818AC_Obj *a, fn_1_818AC_Obj *b) {
    return a->value - b->value;
}
/* fzgx:end fn_1_818AC */

/* fzgx:begin fn_1_818BC */
/* VIEWS2 */
#define lbl_1_bss_6D83C (*(Car818BC * *)&lbl_1_bss_6D83C)
#define lbl_1_bss_6D840 (*(u8 * *)&lbl_1_bss_6D840)
/* fn_1_801F8: the part-name suffix */

static inline void fn_1_818BC_suffix(s16 kind, char *name) {

    switch (kind) {
    case 6:
        strcpy(name, (const char *)(lbl_1_data_205BC));
        break;
    case 0:
        strcpy(name, (const char *)(lbl_1_data_205C4));
        break;
    case 1:
        strcpy(name, (const char *)(lbl_1_data_205CC));
        break;
    }
}

/* fn_1_80C18 */

static inline void fn_1_818BC_load(u8 *car, Entry818BC **entry, s8 count) {
    s8 i;

    fn_1_12AB38(lbl_1_data_1FFE4);
    if (lbl_1_bss_6D82C == 0) {
        lbl_1_bss_6D82C = fn_1_12AC00((void *)lbl_1_data_205E4);
    }
    for (i = 0; i < count; i++) {
        if (car == NULL) {
            break;
        }
        fn_1_80294((void *)(*entry), (void *)car, 0);
        car += 0x440;
        (*entry)++;
    }
    fn_1_12AB38(lbl_1_data_1FFF8);
}

/* fn_1_81164 */

static inline void fn_1_818BC_move(Car818BC *car, s16 from, s16 to) {
    char buf[0x20];
    s16 fromSlot;
    s16 toSlot;
    s32 kindFrom;
    s32 kindTo;
    s32 flag;
    u32 a;
    Fn81164Model *model;
    Fn81164Model *resource;

    if (car->unk_390 & 0x04000000) {
        car->unk_3B8 = to;
        return;
    }
    if (from == to) {
        return;
    }
    fromSlot = from % 4;
    toSlot = to % 4;
    if (from / 4 != to / 4) {
        return;
    }
    from = fromSlot;
    if (car->unk_37C[from] == NULL || car->unk_37C[toSlot] != NULL) {
        return;
    }
    flag = 0;
    fn_80006E10((char *)(lbl_1_data_1FFE4));
    if (car->unk_390 & 0x100000) {
        flag = 1;
    }
    kindFrom = car->unk_328;
    strcpy(buf, lbl_1_data_1F4FC[kindFrom]);
    if (flag == 1) {
        fn_1_818BC_suffix(kindFrom, buf);
    }
    fn_80006E10(buf);
    kindTo = car->unk_328;
    strcpy(buf, lbl_1_data_1F4FC[kindTo]);
    if (flag == 1) {
        fn_1_818BC_suffix(kindTo, buf);
    }
    if ((u8)to != 0) {
        if ((u8)to >= 4) {
            sprintf(buf, (char *)(lbl_1_data_20530), buf, (u8)to - 4);
        } else {
            sprintf(buf, (char *)(lbl_1_data_2053C), buf);
        }
    } else {
        sprintf(buf, (char *)(lbl_1_data_20548), buf);
    }
    model = resource = fn_1_D3884(buf);
    fn_80006E10((char *)(lbl_1_data_20654));
    car->unk_3A8 = fn_80077D40((void *)model);
    a = fn_80071470(model->unk_8, 0);
    fn_80008BA8((void *)fn_80071470(car->unk_37C[from]->unk_8, 0), (void *)a, car->unk_3A8);
    fn_80071718((u32)resource);
    car->unk_37C[toSlot] = car->unk_37C[from];
    car->unk_37C[from] = NULL;
    car->unk_3B8 = to;
}

/* the part name of a seat entry, with its suffix */

static inline void fn_1_818BC_name(s16 kind, char *name, s32 flag) {
    strcpy(name, lbl_1_data_1F4FC[kind]);
    if (flag == 1) {
        fn_1_818BC_suffix(kind, name);
    }
}

/* the slot numbers of the first bit and of the selected bit */

static inline void fn_1_818BC_slots(u32 sel, u32 first, s16 *from, s16 *to) {
    s16 b;

    for (b = 0; b < 8; b++) {
        u32 bit = (u8)(1 << b);
        if (bit == first) {
            *from = b;
        }
        if (bit == sel) {
            *to = b;
        }
    }
}

/* moves a car's part from its first slot to the selected one */

static inline void fn_1_818BC_place(Car818BC *car, u32 sel, u32 first, s16 *from, s16 *to) {
    fn_1_818BC_slots(sel, first, from, to);
    fn_1_818BC_move(car, *from, *to);
}

void fn_1_818BC(Entry818BC *entries, u32 count, s32 mode) {
    s16 from1;
    Entry818BC sorted[41];
    Entry818BC *list;
    s16 to;
    s16 to2;
    s16 from2;
    Entry818BC work[41];
    s16 parts = 0;
    s16 racing;
    s16 i;
    s16 n;
    s16 from;
    s16 to3;
    s32 flag;
    char path[0x20];
    char name[0x20];
    char path2[0x20];
    char name2[0x20];

    if (mode == 0) {
        fn_80008BA8((void *)sorted, (void *)entries, count << 5);
        qsort(sorted, count, 0x20, fn_1_81860);
        list = sorted;
        for (i = 0, n = 0; i < count; i++) {
            if (list[i].unk_C & 0x04000000) {
                lbl_1_bss_6D83C[i].unk_3A0 = lbl_1_bss_6D840 + n++ * 0xA20;
                lbl_1_bss_6D83C[i].unk_328 = list[i].unk_2;
                lbl_1_bss_6D83C[i].unk_390 |= 0x04000000;
            }
        }
        fn_1_818BC_load((u8 *)lbl_1_bss_6D83C, &list, count);
        return;
    }

    fn_80008BA8((void *)sorted, (void *)entries, count << 5);
    fn_80008BA8((void *)work, (void *)entries, count << 5);
    for (i = 0; i < count; i++) {
        work[i].unk_4 = 0xE;
        work[i].unk_8 = 0x10;
        if (work[i].unk_C & 0xF0000000) {
            work[i].unk_4 = 0xD;
            parts++;
            work[i].unk_8 = 1;
        }
    }
    racing = count - parts;
    qsort(sorted, count, 0x20, fn_1_81860);
    qsort(work, count, 0x20, fn_1_81860);
    for (i = 0, n = 0; i < count; i++) {
        if (work[i].unk_C & 0x04000000) {
            lbl_1_bss_6D83C[i].unk_3A0 = lbl_1_bss_6D840 + n++ * 0xA20;
            lbl_1_bss_6D83C[i].unk_328 = sorted[i].unk_2;
            lbl_1_bss_6D83C[i].unk_390 |= 0x04000000;
        }
    }
    fn_1_12AB38(lbl_1_data_1FFE4);
    if (lbl_1_bss_6D82C == 0) {
        lbl_1_bss_6D82C = fn_1_12AC00((void *)lbl_1_data_205E4);
    }
    fn_1_12AB38(lbl_1_data_1FFF8);

    for (i = 0; i < racing; i++) {
        if (!(work[i].unk_C & 0x04000000)) {
            flag = 0;
            if (work[i].unk_C & 0x100000) {
                flag = 1;
            }
            fn_1_818BC_name(work[i].unk_2, name, flag);
            sprintf(path, (char *)(lbl_1_data_205F4), name);
            lbl_1_bss_6D83C[i].unk_324 = fn_1_12A32C(path);
        }
    }
    for (i = 0; i < racing; i++) {
        if (lbl_1_bss_6D83C[i].unk_390 & 0x04000000) {
            fn_1_12AB38(lbl_1_data_1FFE4);
            fn_1_80294((void *)&work[i], (void *)&lbl_1_bss_6D83C[i], 0);
            fn_1_12AB38(lbl_1_data_1FFF8);
        } else {
            Car818BC *car;
            fn_1_12A2B8(1);
            fn_1_12A2C4(1);
            fn_1_12A2D0(lbl_1_bss_6D83C[i].unk_324);
            fn_1_12AB38(lbl_1_data_1FFE4);
            car = &lbl_1_bss_6D83C[i];
            if (car == NULL) {
                break;
            }
            fn_1_80294((void *)&work[i], (void *)car, 0);
            fn_1_12AB38(lbl_1_data_1FFF8);
            fn_1_12A2B8(0);
            fn_1_12A2C4(0);
        }
    }
    for (i = 0; i < racing; i++) {
        u8 sel = sorted[i].unk_8;
        if (sel != 0x10) {
            fn_1_818BC_place(&lbl_1_bss_6D83C[i], sel, 0x10, &from, &to);
        }
    }

    for (i = racing; i < count; i++) {
        flag = 0;
        if (!(work[i].unk_C & 0x04000000)) {
            if (work[i].unk_C & 0x100000) {
                flag = 1;
            }
            fn_1_818BC_name(work[i].unk_2, name2, flag);
            sprintf(path2, (char *)(lbl_1_data_20608), name2);
            lbl_1_bss_6D83C[i].unk_324 = fn_1_12A32C(path2);
        }
    }
    for (i = racing; i < count; i++) {
        if (lbl_1_bss_6D83C[i].unk_390 & 0x04000000) {
            fn_1_12AB38(lbl_1_data_1FFE4);
            fn_1_80294((void *)&work[i], (void *)&lbl_1_bss_6D83C[i], 0);
            fn_1_12AB38(lbl_1_data_1FFF8);
        } else {
            Car818BC *car;
            fn_1_12A2B8(1);
            fn_1_12A2C4(1);
            fn_1_12A2D0(lbl_1_bss_6D83C[i].unk_324);
            fn_1_12AB38(lbl_1_data_1FFE4);
            car = &lbl_1_bss_6D83C[i];
            if (car == NULL) {
                break;
            }
            fn_1_80294((void *)&work[i], (void *)car, 0);
            fn_1_12AB38(lbl_1_data_1FFF8);
            fn_1_12A2B8(0);
            fn_1_12A2C4(0);
        }
    }
    for (i = racing; i < count; i++) {
        u32 sel = sorted[i].unk_8;
        if (sel & 0xE) {
            fn_1_818BC_place(&lbl_1_bss_6D83C[i], sel, 1, &from1, &to2);
        } else if (sel & 0xE0) {
            fn_1_818BC_place(&lbl_1_bss_6D83C[i], sel, 0x10, &from2, &to3);
        }
    }
}
#undef lbl_1_bss_6D83C
#undef lbl_1_bss_6D840
/* fzgx:end fn_1_818BC */

/* fzgx:begin fn_1_82724 */
/* VIEWS2 */
#define lbl_1_bss_6D828 (*(void * *)&lbl_1_bss_6D828)
#define lbl_1_bss_6D838 (*(CarRuntime * *)&lbl_1_bss_6D838)
#define lbl_1_bss_6D83C (*(CarInitObject * *)&lbl_1_bss_6D83C)
/* VIEWS */
#define lbl_1_bss_8B3A0 (*(Obj_1_bss_8B3A0_L *)&lbl_1_bss_8B3A0)
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)
/* begin rel/main_rel/car.h (fork-deltawave784/windows-and-types@4b722344) */

#define REL_MAIN_REL_CAR_H

/* begin rel/main_rel/globals.h (fork-deltawave784/windows-and-types@4b722344) */

#define REL_MAIN_REL_GLOBALS_H

// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the

// module's disassembly (matched or not). Field names are offsets until the librarian names them;

// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}

// lbl_1_bss_8B3A0: .bss size 0x14C, referenced by 87 functions, shape {'object': 253}

// object reached through lbl_1_bss_8B3A0.unk_A4

/* end rel/main_rel/globals.h */

// Generated by `fzgx headers --module main_rel --tu car.c`: globals of car.c (referenced by its

// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_1_data_1F1D8: .data size 0x8, 15 refs from car.c

// lbl_1_bss_525C: .bss size 0x198, 2 refs from car.c

#define FZGX_TYPES_LBL_1_BSS_525C

void fn_1_82724(void *arg0, void *arg1, CarInitInput *input, u32 count, u32 arg4)
{

    u8 *data = (u8 *)&lbl_1_data_1F1D8;
    CarRuntime *runtimeBase;
    CarInitObject *objectBase;
    u32 driverCount = 0;
    CarShadow *shadowBase;
    u32 i;
    CarRuntime *runtime;
    CarInitObject *object;
    CarShadow *shadow;
    CarInitEvent event;

    lbl_1_bss_6D854 = 0;
    if (lbl_1_bss_960 == 9 && lbl_1_bss_9C == 6) {
        lbl_1_bss_6D858 = 1;
        fn_1_8E188();
    } else {
        lbl_1_bss_6D858 = 0;
    }
    if (lbl_1_bss_6D85C.unk_4 == 0) {
        lbl_1_bss_6D85C.unk_0 = (u32)fn_1_12ADA0((const char *)(data + 0x13d0), (void *)(lbl_1_bss_6D85C.unk_4 = fn_1_12AC00(data + 0x13bc)));
    }
    if (count > 30)
        count = 30;
    if (lbl_1_bss_6D83C == 0 && lbl_1_bss_6D844 == 0) {
    u32 *heap = &lbl_801A6410;
    lbl_1_bss_6D834 = 0;
    lbl_1_bss_6D830 = 0;
    lbl_1_bss_6D83C = fn_1_4630(*heap, count * 0x440, data + 0xe18, 0x7a1);
    for (i = 0; i < count; i++)
        lbl_1_bss_6D83C[i].sentinel = -1;
    lbl_1_bss_6D848 = 0;
    for (i = 0; i < count; i++) {
        if (input[i].flags & 0x04000000)
            lbl_1_bss_6D848++;
    }
    if (lbl_1_bss_6D848 != 0) {
        lbl_1_bss_6D840 = fn_1_4630(lbl_801A6410, lbl_1_bss_6D848 * 0xa20, data + 0xe18, 0x7aa);
    }
    fn_1_818BC((void *)input, count, arg4);
    qsort(lbl_1_bss_6D83C, count, 0x440, fn_1_818AC);
    runtime = lbl_1_bss_6D838;
    object = lbl_1_bss_6D83C;
    for (i = 0; i < count; i++, runtime++, object++) {
        object->runtime = runtime;
        if (object->flags & 0x04000000)
            fn_1_983CC(runtime, object->special + 0x6e0);
        else
            fn_1_983CC(runtime, object);
        fn_80008BEC(&event, 0, 0xe8);
        event.kind = 1;
        event.index = i;
        event.runtime = runtime;
        fn_1_58E3C(&event);
    }
    shadow = fn_1_4630(lbl_801A6410, count * 0x4c, data + 0xe18, 0x7cc);
    {
        int shadowMode = lbl_1_bss_6D84A;
        lbl_1_bss_6D844 = shadow;
        fn_1_5672C(shadow, shadowMode);
    }
    fn_1_A7294(lbl_1_bss_6D83C, count);
    fn_1_A744C(lbl_1_bss_6D83C, count);
    runtime = lbl_1_bss_6D838;
    for (i = 0; i < count; i++) {
        if (runtime[i].driver != -1)
            driverCount++;
    }
    if (lbl_1_bss_960 == 2 || lbl_1_bss_960 == 14) {
        if (lbl_1_bss_8B3A0.unk_0 == 1 || lbl_1_bss_8B3A0.unk_0 == 3 || lbl_1_bss_8B3A0.unk_0 == 2) {
            fn_1_FC414(lbl_1_bss_6D828 = fn_1_45D0((void *)lbl_801A6410, 0x10440, (void *)(data + 0xe18), 0x7e2), 1);
        } else {
            fn_1_FC414(lbl_1_bss_6D828 = fn_1_45D0((void *)lbl_801A6410, 0x41100, (void *)(data + 0xe18), 0x7e7), 4);
        }
        fn_1_FCF74();
    } else if (lbl_1_bss_960 == 12) {
        fn_1_FC414(lbl_1_bss_6D828 = fn_1_45D0((void *)lbl_801A6410, 0x10440, (void *)(data + 0xe18), 0x7ee), 1);
        fn_1_FCF74();
    }
    {
    runtimeBase = lbl_1_bss_6D838;
    shadowBase = lbl_1_bss_6D844;
    objectBase = lbl_1_bss_6D83C;
    for (i = 0; i < count; i++, runtimeBase++, shadowBase++, objectBase++) {
        fn_1_435C(arg0);
        fn_1_3F8C((char *)(data + 0x14d4), fn_1_56D4C, shadowBase, 0x16);
        fn_1_435C(arg1);
        fn_1_568EC(shadowBase, runtimeBase, objectBase);
        fn_1_3F8C((char *)(data + 0x14e4), fn_1_568F8, shadowBase, 0);
        fn_1_3F8C((char *)(data + 0x14f8), fn_1_84860, objectBase, 0x11);
        if (lbl_1_bss_960 == 10)
            continue;
        if (lbl_1_bss_960 == 2 || lbl_1_bss_960 == 14 || lbl_1_bss_960 == 12) {
            if (lbl_1_bss_960 == 14) {
                /* The selected car and the single-car fallback share setup. */
                if (i == lbl_1_bss_525C.unk_F8)
                    goto setupEffects; /* fzgx-allow: S1 shared setup tail; retail keeps this exact branch chain */
                if (lbl_1_bss_525C.unk_F8 < 3)
                    continue;
                if (count == 1)
                    goto setupEffects; /* fzgx-allow: S1 single-car fallback joins the shared setup tail */
                continue;
            } else if (lbl_1_bss_960 != 12 && i >= 4) {
                continue;
            }
setupEffects:
            fn_1_82C70((void *)arg1, i, (void *)objectBase, (void *)lbl_1_bss_6D828, driverCount);
        }
    }
    }
    }
}
#undef lbl_1_bss_8B3A0
#undef lbl_1_bss_960
#undef REL_MAIN_REL_CAR_H
#undef REL_MAIN_REL_GLOBALS_H
#undef FZGX_TYPES_LBL_1_BSS_525C
#undef lbl_1_bss_6D828
#undef lbl_1_bss_6D838
#undef lbl_1_bss_6D83C
/* fzgx:end fn_1_82724 */

/* fzgx:begin fn_1_82C70 */
/* VIEWS2 */
/* VIEWS */
#define lbl_1_bss_525C (*(Fn1_82C70_Obj_525C *)&lbl_1_bss_525C)
/* the racer block (0x620 bytes); +0x474 is the controller port, -1 when none */

/* the car object (0x440 bytes a machine) */

/* a garage record (0x81C0 bytes) */

/* the emblem projection work area (0x10440 bytes a machine) */

/* lbl_1_bss_525C as this function reads it: a table of 8-byte entries led by a record pointer, and a byte at +0xF8 */

void fn_1_82C70(void *manager, u8 index, Fn1_82C70_Car *car, Fn1_82C70_Work *work_base, u8 flag) {
    u8 port;
    Fn1_82C70_Record *record;
    Fn1_82C70_Work *work;
    s16 levels;
    u8 ok;

    record = NULL;
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
        port = fn_1_8623C();
        if (index != port) {
            return;
        }
    } else {
        port = car->unk_32C->unk_474;
    }
    if (*(s16 *)&lbl_1_bss_960 == 2) {
        if (port == 0xFF) {
            return;
        }
        record = (Fn1_82C70_Record *)((u8 *)fn_1_36AD0() + port * 0x81C0);
    } else if (*(s16 *)&lbl_1_bss_960 == 14) {
        if (lbl_1_bss_525C.unk_F8 >= 3) {
            record = lbl_1_bss_525C.unk_0[lbl_1_bss_525C.unk_F8].unk_0;
        } else {
            record = lbl_1_bss_525C.unk_0[index].unk_0;
        }
        if (record == NULL) {
            return;
        }
        port = 0;
    } else if (*(s16 *)&lbl_1_bss_960 == 12) {
        port = 0;
        flag = 1;
        record = fn_1_36AD0();
        if (record->unk_0 & 0x80000000) {
            if (record->unk_0 & 0x40000000) {
                if (car->unk_328 != record->unk_5) {
                    return;
                }
            } else if (car->unk_328 != record->unk_81A0) {
                return;
            }
        }
    }
    if (record->unk_7 == 0) {
        return;
    }
    /* retail forms these four addresses from work_base + 0x10000 and the rest from the work pointer */
    work_base[port].unk_10420 = 0;
    work_base[port].unk_10428 = fn_1_FDC00;
    work_base[port].unk_1042C = fn_1_FDD7C;
    work_base[port].unk_10424 = fn_1_FDB40;
    work = &work_base[port];
    work->unk_4 = 4;
    work->unk_0 = car;
    work->unk_8 = 1.0f;
    work->unk_C = 0x40000000;
    if (*(s16 *)&lbl_1_bss_960 == 14) {
        car->unk_3BA = 1;
        work->unk_C = 0x20000000;
        levels = 2;
    } else if (flag == 1) {
        car->unk_3BA = 0;
        levels = 5;
    } else {
        car->unk_3BA = 1;
        levels = 6;
    }
    car->unk_3A4 = fn_1_7F254((void *)record, levels);
    if (car->unk_3A4 == NULL) {
        return;
    }
    ok = fn_1_FD844(record, work);
    if (ok) {
        fn_1_435C((void *)manager);
        fn_1_FE004();
        fn_1_3F8C(lbl_1_data_206D8, fn_1_FCFA4, work, 0x12);
    }
    lbl_1_bss_6D854 = ok;
}
#undef lbl_1_bss_525C
/* fzgx:end fn_1_82C70 */

/* fzgx:begin fn_1_82EDC */
void *fn_1_82EDC(s16 arg0, s16 arg1, void *arg2) {
    u8 *data;
    u32 i;
    u32 *dst;
    u32 *src;

    if (arg1 < 41) {
        dst = arg2;
        src = (u32 *)(0x23800000 + arg1 * 0xB4);
        for (i = 0; i < 45; i++) {
            dst[i] = src[i];
        }
    } else {
        if (arg0 == -1) {
            return 0;
        }
        data = ((u8 *)fn_1_36AD0()) + arg0 * 0x81C0;
        fn_1_14F6F8(data[0x81A4], data[0x81AC], data[0x81B4], arg2);
    }
    return arg2;
}
/* fzgx:end fn_1_82EDC */

/* fzgx:begin fn_1_83070 */
/* VIEWS2 */
#define lbl_1_bss_6D838 (*(F83070Car * *)&lbl_1_bss_6D838)
/* fixed-address machine descriptor table (folded literal, no relocation in retail) */

#define DESC_TABLE_BASE 0x23800000

/* copies a machine descriptor out of the fixed descriptor table */

static inline void CopyDesc(F83070Desc *out, s16 type)
{
    u32 k;
    u32 *src = (u32 *)(DESC_TABLE_BASE + type * sizeof(F83070Desc));
    u32 *dst = out->words;
    for (k = 0; k < 45; k++) {
        dst[k] = src[k];
    }
}

F83070Car *fn_1_83070(void *arg0, u32 unused, F83070Setup *items, u32 count)
{
    s8 selection[4];
    char name[32];
    F83070Desc desc;
    u32 i;
    F83070Car *car;
    u32 j;
    s16 playerIndex;
    u8 *savedata;
    u32 size;

    lbl_1_bss_6D864 = 0;
    lbl_1_bss_6D84A = count;
    for (i = 0; i < 4; i++) {
        ((u8 *)lbl_1_bss_6D868)[i] = 0xFF;
    }
    size = count * 0x620;
    lbl_1_bss_6D838 = fn_1_45D0((void *)lbl_801A6410, size, lbl_1_data_1FFF0, 0x8DC);
    fn_800793D4(lbl_1_bss_6D838, 0, size);
    lbl_1_bss_6D84B = lbl_1_bss_6D84A;
    car = lbl_1_bss_6D838;
    lbl_1_bss_6D84C = 0;
    for (i = 0; i < 4; i++) {
        lbl_1_bss_6D86C[i] = -1;
        lbl_1_bss_6D87C[i] = 0;
    }

    for (i = 0; i < count; i++, car++) {
        lbl_1_bss_6D8F4[car->index] = 0;
        for (j = 0; j < 4; j++) {
            car->part[j] = fn_1_45D0((void *)lbl_801A6410, 0xC0, lbl_1_data_1FFF0, 0x8EE);
        }
        car->unk498 = fn_1_45D0((void *)lbl_801A6410, 0x194, lbl_1_data_1FFF0, 0x8EF);
        car->unk49C = fn_1_45D0((void *)lbl_801A6410, 0x1FC, lbl_1_data_1FFF0, 0x8F0);
        savedata = ((u8 *)fn_1_36AD0());
        playerIndex = 0;
        fn_80008BA8((void *)selection, (void *)lbl_1_data_2065C, 4);
        for (j = 0; j < 4; j++) {
            if (selection[j] == i) {
                selection[j] = -1;
                playerIndex = j;
            }
        }
        if (items[i].type < 41) {
            CopyDesc(&desc, items[i].type);
        } else if (playerIndex != -1) {
            u8 *machine = ((u8 *)fn_1_36AD0()) + playerIndex * 0x81C0;
            fn_1_14F6F8(machine[0x81A4], machine[0x81AC], machine[0x81B4], (void *)&desc);
        }
        fn_1_2277C(car, &desc);
        if (items[i].type >= 41) {
            u8 *machine = savedata + playerIndex * 0x81C0;
            strncpy(car->name, fn_1_14FEAC(machine[0x81A4], machine[0x81AC], machine[0x81B4], name, 0), 31);
            car->name[31] = 0;
        }
        for (j = 0; j < 4; j++) {
            if (lbl_1_data_2065C[j] == i) {
                lbl_1_data_2065C[j] = -1;
                car->player = j;
                lbl_1_data_20664[j] = i;
            }
            if (lbl_1_data_20660[j] == i) {
                lbl_1_data_20660[j] = -1;
                car->player2 = j;
            }
        }
        car->index = i;
        car->type = items[i].type;
        fn_1_435C(arg0);
        fn_1_43E8(1);
        fn_1_3F8C(lbl_1_data_206F8, fn_1_83858, car, 7);
        fn_1_43F4();
        if (car->player == -1) {
            car->flags |= 0x04000200;
            car->ai = fn_1_45D0((void *)lbl_801A6410, 0x88, lbl_1_data_1FFF0, 0x919);
            *(u32 *)((u8 *)car->ai + 0x40) = lbl_801A6410;
            car->unk50E = 0;
            fn_1_C487C(car);
            fn_1_43E8(1);
            fn_1_3F8C(lbl_1_data_20700, fn_1_C4ABC, car, 3);
            fn_1_43F4();
        } else {
            car->flags &= 0xFBFFFDFF;
            car->ai = 0;
            lbl_1_bss_6D96C++;
        }
    }
    fn_1_8365C(1);
    lbl_1_bss_6D850 = 0;
    lbl_1_bss_6D970 = 0;
    DCFlushRange(lbl_1_bss_6D838, lbl_1_bss_6D84A * 0x620);
    fn_1_C6F80(0);
    return lbl_1_bss_6D838;
}
#undef DESC_TABLE_BASE
#undef lbl_1_bss_6D838
/* fzgx:end fn_1_83070 */

/* fzgx:begin fn_1_835E0 */
/* TU A .bss 6D974..6D97C: defined here (retail .bss order; fn_1_8365C stores 6D97C before 6D978) */
static u32 lbl_1_bss_6D974 = 0;
static s32 lbl_1_bss_6D978 = 0;
static u32 lbl_1_bss_6D97C = 0;

// Registers the car callbacks and publishes the supplied car context.

void fn_1_835E0(void *car_context, void *initial_state, void *callback_context) {
    ((u32)fn_1_435C( (void *)((u32)(initial_state))));
    lbl_1_bss_6D970 = (u32)callback_context;
    fn_1_43E8(1);
    fn_1_3F8C(lbl_1_data_20714, fn_1_850C4, car_context, 9);
    lbl_1_bss_6D974 = (u32)fn_1_8B8A4;
    fn_1_43F4();
}
/* fzgx:end fn_1_835E0 */

/* fzgx:begin fn_1_8365C */
void fn_1_8365C(s32 enabled) {
    u32 value;

    if (enabled != 0) {
        lbl_1_bss_6D97C = 0;
        value = 0;
    } else {
        lbl_1_bss_6D97C = 1;
        value = 1;
    }
    lbl_1_bss_6D978 = value;
}
/* fzgx:end fn_1_8365C */

/* fzgx:begin fn_1_83694 */
static inline void fn_1_83694_add(u8 *car, f32 a, f32 b, f32 limit)
{
    b = a + b;
    *(f32 *)(car + 0x1f8) = b;
    b = *(f32 *)(car + 0x1f8);
    if (b > limit) {
        *(f32 *)(car + 0x1f8) = limit;
    }
}

static inline void fn_1_83694_sub(u8 *car, f32 a, f32 b, f32 limit)
{
    b = a - b;
    *(f32 *)(car + 0x1f8) = b;
    b = *(f32 *)(car + 0x1f8);
    if (b < limit) {
        *(f32 *)(car + 0x1f8) = limit;
    }
}

void fn_1_83694(u8 *car)
{
    f32 a;
    s32 idx;
    f32 f3;
    u8 b;
    u32 flags;

    idx = *(s8 *)(car + 0x474);
    f3 = lbl_1_bss_C70[idx].brake;

    if ((((u8 *)&lbl_1_bss_A88)[idx * 6] >> 4) & 1) {
        a = *(f32 *)(car + 0x1fc);
        if (__fabs(a) > 0.5 && __fabs(a - *(f32 *)(car + 0x20c)) > 0.20000000298023224) {
            *(u32 *)car |= 8;
        }
    }
    if (f3 > 0.1f) {
        fn_1_83694_add(car, *(f32 *)(car + 0x1f8), 0.12f, 1.0f);
    } else if (f3 < -0.1f) {
        fn_1_83694_sub(car, *(f32 *)(car + 0x1f8), 0.12f, -1.0f);
    } else {
        *(f32 *)(car + 0x1f8) *= 0.9f;
    }
    flags = 0;
    if (f3 < -0.1f) {
        flags |= 0x10;
    }
    if (f3 > 0.1f) {
        flags |= 0x20;
    }
    if (flags == 0x10 || flags == 0x20) {
        b = *(car + 0x4c3);
        if ((b & 0xf0) == flags) {
            if ((b & 0xf) < 9) {
                *(u32 *)car |= 0x20000;
                if (f3 > 0.0f) {
                    *(s8 *)(car + 0x614) = 1;
                } else {
                    *(s8 *)(car + 0x614) = -1;
                }
                *(f32 *)(car + 0x610) = 0.49f * f3;
            } else {
                *(car + 0x4c3) = flags | 0xa;
            }
        } else {
            *(car + 0x4c3) = flags | 0xa;
        }
    }
    if (*(f32 *)(car + 0x204) > 0.1f && *(car + 0x197) < 0x1e) {
        *(u32 *)car |= 0x1000;
    }
    *(u32 *)(car + 0x58c) |= 4;
}
/* fzgx:end fn_1_83694 */

/* fzgx:begin fn_1_83858 */
/* VIEWS2 */
/* fzgx-allow: S2 pool primer sink */

#define lbl_1_bss_6D820 (*(struct fn_1_83858_lbl_1_bss_6D820 *)&lbl_1_bss_6D820)

#define lbl_1_bss_9F8 (*(struct fn_1_83858_lbl_1_bss_9F8 *)&lbl_1_bss_9F8)

static inline void fn_1_83858_clear(struct fn_1_83858_Arg0 *car) {
    car->steer = 0.0f;
    car->accel = 0.0f;
    car->pitch = 0.0f;
    car->side = 0.0f;
    car->brake = 0.0f;
}

static inline void fn_1_83858_human(struct fn_1_83858_Arg0 *car) {
    car->brake = lbl_1_bss_C70[car->port].brake;
    car->steer = car->steer * __fabs(car->steer);
    if ((lbl_1_bss_A88.unk_0[car->port].unk_0 >> 4) & 1) {
        car->unk_0 |= 0x1000;
    }
    car->unk_58C &= ~4;
}

void fn_1_83858(struct fn_1_83858_Arg0 *car) {
    s32 port;

    car->unk_614 = 0;
    car->unk_610 = 0.0f;
    if (car->unk_0 & 0x80) {
        fn_1_83858_clear(car);
    } else if (car->unk_0 & 0x4000000) {
        fn_1_C6ED4((Sig_fn_1_C6ED4_Fn1C6ED4Enemy *)car);
        if (lbl_1_bss_6D820.unk_0 != 0 && ((lbl_1_bss_9F8.unk_1C >> 10) & 1)) {
            fn_1_8DAB4();
        }
    } else {
        port = (s8)car->port;
        if (port == -1) {
            fn_1_83858_clear(car);
        } else {
            if (lbl_1_bss_6D820.unk_0 != 0 && ((lbl_1_bss_9F8.unk_1C >> 10) & 1)) {
                fn_1_8D894((Obj_1_bss_6D838_Target *)car);
            }
            car->steer = lbl_1_bss_C70[port].steer;
            car->accel = lbl_1_bss_C70[port].accel;
            car->pitch = lbl_1_bss_C70[port].pitch;
            car->side = lbl_1_bss_C70[port].side;
            if (((lbl_1_bss_A88.unk_0[port].unk_0 >> 7) & 1) && __fabs(car->steer) > 0.8f) {
                car->unk_0 |= 0x20000;
                car->unk_610 = 0.4f * car->steer;
                if (car->steer > 0.0f) {
                    car->unk_614 = 1;
                } else {
                    car->unk_614 = -1;
                }
            }
            if (!(car->unk_0 & 0x8000) && car->unk_481 > 60 && ((lbl_1_bss_A88.unk_0[port].unk_0 >> 5) & 1) &&
                __fabs(car->steer) > 0.2f) {
                car->unk_0 |= 8;
            }
            if ((lbl_1_bss_CC0.unk_0[port] >> 2) & 1) {
                car->unk_0 |= 0x2000;
            }
            if ((lbl_1_bss_CC0.unk_0[port] >> 6) & 1) {
                car->unk_0 |= 0x40;
            }
            switch (car->unk_590) {
            case 1:
                fn_1_83858_human(car);
                break;
            case 2:
                if (lbl_1_bss_D70.unk_0[car->port] != 0) {
                    fn_1_83694((u8 *)car);
                } else {
                    fn_1_83858_human(car);
                }
                break;
            case 3:
                if (lbl_1_bss_D70.unk_0[car->port] != 0) {
                    fn_1_83694((u8 *)car);
                } else {
                    fn_1_83858_human(car);
                }
                break;
            case 4:
                fn_1_83694((u8 *)car);
                break;
            default:
                fn_1_83858_clear(car);
                break;
            }
        }
    }
    if (lbl_1_bss_6D978 != 0) {
        car->unk_0 |= 1;
    }
    if (lbl_1_bss_6D850 != 0) {
        ((fn_1_83858_Fn0)lbl_1_bss_6D850)((u32)car);
    }
    fn_1_236CC((u32)car);
    fn_1_83CB0((Sig_fn_1_83CB0_Fn183CB0Object *)car);
    if (lbl_1_bss_6D8F4[car->unk_4] != 0) {
        lbl_1_bss_6D8F4[car->unk_4]--;
    }
}

#undef lbl_1_bss_6D820
#undef lbl_1_bss_9F8
/* fzgx:end fn_1_83858 */

/* fzgx:begin fn_1_83CB0 */
void fn_1_83CB0(Sig_fn_1_83CB0_Fn183CB0Object *obj) {
    Vec3 local = {0.0f, 0.5f, 0.5f};
    f32 z;
    f32 y;
    f32 x;

    lbl_8006DC6C(obj->field_ec);
    x = obj->field_7c;
    y = obj->field_80;
    z = obj->field_84;
    mtx_set_translate((void *)LC_BASE, x, y, z);
    lbl_8006E1B0(&local, obj->field_4a0);
}
/* fzgx:end fn_1_83CB0 */

/* fzgx:begin fn_1_83D28 */
s8 fn_1_83D28(DistanceState *state, f32 scale)
{
    s8 result = -1;
    s8 level;
    DistanceObject *object;
    s8 mode;
    u8 value;
    f32 camera_a;
    f32 camera_b;
    struct { f32 x, y, z; } vector;
    f32 diameter;
    f32 depth;
    f32 distance;
    f32 threshold;

    level = fn_1_84124((void *)state, 1, 0, (void *)&value);
    if (state->flags & 0x04000000) {
        object = *state->other->levels[level]->object;
    } else {
        object = *state->levels[level].object;
    }
    if (object == 0) {
        return -1;
    }
    diameter = 2.0f * object->radius * scale;
    lbl_8006DFE8((u8 *)state->projection + 0x14C);
    if (fn_1_54E34(&object->vector, object->radius) == 0) {
        return 5;
    }
    lbl_8006E1B0((u8 *)object + 8, &vector);
    if (vector.z > -1.1920928955078125e-7f) {
        return level;
    }
    depth = -vector.z * fn_1_A71AC();
    mode = fn_1_84644((void *)state->projection);
    lbl_1_bss_6D980[state->index] = 0;
    distance = 240.0f * diameter / depth;
    if (camera_get_values(&camera_a, &camera_b)) {
        distance *= camera_b;
    }
    if ((s8)fn_1_A5DC4()) {
        distance *= 0.75f;
    }
    {
    s8 i;
for (i = 0; i < 6; i++) {
        threshold = state->levels[i + 1].threshold;
        if (i == 3) {
            if (mode == 0) {
                threshold = 2.0f;
            } else if (distance < lbl_1_data_1FFE0) {
                lbl_1_bss_6D980[state->index] = 1;
            }
        }
        if (distance > threshold) {
            if (i > 0) {
                f32 ratio = distance / (state->levels[i].threshold + threshold);
                if (ratio > 0.5f) {
                    ((u8 *)&lbl_1_bss_6D9A0)[state->index] = 0;
                } else {
                    ((u8 *)&lbl_1_bss_6D9A0)[state->index] = 1;
                }
            } else {
                ((u8 *)&lbl_1_bss_6D9A0)[state->index] = 1;
            }
            if (i == 4) {
                i = 5;
            }
            result = i;
            break;
        }
        if (threshold < 0.0f) {
            result = i;
            break;
        }
    }
    level = i;
}
    if (result == 5 && state->projection != 0 && state->projection->value == 0.0f) {
        lbl_1_bss_6D980[state->index] = 0;
        result--;
    }
    return result;
}
/* fzgx:end fn_1_83D28 */

/* fzgx:begin fn_1_84038 */
f32 fn_1_84038(Fn184038Object *obj, s16 index, u8 use_table, f32 value) {
    f32 saved_value = value;
    void *entry;
    Fn184038Result result;

    if (use_table != 0) {
        entry = ((void **)((u8 *)obj->field_3a0 + 0x344))[index];
        entry = *(void **)((u8 *)entry + 4);
    } else {
        entry = (u8 *)obj + index * 0xc;
        entry = *(void **)((u8 *)entry + 0x334);
        entry = *(void **)entry;
    }

    if (entry == NULL) {
        return (-1.0f);
    }

    lbl_8006DFE8((u8 *)obj->field_32c + 0x14c);
    lbl_8006E1B0((u8 *)entry + 8, &result);

    if (result.value > (-1.1920929e-07f)) {
        return (1000.0f);
    }

    return (240.0f) * ((2.0f) * *(f32 *)((u8 *)entry + 0x14) * saved_value) / (-result.value * fn_1_A71AC());
}
/* fzgx:end fn_1_84038 */

/* fzgx:begin fn_1_84124 */
s8 fn_1_84124(Fn184124Object *obj, s8 direction, s8 index, u8 *count) {
    *count = 0;

    if (index == 5) {
        return index;
    }

    if (index < 0 || index > 5) {
        return index < 0 ? 0 : (index > 5 ? 5 : index);
    }

    if (direction == 1) {
        while (index < 5) {
            if (obj->flags & (1 << index)) {
                return index;
            }
            index++;
            (*count)++;
        }
    } else if (direction == -1) {
        while (index > -1) {
            if (obj->flags & (1 << index)) {
                return index;
            }
            index--;
            (*count)++;
        }
    }

    return -1;
}
/* fzgx:end fn_1_84124 */

/* fzgx:begin fn_1_8421C */
static inline s8 clamp_selection(s8 value) {
    return value < 0 ? 0 : value > 5 ? 5 : value;
}

static inline s8 forward_selection(struct fn_1_8421C_Arg0 *arg0, s8 arg1, s8 *distance) {
    s8 v0;
    if (arg1 == 5) return arg1;
    if (arg1 < 0 || arg1 > 5) return clamp_selection(arg1);
    v0 = arg1;
    while (v0 < 5) {
        if (arg0->unk_38C & (1 << v0)) return v0;
        v0++;
        (*distance)++;
    }
    return -1;
}

static inline s8 backward_selection(struct fn_1_8421C_Arg0 *arg0, s8 arg1, s8 *distance) {
    if (arg1 == 5) return arg1;
    if (arg1 < 0 || arg1 > 5) return clamp_selection(arg1);
    while (arg1 > -1) {
        if (arg0->unk_38C & (1 << arg1)) return arg1;
        arg1--;
        (*distance)++;
    }
    return -1;
}

static inline s8 select_result(struct fn_1_8421C_Arg0 *arg0, s8 v0, s8 v3, s8 v1, s8 v4) {
    if (v0 == -1) return v3;
    if (v3 == -1) return v0;
    if (v1 > v4) return v0;
    if (v1 < v4) return v3;
    if (lbl_1_bss_6D9A0[arg0->unk_320] == 1) return v0;
    return v3;
}

s8 fn_1_8421C(struct fn_1_8421C_Arg0 *arg0, s8 arg1) {
    s8 v0;
    s8 v1 = 0;
    s8 v3;
    s8 v4;
    v0 = forward_selection(arg0, arg1, &v1);
    v4 = 0;
    v3 = backward_selection(arg0, arg1, &v4);
    if (v0 == -1 && v3 == -1) return 3;
    return select_result(arg0, v0, v3, v1, v4);
}
/* fzgx:end fn_1_8421C */

/* fzgx:begin fn_1_843BC */
f32 fn_1_843BC(Fn1843BCObject *obj) {
    if (obj == NULL) {
        return 1.0f;
    }

    if (obj->field_32c == NULL) {
        return 1.0f;
    }

    return fn_1_86A2C((void *)obj->field_32c);
}
/* fzgx:end fn_1_843BC */

/* fzgx:begin fn_1_84408 */
/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* end game/main_rel/car_test_types.h */

#define fn_1_84408 fn_1_84408_header_decl

#undef fn_1_84408

#define CAR_LANE_BITS(car) ((car)->pad_378[0x14])

static inline s8 fn_1_84408_findUp(Fn183D28Car *car, s8 start, s8 *result)
{
    s8 count;

    count = 0;
    if (start == 5) {
        *result = start;
    } else if (start < 0 || start > 5) {
        *result = start < 0 ? 0 : (start > 5 ? 5 : start);
    } else {
        for (*result = start; *result < 5; (*result)++, count++) {
            if (CAR_LANE_BITS(car) & (1 << *result)) {
                return count;
            }
        }
        *result = -1;
    }
    return count;
}

static inline s8 fn_1_84408_findDown(Fn183D28Car *car, s8 start, s8 *count)
{
    s8 i;

    *count = 0;
    if (start == 5) {
        return start;
    }
    if (start < 0 || start > 5) {
        return start < 0 ? 0 : (start > 5 ? 5 : start);
    }
    for (i = start; i > -1; i--, (*count)++) {
        if (CAR_LANE_BITS(car) & (1 << i)) {
            return i;
        }
    }
    return -1;
}

s8 fn_1_84408(CarTestCar *arg0)
{
    Fn183D28Car *car = (Fn183D28Car *)arg0;
    s8 cur;
    s8 upCount;
    s8 down;
    s8 up;
    s8 downCount;

    if (car->body == NULL) {
        fn_1_84408_findUp(car, 3, &up);
        fn_1_84408_findDown(car, 3, &downCount);
    }
    cur = fn_1_83D28((void *)car, 0.5f);
    upCount = fn_1_84408_findUp(car, cur, &up);
    down = fn_1_84408_findDown(car, cur, &downCount);
    if (up == -1 && down == -1) {
        return 3;
    }
    if (up == -1) {
        return down;
    }
    if (down == -1) {
        return up;
    }
    if (upCount > downCount) {
        return up;
    }
    if (upCount < downCount) {
        return down;
    }
    if (lbl_1_bss_6D9A0[car->index] == 1) {
        return up;
    }
    return down;
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef CAR_LANE_BITS
/* fzgx:end fn_1_84408 */

/* fzgx:begin fn_1_84644 */
/* Unknown retail object: .rodata 3AB8..3B1F, no retail function reads it (s32 -1 pair, then 1.0f / 0.0f words) */
static const u32 lbl_1_rodata_3AB8[26] = {
    0xFFFFFFFF, 0xFFFFFFFF, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000,
    0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000,
    0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000,
    0x00000000, 0x3F800000,
};

s8 fn_1_84644(Fn184644Object *obj) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 delta0;
    Vec3 delta1;
    u32 index;
    f32 result;

    index = (u8)(fn_1_5910());
    fn_1_681C( (u8)(index), (void *)((u32 *)(Vec3 *)(&v0)));
    fn_1_6914( (u8)(index), (u32 *)(Vec3 *)(&v1));

    psvec_sub(&v1.x, &v0.x, &delta0.x);
    lbl_8006DBAC((void *)&obj->field_14c);

    {
        Vec3 basis = {0.0f, 0.0f, -1.0f};
        lbl_8006E1B0(&basis, (Vec3 *)(&v2));
    }

    psvec_sub(&v2.x, &obj->field_07c.x, &delta1.x);
    result = lbl_8006D534(&delta0, &delta1);
    return (result > 0.8f);
}
/* fzgx:end fn_1_84644 */

/* fzgx:begin fn_1_8472C */
void *fn_1_8472C(Fn18472CObject *obj) {
    s16 index;

    index = -1;
    if (obj->field_6 >= 0x29) {
        index = obj->field_6 - 0x32;
    }

    if (index == -1) {
        return NULL;
    }

    return ((u8 *)fn_1_36AD0()) + index * 0x81c0;
}
/* fzgx:end fn_1_8472C */

/* fzgx:begin fn_1_84794 */
u8 fn_1_84794(s32 index) {
    return lbl_1_bss_6D868[(s16)index];
}
/* fzgx:end fn_1_84794 */

/* fzgx:begin fn_1_847A8 */
s16 fn_1_847A8(s16 value, s16 divisor) {
    s16 selected = 0;

    switch (value) {
    case 0:
    case 12:
    case 19:
    case 20:
        selected = 0;
        break;
    case 1:
    case 3:
    case 6:
    case 7:
    case 9:
    case 13:
    case 14:
    case 15:
    case 17:
    case 30:
        selected = 1;
        break;
    case 8:
    case 28:
    case 31:
        selected = 2;
        break;
    case 2:
    case 4:
    case 5:
    case 10:
    case 11:
    case 16:
    case 18:
    case 23:
    case 37:
        selected = 3;
        break;
    case 22:
    case 24:
    case 38:
        selected = 4;
        break;
    case 21:
        selected = 5;
        break;
    case 26:
    case 27:
        selected = 6;
        break;
    case 29:
        selected = 7;
        break;
    case 32:
        selected = 8;
        break;
    case 25:
    case 33:
        selected = 9;
        break;
    case 34:
        selected = 10;
        break;
    case 35:
        selected = 11;
        break;
    case 36:
        selected = 12;
        break;
    case 39:
        selected = 13;
        break;
    case 40:
        selected = 14;
        break;
    }

    return (selected % divisor);
}
/* fzgx:end fn_1_847A8 */

/* fzgx:begin fn_1_84860 */
/* .rodata 3B30..3B67: 14 pointers to the .data strings 20720..207A0 ("CARCV0" .. "CARLOD_NODISP"), from the retail
   relocations. No retail function reads the table (inferred: a debug print that the retail link removed used it).
   The strings stay the named .data objects of the TU data model. */
static char *const lbl_1_rodata_3B30[14] = {
    lbl_1_data_20720, lbl_1_data_20728, lbl_1_data_20730, lbl_1_data_20738,
    lbl_1_data_20740, lbl_1_data_20748, lbl_1_data_20750, lbl_1_data_20758,
    lbl_1_data_20760, lbl_1_data_2076C, lbl_1_data_20778, lbl_1_data_20784,
    lbl_1_data_20790, lbl_1_data_207A0,
};

/* .rodata 3B68 / 3B6C: the two black tints fn_1_84860 copies before its fn_1_5631C calls */
static const GXColor burner_tint_clear = {0, 0, 0, 0};
static const GXColor burner_tint_reset = {0, 0, 0, 0};

/* Unknown retail function: the retail link removed it and no surviving code holds a copy of it.
   Its literals are .rodata 3B70..3B7F (f64 0.0, f64 1.0), created before fn_1_84860's first literal (15.0f at .rodata 3B80).
   The retail body is not known: this placeholder only recreates the literals 3B70..3B7F in retail order.
   WARNING: compiler-diff device, not original code (the body is a placeholder that only rebuilds the literals) */
/* WARNING: compiler-diff device, not original code */
static f64 car_literal_order_3B70(f64 x)
{
    if (x < 0.0) {
        x = -x;
    }
    return x - 1.0;
}
/* VIEWS2 */
/* VIEWS */
#define lbl_1_bss_3BE0 (*(void * *)&lbl_1_bss_3BE0)
/* The TU's .bss objects starting at lbl_1_bss_6D820, addressed off one section base. */

/* Nearest set bit of car->unk_38c above (2..4) and at/below (2..0) slot 2. */

static inline s8 burner_scan_up(BurnerCar *car, s8 *count) {
    s8 i;

    *count = 0;
    for (i = 2; i < 5; i++, (*count)++) {
        if (car->unk_38c & (1 << i)) {
            return i;
        }
    }
    return -1;
}

static inline s8 burner_scan_down(BurnerCar *car, s8 *count) {
    s8 i;

    *count = 0;
    for (i = 2; i > -1; i--, (*count)++) {
        if (car->unk_38c & (1 << i)) {
            return i;
        }
    }
    return -1;
}

static inline s8 burner_pick_slot(BurnerCar *car) {
    s8 nlo;
    s8 nhi;
    s8 hi = burner_scan_up(car, &nhi);
    s8 lo = burner_scan_down(car, &nlo);

    if (hi == -1 && lo == -1) {
        return 3;
    }
    if (hi == -1) {
        return lo;
    }
    if (lo == -1) {
        return hi;
    }
    if (nhi > nlo) {
        return hi;
    }
    if (nhi < nlo) {
        return lo;
    }
    if (lbl_1_bss_6D9A0[car->index] == 1) {
        return hi;
    }
    return lo;
}

void fn_1_84860(BurnerCar *car) {
    GXColor color;
    GXColor shadow;
    u32 flags;
    BurnerBody *body;
    BurnerTarget *target;
    s8 idx;
    s32 enable;
    s16 mode;
    f32 t;
    f32 scale;
    s16 model;

    flags = car->flags;
    body = car->body;
    if (flags & 0x1000000) {
        return;
    }
    idx = car->slot;
    if (idx == 5) {
        return;
    }
    if (flags & 0x4000000) {
        target = *car->alt->slots[idx]->target;
    } else {
        target = *car->entries[idx].target;
    }
    if (target == NULL) {
        OSReport("No LOD\n");
        return;
    }

    enable = 0;
    if (lbl_1_bss_3BE0 != NULL && fn_1_1FB80(body->unk_7c, 0x2000) != 0) {
        enable = 1;
    }
    lbl_1_bss_6D9C0[body->id] = enable;
    if (lbl_1_bss_6D9C0[body->id] != 0) {
        mode = fn_1_7B054();
        color = (*lbl_1_data_2A8D8[lbl_1_data_2B0D4[mode]])->color;
        if (mode == 40) {
            if (lbl_1_bss_6D87C[body->id] < 15) {
                lbl_1_bss_6D87C[body->id]++;
            }
            /* fade progress, clamped to 0..1 */
            t = (t = lbl_1_bss_6D87C[body->id] / 15.0f) < 0.0 ? 0.0 : (t > 1.0 ? 1.0 : t);
            color.r *= 1.0f - t;
            color.g *= 1.0f - t;
            color.b *= 1.0f - t;
        } else {
            color.r *= 0.01f;
            color.g *= 0.01f;
            color.b *= 0.01f;
        }
        fn_1_55FD0(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
    } else {
        mode = fn_1_7B054();
        if (mode == 40 && lbl_1_bss_6D87C[body->id] > 0) {
            lbl_1_bss_6D87C[body->id]--;
            t = (t = lbl_1_bss_6D87C[body->id] / 15.0f) < 0.0 ? 0.0 : (t > 1.0 ? 1.0 : t);
            color = (*lbl_1_data_2A8D8[lbl_1_data_2B0D4[mode]])->color;
            color.r *= 1.0f - t;
            color.g *= 1.0f - t;
            color.b *= 1.0f - t;
            fn_1_55FD0(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
        }
    }

    if (lbl_1_bss_6DA38 != 0) {
        scale = 1.0f;
    } else {
        scale = fn_1_86A2C((void *)body);
    }
    if (lbl_1_bss_6D858 != 0 && body->id == 0 && !(body->flags & 0x80)) {
        fn_1_8E244((void *)body->pos);
    }
    if (0.0f != scale) {
        lbl_8006DFE8((void *)body->pos);
        if (fn_1_54E34((void *)target->dir, target->radius) != 0) {
            fn_1_566EC(1, 0xff);
            if (!(car->flags & 0x200000) && 1.0f == scale) {
                if (fn_1_3EFA8() == 0) {
                    fn_1_A77DC((void *)car);
                }
                fn_1_A7854((void *)car, NULL);
            }
            model = -1;
            if (body->kind >= 41) {
                model = body->kind - 50;
            }
            fn_1_151BDC(model == -1 ? NULL : &((BurnerBig *)fn_1_36AD0())[model]);
            fn_1_86E08((void *)car->body);
            if (car->flags & 0x40000) {
                GXColor c1 = burner_tint_clear;
                fn_1_5631C(&c1);
            }
            if (car->flags & 0x200000) {
                fn_80072558();
                fn_1_55210(((BurnerList *)lbl_1_bss_6D85C.unk_0)->items[fn_1_847A8(car->unk_328, ((BurnerList *)lbl_1_bss_6D85C.unk_0)->count) * 2]);
            } else {
                if (fn_1_A728C(body->id)) {
                    idx = burner_pick_slot(car);
                }
                fn_1_870BC((void *)car, idx, (s32)car, 1, car->unk_3b8, scale);
            }
            {
                GXColor c2 = burner_tint_reset;
                fn_1_5631C(&c2);
            }
            fn_1_566EC(0, 0);
        }
        if (!(car->flags & 0x200000)) {
            shadow.r = 0;
            shadow.g = 0;
            shadow.b = 0;
            shadow.a = 128.0f * scale;
            fn_1_5745C((u8 *)lbl_1_bss_6D844 + body->id * 0x4c, &shadow);
        }
    }

    if (lbl_1_bss_6D9C0[body->id] != 0) {
        color = (*lbl_1_data_2A8D8[lbl_1_data_2B0D4[mode]])->color;
        fn_1_55FD0(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
    }
}
#undef lbl_1_bss_3BE0
/* fzgx:end fn_1_84860 */

/* fzgx:begin fn_1_850C4 */
/* Unknown retail object: .data 2089C, a debug format string no retail function reads (after fn_1_84860's literal) */
static char lbl_1_data_2089C[12] = "%2.2f m/f\n";

void fn_1_850C4(Race8B9B8 *racer) {
State850C4 *state;
u32 i;
u32 j;
u8 forced;
s32 wasSet;
u32 flags;
u32 bit;
Owner850C4 *a;
Owner850C4 *b;
Car850C4 *car;
s32 slot;
u8 best;
u8 rank;
state = (State850C4 *)&lbl_1_bss_6D820;
forced = 0;
flags = racer->flags;
bit = flags & 0x200000;
wasSet = (flags >> 21) & 1;
if (racer != ((void *)0) ) {
if (flags & 0x20) {
racer = ((void *)0) ;
} else if (!(flags & 0x4000) || bit) {
forced = 1;
racer->flags |= 0x200000;
}
}
for (i = 0; i < state->count; i++) {
for (j = i + 1; j < state->count; j++) {
if (fn_1_239C4(&state->cars[i], &state->cars[j]) != 0) {
a = ((Owner850C4 *)fn_1_868C0((state->cars)[i].id));
b = ((Owner850C4 *)fn_1_868C0((state->cars)[j].id));
if (a->flags & 0x200000) {
fn_1_25004((void *)&state->cars[i]);
}
if (b->flags & 0x200000) {
fn_1_25004((void *)&state->cars[j]);
}
fn_1_68B6C(i, j);
}
}
}
for (car = (state->cars), j = 0; j < state->count; j++, car++) {
if (car->flags58C & 8) {
lbl_8006DBAC((void *)&car->vecEC);
mathutil_mtxA_set_translate(&car->pos);
fn_1_266A8(car);
}
}
for (car = state->cars, i = 0; i < state->count; i++, car++) {
fn_1_24A4C(car);
}
for (car = state->cars, i = 0; i < state->count; i++, car++) {
fn_1_8A1B4((void *)car, (s32)(((void *)0)), (void *)racer);
}
if (!forced && state->f158 == 0) {
for (car = state->cars, i = 0; i < state->count; i++, car++) {
CarInfo850C4 *info = car->info;
if (!(car->flags & 0x08010000) && racer != ((void *)0) ) {
s32 ok = info->lap >= racer->lap;
ok &= state->f158 == 0 && !(racer->flags & 0x40);
if (ok) {
fn_1_250F8(car);
}
}
}
} else {
for (car = state->cars, i = 0; i < state->count; i++, car++) {
car->f184 = 100.0f;
}
}
if (racer != ((void *)0) ) {
state->racerHook(racer);
state->racerHook = fn_1_8B9B8;
racer->slotMask = 0;
best = state->count;
for (car = state->cars, i = 0; i < state->count; i++, car++) {
slot = -1;
if (!(car->flags & 0x20000000)) {
if (i < ((u32)fn_1_3F854())) {
slot = i;
} else {
rank = car->info->rank;
if (rank < best) {
slot = 4;
best = rank;
}
}
if (slot != -1) {
racer->slotMask |= 1 << slot;
racer->slots[slot] = car->pos;
}
}
}
}
if (state->carHook != ((void *)0) ) {
for (car = state->cars, i = 0; i < state->count; i++, car++) {
state->carHook(car);
}
}
state->f158 = state->f15C != 0;
if (racer != ((void *)0) && wasSet == 0) {
racer->flags &= ~0x200000;
}
}

/* fzgx:end fn_1_850C4 */

/* fzgx:begin fn_1_854D4 */
/* VIEWS2 */
#define lbl_1_bss_6D838 (*(Car_854D4 * *)&lbl_1_bss_6D838)
void fn_1_854D4(void) {

    u32 i;
    Car_854D4 *car;
    u32 j;
    u32 t;
    ((s8 *)(((u8 *)lbl_1_data_2065C)))[0] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20660)))[0] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20664)))[0] = -1;
    ((s8 *)(((u8 *)lbl_1_data_2065C)))[1] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20660)))[1] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20664)))[1] = -1;
    ((s8 *)(((u8 *)lbl_1_data_2065C)))[2] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20660)))[2] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20664)))[2] = -1;
    ((s8 *)(((u8 *)lbl_1_data_2065C)))[3] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20660)))[3] = -1;
    ((s8 *)(((u8 *)lbl_1_data_20664)))[3] = -1;
    car = lbl_1_bss_6D838;
    for (i = 0; i < lbl_1_bss_6D84A; i++, car++) {
        if (car->p484 != 0) {
            t = fn_80008E84(*(u32 *)(car->p484 + 0x40));
            fn_1_46B4(lbl_801A6410, car->p484, (void *)(((char *)(((u8 *)lbl_1_data_1FFF0)))), 0xdd2);
            car->p484 = 0;
            fn_80008E84(t);
        }
        for (j = 0; j < 4; j++) {
            if (car->p488[j] != 0) {
                fn_1_46B4(lbl_801A6410, car->p488[j], (void *)(((char *)(((u8 *)lbl_1_data_1FFF0)))), 0xdd9);
                car->p488[j] = 0;
            }
        }
        if (car->p498 != 0) {
            fn_1_46B4(lbl_801A6410, car->p498, (void *)(((char *)(((u8 *)lbl_1_data_1FFF0)))), 0xddf);
            car->p498 = 0;
        }
        if (car->p49c != 0) {
            fn_1_46B4(lbl_801A6410, car->p49c, (void *)(((char *)(((u8 *)lbl_1_data_1FFF0)))), 0xde4);
            car->p49c = 0;
        }
    }
    fn_1_1071C0();
    fn_1_46B4(lbl_801A6410, (u32)lbl_1_bss_6D838, (void *)(((char *)(((u8 *)lbl_1_data_1FFF0)))), 0xdeb);
    lbl_1_bss_6D838 = 0;
    lbl_1_bss_6D84A = 0;
    lbl_1_bss_6D96C = 0;
}
#undef lbl_1_bss_6D838
/* fzgx:end fn_1_854D4 */

/* fzgx:begin fn_1_85688 */
/* VIEWS2 */
#define lbl_1_bss_6D83C (*(Fn85688Car * *)&lbl_1_bss_6D83C)
#define lbl_1_bss_6D840 (*(u32 *)&lbl_1_bss_6D840)
#define lbl_1_bss_6D844 (*(u32 *)&lbl_1_bss_6D844)
void fn_1_85688(void) {
    Fn80294Item *q;
    s8 j;
    s16 i;
    Fn85688Car *cars;
    u32 t_2;
    s32 cnt;
    u32 t;

    fn_1_56858((void *)lbl_1_bss_6D844, lbl_1_bss_6D84A);
    fn_1_46B4(lbl_801A6410, lbl_1_bss_6D844, lbl_1_data_1FFF0, 0xdfa);

    i = 0;
    goto loop1_test; /* Keep the verified branch to loop1_test. */
loop1_body:
    if ((*((lbl_1_bss_6D83C) + i)).unk_324 != -1) {
        fn_1_12A734((*((lbl_1_bss_6D83C) + i)).unk_324);
        (*((lbl_1_bss_6D83C) + i)).unk_324 = -1;
    }
    i++;
loop1_test:
    cnt = (s8)lbl_1_bss_6D84A;
    if (i < cnt) goto loop1_body; /* Keep the verified branch to loop1_body. */

    cars = lbl_1_bss_6D83C;
    for (j = 0; j < cnt; j++) {
        fn_1_7F658((void *)&cars[j]);
    }
    fn_1_46B4(lbl_801A6410, (u32)cars, lbl_1_data_1FFF0, 0x2b3);

    t = lbl_1_bss_6D82C;
    if (t) {
        fn_80071718(t);
        lbl_1_bss_6D82C = 0;
    }
    t = lbl_1_bss_6D840;
    if (t) {
        fn_1_46B4(lbl_801A6410, t, lbl_1_data_1FFF0, 0xdff);
        lbl_1_bss_6D840 = 0;
    }
    lbl_1_bss_6D848 = 0;
    fn_1_591A0(1);
    q = &lbl_1_bss_6D85C;
    lbl_1_bss_6D844 = 0;
    lbl_1_bss_6D83C = 0;
    if (q->unk_4) {
        fn_80071718(q->unk_4);
        fn_800711A8(lbl_1_bss_6D85C.unk_0);
        q->unk_4 = 0;
        lbl_1_bss_6D85C.unk_0 = 0;
    }
    if (lbl_1_bss_6D858 != 0) {
        fn_1_8E1E8();
    }
    if (*(s16 *)&lbl_1_bss_960 == 14 || *(s16 *)&lbl_1_bss_960 == 2 || *(s16 *)&lbl_1_bss_960 == 12) {
        fn_1_FDFF4();
        t_2 = lbl_1_bss_6D828;
        if (t_2) {
            fn_1_46B4(lbl_801A6410, t_2, lbl_1_data_1FFF0, 0xe1b);
            lbl_1_bss_6D828 = 0;
        }
    }
}
/* fzgx:end fn_1_85688 */

/* fzgx:begin fn_1_85878 */
void fn_1_85878(void) {
    fn_1_85688();
    fn_1_854D4();
}
/* fzgx:end fn_1_85878 */

/* fzgx:begin fn_1_8589C */
void fn_1_8589C(u32 value) {
    lbl_1_bss_6D864 = value;
}
/* fzgx:end fn_1_8589C */

/* fzgx:begin fn_1_858A8 */
s32 fn_1_858A8(s16 *a, s16 *b) {
    Fn858A8Data *obj;
    Obj_1_bss_6D838_Target *entry_a;
    Obj_1_bss_6D838_Target *entry_b;
    s16 ia = *a;
    s16 ib = *b;

    entry_a = &lbl_1_bss_6D838[ia];
    obj = (Fn858A8Data *)lbl_1_bss_6D864;
    entry_b = &lbl_1_bss_6D838[ib];

    if (((0) != obj) && obj->unk_A7 != 0) {
        u16 index = obj->unk_A7 - 1;
        u8 *data = obj->unk_E2;

        return (data + entry_b->unk_4 * 0xA0)[index] -
               (data + entry_a->unk_4 * 0xA0)[index];
    }
    return (s8)entry_a->unk_474 - (s8)entry_b->unk_474;
}
#undef lbl_1_bss_6D83C
#undef lbl_1_bss_6D840
#undef lbl_1_bss_6D844
/* fzgx:end fn_1_858A8 */

/* fzgx:begin fn_1_85934 */
/* VIEWS2 */
#define lbl_1_bss_6D83C (*(Fn85934Record * *)&lbl_1_bss_6D83C)
#define lbl_1_bss_6D864 (*(u8 * *)&lbl_1_bss_6D864)
void fn_1_85934(f32 arg) {
    s16 order[48];
    Fn14F04Result *result;
    Obj_1_bss_6D838_Target *car;
    s32 count;
    s32 i;
    f32 value;

    value = 0.0f;
    if (*(s16 *)&lbl_1_bss_960 == 12) {
        for (i = 0; i < lbl_1_bss_6D84A; i++) {
            order[i] = lbl_1_bss_26B80[i * 5 + 4];
        }
    } else {
        for (i = 0; i < lbl_1_bss_6D84A; i++) {
            order[i] = i;
        }
        qsort(order, lbl_1_bss_6D84A, 2, fn_1_858A8);
    }

    if (lbl_1_bss_3BE0 != 0) {
        result = (Fn14F04Result *)fn_1_14F04();
        count = lbl_1_bss_3BE0->unk_8;
        if (count > 0) {
            count--;
        } else {
            count = 0;
        }
        fn_1_17920(count, 1.0f, 0);
        value = result->value;
    }

    for (i = 0; i < lbl_1_bss_6D84A; i++) {
        car = &lbl_1_bss_6D838[order[i]];
        if (lbl_1_bss_6D83C != 0) {
            lbl_1_bss_6D83C[order[i]].unk_390 &= ~0x200000;
            lbl_1_bss_6D83C[order[i]].unk_390 &= ~0x1000000;
        }
        if (lbl_1_bss_6D864 != 0) {
            lbl_1_bss_6D864[order[i] + 0xE] = i;
        }
        lbl_1_bss_6DA3C[i] = order[i];
        lbl_1_bss_6DA5C[order[i]] = i;
        fn_1_85C58(i, value);
        fn_1_85F70(car, arg);
    }
    fn_1_8B880();
}
#undef lbl_1_bss_6D83C
#undef lbl_1_bss_6D864
/* fzgx:end fn_1_85934 */

/* fzgx:begin fn_1_85C58 */



void fn_1_85C58(s32 index, f32 arg1) {
    f32 *px;
    f32 base[5] = {19.0f, 15.0f, 19.0f, 19.0f, 19.0f};
    f32 step[5] = {12.9f, 13.0f, 13.0f, 13.0f, 13.0f};
    u8 count[5] = {6, 1, 4, 6, 2};
    f32 scale[5] = {0.5f, 0.5f, 0.5f, 0.5f, 0.2f};
    f32 sign[5] = {1.0f, 1.0f, -1.0f, -1.0f, 1.0f};
    u8 kind;
    u8 *p;
    int hit;
    f32 z;
    u8 n;
    Vec3 pos;
    f32 height;
    f32 k;
    f32 offset;
    f32 start;

    /* course 37, 39 or 43 in story mode (mode 9), or course 45, picks its own table entry */
    if (*(s16 *)&lbl_1_bss_960 == 9 && fn_1_7B054() == 37) {
        kind = 1;
    } else if (*(s16 *)&lbl_1_bss_960 == 9 && fn_1_7B054() == 39) {
        kind = 2;
    } else if (*(s16 *)&lbl_1_bss_960 == 9 && fn_1_7B054() == 43) {
        kind = 3;
    } else if (fn_1_7B054() == 45) {
        kind = 4;
    } else {
        kind = 0;
    }

    if (lbl_1_bss_3BE0 != NULL) {
        p = ((u8 *)fn_1_14F04()) + 0x400;
        k = 0.0f;
        px = (f32 *)&pos;
        px[0] = 0.0f;
        px[1] = 0.0f;
        start = base[kind];
        offset = index * step[kind];
        px[2] = z = start + offset;
        hit = fn_1_20994(&pos, &height);
        fn_1_17920(hit, height, 0);
        lbl_8006DBAC((void *)((Vec3 *)p));
        if (lbl_1_bss_3BE0->unk_7D != 0 && hit == 0 && height < 0.0f) {
            lbl_8006E0B4(0.0f, 0.0f, z);
        }
        n = count[kind];
        if (n > 1) {
            f32 drift = k * (*(f32 *)(p + 0x68) - arg1);
            f32 spread = sign[kind] * (scale[kind] * (arg1 * (0.5f - (f32)(index % n) / (n - 1))));
            lbl_8006E0B4(drift + spread, 0.1f, 0.0f);
        } else {
            lbl_8006E0B4(0.0f, 0.1f, 0.0f);
        }
    } else {
        lbl_8006D758();
    }
}


/* fzgx:end fn_1_85C58 */

/* fzgx:begin fn_1_85F70 */
void fn_1_85F70(void *car, f32 arg) {
    fn_1_23500();
}
/* fzgx:end fn_1_85F70 */

/* fzgx:begin fn_1_85F90 */
void fn_1_85F90(void *obj, f32 a, f32 b, f32 c, f32 d, int mode) {
    f32 *pos;
    int active;
    int result;
    f32 value;
    f32 *base;
    f32 dd;
    u8 *p;
    FzgxChild *child;

    child = *(FzgxChild **)((u8 *)obj + 0x49c);
    if (((0) == lbl_1_bss_3BE0) || ((0) == child)) {
        lbl_8006D7F4(0.0f, 1.0f, -0.1f);
        active = 1;
    } else {
        pos = &child->unk_148;
        dd = d;
        *pos = b;
        pos[1] = c;
        pos[2] = dd;
        base = &child->unk_148;
        if (mode < 0) {
            result = fn_1_20A5C(base, &value);
        } else {
            result = (int)fn_1_21644( base, &value, (void *)(mode));
        }
        child->unk_140 = result;
        child->unk_144 = value;
        if (lbl_1_bss_3BE0->unk_7D != 0 && ((0) == result) && value < 0.0f) {
            p = ((u8 *)fn_1_14F04()) + 0x400;
            fn_1_17920(0, 0.0f, 0);
            lbl_8006DBAC( (void *)((Vec3 *)(p)));
            lbl_8006E0A4(p + 0x70);
            lbl_8006E0B4(b, (*(s16 *)&lbl_1_bss_960 == 9 && !(*(u32 *)obj & (1 << 10))) ? 0.1f : 1.0f, d);
            active = 0;
        } else {
            fn_1_892FC((void *)obj, (void *)((int)(&b)), (void *)((int)(&d)));
            if (0 != lbl_1_bss_3BE0->unk_7D) {
                active = 1;
            } else {
                active = 0;
            }
        }
    }
    fn_1_23500(obj, a);
    if (child != 0 && active) {
        (child->unk_11c = (0));
        child->unk_118 = 0;
    }
}
/* fzgx:end fn_1_85F90 */

/* fzgx:begin fn_1_8616C */
// Passes the default handling value to the car update routine.

void fn_1_8616C(void) {
    fn_1_85934(0.0f);
}
/* fzgx:end fn_1_8616C */

/* fzgx:begin fn_1_86194 */
// fn_1_86194: main_rel .text:0x00086194 size 0x20

// Wrapper that calls fn_1_85934.

void fn_1_86194(f32 arg) {
    fn_1_85934(arg);
}
/* fzgx:end fn_1_86194 */

/* fzgx:begin fn_1_861B4 */
// Processes active car entries before finalizing the car table.

void fn_1_861B4(void) {
    u32 i;
    Obj_1_bss_6D838_Target *car;

    i = 0;
    car = lbl_1_bss_6D838;
    while (i < (s8)lbl_1_bss_6D84A) {
        if (car->unk_0 & 0x04000000) {
            fn_1_C489C(car);
        }
        i++;
        car++;
    }
    fn_1_C40A0(lbl_1_bss_6D838);
}
/* fzgx:end fn_1_861B4 */

/* fzgx:begin fn_1_8623C */
// fn_1_8623C: returns a constant.

int fn_1_8623C(void) {
    return 0;
}
/* fzgx:end fn_1_8623C */

/* fzgx:begin fn_1_86244 */
u32 fn_1_86244(void) {
    return *(u32 *)&lbl_1_bss_6D838;
}
/* fzgx:end fn_1_86244 */

/* fzgx:begin fn_1_86254 */
void *fn_1_86254(int index) {
    if (lbl_1_bss_6D838 != 0) {
        return (u8 *)lbl_1_bss_6D838 + index * 0x620;
    }
    return 0;
}
/* fzgx:end fn_1_86254 */

/* fzgx:begin fn_1_8627C */
u32 fn_1_8627C(s32 index) {
    CarEntry_8627C *cars;

    cars = (CarEntry_8627C *)lbl_1_bss_6D838;
    if (cars != 0) {
        return cars[index].value;
    }
    return 0;
}
/* fzgx:end fn_1_8627C */

/* fzgx:begin fn_1_862A8 */
u32 fn_1_862A8(u32 arg0, struct fn_1_862A8_Arg1 *arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = ((*((u32 *)&lbl_1_bss_6D838)) + (arg0 * 1568));
    v1 = *(u32 *)(v0 + 444);
    v2 = *(u32 *)(v0 + 448);
    arg1->unk_0 = v1;
    arg1->unk_4 = v2;
    arg1->unk_8 = *(u32 *)(v0 + 452);
    return v1;
}
/* fzgx:end fn_1_862A8 */

/* fzgx:begin fn_1_862D4 */

/* WARNING: compiler-diff device, not original code */
__declspec(section ".rodata") static RawVec3 zero_7C = {0.0f, 0.0f, 0.0f};

typedef struct Car862D4 {
    u8 pad_0[0x7C];
    RawVec3 pos; /* 0x7C */
    u8 pad_88[0x620 - 0x88];
} Car862D4;

#define lbl_1_bss_6D838 (*(Car862D4 **)&lbl_1_bss_6D838)
void fn_1_862D4(int index, RawVec3 *out) {
    if ((int)fn_80007CDC((f32 *)&lbl_1_bss_6D838[index].pos) != 0) {
        *out = zero_7C;
    } else {
        *out = lbl_1_bss_6D838[index].pos;
    }
}
#undef lbl_1_bss_6D838
/* fzgx:end fn_1_862D4 */

/* fzgx:begin fn_1_8636C */
// Dispatches the argument based on the indexed car entry's state.

void fn_1_8636C(int index, void *arg) {
    int offset = index * 0x620;

    if ((int)fn_80007D58( (f32 *)((u8 *)lbl_1_bss_6D838 + offset + 0xec)) != 0) {
        lbl_8006D784(arg);
    } else {
        lbl_8006DD14((u8 *)lbl_1_bss_6D838 + offset + 0xec, arg);
    }
}
/* fzgx:end fn_1_8636C */

/* fzgx:begin fn_1_863E4 */
// Dispatches the indexed car record to the appropriate handler.

void fn_1_863E4(int index, void *arg) {
    int offset = index * 0x620;

    if ((int)fn_80007D58( (f32 *)((u8 *)lbl_1_bss_6D838 + offset + 0x5e0)) != 0) {
        lbl_8006D784(arg);
    } else {
        lbl_8006DD14((u8 *)lbl_1_bss_6D838 + offset + 0x5e0, arg);
    }
}
/* fzgx:end fn_1_863E4 */

/* fzgx:begin fn_1_8645C */
void fn_1_8645C(int index, void *arg) {
    int offset = index * 0x620;
    f32 v;

    if ((int)fn_80007D58( (f32 *)((u8 *)lbl_1_bss_6D838 + offset + 0x14c)) != 0) {
        lbl_8006D784(arg);
        v = 0.0f;
        *(f32 *)((u8 *)arg + 0xc) = v;
        *(f32 *)((u8 *)arg + 0x1c) = v;
        *(f32 *)((u8 *)arg + 0x2c) = v;
    } else {
        lbl_8006DD14((u8 *)lbl_1_bss_6D838 + offset + 0x14c, arg);
    }
}
/* fzgx:end fn_1_8645C */

/* fzgx:begin fn_1_864E8 */
// Returns the indexed car record from the shared car table.

u32 fn_1_864E8(int index) {
    return ((u32 *)lbl_1_bss_6D838)[index * (0x620 / sizeof(u32))];
}
/* fzgx:end fn_1_864E8 */

/* fzgx:begin fn_1_864FC */
/* VIEWS */
#define lbl_1_bss_6D838 (*(Fn864FCEntry * *)&lbl_1_bss_6D838)
u32 fn_1_864FC(u32 index) {
    return lbl_1_bss_6D838[index].value;
}
#undef lbl_1_bss_6D838
/* fzgx:end fn_1_864FC */

/* fzgx:begin fn_1_86514 */
u32 fn_1_86514(int index) {
    return lbl_1_bss_6D838[index].unk_218;
}
/* fzgx:end fn_1_86514 */

/* fzgx:begin fn_1_8652C */
f32 fn_1_8652C(int index) {
    u32 offset;

    offset = index * 0x620;
    return lbl_1_bss_6D838[index].unk_17C;
}
/* fzgx:end fn_1_8652C */

/* fzgx:begin fn_1_86544 */
f32 fn_1_86544(s32 index) {
    Obj_1_bss_6D838_Target *array;

    array = lbl_1_bss_6D838;
    return array[index].unk_224;
}
/* fzgx:end fn_1_86544 */

/* fzgx:begin fn_1_8655C */
// Returns the requested car record's stored value.

f32 fn_1_8655C(int index) {
    return lbl_1_bss_6D838[index].unk_34;
}
/* fzgx:end fn_1_8655C */

/* fzgx:begin fn_1_86574 */
f32 fn_1_86574(int index) {
    return lbl_1_bss_6D838[index].unk_38;
}
/* fzgx:end fn_1_86574 */

/* fzgx:begin fn_1_8658C */
/* WARNING: compiler-diff device, not original code */
__declspec(section ".rodata") static RawVec3 zero_88 = {0.0f, 0.0f, 0.0f};

typedef struct Car8658C {
    u8 pad_0[0x88];
    RawVec3 unk_88; /* 0x88 */
    u8 pad_94[0x620 - 0x94];
} Car8658C;

#define lbl_1_bss_6D838 (*(Car8658C **)&lbl_1_bss_6D838)
void fn_1_8658C(int index, RawVec3 *out) {
    if ((int)fn_80007CDC((f32 *)&lbl_1_bss_6D838[index].unk_88) != 0) {
        *out = zero_88;
    } else {
        *out = lbl_1_bss_6D838[index].unk_88;
    }
}
#undef lbl_1_bss_6D838
/* fzgx:end fn_1_8658C */

/* fzgx:begin fn_1_86624 */
u8 fn_1_86624(void) {
    return lbl_1_bss_6D84A;
}
/* fzgx:end fn_1_86624 */

/* fzgx:begin fn_1_86634 */
u8 fn_1_86634(int index) {
    return lbl_1_bss_6D838[index].unk_475;
}
/* fzgx:end fn_1_86634 */

/* fzgx:begin fn_1_8664C */
u16 fn_1_8664C(int index) {
    if (lbl_1_bss_6D838 != 0) {
        return lbl_1_bss_6D838[index].unk_214;
    }
    return 0;
}
/* fzgx:end fn_1_8664C */

/* fzgx:begin fn_1_86678 */
u8 fn_1_86678(int index) {
    return lbl_1_bss_6D838[index].unk_474;
}
/* fzgx:end fn_1_86678 */

/* fzgx:begin fn_1_86690 */
s8 fn_1_86690(s8 index) {
    return lbl_1_bss_6D838[index].unk_6;
}
/* fzgx:end fn_1_86690 */

/* fzgx:begin fn_1_866B4 */
s32 fn_1_866B4(u32 arg0) {
    s16 i;

    for (i = 0; i < lbl_1_bss_6D84A; i++) {
        if ((s8)arg0 == ((struct fn_1_866B4_car *)lbl_1_bss_6D83C)[i].unk_32C->unk_474) {
            struct fn_1_866B4_car *cars = lbl_1_bss_6D83C;
            return (s8)cars[i].unk_32C->unk_4;
        }
    }
    for (i = 0; i < lbl_1_bss_6D84A; i++) {
        if (lbl_1_bss_6D868[(s8)arg0] == ((struct fn_1_866B4_car *)lbl_1_bss_6D83C)[i].unk_32C->unk_4) {
            struct fn_1_866B4_car *cars = lbl_1_bss_6D83C;
            return (s8)cars[i].unk_32C->unk_4;
        }
    }
    return -1;
}
/* fzgx:end fn_1_866B4 */

/* fzgx:begin fn_1_8677C */
u32 fn_1_8677C(u32 arg0) {
    u32 v0;
    u8 v1;

    v0 = (u32)lbl_1_bss_6D838 + (arg0 * 1568);
    v1 = 0;
    while (v1 < 4) {
        if ((*(u32 *)((u8 *)v0 + 580 + (v1 * 92)) & 0x4) != 0) {
            return 1;
        }
        v1++;
    }
    return 0;
}
/* fzgx:end fn_1_8677C */

/* fzgx:begin fn_1_867CC */
u32 fn_1_867CC(u32 arg0, struct fn_1_867CC_Arg1 *arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = ((u32)lbl_1_bss_6D838 + (arg0 * 1568));
    v1 = *(u32 *)(v0 + 1184);
    v2 = *(u32 *)(v0 + 1188);
    arg1->unk_0 = v1;
    arg1->unk_4 = v2;
    arg1->unk_8 = *(u32 *)(v0 + 1192);
    return v1;
}
/* fzgx:end fn_1_867CC */

/* fzgx:begin fn_1_867F8 */
// Return the indexed car's stored float value.

f32 fn_1_867F8(int index) {
    return lbl_1_bss_6D838[index].unk_184;
}
/* fzgx:end fn_1_867F8 */

/* fzgx:begin fn_1_86810 */
// Return the indexed car object's status byte.

u8 fn_1_86810(int index) {
    u8 *object = (u8 *)lbl_1_bss_6D838[index].unk_49C;
    return object[0x115];
}
/* fzgx:end fn_1_86810 */

/* fzgx:begin fn_1_8682C */
u8 fn_1_8682C(int index) {
    return lbl_1_bss_6DA5C[index];
}
/* fzgx:end fn_1_8682C */

/* fzgx:begin fn_1_8683C */
// Return the indexed car object's stored halfword value.

s16 fn_1_8683C(int index) {
    return lbl_1_bss_6D838[index].unk_188;
}
/* fzgx:end fn_1_8683C */

/* fzgx:begin fn_1_86854 */
fn_1_86854_Entry *fn_1_86854(int id) {
    fn_1_86854_Entry *base = lbl_1_bss_6D83C;
    s8 count = lbl_1_bss_6D84A;
    s8 i;

    for (i = 0; i < count; i++) {
        fn_1_86854_Entry *entry = &base[i];

        if (entry == 0) {
            break;
        }
        if ((s8)id == (s8)entry->id) {
            return &base[i];
        }
    }
    return 0;
}
/* fzgx:end fn_1_86854 */

/* fzgx:begin fn_1_868C0 */
void *fn_1_868C0(s8 index) {
    if (index < lbl_1_bss_6D84A) {
        if (lbl_1_bss_6D83C != 0) {
            return ((u8 *)lbl_1_bss_6D83C) + index * 0x440;
        }
    }
    return 0;
}
/* fzgx:end fn_1_868C0 */

/* fzgx:begin fn_1_86900 */
void *fn_1_86900(s32 arg0) {

    s8 i;
    u8 *base = lbl_1_bss_6D83C;
    s16 count = lbl_1_bss_6D84A;
    {
        s16 j;
        for (j = 0; j < count; j++) {
            if ((s8)arg0 == (s8)*((u8 *)*(u32 *)(base + 0x32C + j * 0x440) + 0x474)) {
                return base + j * 0x440;
            }
        }
        i = j;
    }
    {
        s32 id;
        s16 k;
        id = ((s8)arg0);
        for (k = 0; k < count; k++) {
            if (lbl_1_bss_6D868[id] == *(s16 *)((u8 *)*(u32 *)((((base) + (k * 0x440)) + (0x32C))) + 4)) {
                return base + k * 0x440;
            }
        }
        i = k;
    }
    return 0;
}
/* fzgx:end fn_1_86900 */

/* fzgx:begin fn_1_869B0 */
void fn_1_869B0(int index, u32 *out) {
    Data_1_869B0 *data = (Data_1_869B0 *)lbl_1_bss_6D838[index].unk_49C;
    *(RawVec3 *)out = *(RawVec3 *)&data->value_50;
}
/* fzgx:end fn_1_869B0 */

/* fzgx:begin fn_1_869E0 */
void fn_1_869E0(int index, u32 *out) {
    CarData *data = (CarData *)lbl_1_bss_6D838[index].unk_49C;
    *(Copy12 *)out = *(Copy12 *)&data->value_5c;
}
/* fzgx:end fn_1_869E0 */

/* fzgx:begin fn_1_86A10 */
u8 fn_1_86A10(u32 arg0) {
    return ((u8 *)lbl_1_bss_6D838)[arg0 * 0x620 + 0x482];
}
/* fzgx:end fn_1_86A10 */

/* fzgx:begin fn_1_86A2C */
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))


f32 fn_1_86A2C(fn_1_86A2C_Car *car) {
    f32 result;
    s8 slot;
    u8 *entry;
    u8 *obj;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 dist;
    f32 z;
    f32 y;
    f32 x;
    u16 timer;
    s32 camera;
    f32 cam[3];
    f32 target[3];
    f32 ofs[3];

    result = 1.0f;
    camera = car->idx;
    if ((s32)fn_1_6EC0(camera) != 0) {
        if (car->flags & 0x10000) {
            result = 1.0f;
        } else if ((u32)fn_1_5910() == (s8)car->idx) {
            if (camera_get_entry_field_0xa4(car->idx) != 0 && camera_get_entry_field_0xa4(car->idx) != 1) {
                result = 1.0f;
            } else {
                slot = car->unk_4;
                if (slot < (s8)lbl_1_bss_6D84A && lbl_1_bss_6D83C != NULL) {
                    entry = ((u8 *)lbl_1_bss_6D83C) + slot * 0x440;
                } else {
                    entry = NULL;
                }
                obj = *(u8 **)(entry + 0x394);
                if (obj == NULL) {
                    fn_1_681C(car->idx, (void *)((u32 *)target));
                    dx = target[0] - car->pos[0];
                    dy = target[1];
                    dy -= car->pos[1];
                    dz = target[2];
                    dz = dz - car->pos[2];
                    dist = dx * dx;
                    dist += dy * dy;
                    dist += dz * dz;
                    result = CLAMP(CLAMP(dist - 2.3f, 0.0f, 17.0f) / 14.7f, 0.0f, 1.0f);
                } else {
                    f32 dz2;
                    f32 dy2;
                    f32 dist2;
                    ofs[0] = 0.0f;
                    ofs[1] = 0.3f + *(f32 *)(obj + 0x118);
                    ofs[2] = *(f32 *)(obj + 0x11C);
                    lbl_8006DC6C(car->mtx);
                    x = car->pos[0];
                    y = car->pos[1];
                    z = car->pos[2];
                    /* translation column of the locked-cache current matrix */
                    *(f32 *)(0xE0000000 + 0x0C) = x;
                    *(f32 *)(0xE0000000 + 0x1C) = y;
                    *(f32 *)(0xE0000000 + 0x2C) = z;
                    lbl_8006E1B0((void *)((Vec3 *)ofs), (void *)((Vec3 *)ofs));
                    fn_1_681C(car->idx, (void *)((u32 *)cam));
                    x = cam[0] - ofs[0];
                    dy2 = cam[1];
                    dy2 = dy2 - ofs[1];
                    dz2 = cam[2];
                    dz2 = dz2 - ofs[2];
                    dist2 = x * x;
                    dist2 += dy2 * dy2;
                    dist2 += dz2 * dz2;
                    result = CLAMP(CLAMP(dist2 - 2.3f, 0.0f, 10.0f) / 7.7f, 0.0f, 1.0f);
                }
            }
        }
    }
    timer = car->timer;
    if (timer != 0 && timer < 160.0f) {
        if (timer > 160.0f) {
            result = (timer - 160.0f) / 100.0f;
        } else if (timer <= 20) {
            result = 1.0f - timer / 30.0f;
        } else {
            result = 0.0f;
        }
    }
    return result;
}


#undef CLAMP
/* fzgx:end fn_1_86A2C */

/* fzgx:begin fn_1_86E08 */
void fn_1_86E08(fn_1_86E08_Car *car) {

    fn_1_86E08_Machine *machine;
    s32 *timer;
    s32 idx;
    s32 period;
    f32 t;
    f32 v;
    f64 d;
    u32 frame;

    if (car != NULL && !(car->flags & 0x20000000)) {
        idx = (s8)car->id;
        if (idx < lbl_1_bss_6D84A && lbl_1_bss_6D83C != NULL) {
            machine = &((fn_1_86E08_Machine *)lbl_1_bss_6D83C)[idx];
        } else {
            machine = NULL;
        }
        if (!(machine->flags & 0x200000)) {
            if (car->speed < 25.0f) {
                period = 30;
                if (car->speed < 15.0f) {
                    period = 20;
                }
                t = (s32)(lbl_801A66A0 % period) / (f32)period;
                fn_1_56298(t < 0.1f ? 0.1f : (t > 0.3f ? 0.3f : t), 0.0f, 0.0f, 0.0f);
            }
            if (car->flags & 0x2800000) {
                timer = (s32 *)lbl_1_bss_6D8F4;
                timer[car->id] = 18;
            }
            timer = (s32 *)lbl_1_bss_6D8F4;
            if (timer[car->id] != 0) {
                d = car->unk_4AC < 0.2 ? 0.2 : (car->unk_4AC > 0.4f ? 0.4f : car->unk_4AC);
                v = d;
                frame = lbl_801A66A0;
                if (frame % 3 == 0) {
                    fn_1_56298(v, v, v, 0.0f);
                } else if (car->speed < 25.0f) {
                    t = (frame % 15) / 15.0f;
                    fn_1_56298(t < 0.1f ? 0.1f : (t > 0.3f ? 0.3f : t), 0.0f, 0.0f, 0.0f);
                } else {
                    fn_1_56298(0.1f, 0.1f, 0.1f, 0.0f);
                }
            }
        }
    }
}
/* fzgx:end fn_1_86E08 */

/* fzgx:begin fn_1_87074 */
void fn_1_87074(void) {
    u32 zero;
    u8 i;

    zero = 0;
    for (i = 0; i < 30; i += 6) {
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2)) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 4) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 8) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 12) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 16) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 20) = zero;
    }
}
/* fzgx:end fn_1_87074 */

/* fzgx:begin fn_1_870BC */
void fn_1_870BC(Car870BC *car, s8 a, s32 b, s16 c, u8 d, f32 x)
{
    s32 i;
    s8 signed_a = a;
    car->f3ba = signed_a;
    if (car->flags & 0x04000000) {
        fn_1_14E2DC(car->f3a0, signed_a, x);
        return;
    }
    i = d;
    if (car->f3b8 != i) {
        u32 v = car->tab[i % 4];
        if (v != 0) {
            Car870BC *q = (Car870BC *)((u8 *)car + signed_a * 12);
            u32 s;
            fn_800713E0(q->slot[0].a, v);
            s = q->slot[0].a;
            {
                CarTexRemapTable remap = car_tex_remap;
                fn_800712E4((void *)s, lbl_1_bss_6D82C, remap.entries);
            }
        }
        car->f3b8 = d;
    }
    lbl_8006DAEC();
    fn_1_8E450((u32)car);
    if (c != 0) {
        lbl_1_data_1F5A0[car->f328]((Fn187750Object *)car);
    } else {
        fn_1_87610((void *)car, (void *)b);
    }
    fn_1_875B4((Fn1_87448_Obj *)car, (Fn1_87448_Arg1 *)b, a, x);
    lbl_8006DBE4();
    fn_1_87238((void *)car, a, x);
    fn_1_8E480();
    lbl_8006DB30();
}
/* fzgx:end fn_1_870BC */

/* fzgx:begin fn_1_87238 */
void fn_1_87238(struct fn_1_87238_Car *car, s8 index, f32 f1) {
    struct ModelItem *item;
    int i;
    int field_0x328;
    u32 flag;
    int is_one;
    struct Model *model;

    if (f1 == 0.0f) {
        return;
    }

    is_one = (f1 == 1.0f);
    model = *car->slots[index].model_ptr;
    if (model == NULL) {
        return;
    }

    field_0x328 = car->field_0x328;
    item = model->items;
    flag = car->flags & 0x00100000;

    for (i = 0; i < model->count; i++, item++) {
        if (!(item->flags & 0x00020000)) {
            continue;
        }

        if (field_0x328 == 0x26) {
            fn_1_56018(1);
            lbl_8006D784(&((struct TargetObj *)lbl_801A6D00)->field_0x60);
            ((struct TargetObj *)lbl_801A6D00)->field_0x6c = (u8)lbl_801A66A0 / 255.0f;
            fn_1_560F0(0, (void *)(&((struct TargetObj *)lbl_801A6D00)->field_0x60));
        } else if (flag) {
            fn_1_56018(1);
            lbl_8006D784(&((struct TargetObj *)lbl_801A6D00)->field_0x60);
            ((struct TargetObj *)lbl_801A6D00)->field_0x7c = lbl_8006D188(((int)((lbl_801A66A0 % 180) * 182.04445f) + 0x4000));
            fn_1_560F0(0, (void *)(&((struct TargetObj *)lbl_801A6D00)->field_0x60));
        }
    }

    fn_80072558();
    if (is_one) {
        fn_1_556B8( (void *)((struct Model *)(model)));
    } else {
        fn_1_55FF0(f1);
        fn_1_55210( (void *)((struct Model *)(model)));
    }
    fn_1_56018(0);
}
/* fzgx:end fn_1_87238 */

/* fzgx:begin fn_1_87448 */
void fn_1_87448(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, int flag, f32 f) {
    s32 k;
    u8 **row;
    s32 n;
    Fn1_87448_Tab *tab;
    s32 below;
    void *p;
    s16 lim;

    lim = 0;
    tab = (Fn1_87448_Tab *)self->unk_334[arg2].unk_04;
    if (f <= 0.0f) {
        return;
    }
    below = f < 1.0f;
    if (arg1 != 0) {
        lim = arg1->unk_02;
    }
    k = 1;
    n = 0;
    for (; k < tab->unk_00; k++) {
        if (n > lim - 1) {
            break;
        }
        if (((u8 *)strstr((void *)((*((k) + tab->unk_08)).unk_04), (void *)((u8 *)"pos_"))) != tab->unk_08[k].unk_04) {
            row = self->unk_334[arg2].unk_00;
            p = row[k];
            if (p == 0) {
                n += 1;
                continue;
            }
            if (below != 0) {
                fn_1_55FF0(f);
            }
            lbl_8006DBE4();
            lbl_8006DFC4((void *)(self->unk_330 + n * 0x30));
            fn_80072558();
            if (flag != 0) {
                fn_1_556B8(p);
            } else {
                fn_1_55628((Sig_fn_1_55628_Fn1_55628Object *)p);
            }
            n += 1;
        }
    }
}
/* fzgx:end fn_1_87448 */

/* fzgx:begin fn_1_875B4 */
/* Unknown retail objects: .data 208B0..2090B, debug format strings no retail function reads (after fn_1_87448's "pos_") */
static char lbl_1_data_208B0[16] = "SECT:%4d [%d]\n";
static char lbl_1_data_208C0[16] = "C   :%4d %f\n";
static char lbl_1_data_208D0[16] = "A   :%4d %f\n";
static char lbl_1_data_208E0[16] = "R   :%4d %f\n";
static char lbl_1_data_208F0[16] = "%d   :%4d %f\n";
static char lbl_1_data_20900[12] = "TRIP:%f\n";

/* Unknown retail object: .rodata 3C28, no retail function reads it (between fn_1_86E08's and fn_1_87750's literals) */
const f32 lbl_1_rodata_3C28 = 0.25f;

void fn_1_875B4(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, f32 value) {
    fn_1_87448(self, arg1, arg2, value >= 1.0f, value);
}
/* fzgx:end fn_1_875B4 */

/* fzgx:begin fn_1_875EC */
void fn_1_875EC(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, f32 value) {
    fn_1_87448(self, arg1, arg2, 1, value);
}
/* fzgx:end fn_1_875EC */

/* fzgx:begin fn_1_87610 */
void fn_1_87610(Fn187610Object *object, Fn187610Data *data) {
    u8 value[12];
    int i;
    s16 result;

    if (data != 0) {
        for (i = 0; i < data->field_002; i++) {
            switch (object->field_328) {
            case 40:
                switch (object->field_3BA) {
                case 0:
                    switch (i) {
                    case 0:
                        result = 1;
                        break;
                    case 1:
                        result = 2;
                        break;
                    case 2:
                        result = 0;
                        break;
                    default:
                        result = 0;
                        break;
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    switch (i) {
                    case 0:
                        result = 0;
                        break;
                    case 1:
                        result = 1;
                        break;
                    case 2:
                        result = 2;
                        break;
                    default:
                        result = 0;
                        break;
                    }
                    break;
                }
                break;
            default:
                result = i;
                break;
            }

            fn_80008BA8(value, &data->field_208[i * 20], 12);
            lbl_8006D7DC((void *)value);
            lbl_8006DB74((void *)((u8 *)object->field_330 + result * 0x30));
        }
    }
}
/* fzgx:end fn_1_87610 */

/* fzgx:begin fn_1_87750 */
void fn_1_87750(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87750 */

/* fzgx:begin fn_1_877E8 */
void fn_1_877E8(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_877E8 */

/* fzgx:begin fn_1_87880 */
void fn_1_87880(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87880 */

/* fzgx:begin fn_1_87918 */
void fn_1_87918(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87918 */

/* fzgx:begin fn_1_879B0 */
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_879B0(Fn187750Object *object) {
    u8 value1[12];
    u8 value2[12];

    fn_80008BA8(value1, (u8 *)object + 0x208, 12);
    lbl_8006D7DC((void *)value1);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_y(182.04445f * CLAMP(-30.0f * object->field_32C->value_A4 / 256.0f, -30.0f, 30.0f));
    }

    lbl_8006DB74((void *)object->field_330);

    if (object != 0 && object->field_3BA == 0 && object->field_002 - 1 >= 1) {
        fn_80008BA8(value2, (u8 *)object + 0x21c, 12);
        lbl_8006D7DC((void *)value2);
        if (object->field_32C != 0) {
            mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
        }
        lbl_8006DB74((void *)((u8 *)object->field_330 + 0x30));
    }
}
/* fzgx:end fn_1_879B0 */

/* fzgx:begin fn_1_87AD8 */
#undef CLAMP

void fn_1_87AD8(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87AD8 */

/* fzgx:begin fn_1_87B70 */
void fn_1_87B70(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87B70 */

/* fzgx:begin fn_1_87C08 */
void fn_1_87C08(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87C08 */

/* fzgx:begin fn_1_87CA0 */
void fn_1_87CA0(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87CA0 */

/* fzgx:begin fn_1_87D38 */
void fn_1_87D38(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87D38 */

/* fzgx:begin fn_1_87DD0 */
void fn_1_87DD0(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87DD0 */

/* fzgx:begin fn_1_87E68 */
void fn_1_87E68(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87E68 */

/* fzgx:begin fn_1_87F00 */
void fn_1_87F00(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87F00 */

/* fzgx:begin fn_1_87F98 */
void fn_1_87F98(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_87F98 */

/* fzgx:begin fn_1_88030 */
void fn_1_88030(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88030 */

/* fzgx:begin fn_1_880C8 */
void fn_1_880C8(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_880C8 */

/* fzgx:begin fn_1_88160 */
void fn_1_88160(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88160 */

/* fzgx:begin fn_1_881F8 */
void fn_1_881F8(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_881F8 */

/* fzgx:begin fn_1_88290 */
void fn_1_88290(Fn187750Object *object) {
    s8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88290 */

/* fzgx:begin fn_1_88328 */
void fn_1_88328(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88328 */

/* fzgx:begin fn_1_883C0 */
void fn_1_883C0(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_883C0 */

/* fzgx:begin fn_1_88458 */
void fn_1_88458(Fn187750Object *object) {
    u8 value_1[12];
    u8 value_2[12];

    if (object != 0 && object->field_3BA == 0 && object->field_002 - 1 >= 0) {
        fn_80008BA8(value_1, object->field_208, 12);
        lbl_8006D7DC((void *)value_1);

        if (object->field_32C != 0) {
            mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
        }

        lbl_8006DB74((void *)object->field_330);
    }

    if (object != 0 && object->field_3BA == 0 && object->field_002 - 1 >= 1) {
        fn_80008BA8(value_2, &object->field_208[0x14], 12);
        lbl_8006D7DC((void *)value_2);

        if (object->field_32C != 0) {
            mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
        }

        lbl_8006DB74((void *)((u8 *)object->field_330 + 0x30));
    }
}
/* fzgx:end fn_1_88458 */

/* fzgx:begin fn_1_8856C */
void fn_1_8856C(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_8856C */

/* fzgx:begin fn_1_88604 */
void fn_1_88604(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88604 */

/* fzgx:begin fn_1_8869C */
void fn_1_8869C(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_8869C */

/* fzgx:begin fn_1_88734 */
void fn_1_88734(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88734 */

/* fzgx:begin fn_1_887CC */
void fn_1_887CC(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_887CC */

/* fzgx:begin fn_1_88864 */
void fn_1_88864(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88864 */

/* fzgx:begin fn_1_888FC */
void fn_1_888FC(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_888FC */

/* fzgx:begin fn_1_88994 */
void fn_1_88994(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88994 */

/* fzgx:begin fn_1_88A2C */
void fn_1_88A2C(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88A2C */

/* fzgx:begin fn_1_88AC4 */
void fn_1_88AC4(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88AC4 */

/* fzgx:begin fn_1_88B5C */
void fn_1_88B5C(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88B5C */

/* fzgx:begin fn_1_88BF4 */
void fn_1_88BF4(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88BF4 */

/* fzgx:begin fn_1_88C8C */
void fn_1_88C8C(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88C8C */

/* fzgx:begin fn_1_88D24 */
void fn_1_88D24(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88D24 */

/* fzgx:begin fn_1_88DBC */
void fn_1_88DBC(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88DBC */

/* fzgx:begin fn_1_88E54 */
void fn_1_88E54(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88E54 */

/* fzgx:begin fn_1_88EEC */
void fn_1_88EEC(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88EEC */

/* fzgx:begin fn_1_88F84 */
void fn_1_88F84(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC((void *)value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((8192.0f * -object->field_32C->value_1FC));
    }

    lbl_8006DB74((void *)object->field_330);
}
/* fzgx:end fn_1_88F84 */

/* fzgx:begin fn_1_8901C */
/* degrees to binary angle units (65536 / 360) */

#define CLAMP(x, lo, hi) (((x) < (lo)) ? (lo) : (((x) > (hi)) ? (hi) : (x)))

#define DEG_TO_S16(deg) (182.04445f * (s16)(deg))

void fn_1_8901C(Fn187750Object *car) {
    s16 a;
    s16 b;
    s16 c;
    f32 angle;
    Vec3 v;

    angle = 0.0f;
    if (car->field_32C != NULL && (car->field_32C->flags & 0x60)) {
        Fn187750Inner *d = car->field_32C;
        f32 r;
        f32 scale;

        scale = (d->flags & 0x600000) ? 44.0f : 89.0f;
        r = CLAMP((180.0f / scale) * d->unk_18A, 0.0f, 180.0f);
        angle = lbl_8006D188(DEG_TO_S16(r));
    }
    switch (car->field_3BA) {
    case 0:
        a = 1;
        b = 2;
        c = 0;
        break;
    case 1:
    case 2:
    case 3:
        a = 0;
        b = 1;
        c = 2;
        break;
    }
    fn_80008BA8((void *)&v, (void *)car->field_208, 12);
    lbl_8006D7DC((void *)&v);
    mathutil_mtxA_rotate_y(DEG_TO_S16(360.0f - 60.0f * angle));
    lbl_8006DB74((u8 *)car->field_330 + a * 0x30);
    fn_80008BA8((void *)&v, (void *)&car->field_208[0x14], 12);
    lbl_8006D7DC((void *)&v);
    mathutil_mtxA_rotate_y(DEG_TO_S16(60.0f * angle));
    lbl_8006DB74((u8 *)car->field_330 + b * 0x30);
    if (car->field_32C != NULL && car->field_3BA == 0 && car->field_002 - 1 >= 2) {
        fn_80008BA8((void *)&v, (void *)&car->field_208[0x28], 12);
        lbl_8006D7DC((void *)&v);
        mathutil_mtxA_rotate_z((8192.0f * -car->field_32C->value_1FC));
        lbl_8006DB74((u8 *)car->field_330 + c * 0x30);
    }
}
#undef CLAMP
#undef DEG_TO_S16
/* fzgx:end fn_1_8901C */

/* fzgx:begin fn_1_892CC */
/* Original assembly (CodeWarrior asm function): copies three words. a and b are scratch
 * registers that every caller passes as 0 (retail fn_1_8A1B4 loads r5/r6 = 0 before each call). */
asm void fn_1_892CC(register V3 *dst, register V3 *src, register u32 a, register u32 b) {
    nofralloc
    lwz a, 0(src)
    lwz b, 4(src)
    stw a, 0(dst)
    lwz a, 8(src)
    stw b, 4(dst)
    stw a, 8(dst)
    blr
}
/* fzgx:end fn_1_892CC */

/* fzgx:begin fn_1_892E8 */
/* Original assembly (CodeWarrior asm function): clears three words. val is a scratch register
 * that every caller passes as 0; the zero is made with subf, an idiom compiled code in this game
 * never emits (it appears only here; SMB1's asm mathutil zeroes by self-subtraction too). */
asm void fn_1_892E8(register u32 *p, register u32 val) {
    nofralloc
    subf val, val, val
    stw val, 0(p)
    stw val, 4(p)
    stw val, 8(p)
    blr
}
/* fzgx:end fn_1_892E8 */

/* fzgx:begin fn_1_892FC */
/* Unknown retail function: the retail link removed it and no surviving code holds a copy of it.
   Its literals are .rodata 3C34..3C38 (200.0f, 40000.0f), created before fn_1_892FC's local initializer table (.rodata 3C3C).
   The retail body is not known: this placeholder only recreates the literals 3C34..3C38 in retail order.
   WARNING: compiler-diff device, not original code (the body is a placeholder that only rebuilds the literals) */
/* WARNING: compiler-diff device, not original code */
static f32 car_literal_order_3C34(f32 x)
{
    f32 y;

    y = 40000.0f * x;
    return y * 200.0f;
}

/* one 0x50-byte segment of a checkpoint (course data) */

/* one 0xC-byte checkpoint entry of the course table */

/* one hover corner (0x5C bytes) */

/* exponent all ones (inf or NaN); the negated != keeps a value-context result in its own register (retail r20) */

static inline s32 fn_1_892FC_nonfinite(f32 x) {
    return !((*(s32 *)&x & 0x7F800000) != 0x7F800000);
}

/* translation column of the current matrix in the locked cache */

static inline void fn_1_892FC_set_translate(Vec3 *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

/* retail reads the matrix base through addi; lwz for the up vector: opt_dead_assignments off */

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

void fn_1_892FC(Car892FC *car, f32 *out_c, f32 *out_2c) {
    u32 k;
    u32 mask;
    Prog892FC *p;
    Frame892FC *frame;
    Seg892FC *sa;
    Seg892FC *sb;
    Seg892FC *s0;
    Vec3 *pv;
    s32 corner;
    Corner892FC *c;
    u32 j;
    s32 count;
    s32 cp;
    s32 n;
    s32 next;
    s32 hit;
    s32 a;
    s32 cp0;
    s32 cp1;
    u8 *q;
    u32 bits;
    s32 bad;
    f32 *m;
    Vec3 *pos;
    f32 py;
    f32 px;
    f32 pz;
    f32 n1x;
    f32 n1y;
    f32 n1z;
    f32 n2x;
    f32 n2y;
    f32 n2z;
    u32 tb;
    s32 i;
    f32 dist;
    f32 x;
    f32 len;
    f32 da;
    f32 db;
    f32 t;
    Vec3 up;
    Vec3 out60;
    Vec3 nrm;
    Vec3 e2;
    Vec3 w;
    Vec3 u;
    f32 frac;
    f32 tmp;
    f32 out1c;
    s32 branch;

    p = car->unk_49C;
    if (lbl_1_bss_3BE0 == NULL || p == NULL || p->unk_140 < 0) {
        lbl_8006D7F4(0.0f, 1.0f, -0.1f);
        return;
    }
    count = lbl_1_bss_3BE0->unk_8;
    cp = p->unk_140;
    frac = p->unk_144;
    sa = *(Seg892FC **)(lbl_1_bss_3BE0->unk_C + 4 + cp * 0xC);
    dist = sa->unk_40 + (f32)(frac * (sa->unk_44 - sa->unk_40));
    if (p->unk_118 > p->unk_154 || p->unk_11C > p->unk_158) {
        dist = 5.0f;
        cp = fn_1_214C4(&frac, cp, dist);
    } else {
        p->unk_118 = p->unk_154;
        p->unk_11C = p->unk_158;
    }

    if (lbl_1_bss_3BE0->unk_7D != 0) {
        if (5.0f > dist) {
            dist = 5.0f;
            cp = fn_1_214C4(&frac, cp, dist);
        } else if (5.0f > *(f32 *)lbl_1_bss_3BE0->unk_90 - dist) {
            dist = *(f32 *)lbl_1_bss_3BE0->unk_90 - 5.0f;
            cp = fn_1_214C4(&frac, cp, dist);
        }
    } else if (5.0f > dist || 5.0f > *(f32 *)lbl_1_bss_3BE0->unk_90 - dist) {
        if (p->unk_148.z < 0.0f) {
            dist = 5.0f;
            cp = fn_1_214C4(&frac, cp, dist);
        } else {
            dist = *(f32 *)lbl_1_bss_3BE0->unk_90 - 5.0f;
            cp = fn_1_214C4(&frac, cp, dist);
        }
    }

    n = fn_1_214C4(&tmp, cp, 20.0f + dist);
    if (n != cp && fn_1_17FCC(n, cp, count) == 0) {
        dist -= 20.0f;
        cp = fn_1_214C4(&frac, cp, dist);
    }
    n = fn_1_214C4(&tmp, cp, dist - 20.0f);
    if (n != cp && fn_1_17FCC(n, cp, count) == 0) {
        dist = 20.0f + dist;
        cp = fn_1_214C4(&frac, cp, dist);
    }
    if (fn_1_7B054() == 0x10 || fn_1_7B054() == 0x1C) {
        n = fn_1_214C4(&tmp, cp, 40.0f + dist);
        if (n != cp && fn_1_181CC(n, cp, count) == 0) {
            dist -= 40.0f;
            cp = fn_1_214C4(&frac, cp, dist);
        }
        n = fn_1_214C4(&tmp, cp, dist - 20.0f);
        if (n != cp && fn_1_181F0(n, cp, count) == 0) {
            dist = 20.0f + dist;
            cp = fn_1_214C4(&frac, cp, dist);
        }
    }
    n = fn_1_214C4(&tmp, cp, 100.0f + dist);
    if (n != cp && fn_1_17C6C(n, cp, count) == 0) {
        for (i = 0; i < count; i++) {
            a = (cp + i + count) % count;
            sa = ((Entry892FC *)lbl_1_bss_3BE0->unk_C)[a].unk_4;
            next = (a + 1) % count;
            if (next == 0) {
                break;
            }
            if (sa->unk_4D == 0 || (next == 0x8C && fn_1_7B054() == 3)) {
                frac = 0.0f;
                cp = next;
                sa = *(Seg892FC **)(lbl_1_bss_3BE0->unk_C + 4 + cp * 0xC);
                dist = sa->unk_40 + (f32)(frac * (sa->unk_44 - sa->unk_40));
                break;
            }
        }
    }
    n = fn_1_214C4(&tmp, cp, dist - 5.0f);
    if (n != cp && fn_1_17C6C(n, cp, count) == 0) {
        dist = 5.0f + dist;
        cp = fn_1_214C4(&frac, cp, dist);
    }

    if (fn_1_7B054() == 3 && (cp == 0x3F || cp == 0x3E)) {
        frac = 0.0f;
        cp = 0x40;
        sa = ((Entry892FC *)lbl_1_bss_3BE0->unk_C)[0x40].unk_4;
        dist = sa->unk_40 + (f32)(frac * (sa->unk_44 - sa->unk_40));
    }
    if (fn_1_7B054() == 0x23 && (cp == 0x90 || (cp == 0x91 && frac < 0.1f))) {
        frac = 0.1f;
        cp = 0x91;
        sa = ((Entry892FC *)lbl_1_bss_3BE0->unk_C)[0x91].unk_4;
        dist = sa->unk_40 + (f32)(frac * (sa->unk_44 - sa->unk_40));
    }
    if (fn_1_7B054() == 9) {
        f32 tbl[4][2] = {{16361.0f, 16361.0f}, {16661.0f, 16661.0f}, {16961.0f, 16961.0f}, {17261.0f, 17261.0f}};

        for (j = 0; j < 4; j++) {
            if (tbl[j][0] - 10.0f < dist && 10.0f + tbl[j][1] > dist) {
                cp = fn_1_214C4(&frac, cp, 10.0f + tbl[j][1]);
                sa = ((Entry892FC *)lbl_1_bss_3BE0->unk_C)[cp].unk_4;
                dist = sa->unk_40 + (f32)(frac * (sa->unk_44 - sa->unk_40));
            }
        }
    }
    if (fn_1_7B054() == 0xD) {
        f32 tbl[7][2] = {{6459.0f, 6496.0f}, {7259.0f, 7296.0f}, {8059.0f, 8096.0f}, {13407.0f, 13425.0f},
                         {13534.0f, 13552.0f}, {13661.0f, 13679.0f}, {14137.0f, 14152.0f}};

        for (k = 0; k < 7; k++) {
            if (tbl[k][0] - 10.0f < dist && 10.0f + tbl[k][1] > dist) {
                cp = fn_1_214C4(&frac, cp, 10.0f + tbl[k][1]);
                sa = ((Entry892FC *)lbl_1_bss_3BE0->unk_C)[cp].unk_4;
                dist = sa->unk_40 + (f32)(frac * (sa->unk_44 - sa->unk_40));
            }
        }
    }
    if (fn_1_7B054() == 0xF) {
        f32 tbl[2] = {16954.0f, 16970.0f};

        if (tbl[0] - 10.0f < dist && 10.0f + tbl[1] > dist) {
            cp = fn_1_214C4(&frac, cp, 10.0f + tbl[1]);
        }
    }

    frame = ((Frame892FC *)fn_1_14F04());
    fn_1_17920(cp, frac, 0);
    branch = fn_1_17A9C(&p->unk_148);
    if (fn_1_7B054() == 0x1B && branch == 2) {
        branch = 1;
    }
    lbl_8006DBAC(frame->unk_400[branch]);
    if (out_c != NULL) {
        ((f32 *)lbl_801A6D00)[3] = *out_c;
    }
    if (out_2c != NULL) {
        ((f32 *)lbl_801A6D00)[11] = *out_2c;
    }
    for (i = 0; i < frame->unk_1C; i++) {
        p->unk_120[i] = cp;
        p->unk_130[i] = frac;
    }

    {
        Vec3 v[4];

        lbl_8006E1D8(&up, 0.0f, 1000.0f, 0.0f);
        lbl_8006E1D8(&v[0], 0.0f, -1000.0f, 0.0f);
        mask = 0x880001;
        if (branch < 4) {
            mask |= 0x80000000 >> branch;
        }
        lbl_8006DAEC();
        hit = fn_1_15578(&v[0], &up, &out1c, &out60, mask, p->unk_120, frame->unk_1C, 0, 0, car);
        lbl_8006DBE4();
        if (hit == 0) {
            hit = fn_1_15578(&v[0], &up, &out1c, &out60, mask & 0x07FFFFFF, p->unk_120, frame->unk_1C, 0, 0, car);
        }
        lbl_8006DB30();

        if (hit != 0) {
            lbl_8006DC6C(frame->unk_400[frame->unk_10C]);
            fn_1_892FC_set_translate(&v[0]);
            p->unk_140 = frame->unk_110;
            p->unk_144 = frame->unk_114;
            {
                u8 tbl[5][4] = {{2, 1, 0, 3}, {2, 3, 1, 3}, {0, 2, 3, 2}, {3, 1, 0, 1}, {1, 0, 2, 0}};

                bits = 0;
                q = NULL;
                /* pointer, counter and corner in their own locals: retail r22, r25, r26 */
                for (corner = 0, pv = v, c = car->unk_244; corner < 4; corner++, pv++, c++) {
                    lbl_8006E1D8(pv, c->unk_8.x, c->unk_8.y - 100.0f, c->unk_8.z);
                    lbl_8006E1D8(&up, c->unk_8.x, 100.0f + c->unk_8.y, c->unk_8.z);
                    lbl_8006DAEC();
                    if (fn_1_15578(pv, &up, &out1c, &out60, 0x880001, p->unk_120, frame->unk_1C, 0, 0, car) != 0) {
                        bits |= 1 << corner;
                    }
                    lbl_8006DB30();
                }
                if (bits == 0xF) {
                    q = tbl[0];
                } else if (bits == 0xE) {
                    q = tbl[1];
                } else if (bits == 0xD) {
                    q = tbl[2];
                } else if (bits == 0xB) {
                    q = tbl[3];
                } else if (bits == 7) {
                    q = tbl[4];
                }
                if (q != NULL) {
                    psvec_sub(&v[q[0]], &v[q[1]], &nrm);
                    psvec_sub(&v[q[2]], &v[q[3]], &e2);
                    mathutil_vec_cross_prod(&nrm, &e2, &nrm);
                    len = lbl_8006D668(&nrm);
                    if (!fn_1_892FC_nonfinite(len)) {
                        u.x = ((f32 *)lbl_801A6D00)[2];
                        u.y = ((f32 *)lbl_801A6D00)[6];
                        u.z = ((f32 *)lbl_801A6D00)[10];
                        mathutil_vec_cross_prod(&nrm, &u, &w);
                        bad = fn_1_892FC_nonfinite(lbl_8006D668(&w));
                        mathutil_vec_cross_prod(&w, &nrm, &u);
                        if (!(bad | fn_1_892FC_nonfinite(lbl_8006D668(&u)))) {
                            m = (f32 *)lbl_801A6D00;
                            m[0] = w.x;
                            m[1] = nrm.x;
                            m[2] = u.x;
                            m[4] = w.y;
                            m[5] = nrm.y;
                            m[6] = u.y;
                            m[8] = w.z;
                            m[9] = nrm.z;
                            m[10] = u.z;
                        }
                    }
                }
            }
        } else {
            p->unk_140 = cp;
            p->unk_144 = frac;
        }
    }

    x = 0.0f;
    if (fn_1_7B054() == 10) {
        if (cp == 0x7F || cp == 0x80 || cp == 0x81) {
            x = -35.0f;
            cp0 = 0x7F;
            cp1 = 0x81;
        } else if (cp == 0x85 || cp == 0x86 || cp == 0x87) {
            x = -35.0f;
            cp0 = 0x85;
            cp1 = 0x87;
        } else if (cp == 0x8B || cp == 0x8C || cp == 0x8D) {
            x = -35.0f;
            cp0 = 0x8B;
            cp1 = 0x8D;
        } else if (cp == 0x82 || cp == 0x83 || cp == 0x84) {
            x = 35.0f;
            cp0 = 0x82;
            cp1 = 0x84;
        } else if (cp == 0x88 || cp == 0x89 || cp == 0x8A) {
            x = 35.0f;
            cp0 = 0x88;
            cp1 = 0x8A;
        }
        if (0.0f != x) {
            tb = lbl_1_bss_3BE0->unk_C + 4;
            s0 = *(Seg892FC **)(tb + cp0 * 0xC);
            sb = *(Seg892FC **)(tb + cp1 * 0xC);
            pos = &lbl_801A66CC->unk_D4;
            m = (f32 *)0xE0000000; /* fzgx-allow: A2 locked-cache current matrix address */
            psvec_set(pos, m[11], m[7], m[3]);
            px = lbl_801A66CC->unk_D4.x;
            py = lbl_801A66CC->unk_D4.y;
            pz = lbl_801A66CC->unk_D4.z;
            /* WARNING: compiler-diff device, not original code */
            n1x = *(volatile f32 *)&s0->unk_C.x;  /* real local, loaded first (retail) */
            n1y = s0->unk_C.y;
            n1z = s0->unk_C.z;
            /* WARNING: compiler-diff device, not original code */
            n2x = *(volatile f32 *)&sb->unk_28.x;  /* real local (retail f4) */
            /* WARNING: compiler-diff device, not original code */
            n2y = *(volatile f32 *)&sb->unk_28.y;  /* real local (retail f3) */
            n2z = sb->unk_28.z;
            da = px * n1x;
            db = px * n2x;
            da += py * n1y;
            db += py * n2y;
            da += pz * n1z;
            db += lbl_801A66CC->unk_D4.z * n2z;
            da = s0->unk_8 + da;
            db = sb->unk_24 + db;
            t = da / (da + db);
            if (t < 0.0f) {
                t = 0.0f;
            } else if (t > 1.0f) {
                t = 1.0f;
            }
            x = x - (f64)(x * __fabs((f32)(2.0f * t) - 1.0f));
        }
    }
    lbl_8006E0B4(x, (*(s16 *)&lbl_1_bss_960 == 9 && !(car->unk_0 & 0x400)) ? 0.1f : 1.0f, 0.0f);
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_892FC */

/* fzgx:begin fn_1_8A168 */
void fn_1_8A168(void *arg0) {
    fn_1_892FC((void *)arg0, (void *)0, (void *)0);
}
/* fzgx:end fn_1_8A168 */

/* fzgx:begin fn_1_8A190 */
void fn_1_8A190(void *arg0, void *arg1) {
    fn_1_8A1B4((void *)arg0, (s32)arg1, (void *)0);
}
/* fzgx:end fn_1_8A190 */

/* fzgx:begin fn_1_8A1B4 */
/* lap time: frames, sub-frame fraction, minutes/seconds/milliseconds */

/* one 0x50-byte segment of a checkpoint (course data) */

/* one 0xC-byte checkpoint entry of the course table */

static inline Entry8A1B4 *fn_1_8A1B4_table(void) {
    Entry8A1B4 *t;

    t = (Entry8A1B4 *)lbl_1_bss_3BE0->unk_C;
    return t;
}

/* exponent all ones (inf or NaN) */

static inline s32 fn_1_8A1B4_nonfinite(f32 x) {
    return (*(s32 *)&x & 0x7F800000) == 0x7F800000;
}

static inline f32 fn_1_8A1B4_dist2(Vec3 *a, Vec3 *b) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 t;

    dx = a->x;
    dx -= b->x;
    dy = a->y;
    dy -= b->y;
    dz = a->z;
    t = b->z;
    dz -= t;
    t = dx * dx;
    t += dy * dy;
    t += dz * dz;
    return t;
}

static inline s32 fn_1_8A1B4_changed(Prog8A1B4 *p) {
    s32 changed;

    changed = 1;
    if (p->unk_154 == p->unk_118 && p->unk_158 == p->unk_11C) {
        changed = 0;
    }
    return changed;
}

static inline void fn_1_8A1B4_set(Vec3 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

/* frames -> minutes, seconds, milliseconds */

static inline void fn_1_8A1B4_split(Time8A1B4 *t) {
    u32 frames;
    f32 frac;
    u32 min;
    u32 ms;

    frames = t->frames;
    if (frames >= 360000) {
        t->min = 99;
        t->sec = 59;
        t->ms = 999;
    } else {
        frac = t->frac;
        if (frac >= 1.0f) {
            frac -= 1.0f;
            frames++;
        }
        min = frames / 3600;
        if (min >= 100) {
            t->min = 99;
            t->sec = 59;
            t->ms = 999;
        } else {
            frames -= min * 3600;
            t->min = min;
            t->sec = frames / 60;
            frames -= frames / 60 * 60;
            frac = (frames + frac) / 60.0f;
            ms = frac * 1000.0f;
            if (ms > 999) {
                ms = 999;
            }
            t->ms = ms;
        }
    }
}

static inline void fn_1_8A1B4_add(Time8A1B4 *dst, Time8A1B4 *a, Time8A1B4 *b) {
    dst->frames = a->frames + b->frames;
    dst->frac = a->frac + b->frac;
    if (dst->frac >= 1.0f) {
        dst->frac -= 1.0f;
        dst->frames++;
    }
    dst->min = a->min + b->min;
    dst->sec = a->sec + b->sec;
    dst->ms = a->ms + b->ms;
    while (dst->ms >= 1000) {
        dst->ms -= 1000;
        dst->sec++;
    }
    while (dst->sec >= 60) {
        dst->sec -= 60;
        dst->min++;
    }
    if (dst->min >= 100) {
        dst->ms = 999;
        dst->sec = 59;
        dst->min = 99;
    }
}

/* the car is clear of every segment around checkpoint *cp */

static inline s32 fn_1_8A1B4_clear(Car8A1B4 *car, s32 *cp, s32 count) {
    s32 k;
    s32 j;
    Entry8A1B4 *e;
    Seg8A1B4 *s;
    Vec3 tmp;

    for (k = -1; k <= 1; k++) {
        e = &fn_1_8A1B4_table()[(count + (*cp - k)) % count];
        for (j = 0; j < e->unk_0; j++) {
            s = &e->unk_4[j];
            if (k == -1) {
                if (car->pos.y > s->unk_34.y - 200.0f) {
                    return 0;
                }
                {
                    f32 dx;
                    f32 dy;
                    f32 dz;

                    dx = car->pos.x;
                    dx -= s->unk_34.x;
                    dy = car->pos.y - s->unk_34.y;
                    dz = car->pos.z - s->unk_34.z;
                    if ((f32)(dx * dx) + dy * dy + dz * dz <= 40000.0f) {
                        return 0;
                    }
                }
            } else if (k == 1) {
                if (car->pos.y > s->unk_18.y - 200.0f) {
                    return 0;
                }
                {
                    f32 dx;
                    f32 dy;
                    f32 dz;

                    dx = car->pos.x;
                    dx -= s->unk_18.x;
                    dy = car->pos.y - s->unk_18.y;
                    dz = car->pos.z - s->unk_18.z;
                    if ((f32)(dx * dx) + dy * dy + dz * dz <= 40000.0f) {
                        return 0;
                    }
                }
            } else {
                if (car->pos.y > s->unk_34.y - 200.0f) {
                    return 0;
                }
                if (car->pos.y > s->unk_18.y - 200.0f) {
                    return 0;
                }
                if (200.0f >= fn_1_1FDB0(&car->pos, &s->unk_18, &s->unk_34, &tmp)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

void fn_1_8A1B4(Car8A1B4 *car, s32 reset, Racer8A1B4 *racer) {
    f32 w;
    Prog8A1B4 *p;
    Prog8A1B4 *q;
    s32 count;
    s32 keep;
    s8 dir;
    s32 first;
    s32 warp;
    s32 i;
    s32 idx;
    s32 r;
    s32 branch;
    s32 best;
    s32 changed;
    s32 below;
    s32 belowPrev;
    Entry8A1B4 *tbl;
    Entry8A1B4 *e;
    Seg8A1B4 *sb;
    Seg8A1B4 *sa;
    Frame892FC *frame;
    f32 *m;
    f32 a;
    f32 b;
    f32 diff;
    f32 bestDist;
    f32 prev;
    f32 cur;
    f32 za;
    f32 zb;
    f32 t;
    f32 fa;
    f32 fb;
    f32 dot;
    f32 da;
    f32 db;
    f32 frac;
    f32 frac2;
    Vec3 pt;
    Vec3 pt2;
    f32 bestDist2;

    p = car->unk_49C;
    dir = 0;
    if (p != NULL && lbl_1_bss_3BE0 != NULL && (count = lbl_1_bss_3BE0->unk_8) != 0) {
    if (p->unk_80 != 0) {
        p->unk_1F0 = car->pos;
    }
    if (reset != 0) {
        keep = 0;
        first = 1;
    } else if (car->flags58C & 8) {
        keep = car->flags & 2;
        first = car->unk_1C8 > 0.0f;
    } else {
        keep = 1;
        first = 0;
    }
    warp = 0;
    if (reset == 0 && !(car->flags & 0x10000) && p->unk_160[0].frames < 360000 && racer != NULL &&
        racer->unk_1474 != 0) {
        p->unk_160[0].frames++;
    }

    if (*p->unk_90 < 0) {
        p->unk_AC = p->unk_148;
        p->unk_B8[0] = p->unk_140;
        p->unk_C8[0] = p->unk_144;
        if (p->unk_B8[0] < 0) {
            p->unk_B8[0] = 0;
        }
        if (p->unk_80 != 0) {
            p->unk_AC = car->pos;
            if (fn_1_7B054() == 0x2A) {
                p->unk_B8[0] = ((s32)fn_1_20A5C((void *)&p->unk_AC, p->unk_C8));
            } else {
                p->unk_B8[0] = ((s32)fn_1_20994((void *)&p->unk_AC, (void *)p->unk_C8));
            }
        }
        p->unk_80 = 0;
        keep = 0;
        first = 1;
        reset = 1;
    } else {
        if (first != 0 && car->unk_1CC >= 0) {
            p->unk_D8[0] = car->unk_1CC;
            p->unk_E8[0] = car->unk_1D0;
            if (!(car->flags & 0x20000000) && p->unk_B8[0] < p->unk_D8[0]) {
                sa = *(Seg8A1B4 **)(lbl_1_bss_3BE0->unk_C + 4 + p->unk_B8[0] * 0xC);
                sb = *(Seg8A1B4 **)(lbl_1_bss_3BE0->unk_C + 4 + p->unk_D8[0] * 0xC);
                a = sa->unk_40 + (f32)(p->unk_C8[0] * (sa->unk_44 - sa->unk_40));
                b = sb->unk_40 + (f32)(p->unk_E8[0] * (sb->unk_44 - sb->unk_40));
                diff = b - a - lbl_8006D0B4(fn_1_8A1B4_dist2(&p->unk_AC, &car->pos));
                if (fn_1_7B054() == 3) {
                    if (diff > 1500.0f) {
                        warp = 1;
                    }
                } else if (diff > 1000.0f) {
                    warp = 1;
                }
            }
            p->unk_B8[0] = p->unk_D8[0];
        }
        p->unk_AC = car->pos;
        p->unk_B8[0] = ((s32)fn_1_21644((void *)&p->unk_AC, (void *)p->unk_C8, (void *)p->unk_B8[0]));
    }

    if (first != 0) {
        p->unk_90 = p->unk_B8;
        p->unk_94 = p->unk_C8;
        p->unk_D8[0] = -1;
    } else {
        if (fn_1_7B054() == 0x1D) {
            p->unk_D8[0] = fn_1_216C0(&car->pos, p->unk_E8, *p->unk_90);
            if (p->unk_D8[0] < 0) {
                p->unk_D8[0] = ((s32)fn_1_20A5C((void *)&car->pos, p->unk_E8));
            }
        } else {
            p->unk_D8[0] = ((s32)fn_1_20A5C((void *)&car->pos, p->unk_E8));
        }
        if (p->unk_D8[0] >= 0) {
            p->unk_90 = p->unk_D8;
            p->unk_94 = p->unk_E8;
        } else {
            p->unk_90 = p->unk_B8;
            p->unk_94 = p->unk_C8;
            p->unk_D8[0] = -1;
        }
    }

    p->unk_9C[0] = fn_1_216F0(&car->pos, *p->unk_90, 0);
    if ((idx = *p->unk_90) >= 0) {
        bestDist = 0.0f;
        tbl = fn_1_8A1B4_table();
        best = 0;
        for (i = 1; i < tbl[idx].unk_0; i++) {
            r = fn_1_210A8(&car->pos, &frac, *p->unk_90, i, &pt);
            if (r < 0) {
                p->unk_90[i] = *p->unk_90;
                p->unk_94[i] = *p->unk_94;
            } else {
                p->unk_90[i] = r;
                p->unk_94[i] = frac;
                {
                    f32 dz;
                    f32 dy;
                    f32 dx;
                    f32 d = 0.0f;

                    dx = car->pos.x;
                    dx -= pt.x;
                    dy = car->pos.y;
                    dy -= pt.y;
                    dz = car->pos.z;
                    dz -= pt.z;
                    d = dx * dx;
                    d += dy * dy;
                    d += dz * dz;
                    if (best <= 0 || bestDist >= d) {
                        best = i;
                        bestDist = d;
                    }
                }
            }
            p->unk_9C[i] = fn_1_216F0(&car->pos, p->unk_90[i], i);
        }
        p->unk_98 = tbl[idx].unk_0;
    } else {
        p->unk_98 = 0;
    }

    if ((idx = p->unk_B8[0]) >= 0) {
        bestDist2 = 0.0f;
        tbl = fn_1_8A1B4_table();
        best = 0;
        for (i = 1; i < tbl[idx].unk_0; i++) {
            r = fn_1_210A8(&car->pos, &frac2, p->unk_B8[0], i, &pt2);
            if (r < 0) {
                p->unk_B8[i] = p->unk_B8[0];
                p->unk_C8[i] = p->unk_C8[0];
            } else {
                p->unk_B8[i] = r;
                p->unk_C8[i] = frac2;
                {
                    f32 dz;
                    f32 dy;
                    f32 dx;
                    f32 d;

                    dx = car->pos.x;
                    dx -= pt2.x;
                    dy = car->pos.y;
                    dy -= pt2.y;
                    dz = car->pos.z;
                    dz -= pt2.z;
                    d = dx * dx;
                    d += dy * dy;
                    d += dz * dz;
                    if (best <= 0 || bestDist2 >= d) {
                        best = i;
                        bestDist2 = d;
                    }
                }
            }
        }
    } else {
        best = 0;
    }

    if ((p->unk_B8[0] < 0 || fn_1_8A1B4_clear(car, p->unk_B8, count)) &&
        (p->unk_D8[0] < 0 || fn_1_8A1B4_clear(car, p->unk_D8, count))) {
        car->flags |= 0x800;
    }

    frame = ((Frame892FC *)fn_1_14F04());
    if (p->unk_D8[0] < 0 || p->unk_D8[0] == p->unk_B8[0]) {
        f32 t = p->unk_94[best];
        fn_1_17920(p->unk_90[best], t, (void *)car->unk_498);
    } else {
        f32 t = p->unk_C8[0];
        fn_1_17920(p->unk_B8[0], t, (void *)car->unk_498);
    }
    branch = fn_1_17A9C(&car->pos);
    p->unk_88 = frame->unk_1C;
    p->unk_8C = branch;
    memcpy(p, frame->unk_400[branch], 0x80);

    if (!(car->flags & 0x20002)) {
        lbl_8006DAEC();
        lbl_8006DC6C(car->unk_EC);
        m = (f32 *)0xE0000000; /* fzgx-allow: A2 locked matrix */
        {
            f32 z;
            f32 y;
            f32 x;

            z = m[10];
            z *= -1.0f;
            y = m[6];
            y *= -1.0f;
            x = m[2];
            x *= -1.0f;
            fn_1_8A1B4_set(&lbl_801A66CC->unk_D4, x, y, z);
        }
        w = p->unk_50.x;
        dot = w * lbl_801A66CC->unk_D4.x;
        w = p->unk_50.y;
        dot += w * lbl_801A66CC->unk_D4.y;
        w = p->unk_50.z;
        dot += w * lbl_801A66CC->unk_D4.z;
        if (0.0f > dot) {
            p->unk_114++;
        } else {
            p->unk_114--;
        }
        lbl_8006DB30();
    } else {
        p->unk_114--;
    }
    p->unk_110 = 0;
    if (p->unk_114 >= 30) {
        if (p->unk_10C == 0) {
            p->unk_10C = 1;
            p->unk_110 = 1;
        }
        p->unk_114 = 30;
    } else if (p->unk_114 <= 0) {
        if (p->unk_10C != 0) {
            p->unk_10C = 0;
            p->unk_110 = 1;
        }
        p->unk_114 = 0;
    }

    if (!(car->flags & 0x08000000)) {
        prev = p->unk_100;
        p->unk_FC = *(f32 *)lbl_1_bss_3BE0->unk_90;
        if (p->unk_B8[0] < 0) {
            p->unk_100 = 0.0f;
            prev = 0.0f;
        } else {
            if (p->unk_B8[branch] < 0) {
                branch = 0;
            }
            e = &fn_1_8A1B4_table()[p->unk_B8[branch]];
            sa = &e->unk_4[branch];
            p->unk_100 = sa->unk_40 + (f32)(p->unk_C8[branch] * (sa->unk_44 - sa->unk_40));
        }
        cur = p->unk_100;
        changed = fn_1_8A1B4_changed(p);
        if (lbl_1_bss_3BE0->unk_7D != 0) {
            sa = fn_1_8A1B4_table()[0].unk_4;
            if (changed != 0 || (__fabs(cur) < 50.0 && __fabs(prev) < 50.0)) {
                za = car->pos.z;
                zb = p->unk_1F0.z;
                below = za < 0.0f;
                belowPrev = zb < 0.0f;
                if (below && !belowPrev) {
                    if (-1.0f < car->pos.y - sa->unk_18.y || -1.0f < p->unk_1F0.y - sa->unk_18.y ||
                        fn_1_7B054() == 0x21 || fn_1_7B054() == 0x29) {
                        dir = 1;
                    }
                } else if (!below && belowPrev) {
                    dir = -1;
                }
            }
            if (dir == 0) {
                e = fn_1_8A1B4_table();
                sb = e[count - 1].unk_4;
                if (changed != 0 || (__fabs(p->unk_FC - cur) < 50.0 && __fabs(p->unk_FC - prev) < 50.0)) {
                    da = car->pos.x * sb->unk_28.x;
                    w = p->unk_1F0.x;
                    db = w * sb->unk_28.x;
                    da += car->pos.y * sb->unk_28.y;
                    db += p->unk_1F0.y * sb->unk_28.y;
                    w = car->pos.z;
                    da += w * sb->unk_28.z;
                    w = p->unk_1F0.z;
                    db += w * sb->unk_28.z;
                    w = sb->unk_24;
                    za = w + da;
                    zb = w + db;
                    below = za < 0.0f;
                    belowPrev = zb < 0.0f;
                    if (below && !belowPrev) {
                        if (-1.0f < car->pos.y - sb->unk_34.y || -1.0f < p->unk_1F0.y - sb->unk_34.y ||
                            fn_1_7B054() == 0x21 || fn_1_7B054() == 0x29) {
                            dir = 1;
                        }
                    } else if (!below && belowPrev) {
                        dir = -1;
                    }
                }
            }
        } else {
            sa = fn_1_8A1B4_table()[0].unk_4;
            if (changed != 0 || ((cur < 50.0f || p->unk_FC - cur < 50.0f) &&
                                 (prev < 50.0f || p->unk_FC - prev < 50.0f))) {
                za = car->pos.z;
                zb = p->unk_1F0.z;
                below = za < 0.0f;
                belowPrev = zb < 0.0f;
                if (below && !belowPrev) {
                    if (-1.0f < car->pos.y - sa->unk_18.y || -1.0f < p->unk_1F0.y - sa->unk_18.y ||
                        fn_1_7B054() == 0x21) {
                        dir = 1;
                    }
                } else if (!below && belowPrev) {
                    dir = -1;
                }
            }
        }

        if (dir != 0 && !(car->flags & 0x10000) && (car->flags58C & 8) && p->unk_140 >= 0) {
            t = 0.0f;
            if (dir > 0) {
                p->unk_11C++;
            } else {
                p->unk_11C--;
            }
            if (p->unk_11C > 10000) {
                p->unk_11C = 10000;
            }
            if (p->unk_11C < -1) {
                p->unk_11C = -1;
            }
            if (p->unk_118 - p->unk_11C > 1) {
                p->unk_11C = p->unk_118 - 1;
            }
            if (p->unk_118 < p->unk_11C) {
                p->unk_118 = p->unk_11C;
                if (p->unk_11C != 0) {
                    fa = __fabs(za);
                    fb = __fabs(zb);
                    t = fb / (fa + fb);
                    if (fn_1_8A1B4_nonfinite(t)) {
                        t = 0.0f;
                    } else if (t < 0.0f) {
                        t = 0.0f;
                    } else if (t > 1.0f) {
                        t = 1.0f;
                    }
                    if (p->unk_160[0].frames < 360000) {
                        p->unk_160[0].frames--;
                        p->unk_160[0].frac += t;
                    } else {
                        p->unk_160[0].frames = 360000;
                        p->unk_160[0].frac = 0.0f;
                    }
                    if (p->unk_160[0].frac >= 1.0f) {
                        p->unk_160[0].frac -= 1.0f;
                        p->unk_160[0].frames++;
                    }
                    fn_1_8A1B4_split(&p->unk_160[0]);
                }
                fn_1_892CC((void *)&p->unk_160[8], (void *)&p->unk_160[7], 0, 0);
                fn_1_892CC((void *)&p->unk_160[7], (void *)&p->unk_160[6], 0, 0);
                fn_1_892CC((void *)&p->unk_160[6], (void *)&p->unk_160[5], 0, 0);
                fn_1_892CC((void *)&p->unk_160[5], (void *)&p->unk_160[4], 0, 0);
                fn_1_892CC((void *)&p->unk_160[4], (void *)&p->unk_160[3], 0, 0);
                fn_1_892CC((void *)&p->unk_160[3], (void *)&p->unk_160[2], 0, 0);
                fn_1_892CC((void *)&p->unk_160[2], (void *)&p->unk_160[1], 0, 0);
                fn_1_892CC((void *)&p->unk_160[1], (void *)&p->unk_160[0], 0, 0);
                if ((p->unk_1CC.frames == 0 && 0.0f == p->unk_1CC.frac) ||
                    p->unk_160[0].frames < p->unk_1CC.frames ||
                    (p->unk_160[0].frames == p->unk_1CC.frames && p->unk_160[0].frac < p->unk_1CC.frac)) {
                    fn_1_892CC((void *)&p->unk_1CC, (void *)&p->unk_160[0], 0, 0);
                    p->unk_117 = p->unk_118 > 0 ? p->unk_118 - 1 : 0;
                }
                fn_1_8A1B4_add(&p->unk_1D8, &p->unk_1D8, &p->unk_160[0]);
                fn_1_892E8((void *)&p->unk_160[0], 0);
                p->unk_160[0].frac = 1.0f - t;
                if (p->unk_160[0].frac >= 1.0f) {
                    p->unk_160[0].frac -= 1.0f;
                    p->unk_160[0].frames++;
                }
                p->unk_15C = -1;
                car->flags |= 0x40000;
            }
        }
        if (p->unk_118 == p->unk_11C) {
            fn_1_224F8(&car->pos, &car->unk_88, &p->unk_15C);
        }
        fn_1_8A1B4_split(&p->unk_160[0]);
        fn_1_8A1B4_add(&p->unk_1E4, &p->unk_1D8, &p->unk_160[0]);
        if (lbl_1_bss_3BE0->unk_7D != 0) {
            p->unk_F8 = p->unk_100;
        } else {
            p->unk_F8 = p->unk_100 + (f32)(p->unk_FC * p->unk_11C);
        }
    }

    if (warp != 0 && dir >= 0) {
        fn_1_25004((void *)car);
    }
    if (car->flags58C & 8) {
        p->unk_1F0 = car->pos;
    }
    if (!(car->flags & 0x800) && warp == 0 && keep == 0 && (q = car->unk_49C) != NULL) {
        for (i = 0; i < 4; i++) {
            q->unk_120[i] = q->unk_90[i];
            q->unk_130[i] = q->unk_94[i];
        }
        q->unk_140 = car->unk_1CC;
        q->unk_144 = car->unk_1D0;
        q->unk_148 = car->pos;
        q->unk_154 = q->unk_118;
        q->unk_158 = q->unk_11C;
    }
    if (reset != 0) {
        p->unk_140 = -1;
    }
    }
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_8A1B4 */

/* fzgx:begin fn_1_8B880 */
/* TU A .bss 6DA7A..6DA7D: defined here, after the objects of fn_1_85934 and before fn_1_8B8A4 (retail .bss order) */
static u8 lbl_1_bss_6DA7A = 0;
static u8 lbl_1_bss_6DA7B = 0;
static u8 lbl_1_bss_6DA7C = 0;
static u8 lbl_1_bss_6DA7D = 0;

/* Unknown retail objects: .rodata 3CDC..3CEF, no retail function reads them (after fn_1_8A1B4's literals) */
static const GXColor lbl_1_rodata_3CDC[3] = {{0xC0, 0x00, 0x00, 0xFF}, {0x00, 0x00, 0xC0, 0xFF}, {0x00, 0x00, 0x00, 0x00}};
const f64 lbl_1_rodata_3CE8 = 640.0;
void fn_1_8B880(void) {
    fn_1_8B8A4( (0));
}
/* fzgx:end fn_1_8B880 */

/* fzgx:begin fn_1_8B8A4 */
void fn_1_8B8A4(void *arg) {
    s32 i;

    for (i = 0; i < 30; i++) {
        lbl_1_bss_6DA5C[i] = i;
        lbl_1_bss_6DA3C[i] = i;
    }
    fn_800793D4( lbl_1_bss_6DA80, 0, 0x6CC);
    fn_800793D4( lbl_1_bss_6E160, 0, 0x6CC);
    lbl_1_bss_6DA7C = 0;
    lbl_1_bss_6DA7D = 0;
    lbl_1_bss_6DA7A = 1;
    lbl_1_bss_6DA7B = 1;
    if (lbl_1_bss_6D838 != NULL && ((CarObj *)lbl_1_bss_6D838)->info != NULL) {
        lbl_1_bss_6DA7A = ((CarObj *)lbl_1_bss_6D838)->info->unk_115;
        lbl_1_bss_6DA7B = ((CarObj *)lbl_1_bss_6D838)->info->unk_115;
    }
    fn_1_8B9B8((void *)arg);
}
/* fzgx:end fn_1_8B8A4 */

/* fzgx:begin fn_1_8B9B8 */
/* Unknown retail function: the retail link removed it and no surviving code holds a copy of it.
   Its literal is .rodata 3CF0 (f64 -1.0), created before fn_1_8B9B8's first literal (f64 0.05 at .rodata 3CF8).
   The retail body is not known: this placeholder only recreates the literal 3CF0 in retail order.
   WARNING: compiler-diff device, not original code (the body is a placeholder that only rebuilds the literals) */
/* WARNING: compiler-diff device, not original code */
static f64 car_literal_order_3CF0(f64 x)
{
    return -1.0 * x;
}

/* the locked-cache matrix at 0xE0000000 (car_test.c spells it the same way) */

#define HW_F32(off) (*(f32 *)(0xE0000000 + (off)))

static inline Progress8B9B8 *fn_1_8B9B8_progress(s32 seat) {
    return (lbl_1_bss_6D838 != NULL) ? lbl_1_bss_6D838[seat].unk_49C : NULL;
}

static inline void fn_1_8B9B8_ports(Racer8B9B8 *racers) {
    s32 i;
    s8 seat;
    u8 rank;
    s8 *port;

    port = (s8 *)&lbl_1_data_20664;
    for (i = 0; i < 4; port++, i++) {
        seat = *port;
        if (seat != -1) {
            rank = racers[seat].unk_49C->unk_115;
            if (rank < lbl_1_bss_6DA7A) {
                lbl_1_bss_6DA7A = rank;
                lbl_1_bss_6DA7C = seat;
            }
            if (rank > lbl_1_bss_6DA7B) {
                lbl_1_bss_6DA7B = rank;
                lbl_1_bss_6DA7D = *port;
            }
        }
    }
}

void fn_1_8B9B8(Race8B9B8 *race) {
    s8 start[4];
    s8 end[4];
    s16 seats[30];
    s32 group[30];
    f32 keys[30];
    Racer8B9B8 *racers;
    Progress8B9B8 *p;
    s32 i;
    s32 g;
    s8 best;
    s32 j;
    s8 k;
    f32 ratio;
    Progress8B9B8 *q;
    s32 m;

    /* retail tests the course word signed (cmpwi), though globals.h types it u32 */
    if (lbl_1_bss_3BE0 != NULL && (s32)lbl_1_bss_3BE0->unk_8 != 0) {
        lbl_1_bss_6D84B = 0;
        lbl_1_bss_6D84C = 0;
        for (i = 0; i < lbl_1_bss_6D84A; i++) {
            u32 flags = lbl_1_bss_6D838[lbl_1_bss_6DA5C[i]].unk_0;
            if (flags & 0x20000000) {
                group[i] = 3;
            } else if (flags & 0x10000) {
                group[i] = 0;
                lbl_1_bss_6D84B++;
                lbl_1_bss_6D84C++;
            } else if ((race != NULL && (race->flags & 0x8000)) || !(flags & 0x08000000)) {
                group[i] = 1;
                lbl_1_bss_6D84B++;
            } else {
                group[i] = 2;
            }
        }
        if (race != NULL) {
            race->unk_A = lbl_1_bss_6D84B;
            race->unk_B = lbl_1_bss_6D84C;
        }

        k = 0;
        for (g = 0; g < 4; g++) {
            start[g] = k;
            for (i = 0; i < lbl_1_bss_6D84A; i++) {
                if (group[i] == g) {
                    s8 seat = lbl_1_bss_6DA5C[i];
                    p = (Progress8B9B8 *)lbl_1_bss_6D838[seat].unk_49C;
                    if (g == 0) {
                        keys[k] = p->unk_1D8 + p->unk_1DC;
                    } else {
                        keys[k] = p->unk_F8;
                    }
                    seats[k++] = seat;
                }
            }
            end[g] = k;
        }

        for (g = 0; g < 4; g++) {
            for (i = start[g]; i < end[g]; i++) {
                f32 bestKey = keys[i];
                best = i;
                for (j = i + 1; j < end[g]; j++) {
                    if (g == 0) {
                        if (bestKey > keys[j]) {
                            bestKey = keys[j];
                            best = j;
                        }
                    } else if (bestKey < keys[j]) {
                        best = j;
                        bestKey = keys[j];
                    }
                }
                if (best != i) {
                    s16 seat = seats[i];
                    f32 key;
                    seats[i] = seats[best];
                    seats[best] = seat;
                    key = keys[i];
                    keys[i] = keys[best];
                    keys[best] = key;
                }
                lbl_1_bss_6DA5C[i] = seats[i];
            }
        }

        for (i = 0; i < lbl_1_bss_6D84A; i++) {
            s8 seat = lbl_1_bss_6DA5C[i];
            racers = (Racer8B9B8 *)&lbl_1_bss_6D838[seat];
            p = racers->unk_49C;
            p->unk_115 = i;
            lbl_1_bss_6DA3C[seat] = i;
            if (race != NULL) {
                race->unk_E[i] = seat;
                race->unk_2C[i] = p;
            }
        }

        lbl_1_bss_6DA7A = 0xFF;
        lbl_1_bss_6DA7B = 0;
        racers = (Racer8B9B8 *)lbl_1_bss_6D838;
        fn_1_8B9B8_ports(racers);
        if (lbl_1_bss_6DA7A == 0xFF) {
            lbl_1_bss_6DA7C = 0;
            lbl_1_bss_6DA7D = 0;
            lbl_1_bss_6DA7A = 1;
            lbl_1_bss_6DA7B = 1;
            if (racers != NULL && racers->unk_49C != NULL) {
                lbl_1_bss_6DA7A = racers->unk_49C->unk_115;
                lbl_1_bss_6DA7B = racers->unk_49C->unk_115;
            }
        }

        for (m = 0; m < lbl_1_bss_6D84A; m++, racers++) {
            q = racers->unk_49C;
            lbl_8006DC6C(racers->unk_EC);
            mathutil_mtxA_set_translate(&racers->pos);
            lbl_8006DB74(lbl_801A6D00 + 0x60);
            lbl_8006DBAC(q);
            lbl_8006DF44();
            if (q->unk_7C & 0x02200000) {
                ratio = 1.0f;
            } else {
                ratio = q->unk_34 / q->unk_30;
                if (ratio < 0.05) {
                    ratio = 0.0f;
                }
            }
            lbl_8006DFC4(lbl_801A6D00 + 0x60);
            q->unk_104 = fn_8006F394();
            if ((q->unk_7C & 0x02200000) || ratio == 0.0f) {
                q->unk_84 = q->unk_68;
                q->unk_108 = *(f32 *)(lbl_801A6D00 + 0xC);
            } else if (q->unk_7C & 0x01800000) {
                Vec3 b;
                Vec3 a;
                f32 ang;

                q->unk_84 = 1.5707963705062866 * (q->unk_6C * (q->unk_30 + q->unk_34));
                {
                    f32 y = -0.5f * q->unk_34;
                    a.x = 0.0f;
                    a.z = 0.0f;
                    a.y = y;
                }
                psvec_set(&b, HW_F32(0x2C), HW_F32(0x1C), HW_F32(0xC));
                {
                    f64 sign = (b.x < 0.0f) ? -1.0 : 1.0;
                    lbl_8006D6FC(&a, &b);
                    ang = sign * lbl_8006D46C();
                    if (q->unk_7C & 1) {
                        ang = ((ang < 0.0f) ? -1.0 : 1.0) * (32768.0 - __fabs(ang));
                    }
                }
                q->unk_108 = q->unk_84 * (ang / (65536.0f * q->unk_6C));
            } else {
                Vec3 b;
                Vec3 a;
                f32 half;
                f32 dist;
                f32 ang;
                f32 scale;
                f32 width;
                f32 edge;

                scale = 2.1415927410125732f * ratio;
                q->unk_84 = (1.0f + scale) * (q->unk_68 - q->unk_3C);
                {
                    f32 y = -0.5f * q->unk_40;
                    a.x = 0.0f;
                    a.z = 0.0f;
                    a.y = y;
                }
                psvec_set(&b, HW_F32(0x2C), HW_F32(0x1C), HW_F32(0xC));
                dist = __fabs(b.x);
                half = 0.5f * q->unk_3C;
                if (dist <= half) {
                    width = 2.0f * q->unk_3C;
                    q->unk_84 = q->unk_84 + width;
                    if ((b.y >= 0.0f) ^ (q->unk_7C & 1)) {
                        edge = 0.5f * q->unk_84;
                        dist = edge - dist;
                    }
                    if (b.x < 0.0f) {
                        dist = -dist;
                    }
                    q->unk_108 = dist;
                } else {
                    b.x = (b.x < 0.0f) ? b.x + half : b.x - half;
                    {
                        f64 sign = (b.x < 0.0f) ? -1.0 : 1.0;
                        lbl_8006D6FC(&a, &b);
                        ang = sign * lbl_8006D46C();
                        if (q->unk_7C & 1) {
                            ang = ((ang < 0.0f) ? -1.0 : 1.0) * (32768.0 - __fabs(ang));
                        }
                    }
                    q->unk_108 = 0.5 * ((ang / 32768.0f) * q->unk_84);
                    if (q->unk_108 < 0.0f) {
                        q->unk_108 -= half;
                    } else {
                        q->unk_108 += half;
                    }
                    width = 2.0f * q->unk_3C;
                    q->unk_84 = q->unk_84 + width;
                }
            }
        }

        {
            f32 lap;
            f32 wrap;
            u32 j;
            u32 pair;

            lap = fn_1_8B9B8_progress(0)->unk_FC;
            wrap = 0.5 * lap;
            for (i = 0; i < lbl_1_bss_6D84A; i++) {
                Progress8B9B8 *a = fn_1_8B9B8_progress(i);
                f32 dist0;
                f32 lat0;
                dist0 = a->unk_100;
                lat0 = a->unk_108;
                pair = i * 29U - (i * (i + 1U)) / 2 - 1;
                j = i + 1;
                pair += j;
                for (; j < lbl_1_bss_6D84A; j++, pair++) {
                    Progress8B9B8 *b = fn_1_8B9B8_progress(j);
                    f32 d = b->unk_100 - dist0;
                    if (d > wrap) {
                        d -= lap;
                    } else if (d < -wrap) {
                        d += lap;
                    }
                    lbl_1_bss_6DA80[pair] = d;
                    lbl_1_bss_6E160[pair] = b->unk_108 - lat0;
                }
            }
        }
    }
}

#undef HW_F32
/* fzgx:end fn_1_8B9B8 */

/* fzgx:begin fn_1_8C3EC */
u8 fn_1_8C3EC(void) {
    return lbl_1_bss_6DA7A;
}
/* fzgx:end fn_1_8C3EC */

/* fzgx:begin fn_1_8C3FC */
// fn_1_8C3FC: Load byte from BSS and return

u8 fn_1_8C3FC(void) {
    return lbl_1_bss_6DA7B;
}
/* fzgx:end fn_1_8C3FC */

/* fzgx:begin fn_1_8C40C */
f32 fn_1_8C40C(void) {
    if (lbl_1_bss_6DA7C >= lbl_1_bss_6D84A) {
        return 0.0f;
    }
    return ((Fn1844CValue *)lbl_1_bss_6D838[lbl_1_bss_6DA7C].unk_49C)->value;
}
/* fzgx:end fn_1_8C40C */

/* fzgx:begin fn_1_8C44C */
f32 fn_1_8C44C(void) {
    if (lbl_1_bss_6DA7D >= lbl_1_bss_6D84A) {
        return 0.0f;
    }
    return ((Fn1844CValue *)lbl_1_bss_6D838[lbl_1_bss_6DA7D].unk_49C)->value;
}
/* fzgx:end fn_1_8C44C */

/* fzgx:begin fn_1_8C48C */
// Return the selected car's handling value, or zero object's value when unavailable.

f32 fn_1_8C48C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x50);
}
/* fzgx:end fn_1_8C48C */

/* fzgx:begin fn_1_8C4BC */
f32 fn_1_8C4BC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x54);
}
/* fzgx:end fn_1_8C4BC */

/* fzgx:begin fn_1_8C4EC */
f32 fn_1_8C4EC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x58);
}
/* fzgx:end fn_1_8C4EC */

/* fzgx:begin fn_1_8C51C */
// Return the indexed car's float field, or zero-base fallback when the car table is absent.

f32 fn_1_8C51C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x5c);
}
/* fzgx:end fn_1_8C51C */

/* fzgx:begin fn_1_8C54C */
f32 fn_1_8C54C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x60);
}
/* fzgx:end fn_1_8C54C */

/* fzgx:begin fn_1_8C57C */
f32 fn_1_8C57C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x64);
}
/* fzgx:end fn_1_8C57C */

/* fzgx:begin fn_1_8C5AC */
// Return the indexed car's float value.

f32 fn_1_8C5AC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x68);
}
/* fzgx:end fn_1_8C5AC */

/* fzgx:begin fn_1_8C5DC */
u32 fn_1_8C5DC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u32 *)(ptr + 0x118);
}
/* fzgx:end fn_1_8C5DC */

/* fzgx:begin fn_1_8C60C */
u32 fn_1_8C60C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u32 *)(ptr + 0x88);
}
/* fzgx:end fn_1_8C60C */

/* fzgx:begin fn_1_8C63C */
u32 fn_1_8C63C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    ptr = *(u32 *)(ptr + 0x8c);
    return ptr;
}
/* fzgx:end fn_1_8C63C */

/* fzgx:begin fn_1_8C66C */
// Return the value stored in the indexed car's nested state object.

u32 fn_1_8C66C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    ptr = *(u32 *)(ptr + 0x90);
    return *(u32 *)ptr;
}
/* fzgx:end fn_1_8C66C */

/* fzgx:begin fn_1_8C6A0 */
f32 fn_1_8C6A0(u32 index) {
    u32 base;
    u32 car;
    u32 state;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        car = base + index * 0x620;
    } else {
        car = 0;
    }

    state = *(u32 *)(car + 0x49c);
    state = *(u32 *)(state + 0x94);
    return *(f32 *)state;
}
/* fzgx:end fn_1_8C6A0 */

/* fzgx:begin fn_1_8C6D4 */
u32 fn_1_8C6D4(u32 index) {
    u32 base;
    u32 car;
    u32 state;

    // Return the requested car's value from its state block.
    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        car = base + index * 0x620;
    } else {
        car = 0;
    }

    state = *(u32 *)(car + 0x49c);
    return *(u32 *)(state + 0xb8);
}
/* fzgx:end fn_1_8C6D4 */

/* fzgx:begin fn_1_8C704 */
// Returns the selected car's value at offset 0xd8.

u32 fn_1_8C704(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u32 *)(ptr + 0xd8);
}
/* fzgx:end fn_1_8C704 */

/* fzgx:begin fn_1_8C734 */
// Return the selected car's float field, or the null object's field when unavailable.

f32 fn_1_8C734(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0xf8);
}
/* fzgx:end fn_1_8C734 */

/* fzgx:begin fn_1_8C764 */
f32 fn_1_8C764(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0xfc);
}
/* fzgx:end fn_1_8C764 */

/* fzgx:begin fn_1_8C794 */
f32 fn_1_8C794(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x100);
}
/* fzgx:end fn_1_8C794 */

/* fzgx:begin fn_1_8C7C4 */
// Return the selected car's status byte, or the null-entry status when unavailable.

u8 fn_1_8C7C4(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u8 *)(ptr + 0x115);
}
/* fzgx:end fn_1_8C7C4 */

/* fzgx:begin fn_1_8C7F4 */
u8 fn_1_8C7F4(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u8 *)(ptr + 0x116);
}
/* fzgx:end fn_1_8C7F4 */

/* fzgx:begin fn_1_8C824 */
u16 fn_1_8C824(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u16 *)(ptr + 0x104);
}
/* fzgx:end fn_1_8C824 */

/* fzgx:begin fn_1_8C854 */
f32 fn_1_8C854(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x108);
}
/* fzgx:end fn_1_8C854 */

/* fzgx:begin fn_1_8C884 */
u32 fn_1_8C884(u32 arg0) {
    u32 v0;
    s32 v1;
    u32 v2;
    v0 = (u32)lbl_1_bss_6D838;
    v1 = arg0;
    v2 = v0;
    if (v0 != 0) {
    v1 = (v2 + (v1 * 1568));
    v2 = *(u32 *)(v1 + 1180);
    } else {
    v2 = 0;
    }
    return ((*(u32 *)(v2 + 280) << 2) + __cntlzw(*(u32 *)(v2 + 348)));
}
/* fzgx:end fn_1_8C884 */

/* fzgx:begin fn_1_8C8C4 */
f32 fn_1_8C8C4(u32 index) {
    return lbl_1_bss_6D838[index].unk_1F4;
}
/* fzgx:end fn_1_8C8C4 */

/* fzgx:begin fn_1_8C8DC */
f32 fn_1_8C8DC(u32 index) {
    return lbl_1_bss_6D838[index].unk_1F8;
}
/* fzgx:end fn_1_8C8DC */

/* fzgx:begin fn_1_8C8F4 */
f32 fn_1_8C8F4(u32 index) {
    return lbl_1_bss_6D838[index].unk_1FC;
}
/* fzgx:end fn_1_8C8F4 */

/* fzgx:begin fn_1_8C90C */
f32 fn_1_8C90C(s32 index) {
    return lbl_1_bss_6D838[index].unk_200;
}
/* fzgx:end fn_1_8C90C */

/* fzgx:begin fn_1_8C924 */
f32 fn_1_8C924(s32 index) {
    return lbl_1_bss_6D838[index].unk_204;
}
/* fzgx:end fn_1_8C924 */

/* fzgx:begin fn_1_8C93C */
s32 fn_1_8C93C(s32 index) {
    u32 ref = lbl_1_bss_6D838[index].unk_484;
    if (ref != 0) {
        return ((fn_1_95238_lbl_801A6D00 *)ref)->unk_0;
    }
    return -1;
}
/* fzgx:end fn_1_8C93C */

/* fzgx:begin fn_1_8C968 */
s32 fn_1_8C968(s32 index) {
    u8 *data;

    data = (u8 *)lbl_1_bss_6D838[index].unk_484;
    if (data != 0) {
        return data[0x32];
    }
    return -1;
}
/* fzgx:end fn_1_8C968 */

/* fzgx:begin fn_1_8C994 */
// Return the shared car-state object.

Obj_1_bss_6D838_Target *fn_1_8C994(void) {
    return lbl_1_bss_6D838;
}
/* fzgx:end fn_1_8C994 */

/* fzgx:begin fn_1_8C9A4 */
// Returns the address of the object's field at offset 0x6.

u32 fn_1_8C9A4(void) {
    return (u32)&lbl_1_bss_6D838->unk_6;
}
/* fzgx:end fn_1_8C9A4 */

/* fzgx:begin fn_1_8C9B8 */
// Return the address of the object's field at offset 0x7c.

u32 fn_1_8C9B8(void) {
    return (u32)&lbl_1_bss_6D838->unk_7C;
}
/* fzgx:end fn_1_8C9B8 */

/* fzgx:begin fn_1_8C9CC */
// Return the address of the vehicle's field at offset 0x80.

u32 *fn_1_8C9CC(void) {
    return &lbl_1_bss_6D838->unk_80;
}
/* fzgx:end fn_1_8C9CC */

/* fzgx:begin fn_1_8C9E0 */
u32 *fn_1_8C9E0(void) {
    return &lbl_1_bss_6D838->unk_84;
}
/* fzgx:end fn_1_8C9E0 */

/* fzgx:begin fn_1_8C9F4 */
s8 *fn_1_8C9F4(void) {
    return &lbl_1_bss_6D84A;
}
/* fzgx:end fn_1_8C9F4 */

/* fzgx:begin fn_1_8CA00 */
u32 *fn_1_8CA00(void) {
    return (void *)&lbl_1_data_1FFDC;
}
/* fzgx:end fn_1_8CA00 */

/* fzgx:begin fn_1_8CA0C */
u32 fn_1_8CA0C(void) {
    return (u32)lbl_1_bss_6D83C + 0x328;
}
/* fzgx:end fn_1_8CA0C */

/* fzgx:begin fn_1_8CA20 */
// Return the car object's data pointer adjusted to this function's subobject.

u32 fn_1_8CA20(void) {
    return (u32)lbl_1_bss_6D83C + 0x3a8;
}
/* fzgx:end fn_1_8CA20 */

/* fzgx:begin fn_1_8CA34 */
// Return the car object address adjusted to this function's field.

u32 fn_1_8CA34(void) {
    return (u32)lbl_1_bss_6D83C + 0x3ac;
}
/* fzgx:end fn_1_8CA34 */

/* fzgx:begin fn_1_8CA48 */
u32 fn_1_8CA48(void) {
    return (u32)lbl_1_bss_6D83C + 0x3b0;
}
/* fzgx:end fn_1_8CA48 */

/* fzgx:begin fn_1_8CA5C */
u32 fn_1_8CA5C(void) {
    return (u32)lbl_1_bss_6D83C + 0x3b4;
}
/* fzgx:end fn_1_8CA5C */

/* fzgx:begin fn_1_8CA70 */
f32 fn_1_8CA70(u32 a, s32 b) {
    f32 value;
    u32 total;
    u32 half;
    u32 span;
    u32 index;
    int swapped = 0;
    if (a == b) {
        return 0.0f;
    }
    if (a > b) {
        u32 temp = a;
        a = b;
        b = temp;
        swapped = 1;
    }
    total = a * 30;
    half = (a * (a + 1)) >> 1;
    span = b - a;
    index = (total - half) + (span - 1);
    value = lbl_1_bss_6E160[index];
    if (!swapped) {
        return value;
    }
    if (0.0 == value) {
        return value;
    }
    value *= -1.0;
    return value;
}
/* fzgx:end fn_1_8CA70 */

/* fzgx:begin fn_1_8CAF4 */
f32 fn_1_8CAF4(u32 a, s32 b) {
    f32 value;
    u32 total;
    u32 half;
    u32 span;
    u32 index;
    int swapped = 0;
    if (a == b) {
        return 0.0f;
    }
    if (a > b) {
        u32 temp = a;
        a = b;
        b = temp;
        swapped = 1;
    }
    total = a * 30;
    half = (a * (a + 1)) >> 1;
    span = b - a;
    index = (total - half) + (span - 1);
    value = lbl_1_bss_6DA80[index];
    if (!swapped) {
        return value;
    }
    if (0.0 == value) {
        return value;
    }
    value *= -1.0;
    return value;
}
/* fzgx:end fn_1_8CAF4 */

/* fzgx:begin fn_1_8CB78 */
void fn_1_8CB78(EntryTable *table) {
    u32 offset;
    s8 index;

    offset = 0;
    index = 0;
    while (index < table->count) {
        fn_1_8CB78_Entry *entry = (fn_1_8CB78_Entry *)(table->data + offset);
        fn_1_A8DD4("%2d:%3uX%3u %u\n", index, entry->value8,
                   entry->valueA, entry->pointer);
        offset += 0x10;
        index++;
    }
}
/* fzgx:end fn_1_8CB78 */

/* fzgx:begin fn_1_8CC04 */
void fn_1_8CC04(CarDbgObj *obj, s8 sel, s16 x, s16 y, u32 value, f32 scale) {
    CarDbgEntry *entries;
    CarDbgEntry *e;
    s8 i;
    f32 cx;
    f32 cy;
    f32 t;
    CarDbgRect rect;
    u32 w20;
    u16 width;
    u16 height;
    u32 w1C;
    u32 w18;
    u32 w14;
    u8 b0C;

    entries = obj->entries;
    cx = (x - 320.0f) / 320.0f;
    cy = (y - 240.0f) / 240.0f;

    rect.flag = (lbl_1_bss_D58.unk_0 >> 11) & 1;
    fn_80008BEC((void *)&rect, 0, sizeof(rect));
    fn_80008BA8(&rect.value, &value, 4);
    sel = (sel < obj->count - 1) ? sel : obj->count - 1;
    fn_1_A8EF8(x, y);
    if (obj != NULL && entries != NULL) {
        fn_1_A8DD4("%2d/%2d\n", sel + 1, obj->count);
    }
    e = entries;
    for (i = 0; i < obj->count; e++, i++) {
        if (i != sel) {
            continue;
        }
        if (e != NULL) {
            fn_1_A8DD4("texno[%2d]\n", e->id);
        }
        if (e == NULL || e->data == NULL) {
            fn_1_A8DD4("NULL\n");
        } else if (e->flags & 0x200000) {
            fn_1_A8DD4("CmnTex\n");
        } else {
            fn_80036070(e->data, &w20, &width, &height, &w1C, &w18, &w14, &b0C);
            rect.x0 = cx;
            rect.y0 = cy;
            t = scale * ((f32)width / height);
            rect.x1 = cx + ((t < scale) ? t : scale);
            t = scale * ((f32)height / width);
            rect.y1 = cy + ((t < scale) ? t : scale);
            rect.z = -1.0f;
            fn_1_A8DD4("%3dX%3d\n", width, height);
            fn_800084E8(e->data, &rect);
        }
    }
}
/* fzgx:end fn_1_8CC04 */

/* fzgx:begin fn_1_8CED0 */
void fn_1_8CED0(Fn1_8CED0State *state, u16 arg1, u16 arg2) {
    u16 h = arg2;
    u32 w = arg1;

    state->unk_00 = 0.0f;
    state->unk_04 = 0.0f;
    state->unk_08 = w;
    state->unk_0C = h;
    state->unk_10 = 0.0f;
    state->unk_14 = 1.0f;
    state->unk_18 = 0.0f;
    state->unk_1C = 0.0f;
    state->unk_20 = w;
    state->unk_24 = h;
    state->unk_28 = 0;
    state->unk_2A = 0;
    state->unk_2C = arg1;
    state->unk_2E = arg2;
    if (lbl_1_bss_8CA28 != 0) {
        state->unk_34 = 5;
    } else {
        state->unk_34 = 6;
    }
    state->unk_38 = 1;
    if (lbl_1_bss_8CA28 != 0) {
        state->unk_39 = 1;
    } else {
        state->unk_39 = 0;
    }
    w = state->unk_39;
    if ((w) != 0) {
        state->unk_30 = state->unk_2C >> 1;
        state->unk_32 = state->unk_2E >> 1;
    } else {
        state->unk_30 = state->unk_2C;
        state->unk_32 = state->unk_2E;
    }
    state->unk_3A = 1;
    state->unk_3C = 7;
    state->unk_40 = 0;
    state->unk_44 = 55.0f;
    state->unk_48 = (0.9333333373069763f * arg1) / arg2;
    state->unk_4C = 0.10000000149011612f;
    state->unk_50 = 90000.0f;    state->unk_54 = 1;
    fn_80008BEC((void *)state->unk_5C, 0, 4);
    state->unk_58 = 1;
}
/* fzgx:end fn_1_8CED0 */

/* fzgx:begin fn_1_8D0A4 */
static inline u32 abs_value(u32 value) {
    u32 sign = value >> 31;
    u32 low = value & 1;
    return (low ^ sign) - sign;
}

void fn_1_8D0A4(Fn1_8D0A4State *state) {
    if (state->width == 0 && state->height == 0) {
        state->result = 0;
    } else {
        if (abs_value(state->width) != 0 || abs_value(state->height) != 0) {
            state->width = 0x280;
            state->height = 0x1e0;
        }
        state->result = ((u32)fn_1_4630(
            (u32)((*((void * *)&lbl_801A6410))),
            (u32)(GXGetTexBufferSize(state->width, state->height, state->arg34, 0, 0)),
            (void *)&lbl_1_data_1FFF0,
            (u32)0x1bfc));
    }
}
/* fzgx:end fn_1_8D0A4 */

/* fzgx:begin fn_1_8D168 */
void fn_1_8D168(Fn1_8D168State *state) {
    fn_8006FDEC();
    fn_8006FEFC();
    if (state->field_60 != 0) {
        fn_1_46B4(lbl_801A6410, state->field_60, (const char *)(lbl_1_data_1FFF0), 0x1c04);
        state->field_60 = 0;
    }
}
/* fzgx:end fn_1_8D168 */

/* fzgx:begin fn_1_8D1C8 */
/* Unknown retail objects: .data 20950..20993, debug format strings no retail function reads (after fn_1_8CC04's literals) */
static char lbl_1_data_20950[24] = "%2d %7s %0x (%2.1f%)\n";
static char lbl_1_data_20968[24] = "----------------------\n";
static char lbl_1_data_20980[20] = "Total %0x (%2.1f%)";

void fn_1_8D1C8(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg) {
    fn_1_8D210(car, callback, arg, 1);
}
/* fzgx:end fn_1_8D1C8 */

/* fzgx:begin fn_1_8D1EC */
void fn_1_8D1EC(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg) {
    fn_1_8D210(car, callback, arg, 0);
}
/* fzgx:end fn_1_8D1EC */

/* fzgx:begin fn_1_8D210 */
/* rodata tables shared by the functions of this unit and the next ones */
const u32 lbl_1_rodata_3D34[41] = {0x60000000, 0x60000000, 0xC0000000, 0x60000000, 0xC0000000, 0xC0000000, 0xC0000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x00000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000};  /* fzgx-allow: A1 bit masks, not addresses */
static const u16 lbl_1_rodata_3DD8[42] = {0x000A, 0x0008, 0x0063, 0x0007, 0x0063, 0x0063, 0x0063, 0x0008, 0x0007, 0x000C, 0x0008, 0x000A, 0x0008, 0x0008, 0x0008, 0x000A, 0x0007, 0x000A, 0x0007, 0x000C, 0x000C, 0x000C, 0x000A, 0x0007, 0x000A, 0x0008, 0x000A, 0x000A, 0x0007, 0x000A, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0000};
s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable) {
    u8 local_34[24];
    u8 local_14[4];
    u8 local_10[4];
    u8 local_c[4];
    u8 local_8[4];
    u8 local_18[0x1c];
    u8 local_8c[52];
    u8 local_4c[64];
    s32 result;

    lbl_8006DD14(lbl_801A6D00 + 0x30, local_8c);
    fn_80038F10( (f32*)(local_34));
    GXGetScissor( (u32 *)(local_14), (u32 *)(local_10), (u32 *)(local_c), (u32 *)(local_8));
    GXGetProjectionv( (f32*)(local_18));
    fn_1_550A8();
    C_MTXPerspective( (f32 *)(local_4c), car->field_44, car->field_48, car->field_4c, car->field_50);
    fn_800737E4(local_4c, 0);
    fn_80038EEC(car->position[0], car->position[1], car->position[2], car->position[3], car->position[4], car->position[5]);
    fn_80074188(__cvt_fp2unsigned(car->scale_z), __cvt_fp2unsigned(car->scale_y),
                __cvt_fp2unsigned(car->scale_x), __cvt_fp2unsigned(car->field_24));
    lbl_8006D758();
    fn_80074918(car->field_3a, car->field_3c, car->field_40);
    if (car->field_58 != 0)
        fn_80008204(&car->field_5c);
    result = callback(arg);
    if (car->field_54 != 0)
        fn_1_545B8();
    if (enable != 0) {
        fn_80074300(car->field_28, car->field_2a, car->field_2c, car->field_2e);
        fn_80074438(car->field_30, car->field_32, car->field_34, car->field_39);
        fn_8003526C(car->field_60, car->field_38);
        GXInvalidateTexAll();
    }
    fn_80074918(1, 3, 0);
    fn_1_550E0();
    lbl_8006DD14(local_8c, lbl_801A6D00 + 0x30);
    fn_80038EEC(*(f32 *)&local_34[0], *(f32 *)&local_34[4], *(f32 *)&local_34[8], *(f32 *)&local_34[12],
                *(f32 *)&local_34[16], *(f32 *)&local_34[20]);
    fn_80074188(*(s32 *)&local_14[0], *(s32 *)&local_10[0], *(s32 *)&local_c[0], *(s32 *)&local_8[0]);
    fn_80072270(local_18);
    return result;
}
/* fzgx:end fn_1_8D210 */

/* fzgx:begin fn_1_8D3F8 */
u32 fn_1_8D3F8(Fn1_8D3F8Car *car, u32 arg1, u32 (*callback)(u32), u32 arg3) {
    u32 local_14;
    u32 local_10;
    u32 local_0c;
    u32 local_08;
    u8 local_30[0x1c];
    f32 local_18[6];
    u8 local_7c[0x40];
    u8 local_4c[0x30];
    u32 result;

    lbl_8006DD14(lbl_801A6D00 + 0x30, local_4c);
    fn_80038F10(local_18);
    GXGetScissor( &local_08, &local_0c, &local_10, &local_14);
    GXGetProjectionv((f32 *)local_30);
    fn_1_550A8();
    C_MTXPerspective( (f32 *)(local_7c), car->field_44, car->field_48, car->field_4c, car->field_50);
    fn_800737E4(local_7c, 0);
    fn_80038EEC(car->field_00, car->field_04, car->field_08, car->field_0c, car->field_10, car->field_14);
    fn_80074188(__cvt_fp2unsigned(car->field_18), __cvt_fp2unsigned(car->field_1c),
                __cvt_fp2unsigned(car->field_20), __cvt_fp2unsigned(car->field_24));
    lbl_8006D758();
    fn_80074918(car->field_3a, car->field_3c, car->field_40[0]);
    if (car->field_58 != 0) {
        fn_80008204(&car->field_5c);
    }
    result = callback(arg3);
    if (car->field_54 != 0) {
        fn_1_545B8();
    }
    fn_80074300(car->field_28, car->field_2a, car->field_2c, car->field_2e);
    fn_80074438(car->field_30, car->field_32, car->field_34, car->field_39);
    fn_8003526C(car->field_60, car->field_38);
    GXInvalidateTexAll();
    fn_80074918(1, 3, 0);
    fn_1_550E0();
    lbl_8006DD14(local_4c, lbl_801A6D00 + 0x30);
    fn_80038EEC(local_18[0], local_18[1], local_18[2], local_18[3], local_18[4], local_18[5]);
    fn_80074188(local_08, local_0c, local_10, local_14);
    fn_80072270(local_30);
    fn_1_4FC50(arg1, car->field_34, car->field_30, car->field_32, car->field_60);
    return result;
}
/* fzgx:end fn_1_8D3F8 */

/* fzgx:begin fn_1_8D5F0 */
u32 fn_1_8D5F0(s16 index) {
    Table table;

    table = *(Table *)lbl_1_rodata_3D34;
    return table.data[index];
}
/* fzgx:end fn_1_8D5F0 */

/* fzgx:begin fn_1_8D640 */
s16 fn_1_8D640(s16 index) {
    Fn1_8D640Table table = *(Fn1_8D640Table *)lbl_1_rodata_3DD8;
    return table.values[index];
}
/* fzgx:end fn_1_8D640 */

/* fzgx:begin fn_1_8D690 */
// Return whether the indexed flag remains enabled after the preliminary check.

u32 fn_1_8D690(s16 arg0) {
    FnTable table;
    u32 valid;

    valid = 1;
    if (!fn_1_F7BE4(arg0)) {
        table = *(const FnTable *)lbl_1_rodata_3D34;
        if ((table.entries[arg0] & ~0x7fffffff) == 0) {
            valid = 0;
        }
    }
    return valid != 0;
}
/* fzgx:end fn_1_8D690 */

/* fzgx:begin fn_1_8D72C */
u32 fn_1_8D72C(s16 index) {
    Table164 table;
    s32 result;

    result = 1;
    if (fn_1_F7BE4(index) == 0) {
        table = *(const Table164 *)lbl_1_rodata_3D34;
        if ((table.w[index] & 0x40000000) == 0) {
            result = 0;
        }
    }
    return result != 0;
}
/* fzgx:end fn_1_8D72C */

/* fzgx:begin fn_1_8D7C8 */
s16 fn_1_8D7C8(void) {
    int enabled;
    u32 *value;
    s16 index;
    s16 count;
    Fn1_8D7C8Data data;

    count = 0;
    index = 0;
    value = data.values;
    while (index < 41) {
        enabled = 1;
        if (fn_1_F7BE4(index) == 0) {
            data = *(Fn1_8D7C8Data *)lbl_1_rodata_3D34;
            if ((*value & 0x40000000) == 0) {
                enabled = 0;
            }
        }
        if (enabled != 0) {
            count = (count + 1);
        }
        value++;
        index++;
    }
    return count;
}
/* fzgx:end fn_1_8D7C8 */

/* fzgx:begin fn_1_8D894 */
void fn_1_8D894(Obj_1_bss_6D838_Target *car) {
    u32 value;
    u32 obj;

    // Initialize the car resource and register it when allocation succeeds.
    value = car->unk_0;
    car->unk_0 = value | 0x04000000;
    obj = ((s32)fn_1_45D0((void *)lbl_801A6410, (s32)0x88, (void *)lbl_1_data_1FFF0, (s32)0x1CB0));
    car->unk_484 = obj;
    obj = car->unk_484;
    if (obj == 0) {
        value = car->unk_0;
        car->unk_0 = value & 0xFBFFFFFF;
    } else {
        *(u32 *)((u8 *)obj + 0x40) = lbl_801A6410;
        *((u8 *)car + 0x50E) = 1;
        fn_1_C487C((void *)car);
        fn_1_43E8(1);
        obj = (u32)fn_1_3F8C(lbl_1_data_20700, fn_1_C4ABC, car, 3);
        lbl_1_bss_6D86C[(s8)car->unk_474] = obj;
        fn_1_43F4();
        lbl_1_bss_6D868[(s8)car->unk_474] = car->unk_4;
        *((s8 *)car + 0x474) = -1;
    }
}
/* fzgx:end fn_1_8D894 */

/* fzgx:begin fn_1_8D988 */
void fn_1_8D988(void) {
    u32 i;
    fn_1_8D988_Car *car;

    car = (fn_1_8D988_Car *)lbl_1_bss_6D838;
    for (i = 0; i < lbl_1_bss_6D84A; i++, car++) {
        if (car->unk_0 & 0x04000000) {
            continue;
        }
        car->unk_0 |= 0x04000000;
        car->unk_484 = fn_1_45D0((void *)lbl_801A6410, 0x88, (char *)lbl_1_data_1FFF0, 0x1cb0);
        if (car->unk_484 == 0) {
            car->unk_0 &= ~0x04000000;
            continue;
        }
        car->unk_484->unk_40 = (void *)lbl_801A6410;
        car->unk_50e = 1;
        fn_1_C487C((F83070Car *)car);
        fn_1_43E8(1);
        lbl_1_bss_6D86C[car->unk_474] = (u32)fn_1_3F8C(lbl_1_data_20700, fn_1_C4ABC, car, 3);
        fn_1_43F4();
        lbl_1_bss_6D868[car->unk_474] = car->unk_4;
        car->unk_474 = -1;
    }
}
/* fzgx:end fn_1_8D988 */

/* fzgx:begin fn_1_8DAB4 */
void fn_1_8DAB4(void) {
    u8 *pending;
    s32 *handles;
    u32 i;
    fn_1_8DAB4_Object *object;
    u32 flags;
    void *value;

    pending = lbl_1_bss_6D868;
    handles = (s32 *)lbl_1_bss_6D86C;
    for (i = 0; i < 4; i++, pending++, handles++) {
        if (*pending != 0xff) {
            object = (fn_1_8DAB4_Object *)((u8 *)lbl_1_bss_6D838 + *pending * 0x620);
            flags = *(u32 *)object;
            flags &= 0xfbffffff;
            *(u32 *)object = flags;
            object->active = i;
            if (object->resource_holder != 0) {
                value = (void *)fn_80008E84( (u32)(object->resource_holder->value));
                fn_1_46B4(lbl_801A6410, (u32)(ResourceHolder *)(object->resource_holder), (const char *)lbl_1_data_1FFF0, 0x1ced);
                object->resource_holder = 0;
                fn_80008E84( (u32)(value));
            }
            if (*handles != -1) {
                fn_1_426C(*handles);
            }
            *pending = 0xff;
        }
    }
}
/* fzgx:end fn_1_8DAB4 */

/* fzgx:begin fn_1_8DB94 */
u8 fn_1_8DB94(void) {
    return lbl_1_bss_6D820;
}
/* fzgx:end fn_1_8DB94 */

/* fzgx:begin fn_1_8DBA4 */
void fn_1_8DBA4(u8 value) {
    lbl_1_bss_6D820 = value;
}
/* fzgx:end fn_1_8DBA4 */

/* fzgx:begin fn_1_8DBB0 */
static inline fn_1_8DBB0_Car *get_car(s8 index) {
    if (index < lbl_1_bss_6D84A && lbl_1_bss_6D83C != NULL) {
        return &((fn_1_8DBB0_Car *)lbl_1_bss_6D83C)[index];
    }
    return NULL;
}

static inline s8 next_lod(fn_1_8DBB0_Car *car, s8 lod) {
    s8 i = lod;

    if (i == 5) {
        return i;
    }
    if (lod < 0 || i > 5) {
        return (lod < 0) ? 0 : ((lod > 5) ? 5 : lod);
    }
    for (; i < 5; i++) {
        if (car->unk_38C & (1 << i)) {
            return i;
        }
    }
    return -1;
}

void fn_1_8DBB0(void) {
    s16 *row;
    fn_1_8DBB0_Setup setup;
    s32 i;
    fn_1_8DBB0_Car *car;
    s32 lod;
    s8 got;

    fn_1_3EF14(&setup);
    fn_80008BEC(lbl_1_bss_6E82C, 0, sizeof(lbl_1_bss_6E82C));
    lbl_1_bss_6DA38 = 1;
    row = (s16 *)lbl_1_bss_6E82C[0];
    for (i = 0; i < setup.unk_9; i++) {
        for (lod = 0; lod < 5; lod++) {
            car = get_car(i);
            lbl_8006DCA4();
            lbl_8006DD7C();
            lbl_8006E0B4(0.0f, 0.0f, -10.0f);
            lbl_8006DB74(car->unk_32C + 0x14C);
            got = next_lod(car, lod);
            if (got == -1) {
                break;
            }
            lod = got;
            car->unk_3BA = lod;
            fn_1_3BDC(0);
            fn_1_84860((void *)car);
            row[lod] = fn_1_3C18(0);
            /* WARNING: compiler-diff device, not original code (a redundant re-assignment that keeps
             * got live across the timing calls in r26, replacing #pragma opt_common_subs off) */
            lod = (u32)got;
        }
        row += 5;
    }
    lbl_1_bss_6DA38 = 0;
}


/* fzgx:end fn_1_8DBB0 */

/* fzgx:begin fn_1_8DD54 */
static inline CarTestCar *get_car_8DD54(s32 index) {
if ((s8)index < lbl_1_bss_6D84A && lbl_1_bss_6D83C != NULL) {
return &((CarTestCar *)lbl_1_bss_6D83C)[(s8)index];
}
return NULL;
}

void fn_1_8DD54(void) {
s32 i;
u32 limit;
CarTestCar *car;
s16 state;
CarTestInfo info;
u32 total;
fn_1_3EF14( (void *)((CarTestInfo *)(&info)));
total = 0;
switch (fn_1_58C4()) {
case 1:
state = fn_1_7B054();
if (state == 40) {
limit = 2100;
} else if (state == 25) {
limit = 1300;
} else {
limit = 1600;
}
break;
case 2:
limit = 1600;
break;
case 3:
limit = 600;
break;
case 4:
default:
limit = 600;
break;
}
if ((info.flags & 0x4000) && (fn_1_3F0C8() == 40 || fn_1_3FC18() > 0)) {
lbl_1_data_1FFE0 = 8.0f;
} else {
lbl_1_data_1FFE0 = 5.0f;
}
for (i = 0; i < info.count; i++) {
car = get_car_8DD54(i);
car->state = fn_1_84408((void *)car);
state = car->state;
if (state != 5 && *((u8 *)lbl_1_bss_6D838 + i * 0x620 + 0x50d) >= 0xf0) {
car->state = 3;
total += 50;
} else if (state != 5) {
total += lbl_1_bss_6E82C[i][state];
}
}
if (total > limit || lbl_1_bss_6D854) {
for (i = 0; i < info.count; i++) {
car = get_car_8DD54(i);
if (lbl_1_bss_6D980[i]) {
total -= lbl_1_bss_6E82C[i][car->state];
car->state = 5;
}
}
if (total > limit) {
for (i = 0; i < info.count; i++) {
car = get_car_8DD54(i);
if (car->state > 0 && car->state < 3) {
fn_1_8E084((void *)car, (void *)&total, i);
}
}
if (total > limit) {
for (i = 0; i < info.count; i++) {
car = get_car_8DD54(i);
if (car->state == 0) {
fn_1_8E084((void *)car, (void *)&total, i);
}
}
}
}
}
}
/* fzgx:end fn_1_8DD54 */

/* fzgx:begin fn_1_8E084 */
#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

// Slot to move to from `n` (the slot after the current one): 5 stays 5, out of

// range clamps, otherwise the first usable slot at or after n, -1 when none.

static inline s8 advance_slot(SlotCar *car, s32 n) {
    s8 next;

    if ((s8)n == 5) {
        return n;
    }
    if ((s8)n < 0 || (s8)n > 5) {
        return CLAMP((s8)n, 0, 5);
    }
    for (next = n; next < 5; next++) {
        if (car->slot_mask & (1 << next)) {
            return next;
        }
    }
    return -1;
}

void fn_1_8E084(SlotCar *car, s32 *value, s32 row) {
    s8 cur = car->slot;
    s32 slot;

    car->slot = advance_slot(car, cur + 1);

    slot = car->slot;
    if (slot == -1) {
        car->slot = 5;
        *value -= lbl_1_bss_6E82C[row][cur];
    } else {
        *value = *value - lbl_1_bss_6E82C[row][cur] + lbl_1_bss_6E82C[row][slot];
    }
}
/* fzgx:end fn_1_8E084 */

/* fzgx:begin fn_1_8E188 */
void fn_1_8E188(void) {
    if (lbl_1_bss_6E958.texture == 0) {
        lbl_1_bss_6E958.texture = fn_1_12AC00((u8 *)"init/storymdl.tpl");
        lbl_1_bss_6E958.list = (CarList *)fn_1_12ADA0("init/storymdl.gma", (void *)lbl_1_bss_6E958.texture);
    }
}
/* fzgx:end fn_1_8E188 */

/* fzgx:begin fn_1_8E1E8 */
// Releases both pending resource handles when the secondary handle is active.

void fn_1_8E1E8(void) {
    if (lbl_1_bss_6E958.texture != 0) {
        fn_80071718( (lbl_1_bss_6E958.texture));
        fn_800711A8((u32)lbl_1_bss_6E958.list);
        lbl_1_bss_6E958.texture = 0;
        lbl_1_bss_6E958.list = 0;
    }
}
/* fzgx:end fn_1_8E1E8 */

/* fzgx:begin fn_1_8E244 */
void fn_1_8E244(void *arg0) {
    Vec3 v = {0.0f, 1.5f, 1.0f};
    f32 s;

    if (lbl_1_bss_6E958.texture != 0) {
        lbl_8006DFE8(arg0);
        s = 0.5215686559677124f;
        psvec_scale(&v.x, s, &v.x);
        lbl_8006E0A4(&v);
        lbl_8006DAEC();
        {
            s16 i;
            for (i = 0; i < lbl_1_bss_6E958.list->count; i++) {
                lbl_8006DBE4();
                if (i) {
                    u32 *q = &lbl_801A66A0;
                    mathutil_mtxA_rotate_y((182.04444885253906f * (*q % 360)));
                }
                fn_80072558();
                fn_1_55210(lbl_1_bss_6E958.list->items[i].ptr);
            }
        }
        lbl_8006DC20();
    }
}
/* fzgx:end fn_1_8E244 */

/* fzgx:begin fn_1_8E3A4 */
void fn_1_8E3A4(fn_1_8E3A4_Object *obj) {
    u32 value;
    s8 color[4];

    if (lbl_1_bss_6D824 != 0) {
        value = lbl_1_bss_6D824->value;
        if (value != 0xffffffff) {
            if (obj->state->code == (u8)value) {
                u32 b0 = value >> 24;
                u32 b1 = (value >> 16) & 0xff;
                u32 b2 = (value >> 8) & 0xff;

                color[0] = b0;
                color[1] = b1;
                color[2] = b2;
                ((u8 *)color)[3] = 0xff;
                fn_80008BA8((u8 *)obj->state + 8, color, 4);
                fn_80008BA8((u8 *)obj->state + 4, color, 4);
            }
        }
    }
}
/* fzgx:end fn_1_8E3A4 */

/* fzgx:begin fn_1_8E448 */
void fn_1_8E448(GlobalObject *obj, u32 value) {
    obj->value = value;
}
#undef CLAMP
/* fzgx:end fn_1_8E448 */

/* fzgx:begin fn_1_8E450 */
void fn_1_8E450(u32 value) {
    lbl_1_bss_6D824 = (GlobalObject *)value;
    fn_80074A7C((u32)fn_1_8E3A4);
}
/* fzgx:end fn_1_8E450 */

/* fzgx:begin fn_1_8E480 */
void fn_1_8E480(void) {
    fn_80074A7C(0);
}
/* fzgx:end fn_1_8E480 */
