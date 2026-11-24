#include "types.h"
#include "rel/main_rel/globals.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/vec3.h"
#include "psvec.h"
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
struct fn_1_2B478_lbl_801A6D00 {
    u32 unk_0;
};

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
    u8 pad_0[0x8];
    f32 zero;    /* 0x08 */
    f32 one;     /* 0x0C */
    u8 pad_10[0x8];
    f32 neg_one; /* 0x18 */
    f32 two;     /* 0x1C */
} StcoliPool17920;

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
    void *unk_1C[4]; /* segment of any kind */
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

/* fn_1_1D0CC */
typedef struct {
    u32 unk_0;
} Segment;

/* fn_1_1D0CC */
typedef struct {
    s32 unk_0;
    u8 pad_4[0x18];
    void *unk_1C[4]; /* segment of any kind */
    f32 unk_2C[4];
    u32 unk_3C[4];
    s32 unk_4C[4];
} CollNode;

/* fn_1_1D0CC */
typedef struct {
    CollNode *unk_0;
    CollNode *unk_4;
} CollCtx;

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

/* Course collision header (*lbl_1_bss_3BE0). globals.h declares the symbol with its generated placeholder
 * type (all u32 words), so the units of this file read it through this layout. */
typedef struct {
    u8 pad_0[0x8];
    s32 count;
    fn_1_20A5C_Seg *segs;
    u8 pad_10[0x18 - 0x10];
    s32 ncells;
    Cell *cells;
    u8 pad_20[0x48 - 0x20];
    s32 nobj;
    s32 firstobj;
    s32 firstobj2;
    Obj *objs;
    u8 pad_58[0x7D - 0x58];
    u8 single;
    u8 pad_7e[0xBC - 0x7E];
    s16 **grid;
    f32 x0;
    f32 z0;
    f32 sx;
    f32 sz;
    s32 nx;
    s32 nz;
} ColiCourse;

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
struct fn_1_6400_lbl_801A6410 {
    u32 unk_0;
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
struct fn_1_2B478_lbl_801A66CC {
    u32 unk_0;
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
    f32 field7c;
    f32 field80;
    f32 field84;
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
    f32 field7c;
    f32 field80;
    f32 field84;
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
    f32 posX;           /* 0x7C */
    f32 posY;           /* 0x80 */
    f32 posZ;           /* 0x84 */
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

/* fn_1_2BF8C */
struct fn_1_2BF8C_lbl_801A66CC {
    u32 unk_0;
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
extern int fn_80083BCC(const u8 *, const u8 *);
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
extern void lbl_8006DBE4(void);
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
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_z(s16);
/* rotation by (sin, cos): entry 0xC bytes into mathutil_mtxA_rotate_z */
extern void mathutil_mtxA_rotate_z_s_c(f32, f32);
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
void fn_1_18F28(StcoliNode *node, StcoliVec *vec, void *arg3, f32 value);
void fn_1_18FFC(Vec3 *arg0, Vec3 *arg1, u32 arg2, void *arg3, Vec3 *arg4, void *arg5, void *arg6, s32 arg7, f32 arg8);
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
void fn_1_2192C(void *self, void *arg, f32 t);
void fn_1_21950(u32 arg0, f32 arg1, f32 arg2);
void fn_1_21BE4(Fn_1_21BE4 *self, void *arg, f32 t);
void fn_1_21C5C(void *self, void *arg, f32 t);
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
void fn_1_25480(Fn_1_25480_Obj *p);
void fn_1_25870(Fn_1_25870 *self);
s32 fn_1_25A14(fn_1_25A14_Machine *m);
void fn_1_266A8(CollisionObject *obj);
f32 fn_1_26F34(u32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 fn_1_278B8(u32 arg0, void *arg1, f32 arg2);
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
s32 fn_1_2BF8C(u32 arg0, f32 arg1);
u32 fn_1_2C688(u32 arg0, u32 arg1, u32 arg2);

/* ---- coli.c file-scope data */
typedef void (*ColiTestFn)(void *, void *, u32, void *, void *, void *, void *, s32, f32);
typedef void (*ColiDrawFn)(void *, void *, f32);

ColiTestFn lbl_1_data_5548[33] = {
    (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC,
    (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_19AE0, (ColiTestFn)fn_1_1D0CC,
    (ColiTestFn)fn_1_1DCD8, (ColiTestFn)fn_1_1EBD4, (ColiTestFn)fn_1_1B2A4, (ColiTestFn)fn_1_1B010,
    (ColiTestFn)fn_1_1B010, (ColiTestFn)fn_1_1B010, (ColiTestFn)fn_1_1B010, (ColiTestFn)fn_1_18FFC,
    (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC,
    (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC,
    (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC,
    (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC, (ColiTestFn)fn_1_18FFC,
    (ColiTestFn)fn_1_18FFC,
};

/* Unknown retail object: draw handler table, no retail function reads it. */
ColiDrawFn lbl_1_data_55CC[33] = {
    (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C,
    (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_21BE4, (ColiDrawFn)fn_1_21CFC,
    (ColiDrawFn)fn_1_21F18, (ColiDrawFn)fn_1_2221C, (ColiDrawFn)fn_1_21CA0, (ColiDrawFn)fn_1_21C5C,
    (ColiDrawFn)fn_1_21C5C, (ColiDrawFn)fn_1_21C5C, (ColiDrawFn)fn_1_21C5C, (ColiDrawFn)fn_1_2192C,
    (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C,
    (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C,
    (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C,
    (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C, (ColiDrawFn)fn_1_2192C,
    (ColiDrawFn)fn_1_2192C,
};

/* fzgx:begin fn_1_14F04 */
u8 * fn_1_14F04(void) {
    return (u8 *)&lbl_801A66CC->radius;
}
/* fzgx:end fn_1_14F04 */

/* fzgx:begin fn_1_14F18 */
/* Grid cell of the point (x, z), -1 outside the grid. */
static s32 cell_index(Cell *cell, f32 x, f32 z) {
    s32 ix;
    s32 iz;
    s32 idx;

    ix = fpscr_floorf((x - cell->x0) / cell->sx);
    iz = fpscr_floorf((z - cell->z0) / cell->sz);
    if (ix < 0 || ix >= cell->nx) {
        idx = -1;
    } else if (iz < 0 || iz >= cell->nz) {
        idx = -1;
    } else {
        idx = ix + iz * cell->nx;
    }
    return idx;
}

/* Plane d, normal, then `count` vertices followed by `count` edge normals. */

static inline s32 FZGX_NONFINITE(f32 f) {
    return (*(u32 *)&f & 0x7F800000) == 0x7F800000;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

static inline f32 fn_1_14F18_dot(Vec3 *a, Vec3 *b) {
    f32 r;
    f32 y;
    f32 z;
    r = a->x * b->x;
    y = a->y;
    z = a->z;
    r = y * b->y + r;
    r = z * b->z + r;
    return r;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

s32 fn_1_14F18(Vec3 *pos, void *arg1, Vec3 *dir, f32 *outT,
               fn_1_14F18_Poly *poly, s32 count, u32 flags, f32 radius) {
    Vec3 *edges[5];
    Vec3 hit;
    Vec3 out0;
    Vec3 out1;
    Vec3 **e;
    s32 i;
    Vec3 *v;
    Vec3 **initE;
    Vec3 *n;
    Vec3 *d;
    f32 tIn;
    f32 tOut;
    f32 denom;
    f32 dist;
    f32 planeDot;
    s32 j;
    Vec3 *verts;

    denom = poly->n.x * dir->x;
    denom = poly->n.y * dir->y + denom;
    denom = poly->n.z * dir->z + denom;
    if (denom > 0.0f && !(flags & 0x400000)) {
        return 0;
    }
    planeDot = poly->n.x * pos->x;
    planeDot = poly->n.y * pos->y + planeDot;
    planeDot = poly->n.z * pos->z + planeDot;
    dist = planeDot + poly->d;
    tIn = dist / denom;
    if (1.0f < tIn || FZGX_NONFINITE(tIn)) {
        return 0;
    }
    tOut = (dist - radius) / denom;
    if (tOut < 0.0f || FZGX_NONFINITE(tOut)) {
        return 0;
    }
    if (tIn < 0.0f) {
        tIn = 0.0f;
    }
    psvec_scale_add(pos, dir, -tIn, &hit);

    v = poly->verts;
    initE = &edges[1];
    for (j = count; j > 1; j--) {
        *initE++ = v++;
    }

    verts = poly->verts;
    e = edges;
    e[count] = verts;
    n = verts + count;
    v = verts;
    for (i = 0; i < count;) {
        psvec_sub(&hit, v, &lbl_801A66CC->delta);
        d = &lbl_801A66CC->delta;
        if (fn_1_14F18_dot(d, n) < 0.0f) {
            if (fn_1_1FFA0((void *)pos, (void *)arg1, (void *)v, (void *)e[1], (void *)&out0, (void *)&out1) > radius * radius) {
                return 0;
            }
        }
        e++;
        i++;
        v++;
        n++;
    }

    if (tOut > 1.0f) {
        tOut = 1.0f;
    }
    psvec_scale_add(pos, dir, -tOut, pos);
    *outT = 1.0f - tOut;
    return 1;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
/* fzgx:end fn_1_14F18 */

/* fzgx:begin fn_1_15248 */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@b1e6f2df) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

/* reloaded on every access in retail, including after the paired-single stores */

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

static inline void fn_1_15248_cross(Vec3 *a, Vec3 *b, Vec3 *out)
{
    f32 x, y, z;
    x = a->y * b->z;
    x -= a->z * b->y;
    y = a->z * b->x;
    y -= a->x * b->z;
    z = a->x * b->y;
    z -= a->y * b->x;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 fn_1_15248_dot(Vec3 *a, Vec3 *b)
{
    f32 d;
    f32 y, z;
    /* Snapshot the shared scratch components before accumulating. */
    /* WARNING: compiler-diff device, not original code */
    y = *(volatile f32 *)&a->y;
    /* WARNING: compiler-diff device, not original code */
    z = *(volatile f32 *)&a->z;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    d = a->x * b->x;
    d = y * b->y + d;
    d = z * b->z + d;
    return d;
}

s32 fn_1_15248(Vec3 *pos, Vec3 *arg1, fn_1_15248_Poly *poly, s32 n, f32 radius)
{
    Vec3 local[4];
    Vec3 edge;
    Vec3 side;
    Vec3 origin;
    Vec3 point;
    Vec3 out0;
    Vec3 out1;
    s32 count;
    Vec3 *nrm;
    s32 j;
    s32 i;
    Vec3 *verts;
    s32 found;
    f32 *mtx;
    s32 next;
    f32 hi;
    f32 lo;
    f32 y;
    f32 zero;
    f32 rr;

    if (n > 4) {
        return 0;
    }

    psvec_sub(&poly->verts[1], &poly->verts[0], &edge);
    fn_1_15248_cross(&edge, &poly->normal, &side);
    {
        f32 z, y, x;
        x = poly->normal.y * side.z;
        x -= poly->normal.z * side.y;
        y = poly->normal.z * side.x;
        y -= poly->normal.x * side.z;
        z = poly->normal.x * side.y;
        z -= poly->normal.y * side.x;
        edge.x = x;
        edge.y = y;
        edge.z = z;
    }
    lbl_8006D668(&edge);
    lbl_8006D668(&side);

    mtx = lbl_801A6D00;
    mtx[0] = edge.x;
    mtx[1] = poly->normal.x;
    mtx[2] = side.x;
    mtx[3] = pos->x;
    mtx[4] = edge.y;
    mtx[5] = poly->normal.y;
    mtx[6] = side.y;
    mtx[7] = pos->y;
    mtx[8] = edge.z;
    mtx[9] = poly->normal.z;
    mtx[10] = side.z;
    mtx[11] = pos->z;
    lbl_8006DF44();

    lo = -5.0f;
    hi = 10.0f;
    verts = poly->verts;
    found = 0;
    for (i = 0; i < n; i++, verts++) {
        lbl_8006E1B0((void *)verts, (void *)&local[i]);
        y = -local[i].y;
        if (lo <= y && y <= hi) {
            found = 1;
        }
    }
    if (found == 0) {
        return 0;
    }

    verts = poly->verts;
    nrm = &verts[n];
    zero = 0.0f;
    count = 0;
    for (i = 0; i < n; i++, verts++, nrm++) {
        Vec3 *delta;
        f32 d;
        psvec_sub(pos, verts, &lbl_801A66CC->delta);
        delta = &lbl_801A66CC->delta;
        d = fn_1_15248_dot(delta, nrm);
        if (d < zero) {
            break;
        }
        count++;
    }
    if (count == n) {
        return 1;
    }

    zero = 0.0f;
    origin.x = zero;
    origin.y = zero;
    origin.z = zero;
    lbl_8006E1B0((void *)arg1, (void *)&point);
    zero = 0.0f;
    rr = radius * radius;
    point.y = zero;
    local[0].y = zero;
    for (j = 0; j < n; j++) {
        next = (j == n - 1) ? 0 : j + 1;
        local[next].y = zero;
        if (fn_1_1FFA0((void *)&origin, (void *)&point, (void *)&local[j], (void *)&local[next], (void *)&out0, (void *)&out1) < rr) {
            return 1;
        }
    }
    return 0;
}

#pragma opt_lifetimes reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
/* fzgx:end fn_1_15248 */

/* fzgx:begin fn_1_15578 */
static inline void hit_reset(ColiContact *h) {
    h->flags = 0;
    h->t = -1.0f;
}

static inline s32 is_nonfinite(f32 f) {
    return (*(u32 *)&f & 0x7F800000) == 0x7F800000;
}

static inline f32 dot3(Vec3 *a, Vec3 *b) {
    f32 r;
    f32 y;
    f32 z;
    r = a->x * b->x;
    y = a->y;
    z = a->z;
    r = y * b->y + r;
    r = z * b->z + r;
    return r;
}

/* MWCC colours compiler temporaries before named locals, and an inline's
 * locals in reverse declaration order. Holding every component in a local
 * keeps the edge test's registers behind `t` and the 0.0f constant. */

static inline f32 dot3_cached(Vec3 *a, Vec3 *b) {
    f32 r;
    f32 ax, ay, az;
    f32 bx, by, bz;
    ax = a->x;
    ay = a->y;
    az = a->z;
    bx = b->x;
    by = b->y;
    bz = b->z;
    r = ax * bx;
    r = ay * by + r;
    r = az * bz + r;
    return r;
}

/* The declaration order is load-bearing (see dot3_cached): retail colours t
 * first, then d, n, p, denom and dist. */

static inline s32 ray_poly(Vec3 *pos, Vec3 *dir, fn_1_14F18_Poly *poly, s32 count, f32 *outT) {
    Vec3 hit;
    f32 dist;
    f32 denom;
    f32 px, py, pz;
    f32 nx, ny, nz;
    f32 dx, dy, dz;
    f32 t;
    Vec3 *v;
    Vec3 *n;
    s32 i;

    nx = poly->n.x;
    ny = poly->n.y;
    nz = poly->n.z;
    dx = dir->x;
    dy = dir->y;
    dz = dir->z;
    denom = nx * dx;
    denom = ny * dy + denom;
    denom = nz * dz + denom;
    if (denom > 0.0f) {
        return 0;
    }
    px = pos->x;
    py = pos->y;
    pz = pos->z;
    dist = nx * px;
    dist = ny * py + dist;
    dist = nz * pz + dist;
    t = (poly->d + dist) / denom;
    if (t < 0.0f || 1.0f < t || is_nonfinite(t)) {
        return 0;
    }
    psvec_scale_add(pos, dir, -t, &hit);
    v = poly->verts;
    n = v + count;
    for (i = 0; i < count; i++, v++, n++) {
        psvec_sub(&hit, v, &lbl_801A66CC->delta);
        if (dot3_cached(&lbl_801A66CC->delta, n) < 0.0f) {
            return 0;
        }
    }
    *pos = hit;
    *outT = 1.0f - t;
    return 1;
}

s32 fn_1_15578(Vec3 *arg0, Vec3 *arg1, f32 *outT, Vec3 *outNrm, u32 flags, s32 *arg5, s32 arg6, s32 arg7, s32 arg8, Racer *racer) {
    Vec3 a;
    Vec3 b;
    Vec3 p0;
    Vec3 save;
    Vec3 d;
    Vec3 save2;
    Vec3 d2;
    f32 t;
    f32 t2;
    f32 t3;
    u32 vis;
    ColiContact *w;
    s32 idx;
    Cell *cell;
    s32 i;
    s32 k;
    s32 best;
    Vec3 *hitPos;
    Vec3 *hitNrm;
    s32 bit;
    s32 type;
    s16 ***lists;
    s16 *p;
    void *poly;
    s32 slot;
    Obj *obj;
    Xform2 *xf;
    Model *model;
    s32 scaled;
    s32 j;
    u8 *pp;
    f32 m;
    f32 radius;
    f32 len;
    ColiContact *h;

    w = &lbl_801A66CC->hits[4];
    hitPos = &w->point;
    hitNrm = &w->normal;
    best = -1;
    vis = fn_1_9D260();
    lbl_801A66CC->unk_1C8 = 0;
    lbl_801A66CC->total = 0;
    lbl_801A66CC->num_volumes = 0;
    lbl_801A66CC->flags = 0;
    lbl_801A66CC->probes[0].mask = 0;
    lbl_801A66CC->num_contacts = 0;
    hit_reset(&lbl_801A66CC->hits[0]);
    hit_reset(&lbl_801A66CC->hits[1]);
    hit_reset(&lbl_801A66CC->hits[2]);
    hit_reset(&lbl_801A66CC->hits[3]);
    hit_reset(&lbl_801A66CC->hits[4]);
    if (racer) {
        lbl_801A66CC->radius = racer->radius;
        lbl_801A66CC->unk_1B4 = racer->unk588;
    } else {
        lbl_801A66CC->radius = 2.0f;
        lbl_801A66CC->unk_1B4 = 0.0f;
        lbl_801A66CC->ctx = 0;
    }
    w->t = 10.0f;
    p0 = *arg0;
    cell = ((ColiCourse *)lbl_1_bss_3BE0)->cells;
    if (flags & 5) {
        fn_1_17098((void *)arg0, (u32)arg1, flags, (u32)arg5, arg6, (void *)arg7, (void *)arg8);
    }
    if ((flags & 0x4000000) && fn_1_7B054() == 15) {
        flags &= ~4;
    }
    if (flags & 0x705) {
        for (i = 0; i < ((ColiCourse *)lbl_1_bss_3BE0)->ncells; i++, cell++) {
            a = p0;
            b = *arg1;
            if (i != 0 && i > 0) {
                CellMtx *cm = &lbl_1_bss_3BE4[i];
                lbl_8006DBAC(cm->mtx0);
                /* WARNING: compiler-diff device, not original code. Retail keeps a dead
                 * `b +8; bl fn_8006E2B0` after this call (same device as fn_1_163BC).
                 * Honest form: `fn_8006E250(&a, &a);`. */
                (fn_8006E250(&a, &a), 1) || (fn_8006E2B0(&a, (void *)&a), 1);
                lbl_8006DBAC(cm->mtx1);
                fn_8006E250(&b, &b);
            }
            idx = cell_index(cell, b.x, b.z);
            if (idx >= 0) {
                for (k = 0; k < 2; k++) {
                    if (k == 0) {
                        lists = cell->lists70;
                        type = 4;
                    } else {
                        type = 3;
                        lists = cell->lists58;
                    }
                    if (lists && best < 0) {
                        save = a;
                        psvec_sub(&a, &b, &d);
                        for (bit = 0; bit < 11; bit++) {
                            if (flags & (1 << bit)) {
                                slot = bit;
                                if (bit == 10) {
                                    if (vis == 2) {
                                        slot = bit + 1;
                                    } else if (vis == 4) {
                                        slot = bit + 2;
                                    } else if (vis == 8) {
                                        slot = bit + 3;
                                    }
                                }
                                p = lists[slot][idx];
                                if (p) {
                                    for (; *p >= 0; p++) {
                                        if (type == 4) {
                                            poly = (u8 *)cell->polys70 + *p * 0x70;
                                        } else {
                                            poly = (u8 *)cell->polys58 + *p * 0x58;
                                        }
                                        if ((1 << bit) & 0x700) {
                                            if (!fn_1_14F18((void *)&a, (void *)&b, (void *)&d, (void *)&t, (void *)poly, type, flags, lbl_801A66CC->radius)) {
                                                continue;
                                            }
                                        } else if (!ray_poly(&a, &d, poly, type, &t)) {
                                            continue;
                                        }
                                        {
                                            if (t <= w->t) {
                                            *hitPos = a;
                                            if (type == 4) {
                                                *hitNrm = ((fn_1_14F18_Poly *)poly)->n;
                                            } else {
                                                *hitNrm = ((fn_1_14F18_Poly *)poly)->n;
                                            }
                                            w->t = t;
                                            best = i;
                                            w->flags = 1 << bit;
                                            a = save;
                                            }
                                        }
                                    }
                                    if (best >= 0) {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((flags & 0x3800) && (fn_1_7B054() != 10 || (*arg5 > 0x7E && *arg5 < 0x8F))) {
        i = ((ColiCourse *)lbl_1_bss_3BE0)->firstobj;
        obj = ((ColiCourse *)lbl_1_bss_3BE0)->objs + i;
        for (; i < ((ColiCourse *)lbl_1_bss_3BE0)->nobj; i++, obj++) {
            model = obj->ref->model;
            if (!model) {
                break;
            }
            if (!(obj->flags & vis)) {
                continue;
            }
            if (!(model->flags & flags & 0x3800)) {
                continue;
            }
            xf = obj->xf;
            scaled = 1.0f != obj->scale.x || 1.0f != obj->scale.y || 1.0f != obj->scale.z;
            if (obj->mtx) {
                lbl_8006DBAC(obj->mtx);
            } else {
                lbl_8006D7DC(&obj->pos);
                if (obj->rz != 0) {
                    mathutil_mtxA_rotate_z(obj->rz);
                }
                if (obj->ry != 0) {
                    mathutil_mtxA_rotate_y(obj->ry);
                }
                if (obj->rx != 0) {
                    mathutil_mtxA_rotate_x(obj->rx);
                }
                if (scaled) {
                    lbl_8006E13C(&obj->scale);
                }
            }
            lbl_8006E1B0(&model->center, &a);
            if (scaled) {
                f32 dz, dy, dx, sq;
                m = obj->scale.x > obj->scale.y ? obj->scale.x : obj->scale.y;
                m = obj->scale.z > m ? obj->scale.z : m;
                dx = a.x;
                dx -= p0.x;
                dy = a.y;
                dy -= p0.y;
                dz = a.z;
                dz -= p0.z;
                sq = dx * dx;
                sq += dy * dy;
                sq += dz * dz;
                if (sq > (model->radius * m) * (model->radius * m)) {
                    continue;
                }
                m = obj->scale.x < obj->scale.y ? obj->scale.x : obj->scale.y;
                m = obj->scale.z < m ? obj->scale.z : m;
                radius = lbl_801A66CC->radius / m;
                lbl_8006DAEC();
                lbl_8006DD7C();
                lbl_8006E1B0(&p0, &a);
                lbl_8006DB30();
            } else {
                f32 dz, dy, dx, sq;
                Vec3 *pp0 = &p0;
                Vec3 *pa = &a;
                dx = a.x;
                dx -= p0.x;
                dy = a.y;
                dy -= p0.y;
                dz = a.z;
                dz -= p0.z;
                sq = dx * dx;
                sq += dy * dy;
                sq += dz * dz;
                if (sq > model->radius * model->radius) {
                    continue;
                }
                radius = lbl_801A66CC->radius;
                fn_8006E250(pp0, pa);
            }
            lbl_8006DAEC();
            scaled = 1.0f != xf->scale.x || 1.0f != xf->scale.y || 1.0f != xf->scale.z;
            if (obj->mtx) {
                lbl_8006DBAC(obj->mtx);
            } else {
                lbl_8006D7DC(&xf->pos);
                if (xf->rz != 0) {
                    mathutil_mtxA_rotate_z(xf->rz);
                }
                if (xf->ry != 0) {
                    mathutil_mtxA_rotate_y(xf->ry);
                }
                if (xf->rx != 0) {
                    mathutil_mtxA_rotate_x(xf->rx);
                }
                if (scaled) {
                    lbl_8006E13C(&xf->scale);
                }
            }
            if (scaled) {
                lbl_8006DD7C();
                lbl_8006E1B0(arg1, &b);
            } else {
                fn_8006E250(arg1, &b);
            }
            lbl_8006DB30();
            psvec_sub(&a, &b, &d2);
            save2 = a;
            pp = model->polys70;
            for (j = 0; j < model->n70; j++, pp += 0x70) {
                if (fn_1_14F18((void *)&a, (void *)&b, (void *)&d2, (void *)&t2, (void *)pp, 4, flags, radius) && t2 <= w->t) {
                    lbl_8006E1B0(&a, hitPos);
                    lbl_8006E1C0(pp + 4, hitNrm);
                    best = 0;
                    w->t = t2;
                    w->flags = model->flags & 0x3800;
                    a = save2;
                }
            }
            pp = model->polys58;
            for (j = 0; j < model->n58; j++, pp += 0x58) {
                if (fn_1_14F18((void *)&a, (void *)&b, (void *)&d2, (void *)&t3, (void *)pp, 3, flags, radius) && t3 <= w->t) {
                    lbl_8006E1B0(&a, hitPos);
                    lbl_8006E1C0(pp + 4, hitNrm);
                    best = 0;
                    w->t = t3;
                    w->flags = model->flags & 0x3800;
                    a = save2;
                }
            }
        }
    }
    if (best > 0 && best > 0) {
        CellMtx *cm = &lbl_1_bss_3BE4[best];
        lbl_8006DBAC(cm->mtx0);
        if (hitPos) {
            lbl_8006E1B0(hitPos, hitPos);
        }
        if (hitNrm) {
            /* WARNING: compiler-diff device, not original code. Retail keeps an
             * unreachable `bl lbl_8006DBAC; li r3,0; li r4,0; bl lbl_8006E1B0` after
             * this call. Honest form: `lbl_8006E1C0(hitNrm, hitNrm);` (misses by 5 rows). */
            (lbl_8006E1C0(hitNrm, hitNrm), 1) || (lbl_8006DBAC(cm->mtx0), lbl_8006E1B0(NULL, NULL), 1);
        }
    }
    if (w->flags) {
        psvec_sub(&p0, hitPos, &lbl_801A66CC->delta);
        len = lbl_8006D6FC(&lbl_801A66CC->delta, hitNrm);
        if (!is_nonfinite(len)) {
            psvec_scale(&lbl_801A66CC->delta, len, &lbl_801A66CC->delta);
        }
        if (w->flags & 0x3804) {
            len = lbl_8006D0B4(dot3(&lbl_801A66CC->delta, &lbl_801A66CC->delta)) + 0.5f;
        } else {
            len = lbl_8006D0B4(dot3(&lbl_801A66CC->delta, &lbl_801A66CC->delta));
        }
        psvec_scale(hitNrm, len, &lbl_801A66CC->hits[4].correction);
    }
    if (lbl_801A66CC->hits[3].flags || lbl_801A66CC->hits[4].flags || lbl_801A66CC->hits[0].flags) {
        ColiWork *w2 = lbl_801A66CC;
        if (!w2->hits[3].flags) {
            h = &w2->hits[4];
        } else if (!w2->hits[4].flags) {
            h = &w2->hits[3];
        } else if (w2->hits[3].t < w2->hits[4].t) {
            h = &w2->hits[3];
            w2->hits[4].flags = 0;
        } else {
            h = &w2->hits[4];
        }
        *arg0 = h->point;
        *outNrm = h->normal;
        *outT = h->t;
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_15578 */

/* fzgx:begin fn_1_163BC */
/* fzgx:begin fn_1_163BC noprologue */

s32 fn_1_163BC(Vec3 *arg0, Vec3 *arg1, s32 mask, s32 arg3) {
    Vec3 a;
    Vec3 b;
    Vec3 pos;
    Vec3 save;
    Vec3 save2;
    Vec3 sp18;
    s32 idx;
    s32 i;
    Cell *cell;
    s32 result;
    s32 k;
    s32 bit;
    s32 type;
    s16 ***lists;
    s16 *p;
    void *poly;
    u32 vis;
    Obj *obj;
    Model *model;
    Xform2 *xf;
    s32 scaled;
    f32 m;
    void * lab_t0;
    void * lab_t0_;
    f32 dy;
    f32 dx;
    f32 dz;
    f32 sq;
    s32 j;
    u8 *pp;
    s32 start;

    result = 0;
    /* Retail keeps this bounds check although its result is unused. */
    if (((ColiCourse *)lbl_1_bss_3BE0)->count != 0 && arg3 >= 0 && arg3 < ((ColiCourse *)lbl_1_bss_3BE0)->count) {
        start = arg3;
    }
    pos = *arg0;
    /* WARNING: compiler-diff device, not original code. Dead load that register allocation
     * deletes; it shifts the pre-RA schedule so the lbl_1_bss_3BE0 reload lands after the
     * pos stores, as in retail. Honest form (no load) misses by 10 rows in the prologue. */
    m = 1.0f;
    cell = ((ColiCourse *)lbl_1_bss_3BE0)->cells;
    for (i = 0; i < ((ColiCourse *)lbl_1_bss_3BE0)->ncells; i++, cell++) {
        a = pos;
        b = *arg1;
        if (i != 0 && i > 0) {
            CellMtx *cm = &lbl_1_bss_3BE4[i];
            lbl_8006DBAC(cm->mtx0);
            /* WARNING: compiler-diff device, not original code. Retail has a dead
             * `b; bl fn_8006E2B0` here (likely a constant-condition macro choosing between the
             * two transforms); this constant-true `||` reproduces it. Honest form
             * `fn_8006E250(&a, &a);` misses the dead pair: 2 words, 3 rows. */
            (fn_8006E250(&a, &a), 1) || (fn_8006E2B0(&a, (void *)&a), 1);
            lbl_8006DBAC(cm->mtx1);
            fn_8006E250(&b, &b);
        }
        idx = cell_index(cell, b.x, b.z);
        if (idx >= 0) {
            for (k = 0; k < 2; k++) {
                if (k == 0) {
                    lists = cell->lists70;
                    type = 4;
                } else {
                    type = 3;
                    lists = cell->lists58;
                }
                if (lists) {
                    save = a;
                    for (bit = 0; bit < 11; bit++) {
                        if (mask & (1 << bit)) {
                            p = lists[bit][idx];
                            if (p) {
                                for (; *p >= 0; p++) {
                                    if (type == 4) {
                                        poly = (u8 *)cell->polys70 + *p * 0x70;
                                    } else {
                                        poly = (u8 *)cell->polys58 + *p * 0x58;
                                    }
                                    if (fn_1_15248((void *)&a, (void *)&b, (void *)poly, type, 2.5f)) {
                                        result |= 1 << bit;
                                        a = save;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (mask & 0x4080) {
        vis = fn_1_9D260();
        i = ((ColiCourse *)lbl_1_bss_3BE0)->firstobj2;
        obj = ((ColiCourse *)lbl_1_bss_3BE0)->objs + i;
        for (; i < ((ColiCourse *)lbl_1_bss_3BE0)->nobj; i++, obj++) {
            model = obj->ref->model;
            if (!model) {
                break;
            }
            if (!(model->flags & 0x4000)) {
                break;
            }
            if (!(obj->flags & vis)) {
                continue;
            }
            if (!(obj->mask & lbl_1_data_2A7E0.unk_A0)) {
                continue;
            }
            if (obj->flags & 0x40000000) {
                if (!(mask & 0x80)) {
                    continue;
                }
            } else if (!(mask & 0x4000)) {
                continue;
            }
            xf = obj->xf;
            scaled = 1.0f != obj->scale.x || 1.0f != obj->scale.y || 1.0f != obj->scale.z;
            if (obj->mtx) {
                lbl_8006DBAC(obj->mtx);
            } else {
                lbl_8006D7DC(&obj->pos);
                if (obj->rz != 0) {
                    mathutil_mtxA_rotate_z(obj->rz);
                }
                if (obj->ry != 0) {
                    mathutil_mtxA_rotate_y(obj->ry);
                }
                if (obj->rx != 0) {
                    mathutil_mtxA_rotate_x(obj->rx);
                }
                if (scaled) {
                    lbl_8006E13C(&obj->scale);
                }
            }
            lbl_8006E1B0(&model->center, &a);
            if (scaled) {
                m = obj->scale.x > obj->scale.y ? obj->scale.x : obj->scale.y;
                m = obj->scale.z > m ? obj->scale.z : m;
                dx = a.x;
                dx -= pos.x;
                dy = a.y;
                dy -= pos.y;
                dz = a.z;
                dz -= pos.z;
                sq = dx * dx;
                sq += dy * dy;
                sq += dz * dz;
                if (sq > (model->radius * m) * (model->radius * m)) {
                    continue;
                }
                lbl_8006DAEC();
                lbl_8006DD7C();
                lbl_8006E1B0(&pos, &a);
                lbl_8006DB30();
            } else {
                lab_t0_ = &pos;
                lab_t0 = &a;
                dx = a.x;
                dx -= pos.x;
                dy = a.y;
                dy -= pos.y;
                dz = a.z;
                dz -= pos.z;
                sq = dx * dx;
                sq += dy * dy;
                sq += dz * dz;
                if (sq > (model->radius) * model->radius) {
                    continue;
                }
                fn_8006E250(lab_t0_, lab_t0);
            }
            lbl_8006DAEC();
            scaled = 1.0f != xf->scale.x || 1.0f != xf->scale.y || 1.0f != xf->scale.z;
            if (obj->mtx) {
                lbl_8006DBAC(obj->mtx);
            } else {
                lbl_8006D7DC(&xf->pos);
                if (xf->rz != 0) {
                    mathutil_mtxA_rotate_z(xf->rz);
                }
                if (xf->ry != 0) {
                    mathutil_mtxA_rotate_y(xf->ry);
                }
                if (xf->rx != 0) {
                    mathutil_mtxA_rotate_x(xf->rx);
                }
                if (scaled) {
                    lbl_8006E13C(&xf->scale);
                }
            }
            if (scaled) {
                lbl_8006DD7C();
                lbl_8006E1B0(arg1, &b);
            } else {
                fn_8006E250(arg1, &b);
            }
            lbl_8006DB30();
            save2 = a;
            psvec_sub(&a, &b, &sp18);
            pp = model->polys70;
            for (j = 0; j < model->n70; j++, pp += 0x70) {
                if (fn_1_15248((void *)&a, (void *)&b, (void *)pp, 4, 2.5f)) {
                    if (obj->flags & 0x40000000) {
                        result |= 0x80;
                    } else {
                        result |= 0x4000;
                        *arg0 = obj->pos;
                        obj->flags |= 0x20000000;
                    }
                    a = save2;
                }
            }
            pp = model->polys58;
            for (j = 0; j < model->n58; j++, pp += 0x58) {
                if (fn_1_15248((void *)&a, (void *)&b, (void *)pp, 3, 2.5f)) {
                    if (obj->flags & 0x40000000) {
                        result |= 0x80;
                    } else {
                        result |= 0x4000;
                        *arg0 = obj->pos;
                        obj->flags |= 0x20000000;
                    }
                    a = save2;
                }
            }
        }
    }
    return result;
}
/* fzgx:end fn_1_163BC */

/* fzgx:begin fn_1_16BA0 */
#define GAME_VEC3_H

/* end game/vec3.h */

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

s32 fn_1_16BA0(Vec3 *pos, f32 *ratio, s32 idx, s32 *sub, s32 strict) {
    f32 thr;
    f32 neg;
    f32 a;
    f32 b;
    f32 z;
    f32 bz;
    f32 az;
    f32 ay;
    f32 y;
    f32 by;
    f32 ax;
    f32 x;
    f32 bx;
    f32 sb;
    f32 sa;
    s32 result;
    s32 flag;
    s32 i;
    s32 count;
    s32 cur;
    s32 n;
    s32 first;
    fn_1_16BA0_Seg *segs;
    fn_1_16BA0_Plane *p;
    s32 j;
    s32 k;
    s32 back;
    s32 fwd;

    if (fn_1_7B054() == 25) {
        thr = 1.7f;
    } else {
        thr = 0.001f;
    }
    *ratio = 0.0f;
    count = lbl_1_bss_3BE0->unk_8;
    segs = (fn_1_16BA0_Seg *)lbl_1_bss_3BE0->unk_C;
    if (idx < 0 || count <= idx) {
        idx = 0;
    }
    result = -1;
    cur = *sub;
    flag = lbl_1_bss_3BE0->unk_7D;
    if (cur == 0) {
        cur = 1;
    }
    n = 10;
    if (count < 10) {
        n = count;
    }
    neg = -thr;
    first = segs[idx].count;
    for (i = 0; i < n; i++) {
        j = (idx + count) % count;
        if (strict != 0 && first != segs[j].count) {
            break;
        }
        if (cur != 0 && segs[j].count <= cur) {
            k = segs[j].count - 1;
        } else {
            k = cur;
        }
        p = &segs[j].planes[k];
        x = pos->x;
        y = pos->y;
        z = pos->z;
        ax = p->ax;
        bx = p->bx;
        sa = x * ax;
        ay = p->ay;
        sb = x * bx;
        by = p->by;
        az = p->az;
        sa += y * ay;
        sb += y * by;
        bz = p->bz;
        sa += z * az;
        sb += z * bz;
        a = p->a0 + sa;
        b = p->b0 + sb;
        if (j == 0) {
            fwd = neg <= b;
            back = z < 0.0f;
            if (flag != 0) {
                back = 1;
            }
        } else if (j == count - 1) {
            fwd = z >= 0.0f;
            back = neg <= a;
            if (flag != 0 && fn_1_7B054() != 41) {
                fwd = 1;
            }
        } else {
            fwd = neg <= b;
            back = neg <= a;
        }
        if (fwd == 0) {
            if (strict != 0 && p->canFwd == 0) {
                break;
            }
            idx++;
        } else if (back == 0) {
            if (strict != 0 && p->canBack == 0) {
                break;
            }
            idx--;
        } else {
            *sub = k;
            result = j;
            *ratio = a / (a + b);
            break;
        }
    }
    return result;
}

#pragma opt_propagation reset
#undef GAME_VEC3_H
/* fzgx:end fn_1_16BA0 */

/* fzgx:begin fn_1_16E68 */
/* signed distances of the point to the segment's two boundary planes */

#define PLANE1(v, p) ny = (p)->n1y; nz = (p)->n1z; dot = x * (p)->n1x; dot = y * ny + dot; dot = z * nz + dot; v = (p)->d1 + dot

#define PLANE2(v, p) ny = (p)->n2y; nz = (p)->n2z; dot = x * (p)->n2x; dot = y * ny + dot; dot = z * nz + dot; v = (p)->d2 + dot

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

f32 fn_1_16E68(Vec3 *pos, s32 idx, s32 sub) {
    f32 thresh;
    s32 count;
    StcoliPlanePair *p;
    StcoliSegment *seg;
    f32 nz20;
    f32 ny20;
    f32 y0;
    f32 x0;
    f32 dot20;
    f32 nz10;
    f32 ny10;
    f32 dot10;
    f32 nz11;
    f32 ny11;
    f32 dot11;
    f32 nz21;
    f32 ny21;
    f32 y1;
    f32 x1;
    f32 dot21;
    f32 z2;
    f32 y2;
    f32 x2;
    f32 dot22;
    f32 negThresh;
    f32 nz12;
    f32 ny12;
    f32 dot12;
    f32 a;
    f32 b;

    if (fn_1_7B054() == 25) {
        thresh = 1.7f;
    } else {
        thresh = 0.001f;
    }
    count = lbl_1_bss_3BE0->unk_8;
    if (idx < 0 || count <= idx) {
        idx = 0;
    }
    seg = (StcoliSegment *)lbl_1_bss_3BE0->unk_C;
    p = seg[idx].planes + sub;

    if (idx == 0) {
        if (!(pos->z < 0.0f)) {
            return 0.0f;
        }
        x0 = pos->x;
        y0 = pos->y;
        ny20 = p->n2y;
        nz20 = p->n2z;
        dot20 = x0 * p->n2x;
        dot20 = y0 * ny20 + dot20;
        dot20 = pos->z * nz20 + dot20;
        b = p->d2 + dot20;
        if (!(-thresh <= b)) {
            return 1.0f;
        }
        ny10 = p->n1y;
        nz10 = p->n1z;
        dot10 = x0 * p->n1x;
        dot10 = y0 * ny10 + dot10;
        dot10 = pos->z * nz10 + dot10;
        a = p->d1 + dot10;
    } else if (idx == count - 1) {
        if (!(pos->z >= 0.0f)) {
            return 1.0f;
        }
        x1 = pos->x;
        y1 = pos->y;
        ny21 = p->n1y;
        nz21 = p->n1z;
        dot21 = x1 * p->n1x;
        dot21 = y1 * ny21 + dot21;
        dot21 = pos->z * nz21 + dot21;
        a = p->d1 + dot21;
        if (!(-thresh <= a)) {
            return 0.0f;
        }
        ny11 = p->n2y;
        nz11 = p->n2z;
        dot11 = x1 * p->n2x;
        dot11 = y1 * ny11 + dot11;
        dot11 = pos->z * nz11 + dot11;
        b = p->d2 + dot11;
    } else {
        x2 = pos->x;
        y2 = pos->y;
        z2 = pos->z;
        negThresh = -thresh;
        dot22 = x2 * p->n2x;
        dot22 = y2 * p->n2y + dot22;
        dot22 = z2 * p->n2z + dot22;
        b = p->d2 + dot22;
        if (!(negThresh <= b)) {
            return 1.0f;
        }
        ny12 = p->n1y;
        nz12 = p->n1z;
        dot12 = x2 * p->n1x;
        dot12 = y2 * ny12 + dot12;
        dot12 = z2 * nz12 + dot12;
        a = p->d1 + dot12;
        if (!(negThresh <= a)) {
            return 0.0f;
        }
    }
    return a / (a + b);
}

#pragma opt_propagation reset
#undef PLANE1
#undef PLANE2
/* fzgx:end fn_1_16E68 */

/* fzgx:begin fn_1_17098 */
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

/* FILE-SCOPE */ typedef void (*ColiDispatch)(void *, u32, u32, struct Sig_fn_1_18B40_fn_1_18B40_Obj *, f32, struct Sig_fn_1_18B40_fn_1_18B40_Vec *, ColiContext *, void *, s32);

static inline u32 coli_bit(u32 flags, s32 bit) {
    return __rlwnm(flags, (bit + 1) & 31, 31, 31);
}

static inline void coli_dispatch(void *arg0, u32 arg1, u32 flags, struct Sig_fn_1_18B40_fn_1_18B40_Obj *obj, struct Sig_fn_1_18B40_fn_1_18B40_Vec *vector, ColiContext *ctx, void *arg6, s32 index, f32 t) {
    ((f32 *)vector)[0] = 1.0f;
    ((f32 *)vector)[1] = 1.0f;
    ((f32 *)vector)[2] = 1.0f;
    lbl_1_data_5548[__cntlzw(obj->flags & 0x3FE0000)](arg0, (void *)arg1, flags, obj, vector, ctx, arg6, index, t);
}

static inline s32 coli_selective(u32 flags) {
    s32 enabled = 0;
    if (flags & 0x1800000) {
        if (flags & 0xF8000000) enabled = 1;
    }
    return enabled;
}

static inline void coli_skip(ColiContext *ctx) {
    f32 time = 1.0f;
    ctx->result->values[ctx->result->count] = 0;
    ctx->result->times[ctx->result->count] = time;
    ctx->result->masks[ctx->result->count] = 0;
    ctx->result->ids[ctx->result->count] = -1;
    if (ctx->result->count < 3) ctx->result->count++;
}

u32 fn_1_17098(void *arg0, u32 arg1, u32 v1, u32 arg3, u32 arg4, ColiContext *ctx, void *arg6) {
    s32 v0;
    s32 i;
    s32 last;
    s32 first;
    s32 missed = 0;
    s32 index;
    void *point;
    struct Sig_fn_1_18B40_fn_1_18B40_Obj *obj;
    s32 *list = (s32 *)arg3;
    u32 maskA, maskB, maskC;
    f32 time;
    f32 t;
    s32 item;
    f32 tmpTime;
    s32 tmpItem;
    f32 vector[3];
    struct Sig_fn_1_18B40_fn_1_18B40_Vec mid;
    s32 currentItem;
    ColiEntry *entry;
    ColiRange *range;
    ColiContact *best;
    ColiContact *rec;
    s32 result;
    if (ctx != 0) {
        ctx->result->count = 0;
        ctx->result->flags = 0;
        ctx->result->any = 0;
    }
    if (arg6 != 0) *(u32 *)arg6 = 0;
    v0 = coli_selective(v1);
    if (v0 != 0) {
        u32 bit = __rlwnm(v1, 1, 31, 31) != 0;
        v1 |= 0x80000000U >> bit;
    }
    if ((s32)arg4 > 1) {
        last = arg4 - 1;
        first = 1;
        lbl_801A66CC->count = last;
    } else {
        first = 0;
        last = 0;
        lbl_801A66CC->count = 1;
    }
    for (i = first; i <= last; i++) {
        item = i;
        index = list[i];
        if (v0 && !coli_bit(v1, i)) index = -1;
        if (index < 0) {
            if (ctx) coli_skip(ctx);
            missed++;
            continue;
        }
        if (v1 & 0x80000) {
            lbl_8006D5A4(arg0, arg1, &mid, 0.5f);
            point = &mid;
        } else if (v1 & 0x40000) {
            point = (void *)arg1;
        } else {
            point = arg0;
        }
        if (v1 & 0x20000) {
            tmpItem = item;
            result = ((int)fn_1_16BA0((void *)point, (void *)&tmpTime, (s32)((void *)index), (void *)&tmpItem, 1));
            if (result < 0) {
                time = fn_1_16E68((void *)point, (s32)((void *)index), item);
            } else {
                index = result;
                time = tmpTime;
                item = tmpItem;
            }
        } else {
            index = ((int)fn_1_16BA0((void *)point, (void *)&time, (s32)((void *)index), (void *)&item, 0));
        }
        if (index < 0) {
            if (ctx) coli_skip(ctx);
            missed++;
            continue;
        }
        currentItem = item;
        entry = &((ColiEntry *)lbl_1_bss_3BE0->unk_C)[index];
        range = entry->ranges;
        obj = entry->obj;
        t = range->a + (f32)(time * (range->b - range->a));
        if (currentItem != 0 && obj->unk_4C != 0 && obj->unk_4C != currentItem) continue;
        if (obj->flags & 2) continue;
        lbl_801A66CC->index = currentItem;
        lbl_801A66CC->segment = index;
        lbl_801A66CC->time = time;
        result = 0;
        if (range[item].enabledA && range[item].enabledB) result = 1;
        lbl_801A66CC->enabled = result;
        if (ctx && lbl_801A66CC->count == *ctx->other) {
            if (fn_1_7B054() == 0x18) {
                if ((index >= 2 && index <= 0x1c) ||
                    (index >= 0x1f && index <= 0x33) ||
                    (index >= 0x3a && index <= 0xa3) ||
                    (index >= 0xa7 && index <= 0xb7)) {
                    lbl_801A66CC->enabled = 0;
                }
            } else if (fn_1_7B054() != 8) {
                lbl_801A66CC->enabled = 0;
            }
        }
        lbl_8006D758();
        {
            struct Sig_fn_1_18B40_fn_1_18B40_Vec * output;
            output = (struct Sig_fn_1_18B40_fn_1_18B40_Vec *)vector;
            coli_dispatch(arg0, arg1, v1, obj, output, ctx, arg6, index, t);
        }
        fn_1_18B40(arg0, (void *)arg1, v1, (void *)obj, (void *)((struct Sig_fn_1_18B40_fn_1_18B40_Vec *)vector), item, ctx, arg6, t, index);
        lbl_801A66CC->total++;
    }
    lbl_801A66CC->total += missed;
    if (ctx) {
        if (ctx->result->any) {
            for (i = 0; i < ctx->result->count; i++) {
                if (ctx->result->masks[i] & 0x2200000) ctx->result->masks[i] |= 0x20000000;
            }
        }
        for (i = 0; i < ctx->result->count; i++) {
            if (ctx->result->masks[i] & 0xF0000000) ctx->result->flags |= ctx->result->masks[i];
        }
        if (v0 && (ctx->result->flags & 0xF0000000) != 0xF0000000) {
            return fn_1_17098(arg0, arg1, v1 & 0x7FFFFFF, arg3, arg4, ctx, arg6);
        }
    }
    best = 0;
    rec = lbl_801A66CC->contacts;
    for (i = 0; i < lbl_801A66CC->num_contacts; i++, rec++) {
        if (rec->flags && (!best || rec->t < best->t)) best = rec;
    }
    if (best) {
        lbl_801A66CC->hits[2] = *best;
        if (ctx) {
            rec = lbl_801A66CC->contacts;
            for (i = 0; i < lbl_801A66CC->num_contacts; i++, rec++) {
                if (rec->flags && rec != best) {
                    ctx->result->masks[lbl_801A66CC->contact_ids[i]] &= 0xFFFFFFF;
                }
            }
        }
    }
    result = 0;
    if ((v1 & 5) == 5) {
        if (lbl_801A66CC->hits[1].flags || lbl_801A66CC->hits[2].flags) {
            rec = &lbl_801A66CC->hits[1];
            i = 0;
            if (!rec->flags) {
                i = 1;
                rec++;
                if (!rec->flags) {
                    i = 2;
                    rec++;
                }
            }
            best = rec;
            for (; i < 2; i++, rec++) {
                if (rec->flags && rec->t < best->t) best = rec;
            }
            lbl_801A66CC->hits[3] = *best;
            result = 1;
        }
    } else if ((v1 & 1) && lbl_801A66CC->hits[1].flags) {
        lbl_801A66CC->hits[3] = lbl_801A66CC->hits[1];
        result = 1;
    } else if ((v1 & 4) && lbl_801A66CC->hits[2].flags) {
        lbl_801A66CC->hits[3] = lbl_801A66CC->hits[2];
        result = 1;
    }
    return result;
}
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H
/* fzgx:end fn_1_17098 */

/* fzgx:begin fn_1_17920 */
/* one 12-byte entry of the table at lbl_1_bss_3BE0->unk_C */

/* one of the five 0x48-byte result slots */

/* local view of the collision work area at [lbl_801A66CC]; the track query's area starts at +0x1B0 */

void fn_1_17920(s32 index, void *arg1, f32 t) {
    fn_1_17920_Slot *table;
    fn_1_17920_Record *rec;
    void *node;
    f32 pos;
    f32 *p;
    Vec3 scale;
    s32 i;

    table = (fn_1_17920_Slot *)lbl_1_bss_3BE0->unk_C;
    rec = table[index].unk_4;
    node = table[index].unk_8;
    pos = rec->unk_0 + (f32)(t * (rec->unk_4 - rec->unk_0));
    lbl_801A66CC->unk_1C8 = 0;
    lbl_801A66CC->total = 0;
    lbl_801A66CC->num_volumes = 0;
    lbl_801A66CC->flags = 0;
    lbl_801A66CC->probes[0].mask = 0;
    lbl_801A66CC->num_contacts = 0;
    for (i = 0; i < 5; i++) {
        ColiContact *r = &lbl_801A66CC->hits[i];
        r->flags = 0;
        r->t = -1.0f;
    }
    lbl_801A66CC->radius = 2.0f;
    lbl_801A66CC->unk_1B4 = 0.0f;
    lbl_8006D758();
    /* filled through a pointer: retail computes &scale before the call's other arguments */
    p = &scale.x;
    for (i = 0; i < 3; i++) {
        p[i] = 1.0f;
    }
    lbl_801A66CC->index = 1;
    fn_1_1902C((void *)node, (void *)&scale, (void *)arg1, pos);
    lbl_801A66CC->total++;
    lbl_801A66CC->count = lbl_801A66CC->total > 1 ? lbl_801A66CC->total - 1 : lbl_801A66CC->total;
}
/* fzgx:end fn_1_17920 */

/* fzgx:begin fn_1_17A9C */
static inline f32 vec_dist(const f32 *a, const f32 *b)
{
    f32 dx = a[0];
    f32 dy;
    f32 dz;
    dx -= b[0];
    dy = a[1];
    dy -= b[1];
    dz = a[2];
    dz -= b[2];
    dx = dx * dx;
    dx = dx + dy * dy;
    dx = dx + dz * dz;
    return dx;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off

s32 fn_1_17A9C(const f32 *arg0)
{
    s32 n;
    ColiWork *obj = lbl_801A66CC;
    u8 *cur;
    s32 best;
    f32 bd, d;
    s32 i;

    n = obj->total;
    if (n <= 1) {
        best = 0;
    } else {
        bd = vec_dist(arg0, &obj->probes[1].v0.x);
        best = 1;
        cur = (u8 *)obj + 0x2b0;
        for (i = 2; i < n; i++) {
            d = vec_dist(arg0, (const f32 *)(cur + 0x444));
            if (bd > d) {
                best = i;
                bd = d;
            }
            cur += 0x80;
        }
    }
    return best;
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_17A9C */

/* fzgx:begin fn_1_17B5C */
int fn_1_17B5C(int a, int b, int count, f32 threshold) {
    int end;
    int span;
    int j;
    int found;
    int result;
    Fn17B5C_Slot *left;
    Fn17B5C_Slot *right;
    f32 delta;

    if (a == b) {
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    span = b - a;
    {
        int diff = count - span;
        if (diff < span) {
            int temp = a;
            a = b;
            b = temp;
            span = diff;
        }
    }

    left = &((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[a];
    right = &((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[b];
    if (threshold > 0.0f) {
        delta = right->unk_4->unk_40 - left->unk_4->unk_44;
        if (delta < 0.0f) {
            delta += *(f32 *)lbl_1_bss_3BE0->unk_90;
        }
        if (delta > threshold) {
            return 0;
        }
    }

    b = a + 1;
    end = count - 1;
    found = 0;
    for (j = 0; j < span; j++) {
        if (b > end) {
            b = 0;
        }
        if (!((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[a].unk_4->unk_4D) {
            break;
        }
        a = b;
        found++;
        b++;
    }

    result = 0;
    if (span == 0 || found >= span) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17B5C */

/* fzgx:begin fn_1_17C6C */
int fn_1_17C6C(int current, int next, int limit) {
    int end;
    int count;
    int span;
    int result;

    if (current == next) {
        return 1;
    }

    if (current > next) {
        int temp = current;
        current = next;
        next = temp;
    }

    span = next - current;
    {
        int diff = limit - span;
        if (diff < span) {
            current = next;
            span = diff;
        }
    }

    next = current + 1;
    count = 0;
    end = limit - 1;

    while (count < span) {
        if (next > end) {
            next = 0;
        }

        if (!((Root *)lbl_1_bss_3BE0)->slots[current].entry->active) {
            break;
        }
        if (current == 0x8b && fn_1_7B054() == 3) {
            break;
        }
        current = next;
        count++;
        next++;
    }

    result = 0;
    if (span == 0 || count >= span) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17C6C */

/* fzgx:begin fn_1_17D5C */
void fn_1_17D5C(Node *node, u32 *acc) {
    Node *root;
    s32 i1;
    Node *p1;
    Node *p2;
    s32 i2;
    Node *p3;
    s32 i3;
    Node *p4;
    s32 i4;
    Node *p5;
    s32 i5;
    Node *p6;
    s32 i6;
    Node *p7;
    s32 i7;
    Node *p8;
    s32 i8;
    Node *p9;
    s32 i9;

    root = node;
    *acc |= root->unk_0;
    if (root->count > 0) {
        i1 = 0;
        p1 = root->children;
        while (i1 < root->count) {
            *acc |= p1->unk_0;
            if (p1->count > 0) {
                p2 = p1->children;
                i2 = 0;
                while (i2 < p1->count) {
                    *acc |= p2->unk_0;
                    if (p2->count > 0) {
                        p3 = p2->children;
                        i3 = 0;
                        while (i3 < p2->count) {
                            *acc |= p3->unk_0;
                            if (p3->count > 0) {
                                p4 = p3->children;
                                i4 = 0;
                                while (i4 < p3->count) {
                                    *acc |= p4->unk_0;
                                    if (p4->count > 0) {
                                        p5 = p4->children;
                                        i5 = 0;
                                        while (i5 < p4->count) {
                                            *acc |= p5->unk_0;
                                            if (p5->count > 0) {
                                                p6 = p5->children;
                                                i6 = 0;
                                                while (i6 < p5->count) {
                                                    *acc |= p6->unk_0;
                                                    if (p6->count > 0) {
                                                        p7 = p6->children;
                                                        i7 = 0;
                                                        while (i7 < p6->count) {
                                                            *acc |= p7->unk_0;
                                                            if (p7->count > 0) {
                                                                p8 = p7->children;
                                                                i8 = 0;
                                                                while (i8 < p7->count) {
                                                                    *acc |= p8->unk_0;
                                                                    if (p8->count > 0) {
                                                                        p9 = p8->children;
                                                                        i9 = 0;
                                                                        while (i9 < p8->count) {
                                                                            fn_1_17D5C(p9, acc);
                                                                            i9++;
                                                                            p9++;
                                                                        }
                                                                    }
                                                                    i8++;
                                                                    p8++;
                                                                }
                                                            }
                                                            i7++;
                                                            p7++;
                                                        }
                                                    }
                                                    i6++;
                                                    p6++;
                                                }
                                            }
                                            i5++;
                                            p5++;
                                        }
                                    }
                                    i4++;
                                    p4++;
                                }
                            }
                            i3++;
                            p3++;
                        }
                    }
                    i2++;
                    p2++;
                }
            }
            i1++;
            p1++;
        }
    }
}
/* fzgx:end fn_1_17D5C */

/* fzgx:begin fn_1_17FCC */
int fn_1_17FCC(int a, int b, int c) {
    int count;
    int i;
    int end;
    fn_1_17FCC_StcoliEntry *last;
    fn_1_17FCC_StcoliEntry *entry;
    u32 fa;
    u32 fb;
    int result;

    if (a == b) {
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    count = b - a;
    i = c - count;
    if (i < count) {
        a = b;
        count = i;
    }
    b = a + 1;
    end = c;
    end = end - 1;
    last = (fn_1_17FCC_StcoliEntry *)lbl_1_bss_3BE0->unk_C + a;
    i = 0;
    while (i < count) {
        if (b > end) {
            b = 0;
        }
        entry = (fn_1_17FCC_StcoliEntry *)lbl_1_bss_3BE0->unk_C + b;
        fb = 0;
        fa = 0;
        fn_1_17D5C( (Node *)(last->unk_8), &fa);
        fn_1_17D5C( (Node *)(entry->unk_8), &fb);
        if ((fa & 0x01000000) != 0 && (fb & 0x00800000) != 0) {
            break;
        }
        if ((fb & 0x01000000) != 0 && (fa & 0x00800000) != 0) {
            break;
        }
        last = entry;
        i++;
        b++;
    }
    result = 0;
    if (count == 0 || i >= count) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17FCC */

/* fzgx:begin fn_1_180F4 */
int fn_1_180F4(int first, int second, int count, int ascending) {
    int wins;
    int current;
    int limit;
    int j;
    int tmp;
    Entry_180F4 *current_entry;
    Entry_180F4 *candidate;
    int result;

    if (first == second) {
        return 1;
    }

    if (first > second) {
        tmp = first;
        first = second;
        second = tmp;
    }

    current = second - first;
    limit = count - current;
    if (limit < current) {
        first = second;
        current = limit;
    }

    current_entry = &((Entry_180F4 *)lbl_1_bss_3BE0->unk_C)[first];
    wins = 0;
    second = first + 1;
    limit = count;
    limit -= 1;
    j = current;

    while (j > 0) {
        if (second > limit) {
            second = 0;
        }

        candidate = &((Entry_180F4 *)lbl_1_bss_3BE0->unk_C)[second];
        if (ascending) {
            if (current_entry->unk_0 < candidate->unk_0) {
                break;
            }
        } else if (current_entry->unk_0 > candidate->unk_0) {
            break;
        }

        current_entry = candidate;
        wins++;
        second++;
        j--;
    }

    result = 0;
    if (current == 0 || wins >= current) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_180F4 */

/* fzgx:begin fn_1_181CC */
// fn_1_181CC: main_rel .text:0x000181CC size 0x24

// Wrapper function that passes first three arguments through and sets fourth to 1

void fn_1_181CC(int a, int b, int c) {
    fn_1_180F4(a, b, c, 1);
}
/* fzgx:end fn_1_181CC */

/* fzgx:begin fn_1_181F0 */
void fn_1_181F0(int a, int b, int c) {
    fn_1_180F4(a, b, c, 0);
}
/* fzgx:end fn_1_181F0 */

/* fzgx:begin fn_1_18214 */
void fn_1_18214(Entity *arg0, f32 *arg1, Stack *arg2, f32 t) {
    Cfg *v0 = arg0->cfg;
    u8 *slot;
    f32 a;
    f32 b;
    f32 c;
    f32 r;

    if (arg2 != 0) {
        slot = (u8 *)arg2 + arg2->count * 36 + 44;
        if (arg2->entries[arg2->count] != (u32)arg0) {
            fn_80008BEC((u8 *)arg2 + arg2->count * 36 + 44, 0, (u32)((void *)36));
        }
        if (v0->f3c != 0) {
            a = fn_1_9E170(v0->f18, v0->f3c, slot, t);
        } else {
            a = arg0->sxv;
        }
        if (v0->f40 != 0) {
            b = fn_1_9E170(v0->f1c, v0->f40, slot + 4, t);
        } else {
            b = arg0->syv;
        }
        if (v0->f44 != 0) {
            c = fn_1_9E170(v0->f20, v0->f44, slot + 8, t);
        } else {
            c = arg0->szv;
        }
        if (0.0f != a || 0.0f != b || 0.0f != c) {
            lbl_8006E0B4(arg1[0] * a, arg1[1] * b, arg1[2] * c);
        }
        if (v0->f30 != 0) {
            a = fn_1_9E170(v0->f0c, v0->f30, slot + 12, t);
        } else {
            a = arg0->rxv;
        }
        if (v0->f34 != 0) {
            b = fn_1_9E170(v0->f10, v0->f34, slot + 16, t);
        } else {
            b = arg0->ryv;
        }
        if (v0->f38 != 0) {
            c = fn_1_9E170(v0->f14, v0->f38, slot + 20, t);
        } else {
            c = arg0->rzv;
        }
        if (0.0f != c) {
            if (((s32)(182.04445f * c) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_z((s16)(u16)(s32)(182.04445f * c));
            }
        }
        if (0.0f != b) {
            if (((s32)(182.04445f * b) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_y((s16)(u16)(s32)(182.04445f * b));
            }
        }
        if (0.0f != a) {
            if (((s32)(182.04445f * a) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_x((s16)(u16)(s32)(182.04445f * a));
            }
        }
        if (v0->f24 != 0) {
            r = fn_1_9E170(v0->f00, v0->f24, slot + 24, t);
        } else {
            r = arg0->fx;
        }
        arg1[0] = arg1[0] * r;
        if (v0->f28 != 0) {
            r = fn_1_9E170(v0->f04, v0->f28, slot + 28, t);
        } else {
            r = arg0->fy;
        }
        arg1[1] = arg1[1] * r;
        if (v0->f2c != 0) {
            r = fn_1_9E170(v0->f08, v0->f2c, slot + 32, t);
        } else {
            r = arg0->fz;
        }
        arg1[2] = arg1[2] * r;
    } else {
        if (v0->f3c != 0) {
            a = fn_1_9E14C(v0->f18, v0->f3c, t);
        } else {
            a = arg0->sxv;
        }
        if (v0->f40 != 0) {
            b = fn_1_9E14C(v0->f1c, v0->f40, t);
        } else {
            b = arg0->syv;
        }
        if (v0->f44 != 0) {
            c = fn_1_9E14C(v0->f20, v0->f44, t);
        } else {
            c = arg0->szv;
        }
        if (0.0f != a || 0.0f != b || 0.0f != c) {
            lbl_8006E0B4(arg1[0] * a, arg1[1] * b, arg1[2] * c);
        }
        if (v0->f30 != 0) {
            b = fn_1_9E14C(v0->f0c, v0->f30, t);
        } else {
            b = arg0->rxv;
        }
        if (v0->f34 != 0) {
            a = fn_1_9E14C(v0->f10, v0->f34, t);
        } else {
            a = arg0->ryv;
        }
        if (v0->f38 != 0) {
            c = fn_1_9E14C(v0->f14, v0->f38, t);
        } else {
            c = arg0->rzv;
        }
        if (0.0f != c) {
            if (((s32)(182.04445f * c) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_z((s16)(u16)(s32)(182.04445f * c));
            }
        }
        if (0.0f != a) {
            if (((s32)(182.04445f * a) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_y((s16)(u16)(s32)(182.04445f * a));
            }
        }
        if (0.0f != b) {
            if (((s32)(182.04445f * b) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_x((s16)(u16)(s32)(182.04445f * b));
            }
        }
        if (v0->f24 != 0) {
            r = fn_1_9E14C(v0->f00, v0->f24, t);
        } else {
            r = arg0->fx;
        }
        arg1[0] = arg1[0] * r;
        if (v0->f28 != 0) {
            r = fn_1_9E14C(v0->f04, v0->f28, t);
        } else {
            r = arg0->fy;
        }
        arg1[1] = arg1[1] * r;
        if (v0->f2c != 0) {
            r = fn_1_9E14C(v0->f08, v0->f2c, t);
        } else {
            r = arg0->fz;
        }
        arg1[2] = arg1[2] * r;
    }
    if (arg2 != 0) {
        arg2->entries[arg2->count] = (u32)arg0;
        if ((s32)arg2->count < 9) {
            arg2->count = arg2->count + 1;
        }
    }
}
/* fzgx:end fn_1_18214 */

/* fzgx:begin fn_1_18784 */
/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_18784(u32 arg0, Motion *a, Vec3 *b, void *c, f32 d)
{
    ColiProbe *p;
    ColiProbe *q;
    u32 mask;
    fn_1_18784_Cfg *cf;
    f64 tmp___fabs;
    f32 scx;
    f32 s2;
    f32 ax;
    f32 ay;
    f32 sm;
    f32 px;

    if ((arg0 & 0x800000) != 0) {
        q = &lbl_801A66CC->probes[lbl_801A66CC->total];
    } else {
        q = NULL;
    }
    p = q;
    mask = a->f00 & 0x07E00C01;
    lbl_801A66CC->unk_1C8 |= mask;
    if ((a->f00 & 0x4000000) != 0) {
        ColiWork *m = lbl_801A66CC;
        if (m->index == 1 || (m->index > 1 && m->total == 0)) {
            if (m->total < 3) {
                m->total = m->total + 1;
                if (p != 0) {
                    p[1].mask = 0;
                    p++;
                }
            }
        }
    }
    if ((a->f00 & 0x600000) == 0) {
        fn_1_18214((void *)a, (void *)b, (void *)c, d);
        if (p != 0) {
            f32 *mtx;
            lbl_8006DB74((void *)p);
            /* Locked cache: the current matrix at 0xE0000000 is not a data symbol. */
            mtx = (f32 *)(0xE0000000 + 0);
            p->pos = *b;
            psvec_set(&p->v0.x, mtx[11], mtx[7], mtx[3]);
            p->e.x = -lbl_801A6D00[2];
            p->e.y = -lbl_801A6D00[6];
            p->e.z = -lbl_801A6D00[10];
            p->m.x = lbl_801A6D00[1];
            p->m.y = lbl_801A6D00[5];
            p->m.z = lbl_801A6D00[9];
        }
    }
    if ((a->f00 & 0x400000) != 0) {
        cf = a->cfg;
        scx = (cf->f3c != 0) ? fn_1_9E14C(cf->f18, cf->f3c, d) : a->f2c;
        scx = 2.0f * scx;
        s2 = (cf->f28 != 0) ? fn_1_9E14C(cf->f04, cf->f28, d) : a->f18;
{
    f32 bx;
        bx = b->x;
        sm = scx + s2;
        scx = scx * bx;
        tmp___fabs = __fabs(scx);
        ax = tmp___fabs;
        tmp___fabs = __fabs(s2 * b->y);
        ay = tmp___fabs;
        px = bx * sm;
}
        lbl_801A66CC->unk_1DC = ax;
        lbl_801A66CC->unk_1E0 = ay;
        if (p != 0) {
            p->ax = ax;
            p->ay = ay;
        }
    }
    if (p != 0) {
        p->mask |= mask;
        if ((a->f00 & 0x800000) != 0 && a->f0c == 1) {
            fn_1_18784_Cfg *c2 = ((Src *)a->f10)->cfg;
            p->d0 = b->x;
            p->d1 = (c2->f28 != 0) ? fn_1_9E14C(c2->f04, c2->f28, d) : ((Src *)a->f10)->f18;
        } else if ((a->f00 & 0x200000) == 0) {
            p->d0 = (a->f00 & 0x400000) ? px : b->x;
            p->d1 = 1.0f;
        }
        if ((a->f00 & 0x400000) != 0) {
            psvec_scale_add(&p->v0.x, &p->m.x, -0.5f * p->ay, &p->o.x);
        } else if ((a->f00 & 0x1800000) != 0) {
            psvec_scale_add(&p->v0.x, &p->m.x, -0.5f * b->y, &p->o.x);
        } else {
            p->o = p->v0;
        }
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_18784 */

/* fzgx:begin fn_1_18B40 */
/* WARNING: compiler-diff device, not original code */
#pragma opt_loop_invariants off
/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off
void fn_1_18B40(void * arg0, void * arg1, u32 arg2, struct fn_1_18B40_Obj *arg3, struct fn_1_18B40_Vec *arg4, int arg5, void * arg6, void * arg7, f32 arg8, u32 arg9) {
    struct fn_1_18B40_Vec saved;
    int i;
    struct fn_1_18B40_Obj *entry;

    if (arg3->count > 0) {
        lbl_8006DAEC();
        entry = arg3->entries;
        i = 0;
        while (i < arg3->count) {
            if (arg5 == 0 || entry->unk_4C == 0 || entry->unk_4C == arg5) {
                if ((entry->flags & 0x2) == 0) {
                    saved = *arg4;
                    lbl_8006DBE4();
                    lbl_1_data_5548[__cntlzw(entry->flags & 0x3FE0000)](arg0, arg1, arg2, entry, arg4, arg6, arg7, arg9, arg8);
                    fn_1_18B40(arg0, arg1, arg2, entry, arg4, arg5, arg6, arg7, arg8, arg9);
                    *arg4 = saved;
                }
            }
            i++;
            entry++;
        }
        lbl_8006DB30();
    }
}
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_18B40 */

/* fzgx:begin fn_1_18F28 */
void fn_1_18F28(StcoliNode *node, StcoliVec *vec, void *arg3, f32 value) {
    StcoliVec saved;
    s32 i;
    StcoliNode *child;

    if (node->count > 0) {
        lbl_8006DAEC();
        child = node->items;
        i = 0;
        while (i < node->count) {
            if ((child->flags & 0x1e0002) == 0) {
                saved = *vec;
                lbl_8006DBE4();
                fn_1_1902C(child, vec, arg3, value);
                *vec = saved;
            }
            i++;
            child++;
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_18F28 */

/* fzgx:begin fn_1_18FFC */
void fn_1_18FFC(Vec3 *arg0, Vec3 *arg1, u32 arg2, void *arg3, Vec3 *arg4, void *arg5, void *arg6, s32 arg7, f32 arg8) {
    fn_1_18784(arg2, arg3, arg4, arg6, arg8);
}
/* fzgx:end fn_1_18FFC */

/* fzgx:begin fn_1_1902C */
void fn_1_1902C(StcoliNode *node, StcoliVec *vec, void *arg3, f32 value) {
    fn_1_18784(0x800000, (void *)node, (void *)vec, NULL, value);
    fn_1_18F28(node, vec, arg3, value);
}
/* fzgx:end fn_1_1902C */

/* fzgx:begin fn_1_192E8 */
/* begin game/vec3.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define fabsf(x) __fabsf(x)

static inline int fn_1_192E8_allowed(struct fn_1_192E8_Context *ctx,
    struct fn_1_192E8_Arg4 *wall, int id, int side)
{
    s32 index;
    s32 count;
    u32 needed;
    u32 flags;
    u32 mask;
    s32 other;
    s32 mode;
    if (ctx == 0) return 0;
    index = ctx->node->index;
    count = ctx->table->count;
    flags = ctx->table->flags[index];
    if (count <= index) return 0;
    if (!__rlwnm(flags, (side + 1) & 31, 31, 31)) return 0;
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) mask |= 0xC00;
    needed = wall->unk_0 & mask;
    other = ctx->table->ids[index];
    if (needed == (needed & flags)) {
        if (ctx->table->objects[index] != wall) {
            if (!fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f)) goto failed; /* Keep the verified branch to failed. */
        }
        if (fn_1_7B054() == 0x10) {
            if (id >= 0x5F && id <= 0x79 && !(other >= 0x5F && other <= 0x79)) {
                mode = lbl_801A66CC->index;
                if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
            }
            return 1;
        } else if (fn_1_7B054() == 0x1C) {
            if (id >= 0x74 && id <= 0x90) {
                if (other < 0x74) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                }
                if (other > 0x90) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                return 1;
            } else if (id >= 0xA8 && id <= 0xC6) {
                if (other < 0xA8) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                if (other > 0xC6) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                }
                return 1;
            }
            return 1;
        }
        return 1;
    }
failed:
    return 0;
}

static inline void fn_1_192E8_normal(Vec3 *out, f32 scale)
{
    f32 x, y, z;
    x = *(f32 *)LC_BASE;
    y = *(f32 *)(LC_BASE + 0x10);
    z = *(f32 *)(LC_BASE + 0x20);
    x *= scale;
    y *= scale;
    z *= scale;
    out->x = x;
    out->y = y;
    out->z = z;
}

int fn_1_192E8(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2, Vec3 *arg3,
    struct fn_1_192E8_Arg4 *arg4, f32 *arg5, struct fn_1_192E8_Context *arg6,
    int arg7, u32 *arg9_input, int arg10_input, f32 arg8)
{
    f32 dot_z, dot_y, dot_x;
    f32 v0;
    f32 v1;
    int hit;
    u32 v2;
    u32 v3;
    int arg10 = arg10_input;
    u32 *arg9 = arg9_input;
    int v4;
    f32 t;
    f32 limit;
    Vec3 position;
    Vec3 normal;
    union { f32 f; u32 u; } bits;
    s32 i;
    f32 half;
    f32 height;
    f32 width;
    ColiContact *contact;
    s32 *index_ptr;
    f32 depth;
    f32 scale;
    v0 = (0.5f * arg8);
    v1 = 0.5f;
    if (arg8 > 0.0f) {
        v1 = -0.5f;
        v2 = 0;
        v3 = 1024;
        limit = arg4->unk_40;
        v4 = v1 >= arg2->x;
        hit = v4 && arg3->x >= v1;
    } else {
        v2 = 1;
        v3 = 2048;
        limit = arg4->unk_3C;
        v4 = v1 <= arg2->x;
        hit = v4 && arg3->x <= v1;
    }
    if (hit) {
        t = (arg3->x + v0) / (arg3->x - arg2->x);
        bits.f = t;
        if ((bits.u & 0x7F800000) != 0x7F800000 &&
            (!arg10 || fabsf(arg3->y + (f32)(t * (arg2->y - arg3->y))) <= limit)) {
            hit = 1;
        } else {
            hit = 0;
        }
        *arg9 |= 0x80000000U >> v2;
    }
    if (!hit && v4 && fn_1_192E8_allowed(arg6, arg4, arg7, v2)) {
        if (!arg10 || fabsf(arg2->y) <= limit || fabsf(arg3->y) <= limit) {
            *arg9 |= 0x80000000U >> v2;
            t = 0.0f;
            hit = 1;
        }
    }
    if (hit) {
        lbl_8006E1D8(&position, *arg5 * (0.5f * -arg8),
            0.0f, 0.0f);
        if (lbl_801A66CC->num_volumes > 0) {
            lbl_8006DAEC();
            half = 0.5f;
            for (i = 0; i < lbl_801A66CC->num_volumes; i++) {
                lbl_8006DBAC((void *)&lbl_801A66CC->volumes[i].mtx);
                width = half * lbl_801A66CC->volumes[i].scale.x;
                height = lbl_801A66CC->volumes[i].height;
                lbl_8006E1B0((void *)((Vec3 *)&position), (void *)((Vec3 *)&lbl_801A66CC->delta));
                if (fabsf(lbl_801A66CC->delta.x) <= width - 0.1f &&
                    fabsf(lbl_801A66CC->delta.y) <= height) {
                    if (arg6 != 0) arg6->node->unk_8 = 1;
                    *arg9 &= ~(0x80000000U >> v2);
                    hit = 0;
                    break;
                }
            }
            lbl_8006DB30();
        }
        if (hit) {
            fn_1_192E8_normal(&normal, arg8);
            if (arg6 != 0) {
                dot_x = arg6->table->normal.x;
                /* Keep the normal's y read in the scalar dot-product local. */
                /* WARNING: compiler-diff device, not original code */
                dot_y = *(volatile f32 *)&arg6->table->normal.y;
                dot_x = (dot_x * normal.x);
                /* The z read follows the first product in the dot kernel. */
                /* WARNING: compiler-diff device, not original code */
                dot_z = *(volatile f32 *)&arg6->table->normal.z;
                dot_x = dot_y * normal.y + dot_x;
                dot_x = dot_z * normal.z + dot_x;
                if (dot_x < 0.0f) {
                    *arg9 &= ~(0x80000000U >> v2);
                    hit = 0;
                }
            }
        }
        if (hit) {
            f32 zero;
            contact = &lbl_801A66CC->contacts[lbl_801A66CC->num_contacts];
            contact->flags = 0;
            contact->t = -1.0f;
            zero = 0.0f;
            index_ptr = &lbl_801A66CC->contact_ids[lbl_801A66CC->num_contacts++];
            contact->position = position;
            psvec_sub_scale_add(arg0, arg1, t, &position, &contact->point);
            contact->normal = normal;
            depth = (f32)(*arg5 * (arg8 * (v0 + arg2->x))) - 0.5f;
            if (depth < zero) {
                scale = arg8 * -depth;
                fn_1_192E8_normal(&contact->correction, scale);
            } else {
                contact->correction.x = zero;
                contact->correction.y = zero;
                contact->correction.z = zero;
            }
            contact->t = t;
            contact->flags = v3;
            contact->unk_0 = lbl_801A66CC->index;
            contact->unk_4 = lbl_801A66CC->segment;
            contact->unk_8 = lbl_801A66CC->time;
            contact->link = arg6 != 0 ? &arg6->node->links[arg6->node->index] : 0;
            *index_ptr = arg6 != 0 ? arg6->node->index : 0;
        }
    }
    return hit;
}
#undef GAME_VEC3_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef fabsf
/* fzgx:end fn_1_192E8 */

/* fzgx:begin fn_1_19AE0 */
#define GAME_VEC3_H

#define LC ((f32 *)LC_BASE)

static inline int fn_1_19AE0_finite(f32 x)
{
    union { f32 f; u32 u; } bits;
    bits.f = x;
    return (bits.u & 0x7F800000) != 0x7F800000;
}

static inline int fn_1_19AE0_match(Ctx *ctx, Seg *seg, s32 id)
{
    s32 index;
    s32 count;
    u32 flags;
    u32 needed;
    if (ctx == NULL) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index || !__rlwnm(flags, 3, 31, 31)) {
        if (lbl_801A66CC->enabled == 0) return 0;
        for (index = 0; index < count; index++) {
            flags = ctx->unk_4->unk_3C[index];
            if (__rlwnm(flags, 3, 31, 31)) break;
        }
        if (index >= count) return 0;
    }
    if (flags & 0x02A00000) flags |= 0x02A00000;
    needed = seg->unk_0 & 0x03E00000;
    if (needed == (needed & flags)) {
        if (ctx->unk_4->unk_1C[index] == seg ||
            fn_1_17B5C(ctx->unk_4->unk_4C[index], id, lbl_1_bss_3BE0->unk_8, 200.0f)) {
            return 1;
        }
    }
    return 0;
}

static inline int fn_1_19AE0_allowed(Ctx *ctx, Seg *seg, s32 id)
{
    s32 index;
    s32 count;
    u32 needed;
    u32 flags;
    u32 mask;
    s32 other;
    if (ctx == NULL) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index) return 0;
    if (!__rlwnm(flags, 30, 31, 31)) return 0;
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) mask |= 0xC00;
    needed = seg->unk_0 & mask;
    other = ctx->unk_4->unk_4C[index];
    if (needed == (needed & flags)) {
        if (ctx->unk_4->unk_1C[index] == seg || fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f)) {
            if (fn_1_7B054() == 0x10) return 1;
            if (fn_1_7B054() == 0x1C) {
                if (id >= 0x74 && id <= 0x90) return 1;
                if (id >= 0xA8 && id <= 0xC6) return 1;
                return 1;
            }
            return 1;
        }
    }
    return 0;
}

static inline void fn_1_19AE0_axis_y(Vec3 *out, f32 scale)
{
    f32 x, y, z;
    x = LC[1];
    y = LC[5];
    z = LC[9];
    x *= scale;
    y *= scale;
    z *= scale;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* retail keeps the course-1 node-107 block's zero = 0.0f assignment alive (f6) */

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

void fn_1_19AE0(Vec3 *arg0, Vec3 *arg1, u32 arg2, Seg *seg, Vec3 *scale, Ctx *ctx, void *arg6, s32 id, f32 arg8)
{
    int has_ctx;
    u32 hit;
    u32 seen;
    Vec3 p0;
    Vec3 p1;
    Vec3 delta;
    Vec3 pt;
    Vec3 s0;
    Vec3 s1;
    Vec3 s0b;
    Vec3 s1b;
    Vec3 v;
    Vec3 delta2;
    u32 rail;
    ColiVolume *vol;
    ColiContact *up;
    ColiContact *down;
    s32 i;
    f32 half;
    f32 w;
    f32 t;
    f32 d;
    f32 sx;
    f32 sxb;
    f32 t2;
    f32 y;
    int sub;
    int sub2;
    s32 right;
    s32 left;
    int above;
    int in;
    int ok;
    ColiContact *c;

    rail = 0xE0000000;
    w = 0.5f;
    hit = 0;
    seen = 0;
    fn_1_18784(arg2, (void *)seg, (void *)scale, (void *)arg6, arg8);
    has_ctx = 0;
    if (ctx != NULL && fn_1_7B054() != 8) has_ctx = 1;
    lbl_8006DAEC();
    lbl_8006DF44();
    vol = &lbl_801A66CC->volumes[lbl_801A66CC->num_volumes];
    vol->height = seg->unk_40 > seg->unk_3C ? seg->unk_40 : seg->unk_3C;
    vol->scale = *scale;
    lbl_8006DB74(vol);
    lbl_8006E1B0((void *)arg0, (void *)&p0);
    if (lbl_801A66CC->num_contacts > 0) {
        half = 0.5f * scale->x;
        c = lbl_801A66CC->contacts;
        for (i = 0; i < lbl_801A66CC->num_contacts; i++, c++) {
            if (c->flags != 0) {
                lbl_8006E1B0((void *)&c->position, (void *)&lbl_801A66CC->delta);
                if (__fabsf(lbl_801A66CC->delta.x) <= half - 0.1f) {
                    y = __fabsf(lbl_801A66CC->delta.y);
                    if (y <= seg->unk_40 || y <= seg->unk_3C) {
                        if (ctx != NULL) {
                            ctx->unk_0->unk_3C[lbl_801A66CC->contact_ids[i]] &= 0x3FFF3FFF;
                            if (c->flags & 0xC00) ctx->unk_0->unk_8 = 1;
                        }
                        c->flags = 0;
                    }
                }
            }
        }
    }
    p0.x /= scale->x;
    lbl_8006E1B0((void *)arg1, (void *)&p1);
    p1.x /= scale->x;
    lbl_8006DB30();
    left = arg2 & 4;
    right = left;
    up = &lbl_801A66CC->hits[1];
    down = &lbl_801A66CC->hits[0];
    if (ctx != NULL) {
        u32 flags = ctx->unk_4->unk_18;
        if (flags & 0x8000) left = 0;
        if (flags & 0x4000) right = 0;
    }
    if (!(seg->unk_0 & 0x400) && !(seg->unk_0 & 0x800)) {
        w = 0.5f + lbl_801A66CC->unk_1B4 / scale->x;
        if ((-w > p1.x && -w > p0.x) || (w < p1.x && w < p0.x)) rail = 0;
        if (lbl_801A66CC->count > 1 && p0.y > 5.0f && p1.y > 5.0f) rail &= ~0x20000000;
    }
    if (fn_1_7B054() == 3 && lbl_801A66CC->segment >= 0x7C && lbl_801A66CC->segment <= 0x8B &&
        p0.y > 50.0f && p1.y > 50.0f) {
        rail &= ~0x20000000;
    }
    if (p0.x > 0.0f) right = 0;
    /* retail reloads p0.x here */
    if (!(*(f32 *)&p0 > 0.0f)) left = 0;
    above = 0.0f >= p0.y;
    if (above) rail &= ~0x20000000;
    in = fn_1_19AE0_match(ctx, seg, id);
    if (!((-w > p1.x && -w > p0.x) || (w < p1.x && w < p0.x))) {
        t = p1.y / (p1.y - p0.y);
        if (p1.y >= 0.0f && above && fn_1_19AE0_finite(t)) {
            seen |= 0x20000000;
            if (up->flags == 0 || t < up->t) hit = 0x20000000;
        } else if (p1.y >= p0.y) {
            if (t <= 1.0f && 0.0f <= t && fn_1_19AE0_finite(t)) {
                seen |= 0x20000000;
                if (up->flags == 0 || t < up->t) hit = 0x20000000;
            }
        } else if (has_ctx && !in) {
            if (t <= 1.0f && 0.0f <= t && fn_1_19AE0_finite(t)) {
                seen |= 0x02000000;
                if (down->flags == 0 || t < down->t) hit = 0x02000000;
            }
        }
    }
    if (in && above && !((hit >> 29) & 1)) {
        seen |= 0x20000000;
        if (up->flags == 0) {
            hit = 0x20000000;
            t = 0.0f;
        }
    }
    if (has_ctx && hit == 0) {
        ok = in;
        if (!ok) ok = !(0.0f >= p1.y);
        if (!ok || fn_1_19AE0_allowed(ctx, seg, id)) {
            if (!above) {
                seen |= 0x02000000;
                if (down->flags == 0) {
                    hit = 0x02000000;
                    t = 0.0f;
                }
            }
        }
    }
    if (hit != 0) {
        if ((hit << 6 >> 31)) {
            c = down;
        } else {
            c = up;
        }
        psvec_sub_scale_add(&p0, &p1, t, &delta, &pt);
        if (__fabsf(pt.x) <= w ||
            (!((hit >> 25) & 1) && (arg2 & 0x02000000) && in &&
             ((pt.x > 0.0f && (seg->unk_0 & 0x800) &&
               __rlwnm(ctx->unk_4->unk_3C[ctx->unk_0->unk_0], 2, 31, 31)) ||
              (pt.x <= 0.0f && (seg->unk_0 & 0x400) &&
               __rlwnm(ctx->unk_4->unk_3C[ctx->unk_0->unk_0], 1, 31, 31))))) {
            psvec_sub_scale_add(arg0, arg1, t, &delta, &c->point);
            if ((hit >> 25) & 1) {
                c->normal.x = -lbl_801A6D00[1];
                c->normal.y = -lbl_801A6D00[5];
                c->normal.z = -lbl_801A6D00[9];
                d = -p0.y;
                if (d < 0.0f) {
                    fn_1_19AE0_axis_y(&c->correction, d);
                } else {
                    c->correction.x = 0.0f;
                    c->correction.y = 0.0f;
                    c->correction.z = 0.0f;
                }
            } else {
                c->normal.x = lbl_801A6D00[1];
                c->normal.y = lbl_801A6D00[5];
                c->normal.z = lbl_801A6D00[9];
                d = -p0.y;
                if (d > 0.0f) {
                    fn_1_19AE0_axis_y(&c->correction, d);
                } else {
                    c->correction.x = 0.0f;
                    c->correction.y = 0.0f;
                    c->correction.z = 0.0f;
                }
            }
            c->t = t;
            c->flags = 0x02000000;
            c->unk_0 = lbl_801A66CC->index;
            c->unk_4 = lbl_801A66CC->segment;
            c->unk_8 = lbl_801A66CC->time;
            c->link = ctx != NULL ? &ctx->unk_0->unk_3C[ctx->unk_0->unk_0] : NULL;
        } else {
            hit = 0;
            seen = 0;
        }
        if ((hit >> 25) & 1) {
            hit = 0;
            rail = 0;
        }
    }
    if (seg->unk_0 & 0x400) {
        sub = seg->unk_0 & 0x1000;
        if (sub) {
            s0 = p0;
            s1 = p1;
            sx = scale->x;
            lbl_8006DAEC();
            lbl_8006DBAC(seg->unk_8);
            lbl_8006DAEC();
            lbl_8006DF44();
            scale->x = seg->unk_8->unk_30;
            lbl_8006E1B0((void *)arg0, (void *)&p0);
            p0.x /= scale->x;
            lbl_8006E1B0((void *)arg1, (void *)&p1);
            p1.x /= scale->x;
            lbl_8006DB30();
        }
        if (-w >= p0.x) rail &= 0x7FFFFFFF;
        if (right) {
            if (fn_1_192E8((void *)arg0, (void *)arg1, (void *)&p0, (void *)&p1, (void *)seg, (void *)&scale->x, (void *)ctx, id, (void *)&rail, !((hit >> 29) & 1), 1.0f)) {
                hit |= 0x80000000;
            }
        }
        if (sub) {
            lbl_8006DB30();
            p0 = s0;
            p1 = s1;
            scale->x = sx;
        }
    }
    if (seg->unk_0 & 0x800) {
        sub2 = seg->unk_0 & 0x2000;
        if (sub2) {
            s0b = p0;
            s1b = p1;
            sxb = scale->x;
            lbl_8006DAEC();
            lbl_8006DBAC(seg->unk_8);
            lbl_8006DAEC();
            lbl_8006DF44();
            scale->x = seg->unk_8->unk_30;
            lbl_8006E1B0((void *)arg0, (void *)&p0);
            p0.x /= scale->x;
            lbl_8006E1B0((void *)arg1, (void *)&p1);
            p1.x /= scale->x;
            lbl_8006DB30();
        }
        if (w <= p0.x) rail &= ~0x40000000;
        if (left) {
            if (fn_1_192E8((void *)arg0, (void *)arg1, (void *)&p0, (void *)&p1, (void *)seg, (void *)&scale->x, (void *)ctx, id, (void *)&rail, !((hit >> 29) & 1), -1.0f)) {
                hit |= 0x40000000;
            }
        }
        if (sub2) {
            lbl_8006DB30();
            p0 = s0b;
            p1 = s1b;
            scale->x = sxb;
        }
    }
    if ((arg2 & 0x01000000) && fn_1_7B054() == 0x26 && hit == 0) {
        if (!((rail >> 29) & 1) && p0.x > 0.0f) fn_1_1ACC0((void *)arg0, (void *)arg1, (void *)seg, (void *)scale, p0.x);
        if (!(rail >> 31) && p0.x <= 0.0f) fn_1_1ACC0((void *)arg0, (void *)arg1, (void *)seg, (void *)scale, p0.x);
    }
    if (((rail | hit) & 0xE0000000) == 0xE0000000 && (arg2 & 0x01000004) == 0x01000004 &&
        lbl_801A66CC->segment == 0x6B && fn_1_7B054() == 1) {
        v = ((PlaneOwner *)lbl_1_bss_3BE0->unk_C)->unk_508->unk_18;
        v.x -= 0.5f;
        if (arg0->x >= v.x) {
            t2 = (arg1->x - v.x) / (arg1->x - arg0->x);
            if (!fn_1_19AE0_finite(t2)) t2 = 0.0f;
            if (__fabsf(arg1->y + (f32)(t2 * (arg0->y - arg1->y)) - v.y) <= seg->unk_40) {
                f32 zero = 0.0f;

                c = &lbl_801A66CC->contacts[lbl_801A66CC->num_contacts];
                c->flags = 0;
                c->t = -1.0f;
                lbl_801A66CC->num_contacts++;
                c->position = v;
                psvec_sub_scale_add(arg0, arg1, t2, &delta2, &c->point);
                c->normal.x = -1.0f;
                c->normal.y = zero;
                c->normal.z = zero;
                d = arg0->x - v.x;
                if (d > zero) {
                    c->correction.x = -d - 0.5f;
                    c->correction.y = zero;
                    c->correction.z = zero;
                } else {
                    c->correction.x = zero;
                    c->correction.y = zero;
                    c->correction.z = zero;
                }
                c->t = t2;
                c->flags = 0x400;
                c->unk_0 = lbl_801A66CC->index;
                c->unk_4 = lbl_801A66CC->segment;
                c->unk_8 = lbl_801A66CC->time;
                c->link = ctx != NULL ? &ctx->unk_0->unk_3C[ctx->unk_0->unk_0] : NULL;
            }
        }
    }
    if (lbl_801A66CC->num_volumes < 3) lbl_801A66CC->num_volumes++;
    if (ctx != NULL) {
        u32 hit2 = hit & ~0x02000000;
        u32 seen2 = seen & ~0x02000000;
        ctx->unk_0->unk_1C[ctx->unk_0->unk_0] = seg;
        ctx->unk_0->unk_2C[ctx->unk_0->unk_0] = scale->x;
        ctx->unk_0->unk_3C[ctx->unk_0->unk_0] = seg->unk_0 | (((hit >> 25) & 1) ? 4 : 0);
        if (rail != 0 || hit2 != 0 || seen2 != 0) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= seen2 | (rail | hit2) | 0x10000000;
        }
        if (hit2 >> 31) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] &= ~0xC000;
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= 0x8000;
        } else if ((hit2 >> 30) & 1) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] &= ~0xC000;
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= 0x4000;
        }
        ctx->unk_0->unk_4C[ctx->unk_0->unk_0] = id;
        if (ctx->unk_0->unk_0 < 3) ctx->unk_0->unk_0++;
    }
}

#pragma opt_dead_assignments reset
#undef GAME_VEC3_H
#undef LC
/* fzgx:end fn_1_19AE0 */

/* fzgx:begin fn_1_1ACC0 */
#define GAME_VEC3_H

#define LC ((f32 *)LC_BASE)

static inline int fn_1_1ACC0_finite(f32 x)
{
    union { f32 f; u32 u; } bits;
    bits.f = x;
    return (bits.u & 0x7F800000) != 0x7F800000;
}

static inline void fn_1_1ACC0_axis_y(Vec3 *out, f32 scale)
{
    f32 x, y, z;
    x = LC[1];
    y = LC[5];
    z = LC[9];
    x *= scale;
    y *= scale;
    z *= scale;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* retail translates mtxA in place (fmadds into the loaded column registers) and keeps the zero local of the
 * low-height block alive (f1) */

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

/* WARNING: compiler-diff device, not original code */
#pragma opt_dead_assignments off

void fn_1_1ACC0(Vec3 *arg0, Vec3 *arg1, fn_1_1ACC0_Seg *arg2, f32 *arg3, f32 arg4)
{
    ColiContact *c = &lbl_801A66CC->hits[4];
    s32 up = arg4 > 0.0f;
    f32 height = arg0->y - lbl_801A6D00[7];
    Vec3 a;
    Vec3 b;
    Vec3 d;
    Vec3 out;
    f32 t;
    f32 y;
    u32 flags;

    lbl_8006DAEC();
    if (up) {
        f32 m20, m23, m10, m13, m00, m03, x;

        m00 = LC[0];
        m03 = LC[3];
        m10 = LC[4];
        m13 = LC[7];
        m20 = LC[8];
        m23 = LC[11];
        x = 0.5f * *arg3;
        m00 = m00 * x + m03;
        m10 = m10 * x + m13;
        m20 = m20 * x + m23;
        LC[3] = m00;
        LC[7] = m10;
        LC[11] = m20;
        mathutil_mtxA_rotate_z(-0x31C7);
    } else {
        lbl_8006E0B4(-0.5f * *arg3, arg2->unk_40, 0.0f);
        mathutil_mtxA_rotate_z(-0xCCC);
    }
    lbl_8006DAEC();
    lbl_8006DF44();
    lbl_8006E1B0((void *)arg0, (void *)&a);
    lbl_8006E1B0((void *)arg1, (void *)&b);
    lbl_8006DB30();
    if (height < -5.0f) {
        f32 zero = 0.0f;

        c->point = *arg1;
        c->normal.x = lbl_801A6D00[1];
        c->normal.y = lbl_801A6D00[5];
        c->normal.z = lbl_801A6D00[9];
        c->correction.x = zero;
        c->correction.y = zero;
        c->correction.z = zero;
        c->t = zero;
        c->flags |= 0x100;
        c->unk_0 = lbl_801A66CC->index;
        c->unk_4 = lbl_801A66CC->segment;
        c->unk_8 = lbl_801A66CC->time;
        c->link = NULL;
    }
    if (0.0f >= a.y) {
        t = b.y / (b.y - a.y);
        if (!fn_1_1ACC0_finite(t)) {
            t = 0.0f;
        }
        psvec_sub(&a, &b, &d);
        psvec_scale_add(&b, &d, t, &out);
        psvec_sub(arg0, arg1, &d);
        psvec_scale_add(arg1, &d, t, &c->point);
        c->normal.x = lbl_801A6D00[1];
        c->normal.y = lbl_801A6D00[5];
        c->normal.z = lbl_801A6D00[9];
        y = -a.y;
        if (y > 0.0f) {
            fn_1_1ACC0_axis_y(&c->correction, y);
        } else {
            c->correction.x = 0.0f;
            c->correction.y = 0.0f;
            c->correction.z = 0.0f;
        }
        c->t = t;
        if (up) {
            if (height < -50.0f) {
                flags = 0x200;
            } else {
                flags = 0x800;
            }
        } else {
            flags = 0x400;
        }
        c->flags = flags;
        c->unk_0 = lbl_801A66CC->index;
        c->unk_4 = lbl_801A66CC->segment;
        c->unk_8 = lbl_801A66CC->time;
        c->link = NULL;
    }
    lbl_8006DB30();
}

#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset
#undef GAME_VEC3_H
#undef LC
/* fzgx:end fn_1_1ACC0 */

/* fzgx:begin fn_1_1B010 */
void fn_1_1B010(u32 arg0, void *pos, u32 mode, StcoliEntity *entity, f32 *out, u32 arg5, void *work, f32 value) {
u32 shapes[9] = {0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C, 0x40, 0x44};
u32 counts[9] = {0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20};
Vec3 local;
u8 *cfg;
s32 i;
u8 *shape;
f32 minV;
f32 maxV;
f32 t;
f32 width;
u32 n;
s32 empty;
if ((mode & 0x200000) != 0) {
empty = 1;
minV = lbl_1_data_4;
maxV = 0.0f;
cfg = entity->cfg;
for (i = 0; i < 9; i++) {
shape = *(u8 **)(cfg + shapes[i]);
if (shape != ((void *)0) ) {
t = *(f32 *)(shape + 4);
n = *(u32 *)(cfg + counts[i]);
if (minV > t) {
minV = t;
}
t = *(f32 *)(shape + n * 20 - 16);
if (maxV < t) {
maxV = t;
}
empty = 0;
}
}
if (empty || (minV < value && value < maxV)) {
fn_1_18214((void *)entity, (void *)out, (void *)work, value);
t = *out;
if (t < 0.0f) {
t = -t;
}
width = 2.5f + (f32)(0.5f * t);
fn_8006E250(pos, (void *)&local);
if (-5.0f < local.y && local.y < 10.0f) {
if (-width < local.x && local.x < width) {
lbl_801A66CC->flags |= entity->flags & 0x1E0000;
}
}
}
}
}
/* fzgx:end fn_1_1B010 */

/* fzgx:begin fn_1_1B2A4 */
#define GAME_VEC3_H

#define LC ((f32 *)LC_BASE)

/* fzgx-allow: S2 pool primer sink */

static inline int fn_1_1B2A4_finite(f32 x)
{
    union { f32 f; u32 u; } bits;
    bits.f = x;
    return (bits.u & 0x7F800000) != 0x7F800000;
}

static inline int fn_1_1B2A4_match(Ctx *ctx, Seg_1B2A4 *seg, s32 id)
{
    s32 index;
    s32 count;
    u32 flags;
    u32 needed;
    if (ctx == NULL) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index || !__rlwnm(flags, 3, 31, 31)) {
        if (lbl_801A66CC->enabled == 0) return 0;
        for (index = 0; index < count; index++) {
            flags = ctx->unk_4->unk_3C[index];
            if (__rlwnm(flags, 3, 31, 31)) break;
        }
        if (index >= count) return 0;
    }
    if (flags & 0x02A00000) flags |= 0x02A00000;
    needed = seg->unk_0 & 0x03E00000;
    if (needed == (needed & flags)) {
        if (ctx->unk_4->unk_1C[index] == seg ||
            fn_1_17B5C(ctx->unk_4->unk_4C[index], id, lbl_1_bss_3BE0->unk_8, 200.0f)) {
            return 1;
        }
    }
    return 0;
}

static inline int fn_1_1B2A4_allowed(Ctx *ctx, Seg_1B2A4 *seg, s32 id)
{
    s32 index;
    s32 count;
    u32 needed;
    u32 flags;
    u32 mask;
    s32 other;
    if (ctx == NULL) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index) return 0;
    if (!__rlwnm(flags, 30, 31, 31)) return 0;
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) mask |= 0xC00;
    needed = seg->unk_0 & mask;
    other = ctx->unk_4->unk_4C[index];
    if (needed == (needed & flags)) {
        if (ctx->unk_4->unk_1C[index] == seg || fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f)) {
            if (fn_1_7B054() == 0x10) return 1;
            if (fn_1_7B054() == 0x1C) {
                if (id >= 0x74 && id <= 0x90) return 1;
                if (id >= 0xA8 && id <= 0xC6) return 1;
                return 1;
            }
            return 1;
        }
    }
    return 0;
}

static inline void fn_1_1B2A4_axis_y(Vec3 *out, f32 scale)
{
    f32 x, y, z;
    x = LC[1];
    y = LC[5];
    z = LC[9];
    x *= scale;
    y *= scale;
    z *= scale;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void fn_1_1B2A4_raise(f32 lift)
{
    f32 x, y, z;
    x = LC[1];
    y = LC[5];
    z = LC[9];
    x = x * lift + LC[3];
    y = y * lift + LC[7];
    z = z * lift + LC[11];
    LC[3] = x;
    LC[7] = y;
    LC[11] = z;
}

/* retail's in-place fmadds translate in the rail blocks (x = x * lift + LC[3] in one register) needs opt_lifetimes off */

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

void fn_1_1B2A4(Vec3 *arg0, Vec3 *arg1, u32 arg2, Seg_1B2A4 *seg, Vec3 *scale, Ctx *ctx, void *arg6, s32 id, f32 arg8)
{
    u32 hit;
    u32 seen;
    Vec3 p0;
    Vec3 p1;
    Vec3 delta;
    Vec3 pt;
    u32 rail;
    ColiVolume *vol;
    ColiContact *up;
    ColiContact *down;
    f32 lift2;
    s32 i;
    f32 half;
    f32 h;
    f32 first;
    f32 span;
    f32 place;
    f32 t;
    f32 d;
    f32 zero;
    f32 lift;
    f32 y0;
    f32 y1;
    f32 y;
    s32 right;
    s32 left;
    int above;
    int in;
    int has_ctx;
    int ok;

    if (fn_1_7B054() == 36 || fn_1_7B054() == 37) {
        fn_1_1C0D0((void *)arg0, (void *)arg1, arg2, (void *)seg, (void *)scale, (void *)ctx, (void *)arg6, id, arg8);
        return;
    }
    rail = 0xE0000000;
    hit = 0;
    seen = 0;
    fn_1_18784(arg2, (void *)seg, (void *)scale, (void *)arg6, arg8);
    has_ctx = ctx != NULL;
    lbl_8006DAEC();
    lbl_8006DF44();
    vol = &lbl_801A66CC->volumes[lbl_801A66CC->num_volumes];
    vol->height = seg->unk_40 > seg->unk_3C ? seg->unk_40 : seg->unk_3C;
    vol->scale = *scale;
    lbl_8006DB74(vol);
    lbl_8006E1B0((void *)arg0, (void *)&p0);
    if (lbl_801A66CC->num_contacts > 0) {
        ColiContact *c;

        half = 0.5f * scale->x;
        c = lbl_801A66CC->contacts;
        for (i = 0; i < lbl_801A66CC->num_contacts; i++, c++) {
            if (c->flags != 0) {
                lbl_8006E1B0((void *)&c->position, (void *)&lbl_801A66CC->delta);
                if (__fabsf(lbl_801A66CC->delta.x) <= half - 0.1f) {
                    y = __fabsf(lbl_801A66CC->delta.y);
                    if (y <= seg->unk_40 || y <= seg->unk_3C) {
                        if (ctx != NULL) {
                            ctx->unk_0->unk_3C[lbl_801A66CC->contact_ids[i]] &= 0x3FFF3FFF;
                            if (c->flags & 0xC00) ctx->unk_0->unk_8 = 1;
                        }
                        c->flags = 0;
                    }
                }
            }
        }
    }
    p0.x /= scale->x;
    lbl_8006E1B0((void *)arg1, (void *)&p1);
    p1.x /= scale->x;
    lbl_8006DB30();
    {
        SegChild *child = seg->unk_4;
        Key *keys = child->unk_40;
        if (keys != NULL) {
            first = keys[0].unk_4;
            span = keys[child->unk_1C - 1].unk_4 - first;
            if (arg2 & 0x80000) {
                place = 0.5f * (p1.x + p0.x);
            } else if (arg2 & 0x40000) {
                place = p1.x;
            } else {
                place = p0.x;
            }
            h = fn_1_9E14C(child->unk_1C, (u32)keys, first + (f32)((0.5f + place) * span));
        } else {
            h = seg->unk_30;
        }
    }
    h *= scale->y;
    left = arg2 & 4;
    right = left;
    up = &lbl_801A66CC->hits[1];
    down = &lbl_801A66CC->hits[0];
    if (ctx != NULL) {
        u32 flags = ctx->unk_4->unk_18;
        if (flags & 0x8000) left = 0;
        if (flags & 0x4000) right = 0;
    }
    if (p0.x > 0.0f) right = 0;
    /* retail reloads p0.x here */
    if (!(*(f32 *)&p0 > 0.0f)) left = 0;
    above = h >= p0.y;
    if (above) rail &= ~0x20000000;
    in = fn_1_1B2A4_match(ctx, seg, id);
    if (!((-0.5f > p1.x && -0.5f > p0.x) || (0.5f < p1.x && 0.5f < p0.x))) {
        t = (p1.y - h) / (p1.y - p0.y);
        if (p1.y >= h && above && fn_1_1B2A4_finite(t)) {
            seen |= 0x20000000;
            if (up->flags == 0 || t < up->t) hit = 0x20000000;
        } else if (p1.y >= p0.y) {
            if (t <= 1.0f && 0.0f <= t && fn_1_1B2A4_finite(t)) {
                seen |= 0x20000000;
                if (up->flags == 0 || t < up->t) hit = 0x20000000;
            }
        } else if (has_ctx && !in) {
            if (t <= 1.0f && 0.0f <= t && fn_1_1B2A4_finite(t)) {
                seen |= 0x02000000;
                if (down->flags == 0 || t < down->t) hit = 0x02000000;
            }
        }
    }
    if (in && above && !((hit >> 29) & 1)) {
        seen |= 0x20000000;
        if (up->flags == 0) {
            hit = 0x20000000;
            t = 0.0f;
        }
    }
    if (has_ctx && hit == 0) {
        ok = in;
        if (!ok) ok = !(h >= p1.y);
        if (!ok || fn_1_1B2A4_allowed(ctx, seg, id)) {
            if (!above) {
                seen |= 0x02000000;
                if (down->flags == 0) {
                    hit = 0x02000000;
                    t = 0.0f;
                }
            }
        }
    }
    if (hit != 0) {
        ColiContact *c;

        if ((hit << 6 >> 31)) {
            c = down;
        } else {
            c = up;
        }
        psvec_sub_scale_add(&p0, &p1, t, &delta, &pt);
        if (__fabs(pt.x) <= 0.5 ||
            (!((hit >> 25) & 1) && (arg2 & 0x02000000) && in &&
             ((pt.x > 0.0f && (seg->unk_0 & 0x800) &&
               __rlwnm(ctx->unk_4->unk_3C[ctx->unk_0->unk_0], 2, 31, 31)) ||
              (pt.x <= 0.0f && (seg->unk_0 & 0x400) &&
               __rlwnm(ctx->unk_4->unk_3C[ctx->unk_0->unk_0], 1, 31, 31))))) {
            psvec_sub_scale_add(arg0, arg1, t, &delta, &c->point);
            if ((hit >> 25) & 1) {
                zero = 0.0f;
                c->normal.x = -lbl_801A6D00[1];
                c->normal.y = -lbl_801A6D00[5];
                c->normal.z = -lbl_801A6D00[9];
                d = -(p0.y - h);
                if (d < zero) {
                    fn_1_1B2A4_axis_y(&c->correction, d);
                } else {
                    c->correction.x = zero;
                    c->correction.y = zero;
                    c->correction.z = zero;
                }
            } else {
                zero = 0.0f;
                c->normal.x = lbl_801A6D00[1];
                c->normal.y = lbl_801A6D00[5];
                c->normal.z = lbl_801A6D00[9];
                d = -(p0.y - h);
                if (d > zero) {
                    fn_1_1B2A4_axis_y(&c->correction, d);
                } else {
                    c->correction.x = zero;
                    c->correction.y = zero;
                    c->correction.z = zero;
                }
            }
            c->t = t;
            c->flags = 0x200000;
            c->unk_0 = lbl_801A66CC->index;
            c->unk_4 = lbl_801A66CC->segment;
            c->unk_8 = lbl_801A66CC->time;
            c->link = ctx != NULL ? &ctx->unk_0->unk_3C[ctx->unk_0->unk_0] : NULL;
        } else {
            hit = 0;
            seen = 0;
        }
        if ((hit >> 25) & 1) {
            hit = 0;
            rail = 0;
        }
    }
    if (seg->unk_0 & 0x400) {
        SegChild *child = seg->unk_4;
        lbl_8006DAEC();
        y0 = p0.y;
        y1 = p1.y;
        lift = child->unk_40 != NULL ? child->unk_40->unk_8 : seg->unk_30;
        lift *= scale->y;
        fn_1_1B2A4_raise(lift);
        p0.y -= lift;
        p1.y -= lift;
        if (-0.5f >= p0.x) rail &= 0x7FFFFFFF;
        if (right) {
            if (fn_1_192E8((void *)arg0, (void *)arg1, (void *)&p0, (void *)&p1, (void *)seg, (void *)&scale->x, (void *)ctx, id, (void *)&rail, !((hit >> 29) & 1), 1.0f)) {
                hit |= 0x80000000;
            }
        }
        lbl_8006DB30();
        p0.y = y0;
        p1.y = y1;
    }
    if (seg->unk_0 & 0x800) {
        SegChild *child = seg->unk_4;
        lift2 = child->unk_40 != NULL ? child->unk_40[child->unk_1C - 1].unk_8 : seg->unk_30;
        lift2 *= scale->y;
        fn_1_1B2A4_raise(lift2);
        p0.y -= lift2;
        p1.y -= lift2;
        if (0.5f <= p0.x) rail &= ~0x40000000;
        if (left) {
            if (fn_1_192E8((void *)arg0, (void *)arg1, (void *)&p0, (void *)&p1, (void *)seg, (void *)&scale->x, (void *)ctx, id, (void *)&rail, !((hit >> 29) & 1), -1.0f)) {
                hit |= 0x40000000;
            }
        }
    }
    if (lbl_801A66CC->num_volumes < 3) lbl_801A66CC->num_volumes++;
    if (ctx != NULL) {
        u32 hit2 = hit & ~0x02000000;
        u32 seen2 = seen & ~0x02000000;
        ctx->unk_0->unk_1C[ctx->unk_0->unk_0] = seg;
        ctx->unk_0->unk_2C[ctx->unk_0->unk_0] = scale->x;
        ctx->unk_0->unk_3C[ctx->unk_0->unk_0] = seg->unk_0 | (((hit >> 25) & 1) ? 4 : 0);
        if (rail != 0 || hit2 != 0 || seen2 != 0) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= seen2 | (rail | hit2) | 0x10000000;
        }
        if (hit2 >> 31) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] &= ~0xC000;
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= 0x8000;
        } else if ((hit2 >> 30) & 1) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] &= ~0xC000;
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= 0x4000;
        }
        ctx->unk_0->unk_4C[ctx->unk_0->unk_0] = id;
        if (ctx->unk_0->unk_0 < 3) ctx->unk_0->unk_0++;
    }
}

#pragma opt_lifetimes reset
#undef GAME_VEC3_H
#undef LC
/* fzgx:end fn_1_1B2A4 */

/* fzgx:begin fn_1_1C0D0 */
/* the current matrix (mtxA) lives in the locked cache */

#define MTXA ((f32(*)[4])LC_BASE)

/* retail evaluates the float argument first; the definition passes it through unnamed */

static inline int fn_1_1C0D0_finite(f32 x)
{
    return (*(u32 *)&x & 0x7F800000) != 0x7F800000;
}

/* mtxA translated along its x or y axis */

static inline void fn_1_1C0D0_translate_x(f32 offset)
{
    f32 x, y, z;

    x = MTXA[0][0];
    y = MTXA[1][0];
    z = MTXA[2][0];
    x = x * offset + MTXA[0][3];
    y = y * offset + MTXA[1][3];
    z = z * offset + MTXA[2][3];
    MTXA[0][3] = x;
    MTXA[1][3] = y;
    MTXA[2][3] = z;
}

static inline void fn_1_1C0D0_translate_y(f32 offset)
{
    f32 x, y, z;

    x = MTXA[0][1];
    y = MTXA[1][1];
    z = MTXA[2][1];
    x = x * offset + MTXA[0][3];
    y = y * offset + MTXA[1][3];
    z = z * offset + MTXA[2][3];
    MTXA[0][3] = x;
    MTXA[1][3] = y;
    MTXA[2][3] = z;
}

/* both points in the current frame, x divided by scale[0] */

static inline void fn_1_1C0D0_project(Vec3 *a, Vec3 *b, Vec3 *pa,
    Vec3 *pb, f32 *scale)
{
    lbl_8006DAEC();
    lbl_8006DF44();
    lbl_8006E1B0((void *)a, (void *)pa);
    pa->x = pa->x / scale[0];
    lbl_8006E1B0((void *)b, (void *)pb);
    pb->x = pb->x / scale[0];
    lbl_8006DB30();
}

static inline s16 fn_1_1C0D0_angle(fn_1_1C0D0_Cfg *cfg, f32 at, f32 *scale, f32 span)
{
    if (cfg->unk_40 != NULL) {
        f32 k = fn_1_9E194(at, cfg->unk_1C, cfg->unk_40);
        return lbl_8006D2AC(k * (scale[1] * span / scale[0]));
    }
    return 0;
}

static inline int fn_1_1C0D0_pick(fn_1_1C0D0_Ctx *ctx, fn_1_1C0D0_Wall *wall, int id)
{
    s32 index;
    s32 count;
    u32 flags;
    u32 needed;

    if (ctx == NULL) {
        return 0;
    }
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index || !__rlwnm(flags, 3, 31, 31)) {
        if (lbl_801A66CC->enabled == 0) {
            return 0;
        }
        for (index = 0; index < count; index++) {
            flags = ctx->unk_4->unk_3C[index];
            if (__rlwnm(flags, 3, 31, 31)) {
                break;
            }
        }
        if (index >= count) {
            return 0;
        }
    }
    if (flags & 0x02A00000) {
        flags |= 0x02A00000;
    }
    needed = wall->unk_0 & 0x03E00000;
    if (needed == (needed & flags)) {
        if (ctx->unk_4->unk_1C[index] == wall ||
            fn_1_17B5C(ctx->unk_4->unk_4C[index], id, lbl_1_bss_3BE0->unk_8, 200.0f)) {
            return 1;
        }
    }
    return 0;
}

static inline int fn_1_1C0D0_allowed(fn_1_1C0D0_Ctx *ctx, fn_1_1C0D0_Wall *wall, int id)
{
    s32 index;
    s32 count;
    u32 flags;
    u32 mask;
    u32 needed;
    s32 other;

    if (ctx == NULL) {
        return 0;
    }
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index) {
        return 0;
    }
    if (!__rlwnm(flags, 30, 31, 31)) {
        return 0;
    }
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) {
        mask |= 0xC00;
    }
    needed = wall->unk_0 & mask;
    other = ctx->unk_4->unk_4C[index];
    if (needed == (needed & flags) &&
        (ctx->unk_4->unk_1C[index] == wall || fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f))) {
        if (fn_1_7B054() == 0x10) {
            return 1;
        }
        if (fn_1_7B054() == 0x1C) {
            if (id >= 0x74 && id <= 0x90) {
                return 1;
            }
            if (id >= 0xA8 && id <= 0xC6) {
                return 1;
            }
            return 1;
        }
        return 1;
    }
    return 0;
}

static inline void fn_1_1C0D0_lift(Vec3 *out, f32 depth)
{
    f32 x, y, z;
    x = MTXA[0][1];
    y = MTXA[1][1];
    z = MTXA[2][1];
    x *= depth;
    y *= depth;
    z *= depth;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 fn_1_1C0D0_first(fn_1_1C0D0_Wall *wall)
{
    if (wall->unk_4->unk_40 != NULL) {
        return wall->unk_4->unk_40[0].unk_8;
    }
    return wall->unk_30;
}

static inline f32 fn_1_1C0D0_last(fn_1_1C0D0_Wall *wall)
{
    fn_1_1C0D0_Cfg *cfg = wall->unk_4;

    if (cfg->unk_40 != NULL) {
        return cfg->unk_40[cfg->unk_1C - 1].unk_8;
    }
    return wall->unk_30;
}

/* retail keeps each mtxA column load and its fmadds result in one register (f4/f3/f2) */

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

void fn_1_1C0D0(Vec3 *a, Vec3 *b, u32 flags, fn_1_1C0D0_Wall *wall, f32 *scale,
    fn_1_1C0D0_Ctx *ctx, void *arg6, int id, f32 arg8)
{
    int ok;
    s32 use_own;
    u32 hit;
    u32 seen;
    ColiContact *contact1;
    ColiContact *contact0;
    s32 left;
    s32 right;
    s32 below;
    ColiWork *mgr;
    fn_1_1C0D0_Cfg *cfg;
    fn_1_1C0D0_Key *keys;
    ColiContact *contact;
    Vec3 pa;
    Vec3 pb;
    Vec3 d;
    Vec3 p;
    s32 has_ctx;
    s32 inside;
    s32 side;
    s32 done_left;
    s32 done_right;
    u32 mask;
    s16 angle_left;
    s16 angle_right;
    f32 h;
    f32 at;
    f32 span;
    f32 start;
    f32 end;
    f32 t;
    f32 depth;
    u32 hit_rest;
    u32 seen_rest;

    use_own = 0;
    if (lbl_801A66CC->ctx != NULL && (flags & 0x01800000) == 0) {
        use_own = 1;
    }
    mask = 0xE0000000;
    hit = 0;
    seen = 0;
    fn_1_18784(flags, (void *)wall, (void *)scale, (void *)arg6, arg8);
    has_ctx = ctx != NULL;
    if (wall->unk_4->unk_40 != NULL) {
        keys = wall->unk_4->unk_40;
        start = keys[0].unk_4;
        end = keys[wall->unk_4->unk_1C - 1].unk_4;
        span = end - start;
    }
    done_right = 0;
    mgr = lbl_801A66CC;
    done_left = 0;
    angle_left = 0;
    contact1 = &mgr->hits[1];
    angle_right = 0;
    contact0 = &mgr->hits[0];
    fn_1_1C0D0_project(a, b, &pa, &pb, scale);

    left = (flags & 4) && (wall->unk_0 & 0x400);
    right = (flags & 4) && (wall->unk_0 & 0x800);
    side = pa.x > 0.0f;
    if (side) {
        left = 0;
    }
    if (!side) {
        right = 0;
    }

    cfg = wall->unk_4;
    keys = cfg->unk_40;
    if (keys != NULL) {
        if (flags & 0x80000) {
            at = 0.5f * (pb.x + pa.x);
        } else if (flags & 0x40000) {
            at = pb.x;
        } else {
            at = pa.x;
        }
        at = start + (f32)((0.5f + at) * span);
        if (end < at) {
            h = keys[cfg->unk_1C - 1].unk_8 + (f32)(keys[cfg->unk_1C - 1].unk_C * (at - end));
        } else {
            h = fn_1_9E14C(cfg->unk_1C, (u32)keys, at);
        }
    } else {
        h = wall->unk_30;
    }
    h *= scale[1];
    below = h >= pa.y;
    if (below) {
        mask &= ~0x20000000;
    }

    ok = fn_1_1C0D0_pick(use_own ? lbl_801A66CC->ctx : ctx, wall, id);

    if (!((-0.5f > pb.x && -0.5f > pa.x) || (0.5f < pb.x && 0.5f < pa.x))) {
        t = (pb.y - h) / (pb.y - pa.y);
        if (pb.y >= h && below && fn_1_1C0D0_finite(t)) {
            seen |= 0x20000000;
            if (contact1->flags == 0 || t < contact1->t) {
                hit = 0x20000000;
            }
        } else if (pb.y >= pa.y) {
            if (t <= 1.0f && 0.0f <= t && fn_1_1C0D0_finite(t)) {
                seen |= 0x20000000;
                if (contact1->flags == 0 || t < contact1->t) {
                    hit = 0x20000000;
                }
            }
        } else if (has_ctx && !ok && t <= 1.0f && 0.0f <= t && fn_1_1C0D0_finite(t)) {
            seen |= 0x02000000;
            if (contact0->flags == 0 || t < contact0->t) {
                hit = 0x02000000;
            }
        }
    }

    if (ok && below && !__rlwinm(hit, 3, 31, 31)) {
        seen |= 0x20000000;
        if (contact1->flags == 0) {
            hit = 0x20000000;
            t = 0.0f;
        }
    }
    if (has_ctx && hit == 0) {
        s32 blocked = ok;
        if (!blocked) {
            blocked = !(h >= pb.y);
        }
        if (!blocked || fn_1_1C0D0_allowed(ctx, wall, id)) {
            if (!below) {
                seen |= 0x02000000;
                if (contact0->flags == 0) {
                    hit = 0x02000000;
                    t = 0.0f;
                }
            }
        }
    }

    if (hit != 0) {
        if (__rlwinm(hit, 7, 31, 31)) {
            contact = contact0;
        } else {
            contact = contact1;
        }
        psvec_sub_scale_add(&pa, &pb, t, &d, &p);
        inside = __fabs(p.x) <= 0.5;
        if (inside ||
            (ok &&
             ((!use_own && !__rlwinm(hit, 7, 31, 31) && (flags & 0x02000000) &&
               ((p.x > 0.0f && right && __rlwnm(ctx->unk_4->unk_3C[ctx->unk_0->unk_0], 2, 31, 31)) ||
                (p.x <= 0.0f && left && __rlwnm(ctx->unk_4->unk_3C[ctx->unk_0->unk_0], 1, 31, 31)))) ||
              (use_own &&
               ((p.x > 0.0f && right && __rlwnm(lbl_801A66CC->ctx->unk_0->unk_3C[0], 2, 31, 31)) ||
                (p.x <= 0.0f && left && __rlwnm(lbl_801A66CC->ctx->unk_0->unk_3C[0], 1, 31, 31))))))) {
            psvec_sub_scale_add(a, b, t, &d, &contact->point);
            if (!inside) {
                lbl_8006DAEC();
                if (p.x > 0.0f) {
                    done_right = 1;
                    angle_right = fn_1_1C0D0_angle(wall->unk_4, lbl_1_data_4, scale, span);
                    if (angle_right != 0) {
                        mathutil_mtxA_rotate_z(angle_right);
                    }
                } else {
                    done_left = 1;
                    angle_left = fn_1_1C0D0_angle(wall->unk_4, 0.0f, scale, span);
                    if (angle_left != 0) {
                        mathutil_mtxA_rotate_z(angle_left);
                    }
                }
            }
            if (__rlwinm(hit, 7, 31, 31)) {
                contact->normal.x = -lbl_801A6D00[1];
                contact->normal.y = -lbl_801A6D00[5];
                contact->normal.z = -lbl_801A6D00[9];
                depth = -(pa.y - h);
                if (depth < 0.0f) {
                    fn_1_1C0D0_lift(&contact->correction, depth);
                } else {
                    contact->correction.x = 0.0f;
                    contact->correction.y = 0.0f;
                    contact->correction.z = 0.0f;
                }
            } else {
                contact->normal.x = lbl_801A6D00[1];
                contact->normal.y = lbl_801A6D00[5];
                contact->normal.z = lbl_801A6D00[9];
                depth = -(pa.y - h);
                if (depth > 0.0f) {
                    fn_1_1C0D0_lift(&contact->correction, depth);
                } else {
                    contact->correction.x = 0.0f;
                    contact->correction.y = 0.0f;
                    contact->correction.z = 0.0f;
                }
            }
            if (!inside) {
                lbl_8006DB30();
            }
            contact->t = t;
            contact->flags = 0x200000;
            contact->unk_0 = lbl_801A66CC->index;
            contact->unk_4 = lbl_801A66CC->segment;
            contact->unk_8 = lbl_801A66CC->time;
            contact->link = ctx != NULL ? &ctx->unk_0->unk_3C[ctx->unk_0->unk_0] : NULL;
            if (use_own) {
                right = 0;
                left = 0;
            }
        } else {
            hit = 0;
            seen = 0;
        }
        if (__rlwinm(hit, 7, 31, 31)) {
            hit = 0;
            mask = 0;
        }
    }

    if (left) {
        f32 dy;
        f32 dx0;
        f32 dx1;

        t = fn_1_1C0D0_first(wall);
        if (!done_left) {
            angle_left = fn_1_1C0D0_angle(wall->unk_4, 0.0f, scale, span);
        }
        lbl_8006DAEC();
        dy = t * scale[1];
        fn_1_1C0D0_translate_y(dy);
        dx0 = -0.5f * scale[0];
        fn_1_1C0D0_translate_x(dx0);
        if (angle_left != 0) {
            mathutil_mtxA_rotate_z(angle_left);
        }
        dx1 = 0.5f * scale[0];
        fn_1_1C0D0_translate_x(dx1);
        fn_1_1C0D0_project(a, b, &pa, &pb, scale);
        if (-0.5f >= pa.x) {
            mask &= ~0x80000000;
        }
        if (fn_1_192E8((void *)a, (void *)b, (void *)&pa, (void *)&pb, (void *)wall, (void *)scale, (void *)ctx, id, (void *)&mask, !__rlwinm(hit, 3, 31, 31), 1.0f)) {
            hit |= 0x80000000;
        }
        lbl_8006DB30();
    }

    if (right) {
        f32 dy;
        f32 dx0;
        f32 dx1;

        t = fn_1_1C0D0_last(wall);
        if (!done_right) {
            angle_right = fn_1_1C0D0_angle(wall->unk_4, lbl_1_data_4, scale, span);
        }
        lbl_8006DAEC();
        dy = t * scale[1];
        fn_1_1C0D0_translate_y(dy);
        dx0 = 0.5f * scale[0];
        fn_1_1C0D0_translate_x(dx0);
        if (angle_right != 0) {
            mathutil_mtxA_rotate_z(angle_right);
        }
        dx1 = -0.5f * scale[0];
        fn_1_1C0D0_translate_x(dx1);
        fn_1_1C0D0_project(a, b, &pa, &pb, scale);
        if (0.5f <= pa.x) {
            mask &= ~0x40000000;
        }
        if (fn_1_192E8((void *)a, (void *)b, (void *)&pa, (void *)&pb, (void *)wall, (void *)scale, (void *)ctx, id, (void *)&mask, !__rlwinm(hit, 3, 31, 31), -1.0f)) {
            hit |= 0x40000000;
        }
        lbl_8006DB30();
    }

    if (ctx != NULL) {
        hit_rest = hit & ~0x02000000;
        seen_rest = seen & ~0x02000000;
        ctx->unk_0->unk_1C[ctx->unk_0->unk_0] = wall;
        ctx->unk_0->unk_2C[ctx->unk_0->unk_0] = scale[0];
        ctx->unk_0->unk_3C[ctx->unk_0->unk_0] = wall->unk_0 | (__rlwinm(hit, 7, 31, 31) ? 4 : 0);
        if (mask != 0 || hit_rest != 0 || seen_rest != 0) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] |= seen_rest | (mask | hit_rest) | 0x10000000;
        }
        ctx->unk_0->unk_4C[ctx->unk_0->unk_0] = id;
        if (ctx->unk_0->unk_0 < 3) {
            ctx->unk_0->unk_0++;
        }
    }
}

#pragma opt_lifetimes reset
#undef MTXA
/* fzgx:end fn_1_1C0D0 */

/* fzgx:begin fn_1_1D0CC */
static inline f32 dot2(Vec3 *a, Vec3 *b)
{
    return (f32)(a->x * b->x) + (f32)(a->y * b->y);
}

static inline int finite(f32 x)
{
    return ((*(u32 *)&x & 0x7F800000) - 0x7F800000) != 0;
}

static inline f32 dist2(Vec3 *a, Vec3 *b)
{
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    f32 d;
    x -= b->x;
    y -= b->y;
    z -= b->z;
    d = x * x;
    d = y * y + d;
    d = z * z + d;
    return d;
}

static inline int allowed(CollCtx *ctx, Segment *seg, s32 id, int side)
{
    s32 index;
    s32 count;
    u32 needed;
    u32 flags;
    u32 mask;
    s32 other;
    s32 mode;
    if (ctx == 0) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index) return 0;
    if (!__rlwnm(flags, (side + 1) & 31, 31, 31)) return 0;
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) mask |= 0xC00;
    needed = seg->unk_0 & mask;
    other = ctx->unk_4->unk_4C[index];
    if (needed == (needed & flags) &&
        (ctx->unk_4->unk_1C[index] == seg || fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f))) {
        if (fn_1_7B054() == 0x10) {
            if (id >= 0x5F && id <= 0x79 && !(other >= 0x5F && other <= 0x79)) {
                mode = lbl_801A66CC->index;
                if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
            }
            return 1;
        } else if (fn_1_7B054() == 0x1C) {
            if (id >= 0x74 && id <= 0x90) {
                if (other < 0x74) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                }
                if (other > 0x90) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                return 1;
            } else if (id >= 0xA8 && id <= 0xC6) {
                if (other < 0xA8) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                if (other > 0xC6) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                }
                return 1;
            }
            return 1;
        }
        return 1;
    }
    return 0;
}

void fn_1_1D0CC(Vec3 *arg0, Vec3 *arg1, u32 arg2, Segment *arg3, Vec3 *arg4, CollCtx *arg5, void *arg6,
    s32 arg7, f32 arg8)
{
    Vec3 v0;
    s32 test2;
    Vec3 v1;
    Vec3 v0_world;
    Vec3 d;
    Vec3 p;
    u32 found;
    Vec3 tmp;
    u32 crossed;
    s32 use_world;
    s32 bit0;
    ColiContact *second;
    s32 circle;
    ColiContact *contact;
    s32 inside;
    s32 ok[2];
    s32 out;
    s16 angle;
    s16 course;
    u32 bit21;
    ColiWork *m;
    u32 mask;
    f32 sign;
    f32 t;
    f32 a;
    f32 b;
    f32 c;
    f32 root;
    f32 len2;
    f32 depth;
    f32 dist;

    mask = 0x20000000;
    found = 0;
    crossed = 0;
    fn_1_18784(arg2, (void *)arg3, (void *)arg4, (void *)arg6, arg8);
    bit0 = arg3->unk_0 & 1;
    test2 = 0;
    if (arg5 != 0 && bit0 == 0) test2 = 1;
    bit21 = arg2 & 0x200000;
    circle = 0;
    if (bit21 != 0 && __fabs(arg4->y / arg4->x - 1.0f) < 0.01f) circle = 1;
    use_world = circle;
    lbl_8006DAEC();
    lbl_8006DF44();
    lbl_8006E1B0(arg1, &v1);
    if (circle) {
        if (bit0) {
            v0.x = 0.0f;
            v0.y = 0.0f;
            v0.z = 0.0f;
        } else {
            len2 = (v1.x * v1.x) + (v1.y * v1.y);
            if (len2 < 1.0f) {
                use_world = 0;
            } else {
                f32 r = lbl_8006D0E8(len2);
                v0.x = v1.x + (f32)(2000.0f * (v1.x * r));
                v0.y = v1.y + (f32)(2000.0f * (v1.y * r));
                v0.z = 0.0f;
            }
        }
    }
    v1.x /= arg4->x;
    v1.y /= arg4->y;
    if (!use_world) lbl_8006E1B0(arg0, &v0);
    v0_world = v0;
    v0.x /= arg4->x;
    v0.y /= arg4->y;
    lbl_8006DB30();
    second = &lbl_801A66CC->hits[1];
    contact = &lbl_801A66CC->hits[0];
    sign = bit0 ? 1.0f : -1.0f;
    psvec_sub(&v0, &v1, &d);
    inside = !(sign * ((v0.x * v0.x) + (v0.y * v0.y) - 0.25f) >= 0.0f);
    /* retail clears bit 29 with rlwinm from a freshly loaded 0x20000000, which `&= ~0x20000000` does not give */
    if (inside) mask = __rlwinm(mask, 0, 3, 1);
    ok[0] = allowed(arg5, arg3, arg7, 2);
    a = dot2(&d, &d);
    b = dot2(&d, &v1);
    c = dot2(&v1, &v1) - 0.25f;
    if ((f32)(b * b) - (f32)(a * c) >= 0.0f) {
        root = lbl_8006D0B4((f32)(b * b) - (f32)(a * c));
        if (finite(root)) {
            root = sign * root;
            t = -(b + root) / a;
            if (0.0f <= t && t <= 1.0f && finite(t)) {
                crossed |= 0x20000000;
                if (second->flags == 0 || t < second->t) found = 0x20000000;
            }
            if (test2 && !ok[0] && !((found >> 29) & 1)) {
                t = -(b - root) / a;
                if (0.0f <= t && t <= 1.0f && finite(t)) {
                    crossed |= 0x02000000;
                    if (contact->flags == 0 || t < contact->t) found = 0x02000000;
                }
            }
        }
    }
    if (ok[0] && inside && !((found >> 29) & 1) && (arg2 & 0x02000000)) {
        crossed |= 0x20000000;
        if (second->flags == 0) {
            found = 0x20000000;
            t = 0.0f;
        }
    }
    out = ok[0];
    if (!out) out = sign * ((v1.x * v1.x) + (v1.y * v1.y) - 0.25f) >= 0.0f;
    if (test2 && found == 0 && (!out || (ok[1] = allowed(arg5, arg3, arg7, 29))) && !inside && (arg2 & 0x02000000)) {
        crossed |= 0x02000000;
        if (contact->flags == 0) {
            found = 0x02000000;
            t = 0.0f;
        }
    }
    if (((found >> 29) & 1) && !bit0 && (arg2 & 0x04000000) && !out) found &= ~0x20000000;
    if (found != 0) {
        psvec_scale_add(&v1, &d, t, &p);
        if ((found >> 25) & 1) {
            sign = -sign;
            bit0 = !bit0;
            mask = 0;
            found = 0;
        } else {
            contact = second;
        }
        if (use_world) {
            lbl_8006E1B0(&v0_world, &lbl_801A66CC->delta);
            psvec_sub_scale_add(&lbl_801A66CC->delta, arg1, t, &tmp, &contact->point);
        } else {
            psvec_sub_scale_add(arg0, arg1, t, &tmp, &contact->point);
        }
        contact->normal.x = tmp.x = sign * p.x;
        contact->normal.y = tmp.y = sign * p.y;
        contact->normal.z = tmp.z = 0.0f;
        lbl_8006E1C0(&contact->normal, &contact->normal);
        lbl_8006D668(&contact->normal);
        depth = sign * (0.5f - lbl_8006D0B4((v0.x * v0.x) + (v0.y * v0.y)));
        if (depth > 0.0f) {
            lbl_8006D5F0(&tmp, &tmp, depth);
            tmp.x *= arg4->x;
            tmp.y *= arg4->y;
            lbl_8006E1C0(&tmp, &contact->correction);
        } else {
            contact->correction.x = 0.0f;
            contact->correction.y = 0.0f;
            contact->correction.z = 0.0f;
        }
        if (use_world) {
            dist = lbl_8006D0B4(dist2(arg1, &contact->point));
            t = dist / lbl_8006D0B4(dist2(arg1, arg0));
            if (!finite(t)) t = 0.0f;
        }
        contact->t = t;
        contact->flags = bit0 ? 0x01000001 : 0x01000000;
        contact->unk_0 = lbl_801A66CC->index;
        contact->unk_4 = lbl_801A66CC->segment;
        contact->unk_8 = lbl_801A66CC->time;
        contact->link = arg5 != 0 ? &arg5->unk_0->unk_3C[arg5->unk_0->unk_0] : 0;
    }
    if (found != 0 && bit21 != 0) {
        course = fn_1_7B054();
        if (course == 0x21) {
            if ((lbl_801A66CC->segment >= 20 && lbl_801A66CC->segment <= 21) || (lbl_801A66CC->segment == 19 && 0.8f <= lbl_801A66CC->time) || (lbl_801A66CC->segment == 22 && 0.32f >= lbl_801A66CC->time)) {
                angle = lbl_8006D24C(v1.y, v1.x);
                if (angle >= 0x1800 && angle <= 0x6800) lbl_801A66CC->flags = 0x100000;
            } else {
                m = lbl_801A66CC;
                if (lbl_801A66CC->index == 2 && ((lbl_801A66CC->segment >= 38 && m->segment <= 39) || (lbl_801A66CC->segment == 40 && 0.877f >= lbl_801A66CC->time))) {
                angle = lbl_8006D24C(v1.y, v1.x);
                if (angle >= 0x1800 && angle <= 0x6800) lbl_801A66CC->flags = 0x100000;
                }
            }
        } else if (course == 0x23) {
            if (lbl_801A66CC->segment >= 91 && lbl_801A66CC->segment <= 102) {
                u16 uangle = lbl_8006D24C(v1.y, v1.x);
                if (uangle >= 0x6000 && uangle <= 0xA000) lbl_801A66CC->flags = 0x100000;
            }
        }
    }
    if (arg5 != 0) {
        u32 rest = crossed & ~0x02000000;
        arg5->unk_0->unk_1C[arg5->unk_0->unk_0] = arg3;
        arg5->unk_0->unk_2C[arg5->unk_0->unk_0] = arg4->x;
        arg5->unk_0->unk_3C[arg5->unk_0->unk_0] = arg3->unk_0 | (((crossed >> 25) & 1) ? 4 : 0);
        if (mask != 0 || found != 0 || rest != 0) {
            arg5->unk_0->unk_3C[arg5->unk_0->unk_0] |= 0xF0000000;
        }
        arg5->unk_0->unk_4C[arg5->unk_0->unk_0] = arg7;
        if (arg5->unk_0->unk_0 < 3) arg5->unk_0->unk_0++;
    }
}
/* fzgx:end fn_1_1D0CC */

/* fzgx:begin fn_1_1DCD8 */
static inline f32 fn_1_1DCD8_dot2(Vec3 *a, Vec3 *b)
{
    return (f32)(a->x * b->x) + (f32)(a->y * b->y);
}

static inline int fn_1_1DCD8_finite(f32 x)
{
    return ((*(u32 *)&x & 0x7F800000) - 0x7F800000) != 0;
}

static inline f32 fn_1_1DCD8_dist2(Vec3 *a, Vec3 *b)
{
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    f32 d;
    x -= b->x;
    y -= b->y;
    z -= b->z;
    d = x * x;
    d = y * y + d;
    d = z * z + d;
    return d;
}

static inline f32 fn_1_1DCD8_seg_fraction(Segment_1DCD8 *seg, f32 t)
{
    SegSrc *src = seg->unk_10;
    return src->unk_4->unk_28 != 0 ? fn_1_9E14C(src->unk_4->unk_4, src->unk_4->unk_28, t) : src->unk_18;
}

static inline int fn_1_1DCD8_allowed(CollCtx *ctx, Segment_1DCD8 *seg, s32 id, int side)
{
    s32 index;
    s32 count;
    u32 needed;
    u32 flags;
    u32 mask;
    s32 other;
    s32 mode;
    if (ctx == 0) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index) return 0;
    if (!__rlwnm(flags, (side + 1) & 31, 31, 31)) return 0;
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) mask |= 0xC00;
    needed = seg->unk_0 & mask;
    other = ctx->unk_4->unk_4C[index];
    if (needed == (needed & flags) &&
        (ctx->unk_4->unk_1C[index] == seg || fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f))) {
        if (fn_1_7B054() == 0x10) {
            if (id >= 0x5F && id <= 0x79 && !(other >= 0x5F && other <= 0x79)) {
                mode = lbl_801A66CC->index;
                if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
            }
            return 1;
        } else if (fn_1_7B054() == 0x1C) {
            if (id >= 0x74 && id <= 0x90) {
                if (other < 0x74) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                }
                if (other > 0x90) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                return 1;
            } else if (id >= 0xA8 && id <= 0xC6) {
                if (other < 0xA8) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                if (other > 0xC6) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                }
                return 1;
            }
            return 1;
        }
        return 1;
    }
    return 0;
}

void fn_1_1DCD8(Vec3 *arg0, Vec3 *arg1, u32 arg2, Segment_1DCD8 *arg3, Vec3 *arg4, CollCtx *arg5, void *arg6,
    s32 arg7, f32 arg8)
{
    Vec3 v0;
    Vec3 v1;
    Vec3 v0_world;
    Vec3 v1_world;
    Vec3 d;
    Vec3 p;
    Vec3 q;
    Vec3 tmp;
    f32 sn;
    f32 cs;
    s32 open;
    ColiContact *target;
    s32 hit;
    s32 hit_inner;
    s32 use_world;
    s32 edge;
    s32 closed;
    s32 flat;
    ColiContact *second;
    s32 circle;
    ColiContact *contact;
    s32 inside;
    s32 ok[2];
    f32 ratio;
    f32 sign;
    f32 radius;
    f32 half;
    f32 a;
    f32 b;
    f32 t;
    f32 c;
    f32 root;
    f32 len2;
    f32 depth;
    f32 dist;
    f32 y;
    f32 nx;
    f32 ny;

    radius = 0.5f;
    edge = 1;
    hit = 0;
    hit_inner = 0;
    if (arg3->unk_C == 1) {
        half = fn_1_1DCD8_seg_fraction(arg3, arg8);
        if (half < 0.0f) {
            half = 0.0f;
        } else if (half > 1.0f) {
            half = 1.0f;
        }
        lbl_8006D1BC((32768.0f * half), &sn, &cs);
        half = 0.5f * cs;
    }
    fn_1_18784(arg2, (void *)arg3, (void *)arg4, (void *)arg6, arg8);
    closed = arg3->unk_0 & 1;
    open = 0;
    if (arg5 != 0 && closed == 0) open = 1;
    ratio = arg4->y / arg4->x;
    flat = ratio < 0.1f;
    circle = 0;
    if ((arg2 & 0x200000) && __fabs(ratio - 1.0f) < 0.01f) circle = 1;
    use_world = circle;
    lbl_8006DAEC();
    lbl_8006DF44();
    lbl_8006E1B0(arg1, &v1);
    if (circle) {
        if (closed) {
            v0.x = 0.0f;
            v0.y = 0.0f;
            v0.z = 0.0f;
        } else {
            len2 = (v1.x * v1.x) + (v1.y * v1.y);
            if (len2 < 1.0f) {
                use_world = 0;
            } else {
                f32 r = lbl_8006D0E8(len2);
                v0.x = v1.x + (f32)(2000.0f * (v1.x * r));
                v0.y = v1.y + (f32)(2000.0f * (v1.y * r));
                v0.z = 0.0f;
            }
        }
    }
    v1_world = v1;
    v1.x /= arg4->x;
    v1.y /= arg4->y;
    if (!use_world) lbl_8006E1B0(arg0, &v0);
    v0_world = v0;
    v0.x /= arg4->x;
    v0.y /= arg4->y;
    lbl_8006DB30();
    second = &lbl_801A66CC->hits[1];
    contact = &lbl_801A66CC->hits[0];
    sign = closed ? 1.0f : -1.0f;
    psvec_sub(&v0, &v1, &d);
    inside = !(sign * (fn_1_1DCD8_dot2(&v0, &v0) - 0.25f) >= 0.0f);
    if (inside) edge = 0;
    ok[0] = fn_1_1DCD8_allowed(arg5, arg3, arg7, 2);
    if (flat) {
        radius = 0.5f + (10.0f * (lbl_801A66CC->unk_1B4 / arg4->x)) * (0.1f - arg4->y / arg4->x);
        if (arg2 & 0x80000) {
            lbl_8006D5A4(&v0_world, (u32)&v1_world, &q, 0.5f);
        } else if (arg2 & 0x40000) {
            q = v1_world;
        } else {
            q = v0_world;
        }
        y = __fabs(q.x) / (0.5f * arg4->x);
        if (y > 1.0f) y = 1.0f;
        y = sign * (0.5f * arg4->y) * lbl_8006D0B4(1.0f - (f32)(y * y));
        if (y >= v0_world.y) edge = 0;
        if (__fabs(q.x) <= radius * arg4->x) {
            t = (v1_world.y - y) / (v1_world.y - v0_world.y);
            if (v1_world.y >= v0_world.y) {
                if (0.0f <= t && t <= 1.0f && fn_1_1DCD8_finite(t)) {
                    hit = 1;
                } else if (v0_world.y <= y && y <= v1_world.y) {
                    t = 0.0f;
                    hit = 1;
                }
            } else if (open && !ok[0]) {
                if (0.0f <= t && t <= 1.0f && fn_1_1DCD8_finite(t)) {
                    hit_inner = 1;
                } else if (v0_world.y >= y && y >= v1_world.y) {
                    t = 0.0f;
                    hit_inner = 1;
                }
            }
        }
    } else {
        a = (d.x * d.x) + (d.y * d.y);
        b = (f32)(d.x * v1.x) + (f32)(d.y * v1.y);
        c = fn_1_1DCD8_dot2(&v1, &v1) - 0.25f;
        if ((f32)(b * b) - (f32)(a * c) >= 0.0f) {
            root = lbl_8006D0B4((f32)(b * b) - (f32)(a * c));
            if (fn_1_1DCD8_finite(root)) {
                root = sign * root;
                t = -(b + root) / a;
                if (0.0f <= t && t <= 1.0f && (second->flags == 0 || t < second->t) && fn_1_1DCD8_finite(t)) hit = 1;
                if (open && !hit && !ok[0]) {
                    t = -(b - root) / a;
                    if (0.0f <= t && t <= 1.0f && (contact->flags == 0 || t < contact->t) && fn_1_1DCD8_finite(t)) {
                        hit_inner = 1;
                    }
                }
            }
        }
        if (ok[0] && inside && second->flags == 0 && !hit && (arg2 & 0x02000000)) {
            t = 0.0f;
            hit = 1;
            hit_inner = 0;
        }
        if (!ok[0]) ok[0] = sign * (fn_1_1DCD8_dot2(&v1, &v1) - 0.25f) >= 0.0f;
        if (open && !hit && (!ok[0] || (ok[1] = fn_1_1DCD8_allowed(arg5, arg3, arg7, 29))) && !inside && contact->flags == 0 &&
            !hit_inner && (arg2 & 0x02000000)) {
            hit_inner = 1;
            t = 0.0f;
        }
    }
    if (hit_inner) hit = 1;
    psvec_scale_add(&v1, &d, t, &p);
    if (!flat && hit) {
        if (closed) {
            if (p.y < half) {
                hit = 0;
                hit_inner = 0;
            } else if ((arg2 & 0x04000000) && v1.y < half) {
                hit = 0;
                hit_inner = 0;
            }
        } else {
            f32 limit = -half;
            if (p.y > limit) {
                hit = 0;
                hit_inner = 0;
            } else if (arg2 & 0x04000000) {
                if (v1.y > limit) {
                    hit = 0;
                    hit_inner = 0;
                } else if (!ok[0]) {
                    hit = 0;
                    hit_inner = 0;
                }
            }
        }
    }
    if (flat && -radius <= v0.x && v0.x <= radius && !closed && v0.y > -half) edge = 1;
    if (hit) {
        if (hit_inner) {
            sign = -sign;
            target = contact;
            closed = !closed;
            hit = 0;
            edge = 0;
        } else {
            target = second;
        }
        if (use_world) {
            lbl_8006E1B0(&v0_world, &lbl_801A66CC->delta);
            psvec_sub_scale_add(&lbl_801A66CC->delta, arg1, t, &tmp, &target->point);
        } else {
            psvec_sub_scale_add(arg0, arg1, t, &tmp, &target->point);
        }
        if (flat) {
            nx = 0.0f;
            ny = closed ? 1.0f : -1.0f;
        } else {
            nx = p.x / arg4->x;
            ny = p.y / arg4->y;
            if (!fn_1_1DCD8_finite(ny)) {
                nx = 0.0f;
                ny = closed ? 1.0f : -1.0f;
            }
        }
        target->normal.x = tmp.x = sign * nx;
        target->normal.y = tmp.y = sign * ny;
        target->normal.z = tmp.z = 0.0f;
        lbl_8006E1C0(&target->normal, &target->normal);
        lbl_8006D668(&target->normal);
        if (flat) {
            depth = y - v0_world.y;
        } else {
            depth = sign * (radius - lbl_8006D0B4(fn_1_1DCD8_dot2(&v0, &v0)));
        }
        if (depth > 0.0f) {
            lbl_8006D5F0(&tmp, &tmp, depth);
            if (flat) {
                tmp.x *= arg4->x;
            } else {
                tmp.x *= arg4->x;
                tmp.y *= arg4->y;
            }
            lbl_8006E1C0(&tmp, &target->correction);
        } else {
            target->correction.x = 0.0f;
            target->correction.y = 0.0f;
            target->correction.z = 0.0f;
        }
        if (use_world) {
            dist = lbl_8006D0B4(fn_1_1DCD8_dist2(arg1, &target->point));
            t = dist / lbl_8006D0B4(fn_1_1DCD8_dist2(arg1, arg0));
            if (!fn_1_1DCD8_finite(t)) t = 0.0f;
        }
        target->t = t;
        target->flags = closed ? 0x00800001 : 0x00800000;
        target->unk_0 = lbl_801A66CC->index;
        target->unk_4 = lbl_801A66CC->segment;
        target->unk_8 = lbl_801A66CC->time;
        target->link = arg5 != 0 ? &arg5->unk_0->unk_3C[arg5->unk_0->unk_0] : 0;
    }
    if (arg5 != 0) {
        arg5->unk_0->unk_1C[arg5->unk_0->unk_0] = arg3;
        arg5->unk_0->unk_2C[arg5->unk_0->unk_0] = arg4->x;
        if (edge || hit) {
            arg5->unk_0->unk_3C[arg5->unk_0->unk_0] = arg3->unk_0 | 0xF0000000;
        } else {
            arg5->unk_0->unk_3C[arg5->unk_0->unk_0] = arg3->unk_0;
        }
        if (hit_inner) arg5->unk_0->unk_3C[arg5->unk_0->unk_0] |= 4;
        arg5->unk_0->unk_4C[arg5->unk_0->unk_0] = arg7;
        if (arg5->unk_0->unk_0 < 3) arg5->unk_0->unk_0++;
    }
}
/* fzgx:end fn_1_1DCD8 */

/* fzgx:begin fn_1_1EBD4 */
/* degrees to the s16 angle unit (the float converts at the call) */
#define COLI_DEG_TO_S16(deg) ((deg) * 65536.0f / 360.0f)

#define GAME_VEC3_H

#define LC ((f32 *)LC_BASE)

/* fzgx-allow: S2 pool primer sink */

static inline int fn_1_1EBD4_finite(f32 x)
{
    union { f32 f; u32 u; } bits;
    bits.f = x;
    return (bits.u & 0x7F800000) != 0x7F800000;
}

static inline void fn_1_1EBD4_translate_x(f32 scale)
{
    f32 x, y, z;
    f32 *axis;
    f32 *pos;
    /* retail holds the matrix base in its own saved register across loop 1 */
    axis = pos = LC;
    x = axis[0];
    y = axis[4];
    z = axis[8];
    x = x * scale + pos[3];
    y = y * scale + pos[7];
    z = z * scale + pos[11];
    pos[3] = x;
    pos[7] = y;
    pos[11] = z;
}

static inline void fn_1_1EBD4_translate_y(f32 scale)
{
    f32 x, y, z;
    x = LC[1];
    y = LC[5];
    z = LC[9];
    x = x * scale + LC[3];
    y = y * scale + LC[7];
    z = z * scale + LC[11];
    LC[3] = x;
    LC[7] = y;
    LC[11] = z;
}

static inline void fn_1_1EBD4_axis_y(Vec3 *out, f32 scale)
{
    f32 x, y, z;
    x = LC[1];
    y = LC[5];
    z = LC[9];
    x *= scale;
    y *= scale;
    z *= scale;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline int fn_1_1EBD4_allowed(Ctx *ctx, Segment *seg, int id, int side)
{
    s32 index;
    s32 count;
    u32 needed;
    u32 flags;
    u32 mask;
    s32 other;
    s32 mode;
    if (ctx == NULL) return 0;
    index = ctx->unk_0->unk_0;
    count = ctx->unk_4->unk_0;
    flags = ctx->unk_4->unk_3C[index];
    if (count <= index) return 0;
    if (!__rlwnm(flags, (side + 1) & 31, 31, 31)) return 0;
    mask = 0x03E00000;
    if (lbl_801A66CC->count == count) mask |= 0xC00;
    other = ctx->unk_4->unk_4C[index];
    needed = seg->unk_0 & mask;
    if (needed == (needed & flags)) {
        if (ctx->unk_4->unk_1C[index] == seg || fn_1_17B5C(other, id, lbl_1_bss_3BE0->unk_8, 200.0f)) {
            if (fn_1_7B054() == 0x10) {
                if (id >= 0x5F && id <= 0x79 && !(other >= 0x5F && other <= 0x79)) {
                    mode = lbl_801A66CC->index;
                    if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                }
                return 1;
            } else if (fn_1_7B054() == 0x1C) {
                if (id >= 0x74 && id <= 0x90) {
                    if (other < 0x74) {
                        mode = lbl_801A66CC->index;
                        if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                    }
                    if (other > 0x90) {
                        mode = lbl_801A66CC->index;
                        if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                    }
                    return 1;
                } else if (id >= 0xA8 && id <= 0xC6) {
                    if (other < 0xA8) {
                        mode = lbl_801A66CC->index;
                        if ((mode == 1 && side == 0) || (mode == 2 && side == 1)) return 0;
                    }
                    if (other > 0xC6) {
                        mode = lbl_801A66CC->index;
                        if ((mode == 1 && side == 1) || (mode == 2 && side == 0)) return 0;
                    }
                    return 1;
                }
                return 1;
            }
            return 1;
        }
    }
    return 0;
}

static inline void fn_1_1EBD4_slip(ColiWork *g)
{
    s32 n = g->segment;
    if ((n >= 0x1E && n <= 0x45) ||
        (n == 0x5C && 0.5f <= g->time) ||
        (n >= 0x5D && g->segment <= 0x60) ||
        (n == 0x61 && 0.5f >= g->time) ||
        (n >= 0x78 && g->segment <= 0x8B)) {
        g->flags = 0x80000;
    }
}

/* retail translates the locked-cache matrix in place (fmadds into the loaded register) */

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

void fn_1_1EBD4(Vec3 *arg0, Vec3 *arg1, u32 arg2, Segment *seg, Vec3 *scale, Ctx *ctx, void *arg6, int id, f32 arg8)
{
    Vec3 a;
    Vec3 b;
    Vec3 q;
    Vec3 d;
    Vec3 e;
    Vec3 dd;
    f32 up;
    u32 near;
    s32 side;
    s32 side2;
    u32 outer;
    u32 edge;
    u32 hits;
    u32 kind;
    s32 inside;
    f32 down;
    ColiContact *c;
    f32 width;
    f32 radius;
    s32 allowed;
    f32 sgn;
    f32 quarter;
    f32 zero;
    f32 ra;
    f32 rb;
    f32 t;
    f32 db;
    f32 disc;
    f32 s;
    f32 t2;
    s32 inside2;
    s32 found2;
    f32 da;
    f32 depth;
    f32 off;
    Vec3 p;
    s32 found;
    s32 n;
    s32 any;

    if (seg->unk_0 & 1) {
        kind = 0x400001;
        sgn = 1.0f;
    } else {
        kind = 0x400000;
        sgn = -1.0f;
    }
    outer = 0xF0000000;
    edge = 0xF0000000;
    hits = 0;
    fn_1_18784(arg2, (void *)seg, (void *)scale, (void *)arg6, arg8);
    quarter = 0.25f;
    near = arg2 & 0x02000000;
    zero = 0.0f;
    radius = lbl_801A66CC->unk_1DC;
    width = lbl_801A66CC->unk_1E0;
    for (side = 0; side <= 1; side++) {
        c = &lbl_801A66CC->hits[1];
        found = 0;
        lbl_8006DAEC();
        off = radius * (side == 0 ? 0.5f : -0.5f);
        fn_1_1EBD4_translate_x(off);
        fn_8006E250((void *)arg0, (void *)&a);
        a.x /= width;
        a.y /= width;
        fn_8006E250((void *)arg1, (void *)&b);
        b.x /= width;
        b.y /= width;
        psvec_sub(&a, &b, &d);
        ra = (a.x * a.x) + (a.y * a.y) - quarter;
        rb = (b.x * b.x) + (b.y * b.y) - quarter;
        inside = sgn * ra <= zero;
        if (inside) outer &= ~(0x80000000 >> side);
        if (ra > zero && rb > zero) edge &= ~(0x80000000 >> side);
        allowed = fn_1_1EBD4_allowed(ctx, seg, id, side);
        da = (d.x * d.x) + (d.y * d.y);
        db = (f32)(d.x * b.x) + (f32)(d.y * b.y);
        disc = (f32)(db * db) - (f32)(da * rb);
        if (disc >= zero) {
            s = lbl_8006D0B4(disc);
            if (fn_1_1EBD4_finite(s)) {
                t = -(db + (f32)(sgn * s)) / da;
                if (zero <= t && t <= 1.0f) {
                    if (c->flags == 0 || t < c->t) {
                        if (fn_1_1EBD4_finite(t)) found = 1;
                    }
                }
            }
        }
        if (allowed && !found && inside && c->flags == 0 && near) {
            found = 1;
            t = zero;
        }
        if (found) {
            f32 x = b.x + (f32)(t * d.x);
            if (side == 0) {
                if (x < zero) found = 0;
            } else {
                if (x > zero) found = 0;
            }
        }
        if (found) {
            psvec_scale_add(&b, &d, t, &q);
            psvec_sub(arg0, arg1, &e);
            psvec_scale_add(arg1, &e, t, &c->point);
            c->normal.x = e.x = sgn * q.x;
            c->normal.y = e.y = sgn * q.y;
            c->normal.z = e.z = zero;
            lbl_8006E1C0((void *)&c->normal, (void *)&c->normal);
            lbl_8006D668((void *)&c->normal);
            depth = sgn * (0.5f - lbl_8006D0B4((a.x * a.x) + (a.y * a.y)));
            if (depth > zero) {
                lbl_8006D5F0(&e, &e, depth);
                e.x *= width;
                e.y *= width;
                lbl_8006E1C0((void *)&e, (void *)&c->correction);
            } else {
                c->correction.x = zero;
                c->correction.y = zero;
                c->correction.z = zero;
            }
            c->t = t;
            c->flags = kind;
            c->unk_0 = lbl_801A66CC->index;
            c->unk_4 = lbl_801A66CC->segment;
            c->unk_8 = lbl_801A66CC->time;
            c->link = ctx != NULL ? &ctx->unk_0->unk_3C[ctx->unk_0->unk_0] : NULL;
            hits |= 0x80000000 >> side;
        }
        lbl_8006DB30();
    }
    up = 0.5f * width;
    zero = 0.0f;
    down = -0.5f * width;
    for (side2 = 2; side2 <= 3; side2++) {
        c = &lbl_801A66CC->hits[1];
        found2 = 0;
        lbl_8006DAEC();
        if (side2 == 3) mathutil_mtxA_rotate_z(COLI_DEG_TO_S16(180.0f));
        if (seg->unk_0 & 1) {
            fn_1_1EBD4_translate_y(up);
        } else {
            fn_1_1EBD4_translate_y(down);
        }
        fn_8006E250((void *)arg0, (void *)&a);
        a.x /= radius;
        fn_8006E250((void *)arg1, (void *)&b);
        b.x /= radius;
        inside2 = zero >= a.y;
        if (inside2) outer &= ~(0x80000000 >> side2);
        if ((zero < sgn * a.y && zero < sgn * b.y) || (-0.5f > a.x && -0.5f > b.x) || (0.5f < a.x && 0.5f < b.x)) {
            edge &= ~(0x80000000 >> side2);
        }
        allowed = fn_1_1EBD4_allowed(ctx, seg, id, side2);
        if (inside2 && b.y >= zero) {
            if (!((-0.5f > b.x && -0.5f > a.x) || (0.5f < b.x && 0.5f < a.x))) {
                t2 = b.y / (b.y - a.y);
                if (c->flags == 0 || t2 < c->t) {
                    if (fn_1_1EBD4_finite(t2)) found2 = 1;
                }
            }
        }
        if (!found2 && inside2 && c->flags == 0 && allowed && near) {
            found2 = 1;
            t2 = zero;
        }
        if (found2) {
            psvec_sub_scale_add(&a, &b, t2, &dd, &p);
            if ((allowed && !(seg->unk_0 & 1)) || (-0.5f <= p.x && p.x <= 0.5f)) {
                f32 depth2;

                psvec_sub_scale_add(arg0, arg1, t2, &dd, &c->point);
                c->normal.x = lbl_801A6D00[1];
                c->normal.y = lbl_801A6D00[5];
                c->normal.z = lbl_801A6D00[9];
                depth2 = -a.y;
                if (depth2 > zero) {
                    fn_1_1EBD4_axis_y(&c->correction, depth2);
                } else {
                    c->correction.x = zero;
                    c->correction.y = zero;
                    c->correction.z = zero;
                }
                c->t = t2;
                c->flags = kind;
                c->unk_0 = lbl_801A66CC->index;
                c->unk_4 = lbl_801A66CC->segment;
                c->unk_8 = lbl_801A66CC->time;
                c->link = ctx != NULL ? &ctx->unk_0->unk_3C[ctx->unk_0->unk_0] : NULL;
                hits |= 0x80000000 >> side2;
            }
        }
        lbl_8006DB30();
    }
    if (hits != 0 && (arg2 & 0x200000) && fn_1_7B054() == 0x20) {
        fn_1_1EBD4_slip(lbl_801A66CC);
    }
    if (!(seg->unk_0 & 1)) {
        any = 0;
        if ((edge >> 31) || ((edge >> 30) & 1) || (((edge >> 29) & 1) && ((edge >> 28) & 1))) any = 1;
        if (any || hits != 0) {
            outer = 0xF0000000;
        } else {
            outer = 0;
        }
    }
    if (ctx != NULL) {
        ctx->unk_0->unk_1C[ctx->unk_0->unk_0] = seg;
        ctx->unk_0->unk_2C[ctx->unk_0->unk_0] = scale->x;
        if ((outer | hits) != 0) {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] = seg->unk_0 | (outer | hits);
        } else {
            ctx->unk_0->unk_3C[ctx->unk_0->unk_0] = seg->unk_0;
        }
        ctx->unk_0->unk_4C[ctx->unk_0->unk_0] = id;
        if (ctx->unk_0->unk_0 < 3) ctx->unk_0->unk_0++;
    }
}

#pragma opt_lifetimes reset
#undef GAME_VEC3_H
#undef LC
/* fzgx:end fn_1_1EBD4 */

/* fzgx:begin fn_1_1FB80 */
/* 0x24-byte trigger volume entry */

u32 fn_1_1FB80(void *pos, u32 mask) {
    /* WARNING: compiler-diff device, not original code */
    struct { u32 value; } result;
    struct { s32 value; } i;
    struct { s32 value; } count;
    struct { ColiVolume_fn_1_1FB80 *value; } vol;
    Vec3 local;

    result.value = 0;
    i.value = 0;
    vol.value = 0;
    count.value = lbl_1_bss_3BE0->unk_9C;
    vol.value = (ColiVolume_fn_1_1FB80 *)lbl_1_bss_3BE0->unk_A0;
    for (; i.value < count.value; i.value++, vol.value++) {
        if (vol.value->flags & mask) {
            lbl_8006D7DC(vol.value);
            if (vol.value->rot_z) {
                mathutil_mtxA_rotate_z(vol.value->rot_z);
            }
            if (vol.value->rot_y) {
                mathutil_mtxA_rotate_y(vol.value->rot_y);
            }
            if (vol.value->rot_x) {
                mathutil_mtxA_rotate_x(vol.value->rot_x);
            }
            fn_8006E250((void *)pos, (void *)&local);
            if (__fabs(local.x) <= 5.0f * vol.value->size_x
             && __fabs(local.y) <= 5.0f * vol.value->size_y
             && __fabs(local.z) <= 5.0f * vol.value->size_z) {
                result.value |= vol.value->flags;
            }
        }
    }
    return result.value;
}
/* fzgx:end fn_1_1FB80 */

/* fzgx:begin fn_1_1FC98 */
/* 0x24-byte trigger volume entry */

u32 fn_1_1FC98(void *pos, u32 mask) {
    /* WARNING: compiler-diff device, not original code */
    struct { u32 value; } result;
    struct { s32 value; } i;
    struct { s32 value; } count;
    struct { ColiVolume_fn_1_1FB80 *value; } vol;
    Vec3 local;

    result.value = 0;
    i.value = 0;
    vol.value = 0;
    count.value = lbl_1_bss_3BE0->unk_94;
    vol.value = (ColiVolume_fn_1_1FB80 *)lbl_1_bss_3BE0->unk_98;
    for (; i.value < count.value; i.value++, vol.value++) {
        if (vol.value->flags & mask) {
            lbl_8006D7DC(vol.value);
            if (vol.value->rot_z) {
                mathutil_mtxA_rotate_z(vol.value->rot_z);
            }
            if (vol.value->rot_y) {
                mathutil_mtxA_rotate_y(vol.value->rot_y);
            }
            if (vol.value->rot_x) {
                mathutil_mtxA_rotate_x(vol.value->rot_x);
            }
            fn_8006E250((void *)pos, (void *)&local);
            if (__fabs(local.x) <= 5.0f * vol.value->size_x
             && __fabs(local.y) <= 5.0f * vol.value->size_y
             && __fabs(local.z) <= 5.0f * vol.value->size_z) {
                result.value |= vol.value->flags;
            }
        }
    }
    return result.value;
}
/* fzgx:end fn_1_1FC98 */

/* fzgx:begin fn_1_1FDB0 */
static inline f32 fn_1_1FDB0_squared_length(f32 x, f32 y, f32 z) {
 /* WARNING: compiler-diff device, not original code */
 struct { f32 value; } result;
 result.value = x*x;
 result.value += y*y;
 result.value += z*z;
 return result.value;
}

static inline BOOL fn_1_1FDB0_finite(f32 v) {
 return (*(u32 *)&v & 0x7f800000) != 0x7f800000;
}

static inline void fn_1_1FDB0_projection(f32 x, f32 y, f32 z, struct Vec *a, f32 *ax_out, f32 *ay_out, f32 *norm_out, f32 *dot_out) {
 /* WARNING: compiler-diff device, not original code */
 struct { f32 value; } norm, dot;
 f32 ax, ay;
 /* WARNING: compiler-diff device, not original code */
 ax = *(volatile f32 *)&a->x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
 dot.value = x*ax;
 norm.value = x*x;
 norm.value += y*y;
 norm.value += z*z;
 ay = a->y;
 dot.value += y*ay;
 dot.value += z*a->z;
 *ax_out = ax;
 *ay_out = ay;
 *norm_out = norm.value;
 *dot_out = dot.value;
}

f32 fn_1_1FDB0(struct fn_1_1FDB0_Arg0 *arg0, struct fn_1_1FDB0_Arg1 *arg1, struct fn_1_1FDB0_Arg2 *arg2, struct fn_1_1FDB0_Arg3 *arg3) {
 f32 t, norm, dot, ax, ay;
 struct Vec d, a, b;
 f32 l, m;
 psvec_sub(arg2,arg1,&d);
 psvec_sub(arg1,arg0,&a);
 fn_1_1FDB0_projection(d.x,d.y,d.z,&a,&ax,&ay,&norm,&dot);
 t = -dot / norm;
 if (!fn_1_1FDB0_finite(t)) {
  *arg3 = *(struct fn_1_1FDB0_Arg3 *)arg1;
  return lbl_8006D0B4(fn_1_1FDB0_squared_length(ax,ay,a.z));
 }
 if (0.0f <= t && t <= 1.0f) {
  psvec_scale(&d,t,&lbl_801A66CC->delta);
  psvec_add(&a,&lbl_801A66CC->delta,&a);
  psvec_add(arg1,&lbl_801A66CC->delta,arg3);
  return lbl_8006D0B4(fn_1_1FDB0_squared_length(a.x,a.y,a.z));
 }
 psvec_sub(arg2,arg0,&b);
 l=fn_1_1FDB0_squared_length(a.x,a.y,a.z);
 m=fn_1_1FDB0_squared_length(b.x,b.y,b.z);
 if (l<m) {
  *arg3=*(struct fn_1_1FDB0_Arg3 *)arg1;
  return lbl_8006D0B4(l);
 }
 *arg3=*(struct fn_1_1FDB0_Arg3 *)arg2;
 return lbl_8006D0B4(m);
}
/* fzgx:end fn_1_1FDB0 */

/* fzgx:begin fn_1_1FFA0 */
/* Treat an infinite/NaN result as zero (exponent field all ones). */

static inline BOOL fn_1_1FFA0_finite(f32 v) {
    return (*(u32 *)&v & 0x7F800000) != 0x7F800000;
}

#define FN_1_1FFA0_FINITE(v) fn_1_1FFA0_finite(v)

static inline f32 fn_1_1FFA0_squared_length(f32 x, f32 y, f32 z) {
    f32 result = x * x;
    result += y * y;
    result += z * z;
    return result;
}

/* Closest points between segments p1-p2 and p3-p4; returns their squared distance. */

f32 fn_1_1FFA0(Vec3 *p1, Vec3 *p2, Vec3 *p3, Vec3 *p4,
               Vec3 *outA, Vec3 *outB) {
    f32 p3x, p3y;
    f32 s;
    Vec3 diff;
    f32 t;
    f32 p3z, p1y;
    f32 d2y, d2z;
    f32 d1y, d1x, rx, d1z, rz;
    f32 d2x;
    f32 a, e, c, b, f;
    f32 ry;
    f32 p1z, p1x;

    p3x = p3->x;
    p1x = p1->x;
    rx = p1x - p3x;
    d2x = p4->x - p3x;
    d1x = p2->x - p1x;
    p3y = p3->y;
    p1y = p1->y;
    d2y = p4->y - p3y;
    d1y = p2->y - p1y;
    ry = p1y - p3y;
    p3z = p3->z;
    p1z = p1->z;
    d2z = p4->z - p3z;
    rz = p1z - p3z;
    d1z = p2->z - p1z;

    e = (f32)(rx * d2x) + (f32)(ry * d2y) + (f32)(rz * d2z);
    b = (f32)(d2x * d1x) + (f32)(d2y * d1y) + (f32)(d2z * d1z);
    c = (f32)(d2x * d2x) + (f32)(d2y * d2y) + (f32)(d2z * d2z);
    f = (f32)(rx * d1x) + (f32)(ry * d1y) + (f32)(rz * d1z);
    a = (f32)(d1x * d1x) + (f32)(d1y * d1y) + (f32)(d1z * d1z);

    s = ((f32)(e * b) - (f32)(f * c)) / ((f32)(a * c) - (f32)(b * b));
    if (!FN_1_1FFA0_FINITE(s)) {
        s = 0.0f;
    }
    t = (e + (f32)(s * b)) / c;
    if (!FN_1_1FFA0_FINITE(t)) {
        t = 0.0f;
    }

    psvec_sub(p2, p1, outA);
    if (s < 0.0f) {
        s = 0.0f;
    } else if (s > 1.0f) {
        s = 1.0f;
    }
    psvec_scale(outA, s, outA);
    psvec_add(p1, outA, outA);

    psvec_sub(p4, p3, outB);
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    psvec_scale(outB, t, outB);
    psvec_add(p3, outB, outB);

    psvec_sub(outB, outA, &diff);
    return fn_1_1FFA0_squared_length(diff.x, diff.y, diff.z);
}
/* fzgx:end fn_1_1FFA0 */

/* fzgx:begin fn_1_20258 */
f32 fn_1_20258(Fn_1_20258 *self, f32 *out_ratio) {
    u32 flags = self->flags;
    f32 ratio;
    f32 scale;

    if ((flags & 0x01c00000) != 0) {
        ratio = self->field34 / self->field30;
        if (ratio < 0.05) {
            ratio = 0.0f;
        }
    } else if ((flags & 0x02200000) != 0) {
        ratio = 1.0f;
    } else {
        OSReport("ERROR in coli.c (0) m_search: %08x\n", flags);
        OSPanic("coli.c", 0x1650,
                    "???");
    }

    if ((self->flags & 0x02200000) != 0 ||
        0.0f == ratio) {
        scale = self->field68;
    } else if ((self->flags & 0x01800000) != 0) {
        f32 t;

        t = 2.1415927f * ratio;
        scale = (1.0f + t) * (self->field6c * self->field68);
    } else if ((self->flags & 0x00400000) != 0) {
        f32 t;
        f64 prod;

        t = 2.1415927f * ratio;
        prod = 2.0 * self->field3c;
        scale = prod + (1.0f + t) * (self->field68 - self->field3c);
    } else {
        OSReport("ERROR in coli.c (1) m_search: %08x\n", self->flags);
        OSPanic("coli.c", 0x1661,
                    "???\n");
    }

    if (out_ratio != 0) {
        *out_ratio = ratio;
    }
    return scale;
}
#undef FN_1_1FFA0_FINITE
/* fzgx:end fn_1_20258 */

/* fzgx:begin fn_1_203E4 */
/* begin game/vec3.h (deltawave784/fzgx@7d73e43f (CC0)) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

/* end game/vec3.h */

/* The current matrix (mtxA) lives in the locked cache. */

#define MTXA ((f32(*)[4])LC_BASE)

/* mtxA translation along its x axis */

static inline void fn_1_203E4_translate_x(f32 (*mtx)[4], f32 d) {
    f32 x, y, z;
    x = ((0)[mtx])[0];
    y = ((1)[mtx])[0];
    z = ((2)[mtx])[0];
    x = x * d + mtx[0][3];
    y = y * d + mtx[1][3];
    z = z * d + mtx[2][3];
    mtx[0][3] = x;
    mtx[1][3] = y;
    mtx[2][3] = z;
}

/* Translation used by the curved section. */

static inline void fn_1_203E4_translate_curve(f32 (*mtx)[4], f32 d) {
    f32 x, y, z, xx, yy, zz;
    x = mtx[0][0];
    y = mtx[1][0];
    z = mtx[2][0];
    xx = mtx[0][3];
    yy = mtx[1][3];
    zz = mtx[2][3];
    x = x * d + xx;
    y = y * d + yy;
    z = z * d + zz;
    mtx[0][3] = x;
    mtx[1][3] = y;
    mtx[2][3] = z;
}

/* mtxA translation along its y axis */

static inline void fn_1_203E4_translate_y(f32 (*mtx)[4], f32 d) {
    f32 x, y, z;
    x = ((0)[mtx])[1];
    y = ((1)[mtx])[1];
    z = ((2)[mtx])[1];
    x = x * d + mtx[0][3];
    y = y * d + mtx[1][3];
    z = z * d + mtx[2][3];
    mtx[0][3] = x;
    mtx[1][3] = y;
    mtx[2][3] = z;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

void fn_1_203E4(fn_1_203E4_Obj *obj, s32 noOut, Vec3 *out, f32 pos, f32 scale, f32 dir) {
    f32 tz, ty, tx, distance;
    f32 (*mtx)[4];
    u32 flags;
    f32 half;
    f32 sign;

    if (0.0 == dir) {
        lbl_8006DC6C(obj);
        mtx = MTXA;
        /* Preserve the retail order of translation-column loads. */
        tx = obj->unk_70;
        ty = obj->unk_74;
        tz = obj->unk_78;
        ((0)[mtx])[3] = tx;
        ((1)[mtx])[3] = ty;
        ((2)[mtx])[3] = tz;
    } else {
        lbl_8006DBAC(obj);
    }
    flags = obj->unk_7C;
    if (flags & 1) {
        dir = -dir;
    }
    if ((flags & 0x2200000) || 0.0f == dir) {
        distance = pos * scale;
        fn_1_203E4_translate_x(mtx = MTXA, distance);
    } else if (flags & 0x1800000) {
        f64 angle, angleScale;
        lbl_8006E15C(1.0f, dir, 1.0f);
        angleScale = 32768.0;
        angle = 2.0;
        angle *= pos;
        mathutil_mtxA_rotate_z(angleScale * (angle * obj->unk_6C));
        fn_1_203E4_translate_y(mtx = MTXA, 0.5 * -obj->unk_68);
        if (noOut == 0 && (obj->unk_7C & 1)) {
            mathutil_mtxA_rotate_z_s_c(0.0f, -1.0f);
        }
    } else if (flags & 0x400000) {
        half = 0.5 * (obj->unk_3C / scale);
        sign = (pos > 0.0f) ? 1.0 : -1.0;
        if (1.0 != dir) {
            lbl_8006E15C(1.0f, dir, 1.0f);
        }
        if (__fabs(pos) < half) {
            lbl_8006E0B4(pos * scale, 0.5 * -obj->unk_40, 0.0f);
        } else {
            f64 poolHalf = 0.5;
            if (__fabs(pos) > poolHalf - half) {
                lbl_8006E0B4(scale * ((f64)(poolHalf * sign) - pos), poolHalf * obj->unk_40, 0.0f);
                if (noOut == 0) {
                    mathutil_mtxA_rotate_z_s_c(0.0f, -1.0f);
                }
            } else {
                pos = (pos - (f32)(sign * half)) / (poolHalf - (f64)(2.0 * half));
                fn_1_203E4_translate_curve(mtx = MTXA, poolHalf * (sign * obj->unk_3C));
                mathutil_mtxA_rotate_z(32768.0f * pos);
                fn_1_203E4_translate_y(mtx = MTXA, 0.5 * -obj->unk_40);
            }
        }
        if (noOut == 0 && (obj->unk_7C & 1)) {
            mathutil_mtxA_rotate_z_s_c(0.0f, -1.0f);
        }
    } else {
        OSReport("ERROR in coli.c (2) m_search: %08x\n", flags);
        OSPanic("coli.c", 0x16A5, "???\n");
    }
    if (noOut) {
        mtx = MTXA;
        psvec_set(out, ((2)[mtx])[3], ((1)[mtx])[3], ((0)[mtx])[3]);
    }
}

#pragma opt_lifetimes reset

#pragma opt_propagation reset
#undef GAME_VEC3_H
#undef MTXA
#undef fn_1_203E4_flip
/* fzgx:end fn_1_203E4 */

/* fzgx:begin fn_1_207DC */
static inline void set_f32(f32 *dst, f32 v) {
    if (dst) {
        *dst = v;
    }
}

void fn_1_207DC(struct fn_1_207DC_obj *obj, void *out, f32 x) {
    u32 flags = obj->unk_7C;
    u32 flags2;
    f32 t;
    f32 val;
    f32 prod;
    f64 d2;
    f32 arg6;

    if (flags & 0x1C00000) {
        t = obj->unk_34 / obj->unk_30;
        if (t < 0.05) {
            t = 0.0f;
        }
    } else if (flags & 0x2200000) {
        t = 1.0f;
    } else {
        OSReport("ERROR in coli.c (0) m_search: %08x\n", flags);
        OSPanic("coli.c", 0x1650, "???");
    }

    flags2 = obj->unk_7C;
    if ((flags2 & 0x2200000) || 0.0f == t) {
        val = obj->unk_68;
    } else if (flags2 & 0x1800000) {
        prod = 2.1415927f * t;
        val = (1.0f + prod) * (obj->unk_6C * obj->unk_68);
    } else if (flags2 & 0x400000) {
        prod = 2.1415927f * t;
        d2 = 2.0 * obj->unk_3C;
        val = d2 + (1.0f + prod) * (obj->unk_68 - obj->unk_3C);
    } else {
        OSReport("ERROR in coli.c (1) m_search: %08x\n", flags2);
        OSPanic("coli.c", 0x1661, "???\n");
    }

    set_f32(&arg6, t);
    fn_1_203E4((void *)obj, 1, (void *)out, x, val, arg6);
}
/* fzgx:end fn_1_207DC */

/* fzgx:begin fn_1_20994 */
int fn_1_20994(void *arg, f32 *out) {
    f32 value;
    int result;
    int index;
    Fn_1_20994_Object *object;

    value = 0.0f;
    result = 0;
    object = ((Fn_1_20994_Object *)lbl_1_bss_3BE0);
    if (object != 0) {
        if (object->unk_7D != 0) {
            index = 0;
        } else {
            index = object->unk_8 - 1;
        }
        do {
            result = ((int)fn_1_210A8((void *)arg, (void *)&value, index--, 0, (void *)0));
        } while (result < 0 && index >= 0);
        if (result < 0) {
            result = 0;
            value = 0.0f;
        }
    }
    *out = value;
    return result;
}
/* fzgx:end fn_1_20994 */

/* fzgx:begin fn_1_20A5C */
static inline f32 fn_1_20A5C_dot(Vec3 *a, Vec3 *b) {
    f32 r;
    f32 ax, ay, az;
    f32 bx, by, bz;
    ax = a->x;
    ay = a->y;
    az = a->z;
    bx = b->x;
    by = b->y;
    bz = b->z;
    r = ax * bx;
    r = ay * by + r;
    r = az * bz + r;
    return r;
}

s32 fn_1_20A5C(Vec3 *pos, f32 *out_t) {
    Vec3 closest;
    Vec3 f;
    Vec3 e;
    Vec3 d;
    s32 single;
    s32 count;
    s32 best;
    s16 *list;
    s32 n;
    s32 excl;
    s32 weighted;
    s32 id;
    s32 i;
    s32 end;
    s32 start;
    fn_1_20A5C_Rec *rec;
    s32 in0;
    s32 in1;
    fn_1_20A5C_Seg *seg;
    s32 cnt;
    s32 ix;
    s32 iz;
    s16 mode;
    f32 thr;
    f32 best_dist;
    f32 d0;
    f32 d1;
    f32 dist;
    f32 t;
    f32 ee;
    f32 ff;
    f32 dd;
    f32 de;
    f32 wt;
    f32 dx, dy, dz, ex, ey, ez;

    thr = (fn_1_7B054() == 25) ? 1.7f : 0.001f;
    *out_t = 0.0f;
    if (!lbl_1_bss_3BE0) {
        return -1;
    }
    count = ((ColiCourse *)lbl_1_bss_3BE0)->count;
    if (count == 0) {
        return -1;
    }
    best_dist = 0.0f;
    single = ((ColiCourse *)lbl_1_bss_3BE0)->single;
    best = -1;
    if (((ColiCourse *)lbl_1_bss_3BE0)->grid) {
        ix = fpscr_floorf((pos->x - ((ColiCourse *)lbl_1_bss_3BE0)->x0) / ((ColiCourse *)lbl_1_bss_3BE0)->sx);
        iz = fpscr_floorf((pos->z - ((ColiCourse *)lbl_1_bss_3BE0)->z0) / ((ColiCourse *)lbl_1_bss_3BE0)->sz);
        if (ix < 0) {
            ix = 0;
        } else if (ix > ((ColiCourse *)lbl_1_bss_3BE0)->nx - 1) {
            ix = ((ColiCourse *)lbl_1_bss_3BE0)->nx - 1;
        }
        if (iz < 0) {
            iz = 0;
        } else if (iz > ((ColiCourse *)lbl_1_bss_3BE0)->nz - 1) {
            iz = ((ColiCourse *)lbl_1_bss_3BE0)->nz - 1;
        }
        list = ((ColiCourse *)lbl_1_bss_3BE0)->grid[ix + iz * ((ColiCourse *)lbl_1_bss_3BE0)->nx];
        if (!list) {
            return -1;
        }
    }
    mode = fn_1_7B054();
    excl = mode == 29;
    weighted = mode != 8;
    n = 0;
    for (;;) {
        if (((ColiCourse *)lbl_1_bss_3BE0)->grid) {
            id = list[n];
            if (id < 0) {
                break;
            }
        } else {
            id = n;
            if (n >= count) {
                break;
            }
        }
        n++;
        if (excl && ((id >= 0x6B && id <= 0xDE) || (id >= 0xF2 && id <= 0x131) ||
                     (id >= 0x13 && id <= 0x24) || id == 0x25 || id == 0xF1)) {
            continue;
        }
        seg = &((ColiCourse *)lbl_1_bss_3BE0)->segs[id];
        cnt = seg->count;
        if (cnt > 1) {
            end = cnt - 1;
            start = 1;
        } else {
            start = 0;
            end = 0;
        }
        rec = seg->recs;
        for (i = start; i <= end; i++, rec++) {
            f32 n1z;
            f32 n1y;
            f32 n1x;
            f32 z;
            f32 y;
            f32 x;
            f32 n2z;
            f32 n2y;
            f32 n2x;
            f32 p0;
            f32 p1;
            x = pos->x;
            y = pos->y;
            z = pos->z;
            n1x = rec->n0.x;
            n1y = rec->n0.y;
            n1z = rec->n0.z;
            n2x = rec->n1.x;
            n2y = rec->n1.y;
            n2z = rec->n1.z;
            p0 = x * n1x;
            p1 = x * n2x;
            p0 += y * n1y;
            p1 += y * n2y;
            p0 += z * n1z;
            p1 += z * n2z;
            d0 = rec->d0 + p0;
            d1 = rec->d1 + p1;
            if (id == 0) {
                in1 = -thr <= d1;
                in0 = z < 0.0f;
                if (single) {
                    in0 = 1;
                }
            } else if (id == count - 1) {
                in1 = z >= 0.0f;
                in0 = -thr <= d0;
                if (single && fn_1_7B054() != 41) {
                    in1 = 1;
                }
            } else {
                in1 = -thr <= d1;
                in0 = -thr <= d0;
            }
            if (in0 && in1) {
                psvec_sub(&rec->b, &rec->a, &d);
                psvec_sub(&rec->a, pos, &e);
                de = fn_1_20A5C_dot(&d, &e);
                dd = fn_1_20A5C_dot(&d, &d);
                t = -de / dd;
                if ((*(u32 *)&t & 0x7F800000) == 0x7F800000) {
                    closest = rec->a;
                    ee = fn_1_20A5C_dot(&e, &e);
                    dist = lbl_8006D0B4(ee);
                } else if (0.0f <= t && t <= 1.0f) {
                    f32 s = t;
                    psvec_scale(&d, s, &lbl_801A66CC->delta);
                    psvec_add(&e, &lbl_801A66CC->delta, &e);
                    psvec_add(&rec->a, &lbl_801A66CC->delta, &closest);
                    ee = e.x * e.x;
                    ee = e.y * e.y + ee;
                    ee = e.z * e.z + ee;
                    dist = lbl_8006D0B4(ee);
                } else {
                    psvec_sub(&rec->b, pos, &f);
                    ee = fn_1_20A5C_dot(&e, &e);
                    ff = fn_1_20A5C_dot(&f, &f);
                    if (ee < ff) {
                        closest = rec->a;
                        dist = lbl_8006D0B4(ee);
                    } else {
                        closest = rec->b;
                        dist = lbl_8006D0B4(ff);
                    }
                }
                if (weighted) {
                    wt = 0.5f * rec->w;
                    dist -= wt;
                }
                if (best < 0 || dist < best_dist) {
                    best = id;
                    best_dist = dist;
                    *out_t = d0 / (d0 + d1);
                }
            }
        }
    }
    return best;
}
/* fzgx:end fn_1_20A5C */

/* fzgx:begin fn_1_210A8 */
/* one 0x50-byte record of a course segment, picked by the mode argument */

/* the course header's segment table (header +0xC, header +0x8 entries) */

/* retail loads every component into its own register before the products: opt_propagation off
 * keeps the component locals (as fn_1_216F0 does) */

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

s32 fn_1_210A8(Vec3 *pos, f32 *out_t, s32 index, s32 mode, Vec3 *out_pos) {
    s32 single;
    s32 k;
    s32 count;
    u32 ref;
    s32 refid;
    fn_1_210A8_Seg *segs;
    s32 result;
    s32 side;
    fn_1_210A8_Rec *rec;
    s32 cur;
    s32 in0;
    s32 in1;
    s32 step[2];
    s32 skip[2];
    s32 prev0[2];
    s32 prev1[2];
    f32 thr;
    f32 n1z;
    f32 n1y;
    f32 n1x;
    f32 z;
    f32 y;
    f32 x;
    f32 n2z;
    f32 n2y;
    f32 n2x;
    f32 d1;
    f32 d0;

    thr = (fn_1_7B054() == 25) ? 1.7f : 0.001f;
    *out_t = 0.0f;
    if (out_pos != NULL) {
        *out_pos = *pos;
    }
    if (lbl_1_bss_3BE0 == NULL) {
        return -1;
    }
    count = lbl_1_bss_3BE0->unk_8;
    segs = (fn_1_210A8_Seg *)lbl_1_bss_3BE0->unk_C;
    if (count == 0) {
        return -1;
    }
    if (index < 0 || count <= index) {
        return -1;
    }
    step[0] = 0;
    step[1] = -1;
    skip[0] = skip[1] = 0;
    result = -1;
    prev1[0] = prev1[1] = 1;
    prev0[0] = prev0[1] = 1;
    single = lbl_1_bss_3BE0->unk_7D;
    ref = segs[index].unk_8->unk_0;
    refid = segs[index].unk_0;
    for (k = 0; k < count; k++) {
        side = single ? 0 : __rlwinm(k, 0, 31, 31);
        cur = (index + step[side] + count) % count;
        if (mode != 0 && (ref != segs[cur].unk_8->unk_0 || refid != segs[cur].unk_0)) {
            skip[side] = 1;
        }
        if (side) {
            step[side]--;
        } else {
            step[side]++;
        }
        if (skip[side] != 0) {
            continue;
        }
        rec = &segs[cur].unk_4[mode];
        x = pos->x;
        y = pos->y;
        z = pos->z;
        n1x = rec->unk_C;
        n1y = rec->unk_10;
        n1z = rec->unk_14;
        n2x = rec->unk_28;
        n2y = rec->unk_2C;
        n2z = rec->unk_30;
        d0 = x * n1x;
        d1 = x * n2x;
        d0 += y * n1y;
        d1 += y * n2y;
        d0 += z * n1z;
        d1 += z * n2z;
        d0 = rec->unk_8 + d0;
        d1 = rec->unk_24 + d1;
        if (cur == 0) {
            in1 = -thr <= d1;
            in0 = pos->z < 0.0f;
            if (single) {
                in0 = 1;
            }
        } else if (cur == count - 1) {
            in1 = pos->z >= 0.0f;
            in0 = -thr <= d0;
            if (single && fn_1_7B054() != 41) {
                in1 = 1;
            }
        } else {
            in1 = -thr <= d1;
            in0 = -thr <= d0;
        }
        if (in0 && in1) {
            result = cur;
            *out_t = d0 / (d0 + d1);
            if (out_pos != NULL) {
                psvec_sub(&rec->unk_34, &rec->unk_18, &lbl_801A66CC->delta);
                psvec_scale_add(&rec->unk_18, &lbl_801A66CC->delta, *out_t, out_pos);
            }
            break;
        }
        if ((side == 0 && prev1[side] == 0 && !in0) || (side != 0 && prev0[side] == 0 && !in1)) {
            result = -1;
            break;
        }
        prev0[side] = in0;
        prev1[side] = in1;
    }
    return result;
}

#pragma opt_propagation reset
/* fzgx:end fn_1_210A8 */

/* fzgx:begin fn_1_214C4 */
/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

s32 fn_1_214C4(f32 *out, s32 start, f32 x) {
    Obj_1_bss_3BE0_Target *tbl;
    s32 v;
    s32 offset;
    s32 *p;
    s32 i;
    s32 sum;
    s32 idx;
    s32 loc[2];
    f32 t;
    f32 period;
    s32 n;
    s32 found;
    *out = 0.0f;
    if (lbl_1_bss_3BE0 == 0) {
        return 0;
    }
    n = lbl_1_bss_3BE0->unk_8;
    if (n == 0) {
        return 0;
    }
    if (start < 0 || n <= start) {
        start = 0;
    }
    found = 0;
    loc[0] = 0;
    loc[1] = -1;
    t = x;
    if ((((*(u32 *)&t) & 0x7F800000) - 0x7F800000) == 0) {
        return 0;
    }
    while (x < 0.0f) {
        period = *(f32 *)lbl_1_bss_3BE0->unk_90;
        x += period;
    }
    while (x >= *(f32 *)lbl_1_bss_3BE0->unk_90) {
        x -= *(f32 *)lbl_1_bss_3BE0->unk_90;
    }
    /* Reload the shared table pointer after normalizing the position. */
    tbl = *(Obj_1_bss_3BE0_Target **)&lbl_1_bss_3BE0;
    p = loc;
    for (i = 0; i < n; i++) {
        Seg_214C4 *s;
        f32 lo;
        f32 hi;
        offset = (i & 1) * 4;
        v = *(s32 *)((u8 *)p + offset);
        sum = v + n;
        idx = (start + sum) % n;
        if (i & 1) {
            *(s32 *)((u8 *)p + offset) = v - 1;
        } else {
            *(s32 *)((u8 *)p + offset) = v + 1;
        }
        s = ((Ent *)tbl->unk_C)[idx].seg;
        lo = s->lo;
        hi = s->hi;
        if (lo <= x && x <= hi) {
            *out = (x - lo) / (hi - lo);
            found = idx;
            break;
        }
    }
    return found;
}
/* fzgx:end fn_1_214C4 */

/* fzgx:begin fn_1_21644 */
void *fn_1_21644(void *arg0, f32 *arg1, void *arg2) {
    int local;

    int status;

    local = 0;
    status = ((int)fn_1_16BA0((void *)arg0, (void *)arg1, (s32)arg2, (void *)&local, 0));
    if (status < 0) {
        local = 0;
        *arg1 = fn_1_16E68((void *)arg0, (s32)arg2, 0);
        return arg2;
    }
    return (void *)status;
}
/* fzgx:end fn_1_21644 */

/* fzgx:begin fn_1_216C0 */
void fn_1_216C0(void *arg0, void *arg1, void *arg2) {
    int local;

    local = 0;
    ((int)fn_1_16BA0((void *)arg0, (void *)arg1, (s32)arg2, (void *)((int *)(&local)), 0));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_216C0 */

/* fzgx:begin fn_1_216F0 */
/* a 0x50-byte record of a course segment: two boundary planes (distance unk_8 with normal unk_C,
 * distance unk_24 with normal unk_28), as fn_1_16E68 reads them */

/* a 12-byte entry of the course header's unk_C table */

/* retail loads every component into its own register before the products: opt_propagation off
 * keeps the component locals (as fn_1_16E68 does) */

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

s32 fn_1_216F0(Vec3 *pos, s32 idx, s32 sub) {
    fn_1_216F0_Rec *p;
    fn_1_216F0_Seg *seg;
    s32 count;
    s32 ok_a;
    s32 ok_b;
    s32 flag;
    f32 thresh;
    f32 n1z;
    f32 n1y;
    f32 n1x;
    f32 z;
    f32 y;
    f32 x;
    f32 n2z;
    f32 n2y;
    f32 n2x;
    f32 b;
    f32 a;

    if (fn_1_7B054() == 25) {
        thresh = 1.7f;
    } else {
        thresh = 0.001f;
    }
    if (lbl_1_bss_3BE0 == NULL) {
        return -1;
    }
    count = lbl_1_bss_3BE0->unk_8;
    if (count == 0) {
        return -1;
    }
    if (idx < 0 || count <= idx) {
        idx = 0;
    }
    seg = (fn_1_216F0_Seg *)lbl_1_bss_3BE0->unk_C;
    p = seg[idx].unk_4 + sub;
    flag = lbl_1_bss_3BE0->unk_7D;
    x = pos->x;
    y = pos->y;
    z = pos->z;
    n1x = p->unk_C.x;
    n1y = p->unk_C.y;
    n1z = p->unk_C.z;
    n2x = p->unk_28.x;
    n2y = p->unk_28.y;
    n2z = p->unk_28.z;
    a = x * n1x;
    b = x * n2x;
    a += y * n1y;
    b += y * n2y;
    a += z * n1z;
    b += z * n2z;
    a = p->unk_8 + a;
    b = p->unk_24 + b;
    if (idx == 0) {
        ok_b = -thresh <= b;
        ok_a = pos->z < 0.0f;
        if (flag) {
            ok_a = 1;
        }
    } else if (idx == count - 1) {
        ok_b = pos->z >= 0.0f;
        ok_a = -thresh <= a;
        if (flag && fn_1_7B054() != 41) {
            ok_b = 1;
        }
    } else {
        ok_b = -thresh <= b;
        ok_a = -thresh <= a;
    }
    if (!ok_a || !ok_b) {
        if (fn_1_7B054() == 7 && idx >= 32 && idx <= 43) {
            if (p->unk_20 - 0.3f <= pos->z && pos->z <= p->unk_3C + thresh) {
                return idx;
            }
        }
        return -1;
    }
    return idx;
}

#pragma opt_propagation reset
/* fzgx:end fn_1_216F0 */

/* fzgx:begin fn_1_2192C */
void fn_1_2192C(void *self, void *arg, f32 t) {
    fn_1_18214((void *)self, (void *)arg, (void *)0, t);
}
/* fzgx:end fn_1_2192C */

/* fzgx:begin fn_1_21950 */
#define GX_FIFO (*(volatile f32 *)((u8 *)0xCC010000 - 0x8000))  /* fzgx-allow: A1,A2 GX write-gather FIFO pipe */

static inline void gx_pos3(f32 x, f32 y, f32 z) {
    GX_FIFO = x;
    GX_FIFO = y;
    GX_FIFO = z;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_21950(u32 arg0, f32 arg1, f32 arg2) {
    f32 v11_2;
    u32 v2;
    u32 v5;
    f32 v4;
    f32 v6;
    f32 v7;
    f32 v8;
    f32 v9;
    f32 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    f32 loc_44[3];
    f32 loc_38[3];
    f32 loc_2C[3];
    f32 loc_20[3];
    f32 loc_14[3];
    f32 loc_8[3];
    void * lab_t0;
    /* frame */

    v2 = (0.0f != arg1);
    v5 = (0.0f != arg2);
    v4 = -0.5f;
    loc_8[0] = v4;
    loc_8[1] = 0.0f;
    loc_8[2] = 0.0f;
    loc_8[0] = (v4 * *(f32 *)(arg0));
    lab_t0 = loc_8;
    lbl_8006E1B0(lab_t0, loc_8);
    v6 = 0.0f;
    v7 = 0.5f;
    loc_14[1] = v6;
    loc_14[0] = v7;
    loc_14[2] = v6;
    loc_14[0] = (v7 * *(f32 *)(arg0));
    lbl_8006E1B0(loc_14, loc_14);
    if ((s32)v2 != 0) {
    v8 = 0.0f;
    v9 = -0.5f;
    loc_20[1] = v8;
    loc_20[0] = v9;
    loc_20[2] = v8;
    loc_20[0] = (v9 * *(f32 *)(arg0));
    lbl_8006E1B0(loc_20, loc_20);
    v11 = 0.0f;
    v10 = -0.5f;
    loc_2C[1] = arg1;
    loc_2C[0] = v10;
    loc_2C[2] = v11;
    loc_2C[0] = (v10 * *(f32 *)(arg0));
    lbl_8006E1B0(loc_2C, loc_2C);
    }
    if ((s32)v5 != 0) {
    v11_2 = 0.0f;
    v12 = 0.5f;
    loc_38[1] = v11_2;
    loc_38[0] = v12;
    loc_38[2] = v11_2;
    loc_38[0] = (v12 * *(f32 *)(arg0));
    lbl_8006E1B0(loc_38, loc_38);
    v14 = 0.0f;
    v13 = 0.5f;
    loc_44[1] = arg2;
    loc_44[0] = v13;
    loc_44[2] = v14;
    loc_44[0] = (v13 * *(f32 *)(arg0));
    lbl_8006E1B0(loc_44, loc_44);
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    fn_8003462C(0xb0, 0, 2);
    GX_FIFO = loc_8[0];
    GX_FIFO = loc_8[1];
    GX_FIFO = loc_8[2];
    GX_FIFO = loc_14[0];
    GX_FIFO = loc_14[1];
    GX_FIFO = loc_14[2];
    if ((s32)v2 != 0) {
    fn_8003462C(0xb0, 0, 2);
    gx_pos3(loc_20[0], loc_20[1], loc_20[2]);
    gx_pos3(loc_2C[0], loc_2C[1], loc_2C[2]);
    }
    if ((s32)v5 != 0) {
    fn_8003462C(0xb0, 0, 2);
    gx_pos3(loc_38[0], loc_38[1], loc_38[2]);
    gx_pos3(loc_44[0], loc_44[1], loc_44[2]);
    }
    lbl_8006DB30();
}
/* fzgx:end fn_1_21950 */

/* fzgx:begin fn_1_21BE4 */
#pragma opt_propagation reset

void fn_1_21BE4(Fn_1_21BE4 *self, void *arg, f32 t) {
    f32 value2;
    f32 value1;

    fn_1_18214((void *)self, (void *)arg, (void *)0, t);
    if ((self->flags & 0x800) != 0) {
        value2 = self->field3c;
    } else {
        value2 = 0.0f;
    }
    if ((self->flags & 0x400) != 0) {
        value1 = self->field40;
    } else {
        value1 = 0.0f;
    }
    fn_1_21950( (u32)(arg), value1, value2);
}
/* fzgx:end fn_1_21BE4 */

/* fzgx:begin fn_1_21C5C */
void fn_1_21C5C(void *self, void *arg, f32 t) {
    fn_1_18214((void *)self, (void *)arg, (void *)0, t);
    fn_1_21950( (u32)(arg), 1.0f, 1.0f);
}
/* fzgx:end fn_1_21C5C */

/* fzgx:begin fn_1_21CA0 */
void fn_1_21CA0(Fn_1_21BE4 *self, void *arg) {
    f32 value2;
    f32 value1;

    if ((self->flags & 0x800) != 0) {
        value2 = self->field3c;
    } else {
        value2 = 0.0f;
    }
    if ((self->flags & 0x400) != 0) {
        value1 = self->field40;
    } else {
        value1 = 0.0f;
    }
    fn_1_21950( (u32)(arg), value1, value2);
}
/* fzgx:end fn_1_21CA0 */

/* fzgx:begin fn_1_21CFC */
/* 0.0f */

/* 0.5f */

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */

#define STCOLI_GX_WRITE_F32(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v)) /* Hardware access must remain ordered. */

static inline void fn_1_21CFC_Position3f32(f32 x, f32 y, f32 z) {
    STCOLI_GX_WRITE_F32(x);
    STCOLI_GX_WRITE_F32(y);
    STCOLI_GX_WRITE_F32(z);
}

/* WARNING: compiler-diff device, not original code */
extern const f32 lbl_1_rodata_6D0; /* the TU's own 0.0f literal, exported by the unit's pool map */

void fn_1_21CFC(void *entity, Vec3 *scale, f32 t) {
    f32 y;
    f32 z;
    Vec3 points[16];
    Vec3 *point;
    s32 i;
    s32 angle;

    fn_1_18214((void *)entity, (void *)scale, (void *)NULL, t);
    z = lbl_1_rodata_6D0;
    point = points;
    for (i = 0, angle = 0; i < 16; i++, angle += 0x1000) {
        y = 0.5f * lbl_8006D188(angle + 0x4000);
        point->x = 0.5f * lbl_8006D188(angle);
        point->y = y;
        point->z = z;
        point->x *= scale->x;
        point->y *= scale->y;
        lbl_8006E1B0( (Vec3 *)(point), (Vec3 *)(point));
        point++;
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    point = points;
    fn_8003462C(0xB0, 0, 17);
    for (i = 0; i < 16; i++) {
        fn_1_21CFC_Position3f32(point->x, point->y, point->z);
        point++;
    }
    STCOLI_GX_WRITE_F32(points[0].x);
    STCOLI_GX_WRITE_F32(points[0].y);
    STCOLI_GX_WRITE_F32(points[0].z);
    lbl_8006DB30();
}
#undef GX_FIFO
#undef STCOLI_GX_WRITE_F32
/* fzgx:end fn_1_21CFC */

/* fzgx:begin fn_1_21F18 */
/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* end game/main_rel/car_test_types.h */

/* GX write-gather pipe: every store must reach the FIFO, hence volatile. */
#define GX_WRITE_F32(v) (*(volatile f32 *)GX_FIFO_BASE = (v))

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GX_WRITE_F32(x);
    GX_WRITE_F32(y);
    GX_WRITE_F32(z);
}

/* WARNING: compiler-diff device, not original code */
extern f32 lbl_1_rodata_6C8[2]; /* the TU's own literal pool, exported by the unit's pool map */
/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off
void fn_1_21F18(StcoliDrawEntity *entity, f32 *scale, f32 time) {
    StcoliPool6C8_21F18 *pool;
    Vec3 v;
    Vec3 pts[16];
    Vec3 *p;
    s32 i;
    s32 angle;
    f32 half;
    f32 c;
    f32 zero;
    f32 t;
    StcoliCurveOwner *owner;
    StcoliCurveSrc *src;

    pool = (StcoliPool6C8_21F18 *)lbl_1_rodata_6C8;
    fn_1_18214((void *)entity, (void *)scale, (void *)NULL, time);
    zero = pool->zero;
    half = pool->half;
    p = pts;
    for (i = 0, angle = 0; i < 16; i++, angle += 0x1000) {
        c = half * lbl_8006D188((angle + 0x4000));
        p->x = half * lbl_8006D188(angle);
        p->y = c;
        p->z = zero;
        p->x *= ((scale)[0]);
        p->y *= ((scale)[1]);
        lbl_8006E1B0((void *)p, (void *)p);
        p++;
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    p = pts;
    fn_8003462C(0xb0, 0, 17);
    for (i = 0; i < 16; i++) {
        GXPosition3f32(p->x, p->y, p->z);
        p++;
    }
    GX_WRITE_F32(pts[0].x);
    GX_WRITE_F32(pts[0].y);
    GX_WRITE_F32(pts[0].z);
    lbl_8006DB30();

    if (entity->mode == 1) {
        owner = entity->owner;
        src = owner->src;
        if (src->curve != NULL) {
            t = fn_1_9E14C(src->key, (u32)src->curve, time);
        } else {
            t = owner->value;
        }
        {
            /* WARNING: compiler-diff device, not original code */
            volatile StcoliPool6C8_21F18 *components = pool;
            f32 n = components->neg_half;
            f32 z = components->zero;
            f32 x;
            f32 y = n + t;
            x = components->half;
            v.z = z;
            v.x = x;
            v.y = y;
            v.x = x * ((scale)[0]);
            v.y = y * ((scale)[1]);
        }
        lbl_8006E1B0((void *)&v, &pts[0]);
        v.x = -v.x;
        lbl_8006E1B0((void *)&v, &pts[1]);
        lbl_8006DAEC();
        lbl_8006DCA4();
        fn_80072558();
        fn_8003462C(0xb0, 0, 2);
        GX_WRITE_F32(pts[0].x);
        GX_WRITE_F32(pts[0].y);
        GX_WRITE_F32(pts[0].z);
        GX_WRITE_F32(pts[1].x);
        GX_WRITE_F32(pts[1].y);
        GX_WRITE_F32(pts[1].z);
        lbl_8006DB30();
    }
}
#pragma opt_common_subs reset

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef GX_WRITE_F32
/* fzgx:end fn_1_21F18 */

/* fzgx:begin fn_1_2221C */
/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@215f1cd8) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* end game/main_rel/car_test_types.h */

#define LC_MTX ((f32 (*)[4])LC_BASE)

/* GX write-gather FIFO: the compiler is free to reorder these stores */

#define GX_FIFO_F32 (*(f32 *)GX_FIFO_BASE)

static inline void fn_1_2221C_pos3(f32 x, f32 y, f32 z) {
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y;
    GX_FIFO_F32 = z;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_lifetimes off

/* WARNING: compiler-diff device, not original code */
#pragma opt_propagation off

void fn_1_2221C(fn_1_2221C_Obj *obj, Vec3 *scale, f32 t) {
    f32 tz;
    f32 ty;
    f32 tx;
    Vec3 *q;
    Vec3 *b;
    Vec3 *p;
    f32 zero;
    f32 width;
    f32 half;
    f32 y;
    f32 radius;
    f32 offset;
    f32 value;
    f32 x;
    s32 output_i;
    s32 i;
    s32 j;
    fn_1_2221C_Anim *anim;
    s32 angle;
    Vec3 buf[18];
    /* WARNING: compiler-diff device, not original code */
    struct { f32 (*value)[4]; } m;

    anim = obj->anim;
    if (anim->unk_3C != 0) {
        value = fn_1_9E14C(anim->unk_18, (u32)anim->unk_3C, t);
    } else {
        value = obj->unk_2C;
    }
    width = __fabs(value * (2.0f * scale->x));
    if (anim->unk_28 != 0) {
        value = fn_1_9E14C(anim->unk_4, (u32)anim->unk_28, t);
    } else {
        value = obj->unk_18;
    }
    radius = __fabs(value * scale->y);

    zero = 0.0f;
    half = 0.5f;
    b = buf;
    for (i = 0, m.value = LC_MTX; i < 2; i++) {
        lbl_8006DAEC();
        offset = width * ((i == 0) ? 0.5f : -0.5f);
        tx = m.value[0][0];
        tx = tx * offset + m.value[0][3];
        ty = m.value[1][0];
        ty = ty * offset + m.value[1][3];
        tz = m.value[2][0];
        tz = tz * offset + m.value[2][3];
        m.value[0][3] = tx;
        m.value[1][3] = ty;
        m.value[2][3] = tz;
        angle = (i == 0) ? 0 : 0x8000;
        q = b;
        for (j = 0; j <= 8; j++) {
            y = half * lbl_8006D188(angle + 0x4000);
            x = half * lbl_8006D188(angle);
            q->x = x;
            q->y = y;
            q->z = zero;
            q->x *= radius;
            q->y *= radius;
            lbl_8006E1B0((void *)q, (void *)q);
            angle += 0x1000;
            q++;
            b++;
        }
        lbl_8006DB30();
    }

    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    p = buf;
    fn_8003462C(0xB0, 0, 19);
    output_i = 0;
    if (output_i < 18) {
    for (output_i = 0; output_i < 18; output_i += 6) {
        fn_1_2221C_pos3(p[0].x, p[0].y, p[0].z);
#define WRITE_NEXT(k) { f32 vx; f32 vz; f32 vy; vz = p[k].z; vy = p[k].y; vx = p[k].x; GX_FIFO_F32 = vx; GX_FIFO_F32 = vy; GX_FIFO_F32 = vz; }
        WRITE_NEXT(1);
        WRITE_NEXT(2);
        WRITE_NEXT(3);
        WRITE_NEXT(4);
        WRITE_NEXT(5);
#undef WRITE_NEXT
        p += 6;
    }
    }
    GX_FIFO_F32 = buf[0].x;
    GX_FIFO_F32 = buf[0].y;
    GX_FIFO_F32 = buf[0].z;
    lbl_8006DB30();
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef LC_MTX
#undef GX_FIFO_F32
#pragma opt_lifetimes reset
#pragma opt_propagation reset
/* fzgx:end fn_1_2221C */

/* fzgx:begin fn_1_224F8 */
#define GAME_MAIN_REL_STCOLI_TYPES_H

#define GAME_VEC3_H

s32 fn_1_224F8(Vec3 *start, Vec3 *end, u32 *mask) {
    s32 result;
    s32 i;
    s32 first;
    StcoliGate *gate;
    Vec3 p0;
    Vec3 p1;
    Vec3 delta;
    Vec3 hit;
    f32 sx;
    f32 sy;
    f32 t;
    s32 below1;

    result = -1;
    if (fn_1_7B054() == -1) {
        return -1;
    }
    if (lbl_1_bss_3BE0 == NULL) {
        return -1;
    }
    first = __cntlzw(*mask);
    lbl_8006DAEC();
    for (i = first, gate = &((StcoliGate *)lbl_1_bss_3BE0->unk_B0)[first]; i < (s32)lbl_1_bss_3BE0->unk_AC; i++, gate++) {
        if (!__rlwnm(*mask, (i + 1) & 0x1F, 31, 31)) {
            continue;
        }
        lbl_8006D7DC(gate);
        if (gate->rot_z) {
            mathutil_mtxA_rotate_z(gate->rot_z);
        }
        if (gate->rot_y) {
            mathutil_mtxA_rotate_y(gate->rot_y);
        }
        if (gate->rot_x) {
            mathutil_mtxA_rotate_x(gate->rot_x);
        }
        lbl_8006DF44();
        lbl_8006E1B0(start, &p0);
        lbl_8006E1B0(end, &p1);
        below1 = p1.z < 0.0f;
        if (!(p0.z < 0.0f) || below1) {
            continue;
        }
        sx = 0.5f * (10.0f * gate->width);
        sy = 0.5f * (10.0f * gate->height);
        p0.x /= sx;
        p0.y /= sy;
        p1.x /= sx;
        p1.y /= sy;
        psvec_sub(&p0, &p1, &delta);
        t = -(p0.z / delta.z);
        psvec_scale_add(&p0, &delta, t, &hit);
        if (gate->round) {
            f32 xx = hit.x * hit.x;
            f32 yy = hit.y * hit.y;
            if (xx + yy <= 1.0f) {
                result = i;
                break;
            }
        } else if ((-1.0f) <= hit.x && hit.x <= 1.0f && (-1.0f) <= hit.y && hit.y <= 1.0f) {
            result = i;
            break;
        }
    }
    lbl_8006DB30();
    if (result >= 0) {
        *mask &= 0xFFFFFFFFu >> (result + 1);
    }
    return result;
}
#undef GAME_MAIN_REL_STCOLI_TYPES_H
#undef GAME_VEC3_H

/* Unknown retail object: three colour tables and an offset vector after the last literal of coli.c
 * (.rodata 7C4..83F). No retail code reads them; the debug drawing that used them is not linked. */
typedef struct ColiColor {
    u8 r, g, b, a;
} ColiColor;

static const ColiColor coli_debug_colors_a[11] = {
    {0xC0, 0xC0, 0xC0, 0xFF}, {0x40, 0x40, 0xFF, 0xFF}, {0x40, 0xFF, 0x40, 0xFF}, {0xFF, 0x40, 0x40, 0xFF},
    {0x40, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0x40, 0xFF}, {0xFF, 0x40, 0xFF, 0xFF}, {0x40, 0x40, 0x40, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xC0, 0xC0, 0xFF}, {0xC0, 0xFF, 0xC0, 0xFF},
};
static const ColiColor coli_debug_colors_b[11] = {
    {0xFF, 0xFF, 0xFF, 0xFF}, {0x60, 0x60, 0xFF, 0xFF}, {0x60, 0xFF, 0x60, 0xFF}, {0xFF, 0x60, 0x60, 0xFF},
    {0x60, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0x60, 0xFF}, {0xFF, 0x60, 0xFF, 0xFF}, {0x60, 0x60, 0x60, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xC0, 0xC0, 0xFF}, {0xC0, 0xFF, 0xC0, 0xFF},
};
static const Vec3 coli_debug_offset = {0.0f, 0.0f, -10.0f};
static const ColiColor coli_debug_colors_c[6] = {
    {0x80, 0x80, 0x80, 0xFF}, {0x80, 0x80, 0x80, 0xFF}, {0x40, 0x80, 0x40, 0xFF},
    {0x60, 0x80, 0x60, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0x00, 0xFF},
};

/* Unknown retail object: .data 56D0, the words -1 and 0, no retail reader */
s32 coli_unknown_56D0[2] = {-1, 0};
/* fzgx:end fn_1_224F8 */
