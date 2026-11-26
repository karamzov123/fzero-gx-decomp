#include "types.h"
#include "rel/main_rel/globals.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/vec3.h"
#include "psvec.h"
#include "mathutil_mtxA_set_translate.h"
#include "fpscr_floorf.h"
#include "rel/main_rel/camera.h"
#include "rel/main_rel/car_test.h"

/* fn_1_1384C */
typedef struct Fn1_1384C_Found Fn1_1384C_Found;

/* fn_1_1384C */
struct Fn1_1384C_Found {
    u8 pad_00[0x1A];
    u16 unk_1A;
    u16 unk_1C;
    u32 unk_20;
    u8 pad_24[0x1C];
};

/* fn_1_1384C */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x1C];
} Fn1_1384C_Bit;

/* fn_1_1384C */
typedef struct {
    Fn1_1384C_Found *unk_0;
    u8 *unk_4;
} Fn1_1384C_Ent;

/* fn_1_1384C */
typedef struct {
    s32 unk_0;
    u32 unk_4;
    Fn1_1384C_Ent *unk_8;
} Fn1_1384C_Sub;

/* fn_1_1384C */
typedef struct {
    Fn1_1384C_Sub *unk_0;
    u32 unk_4;
} Fn1_1384C_List;

/* fn_1_1384C */
typedef struct {
    u32 unk_0;
    u8 *unk_4;
    Fn1_1384C_Found *unk_8;
    u32 unk_C;
} Fn1_1384C_Elem;

/* fn_1_1384C */
typedef struct {
    u32 unk_0;
    s32 unk_4;
    Fn1_1384C_Elem *unk_8;
    u32 unk_C;
} Fn1_1384C_Group;

/* fn_1_1384C */
typedef struct Fn1_13A28 Fn1_13A28;

/* fn_1_1384C */
struct Fn1_13A28 {
    u8 unk_00[4];
    Fn1_13A28 *unk_04;
    Fn1_13A28 *unk_08;
    s32 unk_0c;
    Fn1_13A28 *unk_10;
    u8 unk_14[0x10];
    Fn1_13A28 *unk_24;
    Fn1_13A28 *unk_28;
    Fn1_13A28 *unk_2c;
    Fn1_13A28 *unk_30;
    Fn1_13A28 *unk_34;
    Fn1_13A28 *unk_38;
    Fn1_13A28 *unk_3c;
    Fn1_13A28 *unk_40;
    Fn1_13A28 *unk_44;
    u8 unk_48[8];
};

/* fn_1_1384C */
typedef struct ColiAnimTrack {
    s32 count;
    void *keys;
} ColiAnimTrack;

/* fn_1_1384C */
typedef struct ColiAnim {
    ColiAnimTrack tracks[6];
} ColiAnim;

/* fn_1_1384C */
typedef struct ColiBank {
    void **first;
    void **second;
} ColiBank;

/* fn_1_1384C */
typedef struct ColiExtra {
    u8 pad_0[0xC];
    f32 unk_C;
} ColiExtra;

/* fn_1_1384C */
typedef struct ColiObject {
    f32 x, y, z;
    s16 rx, ry, rz;
    u8 pad_12[2];
    ColiAnim *anim;
    f32 ox, oy, oz;
    void *unk_24;
    void **banks0[14];
    u8 pad_60[0x10];
    s32 columns;
    s32 rows;
    void *unk_78;
    void **banks1[14];
    u8 pad_B4[4];
    void *unk_B8;
    u8 pad_BC[4];
    void *unk_C0;
    u8 pad_C4[4];
    void *unk_C8;
    u8 pad_CC[4];
    void *unk_D0;
    u8 pad_D4[4];
    void *unk_D8;
    u8 pad_DC[4];
    void *unk_E0;
    u8 pad_E4[4];
    void *unk_E8;
    u8 pad_EC[8];
    ColiExtra *extra;
    u8 pad_F8[0xC];
    u32 flags;
    f32 unk_108;
    f32 unk_10C;
    ColiBank unk_110[2];
    u8 pad_120[0x4B0 - 0x120];
} ColiObject;

/* fn_1_1384C */
typedef struct ColiModelRef {
    u32 unk_0;
    void *unk_4;
    void *unk_8;
} ColiModelRef;

/* fn_1_1384C */
typedef struct ColiSub54Anim {
    u8 pad_0[0x30];
    void *unk_30;
    u8 pad_34[0x14];
    void *unk_48;
    u8 pad_4C[0x14];
    void *unk_60;
    u8 pad_64[0x14];
    void *unk_78;
    u8 pad_7C[0x14];
    void *unk_90;
    u8 pad_94[0x14];
    void *unk_A8;
    u8 pad_AC[0x14];
    void *unk_C0;
    u8 pad_C4[0x14];
    void *unk_D8;
    u8 pad_DC[0x14];
    void *unk_F0;
    u8 pad_F4[0x14];
    void *unk_108;
    u8 pad_10C[0x14];
    void *unk_120;
} ColiSub54Anim;

/* fn_1_1384C */
typedef struct ColiSub54Ptrs {
    void *unk_0;
    void *unk_4;
    void *unk_8;
    void *unk_C;
} ColiSub54Ptrs;

/* fn_1_1384C */
typedef struct ColiSub54C {
    u8 pad_0[0xC];
    void *unk_C;
} ColiSub54C;

/* fn_1_1384C */
typedef struct ColiSub54 {
    u8 pad_0[8];
    void *unk_8;
    u8 pad_C[0x24];
    ColiSub54Anim *unk_30;
    ColiSub54Ptrs *unk_34;
    ColiSub54C *unk_38;
    void *unk_3C;
} ColiSub54;

/* fn_1_1384C */
typedef struct ColiRec24 {
    void *unk_0;
    u8 pad_4[0x20];
} ColiRec24;

/* fn_1_1384C */
typedef struct ColiElem {
    u32 unk_0;
    void *unk_4;
    u8 pad_8[8];
} ColiElem;

/* fn_1_1384C */
typedef struct ColiGroupC {
    u8 pad_0[0x1C];
    void *unk_1C;
    void *unk_20;
} ColiGroupC;

/* fn_1_1384C */
typedef struct ColiGroup {
    u32 unk_0;
    s32 count;
    ColiElem *elems;
    ColiGroupC *unk_C;
} ColiGroup;

/* fn_1_1384C */
typedef struct ColiRec70 {
    void *unk_0;
    u8 pad_4[0x20];
    void *unk_24;
    u8 pad_28[4];
    void *unk_2C;
    u8 pad_30[4];
    void *unk_34;
    u8 pad_38[4];
    void *unk_3C;
    u8 pad_40[4];
    void *unk_44;
    u8 pad_48[4];
    void *unk_4C;
    u8 pad_50[4];
    void *unk_54;
    u8 pad_58[4];
    void *unk_5C;
    u8 pad_60[0x10];
} ColiRec70;

/* fn_1_1384C */
typedef struct ColiRecA0 {
    u8 pad_0[0xC];
    void *unk_C;
    u8 pad_10[4];
    void *unk_14;
    u8 pad_18[4];
    void *unk_1C;
    u8 pad_20[0x80];
} ColiRecA0;

/* fn_1_1384C */
typedef struct ColiRec38 {
    u8 pad_0[0x10];
    ColiAnim *anim;
    u8 pad_14[0x24];
} ColiRec38;

/* fn_1_1384C */
typedef struct ColiHeader {
    f32 unk_0;
    f32 unk_4;
    s32 modelCount;
    ColiModelRef *models;
    u8 pad_10[4];
    void *unk_14;
    s32 objectCount;
    ColiObject *objects;
    void *unk_20;
    void *unk_24;
    u8 pad_28[4];
    void *unk_2C;
    u8 pad_30[0xC];
    void *unk_3C;
    u8 pad_40[4];
    void *unk_44;
    s32 sub54Count;
    u8 pad_4C[8];
    ColiSub54 *sub54;
    u8 pad_58[4];
    s32 rec24Count;
    ColiRec24 *rec24;
    s32 groupCount;
    ColiGroup *groups;
    s32 wordCount;
    void **words;
    s32 rec70Count;
    ColiRec70 *rec70;
    u8 pad_7C[4];
    ColiAnim *unk_80;
    void *unk_84;
    s32 recA0Count;
    ColiRecA0 *recA0;
    f32 *unk_90;
    u8 pad_94[4];
    void *unk_98;
    u8 pad_9C[4];
    void *unk_A0;
    u8 pad_A4[4];
    void *unk_A8;
    u8 pad_AC[4];
    void *unk_B0;
    s32 rec38Count;
    ColiRec38 *rec38;
    void **grid;
    u8 pad_C0[0x10];
    s32 gridColumns;
    s32 gridRows;
} ColiHeader;

/* fn_1_1384C */
typedef struct ColiRuntime {
    u32 flags;
    u8 pad_4[4];
    f32 x, y, z;
    f32 dx, dy, dz;
    s16 rx, ry, rz;
    s16 rx2, ry2, rz2;
    u8 mtx_2C[0x30];
    u8 mtx_5C[0x30];
    u8 pad_8C[0xC];
    f32 unk_98;
    u32 unk_9C;
} ColiRuntime;

/* fn_1_14CB4 */
typedef struct Node {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node *children;
    u8 pad_14[0x50 - 0x14];
} Node;

/* fn_1_14CB4 */
typedef struct StcoliNode StcoliNode;

/* fn_1_14CB4 */
struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

/* fn_1_14CB4 */
typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

/* fn_1_14CB4 */
typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

/* fn_1_14CB4 */
typedef struct Fn_1_20258Constants {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants;

/* fn_1_14CB4 */
typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

/* fn_1_14CB4 */
typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

/* fn_1_14CB4 */
typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

/* fn_1_14CB4 */
typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

/* fn_1_14CB4 */
struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_14CB4 */
struct fn_1_207DC_pool {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_14CB4 */
struct fn_1_21950_lbl_1_rodata_6C8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_14CB4 */
typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

/* fn_1_14CB4 */
typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg;

/* fn_1_14CB4 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

/* fn_1_14CB4 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

/* fn_1_14CB4 */
struct fn_1_2D524_Copy200 { char *a[10][5]; };

/* fn_1_14CB4 */
struct fn_1_2D524_Copy8 { char *a[2]; };

/* fn_1_14CB4 */
struct fn_1_2D524_lbl_1_rodata_BD8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200 unk_58;
    struct fn_1_2D524_Copy8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_14CB4 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s8 unk_8;
    s8 unk_9;
} fn_1_14DE8_StcoliEntry;

/* fn_1_14CB4 */
typedef struct {
    s32 count;
    u8 *base;
    u8 pad_8[4];
} StcoliRecord;

/* fn_1_14CB4 */
typedef struct Node_fn_1_14F18 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_14F18 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_14F18;

/* fn_1_14CB4 */
typedef struct StcoliNode_fn_1_14F18 StcoliNode_fn_1_14F18;

/* fn_1_14CB4 */
struct StcoliNode_fn_1_14F18 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_14F18 *items;
    u8 rest[0x3c];
};

/* fn_1_14CB4 */
struct fn_1_2B478_lbl_801A6D00_fn_1_14F18 {
    u32 unk_0;
};

/* fn_1_14CB4 */
struct Pool_fn_1_14F18 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_14CB4 */
struct fn_1_207DC_pool_fn_1_14F18 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_14CB4 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_14F18 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_14CB4 */
struct fn_1_2D524_Copy200_fn_1_14F18 { char *a[10][5]; };

/* fn_1_14CB4 */
struct fn_1_2D524_Copy8_fn_1_14F18 { char *a[2]; };

/* fn_1_14CB4 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_14F18 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_14F18 unk_58;
    struct fn_1_2D524_Copy8_fn_1_14F18 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_14CB4 */
typedef struct {
    f32 d;
    Vec3 n;
    Vec3 verts[1];
} fn_1_14F18_Poly;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0x14c];
    Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0x8];
    Vec3 dir;
    f32 radius;
} Fn183D28Target;

/* fn_1_15248 */
typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

/* fn_1_15248 */
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

/* fn_1_15248 */
typedef struct {
    u32 flags;
    u8 pad_4[0x5];
    u8 count;
    u8 pad_A[0x14AE];
    f64 pad_14B8;
} CarTestInfo;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0x4];
    Vec3 normal;
    Vec3 verts[1];
} fn_1_15248_Poly;

/* fn_1_15248 */
typedef struct {
    u8 pad_0[0xd4];
    Vec3 delta;
} fn_1_15248_Work;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0x24];
    void *polys58;
    s16 **lists58[11];
    u8 pad_54[0x60 - 0x54];
    f32 x0;
    f32 z0;
    f32 sx;
    f32 sz;
    s32 nx;
    s32 nz;
    void *polys70;
    s16 **lists70[14];
    u8 pad_b4[0x4B0 - 0xB4];
} Cell;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0x2C];
    u8 mtx0[0x30];
    u8 mtx1[0x30];
    u8 pad_8c[0xA0 - 0x8C];
} CellMtx;

/* fn_1_15578 */
typedef struct {
    u32 flags;
    Vec3 center;
    f32 radius;
    s32 n58;
    s32 n70;
    u8 *polys58;
    u8 *polys70;
} Model;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0xC];
    Model *model;
} ModelRef;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0x10];
    Vec3 pos;
    s16 rx;
    s16 ry;
    s16 rz;
    u16 pad_22;
    Vec3 scale;
} Xform2;

/* fn_1_15578 */
typedef struct {
    u32 flags;
    u8 pad_4[4];
    ModelRef *ref;
    Vec3 pos;
    s16 rx;
    s16 ry;
    s16 rz;
    u16 mask;
    Vec3 scale;
    u8 pad_2c[8];
    Xform2 *xf;
    u8 pad_38[4];
    void *mtx;
} Obj;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[8];
    s32 unk8;
    u8 pad_c[0x18 - 0xC];
    s32 ncells;
    Cell *cells;
    u8 pad_20[0x48 - 0x20];
    s32 nobj;
    s32 firstobj;
    u8 pad_50[4];
    Obj *objs;
} Stcoli;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0xC];
    u32 flags;
    f32 t;
    Vec3 pos;
    Vec3 nrm;
    Vec3 push;
    u8 pad_38[0x48 - 0x38];
} Hit;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 delta;
    u8 pad_e0[0x1B0 - 0xE0];
    f32 radius;
    f32 unk1B4;
    u8 pad_1b8[0x1C8 - 0x1B8];
    s32 unk1C8;
    s32 unk1CC;
    s32 unk1D0;
    s32 unk1D4;
    u8 pad_1d8[0x1E4 - 0x1D8];
    Hit hits[5];
    u8 pad_34c[0x5AC - 0x34C];
    s32 unk5AC;
    u8 pad_5b0[0x62C - 0x5B0];
    s32 unk62C;
    u8 pad_630[0x8B0 - 0x630];
    s32 unk8B0;
} Work;

/* fn_1_15578 */
typedef struct {
    u8 pad_0[0x584];
    f32 radius;
    f32 unk588;
} Racer;

/* fn_1_163BC */
typedef struct {
    u8 pad_0[0x24];
    void *polys58;
    s16 **lists58[11];
    u8 pad_54[0x60 - 0x54];
    f32 x0;
    f32 z0;
    f32 sx;
    f32 sz;
    s32 nx;
    s32 nz;
    void *polys70;
    s16 **lists70[11];
    u8 pad_a8[0x4B0 - 0xA8];
} Cell_163BC;

/* fn_1_163BC */
typedef struct {
    u8 pad_0[8];
    s32 unk8;
    u8 pad_c[0x18 - 0xC];
    s32 ncells;
    Cell_163BC *cells;
    u8 pad_20[0x48 - 0x20];
    s32 nobj;
    u8 pad_4c[4];
    s32 firstobj;
    Obj *objs;
} Stcoli_163BC;

/* fn_1_163BC */
typedef struct {
    u8 pad_0[0xA0];
    u16 unkA0;
} Data2A7E0;

/* fn_1_16BA0 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    u8 pad_C[0x1C];
    f32 wideThreshold;
    f32 threshold;
} fn_1_16BA0_Pool;

/* fn_1_16BA0 */
typedef struct {
    u8 pad_0[0x8];
    f32 a0;
    f32 ax;
    f32 ay;
    f32 az;
    u8 pad_18[0xC];
    f32 b0;
    f32 bx;
    f32 by;
    f32 bz;
    u8 pad_34[0x18];
    s8 canBack;
    s8 canFwd;
    u8 pad_4E[0x2];
} fn_1_16BA0_Plane;

/* fn_1_16BA0 */
typedef struct {
    s32 count;
    fn_1_16BA0_Plane *planes;
    u8 pad_8[0x4];
} fn_1_16BA0_Seg;

/* fn_1_16E68 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;    /* 0x08 */
    f32 one;     /* 0x0C */
    u8 pad_10[0x18];
    f32 thresh25;  /* 0x28: 1.7f */
    f32 threshDef; /* 0x2C: 0.001f */
} StcoliPool16E68;

/* fn_1_16E68 */
typedef struct {
    u8 pad_0[0x8];
    f32 d1;
    f32 n1x, n1y, n1z;
    u8 pad_18[0xC];
    f32 d2;
    f32 n2x, n2y, n2z;
    u8 pad_34[0x1C];
} StcoliPlanePair;

/* fn_1_16E68 */
typedef struct {
    u32 unk_0;
    StcoliPlanePair *planes;
    u32 unk_8;
} StcoliSegment;

/* fn_1_17098 */
typedef struct Fn_1_21950Constants {
    u8 pad_0[8];
    f32 zero;      /* 0x08 */
    u8 pad_c[0x14];
    f32 half;      /* 0x20 */
    u8 pad_24[0x10];
    f32 neg_half;  /* 0x34 */
} Fn_1_21950Constants;

/* fn_1_17098 */
typedef struct Fn_1_28660 {
    int field00;
    short field04;
    unsigned char pad06[0x212];
    int field218;
    unsigned char pad21c[0x2e0];
    int field4fc;
    unsigned char pad500[0x8c];
    int field58c;
} Fn_1_28660;

/* fn_1_17098 */
struct fn_1_287E8_Arg0 {
    u32 flags;
    u8 pad_4[0x178];
    f32 unk_17C;
    u8 pad_180[0x10];
    u32 unk_190;
    u16 unk_194;
    u8 unk_196;
    u8 pad_197[0x65];
    f32 unk_1FC;
    f32 unk_200;
    u8 pad_204[0xE];
    u8 unk_212;
    u8 pad_213[0x26D];
    u8 unk_480;
    u8 pad_481[0x43];
    u8 unk_4C4;
};

/* fn_1_17098 */
typedef struct Fn_1_2A638 {
    unsigned char pad00[0x08];
    f32 field08;
    f32 field0c;
    f32 field10;
    unsigned char pad14[0x30];
    f32 field44;
    f32 field48;
} Fn_1_2A638;

/* fn_1_17098 */
typedef struct Fn_1_2A678_Values {
    int x;
    int y;
    int z;
} Fn_1_2A678_Values;

/* fn_1_17098 */
typedef struct Fn_1_2A678_Source {
    unsigned char pad00[0x7c];
    Fn_1_2A678_Values values;
} Fn_1_2A678_Source;

/* fn_1_17098 */
typedef struct Fn_1_2A678_Dest {
    unsigned char pad00[0xc];
    Fn_1_2A678_Values values;
} Fn_1_2A678_Dest;

/* fn_1_17098 */
typedef struct Part {
    u32 flags;
    u8 pad_4[0x5c - 0x4];
} Part;

/* fn_1_17098 */
typedef struct Body {
    u32 flags;
    u8 pad_4[0x4];
    f32 mass;
    u8 pad_C[0x10];
    f32 f1C;
    f32 f20;
    u8 pad_24[0x58];
    Vec3 pos;           /* 0x7C */
    Vec3 prevPos;       /* 0x88 */
    Vec3 vel;           /* 0x94 */
    u8 pad_A0[0x18];
    f32 fB8;
    u8 pad_BC[0x8];
    f32 fC4;
    f32 fC8;
    f32 fCC;
    f32 fD0;
    u8 pad_D4[0x18];
    f32 mtxEC[12];
    f32 mtx11C[12];
    u8 pad_14C[0x30];
    f32 f17C;
    u8 pad_180[0x4];
    f32 f184;
    u8 pad_188[0x58];
    Vec3 pos1E0;        /* 0x1E0 */
    u8 pad_1EC[0x8];
    f32 f1F4;
    f32 f1F8;
    f32 f1FC;
    u8 pad_200[0x4];
    f32 f204;
    u8 pad_208[0x10];
    u32 f218;
    u8 pad_21C[0x28];
    Part parts[4];       /* 0x244 */
    u8 pad_3B4[0xC8];
    u32 f47C;
    u8 pad_480[0x1];
    u8 b481;
    u8 pad_482[0x1];
    u8 b483;
    u8 pad_484[0x30];
    Vec3 v4B4;
    u8 b4C0;
    u8 pad_4C1[0x2];
    u8 b4C3;
    u8 pad_4C4[0x1];
    u8 b4C5;
    u8 pad_4C6[0x2];
    Vec3 pos4C8;        /* 0x4C8 */
    u8 pad_4D4[0xAC];
    f32 f580;
    u8 pad_584[0x8];
    u32 f58C;
    u8 pad_590[0x2];
    u8 b592;
    u8 b593;
    u8 pad_594[0x46];
    u16 h5DA;
} Body;

/* fn_1_17098 */
typedef struct { f32 x, y, z, w; } Quat;

/* fn_1_17098 */
typedef struct Sig_fn_1_2A694_N { u8 p[0x98]; u32 v98; u32 v9c; } Sig_fn_1_2A694_N;

/* fn_1_17098 */
typedef struct Sig_fn_1_2A694_O {
    u32 flags;
    s16 id;
    u8 p[0x8e];
    f32 f94;
    f32 f98;
    f32 f9c;
    f32 fa0;
    f32 fa4;
    f32 fa8;
    u8 p1[0xd0];
    f32 f17c;
    u8 p1b[4];
    f32 f184;
    u8 p1c[0x9c];
    f32 f224;
    u8 p2[0x24c];
    u8 v474;
    u8 p3[0x23];
    u32 field498;
    Sig_fn_1_2A694_N *field49c;
    u8 p4[0xec];
    u32 field58c;
} Sig_fn_1_2A694_O;

/* fn_1_17098 */
typedef struct ColiTarget {
    u8 p[0x390];
    u32 flags390;
} ColiTarget;

/* fn_1_17098 */
typedef struct {
    u8 pad[0x390];
    u32 f390;
} Fn2BA48_Other;

/* fn_1_17098 */
struct fn_1_2D038_Text {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u32 pad_10[7];
    f32 unk_2C;
    u32 unk_30;
    u32 pad_34[9];
};

/* fn_1_17098 */
struct fn_1_2D524_Copy200_17098 { u32 a[10][5]; };

/* fn_1_17098 */
struct fn_1_2D524_Copy8_17098 { u32 a[2]; };

/* fn_1_17098 */
typedef struct Sig_fn_1_2A8D0_ColiQuery {
    u8 p[0xc];
    Vec3 pos;
    Vec3 dir;
} Sig_fn_1_2A8D0_ColiQuery;

/* fn_1_17098 */
struct Sig_fn_1_18B40_fn_1_18B40_Obj {
    u32 flags;
    u8 pad_4[0x8];
    s32 count;
    struct Sig_fn_1_18B40_fn_1_18B40_Obj *entries;
    u8 pad_14[0x38];
    s32 unk_4C;
};

/* fn_1_17098 */
struct Sig_fn_1_18B40_fn_1_18B40_Vec { u32 x, y, z; };

/* fn_1_17098 */
typedef struct ColiRange {
    f32 a, b;
    u8 pad8[0x44];
    s8 enabledA, enabledB;
    u8 pad4E[2];
} ColiRange;

/* fn_1_17098 */
typedef struct ColiEntry {
    u32 unk0;
    ColiRange *ranges;
    struct Sig_fn_1_18B40_fn_1_18B40_Obj *obj;
} ColiEntry;

/* fn_1_17098 */
typedef struct ColiResult {
    s32 count;
    u32 flags;
    s32 any;
    u8 padC[0x10];
    u32 values[4];
    f32 times[4];
    u32 masks[4];
    s32 ids[4];
} ColiResult;

/* fn_1_17098 */
typedef struct ColiContext {
    ColiResult *result;
    s32 *other;
} ColiContext;

/* fn_1_17098 */
typedef struct ColiRecord {
    u32 words[3];
    u32 valid;
    f32 distance;
    u8 pad14[0x34];
} ColiRecord;

/* fn_1_17098 */
typedef struct ColiManager {
    u8 pad0[0x1B8];
    s32 count;
    s32 index;
    s32 segment;
    f32 time;
    u32 unk1C8;
    s32 total;
    u8 pad1D0[8];
    s32 enabled;
    u8 pad1DC[0x50];
    ColiRecord primary[4];
    ColiRecord candidates[8];
    s32 candidateIds[8];
    s32 candidateCount;
} ColiManager;

/* fn_1_17920 */
typedef struct {
    f32 unk_0;
    f32 unk_4;
} fn_1_17920_Record;

/* fn_1_17920 */
typedef struct {
    u32 unk_0;
    fn_1_17920_Record *unk_4;
    void *unk_8;
} fn_1_17920_Slot;

/* fn_1_17920 */
typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
    f32 unk_10;
    u8 pad_14[0x34];
} fn_1_17920_Result;

/* fn_1_17920 */
typedef struct {
    u8 pad_0[0x1B0];
    f32 unk_1B0;
    f32 unk_1B4;
    s32 unk_1B8;
    u32 unk_1BC;
    u8 pad_1C0[0x8];
    u32 unk_1C8;
    s32 unk_1CC;
    u32 unk_1D0;
    u32 unk_1D4;
    u8 pad_1D8[0xC];
    fn_1_17920_Result unk_1E4[5];
    u8 pad_34C[0x260];
    u32 unk_5AC;
    u8 pad_5B0[0x7C];
    u32 unk_62C;
} fn_1_17920_Work;

/* fn_1_17920 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;    /* 0x08 */
    f32 one;     /* 0x0C */
    u8 pad_10[0x8];
    f32 neg_one; /* 0x18 */
    f32 two;     /* 0x1C */
} StcoliPool17920;

/* fn_1_17A9C */
struct FnObj {
    u8 pad_1cc[0x1cc];
    s32 count;
    u8 pad_674[0x674 - 0x1d0];
    Vec3 first;
    u8 pad_6f4[0x6f4 - 0x680];
    Vec3 second;
};

/* fn_1_17B5C */
typedef struct {
    u8 pad_0[0x40];
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x5];
    s8 unk_4D;
} Fn17B5C_Record;

/* fn_1_17B5C */
typedef struct {
    u32 unk_0;
    Fn17B5C_Record *unk_4;
    u32 unk_8;
} Fn17B5C_Slot;

/* fn_1_17B5C */
typedef struct Entry {
    char pad[0x4d];
    s8 active;
} Entry;

/* fn_1_17B5C */
typedef struct Slot {
    int pad;
    Entry *entry;
    int tail;
} Slot;

/* fn_1_17B5C */
typedef struct Root {
    char pad[0xc];
    Slot *slots;
} Root;

/* fn_1_17B5C */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} fn_1_17FCC_StcoliEntry;

/* fn_1_17B5C */
typedef struct {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry_180F4;

/* fn_1_18784 */
typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Mat;

/* fn_1_18784 */
typedef struct {
    u8 pad_0[0x1bc];
    s32 f1bc;
    u8 pad_1c0[8];
    u32 f1c8;
    s32 f1cc;
    u8 pad_1d0[0xc];
    f32 f1dc;
    f32 f1e0;
} Mgr;

/* fn_1_18B40 */
struct fn_1_18B40_Obj {
    u32 flags;
    u8 pad_4[0x8];
    s32 count;
    struct fn_1_18B40_Obj *entries;
    u8 pad_14[0x38];
    s32 unk_4C;
};

/* fn_1_18B40 */
struct fn_1_18B40_Vec {
    u32 x;
    u32 y;
    u32 z;
};

/* fn_1_18F28 */
typedef struct {
    unsigned int flags;
} Fn118F28Entry;

/* fn_1_192E8 */
struct fn_1_192E8_Arg4 {
    u32 unk_0;
    u8 pad_4[0x38];
    f32 unk_3C;
    f32 unk_40;
};

/* fn_1_192E8 */
struct fn_1_192E8_lbl_1_rodata_6C8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0xC];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};

/* fn_1_192E8 */
struct fn_1_192E8_Node {
    s32 index;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x30];
    u32 links[4];
};

/* fn_1_192E8 */
struct fn_1_192E8_Table {
    s32 count;
    u8 pad_4[8];
    Vec3 normal;
    u32 unk_18;
    struct fn_1_192E8_Arg4 *objects[8];
    u32 flags[4];
    s32 ids[4];
};

/* fn_1_192E8 */
struct fn_1_192E8_Context {
    struct fn_1_192E8_Node *node;
    struct fn_1_192E8_Table *table;
};

/* fn_1_192E8 */
struct fn_1_192E8_Contact {
    s32 unk_0;
    s32 unk_4;
    f32 unk_8;
    u32 flags;
    f32 t;
    Vec3 point;
    Vec3 normal;
    Vec3 correction;
    Vec3 position;
    u32 *link;
};

/* fn_1_192E8 */
struct fn_1_192E8_Volume {
    Vec3 matrix;
    u8 pad_C[0x24];
    f32 width;
    u8 pad_34[8];
    f32 height;
};

/* fn_1_192E8 */
struct fn_1_192E8_Manager {
    u8 pad_0[0xD4];
    Vec3 position;
    u8 pad_E0[0xD8];
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[8];
    s32 num_volumes;
    u8 pad_1D4[0x178];
    struct fn_1_192E8_Contact contacts[8];
    s32 indices[8];
    s32 num_contacts;
    u8 pad_5B0[0x200];
    struct fn_1_192E8_Volume volumes[1];
};

/* fn_1_19AE0 */
typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
} SegSub;

/* fn_1_19AE0 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x4];
    SegSub *unk_8;
    u8 pad_C[0x30];
    f32 unk_3C;
    f32 unk_40;
} Seg;

/* fn_1_19AE0 */
typedef struct {
    s32 unk_0;
    u8 pad_4[0x4];
    u32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    Seg *unk_1C[4];
    f32 unk_2C[4];
    u32 unk_3C[4];
    s32 unk_4C[4];
} Rec_19AE0;

/* fn_1_19AE0 */
typedef struct {
    Rec_19AE0 *unk_0;
    Rec_19AE0 *unk_4;
} Ctx;

/* fn_1_19AE0 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    f32 unk_8;
    u32 unk_C;
    f32 unk_10;
    Vec3 unk_14;
    Vec3 unk_20;
    Vec3 unk_2C;
    Vec3 unk_38;
    u32 *unk_44;
} Contact;

/* fn_1_19AE0 */
typedef struct {
    u8 unk_0[0x30];
    Vec3 unk_30;
    f32 unk_3C;
} Volume;

/* fn_1_19AE0 */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 unk_D4;
    u8 pad_E0[0xD4];
    f32 unk_1B4;
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0x8];
    s32 unk_1D0;
    u8 pad_1D4[0x4];
    s32 unk_1D8;
    u8 pad_1DC[0x8];
    Contact unk_1E4;
    Contact unk_22C;
    u8 pad_274[0xD8];
    Contact unk_34C[8];
    s32 unk_58C[8];
    s32 unk_5AC;
    u8 pad_5B0[0x200];
    Volume unk_7B0[1];
} Mgr_19AE0;

/* fn_1_19AE0 */
typedef struct {
    u8 pad_0[0x18];
    Vec3 unk_18;
} Plane;

/* fn_1_19AE0 */
typedef struct {
    u8 pad_0[0x508];
    Plane *unk_508;
} PlaneOwner;

/* fn_1_1ACC0 */
typedef struct {
    u8 pad_0[0x40];
    f32 unk_40;
} fn_1_1ACC0_Seg;

/* fn_1_1ACC0 */
typedef struct {
    u8 pad_0[0x1BC];
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0x304 - 0x1C8];
    Contact unk_304;
} fn_1_1ACC0_Mgr;

/* fn_1_1B010 */
typedef struct {
u32 off[9];
} OffsetTable;

/* fn_1_1B010 */
typedef struct {
u8 pad_0[0x8];
f32 zero;
u8 pad_C[0x4];
f32 minY;
f32 maxY;
u8 pad_18[0x8];
f32 scale;
f32 bias;
u8 pad_28[0x24];
OffsetTable shapes;
OffsetTable counts;
} StcoliPool6C8;

/* fn_1_1B010 */
typedef struct {
u32 flags;
u8 *cfg;
} StcoliEntity;

/* fn_1_1B010 */
typedef struct {
u8 pad_0[0x1D4];
u32 flags;
} StcoliGlobal;

/* fn_1_1B2A4 */
typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x8];
} Key;

/* fn_1_1B2A4 */
typedef struct {
    u8 pad_0[0x1C];
    s32 unk_1C;
    u8 pad_20[0x20];
    Key *unk_40;
} SegChild;

/* fn_1_1B2A4 */
typedef struct {
    u32 unk_0;
    SegChild *unk_4;
    u8 pad_8[0x28];
    f32 unk_30;
    u8 pad_34[0x8];
    f32 unk_3C;
    f32 unk_40;
} Seg_1B2A4;

/* fn_1_1B2A4 */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 unk_D4;
    u8 pad_E0[0xD8];
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0x8];
    s32 unk_1D0;
    u8 pad_1D4[0x4];
    s32 unk_1D8;
    u8 pad_1DC[0x8];
    Contact unk_1E4;
    Contact unk_22C;
    u8 pad_274[0xD8];
    Contact unk_34C[8];
    s32 unk_58C[8];
    s32 unk_5AC;
    u8 pad_5B0[0x200];
    Volume unk_7B0[1];
} Mgr_1B2A4;

/* fn_1_1C0D0 */
typedef struct {
    s32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
} fn_1_1C0D0_Key;

/* fn_1_1C0D0 */
typedef struct {
    u8 pad_0[0x1C];
    s32 unk_1C;
    u8 pad_20[0x20];
    fn_1_1C0D0_Key *unk_40;
} fn_1_1C0D0_Cfg;

/* fn_1_1C0D0 */
typedef struct {
    u32 unk_0;
    fn_1_1C0D0_Cfg *unk_4;
    u8 pad_8[0x28];
    f32 unk_30;
} fn_1_1C0D0_Wall;

/* fn_1_1C0D0 */
typedef struct {
    s32 unk_0;
    u8 pad_4[0x18];
    fn_1_1C0D0_Wall *unk_1C[4];
    f32 unk_2C[4];
    u32 unk_3C[4];
    s32 unk_4C[4];
} fn_1_1C0D0_List;

/* fn_1_1C0D0 */
typedef struct {
    fn_1_1C0D0_List *unk_0;
    fn_1_1C0D0_List *unk_4;
} fn_1_1C0D0_Ctx;

/* fn_1_1C0D0 */
typedef struct {
    u8 pad_0[0x1B8];
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0x10];
    s32 unk_1D8;
    u8 pad_1DC[0x8];
    Contact unk_1E4;
    Contact unk_22C;
    u8 pad_274[0x63C];
    fn_1_1C0D0_Ctx *unk_8B0;
} fn_1_1C0D0_Mgr;

/* fn_1_1D0CC */
typedef struct {
    u32 unk_0;
} Segment;

/* fn_1_1D0CC */
typedef struct {
    s32 unk_0;
    u8 pad_4[0x18];
    Segment *unk_1C[4];
    f32 unk_2C[4];
    u32 unk_3C[4];
    s32 unk_4C[4];
} CollNode;

/* fn_1_1D0CC */
typedef struct {
    CollNode *unk_0;
    CollNode *unk_4;
} CollCtx;

/* fn_1_1D0CC */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 unk_D4;
    u8 pad_E0[0xD8];
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0xC];
    u32 unk_1D4;
    u8 pad_1D8[0xC];
    Contact unk_1E4[2];
} Manager;

/* fn_1_1DCD8 */
typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x20];
    u32 unk_28;
} SegCfg;

/* fn_1_1DCD8 */
typedef struct {
    u8 pad_0[0x4];
    SegCfg *unk_4;
    u8 pad_8[0x10];
    f32 unk_18;
} SegSrc;

/* fn_1_1DCD8 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 unk_C;
    SegSrc *unk_10;
} Segment_1DCD8;

/* fn_1_1DCD8 */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 unk_D4;
    u8 pad_E0[0xD4];
    f32 unk_1B4;
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0x1C];
    Contact unk_1E4[2];
} Manager_1DCD8;

/* fn_1_1EBD4 */
typedef struct {
    s32 unk_0;
    u8 pad_4[0x4];
    u32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    Segment *unk_1C[4];
    f32 unk_2C[4];
    u32 unk_3C[4];
    s32 unk_4C[4];
} Rec_1EBD4;

/* fn_1_1EBD4 */
typedef struct {
    u8 pad_0[0x1B8];
    s32 unk_1B8;
    s32 unk_1BC;
    s32 unk_1C0;
    f32 unk_1C4;
    u8 pad_1C8[0xC];
    u32 unk_1D4;
    u8 pad_1D8[0x4];
    f32 unk_1DC;
    f32 unk_1E0;
    u8 pad_1E4[0x48];
    Contact unk_22C;
} Mgr_1EBD4;

/* fn_1_1FB80 */
typedef struct {
    u8 pad_0[0xC];
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_12[2];
    f32 size_x;
    f32 size_y;
    f32 size_z;
    u32 flags;
} ColiVolume_fn_1_1FB80;

/* fn_1_1FDB0 */
struct fn_1_1FDB0_Arg0 { u8 pad_0[8]; f32 unk_8; };

/* fn_1_1FDB0 */
struct fn_1_1FDB0_Arg1 { u32 unk_0; u32 unk_4; u32 unk_8; };

/* fn_1_1FDB0 */
struct fn_1_1FDB0_Arg2 { u8 pad_0[8]; f32 unk_8; };

/* fn_1_1FDB0 */
struct fn_1_1FDB0_Arg3 { u32 unk_0; u32 unk_4; u32 unk_8; };

/* fn_1_1FDB0 */
struct Vec { f32 x,y,z; };

/* fn_1_1FDB0 */
struct Scratch { u8 pad[0xd4]; struct Vec v; };

/* fn_1_1FFA0 */
typedef struct Node_fn_1_1FFA0 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_1FFA0 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_1FFA0;

/* fn_1_1FFA0 */
typedef struct StcoliNode_fn_1_1FFA0 StcoliNode_fn_1_1FFA0;

/* fn_1_1FFA0 */
struct StcoliNode_fn_1_1FFA0 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_1FFA0 *items;
    u8 rest[0x3c];
};

/* fn_1_1FFA0 */
struct fn_1_2B478_lbl_801A6D00_fn_1_1FFA0 {
    u32 unk_0;
};

/* fn_1_1FFA0 */
struct Pool_fn_1_1FFA0 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_1FFA0 */
struct fn_1_207DC_pool_fn_1_1FFA0 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_1FFA0 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_1FFA0 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_1FFA0 */
struct fn_1_2D524_Copy200_fn_1_1FFA0 { char *a[10][5]; };

/* fn_1_1FFA0 */
struct fn_1_2D524_Copy8_fn_1_1FFA0 { char *a[2]; };

/* fn_1_1FFA0 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_1FFA0 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_1FFA0 unk_58;
    struct fn_1_2D524_Copy8_fn_1_1FFA0 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_1FFA0 */
typedef struct Fn_1_20258 {
    unsigned char pad00[0x30];
    f32 field30;
    f32 field34;
    unsigned char pad38[4];
    f32 field3c;
    unsigned char pad40[0x28];
    f32 field68;
    f32 field6c;
    unsigned char pad70[0xc];
    u32 flags;
} Fn_1_20258;

/* fn_1_203E4 */
typedef struct {
    u8 pad_0[0x3C];
    f32 unk_3C;
    f32 unk_40;
    u8 pad_44[0x24];
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    u32 unk_7C;
} fn_1_203E4_Obj;

/* fn_1_203E4 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;      /* 0x08 */
    f32 one;       /* 0x0C */
    u8 pad_10[0x8];
    f32 minusOne;  /* 0x18 */
    u8 pad_1C[0x7C];
    f64 half;      /* 0x98 */
    u8 pad_A0[0x1C];
    f32 angleScale; /* 0xBC */
    u8 pad_C0[0x10];
    f64 two;       /* 0xD0 */
    f64 zeroD;     /* 0xD8 */
    f64 angleScaleD; /* 0xE0 */
    f64 oneD;      /* 0xE8 */
    f64 minusOneD; /* 0xF0 */
} fn_1_203E4_Pool;

/* fn_1_207DC */
struct fn_1_207DC_obj {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[4];
    f32 unk_3C;
    u8 pad_40[0x28];
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0xC];
    u32 unk_7C;
};

/* fn_1_207DC */
typedef struct Fn_1_20994_Object {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_0C[0x71];
    u8 unk_7D;
} Fn_1_20994_Object;

/* fn_1_20A5C */
typedef struct {
    u8 pad_0[0x8];
    f32 d0;
    Vec3 n0;
    Vec3 a;
    f32 d1;
    Vec3 n1;
    Vec3 b;
    u8 pad_40[0x8];
    f32 w;
    u8 pad_4c[0x4];
} fn_1_20A5C_Rec;

/* fn_1_20A5C */
typedef struct {
    s32 count;
    fn_1_20A5C_Rec *recs;
    void *unk_8;
} fn_1_20A5C_Seg;

/* fn_1_20A5C */
typedef struct {
    u8 pad_0[0x8];
    s32 count;
    fn_1_20A5C_Seg *segs;
    u8 pad_10[0x7D - 0x10];
    u8 single;
    u8 pad_7e[0xBC - 0x7E];
    s16 **grid;
    f32 x0;
    f32 z0;
    f32 sx;
    f32 sz;
    s32 nx;
    s32 nz;
} fn_1_20A5C_Course;

/* fn_1_20A5C */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    f32 one;
    u8 pad_10[0x10];
    f32 unk_20;
    u8 pad_24[0x4];
    f32 unk_28;
    f32 unk_2C;
} fn_1_20A5C_Pool;

/* fn_1_20A5C */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 delta;
} fn_1_20A5C_Work;

/* fn_1_210A8 */
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    Vec3 unk_18;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    Vec3 unk_34;
    u8 pad_40[0x10];
} fn_1_210A8_Rec;

/* fn_1_210A8 */
typedef struct {
    s32 unk_0;
    fn_1_210A8_Rec *unk_4;
    Segment *unk_8;
} fn_1_210A8_Seg;

/* fn_1_210A8 */
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x1C];
    f32 unk_28;
    f32 unk_2C;
} fn_1_210A8_Pool;

/* fn_1_214C4 */
typedef struct Node_fn_1_214C4 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_214C4 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_214C4;

/* fn_1_214C4 */
typedef struct StcoliNode_fn_1_214C4 StcoliNode_fn_1_214C4;

/* fn_1_214C4 */
struct StcoliNode_fn_1_214C4 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_214C4 *items;
    u8 rest[0x3c];
};

/* fn_1_214C4 */
struct fn_1_2B478_lbl_801A6D00_fn_1_214C4 {
    u32 unk_0;
};

/* fn_1_214C4 */
struct Pool_fn_1_214C4 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_214C4 */
struct fn_1_207DC_pool_fn_1_214C4 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_214C4 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_214C4 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_214C4 */
struct fn_1_2D524_Copy200_fn_1_214C4 { char *a[10][5]; };

/* fn_1_214C4 */
struct fn_1_2D524_Copy8_fn_1_214C4 { char *a[2]; };

/* fn_1_214C4 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_214C4 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_214C4 unk_58;
    struct fn_1_2D524_Copy8_fn_1_214C4 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_214C4 */
typedef struct { u8 pad_0[0x40]; f32 lo; f32 hi; } Seg_214C4;

/* fn_1_214C4 */
typedef struct { u32 a; Seg_214C4 *seg; u32 b; } Ent;

/* fn_1_216F0 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;      /* 0x08 */
    u8 pad_C[0x1C];
    f32 thresh25;  /* 0x28: 1.7f */
    f32 threshDef; /* 0x2C: 0.001f */
    u8 pad_30[0xC8];
    f32 margin;    /* 0xF8: 0.3f */
} StcoliPool216F0;

/* fn_1_216F0 */
typedef struct fn_1_216F0_Rec {
    u8 pad_0[0x8];
    f32 unk_8;
    Vec3 unk_C;
    u8 pad_18[0x8];
    f32 unk_20;
    f32 unk_24;
    Vec3 unk_28;
    u8 pad_34[0x8];
    f32 unk_3C;
    u8 pad_40[0x10];
} fn_1_216F0_Rec;

/* fn_1_216F0 */
typedef struct fn_1_216F0_Seg {
    u32 unk_0;
    fn_1_216F0_Rec *unk_4;
    u32 unk_8;
} fn_1_216F0_Seg;

/* fn_1_2192C */
typedef struct Fn_1_21BE4 {
    u32 flags;
    unsigned char pad04[0x38];
    f32 field3c;
    f32 field40;
} Fn_1_21BE4;

/* fn_1_21F18 */
typedef struct {
    u8 pad_0[0x4];
    u32 key;
    u8 pad_8[0x20];
    void *curve;
} StcoliCurveSrc;

/* fn_1_21F18 */
typedef struct {
    u8 pad_0[0x4];
    StcoliCurveSrc *src;
    u8 pad_8[0x10];
    f32 value;
} StcoliCurveOwner;

/* fn_1_21F18 */
typedef struct {
    u8 pad_0[0xc];
    s32 mode;
    StcoliCurveOwner *owner;
} StcoliDrawEntity;

/* fn_1_21F18 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    u8 pad_C[0x14];
    f32 half;
    u8 pad_24[0x10];
    f32 neg_half;
} StcoliPool6C8_21F18;

/* fn_1_2221C */
typedef struct {
    s32 type;
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey;

/* fn_1_2221C */
typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x10];
    u32 unk_18;
    u8 pad_1C[0xC];
    Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *unk_28;
    u8 pad_2C[0x10];
    Sig_fn_1_9DDA8_fn_1_9DDA8_CurveKey *unk_3C;
} fn_1_2221C_Anim;

/* fn_1_2221C */
typedef struct {
    u8 pad_0[0x4];
    fn_1_2221C_Anim *anim;
    u8 pad_8[0x10];
    f32 unk_18;
    u8 pad_1C[0x10];
    f32 unk_2C;
} fn_1_2221C_Obj;

/* fn_1_2221C */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    u8 pad_C[0x10];
    f32 two;
    f32 half;
    u8 pad_24[0x10];
    f32 neg_half;
} fn_1_2221C_Pool;

/* fn_1_224F8 */
typedef struct {
    Vec3 pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_12[2];
    f32 width;
    f32 height;
    u8 pad_1C[4];
    u32 round;
} StcoliGate;

/* fn_1_224F8 */
typedef struct {
    u8 pad_0[0x8];
    f32 zero;    /* 0x08 */
    f32 one;     /* 0x0C */
    u8 pad_10[0x4];
    f32 ten;     /* 0x14 */
    f32 neg_one; /* 0x18 */
    u8 pad_1C[0x4];
    f32 half;    /* 0x20 */
} Fn_1_224F8Constants;

/* fn_1_2277C */
typedef struct StcoliWheel {
    s32 state;          /* 0x00 */
    f32 f04;            /* 0x04 */
    Vec3 pos;      /* 0x08 */
    Vec3 vel;      /* 0x14 */
    u8 pad20[0x24];
    f32 f44;            /* 0x44 */
    f32 f48;            /* 0x48 */
    u8 pad4C[0x10];
} StcoliWheel;

/* fn_1_2277C */
typedef struct StcoliPoint {
    Vec3 pos;      /* 0x00 */
    u8 pad0C[0x18];
    Vec3 vel;      /* 0x24 */
} StcoliPoint;

/* fn_1_2277C */
typedef struct StcoliObj {
    u32 flags;              /* 0x000 */
    s16 s04;                /* 0x004 */
    s16 s06;                /* 0x006 */
    f32 size;               /* 0x008 */
    u8 pad00C[0x30];
    char name[32];          /* 0x03C */
    u8 pad05C[0x50];
    f32 fAC;                /* 0x0AC */
    f32 fB0;                /* 0x0B0 */
    f32 fB4;                /* 0x0B4 */
    u8 pad0B8[0x170];
    f32 f228;               /* 0x228 */
    u8 pad22C[0x18];
    StcoliWheel wheels[4];  /* 0x244 */
    StcoliPoint points[4];  /* 0x3B4 */
    s8 s474;                /* 0x474 */
    s8 s475;                /* 0x475 */
    u8 pad476[0x10E];
    f32 maxLen;             /* 0x584 */
    f32 maxX;               /* 0x588 */
    u8 pad58C[4];
    u8 b590;                /* 0x590 */
    u8 pad591[0x49];
    s16 s5DA;               /* 0x5DA */
} StcoliObj;

/* fn_1_2277C */
typedef struct StcoliDesc {
    char *name;             /* 0x00 */
    u8 pad04[0x50];
    Vec3 wheelPos[4];  /* 0x54 */
    Vec3 pointPos[4];  /* 0x84 */
} StcoliDesc;

/* fn_1_2277C */
typedef struct {
    f32 field_0;
    f32 divisor;
    f32 x;
    f32 y;
    u8  pad_10[0x30];
    f32 limit;
} fn_1_229EC_ctrl;

/* fn_1_22B10 */
typedef struct Node_fn_1_22B10 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_22B10 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_22B10;

/* fn_1_22B10 */
typedef struct StcoliNode_fn_1_22B10 StcoliNode_fn_1_22B10;

/* fn_1_22B10 */
struct StcoliNode_fn_1_22B10 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_22B10 *items;
    u8 rest[0x3c];
};

/* fn_1_22B10 */
struct fn_1_2B478_lbl_801A6D00_fn_1_22B10 {
    u32 unk_0;
};

/* fn_1_22B10 */
struct Pool_fn_1_22B10 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_22B10 */
struct fn_1_207DC_pool_fn_1_22B10 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_22B10 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_22B10 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_22B10 */
struct fn_1_2D524_Copy200_fn_1_22B10 { char *a[10][5]; };

/* fn_1_22B10 */
struct fn_1_2D524_Copy8_fn_1_22B10 { char *a[2]; };

/* fn_1_22B10 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_22B10 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_22B10 unk_58;
    struct fn_1_2D524_Copy8_fn_1_22B10 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_22B10 */
struct fn_1_22B10_Arg0 {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
    u8 pad_38[0x4];
    f32 unk_3C;
};

/* fn_1_22E8C */
typedef struct Fn_1_22E8CInput {
    unsigned char pad00[0x04];
    float field04;
    float field08;
    float field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    float field3c;
    float field40;
    float field44;
    unsigned char field48;
    unsigned char field49;
    unsigned char pad4a[0x02];
    float field4c;
    float field50;
} Fn_1_22E8CInput;

/* fn_1_22E8C */
typedef struct Fn_1_22E8COutput {
    unsigned int flags;
    unsigned char pad04[0x04];
    float field08;
    float field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    unsigned char pad3c[0x1e4];
    float field220;
    unsigned char pad224[0x08];
    float field22c;
    float field230;
    float field234;
    float field238;
    float field23c;
    unsigned char pad240[0x237];
    unsigned char field477;
} Fn_1_22E8COutput;

/* fn_1_22F90 */
typedef struct { u8 pad_0[0x254]; f32 unk_254; u8 pad_258[0xB4]; f32 unk_30C; u8 pad_310[0x2D0]; Mtx unk_5E0; } Sig_fn_1_29968_Owner;

/* fn_1_22F90 */
typedef struct { unsigned char *field00; unsigned char *field04; unsigned char data[0xb8]; } Sig_fn_1_235C8_Fn_1_235C8;

/* fn_1_22F90 */
typedef struct { unsigned char pad00[0x80]; int field80; unsigned char pad84[0x0c]; int *field90; int *field94; unsigned char pad98[0x04]; int field9c; unsigned char padA0[0x18]; int fieldb8; unsigned char padbc[0x0c]; int fieldc8; unsigned char padcc[0x0c]; int fieldd8; unsigned char pade0[0x40]; int field11c; unsigned char pad120[0x3c]; int field15c; unsigned char tail160[0x9c]; } Sig_fn_1_23640_Fn_1_23640;

/* fn_1_22F90 */
struct fn_1_22F90_Copy16 { u32 a[4]; };

/* fn_1_22F90 */
struct fn_1_22F90_lbl_1_rodata_840 { u8 pad_0[0xC]; f32 unk_C; u8 pad_10[4]; f32 unk_14; f32 unk_18; f32 unk_1C; f64 unk_20; u8 pad_28[0x50]; f32 unk_78; u8 pad_7C[0x70]; f32 unk_EC; f32 unk_F0; };

/* fn_1_23500 */
typedef struct Fn_1_23500_Rodata {
    unsigned char pad00[0xc];
    f32 value0c;
    unsigned char pad10[0x4];
    f32 value14;
    unsigned char pad18[0x38];
    f64 value50;
    unsigned char pad58[0x98];
    f32 valuef0;
} Fn_1_23500_Rodata;

/* fn_1_23500 */
typedef struct Fn_1_23500 {
    int flags;
    unsigned char pad04[4];
    f32 field08;
    unsigned char pad0c[0x88];
    f32 field94;
    unsigned char pad98[0x168];
    f32 field200;
    unsigned char pad204[0x20];
    f32 field224;
    unsigned char pad228[0x259];
    unsigned char field481;
} Fn_1_23500;

/* fn_1_236CC */
struct fn_1_2D524_Copy200_236CC { u32 a[10][5]; };

/* fn_1_236CC */
struct fn_1_2D524_Copy8_236CC { u32 a[2]; };

/* fn_1_236CC */
typedef struct Fn_1_236CC_Consts {
    u8 pad_0[0xC];
    f32 zero;       /* 0x0C */
    u8 pad_10[0x4];
    f32 one;        /* 0x14 */
    u8 pad_18[0xD8];
    f32 f200;       /* 0xF0 */
    f32 f0_02;      /* 0xF4 */
    f64 f0_01;      /* 0xF8 */
    f32 f0_04;      /* 0x100 */
} Fn_1_236CC_Consts;

/* fn_1_236CC */
typedef struct Fn_1_236CC_Words {
    s32 a[3];
} Fn_1_236CC_Words;

/* fn_1_239C4 */
typedef struct {
    u8 pad_0[4]; s16 id; u8 pad_6[0x7c-6]; Vec3 pos;
} Sig_fn_1_2BBD0_Fn2BBD0_Other;

/* fn_1_239C4 */
typedef struct {
    u8 pad_0[0x7c]; Vec3 pos;
    u8 pad_88[0xec-0x88]; u8 mtx[0x4b4-0xec];
    Vec3 dir; u8 active, owner;
} Sig_fn_1_2BBD0_Fn2BBD0_Self;

/* fn_1_239C4 */
typedef struct Sig_fn_1_2BD30_StcoliObj2BD30 {
    u8 pad0[8]; f32 scale; u8 padC[0x7c-0xc];
    f32 posX, posY, posZ; u8 pad88[0x94-0x88];
    f32 velX, velY, velZ; u8 padA0[0xec-0xa0]; Vec3 rot;
    u8 padF8[0x1bc-0xf8]; u8 ref[0x10];
} Sig_fn_1_2BD30_StcoliObj2BD30;

/* fn_1_239C4 */
typedef struct Sig_fn_1_2BD30_StcoliOut2BD30 {
    u8 pad0[0xc]; Vec3 dir; Vec3 axis; u8 pad24[0x30-0x24];
    f32 speed, depth;
} Sig_fn_1_2BD30_StcoliOut2BD30;

/* fn_1_239C4 */
typedef struct Sig_fn_1_2A41C_Fn_1_2A41C {
    u32 flags; u8 pad04[0x190]; u16 value194;
} Sig_fn_1_2A41C_Fn_1_2A41C;

/* fn_1_239C4 */
typedef struct Sig_fn_1_24F10_Fn_1_24F10 {
    int flags; u8 pad04[0x2c]; f32 field30; u8 pad34[0x150];
    f32 field184; u8 pad188[0x8c]; u16 field214; u8 pad216[0xe];
    f32 field224; u8 pad228[0x284]; f32 field4ac;
    u8 pad4b0[0xe3]; u8 field593; u8 pad594[0x46]; u16 field5da;
} Sig_fn_1_24F10_Fn_1_24F10;

/* fn_1_239C4 */
typedef struct Sig_fn_1_2A318_Fn_1_2A318 {
    u8 pad000[0x184]; f32 field184; u8 pad188[2]; u8 field18a;
    u8 pad18b[0x85]; u16 field210; u8 field212; u8 pad213[0x26f];
    u8 field482; u8 pad483[0x10f]; u8 field592;
    u8 pad593[0x47]; u16 field5da;
} Sig_fn_1_2A318_Fn_1_2A318;

/* fn_1_239C4 */
struct fn_1_239C4_Arg0 {
    u32 flags; s16 id; s16 type; f32 scale; u8 pad0C[0x70];
    Vec3 pos; u8 pad88[0xc]; Vec3 vel; u8 padA0[0x4c];
    Vec3 vecEC; u8 padF8[0x3d0]; Vec3 prevPos; u8 pad4D4[0x2c];
    Vec3 impulse; u8 pad50C[0x80]; u32 unk_58C;
};

/* fn_1_239C4 */
struct fn_1_239C4_lbl_1_rodata_840 {
    u8 pad_0[0xc]; f32 unk_C; u8 pad_10[4];
    f32 unk_14, unk_18, unk_1C; u8 pad_20[0x30]; f64 unk_50;
    u8 pad_58[0x20]; f32 unk_78; u8 pad_7C[8];
    f32 unk_84, unk_88; u8 pad_8C[0x24]; f32 unk_B0;
    u8 pad_B4[0x14]; f32 unk_C8; u8 pad_CC[0x38]; f32 unk_104;
    f64 unk_108; f32 unk_110, unk_114, unk_118, unk_11C;
    f32 unk_120, unk_124, unk_128, unk_12C, unk_130;
    u8 pad_134[4]; f64 unk_138, unk_140;
};

/* fn_1_239C4 */
typedef struct Fn_1_248C0 {
    u32 unk_00;
    unsigned char pad04[0x471];
    signed char unk_475;
    unsigned char pad476[0x3d];
    unsigned char unk_4b3;
} Fn_1_248C0;

/* fn_1_24A4C */
typedef struct {
    u8 pad00[8];
    f32 f08;
    f32 f0C;
    f32 f10;
    Vec3 prev;
    Vec3 cur;
    u8 pad2C[0x44 - 0x2c];
    f32 f44;
    f32 f48;
    u8 pad4C[0x5c - 0x4c];
} fn_1_24A4C_Wheel;

/* fn_1_24A4C */
typedef struct {
    u8 pad00[0xc];
    Vec3 prev;
    Vec3 cur;
    u8 pad24[0x30 - 0x24];
} fn_1_24A4C_Spring;

/* fn_1_24A4C */
typedef struct {
    u32 flags;
    s16 id;
    u8 pad06[2];
    f32 mass;
    u8 pad0c[0x7c - 0xc];
    Vec3 pos;
    Vec3 prevPos;
    Vec3 vel;
    u8 padA0[0xd8 - 0xa0];
    f32 maxSpeed;
    u8 padDC[0xec - 0xdc];
    u8 mtx[0x17c - 0xec];
    f32 speed;
    u8 pad180[0x214 - 0x180];
    u16 timer214;
    u8 pad216[2];
    u32 flags218;
    u8 pad21C[0x244 - 0x21c];
    fn_1_24A4C_Wheel wheel[4];
    fn_1_24A4C_Spring spring[4];
    u8 pad474;
    s8 s475;
    u8 pad476[0x4b4 - 0x476];
    Vec3 v4b4;
    u8 u4c0;
    u8 pad4c1[0x4e0 - 0x4c1];
    u16 timer4e0;
    u8 pad4e2[0x58c - 0x4e2];
    u32 flags58c;
} fn_1_24A4C_Car;

/* fn_1_24A4C */
typedef struct {
    u8 pad[0x390];
    u32 flags390;
} fn_1_24A4C_Other;

/* fn_1_24A4C */
typedef struct {
    u8 pad[0x24];
    f32 *p24;
} fn_1_24A4C_Course;

/* fn_1_24A4C */
struct fn_1_24A4C_lbl_1_rodata_840 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x10];
    f64 unk_20;
    u8 pad_28[0x28];
    f64 unk_50;
    u8 pad_58[0x98];
    f32 unk_F0;
    u8 pad_F4[0x28];
    f32 unk_11C;
    u8 pad_120[0x28];
    f32 unk_148;
    f32 unk_14C;
    f64 unk_150;
    f32 unk_158;
    f32 unk_15C;
    f32 unk_160;
    f32 unk_164;
    f32 unk_168;
    f32 unk_16C;
    f32 unk_170;
    f32 unk_174;
};

/* fn_1_24F10 */
typedef struct Fn_1_24F10 {
    int flags;
    unsigned char pad04[0x2c];
    f32 field30;
    unsigned char pad34[0x150];
    f32 field184;
    unsigned char pad188[0x8c];
    u16 field214;
    unsigned char pad216[0x0e];
    f32 field224;
    unsigned char pad228[0x284];
    f32 field4ac;
    unsigned char pad4b0[0xe3];
    u8 field593;
    unsigned char pad594[0x46];
    u16 field5da;
} Fn_1_24F10;

/* fn_1_24F10 */
typedef struct Fn_1_25004_Obj {
    u32 flags00;
    s16 field04;
    u8 pad06[0x8e];
    f32 field94;
    f32 field98;
    f32 field9c;
    f32 fielda0;
    f32 fielda4;
    f32 fielda8;
    u8 padac[0xd0];
    f32 field17c;
    u8 pad180[0x4];
    f32 field184;
    u8 pad188[0x9c];
    f32 field224;
    u8 pad228[0x24c];
    u8 field474;
    u8 pad475[0x117];
    u32 flags58c;
} Fn_1_25004_Obj;

/* fn_1_24F10 */
typedef struct Fn_1_25004_Result {
    u8 pad390[0x390];
    u32 flags390;
} Fn_1_25004_Result;

/* fn_1_24F10 */
typedef struct Fn_1_250F8 {
    u32 flags;
    u8 pad04[0x180];
    f32 field184;
    u8 pad188[0x88];
    u16 field210;
    u8 pad212[0x01];
    u8 field213;
    u8 pad214[0x03];
    u8 field217;
    u8 pad218[0x29A];
    u8 field4b2;
    u8 pad4b3[0xD9];
    u32 field58c;
} Fn_1_250F8;

/* fn_1_253A4 */
typedef struct {
    u32 flag;                   // 0x0
    u8 _4[0x5c - 0x4];
} Corner;

/* fn_1_253A4 */
typedef struct {
    u32 state;                  // 0x0
    u8 _4[0x14 - 0x4];
    f32 f14;                    // 0x14
    f32 f18;                    // 0x18
    u8 _1c[0xa4 - 0x1c];
    f32 fa4;                    // 0xa4
    u8 _a8[0x1f8 - 0xa8];
    f32 f1f8;                   // 0x1f8
    f32 f1fc;                   // 0x1fc
    u8 _200[0x20c - 0x200];
    f32 f20c;                   // 0x20c
    u8 _210[0x244 - 0x210];
    Corner corner[4];           // 0x244
} ColObj;

/* fn_1_253A4 */
typedef struct {
    u8 _0[0xc];
    f32 kc;                     // 0xc
    u8 _10[0x14 - 0x10];
    f32 k14;                    // 0x14
    u8 _18[0x60 - 0x18];
    f32 k60;                    // 0x60
    u8 _64[0x84 - 0x64];
    f32 k84;                    // 0x84
    u8 _88[0x130 - 0x88];
    f32 k130;                   // 0x130
    u8 _134[0x180 - 0x134];
    f64 k180;                   // 0x180
} ScalePool;

/* fn_1_25480 */
typedef struct Node_fn_1_25480 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_25480 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_25480;

/* fn_1_25480 */
typedef struct StcoliNode_fn_1_25480 StcoliNode_fn_1_25480;

/* fn_1_25480 */
struct StcoliNode_fn_1_25480 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_25480 *items;
    u8 rest[0x3c];
};

/* fn_1_25480 */
struct fn_1_2B478_lbl_801A6D00_fn_1_25480 {
    u32 unk_0;
};

/* fn_1_25480 */
struct fn_1_2D524_Copy200_fn_1_25480 { u32 a[10][5]; };

/* fn_1_25480 */
struct fn_1_2D524_Copy8_fn_1_25480 { u32 a[2]; };

/* fn_1_25480 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_25480 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_25480 unk_58;
    struct fn_1_2D524_Copy8_fn_1_25480 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_25480 */
typedef struct Fn_1_25480_Obj {
    u32 flags;          /* 0x000 */
    u8 pad_4[0x4];
    f32 mass;           /* 0x008 */
    u8 pad_C[0x10];
    f32 f1C;            /* 0x01C */
    f32 f20;            /* 0x020 */
    u8 pad_24[0x8];
    f32 f2C;            /* 0x02C */
    u8 pad_30[0x64];
    Vec3 vel;          /* 0x094 */
    f32 fA0;            /* 0x0A0 */
    u8 pad_A4[0x4];
    f32 fA8;            /* 0x0A8 */
    u8 pad_AC[0xC];
    f32 fB8;            /* 0x0B8 */
    u8 pad_BC[0x4];
    f32 fC0;            /* 0x0C0 */
    u8 pad_C4[0x4];
    f32 fC8;            /* 0x0C8 */
    f32 fCC;            /* 0x0CC */
    f32 fD0;            /* 0x0D0 */
    f32 fD4;            /* 0x0D4 */
    u8 pad_D8[0xE4];
    f32 f1BC;           /* 0x1BC */
    f32 f1C0;           /* 0x1C0 */
    f32 f1C4;           /* 0x1C4 */
    u8 pad_1C8[0x24];
    f32 f1EC;           /* 0x1EC */
    f32 f1F0;           /* 0x1F0 */
    u8 pad_1F4[0x4];
    f32 f1F8;           /* 0x1F8 */
    f32 f1FC;           /* 0x1FC */
    u8 pad_200[0x18];
    u32 f218;           /* 0x218 */
    u8 pad_21C[0x264];
    u8 b480;            /* 0x480 */
    u8 pad_481[0x53];
    f32 f4D4;           /* 0x4D4 */
    u8 pad_4D8[0xB4];
    u32 f58C;           /* 0x58C */
    u8 pad_590[0x80];
    f32 f610;           /* 0x610 */
} Fn_1_25480_Obj;

/* fn_1_25480 */
typedef struct Fn_1_25870 {
    u32 flags;
    unsigned char pad04[0x1f4];
    f32 field1f8;
    f32 field1fc;
    unsigned char pad200[0x24];
    f32 field224;
    unsigned char pad228[0x1c];
    u32 field244;
    unsigned char pad248[0x58];
    u32 field2a0;
    unsigned char pad2a4[0x58];
    u32 field2fc;
    unsigned char pad300[0x58];
    u32 field358;
    unsigned char pad35c[0x11a];
    u8 field476;
    u8 field477;
} Fn_1_25870;

/* fn_1_25A14 */
typedef struct fn_1_25A14_Result {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x4];
    Vec3 unk_C;
    u32 unk_18;
} fn_1_25A14_Result;

/* fn_1_25A14 */
typedef struct fn_1_25A14_Corner5C {
    u32 unk_0;
    u8 pad_4[0x58];
} fn_1_25A14_Corner5C;

/* fn_1_25A14 */
typedef struct fn_1_25A14_Corner30 {
    Vec3 unk_0;
    Vec3 unk_C;
    Vec3 unk_18;
    Vec3 unk_24;
} fn_1_25A14_Corner30;

/* fn_1_25A14 */
typedef struct fn_1_25A14_Course {
    u8 pad_0[0x90];
    s32 *unk_90;
} fn_1_25A14_Course;

/* fn_1_25A14 */
typedef struct fn_1_25A14_Machine {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x192];
    Vec3 unk_198;
    Vec3 unk_1A4;
    Vec3 unk_1B0;
    u8 pad_1BC[0xC];
    f32 unk_1C8;
    u8 pad_1CC[0x4C];
    u32 unk_218;
    u8 pad_21C[0x28];
    fn_1_25A14_Corner5C unk_244[4];
    fn_1_25A14_Corner30 unk_3B4[4];
    u8 pad_474[0x14];
    fn_1_25A14_Result **unk_488[4];
    u8 pad_498[0x4];
    fn_1_25A14_Course *unk_49C;
    u8 pad_4A0[0x6C];
    u8 unk_50C;
    u8 pad_50D[0x2];
    u8 unk_50F;
    u8 pad_510[0x7C];
    u32 unk_58C;
    u8 pad_590[0x8C];
    u32 unk_61C;
} fn_1_25A14_Machine;

/* fn_1_266A8 */
typedef struct CollisionObject {
    u32 flags;
    u8 pad4[4];
    f32 scale;
    u8 padC[0x70];
    Vec3 position;
    u8 pad88[0xC];
    Vec3 velocity;
    u8 padA0[0x24];
    f32 field_c4;
    f32 field_c8;
    u8 padCC[0xB0];
    f32 field_17c;
    u8 pad180[4];
    f32 field_184;
    u8 pad188[2];
    u8 field_18a;
    u8 field_18b;
    u8 pad18C[0x24];
    Vec3 collision;
    Vec3 normal;
    u8 pad1C8[0x4B];
    u8 field_213;
    u16 field_214;
    u8 field_216;
    u8 pad217[0xD];
    f32 field_224;
    f32 field_228;
    u8 pad22C[0x18];
    u32 field_244;
    u8 pad248[0x58];
    u32 field_2a0;
    u8 pad2A4[0x58];
    u32 field_2fc;
    u8 pad300[0x58];
    u32 field_358;
    u8 pad35C[0x58];
    struct { Vec3 point; u8 pad[0x18]; Vec3 dest; } parts[4];
    s8 field_474;
    u8 pad475[0xC];
    u8 field_481;
    u8 pad482[0x2A];
    f32 field_4ac;
    u8 pad4B0[0x50];
    Vec3 field_500;
    u8 pad50C[0x87];
    u8 field_593;
    u8 pad594[0x46];
    u16 field_5da;
} CollisionObject;

/* fn_1_26F34 */
typedef struct Sig_fn_1_2A3E4_Fn_1_2A3E4 {
 u32 flags; unsigned char pad04[0x186]; u8 active; unsigned char pad18b[0x85]; u16 value210;
} Sig_fn_1_2A3E4_Fn_1_2A3E4;

/* fn_1_26F34 */
struct fn_1_26F34_lbl_1_rodata_840 {
 u8 pad0[12]; f32 unk_C; u8 pad10[4]; f32 unk_14; u8 pad18[4]; f32 unk_1C; f64 unk_20;
 f32 unk_28,unk_2C,unk_30,unk_34,unk_38,unk_3C,unk_40,unk_44;
 u8 pad48[0x20]; f32 unk_68; u8 pad6c[12]; f32 unk_78; u8 pad7c[0x1c]; f32 unk_98;
 u8 pad9c[8]; f32 unk_A4; u8 pada8[0x20]; f32 unk_C8; u8 padcc[0x38]; f32 unk_104;
 u8 pad108[12]; f32 unk_114; u8 pad118[4]; f32 unk_11C; u8 pad120[16]; f32 unk_130;
 u8 pad134[0x34]; f32 unk_168,unk_16C; u8 pad170[0xdc];
 f32 unk_24C,unk_250,unk_254,unk_258,unk_25C,unk_260,unk_264,unk_268;
};

/* fn_1_278B8 */
typedef struct CameraTarget {
    u8 pad_000[0x394];
    void *data;
} CameraTarget;

/* fn_1_278B8 */
struct fn_1_AA54_lbl_1_rodata_388 {
    f64 unk_0;
};

/* fn_1_278B8 */
typedef struct camera_reset_transition_Camera {
    u8 pad_00[0xA4];
    s16 unk_A4;
} camera_reset_transition_Camera;

/* fn_1_278B8 */
typedef struct camera_update_transition_Camera {
    u8 pad_00[0x78];
    s16 unk_78;
    u8 pad_7A[0x2A];
    s16 unk_A4;
} camera_update_transition_Camera;

/* fn_1_278B8 */
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

/* fn_1_278B8 */
typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

/* fn_1_278B8 */
typedef struct { u8 pad_0[0x4]; f32 unk_4; u32 unk_8; f32 unk_C; } Bss_104C;

/* fn_1_278B8 */
typedef struct fn_1_ABAC_Target {
    u8 pad_0[0x214];
    u16 unk_214;
} fn_1_ABAC_Target;

/* fn_1_278B8 */
typedef struct { u8 pad_0[0x20]; u32 unk_20; } Inner;

/* fn_1_278B8 */
typedef struct { u8 pad_0[0x8]; Inner *unk_8; } Outer;

/* fn_1_278B8 */
typedef struct {
    u8 data[0x10];
} CamEntry;

/* fn_1_278B8 */
struct fn_1_278B8_lbl_1_rodata_840 {
    u8 pad_0[0x8]; f32 unk_8; f32 unk_C; u8 pad_10[4];
    f32 unk_14; f32 unk_18; u8 pad_1C[4]; f64 unk_20;
    u8 pad_28[0xC]; f32 unk_34; f32 unk_38; u8 pad_3C[4];
    f32 unk_40; u8 pad_44[0xC]; f64 unk_50; u8 pad_58[0x10];
    f32 unk_68; u8 pad_6C[0xC]; f32 unk_78; u8 pad_7C[0x4C];
    f32 unk_C8; u8 pad_CC[0x38]; f32 unk_104; u8 pad_108[0x70];
    f32 unk_178; u8 pad_17C[0x1C]; f32 unk_198; f32 unk_19C;
    u8 pad_1A0[0x20]; f64 unk_1C0; u8 pad_1C8[0xA8];
    f64 unk_270; f64 unk_278; f64 unk_280; f32 unk_288; f32 unk_28C;
};

/* fn_1_278B8 */
typedef struct {
    u32 flags;
    u8 pad_4[0x78];
    Vec3 position;
    Vec3 previous;
    u8 pad_94[0x140];
    Vec3 displacement;
} CollisionObject_278B8;

/* fn_1_27E34 */
typedef struct {
    u32 flag;
    u8 pad_4[0x18];
    u32 f_1c;
    u8 pad_20[0x1c];
    u32 m_3c;
    u8 pad_40[0xc];
    u32 f_4c;
    u8 pad_50[0xc];
} Agg;

/* fn_1_27E34 */
typedef struct {
    Agg *a;
    Agg *b;
} Group;

/* fn_1_27E34 */
typedef struct {
    Agg * a;
    Agg * b;
    Agg list_a;
    Agg list_b;
} Ctx_27E34;

/* fn_1_27E34 */
typedef struct {
    u8 pad_0[0x47c];
    u32 f_47c;
} MgrEntry;

/* fn_1_27E34 */
typedef struct {
    u8 pad_0[0x24];
    u32 f_24;
    u8 pad_28[0xe4];
    u32 f_10c;
    u32 f_110;
    f32 f_114;
    u32 f_118;
    u8 pad_11c[0x5e4];
    u32 f_700;
} Mgr_27E34;

/* fn_1_27E34 */
typedef struct {
    u32 flags;
    s16 f_4;
    u8 pad_6[0x1b6];
    Vec3 v_1bc;
    f32 v_1c8;
    u32 v_1cc;
    f32 v_1d0;
    Vec3 v_1d4;
    u8 pad_1e0[0x3c];
    u32 v_21c;
    u8 pad_220[0x268];
    Group *g_488;
    Group *g_48c;
    Group *g_490;
    Group *g_494;
    u8 pad_498[0x64];
    u32 v_4fc;
    u8 pad_500[0x11c];
    s32 v_61c;
} Object;

/* fn_1_28184 */
typedef struct Racer28184 {
    u32 flags;          /* 0x000 */
    s16 id;             /* 0x004 */
    u8 pad_006[0x2];
    f32 unk_8;          /* 0x008 */
    u8 pad_00C[0x24];
    f32 unk_30;         /* 0x030 */
    u8 pad_034[0x48];
    Vec3 pos;           /* 0x07C */
    Vec3 center;        /* 0x088 */
    Vec3 vel;           /* 0x094 */
    u8 pad_0A0[0x24];
    f32 unk_C4;         /* 0x0C4 */
    f32 unk_C8;         /* 0x0C8 */
    u8 pad_0CC[0x20];
    u8 mtx[0x90];       /* 0x0EC */
    f32 unk_17C;        /* 0x17C */
    u8 pad_180[0x4];
    f32 unk_184;        /* 0x184 */
    u8 pad_188[0x34];
    Vec3 axis;          /* 0x1BC */
    u8 pad_1C8[0x4C];
    u16 unk_214;        /* 0x214 */
    u8 pad_216[0x2];
    u32 flags2;         /* 0x218 */
    u8 pad_21C[0x8];
    f32 unk_224;        /* 0x224 */
    u8 pad_228[0x284];
    f32 unk_4AC;        /* 0x4AC */
    u8 pad_4B0[0xE3];
    u8 unk_593;         /* 0x593 */
    u8 pad_594[0x46];
    u16 unk_5DA;        /* 0x5DA */
} Racer28184;

/* fn_1_28184 */
struct fn_1_28184_Pool {
    u8 pad_0[0xC];
    f32 zero;           /* 0x00C */
    u8 pad_10[0x4];
    f32 one;            /* 0x014 */
    u8 pad_18[0x8];
    f64 u2f_bias;       /* 0x020 */
    u8 pad_28[0xC];
    f32 four;           /* 0x034 */
    f32 ratio_max;      /* 0x038 */
    u8 pad_3C[0x24];
    f32 quarter;        /* 0x060 */
    u8 pad_64[0x14];
    f32 two;            /* 0x078 */
    u8 pad_7C[0x4C];
    f32 ratio_min;      /* 0x0C8 */
    u8 pad_CC[0x48];
    f32 epsilon;        /* 0x114 */
    u8 pad_118[0x50];
    f32 ten;            /* 0x168 */
    u8 pad_16C[0xC];
    f32 twenty;         /* 0x178 */
    f32 speed_scale;    /* 0x17C */
    u8 pad_180[0x28];
    f64 delta_scale;    /* 0x1A8 */
    u8 pad_1B0[0x98];
    f32 minus_one;      /* 0x248 */
    u8 pad_24C[0x48];
    f32 threshold;      /* 0x294 */
    f32 six;            /* 0x298 */
};

/* fn_1_28660 */
typedef struct Fn_1_287E8 {
    unsigned int flags;
    unsigned char pad04[0x178];
    f32 field17c;
    unsigned char pad180[0x10];
    unsigned int field190;
    unsigned short field194;
    unsigned char field196;
    unsigned char pad197[0x65];
    f32 field1fc;
    f32 field200;
    unsigned char pad204[0x0e];
    s8 field212;
    unsigned char pad213[0x26d];
    unsigned char field480;
    unsigned char pad481[0x43];
    unsigned char field4c4;
} Fn_1_287E8;

/* fn_1_289B4 */
struct fn_1_2D524_Copy200_289B4 { u32 a[10][5]; };

/* fn_1_289B4 */
struct fn_1_2D524_Copy8_289B4 { u32 a[2]; };

/* fn_1_28F08 */
typedef struct {
    f32 pad[43];
    f32 inv_x;
    f32 inv_y;
    f32 inv_z;
} ScaleInfo;

/* fn_1_29044 */
typedef struct {
    u8 pad[0xA0];
    Vec3 v;
} Object29044;

/* fn_1_290E8 */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x88];
    Vec3 unk_94;
    u8 pad_A0[0x4C];
    f32 unk_EC[12];
    u8 pad_11C[0x64];
    f32 unk_180;
    u8 pad_184[0x38];
    Vec3 unk_1BC;
    f32 unk_1C8;
    u8 pad_1CC[0x50];
    u32 unk_21C;
} Racer290E8;

/* fn_1_294D0 */
typedef struct Node_fn_1_294D0 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_294D0 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_294D0;

/* fn_1_294D0 */
typedef struct StcoliNode_fn_1_294D0 StcoliNode_fn_1_294D0;

/* fn_1_294D0 */
struct StcoliNode_fn_1_294D0 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_294D0 *items;
    u8 rest[0x3c];
};

/* fn_1_294D0 */
struct fn_1_2B478_lbl_801A6D00_fn_1_294D0 {
    u32 unk_0;
};

/* fn_1_294D0 */
struct fn_1_2D524_Copy200_fn_1_294D0 { u32 a[10][5]; };

/* fn_1_294D0 */
struct fn_1_2D524_Copy8_fn_1_294D0 { u32 a[2]; };

/* fn_1_294D0 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_294D0 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_294D0 unk_58;
    struct fn_1_2D524_Copy8_fn_1_294D0 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_294D0 */
typedef struct fn_1_294D0_Body {
    u32 flags;           /* 0x000 */
    u8 pad_4[0x4];
    f32 mass;            /* 0x008 */
    u8 pad_C[0x88];
    Vec3 vel;           /* 0x094 */
    u8 pad_A0[0x11C];
    Vec3 normal;        /* 0x1BC */
    u8 pad_1C8[0x2B0];
    f32 drag;            /* 0x478 */
    u8 pad_47C[0x64];
    u16 boostTimer;      /* 0x4E0 */
} fn_1_294D0_Body;

/* fn_1_294D0 */
typedef struct Node_fn_1_29800 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_29800 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_29800;

/* fn_1_294D0 */
typedef struct StcoliNode_fn_1_29800 StcoliNode_fn_1_29800;

/* fn_1_294D0 */
struct StcoliNode_fn_1_29800 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_29800 *items;
    u8 rest[0x3c];
};

/* fn_1_294D0 */
struct fn_1_2B478_lbl_801A6D00_fn_1_29800 {
    u32 unk_0;
};

/* fn_1_294D0 */
struct Pool_fn_1_29800 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_294D0 */
struct fn_1_207DC_pool_fn_1_29800 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_294D0 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_29800 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_294D0 */
struct fn_1_2D524_Copy200_fn_1_29800 { char *a[10][5]; };

/* fn_1_294D0 */
struct fn_1_2D524_Copy8_fn_1_29800 { char *a[2]; };

/* fn_1_294D0 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_29800 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_29800 unk_58;
    struct fn_1_2D524_Copy8_fn_1_29800 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_294D0 */
struct S {
    u32 flags;
    u8 pad_4[0x17C];
    f32 f180;
    u8 pad_184[0x70];
    f32 f1F4;
    u8 pad_1F8[0x4];
    f32 f1FC;
    u8 pad_200[0x1C];
    u32 f21C;
    u8 pad_220[0x261];
    u8 b481;
    u8 pad_482[0x1];
    u8 b483;
    u8 pad_484[0x108];
    u32 f58C;
};

/* fn_1_29A0C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Quat_29A0C;

/* fn_1_29A0C */
typedef struct {
    f32 unk_0[3][4];
} Mtx34;

/* fn_1_29A0C */
typedef struct {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    f32 unk_8;
    u8 pad_C[0x10];
    f32 unk_1C;
    u8 pad_20[0x5C];
    Vec3 unk_7C;
    u8 pad_88[0xC];
    Vec3 unk_94;
    u32 unk_A0;
    f32 unk_A4;
    u32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    u8 pad_B8[0xC];
    f32 unk_C4;
    f32 unk_C8;
    u8 pad_CC[0x20];
    Mtx34 unk_EC;
    u8 pad_11C[0x30];
    Mtx34 unk_14C;
    f32 unk_17C;
    u8 pad_180[0xC];
    f32 unk_18C;
    u32 unk_190;
    u8 pad_194[0x2];
    u8 unk_196;
    u8 pad_197[0x59];
    f32 unk_1F0;
    u8 pad_1F4[0x24];
    u32 unk_218;
    u8 pad_21C[0x8];
    f32 unk_224;
    u8 pad_228[0x2C];
    f32 unk_254;
    u8 pad_258[0xB4];
    f32 unk_30C;
    u8 pad_310[0x168];
    f32 unk_478;
    u8 pad_47C[0x5];
    u8 unk_481;
    u8 pad_482[0x2E];
    s16 unk_4B0;
    u8 pad_4B2[0x22];
    f32 unk_4D4;
    f32 unk_4D8;
    u8 pad_4DC[0x8];
    f32 unk_4E4;
    f32 unk_4E8;
    f32 unk_4EC;
    u8 pad_4F0[0x9C];
    u32 unk_58C;
    u8 pad_590[0x34];
    Quat_29A0C unk_5C4;
    f32 unk_5D4;
    u8 pad_5D8[0x8];
    Mtx34 unk_5E0;
} Machine;

/* fn_1_29A0C */
typedef struct {
    u8 pad_0[0x390];
    u32 unk_390;
} Other;

/* fn_1_2A214 */
typedef struct {
    unsigned int flags;
    unsigned char pad4[0x9c];
    float a0;
    float a4;
    float a8;
    float pad_ac;
    float b0;
} StColiObj;

/* fn_1_2A2A4 */
typedef struct {
    u8 pad00[0xec];
    u8 field_ec[0xd0];
    u8 pad_1bc[0x1bc];
} Fn1_2A2A4Object;

/* fn_1_2A2A4 */
typedef struct Fn_1_2A318 {
    unsigned char pad000[0x184];
    f32 field184;
    unsigned char pad188[0x02];
    unsigned char field18a;
    unsigned char pad18b[0x85];
    u16 field210;
    unsigned char field212;
    unsigned char pad213[0x26f];
    unsigned char field482;
    unsigned char pad483[0x10f];
    unsigned char field592;
    unsigned char pad593[0x47];
    u16 field5da;
} Fn_1_2A318;

/* fn_1_2A41C */
typedef struct Fn_1_2A41C {
    u32 flags;
    unsigned char pad04[0x190];
    u16 value194;
} Fn_1_2A41C;

/* fn_1_2A41C */
struct CalcOut {
    u32 flags;
    void *self;
    f32 scale;
    Vec3 v;
};

/* fn_1_2A694 */
typedef struct O { u32 flags; s16 id; u8 p[0x46e]; u8 v474; u8 p2[0x23]; u32 field498; Sig_fn_1_2A694_N *field49c; u8 p3[0xec]; u32 field58c; } O;

/* fn_1_2A694 */
typedef struct R { u8 p[0x160]; u32 flags160; u8 p2[0x1c]; u32 v180; u32 v184; u32 v188; } R;

/* fn_1_2A694 */
typedef struct P { u32 x; u32 y; } P;

/* fn_1_2A8D0 */
typedef struct Sig_fn_1_2A694_O_2A8D0 { u32 flags; s16 id; u8 p[0x46e]; s8 v474; u8 p2[0x23]; u32 field498; Sig_fn_1_2A694_N *field49c; u8 p3[0xec]; u32 field58c; } Sig_fn_1_2A694_O_2A8D0;

/* fn_1_2A8D0 */
struct fn_1_2A8D0_Copy12 { u32 a[3]; };

/* fn_1_2ABD4 */
typedef struct fn_1_2ABD4_Body {
    u32 flags;              /* 0x000 */
    s16 id;                 /* 0x004 */
    u8 pad_6[0x2];
    f32 mass;               /* 0x008 */
    u8 pad_C[0x1BC];
    f32 f1C8;               /* 0x1C8 */
    u8 pad_1CC[0x2B5];
    u8 b481;                /* 0x481 */
    u8 pad_482[0x16];
    u32 f498;               /* 0x498 */
} fn_1_2ABD4_Body;

/* fn_1_2ABD4 */
typedef struct fn_1_2ABD4_Wheel {
    u32 flags;              /* 0x00 */
    u8 pad_4[0x4];
    Vec3 pos;     /* 0x08 */
    u8 pad_14[0xC];
    Vec3 contact; /* 0x20 */
    Vec3 normal;  /* 0x2C */
    Vec3 hitNormal; /* 0x38 */
    f32 compression;        /* 0x44 */
    f32 length;             /* 0x48 */
    Vec3 force;   /* 0x4C */
    f32 forceMag;           /* 0x58 */
} fn_1_2ABD4_Wheel;

/* fn_1_2ABD4 */
typedef struct fn_1_2ABD4_Node {
    u8 pad_0[0x98];
    u32 v98;
    u32 v9c;
} fn_1_2ABD4_Node;

/* fn_1_2AF0C */
typedef struct HoverCorner {
    u32 unk_0;          /* 0x00 ground/air state (0x2 in contact) */
    u8 pad_4[0x1C];
    Vec3 unk_20;       /* 0x20 world position, current */
    Vec3 unk_2C;   /* 0x2C track normal 1 */
    Vec3 unk_38;   /* 0x38 track normal 2 */
    f32 unk_44;          /* 0x44 slope / compression */
    u8 pad_48[0x4];
    Vec3 unk_4C;     /* 0x4C suspension force (machine frame) */
    f32 unk_58;      /* 0x58 suspension magnitude */
} HoverCorner;

/* fn_1_2AF0C */
typedef struct HoverMachine {
    u8 pad_0[0x1C8];
    f32 unk_1C8;
    u8 pad_1CC[0x4C];
    u32 unk_218;          /* 0x218 */
    u8 pad_21C[0x28];
    HoverCorner unk_244[4];     /* 0x244 */
    u8 pad_3B4[0xD4];
    void *unk_488[4];     /* 0x488 track-query records (0xC0 each) */
    u8 pad_498[0x74];
    u8 unk_50C;
    u8 pad_50D[0x7F];
    u32 unk_58C;                 /* 0x58C */
} HoverMachine;

/* fn_1_2AF0C */
typedef struct CornerQuad {
    u8 unk_0[4];
} CornerQuad;

/* fn_1_2AF0C */
typedef struct CornerQuads {
    CornerQuad unk_0[5];
} CornerQuads;

/* fn_1_2AF0C */
struct fn_1_2AF0C_pool {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x32C];
    CornerQuads unk_344;
};

/* fn_1_2B478 */
struct fn_1_2B478_Arg0 {
    u8 pad_0[0x1C8];
    f32 unk_1C8;
    u8 pad_1CC[0x2D0];
    u32 unk_49C;
};

/* fn_1_2B478 */
typedef struct Node_fn_1_2B524 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_2B524 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_2B524;

/* fn_1_2B478 */
typedef struct StcoliNode_fn_1_2B524 StcoliNode_fn_1_2B524;

/* fn_1_2B478 */
struct StcoliNode_fn_1_2B524 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_2B524 *items;
    u8 rest[0x3c];
};

/* fn_1_2B478 */
struct fn_1_2B478_lbl_801A6D00_fn_1_2B524 {
    u32 unk_0;
};

/* fn_1_2B478 */
struct Pool_fn_1_2B524 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_2B478 */
struct fn_1_207DC_pool_fn_1_2B524 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_2B478 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_2B524 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_2B478 */
struct fn_1_2D524_Copy200_fn_1_2B524 { char *a[10][5]; };

/* fn_1_2B478 */
struct fn_1_2D524_Copy8_fn_1_2B524 { char *a[2]; };

/* fn_1_2B478 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_2B524 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_2B524 unk_58;
    struct fn_1_2D524_Copy8_fn_1_2B524 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_2B478 */
typedef struct {
    u8 pad_0[8];
    f32 ang;
    u8 pad_c[0x7c - 0xc];
    u32 h0, h1, h2;
    u8 pad_88[0xa0 - 0x88];
    Vec3 vel;
    u8 pad_ac[0x224 - 0xac];
    u32 h3;
} Fn2B524_Self;

/* fn_1_2B684 */
typedef struct Fn2B684Obj {
    u8 pad_0[0x8];
    f32 mass;            /* 0x08 */
    u8 pad_C[0x70];
    u32 seed7C;          /* 0x7C */
    u32 seed80;          /* 0x80 */
    u32 seed84;          /* 0x84 */
    u8 pad_88[0xC];
    Vec3 vel;           /* 0x94 */
    Vec3 posA0;         /* 0xA0 */
    u8 pad_AC[0xA0];
    u8 mtx14C[0x30];     /* 0x14C */
    f32 f17C;            /* 0x17C */
    u8 pad_180[0x3C];
    Vec3 dir1BC;        /* 0x1BC */
    u8 pad_1C8[0x318];
    u16 timer;           /* 0x4E0 */
    u8 pad_4E2[0xE];
    Vec3 pos4F0;        /* 0x4F0 */
    u8 pad_4FC[0x90];
    u32 flags;           /* 0x58C */
} Fn2B684Obj;

/* fn_1_2BA48 */
typedef struct {
	u32 a;
	u32 b;
	u32 c;
} U24;

/* fn_1_2BA48 */
typedef struct {
	u32 unk_0;
	s16 unk_4;
	u8 pad_6[0x76];
	U24 unk_7c;
	U24 unk_88;
	f32 unk_94;
	f32 unk_98;
	f32 unk_9c;
	u8 pad_a0[0x3d4];
	u8 unk_474;
	u8 unk_475;
	u8 pad_476[0x6a];
	u16 unk_4e0;
	Vec3 unk_4e4;
	Vec3 unk_4f0;
	u8 pad_4fc[0x11];
	u8 unk_50d;
	u8 pad_50e[0x7e];
	u32 unk_58c;
} St;

/* fn_1_2BA48 */
typedef struct Fn_1_2BBD0 {
    unsigned char pad00[0x7c];
    Vec3 pos;
    unsigned char pad88[0x42c];
    Vec3 position;
    u8 active;
    u8 value4c1;
} Fn_1_2BBD0;

/* fn_1_2BA48 */
typedef struct Fn_1_2BBD0Arg {
    unsigned char pad00[0x04];
    s16 value04;
    unsigned char pad06[0x76];
    Vec3 pos;
} Fn_1_2BBD0Arg;

/* fn_1_2BD30 */
typedef struct {
    u8 pad_0[0xC];
    f32 zero;        /* 0x00C */
    u8 pad_10[0x104];
    f32 eps;         /* 0x114: 1.1920929e-7f */
    u8 pad_118[0x130];
    f32 neg_one;     /* 0x248: -1.0f */
    u8 pad_24C[0x12C];
    f64 y_weight;    /* 0x378: 0.05 */
} StcoliPool2BD30;

/* fn_1_2BD30 */
typedef struct StcoliObj2BD30 {
    u8 pad0[0x8];
    f32 scale;          /* 0x08 */
    u8 padC[0x7C - 0xC];
    Vec3 pos;           /* 0x7C */
    u8 pad88[0x94 - 0x88];
    f32 velX;           /* 0x94 */
    f32 velY;           /* 0x98 */
    f32 velZ;           /* 0x9C */
    u8 padA0[0xEC - 0xA0];
    Vec3 rot;           /* 0xEC */
    u8 padF8[0x1BC - 0xF8];
    u8 ref[0x10];       /* 0x1BC */
} StcoliObj2BD30;

/* fn_1_2BD30 */
typedef struct StcoliOut2BD30 {
    u8 pad0[0xC];
    Vec3 dir;           /* 0x0C */
    Vec3 axis;          /* 0x18 */
    u8 pad24[0x30 - 0x24];
    f32 speed;          /* 0x30 */
    f32 depth;          /* 0x34 */
} StcoliOut2BD30;

/* fn_1_2BF8C */
struct fn_1_2BF8C_lbl_1_rodata_840 {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f64 unk_20;
    u8 pad_28[0x358];
    f64 unk_380;
    f64 unk_388;
    f32 unk_390;
};

extern void ADXT_Stop(void *);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void OSReport(const char *format, ...);
extern f64 __fabs(f64);
extern f32 __fmadds(f32, f32, f32);
extern void fn_1_12860(void *, void *);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2);
extern s32 fn_1_154C84(void);
extern char *fn_1_15BA78(char *name);
extern u32 fn_1_304A8(void);
extern void fn_1_3F2A0(void);
extern u32 fn_1_4060(void);
extern void fn_1_40E08(u32 arg0);
extern u32 fn_1_435C(u32 value);
extern int fn_1_45730(void *, void *);
extern int fn_1_45850(void *);
extern int fn_1_458A0(void *, void *, u32, u32);
extern void *fn_1_45D0(void *, u32, void *, u32);
extern void fn_1_465D0(char *, int);
extern void fn_1_46B4(void *, void *, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49F0(u32 *value);
extern void fn_1_4A00(s32 enabled, u8 mode, void *value);
extern void fn_1_4A0D8(const char *);
extern u32 fn_1_4AEC0(u32 value);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(s32 value);
extern int fn_1_4C10(void);
extern void fn_1_50A90(void *, s32, s32, s32, s32);
extern void fn_1_694A4(s32, Vec3 *, Vec3 *, f32);
extern s16 fn_1_7B054(void);
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern s8 fn_1_84124(Fn183D28Car *, s8, s8, u8 *);
extern s8 fn_1_84408(CarTestCar *);
extern s8 fn_1_84644(Fn183D28Body *);
extern u32 fn_1_8627C(s32 index);
extern void fn_1_862D4(u8 index, Vec3 *out);
extern void fn_1_8658C(u8 index, Vec3 *out);
extern void *fn_1_868C0(s8 index);
extern void fn_1_8A168(void *);
extern void fn_1_8A190(void *, void *);
extern u32 fn_1_8C66C(u32 index);
extern s32 fn_1_8C6D4(s16);
extern s32 fn_1_8C704(s16);
extern void fn_1_8E084(CarTestCar *, u32 *, s32);
extern u32 fn_1_9D260(void);
extern void fn_1_9D420(void *, s32);
extern void fn_1_9D77C(u32, u32);
extern f32 fn_1_9E14C(u32, u32, f32);
extern f32 fn_1_9E170(u32, u32, void *, f32);
extern f32 fn_1_9E194(f32, u32, void *);
extern u32 fn_1_A1588(void *, u32);
extern void fn_1_A2D84(u32);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_A33F0(s32, f32);
extern void fn_1_AEB8(camera_reset_transition_Camera *);
extern void fn_1_AFC8(camera_update_transition_Camera *);
extern void fn_1_EB080(int mode);
extern int fn_1_EB248(void);
extern void fn_1_F2008(s32 arg);
extern u32 fn_1_F22D4(void);
extern u32 fn_1_F45B4(void);
extern void fn_1_F7338(int arg0, void *arg1, void *arg2);
extern void fn_1_F7F48(s16);
extern void fn_1_F83F0(s16 arg0);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F8C00(s32 value);
extern u32 fn_1_F8D10(void);
extern void fn_1_F8D38(u32 value);
extern void fn_1_F9D68(u32 arg);
extern void fn_1_F9DE8(u32 param);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008DB4(void *, f32, void *, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8006E250(void *, void *);
extern void fn_8006E2B0(void *, Vec3 *);
extern void fn_8006E5FC(Quat_29A0C *);
extern void fn_8006E7E4(void *, void *, s32);
extern void fn_8006E978(void *, void *, void *);
extern void fn_8006EB4C(Quat_29A0C *, Quat_29A0C *, Quat_29A0C *, f32);
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void fn_80072558(void);
extern void fn_800793D4(void *, int, u32);
extern int strcmp(const u8 *, const u8 *);
extern Bss_104C lbl_1_bss_104C;
extern u32 lbl_1_bss_25B9C;
extern Outer *lbl_1_bss_38454;
extern u32 lbl_1_bss_3BBC;
extern u8 lbl_1_bss_3BC0[32];
extern CellMtx *lbl_1_bss_3BE4;
extern u8 lbl_1_bss_6F316;
extern f32 lbl_1_bss_7AC88;
extern f32 lbl_1_bss_7AC9C;
extern u8 lbl_1_bss_8E51D;
extern char lbl_1_bss_9C;
extern char *lbl_1_data_2BD54[][6];
extern f32 lbl_1_data_4;
extern const struct fn_1_2D038_Text lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_3508[4];
extern struct fn_1_AA54_lbl_1_rodata_388 lbl_1_rodata_388;
extern struct fn_1_2D524_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern u32 lbl_1_rodata_D18;
extern u32 lbl_1_rodata_D1C[11];
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D188(s16);
extern void lbl_8006D1B8(s16, f32 *);
extern void lbl_8006D1BC(s32, f32 *, f32 *);
extern s32 lbl_8006D24C(f32, f32);
extern s16 lbl_8006D2AC(f32);
extern void *lbl_8006D5A4(void *, u32, void *, f32);
extern void lbl_8006D5F0(void *, void *, f32);
extern f32 lbl_8006D668(void *);
extern f32 lbl_8006D6FC(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006D9D8(CamEntry *);
extern void lbl_8006DA50(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(int, int);
extern void * lbl_8006DC34(void *);
extern void lbl_8006DC6C(void *);
extern u32 lbl_8006DCA4(void);
extern u32 lbl_8006DD14(u32, void *);
extern void * lbl_8006DD48(void *, void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DF44(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DFE8(Vec3 *);
extern void lbl_8006E0A4(Vec3 *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E0C8(void *);
extern void lbl_8006E13C(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006E1D8(Vec3 *, f32, f32, f32);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern s32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern s32 lbl_801A66C8[];
/* One collision contact (hit or candidate) of the collision work area, 0x48 bytes. */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    f32 unk_8;
    u32 flags;
    f32 t;
    Vec3 point;
    Vec3 normal;
    Vec3 correction;
    Vec3 position;
    u32 *link;
} ColiContact;

/* One probe record of the collision work area, 0x80 bytes. */
typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 mask;
} ColiProbe;

/* One box volume of the collision work area, 0x40 bytes. */
typedef struct {
    f32 mtx[3][4];
    Vec3 scale;
    f32 height;
} ColiVolume;

/* The collision work area that lbl_801A66CC points to. */
typedef struct {
    u8 pad_0[0xD4];
    Vec3 delta;
    u8 pad_e0[0x1B0 - 0xE0];
    f32 radius;
    f32 unk_1B4;
    s32 count;
    s32 index;
    s32 segment;
    f32 time;
    u32 unk_1C8;
    s32 total;
    s32 num_volumes;
    u32 flags;
    s32 enabled;
    f32 unk_1DC;
    f32 unk_1E0;
    ColiContact hits[5];
    ColiContact contacts[8];
    s32 contact_ids[8];
    s32 num_contacts;
    ColiProbe probes[4];
    ColiVolume volumes[4];
    fn_1_1C0D0_Ctx *ctx;
} ColiWork;

extern ColiWork *lbl_801A66CC;
extern f32 *lbl_801A6D00;
extern void mathutil_mtxA_from_quat(void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void *memset(void *, int, unsigned int);
extern int sprintf(char *s, const char *format, ...);
extern char *strncpy(char *, const char *, unsigned long);

void fn_1_1384C(Fn1_1384C_List **arg0);
void fn_1_13A28(Fn1_13A28 *arg0, s32 arg1);
void fn_1_13B98(s32 course, s32 initModels);
void fn_1_14CB4(void);
void fn_1_14D5C(char *arg0, int arg1);
u32 fn_1_14DC4(void);
void fn_1_14DE8(u32 index);
u8 * fn_1_14F04(void);
s32 fn_1_14F18(Vec3 *pos, void *arg1, Vec3 *dir, f32 *outT, fn_1_14F18_Poly *poly, s32 count, u32 flags, f32 radius);
s32 fn_1_15248(Vec3 *pos, Vec3 *arg1, fn_1_15248_Poly *poly, s32 n, f32 radius);
s32 fn_1_15578(Vec3 *arg0, Vec3 *arg1, f32 *outT, Vec3 *outNrm, u32 flags, s32 *arg5, s32 arg6, s32 arg7, s32 arg8, Racer *racer);
s32 fn_1_163BC(Vec3 *arg0, Vec3 *arg1, s32 mask, s32 arg3);
s32 fn_1_16BA0(Vec3 *pos, f32 *ratio, s32 idx, s32 *sub, s32 strict);
f32 fn_1_16E68(Vec3 *pos, s32 idx, s32 sub);
u32 fn_1_17098(void *arg0, u32 arg1, u32 v1, u32 arg3, u32 arg4, ColiContext *ctx, void *arg6);
void fn_1_17920(s32 index, void *arg1, f32 t);
s32 fn_1_17A9C(const f32 *arg0);
int fn_1_17B5C(int a, int b, int count, f32 threshold);
int fn_1_17C6C(int current, int next, int limit);
void fn_1_17D5C(Node *node, u32 *acc);
int fn_1_17FCC(int a, int b, int c);
int fn_1_180F4(int first, int second, int count, int ascending);
void fn_1_181CC(int a, int b, int c);
void fn_1_181F0(int a, int b, int c);
void fn_1_18214(Entity *arg0, f32 *arg1, Stack *arg2, f32 t);
void fn_1_18784(u32 arg0, Motion *a, Vec3 *b, void *c, f32 d);
void fn_1_18B40(void * arg0, void * arg1, u32 arg2, struct fn_1_18B40_Obj *arg3, struct fn_1_18B40_Vec *arg4, int arg5, void * arg6, void * arg7, f32 arg8, u32 arg9);
void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value);
void fn_1_18FFC(int a, int b, int c, int d, int e, int f, int g);
void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value);
int fn_1_192E8(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2, Vec3 *arg3, struct fn_1_192E8_Arg4 *arg4, f32 *arg5, struct fn_1_192E8_Context *arg6, int arg7, u32 *arg9_input, int arg10_input, f32 arg8);
void fn_1_19AE0(Vec3 *arg0, Vec3 *arg1, u32 arg2, Seg *seg, Vec3 *scale, Ctx *ctx, void *arg6, s32 id, f32 arg8);
void fn_1_1ACC0(Vec3 *arg0, Vec3 *arg1, fn_1_1ACC0_Seg *arg2, f32 *arg3, f32 arg4);
void fn_1_1B010(u32 arg0, void *pos, u32 mode, StcoliEntity *entity, f32 *out, u32 arg5, void *work, f32 value);
void fn_1_1B2A4(Vec3 *arg0, Vec3 *arg1, u32 arg2, Seg_1B2A4 *seg, Vec3 *scale, Ctx *ctx, void *arg6, s32 id, f32 arg8);
void fn_1_1C0D0(Vec3 *a, Vec3 *b, u32 flags, fn_1_1C0D0_Wall *wall, f32 *scale, fn_1_1C0D0_Ctx *ctx, void *arg6, int id, f32 arg8);
void fn_1_1D0CC(Vec3 *arg0, Vec3 *arg1, u32 arg2, Segment *arg3, Vec3 *arg4, CollCtx *arg5, void *arg6, s32 arg7, f32 arg8);
void fn_1_1DCD8(Vec3 *arg0, Vec3 *arg1, u32 arg2, Segment_1DCD8 *arg3, Vec3 *arg4, CollCtx *arg5, void *arg6, s32 arg7, f32 arg8);
void fn_1_1EBD4(Vec3 *arg0, Vec3 *arg1, u32 arg2, Segment *seg, Vec3 *scale, Ctx *ctx, void *arg6, int id, f32 arg8);
u32 fn_1_1FB80(void *pos, u32 mask);
u32 fn_1_1FC98(void *pos, u32 mask);
f32 fn_1_1FDB0(struct fn_1_1FDB0_Arg0 *arg0, struct fn_1_1FDB0_Arg1 *arg1, struct fn_1_1FDB0_Arg2 *arg2, struct fn_1_1FDB0_Arg3 *arg3);
f32 fn_1_1FFA0(Vec3 *p1, Vec3 *p2, Vec3 *p3, Vec3 *p4, Vec3 *outA, Vec3 *outB);
f32 fn_1_20258(Fn_1_20258 *self, f32 *out_ratio);
void fn_1_203E4(fn_1_203E4_Obj *obj, s32 noOut, Vec3 *out, f32 pos, f32 scale, f32 dir);
void fn_1_207DC(struct fn_1_207DC_obj *obj, void *out, f32 x);
int fn_1_20994(void *arg, f32 *out);
s32 fn_1_20A5C(Vec3 *pos, f32 *out_t);
s32 fn_1_210A8(Vec3 *pos, f32 *out_t, s32 index, s32 mode, Vec3 *out_pos);
s32 fn_1_214C4(f32 *out, s32 start, f32 x);
void *fn_1_21644(void *arg0, f32 *arg1, void *arg2);
void fn_1_216C0(void *arg0, void *arg1, void *arg2);
s32 fn_1_216F0(Vec3 *pos, s32 idx, s32 sub);
void fn_1_2192C(void *self, void *arg);
void fn_1_21950(u32 arg0, f32 arg1, f32 arg2);
void fn_1_21BE4(Fn_1_21BE4 *self, void *arg);
void fn_1_21C5C(void *self, void *arg);
void fn_1_21CA0(Fn_1_21BE4 *self, void *arg);
void fn_1_21CFC(void *entity, Vec3 *scale, f32 t);
void fn_1_21F18(StcoliDrawEntity *entity, f32 *scale, f32 time);
void fn_1_2221C(fn_1_2221C_Obj *obj, Vec3 *scale, f32 t);
s32 fn_1_224F8(Vec3 *start, Vec3 *end, u32 *mask);
void fn_1_2277C(StcoliObj *obj, StcoliDesc *desc);
void fn_1_229EC(fn_1_229EC_ctrl *ctrl, f32 *out_pos, f32 *out_mag);
void fn_1_22B10(struct fn_1_22B10_Arg0 *p, f32 speed);
void fn_1_22E8C(Fn_1_22E8COutput *self, Fn_1_22E8CInput *source);
void fn_1_22F90(u8 *arg0, int arg1);
void fn_1_23500(Fn_1_23500 *self, f32 value);
void fn_1_235C8(Sig_fn_1_235C8_Fn_1_235C8 *self);
void fn_1_23610(void *self);
void fn_1_23640(Sig_fn_1_23640_Fn_1_23640 *self, int value);
void fn_1_236CC(Body *b);
s32 fn_1_239C4(struct fn_1_239C4_Arg0 *arg0, struct fn_1_239C4_Arg0 *arg1);
int fn_1_248C0(Fn_1_248C0 *self, int arg);
void fn_1_24A4C(fn_1_24A4C_Car *car);
int fn_1_24F10(Fn_1_24F10 *self, f32 value);
void fn_1_25004(Fn_1_25004_Obj *self);
void fn_1_250F8(Fn_1_250F8 *self);
s32 fn_1_251F8(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d, f32 *out, s32 *flag, f32 p, f32 q);
f32 fn_1_253A4(ColObj *p);
void fn_1_25480(Fn_1_25480_Obj *p, void *vel, f32 speed);
void fn_1_25870(Fn_1_25870 *self);
s32 fn_1_25A14(fn_1_25A14_Machine *m);
void fn_1_266A8(CollisionObject *obj);
f32 fn_1_26F34(u32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 fn_1_278B8(u8 *arg0, void *arg1, f32 arg2);
void fn_1_27DE4(CollisionObject_278B8 *obj);
s32 fn_1_27E34(Object *arg0);
void fn_1_28184(Racer28184 *r);
void fn_1_28660(Fn_1_28660 *self);
void fn_1_287E8(Fn_1_287E8 *self);
void fn_1_289B4(Body *p, u32 *out, void *arg2);
void fn_1_28F08(ScaleInfo *scale, Vec3 *src, f32 bias);
void fn_1_29044(Object29044 *self, Vec3 *vec, void *arg2);
void fn_1_290E8(Racer290E8 *p);
void fn_1_294D0(fn_1_294D0_Body *p);
void fn_1_29800(struct S *p);
void fn_1_29968(Sig_fn_1_29968_Owner *self);
void fn_1_29A0C(Machine *m);
void fn_1_2A214(StColiObj *obj);
void fn_1_2A2A4(Fn1_2A2A4Object *self);
void fn_1_2A318(Fn_1_2A318 *self);
void fn_1_2A3E4(Sig_fn_1_2A3E4_Fn_1_2A3E4 *self);
f32 fn_1_2A41C(Fn_1_2A41C *self, int arg);
s32 fn_1_2A500(void *self, Vec3 *out, Vec3 *pos, void *a, void *b, f32 *outF);
void fn_1_2A638(void *arg0, Fn_1_2A638 *self);
void fn_1_2A678(Fn_1_2A678_Source *self, Fn_1_2A678_Dest *dest);
int fn_1_2A694(O *self, void *arg1, Vec3 *swap, u32 mask, Vec3 *out0, Vec3 *out1);
int fn_1_2A8D0(Sig_fn_1_2A694_O_2A8D0 * arg0, u8 * arg1, u32 * arg2, u32 arg3, Vec3 * arg4, u32 * arg5, u32 * arg6, u32 arg7);
void fn_1_2ABD4(fn_1_2ABD4_Body *body, fn_1_2ABD4_Wheel *wheel);
s32 fn_1_2AF0C(HoverMachine *racer, Vec3 *normal);
f32 fn_1_2B478(void *arg0);
void fn_1_2B524(Fn2B524_Self *self);
void fn_1_2B684(Fn2B684Obj *obj);
void fn_1_2BA48(St *p);
void fn_1_2BBD0(Fn_1_2BBD0 *self, Fn_1_2BBD0Arg *other, f32 threshold);
f32 fn_1_2BD30(StcoliObj2BD30 *obj, StcoliOut2BD30 *out, Vec3 *src);
s32 fn_1_2BF8C(u32 arg0);
u32 fn_1_2C688(u32 arg0, u32 arg1, u32 arg2);

/* fzgx:begin fn_1_2277C */
/* 0x5c */

/* 0x30 */

static inline f32 stcoli_mag(Vec3 *v)
{
    f32 x, y, z;
    f32 sq;

    x = v->x;
    y = v->y;
    z = v->z;
    sq = x * x;
    sq += y * y;
    sq += z * z;
    return lbl_8006D0B4(sq);
}

void fn_1_2277C(StcoliObj *obj, StcoliDesc *desc)
{
    s32 i;
    f32 len;
    f32 ax;
    StcoliPoint *pt;

    obj->flags = 0;
    obj->s04 = 0;
    obj->s06 = 0;
    strncpy(obj->name, desc->name, 31);
    obj->name[31] = 0;
    fn_1_22E8C((void *)obj, (void *)desc);

    obj->fAC = 52.0f * obj->size / 16.0f;
    obj->fB0 = 45.0f * obj->size / 16.0f;
    obj->fB4 = 52.0f * obj->size / 16.0f;

    obj->f228 = 0.0f;
    for (i = 0; i < 4; i++) {
        obj->wheels[i].f44 = 0.0f;
        obj->wheels[i].pos = desc->wheelPos[i];
        obj->wheels[i].vel.x = 0.0f;
        obj->wheels[i].vel.y = 0.0f;
        obj->wheels[i].vel.z = 0.0f;
        obj->wheels[i].state = 0;
        obj->wheels[i].f04 = 0.0f;
        obj->wheels[i].f48 = 1.7f;
    }

    obj->maxLen = 0.0f;
    obj->maxX = 1.0f;
    for (i = 0; i < 4; i++) {
        pt = &obj->points[i];
        pt->pos = desc->pointPos[i];
        pt->vel.x = 0.0f;
        pt->vel.y = 0.0f;
        pt->vel.z = 0.0f;
        len = stcoli_mag(&pt->pos);
        if (obj->maxLen < len) {
            obj->maxLen = len;
        }
        ax = __fabs(pt->pos.x);
        if (obj->maxX < ax) {
            obj->maxX = ax;
        }
    }

    obj->maxLen += 0.1f;
    obj->s474 = -1;
    obj->s475 = -1;
    obj->b590 = 0;
    obj->s5DA = 100;
    lbl_8006DAEC();
    lbl_8006D758();
    fn_1_22F90((void *)obj, 1);
    lbl_8006DB30();
}
/* fzgx:end fn_1_2277C */

/* fzgx:begin fn_1_229EC */
static void stcoli_restart(u32 obj)
{
    u16 timer;
    f32 boost;
    u8 count;
    u32 bit;
    f32 half;

    timer = *(u16 *)(obj + 0x214);
    boost = *(f32 *)(obj + 0x184);
    bit = *(u32 *)obj & 1;
    count = *(u8 *)(obj + 0x4C2);
    lbl_8006DAEC();
    lbl_8006DBAC((void *)(obj + 0x594));
    fn_1_22F90((u8 *)obj, 0);
    *(u16 *)(obj + 0x214) = timer;
    *(u32 *)obj |= 0x400;
    *(u8 *)(obj + 0x481) = 60;
    *(u8 *)(obj + 0x4C2) = count + 1;
    *(u32 *)obj |= bit;
    half = *(u16 *)(obj + 0x5DA) / 2.0f;
    if (boost <= half) {
        *(f32 *)(obj + 0x184) = half;
    } else {
        *(f32 *)(obj + 0x184) = boost;
    }
    fn_1_8A190((void *)obj, (void *)1);
    lbl_8006DB30();
}


void fn_1_229EC(fn_1_229EC_ctrl *ctrl, f32 *out_pos, f32 *out_mag)
{
    f32 y;
    f32 x;
    f32 delta;
    f32 mag;
    f32 falloff;
    x = ctrl->x;
    y = ctrl->y;
    mag = *out_mag;
{
    f32 total;
    total = 40.0f * x / 348.0f + *out_pos;
    falloff = total / (36.0f + (f32)(40.0f * y));
    delta = total - mag;

    if (falloff < 0.0f) {
        falloff = 0.0f;
    }
    falloff = falloff * (x * (0.6f + x) * 4.0f);
    if (mag < 0.0f) {
        falloff *= 5.0f;
    }

    *out_pos = total - (f32)(((f32)((f32)((delta)) * (f32)((falloff)))));
}
    {
        f32 lim;
        if (*out_pos > (lim = ctrl->limit)) {
            *out_pos = *out_pos - lim;
        } else {
            *out_pos = 0.0f;
        }
    }

    if (mag < 0.0f) {
        delta *= 0.05f;
    }

    *out_mag = *out_mag + (f32)(((f32)((f32)((1000.0f)) * (f32)((delta))))) / ctrl->divisor;
    *out_mag = *out_mag - (f32)((*out_mag * *out_mag) * 8.0f) / ctrl->divisor;
    if (216.0 * *out_mag < 2.0) {
        *out_mag = 0.0f;
    }
}
/* fzgx:end fn_1_229EC */

/* fzgx:begin fn_1_22B10 */
/* Unknown retail function: the retail link removed it and no surviving code holds a copy of it.
   Its literals are .rodata 8A0..8BC (0.25f, 0.07f, 0.2f, 0.84, 2.0f; 0.07f and 0.84 have no retail reader).
   The retail body is not known: this placeholder only recreates the literals 8A0..8BC in retail order.
   WARNING: compiler-diff device, not original code (the body is a placeholder that only rebuilds the literals) */
static f32 stcoli_param_unknown(f32 x)
{
    f32 y;

    y = 0.25f * x;
    y += 0.07f;
    y *= 0.2f;
    y = y * 0.84;
    return y * 2.0f;
}

/* WARNING: compiler-diff device, not original code */
#pragma fp_contract off

void fn_1_22B10(struct fn_1_22B10_Arg0 *p, f32 speed) {
    f32 a;
    f32 b;
    f32 d;
    f32 t;
    f32 k;
    f32 r;
    f32 m;
    f32 y;
    f32 x;
    s32 flag;
    f32 scale;

    flag = 1;
    d = speed - 0.5f;
    if (d > 0.0f) {
        b = 0.0f;
        a = 1.0f;
        x = p->unk_1C;
        if (x > 1.0f) {
            p->unk_1C = x - 1.8f * (x * d);
        }
    } else {
        x = p->unk_1C;
        a = 0.0f;
        b = 1.4f;
        if (x < 1.0f) {
            p->unk_1C = x - 2.0f * ((2.0f - x) * d);
        } else if (x < 1.5f) {
            p->unk_1C = x - 1.2f * (x * d);
        } else {
            p->unk_1C = x - (1.2f - (x - 1.5f)) * (x * d);
        }
        if (p->unk_1C > 2.3f) {
            p->unk_1C = 2.3f;
        }
    }

    if (d < 0.0f && p->unk_8 >= 0.5f && p->unk_C <= 0.2f) {
        flag = 0;
    }

    t = d * __fabs(a - p->unk_C);
    if (d > 0.0f) {
        k = 1.0f;
        if (p->unk_8 < 0.4f) {
            k = 3.2f;
        } else if (p->unk_8 >= 0.5f) {
            if (p->unk_C < 0.15f) {
                k = 0.0f;
            } else {
                k = -0.25f;
            }
        }
        t *= 0.16f * k;
    } else {
        r = (p->unk_C - 0.12f) / 0.08f;
        if (r > 1.0f) {
            r = 1.0f;
        }
        t *= 0.45f * (0.4f + 0.2f * r);
    }

    x = p->unk_8;
    if (x > 0.6f && d < 0.0f) {
        p->unk_8 = x + (2.0f * d) * __fabs(0.7f - x);
    } else {
        p->unk_8 += 0.6f * (-d * __fabs(b - x));
    }

    if (p->unk_8 < 0.4f) {
        m = 1.0f;
        if (p->unk_8 < 0.31f) {
            t *= 1.5f;
            m = 1.5f;
        }
        if (p->unk_3C > 0.03f) {
            m *= 1.5f;
        }
        if (d < 0.0f) {
            m *= 2.0f;
        }
        p->unk_3C -= __fabs(0.7f * (m * (p->unk_3C * d)));
        if (p->unk_3C < 0.01f) {
            p->unk_3C = 0.01f;
        }
    }

    if (p->unk_4 < 700.0f && p->unk_8 > 0.7f) {
        p->unk_8 = 0.7f;
    }

    p->unk_C += t;
    if (d > 0.0f) {
        p->unk_20 *= 1.0f - 0.6f * d;
    } else {
        p->unk_20 *= 1.0f - 0.2f * d;
    }

    scale = 1.0f;
    p->unk_10 = p->unk_10 * (scale + 0.25f * d);
    p->unk_14 = p->unk_14 * (scale + 0.25f * d);

    if (flag) {
        p->unk_34 *= scale + 0.1f * d;
    }
}

#pragma fp_contract reset
/* fzgx:end fn_1_22B10 */

/* fzgx:begin fn_1_22E8C */
void fn_1_22E8C(Fn_1_22E8COutput *self, Fn_1_22E8CInput *source) {
    float first = source->field04;

    self->field08 = first;
    self->field0c = source->field10;
    self->field28 = source->field14;
    self->field14 = source->field20;
    self->field1c = source->field28;
    self->field20 = source->field2c;
    self->field24 = source->field30;
    self->field30 = source->field44;
    self->field10 = source->field18;
    self->field2c = source->field1c;
    self->field477 = source->field48;
    self->field34 = source->field4c;
    self->field38 = source->field50;
    self->field18 = source->field24;
    self->field220 = source->field08;
    self->field22c = source->field0c;
    self->field230 = 0.57 * source->field34;
    self->field234 = source->field38;
    self->field238 = source->field3c;
    self->field23c = source->field40;
    if (source->field49 & 1) {
        self->flags |= 0x100;
    } else {
        self->flags &= ~0x100;
    }
    if (source->field49 & 2) {
        self->flags |= (1u << 31);
    } else {
        self->flags &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_22E8C */

/* fzgx:begin fn_1_22F90 */
/* Unknown retail object: .rodata 918, 0.57f (the float twin of the 0.57 that fn_1_22E8C reads), no retail reader */
const f32 stcoli_unknown_918 = 0.57f;

void fn_1_22F90(u8 *arg0, int arg1) {
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    v0 = (0.0f); v1 = (1.0f);
    *(f32 *)((u8 *)arg0+148)=0.0f; *(f32 *)((u8 *)arg0+152)=0.0f; *(f32 *)((u8 *)arg0+156)=0.0f;
    *(f32 *)((u8 *)arg0+204)=0.0f; *(f32 *)((u8 *)arg0+208)=0.0f; *(f32 *)((u8 *)arg0+212)=0.0f;
    *(f32 *)((u8 *)arg0+184)=0.0f; *(f32 *)((u8 *)arg0+188)=0.0f; *(f32 *)((u8 *)arg0+192)=0.0f;
    *(f32 *)((u8 *)arg0+160)=0.0f; *(f32 *)((u8 *)arg0+164)=0.0f; *(f32 *)((u8 *)arg0+168)=0.0f;
    *(f32 *)((u8 *)arg0+432)=0.0f; *(f32 *)((u8 *)arg0+436)=0.0f; *(f32 *)((u8 *)arg0+440)=0.0f;
    *(f32 *)((u8 *)arg0+420)=0.0f; *(f32 *)((u8 *)arg0+424)=0.0f; *(f32 *)((u8 *)arg0+428)=0.0f;
    *(f32 *)((u8 *)arg0+408)=0.0f; *(f32 *)((u8 *)arg0+412)=0.0f; *(f32 *)((u8 *)arg0+416)=0.0f;
    *(f32 *)((u8 *)arg0+224)=0.0f; *(f32 *)((u8 *)arg0+228)=0.0f; *(f32 *)((u8 *)arg0+232)=0.0f;
    *(f32 *)((u8 *)arg0+1252)=0.0f; *(f32 *)((u8 *)arg0+1256)=0.0f; *(f32 *)((u8 *)arg0+1260)=0.0f;
    *(f32 *)((u8 *)arg0+1264)=0.0f; *(f32 *)((u8 *)arg0+1268)=0.0f; *(f32 *)((u8 *)arg0+1272)=0.0f;
    lbl_8006E1F0(arg0+444,0.0f,1.0f,0.0f);
    psvec_set((u8 *)arg0+124,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    psvec_set((u8 *)arg0+136,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    psvec_set((u8 *)arg0+1224,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    lbl_8006DAEC();
    v2=(0.0f); lbl_8006E0B4(v2,(-0.100000001f),v2);
    psvec_set((u8 *)arg0+468,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    lbl_8006DB30();
{
    f32 v3;
    psvec_set((u8 *)arg0+480,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));

    v3=(0.0f);
    v5=(200.0f);
    v6=(1.0f); v7=(2.0f);
    *(f32 *)((u8 *)arg0+508)=0.0f; *(f32 *)((u8 *)arg0+524)=0.0f; *(f32 *)((u8 *)arg0+1144)=0.0f;
    *(f32 *)((u8 *)arg0+512)=0.0f; *(f32 *)((u8 *)arg0+516)=0.0f; *(f32 *)((u8 *)arg0+504)=0.0f; *(f32 *)((u8 *)arg0+500)=0.0f;
    *(f32 *)((u8 *)arg0+456)=0.0f; *(u32 *)((u8 *)arg0+460)=0; *(f32 *)((u8 *)arg0+464)=0.0f;
    *(f32 *)((u8 *)arg0+196)=0.0f; *(u16 *)((u8 *)arg0+392)=0; *(f32 *)((u8 *)arg0+200)=0.0f;
*(f32 *)((u8 *)arg0+388) = (f32)*(u16 *)((u8 *)arg0+1498);
    *(u8 *)((u8 *)arg0+395)=0; *(f32 *)((u8 *)arg0+384)=0.0f; *(u8 *)((u8 *)arg0+394)=0;
    *(f32 *)((u8 *)arg0+492)=0.0f; *(f32 *)((u8 *)arg0+496)=0.0f; *(u8 *)((u8 *)arg0+1153)=0;
    *(f32 *)((u8 *)arg0+380)=0.0f; *(f32 *)((u8 *)arg0+220)=0.0f; *(u8 *)((u8 *)arg0+1424)=0;
    *(f32 *)((u8 *)arg0+396)=0.0f; *(u8 *)((u8 *)arg0+1142)=0; *(u8 *)((u8 *)arg0+1155)=0;
    *(u32 *)((u8 *)arg0+400)=0; *(u16 *)((u8 *)arg0+404)=0; *(u8 *)((u8 *)arg0+406)=0;
    *(f32 *)((u8 *)arg0+520)=v5; *(f32 *)((u8 *)arg0+1196)=0.0f; *(u32 *)((u8 *)arg0+1148)=0;
    *(u8 *)((u8 *)arg0+1152)=0; *(u8 *)((u8 *)arg0+407)=0; *(u8 *)((u8 *)arg0+530)=0;
    *(u16 *)((u8 *)arg0+528)=0; *(u16 *)((u8 *)arg0+532)=0; *(u8 *)((u8 *)arg0+534)=0;
    *(u32 *)((u8 *)arg0+536)=0; *(u32 *)((u8 *)arg0+540)=0; *(u32 *)((u8 *)arg0+1564)=0;
    *(u8 *)((u8 *)arg0+1202)=0; *(u8 *)((u8 *)arg0+1216)=0; *(u8 *)((u8 *)arg0+1217)=255;
    *(u8 *)((u8 *)arg0+1220)=0; *(u16 *)((u8 *)arg0+1248)=0; *(f32 *)((u8 *)arg0+1408)=0.0f;
    *(u8 *)((u8 *)arg0+1203)=0; *(u16 *)((u8 *)arg0+1222)=0; *(u8 *)((u8 *)arg0+1221)=0;
    *(u8 *)((u8 *)arg0+1497)=0; *(u8 *)((u8 *)arg0+1219)=0; *(u32 *)((u8 *)arg0+1276)=0;
    *(u8 *)((u8 *)arg0+1292)=4; *(f32 *)((u8 *)arg0+1308)=0.0f; *(f32 *)((u8 *)arg0+1304)=0.0f;
    *(f32 *)((u8 *)arg0+1236)=0.0f; *(f32 *)((u8 *)arg0+1240)=0.0f; *(f32 *)((u8 *)arg0+1492)=0.0f;
}
    *(u8 *)((u8 *)arg0+1293)=0; *(f32 *)((u8 *)arg0+1244)=v6; *(u8 *)((u8 *)arg0+1425)=0;
    *(u8 *)((u8 *)arg0+1426)=0; *(u8 *)((u8 *)arg0+1427)=0; *(u8 *)((u8 *)arg0+1295)=0;
    *(f32 *)((u8 *)arg0+1296)=v7;
    { struct fn_1_22F90_Copy16 init_c = {{0, 0, 0, 0x3F800000}}; *(struct fn_1_22F90_Copy16 *)(arg0+1476) = init_c; }
    *(u32 *)((u8 *)arg0+1300)=-1; *(u8 *)((u8 *)arg0+1496)=0;
    lbl_8006DAEC(); v10=(0.0f);
    *(f32 *)(0xE0000000+0x0C)=v10; *(f32 *)(0xE0000000+0x1C)=v10; *(f32 *)(0xE0000000+0x2C)=v10;
    lbl_8006DB74((void *)((u32)(arg0+236))); lbl_8006DB74((void *)((u32)(arg0+284))); fn_1_29968((void *)((Sig_fn_1_29968_Owner *)arg0));
    lbl_8006DC34((arg0+1312));
    *(f32 *)((u8 *)arg0+1324)=*(f32 *)((u8 *)arg0+124);
    *(f32 *)((u8 *)arg0+1340)=*(f32 *)((u8 *)arg0+128);
    *(f32 *)((u8 *)arg0+1356)=*(f32 *)((u8 *)arg0+132);
    lbl_8006DD14((u32)(arg0+1312),(arg0+1428)); lbl_8006DB30(); lbl_8006DAEC();
    if (*(s16 *)(arg0+6)>40) { v11=(0.0f); lbl_8006E0B4(v11,(0.5f),v11); }
    lbl_8006DB74((void *)((u32)(arg0+332))); lbl_8006DB74((void *)((u32)(arg0+1360))); lbl_8006DB30();
    v12=(0.0f); *(f32 *)(arg0+548)=0.0f; *(f32 *)(arg0+552)=0.0f;
    *(u8 *)((u8 *)arg0+576)=0; *(u8 *)((u8 *)arg0+577)=0;
    *(f32 *)((u8 *)arg0+1184)=0.0f; *(f32 *)((u8 *)arg0+1188)=0.0f; *(f32 *)((u8 *)arg0+1192)=0.0f;
    if (arg1) { *(u32 *)arg0 &= 0x24000300; *(arg0+1218)=0; *(f32 *)(arg0+216)=0.0f;
      *(u8 *)((u8 *)arg0+1154)=0; *(u8 *)((u8 *)arg0+531)=0; *(u8 *)((u8 *)arg0+535)=0;
    } else { *(u32 *)arg0 &= 0x24010300; *(u32 *)(arg0+1420) &= 1; }
    v13=(0.0f); *(u32 *)(arg0+1420) &= -945;
    {
      u8 *a = arg0;
      u8 *b = arg0;
      u8 *p2;
      s32 i2;
      s32 i1;
      u8 *c;
      for (i1 = 0; i1 < 4; i1++, a += 0x5c, b += 0x30, v13 = v13) {
        c = b + 0x3b4;
        *(u32 *)(a+0x244)=0; *(f32 *)(a+0x288)=v13; *(f32 *)(a+0x29c)=v13;
        lbl_8006E1B0(a+0x24c,a+0x258); lbl_8006E1B0(a+0x24c,a+0x264);

        *(f32 *)(a+0x290)=v13;
        *(f32 *)(a+0x294)=v13; *(f32 *)(a+0x298)=v13;
        lbl_8006E1F0(a+0x27c,v13,1.0f,v13);
        lbl_8006E1F0(a+0x270,0.0f,1.0f,0.0f);
        lbl_8006E1D8((void *)((u32)(c+0xc)), 0.0f, 0.100000001f, 0.0f);
        lbl_8006E1B0(c,c+0x18);
        *(f32 *)(c+0x24)=v13; *(f32 *)(c+0x28)=v13; *(f32 *)(c+0x2c)=v13;
      }
      for (i2 = 0, p2 = arg0; i2 < 4; i2++, p2 += 4) {
        fn_1_235C8((void *)(*(Sig_fn_1_235C8_Fn_1_235C8 **)(p2 + 0x488)));
      }
    }
    fn_1_23610((void *)*(u32 *)(arg0+1176));
    fn_1_23640((void *)((Sig_fn_1_23640_Fn_1_23640 *)*(u32 *)(arg0+1180)),arg1);
}
/* fzgx:end fn_1_22F90 */

/* fzgx:begin fn_1_23500 */
void fn_1_23500(Fn_1_23500 *self, f32 value) {
    f64 factor;
    f32 amount;
    f32 one;

    factor = value / (216.0);
    amount = factor * self->field08;
    fn_1_22F90((void *)self, 1);
    if ((0.0f) != value) {
        lbl_8006E1F0(&self->field94, (0.0f), (0.0f), -amount);
        one = (1.0f);
        self->field224 = value / (200.0f);
        self->flags |= 0x400;
        self->field200 = one;
        self->field481 = 0x5a;
    }
    fn_1_8A190((void *)self, (void *)(1));
}
/* fzgx:end fn_1_23500 */

/* fzgx:begin fn_1_235C8 */
void fn_1_235C8(Sig_fn_1_235C8_Fn_1_235C8 *self) {
    if (self != 0) {
        memset(self, 0, 0xc0);
        self->field00 = &self->data[0];
        self->field04 = &self->data[0x5c];
    }
}
/* fzgx:end fn_1_235C8 */

/* fzgx:begin fn_1_23610 */
void fn_1_23610(void *self) {
    if (self != 0) {
        memset(self, 0, 0x194);
    }
}
/* fzgx:end fn_1_23610 */

/* fzgx:begin fn_1_23640 */
void fn_1_23640(Sig_fn_1_23640_Fn_1_23640 *self, int value) {
    if (self != 0) {
        if (value != 0) {
            memset(self, 0, 0x1fc);
            self->field11c = -1;
            self->field15c = -1;
        } else {
            memset(self, 0, 0x117);
        }
        self->field80 = value;
        self->field90 = &self->fieldb8;
        self->field94 = &self->fieldc8;
        self->field9c = -1;
        self->fieldb8 = -1;
        self->fieldd8 = -1;
    }
}
/* fzgx:end fn_1_23640 */

/* fzgx:begin fn_1_236CC */
/* begin game/main_rel/stcoli_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_STCOLI_TYPES_H

// Types (and the externs that name them) of stcoli.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* end game/main_rel/stcoli_types.h */

/* game/vec3.h: inlined above */

/* translation column of the current matrix in the locked cache */

static inline void fn_1_236CC_set_translate(f32 x, f32 y, f32 z) {
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

#define BODY_VA0(b) ((Vec3 *)(b)->pad_A0)

void fn_1_236CC(Body *b) {
    f32 rate;
    f32 speed;
    f32 inv;
    s32 i;
    Fn_1_236CC_Words vel;
    Fn_1_236CC_Words hit;
    s32 found;
    u8 n;
    f32 z, y, x;
    f32 zero;

    if (fn_1_2BF8C((u32)b) != 0) {
        b->f58C &= ~0x8;
        return;
    }
    b->f58C |= 0x8;
    fn_1_289B4((void *)b, (void *)&found, (void *)&hit);
    if (fn_1_27E34((void *)b) != 0 && found != 0) {
        *(Fn_1_236CC_Words *)((u8 *)b + 0x1BC) = hit;
    }
    vel = *(Fn_1_236CC_Words *)&b->vel;
    speed = fn_1_253A4((void *)b);
    fn_1_25870((void *)b);
    rate = BODY_VA0(b)->y;
    if (b->b481 != 0) {
        for (i = 0; i < 4; i++) {
            fn_1_278B8((u8 *)b, &b->parts[i], rate);
        }
    }
    if (b->flags & 0x4) {
        b->f580 *= 0.02f;
    }
    if (__fabs(b->f1F8) > 0.009999999776482582) {
        b->f580 *= 0.04f;
    }
    fn_1_25480((void *)b, &vel, speed);
    fn_1_2A214((void *)b);
    lbl_8006DBAC(b->mtxEC);
    fn_1_29800((void *)b);
    fn_1_290E8((void *)b);
    fn_1_294D0((void *)b);
    inv = 1.0f / b->mass;
    psvec_scale_add(&b->pos, &b->vel, inv, &b->pos);
    fn_1_28184((void *)b);
    mathutil_mtxA_set_translate(&b->pos);
    fn_1_28F08((void *)b, (void *)(BODY_VA0(b)), 0.0f);
    zero = 0.0f;
    fn_1_236CC_set_translate(zero, zero, zero);
    lbl_8006DB74(b->mtxEC);
    if (b->flags & 0x2000) {
        b->flags |= 0x80000;
    }
    if (b->flags & 0x8000) {
        b->flags &= ~0x180000;
    }
    if (b->flags & 0x400) {
        n = b->b481;
        if (n < 30) {
            if (n % 6 == 0) {
                fn_1_2B524((void *)b);
            }
        } else if (n < 90) {
            zero = 0.0f;
            BODY_VA0(b)->x = zero;
            BODY_VA0(b)->y = zero;
            BODY_VA0(b)->z = zero;
        }
    }
    if (*((u8 *)b + 0x216) != 0) {
        (*((u8 *)b + 0x216))--;
    }
    b->flags &= ~0x03803000;
    *(f32 *)((u8 *)b + 0x208) = 200.0f;
    fn_1_27DE4((void *)b);
}
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H
#undef BODY_VA0
/* fzgx:end fn_1_236CC */

/* fzgx:begin fn_1_239C4 */
/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))

#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))

#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))

#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))

#define S(p,o) (*(s8 *)((u8 *)(p)+(o)))

#define V(p,o) ((Vec3 *)((u8 *)(p)+(o)))

#define CLEAR_PAIR() do { U(arg0,0x514) &= ~(0x80000000U >> H(arg1,4)); U(arg1,0x514) &= ~(0x80000000U >> H(arg0,4)); } while (0)

static inline f32 length239C4(Vec3 *p) {
    f32 x = p->x, y = p->y, z = p->z;
    f32 v1 = x*x;
    v1 = y*y+v1;
    v1 = z*z+v1;
    return lbl_8006D0B4(v1);
}

#define LENGTH(p) length239C4(p)

static inline f32 distance239C4(Vec3 *a, Vec3 *b) {
    f32 x = a->x - b->x;
    f32 y = a->y;
    f32 z = a->z;
    y -= b->y;
    z -= b->z;
    x = x*x;
    x = y*y + x;
    x = z*z + x;
    return lbl_8006D0B4(x);
}

#define DIST(a,b) distance239C4(a,b)

s32 fn_1_239C4(struct fn_1_239C4_Arg0 *arg0, struct fn_1_239C4_Arg0 *arg1) {
    f32 v84, v85, v88, v89, v64, v65, v2, v6, v58, v59, v7, v3, v1;
    f32 v10, v11;
    f32 v5, v9, v41, v54;
    int v34, v96, v94, v95, v98, v99;
    Sig_fn_1_2BD30_StcoliOut2BD30 loc_F0;
    Sig_fn_1_2BD30_StcoliOut2BD30 loc_B8;
    Vec3 loc_AC, loc_A0, loc_94, loc_88, loc_7C, loc_70, loc_64;
    Vec3 loc_58, loc_4C, loc_40, loc_34, loc_28, loc_1C, loc_10;
    f32 loc_C;
    s32 loc_8;

    if ((arg0->unk_58C | arg1->unk_58C) & 0x10) return 0;
    if (U(arg0,0) & 0x20000000) {
        if (H(arg0,6) >= 2) v5 = ((f32)(1.0f));
        else v5 = lbl_1_rodata_3508[H(arg0,6)*2+1];
        v10 = F(arg0,0x510)*v5;
        v10 = ((f32)(0.800000012f)) * v10;
        v2 = F(arg0,8);
    } else { v10 = F(arg0,0x510); v2 = F(arg0,8); }
    if (U(arg1,0) & 0x20000000) {
        if (H(arg1,6) >= 2) v9 = ((f32)(1.0f));
        else v9 = lbl_1_rodata_3508[H(arg1,6)*2+1];
        v11 = F(arg1,0x510)*v9;
        v11 = ((f32)(0.800000012f)) * v11;
        v6 = F(arg1,8);
    } else { v11 = F(arg1,0x510); v6 = F(arg1,8); }
    v1 = DIST(&arg0->pos, &arg1->pos);
    if (v1 > v11 + (v10 + (F(arg0,0x17c)/((f64)(216.0)) + F(arg1,0x17c)/((f64)(216.0))))) {
        CLEAR_PAIR();
        return 0;
    }
    fn_1_2BBD0((void *)((Sig_fn_1_2BBD0_Fn2BBD0_Self *)arg0),(void *)((Sig_fn_1_2BBD0_Fn2BBD0_Other *)arg1),v1);
    fn_1_2BBD0((void *)((Sig_fn_1_2BBD0_Fn2BBD0_Self *)arg1),(void *)((Sig_fn_1_2BBD0_Fn2BBD0_Other *)arg0),v1);
    v1 = DIST(&arg0->prevPos,&arg0->pos);
    if (v1 > ((f64)(13.888888888888889))) {
        psvec_sub(&arg0->pos, &arg0->prevPos, &loc_94);
        lbl_8006D5F0(&loc_94,&loc_94,((f32)(13.8888893f)));
        psvec_add(&arg0->pos, &loc_94, &loc_94);
        lbl_8006D5F0(&arg0->vel, &loc_7C, (((f64)(13.888888888888889))*v2));
    } else { loc_94 = arg0->prevPos; loc_7C = arg0->vel; }
    v1 = DIST(&arg1->prevPos,&arg1->pos);
    if (v1 > ((f64)(13.888888888888889))) {
        psvec_sub(&arg1->pos, &arg1->prevPos, &loc_88);
        lbl_8006D5F0(&loc_88,&loc_88,((f32)(13.8888893f)));
        psvec_add(&arg1->pos, &loc_88, &loc_88);
        lbl_8006D5F0(&arg1->vel, &loc_70, (((f64)(13.888888888888889))*v6));
    } else { loc_88 = arg1->prevPos; loc_70 = arg1->vel; }
    if (!fn_1_251F8((void *)&loc_94,(void *)&arg0->pos,(void *)&loc_88,(void *)&arg1->pos,(void *)&loc_C,(void *)&loc_8,v10,v11)) {
        if (!loc_8) { CLEAR_PAIR(); }
        return 0;
    }
    v3 = v10+v11;
    loc_C = ((f32)(1.0f))-loc_C;
    lbl_8006D5A4(&loc_94,(u32)&arg0->pos,&loc_AC,loc_C);
    lbl_8006D5A4(&loc_88,(u32)&arg1->pos,&loc_A0,loc_C);
    v7 = DIST(&loc_AC,&loc_A0);
    v34 = 0;
    if (v7 < v3 && v7 > ((f32)(1.1920929e-07f))) v34 = 1;
    if (v34) {
        /* WARNING: compiler-diff device, not original code: variable-amount __rlwnm bit tests, no natural spelling known */
        if (__rlwnm(U(arg0,0x514), (H(arg1,4)+1)&31, 31, 31) || __rlwnm(U(arg1,0x514), (H(arg0,4)+1)&31, 31, 31)) v34 = 0;
    } else { CLEAR_PAIR(); }
    if (v34) {
        psvec_sub(&loc_A0,&loc_AC,&loc_64);
        lbl_8006D668((void *)&loc_64);
        {
            f32 offsetB = ((f32)(0.5f))*((((f32)(0.00999999978f))+v3)-v7);
            v41 = -offsetB;
            psvec_scale_add(&loc_AC,&loc_64,v41,&arg0->pos);
            psvec_scale_add(&loc_A0,&loc_64,offsetB,&arg1->pos);
        }
        psvec_add(&arg0->pos,&arg1->pos,&loc_40);
        psvec_scale(&loc_40,((f32)(0.5f)),&loc_40);
        v3 = fn_1_2BD30((void *)((Sig_fn_1_2BD30_StcoliObj2BD30 *)arg0),(void *)&loc_F0,(void *)&loc_40);
        v1 = fn_1_2BD30((void *)((Sig_fn_1_2BD30_StcoliObj2BD30 *)arg1),(void *)&loc_B8,(void *)&loc_40);
        if (v3 > v1) loc_34 = loc_F0.axis;
        else { loc_34.x = -loc_B8.axis.x; loc_34.y = -loc_B8.axis.y; loc_34.z = -loc_B8.axis.z; }
        v3 = LENGTH(&loc_7C);
        if (v3 > ((f32)(1.1920929e-07f))) v7 = v3*(lbl_8006D6FC(&loc_34,&loc_7C)/v2);
        else v7 = ((f32)(0.0f));
        v3 = LENGTH(&loc_70);
        if (v3 > ((f32)(1.1920929e-07f))) v1 = v3*(lbl_8006D6FC(&loc_34,&loc_70)/v6);
        else v1 = ((f32)(0.0f));
        v54 = (((f32)(2.0f))*(v7-v1))/(v2+v6);
        F(arg0,0x224) += (f32)(((f32)(800.0f))*(loc_F0.depth*v54));
        F(arg1,0x224) += (f32)(((f32)(800.0f))*(loc_B8.depth*v54));
        v1 = F(arg0,0x224);
        if (v1 < ((f32)(0.0f))) F(arg0,0x224) = ((f32)(0.0f));
        v1 = F(arg1,0x224);
        if (v1 < ((f32)(0.0f))) F(arg1,0x224) = ((f32)(0.0f));
        {
        v7 = v2*v54;
        v3 = -v6*v54;
        v58 = fn_1_2A41C((void *)((Sig_fn_1_2A41C_Fn_1_2A41C *)arg0),U(arg1,0)&0x200);
        v59 = fn_1_2A41C((void *)((Sig_fn_1_2A41C_Fn_1_2A41C *)arg1),U(arg0,0)&0x200);
        if (U(arg0,0)&0x80) { v58 *= ((f32)(1.5f)); v59 *= ((f32)(1.20000005f)); }
        if (U(arg1,0)&0x80) { v59 *= ((f32)(1.5f)); v58 *= ((f32)(1.20000005f)); }
        v64 = v59*(v3*v2);
        v65 = v58*(v7*v6);
        }
        psvec_scale(&loc_64,v64,&loc_58);
        psvec_scale(&loc_64,v65,&loc_4C);
        loc_28.x = ((f32)(0.949999988f))*(loc_58.x*F(arg0,0x1bc));
        loc_28.y = ((f32)(0.949999988f))*(loc_58.y*F(arg0,0x1c0));
        loc_28.z = ((f32)(0.949999988f))*(loc_58.z*F(arg0,0x1c4));
        psvec_sub(&loc_58,&loc_28,&loc_58);
        loc_28.x = ((f32)(0.949999988f))*(loc_4C.x*F(arg1,0x1bc));
        loc_28.y = ((f32)(0.949999988f))*(loc_4C.y*F(arg1,0x1c0));
        loc_28.z = ((f32)(0.949999988f))*(loc_4C.z*F(arg1,0x1c4));
        psvec_sub(&loc_4C,&loc_28,&loc_4C);
        *(&arg0->impulse) = loc_58; *(&arg1->impulse) = loc_4C;
        if ((U(arg0,0)|U(arg1,0))&0x20008) v84 = v85 = ((f32)(1.5f));
        else v84 = v85 = ((f32)(2.20000005f));
        if (U(arg0,0)&0x20000000) v84 = ((f32)(1.0f));
        if (U(arg1,0)&0x20000000) v85 = ((f32)(1.0f));
        psvec_scale(&loc_58,v84,&loc_28);
        if (LENGTH(&arg0->vel) > ((f32)(0.100000001f)) &&
            LENGTH(&loc_58) > ((f32)(0.100000001f))) {
            v88 = lbl_8006D6FC(&arg0->vel,&loc_58);
            if (v88 > ((f32)(0.0f))) v88 = ((f32)(0.0f));
            v1 = ((f32)(0.699999988f))*v88;
            v88 = ((f32)(1.0f)) + v1;
            psvec_scale(&loc_28,v88,&loc_28);
        }
        psvec_add(&loc_28,&loc_7C,&arg0->vel);
        psvec_scale(&loc_4C,v85,&loc_28);
        if (LENGTH(&arg1->vel) > ((f32)(0.100000001f)) &&
            LENGTH(&loc_4C) > ((f32)(0.100000001f))) {
            v89 = lbl_8006D6FC(&arg1->vel,&loc_4C);
            if (v89 > ((f32)(0.0f))) v89 = ((f32)(0.0f));
            v1 = ((f32)(0.699999988f))*v89;
            v89 = ((f32)(1.0f)) + v1;
            psvec_scale(&loc_28,v89,&loc_28);
        }
        psvec_add(&loc_28,&loc_70,&arg1->vel);
        lbl_8006DAEC();
        v94 = 0;
        v95 = 0;
        if ((U(arg0,0)&0x200) && (U(arg1,0)&0x200)) v96 = 1; else v96 = 0;
        v98 = v99 = 1;
        if (!(U(arg0,0)&0x200)) {
            if ((U(arg1,0)&0x200) && (U(arg0,0)&0x20008) && !(U(arg1,0)&0x20008)) v98 = 0;
        } else {
            if (!(U(arg1,0)&0x200) && (U(arg1,0)&0x20008) && !(U(arg0,0)&0x20008)) v99 = 0;
        }
        lbl_8006DBAC((void *)&arg0->vecEC);
        psvec_scale(&loc_64,((f32)(-0.5f)),&loc_1C);
        fn_8006E2B0(&loc_1C,&loc_1C);
        fn_8006E2B0(&loc_58,&loc_10);
        F(arg0,0xc4) += loc_10.x;
        F(arg0,0xc8) += loc_10.z;
{
        f32 damage0;
        damage0 = (v59*(((f32)(0.00200000009f))*LENGTH(&loc_58)))/v58;
        if (v96) damage0 *= ((f32)(0.00100000005f));
        if (U(arg1,0)&0x80) damage0 *= ((f32)(0.300000012f));
        if (v98 && !B(arg0,0x4c5) && fn_1_24F10((void *)((Sig_fn_1_24F10_Fn_1_24F10 *)arg0),damage0)) v94 = 1;
        fn_1_F7338(S(arg0,0x474),(void *)4,(void *)12);
        lbl_8006DBAC((void *)&arg1->vecEC);
        psvec_scale(&loc_64,((f32)(0.5f)),&loc_1C);
        fn_8006E2B0(&loc_1C,&loc_1C);
        fn_8006E2B0(&loc_4C,&loc_10);
        F(arg1,0xc4) += loc_10.x;
        F(arg1,0xc8) += loc_10.z;
        v1 = (v58*(((f32)(0.00200000009f))*LENGTH(&loc_4C)))/v59;
        if (v96) v1 *= ((f32)(0.00100000005f));
        if (U(arg0,0)&0x80) v1 *= ((f32)(0.300000012f));
        if (v99 && !B(arg1,0x4c5) && fn_1_24F10((void *)((Sig_fn_1_24F10_Fn_1_24F10 *)arg1),v1)) v95 = 1;
        if (v94) {
            fn_1_2A318((void *)((Sig_fn_1_2A318_Fn_1_2A318 *)arg1));
            if (S(arg1,0x475) != -1 && !(U(arg1,0)&0x4000200)) fn_1_A2D84(0xa9092100);
        }
        if (v95) {
            fn_1_2A318((void *)((Sig_fn_1_2A318_Fn_1_2A318 *)arg0));
            if (S(arg0,0x475) != -1 && !(U(arg0,0)&0x4000200)) fn_1_A2D84(0xa9092100);
        }
        fn_1_F7338(S(arg1,0x474),(void *)4,(void *)12);
        v1 = damage0+v1;
        }
        if (v1 > ((f64)(0.40000000000000002))) {
            fn_1_F7338(S(arg0,0x474),(void *)2,(void *)9);
            fn_1_F7338(S(arg1,0x474),(void *)2,(void *)9);
        } else if (v1 > ((f64)(0.10000000000000001))) {
            fn_1_F7338(S(arg0,0x474),(void *)3,(void *)9);
            fn_1_F7338(S(arg1,0x474),(void *)3,(void *)9);
        }
        if (U(arg0,0)&0x80) F(arg0,0x184) = ((f32)(0.0f));
        if (U(arg1,0)&0x80) F(arg1,0x184) = ((f32)(0.0f));
        lbl_8006DB30();
        U(arg0,0) |= 0x2000400; U(arg1,0) |= 0x2000400;
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_239C4 */

/* fzgx:begin fn_1_248C0 */
// Updates the collision state and reports whether the current flags trigger a response.

int fn_1_248C0(Fn_1_248C0 *self, int arg) {
    int result;
    int test;

    result = 0;
    if (self->unk_00 & 0x800) {
        if (self->unk_00 & 1) {
            result = 1;
        } else if (self->unk_00 & 0x10000) {
            result = 1;
        }
        if (!(self->unk_00 & 0x10000) && self->unk_4b3 == 0) {
            if (lbl_1_bss_960 == 9 && lbl_1_bss_9C == 5) {
            } else if (lbl_1_bss_9C == 6) {
            } else if (self->unk_475 != -1 && !(self->unk_00 & 0x04000200)) {
                fn_1_A2D84(0xA9072100);
            }
            self->unk_4b3 = 1;
        }
    } else {
        test = self->unk_00 & 0x80;
        if (test && self->unk_4b3 == 0 && !(self->unk_00 & 0x10000)) {
            if (self->unk_475 != -1 && !(self->unk_00 & 0x04000200)) {
                fn_1_A2D84(0xA9072200);
            }
            self->unk_4b3 = 1;
        }
        if ((self->unk_00 & 1) && test) {
            if ((self->unk_00 & 0x02810000) || arg) {
                result = 1;
            }
        }
    }
    if ((self->unk_00 & 0x40000000) && (self->unk_00 & 1)) {
        result = 1;
    }
    if (self->unk_00 & 0x10000000) {
        result = 0;
    }
    return result;
}
#undef GAME_VEC3_H
#undef F
#undef U
#undef H
#undef B
#undef S
#undef V
#undef CLEAR_PAIR
#undef LENGTH
#undef DIST
/* fzgx:end fn_1_248C0 */

/* fzgx:begin fn_1_24A4C */
static void stcoli_update_speed(fn_1_24A4C_Car *car)
{
    f32 vx, vy, vz;
    f32 sq;
    s32 below;

    if (car->flags & 0x8000) {
        car->speed = 0.0f;
    } else {
        vx = car->vel.x;
        vy = car->vel.y;
        vz = car->vel.z;
        sq = vx * vx;
        sq += vy * vy;
        sq += vz * vz;
        sq = lbl_8006D0B4(sq);
        car->speed = 216.0 * (sq / car->mass);
        if (car->speed > car->maxSpeed) {
            below = car->speed < 80.0f + car->maxSpeed;
            below |= car->speed < 1700.0f;
            below &= !(car->flags & 0x3800000);
            if (below) {
                car->maxSpeed = car->speed;
            }
        }
    }
}

static void stcoli_damage_timer(fn_1_24A4C_Car *car, s32 contact)
{
    if (car->timer214 == 0) {
        car->timer214 = 180;
        if ((car->flags & 0x80) && ((car->flags & 0x2800000) || contact != 0)) {
            car->timer214 += 90.0;
        }
        if (car->flags & 0x40000000) {
            car->timer214 = 180;
        }
    }
}

static inline f32 fn_1_24A4C_speed(f64 scale, f32 magnitude, f32 mass) { return scale * (magnitude / mass); }

static inline f64 fn_1_24A4C_read_pointer(struct fn_1_24A4C_lbl_1_rodata_840 * owner) { return owner->unk_20; }



void fn_1_24A4C(fn_1_24A4C_Car *car) {
    s32 i;
    s32 contact;
    s32 below;
    f32 speed;
    f32 y;
    f32 zero;
    f32 vx, vy, vz;
    f32 sq;
    u32 flags;
    fn_1_24A4C_Other *other;
    union {
        f64 d;
        u32 w[2];
    } cvt;

    if (!(car->flags58c & 8)) {
        return;
    }
    lbl_8006DBAC(car->mtx);
    mathutil_mtxA_set_translate(&car->pos);
    if (car->timer4e0 != 0) {
        fn_1_2BA48((void *)car);
    }
    if ((car->flags218 >> 25) & 1) {
        fn_1_24F10((void *)car, 0.33333334f);
        contact = 1;
        if ((car->flags58c & 0x200) && (car->flags & 0x80)) {
            fn_1_25004((void *)car);
        }
    }
    lbl_8006DBAC(car->mtx);
    mathutil_mtxA_set_translate(&car->pos);
    for (i = 0; i < 4; i++) {
        fn_1_24A4C_Wheel *w = &car->wheel[i];
        fn_1_24A4C_Spring *s = &car->spring[i];
        w->prev = w->cur;
        lbl_8006E1D8((void *)&w->cur, w->f08, w->f0C + w->f44 - w->f48, w->f10);
        s->prev = s->cur;
        lbl_8006E1B0(s, &s->cur);
    }
    if (!(car->flags58c & 0x10)) {
        y = car->pos.y;
        if (y < -5000.0f || ((fn_1_24A4C_Course *)lbl_1_bss_3BE0)->p24[0] - 900.0f > y) {
            fn_1_25004((void *)car);
        }
    }
    if (car->pos.y < -10000.0f) {
        car->pos.y = -10000.0f;
        zero = 0.0f;
        car->vel.x = zero;
        car->vel.y = zero;
        car->vel.z = zero;
    }
    fn_1_29A0C((void *)car);
    stcoli_update_speed(car);
    if (fn_1_248C0((void *)car, 1) != 0) {
        stcoli_damage_timer(car, contact);
    } else {
        flags = car->flags;
        if (!(flags & 0x08000201)) {
            if ((flags & 0x80) && car->timer4e0 == 0) {
                fn_1_2B684((void *)car);
            }
        } else if ((flags & 0x280) == 0x280) {
            speed = car->speed;
            if (speed < 10.0f) {
                zero = 0.0f;
                car->vel.x = zero;
                car->vel.y = zero;
                car->vel.z = zero;
                car->pos = car->prevPos;
                car->flags = car->flags | 0x08000000;
                other = ((fn_1_24A4C_Other *)fn_1_868C0(car->id));
                if (!(car->flags58c & 0x80)) {
                    car->flags58c = car->flags58c | 0x100;
                    other->flags390 = other->flags390 | 0x200000;
                }
                car->flags58c = car->flags58c | 0x80;
                if (lbl_801A66C8[0] + car->id == 0) {
                    fn_1_A2D84(0xA9092E00);
                    if (car->s475 != -1 && !(car->flags & 0x04000200)) {
                        fn_1_A2D84(0xA9091200);
                    }
                }
            } else if (speed < 100.0f) {
                psvec_scale(&car->vel, 0.95f, &car->vel);
            } else if (speed < 400.0f) {
                psvec_scale(&car->vel, 0.99f, &car->vel);
            }
        }
    }
    if (car->u4c0 == 0 && !(car->flags & 0x880)) {
        vx = car->v4b4.x;
        vy = car->v4b4.y;
        vz = car->v4b4.z;
        sq = vx * vx;
        sq += vy * vy;
        sq += vz * vz;
        if (lbl_8006D0B4(sq) < 200.0f) {
            car->u4c0 = 60;
        }
    }
}

/* fzgx:end fn_1_24A4C */

/* fzgx:begin fn_1_24F10 */
int fn_1_24F10(Fn_1_24F10 *self, f32 value) {
    f32 amount;
    f32 dist;
    int result;

    if (self->field214 != 0 || self->field593 != 0) {
        return 0;
    }

    amount = value * self->field30;
    if ((self->flags & 0x200) == 0 && amount > 20.0f) {
        amount = 20.0f;
    }

    if (amount > 1.01f * self->field5da) {
        amount = 1.01f * self->field5da;
    }

    self->field4ac = amount;
    dist = self->field184 - self->field4ac;
    self->field184 = dist;
    if (dist < 0.0f) {
        if ((self->flags & 0x10080) != 0) {
            result = 0;
        } else {
            result = 1;
            self->field593 = 0x3c;
        }
        self->flags |= 0x80;
        self->field184 = 0.0f;
        self->field224 = 0.0f;
        return result;
    }

    return 0;
}
/* fzgx:end fn_1_24F10 */

/* fzgx:begin fn_1_25004 */
void fn_1_25004(Fn_1_25004_Obj *self) {
    Fn_1_25004_Result *result;
    f32 zero;

    result = (Fn_1_25004_Result *)fn_1_868C0(self->field04);
    if ((self->flags58c & 0x10) == 0) {
        if ((s8)self->field474 != -1) {
            fn_1_F7338((s8)self->field474, (void *)(2), (void *)(0x1e));
        }
        zero = (0.0f);
        self->flags00 |= 0x800;
        self->flags00 |= 0x80;
        self->flags00 |= 0x800000;
        self->flags00 |= 0x40000000;
        self->flags58c |= 0x10;
        self->field184 = zero;
        self->field224 = zero;
        self->field94 = zero;
        self->field98 = zero;
        self->field9c = zero;
        self->fielda0 = zero;
        self->fielda4 = zero;
        self->fielda8 = zero;
        self->field17c = zero;
        self->flags58c &= ~0x80;
        result->flags390 &= ~0x200000;
        result->flags390 |= 0x1000000;
    }
}
/* fzgx:end fn_1_25004 */

/* fzgx:begin fn_1_250F8 */
void fn_1_250F8(Fn_1_250F8 *self) {
    u16 value;
    f32 add;
    f32 elapsed;
    u32 delta;

    if ((self->flags & 0x10000) == 0) {
        value = self->field210;
        add = 0.5f * self->field184;
        elapsed = value + add;
        delta = ((u32)self->field213 * 60) / 60;
        self->field210 = elapsed;
        if (self->field217 == 0) {
            self->field210 += 25;
        }
        if (self->field4b2 == 0) {
            self->field210 += 25;
        }
        if ((self->field58c & 1) == 0) {
            self->field210 += 40;
        }
        if (self->flags & 0x80) {
            self->field210 += 25;
        }
        if (self->field210 > delta) {
            self->field210 -= delta;
        } else {
            self->field210 = 0;
        }
    }
    self->flags |= 0x10000;
}
/* fzgx:end fn_1_250F8 */

/* fzgx:begin fn_1_251F8 */
/* WARNING: compiler-diff device, not original code */
#pragma fp_contract off

s32 fn_1_251F8(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d, f32 *out, s32 *flag, f32 p, f32 q) {
    f32 ux;
    f32 uy;
    f32 uz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len2;
    f32 cterm;
    f32 dt;
    f32 disc;

    *out = 100.0f;
    *flag = 0;

    ux = a->x - c->x;
    uy = a->y - c->y;
    uz = a->z - c->z;
    dx = b->x - d->x - ux;
    dy = b->y - d->y - uy;
    dz = b->z - d->z - uz;
    len2 = dx * dx + dy * dy + dz * dz;

    if (1.1920929e-07f > len2) {
        *flag = 1;
        return 0;
    }

    dt = ux * dx + uy * dy + uz * dz;
    cterm = ux * ux + uy * uy + uz * uz - (p + q) * (p + q);
    disc = dt * dt - len2 * cterm;

    if (0.0f > disc) {
        return 0;
    }
    if (0.0f >= cterm) {
        *out = 0.0f;
        return 1;
    }
    if (0.0f >= (cterm + (dt + (len2 + dt)))) {
        goto compute; /* Keep the verified branch to compute. */
    }
    if (0.0f <= dt) {
        return 0;
    }
    if (-dt >= len2) {
        return 0;
    }
compute:
    *out = -(dt + lbl_8006D0B4(disc)) / len2;
    return 1;
}
#pragma fp_contract reset
/* fzgx:end fn_1_251F8 */

/* fzgx:begin fn_1_253A4 */
// Scales collision response based on the flagged corner count.

// 0x5c

f32 fn_1_253A4(ColObj *p) {
    f32 f1, v, s;
    u32 flags = p->state;
    int i;

    if (!(flags & 0x400)) {
        return 0.0f;
    }

    v = 1.0f;
    s = 0.25f;
    for (i = 0; i < 4; i++) {
        if (p->corner[i].flag & 4) {
            v -= s;
        }
    }

    f1 = p->f18 * (p->f1f8 * p->f1fc);
    v = v * f1;
    f1 = p->f14 + v;
    f1 = f1 * -p->f1fc;
    if (flags & 0x20000) {
        f1 *= 0.3f;
    }

    {
        f32 t = 1.5f * f1;
        p->fa4 = p->fa4 + t;
    }
    if (__fabs(p->fa4) < 1.0) {
        p->fa4 = 0.0f;
    }
    p->f20c = p->f1fc;
    return f1;
}
/* fzgx:end fn_1_253A4 */

/* fzgx:begin fn_1_25480 */
/* begin game/main_rel/stcoli_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_STCOLI_TYPES_H

// Types (and the externs that name them) of stcoli.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

void fn_1_25480(Fn_1_25480_Obj *p, void *vel, f32 rate)
{
    Vec3 push;
    Vec3 kick;
    f32 drive;
    f32 grip;
    f32 yaw;
    f32 speed;
    f32 slip;
    f32 tilt;
    f32 bank;
    f32 len;
    f32 vz;
    f32 vy;
    f32 len2;
    f32 wy;
    f32 *mtx;

    vz = p->fD4;
    vy = p->fD0;
    len = p->fCC * p->fCC;
    len = __fmadds(vy, vy, len);
    len = __fmadds(vz, vz, len);
    drive = -p->fC0;
    yaw = __fabs(p->fB8);
    speed = lbl_8006D0B4(len);
    if (!(p->flags & 0x03800000) && speed > (10.0f * p->mass) / 216.0) {
        slip = p->fD4 / speed;
        slip = slip * slip;
        slip = (1.0f - slip) * p->f2C;
        if (slip > 1.0f) {
            slip = 1.0f;
        }
    } else {
        slip = 0.0f;
    }
    drive = fn_1_26F34((u32)p, drive, yaw, slip);
    grip = fn_1_2B478((void *)p);
    grip = 0.6f + (f64)(0.55f * __fabs(grip));
    if (grip > 1.0f) {
        grip = 1.0f;
    }
    drive *= grip;
    psvec_scale(&p->vel, grip, &p->vel);

    if (p->flags & 0x20) {
        p->fC8 += (f32)(0.05f * drive);
    } else {
        p->fC8 += (f32)(0.25f * drive);
    }

    if (p->flags & 0x2) {
        mtx = lbl_801A6D00;
        grip = 3.4f * (0.3f + ((f32)(mtx[10] * p->f1C4) + ((f32)(mtx[2] * p->f1BC) + (f32)(mtx[6] * p->f1C0))));
        if (grip > 1.0f) {
            grip = 1.0f;
        } else {
            if (grip < 0.0f) {
                grip = 0.0f;
            }
            grip = grip * grip;
        }
    } else {
        grip = 1.0f;
    }

    lbl_8006DAEC();
    tilt = p->f1FC * p->f20;
    bank = -(tilt + (f32)(p->f1F8 * p->f1C));
    if (p->flags & 0x20000) {
        bank = 0.0f;
    }
    p->f4D4 = 0.75f * -tilt;
    mathutil_mtxA_rotate_y((s32)(182.04445f * (bank < -45.0f ? -45.0f : (bank > 45.0f ? 45.0f : bank))));
    lbl_8006E1F0(&push, 0.0f, 0.0f, -drive * grip);
    psvec_add(&push, &p->vel, &p->vel);
    lbl_8006DB30();

    wy = p->vel.y;
    len2 = p->vel.x * p->vel.x;
    len2 = __fmadds(wy, wy, len2);
    speed = lbl_8006D0B4(__fmadds(p->vel.z, p->vel.z, len2));
    if (speed / p->mass > 0.9259259259259259) {
        if (p->b480 == 6) {
            f32 limit = speed;
            if (speed > 5.555555555555555 * p->mass) {
                limit = 5.555555555555555 * p->mass;
            }
            lbl_8006E1F0(&kick, p->f610 * limit, 0.0f, 0.0f);
            psvec_add(&kick, &p->vel, &p->vel);
        }
        if ((p->f218 >> 26) & 1) {
            lbl_8006E1F0(&kick, 0.0f, 1.13f * speed, 0.0f);
            psvec_add(&kick, &p->vel, &p->vel);
            p->f58C |= 2;
            p->fA0 = 0.0f;
            p->fA8 = 0.0f;
        }
    }

    p->f1F0 = p->f1EC / 20.0f;
    p->f1EC = p->f1EC + ((f32)(8.0f * p->f1F8) - (f32)(5.0f * p->f1F0));
}
/* fzgx:end fn_1_25480 */

/* fzgx:begin fn_1_25870 */
void fn_1_25870(Fn_1_25870 *self) {
    u32 flags;
    int trigger;

    if (self->field476 != 0) {
        self->field476--;
    }
    flags = self->flags;
    if ((flags & 0x2) == 0) {
        if (self->field224 > 0.1f) {
            if ((flags & 0x2000) != 0) {
                self->field244 &= ~4;
                self->field2a0 &= ~4;
                self->field2fc &= ~4;
                self->field358 &= ~4;
                self->field476 = self->field477;
            } else {
                trigger = 0;
                if ((flags & 0x1000) != 0 &&
                    __fabs(self->field1fc) > 0.10000000149011612) {
                    trigger = 1;
                }
                if ((self->flags & 0x8) != 0) {
                    trigger = 1;
                }
                if (trigger != 0) {
                    self->field244 |= 4;
                    self->field2a0 |= 4;
                    self->field2fc |= 4;
                    self->field358 |= 4;
                }
            }
        }
    } else {
        self->field244 &= ~4;
        self->field2a0 &= ~4;
        self->field2fc &= ~4;
        self->field358 &= ~4;
    }
    flags = self->flags;
    if ((flags & 0x4000) != 0 &&
        __fabs(self->field1fc) < 0.10000000149011612) {
        self->flags = flags & ~0x4000;
    }
    if (__fabs(self->field1f8) > 0.30000001192092896) {
        self->flags |= 0x4000;
    }
    if ((self->flags & 0x4000) == 0) {
        return;
    }
    self->field244 |= 0x10;
    self->field2a0 |= 0x10;
    self->field2fc |= 0x10;
    self->field358 |= 0x10;
}
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H
/* fzgx:end fn_1_25870 */

/* fzgx:begin fn_1_25A14 */
/* the track query result a corner's M+0x488[k] pair points at */

/* WARNING: compiler-diff device, not original code: variable-amount __rlwnm bit test, no natural spelling known */
#define BIT(word, k) __rlwnm((word), ((k) + 1) & 31, 31, 31)

#define CUR (&lbl_801A66CC->delta)

#define MINMAX(lo, hi, c)         \
    if (CUR->c > (hi).c) {        \
        (hi).c = CUR->c;          \
    } else if (CUR->c < (lo).c) { \
        (lo).c = CUR->c;          \
    }

static inline void fn_1_25A14_square_length_to(Vec3 *v, f32 *len)
{
    f32 x;
    f32 y;
    f32 z;

    x = v->x;
    y = v->y;
    *len = x * x;
    *len += y * y;
    z = v->z;
    *len += z * z;
}

static inline f32 fn_1_25A14_square_length(Vec3 *v)
{
    f32 sum;
    f32 x;
    f32 y;
    f32 z;

    x = v->x;
    y = v->y;
    sum = x * x;
    sum += y * y;
    z = v->z;
    sum += z * z;
    return sum;
}

static inline f32 fn_1_25A14_dot_product(Vec3 *a, Vec3 *b)
{
    f32 sum = a->x * b->x;
    sum = a->y * b->y + sum;
    sum = a->z * b->z + sum;
    return sum;
}

static inline void fn_1_25A14_add_bounds(Vec3 *v, Vec3 *lo, Vec3 *hi)
{
    lbl_8006E1C0(v, &lbl_801A66CC->delta);
    MINMAX(*lo, *hi, x)
    MINMAX(*lo, *hi, y)
    MINMAX(*lo, *hi, z)
}

/* WARNING: compiler-diff device, not original code */
extern const f32 lbl_1_rodata_84C; /* the TU's own 0.0f literal, exported by the unit's pool map */

s32 fn_1_25A14(fn_1_25A14_Machine *m)
{
    Vec3 vecs[4][4];
    Vec3 lo[3];
    Vec3 hi[3];
    f32 dz;
    u32 masks[4];
    Vec3 out0;
    Vec3 out1;
    Vec3 sum0;
    Vec3 sum1;
    u32 mask;
    u32 *mp;
    u32 v;
    s32 hit;
    s32 k;
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    s32 found;
    f32 len1;
    f32 len0;
    s32 id;
    fn_1_25A14_Corner30 *c;
    fn_1_25A14_Result *r;
    u32 flags;
    fn_1_25A14_Corner5C *h;
    fn_1_25A14_Result **pair;
    fn_1_25A14_Corner30 *corner;
    s32 ok;
    ColiWork *p;
    fn_1_25A14_Corner30 *cc;
    f32 dy;
    f32 dx;
    u32 *refs[4][4];
    f32 best;
    s32 nearest;

    mask = 0x22800;
    if (m->unk_0 & 2) {
        mask |= 0x1700;
    }
    hit = fn_1_2A694((void *)m, (void *)&m->unk_3B4[0].unk_C, (void *)NULL, mask, (void *)&out0, (void *)&out1);
    a = fn_1_8C704(m->unk_4);
    b = fn_1_8C6D4(m->unk_4);
    flags = 0x01020005;
    if (a < 0 || a == b) {
        flags |= 0x02000000;
    }
    switch (fn_1_7B054()) {
    case 24:
        if (m->unk_50C < 4) {
            flags |= 0x80000000 >> m->unk_50C;
        }
        break;
    case 16:
        id = *m->unk_49C->unk_90;
        if (id >= 0x62 && id <= 0x77) {
            flags |= 0x80000000 >> m->unk_50C;
        }
        break;
    case 8:
        id = *m->unk_49C->unk_90;
        if ((id >= 0x22 && id <= 0x24) || (id >= 0x2D && id <= 0x2F)) {
            flags |= 0x80000000 >> m->unk_50C;
        }
        break;
    case 28:
        id = *m->unk_49C->unk_90;
        if ((id >= 0x77 && id <= 0x8E) || (id >= 0xAA && id <= 0xC4)) {
            flags |= 0x80000000 >> m->unk_50C;
        }
        break;
    }
    mp = masks;
    masks[0] = 0;
    masks[1] = 0;
    masks[2] = 0;
    masks[3] = 0;
    corner = m->unk_3B4;
    for (i = 0; i < 4; i++, corner++) {
        pair = m->unk_488[i];
        fn_1_2A8D0((void *)m, (u8 *)corner, (void *)pair, flags, vecs[i], (void *)refs[i], masks, 1 << (31 - i));
    }
    for (i = 0; i < 4; i++) {
        r = m->unk_488[i][1];
        if (hit) {
            r->unk_C = out0;
        } else {
            r->unk_C.x = 0.0f;
            r->unk_C.y = 0.0f;
            r->unk_C.z = 0.0f;
        }
    }
    if (m->unk_1C8 <= 1.1920928955078125e-07f) {
        m->unk_50F = 0;
    } else if (!(m->unk_61C & 0x01800000) && (m->unk_0 & 2)) {
        m->unk_50F = 0;
    }
    found = 0;
    if ((fn_1_7B054() != 29 && fn_1_7B054() != 39) || hit == 0) {
        for (i = 0; i < 4; i++) {
            pair = m->unk_488[i];
            if (m->unk_50F != 0 || (pair[1]->unk_4 & 0xF0000000) != 0xF0000000) {
                if (!(m->unk_0 & 2) && m->unk_1C8 > 1.1920928955078125e-07f) {
                    m->unk_50F = 1;
                }
                found = 1;
                break;
            }
        }
    }
    h = m->unk_244;
    for (i = 0; i < 4; i++, h++) {
        if (found) {
            h->unk_0 |= 0x20;
            masks[0] = 0;
            vecs[i][0].x = 0.0f;
            vecs[i][0].y = 0.0f;
            vecs[i][0].z = 0.0f;
            vecs[i][1] = vecs[i][3];
            masks[1] = masks[3];
            if (refs[i][0] != NULL) {
                *refs[i][0] &= 0x0FFFFFFF;
            }
            if (refs[i][1] != NULL) {
                *refs[i][1] &= 0x0FFFFFFF;
            }
        } else {
            h->unk_0 &= ~0x20;
            masks[3] = 0;
            if (refs[i][3] != NULL) {
                *refs[i][3] &= ~4;
            }
        }
    }
    if (hit && masks[0]) {
        for (i = 0; i < 4; i++) {
            if (BIT(masks[0], i) && fn_1_25A14_dot_product(&out0, &vecs[i][0]) < 0.0f) {
                vecs[i][0].x = 0.0f;
                vecs[i][0].y = 0.0f;
                vecs[i][0].z = 0.0f;
                masks[0] &= ~(0x80000000 >> i);
                if (refs[i][0] != NULL) {
                    *refs[i][0] &= 0x0FFFFFFB;
                }
            }
        }
    }
    v = 0;
    for (i = 0; i < 4; i++) {
        if (BIT(masks[0], i)) {
            v |= *refs[i][0];
        }
    }
    v &= 0xC000;
    if (v == 0xC000) {
        v = 0;
    }
    for (i = 0; i < 4; i++) {
        m->unk_488[i][1]->unk_18 = v;
    }
    for (i = 0; i < 4; i++) {
        psvec_add(&vecs[i][0], &vecs[i][2], &m->unk_3B4[i].unk_24);
    }
    {
        f32 zero = lbl_1_rodata_84C;

        m->unk_198.x = zero;
        m->unk_198.y = zero;
        m->unk_198.z = zero;
        m->unk_1A4.x = zero;
        m->unk_1A4.y = zero;
        m->unk_1A4.z = zero;
    }
    if (hit || masks[0] || masks[1] || masks[2]) {
        lbl_8006DAEC();
        lbl_8006DF44();
        /* retail steps the vecs column (i) after mp, apart from the lo/hi row (j) */
        for (j = 0, i = 0; j < 3; j++, mp++, i++) {
            lo[j].x = 0.0f;
            hi[j].x = 0.0f;
            lo[j].y = 0.0f;
            hi[j].y = 0.0f;
            lo[j].z = 0.0f;
            hi[j].z = 0.0f;
            if (j == 0 && hit) {
                fn_1_25A14_add_bounds(&out0, &lo[j], &hi[j]);
            }
            for (k = 0; k < 4; k++) {
                if (BIT(*mp, k)) {
                    fn_1_25A14_add_bounds(&vecs[k][i], &lo[j], &hi[j]);
                }
            }
        }
        lbl_8006DB30();
        psvec_add(&hi[0], &hi[1], &m->unk_198);
        psvec_add(&hi[2], &m->unk_198, &m->unk_198);
        psvec_add(&lo[0], &lo[1], &m->unk_1A4);
        psvec_add(&lo[2], &m->unk_1A4, &m->unk_1A4);
        lbl_8006E1C0(&m->unk_1A4, &m->unk_1A4);
        lbl_8006E1C0(&m->unk_198, &m->unk_198);
    }
    psvec_add(&m->unk_198, &m->unk_1A4, &m->unk_1B0);
    if (hit) {
        psvec_sub(&out1, &m->unk_1B0, &lbl_801A66CC->delta);
        p = lbl_801A66CC;
        cc = m->unk_3B4;
        for (i = 0; i < 4; i++, cc++) {
            dx = p->delta.x;
            dx -= cc->unk_18.x;
            dy = p->delta.y;
            dy -= cc->unk_18.y;
            dz = p->delta.z;
            dz -= cc->unk_18.z;
            dx *= dx;
            dx += dy * dy;
            dx += dz * dz;
            if (i == 0 || best > dx) {
                nearest = i;
                best = dx;
            }
        }
        c = &m->unk_3B4[nearest];
        if (c->unk_24.x == 0.0f && c->unk_24.y == 0.0f && c->unk_24.z == 0.0f) {
            c->unk_24 = out0;
        }
    }
    if (masks[3]) {
        m->unk_218 |= 0x02000000;
        m->unk_58C |= 0x200;
    }
    ok = hit || (masks[0] && (hi[0].x != 0.0f || hi[0].y != 0.0f || hi[0].z != 0.0f || lo[0].x != 0.0f ||
                              lo[0].y != 0.0f || lo[0].z != 0.0f));
    if (!ok) {
        return 0;
    }
    ok = masks[1] && (hi[1].x != 0.0f || hi[1].y != 0.0f || hi[1].z != 0.0f || lo[1].x != 0.0f ||
                      lo[1].y != 0.0f || lo[1].z != 0.0f);
    if (!ok) {
        return 1;
    }
    psvec_add(&hi[0], &lo[0], &sum0);
    psvec_add(&hi[1], &lo[1], &sum1);
    fn_1_25A14_square_length_to(&sum1, &len1);
    fn_1_25A14_square_length_to(&sum0, &len0);
    if (len1 < len0 || (hit && len1 < fn_1_25A14_square_length(&out0))) {
        return 1;
    }
    return 0;
}
#undef BIT
#undef CUR
#undef MINMAX
/* fzgx:end fn_1_25A14 */

/* fzgx:begin fn_1_266A8 */
#define GAME_VEC3_H

static inline f32 collision_vector_squared(const Vec3 *v)
{
    f32 sum; f32 x; f32 y; f32 z;
    x=v->x; y=v->y;
    sum = (x*x); sum += y*y;
    z=v->z; sum += z*z;
    return sum;
}

#define LENGTH(v) lbl_8006D0B4(collision_vector_squared(&(v)))

static inline f32 collision_factor(f32 speed, CollisionObject *obj,
                                  Vec3 *projected, Vec3 *remainder,
                                  f32 projection)
{
    f32 factor = 2.0 * __fabs(0.5f + speed);
    psvec_scale(&obj->normal, projection, projected);
    psvec_sub(&obj->velocity, projected, remainder);
    return factor;
}

static void stcoli_slide(CollisionObject *obj)
{
    Vec3 up;
    Vec3 projected;
    Vec3 remainder;
    f32 speed;
    f32 dot;
    f32 k;

    if (!(LENGTH(obj->velocity) / obj->scale < 0.046296296296296294)) {
        f32 len;
        lbl_8006E1F0((void *)&up, 0.0f, 1.0f, 0.0f);
        k = lbl_8006D6FC(&up, &obj->normal);
        speed = lbl_8006D6FC(&obj->velocity, &obj->normal);
        len = LENGTH(obj->velocity);
        if (k < 0.0f) {
            k = 0.0f;
        }
        obj->field_224 *= k;
        dot = len * speed;
        len = collision_factor(speed, obj, &projected, &remainder, dot);
        if (len < 0.9f) {
            lbl_8006D5F0(&remainder, &remainder, 0.9f * ((1.0f - (f32)(1.11f * len)) * k));
        }
        psvec_scale(&projected, k, &projected);
        psvec_sub(&obj->velocity, &projected, &obj->velocity);
        psvec_add(&obj->velocity, &remainder, &obj->velocity);
    }
}

void fn_1_266A8(CollisionObject *obj)
{
    Vec3 impulse;
    Vec3 converted;
    Vec3 part;
    f32 dot;
    f32 k;
    f32 speed;
    f32 collisionLength;
    f32 damage;
    s32 hit;
    s32 active;
    s32 i;

    hit = fn_1_25A14((void *)obj);
    collisionLength = LENGTH(obj->collision);
    speed = LENGTH(obj->velocity) / obj->scale;
    if (collisionLength > 0.0023148148148148147) {
        if (hit != 0) {
            obj->flags |= 0x800000;
            if (obj->field_213 < 180) {
                obj->field_213++;
            }
        } else {
            obj->flags |= 0x1000000;
        }
        if ((obj->flags & 0x10) && obj->field_17c > 0.1) {
            if (collisionLength > 2.0) {
                fn_1_F7338(obj->field_474, (void *)2, (void *)9);
            } else if (collisionLength > 0.5) {
                fn_1_F7338(obj->field_474, (void *)3, (void *)9);
            } else {
                fn_1_F7338(obj->field_474, (void *)4, (void *)9);
            }
        }
    }
    active = 0;
    if (collisionLength > 0.004629629629629629 && speed > 0.004629629629629629) {
        active = 1;
    }
    if (obj->field_481 > 60) {
        active = active && (obj->flags & 0x800000);
    }
    if (active) {
        obj->field_500 = obj->collision;
        dot = lbl_8006D6FC(&obj->collision, &obj->velocity);
        if (dot > 0.0f) {
            dot = 0.0f;
        }
        if (speed > 0.023148148148148147) {
            f32 normalDot = lbl_8006D6FC(&obj->collision, &obj->normal);
            damage = 0.0f;
            if ((f32)__fabs(normalDot) < 0.7f) {
                normalDot = dot;
                normalDot *= dot;
                normalDot = (0.15f + normalDot) / 1.5f;
                normalDot *= LENGTH(obj->velocity);
                damage = normalDot;
                if (obj->flags & 0x200) {
                    damage /= 2000.0f;
                } else {
                    damage /= 500.0f;
                    if (obj->field_216) {
                        damage *= 0.15f;
                    }
                }
            }
            if (dot < -0.5f) {
                obj->flags &= 0xFF9FFF9F;
                obj->field_18a = 0;
                obj->field_18b = 0;
            }
            if (obj->field_17c > 0.1f) {
                if (damage > 0.4) {
                    fn_1_F7338(obj->field_474, (void *)2, (void *)9);
                } else if (damage > 0.2) {
                    fn_1_F7338(obj->field_474, (void *)3, (void *)9);
                } else {
                    fn_1_F7338(obj->field_474, (void *)4, (void *)9);
                }
            }
            if ((obj->flags & 0x800000) && obj->field_214 == 0 && obj->field_593 == 0) {
                f32 amount;
                f32 limit;
                amount = damage * *(f32 *)((u8 *)obj + 0x30);
                if (!(obj->flags & 0x200) && amount > 20.0f) {
                    amount = 20.0f;
                }
                limit = 1.01f * obj->field_5da;
                if (amount > limit) {
                    amount = limit;
                }
                obj->field_4ac = amount;
                if ((obj->field_184 -= obj->field_4ac) < 0.0f) {
                    if (!(obj->flags & 0x10080)) {
                        obj->field_593 = 60;
                    }
                    obj->flags |= 0x80;
                    obj->field_184 = 0.0f;
                    obj->field_224 = 0.0f;
                }
            }
        }
        lbl_8006D5F0(&obj->collision, &impulse, dot * LENGTH(obj->velocity));
        if (dot < 0.0f) {
            if (obj->field_216 == 0) {
                f32 t = dot / 0.7f;
                f32 m = 0.2f + (f32)(0.6f * lbl_8006D0B4(1.0f - (f32)(t * t)));
                obj->field_224 *= m;
                obj->field_228 *= 0.3f + (f32)(0.4f * m);
            } else {
                f32 t = dot / 0.7f;
                f32 m = 0.64f + (f32)(0.35f * lbl_8006D0B4(1.0f - (f32)(t * t)));
                obj->field_224 *= m;
                obj->field_228 *= 0.3f + (f32)(0.6f * m);
            }
        }
        if (speed > 1.8518518518518519) {
            f32 factor;
            if (obj->flags & 0x80) {
                factor = 3.4000000953674316 - (f64)(1.7000000476837158 * __fabs(dot));
            } else if (obj->field_216) {
                factor = 2.0 - __fabs(dot);
            } else {
                factor = 3.0 - (f64)(1.5 * __fabs(dot));
            }
            if (dot < -0.4f && speed > 3.240740740740741) {
                k = -factor;
                psvec_scale(&impulse, k, &impulse);
                psvec_add(&impulse, &obj->velocity, &obj->velocity);
            } else {
                k = -factor;
                psvec_scale(&impulse, k, &impulse);
                psvec_add(&impulse, &obj->velocity, &obj->velocity);
            }
            if (obj->field_216 == 0) {
                obj->field_244 |= 4;
                obj->field_2a0 |= 4;
                obj->field_2fc |= 4;
                obj->field_358 |= 4;
            }
            obj->field_216 = 20;
        } else {
            k = -1.0f;
            psvec_scale(&impulse, k, &impulse);
            psvec_add(&impulse, &obj->velocity, &obj->velocity);
        }
        fn_8006E2B0(&impulse, &converted);
        obj->field_c4 += converted.x;
        obj->field_c8 += converted.z;
        if (obj->flags & 0x400) {
            for (i = 0; i < 4; i++) {
                part = obj->parts[i].point;
                part.z += 0.2f;
                fn_1_29044((void *)obj, (void *)&part, (void *)&obj->parts[i].dest);
            }
        }
        if (obj->field_481 > 60) {
            fn_1_2A2A4((void *)obj);
        }
    } else if (obj->flags & 0x10) {
        stcoli_slide(obj);
    }
    psvec_add(&obj->position, &obj->collision, &obj->position);
}
#undef GAME_VEC3_H
#undef LENGTH
/* fzgx:end fn_1_266A8 */

/* fzgx:begin fn_1_26F34 */
#define GAME_VEC3_H

#define F(o) (*(f32 *)((u8 *)arg0+(o)))

#define U(o) (*(u32 *)((u8 *)arg0+(o)))

#define H(o) (*(u16 *)((u8 *)arg0+(o)))

#define B(o) (*(u8 *)((u8 *)arg0+(o)))

#define K(n) K_##n

#define K_C 0.0f

#define K_14 1.0f

#define K_1C 0.5f

#define K_28 40.0f

#define K_2C 348.0f

#define K_30 36.0f

#define K_34 4.0f

#define K_38 0.6f

#define K_3C 5.0f

#define K_40 0.05f

#define K_44 1000.0f

#define K_68 0.2f

#define K_78 2.0f

#define K_98 0.15f

#define K_A4 0.12f

#define K_C8 0.01f

#define K_104 0.8f

#define K_114 1.1920928955078125e-7f

#define K_11C 0.95f

#define K_130 0.3f

#define K_168 10.0f

#define K_16C 100.0f

#define K_24C 0.0001f

#define K_250 0.014f

#define K_254 9.0f

#define K_258 60.0f

#define K_25C 3.0f

#define K_260 0.16666667f

#define K_264 1200.0f

#define K_268 1600.0f

/* squared ratio: the argument is evaluated once and its square taken in place */

static inline f32 sq_f32(f32 x) { return x * x; }

f32 fn_1_26F34(u32 arg0, f32 arg1, f32 arg2, f32 arg3) {
 u32 v0=U(0), v1; s32 v9;
 f32 v5, v16, v36, v41, v2, v45, v49, v52, v54, v60, v66;
 f32 v6, v7, v28, v30, v31, v32;
 s32 v14;
 if ((v0&0x80) && H(0x4e0)<120) {
  v1=B(0x197);
  if(v1>60) { F(0x200)=K(C); F(0x204)=K(24C); }
  else B(0x197)=v1+1;
  return K(C);
 }
 v5=F(0x200);
 if(U(0x58c)&4) {
  if(v5<K(C) || B(0x197)>=30) v5=K(C);
 } else {
  if(v5<K(C) || F(0x204)>K(C)) v5=K(C);
 }
 if(!(v0&0x400) && v5<K(130)) v5=K(C);
 if(v5>K(114)) {
  if(!(v0&0x400)) { U(0)|=0x400; B(0x481)=1; }
  if(U(0)&0x8000) F(0xdc)=(F(0xdc)+v5);
  else if(F(0xdc)>K(C)) { F(0x224)=K(14); U(0)|=0x180000; F(0xdc)=K(C); }
 } else {
  v6=F(0xdc);
  if(v6>K(C)) {
   v7=(v6-K(78));
   F(0xdc)=v7;
   if(v7<K(C)) F(0xdc)=K(C);
   if(!(U(0)&0x8000)) F(0x224)=K(C);
  } else if(v0&0x8000) F(0x224)=K(C);
 }
 v1=U(0);
 if(v1&0x8000) {
  F(0x224)=(K(250)*F(0xdc)); B(0x241)=0; B(0x240)=0; return -arg1;
 }
 arg1=(arg1/F(8));
 if((s8)B(0x474)!=-1) {
  v9=(v1>>6)&1;
  if(H(0x4c6)) { U(0)=v1&~0x40; H(0x4c6)--; }
  if(v9 != 0) { if(H(0x4c6)) H(0x4c6)++; else H(0x4c6)=6; }
 }
 v1=U(0);
 if(v1&0x400000) {
  v16=(K(14)-(F(0x228)/(K(254)*F(0x230))));
  v14=(K(1C)*(K(258)*F(0x234)));
  fn_1_2A3E4((void *)((Sig_fn_1_2A3E4_Fn_1_2A3E4 *)arg0));
  if((u8)v14>B(0x18a)) B(0x18a)=v14;
  U(0)&=~0x40; U(0)|=0x20;
  if(v16<K(68)) v16=K(68);
  F(0x228)=(F(0x228)+(f32)((K(78)*F(0x230))*v16));
  fn_1_F7338(*(s8 *)(arg0+0x474),(void *)3,(void *)15);
  if(B(0x4b2)<100) B(0x4b2)++;
 } else if(B(0x18a)) {
  U(0)=v1&~0x40; U(0)|=0x20;
 } else if((v1&0x40) && F(0x184)>K(14) && v5>K(C)) {
  v16=(K(14)-(F(0x228)/(K(254)*F(0x230))));
  fn_1_2A3E4((void *)((Sig_fn_1_2A3E4_Fn_1_2A3E4 *)arg0));
  v14=(K(258)*F(0x234));
  B(0x18a)=v14; B(0x18b)=v14;
  U(0)|=0x20; U(0)&=~0x200000;
  if(v16<K(68)) v16=K(68);
  if(B(0x217)<100) B(0x217)++;
  F(0x228)=(F(0x228)+(f32)(F(0x230)*v16));
  fn_1_F7338(*(s8 *)(arg0+0x474),(void *)1,(void *)15);
 } else {
  U(0)&=0xffdfff9f;
  F(0x228)=(F(0x228)-((K(34)+(f32)(K(1C)*F(0x228)))/K(258)));
 }
 if(U(0)&8) {
  v28=F(0x228);
  F(0x228)=(v28-((K(25C)+(f32)(K(1C)*v28))/K(258)));
  v5 *= K(104);
 } else {
  v30=F(0x228);
  F(0x228)=(v30-((K(78)+(f32)(K(1C)*v30))/K(258)));
 }
 if(F(0x228)<K(C)) F(0x228)=K(C);
 v5 *= (K(28)*F(0x220));
 if(U(0)&0x20) {
  if(B(0x18b)) { F(0x184)=(F(0x184)-(f32)(K(260)*F(0x4dc))); B(0x18b)--; }
  if(--B(0x18a)==0 && F(0x17c)>K(264)) {
   v36=((F(0x17c)-K(264))/K(258));
   if(v36>K(168)) v36=K(168);
   if(v36>H(0x4c6)) H(0x4c6)=v36;
  }
  if(F(0x184)<K(C8)) {
   F(0x184)=K(C8); B(0x18b)=0;
   if(U(0)&0x200000) {
    v14=(K(1C)*(K(258)*F(0x234)));
    if(B(0x18a)>(u8)v14) B(0x18a)=v14;
   } else B(0x18a)=0;
  }
 }
 {
 f32 v40, v42, v43, v44;
 v41=(v5/K(2C));
 v2=F(0x22c);
 v40=(K(28)*v2);
 v41+=F(0x224);
 v45=K(78);
 v44=((K(30)+v40)+(f32)(F(0x228)*v45));
 v42=F(8); v43=K(C);
 arg2=((arg2*F(0x220))/v42);
 v2=(v41-arg1);
 v49=(v41/v44);
 if(v49<v43) v49=v43;
 v49 *= (K(34)*(F(0x220)*(K(38)+F(0x220))));
 v1=U(0);
 if(v1&0x400040) v49=K(C);
 else if(v1&0x20) { if(v42>K(44)) v49 *= K(1C); else v49 *= K(130); }
 }
 if(v2>K(C) && (arg1<K(C) || ((U(0x218)>>29)&1))) v49 *= K(3C);
 v52=((K(14)-arg3)*((f32)(v2*v49)+(f32)(arg2*F(0x238))));
 if(F(0x200)<K(14)) v52=(v52*(K(40)+(f32)(K(11C)*F(0x200))));
 F(0x224)=(v41-v52);
 if(F(0x204)>K(40)) { if(B(0x197)<30) B(0x197)++; } else B(0x197)=0;
 if(U(0x58c)&4) {
  if(B(0x197)>=15) v54=(F(0x204)*(K(1C)*v49)); else v54=K(C);
 } else v54=(F(0x204)*(K(1C)*v49));
 if(v54>K(A4)) v54=K(A4);
 if(v54>F(0x224)) F(0x224)=K(C); else F(0x224)=(F(0x224)-v54);
 if(F(0x224)>F(0x23c)) F(0x224)-=F(0x23c); else F(0x224)=K(C);
 if(!(v54>K(C))) {
  v60=K(14); if(!(U(0)&0x2000)) v60=K(130);
  if(arg1<K(C)) v2=(v2*(K(1C)*v60));
  else if(v2<K(C)) v2=(v2*(K(1C)*v60));
 }
 if(B(0x241)) {
  F(0x224)=(F(0x224)*(K(14)-(f32)(K(38)*sq_f32((B(0x240)/(K(25C)*B(0x241)))))));
  if(B(0x240)>B(0x241) || F(0x224)<=K(C)) { B(0x240)=0; B(0x241)=0; }
  else B(0x240)++;
 }
 v1=U(0);
 if(v1&0x80) {
  v66=(F(0x17c)/K(16C)); if(v66>K(14)) v66=K(14);
  v2=(v2*(K(68)-(f32)(K(98)*v66)));
 }
 if(v1&0x200020) { if(F(8)>K(44)) v2=K(268)*v2; else v2=K(264)*v2; }
 else v2=K(44)*v2;
 return v2;
}
#undef GAME_VEC3_H
#undef F
#undef U
#undef H
#undef B
#undef K
#undef K_C
#undef K_14
#undef K_1C
#undef K_28
#undef K_2C
#undef K_30
#undef K_34
#undef K_38
#undef K_3C
#undef K_40
#undef K_44
#undef K_68
#undef K_78
#undef K_98
#undef K_A4
#undef K_C8
#undef K_104
#undef K_114
#undef K_11C
#undef K_130
#undef K_168
#undef K_16C
#undef K_24C
#undef K_250
#undef K_254
#undef K_258
#undef K_25C
#undef K_260
#undef K_264
#undef K_268
/* fzgx:end fn_1_26F34 */

/* fzgx:begin fn_1_278B8 */
/* begin game/main_rel/camera_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAMERA_TYPES_H

// Types (and the externs that name them) of camera.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

/* WARNING: compiler-diff device, not original code */
#pragma fp_contract off

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

f32 fn_1_278B8(u8 *arg0, void *arg1, f32 arg2) {
    f64 tmp_call4;
    s32 v0;
    f32 tmp___fmadds;
    f32 v1, v2, v3;
    s16 v4;
    void *v5;
    f32 v6, v7;
    s32 v8;
    f32 v9, v10, v11, v12;
    u32 v13;
    s32 unk_1;
    f32 v15, v16, v17, v18, v19, v20;
    u32 v21;
    f32 v22, v23, v27, v25, v26, v24;
    f64 v28;
    u32 v29;
    f32 v31, v34;
    void *v35;
    f32 v36, v37;
    Vec3 loc_2C;
    Vec3 loc_20;
    Vec3 loc_14;
    Vec3 loc_8;
    f64 t3;
    v0 = (*(u32 *)(arg1) & 4);
    psvec_sub((u8 *)arg1 + 20, (u8 *)arg1 + 32, &loc_2C);
    lbl_8006DAEC();
    v1 = (*(f32 *)(arg0 + 508) * *(f32 *)(arg0 + 32));
    v2 = 182.04444885253906f;
    v3 = -(v1 + (*(f32 *)(arg0 + 504) * *(f32 *)(arg0 + 28)));
    v6 = v3 < -45.0f ? -45.0f : (v3 > 45.0f ? 45.0f : v3);
    v4 = (v2 * v6);
    mathutil_mtxA_rotate_y((s16)(v4 / 2));
    v5 = &loc_2C;
    fn_8006E2B0(v5, (Vec3 *)v5);
    v1 = loc_2C.x * loc_2C.x;
    tmp___fmadds = __fmadds(loc_2C.y, loc_2C.y, v1);
    v1 = tmp___fmadds;
    tmp___fmadds = __fmadds(loc_2C.z, loc_2C.z, v1);
    v1 = tmp___fmadds;
    tmp_call4 = lbl_8006D0B4(v1);
    t3 = 216.0 * tmp_call4;
    v6 = 0.0f;
    loc_14.y = v6;
    loc_14.x = 1.0f;
    loc_14.z = v6;
    v7 = (t3 / 1000.0);
    v11 = loc_2C.x;
    v8 = 0;
    if (v0 == 0 && (*(u32 *)arg1 & 0x10) != 0) v8 = 1;
    v9 = v6;
    if (v8 != 0 || *(u8 *)(arg0 + 1142) != 0) {
        v9 = 20.0f;
    } else {
        v10 = *(f32 *)(arg0 + 12);
        v9 = v10;
        if ((*(u32 *)(arg0 + 1420) & 4) != 0) {
            if (v0 != 0 && *(u8 *)(arg0 + 407) < 30) {
                v9 = *(f32 *)(arg0 + 40);
                if (v9 > v10) v9 = v10;
            }
        } else {
            if (v0 != 0 && *(u8 *)(arg0 + 407) == 0)
                v9 = *(f32 *)(arg0 + 40);
        }
    }
    if (__fabs(v11) < *(f32 *)(arg0 + 40)) *(u32 *)arg1 &= ~0x10;
    unk_1 = 1;
    if (v0 == 0 && !(__fabs(*(f32 *)(arg0 + 508)) > (f64)0.7f)) unk_1 = 0;
    if (__fabs(v11) > v9 && unk_1 != 0) {
        *(u32 *)arg1 |= 4;
        if (v11 < 0.0f) v9 = -v9;
        v11 = v9;
    } else {
        if (__fabs(v11) < 1.1920928955078125e-7) v11 = 0.0f;
        *(u32 *)arg1 &= ~4;
    }
    v13 = *(u32 *)arg0;
    if ((v13 & 0x03820000) != 0) v11 = 0.0f;
    if ((v13 & 0x08000000) != 0) {
        v11 *= 0.2f;
    } else if ((v13 & 0x80) != 0) {
        v17 = 0.01f * ((f32)*(u16 *)(arg0 + 1248) - 4.0f);
        v18 = v17 < 0.0f ? 0.0f : (v17 > 0.05f ? 0.05f : v17);
        v11 *= v18;
    }
    if (0.0f != v11) {
        v19 = *(f32 *)(arg0 + 16);
        v31 = v11 * *(f32 *)(arg0 + 8);
        if (v19 < 0.1f && *(u8 *)(arg0 + 1142) == 0) {
            v21 = *(u32 *)arg1;
            if ((v21 & 2) == 0 && (v13 & 0x40) == 0) {
                v22 = 0.2f;
                v23 = 1.0f;
                v24 = v23 - (f32)*(u8 *)(arg0 + 534) / 20.0f;
                v25 = v7;
                if (v7 < v22) v25 = v22;
                else {
                    v26 = 0.8f;
                    if (v7 > v26) v25 = v26;
                }
                v27 = ((v25 - 0.2f) / 0.6f) * (v19 - 0.1f);
                if ((v21 & 4) != 0) v27 = 0.0f;
                else {
                    v28 = (f64)0.3f;
                    v27 *= v28 + (f64)0.7f * __fabs(*(f32 *)(arg0 + 508));
                }
                v31 *= 0.1f + (v27 * v24);
            } else v31 *= 0.1f;
        } else v31 *= v19;
        v29 = *(u32 *)(arg0 + 536);
        if (v29 >> 31) v31 *= 0.003f;
        else if ((v29 >> 29) & 1) v31 *= 2.0f;
        psvec_scale(&loc_14, v31, &loc_14);
        lbl_8006E1C0(&loc_14, &loc_20);
        psvec_add(&loc_20, (u8 *)arg1 + 76, (u8 *)arg1 + 76);
        if ((*(u32 *)arg1 & 4) != 0) v31 *= 0.6f;
        *(f32 *)((u8 *)arg0 + 1408) += v31;
    }
    lbl_8006DB30();
    loc_8 = *(Vec3 *)((u8 *)arg1 + 76);
    psvec_add(&loc_8, (u8 *)arg0 + 148, (u8 *)arg0 + 148);
    if (*(u8 *)(arg0 + 534) < 6)
        fn_1_29044((void *)arg0, (void *)((u8 *)arg1 + 8), (void *)((u8 *)arg1 + 76));
    v35 = &loc_8;
    fn_8006E2B0(v35, (Vec3 *)v35);
    if (v0 != 0 && (*(u32 *)arg0 & 0x02000000) == 0) arg2 *= *(f32 *)(arg0 + 36);
    v37 = *(f32 *)(arg0 + 164);
    *(f32 *)((u8 *)arg0 + 164) = v37 - (f32)(0.125f * arg2);
    return v37;
}
/* fzgx:end fn_1_278B8 */

/* fzgx:begin fn_1_27DE4 */
#pragma opt_common_subs reset

void fn_1_27DE4(CollisionObject_278B8 *obj)
{
    Vec3 delta;
    if (!(obj->flags & 0x8000)) {
        psvec_sub(&obj->position, &obj->previous, &delta);
        psvec_add(&obj->displacement, &delta, &obj->displacement);
    }
}
#undef GAME_MAIN_REL_CAMERA_TYPES_H
#undef GAME_VEC3_H
#pragma fp_contract reset
/* fzgx:end fn_1_27DE4 */

/* fzgx:begin fn_1_27E34 */
/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

s32 fn_1_27E34(Object *arg0)
{
    /* WARNING: compiler-diff device, not original code */
    f32 one;
    Ctx_27E34 ctx;
    Vec3 tmp;
    Vec3 out;
    Vec3 cur;
    f32 dist;
    Mgr_27E34 *mgr;
    u32 mode;
    Object *obj = arg0;
    s32 ret;
    s32 a;
    s32 b;
    MgrEntry *ent;

    mode = 0x04060005;
    a = fn_1_8C704(obj->f_4);
    b = fn_1_8C6D4(obj->f_4);
    if (a < 0 || a == b) {
        mode |= 0x200000;
    }
    obj->v_4fc = 0;
    mgr = ((Mgr_27E34 *)fn_1_14F04());
    lbl_8006E1D8(&tmp, 0.0f, -2000.0f, 0.0f);
    psvec_set(&cur, *(f32 *)(LC_BASE + 0x2C), *(f32 *)(LC_BASE + 0x1C), *(f32 *)(LC_BASE + 0x0C));
    obj->v_1d4 = tmp;

    if (fn_1_7B054() == 0x24 || fn_1_7B054() == 0x25) {
        Group *g = obj->g_488;
        Group *h;
        Group *j;
        Group *k;
        ctx.a = &ctx.list_a;
        ctx.b = &ctx.list_b;
        ctx.b->flag = 1;
        ctx.b->f_1c = g->b->f_1c;
        ctx.b->m_3c = g->b->m_3c;
        ctx.b->f_4c = g->b->f_4c;
        ctx.a->flag = 0;
        ctx.a->m_3c = g->a->m_3c;
        h = obj->g_48c;
        ctx.b->m_3c &= h->b->m_3c;
        ctx.a->m_3c &= h->a->m_3c;
        j = obj->g_490;
        ctx.b->m_3c &= j->b->m_3c;
        ctx.a->m_3c &= j->a->m_3c;
        k = obj->g_494;
        ctx.b->m_3c &= k->b->m_3c;
        ctx.a->m_3c &= k->a->m_3c;
        ((Mgr_27E34 *)fn_1_14F04())->f_700 = (u32)&ctx;
    }

    if (fn_1_2A500((void *)obj, (void *)&obj->v_1d4, (void *)&cur, (void *)&out, (void *)mode, (void *)&dist)) {
        dist = 20.0f + (dist - 2000.0f);
        if (dist <= 0.0f && !(obj->flags & 0x800)
            && (mgr->f_118 & 0x1C00000) != 0 && (mode & 0x200000) != 0) {
            if (!(mgr->f_118 & 0x800000) || fn_1_7B054() != 15) {
                dist = 1.1920928955078125e-07f;
            }
        }
        obj->v_4fc = mgr->f_24;
    } else {
        dist = 0.0f;
    }

    if (dist <= 0.0f) {
        ret = 0;
        obj->v_1bc.x = 0.0f;
        one = 1.0f;
        obj->v_1bc.y = one;
        obj->v_1bc.z = 0.0f;
        obj->v_1d4 = cur;
        obj->v_1c8 = 0.0f;
        obj->v_21c = 0;
        obj->v_61c = 0;
    } else {
        ret = 1;
        obj->v_1bc = out;
        obj->v_1c8 = dist;
        obj->v_1cc = mgr->f_110;
        obj->v_1d0 = mgr->f_114;
        ent = (MgrEntry *)((u8 *)mgr + (mgr->f_10c << 7));
        obj->v_21c = ent->f_47c;
        obj->v_61c = mgr->f_118;
    }
    return ret;
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_27E34 */

/* fzgx:begin fn_1_28184 */
/* begin game/vec3.h (deltawave784/fzgx@7d73e43f (CC0)) */

#define GAME_VEC3_H

/* The TU's shared literal pool, addressed through one base register. */

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

static inline f32 norm28184(Vec3 *v) {
    f32 n = v->x * v->x;
    n += v->y * v->y;
    n += v->z * v->z;
    return lbl_8006D0B4(n);
}

static inline f32 square28184(f32 x) {
    return x * x;
}

static inline f32 add28184(f32 k, f32 x, f32 y) {
    f32 product = k * x;
    return y + product;
}

void fn_1_28184(Racer28184 *r) {
    Vec3 pos;
    Vec3 proj;
    Vec3 delta;
    Vec3 b;
    Vec3 a;
    Vec3 d;
    f32 len;
    f32 t;
    f32 sign;
    f32 dist;
    f32 s;
    f32 speed;
    f32 ratio;
    f32 scale;

    pos = r->pos;
    lbl_8006DAEC();
    if (((int)fn_1_163BC((void *)&pos, (void *)&r->center, 0x4000, fn_1_8C66C(r->id))) != 0) {
        psvec_sub(&r->pos, &r->center, &a);
        psvec_sub(&pos, &r->center, &d);
        len = norm28184(&a);
        scale = a.x * d.x;
        scale = __fmadds(a.y, d.y, scale);
        scale += a.z * d.z;
        t = scale / (len * len);
        psvec_scale(&a, t, &proj);
        psvec_add(&proj, &r->center, &proj);
        if (r->unk_17C > (600.0f)) {
            sign = (1.0f);
        } else {
            sign = (-1.0f);
        }
        psvec_sub(&proj, &pos, &d);
        dist = norm28184(&d);
        psvec_scale(&r->axis, (dist * lbl_8006D6FC(&r->axis, &d)), &b);
        psvec_add(&b, &pos, &b);
        psvec_sub(&proj, &b, &d);
        scale = norm28184(&d);
        dist = scale / (4.0f);
        s = sign * lbl_8006D0B4((1.0f) - square28184(dist));
        dist = s * s;
        scale = lbl_8006D0B4((1.0f) - dist);
        if (scale > (1.1920929e-07f)) {
            lbl_8006D5F0(&d, &d, scale);
        } else {
            d.x = (0.0f);
            d.y = (0.0f);
            d.z = (0.0f);
        }
        if (s > (1.1920929e-07f)) {
            lbl_8006D5F0(&a, &a, s);
        } else {
            a.x = (0.0f);
            a.y = (0.0f);
            a.z = (0.0f);
        }
        psvec_add(&d, &a, &a);
        lbl_8006D5F0(&a, &a, (4.0f));
        psvec_add(&a, &b, &r->pos);
        psvec_sub(&r->pos, &pos, &delta);
        lbl_8006DBAC((void *)r->mtx);
        fn_8006E2B0((void *)&delta, &delta);
        ratio = norm28184(&delta) / (20.0f);
        fn_1_A33F0(r->id, ratio < (0.00999999978f) ? (0.00999999978f)
                          : (ratio > (0.600000024f) ? (0.600000024f) : ratio));
        lbl_8006D5F0(&delta, &delta, (5.5555555555555554) * r->unk_8);
        r->unk_C4 = add28184((6.0f), delta.x, r->unk_C4);
        r->unk_C8 = add28184((2.0f), delta.z, r->unk_C8);
        lbl_8006E1C0((void *)&delta, (void *)&delta);
        psvec_add(&delta, &r->vel, &r->vel);
        speed = (20.0f);
        r->flags2 |= 0x40000000;
        if (r->unk_214 == 0 && r->unk_593 == 0) {
            speed *= r->unk_30;
            if (!(r->flags & 0x200) && speed > (20.0f)) {
                speed = (20.0f);
            }
            scale = (1.00999999f) * r->unk_5DA;
            if (speed > scale) {
                speed = scale;
            }
            r->unk_4AC = speed;
            scale = r->unk_184 - r->unk_4AC;
            r->unk_184 = scale;
            if (scale < (0.0f)) {
                if (!(r->flags & 0x10080)) {
                    r->unk_593 = 60;
                }
                r->flags |= 0x80;
                r->unk_184 = (0.0f);
                r->unk_224 = (0.0f);
            }
        }
        fn_1_694A4(r->id, &proj, &delta, ratio / (10.0f));
    }
    lbl_8006DB30();
}
#undef GAME_VEC3_H
#pragma opt_common_subs reset
/* fzgx:end fn_1_28184 */

/* fzgx:begin fn_1_28660 */
void fn_1_28660(Fn_1_28660 *self) {
    int result;
    int mask;

    lbl_8006DAEC();

    mask = 0x88;
    if ((self->field58c & 0x2) == 0) {
        mask |= 0x10;
    }
    if ((self->field4fc & 0x00100000) == 0) {
        mask |= 0x2;
    }
    if ((self->field4fc & 0x00080000) == 0) {
        mask |= 0x20;
    }
    if ((self->field4fc & 0x00040000) == 0) {
        mask |= 0x40;
    }
    if ((self->field4fc & 0x00020000) == 0) {
        mask |= 0x80;
    }

    if ((self->field00 & 0x2) != 0) {
        result = 0;
    } else {
        result = ((int)fn_1_163BC((void *)((char *)self + 0x7c), (void *)((char *)self + 0x88),
            mask, fn_1_8C66C(self->field04)));
    }

    if ((result & 0x8) != 0) {
        self->field00 |= 0x00600000;
        self->field218 |= 0x10000000;
    }
    if ((self->field4fc & 0x00100000) != 0 ||
        (result & 0x2) != 0) {
        if ((self->field00 & 0x80) == 0) {
            self->field58c |= 1;
            self->field218 |= 0x08000000;
        }
    }
    if ((self->field00 & 0x20) == 0) {
        if ((self->field4fc & 0x00040000) != 0 ||
            (result & 0x40) != 0) {
            self->field218 |= 0x20000000;
        }
    }
    if ((self->field4fc & 0x00080000) != 0 ||
        (result & 0x20) != 0) {
        self->field218 |= 0x80000000u;
    }
    if ((result & 0x10) != 0) {
        self->field218 |= 0x04000000;
    }
    if ((self->field4fc & 0x00020000) != 0 ||
        (result & 0x80) != 0) {
        self->field218 |= 0x02000000;
    }

    lbl_8006DB30();
}
/* fzgx:end fn_1_28660 */

/* fzgx:begin fn_1_287E8 */
/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

void fn_1_287E8(Fn_1_287E8 *self) {

    if (self->field17c < (300.0f)) {
        if (!self->field190) {
            self->flags = ((~8) & self->flags);
        }
        self->flags = self->flags & ~0x20000;
    }

    if (self->field480 != 0) {
        self->flags = self->flags & ~8;
    }

    if ((self->flags & 8) != 0) {
        u32 total = self->field190;

        if (total == 0) {
            self->field190 = 0x40000;
            self->field194 = 0x1000;
            if (self->field1fc > (0.0f)) {
                self->field196 = 0;
            } else {
                self->field196 = 1;
            }
        } else {
            u16 step = self->field194;

            if (total > step) {
                self->field190 = total - step;
                if (self->field190 < 0x20000) {
                    self->field194 = self->field194 - 0x41;
                    if (self->field194 < 0x50) {
                        self->field194 = 0x50;
                    }
                }
            } else {
                self->field190 = 0;
                self->field194 = 0;
                self->flags = self->flags & ~8;
            }
        }
        self->flags = self->flags & ~0x20000;
    } else {
        self->field190 = 0;
    }

    if (self->flags & 0x20000) {
        u8 counter;

        counter = self->field480;
        if (counter == 0) {
            self->field480 = 6;
        } else if (counter == 1) {
            self->flags = self->flags & ~0x20000;
        } else {
            self->field480 = counter - 1;
        }

        if ((self->flags & 0x02800000) != 0 ||
            self->field200 < (0.5f)) {
            self->flags = self->flags & ~0x20000;
            self->field480 = 1;
        }
    } else {
        self->field480 = 0;
    }

    if (self->field4c4 != 0) {
        self->field4c4 -= 1;
    }

    if ((self->flags & 0x20008) != 0) {
        return;
    }
    self->field212 = 0;
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_287E8 */

/* fzgx:begin fn_1_289B4 */
/* begin game/main_rel/stcoli_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_STCOLI_TYPES_H

// Types (and the externs that name them) of stcoli.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

/* Keeps the zero local of the v4B4 reset: retail loads 0.0f before 10000.0f (5 words without). */

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_289B4(Body *p, u32 *out, void *arg2) {
    s32 i;
    s32 pending;
    u8 *base;
    Part *part;
    u8 *base2;
    u8 *q;
    s32 allGrounded;
    s32 j;
    f32 len;
    f32 ang;
    f32 a;
    f32 b;
    f32 vx, vy, vz;
    f32 zero;
    u16 limit;
    u32 flags;
    u8 v;

    if (p->flags & 0x8000) {
        p->f1FC = 0.0f;
        p->f1F4 = 0.0f;
        p->f204 = 0.0f;
        p->f1F8 = 0.0f;
        p->flags &= ~0x00020048;
    }
    pending = (p->f218 >> 28) & 1;
    p->flags &= ~0x405C0016;
    p->f58C &= ~0x300;
    p->f218 = 0;
    if (!(p->flags & 0x10000000)) {
        fn_1_28660( (Fn_1_28660 *)(Body *)(p));
    }
    if (pending) {
        p->flags &= ~0x400000;
    }

    lbl_8006DBAC(p->mtx11C);
    mathutil_mtxA_set_translate(&p->prevPos);
    lbl_8006DD14((u32)p->mtxEC, p->mtx11C);
    p->pos4C8 = p->pos;
    p->prevPos = p->pos4C8;

    base = (u8 *)p;
    for (i = 0; i < 4; i++) {
        part = (Part *)(base + 0x244);
        fn_1_2A638( (Body *)(p), (Fn_1_2A638 *)(Part *)(part));
        if (part->flags & 4) {
            p->parts[0].flags |= 4;
            p->parts[1].flags |= 4;
            p->parts[2].flags |= 4;
            p->parts[3].flags |= 4;
        }
        base += 0x5c;
    }

    lbl_8006DBAC(p->mtxEC);
    mathutil_mtxA_set_translate(&p->pos);

    if (p->flags & 0x400) {
        *out = ((u32)fn_1_2AF0C((void *)p, (void *)arg2));
    } else {
        *out = 0;
    }

    base2 = (u8 *)p;
    q = (u8 *)p;
    allGrounded = 1;
    for (j = 0; j < 4; j++) {
        if (!(((Part *)(base2 + 0x244))->flags & 2)) {
            allGrounded = 0;
        }
        fn_1_2A678( (Fn_1_2A678_Source *)(Body *)(p), (Fn_1_2A678_Dest *)(q + 0x3B4));
        base2 += 0x5c;
        q += 0x30;
    }

    if (allGrounded) {
        p->flags |= 2;
        p->b483 += (p->b483 < 180);
        if (p->b483 > 10) {
            p->flags |= 4;
        }
    } else {
        if (p->b483 != 0) {
            p->flags |= 0x10;
        }
        p->b483 = 0;
        p->flags &= ~4;
        p->f58C &= ~2;
    }

    p->f580 = 0.0f;
    p->fC4 *= 0.8f;
    p->fC8 *= 0.9f;

    if (p->flags & 0x400) {
        p->b481 += (p->b481 != 255);
    }

    if ((p->flags & 0x10000) || ((p->f218 >> 27) & 1)) {
        p->f184 += 1.1111111640930176f;
        limit = p->h5DA;
        if (p->f184 > limit) {
            p->f184 = limit;
        }
    }

    vx = p->vel.x;
    vy = p->vel.y;
    vz = p->vel.z;
    len = vx * vx;
    len += vy * vy;
    len += vz * vz;
    len = lbl_8006D0B4(len);
    p->f17C = 216.0 * (len / p->mass);

    flags = p->flags;
    if ((flags & 0x8000000) && !(flags & 2)) {
        if (p->f17C < 10.0f) {
            p->vel.x = 0.0f;
            p->vel.y = 0.0f;
            p->vel.z = 0.0f;
        } else {
            psvec_scale(&p->vel.x, 0.8999999761581421f, &p->vel.x);
        }
    }

    fn_1_287E8( (void *)((struct fn_1_287E8_Arg0 *)(Body *)(p)));

    if (p->b4C5 != 0) {
        p->b4C5--;
    } else if (p->flags & 0x2000000) {
        p->b4C5 = 6;
    }
    if (p->b593 != 0) {
        p->b593--;
    }

    fn_8006E2B0(&p->vel, (void *)&p->fB8);
    lbl_8006DAEC();
    a = p->f1FC * p->f20;
    b = p->f1F8 * p->f1C;
    ang = -(a + b);
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (ang < -45.0f ? -45.0f : ang > 45.0f ? 45.0f : ang)));
    fn_8006E2B0(&p->vel, (void *)&p->fCC);
    p->fD0 = 0.0f;
    lbl_8006DB30();

    p->pos1E0 = p->pos;
    p->f47C++;

    v = p->b4C3;
    if (v != 0) {
        if ((v & 0xF) - 1 != 0) {
            p->b4C3 = (v & 0xF0) | ((v & 0xF) - 1);
        } else {
            p->b4C3 = 0;
        }
    }

    zero = 0.0f;
    p->v4B4.x = 10000.0f;
    p->v4B4.y = zero;
    p->v4B4.z = zero;
    if (p->b4C0 != 0) {
        p->b4C0--;
    }
    v = p->b592;
    if (v != 0) {
        if (v < 120) {
            p->b592 = v + 1;
        } else {
            p->b592 = 0;
        }
    }
}

#pragma opt_propagation reset
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H
/* fzgx:end fn_1_289B4 */

/* fzgx:begin fn_1_28F08 */
/* WARNING: compiler-diff device, not original code: operand/read_pointer helpers keep the
 * products and the v.z reads apart under opt_propagation off (27 words with plain v.z reads) */
static inline f32 fn_1_28F08_operand(f32 left, f32 right) { return left + right; }

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

static inline f32 fn_1_28F08_read_pointer(Vec3 * owner) { return owner->z; }

void fn_1_28F08(ScaleInfo *scale, Vec3 *src, f32 bias)
{
    /* WARNING: compiler-diff device, not original code */
    f32 y;
    Vec3 v;
    Mtx mtx;
    f32 len;

    v.x = src->x;
    v.y = src->y + bias;
    v.z = src->z;

    if (v.x > 3.0f) {
        v.x -= 3.0f;
    } else if (v.x < -3.0f) {
        v.x += 3.0f;
    } else {
        v.x = 0.0f;
    }

    if (fn_1_28F08_read_pointer(&v) > 3.0f) {
        v.z -= 3.0f;
    } else if (fn_1_28F08_read_pointer(&v) < -3.0f) {
        v.z += 3.0f;
    } else {
        v.z = 0.0f;
    }

    v.x = v.x / scale->inv_x;
    y = v.y;
    v.y = y / scale->inv_y;
    v.z = fn_1_28F08_read_pointer(&v) / scale->inv_z;

    y = v.y;
    len = lbl_8006D0B4(fn_1_28F08_operand((v.x * v.x), (y * y)) + fn_1_28F08_read_pointer(&v) * fn_1_28F08_read_pointer(&v));

    fn_8006E7E4(&v, &v, (10430.378f * len));
    lbl_8006DAEC();
    mathutil_mtxA_from_quat(&v);
    lbl_8006DB74((void *)&mtx);
    lbl_8006DB30();
    lbl_8006DFC4((void *)&mtx);
}

#pragma opt_propagation reset
/* fzgx:end fn_1_28F08 */

/* fzgx:begin fn_1_29044 */
/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* Volatile preserves the ordered input stack copy before the call. */

/* WARNING: compiler-diff device, not original code */
static inline void copy_vec(volatile Vec3 *out, f32 z, f32 y, f32 x)
{
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void cross_vec(const Vec3 *a, const Vec3 *b, Vec3 *out)
{
    f32 ax = a->x;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 by = b->y;
    f32 bz = b->z;
    f32 x, y, z;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

void fn_1_29044(Object29044 *self, Vec3 *vec, void *arg2)
{
    Vec3 result;
    Vec3 cross;
    Vec3 input;

    copy_vec(&input, vec->z, vec->y, vec->x);
    fn_8006E2B0(arg2, &result);
    cross_vec(&input, &result, &cross);
    psvec_add(&self->v, &cross, &self->v);
}
#undef GAME_VEC3_H
/* fzgx:end fn_1_29044 */

/* fzgx:begin fn_1_290E8 */
/* the machine-state fields this function touches */

static inline f32 vec_len(Vec3 *p)
{
    f32 x = p->x, y = p->y, z = p->z;
    f32 v1 = x * x;
    v1 = y * y + v1;
    v1 = z * z + v1;
    return lbl_8006D0B4(v1);
}

/* out = a x b; the components are read in this order (y, z of a and b first), as retail loads them */

static inline void cross_vec_290E8(const Vec3 *a, const Vec3 *b, Vec3 *out)
{
    f32 ax, ay, az;
    f32 bx, by, bz;
    f32 x, y, z;

    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    ax = a->x;
    by = b->y;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* Both branches of fn_1_290E8 are inline helpers: their locals get the retail stack homes (ground helper's
 * after the no-ground helper's, the nested fallback's last). In the no-ground branch the axis pointer, set
 * inside the cross call, gives retail's order: &axis2 (addi r4) before &q2, and the cross product's inputs
 * loaded around the 182.04 multiply */

static void stcoli_fallback_axis(Racer290E8 *p, Vec3 *axis)
{
    Vec3 col;
    Vec3 up;

    lbl_8006E1F0((void *)&up, 0.0f, 1.0f, 0.0f);
    if (!(lbl_8006D6FC((void *)&up, (void *)&p->unk_1BC) > 0.0f)) {
        f32 (*cam)[4] = (f32 (*)[4])lbl_801A6D00;
        col.x = cam[0][0];
        col.y = cam[1][0];
        col.z = cam[2][0];
        axis->x = cam[0][2];
        axis->y = cam[1][2];
        axis->z = cam[2][2];
        if (lbl_8006D6FC((void *)&p->unk_1BC, (void *)&col) > 0.0) {
            axis->x = -axis->x;
            axis->y = -axis->y;
            axis->z = -axis->z;
        }
    }
}

static void stcoli_align_to_ground(Racer290E8 *p)
{
    f32 tilt;
    f32 rate;
    f32 len;
    f32 sc[2];
    Vec3 axis;
    Vec3 dir;
    f32 q[4];
    f32 m[12];

    lbl_8006D1B8(182.04444885253906f * p->unk_180, sc);
    lbl_8006E1F0((void *)&dir, 0.0f, sc[1], sc[0]);
    tilt = lbl_8006D6FC((void *)&dir, (void *)&p->unk_1BC);
    if (tilt < 0.9919999837875366f) {
        tilt += 0.00800000037997961f;
        if (p->unk_21C & 0x1800000) {
            rate = 50.0f;
        } else {
            rate = 15.0f;
        }
        cross_vec_290E8(&dir, &p->unk_1BC, &axis);
        len = vec_len(&axis);
        if (len < 0.1f || tilt < 0.00800000037997961f) {
            stcoli_fallback_axis(p, &axis);
        }
        if (tilt < 0.0) {
            tilt = 0.0f;
        } else {
            tilt *= tilt;
        }
        fn_8006E7E4(q, (void *)&axis, 182.04444885253906f * (rate * (1.0f - tilt)));
        lbl_8006DB74(m);
        mathutil_mtxA_from_quat(q);
        lbl_8006DFC4(m);
    }
}

static inline void stcoli_align_to_up(Racer290E8 *p)
{
    Vec3 up2;
    Vec3 axis2;
    f32 q2[4];
    f32 m2[12];
    f32 dot;
    Vec3 *axis_p;

    lbl_8006E1F0((void *)&up2, 0.0f, 1.0f, 0.0f);
    dot = lbl_8006D6FC((void *)&up2, (void *)&p->unk_1BC);
    if (dot < 0.7f) {
        if (dot < 0.0) {
            dot = 0.0f;
        } else {
            dot = dot / 0.7f;
        }
        dot = 1.0f - dot;
        cross_vec_290E8(&up2, &p->unk_1BC, axis_p = &axis2);
        fn_8006E7E4(q2, (void *)axis_p, 182.04444885253906f * (40.0f * dot));
        lbl_8006DB74(m2);
        mathutil_mtxA_from_quat(q2);
        lbl_8006DFC4(m2);
    }
}

void fn_1_290E8(Racer290E8 *p)
{
    f32 mass;
    f32 k;
    Vec3 push;

    mass = p->unk_8;
    k = 1.5f + mass / 4000.0f;
    if (k < 1.8f) {
        k = 3.6 - k;
    } else if (k > 2.0f) {
        k = 2.0f;
    }
    if (p->unk_0 & 2) {
        if (p->unk_1C8 > 0.0f) {
            if (p->unk_0 & 0x200) {
                k *= 1.8f;
            } else {
                k *= 1.3f;
            }
        } else {
            k *= 0.6f;
        }
    } else {
        k *= 1.3f;
    }
    psvec_scale(&p->unk_1BC, 10.0f * -(0.009000000543892384f * mass) * k, &push);
    psvec_add(&p->unk_94, &push, &p->unk_94);

    if (p->unk_0 & 2) {
        stcoli_align_to_ground(p);
        lbl_8006DB74(p->unk_EC);
    } else {
        stcoli_align_to_up(p);
        lbl_8006DB74(p->unk_EC);
    }
}
/* fzgx:end fn_1_290E8 */

/* fzgx:begin fn_1_294D0 */
/* begin game/main_rel/stcoli_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_STCOLI_TYPES_H

// Types (and the externs that name them) of stcoli.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* end game/main_rel/stcoli_types.h */

/* Shared literal pool primer: retail's TU pool (lbl_1_rodata_840) in address order. */

/* Fields of the machine body this drag step touches. */

void fn_1_294D0(fn_1_294D0_Body *p) {
    f32 scale1;
    f32 scale2;
    f32 clamp;
    f32 speed;
    f32 down;
    f32 along;
    f32 t;
    f32 sum;
    Vec3 push;
    Vec3 drag;
    Vec3 dir;

    sum = p->vel.y;
    t = p->vel.x * p->vel.x;
    t = __fmadds(sum, sum, t);
    t = __fmadds(p->vel.z, p->vel.z, t);
    speed = lbl_8006D0B4(t) / p->mass;
    if (216.0 * speed < 2.0) {
        p->vel.x = 0.0f;
        p->vel.y = 0.0f;
        p->vel.z = 0.0f;
        p->drag = 0.0f;
        return;
    }
    if (216.0 * speed > 9990.0) {
        lbl_8006D5F0((void *)&p->vel, (void *)&p->vel, 46.25f);
        return;
    }

    along = lbl_8006D6FC(&p->normal, &p->vel);
    lbl_8006E1F0(&dir, 0.0f, 0.0f, -1.0f);
    down = lbl_8006D6FC(&p->normal, &dir);
    scale1 = p->mass * (along * speed);
    speed = speed * (8.0f * speed);
    psvec_scale(&p->normal, scale1, &drag);
    psvec_sub(&p->vel, &drag, &push);

    if (p->flags & 2) {
        if (down < 0.0f) {
            down = 1.0f + down;
            if (down < 0.0f) {
                down = 0.0f;
            }
            speed *= down;
        } else {
            down += 1.0f;
        }
    }
    lbl_8006D5F0((void *)&push, (void *)&push, speed);
    p->drag = speed;

    if (p->mass < 1100.0f) {
        t = p->mass / 1100.0f;
        along *= t * t;
    }

    if (!(p->flags & 0x20) && (p->flags & 2)) {
        if (along < 0.0f && down > 0.8f) {
            along *= 0.6f + (f32)(4.0f * (down - 0.8f));
        } else {
            along *= 0.6f;
        }
    } else if (p->flags & 0x20) {
        along *= 0.5f;
    } else {
        along *= 0.6f;
    }

    scale2 = speed * along;
    psvec_scale(&p->normal, scale2, &drag);
    psvec_add(&drag, &push, &push);

    if (p->boostTimer != 0) {
        t = 0.01f * (p->boostTimer - 4.0f);
        if (t < 0.0f) {
            clamp = 0.0f;
        } else if (t > 1.0f) {
            clamp = 1.0f;
        } else {
            clamp = t;
        }
        psvec_scale(&push, clamp, &push);
    }
    psvec_sub(&p->vel, &push, &p->vel);
}
/* fzgx:end fn_1_294D0 */

/* fzgx:begin fn_1_29800 */
void fn_1_29800(struct S *p) {
    s32 v0 = 0;
    f32 f4;
    f32 t;
    if (p->b481 > 60 && (p->flags & 2) != 0) {
        v0 = 1;
    }
    if (v0 != 0) {
        f4 = 2.0 * __fabs(p->f1FC);
        if ((p->f58C & 2) != 0) {
            f4 = 0.0f;
        }
        if (f4 < 0.1f) {
            f32 q = 4.0f * p->f1F4;
            f4 = f4 + q;
        } else {
            f32 two = 2.0f;
            f32 m = two * p->f1F4;
            f64 pr = m * __fabs(two - f4);
            f4 = f4 + pr;
            if ((p->flags & 0x20) != 0 && (p->flags & 0x200000) == 0) {
                f4 = f4 * two;
            }
        }
        if (p->b483 > 60) {
            t = (p->b483 - 60) / 120.0f;
            if (t > 1.0f) {
                t = 1.0f;
            }
            f4 = f4 * (1.0f + (t = 0.3f * t));
            f4 = f4 + t;
        }
        if ((p->f21C & 0x1800000) != 0) {
            f32 k = 0.3f;
            f4 = f4 * k;
        }
        p->f180 = p->f180 + f4;
        {
            f32 v = p->f180;
            if (v < -50.0f) {
                p->f180 = -50.0f;
            } else if (v > 60.0f) {
                p->f180 = 60.0f;
            }
        }
    } else {
        p->f180 = 0.0f;
    }
}
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H
/* fzgx:end fn_1_29800 */

/* fzgx:begin fn_1_29968 */
/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off
void fn_1_29968(Sig_fn_1_29968_Owner *self)
{
    f32 v;
    f32 scale;
    f32 step;
    f32 t;

    lbl_8006DAEC();
    t = self->unk_30C;
    t = t / -self->unk_254;
    v = t - 1.0f;
    scale = 182.04445f;
    step = 30.0f;
    mathutil_mtxA_rotate_x((s32)(scale * (step * ((v < -0.2f) ? -0.2f : ((v > 0.2f) ? 0.2f : v)))));
    lbl_8006DB74((void *)&self->unk_5E0);
    lbl_8006DB30();
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_29968 */

/* fzgx:begin fn_1_29A0C */
#define GAME_VEC3_H

#define LC ((f32 *)LC_BASE)

#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

/* the same-TU fn_1_29968, which retail inlines here */

static inline void fn_1_29A0C_present(Machine *m)
{
    f32 v;

    lbl_8006DAEC();
    v = m->unk_30C / -m->unk_254;
    v = CLAMP(v - 1.0f, -0.2f, 0.2f);
    mathutil_mtxA_rotate_x((182.04444885253906f * (30.0f * v)));
    lbl_8006DB74(&m->unk_5E0);
    lbl_8006DB30();
}

static inline f32 fn_1_29A0C_length(Vec3 *p)
{
    f32 x = p->x, y = p->y, z = p->z;
    f32 v1 = x * x;
    v1 = y * y + v1;
    v1 = z * z + v1;
    return lbl_8006D0B4(v1);
}

/* retail's in-place fmadds translate (x = x * lift + LC[3] in one register) needs opt_lifetimes off */

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

void fn_1_29A0C(Machine *m)
{
    Mtx34 mtx;
    Vec3 pos;
    Quat_29A0C q;
    Vec3 jitter;
    f32 a;
    f32 t;
    f32 sway;
    f32 bounce;
    f32 speed;
    f32 scale;
    f32 pitch;
    f32 grip;
    f32 amp;
    s32 angle;
    u32 hash;
    s16 index;

    if (m->unk_224 > 2.0f) {
        sway = 0.0f;
    } else {
        sway = (2.0f - m->unk_224) / 2.0f;
    }
    if (m->unk_481 < 90) {
        sway *= m->unk_481 / 90.0f;
    }
    m->unk_5D4 = m->unk_5D4 + (f32)(0.05f * (sway - m->unk_5D4));
    a = m->unk_5D4;
    t = (s16)(182.04444885253906f * (0.5f * (a * lbl_8006D188((lbl_801A66A0 * 0x109)))));
    bounce = 0.006f * (a * lbl_8006D188((lbl_801A66A0 * 0x1A3)));
    if (m->unk_481 < 90 && m->unk_6 > 40) {
        bounce = bounce + (f32)(0.5f * (1.0f - m->unk_481 / 90.0f));
    }
    lbl_8006E1F0((void *)&pos, 0.0f, bounce - (f32)(0.2f * a), 0.0f);
    psvec_add(&pos, &m->unk_7C, &pos);
    lbl_8006DA50();
    LC[3] = 0.0f;
    LC[7] = 0.0f;
    LC[11] = 0.0f;
    lbl_8006DB74(&m->unk_EC);
    fn_1_29A0C_present(m);
    mathutil_mtxA_rotate_z((10430.3779296875f * (m->unk_4EC / m->unk_B4)));
    mathutil_mtxA_rotate_y((10430.3779296875f * (m->unk_4E8 / m->unk_B0)));
    mathutil_mtxA_rotate_x((10430.3779296875f * (m->unk_4E4 / m->unk_AC)));
    lbl_8006DAEC();
    if (m->unk_58C & 0x20) {
        lbl_8006DBAC(&m->unk_14C);
    } else {
        lbl_8006DAEC();
        lbl_8006D758();
        if (m->unk_0 & 0x400) {
            m->unk_4D8 = m->unk_4D8 + (f32)(0.05f * (m->unk_4D4 - m->unk_4D8));
            mathutil_mtxA_rotate_y((182.04444885253906f * m->unk_4D8));
        }
        speed = fn_1_29A0C_length(&m->unk_94) / m->unk_8 / 4.62962962962963;
        scale = m->unk_1C / 15.0f;
        m->unk_4B0 = 182.04444885253906f * (scale * (-5.0f * m->unk_1F0 * speed));
        angle = (s16)(10430.3779296875f * (speed * (4.5f * (m->unk_A4 / m->unk_B0))));
        angle += m->unk_4B0;
        grip = 1.0f - __abs(angle) / 3640.0f;
        if (grip < 0.0f) {
            grip = 0.0f;
        }
        pitch = grip * (0.7f * (m->unk_C8 / m->unk_AC));
        a = 2.5f * (m->unk_C4 / m->unk_B4);
        if (pitch > 0.3f) {
            pitch = 0.3f;
        } else if (pitch < -0.3f) {
            pitch = -0.3f;
        }
        if (a > 0.5f) {
            a = 0.5f;
        } else if (a < -0.5f) {
            a = -0.5f;
        }
        mathutil_mtxA_rotate_x((10430.3779296875f * pitch));
        angle += (s16)(10430.3779296875f * -a);
        if (angle > 0x238E) {
            angle = 0x238E;
        } else if (angle < -0x238E) {
            angle = -0x238E;
        }
        mathutil_mtxA_rotate_z((angle + t));
        fn_8006E5FC(&q);
        fn_8006EB4C(&m->unk_5C4, &m->unk_5C4, &q, 0.2f);
        mathutil_mtxA_from_quat((void *)&m->unk_5C4);
        lbl_8006DB74(&mtx);
        lbl_8006DB30();
        lbl_8006DFC4(&mtx);
        if (m->unk_190 != 0) {
            if (m->unk_196 != 0) {
                mathutil_mtxA_rotate_y((s16)-m->unk_190);
            } else {
                mathutil_mtxA_rotate_y((s16)m->unk_190);
            }
        }
    }
    /* the locked-cache matrix (LC_BASE) gets the position as its translation */
    mathutil_mtxA_set_translate(&pos);
    amp = 5.999999848427251e-05f * m->unk_478;
    hash = (*(u32 *)(&m->unk_94.z)) ^ ((*(u32 *)(&m->unk_94.x)) ^ (*(u32 *)(&m->unk_94.y)));
    t = amp * ((u16)(hash ^ m->unk_A0) / 65536.0f);
    mathutil_mtxA_rotate_z((10430.3779296875f * (amp * ((u16)(hash ^ (*(u32 *)(&m->unk_A4))) / 65536.0f))));
    mathutil_mtxA_rotate_x((10430.3779296875f * t));
    if (m->unk_0 & 0x20) {
        f32 w = m->unk_C8;
        if (w < 0.0f) {
            w = 0.0f;
        }
        m->unk_18C = m->unk_18C + (f32)(0.2f * ((f32)(4.5f * (w / m->unk_AC)) - m->unk_18C));
        if (m->unk_18C > 0.3f) {
            m->unk_18C = 0.3f;
        }
    } else {
        m->unk_18C = m->unk_18C - (f32)(0.05f * m->unk_18C);
    }
    /* and is raised along its y column by M+0x18C */
    {
        f32 z;
        f32 y;
        f32 x;
        f32 lift;
        x = LC[1];
        y = LC[5];
        z = LC[9];
        lift = m->unk_18C;
        x = x * lift + LC[3];
        y = y * lift + LC[7];
        z = z * lift + LC[11];
        LC[3] = x;
        LC[7] = y;
        LC[11] = z;
    }
    if ((m->unk_218 >> 29) & 1) {
        t = 0.1f + m->unk_17C / 900.0f;
        if (t > 1.0f) {
            t = 1.0f;
        }
        jitter.x = (u16)(hash ^ (*(u32 *)(&m->unk_A4))) / 65536.0f - 0.5f;
        jitter.y = 0.0f;
        jitter.z = (u16)(hash ^ m->unk_A8) / 65536.0f - 0.5f;
        lbl_8006E1C0((void *)&jitter, (void *)&jitter);
        psvec_scale(&jitter, 0.15f * t, &jitter);
        lbl_8006E0A4(&jitter);
    }
    if (((Other *)fn_1_868C0(m->unk_4))->unk_390 & 0x100000) {
        index = m->unk_6;
        lbl_8006E14C(index >= 2 ? 1.0f : lbl_1_rodata_3508[index * 2]);
    }
    lbl_8006DB74(&m->unk_14C);
    lbl_8006DB30();
}

#pragma opt_lifetimes reset
#undef GAME_VEC3_H
#undef LC
#undef CLAMP
/* fzgx:end fn_1_29A0C */

/* fzgx:begin fn_1_2A214 */
void fn_1_2A214(StColiObj *obj)
{
    float limit;

    if (obj->flags & 2) {
        float k0 = (0.899999976f);
        float k1 = (0.99000001f);
        obj->a0 = obj->a0 * k0;
        obj->a8 = obj->a8 * k1;
        limit = obj->b0;
    } else if (obj->flags & 0x10) {
        limit = (0.200000003f) * obj->b0;
    } else {
        limit = (0.0500000007f) * obj->b0;
    }
    if (__fabs(obj->a4) > limit) {
        if (obj->a4 < (0.0f)) {
            obj->a4 = -limit;
        } else {
            obj->a4 = limit;
        }
    }
}
/* fzgx:end fn_1_2A214 */

/* fzgx:begin fn_1_2A2A4 */
void fn_1_2A2A4(Fn1_2A2A4Object *self) {
    u8 local_14[12];
    u8 local_8[12];
    f32 value_1;
    f32 value_2;

    value_1 = 0.0f;
    value_2 = 1.0f;
    lbl_8006E1F0(local_8, value_1, value_2, value_1);
    lbl_8006DAEC();
    fn_8006E978( (void *)((f32 *)(local_14)), (void *)((Vec3 *)(local_8)), (void *)((Vec3 *)(self->pad_1bc)));
    mathutil_mtxA_from_quat(local_14);
    lbl_8006DFC4(self->field_ec);
    lbl_8006DB74(self->field_ec);
    lbl_8006DB30();
}
/* fzgx:end fn_1_2A2A4 */

/* fzgx:begin fn_1_2A318 */
void fn_1_2A318(Fn_1_2A318 *self) {
    u16 value;
    f32 progress;

    self->field482++;
    self->field212++;
    self->field210 += self->field212 * (self->field18a ? 15 : 10);
    if (self->field592 == 0) {
        self->field592 = 1;
    }
    value = self->field5da;
    progress = self->field184;
    if (progress < value) {
        progress += 6.6666665f;
        self->field184 = progress;
        if (progress > value) {
            self->field184 = self->field5da;
        }
    }
}
/* fzgx:end fn_1_2A318 */

/* fzgx:begin fn_1_2A3E4 */
void fn_1_2A3E4(Sig_fn_1_2A3E4_Fn_1_2A3E4 *self) {
    if (self->active != 0) {
        if (self->flags & 0x00200000) {
            self->value210 += 0x14;
        } else {
            self->value210 += 0xA;
        }
    }
}
/* fzgx:end fn_1_2A3E4 */

/* fzgx:begin fn_1_2A41C */
f32 fn_1_2A41C(Fn_1_2A41C *self, int arg) {
    f32 result;
    u32 flags;
    f32 delta;
    f32 half;
    f32 scaled;
    f32 t;

    flags = self->flags;
    result = 1.0f;
    if ((flags & 0x20008) != 0) {
        if ((flags & 0x200) != 0) {
            if ((flags & 8) != 0) {
                result *= 3.5f;
            } else {
                result *= 4.0f;
            }
        } else {
            delta = self->value194;
            delta *= 0.000244140625f;
            half = 0.5f;
            scaled = half * delta;
            t = half + scaled;
            if (arg != 0) {
                if ((flags & 8) != 0) {
                    result *= 5.0f * t;
                } else {
                    result *= 6.0f;
                }
            } else {
                if ((flags & 8) != 0) {
                    result *= 3.0f * t;
                } else {
                    result *= 2.0f;
                }
            }
        }
    } else {
        if ((flags & 0x200) != 0) {
            result *= 0.8f;
        }
    }
    return result;
}
/* fzgx:end fn_1_2A41C */

/* fzgx:begin fn_1_2A500 */
/* result block passed to the helper; the helper fills scale and vec */

s32 fn_1_2A500(void *self, Vec3 *out, Vec3 *pos, void *a, void *b, f32 *outF)
{
    void *mgr = (void *)fn_1_8627C(*(s16 *)((u8 *)self + 4));
    Vec3 v;
    f32 scale;
    s32 found_2;
    s32 found;
    f32 f;

    lbl_8006DAEC();

    v = *out;
    found = fn_1_15578(&v, pos, &scale, a, (u32)b, (s32 *)((u8 *)mgr + 0x9C), *(s32 *)((u8 *)mgr + 0x98), 0,
                       *(s32 *)((u8 *)self + 0x498), self);

    if (found != 0) {
        f32 dz = out->z;
        f32 dy = out->y;
        f32 dx = out->x;
        f32 d;

        dz = dz - pos->z;
        dy = dy - pos->y;
        dx = dx - pos->x;
        d = (dx * dx);
        d = d + dy * dy;
        d = d + dz * dz;

        f = (1.0f - scale) * lbl_8006D0B4(d);

        *out = v;
        found_2 = 1;
    } else {
        f = 0.0f;
        found_2 = 0;
    }

    lbl_8006DB30();
    *outF = f;
    return found_2;
}
/* fzgx:end fn_1_2A500 */

/* fzgx:begin fn_1_2A638 */
void fn_1_2A638(void *arg0, Fn_1_2A638 *self) {
    lbl_8006E1D8((void *)((char *)self + 0x14), self->field08,
        self->field0c + self->field44 - self->field48, self->field10);
}
/* fzgx:end fn_1_2A638 */

/* fzgx:begin fn_1_2A678 */
void fn_1_2A678(Fn_1_2A678_Source *self, Fn_1_2A678_Dest *dest) {
    dest->values = self->values;
}
/* fzgx:end fn_1_2A678 */

/* fzgx:begin fn_1_2A694 */
int fn_1_2A694(O *self, void *arg1, Vec3 *swap, u32 mask, Vec3 *out0, Vec3 *out1) {
 Vec3 local; f32 work[4]; R *result; int status; int actor;
 if ((self->flags&2)==0) mask&=0xfffff8ff;
 { psvec_set(&local.x, *(const f32 *)(LC_BASE + 0x2C), *(const f32 *)(LC_BASE + 0x1C), *(const f32 *)(LC_BASE + 0xC)); } lbl_8006DAEC();
 status=((int)fn_1_15578((void *)&local,(void *)arg1,(void *)&work[0],(void *)&work[1],mask,(void *)&self->field49c->v9c,(s32)((void *)self->field49c->v98),(s32)swap,self->field498,(void *)self)); lbl_8006DB30();
 if(((0) != swap)){u32 t=*(u32 *)swap;*(u32 *)swap=*(((1) + ((u32 *)swap)));*(((1) + ((u32 *)swap)))=t;}
 if(status!=0){result=(R *)((void *)fn_1_14F04()); if(result->flags160==0x100){self->flags|=0x800;status=0;}else{
  *(P *)out0=*(P *)&result->v180;*(u32 *)((u8 *)out0+8)=result->v188; *(P *)out1=*(P *)&local;*(u32 *)((u8 *)out1+8)=*(u32 *)&local.z;
  if((result->flags160&0x600)!=0){actor=((int)fn_1_868C0(self->id));if((self->field58c&0x10)==0){if((s8)self->v474!=-1)fn_1_F7338((s8)self->v474,(void *)2,(void *)30);
   self->flags|=0x800;self->flags|=0x80;self->flags|=0x00800000;self->flags|=0x40000000;self->field58c|=0x10;
   *(f32 *)((u8 *)self+0x184)=0.0f;*(f32 *)((u8 *)self+0x224)=0.0f;
   *(f32 *)((u8 *)self+0x94)=0.0f;*(f32 *)((u8 *)self+0x98)=0.0f;*(f32 *)((u8 *)self+0x9c)=0.0f;*(f32 *)((u8 *)self+0xa0)=0.0f;*(f32 *)((u8 *)self+0xa4)=0.0f;*(f32 *)((u8 *)self+0xa8)=0.0f;*(f32 *)((u8 *)self+0x17c)=0.0f;
   self->field58c&=~0x80;*(u32 *)(actor+0x390)&=~0x200000;*(u32 *)(actor+0x390)|=0x01000000;}} if((result->flags160&0x100)!=0)self->flags|=0x800;}}
 if(status==0){f32 z=0.0f;out0->x=z;out0->y=z;out0->z=z;out1->x=z;out1->y=z;out1->z=z;} return status;
}
/* fzgx:end fn_1_2A694 */

/* fzgx:begin fn_1_2A8D0 */
int fn_1_2A8D0(Sig_fn_1_2A694_O_2A8D0 * arg0, u8 * arg1, u32 * arg2, u32 arg3, Vec3 * arg4, u32 * arg5, u32 * arg6, u32 arg7) {
    u32 loc_20[3];
    struct fn_1_2A8D0_Copy12 loc_14;
    u32 loc_10;
    u32 v1;
    u32 v3;
    int v2;
    u8 * t4;
    u8 * t5;
    Sig_fn_1_2A694_N *v0;

    lbl_8006E1B0(arg1, arg1 + 24);
    lbl_8006DAEC();
    loc_14 = *(struct fn_1_2A8D0_Copy12 *)(arg1 + 24);
    v0 = arg0->field49c;
    v2 = ((int)fn_1_15578((void *)&loc_14, (void *)(arg1 + 12), (void *)&loc_10, (void *)loc_20, (u32)arg3, (void *)&v0->v9c, (s32)v0->v98, (s32)arg2, (s32)arg0->field498, (void *)arg0));
    lbl_8006DB30();
    if (arg2 != 0) {
        v1 = arg2[0];
        arg2[0] = arg2[1];
        arg2[1] = v1;
    }
    arg4[0].x = 0.0f;
    arg4[0].y = 0.0f;
    arg4[0].z = 0.0f;
    arg4[1].x = 0.0f;
    arg4[1].y = 0.0f;
    arg4[1].z = 0.0f;
    arg4[2].x = 0.0f;
    arg4[2].y = 0.0f;
    arg4[2].z = 0.0f;
    arg4[3].x = 0.0f;
    arg4[3].y = 0.0f;
    arg4[3].z = 0.0f;
    arg5[3] = 0;
    arg5[2] = 0;
    arg5[1] = 0;
    arg5[0] = 0;
    if (v2 != 0) {
        t4 = fn_1_14F04();
        if (*(u32 *)(t4 + 208) != 0) {
            *(struct fn_1_2A8D0_Copy12 *)&arg4[0] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 240);
            arg5[0] = *(u32 *)(t4 + 264);
            arg6[0] |= arg7;
        }
        if (*(u32 *)(t4 + 136) != 0) {
            *(struct fn_1_2A8D0_Copy12 *)&arg4[1] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 168);
            arg5[1] = *(u32 *)(t4 + 192);
            arg6[1] |= arg7;
        }
        v3 = *(u32 *)(t4 + 352);
        if (v3 != 0) {
            if (v3 & 0x100) {
                arg0->flags |= 0x800;
                v2 = 0;
            } else if (v3 & 0x600) {
                *(struct fn_1_2A8D0_Copy12 *)&arg4[2] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 384);
                t5 = fn_1_868C0(arg0->id);
                if (!(arg0->field58c & 0x10)) {
                    if (arg0->v474 != -1) {
                        fn_1_F7338(arg0->v474, (void *)(2), (void *)(30));
                    }
                    arg0->flags |= 0x800;
                    arg0->flags |= 0x80;
                    arg0->flags |= 0x800000;
                    arg0->flags |= 0x40000000;
                    arg0->field58c |= 0x10;
                    *(f32 *)((u8 *)arg0 + 388) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 548) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 148) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 152) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 156) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 160) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 164) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 168) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 380) = 0.0f;
                    arg0->field58c &= ~0x80;
                    *(u32 *)(t5 + 912) &= ~0x200000;
                    *(u32 *)(t5 + 912) |= 0x1000000;
                }
            } else {
                *(struct fn_1_2A8D0_Copy12 *)&arg4[2] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 384);
            }
            arg6[2] |= arg7;
        }
        if (*(u32 *)(t4 + 64) != 0) {
            *(struct fn_1_2A8D0_Copy12 *)&arg4[3] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 96);
            arg5[3] = *(u32 *)(t4 + 120);
            arg6[3] |= arg7;
        }
    }
    return v2;
}
/* fzgx:end fn_1_2A8D0 */

/* fzgx:begin fn_1_2ABD4 */
/* Machine body fields read by the wheel suspension step. */

static inline void fn_1_2ABD4_set(Vec3 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline f32 fn_1_2ABD4_distance(Vec3 *a, Vec3 *b) {
    f32 t;
    f32 dy;
    f32 dz;
    t = a->x;
    t -= b->x;
    dy = a->y;
    dy -= b->y;
    dz = a->z;
    dz -= b->z;
    t = t * t;
    t = dy * dy + t;
    t = dz * dz + t;
    return lbl_8006D0B4(t);
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

void fn_1_2ABD4(fn_1_2ABD4_Body *body, fn_1_2ABD4_Wheel *wheel) {
    f32 one;
    f32 k;
    f32 limit;
    f32 dist;
    f32 prev;
    f32 len;
    f32 rate;
    f32 dx, dy, dz;
    fn_1_2ABD4_Node *node;
    int hit;
    u32 flags;
    f32 frac;
    Vec3 end;
    Vec3 start;

    limit = (0.100000001f) + body->b481 / (90.0f);
    if (limit > (0.5f)) {
        limit = (0.5f);
    }
    limit *= (2.0f) * wheel->length;

    lbl_8006E1B0(&wheel->pos, &end);
    lbl_8006E1D8((void *)&wheel->contact, wheel->pos.x, wheel->pos.y - (2000.0f), wheel->pos.z);

    flags = wheel->flags;
    if ((flags & 0x20) || (body->f1C8 <= (0.0f) && (flags & 2))) {
        wheel->flags |= 8;
        len = (0.0f);
    } else {
        node = ((void *)fn_1_8627C(body->id));
        lbl_8006DAEC();
        start = wheel->contact;
        if (((int)fn_1_15578((void *)&start, (void *)&end, (void *)&frac, (void *)&wheel->hitNormal, 0x60005, (void *)&node->v9c,
                       (s32)((void *)node->v98), (s32)0, body->f498, (void *)body)) != 0) {
            dist = fn_1_2ABD4_distance(&wheel->contact, &end);
            dist = ((1.0f) - frac) * dist;
            hit = 1;
            wheel->contact = start;
        } else {
            dist = (0.0f);
            hit = 0;
        }
        lbl_8006DB30();
        if (hit) {
            wheel->flags &= ~8;
            len = (dist - (2000.0f)) + limit;
        } else {
            wheel->flags |= 8;
            len = (0.0f);
        }
    }

    if (len <= (0.0f)) {
        wheel->flags |= 2;
        wheel->compression = (0.0f);
        k = (0.0f);
        one = (1.0f);
        fn_1_2ABD4_set(&wheel->normal, (0.0f), one, (0.0f));
        if (wheel->flags & 8) {
            fn_1_2ABD4_set(&wheel->hitNormal, (0.0f), one, (0.0f));
        }
    } else {
        wheel->flags &= ~2;
        if (len > limit) {
            prev = (0.5f) * (len - wheel->compression);
            k = prev * body->mass;
            len = limit;
        } else {
            k = (0.0f);
        }
        rate = body->mass / (1200.0f);
        k += (f32)((0.00900000054f) * ((9000.0f) * len) * rate);
        k -= (f32)(rate * ((10000.0f) * ((0.00900000054f) * (wheel->compression - len))));
        wheel->compression = len;
        wheel->normal = wheel->hitNormal;
    }
    wheel->forceMag = k;
    psvec_scale(&wheel->normal, k, &wheel->force);
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2ABD4 */

/* fzgx:begin fn_1_2AF0C */
/* One hover corner: 4 x 0x5C at machine +0x244 (front right, front left, back right, back left). */

/* Corner indices a, b, c, d: the normal is (a - b) x (c - d). */

/* One quad per set of corners probed: all four, then three with corner 0, 1, 2 or 3 missing. */

static inline void hover_cross(const Vec3 *a, const Vec3 *b, Vec3 *out) {
    f32 ax, ay, az, bx, by, bz;
    f32 x, y, z;
    ay = a->y;
    ax = a->x;
    az = a->z;
    by = b->y;
    bx = b->x;
    bz = b->z;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off
s32 fn_1_2AF0C(HoverMachine *racer, Vec3 *normal) {
    CornerQuads quads = {{{2, 1, 0, 3}, {2, 3, 1, 3}, {0, 2, 3, 2}, {3, 1, 0, 1}, {1, 0, 2, 0}}};
    u8 entry[4];
    Vec3 up;
    Vec3 edge;
    f32 len;
    f32 zero;
    f32 one;
    /* WARNING: compiler-diff device, not original code */
    struct { s32 value; } modulated;
    s32 result;
    s32 i;
    s32 strip_hits;
    HoverCorner *c;
    u32 airborne;
    u32 probed;
    CornerQuad *quad;
    u8 no_static;
    u8 *area;
    u32 flags;
    u32 bit;

    result = 0;
    no_static = 0;
    /* courses 36 and 37: the modulated roads */
    modulated.value = 1;
    if (fn_1_7B054() != 36 && fn_1_7B054() != 37) {
        modulated.value = 0;
    }
    probed = 0;
    airborne = 0;
    quad = NULL;
    strip_hits = 0;
    for (i = 0, c = racer->unk_244; i < 4; i++, c++) {
        entry[i] = 4;
        /* the pointer the modulated-road shape function reads */
        *(void **)(fn_1_14F04() + 0x700) = racer->unk_488[i];
        fn_1_2ABD4((void *)racer, (void *)c);
        if (!(c->unk_0 & 2) || (modulated.value && !(c->unk_0 & 8) && racer->unk_1C8 > 0.0f)) {
            area = fn_1_14F04();
            /* slot 4 of the query area holds no hit: the probe met no static collision */
            if (lbl_801A66CC->hits[4].flags == 0) {
                no_static++;
            }
            flags = *(u32 *)(area + 0x118);
            if (flags & 0xC00) {
                strip_hits++;
            } else if (flags & 0x3E00000) {
                entry[i] = *(u32 *)(area + 0x10C);
            }
            bit = 1 << i;
            probed |= bit;
            if (!(c->unk_0 & 2)) {
                airborne |= bit;
            }
        }
    }
    /* course 15 (Cylinder Knot): contact is forced when every probe without ground hit static collision */
    if (airborne != 0 && no_static == 0 && fn_1_7B054() == 15) {
        airborne = 0;
        zero = 0.0f;
        one = 1.0f;
        for (i = 0; i < 4; i++) {
            c = &racer->unk_244[i];
            c->unk_0 |= 0xA;
            c->unk_58 = zero;
            c->unk_44 = zero;
            c->unk_2C.x = zero;
            c->unk_2C.y = one;
            c->unk_2C.z = zero;
            c->unk_38.x = zero;
            c->unk_38.y = one;
            c->unk_38.z = zero;
            c->unk_4C.x = zero;
            c->unk_4C.y = zero;
            c->unk_4C.z = zero;
        }
    }
    if (entry[0] == entry[1] && entry[1] == entry[2] && entry[2] == entry[3]) {
        racer->unk_50C = entry[0];
    }
    if (airborne == 15) {
        quad = &quads.unk_0[0];
    } else if (airborne == 14) {
        quad = &quads.unk_0[1];
    } else if (airborne == 13) {
        quad = &quads.unk_0[2];
    } else if (airborne == 11) {
        quad = &quads.unk_0[3];
    } else if (airborne == 7) {
        quad = &quads.unk_0[4];
    } else if (modulated.value) {
        if (probed == 15) {
            quad = &quads.unk_0[0];
        } else if (probed == 14) {
            quad = &quads.unk_0[1];
        } else if (probed == 13) {
            quad = &quads.unk_0[2];
        } else if (probed == 11) {
            quad = &quads.unk_0[3];
        } else if (probed == 7) {
            quad = &quads.unk_0[4];
        }
    }
    if (quad != NULL) {
        psvec_sub(&racer->unk_244[quad->unk_0[0]].unk_20, &racer->unk_244[quad->unk_0[1]].unk_20, &up);
        psvec_sub(&racer->unk_244[quad->unk_0[2]].unk_20, &racer->unk_244[quad->unk_0[3]].unk_20, &edge);
        hover_cross(&up, &edge, &up);
        len = lbl_8006D668(&up);
        if ((*(u32 *)&len & 0x7F800000) != 0x7F800000) {
            for (i = 0, c = racer->unk_244; i < 4; i++, c++) {
                result = 1;
                c->unk_38 = up;
                *normal = c->unk_38;
                if (!(c->unk_0 & 8)) {
                    c->unk_2C = up;
                    psvec_scale(&c->unk_2C, c->unk_58, &c->unk_4C);
                }
            }
        }
        if (strip_hits >= 3) {
            racer->unk_218 |= 0x2000000;
            racer->unk_58C |= 0x200;
        }
    }
    return result;
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2AF0C */

/* fzgx:begin fn_1_2B478 */
f32 fn_1_2B478(void *arg0) {
    void *temp_r5;

    temp_r5 = (*(void **)((u8 *)(arg0) + 1180));
    if (!((*(s32 *)((u8 *)(temp_r5) + 124)) & 0x01800000) || ((*(f32 *)((u8 *)(arg0) + 456)) <= 0.0f)) {
        return (1.0f);
    }
    lbl_801A66CC->delta.x = -lbl_801A6D00[2];
    lbl_801A66CC->delta.y = -lbl_801A6D00[6];
    lbl_801A66CC->delta.z = -lbl_801A6D00[10];
    return lbl_8006D6FC(&lbl_801A66CC->delta, ((u8 *)(temp_r5) + 0x50));
}
/* fzgx:end fn_1_2B478 */

/* fzgx:begin fn_1_2B524 */
static inline f32 fn_1_2B524_add(f32 a, f32 b) {
    return a + b;
}

static inline void fn_1_2B524_cross(const Vec3 *a, const Vec3 *b, Vec3 *out) {
    f32 ax, ay, az, bx, bz, by;
    f32 x, y, z;
    ax = a->x;
    ay = a->y;
    az = a->z;
    bx = b->x;
    bz = b->z;
    by = b->y;
    x = ay * bz;
    x = x - az * by;
    y = (f32)(az * bx) - ax * bz;
    z = (f32)(ax * by) - ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

void fn_1_2B524(Fn2B524_Self *self) {
    /* WARNING: compiler-diff device, not original code */
    f32 *z_ptr;
    u32 h;
    u32 a, b;
    f32 fb, fa;
    f32 mtx[3];
    Vec3 v;
    Vec3 r;
    Vec3 w;

    a = self->h0 ^ self->h1;
    h = self->h2 ^ a;
    h = h ^ self->h3;
    a = (h ^ *(u32 *)&self->vel.x) & 0xFFFF;
    b = (h ^ *(u32 *)&self->vel.y) & 0xFFFF;
    fa = (f32)(2.0f * (a / 65536.0f)) - 1.0f;
    fb = 0.5f + (f32)(1.5f * (b / 65536.0f));
    if (fa > 0.0f) {
        v.x = fn_1_2B524_add(fa, 0.5f);
    } else {
        v.x = fa - 0.5f;
    }
    mtx[0] = 0.0f;
    mtx[1] = 0.016203703703703703 * self->ang;
    mtx[2] = 0.0f;
    v.y = 0.0f;
    z_ptr = &v.z;
    *z_ptr = fb;
    fn_8006E2B0(mtx, (void *)&w);
    fn_1_2B524_cross(&v, &w, &r);
    psvec_add(&self->vel.x, &r.x, &self->vel.x);
}
/* fzgx:end fn_1_2B524 */

/* fzgx:begin fn_1_2B684 */
#define GAME_MAIN_REL_STCOLI_TYPES_H

#define GAME_VEC3_H

static inline void fn_1_2B684_cross(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 ax = a->x, ay = a->y, bz = b->z;
    f32 az = a->z, bx = b->x, by = b->y;
    f32 x = ay * bz;
    f32 y = az * bx;
    f32 z;
    y -= ax * bz;
    x -= az * by;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 fn_1_2B684_clamp(f32 t) {
    if (t < 0.0f) return 0.0f;
    if (t > 1.0f) return 1.0f;
    return t;
}

static inline f32 fn_1_2B684_square(f32 t) {
    if (t < 0.0) return 0.0f;
    return t * t;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_2B684(Fn2B684Obj *obj) {
    f32 dirv[3];
#define dir (*(Vec3 *)dirv)
    Vec3 push;
    Vec3 spin;
    Vec3 torque;
    Vec3 up;
    Vec3 axis;
    Quat q;
    u32 hash;
    f32 t;
    f32 k;
    f32 scale;
    f32 dot;
    f32 top;
    f32 sq;

    hash = obj->seed7C ^ obj->seed80 ^ obj->seed84;
    dir.x = (f32)(2.0f * (((hash ^ *(u32 *)&obj->posA0.x) & 0xFFFF) / 65536.0f)) - 1.0f;
    dir.y = 0.0f;
    dir.z = (f32)(2.0f * (((hash ^ *(u32 *)&obj->posA0.y) & 0xFFFF) / 65536.0f)) - 1.0f;
    t = dir.x;
    if (t > 0.0f) {
        t += 0.5f;
    } else {
        t -= 0.5f;
    }
    dir.x = t;
    if (dir.z > 0.0f) {
        dir.z += 0.5f;
    } else {
        dir.z -= 0.5f;
    }

    t = (f32)(0.0015f * obj->f17C) - 1.0f;
    k = fn_1_2B684_clamp(t);
    top = 450.0f;
    scale = k * (top / 216.0);

    lbl_8006E1F0((void *)&push, -dir.x, 0.5f, -dir.z);
    psvec_scale(&push, scale * obj->mass, &push);
    obj->flags |= 2;
    fn_8006E2B0(&push, (void *)&spin);
    psvec_scale(&spin, 0.5f, &spin);
    fn_1_2B684_cross(&dir, &spin, &torque);
    psvec_add(&obj->posA0, &torque, &obj->pos4F0);
    lbl_8006D5F0(&obj->dir1BC, &push, 0.2f * (scale * obj->mass));
    psvec_add(&obj->vel, &push, &obj->vel);

    if (obj->timer > 30) {
        obj->flags |= 0x20;
        lbl_8006DAEC();
        lbl_8006DBAC(obj->mtx14C);
        lbl_8006E1F0((void *)&up, 0.0f, 1.0f, 0.0f);
        dot = lbl_8006D6FC(&up, &obj->dir1BC);
        if (dot < 0.99f) {
            f32 by, bz, y, x, bx, az, ay, ax, z;
            ax = up.x; ay = up.y; az = up.z;
            bz = obj->dir1BC.z; bx = obj->dir1BC.x; by = obj->dir1BC.y;
            x = ay * bz;
            y = az * bx;
            z = ax * by;
            x -= az * by;
            y -= ax * bz;
            z -= ay * bx;
            axis.x = x;
            axis.y = y;
            axis.z = z;
            sq = axis.x * axis.x;
            sq += axis.y * axis.y;
            sq += axis.z * axis.z;
            if (lbl_8006D0B4(sq) > 0.1f) {
                sq = fn_1_2B684_square(dot);
                t = 1.0f - sq;
                fn_8006E7E4((void *)&q, (void *)&axis, (1365.0f * t));
                mathutil_mtxA_from_quat(&q);
                lbl_8006DFC4(obj->mtx14C);
                lbl_8006DB74(obj->mtx14C);
            }
        }
        lbl_8006DB30();
    }

    if (obj->timer < 2) {
        obj->timer = 2;
    } else if (++obj->timer >= 240) {
        obj->timer = 240;
    }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H
#undef dir
#pragma opt_propagation reset
/* fzgx:end fn_1_2B684 */

/* fzgx:begin fn_1_2BA48 */
void fn_1_2BA48(St *p) {
	s32 v = 0x3c;
	Other *g;
	f32 z;
	u32 n;
	U24 c;

	if (lbl_1_bss_960 != 9) {
		v = 0xf0;
	}
	if (!(p->unk_0 & 0x2)) {
		fn_1_2B684((void *)((u32)p));
	}
	if (p->unk_4e0 < 0x3c) {
		psvec_add(&p->unk_4f0, &p->unk_4e4, &p->unk_4e4);
	}
	n = p->unk_50d + 1;
	p->unk_50d = n;
	if ((u8)n >= (u16)v) {
		if (!(p->unk_0 & 0x2)) {
			z = 0.0f;
			p->unk_94 = z;
			p->unk_98 = z;
			p->unk_9c = z;
			c = p->unk_88;
			p->unk_7c = c;
			g = (Other *)fn_1_868C0(p->unk_4);
			if (!(p->unk_58c & 0x90)) {
				p->unk_58c = p->unk_58c | 0x80;
				p->unk_58c = p->unk_58c | 0x100;
				g->unk_390 = g->unk_390 | 0x200000;
				if ((s8)p->unk_474 != -1) {
					fn_1_F7338((s8)p->unk_474, (void *)(2), (void *)(0x1e));
				}
			}
			if (*lbl_801A66C8 + p->unk_4 == 0) {
				fn_1_A2D84(0xa9092e00);
				if ((s8)p->unk_475 != -1 && !(p->unk_0 & 0x4000200)) {
					fn_1_A2D84(0xa9091200);
				}
			}
		}
		p->unk_50d = v;
	}
}
/* fzgx:end fn_1_2BA48 */

/* fzgx:begin fn_1_2BBD0 */


void fn_1_2BBD0(Fn_1_2BBD0 *self, Fn_1_2BBD0Arg *other, f32 threshold) {
    if (self->active == 0) {
        Vec3 vec;
        f32 sum;
        f32 z;
        f32 y;
        f32 x;

        x = self->position.x;
        y = self->position.y;
        z = self->position.z;
        sum = x * x;
        sum += y * y;
        sum += z * z;
        if (threshold < lbl_8006D0B4(sum)) {
            lbl_8006DAEC();
            lbl_8006DBAC((void *)(((0xec) + ((char *)self))));
            mathutil_mtxA_set_translate(&self->pos);
            fn_8006E250((void *)&other->pos, (void *)&vec);
            lbl_8006D668((void *)&vec);
            if (vec.z < -0.1f) {
                self->position = vec;
                self->value4c1 = other->value04;
                lbl_8006D668((void *)&self->position);
            }
            lbl_8006DB30();
        }
    } else if (self->value4c1 == other->value04) {
        lbl_8006DAEC();
        lbl_8006DBAC((void *)((char *)self + 0xec));
        mathutil_mtxA_set_translate(&self->pos);
        fn_8006E250((void *)&other->pos, (void *)&self->position);
        lbl_8006D668((void *)&self->position);
        if (self->position.z > -0.1f) {
            self->position.z = -0.1f;
        }
        lbl_8006DB30();
    }
}


/* fzgx:end fn_1_2BBD0 */

/* fzgx:begin fn_1_2BD30 */
/* Unknown retail object: .rodata BAC, 9990.0f and -10.0f, no retail reader */
const f32 stcoli_unknown_BAC[2] = {9990.0f, -10.0f};

/* begin game/main_rel/camera_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAMERA_TYPES_H

// Types (and the externs that name them) of camera.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* end game/main_rel/camera_types.h */

static inline void fn_1_2BD30_set(Vec3 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline int fn_1_2BD30_nonfinite(f32 x) {
    return (*(u32 *)&x & 0x7F800000) == 0x7F800000;
}


/* WARNING: compiler-diff device, not original code: obj->velZ through an inline under
 * opt_dead_assignments off (6 words with the plain read) */
static inline f32 fn_1_2BD30_read_pointer(StcoliObj2BD30 * owner) { return owner->velZ; }

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

f32 fn_1_2BD30(StcoliObj2BD30 *obj, StcoliOut2BD30 *out, Vec3 *src) {
    Vec3 local;
    f32 m;
    f32 ax, ay, az;
    f32 vx, vy, vz;
    f32 lengthSquared;

    lbl_8006DAEC();
    lbl_8006DBAC((void *)&obj->rot);
    mathutil_mtxA_set_translate(&obj->pos);
    fn_8006E250((void *)src, (void *)&out->dir);
    fn_8006E2B0(obj->ref, &local);
    psvec_sub(&out->dir, &local, &out->dir);
    vx = out->dir.x;
    vy = out->dir.y;
    vz = out->dir.z;
    lengthSquared = vx * vx;
    lengthSquared += vy * vy;
    lengthSquared += vz * vz;
    if (lbl_8006D0B4(lengthSquared) > 0.00000011920929f) {
        lbl_8006D668(&out->dir);
    } else {
        f32 negOne = -1.0f;
        fn_1_2BD30_set(&out->dir, 0.0f, 0.0f, negOne);
    }

    ax = __fabs(out->dir.x);
    ay = 0.05000000074505806 * __fabs(out->dir.y);
    az = __fabs(out->dir.z);
    out->depth = 0.0f;
    if (ax > ay) {
        if (ax > az) {
            m = ax;
            fn_1_2BD30_set(&out->axis, out->dir.x, 0.0f, 0.0f);
        } else {
            m = az;
            fn_1_2BD30_set(&out->axis, 0.0f, 0.0f, out->dir.z);
            out->depth = out->dir.z;
        }
    } else {
        if (ay > az) {
            m = ay;
            fn_1_2BD30_set(&out->axis, 0.0f, out->dir.y, 0.0f);
        } else {
            m = az;
            fn_1_2BD30_set(&out->axis, 0.0f, 0.0f, out->dir.z);
            out->depth = out->dir.z;
        }
    }
    lbl_8006D668(&out->axis);

    vx = obj->velX;
    if (fn_1_2BD30_nonfinite(vx) || fn_1_2BD30_nonfinite(vy = obj->velY) || fn_1_2BD30_nonfinite(vz = fn_1_2BD30_read_pointer(obj))) {
        out->speed = 0.0f;
    } else {
        lengthSquared = (vx * vx);
        lengthSquared += vy * vy;
        lengthSquared += vz * vz;
        out->speed = lbl_8006D0B4(lengthSquared) / obj->scale;
    }
    lbl_8006E1C0(&out->axis, &out->axis);
    lbl_8006DB30();
    return __fabs(m);
}

#pragma opt_dead_assignments reset

#undef GAME_MAIN_REL_CAMERA_TYPES_H
#undef GAME_VEC3_H

/* fzgx:end fn_1_2BD30 */

/* fzgx:begin fn_1_2BF8C */
/* begin game/main_rel/camera_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAMERA_TYPES_H

// Types (and the externs that name them) of camera.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/vec3.h (deltawave784/fzgx, CC0) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* end game/main_rel/camera_types.h */

#define fn_1_2BF8C_clamp(value, bound) ((value) < (bound) ? (bound) : ((value) > 1.0f ? 1.0f : (value)))

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off
s32 fn_1_2BF8C(u32 arg0) {
    f32 v0;
    f32 zero;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v10;
    f32 v14;
    f32 v15;
    f32 v24;
    Vec3 loc_8;

    if (*(u8 *)(arg0 + 1496) != 0) {
    *(u32 *)((u8 *)arg0 + 1300) = -1;
    (*(u8 *)(arg0 + 1496))--;
    }
    if (*(u16 *)(arg0 + 532) != 0) {
    *(u32 *)((u8 *)arg0 + 1300) = -1;
    *(u8 *)((u8 *)arg0 + 1496) = 60;
    (*(u16 *)(arg0 + 532))--;
    if (*(u16 *)(arg0 + 532) == 179 && (s8)*(u8 *)(arg0 + 1141) != -1) {
    v1 = *(u32 *)(arg0);
    if ((v1 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 8704));
    }
    }
    if (*(u16 *)(arg0 + 532) == 170 && (s8)*(u8 *)(arg0 + 1141) != -1) {
    v2 = *(u32 *)(arg0);
    if ((v2 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 8960));
    }
    }
    if (*(u16 *)(arg0 + 532) == 20 && (s8)*(u8 *)(arg0 + 1141) != -1) {
    v3 = *(u32 *)(arg0);
    if ((v3 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9472));
    }
    }
    if (*(u16 *)(arg0 + 532) == 0) {
    if ((s8)*(u8 *)(arg0 + 1141) != -1) {
    v4 = *(u32 *)(arg0);
    if ((v4 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9728));
    }
    }
    if ((s8)*(u8 *)(arg0 + 1141) != -1) {
    v5 = *(u32 *)(arg0);
    if ((v5 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9216));
    }
    }
    if ((s8)*(u8 *)(arg0 + 1141) != -1) {
    v6 = *(u32 *)(arg0);
    if ((v6 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9060000 + 7168));
    }
    }
    }
    if ((*(u32 *)(arg0) & 0x10000000) != 0) {
    *(u16 *)((u8 *)arg0 + 532) = 0;
    lbl_8006DAEC();
    lbl_8006DBAC((void *)((Vec3 *)(arg0 + 332)));
    zero = 0.0f;
    psvec_set(((u8 *)arg0 + 124), *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    psvec_set(((u8 *)arg0 + 136), *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    *(f32 *)(0xE0000000 + 0x0C) = zero;
    *(f32 *)(0xE0000000 + 0x1C) = zero;
    *(f32 *)(0xE0000000 + 0x2C) = zero;
    lbl_8006DB74((void *)((arg0 + 236)));
    lbl_8006DB74((void *)((arg0 + 284)));
    lbl_8006DB30();
    if ((s8)*(u8 *)(arg0 + 1141) != -1) {
    v7 = *(u32 *)(arg0);
    if ((v7 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 9216));
    }
    }
    }
    v8 = *(u16 *)(arg0 + 532);
    if (*(u16 *)(arg0 + 532) == 0) {
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) & 0xFFFF7FFF);
    return 0;
    } else {
    if (v8 < 20) {
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | 32768);
    return 0;
    } else {
    if (v8 < 150.0) {
    if (v8 == 149.0 && (s8)*(u8 *)(arg0 + 1141) != -1) {
    v10 = *(u32 *)(arg0);
    if ((v10 & (0x4000000 + 512)) == 0) {
    fn_1_A2D84((0xA9090000 + 4608));
    }
    }
    v8 = *(u16 *)(arg0 + 532);
    if (v8 - 60 < 45.0f) {
    v0 = (*(f32 *)(arg0 + 1308));
    *(f32 *)((u8 *)arg0 + 1308) = (f32)(v0 - 0.00049382716f);
    } else {
    *(f32 *)((u8 *)arg0 + 1308) += 0.00049382716f;
    }
    *(f32 *)((u8 *)arg0 + 1304) += *(f32 *)((u8 *)arg0 + 1308);
    *(f32 *)((u8 *)arg0 + 1304) = fn_1_2BF8C_clamp(*(f32 *)((u8 *)arg0 + 1304), 0.0f);
    lbl_801A66CC->delta.x = *(f32 *)((u8 *)arg0 + 1324);
    lbl_801A66CC->delta.y = *(f32 *)((u8 *)arg0 + 1340);
    lbl_801A66CC->delta.z = *(f32 *)((u8 *)arg0 + 1356);
    loc_8.x = *(f32 *)(arg0 + 1440);
    v8 = (u32)&lbl_801A66CC->delta;
    loc_8.y = *(f32 *)(arg0 + 1456);
    loc_8.z = *(f32 *)(arg0 + 1472);
    v0 = (*(f32 *)(arg0 + 1304));
    lbl_8006D5A4((void *)v8, (u32)&loc_8, (void *)(arg0 + 124), v0);
    v0 = (*(f32 *)(arg0 + 1304));
    v8 = (arg0 + 1312);
    fn_80008DB4((void *)v8, v0, (void *)(arg0 + 1428), (void *)(arg0 + 236));
    v14 = 0.0f;
    v8 = (arg0 + 1360);
    *(f32 *)((u8 *)arg0 + 280) = v14;
    *(f32 *)((u8 *)arg0 + 264) = v14;
    *(f32 *)((u8 *)arg0 + 248) = v14;
    v0 = (*(f32 *)(arg0 + 1304));
    fn_80008DB4((void *)v8, v0, (void *)(arg0 + 1428), (void *)(arg0 + 332));
    *(f32 *)((u8 *)arg0 + 344) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 360) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 376) = *(f32 *)((u8 *)arg0 + 132);
    if (*(u16 *)(arg0 + 532) == 20) {
    v8 = (arg0 + 1312);
    *(f32 *)((u8 *)arg0 + 124) = *(f32 *)((u8 *)arg0 + 1440);
    *(f32 *)((u8 *)arg0 + 128) = *(f32 *)((u8 *)arg0 + 1456);
    *(f32 *)((u8 *)arg0 + 132) = *(f32 *)((u8 *)arg0 + 1472);
    lbl_8006DD48((void *)v8, (void *)(arg0 + 236));
    v15 = 0.0f;
    v8 = (arg0 + 1360);
    *(f32 *)((u8 *)arg0 + 280) = v15;
    *(f32 *)((u8 *)arg0 + 264) = v15;
    *(f32 *)((u8 *)arg0 + 248) = v15;
    lbl_8006DD14(v8, (void *)(arg0 + 332));
    *(f32 *)((u8 *)arg0 + 344) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 360) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 376) = *(f32 *)((u8 *)arg0 + 132);
    stcoli_restart(arg0);
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | 32768);
    lbl_8006DAEC();
    v0 = (f32)(0.0f);
    lbl_8006E0B4(v0, 1.0f, v0);
    v8 = arg0;
    for (v1 = 0; v1 < 4; v1++) {
        psvec_set(((u8 *)arg0 + 960 + 48 * v1), *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    }
    fn_1_25A14((void *)v8);
    lbl_8006DB30();
    return 0;
    } else {
    return 1;
    }
    } else {
    if (v8 < 180) {
    if (v8 == 150.0) {
    v24 = 0.0f;
    v8 = (arg0 + 236);
    *(f32 *)((u8 *)arg0 + 1304) = v24;
    *(f32 *)((u8 *)arg0 + 1308) = v24;
    lbl_8006DD48((void *)v8, (void *)(arg0 + 1312));
    v8 = (arg0 + 332);
    *(f32 *)((u8 *)arg0 + 1324) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 1340) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 1356) = *(f32 *)((u8 *)arg0 + 132);
    lbl_8006DD14(v8, (void *)(arg0 + 1360));
    lbl_8006DAEC();
    v8 = arg0;
    fn_1_8A168((void *)v8);
    v8 = (arg0 + 1428);
    lbl_8006DB74((void *)v8);
    lbl_8006DB30();
    return 1;
    }
    } else {
    *(f32 *)((u8 *)arg0 + 344) = *(f32 *)((u8 *)arg0 + 124);
    *(f32 *)((u8 *)arg0 + 360) = *(f32 *)((u8 *)arg0 + 128);
    *(f32 *)((u8 *)arg0 + 376) = *(f32 *)((u8 *)arg0 + 132);
    }
    }
    }
    }
    }
    return 0;
}

#undef GAME_MAIN_REL_CAMERA_TYPES_H
#undef GAME_VEC3_H
#undef fn_1_2BF8C_clamp

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2BF8C */

/* fzgx:begin fn_1_2C688 */
u32 fn_1_2C688(u32 arg0, u32 arg1, u32 arg2) {
    u32 v1;
    s32 v0;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 t0;
    u32 t1;
    u32 t2;
    v0 = 0;
    v1 = arg0;
    do {
    v2 = *(u32 *)(v1 + 1160);
    v3 = arg0;
    v4 = arg1;
    v5 = arg2;
    if (v2 != 0) {
    v3 = v2;
    v4 = 0;
    v5 = 192;
    t0 = (u32)memset( (void *)(v3), v4, v5);
    v3 = t0;
    v3 = (v2 + 8);
    *(u32 *)((u8 *)v2 + 0) = v3;
    *(u32 *)((u8 *)v2 + 4) = (v2 + 100);
    }
    v0++;
    v1 += 4;
    } while (v0 < 4);
    v3 = *(u32 *)(arg0 + 1176);
    if (v3 != 0) {
    v4 = 0;
    v5 = 404;
    t1 = (u32)memset( (void *)(v3), v4, v5);
    v3 = t1;
    }
    v6 = *(u32 *)(arg0 + 1180);
    if (v6 != 0) {
    v3 = v6;
    v4 = 0;
    v5 = 279;
    t2 = (u32)memset( (void *)(v3), v4, v5);
    v3 = t2;
    v4 = (v6 + 184);
    *(u32 *)((u8 *)v6 + 128) = 0;
    v3 = (v6 + 200);
    *(u32 *)((u8 *)v6 + 144) = v4;
    *(u32 *)((u8 *)v6 + 148) = v3;
    *(u32 *)((u8 *)v6 + 156) = -1;
    *(u32 *)((u8 *)v6 + 184) = -1;
    *(u32 *)((u8 *)v6 + 216) = -1;
    }
    return v3;
}
/* fzgx:end fn_1_2C688 */
