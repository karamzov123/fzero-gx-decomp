#include "types.h"
#include "rel/main_rel/globals.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "dolphin/os/OSCache.h"
#include "dolphin/os/OSFastCast.h"
#include "game/vec3.h"
#include "mathutil.h"
#include "psvec.h"
#include "lc_mtx.h"
#include "rel/main_rel/camera.h"
#include "rel/main_rel/car_test.h"
typedef struct {
    s16 unk_0;  // 16 loads, 16 stores
    u8 pad_2[0xA];
} Obj_1_bss_6C850;
typedef struct {
    u8 unk_0;  // 14 loads, 5 stores
    u8 pad_1[0x1];
    u16 unk_2;  // 0 loads, 1 stores
    s16 unk_4;  // 10 loads, 1 stores
    u8 pad_6[0x2];
    u32 unk_8;  // 3 loads, 2 stores
    s16 unk_C;  // 6 loads, 0 stores
    u8 pad_E[0xA];
    s16 unk_18;  // 1 loads, 0 stores
    u16 unk_1A;  // 2 loads, 0 stores
    u8 pad_1C[0x18];
    u32 unk_34;  // 1 loads, 0 stores
    u32 unk_38;  // 1 loads, 0 stores
    u8 pad_3C[0xAC];
} Obj_1_bss_6C84C_Target;
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;  // 1 loads, 0 stores
    f32 unk_C;  // 1 loads, 0 stores
    u8 pad_10[0x164];
} Obj_1_data_1D730;
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;  // 1 loads, 0 stores
    f32 unk_C;  // 1 loads, 0 stores
    u8 pad_10[0x60];
} Obj_1_data_1D6C0;
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
} Obj_1_data_1CC74_Target;

typedef s32 (*fn_1_8D210_callback)(u32);
typedef void (*AvlineCallback)(void *);
/* _prologue */
typedef struct fn_1_58D38_EffectEntry {
    s8 unk_00;
    u8 pad_01[7];
    u32 unk_08;
    s16 unk_0C;
    u8 pad_0E[0x0C];
    u16 unk_1A;
    u8 pad_1C[0xCC];
} fn_1_58D38_EffectEntry;

/* _prologue */
struct fn_1_5BF70_lbl_1_rodata_2950 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0xC8];
    f64 unk_F0;
    f64 unk_F8;
    u8 pad_100[0x30];
    f64 unk_130;
};

/* _prologue */
typedef struct {
    u8 unk00[0x18];
    s16 value18;
    u8 unk1A[2];
    f32 value1C;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 unk2C[8];
    void *field34;
    u8 unk38[0x1c];
    s16 value54;
    s16 value56;
} fn_1_5FEBC_EffectData;

/* _prologue */
typedef struct {
    u8 unk00[8];
    fn_1_5FEBC_EffectData *data;
} fn_1_5FEBC_EffectObject;

/* _prologue */
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x20];
    u32 unk_34;
    void *unk_38;
    u8 pad_3c[0x18];
    s16 unk_54;
    u8 pad_56[0x4];
    u16 unk_5a;
    u8 pad_5c[0x58];
    f32 unk_b4;
} fn_1_61D08_EffectObject;

/* _prologue */
typedef struct {
    u8 pad_00[0x8];
    void *unk_08;
} fn_1_652F4_Effect;

/* _prologue */
typedef struct {
    u8 pad20[0x20];
    void *unk_20;
} Fn1_61E60Node;

/* _prologue */
typedef struct {
    u8 pad38[0x38];
    Fn1_61E60Node *unk_38;
} Fn1_61E60Object;

/* fn_1_584D4 */
typedef struct AvlineEntry {
    s8 unk_00;
    u8 _pad01;
    s16 unk_02;
    s16 unk_04;
    u8 _pad06[0xe2];
} AvlineEntry;

/* fn_1_584D4 */
typedef struct AvlineState {
    AvlineEntry *unk_00;
    AvlineEntry *unk_04;
    s16 unk_08;
    u8 _pad0a[2];
    s32 unk_0c;
    s32 unk_10;
} AvlineState;

/* fn_1_58694 */
typedef struct AvlineVec3 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} AvlineVec3;

/* fn_1_58694 */
typedef struct AvlineEntry_58694 {
    s8 unk_00;
    u8 _pad01[0x0b];
    s16 unk_0c;
    u8 _pad0e[0x02];
    s32 unk_10;
    u8 _pad14[0x28];
    AvlineVec3 unk_3c;
    u8 _pad48[0x18];
    AvlineVec3 unk_60;
    u8 _pad6c[0x7c];
} AvlineEntry_58694;
typedef void (*AvlineHandler)(AvlineEntry_58694 *);

/* fn_1_58694 */
typedef struct AvlineState_58694 {
    AvlineEntry_58694 *unk_00;
    AvlineEntry_58694 *unk_04;
    u8 _pad08[0x0c];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
} AvlineState_58694;

/* fn_1_58854 */
typedef struct {
    s8 unk_0;
    u8 pad_1[0xb];
    s16 unk_C;
} AvlineObj;

/* fn_1_58994 */
typedef struct AvlineEntry_58994 {
    s8 unk_00;
    u8 pad01[0x07];
    u32 unk_08;
    s16 unk_0c;
    u8 pad0e[0x02];
    u32 unk_10;
    u32 unk_14;
    u8 pad18[0x02];
    u16 unk_1a;
    u8 pad1c[0x20];
    AvlineVec3 unk_3c;
    u8 pad48[0x18];
    AvlineVec3 unk_60;
    u8 pad6c[0x7c];
} AvlineEntry_58994;
typedef void (*AvlineHandler_58994)(AvlineEntry_58994 *);

/* fn_1_58994 */
typedef struct AvlineTables {
    u8 pad000[0xd68];
    AvlineHandler_58994 unk_d68[0x45];
    AvlineHandler_58994 unk_e7c[0x45];
    u32 unk_f90;
} AvlineTables;

/* fn_1_58994 */
typedef struct AvlineState_58994 {
    AvlineEntry_58994 *unk_00;
    AvlineEntry_58994 *unk_04;
    u32 unk_08;
    u32 unk_0c;
} AvlineState_58994;

/* fn_1_58994 */
typedef struct Effect_63518Vec {
    u32 x;
    u32 y;
    u32 z;
} Effect_63518Vec;

/* fn_1_58994 */
typedef struct Effect_63518 {
    u8 unk00[0x14];
    u32 unk14;
    u8 unk18[0x20];
    Effect_63518Vec *unk38;
    Effect_63518Vec unk3c;
    u8 unk48[0x10];
    u16 unk58;
    u8 unk5a[0x06];
    Effect_63518Vec unk60;
    u8 unk6c[0x40];
    u16 unkac;
    u16 unkae;
    u16 unkb0;
} Effect_63518;

/* fn_1_58C6C */
struct fn_1_58C6C_lbl_1_bss_6C848_T {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xC];
    u16 unk_1A;
};

/* fn_1_58C6C */
struct fn_1_58C6C_lbl_1_bss_6C84C_T {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xC];
    u16 unk_1A;
};

/* fn_1_58D38 */
typedef struct fn_1_58D38_EffectState {
    fn_1_58D38_EffectEntry *unk_00;
    fn_1_58D38_EffectEntry *unk_04;
    u8 pad_08[8];
    u32 unk_10;
} fn_1_58D38_EffectState;

/* fn_1_58E3C */
typedef struct {
    s8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[0xDA];
} EffectEntry;

/* fn_1_58F50 */
typedef struct {
    u8 unk_0;
    u8 pad_1[1];
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[0xDA];
} fn_1_58F50_EffectEntry;

/* fn_1_591A0 */
typedef struct {
    s8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xDA];
} Fn591A0Obj;

/* fn_1_5962C */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

/* fn_1_5962C */
typedef struct {
    s32 field_00[4];
    s32 timer;
    s32 field_14;
    s32 field_18;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    s32 field_30;
    s32 field_34;
    s32 field_38;
    union {
        Vec3f pos;
        Vec3i bits;
    } field_3c;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5c;
    Vec3i prev;
    s32 field_6c[10];
    f32 field_94;
    f32 field_98;
} Fn_1_5962C_State;

/* fn_1_59770 */
typedef struct {
    f32 scale;
    u32 unk4;
    f32 mtx[3][4];
    u32 unk38;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_59770_Sprite;

/* fn_1_59770 */
typedef struct {
    u8 pad_0[0x8];
    u32 flags;
    u8 pad_C[0xC];
    s16 unk18;
    u8 pad_1A[0x2];
    f32 red;
    f32 green;
    f32 blue;
    f32 scale;
    u8 pad_2C[0x8];
    void *unk34;
    u8 pad_38[0x4];
    Vec3 pos;
    u8 pad_48[0x18];
    Vec3 prevPos;
} fn_1_59770_Effect;

/* fn_1_59A74 */
struct fn_1_59A74_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x6];
    u16 unk_1A;
};

/* fn_1_59B00 */
typedef struct fn_1_59B00_Effect {
    u8 pad_00[0x10];
    s32 frame;
    u8 pad_14[0x14];
    f32 value;
    f32 target;
} fn_1_59B00_Effect;

/* fn_1_59B90 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_59B90;

/* fn_1_59B90 */
typedef struct {
    f32 m[12];
} Mtx;

/* fn_1_59B90 */
typedef struct {
    u8 pad_0[0x8];
    Vec3_59B90 v8;
    f32 f14;
} NodeObj;

/* fn_1_59B90 */
typedef struct {
    u8 pad_0[0x90];
    NodeObj *unk_90;
} MgrObj;

/* fn_1_59B90 */
typedef struct {
    u8 pad_0[0x28];
    f32 f28;
    u8 pad_2C[0x10];
    u32 unk_3C;
    u8 pad_40[0x14];
    s16 unk_54;
    s16 unk_56;
} SelfObj;

/* fn_1_59CC8 */
struct Fn159CC8Object {
    u8 pad[0x10];
    s32 unk_10;
};

/* fn_1_59D54 */
typedef struct fn_1_59D54_Effect {
    u8 state;
    u8 pad0[0xf];
    s32 frame;
    u8 pad1[0x4];
    s16 effect_id;
    u8 pad2[0x22];
    f32 position_x;
    f32 position_y;
    f32 position_z;
    f32 velocity_x;
    f32 velocity_y;
    f32 velocity_z;
    u8 pad3[0x40];
    f32 accumulator_x;
    f32 accumulator_y;
    f32 accumulator_z;
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    u8 pad4[0x8];
    f32 intensity;
} fn_1_59D54_Effect;

/* fn_1_59EE4 */
typedef struct {
    f32 x, y, z;
} Fn59EE4Vec;

/* fn_1_59EE4 */
typedef struct {
    u8 r, g, b, a;
} Fn59EE4Color;

/* fn_1_59EE4 */
typedef struct {
    Fn59EE4Vec pos;
    Fn59EE4Color color;
} Fn59EE4Vertex;

/* fn_1_59EE4 */
typedef struct {
    Fn59EE4Vec pos;
    f32 radius;
    u16 unk_10;
    u16 unk_12;
    Fn59EE4Color color;
} Fn59EE4Glow;

/* fn_1_59EE4 */
typedef struct {
    s32 type;
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} Fn59EE4CurveKey;

/* fn_1_59EE4 */
typedef struct {
    u8 pad_0[0xf90];
    u32 seed;
    u8 pad_f94[0x1c];
    Fn59EE4CurveKey curve_x[2];
    Fn59EE4CurveKey curve_y[2];
    Fn59EE4CurveKey curve_z[2];
} Fn59EE4Data;

/* fn_1_59EE4 */
typedef struct {
    u8 pad_0[0xd4];
    Fn59EE4Vec work;
} Fn59EE4Scratch;

/* fn_1_59EE4 */
typedef struct {
    u8 pad_0[0x8];
    u32 flags;
    u8 pad_c[0x4];
    s32 frame;
    u8 pad_14[0x4];
    s16 id;
    u8 pad_1a[0x2];
    f32 color[3];
    u8 pad_28[0x14];
    Fn59EE4Vec pos;
    u8 pad_48[0x28];
    f32 bend[3];
    u8 pad_7c[0x18];
    Fn59EE4Vec dir;
    u8 pad_a0[0xc];
    s16 max_count;
    u8 pad_ae[0x6];
    f32 scale;
} Fn59EE4Effect;

/* fn_1_59EE4 */
typedef struct {
    u8 pad_0[0x3ba];
    s16 mode;
} Fn59EE4Racer;

/* fn_1_59EE4 */
typedef struct {
    u8 pad_0[0x475];
    u8 camera;
} Fn59EE4Owner;

/* fn_1_5A8D0 */
typedef struct {
    u8 pad[0x10];
    s32 field_10;
} Fn1_5A8D0Data;

/* fn_1_5A8DC */
typedef struct { f32 x,y,z; } Vec3_5A8DC;

/* fn_1_5A8DC */
typedef struct {
 u8 pad_0[0x18]; s16 unk_18; u8 pad_1A[2];
 Vec3_5A8DC unk_1C; u8 pad_28[0x14];
 Vec3_5A8DC unk_3C; u8 pad_48[0x4C];
 Vec3_5A8DC unk_94;
} Arg_5A8DC;

/* fn_1_5A8DC */
typedef struct {
 s8 unk_0; u8 pad_1; s16 unk_2,unk_4; u8 pad_6[6];
 s16 unk_C; u8 pad_E[0xA]; s16 unk_18; u16 unk_1A;
 Vec3_5A8DC unk_1C; f32 unk_28,unk_2C; u8 pad_30[4];
 u32 unk_34; u8 pad_38[4];
 Vec3_5A8DC unk_3C,unk_48; s16 unk_54,unk_56;
 u8 pad_58[0x3C]; Vec3_5A8DC unk_94; u8 pad_A0[0x48];
} Effect_5A8DC;

/* fn_1_5ABCC */
typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} Fn1_5ABCCOutput;

/* fn_1_5AC48 */
typedef struct fn_1_58D38_EffectEntry_fn_1_5AC48 {
    s8 unk_00;
    u8 pad_01[7];
    u32 unk_08;
    s16 unk_0C;
    u8 pad_0E[0x0C];
    u16 unk_1A;
    u8 pad_1C[0xCC];
} fn_1_58D38_EffectEntry_fn_1_5AC48;

/* fn_1_5AC48 */
struct fn_1_5BF70_lbl_1_rodata_2950_fn_1_5AC48 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0xC8];
    f64 unk_F0;
    f64 unk_F8;
    u8 pad_100[0x30];
    f64 unk_130;
};

/* fn_1_5AC48 */
typedef struct {
    u8 unk00[0x18];
    s16 value18;
    u8 unk1A[2];
    f32 value1C;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 unk2C[8];
    void *field34;
    u8 unk38[0x1c];
    s16 value54;
    s16 value56;
} fn_1_5FEBC_EffectData_fn_1_5AC48;

/* fn_1_5AC48 */
typedef struct {
    u8 unk00[8];
    fn_1_5FEBC_EffectData_fn_1_5AC48 *data;
} fn_1_5FEBC_EffectObject_fn_1_5AC48;

/* fn_1_5AC48 */
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x20];
    u32 unk_34;
    void *unk_38;
    u8 pad_3c[0x18];
    s16 unk_54;
    u8 pad_56[0x4];
    u16 unk_5a;
    u8 pad_5c[0x58];
    f32 unk_b4;
} fn_1_61D08_EffectObject_fn_1_5AC48;

/* fn_1_5AC48 */
typedef struct {
    u8 pad_00[0x8];
    void *unk_08;
} fn_1_652F4_Effect_fn_1_5AC48;

/* fn_1_5AC48 */
typedef struct {
    u8 pad20[0x20];
    void *unk_20;
} Fn1_61E60Node_fn_1_5AC48;

/* fn_1_5AC48 */
typedef struct {
    u8 pad38[0x38];
    Fn1_61E60Node_fn_1_5AC48 *unk_38;
} Fn1_61E60Object_fn_1_5AC48;

/* fn_1_5AC48 */
typedef struct {
    f32 x, y, z;
} fn_1_5AC48_Vec;

/* fn_1_5AC48 */
typedef struct {
    s8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[2];
    s32 unk_10;
    u8 pad_14[4];
    s16 unk_18;
    u16 unk_1A;
    fn_1_5AC48_Vec unk_1C;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[4];
    u32 unk_34;
    u8 pad_38[4];
    fn_1_5AC48_Vec pos;
    fn_1_5AC48_Vec vel;
    u8 pad_54[0xE8 - 0x54];
} fn_1_5AC48_Effect;

/* fn_1_5AC48 */
typedef struct {
    u8 pad_0[0x70];
    u32 unk_70;
} fn_1_5AC48_Inner;

/* fn_1_5AC48 */
typedef struct {
    u8 pad_0[0x8];
    fn_1_5AC48_Inner *unk_8;
} fn_1_5AC48_Owner;

/* fn_1_5AF28 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_5AF28;

/* fn_1_5AF28 */
typedef struct {
    u8 pad_0[0x1C];
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad_2C[0x8];
    NodeObj *unk_34;
    u8 pad_38[0x4];
    u32 unk_3C;
} SelfObj_5AF28;

/* fn_1_5B078 */
struct fx_5b078_out {
    u8 pad_00[0x10];
    s32 field_10;
    u8 pad_14[0x44];
    s16 field_58;
    u8 pad_5a[0x4];
    s16 field_5e;
    u8 pad_60[0x54];
    f32 field_b4;
};

/* fn_1_5B188 */
struct fx_5b188 {
    u8 pad_00[0x10];
    s32 field_10;
    u8 pad_14[0x8];
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    u8 pad_28[0x4];
    f32 field_2C;
    u8 pad_30[0xC];
    f32 field_3C;
    f32 field_40;
    f32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
    u8 pad_54[0x4];
    s16 field_58;
    u8 pad_5A[0x4];
    s16 field_5E;
    u8 pad_60[0x54];
    f32 field_B4;
};

/* fn_1_5B30C */
struct fn_1_5B30C_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};

/* fn_1_5B3D0 */
struct fn_1_5B3D0_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

/* fn_1_5B3D0 */
struct fn_1_5B3D0_State {
    u32 unk_0;
};

/* fn_1_5B450 */
typedef struct Fn1_5B450Object {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x04];
    s16 unk_18;
    u8 pad_1a[0x02];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0x28];
    s16 unk_58;
} Fn1_5B450Object;

/* fn_1_5B578 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec_1_5B578_T;

/* fn_1_5B578 */
typedef struct {
    u8 pad_0[8];
    u32 unk_8;
} Obj_1_5B578_Scene_T;

/* fn_1_5B578 */
typedef struct {
    u8 pad_0[0x70];
    u32 unk_70;
} Obj_1_5B578_World_T;

/* fn_1_5B578 */
typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
} Obj_1_5B578_Entity_T;

/* fn_1_5B578 */
typedef struct {
    u8 pad_8[8];
    Vec_1_5B578_T vec;
} Obj_1_5B578_Child_T;

/* fn_1_5B578 */
typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x18];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[8];
    Obj_1_5B578_Child_T *unk_34;
    u8 pad_38[4];
    u32 unk_3c;
} Obj_1_5B578_T;

/* fn_1_5B6F4 */
typedef struct Fn15B6F4 {
    u8 _pad00[0x10];
    s32 unk_10;
    s32 unk_14;
} Fn15B6F4;

/* fn_1_5B780 */
typedef struct Fn15B780 {
    u8 state;
    u8 _pad01[0x0f];
    int current;
    int maximum;
    u8 _pad18[0x94];
    s16 step;
    u8 _padAE[0x04];
    f32 result;
} Fn15B780;

/* fn_1_5B7F8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

/* fn_1_5B7F8 */
struct fn_1_5B7F8_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
    s32 unk_14;
    s16 unk_18;
    u8 pad_1A[2];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[0x6C];
    f32 unk_94;
    f32 unk_98;
    u8 pad_9C[0x10];
    s16 unk_AC;
};

/* fn_1_5B7F8 */
typedef struct {
    u8 r, g, b, a;
} fn_1_5B7F8_Color;

/* fn_1_5B7F8 */
typedef struct {
    Fn183D28Vec3 pos;
    fn_1_5B7F8_Color color;
} fn_1_5B7F8_Point;

/* fn_1_5B7F8 */
typedef struct {
    f32 y, z;
} fn_1_5B7F8_Wave;

/* fn_1_5BF70 */
struct fn_1_5BF70_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
};

/* fn_1_5BF70 */
struct fn_1_5BF70_lbl_1_data_1D628 {
    u32 unk_0;
};

/* fn_1_5BFF0 */
struct fn_1_5BFF0_Arg0 {
    u8 unk_0;
    u8 pad_1[0xF];
    u32 unk_10;
    u8 pad_14[0x98];
    s16 unk_AC;
    u8 pad_AE[0x6];
    f32 unk_B4;
};

/* fn_1_5C058 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

/* fn_1_5C058 */
struct fn_1_5C058_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[4];
    s16 unk_18;
    u8 pad_1A[2];
    f32 unk_1C, unk_20, unk_24;
    u8 pad_28[0x6C];
    f32 unk_94, unk_98;
    u8 pad_9C[0x10];
    s16 unk_AC;
};

/* fn_1_5C058 */
typedef struct { Fn183D28Vec3 pos; s32 color; } Fn5C058Vertex;

/* fn_1_5C784 */
typedef struct Vec3_5C784 {
    u32 x;
    u32 y;
    u32 z;
} Vec3_5C784;

/* fn_1_5C784 */
typedef struct EffectWork {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1a[0x22];
    Vec3_5C784 unk_3c;
    u8 pad_48[0x4c];
    Vec3_5C784 unk_94;
    u8 pad_a0[0x18];
    u8 unk_b8;
} EffectWork;

/* fn_1_5C83C */
struct Fn1_5C83CObject {
    u8 state;
    u8 _pad01[0xf];
    s32 age;
    u8 _pad14[0x4];
    s16 owner;
    u8 _pad1a[0x2];
    f32 color_1c;
    f32 color_20;
    f32 color_24;
    f32 size;
    f32 target_size;
    u8 _pad30[0xc];
    f32 pos_3c;
    f32 pos_40;
    f32 pos_44;
    f32 vel_48;
    f32 vel_4c;
    f32 vel_50;
    u8 _pad54[0x34];
    f32 blend;
    f32 target_blend;
    u8 _pad90[0x4];
    f32 acc_94;
    f32 acc_98;
    f32 acc_9c;
    u8 _pada0[0x12];
    u16 flag_b2;
    u8 _padb4[0x4];
    u8 matrix_b8[1];
};

/* fn_1_5CA00 */
struct fn_1_5CA00_Arg0 { u8 pad_0[0x18]; s16 unk_18; u8 pad_1A[0x22]; Fn183D28Vec3 unk_3C; };

/* fn_1_5CA00 */
struct Draw5CA { f32 width,height; u32 mtx[12]; u32 flags; s8 r; u8 g,b,a; };

/* fn_1_5D014 */
typedef struct Fn1_5D014Object {
    u8 pad[0xae];
    s16 field_ae;
} Fn1_5D014Object;

/* fn_1_5D020 */
typedef struct Fx {
    u8 state;
    u8 pad1[0xF];
    s32 unk10;
    u8 pad14[8];
    f32 unk1c, unk20, unk24, unk28, unk2c;
    u8 pad30[0xC];
    f32 unk3c, unk40, unk44, unk48, unk4c, unk50;
    u8 pad54[0x34];
    f32 unk88, unk8c;
    u8 pad90[0x1C];
    s16 unkac, unkae;
} Fx;

/* fn_1_5D1B8 */
typedef struct { f32 x; f32 y; f32 z; } Vec3_5D1B8;

/* fn_1_5D1B8 */
typedef struct { f32 x; f32 y; Vec3_5D1B8 pos; u8 pad_14[0x28]; u8 r; u8 g; u8 b; u8 a; } Quad;

/* fn_1_5D1B8 */
typedef struct { u8 pad_00[0x14]; f32 f_14; } Obj;

/* fn_1_5D1B8 */
typedef struct {
u8 pad_00[0x14]; f32 f_14; u8 pad_18[4];
f32 f_1c; f32 f_20; f32 f_24; f32 f_28;
u8 pad_2c[8]; Obj *f_34; u8 pad_38[4]; Vec3_5D1B8 v_3c;
u8 pad_48[0x66]; s16 s_ae;
} Self;

/* fn_1_5D378 */
typedef struct fn_1_5D378_obj {
    s8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[4];
    s16 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
} fn_1_5D378_obj;

/* fn_1_5D500 */
typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_C;
    s32 unk_10;
    u32 unk_14;
    s16 unk_18;
    u8 pad_1A[2];
    f32 unk_1C, unk_20, unk_24;
    u8 pad_28[0x14];
    u8 unk_3C[3];
} EffectUpdate;

/* fn_1_5D718 */
struct Fn15D718 {
	u8 _pad00[0x1c];
	f32 value1c;
	f32 value20;
	f32 value24;
	f32 value28;
	u8 _pad2c[0x08];
	u32 object34;
	u8 _pad38[0x04];
	f32 value3c;
};

/* fn_1_5D718 */
struct Fn15D718Tmp {
	u8 data[0x30];
};

/* fn_1_5D718 */
struct Fn15D718Sub {
	u8 data[0x34];
};

/* fn_1_5D718 */
struct Fn15D718Work {
	f32 alpha;
	f32 alpha2;
	struct Fn15D718Sub sub;
	u8 red;
	u8 green;
	u8 blue;
	u8 alphaByte;
};

/* fn_1_5D88C */
struct Fn15D88C {
    u8 _pad08[0x08];
    u32 flags;
    u8 _pad0c[0x1c];
    f32 value28;
    u8 _pad2c[0x08];
    u32 enabled;
    u8 _pad38[0x1c];
    u16 value54;
    u16 value56;
    u16 value58;
    u8 _pad5a[0x5a];
    f32 value_b4;
};

/* fn_1_5D91C */
typedef struct Fn5D91CVec {
    f32 x;
    f32 y;
    f32 z;
} Fn5D91CVec;

/* fn_1_5D91C */
typedef struct Fn5D91CObj {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    u8 pad_c[4];
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2c[8];
    u32 unk_34;
    u8 pad_38[4];
    Fn5D91CVec unk_3c;
    Fn5D91CVec unk_48;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5a;
    s16 unk_5c;
    s16 unk_5e;
    Fn5D91CVec unk_60;
    u8 pad_6c[0x1c];
    f32 unk_88;
    f32 unk_8c;
    u8 pad_90[4];
    f32 unk_94;
    f32 unk_98;
    f32 unk_9c;
    u8 pad_a0[0x14];
    f32 unk_b4;
    u8 unk_b8[4];
} Fn5D91CObj;

/* fn_1_5DFA4 */
struct fn_1_6400_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_5DFA4 */
typedef struct CameraTarget {
    u8 pad_000[0x394];
    void *data;
} CameraTarget;

/* fn_1_5DFA4 */
struct fn_1_AA54_lbl_1_rodata_388 {
    f64 unk_0;
};

/* fn_1_5DFA4 */
typedef struct Vec3f_5DFA4 {
    f32 x, y, z;
} Vec3f_5DFA4;

/* fn_1_5DFA4 */
typedef struct camera_reset_transition_Camera {
    u8 pad_00[0xA4];
    s16 unk_A4;
} camera_reset_transition_Camera;

/* fn_1_5DFA4 */
typedef struct camera_update_transition_Camera {
    u8 pad_00[0x78];
    s16 unk_78;
    u8 pad_7A[0x2A];
    s16 unk_A4;
} camera_update_transition_Camera;

/* fn_1_5DFA4 */
typedef struct Transform {
    u8 pad_08[0x8];
    f32 unk_08;
    u8 pad_0c[0xc];
    f32 unk_18;
    u8 pad_1c[0xc];
    f32 unk_28;
    u8 pad_2c[0x24];
    u8 unk_50[0x2c];
    u32 unk_7C;
} Transform;

/* fn_1_5DFA4 */
typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

/* fn_1_5DFA4 */
typedef struct { u8 pad_0[0x4]; f32 unk_4; u32 unk_8; f32 unk_C; } Bss_104C;

/* fn_1_5DFA4 */
typedef struct fn_1_ABAC_Target {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_ABAC_Target;

/* fn_1_5DFA4 */
typedef struct { u8 pad_0[0x20]; u32 unk_20; } Inner;

/* fn_1_5DFA4 */
typedef struct { u8 pad_0[0x8]; Inner *unk_8; } Outer;

/* fn_1_5DFA4 */
typedef struct {
    u8 data[0x10];
} CamEntry;

/* fn_1_5DFA4 */
typedef struct {
    u8 pad_0[0x14c];
    Fn183D28Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

/* fn_1_5DFA4 */
typedef struct {
    u8 pad_0[0x8];
    Fn183D28Vec3 dir;
    f32 radius;
} Fn183D28Target;

/* fn_1_5DFA4 */
typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

/* fn_1_5DFA4 */
typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

/* fn_1_5DFA4 */
typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

/* fn_1_5DFA4 */
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

/* fn_1_5DFA4 */
typedef struct {
    u32 flags;
    u8 pad_4[0x5];
    u8 count;
    u8 pad_A[0x14AE];
    f64 pad_14B8;
} CarTestInfo;

/* fn_1_5DFA4 */
typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

/* fn_1_5DFA4 */
struct fn_1_5DFA4_lbl_1_rodata_2950 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x20];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    f64 unk_40;
    f64 unk_48;
    f32 unk_50;
    f32 unk_54;
    u8 pad_58[0x4];
    f32 unk_5C;
    u8 pad_60[0x20];
    f32 unk_80;
    u8 pad_84[0x8];
    f32 unk_8C;
    u8 pad_90[0x10];
    f32 unk_A0;
    u8 pad_A4[0x14];
    f32 unk_B8;
    u8 pad_BC[0x3C];
    f64 unk_F8;
    u8 pad_100[0x50];
    f32 unk_150;
    u8 pad_154[0x4];
    f64 unk_158;
    u8 pad_160[0x68];
    f32 unk_1C8;
    f32 unk_1CC;
    f64 unk_1D0;
    f32 unk_1D8;
    f32 unk_1DC;
};

/* fn_1_5DFA4 */
typedef struct {
    u8 pad_0[0x8];
    u32 flags;
    u8 pad_C[0x4];
    s32 timer;
    u8 pad_14[0x8];
    f32 color[3];
    u8 pad_28[0xC];
    void *model;
    u8 pad_38[0x4];
    Vec3 pos;
    Vec3 scale;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_5A[0x6];
    Vec3 prev_pos;
    u8 pad_6C[0x48];
    f32 alpha;
} Fn5DFA4Effect;

/* fn_1_5DFA4 */
typedef struct {
    Vec3 pos;
    u8 color[4];
} Fn5DFA4Point;

/* fn_1_5DFA4 */
typedef struct {
    f32 scale;
    f32 unk_4;
    u8 unk_8[0x34];
    u8 color[4];
} Fn5DFA4Draw;

/* fn_1_5E3C4 */
struct fn_1_5E3C4_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x9E];
    u16 unk_B2;
};

/* fn_1_5E4D8 */
typedef struct FzgxV3 {
    f32 x, y, z;
} FzgxV3;

/* fn_1_5EB08 */
typedef struct FnObj {
    u8 pad18[0x18];
    s16 value;
    u8 pad3c[0x22];
    f32 field3c;
} FnObj;

/* fn_1_5EB08 */
typedef struct FnLocal {
    u8 data[0x10];
} FnLocal;

/* fn_1_5EB08 */
typedef struct FnNode {
    u8 pad4[4];
    void (*callback)(void);
    FnObj *object;
} FnNode;

/* fn_1_5EB98 */
typedef struct { s32 type; f32 time, value, tanIn, tanOut; } Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey;

/* fn_1_5EB98 */
struct Sig_fn_1_9EA94_fn_1_9EA94_Arg0 { u8 pad_0[0xC]; f32 unk_C; };

/* fn_1_5EB98 */
struct fn_1_5EB98_Arg0 { u8 pad_0[8]; u32 unk_8; };

/* fn_1_5EB98 */
typedef struct { f32 x, y, z; } Fn5EB98Vec;

/* fn_1_5EB98 */
typedef struct { u8 r, g, b, a; } Fn5EB98Color;

/* fn_1_5EB98 */
typedef struct { Fn5EB98Vec pos; Fn5EB98Color color; } Fn5EB98Vertex;

/* fn_1_5F5C8 */
struct fn_1_5F5C8_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

/* fn_1_5F5C8 */
struct fn_1_5F5C8_lbl_1_data_1D628 {
    u32 unk_0;
};

/* fn_1_5F5C8 */
struct fn_1_5F5C8_lbl_1_rodata_2950 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0x44];
    f32 unk_6C;
    u8 pad_70[0x48];
    f32 unk_B8;
};

/* fn_1_5F654 */
typedef struct fn_1_5F654_Effect {
    u8 pad_00[0x8];
    u32 flags;
    u8 pad_0C[0x4];
    s32 frame;
    u8 pad_14[0x4];
    s16 id;
    u8 pad_1A[0x2];
    f32 color[3];
    f32 speed;
    u8 pad_2C[0x10];
    Fn183D28Vec3 pos;
    u8 pad_48[0xC];
    s16 rot_x;
    s16 rot_y;
    u8 pad_58[0x2];
    s16 rot_vel_x;
    s16 rot_vel_y;
    u8 pad_5E[0x56];
    f32 alpha;
} fn_1_5F654_Effect;

/* fn_1_5F654 */
typedef struct {
    u8 pad_000[0x475];
    u8 camera;
} fn_1_5F654_Owner;

/* fn_1_5F9B8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_5F9B8_Vec;

/* fn_1_5F9B8 */
typedef struct {
    u8 pad_0[0x18];
    s16 id;
    u8 pad_1A[0x2];
    f32 red;
    f32 green;
    f32 blue;
    f32 size;
    u8 pad_2C[0x10];
    fn_1_5F9B8_Vec pos;
    u8 pad_48[0xC];
    s16 rot_x;
    s16 rot_y;
    u8 pad_58[0x5C];
    f32 scale;
} fn_1_5F9B8_Effect;

/* fn_1_5F9B8 */
typedef struct {
    fn_1_5F9B8_Vec pos;
    f32 radius;
    s16 flags;
    u8 pad_12[0x2];
    u8 color[4];
} fn_1_5F9B8_Light;

/* fn_1_5F9B8 */
typedef struct {
    u8 pad_0[0x8];
    fn_1_5F9B8_Vec pos;
    u8 pad_14[0x10];
    void *tex;
} fn_1_5F9B8_Model;

/* fn_1_5F9B8 */
typedef struct {
    u8 pad_0[0xA0];
    fn_1_5F9B8_Model *glow;
    u8 pad_A4[0x7C];
    void *model;
} fn_1_5F9B8_Assets;

/* fn_1_5FE30 */
typedef struct {
    u8 unk[0x18];
    s16 value;
    u8 unk1A[0x0E];
    f32 rate;
    u8 unk2C[0x10];
    u8 field3C[1];
} fn_1_5FE30_FZeroObject;

/* fn_1_5FE30 */
typedef struct {
    u8 unk0[4];
    void (*callback)(void);
    fn_1_5FE30_FZeroObject *owner;
} FZeroEvent;

/* fn_1_5FFB0 */
struct fn_1_5FFB0_p {
    u8 pad_0[0x10];
    s32 unk_10;
    s32 unk_14;
    u8 pad_18[0x20];
    void *unk_38;
    u8 pad_3C[0x18];
    s16 unk_54;
};

/* fn_1_60170 */
typedef struct {
    u8 unk[0x38];
    void *field38;
} fn_1_60170_FZeroObject;

/* fn_1_601B4 */
typedef struct {
    u8 unk_0[0x10];
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x24];
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
    f32 unk_50;
    u8 unk_54[0x60];
    f32 unk_b4;
} EffectState;

/* fn_1_6028C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} BeamVec;

/* fn_1_6028C */
typedef struct {
    u8 pad_00[0x14];
    s32 timer;          /* 0x14 */
    u8 pad_18[0x10];
    f32 scale;          /* 0x28 */
    u8 pad_2C[0x4];
    f32 angle;          /* 0x30 */
    u8 pad_34[0x8];
    BeamVec start;      /* 0x3C */
    u8 pad_48[0xC];
    s16 variant;        /* 0x54 */
    u8 pad_56[0x32];
    BeamVec end;        /* 0x88 */
    u8 pad_94[0x1E];
    u16 alt;            /* 0xB2 */
    f32 alpha;          /* 0xB4 */
} BeamEffect;

/* fn_1_6028C */
typedef struct {
    u8 pad_000[0xF90];
    u32 seed;               /* 0xF90 */
    u8 pad_F94[0x1188 - 0xF94];
    char beamNames[4][0x14]; /* 0x1188 */
    char missing[0xC];      /* 0x11D8 */
    char glowAlt[0x14];     /* 0x11E4 */
    char glow[0x14];        /* 0x11F8 */
} EffectData;

/* fn_1_6028C */
typedef struct {
    u8 pad_00[0x28];
    f32 one;
    u8 pad_2C[0x28];
    f32 half;
    u8 pad_58[0x70];
    f32 angleScale;
    u8 pad_CC[0x17C];
    f64 percent;
    f32 width;
} BeamConstants;

/* fn_1_60734 */
typedef struct Fn60734 {
    u8 pad_00[0x0e];
    s16 unk_0e;
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2c[0x28];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} Fn60734;

/* fn_1_60880 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Avl60880Vec;

/* fn_1_60880 */
typedef struct {
    u8 state;           // 0x00
    u8 pad_1[0x27];
    f32 size;           // 0x28
    u8 pad_2C[0x10];
    Avl60880Vec pos;    // 0x3c
    Avl60880Vec vel;    // 0x48
    s16 rotX;           // 0x54
    s16 rotY;           // 0x56
    s16 rotZ;           // 0x58
    s16 spinX;          // 0x5a
    s16 spinY;          // 0x5c
    s16 spinZ;          // 0x5e
} Avl60880Obj;

/* fn_1_60B80 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Sig_fn_1_5557C_Fn1_5557CObject;

/* fn_1_60B80 */
typedef Sig_fn_1_5557C_Fn1_5557CObject Sig_fn_1_555D0_Fn1_555D0Object;

/* fn_1_60B80 */
typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x14];
    f32 unk_28;
    u8 unk_2C[0x8];
    Sig_fn_1_5557C_Fn1_5557CObject *unk_34;
    u8 unk_38[0x4];
    u32 unk_3C;
    u8 unk_40[0x14];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} Sig_fn_1_60B80_Obj;

/* fn_1_60C74 */
struct fn_1_60C74_Effect {
    u8 _pad[0x28];
    f32 field_28;
};

/* fn_1_60C88 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_f;

/* fn_1_60C88 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4_f;

/* fn_1_60C88 */
typedef struct {
    u8 pad_00[0x10];
    u32 i10;
    u8 pad_14[4];
    s16 s18;
    u8 pad_1A[0xE];
    f32 f28;
    u8 pad_2C[0x10];
    Vec4_f v3c;
    u8 pad_4C[0x48];
    Vec4_f v94;
    u8 pad_A4[0x10];
    f32 fb4;
} Obj_60C88;

/* fn_1_60D54 */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_60D54_Color;

/* fn_1_60D54 */
typedef struct {
    u8 pad[0x3c];
    fn_1_60D54_Color color;
} fn_1_60D54_Light;

/* fn_1_60F84 */
typedef struct fn_1_58D38_EffectEntry_fn_1_60F84 {
    s8 unk_00;
    u8 pad_01[7];
    u32 unk_08;
    s16 unk_0C;
    u8 pad_0E[0x0C];
    u16 unk_1A;
    u8 pad_1C[0xCC];
} fn_1_58D38_EffectEntry_fn_1_60F84;

/* fn_1_60F84 */
struct fn_1_5BF70_lbl_1_rodata_2950_fn_1_60F84 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0xC8];
    f64 unk_F0;
    f64 unk_F8;
    u8 pad_100[0x30];
    f64 unk_130;
};

/* fn_1_60F84 */
typedef struct {
    u8 unk00[0x18];
    s16 value18;
    u8 unk1A[2];
    f32 value1C;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 unk2C[8];
    void *field34;
    u8 unk38[0x1c];
    s16 value54;
    s16 value56;
} fn_1_5FEBC_EffectData_fn_1_60F84;

/* fn_1_60F84 */
typedef struct {
    u8 unk00[8];
    fn_1_5FEBC_EffectData_fn_1_60F84 *data;
} fn_1_5FEBC_EffectObject_fn_1_60F84;

/* fn_1_60F84 */
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x20];
    u32 unk_34;
    void *unk_38;
    u8 pad_3c[0x18];
    s16 unk_54;
    u8 pad_56[0x4];
    u16 unk_5a;
    u8 pad_5c[0x58];
    f32 unk_b4;
} fn_1_61D08_EffectObject_fn_1_60F84;

/* fn_1_60F84 */
typedef struct {
    u8 pad_00[0x8];
    void *unk_08;
} fn_1_652F4_Effect_fn_1_60F84;

/* fn_1_60F84 */
typedef struct {
    u8 pad20[0x20];
    void *unk_20;
} Fn1_61E60Node_fn_1_60F84;

/* fn_1_60F84 */
typedef struct {
    u8 pad38[0x38];
    Fn1_61E60Node_fn_1_60F84 *unk_38;
} Fn1_61E60Object_fn_1_60F84;

/* fn_1_60F84 */
typedef struct fn_1_60F84_Effect {
    u8 pad0[0x10];
    s32 age;
    u8 pad14[8];
    f32 color_1c;
    f32 color_20;
    f32 color_24;
    f32 size;
    f32 target_size;
    u8 pad30[0xC];
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 vel_x;
    f32 vel_y;
    f32 vel_z;
} fn_1_60F84_Effect;

/* fn_1_61070 */
typedef struct Fn161070 {
    u8 pad00[0x1c];
    f32 field1c;
    f32 field20;
    f32 field24;
    f32 field28;
    u8 pad2c[0x8];
    int field34;
    u8 pad38[0x4];
    u8 field3c[0x1c];
    s16 field58;
} Fn161070;

/* fn_1_61070 */
typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
} Vec;

/* fn_1_61070 */
typedef struct Mat44 {
    f32 m[4][4];
} Mat44;

/* fn_1_61070 */
typedef struct EfxData {
    f32 field0;
    f32 field4;
    u8 mtx[0x34];
    u8 color[4];
} EfxData;

/* fn_1_61070 */
typedef struct Fade {
    f32 m[12];
} Fade;

/* fn_1_611EC */
struct FxParam {
	u8 pad_00[0x0E];
	u16 unk_0E;
	s32 unk_10;
	u8 pad_14[0x14];
	f32 f_28;
	u8 pad_2C[0x0C];
	void *unk_38;
	u8 pad_3C[0x18];
	u16 unk_54;
	u16 unk_56;
	u16 unk_58;
};

/* fn_1_61370 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_61370_Vec;

/* fn_1_61370 */
typedef struct {
    u8 pad_0[0x14];
    s32 count;
    u8 pad_18[0x10];
    f32 scale;
    u8 pad_2C[0xC];
    fn_1_61370_Vec *trail;
    fn_1_61370_Vec pos;
    fn_1_61370_Vec vel;
    s16 ang[3];
    s16 rot[3];
    u8 pad_60[0x4C];
    s16 unk_AC;
} fn_1_61370_Obj;

/* fn_1_61370 */
typedef struct {
    u8 pad_0[0x28];
    f32 c_28; /* 0x028: 1.0 */
    u8 pad_2c[0x24];
    f32 c_50; /* 0x050: 0.0 */
    u8 pad_54[0x88];
    f32 c_dc; /* 0x0dc: 0.949999988079071 */
    u8 pad_e0[0xe0];
    f32 c_1c0; /* 0x1c0: 512.0 */
    u8 pad_1c4[0xa4];
    f64 c_268; /* 0x268: 0.003 */
    u8 pad_270[0x40];
    f32 c_2b0; /* 0x2b0: -0.8999999761581421 */
} EffectPool61370;

/* fn_1_61640 */
struct Fn1_61640Pool {
    u8 _pad00[0x28];
    f32 initial;
    u8 _pad2c[0xc];
    f64 int_bias;
    u8 _pad40[0x4c];
    f32 scale;
    u8 _pad90[0x200];
    f64 threshold;
};

/* fn_1_61640 */
struct Fn1_61640Object {
    u8 _pad10[0x10];
    s32 field_10;
    u8 _pad14[0x4];
    s16 field_18;
    u8 _pad1a[0xe];
    f32 field_28;
    u8 _pad2c[0x8];
    void *field_34;
    u8 _pad38[0x4];
    f32 field_3c[3];
    u8 _pad48[0xc];
    s16 field_54;
    s16 field_56;
    s16 field_58;
};

/* fn_1_61760 */
struct Fn1_61760Object {
    u8 _pad38[0x38];
    void *effect_resource;
};

/* fn_1_617A4 */
struct Fn1_617A4Object {
    u8 _pad10[0x10];
    s32 unk_10;
    u8 _pad14[0x80];
    f32 unk_94;
    f32 unk_98;
};

/* fn_1_618B8 */
struct obj_state {
	u8 pad00[0x10];
	s32 timer;
	u8 pad14[8];
	f32 f1c;
	f32 f20;
	f32 f24;
	f32 f28;
	f32 f2c;
	u8 pad30[0xc];
	f32 f3c;
	f32 f40;
	f32 f44;
	f32 f48;
	f32 f4c;
	f32 f50;
	u8 pad54[0x40];
	f32 f94;
	f32 f98;
};

/* fn_1_619E4 */
struct fn_1_619E4_pool {
u8 pad_0[0x28];
f32 one;
u8 pad_2C[0x24];
f32 zero;
f32 half;
u8 pad_58[0x4];
f32 c255;
u8 pad_60[0x40];
f32 two;
u8 pad_A4[0x214];
f32 widthScale;
};

/* fn_1_619E4 */
typedef struct fn_1_619E4_Obj {
u8 pad_0[0x1C];
f32 red;
f32 green;
f32 blue;
f32 radius;
u8 pad_2C[0x8];
void *model;
u8 pad_38[0x4];
Vec3 end;
u8 pad_48[0x18];
Vec3 start;
} fn_1_619E4_Obj;

/* fn_1_619E4 */
typedef struct fn_1_619E4_DrawParam {
f32 scale;
f32 unk4;
f32 mtx[3][4];
f32 unk38;
u8 r, g, b, a;
} fn_1_619E4_DrawParam;

/* fn_1_61D08 */
typedef struct {
    u8 pad_0[0x20];
    void *unk_20;
} EffectChild;

/* fn_1_61D08 */
typedef struct {
    u8 pad_0[0x130];
    u32 unk_130;
} EffectInner;

/* fn_1_61EF4 */
struct P {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x18];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x20];
    f32 unk_60;
    f32 unk_64;
    u8 pad_68[0xC];
    f32 unk_74;
    u8 pad_78[0x54];
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
};

/* fn_1_61EF4 */
typedef struct Fn620C8Viewport {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 near;
    f32 far;
} Fn620C8Viewport;

/* fn_1_61EF4 */
typedef struct Obj_61EF4 {
    u8 b0;
    u8 pad1[0xF];
    s32 n10;
    u8 pad14[4];
    s16 id18;
    u8 pad1a[0x0E];
    f32 f28;
    f32 f2c;
    u8 pad30[0x0C];
    f32 m3c[3];
    f32 f48;
    f32 f4c;
    f32 f50;
    s16 s54;
    u8 pad56[4];
    s16 s5a;
    u8 pad5c[0x38];
    f32 p94[3];
    u8 pada0[0x14];
    f32 fb4;
} Obj_61EF4;

/* fn_1_61EF4 */
typedef struct Fn620C8Model {
    u8 pad_0[0x8];
    u8 data[0xC];
    f32 scale;
} Fn620C8Model;

/* fn_1_61EF4 */
typedef struct Fn620C8TexObj {
    u32 dummy[8];
    void *image;
} Fn620C8TexObj;

/* fn_1_61EF4 */
typedef struct Fn620C8Obj {
    u8 pad_0[0x28];
    f32 time;
    u8 pad_2C[0x8];
    Fn620C8Model *model;
    Fn620C8TexObj *tex;
    u8 rot[0x78];
    f32 brightness;
    Fn183D28Vec3 pos;
} Fn620C8Obj;

/* fn_1_620C8 */
typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

/* fn_1_620C8 */
struct fn_1_620C8_lbl_1_rodata_2950 {
    u8 pad_0[0x28];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x10];
    f32 unk_50;
    u8 pad_54[0x24];
    f32 unk_78;
    u8 pad_7C[0x248];
    f32 unk_2C4;
};

/* fn_1_62360 */
typedef union { f32 f32; u8 u8; } Fifo;

/* fn_1_62794 */
typedef struct { u32 dummy[8]; } TexObj62794;

/* fn_1_62794 */
struct fn_1_62794_pool {
    u8 pad_0[0x50];
    f32 unk_50;
    f32 unk_54;
    u8 pad_58[0x154];
    f32 unk_1AC;
};

/* fn_1_62AF8 */
struct fn_1_62AF8_obj {
    u8 pad_00[0x0E];
    s16 unk_0E;
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2C[0x28];
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
};

/* fn_1_62C84 */
typedef struct {
 u8 unk_0; u8 pad_1[0x27]; f32 unk_28; u8 pad_2C[0x10];
 f32 unk_3C, unk_40, unk_44, unk_48, unk_4C, unk_50;
 s16 unk_54, unk_56, unk_58, unk_5A, unk_5C, unk_5E;
} Particle;

/* fn_1_62E9C */
typedef struct EffVec3 {
    f32 x;
    f32 y;
    f32 z;
} EffVec3;

/* fn_1_62E9C */
typedef struct EffRot3 {
    s16 x;
    s16 y;
    s16 z;
} EffRot3;

/* fn_1_62E9C */
struct Eff62E9C {
    u8 pad_0[0x10];
    s32 unk_10;
    u8 pad_14[0x8];
    f32 r;
    f32 g;
    f32 b;
    f32 size;
    u8 pad_2C[0x8];
    void *unk_34;
    u8 pad_38[0x4];
    EffVec3 pos;
    u8 pad_48[0xC];
    EffRot3 rot;
};

/* fn_1_62E9C */
struct EffPacket62E9C {
    f32 unk_0;
    f32 unk_4;
    f32 mtx[12];
    u8 pad_38[0x4];
    u8 color[4];
};

/* fn_1_63130 */
struct fn_1_63130_obj {
    u8 unk_00[0xAE];
    s16 unk_AE;
};

/* fn_1_632D4 */
struct fn_1_632D4_obj {
    u8 unk_00[0x1C];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C[0x8];
    int unk_34;
    u8 unk_38[0x4];
    void *unk_3C;
    u8 unk_40[0x6E];
    s16 unk_AE;
};

/* fn_1_632D4 */
struct fn_1_632D4_data {
    f32 unk_00;
    f32 unk_04;
    u8 unk_08[0x34];
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
};

/* fn_1_633C0 */
typedef struct { f32 x, y, z; } FxVec;

/* fn_1_633C0 */
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
    s16 unk18;
    u8 pad1A[0x3c - 0x1a];
    FxVec unk3c;
    u8 pad48[0x60 - 0x48];
    FxVec unk60;
    u8 pad6c[0x94 - 0x6c];
    FxVec unk94;
} FxObj633C0;

/* fn_1_63518 */
typedef struct Effect_63518_vec {
    u32 x;
    u32 y;
    u32 z;
} Effect_63518_vec;

/* fn_1_63518 */
typedef struct Effect_63518_63518 {
    u8 unk00[0x14];
    u32 unk14;
    u8 unk18[0x20];
    Effect_63518_vec *unk38;
    Effect_63518_vec unk3c;
    u8 unk48[0x10];
    u16 unk58;
    u8 unk5a[0x06];
    Effect_63518_vec unk60;
    u8 unk6c[0x40];
    u16 unkac;
    u16 unkae;
    u16 unkb0;
} Effect_63518_63518;

/* fn_1_635BC */
typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

/* fn_1_635BC */
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

/* fn_1_635BC */
typedef struct {
    u8 pad0[0x24];
    void *field_24;
} EventData;

/* fn_1_635BC */
typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

/* fn_1_635BC */
struct fn_1_7F954_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_635BC */
struct fn_1_7FA04_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_635BC */
typedef struct {
    u8 pad0[0x40];
    void *value;
} ResourceHolder;

/* fn_1_635BC */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RawVec3;

/* fn_1_635BC */
typedef struct Vec3f_635BC {
    f32 x, y, z;
} Vec3f_635BC;

/* fn_1_635BC */
typedef struct {
    u8 _pad_000[0x7c];
    Vec3 field_07c;
    u8 _pad_088[0xc4];
    Vec3 field_14c;
} Fn184644Object;

/* fn_1_635BC */
typedef struct Fn195158Object_635BC Fn195158Object_635BC;

/* fn_1_635BC */
struct Fn195158Object_635BC {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

/* fn_1_635BC */
struct TargetObj {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

/* fn_1_635BC */
struct ModelItem {
    u32 flags;
    char pad[0x1c];
};

/* fn_1_635BC */
struct Model {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem items[1];
};

/* fn_1_635BC */
typedef struct {
    u32 entries[41];
} FnTable;

/* fn_1_635BC */
typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Fn1_8F45C_Object;

/* fn_1_635BC */
typedef struct {
    s32 active;
    s32 entries[5];
} Fn1_8F494_Object;

/* fn_1_635BC */
typedef struct {
    u8 pad_0[0x148];
    u8 pad_148[0x20];
    u8 pad_168[0x40];
    u8 pad_1a8[0x20];
    u8 pad_1c8[0x20];
    u8 pad_1e8[0x20];
    u8 entries[0x14][0x20];
} Fn1_8F5A4_Object;

/* fn_1_635BC */
typedef struct Fn195158Data_635BC Fn195158Data_635BC;

/* fn_1_635BC */
struct Fn195158Data_635BC {
    u8 unk_00[0x08];
    Fn195158Object_635BC *unk_08;
};

/* fn_1_635BC */
typedef struct Fn195158Car_635BC Fn195158Car_635BC;

/* fn_1_635BC */
struct Fn195158Car_635BC {
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
    Fn195158Data_635BC *unk_150;
};

/* fn_1_635BC */
typedef struct Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Fn935E4Slot;

/* fn_1_635BC */
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

/* fn_1_635BC */
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

/* fn_1_635BC */
typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

/* fn_1_635BC */
typedef struct {
    u8 pad0[0x24];
    void *field_24;
    f32 field_28;
    f32 field_2c;
} OutData;

/* fn_1_635BC */
typedef struct {
    u8 pad0[0x1c];
    Node *field_1c;
    u8 pad20[0x128];
    u16 field_148;
    u8 pad14a[6];
    OutData *field_150;
    void *field_154;
} Owner;

/* fn_1_635BC */
typedef struct Fn1967A8Resource_635BC Fn1967A8Resource_635BC;

/* fn_1_635BC */
struct Fn1967A8Resource_635BC {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

/* fn_1_635BC */
typedef struct Fn196968Object_635BC Fn196968Object_635BC;

/* fn_1_635BC */
struct Fn196968Object_635BC {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

/* fn_1_635BC */
typedef struct Fn1969E8Owner_635BC Fn1969E8Owner_635BC;

/* fn_1_635BC */
struct Fn1969E8Owner_635BC {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

/* fn_1_635BC */
typedef struct Fn196BC0Object_635BC Fn196BC0Object_635BC;

/* fn_1_635BC */
struct Fn196BC0Object_635BC {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

/* fn_1_635BC */
typedef struct Fn196A68Object_635BC Fn196A68Object_635BC;

/* fn_1_635BC */
struct Fn196A68Object_635BC {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

/* fn_1_635BC */
typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

/* fn_1_635BC */
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

/* fn_1_635BC */
typedef struct {
    u8 pad[0x15];
    u8 code;
} State;

/* fn_1_635BC */
typedef struct {
    u8 pad[4];
    State *state;
} fn_1_8E3A4_Object;

/* fn_1_635BC */
typedef struct {
    u8 pad_0[0x400];
    u8 mtx[0x70];
    u8 mtx2[0x30];
} CamObj;

/* fn_1_635BC */
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

/* fn_1_635BC */
typedef struct {
    u32 flags;
    u8 pad_4[0x498];
    CarSound *sound;
} fn_1_85F90_Car;

/* fn_1_635BC */
typedef struct {
    u8 pad_0[0x8];
    u32 flags;
    u8 pad_C[0x4];
    s32 timer;
    u8 pad_14[0x4];
    s16 id;
    u8 pad_1A[0x2];
    f32 r;
    f32 g;
    f32 b;
    u8 pad_28[0x14];
    Fn183D28Vec3 pos;
    u8 pad_48[0xC];
    s16 rot_x;
    s16 rot_y;
    u8 pad_58[0x2];
    s16 vel_x;
    s16 vel_y;
    u8 pad_5E[0x36];
    Fn183D28Vec3 offset;
    u8 pad_A0[0x14];
    f32 unk_B4;
} Fn1635BCEffect;

/* fn_1_63858 */
struct LocalData {
    u8 data[0x10];
};

/* fn_1_63858 */
struct fn_1_63858_Event {
    u8 data[4];
    void (*callback)(void);
    void *owner;
};

/* fn_1_63858 */
struct fn_1_63858_Object {
    u8 data[0x18];
    s16 value;
};

/* fn_1_638E8 */
struct Sig_fn_1_867CC_fn_1_867CC_Arg1 { u32 unk_0, unk_4, unk_8; };

/* fn_1_638E8 */
struct Sig_fn_1_9EA94_fn_1_9EA94_Arg0_638E8 {
    Fn183D28Vec3 unk_0;
    f32 unk_C;
    u16 unk_10;
    u8 pad_12[2];
    u8 color[4];
};

/* fn_1_638E8 */
struct fn_1_638E8_row { Fn183D28Vec3 a[8]; };

/* fn_1_638E8 */
struct fn_1_638E8_Arg0 { u8 pad_0[8]; u32 unk_8; };

/* fn_1_638E8 */
struct fn_1_638E8_lbl_1_rodata_2950 {
    u8 pad_0[4]; f32 unk_4; f32 unk_8; u8 pad_C[0x14];
    f64 unk_20; f32 unk_28; u8 pad_2C[0x1C]; f64 unk_48;
    u8 pad_50[4]; f32 unk_54; u8 pad_58[4]; f32 unk_5C;
    u8 pad_60[0x20]; f32 unk_80; u8 pad_84[0x10]; f32 unk_94;
    u8 pad_98[0x38]; f32 unk_D0; u8 pad_D4[0x7C]; f32 unk_150;
    u8 pad_154[0xC8]; f32 unk_21C;
};

/* fn_1_638E8 */
struct fn_1_638E8_lbl_801A66CC { u32 unk_0; };

/* fn_1_638E8 */
struct fn_1_638E8_lbl_801A6D00_T {
    u8 pad_0[0x3C]; f32 unk_3C; u8 pad_40[0xC]; f32 unk_4C;
    u8 pad_50[0xC]; f32 unk_5C;
};

/* fn_1_64098 */
typedef struct Fn164098Object {
    u8 pad[0xae];
    u16 value;
} Fn164098Object;

/* fn_1_640A4 */
struct fn_1_640A4_lbl_1_rodata_2950 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x18];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x130];
    f32 unk_170;
    f32 unk_174;
    f32 unk_178;
    u8 pad_17C[0x98];
    f32 unk_214;
    u8 pad_218[0xFC];
    f32 unk_314;
    f32 unk_318;
    f32 unk_31C;
};

/* fn_1_642E8 */
typedef struct fn_1_642E8_EffectState {
    char bytes[0x14];
} fn_1_642E8_EffectState;

/* fn_1_642E8 */
typedef struct fn_1_642E8_EffectObject {
    char pad0[0x28];
    f32 value;
    char pad2c[0x10];
    fn_1_642E8_EffectState state;
} fn_1_642E8_EffectObject;

/* fn_1_642E8 */
typedef struct EffectNode {
    char pad0[4];
    void (*callback)(void);
    void *owner;
} EffectNode;

/* fn_1_64388 */
typedef struct { f32 x,y,z; } Vec3_64388;

/* fn_1_64388 */
typedef struct { u8 pad[0x14]; f32 f14; } NodeObj_64388;

/* fn_1_64388 */
typedef struct {
 u8 pad0[0x10]; s32 age;
 u8 pad14[8]; f32 x,y,z,size;
 u8 pad2c[8]; NodeObj_64388 *node;
 u8 pad38[4]; Vec3_64388 pos;
 u8 pad48[0x66]; s16 angle;
} SelfObj_64388;

/* fn_1_64388 */
typedef struct { u8 pad[8]; SelfObj_64388 *obj; } ArgObj;

/* fn_1_645D4 */
typedef struct { f32 x, y, z; } V3;

/* fn_1_645D4 */
struct A { u8 pad_0[0x18]; s16 unk_18; u8 pad_1a[0x22]; V3 unk_3c; u8 pad_48[0x4c]; V3 unk_94; };

/* fn_1_648DC */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec648DC;

/* fn_1_648DC */
typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
} Surface648DC;

/* fn_1_648DC */
typedef struct {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0xE];
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0x4];
    Surface648DC *unk_34;
    u8 pad_38[0x4];
    Vec648DC unk_3c;
    Vec648DC unk_48;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5a;
    s16 unk_5c;
    s16 unk_5e;
    Vec648DC unk_60;
    u8 pad_6C[0x1C];
    f32 unk_88;
    f32 unk_8c;
    u8 pad_90[0x10];
    Vec648DC unk_a0;
} Effect648DC;

/* fn_1_64F2C */
typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} Fn_1_64F2C_Object;

/* fn_1_64FB8 */
typedef struct { u32 x,y,z; } ClosureEffectWords;

/* fn_1_64FB8 */
typedef struct { f32 x,y,z; } ClosureEffectVec;

/* fn_1_64FB8 */
typedef struct { f32 values[12]; } ClosureEffectMatrix;

/* fn_1_65268 */
typedef struct {
    u32 pad_00;
    void (*vtable)(void);
    void *owner;
} Event;

/* fn_1_65268 */
typedef struct {
    u8 pad_00[0x18];
    s16 value;
    u8 pad_1a[0xe];
    f32 amount;
    u8 pad_2c[0x10];
    u8 embedded[1];
} Object;

/* fn_1_652F4 */
typedef struct {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x28];
    s16 unk_54;
    s16 unk_56;
} fn_1_652F4_EffectData;

/* fn_1_652F4 */
typedef struct {
    u8 pad_00[0x120];
    void *unk_120;
} EffectRoot;

/* fn_1_652F4 */
typedef struct {
    f32 value;
    f32 value2;
    u8 pad_08[0x34];
    u8 color[4];
} ParticleData;

/* fn_1_65424 */
typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} fn_1_65424_EffectObject;

/* fn_1_654B0 */
typedef struct Particle654B0 {
    u8 pad0[0x10];
    s32 age;          /* 0x10 */
    u8 pad14[0x1c - 0x14];
    f32 r;            /* 0x1c */
    f32 g;            /* 0x20 */
    f32 b;            /* 0x24 */
    f32 scale;        /* 0x28 */
    f32 scaleVel;     /* 0x2c */
    u8 pad30[0x3c - 0x30];
    f32 pos[3];       /* 0x3c */
    f32 vel[3];       /* 0x48 */
    s16 rot[2];       /* 0x54 */
    u8 pad58[2];
    s16 rotVel[2];    /* 0x5a */
    u8 pad5e[0x88 - 0x5e];
    f32 damp;         /* 0x88 */
    f32 dampTarget;   /* 0x8c */
    u8 pad90[0xb4 - 0x90];
    f32 halfAge;      /* 0xb4 */
} Particle654B0;

/* fn_1_656C8 */
typedef struct {
    u32 unk_00;
    void (*unk_04)(void);
    void *unk_08;
} EffectEvent;

/* fn_1_656C8 */
typedef struct {
    u8 unk_00[0x28];
    f32 unk_28;
    u8 unk_2c[0x10];
    u8 unk_3c[1];
} fn_1_656C8_EffectObject;

/* fn_1_65748 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_65748_Vec;

/* fn_1_65748 */
typedef struct {
    u8 pad_0[0x1C];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[0x10];
    fn_1_65748_Vec unk_3C;
    u8 pad_48[0x6C];
    f32 unk_B4;
} fn_1_65748_Effect;

/* fn_1_65748 */
typedef struct {
    u8 pad_0[0x8];
    fn_1_65748_Effect *unk_8;
} fn_1_65748_Event;

/* fn_1_65748 */
typedef struct {
    fn_1_65748_Vec pos;
    f32 radius;
    s16 flags;
    u8 pad_12[0x2];
    u8 color[4];
} fn_1_65748_Light;

/* fn_1_65748 */
typedef struct {
    u8 pad_0[0x8];
    fn_1_65748_Vec pos;
    u8 pad_14[0x10];
    void *tex;
} fn_1_65748_Model;

/* fn_1_65748 */
typedef struct {
    u8 pad_0[0xA8];
    fn_1_65748_Model *unk_A8;
} fn_1_65748_Assets;

/* fn_1_65AB0 */
typedef struct {
    u8 pad_00[0x10];
    s32 value_10;
    u8 pad_14[0x18];
    f32 value_2c;
    u8 pad_30[0x84];
    f32 value_b4;
} Fn165AB0Object;

/* fn_1_65B5C */
typedef struct EffP {
    s32 pad0[4];
    s32 i10;
    s32 pad14[2];
    f32 f1c, f20, f24, f28, f2c;
    s32 pad30[3];
    f32 f3c, f40, f44, f48, f4c, f50;
    u8 pad54[0xb4 - 0x54];
    f32 fb4;
} EffP;

/* fn_1_65CDC */
struct Fn1_65CDC {
	u8 _pad00[0x1c];
	f32 value1c;
	f32 value20;
	f32 value24;
	f32 value28;
	u8 _pad2c[0x08];
	u32 object34;
	u8 _pad38[0x04];
	f32 value3c;
	u8 _pad40[0x18];
	s16 value58;
};

/* fn_1_65CDC */
struct Fn1_65CDCTmp {
	u8 data[0x30];
};

/* fn_1_65CDC */
struct Fn1_65CDCSub {
	u8 data[0x34];
};

/* fn_1_65CDC */
struct Fn1_65CDCWork {
	f32 alpha;
	f32 alpha2;
	struct Fn1_65CDCSub sub;
	u8 red;
	u8 green;
	u8 blue;
	u8 alphaByte;
};

/* fn_1_65E58 */
typedef struct fn_1_65E58_Effect {
    u8 _pad_00[0x10];
    int field_10;
    u8 _pad_14[0x4];
    s16 field_18;
    u8 _pad_1a[0x9e];
} fn_1_65E58_Effect;

/* fn_1_65E8C */
typedef struct Effect65E8C_Owner {
    u8 pad_0[0x214];
    u16 active;
} Effect65E8C_Owner;

/* fn_1_65E8C */
typedef struct Effect65E8C {
    u8 pad_0[0x10];
    s32 timer;
    u8 pad_14[0x4];
    s16 mtxId;
    u8 pad_1A[0x1E];
    Effect65E8C_Owner *owner;
    Fn183D28Vec3 pos;
    u8 pad_48[0xC];
    s16 spinScale;
    s16 rotY;
    s16 rotZ;
    s16 velX;
    s16 velY;
    s16 velZ;
    u8 pad_60[0x58];
    u8 unk_B8[1];
} Effect65E8C;

/* fn_1_660EC */
typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x24];
    u8 *unk_38;
    u8 pad_3C[0x18];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} ObjFx_T;

/* fn_1_66254 */
typedef struct {
    u8 pad[0x28];
    f32 field_28;
    f32 field_2c;
} fn_1_66254_output;

/* fn_1_662D8 */
struct Sig_fn_1_862A8_fn_1_862A8_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

/* fn_1_662D8 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_8658C_Vec3U32;

/* fn_1_662D8 */
typedef struct {
    s8 active;
    u8 pad_1;
    s16 index;
    s16 serial;
    u8 pad_6[6];
    s16 type;
    u8 pad_E[2];
    s32 life;
    u8 pad_14[4];
    s16 car;
    u16 mode;
    f32 color_x, color_y, color_z;
    f32 param_28, param_2C;
    u8 pad_30[4];
    u32 asset;
    u8 pad_38[4];
    Fn183D28Vec3 pos;
    Fn183D28Vec3 vel;
    s16 angle_x, angle_y, angle_z;
    s16 unk_5A, unk_5C;
    u8 pad_5E[0x12];
    Fn183D28Vec3 direction;
    u8 pad_7C[0xC];
    f32 param_88, param_8C;
    u8 pad_90[4];
    Fn183D28Vec3 anchor;
    Fn183D28Vec3 aux;
    s16 unk_AC;
    u8 pad_AE[0x3A];
} Fn662D8Effect;

/* fn_1_662D8 */
typedef struct {
    u8 pad_0[0x148];
    u32 unk_148;
    u8 pad_14C[0x1C];
    u32 unk_168;
} Fn662D8Assets;

/* fn_1_662D8 */
typedef struct { f32 x, y, z, pad; } Sig_fn_8006FA24_Vector;

/* fn_1_662D8 */
typedef struct { Sig_fn_8006FA24_Vector a, b, c; } Sig_fn_8006FA24_Basis;

/* fn_1_662D8 */
typedef Fn662D8Effect Fn662D8Source;

/* fn_1_67294 */
typedef struct {
	f32 e[0x60];
} Pool;

/* fn_1_67294 */
typedef struct {
	u8 pad_0[0x168];
	u32 unk_168;
} Ctx;

/* fn_1_67294 */
typedef struct {
	f32 x, y, z;
} Vec3_67294;

/* fn_1_67294 */
typedef struct {
	u8 pad_0[0x30];
} VecObj;

/* fn_1_67294 */
typedef struct {
	u8 pad_0[0x34];
} Inner_67294;

/* fn_1_67294 */
typedef struct {
	f32 unk_0;
	f32 unk_4;
	Inner_67294 unk_8;
	u8 unk_3C;
	u8 unk_3D;
	u8 unk_3E;
	u8 unk_3F;
} Buf;

/* fn_1_67294 */
typedef struct {
	u8 pad_0[0x1C];
	f32 unk_1C;
	f32 unk_20;
	f32 unk_24;
	f32 unk_28;
	u8 pad_2C[0x10];
	u8 unk_3C;
} Obj_67294;

/* fn_1_67414 */
struct fn_1_67414_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0xa0];
    f32 unk_b4;
};

/* fn_1_67430 */
typedef struct {
    f32 x, y, z;
} Vec3f_67430;

/* fn_1_67430 */
typedef struct {
    f32 x, y, z;
    u8  pad[40];
} Vec3fBig;

/* fn_1_67430 */
typedef struct {
    u8    pad00[0x10];
    u32   unk10;
    u8    pad14[4];
    s16   unk18;
    u8    pad1a[0x0E];
    f32   f28;
    f32   f2c;
    u8    pad30[0x0C];
    Vec3f_67430 v3c;
    Vec3f_67430 v48;
    u8    pad54[0x40];
    Vec3f_67430 v94;
    u8    padA0[0x14];
    f32   fb4;
} Obj67430;

/* fn_1_6755C */
typedef struct {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1a[2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x88];
    f32 unk_b4;
} FnObj_6755C;

/* fn_1_6755C */
typedef struct {
    u8 pad_0[0x120];
    u32 unk_120;
} Root_6755C;

/* fn_1_6766C */
typedef struct {
    u8 padding[0xb4];
    f32 value;
} Fn6766CObject;

/* fn_1_67680 */
typedef struct EffectVec {
    f32 x, y, z;
} EffectVec;

/* fn_1_67680 */
typedef struct EffectPoolState {
    u8 *pool[2];
    s16 serial;
} EffectPoolState;

/* fn_1_67D0C */
typedef struct {
	u8 pad_0[0x50];
	u32 unk_50;
} Ctx_67D0C;

/* fn_1_67D0C */
typedef struct {
	u8 pad_0[0x8];
	Ctx_67D0C *unk_8;
} Mid;

/* fn_1_67D0C */
typedef struct {
	Mid *unk_0;
} Hdr;

/* fn_1_67D0C */
typedef struct {
	f32 x, y, z;
} Vec3_67D0C;

/* fn_1_67D0C */
typedef struct {
	u8 pad_0[0x34];
} Inner_67D0C;

/* fn_1_67D0C */
typedef struct {
	u8 pad_0[0x1C];
	f32 unk_1C;
	f32 unk_20;
	f32 unk_24;
	f32 unk_28;
	u8 pad_2C[0x10];
	u8 unk_3C;
	u8 unk_3D;
	u8 unk_3E;
	u8 unk_3F;
	u8 pad_40[0x74];
	f32 unk_B4;
} Obj_67D0C;

/* fn_1_67F20 */
typedef struct Fn167F20 {
    u8 pad00[0x10];
    s32 state;
    u8 pad14[0x08];
    f32 value1c;
    f32 value20;
    f32 value24;
    f32 value28;
    f32 value2c;
    u8 pad30[0x0c];
    f32 value3c;
    f32 value40;
    f32 value44;
    f32 value48;
    f32 value4c;
    f32 value50;
    u8 pad54[0x34];
    f32 value88;
    f32 value8c;
    u8 pad90[0x1c];
    s16 valueac;
    s16 valueae;
} Fn167F20;

/* fn_1_68054 */
typedef struct fn_1_68054_EffectObject {
    u8 pad0[0x28];
    f32 value;
    u8 pad1[0x10];
    u8 subobject;
} fn_1_68054_EffectObject;

/* fn_1_68054 */
typedef struct fn_1_68054_EffectEntry {
    u8 pad0[4];
    void (*callback)(void);
    fn_1_68054_EffectObject *owner;
} fn_1_68054_EffectEntry;

extern void GXGetProjectionv(f32 *);
extern u32 GXGetTexBufferSize(u16, u16, u32, u32, u8);
extern void GXInitTexObj(void *, void *, u16, u16, s32, s32, s32, u8);
extern void GXLoadPosMtxImm(void *,u32);
extern void GXLoadTexMtxImm(f32 *, u32, u32);
extern f32 __fmadds(f32, f32, f32);
extern u32 camera_forward_status(void);
extern s16 camera_get_entry_field_0xa4(u32);
extern s16 camera_get_mode(void);
extern void fn5C058PoolD(f64);
extern void fn5C058PoolF(f32);
extern s32 fn_1_15578(Vec648DC *from, Vec648DC *to, u32 *arg2, Vec648DC *normal, u32 mask, s32 *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
extern void fn_1_3BDC(u32);
extern u32 fn_1_3C18(s32 arg0);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_3F164(void);
extern s32 fn_1_3FC58(void);
extern u32 fn_1_3FC8C(void);
extern Fn1967A8Resource_635BC *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource_635BC *arg0, void *arg1);
extern void fn_1_41F58(Fn1967A8Resource_635BC *arg0, s32 arg1, void (*arg2)(void), void *arg3);
extern void *fn_1_45D0(void *, u32, const char *, u32);
extern void *fn_1_4630(u32, u32, const char *, u32);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_4730(u32 value, u32 count, u32 size, const char *file, int line);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void *fn_1_548AC(u32 size);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_55210(void *);
extern void fn_1_5557C(void *object);
extern void fn_1_555D0(void *object);
extern void fn_1_556B8(void *);
extern void fn_1_557C4(void *);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void fn_1_56000(u8, u8, u8);
extern u32 fn_1_56018(s32);
extern void fn_1_560F0(s32, void *);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_57714(u8);
extern void fn_1_57720(u32, u32, u32, u32);
extern void fn_1_579A0(void *, void *);
extern void fn_1_57A70(u16, void *);
extern void fn_1_58114(void);
extern void fn_1_58158(void);
extern void fn_1_5819C(void);
extern s32 fn_1_581AC(u16, u16, void *);
extern u32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern s32 fn_1_66B8(void *, f32);
extern void fn_1_680F8(void);
extern void fn_1_681C(u8, EffVec3 *);
extern void fn_1_68248(void);
extern void fn_1_68284(void);
extern void fn_1_68B68(void);
extern void fn_1_69BBC(void);
extern void fn_1_69BCC(void);
extern s32 fn_1_6EC0(u8);
extern u32 fn_1_707C(u32);
extern s8 fn_1_84124(Fn183D28Car *, s8, s8, u8 *);
extern s8 fn_1_84408(CarTestCar *);
extern s8 fn_1_84644(Fn183D28Body *);
extern void *fn_1_86254(int);
extern u32 fn_1_862A8(u32, struct Sig_fn_1_862A8_fn_1_862A8_Arg1 *);
extern void fn_1_862D4(int, void *);
extern void fn_1_8636C(int, void *);
extern void fn_1_8645C(int, void *);
extern u32 fn_1_864E8(int);
extern u32 fn_1_86514(int);
extern f32 fn_1_8652C(int);
extern void fn_1_8658C(int, void *);
extern s8 fn_1_86634(int);
extern u32 fn_1_867CC(u32, void *);
extern void *fn_1_868C0(s8);
extern s32 fn_1_8C66C(s16 index);
extern s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
extern void fn_1_8E084(CarTestCar *, u32 *, s32);
extern void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
extern void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
extern void fn_1_93734(CarObject *arg0, void *arg1);
extern void fn_1_943F8(Fn935E4Car *, f32, void *);
extern void fn_1_95158(Fn195158Car_635BC *car);
extern void fn_1_966A0(Fn1_8F494_Object *obj);
extern void fn_1_968FC(Fn1_8F5A4_Object *obj);
extern u16 fn_1_96968(Fn196968Object_635BC *object, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner_635BC *owner, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object_635BC *object, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object_635BC *object, void *arg1);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void *fn_1_9CE1C(const char *, s32);
extern f32 fn_1_9E14C(s32, void *, f32);
extern void fn_1_9EA94(void *);
extern void fn_1_9F7DC(void);
extern void fn_1_9F870(void);
extern void fn_1_9F8FC(void);
extern int fn_1_9F914(const void *, const void *);
extern s32 fn_1_9F9A4(void *);
extern f32 fn_1_A71AC(void);
extern void fn_1_A8E78(const char *);
extern void fn_1_AEB8(camera_reset_transition_Camera *);
extern void fn_1_AFC8(camera_update_transition_Camera *);
extern void fn_1_B81C(Vec3f_635BC *, Vec3f_635BC *, s32);
extern void fn_80008BA8(void *, void *, int);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_8003462C(u32,u32,u32);
extern void fn_8003526C(void *, u8);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80038F10(void *);
extern void fn_8006E250(void *, void *);
extern void fn_8006E294(void *);
extern void fn_8006E2B0(Fn5D91CVec *, Fn5D91CVec *);
extern void fn_8006EDBC(void *, void *, s16 *, s16 *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void fn_8006F3E4(s16 *, s16 *, s16 *);
extern void fn_8006F9A4(f32, Vec3 *, Vec3 *, void *);
extern void fn_8006FA24(void *, void *, void *, f32);
extern CarR29 *fn_80071268(void *, void *);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80073B50(u32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_80073C6C(s32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern void fn_80074300(u16, u16, u16, u16);
extern void fn_80074438(u16, u16, u32, u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern Bss_104C lbl_1_bss_104C;
extern Outer *lbl_1_bss_38454;
extern struct fn_1_AA54_lbl_1_rodata_388 lbl_1_rodata_388;
extern Triple lbl_1_rodata_3BE8;
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D188(s32);
extern void lbl_8006D1B8(s16,void *);
extern s16 lbl_8006D24C(f32, f32);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern void lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006D5F0(void *, void *, f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D758(void);
extern void lbl_8006D7B0(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006D848(f32);
extern void lbl_8006D8D8(s16);
extern void lbl_8006D95C(s32);
extern void lbl_8006D9D8(void *);
extern u32 lbl_8006DA50(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void *lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void *lbl_8006DC6C(void *);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006DF44(void);
extern void *lbl_8006DFC4(void *);
extern void lbl_8006DFD8(void *);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1C0(void *, void *);
extern void *lbl_8006E1F0(void *, f32, f32, f32);
extern void lbl_8006E2C0(Vec3f_635BC *, f32, f32, f32);
extern u32 lbl_801A63C0;
extern void *lbl_801A63D0;
extern void *lbl_801A6410;
extern u32 lbl_801A66A0;
extern struct fn_1_638E8_lbl_801A66CC lbl_801A66CC;
extern void *lbl_801A6D00;
extern void mathutil_mtxA_rotate_x(s16 value);
extern void mathutil_mtxA_rotate_y(s16 value);
extern void mathutil_mtxA_rotate_z(s16 value);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);
extern void u_gxutil_upload_some_mtx(u32, u32);

void fn_1_584D4(void);
void fn_1_58694(void);
void fn_1_58854(void);
void fn_1_58994(void);
void fn_1_58C6C(void);
void fn_1_58D38(void);
s16 fn_1_58E3C(void *source);
s16 fn_1_58F50(const void *source);
s16 fn_1_59078(Obj_1_bss_6C84C_Target *arg0);
void fn_1_591A0(s32 id);
void fn_1_59290(void);
void fn_1_5942C(void);
void fn_1_5944C(void);
void fn_1_5946C(void);
void fn_1_5948C(void);
void fn_1_594AC(void);
void fn_1_594CC(void);
void fn_1_594EC(void);
void fn_1_594F0(void);
void fn_1_594F4(void);
void fn_1_594F8(void);
void fn_1_594FC(void);
void fn_1_59500(void);
void fn_1_59504(void);
void fn_1_59508(void);
void fn_1_5950C(void);
void fn_1_59510(void);
void fn_1_59514(void *obj);
void fn_1_5962C(Fn_1_5962C_State *self);
void fn_1_59770(fn_1_59770_Effect *effect);
void fn_1_59A70(void);
void fn_1_59A74(struct fn_1_59A74_Arg0 *arg0);
void fn_1_59B00(fn_1_59B00_Effect *effect);
void fn_1_59B90(SelfObj *arg0);
void fn_1_59CC4(void);
void fn_1_59CC8(struct Fn159CC8Object *arg0);
void fn_1_59D54(fn_1_59D54_Effect *effect);
void fn_1_59EE4(Fn59EE4Effect *effect);
void fn_1_5A8CC(void);
void fn_1_5A8D0(Fn1_5A8D0Data *data);
void fn_1_5A8DC(Arg_5A8DC *arg0);
void fn_1_5ABC4(void);
void fn_1_5ABC8(void);
void fn_1_5ABCC(Fn1_5ABCCOutput *out);
void fn_1_5AC48(fn_1_5AC48_Effect *effect);
void fn_1_5AF28(SelfObj_5AF28 *arg0);
void fn_1_5B074(void);
void fn_1_5B078(struct fx_5b078_out *out);
void fn_1_5B188(struct fx_5b188 *p);
void fn_1_5B30C(struct fn_1_5B30C_Arg0 *arg0);
void fn_1_5B3CC(void);
void fn_1_5B3D0(struct fn_1_5B3D0_Arg0 *arg0);
void fn_1_5B450(Fn1_5B450Object *arg0);
void fn_1_5B578(Obj_1_5B578_T *p);
void fn_1_5B6F0(void);
void fn_1_5B6F4(Fn15B6F4 *obj);
void fn_1_5B780(Fn15B780 *effect);
void fn_1_5B7F8(struct fn_1_5B7F8_Arg0 *e);
void fn_1_5BF6C(void);
void fn_1_5BF70(struct fn_1_5BF70_Arg0 *arg0);
void fn_1_5BFF0(struct fn_1_5BFF0_Arg0 *arg0);
void fn_1_5C058(struct fn_1_5C058_Arg0 *arg0);
void fn_1_5C780(void);
void fn_1_5C784(EffectWork *self);
void fn_1_5C83C(struct Fn1_5C83CObject *self);
void fn_1_5CA00(struct fn_1_5CA00_Arg0 *arg0);
void fn_1_5D010(void);
void fn_1_5D014(Fn1_5D014Object *obj);
void fn_1_5D020(Fx *p);
void fn_1_5D1B8(Self *self);
void fn_1_5D374(void);
void fn_1_5D378(fn_1_5D378_obj *self);
void fn_1_5D4FC(void);
void fn_1_5D500(EffectUpdate *arg0);
void fn_1_5D718(struct Fn15D718 *self);
void fn_1_5D88C(struct Fn15D88C *self);
void fn_1_5D918(void);
void fn_1_5D91C(Fn5D91CObj *obj);
void fn_1_5DFA4(Fn5DFA4Effect *effect);
void fn_1_5E3C4(struct fn_1_5E3C4_Arg0 *arg0);
void fn_1_5E4D8(void *arg0);
void fn_1_5EB08(FnObj *object);
void fn_1_5EB98(struct fn_1_5EB98_Arg0 *arg0, u32 arg1, u32 arg2);
void fn_1_5F5C4(void);
void fn_1_5F5C8(struct fn_1_5F5C8_Arg0 *arg0);
void fn_1_5F654(fn_1_5F654_Effect *effect);
void fn_1_5F9B8(fn_1_5F9B8_Effect *effect);
void fn_1_5FE24(void);
void fn_1_5FE28(void);
void fn_1_5FE2C(void);
void fn_1_5FE30(fn_1_5FE30_FZeroObject *object);
void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object);
void fn_1_5FFAC(void);
void fn_1_5FFB0(struct fn_1_5FFB0_p *p);
void fn_1_60170(fn_1_60170_FZeroObject *object);
void fn_1_601B4(EffectState *effect);
void fn_1_6028C(BeamEffect *effect);
void fn_1_60734(Fn60734 *effect);
void fn_1_60880(Avl60880Obj *obj);
void fn_1_60B80(Sig_fn_1_60B80_Obj *obj, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2);
void fn_1_60C70(void);
void fn_1_60C74(struct fn_1_60C74_Effect *effect);
void fn_1_60C84(void);
void fn_1_60C88(Obj_60C88 *this);
void fn_1_60D54(u8 *arg0);
void fn_1_60F7C(void);
void fn_1_60F80(void);
void fn_1_60F84(fn_1_60F84_Effect *obj);
void fn_1_61070(Fn161070 *self);
void fn_1_611EC(struct FxParam *p, u32 unused1, u32 unused2, u32 unused3);
void fn_1_61370(fn_1_61370_Obj *p);
void fn_1_61640(struct Fn1_61640Object *object);
void fn_1_61760(struct Fn1_61760Object *object);
void fn_1_617A4(struct Fn1_617A4Object *object);
void fn_1_618B8(struct obj_state *p);
void fn_1_619E4(fn_1_619E4_Obj *obj);
void fn_1_61C84(void);
void fn_1_61C88(void);
void fn_1_61CA8(void);
void fn_1_61CC8(void);
void fn_1_61CE8(void);
void fn_1_620C4(void);
void fn_1_620C8(void *arg0);
void fn_1_62360(void *arg0);
void fn_1_62794(void *arg0);
void fn_1_62AF8(struct fn_1_62AF8_obj *obj);
void fn_1_62C84(Particle *p);
void fn_1_62E9C(struct Eff62E9C *e);
void fn_1_6312C(void);
void fn_1_63130(struct fn_1_63130_obj *obj);
void fn_1_6313C(Fx *p);
void fn_1_632D4(struct fn_1_632D4_obj *obj);
void fn_1_633BC(void);
void fn_1_633C0(FxObj633C0 *obj);
void fn_1_63514(void);
void fn_1_63518(Effect_63518_63518 *effect);
void fn_1_635BC(Fn1635BCEffect *e);
void fn_1_63858(struct fn_1_63858_Object *object);
void fn_1_638E8(struct fn_1_638E8_Arg0 *arg0);
void fn_1_64098(Fn164098Object *object);
void fn_1_640A4(u8 *arg0);
void fn_1_642E8(fn_1_642E8_EffectObject *self);
void fn_1_64388(ArgObj *arg0);
void fn_1_645C8(void);
void fn_1_645CC(void);
void fn_1_645D0(void);
void fn_1_645D4(struct A *arg0);
void fn_1_64760(struct Fn15D718 *self);
void fn_1_648D4(void);
void fn_1_648D8(void);
void fn_1_648DC(Effect648DC *effect);
void fn_1_64E1C(void * arg0);
void fn_1_64F2C(Fn_1_64F2C_Object *obj);
void fn_1_64FB8(void *arg0);
void fn_1_65268(Object *object);
void fn_1_652F4(fn_1_652F4_Effect *effect);
void fn_1_65420(void);
void fn_1_65424(fn_1_65424_EffectObject *object);
void fn_1_654B0(Particle654B0 *p);
void fn_1_656C8(fn_1_656C8_EffectObject *object);
void fn_1_65748(fn_1_65748_Event *event);
void fn_1_65AAC(void);
void fn_1_65AB0(Fn165AB0Object *obj);
void fn_1_65B58(void);
void fn_1_65B5C(EffP *p);
void fn_1_65CDC(struct Fn1_65CDC *self);
void fn_1_65E58(fn_1_65E58_Effect *effect);
void fn_1_65E88(void);
void fn_1_65E8C(Effect65E8C *eff);
void fn_1_660EC(ObjFx_T *this);
void fn_1_66254(fn_1_66254_output *output);
void fn_1_662D4(void);
void fn_1_662D8(Fn662D8Source *arg0);
void fn_1_67294(Obj_67294 *arg0);
void fn_1_67414(struct fn_1_67414_Arg0 *arg0);
void fn_1_6742C(void);
void fn_1_67430(Obj67430 *p);
void fn_1_6755C(FnObj_6755C *obj);
void fn_1_6766C(Fn6766CObject *object);
void fn_1_6767C(void);
void fn_1_67680(void *arg0);
void fn_1_67D0C(Obj_67D0C *arg0);
void fn_1_67E94(u8 *object);
void fn_1_67F20(Fn167F20 *obj);
void fn_1_68054(fn_1_68054_EffectObject *effect);
void fn_1_680F4(void);

/* effect.c .data, retail order (1C698..1D628 before the first function) */
u32 lbl_1_data_1C698[372] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
    55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126,
    127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147,
    148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168,
    169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189,
    190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210,
    211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231,
    232, 233, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 0, 23, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 24, 25, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76,
    77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
    123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136
};
Obj_1_data_1CC74_Target lbl_1_data_1CC68 = {0.0f, -1.0f, 0.0f};
Obj_1_data_1CC74_Target *lbl_1_data_1CC74 = &lbl_1_data_1CC68;
char *lbl_1_data_1D0C8[68] = {
    "ET_COLI_PARTICLE", "ET_CAR_EFFECT", "ET_DRIFT_PTCL", "ET_CARSTAB_SRIP01", "ET_CAR_COLIP",
    "ET_CAR_THUNDER01", "ET_ROCKET_START_E3SCN", "ET_RSTART_E3SCN_PTCL", "ET_RSTART_E3SCN_PTCLFRAG",
    "ET_RSTART_E3SCN_RING", "ET_CAR_FRONT_THUNDER", "ET_CAR_FRONT_THUNDER_OUT", "ET_CAR_BELT",
    "ET_CAR_SMOKE", "ET_CAR_REPAIR", "ET_CAR_SPARK", "ET_CAR_THUNDER02", "ET_CAR_THUNDER03",
    "ET_CAR_EMERGENCY", "ET_BG_THUNDER01", "ET_CAR_LEAF", "ET_CAR_HITMARK", "ET_CAR_HITMARK2",
    "ET_CAR_TURBO_END", "ET_CAR_JUMP_PTCL", "ET_HBOARD_PLANE", "ET_CAR_WATER", "ET_CAR_WATER_SMOKE",
    "ET_CAR_SPIN_ATK", "ET_CAR_BREAK_SMOKE", "ET_CAR_BREAK_START_PTCL", "ET_CAR_BREAK_PTCL",
    "ET_CAR_BREAK_BALL", "ET_CAR_BREAK_BALL_BOMB", "ET_CAR_BOMB_FIRE", "ET_CAR_BOMB_MISSILE",
    "ET_CAR_BOMB_MISSILE_SMOKE", "ET_CAR_UFO", "ET_CAR_BOMB_CTRL", "ET_CAR_DIRT", "ET_DMY001", "ET_DMY002",
    "ET_DMY003", "ET_DMY004", "ET_TMP001", "ET_TMP002", "ET_TMP003", "ET_TMP004", "ET_TMP005", "ET_TMP006",
    "ET_TMP007", "ET_TMP008", "ET_TMP009", "ET_TMP010", "ET_TMP011", "ET_TMP012", "ET_TMP013", "ET_TMP014",
    "ET_TMP015", "ET_TMP016", "ET_TMP017", "ET_TMP018", "ET_TMP019", "ET_TMP020", "ET_TMP021", "ET_TMP022",
    "ET_TMP023", "ET_TMP024"
};
typedef void (*EffectHandler)(void *);
EffectHandler lbl_1_data_1D1D8[69] = {
    (EffectHandler)fn_1_59504, (EffectHandler)fn_1_5942C, (EffectHandler)fn_1_59514,
    (EffectHandler)fn_1_59A74, (EffectHandler)fn_1_594AC, (EffectHandler)fn_1_59CC8,
    (EffectHandler)fn_1_5A8D0, (EffectHandler)fn_1_5ABCC, (EffectHandler)fn_1_5B078,
    (EffectHandler)fn_1_5B3D0, (EffectHandler)fn_1_5B6F4, (EffectHandler)fn_1_5BF70,
    (EffectHandler)fn_1_5C784, (EffectHandler)fn_1_5D014, (EffectHandler)fn_1_5D378,
    (EffectHandler)fn_1_5D88C, (EffectHandler)fn_1_5E3C4, (EffectHandler)fn_1_5F5C8,
    (EffectHandler)fn_1_5FE28, (EffectHandler)fn_1_5FFB0, (EffectHandler)fn_1_60734,
    (EffectHandler)fn_1_60C74, (EffectHandler)fn_1_60F7C, (EffectHandler)fn_1_611EC,
    (EffectHandler)fn_1_617A4, (EffectHandler)fn_1_61C88, (EffectHandler)fn_1_62AF8,
    (EffectHandler)fn_1_63130, (EffectHandler)fn_1_633C0, (EffectHandler)fn_1_64098,
    (EffectHandler)fn_1_645CC, (EffectHandler)fn_1_648D4, (EffectHandler)fn_1_64F2C,
    (EffectHandler)fn_1_65424, (EffectHandler)fn_1_65AB0, (EffectHandler)fn_1_6766C,
    (EffectHandler)fn_1_67E94, (EffectHandler)fn_1_65E58, (EffectHandler)fn_1_66254,
    (EffectHandler)fn_1_67414, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4,
    (EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F4, NULL
};
EffectHandler lbl_1_data_1D2EC[69] = {
    (EffectHandler)fn_1_59508, (EffectHandler)fn_1_5944C, (EffectHandler)fn_1_5962C,
    (EffectHandler)fn_1_59B00, (EffectHandler)fn_1_594CC, (EffectHandler)fn_1_59D54,
    (EffectHandler)fn_1_5A8DC, (EffectHandler)fn_1_5AC48, (EffectHandler)fn_1_5B188,
    (EffectHandler)fn_1_5B450, (EffectHandler)fn_1_5B780, (EffectHandler)fn_1_5BFF0,
    (EffectHandler)fn_1_5C83C, (EffectHandler)fn_1_5D020, (EffectHandler)fn_1_5D500,
    (EffectHandler)fn_1_5D91C, (EffectHandler)fn_1_5E4D8, (EffectHandler)fn_1_5F654,
    (EffectHandler)fn_1_5FE2C, (EffectHandler)fn_1_601B4, (EffectHandler)fn_1_60880,
    (EffectHandler)fn_1_60C88, (EffectHandler)fn_1_60F84, (EffectHandler)fn_1_61370,
    (EffectHandler)fn_1_618B8, (EffectHandler)fn_1_61CA8, (EffectHandler)fn_1_62C84,
    (EffectHandler)fn_1_6313C, (EffectHandler)fn_1_635BC, (EffectHandler)fn_1_640A4,
    (EffectHandler)fn_1_645D4, (EffectHandler)fn_1_648DC, (EffectHandler)fn_1_64FB8,
    (EffectHandler)fn_1_654B0, (EffectHandler)fn_1_65B5C, (EffectHandler)fn_1_67680,
    (EffectHandler)fn_1_67F20, (EffectHandler)fn_1_65E8C, (EffectHandler)fn_1_662D8,
    (EffectHandler)fn_1_67430, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8,
    (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594F8, NULL
};
EffectHandler lbl_1_data_1D400[69] = {
    (EffectHandler)fn_1_5950C, (EffectHandler)fn_1_5946C, (EffectHandler)fn_1_59770,
    (EffectHandler)fn_1_59B90, (EffectHandler)fn_1_594EC, (EffectHandler)fn_1_59EE4,
    (EffectHandler)fn_1_5ABC4, (EffectHandler)fn_1_5AF28, (EffectHandler)fn_1_5B30C,
    (EffectHandler)fn_1_5B578, (EffectHandler)fn_1_5B7F8, (EffectHandler)fn_1_5C058,
    (EffectHandler)fn_1_5CA00, (EffectHandler)fn_1_5D1B8, (EffectHandler)fn_1_5D718,
    (EffectHandler)fn_1_5DFA4, (EffectHandler)fn_1_5EB08, (EffectHandler)fn_1_5F9B8,
    (EffectHandler)fn_1_5FE30, (EffectHandler)fn_1_6028C, (EffectHandler)fn_1_60B80,
    (EffectHandler)fn_1_60D54, (EffectHandler)fn_1_61070, (EffectHandler)fn_1_61640,
    (EffectHandler)fn_1_619E4, (EffectHandler)fn_1_61CC8, (EffectHandler)fn_1_62E9C,
    (EffectHandler)fn_1_632D4, (EffectHandler)fn_1_63858, (EffectHandler)fn_1_642E8,
    (EffectHandler)fn_1_64760, (EffectHandler)fn_1_64E1C, (EffectHandler)fn_1_65268,
    (EffectHandler)fn_1_656C8, (EffectHandler)fn_1_65CDC, (EffectHandler)fn_1_67D0C,
    (EffectHandler)fn_1_68054, (EffectHandler)fn_1_660EC, (EffectHandler)fn_1_67294,
    (EffectHandler)fn_1_6755C, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC,
    (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_594FC, NULL
};
EffectHandler lbl_1_data_1D514[69] = {
    (EffectHandler)fn_1_59510, (EffectHandler)fn_1_5948C, (EffectHandler)fn_1_59A70,
    (EffectHandler)fn_1_59CC4, (EffectHandler)fn_1_594F0, (EffectHandler)fn_1_5A8CC,
    (EffectHandler)fn_1_5ABC8, (EffectHandler)fn_1_5B074, (EffectHandler)fn_1_5B3CC,
    (EffectHandler)fn_1_5B6F0, (EffectHandler)fn_1_5BF6C, (EffectHandler)fn_1_5C780,
    (EffectHandler)fn_1_5D010, (EffectHandler)fn_1_5D374, (EffectHandler)fn_1_5D4FC,
    (EffectHandler)fn_1_5D918, (EffectHandler)fn_1_5F5C4, (EffectHandler)fn_1_5FE24,
    (EffectHandler)fn_1_5FFAC, (EffectHandler)fn_1_60170, (EffectHandler)fn_1_60C70,
    (EffectHandler)fn_1_60C84, (EffectHandler)fn_1_60F80, (EffectHandler)fn_1_61760,
    (EffectHandler)fn_1_61C84, (EffectHandler)fn_1_61CE8, (EffectHandler)fn_1_6312C,
    (EffectHandler)fn_1_633BC, (EffectHandler)fn_1_63514, (EffectHandler)fn_1_645C8,
    (EffectHandler)fn_1_645D0, (EffectHandler)fn_1_648D8, (EffectHandler)fn_1_65420,
    (EffectHandler)fn_1_65AAC, (EffectHandler)fn_1_65B58, (EffectHandler)fn_1_6767C,
    (EffectHandler)fn_1_680F4, (EffectHandler)fn_1_65E88, (EffectHandler)fn_1_662D4,
    (EffectHandler)fn_1_6742C, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500,
    (EffectHandler)fn_1_59500, (EffectHandler)fn_1_59500, NULL
};
u32 lbl_1_data_1D628 = 1;

/* effect.c .bss, retail order */
Obj_1_bss_6C84C_Target *lbl_1_bss_6C848;
Obj_1_bss_6C84C_Target *lbl_1_bss_6C84C;
s16 lbl_1_bss_6C850;
s32 lbl_1_bss_6C854;
s32 lbl_1_bss_6C858;
s32 lbl_1_bss_6C85C;
s32 lbl_1_bss_6C860;
u32 lbl_1_bss_6C864;
u32 lbl_1_bss_6C868;
s32 lbl_1_bss_6C86C;
s32 lbl_1_bss_6C870;

/* The generator of fn_1_584AC (avline.c), inlined in this TU. */
static inline u32 effect_rnd(void) {
    u32 r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = r;
    r = (r >> 16) & 0x7FFF;
    return r;
}

/* x*x + y*y + z*z (retail: fmuls, fmadds, fmadds). */
static inline f32 effect_sum_sq(f32 x, f32 y, f32 z) {
    f32 s = x * x;
    s += y * y;
    s += z * z;
    return s;
}

/* fzgx:begin fn_1_584D4 */
void fn_1_584D4(void) {
    s32 id;
    s32 count;
    AvlineEntry *entry;

    lbl_1_bss_6C848 = fn_1_4630((u32)lbl_801A6410, sizeof(AvlineEntry) * 0xbe, "effect.c", 0xc1);
    lbl_1_bss_6C84C = fn_1_4630((u32)lbl_801A6410, sizeof(AvlineEntry) * 0xc8, "effect.c", 0xc2);
    entry = (AvlineEntry *)lbl_1_bss_6C848;
    lbl_1_bss_6C850 = 0;
    id = 0;
    for (count = 0xbe; count > 0; count--) {
        entry->unk_02 = id++;
        entry->unk_04 = -1;
        entry++;
    }
    entry = (AvlineEntry *)lbl_1_bss_6C84C;
    id = 0;
    for (count = 0xc8; count > 0; count--) {
        entry->unk_02 = id++;
        entry->unk_04 = -1;
        entry++;
    }

    fn_1_9F7DC();
    fn_1_58114();
    lbl_1_bss_6C854 = 0;
    lbl_1_bss_6C858 = 0;
}
/* fzgx:end fn_1_584D4 */

/* fzgx:begin fn_1_58694 */
void fn_1_58694(void) {
    s32 count;
    AvlineEntry_58694 *entry;

    if (fn_1_3F0C8() != 0x28) {
        entry = (AvlineEntry_58694 *)lbl_1_bss_6C848;
        lbl_1_bss_6C85C = 0;
        lbl_1_bss_6C860 = 0;
        lbl_1_bss_6C864 = 0;
        lbl_1_bss_6C868 = 0;
        fn_1_3BDC(9);
        for (count = 0xbe; count > 0; count--) {
            if (entry->unk_00 != 0) {
                entry->unk_10 -= 1;
                if (entry->unk_10 == 0 || entry->unk_00 == 3) {
                    lbl_1_data_1D514[entry->unk_0c](entry);
                    entry->unk_00 = 0;
                } else {
                    entry->unk_60 = entry->unk_3c;
                    lbl_1_data_1D2EC[entry->unk_0c](entry);
                }
            }
            entry++;
        }
        entry = (AvlineEntry_58694 *)lbl_1_bss_6C84C;
        for (count = 0xc8; count > 0; count--) {
            if (entry->unk_00 != 0) {
                entry->unk_10 -= 1;
                if (entry->unk_10 == 0 || entry->unk_00 == 3) {
                    lbl_1_data_1D514[entry->unk_0c](entry);
                    entry->unk_00 = 0;
                } else {
                    entry->unk_60 = entry->unk_3c;
                    lbl_1_data_1D2EC[entry->unk_0c](entry);
                }
            }
            entry++;
        }
        fn_1_3C18(9);
    }
}
/* fzgx:end fn_1_58694 */

/* fzgx:begin fn_1_58854 */
void fn_1_58854(void) {
    s32 count;
    AvlineObj *obj;
    s32 index;
    EffectHandler callback;

    fn_1_9F870();
    fn_1_58158();

    obj = *(AvlineObj **)&lbl_1_bss_6C848;
    count = 0xbe;
    index = 0;
    while (count > 0) {
        if (obj->unk_0 != 0) {
            callback = lbl_1_data_1D514[obj->unk_C];
            callback(obj);
            obj->unk_0 = index;
        }
        count--;
        obj = (AvlineObj *)((u8 *)obj + 0xe8);
    }

    obj = (AvlineObj *)lbl_1_bss_6C84C;
    count = 0xc8;
    index = 0;
    while (count > 0) {
        if (obj->unk_0 != 0) {
            callback = lbl_1_data_1D514[obj->unk_C];
            callback(obj);
            obj->unk_0 = index;
        }
        count--;
        obj = (AvlineObj *)((u8 *)obj + 0xe8);
    }

    fn_1_46B4((u32)lbl_801A6410, *(u32 *)&lbl_1_bss_6C848,
              "effect.c", 0x156);
    fn_1_46B4((u32)lbl_801A6410, *(u32 *)&lbl_1_bss_6C84C,
              "effect.c", 0x157);

    *(u32 *)&lbl_1_bss_6C848 = 0;
    lbl_1_bss_6C84C = 0;
}
/* fzgx:end fn_1_58854 */

/* fzgx:begin fn_1_58994 */
void fn_1_58994(void) {
    u16 active_2;
    AvlineState_58994 *state = (AvlineState_58994 *)&lbl_1_bss_6C848;
    u32 value;
    struct { u32 value; } active;
    EffectHandler *tbl;
    AvlineEntry_58994 *entry;
    s32 count;
    u32 mode;
    u16 mask;
    u32 best;

    fn_1_3BDC(9);
    if (fn_1_3F164() != 0) {
        lbl_1_data_1D628 = 1;
    }
    fn_1_9F8FC();
    fn_1_5819C();
    mode = fn_1_58C4();
    if (mode >= 1 && mode <= 4) {
        mask = 1 << (mode - 1);
    } else {
        mask = 0xffff;
    }

    entry = state->unk_00;
    if ((camera_forward_status() & 0x80000000) == 0) {
        active.value = mask;
        tbl = lbl_1_data_1D400;
        count = 0xbe;
        while (count > 0) {
            if (entry->unk_00 != 0) {
                if ((entry->unk_1a & active.value) != 0) {
                    if ((entry->unk_08 & 0x80000000) == 0) {
                        tbl[entry->unk_0c](entry);
                    }
                }
            }
            entry++;
            count--;
        }
{
    AvlineEntry_58994 * fzgx_loop_entry_2643;
        fzgx_loop_entry_2643 = state->unk_04;
        tbl = lbl_1_data_1D400;
        count = 0xc8;
        while (count > 0) {
            if (fzgx_loop_entry_2643->unk_00 != 0) {
                if ((fzgx_loop_entry_2643->unk_1a & active.value) != 0) {
                    if ((fzgx_loop_entry_2643->unk_08 & 0x80000000) == 0) {
                        tbl[fzgx_loop_entry_2643->unk_0c](fzgx_loop_entry_2643);
                    }
                }
            }
            fzgx_loop_entry_2643++;
            count--;
        }
    entry = fzgx_loop_entry_2643;
}
    } else {
        active_2 = mask;
        count = 0xbe;
        while (count > 0) {
            if (entry->unk_00 != 0) {
                if ((entry->unk_1a & active_2) != 0) {
                    if ((entry->unk_08 & 0x80000000) == 0) {
                        if ((entry->unk_08 & 0x08000000) != 0) {
                            lbl_1_data_1D514[entry->unk_0c](entry);
                            entry->unk_00 = 0;
                        } else {
                            if ((entry->unk_08 & 0x70000000) != 0) {
                                entry->unk_60 = entry->unk_3c;
                            }
                            if (entry->unk_0c == 28) {
                                fn_1_63518((Effect_63518_63518 *)entry);
                            }
                            lbl_1_data_1D400[entry->unk_0c](entry);
                        }
                    }
                }
            }
            entry++;
            count--;
        }
        entry = state->unk_04;
        count = 0xc8;
        while (count > 0) {
            if (entry->unk_00 != 0) {
                if ((entry->unk_1a & active_2) != 0) {
                    if ((entry->unk_08 & 0x80000000) == 0) {
                        if ((entry->unk_08 & 0x08000000) != 0) {
                            lbl_1_data_1D514[entry->unk_0c](entry);
                            entry->unk_00 = 0;
                        } else {
                            if ((entry->unk_08 & 0x70000000) != 0) {
                                entry->unk_60 = entry->unk_3c;
                            }
                            if (entry->unk_0c == 28) {
                                fn_1_63518((Effect_63518_63518 *)entry);
                            }
                            lbl_1_data_1D400[entry->unk_0c](entry);
                        }
                    }
                }
            }
            entry++;
            count--;
        }
    }

    value = fn_1_3C18(9);
    best = state->unk_0c;
    if (value > best) {
        best = value;
    }
    state->unk_0c = best;
}
/* fzgx:end fn_1_58994 */

/* fzgx:begin fn_1_58C6C */
void fn_1_58C6C(void) {
    struct fn_1_58C6C_lbl_1_bss_6C848_T *var_r31;
    s32 var_r30;
    s32 var_r30_2;
    struct fn_1_58C6C_lbl_1_bss_6C84C_T *var_r31_2;

    var_r30 = 0xBE;
    var_r31 = (struct fn_1_58C6C_lbl_1_bss_6C848_T *)(*(struct fn_1_58C6C_lbl_1_bss_6C848_T **)((&(*(struct fn_1_58C6C_lbl_1_bss_6C848_T * *)&lbl_1_bss_6C848))));
    do {
        if ((var_r31->unk_C == 0x19) && ((s8) var_r31->unk_0 != 0) && ((s32) var_r31->unk_1A != 0) && !(var_r31->unk_8 & 0x80000000)) {
            fn_1_620C8(var_r31);
        }
        var_r30 -= 1;
        var_r31 = (struct fn_1_58C6C_lbl_1_bss_6C848_T *)((u8 *)(var_r31) + 0xE8);
    } while (var_r30 > 0);
    var_r30_2 = 0xC8;
    var_r31_2 = (struct fn_1_58C6C_lbl_1_bss_6C84C_T *)(*(struct fn_1_58C6C_lbl_1_bss_6C84C_T **)((&(*(struct fn_1_58C6C_lbl_1_bss_6C84C_T * *)&lbl_1_bss_6C84C))));
    do {
        if ((var_r31_2->unk_C == 0x19) && ((s8) var_r31_2->unk_0 != 0) && ((s32) var_r31_2->unk_1A != 0) && !(var_r31_2->unk_8 & 0x80000000)) {
            fn_1_620C8(var_r31_2);
        }
        var_r30_2 -= 1;
        var_r31_2 = (struct fn_1_58C6C_lbl_1_bss_6C84C_T *)((u8 *)(var_r31_2) + 0xE8);
    } while (var_r30_2 > 0);
}
/* fzgx:end fn_1_58C6C */

/* fzgx:begin fn_1_58D38 */
void fn_1_58D38(void) {
    fn_1_58D38_EffectState *state;
    s32 count;
    fn_1_58D38_EffectEntry *entry;
    u32 max_count;

    state = (fn_1_58D38_EffectState *)&lbl_1_bss_6C848;
    if (state->unk_00 != 0) {
        fn_1_3BDC(9);

        entry = state->unk_00;
        count = 190;
        do {
            if (entry->unk_0C == 25 &&
                entry->unk_00 != 0 &&
                entry->unk_1A != (s16)0 &&
                (entry->unk_08 & ~0x7fffffff) == 0) {
                fn_1_62360(entry);
            }
            count--;
            entry++;
        } while (count > 0);

        entry = state->unk_04;
        count = 200;
        do {
            if (entry->unk_0C == 25 &&
                entry->unk_00 != 0 &&
                entry->unk_1A != (s16)0 &&
                (entry->unk_08 & ~0x7fffffff) == 0) {
                fn_1_62360(entry);
            }
            count--;
            entry++;
        } while (count > 0);

        count = fn_1_3C18(9);
        max_count = state->unk_10;
        if (count > max_count) {
            max_count = count;
        }
        state->unk_10 = max_count;
    }
}
/* fzgx:end fn_1_58D38 */

/* fzgx:begin fn_1_58E3C */
s16 fn_1_58E3C(void *source) {
    s32 i;

    if ((s32)fn_1_3FC58() != 0) {
        return -1;
    }

    {
        EffectEntry *scan;
        scan = *(EffectEntry **)&lbl_1_bss_6C848;
        i = 0;
        for (; i < 0xbe; i++, scan++) {
            if (!scan->unk_0) {
                scan->unk_0 = 1;
                /* The shared exit preserves the counted search result. */
                goto slot_found;
            }
        }
        i = -1;
    }
slot_found:
    if (i < 0) {
        return -1;
    }
    {
        EffectEntry *entry;
        entry = *(EffectEntry **)&lbl_1_bss_6C848 + i;
    memcpy(entry, source, 0xe8);
    entry->unk_0 = 1;
    entry->unk_2 = i;
    lbl_1_data_1D1D8[entry->unk_C](entry);
    entry->unk_4 = lbl_1_bss_6C850;
    lbl_1_bss_6C850++;
    if (lbl_1_bss_6C850 < 0) {
        lbl_1_bss_6C850 = 0;
    }
        return entry->unk_4;
    }
}
/* fzgx:end fn_1_58E3C */

/* fzgx:begin fn_1_58F50 */
/* Allocate an effect entry, initialize it, and return its sequence number. */

s16 fn_1_58F50(const void *source) {
    fn_1_58F50_EffectEntry *entry;
    s32 index;
    u8 *cursor;

    if ((int)fn_1_3FC8C() != 0) {
        return -1;
    }
    if ((int)fn_1_3FC58() != 0) {
        return -1;
    }

    cursor = *(u8 **)&lbl_1_bss_6C848;
    index = 0;
    for (; index < 0xbe;) {
        if (*(s8 *)cursor == 0) {
            *cursor = 1;
            goto found; /* irreducible split between allocation and failure */
        }
        index++;
        cursor += 0xe8;
    }
    index = -1;
found:
    if (index < 0) {
        return -1;
    }

    entry = (fn_1_58F50_EffectEntry *)(*(u8 **)&lbl_1_bss_6C848) + index;
    memcpy(entry, source, 0xe8);
    entry->unk_0 = 1;
    entry->unk_2 = index;
    lbl_1_data_1D1D8[entry->unk_C](entry);

    entry->unk_4 = lbl_1_bss_6C850;
    lbl_1_bss_6C850++;
    if (lbl_1_bss_6C850 < 0) {
        lbl_1_bss_6C850 = 0;
    }
    return entry->unk_4;
}
/* fzgx:end fn_1_58F50 */

/* fzgx:begin fn_1_59078 */
s16 fn_1_59078(Obj_1_bss_6C84C_Target *arg0) {
    Obj_1_bss_6C84C_Target *obj;
    s32 i;

    if ((int)fn_1_3FC8C() != 0) {
        return -1;
    }
    if ((int)fn_1_3FC58() != 0) {
        return -1;
    }

    obj = lbl_1_bss_6C84C;
    for (i = 0; i < 0xbe; i++, obj++) {
        if ((s8)obj->unk_0 == 0) {
            obj->unk_0 = 1;
            // Skip the exhaustion path when a free slot is found.
            goto slot_found;
        }
    }
    i = -1;
slot_found:
    if (i < 0) {
        return -1;
    }

    obj = lbl_1_bss_6C84C + i;
    memcpy(obj, arg0, 0xe8);
    obj->unk_0 = 1;
    obj->unk_2 = i;
    lbl_1_data_1D1D8[obj->unk_C](obj);
    obj->unk_4 = lbl_1_bss_6C850;
    lbl_1_bss_6C850++;
    if (lbl_1_bss_6C850 < 0) {
        lbl_1_bss_6C850 = 0;
    }
    return obj->unk_4;
}
/* fzgx:end fn_1_59078 */

/* fzgx:begin fn_1_591A0 */
void fn_1_591A0(s32 id) {
    {
        Fn591A0Obj *obj;
        void (**table)(void *);
        s32 count;
        s32 zero;

        obj = *(Fn591A0Obj **)&lbl_1_bss_6C848;
        table = lbl_1_data_1D514;
        zero = 0;
        for (count = 0xbe; count > 0; count--) {
            if (obj->unk_0 && obj->unk_C == id) {
                table[obj->unk_C](obj);
                obj->unk_8 |= (u32)0x8000 << 16;
                obj->unk_0 = zero;
            }
            obj++;
        }
    }
    {
        s32 count;
        Fn591A0Obj *obj;
        void (**table)(void *);
        s32 zero;

        obj = (Fn591A0Obj *)lbl_1_bss_6C84C;
        table = lbl_1_data_1D514;
        zero = 0;
        for (count = 0xc8; count > 0; count--) {
            if (obj->unk_0 && obj->unk_C == id) {
                table[obj->unk_C](obj);
                obj->unk_8 |= (u32)0x8000 << 16;
                obj->unk_0 = zero;
            }
            obj++;
        }
    }
}
/* fzgx:end fn_1_591A0 */

/* fzgx:begin fn_1_59290 */
void fn_1_59290(void) {
    u8 buffer1[0xe8];
    u8 buffer2[0xe8];
    int count;
    Obj_1_bss_6C84C_Target *effect;
    Obj_1_bss_6C84C_Target *effects;

    effects = *(Obj_1_bss_6C84C_Target **)&lbl_1_bss_6C848;
    effect = effects;
    count = 0xbe;
    for (; count > 0; count--, effect++) {
        if ((s8)effect->unk_0 != 0) {
            if (effect->unk_C == 1) {
                fn_80008BEC(buffer1, 0, 0xe8);
                *(s16 *)(buffer1 + 0x4) = effect->unk_4;
                buffer1[0] = effect->unk_0;
                *(s16 *)(buffer1 + 0xc) = effect->unk_C;
                *(u32 *)(buffer1 + 0x38) = effect->unk_38;
                *(u32 *)(buffer1 + 0x34) = effect->unk_34;
                *(u16 *)(buffer1 + 0x1a) = effect->unk_1A;
                *(s16 *)(buffer1 + 0x18) = effect->unk_18;
                fn_80008BEC(effect, 0, 0xe8);
                fn_80008BA8(effect, buffer1, 0xe8);
            } else if (effect->unk_C != 4) {
                effect->unk_0 = 3;
                effect->unk_8 |= (u32)1 << 31;
            }
        }
    }

    effects = lbl_1_bss_6C84C;
    effect = effects;
    count = 0xc8;
    for (; count > 0; count--, effect++) {
        if ((s8)effect->unk_0 != 0) {
            if (effect->unk_C == 1) {
                fn_80008BEC(buffer2, 0, 0xe8);
                *(s16 *)(buffer2 + 0x4) = effect->unk_4;
                buffer2[0] = effect->unk_0;
                *(s16 *)(buffer2 + 0xc) = effect->unk_C;
                *(u32 *)(buffer2 + 0x38) = effect->unk_38;
                *(u32 *)(buffer2 + 0x34) = effect->unk_34;
                *(u16 *)(buffer2 + 0x1a) = effect->unk_1A;
                *(s16 *)(buffer2 + 0x18) = effect->unk_18;
                fn_80008BEC(effect, 0, 0xe8);
                fn_80008BA8(effect, buffer2, 0xe8);
            } else if (effect->unk_C != 4) {
                effect->unk_0 = 3;
                effect->unk_8 |= (u32)1 << 31;
            }
        }
    }
}
/* fzgx:end fn_1_59290 */

/* fzgx:begin fn_1_5942C */
// fn_1_5942C: wrapper that calls fn_1_680F8

void fn_1_5942C(void) {
    fn_1_680F8();
}
/* fzgx:end fn_1_5942C */

/* fzgx:begin fn_1_5944C */
void fn_1_5944C(void) {
    fn_1_68284();
}
/* fzgx:end fn_1_5944C */

/* fzgx:begin fn_1_5946C */
void fn_1_5946C(void) {
    fn_1_68B68();
}
/* fzgx:end fn_1_5946C */

/* fzgx:begin fn_1_5948C */
void fn_1_5948C(void) {
    fn_1_68248();
}
/* fzgx:end fn_1_5948C */

/* fzgx:begin fn_1_594AC */
void fn_1_594AC(void) {
    fn_1_69BBC();
}
/* fzgx:end fn_1_594AC */

/* fzgx:begin fn_1_594CC */
void fn_1_594CC(void) {
    fn_1_69BCC();
}
/* fzgx:end fn_1_594CC */

/* fzgx:begin fn_1_594EC */
// fn_1_594EC: empty in retail (single blr).

void fn_1_594EC(void) {
}
/* fzgx:end fn_1_594EC */

/* fzgx:begin fn_1_594F0 */
// fn_1_594F0: empty in retail (single blr).

void fn_1_594F0(void) {
}
/* fzgx:end fn_1_594F0 */

/* fzgx:begin fn_1_594F4 */
// fn_1_594F4: empty in retail (single blr).

void fn_1_594F4(void) {
}
/* fzgx:end fn_1_594F4 */

/* fzgx:begin fn_1_594F8 */
// fn_1_594F8: empty in retail (single blr).

void fn_1_594F8(void) {
}
/* fzgx:end fn_1_594F8 */

/* fzgx:begin fn_1_594FC */
// fn_1_594FC: empty in retail (single blr).

void fn_1_594FC(void) {
}
/* fzgx:end fn_1_594FC */

/* fzgx:begin fn_1_59500 */
// fn_1_59500: empty in retail (single blr).

void fn_1_59500(void) {
}
/* fzgx:end fn_1_59500 */

/* fzgx:begin fn_1_59504 */
EffectHandler lbl_1_data_1D638[4] = {(EffectHandler)fn_1_594F4, (EffectHandler)fn_1_594F8, (EffectHandler)fn_1_594FC, (EffectHandler)fn_1_59500};

// fn_1_59504: empty in retail (single blr).

void fn_1_59504(void) {
}
/* fzgx:end fn_1_59504 */

/* fzgx:begin fn_1_59508 */
// fn_1_59508: empty in retail (single blr).

void fn_1_59508(void) {
}
/* fzgx:end fn_1_59508 */

/* fzgx:begin fn_1_5950C */
// fn_1_5950C: empty in retail (single blr).

void fn_1_5950C(void) {
}
/* fzgx:end fn_1_5950C */

/* fzgx:begin fn_1_59510 */
// fn_1_59510: empty in retail (single blr).

void fn_1_59510(void) {
}
/* fzgx:end fn_1_59510 */

/* fzgx:begin fn_1_59514 */
void fn_1_59514(void *obj) {
    if (*(s32 *)((u8 *)obj + 0x10) == 0) {
        u32 s = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        u32 r;
        lbl_1_data_1D628 = s;
        r = (s >> 16) & 0x7fff;
        *(s32 *)((u8 *)obj + 0x10) = (s32)(60.0f * (0.1f + (f32)r / 32767.0f));
    }

    {
        f32 t = fn_1_8652C(*(s16 *)((u8 *)obj + 0x18));
        u32 s = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        u32 r;
        lbl_1_data_1D628 = s;
        r = (s >> 16) & 0x7fff;
        *(f32 *)((u8 *)obj + 0x94) = 0.05f * ((f32)r / 32767.0f);
        *(f32 *)((u8 *)obj + 0x98) = (f32)(0.07 + t / 20000.0f);
    }
}
/* fzgx:end fn_1_59514 */

/* fzgx:begin fn_1_5962C */
void fn_1_5962C(Fn_1_5962C_State *self) {
    f32 scale;
    s32 t;

    self->prev = self->field_3c.bits;
    scale = 1.0f - self->field_94;
    self->field_4c += -0.03f;
    self->field_48 *= scale;
    self->field_4c *= scale;
    self->field_50 *= scale;
    self->field_3c.pos.x += self->field_48;
    self->field_3c.pos.y += self->field_4c;
    self->field_3c.pos.z += self->field_50;
    self->field_94 += (f32)(0.05f * (self->field_98 - self->field_94));
    self->field_28 += (f32)(0.1f * (self->field_2c - self->field_28));
    t = self->timer;
    if (t < 15.0) {
        self->field_1c = self->field_1c * (1.0f - 1.0f / (t + 1));
        self->field_20 = self->field_20 * (1.0f - 1.0f / (t + 1));
        self->field_24 = self->field_24 * (1.0f - 1.0f / (t + 1));
    }
}
/* fzgx:end fn_1_5962C */

/* fzgx:begin fn_1_59770 */
/* begin game/vec3.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define GAME_VEC3_H

#pragma opt_lifetimes off

#pragma opt_propagation off

void fn_1_59770(fn_1_59770_Effect *effect)
{
    f32 workZ;
    f32 workY;
    f32 headY;
    f32 headX;
    f32 workX;
    f32 width;
    f32 offset;
    f32 tailX;
    f32 shiftedX;
    f32 offsetY;
    f32 mtx[3][4];
    fn_1_59770_Sprite sprite;
    Vec3 head;
    Vec3 tail;
    Vec3 mid;
    Vec3 dir;
    s16 rotX;
    s16 rotY;
    f32 size;
    f32 scale;
    f32 len;
    f32 dy;
    void *target;

    target = effect->unk34;
    fn_1_8636C(effect->unk18, mtx);
    scale = effect->scale;
    lbl_8006DBAC((void *)lbl_801A66CC.unk_0);
    lbl_8006E1B0(&effect->prevPos, &tail);
    lbl_8006DCA4();
    lbl_8006E1B0(&effect->pos, &head);
    tail.x = (f64)(1.5 * tail.x) - (f64)(0.5 * head.x);
    tail.y = (f64)(1.5 * tail.y) - (f64)(0.5 * head.y);
    tail.z = (f64)(1.5 * tail.z) - (f64)(0.5 * head.z);
    if (head.z < 0.0f && tail.z < 0.0f) {
        size = effect->scale;
        dir.x = head.x - tail.x;
        dir.y = head.y - tail.y;
        if (0.0f == dir.x && 0.0f == dir.y) {
            lbl_8006E0A4(&effect->pos);
            lbl_8006DC6C(mtx);
            mathutil_mtxA_rotate_x(0x4000);
        } else {
            dir.z = 0.0f;
            lbl_8006D668(&dir);
            width = scale;
            width *= 0.1f;
            workZ = dir.x;
            workY = dir.y;
            /* Keep the endpoint loads in their original evaluation order. */
            headX = head.x;
            workX = tail.x;
            offset = workZ * width;
            offsetY = workY * width;
            workY = tail.y;
            tailX = workX - offset;
            headY = head.y;
            shiftedX = headX + offset;
            offset = workY - offsetY;
            width = 0.5f;
            headY = headY + offsetY;
            workY = shiftedX - tailX;
            headX = shiftedX + tailX;
            head.x = shiftedX;
            offsetY = headY - offset;
            workY = workY * workY;
            head.y = headY;
            shiftedX = head.z - tail.z;
            tail.x = tailX;
            headY = headY + offset;
            workY = offsetY * offsetY + workY;
            tail.y = offset;
            dy = width * headY;
            headX = width * headX;
            mid.x = headX;
            mid.y = dy;
            mid.z = width * (head.z + tail.z);
            workY = shiftedX * shiftedX + workY;
            len = lbl_8006D0B4(workY);
            fn_8006EDBC(&head, &tail, &rotX, &rotY);
            lbl_8006D7DC(&mid);
            mathutil_mtxA_rotate_y(rotY);
            mathutil_mtxA_rotate_x(rotX);
            lbl_8006E15C(1.0f, 1.0f, len / scale);
            mathutil_mtxA_rotate_x(0x4000);
            fn_8006E294(&dir);
            mathutil_mtxA_rotate_y(lbl_8006D24C(dir.x, dir.z));
        }
        memset(&sprite, 0, sizeof(sprite));
        lbl_8006DB74(sprite.mtx);
        sprite.scale = 8.0f * size;
        if ((effect->flags >> 14) & 1) {
            sprite.scale = sprite.scale / 2.0f;
        }
        sprite.r = 255.0f * effect->red;
        sprite.g = 255.0f * effect->green;
        sprite.b = 255.0f * effect->blue;
        sprite.a = 0xff;
        fn_1_9F914(&sprite, target);
    }
}

#pragma opt_propagation reset
#undef GAME_VEC3_H
#pragma opt_lifetimes reset
/* fzgx:end fn_1_59770 */

/* fzgx:begin fn_1_59A70 */
// fn_1_59A70: empty in retail (single blr).

void fn_1_59A70(void) {
}
/* fzgx:end fn_1_59A70 */

/* fzgx:begin fn_1_59A74 */
void fn_1_59A74(struct fn_1_59A74_Arg0 *arg0) {
    u32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v4;

    arg0->unk_1A = (0x10000 - 1);
    v0 = ((lbl_1_data_1D628 * (0x41C60000 + 20077)) + 12345);
    lbl_1_data_1D628 = v0;
    v1 = ((v0 >> 16) & 0x7FFF);
    v2 = v1 / 32767.0f;
    v3 = 0.5f * v2;
    v4 = 0.1f + v3;
    arg0->unk_10 = (s32)(60.0f * v4);
}
/* fzgx:end fn_1_59A74 */

/* fzgx:begin fn_1_59B00 */
void fn_1_59B00(fn_1_59B00_Effect *effect) {
    if (effect->frame < 15.0f) {
        effect->value = effect->value * (1.0f - 1.0f / (effect->frame + 1));
    } else {
        f32 delta = (effect->target - effect->value) * 0.2f;

        effect->value += delta;
    }
}
/* fzgx:end fn_1_59B00 */

/* fzgx:begin fn_1_59B90 */
void fn_1_59B90(SelfObj *arg0) {
    MgrObj *mgr;
    NodeObj *r;
    Mtx pos;
    Vec3_59B90 dir;
    f32 x, y, z;
    f32 len;
    f32 t;

    mgr = (MgrObj *)lbl_1_bss_38458->unk_8;
    r = mgr->unk_90;
    lbl_8006D9D8(&arg0->unk_3C);
    mathutil_mtxA_rotate_y(arg0->unk_56);
    mathutil_mtxA_rotate_x(arg0->unk_54);
    lbl_8006E14C(arg0->f28 / r->f14);
    if (fn_1_54E34(&r->v8, arg0->f28) != 0) {
        psvec_set(&dir, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        lbl_8006DB74(&pos);
        x = dir.x;
        y = dir.y;
        z = dir.z;
        len = x * x;
        len += y * y;
        len += z * z;
        len = lbl_8006D0B4(len);
        t = (len - 0.1f) / len;
        lbl_8006D848(t);
        lbl_8006DFC4(&pos);
        fn_1_56000(1, 3, 0);
        u_gxutil_upload_some_mtx((u32)lbl_801A6D00, 0);
        fn_1_556B8(r);
        fn_1_56000(1, 3, 1);
    }
}
/* fzgx:end fn_1_59B90 */

/* fzgx:begin fn_1_59CC4 */
// fn_1_59CC4: empty in retail (single blr).

void fn_1_59CC4(void) {
}
/* fzgx:end fn_1_59CC4 */

/* fzgx:begin fn_1_59CC8 */
/* +0x0 = 60.0f */

/* placeholder, replaced below */

void fn_1_59CC8(struct Fn159CC8Object *arg0) {
    if (arg0->unk_10 == 0) {
        u32 seed = (0x41C64E6D * lbl_1_data_1D628) + 0x3039;

        f32 value;
        f32 scaled;

        lbl_1_data_1D628 = seed;
        value = ((seed >> 16) & 0x7FFF);
        scaled = 0.25f * (value / 32767.0f);
        arg0->unk_10 = (60.0f * (0.08f + scaled));
    }
}
/* fzgx:end fn_1_59CC8 */

/* fzgx:begin fn_1_59D54 */
void fn_1_59D54(fn_1_59D54_Effect *effect) {
    f32 coords[3];
    f32 dz, dy, dx, dist;

    effect->velocity_x *= 0.98f;
    effect->velocity_y *= 0.98f;
    effect->velocity_z *= 0.98f;
    effect->position_x += effect->velocity_x;
    effect->position_y += effect->velocity_y;
    effect->position_z += effect->velocity_z;

    effect->scale_x *= 0.99f;
    effect->scale_y *= 0.99f;
    effect->scale_z *= 0.99f;
    effect->accumulator_x += effect->scale_x;
    effect->accumulator_y += effect->scale_y;
    effect->accumulator_z += effect->scale_z;

    effect->intensity = 0.5f * effect->frame;

    fn_1_862D4(effect->effect_id, coords);

    dx = coords[0] - effect->position_x;
    dist = dx * dx;
    dy = coords[1];
    dy = dy - effect->position_y;
    dist += dy * dy;
    dz = coords[2];
    dz = dz - effect->position_z;
    dist += dz * dz;
    dist = lbl_8006D0B4(dist);

    if (dist > 40.0f) {
        effect->state = 3;
    } else if (dist > 20.0f) {
        effect->intensity *= 0.05f * (dist - 20.0f);
    }
}
/* fzgx:end fn_1_59D54 */

/* fzgx:begin fn_1_59EE4 */
static Fn59EE4CurveKey lbl_1_data_1D648[2] = {{2, 0.0f, 0.0f, 0.0f, 0.0f}, {2, 1.0f, 0.0f, 0.0f, 0.0f}};
static Fn59EE4CurveKey lbl_1_data_1D670[2] = {{2, 0.0f, 0.0f, 0.0f, 0.0f}, {2, 1.0f, 0.0f, 0.0f, 0.0f}};
static Fn59EE4CurveKey lbl_1_data_1D698[2] = {{2, 0.0f, 0.0f, 0.0f, 0.0f}, {2, 1.0f, 0.0f, 0.0f, 0.0f}};

static inline f32 fn_1_59EE4_vec_len(Fn59EE4Vec *v) {
    return lbl_8006D0B4(mathutil_sum_of_sq_3(v->x, v->y, v->z));
}

static inline f32 fn_1_59EE4_randf(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    return ((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f;
}

static inline f32 fn_1_59EE4_jitter(f32 amount) {
    return amount * (fn_1_59EE4_randf() - 0.5f);
}

static inline void fn_1_59EE4_to_color(Fn59EE4Color *c, Fn59EE4Vec *v) {
    c->r = __OSf32tou8(v->x);
    c->g = __OSf32tou8(v->y);
    c->b = __OSf32tou8(v->z);
    c->a = 255;
}

#define FN_1_59EE4_CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_59EE4(Fn59EE4Effect *effect) {
    Fn59EE4Vertex verts[12];
    Fn59EE4Vec pts[2];
    Fn59EE4Glow glow;
    Fn59EE4Vec target;
    Fn59EE4Vec delta;
    Fn59EE4Vec mid;
    Fn59EE4Vec prev;
    Fn59EE4Vec cur;
    Fn59EE4Vec start;
    f32 radii[2];
    Fn59EE4Color color;
    f32 dist;
    f32 len;
    f32 k;
    f32 bright;
    f32 bend;
    f32 scale;
    f32 t;
    f32 step;
    f32 size;
    f32 spark;
    f32 depth;
    f32 radius;
    Fn59EE4Vec *w;
    s32 i;
    Fn59EE4Vertex *out;
    s32 n;
    s16 count;

    if (((Fn59EE4Racer *)fn_1_868C0(effect->id))->mode >= 5) {
        Fn59EE4Owner *owner = fn_1_86254(effect->id);
        if ((s8)owner->camera == -1 || fn_1_6EC0(owner->camera) == 0 ||
            camera_get_entry_field_0xa4(owner->camera) != 0) {
            return;
        }
    }

    fn_1_862D4(effect->id, &target);
    pts[1] = target;
    pts[0] = effect->pos;
    psvec_sub(&pts[1], &pts[0], &delta);
    mid = delta;
    dist = fn_1_59EE4_vec_len(&delta);
    len = dist;
    if (dist > 1.5f) {
        len -= 1.5f;
        k = (dist - 1.5f) / dist;
        psvec_scale(&mid, k, &mid);
    }
    len *= 0.5f;
    psvec_scale_add(&pts[0], &mid, 0.5f, &mid);
    lbl_8006DCA4();
    if (fn_1_54E34(&mid, len) == 0) {
        return;
    }

    psvec_scale(&delta, 1.5f / dist, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
    psvec_sub(&pts[1], &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work, &pts[1]);

    bright = effect->scale * (0.45f * effect->scale);
    if (bright > 1.0f) {
        bright = 255.0f;
    } else {
        bright *= 255.0f;
    }
    psvec_scale(effect->color, bright, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
    fn_1_59EE4_to_color(&color, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);

    scale = effect->scale;
    psvec_sub(&effect->dir, &target, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
    bend = -2.0f * scale;
    lbl_8006D5F0(&((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work, 1.0f + scale);

    lbl_1_data_1D648[0].value = pts[1].x;
    lbl_1_data_1D648[0].tanOut = lbl_1_data_1D648[0].tanIn = ((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work.x;
    lbl_1_data_1D648[1].value = pts[0].x;
    lbl_1_data_1D648[1].tanOut = lbl_1_data_1D648[1].tanIn = effect->bend[0] * bend;
    lbl_1_data_1D670[0].value = pts[1].y;
    lbl_1_data_1D670[0].tanOut = lbl_1_data_1D670[0].tanIn = ((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work.y;
    lbl_1_data_1D670[1].value = pts[0].y;
    lbl_1_data_1D670[1].tanOut = lbl_1_data_1D670[1].tanIn = effect->bend[1] * bend;
    lbl_1_data_1D698[0].value = pts[1].z;
    lbl_1_data_1D698[0].tanOut = lbl_1_data_1D698[0].tanIn = ((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work.z;
    lbl_1_data_1D698[1].value = pts[0].z;
    lbl_1_data_1D698[1].tanOut = lbl_1_data_1D698[1].tanIn = effect->bend[2] * bend;

    start = pts[1];
    verts[0].pos = start;
    verts[0].color = color;
    prev = start;
    out = &verts[1];
    step = 1.0f / 12.0f;
    for (i = 5; i > 0; i--) {
        t = 1.0f - (f32)((i + 1) * step);
        cur.x = fn_1_9E14C(2, lbl_1_data_1D648, t);
        cur.y = fn_1_9E14C(2, lbl_1_data_1D670, t);
        cur.z = fn_1_9E14C(2, lbl_1_data_1D698, t);
        {
            Fn59EE4Vertex *v = &out[1];
            v->pos.x = cur.x + fn_1_59EE4_jitter(0.25f);
            v->pos.y = cur.y + fn_1_59EE4_jitter(0.25f);
            v->pos.z = cur.z + fn_1_59EE4_jitter(0.25f);
            v->color = color;
        }
        psvec_add(&cur, &prev, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
        psvec_scale(&((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work, 0.5f, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
        w = &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work;
        out[0].pos.x = w->x + fn_1_59EE4_jitter(0.15f);
        out[0].pos.y = w->y + fn_1_59EE4_jitter(0.15f);
        out[0].pos.z = w->z + fn_1_59EE4_jitter(0.15f);
        out[0].color = color;
        prev = cur;
        out += 2;
    }
    out->pos = pts[0];
    out->color = color;

    n = effect->frame * 2 + 5;
    if (n > effect->max_count) {
        n = effect->max_count;
    }
    count = n;
    fn_1_581AC(count, 12, verts);

    size = 0.25f * effect->scale;
    spark = 255.0f * ((0.125f + (f32)(0.5f * size)) * (1.0f + fn_1_59EE4_randf()));
    glow.unk_12 = 0;
    psvec_scale(effect->color, spark, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
    fn_1_59EE4_to_color(&glow.color, &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);

    depth = fn_1_A71AC();
    lbl_8006E1B0(&pts[0], &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
    radii[0] = size * FN_1_59EE4_CLAMP(-0.4f * ((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work.z * depth, 0.2f, 1.5f);
    lbl_8006E1B0(&pts[1], &((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work);
    radii[1] = size * FN_1_59EE4_CLAMP(-0.3f * ((Fn59EE4Scratch *)lbl_801A66CC.unk_0)->work.z * depth, 0.2f, 1.5f);

    for (i = 0; i <= 1; i++) {
        if (i == 1 && ((effect->flags >> 16) & 1)) {
            return;
        }
        if (fn_1_54E34(&pts[i], radii[i])) {
            if ((effect->flags >> 16) & 1) {
                f32 s = fn_1_8652C(effect->id);
                f32 k = FN_1_59EE4_CLAMP(s / 250.0f + (i == 0 ? 0.2f : 0.5f), 1.0f, 2.0f);
                radius = k * radii[i] * (0.6 + (f64)(0.4 * fn_1_59EE4_randf()));
            } else {
                radius = radii[i];
            }
            glow.pos = pts[i];
            glow.radius = radius;
            glow.unk_10 = 0;
            fn_1_9F9A4(&glow);
        }
    }
}
#undef FN_1_59EE4_CLAMP
/* fzgx:end fn_1_59EE4 */

/* fzgx:begin fn_1_5A8CC */
// fn_1_5A8CC: empty in retail (single blr).

void fn_1_5A8CC(void) {
}
/* fzgx:end fn_1_5A8CC */

/* fzgx:begin fn_1_5A8D0 */
void fn_1_5A8D0(Fn1_5A8D0Data *data) {
    data->field_10 = 2;
}
/* fzgx:end fn_1_5A8D0 */

/* fzgx:begin fn_1_5A8DC */
static inline s32 allocate_5A8DC(void) {
 Effect_5A8DC *p = *(Effect_5A8DC **)&lbl_1_bss_6C848;
 s32 i;
 for (i=0; i<190; i++,p++) {
  if(p->unk_0 == 0) { p->unk_0=1; return i; }
 }
 return -1;
}

void fn_1_5A8DC(Arg_5A8DC *arg0) {
 Vec3_5A8DC loc_20;
 Vec3_5A8DC old;
 Vec3_5A8DC loc_8;
 Effect_5A8DC loc_2C;
 f32 dx,dy,dz;
 s32 i;
 Effect_5A8DC *p;
 old = arg0->unk_3C;
 fn_1_8645C(arg0->unk_18, lbl_801A6D00);
 lbl_8006E1B0(&arg0->unk_94, &loc_20);
 lbl_8006E1F0(&loc_8, 0.0f, 0.0f, 1.0f);
 dx = loc_20.x-old.x;
 dy = loc_20.y-old.y;
 dz = loc_20.z-old.z;
 arg0->unk_3C = loc_20;
 memset(&loc_2C,0,sizeof(loc_2C));
 loc_2C.unk_18 = arg0->unk_18;
 loc_2C.unk_C = 9;
 loc_2C.unk_1A = 65535;
 loc_2C.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8+0x120);
 loc_2C.unk_3C = loc_20;
 loc_2C.unk_94 = arg0->unk_94;
 loc_2C.unk_48.x = dx;
 loc_2C.unk_48.y = dy;
 loc_2C.unk_48.z = dz;
 loc_2C.unk_3C.x -= dx;
 loc_2C.unk_3C.y -= dy;
 loc_2C.unk_3C.z -= dz;
 fn_8006EF10(&loc_8,&loc_2C.unk_54,&loc_2C.unk_56);
 loc_2C.unk_28 = 0.3f;
 lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
 loc_2C.unk_2C = 0.3f + (f32)(0.2f * (((lbl_1_data_1D628 >> 16)&0x7FFF) / 32767.0f));
 loc_2C.unk_1C = arg0->unk_1C;
 if ((s32)fn_1_3FC58() == 0) {
  i = allocate_5A8DC();
  if(i>=0) {
   arg0 = (Arg_5A8DC *)&(*(Effect_5A8DC **)&lbl_1_bss_6C848)[i];
   memcpy(arg0,&loc_2C,sizeof(loc_2C));
   ((Effect_5A8DC *)arg0)->unk_0=1;
   ((Effect_5A8DC *)arg0)->unk_2=i;
   lbl_1_data_1D1D8[((Effect_5A8DC *)arg0)->unk_C]((Effect_5A8DC *)arg0);
   ((Effect_5A8DC *)arg0)->unk_4=lbl_1_bss_6C850;
   lbl_1_bss_6C850++;
   if(lbl_1_bss_6C850<0) lbl_1_bss_6C850=0;
  }
 }
}
/* fzgx:end fn_1_5A8DC */

/* fzgx:begin fn_1_5ABC4 */
// fn_1_5ABC4: empty in retail (single blr).

void fn_1_5ABC4(void) {
}
/* fzgx:end fn_1_5ABC4 */

/* fzgx:begin fn_1_5ABC8 */
// fn_1_5ABC8: empty in retail (single blr).

void fn_1_5ABC8(void) {
}
/* fzgx:end fn_1_5ABC8 */

/* fzgx:begin fn_1_5ABCC */
void fn_1_5ABCC(Fn1_5ABCCOutput *out) {
    f32 t;
    f32 scaled;

{
    u32 value;
    value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    lbl_1_data_1D628 = value;
    t = ((value >> 16) & 0x7fff);
}
    scaled = (0.25f) * (t / (32767.0f));
    out->unk_10 = ((60.0f) * ((0.25f) + scaled));
}
/* fzgx:end fn_1_5ABCC */

/* fzgx:begin fn_1_5AC48 */
static inline s16 fn_1_5AC48_spawn(void *source) {
    s32 i;

    if ((s32)fn_1_3FC58() != 0) {
        return -1;
    }

    {
        fn_1_5AC48_Effect *scan;
        scan = *(fn_1_5AC48_Effect **)&lbl_1_bss_6C848;
        i = 0;
        for (; i < 0xbe; i++, scan++) {
            if (!scan->unk_0) {
                scan->unk_0 = 1;
                /* Skip the exhaustion path when a free slot is found. */
                goto slot_found;
            }
        }
        i = -1;
    }
slot_found:
    if (i < 0) {
        return -1;
    }
    {
        fn_1_5AC48_Effect *entry;
        entry = *(fn_1_5AC48_Effect **)&lbl_1_bss_6C848 + i;
        memcpy(entry, source, 0xe8);
        entry->unk_0 = 1;
        entry->unk_2 = i;
        lbl_1_data_1D1D8[entry->unk_C](entry);
        entry->unk_4 = lbl_1_bss_6C850;
        lbl_1_bss_6C850++;
        if (lbl_1_bss_6C850 < 0) {
            lbl_1_bss_6C850 = 0;
        }
        return entry->unk_4;
    }
}

/* Linear congruential random value in [0, 1]. */

static inline f32 fn_1_5AC48_rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    return ((lbl_1_data_1D628 >> 16) & 0x7fff) / 32767.0f;
}

void fn_1_5AC48(fn_1_5AC48_Effect *effect) {
    fn_1_5AC48_Effect spawn;

    effect->vel.y += -0.004f;
    effect->vel.x *= 0.98f;
    effect->vel.y *= 0.98f;
    effect->vel.z *= 0.98f;
    effect->pos.x += effect->vel.x;
    effect->pos.y += effect->vel.y;
    effect->pos.z += effect->vel.z;

    memset(&spawn, 0, 0xe8);
    spawn.unk_18 = effect->unk_18;
    spawn.unk_C = 8;
    spawn.unk_1A = 0xffff;
    spawn.unk_34 = ((fn_1_5AC48_Owner *)lbl_1_bss_38458)->unk_8->unk_70;
    spawn.pos = effect->pos;
    spawn.vel.x = 0.5f * effect->vel.x;
    spawn.vel.y = 0.5f * effect->vel.y;
    spawn.vel.z = 0.5f * effect->vel.z;
    spawn.unk_28 = 0.25f * effect->unk_28;
    spawn.unk_2C = effect->unk_2C * (0.016666668f * fn_1_5AC48_rand());
    spawn.unk_1C = effect->unk_1C;
    fn_1_5AC48_spawn(&spawn);

    if (effect->unk_10 < 15.0f) {
        effect->unk_28 *= 1.0f - 1.0f / (effect->unk_10 + 1);
    }
}
/* fzgx:end fn_1_5AC48 */

/* fzgx:begin fn_1_5AF28 */
void fn_1_5AF28(SelfObj_5AF28 *arg0) {
    NodeObj *r;
    Mtx pos;
    Vec3_5AF28 dir;
    f32 len;

    r = arg0->unk_34;
    lbl_8006D9D8(&arg0->unk_3C);
    lbl_8006D7B0();
    lbl_8006E14C(arg0->f28 / r->f14);
    if (fn_1_54E34(&r->v8, arg0->f28) != 0) {
        psvec_set(&dir, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        len = lbl_8006D0B4(effect_sum_sq(dir.x, dir.y, dir.z));
        if (len > arg0->f28 + 0.1f) {
            lbl_8006DB74(&pos);
            lbl_8006D848((len - arg0->f28) / len);
            lbl_8006DFC4(&pos);
        }
        fn_1_5621C(arg0->f1C, arg0->f20, arg0->f24, 1.0f);
        fn_1_56000(1, 3, 0);
        fn_1_557C4(r);
        fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
        fn_1_56000(1, 3, 1);
    }
}
/* fzgx:end fn_1_5AF28 */

/* fzgx:begin fn_1_5B074 */
// fn_1_5B074: empty in retail (single blr).

void fn_1_5B074(void) {
}
/* fzgx:end fn_1_5B074 */

/* fzgx:begin fn_1_5B078 */
void fn_1_5B078(struct fx_5b078_out *out)
{
    u32 rnd;
    u32 n;
    u32 n_2;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6Du + 0x3039u;
    rnd = lbl_1_data_1D628;
    n = (rnd >> 16) & 0x7FFFu;
    out->field_10 = (((f32)(n / 32767.0f * 0.1f) + 0.125f) * 60.0f);

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6Du + 0x3039u;
    rnd = lbl_1_data_1D628;
    n = (rnd >> 16) & 0x7FFFu;
    out->field_58 = ((n / 32767.0f - 0.5f) * 65536.0f);

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6Du + 0x3039u;
    rnd = lbl_1_data_1D628;
    n_2 = (rnd >> 16) & 0x7FFFu;
    out->field_5e = ((n_2 / 32767.0f - 0.5f) * 4096.0f);

    out->field_b4 = 0.5f;
}
/* fzgx:end fn_1_5B078 */

/* fzgx:begin fn_1_5B188 */
void fn_1_5B188(struct fx_5b188 *p)
{
    f32 d;

    d = 1.0f / (p->field_10 + 1);
    p->field_48 *= 0.96f;
    p->field_4C *= 0.96f;
    p->field_50 *= 0.96f;
    p->field_3C += p->field_48;
    p->field_40 += p->field_4C;
    p->field_44 += p->field_50;
    p->field_5E = 0.99f * p->field_5E;
    p->field_58 += p->field_5E;
    p->field_1C += (f32)(0.05f * (0.4f - p->field_1C));
    p->field_20 += (f32)(0.0505f * (0.4f - p->field_20));
    p->field_24 += (f32)(0.051f * (0.4f - p->field_24));
    if (p->field_10 < 15.0f) {
        p->field_B4 *= 1.0f - d;
        p->field_2C *= 0.95f;
    } else {
        p->field_B4 += (f32)(0.2f * (1.0f - p->field_B4));
    }
}
/* fzgx:end fn_1_5B188 */

/* fzgx:begin fn_1_5B30C */
void fn_1_5B30C(struct fn_1_5B30C_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    f32 v2;
    u32 t3;
    v0 = arg0->unk_34;
    lbl_8006D9D8((void *)((u32)arg0 + 60));
    lbl_8006D7B0();
    lbl_8006E14C((*(f32 *)((u8 *)arg0 + 40) / *(f32 *)(v0 + 20)));
    t3 = fn_1_54E34((void *)(v0 + 8), *(f32 *)((u8 *)arg0 + 40));
    v1 = t3;
    if ((s32)t3 != 0) {
    v1 = *(s16 *)((u8 *)arg0 + 88);
    mathutil_mtxA_rotate_z(v1);
    v2 = *(f32 *)((u8 *)arg0 + 28);
    fn_1_5621C(v2, *(f32 *)((u8 *)arg0 + 32), *(f32 *)((u8 *)arg0 + 36), *(f32 *)((u8 *)arg0 + 180));
    v1 = 1;
    fn_1_56000(v1, 3, 0);
    v1 = v0;
    fn_1_557C4((void *)v1);
    v2 = 1.0f;
    fn_1_5621C(v2, v2, v2, v2);
    v1 = 1;
    fn_1_56000(v1, 3, 1);
    }
}
/* fzgx:end fn_1_5B30C */

/* fzgx:begin fn_1_5B3CC */
// fn_1_5B3CC: empty in retail (single blr).

void fn_1_5B3CC(void) {
}
/* fzgx:end fn_1_5B3CC */

/* fzgx:begin fn_1_5B3D0 */
void fn_1_5B3D0(struct fn_1_5B3D0_Arg0 *arg0) {
    u32 next;
    struct fn_1_5B3D0_State *state;
    u32 random;
    f32 r;

    state = (struct fn_1_5B3D0_State *)&lbl_1_data_1D628;
    next = ((1103515245) * state->unk_0) + 12345;
    random = ((next >> 16) & 0x7FFF);
    r = 0.1f * (random / 32767.0f);
    state->unk_0 = next;
    arg0->unk_10 = (s32)(60.0f * (0.125f + r));
}
/* fzgx:end fn_1_5B3D0 */

/* fzgx:begin fn_1_5B450 */
void fn_1_5B450(Fn1_5B450Object *arg0) {
    s32 frame;
    f32 t;

    fn_1_8645C(arg0->unk_18, lbl_801A6D00);
    lbl_8006E1B0((u8 *)arg0 + 0x94, (u8 *)arg0 + 0x3c);

    arg0->unk_58 += effect_rnd();
    arg0->unk_2c *= 0.95f;
    arg0->unk_28 += arg0->unk_2c;

    frame = arg0->unk_10;
    if (frame < 60.0f) {
        t = 1.0f - 1.0f / (frame + 1);
        arg0->unk_1c *= t;
        arg0->unk_20 *= 0.99f * t;
        arg0->unk_24 *= 0.95f * t;
    }
}
/* fzgx:end fn_1_5B450 */

/* fzgx:begin fn_1_5B578 */
void fn_1_5B578(Obj_1_5B578_T *p)
{
    Obj_1_5B578_Child_T *child;
    f32 d;
    f32 t;
    f32 acc;
    f32 vx;
    f32 vy;
    f32 vz;
    /* volatile: the update calls leave this vector in its frame slot */
    volatile Vec_1_5B578_T v;
    Obj_1_5B578_Entity_T *entity;
    u32 debug[12];

    child = p->unk_34;
    t = ((lbl_801A66A0 + p->unk_2) & 1) ? 1.0f : 0.9f;
    lbl_8006D9D8(&p->unk_3c);
    if (fn_1_54E34(&child->vec, p->unk_28) == 0) {
        return;
    }
    entity = (Obj_1_5B578_Entity_T *)((Obj_1_5B578_World_T *)((Obj_1_5B578_Scene_T *)lbl_1_bss_38458->pad_0)->unk_8)->unk_70;
    lbl_8006D7B0();
    d = p->unk_28 / entity->unk_14;
    lbl_8006E14C(d * t);
    vx = v.x;
    vy = v.y;
    vz = v.z;
    acc = vx * vx;
    acc += vy * vy;
    acc += vz * vz;
    t = lbl_8006D0B4(acc);
    if (t > 0.1f + (f32)(2.0f * p->unk_28)) {
        lbl_8006DB74(debug);
        lbl_8006D848((t - (f32)(2.0f * p->unk_28)) / t);
        lbl_8006DFC4(debug);
    }
    fn_1_56000(1, 3, 0);
    fn_1_5621C(p->unk_1c, p->unk_20, p->unk_24, 0.2f);
    fn_1_557C4(entity);
    t = 1.0f;
    fn_1_5621C(t, t, t, t);
    fn_1_56000(1, 3, 1);
}
/* fzgx:end fn_1_5B578 */

/* fzgx:begin fn_1_5B6F0 */
// fn_1_5B6F0: empty in retail (single blr).

void fn_1_5B6F0(void) {
}
/* fzgx:end fn_1_5B6F0 */

/* fzgx:begin fn_1_5B6F4 */
void fn_1_5B6F4(Fn15B6F4 *obj) {
    u32 seed = lbl_1_data_1D628 * 1103515245 + 12345;
    f32 r = ((seed >> 16) & 0x7FFF) / 32767.0f;
    f64 d = 10.0 * (r - 3.0);

    lbl_1_data_1D628 = seed;
    obj->unk_10 = (150.0 + d);
    obj->unk_14 = obj->unk_10 - 20;
}
/* fzgx:end fn_1_5B6F4 */

/* fzgx:begin fn_1_5B780 */
void fn_1_5B780(Fn15B780 *effect) {
    effect->state = 2;
    if (effect->current <= effect->maximum) {
        effect->step += 2;
        if (effect->step >= 14) {
            effect->step = 14;
        }
    }
    effect->result = 0.5f * effect->current;
}
/* fzgx:end fn_1_5B780 */

/* fzgx:begin fn_1_5B7F8 */
fn_1_5B7F8_Wave lbl_1_data_1D6C0[14] = {
    {0.0f, 0.0f}, {-0.1f, -0.1f}, {0.1f, -0.38f}, {0.6f, -0.12f}, {0.9f, 0.5f}, {0.97f, 1.0f}, {1.0f, 2.0f},
    {1.01f, 3.0f}, {1.01f, 4.0f}, {1.02f, 6.0f}, {1.02f, 8.0f}, {1.02f, 11.0f}, {1.03f, 13.0f},
    {1.03f, 14.0f}
};

/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@842a08a9) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

#define FN_1_5B7F8_RAND() \
    (lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345, \
     ((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f)

/* lbl_1_data_1D6C0 is a table of (y, z) offsets, 8 bytes per point. */

#define FN_1_5B7F8_WAVE lbl_1_data_1D6C0

static inline void fn_1_5B7F8_transform(void *mtx, Fn183D28Vec3 *out, Fn183D28Vec3 *t, Fn183D28Vec3 *in) {
    f32 x;
    f32 y;
    f32 z;
    Fn183D28Vec3 *dest;
    Fn183D28Vec3 *source;
    lbl_8006DC6C(mtx);
    (dest = out);
    (source = in);
    x = dest->x;
    y = dest->y;
    z = dest->z;
    mtx_set_translate((void *)LC_BASE, x, y, z);
    lbl_8006E1B0(source, dest);
}

/* Locked-cache transform scratch: the stores must follow the three loads in order. */

#define FN_1_5B7F8_SET_TRANS(v, tag) \
    do { \
        f32 tag##_z; \
        f32 tag##_y; \
        f32 tag##_x; \
        tag##_x = *(volatile f32 *)&(v).x; /* fzgx-allow: S2 volatile keeps the column loads in order */ \
        tag##_y = (v).y; \
        tag##_z = (v).z; \
        lc[3] = tag##_x; \
        lc[7] = tag##_y; \
        lc[11] = tag##_z; \
    } while (0)

static inline void fn_1_5B7F8_init_lc(volatile f32 **cache) {  /* fzgx-allow: S2 volatile keeps the verified access order */
    *cache = (volatile f32 *)LC_BASE; /* Locked-cache transform matrix. */
}

void fn_1_5B7F8(struct fn_1_5B7F8_Arg0 *e) {
    volatile f32 *lc; /* Locked-cache transform matrix. */
    fn_1_5B7F8_Wave *wave;
    fn_1_5B7F8_Point pts[14];
    int j;
    s32 i;
    fn_1_5B7F8_Point seg[2];
    Fn183D28Vec3 origin;
    Fn183D28Vec3 off;
    fn_1_5B7F8_Color color;
    f32 mtx[3][4];
    f32 t;
    f32 r;
    f32 g;
    f32 b;
    f32 s;
    f32 scale;
    f32 y;

    if (e->unk_10 <= e->unk_14) {
    fn_1_862D4(e->unk_18, &origin);
    fn_1_8636C(e->unk_18, mtx);
    {
    union {
        Fn183D28Vec3 pos;
        f32 xyz[3];
    } position;
    position.pos = origin;
    {
    Fn183D28Vec3 dir = { 0.0f, 0.1f, -2.4f };
    {
        fn_1_5B7F8_transform(mtx, (Fn183D28Vec3 *)position.xyz, &position.pos, &dir);
    }

    t = 0.05f * e->unk_10;
    if (t > 1.0f) {
        r = (f32)(255.0f * e->unk_1C) + (f32)(5.0f * (FN_1_5B7F8_RAND() - 0.5f));
        g = (f32)(255.0f * e->unk_20) + (f32)(5.0f * (FN_1_5B7F8_RAND() - 0.5f));
        b = (f32)(255.0f * e->unk_24) + (f32)(5.0f * (FN_1_5B7F8_RAND() - 0.5f));
    } else {
        r = 255.0f * (e->unk_1C * t);
        g = 255.0f * (e->unk_20 * t);
        b = 255.0f * (e->unk_24 * t);
    }
    color.r = __OSf32tou8(r);
    color.g = __OSf32tou8(g);
    color.b = __OSf32tou8(b);
    color.a = 255;

    i = 2;
    do {
        fn_1_5B7F8_Point *p;
        s32 n;
        wave = FN_1_5B7F8_WAVE;
        ++wave;
        /* The table base is kept separate from the current row. */
        pts[0].pos = position.pos;
        pts[0].color = color;
        dir.x = e->unk_94;
        p = pts;
        ++p;
        for (j = 1; j < e->unk_AC; j++, p++) {
            fn_1_5B7F8_init_lc(&lc);
            off.x = 0.4 * dir.x;
            s = lbl_8006D188(e->unk_98);
            off.z = wave->z;
            y = wave->y;
            y *= s;
            off.y = 1.2 * y;
            if (j == 13) {
                off.z += (f64)(3.0 * FN_1_5B7F8_RAND());
            }
            lbl_8006DC6C(mtx);
            FN_1_5B7F8_SET_TRANS(position.pos, loop);
            lbl_8006E1B0(&off, &p->pos);
            p->color = color;
            ++wave;
            scale = 0.1 * j;
            p->pos.x += (f32)(scale * (FN_1_5B7F8_RAND() - 0.5f));
            p->pos.y += (f32)(scale * (FN_1_5B7F8_RAND() - 0.5f));
            p->pos.z += (f32)(scale * (FN_1_5B7F8_RAND() - 0.5f));
            dir.x += e->unk_94;
        }

        if (e->unk_10 >= 25) {
            n = 10.0f + (f32)(18.0f * (FN_1_5B7F8_RAND() - 0.5f));
        } else {
            n = e->unk_10;
        }
        fn_1_57714(n);
        fn_1_57720(1, 1, 1, 0);
        lbl_8006DCA4();
        if (e->unk_AC > 4) {
            fn_1_57A70(e->unk_AC - 3, pts);
            seg[0] = pts[e->unk_AC - 4];
            seg[1] = pts[e->unk_AC - 3];
            n *= 0.7;
            fn_1_57714(n);
            fn_1_57A70(2, seg);
            seg[0] = pts[e->unk_AC - 3];
            seg[1] = pts[e->unk_AC - 2];
            n *= 0.5;
            fn_1_57714(n);
            fn_1_57A70(2, seg);
            seg[0] = pts[e->unk_AC - 2];
            seg[1] = pts[e->unk_AC - 1];
            n *= 0.5;
            fn_1_57714(n);
            fn_1_57A70(2, seg);
        } else {
            fn_1_57A70(e->unk_AC, pts);
        }
    } while (--i > 0);
    }
    }
    }
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef FN_1_5B7F8_RAND
#undef FN_1_5B7F8_WAVE
#undef FN_1_5B7F8_SET_TRANS
/* fzgx:end fn_1_5B7F8 */

/* fzgx:begin fn_1_5BF6C */
// fn_1_5BF6C: empty in retail (single blr).

void fn_1_5BF6C(void) {
}
/* fzgx:end fn_1_5BF6C */

/* fzgx:begin fn_1_5BF70 */
void fn_1_5BF70(struct fn_1_5BF70_Arg0 *arg0) {
    u32 seed;
    f32 normalized;
    f64 value;

    seed = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    lbl_1_data_1D628 = seed;
    normalized = ((seed >> 16) & 0x7fff) / 32767.0f;
    value = 10.0 * (normalized - 3.0);
    arg0->unk_10 = (value + 50.0);
}
/* fzgx:end fn_1_5BF70 */

/* fzgx:begin fn_1_5BFF0 */
void fn_1_5BFF0(struct fn_1_5BFF0_Arg0 *arg0) {
    arg0->unk_0 = 2;
    arg0->unk_AC += 2;
    if (arg0->unk_AC >= 15) {
    arg0->unk_AC = 15;
    }
    arg0->unk_B4 = (0.5f * (s32)arg0->unk_10);
}
/* fzgx:end fn_1_5BFF0 */

/* fzgx:begin fn_1_5C058 */
static const Fn183D28Vec3 lbl_1_rodata_2A50 = {0.0f, 0.1f, -2.4f};

f32 lbl_1_data_1D730[15][2] = {
    {0.0f, 0.0f}, {-0.8f, -0.8f}, {-0.8f, -2.0f}, {0.0f, -3.0f}, {1.0f, -3.5f}, {2.0f, -3.5f}, {4.0f, -3.0f},
    {5.8f, -1.0f}, {6.3f, 0.0f}, {6.8f, 3.0f}, {7.1f, 5.0f}, {7.3f, 8.0f}, {8.0f, 9.7f}, {8.5f, 11.0f},
    {8.8f, 12.0f}
};

/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@842a08a9) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

static inline void fn5C058Translation(volatile f32 *mtx, volatile Fn183D28Vec3 *v) {  /* fzgx-allow: S2 volatile keeps the verified access order */
    f32 x, y, z;
    /* Preserve the locked-cache translation-column load ordering. */
    x = v->x;
    y = v->y;
    z = v->z;
    mtx[3] = x;
    mtx[7] = y;
    mtx[11] = z;
}

static inline void fn5C058TransformVector(Fn183D28Vec3 *out, Fn183D28Vec3 *in) {
    Fn183D28Vec3 *translated = out;
    f32 x, y, z;
    x = translated->x;
    y = translated->y;
    z = translated->z;
    mtx_set_translate((void *)LC_BASE, x, y, z);
    lbl_8006E1B0(in, translated);
}

static inline int fn5C058CacheInit(volatile f32 **cache) {  /* fzgx-allow: S2 volatile keeps the verified access order */
    *cache = (f32 *)LC_BASE;
    return 1;
}

static inline u32 fn5C058Rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

#define fn5C058Random() ((f32)fn5C058Rand() / 32767.0f)

#pragma opt_lifetimes off

void fn_1_5C058(struct fn_1_5C058_Arg0 *arg0) {
    f32 v13, v14, v16;
    volatile f32 *cache;  /* fzgx-allow: S2 volatile keeps the verified access order */
    u32 color;
    f32 *v25;
    s32 v24;
    Fn5C058Vertex *v23;
    s32 v42;
    f32 v41;
    Fn5C058Vertex loc_98[15];
    f32 loc_68[3][4];
    Fn5C058Vertex loc_48[2];
    Triple loc_3C;
    Fn183D28Vec3 loc_30;
    Fn183D28Vec3 loc_24;
    Fn183D28Vec3 loc_18;
    u8 loc_14[4];
    f32 v4;
    fn_1_862D4(arg0->unk_18, &loc_3C);
    fn_1_8636C(arg0->unk_18, &loc_68);
    loc_24 = *(Fn183D28Vec3 *)&loc_3C;
    loc_18 = lbl_1_rodata_2A50;
    lbl_8006DC6C(&loc_68);
    fn5C058TransformVector(&loc_24, &loc_18);
    v4 = 0.05f * arg0->unk_10;
    if (v4 > 1.0f) {
        v13 = (f32)(5.0f * (fn5C058Random() - 0.5f)) + (f32)(255.0f * arg0->unk_1C);
        v14 = (f32)(5.0f * (fn5C058Random() - 0.5f)) + (f32)(255.0f * arg0->unk_20);
        v16 = (f32)(5.0f * (fn5C058Random() - 0.5f)) + (f32)(255.0f * arg0->unk_24);
    } else {
        v13 = 255.0f * (arg0->unk_1C * v4);
        v14 = 255.0f * (arg0->unk_20 * v4);
        v16 = 255.0f * (arg0->unk_24 * v4);
    }
    loc_14[0] = __OSf32tou8(v13);
    loc_14[1] = __OSf32tou8(v14);
    loc_14[2] = __OSf32tou8(v16);
    loc_14[3] = 255;
    loc_98[0].pos = loc_24;
    loc_98[0].color = *(u32 *)loc_14;
    loc_18.x = arg0->unk_94;
    for (v25 = &lbl_1_data_1D730[1][0], v23 = &loc_98[1], v24 = 1; v24 < arg0->unk_AC; v25 += 2, v24++, v23++) {
        fn5C058CacheInit(&cache);
        loc_30.x = 0.4 * loc_18.x;
        loc_30.y = v25[0] * lbl_8006D188((s32)arg0->unk_98);
        loc_30.z = v25[1];
        if (v24 == 14) {
            loc_30.z = loc_30.z + (f64)(3.0 * fn5C058Random());
        }
        lbl_8006DC6C(&loc_68);
        fn5C058Translation(cache, &loc_24);
        lbl_8006E1B0(&loc_30, &v23->pos);
        v23->color = *(u32 *)loc_14;
        v41 = 0.1 * v24;
        v23->pos.x += (f32)(v41 * (fn5C058Random() - 0.5f));
        v23->pos.y += (f32)(v41 * (fn5C058Random() - 0.5f));
        v23->pos.z += (f32)(v41 * (fn5C058Random() - 0.5f));
        loc_18.x += arg0->unk_94;
    }
    if (arg0->unk_10 >= 10) {
        v42 = (10.0f + (f32)(19.0f * (fn5C058Random() - 0.5f)));
    } else {
        v42 = arg0->unk_10;
    }
    fn_1_57714(v42);
    fn_1_57720(1, 1, 1, 0);
    lbl_8006DCA4();
    if (arg0->unk_AC > 4) {
        fn_1_57A70(arg0->unk_AC - 3, loc_98);
        loc_48[0] = loc_98[arg0->unk_AC - 4];
        v25 = (f32 *)&loc_98[-3];
        loc_48[1] = ((Fn5C058Vertex *)v25)[arg0->unk_AC];
        v42 *= 0.7;
        fn_1_57714(v42);
        fn_1_57A70(2, loc_48);
        loc_48[0] = ((Fn5C058Vertex *)v25)[arg0->unk_AC];
        cache = (f32 *)&loc_98[-2];
        loc_48[1] = ((Fn5C058Vertex *)cache)[arg0->unk_AC];
        v42 *= 0.5;
        fn_1_57714(v42);
        fn_1_57A70(2, loc_48);
        loc_48[0] = ((Fn5C058Vertex *)cache)[arg0->unk_AC];
        loc_48[1] = loc_98[arg0->unk_AC - 1];
        v42 *= 0.5;
        fn_1_57714(v42);
        fn_1_57A70(2, loc_48);
    } else {
        fn_1_57A70(arg0->unk_AC, loc_98);
    }
}

#pragma opt_lifetimes reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef fn5C058Random
/* fzgx:end fn_1_5C058 */

/* fzgx:begin fn_1_5C780 */
// fn_1_5C780: empty in retail (single blr).

void fn_1_5C780(void) {
}
/* fzgx:end fn_1_5C780 */

/* fzgx:begin fn_1_5C784 */
void fn_1_5C784(EffectWork *self) {
    if (self->unk_10 == 0) {
        u32 value = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = value;
        value = (value >> 16) & 0x7FFF;
        self->unk_10 = ((60.0f) * ((0.100000001f) + value / (32767.0f)));
    }
    self->unk_3c = self->unk_94;
    fn_1_8636C(self->unk_18, &self->unk_b8);
}
/* fzgx:end fn_1_5C784 */

/* fzgx:begin fn_1_5C83C */
#define GAME_MAIN_REL_EFFECT_TYPES_H

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

void fn_1_5C83C(struct Fn1_5C83CObject *self) {
    f32 mtx[12];
    f32 pos[3];
    f32 t;
    s32 age;

    self->state = 2;
    fn_1_862D4(self->owner, pos);
    fn_1_8636C(self->owner, mtx);

    t = 1.0f - self->blend;
    self->vel_48 *= t;
    self->vel_4c *= t;
    self->vel_50 *= t;
    self->pos_3c += self->vel_48;
    self->pos_40 += self->vel_4c;
    self->pos_44 += self->vel_50;

    if (self->flag_b2 != 0) {
        self->acc_94 += (f32)(0.2f * self->vel_48);
        self->acc_98 += (f32)(0.2f * self->vel_4c);
        self->acc_9c += (f32)(0.2f * self->vel_50);
    }

    fn_8006FA24(self->matrix_b8, mtx, self->matrix_b8, 0.05f);

    self->blend += (f32)(0.05f * (self->target_blend - self->blend));
    self->size += (f32)(0.2f * (self->target_size - self->size));

    age = self->age;
    if (age < 24.0) {
        /* the common factor is CSE'd by the compiler; writing it out per
           component keeps the color load ahead of the literal */
        self->color_1c = self->color_1c * (1.0f - 1.0f / (age + 1));
        self->color_20 = self->color_20 * (1.0f - 1.0f / (age + 1));
        self->color_24 = self->color_24 * (1.0f - 1.0f / (age + 1));
    }
}
#undef GAME_MAIN_REL_EFFECT_TYPES_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_5C83C */

/* fzgx:begin fn_1_5CA00 */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TYPES_H

#define GAME_VEC3_H

#define FIELD(off) (*(f32 *)((u8 *)arg0 + (off)))

static inline void load_car_matrix(struct fn_1_5CA00_Arg0 *car) {
 lbl_8006E0A4(&car->unk_3C);
}

static inline f32 draw_max(f32 a, f32 b) { if(a>b) return a; return b; }

/* Keep the metadata commit after the alpha write, but allow its read to hoist. */
static inline void init_draw_metadata(struct Draw5CA *d) { *(volatile u8 *)&d->a=255; *(volatile u32 *)&d->flags=d->flags|2; }

#define CLAMP255(v) ((v) < 0.0 ? 0.0 : (v) > 255.0 ? 255.0 : (v))

#define COLORS(R) { d.r=(u8)CLAMP255(1.5*(u32)(R)); d.g=(u8)CLAMP255(1.5*(u32)d.g); d.b=(u8)CLAMP255(1.5*(u32)d.b); }

#pragma opt_propagation off

#pragma opt_loop_invariants off

void fn_1_5CA00(struct fn_1_5CA00_Arg0 *arg0) {
 u32 model;
 u8 mode;
 u32 *draw_mtx;
 u8 i;
 f32 zero,scale,length,half;
 struct Draw5CA d;
 Fn183D28Vec3 loc_3C,loc_30,mid,diff;
 Triple loc_C;
 s16 ax,ay;
 f32 z,y,x,t,width;
 s32 red;
 fn_1_862D4(arg0->unk_18,&loc_C);
 model=*(u32 *)((u8 *)arg0+52);
 lbl_8006DC6C((u8 *)arg0+184);
 x=*(f32 *)((u8 *)&loc_C); y=*(f32 *)((u8 *)&loc_C+4); z=*(f32 *)((u8 *)&loc_C+8);
 mtx_set_translate((void *)LC_BASE, x, y, z);
 lbl_8006E1B0(&arg0->unk_3C,&loc_3C);
 lbl_8006E1B0((Fn183D28Vec3 *)((u8 *)arg0+148),&loc_30);
 lbl_8006DCA4();
 lbl_8006E1B0(&loc_3C,&loc_3C); lbl_8006E1B0(&loc_30,&loc_30);
 if (fn_1_6EC0(fn_1_5910()) && arg0->unk_18==camera_get_mode()) mode=1;
 else if(fn_1_6EC0(fn_1_5910())) mode=2;
 else mode=3;
 memset(&d,0,64);
 scale=FIELD(40);
 d.width=0.7071067690849304f*scale;
 red=(255.0f*FIELD(28)); d.r=red; d.g=(255.0f*FIELD(32)); d.b=(255.0f*FIELD(36)); init_draw_metadata(&d);
 if(mode==1) COLORS((u8)d.r) else COLORS((u8)d.r)
 zero=0.0f; half=0.5f;
 draw_mtx=d.mtx;
 for(i=mode;i!=0;i--) {
 t=FIELD(180);
 switch(i) {
 case 4: loc_3C.x-=t;loc_3C.y+=t;loc_30.x-=t;loc_30.y+=t;break;
 case 3: t=2.0f*t;loc_3C.x+=t;loc_30.x+=t;break;
 case 2: t=2.0f*t;loc_3C.y-=t;loc_30.y-=t;break;
 case 1: if(mode==1) {loc_3C.y=loc_3C.y+(f32)(2.0f*t);} else {t=2.0f*t;loc_3C.x-=t;loc_30.x-=t;}break;
 }
 diff.x=loc_3C.x-loc_30.x; diff.y=loc_3C.y-loc_30.y;
 if(zero==diff.x && zero==diff.y) {load_car_matrix(arg0);lbl_8006D7B0();}
 else {
 f32 x0,x1,z1,y0,z0,y1,sx,sy,mx,sz,factor,dx,dz,dy,sq;
 /* Reload the endpoint snapshot after the degenerate-transform branch. */
 x1=*(f32 *)&loc_3C.x; x0=*(f32 *)&loc_30.x;
 y1=*(volatile f32 *)&loc_3C.y; y0=*(volatile f32 *)&loc_30.y;  /* fzgx-allow: S2 volatile view keeps the verified load order */
 dx=x1-x0; sx=x1+x0;
 z1=loc_3C.z; z0=loc_30.z;
 dy=y1-y0; sq=dx*dx;
 dz=z1-z0; sy=y1+y0;
 factor=0.5f;
 sz=z1+z0;
 sq=sq+dy*dy;
 mx=factor*sx;mid.x=mx;mid.y=factor*sy;mid.z=factor*sz;
 sq=sq+dz*dz;
 length=0.9*lbl_8006D0B4(sq);
 fn_8006EDBC(&loc_3C,&loc_30,&ax,&ay);
 lbl_8006D7DC(&mid);mathutil_mtxA_rotate_y(ay);mathutil_mtxA_rotate_x(ax);
 lbl_8006E15C(1.0f,1.0f,length/scale);
 mathutil_mtxA_rotate_x(0x4000);
 fn_8006E294(&diff);mathutil_mtxA_rotate_y(lbl_8006D24C(diff.x,diff.z));
 }
 lbl_8006DB74(draw_mtx);
 t=length*half;
 width=d.width;
 d.height=draw_max(t,width);
 fn_1_9F914(&d,(void *)model);
 }
}

#pragma opt_propagation reset

#pragma opt_loop_invariants reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef GAME_VEC3_H
#undef FIELD
#undef CLAMP255
#undef COLORS
/* fzgx:end fn_1_5CA00 */

/* fzgx:begin fn_1_5D010 */
// fn_1_5D010: empty in retail (single blr).

void fn_1_5D010(void) {
}
/* fzgx:end fn_1_5D010 */

/* fzgx:begin fn_1_5D014 */
void fn_1_5D014(Fn1_5D014Object *obj) {
    obj->field_ae = 0;
}
/* fzgx:end fn_1_5D014 */

/* fzgx:begin fn_1_5D020 */
void fn_1_5D020(Fx *p) {
    f32 t;
    s32 n;
    p->state = 2;
    lbl_1_bss_6C860 = lbl_1_bss_6C860 + 1;
    if (lbl_1_bss_6C860 > 150) {
        p->state = 3;
    }
    if (fn_1_66B8(&p->unk3c, p->unk28) == 0) {
        p->state = 3;
    }
    t = 1.0f - p->unk88;
    p->unk48 *= t;
    p->unk4c *= t;
    p->unk50 *= t;
    p->unk4c += 0.004f;
    p->unk48 += 0.001f;
    p->unk3c += p->unk48;
    p->unk40 += p->unk4c;
    p->unk44 += p->unk50;
    p->unk88 = p->unk88 + (f32)(0.05f * (p->unk8c - p->unk88));
    p->unk28 = p->unk28 + (f32)(0.01f * (p->unk2c - p->unk28));
    p->unkae += p->unkac;
    n = p->unk10;
    p->unk1c = p->unk1c * (1.0f - 1.0f / (n + 1));
    p->unk20 = p->unk20 * (1.0f - 1.0f / (n + 1));
    p->unk24 = p->unk24 * (1.0f - 1.0f / (n + 1));
}
/* fzgx:end fn_1_5D020 */

/* fzgx:begin fn_1_5D1B8 */
static inline f32 fn_1_5D1B8_scaled(f32 product, f32 scale) { return product; }

void fn_1_5D1B8(Self *self)
{
Vec3_5D1B8 v;
Quad out;
Obj *obj;
Self *s;
f32 cr;
f32 cg;
f32 cb;
f32 scale;
f32 fade;
f32 d;
s = self;
obj = (s->f_34);
scale = s->f_28;
lbl_8006DCA4();
lbl_8006E1B0(&s->v_3c, &v);
if (v.z > -0.00000011920929f) { return; }
d = 240.0f * ((2.0f * obj->f_14) * fn_1_5D1B8_scaled(scale, 1.0f)) / (-v.z * fn_1_A71AC());
fade = 1.0f;
if (d < 100.0f) { return; }
if (d < 300.0f) { f32 range = 200.0f; fade = fade * ((d - 100.0f) / range); }
if (d > 10000.0f) { return; }
if (d > 5000.0f) { fade = fade * (1.0f - (d - 5000.0f) / 5000.0f); }
lbl_8006D7DC(&v);
mathutil_mtxA_rotate_z(s->s_ae);
memset(&out, 0, 0x40);
lbl_8006DB74(&out.pos);
out.x = 0.70710677f * scale;
cr = 255.0f * (s->f_1c);
out.r = cr * fade;
cg = 255.0f * s->f_20;
out.g = cg * fade;
cb = 255.0f * s->f_24;
out.b = cb * fade;
out.a = 255.0f * fade;
out.y = 0.70710677f * scale;
fn_1_9F914(&out, obj);
}
/* fzgx:end fn_1_5D1B8 */

/* fzgx:begin fn_1_5D374 */
// fn_1_5D374: empty in retail (single blr).

void fn_1_5D374(void) {
}
/* fzgx:end fn_1_5D374 */

/* fzgx:begin fn_1_5D378 */
static inline f32 rnd_unit(void)
{
    u32 r;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    r = (lbl_1_data_1D628 >> 16) & 0x7fff;
    return r / 32767.0f;
}

void fn_1_5D378(fn_1_5D378_obj *self)
{
    f32 a;
    f32 b;
    u32 v;

    if (self->unk_10 == 0) {
        a = rnd_unit();
        a = 0.1f * a;
        self->unk_10 = ((0.4f + a) * 60.0f);
    }

    v = fn_1_86634(self->unk_18);

    if (fn_1_6EC0(v) != 0 && camera_get_entry_field_0xa4((u8)v) == 0) {
        *(&self->unk_1c) = 0.0f;
        self->unk_20 = 0.0f;
        self->unk_24 = 0.0f;
    } else {
        b = rnd_unit();
        a = 0.2f * b;
        b = 0.5f + a;
        self->unk_1c = (204.0f * (0.5f * (1.0f + b))) / 255.0f;
        self->unk_20 = (85.0f * b) / 255.0f;
        self->unk_24 = 0.0f;
    }
}
/* fzgx:end fn_1_5D378 */

/* fzgx:begin fn_1_5D4FC */
// fn_1_5D4FC: empty in retail (single blr).

void fn_1_5D4FC(void) {
}
/* fzgx:end fn_1_5D4FC */

/* fzgx:begin fn_1_5D500 */
void fn_1_5D500(EffectUpdate *arg0)
{
    s32 camera;
    f32 random;
    f32 scale;
    if (((fn_1_86514(arg0->unk_18) >> 27) & 1) && ((arg0->unk_8 >> 18) & 1)) {
        arg0->unk_10++;
    } else {
        arg0->unk_8 &= ~0x40000;
    }
    fn_1_867CC(arg0->unk_18, &arg0->unk_3C);
    camera = fn_1_86634(arg0->unk_18);
    if (fn_1_6EC0(camera) && camera_get_entry_field_0xa4((u8)camera) == 0) {
        arg0->unk_1C += (f32)(0.05f * -arg0->unk_1C);
        arg0->unk_20 += (f32)(0.05f * -(arg0->unk_20));
        arg0->unk_24 += (f32)(0.05f * -arg0->unk_24);
    } else {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
        random = 0.5f + (f32)(0.1f * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
        arg0->unk_1C = (204.0f * (0.5f * (1.0f + random))) / 255.0f;
        arg0->unk_20 = (85.0f * random) / 255.0f;
        arg0->unk_24 = 0.0f;
    }
    if (lbl_1_data_2A7E0.unk_0 == 6) {
        arg0->unk_1C *= 0.2f;
        arg0->unk_20 *= 0.2f;
        arg0->unk_24 *= 0.2f;
    }
    if (arg0->unk_10 < 20) {
        scale = 1.0f + (f32)(-0.05f * arg0->unk_10);
        arg0->unk_1C *= 1.0f - scale;
        arg0->unk_20 *= 1.0f - scale;
        arg0->unk_24 *= 1.0f - scale;
    }
}
/* fzgx:end fn_1_5D500 */

/* fzgx:begin fn_1_5D718 */
/* Fixed engine address; three floats at 0xc, 0x1c, 0x2c. */

void fn_1_5D718(struct Fn15D718 *self) {
struct Fn15D718Work work;
struct Fn15D718Tmp tmp;
u32 object;
f32 radius;
f32 distance;
f32 alpha;
f32 v[3];
object = self->object34;
radius = self->value28;
lbl_8006D9D8(&self->value3c);
lbl_8006D7B0();
psvec_set(v, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
distance = lbl_8006D0B4(effect_sum_sq(v[0], v[1], v[2]));
if (distance > 0.1f + radius) {
lbl_8006DB74(&tmp);
lbl_8006D848((distance - radius) / distance);
lbl_8006DFC4(&tmp);
}
memset(&work, 0, 0x40);
lbl_8006DB74(&work.sub);
alpha = 0.70710677f * self->value28;
work.alpha = alpha;
work.red = (255.0f * self->value1c);
work.green = (255.0f * self->value20);
work.blue = (255.0f * self->value24);
work.alphaByte = 0xff;
work.alpha2 = alpha;
fn_1_9F914(&work, (const void *)object);
}
/* fzgx:end fn_1_5D718 */

/* fzgx:begin fn_1_5D88C */
void fn_1_5D88C(struct Fn15D88C *self) {
    self->value_b4 = 255.0f;
    if (self->enabled != 0) {
        f32 value28;
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        value28 = 1.0f;
        self->value54 = ((lbl_1_data_1D628 >> 16) & 0x7fff);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        self->value56 = ((lbl_1_data_1D628 >> 16) & 0x7fff);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        self->value58 = ((lbl_1_data_1D628 >> 16) & 0x7fff);
        self->value28 = value28;
    }
    self->flags |= 0x40000000;
}
/* fzgx:end fn_1_5D88C */

/* fzgx:begin fn_1_5D918 */
// fn_1_5D918: empty in retail (single blr).

void fn_1_5D918(void) {
}
/* fzgx:end fn_1_5D918 */

/* fzgx:begin fn_1_5D91C */
static inline void set_translation(Fn5D91CObj *obj) {
    f32 x, y, z;
    x = obj->unk_94;
    y = obj->unk_98;
    z = obj->unk_9c;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

static inline f32 length(Fn5D91CVec *v) {
    f32 x, y, z, sum;
    x = v->x;
    sum = x * x;
    y = v->y;
    sum += y * y;
    z = v->z;
    sum += z * z;
    return lbl_8006D0B4(sum);
}

/* opt_dead_assignments off keeps z as its own value in the dot product, so up.z takes f4 as in retail
 * (the same pragma and z copy as the sibling fn_1_60880 in avline.c) */

#pragma opt_dead_assignments off

void fn_1_5D91C(Fn5D91CObj *obj) {
    Fn5D91CVec pos;
    Fn5D91CVec vel;
    Fn5D91CVec up;
    f32 len;
    f32 spin;
    f32 z;

    obj->unk_0 = 2;
    if (obj->unk_34 != 0) {
        if (++lbl_1_bss_6C85C > 200) {
            obj->unk_0 = 3;
        }
        if (fn_1_66B8(&obj->unk_3c, 4.0f) == 0) {
            obj->unk_0 = 3;
        }
        obj->unk_48.y += -0.06f;
        lbl_8006D8D8(obj->unk_56);
        mathutil_mtxA_rotate_x(obj->unk_54);
        mathutil_mtxA_rotate_z(obj->unk_58);
        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        lbl_8006E1C0(&up, &up);
        length(&obj->unk_48);
        len = up.x * obj->unk_48.x;
        len += up.y * obj->unk_48.y;
        z = up.z;
        len += z * obj->unk_48.z;
        len = -0.03f * len;
        obj->unk_48.x += (f32)(up.x * len);
        obj->unk_48.y += (f32)(up.y * len);
        obj->unk_48.z += (f32)(up.z * len);
        obj->unk_48.x *= 0.96f;
        obj->unk_48.y *= 0.96f;
        obj->unk_48.z *= 0.96f;
        lbl_8006DC6C(obj->unk_b8);
        set_translation(obj);
        fn_8006E250(&obj->unk_3c, &pos);
        fn_8006E2B0(&obj->unk_48, &vel);
        if (pos.y < -0.5f) {
            lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
            vel.y = -1.0f * vel.y + (f64)(vel.y * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f - 0.5));
            lbl_8006E1C0(&up, &up);
            vel.x = vel.x + (f64)(0.2 * up.x * vel.y);
            vel.y = vel.y + (f64)(0.2 * up.y * vel.y);
            vel.z = vel.z + (f64)(0.2 * up.z * vel.y);
        }
        lbl_8006E1B0(&pos, &obj->unk_3c);
        lbl_8006E1C0(&vel, &obj->unk_48);
        obj->unk_3c.x += obj->unk_48.x;
        obj->unk_3c.y += obj->unk_48.y;
        obj->unk_3c.z += obj->unk_48.z;
        spin = 512.0f / obj->unk_28;
        obj->unk_5a += (s32)(spin * (obj->unk_48.x + obj->unk_48.y));
        obj->unk_5c += (s32)(spin * (obj->unk_48.y + obj->unk_48.z));
        obj->unk_5e += (s32)(spin * (obj->unk_48.z + obj->unk_48.x));
        obj->unk_5a -= obj->unk_5a >> 5;
        obj->unk_5c -= obj->unk_5c >> 5;
        obj->unk_5e -= obj->unk_5e >> 5;
        obj->unk_54 += obj->unk_5a;
        obj->unk_56 += obj->unk_5c;
        obj->unk_58 += obj->unk_5e;
    } else {
        obj->unk_60 = obj->unk_3c;
        len = 1.0f - obj->unk_88;
        obj->unk_48.x *= len;
        obj->unk_48.y *= len;
        obj->unk_48.z *= len;
        len = length(&obj->unk_48);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        obj->unk_48.x += (f32)(0.1f * (len * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f - 0.5f)));
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        obj->unk_48.y += (f32)(0.1f * (len * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f - 0.5f)));
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        obj->unk_48.z += (f32)(0.1f * (len * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f - 0.5f)));
        obj->unk_48.y += -0.03f;
        obj->unk_3c.x += obj->unk_48.x;
        obj->unk_3c.y += obj->unk_48.y;
        obj->unk_3c.z += obj->unk_48.z;
        if (((obj->unk_8 >> 12) & 1) == 0) {
            lbl_8006DC6C(obj->unk_b8);
            set_translation(obj);
            fn_8006E250(&obj->unk_3c, &pos);
            fn_8006E2B0(&obj->unk_48, &vel);
            if (pos.y < -0.5f) {
                lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
                vel.y = -1.0f * vel.y + (f64)(vel.y * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f - 0.5));
                vel.z = 0.95f * vel.z;
            }
            lbl_8006E1B0(&pos, &obj->unk_3c);
            lbl_8006E1C0(&vel, &obj->unk_48);
        }
        obj->unk_88 += (f32)(0.03f * (obj->unk_8c - obj->unk_88));
        obj->unk_b4 *= 1.0f - 1.0f / (obj->unk_10 + 1);
    }
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_5D91C */

/* fzgx:begin fn_1_5DFA4 */
/* begin game/main_rel/camera_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAMERA_TYPES_H

// Types (and the externs that name them) of camera.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3f_5DFA4 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* end game/main_rel/camera_types.h */

/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* end game/main_rel/car_test_types.h */

/* game/vec3.h: inlined above */

static inline void extrapolate(Vec3 *out, Vec3 *prev, Vec3 *a) {
    f64 px, py, pz, ax, ay, az;
    px = 1.5 * prev->x;
    py = 1.5 * prev->y;
    pz = 1.5 * prev->z;
    ax = 0.5 * a->x;
    ay = 0.5 * a->y;
    az = 0.5 * a->z;
    out->x = px - ax;
    out->y = py - ay;
    out->z = pz - az;
}

#pragma opt_common_subs off

static inline f32 scale_len_sq(Vec3 *v) {
    f32 result = v->x * v->x;
    result += v->y * v->y;
    result += v->z * v->z;
    return result;
}

void fn_1_5DFA4(Fn5DFA4Effect *effect) {
    Fn5DFA4Draw draw;
    Fn5DFA4Point b;
    Fn5DFA4Point a;
    Fn5DFA4Point *bp;
    Vec3 prev;
    Vec3 mid;
    f32 red;
    f32 green;
    f32 blue;
    f32 dx;
    f32 dz;
    f32 dy;
    struct { f32 value; } len2;
    f32 alpha;
    f32 dist;
    f32 t;
    void *model;
    s32 timer;

    if (camera_forward_status() & 0x80000000) {
        return;
    }
    if (effect->model != NULL) {
        if (scale_len_sq(&effect->scale) < 0.1f) {
            len2.value = 0.1f;
        } else if (scale_len_sq(&effect->scale) > 0.3f) {
            len2.value = 0.3f;
        } else {
            len2.value = scale_len_sq(&effect->scale);
        }
        lbl_8006D9D8((CamEntry *)&effect->pos);
        mathutil_mtxA_rotate_y(effect->rot_y);
        mathutil_mtxA_rotate_x(effect->rot_x);
        mathutil_mtxA_rotate_z(effect->rot_z);
        timer = effect->timer;
        model = effect->model;
        alpha = 1.0f;
        if (timer < 12) {
            alpha *= 0.083333336f * timer;
        }
        memset(&draw, 0, sizeof(draw));
        lbl_8006DB74(draw.unk_8);
        red = 255.0f * alpha;
        green = 51.0f * alpha;
        blue = 0.0f;
        draw.color[0] = __OSf32tou8(red);
        draw.color[1] = __OSf32tou8(green);
        draw.color[2] = __OSf32tou8(blue);
        draw.color[3] = 0xFF;
        draw.scale = 0.70710677f * (2.0f * len2.value);
        fn_1_9F914(&draw, model);
    } else {
        lbl_8006DBAC((Vec3 *)lbl_801A66CC.unk_0);
        lbl_8006E1B0((Fn183D28Vec3 *)&effect->prev_pos, (Fn183D28Vec3 *)&prev);
        lbl_8006DCA4();
        lbl_8006E1B0((Fn183D28Vec3 *)&effect->pos, (Fn183D28Vec3 *)&a.pos);
        bp = &b;
        extrapolate(&b.pos, &prev, &a.pos);
        lbl_8006D758();
        dx = a.pos.x - b.pos.x;
        dy = a.pos.y;
        dy -= b.pos.y;
        dz = a.pos.z;
        dz -= b.pos.z;
        dx *= dx;
        dx += dy * dy;
        dx += dz * dz;
        dist = lbl_8006D0B4(dx);
        mid.x = 0.5f * ((dx = a.pos.x) + (dy = b.pos.y));
        mid.y = 0.5f * (a.pos.y + dy);
        mid.z = 0.5f * (a.pos.z + b.pos.z);
        if (fn_1_54E34(&mid, 0.5f * dist) != 0) {
            t = a.pos.z;
            a.color[0] = 255.0f * effect->color[0];
            a.color[1] = 255.0f * effect->color[1];
            a.color[2] = 255.0f * effect->color[2];
            a.color[3] = 255.0f * effect->alpha;
            b.color[0] = 88.0f * effect->color[0];
            b.color[1] = 88.0f * effect->color[1];
            b.color[2] = 88.0f * effect->color[2];
            b.color[3] = 255.0f * effect->alpha;
            if (t < -3.0) {
                t = 1.5f;
            } else if (t > 0.0) {
                t = 4.5f;
            } else {
                t = 1.5 + (3.0 + t);
            }
            if ((effect->flags >> 12) & 1) {
                t *= 2.0f;
            }
            fn_1_57714(6.0f * t);
            fn_1_57720(1, 1, 1, 0);
            fn_1_579A0(&a, bp);
        }
    }
    return;
}
#undef GAME_MAIN_REL_CAMERA_TYPES_H
#undef GAME_VEC3_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#pragma opt_common_subs reset
/* fzgx:end fn_1_5DFA4 */

/* fzgx:begin fn_1_5E3C4 */
void fn_1_5E3C4(struct fn_1_5E3C4_Arg0 *arg0) {
    if (arg0->unk_B2 == 1) {
        if ((s32)arg0->unk_10 == 0) {
            lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
            arg0->unk_10 = (s32)(60.0f * (0.4f + (f32)(0.25f * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f))));
        }
    } else {
        if ((s32)arg0->unk_10 == 0) {
            lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
            arg0->unk_10 = (s32)(60.0f * (0.08f + (f32)(0.25f * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f))));
        }
    }
}
/* fzgx:end fn_1_5E3C4 */

/* fzgx:begin fn_1_5E4D8 */
/* begin game/main_rel/car_test_types.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TYPES_H

#define GAME_VEC3_H

#define S(o) (*(s16 *)((u8 *)arg0+(o)))

#define H(o) (*(u16 *)((u8 *)arg0+(o)))

#define I(o) (*(s32 *)((u8 *)arg0+(o)))

#define F(o) (*(f32 *)((u8 *)arg0+(o)))

#define RF(p,o) (*(f32 *)((u8 *)(p)+(o)))

#define RS(p,o) (*(s16 *)((u8 *)(p)+(o)))

#define RB(p,o) (*(s8 *)((u8 *)(p)+(o)))

static inline Obj_1_bss_6C84C_Target *find_effect(Obj_1_bss_6C84C_Target *p, s32 count, s32 key) {
    for (; count != 0; count--, p++) {
        if (RB(p,0) && p->unk_4 == key) break;
    }
    if (count == 0) p = 0;
    return p;
}

void fn_1_5E4D8(void *arg0) {
Obj_1_bss_6C84C_Target *obj;
s32 active=0;
s32 key;
u8 *p;
s32 count;
s32 j;
struct {u32 a[12];} matrix;
Fn183D28Vec3 offset;
Triple pos;
Fn183D28Vec3 rel;
f32 z,y,x,t,f;
f32 dx,dz,dy;
void *car=(void *)I(0x38);
if(H(0xb2)==1 && *(u16 *)((u8 *)car+0x214)!=0) {active=1; I(0x10)++;}
fn_1_8636C(S(0x18),&matrix);
fn_1_862D4(S(0x18),&pos);
lbl_8006DC6C(&matrix);
if(H(0xb2)==1 && active) {
key=S(0x58);
find_effect(*(Obj_1_bss_6C84C_Target **)&lbl_1_bss_6C848,190,key);
obj=find_effect(lbl_1_bss_6C84C,200,key);
if(obj) {
lbl_8006DC6C(&matrix);
x=RF(obj,0x3c); y=RF(obj,0x40); z=RF(obj,0x44);
mtx_set_translate((void *)LC_BASE, x, y, z);
f=1.2f;
switch(I(0x14)) {
case 0: {Fn183D28Vec3 v={1.1f,0.0f,0.9f}; ((f32 *)&v)[1]=-f; rel=v; break;}
case 1: {Fn183D28Vec3 v={-1.1f,0.0f,0.9f}; ((f32 *)&v)[1]=-f; rel=v; break;}
case 2: {Fn183D28Vec3 v={0.0f,0.0f,-0.7f}; ((f32 *)&v)[1]=-f; rel=v; break;}
}
mathutil_mtxA_rotate_y(RS(obj,0x56)); mathutil_mtxA_rotate_x(RS(obj,0x54)); mathutil_mtxA_rotate_z(RS(obj,0x58));
lbl_8006E1B0(&rel,(Fn183D28Vec3 *)((u8 *)arg0+0x88));
}}
/* angular velocity decay (0x5a, 0x5c): a two-element loop keeps 0.98f and the
   int-to-float bias in registers across both stores */
if(!active) {for(count=0;count<2;count++) ((s16 *)((u8 *)arg0+0x5a))[count]*=0.98f;}
lbl_8006DC6C(&matrix);
{ f32 pz,py,px;
px=((f32 *)&pos)[0]; py=((f32 *)&pos)[1];pz=((f32 *)&pos)[2];
mtx_set_translate((void *)LC_BASE, px, py, pz);
}
f=0.01f;
S(0x54)+=S(0x5a);S(0x56)+=S(0x5c);
F(0x28)=F(0x28)+(f32)(f*(F(0x2c)-F(0x28)));
mathutil_mtxA_rotate_y(S(0x56)); mathutil_mtxA_rotate_x(S(0x54));
{Fn183D28Vec3 v={0.0f,0.0f,0.0f};((f32 *)&v)[2]=-F(0x28);offset=v;}
lbl_8006E1B0(&offset,(Fn183D28Vec3 *)((u8 *)arg0+0x3c));
if(!active) {F(0x94)+=F(0xa0);F(0x98)+=F(0xa4);F(0x9c)+=F(0xa8);}
F(0xb4)=0.5f*(I(0x10)<0.0f ? 0.0f : I(0x10)>15.0f ? 15.0f : I(0x10));
if(I(0x10)<20 && !active) {
x=F(0x1c);
f=1.0f-(1.0f+(f32)(-0.05f*I(0x10)));
F(0x1c)=x*f;F(0x20)*=f;F(0x24)*=f;
}
if(!active) {
dx=((f32 *)&pos)[0]-F(0x88); dy=((f32 *)&pos)[1]; dy=dy-F(0x8c); dz=((f32 *)&pos)[2]; dz=dz-F(0x90);
dx=dx*dx;
dx=dy*dy+dx;
dx=dz*dz+dx;
t=lbl_8006D0B4(dx);
if(t>50.0f) *(u8 *)arg0=3;
else if(t>10.0f) {x=F(0x1c);f=1.0f-(f32)(0.025f*(t-10.0f));F(0x1c)=x*f;F(0x20)*=f;F(0x24)*=f;}
}
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef GAME_VEC3_H
#undef S
#undef H
#undef I
#undef F
#undef RF
#undef RS
#undef RB
/* fzgx:end fn_1_5E4D8 */

/* fzgx:begin fn_1_5EB08 */
void fn_1_5EB08(FnObj *object) {
    FnLocal local;
    FnNode *node;
    FnNode *allocated;

    fn_1_862D4(object->value, &local);
    lbl_8006DCA4();
    if (fn_1_54E34(&object->field3c, 4.0f)) {
        node = fn_1_5448C(&local);
        allocated = fn_1_548AC(0xc);
        if (allocated != 0) {
            allocated->callback = (void *)fn_1_5EB98;
            allocated->object = object;
            fn_1_5489C( (void **)(node), (void **)(allocated));
        }
    }
}
/* fzgx:end fn_1_5EB08 */

/* fzgx:begin fn_1_5EB98 */
static Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey lbl_1_data_1D7A8[2] = {{2, 0.0f, 0.0f, 0.0f, 0.0f}, {2, 1.0f, 0.0f, 0.0f, 0.0f}};
static Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey lbl_1_data_1D7D0[2] = {{2, 0.0f, 0.0f, 0.0f, 0.0f}, {2, 1.0f, 0.0f, 0.0f, 0.0f}};
static Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey lbl_1_data_1D7F8[2] = {{2, 0.0f, 0.0f, 0.0f, 0.0f}, {2, 1.0f, 0.0f, 0.0f, 0.0f}};
#define GAME_MAIN_REL_CAMERA_TYPES_H

/* end game/main_rel/camera_types.h */

/* retail .data objects of this TU, in retail order (defined before the pool
 * primers so the .data section base is created before the .rodata one) */

static inline f32 Fn5EB98Length(const f32 *v) { f32 z=v[2], x=v[0], y=v[1]; f32 len=x*x; len=y*y+len; len=z*z+len; return lbl_8006D0B4(len); }

/* LCG step; the updated seed is read back from the global (forwarded by the
 * compiler): a named helper local here changes the loop's register numbering */

static inline f32 Fn5EB98Rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    return ((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f;
}

void fn_1_5EB98(struct fn_1_5EB98_Arg0 *arg0, u32 arg1, u32 arg2) {
u32 v0;
s32 v44;
Fn5EB98Vertex *vout;
u32 v6;
f32 colorR,colorG,colorB;
f32 v4,v3,v5,v14,v19,v27,v28;
f64 v26,v25,v24;
f64 v31;
f32 v33,v40,v41,v42,v50,v49,v48,v43,v55,v60,v61,v20,v62,v63;
f32 t2,t4,t5,t6,t33,t41,lz;
u32 v52;
u32 v54,v76;
Fn5EB98Vertex verts[16];
struct { u32 a[12]; } loc_DC;
struct { u32 a[12]; } loc_AC;
struct { u8 a[64]; } loc_6C;
struct { u8 a[24]; } loc_54;
Fn5EB98Vec loc_48;
Fn5EB98Vec loc_3C, loc_30;
f32 loc_24[3];
Fn5EB98Color loc_20;
Fn5EB98Vec origin;
u32 v30,v29,v23;
v0 = arg0->unk_8;

fn_1_8636C((*(s16 *)((v0)+(24))) , &loc_DC);
fn_1_867CC((*(s16 *)((v0)+(24))) , &loc_48);
if ((*(u16 *)((v0)+(178))) ==1) loc_3C = *(Fn5EB98Vec *)(v0+136);
else loc_3C = loc_48;
loc_30 = *(Fn5EB98Vec *)(v0+60);
v3 = loc_30.x-loc_3C.x;
v4 = loc_30.y-loc_3C.y;
v5 = loc_30.z-loc_3C.z;
loc_24[0]=v3; loc_24[1]=v4; loc_24[2]=v5;
t2=v3*v3; t2=v4*v4+t2; t2=v5*v5+t2; t2=lbl_8006D0B4(t2);
v14=((*(f32 *)((v0)+(180))) *(0.45f*(*(f32 *)((v0)+(180))) ))*
(0.2f+(f32)(0.8f*Fn5EB98Rand() ));
if(v14>1.0f) {
colorR=255.0f*(*(f32 *)((v0)+(28))) ;
colorG=255.0f*(*(f32 *)((v0)+(32))) ;
colorB=255.0f*(*(f32 *)((v0)+(36))) ;
} else {
colorR=255.0f*((*(f32 *)((v0)+(28))) *v14);
colorG=255.0f*((*(f32 *)((v0)+(32))) *v14);
colorB=255.0f*((*(f32 *)((v0)+(36))) *v14);
}
loc_20.r=__OSf32tou8(colorR); loc_20.g=__OSf32tou8(colorG); loc_20.b=__OSf32tou8(colorB); loc_20.a=255;
v19=-2.0f*(*(f32 *)((u8 *)(v0)+(180))) ;
v20=1.0f+(*(f32 *)((u8 *)(v0)+(180))) ;
loc_24[0]=(*(f32 *)((v0)+(148))) -loc_3C.x;
loc_24[1]=(*(f32 *)((v0)+(152))) -loc_3C.y;
loc_24[2]=(*(f32 *)((v0)+(156))) -loc_3C.z;
lbl_8006D668(loc_24);
v24=loc_24[0]*v20; v25=loc_24[1]*v20; v26=loc_24[2]*v20;
loc_24[0]=v24; loc_24[1]=v25; loc_24[2]=v26;
v23=(u32)(((u8 *)lbl_1_data_1D7A8));
v29=(u32)(((u8 *)lbl_1_data_1D7D0));
v30=(u32)(((u8 *)lbl_1_data_1D7F8));
(*(f32 *)((v23)+(8))) =loc_3C.x; (*(f32 *)((v23)+(12))) =v24; (*(f32 *)((v23)+(16))) =loc_24[0]; (*(f32 *)((v23)+(28))) =loc_30.x;
v33=(*(f32 *)((v0)+(112))) *v19;
(*(f32 *)((v29)+(8))) =loc_3C.y; (*(f32 *)((v29)+(12))) =v25;
(*(f32 *)((v23)+(32))) =v33; (*(f32 *)((v23)+(36))) =v33;
(*(f32 *)((v29)+(16))) =loc_24[1]; (*(f32 *)((v29)+(28))) =loc_30.y;
v40=(*(f32 *)((v0)+(116))) *v19;
(*(f32 *)((v30)+(8))) =loc_3C.z; (*(f32 *)((v30)+(12))) =v26;
(*(f32 *)((v29)+(32))) =v40; (*(f32 *)((v29)+(36))) =v40;
(*(f32 *)((v30)+(16))) =loc_24[2]; (*(f32 *)((v30)+(28))) =loc_30.z;
v41=(*(f32 *)((v0)+(120))) *v19;
(*(f32 *)((v30)+(32))) =v41; (*(f32 *)((v30)+(36))) =v41;
v31=0.1*t2;
verts[0].pos=loc_3C;
verts[0].color=loc_20;
vout=&verts[1];
for(v44=14; v44>0; v44--) {
v42=1.0f - (f32)((v44+1) / 16.0f);
t4=fn_1_9E14C(2,(Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *)(((u8 *)lbl_1_data_1D7A8)),v42);
t5=fn_1_9E14C(2,(Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *)(((u8 *)lbl_1_data_1D7D0)),v42);
t6=fn_1_9E14C(2,(Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *)(((u8 *)lbl_1_data_1D7F8)),v42);
if((*(u16 *)((v0)+(178))) ==1) v43=v31;
else v43=0.25f;
v48 = Fn5EB98Rand();
v48 -= 0.5f;
v49=Fn5EB98Rand() -0.5f;
v50=Fn5EB98Rand() -0.5f;
vout->pos.x=t4+(f32)(v43*v48);
vout->pos.y=t5+(f32)(v43*v49);
vout->pos.z=t6+(f32)(v43*v50);
vout->color=loc_20; vout++;
}
vout->pos=loc_30; vout->color=loc_20;
if((s32)(((*(u32 *)((v0)+(16))) <<1)+3)>(*(s16 *)((u8 *)(v0)+(172))) ) fn_1_57714((*(s16 *)((u8 *)(v0)+(172))) );
else fn_1_57714((((*(u32 *)((v0)+(16))) <<1)+3));
fn_1_57720(1,1,1,0);
lbl_8006DCA4();
fn_1_57A70(16,verts);
v52=lbl_1_data_1D628;
v52*=0x41C64E6D;
v52+=12345;
v60=((v52>>16)&0x7FFF)/32767.0f;
v54=(u32)((void **)(lbl_1_bss_38458->unk_8))[40];
v55=0.25f*(*(f32 *)((v0)+(180))) ;
*(u32 *)&lbl_1_data_1D628 =v52; /* fzgx-allow: S2 preserve the generator update */
v61=1.0f+v55;
v62=0.125f+(f32)(0.5f*v55);
v63=255.0f*(v62*(1.0f+v60));
fn_80074788(0); fn_80072864(0);
fn_800745A4(0,1,4,60,0,125);
fn_800734A8(0,0,0,255); fn_80072AB0(0,0,0);
fn_800735C8(0,12); fn_80073620(0,28); fn_80073C6C(0);
fn_80072C24(0,15,15,15,14); fn_80072D64(0,0,0,0,1,0);
fn_80072CC4(0,7,6,4,7); fn_80072E20(0,0,0,0,1,0);
fn_80073678(1); fn_80074660(1); fn_80074918(1,3,0);
fn_800720B0(0); fn_800728A8(1,4,1,0); fn_80073778((void *)(*(u32 *)((v54)+(36))) ,0);
memset(&loc_54,0,24);
colorR=v63*(*(f32 *)((v0)+(28))) ; colorG=v63*(*(f32 *)((v0)+(32))) ; colorB=v63*(*(f32 *)((v0)+(36))) ;
loc_54.a[20]=__OSf32tou8(colorR); loc_54.a[21]=__OSf32tou8(colorG); loc_54.a[22]=__OSf32tou8(colorB); loc_54.a[23]=255;
lbl_8006D9D8((CamEntry *)&loc_30); lbl_8006D7B0();
if(fn_1_54E34((void *)(v54+8),v61)!=0) {
psvec_set(loc_24,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0xC));
t33=Fn5EB98Length(loc_24);
if(t33>0.1f+v61) {
lbl_8006DB74(&loc_AC); lbl_8006D848((t33-v61)/t33); lbl_8006DFC4(&loc_AC);
}
*(Fn5EB98Vec *)&loc_54=*(Fn5EB98Vec *)(v54+8);
(*(f32 *)((u8 *)(&loc_54)+(12))) =0.7071067690849304f*v61; (*(u16 *)((u8 *)(&loc_54)+(16))) =0;
fn_1_9EA94((struct Sig_fn_1_9EA94_fn_1_9EA94_Arg0 *)&loc_54);
}
lbl_8006D9D8((CamEntry *)&loc_3C); lbl_8006D7B0();
if(fn_1_54E34((void *)(v54+8),v61)!=0) {
psvec_set(loc_24,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0xC));
t41=Fn5EB98Length(loc_24);
if(t41>0.1f+v61) {
lbl_8006DB74(&loc_AC); lbl_8006D848((t41-v61)/t41); lbl_8006DFC4(&loc_AC);
}
*(Fn5EB98Vec *)&loc_54=*(Fn5EB98Vec *)(v54+8);
(*(f32 *)((u8 *)(&loc_54)+(12))) =0.7071067690849304f*v61; (*(u16 *)((u8 *)(&loc_54)+(16))) =0;
fn_1_9EA94((struct Sig_fn_1_9EA94_fn_1_9EA94_Arg0 *)&loc_54);
}
if((*(u16 *)((v0)+(178))) ==1) {
v76=(*(u32 *)((lbl_1_bss_38458->unk_8)+(288))) ;
lbl_8006D9D8((CamEntry *)&loc_48);
lbl_8006D95C((*(s16 *)((v0)+(86))) ); mathutil_mtxA_rotate_x((*(s16 *)((v0)+(84))) );
memset(&loc_6C,0,64); lbl_8006DB74(&loc_6C.a[8]);
v27=2.5f*(*(f32 *)((v0)+(40))) ;
v28=0.7071067690849304f*v27;
(*(f32 *)((&loc_6C)+(0))) =v28;
lbl_1_data_1D628 =lbl_1_data_1D628 *0x41C64E6D+12345;
loc_6C.a[60]=(255.0f*(*(f32 *)((v0)+(28))) );
loc_6C.a[61]=(255.0f*(*(f32 *)((v0)+(32))) );
loc_6C.a[62]=(255.0f*(*(f32 *)((v0)+(36))) );
loc_6C.a[63]=255; (*(f32 *)((u8 *)(&loc_6C)+(4))) =v28;
fn_1_9F914(&loc_6C,(void *)v76);
}
}
#undef GAME_MAIN_REL_CAMERA_TYPES_H
/* fzgx:end fn_1_5EB98 */

/* fzgx:begin fn_1_5F5C4 */
// fn_1_5F5C4: empty in retail (single blr).

void fn_1_5F5C4(void) {
}
/* fzgx:end fn_1_5F5C4 */

/* fzgx:begin fn_1_5F5C8 */
void fn_1_5F5C8(struct fn_1_5F5C8_Arg0 *arg0) {
    if ((s32)arg0->unk_10 == 0) {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
        arg0->unk_10 = (s32)(60.0f * (0.3f + (f32)(0.25f * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f))));
    }
}
/* fzgx:end fn_1_5F5C8 */

/* fzgx:begin fn_1_5F654 */
/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* end game/main_rel/car_test_types.h */

/* Sets the translation column of the locked-cache matrix A. */

void fn_1_5F654(fn_1_5F654_Effect *effect) {
    f32 mtx[12];
    Fn183D28Vec3 pos;
    Fn183D28Vec3 tail;
    Fn183D28Vec3 eye;
    fn_1_5F654_Owner *owner;
    f32 t;

    if (((fn_1_86514(effect->id) >> 27) & 1) && ((effect->flags >> 18) & 1)) {
        effect->frame++;
    } else {
        effect->rot_vel_x *= 0.98f;
        effect->rot_vel_y *= 0.98f;
        effect->flags &= ~0x40000;
    }

    owner = fn_1_86254(effect->id);
    fn_1_862D4(effect->id, &pos);
    fn_1_8636C(effect->id, mtx);
    lbl_8006DC6C(mtx);
    {
        {
        f32 z, y, x;
        x = pos.x;
        y = pos.y;
        z = pos.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    }

    if ((s8)owner->camera != -1 && (s32)fn_1_6EC0(owner->camera) != 0 &&
        camera_get_entry_field_0xa4(owner->camera) == 0) {
        Fn183D28Vec3 offset = {0.0f, 0.0f, 0.0f};

        offset.z = -3.0f;
        eye = offset;
        lbl_8006E1B0(&eye, &eye);
        {
            {
        f32 z, y, x;
        x = eye.x;
        y = eye.y;
        z = eye.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
        }
    }

    effect->rot_x += effect->rot_vel_x;
    effect->rot_y += effect->rot_vel_y;
    mathutil_mtxA_rotate_y(effect->rot_y);
    mathutil_mtxA_rotate_x(effect->rot_x);
    {
        Fn183D28Vec3 offset = {0.0f, 0.0f, 0.0f};

        offset.z = 0.5 * -effect->speed;
        tail = offset;
        lbl_8006E1B0(&tail, &effect->pos);
    }

    effect->alpha = 0.5f * effect->frame;
    {
        u32 seed = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;

        lbl_1_data_1D628 = seed;
        t = 0.8f + (f32)(0.2f * (((seed >> 16) & 0x7FFF) / 32767.0f));
    }
    effect->color[0] = (255.0f * (0.5f * (1.0f + t))) / 255.0f;
    effect->color[1] = (85.0f * t) / 255.0f;
    effect->color[2] = 0.0f;
    if (lbl_1_data_2A7E0.unk_0 == 6) {
        effect->color[0] *= 0.2f;
        effect->color[1] *= 0.2f;
        effect->color[2] *= 0.2f;
    }
    if (effect->frame < 20) {
        f32 fade;
        effect->color[0] *= (fade = 1.0f - (1.0f + (f32)(-0.05f * effect->frame)));
        effect->color[1] *= fade;
        effect->color[2] *= fade;
    }
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_5F654 */

/* fzgx:begin fn_1_5F9B8 */
void fn_1_5F9B8(fn_1_5F9B8_Effect *effect) {
    u8 camera[12];
    fn_1_5F9B8_Vec pos;
    u8 data[64];
    u8 mtx[0x30];
    fn_1_5F9B8_Light light;
    fn_1_5F9B8_Vec axis;
    fn_1_5F9B8_Model *glow;
    void *model;
    s32 players;
    void *player;
    f32 red;
    f32 green;
    f32 blue;
    f32 radius;
    f32 brightness;
    f32 size;
    f32 color_scale;
    f32 base;
    f32 half;
    f32 dist;

    fn_1_867CC(effect->id, camera);
    players = *(s16 *)((u8 *)fn_1_868C0(effect->id) + 0x3ba);
    player = fn_1_86254(effect->id);
    if (players >= 3 && *(s8 *)((u8 *)player + 0x475) == -1) {
        return;
    }

    pos = effect->pos;
    model = ((fn_1_5F9B8_Assets *)lbl_1_bss_38458->unk_8)->model;
    lbl_8006D9D8(camera);
    lbl_8006D95C(effect->rot_y);
    mathutil_mtxA_rotate_x(effect->rot_x);
    memset(data, 0, 64);
    lbl_8006DB74(data + 8);
    size = 0.70710677f * effect->size;
    *(f32 *)(data + 0) = size;
    color_scale = 255.0f;
    data[60] = (color_scale * effect->red);
    data[61] = (color_scale * effect->green);
    data[62] = (color_scale * effect->blue);
    data[63] = 0xff;
    *(f32 *)(data + 4) = size;
    fn_1_9F914(data, model);

    glow = ((fn_1_5F9B8_Assets *)lbl_1_bss_38458->unk_8)->glow;
    base = 0.1f * effect->scale;
    radius = 1.0f + base;
    half = 0.5f * base;
    brightness = 255.0f * ((0.125f + half) * (1.0f + (((lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039) >> 16) & 0x7fff) / 32767.0f));

    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    fn_80073778(glow->tex, 0);

    memset(&light, 0, sizeof(light));
    red = brightness * effect->red;
    green = brightness * effect->green;
    blue = brightness * effect->blue;
    light.color[0] = __OSf32tou8(red);
    light.color[1] = __OSf32tou8(green);
    light.color[2] = __OSf32tou8(blue);
    light.color[3] = 0xff;
    lbl_8006D9D8(&pos);
    lbl_8006D7B0();
    if (fn_1_54E34(&glow->pos, radius) != 0) {
        /* translation column of the locked-cache matrix */
        psvec_set(&axis, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
        /* squared length; the asm block above blocks fp contraction, so fuse explicitly */
        dist = axis.x * axis.x;
        dist = __fmadds(axis.y, axis.y, dist);
        dist = lbl_8006D0B4(__fmadds(axis.z, axis.z, dist));
        if (dist > 0.1f + radius) {
            lbl_8006DB74(mtx);
            lbl_8006D848((dist - radius) / dist);
            lbl_8006DFC4(mtx);
        }
        light.pos = glow->pos;
        light.radius = 0.70710677f * radius;
        light.flags = 0;
        fn_1_9EA94(&light);
    }
}
/* fzgx:end fn_1_5F9B8 */

/* fzgx:begin fn_1_5FE24 */
// fn_1_5FE24: empty in retail (single blr).

void fn_1_5FE24(void) {
}
/* fzgx:end fn_1_5FE24 */

/* fzgx:begin fn_1_5FE28 */
// fn_1_5FE28: empty in retail (single blr).

void fn_1_5FE28(void) {
}
/* fzgx:end fn_1_5FE28 */

/* fzgx:begin fn_1_5FE2C */
// fn_1_5FE2C: empty in retail (single blr).

void fn_1_5FE2C(void) {
}
/* fzgx:end fn_1_5FE2C */

/* fzgx:begin fn_1_5FE30 */
void fn_1_5FE30(fn_1_5FE30_FZeroObject *object) {
    u8 result[8];
    void *callback;
    FZeroEvent *event;

    fn_1_862D4(object->value, result);
    lbl_8006DCA4();
    if (fn_1_54E34(object->field3C, object->rate) != 0) {
        callback = fn_1_5448C(result);
        event = (FZeroEvent *)fn_1_548AC(12);
        if (event != 0) {
            event->callback = (void *)fn_1_5FEBC;
            event->owner = object;
            fn_1_5489C(callback, event);
        }
    }
}
/* fzgx:end fn_1_5FE30 */

/* fzgx:begin fn_1_5FEBC */
void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object) {
    u8 result[12];
    u8 data[64];
    fn_1_5FEBC_EffectData *effect;
    void *owner;
    f32 color_scale;
    f32 size;

    effect = object->data;
    fn_1_867CC(effect->value18, result);
    owner = effect->field34;
    lbl_8006D9D8(result);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_y(effect->value56);
    mathutil_mtxA_rotate_x(effect->value54);
    memset(data, 0, 64);
    lbl_8006DB74(data + 8);
    size = 0.70710677f;
    size = size * effect->value28;
    *(f32 *)(data + 0) = size;
    color_scale = 255.0f;
    data[60] = (color_scale * effect->value1C);
    data[61] = (color_scale * effect->value20);
    data[62] = (color_scale * effect->value24);
    data[63] = 0xff;
    *(f32 *)(data + 4) = size;
    fn_1_9F914(data, owner);
}
/* fzgx:end fn_1_5FEBC */

/* fzgx:begin fn_1_5FFAC */
// fn_1_5FFAC: empty in retail (single blr).

void fn_1_5FFAC(void) {
}
/* fzgx:end fn_1_5FFAC */

/* fzgx:begin fn_1_5FFB0 */
static inline u16 urand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

#pragma opt_propagation off

void fn_1_5FFB0(struct fn_1_5FFB0_p *p) {
    lbl_1_bss_6C86C = 30;
    lbl_1_bss_6C870 = 8;
    p->unk_14 = (lbl_1_bss_6C870 * (0.8f + (f32)(0.5f * (urand() / 32767.0f))));
    p->unk_10 = p->unk_14 + (f32)(lbl_1_bss_6C86C * (0.8f + (f32)(0.2f * (urand() / 32767.0f))));
    p->unk_38 = fn_1_45D0(lbl_801A6410, 0xA0, "effect.c", 0x1254);
    p->unk_54 = urand() % 4;
}

#pragma opt_propagation reset
/* fzgx:end fn_1_5FFB0 */

/* fzgx:begin fn_1_60170 */
// Submit the effect data when this object has an associated field.

void fn_1_60170(fn_1_60170_FZeroObject *object) {
    if (object->field38 != 0) {
        fn_1_46B4((u32)lbl_801A6410, (u32)(object->field38), "effect.c", 0x1261);
    }
}
/* fzgx:end fn_1_60170 */

/* fzgx:begin fn_1_601B4 */
void fn_1_601B4(EffectState *effect) {
    f32 factor;

    effect->unk_14--;
    if (effect->unk_14 > 0) {
        factor = 0.98f;
        effect->unk_48 *= factor;
        effect->unk_4c *= factor;
        effect->unk_50 *= factor;
        effect->unk_3c += effect->unk_48;
        effect->unk_40 += effect->unk_4c;
        effect->unk_44 += effect->unk_50;
        effect->unk_b4 = 2.0f;
    } else {
        s32 numerator = effect->unk_10;
        s32 denominator = lbl_1_bss_6C86C;

        effect->unk_b4 = (f32)numerator / denominator;
    }
}
/* fzgx:end fn_1_601B4 */

/* fzgx:begin fn_1_6028C */
#define GAME_MAIN_REL_CAMERA_TYPES_H

#define GAME_VEC3_H

/* end game/main_rel/camera_types.h */

/* view of lbl_1_data_1C698 (the TU's .data block) */

static inline void beam_vec_sub(BeamVec *out, BeamVec *a, BeamVec *b)
{
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

static inline f32 beam_vec_length(BeamVec *v)
{
    const f32 *p = (const f32 *)v;
    f32 y = p[1];
    f32 z = p[2];
    f32 len;
{
    f32 x = p[0];
    len = x * x;
}
    len += y * y;
    len += z * z;
    return lbl_8006D0B4(len);
}

/* orient the current matrix along the segment from start to end; returns its length */

static inline f32 beam_orient(BeamEffect *effect, BeamVec *startArg, BeamVec *endArg)
{
    f32 fzgx_value;
    BeamVec mid;
    BeamVec start;
    BeamVec end;
    s16 rotZ;
    s16 rotX;
    s16 rotY;
    f32 len;
    f32 dy;
    f32 dz;
    f32 fzgx_live;
    f32 sumZ;
    f32 sumX;
    f32 endY;
    f32 startY;
    f32 endZ;
    f32 endX;
    f32 startX;
    f32 startZ;

    end = *endArg;
    start = *startArg;
    lbl_8006DCA4();
    fn_8006F3E4(&rotX, &rotY, &rotZ);
    endX = end.x;
    startX = start.x;
    endY = end.y;
    startY = start.y;
    endZ = end.z;
    startZ = start.z;
    sumX = endX;
    sumX += startX;
    fzgx_live = endX - startX;
    dy = endY - startY;
    dz = endZ - startZ;
    startY = endY + startY;
    sumZ = endZ + startZ;
    len = fzgx_live * fzgx_live;
    len += dy * dy;
    len += dz * dz;
    fzgx_live = 0.5f;
    fzgx_value = fzgx_live * sumX;
    mid.x = fzgx_value;
    mid.y = fzgx_live * startY;
    mid.z = fzgx_live * sumZ;
    len = lbl_8006D0B4(len);
    lbl_8006D9D8(&mid);
    mathutil_mtxA_rotate_y((s16)-rotX);
    mathutil_mtxA_rotate_z((s16)((s32)(4096.0f * effect->angle) - 0x1000));
    return len;
}

static inline void *beam_model(const char *name)
{
    void **res = fn_1_9CE1C(name, 1);
    if (res == NULL) {
        fn_1_A8E78("nodeNULL");
    }
    return *res;
}

#pragma opt_dead_assignments off

#pragma opt_lifetimes off

void fn_1_6028C(BeamEffect *effect)
{
    BeamVec end;
    BeamVec start;
    BeamVec delta;
    const char *name;
    void *model;
    f32 scale;
    f32 alpha;

    end = effect->end;
    start = effect->start;
    end.x = start.x;
    end.z = start.z;
    beam_vec_sub(&delta, &start, &end);
    beam_vec_length(&delta);

    if (effect->timer > 0) {
        if (!(effect->timer & 1)) {
            u32 seed = lbl_1_data_1D628 * 1103515245 + 12345;
            lbl_1_data_1D628 = seed;
            effect->variant = (s32)((seed >> 16) & 0x7FFF) % 4;
        }
        switch (effect->variant) {
        case 0:
            name = "LIG_EFF_THUNDER_E1";
            break;
        case 1:
            name = "LIG_EFF_THUNDER_E2";
            break;
        case 2:
            name = "LIG_EFF_THUNDER_E3";
            break;
        default:
            name = "LIG_EFF_THUNDER_E4";
            break;
        }
    } else {
        switch (effect->variant) {
        case 0:
            name = "LIG_EFF_THUNDER_E1";
            break;
        case 1:
            name = "LIG_EFF_THUNDER_E2";
            break;
        case 2:
            name = "LIG_EFF_THUNDER_E3";
            break;
        default:
            name = "LIG_EFF_THUNDER_E4";
            break;
        }
    }
    model = beam_model(name);
    fn_80073778(*(void **)((u8 *)model + 0x24), 0);
    scale = beam_orient(effect, &start, &end);
    fn_1_56000(1, 3, 0);
    scale = 0.01 * (1.86f * (effect->scale * scale));
    lbl_8006E14C(scale);
    fn_1_55FC4(scale);
    fn_80072558();
    alpha = 0.5f * effect->alpha;
    if (alpha > 1.0f) {
        fn_1_55FF0(1.0f);
    } else {
        fn_1_55FF0(alpha);
    }
    fn_1_55210(model);
    fn_1_56000(1, 3, 1);

    if (effect->alt != 0) {
        name = "LIG_EFF_THUNDER_C3";
    } else {
        name = "LIG_EFF_THUNDER_C2";
    }
    model = beam_model(name);
    fn_80073778(*(void **)((u8 *)model + 0x24), 0);
    beam_orient(effect, &start, &end);
    fn_1_56000(1, 3, 0);
    lbl_8006E14C(effect->scale);
    fn_1_55FC4(effect->scale);
    fn_80072558();
    alpha = 0.5f * effect->alpha;
    if (alpha > 1.0f) {
        fn_1_55FF0(1.0f);
    } else {
        fn_1_55FF0(alpha);
    }
    fn_1_55210(model);
    fn_1_56000(1, 3, 1);
}

#pragma opt_dead_assignments reset
#undef GAME_MAIN_REL_CAMERA_TYPES_H
#undef GAME_VEC3_H
#pragma opt_lifetimes reset
/* fzgx:end fn_1_6028C */

/* fzgx:begin fn_1_60734 */
void fn_1_60734(Fn60734 *effect) {
    u32 value;

    if (effect->unk_10 == 0) {
        value = lbl_1_data_1D628 * 1103515245 + 12345;
        lbl_1_data_1D628 = value;
        effect->unk_10 = (210.0 + 60.0f * (((value >> 16) & 0x7fff) / 32767.0f));
    }

    effect->unk_0e = 0;
    if (0.0f == effect->unk_28) {
        f64 prod;
        value = lbl_1_data_1D628 * 1103515245 + 12345;
        lbl_1_data_1D628 = value;
        prod = 0.02 * (((value >> 16) & 0x7fff) / 32767.0f);
        effect->unk_28 = (prod + 0.02);
    }

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_54 = (value >> 16) & 0x7fff;

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_56 = (value >> 16) & 0x7fff;

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_58 = (value >> 16) & 0x7fff;
}
/* fzgx:end fn_1_60734 */

/* fzgx:begin fn_1_60880 */
static inline f64 clampd(f64 x, f64 lo, f64 hi) { return (x < lo) ? lo : ((x > hi) ? hi : x); }

#pragma opt_dead_assignments off

void fn_1_60880(Avl60880Obj *obj) {
    Obj_1_data_1CC74_Target *grav = lbl_1_data_1CC74;
    Avl60880Vec up;
    f64 drag;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 dot;
    struct { f32 value; } scale;
    f32 lenSq;
    f32 len;
    f32 k;

    if (++lbl_1_bss_6C85C > 200) {
        obj->state = 3;
    }
    if (fn_1_66B8(&obj->pos, 4.0f) == 0) {
        obj->state = 3;
    }

    obj->vel.x = obj->vel.x + (f64)(0.003 * grav->unk_0);
    obj->vel.y = obj->vel.y + (f64)(0.003 * grav->unk_4);
    obj->vel.z = obj->vel.z + (f64)(0.003 * grav->unk_8);

    lbl_8006D8D8(obj->rotY);
    mathutil_mtxA_rotate_x(obj->rotX);
    mathutil_mtxA_rotate_z(obj->rotZ);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    lbl_8006E1C0(&up, &up);

    vx = obj->vel.x;
    lenSq = vx * vx;
    vy = obj->vel.y;
    lenSq += vy * vy;
    vz = obj->vel.z;
    lenSq += vz * vz;
    len = lbl_8006D0B4(lenSq);
    drag = clampd((f64)(0.141 * len) - 0.7f, -0.7f, -0.03f);

    dot = up.x * obj->vel.x;
    dot += (up.y) * obj->vel.y;
    vz = up.z;
    dot += vz * obj->vel.z;
    scale.value = (f32)drag * dot;
    obj->vel.x += (f32)(up.x * scale.value);
    obj->vel.y += (f32)((up.y) * scale.value);
    obj->vel.z += (f32)(up.z * scale.value);

    obj->vel.x *= 0.96f;
    obj->vel.y *= 0.96f;
    obj->vel.z *= 0.96f;

    obj->pos.x += obj->vel.x;
    obj->pos.y += obj->vel.y;
    obj->pos.z += obj->vel.z;

    k = 512.0f / (10.0f * obj->size);
    obj->spinX += (s32)(k * (obj->vel.x + obj->vel.y));
    obj->spinY += (s32)(k * (obj->vel.y + obj->vel.z));
    obj->spinZ += (s32)(k * (obj->vel.z + obj->vel.x));

    obj->spinX -= obj->spinX >> 5;
    obj->spinY -= obj->spinY >> 5;
    obj->spinZ -= obj->spinZ >> 5;

    obj->rotX += obj->spinX;
    obj->rotY += obj->spinY;
    obj->rotZ += obj->spinZ;
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_60880 */

/* fzgx:begin fn_1_60B80 */
void fn_1_60B80(Sig_fn_1_60B80_Obj *obj, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2)
{
    f32 v = 1.0f;

    lbl_8006D9D8(&obj->unk_3C);
    mathutil_mtxA_rotate_y(obj->unk_56);
    mathutil_mtxA_rotate_x(obj->unk_54);
    mathutil_mtxA_rotate_z(obj->unk_58);
    if (v < 0.0) {
        return;
    }
    if (v > 1.0) {
        v = 1.0f;
    }
    lbl_8006E14C((obj->unk_28));
    fn_1_55FC4((obj->unk_28));
    if (obj->unk_10 < 12) {
        v *= 0.0833333358168602f * obj->unk_10;
    }
    if (v < 1.0) {
        fn_1_55FF0(v);
        fn_1_5557C(obj->unk_34);
    }
    else {
        fn_1_555D0(obj->unk_34);
    }
}
/* fzgx:end fn_1_60B80 */

/* fzgx:begin fn_1_60C70 */
// fn_1_60C70: empty in retail (single blr).

void fn_1_60C70(void) {
}
/* fzgx:end fn_1_60C70 */

/* fzgx:begin fn_1_60C74 */
void fn_1_60C74(struct fn_1_60C74_Effect *effect) {
    effect->field_28 = 5.0f;
}
/* fzgx:end fn_1_60C74 */

/* fzgx:begin fn_1_60C84 */
// fn_1_60C84: empty in retail (single blr).

void fn_1_60C84(void) {
}
/* fzgx:end fn_1_60C84 */

/* fzgx:begin fn_1_60C88 */
void fn_1_60C88(Obj_60C88 *this)
{
    Vec3_f v;
    void * lab_t1;
    f32 tz, ty, tx;

    fn_1_862D4(this->s18, &v);
    lab_t1 = lbl_801A6D00;
    fn_1_8636C(this->s18, lab_t1);

    tx = v.x;
    ty = v.y;
    tz = v.z;
    mtx_set_translate((void *)LC_BASE, tx, ty, tz);

    lbl_8006E1B0(&this->v94, &this->v3c);

    this->fb4 = (s32)this->i10 * 0.5f;
    if (this->f28 > 0.0f) {
        this->f28 = ((this->f28) - 0.3);
    }
}
/* fzgx:end fn_1_60C88 */

/* fzgx:begin fn_1_60D54 */
static inline u16 fn_1_60D54_rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

void fn_1_60D54(u8 *arg0) {
    void *obj;
    f32 r;
    f32 g;
    f32 size;
    f32 scale;
    f32 b;
    f32 intensity;
    fn_1_60D54_Color color;
    fn_1_60D54_Light light;

    obj = *(void **)(arg0 + 0x34);
    intensity = 0.25f * *(f32 *)(arg0 + 0xb4);
    scale = (0.125f + (f32)(0.25f * intensity)) *
            (1.0f + fn_1_60D54_rand() / 32767.0f);
    size = 0.2 * (*(f32 *)(arg0 + 0x28) * (0.800000011920929 + (f64)(0.2 * (fn_1_60D54_rand() / 32767.0f))));
    memset(&light, 0, 0x40);
    r = scale * *(f32 *)(arg0 + 0x1c);
    g = scale * *(f32 *)(arg0 + 0x20);
    b = scale * *(f32 *)(arg0 + 0x24);
    light.color.r = __OSf32tou8(r);
    light.color.g = __OSf32tou8(g);
    light.color.b = __OSf32tou8(b);
    light.color.a = 0xff;
    lbl_8006DC6C((u8 *)lbl_801A6D00 + 0x30);
    {
        f32 z;
        f32 y;
        f32 x;
        x = *(f32 *)(arg0 + 0x3c);
        y = *(f32 *)(arg0 + 0x40);
        z = *(f32 *)(arg0 + 0x44);
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    lbl_8006E14C(size);
    fn_1_55FC4(size);
    fn_1_56000(1, 3, 0);
    fn_1_5621C(r, g, b, 1.0f);
    fn_80072558();
    fn_1_556B8(obj);
    fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
    fn_1_56000(1, 3, 1);
}
/* fzgx:end fn_1_60D54 */

/* fzgx:begin fn_1_60F7C */
// fn_1_60F7C: empty in retail (single blr).

void fn_1_60F7C(void) {
}
/* fzgx:end fn_1_60F7C */

/* fzgx:begin fn_1_60F80 */
// fn_1_60F80: empty in retail (single blr).

void fn_1_60F80(void) {
}
/* fzgx:end fn_1_60F80 */

/* fzgx:begin fn_1_60F84 */
void fn_1_60F84(fn_1_60F84_Effect *obj)
{
    f32 t;
    f64 d;
    f32 k = 0.96f;

    obj->vel_x = obj->vel_x * k;
    obj->vel_y = obj->vel_y * k;
    obj->vel_z = obj->vel_z * k;
    obj->pos_x = obj->pos_x + obj->vel_x;
    obj->pos_y = obj->pos_y + obj->vel_y;
    obj->pos_z = obj->pos_z + obj->vel_z;
    /* held in a double so the product and sum stay separate (fmul; fadd; frsp) */
    d = 0.1 * (obj->target_size - obj->size);
    obj->size = obj->size + d;

    if (obj->age < 20) {
        t = 1.0f + (f32)(-0.05f * obj->age);
        /* the common factor is CSE'd by the compiler; a named local would
           coalesce it with the chain and move the color load's */
        obj->color_1c = obj->color_1c * (1.0f - t);
        obj->color_20 = obj->color_20 * (1.0f - t);
        obj->color_24 = obj->color_24 * (1.0f - t);
    }
}
/* fzgx:end fn_1_60F84 */

/* fzgx:begin fn_1_61070 */
void fn_1_61070(Fn161070 *self) {
    EfxData data;
    Fade fade;
    Vec vector;
    int id = self->field34;
    f32 radius = self->field28;
    f32 distance;
    f32 scale;

    lbl_8006D9D8(self->field3c);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_z(self->field58);

    psvec_set(&vector, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
    distance = lbl_8006D0B4(effect_sum_sq(vector.x, vector.y, vector.z));
    if (distance > 0.1f + radius) {
        lbl_8006DB74(&fade);
        lbl_8006D848((distance - radius) / distance);
        lbl_8006DFC4(&fade);
    }

    memset((u8 *)&data, 0, 0x40);
    lbl_8006DB74(data.mtx);
    scale = 0.70710677f * self->field28;
    data.field0 = scale;
    data.color[0] = (255.0f * self->field1c);
    data.color[1] = (255.0f * self->field20);
    data.color[2] = (255.0f * self->field24);
    data.color[3] = 0xff;
    data.field4 = scale;
    fn_1_9F914(&data, (const void *)id);
}
/* fzgx:end fn_1_61070 */

/* fzgx:begin fn_1_611EC */
static inline u32 FxRand(void)
{
	lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
	return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

void fn_1_611EC(struct FxParam *p, u32 unused1, u32 unused2, u32 unused3)
{
	if (p->unk_10 == 0) {
		f32 t = FxRand() / 32767.0f;
		f64 d = 12.0 * t;
		p->unk_10 = (12.0 + d);
	}

	p->unk_0E = 0;

	if (0.0f == p->f_28) {
		f32 t = FxRand() / 32767.0f;
		p->f_28 = (1.0 + t);
	}

	p->unk_54 = FxRand();
	p->unk_56 = FxRand();
	p->unk_58 = FxRand();

	p->unk_38 = fn_1_45D0(lbl_801A6410, 0xF0, "effect.c", 0x1573);
}
/* fzgx:end fn_1_611EC */

/* fzgx:begin fn_1_61370 */
#pragma opt_propagation off

void fn_1_61370(fn_1_61370_Obj *p) {

    Obj_1_data_1CC74_Target *target = lbl_1_data_1CC74;
    fn_1_61370_Vec up;
    fn_1_61370_Vec *trail;
    f32 s;
    f32 k;
    f32 dot;

    p->vel.x += (f64)(0.003 * target->unk_0);
    p->vel.y += (f64)(0.003 * target->unk_4);
    p->vel.z += (f64)(0.003 * target->unk_8);

    lbl_8006D8D8(p->ang[1]);
    mathutil_mtxA_rotate_x(p->ang[0]);
    mathutil_mtxA_rotate_z(p->ang[2]);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    lbl_8006E1C0(&up, &up);

    /* reflect the velocity off the rotated up axis */
    {
        f32 up_z;
        f32 up_x;
        f32 dot;
        up_x = up.x;
        dot = up_x * p->vel.x;
        dot += up.y * p->vel.y;
        up_z = up.z;
        dot += up_z * p->vel.z;
        s = -0.9f * dot;
        p->vel.x += (f32)(up_x * s);
    }
    p->vel.y += (f32)(up.y * s);
    p->vel.z += (f32)(up.z * s);
    p->vel.x *= 0.95f;
    p->vel.y *= 0.95f;
    p->vel.z *= 0.95f;
    p->pos.x += p->vel.x;
    p->pos.y += p->vel.y;
    p->pos.z += p->vel.z;

    k = 512.0f / p->scale;
    (p->rot)[0] += (s32)(k * (p->vel.x + p->vel.y));
    (p->rot)[1] += (s32)(k * (p->vel.y + p->vel.z));
    (p->rot)[2] += (s32)(k * (p->vel.z + p->vel.x));
    (p->rot)[0] -= (p->rot)[0] >> 5;
    (p->rot)[1] -= (p->rot)[1] >> 5;
    (p->rot)[2] -= (p->rot)[2] >> 5;
    p->ang[0] += (p->rot)[0];
    p->ang[1] += (p->rot)[1];
    p->ang[2] += (p->rot)[2];

    if (p->count > 20) {
        p->count = 0;
    }
    trail = p->trail;
    trail[p->count].x = p->pos.x;
    trail[p->count].y = p->pos.y;
    trail[p->count].z = p->pos.z;
    p->count++;

    if (p->unk_AC < 20) {
        p->unk_AC++;
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_61370 */

/* fzgx:begin fn_1_61640 */
void fn_1_61640(struct Fn1_61640Object *object) {
    f32 value = (1.0f);
    f32 output[3];
    f32 temp[3];
    f32 pz, py, px;

    fn_1_862D4(object->field_18, output);
    fn_1_8636C(object->field_18, lbl_801A6D00);

    px = output[0];
    py = output[1];
    pz = output[2];

    mtx_set_translate((void *)LC_BASE, px, py, pz);

    lbl_8006E1B0(object->field_3c, temp);
    lbl_8006D9D8(temp);
    mathutil_mtxA_rotate_y(object->field_56);
    mathutil_mtxA_rotate_x(object->field_54);
    mathutil_mtxA_rotate_z(object->field_58);
    lbl_8006E14C(object->field_28);
    fn_1_55FC4(object->field_28);

    if (object->field_10 < 12) {
        value *= (0.0833333358f) * object->field_10;
    }
    if (value < (1.0)) {
        fn_1_55FF0(value);
        fn_1_5557C(object->field_34);
    } else {
        fn_1_555D0(object->field_34);
    }
}
/* fzgx:end fn_1_61640 */

/* fzgx:begin fn_1_61760 */
// Dispatches the object's effect resource when one is available.

void fn_1_61760(struct Fn1_61760Object *object) {
    if (object->effect_resource != 0) {
        fn_1_46B4((u32)lbl_801A6410, (u32)(object->effect_resource), "effect.c", 0x16c1);
    }
}
/* fzgx:end fn_1_61760 */

/* fzgx:begin fn_1_617A4 */
void fn_1_617A4(struct Fn1_617A4Object *object) {
    f32 t;

    if (object->unk_10 == 0) {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        object->unk_10 = ((60.0f) *
            ((0.100000001f) + ((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f)));
    }

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    t = (0.0299999993f) * (((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f));
    object->unk_94 = (0.0700000003f) + t;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    t = (0.100000001f) * (((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f));
    object->unk_98 = (0.0700000003f) + t;
}
/* fzgx:end fn_1_617A4 */

/* fzgx:begin fn_1_618B8 */
void fn_1_618B8(struct obj_state *p)
{
	f32 s;
	s32 t;

	s = 1.0f - p->f94;
	p->f4c += -0.004f;
	p->f48 = p->f48 * s;
	p->f4c = p->f4c * s;
	p->f50 = p->f50 * s;
	p->f3c = p->f3c + p->f48;
	p->f40 = p->f40 + p->f4c;
	p->f44 = p->f44 + p->f50;
	p->f94 = (f32)(0.05f * (p->f98 - p->f94)) + p->f94;
	p->f28 = (f32)(0.2f * (p->f2c - p->f28)) + p->f28;
	t = p->timer;
	if (t < 15.0) {
		p->f1c = p->f1c * (1.0f - 1.0f / (t + 1));
		p->f20 = p->f20 * (1.0f - 1.0f / (t + 1));
		p->f24 = p->f24 * (1.0f - 1.0f / (t + 1));
	}
}
/* fzgx:end fn_1_618B8 */

/* fzgx:begin fn_1_619E4 */
#pragma opt_common_subs off

void fn_1_619E4(fn_1_619E4_Obj *obj) {
void *model;
f32 size;
f32 radius;
f32 len;
f32 s;
f32 dx, dz, dy;
f32 ox, oy;
fn_1_619E4_DrawParam param;
Vec3 end;
Vec3 start;
Vec3 mid;
Vec3 dir;
s16 rotX;
s16 rotY;
model = obj->model;
memset(&param, 0, sizeof(param));
radius = obj->radius;
lbl_8006DBAC((void *)lbl_801A66CC.unk_0);
lbl_8006E1B0(&obj->start, &start);
lbl_8006DCA4();
if (fn_1_54E34(&obj->end, obj->radius)) {
lbl_8006E1B0(&obj->end, &end);
if (end.z < 0.0f && start.z < 0.0f) {
dx = end.x - start.x;
dy = end.y - start.y;
size = obj->radius;
dir.x = dx;
dir.y = dy;
if (0.0f == dx && 0.0f == dy) {
lbl_8006E0A4(&obj->end);
lbl_8006D7B0();
} else {
dir.z = 0.0f;
lbl_8006D668(&dir);
s = radius;
s *= 0.6f;
ox = dir.x * s;
oy = dir.y * s;
end.x = end.x + ox;
end.y = end.y + oy;
start.x = start.x - ox;
start.y = start.y - oy;
mid.x = 0.5f * (end.x + start.x);
mid.y = 0.5f * (end.y + start.y);
mid.z = 0.5f * (end.z + start.z);
dx = end.x - start.x;
oy = end.y - start.y;
ox = end.z - start.z;
len = dx * dx;
len = oy * oy + len;
len = ox * ox + len;
len = lbl_8006D0B4(len);
fn_8006EDBC(&end, &start, &rotX, &rotY);
lbl_8006D7DC(&mid);
mathutil_mtxA_rotate_y(rotY);
mathutil_mtxA_rotate_x(rotX);
lbl_8006E15C(1.0f, 1.0f, len / radius);
mathutil_mtxA_rotate_x(0x4000);
fn_8006E294(&dir);
mathutil_mtxA_rotate_y(lbl_8006D24C(dir.x, dir.z));
}
lbl_8006DB74(param.mtx);
param.scale = 2.0f * size;
param.r = 255.0f * obj->red;
param.g = 255.0f * obj->green;
param.b = 255.0f * obj->blue;
param.a = 0xFF;
fn_1_9F914(&param, model);
}
}
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_619E4 */

/* fzgx:begin fn_1_61C84 */
// fn_1_61C84: empty in retail (single blr).

void fn_1_61C84(void) {
}
/* fzgx:end fn_1_61C84 */

/* fzgx:begin fn_1_61C88 */
void fn_1_61C88(void) {
    fn_1_61D08();
}
/* fzgx:end fn_1_61C88 */

/* fzgx:begin fn_1_61CA8 */
void fn_1_61CA8(void) {
    fn_1_61EF4();
}
/* fzgx:end fn_1_61CA8 */

/* fzgx:begin fn_1_61CC8 */
void fn_1_61CC8(void) {
    fn_1_620C4();
}
/* fzgx:end fn_1_61CC8 */

/* fzgx:begin fn_1_61CE8 */
void fn_1_61CE8(void) {
    fn_1_61E60();
}
/* fzgx:end fn_1_61CE8 */

/* fzgx:begin fn_1_61D08 */
f32 lbl_1_data_1D8A4 = 3e+01f;

int fn_1_61D08(fn_1_61D08_EffectObject *obj) {
    EffectChild *child;
    u32 size;
    u32 random;
    f32 initial;
    f32 value;

    obj->unk_38 = fn_1_45D0(lbl_801A6410, 0x24, "effect.c", 0x17a6);
    child = (EffectChild *)obj->unk_38;
    size = GXGetTexBufferSize(0x14, 0xe, 0, 0, 0);
    child->unk_20 = fn_1_45D0(lbl_801A6410, size, "effect.c", 0x17ab);

    initial = 30.0f;
    lbl_1_data_1D8A4 = initial;
    obj->unk_10 = (s32)initial;
    obj->unk_b4 = 0.3f;

    random = ((0x41c64e6d) * (lbl_1_data_1D628)) + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_54 = ((random >> 16) & 0x7fff);

    random = ((0x41c64e6d) * (lbl_1_data_1D628)) + 0x3039;
    lbl_1_data_1D628 = random;
    value = ((random >> 16) & 0x7fff);
    obj->unk_5a = (4096.0f * (value / 32767.0f - 0.5f));

    obj->unk_34 = ((EffectInner *)lbl_1_bss_38458->unk_8)->unk_130;
    return 1;
}
/* fzgx:end fn_1_61D08 */

/* fzgx:begin fn_1_61E60 */
// Releases the effect resources and clears the active effect references.

int fn_1_61E60(Fn1_61E60Object *object) {
    Fn1_61E60Node *node = object->unk_38;

    if (node != 0) {
        fn_1_4730( (u32)(lbl_801A6410), (u32)(node->unk_20), 1, "effect.c", 0x17D5);
        node->unk_20 = 0;
        fn_1_46B4((u32)lbl_801A6410, (u32)(object->unk_38), "effect.c", 0x17D8);
        object->unk_38 = 0;
    }

    return 1;
}
/* fzgx:end fn_1_61E60 */

/* fzgx:begin fn_1_61EF4 */
/* begin game/main_rel/effect_types.h (deltawave784/fzgx@13b0aeca (CC0)) */

#define GAME_MAIN_REL_EFFECT_TYPES_H

// Types (and the externs that name them) of effect.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* end game/main_rel/effect_types.h */

/* begin game/main_rel/car_test_types.h (deltawave784/fzgx@13b0aeca (CC0)) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

int fn_1_61EF4(Obj_61EF4 *self) {
    f32 b[13];
    f32 a[3];
    s32 c;

    c = ++lbl_1_bss_6C864;
    if (c > 1) {
        self->b0 = 3;
    }
    fn_1_862D4(self->id18, a);
    fn_1_8636C(self->id18, b);
    lbl_8006DC6C(b);
    {
        f32 z, y, x;
        x = a[0];
        y = a[1];
        z = a[2];
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    self->f48 *= 0.98f;
    self->f4c *= 0.98f;
    self->p94[0] += self->f48;
    self->p94[1] += self->f4c;
    self->p94[2] += self->f50;
    lbl_8006E1B0( (Fn183D28Vec3 *)(self->p94), (Fn183D28Vec3 *)(self->m3c));
    lbl_8006DBAC((u8 *)self + 0xb8);
    lbl_8006DA50();
    lbl_8006DF44();
    lbl_8006E1B0( (Fn183D28Vec3 *)(self->m3c), (Fn183D28Vec3 *)(self->m3c));
    self->s5a = 0.98f * self->s5a;
    self->s54 += self->s5a;
    self->f2c *= 1.06f;
    self->f28 += self->f2c;
    if (self->n10 > 15) {
        self->fb4 = self->fb4 + (f32)(0.1f * (1.0f - self->fb4));
    } else {
        self->fb4 = self->fb4 * (1.0f - 1.0f / (self->n10 + 1));
    }
    return 1;
}

#undef GAME_MAIN_REL_EFFECT_TYPES_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_61EF4 */

/* fzgx:begin fn_1_620C4 */
// fn_1_620C4: empty in retail (single blr).

void fn_1_620C4(void) {
}
/* fzgx:end fn_1_620C4 */

/* fzgx:begin fn_1_620C8 */
void fn_1_620C8(void *arg0)
{
    s32 w;
    s32 h;
    s32 hw;
    s32 hh;
    void *tex = *(void **)((u8 *)arg0 + 0x38);
    void *obj;
    f32 col;
    f32 vp[6];

    fn_80038F10(vp);
    w = ((vp[2] < 40.0f) ? vp[2] : 40.0f);
    h = ((vp[3] < 28.0f) ? vp[3] : 28.0f);
    hw = w >> 1;
    hh = h >> 1;
    fn_80038EEC(vp[0], vp[1], w, h, 0.0f, 1.0f);
    fn_80074188((s32)vp[0], (s32)vp[1], w, h);
    col = *(f32 *)((u8 *)arg0 + 0xB4);
    obj = *(void **)((u8 *)arg0 + 0x34);
    lbl_8006DFE8((u8 *)arg0 + 0xB8);
    lbl_8006DA50();
    lbl_8006E0A4((u8 *)arg0 + 0x3C);
    lbl_8006E14C(*(f32 *)((u8 *)arg0 + 0x28) / *(f32 *)((u8 *)obj + 0x14));
    mathutil_mtxA_rotate_x(-0x8000);
    if (fn_1_54E34((u8 *)obj + 8, *(f32 *)((u8 *)arg0 + 0x28)) != 0) {
        fn_1_56000(1, 3, 0);
        fn_1_5621C(col, col, col, 1.0f);
        fn_80072558();
        fn_1_556B8(obj);
        fn_1_56000(1, 3, 1);
        fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
    }
    fn_80074918(1, 3, 1);
    fn_80074300((s32)vp[0], (s32)vp[1], w, h);
    fn_80074438(hw, hh, 0, 1);
    fn_8003526C(*(void **)((u8 *)tex + 0x20), 1);
    GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)tex, *(void **)((u8 *)tex + 0x20), hw, hh, 0, 0, 0, 0);
    fn_80038EEC(vp[0], vp[1], vp[2], vp[3], vp[4], vp[5]);
    fn_80074188((s32)vp[0], (s32)vp[1], (s32)vp[2], (s32)vp[3]);
}
/* fzgx:end fn_1_620C8 */

/* fzgx:begin fn_1_62360 */
/* GX write-gather pipe: a volatile hardware FIFO, as GXWGFifo in the SDK. */
#define WGPIPE (*(volatile Fifo *)GX_FIFO_BASE)

static inline void color(u8 a) {
WGPIPE.u8=0;WGPIPE.u8=0;WGPIPE.u8=0;WGPIPE.u8=a;
}

void fn_1_62360(void *arg0) {
    s32 inneralpha;
    void * obj;
 f32 radius, middle, outer;
 s32 alpha;
 s32 endalpha;
 s32 i;
 struct { f32 s,c; } sc;
 f32 center,y1,y2;
 obj = *(void **)(((0x38) + ((u8 *)arg0)));
 lbl_8006DFE8((u8 *)arg0+0xb8);
 lbl_8006E0A4((u8 *)arg0+0x3c);
 fn_1_62794(obj);
 radius=5.0*(lbl_1_data_1D8A4-(f32)*(s32 *)((u8 *)arg0+0x10))/lbl_1_data_1D8A4;
 middle=1.5f*radius;
 outer=3.5f*radius;
lbl_8006D188((65536.0f*(*(s32 *)((u8 *)arg0+0x10)%(2*(s32)lbl_1_data_1D8A4))/(2*(s32)lbl_1_data_1D8A4)));
alpha=(180.0f*lbl_8006D188((65536.0f*(*(s32 *)((u8 *)arg0+0x10)%(2*(s32)lbl_1_data_1D8A4))/(2*(s32)lbl_1_data_1D8A4))));
endalpha=(0.0f*lbl_8006D188((65536.0f*(*(s32 *)((u8 *)arg0+0x10)%(2*(s32)lbl_1_data_1D8A4))/(2*(s32)lbl_1_data_1D8A4))));
fn_800724C8();
fn_8007245C(0xa00);
fn_80074918(1,7,0);
GXLoadPosMtxImm(lbl_801A6D00,0);
fn_8003462C(0x98,0,42);
center=0.0f;
for(i=0;i<=20;i++){
 inneralpha=((u8)center);
 lbl_8006D1B8((i*65536/20),&sc);
WGPIPE.f32=center+(f32)(radius*sc.c);
y1=center+(f32)(radius*sc.s);
y2=center+(f32)(middle*sc.s);
WGPIPE.f32=y1;
WGPIPE.f32=0.0f;
color(inneralpha);
WGPIPE.f32=center+(f32)(middle*sc.c);
WGPIPE.f32=y2;
WGPIPE.f32=0.0f;
color((alpha & 0xFF));
}
fn_8003462C(0x98,0,42);
center=0.0f;

for(i=0;i<=20;i++){
lbl_8006D1B8((i*65536/20),&sc);
WGPIPE.f32=center+(f32)(middle*sc.c);
y1=center+(f32)(middle*sc.s);
y2=center+(f32)(outer*sc.s);
WGPIPE.f32=y1;
WGPIPE.f32=0.0f;
color((alpha & 0xFF));
WGPIPE.f32=center+(f32)(outer*sc.c);
WGPIPE.f32=y2;
WGPIPE.f32=0.0f;
color((endalpha & 0xFF));
}
fn_80074788(0);fn_80073898(0);fn_80073C6C(0);
}
#undef WGPIPE
/* fzgx:end fn_1_62360 */

/* fzgx:begin fn_1_62794 */
void fn_1_62794(void *arg0) {
    s32 w;
    s32 h;
    void *buf;
    f32 half;
    f32 zero;
    u32 loc_7C[12];
    TexObj62794 loc_5C;
    f32 loc_44[6];
    f32 loc_28[7];
    f32 loc_10[6];

    buf = lbl_801A63D0;
    fn_80038F10(loc_44);
    w = (s32)((2)[loc_44]) >> 1;
    h = (s32)((3)[loc_44]) >> 1;
    fn_80074300((s32)((0)[loc_44]), (s32)((1)[loc_44]), (s32)((2)[loc_44]), (s32)((3)[loc_44]));
    fn_80074438(w, h, 4, 1);
    fn_8003526C(buf, 0);
    GXInitTexObj(&loc_5C, buf, w, h, 4, 0, 0, 0);
    fn_80072864(0);
    GXGetProjectionv(loc_28);
    lbl_8006DAEC();
    lbl_8006DAEC();
    lbl_8006D758();
    {
        f32 hh = -0.5f;
        f32 t = hh * ((1)[loc_28]);
        hh = 0.5f;
        ((f32 *)lbl_801A6D00)[0] = t;
        ((f32 *)lbl_801A6D00)[2] = hh + (f32)(hh * ((2)[loc_28]));
        ((f32 *)lbl_801A6D00)[5] = hh * ((3)[loc_28]);
        ((f32 *)lbl_801A6D00)[6] = hh + (f32)(hh * ((4)[loc_28]));
    }
    lbl_8006DB74(loc_7C);
    lbl_8006DB30();
    lbl_8006DFD8(loc_7C);
    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
    lbl_8006DB30();
    zero = 0.0f;
    half = 0.5f;
    loc_10[0] = zero;
    loc_10[1] = half;
    loc_10[2] = zero;
    loc_10[3] = half;
    loc_10[4] = zero;
    loc_10[5] = zero;
    fn_80073A58(1, loc_10, 0);
    fn_80074788(1);
    fn_800747D0(0, 0, 0, 0, 0, 0, 2);
    fn_800747D0(2, 0, 0, 1, 0, 0, 2);
    fn_80073778(&loc_5C, 0);
    fn_80073778(arg0, 1);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800734A8(0, 0, 0, 4);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 15, 15, 8);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 5);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    fn_800745A4(1, 0, 0, 30, 0, 125);
    fn_800738E0(0, 1, 1);
    fn_80073B50(0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    fn_80073678(1);
    fn_80074660(2);
    fn_80073898(1);
}
/* fzgx:end fn_1_62794 */

/* fzgx:begin fn_1_62AF8 */
/* Unknown retail object: .rodata 2C28, no retail code reads it. */
const u32 lbl_1_rodata_2C28[2] = {0xFFFFFFFF, 0xFFFFFFFF};

void fn_1_62AF8(struct fn_1_62AF8_obj *obj) {
    u32 random;

    if (obj->unk_10 == 0) {
        u32 r15;
        f32 ratio;

        random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = random;
        r15 = (random >> 16) & 0x7FFF;
        ratio = r15 / 32767.0f;
        obj->unk_10 = (30.0 + 60.0f * ratio);
    }

    obj->unk_0E = 0;
    if (0.0f == obj->unk_28) {
        u16 r15a;
        u16 r15b;
        f32 qa;
        f32 qb;
        f64 da;
        f64 db;

        r15a = (lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039) >> 16 & 0x7FFF;
        qa = r15a / 32767.0f;

        r15b = (lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039) >> 16 & 0x7FFF;
        qb = r15b / 32767.0f;

        da = 0.02 * qa;
        db = 0.5 * qb;
        obj->unk_28 = ((5.0f * (f32)(0.02 + da)) * (0.5 + db));
    }

    random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_54 = (random >> 16) & 0x7FFF;
    random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_56 = (random >> 16) & 0x7FFF;
    random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_58 = (random >> 16) & 0x7FFF;
}
/* fzgx:end fn_1_62AF8 */

/* fzgx:begin fn_1_62C84 */
void fn_1_62C84(Particle *p) {
 Obj_1_data_1CC74_Target *accel = lbl_1_data_1CC74;
 f32 factor;
 if ((s32)++lbl_1_bss_6C868 > 50) p->unk_0 = 3;
 if (fn_1_66B8(&p->unk_3C, (1.0f)) == 0) p->unk_0 = 3;
 {
 p->unk_48 += (f64)(0.03 * accel->unk_0);
 p->unk_4C += (f64)(0.03 * accel->unk_4);
 p->unk_50 += (f64)(0.03 * accel->unk_8);
 p->unk_48 *= 0.94f;
 p->unk_4C *= 0.94f;
 p->unk_50 *= 0.94f;
 p->unk_3C += p->unk_48;
 p->unk_40 += p->unk_4C;
 p->unk_44 += p->unk_50;
 factor = 512.0f / (10.0f * p->unk_28);
 p->unk_5A += (s32)(factor * (p->unk_48 + p->unk_4C));
 p->unk_5C += (s32)(factor * (p->unk_4C + p->unk_50));
 p->unk_5E += (s32)(factor * (p->unk_50 + p->unk_48));
 p->unk_5A -= p->unk_5A >> 5;
 p->unk_5C -= p->unk_5C >> 5;
 p->unk_5E -= p->unk_5E >> 5;
 p->unk_54 += p->unk_5A;
 p->unk_56 += p->unk_5C;
 p->unk_58 += p->unk_5E;
 }
}
/* fzgx:end fn_1_62C84 */

/* fzgx:begin fn_1_62E9C */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

static inline f32 eff_dist_to(struct Eff62E9C *e, EffVec3 *p) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sq;
    dx = e->pos.x;
    dx -= p->x;
    sq = dx * dx;
    dy = e->pos.y;
    dy -= p->y;
    sq += dy * dy;
    dz = e->pos.z;
    dz -= p->z;
    sq += dz * dz;
    return lbl_8006D0B4(sq);
}

void fn_1_62E9C(struct Eff62E9C *e) {
    struct EffPacket62E9C pkt;
    EffVec3 tpos;
    EffVec3 cam;
    f32 alpha;
    f32 dist;
    u32 count;
    u32 i;

    alpha = 1.0f;
    lbl_8006DCA4();
    lbl_8006E1B0(&e->pos, &tpos);
    lbl_8006D7DC(&tpos);
    mathutil_mtxA_rotate_y(e->rot.y);
    mathutil_mtxA_rotate_x(e->rot.x);
    mathutil_mtxA_rotate_z(e->rot.z);

    count = fn_1_58C4();
    fn_1_681C(0, &cam);
    dist = eff_dist_to(e, &cam);
    for (i = 1; i < count; i++) {
        fn_1_681C(i, &cam);
        /* the macro evaluates the distance twice, as retail does */
        if (dist < eff_dist_to(e, &cam)) {
            dist = dist;
        } else {
            dist = eff_dist_to(e, &cam);
        }
    }

    if (dist <= 5.0) {
        return;
    }
    if (dist < 20.0f) {
        dist = dist / 20.0f;
    } else {
        dist = 1.0f;
    }
    memset(&pkt, 0, sizeof(pkt));
    lbl_8006DB74(pkt.mtx);
    pkt.unk_0 = 0.70710677f * e->size;
    if (e->unk_10 < 12) {
        alpha *= 0.083333336f * e->unk_10;
    }
    pkt.color[0] = (dist * (255.0f * e->r * alpha));
    pkt.color[1] = (dist * (255.0f * e->g * alpha));
    pkt.color[2] = (dist * (255.0f * e->b * alpha));
    pkt.color[3] = 255.0f * dist;
    pkt.unk_4 = pkt.unk_0;
    fn_1_9F914(&pkt, e->unk_34);
}
#undef MIN
/* fzgx:end fn_1_62E9C */

/* fzgx:begin fn_1_6312C */
// fn_1_6312C: empty in retail (single blr).

void fn_1_6312C(void) {
}
/* fzgx:end fn_1_6312C */

/* fzgx:begin fn_1_63130 */
void fn_1_63130(struct fn_1_63130_obj *obj) {
    obj->unk_AE = 0;
}
/* fzgx:end fn_1_63130 */

/* fzgx:begin fn_1_6313C */
void fn_1_6313C(Fx *p) {
    f32 t;
    s32 n;
    p->state = 2;
    lbl_1_bss_6C860 = lbl_1_bss_6C860 + 1;
    if (lbl_1_bss_6C860 > 150) {
        p->state = 3;
    }
    if (fn_1_66B8(&p->unk3c, p->unk28) == 0) {
        p->state = 3;
    }
    t = 1.0f - p->unk88;
    p->unk48 *= t;
    p->unk4c *= t;
    p->unk50 *= t;
    p->unk4c += -0.08f;
    p->unk48 += 0.001f;
    p->unk3c += p->unk48;
    p->unk40 += p->unk4c;
    p->unk44 += p->unk50;
    p->unk88 = p->unk88 + (f32)(0.05f * (p->unk8c - p->unk88));
    p->unk28 = p->unk28 + (f32)(0.01f * (p->unk2c - p->unk28));
    p->unkae += p->unkac;
    n = p->unk10;
    p->unk1c = p->unk1c * (1.0f - 1.0f / (n + 1));
    p->unk20 = p->unk20 * (1.0f - 1.0f / (n + 1));
    p->unk24 = p->unk24 * (1.0f - 1.0f / (n + 1));
}
/* fzgx:end fn_1_6313C */

/* fzgx:begin fn_1_632D4 */
void fn_1_632D4(struct fn_1_632D4_obj *obj) {
    struct fn_1_632D4_value { s32 a, b, c; } value;
    struct fn_1_632D4_data data;
    int id;
    s32 red;
    s32 green;
    s32 blue;
    f32 color_scale;
    f32 size;

    id = obj->unk_34;
    lbl_8006DCA4();
    lbl_8006E1B0(&obj->unk_3C, &value);
    lbl_8006D7DC(&value);
    mathutil_mtxA_rotate_z(obj->unk_AE);
    memset(&data, 0, 0x40);
    lbl_8006DB74(&data.unk_08);

    size = 0.70710677f;
    size = size * obj->unk_28;
    data.unk_00 = size;
    color_scale = 255.0f;
    red = color_scale * obj->unk_1C;
    data.red = red;
    green = color_scale * obj->unk_20;
    data.green = green;
    blue = color_scale * obj->unk_24;
    data.alpha = 0xff;
    data.unk_04 = size;
    data.blue = blue;

    fn_1_9F914(&data, (const void *)(id));
}
/* fzgx:end fn_1_632D4 */

/* fzgx:begin fn_1_633BC */
// fn_1_633BC: empty in retail (single blr).

void fn_1_633BC(void) {
}
/* fzgx:end fn_1_633BC */

/* fzgx:begin fn_1_633C0 */
void fn_1_633C0(FxObj633C0 *obj) {
    FxVec b[4];
    FxVec a;
    FxVec d;

    if (obj->unk10 == 0) {
        u32 r;
        r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = r;
        obj->unk10 = (60.0f * (0.2f + (f32)((0.2f * (((r >> 16) & 0x7FFF) / 32767.0f)))));
    }
    fn_1_862D4(obj->unk18, &a);
    fn_1_8645C(obj->unk18, &b);
    lbl_8006DC6C(&b);
    {
        f32 z, y, x;
        x = a.x;
        y = a.y;
        z = a.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    {
    FxVec c = {0.0f, 0.0f, 0.0f};
    c.x = obj->unk94.x;
    c.y = obj->unk94.y;
    c.z = obj->unk94.z;
    d = c;
    }
    lbl_8006E1B0(&d, &obj->unk3c);
    obj->unk60 = obj->unk3c;
}
/* fzgx:end fn_1_633C0 */

/* fzgx:begin fn_1_63514 */
// fn_1_63514: empty in retail (single blr).

void fn_1_63514(void) {
}
/* fzgx:end fn_1_63514 */

/* fzgx:begin fn_1_63518 */
void fn_1_63518(Effect_63518_63518 *effect) {
    Effect_63518_vec *dst;
    u32 i;

    effect->unk14 = 0;
    effect->unkac = 0;
    effect->unkae = 0;
    effect->unkb0 = 0;
    effect->unk58 = 0;

    effect->unk60 = effect->unk3c;
    dst = effect->unk38;

    for (i = 0; i < fn_1_58C4() * 8; i++) {
        *dst++ = effect->unk3c;
    }
}
/* fzgx:end fn_1_63518 */

/* fzgx:begin fn_1_635BC */
/* begin game/main_rel/car_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TYPES_H

// Types (and the externs that name them) of car.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3f_635BC likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* game/vec3.h: inlined above */

/* retail takes (obj, idx, mask, mask2) (fn_1_8F198 passes all four); non-prototype until fn_1_8F45C passes its own four through */

/* end game/main_rel/car_types.h */

/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

/* fzgx-allow: S2 pool primer sink */

/* Translation column of the current matrix in the locked cache. */

void fn_1_635BC(Fn1635BCEffect *e) {
    Fn183D28Vec3 pos;
    Fn183D28Vec3 offset;
    Fn183D28Vec3 tmp;
    u32 flags;
    f32 rnd;
    f32 scale;

    flags = fn_1_864E8(e->id);
    if (((flags & 0x8) || (flags & 0x20000)) && __rlwnm(e->flags, 19, 31, 31)) {
        e->timer++;
    } else {
        e->vel_x *= 0.98f;
        e->vel_y *= 0.98f;
        e->flags &= ~0x2000;
    }

    fn_1_862D4(e->id, &pos);
{
    f32 mtx[3][4];
    fn_1_8645C(e->id, mtx);
    lbl_8006DC6C(mtx);
}
    {
        f32 z, y, x;
        x = pos.x;
        y = pos.y;
        z = pos.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    e->rot_y += e->vel_y;
    e->rot_x += e->vel_x;
    mathutil_mtxA_rotate_y(e->rot_y);
    mathutil_mtxA_rotate_x(e->rot_x);
    {
        Fn183D28Vec3 init = { 0.0f, 0.0f, 0.0f };
        tmp = init;
    }
    tmp.x = e->offset.x;
    tmp.y = e->offset.y;
    tmp.z = e->offset.z;
    offset = tmp;
    lbl_8006E1B0(&offset, &e->pos);

    e->unk_B4 = 0.5f * e->timer;
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
    rnd = 0.8f + (f32)(0.2f * (((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
    e->r = 255.0f * (0.5f * (1.0f + rnd)) / 255.0f;
    scale = 136.0f * rnd / 255.0f;
    e->g = scale;
    e->b = scale;
    if (e->timer < 30) {
        e->r *= scale = 1.0f - (1.0f + (f32)(-0.03f * e->timer));
        e->g *= scale;
        e->b *= scale;
    }
}
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef GAME_VEC3_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_635BC */

/* fzgx:begin fn_1_63858 */
void fn_1_63858(struct fn_1_63858_Object *object) {
    struct LocalData local;
    struct fn_1_63858_Event *event;
    void *target;

    fn_1_862D4(object->value, &local);
    lbl_8006DCA4();
    if (fn_1_54E34(&local, 6.0f) != 0) {
        target = fn_1_5448C(&local);
        event = (struct fn_1_63858_Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->callback = (void *)fn_1_638E8;
            event->owner = object;
            fn_1_5489C( (void **)(target), (void **)(event));
        }
    }
}
/* fzgx:end fn_1_63858 */

/* fzgx:begin fn_1_638E8 */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@f88123fa) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

/* fzgx-allow: S2 keeps the verified access order */

static inline void fn_1_638E8_locked_cache(f32 **ptr) {
    *ptr = (f32 *)LC_BASE;
}

void fn_1_638E8(struct fn_1_638E8_Arg0 *arg0) {
    f32 *locked_ptr;
    u32 v33;
    s16 v2;
    Fn183D28Vec3 *v52;
    Fn183D28Vec3 *v17;
    struct fn_1_638E8_row *v38;
    s16 v14;
    u8 *v0;
    u32 v35;
    u32 v1;
    u32 v42;
    f64 v18;
    u32 v19;
    f32 v20, v21, v24;
    u32 v25;
    f32 v47, v46, v45, v44, v43;
    f32 v31;
    f32 v30;
    u32 v37;
    u32 v41;
    u32 v49;
    f32 v48, v50, v51, v53;
    f32 v57, v58, v59;
    f32 v54, v55;
    f32 v61;
    struct { f32 a[12]; } loc_80;
    struct { u32 a[12]; } loc_50;
    struct Sig_fn_1_9EA94_fn_1_9EA94_Arg0_638E8 loc_38;
    struct Sig_fn_1_867CC_fn_1_867CC_Arg1 loc_2C;
    Fn183D28Vec3 loc_20;
    Fn183D28Vec3 loc_14;
    u8 loc_10, loc_C, loc_8;
    s32 t0;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t13;
#define locked (locked_ptr = (f32 *)LC_BASE)

    v0 = (u8 *)arg0->unk_8;
    t0 = fn_1_5910();
    if (camera_get_entry_field_0xa4((t0 & 0xFF)) == 0 &&
        (s32)fn_1_707C((*(s16 *)(v0 + 24) & 0xFF)) != 0) {
        v1 = 1;
    } else {
        v1 = 0;
    }
    fn_1_867CC(*(s16 *)(v0 + 24), &loc_2C);
    t4 = fn_1_3F164();
    if (t4 != 0) {
        t5 = fn_1_5910();
        switch (t5) {
        case 0: v2 = ((*(s16 *)(v0 + 172) - 1) % 8); break;
        case 1: v2 = ((*(s16 *)(v0 + 174) - 1) % 8); break;
        case 2: v2 = ((*(s16 *)(v0 + 176) - 1) % 8); break;
        case 3: v2 = ((*(s16 *)(v0 + 88) - 1) % 8); break;
        default: v2 = ((*(s16 *)(v0 + 172) - 1) % 8); break;
        }
    } else {
        struct fn_1_638E8_row *v15;
        t6 = fn_1_5910();
        switch (t6) {
        case 0: v14 = *(s16 *)(v0 + 172); break;
        case 1: v14 = *(s16 *)(v0 + 174); break;
        case 2: v14 = *(s16 *)(v0 + 176); break;
        case 3: v14 = *(s16 *)(v0 + 88); break;
        default: v14 = *(s16 *)(v0 + 172); break;
        }
        v15 = *(struct fn_1_638E8_row **)(v0 + 56);
        v17 = &v15->a[v14] + fn_1_5910() * 8;
        lbl_8006DCA4();
        lbl_8006E1B0((Fn183D28Vec3 *)(v0 + 60), v17 + 1);
        v18 = 0.5;
        v19 = lbl_801A66CC.unk_0;
        loc_20.x = v18 * (*(f32 *)(v0 + 60) + *(f32 *)(v0 + 96));
        loc_20.y = v18 * (*(f32 *)(v0 + 64) + *(f32 *)(v0 + 100));
        loc_20.z = v18 * (*(f32 *)(v0 + 68) + *(f32 *)(v0 + 104));
        v20 = v18 * (((struct fn_1_638E8_lbl_801A6D00_T *)lbl_801A6D00)->unk_3C + *(f32 *)(v19 + 12));
        v21 = v18 * (((struct fn_1_638E8_lbl_801A6D00_T *)lbl_801A6D00)->unk_4C + *(f32 *)(v19 + 28));
        v24 = v18 * (((struct fn_1_638E8_lbl_801A6D00_T *)lbl_801A6D00)->unk_5C + *(f32 *)(v19 + 44));
        fn_8006F9A4(0.5f, (Vec3 *)v19, (Vec3 *)((u32)lbl_801A6D00 + 48), &loc_80);
        loc_80.a[3] = v20;
        loc_80.a[7] = v21;
        loc_80.a[11] = v24;
        lbl_8006DBAC((Vec3 *)&loc_80);
        lbl_8006E1B0(&loc_20, (Fn183D28Vec3 *)v17);
        v25 = *(u32 *)(v0 + 20);
        if ((s32)v25 < 8) {
            *(u32 *)((u8 *)v0 + 20) = v25 + 2;
            v2 = ((v14 + 2) % 8);
        } else {
            *(u32 *)((u8 *)v0 + 20) = 8;
            v2 = ((v14 + 2) % 8);
        }
        t13 = fn_1_5910();
        switch (t13) {
        case 0: *(u16 *)(v0 + 172) = v2; break;
        case 1: *(u16 *)(v0 + 174) = v2; break;
        case 2: *(u16 *)(v0 + 176) = v2; break;
        case 3: *(u16 *)(v0 + 88) = v2; break;
        default: *(u16 *)(v0 + 172) = v2; break;
        }
    }
#undef locked
#define locked locked_ptr
    v30 = 0.1f;
    v31 = 1.0f;
    v33 = 0x41C64E6D;

    v43 = 0.8f;
    v44 = 255.0f;
    v45 = 0.125f;
    v46 = 0.5f;
    v47 = 32767.0f;
    v35 = 0;
    while (v35 < *(u32 *)(v0 + 20)) {
        v38 = *(struct fn_1_638E8_row **)(v0 + 56);
        v52 = &v38->a[v2] + fn_1_5910() * 8;
        v48 = v30 * *(f32 *)(v0 + 180);
        v41 = v35 / *(u32 *)(v0 + 20);
        v50 = v48 * (v31 - v41);
        v37 = lbl_1_bss_38458->unk_8;
        v42 = *(u32 *)(v37 + 112);
        v37 = lbl_1_data_1D628 * v33 + 12345;
        v49 = (v37 >> 16) & 0x7FFF;
        lbl_1_data_1D628 = v37;
        v51 = v43 * v50;
        v53 = v45 + (f32)(v46 * v50);
        v54 = v30 + v51;
        v55 = v44 * (v53 * (v31 + (v49 / v47)));
        v55 = v55 * (v31 - (v35 / *(u32 *)(v0 + 20)));
        fn_1_638E8_locked_cache(&locked_ptr);
        if ((u8)v1 != 0) {
            v54 *= 0.4f;
            v55 *= 1.5f;
        }
        fn_80074788(0);
        fn_80072864(0);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800734A8(0, 0, 0, 255);
        fn_80072AB0(0, 0, 0);
        fn_800735C8(0, 12);
        fn_80073620(0, 28);
        fn_80073C6C(0);
        fn_80072C24(0, 15, 15, 15, 14);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 6, 4, 7);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80073678(1);
        fn_80074660(1);
        fn_80074918(1, 3, 0);
        fn_800720B0(0);
        fn_800728A8(1, 4, 1, 0);
        fn_80073778(*(void **)(v42 + 36), 0);
        memset(&loc_38, 0, 24);
        v57 = v55 * *(f32 *)(v0 + 28);
        v58 = v55 * *(f32 *)(v0 + 32);
        v59 = v55 * *(f32 *)(v0 + 36);
        loc_10 = __OSf32tou8(v57);
        loc_38.color[0] = loc_10;
        loc_C = __OSf32tou8(v58);
        loc_38.color[1] = loc_C;
        loc_8 = __OSf32tou8(v59);
        loc_38.color[3] = 255;
        loc_38.color[2] = loc_8;
        loc_14 = *(Fn183D28Vec3 *)v52;
        lbl_8006D7B0();
        locked[3] = loc_14.x;
        locked[7] = loc_14.y;
        locked[11] = loc_14.z;
        if (fn_1_54E34((void *)(v42 + 8), v54) != 0) {
            f32 y;
            y = loc_14.y;
            v61 = loc_14.x * loc_14.x;
            v61 = __fmadds(y, y, v61);
            v61 = __fmadds(loc_14.z, loc_14.z, v61);
            v61 = lbl_8006D0B4(v61);
            if (v61 > 0.1f + v54) {
                lbl_8006DB74(&loc_50);
                lbl_8006D848((v61 - v54) / v61);
                lbl_8006DFC4(&loc_50);
            }
            loc_38.unk_0 = *(Fn183D28Vec3 *)(v42 + 8);
            loc_38.unk_C = 0.7071067690849304f * v54;
            loc_38.unk_10 = 0;
            fn_1_9EA94(&loc_38);
        }
        v35++;
        v2 = ((v2 + 1) % 8);
    }
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_638E8 */

/* fzgx:begin fn_1_64098 */
void fn_1_64098(Fn164098Object *object) {
    object->value = 0;
}
/* fzgx:end fn_1_64098 */

/* fzgx:begin fn_1_640A4 */
void fn_1_640A4(u8 *arg0) {
    u8 *o = arg0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f1;
    s32 temp_r0;

    o[0] = 2;
    temp_r0 = lbl_1_bss_6C860 + 1;
    lbl_1_bss_6C860 = temp_r0;
    if (temp_r0 > 0x96) {
        o[0] = 3;
    }
    if (fn_1_66B8(o + 0x3c, *(f32 *)(o + 0x28)) == 0) {
        o[0] = 3;
    }
    temp_f2 = (1.0f) - *(f32 *)(o + 0x88);
    *(f32 *)(o + 0x48) = *(f32 *)(o + 0x48) * temp_f2;
    *(f32 *)(o + 0x4c) = *(f32 *)(o + 0x4c) * temp_f2;
    *(f32 *)(o + 0x50) = *(f32 *)(o + 0x50) * temp_f2;
    *(s16 *)(o + 0xac) = (s16) ((f32) (*(s16 *)(o + 0xac)) * temp_f2);
    if (!(((*(u32 *)(o + 8)) >> 0x11U) & 1)) {
        *(f32 *)(o + 0x4c) += (0.00800000038f);
    } else {
        *(f32 *)(o + 0x4c) += (0.00400000019f);
    }
    temp_f1 = (0.00100000005f);
    temp_f2 = (0.0500000007f);
    temp_f3 = (0.00999999978f);
    *(f32 *)(o + 0x48) = *(f32 *)(o + 0x48) + temp_f1;
    *(f32 *)(o + 0x3c) = *(f32 *)(o + 0x3c) + *(f32 *)(o + 0x48);
    *(f32 *)(o + 0x40) = *(f32 *)(o + 0x40) + *(f32 *)(o + 0x4c);
    *(f32 *)(o + 0x44) = *(f32 *)(o + 0x44) + *(f32 *)(o + 0x50);
    *(s16 *)(o + 0xae) = (s16) ((*(s16 *)(o + 0xae)) + (*(s16 *)(o + 0xac)));
    temp_f4 = *(f32 *)(o + 0x88);
    temp_f0 = temp_f2 * (*(f32 *)(o + 0x8c) - temp_f4);
    *(f32 *)(o + 0x88) = temp_f4 + temp_f0;
    temp_f4 = *(f32 *)(o + 0x28);
    temp_f0 = temp_f3 * (*(f32 *)(o + 0x2c) - temp_f4);
    *(f32 *)(o + 0x28) = temp_f4 + temp_f0;
    if (*(f32 *)(o + 0x2c) > (50.0f)) {
        temp_r0 = *(s32 *)(o + 0x10);
        if (temp_r0 < 0xDC) {
            var_f1 = temp_r0;
            var_f1 = (0.0045454544f) * var_f1;
        } else {
            var_f1 = (1.0f);
        }
    } else {
        temp_r0 = *(s32 *)(o + 0x10);
        if (temp_r0 < 0x46) {
            var_f1 = temp_r0;
            var_f1 = (0.0142857144f) * var_f1;
        } else {
            var_f1 = (1.0f);
        }
    }
    *(f32 *)(o + 0x1c) = *(f32 *)(o + 0x1c) * var_f1;
    *(f32 *)(o + 0x20) = *(f32 *)(o + 0x20) * var_f1;
    *(f32 *)(o + 0x24) = *(f32 *)(o + 0x24) * var_f1;
}
/* fzgx:end fn_1_640A4 */

/* fzgx:begin fn_1_642E8 */
void fn_1_642E8(fn_1_642E8_EffectObject *self) {
    f32 value;
    void *state;
    EffectNode *node;

    value = self->value / 1e+01f;
    lbl_8006DCA4();
    if (fn_1_54E34(&self->state, value)) {
        state = fn_1_5448C(&self->state);
        node = fn_1_548AC(0xc);
        if (node != 0) {
            node->callback = (void *)fn_1_64388;
            node->owner = self;
            fn_1_5489C( (void **)(state), (void **)(node));
        }
    }
}
/* fzgx:end fn_1_642E8 */

/* fzgx:begin fn_1_64388 */
void fn_1_64388(ArgObj *arg0) {
 SelfObj_64388 *obj;
 NodeObj_64388 *node;
 Vec3_64388 pos;
 Vec3_64388 dir;
 Mtx mtx;
 f32 scale;
 f32 alpha;
 f32 ratio;
 f32 len;
 obj=arg0->obj;
 lbl_8006DCA4();
 lbl_8006E1B0(&obj->pos,&pos);
 scale=obj->size/10.0f;
 node=obj->node;
 if(pos.z > -1.1920928955078125e-7f) return;
 ratio=fn_1_A71AC();
 ratio=(240.0f*((2.0f*node->f14)*scale))/(-pos.z*ratio);
 alpha=1.0f;
 if(ratio<10.0f) return;
 if(ratio<20.0f) alpha*= (ratio-10.0f)/10.0f;
 if(ratio>2000.0f) return;
 if(ratio>1000.0f) alpha*=1.0f-(ratio-1000.0f)/1000.0f;
 lbl_8006D7DC(&pos);
 psvec_set(&dir,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
 len=lbl_8006D0B4(effect_sum_sq(dir.x,dir.y,dir.z));
 if(len>2.1f) {
 lbl_8006DB74(&mtx);
 lbl_8006D848((len-2.0f)/len);
 lbl_8006DFC4(&mtx);
 }
 mathutil_mtxA_rotate_z(obj->angle);
 lbl_8006E14C(scale);
 fn_1_55FC4(scale);
 fn_1_56000(1,3,0);
 fn_80072558();
 fn_1_5621C(obj->x,obj->y,obj->z,obj->age<60 ? (0.01666666753590107f*obj->age)*alpha : alpha);
 fn_1_556B8(node);
 fn_1_56000(1,3,1);
 fn_1_5621C(1.0f,1.0f,1.0f,1.0f);
}
/* fzgx:end fn_1_64388 */

/* fzgx:begin fn_1_645C8 */
// fn_1_645C8: empty in retail (single blr).

void fn_1_645C8(void) {
}
/* fzgx:end fn_1_645C8 */

/* fzgx:begin fn_1_645CC */
// fn_1_645CC: empty in retail (single blr).

void fn_1_645CC(void) {
}
/* fzgx:end fn_1_645CC */

/* fzgx:begin fn_1_645D0 */
// fn_1_645D0: empty in retail (single blr).

void fn_1_645D0(void) {
}
/* fzgx:end fn_1_645D0 */

/* fzgx:begin fn_1_645D4 */
void fn_1_645D4(struct A *arg0) {
    V3 pos;
    V3 rnd2;
    u8 mtx[0x30];
    fn_1_862D4(arg0->unk_18, &pos);
    fn_1_8636C(arg0->unk_18, mtx);
{
    V3 rnd = {0.0f, 0.0f, 0.0f};
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.x = 0.2 * ((s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.y = 0.2 * ((s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.z = 0.2 * ((s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    rnd2 = rnd;
}
    lbl_8006D5A4(&arg0->unk_94, &rnd2, &arg0->unk_94, 0.05f);
    lbl_8006DC6C(mtx);
    {
        f32 z, y, x;
        x = pos.x;
        y = pos.y;
        z = pos.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    lbl_8006E1B0(&arg0->unk_94, &arg0->unk_3c);
}
/* fzgx:end fn_1_645D4 */

/* fzgx:begin fn_1_64760 */
/* Fixed engine address; three floats at 0xc, 0x1c, 0x2c. */

void fn_1_64760(struct Fn15D718 *self) {
struct Fn15D718Work work;
struct Fn15D718Tmp tmp;
u32 object;
f32 radius;
f32 distance;
f32 alpha;
f32 v[3];
object = self->object34;
radius = self->value28;
lbl_8006D9D8(&self->value3c);
lbl_8006D7B0();
psvec_set(v, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
distance = lbl_8006D0B4(effect_sum_sq(v[0], v[1], v[2]));
if (distance > 0.1f + radius) {
lbl_8006DB74(&tmp);
lbl_8006D848((distance - radius) / distance);
lbl_8006DFC4(&tmp);
}
memset(&work, 0, 0x40);
lbl_8006DB74(&work.sub);
alpha = 0.70710677f * self->value28;
work.alpha = alpha;
work.red = (255.0f * self->value1c);
work.green = (255.0f * self->value20);
work.blue = (255.0f * self->value24);
work.alphaByte = 0xff;
work.alpha2 = alpha;
fn_1_9F914(&work, (const void *)object);
}
/* fzgx:end fn_1_64760 */

/* fzgx:begin fn_1_648D4 */
// fn_1_648D4: empty in retail (single blr).

void fn_1_648D4(void) {
}
/* fzgx:end fn_1_648D4 */

/* fzgx:begin fn_1_648D8 */
// fn_1_648D8: empty in retail (single blr).

void fn_1_648D8(void) {
}
/* fzgx:end fn_1_648D8 */

/* fzgx:begin fn_1_648DC */
/* retail loads the plain local copies (vx, vy, vz, nx, x) where they are assigned and keeps each in its own register */

#pragma opt_propagation off

void fn_1_648DC(Effect648DC *effect) {
    Vec648DC normal;
    Vec648DC d;
    Vec648DC side;
    Vec648DC up;
    u32 out;
    s32 checkpoint;
    Vec648DC *keep_d = &d; /* keeps d in memory: retail stores it */
    Surface648DC *surface;
    f32 retain;
    f32 push;
    f32 depth;
    f32 len;
    f32 y;
    f32 z;
    f32 up_weight;
    f32 side_weight;
    s16 rot_x;
    s16 rot_z;
    f32 vz;
    f32 nx;
    f32 vy;
    f32 vx;
    f32 dot;
    f32 x;
    f32 vdot;

    retain = 1.0f - effect->unk_88;
    effect->unk_48.x *= retain;
    effect->unk_48.y *= retain;
    effect->unk_48.z *= retain;
    effect->unk_48.y += -0.03f;
    effect->unk_3c.x += effect->unk_48.x;
    effect->unk_3c.y += effect->unk_48.y;
    effect->unk_3c.z += effect->unk_48.z;
    effect->unk_5a -= effect->unk_5a >> 5;
    effect->unk_5c -= effect->unk_5c >> 5;
    effect->unk_5e -= effect->unk_5e >> 5;
    effect->unk_54 += effect->unk_5a;
    effect->unk_56 += effect->unk_5c;
    effect->unk_58 += effect->unk_5e;
    effect->unk_88 += (f32)(0.03f * (effect->unk_8c - effect->unk_88));

    checkpoint = fn_1_8C66C(effect->unk_18);
    if (fn_1_15578(&effect->unk_3c, &effect->unk_60, &out, &normal, 0x40005, &checkpoint, 1, 0, 0, 0) == 0) {
        return;
    }
    d.x = effect->unk_3c.x - effect->unk_60.x;
    d.y = effect->unk_3c.y - effect->unk_60.y;
    d.z = effect->unk_3c.z - effect->unk_60.z;
    surface = effect->unk_34;
    if (effect->unk_28 < 0.04) {
        effect->unk_48.x *= 0.98;
        effect->unk_48.y *= 0.98;
        effect->unk_48.z *= 0.98;
    } else {
        effect->unk_48.x *= 0.96;
        effect->unk_48.y *= 0.96;
        effect->unk_48.z *= 0.96;
    }
    dot = normal.x * d.x;
    dot += normal.y * d.y;
    dot += normal.z * d.z;
    if (dot < 0.025) {
        depth = (f32)(surface->unk_14 * effect->unk_28) - dot;
        effect->unk_a0 = normal;
        effect->unk_2c = depth;
        vx = effect->unk_48.x;
        nx = normal.x;
        vy = effect->unk_48.y;
        vz = effect->unk_48.z;
        vdot = vx * nx;
        vdot += vy * normal.y;
        vdot += vz * normal.z;
        if (vdot < 0.0) {
            push = vdot;
            push *= -1.0;
            effect->unk_48.x = vx + (f32)(push * nx);
            effect->unk_48.y = effect->unk_48.y + (f32)(push * normal.y);
            effect->unk_48.z = effect->unk_48.z + (f32)(push * normal.z);
            effect->unk_48.x *= 0.8;
            effect->unk_48.y *= 0.8;
            effect->unk_48.z *= 0.8;
            if (effect->unk_28 < 0.04) {
                push *= 0.5f;
            } else {
                push *= 0.3f;
            }
            effect->unk_48.x = effect->unk_48.x + (f32)(push * normal.x);
            effect->unk_48.y = effect->unk_48.y + (f32)(push * normal.y);
            effect->unk_48.z = effect->unk_48.z + (f32)(push * normal.z);
        }

        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        side = normal;
        lbl_8006D8D8(effect->unk_56);
        mathutil_mtxA_rotate_x(effect->unk_54);
        mathutil_mtxA_rotate_z(effect->unk_58);
        lbl_8006E1C0(&up, &up);
        if ((f32)(up.x * normal.x) + (f32)(up.y * normal.y) + (f32)(up.z * normal.z) < 0.0) {
            side.x = -side.x;
            side.y = -side.y;
            side.z = -side.z;
        }
        up_weight = 0.95f;
        x = side.x;
        side_weight = 0.05f;
        up.x = (f32)(x * side_weight) + (f32)(up.x * up_weight);
        up.y = (f32)(side.y * side_weight) + (f32)(up.y * up_weight);
        up.z = (f32)(side.z * side_weight) + (f32)(up.z * up_weight);
        lbl_8006D668(&up);
        rot_x = effect->unk_54;
        rot_z = effect->unk_58;
        lbl_8006D8D8(-effect->unk_56);
        mathutil_mtxA_rotate_x(0);
        lbl_8006E1C0(&up, &up);
        effect->unk_54 = lbl_8006D24C(up.z, up.y);
        z = up.z;
        len = z * z;
        y = up.y;
        len += y * y;
        effect->unk_58 = -lbl_8006D24C(up.x, lbl_8006D0B4(len));
        effect->unk_5a >>= 2;
        effect->unk_5a += (effect->unk_54 - rot_x) >> 2;
        effect->unk_5c -= effect->unk_5c >> 4;
        effect->unk_5e >>= 2;
        effect->unk_5e += (effect->unk_58 - rot_z) >> 2;
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_648DC */

/* fzgx:begin fn_1_64E1C */
void fn_1_64E1C(void * arg0) {
    f32 v0;
    u32 v1;
    f32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    struct { f32 a[3]; } loc_8;
    v0 = *(f32 *)((u8 *)arg0 + 44);
    v1 = *(u32 *)((u8 *)arg0 + 52);
    loc_8.a[0] = (*(f32 *)((u8 *)arg0 + 60) + (f32)(v0 * *(f32 *)((u8 *)arg0 + 160)));
    loc_8.a[1] = (*(f32 *)((u8 *)arg0 + 64) + (f32)(v0 * *(f32 *)((u8 *)arg0 + 164)));
    v2 = *(f32 *)((u8 *)arg0 + 68);
    loc_8.a[2] = (v2 + (f32)(v0 * *(f32 *)((u8 *)arg0 + 168)));
    v3 = *(f32 *)((u8 *)arg0 + 40);
    lbl_8006D9D8(&loc_8);
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 86));
    mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg0 + 84));
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 88));
    lbl_8006E14C(v3);
    fn_1_55FC4(v3);
    fn_80072558();
    v4 = *(u32 *)((u8 *)arg0 + 16);
    if ((s32)v4 < 20) {
        v5 = (0.05f * (s32)v4);
    } else {
        v5 = 1.0f;
    }
    fn_1_55FF0(v5);
    fn_1_55210((void *)v1);
}
/* fzgx:end fn_1_64E1C */

/* fzgx:begin fn_1_64F2C */
/* fzgx-allow: S2 pool primer sink */

void fn_1_64F2C(Fn_1_64F2C_Object *obj) {
    f32 random;
    f32 scaled;
    f32 offset;

    if (obj->unk_10 == 0) {
{
    u32 value;
        value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = value;
        random = ((value >> 16) & 0x7fff) / 32767.0f;
}
        scaled = 0.25f * random;
        offset = 0.3f + scaled;
        obj->unk_10 = (60.0f * offset);
    }
}
/* fzgx:end fn_1_64F2C */

/* fzgx:begin fn_1_64FB8 */
void fn_1_64FB8(void *arg0) {
    ClosureEffectMatrix matrix;
    ClosureEffectVec position;
    ClosureEffectVec offset;
    ClosureEffectVec displacement;
    u8 *p=arg0;
    u8 *entry;
    f32 f9,gain,v0,v1,v2;
    u32 random;
    *(s16 *)(p+0x5a) *= (0.980000019f);
    *(s16 *)(p+0x5c) *= (0.980000019f);
    entry=fn_1_86254(*(s16 *)(p+0x18));
    fn_1_862D4(*(s16 *)(p+0x18),&position);
    fn_1_8636C(*(s16 *)(p+0x18),&matrix);
    lbl_8006DC6C(&matrix);
    {
        f32 z,y,x;
        x=position.x; y=position.y; z=position.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    if((s8)entry[0x475] != -1 && fn_1_6EC0(entry[0x475]) && camera_get_entry_field_0xa4(entry[0x475])==0) {
        ClosureEffectVec default_displacement = {0.0f, 0.0f, 0.0f};
        default_displacement.z=-3.0f;
        displacement=default_displacement;
        lbl_8006E1B0(&displacement,&displacement);
        {
            f32 z,y,x;
            x=displacement.x; y=displacement.y; z=displacement.z;
            mtx_set_translate((void *)LC_BASE, x, y, z);
        }
    }
    *(s16 *)(p+0x54)+=*(s16 *)(p+0x5a);
    *(s16 *)(p+0x56)+=*(s16 *)(p+0x5c);
    mathutil_mtxA_rotate_y(*(s16 *)(p+0x56));
    mathutil_mtxA_rotate_x(*(s16 *)(p+0x54));
    {
        ClosureEffectVec default_offset = {0.0f, 0.0f, 0.0f};
        default_offset.z=0.5 * -*(f32 *)(p+0x28);
        offset=default_offset;
    }
    lbl_8006E1B0(&offset,p+0x3c);
    *(f32 *)(p+0x28)=*(f32 *)(p+0x28)+(f32)(0.01f*(*(f32 *)(p+0x2c)-*(f32 *)(p+0x28)));
    *(f32 *)(p+0xb4)=0.5f*(f32)*(s32 *)(p+0x10);
    random=(lbl_1_data_1D628)*1103515245u+12345u;
    lbl_1_data_1D628=random;
    gain=0.8f+(f32)(0.2f*(((random>>16)&0x7fffu)/32767.0f));
    *(f32 *)(p+0x1c)=(255.0f*(0.5f*(1.0f+gain)))/255.0f;
    {
        f32 spread=(136.0f*gain)/255.0f;
        *(f32 *)(p+0x20)=spread;
        *(f32 *)(p+0x24)=spread;
    }
}
/* fzgx:end fn_1_64FB8 */

/* fzgx:begin fn_1_65268 */
void fn_1_65268(Object *object) {
    u8 local[4];
    void *result;
    Event *event;

    fn_1_862D4(object->value, local);
    lbl_8006DCA4();
    if (fn_1_54E34(&object->embedded[0], object->amount) != 0) {
        result = fn_1_5448C(local);
        event = (Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->vtable = (void *)fn_1_652F4;
            event->owner = object;
            fn_1_5489C(result, event);
        }
    }
}
/* fzgx:end fn_1_65268 */

/* fzgx:begin fn_1_652F4 */
void fn_1_652F4(fn_1_652F4_Effect *effect) {
    u8 temp[0xc];
    ParticleData data;
    fn_1_652F4_EffectData *object;
    void *owner;
    void *manager;
    s16 level;

    object = effect->unk_08;
    fn_1_867CC(object->unk_18, temp);
    level = *(s16 *)((u8 *)fn_1_868C0(object->unk_18) + 0x3ba);
    owner = fn_1_86254(object->unk_18);
    if (level >= 3 && *(s8 *)((u8 *)owner + 0x475) == -1) {
        return;
    }
    manager = ((EffectRoot *)lbl_1_bss_38458->unk_8)->unk_120;
    lbl_8006D9D8(temp);
    lbl_8006D95C(object->unk_56);
    mathutil_mtxA_rotate_x(object->unk_54);
    memset(&data, 0, 0x40);
    lbl_8006DB74((u8 *)&data + 8);

    data.value = 0.70710677f * object->unk_28;
    data.color[0] = 255.0f * object->unk_1c;
    data.color[1] = 255.0f * object->unk_20;
    data.color[2] = 255.0f * object->unk_24;
    data.color[3] = 0xff;
    data.value2 = data.value;
    fn_1_9F914(&data, manager);
}
/* fzgx:end fn_1_652F4 */

/* fzgx:begin fn_1_65420 */
// fn_1_65420: empty in retail (single blr).

void fn_1_65420(void) {
}
/* fzgx:end fn_1_65420 */

/* fzgx:begin fn_1_65424 */
void fn_1_65424(fn_1_65424_EffectObject *object) {
    u32 next;

    if (object->unk_10 == 0) {
        next = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = next;
        object->unk_10 = (60.0f * (0.3f + (f32)(0.25f * (((next >> 16) & 0x7FFF) / 32767.0f))));
    }
}
/* fzgx:end fn_1_65424 */

/* fzgx:begin fn_1_654B0 */
/* Advances the shared linear congruential generator. */

#pragma opt_common_subs off

static inline f32 fn_1_654B0_operand_(f32 right, f32 left) { return left * right; }

static inline void advance_particle654B0(Particle654B0 *p)
{
    f32 * fzgx_live;
    f32 keep;

    keep = 1.0f - p->damp;
    fzgx_live = p->vel;
    fzgx_live[0] *= keep;
    fzgx_live = p->vel;
    fzgx_live[1] *= keep;
    fzgx_live = p->vel;
    fzgx_live[2] *= keep;
    p->rotVel[0] = fn_1_654B0_operand_((0.98f), (p->rotVel[0]));
    p->rotVel[1] = fn_1_654B0_operand_((0.98f), (p->rotVel[1]));
    fzgx_live = p->vel;
    p->pos[0] += fzgx_live[0];
    fzgx_live = p->vel;
    p->pos[1] += fzgx_live[1];
    fzgx_live = p->vel;
    p->pos[2] += fzgx_live[2];
    p->rot[0] += p->rotVel[0];
    p->rot[1] += p->rotVel[1];
    p->scale += p->scaleVel;
    p->halfAge = fn_1_654B0_operand_(p->age, (0.5f));
    p->damp = p->damp + (fn_1_654B0_operand_(((p->dampTarget - p->damp)), (0.03f)));

}

static inline u32 random_bits654B0(void)
{
    /* fzgx-allow: shared generator accesses retain their ordering. */
    return ((lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345) >> 16) & 0x7FFFu;
}

static inline f32 random_float654B0(f32 bits)
{
    return bits / 32767.0f;
}

void fn_1_654B0(Particle654B0 *p)
{
    f32 v;
    f32 fade;

    advance_particle654B0(p);
    v = 0.8f + (fn_1_654B0_operand_((random_float654B0(random_bits654B0())), (0.2f)));
    p->r = fn_1_654B0_operand_(((0.5f * (1.0f + v))), (255.0f)) / 255.0f;
    p->g = fn_1_654B0_operand_(v, (136.0f)) / 255.0f;
    p->b = 0.0f;

    if (p->age < 25) {
        p->r *= fade = 1.0f - (1.0f + fn_1_654B0_operand_(p->age, (-0.04f)));
        p->g *= fade;
        p->b *= fade;
    }
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_654B0 */

/* fzgx:begin fn_1_656C8 */
// Initializes the effect and queues an event when its embedded state is ready.

void fn_1_656C8(fn_1_656C8_EffectObject *object) {
    void *result;
    EffectEvent *event;

    lbl_8006DCA4();
    if (fn_1_54E34(&object->unk_3c, object->unk_28) != 0) {
        result = fn_1_5448C(&object->unk_3c);
        event = (EffectEvent *)fn_1_548AC(0xc);
        if (event != 0) {
            event->unk_04 = (void *)fn_1_65748;
            event->unk_08 = object;
            fn_1_5489C( (void **)(result), (void **)(event));
        }
    }
}
/* fzgx:end fn_1_656C8 */

/* fzgx:begin fn_1_65748 */
/* The translation column of the locked-cache matrix. The chained copy (the stcoli.c fn_1_1EBD4 idiom) keeps the
 * matrix base a named value, numbered ahead of the .rodata pool base, so MWCC gives effect r31 and the pool base
 * r30 as retail does. */

static inline void fn_1_65748_lc_pos(fn_1_65748_Vec *out) {
    f32 *m;
    f32 *t;
    m = t = (f32 *)LC_BASE;
    psvec_set(out, t[11], m[7], m[3]);
}

void fn_1_65748(fn_1_65748_Event *event) {
    fn_1_65748_Vec axis;
    fn_1_65748_Light light;
    u8 mtx[0x30];
    fn_1_65748_Effect *effect;
    fn_1_65748_Model *model;
    f32 red;
    f32 green;
    f32 blue;
    f32 radius;
    f32 brightness;
    f32 base;
    f32 dist;
    u8 b;

    effect = event->unk_8;
    model = ((fn_1_65748_Assets *)lbl_1_bss_38458->unk_8)->unk_A8;
    base = 0.1f * effect->unk_B4;
    brightness = 255.0f * ((0.125f + (f32)(0.5f * base)) * (1.0f + (((lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039) >> 16) & 0x7fff) / 32767.0f));

    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    fn_80073778(model->tex, 0);

    memset(&light, 0, sizeof(light));
    red = brightness * effect->unk_1C;
    green = brightness * effect->unk_20;
    blue = brightness * effect->unk_24;
    light.color[0] = __OSf32tou8(red);
    light.color[1] = __OSf32tou8(green);
    b = __OSf32tou8(blue); /* retail stores the alpha byte before blue's */
    light.color[3] = 0xff;
    light.color[2] = b;
    lbl_8006D9D8(&effect->unk_3C);
    lbl_8006D7B0();
    radius = 2.0 * effect->unk_28;
    if (fn_1_54E34(&model->pos, radius) != 0) {
        fn_1_65748_lc_pos(&axis);
        /* squared length; the asm block above blocks fp contraction, so fuse explicitly */
        dist = axis.x * axis.x;
        dist = __fmadds(axis.y, axis.y, dist);
        dist = lbl_8006D0B4(__fmadds(axis.z, axis.z, dist));
        if (dist > 0.1f + radius) {
            lbl_8006DB74(mtx);
            lbl_8006D848((dist - radius) / dist);
            lbl_8006DFC4(mtx);
        }
        light.pos = model->pos;
        light.radius = 0.70710677f * radius;
        light.flags = 0;
        fn_1_9EA94(&light);
    }
}
/* fzgx:end fn_1_65748 */

/* fzgx:begin fn_1_65AAC */
// fn_1_65AAC: empty in retail (single blr).

void fn_1_65AAC(void) {
}
/* fzgx:end fn_1_65AAC */

/* fzgx:begin fn_1_65AB0 */
static inline f32 clampf_65AB0(f32 x, f32 lo, f32 hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

void fn_1_65AB0(Fn165AB0Object *obj) {
    f32 zero = 0.0f;

    if (obj->value_b4 == zero) {
        obj->value_b4 = 1.0f;
    }
    if (obj->value_b4 > 1.0f) {
        obj->value_2c = obj->value_2c * obj->value_b4;
        obj->value_10 = obj->value_10 * clampf_65AB0(obj->value_b4 / 7.0f, 1.0f, 1.2f);
    }
}
/* fzgx:end fn_1_65AB0 */

/* fzgx:begin fn_1_65B58 */
// fn_1_65B58: empty in retail (single blr).

void fn_1_65B58(void) {
}
/* fzgx:end fn_1_65B58 */

/* fzgx:begin fn_1_65B5C */
void fn_1_65B5C(EffP *p) {
    p->f48 *= 0.98f;
    p->f4c *= 0.98f;
    p->f50 *= 0.98f;
    p->f3c += p->f48;
    p->f40 += p->f4c;
    p->f44 += p->f50;
    if (p->f28 > 50.0f * (p->fb4 / 2.0f)) {
        p->f2c *= 0.9200000137090683; /* the retail double (0.4f * 2.3 gives the same bits) */
    }
    p->f28 += p->f2c;
    if (p->fb4 > 1.0f) {
        s32 n = p->i10;
        if (n < 50) {
            p->f1c = p->f1c * (1.0f - (1.0f + (f32)(-0.02 * n)));
            p->f20 = p->f20 * (1.0f - (1.0f + (f32)(-0.02 * n)));
            p->f24 = p->f24 * (1.0f - (1.0f + (f32)(-0.02 * n)));
        }
    } else {
        s32 n = p->i10;
        if (n < 40) {
            p->f1c = p->f1c * (1.0f - (1.0f + (f32)(-0.025f * n)));
            p->f20 = p->f20 * (1.0f - (1.0f + (f32)(-0.025f * n)));
            p->f24 = p->f24 * (1.0f - (1.0f + (f32)(-0.025f * n)));
        }
    }
}
/* fzgx:end fn_1_65B5C */

/* fzgx:begin fn_1_65CDC */
void fn_1_65CDC(struct Fn1_65CDC *self) {
	struct Fn1_65CDCWork work;
	struct Fn1_65CDCTmp tmp;
	u32 object;
	f32 radius;
	f32 distance;
	f32 alpha;
	f32 v[3];
	object = self->object34;
	radius = self->value28;
	lbl_8006D9D8(&self->value3c);
	lbl_8006D7B0();
	mathutil_mtxA_rotate_z(self->value58);
	psvec_set(v, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
distance = lbl_8006D0B4(effect_sum_sq(v[0], v[1], v[2]));
if (distance > 0.1f + radius) {
		lbl_8006DB74(&tmp);
		lbl_8006D848((distance - radius) / distance);
		lbl_8006DFC4(&tmp);
	}
	memset(&work, 0, 0x40);
	lbl_8006DB74(&work.sub);
	alpha = 0.70710677f * self->value28;
	work.alpha = alpha;
	work.red = (255.0f * self->value1c);
	work.green = (255.0f * self->value20);
	work.blue = (255.0f * self->value24);
	work.alphaByte = 0xff;
	work.alpha2 = alpha;
	fn_1_9F914(&work, (const void *)object);
}
/* fzgx:end fn_1_65CDC */

/* fzgx:begin fn_1_65E58 */
void fn_1_65E58(fn_1_65E58_Effect *effect) {
    effect->field_10 = 10;
    fn_1_8636C(effect->field_18, (u8 *)effect + 0xb8);
}
/* fzgx:end fn_1_65E58 */

/* fzgx:begin fn_1_65E88 */
// fn_1_65E88: empty in retail (single blr).

void fn_1_65E88(void) {
}
/* fzgx:end fn_1_65E88 */

/* fzgx:begin fn_1_65E8C */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@4b722344) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TYPES_H

#define GAME_VEC3_H

/* fzgx-allow: S2 pool primer sink */

void fn_1_65E8C(Effect65E8C *eff) {
    s32 moving;
    s32 t;
    f32 bob;
    u8 mtx[0x30];
    Fn183D28Vec3 pos;
    Fn183D28Vec3 arg;
    Fn183D28Vec3 v;

    moving = 0;
    if (eff->owner->active != 0) {
        t = eff->timer;
        moving = 1;
        if (t < 20) {
            eff->timer = t + 2;
        } else {
            eff->timer = t + 1;
        }
    }
    fn_1_862D4(eff->mtxId, (Triple *)&pos);
    fn_1_8636C(eff->mtxId, mtx);
    if (moving != 0) {
        bob = 0.3 * lbl_8006D188((182.04444885253906f * lbl_801A66A0));
        lbl_8006DC6C(mtx);
        /* set the current matrix's translation */
        {
        f32 z, y, x;
        x = pos.x;
        y = pos.y;
        z = pos.z;
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
        {
            Fn183D28Vec3 init = {0.0f, 0.0f, 0.0f};
            v = init;
        }
        v.y = 5.0 + bob;
        arg = v;
        lbl_8006E1B0(&arg, &eff->pos);
    } else {
        eff->velX *= 0.98;
        eff->velY *= 0.98;
        eff->velZ *= 0.98;
    }
    eff->spinScale = 768.0f * lbl_8006D188((182.04444885253906f * lbl_801A66A0));
    eff->rotY += eff->velY;
    eff->rotZ += eff->velZ;
    lbl_8006DB74(eff->unk_B8);
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef GAME_VEC3_H
/* fzgx:end fn_1_65E8C */

/* fzgx:begin fn_1_660EC */
/* fzgx-allow: S2 pool primer sink */

void fn_1_660EC(ObjFx_T *this)
{
    u8 *sub = this->unk_38;
    f32 scale;
    u32 g;
    u32 buf[12];

    scale = (this->unk_10 < 0x14) ? 0.05f * this->unk_10 : 1.0f;
    lbl_8006D7F4(((lbl_801A66A0 % 30)) / 29.0f, 0.0f, 0.0f);
    lbl_8006DB74(buf);
    g = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x1F0);
    lbl_8006D9D8(&this->pad_3C[0]);
    lbl_8006DFC4(sub + 0xEC);
    mathutil_mtxA_rotate_y(this->unk_56);
    mathutil_mtxA_rotate_x(this->unk_54);
    mathutil_mtxA_rotate_z(this->unk_58);
    lbl_8006E14C(0.5f);
    fn_1_55FC4(0.5f);
    fn_80072558();
    fn_1_55FF0(scale);
    fn_1_56018(1);
    fn_1_560F0(0, buf);
    fn_1_55210((void *)g);
    fn_1_56018(0);
}
/* fzgx:end fn_1_660EC */

/* fzgx:begin fn_1_66254 */
void fn_1_66254(fn_1_66254_output *output) {
    u32 *state;
    u32 seed;
    u32 value;
    f32 coordinate;
    f32 field_2c;
    f32 field_28;

    state = &lbl_1_data_1D628;
    seed = *state;
    value = seed * 0x41c64e6d;
    value += 0x3039;
    coordinate = 0.8f + (f32)(0.2f * (((value >> 16) & 0x7fff) / 32767.0f));
    *state = value;
    field_2c = 3.5f * coordinate;
    field_28 = 0.5f * coordinate;
    output->field_2c = field_2c;
    output->field_28 = field_28;
}
/* fzgx:end fn_1_66254 */

/* fzgx:begin fn_1_662D4 */
// fn_1_662D4: empty in retail (single blr).

void fn_1_662D4(void) {
}
/* fzgx:end fn_1_662D4 */

/* fzgx:begin fn_1_662D8 */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@842a08a9) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

static inline u16 effect_rand(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
    return (lbl_1_data_1D628 >> 16) & 0x7FFF;
}

static inline s32 effect_rand2(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 13259;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#define effect_random() ((f32)effect_rand() / 32767.0f)

#define effect_random2() ((f32)effect_rand2() / 32767.0f)

static inline void effect_cross_store(const Fn183D28Vec3 *a, const Fn183D28Vec3 *b, Fn183D28Vec3 *out) {
    f32 ax, ay, az;
    f32 x, y, z;
    ay = a->y;
    az = a->z;
    ax = a->x;
    x = (ay * b->z);
    y = (az * b->x);
    z = (ax * b->y);
    x = x - az * b->y;
    y = y - ax * b->z;
    z = z - ay * b->x;
    /* The cross-product intermediate is materialized in the retail frame. */
    out->x = x;
    /* Materialize the cross-product y component. */
    out->y = y;
    /* Materialize the cross-product z component. */
    *(volatile f32 *)&out->z = z;
}

#define effect_cross(a, b, out) effect_cross_store(a, b, out)

static inline u32 effect_aux_jitter(Fn183D28Vec3 *v) {
    f32 x, y;
    u32 z;
    x = effect_random();
    y = effect_random();
    v->x += (f32)(0.25f * (x - 0.5f));
    /* Materialize the y component before the remaining RNG samples. */
    *(volatile f32 *)&v->y = v->y + (f32)(0.25f * (f32)(y - 0.5f));
    z = effect_rand();
    return z;
}

static inline f32 effect_size_random(u32 sample) {
    f32 z = sample / 32767.0f;
    return z;
}

static inline s32 effect_slot(void) {
    s32 i;
    Fn662D8Effect *p = *(Fn662D8Effect **)&lbl_1_bss_6C848;
    for (i = 0; i < 190; i++, p++) {
        if (p->active == 0) {
            p->active = 1;
            return i;
        }
    }
    return -1;
}

static inline void effect_emit(Fn662D8Effect *src) {
    s32 i;
    Fn662D8Effect *dst;
    if (fn_1_3FC58() == 0) {
        i = effect_slot();
        if (i >= 0) {
            dst = *(Fn662D8Effect **)&lbl_1_bss_6C848 + i;
            memcpy(dst, src, 0xE8);
            dst->active = 1;
            dst->index = i;
            lbl_1_data_1D1D8[dst->type](dst);
            dst->serial = lbl_1_bss_6C850;
            if (++lbl_1_bss_6C850 < 0) lbl_1_bss_6C850 = 0;
        }
    }
}

#define unk_28 param_28

#define unk_2C param_2C

#define drift vel

#define velocity anchor

static inline f32 effect_multiply(f32 a, f32 b) {
    return a * b;
}

static inline f32 effect_sqnorm(const Fn183D28Vec3 *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    f32 result = x * x;
    result = y * y + result;
    result = z * z + result;
    return result;
}

void fn_1_662D8(Fn662D8Source *arg0) {
    s16 angle_y;
    s16 v0;
    f32 v1, v2, v8, v9;
    u8 v13;
    f32 speed_factor;
    f32 velocity_factor;
    f32 size_factor;
    f32 random_z, random_y, random_x;
    f32 random_aux_z;
    Fn662D8Effect effect;
    struct { u32 a[12]; } loc_5C;
    Fn183D28Vec3 loc_50;
    struct Sig_fn_1_862A8_fn_1_862A8_Arg1 loc_44;
    Triple loc_38;
    Sig_fn_1_8658C_Vec3U32 loc_2C;
    Fn183D28Vec3 loc_20;
    Fn183D28Vec3 loc_14;
    f32 t4;
    f32 t5;
    f32 tz, ty, tx;
    f64 clamped;
    v0 = arg0->car;
    fn_1_8636C(v0, &loc_5C);
    fn_1_862D4(v0, &loc_38);
    fn_1_862A8(v0, &loc_44);
    fn_1_8658C(v0, &loc_2C);
    t4 = fn_1_8652C(arg0->car);
    if (t4 < 100.0f) {
        if (effect_rand() % 3 != 0) return;
    } else {
        if (effect_rand() % 3 == 0) return;
    }
    v8 = arg0->unk_28;
    arg0->unk_28 = v8 + (f32)(0.01f * (arg0->unk_2C - v8));
    t5 = lbl_8006D0B4(effect_sqnorm(&arg0->velocity));
    v2 = t5;
    if (v2 < 0.0f) v2 = 0.0f;
    else if (v2 > 0.7f) v2 = 0.7f;
    lbl_8006D5F0(&arg0->velocity, &loc_50, v2);
    lbl_8006DC6C(&loc_5C);
    tx = *(f32 *)(&loc_38);
    ty = *(f32 *)((u8 *)&loc_38 + 4);
    tz = *(f32 *)((u8 *)&loc_38 + 8);
    mtx_set_translate((void *)LC_BASE, tx, ty, tz);
    lbl_8006E1B0(&loc_50, &loc_50);
    arg0->pos = loc_50;
    psvec_sub(&loc_38, &loc_2C, &arg0->drift);
    if (t4 < 500.0f) v13 = 1;
    if (500.0f <= t4 && t4 < 800.0f) v13 = 2;
    if (800.0f <= t4 && t4 < 1000.0f) v13 = 2;
    if (1000.0f <= t4) v13 = 2;
    while (v13) {
        memset(&effect, 0, 0xE8);
        {
        f32 pz, py, px;
        f32 randvz;
        f32 spread = 0.4f;
        f32 rvz, rvy, rvx;
        effect.car = arg0->car;
        effect.type = 29;
        effect.mode = 0xFFFF;
        effect.asset = ((Fn662D8Assets *)lbl_1_bss_38458->unk_8)->unk_148;
        effect.color_x = 255.0f;
        effect.color_y = 102.0f;
        effect.color_z = 0.0f;
        effect.pos = loc_50;
        px = effect.pos.x;
        py = effect.pos.y;
        pz = effect.pos.z;
        effect.vel = arg0->drift;
        random_x = 60.0f * (0.9f + (f32)(0.6f * effect_random()));
        effect.life = random_x;
        effect.vel.x += (f64)(spread * (effect_random() - 0.5));
        randvz = effect_random();
        effect.vel.z += (f64)(spread * (randvz - 0.5));
        velocity_factor = t4 / 2500.0f;
        effect.vel.x += (f32)((*(Fn183D28Vec3 *)&loc_44).x * velocity_factor);
        effect.vel.y += (f32)((*(Fn183D28Vec3 *)&loc_44).y * velocity_factor);
        effect.vel.z += (f32)((*(Fn183D28Vec3 *)&loc_44).z * velocity_factor);
        effect.pos.x = px - effect.vel.x;
        effect.pos.y = py - effect.vel.y;
        effect.pos.z = pz - effect.vel.z;
        }
        speed_factor = t4 / 500.0f;
        clamped = speed_factor < 0.0 ? 0.0 : speed_factor > 2.5f ? 2.5f : speed_factor;
        effect.param_28 = 0.1 + clamped;
        effect.param_2C = 30.0 + (f64)(5.0 * effect_random());
        size_factor = 0.8f + (f32)(0.2f * effect_random());
        effect.color_x = (255.0f * (0.5f * (1.0f + size_factor))) / 255.0f;
        effect.color_y = (224.0f * size_factor) / 255.0f;
        effect.color_z = (176.0f * size_factor) / 255.0f;
        effect.param_88 = 0.0003 * effect_random();
        effect.param_8C = (0.02 + t4 / 1000.0f);
        effect.unk_AC = 364;
        effect_emit(&effect);
        memset(&effect, 0, 0xE8);
        effect.type = 22;
        effect.mode = 0xFFFF;
        effect.asset = ((Fn662D8Assets *)lbl_1_bss_38458->unk_8)->unk_168;
        effect.pos.x = loc_50.x + (f64)(0.20000000298023224 * (effect_random() - 0.5));
        effect.pos.y = loc_50.y + (f64)(0.20000000298023224 * (effect_random() - 0.5));
        effect.pos.z = loc_50.z + (f64)(0.20000000298023224 * (effect_random() - 0.5));
        effect.vel = arg0->drift;
        effect.pos.x -= effect.vel.x;
        effect.pos.y -= effect.vel.y;
        effect.pos.z -= effect.vel.z;
        size_factor = 0.8f + (f32)(0.2f * effect_random());
        effect.param_2C = 3.5f * size_factor;
        clamped = speed_factor < 0.0 ? 0.0 : speed_factor > 2.5f ? 2.5f : speed_factor;
        effect.color_z = 0.0f;
        effect.param_28 = size_factor * (0.5 + clamped);
        size_factor = 0.8f + (f32)(0.2f * effect_random());
        effect.life = 22;
        effect.angle_z = effect_rand();
        effect.color_x = (255.0f * (0.5f * (1.0f + size_factor))) / 255.0f;
        effect.color_y = (136.0f * size_factor) / 255.0f;
        effect_emit(&effect);
        v13--;
    }
    memset(&effect, 0, 0xE8);
    effect.car = arg0->car;
    effect.type = 16;
    effect.mode = 1;
    effect.angle_x = effect_rand();
    {
        angle_y = effect_rand();
        effect.angle_y = angle_y;
        effect.unk_5A = (16.0f + (f32)(4096.0f * effect_random()));
        effect.unk_5C = (16.0f + (f32)(4096.0f * effect_random()));
    }
    effect.param_28 = 3.0f * (0.4f + (f32)(0.6f * effect_random2()));
    effect.param_2C = 6.0f * (0.8f + (f32)(0.2f * effect_random2()));
    lbl_8006DC6C(&loc_5C);
    {
        f32 z, y, x;
        x = *(f32 *)(&loc_38);
        y = *(f32 *)((u8 *)&loc_38 + 4);
        z = *(f32 *)((u8 *)&loc_38 + 8);
        mtx_set_translate((void *)LC_BASE, x, y, z);
    }
    mathutil_mtxA_rotate_y(effect.angle_y);
    mathutil_mtxA_rotate_x(effect.angle_x);
    {
        Fn183D28Vec3 loc_8 = {0.0f, 0.0f, 0.0f};
        loc_8.z = -effect.param_28;
        loc_20 = loc_8;
        lbl_8006E1B0(&loc_20, &effect.pos);
    }
    effect.anchor.x = (0.5f * (effect.pos.x + (*(Fn183D28Vec3 *)&loc_38).x));
    effect.anchor.y = (0.5f * (effect.pos.y + (*(Fn183D28Vec3 *)&loc_38).y));
    effect.anchor.z = (0.5f * (effect.pos.z + (*(Fn183D28Vec3 *)&loc_38).z));
    effect.aux.x = arg0->drift.x;
    effect.aux.y = arg0->drift.y;
    effect.aux.z = arg0->drift.z;
    {
        u32 sample = effect_aux_jitter(&effect.aux);
        random_aux_z = effect_size_random(sample);
        effect.aux.z += (f32)(0.25f * (random_aux_z - 0.5f));
        v9 = effect_size_random(effect_rand());
        size_factor = 0.8f + effect_multiply(0.2f, v9);
        effect.color_x = effect_multiply((255.0f * (0.5f * (1.0f + size_factor))) / 255.0f, 1.0f);
        size_factor = (85.0f * size_factor) / 255.0f;
        effect.color_y = size_factor;
        effect.color_z = effect_multiply(size_factor, 0.0f);
    }

    {
        effect_cross(&arg0->drift, &effect.aux, &loc_14);
        effect.direction.x = loc_14.x + (f32)(0.4f * (f32)(effect_random() - 0.5f));
        effect.direction.y = loc_14.y + (f32)(0.4f * (f32)(effect_random() - 0.5f));
        effect.direction.z = loc_14.z + (f32)(0.4f * (f32)(effect_random() - 0.5f));
    }
    lbl_8006D668((Sig_fn_8006FA24_Basis *)&effect.direction);
    effect.unk_AC = 24;
    effect_emit(&effect);
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GAME_MAIN_REL_CAR_TYPES_H
#undef effect_random
#undef effect_random2
#undef effect_cross
#undef unk_28
#undef unk_2C
#undef drift
#undef velocity
/* fzgx:end fn_1_662D8 */

/* fzgx:begin fn_1_67294 */
void fn_1_67294(Obj_67294 *arg0)
{
	Vec3_67294 v;
	Buf buf;
	VecObj o;
	Ctx *ctx;
	f32 a;
	f32 d;
	f32 s;
	u32 g;
	Obj_67294 *t = arg0;

	ctx = *(Ctx **)&lbl_1_bss_38458->unk_8;
	g = ctx->unk_168;
	a = t->unk_28;
	lbl_8006D9D8(&t->unk_3C);
	lbl_8006D7B0();
	psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
	d = lbl_8006D0B4(effect_sum_sq(v.x, v.y, v.z));
	if (d > 0.1f + a) {
		lbl_8006DB74(&o);
		lbl_8006D848((d - a) / d);
		lbl_8006DFC4(&o);
	}
	memset(&buf, 0, 0x40);
	lbl_8006DB74(&buf.unk_8);
	s = 0.70710677f * t->unk_28;
	buf.unk_0 = s;
	buf.unk_3C = (255.0f * t->unk_1C);
	buf.unk_3D = (255.0f * t->unk_20);
	buf.unk_3E = (255.0f * t->unk_24);
	buf.unk_3F = 0xFF;
	buf.unk_4 = s;
	fn_1_9F914(&buf, (const void *)g);
}
/* fzgx:end fn_1_67294 */

/* fzgx:begin fn_1_67414 */
void fn_1_67414(struct fn_1_67414_Arg0 *arg0) {
    arg0->unk_10 = 30;
    arg0->unk_b4 = 0.1f;
}
/* fzgx:end fn_1_67414 */

/* fzgx:begin fn_1_6742C */
// fn_1_6742C: empty in retail (single blr).

void fn_1_6742C(void) {
}
/* fzgx:end fn_1_6742C */

/* fzgx:begin fn_1_67430 */
void fn_1_67430(Obj67430 *p)
{
    Vec3fBig   v1;
    Vec3f_67430      v0;
    f32        c, b, a;
    f32        old;
    f64        t;

    if (((fn_1_86514(p->unk18) >> 29) & 1) == 0) {
        p->unk10 = 1;
    }
    fn_1_862D4(p->unk18, &v0);
    fn_1_8636C(p->unk18, &v1);
    p->v48.x *= 0.98;
    p->v48.y *= 0.98;
    p->v48.z *= 0.98;
    psvec_add(&p->v94, &p->v48, &p->v94);
    lbl_8006DC6C(&v1);
    a = v0.x;
    b = v0.y;
    c = v0.z;
    mtx_set_translate((void *)LC_BASE, a, b, c);
    lbl_8006E1B0(&p->v94, &p->v3c);
    old = p->f28;
    t = 0.02 * (p->f2c - old);
    p->f28 = old + t;
    t = 0.05 * (1.0 - p->fb4);
    p->fb4 = p->fb4 + t;
}
/* fzgx:end fn_1_67430 */

/* fzgx:begin fn_1_6755C */
void fn_1_6755C(FnObj_6755C *obj) {
    u8 temp[0x30];
    Buf buf;
    f32 s;
    u32 manager;

    manager = ((Root_6755C *)lbl_1_bss_38458->unk_8)->unk_120;
    fn_1_8636C(obj->unk_18, temp);
    lbl_8006D9D8((u8 *)obj + 0x3c);
    lbl_8006DFC4(temp);
    lbl_8006D95C(0);
    mathutil_mtxA_rotate_x(0x4000);
    memset(&buf, 0, 0x40);
    lbl_8006DB74(&buf.unk_8);
    s = 0.70710677f * obj->unk_28;
    buf.unk_0 = s;
    buf.unk_3C = 255.0f * obj->unk_1c * obj->unk_b4;
    buf.unk_3D = 255.0f * obj->unk_20 * obj->unk_b4;
    buf.unk_3E = 255.0f * obj->unk_24 * obj->unk_b4;
    buf.unk_3F = 0xFF;
    buf.unk_4 = s;
    fn_1_9F914(&buf, (const void *)manager);
}
/* fzgx:end fn_1_6755C */

/* fzgx:begin fn_1_6766C */
void fn_1_6766C(Fn6766CObject *object) {
    object->value = 1.0f;
}
/* fzgx:end fn_1_6766C */

/* fzgx:begin fn_1_6767C */
// fn_1_6767C: empty in retail (single blr).

void fn_1_6767C(void) {
}
/* fzgx:end fn_1_6767C */

/* fzgx:begin fn_1_67680 */
#define F(p,n) (*(f32 *)((u8 *)(p)+(n)))

#define S(p,n) (*(s16 *)((u8 *)(p)+(n)))

#define U(p,n) (*(u16 *)((u8 *)(p)+(n)))

#define I(p,n) (*(s32 *)((u8 *)(p)+(n)))

#define B(p,n) (*(s8 *)((u8 *)(p)+(n)))

#define V(p,n) (*(EffectVec *)((u8 *)(p)+(n)))

/* LCG random, 15 bits */

static inline u32 rand15(void) {
    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 12345;
    return (lbl_1_data_1D628 >> 16) & 0x7fff;
}

#define frand() ((f32)rand15() / 32767.0f)

/* claims the first free slot of a 190-entry pool, -1 when full */

static inline s32 alloc_slot(u8 *p) {
    s32 i;
    for (i = 0; i < 190; i++, p += 232) {
        if (B(p,0) == 0) {
            B(p,0) = 1;
            return i;
        }
    }
    return -1;
}

static inline void spawn(EffectPoolState *st, void *src, int bank) {
    s32 i;
    u8 *p;
    if ((s32)fn_1_3FC8C() != 0) return;
    if ((s32)fn_1_3FC58() != 0) return;
    i = alloc_slot(st->pool[bank]);
    if (i >= 0) {
        p = st->pool[bank] + i * 232;
        memcpy(p, src, 232);
        B(p,0) = 1;
        S(p,2) = i;
        ((void (**)(void *))lbl_1_data_1D1D8)[S(p,12)](p);
        S(p,4) = st->serial;
        if ((s16)++st->serial < 0) st->serial = 0;
    }
}

void fn_1_67680(void *arg0) {
    EffectPoolState *st = (EffectPoolState *)&lbl_1_bss_6C848;
    u8 loc_8[232];
    void *t0;
    s16 v16;
    u32 v17,v18,v36,v37,v41;
    s32 n;
    f32 v0,v3,v31,v33,v34,v35,v42,v45;
    f64 v43,v44,v47,v48;
    v0=1.0f-F(arg0,136);
    F(arg0,72)=F(arg0,72)*v0;
    F(arg0,76)=F(arg0,76)*v0;
    F(arg0,80)=F(arg0,80)*v0;
    F(arg0,76)+= -0.015;
    psvec_add((u8 *)arg0+60,(u8 *)arg0+72,(u8 *)arg0+60);
    v3=F(arg0,136);
    F(arg0,136)=v3+(f32)(0.03f*(F(arg0,140)-v3));
    if(I(arg0,16)<40) F(arg0,180)=(F(arg0,180)*(I(arg0,16)/40.0f));
    n=I(arg0,16);
    if(n<40) {
        /* the fade factor is re-spelled per component: MWCC CSEs the register-only expression */
        F(arg0,28)*=1.0f-(f32)(1.0f+(f32)(-0.025f*n));
        F(arg0,32)*=1.0f-(f32)(1.0f+(f32)(-0.025f*n));
        F(arg0,36)*=1.0f-(1.0f+(-0.025f*n));
    }
    t0=fn_1_86254(S(arg0,24));
    memset(loc_8,0,232);
    S(loc_8,24)=S(arg0,24);
    S(loc_8,12)=36;
    U(loc_8,26)=0xFFFF;
    I(loc_8,52)=I(lbl_1_bss_38458->unk_8,328);
    for(v16=1;v16>0;v16--) {
        V(loc_8,60)=V(arg0,60);
        V(loc_8,72)=V(arg0,72);
        I(loc_8,16)=(F(arg0,180)*(60.0f*(0.5f+(f32)(0.2f*frand()))));
        F(loc_8,72)*=0.9f;
        F(loc_8,76)*=0.9f;
        F(loc_8,80)*=0.9f;
        F(loc_8,60)-=F(loc_8,72);
        F(loc_8,64)-=F(loc_8,76);
        F(loc_8,68)-=F(loc_8,80);
        F(loc_8,40)=F(arg0,40)*(F(arg0,180)*(0.3f+(f32)(0.2f*frand())));
        F(loc_8,44)=F(arg0,40)*(F(arg0,180)*(10.0+(5.0f*frand())));
        v42=0.8f+(f32)(0.2f*frand());
        F(loc_8,28)=(255.0f*(0.5f*(1.0f+v42)))/255.0f;
        F(loc_8,32)=(224.0f*v42)/255.0f;
        F(loc_8,36)=(176.0f*v42)/255.0f;
        F(loc_8,136)=0.003*frand();
        F(loc_8,140)=0.02f;
        S(loc_8,172)=364;
        if(B(t0,1141)!=-1) spawn(st,loc_8,1);
        else spawn(st,loc_8,0);
    }
}
#undef F
#undef S
#undef U
#undef I
#undef B
#undef V
#undef frand
/* fzgx:end fn_1_67680 */

/* fzgx:begin fn_1_67D0C */
void fn_1_67D0C(Obj_67D0C *arg0)
{
	Vec3_67D0C v;
	Buf buf;
	VecObj o;
	Ctx_67D0C *ctx;
	f32 a;
	f32 d;
	f32 s;
	u32 g;
	Obj_67D0C *t = arg0;

	ctx = (*(Mid **)&lbl_1_bss_38458)->unk_8;
	g = ctx->unk_50;
	a = 0.3f * t->unk_B4;
	lbl_8006D9D8(&t->unk_3C);
	lbl_8006D7B0();
	psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
	d = lbl_8006D0B4(effect_sum_sq(v.x, v.y, v.z));
	if (d > 0.1f + a) {
		lbl_8006DB74(&o);
		lbl_8006D848((d - a) / d);
		lbl_8006DFC4(&o);
	}
	memset(&buf, 0, 0x40);
	lbl_8006DB74(&buf.unk_8);
	s = 0.70710677f * a;
	buf.unk_0 = s;
	buf.unk_3C = (255.0f * t->unk_1C);
	buf.unk_3D = (255.0f * t->unk_20);
	buf.unk_3E = (255.0f * t->unk_24);
	buf.unk_3F = 0xFF;
	buf.unk_4 = s;
	fn_1_9F914(&buf, (const void *)g);
}
/* fzgx:end fn_1_67D0C */

/* fzgx:begin fn_1_67E94 */
static inline f32 pool_pad(u32 sel) {
    switch (sel) {
    case 0: return 1.0f;
    case 1: return 2.0f;
    case 2: return 3.0f;
    case 3: return 4.0f;
    }
    return 0.0f;
}

void fn_1_67E94(u8 *object) {
    u32 value;

    if (*(s32 *)(object + 0x10) == 0) {
        value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = value;
        *(s32 *)(object + 0x10) = (s32)(60.0f *
            (0.2f + ((value & 0x7fff8000) >> 16) / 32767.0f));
    } else {
        pool_pad(value);
    }
    *(u16 *)(object + 0xae) = 0;
}
/* fzgx:end fn_1_67E94 */

/* fzgx:begin fn_1_67F20 */
void fn_1_67F20(Fn167F20 *obj) {
    obj->value48 *= 0.9f;
    obj->value4c *= 0.9f;
    obj->value50 *= 0.9f;
    obj->valueac *= 0.9f;
    obj->value48 += 0.001f;
    obj->value3c += obj->value48;
    obj->value40 += obj->value4c;
    obj->value44 += obj->value50;
    obj->valueae += obj->valueac;
    obj->value88 += (f32)(0.05f * (obj->value8c - obj->value88));
    obj->value28 += (f32)(0.01f * (obj->value2c - obj->value28));
    if (obj->state < 0x1e) {
        f32 rate = 0.01f;
        obj->value1c = -obj->value1c * rate;
        obj->value20 = -obj->value20 * rate;
        obj->value24 = -obj->value24 * rate;
    }
}
/* fzgx:end fn_1_67F20 */

/* fzgx:begin fn_1_68054 */
// Advances the effect and queues its completion callback when it finishes.

void fn_1_68054(fn_1_68054_EffectObject *effect) {
    f32 progress;
    void *source;
    fn_1_68054_EffectEntry *completion;

    progress = effect->value / 1e+01f;
    lbl_8006DCA4();

    if (fn_1_54E34(&effect->subobject, progress) == 0) {
        return;
    }

    source = fn_1_5448C(&effect->subobject);
    completion = (fn_1_68054_EffectEntry *)fn_1_548AC(0xc);
    if (completion == 0) {
        return;
    }

    completion->callback = (void *)fn_1_64388;
    completion->owner = effect;
    fn_1_5489C( (void **)(source), (void **)(completion));
}
/* fzgx:end fn_1_68054 */

/* fzgx:begin fn_1_680F4 */
// fn_1_680F4: empty in retail (single blr).

void fn_1_680F4(void) {
}
/* fzgx:end fn_1_680F4 */
