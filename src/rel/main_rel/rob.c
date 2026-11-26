#include "types.h"
#include "rel/main_rel/globals.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/vec3.h"
#include "game/pad.h"
#include "psvec.h"
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

/* fn_1_7F934 */
struct fn_1_7F954_lbl_1_bss_6D82C {
    u32 unk_0;
};

/* fn_1_7F934 */
struct fn_1_7FA04_lbl_1_bss_6D82C {
    u32 unk_0;
};

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
    u8 pad_4[0x60C];
    f32 unk_610;
    u8 unk_614;
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

/* fn_1_850C4 */
typedef struct Racer850C4 {
u32 flags;
u8 lap;
u8 pad5[0x1400];
u8 slotMask;
u8 pad1406[0x2];
Vec3 slots[5];
} Racer850C4;

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
void (*racerHook)(Racer850C4 *);
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
    u8 pad_000[0x1FC];
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

/* fn_1_875B4 */
typedef struct Fn1879B0Inner {
    u8 pad_000[0xA4];
    f32 value_A4;
    u8 pad_A8[0x154];
    f32 value_1FC;
} Fn1879B0Inner;

/* fn_1_875B4 */
typedef struct Fn1879B0Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x209];
    u8 field_20C[0x110];
    u8 field_31C[0x10];
    Fn1879B0Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1879B0Object;

/* fn_1_8901C */
typedef struct Fn8901CDriver {
    u32 flags;
    u8 pad_4[0x18a - 0x4];
    u8 unk_18a;
    u8 pad_18b[0x1fc - 0x18b];
    f32 unk_1fc;
} Fn8901CDriver;

/* fn_1_8901C */
typedef struct Fn8901CCar {
    u8 pad_0[0x2];
    s8 unk_2;
    u8 pad_3[0x208 - 0x3];
    Vec3 pos0;
    u8 pad_214[0x21c - 0x214];
    Vec3 pos1;
    u8 pad_228[0x230 - 0x228];
    Vec3 pos2;
    u8 pad_23c[0x32c - 0x23c];
    Fn8901CDriver *driver;
    u8 *mtx;
    u8 pad_334[0x3ba - 0x334];
    s16 unk_3ba;
} Fn8901CCar;

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
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    u8 pad_88[0x64];
    u8 unk_EC[0x3B0];
    Progress8B9B8 *unk_49C;
    u8 pad_4A0[0x180];
} Racer8B9B8;

/* fn_1_8B9B8 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x6];
    u8 unk_A;
    u8 unk_B;
    u8 pad_C[0x2];
    u8 unk_E[0x1E];
    Progress8B9B8 *unk_2C[30];
} Race8B9B8;

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

/* fn_1_8C40C */
struct fn_1_8C884_lbl_1_bss_6D838 {
    u32 unk_0;
};

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
    char *node;
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
    void *unk_BC[5];
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
typedef struct {
    u16 a[12];
} MotionParam97288;

typedef struct {
    u32 kind : 3;
    u32 volume : 29;
} Track97288;

typedef struct {
    u8 pad_0[0x24];
    void *names;
} MotionObj97288;

struct fn_1_97288_Arg0 {
    u8 pad_0[0x1A8];
    u16 unk_1A8;
    u8 pad_1AA[0x6];
    void *unk_1B0;
    void *unk_1B4;
    u8 pad_1B8[0x10];
    u16 motion;
    u8 pad_1CA[0x6];
    MotionObj97288 *obj;
    u8 pad_1D4[0x10];
    u32 unk_1E4;
    u8 pad_1E8[0x2A1];
    s8 start;
    s8 kind;
    s8 prevKind;
    s32 count;
    s32 length;
    f32 blend;
    f32 volume;
    f32 prevVolume;
    s32 index;
    u8 pad_4A4[0x8];
    s32 trackCount;
    Track97288 *track;
    char *name;
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
extern void GXLoadPosMtxImm(const void *, u32);
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
extern void fn_1_1502BC(void *, void *, void *);
extern void fn_1_150464(u32);
extern void fn_1_151BDC(BurnerBig *);
extern s32 fn_1_15578(Vec3 *, Vec3 *, f32 *, Vec3 *, u32, s32 *, s32, s32, s32, Car892FC *);
extern void fn_1_17920(s32, s32, f32);
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
typedef u16 (*Fn41F58Callback)(void *arg, void *entry);
extern void fn_1_41F58(void *data, s32 type, Fn41F58Callback callback, void *arg);
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
extern s32 fn_1_548EC(void *arg0);
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
extern u32 lbl_1_bss_6D828;
extern u32 lbl_1_bss_6D82C[3];
extern u32 lbl_1_bss_6D850;
extern u8 lbl_1_bss_6D854;
extern u32 lbl_1_bss_6D86C[34];
extern u32 lbl_1_bss_6D8F4[31];
extern u32 lbl_1_bss_6D970;
extern u32 lbl_1_bss_6D974;
extern u32 lbl_1_bss_6D978;
extern u32 lbl_1_bss_6D97C;
extern u8 lbl_1_bss_6D980[32];
extern u8 lbl_1_bss_6DA5C[30];
extern u8 lbl_1_bss_6DA80[1740];
extern u8 lbl_1_bss_6E160[1740];
extern u16 lbl_1_bss_6E82C[30][5];
extern u8 lbl_1_bss_8CA28;
extern s8 lbl_1_bss_9C;
extern struct fn_1_83858_lbl_1_bss_A88 lbl_1_bss_A88;
extern u32 lbl_1_bss_C70;
extern struct fn_1_83858_lbl_1_bss_CC0 lbl_1_bss_CC0;
extern Fn9012CPad lbl_1_bss_D58;
extern struct fn_1_83858_lbl_1_bss_D70 lbl_1_bss_D70;
extern u8 lbl_1_data_1F1D8[];
extern char *lbl_1_data_1F318[];
extern Obj_1_data_1FFE0 lbl_1_data_1FFE0;
extern u8 lbl_1_data_1FFF0[0xC];
extern char lbl_1_data_206D8[];
extern char lbl_1_data_20700[17];
extern char lbl_1_data_20894[];
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
extern f32 lbl_8006D188(u32);
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
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern u32 lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DC6C(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DF44(void);
extern void lbl_8006DFC4(void *);
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
extern void mathutil_mtxA_rotate_x(int value);
extern void mathutil_mtxA_rotate_y(int value);
extern void mathutil_mtxA_rotate_z(int value);
extern void *memcpy(void *, void *, u32);
extern void *memset(void *dst, int value, u32 size);
extern void qsort(void *, u32, u32, void *, void *);
extern int sprintf(char *, const char *, ...);
extern char *strcat(char *, const char *);
extern u32 strlen(const char *);
extern int strncmp(const char *, const char *, u32);
extern char *strncpy(char *, const char *, unsigned long);

void fn_1_7EB8C(Object *arg0);
void fn_1_7ECB8(void * arg0, u32 arg1, u32 arg2, f32 arg3);
void fn_1_7F1E8(void *arg0, u32 arg1, f32 arg2);
void fn_1_7F20C(void *arg0, u32 arg1, f32 arg2);
void fn_1_7F230(void *arg0, u32 arg1, f32 arg2);
void *fn_1_7F254(void *arg0, void *arg1);
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
void fn_1_850C4(Racer850C4 *racer);
void fn_1_854D4(void);
void fn_1_85688(void);
void fn_1_85878(void);
void fn_1_8589C(u32 value);
s32 fn_1_858A8(s16 *a, s16 *b);
void fn_1_85934(f32 arg);
void fn_1_85C58(s32 index, f32 arg1);
void fn_1_85F70(void);
void fn_1_85F90(void *obj, f32 a, f32 b, f32 c, f32 d, int mode);
void fn_1_8616C(void);
void fn_1_86194(void);
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
void fn_1_870BC(Car870BC *car, s32 a, s32 b, s16 c, u8 d, f32 x);
void fn_1_87238(struct fn_1_87238_Car *car, s8 index, f32 f1);
void fn_1_87448(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, int flag, f32 f);
void fn_1_875B4(void *arg, int value_1, int value_2, f32 value);
void fn_1_875EC(void *arg0, void *arg1, void *arg2);
void fn_1_87610(Fn187610Object *object, Fn187610Data *data);
void fn_1_87750(Fn187750Object *object);
void fn_1_877E8(Fn187750Object *object);
void fn_1_87880(Fn187750Object *object);
void fn_1_87918(Fn187750Object *object);
void fn_1_879B0(Fn1879B0Object *object);
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
void fn_1_8901C(Fn8901CCar *car);
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
u8 *fn_1_8C9F4(void);
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
void fn_1_8D1C8(u32 arg0, u32 arg1, u32 arg2);
void fn_1_8D1EC(u32 arg0, u32 arg1, u32 arg2);
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
void fn_1_8F45C(Fn1_8F45C_Object *obj, s32 idx, u32 mask, u32 mask2);
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
void fn_1_933D8(CarObject *arg0, EventObject *arg1, s32 arg2);
void fn_1_934CC(CarObject *arg0, EventObject *arg1, char *name);
void fn_1_935E4(Fn935E4Car *arg0, void *arg1, void *arg2, f32 arg3);
void fn_1_93734(CarObject_93734 *car, void *name);
void fn_1_943F8(CarObject_93734 *car, void *name, f32 blend);
s32 fn_1_950E8(Fn1950E8Data *data);
s32 fn_1_95120(Fn195120Owner *owner);
void fn_1_95158(Fn195158Car *car);
void fn_1_95210(void *arg0);
void fn_1_95238(u32 arg0, EventList_95158 *arg1);
void fn_1_9550C(Owner *owner, Config *config);
void fn_1_956B8(Fn1956B8Data *data);
void fn_1_956EC(s32 id, u32 mask);
void fn_1_95950(u32 arg0);
void fn_1_95EF0(void *arg0);
void fn_1_96130(void *arg0);
void fn_1_9617C(CarResourceState *car, void *resource);
void fn_1_961F0(Fn1961F0Owner *owner);
void fn_1_96230(Fn196230Obj *obj, s32 idx, u32 mask1, u32 mask2, s32 flag);
void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2);
void fn_1_96664(void *arg0, void *arg1, void *arg2);
void fn_1_966A0(Fn1966A0Object *object);
void fn_1_967A8(Fn1967A8Object *arg0, void *arg1);
void fn_1_968FC(Fn1968FCObject *object);
u16 fn_1_96968(void *arg, void *arg1);
u16 fn_1_969E8(void *arg, void *arg1);
u16 fn_1_96A68(void *arg, void *arg1);
u16 fn_1_96AE8(void *base, void *arg1);
u16 fn_1_96B14(void *base, void *arg1, s32 index);
u16 fn_1_96BC0(void *arg, void *arg1);
void fn_1_96C40(void *arg0);
void fn_1_96F20(CarData_96F20 *car);
s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2);
void fn_1_97204(void *arg0, void *arg1);
void fn_1_9724C(void *rob);
void fn_1_97288(struct fn_1_97288_Arg0 *arg0);
void fn_1_977BC(Rob *rob, RobView *arg1);
s16 fn_1_97F1C(Fn197F1CObject *object, s16 index);
u8 fn_1_97F80(Fn197F80Object *rob, const char *name);
s16 fn_1_98104(Fn198104Obj *obj);
s32 fn_1_9818C(u32 arg0);

/* lbl_1_bss_6EAD0 (sound/stcoli object, rel/main_rel/stcoli.h layout) */
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Obj_1_bss_6EAD0_At0;
typedef struct {
    Obj_1_bss_6EAD0_At0 *unk_0;
    u8 pad_4[0x704];
} Obj_1_bss_6EAD0;
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;

/* TU B .bss 6E960..6EA00 */
s32 lbl_1_bss_6E960 = 0;
s32 lbl_1_bss_6E964 = 0;
s32 lbl_1_bss_6E968 = 0;
s32 lbl_1_bss_6E96C = 0;
s32 lbl_1_bss_6E970 = 0;
s32 lbl_1_bss_6E974 = 0;
s32 lbl_1_bss_6E978 = 0;
s32 lbl_1_bss_6E97C = 0;
s32 lbl_1_bss_6E980 = 0;
s32 lbl_1_bss_6E984 = 0;
s16 lbl_1_bss_6E988 = 0;
u32 lbl_1_bss_6E98C = 0;
EventList lbl_1_bss_6E990;
/* TU B (retail rob.c) .data 209C0..27DE0, phase 1: every object in retail order (generated by gdata.py) */
char lbl_1_data_209C0[] = "GAZELLE";
char lbl_1_data_209C8[] = "JODY";
char lbl_1_data_209D0[] = "STEWART";
char lbl_1_data_209D8[] = "BABA";
char lbl_1_data_209E0[] = "GOROH";
char lbl_1_data_209E8[] = "PICO";
char lbl_1_data_209F0[] = "FALCON";
char lbl_1_data_209F8[] = "OCTMAN";
char lbl_1_data_20A00[] = "EAD";
char lbl_1_data_20A04[] = "JAMES";
char lbl_1_data_20A0C[] = "BILLY";
char lbl_1_data_20A14[] = "KATE";
char lbl_1_data_20A1C[] = "ZODA";
char lbl_1_data_20A24[] = "JACK";
char lbl_1_data_20A2C[] = "REX";
char lbl_1_data_20A30[] = "GORDON";
char lbl_1_data_20A38[] = "GUSTER";
char lbl_1_data_20A40[] = "BEASTMAN";
char lbl_1_data_20A4C[] = "LEON";
char lbl_1_data_20A54[] = "ARROW";
char lbl_1_data_20A5C[] = "MRS";
char lbl_1_data_20A60[] = "SHIO";
char lbl_1_data_20A68[] = "NEELSEN";
char lbl_1_data_20A70[] = "MICHAEL";
char lbl_1_data_20A78[] = "BLOOD";
char lbl_1_data_20A80[] = "TANAKA";
char lbl_1_data_20A88[] = "DRAQ";
char lbl_1_data_20A90[] = "ROGER";
char lbl_1_data_20A98[] = "CLASH";
char lbl_1_data_20AA0[] = "SHADOW";
char lbl_1_data_20AA8[] = "BOSS";
char lbl_1_data_20AB0[] = "DON";
char lbl_1_data_20AB4[] = "DIGIBOY";
char lbl_1_data_20ABC[] = "DAI";
char lbl_1_data_20AC0[] = "SPADE";
char lbl_1_data_20AC8[] = "DAIGOROH";
char lbl_1_data_20AD4[] = "PRISIA";
char lbl_1_data_20ADC[] = "LILY";
char lbl_1_data_20AE4[] = "PJ";
char lbl_1_data_20AE8[] = "QQQ";
char lbl_1_data_20AEC[] = "SHERLOCK";
char lbl_1_data_20AF8[] = "GOMA";
char lbl_1_data_20B00[] = "SAN";
char lbl_1_data_20B04[] = "GEN";
char lbl_1_data_20B08[] = "INTERVIEWER";
char *lbl_1_data_20B14[45] = { lbl_1_data_209C0, lbl_1_data_209C8, lbl_1_data_209D0, lbl_1_data_209D8, lbl_1_data_209E0, lbl_1_data_209E8, lbl_1_data_209F0, lbl_1_data_209F8, lbl_1_data_20A00, lbl_1_data_20A04, lbl_1_data_20A0C, lbl_1_data_20A14, lbl_1_data_20A1C, lbl_1_data_20A24, lbl_1_data_20A2C, lbl_1_data_20A30, lbl_1_data_20A38, lbl_1_data_20A40, lbl_1_data_20A4C, lbl_1_data_20A54, lbl_1_data_20A5C, lbl_1_data_20A60, lbl_1_data_20A68, lbl_1_data_20A70, lbl_1_data_20A78, lbl_1_data_20A80, lbl_1_data_20A88, lbl_1_data_20A90, lbl_1_data_20A98, lbl_1_data_20AA0, lbl_1_data_20AA8, lbl_1_data_20AB0, lbl_1_data_20AB4, lbl_1_data_20ABC, lbl_1_data_20AC0, lbl_1_data_20AC8, lbl_1_data_20AD4, lbl_1_data_20ADC, lbl_1_data_20AE4, lbl_1_data_20AE8, lbl_1_data_20AEC, lbl_1_data_20AF8, lbl_1_data_20B00, lbl_1_data_20B04, lbl_1_data_20B08 };
char lbl_1_data_20BC8[] = "gazelle";
char lbl_1_data_20BD0[] = "jody";
char lbl_1_data_20BD8[] = "stewart";
char lbl_1_data_20BE0[] = "baba";
char lbl_1_data_20BE8[] = "goroh";
char lbl_1_data_20BF0[] = "pico";
char lbl_1_data_20BF8[] = "falcon";
char lbl_1_data_20C00[] = "octman";
char lbl_1_data_20C08[] = "ead";
char lbl_1_data_20C0C[] = "james";
char lbl_1_data_20C14[] = "billy";
char lbl_1_data_20C1C[] = "kate";
char lbl_1_data_20C24[] = "zoda";
char lbl_1_data_20C2C[] = "jack";
char lbl_1_data_20C34[] = "rex";
char lbl_1_data_20C38[] = "gordon";
char lbl_1_data_20C40[] = "guster";
char lbl_1_data_20C48[] = "beastman";
char lbl_1_data_20C54[] = "leon";
char lbl_1_data_20C5C[] = "arrow";
char lbl_1_data_20C64[] = "mrs";
char lbl_1_data_20C68[] = "shio";
char lbl_1_data_20C70[] = "neelsen";
char lbl_1_data_20C78[] = "michael";
char lbl_1_data_20C80[] = "blood";
char lbl_1_data_20C88[] = "tanaka";
char lbl_1_data_20C90[] = "draq";
char lbl_1_data_20C98[] = "roger";
char lbl_1_data_20CA0[] = "clash";
char lbl_1_data_20CA8[] = "shadow";
char lbl_1_data_20CB0[] = "boss";
char lbl_1_data_20CB8[] = "don";
char lbl_1_data_20CBC[] = "digiboy";
char lbl_1_data_20CC4[] = "dai";
char lbl_1_data_20CC8[] = "spade";
char lbl_1_data_20CD0[] = "daigoroh";
char lbl_1_data_20CDC[] = "prisia";
char lbl_1_data_20CE4[] = "lily";
char lbl_1_data_20CEC[] = "pj";
char lbl_1_data_20CF0[] = "qqq";
char lbl_1_data_20CF4[] = "sherlock";
char lbl_1_data_20D00[] = "goma";
char lbl_1_data_20D08[] = "san";
char lbl_1_data_20D0C[] = "gen";
char lbl_1_data_20D10[] = "interviewer";
char *lbl_1_data_20D1C[45] = { lbl_1_data_20BC8, lbl_1_data_20BD0, lbl_1_data_20BD8, lbl_1_data_20BE0, lbl_1_data_20BE8, lbl_1_data_20BF0, lbl_1_data_20BF8, lbl_1_data_20C00, lbl_1_data_20C08, lbl_1_data_20C0C, lbl_1_data_20C14, lbl_1_data_20C1C, lbl_1_data_20C24, lbl_1_data_20C2C, lbl_1_data_20C34, lbl_1_data_20C38, lbl_1_data_20C40, lbl_1_data_20C48, lbl_1_data_20C54, lbl_1_data_20C5C, lbl_1_data_20C64, lbl_1_data_20C68, lbl_1_data_20C70, lbl_1_data_20C78, lbl_1_data_20C80, lbl_1_data_20C88, lbl_1_data_20C90, lbl_1_data_20C98, lbl_1_data_20CA0, lbl_1_data_20CA8, lbl_1_data_20CB0, lbl_1_data_20CB8, lbl_1_data_20CBC, lbl_1_data_20CC4, lbl_1_data_20CC8, lbl_1_data_20CD0, lbl_1_data_20CDC, lbl_1_data_20CE4, lbl_1_data_20CEC, lbl_1_data_20CF0, lbl_1_data_20CF4, lbl_1_data_20D00, lbl_1_data_20D08, lbl_1_data_20D0C, lbl_1_data_20D10 };
char lbl_1_data_20DD0[] = "\203}\203C\203e\203B\201[ \203K\203[\203\213";
char lbl_1_data_20DE4[] = "\203W\203\207\203f\203B \203T\203}\201[";
char lbl_1_data_20DF4[] = "\203h\203N\203^\201[ \203X\203`\203\205\203\217\201[\203g";
char lbl_1_data_20E0C[] = "\203o\203o";
char lbl_1_data_20E14[] = "\203T\203\200\203\211\203C \203S\203\215\201[";
char lbl_1_data_20E24[] = "\203s\203R";
char lbl_1_data_20E2C[] = "\203L\203\203\203v\203e\203\223 \203t\203@\203\213\203R\203\223";
char lbl_1_data_20E44[] = "\203I\203N\203g\203}\203\223";
char lbl_1_data_20E50[] = "\203~\203X\203^\201[ \203C\201[\201E\203G\203C\201E\203f\203B";
char lbl_1_data_20E6C[] = "\203W\203F\201[\203\200\203Y \203}\203N\203\211\203E\203h";
char lbl_1_data_20E84[] = "\203r\203\212\201[";
char lbl_1_data_20E8C[] = "\203P\203C\203g \203A\203\214\203\223";
char lbl_1_data_20E9C[] = "\203]\201[\203_";
char lbl_1_data_20EA4[] = "\203W\203\203\203b\203N \203\214\203r\203\223";
char lbl_1_data_20EB4[] = "\203o\203C\203I \203\214\203b\203N\203X";
char lbl_1_data_20EC4[] = "\203U \203X\203J\203\213";
char lbl_1_data_20ED0[] = "\203A\203\223\203g\203j\203I \203K\203X\203^\201[";
char lbl_1_data_20EE4[] = "\203r\201[\203X\203g\203}\203\223";
char lbl_1_data_20EF4[] = "\203\214\203I\203\223";
char lbl_1_data_20EFC[] = "\203X\201[\203p\201[ \203A\203\215\201[";
char lbl_1_data_20F0C[] = "\203~\203Z\203X \203A\203\215\201[";
char lbl_1_data_20F1C[] = "\203S\203}\201[\201\225\203V\203I\201[";
char lbl_1_data_20F2C[] = "\203V\203\213\203o\201[ \203j\201[\203\213\203Z\203\223";
char lbl_1_data_20F40[] = "\203}\203C\203P\203\213 \203`\203F\201[\203\223";
char lbl_1_data_20F54[] = "\203u\203\211\203b\203h \203t\203@\203\213\203R\203\223";
char lbl_1_data_20F68[] = "\203W\203\207\203\223 \203^\203i\203J";
char lbl_1_data_20F78[] = "\203h\203\211\203N";
char lbl_1_data_20F80[] = "\203\215\203W\203\203\201[ \203o\203X\203^\201[";
char lbl_1_data_20F94[] = "\203h\203N\203^\201[ \203N\203\211\203b\203V\203\205";
char lbl_1_data_20FA8[] = "\203u\203\211\203b\203N \203V\203\203\203h\201[";
char lbl_1_data_20FBC[] = "\203f\203X\203{\201[\203\223";
char lbl_1_data_20FC8[] = "\203h\203\223 \203W\201[\203j\201[";
char lbl_1_data_20FD8[] = "\203f\203W \203{\201[\203C";
char lbl_1_data_20FE4[] = "\203_\203C\201E\203T\203\223\201E\203Q\203\223";
char lbl_1_data_20FF8[] = "\203X\203y\201[\203h";
char lbl_1_data_21004[] = "\203_\203C\203S\203\215\201[";
char lbl_1_data_21010[] = "\203v\203\212\203\223\203V\203A";
char lbl_1_data_2101C[] = "\203\212\203\212\201[";
char lbl_1_data_21024[] = "\203s\201[\203W\203F\203C";
char lbl_1_data_21030[] = "\203L\203\205\201[\203X\203\212\201[";
char lbl_1_data_21040[] = "\203t\203F\203j\203b\203N\203X";
char lbl_1_data_21050[] = "\203S\203}\201[";
char lbl_1_data_21058[] = "\203T\203\223";
char lbl_1_data_21060[] = "\203Q\203\223";
char lbl_1_data_21068[] = "\203C\203\223\203^\203r\203\205\203\217\201[";
char *lbl_1_data_21078[45] = { lbl_1_data_20DD0, lbl_1_data_20DE4, lbl_1_data_20DF4, lbl_1_data_20E0C, lbl_1_data_20E14, lbl_1_data_20E24, lbl_1_data_20E2C, lbl_1_data_20E44, lbl_1_data_20E50, lbl_1_data_20E6C, lbl_1_data_20E84, lbl_1_data_20E8C, lbl_1_data_20E9C, lbl_1_data_20EA4, lbl_1_data_20EB4, lbl_1_data_20EC4, lbl_1_data_20ED0, lbl_1_data_20EE4, lbl_1_data_20EF4, lbl_1_data_20EFC, lbl_1_data_20F0C, lbl_1_data_20F1C, lbl_1_data_20F2C, lbl_1_data_20F40, lbl_1_data_20F54, lbl_1_data_20F68, lbl_1_data_20F78, lbl_1_data_20F80, lbl_1_data_20F94, lbl_1_data_20FA8, lbl_1_data_20FBC, lbl_1_data_20FC8, lbl_1_data_20FD8, lbl_1_data_20FE4, lbl_1_data_20FF8, lbl_1_data_21004, lbl_1_data_21010, lbl_1_data_2101C, lbl_1_data_21024, lbl_1_data_21030, lbl_1_data_21040, lbl_1_data_21050, lbl_1_data_21058, lbl_1_data_21060, lbl_1_data_21068 };
char lbl_1_data_2112C[] = "MIGHTY GAZELLE";
char lbl_1_data_2113C[] = "JODY SUMMER";
char lbl_1_data_21148[] = "Dr. STEWART";
char lbl_1_data_21154[] = "SAMURAI GOROH";
char lbl_1_data_21164[] = "CAPTAIN FALCON";
char lbl_1_data_21174[] = "OCTOMAN";
char lbl_1_data_2117C[] = "Mr. EAD";
char lbl_1_data_21184[] = "JAMES McCLOUD";
char lbl_1_data_21194[] = "KATE ALEN";
char lbl_1_data_211A0[] = "JACK LEVIN";
char lbl_1_data_211AC[] = "BIO REX";
char lbl_1_data_211B4[] = "THE SKULL";
char lbl_1_data_211C0[] = "ANTONIO GUSTER";
char lbl_1_data_211D0[] = "SUPER ARROW";
char lbl_1_data_211DC[] = "Mrs. ARROW";
char lbl_1_data_211E8[] = "GOMAR & SHIOH";
char lbl_1_data_211F8[] = "SILVER NEELSEN";
char lbl_1_data_21208[] = "MICHAEL CHAIN";
char lbl_1_data_21218[] = "BLOOD FALCON";
char lbl_1_data_21228[] = "JOHN TANAKA";
char lbl_1_data_21234[] = "ROGER BUSTER";
char lbl_1_data_21244[] = "Dr. CLASH";
char lbl_1_data_21250[] = "BLACK SHADOW";
char lbl_1_data_21260[] = "DEATHBORN";
char lbl_1_data_2126C[] = "DON GENIE";
char lbl_1_data_21278[] = "DIGI-BOY";
char lbl_1_data_21284[] = "DAI SAN GEN";
char lbl_1_data_21290[] = "PRINCIA";
char lbl_1_data_21298[] = "PHOENIX";
char lbl_1_data_212A0[] = "GOMAR";
char *lbl_1_data_212A8[45] = { lbl_1_data_2112C, lbl_1_data_2113C, lbl_1_data_21148, lbl_1_data_209D8, lbl_1_data_21154, lbl_1_data_209E8, lbl_1_data_21164, lbl_1_data_21174, lbl_1_data_2117C, lbl_1_data_21184, lbl_1_data_20A0C, lbl_1_data_21194, lbl_1_data_20A1C, lbl_1_data_211A0, lbl_1_data_211AC, lbl_1_data_211B4, lbl_1_data_211C0, lbl_1_data_20A40, lbl_1_data_20A4C, lbl_1_data_211D0, lbl_1_data_211DC, lbl_1_data_211E8, lbl_1_data_211F8, lbl_1_data_21208, lbl_1_data_21218, lbl_1_data_21228, lbl_1_data_20A88, lbl_1_data_21234, lbl_1_data_21244, lbl_1_data_21250, lbl_1_data_21260, lbl_1_data_2126C, lbl_1_data_21278, lbl_1_data_21284, lbl_1_data_20AC0, lbl_1_data_20AC8, lbl_1_data_21290, lbl_1_data_20ADC, lbl_1_data_20AE4, lbl_1_data_20AE8, lbl_1_data_21298, lbl_1_data_212A0, lbl_1_data_20B00, lbl_1_data_20B04, lbl_1_data_20B08 };
u32 lbl_1_data_2135C[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21384[5] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E1D, 0x1E1F2021 };
char lbl_1_data_21398[] = "\"#$'(+,";
u32 lbl_1_data_213A0[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_213B0[5] = { 0x205080B, 0xE0F1113, 0x14161B1E, 0x22232425, 0x292A2B2C };
u32 lbl_1_data_213C4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_213D4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_213E4[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_213EC[10] = { 0x1030506, 0x7080B0C, 0xD101718, 0x1A1B1213, 0x15160000, 0x1030506, 0x7080B0C, 0xD101718, 0x1A1B1213, 0x15160000 };
u32 lbl_1_data_21414[5] = { 0x10304, 0x5070809, 0xA0C0D0E, 0x1011121D, 0x1E1F2021 };
char lbl_1_data_21428[] = "\"#$&'()*+,-";
u32 lbl_1_data_21434[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21444[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21454[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21464[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_2146C[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21494[5] = { 0x10304, 0x5070809, 0xA101112, 0xC0D0E1D, 0x1E1F2021 };
char lbl_1_data_214A8[] = "\"#$&'()*+,-";
u32 lbl_1_data_214B4[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_214C4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_214D4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_214E4[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_214EC[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21514[10] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x1011121D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D19, 0x1A1B1516, 0x17000000 };
u32 lbl_1_data_2153C[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_2154C[4] = { 0x1050708, 0xA0C0D0F, 0x1017181A, 0x12131500 };
u32 lbl_1_data_2155C[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_2156C[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21574[10] = { 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_2159C[7] = { 0x10304, 0x5070809, 0xA101112, 0xC0D0E2B, 0x2C272822, 0x23241E1F, 0x20000000 };
u32 lbl_1_data_215B8[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_215C8[4] = { 0x1030507, 0x80A0C0D, 0xF101213, 0x1517181A };
u32 lbl_1_data_215D8[4] = { 0x10121315, 0x17181A01, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_215E8[2] = { 0x1030507, 0x80C0D10 };
u32 lbl_1_data_215F0[10] = { 0x10B0C0D, 0x6070805, 0x10121315, 0x1617181A, 0x1B000000, 0x10B0C0D, 0x6070805, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_21618[4] = { 0x1E1F20, 0x2223242C, 0x2813191A, 0x1B151617 };
u32 lbl_1_data_21628[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21638[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0305 };
u32 lbl_1_data_21648[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0305 };
u32 lbl_1_data_21658[2] = { 0x10010C0D, 0x7080305 };
u32 lbl_1_data_21660[18] = { 0x10B0C0D, 0x5060708, 0x1D1E2025, 0x26212223, 0x2428292B, 0x2E2F2C2D, 0x30311012, 0x13151617, 0x181A1B00, 0x10B0C0D, 0x5060708, 0x1D1E2025, 0x26212223, 0x2428292B, 0x2E2F2C2D, 0x30311012, 0x13151617, 0x181A1B00 };
u32 lbl_1_data_216A8[6] = { 0x10304, 0x5070809, 0xA0C0D0E, 0x10111219, 0x1A1B1516, 0x17000000 };
u32 lbl_1_data_216C0[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_216D0[5] = { 0x10121315, 0x17181A01, 0xC0D0F05, 0x7080A1D, 0x1E282900 };
u32 lbl_1_data_216E4[5] = { 0x10121315, 0x17181A01, 0xC0D0F05, 0x7080A1D, 0x1E282900 };
u32 lbl_1_data_216F8[2] = { 0x10010C0D, 0x5070800 };
u32 lbl_1_data_21700[10] = { 0x103050B, 0xC0D0607, 0x8101213, 0x15161718, 0x1A1B0000, 0x103050B, 0xC0D0607, 0x8101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_21728[9] = { 0x10304, 0x5070809, 0x1011120C, 0xD0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000 };
u32 lbl_1_data_2174C[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_2175C[4] = { 0x10121315, 0x17181A01, 0x3050C0D, 0x7080000 };
u32 lbl_1_data_2176C[4] = { 0xF1001, 0x2030405, 0x6070809, 0xA0B0C00 };
u32 lbl_1_data_2177C[4] = { 0x103050C, 0xD0F0708, 0xA101213, 0x1517181A };
u32 lbl_1_data_2178C[3] = { 0x1050C0D, 0x7081012, 0x17000000 };
u32 lbl_1_data_21798[10] = { 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000, 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_217C0[6] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111219, 0x1A1B1516, 0x171D1E1F };
char lbl_1_data_217D8[] = " !\"#$&'()*+,-/0";
u32 lbl_1_data_217E8[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_217F8[1] = { 0x1000000 };
u32 lbl_1_data_217FC[5] = { 0x10121315, 0x1617181A, 0x1B01050C, 0xD0F0708, 0xA000000 };
u32 lbl_1_data_21810[5] = { 0x10121315, 0x1617181A, 0x1B01050C, 0xD0E0708, 0x9000000 };
u32 lbl_1_data_21824[3] = { 0x10121701, 0x50C0D07, 0x8000000 };
u32 lbl_1_data_21830[12] = { 0x1060708, 0xB0C0D03, 0x5101213, 0x15161D1E, 0x2017181A, 0x1B000000, 0x1060708, 0xB0C0D03, 0x5101213, 0x15161D1E, 0x2017181A, 0x1B000000 };
u32 lbl_1_data_21860[6] = { 0x10304, 0x5070809, 0xA101112, 0xC0D0E15, 0x1617191A, 0x1B000000 };
u32 lbl_1_data_21878[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21888[5] = { 0x107080A, 0xC0D0F05, 0x10121315, 0x1D1E1F17, 0x181A0000 };
u32 lbl_1_data_2189C[5] = { 0x107080A, 0xC0D0F05, 0x10121315, 0x1D1E1F17, 0x181A0000 };
u32 lbl_1_data_218B0[2] = { 0x107080C, 0xD051000 };
u32 lbl_1_data_218B8[8] = { 0x1060708, 0xB0C0D10, 0x12131516, 0x17181A1B, 0x1060708, 0xB0C0D10, 0x12131516, 0x17181A1B };
u32 lbl_1_data_218D8[10] = { 0x10304, 0x5070809, 0xA0C0D0E, 0x1011121D, 0x1E1F2021, 0x2223242A, 0x2B2C2D26, 0x27282919, 0x1A1B1516, 0x17000000 };
u32 lbl_1_data_21900[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21910[1] = { 0x1000000 };
u32 lbl_1_data_21914[4] = { 0x1050708, 0xA0C0D0F, 0x10121315, 0x17181A00 };
u32 lbl_1_data_21924[4] = { 0x1050708, 0xA0C0D0F, 0x10121315, 0x17181A00 };
u32 lbl_1_data_21934[2] = { 0x1050708, 0xC0D1000 };
u32 lbl_1_data_2193C[4] = { 0x1050708, 0xC0D1017, 0x181A1B12, 0x1315161D };
u32 lbl_1_data_2194C[5] = { 0x20210000, 0x1050708, 0xC0D1017, 0x181A1B12, 0x1315161D };
char lbl_1_data_21960[] = " !";
u32 lbl_1_data_21964[5] = { 0x10304, 0x5070809, 0xC0D0E10, 0x11121D1E, 0x1F202122 };
u32 lbl_1_data_21978[2] = { 0x23242728, 0x292B2C2D };
u32 lbl_1_data_21980[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21990[5] = { 0x1017181A, 0x1213151D, 0x20010305, 0x7080A0C, 0xD0F0000 };
u32 lbl_1_data_219A4[5] = { 0x1017181A, 0x1213151D, 0x20010305, 0x7080A0C, 0xD0F0000 };
u32 lbl_1_data_219B8[2] = { 0x10010507, 0x80A0C0D };
u32 lbl_1_data_219C0[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_219E8[6] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111215, 0x1617191A, 0x1B1E1F20 };
char lbl_1_data_21A00[] = "\"#$";
u32 lbl_1_data_21A04[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21A14[4] = { 0x1017181A, 0x12131501, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_21A24[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21A34[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21A3C[10] = { 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_21A64[7] = { 0x10304, 0x5070809, 0xA101112, 0xC0D0E2B, 0x2C2D2728, 0x29222324, 0x1E1F2000 };
u32 lbl_1_data_21A80[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21A90[4] = { 0x10121315, 0x17181A01, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_21AA0[4] = { 0x10121315, 0x17181A01, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_21AB0[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21AB8[8] = { 0x1060708, 0xB0C0D10, 0x17181A1B, 0x12131516, 0x1060708, 0xB0C0D10, 0x17181A1B, 0x12131516 };
u32 lbl_1_data_21AD8[1] = { 0x2F3000 };
u32 lbl_1_data_21ADC[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21AEC[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21AFC[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21B0C[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21B14[10] = { 0x103050B, 0xC0D0607, 0x8101213, 0x15161718, 0x1A1B0000, 0x103050B, 0xC0D0607, 0x8101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_21B3C[9] = { 0x10304, 0x5070809, 0x1011120C, 0xD0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000 };
u32 lbl_1_data_21B60[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21B70[4] = { 0x10121315, 0x17181A01, 0x3050C0D, 0x7080000 };
u32 lbl_1_data_21B80[4] = { 0xF1001, 0x2030405, 0x6070809, 0xA0B0C00 };
u32 lbl_1_data_21B90[4] = { 0x103050C, 0xD0F0708, 0xA101213, 0x1517181A };
u32 lbl_1_data_21BA0[3] = { 0x1050C0D, 0x7081012, 0x17000000 };
u32 lbl_1_data_21BAC[10] = { 0x1050B0C, 0xD060708, 0x1017181A, 0x1B121315, 0x16000000, 0x1050B0C, 0xD060708, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21BD4[7] = { 0x101112, 0xC0D0E01, 0x3040507, 0x8092B2C, 0x2D272829, 0x2223241E, 0x1F200000 };
u32 lbl_1_data_21BF0[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21C00[4] = { 0x103050C, 0xD070810, 0x17181A12, 0x13150000 };
u32 lbl_1_data_21C10[4] = { 0xF1001, 0x2030405, 0x6070809, 0xA0B0C00 };
u32 lbl_1_data_21C20[4] = { 0x103050C, 0xD0F0708, 0xA101718, 0x1A121315 };
u32 lbl_1_data_21C30[2] = { 0x1050C0D, 0x7081000 };
u32 lbl_1_data_21C38[10] = { 0x1030507, 0x80A0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1030507, 0x80A0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21C60[6] = { 0x10708, 0x9030405, 0xA0F1011, 0x120B0C0D, 0xE13191A, 0x1B151617 };
char lbl_1_data_21C78[] = "/0";
u32 lbl_1_data_21C7C[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21C8C[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21C9C[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21CAC[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21CB4[10] = { 0x10B0C0D, 0x6070803, 0x5101213, 0x15161718, 0x1A1B0000, 0x10B0C0D, 0x6070803, 0x5101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_21CDC[6] = { 0x10304, 0x5070809, 0xA0C0D0E, 0x10111213, 0x15161719, 0x1A1B0000 };
u32 lbl_1_data_21CF4[5] = { 0xD0E0F, 0x10010203, 0x4050607, 0x8090A0B, 0xC000000 };
u32 lbl_1_data_21D08[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0305 };
u32 lbl_1_data_21D18[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0305 };
u32 lbl_1_data_21D28[2] = { 0x10010C0D, 0x7080500 };
u32 lbl_1_data_21D30[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21D58[6] = { 0x10304, 0x5070809, 0xA101112, 0xC0D0E19, 0x1A1B1516, 0x17000000 };
u32 lbl_1_data_21D70[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21D80[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21D90[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21DA0[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21DA8[5] = { 0x1030506, 0x7080B0C, 0xD101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_21DBC[5] = { 0x10708, 0x9030405, 0xA0F1011, 0x120B0C0D, 0xE000000 };
u32 lbl_1_data_21DD0[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21DE0[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21DF0[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21E00[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21E08[10] = { 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000, 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_21E30[7] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111219, 0x1A1B1516, 0x172F3022, 0x23241E1F };
char lbl_1_data_21E4C[] = " +,-'()";
u32 lbl_1_data_21E54[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21E64[4] = { 0x10121315, 0x17181A01, 0x3050C0D, 0xF07080A };
u32 lbl_1_data_21E74[4] = { 0x10121315, 0x17181A01, 0x3050C0D, 0xF07080A };
u32 lbl_1_data_21E84[2] = { 0x10010305, 0xC0D0708 };
u32 lbl_1_data_21E8C[10] = { 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_21EB4[6] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E15, 0x1617191A, 0x1B000000 };
u32 lbl_1_data_21ECC[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21EDC[4] = { 0x10121315, 0x17181A01, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_21EEC[4] = { 0x10121315, 0x17181A01, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_21EFC[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_21F04[10] = { 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000, 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_21F2C[6] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111219, 0x1A1B1516, 0x171E1F20 };
char lbl_1_data_21F44[] = "\"#$'()+,-0/";
u32 lbl_1_data_21F50[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21F60[4] = { 0x10121315, 0x17181A01, 0x50C0D0F, 0x7080A00 };
u32 lbl_1_data_21F70[4] = { 0x10121315, 0x17181A01, 0x50C0D0F, 0x7080A00 };
u32 lbl_1_data_21F80[2] = { 0x1001050C, 0xD070800 };
u32 lbl_1_data_21F88[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_21FB0[7] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111213, 0x15161719, 0x1A1B2F30, 0x1E1F2022 };
u32 lbl_1_data_21FCC[2] = { 0x23242728, 0x292B2C2D };
u32 lbl_1_data_21FD4[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_21FE4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_21FF4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22004[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_2200C[12] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x24000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x24000000 };
u32 lbl_1_data_2203C[6] = { 0x10809, 0x304050A, 0xC0D0E10, 0x11122F30, 0x2223241E, 0x1F202B2C };
char lbl_1_data_22054[] = "-'(";
u32 lbl_1_data_22058[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_22068[5] = { 0x1017181A, 0x1D202324, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_2207C[5] = { 0x1017181A, 0x1D202324, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22090[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_22098[10] = { 0x1060708, 0xB0C0D03, 0x5101213, 0x15161718, 0x1A1B0000, 0x1060708, 0xB0C0D03, 0x5101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_220C0[10] = { 0x10708, 0x9030405, 0x2F302B2C, 0x2D272829, 0x15161719, 0x1A1B0A0F, 0x1011120B, 0xC0D0E21, 0x2223241D, 0x1E1F2000 };
u32 lbl_1_data_220E8[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_220F8[4] = { 0x10121315, 0x17181A01, 0x7080A0C, 0xD0F0500 };
u32 lbl_1_data_22108[4] = { 0x10121315, 0x17181A01, 0x7080A0C, 0xD0F0500 };
u32 lbl_1_data_22118[2] = { 0x10010708, 0xC0D0500 };
u32 lbl_1_data_22120[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_22148[6] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111215, 0x1617191A, 0x1B000000 };
u32 lbl_1_data_22160[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_22170[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22180[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22190[2] = { 0x1050708, 0xC0D1000 };
u32 lbl_1_data_22198[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_221C0[7] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111215, 0x1617191A, 0x1B2F301E, 0x1F202223 };
char lbl_1_data_221DC[] = "$'()+,-";
u32 lbl_1_data_221E4[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_221F4[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22204[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22214[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_2221C[10] = { 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x1050607, 0x80B0C0D, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_22244[8] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E13, 0x191A1B15, 0x16172122, 0x23241D1E, 0x1F200000 };
u32 lbl_1_data_22264[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_22274[1] = { 0x1000000 };
u32 lbl_1_data_22278[4] = { 0x10121315, 0x17181A01, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22288[4] = { 0x10121315, 0x17181A01, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22298[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_222A0[13] = { 0x1017181A, 0x1B121315, 0x162B2E2F, 0x26292A01, 0xC0D0F07, 0x80A1C1F, 0x20212425, 0x1017181A, 0x1B121315, 0x162B2E2F, 0x26292A01, 0xC0D0F07, 0x80A1C1F };
u32 lbl_1_data_222D4[1] = { 0x20212425 };
u32 lbl_1_data_222D8[4] = { 0x30405, 0x708090C, 0xD0E1011, 0x121E1F20 };
char lbl_1_data_222E8[] = "\"#$+,-'()";
u32 lbl_1_data_222F4[6] = { 0x10C0D0F, 0x7080A05, 0x1C1F2021, 0x24251017, 0x181A1213, 0x152B2E2F };
char lbl_1_data_2230C[] = "&)*";
u32 lbl_1_data_22310[6] = { 0x10C0D0F, 0x7080A05, 0x1C1F2021, 0x24251017, 0x181A1213, 0x152B2E2F };
char lbl_1_data_22328[] = "&)*";
u32 lbl_1_data_2232C[2] = { 0x10C0D07, 0x8051000 };
u32 lbl_1_data_22334[10] = { 0x10B0C0D, 0x6070803, 0x5101213, 0x15161718, 0x1A1B0000, 0x10B0C0D, 0x6070803, 0x5101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_2235C[1] = { 0x10A00 };
u32 lbl_1_data_22360[5] = { 0xD0E0F, 0x10010203, 0x4050607, 0x8090A0B, 0xC000000 };
u32 lbl_1_data_22374[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0500 };
u32 lbl_1_data_22384[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0500 };
u32 lbl_1_data_22394[3] = { 0x10121701, 0xC0D0708, 0x5000000 };
u32 lbl_1_data_223A0[5] = { 0x1060708, 0xB0C0D05, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_223B4[6] = { 0x1000000, 0x1060708, 0xB0C0D05, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_223CC[1] = { 0x10A00 };
u32 lbl_1_data_223D0[3] = { 0xE0F10, 0x405060A, 0xB0C0000 };
u32 lbl_1_data_223DC[4] = { 0x107080A, 0xC0D0F05, 0x10121315, 0x17181A00 };
u32 lbl_1_data_223EC[4] = { 0x107080A, 0xC0D0F05, 0x10121315, 0x17181A00 };
u32 lbl_1_data_223FC[2] = { 0x107080C, 0xD051000 };
u32 lbl_1_data_22404[10] = { 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000, 0x1050B0C, 0xD060708, 0x10121315, 0x1617181A, 0x1B000000 };
u32 lbl_1_data_2242C[7] = { 0x10304, 0x5070809, 0xA101112, 0xC0D0E15, 0x1617191A, 0x1B222324, 0x1D1E1F20 };
char lbl_1_data_22448[] = "*+,-&'()0/";
u32 lbl_1_data_22454[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_22464[4] = { 0x1050C0D, 0xF07080A, 0x10121315, 0x17181A00 };
u32 lbl_1_data_22474[4] = { 0x1050C0D, 0xF07080A, 0x10121315, 0x17181A00 };
u32 lbl_1_data_22484[2] = { 0x1001050C, 0xD070800 };
u32 lbl_1_data_2248C[8] = { 0x1030708, 0xC0D1017, 0x181A1B12, 0x13151600, 0x1030708, 0xC0D1017, 0x181A1B12, 0x13151600 };
u32 lbl_1_data_224AC[2] = { 0x1120E, 0x2E000000 };
u32 lbl_1_data_224B4[1] = { 0xE0A00 };
u32 lbl_1_data_224B8[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_224C8[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_224D8[3] = { 0x10171201, 0x5070809, 0xC0D0E00 };
u32 lbl_1_data_224E4[12] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x26000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x26000000 };
u32 lbl_1_data_22514[3] = { 0x10A0C, 0xD0E1011, 0x12000000 };
u32 lbl_1_data_22520[2] = { 0xE0F04, 0x50A0B0C };
u32 lbl_1_data_22528[5] = { 0x1017181A, 0x1213151D, 0x20232601, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_2253C[5] = { 0x1017181A, 0x1213151D, 0x20232601, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22550[3] = { 0x101D2023, 0x1050708, 0xC0D0000 };
u32 lbl_1_data_2255C[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_22584[10] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E2F, 0x301D1E1F, 0x20212223, 0x24262728, 0x292A2B2C, 0x2D191A1B, 0x15161700 };
u32 lbl_1_data_225AC[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_225BC[4] = { 0x1050708, 0xA0C0D0F, 0x1017181A, 0x12131500 };
u32 lbl_1_data_225CC[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_225DC[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_225E4[10] = { 0x103050B, 0xC0D0607, 0x8101213, 0x15161718, 0x1A1B0000, 0x103050B, 0xC0D0607, 0x8101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_2260C[9] = { 0x10304, 0x5070809, 0x1011120C, 0xD0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000 };
u32 lbl_1_data_22630[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_22640[4] = { 0x10121315, 0x17181A01, 0x3050C0D, 0x7080000 };
u32 lbl_1_data_22650[4] = { 0xF1001, 0x2030405, 0x6070809, 0xA0B0C00 };
u32 lbl_1_data_22660[4] = { 0x103050C, 0xD0F0708, 0xA101213, 0x1517181A };
u32 lbl_1_data_22670[3] = { 0x1050C0D, 0x7081012, 0x17000000 };
u32 lbl_1_data_2267C[10] = { 0x10B0C0D, 0x6070805, 0x1017181A, 0x1B121315, 0x16000000, 0x10B0C0D, 0x6070805, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_226A4[5] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E22, 0x23241E1F };
char lbl_1_data_226B8[] = " '()+,-";
u32 lbl_1_data_226C0[5] = { 0xD0E0F, 0x10010203, 0x4050607, 0x8090A0B, 0xC000000 };
u32 lbl_1_data_226D4[4] = { 0x1017181A, 0x12131501, 0xC0D0F07, 0x80A0500 };
u32 lbl_1_data_226E4[4] = { 0x10C0D0F, 0x7080A05, 0x1017181A, 0x12131500 };
u32 lbl_1_data_226F4[2] = { 0x10C0D07, 0x8051000 };
u32 lbl_1_data_226FC[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_22724[7] = { 0x10708, 0x9030405, 0xA0C0D0E, 0x10111226, 0x2728292A, 0x2B2C2D1D, 0x1E1F2021 };
char lbl_1_data_22740[] = "\"#$";
u32 lbl_1_data_22744[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_22754[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22764[4] = { 0x1017181A, 0x12131501, 0x507080A, 0xC0D0F00 };
u32 lbl_1_data_22774[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_2277C[10] = { 0x1060708, 0x50B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1060708, 0x50B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_227A4[6] = { 0xF1011, 0x120B0C0D, 0xE010304, 0x5070809, 0x2223241E, 0x1F202B2C };
u32 lbl_1_data_227BC[1] = { 0x2D272829 };
u32 lbl_1_data_227C0[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_227D0[4] = { 0x1070803, 0x50C0D10, 0x17181A12, 0x13150000 };
u32 lbl_1_data_227E0[4] = { 0xF1001, 0x2030405, 0x6070809, 0xA0B0C00 };
u32 lbl_1_data_227F0[4] = { 0x107080A, 0x3050C0D, 0xF101718, 0x1A121315 };
u32 lbl_1_data_22800[2] = { 0x1070803, 0x50C0D10 };
u32 lbl_1_data_22808[5] = { 0x10B0C0D, 0x3050607, 0x8101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_2281C[6] = { 0x1000000, 0x10B0C0D, 0x3050607, 0x8101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_22834[4] = { 0x191A1B, 0x15161727, 0x28292B2C, 0x2D1E1F20 };
char lbl_1_data_22844[] = "\"#$.0/";
u32 lbl_1_data_2284C[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_2285C[4] = { 0x10121315, 0x17181A01, 0xC0D0F03, 0x507080A };
u32 lbl_1_data_2286C[4] = { 0x10121315, 0x17181A01, 0xC0D0F03, 0x507080A };
u32 lbl_1_data_2287C[2] = { 0x10010C0D, 0x5070800 };
u32 lbl_1_data_22884[10] = { 0x10B0C0D, 0x6070803, 0x5101213, 0x15161718, 0x1A1B0000, 0x10B0C0D, 0x6070803, 0x5101213, 0x15161718, 0x1A1B0000 };
u32 lbl_1_data_228AC[8] = { 0x10304, 0x5070809, 0xA0C0D0E, 0x10111214, 0x15161718, 0x191A1B21, 0x2223241D, 0x1E1F2000 };
u32 lbl_1_data_228CC[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_228DC[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0500 };
u32 lbl_1_data_228EC[4] = { 0x10121315, 0x17181A01, 0xC0D0F07, 0x80A0500 };
u32 lbl_1_data_228FC[2] = { 0x10010C0D, 0x7080500 };
u32 lbl_1_data_22904[10] = { 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x1050607, 0x80B0C0D, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_2292C[7] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E13, 0x191A1B15, 0x16171D1E, 0x1F202122 };
char lbl_1_data_22948[] = "#$";
u32 lbl_1_data_2294C[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_2295C[2] = { 0x20B0C06, 0x7000000 };
u32 lbl_1_data_22964[4] = { 0x1017181A, 0x12131501, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_22974[4] = { 0x1017181A, 0x12131501, 0x3050708, 0xA0C0D0F };
u32 lbl_1_data_22984[2] = { 0x10010507, 0x80C0D00 };
u32 lbl_1_data_2298C[10] = { 0x10B0C0D, 0x6070805, 0x1017181A, 0x1B121315, 0x16000000, 0x10B0C0D, 0x6070805, 0x1017181A, 0x1B121315, 0x16000000 };
u32 lbl_1_data_229B4[9] = { 0x10708, 0x9030405, 0xA101112, 0xC0D0E13, 0x191A1B15, 0x16172B2C, 0x2D272829, 0x2223241E, 0x1F20302F };
u32 lbl_1_data_229D8[4] = { 0xE0F10, 0x1020304, 0x5060708, 0x90A0B0C };
u32 lbl_1_data_229E8[4] = { 0x1017181A, 0x12131501, 0xC0D0F07, 0x80A0305 };
u32 lbl_1_data_229F8[4] = { 0x1017181A, 0x12131501, 0xC0D0F07, 0x80A0305 };
u32 lbl_1_data_22A08[2] = { 0x10010C0D, 0x7080500 };
u32 lbl_1_data_22A10[1] = { 0x1000000 };
u32 lbl_1_data_22A14[1] = { 0xC000000 };
u32 lbl_1_data_22A18[1] = { 0x7000000 };
char lbl_1_data_22A1C[] = "BODY";
char lbl_1_data_22A24[] = "FACE";
char lbl_1_data_22A2C[] = "HANDL";
char lbl_1_data_22A34[] = "HANDR";
char lbl_1_data_22A3C[] = "KATAATE";
char lbl_1_data_22A44[] = "_BOARD";
void *lbl_1_data_22A4C[54] = { 0, lbl_1_data_22A1C, lbl_1_data_21A3C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21A64, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21A80, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21A80, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A3C, lbl_1_data_22A14, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_22B24[45] = { 0, lbl_1_data_22A1C, lbl_1_data_215F0, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21618, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21628, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21628, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_22BD8[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21CB4, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21CDC, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21CF4, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21CF4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_22C8C[45] = { 0, lbl_1_data_22A1C, lbl_1_data_22334, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_2235C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22360, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22360, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_22D40[45] = { 0, lbl_1_data_22A1C, lbl_1_data_22884, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_228AC, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_228CC, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_228CC, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_22DF4[] = "KATAATE_R";
char lbl_1_data_22E00[] = "KATAATE_L";
void *lbl_1_data_22E0C[63] = { 0, lbl_1_data_22A1C, lbl_1_data_21F04, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21F2C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21F50, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21F50, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22DF4, lbl_1_data_22A14, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22E00, lbl_1_data_22A18, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_22F08[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21E08, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21E30, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21E54, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21E54, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_22FBC[27] = { 0, lbl_1_data_22A1C, lbl_1_data_222A0, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_222D8, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23028[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21660, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_216A8, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_216C0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_216C0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_230DC[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2193C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21964, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21980, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21980, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_23190[] = "_STICK";
void *lbl_1_data_23198[54] = { 0, lbl_1_data_22A1C, lbl_1_data_2221C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_22244, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22264, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22264, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_23190, lbl_1_data_22274, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23270[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2255C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_22584, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_225AC, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_225AC, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23324[63] = { 0, lbl_1_data_22A1C, lbl_1_data_2146C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21494, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_214B4, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_214B4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22DF4, lbl_1_data_22A14, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22E00, lbl_1_data_22A18, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_23420[] = "_MEKA";
void *lbl_1_data_23428[54] = { 0, lbl_1_data_22A1C, lbl_1_data_22904, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_2292C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_2294C, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_2294C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_23420, lbl_1_data_2295C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23500[63] = { 0, lbl_1_data_22A1C, lbl_1_data_213EC, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21414, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21434, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21434, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22DF4, lbl_1_data_22A14, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22E00, lbl_1_data_22A18, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_235FC[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21F88, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21FB0, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21FD4, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21FD4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_236B0[] = "_OWL";
void *lbl_1_data_236B8[54] = { 0, lbl_1_data_22A1C, lbl_1_data_2135C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21384, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_213A0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_213A0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_236B0, lbl_1_data_213B0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23790[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2200C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_2203C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22058, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22058, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23844[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21C38, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21C60, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21C7C, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21C7C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_238F8[45] = { 0, lbl_1_data_22A1C, lbl_1_data_22120, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_22148, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22160, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22160, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_239AC[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21D30, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21D58, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21D70, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21D70, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23A60[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21E8C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21EB4, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21ECC, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21ECC, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23B14[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21574, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_2159C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_215B8, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_215B8, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23BC8[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2267C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_226A4, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_226C0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_226C0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23C7C[45] = { 0, lbl_1_data_22A1C, lbl_1_data_22198, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_221C0, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_221E4, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_221E4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23D30[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21BAC, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21BD4, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21BF0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21BF0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23DE4[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2277C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_227A4, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_227C0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_227C0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23E98[45] = { 0, lbl_1_data_22A1C, lbl_1_data_219C0, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_219E8, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21A04, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21A04, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_23F4C[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2298C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_229B4, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_229D8, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_229D8, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24000[45] = { 0, lbl_1_data_22A1C, lbl_1_data_214EC, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21514, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_2153C, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_2153C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_240B4[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21AB8, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21AD8, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21ADC, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21ADC, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24168[45] = { 0, lbl_1_data_22A1C, lbl_1_data_224E4, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_22514, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22520, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22520, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_2421C[63] = { 0, lbl_1_data_22A1C, lbl_1_data_22404, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_2242C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22454, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22454, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22DF4, lbl_1_data_22A14, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22E00, lbl_1_data_22A18, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_24318[] = "_KATANA";
void *lbl_1_data_24320[54] = { 0, lbl_1_data_22A1C, lbl_1_data_21798, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_217C0, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_217E8, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_217E8, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24318, lbl_1_data_217F8, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_243F8[45] = { 0, lbl_1_data_22A1C, lbl_1_data_2248C, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_224AC, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_224B4, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_224B4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_244AC[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21830, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21860, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21878, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21878, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24560[54] = { 0, lbl_1_data_22A1C, lbl_1_data_218B8, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_218D8, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21900, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21900, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_23190, lbl_1_data_21910, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_24638[] = "_OP";
void *lbl_1_data_2463C[54] = { 0, lbl_1_data_22A1C, lbl_1_data_223A0, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_223CC, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_223D0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_223D0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24638, lbl_1_data_223B4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24714[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21700, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21728, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_2174C, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_2174C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_247C8[45] = { 0, lbl_1_data_22A1C, lbl_1_data_225E4, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_2260C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22630, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22630, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_2487C[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21B14, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21B3C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21B60, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21B60, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24930[45] = { 0, lbl_1_data_22A1C, lbl_1_data_22098, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_220C0, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_220E8, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_220E8, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_249E4[] = "_CARD_JOKER01";
char lbl_1_data_249F4[] = "_CARD_JOKER02";
char lbl_1_data_24A04[] = "_CARD_JOKER03";
char lbl_1_data_24A14[] = "_CARD_JOKER04";
char lbl_1_data_24A24[] = "_CARD_ACE01";
char lbl_1_data_24A30[] = "_CARD_ACE02";
char lbl_1_data_24A3C[] = "_CARD_ACE03";
char lbl_1_data_24A48[] = "_CARD_ACE04";
char lbl_1_data_24A54[] = "_BALL01";
char lbl_1_data_24A5C[] = "_BALL02";
char lbl_1_data_24A64[] = "_BALL03";
char lbl_1_data_24A6C[] = "_BALL04";
char lbl_1_data_24A74[] = "_BALL05";
char lbl_1_data_24A7C[] = "_BALL06";
char lbl_1_data_24A84[] = "_BALL07";
char lbl_1_data_24A8C[] = "_BALL08";
void *lbl_1_data_24A94[189] = { 0, lbl_1_data_22A1C, lbl_1_data_22808, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_22834, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_2284C, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_2284C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_249E4, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_249F4, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A04, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A14, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A24, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A30, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A3C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A48, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A54, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A5C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A64, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A6C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A74, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A7C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A84, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A8C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24D88[45] = { 0, lbl_1_data_22A1C, lbl_1_data_226FC, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_22724, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22744, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22744, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_24E3C[45] = { 0, lbl_1_data_22A1C, lbl_1_data_21DA8, 0, 0, 0, 0, 0, 0, (void *)0x5, lbl_1_data_22A24, lbl_1_data_21DBC, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21DD0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21DD0, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_22A44, lbl_1_data_22A10 };  /* fzgx-allow: A2 retail table words, not addresses */
char lbl_1_data_24EF0[] = "c_hara";
void *lbl_1_data_24EF8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21A90 };
void *lbl_1_data_24F1C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21638 };
void *lbl_1_data_24F40[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21D08 };
void *lbl_1_data_24F64[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22374 };
void *lbl_1_data_24F88[9] = { 0, lbl_1_data_24EF0, lbl_1_data_228DC };
void *lbl_1_data_24FAC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21F60 };
void *lbl_1_data_24FD0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_222F4 };
void *lbl_1_data_24FF4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_216D0 };
void *lbl_1_data_25018[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21990 };
void *lbl_1_data_2503C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21E64 };
void *lbl_1_data_25060[18] = { 0, lbl_1_data_24EF0, lbl_1_data_22278, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_23190, lbl_1_data_22274 };
void *lbl_1_data_250A8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_225BC };
void *lbl_1_data_250CC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_214C4 };
void *lbl_1_data_250F0[18] = { 0, lbl_1_data_24EF0, lbl_1_data_22964, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_23420, lbl_1_data_2295C };
void *lbl_1_data_25138[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21444 };
void *lbl_1_data_2515C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21FE4 };
void *lbl_1_data_25180[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22068 };
void *lbl_1_data_251A4[18] = { 0, lbl_1_data_24EF0, lbl_1_data_213C4, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_236B0, lbl_1_data_213B0 };
void *lbl_1_data_251EC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21C8C };
void *lbl_1_data_25210[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22170 };
void *lbl_1_data_25234[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21D80 };
void *lbl_1_data_25258[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21EDC };
void *lbl_1_data_2527C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_215C8 };
void *lbl_1_data_252A0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_226D4 };
void *lbl_1_data_252C4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_221F4 };
void *lbl_1_data_252E8[27] = { 0, lbl_1_data_24EF0, lbl_1_data_21C00, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21C10, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21C10 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_25354[27] = { 0, lbl_1_data_24EF0, lbl_1_data_227D0, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_227E0, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_227E0 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_253C0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21A14 };
void *lbl_1_data_253E4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_229E8 };
void *lbl_1_data_25408[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21AEC };
void *lbl_1_data_2542C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2154C };
void *lbl_1_data_25450[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22528 };
void *lbl_1_data_25474[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22464 };
void *lbl_1_data_25498[18] = { 0, lbl_1_data_24EF0, lbl_1_data_217FC, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24318, lbl_1_data_217F8 };
void *lbl_1_data_254E0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_224B8 };
void *lbl_1_data_25504[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21888 };
void *lbl_1_data_25528[18] = { 0, lbl_1_data_24EF0, lbl_1_data_21914, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_23190, lbl_1_data_21910 };
void *lbl_1_data_25570[18] = { 0, lbl_1_data_24EF0, lbl_1_data_223DC, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24638, lbl_1_data_223B4 };
void *lbl_1_data_255B8[27] = { 0, lbl_1_data_24EF0, lbl_1_data_2175C, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_2176C, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_2176C };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_25624[27] = { 0, lbl_1_data_24EF0, lbl_1_data_22640, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_22650, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_22650 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_25690[27] = { 0, lbl_1_data_24EF0, lbl_1_data_21B70, 0, 0, 0, 0, 0, 0, (void *)0xA, lbl_1_data_22A2C, lbl_1_data_21B80, 0, 0, 0, 0, 0, 0, (void *)0xF, lbl_1_data_22A34, lbl_1_data_21B80 };  /* fzgx-allow: A2 retail table words, not addresses */
void *lbl_1_data_256FC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_220F8 };
void *lbl_1_data_25720[153] = { 0, lbl_1_data_24EF0, lbl_1_data_2285C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_249E4, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_249F4, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A04, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A14, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A24, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A30, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A3C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A48, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A54, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A5C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A64, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A6C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A74, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A7C, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A84, lbl_1_data_2281C, 0, 0, 0, 0, 0, 0, 0, lbl_1_data_24A8C, lbl_1_data_2281C };
void *lbl_1_data_25984[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22754 };
void *lbl_1_data_259A8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21DE0 };
void *lbl_1_data_259CC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21AA0 };
void *lbl_1_data_259F0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21648 };
void *lbl_1_data_25A14[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21D18 };
void *lbl_1_data_25A38[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22384 };
void *lbl_1_data_25A5C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_228EC };
void *lbl_1_data_25A80[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21F70 };
void *lbl_1_data_25AA4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22310 };
void *lbl_1_data_25AC8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_216E4 };
void *lbl_1_data_25AEC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_219A4 };
void *lbl_1_data_25B10[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21E74 };
void *lbl_1_data_25B34[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22288 };
void *lbl_1_data_25B58[9] = { 0, lbl_1_data_24EF0, lbl_1_data_225CC };
void *lbl_1_data_25B7C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_214D4 };
void *lbl_1_data_25BA0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22974 };
void *lbl_1_data_25BC4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21454 };
void *lbl_1_data_25BE8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21FF4 };
void *lbl_1_data_25C0C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2207C };
void *lbl_1_data_25C30[9] = { 0, lbl_1_data_24EF0, lbl_1_data_213D4 };
void *lbl_1_data_25C54[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21C9C };
void *lbl_1_data_25C78[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22180 };
void *lbl_1_data_25C9C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21D90 };
void *lbl_1_data_25CC0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21EEC };
void *lbl_1_data_25CE4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_215D8 };
void *lbl_1_data_25D08[9] = { 0, lbl_1_data_24EF0, lbl_1_data_226E4 };
void *lbl_1_data_25D2C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22204 };
void *lbl_1_data_25D50[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21C20 };
void *lbl_1_data_25D74[9] = { 0, lbl_1_data_24EF0, lbl_1_data_227F0 };
void *lbl_1_data_25D98[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21A24 };
void *lbl_1_data_25DBC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_229F8 };
void *lbl_1_data_25DE0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21AFC };
void *lbl_1_data_25E04[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2155C };
void *lbl_1_data_25E28[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2253C };
void *lbl_1_data_25E4C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22474 };
void *lbl_1_data_25E70[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21810 };
void *lbl_1_data_25E94[9] = { 0, lbl_1_data_24EF0, lbl_1_data_224C8 };
void *lbl_1_data_25EB8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2189C };
void *lbl_1_data_25EDC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21924 };
void *lbl_1_data_25F00[9] = { 0, lbl_1_data_24EF0, lbl_1_data_223EC };
void *lbl_1_data_25F24[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2177C };
void *lbl_1_data_25F48[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22660 };
void *lbl_1_data_25F6C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21B90 };
void *lbl_1_data_25F90[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22108 };
void *lbl_1_data_25FB4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2286C };
void *lbl_1_data_25FD8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22764 };
void *lbl_1_data_25FFC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21DF0 };
void *lbl_1_data_26020[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21AB0 };
void *lbl_1_data_26044[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21658 };
void *lbl_1_data_26068[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21D28 };
void *lbl_1_data_2608C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22394 };
void *lbl_1_data_260B0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_228FC };
void *lbl_1_data_260D4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21F80 };
void *lbl_1_data_260F8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2232C };
void *lbl_1_data_2611C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_216F8 };
void *lbl_1_data_26140[9] = { 0, lbl_1_data_24EF0, lbl_1_data_219B8 };
void *lbl_1_data_26164[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21E84 };
void *lbl_1_data_26188[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22298 };
void *lbl_1_data_261AC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_225DC };
void *lbl_1_data_261D0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_214E4 };
void *lbl_1_data_261F4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22984 };
void *lbl_1_data_26218[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21464 };
void *lbl_1_data_2623C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22004 };
void *lbl_1_data_26260[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22090 };
void *lbl_1_data_26284[9] = { 0, lbl_1_data_24EF0, lbl_1_data_213E4 };
void *lbl_1_data_262A8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21CAC };
void *lbl_1_data_262CC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22190 };
void *lbl_1_data_262F0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21DA0 };
void *lbl_1_data_26314[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21EFC };
void *lbl_1_data_26338[9] = { 0, lbl_1_data_24EF0, lbl_1_data_215E8 };
void *lbl_1_data_2635C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_226F4 };
void *lbl_1_data_26380[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22214 };
void *lbl_1_data_263A4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21C30 };
void *lbl_1_data_263C8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22800 };
void *lbl_1_data_263EC[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21A34 };
void *lbl_1_data_26410[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22A08 };
void *lbl_1_data_26434[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21B0C };
void *lbl_1_data_26458[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2156C };
void *lbl_1_data_2647C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22550 };
void *lbl_1_data_264A0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22484 };
void *lbl_1_data_264C4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21824 };
void *lbl_1_data_264E8[9] = { 0, lbl_1_data_24EF0, lbl_1_data_224D8 };
void *lbl_1_data_2650C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_218B0 };
void *lbl_1_data_26530[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21934 };
void *lbl_1_data_26554[9] = { 0, lbl_1_data_24EF0, lbl_1_data_223FC };
void *lbl_1_data_26578[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2178C };
void *lbl_1_data_2659C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22670 };
void *lbl_1_data_265C0[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21BA0 };
void *lbl_1_data_265E4[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22118 };
void *lbl_1_data_26608[9] = { 0, lbl_1_data_24EF0, lbl_1_data_2287C };
void *lbl_1_data_2662C[9] = { 0, lbl_1_data_24EF0, lbl_1_data_22774 };
void *lbl_1_data_26650[9] = { 0, lbl_1_data_24EF0, lbl_1_data_21E00 };
u32 lbl_1_data_26674[45] = { 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xB4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xFC000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF0000000 };
void *lbl_1_data_26728[45] = { lbl_1_data_240B4, lbl_1_data_22E0C, lbl_1_data_22D40, lbl_1_data_23500, lbl_1_data_22BD8, lbl_1_data_22C8C, lbl_1_data_22A4C, lbl_1_data_22FBC, lbl_1_data_23E98, lbl_1_data_23A60, lbl_1_data_24000, lbl_1_data_235FC, lbl_1_data_23F4C, lbl_1_data_22F08, lbl_1_data_24168, lbl_1_data_23844, lbl_1_data_239AC, lbl_1_data_23324, lbl_1_data_23790, lbl_1_data_236B8, lbl_1_data_23C7C, lbl_1_data_23DE4, lbl_1_data_23198, lbl_1_data_238F8, lbl_1_data_23B14, lbl_1_data_23428, lbl_1_data_230DC, lbl_1_data_23270, lbl_1_data_23028, lbl_1_data_23BC8, lbl_1_data_22B24, lbl_1_data_24560, lbl_1_data_244AC, lbl_1_data_24714, lbl_1_data_24A94, lbl_1_data_24320, lbl_1_data_2421C, lbl_1_data_24930, lbl_1_data_2463C, lbl_1_data_243F8, lbl_1_data_24D88, lbl_1_data_23D30, lbl_1_data_247C8, lbl_1_data_2487C, lbl_1_data_24E3C };
u32 lbl_1_data_267DC[45] = { 0x5, 0x7, 0x5, 0x7, 0x5, 0x5, 0x6, 0x3, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x7, 0x5, 0x6, 0x5, 0x5, 0x6, 0x5, 0x5, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x6, 0x5, 0x5, 0x15, 0x6, 0x7, 0x5, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5 };
void *lbl_1_data_26890[45] = { lbl_1_data_25408, lbl_1_data_24FAC, lbl_1_data_24F88, lbl_1_data_25138, lbl_1_data_24F40, lbl_1_data_24F64, lbl_1_data_24EF8, lbl_1_data_24FD0, lbl_1_data_253C0, lbl_1_data_25258, lbl_1_data_2542C, lbl_1_data_2515C, lbl_1_data_253E4, lbl_1_data_2503C, lbl_1_data_25450, lbl_1_data_251EC, lbl_1_data_25234, lbl_1_data_250CC, lbl_1_data_25180, lbl_1_data_251A4, lbl_1_data_252C4, lbl_1_data_25354, lbl_1_data_25060, lbl_1_data_25210, lbl_1_data_2527C, lbl_1_data_250F0, lbl_1_data_25018, lbl_1_data_250A8, lbl_1_data_24FF4, lbl_1_data_252A0, lbl_1_data_24F1C, lbl_1_data_25528, lbl_1_data_25504, lbl_1_data_255B8, lbl_1_data_25720, lbl_1_data_25498, lbl_1_data_25474, lbl_1_data_256FC, lbl_1_data_25570, lbl_1_data_254E0, lbl_1_data_25984, lbl_1_data_252E8, lbl_1_data_25624, lbl_1_data_25690, lbl_1_data_259A8 };
u32 lbl_1_data_26944[45] = { 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x3, 0x2, 0x1, 0x1, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x3, 0x11, 0x2, 0x1, 0x1, 0x2, 0x1, 0x1, 0x3, 0x3, 0x3, 0x1 };
void *lbl_1_data_269F8[45] = { lbl_1_data_25DE0, lbl_1_data_25A80, lbl_1_data_25A5C, lbl_1_data_25BC4, lbl_1_data_25A14, lbl_1_data_25A38, lbl_1_data_259CC, lbl_1_data_25AA4, lbl_1_data_25D98, lbl_1_data_25CC0, lbl_1_data_25E04, lbl_1_data_25BE8, lbl_1_data_25DBC, lbl_1_data_25B10, lbl_1_data_25E28, lbl_1_data_25C54, lbl_1_data_25C9C, lbl_1_data_25B7C, lbl_1_data_25C0C, lbl_1_data_25C30, lbl_1_data_25D2C, lbl_1_data_25D74, lbl_1_data_25B34, lbl_1_data_25C78, lbl_1_data_25CE4, lbl_1_data_25BA0, lbl_1_data_25AEC, lbl_1_data_25B58, lbl_1_data_25AC8, lbl_1_data_25D08, lbl_1_data_259F0, lbl_1_data_25EDC, lbl_1_data_25EB8, lbl_1_data_25F24, lbl_1_data_25FB4, lbl_1_data_25E70, lbl_1_data_25E4C, lbl_1_data_25F90, lbl_1_data_25F00, lbl_1_data_25E94, lbl_1_data_25FD8, lbl_1_data_25D50, lbl_1_data_25F48, lbl_1_data_25F6C, lbl_1_data_25FFC };
u32 lbl_1_data_26AAC[45] = { 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1 };
void *lbl_1_data_26B60[45] = { lbl_1_data_26434, lbl_1_data_260D4, lbl_1_data_260B0, lbl_1_data_26218, lbl_1_data_26068, lbl_1_data_2608C, lbl_1_data_26020, lbl_1_data_260F8, lbl_1_data_263EC, lbl_1_data_26314, lbl_1_data_26458, lbl_1_data_2623C, lbl_1_data_26410, lbl_1_data_26164, lbl_1_data_2647C, lbl_1_data_262A8, lbl_1_data_262F0, lbl_1_data_261D0, lbl_1_data_26260, lbl_1_data_26284, lbl_1_data_26380, lbl_1_data_263C8, lbl_1_data_26188, lbl_1_data_262CC, lbl_1_data_26338, lbl_1_data_261F4, lbl_1_data_26140, lbl_1_data_261AC, lbl_1_data_2611C, lbl_1_data_2635C, lbl_1_data_26044, lbl_1_data_26530, lbl_1_data_2650C, lbl_1_data_26578, lbl_1_data_26608, lbl_1_data_264C4, lbl_1_data_264A0, lbl_1_data_265E4, lbl_1_data_26554, lbl_1_data_264E8, lbl_1_data_2662C, lbl_1_data_263A4, lbl_1_data_2659C, lbl_1_data_265C0, lbl_1_data_26650 };
u32 lbl_1_data_26C14[45] = { 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1 };
u32 lbl_1_data_26CC8[34] = { 0x18000000, 0x0, 0x18000000, 0x10000, 0x18000000, 0x20000, 0x18000000, 0x30000, 0x18000000, 0x40000, 0x18000000, 0x50000, 0x18000000, 0x60000, 0x18000000, 0x70000, 0x18000000, 0x80000, 0x18000000, 0x90000, 0x18000000, 0xA0000, 0x18000000, 0xB0000, 0x18000000, 0xC0000, 0x18000000, 0xD0000, 0x18000000, 0xE0000, 0x18000000, 0xF0000, 0x18000000, 0x100000 };
char lbl_1_data_26D50[] = "";
char lbl_1_data_26D54[] = "_1000";
char lbl_1_data_26D5C[] = "_500";
char lbl_1_data_26D64[] = "_100";
char lbl_1_data_26D6C[] = "_3000";
char lbl_1_data_26D74[] = "_cv1";
char lbl_1_data_26D7C[] = "_cv2";
char lbl_1_data_26D84[] = "_cv3";
char lbl_1_data_26D8C[] = "LIP_A";
char lbl_1_data_26D94[] = "LIP_I";
char lbl_1_data_26D9C[] = "LIP_U";
char lbl_1_data_26DA4[] = "LIP_E";
char lbl_1_data_26DAC[] = "LIP_O";
char lbl_1_data_26DB4[] = "FACE_DEF";
char *lbl_1_data_26DC0[6] = { lbl_1_data_26D8C, lbl_1_data_26D94, lbl_1_data_26D9C, lbl_1_data_26DA4, lbl_1_data_26DAC, lbl_1_data_26DB4 };
f32 lbl_1_data_26DD8 = 50.0f;
char lbl_1_data_26DDC[] = "int_02";
char lbl_1_data_26DE4[] = "int_03";
char lbl_1_data_26DEC[] = "int_04";
char lbl_1_data_26DF4[] = "int_04_fear";
char lbl_1_data_26E00[] = "int_05_fear";
char lbl_1_data_26E0C[] = "int_14";
char lbl_1_data_26E14[] = "int_15";
char lbl_1_data_26E1C[] = "int_16";
char lbl_1_data_26E24[] = "int_18";
char lbl_1_data_26E2C[] = "int_20";
char lbl_1_data_26E34[] = "int_21";
char lbl_1_data_26E3C[] = "int_23";
char lbl_1_data_26E44[] = "int_24";
char lbl_1_data_26E4C[] = "int_27";
char lbl_1_data_26E54[] = "int_28";
char lbl_1_data_26E5C[] = "int_31";
char lbl_1_data_26E64[] = "int_33";
char lbl_1_data_26E6C[] = "int_34";
char lbl_1_data_26E74[] = "int_35";
char lbl_1_data_26E7C[] = "int_36";
char lbl_1_data_26E84[] = "int_37";
char lbl_1_data_26E8C[] = "int_50";
char lbl_1_data_26E94[] = "int_51";
char lbl_1_data_26E9C[] = "int_52";
char lbl_1_data_26EA4[] = "int_com_1";
char lbl_1_data_26EB0[] = "int_com_2";
char lbl_1_data_26EBC[] = "int_com_3";
char lbl_1_data_26EC8[] = "int_com_4";
char lbl_1_data_26ED4[] = "int_com_5";
char lbl_1_data_26EE0[] = "int_com_6";
char lbl_1_data_26EEC[] = "int_com_7";
char lbl_1_data_26EF8[] = "int_com_8";
char lbl_1_data_26F04[] = "int_com_9";
char lbl_1_data_26F10[] = "int_com_10";
char lbl_1_data_26F1C[] = "int_com2_1";
char lbl_1_data_26F28[] = "int_com2_2";
char lbl_1_data_26F34[] = "int_com2_3";
char lbl_1_data_26F40[] = "int_com2_4";
char lbl_1_data_26F4C[] = "int_com2_5";
char lbl_1_data_26F58[] = "int_com2_6";
char lbl_1_data_26F64[] = "int_com2_7";
char lbl_1_data_26F70[] = "int_com2_8";
char lbl_1_data_26F7C[] = "int_com2_9";
char lbl_1_data_26F88[] = "int_com2_10";
char *lbl_1_data_26F94[45] = { lbl_1_data_26DDC, lbl_1_data_26DE4, lbl_1_data_26DEC, lbl_1_data_26DF4, lbl_1_data_26E00, lbl_1_data_26E0C, lbl_1_data_26E14, lbl_1_data_26E1C, lbl_1_data_26E24, lbl_1_data_26E2C, lbl_1_data_26E34, lbl_1_data_26E3C, lbl_1_data_26E44, lbl_1_data_26E4C, lbl_1_data_26E54, lbl_1_data_26E5C, lbl_1_data_26E5C, lbl_1_data_26E64, lbl_1_data_26E6C, lbl_1_data_26E74, lbl_1_data_26E7C, lbl_1_data_26E84, lbl_1_data_26E8C, lbl_1_data_26E94, lbl_1_data_26E9C, lbl_1_data_26EA4, lbl_1_data_26EB0, lbl_1_data_26EBC, lbl_1_data_26EC8, lbl_1_data_26ED4, lbl_1_data_26EE0, lbl_1_data_26EEC, lbl_1_data_26EF8, lbl_1_data_26F04, lbl_1_data_26F10, lbl_1_data_26F1C, lbl_1_data_26F28, lbl_1_data_26F34, lbl_1_data_26F40, lbl_1_data_26F4C, lbl_1_data_26F58, lbl_1_data_26F64, lbl_1_data_26F70, lbl_1_data_26F7C, lbl_1_data_26F88 };
char lbl_1_data_27048[] = "gazelle_board";
char lbl_1_data_27058[] = "BOARD";
char lbl_1_data_27060[] = "jody_board";
char lbl_1_data_2706C[] = "stewart_board";
char lbl_1_data_2707C[] = "baba_board";
char lbl_1_data_27088[] = "goroh_board";
char lbl_1_data_27094[] = "pico_board";
char lbl_1_data_270A0[] = "falcon_board";
char lbl_1_data_270B0[] = "octman_board";
char lbl_1_data_270C0[] = "ead_board";
char lbl_1_data_270CC[] = "james_board";
char lbl_1_data_270D8[] = "billy_board";
char lbl_1_data_270E4[] = "kate_board";
char lbl_1_data_270F0[] = "zoda_board";
char lbl_1_data_270FC[] = "jack_board";
char lbl_1_data_27108[] = "rex_board";
char lbl_1_data_27114[] = "gordon_board";
char lbl_1_data_27124[] = "guster_board";
char lbl_1_data_27134[] = "beastman_board";
char lbl_1_data_27144[] = "leon_board";
char lbl_1_data_27150[] = "arrow_board";
char lbl_1_data_2715C[] = "mrs_board";
char lbl_1_data_27168[] = "shio_board";
char lbl_1_data_27174[] = "neelsen_board";
char lbl_1_data_27184[] = "michael_board";
char lbl_1_data_27194[] = "blood_board";
char lbl_1_data_271A0[] = "tanaka_board";
char lbl_1_data_271B0[] = "draq_board";
char lbl_1_data_271BC[] = "roger_board";
char lbl_1_data_271C8[] = "clash_board";
char lbl_1_data_271D4[] = "shadow_board";
char lbl_1_data_271E4[] = "boss_board";
char lbl_1_data_271F0[] = "don_board";
char lbl_1_data_271FC[] = "digiboy_board";
char lbl_1_data_2720C[] = "dai_board";
char lbl_1_data_27218[] = "spade_board";
char lbl_1_data_27224[] = "daigoroh_board";
char lbl_1_data_27234[] = "prisia_board";
char lbl_1_data_27244[] = "lily_board";
char lbl_1_data_27250[] = "pj_board";
char lbl_1_data_2725C[] = "qqq_board";
char lbl_1_data_27268[] = "sherlock_board";
char lbl_1_data_27278[] = "goma_board";
char lbl_1_data_27284[] = "san_board";
char lbl_1_data_27290[] = "gen_board";
char lbl_1_data_2729C[] = "tanaka_meka";
char lbl_1_data_272A8[] = "MEKA";
char lbl_1_data_272B0[] = "arrow_owl";
char lbl_1_data_272BC[] = "OWL";
char lbl_1_data_272C0[] = "neelsen_stick";
char lbl_1_data_272D0[] = "TUE";
char lbl_1_data_272D4[] = "daigoroh_katana";
char lbl_1_data_272E4[] = "KATANA";
char lbl_1_data_272EC[] = "don_stick";
char lbl_1_data_272F8[] = "pj_op";
char lbl_1_data_27300[] = "OP";
char lbl_1_data_27304[] = "spade_card_ace01";
char lbl_1_data_27318[] = "CARD_ACE01";
char lbl_1_data_27324[] = "spade_card_ace02";
char lbl_1_data_27338[] = "CARD_ACE02";
char lbl_1_data_27344[] = "spade_card_ace03";
char lbl_1_data_27358[] = "CARD_ACE03";
char lbl_1_data_27364[] = "spade_card_ace04";
char lbl_1_data_27378[] = "CARD_ACE04";
char lbl_1_data_27384[] = "spade_card_joker01";
char lbl_1_data_27398[] = "CARD_JOKER01";
char lbl_1_data_273A8[] = "spade_card_joker02";
char lbl_1_data_273BC[] = "CARD_JOKER02";
char lbl_1_data_273CC[] = "spade_card_joker03";
char lbl_1_data_273E0[] = "CARD_JOKER03";
char lbl_1_data_273F0[] = "spade_card_joker04";
char lbl_1_data_27404[] = "CARD_JOKER04";
char lbl_1_data_27414[] = "spade_ball01";
char lbl_1_data_27424[] = "BALL01";
char lbl_1_data_2742C[] = "spade_ball02";
char lbl_1_data_2743C[] = "BALL02";
char lbl_1_data_27444[] = "spade_ball03";
char lbl_1_data_27454[] = "BALL03";
char lbl_1_data_2745C[] = "spade_ball04";
char lbl_1_data_2746C[] = "BALL04";
char lbl_1_data_27474[] = "spade_ball05";
char lbl_1_data_27484[] = "BALL05";
char lbl_1_data_2748C[] = "spade_ball06";
char lbl_1_data_2749C[] = "BALL06";
char lbl_1_data_274A4[] = "spade_ball07";
char lbl_1_data_274B4[] = "BALL07";
char lbl_1_data_274BC[] = "spade_ball08";
char lbl_1_data_274CC[] = "BALL08";
PartEntry lbl_1_data_274D4[66] = { { 0x0, 0, lbl_1_data_27048, lbl_1_data_27058 }, { 0x1, 0, lbl_1_data_27060, lbl_1_data_27058 }, { 0x2, 0, lbl_1_data_2706C, lbl_1_data_27058 }, { 0x3, 0, lbl_1_data_2707C, lbl_1_data_27058 }, { 0x4, 0, lbl_1_data_27088, lbl_1_data_27058 }, { 0x5, 0, lbl_1_data_27094, lbl_1_data_27058 }, { 0x6, 0, lbl_1_data_270A0, lbl_1_data_27058 }, { 0x7, 0, lbl_1_data_270B0, lbl_1_data_27058 }, { 0x8, 0, lbl_1_data_270C0, lbl_1_data_27058 }, { 0x9, 0, lbl_1_data_270CC, lbl_1_data_27058 }, { 0xA, 0, lbl_1_data_270D8, lbl_1_data_27058 }, { 0xB, 0, lbl_1_data_270E4, lbl_1_data_27058 }, { 0xC, 0, lbl_1_data_270F0, lbl_1_data_27058 }, { 0xD, 0, lbl_1_data_270FC, lbl_1_data_27058 }, { 0xE, 0, lbl_1_data_27108, lbl_1_data_27058 }, { 0xF, 0, lbl_1_data_27114, lbl_1_data_27058 }, { 0x10, 0, lbl_1_data_27124, lbl_1_data_27058 }, { 0x11, 0, lbl_1_data_27134, lbl_1_data_27058 }, { 0x12, 0, lbl_1_data_27144, lbl_1_data_27058 }, { 0x13, 0, lbl_1_data_27150, lbl_1_data_27058 }, { 0x14, 0, lbl_1_data_2715C, lbl_1_data_27058 }, { 0x15, 0, lbl_1_data_27168, lbl_1_data_27058 }, { 0x16, 0, lbl_1_data_27174, lbl_1_data_27058 }, { 0x17, 0, lbl_1_data_27184, lbl_1_data_27058 }, { 0x18, 0, lbl_1_data_27194, lbl_1_data_27058 }, { 0x19, 0, lbl_1_data_271A0, lbl_1_data_27058 }, { 0x1A, 0, lbl_1_data_271B0, lbl_1_data_27058 }, { 0x1B, 0, lbl_1_data_271BC, lbl_1_data_27058 }, { 0x1C, 0, lbl_1_data_271C8, lbl_1_data_27058 }, { 0x1D, 0, lbl_1_data_271D4, lbl_1_data_27058 }, { 0x1E, 0, lbl_1_data_271E4, lbl_1_data_27058 }, { 0x1F, 0, lbl_1_data_271F0, lbl_1_data_27058 }, { 0x20, 0, lbl_1_data_271FC, lbl_1_data_27058 }, { 0x21, 0, lbl_1_data_2720C, lbl_1_data_27058 }, { 0x22, 0, lbl_1_data_27218, lbl_1_data_27058 }, { 0x23, 0, lbl_1_data_27224, lbl_1_data_27058 }, { 0x24, 0, lbl_1_data_27234, lbl_1_data_27058 }, { 0x25, 0, lbl_1_data_27244, lbl_1_data_27058 }, { 0x26, 0, lbl_1_data_27250, lbl_1_data_27058 }, { 0x27, 0, lbl_1_data_2725C, lbl_1_data_27058 }, { 0x28, 0, lbl_1_data_27268, lbl_1_data_27058 }, { 0x29, 0, lbl_1_data_27278, lbl_1_data_27058 }, { 0x2A, 0, lbl_1_data_27284, lbl_1_data_27058 }, { 0x2B, 0, lbl_1_data_27290, lbl_1_data_27058 }, { 0x19, 1, lbl_1_data_2729C, lbl_1_data_272A8 }, { 0x13, 1, lbl_1_data_272B0, lbl_1_data_272BC }, { 0x16, 1, lbl_1_data_272C0, lbl_1_data_272D0 }, { 0x23, 1, lbl_1_data_272D4, lbl_1_data_272E4 }, { 0x1F, 1, lbl_1_data_272EC, lbl_1_data_272D0 }, { 0x26, 1, lbl_1_data_272F8, lbl_1_data_27300 }, { 0x22, 1, lbl_1_data_27304, lbl_1_data_27318 }, { 0x22, 2, lbl_1_data_27324, lbl_1_data_27338 }, { 0x22, 3, lbl_1_data_27344, lbl_1_data_27358 }, { 0x22, 4, lbl_1_data_27364, lbl_1_data_27378 }, { 0x22, 5, lbl_1_data_27384, lbl_1_data_27398 }, { 0x22, 6, lbl_1_data_273A8, lbl_1_data_273BC }, { 0x22, 7, lbl_1_data_273CC, lbl_1_data_273E0 }, { 0x22, 8, lbl_1_data_273F0, lbl_1_data_27404 }, { 0x22, 9, lbl_1_data_27414, lbl_1_data_27424 }, { 0x22, 10, lbl_1_data_2742C, lbl_1_data_2743C }, { 0x22, 11, lbl_1_data_27444, lbl_1_data_27454 }, { 0x22, 12, lbl_1_data_2745C, lbl_1_data_2746C }, { 0x22, 13, lbl_1_data_27474, lbl_1_data_27484 }, { 0x22, 14, lbl_1_data_2748C, lbl_1_data_2749C }, { 0x22, 15, lbl_1_data_274A4, lbl_1_data_274B4 }, { 0x22, 16, lbl_1_data_274BC, lbl_1_data_274CC } };
u32 lbl_1_data_277EC = 0x42;
u32 lbl_1_data_277F0 = 0xC7382A7E;
/* TU B .rodata 3E48: the coin/card suffix tables */
static const char *const sDirs[5] = { lbl_1_data_26D50, lbl_1_data_26D50, lbl_1_data_26D54, lbl_1_data_26D5C, lbl_1_data_26D64 };
static const char *const sPacks[5] = { lbl_1_data_26D50, lbl_1_data_26D6C, lbl_1_data_26D54, lbl_1_data_26D5C, lbl_1_data_26D64 };
static const char *const sExts[4] = { lbl_1_data_26D50, lbl_1_data_26D74, lbl_1_data_26D7C, lbl_1_data_26D84 };

/* fzgx:begin fn_1_8E4A4 */
/* flag masks: the top two (or three, for special ids) bits select a variant */

#define FLAGS_HI2 (~0x3FFFFFFFu)

#define FLAGS_HI3 (~0x1FFFFFFFu)

static inline char *findPart(u32 id, u32 index) {
    u32 i;
    PartEntry *e = lbl_1_data_274D4;
    for (i = 0; i < lbl_1_data_277EC; i++) {
        if (id == e[i].id && index == e[i].index) {
            return lbl_1_data_274D4[i].name;
        }
    }
    return NULL;
}

static inline int isSpecial(s32 id) {
    return id == 0x15 || id == 0x29 || id == 0x21 || id == 0x2a || id == 0x2b;
}

void fn_1_8E4A4(s32 id, u32 flags, void *arg) {
    char buf[64];

    char *name = lbl_1_data_20D1C[id];
    u32 hi;
    u32 i;
    int special;

    fn_1_96664((void *)id, (void *)flags, (void *)arg);
    fn_1_956EC(id, flags);

    if (*(s16 *)&lbl_1_bss_960 == 14 && flags == 0x10000000) {
        sprintf(buf, "%s_win.mta", name);
        fn_1_96130((void *)buf);
    } else {
        sprintf(buf, "%s_test.mta", name);
        fn_1_96130((void *)buf);
        special = isSpecial(id);
        if ((flags & (special ? FLAGS_HI3 : FLAGS_HI2)) &&
            (lbl_1_data_26674[id] & 0x40000000)) {
            sprintf(buf, "%s_hand.mta", name);
            fn_1_96130((void *)buf);
        }
        hi = flags & FLAGS_HI2;
        if (hi && (lbl_1_data_26674[id] & 0x20000000)) {
            sprintf(buf, "%s_face.mta", name);
            fn_1_96130((void *)buf);
        }
        if (hi && (lbl_1_data_26674[id] & 0x10000000)) {
            sprintf(buf, "%s_lip.mta", name);
            fn_1_96130((void *)buf);
        }
        if (hi && (lbl_1_data_26674[id] & 0x08000000)) {
            sprintf(buf, "%s_eye.mta", name);
            fn_1_96130((void *)buf);
        }
        if ((flags & FLAGS_HI3) && (lbl_1_data_26674[id] & 0x04000000)) {
            for (i = 0; i < 20; i++) {
                sprintf(buf, "%s.mta", findPart(id, i));
                if (strcmp(buf, ".mta")) {
                    fn_1_96130((void *)buf);
                }
            }
        }
    }
    sprintf(buf, "%s_common.mal", name);
    fn_1_96130((void *)buf);
}
/* fzgx:end fn_1_8E4A4 */

/* fzgx:begin fn_1_8E728 */
void fn_1_8E728(struct Unk_1_8E728 *p, u8 idx) {
    s32 i;

    if (p != 0) {
        idx %= 4;
        /* WARNING: compiler-diff device, not original code: __rlwnm keeps retail's `rlwnm.` with the rotate amount in a
              register; `(m >> (31 - i)) & 1` gives subfic/srw/clrlwi. No natural spelling is known (lanes FT, DVcar). */
        if ((__rlwnm(p->field_9c, ((idx + 1) & 31), 31, 31) != 0)) {
            for (i = 0; i < 5; i++) {
                u32 v0 = p->field_e4[i];
                u32 v1 = p->field_f8[i][idx];
                if (v0 != 0 && v1 != 0) {
                    fn_800713E0((u32)((struct Sig_fn_800713E0_fn_800713E0_Arg0 *)v0), v1);
                }
            }
            p->field_98 = idx;
        }
    }
}
#undef FLAGS_HI2
#undef FLAGS_HI3
/* fzgx:end fn_1_8E728 */

/* fzgx:begin fn_1_8E7D0 */
/* VIEWS */
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)
static inline char *fn_1_8E7D0_motion(u32 id, u32 slot) {
    u32 k;

    for (k = 0; k < lbl_1_data_277EC; k++) {
        if (id == lbl_1_data_274D4[k].id && slot == lbl_1_data_274D4[k].index) {
            return lbl_1_data_274D4[k].name;
        }
    }
    return NULL;
}

static inline s32 fn_1_8E7D0_handle(Fn8E7D0Car *car) {
    s32 *entry;
    s32 handle;
    s32 i;

    handle = -1;
    entry = &car->unk_0;
    for (i = 0; i < 5; i++) {
        if (entry[1] != -1) {
            handle = car->unk_4[i];
            break;
        }
        entry++;
    }
    return handle;
}

void fn_1_8E7D0(Fn8E7D0Car *car, s32 idx, u32 mask, u32 mask2) {
    char *name;
    s32 i;
    u32 face;
    u32 j;
    s32 handle;
    s32 k;
    char buf[0x40];
    s32 special;

    name = lbl_1_data_20D1C[idx];
    car->unk_0 = 1;
    handle = fn_1_8E7D0_handle(car);
    if (handle != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(handle);
    } else {
        fn_1_12A2B8(0);
    }
    if (mask == 0) {
        mask = 0x80000000;
    }
    car->unk_1C = 0;
    car->unk_20 = 0;
    car->unk_24 = 0;
    car->unk_28 = 0;
    car->unk_18 = 0;
    car->unk_88 = idx;
    if (mask >> 31) {
        car->unk_8C = 0;
    } else if ((mask >> 30) & 1) {
        car->unk_8C = 1;
    } else if ((mask >> 29) & 1) {
        car->unk_8C = 2;
    } else if ((mask >> 28) & 1) {
        car->unk_8C = 3;
    } else if ((mask >> 27) & 1) {
        car->unk_8C = 4;
    } else {
        car->unk_8C = 0;
        mask = 0x80000000;
    }
    car->unk_94 = mask;
    if (mask2 >> 31) {
        car->unk_98 = 0;
    } else if ((mask2 >> 30) & 1) {
        car->unk_98 = 1;
    } else if ((mask2 >> 29) & 1) {
        car->unk_98 = 2;
    } else if ((mask2 >> 28) & 1) {
        car->unk_98 = 3;
    } else {
        car->unk_98 = 0;
        mask2 = 0x80000000;
    }
    car->unk_9C = mask2;
    car->unk_90 = car->unk_8C;
    car->unk_A4 = 0;
    car->unk_A2 = 0;
    car->unk_A0 = 0;
    {
        Vec3 zero = {0.0f, 0.0f, 0.0f};

        car->unk_A8 = zero;
    }
    car->unk_B4 = 0.0f;
    car->unk_B8 = 1.0f;
    for (k = 0; k < 5; k++) {
        if (k == 0) {
            car->unk_BC[k] = lbl_1_data_26728[idx];
            car->unk_D0[k] = lbl_1_data_267DC[idx];
        } else if (k == 1) {
            car->unk_BC[k] = lbl_1_data_26728[idx];
            car->unk_D0[k] = lbl_1_data_267DC[idx];
        } else if (k == 2) {
            car->unk_BC[k] = lbl_1_data_26890[idx];
            car->unk_D0[k] = lbl_1_data_26944[idx];
        } else if (k == 3) {
            car->unk_BC[k] = lbl_1_data_269F8[idx];
            car->unk_D0[k] = lbl_1_data_26AAC[idx];
        } else if (k == 4) {
            car->unk_BC[k] = lbl_1_data_26B60[idx];
            car->unk_D0[k] = lbl_1_data_26C14[idx];
        } else {
            car->unk_BC[k] = 0;
            car->unk_D0[k] = 0;
        }
        car->unk_E4[k] = 0;
        car->unk_F8[k][0] = 0;
        car->unk_F8[k][1] = 0;
        car->unk_F8[k][2] = 0;
        car->unk_F8[k][3] = 0;
    }
    fn_1_96630((void *)car, (void *)mask, (void *)mask2);
    {
        Fn8E7D0Part part = {0};

        car->unk_148 = part;
    }
    {
        Fn8E7D0Part part = {0};

        car->unk_168 = part;
    }
    {
        Fn8E7D0Part part = {0};

        car->unk_188 = part;
    }
    {
        Fn8E7D0Part part = {0};

        car->unk_1A8 = part;
    }
    {
        Fn8E7D0Part part = {0};

        car->unk_1C8 = part;
    }
    {
        Fn8E7D0Part part = {0};

        car->unk_1E8 = part;
    }
    for (k = 0; k < 20; k++) {
        Fn8E7D0Part part = {0};

        car->unk_208[k] = part;
    }
    fn_1_95950((u32)car);
    if (lbl_1_bss_960 == 14 && mask == 0x10000000) {
        sprintf(buf, "%s_win.mta", name);
    } else {
        sprintf(buf, "%s_test.mta", name);
    }
    fn_1_9617C((void *)&car->unk_148, (void *)buf);
    special = idx == 0x15 || idx == 0x29 || idx == 0x21 || idx == 0x2A || idx == 0x2B;
    if ((mask & (special ? (1U << 31) | (1U << 30) | (1U << 29) : (1U << 31) | (1U << 30))) && (lbl_1_data_26674[idx] & 0x40000000)) {
        sprintf(buf, "%s_hand.mta", name);
        fn_1_9617C((void *)&car->unk_168, (void *)buf);
        car->unk_188.unk_C = car->unk_168.unk_C;
        if (car->unk_188.unk_8 != NULL && car->unk_188.unk_C != NULL) {
            fn_1_426E4(car->unk_188.unk_8, car->unk_188.unk_C);
        }
    }
    face = mask & ((1U << 31) | (1U << 30));
    if (face && (lbl_1_data_26674[idx] & 0x20000000)) {
        sprintf(buf, "%s_face.mta", name);
        fn_1_9617C((void *)&car->unk_1A8, (void *)buf);
    }
    if (face && (lbl_1_data_26674[idx] & 0x10000000)) {
        sprintf(buf, "%s_lip.mta", name);
        fn_1_9617C((void *)&car->unk_1C8, (void *)buf);
    }
    if (face && (lbl_1_data_26674[idx] & 0x08000000)) {
        sprintf(buf, "%s_eye.mta", name);
        fn_1_9617C((void *)&car->unk_1E8, (void *)buf);
    }
    if ((mask & ((1U << 31) | (1U << 30) | (1U << 29))) && (lbl_1_data_26674[idx] & 0x04000000)) {
        for (j = 0; j < 20; j++) {
            if (car->unk_208[j].unk_8 != NULL) {
                sprintf(buf, "%s.mta", fn_1_8E7D0_motion(car->unk_88, j));
                if (strcmp(buf, ".mta")) {
                    fn_1_9617C((void *)&car->unk_208[j], (void *)buf);
                }
            }
        }
    }
    sprintf(buf, "%s_common.mal", name);
    fn_1_967A8((void *)car, (void *)buf);
    if (car->unk_148.unk_8 != NULL && car->unk_148.unk_C != NULL) {
        fn_1_933D8((void *)car, (void *)&car->unk_148, 0);
    }
    if (car->unk_168.unk_8 != NULL && car->unk_168.unk_C != NULL) {
        fn_1_934CC((void *)car, (void *)&car->unk_168, "TE_R");
    }
    if (car->unk_188.unk_8 != NULL && car->unk_188.unk_C != NULL) {
        fn_1_934CC((void *)car, (void *)&car->unk_188, "TE_RM");
    }
    if (car->unk_1A8.unk_8 != NULL && car->unk_1A8.unk_C != NULL) {
        fn_1_934CC((void *)car, (void *)&car->unk_1A8, lbl_1_data_22A24);
    }
    if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL) {
        fn_1_934CC((void *)car, (void *)&car->unk_1C8, "LIP");
    }
    if (car->unk_1E8.unk_8 != NULL && car->unk_1E8.unk_C != NULL) {
        fn_1_934CC((void *)car, (void *)&car->unk_1E8, "EYE");
    }
    for (i = 0; i < 20; i++) {
        if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
            fn_1_934CC((void *)car, (void *)&car->unk_208[i], "ACCE");
        }
    }
    fn_1_107930(car);
    fn_80008BEC(car->unk_488, 0, 0x30);
    car->unk_4B8 = 0;
    car->unk_4BC = 0;
    car->unk_4C0 = 0;
    car->unk_4C4 = 0;
    if (handle != -1) {
        fn_1_12A2B8(0);
    }
}
#undef lbl_1_bss_960
/* fzgx:end fn_1_8E7D0 */

/* fzgx:begin fn_1_8F198 */
void fn_1_8F198(Fn1_8F198_Object *obj, s32 idx, u32 mask, u32 mask2) {
    char buf[0x40];
    s32 i;
    s32 j;
    u32 size;
    char *name;
    u32 src;
    u32 dst;
    u32 orig;
    u32 total;

    name = ((char **)(((u8 *)lbl_1_data_20D1C)))[idx];
    if (mask == 0) {
        mask = 0x80000000;
    }
    if (mask2 == 0) {
        mask2 = 0x80000000;
    }
    obj->handles[0] = -1;
    obj->handles[1] = -1;
    obj->handles[2] = -1;
    obj->handles[3] = -1;
    obj->handles[4] = -1;

    for (i = 0; i < 5; i++) {
        /* WARNING: compiler-diff device, not original code: __rlwnm keeps retail's `rlwnm.` with the rotate amount in a
              register; `(m >> (31 - i)) & 1` gives subfic/srw/clrlwi. No natural spelling is known (lanes FT, DVcar). */
        if (!__rlwnm(mask, (i + 1) & 0x1F, 31, 31)) {
            continue;
        }
        if (idx == 0x2C || i == 4) {
            continue;
        }
        strcpy(buf, "/chara/arc/");
        strcat(buf, name);
        strcat(buf, "_sel");
        switch (i) {
        case 1:
            strcat(buf, (char *)(((u8 *)lbl_1_data_26D6C)));
            break;
        case 2:
            strcat(buf, (char *)(((u8 *)lbl_1_data_26D54)));
            break;
        case 3:
            strcat(buf, (char *)(((u8 *)lbl_1_data_26D5C)));
            break;
        case 4:
            strcat(buf, (char *)(((u8 *)lbl_1_data_26D64)));
            break;
        }
        strcat(buf, ".arc.lz");
        obj->handles[i] = fn_1_12A32C(buf);
        if (obj->handles[i] == -1) {
            continue;
        }
        if (mask2 == 0x80000000 || mask2 == 0x40000000 || mask2 == 0x20000000 || mask2 == 0x10000000) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(obj->handles[i]);
            fn_1_12AB38((void *)("chara"));
            total = fn_80009FB4(fn_1_12A290(obj->handles[i]));
            orig = total;
            sprintf(buf, "%s%s%s.tpl", name, sDirs[i], sExts[0]);
            dst = fn_1_12A6D8(buf);
            for (j = 0; j < 4; j++) {
                sprintf(buf, "%s%s%s.tpl", name, sDirs[i], sExts[j]);
                src = fn_1_12A6D8(buf);
                size = fn_1_12AAC8(buf);
                /* WARNING: compiler-diff device, not original code: __rlwnm (see above). */
                if (!__rlwnm(mask2, (j + 1) & 0x1F, 31, 31)) {
                    total -= size;
                } else {
                    if (dst != src) {
                        fn_80008BA8((void *)dst, (void *)src, size);
                        DCFlushRange((void *)dst, size);
                    }
                    dst += size;
                }
            }
            if (orig != total) {
                fn_80009CAC(fn_1_12A290(obj->handles[i]), total);
            }
            fn_1_12AB38((void *)(".."));
            fn_1_12A2B8(0);
        }
    }
    fn_1_8E7D0((void *)obj, idx, mask, mask2);
}
/* fzgx:end fn_1_8F198 */

/* fzgx:begin fn_1_8F45C */
void fn_1_8F45C(Fn1_8F45C_Object *obj, s32 idx, u32 mask, u32 mask2) {
    obj->field_4 = -1;
    obj->field_8 = -1;
    obj->field_c = -1;
    obj->field_10 = -1;
    obj->field_14 = -1;
    fn_1_8E7D0((void *)obj, idx, mask, mask2);
}
/* fzgx:end fn_1_8F45C */

/* fzgx:begin fn_1_8F494 */
void fn_1_8F494(Fn1_8F494_Object *obj) {
    s32 i;
    s32 *entry;
    s32 value;
    s32 *entry2;
    s32 k;

    if (obj->active != 0) {
        value = -1;
        entry = &obj->active;
        for (i = 0; i < 5; i++) {
            if (entry[1] != -1) {
                value = obj->entries[i];
                break;
            }
            entry++;
        }
        if (value != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(value);
        } else {
            fn_1_12A2B8(0);
        }
        fn_1_9724C(obj);
        fn_1_107C4C( (Fn1_8F494_Object *)(obj));
        fn_1_966A0((void *)obj);
        fn_1_95EF0((void *)obj);
        fn_1_8F5A4( (Fn1_8F5A4_Object *)(Fn1_8F494_Object *)(obj));
        GXInvalidateTexAll();
        entry2 = (s32 *)obj;
        for (k = 0; k < 5; k++) {
            if (entry2[1] != -1) {
                fn_1_12A734(entry2[1]);
                entry2[1] = -1;
            }
            entry2++;
        }
        if (value != -1) {
            fn_1_12A2B8(0);
        }
        obj->active = 0;
    }
}
/* fzgx:end fn_1_8F494 */

/* fzgx:begin fn_1_8F5A4 */
void fn_1_8F5A4(Fn1_8F5A4_Object *obj) {
    u32 i;

    fn_1_961F0((void *)obj->pad_148);
    fn_1_961F0((void *)obj->pad_168);
    fn_1_961F0((void *)obj->pad_1a8);
    fn_1_961F0((void *)obj->pad_1c8);
    fn_1_961F0((void *)obj->pad_1e8);
    for (i = 0; i < 0x14; i++) {
        fn_1_961F0((void *)obj->entries[i]);
    }
    fn_1_968FC((void *)obj);
}
/* fzgx:end fn_1_8F5A4 */

/* fzgx:begin fn_1_8F62C */
/* Static helper. MWCC inlines it into fn_1_8F62C. The retail link removed its out-of-line copy (strip_allow.txt). */
static void rob_open_lip(Fn8F62CCar *car) {
    f32 saved = car->unk_1C8.unk_8->unk_28;

    car->unk_1C8.unk_8->unk_28 = 100.0f * (1.0f - car->unk_494);
    fn_1_42E74((void *)car->unk_1C8.unk_8);
    car->unk_1C8.unk_8->unk_28 = 1.0f + saved;
}

/* Static helper. MWCC inlines it into fn_1_8F62C. The retail link removed its out-of-line copy (strip_allow.txt). */
static void rob_set_blink_wait(Fn8F62CCar *car) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    car->unk_4B8 = (s32)(180.0f * ((s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f));
}

static inline void fn_1_8F62C_part(Fn8F62CCar *car, Fn8F62CPart *part, u32 index) {
    Fn8F62CResult result;

    if (part->unk_1C != 0) {
        fn_1_42E74((void *)part->unk_8);
        {
            Fn8F62CResult init = {0xFFFF, 0xFFFF, -1.0f, 0xFFFF, 0xFFFF};

            part->unk_10 = init;
        }
        return;
    }
    fn_1_41E34((void *)car->unk_1C, index, (void *)&result);
    if (part->unk_10.unk_2 != result.unk_2 || part->unk_10.unk_8 != result.unk_8 || part->unk_10.unk_4 != result.unk_4) {
        fn_1_933D8((void *)car, (void *)part, result.unk_2 != 0 ? (u16)(result.unk_2 - 1) : 0);
        part->unk_10 = result;
    }
    if (part->unk_10.unk_8 & 2) {
        fn_1_42E74((void *)part->unk_8);
    } else {
        fn_1_43058(part->unk_8, 0, 100, result.unk_4);
    }
}

void fn_1_8F62C(Fn8F62CCar *car) {
    u8 match[20];
    Vec3 vec;
    u32 i;
    void *object;

    if (car == NULL) {
        return;
    }
    if (car->unk_18 & (1U << 31)) {
        return;
    }
    if (car->unk_148.unk_8->unk_40 & 4) {
        fn_1_95158((void *)car);
    }
    for (i = 0; i < 20; i++) {
        if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL
            && ((char *)strstr((void *)(((char *)fn_1_41418((void *)car->unk_208[i].unk_C, car->unk_208[i].unk_0))),
                           (void *)(((char *)fn_1_41418((void *)car->unk_148.unk_C, car->unk_148.unk_0))))) != NULL) {
            match[i] = 1;
        } else {
            match[i] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        if (match[i] && car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
            car->unk_208[i].unk_8->unk_4C = car->unk_148.unk_8->unk_4C;
        }
    }
    if (car->unk_148.unk_8 != NULL && car->unk_148.unk_C != NULL) {
        fn_1_41CB8(car->unk_1C);
        if (car->unk_18 & 0x10000000) {
            object = car->unk_1C->unk_8;
            lbl_8006DAEC();
            lbl_8006D758();
            lbl_8006E0B4(car->unk_A8, car->unk_AC + car->unk_B4, car->unk_B0);
            mathutil_mtxA_rotate_z(car->unk_A4);
            mathutil_mtxA_rotate_y(car->unk_A0);
            mathutil_mtxA_rotate_x(car->unk_A2);
            lbl_8006E14C(car->unk_B8);
            fn_8006E250((void *)&car->unk_4D4, (void *)&vec);
            fn_1_43120(object, 5, &vec);
            lbl_8006DB30();
        }
    }
    if (car->unk_168.unk_8 != NULL && car->unk_168.unk_C != NULL) {
        fn_1_8F62C_part(car, &car->unk_168, 1);
    }
    if (car->unk_188.unk_8 != NULL && car->unk_188.unk_C != NULL) {
        fn_1_8F62C_part(car, &car->unk_188, 0);
    }
    if (car->unk_1A8.unk_8 != NULL && car->unk_1A8.unk_C != NULL) {
        if (strcmp((void *)(((char *)fn_1_41418((void *)car->unk_1A8.unk_C, car->unk_1A8.unk_0))), (void *)((char *)"FACE_LAUGH")) == 0) {
            Fn8F62CModel *model = car->unk_1A8.unk_8;

            if (model->unk_4C >= model->unk_50 - 1.0f) {
                model->unk_4C = model->unk_50 - 1.0f;
            }
        }
        fn_1_8F62C_part(car, &car->unk_1A8, 2);
    }
    for (i = 0; i < 20; i++) {
        if (match[i] && car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
            fn_1_42E74((void *)car->unk_208[i].unk_8);
        }
    }
    if (car->unk_488 != 0
        && (car->unk_1C8.unk_8 == NULL || car->unk_1C8.unk_C == NULL
            || (car->unk_488 != 0 && car->unk_4A0 >= car->unk_4AC - 1))) {
        fn_1_9724C(car);
    }
    if (car->unk_488 != 0) {
        fn_1_97288((void *)car);
    }
    if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL) {
        if (car->unk_488 != 0) {
            if (car->unk_494 > 0.0f) {
                rob_open_lip(car);
            } else {
                car->unk_1C8.unk_8->unk_28 = car->unk_1C8.unk_8->unk_2C;
                fn_1_42E74((void *)car->unk_1C8.unk_8);
            }
        } else {
            fn_1_8F62C_part(car, &car->unk_1C8, 3);
        }
    }
    if (car->unk_1E8.unk_8 != NULL && car->unk_1E8.unk_C != NULL) {
        if (car->unk_4B8 != 0) {
            car->unk_4B8--;
        } else {
            if (car->unk_488 != 0 || *(s16 *)&lbl_1_bss_960 == 1) {
                fn_1_42E74((void *)car->unk_1E8.unk_8);
            } else {
                fn_1_43058(car->unk_1E8.unk_8, car->unk_1E8.unk_8->unk_42, car->unk_1E8.unk_8->unk_44, 0.0f);
            }
            if (car->unk_1E8.unk_8->unk_40 & 4) {
                rob_set_blink_wait(car);
            }
        }
    }
    if (!(car->unk_18 & 0x20000000)) {
        fn_1_107C74(car);
    }
    car->unk_90 = car->unk_8C;
}
/* fzgx:end fn_1_8F62C */

/* fzgx:begin fn_1_8FE74 */
void fn_1_8FE74(Fn8FE74Obj *arg0, Fn8FE74Entry *arg1, s32 arg2) {
    char *name;
    char *fmt;
    s32 i;

    if (arg1->unk_8 == NULL || arg1->unk_C == NULL) {
        return;
    }
    if (arg1 == &arg0->unk_148) {
        name = "body ";
    } else if (arg1 == &arg0->unk_168) {
        name = "handr";
    } else if (arg1 == &arg0->unk_188) {
        name = "handl";
    } else if (arg1 == &arg0->unk_1A8) {
        name = "face ";
    } else if (arg1 == &arg0->unk_1C8) {
        name = "lip  ";
    } else if (arg1 == &arg0->unk_1E8) {
        name = "eye  ";
    } else {
        for (i = 0; i < 20; i++) {
            if (arg1 == &arg0->unk_208[i]) {
                name = "acce ";
                break;
            }
        }
    }
    if (arg2) {
        fmt = ">";
    } else {
        fmt = " ";
    }
    fn_1_A8DD4(fmt);
    fn_1_A8F40(0x33);
    fn_1_A8DD4("%s", name);
    fn_1_A8F40(0xFF);
    fn_1_A8DD4(":[%03d]", arg1->unk_0);
    fn_1_A8F40(0xF3);
    fn_1_A8DD4("[%5.1f/%5.1f]", arg1->unk_8->unk_4C, arg1->unk_8->unk_50);
    fn_1_A8F40(0xFF);
    fn_1_A8DD4("%s \n", fn_1_41418( (Sig_fn_1_41418_Fn41418Data *)(arg1->unk_C), arg1->unk_0));
}
/* fzgx:end fn_1_8FE74 */

/* fzgx:begin fn_1_900B4 */
u32 fn_1_900B4(void) {
    return lbl_1_bss_6E978;
}
/* fzgx:end fn_1_900B4 */

/* fzgx:begin fn_1_900C4 */
EventList *lbl_1_data_27920 = &lbl_1_bss_6E990;
s32 lbl_1_data_27924 = 1;
void fn_1_900C4(void) {
    lbl_1_bss_6E97C = 1;
    lbl_1_bss_6E978 = 0;
    lbl_1_bss_6E980 = 0;
    lbl_1_bss_6E960 = 0;
    lbl_1_bss_6E964 = 0;
    lbl_1_bss_6E968 = 0;
    lbl_1_bss_6E96C = 0;
    lbl_1_data_27924 = 1;
    lbl_1_bss_6E970 = 0;
    lbl_1_bss_6E974 = 0;
    fn_1_95210(lbl_1_data_27920);
}
/* fzgx:end fn_1_900C4 */

/* fzgx:begin fn_1_9012C */


/* fn_1_8F494, inlined */

/* WARNING: compiler-diff device, not original code: static inline copy of fn_1_8F494 (retail inlines it here and in
 * fn_1_913FC). Calling fn_1_8F494 is not auto-inlined (434 words); declaring it `inline` drops its out-of-line copy. */
static inline void fn_1_9012C_inline_8F494(Fn9012CCar *obj) {
    s32 *entry;
    s32 i;
    s32 *entry2;
    s32 value;
    s32 k;

    if (obj->unk_0 != 0) {
        value = -1;
        entry = &obj->unk_0;
        for (i = 0; i < 5; i++) {
            if (entry[1] != -1) {
                value = obj->unk_4[i];
                break;
            }
            entry++;
        }
        if (value != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(value);
        } else {
            fn_1_12A2B8(0);
        }
        fn_1_9724C(obj);
        fn_1_107C4C(obj);
        fn_1_966A0((void *)obj);
        fn_1_95EF0((void *)obj);
        fn_1_8F5A4((Fn1_8F5A4_Object *)obj);
        GXInvalidateTexAll();
        entry2 = (s32 *)obj;
        for (k = 0; k < 5; k++) {
            if (entry2[1] != -1) {
                fn_1_12A734(entry2[1]);
                entry2[1] = -1;
            }
            entry2++;
        }
        if (value != -1) {
            fn_1_12A2B8(0);
        }
        obj->unk_0 = 0;
    }
}

static inline int fn_1_9012C_cycle(Fn9012CCar *car, Fn9012CPart *part, s32 step) {
    s32 count;
    s32 id;

    count = (u16)part->unk_C->unk_0;
    id = part->unk_0 + step;
    id = (id + count) % count;
    if (part->unk_0 != id) {
        fn_1_933D8((void *)car, (void *)part, id & 0xFFFF);
        return 1;
    }
    return 0;
}

void fn_1_9012C(Fn9012CCar *car) {
    Fn8F62CResult result0;
    s32 step;
    s32 id148;
    s32 id168;
    u32 i;
    Fn8F62CResult result1;
    char buf[0x40];
    Fn9012CPart *part;
    u16 ids[20];
    s32 id188;
    s32 lines;
    Fn9012CCamera *cam;
    s32 cur;
    s32 dir;
    s32 id1A8;
    s32 id1E8;
    s32 id1C8;
    s32 same;

    cam = ((Fn9012CCamera *)camera_get_state_object());
    if (lbl_1_bss_6E978 != 0 && lbl_1_bss_6E980 != 0) {
        fn_1_913FC((void *)car);
        return;
    }
    if (lbl_1_bss_6E97C != 0) {
        lbl_1_bss_6E97C = 0;
    }
    lines = 6;
    if (lbl_1_data_27924 != 0) {
        lines = 0x22;
    }
    if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL && ((lbl_1_bss_9F8.unk_8 >> 10) & 1)) {
        strcpy((void *)buf, (void *)lbl_1_data_26D50);
        if (car->unk_88 != 0x2C) {
            sprintf(buf, "%s_%d", lbl_1_data_20D1C[lbl_1_bss_6E964 % 45], lbl_1_bss_6E974 % 16 + 1);
        } else {
            strcpy((void *)buf, (void *)lbl_1_data_26F94[lbl_1_bss_6E974]);
        }
        fn_1_97204((void *)car, (void *)buf);
    }
    if (lbl_1_bss_6E978 != 0 && PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
        lbl_1_bss_6E960 = 0;
        lbl_1_bss_6E978 = 0;
    }
    if (lbl_1_bss_6E978 == 0 && PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
        lbl_1_bss_6E960 = 0;
        lbl_1_bss_6E978 = 1;
    }
    if (lbl_1_bss_6E978 == 0) {
        dir = 0;
    } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 3)) {
        dir = -1;
    } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 2)) {
        dir = 1;
    } else {
        dir = 0;
    }
    while (dir != 0) {
        lbl_1_bss_6E960 = (lbl_1_bss_6E960 + dir + lines) % lines;
        switch (lbl_1_bss_6E960) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            dir = 0;
            break;
        case 7:
            if (car->unk_168.unk_8 != NULL && car->unk_168.unk_C != NULL) {
                dir = 0;
            }
            break;
        case 8:
            if (car->unk_188.unk_8 != NULL && car->unk_188.unk_C != NULL) {
                dir = 0;
            }
            break;
        case 9:
            if (car->unk_1A8.unk_8 != NULL && car->unk_1A8.unk_C != NULL) {
                dir = 0;
            }
            break;
        case 10:
            if (car->unk_1E8.unk_8 != NULL && car->unk_1E8.unk_C != NULL) {
                dir = 0;
            }
            break;
        case 11:
        case 12:
        case 13:
            if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL) {
                dir = 0;
            }
            break;
        default:
            part = &car->unk_208[lbl_1_bss_6E960 - 14];
            if (part->unk_8 != NULL && part->unk_C != NULL) {
                dir = 0;
            }
            break;
        }
    }
    step = 0;
    if (lbl_1_bss_6E978) {
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
            step = 1;
        } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 0)) {
            step = -1;
        }
    } else {
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 2)) {
            step = 1;
        } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 3)) {
            step = -1;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1) || PAD_BIT(lbl_1_bss_D58.unk_10, 0)) {
            lbl_1_bss_6E980 ^= 1;
        }
    }
    if (step != 0) {
        switch (lbl_1_bss_6E960) {
        case 0:
            lbl_1_bss_6E964 = (lbl_1_bss_6E964 + step + 45) % 45;
            break;
        case 1:
            lbl_1_bss_6E968 = (lbl_1_bss_6E968 + step + 5) % 5;
            break;
        case 2:
            lbl_1_bss_6E96C = (lbl_1_bss_6E96C + step + 4) % 4;
            break;
        case 3:
            lbl_1_data_27924 = (lbl_1_data_27924 + 1) % 2;
            break;
        case 4:
            lbl_1_bss_6E970 = (lbl_1_bss_6E970 + 1) % 2;
            break;
        case 5:
            cam->unk_1C += step;
            if (cam->unk_1C > 55.0f) {
                cam->unk_1C = 55.0f;
            }
            if (cam->unk_1C < 30.0f) {
                cam->unk_1C = 30.0f;
            }
            break;
        case 6:
            {
                s32 count = (u16)car->unk_148.unk_C->unk_0;
                s32 id;

                part = &car->unk_148;
                id = part->unk_0 + step;
                id = (id + count) % count;
                if (part->unk_0 != id) {
                    fn_1_933D8((void *)car, (void *)part, id & 0xFFFF);
                }
            }
            break;
        case 7:
            part = &car->unk_168;
            if (part->unk_8 != NULL && part->unk_C != NULL && fn_1_9012C_cycle(car, part, step)) {
                part->unk_1C = 1;
            }
            break;
        case 8:
            part = &car->unk_188;
            if (part->unk_8 != NULL && part->unk_C != NULL && fn_1_9012C_cycle(car, part, step)) {
                part->unk_1C = 1;
            }
            break;
        case 9:
            part = &car->unk_1A8;
            if (part->unk_8 != NULL && part->unk_C != NULL && fn_1_9012C_cycle(car, part, step)) {
                part->unk_1C = 1;
            }
            break;
        case 10:
            part = &car->unk_1E8;
            if (part->unk_8 != NULL && part->unk_C != NULL && fn_1_9012C_cycle(car, part, step)) {
                part->unk_1C = 1;
            }
            break;
        case 11:
            part = &car->unk_1C8;
            if (part->unk_8 != NULL && part->unk_C != NULL && fn_1_9012C_cycle(car, part, step)) {
                part->unk_1C = 1;
            }
            break;
        case 12:
            if (car->unk_88 == 0x2C) {
                lbl_1_bss_6E974 = (lbl_1_bss_6E974 + step + 45) % 45;
            } else {
                lbl_1_bss_6E974 = (lbl_1_bss_6E974 + step + 16) % 16;
            }
            break;
        case 13:
            lbl_1_data_26DD8 = (((lbl_1_data_26DD8 + step) < (1.0f)) ? (1.0f) : (((lbl_1_data_26DD8 + step) > (100.0f)) ? (100.0f) : (lbl_1_data_26DD8 + step)));
            break;
        default:
            part = &car->unk_208[lbl_1_bss_6E960 - 14];
            if (part->unk_8 != NULL && part->unk_C != NULL && fn_1_9012C_cycle(car, part, step)) {
                part->unk_1C = 1;
            }
            break;
        }
    }
    if (lbl_1_bss_6E978 == 0) {
        fn_1_A8EB0(1, 4);
        fn_1_A8F40(0xF3);
        fn_1_A8DD4(">[%2d]%s \n", lbl_1_bss_6E964, lbl_1_data_20B14[lbl_1_bss_6E964]);
        fn_1_A8F40(0xFF);
        for (i = 1; i < 20; i++) {
            fn_1_A8EB0(1, (s16)(i + 4));
            fn_1_A8DD4(" [%2d]%s \n", (lbl_1_bss_6E964 + i) % 45, lbl_1_data_20B14[(lbl_1_bss_6E964 + i) % 45]);
        }
        fn_1_A8EB0(0xF, 4);
        fn_1_A8F40(0xF3);
        if (lbl_1_bss_6E980 != 0) {
            fn_1_A8DD4("-> List Play   (LR button)");
        } else {
            fn_1_A8DD4("-> Normal Play (LR button)");
        }
        fn_1_A8F40(0xFF);
        return;
    }
    cur = lbl_1_bss_6E964;
    lbl_1_bss_6E984 = lbl_1_bss_6E970 != 0;
    if (cur != car->unk_88) {
        same = cur == car->unk_88;
        id1C8 = 0;
        id1E8 = 0;
        id1A8 = 0;
        id188 = 0;
        id168 = 0;
        id148 = 0;
        for (i = 0; i < 20; i++) {
            ids[i] = 0;
        }
        if (same) {
            if (car->unk_148.unk_8 != NULL && car->unk_148.unk_C != NULL) {
                id148 = car->unk_148.unk_0;
            }
            if (car->unk_168.unk_8 != NULL && car->unk_168.unk_C != NULL) {
                id168 = car->unk_168.unk_0;
            }
            if (car->unk_188.unk_8 != NULL && car->unk_188.unk_C != NULL) {
                id188 = car->unk_188.unk_0;
            }
            if (car->unk_1A8.unk_8 != NULL && car->unk_1A8.unk_C != NULL) {
                id1A8 = car->unk_1A8.unk_0;
            }
            if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL) {
                id1C8 = car->unk_1C8.unk_0;
            }
            if (car->unk_1E8.unk_8 != NULL && car->unk_1E8.unk_C != NULL) {
                id1E8 = car->unk_1E8.unk_0;
            }
            for (i = 0; i < 20; i++) {
                if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
                    ids[i] = car->unk_208[i].unk_0;
                }
            }
        }
        fn_1_9012C_inline_8F494(car);
        fn_1_8F198((void *)car, lbl_1_bss_6E964, 0xF8000000, 0xF0000000);
        if (same) {
            if (car->unk_148.unk_8 != NULL && car->unk_148.unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148, id148);
            }
            if (car->unk_168.unk_8 != NULL && car->unk_168.unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_168, id168);
            }
            if (car->unk_188.unk_8 != NULL && car->unk_188.unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_188, id188);
            }
            if (car->unk_1A8.unk_8 != NULL && car->unk_1A8.unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_1A8, id1A8);
            }
            if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_1C8, id1C8);
            }
            if (car->unk_1E8.unk_8 != NULL && car->unk_1E8.unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_1E8, id1E8);
            }
            for (i = 0; i < 20; i++) {
                if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
                    fn_1_933D8((void *)car, (void *)&car->unk_208[i], ids[i]);
                }
            }
        }
    }
    if (lbl_1_bss_6E968 != car->unk_8C) {
        car->unk_8C = lbl_1_bss_6E968;
    }
    if (lbl_1_bss_6E96C != car->unk_98) {
        fn_1_8E728((struct Unk_1_8E728 *)car, lbl_1_bss_6E96C);
    }
    fn_1_41E34((void *)car->unk_1C, 0, (void *)&result0);
    fn_1_41E34((void *)car->unk_1C, 1, (void *)&result1);
    fn_1_41E34((void *)car->unk_1C, 2, (void *)&result1);
    fn_1_41E34((void *)car->unk_1C, 3, (void *)&result1);
    fn_1_41E34((void *)car->unk_1C, 4, (void *)&result1);
    fn_1_41E34((void *)car->unk_1C, 5, (void *)&result1);
    fn_1_A8EB0(1, 3);
    fn_1_A8DD4(lbl_1_bss_6E960 == 0 ? ">" : " ");
    fn_1_A8F40(0xC3);
    fn_1_A8DD4("[%s] \n", lbl_1_data_20B14[lbl_1_bss_6E964]);
    fn_1_A8F40(0xFF);
    fn_1_A8DD4(lbl_1_bss_6E960 == 1 ? ">" : " ");
    fn_1_A8DD4("[%s] \n",
               lbl_1_bss_6E968 == 0 ? "HI"
               : lbl_1_bss_6E968 == 1 ? "3000"
               : lbl_1_bss_6E968 == 2 ? "1000"
               : lbl_1_bss_6E968 == 3 ? "500"
                                  : "100");
    fn_1_A8DD4(lbl_1_bss_6E960 == 2 ? ">" : " ");
    fn_1_A8DD4("chara_col : [%d]\n", lbl_1_bss_6E96C);
    fn_1_A8DD4(lbl_1_bss_6E960 == 3 ? ">" : " ");
    fn_1_A8DD4("char_disp : [%s]\n", lbl_1_data_27924 == 0 ? "ON" : "OFF");
    fn_1_A8DD4(lbl_1_bss_6E960 == 4 ? ">" : " ");
    fn_1_A8DD4("bg_color  : [%s]\n", lbl_1_bss_6E970 != 0 ? "GRAY" : "BLACK");
    fn_1_A8DD4(lbl_1_bss_6E960 == 5 ? ">" : " ");
    fn_1_A8DD4("perspect  : [%4.1f]\n", cam->unk_1C);
    if (lbl_1_data_27924 != 0) {
        fn_1_8FE74((void *)car, (void *)&car->unk_148, lbl_1_bss_6E960 == 6);
        fn_1_8FE74((void *)car, (void *)&car->unk_168, lbl_1_bss_6E960 == 7);
        fn_1_8FE74((void *)car, (void *)&car->unk_188, lbl_1_bss_6E960 == 8);
        fn_1_8FE74((void *)car, (void *)&car->unk_1A8, lbl_1_bss_6E960 == 9);
        fn_1_8FE74((void *)car, (void *)&car->unk_1E8, lbl_1_bss_6E960 == 10);
        fn_1_8FE74((void *)car, (void *)&car->unk_1C8, lbl_1_bss_6E960 == 11);
        if (car->unk_1C8.unk_8 != NULL && car->unk_1C8.unk_C != NULL) {
            fn_1_A8DD4(lbl_1_bss_6E960 == 12 ? ">" : " ");
            if (car->unk_88 == 0x2C) {
                fn_1_A8DD4("[%s] \n", lbl_1_data_26F94[lbl_1_bss_6E974]);
            } else {
                fn_1_A8DD4("[%s_%d] \n", lbl_1_data_20D1C[lbl_1_bss_6E964], lbl_1_bss_6E974 % 16 + 1);
            }
            fn_1_A8DD4(lbl_1_bss_6E960 == 13 ? ">" : " ");
            fn_1_A8DD4("VOL : %4.2f \n", lbl_1_data_26DD8);
        }
        for (i = 0; i < 20; i++) {
            if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
                fn_1_8FE74((void *)car, (void *)&car->unk_208[i], lbl_1_bss_6E960 == i + 14);
            }
        }
    }
    fn_1_8F62C((void *)car);
    car->unk_A8.x = 0.0f;
    car->unk_A8.y = 0.0f;
    car->unk_A8.z = 0.0f;
    if (PAD_BIT(lbl_1_bss_D58.unk_0, 11)) {
        fn_1_96F20((void *)car);
    }
}
/* fzgx:end fn_1_9012C */

/* fzgx:begin fn_1_913FC */

/* WARNING: compiler-diff device, not original code: static inline copy of fn_1_8F494 (retail inlines it here and in
 * fn_1_9012C). Calling fn_1_8F494 is not auto-inlined (434 words); declaring it `inline` drops its out-of-line copy. */
static inline void fn_1_913FC_unload(Fn1913FCCar *car) {
    s32 handle;
    u32 i;
    s32 j;
    u32 k;

    handle = -1;
    for (k = 0; k < 5; k++) {
        if (car->unk_4[k] != -1) {
            handle = car->unk_4[k];
            break;
        }
    }
    if (handle != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(handle);
    } else {
        fn_1_12A2B8(0);
    }
    fn_1_9724C(car);
    fn_1_107C4C(car);
    fn_1_966A0((void *)car);
    fn_1_95EF0((void *)car);
    fn_1_961F0((void *)&car->unk_148[0]);
    fn_1_961F0((void *)&car->unk_148[1]);
    fn_1_961F0((void *)&car->unk_148[3]);
    fn_1_961F0((void *)&car->unk_148[4]);
    fn_1_961F0((void *)&car->unk_148[5]);
    for (i = 0; i < 20; i++) {
        fn_1_961F0((void *)&car->unk_208[i]);
    }
    fn_1_968FC((void *)car);
    GXInvalidateTexAll();
    for (j = 0; j < 5; j++) {
        if (car->unk_4[j] != -1) {
            fn_1_12A734(car->unk_4[j]);
            car->unk_4[j] = -1;
        }
    }
    if (handle != -1) {
        fn_1_12A2B8(0);
    }
    car->unk_0 = 0;
}

void fn_1_913FC(Fn1913FCCar *car) {
    char buf[0x40];
    u16 ids[20];
    Fn1913FCMotion motion0;
    Fn1913FCMotion motion;
    Fn9012CCamera *cam;
    s32 count;
    s32 move;
    s32 step;
    u32 i;
    u32 id148;
    u32 id168;
    u32 id188;
    u32 id1A8;
    u32 id1E8;
    u32 id1C8;
    s32 keep;
    u16 max;
    s32 total;

    cam = camera_get_state_object();
    if (lbl_1_bss_6E97C != 0) {
        lbl_1_bss_6E97C = 0;
    }
    if (lbl_1_data_27924 != 0) {
        count = lbl_1_data_27920->unk_0 * 2 + 7;
    } else {
        count = 6;
    }

    if (car->unk_148[4].unk_8 != NULL && car->unk_148[4].unk_C != NULL && ((lbl_1_bss_9F8.unk_8 >> 10) & 1)) {
        strcpy((void *)buf, (void *)lbl_1_data_26D50);
        if (car->unk_88 != 0x2C) {
            sprintf((void *)buf, (void *)"%s_%d", lbl_1_data_20D1C[lbl_1_bss_6E964 % 45],
                    lbl_1_bss_6E974 % 16 + 1);
        } else {
            strcpy((void *)buf, (void *)lbl_1_data_26F94[lbl_1_bss_6E974]);
        }
        fn_1_97204(car, buf);
    }

    if (lbl_1_bss_6E978 != 0 && PAD_BIT(lbl_1_bss_D58.unk_8, 9) && lbl_1_data_27920->unk_0 == 0) {
        lbl_1_bss_6E960 = 0;
        lbl_1_bss_6E978 = 0;
    } else if (lbl_1_bss_6E978 != 0 && PAD_BIT(lbl_1_bss_D58.unk_8, 9) && lbl_1_data_27920->unk_0 != 0) {
        lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0 - 1] = 0;
        lbl_1_data_27920->unk_18[lbl_1_data_27920->unk_0 - 1] = 0.0f;
        lbl_1_data_27920->unk_40[lbl_1_data_27920->unk_0 - 1] = 0.0f;
        lbl_1_data_27920->unk_0--;
    }
    if (lbl_1_bss_6E978 == 0 && PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
        lbl_1_bss_6E960 = 0;
        lbl_1_bss_6E978 = 1;
    }

    if (lbl_1_bss_6E978 == 0) {
        move = 0;
    } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 3)) {
        move = -1;
    } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 2)) {
        move = 1;
    } else {
        move = 0;
    }
    lbl_1_bss_6E960 = (lbl_1_bss_6E960 + move + count) % count;

    step = 0;
    if (lbl_1_bss_6E978 != 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
            step = 1;
        } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 0)) {
            step = -1;
        }
    } else {
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 2)) {
            step = 1;
        } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 3)) {
            step = -1;
        }
    }

    if (step != 0) {
        switch (lbl_1_bss_6E960) {
        case 0:
            lbl_1_bss_6E964 = (lbl_1_bss_6E964 + step + 45) % 45;
            fn_1_95210(lbl_1_data_27920);
            break;
        case 1:
            lbl_1_bss_6E968 = (lbl_1_bss_6E968 + step + 5) % 5;
            break;
        case 2:
            lbl_1_bss_6E96C = (lbl_1_bss_6E96C + step + 4) % 4;
            break;
        case 3:
            lbl_1_data_27924 = (lbl_1_data_27924 + 1) % 2;
            break;
        case 4:
            lbl_1_bss_6E970 = (lbl_1_bss_6E970 + 1) % 2;
            break;
        case 5:
            cam->unk_1C += step;
            if (cam->unk_1C > 55.0f) {
                cam->unk_1C = 55.0f;
            }
            if (cam->unk_1C < 30.0f) {
                cam->unk_1C = 30.0f;
            }
            break;
        }
    }

    if (lbl_1_bss_6E978 == 0) {
        fn_1_A8EB0(1, 3);
        fn_1_A8F40(0xF3);
        fn_1_A8DD4(">[%2d]%s \n", lbl_1_bss_6E964,
                   lbl_1_data_20B14[lbl_1_bss_6E964]);
        fn_1_A8F40(0xFF);
        for (i = 1; i < 20; i++) {
            fn_1_A8EB0(1, (s16)(i + 3));
            fn_1_A8DD4(" [%2d]%s \n", (lbl_1_bss_6E964 + i) % 45,
                       lbl_1_data_20B14[(lbl_1_bss_6E964 + i) % 45]);
        }
        return;
    }

    lbl_1_bss_6E984 = lbl_1_bss_6E970 != 0;
    if (lbl_1_bss_6E964 != car->unk_88) {
        keep = lbl_1_bss_6E964 == car->unk_88;
        for (i = 0; i < 20; i++) {
            ids[i] = 0;
        }
        id1C8 = 0;
        id1E8 = 0;
        id1A8 = 0;
        id188 = 0;
        id168 = 0;
        id148 = 0;
        if (keep) {
            if (car->unk_148[0].unk_8 != NULL && car->unk_148[0].unk_C != NULL) {
                id148 = car->unk_148[0].unk_0;
            }
            if (car->unk_148[1].unk_8 != NULL && car->unk_148[1].unk_C != NULL) {
                id168 = car->unk_148[1].unk_0;
            }
            if (car->unk_148[2].unk_8 != NULL && car->unk_148[2].unk_C != NULL) {
                id188 = car->unk_148[2].unk_0;
            }
            if (car->unk_148[3].unk_8 != NULL && car->unk_148[3].unk_C != NULL) {
                id1A8 = car->unk_148[3].unk_0;
            }
            if (car->unk_148[4].unk_8 != NULL && car->unk_148[4].unk_C != NULL) {
                id1C8 = car->unk_148[4].unk_0;
            }
            if (car->unk_148[5].unk_8 != NULL && car->unk_148[5].unk_C != NULL) {
                id1E8 = car->unk_148[5].unk_0;
            }
            for (i = 0; i < 20; i++) {
                if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
                    ids[i] = car->unk_208[i].unk_0;
                }
            }
        }
        if (car->unk_0 != 0) {
            fn_1_913FC_unload(car);
        }
        fn_1_8F198((void *)car, lbl_1_bss_6E964, 0xF8000000, 0xF0000000);
        if (keep) {
            if (car->unk_148[0].unk_8 != NULL && car->unk_148[0].unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[0], id148);
            }
            if (car->unk_148[1].unk_8 != NULL && car->unk_148[1].unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[1], id168);
            }
            if (car->unk_148[2].unk_8 != NULL && car->unk_148[2].unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[2], id188);
            }
            if (car->unk_148[3].unk_8 != NULL && car->unk_148[3].unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[3], id1A8);
            }
            if (car->unk_148[4].unk_8 != NULL && car->unk_148[4].unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[4], id1C8);
            }
            if (car->unk_148[5].unk_8 != NULL && car->unk_148[5].unk_C != NULL) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[5], id1E8);
            }
            for (i = 0; i < 20; i++) {
                if (car->unk_208[i].unk_8 != NULL && car->unk_208[i].unk_C != NULL) {
                    fn_1_933D8((void *)car, (void *)&car->unk_208[i], ids[i]);
                }
            }
        }
    }

    if (lbl_1_bss_6E968 != car->unk_8C) {
        car->unk_8C = lbl_1_bss_6E968;
    }
    if (lbl_1_bss_6E96C != car->unk_98) {
        fn_1_8E728((struct Unk_1_8E728 *)car, lbl_1_bss_6E96C);
    }

    fn_1_41E34((void *)car->unk_1C, 0, (void *)&motion0);
    fn_1_41E34((void *)car->unk_1C, 1, (void *)&motion);
    fn_1_41E34((void *)car->unk_1C, 2, (void *)&motion);
    fn_1_41E34((void *)car->unk_1C, 3, (void *)&motion);
    fn_1_41E34((void *)car->unk_1C, 4, (void *)&motion);
    fn_1_41E34((void *)car->unk_1C, 5, (void *)&motion);

    fn_1_A8EB0(1, 3);
    fn_1_A8DD4(lbl_1_bss_6E960 == 0 ? ">" : " ");
    fn_1_A8F40(0xC3);
    fn_1_A8DD4("[%s] \n", lbl_1_data_20B14[lbl_1_bss_6E964]);
    fn_1_A8F40(0xFF);
    fn_1_A8DD4(lbl_1_bss_6E960 == 1 ? ">" : " ");
    fn_1_A8DD4("[%s] \n", lbl_1_bss_6E968 == 0   ? "HI"
                                                : lbl_1_bss_6E968 == 1 ? "3000"
                                                : lbl_1_bss_6E968 == 2 ? "1000"
                                                : lbl_1_bss_6E968 == 3 ? "500"
                                                                                      : "100");
    fn_1_A8DD4(lbl_1_bss_6E960 == 2 ? ">" : " ");
    fn_1_A8DD4("chara_col : [%d]\n", lbl_1_bss_6E96C);
    fn_1_A8DD4(lbl_1_bss_6E960 == 3 ? ">" : " ");
    fn_1_A8DD4("char_disp : [%s]\n", lbl_1_data_27924 == 0 ? "ON" : "OFF");
    fn_1_A8DD4(lbl_1_bss_6E960 == 4 ? ">" : " ");
    fn_1_A8DD4("bg_color  : [%s]\n", lbl_1_bss_6E970 != 0 ? "GRAY" : "BLACK");
    fn_1_A8DD4(lbl_1_bss_6E960 == 5 ? ">" : " ");
    fn_1_A8DD4("perspect  : [%4.1f]\n", cam->unk_1C);
    fn_1_A8EB0(1, 0xB);

    for (i = 0; i < lbl_1_data_27920->unk_0; i++) {
        if (lbl_1_bss_6E960 == i * 2 + 6) {
            if (PAD_BIT(lbl_1_bss_D58.unk_10, 0)) {
                total = car->unk_148[0].unk_C->unk_0 & 0x7FFFFFFF;
                lbl_1_data_27920->unk_2[i] = (lbl_1_data_27920->unk_2[i] - 1 + total) % total;
            } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
                total = car->unk_148[0].unk_C->unk_0 & 0x7FFFFFFF;
                lbl_1_data_27920->unk_2[i] = (lbl_1_data_27920->unk_2[i] + 1 + total) % total;
            }
            if (PAD_BIT(lbl_1_bss_D58.unk_10, 0) || PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
                lbl_1_data_27920->unk_68 = 0.0f;
                lbl_1_data_27920->unk_6C = 0.0f;
                fn_1_933D8((void *)car, (void *)&car->unk_148[0], lbl_1_data_27920->unk_2[i]);
            }
        } else if (lbl_1_bss_6E960 == i * 2 + 7) {
            if (PAD_BIT(lbl_1_bss_D58.unk_10, 0)) {
                if (lbl_1_data_27920->unk_18[i] > 0.0f) {
                    lbl_1_data_27920->unk_18[i] -= 1.0f;
                }
            } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
                if (lbl_1_data_27920->unk_18[i] < 1000.0f) {
                    lbl_1_data_27920->unk_18[i] += 1.0f;
                }
            }
        }
        fn_1_A8DD4(lbl_1_bss_6E960 == i * 2 + 6 ? ">" : " ");
        if (i == lbl_1_data_27920->unk_1) {
            fn_1_A8F40(0xF3);
        }
        fn_1_A8DD4("[%s]\n", fn_1_41418(car->unk_148[0].unk_C, lbl_1_data_27920->unk_2[i]));
        fn_1_A8F40(0xFF);
        fn_1_A8DD4(lbl_1_bss_6E960 == i * 2 + 7 ? ">" : " ");
        fn_1_A8DD4("   \037 %4.1lf\n", lbl_1_data_27920->unk_18[i]);
    }

    if (lbl_1_bss_6E960 == lbl_1_data_27920->unk_0 * 2 + 6) {
        max = 0xFFFF;
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
            max = car->unk_148[0].unk_C->unk_0;
            if (lbl_1_data_27920->unk_0 < 10 &&
                max != lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0]) {
                lbl_1_data_27920->unk_0++;
            }
        } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 0)) {
            max = car->unk_148[0].unk_C->unk_0;
            lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0] =
                (lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0] - 1 + (max + 1)) % (max + 1);
        } else if (PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
            max = car->unk_148[0].unk_C->unk_0;
            lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0] =
                (lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0] + 1 + (max + 1)) % (max + 1);
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 0) || PAD_BIT(lbl_1_bss_D58.unk_10, 1)) {
            if (max != lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0]) {
                fn_1_933D8((void *)car, (void *)&car->unk_148[0], lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0]);
            }
        }
    }
    fn_1_A8DD4(lbl_1_bss_6E960 == lbl_1_data_27920->unk_0 * 2 + 6 ? ">"
                                                                                             : " ");
    if ((car->unk_148[0].unk_C->unk_0 & 0x7FFFFFFF) != lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0]) {
        if (lbl_801A66A0 % 60 > 20) {
            fn_1_A8DD4("[%s]\n",
                       fn_1_41418(car->unk_148[0].unk_C, lbl_1_data_27920->unk_2[lbl_1_data_27920->unk_0]));
        }
        keep = 0;
    } else {
        fn_1_A8DD4("[END]\n");
        keep = 1;
    }
    if (lbl_1_data_27920->unk_0 == 0) {
        keep = 0;
    }
    fn_1_A8EB0(1, 0xA);
    if (keep) {
        if (0.0f == lbl_1_data_27920->unk_6C) {
            fn_1_95238((u32)car, (void *)lbl_1_data_27920);
        } else {
            fn_1_9550C((void *)car, (void *)lbl_1_data_27920);
        }
        fn_1_A8DD4("TOTAL[%5.1lf/%5.1lf]", lbl_1_data_27920->unk_68, lbl_1_data_27920->unk_6C);
    } else {
        lbl_1_data_27920->unk_68 = 0.0f;
        lbl_1_data_27920->unk_6C = 0.0f;
        fn_1_A8DD4("TOTAL[-----/-----]");
    }
    fn_1_8F62C((void *)car);
    fn_1_956B8((void *)lbl_1_data_27920);
    car->unk_A8 = 0.0f;
    car->unk_AC = 0.0f;
    car->unk_B0 = 0.0f;
    if (PAD_BIT(lbl_1_bss_D58.unk_0, 11)) {
        fn_1_96F20((void *)car);
    }
}
/* fzgx:end fn_1_913FC */

/* fzgx:begin fn_1_924CC */
void fn_1_924CC(void) {
    if (lbl_1_bss_6E984 != 0) {
        GXColor color = {0x40, 0x40, 0x40, 0xFF};
        fn_80007AB4((u8 *)&color);
    }
}
/* fzgx:end fn_1_924CC */

/* fzgx:begin fn_1_9250C */
void fn_1_9250C(void *arg0) {
    fn_1_92554((void *)arg0, 0);
}
/* fzgx:end fn_1_9250C */

/* fzgx:begin fn_1_92530 */
void fn_1_92530(void *arg0) {
    fn_1_92554((void *)arg0, 1);
}
/* fzgx:end fn_1_92530 */

/* fzgx:begin fn_1_92554 */
f32 lbl_1_data_27AB0[2] = {0};
f32 lbl_1_data_27AB8[2] = {0};
/* fzgx-allow: S2 pool primer sink */

/* the model a slot points at: its data block at unk_8 */

/* one 0x20-byte model slot of the car object */

/* one 0x24-byte part record */

/* one 0x20-byte item of a node */

static inline void fn_1_92554_place(Car92554 *car) {
    lbl_8006DCA4();
    lbl_8006E0B4(car->unk_A8.x, car->unk_A8.y + car->unk_B4, car->unk_A8.z);
    mathutil_mtxA_rotate_z(car->unk_A4);
    mathutil_mtxA_rotate_y(car->unk_A0);
    mathutil_mtxA_rotate_x(car->unk_A2);
    lbl_8006E14C(car->unk_B8);
}

static inline void fn_1_92554_items(Node92554 *node, Car92554 *car) {
    Item92554 *item;
    u32 e;
    f32 t;

    for (e = 0, item = node->unk_40; e < node->unk_18; item++, e++) {
        if (item->unk_0 & 0x20000) {
            u16 w = item->unk_10;
            u32 m = (w >> 8) & 3;

            t = (car->unk_4BC[m] % 1000) / 1000.0f;
            if (e == 1) {
                lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
                car->unk_4BC[m] += (s32)((lbl_801A63C0 >> 16) & 0x7FFF) % 2 + 18;
            } else {
                lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
                car->unk_4BC[m] += (s32)((lbl_801A63C0 >> 16) & 0x7FFF) % 2 + 30;
            }
            fn_1_5616C(m, 0.0f, t);
        }
    }
}

/* Points *mtx at the locked-cache current matrix.
 * Accepted shortcut (owner 2026-11-24): setting base through this helper keeps it a declared
 * local in its own register (retail r21) instead of a folded constant; no natural form found
 * (cardev/r3_92554: ~40 variants at 12 words). Replaces #pragma opt_dead_assignments off. */
static inline void fn_1_92554_mtxA(u8 **mtx) {
    *mtx = (u8 *)0xE0000000; /* fzgx-allow: A2 locked-cache current matrix address */
}

void fn_1_92554(Car92554 *car, s32 arg1) {
    u32 *o;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    void *nodes;
    Part92554 *part;
    Node92554 *node;
    Model92554 *model;
    Model92554 *a;
    Model92554 *b;
    u32 *out;
    u8 *p;
    u8 *base;
    s32 slot_part;
    s32 found;
    s32 active;
    u8 flag;
    f32 zero;
    f32 t;
    Node92554 *node2;
    void *nodes2;
    char buf[0x100];
    char buf2[0x100];
    char buf3[0x100];

    zero = 0.0f;
    fn_1_56298(zero, zero, zero, zero);
    if (car->unk_18 & 0x40000000) {
        return;
    }
    out = fn_80077A18();
    nodes = car->unk_E4[car->unk_8C];
    for (i = 0; i < car->unk_D0[car->unk_8C]; i++) {
        part = &car->unk_BC[car->unk_8C][i];
        slot_part = 1;
        active = 0;
        if (strcmp(part->unk_4, lbl_1_data_23190) == 0 ||
            strcmp(part->unk_4, lbl_1_data_23420) == 0 ||
            strcmp(part->unk_4, lbl_1_data_236B0) == 0 ||
            strcmp(part->unk_4, lbl_1_data_24318) == 0 ||
            strcmp(part->unk_4, lbl_1_data_24638) == 0 || ((char *)strstr((void *)part->unk_4, (void *)("_CARD_JOKER"))) != NULL ||
            ((char *)strstr((void *)part->unk_4, (void *)("_CARD_ACE"))) != NULL || ((char *)strstr((void *)part->unk_4, (void *)("_BALL"))) != NULL) {
            active = 1;
        }
        if (active == 0 && ((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_22A44)) == NULL) {
            slot_part = 0;
        }
        found = 0;
        for (j = 0; j < 20; j++) {
            if (car->unk_208[j].unk_8 != NULL && car->unk_208[j].unk_C != NULL && slot_part != 0) {
                if (strcmp(part->unk_4, lbl_1_data_23190) == 0) {
                    sprintf(buf, "%s_TUE", ((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)));
                } else {
                    sprintf(buf, "%s%s", ((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)), part->unk_4);
                }
                if (strcmp(((char *)fn_1_41418((void *)car->unk_208[j].unk_C, car->unk_208[j].unk_0)), buf) == 0) {
                    found = 1;
                }
                if (strncmp(((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)), "INT_", 4) == 0 &&
                    ((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_24318)) != NULL) {
                    found = 1;
                }
            }
        }
        if (found == 0 && slot_part != 0) {
            continue;
        }
        if (((char *)strstr((void *)part->unk_4, (void *)("_CARD_JOKER"))) != NULL || ((char *)strstr((void *)part->unk_4, (void *)("_CARD_ACE"))) != NULL ||
            ((char *)strstr((void *)part->unk_4, (void *)("_BALL"))) != NULL) {
            strncpy(buf2, part->unk_4, strlen(part->unk_4) - 2);
            active = 0;
            buf2[strlen(part->unk_4) - 2] = active;
            node = ((Node92554 *)fn_80071268(nodes, (void *)buf2));
        } else {
            node = ((Node92554 *)fn_80071268(nodes, (void *)part->unk_4));
        }
        if (node == NULL) {
            continue;
        }
        fn_1_92554_place(car);
        lbl_8006DAEC();
        active = 0;
        if (slot_part != 0) {
            active = 1;
        } else {
            lbl_8006DFC4(car->unk_148[0].unk_8->unk_8 + part->unk_2 * 0x18C + 0x88);
        }
        if (fn_1_54E34((void *)&node->unk_8, node->unk_14) != 0 || active != 0) {
            active = 1;
        } else {
            active = 0;
        }
        if (part->unk_2 != 0) {
            lbl_8006DC20();
        } else {
            lbl_8006DB30();
        }
        lbl_8006E0A4((void *)&part->unk_18);
        mathutil_mtxA_rotate_z(182.04445f * part->unk_14);
        mathutil_mtxA_rotate_y(182.04445f * part->unk_10);
        mathutil_mtxA_rotate_x(182.04445f * part->unk_C);
        if (((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_272E4)) != NULL &&
            ((char *)strstr((void *)(((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0))), (void *)("INT_"))) != NULL) {
            fn_80077A20(node, 0);
            lbl_8006DFC4(car->unk_148[0].unk_8->unk_8 + 0x214);
            lbl_8006E0B4(0.2025f, 0.065f, 0.085f);
            mathutil_mtxA_rotate_z(-0x8000);
            mathutil_mtxA_rotate_y(0x560B);
            mathutil_mtxA_rotate_x(0x8000);
        } else if ((node->unk_4 & 0xC) && part->unk_8 != NULL) {
            if (((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_22A1C)) != NULL ||
                ((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_24EF0)) != NULL) {
                model = car->unk_148[0].unk_8;
            } else if (((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_22A2C)) != NULL) {
                model = car->unk_148[2].unk_8;
            } else if (((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_22A34)) != NULL) {
                model = car->unk_148[1].unk_8;
            } else if (slot_part != 0) {
                if (strcmp(part->unk_4, lbl_1_data_23190) == 0) {
                    sprintf(buf3, "%s_TUE", ((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)));
                } else {
                    sprintf(buf3, "%s%s", ((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)), part->unk_4);
                }
                for (j = 0; j < 20; j++) {
                    if (car->unk_208[j].unk_8 != NULL && car->unk_208[j].unk_C != NULL &&
                        strcmp(((char *)fn_1_41418((void *)car->unk_208[j].unk_C, car->unk_208[j].unk_0)), buf3) == 0) {
                        model = car->unk_208[j].unk_8;
                        break;
                    }
                }
            } else {
                model = car->unk_148[3].unk_8;
            }
            if (*(s16 *)&lbl_1_bss_960 == 1) {
                b = car->unk_148[5].unk_8;
                a = NULL;
            } else if (car->unk_488 != 0) {
                a = car->unk_148[4].unk_8;
                b = car->unk_148[5].unk_8;
            } else {
                a = NULL;
                b = NULL;
            }
            for (k = 0, o = out; k < node->unk_1E; k++, o++) {
                if (a != NULL && model == car->unk_148[3].unk_8 && part->unk_8[k] >= 1 && part->unk_8[k] <= 18) {
                    p = a->unk_8 + part->unk_8[k] * 0x18C;
                } else if (b != NULL && model == car->unk_148[3].unk_8 && part->unk_8[k] >= 28 &&
                           part->unk_8[k] <= 48) {
                    p = b->unk_8 + part->unk_8[k] * 0x18C - 27 * 0x18C;
                } else {
                    p = model->unk_8 + part->unk_8[k] * 0x18C;
                }
                *o = (u32)(p + 0x88);
            }
        } else if (node->unk_4 & 0xC) {
            fn_80077A20(node, 0);
        }
        if (((char *)strstr((void *)part->unk_4, (void *)lbl_1_data_22A3C)) != NULL) {
            continue;
        }
        if (arg1 != 0 && active == 0) {
            continue;
        }
        fn_80072558();
        if (strcmp(part->unk_4, lbl_1_data_22A44) == 0 && !(car->unk_18 & 0x08000000)) {
            lbl_1_data_277F0 = lbl_1_data_277F0 * 0x676A4B6B + 0x33CB;
            fn_1_56018(0);
            fn_1_92554_items(node, car);
            fn_1_56018(1);
            fn_1_557C4(node);
            fn_1_56018(0);
        } else {
            fn_1_556B8((void *)node);
        }
        if (car->unk_18 & 0x08000000) {
            fn_80077A20(node, 0);
        }
        if (car->unk_88 == 25 && strcmp(part->unk_4, lbl_1_data_23420) == 0) {
            fn_1_977BC((void *)car, (void *)model);
        }
    }
    if (arg1 != 0) {
        fn_1_107F50(car);
    } else {
        fn_1_107F2C(car);
    }
    if (car->unk_88 == 16 && (car->unk_8C == 0 || car->unk_8C == 1)) {
        flag = 1;
        if (strncmp(((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)), "INT_14", 6) == 0) {
            n = car->unk_148[0].unk_8->unk_4C;
            if (n >= 0 && n < 72) {
                node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GUSTER_HELMET")));
            } else if (n >= 72 && n < 164) {
                node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GUSTER_MOHI")));
                flag = 0;
            } else if (n >= 164 && n < 234) {
                node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GUSTER_AFRO")));
                flag = 0;
            } else if (n >= 234 && n < 330) {
                node2 = NULL;
            } else if (n >= 330 && n < 460) {
                node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GUSTER_HELMET")));
            } else {
                node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GUSTER_MOHI_D")));
                flag = 0;
            }
        } else {
            node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GUSTER_HELMET")));
        }
        if (node2 != NULL) {
            base = car->unk_148[0].unk_8->unk_8;
            fn_1_92554_place(car);
            lbl_8006DFC4(base + 0x844);
            lbl_8006E0B4(0.05 * zero, 0.05 * zero, 0.05 * zero);
            mathutil_mtxA_rotate_z(0);
            mathutil_mtxA_rotate_y(0);
            mathutil_mtxA_rotate_x(0);
            fn_80072558();
            n = fn_1_548EC(fn_1_5448C((void *)&node2->unk_8));
            if (flag) {
                fn_1_556B8((void *)node2);
            } else {
                fn_1_55924(node2, n + j);
            }
        }
    }
    if (car->unk_88 == 35 && car->unk_8C == 0 &&
        strncmp(((char *)fn_1_41418((void *)car->unk_148[0].unk_C, car->unk_148[0].unk_0)), "INT_15", 6) == 0) {
        n = car->unk_148[0].unk_8->unk_4C;
        node2 = ((Node92554 *)fn_80071268(car->unk_E4[car->unk_8C], (void *)("GOROH_FIGURE")));
        if (node2 != NULL && n >= 86 && n <= 357) {
            base = car->unk_148[0].unk_8->unk_8;
            fn_1_92554_place(car);
            lbl_8006DFC4(base + 0x17BC);
            lbl_8006E0B4(0.05f, 0.005f, -0.0175f);
            mathutil_mtxA_rotate_z(-0x2000);
            mathutil_mtxA_rotate_y(-0x293E);
            mathutil_mtxA_rotate_x(0xB60);
            fn_80072558();
            fn_1_556B8((void *)node2);
        }
    }
    if (car != NULL && car->unk_88 == 32) {
        Vec3 v = {0.0f, 0.0f, 0.0f};
        Vec3 ra[2] = {{0.004585f, -0.05806f, -0.072865f}, {0.004585f, -0.05806f, 0.02932f}};
        Vec3 rb[2] = {{-0.004585f, -0.05806f, -0.072865f}, {-0.004585f, -0.05806f, 0.02932f}};

        if (car->unk_8C == 0 || car->unk_8C == 1) {
            Vec3 *r;
            f32 *prev;
            s32 w;

            p = car->unk_148[0].unk_8->unk_8;
            nodes2 = car->unk_E4[car->unk_8C];
            for (r = ra, prev = lbl_1_data_27AB0, w = 0,
                 fn_1_92554_mtxA(&base);
                 w < 2; w++, r++, prev++) {
                lbl_8006D9D8(&car->unk_A8);
                lbl_8006DFC4(p + 0x2104);
                psvec_set(&v, *(f32 *)(base + 0x2C), *(f32 *)(base + 0x1C), *(f32 *)(base + 0x0C));
                lbl_8006E0A4((void *)r);
                mathutil_mtxA_rotate_x(lbl_1_bss_6E988);
                fn_80072558();
                t = v.z - *prev;
                *prev = v.z;
                lbl_1_bss_6E988 -= (s16)(65535.0f * t);
                fn_1_556B8((void *)(((Node92554 *)fn_80071268(nodes2, (void *)("SYARIN_R_F")))));
            }
            p = car->unk_148[0].unk_8->unk_8;
            for (r = rb, prev = lbl_1_data_27AB8, w = 0,
                 fn_1_92554_mtxA(&base);
                 w < 2; w++, r++, prev++) {
                lbl_8006D9D8(&car->unk_A8);
                lbl_8006DFC4(p + 0x28C0);
                psvec_set(&v, *(f32 *)(base + 0x2C), *(f32 *)(base + 0x1C), *(f32 *)(base + 0x0C));
                lbl_8006E0A4((void *)r);
                mathutil_mtxA_rotate_x(lbl_1_bss_6E988);
                fn_80072558();
                t = v.z - *prev;
                *prev = v.z;
                lbl_1_bss_6E988 -= (s16)(65535.0f * t);
                fn_1_556B8((void *)(((Node92554 *)fn_80071268(nodes2, (void *)("SYARIN_R_F")))));
            }
        }
    }
}

/* fzgx:end fn_1_92554 */

/* fzgx:begin fn_1_933D8 */
void fn_1_933D8(CarObject *arg0, EventObject *arg1, s32 arg2) {
    EventNode *node;
    s32 value;
    void *target;

    if (arg1 == (EventObject *)((u8 *)arg0 + 0x148)) {
        node = (EventNode *)arg0->field_1c;
        fn_1_95158((void *)arg0);
        if (node != 0) {
            value = fn_1_97174((void *)node, (void *)0, ((void *)fn_1_41418((void *)arg1->field_8->field_24, arg2)));
            if (value < 0) {
                value = 0;
            }
            node->field_12 = 0;
            if ((s32)node->field_26 > 0) {
                target = node->field_28;
            } else {
                target = ((u8 *)node->field_34 + -node->field_4c * 0xc);
            }
            *(u16 *)((u8 *)target + 0xa) = (u16)value;
        }
        fn_1_93734((void *)arg0, (void *)(((void *)fn_1_41418((void *)arg1->field_c, arg2))));
    }
    fn_1_4270C(arg1->field_8, 0, arg2);
    *(u16 *)arg1 = (u16)arg2;
}
/* fzgx:end fn_1_933D8 */

/* fzgx:begin fn_1_934CC */
void fn_1_934CC(CarObject *arg0, EventObject *arg1, char *name) {
    s32 value;
    EventNode *node;
    s32 result;
    void *target;

    result = fn_1_41488(arg1->field_8->field_24, name);
    if (result + 0x10000u == 0xffff) {
        result = 0;
    }
    if (arg1 == (EventObject *)((u8 *)arg0 + 0x148)) {
        node = (EventNode *)arg0->field_1c;
        fn_1_95158( (Fn195158Car *)(CarObject *)(arg0));
        if (node != 0) {
            value = fn_1_97174((void *)node, (void *)0, (void *)fn_1_41418(arg1->field_8->field_24, result & 0xffff));
            if (value < 0) {
                value = 0;
            }
            node->field_12 = 0;
            if ((s32)node->field_26 > 0) {
                target = node->field_28;
            } else {
                target = ((u8 *)node->field_34 + -node->field_4c * 0xc);
            }
            *(u16 *)((u8 *)target + 0xa) = (u16)value;
        }
        fn_1_93734( (void *)((u32)(CarObject *)(arg0)), (void *)((fn_1_41418(arg1->field_c, result & 0xffff))));
    }
    fn_1_4270C(arg1->field_8, 0, result & 0xffff);
    *(u16 *)arg1 = (u16)result;
}
/* fzgx:end fn_1_934CC */

/* fzgx:begin fn_1_935E4 */
// Updates the selected car resource and applies the corresponding handling flags.

void fn_1_935E4(Fn935E4Car *arg0, void *arg1, void *arg2, f32 arg3) {
    u16 flags;
    u32 id;
    u16 short_value;
    Fn935E4Node *node;
    Fn935E4Slot *slot;
    s32 value;

    id = fn_1_41488(((Fn935E4Obj *)arg1)->field_8->field_24, arg2);
    if (id + 0x10000 == 0xffff) {
        id = 0;
    }

    flags = 0;
    if (arg1 == ((u8 *)arg0 + 0x148)) {
        node = arg0->field_1c;
        if (node != 0) {
            value = fn_1_97174( (void *)((EventNode *)(Fn935E4Node *)(node)), (void *)0,
                (void *)fn_1_41418(((Fn935E4Obj *)arg1)->field_8->field_24, id));
            if (value < 0) {
                value = 0;
            }

            short_value = value;
            node->field_12 = 0;
            if ((s32)node->field_26 > 0) {
                slot = node->field_28;
            } else {
                slot = (Fn935E4Slot *)((u8 *)node->field_34
                    + (-node->field_4c) * 0xc);
            }
            slot->field_a = short_value;
        }

        fn_1_943F8(
            (void *)arg0,
            (void *)fn_1_41418(((Fn935E4Obj *)arg1)->field_c, id), arg3);
    }

    if (arg3 > 50.0f) {
        flags |= 0xc0;
    } else {
        flags |= 0x60;
    }

    fn_1_42AD0(
        ((Fn935E4Obj *)arg1)->field_8, 0, id, arg3, flags);
    ((u16 *)arg1)[0] = id;
}
/* fzgx:end fn_1_935E4 */

/* fzgx:begin fn_1_93734 */
static inline char *lookup(PartEntry *tbl, u32 n, u32 kind, u32 idx) {
    u32 j;
    for (j = 0; j < n; j++) {
        if (kind == tbl[j].id && idx == tbl[j].index) {
            return tbl[j].node;
        }
    }
    return 0;
}

/* Hooks a slot up to animation entry ID; slot 0 also retargets the car node. */

#define APPLY(S, ID, F) \
    do { \
        if (S == &car->slots[0]) { \
            EventNode *node = car->node; s32 value; void *target; \
            fn_1_95158((void *)car); \
            if (node != 0) { \
                value = fn_1_97174((void *)node, (void *)0, ((void *)fn_1_41418((void *)((S)->data->field_24), (ID) & 0xffff))); \
                if (value < 0) { \
                    value = 0; \
                } \
                node->field_12 = 0; \
                if ((s32)node->field_26 > 0) { \
                    target = node->field_28; \
                } else { \
                    target = ((u8 *)node->field_34 + -node->field_4c * 0xc); \
                } \
                *(u16 *)((u8 *)target + 0xa) = (u16)value; \
            } \
            fn_1_93734((void *)car, (void *)(((void *)fn_1_41418((void *)((S)->strs), (ID) & 0xffff)))); \
        } \
        fn_1_4270C((S)->data, 0, (ID) & 0xffff); \
        (S)->id = ID; \
        (S)->flag = F; \
    } while (0)

void fn_1_93734(CarObject_93734 *car, void *name) {
    char buf[0x40];
    u8 buf2[0x40];
    u32 id;
    Slot *sa;
    Slot *sc;
    Slot *sd;
    Slot *se;
    Slot *slot;
    Slot *sb;
    u32 i;
    sa = &car->slots[2];
    if (sa->data != 0 && sa->strs != 0) {
        sprintf(buf, "%s_TE_RM", name);
        id = ((int)fn_1_41488((void *)sa->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(sa, id, 1);
        } else {
            strcpy(buf, "TE_RM");
            id = ((int)fn_1_41488((void *)sa->data->field_24, (void *)buf));
            if (id == -1) {
                APPLY(sa, 0, 0);
            } else {
                APPLY(sa, id, 1);
            }
        }
    }

    sb = &car->slots[1];
    if (sb->data != 0 && sb->strs != 0) {
        sprintf(buf, "%s_TE_R", name);
        id = ((int)fn_1_41488((void *)sb->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(sb, id, 1);
        } else {
            strcpy(buf, "TE_R");
            id = ((int)fn_1_41488((void *)sb->data->field_24, (void *)buf));
            if (id == -1) {
                id = 0;
            }
            APPLY(sb, id, 0);
        }
    }

    sc = &car->slots[3];
    if (sc->data != 0 && sc->strs != 0) {
        sprintf(buf, "%s_FACE", name);
        if (((char *)strstr((void *)name, (void *)"INT")) != 0 && car->field_88 != 0x2c) {
            if ((u32)((int)fn_1_41488((void *)sc->data->field_24, (void *)buf)) == -1) {
                sprintf(buf, "INT_FACE_TEST", lbl_1_data_26D50);
            }
        }
        id = ((int)fn_1_41488((void *)sc->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(sc, id, 1);
        } else {
            APPLY(sc, 0, 0);
        }
    }

    sd = &car->slots[4];
    if (sd->data != 0 && sd->strs != 0) {
        sprintf(buf, "%s_LIP", name);
        id = ((int)fn_1_41488((void *)sd->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(sd, id, 1);
        } else {
            APPLY(sd, 0, 0);
        }
    }

    se = &car->slots[5];
    if (se->data != 0 && se->strs != 0) {
        sprintf(buf, "%s_EYE", name);
        id = ((int)fn_1_41488((void *)se->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(se, id, 1);
        } else {
            APPLY(se, 0, 0);
        }
    }

    for (i = 0; i < 20; i++) {
        slot = &(car->slots + 6)[i];
        if (slot->data != 0 && slot->strs != 0) {
            strcpy((char *)buf2, lookup(lbl_1_data_274D4, lbl_1_data_277EC, car->field_88, i));
            if (buf2[0] != 0) {
                sprintf(buf, "%s_%s", name, buf2);
                id = ((int)fn_1_41488((void *)slot->data->field_24, (void *)buf));
                if (id != -1) {
                    APPLY(slot, id, 1);
                } else {
                    APPLY(slot, 0, 0);
                }
            }
        }
    }
}
#undef APPLY
/* fzgx:end fn_1_93734 */

/* fzgx:begin fn_1_943F8 */
/* Hooks a slot up to animation entry ID; slot 0 also retargets the car node. */

#define APPLY(S, ID, F) \
    do { \
        if (S == &car->slots[0]) { \
            EventNode *node = car->node; s32 value; void *target; \
            fn_1_95158((void *)car); \
            if (node != 0) { \
                value = fn_1_97174((void *)node, (void *)0, ((void *)fn_1_41418((void *)((S)->data->field_24), (ID) & 0xffff))); \
                if (value < 0) { \
                    value = 0; \
                } \
                node->field_12 = 0; \
                if ((s32)node->field_26 > 0) { \
                    target = node->field_28; \
                } else { \
                    target = ((u8 *)node->field_34 + -node->field_4c * 0xc); \
                } \
                *(u16 *)((u8 *)target + 0xa) = (u16)value; \
            } \
            fn_1_93734((void *)car, (void *)(((void *)fn_1_41418((void *)((S)->strs), (ID) & 0xffff)))); \
        } \
        fn_1_4270C((S)->data, 0, (ID) & 0xffff); \
        (S)->id = ID; \
        (S)->flag = F; \
    } while (0)

#define APPLYF(S, ID, F) \
    do { flags = 0; \
        if (S == &car->slots[0]) { \
            EventNode *node = car->node; s32 value; void *target; \
            if (node != 0) { \
                value = fn_1_97174((void *)node, (void *)0, ((void *)fn_1_41418((void *)((S)->data->field_24), (ID) & 0xffff))); \
                if (value < 0) { \
                    value = 0; \
                } \
                node->field_12 = 0; \
                if ((s32)node->field_26 > 0) { \
                    target = node->field_28; \
                } else { \
                    target = ((u8 *)node->field_34 + -node->field_4c * 0xc); \
                } \
                *(u16 *)((u8 *)target + 0xa) = (u16)value; \
            } \
            fn_1_943F8((void *)car, (void *)(((void *)fn_1_41418((void *)((S)->strs), (ID) & 0xffff))), blend); \
        } \
        if (blend > 50.0f) flags |= 0xc0; else flags |= 0x60; \
        fn_1_42AD0((S)->data, 0, ID, blend, flags); \
        (S)->id = ID; \
        (S)->flag = F; \
    } while (0)

void fn_1_943F8(CarObject_93734 *car, void *name, f32 blend) {
    char buf[0x40];
    u8 buf2[0x40];
    u16 flags;
    u32 id;
    Slot *sc;
    Slot *sd;
    Slot *se;
    Slot *slot;
    Slot *sa;
    Slot *sb;
    u32 i;
    sa = &car->slots[2];
    if (sa->data != 0 && sa->strs != 0) {
        sprintf(buf, "%s_TE_RM", name);
        id = ((int)fn_1_41488((void *)sa->data->field_24, (void *)buf));
        if (id != -1) {
            APPLYF(sa, id, 1);
        } else {
            u32 fallback;
            strcpy(buf, "TE_RM");
            fallback = ((int)fn_1_41488((void *)sa->data->field_24, (void *)buf));
            if (fallback == -1) fallback = 0;
            APPLYF(sa, fallback, 0);
        }
    }

    sb = &car->slots[1];
    if (sb->data != 0 && sb->strs != 0) {
        sprintf(buf, "%s_TE_R", name);
        id = ((int)fn_1_41488((void *)sb->data->field_24, (void *)buf));
        if (id != -1) {
            APPLYF(sb, id, 1);
        } else {
            u32 fallback;
            strcpy(buf, "TE_R");
            fallback = ((int)fn_1_41488((void *)sb->data->field_24, (void *)buf));
            if (fallback == -1) {
                fallback = 0;
            }
            APPLYF(sb, fallback, 0);
        }
    }

    sc = &car->slots[3];
    if (sc->data != 0 && sc->strs != 0) {
        sprintf(buf, "%s_FACE", name);
        if (((char *)strstr((void *)name, (void *)"INT")) != 0 && car->field_88 != 0x2c) {
            if ((u32)((int)fn_1_41488((void *)sc->data->field_24, (void *)buf)) == -1) {
                sprintf(buf, "INT_FACE_TEST", lbl_1_data_26D50);
            }
        }
        id = ((int)fn_1_41488((void *)sc->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(sc, id, 1);
        } else {
            APPLY(sc, 0, 0);
        }
    }

    sd = &car->slots[4];
    if (sd->data != 0 && sd->strs != 0) {
        sprintf(buf, "%s_LIP", name);
        id = ((int)fn_1_41488((void *)sd->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(sd, id, 1);
        } else {
            APPLY(sd, 0, 0);
        }
    }

    se = &car->slots[5];
    if (se->data != 0 && se->strs != 0) {
        sprintf(buf, "%s_EYE", name);
        id = ((int)fn_1_41488((void *)se->data->field_24, (void *)buf));
        if (id != -1) {
            APPLY(se, id, 1);
        } else {
            APPLY(se, 0, 0);
        }
    }

    for (i = 0; i < 20; i++) {
        slot = &(car->slots + 6)[i];
        if (slot->data != 0 && slot->strs != 0) {
            strcpy((char *)buf2, lookup(lbl_1_data_274D4, lbl_1_data_277EC, car->field_88, i));
            if (buf2[0] != 0) {
                sprintf(buf, "%s_%s", name, buf2);
                id = ((int)fn_1_41488((void *)slot->data->field_24, (void *)buf));
                if (id != -1) {
                    APPLY(slot, id, 1);
                } else {
                    APPLY(slot, 0, 0);
                }
            }
        }
    }
}
#undef APPLY
#undef APPLYF
/* fzgx:end fn_1_943F8 */

/* fzgx:begin fn_1_950E8 */
s32 fn_1_950E8(Fn1950E8Data *data) {
    if (data == 0) {
        return 0;
    }
    return fn_1_41418(data->resource, data->id);
}
/* fzgx:end fn_1_950E8 */

/* fzgx:begin fn_1_95120 */
s32 fn_1_95120(Fn195120Owner *owner) {
    s32 result;

    if (owner == 0) {
        return 0;
    }
    if (owner->data->value_50 >= owner->data->value_4C) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
/* fzgx:end fn_1_95120 */

/* fzgx:begin fn_1_95158 */
void fn_1_95158(Fn195158Car *car) {
    f32 value0;
    f32 value1;

    lbl_8006DAEC();
    lbl_8006D758();
    lbl_8006E0B4(car->unk_A8, car->unk_AC + car->unk_B4, car->unk_B0);
    mathutil_mtxA_rotate_z(car->unk_A4);
    mathutil_mtxA_rotate_y(car->unk_A0);
    mathutil_mtxA_rotate_x(car->unk_A2);
    lbl_8006E14C(car->unk_B8);
    lbl_8006DFC4((void *)&car->unk_150->unk_08->unk_88);
    value0 = ((Fn195158Object *)lbl_801A6D00)->unk_0C;
    value1 = ((Fn195158Object *)lbl_801A6D00)->unk_2C;
    lbl_8006DB30();
    car->unk_A8 = value0;
    car->unk_B0 = value1;
}
/* fzgx:end fn_1_95158 */

/* fzgx:begin fn_1_95210 */
void fn_1_95210(void *arg0) {
    fn_80008BEC((void *)arg0, 0, 0x70);
}
/* fzgx:end fn_1_95210 */

/* fzgx:begin fn_1_95238 */
static inline void fn_1_95238_setPart(u32 arg0, u16 id) {
    s32 v7;
    void *v9;
    u32 mtx;
    f32 z;
    f32 x;
    u32 node;

    node = *(u32 *)((u8 *)arg0 + 0x1c);
    lbl_8006DAEC();
    lbl_8006D758();
    lbl_8006E0B4(*(f32 *)(arg0 + 0xa8), (*(f32 *)((u8 *)arg0 + 0xac) + *(f32 *)((u8 *)arg0 + 0xb4)), *(f32 *)(arg0 + 0xb0));
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 0xa4));
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 0xa0));
    mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg0 + 0xa2));
    lbl_8006E14C(*(f32 *)((u8 *)arg0 + 0xb8));
    lbl_8006DFC4((void *)((*(u32 *)((u8 *)*(u32 *)(arg0 + 0x150) + 8) + 0x88)));
    mtx = (u32)lbl_801A6D00;
    x = *(f32 *)(mtx + 12);
    z = *(f32 *)(mtx + 44);
    lbl_8006DB30();
    *(f32 *)((u8 *)arg0 + 0xa8) = x;
    *(f32 *)((u8 *)arg0 + 0xb0) = z;
    if (node) {
        v7 = fn_1_97174((void *)node, (void *)0, (char *)fn_1_41418((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)*(u32 *)(arg0 + 0x150) + 0x24), id));
        if (v7 < 0) {
            v7 = 0;
        }
        *(u16 *)((u8 *)node + 0x12) = 0;
        if ((s32)*(u8 *)(node + 0x26) > 0) {
            v9 = *(void **)(node + 0x28);
        } else {
            v9 = (void *)(*(u32 *)(node + 0x34) + (-(s32)*(u8 *)(node + 0x4c)) * 12);
        }
        *(u16 *)((u8 *)v9 + 0xa) = (u16)v7;
    }
    fn_1_93734((void *)arg0, (void *)fn_1_41418((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)arg0 + 0x154), id));
    fn_1_4270C((void *)*(u32 *)(arg0 + 0x150), 0, id);
    *(u16 *)((u8 *)arg0 + 0x148) = id;
}

void fn_1_95238(u32 arg0, EventList_95158 *arg1) {
    u8 *v2;
    u8 *v1;
    u32 v0;

    arg1->field_1 = 0;
    arg1->field_68 = 0.0f;
    arg1->field_6c = 0.0f;
    v2 = (u8 *)arg1;
    v1 = (u8 *)arg1;
    v0 = 0;
    while (v0 < arg1->count) {
        fn_1_95238_setPart(arg0, *(u16 *)(v2 + 2));
        arg1->field_6c = arg1->field_6c + *(f32 *)((u8 *)*(u32 *)(arg0 + 0x150) + 0x50);
        *(f32 *)(v1 + 0x40) = *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x50);
        v2 += 2;
        v1 += 4;
        v0++;
    }
    fn_1_95238_setPart(arg0, *(u16 *)((u8 *)arg1 + 2));
}
/* fzgx:end fn_1_95238 */

/* fzgx:begin fn_1_9550C */
void fn_1_9550C(Owner *owner, Config *config) {
    s32 tmp_ra2;
    f32 value;
    s32 tmp_ra1;
    u16 flags;
    u16 id;

    value = config->value;
    {
        u32 i;
        for (i = 0; i < config->count; i++) {
            Node *state;
            f32 current_value;

            value -= config->field_40[i];
            if (value < (0.0f)) {
                tmp_ra1 = config->current;

                if (tmp_ra1 == i) {
                    break;
                }
                if (i != 0) {
                    owner->field_150->field_28 = (0.0f);
                    owner->field_150->field_2c = config->field_14[i];
                }
                state = owner->field_1c;
                current_value = owner->field_150->field_2c;
                id = config->ids[i];
                flags = 0;
                if (state != 0) {
                    void *target;
                    s32 result;

                    result = fn_1_97174( (void *)((EventNode *)(Node *)(state)), (void *)0, (void *)fn_1_41418(owner->field_150->field_24, id));
                    if (result < 0) {
                        result = 0;
                    }
                    state->field_12 = 0;
                    tmp_ra2 = state->field_26;
                    if (tmp_ra2 > 0) {
                        target = state->field_28;
                    } else {
                        target = ((u8 *)state->field_34 + -state->field_4c * 0xc);
                    }
                    *(u16 *)((u8 *)target + 0xa) = (u16)result;
                }
                fn_1_943F8((void *)((Fn935E4Car *)(owner)), (void *)fn_1_41418(owner->field_154, id), current_value);
                if (current_value > (50.0f)) {
                    flags |= 0xc0;
                } else {
                    flags |= 0x60;
                }
                fn_1_42AD0( (OutData *)(owner->field_150), 0, id, current_value, flags);
                owner->field_148 = id;
                config->current = i;
                break;
            }
        }
    }
}
/* fzgx:end fn_1_9550C */

/* fzgx:begin fn_1_956B8 */
void fn_1_956B8(Fn1956B8Data *data) {
    data->value += 1.0f;
    if (data->value >= data->limit) {
        data->value -= data->limit;
    }
}
/* fzgx:end fn_1_956B8 */

/* fzgx:begin fn_1_956EC */
/* Retail layout of the car.c .data section (lbl_1_data_209C0). */

static inline char *fn_1_956EC_lookup(u32 id, u32 index) {
    u32 i;

    for (i = 0; i < lbl_1_data_277EC; i++) {
        if (id == lbl_1_data_274D4[i].id && index == lbl_1_data_274D4[i].index) {
            return lbl_1_data_274D4[i].name;
        }
    }
    return NULL;
}

void fn_1_956EC(s32 id, u32 mask) {
    u32 off;
    char *name;
    u32 hi;
    u32 i;
    s32 special;
    char buf[64];

    off = id * 4;
    name = *(char **)((u8 *)lbl_1_data_20D1C + off);
    fn_1_12AB38((void *)"motion");
    sprintf(buf, "%s.skl", name);
    fn_1_465D0(buf, 1);

    special = id == 0x15 || id == 0x29 || id == 0x21 || id == 0x2a || id == 0x2b;
    if ((mask & (special ? (7u << 29) : (3u << 30))) &&
        (*(u32 *)((u8 *)lbl_1_data_26674 + off) & 0x40000000)) {
        sprintf(buf, "%s_handr.skl", name);
        fn_1_465D0(buf, 1);
        sprintf(buf, "%s_handl.skl", name);
        fn_1_465D0(buf, 1);
    }
    hi = mask & (3u << 30);
    if (hi && (*(u32 *)((u8 *)lbl_1_data_26674 + off) & 0x20000000)) {
        sprintf(buf, "%s_face.skl", name);
        fn_1_465D0(buf, 1);
    }
    if (hi && (*(u32 *)((u8 *)lbl_1_data_26674 + off) & 0x10000000)) {
        sprintf(buf, "%s_lip.skl", name);
        fn_1_465D0(buf, 1);
    }
    if (hi && (*(u32 *)((u8 *)lbl_1_data_26674 + off) & 0x08000000)) {
        sprintf(buf, "%s_eye.skl", name);
        fn_1_465D0(buf, 1);
    }
    if ((mask & (7u << 29)) && (*(u32 *)((u8 *)lbl_1_data_26674 + off) & 0x04000000)) {
        for (i = 0; i < 20; i++) {
            sprintf(buf, "%s.skl", fn_1_956EC_lookup(id, i));
            if (strcmp(buf, ".skl")) {
                fn_1_465D0(buf, 1);
            }
        }
    }
    fn_1_12AB38((void *)"..");
}
/* fzgx:end fn_1_956EC */

/* fzgx:begin fn_1_95950 */
#define lbl_1_bss_960 (*(s16 *)&lbl_1_bss_960)

void fn_1_95950(u32 arg0) {
    Obj_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    u32 *v0;
    u32 v2;
    u32 v9;
    u32 v16;
    u32 v1;
    u32 v18;
    u32 v3;
    s32 special;
    s32 v4;
    u32 mask;
    u32 name;
    struct { u32 a[16]; } loc_8;
    v0 = (u32 *)(lbl_1_data_20D1C);
    v1 = *(u32 *)(arg0 + 0x94);
    v2 = v0[*(u32 *)(arg0 + 0x88)];
    fn_1_12AB38("motion");
    sprintf((char *)&loc_8, "%s.skl", v2);
    fn_1_12A8A4(&loc_8, (void *)(arg0 + 0x14c));
    *(u32 *)((u8 *)arg0 + 0x150) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)arg0 + 0x14c) * 0x18c + 0x70, "rob.c", 0xae0));
    v3 = *(u32 *)(arg0 + 0x150);
    fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(arg0 + 0x14c));
    v4 = *(s32 *)(arg0 + 0x88);
    special = isSpecial(v4);
    mask = special ? 0xe0000000 : ~0x3fffffffU;
    if ((v1 & mask) && (lbl_1_data_26674[*(u32 *)(arg0 + 0x88)] & 0x40000000)) {
        sprintf((char *)&loc_8, "%s_handr.skl", v2);
        if (fn_1_12A8A4(&loc_8, (void *)(arg0 + 0x16c))) {
            *(u32 *)((u8 *)arg0 + 0x170) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)arg0 + 0x16c) * 0x18c + 0x70, "rob.c", 0xaef));
            v3 = *(u32 *)(arg0 + 0x170);
            fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(arg0 + 0x16c));
        }
        sprintf((char *)&loc_8, "%s_handl.skl", v2);
        if (fn_1_12A8A4(&loc_8, (void *)(arg0 + 0x18c))) {
            *(u32 *)((u8 *)arg0 + 0x190) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)arg0 + 0x18c) * 0x18c + 0x70, "rob.c", 0xaf6));
            v3 = *(u32 *)(arg0 + 0x190);
            fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(arg0 + 0x18c));
            fn_1_426AC((Sig_fn_1_426AC_Fn1426ACObject *)*(u32 *)(arg0 + 0x190), lbl_1_data_26CC8);
            v3 = *(u32 *)(arg0 + 0x190);
            *(u16 *)((u8 *)v3 + 2) |= 2;
        }
    }
    v9 = v1 & ~0x3fffffffU;
    if (v9 && (lbl_1_data_26674[*(u32 *)(arg0 + 0x88)] & 0x20000000)) {
        sprintf((char *)&loc_8, "%s_face.skl", v2);
        if (fn_1_12A8A4(&loc_8, (void *)(arg0 + 0x1ac))) {
            *(u32 *)((u8 *)arg0 + 0x1b0) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)arg0 + 0x1ac) * 0x18c + 0x70, "rob.c", 0xb03));
            v3 = *(u32 *)(arg0 + 0x1b0);
            fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(arg0 + 0x1ac));
        }
    }
    if (v9 && (lbl_1_data_26674[*(u32 *)(arg0 + 0x88)] & 0x10000000)) {
        sprintf((char *)&loc_8, "%s_lip.skl", v2);
        if (fn_1_12A8A4(&loc_8, (void *)(arg0 + 0x1cc))) {
            *(u32 *)((u8 *)arg0 + 0x1d0) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)arg0 + 0x1cc) * 0x18c + 0x70, "rob.c", 0xb0d));
            v3 = *(u32 *)(arg0 + 0x1d0);
            fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(arg0 + 0x1cc));
        }
    }
    if (v9 && (lbl_1_data_26674[*(u32 *)(arg0 + 0x88)] & 0x8000000)) {
        sprintf((char *)&loc_8, "%s_eye.skl", v2);
        if (fn_1_12A8A4(&loc_8, (void *)(arg0 + 0x1ec))) {
            *(u32 *)((u8 *)arg0 + 0x1f0) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)arg0 + 0x1ec) * 0x18c + 0x70, "rob.c", 0xb17));
            v3 = *(u32 *)(arg0 + 0x1f0);
            fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(arg0 + 0x1ec));
        }
    }
    if ((v1 & 0xe0000000) && (lbl_1_data_26674[*(u32 *)(arg0 + 0x88)] & 0x4000000)) {
        v16 = arg0;
        p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
        for (v18 = 0; v18 < 20; v18++, v16 += 0x20) {
            v4 = *(s32 *)(arg0 + 0x88);
            if (v4 == 34 && *(s32 *)(arg0 + 0x8c) == 2 && lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) {
                if (v18 != 1 && v18 != 5 && v18 != 9 && v18 != 11 && v18 != 13 && v18 != 15) continue;
            } else if (v4 == 34 && *(s32 *)(arg0 + 0x8c) == 1 && lbl_1_bss_960 == 14) {
                if (v18 - 1 > 3 && fn_15_5864() == 4) continue;
            } else if (v4 == 19 && *(s32 *)(arg0 + 0x8c) == 2 && lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
            name = (u32)findPart(*(u32 *)(arg0 + 0x88), v18);
            sprintf((char *)&loc_8, "%s.skl", name);
            if (strcmp((char *)&loc_8, "san_board.skl") == 0 || strcmp((char *)&loc_8, "gen_board.skl") == 0 || strcmp((char *)&loc_8, "goma_board.skl") == 0) {
                *(u32 *)((u8 *)v16 + 0x210) = 0;
            } else if (strcmp((char *)&loc_8, ".skl") != 0 && fn_1_12A9BC(&loc_8, (void *)(v16 + 0x20c))) {
                *(u32 *)((u8 *)v16 + 0x210) = ((u32)fn_1_4630(lbl_801A6410, *(u16 *)*(u32 *)((u8 *)v16 + 0x20c) * 0x18c + 0x70, "rob.c", 0xb30));
                v3 = *(u32 *)(v16 + 0x210);
                fn_1_4247C((void *)v3, v3 + 0x70, (void *)*(u32 *)(v16 + 0x20c));
            }
        }
    }
    fn_1_12AB38("..");
}
#undef lbl_1_bss_960
/* fzgx:end fn_1_95950 */

/* fzgx:begin fn_1_95EF0 */
/* VIEWS */
void fn_1_95EF0(void *arg0) {
    void *var_r28;
    void *temp_r3_7;
    void *temp_r3_6;
    void *temp_r3_5;
    void *temp_r3_4;
    void *temp_r3_3;
    void *temp_r3_2;
    void *temp_r3;
    u32 var_r27;
    u32 temp_r4_7;
    u32 temp_r4_6;
    u32 temp_r4_5;
    u32 temp_r4_4;
    u32 temp_r4_3;
    u32 temp_r4_2;
    u32 temp_r4;

    temp_r3 = (*(void **)((u8 *)(arg0) + 332));
    if (temp_r3 != NULL) {
        fn_1_12ABB4(temp_r3);
        (*(void **)((u8 *)(arg0) + 332)) = NULL;
    }
    temp_r4 = *(u32 *)((u8 *)(arg0) + 336);
    if (temp_r4 != 0) {
        fn_1_46B4(lbl_801A6410, temp_r4, (void *)((const char *)("rob.c")), 0xB44);
        (*(u32 *)((u8 *)(arg0) + 336)) = 0U;
    }
    temp_r3_2 = (*(void **)((u8 *)(arg0) + 364));
    if (temp_r3_2 != NULL) {
        fn_1_12ABB4(temp_r3_2);
        (*(void **)((u8 *)(arg0) + 364)) = NULL;
    }
    temp_r4_2 = *(u32 *)((u8 *)(arg0) + 368);
    if (temp_r4_2 != 0) {
        fn_1_46B4(lbl_801A6410, temp_r4_2, (void *)((const char *)("rob.c")), 0xB49);
        (*(u32 *)((u8 *)(arg0) + 368)) = 0U;
    }
    temp_r3_3 = (*(void **)((u8 *)(arg0) + 396));
    if (temp_r3_3 != NULL) {
        fn_1_12ABB4(temp_r3_3);
        (*(void **)((u8 *)(arg0) + 396)) = NULL;
    }
    temp_r4_3 = *(u32 *)((u8 *)(arg0) + 400);
    if (temp_r4_3 != 0) {
        fn_1_46B4(lbl_801A6410, temp_r4_3, (void *)((const char *)("rob.c")), 0xB4B);
        (*(u32 *)((u8 *)(arg0) + 400)) = 0U;
    }
    temp_r3_4 = (*(void **)((u8 *)(arg0) + 428));
    if (temp_r3_4 != NULL) {
        fn_1_12ABB4(temp_r3_4);
        (*(void **)((u8 *)(arg0) + 428)) = NULL;
    }
    temp_r4_4 = *(u32 *)((u8 *)(arg0) + 432);
    if (temp_r4_4 != 0) {
        fn_1_46B4(lbl_801A6410, temp_r4_4, (void *)((const char *)("rob.c")), 0xB4D);
        (*(u32 *)((u8 *)(arg0) + 432)) = 0U;
    }
    temp_r3_5 = (*(void **)((u8 *)(arg0) + 460));
    if (temp_r3_5 != NULL) {
        fn_1_12ABB4(temp_r3_5);
        (*(void **)((u8 *)(arg0) + 460)) = NULL;
    }
    temp_r4_5 = *(u32 *)((u8 *)(arg0) + 464);
    if (temp_r4_5 != 0) {
        fn_1_46B4(lbl_801A6410, temp_r4_5, (void *)((const char *)("rob.c")), 0xB4F);
        (*(u32 *)((u8 *)(arg0) + 464)) = 0U;
    }
    temp_r3_6 = (*(void **)((u8 *)(arg0) + 492));
    if (temp_r3_6 != NULL) {
        fn_1_12ABB4(temp_r3_6);
        (*(void **)((u8 *)(arg0) + 492)) = NULL;
    }
    temp_r4_6 = *(u32 *)((u8 *)(arg0) + 496);
    if (temp_r4_6 != 0) {
        fn_1_46B4(lbl_801A6410, temp_r4_6, (void *)((const char *)("rob.c")), 0xB51);
        (*(u32 *)((u8 *)(arg0) + 496)) = 0U;
    }
    var_r28 = arg0;
    var_r27 = 0U;
    do {
        temp_r3_7 = (*(void **)((u8 *)(var_r28) + 524));
        if (temp_r3_7 != NULL) {
            fn_1_12ABB4(temp_r3_7);
            (*(void **)((u8 *)(var_r28) + 524)) = NULL;
        }
        temp_r4_7 = *(u32 *)((u8 *)(var_r28) + 528);
        if (temp_r4_7 != 0) {
            fn_1_46B4(lbl_801A6410, temp_r4_7, (void *)((const char *)("rob.c")), 0xB54);
            (*(u32 *)((u8 *)(var_r28) + 528)) = 0U;
        }
        var_r27 += 1;
        var_r28 = ((u8 *)(var_r28) + 0x20);
    } while (var_r27 < 0x14U);
}
/* fzgx:end fn_1_95EF0 */

/* fzgx:begin fn_1_96130 */
void fn_1_96130(void *arg0) {
    fn_1_12AB38((void *)"motion");
    fn_1_465D0(arg0, 1);
    fn_1_12AB38((void *)"..");
}
/* fzgx:end fn_1_96130 */

/* fzgx:begin fn_1_9617C */
// Loads the car resource, updates its model data, and restores shared state.

void fn_1_9617C(CarResourceState *car, void *resource) {
    fn_1_12AB38((void *)"motion");
    if (fn_1_12A8A4( (void *)((u32)(resource)), (void *)&car->unk_0C) != 0) {
        fn_1_41328(car->unk_0C);
        fn_1_426E4(car->unk_08, car->unk_0C);
    }
    fn_1_12AB38((void *)"..");
}
/* fzgx:end fn_1_9617C */

/* fzgx:begin fn_1_961F0 */
void fn_1_961F0(Fn1961F0Owner *owner) {
    if (owner->resource != 0) {
        fn_1_12ABB4((void *)owner->resource);
        owner->resource = 0;
    }
}
/* fzgx:end fn_1_961F0 */

/* fzgx:begin fn_1_96230 */
/* bit n of a mask counted from the most significant bit */

/* WARNING: compiler-diff device, not original code: __rlwnm (see fn_1_8E728). */
#define MASK_BIT(mask, n) __rlwnm((mask), ((n) + 1) & 0x1F, 31, 31)

void fn_1_96230(Fn196230Obj *obj, s32 idx, u32 mask1, u32 mask2, s32 flag) {
    char buf[0x40];
    s32 ok[5][4];
    const char *name;
    s32 i;
    s32 j;
    s32 id;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            ok[i][j] = 0;
        }
    }
    name = lbl_1_data_20D1C[idx];
    for (i = 0; i < 5; i++) {
        if (!MASK_BIT(mask1, i)) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            if (!MASK_BIT(mask2, j)) {
                continue;
            }
            if (flag == 0 && obj->ids[i] != -1 &&
                (mask2 == 0x80000000 || mask2 == 0x40000000 || mask2 == 0x20000000 ||
                 mask2 == 0x10000000)) {
                sprintf(buf, "%s%s%s.tpl", name, sDirs[i], sExts[0]);
            } else {
                sprintf(buf, "%s%s%s.tpl", name, sDirs[i], sExts[j]);
            }
            if (flag) {
                fn_1_12AB38("chara");
                ok[i][j] = fn_1_465D0(buf, 1) >= 0;
                fn_1_12AB38("..");
            } else {
                void *file;
                if (obj->ids[i] != -1) {
                    fn_1_12A2B8(1);
                    fn_1_12A2D0(obj->ids[i]);
                } else {
                    fn_1_12A2B8(0);
                }
                fn_1_12AB38("chara");
                file = ((void *)fn_1_12AC00((void *)buf));
                obj->files[i][j] = file;
                ok[i][j] = ((u32)file | -(u32)file) >> 31;
                fn_1_12AB38("..");
            }
            if (ok[i][j] == 0) {
                sprintf(buf, "%s%s.tpl", name, sDirs[i]);
                if (flag) {
                    fn_1_12AB38("chara");
                    ok[i][j] = fn_1_465D0(buf, 1) >= 0;
                    fn_1_12AB38("..");
                } else {
                    void *file;
                    if (obj->ids[i] != -1) {
                        fn_1_12A2B8(1);
                        fn_1_12A2D0(obj->ids[i]);
                    } else {
                        fn_1_12A2B8(0);
                    }
                    fn_1_12AB38("chara");
                    file = ((void *)fn_1_12AC00((void *)buf));
                    obj->files[i][j] = file;
                    ok[i][j] = ((u32)file | -(u32)file) >> 31;
                    fn_1_12AB38("..");
                }
            }
        }
        for (j = 0; j < 4; j++) {
            if (ok[i][j]) {
                sprintf(buf, "%s%s.gma", name, sPacks[i]);
                if (flag) {
                    fn_1_12AB38("chara");
                    fn_1_465D0(buf, 1);
                    fn_1_12AB38("..");
                } else {
                    if (obj->ids[i] != -1) {
                        fn_1_12A2B8(1);
                        fn_1_12A2D0(obj->ids[i]);
                    } else {
                        fn_1_12A2B8(0);
                    }
                    fn_1_12AB38("chara");
                    obj->handles[i] = ((u32)fn_1_12ADA0((void *)buf, (void *)obj->files[i][j]));
                    fn_1_12AB38("..");
                }
                break;
            }
        }
    }
    if (flag == 0) {
        Fn196230Obj *scan;
        id = -1;
        for (j = 0, scan = obj; j < 5; scan = (Fn196230Obj *)((u8 *)scan + 4), j++) {
            if (scan->ids[0] != -1) {
                id = obj->ids[j];
                break;
            }
        }
        if (id != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(id);
        } else {
            fn_1_12A2B8(0);
        }
    }
}
#undef MASK_BIT
/* fzgx:end fn_1_96230 */

/* fzgx:begin fn_1_96630 */
/* Retail .data 27C50..27C87 holds these five formats right after fn_1_96230's strings and no retail function
   reads them: a static loader of the coin models that the retail link removed (strip.txt). Its body is a
   reconstruction from its strings only. */
static void rob_load_coin_models(char *buf, char *name) {
    sprintf(buf, "%s_100.gma", name);
    sprintf(buf, "%s_500.gma", name);
    sprintf(buf, "%s_1000.gma", name);
    sprintf(buf, "%s_3000.gma", name);
    sprintf(buf, "%s.gma", name);
}
void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2) {
    fn_1_96230((void *)object, (s32)object->value_88, (u32)arg1, (u32)arg2, 0);
}
/* fzgx:end fn_1_96630 */

/* fzgx:begin fn_1_96664 */
void fn_1_96664(void *arg0, void *arg1, void *arg2) {
    fn_1_96230((void *)0, (s32)arg0, (u32)arg1, (u32)arg2, 1);
}
/* fzgx:end fn_1_96664 */

/* fzgx:begin fn_1_966A0 */
void fn_1_966A0(Fn1966A0Object *object) {
    u8 *slot;
    u8 *group;
    u8 *outer;
    int i;
    int j;
    s32 value;
    u8 *walk;

    group = (u8 *)object;
    outer = (u8 *)object;
    for (i = 0; i < 5; i++) {
        slot = group;
        for (j = 0; j < 4; j++) {
            if (((Fn1966A0Object *)slot)->resource_f8 != 0) {
                if (*(s32 *)(outer + 4) != -1) {
                    fn_1_12A2D0(*(s32 *)(outer + 4));
                }
                fn_80071718(((Fn1966A0Object *)slot)->resource_f8);
                ((Fn1966A0Object *)slot)->resource_f8 = 0;
            }
            slot += 4;
        }
        if (((Fn1966A0Object *)outer)->resource_e4 != 0) {
            if (*(s32 *)(outer + 4) != -1) {
                fn_1_12A2D0(*(s32 *)(outer + 4));
            }
            fn_800711A8(((Fn1966A0Object *)outer)->resource_e4);
            ((Fn1966A0Object *)outer)->resource_e4 = 0;
        }
        group += 0x10;
        outer += 4;
    }

    value = -1;
    walk = (u8 *)object;
    for (i = 0; i < 5; i++) {
        if (*(s32 *)(walk + 4) != -1) {
            value = object->entries[i + 1];
            break;
        }
        walk += 4;
    }
    if (value != -1) {
        fn_1_12A2D0(value);
    }
}
/* fzgx:end fn_1_966A0 */

/* fzgx:begin fn_1_967A8 */
void fn_1_967A8(Fn1967A8Object *arg0, void *arg1) {
    u32 i;

    fn_1_12AB38((void *)"motion");
    fn_1_12A8A4((void *)arg1, (void *)&arg0->unk_20);
    arg0->unk_1C = fn_1_41518(arg0->unk_20);
    arg0->unk_1C->unk_1C = arg0->unk_14C;
    arg0->unk_1C->unk_08 = arg0->unk_150;
    arg0->unk_1C->unk_00 = arg0->unk_88;
    fn_1_41C18(arg0->unk_1C, arg0->unk_154);
    fn_1_41F58(arg0->unk_1C, 0, fn_1_96968, arg0);
    fn_1_41F58(arg0->unk_1C, 1, fn_1_96968, arg0);
    fn_1_41F58(arg0->unk_1C, 2, fn_1_969E8, arg0);
    fn_1_41F58(arg0->unk_1C, 3, fn_1_96BC0, arg0);
    fn_1_41F58(arg0->unk_1C, 4, fn_1_96A68, arg0);
    for (i = 0; i < 0x14; i++) {
        lbl_1_bss_6E98C = i;
        fn_1_41F58(arg0->unk_1C, 5, fn_1_96AE8, arg0);
    }
    fn_1_12AB38((void *)"..");
}
/* fzgx:end fn_1_967A8 */

/* fzgx:begin fn_1_968FC */
void fn_1_968FC(Fn1968FCObject *object) {
    if (object->unk_20 != 0) {
        fn_1_12ABB4((void *)object->unk_20);
        object->unk_20 = 0;
    }

    if (object->unk_1c != 0) {
        object->unk_1c->unk_1c = 0;
        object->unk_1c->unk_08 = 0;
        fn_1_41850(object->unk_1c);
        object->unk_1c = 0;
    }
}
/* fzgx:end fn_1_968FC */

/* fzgx:begin fn_1_96968 */
// Cache the resource key and return the requested resource sequence number.

u16 fn_1_96968(void *arg, void *arg1) {
    Fn196968Object *object = arg;

    if (object->unk_170 != 0 && object->unk_174 != 0) {
        object->unk_28 = fn_1_41488(object->unk_174, "TE_R");
        return (fn_1_41488(object->unk_174, arg1) + 1);
    }

    object->unk_28 = 0;
    return 0;
}
/* fzgx:end fn_1_96968 */

/* fzgx:begin fn_1_969E8 */
// Resolve the owner's resource values and cache the associated lookup result.

u16 fn_1_969E8(void *arg, void *arg1) {
    Fn1969E8Owner *owner = arg;

    if (owner->unk_1b0 != 0 && owner->unk_1b4 != 0) {
        owner->unk_2c = fn_1_41488(owner->unk_1b4, &lbl_1_data_22A24);
        return (fn_1_41488(owner->unk_1b4, arg1) + 1);
    }

    owner->unk_2c = 0;
    return 0;
}
/* fzgx:end fn_1_969E8 */

/* fzgx:begin fn_1_96A68 */
// Updates the car's resource state and returns the next resource index.

u16 fn_1_96A68(void *arg, void *arg1) {
    Fn196A68Object *object = arg;

    if (object->unk_1F0 != 0 && object->unk_1F4 != 0) {
        object->unk_34 = fn_1_41488(object->unk_1F4, "EYE");
        return (fn_1_41488(object->unk_1F4, arg1) + 1);
    }
    object->unk_34 = 0;
    return 0;
}
/* fzgx:end fn_1_96A68 */

/* fzgx:begin fn_1_96AE8 */
u16 fn_1_96AE8(void *base, void *arg1) {
    return fn_1_96B14(base, arg1, lbl_1_bss_6E98C);
}
/* fzgx:end fn_1_96AE8 */

/* fzgx:begin fn_1_96B14 */
// Computes the indexed entry value when its backing resource is available.

u16 fn_1_96B14(void *base, void *arg1, s32 index) {
    Fn196B14Entry *entry = (Fn196B14Entry *)((u8 *)base + (index << 5));

    if (entry->unk_210 != 0 && entry->unk_214 != 0) {
        ((u32 *)((u8 *)base + 0x38))[index] =
            fn_1_41488(entry->unk_214, "ACCE");
        return (fn_1_41488(entry->unk_214, arg1) + 1);
    }

    ((u32 *)((u8 *)base + 0x38))[index] = 0;
    return 0;
}
/* fzgx:end fn_1_96B14 */

/* fzgx:begin fn_1_96BC0 */
// Updates the car's resource-derived value and returns the converted result.

u16 fn_1_96BC0(void *arg, void *arg1) {
    Fn196BC0Object *object = arg;

    if (object->resource_1D0 != 0 && object->resource_1D4 != 0) {
        object->value_30 = (void *)fn_1_41488(
            object->resource_1D4, "LIP");
        return (fn_1_41488(object->resource_1D4, arg1) + 1);
    }

    object->value_30 = 0;
    return 0;
}
/* fzgx:end fn_1_96BC0 */

/* fzgx:begin fn_1_96C40 */
/* Unknown retail object: .rodata 4014 (-1.0f) between the 935E4 and fn_1_96C40 constants; no retail function reads it. */
const f32 lbl_1_rodata_4014 = -1.0f;
/* GX write-gather FIFO: every store is a hardware write, hence volatile. */

#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)  /* fzgx-allow: S2 GX FIFO stores are hardware writes */

void fn_1_96C40(void *arg0) {
    GXColor colA = {0x40, 0x40, 0x60, 0x80};
    GXColor colB = {0x00, 0x00, 0x00, 0x00};
    s32 pass;
    s32 i;
    s32 j;
    s32 cx;
    s32 cz;
    GXColor c0;
    GXColor c1;
    f32 x0;
    f32 x1;
    f32 z0;
    f32 z1;

    lbl_8006DCA4();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    cx = (s32)*(f32 *)((u8 *)arg0 + 0xA8);
    cz = (s32)*(f32 *)((u8 *)arg0 + 0xB0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(1);
    c0 = colA;
    fn_800725DC(&c0);
    c1 = colB;
    fn_80072614(&c1);
    fn_800747D0(4, 0, 0, 0, 0, 0, 2);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80072864(0);
    for (pass = 0; pass < 2; pass++) {
        for (i = -10; i <= 10; i++) {
            x0 = (cx + i) - 0.5f;
            x1 = 0.5f + (cx + i);
            for (j = -10; j <= 10; j++) {
                if ((u32)pass == ((i + j) & 1)) {
                    continue;
                }
                z0 = (cz + j) - 0.5f;
                z1 = 0.5f + (cz + j);
                fn_8003462C(0x80, 7, 4);
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 1.0f;
            }
        }
        {
            GXColor colC = {0x00, 0x20, 0x40, 0x80};

            fn_800725DC(&colC);
        }
    }
}

#undef GX_FIFO_F32
/* fzgx:end fn_1_96C40 */

/* fzgx:begin fn_1_96F20 */
/* Unknown retail object: .rodata 4028..407B, seven vectors between fn_1_96C40's and fn_1_96F20's literals; no
   retail function reads them. */
static const Vec3 lbl_1_rodata_4028[7] = {
    {0.0f, 0.0f, -0.085f}, {0.0f, -0.085f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f},
};
/* VIEWS */
void fn_1_96F20(CarData_96F20 *car) {
    Vec3 sp40;
    Vec3 sp34;
    Vec3 sp28;
    Vec3 sp1C;
    Vec3 sp10;
    f32 spC;
    f32 sp8;
    CarR29 *r29;
    void *cam;
    CarSub2 *sub2;
    f32 f31_val;
    f32 mtx_x, mtx_y, mtx_z;

    cam = camera_get_state_object();
    r29 = ((CarR29 *)fn_80071268(car->unk_e4[car->unk_8c], &lbl_1_data_22A1C));
    if (!r29) {
        r29 = ((CarR29 *)fn_80071268(car->unk_e4[car->unk_8c], &lbl_1_data_24EF0));
    }
    if (!r29) {
        return;
    }

    camera_update_state(cam);
    lbl_8006E1F0(&sp10, 0.0f, 1.0f, 0.0f);
    fn_1_A714C(&spC, 0, 0, &sp8);

    f31_val = lbl_8006D21C((0.5f * spC * 182.04445f));

    lbl_8006DAEC();
    sub2 = car->unk_150->unk_8;
    lbl_8006E0B4(car->unk_a8, car->unk_ac + car->unk_b4, car->unk_b0);
    mathutil_mtxA_rotate_z(car->unk_a4);
    mathutil_mtxA_rotate_y(car->unk_a0);
    mathutil_mtxA_rotate_x(car->unk_a2);
    lbl_8006E14C(car->unk_b8);
    lbl_8006DFC4(&sub2->unk_88);

    mtx_x = ((f32 (*)[4])lbl_801A6D00)[0][3];
    mtx_y = ((f32 (*)[4])lbl_801A6D00)[1][3];
    mtx_z = ((f32 (*)[4])lbl_801A6D00)[2][3];
    lbl_8006DB30();

    sp28.x = mtx_x;
    sp28.y = mtx_y;
    sp28.z = mtx_z + (1.25f * r29->unk_14) / f31_val;
    sp28.x *= 0.15f;
    sp28.y *= 0.15f;
    sp28.z *= 0.15f;
    if (sp28.z > sp8 + (mtx_z - r29->unk_14)) {
        sp28.z = sp8 + (mtx_z - r29->unk_14);
    }

    lbl_8006E2C0(&sp1C, 0.0f, 0.0f, mtx_z - sp28.z);
    fn_8006E250((void *)&sp28, (void *)&sp40);

    sp34.x = sp40.x + sp1C.x;
    sp34.y = sp40.y + sp1C.y;
    sp34.z = sp40.z + sp1C.z;

    fn_1_B81C(&sp40, &sp34, 0);
}
/* fzgx:end fn_1_96F20 */

/* fzgx:begin fn_1_97174 */
s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2) {
    Fn197174Root *root = fn_1_41BDC();
    s32 index = 0;

    while (index < root->count) {
        Fn197174Entry *entry = fn_1_41B18(owner, arg1, index);
        if (((s32)strcmp((void *)(owner->base + entry->offset), (void *)arg2)) == 0) {
            return index;
        }
        index++;
    }
    return -1;
}
/* fzgx:end fn_1_97174 */

/* fzgx:begin fn_1_97204 */
void fn_1_97204(void *arg0, void *arg1) {
    fn_1_9724C(arg0);
    if (fn_1_97F80((void *)arg0, (void *)arg1)) {
        return;
    }
}
/* fzgx:end fn_1_97204 */

/* fzgx:begin fn_1_9724C */
// Loads the active resource value when the initialization check has not completed.

void fn_1_9724C(void *rob) {
    if (fn_1_98104(rob) == 0) {
        ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
    }
}
/* fzgx:end fn_1_9724C */

/* fzgx:begin fn_1_97288 */
#define GAME_MAIN_REL_MOTASGLIST_TYPES_H

/* begin game/main_rel/shared_types.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/motasglist_types.h */

/* begin sofdec/adxt.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */

#define LAYOUT_CHECK_JOIN2(a, b) a##b

#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)

#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == size) ? 1 : -1]

#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == offset) ? 1 : -1]

void fn_1_97288(struct fn_1_97288_Arg0 *arg0) {
    char path[64];
    MotionParam97288 blendIn;
    MotionParam97288 current;
    MotionParam97288 sub;
    u32 id;
    f32 vol;
    s32 i;
    s32 n;
    s32 rate;

    arg0->unk_1E4 = 0;
    if (arg0->start != 0) {
        id = fn_1_41488(arg0->obj->names, lbl_1_data_26DC0[arg0->track[arg0->index].kind]);
        if (id == -1) {
            id = 0;
        }
        fn_1_4270C(arg0->obj, 0, arg0->motion = id);
        ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
        if (strstr(arg0->name, "int_")) {
            sprintf(path, "snd/ahx/%s.ahx", arg0->name);
        } else if (strstr(arg0->name, lbl_1_data_20D00) || strstr(arg0->name, lbl_1_data_20C68)) {
            sprintf(path, "snd/ahx/gomar_shioh_%s.ahx", arg0->name + 5);
        } else if (strstr(arg0->name, "dai_") || strstr(arg0->name, lbl_1_data_20D08) ||
                   strstr(arg0->name, lbl_1_data_20D0C)) {
            sprintf(path, "snd/ahx/daisangen_%s.ahx", arg0->name + 4);
        } else {
            sprintf(path, "snd/ahx/%s.ahx", arg0->name);
        }
        fn_8004D18C((ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_4, (u32)path);
        arg0->start = 0;
        arg0->kind = arg0->prevKind = arg0->track[arg0->index].kind;
        arg0->count = 0;
    } else if (arg0->index < arg0->trackCount - 1) {
        arg0->index++;
        vol = arg0->track[arg0->index].volume / 65536.0f;
        vol = vol < 0.0f ? 0.0f : vol > lbl_1_data_26DD8 ? lbl_1_data_26DD8 : vol;
        if (arg0->kind == arg0->track[arg0->index].kind) {
            arg0->count++;
        } else {
            arg0->count = 1;
            arg0->prevKind = arg0->kind;
            arg0->prevVolume = arg0->volume;
            arg0->kind = arg0->track[arg0->index].kind;
            arg0->blend = 0.0f;
            for (i = arg0->index; i < arg0->trackCount - 1; i++) {
                if (arg0->kind != arg0->track[i].kind) {
                    break;
                }
            }
            n = i - arg0->index;
            arg0->length = n < 2 ? 2 : n > 8 ? 8 : n;
        }
        arg0->blend = ((f32)arg0->length - (f32)arg0->count) / (f32)arg0->length;
        if (arg0->blend < 0.0f) {
            arg0->blend = 0.0f;
        }
        arg0->volume = vol / lbl_1_data_26DD8;
        if (arg0->volume < 0.0f) {
            arg0->volume = 0.0f;
        }
        if (arg0->blend > 0.0f) {
            id = fn_1_41488(arg0->obj->names, lbl_1_data_26DC0[arg0->prevKind]);
            if (id == -1) {
                id = 0;
            }
            rate = 100.0f * arg0->prevVolume;
            blendIn.a[2] = 0xFFFF;
            blendIn.a[3] = rate;
            blendIn.a[1] = rate;
            fn_1_4270C(arg0->obj, (s32)&blendIn, arg0->motion = id);
            fn_1_42E74(arg0->obj);
        }
        id = fn_1_41488(arg0->obj->names, lbl_1_data_26DC0[arg0->kind]);
        if (id == -1) {
            id = 0;
        }
        rate = 100.0f * arg0->volume;
        current.a[2] = 0xFFFF;
        current.a[3] = rate;
        current.a[1] = rate;
        if (arg0->blend <= 0.0f) {
            fn_1_4270C(arg0->obj, (s32)&current, arg0->motion = id);
        } else {
            fn_1_42AD0(arg0->obj, (s32)&current, arg0->motion = id, 100, 84);
        }
        if (arg0->unk_1B0 != NULL && arg0->unk_1B4 != NULL) {
            rate = 100.0f * arg0->volume;
            sub.a[2] = 0xFFFF;
            sub.a[3] = rate;
            sub.a[1] = rate;
            fn_1_4270C(arg0->unk_1B0, (s32)&sub, arg0->unk_1A8);
        }
    }
}
#undef GAME_MAIN_REL_MOTASGLIST_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
#undef SOFDEC_ADXT_H
#undef LAYOUT_CHECK_H
#undef LAYOUT_CHECK_JOIN2
#undef LAYOUT_CHECK_JOIN
#undef CHECK_SIZE
#undef CHECK_OFFSET

/* fzgx:end fn_1_97288 */

/* fzgx:begin fn_1_977BC */
RobPart lbl_1_data_27CF0[8] = {
    {{-0.019215f, 0.004005f, 0.0265f}, "FIRE1"},
    {{-0.019215f, 0.004005f, -0.0265f}, "FIRE1"},
    {{-0.019215f, -0.016995f, 0.0265f}, "FIRE2"},
    {{-0.019215f, -0.016995f, -0.0265f}, "FIRE2"},
    {{0.009785f, 0.033005f, 0.013f}, "FIRE2"},
    {{0.009785f, 0.033005f, -0.013f}, "FIRE2"},
    {{0.009785f, 0.046005f, 0.0165f}, "FIRE2"},
    {{0.009785f, 0.046005f, -0.0165f}, "FIRE2"},
};
static inline char *rob_name(RobAnim *anim) {
    return anim == 0 ? 0 : ((char *)fn_1_41418((void *)anim->names, anim->id));
}

static inline s32 rob_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline void rob_transform(Rob *rob, RobJoint *joint) {
    lbl_8006DCA4();
    lbl_8006E0B4(rob->pos.x, rob->pos.y + rob->height, rob->pos.z);
    mathutil_mtxA_rotate_z(rob->rot_z);
    mathutil_mtxA_rotate_y(rob->rot_y);
    mathutil_mtxA_rotate_x(rob->rot_x);
    lbl_8006E14C(rob->scale);
    lbl_8006DFC4(joint->matrix);
}

static inline void fn_1_977BC_loop4(RobModel *model) {
    RobMaterial *material;
    f32 offset;
    u32 j;
    f32 matrix[3][4];
        offset = 0.5f * (rob_rand() / 32767.0f);
        material = model->materials;
        for (j = 0; j < model->count; material++, j++) {
            if (material->flags & 0x20000) {
                fn_1_56018(1);
                lbl_8006D784(matrix);
                matrix[1][3] = offset;
                matrix[0][0] = 1.0f;
                matrix[1][1] = 1.0f;
                matrix[2][2] = 1.0f;
                fn_1_560F0(0, matrix);
            }
        }
}

void fn_1_977BC(Rob *rob, RobView *arg1) {
    f32 depth[8];
    u32 order[8];
    u32 i;
    u32 j;
    u32 draw_i;
    u32 index;
    void *model_set;
    RobJoint *joint;
    f32 scale;
    RobPart *parts;
    scale = 1.0f;
    joint = &arg1->joints[2];
    model_set = rob->models[rob->active];
    if (((s32)strcmp((void *)(rob_name(&rob->anim)), (void *)"WIN_3RD")) == 0) {
        f32 t = rob->anim.motion->frame;
        if (320.0f <= t && t <= 420.0f) return;
        if (315.0f <= t && t <= 320.0f) scale = (320.0f - t) / 5.0f;
        else if (420.0f <= t && t <= 435.0f) scale = (4.0f * (t - 420.0f)) / 15.0f;
        else if (435.0f <= t && t <= 450.0f) scale = 1.0f + (3.0f * (450.0f - t)) / 15.0f;
    } else if (((s32)strcmp((void *)(rob_name(&rob->anim)), (void *)"SEL_DEC")) == 0) {
        f32 t = rob->anim.motion->frame;
        if (80.0f <= t && t <= 175.0f) return;
        if (175.0f <= t && t <= 195.0f) scale = (4.0f * (t - 175.0f)) / 20.0f;
        else if (195.0f <= t && t <= 215.0f) scale = 1.0f + (3.0f * (215.0f - t)) / 20.0f;
    } else if (((s32)strcmp((void *)(rob_name(&rob->anim)), (void *)"WIN_1ST")) == 0) {
        f32 t = rob->anim.motion->frame;
        if (330.0f <= t && t <= 355.0f) return;
        if (355.0f <= t && t <= 375.0f) scale = (4.0f * (t - 355.0f)) / 20.0f;
        else if (375.0f <= t && t <= 390.0f) scale = 1.0f + (3.0f * (390.0f - t)) / 15.0f;
    } else if (((s32)strcmp((void *)(rob_name(&rob->anim)), (void *)"WIN_2ND")) == 0) {
        f32 t = rob->anim.motion->frame;
        if (395.0f <= t && t <= 482.0f) return;
        if (482.0f <= t && t <= 500.0f) scale = (4.0f * (t - 482.0f)) / 18.0f;
        else if (500.0f <= t && t <= 520.0f) scale = 1.0f + (3.0f * (520.0f - t)) / 20.0f;
    }
    parts = lbl_1_data_27CF0;
    for (i = 0; i < 8; i++) {
        order[i] = i;
        {
        Vec3 pos = { 0.0f, 0.0f, 0.0f };
        rob_transform(rob, joint);
        lbl_8006E0A4(&parts[i]);
        fn_80072558();
        lbl_8006E1B0(&pos, &pos);
        depth[i] = pos.z;
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = i; j < 8; j++) {
            if (depth[j] > depth[i]) {
                f32 z = depth[i];
                u32 k = order[i];
                depth[i] = depth[j];
                order[i] = order[j];
                depth[j] = z;
                order[j] = k;
            }
        }
    }
    for (draw_i = 0; draw_i < 8; draw_i++) {
{
    RobModel *model;
        model = ((RobModel *)fn_80071268(model_set, (void *)lbl_1_data_27CF0[order[draw_i]].name));
        fn_1_977BC_loop4(model);
        rob_transform(rob, joint);
        {
            RobPart *p = lbl_1_data_27CF0;
            lbl_8006E0A4(p + order[draw_i]);
        }
        lbl_8006D7B0();
        lbl_8006E15C(scale * (2.5f + (f32)(0.4f * (rob_rand() / 32767.0f))),
                    scale * (1.4f + (f32)(0.5f * (rob_rand() / 32767.0f))), 1.0f);
        fn_80072558();
        if (draw_i == 0) index = fn_1_548EC(fn_1_5448C((u8 *)model + 8));
        if (index + draw_i < 0x1000) fn_1_55924((void *)model, index + draw_i);
}
    }
}
/* fzgx:end fn_1_977BC */

/* fzgx:begin fn_1_97F1C */
/* Formats the indexed message and stores its parsed value in the object. */

s16 fn_1_97F1C(Fn197F1CObject *object, s16 index) {
    char buffer[0x80];

    sprintf((void *)buffer, (void *)"lip/%s.lip.arc", lbl_1_data_20D1C[index]);
    object->unk_4A4 = fn_1_12A32C((void *)buffer);
    return object->unk_4A4;
}
/* fzgx:end fn_1_97F1C */

/* fzgx:begin fn_1_97F80 */
u8 fn_1_97F80(Fn197F80Object *rob, const char *name) {
    void *resource = 0;
    char path[0x40];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    u32 length;

    if (name == 0 || strstr((void *)name, (void *)((const char *)(lbl_1_data_26D50))) == 0) {
        return 0;
    }

    sprintf(path, (const char *)("%s.ltt"), name);
    if (strcmp(path, (const char *)("san_12.ltt")) == 0 ||
        strcmp(path, (const char *)("dai_9.ltt")) == 0 ||
        strcmp(path, (const char *)("gen_8.ltt")) == 0 ||
        strcmp(path, (const char *)("gen_9.ltt")) == 0) {
        return 1;
    }

    fn_1_12A2D0((s32)rob->unk_4A4);
    fn_1_12A2B8(1);
    fn_1_12AB38((void *)((const char *)("lip/")));
    if (((int)fn_1_12A8A4((void *)path, (void *)&resource)) == 0) {
        return 0;
    }

    fn_1_12AB38((void *)((const char *)("..")));
    fn_1_12A2B8(0);
    length = strlen(name);
    rob->unk_488 = 1;
    rob->unk_489 = 1;
    rob->unk_4A8 = resource;
    rob->unk_4AC = *(void **)resource;
    rob->unk_4B0 = (u8 *)resource + 4;
    rob->unk_4B4 = fn_1_4630(lbl_801A6410,
                            (length + 0x20) & ~0x1f,
                            (void *)((const char *)("rob.c")), 0xfa9);
    strcpy((void *)rob->unk_4B4, name);
    return 1;
}
/* fzgx:end fn_1_97F80 */

/* fzgx:begin fn_1_98104 */
s16 fn_1_98104(Fn198104Obj *obj) {
    Fn198104Obj *ptr = (Fn198104Obj *)((u8 *)obj + 0x488);
    u32 saved;

    if (ptr == 0) {
        return 0;
    }

    saved = ptr->value_1C;
    if (ptr->value_2C != 0) {
        fn_1_46B4(lbl_801A6410, ptr->value_2C, (void *)"rob.c", 0xfc0);
        ptr->value_2C = 0;
    }

    fn_80008BEC(ptr, 0, 0x30);
    ptr->value_1C = saved;
    return 1;
}
/* fzgx:end fn_1_98104 */

/* fzgx:begin fn_1_9818C */
s32 fn_1_9818C(u32 arg0) {
    s16 id = arg0;

    if (id != -1) {
        fn_1_12A734(id);
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_9818C */
