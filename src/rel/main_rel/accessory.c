#include "types.h"
#define lbl_1_data_3FFBC globals_h_3FFBC
#define lbl_1_data_40530 globals_h_40530
#include "rel/main_rel/globals.h"
#undef lbl_1_data_3FFBC
#undef lbl_1_data_40530
#include "rel/main_rel/cloth.h"
#include "rel/main_rel/game.h"
#include "rel/main_rel/archive.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/vec3.h"
#include "psvec.h"
#include "psvec_set_xyz.h"
#include "mathutil.h"
#include "mathutil_mtxA_translate_col.h"
#include "mathutil_vec_cross_prod.h"
#include "mathutil_vec_sq_distance.h"
#include "font.h"

/* fn_1_107900 */
typedef struct {
    u8 pad_0[0xc];
    u32 unk_c;
    u8 pad_10[0x58];
} Sig_fn_1_108870_fn_1_108870_AccessoryEntry;

/* fn_1_107900 */
typedef u32 (*fn_1_107930_Fn0)(u32);

/* fn_1_107900 */
struct fn_1_107930_lbl_1_data_3F510 {
    u8 pad_0[0x650];
    char unk_650[0x10];
    char unk_660[0x10];
    char unk_670[0x12c];
    const char *unk_79C[98];
    u32 unk_924[221];
    fn_1_107930_Fn0 unk_C98[196];
    u32 unk_FA8;
    const char *unk_FAC[19];
    u32 unk_FF8;
    u8 unk_FFC[8];
    char unk_1004[8];
};

/* fn_1_107900 */
typedef struct { void *unk_0; const char *unk_4; } fn_1_107930_Entry;

/* fn_1_107900 */
typedef struct { u32 unk_0; u32 unk_4; fn_1_107930_Entry *unk_8; } fn_1_107930_List;

/* fn_1_107900 */
typedef struct {
    u8 pad_0[0x88];
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x54];
    fn_1_107930_List *unk_E4[3];
} fn_1_107930_Object;

/* fn_1_107900 */
struct fn_1_107930_lbl_1_rodata_7AB8 { u32 unk_0, unk_4, unk_8; };

/* fn_1_107C74 */
typedef struct {
    u8 pad_0[0x48];
    f32 unk_48;
    f32 unk_4C;
} BgRange;

/* fn_1_107C74 */
typedef struct {
    u8 pad_0[0x8];
    u8 *unk_8;
} BgModel;

/* fn_1_107C74 */
typedef struct {
    u8 pad_0[0x8C];
    s32 unk_8C;
    s32 unk_90;
    u8 pad_94[0xBC];
    BgModel *unk_150;
} BgOwner;

/* fn_1_107C74 */
struct BgEntry {
    u8 pad_0[0x8];
    u32 unk_8;
    BgOwner *unk_C;
    u8 pad_10[0x24];
    Vec3 unk_34;
    u8 pad_40[0x28];
};

/* fn_1_107C74 */
typedef struct BgEntry BgEntry;

/* fn_1_107C74 */
typedef void (*BgEntryFn)(BgEntry *);

/* fn_1_107C74 */
typedef struct {
    u8 pad_0[0xC];
    Vec3 unk_C;
    f64 unk_18;
    f32 unk_20;
} BgPool;

/* fn_1_107C74 */
typedef struct {
    u8 pad_0[0xAAC];
    u32 unk_AAC[0x62];
    u8 unk_C34[0x1EC];
    BgEntryFn unk_E20[1];
} BgData;

/* fn_1_107E90 */
typedef struct {
    u8 unk_00[0x8];
    u32 unk_08;
    u8 *unk_0C;
    u8 unk_10[0x8];
    u32 unk_18;
    u8 unk_1C[0x8];
    u8 *unk_24;
} Fn107E90Context;

/* fn_1_107F74 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;  // 7 loads, 0 stores
    u32 unk_C;  // 4 loads, 0 stores
    u32 unk_10;  // 3 loads, 0 stores
    u8 pad_14[0x1C5C];
} Obj_1_bss_86ED0_L;

/* fn_1_107F74 */
typedef struct {
    u8 pad_0[0xa0];
    s16 rx;
    s16 ry;
    s16 rz;
    u8 pad_a6[2];
    u8 pos[0x10];
    f32 scale;
    u8 pad_bc[0x150 - 0xbc];
    u8 *unk_150;
} BgObj;

/* fn_1_107F74 */
typedef struct {
    u8 b[0x34];
} BgMaterial;

/* fn_1_107F74 */
typedef struct {
    BgMaterial mats[2];
    u8 s68[0x79c - 0x68];
    u8 *names[0xc4];
    u32 ids[0x20];
    u8 pad[0x100c - 0xb2c];
    u8 str1[0xc];
    u8 str2[0xc];
} BgData_107F74;

/* fn_1_108128 */
typedef struct {
    u8 pad_00[0x2];
    u8 count;
    u8 pad_03;
    u16 indices[6];
    Vec3 pos;
    u8 pad_1C[0x28];
} Fn108128Entry;

/* fn_1_108128 */
typedef struct {
    u8 pad_00[0x10];
    void *model;
    u8 pad_14[0x4];
    u32 count;
    u8 pad_1C[0x8];
    Fn108128Entry *entries;
} Fn108128Context;

/* fn_1_10846C */
struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

/* fn_1_10846C */
typedef struct {
    u32 w[3];
} Word3_10846C;

/* fn_1_10846C */
typedef struct {
    Vec3 pos;        /* 0x00 */
    Word3_10846C attr;    /* 0x0C */
    u8 pad_18[0x1D];
    u8 flags;             /* 0x35 */
    u8 pad_36[0xA];
} Vert10846C;

/* fn_1_10846C */
typedef struct {
    u8 flags;             /* 0x00 */
    u8 unk_1;             /* 0x01 */
    u8 count;             /* 0x02 */
    u8 pad_3;
    u16 idx[4];           /* 0x04 */
    u8 pad_C[4];
    Vec3 p10;        /* 0x10 */
    Vec3 p1C;        /* 0x1C */
    Vec3 p28;        /* 0x28 */
    Word3_10846C c34;     /* 0x34 */
    u8 pad_40[4];
} Group10846C;

/* fn_1_10846C */
typedef struct {
    u8 pad_0[0x10];
    void *model;          /* 0x10 */
    u8 pad_14[4];
    u32 groupCount;       /* 0x18 */
    u32 unk_1C;           /* 0x1C */
    u8 pad_20[4];
    Group10846C *groups;  /* 0x24 */
    void *unk_28;         /* 0x28 */
    u8 pad_2C[4];
    void *srcModel;       /* 0x30 */
    u8 pad_34[0x30];
    Vec3 *positions; /* 0x64 */
} Obj10846C;

/* fn_1_108920 */
struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

/* fn_1_108920 */
struct fn_1_108920_Copy12 { u32 a[3]; };

/* fn_1_108920 */
struct fn_1_108920_lbl_801A6410 {
    u32 unk_0;
};

/* fn_1_108A90 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0xf];
    Vec3 vec;
    u8 pad_1c[0x28];
} fn_1_108A90_Entry;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x150];
    u32 *unk_150;
} fn_1_108A90_Mgr;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0xc];
    fn_1_108A90_Mgr *unk_c;
    u8 pad_10[8];
    u32 count;
    u8 pad_1c[8];
    fn_1_108A90_Entry *entries;
} fn_1_108A90_Self;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x14];
    f32 radius;
} Fn1108BD0_Shape;

/* fn_1_108A90 */
typedef struct {
    Fn1108BD0_Shape *shape;
    const char *name;
} Fn1108BD0_Entry;

/* fn_1_108A90 */
typedef struct {
    u32 count;
    u32 unk_4;
    Fn1108BD0_Entry *entries;
} Fn1108BD0_Table;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x88];
    u8 mtx[0x18C - 0x88];
} Fn1108BD0_Joint;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x8];
    Fn1108BD0_Joint *joints;
} Fn1108BD0_Skeleton;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x8C];
    s32 table_index;
    u8 pad_90[0xE4 - 0x90];
    Fn1108BD0_Table *tables[(0x150 - 0xE4) / 4];
    Fn1108BD0_Skeleton *skeleton;
} Fn1108BD0_Model;

/* fn_1_108A90 */
typedef struct {
    u8 flags;
    u8 pad_1[0xF];
    Vec3 pos;
    u8 pad_1C[0x44 - 0x1C];
} Fn1108BD0_Part;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x8];
    s32 name_index;
    Fn1108BD0_Model *model;
    u8 pad_10[0x8];
    u32 part_count;
    u8 pad_1C[0x8];
    Fn1108BD0_Part *parts;
} Fn1108BD0_Object;

/* fn_1_108A90 */
typedef struct {
    f32 w;
    f32 x;
    f32 y;
    f32 z;
} Quat;

/* fn_1_108A90 */
typedef struct {
    f32 pad_0[12];
} Mtx;

/* fn_1_108A90 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0xF];
    Vec3 unk_10;
    u8 pad_1C[0x28];
} fn_1_108EEC_Node;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x150];
    BgModel *unk_150;
} fn_1_108EEC_L0;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0xC];
    fn_1_108EEC_L0 *unk_c;
    u8 pad_10[8];
    u32 unk_18;
    u8 pad_1C[8];
    fn_1_108EEC_Node *unk_24;
} fn_1_108EEC_Arg;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_109114_AccessoryData;

/* fn_1_108A90 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    fn_1_109114_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} fn_1_109114_AccessoryObject;

/* fn_1_1091D4 */
struct fn_1_10D2F0_rodata {
    u8 pad_0[0x64];
    f32 unk_64;   /* -1.0f */
    f32 unk_68;   /* 0.0f */
    u8 pad_6C[0xFC];
    f64 unk_168;  /* 0.015 */
    f32 unk_170;  /* -0.5f */
    u8 pad_174[0x4];
    f64 unk_178;  /* 0.045 */
};

/* fn_1_1091D4 */
typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

/* fn_1_1091D4 */
typedef struct {
    u8 flags;
    u8 pad_1[0x13];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Group1091D4;

/* fn_1_1091D4 */
typedef struct {
    Group1091D4 *a;
    Group1091D4 *b;
    f32 distance;
} Link1091D4;

/* fn_1_1091D4 */
struct fn_1_1091D4_lbl_1_rodata_7AB8 {
    u8 pad_0[0x64];
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
};

/* fn_1_10976C */
typedef Vec3 RopeVec;

/* fn_1_10976C */
typedef struct RopeNode {
    u8 flags, pad1, count, pad3;
    u16 links[6];
    RopeVec pos, prev, local, vel;
    f32 weight;
} RopeNode;

/* fn_1_10976C */
typedef struct { RopeNode *a, *b; f32 length; } RopeLink;

/* fn_1_10976C */
typedef struct { u8 pad[8]; u8 *base; } RopeModel;

/* fn_1_10976C */
typedef struct { u8 pad[0x150]; RopeModel *model; } RopeOwner;

/* fn_1_10976C */
typedef struct {
    u8 flags; u8 pad[7]; u32 index; RopeOwner *owner; void *obj;
    u32 pad14, count, linkCount, pad20; RopeNode *nodes; RopeLink *links;
} RopeWork;

/* fn_1_10A43C */
typedef struct AccessoryEntry {
    u8 unk_0;
    u8 pad_1[0x13];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} AccessoryEntry;

/* fn_1_10A43C */
typedef struct AccessoryObject {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} AccessoryObject;

/* fn_1_10A6A0 */
typedef union fn_1_10A6A0_Vec {
    u32 w[3];
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
} fn_1_10A6A0_Vec;

/* fn_1_10A6A0 */
typedef struct fn_1_10A6A0_Part {
    s8 unk_0;
    u8 pad_1;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4[6];
    fn_1_10A6A0_Vec unk_10;
    fn_1_10A6A0_Vec unk_1C;
    fn_1_10A6A0_Vec unk_28;
    fn_1_10A6A0_Vec unk_34;
    u32 unk_40;
} fn_1_10A6A0_Part;

/* fn_1_10A6A0 */
typedef struct fn_1_10A6A0_Object {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_108EEC_L0 *unk_C;
    void *unk_10;
    u32 pad_14;
    u32 unk_18;
    u8 pad_1C[8];
    fn_1_10A6A0_Part *unk_24;
} fn_1_10A6A0_Object;

/* fn_1_10A8D0 */
typedef struct Node_10A8D0 {
    u8 flag;
    u8 pad[0x13];
    f32 keyA;
    f32 keyB;
    u8 pad2[0x24];
    f32 value;
} Node_10A8D0;

/* fn_1_10A8D0 */
typedef struct Edge_10A8D0 {
    Node_10A8D0 *a;
    Node_10A8D0 *b;
    f32 weight;
} Edge_10A8D0;

/* fn_1_10A8D0 */
typedef struct Graph_10A8D0 {
    u8 pad[0x18];
    u32 nodeCount;
    u32 edgeCount;
    u32 pad2;
    Node_10A8D0 *nodes;
    Edge_10A8D0 *edges;
} Graph_10A8D0;

/* fn_1_10A8D0 */
typedef struct {
    u8 pad_0[0x48];
    f32 quarter;    /* 0x048: 0.25f */
    u8 pad_4C[0x18];
    f32 neg_one;    /* 0x064: -1.0f */
    f32 zero;       /* 0x068: 0.0f */
    u8 pad_6C[0x6C];
    f64 d_neg_one;  /* 0x0D8: -1.0 */
    f32 three_qtr;  /* 0x0E0: 0.75f */
} AccessoryPool10A8D0;

/* fn_1_10AD18 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_10AD18 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_10AD18 */
typedef struct { f32 x,y,z; } Sig_fn_1_1286F4_Vec3f;

/* fn_1_10AD18 */
typedef struct Node {
 u8 flags, pad1, count, pad3;
 u16 links[6];
 Vec3 pos,prev,local,vel;
 f32 weight;
} Node;

/* fn_1_10AD18 */
typedef struct { Node *a,*b; f32 length; } Link;

/* fn_1_10AD18 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_10AD18 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work;

/* fn_1_10B344 */
typedef struct {
    u8 active;
    u8 _pad01[0x13];
    f32 field14;
    f32 field18;
    u8 _pad1c[0x24];
    f32 field40;
} Entry;

/* fn_1_10B344 */
typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Entry *entries;
} Doc;

/* fn_1_10B344 */
typedef union fn_1_10B5A8_Vec {
    u32 w[3];
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
} fn_1_10B5A8_Vec;

/* fn_1_10B344 */
typedef struct fn_1_10B5A8_Part {
    s8 unk_0;
    u8 pad_1;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4[6];
    fn_1_10B5A8_Vec unk_10;
    fn_1_10B5A8_Vec unk_1C;
    fn_1_10B5A8_Vec unk_28;
    fn_1_10B5A8_Vec unk_34;
    u32 unk_40;
} fn_1_10B5A8_Part;

/* fn_1_10B344 */
typedef struct fn_1_10B5A8_Object {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_108EEC_L0 *unk_C;
    void *unk_10;
    u32 pad_14;
    u32 unk_18;
    u8 pad_1C[8];
    fn_1_10B5A8_Part *unk_24;
} fn_1_10B5A8_Object;

/* fn_1_10B344 */
struct PoolObj {
    u8 pad_0[0xE8];
    Vec3 v[3];
    f32 lo;
    f32 hi;
};

/* fn_1_10B344 */
struct Rec {
    s16 f_00;
    u8 count;
    u8 pad_1[1];
    u16 idx[18];
    Vec3 v;
    u32 pad_2[4];
};

/* fn_1_10B344 */
struct Joint {
    u8 pad_0[0x88];
    f32 matrix[3][4];
    u8 pad_1[0x18C - 0xB8];
};

/* fn_1_10B344 */
struct MgrInner {
    u8 pad_0[8];
    struct Joint *joints;
};

/* fn_1_10B344 */
struct Mgr {
    u8 pad_0[0x150];
    struct MgrInner *inner;
};

/* fn_1_10B344 */
struct Accessory {
    u8 pad_0[0xC];
    struct Mgr *mgr;
    u8 *arg;
    u32 pad_1;
    u32 count;
    u32 pad_2[2];
    struct Rec *recs;
};

/* fn_1_10BA00 */
typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

/* fn_1_10BA00 */
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

/* fn_1_10BA00 */
struct FzgxCopy_88 { u32 words[22]; };

/* fn_1_10BA00 */
struct fn_1_129D9C_rodata {
    f32 unk_0;
    u8 pad_4[0xC];
    f32 unk_10;
    u8 pad_14[0x8C];
    u32 unk_A0;
    u32 unk_A4;
    s32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x4];
    f64 unk_B8;
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
};

/* fn_1_10BA00 */
struct fn_1_129D9C_system {
    u8 pad_0[0x2C];
    f32 unk_2C;
};

/* fn_1_10BA00 */
typedef struct Edge10C4E4 {
    Node_10A8D0 *a;
    Node_10A8D0 *b;
    u32 pad;
} Edge10C4E4;

/* fn_1_10BA00 */
typedef struct Graph10C4E4 {
    u8 pad[0x18];
    u32 nodeCount;
    u32 edgeCount;
    u32 pad2;
    Node_10A8D0 *nodes;
    Edge10C4E4 *edges;
} Graph10C4E4;

/* fn_1_10BA00 */
typedef struct fn_1_10D2F0_Entry {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0xE];
    Vec3 unk_10;
    Vec3 unk_1C;
    Vec3 unk_28;
    u8 pad_34[0xC];
    f32 unk_40;
} fn_1_10D2F0_Entry;

/* fn_1_10BA00 */
typedef struct fn_1_10D2F0_Link {
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *b;
    f32 len;
} fn_1_10D2F0_Link;

/* fn_1_10BA00 */
typedef struct fn_1_10D2F0_Obj {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[4];
    fn_1_10D2F0_Entry *unk_24;
    fn_1_10D2F0_Link *unk_28;
} fn_1_10D2F0_Obj;

/* fn_1_10BA00 */
typedef struct {
    f32 zero;           /* 0x0 */
    u8 pad_4[0xC];
    f32 one;            /* 0x10 */
    u8 pad_14[0x64];
    u32 tbl3[3];        /* 0x78 */
    u32 tbl4[4];        /* 0x84 */
    u8 str[4];          /* 0x94 */
} Pool_12999C;

/* fn_1_10BA00 */
typedef struct {
    u8 pad_0[0x9];
    u8 count;           /* 0x9 */
    u8 pad_A[0x14A6];
} Info_12999C;

/* fn_1_10BA00 */
typedef struct {
    u32 flags;          /* 0x0 */
    u8 pad_4[0x148];
    u8 body[0x329];     /* 0x14c */
    s8 slot;            /* 0x475 */
    u8 pad_476[0x26];
    u8 *info;           /* 0x49c */
} Entry_12999C;

/* fn_1_10BA00 */
typedef struct {
    u32 words[6];
} Tmp_12999C;

/* fn_1_10BA00 */
struct fn_1_129D9C_vec {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

/* fn_1_10BA00 */
struct fn_1_129D9C_obj {
    u8 pad_0[0x10];
    u8 unk_10;
};

/* fn_1_10BA00 */
typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Sig_fn_8006F78C_Fn8006F78CData;

/* fn_1_10BA00 */
typedef struct {
    u8 flags;
    u8 unk_1;
    u8 count;
    u8 pad_3;
    u16 idx[4];
    u8 pad_C[4];
    Vec3 p10;
    Vec3 p1C;
    Vec3 p28;
    u32 c34[3];
    f32 weight;
} Group10BA00;

/* fn_1_10BA00 */
typedef struct {
    Group10BA00 *a;
    Group10BA00 *b;
    f32 dist;
} Edge10BA00;

/* fn_1_10BA00 */
typedef struct {
    u8 pad_0[0x10];
    void *model;
    u8 pad_14[4];
    u32 groupCount;
    u32 edgeCount;
    u8 pad_20[4];
    Group10BA00 *groups;
    Edge10BA00 *edges;
} Obj10BA00;

/* fn_1_10BE3C */
struct Sig_fn_80077B14_fn_80077B14_Arg0_10BE3C {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_10BE3C */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_10BE3C *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_10BE3C;

/* fn_1_10C7B4 */
typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_10C7B4_AccessoryData;

/* fn_1_10C7B4 */
typedef struct {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_10C7B4_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} fn_1_10C7B4_AccessoryObject;

/* fn_1_10C7B4 */
typedef union {
    u32 raw;
    f32 value;
} FloatVal;

/* fn_1_10C7B4 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Fn1_10C7B4_Triple;

/* fn_1_10C7B4 */
typedef struct {
    u8 pad_0[0x10];
    FloatVal unk_10;
    FloatVal unk_14;
    FloatVal unk_18;
    FloatVal unk_1C;
    FloatVal unk_20;
    FloatVal unk_24;
    u8 pad_28[0xC];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
} AccessoryItem;

/* fn_1_10C7B4 */
typedef struct Fn10C9B0Entry {
    u8 flags;
    u8 pad_01[0x17];
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Fn10C9B0Entry;

/* fn_1_10C7B4 */
typedef struct Fn10C9B0List {
    u8 pad_00[0x18];
    u32 count;
    u8 pad_1C[0x8];
    Fn10C9B0Entry *entries;
} Fn10C9B0List;

/* fn_1_10CC38 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_10CC38 { u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20; };

/* fn_1_10CC38 */
struct fn_1_10CC38_lbl_1_rodata_7AB8 {
 u8 pad_0[0x58]; f64 unk_58; f32 unk_60; u8 pad_64[0x38]; f32 unk_9C;
 u8 pad_A0[0xA8]; Vec3 unk_148; f32 unk_154, unk_158, unk_15C, unk_160;
};

/* fn_1_10CC38 */
typedef struct Particle {
 u8 flags; u8 pad1; u8 count; u8 pad3; u16 links[6];
 Vec3 pos, prev, local, vel; f32 mass;
} Particle;

/* fn_1_10CC38 */
typedef struct ModelData { u8 pad[8]; u8 *data; } ModelData;

/* fn_1_10CC38 */
typedef struct Owner_10CC38 { u8 pad[0x150]; ModelData *model; } Owner_10CC38;

/* fn_1_10CC38 */
typedef struct Rope {
 u8 flags; u8 pad[7]; u32 index; Owner_10CC38 *owner; struct Sig_fn_80077B14_fn_80077B14_Arg0_10CC38 *handle;
 u32 unk14, count, unk1c, unk20; Particle *particles;
} Rope;

/* fn_1_10D2F0 */
typedef struct {
    u32 a;
    u32 b;
    u32 c;
} W3;

/* fn_1_10D2F0 */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0xE];
    Vec3 v;
    W3 w1;
    W3 w2;
    u8 pad_34[0xC];
    f32 unk_40;
} Elem;

/* fn_1_10D2F0 */
typedef struct {
    u32 a;
    u32 b;
    f32 d;
} Link_10D2F0;

/* fn_1_10D2F0 */
typedef struct {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u32 pad_20;
    Elem *unk_24;
    Link_10D2F0 *unk_28;
} Ctx;

/* fn_1_10D2F0 */
typedef struct {
    u8 pad_0[0x64];
    f32 m1;
    f32 zero;
    u8 pad_6C[0xFC];
    f64 d015;
    f32 m05;
    u8 pad_174[4];
    f64 d045;
} Pool;

/* fn_1_10D7D4 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_10D7D4 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_10D7D4 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_10D7D4 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_10D7D4;

/* fn_1_10DDE4 */
typedef struct RopeNode_10DDE4 {
    u8 unk_0;
    u8 pad_1[0xF];
    Vec3 unk_10;
    u8 pad_1C[0x24];
    f32 unk_40;
} RopeNode_10DDE4;

/* fn_1_10DDE4 */
typedef struct Link_10DDE4 {
    RopeNode_10DDE4 *unk_0;
    RopeNode_10DDE4 *unk_4;
    f32 unk_8;
} Link_10DDE4;

/* fn_1_10DDE4 */
typedef struct RopeOwner_10DDE4 {
    u8 pad_0[0x8C];
    s32 unk_8C;
} RopeOwner_10DDE4;

/* fn_1_10DDE4 */
typedef struct Rope_10DDE4 {
    u8 pad_0[0xC];
    RopeOwner_10DDE4 *unk_C;
    u8 pad_10[0x8];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x4];
    RopeNode_10DDE4 *unk_24;
    Link_10DDE4 *unk_28;
} Rope_10DDE4;

/* fn_1_10E3B4 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_10E3B4 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_10E3B4 */
typedef struct Node_10E3B4 {
 u8 flags, pad1, count, pad3;
 u16 links[6];
 Vec3 pos, prev, local, vel;
 f32 weight;
} Node_10E3B4;

/* fn_1_10E3B4 */
typedef struct { Node_10E3B4 *a, *b; f32 length; } Link_10E3B4;

/* fn_1_10E3B4 */
typedef struct { u8 pad[0x8c]; s32 kind; u8 pad90[0x148 - 0x90]; u8 unk148[8]; RopeModel *model; } Owner_10E3B4;

/* fn_1_10E3B4 */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_10E3B4 *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_10E3B4 *obj;
 u32 pad14, count, linkCount, pad20; Node_10E3B4 *nodes; Link_10E3B4 *links; } Work_10E3B4;

/* fn_1_110478 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_110478 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_110478 */
typedef struct { u8 pad[0x88]; s32 kind; u8 pad8c[0x148 - 0x8c]; u8 unk148[8]; RopeModel *model; } Owner_110478;

/* fn_1_110478 */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_110478 *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_110478 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_110478;

/* fn_1_111980 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_111980 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_111980 */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_110478 *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_111980 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_111980;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 29 loads, 17 stores
    u32 unk_4;  // 6 loads, 12 stores
    u32 unk_8;  // 6 loads, 10 stores
    u32 unk_C;  // 3 loads, 11 stores
    u32 unk_10;  // 10 loads, 9 stores
    u32 unk_14;  // 0 loads, 3 stores
    u32 unk_18;  // 0 loads, 3 stores
    u32 unk_1C;  // 0 loads, 3 stores
    u32 unk_20;  // 0 loads, 4 stores
    u32 unk_24;  // 0 loads, 4 stores
    u32 unk_28;  // 0 loads, 5 stores
    u32 unk_2C;  // 2 loads, 5 stores
    u32 unk_30;  // 2 loads, 6 stores
    u32 unk_34;  // 2 loads, 6 stores
    u8 unk_38;  // 2 loads, 6 stores
    u8 unk_39;  // 0 loads, 1 stores
    u8 unk_3A;  // 0 loads, 1 stores
    u8 unk_3B;  // 0 loads, 1 stores
    u32 unk_3C;  // 0 loads, 4 stores
    u32 unk_40;  // 0 loads, 2 stores
    u32 unk_44;  // 0 loads, 2 stores
    u32 unk_48;  // 0 loads, 2 stores
    u32 unk_4C;  // 0 loads, 3 stores
    u32 unk_50;  // 0 loads, 3 stores
    u32 unk_54;  // 0 loads, 3 stores
    u16 unk_58;  // 0 loads, 3 stores
    u16 unk_5A;  // 0 loads, 1 stores
    u8 unk_5C;  // 4 loads, 3 stores
    u8 unk_5D;  // 13 loads, 6 stores
    u8 unk_5E;  // 4 loads, 2 stores
    u8 pad_5F[0x1];
    u32 unk_60;  // 1 loads, 1 stores
    u8 pad_64[0x10];
    u32 unk_74;  // 2 loads, 5 stores
    u8 pad_78[0xC];
    u32 unk_84;  // 22 loads, 5 stores
    u32 unk_88;  // 0 loads, 4 stores
    u8 pad_8C[0x4];
    u32 unk_90;  // 10 loads, 10 stores
    u8 pad_94[0x18];
    u32 unk_AC;  // 0 loads, 1 stores
    u32 unk_B0;  // 0 loads, 1 stores
    u32 unk_B4;  // 0 loads, 1 stores
    u32 unk_B8;  // 0 loads, 1 stores
    u32 unk_BC;  // 0 loads, 1 stores
    u32 unk_C0;  // 0 loads, 1 stores
    u32 unk_C4;  // 1 loads, 2 stores
    u32 unk_C8;  // 0 loads, 1 stores
    u32 unk_CC;  // 0 loads, 1 stores
    u32 unk_D0;  // 0 loads, 1 stores
    u32 unk_D4;  // 0 loads, 1 stores
    u32 unk_D8;  // 0 loads, 1 stores
    u32 unk_DC;  // 0 loads, 1 stores
    u32 unk_E0;  // 0 loads, 1 stores
    u32 unk_E4;  // 0 loads, 1 stores
    u32 unk_E8;  // 0 loads, 1 stores
    u32 unk_EC;  // 0 loads, 1 stores
    u32 unk_F0;  // 0 loads, 1 stores
    u32 unk_F4;  // 0 loads, 1 stores
    u32 unk_F8;  // 0 loads, 1 stores
    u8 pad_FC[0x8];
    u32 unk_104;  // 0 loads, 1 stores
    u8 pad_108[0xC];
    u32 unk_114;  // 0 loads, 1 stores
    u32 unk_118;  // 0 loads, 1 stores
    u32 unk_11C;  // 0 loads, 1 stores
    u32 unk_120;  // 0 loads, 1 stores
    u32 unk_124;  // 0 loads, 1 stores
    u8 pad_128[0x24];
    u32 unk_14C;  // 0 loads, 1 stores
    u32 unk_150;  // 0 loads, 1 stores
    u32 unk_154;  // 0 loads, 1 stores
    u32 unk_158;  // 0 loads, 1 stores
    u32 unk_15C;  // 0 loads, 1 stores
    u32 unk_160;  // 0 loads, 1 stores
    u32 unk_164;  // 0 loads, 1 stores
    u32 unk_168;  // 0 loads, 1 stores
    u32 unk_16C;  // 3 loads, 2 stores
    u32 unk_170;  // 4 loads, 3 stores
    u32 unk_174;  // 0 loads, 1 stores
    u32 unk_178;  // 0 loads, 1 stores
    u32 unk_17C;  // 0 loads, 1 stores
    u32 unk_180;  // 0 loads, 1 stores
    u32 unk_184;  // 0 loads, 1 stores
    u32 unk_188;  // 0 loads, 1 stores
    u32 unk_18C;  // 0 loads, 1 stores
    u32 unk_190;  // 0 loads, 1 stores
    u32 unk_194;  // 0 loads, 1 stores
    u32 unk_198;  // 0 loads, 1 stores
    u8 pad_19C[0x50];
    u32 unk_1EC;  // 0 loads, 1 stores
    u32 unk_1F0;  // 0 loads, 1 stores
    u32 unk_1F4;  // 0 loads, 1 stores
    u32 unk_1F8;  // 0 loads, 1 stores
    u32 unk_1FC;  // 0 loads, 1 stores
    u32 unk_200;  // 0 loads, 1 stores
    u32 unk_204;  // 0 loads, 2 stores
    u32 unk_208;  // 0 loads, 1 stores
    u32 unk_20C;  // 0 loads, 1 stores
    u32 unk_210;  // 0 loads, 1 stores
    u32 unk_214;  // 0 loads, 1 stores
    u32 unk_218;  // 0 loads, 1 stores
    u32 unk_21C;  // 0 loads, 1 stores
    u32 unk_220;  // 0 loads, 1 stores
    u32 unk_224;  // 0 loads, 1 stores
    u32 unk_228;  // 0 loads, 1 stores
    u32 unk_22C;  // 0 loads, 1 stores
    u32 unk_230;  // 0 loads, 1 stores
    u32 unk_234;  // 0 loads, 1 stores
    u32 unk_238;  // 0 loads, 1 stores
    u8 pad_23C[0xC8];
    f32 unk_304;  // 1 loads, 1 stores
    u8 pad_308[0xFC];
    f32 unk_404;  // 0 loads, 1 stores
    u8 pad_408[0x1C];
    u32 unk_424;  // 0 loads, 1 stores
    u32 unk_428;  // 0 loads, 1 stores
    u32 unk_42C;  // 0 loads, 1 stores
    f32 unk_430;  // 0 loads, 1 stores
    u8 pad_434[0x28C];
    f32 unk_6C0;  // 1 loads, 1 stores
    u8 pad_6C4[0x8];
    u32 unk_6CC;  // 2 loads, 1 stores
    u32 unk_6D0;  // 0 loads, 1 stores
    u32 unk_6D4;  // 5 loads, 2 stores
    u32 unk_6D8;  // 0 loads, 1 stores
    u8 pad_6DC[0x4];
    u32 unk_6E0;  // 2 loads, 2 stores
    u8 pad_6E4[0x2BC];
    u32 unk_9A0;  // 1 loads, 2 stores
    u32 unk_9A4;  // 1 loads, 1 stores
    u32 unk_9A8;  // 1 loads, 1 stores
    u32 unk_9AC;  // 1 loads, 1 stores
    u32 unk_9B0;  // 1 loads, 1 stores
    u32 unk_9B4;  // 1 loads, 1 stores
    u32 unk_9B8;  // 1 loads, 1 stores
    u32 unk_9BC;  // 1 loads, 1 stores
    u8 pad_9C0[0x130];
    f32 unk_AF0;  // 0 loads, 1 stores
    u8 pad_AF4[0xE0];
    u32 unk_BD4;  // 2 loads, 1 stores
    u32 unk_BD8;  // 0 loads, 1 stores
    u8 pad_BDC[0x528];
    u32 unk_1104;  // 0 loads, 1 stores
    u32 unk_1108;  // 1 loads, 0 stores
    u8 pad_110C[0x4];
    u32 unk_1110;  // 0 loads, 1 stores
    u8 pad_1114[0x470];
    u32 unk_1584;  // 1 loads, 1 stores
    u32 unk_1588;  // 0 loads, 1 stores
    u8 pad_158C[0x320];
    u32 unk_18AC;  // 0 loads, 1 stores
    u8 pad_18B0[0x3A8];
    u32 unk_1C58;  // 7 loads, 2 stores
    u32 unk_1C5C;  // 7 loads, 2 stores
    u8 pad_1C60[0x5FC];
    u32 unk_225C;  // 0 loads, 1 stores
    u32 unk_2260;  // 0 loads, 1 stores
    u8 pad_2264[0x4C0];
    u32 unk_2724;  // 3 loads, 2 stores
} Obj_1_data_2A7E0_At3C_L;

/* fn_1_112F40 */
typedef struct {
    s16 unk_0;  // 10 loads, 0 stores
    u8 unk_2;  // 0 loads, 1 stores
    u8 pad_3[0x11];
    u32 unk_14;  // 0 loads, 1 stores
    u8 pad_18[0x4];
    f32 unk_1C;  // 6 loads, 0 stores
    u8 pad_20[0xC];
    u32 unk_2C;  // 0 loads, 3 stores
    u8 pad_30[0x4];
    u32 unk_34;  // 0 loads, 1 stores
    u32 unk_38;  // 1 loads, 0 stores
    Obj_1_data_2A7E0_At3C_L *unk_3C;  // 75 loads, 0 stores
    u8 pad_40[0x8];
    u32 unk_48;  // 2 loads, 1 stores
    u32 unk_4C;  // 2 loads, 1 stores
    u32 unk_50;  // 3 loads, 1 stores
    u32 unk_54;  // 0 loads, 2 stores
    u32 unk_58;  // 0 loads, 1 stores
    u32 unk_5C;  // 3 loads, 1 stores
    u32 unk_60;  // 5 loads, 1 stores
    u32 unk_64;  // 0 loads, 1 stores
    u32 unk_68;  // 2 loads, 1 stores
    u32 unk_6C;  // 2 loads, 1 stores
    u8 unk_70;  // 3 loads, 2 stores
    u8 pad_71[0x3];
    u32 unk_74;  // 2 loads, 2 stores
    u32 unk_78;  // 3 loads, 0 stores
    u32 unk_7C;  // 5 loads, 1 stores
    u32 unk_80;  // 3 loads, 1 stores
    u8 pad_84[0x4];
    u32 unk_88;  // 3 loads, 0 stores
    u32 unk_8C;  // 1 loads, 0 stores
    u8 pad_90[0xC];
    f32 unk_9C;  // 2 loads, 1 stores
    u16 unk_A0;  // 2 loads, 0 stores
    u8 pad_A2[0x56];
} Obj_1_data_2A7E0_L;

/* fn_1_112F40 */
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

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;  // 1 loads, 0 stores
} Obj_1_bss_8B3A0_AtA4_L;

/* fn_1_112F40 */
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

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 7 loads, 0 stores
    f32 unk_4;  // 1 loads, 0 stores
    u32 unk_8;  // 28 loads, 0 stores
    u32 unk_C;  // 40 loads, 0 stores
    u8 pad_10[0x4];
    u32 unk_14;  // 2 loads, 1 stores
    u32 unk_18;  // 9 loads, 0 stores
    u32 unk_1C;  // 11 loads, 1 stores
    u8 pad_20[0x4];
    u32 unk_24;  // 2 loads, 1 stores
    u8 pad_28[0x4];
    u32 unk_2C;  // 1 loads, 1 stores
    u8 pad_30[0xC];
    u32 unk_3C;  // 1 loads, 1 stores
    u8 pad_40[0x4];
    u32 unk_44;  // 1 loads, 1 stores
    u32 unk_48;  // 22 loads, 0 stores
    u32 unk_4C;  // 1 loads, 0 stores
    u32 unk_50;  // 1 loads, 0 stores
    u32 unk_54;  // 40 loads, 1 stores
    u8 pad_58[0x4];
    u32 unk_5C;  // 1 loads, 0 stores
    u32 unk_60;  // 1 loads, 1 stores
    u32 unk_64;  // 3 loads, 0 stores
    u32 unk_68;  // 6 loads, 1 stores
    u32 unk_6C;  // 1 loads, 0 stores
    u32 unk_70;  // 2 loads, 1 stores
    u32 unk_74;  // 1 loads, 0 stores
    u32 unk_78;  // 1 loads, 1 stores
    u8 pad_7C[0x1];
    u8 unk_7D;  // 11 loads, 0 stores
    u8 pad_7E[0x2];
    u32 unk_80;  // 5 loads, 1 stores
    u32 unk_84;  // 2 loads, 1 stores
    u32 unk_88;  // 1 loads, 0 stores
    u32 unk_8C;  // 1 loads, 1 stores
    u32 unk_90;  // 10 loads, 1 stores
    u32 unk_94;  // 1 loads, 0 stores
    u32 unk_98;  // 2 loads, 1 stores
    u32 unk_9C;  // 1 loads, 0 stores
    u32 unk_A0;  // 2 loads, 1 stores
    u32 unk_A4;  // 7 loads, 0 stores
    u32 unk_A8;  // 7 loads, 1 stores
    u32 unk_AC;  // 1 loads, 0 stores
    u32 unk_B0;  // 2 loads, 1 stores
    u32 unk_B4;  // 6 loads, 0 stores
    u32 unk_B8;  // 4 loads, 1 stores
    u32 unk_BC;  // 5 loads, 1 stores
    f32 unk_C0;  // 1 loads, 0 stores
    f32 unk_C4;  // 1 loads, 0 stores
    f32 unk_C8;  // 1 loads, 0 stores
    f32 unk_CC;  // 1 loads, 0 stores
    u32 unk_D0;  // 3 loads, 0 stores
    u32 unk_D4;  // 2 loads, 0 stores
} Obj_1_bss_3BE0_Target_L;

/* fn_1_112F40 */
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

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 4 loads, 1 stores
    u32 unk_4;  // 4 loads, 1 stores
    u32 unk_8;  // 2 loads, 1 stores
    u32 unk_C;  // 2 loads, 1 stores
    u32 unk_10;  // 2 loads, 1 stores
    u32 unk_14;  // 2 loads, 1 stores
    u32 unk_18;  // 3 loads, 1 stores
    u32 unk_1C;  // 3 loads, 1 stores
    u32 unk_20;  // 3 loads, 1 stores
    u32 unk_24;  // 3 loads, 1 stores
    u32 unk_28;  // 3 loads, 1 stores
    u32 unk_2C;  // 3 loads, 1 stores
    u8 pad_30[0x18];
    u32 unk_48;  // 3 loads, 3 stores
    u32 unk_4C;  // 3 loads, 3 stores
    u32 unk_50;  // 3 loads, 3 stores
    u32 unk_54;  // 3 loads, 3 stores
    u32 unk_58;  // 3 loads, 3 stores
    u32 unk_5C;  // 3 loads, 3 stores
    u8 pad_60[0x4];
    u16 unk_64;  // 2 loads, 2 stores
    u16 unk_66;  // 2 loads, 2 stores
    u16 unk_68;  // 2 loads, 2 stores
    u16 unk_6A;  // 3 loads, 3 stores
    u8 pad_6C[0x8C];
    u32 unk_F8;  // 4 loads, 2 stores
    u32 unk_FC;  // 2 loads, 0 stores
    u32 unk_100;  // 12 loads, 12 stores
    u32 unk_104;  // 5 loads, 2 stores
    u32 unk_108;  // 2 loads, 0 stores
    u32 unk_10C;  // 2 loads, 0 stores
    u32 unk_110;  // 12 loads, 9 stores
    u32 unk_114;  // 6 loads, 3 stores
    u8 pad_118[0x120];
    u32 unk_238;  // 2 loads, 0 stores
    u32 unk_23C;  // 2 loads, 0 stores
    u32 unk_240;  // 2 loads, 0 stores
    u32 unk_244;  // 2 loads, 0 stores
    u32 unk_248;  // 2 loads, 0 stores
    u32 unk_24C;  // 2 loads, 0 stores
    u32 unk_250;  // 2 loads, 0 stores
    u32 unk_254;  // 2 loads, 0 stores
    u16 unk_258;  // 2 loads, 0 stores
    u8 pad_25A[0x5106];
} Obj_1_bss_7F0C0_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    s16 unk_4;  // 2 loads, 0 stores
    s16 unk_6;  // 1 loads, 0 stores
    u8 pad_8[0x2C];
    f32 unk_34;  // 1 loads, 0 stores
    f32 unk_38;  // 1 loads, 0 stores
    u8 pad_3C[0x40];
    u32 unk_7C;  // 1 loads, 0 stores
    u32 unk_80;  // 1 loads, 0 stores
    u32 unk_84;  // 1 loads, 0 stores
    u32 unk_88;  // 1 loads, 0 stores
    u32 unk_8C;  // 1 loads, 0 stores
    u32 unk_90;  // 1 loads, 0 stores
    u8 pad_94[0xE8];
    f32 unk_17C;  // 1 loads, 0 stores
    u8 pad_180[0x4];
    f32 unk_184;  // 1 loads, 0 stores
    s16 unk_188;  // 1 loads, 0 stores
    u8 pad_18A[0x32];
    u32 unk_1BC;  // 1 loads, 0 stores
    u32 unk_1C0;  // 1 loads, 0 stores
    u32 unk_1C4;  // 1 loads, 0 stores
    u8 pad_1C8[0x2C];
    f32 unk_1F4;  // 1 loads, 0 stores
    f32 unk_1F8;  // 1 loads, 0 stores
    f32 unk_1FC;  // 1 loads, 0 stores
    f32 unk_200;  // 1 loads, 0 stores
    f32 unk_204;  // 1 loads, 0 stores
    u8 pad_208[0xC];
    u16 unk_214;  // 1 loads, 0 stores
    u8 pad_216[0x2];
    u32 unk_218;  // 1 loads, 0 stores
    u8 pad_21C[0x8];
    f32 unk_224;  // 1 loads, 0 stores
    u8 pad_228[0x24C];
    u8 unk_474;  // 3 loads, 0 stores
    u8 unk_475;  // 1 loads, 0 stores
    u8 pad_476[0xE];
    u32 unk_484;  // 2 loads, 0 stores
    u8 pad_488[0x14];
    u32 unk_49C;  // 5 loads, 0 stores
    u32 unk_4A0;  // 1 loads, 0 stores
    u32 unk_4A4;  // 1 loads, 0 stores
    u32 unk_4A8;  // 1 loads, 0 stores
    u8 pad_4AC[0xE0];
    u32 unk_58C;  // 1 loads, 0 stores
    u8 pad_590[0x90];
} Obj_1_bss_6D838_Target_L;

/* fn_1_112F40 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 unk_10;
    u8 pad_11[0x1];
    u8 unk_12;
    u8 pad_13[0x1];
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 unk_20;
    u8 pad_21[0x3];
    u32 unk_24;
    u8 pad_28[0x2];
    s16 unk_2A;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 pad_3F[0x1D];
    u32 unk_5C;
    u8 pad_60[0x70];
    u8 arr_D0[0x4];
    u16 unk_D4;
    u8 unk_D6;
    u8 unk_D7;
    u32 unk_D8;
    u32 unk_DC;
    u32 unk_E0;
    u32 unk_E4;
    u32 unk_E8;
    u32 unk_EC;
    u32 unk_F0;
    u32 unk_F4;
    u32 unk_F8;
    u32 unk_FC;
    u32 unk_100;
    u8 arr_104[0x8];
    u8 unk_10C;
    u8 pad_10D[0x73];
    u8 unk_180;
    u8 unk_181;
    u8 unk_182;
    u8 pad_183[0x1];
    u8 unk_184;
    u8 unk_185;
    u8 unk_186;
    u8 unk_187;
    u8 pad_188[0x125C];
    u32 unk_13E4;
    u32 unk_13E8;
    u32 unk_13EC;
    u8 pad_13F0[0x14];
    u32 unk_1404;
    u32 unk_1408;
    u32 unk_140C;
    u8 pad_1410[0x14];
    u8 unk_1424;
    u8 unk_1425;
    u8 unk_1426;
    u8 pad_1427[0x1];
    u16 unk_1428;
    u16 unk_142A;
    u16 unk_142C;
    u16 unk_142E;
    u16 unk_1430;
    u8 unk_1432;
    u8 unk_1433;
    u8 unk_1434;
    u8 unk_1435;
    u8 pad_1436[0x3E];
    u32 unk_1474;
    u32 unk_1478;
    u8 pad_147C[0x10];
    u16 unk_148C;
    u8 unk_148E;
    u8 unk_148F;
    u8 unk_1490;
    u8 unk_1491;
    u8 unk_1492;
    u8 unk_1493;
    u32 unk_1494;
    u8 unk_1498;
    u8 unk_1499;
    u8 unk_149A;
    u8 unk_149B;
    u8 unk_149C;
    u8 unk_149D;
    u16 unk_149E;
    u8 unk_14A0;
    u8 unk_14A1;
    u8 unk_14A2;
    u8 unk_14A3;
    u32 unk_14A4;
    u8 pad_14A8[0x18];
    u32 unk_14C0;
    u32 unk_14C4;
    u32 unk_14C8;
    u32 unk_14CC;
    u32 unk_14D0;
    u32 unk_14D4;
    u32 unk_14D8;
    u8 pad_14DC[0xC];
    u16 unk_14E8;
    u8 pad_14EA[0x2];
    u16 unk_14EC;
    u16 unk_14EE;
    u16 unk_14F0;
    u16 unk_14F2;
    u8 unk_14F4;
    u8 pad_14F5[0x3];
    u32 unk_14F8;
    u16 unk_14FC;
    u8 pad_14FE[0x2];
    u32 unk_1500;
    u8 unk_1504;
    u8 pad_1505[0x3];
    u8 unk_1508;
    u8 unk_1509;
    u8 pad_150A[0x1];
    u8 unk_150B;
    u32 unk_150C;
    u8 pad_1510[0x28];
    u16 unk_1538;
    u8 unk_153A;
    u8 unk_153B;
    u8 pad_153C[0xC];
    u16 unk_1548;
    u16 unk_154A;
    u8 pad_154C[0x8];
    f32 unk_1554;
    u8 unk_1558;
    u8 pad_1559[0xBF];
    u8 unk_1618;
    u8 unk_1619;
    u8 unk_161A;
    u8 unk_161B;
    u8 unk_161C;
    u8 unk_161D;
    u8 pad_161E[0x5];
    u8 unk_1623;
    u8 unk_1624;
    u8 pad_1625[0x3];
    u32 unk_1628;
    u32 unk_162C;
    char *unk_1630;
    u8 unk_1634;
    u8 pad_1635[0x3];
    u32 unk_1638;
    u8 unk_163C;
    u8 unk_163D;
    u8 unk_163E;
    u8 unk_163F;
    u8 unk_1640;
    u8 unk_1641;
    u8 unk_1642;
    u8 unk_1643;
    u8 unk_1644;
    u8 unk_1645;
    u8 arr_1646[0x16];
    u8 arr_165C[0xF0];
    u8 arr_174C[0xA0];
    u8 unk_17EC;
    u8 unk_17ED;
    u8 unk_17EE;
    u8 pad_17EF[0x5];
    u16 unk_17F4;
    u8 pad_17F6[0x2];
    u32 unk_17F8;
    u32 unk_17FC;
    u32 unk_1800;
    u32 unk_1804;
    u32 unk_1808;
    u32 unk_180C;
    u8 arr_1810[0x20770];
    u16 unk_21F80;
    u8 pad_21F82[0x2];
    u32 unk_21F84;
    u32 unk_21F88;
    u32 unk_21F8C;
    u32 unk_21F90;
    u32 unk_21F94;
    u16 unk_21F98;
    u8 pad_21F9A[0x2];
    u32 unk_21F9C;
    u32 unk_21FA0;
    u32 unk_21FA4;
    u8 unk_21FA8;
    u8 arr_21FA9[0x1F];
    u8 unk_21FC8;
    u8 unk_21FC9;
    u8 unk_21FCA;
    u8 unk_21FCB;
    u8 unk_21FCC;
    u8 unk_21FCD;
    u8 unk_21FCE;
    u8 unk_21FCF;
    u8 arr_21FD0[0x16];
    u16 unk_21FE6;
    u16 unk_21FE8;
    u8 unk_21FEA;
    u8 pad_21FEB[0x1];
    u32 unk_21FEC;
    u32 unk_21FF0;
    u32 unk_21FF4;
    f32 unk_21FF8;
    f32 unk_21FFC;
    u32 unk_22000;
    u32 unk_22004;
    u32 unk_22008;
    u32 unk_2200C;
    u32 unk_22010;
    u32 unk_22014;
    u32 unk_22018;
    u32 unk_2201C;
    u32 unk_22020;
    u32 unk_22024;
    u32 unk_22028;
    u32 unk_2202C;
    f32 unk_22030;
    f32 unk_22034;
    u32 unk_22038;
    u32 unk_2203C;
    u32 unk_22040;
    u32 unk_22044;
    u16 unk_22048;
    u8 arr_2204A[0x3A];
    u8 arr_22084[0x20];
    u32 unk_220A4;
    u32 unk_220A8;
    u32 unk_220AC;
    u32 unk_220B0;
    u32 unk_220B4;
    u32 unk_220B8;
    u32 unk_220BC;
    u32 unk_220C0;
    u32 unk_220C4;
    u32 unk_220C8;
    u32 unk_220CC;
    u32 unk_220D0;
    u8 arr_220D4[0x163];
    u8 unk_22237;
    u8 pad_22238[0x1C];
    u32 unk_22254;
    u32 unk_22258;
    u32 unk_2225C;
    u32 unk_22260;
    u32 unk_22264;
    u32 unk_22268;
    u32 unk_2226C;
    u32 unk_22270;
    u32 unk_22274;
    u32 unk_22278;
    u32 unk_2227C;
    u32 unk_22280;
    u32 unk_22284;
    u32 unk_22288;
    u32 unk_2228C;
    u8 unk_22290;
    u8 pad_22291[0x3];
    u32 unk_22294;
    u8 unk_22298;
    u8 arr_22299[0x3];
    u16 unk_2229C;
    u8 pad_2229E[0x2];
    u32 unk_222A0;
    u8 unk_222A4;
    u8 pad_222A5[0x3];
    u32 unk_222A8;
    u8 pad_222AC[0x10];
    u8 arr_222BC[0x3A0];
    u8 unk_2265C;
    u8 unk_2265D;
    u8 unk_2265E;
    u8 unk_2265F;
    u8 unk_22660;
    u8 unk_22661;
    u8 arr_22662[0x1A];
    u32 unk_2267C;
    u32 unk_22680;
    u32 unk_22684;
    u32 unk_22688;
    u32 unk_2268C;
    u32 unk_22690;
    u8 arr_22694[0x60];
    u8 unk_226F4;
    u8 pad_226F5[0x3];
    u32 unk_226F8;
    u8 arr_226FC[0x4];
    u16 unk_22700;
    u8 pad_22702[0x2];
    f32 unk_22704;
    f32 unk_22708;
    f32 unk_2270C;
    f32 unk_22710;
    u8 arr_22714[0x7F0];
    u8 arr_22F04[0x4];
    u32 unk_22F08;
    u32 unk_22F0C;
    u32 unk_22F10;
    u32 unk_22F14;
    u8 unk_22F18;
    u8 unk_22F19;
    u8 unk_22F1A;
    u8 unk_22F1B;
    u8 unk_22F1C;
    u8 unk_22F1D;
    u8 unk_22F1E;
    u8 pad_22F1F[0x1];
    u8 unk_22F20;
    u8 unk_22F21;
    u8 unk_22F22;
    u8 unk_22F23;
    u8 unk_22F24;
    u8 unk_22F25;
    u8 unk_22F26;
    u8 unk_22F27;
    u8 arr_22F28[0x18];
    f32 unk_22F40;
    f32 unk_22F44;
    u32 unk_22F48;
    u32 unk_22F4C;
    u32 unk_22F50;
    u8 unk_22F54;
    u8 pad_22F55[0x3];
    u32 unk_22F58;
    u8 arr_22F5C[0x1E];
    u16 unk_22F7A;
    u8 unk_22F7C;
    u8 pad_22F7D[0x3];
    u8 arr_22F80[0x96];
    u8 unk_23016;
    u8 pad_23017[0x1];
    u32 unk_23018;
    u32 unk_2301C;
    u32 unk_23020;
    u8 unk_23024;
    u8 pad_23025[0x3];
    u32 unk_23028;
    u32 unk_2302C;
    u32 unk_23030;
    u32 unk_23034;
    u32 unk_23038;
    u32 unk_2303C;
    u32 unk_23040;
    u32 unk_23044;
    f32 unk_23048;
    f32 unk_2304C;
    f32 unk_23050;
    f32 unk_23054;
    u8 unk_23058;
    u8 pad_23059[0x3];
    u32 unk_2305C;
    u32 unk_23060;
    u32 unk_23064;
    u16 unk_23068;
    u8 unk_2306A;
    u8 pad_2306B[0x1];
    u8 arr_2306C[0x4];
    u8 arr_23070[0x4];
    u32 unk_23074;
    u32 unk_23078;
    u32 unk_2307C;
    u32 unk_23080;
    u16 unk_23084;
    u16 unk_23086;
    u32 unk_23088;
    u32 unk_2308C;
    u32 unk_23090;
    u32 unk_23094;
    u32 unk_23098;
    u32 unk_2309C;
    u32 unk_230A0;
    u32 unk_230A4;
    u8 pad_230A8[0x28];
    u32 unk_230D0;
    u8 pad_230D4[0x4];
    u8 arr_230D8[0x70];
    u8 arr_23148[0x1380];
    u8 arr_244C8[0x2718];
    u8 arr_26BE0[0x324];
    u32 unk_26F04;
    u8 unk_26F08;
    u8 pad_26F09[0x43B];
    u32 unk_27344;
    u8 unk_27348;
    u8 pad_27349[0x43B];
    u32 unk_27784;
    u8 unk_27788;
    u8 pad_27789[0x43B];
    u32 unk_27BC4;
    u8 unk_27BC8;
    u8 pad_27BC9[0x43B];
    u32 unk_28004;
    u8 unk_28008;
    u8 pad_28009[0x43B];
    u32 unk_28444;
    u8 unk_28448;
    u8 pad_28449[0x43B];
    u32 unk_28884;
    u8 unk_28888;
    u8 pad_28889[0x43B];
    u32 unk_28CC4;
    u8 unk_28CC8;
    u8 pad_28CC9[0x117];
    u8 arr_28DE0[0x8C40];
    u8 arr_31A20[0xA20];
    u8 arr_32440[0x1E60];
    u8 arr_342A0[0x190];
    u8 arr_34430[0x190];
    u8 arr_345C0[0x10];
    u8 arr_345D0[0x20];
    u8 arr_345F0[0x4];
    u8 unk_345F4;
    u8 pad_345F5[0xB];
    u8 unk_34600;
} Obj_1_bss_3C00;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;  // 58 loads, 0 stores
} Obj_1_bss_38458_Target_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 10 loads, 1 stores
    u16 unk_4;  // 0 loads, 2 stores
    u8 pad_6[0x1C];
    s16 unk_22;  // 4 loads, 4 stores
    u16 unk_24;  // 0 loads, 1 stores
    u8 pad_26[0x1E];
    s16 unk_44;  // 1 loads, 1 stores
    u16 unk_46;  // 0 loads, 1 stores
    u8 unk_48;  // 30 loads, 13 stores
    u8 unk_49;  // 2 loads, 1 stores
    u8 unk_4A;  // 2 loads, 1 stores
    u8 unk_4B;  // 2 loads, 2 stores
    u8 unk_4C;  // 2 loads, 2 stores
    u8 unk_4D;  // 1 loads, 1 stores
    u8 pad_4E[0x2];
    u32 unk_50;  // 5 loads, 1 stores
    u32 unk_54;  // 2 loads, 1 stores
    f32 unk_58;  // 0 loads, 3 stores
    f32 unk_5C;  // 1 loads, 3 stores
} Obj_1_bss_F68_Target_L;

/* fn_1_112F40 */
typedef struct {
    f32 unk_0;  // 2 loads, 10 stores
    f32 unk_4;  // 3 loads, 8 stores
    f32 unk_8;  // 2 loads, 7 stores
    s16 unk_C;  // 9 loads, 7 stores
    s16 unk_E;  // 2 loads, 3 stores
    u32 unk_10;  // 2 loads, 9 stores
    u32 unk_14;  // 0 loads, 6 stores
    f32 unk_18;  // 2 loads, 3 stores
    f32 unk_1C;  // 7 loads, 15 stores
    f32 unk_20;  // 3 loads, 11 stores
    f32 unk_24;  // 0 loads, 3 stores
    f32 unk_28;  // 2 loads, 3 stores
    u32 unk_2C;  // 11 loads, 11 stores
    u16 unk_30;  // 0 loads, 2 stores
    u16 unk_32;  // 0 loads, 3 stores
    u16 unk_34;  // 0 loads, 3 stores
    u8 unk_36;  // 0 loads, 3 stores
    u8 unk_37;  // 0 loads, 4 stores
    f32 unk_38;  // 0 loads, 3 stores
    f32 unk_3C;  // 6 loads, 3 stores
    f32 unk_40;  // 1 loads, 3 stores
    u8 unk_44;  // 3 loads, 3 stores
    u8 unk_45;  // 3 loads, 3 stores
    u8 unk_46;  // 6 loads, 3 stores
    u8 unk_47;  // 3 loads, 3 stores
    s16 unk_48;  // 3 loads, 3 stores
    s16 unk_4A;  // 3 loads, 3 stores
    s16 unk_4C;  // 3 loads, 3 stores
    s16 unk_4E;  // 3 loads, 3 stores
    f32 unk_50;  // 0 loads, 3 stores
    u32 unk_54;  // 2 loads, 3 stores
    u32 unk_58;  // 3 loads, 3 stores
} Obj_1_bss_4B9CC_L;

/* fn_1_112F40 */
typedef struct {
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
    u8 pad_28[0x4];
    u8 arr_2C[0x1];
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
    u8 arr_30[0x1];
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 arr_34[0x1];
    u8 unk_35;
    u8 unk_36;
    u8 pad_37[0x1];
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u8 arr_44[0x4];
    u32 unk_48;
    u32 unk_4C;
    u8 arr_50[0x1];
    u8 unk_51;
    u16 unk_52;
    u8 arr_54[0x13B0];
    u32 unk_1404;
    u8 arr_1408[0x1F8];
    u32 unk_1600;
    u8 arr_1604[0x10];
    u32 unk_1614;
    u8 arr_1618[0x10];
    u32 unk_1628;
    u8 arr_162C[0x10];
    u32 unk_163C;
    u8 arr_1640[0x10];
    u32 unk_1650;
    u8 arr_1654[0x10];
    u32 unk_1664;
    u8 arr_1668[0x10];
    u32 unk_1678;
    u8 arr_167C[0x10];
    s8 *unk_168C[5];  // indexed per player (fn_1_F0E00)
    u16 *unk_16A0[5];  // indexed per player (fn_1_F0E00)
    u32 unk_16B4;
    u8 arr_16B8[0x10];
    u32 unk_16C8;
    u8 unk_16CC;
    u8 pad_16CD[0x3];
    u32 unk_16D0;
    u32 unk_16D4;
    u32 unk_16D8;
    u32 unk_16DC;
    u8 unk_16E0;
    u8 pad_16E1[0x3];
    u32 unk_16E4;
    u32 unk_16E8;
    u32 unk_16EC[5];  // indexed per player (fn_1_E9770)
    u32 unk_1700[5];  // indexed per player (fn_1_E9770)
    u32 unk_1714[5];  // indexed per player (fn_1_E9770)
    u32 unk_1728[5];  // indexed per player (fn_1_E9770)
    u32 unk_173C;
    u32 unk_1740;
    u32 unk_1744;
    u32 unk_1748;
    u8 unk_174C;
    u8 unk_174D;
    u8 unk_174E;
    u8 pad_174F[0x1];
    u32 unk_1750;
    u8 unk_1754;
    u8 pad_1755[0x3];
    f32 unk_1758;
    f32 unk_175C;
    f32 unk_1760;
    u8 pad_1764[0x30];
    u32 unk_1794;
    u8 arr_1798[0x10];
    u32 unk_17A8;
    u8 arr_17AC[0x10];
    u32 unk_17BC;
    u32 unk_17C0;
    u32 unk_17C4;
    u32 unk_17C8;
    u32 unk_17CC;
    u16 unk_17D0;
    u16 unk_17D2;
    u16 unk_17D4;
    u16 unk_17D6;
    u16 unk_17D8;
    u8 pad_17DA[0x2];
    u32 unk_17DC;
    u32 unk_17E0;
    u32 unk_17E4;
    u32 unk_17E8;
    u32 unk_17EC;
    u8 unk_17F0;
    u8 unk_17F1;
    u8 unk_17F2;
    u8 unk_17F3;
    u8 unk_17F4;
    u8 unk_17F5;
    u8 unk_17F6;
    u8 unk_17F7;
    u8 unk_17F8;
    u8 unk_17F9;
    u8 unk_17FA;
    u8 unk_17FB;
    u8 unk_17FC;
    u8 unk_17FD;
    u8 unk_17FE;
    u8 pad_17FF[0x1];
    u16 unk_1800;
    u8 arr_1802[0xA];
    u8 arr_180C[0x14];
    u32 unk_1820;
    u32 unk_1824;
    u8 arr_1828[0x10];
    u16 unk_1838;
    s16 unk_183A;
    u32 unk_183C;
    u8 pad_1840[0x18];
    u8 arr_1858[0x80];
    u8 arr_18D8[0x30];
    u8 arr_1908[0xC0];
    u8 arr_19C8[0x620];
    u32 unk_1FE8;
    u16 unk_1FEC;
    u8 pad_1FEE[0x76];
    u32 unk_2064;
    u32 unk_2068;
    u32 unk_206C;
    u8 pad_2070[0x64];
    u8 arr_20D4[0x60];
    u8 arr_2134[0xB4];
    f32 unk_21E8;
    u8 pad_21EC[0x20];
    f32 unk_220C;
    u8 pad_2210[0x24D];
    u8 unk_245D;
    u8 pad_245E[0x141A];
    u32 unk_3878;
    u32 unk_387C;
    u8 unk_3880;
    u8 pad_3881[0x3];
    u32 unk_3884;
    u32 unk_3888;
    u8 unk_388C;
    u8 pad_388D[0x3];
    u32 unk_3890;
    u32 unk_3894;
    u32 unk_3898;
    f32 unk_389C;
    f32 unk_38A0;
    u8 unk_38A4;
    u8 unk_38A5;
    u8 unk_38A6;
    u8 pad_38A7[0x1];
    u32 unk_38A8;
    u32 unk_38AC;
    u32 unk_38B0;
    u32 unk_38B4;
    u32 unk_38B8;
    f32 unk_38BC;
    u32 unk_38C0;
    u8 arr_38C4[0x30];
    u8 arr_38F4[0xC0];
    u32 unk_39B4;
    u32 unk_39B8;
    u32 unk_39BC;
    u8 arr_39C0[0x30];
    u32 unk_39F0;
    u8 arr_39F4[0x10];
    u8 arr_3A04[0x30];
    u8 arr_3A34[0xC0];
    u8 arr_3AF4[0xC];
    u8 arr_3B00[0x30];
    u32 unk_3B30;
    u8 arr_3B34[0x8];
    u32 unk_3B3C;
    u32 unk_3B40;
    u32 unk_3B44;
    u8 pad_3B48[0x2];
    u16 unk_3B4A;
    u8 pad_3B4C[0x30];
    u32 unk_3B7C;
    u8 arr_3B80[0x58];
    u32 unk_3BD8;
} Obj_1_bss_7B180_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 4 loads, 4 stores
    u8 pad_4[0x4];
    u8 unk_8;  // 1 loads, 0 stores
    u8 pad_9[0x7];
} Obj_1_data_3D544_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 5 loads, 1 stores
    u8 unk_4;  // 5 loads, 2 stores
    u8 unk_5;  // 0 loads, 1 stores
    u8 unk_6;  // 0 loads, 1 stores
    u8 unk_7;  // 0 loads, 1 stores
    f32 unk_8;  // 9 loads, 2 stores
    u8 unk_C;  // 6 loads, 1 stores
    u8 unk_D;  // 1 loads, 1 stores
    u8 unk_E;  // 1 loads, 1 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 unk_10;  // 6 loads, 1 stores
    u8 unk_11;  // 1 loads, 1 stores
    u8 unk_12;  // 0 loads, 1 stores
    u8 unk_13;  // 0 loads, 1 stores
    u8 unk_14;  // 5 loads, 1 stores
    u8 unk_15;  // 0 loads, 1 stores
    u8 unk_16;  // 0 loads, 1 stores
    u8 pad_17[0x1];
    u32 unk_18;  // 5 loads, 1 stores
    u32 unk_1C;  // 5 loads, 1 stores
    u32 unk_20;  // 6 loads, 1 stores
    u32 unk_24;  // 6 loads, 1 stores
} Obj_1_bss_6C7A4_L;

/* fn_1_112F40 */
typedef struct {
    u8 unk_0;  // 1 loads, 0 stores
    u8 pad_1[0x97];
    u32 unk_98;  // 1 loads, 1 stores
    u32 unk_9C;  // 1 loads, 1 stores
    u16 unk_A0;  // 5 loads, 4 stores
    u16 unk_A2;  // 1 loads, 0 stores
} Obj_1_bss_7EFD8_At40_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 11 loads, 8 stores
    u32 unk_4;  // 1 loads, 2 stores
    u32 unk_8;  // 2 loads, 1 stores
    u32 unk_C;  // 3 loads, 1 stores
    u32 unk_10;  // 0 loads, 2 stores
    u32 unk_14;  // 2 loads, 2 stores
    u8 unk_18;  // 1 loads, 1 stores
    u8 unk_19;  // 0 loads, 4 stores
    u8 unk_1A;  // 1 loads, 3 stores
    u8 unk_1B;  // 1 loads, 3 stores
    u8 unk_1C;  // 0 loads, 2 stores
    u8 unk_1D;  // 0 loads, 1 stores
    u8 unk_1E;  // 0 loads, 1 stores
    u8 unk_1F;  // 0 loads, 1 stores
    u8 unk_20;  // 0 loads, 3 stores
    u8 unk_21;  // 0 loads, 2 stores
    u8 unk_22;  // 0 loads, 2 stores
    u8 unk_23;  // 0 loads, 2 stores
    u8 unk_24;  // 1 loads, 1 stores
    u8 unk_25;  // 0 loads, 1 stores
    u8 unk_26;  // 0 loads, 1 stores
    u8 unk_27;  // 0 loads, 1 stores
    u32 unk_28;  // 1 loads, 0 stores
    u8 pad_2C[0xC];
    u8 unk_38;  // 1 loads, 0 stores
    u8 pad_39[0x3];
    u8 unk_3C;  // 1 loads, 0 stores
    u8 pad_3D[0x3];
    Obj_1_bss_7EFD8_At40_L *unk_40;  // 50 loads, 0 stores
} Obj_1_bss_7EFD8_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 43 loads, 26 stores
    u8 pad_4[0xE];
} Obj_1_bss_6EAB4_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 3 loads, 3 stores
    u8 pad_4[0x4];
    u32 unk_8;  // 1 loads, 0 stores
    u32 unk_C;  // 1 loads, 0 stores
    u8 pad_10[0x68];
    u32 unk_78;  // 1 loads, 0 stores
    u32 unk_7C;  // 1 loads, 0 stores
    u32 unk_80;  // 8 loads, 3 stores
    u8 pad_84[0x7C];
    u32 unk_100;  // 0 loads, 3 stores
    u8 pad_104[0x7C];
    u32 unk_180;  // 0 loads, 3 stores
    u8 pad_184[0x7C];
    u32 unk_200;  // 0 loads, 3 stores
    u8 pad_204[0x7C];
    u32 unk_280;  // 0 loads, 3 stores
    u8 pad_284[0x7C];
    u32 unk_300;  // 0 loads, 3 stores
    u8 pad_304[0x7C];
    u32 unk_380;  // 0 loads, 3 stores
    u8 pad_384[0x1C7C];
} Obj_1_bss_4C688_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 4 loads, 4 stores
    u32 unk_4;  // 5 loads, 5 stores
    u32 unk_8;  // 4 loads, 4 stores
    u8 pad_C[0xBF4];
} Obj_1_bss_88B50_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 0 loads, 5 stores
    u32 unk_4;  // 0 loads, 1 stores
    u32 unk_8;  // 0 loads, 1 stores
    u32 unk_C;  // 0 loads, 1 stores
} Obj_1_bss_89760_L;

/* fn_1_112F40 */
typedef struct {
    f32 unk_0;  // 1 loads, 4 stores
    u8 pad_4[0xC];
} Obj_1_bss_89770_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 1 loads, 1 stores
    u32 unk_4;  // 1 loads, 0 stores
    u32 unk_8;  // 1 loads, 0 stores
    u8 pad_C[0x4];
} Obj_1_bss_89750_L;

/* fn_1_112F40 */
typedef struct {
    u8 unk_0;  // 5 loads, 6 stores
    u8 unk_1;  // 12 loads, 5 stores
    u8 unk_2;  // 3 loads, 1 stores
    u8 pad_3[0x1];
    u16 unk_4;  // 2 loads, 3 stores
    u8 pad_6[0x2];
    u32 unk_8;  // 0 loads, 2 stores
    u8 pad_C[0x4];
    u32 unk_10;  // 9 loads, 1 stores
    f32 unk_14;  // 18 loads, 5 stores
    f32 unk_18;  // 14 loads, 1 stores
    u32 unk_1C;  // 3 loads, 3 stores
    u32 unk_20;  // 3 loads, 3 stores
    u32 unk_24;  // 3 loads, 3 stores
    u32 unk_28;  // 1 loads, 1 stores
    u32 unk_2C;  // 1 loads, 1 stores
    u32 unk_30;  // 1 loads, 1 stores
    f32 unk_34;  // 0 loads, 3 stores
    f32 unk_38;  // 4 loads, 5 stores
    f32 unk_3C;  // 0 loads, 3 stores
    f32 unk_40;  // 0 loads, 4 stores
    u8 pad_44[0x1];
    u8 unk_45;  // 2 loads, 0 stores
    u8 pad_46[0x12];
    f32 unk_58;  // 2 loads, 0 stores
} Obj_1_bss_85250_At18_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 3 loads, 0 stores
    u32 unk_4;  // 3 loads, 0 stores
    f32 unk_8;  // 4 loads, 0 stores
} Obj_1_bss_85250_At20_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 2 loads, 1 stores
    u32 unk_4;  // 7 loads, 2 stores
    u32 unk_8;  // 3 loads, 1 stores
    u32 unk_C;  // 2 loads, 3 stores
    Obj_1_bss_38458_Target_L *unk_10;  // 7 loads, 3 stores
    u32 unk_14;  // 4 loads, 3 stores
    Obj_1_bss_85250_At18_L *unk_18;  // 35 loads, 3 stores
    u32 unk_1C;  // 25 loads, 2 stores
    Obj_1_bss_85250_At20_L *unk_20;  // 19 loads, 3 stores
    u32 unk_24;  // 4 loads, 1 stores
    u32 unk_28;  // 2 loads, 2 stores
    u32 unk_2C;  // 2 loads, 3 stores
} Obj_1_bss_85250_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 3 loads, 2 stores
    u32 unk_4;  // 5 loads, 2 stores
} Obj_1_bss_85280_L;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x4];
    Obj_1_bss_38458_Target_L *unk_4;  // 13 loads, 0 stores
    Obj_1_bss_38458_Target_L *unk_8;  // 14 loads, 0 stores
    u8 pad_C[0x48];
} Obj_1_bss_38460_L;

/* fn_1_112F40 */
typedef struct {
    u8 unk_0;  // 1 loads, 0 stores
    u8 unk_1;  // 1 loads, 0 stores
    u8 unk_2;  // 1 loads, 0 stores
    u8 unk_3;  // 1 loads, 0 stores
    u8 pad_4[0x5C];
} Obj_1_data_3F28C_L;

/* fn_1_112F40 */
typedef struct {
    u32 unk_0;  // 4 loads, 0 stores
    u32 unk_4;  // 4 loads, 0 stores
    u32 unk_8;  // 4 loads, 0 stores
    u8 pad_C[0x54];
} Obj_1_data_3F2EC_L;

/* fn_1_112F40 */
typedef struct {
    u8 unk_0;  // 2 loads, 3 stores
    u8 pad_1[0x3];
    f32 unk_4;  // 2 loads, 3 stores
    f32 unk_8;  // 2 loads, 3 stores
    u8 unk_C;  // 2 loads, 3 stores
    u8 unk_D;  // 2 loads, 3 stores
    u8 unk_E;  // 2 loads, 3 stores
    u8 unk_F;  // 3 loads, 3 stores
    u8 pad_10[0x1C];
} Obj_1_bss_6D7F4;

/* fn_1_112F40 */
typedef struct {
    u8 unk_0;  // 2 loads, 2 stores
    u8 pad_1[0x3];
    f32 unk_4;  // 3 loads, 2 stores
    f32 unk_8;  // 3 loads, 2 stores
    u8 unk_C;  // 3 loads, 2 stores
    u8 unk_D;  // 2 loads, 1 stores
    u8 unk_E;  // 2 loads, 1 stores
    u8 unk_F;  // 2 loads, 0 stores
    u32 unk_10;  // 3 loads, 1 stores
    u32 unk_14;  // 1 loads, 1 stores
    u8 pad_18[0x120];
} Obj_1_bss_6D620;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x14c];
    Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x8];
    Vec3 dir;
    f32 radius;
} Fn183D28Target;

/* fn_1_112F40 */
typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

/* fn_1_112F40 */
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

/* fn_1_112F40 */
typedef struct {
    u32 flags;
    u8 pad_4[0x5];
    u8 count;
    u8 pad_A[0x14AE];
    f64 pad_14B8;
} CarTestInfo;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

/* fn_1_112F40 */
typedef struct RopeMtx {
    u8 data[0x40];
} RopeMtx;

/* fn_1_112F40 */
typedef struct RopePool {
    u8 pad_0[0x58];
    f64 gravityHalf; /* 0x58 */
    f32 gravity;     /* 0x60 */
    u8 pad_64[0x38];
    f32 slack;       /* 0x9C */
    f32 one;         /* 0xA0 */
    f32 maxDist2;    /* 0xA4 */
} RopePool;

/* fn_1_112F40 */
struct fn_1_10CC38_lbl_1_rodata_7AB8_112F40 {
 u8 pad_0[0x58]; f64 unk_58; f32 unk_60; u8 pad_64[0x38]; f32 unk_9C;
 u8 pad_A0[0xA8]; Vec3f unk_148; f32 unk_154, unk_158, unk_15C, unk_160;
};

/* fn_1_112F40 */
struct fn_1_115560_lbl_1_rodata_7AB8 {
 u8 pad_0[0x50]; f64 unk_50; u8 pad_58[0x130]; f64 unk_188,unk_190,unk_198;
 u8 pad_1A0[0x1C4]; Sig_fn_1_1286F4_Vec3f unk_364; f64 unk_370,unk_378;
};

/* fn_1_112F40 */
typedef struct { u8 p0[8]; u8 *base; } Inner;

/* fn_1_112F40 */
typedef struct { u8 flags; u8 pad[0xF]; Vec3 pos; f32 w; u8 rest[0x44 - 0x20]; } Ent;

/* fn_1_112F40 */
typedef struct { u8 p0[0xC]; struct { u8 p[0x150]; Inner *in; } *c; u8 p1[0x8]; u32 count; u8 p2[0x8]; Ent *ents; } Obj;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x8];
    Fn1108BD0_Joint *elems;
} Fn108EECList;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0x150];
    Fn108EECList *list;
} Fn108EECOwner;

/* fn_1_112F40 */
typedef struct {
    u8 flags;
    u8 pad_1[0xF];
    Vec3 pos;
    u8 pad_1C[0x28];
} Fn108EECPoint;

/* fn_1_112F40 */
typedef struct {
    u8 pad_0[0xC];
    Fn108EECOwner *owner;
    u8 pad_10[0x8];
    u32 count;
    u8 pad_1C[0x8];
    Fn108EECPoint *points;
} Fn108EECObj;

/* fn_1_112F40 */
struct fn_1_10AD18_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_10BE3C_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_10CC38_Sig_fn_80077B14_fn_80077B14_Arg0 { u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20; };

/* fn_1_112F40 */
struct fn_1_10D7D4_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_110478_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_111980_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_1188CC_Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_1192D0_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_11A774_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_11B958_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_11C440_Sig_fn_80077B14_fn_80077B14_Arg0 {
u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_11CD3C_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_11F250_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_124AD4_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_1256EC_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_125DF0_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_126774_Sig_fn_80077B14_fn_80077B14_Arg0 {
u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
struct fn_1_12744C_Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_112F40 */
typedef struct { u8 p0[0xC]; struct { u8 p[0x150]; Inner *in; } *c; u8 p1[0x8]; u32 count; u8 p2[0x8]; Ent *ents; } fn_1_108A90_Obj;

/* fn_1_112F40 */
struct fn_1_129D9C_fn_1_129D9C_vec {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

/* fn_1_112F40 */
struct fn_1_129D9C_fn_1_129D9C_obj {
    u8 pad_0[0x10];
    u8 unk_10;
};

/* fn_1_1132E4 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_1132E4 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_1132E4 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_1132E4 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_1132E4;

/* fn_1_1137E4 */
typedef struct RopeNode_1137E4 {
    u8 flags;
    u8 pad_1;
    u8 linkCount;
    u8 pad_3;
    u16 links[6];
    Vec3 pos;
    Vec3 prev;
    Vec3 local;
    Vec3 vel;
    f32 mass;
} RopeNode_1137E4;

/* fn_1_1137E4 */
typedef struct Link_1137E4 {
    RopeNode_1137E4 *a;
    RopeNode_1137E4 *b;
    f32 length;
} Link_1137E4;

/* fn_1_1137E4 */
typedef struct Rope_1137E4 {
    u8 flags;
    u8 pad_1[0x7];
    u32 kind;
    RopeOwner_10DDE4 *owner;
    void *skin;
    u8 pad_14[0x4];
    u32 count;
    u32 linkCount;
    u8 pad_20[0x4];
    RopeNode_1137E4 *nodes;
    Link_1137E4 *links;
} Rope_1137E4;

/* fn_1_113C58 */
typedef struct AccessoryPoint {
    u8 unk_0;
    u8 pad_1[15];
    Vec3 unk_10;
    Vec3 unk_1C;
    Vec3 unk_28;
    Vec3 unk_34;
    f32 unk_40;
} AccessoryPoint;

/* fn_1_113C58 */
typedef struct AccessoryLink {
    AccessoryPoint *unk_0;
    AccessoryPoint *unk_4;
    f32 unk_8;
} AccessoryLink;

/* fn_1_113C58 */
typedef struct {
    u8 pad_0[8];
    u8 *unk_8;
} AccessoryModel;

/* fn_1_113C58 */
typedef struct {
    u8 pad_0[0x8C];
    s32 unk_8C;
    u8 pad_90[0xC0];
    AccessoryModel *unk_150;
} AccessoryDataLocal;

/* fn_1_113C58 */
typedef struct {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    AccessoryDataLocal *unk_C;
    void *unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    AccessoryPoint *unk_24;
    AccessoryLink *unk_28;
} AccessoryObjectLocal;

/* fn_1_1145C8 */
typedef struct Accessory1145C8Node {
    u8 flag;
    u8 pad_1[0xF];
    f32 keyA;
    u8 pad_14[0x4];
    f32 keyB;
    u8 pad_1C[0x24];
    f32 value;
} Accessory1145C8Node;

/* fn_1_1145C8 */
typedef struct Accessory1145C8Mode {
    u8 pad_0[0x88];
    s32 mode;
} Accessory1145C8Mode;

/* fn_1_1145C8 */
typedef struct Accessory1145C8Edge {
    Accessory1145C8Node *a;
    Accessory1145C8Node *b;
    f32 len;
} Accessory1145C8Edge;

/* fn_1_1145C8 */
typedef struct Accessory1145C8 {
    u8 pad_0[0xC];
    Accessory1145C8Mode *unk_C;
    u8 pad_10[0x8];
    u32 count;
    u32 edgeCount;
    u8 pad_20[0x4];
    Accessory1145C8Node *nodes;
    Accessory1145C8Edge *edges;
} Accessory1145C8;

/* fn_1_11492C */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11492C {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11492C */
typedef struct { u8 pad[0x88]; s32 kind; u8 pad8c[0x150 - 0x8c]; RopeModel *model; } Owner_11492C;

/* fn_1_11492C */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_11492C *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_11492C *obj;
 u32 pad14, count, linkCount, pad20; Node_10E3B4 *nodes; Link_10E3B4 *links; } Work_11492C;

/* fn_1_11492C */
typedef struct {
    u8 active;
    u8 _pad01[0x33];
    f32 field34;
    u8 _pad38[4];
    f32 field3c;
    f32 field40;
} Fn1154D0Entry;

/* fn_1_11492C */
typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Fn1154D0Entry *entries;
} Fn1154D0Object;

/* fn_1_115560 */
typedef struct Particle_115560 {
u8 flags; u8 pad1; u8 count; u8 pad3; u16 links[6];
Sig_fn_1_1286F4_Vec3f pos, old, rest, vel; u32 tail;
} Particle_115560;

/* fn_1_115560 */
typedef struct {u8 pad[8]; u8 *bones;} BoneSet;

/* fn_1_115560 */
typedef struct {u8 pad[0x150]; BoneSet *set;} Model_115560;

/* fn_1_115560 */
typedef struct {u8 pad[8]; u32 index; Model_115560 *model; void *mesh; u32 pad14; u32 count; u8 pad1c[8]; Particle_115560 *particles;} Rope_115560;

/* fn_1_115B58 */
typedef struct { f32 x, y, z, w; } Quat_115B58;

/* fn_1_115B58 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_115B58 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_115B58 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_115B58 *obj;
 u32 pad14, count, linkCount, pad20; Node_10E3B4 *nodes; } Work_115B58;

/* fn_1_115B58 */
typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_115BE8_AccessoryData;

/* fn_1_115B58 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    fn_1_115BE8_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} fn_1_115BE8_AccessoryObject;

/* fn_1_11677C */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11677C {
    u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11677C */
struct Sig_fn_1_129D9C_fn_1_129D9C_vec { f32 unk_0, unk_4, unk_8; };

/* fn_1_11677C */
struct fn_1_11677C_Copy12 { u32 a[3]; };

/* fn_1_11677C */
struct fzgx_pool_w20 { u32 w[20]; };

/* fn_1_11677C */
struct fzgx_pool_w71 { u32 w[71]; };

/* fn_1_11677C */
struct fzgx_pool_w48 { u32 w[48]; };

/* fn_1_11677C */
struct fzgx_pool_w7 { u32 w[7]; };

/* fn_1_11677C */
struct fzgx_pool_w8 { u32 w[8]; };

/* fn_1_11677C */
struct fzgx_pool_w19 { u32 w[19]; };

/* fn_1_11677C */
struct fzgx_pool_w40 { u32 w[40]; };

/* fn_1_1171B8 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x17];
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Elem_1171B8;

/* fn_1_1171B8 */
typedef struct {
    u8 pad_0[8];
    s32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    u8 pad_1C[8];
    Elem_1171B8 *unk_24;
} Obj_1171B8;

/* fn_1_117424 */
typedef struct RopeModel_117424 {
    u8 pad_0[0x88];
    Vec3 mtx;
    u8 pad_94[0x18C - 0x94];
} RopeModel_117424;

/* fn_1_117424 */
typedef struct RopeModelList {
    u8 pad_0[0x8];
    RopeModel_117424 *models;
} RopeModelList;

/* fn_1_117424 */
typedef struct RopeOwner_117424 {
    u8 pad_0[0x150];
    RopeModelList *list;
} RopeOwner_117424;

/* fn_1_117424 */
typedef struct Rope_117424 {
    u8 flags;
    u8 pad_1[0x7];
    u32 kind;
    RopeOwner_117424 *owner;
    void *skin;
    u8 pad_14[0x4];
    u32 count;
    u8 pad_1C[0x8];
    RopeNode_1137E4 *nodes;
} Rope_117424;

/* fn_1_117424 */
typedef struct SkinMtx {
    Vec3 v;
    u8 pad_C[0x34];
} SkinMtx;

/* fn_1_1177C4 */
typedef struct HairVtx {
    Vec3 pos;
    u8 pad_C[0x35 - 0xC];
    u8 flags;
    u8 pad_36[0x40 - 0x36];
} HairVtx;

/* fn_1_1177C4 */
typedef struct HairVtxCount {
    u32 count;
} HairVtxCount;

/* fn_1_1177C4 */
typedef struct ModelEntry {
    void *model;
    char *name;
} ModelEntry;

/* fn_1_1177C4 */
typedef struct ModelList {
    u32 count;
    u8 pad_4[0x4];
    ModelEntry *entries;
} ModelList;

/* fn_1_1177C4 */
typedef struct RopeOwner_1177C4 {
    u8 pad_0[0x8C];
    u32 sel;
    u8 pad_90[0xE4 - 0x90];
    ModelList *lists[1];
} RopeOwner_1177C4;

/* fn_1_1177C4 */
typedef struct Rope_1177C4 {
    u8 flags;
    u8 pad_1[0x7];
    u32 kind;
    RopeOwner_1177C4 *owner;
    void *skin;
    u8 pad_14[0x4];
    u32 count;
    u32 linkCount;
    u32 count2;
    RopeNode_1137E4 *nodes;
    Link_1137E4 *links;
    RopeNode_1137E4 *nodes2;
} Rope_1177C4;

/* fn_1_117D5C */
typedef struct Rope_117D5C {
    u8 flags;
    u8 pad_1[0x7];
    u32 kind;
    RopeOwner_117424 *owner;
    void *skin;
    u8 pad_14[0x4];
    u32 count;
    u32 linkCount;
    u32 count2;
    RopeNode_1137E4 *nodes;
    Link_1137E4 *links;
    RopeNode_1137E4 *nodes2;
} Rope_117D5C;

/* fn_1_1185B4 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x13];
    f32 unk_14;
    u8 pad_18[0x28];
    f32 unk_40;
} Elem1185B4;

/* fn_1_1185B4 */
typedef struct {
    u8 pad_0[8];
    s32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    u8 pad_1C[8];
    Elem1185B4 *unk_24;
} Obj1185B4;

/* fn_1_1185B4 */
typedef struct {
    u8 pad_0[0x48];
    f32 c_48; /* 0x048: 0.25 */
    u8 pad_4c[0x18];
    f32 c_64; /* 0x064: -1.0 */
    f32 c_68; /* 0x068: 0.0 */
    u8 pad_6c[0x4];
    f32 c_70; /* 0x070: 2.0 */
    f32 c_74; /* 0x074: 1.1920928955078125e-07 */
    u8 pad_78[0x68];
    f32 c_e0; /* 0x0e0: 0.75 */
} AccessoryPool1185B4;

/* fn_1_1188CC */
typedef struct Rope_1188CC {
    u8 flags;
    u8 pad_1[0x7];
    u32 kind;
    RopeOwner_117424 *owner;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *skin;
    u8 pad_14[0x4];
    u32 count;
    u8 pad_1C[0x8];
    RopeNode_1137E4 *nodes;
} Rope_1188CC;

/* fn_1_1188CC */
typedef struct {
    u8 pad_0[0x58];
    f64 d_scale;    /* 0x058: 0.0013611111376020642 */
    f32 f_scale;    /* 0x060: 0.0027222223579883575f */
    u8 pad_64[0x80];
    f32 neg_qtr;    /* 0x0E4: -0.25f */
    u8 pad_E8[0x308];
    f32 limit;      /* 0x3F0: 1.2f */
} AccessoryPool1188CC;

/* fn_1_118D90 */
struct fn_1_118D90_lbl_1_rodata_7AB8 {
    u8 pad_0[0x64];
    f32 unk_64;
    f32 unk_68;
    u8 pad_6C[0x3C];
    f32 unk_A8;
    u8 pad_AC[0x110];
    f32 unk_1BC;
};

/* fn_1_1192D0 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_1192D0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_1192D0 */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_11492C *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_1192D0 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_1192D0;

/* fn_1_11A158 */
typedef fn_1_10D2F0_Entry Entry_11A158;

/* fn_1_11A774 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11A774 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11A774 */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_11492C *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_11A774 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_11A774;

/* fn_1_11B4E4 */
typedef struct Node11B4E4 {
    u8 unk_0;
    u8 pad_1[0xF];
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Node11B4E4;

/* fn_1_11B4E4 */
typedef struct Link11B4E4 {
    Node11B4E4 *unk_0;
    Node11B4E4 *unk_4;
    f32 unk_8;
} Link11B4E4;

/* fn_1_11B4E4 */
typedef struct Obj11B4E4 {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[4];
    Node11B4E4 *unk_24;
    Link11B4E4 *unk_28;
} Obj11B4E4;

/* fn_1_11B958 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11B958 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11B958 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_11B958 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_11B958;

/* fn_1_11BFCC */
typedef struct Node11BFCC {
    u8 flag;
    u8 pad_1[0xF];
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Node11BFCC;

/* fn_1_11BFCC */
typedef struct Edge11BFCC {
    Node11BFCC *a;
    Node11BFCC *b;
    f32 len;
} Edge11BFCC;

/* fn_1_11BFCC */
typedef struct Obj11BFCC {
    u8 pad_0[0x18];
    u32 count;
    u32 edgeCount;
    u8 pad_20[4];
    Node11BFCC *nodes;
    Edge11BFCC *edges;
} Obj11BFCC;

/* fn_1_11BFCC */
typedef struct Row11BFCC {
    Node11BFCC n[8];
} Row11BFCC;

/* fn_1_11C440 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11C440 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11C440 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_11C440 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_11C440;

/* fn_1_11CAB4 */
typedef struct {
    u8 flags;
    u8 pad1[0xF];
    Vec3 pos;
    u8 pad1C[0x24];
    f32 weight;
} Node_11CAB4;

/* fn_1_11CAB4 */
typedef struct {
    u8 pad0[0x18];
    u32 count;
    u8 pad1C[0x8];
    Node_11CAB4 *nodes;
} NodeSet;

/* fn_1_11CD3C */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11CD3C {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11CD3C */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_11CD3C *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_11CD3C;

/* fn_1_11D1FC */
typedef struct Node_11D1FC {
    u8 flags;
    u8 type;
    u8 count;
    u8 pad_3;
    u16 idx[4];
    u8 pad_C[4];
    Vec3 pos;
    Vec3 p1C;
    Vec3 p28;
    Vec3 c34;
    f32 weight;
} Node_11D1FC;

/* fn_1_11D1FC */
typedef struct {
    Node_11D1FC *a;
    Node_11D1FC *b;
    f32 length;
} Link_11D1FC;

/* fn_1_11D1FC */
typedef struct {
    u8 pad_0[0x18];
    u32 groupCount;
    u32 linkCount;
    u32 nodeCount;
    Node_11D1FC *groups;
    Link_11D1FC *links;
    Node_11D1FC *nodes;
} Obj_11D1FC;

/* fn_1_11DE2C */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11DE2C {
    u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11DE2C */
typedef struct Node_11DE2C {
    u8 flags, kind, count, pad3;
    u16 links[6];
    Vec3 pos, prev, local, vel;
    f32 weight;
} Node_11DE2C;

/* fn_1_11DE2C */
typedef struct { Node_11DE2C *a, *b; f32 length; } Link_11DE2C;

/* fn_1_11DE2C */
typedef struct {
    u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
    struct Sig_fn_80077B14_fn_80077B14_Arg0_11DE2C *obj;
    u32 pad14, count, linkCount, count2;
    Node_11DE2C *nodes; Link_11DE2C *links; Node_11DE2C *nodes2;
} Work_11DE2C;

/* fn_1_11F250 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_11F250 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_11F250 */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_11492C *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_11F250 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_11F250;

/* fn_1_120804 */
typedef struct AccModel {
    u8 pad[8];
    u8 *base;
    u8 pad0C[0x40];
    f32 unk4C;
} AccModel;

/* fn_1_120804 */
typedef struct AccOwner {
    u8 pad[0x8C];
    s32 kind;
    u8 pad90[0x148 - 0x90];
    u8 unk148[8];
    AccModel *model;
} AccOwner;

/* fn_1_120804 */
typedef struct AccWork {
    u8 flags;
    u8 pad[7];
    u32 index;
    AccOwner *owner;
    void *obj;
    s32 timer;
    u32 count;
    u32 linkCount;
    u32 pad20;
    Node_10E3B4 *nodes;
    Link_10E3B4 *links;
} AccWork;

/* fn_1_122348 */
typedef struct {
    u8 flags;
    u8 pad_1[0xF];
    f32 unk10;
    u8 pad_14[4];
    f32 unk18;
    u8 pad_1C[0x24];
    f32 unk40;
} Group122348;

/* fn_1_122348 */
typedef struct {
    u8 pad_0[0x8C];
    s32 mode;
} Owner122348;

/* fn_1_122348 */
typedef struct {
    u8 pad_0[0xC];
    Owner122348 *owner;
    u8 pad_10[8];
    u32 count;
    u8 pad_1C[8];
    Group122348 *groups;
} Obj122348;

/* fn_1_12277C */
typedef union fn_1_12277C_Vec {
    u32 w[3];
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
} fn_1_12277C_Vec;

/* fn_1_12277C */
typedef struct fn_1_12277C_Part {
    s8 unk_0;
    u8 pad_1;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4[6];
    fn_1_12277C_Vec unk_10;
    fn_1_12277C_Vec unk_1C;
    fn_1_12277C_Vec unk_28;
    fn_1_12277C_Vec unk_34;
    u32 unk_40;
} fn_1_12277C_Part;

/* fn_1_12277C */
typedef struct fn_1_12277C_Object {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_108EEC_L0 *unk_C;
    void *unk_10;
    u32 pad_14;
    u32 unk_18;
    u8 pad_1C[8];
    fn_1_12277C_Part *unk_24;
} fn_1_12277C_Object;

/* fn_1_123050 */
typedef struct SimNode {
    u8 flags, pad1, count, pad3;
    u16 links[6];
    Vec3 pos, prev, local, vel;
    f32 mass;
} SimNode;

/* fn_1_123050 */
typedef struct SimLink { SimNode *a, *b; f32 length; } SimLink;

/* fn_1_123050 */
typedef struct SimBones { u8 pad0[8]; u8 *data; } SimBones;

/* fn_1_123050 */
typedef struct SimModel {
    u8 pad0[0x8c]; s32 kind;
    u8 pad90[0xc0]; SimBones *bones;
} SimModel;

/* fn_1_123050 */
typedef struct SimRope {
    u8 flags; u8 pad1[7]; u32 id;
    SimModel *model; void *mesh;
    s32 timer; u32 count, link_count, pad20;
    SimNode *nodes; SimLink *links;
} SimRope;

/* fn_1_1244F0 */
typedef struct {
    u8 flags;
    u8 pad_1[0xF];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad_1C[0x24];
    f32 f40;
} Group1244F0;

/* fn_1_1244F0 */
typedef struct {
    Group1244F0 *a;
    Group1244F0 *b;
    f32 distance;
} Link1244F0;

/* fn_1_1244F0 */
typedef struct {
    u8 pad_0[0x18];
    u32 groupCount;
    u32 linkCount;
    u8 pad_20[4];
    Group1244F0 *groups;
    Link1244F0 *links;
} Obj1244F0;

/* fn_1_124AD4 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_124AD4 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_124AD4 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_124AD4 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_124AD4;

/* fn_1_1250D0 */
typedef fn_1_10D2F0_Entry Entry_1250D0;

/* fn_1_1256EC */
struct Sig_fn_80077B14_fn_80077B14_Arg0_1256EC {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_1256EC */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_1256EC *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_1256EC;

/* fn_1_125CE8 */
typedef struct {
    u8 active;
    u8 pad_1[0x0f];
    f32 value;
    u8 pad_14[0x2c];
    f32 result;
} fn_1_125CE8_AccessoryEntry;

/* fn_1_125CE8 */
typedef struct {
    u8 pad_0[0x18];
    u32 count;
    u8 pad_1c[0x08];
    fn_1_125CE8_AccessoryEntry *entries;
} fn_1_125CE8_AccessoryData;

/* fn_1_125DF0 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_125DF0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_125DF0 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_125DF0 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_125DF0;

/* fn_1_1262A4 */
typedef struct ClothNode1262A4 {
    u8 flags;
    u8 pad_1[0xF];
    f32 height;  /* 0x10 */
    f32 order;   /* 0x14 */
    f32 side;    /* 0x18 */
    u8 pad_1C[0x24];
    f32 weight;  /* 0x40 */
} ClothNode1262A4;

/* fn_1_1262A4 */
typedef struct ClothLink1262A4 {
    ClothNode1262A4 *a;
    ClothNode1262A4 *b;
    f32 len;
} ClothLink1262A4;

/* fn_1_1262A4 */
typedef struct ClothObj1262A4 {
    u8 pad_0[0x18];
    u32 nodeCount;
    u32 linkCount;
    u8 pad_20[4];
    ClothNode1262A4 *nodes;
    ClothLink1262A4 *links;
} ClothObj1262A4;

/* fn_1_126774 */
struct Sig_fn_80077B14_fn_80077B14_Arg0_126774 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_126774 */
typedef struct { u8 flags; u8 pad[7]; u32 index; RopeOwner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_126774 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_126774;

/* fn_1_126DE8 */
typedef struct {
 u8 flags, unk_1, count, pad_3;
 u16 idx[4]; u8 pad_C[4];
 Sig_fn_1_1286F4_Vec3f p10,p1C,p28;
 Word3_10846C c34;
 f32 weight;
} Sig_fn_1_10846C_Group10846C_126DE8;

/* fn_1_126DE8 */
typedef struct {
 u8 pad_0[12]; void *config; void *model;
 u8 pad_14[4]; u32 groupCount,unk_1C;
 u8 pad_20[4]; Sig_fn_1_10846C_Group10846C_126DE8 *groups;
 void *unk_28; u8 pad_2C[4]; void *srcModel; u8 pad_34[0x30];
 Sig_fn_1_1286F4_Vec3f *positions;
} Sig_fn_1_10846C_Obj10846C_126DE8;

/* fn_1_126DE8 */
typedef Sig_fn_1_10846C_Group10846C_126DE8 Group;

/* fn_1_126DE8 */
typedef struct { Group *a,*b; f32 distance; } Edge;

/* fn_1_12744C */
struct Sig_fn_80077B14_fn_80077B14_Arg0_12744C {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

/* fn_1_12744C */
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner_11492C *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0_12744C *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work_12744C;

/* fn_1_127FB8 */
typedef struct {
    u8 active;
    u8 _pad01[0x3f];
    f32 value;
} Fn127FB8Entry;

/* fn_1_127FB8 */
typedef struct {
    u8 _pad00[0x18];
    u32 count;
    u8 _pad1c[8];
    Fn127FB8Entry *entries;
} Fn127FB8Object;

/* fn_1_127FB8 */
typedef struct {
    u8 pad_0[0x88];
    s32 unk_88;
    u8 pad_8C[0xBC];
    u8 unk_148[8];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_128038_AccessoryData;

/* fn_1_127FB8 */
typedef struct {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_128038_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} fn_1_128038_AccessoryObject;

/* fn_1_128884 */
typedef struct {
    u32 word_0;
    u32 word_4;
    u32 word_8;
    u16 half_c;
    u8 byte_e;
} LookupTable;

/* fn_1_128884 */
typedef struct {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 pad_5[3];
    u8 field_8;
    u8 field_9;
    u16 field_a;
    u8 field_c[3];
    u8 field_f;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 pad_13;
    u16 field_14;
    u8 pad_16[2];
    u16 field_18;
} FnData;

/* fn_1_128884 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 unk_20;
} Obj_1_bss_89760_fn_1_128F10;

/* fn_1_128884 */
typedef struct lbl_1_bss_89770_t {
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} lbl_1_bss_89770_t;

/* fn_1_128884 */
typedef struct lbl_1_bss_89780_t {
    u8 unk_20;
    u8 pad_1[0x1f];
} lbl_1_bss_89780_t;

/* fn_1_12907C */
typedef struct {
    u8 r, g, b, a;
} Color_12907C;

/* fn_1_12907C */
typedef struct {
    u8 pad_0[0x104];
    u16 angle;   /* 0x104 */
    u8 pad_106[2];
    f32 height;  /* 0x108 */
} Car_12907C;

/* fn_1_12907C */
struct Obj_t {
 u32 unk_0; u8 pad_4[0x148]; u8 unk_14C[4]; u8 pad_150[0x325];
 s8 unk_475; u8 pad_476[0x26]; u32 unk_49C;
};

/* fn_1_12907C */
struct Ref { u8 pad_0[0x10]; u8 unk_10; u8 pad_11[7]; };

/* fn_1_12907C */
struct E30 { u8 pad[0x30]; };

/* fn_1_12907C */
struct Pool_12907C {
 f32 unk_0; u8 pad_4[0xC]; f32 unk_10; u8 pad_14[0x3C]; f32 unk_50; u8 pad_54[0x24];
 u32 unk_78; u32 unk_7C; u32 unk_80; u32 unk_84; u32 unk_88; u32 unk_8C; s32 unk_90; u32 unk_94;
 u8 pad_98[0x8]; u32 unk_A0; u32 unk_A4; s32 unk_A8; f32 unk_AC; f32 unk_B0; u8 pad_B4[0x4];
 f64 unk_B8; f32 unk_C0; f32 unk_C4; f32 unk_C8; f32 unk_CC; f32 unk_D0; f32 unk_D4;
 f32 unk_D8; f32 unk_DC; f32 unk_E0;
};

/* fn_1_12907C */
struct fn_1_129D9C_chain {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0xC];
    u32 unk_48;
};

/* fn_1_12907C */
typedef struct { f32 value0, value1, value2; } Sig_fn_8006F78C_Fn8006F78CData_12907C;

/* fn_1_12907C */
typedef struct {
    u8 unk_00[8];
    u8 unk_08[0x30];
    f32 unk_38;
    char unk_3C[1];
} DisplayData;

extern void C_MTXOrtho(Sig_fn_80015EE8_Fn80015EE8Out *, f32, f32, f32, f32, f32, f32);
extern void OSCancelThread(void *arg0);
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSPanic(const char *, int, const char *, ...);
extern f64 __fabs(f64);
extern void _restgpr_27(void);
extern void _savegpr_27(void);
extern s32 camera_get_state(void);
extern f64 fabs(f64);
extern void fn_1_103AA8(void);
extern void fn_1_103AD4(void);
extern void fn_1_103B00();
extern void fn_1_103FCC(void);
extern void fn_1_105744(void);
extern void fn_1_105768(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern void fn_1_106DB4(void);
extern u32 fn_1_1071E8(u8 *, u32, void *, void *, void *);
extern s32 fn_1_14D670(void);
extern u8 *fn_1_14F04(void);
extern void fn_1_3EF14(void *);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_3F7E0(void);
extern s32 fn_1_40B20(void);
extern void *fn_1_45D0(void *manager, int type, void *data, int code);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern void fn_1_469BC(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern s32 fn_1_485A8(s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(void *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void (*)(void));
extern void fn_1_4A0D8(const char *);
extern s32 fn_1_4C10(void);
extern void fn_1_52070(u32);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern void *fn_1_54448(s32 arg0);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void *fn_1_548AC(u32);
extern s32 fn_1_54E34(void *, f32);
extern void *fn_1_55210(void *);
extern void fn_1_556B8(void *);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u32 fn_1_58C4(void);
extern u32 fn_1_5910(void);
extern s32 fn_1_6B48(u32 index);
extern s32 fn_1_6EC0(u8);
extern s8 fn_1_84124(Fn183D28Car *, s8, s8, u8 *);
extern s8 fn_1_84408(CarTestCar *);
extern s8 fn_1_84644(Fn183D28Body *);
extern void *fn_1_86254(s32);
extern Car_12907C *fn_1_8627C(s32);
extern void fn_1_862A8(s32, struct Vec3 *);
extern void fn_1_862D4(s32, Vec3 *);
extern u32 fn_1_864E8(s32);
extern s8 fn_1_86624(void);
extern s32 fn_1_86678(s32 arg);
extern u32 fn_1_86810(s32);
extern f32 fn_1_8CAF4(s16, u32);
extern void fn_1_8E084(CarTestCar *, u32 *, s32);
extern const char *fn_1_950E8(void *);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_9E5B8(void *);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern f32 fn_1_A71AC(void);
extern f32 fn_1_A71BC(void);
extern void fn_1_A8EB0(int, int);
extern u8 fn_1_D66BC(void *, void *);
extern u32 fn_1_EB0B0(void);
extern u8 *fn_1_F1C54(u32);
extern s32 fn_1_F1D60(void);
extern s32 fn_1_F2F34(void);
extern void fn_1_F7870(void *);
extern void fn_80008BA8(void *dst, void *src, int size);
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_8006E250(void *, void *);
extern void fn_8006E978(void *, void *, void *);
extern void fn_8006F78C(void *, void *, f32);
extern void fn_80072558(void);
extern void fn_800737E4(void *, s32);
extern void fn_80074918(u8, s32, u8);
extern void *fn_80077B14(void *);
extern void *fn_80077B64(void *);
extern Obj_1_bss_6D620 lbl_1_bss_6D620;
extern u32 lbl_1_bss_6D7E8;
extern u8 lbl_1_bss_6D7F0;
extern Obj_1_bss_6D7F4 lbl_1_bss_6D7F4;
extern struct E30 lbl_1_bss_7CA58[168];
extern u32 lbl_1_bss_85288[2];
extern u8 lbl_1_bss_86EC4;
extern u16 lbl_1_bss_86ECC;
extern u8 lbl_1_bss_89780[32];
extern u32 lbl_1_bss_897A4;
extern u32 lbl_1_bss_897A8;
extern u32 lbl_1_data_1E5C0[13];
extern u8 lbl_1_data_1EF5C[0x80];
extern u32 lbl_1_data_1EFDC;
extern u32 lbl_1_data_1EFE4;
extern u32 lbl_1_data_1F1D8;
extern u8 lbl_1_data_1F4FC[0xA4];
extern u8 lbl_1_data_1F5A0[0xA4];
extern u32 lbl_1_data_1FFDC;
extern Obj_1_bss_89770_L lbl_1_data_1FFE0;
extern FontDrawPacket lbl_1_rodata_26F8;
extern f32 lbl_1_rodata_78E8[19];
extern f32 lbl_1_rodata_7934[11];
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D188(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006D668(void *);
extern f32 lbl_8006D6FC(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006D7B0(void);
extern void lbl_8006D9D8(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DD14(void *arg0, void *arg1);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DFE8(Vec3 *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1C0(void *, void *);
extern u32 lbl_801A63C0;
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern struct fn_1_129D9C_system *lbl_801A6D00;
extern void mathutil_mtxA_from_quat(void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern int sprintf(char *, const char *, ...);
extern int strcmp(void *, void *);
extern void strcpy(void *, void *);
extern char *strstr(const char *, const char *);

void fn_1_107900(void);
void fn_1_107930(fn_1_107930_Object *arg);
void fn_1_107C4C(void *arg);
void fn_1_107C74(BgOwner *owner);
void fn_1_107E90(Fn107E90Context *context);
void fn_1_107F2C(void *arg0);
void fn_1_107F50(void *arg0);
void fn_1_107F74(BgObj *obj, int flag);
void fn_1_108128(Fn108128Context *context, u32 stride);
void fn_1_10846C(Obj10846C *obj);
Sig_fn_1_108870_fn_1_108870_AccessoryEntry *fn_1_108870(void);
void fn_1_1088B8(void *arg);
void fn_1_108920(u32 accessory);
void fn_1_108A90(fn_1_108A90_Self *self, s32 idx, f32 radius, f32 cx, f32 cy, f32 cz);
void fn_1_108BD0(Fn1108BD0_Object *object, s32 joint_index, f32 margin, f32 x, f32 y, f32 z);
void fn_1_108EEC(fn_1_108EEC_Arg *arg0, s32 arg5, s32 arg6, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void fn_1_109114(fn_1_109114_AccessoryObject *self);
void fn_1_1091D4(u32 arg0);
void fn_1_10976C(RopeWork *arg0);
void fn_1_10A43C(AccessoryObject *self);
void fn_1_10A6A0(fn_1_10A6A0_Object *self);
void fn_1_10A8D0(Graph_10A8D0 *g);
void fn_1_10AD18(Work *arg0);
void fn_1_10B344(Doc *obj);
void fn_1_10B5A8(fn_1_10B5A8_Object *self);
void fn_1_10B7D8(void *accessory);
void fn_1_10B800(struct Accessory *acc);
void fn_1_10BA00(Obj10BA00 *obj);
void fn_1_10BE3C(Work_10BE3C *arg0);
void fn_1_10C4E4(Graph10C4E4 *g);
void fn_1_10C7B4(fn_1_10C7B4_AccessoryObject *self);
void fn_1_10C9B0(Fn10C9B0List *list);
void fn_1_10CC38(Rope *arg0);
void fn_1_10D2F0(Ctx *arg0);
void fn_1_10D7D4(Work_10D7D4 *arg0);
void fn_1_10DDE4(Rope_10DDE4 *rope);
void fn_1_10E3B4(Work_10E3B4 *arg0);
void fn_1_110008(fn_1_10D2F0_Obj *obj);
void fn_1_110478(Work_110478 *arg0);
void fn_1_111510(fn_1_10D2F0_Obj *obj);
void fn_1_111980(Work_111980 *arg0);
void fn_1_112F40(fn_1_10D2F0_Obj *obj);
void fn_1_1132E4(Work_1132E4 *arg0);
void fn_1_1137E4(Rope_1137E4 *rope);
void fn_1_113C58(AccessoryObjectLocal *arg0);
void fn_1_1145C8(Accessory1145C8 *obj);
void fn_1_11492C(Work_11492C *arg0);
void fn_1_1154D0(Fn1154D0Object *obj);
void fn_1_115560(Rope_115560 *arg0);
void fn_1_115B58(Fn1154D0Object *obj);
void fn_1_115BE8(Work_115B58 *arg0);
void fn_1_1166EC(Fn1154D0Object *obj);
void fn_1_11677C(void *arg0);
void fn_1_1171B8(Obj_1171B8 *obj);
void fn_1_117424(Rope_117424 *rope);
void fn_1_1177C4(Rope_1177C4 *rope);
void fn_1_117D5C(Rope_117D5C *rope);
void fn_1_1185B4(Obj1185B4 *obj);
void fn_1_1188CC(Rope_1188CC *rope);
void fn_1_118D90(u32 arg0, f32 arg1);
void fn_1_1192D0(Work_1192D0 *arg0);
void fn_1_11A158(fn_1_10D2F0_Obj *obj);
void fn_1_11A774(Work_11A774 *arg0);
void fn_1_11B4E4(Obj11B4E4 *obj);
void fn_1_11B958(Work_11B958 *arg0);
void fn_1_11BFCC(Obj11BFCC *obj);
void fn_1_11C440(Work_11C440 *arg0);
void fn_1_11CAB4(NodeSet *set);
void fn_1_11CD3C(Work_11CD3C *arg0);
void fn_1_11D1FC(Obj_11D1FC *obj);
void fn_1_11DE2C(Work_11DE2C *arg0);
void fn_1_11ED0C(fn_1_10D2F0_Obj *obj);
void fn_1_11F250(Work_11F250 *arg0);
void fn_1_1201E4(Rope_10DDE4 *rope);
void fn_1_120804(AccWork *arg0);
void fn_1_122348(Obj122348 *obj);
void fn_1_12277C(fn_1_12277C_Object *self);
void fn_1_12295C(Rope_10DDE4 *rope);
void fn_1_123050(SimRope *r);
void fn_1_1244F0(Obj1244F0 *obj);
void fn_1_124AD4(Work_124AD4 *arg0);
void fn_1_1250D0(fn_1_10D2F0_Obj *obj);
void fn_1_1256EC(Work_1256EC *arg0);
void fn_1_125CE8(fn_1_125CE8_AccessoryData *data);
void fn_1_125DF0(Work_125DF0 *arg0);
void fn_1_1262A4(ClothObj1262A4 *obj);
void fn_1_126774(Work_126774 *arg0);
void fn_1_126DE8(Sig_fn_1_10846C_Obj10846C_126DE8 *obj);
void fn_1_12744C(Work_12744C *arg0);
void fn_1_127FB8(Fn127FB8Object *obj);
void fn_1_128038(fn_1_128038_AccessoryObject *self);
void fn_1_1286F4(Vec3 *out);
void fn_1_128884(void *arg0, void *arg1, int type);
f32 fn_1_1289BC(const Point1024C4 *a, const Point1024C4 *b);
f32 fn_1_1289F0(Vec3 *a, Vec3 *b, Vec3 *c);
f32 fn_1_128AAC(s32 exponent, f32 value);
s32 fn_1_128B00(s16 value);
void fn_1_128B60(u8 *a0, u8 *a1, u8 *a2, u8 *a3, u8 *a4, u8 *a5, u8 *a6, u8 *a7, u8 *a8, u8 *a9);
u8 fn_1_128DD8(u8 value);
u8 fn_1_128E10(u8 value);
void fn_1_128E8C(u32 unused, FnData *data);
void fn_1_128F10(void);
void fn_1_128F54(void);
void fn_1_12907C(void);
void fn_1_12999C(void);
void fn_1_129D9C(void *arg0, struct Vec3 *arg1, u8 *arg2, void *arg4, u8 arg5, u8 arg6, u8 arg7, f32 arg3);
void fn_1_12A080(void);
void fn_1_12A0E0(DisplayData *arg0);
s8 fn_1_12A24C(s8 arg);

/* TU A (retail accessory.c 107900..128DD8): .data 3F510..405C0 and .bss 86ED0..8975C. The string literals used by the
   functions (4050C "_vtx" .. 405B8 "WIN_3RD", "accessory.c" at 40530) follow these objects in first-use order. */
typedef struct {
    Vec3 pos;
    Vec3 dir;
    u8 color0[4];
    u8 color1[4];
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
} AccessoryLight;

typedef void (*AccessoryFunc)();

/* .data 3F510 / 3F544: the two light records passed to fn_1_F7870 */
static AccessoryLight lbl_1_data_3F510 = {{0.0f, 0.0f, 0.0f}, {2.0f, -1.0f, -1.5f}, {0x87, 0x87, 0x87, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0.0f, 0.0f, 0.95f, 0.0f, 90.0f};
static AccessoryLight lbl_1_data_3F544 = {{0.0f, 0.0f, 0.0f}, {2.0f, -1.0f, 1.5f}, {0x87, 0x87, 0x87, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0.0f, 0.0f, 0.95f, 0.0f, 90.0f};

/* .data 3FCAC: model part names (the strings 3F578..3FC98 are the literals of this initializer) */
static char *lbl_1_data_3FCAC[98] = {
    "GORDON_MOMO_R_vtx",
    "GORDON_MOMO_L_vtx",
    "GORDON_ERI_O_vtx",
    "GORDON_ERI_U_vtx",
    "FALCON_ERI_O_vtx",
    "FALCON_ERI_U_vtx",
    "FALCON_FRONT_O_vtx",
    "FALCON_FRONT_U_vtx",
    "FALCON_ACCESSORY_vtx",
    "FALCON_KATAATE_vtx",
    "JAMES_HAIR_A_vtx",
    "JAMES_HAIR_B_vtx",
    "JAMES_HAIR_C_vtx",
    "JAMES_JACKET_vtx",
    "JAMES_ACCESSORY_vtx",
    "ARROW_MANT_vtx",
    "SHADOW_MANT_vtx",
    "BOSS_MANT_vtx",
    "BOSS_ERI_vtx",
    "GUSTER_JACKET_O_vtx",
    "GUSTER_ERI_O_vtx",
    "GUSTER_ERI_U_vtx",
    "STEWART_SCARF_vtx",
    "GOMA_SCARF_vtx",
    "GOMA_KOSHI_R_vtx",
    "GOMA_KOSHI_L_vtx",
    "SHIO_SCARF_vtx",
    "SHIO_KOSI_R_vtx",
    "SHIO_KOSI_L_vtx",
    "BLOOD_SCARF_vtx",
    "BLOOD_ERI_O_vtx",
    "BLOOD_ERI_U_vtx",
    "BLOOD_KATAATE_2_vtx",
    "JODY_HAIR_A_U_vtx",
    "JODY_HAIR_A_B_vtx",
    "JODY_HAIR_B_U_vtx",
    "JODY_HAIR_B_B_vtx",
    "JODY_HAIR_C_U_vtx",
    "JODY_HAIR_C_B_vtx",
    "JODY_HAIR_D_U_vtx",
    "JODY_HAIR_D_B_vtx",
    "JODY_HAIR_E_U_vtx",
    "JODY_HAIR_E_B_vtx",
    "JODY_HAIR_F_U_vtx",
    "JODY_HAIR_F_B_vtx",
    "JODY_HAIR_G_vtx",
    "JODY_HAIR_H_vtx",
    "JODY_HAIR_I_vtx",
    "JODY_KATAATE_R_vtx",
    "JODY_KATAATE_L_vtx",
    "KATE_EARRING_R_vtx",
    "KATE_EARRING_L_vtx",
    "JACK_HAIR_A_L_vtx",
    "JACK_HAIR_A_R_vtx",
    "JACK_HAIR_B_L_vtx",
    "JACK_HAIR_B_R_vtx",
    "JACK_HAIR_C_L_vtx",
    "JACK_HAIR_C_R_vtx",
    "JACK__HAIR_MID_vtx",
    "EAD_HIGE_R_vtx",
    "EAD_HIGE_L_vtx",
    "NEELSEN_ERI_O_vtx",
    "NEELSEN_ERI_U_vtx",
    "NEELSEN_MOMO_R_vtx",
    "NEELSEN_MOMO_L_vtx",
    "NEELSEN_CAMERA_vtx",
    "NEELSEN_JACKET_vtx",
    "GOROH_ERI_O_vtx",
    "GOROH_ERI_U_vtx",
    "GOROH_BELT_R_vtx",
    "GOROH_BELT_L_vtx",
    "GOROH_JACKET_vtx",
    "BABA_JACKET_vtx",
    "MRS_HAIR_R_vtx",
    "MRS_HAIR_MID_vtx",
    "MRS_HAIR_L_vtx",
    "DON_MANT_vtx",
    "SHERLOK_MANT_U_vtx",
    "SHERLOK_MANT_O_vtx",
    "SPADE_MANT_vtx",
    "DAI_SCARF_vtx",
    "SAN_SCARF_vtx",
    "GEN_SCARF_vtx",
    "PRISIA_SCARF_vtx",
    "PLISIA_MOMO_R_vtx",
    "PLISIA_MOMO_L_vtx",
    "PLISIA_HAIR_R_vtx",
    "PLISIA_HAIR_L_vtx",
    "DAIGOROH_JACKET_vtx",
    "DAIGOROH_BELT_R_vtx",
    "DAIGOROH_BELT_L_vtx",
    "DIGIBOY_MOMO_R_vtx",
    "DIGIBOY_MOMO_L_vtx",
    "LILY_JACKET_vtx",
    "LILY_ERI_vtx",
    "PJ_SUNE_R_vtx",
    "PJ_SUNE_L_vtx",
    "ROGER_JACKET_vtx",
};

/* .data 3FE34: per part value (kind) */
static u32 lbl_1_data_3FE34[98] = {
    15, 15, 15, 15, 6, 6, 6, 6, 6, 6, 9, 9, 9, 9, 9, 19,
    29, 30, 30, 16, 16, 16, 2, 41, 41, 41, 21, 21, 21, 24, 24, 24,
    24, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 11, 11, 13, 13, 13, 13, 13, 13, 13, 8, 8, 22, 22, 22,
    22, 22, 22, 4, 4, 4, 4, 4, 3, 20, 20, 20, 31, 40, 40, 34,
    33, 42, 43, 36, 36, 36, 36, 36, 35, 35, 35, 32, 32, 37, 37, 38,
    38, 27,
};

/* .data 3FFBC: per part bone index (records of 0x18C bytes) */
static u32 lbl_1_data_3FFBC[98] = {
    18, 23, 1, 1, 1, 1, 1, 1, 16, 11, 5, 5, 5, 1, 16, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 16, 16, 1, 16, 16, 1, 1, 1,
    11, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    11, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 18,
    23, 1, 1, 1, 1, 16, 16, 1, 1, 5, 5, 5, 1, 1, 1, 16,
    1, 1, 1, 1, 18, 23, 5, 5, 1, 16, 16, 18, 23, 1, 1, 19,
    24, 1,
};

/* .data 40144: per part draw order */
static u8 lbl_1_data_40144[98] = {
    0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 0,
    0, 0, 1, 0, 1, 2, 0, 0, 1, 2, 0, 1, 2, 0, 1, 2,
    3, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 0, 1, 0, 1, 2, 3, 4, 5, 6, 0, 1, 0, 1, 2,
    3, 4, 5, 0, 1, 2, 3, 4, 0, 0, 1, 2, 0, 0, 1, 0,
    0, 0, 0, 0, 1, 2, 3, 4, 2, 3, 4, 0, 1, 0, 1, 0,
    1, 0,
};

/* .data 401A8: per part update function */
static AccessoryFunc lbl_1_data_401A8[98] = {
    (AccessoryFunc)fn_1_11BFCC, (AccessoryFunc)fn_1_11BFCC, (AccessoryFunc)fn_1_1091D4, (AccessoryFunc)fn_1_10A43C,
    (AccessoryFunc)fn_1_10A8D0, (AccessoryFunc)fn_1_10B344, (AccessoryFunc)fn_1_10BA00, (AccessoryFunc)fn_1_10C4E4,
    (AccessoryFunc)fn_1_10B7D8, (AccessoryFunc)fn_1_127FB8, (AccessoryFunc)fn_1_10C9B0, (AccessoryFunc)fn_1_10C9B0,
    (AccessoryFunc)fn_1_10C9B0, (AccessoryFunc)fn_1_10D2F0, (AccessoryFunc)fn_1_10B7D8, (AccessoryFunc)fn_1_10DDE4,
    (AccessoryFunc)fn_1_110008, (AccessoryFunc)fn_1_111510, (AccessoryFunc)fn_1_112F40, (AccessoryFunc)fn_1_1137E4,
    (AccessoryFunc)fn_1_10A8D0, (AccessoryFunc)fn_1_10B344, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1145C8,
    (AccessoryFunc)fn_1_118D90, (AccessoryFunc)fn_1_118D90, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_118D90,
    (AccessoryFunc)fn_1_118D90, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_10A8D0, (AccessoryFunc)fn_1_10B344,
    (AccessoryFunc)fn_1_127FB8, (AccessoryFunc)fn_1_115B58, (AccessoryFunc)fn_1_1166EC, (AccessoryFunc)fn_1_115B58,
    (AccessoryFunc)fn_1_1166EC, (AccessoryFunc)fn_1_115B58, (AccessoryFunc)fn_1_1166EC, (AccessoryFunc)fn_1_115B58,
    (AccessoryFunc)fn_1_1166EC, (AccessoryFunc)fn_1_115B58, (AccessoryFunc)fn_1_1166EC, (AccessoryFunc)fn_1_115B58,
    (AccessoryFunc)fn_1_1166EC, (AccessoryFunc)fn_1_115B58, (AccessoryFunc)fn_1_115B58, (AccessoryFunc)fn_1_115B58,
    (AccessoryFunc)fn_1_127FB8, (AccessoryFunc)fn_1_127FB8, (AccessoryFunc)fn_1_1154D0, (AccessoryFunc)fn_1_1154D0,
    (AccessoryFunc)fn_1_1171B8, (AccessoryFunc)fn_1_1171B8, (AccessoryFunc)fn_1_1171B8, (AccessoryFunc)fn_1_1171B8,
    (AccessoryFunc)fn_1_1171B8, (AccessoryFunc)fn_1_1171B8, (AccessoryFunc)fn_1_1171B8, (AccessoryFunc)fn_1_1185B4,
    (AccessoryFunc)fn_1_1185B4, (AccessoryFunc)fn_1_10A8D0, (AccessoryFunc)fn_1_10B344, (AccessoryFunc)fn_1_11B4E4,
    (AccessoryFunc)fn_1_11B4E4, (AccessoryFunc)fn_1_11D1FC, (AccessoryFunc)fn_1_126DE8, (AccessoryFunc)fn_1_10A8D0,
    (AccessoryFunc)fn_1_10B344, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_126DE8,
    (AccessoryFunc)fn_1_11A158, (AccessoryFunc)fn_1_11CAB4, (AccessoryFunc)fn_1_11CAB4, (AccessoryFunc)fn_1_11CAB4,
    (AccessoryFunc)fn_1_11ED0C, (AccessoryFunc)fn_1_1201E4, (AccessoryFunc)fn_1_122348, (AccessoryFunc)fn_1_12295C,
    (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1145C8,
    (AccessoryFunc)fn_1_11BFCC, (AccessoryFunc)fn_1_11BFCC, (AccessoryFunc)fn_1_1177C4, (AccessoryFunc)fn_1_1177C4,
    (AccessoryFunc)fn_1_1244F0, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1145C8, (AccessoryFunc)fn_1_1262A4,
    (AccessoryFunc)fn_1_1262A4, (AccessoryFunc)fn_1_1250D0, (AccessoryFunc)fn_1_125CE8, (AccessoryFunc)fn_1_11BFCC,
    (AccessoryFunc)fn_1_11BFCC, (AccessoryFunc)fn_1_126DE8,
};

/* .data 40330: per part draw function */
static AccessoryFunc lbl_1_data_40330[98] = {
    (AccessoryFunc)fn_1_11C440, (AccessoryFunc)fn_1_11C440, (AccessoryFunc)fn_1_10976C, (AccessoryFunc)fn_1_10A6A0,
    (AccessoryFunc)fn_1_10AD18, (AccessoryFunc)fn_1_10B5A8, (AccessoryFunc)fn_1_10BE3C, (AccessoryFunc)fn_1_10C7B4,
    (AccessoryFunc)fn_1_10B800, (AccessoryFunc)fn_1_128038, (AccessoryFunc)fn_1_10CC38, (AccessoryFunc)fn_1_10CC38,
    (AccessoryFunc)fn_1_10CC38, (AccessoryFunc)fn_1_10D7D4, (AccessoryFunc)fn_1_10B800, (AccessoryFunc)fn_1_10E3B4,
    (AccessoryFunc)fn_1_110478, (AccessoryFunc)fn_1_111980, (AccessoryFunc)fn_1_1132E4, (AccessoryFunc)fn_1_113C58,
    (AccessoryFunc)fn_1_10AD18, (AccessoryFunc)fn_1_10B5A8, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_11492C,
    (AccessoryFunc)fn_1_1192D0, (AccessoryFunc)fn_1_1192D0, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_1192D0,
    (AccessoryFunc)fn_1_1192D0, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_10AD18, (AccessoryFunc)fn_1_10B5A8,
    (AccessoryFunc)fn_1_128038, (AccessoryFunc)fn_1_115BE8, (AccessoryFunc)fn_1_11677C, (AccessoryFunc)fn_1_115BE8,
    (AccessoryFunc)fn_1_11677C, (AccessoryFunc)fn_1_115BE8, (AccessoryFunc)fn_1_11677C, (AccessoryFunc)fn_1_115BE8,
    (AccessoryFunc)fn_1_11677C, (AccessoryFunc)fn_1_115BE8, (AccessoryFunc)fn_1_11677C, (AccessoryFunc)fn_1_115BE8,
    (AccessoryFunc)fn_1_11677C, (AccessoryFunc)fn_1_115BE8, (AccessoryFunc)fn_1_115BE8, (AccessoryFunc)fn_1_115BE8,
    (AccessoryFunc)fn_1_128038, (AccessoryFunc)fn_1_128038, (AccessoryFunc)fn_1_115560, (AccessoryFunc)fn_1_115560,
    (AccessoryFunc)fn_1_117424, (AccessoryFunc)fn_1_117424, (AccessoryFunc)fn_1_117424, (AccessoryFunc)fn_1_117424,
    (AccessoryFunc)fn_1_117424, (AccessoryFunc)fn_1_117424, (AccessoryFunc)fn_1_117424, (AccessoryFunc)fn_1_1188CC,
    (AccessoryFunc)fn_1_1188CC, (AccessoryFunc)fn_1_10AD18, (AccessoryFunc)fn_1_10B5A8, (AccessoryFunc)fn_1_11B958,
    (AccessoryFunc)fn_1_11B958, (AccessoryFunc)fn_1_11DE2C, (AccessoryFunc)fn_1_12744C, (AccessoryFunc)fn_1_10AD18,
    (AccessoryFunc)fn_1_10B5A8, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_12744C,
    (AccessoryFunc)fn_1_11A774, (AccessoryFunc)fn_1_11CD3C, (AccessoryFunc)fn_1_11CD3C, (AccessoryFunc)fn_1_11CD3C,
    (AccessoryFunc)fn_1_11F250, (AccessoryFunc)fn_1_120804, (AccessoryFunc)fn_1_12277C, (AccessoryFunc)fn_1_123050,
    (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_11492C,
    (AccessoryFunc)fn_1_11C440, (AccessoryFunc)fn_1_11C440, (AccessoryFunc)fn_1_117D5C, (AccessoryFunc)fn_1_117D5C,
    (AccessoryFunc)fn_1_124AD4, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_11492C, (AccessoryFunc)fn_1_126774,
    (AccessoryFunc)fn_1_126774, (AccessoryFunc)fn_1_1256EC, (AccessoryFunc)fn_1_125DF0, (AccessoryFunc)fn_1_11C440,
    (AccessoryFunc)fn_1_11C440, (AccessoryFunc)fn_1_12744C,
};

static u32 lbl_1_data_404B8 = 98;

/* .data 404BC: part names with an extra vertex set (literals shared with lbl_1_data_3FCAC) */
static char *lbl_1_data_404BC[19] = {
    "GUSTER_JACKET_O_vtx",
    "GOMA_SCARF_vtx",
    "SHIO_SCARF_vtx",
    "SHADOW_MANT_vtx",
    "DAI_SCARF_vtx",
    "SAN_SCARF_vtx",
    "GEN_SCARF_vtx",
    "SPADE_MANT_vtx",
    "BOSS_MANT_vtx",
    "GOROH_BELT_R_vtx",
    "GOROH_BELT_L_vtx",
    "BLOOD_SCARF_vtx",
    "SHERLOK_MANT_U_vtx",
    "SHERLOK_MANT_O_vtx",
    "DAIGOROH_BELT_R_vtx",
    "DAIGOROH_BELT_L_vtx",
    "PRISIA_SCARF_vtx",
    "STEWART_SCARF_vtx",
    "ARROW_MANT_vtx",
};

static u32 lbl_1_data_40508 = 19;

static BgEntry lbl_1_bss_86ED0[70];
static Vec3 lbl_1_bss_88B40;
static u32 lbl_1_bss_88B4C;
static Vec3 lbl_1_bss_88B50[256];
static Vec3 lbl_1_bss_89750;

/* fzgx:begin fn_1_107900 */
void fn_1_107900(void) {
    fn_80008BEC(&lbl_1_bss_86ED0, 0, 0x1c70);
}
/* fzgx:end fn_1_107900 */

/* fzgx:begin fn_1_107930 */
#pragma opt_lifetimes off

void fn_1_107930(fn_1_107930_Object *arg) {
    Obj_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    u32 v17;
    u32 v8;
    fn_1_107930_List *v1;
    void *v19;
    const char **v16;
    void *v25;
    fn_1_107930_Entry *v7;
    fn_1_107930_Object *arg0 = arg;
    u32 *v22;
    s32 v9;
    u32 v20;
    s32 v18;
    u32 v11;
    u32 v24;
    fn_1_107930_Entry *v23;
    s32 v5;
    u32 *v4;
    u32 v3;
    Sig_fn_1_108870_fn_1_108870_AccessoryEntry *v0;
    struct { u32 a[64]; } loc_8;

    if (!arg0) return;
    if (arg0->unk_8C != 0 && (u32)(arg0->unk_8C - 1) > 1) return;
    v1 = arg0->unk_E4[arg0->unk_8C];
    if (!v1) return;
    {
        u32 v6 = lbl_1_data_404B8;
        v4 = lbl_1_data_3FE34;
        v5 = 1;
        for (v3 = 0; v3 < v6; v4++, v3++) {
            if (arg0->unk_88 == (s32)*v4) {
                v5 = 0;
                break;
            }
        }
    }
    if (v5) return;
    p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
    v7 = v1->unk_8;
    for (v8 = 0; v8 < v1->unk_0; v8++, v7++) {
        if (!v7) continue;
        if (!strstr((char *)v7->unk_4, "_vtx")) continue;
        if (strcmp((void *)v7->unk_4, (void *)"DAI_SCARF_vtx") == 0 &&
            lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (strcmp((void *)v7->unk_4, (void *)"SAN_SCARF_vtx") == 0 &&
            lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (strcmp((void *)v7->unk_4, (void *)"GEN_SCARF_vtx") == 0 &&
            lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (arg0->unk_8C == 2) {
            v25 = lbl_1_data_404BC;
            v9 = 0;
            for (v11 = 0; v11 < lbl_1_data_40508; v25 = (u8 *)v25 + 4, v11++) {
                if (strcmp((void *)v7->unk_4, (void *)(*(const char **)v25)) == 0) v9 = 1;
            }
        } else v9 = 1;
        if (!v9) continue;
        v25 = lbl_1_data_3FE34;
        v19 = lbl_1_data_3FCAC;
        v18 = 1;
        for (v17 = 0; v17 < lbl_1_data_404B8;
             v25 = (u8 *)v25 + 4, v19 = (u8 *)v19 + 4, v17++) {
            if (arg0->unk_88 == *(s32 *)v25 &&
                strcmp((void *)v7->unk_4, (void *)(*(const char **)v19)) == 0) {
                v18 = 0;
                break;
            }
        }
        if (v18) continue;
        v19 = v7->unk_0;
        if (!v19) continue;
        v20 = v17 << 2;
        v16 = (const char **)lbl_1_data_3FCAC;
        {
            const char *v21 = *(const char **)((u8 *)v16 + v20);
            v25 = 0;
            sprintf((char *)&loc_8, "N_%s", v21);
        }
        v23 = v1->unk_8;
        v22 = lbl_1_data_3FE34;
        for (v24 = 0; v24 < v1->unk_0; v24++, v23++) {
            if (arg0->unk_88 == *(s32 *)((u8 *)v22 + v20) &&
                strcmp((void *)v23->unk_4, (void *)((char *)&loc_8)) == 0) {
                v25 = v23->unk_0;
                break;
            }
        }
        v0 = fn_1_108870();
        if (v0) {
            *(u32 *)((u8 *)v0 + 8) = v17;
            v0->unk_c = (u32)arg0;
            *(void **)((u8 *)v0 + 0x10) = v19;
            v0->pad_0[0] = 2;
            *(void **)((u8 *)v0 + 0x30) = v25;
            *(s32 *)((u8 *)v0 + 4) = arg0->unk_8C;
        }
        {
            lbl_1_data_401A8[*(u32 *)((u8 *)v0 + 8)](v0);
        }
    }
    {
        static const Vec3 zero = {0.0f, 0.0f, 0.0f};
        lbl_1_bss_88B40 = zero;
    }
}
/* fzgx:end fn_1_107930 */

/* fzgx:begin fn_1_107C4C */
#pragma opt_lifetimes reset

void fn_1_107C4C(void *arg) {
    if (arg != 0) {
        fn_1_1088B8(arg);
    }
}
/* fzgx:end fn_1_107C4C */

/* fzgx:begin fn_1_107C74 */
static const Vec3 fn_1_107C74_zero = {0.0f, 0.0f, 0.0f};

void fn_1_107C74(BgOwner *owner) {

    u32 j;
    u32 i;
    u32 k;
    BgEntry *entry;
    u8 *model;
    BgRange *range;
    Vec3 b;
    Vec3 a;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 distance;

    if (owner == NULL) {
        return;
    }
    if (owner->unk_8C != owner->unk_90) {
        owner->unk_90 = owner->unk_8C;
        if (owner != NULL) {
            fn_1_1088B8(owner);
        }
        fn_1_107930((void *)owner);
        return;
    }
    for (i = 0; i < 64; i++) {
        for (j = 0, entry = lbl_1_bss_86ED0; j < 70; j++, entry++) {
            if (entry->unk_C == NULL || entry->unk_C != owner ||
                i != lbl_1_data_40144[entry->unk_8]) {
                continue;
            }
            model = entry->unk_C->unk_150->unk_8 + lbl_1_data_3FFBC[entry->unk_8] * 0x18C;
            lbl_1_bss_88B4C = 0;
            range = (BgRange *)owner->unk_150;
            if (__fabs(range->unk_4C - range->unk_48) <= 0.00000011920928955078125) {
                a = fn_1_107C74_zero;
                b = a;
                lbl_8006DBAC((void *)(model + 0x88));
                lbl_8006E1B0((void *)&b, (void *)&b);
                lbl_8006DBAC((void *)&entry->unk_34);
                lbl_8006E1B0((void *)&a, (void *)&a);
                dx = b.x - a.x;
                dy = b.y - a.y;
                dz = b.z - a.z;
                b.x = dx;
                b.y = dy;
                b.z = dz;
                distance = dx * dx;
                distance = dy * dy + distance;
                distance = dz * dz + distance;
                lbl_1_bss_88B4C = 1;
                if (distance > 0.01f) {
                    fn_1_107E90((void *)entry);
                    for (k = 0; k < 60; k++) {
                        lbl_1_data_40330[entry->unk_8](entry);
                    }
                }
                lbl_1_bss_88B4C = 0;
            }
            lbl_1_data_40330[entry->unk_8](entry);
            lbl_8006DD14(model + 0x88, &entry->unk_34);
            break;
        }
    }
}
/* fzgx:end fn_1_107C74 */

/* fzgx:begin fn_1_107E90 */
// Initialize each background entry selected by the context.

void fn_1_107E90(Fn107E90Context *context) {
    u32 i;
    u8 *entries;
    u8 *background;
    u8 *entry;
    u32 *background_indices;

    i = 0;
    entries = context->unk_24;
    background_indices = (u32 *)&lbl_1_data_3FFBC;
    background = *(u8 **)(*(u8 **)(context->unk_0C + 0x150) + 0x8);
    entry = background + background_indices[context->unk_08] * 0x18c;
    for (; i < context->unk_18; i++, entries += 0x44) {
        lbl_8006DBAC((void *)(entry + 0x88));
        lbl_8006E1B0((void *)(entries + 0x28), (void *)(entries + 0x10));
    }
}
/* fzgx:end fn_1_107E90 */

/* fzgx:begin fn_1_107F2C */
void fn_1_107F2C(void *arg0) {
    fn_1_107F74((void *)arg0, 0);
}
/* fzgx:end fn_1_107F2C */

/* fzgx:begin fn_1_107F50 */
void fn_1_107F50(void *arg0) {
    fn_1_107F74((void *)arg0, 1);
}
/* fzgx:end fn_1_107F50 */

/* fzgx:begin fn_1_107F74 */
/* VIEWS */
#define lbl_1_bss_86ED0 (*(Obj_1_bss_86ED0_L *)&lbl_1_bss_86ED0)
/* begin rel/main_rel/globals.h (deltawave784/fzgx@7d73e43f (CC0)) */

#define REL_MAIN_REL_GLOBALS_H

// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the

// module's disassembly (matched or not). Field names are offsets until the librarian names them;

// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}

#define REL_MAIN_REL_BG_COMMON_H

// lbl_1_bss_86ED0: .bss size 0x1C70, 3 refs from bg_common.c

#define FZGX_TYPES_LBL_1_BSS_86ED0

// one layout for every TU header that declares this symbol (librarian, typedefs.json)

// typedefs.json decl override

// lbl_1_data_3F510: .data size 0x68, 3 refs from bg_common.c (own data block)

/* end rel/main_rel/bg_common.h */

void fn_1_107F74(BgObj *obj, int flag) {
    u32 i;
    Obj_1_bss_86ED0_L *e;
    u8 *ent;
    s32 r;
    u32 *ids;
    char **names;
    char **names2;
    u8 *model;
    if (obj == NULL) return;
    e = &lbl_1_bss_86ED0;
    for (i = 0; i < 0x46; i++, e = (Obj_1_bss_86ED0_L *)((u8 *)e + 0x68)) {
        if (e == NULL || e->unk_C != (u32)obj) continue;
        ids = lbl_1_data_3FFBC;
        model = obj->unk_150;
        ent = *(u8 **)(model + 8) + ids[e->unk_8] * 0x18c;
        lbl_8006DCA4();
        lbl_8006E0A4(obj->pos);
        mathutil_mtxA_rotate_z(obj->rz);
        mathutil_mtxA_rotate_y(obj->rx);
        mathutil_mtxA_rotate_x(obj->ry);
        lbl_8006E14C(obj->scale);
        lbl_8006DFC4(ent + 0x88);
        r = fn_1_54E34((u8 *)e->unk_10 + 8, *(f32 *)(e->unk_10 + 0x14)) ? 1 : 0;
        if (flag != 0 && r == 0) continue;
        if ((void *)e->unk_10 == NULL) continue;
        if (lbl_1_bss_960 != 4) {
            names = lbl_1_data_3FCAC;
            if (strstr(names[e->unk_8], "SPADE_MANT") != NULL) {
                fn_1_F7870(&lbl_1_data_3F544);
            } else {
                names2 = lbl_1_data_3FCAC;
                if (strstr(names2[e->unk_8], "_MANT") != NULL) {
                    fn_1_F7870(&lbl_1_data_3F510);
                }
            }
        }
        fn_80072558();
        fn_1_556B8((void *)e->unk_10);
        if (lbl_1_bss_960 != 4) {
            names = lbl_1_data_3FCAC;
            if (strstr(names[e->unk_8], "_MANT") != NULL) {
                fn_1_F7870(lbl_1_data_1E5C0);
            }
        }
    }
}

#undef lbl_1_bss_86ED0
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_BG_COMMON_H
#undef FZGX_TYPES_LBL_1_BSS_86ED0
/* fzgx:end fn_1_107F74 */

/* fzgx:begin fn_1_108128 */
static inline void fn_1_108128_cross(Vec3 *a, Vec3 *b, Vec3 *axb) {
    f32 ax = a->x, ay = a->y, az = a->z;
    f32 bx = *(volatile f32 *)&b->x, by = b->y, bz = b->z;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    f32 nx = ay * bz;
    f32 ny = az * bx;
    f32 nz = ax * by;
    nx -= az * by;
    ny -= ax * bz;
    nz -= ay * bx;
    axb->x = nx;
    axb->y = ny;
    axb->z = nz;
}

// Compute a face normal for every (alternating) strip entry and copy it to its vertices.

void fn_1_108128(Fn108128Context *context, u32 stride) {
    u32 i;
    s32 base;
    Fn108128Entry *e;
    u32 odd;
    u32 j;
    Vec3 a;
    Vec3 b;
    Vec3 n;

// Unit normal of the triangle (center, p0, p1).
#define FACE_NORMAL(p0, p1, center)                                 \
    psvec_sub(p0, center, &a);                                      \
    psvec_sub(p1, center, &b);                                      \
    lbl_8006D668((void *)&a);                                               \
    lbl_8006D668((void *)&b);                                               \
    fn_1_108128_cross(&a, &b, &n)

    if (context != NULL && context->model != NULL) {
        base = ((s32)fn_80077B14(context->model));
        e = context->entries;
        odd = (lbl_801A66A0 & 1) ^ 1;
        for (i = 0; i < context->count; i++, e++) {
            if (odd && (i & 1)) {
                continue;
            }
            if (!odd && !(i & 1)) {
                continue;
            }
            if (i > context->count - 1 - stride) {
                if (i + 1 == stride) {
                    FACE_NORMAL(&e[-1].pos, &(e - stride)->pos, &e->pos);
                } else {
                    FACE_NORMAL(&(e - stride)->pos, &e[1].pos, &e->pos);
                }
            } else {
                if (i + 1 == stride) {
                    FACE_NORMAL(&e[stride].pos, &e[-1].pos, &e->pos);
                } else {
                    FACE_NORMAL(&e[1].pos, &e[stride].pos, &e->pos);
                }
            }
            for (j = 0; j < e->count; j++) {
                *(Vec3 *)(base + e->indices[j] * 0x40 + 0xC) = n;
            }
        }
    }
#undef FACE_NORMAL
}
/* fzgx:end fn_1_108128 */

/* fzgx:begin fn_1_10846C */
/* VIEWS */
#define lbl_801A6410 (*(void * *)&lbl_801A6410)
#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

/* model vertex, 0x40 bytes */

/* welded vertex group, 0x44 bytes */

static inline f32 distSq10846C(Vec3 *a, Vec3 *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;
    dx -= b->x;
    dy -= b->y;
    dz -= b->z;
    dx = dx * dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

void fn_1_10846C(Obj10846C *obj) {
    void *model = obj->model;
    u32 *count;
    Vert10846C *verts;
    u32 i;

    if (model == NULL) {
        return;
    }

    if (obj->model != NULL && obj->srcModel != NULL) {
        Vert10846C *dst = fn_80077B14(obj->model);
        u32 *dstCount = fn_80077B64((void *)obj->model);
        Vert10846C *src = fn_80077B14(obj->srcModel);
        u32 *srcCount = fn_80077B64((void *)obj->srcModel);
        u32 j;

        Vert10846C *d;
        Vert10846C *s = src;
        for (i = 0; i < *srcCount; i++, s++) {
            if (s->flags & 1) {
                d = dst;
                for (j = 0; j < *dstCount; j++, d++) {
                    if (distSq10846C(&s->pos, &d->pos) < 0.0000001) {
                        d->attr = s->attr;
                    }
                }
            }
        }
    }

    obj->groupCount = 0;
    obj->unk_1C = 0;
    if (obj->groups != NULL) {
        fn_1_46B4((u32)lbl_801A6410, (u32)obj->groups, "accessory.c", 988);
        obj->groups = NULL;
    }
    if (obj->unk_28 != NULL) {
        fn_1_46B4((u32)lbl_801A6410, (u32)obj->unk_28, "accessory.c", 989);
        obj->unk_28 = NULL;
    }
    if (obj->positions != NULL) {
        fn_1_46B4((u32)lbl_801A6410, (u32)obj->positions, "accessory.c", 991);
        obj->positions = NULL;
    }

    count = fn_80077B64((void *)model);
    verts = fn_80077B14(model);
    obj->groups = (Group10846C *)((u32)fn_1_4630((u32)lbl_801A6410, (u32)(*count * sizeof(Group10846C)), "accessory.c", (s32)998));
    obj->positions = (Vec3 *)((u32)fn_1_4630((u32)lbl_801A6410, (u32)(*count * sizeof(Vec3)), "accessory.c", (s32)999));
    for (i = 0; i < *count; i++) {
        obj->positions[i] = verts->pos;
        verts++;
    }

    verts = fn_80077B14(model);
    obj->groupCount = 0;
    for (i = 0; i < *count; i++, verts++) {
        Group10846C *groups = obj->groups;
        u32 k;
        u32 found = -1;
        u32 n = obj->groupCount;
        Group10846C *g = groups;

        for (k = 0; k < n; k++, g++) {
            if (distSq10846C(&g->p10, &verts->pos) < 0.0000001) {
                found = k;
                break;
            }
        }

        if (found != -1) {
            g = &groups[found];
            g->idx[g->count] = i;
            obj->groups[found].count++;
        } else {
            g = &groups[obj->groupCount];
            g->p28 = verts->pos;
            g->p1C = g->p28;
            g->p10 = g->p1C;
            { Word3_10846C zero = {0, 0, 0}; g->c34 = zero; }
            g->flags = verts->flags;
            fn_80008BEC((void *)g->idx, 0xFF, sizeof(g->idx));
            g->count = 1;
            g->idx[0] = i;
            g->unk_1 = 0;
            obj->groupCount++;
        }
    }
}
#undef lbl_801A6410
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_10846C */

/* fzgx:begin fn_1_108870 */
Sig_fn_1_108870_fn_1_108870_AccessoryEntry *fn_1_108870(void) {
    u32 i;

    for (i = 0; i < 0x46; i++) {
        if (((Sig_fn_1_108870_fn_1_108870_AccessoryEntry *)&lbl_1_bss_86ED0)[i].unk_c == 0) {
            return &((Sig_fn_1_108870_fn_1_108870_AccessoryEntry *)&lbl_1_bss_86ED0)[i];
        }
    }
    return 0;
}
/* fzgx:end fn_1_108870 */

/* fzgx:begin fn_1_1088B8 */
void fn_1_1088B8(void *arg) {
    u32 i;

    for (i = 0; i < 0x46; i++) {
        Sig_fn_1_108870_fn_1_108870_AccessoryEntry *entry = ((Sig_fn_1_108870_fn_1_108870_AccessoryEntry *)&lbl_1_bss_86ED0) + i;
        if (entry->unk_c == (u32)arg) {
            fn_1_108920((u32)entry);
        }
    }
}
/* fzgx:end fn_1_1088B8 */

/* fzgx:begin fn_1_108920 */
/* VIEWS */
#define lbl_801A6410 (*(struct fn_1_108920_lbl_801A6410 *)&lbl_801A6410)
void fn_1_108920(u32 accessory) {
    u32 resource;
    s32 matrix_address;
    s32 source_offset;
    s32 entry_index;
    u32 source_address;
    u32 positions;
    u32 entries;
    u32 indices;
    u32 extra_data;
    void * entry_count;
    s32 matrix_base;
    if (accessory != 0) {
        resource = *(u32 *)(accessory + 16);
        if (resource != 0) {
            entry_count = (fn_80077B64((void *)((struct Sig_fn_80077B64_fn_80077B64_Arg0 *)resource)));
            matrix_base = ((s32)fn_80077B14((void *)((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)resource)));
            matrix_address = matrix_base;
            entry_index = 0;
            source_offset = 0;
            while (entry_index < *(u32 *)(entry_count)) {
                entry_index++;
                source_address = (*(u32 *)(accessory + 100) + source_offset);
                *(struct fn_1_108920_Copy12 *)matrix_address = *(struct fn_1_108920_Copy12 *)source_address;
                source_offset += 12;
                matrix_address += 64;
            }
        }
    }
    positions = *(u32 *)(accessory + 100);
    if (positions != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, positions, (void *)"accessory.c", 1154);
        *(u32 *)((u8 *)accessory + 100) = 0;
    }
    entries = *(u32 *)(accessory + 36);
    if (entries != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, entries, (void *)"accessory.c", 1157);
        *(u32 *)((u8 *)accessory + 36) = 0;
    }
    indices = *(u32 *)(accessory + 40);
    if (indices != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, indices, (void *)"accessory.c", 1158);
        *(u32 *)((u8 *)accessory + 40) = 0;
    }
    extra_data = *(u32 *)(accessory + 44);
    if (extra_data != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, extra_data, (void *)"accessory.c", 1159);
        *(u32 *)((u8 *)accessory + 44) = 0;
    }
    fn_80008BEC((void *)accessory, 0, 104);
}
#undef lbl_801A6410
/* fzgx:end fn_1_108920 */

/* fzgx:begin fn_1_108A90 */
void fn_1_108A90(fn_1_108A90_Self *self, s32 idx, f32 radius, f32 cx, f32 cy, f32 cz) {
    fn_1_108A90_Self *s = self;
    f32 r = radius;
    f32 sq = r * r;
    u32 i;
    fn_1_108A90_Entry *e;
    Vec3 center;
    Vec3 d;

    center.x = cx;
    center.y = cy;
    center.z = cz;
    lbl_8006DBAC((void *)(((0x88) + (((*((s->unk_c->unk_150) + (2)))) + (idx * 0x18c)))));
    lbl_8006E1B0(&center, &center);
    i = 0;
    e = s->entries;
    while (i < s->count) {
        f32 dz;
        f32 dy;
        f32 dx;
        f32 d2;

        /* retail keeps the skip flag test as a branch to the common increment tail */
        if ((*e).unk_0 & 1) {
            goto next; /* skip to the loop increment tail */
        }
        dx = (*e).vec.x - center.x;
        dy = (*e).vec.y;
        dy = dy - center.y;
        dz = (*e).vec.z;
        dz = dz - center.z;
        d2 = (dx * dx);
        d2 = d2 + dy * dy;
        d2 = d2 + dz * dz;
        if (d2 < sq) {
            psvec_sub_scale_add(&e->vec, &center, r * lbl_8006D0E8(d2), &d, &e->vec);
        }
    next:
        i = i + 1;
        e = (fn_1_108A90_Entry *)((u8 *)e + 0x44);
    }
}
/* fzgx:end fn_1_108A90 */

/* fzgx:begin fn_1_108BD0 */
void fn_1_108BD0(Fn1108BD0_Object *object, s32 joint_index, f32 margin, f32 x, f32 y, f32 z) {
    s32 joint = joint_index;
    Fn1108BD0_Object *obj = object;
    u32 i;
    Fn1108BD0_Table *table;
    Fn1108BD0_Entry *entry;
    f32 radius;
    f32 dist;
    f32 dy;
    f32 dz;
    u32 n;
    Fn1108BD0_Part *part;

    table = obj->model->tables[obj->model->table_index];
    if (table == 0) {
        return;
    }
    entry = table->entries;
    for (i = 0; i < table->count; i++, entry++) {
        if (entry != 0 && ((u32)strstr((char *)entry->name, lbl_1_data_3FCAC[obj->name_index])) != 0) {
            radius = 0.5f * entry->shape->radius;
            break;
        }
    }
    radius *= 0.25f;
    {
        Vec3 pos;

        {
            Fn1108BD0_Joint *j = &obj->model->skeleton->joints[joint];
            pos.x = x;
            pos.y = y;
            pos.z = z;
            lbl_8006DBAC(j->mtx);
        }
        lbl_8006E1B0(&pos, &pos);
        {
        Vec3 sum = {0.0f, 0.0f, 0.0f};
        n = 0;
        part = obj->parts;
        for (i = 0; i < obj->part_count; i++, part++) {
            if (!(part->flags & 1)) {
                n++;
                sum.x += part->pos.x;
                sum.y += part->pos.y;
                sum.z += part->pos.z;
            }
        }
        sum.x /= n;
        sum.y /= n;
        sum.z /= n;
        dz = sum.z - pos.z;
        dy = sum.y - pos.y;
        dist = sum.x - pos.x;
        dist *= dist;
        dist += dy * dy;
        dist += dz * dz;
        dist = lbl_8006D0B4(dist);
        if (radius + margin > dist) {
            margin = radius + margin - dist;
            sum.x -= pos.x;
            sum.y -= pos.y;
            sum.z -= pos.z;
            lbl_8006D668(&sum);
            sum.x *= margin;
            sum.y *= margin;
            sum.z *= margin;
            part = obj->parts;
            for (i = 0; i < obj->part_count; i++, part++) {
                if (!(part->flags & 1)) {
                    part->pos.x += sum.x;
                    part->pos.y += sum.y;
                    part->pos.z += sum.z;
                }
            }
        }
        }
    }
}
/* fzgx:end fn_1_108BD0 */

/* fzgx:begin fn_1_108EEC */
void fn_1_108EEC(fn_1_108EEC_Arg *arg0, s32 arg5, s32 arg6, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 fzgx_live;
    u8 *p;
    u32 i;
    fn_1_108EEC_Node *n;
    fn_1_108EEC_Arg *self = arg0;
    u32 j;
    fn_1_108EEC_Node *m;
    u8 *e;
    f32 rad2;
    f32 len2;
    f32 scale;
    f32 dx;
    f32 dy;
    f32 dz;
    Vec3 v;
    Vec3 c;
    Vec3 b;
    Quat q;
    Mtx mtx;

    rad2 = arg1 * arg1;
    e = self->unk_c->unk_150->unk_8 + arg5 * 0x18c;
    v.x = arg2;
    v.y = arg3;
    v.z = arg4;
    lbl_8006DBAC(e + 0x88);
    lbl_8006E1B0(&v, &v);
    p = self->unk_c->unk_150->unk_8 + arg6 * 0x18c;
    n = self->unk_24;
    i = 0;
    while (i < self->unk_18) {
        if (!(n->unk_0 & 1)) {
            b = n->unk_10;
            dx = n->unk_10.x - v.x;
            c.x = dx;
            len2 = (dx * dx);
            dy = n->unk_10.y - v.y;
            c.y = dy;
            len2 = len2 + dy * dy;
            dz = n->unk_10.z - v.z;
            c.z = dz;
            len2 = len2 + dz * dz;
            if (len2 < rad2) {
                scale = arg1 / lbl_8006D0B4(len2);
                fzgx_live = c.x;
                c.x = (f32)(fzgx_live * scale) + v.x;
                c.y = (f32)(c.y * scale) + v.y;
                c.z = (f32)(c.z * scale) + v.z;
                lbl_8006DBAC(p + 0x88);
                fn_8006E250(&c, &c);
                fn_8006E250(&b, &b);
                lbl_8006D668(&c);
                lbl_8006D668(&b);
                fn_8006E978(&q, (void *)&b, (void *)&c);
                mathutil_mtxA_from_quat(&q);
                lbl_8006DB74(&mtx);
                m = self->unk_24;
                j = 0;
                while (j < self->unk_18) {
                    c = m->unk_10;
                    lbl_8006DBAC(p + 0x88);
                    fn_8006E250(&c, &c);
                    lbl_8006DBAC(p + 0x88);
                    lbl_8006DFC4(&mtx);
                    lbl_8006E1B0(&c, &m->unk_10);
                    j++;
                    m++;
                }
            }
        }
        i++;
        n++;
    }
}
/* fzgx:end fn_1_108EEC */

/* fzgx:begin fn_1_109114 */
void fn_1_109114(fn_1_109114_AccessoryObject *self) {
    void *base;
    u16 *item;
    int entry_index;
    int item_index;
    u8 *entry;

    base = fn_80077B14(self->unk_10);
    lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                 lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
    entry = self->unk_24;
    entry_index = 0;
    while (entry_index < self->unk_18) {
        item = (u16 *)entry;
        item_index = 0;
        while (item_index < entry[2]) {
            fn_8006E250(entry + 0x10, (u8 *)base + item[2] * 0x40);
            item++;
            item_index++;
        }
        entry_index++;
        entry += 0x44;
    }
}
/* fzgx:end fn_1_109114 */

/* fzgx:begin fn_1_1091D4 */
/* Gravity step of a rope node: half a step on the position, a full step on the velocity. Plain static: the
   module's -inline auto inlines it at every call and the link drops the out-of-line copy. */
static void accessory_node_fall(Vec3 *pos, Vec3 *vel) {
    pos->y -= 0.0013611111376020642;
    vel->y -= 0.0027222224f;
}

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

void fn_1_1091D4(u32 arg0) {
    u32 v1;
    u32 v5;
    u32 v34;
    u32 t5;
    f32 v0;
    u32 v3;
    v1 = arg0;
    if (arg0 != 0) {
    fn_1_10846C((void *)v1);
    {
    Group1091D4 *v6 = *(Group1091D4 **)(arg0 + 36);
    for (v5 = 0; v5 < *(u32 *)(arg0 + 24); v5++, v6++) {
    if (v6->flags & 1) {
    v6->unk_40 = -1.0f;
    v6->flags = 0;
    } else {
    v6->unk_40 = 0.0f;
    v6->flags = 1;
    }
    }
    }
    {
    Group1091D4 *v16, *v10;
    Group1091D4 *v36;
    u32 v15;
    for (v5 = 0, v10 = *(Group1091D4 **)(arg0 + 36); v5 < *(u32 *)(arg0 + 24); v5++, v10++) {
    v16 = &(*(Group1091D4 **)(arg0 + 36))[v5] + 1;
    for (v15 = v5 + 1; v15 < *(u32 *)(arg0 + 24); v15++, v16++) {
    if ((v10->flags & 1) && !(v16->flags & 1)) {
    fn_1_128884((void *)v10, (void *)v16, 68);
    }
    }
    }
    {
    Group1091D4 *v23, *v18;
    u32 v24;
    for (v5 = 0, v18 = *(Group1091D4 **)(arg0 + 36); v5 < *(u32 *)(arg0 + 24); v5++, v18++) {
    v23 = &(*(Group1091D4 **)(arg0 + 36))[v5] + 1;
    for (v24 = v5 + 1; v24 < *(u32 *)(arg0 + 24); v24++, v23++) {
    if (v18->flags == v23->flags && v18->unk_18 > v23->unk_18) {
    fn_1_128884((void *)v18, (void *)v23, 68);
    }
    }
    }

    }
    {
    Group1091D4 *v31, *v26;
    u32 v32;
    for (v5 = 0, v26 = *(Group1091D4 **)(arg0 + 36); v5 < *(u32 *)(arg0 + 24); v5++, v26++) {
    v31 = &(*(Group1091D4 **)(arg0 + 36))[v5] + 1;
    for (v32 = v5 + 1; v32 < *(u32 *)(arg0 + 24); v32++, v31++) {
    if (v26->flags == v31->flags) {
    if (v26->unk_14 < v31->unk_14 && v26->unk_18 > 0.0f && v31->unk_18 > 0.0f) {
    fn_1_128884((void *)v26, (void *)v31, 68);
    } else if (v26->unk_14 > v31->unk_14 && v26->unk_18 < 0.0f && v31->unk_18 < 0.0f) {
    fn_1_128884((void *)v26, (void *)v31, 68);
    }
    }
    }
    }
    }
    v34 = ((*(u32 *)(arg0 + 24) - 2) >> 1);
    t5 = ((v34 - 1) << 1) + 4;
    *(u32 *)((u8 *)arg0 + 28) = v34 + t5;
    v1 = lbl_801A6410;
    t5 = ((u32)fn_1_4630(v1, (*(u32 *)(arg0 + 28) * 12), "accessory.c", 0x666));
    v1 = t5;
    *(u32 *)((u8 *)arg0 + 40) = v1;
    {
    Group1091D4 *v46;
    u32 v37;
    Group1091D4 *v54;
    for (v5 = 0, v37 = 0, v36 = *(Group1091D4 **)(arg0 + 36); v5 < *(u32 *)(arg0 + 24) - 1; v5++, v36++) {
    if (v36->flags == v36[1].flags) {
    (*(Link1091D4 **)(arg0 + 40))[v37].a = v36;
    (*(Link1091D4 **)(arg0 + 40))[v37].b = v36 + 1;
    v0 = fn_1_1289BC((void *)((const Point1024C4 *)v36), (void *)((const Point1024C4 *)(v36 + 1)));
    (*(Link1091D4 **)(arg0 + 40))[v37].distance = v0;
    v37++;
    }
    }
    v46 = *(Group1091D4 **)((u8 *)arg0 + 36);
    for (v5 = 0; v5 < *(u32 *)(arg0 + 24); v5++, v46++) {
    if (v46->flags != v46[1].flags) {
    (*(Link1091D4 **)(arg0 + 40))[v37].a = *(Group1091D4 **)((u8 *)arg0 + 36);
    (*(Link1091D4 **)(arg0 + 40))[v37].b = v46 + 1;
    (*(Link1091D4 **)(arg0 + 40))[v37].distance = fn_1_1289BC((void *)(*(const Point1024C4 **)(arg0 + 36)), (void *)((const Point1024C4 *)(v46 + 1)));
    v37++;
    (*(Link1091D4 **)(arg0 + 40))[v37].a = &(*(Group1091D4 **)(arg0 + 36))[*(u32 *)(arg0 + 24) - 1];
    (*(Link1091D4 **)(arg0 + 40))[v37].b = v46;
    (*(Link1091D4 **)(arg0 + 40))[v37].distance = fn_1_1289BC((void *)((const Point1024C4 *)&(*(Group1091D4 **)(arg0 + 36))[*(u32 *)(arg0 + 24) - 1]), (void *)((const Point1024C4 *)v46));
    v54 = v46 + 2;
    v37++;
    break;
    }
    }
    for (v5 = 0, v36 = *(Group1091D4 **)(arg0 + 36); v5 < *(u32 *)(arg0 + 24); v5++, v36++, v54++) {
    (*(Link1091D4 **)(arg0 + 40))[v37].a = v36;
    (*(Link1091D4 **)(arg0 + 40))[v37].b = v54;
    (*(Link1091D4 **)(arg0 + 40))[v37].distance = fn_1_1289BC((void *)((const Point1024C4 *)v36), (void *)((const Point1024C4 *)v54));
    v37++;
    if (v36->flags != v36[1].flags) break;
    }
    }
    }
    {
    f32 v66, v2, v64, v65, v67, v68, v74, v76;
    Group1091D4 *v62, *v63;
    u8 v75;
    u32 v3;
    v2 = 0.0f;
    v3 = 10000;
    do {
    v5 = 0;
    v75 = 0;
    for (; v5 < *(u32 *)(arg0 + 28); v5++) {
    v62 = (*(Link1091D4 **)(arg0 + 40))[v5].a;
    v63 = (*(Link1091D4 **)(arg0 + 40))[v5].b;
    v64 = v62->unk_40;
    if (v64 >= v2 && (v65 = v63->unk_40) < v2) {
    if (v64 < 0.00000011920929f) {
    v66 = -2.0f;
    } else {
    v66 = 2.0f * -v64;
    }
    if (v64 > -1.0000001f || v66 > v65) {
    v63->unk_40 = v66;
    }
    } else {
    v67 = v63->unk_40;
    v68 = 0.0f;
    if (v67 >= v68 && v64 < v68) {
    if (v67 < 0.00000011920929f) {
    v66 = -2.0f;
    } else {
    v66 = 2.0f * -v67;
    }
    if (v67 > -1.0000001f || v66 > v64) {
    v62->unk_40 = v66;
    }
    }
    }
    }
    {
    Group1091D4 *v72, *v73;
    for (v34 = 0; v34 < *(u32 *)(arg0 + 28); v34++) {
    v72 = (*(Link1091D4 **)(arg0 + 40))[v34].a;
    v73 = (*(Link1091D4 **)(arg0 + 40))[v34].b;
    v74 = v72->unk_40;
    if (v74 < -1.0000001f) {
    v75 = 1;
    v72->unk_40 = -v74;
    } else {
    v76 = v73->unk_40;
    if (v76 < -1.0000001f) {
    v75 = 1;
    v73->unk_40 = -v76;
    }
    }
    }
    }
    if (v75 == 0) break;
    } while ((u16)v3-- != 0);
    }
    }
}

#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_1091D4 */

/* fzgx:begin fn_1_10976C */
#define ROPE_BASE(w) ((w)->owner->model->base + lbl_1_data_3FFBC[(w)->index] * 0x18c)

static inline void rope_save_pos(RopeWork *w) {
    RopeNode *n;
    u32 i;
    RopeVec *dst;
    for (i = 0, n = w->nodes, dst = (RopeVec *)&lbl_1_bss_88B50; i < w->count; i++, n++) {
        if (!(n->flags & 1)) {
            *dst = n->pos;
            dst++;
        }
    }
}

void fn_1_10976C(RopeWork *arg0) {
    RopeLink *l5;
    RopeNode *n1;
    u32 i5;
    RopeNode *q5;
    RopeLink *l;
    u32 i1;
    RopeNode *n3;
    u32 vi;
    u32 fj;
    u8 *model4;
    u8 *model3;
    RopeNode *a;
    u32 fi;
    u32 i3;
    RopeLink *l6;
    RopeNode *fn;
    RopeNode *q6;
    u32 i6;
    u32 j6;
    u32 li;
    u8 *fmodel;
    RopeNode *n6;
    u16 *lp;
    u32 i4;
    u32 i2;
    u32 j5;
    RopeNode *b;
    RopeNode *n2;
    RopeNode *n5;
    RopeNode *p5;
    RopeNode *n4;
    RopeNode *p6;
    RopeNode *vn;
    RopeVec v;
    RopeVec dif;
    RopeVec t;
    RopeVec g;
    f32 len;
    u8 *mb;
    f32 inv;
    f32 r;
    f32 fa;
    f32 fb;

    if (arg0 && arg0->obj) {
        fn_80077B14(arg0->obj);
        if (arg0->flags & 2) {
            arg0->flags &= ~2;
            lbl_8006DBAC(ROPE_BASE(arg0) + 0x88);
            lbl_8006DAEC();
            for (i1 = 0, n1 = arg0->nodes; i1 < arg0->count; i1++, n1++) {
                lbl_8006DBE4();
                lbl_8006E1B0(&n1->local, &n1->pos);
            }
            lbl_8006DC20();
        }
        g.x = 0.0f;
        g.y = -9.8f / 3600.0f;
        g.z = 0.0f;
        for (i2 = 0, n2 = arg0->nodes; i2 < arg0->count; i2++, n2++) {
            if (!(n2->flags & 1)) {
                n2->prev = n2->pos;
                n2->pos.x += n2->vel.x + g.x * 0.5f;
                n2->pos.y += n2->vel.y + g.y * 0.5f;
                n2->pos.z += n2->vel.z + g.z * 0.5f;
                n2->vel.x += g.x;
                n2->vel.y += g.y;
                n2->vel.z += g.z;
            }
        }
        model3 = ROPE_BASE(arg0);
        for (i3 = 0, n3 = arg0->nodes; i3 < arg0->count; i3++, n3++) {
            lbl_8006DBAC(model3 + 0x88);
            lbl_8006DAEC();
            if (n3->flags & 1) {
                lbl_8006DBE4();
                lbl_8006E1B0(&n3->local, &n3->pos);
            }
            lbl_8006DC20();
        }
        for (li = 0, l = arg0->links; li < arg0->linkCount; li++, l++) {
            a = l->a;
            b = l->b;
            if (a && b) {
                f32 x;
                f32 y;
                f32 z;
                x = a->pos.x - b->pos.x;
                v.x = x;
                y = a->pos.y - b->pos.y;
                v.y = y;
                z = a->pos.z - b->pos.z;
                v.z = z;
                len = (f32)(x * x) + y * y + z * z;
                if (len - 0.0001f > l->length) {
                    inv = lbl_8006D118(len, &len);
                    r = lbl_8006D0B4(l->length);
                    len = inv * (len - r);
                    v.x *= len;
                    v.y *= len;
                    v.z *= len;
                    r = 1.0f / (a->weight + b->weight);
                    fa = a->weight * r;
                    fb = b->weight * r;
                    a->pos.x -= (f32)(v.x * fa);
                    a->pos.y -= (f32)(v.y * fa);
                    a->pos.z -= (f32)(v.z * fa);
                    b->pos.x += (f32)(v.x * fb);
                    b->pos.y += (f32)(v.y * fb);
                    b->pos.z += (f32)(v.z * fb);
                    a->vel.x = a->pos.x - a->prev.x;
                    a->vel.y = a->pos.y - a->prev.y;
                    a->vel.z = a->pos.z - a->prev.z;
                    b->vel.x = b->pos.x - b->prev.x;
                    b->vel.y = b->pos.y - b->prev.y;
                    b->vel.z = b->pos.z - b->prev.z;
                }
            }
        }
        model4 = ROPE_BASE(arg0);
        for (i4 = 0, n4 = arg0->nodes; i4 < arg0->count; i4++, n4++) {
            f32 x;
            f32 d;
            f32 y;
            f32 z;
            lbl_8006DBAC(model4 + 0x88);
            lbl_8006E1B0(&n4->local, &t);
            x = n4->pos.x - t.x;
            dif.x = x;
            d = x * x;
            y = n4->pos.y - t.y;
            dif.y = y;
            d += y * y;
            z = n4->pos.z - t.z;
            dif.z = z;
            d += z * z;
            len = d;
            if (len > 0.0004f) {
                len = lbl_8006D0B4(0.0004f / len);
                n4->pos.x = t.x + (f32)(dif.x * len);
                n4->pos.y = t.y + (f32)(dif.y * len);
                n4->pos.z = t.z + (f32)(dif.z * len);
                n4->prev = n4->pos;
            }
        }
        mb = arg0->owner->model->base;
        {
            RopeVec center = {0.0f, 0.0f, 0.0f};
            v = center;
        }
        lbl_8006DBAC(mb + 0x844);
        mathutil_mtxA_translate_z(0.025f);
        lbl_8006E1B0(&v, &v);
        for (i5 = 0, n5 = arg0->nodes; i5 < arg0->count; i5++, n5++) {
            if (!(n5->flags & 1)) {
                f32 x;
                f32 d;
                f32 y;
                f32 z;
                x = n5->pos.x - v.x;
                dif.x = x;
                d = x * x;
                y = n5->pos.y - v.y;
                dif.y = y;
                d += y * y;
                z = n5->pos.z - v.z;
                dif.z = z;
                d += z * z;
                len = d;
                if (len < 0.065f * 0.065f) {
                    RopeVec c;
                    for (j5 = 0, l5 = arg0->links; j5 < arg0->linkCount; j5++, l5++) {
                        p5 = l5->a;
                        q5 = l5->b;
                        if (p5 && q5) {
                            if (p5 == n5 && (q5->flags & 1)) {
                                p5 = q5;
                                break;
                            }
                            if (q5 == n5 && (p5->flags & 1)) {
                                break;
                            }
                            p5 = NULL;
                        }
                    }
                    if (p5) {
                        dif.x = p5->pos.x - n5->pos.x;
                        dif.y = p5->pos.y - n5->pos.y;
                        dif.z = p5->pos.z - n5->pos.z;
                        t.x = v.x - n5->pos.x;
                        t.y = v.y - n5->pos.y;
                        t.z = v.z - n5->pos.z;
                        lbl_8006D668(&dif);
                        lbl_8006D668(&t);
                        mathutil_vec_cross_prod(&dif, &t, &c);
                        c.x += n5->pos.x;
                        c.y += n5->pos.y;
                        c.z += n5->pos.z;
                        c.x += p5->pos.x;
                        c.y += p5->pos.y;
                        c.z += p5->pos.z;
                        c.x *= 0.5f;
                        c.y *= 0.5f;
                        c.z *= 0.5f;
                        c.x -= n5->pos.x;
                        c.y -= n5->pos.y;
                        c.z -= n5->pos.z;
                        lbl_8006D668(&c);
                        mathutil_vec_cross_prod(&dif, &c, &t);
                        lbl_8006D668(&t);
                        len = 0.065f + 0.01 - lbl_8006D0B4(len);
                        len *= 0.3;
                        n5->pos.x += (f32)(t.x * len);
                        n5->pos.y += (f32)(t.y * len);
                        n5->pos.z += (f32)(t.z * len);
                        n5->prev = n5->pos;
                        i5--;
                        n5--;
                    }
                }
            }
        }
        mb = arg0->owner->model->base;
        {
            RopeVec center = {0.0f, 0.0f, 0.0f};
            v = center;
        }
        lbl_8006DBAC(mb + 0x844);
        mathutil_mtxA_translate_x(-0.019f);
        mathutil_mtxA_translate_z(0.057f);
        lbl_8006E1B0(&v, &v);
        for (i6 = 0, n6 = arg0->nodes; i6 < arg0->count; i6++, n6++) {
            if (!(n6->flags & 1)) {
                f32 x;
                f32 d;
                f32 y;
                f32 z;
                x = n6->pos.x - v.x;
                dif.x = x;
                d = x * x;
                y = n6->pos.y - v.y;
                dif.y = y;
                d += y * y;
                z = n6->pos.z - v.z;
                dif.z = z;
                d += z * z;
                len = d;
                if (len < 0.031f * 0.031f) {
                    RopeVec c;
                    for (j6 = 0, l6 = arg0->links; j6 < arg0->linkCount; j6++, l6++) {
                        p6 = l6->a;
                        q6 = l6->b;
                        if (p6 && q6) {
                            if (p6 == n6 && (q6->flags & 1)) {
                                p6 = q6;
                                break;
                            }
                            if (q6 == n6 && (p6->flags & 1)) {
                                break;
                            }
                            p6 = NULL;
                        }
                    }
                    if (p6) {
                        dif.x = p6->pos.x - n6->pos.x;
                        dif.y = p6->pos.y - n6->pos.y;
                        dif.z = p6->pos.z - n6->pos.z;
                        t.x = v.x - n6->pos.x;
                        t.y = v.y - n6->pos.y;
                        t.z = v.z - n6->pos.z;
                        lbl_8006D668(&dif);
                        lbl_8006D668(&t);
                        mathutil_vec_cross_prod(&dif, &t, &c);
                        c.x += n6->pos.x;
                        c.y += n6->pos.y;
                        c.z += n6->pos.z;
                        c.x += p6->pos.x;
                        c.y += p6->pos.y;
                        c.z += p6->pos.z;
                        c.x *= 0.5f;
                        c.y *= 0.5f;
                        c.z *= 0.5f;
                        c.x -= n6->pos.x;
                        c.y -= n6->pos.y;
                        c.z -= n6->pos.z;
                        lbl_8006D668(&c);
                        mathutil_vec_cross_prod(&dif, &c, &t);
                        lbl_8006D668(&t);
                        len = 0.031f + 0.01 - lbl_8006D0B4(len);
                        len *= 0.3;
                        n6->pos.x += (f32)(t.x * len);
                        n6->pos.y += (f32)(t.y * len);
                        n6->pos.z += (f32)(t.z * len);
                        n6->prev = n6->pos;
                        i6--;
                        n6--;
                    }
                }
            }
        }
        for (vi = 0, vn = arg0->nodes; vi < arg0->count; vi++, vn++) {
            vn->vel.x = vn->pos.x - vn->prev.x;
            vn->vel.y = vn->pos.y - vn->prev.y;
            vn->vel.z = vn->pos.z - vn->prev.z;
        }
        rope_save_pos(arg0);
        fmodel = fn_80077B14(arg0->obj);
        lbl_8006DBAC(ROPE_BASE(arg0) + 0x88);
        for (fi = 0, fn = arg0->nodes; fi < arg0->count; fi++, fn++) {
            for (fj = 0, lp = (u16 *)fn; (s32)fj < fn->count; lp++, fj++) {
                fn_8006E250(&fn->pos, fmodel + (lp[2] << 6));
            }
        }
    }
}
#undef ROPE_BASE
/* fzgx:end fn_1_10976C */

/* fzgx:begin fn_1_10A43C */
void fn_1_10A43C(AccessoryObject *self) {
    int i;
    int j;
    AccessoryEntry *entry_i;
    AccessoryEntry *entry_j;

    if (self == NULL) {
        return;
    }

    fn_1_10846C((void *)self);

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        if (entry_i->unk_0 & 1) {
            entry_i->unk_40 = -1.0f;
            entry_i->unk_0 = 0;
        } else {
            entry_i->unk_40 = 0.0f;
            entry_i->unk_0 = 1;
        }
    }

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        for (j = i + 1, entry_j = (AccessoryEntry *)(self->unk_24 + i * 0x44 + 0x44); j < self->unk_18; j++, entry_j++) {
            if ((entry_i->unk_0 & 1) && !(entry_j->unk_0 & 1)) {
                fn_1_128884((void *)entry_i, (void *)entry_j, sizeof(AccessoryEntry));
            }
        }
    }

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        for (j = i + 1, entry_j = (AccessoryEntry *)(self->unk_24 + i * 0x44 + 0x44); j < self->unk_18; j++, entry_j++) {
            if (entry_i->unk_0 == entry_j->unk_0) {
                if (entry_i->unk_18 > entry_j->unk_18) {
                    fn_1_128884((void *)entry_i, (void *)entry_j, sizeof(AccessoryEntry));
                }
            }
        }
    }

    for (i = 0, entry_i = (AccessoryEntry *)self->unk_24; i < self->unk_18; i++, entry_i++) {
        for (j = i + 1, entry_j = (AccessoryEntry *)(self->unk_24 + i * 0x44 + 0x44); j < self->unk_18; j++, entry_j++) {
            if (entry_i->unk_0 == entry_j->unk_0) {
                if (entry_i->unk_14 < entry_j->unk_14 && entry_i->unk_18 > 0.0f && entry_j->unk_18 > 0.0f) {
                    fn_1_128884((void *)entry_i, (void *)entry_j, sizeof(AccessoryEntry));
                } else if (entry_i->unk_14 > entry_j->unk_14 && entry_i->unk_18 < 0.0f && entry_j->unk_18 < 0.0f) {
                    fn_1_128884((void *)entry_i, (void *)entry_j, sizeof(AccessoryEntry));
                }
            }
        }
    }
}
/* fzgx:end fn_1_10A43C */

/* fzgx:begin fn_1_10A6A0 */
static inline void fn_1_10A6A0_reset_parts(fn_1_10A6A0_Object *self)
{
    s32 i;
    fn_1_10A6A0_Part *p;

    p = self->unk_24;
    for (i = 0; i < self->unk_18; i++, p++) {
        lbl_8006DBE4();
        lbl_8006E1B0(&p->unk_28, &p->unk_10);
    }
}

static inline void fn_1_10A6A0_attach_parts(fn_1_10A6A0_Object *self, u8 *tbl)
{
    s32 i;
    s32 j;
    fn_1_10A6A0_Part *p;

    p = self->unk_24;
    for (i = 0; i < self->unk_18; i++, p++) {
        for (j = 0; j < p->unk_2; j++) {
            fn_8006E250(&p->unk_10, tbl + p->unk_4[j] * 64);
        }
    }
}

void fn_1_10A6A0(fn_1_10A6A0_Object *self)
{
    s32 i;
    s32 n;
    fn_1_10A6A0_Part *part;
    u8 *pool;
    u8 *tbl;
    s32 j;
    fn_1_10A6A0_Part *delta;

    if (self == 0) {
        return;
    }
    if (self->unk_10 == 0) {
        return;
    }
    fn_80077B14(self->unk_10);

    if (self->unk_0 & 2) {
        self->unk_0 &= ~2;
        lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
        lbl_8006DAEC();
        fn_1_10A6A0_reset_parts(self);
        lbl_8006DC20();
    }

    pool = self->unk_C->unk_150->unk_8 +
           lbl_1_data_3FFBC[self->unk_8] * 0x18c;
    n = 0;
    part = self->unk_24;
    for (i = 0; i < self->unk_18; i++, part++) {
        if (part->unk_0 & 1) {
            lbl_8006DBAC(pool + 0x88);
            lbl_8006E1B0(&part->unk_28, &part->unk_10);
        }
        else {
            part->unk_10 = ((fn_1_10A6A0_Vec *)&lbl_1_bss_88B50)[n];
            n++;
        }
    }

    delta = self->unk_24;
    for (j = 0; j < self->unk_18; j++, delta++) {
        delta->unk_34.x = delta->unk_10.x - delta->unk_1C.x;
        delta->unk_34.y = delta->unk_10.y - delta->unk_1C.y;
        delta->unk_34.z = delta->unk_10.z - delta->unk_1C.z;
    }

    tbl = fn_80077B14(self->unk_10);
    lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
    fn_1_10A6A0_attach_parts(self, tbl);
}
/* fzgx:end fn_1_10A6A0 */

/* fzgx:begin fn_1_10A8D0 */
/* VIEWS */
void fn_1_10A8D0(Graph_10A8D0 *g) {

    struct { u32 value; } offset;
    u32 k;
    struct { u32 value; } crossIndex;
    Node_10A8D0 *c;
    u32 j;
    u32 i;
    struct { Node_10A8D0 *value; } pairA;
    Node_10A8D0 *a;
    struct { Node_10A8D0 *value; } b;
    Node_10A8D0 *p;
    u32 half;
    struct { u32 value; } inner;
    struct { u32 value; } edgeOffset;

    if (g == NULL) {
        return;
    }
    fn_1_10846C((void *)g);

    p = g->nodes;
    for (i = 0; i < g->nodeCount; i++, p++) {
        if (p->flag & 1) {
            p->value = -1.0f;
            p->flag = 0;
        } else {
            p->value = 0.0f;
            p->flag = 1;
        }
    }

    /* flagged nodes first */
    i = 0;
    a = g->nodes;
    offset.value = i;
    for (; i < g->nodeCount; offset.value += sizeof(Node_10A8D0), i++, a++) {
        b.value = (Node_10A8D0 *)((u8 *)g->nodes + offset.value) + 1;
        for (j = i + 1; j < g->nodeCount; j++, b.value++) {
            if ((a->flag & 1) && !(b.value->flag & 1)) {
                fn_1_128884((void *)a, (void *)b.value, sizeof(Node_10A8D0));
            }
        }
    }

    /* within a flag group, by keyB descending */
    i = 0;
    a = g->nodes;
    offset.value = i;
    for (; i < g->nodeCount; offset.value += sizeof(Node_10A8D0), i++, a++) {
        b.value = (Node_10A8D0 *)((u8 *)g->nodes + offset.value) + 1;
        for (j = i + 1; j < g->nodeCount; j++, b.value++) {
            if (a->flag == b.value->flag && a->keyB > b.value->keyB) {
                fn_1_128884((void *)a, (void *)b.value, sizeof(Node_10A8D0));
            }
        }
    }

    /* then by keyA, direction depending on the sign of keyB */
    i = 0;
    a = g->nodes;
    offset.value = i;
    for (; i < g->nodeCount; offset.value += sizeof(Node_10A8D0), i++, a++) {
        b.value = (Node_10A8D0 *)((u8 *)g->nodes + offset.value) + 1;
        for (j = i + 1; j < g->nodeCount; j++, b.value++) {
            if (a->flag == b.value->flag) {
                if (a->keyA < b.value->keyA && a->keyB > 0.0f && b.value->keyB > 0.0f) {
                    fn_1_128884((void *)a, (void *)b.value, sizeof(Node_10A8D0));
                } else if (a->keyA > b.value->keyA && a->keyB < 0.0f && b.value->keyB < 0.0f) {
                    fn_1_128884((void *)a, (void *)b.value, sizeof(Node_10A8D0));
                }
            }
        }
    }

    /* edges inside each half plus the ones joining the halves */
    half = g->nodeCount / 2;
    inner.value = (half - 1) * 2;
    g->edgeCount = inner.value + half;
    g->edges = fn_1_4630(lbl_801A6410, g->edgeCount * sizeof(Edge_10A8D0), "accessory.c", 0x8e1);

    i = 0;
    edgeOffset.value = i;
    k = 0;
    a = g->nodes;
    for (; i < g->nodeCount - 1; i++, a++) {
        if (a->flag == a[1].flag) {
            ((Edge_10A8D0 *)((u8 *)g->edges + edgeOffset.value))->a = a;
            ((Edge_10A8D0 *)((u8 *)g->edges + edgeOffset.value))->b = a + 1;
            ((Edge_10A8D0 *)((u8 *)g->edges + edgeOffset.value))->weight = fn_1_1289BC((void *)a, (void *)(a + 1));
            edgeOffset.value += sizeof(Edge_10A8D0);
            k++;
        }
    }

    pairA.value = g->nodes;
    p = pairA.value;
    for (i = 0; i < g->nodeCount; i++) {
        if (p->flag != p[1].flag) {
            c = p + 1;
            break;
        }
        p++;
    }

    inner.value = k * sizeof(Edge_10A8D0);
    for (crossIndex.value = 0; crossIndex.value < g->nodeCount; crossIndex.value++, pairA.value++, c++) {
        ((Edge_10A8D0 *)((u8 *)g->edges + inner.value))->a = pairA.value;
        ((Edge_10A8D0 *)((u8 *)g->edges + inner.value))->b = c;
        ((Edge_10A8D0 *)((u8 *)g->edges + inner.value))->weight = fn_1_1289BC((void *)pairA.value, (void *)c);
        inner.value += sizeof(Edge_10A8D0);
        if (pairA.value->flag != pairA.value[1].flag) {
            break;
        }
    }

    p = &g->nodes[g->nodeCount / 2];
    for (i = g->nodeCount / 2; i < g->nodeCount; i++, p++) {
        half = g->nodeCount / 2;
        p->value = -1.0 * __fabs(lbl_8006D188((s16)(((i - half) << 15) / half + 0x4000)));
        p->value *= 0.75f;
        p->value -= 0.25f;
    }
}
/* fzgx:end fn_1_10A8D0 */

/* fzgx:begin fn_1_10AD18 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

/* Copy the position of every free node into the shared vertex scratch lbl_1_bss_88B50. */
static inline void accessory_copy_free_positions(Work *arg0) {
 Node *cn;
 u32 ci;
 Vec3 *dst;
 for(ci=0,cn=arg0->nodes,dst=lbl_1_bss_88B50;ci<arg0->count;ci++,cn++) {
 if(!(cn->flags&1)) {
 *dst=cn->pos;
 dst++;
 }
 }
}

void fn_1_10AD18(Work *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Link *l;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *vn;
 Node *b;
 u32 i2;
 Node *n2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Vec3 deltav;
 Vec3 diff;
 Vec3 target;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.y+=n2->vel.y-0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target);
 dif.x=0.5f*((-0.25f/n6->weight)*(target.x-n6->pos.x));
 dif.y=(-0.25f/n6->weight)*(target.y-n6->pos.y);
 dif.z=0.5f*((-0.25f/n6->weight)*(target.z-n6->pos.z));
 n6->pos.x+=dif.x;
 n6->pos.y+=dif.y;
 n6->pos.z+=dif.z;
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len>0.0004f) {
 len=lbl_8006D0B4(0.0004f/len);
 n5->pos.x=target.x+(f32)(dif.x*len);
 n5->pos.y=target.y+(f32)(dif.y*len);
 n5->pos.z=target.z+(f32)(dif.z*len);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=vn->pos.x-vn->prev.x;
 vn->vel.y=vn->pos.y-vn->prev.y;
 vn->vel.z=vn->pos.z-vn->prev.z;
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 accessory_copy_free_positions(arg0);
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
/* fzgx:end fn_1_10AD18 */

/* fzgx:begin fn_1_10B344 */
void fn_1_10B344(Doc *obj) {
    u32 i;
    u32 j;
    Entry *a;
    Entry *b;
    f32 zero;
    f32 neg;
    Entry * a_2;
    Entry * b_2;

    if (obj == 0) {
        return;
    }
    fn_1_10846C((void *)obj);
    neg = -1.0f;
    zero = 0.0f;
    a = obj->entries;
    for (i = 0; i < obj->count; i++, a++) {
        if ((a->active & 1) != 0) {
            a->field40 = neg;
            a->active = 0;
        } else {
            a->field40 = zero;
            a->active = 1;
        }
    }
    a_2 = obj->entries;
    for (i = 0; i < obj->count; i++, a_2++) {
        b = obj->entries + i + 1;
        for (j = i + 1; j < obj->count; j++, b++) {
            if ((a_2->active & 1) != 0) {
                if ((b->active & 1) == 0) {
                    fn_1_128884((void *)a_2, (void *)b, 0x44);
                }
            }
        }
    }
    a_2 = obj->entries;
    for (i = 0; i < obj->count; i++, a_2++) {
        b_2 = obj->entries + i + 1;
        for (j = i + 1; j < obj->count; j++, b_2++) {
            if (a_2->active == b_2->active) {
                if (a_2->field18 > b_2->field18) {
                    fn_1_128884((void *)a_2, (void *)b_2, 0x44);
                }
            }
        }
    }
    a_2 = obj->entries;
    for (i = 0; i < obj->count; i++, a_2++) {
        b_2 = obj->entries + i + 1;
        for (j = i + 1; j < obj->count; j++, b_2++) {
            if (a_2->active == b_2->active) {
                if (a_2->field14 < b_2->field14 && a_2->field18 > 0.0f && b_2->field18 > 0.0f) {
                    fn_1_128884((void *)a_2, (void *)b_2, 0x44);
                } else if (a_2->field14 > b_2->field14 && a_2->field18 < 0.0f && b_2->field18 < 0.0f) {
                    fn_1_128884((void *)a_2, (void *)b_2, 0x44);
                }
            }
        }
    }
}
/* fzgx:end fn_1_10B344 */

/* fzgx:begin fn_1_10B5A8 */
static inline void fn_1_10B5A8_reset_parts(fn_1_10B5A8_Object *self)
{
    s32 i;
    fn_1_10B5A8_Part *p;

    p = self->unk_24;
    for (i = 0; i < self->unk_18; i++, p++) {
        lbl_8006DBE4();
        lbl_8006E1B0(&p->unk_28, &p->unk_10);
    }
}

static inline void fn_1_10B5A8_attach_parts(fn_1_10B5A8_Object *self, u8 *tbl)
{
    s32 i;
    s32 j;
    fn_1_10B5A8_Part *p;

    p = self->unk_24;
    for (i = 0; i < self->unk_18; i++, p++) {
        for (j = 0; j < p->unk_2; j++) {
            fn_8006E250(&p->unk_10, tbl + p->unk_4[j] * 64);
        }
    }
}

void fn_1_10B5A8(fn_1_10B5A8_Object *self)
{
    s32 i;
    s32 n;
    fn_1_10B5A8_Part *part;
    u8 *pool;
    u8 *tbl;
    s32 j;
    fn_1_10B5A8_Part *delta;

    if (self == 0) {
        return;
    }
    if (self->unk_10 == 0) {
        return;
    }
    fn_80077B14(self->unk_10);

    if (self->unk_0 & 2) {
        self->unk_0 &= ~2;
        lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
        lbl_8006DAEC();
        fn_1_10B5A8_reset_parts(self);
        lbl_8006DC20();
    }

    pool = self->unk_C->unk_150->unk_8 +
           lbl_1_data_3FFBC[self->unk_8] * 0x18c;
    n = 0;
    part = self->unk_24;
    for (i = 0; i < self->unk_18; i++, part++) {
        if (part->unk_0 & 1) {
            lbl_8006DBAC(pool + 0x88);
            lbl_8006E1B0(&part->unk_28, &part->unk_10);
        }
        else {
            part->unk_10 = ((fn_1_10B5A8_Vec *)&lbl_1_bss_88B50)[n];
            n++;
        }
    }

    delta = self->unk_24;
    for (j = 0; j < self->unk_18; j++, delta++) {
        delta->unk_34.x = delta->unk_10.x - delta->unk_1C.x;
        delta->unk_34.y = delta->unk_10.y - delta->unk_1C.y;
        delta->unk_34.z = delta->unk_10.z - delta->unk_1C.z;
    }

    tbl = fn_80077B14(self->unk_10);
    lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
    fn_1_10B5A8_attach_parts(self, tbl);
}
/* fzgx:end fn_1_10B5A8 */

/* fzgx:begin fn_1_10B7D8 */
// Initializes accessory data only when an accessory object is present.

void fn_1_10B7D8(void *accessory) {
    if (accessory != 0) {
        fn_1_10846C((void *)accessory);
    }
}
/* fzgx:end fn_1_10B7D8 */

/* fzgx:begin fn_1_10B800 */
void fn_1_10B800(struct Accessory *acc) {
    Vec3 c1 = {-1.0f, 0.0f, 0.0f};
    Vec3 c2 = {1.0f, 0.0f, 0.0f};
    s16 angle;
    s16 d = 0x100;
    u8 *base;
    struct Joint *joint;
    u32 n;
    f32 f1;
    f32 lo;
    u32 i;
    u32 j;
    struct Rec *rec;

    if (acc != 0 && acc->arg != 0) {
        base = fn_80077B14(acc->arg);
        joint = &acc->mgr->inner->joints[18];

        lbl_8006DBAC(joint->matrix);
        lbl_8006E1B0(&c1, &c1);
        lbl_8006DBAC(joint->matrix);
        lbl_8006E1B0(&c2, &c2);

        angle = -0x800;
        lo = 0.065f;
        n = 100;
        joint = &acc->mgr->inner->joints[16];
        do {
            Vec3 c3 = {0.138f, 0.004f, 0.116f};
            lbl_8006DBAC(joint->matrix);
            mathutil_mtxA_rotate_y(angle);
            lbl_8006E1B0(&c3, &c3);
            f1 = fn_1_1289F0((void *)&c1, (void *)&c2, (void *)&c3);
            if (f1 < lo) {
                if (d > 0) {
                    d = -(d / 2);
                }
            } else if (f1 > 0.06501f) {
                if (d < 0) {
                    d = -(d / 2);
                }
            }
            angle += d;
        } while ((f1 < lo || 0.06501f < f1) && n-- != 0);

        lbl_8006D758();
        mathutil_mtxA_rotate_y(angle);

        rec = acc->recs;
        i = 0;
        while (i < acc->count) {
            for (j = 0; j < rec->count; j++) {
                lbl_8006E1B0(&rec->v, base + rec->idx[j] * 0x40);
            }
            i++;
            rec++;
        }
    }
}
/* fzgx:end fn_1_10B800 */

/* fzgx:begin fn_1_10BA00 */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx@13b0aeca (CC0)) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx@13b0aeca (CC0)) */

#define GAME_MAIN_REL_SHARED_TYPES_H

/* fzgx-allow: S2 pool primer sink */

#define LINK(e, p, q)                                                              \
    obj->edges[e].a = p;                                                         \
    obj->edges[e].b = q;                                                         \
    obj->edges[e].dist = fn_1_1289BC((void *)((const Point1024C4 *)(p)), (void *)((const Point1024C4 *)(q)))

void fn_1_10BA00(Obj10BA00 *obj) {
    u32 i;
    u32 j;
    u32 k;
    s32 e;
    u32 n;
    Group10BA00 *g;
    Group10BA00 *h;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        for (i = 0, g = obj->groups; i < obj->groupCount; i++, g++) {
            if (g->flags & 1) {
                g->weight = -1.0f;
                g->flags = 0;
            } else {
                g->weight = 0.0f;
                g->flags = 1;
            }
        }

        /* sort all groups by y */
        g = obj->groups;
        for (i = 0; i < obj->groupCount; i++, g++) {
            h = &obj->groups[i] + 1;
            for (j = i + 1; j < obj->groupCount; j++, h++) {
                if (g->p10.y > h->p10.y) {
                    fn_1_128884((void *)g, (void *)h, sizeof(Group10BA00));
                }
            }
        }

        /* sort each block of four by z */
        g = obj->groups;
        for (i = 0; i < obj->groupCount; i += 4, g += 4) {
            for (j = 0, h = g; j < 4; j++, h++) {
                for (k = j + 1; k < 4; k++) {
                    if (g->p10.z > h->p10.z) {
                        fn_1_128884((void *)g, (void *)h, sizeof(Group10BA00));
                    }
                }
            }
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (1.1920929e-07f + obj->groups[i * 4 + j].weight < 0.0f) {
                    obj->groups[i * 4 + j].weight = -fn_1_128AAC((8.0 - (i + j)), 2.0f);
                    obj->groups[i * 4 + j].weight *= 0.00390625f;
                }
            }
        }

        n = obj->groupCount >> 2;
        obj->edgeCount = (n - 1) * 4 + n * 3;
        obj->edges = fn_1_4630(lbl_801A6410, obj->edgeCount * sizeof(Edge10BA00), "accessory.c", 0xB4F);

        for (i = 0, e = 0, g = obj->groups; i < obj->groupCount; i += 4, g += 4) {
            LINK(e, g, g + 1);
            e++;
            LINK(e, g + 1, g + 2);
            e++;
            LINK(e, g + 2, g + 3);
            e++;
        }

        g = obj->groups;
        for (i = 0; i < obj->groupCount - 4; i += 4, g += 4) {
            LINK(e, g, g + 4);
            e++;
            LINK(e, g + 1, g + 5);
            e++;
            LINK(e, g + 2, g + 6);
            e++;
            LINK(e, g + 3, g + 7);
            e++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
#undef LINK
/* fzgx:end fn_1_10BA00 */

/* fzgx:begin fn_1_10BE3C */
/* VIEWS */
#define lbl_1_bss_88B50 (*(u8 (*)[0xC00])&lbl_1_bss_88B50)
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_10BE3C(Work_10BE3C *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Link *l;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *vn;
 Node *b;
 u32 i2;
 Node *n2;
 u32 i6;
 Node *n6;
 u8 *model6;
 u32 ci;
 Node *cn;
 Vec3 *dst;
 Vec3 deltav;
 Vec3 diff;
 Vec3 target;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=(f32)(n2->vel.y*-n2->weight);
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=(f64)(0.0013611111376020642*(0.05/-n2->weight));
 n2->vel.y-=(f64)(0.0027222223579883575*(0.05/-n2->weight));
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target);
 dif.x=0.25f*(target.x-n6->pos.x);
 dif.y=0.5f*(target.y-n6->pos.y);
 if(dif.y<0.0f) {
 dif.y*=0.02;
 }
 dif.z=0.25f*(target.z-n6->pos.z);
 n6->pos.x+=dif.x;
 n6->pos.y+=dif.y;
 n6->pos.z+=dif.z;
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len>0.0004f) {
 len=lbl_8006D0B4(0.0004f/len);
 n5->pos.x=target.x+(f32)(dif.x*len);
 n5->pos.y=target.y+(f32)(dif.y*len);
 n5->pos.z=target.z+(f32)(dif.z*len);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=vn->pos.x-vn->prev.x;
 vn->vel.y=vn->pos.y-vn->prev.y;
 vn->vel.z=vn->pos.z-vn->prev.z;
 }
 for(ci=0,cn=arg0->nodes;ci<arg0->count;ci++,cn++) {
 dst=&((Vec3 *)lbl_1_bss_88B50)[ci];
 *dst=cn->pos;
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}
#undef lbl_1_bss_88B50
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
/* fzgx:end fn_1_10BE3C */

/* fzgx:begin fn_1_10C4E4 */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_SHARED_TYPES_H

/* fzgx-allow: S2 pool primer sink */

void fn_1_10C4E4(Graph10C4E4 *g) {
    u32 a;
    Node_10A8D0 *base;
    u32 k;
    Node_10A8D0 *pa;
    u32 b;
    u32 i;
    Node_10A8D0 *p;
    Node_10A8D0 *q;
    u32 j;
    Node_10A8D0 *na;
    Node_10A8D0 *nb;
    u8 changed;
    f32 t;
    u16 limit;

    if (g == NULL) {
        return;
    }

    fn_1_10846C((void *)g);

    for (i = 0, p = g->nodes; i < g->nodeCount; i++, p++) {
        if (p->flag & 1) {
            p->value = -1.0f;
            p->flag = 0;
        } else {
            p->value = 0.0f;
            p->flag = 1;
        }
    }

    limit = 10000;
    do {
        i = 0;
        changed = 0;
        for (; i < g->edgeCount; i++) {
            na = g->edges[i].a;
            nb = g->edges[i].b;
            if (na->value >= 0.0f && nb->value < 0.0f) {
                if (na->value < 1.1920928955078125e-07f) {
                    t = -2.0f;
                } else {
                    t = 2.0f * -na->value;
                }
                if (na->value > -1.0000001192092896f || t > nb->value) {
                    nb->value = t;
                }
            } else if (nb->value >= 0.0f && na->value < 0.0f) {
                if (nb->value < 1.1920928955078125e-07f) {
                    t = -2.0f;
                } else {
                    t = 2.0f * -nb->value;
                }
                if (nb->value > -1.0000001192092896f || t > na->value) {
                    na->value = t;
                }
            }
        }
        for (i = 0; i < g->edgeCount; i++) {
            na = g->edges[i].a;
            nb = g->edges[i].b;
            if (na->value < -1.0000001192092896f) {
                na->value = -na->value;
                changed = 1;
            } else if (nb->value < -1.0000001192092896f) {
                nb->value = -nb->value;
                changed = 1;
            }
        }
    } while (changed && limit-- != 0);

    for (i = 0, p = g->nodes; i < g->nodeCount; i++, p++) {
        q = &g->nodes[i] + 1;
        for (j = i + 1; j < g->nodeCount; j++, q++) {
            if (p->keyA > q->keyA) {
                fn_1_128884(p, q, sizeof(Node_10A8D0));
            }
        }
    }

    base = g->nodes;
    for (k = 0; k < g->nodeCount; k += 4, base += 4) {
        a = 0;
        pa = base;
        for (; a < 4; a++, pa++) {
            for (b = a + 1; b < 4; b++) {
                if (base->keyB > pa->keyB) {
                    fn_1_128884(base, pa, sizeof(Node_10A8D0));
                }
            }
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_10C4E4 */

/* fzgx:begin fn_1_10C7B4 */
void fn_1_10C7B4(fn_1_10C7B4_AccessoryObject *self) {
    if (self != 0) {
        if (self->unk_10 != 0) {
            fn_80077B14(self->unk_10);
            if (self->unk_0 & 2) {
                AccessoryItem *item;
                u32 i;

                self->unk_0 &= ~2;
                lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
                lbl_8006DAEC();
                item = (AccessoryItem *)self->unk_24;
                i = 0;
                while (i < self->unk_18) {
                    lbl_8006DBE4();
                    lbl_8006E1B0((u8 *)item + 0x28, (u8 *)item + 0x10);
                    i++;
                    item = (AccessoryItem *)((u8 *)item + 0x44);
                }
                lbl_8006DC20();
            }

            {
                Fn1_10C7B4_Triple *src;
                u32 j;
                AccessoryItem *dst = (AccessoryItem *)self->unk_24;
                j = 0;
                src = (Fn1_10C7B4_Triple *)&lbl_1_bss_88B50;
                while (j < self->unk_18) {
                    *(Fn1_10C7B4_Triple *)&dst->unk_10 = src[j];
                    dst->unk_14.value = dst->unk_14.value - 0.0001;
                    j++;
                    dst = (AccessoryItem *)((u8 *)dst + 0x44);
                }
            }

            {
                u32 k;
                AccessoryItem *dst = (AccessoryItem *)self->unk_24;
                for (k = 0; k < self->unk_18; k++) {
                    dst->unk_34 = dst->unk_10.value - dst->unk_1C.value;
                    dst->unk_38 = dst->unk_14.value - dst->unk_20.value;
                    dst->unk_3C = dst->unk_18.value - dst->unk_24.value;
                    dst = (AccessoryItem *)((u8 *)dst + 0x44);
                }
            }

            {
                u8 *base = fn_80077B14(self->unk_10);
                u8 *entry;
                int m;
                u32 n;
                u8 *p;

                lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
                entry = self->unk_24;
                n = 0;
                while (n < self->unk_18) {
                    p = entry;
                    for (m = 0; m < entry[2]; m++) {
                        fn_8006E250(entry + 0x10, base + *(u16 *)(p + 4) * 0x40);
                        p += 2;
                    }
                    n++;
                    entry += 0x44;
                }
            }
        }
    }
}
/* fzgx:end fn_1_10C7B4 */

/* fzgx:begin fn_1_10C9B0 */
void fn_1_10C9B0(Fn10C9B0List *list) {
    u32 i;
    Fn10C9B0Entry *a;
    Fn10C9B0Entry *p;
    u32 groups;
    u32 n;
    f32 neg;

    if (list == NULL) {
        return;
    }
    fn_1_10846C((void *)list);

    a = list->entries;
    for (i = 0; i < list->count; i++, a++) {
        if (a->flags & 1) {
            a->unk_40 = -1.0f;
            a->flags = 0;
        } else {
            a->unk_40 = 0.0f;
            a->flags = 1;
        }
    }

    /* move entries with bit 0 set to the front */
    p = list->entries;
    for (i = 0; i < list->count; i++, p++) {
        Fn10C9B0Entry *b = list->entries + i + 1;
        u32 j;
        for (j = i + 1; j < list->count; j++, b++) {
            if (!(p->flags & 1) && (b->flags & 1)) {
                fn_1_128884(p, b, sizeof(Fn10C9B0Entry));
            }
        }
    }

    /* within equal flags, sort by unk_18 descending */
    p = list->entries;
    for (i = 0; i < list->count; i++, p++) {
        Fn10C9B0Entry *c = list->entries + i + 1;
        u32 m;
        for (m = i + 1; m < list->count; m++, c++) {
            if (p->flags == c->flags && p->unk_18 < c->unk_18) {
                fn_1_128884(p, c, sizeof(Fn10C9B0Entry));
            }
        }
    }

    /* spread the unset values of each group of three over (-1, 0] */
    groups = (list->count - 1) / 3;
    for (i = 0; i < groups; i++) {
        neg = -(f32)i;
        for (n = 0; n < 3; n++) {
            if (1.1920929e-07f + list->entries[i * 3 + n].unk_40 < 0.0f) {
                list->entries[i * 3 + n].unk_40 = neg / groups;
            }
        }
    }
    list->entries[groups * 3].unk_40 = -1.0f;
}
/* fzgx:end fn_1_10C9B0 */

/* fzgx:begin fn_1_10CC38 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/fzgx@7d73e43f (CC0)) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define BASE(r) ((r)->owner->model->data + lbl_1_data_3FFBC[(r)->index] * 0x18c)

#define SETMAT(b) lbl_8006DBAC((void *)((Vec3 *)((b) + 0x88)))

#define TRANS(a,b) lbl_8006E1B0((void *)((Vec3 *)(a)),(void *)((Vec3 *)(b)))

void fn_1_10CC38(Rope *arg0) {
    Particle * p_r2;
    u32 i_r2;
    Particle * p_r3;
    f32 dx_r2;
    f32 dy_r2;
    f32 len_r2;
    f32 dz_r2;
    f32 scale_r2;
    u32 i_r3;
    Particle * p_r4;
    u32 i_r4;
 Particle *group;
 Particle *p;
 u32 i;
 struct { u8 *value; } base_holder;
#define base base_holder.value
 u16 *link;
 u8 *vertices;
 Vec3 loc_20, loc_14, loc_8;
 f32 accel;
 f32 len, scale;
 f32 dx,dy,dz;
 f32 limit;
 if (arg0 && arg0->handle) {
 ((s32)fn_80077B14((void *)arg0->handle));
 if (arg0->flags & 2) {
 arg0->flags &= ~2;
 SETMAT(BASE(arg0));
 lbl_8006DAEC();
 p=arg0->particles;
 for(i=0;i<arg0->count;i++,p++) {
 lbl_8006DBE4(); TRANS(&p->local,&p->pos);
 }
 lbl_8006DC20();
 }
 p_r2=arg0->particles;
 for(i_r2=0;i_r2<arg0->count;i_r2++,p_r2++) {
 if (!(p_r2->flags & 1)) {
 p_r2->prev=p_r2->pos;
 p_r2->pos.x+=p_r2->vel.x; p_r2->pos.y+=p_r2->vel.y; p_r2->pos.z+=p_r2->vel.z;
 p_r2->pos.y=(p_r2->pos.y-0.0013611111376020642);
 p_r2->vel.y-=0.0027222224f;
 }
 }
 { u8 *b2; u32 k;
 b2=BASE(arg0); p_r3=arg0->particles;
 for(k=0;k<arg0->count;k++,p_r3++) {
 SETMAT(b2); lbl_8006DAEC();
 if(p_r3->flags&1) { lbl_8006DBE4(); TRANS(&p_r3->local,&p_r3->pos); }
 lbl_8006DC20();
 } }
{ u32 k; Particle *q; u8 *b3;
 b3=BASE(arg0); q=arg0->particles; limit=0.0001f;
 for(k=0;k<arg0->count;k++,q++) {
 SETMAT(b3); TRANS(&q->local,&loc_8);
 dx=q->pos.x-loc_8.x; loc_14.x=dx;
 len=dx*dx;
 dy=q->pos.y-loc_8.y; loc_14.y=dy;
 len+=dy*dy;
 dz=q->pos.z-loc_8.z; loc_14.z=dz;
 len+=dz*dz;
 if(len>limit) {
 scale=lbl_8006D0B4(limit/len);
 q->pos.x=loc_8.x+(f32)(loc_14.x*scale);
 q->pos.y=loc_8.y+(f32)(loc_14.y*scale);
 q->pos.z=loc_8.z+(f32)(loc_14.z*scale);
 q->prev=q->pos;
 }
 }
 }
 {
 static const Vec3 zero = {0.0f, 0.0f, 0.0f};
 u8 *matrix=arg0->owner->model->data;
 loc_20=zero;
 lbl_8006DBAC((void *)((Vec3 *)(matrix+0x844)));
 mathutil_mtxA_translate_z(0.049f);
 TRANS(&loc_20,&loc_20);
 }
 { u32 k; Particle *q;
 base=BASE(arg0); q=arg0->particles;
 for(k=0;k<arg0->count;k++,q++) {
 if(!(q->flags&1)) {
 dx_r2=q->pos.x-loc_20.x; loc_14.x=dx_r2;
 dy_r2=q->pos.y-loc_20.y; loc_14.y=dy_r2;
 len_r2=dy_r2*dy_r2+(dx_r2*dx_r2);
 dz_r2=q->pos.z-loc_20.z;
 len_r2=dz_r2*dz_r2+len_r2; loc_14.z=dz_r2;
 if(len_r2<0.0025000002f) {
 scale_r2=0.05f/lbl_8006D0B4(len_r2);
 q->pos.x=loc_20.x+(f32)(loc_14.x*scale_r2);
 q->pos.y=loc_20.y+(f32)(loc_14.y*scale_r2);
 q->pos.z=loc_20.z+(f32)(loc_14.z*scale_r2);
 }
 }
 }
 }
 group=arg0->particles;
 for(i_r3=0;i_r3<(arg0->count-1)/3;i_r3++,group+=3) {
 SETMAT(base); TRANS(&group->local,&loc_14);
 group->prev=loc_14;
 loc_14.x=group->pos.x-loc_14.x; loc_14.y=group->pos.y-loc_14.y; loc_14.z=group->pos.z-loc_14.z;
 SETMAT(base); TRANS(&group[1].local,&group[1].pos);
 group[1].pos.x+=loc_14.x; group[1].pos.y+=loc_14.y; group[1].pos.z+=loc_14.z;
 SETMAT(base); TRANS(&group[2].local,&group[2].pos);
 group[2].pos.x+=loc_14.x; group[2].pos.y+=loc_14.y; group[2].pos.z+=loc_14.z;
 group->prev=group->pos; group[1].prev=group[1].pos; group[2].prev=group[2].pos;
 }
 group->prev=group->pos;
 accel=-0.125f;
 p_r4=arg0->particles;
 for(i_r4=0;i_r4<arg0->count;i_r4++,p_r4++) {
 p_r4->vel.x=(accel/p_r4->mass)*(p_r4->pos.x-p_r4->prev.x);
 p_r4->vel.y=(accel/p_r4->mass)*(p_r4->pos.y-p_r4->prev.y);
 p_r4->vel.z=(accel/p_r4->mass)*(p_r4->pos.z-p_r4->prev.z);
 }
 vertices=(u8 *)((s32)fn_80077B14((void *)arg0->handle));
 SETMAT(BASE(arg0));
 { Particle *q; s32 l; u32 k; u16 *link;
 q=arg0->particles;
 for(k=0;k<arg0->count;k++,q++) {
 link=(u16 *)q;
 for(l=0;l<q->count;link++,l++) {
 fn_8006E250((void *)&q->pos,(void *)((Vec3 *)(vertices+(link[2]<<6))));
 }
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef BASE
#undef SETMAT
#undef TRANS
#undef base
/* fzgx:end fn_1_10CC38 */

/* fzgx:begin fn_1_10D2F0 */
/* VIEWS */
void fn_1_10D2F0(Ctx *arg0) {
    u32 i, j, k, pairs, q;
    Elem *p, *e, *a, *b, *c, *last;

    if (arg0 != 0) {
    fn_1_10846C((void *)arg0);

    {
    Elem *initial_p;
    for (i = 0, initial_p = arg0->unk_24; i < arg0->unk_18; i++, initial_p++) {
        if (initial_p->unk_0 & 1) {
            initial_p->unk_0 = 0;
            if (initial_p->v.x > 0.015) {
                initial_p->unk_40 = -0.5f;
                initial_p->unk_1 = 1;
            } else {
                initial_p->unk_40 = -1.0f;
                initial_p->unk_1 = 2;
            }
        } else {
            initial_p->unk_40 = 0.0f;
            initial_p->unk_0 = 1;
            if (initial_p->v.x > 0.045) {
                initial_p->unk_1 = 0;
            } else {
                initial_p->unk_1 = 3;
            }
        }
    }

    }

    {
    Elem *first_e;
    for (i = 0, p = arg0->unk_24; i < arg0->unk_18; i++, p++) {
        for (j = i + 1, first_e = &arg0->unk_24[i] + 1; j < arg0->unk_18; j++, first_e++) {
            if (p->unk_1 > first_e->unk_1) {
                fn_1_128884((void *)p, (void *)first_e, 0x44);
            }
        }
    }

    }

    for (i = 0, p = arg0->unk_24; i < arg0->unk_18; i++, p++) {
        for (j = i + 1, e = &arg0->unk_24[i] + 1; j < arg0->unk_18; j++, e++) {
            if (p->unk_1 == e->unk_1 && p->v.z < e->v.z) {
                fn_1_128884((void *)p, (void *)e, 0x44);
            }
        }
    }

    for (i = 0, p = arg0->unk_24; i < arg0->unk_18; i++, p++) {
        for (j = i + 1, e = &arg0->unk_24[i] + 1; j < arg0->unk_18; j++, e++) {
            if (p->unk_1 == e->unk_1) {
                if (p->v.z > 0.0f && e->v.z > 0.0f) {
                        if (p->v.y > e->v.y) {
                            fn_1_128884((void *)p, (void *)e, 0x44);
                        }
                } else {
                    /* Reload once for both negative-side tests, as retail does. */
                    f32 negative_zero = 0.0f;
                    if (p->v.z < negative_zero && e->v.z < negative_zero) {
                        if (p->v.y < e->v.y) {
                            fn_1_128884((void *)p, (void *)e, 0x44);
                        }
                    }
                }
            }
        }
    }

    b = arg0->unk_24;
    a = b;
    for (k = 0; k < arg0->unk_18; k++) {
        if (a->unk_1 == 1) {
            break;
        }
        a++;
    }
    for (k = 0; k < arg0->unk_18; k++) {
        if (b->unk_1 == 3) {
            break;
        }
        b++;
    }
    a->unk_40 = b->unk_40;
    a->unk_0 = b->unk_0;
    a->w2 = b->w2;
    a->v = b->v;
    a->w1 = b->w1;

    c = arg0->unk_24;
    for (k = 0; k < arg0->unk_18; k++) {
        if (c->unk_1 == 2) {
            break;
        }
        c = c + 1;
    }
    last = &arg0->unk_24[arg0->unk_18 - 1];
    c--;
    c->unk_40 = last->unk_40;
    c->unk_0 = last->unk_0;
    c->w2 = last->w2;
    c->v = last->v;
    c->w1 = last->w1;

    q = arg0->unk_18 >> 2;
    arg0->unk_1C = q * 3 + (q - 1) * 4;
    arg0->unk_28 = (Link_10D2F0 *)((u32)fn_1_4630(lbl_801A6410, arg0->unk_1C * 12, "accessory.c", 0xDF0));

    pairs = 0;
    for (i = 0, p = arg0->unk_24; i < arg0->unk_18 - 1; i++, p++) {
        if (p->unk_1 == (*((p) + (1))).unk_1) {
            (*((arg0->unk_28) + pairs)).a = (u32)p;
            (*((arg0->unk_28) + pairs)).b = (u32)(p + 1);
            (*((arg0->unk_28) + pairs)).d = fn_1_1289BC((void *)p, (void *)(p + 1));
            pairs++;
        }
    }
    for (i = 0, p = arg0->unk_24; i < arg0->unk_18 - q; i++, p++) {
        (*((arg0->unk_28) + pairs)).a = (u32)p;
        (*((arg0->unk_28) + pairs)).b = (u32)(p + q);
        (*((arg0->unk_28) + pairs)).d = fn_1_1289BC((void *)p, (void *)(p + q));
        pairs++;
    }
    }
}
/* fzgx:end fn_1_10D2F0 */

/* fzgx:begin fn_1_10D7D4 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_10D7D4(Work_10D7D4 *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Link *l;
 Node *vn;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *b;
 u32 i2;
 Node *n2;
 Vec3 deltav;
 Vec3 diff;
 Vec3 target;
 Vec3 random;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=(f32)(n2->vel.y*-n2->weight);
 n2->pos.z+=n2->vel.z;
 accessory_node_fall(&n2->pos, &n2->vel);
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len>0.000225f) {
 len=lbl_8006D0B4(0.000225f/len);
 n5->pos.x=target.x+(f32)(dif.x*len);
 n5->pos.y=target.y+(f32)(dif.y*len);
 n5->pos.z=target.z+(f32)(dif.z*len);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.2; vn->vel.y*=0.2; vn->vel.z*=0.2;
 vn->vel.x+=(f64)(0.8*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.8*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.8*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
/* fzgx:end fn_1_10D7D4 */

/* fzgx:begin fn_1_10DDE4 */
/* VIEWS */
void fn_1_10DDE4(Rope_10DDE4 *rope) {
    u32 i;
    u32 m;
    RopeNode_10DDE4 *b;
    RopeNode_10DDE4 *a;
    RopeNode_10DDE4 *p;
    RopeNode_10DDE4 *n;
    s32 last;
    u32 c;
    u32 j;
    RopeNode_10DDE4 *q;
    u32 k;
    u32 rows;
    struct { s32 value; } cols;

    if (rope == NULL) {
        return;
    }
    cols.value = 13;
    if (rope->unk_C->unk_8C == 2) {
        cols.value = 7;
    }
    fn_1_10846C((void *)rope);

    for (i = 0, n = rope->unk_24; i < rope->unk_18; i++, n++) {
        if (n->unk_0 & 1) {
            n->unk_0 = 0;
            n->unk_40 = -1.0f;
        } else {
            n->unk_0 = 1;
            n->unk_40 = 0.0f;
        }
    }

    for (i = 0, a = rope->unk_24; i < rope->unk_18; i++, a++) {
        for (j = i + 1, b = &rope->unk_24[i] + 1; j < rope->unk_18; j++, b++) {
            if (a->unk_0 == 0 && b->unk_0 != 0) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = 0, a = rope->unk_24; i < rope->unk_18; i++, a++) {
        for (j = i + 1, b = &rope->unk_24[i] + 1; j < rope->unk_18; j++, b++) {
            if (a->unk_0 == b->unk_0 && a->unk_10.x < b->unk_10.x) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = 0, a = &rope->unk_24[3]; i < cols.value; i++, a++) {
        for (j = i + 1, b = a + 1; j < cols.value; j++, b++) {
            if (a->unk_10.z > b->unk_10.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    p = rope->unk_24;
    for (i = 0; i < rope->unk_18; i++) {
        if (p->unk_0 != 0 && p[1].unk_0 == 0) {
            break;
        }
        p++;
    }
    p++;

    rows = (rope->unk_18 - (p - rope->unk_24)) / cols.value;
    for (j = 0; j < rows; j++) {
        for (c = 0; c < cols.value; c++) {
            p[c].unk_40 = -(f32)(j + 1) / (rows + 1);
        }
        for (c = 0, n = p; c < cols.value; c++, n++) {
            for (m = c + 1, q = n + 1; m < cols.value; m++, q++) {
                if (n->unk_10.z > q->unk_10.z) {
                    fn_1_128884((void *)n, (void *)q, sizeof(RopeNode_10DDE4));
                }
            }
        }
        p += cols.value;
    }

    rows = (rope->unk_18 - 3) / cols.value;
    rope->unk_1C = rows * (cols.value - 1) + (rows - 1) * cols.value + (cols.value - 1) * 2;
    rope->unk_28 = fn_1_4630(lbl_801A6410, rope->unk_1C * sizeof(Link_10DDE4), "accessory.c", 0xF31);

    last = (u32)cols.value - 1;
    for (i = 0, k = 0, a = &rope->unk_24[3]; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a;
        rope->unk_28[k].unk_4 = a + cols.value + 1;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, a = &rope->unk_24[3]; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a + 1;
        rope->unk_28[k].unk_4 = a + cols.value;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 3, a = &rope->unk_24[3]; i < rope->unk_18 - 1; i++, a++) {
        if ((i - 2) % cols.value != 0) {
            rope->unk_28[k].unk_0 = a;
            rope->unk_28[k].unk_4 = a + 1;
            rope->unk_28[k].unk_8 = fn_1_1289BC((void *)a, (void *)(a + 1));
            k++;
        }
    }
    for (i = 3, a = &rope->unk_24[3]; i < rope->unk_18 - cols.value; i++, a++) {
        rope->unk_28[k].unk_0 = a;
        rope->unk_28[k].unk_4 = a + (u32)cols.value;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)a, (void *)(a + (u32)cols.value));
        k++;
    }
}
/* fzgx:end fn_1_10DDE4 */

/* fzgx:begin fn_1_10E3B4 */
#pragma opt_propagation off

#define INDEX(i) (lbl_1_data_3FFBC[i])

static inline void fn_1_10E3B4_sphere(Work_10E3B4 *arg0, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node_10E3B4 *kn;
 center.x = cx; center.y = cy; center.z = cz;
 lbl_8006DBAC(arg0->owner->model->base + base);
 lbl_8006E1B0(&center, &center);
 for (ki = 0, kn = arg0->nodes; ki < arg0->count; ki++, kn++) {
  if (!(kn->flags & 1)) {
   f32 x, y, z, r;
   x = kn->pos.x; y = kn->pos.y; z = kn->pos.z;
   x -= center.x; y -= center.y; z -= center.z;
   r = (f32)(x * x) + y * y + z * z;
   if (r < radius) {
    psvec_sub_scale_add(&kn->pos, &center, strength * lbl_8006D0E8(r), &diff, &kn->pos);
   }
  }
 }
}

static inline void fn_1_10E3B4_spherec(Work_10E3B4 *arg0, u32 *count, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node_10E3B4 *kn;
 center.x = cx; center.y = cy; center.z = cz;
 lbl_8006DBAC(arg0->owner->model->base + base);
 lbl_8006E1B0(&center, &center);
 for (ki = 0, kn = arg0->nodes; ki < (*count = arg0->count); ki++, kn++) {
  if (!(kn->flags & 1)) {
   f32 x, y, z, r;
   x = kn->pos.x; y = kn->pos.y; z = kn->pos.z;
   x -= center.x; y -= center.y; z -= center.z;
   r = (f32)(x * x) + y * y + z * z;
   if (r < radius) {
    psvec_sub_scale_add(&kn->pos, &center, strength * lbl_8006D0E8(r), &diff, &kn->pos);
   }
  }
 }
}

static inline void fn_1_10E3B4_spherex(Work_10E3B4 *arg0, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node_10E3B4 *kn;
 center.y = cy; center.x = cx; center.z = cz;
 lbl_8006DBAC(arg0->owner->model->base + base);
 lbl_8006E1B0(&center, &center);
 for (ki = 0, kn = arg0->nodes; ki < arg0->count; ki++, kn++) {
  if (!(kn->flags & 1)) {
   f32 x, y, z, r;
   x = kn->pos.x; y = kn->pos.y; z = kn->pos.z;
   x -= center.x; y -= center.y; z -= center.z;
   r = (f32)(x * x) + y * y + z * z;
   if (r < radius) {
    psvec_sub_scale_add(&kn->pos, &center, strength * lbl_8006D0E8(r), &diff, &kn->pos);
   }
  }
 }
}

static inline void fn_1_10E3B4_sphere4(Work_10E3B4 *arg0, u32 count, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node_10E3B4 *kn;
 center.y = cy; center.x = cx; center.z = cz;
 lbl_8006DBAC(arg0->owner->model->base + base);
 lbl_8006E1B0(&center, &center);
 for (ki = count / 4, kn = arg0->nodes; ki < count; ki++, kn++) {
  if (!(kn->flags & 1)) {
   f32 x, y, z, r;
   x = kn->pos.x; y = kn->pos.y; z = kn->pos.z;
   x -= center.x; y -= center.y; z -= center.z;
   r = (f32)(x * x) + y * y + z * z;
   if (r < radius) {
    psvec_sub_scale_add(&kn->pos, &center, strength * lbl_8006D0E8(r), &diff, &kn->pos);
   }
  }
 }
}

#define LINKFIX { \
 f32 inv; \
 f32 r; \
 f32 wa; \
 inv = lbl_8006D118(len, &len); \
 r = lbl_8006D0B4(l->length); \
 len = inv * (len - r); \
 psvec_scale(&delta, len, &delta); \
 wa = a->weight; \
 r = 1.0f / (wa + b->weight); \
 psvec_scale_add(&a->pos, &delta, -wa * r, &a->pos); \
 psvec_scale_add(&b->pos, &delta, b->weight * r, &b->pos); \
}

static inline f32 fn_1_10E3B4_randf(f32 scale) {
 lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
 return scale * ((s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
}

static inline f32 fn_1_10E3B4_rand(void) {
 lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
 return (s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f;
}

#pragma opt_common_subs off

static inline void fn_1_10E3B4_loop0(Work_10E3B4 *arg0) {
 u32 i1;
 Node_10E3B4 *n1;
 for (i1 = 0, n1 = arg0->nodes; i1 < arg0->count; i1++, n1++) {
  lbl_8006DBE4();
  lbl_8006E1B0(&n1->local, &n1->pos);
 }
}

void fn_1_10E3B4(Work_10E3B4 *arg0) {
 u32 li;
 f32 w1;
 u32 i6;
 s32 lim;
 Vec3 delta;
 Node_10E3B4 *fn;
 u32 vi;
 Node_10E3B4 *n3;
 f32 c1a8;
 f32 len;
 u8 *model3;
 Link_10E3B4 *l;
 f32 c68;
 u32 fj;
 u32 fi;
 u32 count;
 Node_10E3B4 *vn;
 s32 kmax;
 u8 *fmodel;
 Node_10E3B4 *a;
 Vec3 random;
 Node_10E3B4 *b;
 u32 i3;
 u32 i2;
 s32 wi;
 Vec3 d;
 Node_10E3B4 *n2;
 f32 g;
 Vec3 push;
 Owner_10E3B4 *owner;
 f32 w2;
 Node_10E3B4 *wn;
 u16 *lp;
 Vec3 target;
 s32 n;
 s32 k;
 Node_10E3B4 *n6;
 if (arg0 && arg0->obj) {
  fn_80077B14(arg0->obj);
  n = (arg0->owner->kind == 2) ? 7 : 13;
  if (arg0->flags & 2) {
   arg0->flags &= ~2;
   owner = arg0->owner;
   lbl_8006DBAC(owner->model->base + INDEX(arg0->index) * 396 + 136);
   lbl_8006DAEC();
   fn_1_10E3B4_loop0(arg0);
   lbl_8006DC20();
  }
  for (i2 = 0, n2 = arg0->nodes; i2 < arg0->count; i2++, n2++) {
   if (!(n2->flags & 1)) {
    n2->prev = n2->pos;
    n2->pos.y -= 0.5 * (g = 0.0027222224f);
    n2->vel.y -= 0.0027222224f;
    if (n2->pos.y < 0.01f) {
     n2->flags |= 4;
     psvec_scale_add(&n2->pos, &n2->vel, 0.03f, &n2->pos);
    } else {
     n2->flags &= ~4;
     psvec_add(&n2->pos, &n2->vel, &n2->pos);
    }
   }
  }
  owner = arg0->owner;
  model3 = owner->model->base + INDEX(arg0->index) * 396;
  for (i3 = 0, n3 = arg0->nodes; i3 < arg0->count; i3++, n3++) {
   lbl_8006DBAC(model3 + 136);
   lbl_8006DAEC();
   if (n3->flags & 1) {
    lbl_8006DBE4();
    lbl_8006E1B0(&n3->local, &n3->pos);
   }
   lbl_8006DC20();
  }
  kmax = (arg0->owner->kind == 2) ? 2 : 4;
  lim = (n - 1) * 2;
  c68 = 0.0f;
  for (k = 0; k < kmax; k++) {
   for (li = 0, l = arg0->links; li < arg0->linkCount; li++, l++) {
    a = l->a; b = l->b;
    if (a && b) {
     f32 x, y, z;
     psvec_sub(&a->pos, &b->pos, &delta);
     x = delta.x; y = delta.y; z = delta.z;
     len = (f32)(x * x) + y * y + z * z;
     if (len - 0.0001f > l->length) LINKFIX
     if (len + 0.001f < l->length && (s32)li < lim) LINKFIX
     if ((y = a->pos.y) < 0.01f || b->pos.y < 0.01f) {
      if (y < 0.01f) a->pos.y = 0.01f;
      if (b->pos.y < 0.01f) b->pos.y = 0.01f;
      psvec_sub(&a->pos, &b->pos, &delta);
      x = delta.x * delta.x;
      x += delta.y * delta.y;
      x += delta.z * delta.z;
      len = x;
      LINKFIX
     }
    }
   }
   c1a8 = 0.115f;
   fn_1_10E3B4_sphere(arg0, 0x214, c1a8, c68, c68, 0.020164002f, 0.142f);
   fn_1_10E3B4_spherec(arg0, &count, 0x1948, c68, c68, c68, 0.017160999f, 0.131f);
   if (arg0->owner->kind == 2) {
    fn_1_10E3B4_sphere4(arg0, count, 0x1c60, 0.08f, 0.0f, 0.0f, 0.0225f, 0.15f);
    fn_1_10E3B4_sphere4(arg0, arg0->count, 0x241c, 0.08f, 0.0f, 0.0f, 0.0225f, 0.15f);
    fn_1_10E3B4_sphere4(arg0, arg0->count, 0x1dec, 0.08f, 0.0f, 0.0f, 0.0225f, 0.15f);
    fn_1_10E3B4_sphere4(arg0, arg0->count, 0x1dec, 0.2f, 0.0f, 0.0f, 0.040000003f, 0.2f);
    fn_1_10E3B4_sphere4(arg0, arg0->count, 0x25a8, 0.08f, 0.0f, 0.0f, 0.0225f, 0.15f);
    fn_1_10E3B4_sphere4(arg0, arg0->count, 0x25a8, 0.2f, 0.0f, 0.0f, 0.040000003f, 0.2f);
   } else {
    fn_1_10E3B4_spherex(arg0, 0x1c60, 0.027f, 0.0f, 0.0f, 0.016384002f, 0.128f);
    fn_1_10E3B4_spherex(arg0, 0x1c60, 0.141f, 0.0f, 0.0f, 0.0169f, 0.13f);
    fn_1_10E3B4_spherex(arg0, 0x241c, 0.027f, 0.0f, 0.0f, 0.016384002f, 0.128f);
    fn_1_10E3B4_spherex(arg0, 0x241c, 0.141f, 0.0f, 0.0f, 0.0169f, 0.13f);
    fn_1_10E3B4_spherex(arg0, 0x1dec, 0.051f, 0.0f, 0.0f, 0.014161001f, 0.119f);
    fn_1_10E3B4_spherex(arg0, 0x1dec, 0.183f, 0.0f, 0.0f, 0.013225f, 0.115f);
    fn_1_10E3B4_spherex(arg0, 0x1dec, 0.298f, 0.0f, 0.0f, 0.0225f, 0.15f);
    fn_1_10E3B4_spherex(arg0, 0x25a8, 0.051f, 0.0f, 0.0f, 0.014161001f, 0.119f);
    fn_1_10E3B4_spherex(arg0, 0x25a8, 0.183f, 0.0f, 0.0f, 0.013225f, 0.115f);
    fn_1_10E3B4_spherex(arg0, 0x25a8, 0.298f, 0.0f, 0.0f, 0.0225f, 0.15f);
   }
  }
  if (strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)), "CAR_SEL") == 0 ||
      strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)), "SEL_WAIT") == 0) {
   for (wi = 0, wn = arg0->nodes; wi < arg0->count; wi++, wn++) {
    if (wi >= 3) {
     s32 m = (wi - 3) % n;
     w2 = 0.2f + (0.8f * m) / 9.0f;
     w1 = 0.2f + (0.8f * (n - m)) / 9.0f;
    } else {
     w1 = 0.0f;
    }
    wn->vel.x *= 0.8; wn->vel.y *= 0.8; wn->vel.z *= 0.8;
    wn->vel.x += (f64)(0.2 * (wn->pos.x - wn->prev.x));
    wn->vel.y += (f64)(0.2 * (wn->pos.y - wn->prev.y));
    wn->vel.z += (f64)(0.2 * (wn->pos.z - wn->prev.z));
    wn->vel.x -= (f32)(w1 * fn_1_10E3B4_randf(0.0012f));
    wn->vel.y += (f32)(w1 * (fn_1_10E3B4_randf(0.0048f) - 0.001f));
    wn->vel.z += (f32)(w1 * (0.0006f * lbl_8006D188((-32768.0f + (65536.0f * ((wi + lbl_801A66A0) % 39)) / 39.0f))));
    wn->vel.z += (f32)(w2 * (0.0012f * fn_1_10E3B4_rand()));
    wn->vel.y += (f32)(w2 * (0.002f * fn_1_10E3B4_rand()));
    wn->vel.x += (f32)(w2 * (0.0006f * lbl_8006D188((-32768.0f + (65536.0f * ((wi + lbl_801A66A0) % 29)) / 29.0f))));
   }
  } else {
   if (lbl_801A66A0 % 60 < 20) {
    owner = arg0->owner;
    lbl_8006DBAC(owner->model->base + INDEX(arg0->index) * 396 + 136);
    lbl_8006DAEC();
    for (i6 = 0, n6 = arg0->nodes; i6 < arg0->count; i6++, n6++) {
     if (!(n6->flags & 4)) {
      lbl_8006DBE4();
      lbl_8006E1B0(&n6->local, &target);
      psvec_sub(&n6->pos, &target, &push);
      lbl_8006D668(&push);
      psvec_scale_add(&n6->vel, &push, -0.001f, &n6->vel);
     }
    }
    lbl_8006DC20();
   }
   for (vi = 0, vn = arg0->nodes; vi < arg0->count; vi++, vn++) {
    fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
    psvec_scale(&vn->vel, 0.55f, &vn->vel);
    psvec_sub(&vn->pos, &vn->prev, &d);
    psvec_scale_add(&vn->vel, &d, 0.4f, &vn->vel);
    if (vn->flags & 4) {
     psvec_scale_add(&vn->vel, &random, 0.1f, &vn->vel);
    } else {
     psvec_scale_add(&vn->vel, &random, 0.5f, &vn->vel);
    }
   }
  }
  fn_1_108128((void *)arg0, n);
  fmodel = fn_80077B14(arg0->obj);
  owner = arg0->owner;
  lbl_8006DBAC(owner->model->base + INDEX(arg0->index) * 396 + 136);
  for (fi = 0, fn = arg0->nodes; fi < arg0->count; fi++, fn++) {
   for (fj = 0, lp = (u16 *)fn; (s32)fj < fn->count; lp++, fj++) {
    fn_8006E250(&fn->pos, (Vec3 *)(fmodel + (lp[2] << 6)));
   }
  }
 }
}

#pragma opt_common_subs reset
#undef INDEX
#undef LINKFIX
#pragma opt_propagation reset
/* fzgx:end fn_1_10E3B4 */

/* fzgx:begin fn_1_110008 */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/shared_types.h */

/* game/main_rel/shared_types.h: inlined above */

/* game/main_rel/shared_types.h: inlined above */

/* end game/main_rel/accessory_types.h */

void fn_1_110008(fn_1_10D2F0_Obj *obj) {
    u32 i;
    u32 j;
    u32 m;
    fn_1_10D2F0_Entry *b;
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *e;
    u32 n;
    u32 rows;
    u32 k;
    u32 c;
    fn_1_10D2F0_Entry *p;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_0 = 0;
                p->unk_40 = -1.0f;
            } else {
                p->unk_0 = 1;
                p->unk_40 = 0.0f;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == 0 && b->unk_0 != 0) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == b->unk_0 && a->unk_10.x < b->unk_10.x) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        for (i = 0, a = obj->unk_24; i < 9; i++, a++) {
            for (j = i + 1, b = a + 1; j < 9; j++, b++) {
                if (a->unk_10.z > b->unk_10.z) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        n = obj->unk_18;
        for (i = 0; i < n; i++, a++) {
            if (a->unk_0 != 0 && a[1].unk_0 == 0) {
                break;
            }
        }
        a++;
        rows = (n - (a - obj->unk_24)) / 9;

        for (k = 0; k < rows; k++, a += 9) {
            for (i = 0; i < 9; i++) {
                a[i].unk_40 = -(f32)(k + 1) / (rows + 1);
            }
            b = a;
            for (i = 0; i < 9; i++, b++) {
                for (m = i + 1, e = b + 1; m < 9; m++, e++) {
                    if (b->unk_10.z > e->unk_10.z) {
                        fn_1_128884((void *)b, (void *)e, sizeof(fn_1_10D2F0_Entry));
                    }
                }
            }
        }

        obj->unk_1C = (obj->unk_18 / 9) * 8 + (obj->unk_18 / 9 - 1) * 9;
        obj->unk_28 = fn_1_4630(lbl_801A6410, obj->unk_1C * sizeof(fn_1_10D2F0_Link), "accessory.c", 4277);

        c = 0;
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 1; i++, a++) {
            if ((i + 1) % 9 != 0) {
                obj->unk_28[c].a = a;
                obj->unk_28[c].b = a + 1;
                obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 1));
                c++;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 9; i++, a++) {
            obj->unk_28[c].a = a;
            obj->unk_28[c].b = a + 9;
            obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 9));
            c++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_110008 */

/* fzgx:begin fn_1_110478 */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#pragma opt_propagation off

#define INDEX(i) (lbl_1_data_3FFBC[i])

static inline void fn_1_110478_sphere(Work_110478 *arg0, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node *kn;
 center.x=cx; center.y=cy; center.z=cz;
 lbl_8006DBAC((Vec3 *)(arg0->owner->model->base+base));
 lbl_8006E1B0(&center,&center);
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) {
 if(!(kn->flags&1)) {
 f32 x,y,z,r;
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z;
 x-=center.x; y-=center.y; z-=center.z;
 r=(f32)(x*x)+y*y+z*z;
 if(r<radius) {
 psvec_sub_scale_add(&kn->pos,&center,strength*lbl_8006D0E8(r),&diff,&kn->pos);
 }
 }
 }
}

#define SPHERE(BASE, CX, CY, CZ, RADIUS, STRENGTH) fn_1_110478_sphere(arg0, BASE, CX, CY, CZ, RADIUS, STRENGTH);

static inline f32 fn_1_110478_measure(Node *a, Node *b, Vec3 *dp) {
 f32 x;
 f32 y;
 f32 z;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 (*dp).x=x; (*dp).y=y; (*dp).z=z;
 { f32 d; d=x*x; d+=y*y; d+=z*z; return d; }
}

#define delta (*dp)

static inline void fn_1_110478_constrain(Node *a, Node *b, Link *l, f32 *len, Vec3 *dp) {
 f32 wb;
 f32 inv;
 f32 s;
 f32 wa;
 f32 fb;
 f32 r;
 f32 fa;
 f32 cx;
 f32 cy;
 f32 cz;
 f32 x;
 inv=lbl_8006D118(*len,len);
 r=lbl_8006D0B4(l->length);
 s=inv*(*len-r);
 *len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=(1.0f)/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
}

#define LINKFIX { fn_1_110478_constrain(a,b,l,&len,dp); }

#undef delta

static inline f32 fn_1_110478_randf(f32 scale) {
 lbl_801A63C0=lbl_801A63C0*0x676A4B6B+0x33CB;
 return scale*((s32)((lbl_801A63C0>>16)&0x7FFF)/(32767.0f));
}

static inline void fn_1_110478_loop0(Work_110478 *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n1->local,&n1->pos);
 }
}

void fn_1_110478(Work_110478 *arg0) {
 u32 wi;
 u8 *fmodel;
 u32 li;
 u32 k;
 Link *l;
 Node *kn;
 Node *fn;
 Node *n3;
 Node *a;
 u32 fj;
 u8 *model3;
 u32 ki;
 f32 c1a8;
 u32 fi;
 u32 i3;
 u32 vi;
 u16 *lp;
 Node *n2;
 u32 i2;
 f32 c68;
 Node *vn;
 f32 c1d0;
 f32 c1dc;
 u32 i6;
 Node *n6;
 u8 *model6;
 Node *b;
 Node *wn;
 Owner_110478 *owner;
 Vec3 deltav;
 Vec3 random;
 Vec3 push;
 Vec3 target;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 fn_80077B14(arg0->obj);
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 owner=arg0->owner;
 lbl_8006DBAC((Vec3 *)(owner->model->base+INDEX(arg0->index)*396+136));
 lbl_8006DAEC();
 fn_1_110478_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=(0.0013611111376020642);
 n2->vel.y-=(0.0027222224f);
 }
 }
 owner=arg0->owner;
 model3=owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((Vec3 *)(model3+136));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n3->local,&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 c68=(0.0f); c1a8=(0.115f); c1d0=(0.027f); c1dc=(0.141f);
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y;
 f32 wa;
 f32 x;
 f32 inv;
 f32 s;
 f32 cz;
 f32 cy;
 f32 r;
 f32 cx;
 f32 fa;
 f32 wb;
 f32 z;
 f32 fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-(0.0001f)>l->length) LINKFIX
 if((y=a->pos.y)<(0.0f) || b->pos.y<(0.0f)) {
 if(y<(0.0f)) a->pos.y=(1e-05f);
 if(b->pos.y<(0.0f)) b->pos.y=(1e-05f);
 len=fn_1_110478_measure(a,b,dp);
 LINKFIX
 }
 }
 }
 SPHERE(532,c1a8,c68,c68,(0.020164002f),(0.142f))
 SPHERE(0x1948,c68,c68,c68,(0.017160999f),(0.131f))
 SPHERE(0x1c60,c1d0,c68,c68,(0.016384002f),(0.128f))
 SPHERE(0x1c60,c1dc,c68,c68,(0.0169f),(0.13f))
 SPHERE(0x241c,c1d0,c68,c68,(0.016384002f),(0.128f))
 SPHERE(0x241c,c1dc,c68,c68,(0.0169f),(0.13f))
 }
 if(strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)),"SEL_DEC")!=0 && strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)),"WIN_1ST")!=0) {
 for(wi=0,wn=arg0->nodes;wi<arg0->count;wi++,wn++) {
 f32 w1,w2;
 u32 m;
 m=wi%9;
 w2=(0.2f)+((0.8f)*m)/(9.0f);
 w1=(0.2f)+((0.8f)*(9-m))/(9.0f);
 wn->vel.x*=(0.8); wn->vel.y*=(0.8); wn->vel.z*=(0.8);
 wn->vel.x+=(f64)((0.2)*(wn->pos.x-wn->prev.x));
 wn->vel.y+=(f64)((0.2)*(wn->pos.y-wn->prev.y));
 wn->vel.z+=(f64)((0.2)*(wn->pos.z-wn->prev.z));
 wn->vel.x-=(f32)(w1*fn_1_110478_randf(0.0012f));
 wn->vel.y+=(f32)(w1*fn_1_110478_randf(0.0028f));
 wn->vel.z+=(f32)(w1*((0.0006f)*lbl_8006D188(((-32768.0f)+((65536.0f)*((wi+lbl_801A66A0)%39))/(39.0f)))));
 wn->vel.z+=(f32)(w2*fn_1_110478_randf(0.0012f));
 wn->vel.y+=(f32)(w2*fn_1_110478_randf(0.0023f));
 wn->vel.x+=(f32)(w2*((0.0006f)*lbl_8006D188(((-32768.0f)+((65536.0f)*((wi+lbl_801A66A0)%29))/(29.0f)))));
 }
 } else {
 if(lbl_801A66A0%60<20) {
 owner=arg0->owner;
 model6=owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 lbl_8006DBAC((Vec3 *)(model6+136));
 lbl_8006E1B0(&n6->local,&target);
 push.x=n6->pos.x-target.x;
 push.y=n6->pos.y-target.y;
 push.z=n6->pos.z-target.z;
 lbl_8006D668(&push);
 n6->vel.x-=(f32)((0.001f)*push.x);
 n6->vel.y-=(f32)((0.001f)*push.y);
 n6->vel.z-=(f32)((0.001f)*push.z);
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=(0.8); vn->vel.y*=(0.8); vn->vel.z*=(0.8);
 vn->vel.x+=(f64)((0.2)*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)((0.2)*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)((0.2)*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)((0.5)*random.x); vn->vel.y+=(f64)((0.5)*random.y); vn->vel.z+=(f64)((0.5)*random.z);
 }
 }
 fn_1_108128((void *)arg0,9);
 fmodel=fn_80077B14(arg0->obj);
 owner=arg0->owner;
 lbl_8006DBAC((Vec3 *)(owner->model->base+INDEX(arg0->index)*396+136));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((Vec3 *)&fn->pos,(Vec3 *)(fmodel+(lp[2]<<6)));
 }
 }
 }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef SPHERE
#undef LINKFIX
#pragma opt_propagation reset
#undef delta
/* fzgx:end fn_1_110478 */

/* fzgx:begin fn_1_111510 */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/shared_types.h */

/* game/main_rel/shared_types.h: inlined above */

/* game/main_rel/shared_types.h: inlined above */

/* end game/main_rel/accessory_types.h */

void fn_1_111510(fn_1_10D2F0_Obj *obj) {
    u32 i;
    u32 j;
    u32 m;
    fn_1_10D2F0_Entry *b;
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *e;
    u32 n;
    u32 rows;
    u32 k;
    u32 c;
    fn_1_10D2F0_Entry *p;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_0 = 0;
                p->unk_40 = -1.0f;
            } else {
                p->unk_0 = 1;
                p->unk_40 = 0.0f;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == 0 && b->unk_0 != 0) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == b->unk_0 && a->unk_10.x < b->unk_10.x) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        for (i = 0, a = obj->unk_24; i < 9; i++, a++) {
            for (j = i + 1, b = a + 1; j < 9; j++, b++) {
                if (a->unk_10.z > b->unk_10.z) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        n = obj->unk_18;
        for (i = 0; i < n; i++, a++) {
            if (a->unk_0 != 0 && a[1].unk_0 == 0) {
                break;
            }
        }
        a++;
        rows = (n - (a - obj->unk_24)) / 9;

        for (k = 0; k < rows; k++, a += 9) {
            for (i = 0; i < 9; i++) {
                a[i].unk_40 = -(f32)(k + 1) / (rows + 1);
            }
            b = a;
            for (i = 0; i < 9; i++, b++) {
                for (m = i + 1, e = b + 1; m < 9; m++, e++) {
                    if (b->unk_10.z > e->unk_10.z) {
                        fn_1_128884((void *)b, (void *)e, sizeof(fn_1_10D2F0_Entry));
                    }
                }
            }
        }

        obj->unk_1C = (obj->unk_18 / 9) * 8 + (obj->unk_18 / 9 - 1) * 9;
        obj->unk_28 = fn_1_4630(lbl_801A6410, obj->unk_1C * sizeof(fn_1_10D2F0_Link), "accessory.c", 4596);

        c = 0;
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 1; i++, a++) {
            if ((i + 1) % 9 != 0) {
                obj->unk_28[c].a = a;
                obj->unk_28[c].b = a + 1;
                obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 1));
                c++;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 9; i++, a++) {
            obj->unk_28[c].a = a;
            obj->unk_28[c].b = a + 9;
            obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 9));
            c++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_111510 */

/* fzgx:begin fn_1_111980 */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#pragma opt_propagation off

#define INDEX(i) (lbl_1_data_3FFBC[i])

static inline void fn_1_111980_sphere(Work_111980 *arg0, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node *kn;
 center.x=cx; center.y=cy; center.z=cz;
 lbl_8006DBAC((Vec3 *)(arg0->owner->model->base+base));
 lbl_8006E1B0(&center,&center);
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) {
 if(!(kn->flags&1)) {
 f32 x,y,z,r;
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z;
 x-=center.x; y-=center.y; z-=center.z;
 r=(f32)(x*x)+y*y+z*z;
 if(r<radius) {
 psvec_sub_scale_add(&kn->pos,&center,strength*lbl_8006D0E8(r),&diff,&kn->pos);
 }
 }
 }
}

#define SPHERE(BASE, CX, CY, CZ, RADIUS, STRENGTH) fn_1_111980_sphere(arg0, BASE, CX, CY, CZ, RADIUS, STRENGTH);

static inline f32 fn_1_111980_measure(Node *a, Node *b, Vec3 *dp) {
 f32 x;
 f32 y;
 f32 z;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 (*dp).x=x; (*dp).y=y; (*dp).z=z;
 { f32 d; d=x*x; d+=y*y; d+=z*z; return d; }
}

#define delta (*dp)

static inline void fn_1_111980_constrain(Node *a, Node *b, Link *l, f32 *len, Vec3 *dp) {
 f32 wb;
 f32 inv;
 f32 s;
 f32 wa;
 f32 fb;
 f32 r;
 f32 fa;
 f32 cx;
 f32 cy;
 f32 cz;
 f32 x;
 inv=lbl_8006D118(*len,len);
 r=lbl_8006D0B4(l->length);
 s=inv*(*len-r);
 *len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=(1.0f)/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
}

#define LINKFIX { fn_1_111980_constrain(a,b,l,&len,dp); }

#undef delta

static inline f32 fn_1_111980_randf(f32 scale) {
 lbl_801A63C0=lbl_801A63C0*0x676A4B6B+0x33CB;
 return scale*((s32)((lbl_801A63C0>>16)&0x7FFF)/(32767.0f));
}

static inline void fn_1_111980_loop0(Work_111980 *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n1->local,&n1->pos);
 }
}

void fn_1_111980(Work_111980 *arg0) {
 u32 wi;
 u8 *fmodel;
 u32 li;
 u32 k;
 Link *l;
 Node *kn;
 Node *fn;
 Node *n3;
 Node *a;
 u32 fj;
 u8 *model3;
 u32 ki;
 f32 c1a8;
 u32 fi;
 u32 i3;
 u32 vi;
 u16 *lp;
 Node *n2;
 u32 i2;
 f32 c68;
 Node *vn;
 f32 c1d0;
 f32 c1dc;
 f32 c1e8;
 f32 c1f4;
 f32 c1fc;
 u32 i6;
 Node *n6;
 u8 *model6;
 Node *b;
 Node *wn;
 Owner_110478 *owner;
 Vec3 deltav;
 Vec3 random;
 Vec3 push;
 Vec3 target;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 fn_80077B14(arg0->obj);
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 owner=arg0->owner;
 lbl_8006DBAC((Vec3 *)(owner->model->base+INDEX(arg0->index)*396+136));
 lbl_8006DAEC();
 fn_1_111980_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=(0.0013611111376020642);
 n2->vel.y-=(0.0027222224f);
 }
 }
 owner=arg0->owner;
 model3=owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((Vec3 *)(model3+136));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n3->local,&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 c68=(0.0f); c1a8=(0.115f); c1d0=(0.027f); c1dc=(0.141f); c1e8=(0.051f); c1f4=(0.183f); c1fc=(0.298f);
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y;
 f32 wa;
 f32 x;
 f32 inv;
 f32 s;
 f32 cz;
 f32 cy;
 f32 r;
 f32 cx;
 f32 fa;
 f32 wb;
 f32 z;
 f32 fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-(0.0001f)>l->length) LINKFIX
 if((y=a->pos.y)<(0.0f) || b->pos.y<(0.0f)) {
 if(y<(0.0f)) a->pos.y=(1e-05f);
 if(b->pos.y<(0.0f)) b->pos.y=(1e-05f);
 len=fn_1_111980_measure(a,b,dp);
 LINKFIX
 }
 }
 }
 SPHERE(532,c1a8,c68,c68,(0.020164002f),(0.142f))
 SPHERE(0x1948,c68,c68,c68,(0.017160999f),(0.131f))
 SPHERE(0x1c60,c1d0,c68,c68,(0.021904001f),(0.148f))
 SPHERE(0x1c60,c1dc,c68,c68,(0.028900001f),(0.17f))
 SPHERE(0x241c,c1d0,c68,c68,(0.021904001f),(0.148f))
 SPHERE(0x241c,c1dc,c68,c68,(0.028900001f),(0.17f))
 SPHERE(0x1dec,c1e8,c68,c68,(0.014161001f),(0.119f))
 SPHERE(0x1dec,c1f4,c68,c68,(0.013225f),(0.115f))
 SPHERE(0x1dec,c1fc,c68,c68,(0.010000001f),(0.1f))
 SPHERE(0x25a8,c1e8,c68,c68,(0.014161001f),(0.119f))
 SPHERE(0x25a8,c1f4,c68,c68,(0.013225f),(0.115f))
 SPHERE(0x25a8,c1fc,c68,c68,(0.010000001f),(0.1f))
 }
 if(strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)),"CAR_SEL")==0 || strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)),"SEL_WAIT_01")==0 || strcmp((void *)(fn_1_950E8(&arg0->owner->unk148)),"SEL_WAIT")==0) {
 for(wi=0,wn=arg0->nodes;wi<arg0->count;wi++,wn++) {
 f32 w1,w2;
 u32 m;
 m=wi%9;
 w2=(0.2f)+((0.8f)*m)/(9.0f);
 w1=(0.2f)+((0.8f)*(9-m))/(9.0f);
 wn->vel.x*=(0.8); wn->vel.y*=(0.8); wn->vel.z*=(0.8);
 wn->vel.x+=(f64)((0.2)*(wn->pos.x-wn->prev.x));
 wn->vel.y+=(f64)((0.2)*(wn->pos.y-wn->prev.y));
 wn->vel.z+=(f64)((0.2)*(wn->pos.z-wn->prev.z));
 wn->vel.x-=(f32)(w1*fn_1_111980_randf(0.0012f));
 wn->vel.y+=(f32)(w1*fn_1_111980_randf(0.0028f));
 wn->vel.z+=(f32)(w1*((0.0006f)*lbl_8006D188(((-32768.0f)+((65536.0f)*((wi+lbl_801A66A0)%39))/(39.0f)))));
 wn->vel.z+=(f32)(w2*fn_1_111980_randf(0.0012f));
 wn->vel.y+=(f32)(w2*fn_1_111980_randf(0.0023f));
 wn->vel.x+=(f32)(w2*((0.0006f)*lbl_8006D188(((-32768.0f)+((65536.0f)*((wi+lbl_801A66A0)%29))/(29.0f)))));
 }
 } else {
 if(lbl_801A66A0%90<20) {
 owner=arg0->owner;
 model6=owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 lbl_8006DBAC((Vec3 *)(model6+136));
 lbl_8006E1B0(&n6->local,&target);
 push.x=n6->pos.x-target.x;
 push.y=n6->pos.y-target.y;
 push.z=n6->pos.z-target.z;
 lbl_8006D668(&push);
 n6->vel.x-=(f32)((0.001f)*push.x);
 n6->vel.y-=(f32)((0.001f)*push.y);
 n6->vel.z-=(f32)((0.001f)*push.z);
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=(0.8); vn->vel.y*=(0.8); vn->vel.z*=(0.8);
 vn->vel.x+=(f64)((0.2)*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)((0.2)*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)((0.2)*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)((0.5)*random.x); vn->vel.y+=(f64)((0.5)*random.y); vn->vel.z+=(f64)((0.5)*random.z);
 }
 }
 fn_1_108128((void *)arg0,9);
 fmodel=fn_80077B14(arg0->obj);
 owner=arg0->owner;
 lbl_8006DBAC((Vec3 *)(owner->model->base+INDEX(arg0->index)*396+136));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((Vec3 *)&fn->pos,(Vec3 *)(fmodel+(lp[2]<<6)));
 }
 }
 }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef SPHERE
#undef LINKFIX
#pragma opt_propagation reset
#undef delta
/* fzgx:end fn_1_111980 */

/* fzgx:begin fn_1_112F40 */
/* VIEWS */
#define lbl_1_bss_38458 (*(Obj_1_bss_38458_Target_L * *)&lbl_1_bss_38458)
#define lbl_1_bss_38460 (*(Obj_1_bss_38460_L *)&lbl_1_bss_38460)
#define lbl_1_bss_3BE0 (*(Obj_1_bss_3BE0_Target_L * *)&lbl_1_bss_3BE0)
#define lbl_1_bss_3C00 ((u8 *)&lbl_1_bss_3C00)
#define lbl_1_bss_3C30 (*(Obj_1_bss_3C30_L *)&lbl_1_bss_3C30)
#define lbl_1_bss_4B9CC (*(Obj_1_bss_4B9CC_L *)&lbl_1_bss_4B9CC)
#define lbl_1_bss_4C688 (*(Obj_1_bss_4C688_L *)&lbl_1_bss_4C688)
#define lbl_1_bss_6C7A4 (*(Obj_1_bss_6C7A4_L *)&lbl_1_bss_6C7A4)
#define lbl_1_bss_6D838 (*(Obj_1_bss_6D838_Target_L * *)&lbl_1_bss_6D838)
#define lbl_1_bss_6EAB4 (*(Obj_1_bss_6EAB4_L *)&lbl_1_bss_6EAB4)
#define lbl_1_bss_7B180 (*(Obj_1_bss_7B180_L *)&lbl_1_bss_7B180)
#define lbl_1_bss_7EFD8 (*(Obj_1_bss_7EFD8_L *)&lbl_1_bss_7EFD8)
#define lbl_1_bss_7F0C0 (*(Obj_1_bss_7F0C0_L *)&lbl_1_bss_7F0C0)
#define lbl_1_bss_85250 (*(Obj_1_bss_85250_L *)&lbl_1_bss_85250)
#define lbl_1_bss_85280 (*(Obj_1_bss_85280_L *)&lbl_1_bss_85280)
#define lbl_1_bss_86ED0 (*(Obj_1_bss_86ED0_L *)&lbl_1_bss_86ED0)
#define lbl_1_bss_88B50 (*(Obj_1_bss_88B50_L *)&lbl_1_bss_88B50)
#define lbl_1_bss_89750 (*(Obj_1_bss_89750_L *)&lbl_1_bss_89750)
#define lbl_1_bss_89760 (*(Obj_1_bss_89760_L *)&lbl_1_bss_89760)
#define lbl_1_bss_89770 (*(Obj_1_bss_89770_L *)&lbl_1_bss_89770)
#define lbl_1_bss_8B3A0 (*(Obj_1_bss_8B3A0_L *)&lbl_1_bss_8B3A0)
#define lbl_1_bss_9F8 (*(Obj_1_bss_9F8_L *)&lbl_1_bss_9F8)
#define lbl_1_bss_F68 (*(Obj_1_bss_F68_Target_L * *)&lbl_1_bss_F68)
#define lbl_1_data_2A7E0 (*(Obj_1_data_2A7E0_L *)&lbl_1_data_2A7E0)
#define lbl_1_data_3C7B8 (*(char (*)[0xA])&lbl_1_data_3C7B8)
#define lbl_1_data_3D544 (*(Obj_1_data_3D544_L *)&lbl_1_data_3D544)
#define lbl_1_data_3F284 (*(Obj_1_bss_85280_L *)&lbl_1_data_3F284)
#define lbl_1_data_3F28C (*(Obj_1_data_3F28C_L *)&lbl_1_data_3F28C)
#define lbl_1_data_3F2EC (*(Obj_1_data_3F2EC_L *)&lbl_1_data_3F2EC)
#define lbl_1_data_5730 (*(char (*)[0xC])&lbl_1_data_5730)
#define lbl_801A6410 (*(void * *)&lbl_801A6410)
/* begin game/main_rel/accessory_types.h (fork-deltawave784/windows-and-types@f88123fa) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin rel/main_rel/globals.h (fork-deltawave784/windows-and-types@f88123fa) */

#define REL_MAIN_REL_GLOBALS_H

// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the

// module's disassembly (matched or not). Field names are offsets until the librarian names them;

// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}

// typedefs.json decl override

// lbl_1_data_2A7E0: .data size 0xF8, referenced by 99 functions, shape {'object': 160}

// object reached through lbl_1_data_2A7E0.unk_3C

// lbl_1_bss_3C30: .bss size 0x14BC, referenced by 95 functions, shape {'object': 411}

// lbl_1_bss_8B3A0: .bss size 0x14C, referenced by 87 functions, shape {'object': 253}

// object reached through lbl_1_bss_8B3A0.unk_A4

// lbl_1_bss_3BE0: .bss size 0x4, referenced by 77 functions, shape {'object': 259, 'pointer': 61}

// lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 304}

// lbl_1_bss_7F0C0: .bss size 0x5360, referenced by 66 functions, shape {'object': 191}

// pinned 2026-10-20 (librarian pass 15): the access analysis drops the 0xF8..0x258 fields, which spline.c's matched fn_1_F9F2C names (pad_25A)

// typedefs.json decl override

// lbl_1_bss_6D838: .bss size 0x4, referenced by 66 functions, shape {'object': 72, 'pointer': 33}

// array of 0x620-byte records

// lbl_1_bss_3C00: .bss size 0x4, referenced by 58 functions, shape {'object': 2442}

// Declared as an incomplete u8 array, never a scalar: a 1-byte (or 4-byte) declared object makes MWCC's alias analysis treat

// every access through &lbl_1_bss_3C00 + off as one location and reuse stored values where retail reloads (fn_1_3DE80).

// lbl_1_bss_3C00 is the first object (a byte, 3 bytes of alignment to 3C04) of the retail TU whose .bss runs 0x3C00..0x38450

// (text ~0x2C908..0x40F54: functions now filed in stcoli.c, burner.c and game.c). It is NOT one struct: MWCC addresses every

// object of that TU off this section base, so a function that touches two or more of them loads `addi rB, lbl_1_bss_3C00@l`

// and reaches each object at its own offset (pointer needed: `addi rX, rB, off`). Never cast &lbl_1_bss_3C00 to a cluster view:

// define the TU's objects in retail order (fixup_layout.tu_section_layout); each object keeps its own extern (globals.h, game.h).

// Obj_1_bss_3C00: LEGACY VIEW ONLY, kept so saved attempt bodies that cast &lbl_1_bss_3C00 to it still compile as seeds.

// It is NOT the type of lbl_1_bss_3C00 (that stays the incomplete u8 array below) and not one retail object: it overlays

// the TU's separate .bss objects 3C00..; offsets come from base-relative loads/stores in retail. Never declare the symbol

// with it and do not write new code against it: address the TU's real objects (globals.h, game.h) instead.

// typedefs.json decl override

// lbl_1_bss_38458: .bss size 0x4, referenced by 43 functions, shape {'object': 62, 'pointer': 9}

// lbl_1_bss_F68: .bss size 0x4, referenced by 42 functions, shape {'object': 140, 'pointer': 7}

// lbl_1_data_1D628: .data size 0x4, referenced by 41 functions, shape {'object': 189}

// lbl_1_bss_4B9CC: .bss size 0x5C, referenced by 38 functions, shape {'object': 237}

// lbl_1_bss_6EA98: .bss size 0x4, referenced by 33 functions, shape {'object': 584}

// lbl_1_bss_716C0: .bss size 0x8, referenced by 32 functions, shape {'object': 780}

// lbl_1_bss_7B180: .bss size 0x8, referenced by 29 functions, shape {'object': 873}

// the ghost .bss run from 0x7B180 as one view: retail addresses the TU's objects off this base (dtk sizes it 8; the objects at 7B188..7ED5C are separate symbols). Offsets from base-relative loads/stores in retail; mixed-width offsets are byte arrays.

// typedefs.json decl override

// lbl_1_data_3D544: .data size 0x10, referenced by 26 functions, shape {'object': 11}

// 'accessory.c'

// lbl_1_data_35AC8: .data size 0x4, referenced by 25 functions, shape {'object': 108}

// lbl_1_bss_6D820: .bss size 0x4, referenced by 23 functions, shape {'object': 283}

// lbl_1_bss_6C7A4: .bss size 0x28, referenced by 23 functions, shape {'object': 84}

// lbl_1_bss_7EFD8: .bss size 0x44, referenced by 22 functions, shape {'object': 121}

// object reached through lbl_1_bss_7EFD8.unk_40

// lbl_1_data_5730: .data size 0xC, referenced by 21 functions, shape {'object': 98}

// 'OVERTAKE'

// lbl_1_data_3C7B8: .data size 0xA, referenced by 21 functions, shape {'object': 52}

// 'memcard.c'

// lbl_1_bss_6EAB4: .bss size 0x12, referenced by 21 functions, shape {'object': 69}

// lbl_1_bss_4C688: .bss size 0x2000, referenced by 21 functions, shape {'object': 39}

// lbl_1_bss_84420: .bss size 0x8, referenced by 21 functions, shape {'object': 32, 'pointer': 10}

/* end rel/main_rel/globals.h */

/* begin rel/main_rel/accessory.h (fork-deltawave784/windows-and-types@f88123fa) */

#define REL_MAIN_REL_ACCESSORY_H

/* rel/main_rel/globals.h: inlined above */

// Generated by `fzgx headers --module main_rel --tu accessory.c`: globals of accessory.c (referenced by its

// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_1_data_3F510: .data size 0x68, 8 refs from accessory.c

// lbl_1_bss_88B50: .bss size 0xC00, 8 refs from accessory.c

// lbl_1_bss_89760: .bss size 0x10, 3 refs from accessory.c

// lbl_1_bss_86ED0: .bss size 0x1C70, 2 refs from accessory.c

#define FZGX_TYPES_LBL_1_BSS_86ED0

// one layout for every TU header that declares this symbol (librarian, typedefs.json)

// typedefs.json decl override

// lbl_1_bss_89770: .bss size 0x10, 2 refs from accessory.c

// lbl_1_bss_962: .bss size 0x2, 2 refs from accessory.c

// lbl_1_bss_89750: .bss size 0x10, 2 refs from accessory.c

// lbl_1_data_405EC: .data size 0x8, 1 refs from accessory.c (own data block)

// lbl_1_data_405F4: .data size 0x6, 1 refs from accessory.c (own data block)

// jumptable_1_data_405C8: .data size 0x24, 1 refs from accessory.c (own data block)

// lbl_1_data_405C0: .data size 0x8, 1 refs from accessory.c (own data block)

/* end rel/main_rel/accessory.h */

/* begin rel/main_rel/cloth.h (fork-deltawave784/windows-and-types@f88123fa) */

#define REL_MAIN_REL_CLOTH_H

/* rel/main_rel/globals.h: inlined above */

// Generated by `fzgx headers --module main_rel --tu cloth.c`: globals of cloth.c (referenced by its

// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_1_bss_85250: .bss size 0x30, 5 refs from cloth.c

#define FZGX_TYPES_LBL_1_BSS_85250

// one layout for every TU header that declares this symbol (librarian, typedefs.json)

// typedefs.json decl override

// lbl_1_data_3F17C: .data size 0x8, 3 refs from cloth.c (own data block)

// lbl_1_bss_85280: .bss size 0x8, 2 refs from cloth.c

#define FZGX_TYPES_LBL_1_BSS_85280

// one layout for every TU header that declares this symbol (librarian, typedefs.json)

// typedefs.json decl override

// lbl_1_bss_38460: .bss size 0x54, 2 refs from cloth.c

// lbl_1_data_3F188: .data size 0xC, 1 refs from cloth.c (own data block)

// lbl_1_data_3F28C: .data size 0x60, 1 refs from cloth.c (own data block)

// lbl_1_data_3F2EC: .data size 0x60, 1 refs from cloth.c (own data block)

// lbl_1_data_3F244: .data size 0x40, 1 refs from cloth.c (own data block)

// lbl_1_data_3F284: .data size 0x8, 1 refs from cloth.c (own data block)

/* end rel/main_rel/cloth.h */

/* begin game/main_rel/shared_types.h (fork-deltawave784/windows-and-types@f88123fa) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/shared_types.h */

/* game/main_rel/shared_types.h: inlined above */

/* game/main_rel/shared_types.h: inlined above */

/* end game/main_rel/accessory_types.h */

/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@f88123fa) */

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* rel/main_rel/globals.h: inlined above */

/* begin rel/main_rel/car_test.h (fork-deltawave784/windows-and-types@f88123fa) */

#define REL_MAIN_REL_CAR_TEST_H

/* rel/main_rel/globals.h: inlined above */

// Generated by `fzgx headers --module main_rel --tu car_test.c`: globals of car_test.c (referenced by its

// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_1_bss_6D7E8: .bss size 0x8, 4 refs from car_test.c

// lbl_1_data_1EF5C: .data size 0x80, 3 refs from car_test.c (own data block)

// lbl_1_bss_6D7F4: .bss size 0x2C, 3 refs from car_test.c

// lbl_1_data_1FFE0: .data size 0x10, 2 refs from car_test.c (own data block)

// lbl_1_bss_6D7F0: .bss size 0x1, 2 refs from car_test.c

// lbl_1_bss_6D620: .bss size 0x138, 2 refs from car_test.c

// lbl_1_data_1FFDC: .data size 0x4, 1 refs from car_test.c (own data block)

// lbl_1_data_1F1D8: .data size 0x8, 1 refs from car_test.c (own data block)

// lbl_1_data_1F5A0: .data size 0xA4, 1 refs from car_test.c (own data block)

// lbl_1_data_1EFDC: .data size 0x5, 1 refs from car_test.c (own data block)

// lbl_1_data_1EFE4: .data size 0x8, 1 refs from car_test.c (own data block)

// lbl_1_data_1F4FC: .data size 0xA4, 1 refs from car_test.c (own data block)

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* rel/main_rel/globals.h: inlined above */

/* rel/main_rel/accessory.h: inlined above */

/* rel/main_rel/cloth.h: inlined above */

void fn_1_112F40(fn_1_10D2F0_Obj *obj) {
    u32 i;
    u32 j;
    u32 n;
    u32 count;
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *b;
    fn_1_10D2F0_Entry *p;
    fn_1_10D2F0_Entry *next;

    if (obj == NULL) {
        return;
    }
    fn_1_10846C( (void *)((fn_1_10D2F0_Obj *)(obj)));

    for (i = 0, a = obj->unk_24; i < obj->unk_18; i++, a++) {
        if (a->unk_0 & 1) {
            a->unk_40 = -1.0f;
            a->unk_0 = 0;
        } else {
            a->unk_40 = 0.0f;
            a->unk_0 = 1;
        }
    }

    for (i = 0, a = obj->unk_24; i < obj->unk_18; i++, a++) {
        for (j = i + 1, b = obj->unk_24 + i + 1; j < obj->unk_18; j++, b++) {
            if ((a->unk_0 & 1) && !(b->unk_0 & 1)) {
                fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
            }
        }
    }

    for (i = 0, a = obj->unk_24; i < obj->unk_18; i++, a++) {
        for (j = i + 1, b = obj->unk_24 + i + 1; j < obj->unk_18; j++, b++) {
            if (a->unk_0 == b->unk_0 && a->unk_10.z > b->unk_10.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
            }
        }
    }

    for (i = 0, a = obj->unk_24; i < obj->unk_18; i++, a++) {
        for (j = i + 1, b = obj->unk_24 + i + 1; j < obj->unk_18; j++, b++) {
            if (a->unk_0 == b->unk_0) {
                if (a->unk_10.y < b->unk_10.y && a->unk_10.z > 0.0f && b->unk_10.z > 0.0f) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                } else if (a->unk_10.y > b->unk_10.y && a->unk_10.z < 0.0f && b->unk_10.z < 0.0f) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }
    }

    n = obj->unk_18 / 2;
    obj->unk_1C = (((n - 1)) << 1) + n;
    obj->unk_28 = (void *)((u32)fn_1_4630((u32)lbl_801A6410, (u32)(obj->unk_1C * sizeof(fn_1_10D2F0_Link)), "accessory.c", (s32)0x1330));

    count = 0;
    for (i = 0, a = obj->unk_24; i < obj->unk_18 - 1; i++, a++) {
        if (a->unk_0 == a[1].unk_0) {
            obj->unk_28[count].a = a;
            obj->unk_28[count].b = a + 1;
            obj->unk_28[count].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 1));
            count++;
        }
    }

    a = obj->unk_24;
    for (i = 0, p = a; i < obj->unk_18; i++, p++) {
        if (p->unk_0 != p[1].unk_0) {
            next = p + 1;
            break;
        }
    }

    for (i = 0; i < obj->unk_18; i++, a++, next++) {
        obj->unk_28[count].a = a;
        obj->unk_28[count].b = next;
        obj->unk_28[count].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)next);
        count++;
        if (a->unk_0 != a[1].unk_0) {
            return;
        }
    }
}
#undef lbl_1_bss_38458
#undef lbl_1_bss_38460
#undef lbl_1_bss_3BE0
#undef lbl_1_bss_3C00
#undef lbl_1_bss_3C30
#undef lbl_1_bss_4B9CC
#undef lbl_1_bss_4C688
#undef lbl_1_bss_6C7A4
#undef lbl_1_bss_6D838
#undef lbl_1_bss_6EAB4
#undef lbl_1_bss_7B180
#undef lbl_1_bss_7EFD8
#undef lbl_1_bss_7F0C0
#undef lbl_1_bss_85250
#undef lbl_1_bss_85280
#undef lbl_1_bss_86ED0
#undef lbl_1_bss_88B50
#undef lbl_1_bss_89750
#undef lbl_1_bss_89760
#undef lbl_1_bss_89770
#undef lbl_1_bss_8B3A0
#undef lbl_1_bss_9F8
#undef lbl_1_bss_F68
#undef lbl_1_data_2A7E0
#undef lbl_1_data_3C7B8
#undef lbl_1_data_3D544
#undef lbl_1_data_3F284
#undef lbl_1_data_3F28C
#undef lbl_1_data_3F2EC
#undef lbl_1_data_5730
#undef lbl_801A6410
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef FZGX_TYPES_LBL_1_BSS_86ED0
#undef REL_MAIN_REL_CLOTH_H
#undef FZGX_TYPES_LBL_1_BSS_85250
#undef FZGX_TYPES_LBL_1_BSS_85280
#undef GAME_MAIN_REL_SHARED_TYPES_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_CAR_TEST_H
/* fzgx:end fn_1_112F40 */

/* fzgx:begin fn_1_1132E4 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_1132E4(Work_1132E4 *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Link *l;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *vn;
 Node *b;
 u32 i2;
 Node *n2;
 Vec3 deltav;
 Vec3 diff;
 Vec3 target;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.y+=n2->vel.y-0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len>0.0004f) {
 len=lbl_8006D0B4(0.0004f/len);
 n5->pos.x=target.x+(f32)(dif.x*len);
 n5->pos.y=target.y+(f32)(dif.y*len);
 n5->pos.z=target.z+(f32)(dif.z*len);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=vn->pos.x-vn->prev.x;
 vn->vel.y=vn->pos.y-vn->prev.y;
 vn->vel.z=vn->pos.z-vn->prev.z;
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
/* fzgx:end fn_1_1132E4 */

/* fzgx:begin fn_1_1137E4 */
/* VIEWS */
void fn_1_1137E4(Rope_1137E4 *rope) {
    u32 i;
    u32 c;
    RopeNode_1137E4 *a;
    RopeNode_1137E4 *n;
    u32 m;
    u32 j;
    RopeNode_1137E4 *b;
    u32 k;
    u32 rows;
    s32 cols;

    if (rope == NULL) {
        return;
    }
    j = 13;
    if (rope->owner->unk_8C == 2) {
        j = 9;
    }
    cols = j;
    fn_1_10846C((void *)rope);

    for (i = 0, a = rope->nodes; i < rope->count; i++, a++) {
        if (a->flags & 1) {
            a->flags = 0;
            a->mass = -1.0f;
        } else {
            a->flags = 1;
            a->mass = 0.0f;
        }
    }

    for (i = 0, a = rope->nodes; i < rope->count; i++, a++) {
        for (m = i + 1, b = &rope->nodes[i] + 1; m < rope->count; m++, b++) {
            if (a->pos.x < b->pos.x) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_1137E4));
            }
        }
    }

    rows = rope->count / cols;
    for (i = 0, a = rope->nodes; i < rows; i++, a += cols) {
        for (m = 0, b = a; m < cols; m++, b++) {
            for (c = m + 1, n = b + 1; c < cols; c++, n++) {
                if (b->pos.z > n->pos.z) {
                    fn_1_128884((void *)b, (void *)n, sizeof(RopeNode_1137E4));
                }
            }
        }
    }

    for (i = 0, a = rope->nodes; i < rows; i++, a += cols) {
        for (m = 0, b = a; m < cols; m++, b++) {
            for (c = m + 1, n = b + 1; c < cols; c++, n++) {
                if (b->pos.z > 0.0f && n->pos.z > 0.0f && b->pos.y < n->pos.y) {
                    fn_1_128884((void *)b, (void *)n, sizeof(RopeNode_1137E4));
                } else if (b->pos.z <= 0.0f && n->pos.z <= 0.0f && b->pos.y > n->pos.y) {
                    fn_1_128884((void *)b, (void *)n, sizeof(RopeNode_1137E4));
                }
            }
        }
    }

    rows = rope->count / cols;
    for (i = 0, a = rope->nodes; i < rows; i++, a += cols) {
        for (m = 0, b = a; m < cols; m++, b++) {
            if (b->flags & 1) {
                b->mass = 0.0f;
            } else {
                b->mass = (i + 1) / (f32)rows;
                b->mass *= -(1.0 - (f64)(0.8 * lbl_8006D188(32768.0f * m / 12.0f)));
            }
        }
    }

    rows = rope->count / cols;
    rope->linkCount = rows * (cols - 1) + (rows - 1) * cols;
    rope->links = fn_1_4630(lbl_801A6410, rope->linkCount * sizeof(Link_1137E4), "accessory.c", 0x143E);

    for (i = 0, k = 0, a = rope->nodes; i < rope->count - 1; i++, a++) {
        if ((i + 1) % cols != 0) {
            rope->links[k].a = a;
            rope->links[k].b = a + 1;
            rope->links[k].length = fn_1_1289BC((void *)a, (void *)(a + 1));
            k++;
        }
    }
    for (i = 0, a = rope->nodes; i < rope->count - cols; i++, a++) {
        rope->links[k].a = a;
        rope->links[k].b = a + (u32)cols;
        rope->links[k].length = fn_1_1289BC((void *)a, (void *)(a + (u32)cols));
        k++;
    }
}
/* fzgx:end fn_1_1137E4 */

/* fzgx:begin fn_1_113C58 */
/* VIEWS */
#define lbl_801A6410 ((u32 *)&lbl_801A6410)
#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_GLOBALS_H

/* end rel/main_rel/accessory.h */

#define P_0x58 0.0013611111376020642

#define P_0x60 0.0027222223579883575f

#define P_0x68 0.0f

#define P_0x9C 0.0001f

#define P_0xA0 1.0f

#define P_0x10C 0.065f

#define P_0x154 0.049f

#define P_0x188 0.2

#define P_0x190 0.8

#define P_0x198 0.5

#define P_0x1A8 0.115f

#define P_0x1D0 0.027f

#define P_0x1E8 0.051f

#define P_0x1F0 0.119f

#define P_0x1F4 0.183f

#define P_0x238 0.1f

#define P_0x278 0.12f

#define P_0x27C 0.07f

#define P_0x280 -0.037f

#define P_0x284 0.09f

#define P_0x288 0.077f

#define P_0x28C 0.112f

#define P_0x290 0.18f

#define P_0x294 -0.013f

#define P_0x298 0.069f

#define P_0x29C -0.002f

#define P_0x2A0 0.021f

#define P_0x2A4 -0.021f

#define P_0x2A8 0.06f

#define P_0x2AC 0.075f

#define P_0x2B0 0.085f

#define P_0x2B4 0.092f

#define P_0x2B8 0.059f

#define P_0x2BC 0.055f

#define F(o) P_##o

#define D(o) P_##o

#define LIMIT(n,a,b,c,d) fn_1_108A90((void *)obj,n,F(a),F(b),F(c),F(d))

static inline void reset_points(AccessoryObjectLocal *obj) {
    u32 n;
    AccessoryPoint *p = obj->unk_24;
    for (n = 0; n < obj->unk_18; n++, p++) {
        lbl_8006DBE4();
        lbl_8006E1B0(&p->unk_28, &p->unk_10);
    }
}

void fn_1_113C58(AccessoryObjectLocal *arg0) {
    Vec3 delta;
    Vec3 noise;
    f32 distance;
    u32 k;
    AccessoryPoint *points;
    u8 *matrix;
    AccessoryLink **sorted;
    f32 *weights;
    AccessoryObjectLocal *obj = arg0;
    AccessoryPoint *integrationPoint;
    u32 i;
    AccessoryLink *link;
    u32 pass;
    AccessoryPoint *finalPoint;
    AccessoryLink **cursor;
    u32 iterations;
    AccessoryPoint *a;
    AccessoryPoint *b;
    u32 j;
    if (obj != 0) {
    if (obj->unk_10 != 0) {
    ((s32)fn_80077B14(obj->unk_10));
    if (obj->unk_0 & 2) {
        obj->unk_0 &= ~2;
        lbl_8006DBAC(((u8 (*)[0x18C])obj->unk_C->unk_150->unk_8)[lbl_1_data_3FFBC[obj->unk_8]] + 0x88);
        lbl_8006DAEC();
        reset_points(obj);
        lbl_8006DC20();
    }
    integrationPoint = obj->unk_24;
    for (i = 0; i < obj->unk_18; i++, integrationPoint++) {
        AccessoryPoint *p = integrationPoint;
        if (!(p->unk_0 & 1)) {
             p->unk_1C = p->unk_10;
            p->unk_10.x += p->unk_34.x;
            p->unk_10.y += p->unk_34.y;
            p->unk_10.z += p->unk_34.z;
            p->unk_10.y -= D(0x58);
            p->unk_34.y -= F(0x60);
        }
    }
    matrix = obj->unk_C->unk_150->unk_8 + lbl_1_data_3FFBC[obj->unk_8] * 0x18C;
    points = obj->unk_24;
    for (i = 0; i < obj->unk_18; i++, points++) {
        lbl_8006DBAC(matrix + 0x88);
        lbl_8006DAEC();
        if (points->unk_0 & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0(&points->unk_28, &points->unk_10);
        }
        lbl_8006DC20();
    }
    sorted = fn_1_4630(lbl_801A6410[0], obj->unk_1C * 4, "accessory.c", 0x147C);
    weights = fn_1_4630(lbl_801A6410[0], obj->unk_1C * 4, "accessory.c", 0x147D);
    {
        f32 *weightcur;
        AccessoryLink **sortcur;
        u32 count;
        AccessoryLink *item;
        item = obj->unk_28;
        sortcur = sorted;
        count = 0;
        weightcur = weights;
        for (; count < obj->unk_1C; count++, weightcur++, sortcur++, item++) {
            *weightcur = item->unk_0->unk_40 + item->unk_4->unk_40;
            *sortcur = item;
        }
    }
    for (i = 0; i < obj->unk_1C; i++) {
        for (j = i; j < obj->unk_1C; j++) {
            if (weights[i] < weights[j]) {
                f32 tmp = weights[i];
                AccessoryLink *tmpLink;
                weights[i] = weights[j];
                weights[j] = tmp;
                tmpLink = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmpLink;
            }
        }
    }
    if (obj->unk_C->unk_8C == 2 || obj->unk_C->unk_8C == 3) iterations = 2;
    else iterations = 4;
    for (pass = 0; pass < iterations; pass++) {
        cursor = sorted;
        for (i = 0; i < obj->unk_1C; i++, cursor++) {
            link = *cursor;
            a = link->unk_0;
            b = link->unk_4;
            if (a && b) {
                f32 stretched;
                psvec_sub(&a->unk_10, &b->unk_10, &delta);
                distance = __fmadds(delta.z, delta.z, __fmadds(delta.y, delta.y, delta.x * delta.x));
                stretched = distance - F(0x9C);
                if (stretched > link->unk_8) {
                    f32 reciprocal = lbl_8006D118(distance, &distance);
                    f32 f1 = lbl_8006D0B4(link->unk_8);
                    f32 massB, massA;
                    f32 factor, wa, wb;
                    distance = reciprocal * (distance - f1);
                    psvec_scale(&delta, distance, &delta);
                    massA = a->unk_40;
                    massB = b->unk_40;
                    factor = F(0xA0) / (massA + massB);
                    wa = -(massA * factor);
                    wb = massB * factor;
                    psvec_scale_add(&a->unk_10, &delta, wa, &a->unk_10);
                    psvec_scale_add(&b->unk_10, &delta, wb, &b->unk_10);
                }
            }
        }
        if (obj->unk_C->unk_8C == 2 || obj->unk_C->unk_8C == 3) {
            LIMIT(1,0x278,0x1A8,0x68,0x68);
            LIMIT(0x10,0x278,0x68,0x68,0x68);
            LIMIT(0x12,0x27C,0x280,0x68,0x68);
            LIMIT(0x12,0x284,0x288,0x68,0x68);
            LIMIT(0x12,0x28C,0x290,0x294,0x68);
            LIMIT(0x17,0x27C,0x280,0x68,0x68);
            LIMIT(0x17,0x284,0x288,0x68,0x68);
            LIMIT(0x17,0x28C,0x290,0x294,0x68);
            LIMIT(0x13,0x298,0x1E8,0x68,0x68);
            LIMIT(0x13,0x10C,0x1F4,0x68,0x68);
            LIMIT(0x18,0x298,0x1E8,0x68,0x68);
            LIMIT(0x18,0x10C,0x1F4,0x68,0x68);
        } else {
            LIMIT(1,0x238,0x1A8,0x68,0x68);
            LIMIT(0x10,0x238,0x68,0x68,0x68);
            LIMIT(0x10,0x238,0x154,0x29C,0x2A0);
            LIMIT(0x10,0x238,0x154,0x29C,0x2A4);
            LIMIT(0x12,0x2A8,0x280,0x68,0x68);
            LIMIT(0x12,0x27C,0x1D0,0x68,0x68);
            LIMIT(0x12,0x2AC,0x288,0x68,0x68);
            LIMIT(0x12,0x2B0,0x1F0,0x68,0x68);
            LIMIT(0x12,0x2B4,0x290,0x294,0x68);
            LIMIT(0x17,0x2A8,0x280,0x68,0x68);
            LIMIT(0x17,0x27C,0x1D0,0x68,0x68);
            LIMIT(0x17,0x2AC,0x288,0x68,0x68);
            LIMIT(0x17,0x2B0,0x1F0,0x68,0x68);
            LIMIT(0x17,0x2B4,0x290,0x294,0x68);
            LIMIT(0x13,0x2B8,0x1E8,0x68,0x68);
            LIMIT(0x13,0x2B8,0x1A8,0x68,0x68);
            LIMIT(0x13,0x2BC,0x1F4,0x68,0x68);
            LIMIT(0x18,0x2B8,0x1E8,0x68,0x68);
            LIMIT(0x18,0x2B8,0x1A8,0x68,0x68);
            LIMIT(0x18,0x2BC,0x1F4,0x68,0x68);
        }
    }
    if (sorted) fn_1_46B4(lbl_801A6410[0], (u32)sorted, "accessory.c", 0x14F8);
    if (weights) fn_1_46B4(lbl_801A6410[0], (u32)weights, "accessory.c", 0x14F9);
    finalPoint = obj->unk_24;
    {
    f64 damping = D(0x190);
    f64 response = D(0x188);
    f64 noiseScale = D(0x198);
    for (k = 0; k < obj->unk_18; k++, finalPoint++) {
        AccessoryPoint *p = finalPoint;
        f64 tmp;
        fn_1_1286F4((void *)&noise);
        p->unk_34.x *= damping;
        p->unk_34.y *= damping;
        p->unk_34.z *= damping;
        p->unk_34.x += (f64)(response * (p->unk_10.x - p->unk_1C.x));
        p->unk_34.y += (f64)(response * (p->unk_10.y - p->unk_1C.y));
        p->unk_34.z += (f64)(response * (p->unk_10.z - p->unk_1C.z));
        p->unk_34.x += (f64)(noiseScale * noise.x);
        p->unk_34.y += (f64)(noiseScale * noise.y);
        p->unk_34.z += (f64)(noiseScale * noise.z);
    }
    }
    fn_1_109114((void *)obj);
    }
    }
}
#undef lbl_801A6410
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_GLOBALS_H
#undef P_0x58
#undef P_0x60
#undef P_0x68
#undef P_0x9C
#undef P_0xA0
#undef P_0x10C
#undef P_0x154
#undef P_0x188
#undef P_0x190
#undef P_0x198
#undef P_0x1A8
#undef P_0x1D0
#undef P_0x1E8
#undef P_0x1F0
#undef P_0x1F4
#undef P_0x238
#undef P_0x278
#undef P_0x27C
#undef P_0x280
#undef P_0x284
#undef P_0x288
#undef P_0x28C
#undef P_0x290
#undef P_0x294
#undef P_0x298
#undef P_0x29C
#undef P_0x2A0
#undef P_0x2A4
#undef P_0x2A8
#undef P_0x2AC
#undef P_0x2B0
#undef P_0x2B4
#undef P_0x2B8
#undef P_0x2BC
#undef F
#undef D
#undef LIMIT
/* fzgx:end fn_1_113C58 */

/* fzgx:begin fn_1_1145C8 */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/shared_types.h */

/* game/main_rel/shared_types.h: inlined above */

/* game/main_rel/shared_types.h: inlined above */

/* end game/main_rel/accessory_types.h */

void fn_1_1145C8(Accessory1145C8 *obj) {
    u32 i;
    u32 l;
    Accessory1145C8Node *row;
    u32 k;
    u32 a;
    Accessory1145C8Node *e;
    Accessory1145C8Node *p;
    Accessory1145C8Node *g;
    u32 b;
    Accessory1145C8Node *f;
    u32 j;
    Accessory1145C8Node *q;
    u32 rows;
    f32 value;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);
        for (i = 0, e = obj->nodes; i < obj->count; i++, e++) {
            if (e->flag & 1) {
                e->flag = 0;
                e->value = -1.0f;
            } else {
                e->flag = 1;
                e->value = 0.0f;
            }
        }

        for (i = 0, e = obj->nodes; i < obj->count; i++, e++) {
            if (obj->unk_C->mode == 4 || obj->unk_C->mode == 35) {
                for (j = i + 1, f = &obj->nodes[i] + 1; j < obj->count; j++, f++) {
                    if (e->keyA > f->keyA) {
                        fn_1_128884((void *)e, (void *)f, sizeof(Accessory1145C8Node));
                    }
                }
            } else {
                for (l = i + 1, g = &obj->nodes[i] + 1; l < obj->count; l++, g++) {
                    if (e->keyA < g->keyA) {
                        fn_1_128884((void *)e, (void *)g, sizeof(Accessory1145C8Node));
                    }
                }
            }
        }

        rows = obj->count / 5;
        for (i = 0, row = obj->nodes; i < rows; i++, row += 5) {
            value = -(f32)i / (rows - 1);
            row[0].value = value;
            row[1].value = value;
            row[2].value = value;
            row[3].value = value;
            row[4].value = value;
            for (a = 0, p = row; a < 5; a++, p++) {
                for (b = a + 1, q = p + 1; b < 5; b++, q++) {
                    if (p->keyB > q->keyB) {
                        fn_1_128884((void *)p, (void *)q, sizeof(Accessory1145C8Node));
                    }
                }
            }
        }

        obj->edgeCount = (obj->count / 5) * 4 + (obj->count / 5 - 1) * 5;
        obj->edges = fn_1_4630(lbl_801A6410, obj->edgeCount * sizeof(Accessory1145C8Edge), "accessory.c", 0x1563);

        k = 0;
        for (i = 0, e = obj->nodes; i < obj->count - 1; i++, e++) {
            if ((i + 1) % 5 != 0) {
                obj->edges[k].a = e;
                obj->edges[k].b = e + 1;
                obj->edges[k].len = fn_1_1289BC((const Point1024C4 *)e, (const Point1024C4 *)(e + 1));
                k++;
            }
        }

        for (i = 0, e = obj->nodes; i < obj->count - 5; i++, e++) {
            obj->edges[k].a = e;
            obj->edges[k].b = e + 5;
            obj->edges[k].len = fn_1_1289BC((const Point1024C4 *)e, (const Point1024C4 *)(e + 5));
            k++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_1145C8 */

/* fzgx:begin fn_1_11492C */
static inline s32 fn_1_11492C_irand(void) {
 lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
 return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline f32 fn_1_11492C_rand01(void) {
 return fn_1_11492C_irand() / 32767.0f;
}

static inline f32 fn_1_11492C_randf(f32 scale) {
 return scale * fn_1_11492C_rand01();
}

void fn_1_11492C(Work_11492C *arg0) {
 u8 *model5;
 u8 *model4;
 Node_10E3B4 *a;
 Vec3 delta;
 Vec3 *d = &delta;
 Vec3 random;
 Vec3 target1;
 Vec3 target2;
 f32 len;
 f32 dy, dx, dz;
 Node_10E3B4 *n1;
 u32 i1;
 Node_10E3B4 *n2;
 u32 i2;
 Node_10E3B4 *n3;
 u8 *model3;
 u32 i3;
 Link_10E3B4 *l;
 s32 kind;
 u32 i4;
 u32 i5;
 Node_10E3B4 *n5;
 Node_10E3B4 *n4;
 u32 li;
 Node_10E3B4 *b;
 u32 i6;
 Node_10E3B4 *n6;
 u32 k;
 s32 kind6;
 if (arg0 && arg0->obj) {
  fn_80077B14(arg0->obj);
  if (arg0->flags & 2) {
   arg0->flags &= ~2;
   lbl_8006DBAC(arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396 + 136);
   lbl_8006DAEC();
   for (i1 = 0, n1 = arg0->nodes; i1 < arg0->count; i1++, n1++) {
    lbl_8006DBE4();
    lbl_8006E1B0(&n1->local, &n1->pos);
   }
   lbl_8006DC20();
  }
  for (i2 = 0, n2 = arg0->nodes; i2 < arg0->count; i2++, n2++) {
   if (!(n2->flags & 1)) {
    n2->prev = n2->pos;
    n2->pos.x += n2->vel.x;
    n2->pos.y += n2->vel.y;
    n2->pos.z += n2->vel.z;
    n2->pos.y -= 0.5 * (9.8f / 60.0 / 60.0);
    n2->vel.y -= 9.8f / 60.0f / 60.0f;
   }
  }
  model3 = arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396;
  for (i3 = 0, n3 = arg0->nodes; i3 < arg0->count; i3++, n3++) {
   lbl_8006DBAC(model3 + 136);
   lbl_8006DAEC();
   if (n3->flags & 1) {
    lbl_8006DBE4();
    lbl_8006E1B0(&n3->local, &n3->pos);
   }
   lbl_8006DC20();
  }
  for (k = 0; k < 4; k++) {
   for (li = 0, l = arg0->links; li < arg0->linkCount; li++, l++) {
    a = l->a;
    b = l->b;
    if (a && b) {
     dx = a->pos.x - b->pos.x;
     dy = a->pos.y - b->pos.y;
     dz = a->pos.z - b->pos.z;
     d->x = dx;
     d->y = dy;
     d->z = dz;
     len = (f32)(dx * dx) + dy * dy + dz * dz;
     if (len - 0.0001f > l->length) {
      f32 inv;
      f32 r;
      f32 wa;
      f32 wb;
      f32 ra;
      f32 rb;
      inv = lbl_8006D118(len, &len);
      r = lbl_8006D0B4(l->length);
      len = inv * (len - r);
      d->x *= len;
      d->y *= len;
      d->z *= len;
      wa = a->weight;
      wb = b->weight;
      r = 1.0f / (wa + wb);
      ra = wa * r;
      rb = wb * r;
      a->pos.x -= (f32)(d->x * ra);
      a->pos.y -= (f32)(d->y * ra);
      a->pos.z -= (f32)(d->z * ra);
      b->pos.x += (f32)(d->x * rb);
      b->pos.y += (f32)(d->y * rb);
      b->pos.z += (f32)(d->z * rb);
     }
    }
   }
   kind = arg0->owner->kind;
   if (kind == 2) {
    fn_1_108A90((void *)arg0, 1, 0.09f, 0.115f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 1, 0.074f, 0.117f, 0.0f, -0.048f);
    fn_1_108A90((void *)arg0, 1, 0.074f, 0.117f, 0.0f, 0.048f);
    fn_1_108A90((void *)arg0, 13, 0.032f, 0.066f, -0.02f, 0.0f);
    fn_1_108A90((void *)arg0, 13, 0.032f, 0.099f, -0.02f, 0.0f);
    fn_1_108A90((void *)arg0, 13, 0.032f, 0.133f, -0.02f, 0.0f);
    fn_1_108A90((void *)arg0, 8, 0.032f, 0.066f, -0.05f, 0.0f);
    fn_1_108A90((void *)arg0, 8, 0.032f, 0.099f, -0.05f, 0.0f);
    fn_1_108A90((void *)arg0, 8, 0.032f, 0.133f, -0.05f, 0.0f);
   } else if (kind == 36) {
    fn_1_108A90((void *)arg0, 1, 0.071f, 0.095f, -0.009f, 0.006f);
    fn_1_108A90((void *)arg0, 12, 0.045f, 0.0f, 0.0f, 0.0f);
   } else if (kind == 33 || kind == 42 || kind == 43) {
    fn_1_108A90((void *)arg0, 1, 0.1f, 0.044f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 1, 0.072f, 0.097f, -0.015f, 0.114f);
   } else if (kind == 41) {
    fn_1_108A90((void *)arg0, 1, 0.311f, 0.039f, -0.221f, 0.0f);
   } else if (kind == 21) {
    fn_1_108A90((void *)arg0, 1, 0.538f, 0.081f, -0.47f, 0.0f);
   } else if (kind == 24) {
    fn_1_108A90((void *)arg0, 1, 0.084f, 0.105f, -0.02f, 0.031f);
    fn_1_108A90((void *)arg0, 1, 0.084f, 0.106f, -0.02f, -0.031f);
    fn_1_108A90((void *)arg0, 12, 0.1f, 0.0f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 7, 0.1f, 0.0f, 0.0f, 0.0f);
   } else if (kind == 4) {
    model4 = arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396;
    for (i4 = 0, n4 = arg0->nodes; i4 < 10; i4++, n4++) {
     if (!(n4->flags & 1)) {
      f32 dx, dy, dz;
      lbl_8006DBAC(model4 + 136);
      lbl_8006E1B0(&n4->local, &target1);
      dx = 0.76 * (target1.x - n4->pos.x);
      dy = 0.76 * (target1.y - n4->pos.y);
      dz = 0.76 * (target1.z - n4->pos.z);
      n4->pos.x += dx;
      n4->pos.y += dy;
      n4->pos.z += dz;
     }
    }
    fn_1_108A90((void *)arg0, 16, 0.141f, 0.047f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 18, 0.108f, 0.0f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 18, 0.106f, 0.051f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 18, 0.105f, 0.086f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 23, 0.108f, 0.0f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 23, 0.106f, 0.051f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 23, 0.105f, 0.086f, 0.0f, 0.0f);
   } else if (kind == 35) {
    model5 = arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396;
    for (i5 = 0, n5 = arg0->nodes; i5 < 10; i5++, n5++) {
     if (!(n5->flags & 1)) {
      f32 dx, dy, dz;
      lbl_8006DBAC(model5 + 136);
      lbl_8006E1B0(&n5->local, &target2);
      dx = 0.76 * (target2.x - n5->pos.x);
      dy = 0.76 * (target2.y - n5->pos.y);
      dz = 0.76 * (target2.z - n5->pos.z);
      n5->pos.x += dx;
      n5->pos.y += dy;
      n5->pos.z += dz;
     }
    }
    fn_1_108A90((void *)arg0, 16, 0.068f, 0.049f, 0.003f, 0.0f);
    fn_1_108A90((void *)arg0, 18, 0.066f, 0.0f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 18, 0.06f, 0.07f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 23, 0.066f, 0.0f, 0.0f, 0.0f);
    fn_1_108A90((void *)arg0, 23, 0.06f, 0.07f, 0.0f, 0.0f);
   }
  }
  for (i6 = 0, n6 = arg0->nodes; i6 < arg0->count; i6++, n6++) {
   fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
   n6->vel.x *= 0.8;
   n6->vel.y *= 0.8;
   n6->vel.z *= 0.8;
   n6->vel.x += (f64)(0.2 * (n6->pos.x - n6->prev.x));
   n6->vel.y += (f64)(0.2 * (n6->pos.y - n6->prev.y));
   n6->vel.z += (f64)(0.2 * (n6->pos.z - n6->prev.z));
   kind6 = arg0->owner->kind;
   if (kind6 == 4 || kind6 == 35) {
    n6->vel.x += (f64)(__fabs(random.x) * fn_1_11492C_rand01());
    n6->vel.y += fn_1_11492C_randf(0.0035f);
    n6->vel.z += (f64)(__fabs(random.z) * fn_1_11492C_rand01());
   } else if (kind6 == 21 || kind6 == 33 || kind6 == 41 || kind6 == 42 || kind6 == 43 || kind6 == 36) {
    n6->vel.x += fn_1_11492C_randf(0.001f);
    n6->vel.y += fn_1_11492C_randf(0.0041f);
    n6->vel.z += 0.0f * fn_1_11492C_rand01();
   } else {
    n6->vel.x += (f64)(0.5 * random.x);
    n6->vel.y += (f64)(0.5 * random.y);
    n6->vel.z += (f64)(0.5 * random.z);
   }
  }
  fn_1_109114((void *)arg0);
 }
}
/* fzgx:end fn_1_11492C */

/* fzgx:begin fn_1_1154D0 */
void fn_1_1154D0(Fn1154D0Object *obj) {
    f32 inactive_value;
    f32 active_value;
    u32 i;
    Fn1154D0Entry *entry;

    if (obj != 0) {
        fn_1_10846C((void *)obj);
        active_value = -1.0f;
        inactive_value = 0.0f;
        entry = obj->entries;
        for (i = 0; i < obj->count; i++, entry++) {
            if ((entry->active & 1) != 0) {
                entry->active = 0;
                entry->field40 = active_value;
            } else {
                entry->active = 1;
                entry->field40 = inactive_value;
                entry->field34 = inactive_value;
                entry->field3c = inactive_value;
            }
        }
    }
}
/* fzgx:end fn_1_1154D0 */

/* fzgx:begin fn_1_115560 */
/* VIEWS */
static inline void integrate(Particle_115560 *p) {
p->old=p->pos;
p->pos.x+=p->vel.x;
p->pos.y+=p->vel.y;
p->pos.z+=p->vel.z;
p->pos.y-=0.0004083333412806193;
p->vel.y-=0.0008166666825612386;
}

static inline void divide(Sig_fn_1_1286F4_Vec3f *v,u32 n) { v->x/=n; v->y/=n; v->z/=n; }

void fn_1_115560(Rope_115560 *arg0) {
u8 *vertices;
Particle_115560 *anchor;
u32 i,j,n;
Particle_115560 *p;
u8 *bone;
f32 matrix[12];
Sig_fn_1_1286F4_Vec3f random;
f64 accel, gravity, spring, damping, noise;
f32 cx,cy,cz,ox,oy,oz,ax,ay,az;
if (arg0 && arg0->mesh) {
vertices=fn_80077B14(arg0->mesh);
for(i=0,p=arg0->particles;i<arg0->count;i++,p++) {
if (!(p->flags&1)) {
integrate(p);
}}
bone=((arg0)->model->set->bones + lbl_1_data_3FFBC[(arg0)->index]*396 + 136) -136;
for(i=0,p=arg0->particles;i<arg0->count;i++,p++) {
if(p->flags&1) {
lbl_8006DBAC(bone+136);
lbl_8006E1B0(&p->rest,&p->pos);
anchor=p;
}}
{
Sig_fn_1_1286F4_Vec3f current;
Sig_fn_1_1286F4_Vec3f original={0.0f,0.0f,0.0f};
f32 quat[4];
Sig_fn_1_1286F4_Vec3f tmp;
current=original;
n=0;
lbl_8006DBAC(((arg0)->model->set->bones + lbl_1_data_3FFBC[(arg0)->index]*396 + 136) );
for(i=0,p=arg0->particles;i<arg0->count;i++,p++) {
if(!(p->flags&1)) {
current.x+=p->pos.x; current.y+=p->pos.y; current.z+=p->pos.z;
n++;
lbl_8006E1B0(&p->rest,&tmp);
original.x+=tmp.x; original.y+=tmp.y; original.z+=tmp.z;
}}
divide(&current,n);
current.x-=anchor->pos.x; current.y-=anchor->pos.y; current.z-=anchor->pos.z;
divide(&original,n);
original.x-=anchor->pos.x; original.y-=anchor->pos.y; original.z-=anchor->pos.z;
lbl_8006D668(&current);
lbl_8006D668(&original);
fn_8006E978(quat,&original,&current);
mathutil_mtxA_from_quat(quat);
lbl_8006DB74(matrix);
lbl_8006DBAC(((arg0)->model->set->bones + lbl_1_data_3FFBC[(arg0)->index]*396 + 136) );
for(i=0,p=arg0->particles;i<arg0->count;i++,p++)
if(!(p->flags&1)) lbl_8006E1B0(&p->rest,&p->pos);
lbl_8006D758();
lbl_8006E0A4(&anchor->pos);
lbl_8006DFC4(matrix);
lbl_8006E0B4(-anchor->pos.x,-anchor->pos.y,-anchor->pos.z);
for(i=0,p=arg0->particles;i<arg0->count;i++,p++)
if(!(p->flags&1)) lbl_8006E1B0(&p->pos,&p->pos);
damping=0.8; spring=0.2; noise=0.5;
for(i=0,p=arg0->particles;i<arg0->count;i++,p++) {
fn_1_1286F4((void *)&random);
p->vel.x*=damping; p->vel.y*=damping; p->vel.z*=damping;
p->vel.x+=(f64)(spring*(p->pos.x-p->old.x));
p->vel.y+=(f64)(spring*(p->pos.y-p->old.y));
p->vel.z+=(f64)(spring*(p->pos.z-p->old.z));
p->vel.x+=(f64)(noise*random.x);
p->vel.y+=(f64)(noise*random.y);
p->vel.z+=(f64)(noise*random.z);
}
lbl_8006DBAC(((arg0)->model->set->bones + lbl_1_data_3FFBC[(arg0)->index]*396 + 136) );
for(i=0,p=arg0->particles;i<arg0->count;i++,p++)
for(j=0;j<p->count;j++) fn_8006E250(&p->pos,vertices+(p->links[j]<<6));
}
}
}
/* fzgx:end fn_1_115560 */

/* fzgx:begin fn_1_115B58 */
void fn_1_115B58(Fn1154D0Object *obj) {
    f32 inactive_value;
    f32 active_value;
    u32 i;
    Fn1154D0Entry *entry;

    if (obj != 0) {
        fn_1_10846C((void *)obj);
        active_value = -1.0f;
        inactive_value = 0.0f;
        entry = obj->entries;
        for (i = 0; i < obj->count; i++, entry++) {
            if ((entry->active & 1) != 0) {
                entry->active = 1;
                entry->field40 = active_value;
            } else {
                entry->active = 0;
                entry->field40 = inactive_value;
                entry->field34 = inactive_value;
                entry->field3c = inactive_value;
            }
        }
    }
}
/* fzgx:end fn_1_115B58 */

/* fzgx:begin fn_1_115BE8 */
/* FILE-SCOPE */ typedef f32 Mtx_115B58[3][4];

/* fn_1_109114 (accessory.c), which retail inlines here. */

static inline void fn_1_115BE8_skin(fn_1_115BE8_AccessoryObject *self) {
    void *base;
    u16 *item;
    int entry_index;
    int item_index;
    u8 *entry;

    base = fn_80077B14(self->unk_10);
    lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                 lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
    entry = self->unk_24;
    entry_index = 0;
    while (entry_index < self->unk_18) {
        item = (u16 *)entry;
        item_index = 0;
        while (item_index < entry[2]) {
            fn_8006E250((Vec3 *)(entry + 0x10), (Vec3 *)((u8 *)base + item[2] * 0x40));
            item++;
            item_index++;
        }
        entry_index++;
        entry += 0x44;
    }
}

static inline void fn_1_115BE8_sphere(Work_115B58 *arg0, f32 cx, f32 radius) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node_10E3B4 *kn;
 center.y = 0.0f; center.x = cx; center.z = 0.0f;
 lbl_8006DBAC(arg0->owner->model->base + 0x214);
 lbl_8006E1B0(&center, &center);
 for (ki = 0, kn = arg0->nodes; ki < arg0->count; ki++, kn++) {
  if (!(kn->flags & 1)) {
   f32 x, y, z, r;
   x = kn->pos.x; y = kn->pos.y; z = kn->pos.z;
   x -= center.x; y -= center.y; z -= center.z;
   r = (f32)(x * x) + y * y + z * z;
   if (r < radius * radius) {
    psvec_sub_scale_add(&kn->pos, &center, radius * lbl_8006D0E8(r), &diff, &kn->pos);
   }
  }
 }
}

void fn_1_115BE8(Work_115B58 *arg0) {
 u32 i;
 u8 *model;
 Node_10E3B4 *n;
 Node_10E3B4 *root;
 u32 cnt;
 f32 dx;
 f32 dz;
 f32 dy;
 f32 len;
 if ((lbl_1_bss_962) != 184 && arg0 && arg0->obj) {
  fn_80077B14(arg0->obj);
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   if (!(n->flags & 1)) {
    n->prev = n->pos;
    n->pos.x += n->vel.x;
    n->pos.y += n->vel.y;
    n->pos.z += n->vel.z;
    n->pos.y -= 0.5 * (9.8f / 60.0 / 60.0);
    n->vel.y -= 9.8f / 60.0f / 60.0f;
   }
  }
  model = arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396;
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   if (n->flags & 1) {
    lbl_8006DBAC(model + 136);
    lbl_8006E1B0(&n->local, &n->pos);
    root = n;
   }
  }
  {
  Mtx_115B58 mtx;
  Vec3 sum;
  Vec3 lsum = {0.0f, 0.0f, 0.0f};
  Quat_115B58 q;
  Vec3 tmp;
  Vec3 delta;
  Vec3 *d = &delta;
  Vec3 target;
  sum = lsum;
  cnt = 0;
  lbl_8006DBAC(arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396 + 136);
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   if (!(n->flags & 1)) {
    cnt++;
    sum.x += n->pos.x;
    sum.y += n->pos.y;
    sum.z += n->pos.z;
    lbl_8006E1B0(&n->local, &tmp);
    lsum.x += tmp.x;
    lsum.y += tmp.y;
    lsum.z += tmp.z;
   }
  }
  sum.x /= cnt;
  sum.y /= cnt;
  sum.z /= cnt;
  sum.x -= root->pos.x;
  sum.y -= root->pos.y;
  sum.z -= root->pos.z;
  lsum.x /= cnt;
  lsum.y /= cnt;
  lsum.z /= cnt;
  lsum.x -= root->pos.x;
  lsum.y -= root->pos.y;
  lsum.z -= root->pos.z;
  lbl_8006D668(&sum);
  lbl_8006D668(&lsum);
  fn_8006E978((void *)&q, (void *)&lsum, (void *)&sum);
  mathutil_mtxA_from_quat((void *)&q);
  lbl_8006DB74(mtx);
  lbl_8006DBAC(arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396 + 136);
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   if (!(n->flags & 1)) {
    lbl_8006E1B0(&n->local, &n->pos);
   }
  }
  lbl_8006D758();
  lbl_8006E0A4((void *)&root->pos);
  lbl_8006DFC4(mtx);
  lbl_8006E0B4(-root->pos.x, -root->pos.y, -root->pos.z);
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   if (!(n->flags & 1)) {
    lbl_8006E1B0(&n->pos, &n->pos);
   }
  }
  {
   Vec3 zero = {0.0f, 0.0f, 0.0f};
   sum = zero;
  }
  cnt = 0;
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   cnt++;
   sum.x += n->pos.x;
   sum.y += n->pos.y;
   sum.z += n->pos.z;
  }
  ((Vec3 *)&lbl_1_bss_89750)->x = sum.x / cnt;
  ((Vec3 *)&lbl_1_bss_89750)->y = sum.y / cnt;
  ((Vec3 *)&lbl_1_bss_89750)->z = sum.z / cnt;
  model = arg0->owner->model->base + lbl_1_data_3FFBC[arg0->index] * 396;
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   lbl_8006DBAC(model + 136);
   lbl_8006E1B0(&n->local, &target);
   dx = n->pos.x - target.x;
   dy = n->pos.y - target.y;
   dz = n->pos.z - target.z;
   d->x = dx;
   d->y = dy;
   d->z = dz;
   len = dx * dx;
   len += dy * dy;
   len += dz * dz;
   if (len > 0.0036f) {
    f32 s = lbl_8006D0B4(0.0036f / len);
    n->pos.x = target.x + (f32)(d->x * s);
    n->pos.y = target.y + (f32)(d->y * s);
    n->pos.z = target.z + (f32)(d->z * s);
    n->prev = n->pos;
   }
  }
  fn_1_115BE8_sphere(arg0, 0.124f, 0.088f);
  fn_1_115BE8_sphere(arg0, 0.064f, 0.083f);
  fn_1_115BE8_sphere(arg0, 0.016f, 0.078f);
  fn_1_108BD0((void *)arg0, 7, 0.045f, 0.0f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 7, 0.037f, 0.03f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 7, 0.037f, 0.06f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 7, 0.037f, 0.09f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 12, 0.045f, 0.0f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 12, 0.037f, 0.03f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 12, 0.037f, 0.06f, 0.0f, 0.0f);
  fn_1_108BD0((void *)arg0, 12, 0.037f, 0.09f, 0.0f, 0.0f);
  for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
   n->vel.x *= 0.8;
   n->vel.y *= 0.8;
   n->vel.z *= 0.8;
   n->vel.x += (f64)(0.2 * (n->pos.x - n->prev.x));
   n->vel.y += (f64)(0.2 * (n->pos.y - n->prev.y));
   n->vel.z += (f64)(0.2 * (n->pos.z - n->prev.z));
  }
  }
  fn_1_115BE8_skin((fn_1_115BE8_AccessoryObject *)arg0);
 }
}
/* fzgx:end fn_1_115BE8 */

/* fzgx:begin fn_1_1166EC */
void fn_1_1166EC(Fn1154D0Object *obj) {
    f32 inactive_value;
    f32 active_value;
    u32 i;
    Fn1154D0Entry *entry;

    if (obj != 0) {
        fn_1_10846C((void *)obj);
        active_value = -1.0f;
        inactive_value = 0.0f;
        entry = obj->entries;
        for (i = 0; i < obj->count; i++, entry++) {
            if ((entry->active & 1) != 0) {
                entry->active = 1;
                entry->field40 = active_value;
            } else {
                entry->active = 0;
                entry->field40 = inactive_value;
                entry->field34 = inactive_value;
                entry->field3c = inactive_value;
            }
        }
    }
}
/* fzgx:end fn_1_1166EC */

/* fzgx:begin fn_1_11677C */
/* VIEWS */
#define lbl_1_bss_89750 (*(Obj_1_bss_89750_L *)&lbl_1_bss_89750)
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

#define REL_MAIN_REL_ACCESSORY_H

static inline f32 fn_1_11677C_operand(f32 right, f32 left) { return left + right; }

void fn_1_11677C(void *arg0) {
    struct fn_1_11677C_Part { u8 pad_0[0x88]; Vec3 matrix; u8 pad_94[0xF8]; };
    Vec3 * lab_t0;
    u32 v16;
    u32 v2, v3, v4, v5, v6;
    u32 v7, v8, v9;
    f32 v1, v10, v11;
    u32 v13, v14, v15;
    s32 v20;
    f32 v25, v34, v35, v37, v40;
    u8 *v46;
    s32 v41, v42;
    u32 v43, v44;
    f32 v45, v47, v48, v49, v50, v52;
    f32 v55, v56, v57, v58, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68;
    u32 v69, v72, v74, v75, v76;
    f64 v71, v70;
    s32 v77;
    u32 v0;
    struct { u32 a[12]; } loc_CC;
    struct { u32 a[12]; } loc_9C;
    if (lbl_1_bss_962 != 184 && arg0 != 0) {
    v0 = *(u32 *)((u8 *)arg0 + 16);
    if (v0 != 0) {
    ((s32)fn_80077B14((void *)((struct Sig_fn_80077B14_fn_80077B14_Arg0_11677C *)v0)));
    v5 = *(u32 *)((u8 *)arg0 + 36);
    v6 = v5;
    v7 = 0;
    while (v7 < (v8 = *(u32 *)((u8 *)arg0 + 24))) {
    if ((*(u8 *)(v6) & 1) == 0) {
    *(struct fn_1_11677C_Copy12 *)((u8 *)v6 + 28) =
        *(struct fn_1_11677C_Copy12 *)((u8 *)v6 + 16);
    *(f32 *)((u8 *)v6 + 16) += *(f32 *)((u8 *)v6 + 52);
    *(f32 *)((u8 *)v6 + 20) += *(f32 *)((u8 *)v6 + 56);
    *(f32 *)((u8 *)v6 + 24) += *(f32 *)((u8 *)v6 + 60);
    *(f32 *)((u8 *)v6 + 20) -= 0.0013611111376020642;
    *(f32 *)((u8 *)v6 + 56) -= 0.0027222223579883575f;
    }
    v7++;
    v6 += 68;
    }
    v13 = *(u32 *)((u8 *)arg0 + 12);
    v2 = *(u32 *)((u8 *)arg0 + 36);
    v14 = lbl_1_data_3FFBC[*(u32 *)((u8 *)arg0 + 8)];
    v0 = *(u32 *)(v13 + 336);
    v0 = *(u32 *)(v0 + 8);
    v46 = (u8 *)(v0 + v14 * 396);
    for (v16 = 0; v16 < v8; v16++) {
    if ((*(u8 *)(v2) & 1) != 0) {
    lab_t0 = (Vec3 *)(v46 + 136);
    lbl_8006DBAC((void *)lab_t0);
    lbl_8006E1B0((void *)((Vec3 *)(v2 + 40)), (void *)((Vec3 *)(v2 + 16)));
    lbl_8006D758();
    lbl_8006E0A4((void *)((u32)&lbl_1_bss_89750));
    lbl_8006E0B4(-*(f32 *)(v2 + 16), -*(f32 *)(v2 + 20), -*(f32 *)(v2 + 24));
    lbl_8006DFC4((void *)((Vec3 *)(v46 + 136)));
    lbl_8006DB74((void *)((u32)&loc_9C));
    v3 = v2;
    *(struct fn_1_11677C_Copy12 *)((u8 *)v2 + 16) = *(struct fn_1_11677C_Copy12 *)&lbl_1_bss_89750;
    break;
    }
    v2 += 68;
    }
    {
    Vec3 loc_90;
    Vec3 loc_84 = {0.0f, 0.0f, 0.0f};
    f32 loc_74[4];
    Vec3 loc_68;
    /* Keep the displacement in memory across the math-library call. */
    struct { f32 a[3]; } loc_5C;
    void *displacement_ref = &loc_5C;
    struct { f32 a[3]; } loc_50;
    struct { f32 a[3]; } loc_44;
    struct { f32 a[3]; } loc_38;
    struct { f32 a[3]; } loc_2C;
    struct { f32 a[3]; } loc_20;
    struct { f32 a[3]; } loc_14;
    struct { f32 a[3]; } loc_8;
    v2 = 0;
    loc_90 = loc_84;
    lab_t0 = (Vec3 *)&loc_9C;
    lbl_8006DBAC((void *)lab_t0);
    v4 = *(u32 *)((u8 *)arg0 + 36);
    v20 = 0;
    while (v20 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(u8 *)(v4) & 1) == 0) {
    v2++;
    loc_90.x += *(f32 *)(v4 + 16);
    loc_90.y += *(f32 *)(v4 + 20);
    loc_90.z += *(f32 *)(v4 + 24);
    lbl_8006E1B0((void *)((Vec3 *)(v4 + 40)), (void *)((Vec3 *)&loc_68));
    loc_84.x += loc_68.x;
    loc_84.y += loc_68.y;
    loc_84.z += loc_68.z;
    }
    v20++;
    v4 += 68;
    }
    loc_90.x /= v2;
    loc_90.y /= v2;
    loc_90.z /= v2;
    loc_90.x -= *(f32 *)(v3 + 16);
    loc_90.y -= *(f32 *)(v3 + 20);
    loc_90.z -= *(f32 *)(v3 + 24);
    loc_84.x /= v2;
    loc_84.y /= v2;
    loc_84.z /= v2;
    loc_84.x -= *(f32 *)(v3 + 16);
    loc_84.y -= *(f32 *)(v3 + 20);
    loc_84.z -= *(f32 *)(v3 + 24);
    lbl_8006D668((void *)((struct Sig_fn_1_129D9C_fn_1_129D9C_vec *)&loc_90));
    lbl_8006D668((void *)((struct Sig_fn_1_129D9C_fn_1_129D9C_vec *)&loc_84));
    fn_8006E978((void *)((f32 *)&loc_74), (void *)((Vec3 *)&loc_84), (void *)((Vec3 *)&loc_90));
    mathutil_mtxA_from_quat(&loc_74);
    lbl_8006DB74((void *)((u32)&loc_CC));
    lab_t0 = (Vec3 *)&loc_9C;
    lbl_8006DBAC((void *)lab_t0);
    {
    u8 *v46;
    u32 v4;
    {
    u8 *v4;
    v4 = *(u8 **)((u8 *)arg0 + 36);
    v41 = 0;
    while (v41 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(v4) & 1) == 0) {
    lbl_8006E1B0((void *)((Vec3 *)(v4 + 40)), (void *)((Vec3 *)(v4 + 16)));
    }
    v41++;
    v4 += 68;
    }
    lbl_8006D758();
    lbl_8006E0A4((void *)(v3 + 16));
    lbl_8006DFC4((void *)((Vec3 *)&loc_CC));
    lbl_8006E0B4(-*(f32 *)(v3 + 16), -*(f32 *)(v3 + 20), -*(f32 *)(v3 + 24));
    }
    {
    u8 *v4;
    v4 = *(u8 **)((u8 *)arg0 + 36);
    v42 = 0;
    while (v42 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(v4) & 1) == 0) {
    lbl_8006E1B0((void *)((Vec3 *)(v4 + 16)), (void *)((Vec3 *)(v4 + 16)));
    }
    v42++;
    v4 += 68;
    }
    }
    v43 = *(u32 *)((u8 *)arg0 + 12);
    v3 = *(u32 *)((u8 *)arg0 + 36);
    v4 = 0;
    v44 = lbl_1_data_3FFBC[*(u32 *)((u8 *)arg0 + 8)];
    v0 = *(u32 *)(v43 + 336);
    v45 = 0.010000000707805157f;
    v0 = *(u32 *)(v0 + 8);
    v46 = (u8 *)v0;
    v46 += v44 * 396;
    while (v4 < *(u32 *)((u8 *)arg0 + 24)) {
    lbl_8006DBAC((void *)((Vec3 *)(v46 + 136)));
    lbl_8006E1B0((void *)((Vec3 *)(v3 + 40)), (void *)((Vec3 *)&loc_50));
    v47 = *(f32 *)(v3 + 16) - loc_50.a[0];
    v48 = *(f32 *)(v3 + 20) - loc_50.a[1];
    v49 = *(f32 *)(v3 + 24) - loc_50.a[2];
    v50 = v47 * v47;
    loc_5C.a[0] = v47;
    v50 = v48 * v48 + v50;
    loc_5C.a[1] = v48;
    loc_5C.a[2] = v49;
    v50 = v49 * v49 + v50;
    if (v50 > v45) {
    f32 sx;
    v1 = lbl_8006D0B4(v45 / v50);
    sx = loc_5C.a[0] * v1;
    sx = fn_1_11677C_operand(sx, loc_50.a[0]);
    *(f32 *)((u8 *)v3 + 16) = sx;
    *(f32 *)((u8 *)v3 + 20) = loc_50.a[1] + (f32)(loc_5C.a[1] * v1);
    *(f32 *)((u8 *)v3 + 24) = (f32)(loc_5C.a[2] * v1) + loc_50.a[2];
    *(struct fn_1_11677C_Copy12 *)((u8 *)v3 + 28) =
        *(struct fn_1_11677C_Copy12 *)((u8 *)v3 + 16);
    }
    v4++;
    v3 += 68;
    }
    }
    v1 = 0.0f;
    loc_38.a[1] = v1;
    loc_38.a[0] = 0.12399999797344208f;
    loc_38.a[2] = v1;
    v0 = *(u32 *)((u8 *)arg0 + 12);
    v0 = *(u32 *)(v0 + 336);
    v0 = *(u32 *)(v0 + 8);
    lab_t0 = (Vec3 *)(v0 + 532);
    lbl_8006DBAC((void *)lab_t0);
    lbl_8006E1B0((void *)((Vec3 *)&loc_38), (void *)((Vec3 *)&loc_38));
    v2 = *(u32 *)((u8 *)arg0 + 36);
    v3 = 0;
    while (v3 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(u8 *)(v2) & 1) == 0) {
    v1 = *(f32 *)(v2 + 16) - loc_38.a[0];
    v55 = *(f32 *)(v2 + 20) - loc_38.a[1];
    v56 = *(f32 *)(v2 + 24) - loc_38.a[2];
    v1 *= v1;
    v1 = v55 * v55 + v1;
    v1 = v56 * v56 + v1;
    if (v1 < 0.00774399982765317f) {
    v1 = lbl_8006D0E8(v1);
    psvec_sub_scale_add((u8 *)v2 + 16, &loc_38, 0.08799999952316284f * v1, &loc_44, (u8 *)v2 + 16);
    }
    }
    v3++;
    v2 += 68;
    }
    v1 = 0.0f;
    loc_20.a[1] = v1;
    loc_20.a[0] = 0.06400000303983688f;
    loc_20.a[2] = v1;
    v0 = *(u32 *)((u8 *)arg0 + 12);
    v0 = *(u32 *)(v0 + 336);
    v0 = *(u32 *)(v0 + 8);
    lab_t0 = (Vec3 *)(v0 + 532);
    lbl_8006DBAC((void *)lab_t0);
    lbl_8006E1B0((void *)((Vec3 *)&loc_20), (void *)((Vec3 *)&loc_20));
    v2 = *(u32 *)((u8 *)arg0 + 36);
    v3 = 0;
    while (v3 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(u8 *)(v2) & 1) == 0) {
    v1 = *(f32 *)(v2 + 16) - loc_20.a[0];
    v57 = *(f32 *)(v2 + 20) - loc_20.a[1];
    v58 = *(f32 *)(v2 + 24) - loc_20.a[2];
    v1 *= v1;
    v1 = v57 * v57 + v1;
    v1 = v58 * v58 + v1;
    if (v1 < 0.006888999603688717f) {
    v1 = lbl_8006D0E8(v1);
    psvec_sub_scale_add((u8 *)v2 + 16, &loc_20, 0.08299999684095383f * v1, &loc_2C, (u8 *)v2 + 16);
    }
    }
    v3++;
    v2 += 68;
    }
    v1 = 0.0f;
    loc_8.a[1] = v1;
    loc_8.a[0] = 0.01600000075995922f;
    loc_8.a[2] = v1;
    v0 = *(u32 *)((u8 *)arg0 + 12);
    v0 = *(u32 *)(v0 + 336);
    v0 = *(u32 *)(v0 + 8);
    lab_t0 = (Vec3 *)(v0 + 532);
    lbl_8006DBAC((void *)lab_t0);
    lbl_8006E1B0((void *)((Vec3 *)&loc_8), (void *)((Vec3 *)&loc_8));
    v2 = *(u32 *)((u8 *)arg0 + 36);
    v3 = 0;
    while (v3 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(u8 *)(v2) & 1) == 0) {
    v1 = *(f32 *)(v2 + 16) - loc_8.a[0];
    v59 = *(f32 *)(v2 + 20) - loc_8.a[1];
    v60 = *(f32 *)(v2 + 24) - loc_8.a[2];
    v1 *= v1;
    v1 = v59 * v59 + v1;
    v1 = v60 * v60 + v1;
    if (v1 < 0.00608400022611022f) {
    v1 = lbl_8006D0E8(v1);
    psvec_sub_scale_add((u8 *)v2 + 16, &loc_8, 0.07800000160932541f * v1, &loc_14, (u8 *)v2 + 16);
    }
    }
    v3++;
    v2 += 68;
    }
    v61 = 0.0f;
    fn_1_108BD0((void *)arg0, 7, 0.04500000178813934f, v61, v61, v61);
    v62 = 0.0f;
    fn_1_108BD0((void *)arg0, 7, 0.03700000047683716f, 0.029999999329447746f, v62, v62);
    v63 = 0.0f;
    fn_1_108BD0((void *)arg0, 7, 0.03700000047683716f, 0.05999999865889549f, v63, v63);
    v64 = 0.0f;
    fn_1_108BD0((void *)arg0, 7, 0.03700000047683716f, 0.09000000357627869f, v64, v64);
    v65 = 0.0f;
    fn_1_108BD0((void *)arg0, 12, 0.04500000178813934f, v65, v65, v65);
    v66 = 0.0f;
    fn_1_108BD0((void *)arg0, 12, 0.03700000047683716f, 0.029999999329447746f, v66, v66);
    v67 = 0.0f;
    fn_1_108BD0((void *)arg0, 12, 0.03700000047683716f, 0.05999999865889549f, v67, v67);
    v68 = 0.0f;
    fn_1_108BD0((void *)arg0, 12, 0.03700000047683716f, 0.09000000357627869f, v68, v68);
    v69 = *(u32 *)((u8 *)arg0 + 36);
    v0 = 0;
    v70 = 0.8;
    v71 = 0.2;
    v72 = v69;
    while (v0 < *(u32 *)((u8 *)arg0 + 24)) {
    v0++;
    *(f32 *)((u8 *)v72 + 52) *= v70;
    *(f32 *)((u8 *)v72 + 56) *= v70;
    *(f32 *)((u8 *)v72 + 60) *= v70;
    *(f32 *)((u8 *)v72 + 52) += (f64)(v71 * (f32)(*(f32 *)((u8 *)v72 + 16) - *(f32 *)((u8 *)v72 + 28)));
    *(f32 *)((u8 *)v72 + 56) += (f64)(v71 * (f32)(*(f32 *)((u8 *)v72 + 20) - *(f32 *)((u8 *)v72 + 32)));
    *(f32 *)((u8 *)v72 + 60) += (f64)(v71 * (f32)(*(f32 *)((u8 *)v72 + 24) - *(f32 *)((u8 *)v72 + 36)));
    v72 += 68;
    }
    v0 = *(u32 *)((u8 *)arg0 + 16);
    v3 = ((s32)fn_80077B14((void *)((struct Sig_fn_80077B14_fn_80077B14_Arg0_11677C *)v0)));
    v74 = *(u32 *)((u8 *)arg0 + 12);
    v75 = *(u32 *)(v74 + 336);
    lbl_8006DBAC((void *)((&((struct fn_1_11677C_Part *)*(u32 *)(v75 + 8))[lbl_1_data_3FFBC[*(u32 *)((u8 *)arg0 + 8)]].matrix)));
    v2 = *(u32 *)((u8 *)arg0 + 36);
    v77 = 0;
    while (v77 < *(u32 *)((u8 *)arg0 + 24)) {
    v76 = v2;
    v4 = 0;
    while ((s32)v4 < (s32)*(u8 *)(v2 + 2)) {
    fn_8006E250((void *)((Vec3f *)(v2 + 16)), (void *)((Vec3f *)(v3 + (*(u16 *)(v76 + 4) << 6))));
    v76 += 2;
    v4++;
    }
    v77++;
    v2 += 68;
    }
    }
    }
    }
}

#undef lbl_1_bss_89750
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef REL_MAIN_REL_ACCESSORY_H
/* fzgx:end fn_1_11677C */

/* fzgx:begin fn_1_1171B8 */
void fn_1_1171B8(Obj_1171B8 *obj) {
    Elem_1171B8 *a3;
    u32 i;
    Elem_1171B8 *a;
    Elem_1171B8 *a2;
    Elem_1171B8 *b2;
    u32 idx;
    u32 j;
    u32 j2;
    u32 n;
    Elem_1171B8 *b3;
    u32 per;

    if (obj != NULL) {
        per = strstr(lbl_1_data_3FCAC[obj->unk_8], "JACK__HAIR_MID_vtx") ? 4 : 3;
        fn_1_10846C((void *)obj);
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            if (a->unk_0 & 1) {
                a->unk_40 = -1.0f;
                a->unk_0 = 0;
            } else {
                a->unk_40 = 0.0f;
                a->unk_0 = 1;
            }
        }
        i = 0;
        a2 = obj->unk_24;
        for (; i < obj->unk_18; i++, a2++) {
            b2 = obj->unk_24 + i + 1;
            for (j2 = i + 1; j2 < obj->unk_18; j2++, b2++) {
                if (!(a2->unk_0 & 1) && (b2->unk_0 & 1)) {
                    fn_1_128884((void *)a2, (void *)b2, 0x44);
                }
            }
        }
        i = 0;
        a3 = obj->unk_24;
        for (; i < obj->unk_18; i++, a3++) {
            b3 = obj->unk_24 + i + 1;
            for (j = i + 1; j < obj->unk_18; j++, b3++) {
                if (a3->unk_0 == b3->unk_0 && a3->unk_18 > b3->unk_18) {
                    fn_1_128884((void *)a3, (void *)b3, 0x44);
                }
            }
        }
        n = (obj->unk_18 - 1) / per;
        for (i = 0; i < n; i++) {
            for (j = 0; j < per; j++) {
                idx = i * per + j;
                if (1.1920928955078125e-07f + obj->unk_24[idx].unk_40 < 0.0f) {
                    obj->unk_24[idx].unk_40 = -(f32)i / n;
                }
            }
        }
        obj->unk_24[per * n].unk_40 = -1.0f;
    }
}
/* fzgx:end fn_1_1171B8 */

/* fzgx:begin fn_1_117424 */
/* the node and rope layouts of fn_1_1188CC, which runs the same node loops */

#define ROPE_MODELS(r) ((r)->owner->list->models)

#define ROPE_INDEX(r) (lbl_1_data_3FFBC[(r)->kind])

/* Place every node at its model-space rest position. */

static inline void rope_reset_nodes(Rope_117424 *rope) {
    u32 i;
    RopeNode_1137E4 *n;

    lbl_8006DBAC(&ROPE_MODELS(rope)[ROPE_INDEX(rope)].mtx);
    lbl_8006DAEC();
    for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
        lbl_8006DBE4();
        lbl_8006E1B0(&n->local, &n->pos);
    }
    lbl_8006DC20();
}

/* Snap fixed (flag 1) nodes back to their model-space positions. */

static inline void rope_pin_fixed_nodes(Rope_117424 *rope) {
    u32 i;
    RopeModel_117424 *model;
    RopeNode_1137E4 *n;

    n = rope->nodes;
    model = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
    for (i = 0; i < rope->count; i++, n++) {
        lbl_8006DBAC(&model->mtx);
        lbl_8006DAEC();
        if (n->flags & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0(&n->local, &n->pos);
        }
        lbl_8006DC20();
    }
}

/* Move each free node by its velocity, then step it and its velocity down by constants. */

static inline void rope_step_free_nodes(Rope_117424 *rope) {
    u32 i;
    RopeNode_1137E4 *n;

    for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
        if (!(n->flags & 1)) {
            n->prev = n->pos;
            n->pos.x += n->vel.x;
            n->pos.y += n->vel.y;
            n->pos.z += n->vel.z;
            n->pos.y = n->pos.y - 0.0013611111376020642;
            n->vel.y -= 0.0027222223579883575f;
        }
    }
}

/* Set each node's velocity to 0.8 times its move since the stored previous position. */

static inline void rope_set_velocity(Rope_117424 *rope) {
    RopeNode_1137E4 *n;
    u32 i;

    for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
        n->vel.x = 0.8f * (n->pos.x - n->prev.x);
        n->vel.y = 0.8f * (n->pos.y - n->prev.y);
        n->vel.z = 0.8f * (n->pos.z - n->prev.z);
    }
}

/* Hand each node's position to fn_8006E250 once per linked skin entry. */

static inline void rope_skin(Rope_117424 *rope, SkinMtx *skin) {
    u32 i;
    s32 k;
    RopeNode_1137E4 *n;

    for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
        for (k = 0; k < n->linkCount; k++) {
            fn_8006E250(&n->pos, &skin[n->links[k]].v);
        }
    }
}

void fn_1_117424(Rope_117424 *rope) {
    u32 i;
    RopeNode_1137E4 *n;
    RopeModel_117424 *model;
    SkinMtx *skin;
    f32 scale;
    Vec3 delta;
    Vec3 tmp;

    if (rope != NULL && rope->skin != NULL) {
        fn_80077B14(rope->skin);
        strstr(lbl_1_data_3FCAC[rope->kind], "JACK__HAIR_MID_vtx");
        if (rope->flags & 2) {
            rope->flags &= ~2;
            rope_reset_nodes(rope);
        }

        rope_step_free_nodes(rope);

        rope_pin_fixed_nodes(rope);

        n = rope->nodes;
        model = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
        for (i = 0; i < rope->count; i++, n++) {
            if (!(n->flags & 1)) {
                lbl_8006DBAC(&model->mtx);
                lbl_8006E1B0(&n->local, &tmp);
                scale = -0.12f / n->mass;
                delta.x = scale * (tmp.x - n->pos.x);
                delta.y = 0.76 * (tmp.y - n->pos.y);
                delta.z = scale * (tmp.z - n->pos.z);
                n->pos.x += delta.x;
                n->pos.y += delta.y;
                n->pos.z += delta.z;
            }
        }

        rope_set_velocity(rope);

        skin = fn_80077B14(rope->skin);
        lbl_8006DBAC(&ROPE_MODELS(rope)[ROPE_INDEX(rope)].mtx);
        rope_skin(rope, skin);
    }
}
#undef ROPE_MODELS
#undef ROPE_INDEX
/* fzgx:end fn_1_117424 */

/* fzgx:begin fn_1_1177C4 */
/* VIEWS */
#define lbl_801A6410 ((void * *)&lbl_801A6410)
/* fzgx-allow: S2 pool primer sink */

/* (a - b) . (a - b): Super Monkey Ball's mathutil_vec_distance kernel without the sqrt. */

static inline f32 link_length(Link_1137E4 *l) {
    return fn_1_1289BC((void *)l->a, (void *)l->b);
}

void fn_1_1177C4(Rope_1177C4 *rope) {
    RopeNode_1137E4 tmp;
    char name[32];
    u32 i;
    RopeNode_1137E4 *dst;
    int left;
    u32 j;
    u32 k;
    u32 m;
    ModelList *list;
    ModelEntry *e;
    HairVtxCount *info;
    HairVtx *v;
    RopeNode_1137E4 *n;
    RopeNode_1137E4 *p;

    if (rope != NULL) {
        left = ((int)strstr(lbl_1_data_3FCAC[rope->kind], "PLISIA_HAIR_R_vtx")) == 0;
        fn_1_10846C((void *)rope);
        dst = rope->nodes;
        list = rope->owner->lists[rope->owner->sel];
        if (list != NULL) {
            for (i = 1; i <= 15; i++) {
                if (left) {
                    sprintf(name, "PLISIA_HAIR_L_%d_vtx", i);
                } else {
                    sprintf(name, "PLISIA_HAIR_R_%d_vtx", i);
                }
                for (j = 0, e = list->entries; j < list->count; j++, e++) {
                    if (strcmp((void *)e->name, (void *)name) == 0) {
                        break;
                    }
                }
                info = ((HairVtxCount *)fn_80077B64(e->model));
                v = fn_80077B14(e->model);
                for (k = 0; k < info->count; k++, v++) {
                    if (v->flags & 1) {
                        for (m = 0, n = rope->nodes; m < rope->count; m++, n++) {
                            if (mathutil_vec_sq_distance(&n->pos, &v->pos) < 1e-07) {
                                for (p = rope->nodes; p != dst; p++) {
                                    if (mathutil_vec_sq_distance(&p->pos, &n->pos) < 1e-07) {
                                        break;
                                    }
                                }
                                if (p == dst) {
                                    tmp = *dst;
                                    *dst = *n;
                                    *n = tmp;
                                    dst++;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
            if (i < 12) {
                n->mass = -0.5f;
                n->flags = 1;
            } else {
                f32 t = (i / 6) / 17.0f;
                n->mass = -t * t;
                n->flags = 0;
            }
        }

        rope->count2 = 15;
        rope->nodes2 = fn_1_4630((u32)lbl_801A6410[0], rope->count2 * sizeof(RopeNode_1137E4), "accessory.c", 0x1A0C);
        {
            u32 seg;
            RopeNode_1137E4 *src;
            RopeNode_1137E4 *out;
            u32 idx;
            idx = 0;
            out = rope->nodes2;
            src = rope->nodes;
            for (seg = 0; seg < 15; seg++, out++, idx++, src += 6) {
                Vec3 sum = {0.0f, 0.0f, 0.0f};
                for (j = 0, p = src; j < 6; j++, p++) {
                    sum.x += p->pos.x;
                    sum.y += p->pos.y;
                    sum.z += p->pos.z;
                }
                sum.x /= 6.0f;
                sum.y /= 6.0f;
                sum.z /= 6.0f;
                out->pos = sum;
                out->local = out->pos;
                if (idx == 0) {
                    out->mass = 0.0f;
                    out->flags = 1;
                } else {
                    out->mass = -0.7f * idx / rope->count2;
                    out->flags = 0;
                }
            }
            if (out - rope->nodes2 != 15U) {
                OSPanic("accessory.c", 0x1A31, "stop..");
            }
        }

        rope->linkCount = 14;
        rope->links = fn_1_4630((u32)lbl_801A6410[0], rope->linkCount * sizeof(Link_1137E4), "accessory.c", 0x1A37);
        for (i = 0; i < 14; i++) {
            rope->links[i].a = &rope->nodes2[i];
            rope->links[i].b = &rope->nodes2[i + 1];
            rope->links[i].length = link_length(&rope->links[i]);
        }
    }
}
#undef lbl_801A6410
/* fzgx:end fn_1_1177C4 */

/* fzgx:begin fn_1_117D5C */
#define ROPE_MODELS(r) ((r)->owner->list->models)

#define ROPE_INDEX(r) (lbl_1_data_3FFBC[(r)->kind])

/* Hand each node's position to fn_8006E250 once per linked skin entry. */

static inline void rope_skin_117D5C(Rope_117D5C *rope, SkinMtx *skin) {
    u32 i;
    s32 k;
    RopeNode_1137E4 *n;

    for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
        for (k = 0; k < n->linkCount; k++) {
            fn_8006E250(&n->pos, &skin[n->links[k]].v);
        }
    }
}

void fn_1_117D5C(Rope_117D5C *rope) {
    Vec3 d;
    Vec3 *dp = &d;
    Vec3 b2;
    Vec3 tmp;
    f32 len;
    RopeModel_117424 *model4;
    u32 i5;
    u32 i4;
    u32 i2;
    u32 i3;
    u32 i9;
    RopeNode_1137E4 *n4;
    RopeModel_117424 *model8;
    SkinMtx *skin;
    u32 i7;
    RopeModel_117424 *model7;
    RopeNode_1137E4 *p;
    RopeNode_1137E4 *n5;
    RopeNode_1137E4 *n2;
    u32 j6;
    RopeNode_1137E4 *first;
    u32 i8;
    u32 k8;
    RopeNode_1137E4 *n7;
    u32 k6;
    RopeNode_1137E4 *n9;
    RopeNode_1137E4 *b;
    u32 j8;
    RopeNode_1137E4 *a;
    RopeNode_1137E4 *n3;
    RopeNode_1137E4 *n1;
    RopeNode_1137E4 *n8;
    RopeModel_117424 *model1;
    Link_1137E4 *l;
    u32 i1;
    f32 inv;
    f32 r;
    f32 wa;
    f32 wb;
    f32 sa;
    f32 sb;
    f32 scale;
    f32 dy;
    f32 dx;
    f32 dz;

    if (rope != NULL && rope->skin != NULL) {
        fn_80077B14(rope->skin);
        strstr(lbl_1_data_3FCAC[rope->kind], "JACK__HAIR_MID_vtx");
        if (rope->flags & 2) {
            rope->flags &= ~2;
            model1 = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
            for (i1 = 0, n1 = rope->nodes; i1 < rope->count; i1++, n1++) {
                lbl_8006DBAC(&model1->mtx);
                lbl_8006E1B0(&n1->local, &n1->pos);
            }
            for (i2 = 0, n2 = rope->nodes2; i2 < rope->count2; i2++, n2++) {
                lbl_8006DBAC(&model1->mtx);
                lbl_8006E1B0(&n2->local, &n2->pos);
            }
        }

        for (i3 = 0, n3 = rope->nodes2; i3 < rope->count2; i3++, n3++) {
            if (!(n3->flags & 1)) {
                n3->prev = n3->pos;
                n3->pos.x += n3->vel.x;
                n3->pos.y += n3->vel.y;
                n3->pos.z += n3->vel.z;
                n3->pos.y = n3->pos.y - 0.0013611111376020642;
                n3->vel.y -= 0.0027222223579883575f;
            }
        }

        model4 = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
        for (i4 = 0, n4 = rope->nodes; i4 < rope->count; i4++, n4++) {
            if (n4->flags & 1) {
                lbl_8006DBAC(&model4->mtx);
                lbl_8006E1B0(&n4->local, &n4->pos);
            }
        }
        for (i5 = 0, n5 = rope->nodes2; i5 < rope->count2; i5++, n5++) {
            if (n5->flags & 1) {
                lbl_8006DBAC(&model4->mtx);
                lbl_8006E1B0(&n5->local, &n5->pos);
            }
        }

        for (k6 = 0; k6 < 4; k6++) {
            for (j6 = 0, l = rope->links; j6 < rope->linkCount; j6++, l++) {
                a = l->a;
                b = l->b;
                if (a != NULL && b != NULL) {
                    dx = a->pos.x - b->pos.x;
                    dy = a->pos.y - b->pos.y;
                    dz = a->pos.z - b->pos.z;
                    len = mathutil_sum_of_sq_3(dx, dy, dz);
                    dp->x = dx;
                    dp->y = dy;
                    dp->z = dz;
                    if (len - 0.0001f > l->length) {
                        inv = lbl_8006D118(len, &len);
                        r = lbl_8006D0B4(l->length);
                        len = inv * (len - r);
                        dp->x *= len;
                        dp->y *= len;
                        dp->z *= len;
                        wa = a->mass;
                        wb = b->mass;
                        r = 1.0f / (wa + wb);
                        sa = wa * r;
                        sb = wb * r;
                        a->pos.x -= (f32)(dp->x * sa);
                        a->pos.y -= (f32)(dp->y * sa);
                        a->pos.z -= (f32)(dp->z * sa);
                        b->pos.x += (f32)(dp->x * sb);
                        b->pos.y += (f32)(dp->y * sb);
                        b->pos.z += (f32)(dp->z * sb);
                    }
                    if (len - 0.001f < l->length) {
                        f32 dy;
                        f32 dx;
                        f32 dz;
                        if (a->pos.y < 0.0f) {
                            a->pos.y = 1e-05f;
                        }
                        if (b->pos.y < 0.0f) {
                            b->pos.y = 1e-05f;
                        }
                        dx = a->pos.x - b->pos.x;
                        dy = a->pos.y - b->pos.y;
                        dz = a->pos.z - b->pos.z;
                        len = mathutil_sum_of_sq_3(dx, dy, dz);
                        dp->x = dx;
                        dp->y = dy;
                        dp->z = dz;
                        inv = lbl_8006D118(len, &len);
                        r = lbl_8006D0B4(l->length);
                        len = inv * (len - r);
                        dp->x *= len;
                        dp->y *= len;
                        dp->z *= len;
                        wa = a->mass;
                        wb = b->mass;
                        r = 1.0f / (wa + wb);
                        sa = wa * r;
                        sb = wb * r;
                        a->pos.x -= (f32)(dp->x * sa);
                        a->pos.y -= (f32)(dp->y * sa);
                        a->pos.z -= (f32)(dp->z * sa);
                        b->pos.x += (f32)(dp->x * sb);
                        b->pos.y += (f32)(dp->y * sb);
                        b->pos.z += (f32)(dp->z * sb);
                    }
                }
            }
        }

        model7 = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
        for (i7 = 0, n7 = rope->nodes2; i7 < rope->count2; i7++, n7++) {
            if (!(n7->flags & 1)) {
                lbl_8006DBAC(&model7->mtx);
                lbl_8006E1B0(&n7->local, &tmp);
                scale = (f32)i7 / rope->count2;
                scale = 1.0f - scale;
                b2.x = (tmp.x - n7->pos.x) * (0.2f * scale * (1.0f + n7->mass));
                b2.y = (tmp.y - n7->pos.y) * (0.2f * scale * (1.0f + n7->mass));
                b2.z = (tmp.z - n7->pos.z) * (0.2f * scale * (1.0f + n7->mass));
                n7->pos.x += b2.x;
                n7->pos.y += b2.y;
                n7->pos.z += b2.z;
            }
        }

        model8 = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
        first = rope->nodes;
        for (i8 = 0; i8 < rope->count; i8++, first++) {
            if (!(first->flags & 1)) {
                break;
            }
        }
        n8 = rope->nodes2;
        n8++;
        for (k8 = 0; k8 < 14; k8++, first += 6, n8++) {
            lbl_8006DBAC(&model8->mtx);
            lbl_8006E1B0(&n8->local, &b2);
            dp->x = n8->pos.x - b2.x;
            dp->y = n8->pos.y - b2.y;
            dp->z = n8->pos.z - b2.z;
            for (j8 = 0, p = first; j8 < 6; j8++, p++) {
                lbl_8006DBAC(&model8->mtx);
                lbl_8006E1B0(&p->local, &b2);
                p->pos.x = b2.x + dp->x;
                p->pos.y = b2.y + dp->y;
                p->pos.z = b2.z + dp->z;
            }
        }

        for (i9 = 0, n9 = rope->nodes2; i9 < rope->count2; i9++, n9++) {
            n9->vel.x = n9->pos.x - n9->prev.x;
            n9->vel.y = n9->pos.y - n9->prev.y;
            n9->vel.z = n9->pos.z - n9->prev.z;
            n9->vel.x *= 0.9f;
            n9->vel.z *= 0.9f;
            if (n9->vel.y > 0.0f) {
                n9->vel.y *= 0.8f;
            }
        }

        skin = fn_80077B14(rope->skin);
        lbl_8006DBAC(&ROPE_MODELS(rope)[ROPE_INDEX(rope)].mtx);
        rope_skin_117D5C(rope, skin);
    }
}
#undef ROPE_MODELS
#undef ROPE_INDEX
/* fzgx:end fn_1_117D5C */

/* fzgx:begin fn_1_1185B4 */
void fn_1_1185B4(Obj1185B4 *obj) {

    u32 i;
    Elem1185B4 *a;
    u32 j;
    Elem1185B4 *b;
    s32 flag;
    u32 n;
    u32 idx;

    if (obj != NULL) {
        flag = strstr(lbl_1_data_3FCAC[obj->unk_8], "EAD_HIGE_R_vtx") != 0;
        fn_1_10846C((void *)obj);
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            if (a->unk_0 & 1) {
                a->unk_40 = -1.0f;
                a->unk_0 = 0;
            } else {
                a->unk_40 = 0.0f;
                a->unk_0 = 1;
            }
        }
        i = 0;
        a = obj->unk_24;
        for (; i < obj->unk_18; i++, a++) {
            b = obj->unk_24 + i + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (!(a->unk_0 & 1) && (b->unk_0 & 1)) {
                    fn_1_128884((void *)a, (void *)b, 0x44);
                }
            }
        }
        i = 0;
        a = obj->unk_24;
        for (; i < obj->unk_18; i++, a++) {
            if (flag) {
                b = obj->unk_24 + i + 1;
                for (j = i + 1; j < obj->unk_18; j++, b++) {
                    if (a->unk_0 == b->unk_0 && a->unk_14 < b->unk_14) {
                        fn_1_128884((void *)a, (void *)b, 0x44);
                    }
                }
            } else {
                b = obj->unk_24 + i + 1;
                for (j = i + 1; j < obj->unk_18; j++, b++) {
                    if (a->unk_0 == b->unk_0 && a->unk_14 > b->unk_14) {
                        fn_1_128884((void *)a, (void *)b, 0x44);
                    }
                }
            }
        }
        n = (obj->unk_18 - 1) / 4;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 4; j++) {
                idx = i * 4 + j;
                if (0.00000011920929f + obj->unk_24[idx].unk_40 < 0.0f) {
                    obj->unk_24[idx].unk_40 = -fn_1_128AAC(i, 2.0f);
                    obj->unk_24[idx].unk_40 /= fn_1_128AAC(n, 2.0f);
                    obj->unk_24[idx].unk_40 *= 0.75f;
                    obj->unk_24[idx].unk_40 -= 0.25f;
                }
            }
        }
        obj->unk_24[n * 4].unk_40 = -1.0f;
    }
}
/* fzgx:end fn_1_1185B4 */

/* fzgx:begin fn_1_1188CC */
/* VIEWS */
/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define ROPE_MODELS(r) ((r)->owner->list->models)

#define ROPE_INDEX(r) (lbl_1_data_3FFBC[(r)->kind])

/* Place every node at its model-space rest position. */

static inline void rope_reset_nodes_1188CC(Rope_1188CC *rope) {
    u32 i;
    RopeNode_1137E4 *n;

    lbl_8006DBAC((void *)(&ROPE_MODELS(rope)[ROPE_INDEX(rope)].mtx));
    lbl_8006DAEC();
    for (i = 0, n = rope->nodes; i < rope->count; i++, n++) {
        lbl_8006DBE4();
        lbl_8006E1B0((void *)((Vec3 *)&n->local), (void *)((Vec3 *)&n->pos));
    }
    lbl_8006DC20();
}

/* Snap fixed (flag 1) nodes back to their model-space positions. */

static inline void rope_pin_fixed_nodes_1188CC(Rope_1188CC *rope) {
    u32 i;
    RopeModel_117424 *model;
    RopeNode_1137E4 *n;

    n = rope->nodes;
    model = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
    for (i = 0; i < rope->count; i++, n++) {
        lbl_8006DBAC((void *)&model->mtx);
        lbl_8006DAEC();
        if (n->flags & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0((void *)((Vec3 *)&n->local), (void *)((Vec3 *)&n->pos));
        }
        lbl_8006DC20();
    }
}

void fn_1_1188CC(Rope_1188CC *rope) {

    RopeNode_1137E4 *n7;
    s32 k7;
    u32 i7;
    SkinMtx *skin;
    u32 i;
    RopeNode_1137E4 *node;
    RopeModel_117424 *model;
    u32 j;
    RopeNode_1137E4 *n4;
    u32 i4;
    RopeNode_1137E4 *n2;
    u32 i2;
    RopeNode_1137E4 *n6;
    u32 i6;
    f32 scale;
    Vec3 delta;
    Vec3 tmp;

    if (rope != NULL && rope->skin != NULL) {
    ((s32)fn_80077B14((void *)rope->skin));
    if (rope->flags & 2) {
        rope->flags &= ~2;
        rope_reset_nodes_1188CC(rope);
    }

    for (i2 = 0, n2 = rope->nodes; i2 < rope->count; i2++, n2++) {
        if (!(n2->flags & 1)) {
            n2->prev = n2->pos;
            n2->pos.x += n2->vel.x;
            n2->pos.y += n2->vel.y;
            n2->pos.z += n2->vel.z;
            n2->pos.y = n2->pos.y - 0.0013611111376020642;
            n2->vel.y -= 0.0027222224f;
        }
    }

    rope_pin_fixed_nodes_1188CC(rope);

    n4 = rope->nodes;
    model = &ROPE_MODELS(rope)[ROPE_INDEX(rope)];
    for (i4 = 0; i4 < rope->count; i4++, n4++) {
        if (!(n4->flags & 1)) {
            lbl_8006DBAC((void *)&model->mtx);
            lbl_8006E1B0((void *)((Vec3 *)&n4->local), (void *)((Vec3 *)&tmp));
            scale = -0.25f / n4->mass;
            delta.x = scale * (tmp.x - n4->pos.x);
            delta.y = scale * (tmp.y - n4->pos.y);
            delta.z = scale * (tmp.z - n4->pos.z);
            n4->pos.x = n4->pos.x + delta.x;
            n4->pos.y = n4->pos.y + delta.y;
            n4->pos.z = n4->pos.z + delta.z;
        }
    }

    node = rope->nodes;
    for (i = 0; i < (rope->count - 1) / 4; i++, node += 4) {
        lbl_8006DBAC((void *)&model->mtx);
        lbl_8006E1B0((void *)((Vec3 *)&node->local), (void *)((Vec3 *)&delta));
        node->prev = delta;
        delta.x = node->pos.x - delta.x;
        delta.y = node->pos.y - delta.y;
        delta.z = node->pos.z - delta.z;
        node->prev = node->pos;
        for (j = 1; j < 4; j++) {
            lbl_8006DBAC((void *)&model->mtx);
            lbl_8006E1B0((void *)((Vec3 *)&node[j].local), (void *)((Vec3 *)&node[j].pos));
            node[j].pos.x += delta.x;
            node[j].pos.y += delta.y;
            node[j].pos.z += delta.z;
            node[j].prev = node[j].pos;
        }
    }
    node->prev = node->pos;

    for (i6 = 0, n6 = rope->nodes; i6 < rope->count; i6++, n6++) {
        n6->vel.x = 1.2f * (n6->pos.x - n6->prev.x);
        n6->vel.y = 1.2f * (n6->pos.y - n6->prev.y);
        n6->vel.z = 1.2f * (n6->pos.z - n6->prev.z);
    }

    skin = (SkinMtx *)((s32)fn_80077B14((void *)rope->skin));
    lbl_8006DBAC((void *)(&ROPE_MODELS(rope)[ROPE_INDEX(rope)].mtx));
    for (i7 = 0, n7 = rope->nodes; i7 < rope->count; i7++, n7++) {
        for (k7 = 0; k7 < n7->linkCount; k7++) {
            fn_8006E250((void *)((Vec3 *)&n7->pos), (void *)&skin[n7->links[k7]].v);
        }
    }
    }
}
#undef GAME_VEC3_H
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef ROPE_MODELS
#undef ROPE_INDEX
/* fzgx:end fn_1_1188CC */

/* fzgx:begin fn_1_118D90 */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/shared_types.h */

/* game/main_rel/shared_types.h: inlined above */

/* game/main_rel/shared_types.h: inlined above */

/* end game/main_rel/accessory_types.h */

void fn_1_118D90(u32 arg0, f32 arg1) {
    f32 v8;
    f32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v5;
    u32 v7;
    u32 v10;
    u32 v11;
    u32 v4;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v16;
    u32 v19;
    u32 v21;
    u32 v23;
    u32 v24;
    s32 v25;
    u32 v26;
    u32 v27;
    u32 v28;
    u32 v29;
    u32 v30;
    u32 v31;
    u32 v32;
    u32 t9;
    f32 t10;
    f32 t11;
    f32 t12;
    v0 = arg1;
    v1 = arg0;
    if (arg0 != 0) {
        fn_1_10846C((void *)((Obj10846C *)v1));
        v7 = *(u32 *)(arg0 + 36);
        v2 = 0;
        v0 = -1.0f;
        v5 = 0;
        v8 = 0.0f;
        v1 = 1;
        while (v2 < *(u32 *)(arg0 + 24)) {
            if ((*(u8 *)(v7) & 0x1) != 0) {
                *(u8 *)((u8 *)v7 + 0) = v5;
                *(f32 *)((u8 *)v7 + 64) = v0;
            } else {
                *(u8 *)((u8 *)v7 + 0) = v1;
                *(f32 *)((u8 *)v7 + 64) = v8;
            }
            v2++;
            v7 += 68;
        }
        v2 = 0;
        v10 = *(u32 *)(arg0 + 36);
        v11 = v10;
        while (v2 < *(u32 *)(arg0 + 24)) {
            v3 = v2 * 68;
            v4 = v2 + 1;
            v12 = *(u32 *)(arg0 + 36) + v3 + 68;
            v13 = v12;
            while (v4 < *(u32 *)(arg0 + 24)) {
                if (*(u8 *)v11 != 0 && *(u8 *)v13 == 0) {
                    fn_1_128884((void *)v11, (void *)v13, 68);
                }
                v4++;
                v13 += 68;
            }
            v2++;
            v11 += 68;
        }
        v2 = 0;
        v14 = *(u32 *)(arg0 + 36);
        v11 = v14;
        while (v2 < *(u32 *)(arg0 + 24)) {
            v3 = v2 * 68;
            v4 = v2 + 1;
            v16 = *(u32 *)(arg0 + 36) + v3 + 68;
            v13 = v16;
            while (v4 < *(u32 *)(arg0 + 24)) {
                if (*(u8 *)v11 == *(u8 *)v13 &&
                    *(f32 *)((u8 *)v11 + 16) < *(f32 *)((u8 *)v13 + 16)) {
                    fn_1_128884((void *)v11, (void *)v13, 68);
                }
                v4++;
                v13 += 68;
            }
            v2++;
            v11 += 68;
        }
        v1 = *(u32 *)(arg0 + 12);
        if (*(s32 *)(v1 + 136) == 41) {
            v2 = 0;
            v11 = *(u32 *)(arg0 + 36);
            while (v2 < *(u32 *)(arg0 + 24)) {
                v3 = v2 * 68;
                v4 = v2 + 1;
                v19 = *(u32 *)(arg0 + 36) + v3 + 68;
                v13 = v19;
                while (v4 < *(u32 *)(arg0 + 24)) {
                    if (*(u8 *)v11 == 0 && *(u8 *)v13 == 0 &&
                        *(f32 *)((u8 *)v11 + 20) < *(f32 *)((u8 *)v13 + 20)) {
                        fn_1_128884((void *)v11, (void *)v13, 68);
                    } else if (*(u8 *)v11 != 0 && *(u8 *)v13 != 0 &&
                        *(f32 *)((u8 *)v11 + 16) < 0.025f &&
                        *(f32 *)((u8 *)v13 + 16) < 0.025f &&
                        *(f32 *)((u8 *)v11 + 20) < *(f32 *)((u8 *)v13 + 20)) {
                        fn_1_128884((void *)v11, (void *)v13, 68);
                    } else if (*(u8 *)v11 != 0 && *(u8 *)v13 != 0 &&
                        *(f32 *)((u8 *)v11 + 16) > 0.025f &&
                        *(f32 *)((u8 *)v13 + 16) > 0.025f &&
                        *(f32 *)((u8 *)v11 + 20) < *(f32 *)((u8 *)v13 + 20)) {
                        fn_1_128884((void *)v11, (void *)v13, 68);
                    }
                    v4++;
                    v13 += 68;
                }
                v2++;
                v11 += 68;
            }
        } else {
            v2 = 0;
            v11 = *(u32 *)(arg0 + 36);
            while (v2 < *(u32 *)(arg0 + 24)) {
                v3 = v2 * 68;
                v4 = v2 + 1;
                v21 = *(u32 *)(arg0 + 36) + v3 + 68;
                v13 = v21;
                while (v4 < *(u32 *)(arg0 + 24)) {
                    if (*(u8 *)v11 == 0 && *(u8 *)v13 == 0 &&
                        *(f32 *)((u8 *)v11 + 20) < *(f32 *)((u8 *)v13 + 20)) {
                        fn_1_128884((void *)v11, (void *)v13, 68);
                    } else if (*(u8 *)v11 != 0 && *(u8 *)v13 != 0 &&
                        *(f32 *)((u8 *)v11 + 16) < 0.08f &&
                        *(f32 *)((u8 *)v13 + 16) < 0.08f &&
                        *(f32 *)((u8 *)v11 + 20) < *(f32 *)((u8 *)v13 + 20)) {
                        fn_1_128884((void *)v11, (void *)v13, 68);
                    } else if (*(u8 *)v11 != 0 && *(u8 *)v13 != 0 &&
                        *(f32 *)((u8 *)v11 + 16) > 0.08f &&
                        *(f32 *)((u8 *)v13 + 16) > 0.08f &&
                        *(f32 *)((u8 *)v11 + 20) < *(f32 *)((u8 *)v13 + 20)) {
                        fn_1_128884((void *)v11, (void *)v13, 68);
                    }
                    v4++;
                    v13 += 68;
                }
                v2++;
                v11 += 68;
            }
        }
        *(u32 *)((u8 *)arg0 + 28) = 20;
        v1 = lbl_801A6410;
        t9 = ((u32)fn_1_4630(v1, *(u32 *)(arg0 + 28) * 12, "accessory.c", 0x1c51));
        *(u32 *)((u8 *)arg0 + 40) = t9;
        {
            struct { u32 value; } val26;
            struct { u32 value; } val25;
            struct { u32 value; } val24;
            struct { u32 value; } index;
#define v26 val26.value
#define v25 val25.value
#define v24 val24.value
            u32 v23;
            u32 v3;
#define v4 index.value
        v26 = 0;
        v25 = 0;
        v24 = 0;
        v4 = 0;
        v25 = v4;
        v3 = 0;
        v23 = *(u32 *)(arg0 + 36);
        v26 = v23;
        v24 = v23;
        while (v4 < 4) {
            v27 = v24 + 272;
            *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v25) = v26;
            v28 = *(u32 *)(arg0 + 40);
            *(u32 *)((u8 *)v28 + v25 + 4) = v27;
            t10 = fn_1_1289BC((void *)((const Point1024C4 *)v26), (void *)((const Point1024C4 *)v27));
            v29 = v24 + 340;
            *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v25 + 8) = t10;
            v2 = (v3 + 1) * 12;
            *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v2) = v26;
            v30 = *(u32 *)(arg0 + 40);
            *(u32 *)((u8 *)v30 + v2 + 4) = v29;
            t11 = fn_1_1289BC((void *)((const Point1024C4 *)v26), (void *)((const Point1024C4 *)v29));
            v31 = v24 + 408;
            *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v2 + 8) = t11;
            v2 = (v3 + 2) * 12;
            *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v2) = v26;
            v32 = *(u32 *)(arg0 + 40);
            *(u32 *)((u8 *)v32 + v2 + 4) = v31;
            t12 = fn_1_1289BC((void *)((const Point1024C4 *)v26), (void *)((const Point1024C4 *)v31));
            v4++;
            *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v2 + 8) = t12;
            v25 += 36;
            v3 += 3;
            v26 += 68;
            v24 += 136;
        }
        v4 = 4;
        while (v4 < 12) {
            v26 = v23 + v4 * 68;
            v25 = v3 * 12;
            v27 = v26 + 68;
            *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v25) = v26;
            v28 = *(u32 *)(arg0 + 40);
            *(u32 *)((u8 *)v28 + v25 + 4) = v27;
            t10 = fn_1_1289BC((void *)((const Point1024C4 *)v26), (void *)((const Point1024C4 *)v27));
            v4++;
            *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 40) + v25 + 8) = t10;
            v3++;
        }
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
#undef v26
#undef v25
#undef v24
#undef v4
/* fzgx:end fn_1_118D90 */

/* fzgx:begin fn_1_1192D0 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

static inline void fn_1_1192D0_sphere(Work_1192D0 *arg0, s32 base, f32 cx, f32 cy, f32 cz, f32 ro, f32 so) {
 Vec3 center;
 Vec3 diff;
 u32 ki;
 Node *kn;
 f32 scale;
 center.y=cy; center.x=cx; center.z=cz;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+base)));
 lbl_8006E1B0((void *)&center,(void *)&center);
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) {
 if(!(kn->flags&1)) {
 f32 x,y,z,r;
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z;
 x-=center.x; y-=center.y; z-=center.z;
 r=(f32)(x*x)+y*y+z*z;
 if(r<ro) {
 scale=so*lbl_8006D0E8(r);
 psvec_sub_scale_add(&kn->pos,&center,scale,&diff,&kn->pos);
 }
 }
 }
}

#define SPHERE(BASE, CX, CY, CZ, RO, SO) fn_1_1192D0_sphere(arg0, BASE, CX, CY, CZ, RO, SO);

static inline void fn_1_1192D0_loop0(Work_1192D0 *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
}

#define delta (*dp)

static inline void fn_1_1192D0_constrain(Node *a, Node *b, Link *l, f32 *len, Vec3 *dp) {
 f32 wb;
 f32 inv;
 f32 s;
 f32 wa;
 f32 fb;
 f32 r;
 f32 fa;
 f32 cx;
 f32 cy;
 f32 cz;
 f32 x;
 inv=lbl_8006D118(*len,len);
 r=lbl_8006D0B4(l->length);
 s=inv*(*len-r);
 *len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
}

#undef delta

static inline void fn_1_1192D0_loop6(u8 *fmodel, Work_1192D0 *arg0) {
 u16 *lp;
 u32 fi;
 u32 fj;
 Node *fn;
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
}

static inline void fn_1_1192D0_loop1(Work_1192D0 *arg0) {
 u32 i3;
 u8 *model3;
 Node *n3;
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
}

void fn_1_1192D0(Work_1192D0 *arg0) {
 u32 ki;
 u8 *fmodel;
 u32 li;
 u32 vi;
 u32 k;
 Node *kn;
 Node *vn;
 Link *l;
 Node *a;
 Node *n2;
 u32 i2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Node *b;
 Vec3 deltav;
 Vec3 random;
 Vec3 target;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 fn_1_1192D0_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 fn_1_1192D0_loop1(arg0);
 for(k=0;k<4;k++) {
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) fn_1_1192D0_constrain(a,b,l,&len,dp);
 }
 }
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 f32 kk;
 f32 x;
 f32 y;
 f32 z;
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target);
 kk=-0.25f/n6->weight;
 x=kk*(target.x-n6->pos.x);
 y=kk*(target.y-n6->pos.y);
 z=kk*(target.z-n6->pos.z);
 n6->pos.x+=x;
 n6->pos.y+=y;
 n6->pos.z+=z;
 }
 }
 if(arg0->owner->kind==0x29) {
 SPHERE(0x1c60,0.045f,0.0f,0.0f,0.004356f,0.066f)
 SPHERE(0x1c60,0.057f,0.0f,0.0f,0.0037210002f,0.061f)
 SPHERE(0x241c,0.045f,0.0f,0.0f,0.004356f,0.066f)
 SPHERE(0x241c,0.057f,0.0f,0.0f,0.0037210002f,0.061f)
 } else if(arg0->owner->kind==0x15) {
 SPHERE(0x1c60,0.037f,0.0f,0.0f,0.0050410004f,0.071f)
 SPHERE(0x1c60,0.07f,0.0f,0.0f,0.010000001f,0.1f)
 SPHERE(0x1c60,0.1f,0.0f,0.0f,0.010000001f,0.1f)
 SPHERE(0x241c,0.037f,0.0f,0.0f,0.0050410004f,0.071f)
 SPHERE(0x241c,0.07f,0.0f,0.0f,0.010000001f,0.1f)
 SPHERE(0x241c,0.1f,0.0f,0.0f,0.010000001f,0.1f)
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.8; vn->vel.y*=0.8; vn->vel.z*=0.8;
 vn->vel.x+=(f64)(0.2*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.2*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.2*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 fn_1_1192D0_loop6(fmodel, arg0);
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef SPHERE
#undef delta
/* fzgx:end fn_1_1192D0 */

/* fzgx:begin fn_1_11A158 */
/* VIEWS */
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

/* rel/main_rel/accessory.h: inlined above */

void fn_1_11A158(fn_1_10D2F0_Obj *obj) {
    u32 div;
    u32 j;
    Entry_11A158 *a;
    u32 k;
    u32 rows;
    u32 i;
    u32 count;
    u32 n;
    u32 q;
    Entry_11A158 *base;
    Entry_11A158 *p;
    Entry_11A158 *b;
    f32 num;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        for (i = 0, p = obj->unk_24; i < obj->unk_18; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_0 = 0;
                p->unk_40 = -1.0f;
            } else {
                p->unk_0 = 1;
                p->unk_40 = 0.0f;
            }
        }

        for (i = 0, p = obj->unk_24; i < obj->unk_18; i++, p++) {
            for (j = i + 1, a = obj->unk_24 + i + 1; j < obj->unk_18; j++, a++) {
                if (p->unk_0 == 0 && a->unk_0 != 0) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_11A158));
                }
            }
        }

        for (i = 0, p = obj->unk_24; i < obj->unk_18; i++, p++) {
            for (j = i + 1, a = obj->unk_24 + i + 1; j < obj->unk_18; j++, a++) {
                if (p->unk_0 == a->unk_0 && p->unk_10.x < a->unk_10.x) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_11A158));
                }
            }
        }

        for (i = 0, p = obj->unk_24; i < obj->unk_18 / 13; i++, p += 13) {
            for (j = 0, a = p; j < 13; j++, a++) {
                for (k = j + 1, b = a + 1; k < 13; k++, b++) {
                    if (a->unk_10.z < b->unk_10.z) {
                        fn_1_128884((void *)a, (void *)b, sizeof(Entry_11A158));
                    }
                }
            }
        }

        /* first row: positive-z entries by descending y, the rest by ascending y */
        for (i = 0, p = obj->unk_24; i < 13; i++, p++) {
            for (j = i + 1, a = p + 1; j < 13; j++, a++) {
                if (p->unk_10.z > 0.0f && a->unk_10.z > 0.0f && p->unk_10.y > a->unk_10.y) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_11A158));
                } else if (p->unk_10.z <= 0.0f && a->unk_10.z <= 0.0f && p->unk_10.y < a->unk_10.y) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_11A158));
                }
            }
        }

        base = obj->unk_24;
        count = obj->unk_18;
        p = base;
        for (i = 0; i < count; i++) {
            if (p->unk_0 != 0 && p[1].unk_0 == 0) {
                break;
            }
            p++;
        }
        p++;
        rows = (count - (p - base)) / 13;
        div = rows + 1;
        for (i = 0; i < rows; i++, p += 13) {
            num = -(f32)(i + 1);
            for (j = 0; j < 13; j++) {
                p[j].unk_40 = num / div;
            }
            for (j = 0, a = p; j < 13; j++, a++) {
                for (k = j + 1, b = a + 1; k < 13; k++, b++) {
                    if (a->unk_10.z > 0.0f && b->unk_10.z > 0.0f && a->unk_10.y > b->unk_10.y) {
                        fn_1_128884((void *)a, (void *)b, sizeof(Entry_11A158));
                    } else if (a->unk_10.z <= 0.0f && b->unk_10.z <= 0.0f && a->unk_10.y < b->unk_10.y) {
                        fn_1_128884((void *)a, (void *)b, sizeof(Entry_11A158));
                    }
                }
            }
        }

        q = obj->unk_18 / 13;
        obj->unk_1C = q * 12 + (q - 1) * 13;
        obj->unk_28 = (fn_1_10D2F0_Link *)((u32)fn_1_4630(lbl_801A6410, obj->unk_1C * sizeof(fn_1_10D2F0_Link), "accessory.c", 0x1D66));

        n = 0;
        p = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 1; i++, p++) {
            if ((i + 1) % 13 != 0) {
                obj->unk_28[n].a = p;
                obj->unk_28[n].b = p + 1;
                obj->unk_28[n].len = fn_1_1289BC((const Point1024C4 *)p, (const Point1024C4 *)(p + 1));
                n++;
            }
        }

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 13; n++, i++, p++) {
            obj->unk_28[n].a = p;
            obj->unk_28[n].b = p + 13;
            obj->unk_28[n].len = fn_1_1289BC((const Point1024C4 *)p, (const Point1024C4 *)(p + 13));
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_11A158 */

/* fzgx:begin fn_1_11A774 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

#define SPHERE(BASE, CX, CY, CZ, RADIUS, STRENGTH) { \
 Vec3 diff; \
 Vec3 center; \
 f32 scale; \
 f32 cx,cy,cz; \
 cz=CZ; cy=CY; cx=CX; \
 vec_set_xyz(&center,cx,cy,cz); \
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+BASE))); \
 lbl_8006E1B0((void *)&center,(void *)&center); \
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) { \
 if(!(kn->flags&1)) { \
 f32 x,z,y,r; \
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z; \
 x-=center.x; y-=center.y; z-=center.z; \
 r=(f32)(x*x)+y*y+z*z; \
 if(r<RADIUS) { \
 scale=STRENGTH*lbl_8006D0E8(r); \
 psvec_sub_scale_add(&kn->pos,&center,scale,&diff,&kn->pos); \
 } \
 } \
 } \
}

#define delta (*dp)

static inline void fn_1_11A774_constrain(Node *a, Node *b, Link *l, f32 *len, Vec3 *dp) {
 f32 wb;
 f32 inv;
 f32 s;
 f32 wa;
 f32 fb;
 f32 r;
 f32 fa;
 f32 cx;
 f32 cy;
 f32 cz;
 f32 x;
 inv=lbl_8006D118(*len,len);
 r=lbl_8006D0B4(l->length);
 s=inv*(*len-r);
 *len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
}

#undef delta

#define LINKFIX { fn_1_11A774_constrain(a,b,l,&len,dp); }

static inline void fn_1_11A774_loop0(Work_11A774 *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
}

void fn_1_11A774(Work_11A774 *arg0) {
 u8 *fmodel;
 u32 i3;
 u32 k;
 Link *l;
 Node *kn;
 Node *fn;
 Node *n3;
 Node *a;
 u32 fj;
 u8 *model3;
 u32 ki;
 Node *vn;
 u32 fi;
 u32 li;
 u32 vi;
 u16 *lp;
 Node *b;
 Node *n2;
 u32 i2;
 Vec3 deltav;
 Vec3 random;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 fn_1_11A774_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<8;k++) {
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y;
 f32 wa;
 f32 x;
 f32 inv;
 f32 s;
 f32 cz;
 f32 cy;
 f32 r;
 f32 cx;
 f32 fa;
 f32 wb;
 f32 z;
 f32 fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-0.0001f>l->length) LINKFIX
 if(0.001f+len<l->length) LINKFIX
 }
 }
 SPHERE(532,0.591f,0.0f,0.0f,0.254016f,0.504f)
 SPHERE(532,0.092f,-0.014f,-0.018f,0.0036f,0.06f)
 SPHERE(532,0.092f,-0.014f,0.0f,0.0036f,0.06f)
 SPHERE(532,0.092f,-0.014f,0.018f,0.0036f,0.06f)
 SPHERE(532,0.062f,-0.014f,-0.018f,0.003249f,0.057f)
 SPHERE(532,0.062f,-0.014f,0.0f,0.003249f,0.057f)
 SPHERE(532,0.062f,-0.014f,0.018f,0.003249f,0.057f)
 SPHERE(0x1948,-0.024f,0.016f,0.0f,0.0037210002f,0.061f)
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.8; vn->vel.y*=0.8; vn->vel.z*=0.8;
 vn->vel.x+=(f64)(0.2*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.2*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.2*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef SPHERE
#undef LINKFIX
#undef delta
/* fzgx:end fn_1_11A774 */

/* fzgx:begin fn_1_11B4E4 */
/* VIEWS */
#define lbl_801A6410 (*(void * *)&lbl_801A6410)
void fn_1_11B4E4(Obj11B4E4 *obj) {
    u32 c0;
    Node11B4E4 *e4;
    Node11B4E4 *e0;
    Node11B4E4 *front;
    Node11B4E4 *back;
    Node11B4E4 *src;
    u32 k;
    u32 m;
    Node11B4E4 *e;
    Node11B4E4 *dst;
    Node11B4E4 *e3;
    Node11B4E4 *ring_2;
    Node11B4E4 sorted[8];
    u32 g;
    u32 ja;
    u32 jb;
    u32 i;
    u32 idx;
    f32 t;
    Node11B4E4 *ring;
    Node11B4E4 *pb;
    Node11B4E4 *pc;

    if (obj == NULL) {
        return;
    }
    fn_1_10846C((void *)obj);

    c0 = 0;
    e0 = obj->unk_24;
    for (; c0 < obj->unk_18; c0++, e0++) {
        if (e0->unk_0 & 1) {
            e0->unk_40 = -1.0f;
            e0->unk_0 = 0;
        } else {
            e0->unk_40 = 0.0f;
            e0->unk_0 = 1;
        }
    }

    e0 = obj->unk_24;
    for (c0 = 0; c0 < obj->unk_18; c0++, e0++) {
        pb = &obj->unk_24[c0] + 1;
        for (ja = c0 + 1; ja < obj->unk_18; ja++, pb++) {
            if (e0->unk_10 > pb->unk_10) {
                fn_1_128884((void *)e0, (void *)pb, sizeof(Node11B4E4));
            }
        }
    }

    ring = obj->unk_24;
    for (g = 0; g < obj->unk_18 / 8; g++, ring += 8) {
        for (jb = 0, ring_2 = ring; jb < 8; jb++, ring_2++) {
            i = jb + 1;
            pc = ring_2 + 1;
            for (; i < 8; i++, pc++) {
                if (ring_2->unk_14 < pc->unk_14) {
                    fn_1_128884((void *)ring_2, (void *)pc, sizeof(Node11B4E4));
                }
            }
        }
        front = sorted;
        *front = ring[0];
        front++;
        back = sorted;
        back += 7;
        e = ring + 1;
        for (k = 1; k < 8; k++, e++) {
            if (e->unk_18 > 0.0f) {
                *front = *e;
                front++;
            } else {
                *back = *e;
                back--;
            }
        }
        t = -(f32)g;
        dst = ring;
        src = sorted;
        for (m = 0; m < 8; m++, src++, dst++) {
            *dst = *src;
            if (g == obj->unk_18 / 8 - 1) {
                dst->unk_40 = 0.0f;
            } else {
                dst->unk_40 = t / (obj->unk_18 / 8 - 1);
            }
        }
    }

    obj->unk_1C = 0x60;
    obj->unk_28 = fn_1_4630((u32)lbl_801A6410, obj->unk_1C * sizeof(Link11B4E4), "accessory.c", 0x1E57);

    idx = 0;
    ring_2 = obj->unk_24;
    for (g = 0; g < obj->unk_18 / 8 - 1; g++, ring_2 += 8) {
        e3 = ring_2;
        for (i = 0; i < 7; i++, e3++) {
            obj->unk_28[idx].unk_0 = e3;
            obj->unk_28[idx].unk_4 = e3 + 1;
            obj->unk_28[idx].unk_8 = fn_1_1289BC((void *)e3, (void *)(e3 + 1));
            idx++;
        }
        obj->unk_28[idx].unk_0 = &ring_2[7];
        obj->unk_28[idx].unk_4 = ring_2;
        obj->unk_28[idx].unk_8 = fn_1_1289BC((void *)&ring_2[7], (void *)ring_2);
        idx++;
    }
    ring_2 = obj->unk_24;
    for (g = 0; g < obj->unk_18 / 8 - 1; g++, ring_2 += 8) {
        e4 = ring_2;
        for (i = 0; i < 8; i++, e4++) {
            obj->unk_28[idx].unk_0 = e4;
            obj->unk_28[idx].unk_4 = e4 + 8;
            obj->unk_28[idx].unk_8 = fn_1_1289BC((void *)e4, (void *)(e4 + 8));
            idx++;
        }
    }
}
#undef lbl_801A6410
/* fzgx:end fn_1_11B4E4 */

/* fzgx:begin fn_1_11B958 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_11B958(Work_11B958 *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 Link *l;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *vn;
 u32 i2;
 Node *n2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Vec3 deltav;
 Vec3 random;
 Vec3 target2;
 Vec3 diff;
 Vec3 target;
 u32 k2;
 Node *b;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x+(f64)(0.5*random.x);
 n2->pos.y+=n2->vel.y+(f64)(0.5*random.y);
 n2->pos.z+=n2->vel.z+(f64)(0.5*random.z);
 n2->pos.y-=0.0013611111376020642;
 n2->vel.x+=random.x;
 n2->vel.y+=random.y;
 n2->vel.z+=random.z;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k2=0;k2<2;k2++) {
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 f32 z,y,x;
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target2);
#define SS (1.0-__fabs(n6->weight))
 x=0.35f*(target2.x-n6->pos.x)*SS;
 y=0.35f*(target2.y-n6->pos.y)*SS;
 z=0.35f*(target2.z-n6->pos.z)*SS;
 n6->pos.x+=x;
 n6->pos.y+=y;
 n6->pos.z+=z;
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z;
 if(d>0.0004f) {
 d=lbl_8006D0B4(0.0004f/d);
 n5->pos.x=target.x+(f32)(dif.x*d);
 n5->pos.y=target.y+(f32)(dif.y*d);
 n5->pos.z=target.z+(f32)(dif.z*d);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=vn->pos.x-vn->prev.x;
 vn->vel.y=vn->pos.y-vn->prev.y;
 vn->vel.z=vn->pos.z-vn->prev.z;
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
#undef SS
/* fzgx:end fn_1_11B958 */

/* fzgx:begin fn_1_11BFCC */
/* VIEWS */
#define lbl_801A6410 (*(struct { u32 unk_0; } *)&lbl_801A6410)
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

/* rel/main_rel/accessory.h: inlined above */

void fn_1_11BFCC(Obj11BFCC *obj) {
    struct { s32 v; } i1;
    struct { Node11BFCC *v; } a1;
    struct { u32 v; } g;
    struct { Node11BFCC *v; } back;
    struct { Node11BFCC *v; } front;
    Row11BFCC tmp;
    Node11BFCC *b1;
    u32 i4;
    u32 i2;
    u32 j2;
    Node11BFCC *b2;
    Node11BFCC *a2;
    u32 i;
    u32 e;
    Node11BFCC *row;
    Node11BFCC *a;
    u32 part_i;
    Node11BFCC *scan;
    Node11BFCC *src;
    u32 copy_i;
    Node11BFCC *dest;
    Node11BFCC *a4;
    u32 j1;

    if (obj == NULL) {
        return;
    }
    fn_1_10846C((void *)obj);
    i = 0;
    a = obj->nodes;
    for (; i < obj->count; i++, a++) {
        if (a->flag & 1) {
            a->unk_40 = -1.0f;
            a->flag = 0;
        } else {
            a->unk_40 = 0.0f;
            a->flag = 1;
        }
    }

    i = 0;
    a = obj->nodes;
    for (; i < obj->count; i++, a++) {
        for (j1 = i + 1, b1 = &obj->nodes[i] + 1; j1 < obj->count; j1++, b1++) {
            if (a->unk_10 > b1->unk_10) {
                fn_1_128884((void *)a, (void *)b1, sizeof(Node11BFCC));
            }
        }
    }

    row = obj->nodes;
    for (g.v = 0; g.v < (obj->count >> 3); g.v++, row += 8) {
        for (i2 = 0, a2 = row; i2 < 8; i2++, a2++) {
            for (j2 = i2 + 1, b2 = a2 + 1; j2 < 8; j2++, b2++) {
                if (a2->unk_14 < b2->unk_14) {
                    fn_1_128884((void *)a2, (void *)b2, sizeof(Node11BFCC));
                }
            }
        }
        front.v = tmp.n;
        back.v = front.v;
        *back.v = row[0];
        scan = row + 1;
        front.v = (back.v += 7) - 6;
        for (part_i = 1; part_i < 8; part_i++, scan++) {
            if (scan->unk_18 > 0.0f) {
                *front.v = *scan;
                front.v++;
            } else {
                *back.v = *scan;
                back.v--;
            }
        }
        for (copy_i = 0, dest = row, src = tmp.n; copy_i < 8; copy_i++, src++, dest++) {
            *dest = *src;
            if (g.v == (obj->count >> 3) - 1) {
                dest->unk_40 = 0.0f;
            } else {
                dest->unk_40 = -(f32)g.v / ((obj->count >> 3) - 1);
            }
        }
    }

    obj->edgeCount = 80;
    obj->edges = fn_1_4630(lbl_801A6410.unk_0, obj->edgeCount * sizeof(Edge11BFCC), "accessory.c", 0x1f83);

    e = 0;
    row = obj->nodes;
    for (g.v = 0; g.v < (obj->count >> 3) - 1; g.v++, row += 8) {
        for (i4 = 0, a4 = row; i4 < 7; i4++, a4++) {
            obj->edges[e].a = a4;
            obj->edges[e].b = a4 + 1;
            obj->edges[e].len = fn_1_1289BC((Point1024C4 *)a4, (Point1024C4 *)(a4 + 1));
            e++;
        }
        obj->edges[e].a = &row[7];
        obj->edges[e].b = &row[0];
        obj->edges[e].len = fn_1_1289BC((Point1024C4 *)&row[7], (Point1024C4 *)&row[0]);
        e++;
    }

    row = obj->nodes;
    for (j1 = 0; j1 < (obj->count >> 3) - 1; j1++, row += 8) {
        for (b2 = row, j2 = 0; j2 < 8; j2++, b2++) {
            obj->edges[e].a = b2;
            obj->edges[e].b = b2 + 8;
            obj->edges[e].len = fn_1_1289BC((Point1024C4 *)b2, (Point1024C4 *)(b2 + 8));
            e++;
        }
    }
}
#undef lbl_801A6410
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_11BFCC */

/* fzgx:begin fn_1_11C440 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_11C440(Work_11C440 *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 Link *l;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *vn;
 u32 i2;
 Node *n2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Vec3 deltav;
 Vec3 random;
 Vec3 target2;
 Vec3 diff;
 Vec3 target;
 u32 k2;
 Node *b;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x+(f64)(0.5*random.x);
 n2->pos.y+=n2->vel.y+(f64)(0.5*random.y);
 n2->pos.z+=n2->vel.z+(f64)(0.5*random.z);
 n2->pos.y-=0.0013611111376020642;
 n2->vel.x+=random.x;
 n2->vel.y+=random.y;
 n2->vel.z+=random.z;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k2=0;k2<2;k2++) {
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 f32 z,y,x;
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target2);
#define SS (1.0-__fabs(n6->weight))
 x=0.35f*(target2.x-n6->pos.x)*SS;
 y=0.35f*(target2.y-n6->pos.y)*SS;
 z=0.35f*(target2.z-n6->pos.z)*SS;
 n6->pos.x+=x;
 n6->pos.y+=y;
 n6->pos.z+=z;
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z;
 if(d>0.0004f) {
 d=lbl_8006D0B4(0.0004f/d);
 n5->pos.x=target.x+(f32)(dif.x*d);
 n5->pos.y=target.y+(f32)(dif.y*d);
 n5->pos.z=target.z+(f32)(dif.z*d);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=vn->pos.x-vn->prev.x;
 vn->vel.y=vn->pos.y-vn->prev.y;
 vn->vel.z=vn->pos.z-vn->prev.z;
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
#undef SS
/* fzgx:end fn_1_11C440 */

/* fzgx:begin fn_1_11CAB4 */
static inline void nodeset_vec_sub(Vec3 *a, Vec3 *b, Vec3 *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

static inline f32 nodeset_vec_mag(Vec3 *v) {
    f32 *p = (f32 *)v;
    f32 x = p[0];
    f32 y = p[1];
    f32 z = p[2];
    f32 sum;
    sum = x * x;
    sum += y * y;
    sum += z * z;
    return lbl_8006D0B4(sum);
}

void fn_1_11CAB4(NodeSet *set) {
    u32 i;
    Node_11CAB4 *n;
    Node_11CAB4 * n_2;

    if (set == NULL) {
        return;
    }
    fn_1_10846C((void *)set);

    n = set->nodes;
    for (i = 0; i < set->count; i++, n++) {
        if (n->flags & 1) {
            n->weight = -1.0f;
            n->flags = 0;
        } else {
            n->weight = 0.0f;
            n->flags = 1;
        }
    }

    {
        Vec3 center = {0};
        Vec3 d;
        u32 active;
        f32 maxDist;

        active = 0;
        n_2 = set->nodes;
        for (i = 0; i < set->count; i++, n_2++) {
            if (n_2->flags & 1) {
                active++;
                center.x += n_2->pos.x;
                center.y += n_2->pos.y;
                center.z += n_2->pos.z;
            }
        }
        center.x /= active;
        center.y /= active;
        center.z /= active;

        maxDist = 0.0f;
        n_2 = set->nodes;
        for (i = 0; i < set->count; i++, n_2++) {
            if (!(n_2->flags & 1)) {
                nodeset_vec_sub(&n_2->pos, &center, &d);
                if (nodeset_vec_mag(&d) > maxDist) {
                    maxDist = nodeset_vec_mag(&d);
                }
            }
        }

        n_2 = set->nodes;
        for (i = 0; i < set->count; i++, n_2++) {
            if (!(n_2->flags & 1)) {
                nodeset_vec_sub(&n_2->pos, &center, &d);
                n_2->weight = -nodeset_vec_mag(&d) / maxDist;
            }
        }
    }
}
/* fzgx:end fn_1_11CAB4 */

/* fzgx:begin fn_1_11CD3C */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_11CD3C(Work_11CD3C *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 Node *n3;
 u32 fj;
 u32 i3;
 Node *fn;
 u16 *lp;
 u8 *model5;
 u32 i5;
 Node *n5;
 u32 vi;
 Node *vn;
 Node *n2;
 u32 i2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Vec3 diff;
 Vec3 target;
 Vec3 *qp = &diff;
#define dif (*qp)
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target);
#define KK (1.0499999523162842-(f64)(0.7*__fabs(n6->weight)))
 dif.x=(target.x-n6->pos.x)*KK;
 dif.y=0.76*(target.y-n6->pos.y);
 dif.z=(target.z-n6->pos.z)*KK;
 n6->pos.x+=dif.x;
 n6->pos.y+=dif.y;
 n6->pos.z+=dif.z;
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z;
 if(d>0.0004f) {
 d=lbl_8006D0B4(0.0004f/d);
 n5->pos.x=target.x+(f32)(dif.x*d);
 n5->pos.y=target.y+(f32)(dif.y*d);
 n5->pos.z=target.z+(f32)(dif.z*d);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=0.8f*(vn->pos.x-vn->prev.x);
 vn->vel.y=0.8f*(vn->pos.y-vn->prev.y);
 vn->vel.z=0.8f*(vn->pos.z-vn->prev.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef KK
/* fzgx:end fn_1_11CD3C */

/* fzgx:begin fn_1_11D1FC */
/* VIEWS */
#define lbl_801A6410 (*(void * *)&lbl_801A6410)
void fn_1_11D1FC(Obj_11D1FC *obj) {
    u32 i;
    u32 j;
    Node_11D1FC *b;
    Node_11D1FC *a;
    u32 k;
    Node_11D1FC *ba;
    u32 bj;
    Node_11D1FC *blk;
    u32 bi;
    Node_11D1FC *bb;
    Node_11D1FC *nodes;
    u32 n;
    Node_11D1FC *dst;
    u32 qi;
    Node_11D1FC *g;
    Node_11D1FC *p;
    Node_11D1FC *quad;
    Vec3 sum;
    u32 cnt;

    if (obj == NULL) {
        return;
    }
    fn_1_10846C((void *)obj);

    g = obj->groups;
    for (i = 0; i < obj->groupCount; i++, g++) {
        if (g->flags & 1) {
            g->weight = -1.0f;
            g->flags = 0;
            g->type = 1;
        } else if (g->pos.x > 0.12f) {
            g->weight = 0.0f;
            g->flags = 1;
            g->type = 0;
        } else if (g->pos.x < 0.06f && g->pos.z > 0.01f) {
            g->weight = 0.0f;
            g->flags = 1;
            g->type = 4;
        } else if (g->pos.x < 0.06f && g->pos.z < 0.01f) {
            g->weight = 0.0f;
            g->flags = 1;
            g->type = 5;
        } else if (g->pos.z > 0.0f) {
            g->weight = 0.0f;
            g->flags = 1;
            g->type = 2;
        } else {
            g->weight = 0.0f;
            g->flags = 1;
            g->type = 3;
        }
    }

    for (i = 0, a = obj->groups; i < obj->groupCount; i++, a++) {
        for (j = i + 1, b = &obj->groups[i] + 1; j < obj->groupCount; j++, b++) {
            if (a->type > b->type) {
                fn_1_128884((void *)a, (void *)b, sizeof(Node_11D1FC));
            }
        }
    }

    for (i = 0, a = obj->groups; i < obj->groupCount; i++, a++) {
        for (j = i + 1, b = a + 1; j < obj->groupCount; j++, b++) {
            if (a->type == b->type && a->pos.x < b->pos.x) {
                fn_1_128884((void *)a, (void *)b, sizeof(Node_11D1FC));
            }
        }
    }

    for (i = 0, a = obj->groups; i < obj->groupCount; i++, a++) {
        for (j = i + 1, b = &obj->groups[i] + 1; j < obj->groupCount; j++, b++) {
            if (a->type == 0 && b->type == 0 && a->pos.z < b->pos.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(Node_11D1FC));
            }
        }
    }

    for (bi = 0, blk = obj->groups; bi < obj->groupCount; bi += 8, blk += 8) {
        for (bj = 0, ba = blk; bj < 8; bj++, ba++) {
            for (k = bj + 1, bb = ba + 1; k < 8; k++, bb++) {
                if (ba->type == 1 && bb->type == 1 && ba->pos.z < bb->pos.z) {
                    fn_1_128884((void *)ba, (void *)bb, sizeof(Node_11D1FC));
                }
            }
        }
    }

    obj->nodeCount = 14;
    obj->nodes = fn_1_4630((u32)lbl_801A6410, obj->nodeCount * sizeof(Node_11D1FC), "accessory.c", 8538);
    nodes = obj->nodes;
    nodes[0].flags = 1;
    nodes[1].flags = 1;
    n = 0;
    dst = nodes;
    for (qi = 0, quad = obj->groups; qi < obj->groupCount; qi += 4, quad += 4) {
        if (quad->type == 0 || quad->type == 1) {
            {
                Vec3 zero = {0.0f, 0.0f, 0.0f};
                sum = zero;
            }
            n++;
            for (k = 0, p = quad; k < 4; k++, p++) {
                sum.x += p->pos.x;
                sum.y += p->pos.y;
                sum.z += p->pos.z;
            }
            sum.x *= 0.25f;
            sum.y *= 0.25f;
            sum.z *= 0.25f;
            dst->pos = sum;
            dst->p28 = dst->pos;
            dst++;
        }
    }

    {
        Vec3 zero = {0.0f, 0.0f, 0.0f};
        sum = zero;
    }
    cnt = 0;
    for (i = 0, g = obj->groups; i < obj->groupCount; i++, g++) {
        if (g->type == 2) {
            cnt++;
            sum.x += g->pos.x;
            sum.y += g->pos.y;
            sum.z += g->pos.z;
        }
    }
    sum.x /= cnt;
    sum.y /= cnt;
    sum.z /= cnt;
    nodes[n].p28 = nodes[n].pos = sum;
    n++;
    {
        Vec3 zero = {0.0f, 0.0f, 0.0f};
        sum = zero;
    }
    cnt = 0;
    for (i = 0, g = obj->groups; i < obj->groupCount; i++, g++) {
        if (g->type == 3) {
            cnt++;
            sum.x += g->pos.x;
            sum.y += g->pos.y;
            sum.z += g->pos.z;
        }
    }
    sum.x /= cnt;
    sum.y /= cnt;
    sum.z /= cnt;
    nodes[n].p28 = nodes[n].pos = sum;
    n++;
    {
        Vec3 zero = {0.0f, 0.0f, 0.0f};
        sum = zero;
    }
    cnt = 0;
    for (i = 0, g = obj->groups; i < obj->groupCount; i++, g++) {
        if (g->type == 4) {
            cnt++;
            sum.x += g->pos.x;
            sum.y += g->pos.y;
            sum.z += g->pos.z;
        }
    }
    sum.x /= cnt;
    sum.y /= cnt;
    sum.z /= cnt;
    nodes[n].p28 = nodes[n].pos = sum;
    n++;
    {
        Vec3 zero = {0.0f, 0.0f, 0.0f};
        sum = zero;
    }
    cnt = 0;
    for (i = 0, g = obj->groups; i < obj->groupCount; i++, g++) {
        if (g->type == 5) {
            cnt++;
            sum.x += g->pos.x;
            sum.y += g->pos.y;
            sum.z += g->pos.z;
        }
    }
    sum.x /= cnt;
    sum.y /= cnt;
    sum.z /= cnt;
    nodes[n].p28 = nodes[n].pos = sum;
    n++;

    nodes[0].weight = nodes[1].weight = 0.0f;
    for (k = 2; k < 14; k++) {
        nodes[k].weight = -1.0f;
    }
    if (n != 14) {
        OSPanic("accessory.c", 8637, "stop..");
    }

    obj->linkCount = 16;
    obj->links = fn_1_4630((u32)lbl_801A6410, obj->linkCount * sizeof(Link_11D1FC), "accessory.c", 8641);
    nodes = obj->nodes;
    obj->links[0].a = &nodes[0];
    obj->links[0].b = &nodes[2];
    obj->links[0].length = fn_1_1289BC((void *)&nodes[0], (void *)&nodes[2]);
    obj->links[1].a = &nodes[1];
    obj->links[1].b = &nodes[3];
    obj->links[1].length = fn_1_1289BC((void *)&nodes[1], (void *)&nodes[3]);
    obj->links[2].a = &nodes[2];
    obj->links[2].b = &nodes[4];
    obj->links[2].length = fn_1_1289BC((void *)&nodes[2], (void *)&nodes[4]);
    obj->links[3].a = &nodes[3];
    obj->links[3].b = &nodes[5];
    obj->links[3].length = fn_1_1289BC((void *)&nodes[3], (void *)&nodes[5]);
    obj->links[4].a = &nodes[4];
    obj->links[4].b = &nodes[6];
    obj->links[4].length = fn_1_1289BC((void *)&nodes[4], (void *)&nodes[6]);
    obj->links[5].a = &nodes[5];
    obj->links[5].b = &nodes[7];
    obj->links[5].length = fn_1_1289BC((void *)&nodes[5], (void *)&nodes[7]);
    obj->links[6].a = &nodes[6];
    obj->links[6].b = &nodes[8];
    obj->links[6].length = fn_1_1289BC((void *)&nodes[6], (void *)&nodes[8]);
    obj->links[7].a = &nodes[7];
    obj->links[7].b = &nodes[9];
    obj->links[7].length = fn_1_1289BC((void *)&nodes[7], (void *)&nodes[9]);
    obj->links[8].a = &nodes[8];
    obj->links[8].b = &nodes[10];
    obj->links[8].length = fn_1_1289BC((void *)&nodes[8], (void *)&nodes[10]);
    obj->links[9].a = &nodes[9];
    obj->links[9].b = &nodes[11];
    obj->links[9].length = fn_1_1289BC((void *)&nodes[9], (void *)&nodes[11]);
    obj->links[10].a = &nodes[10];
    obj->links[10].b = &nodes[11];
    obj->links[10].length = fn_1_1289BC((void *)&nodes[10], (void *)&nodes[11]);
    obj->links[11].a = &nodes[10];
    obj->links[11].b = &nodes[12];
    obj->links[11].length = fn_1_1289BC((void *)&nodes[10], (void *)&nodes[12]);
    obj->links[12].a = &nodes[11];
    obj->links[12].b = &nodes[13];
    obj->links[12].length = fn_1_1289BC((void *)&nodes[11], (void *)&nodes[13]);
    obj->links[13].a = &nodes[12];
    obj->links[13].b = &nodes[13];
    obj->links[13].length = fn_1_1289BC((void *)&nodes[12], (void *)&nodes[13]);
    obj->links[14].a = &nodes[10];
    obj->links[14].b = &nodes[13];
    obj->links[14].length = fn_1_1289BC((void *)&nodes[10], (void *)&nodes[13]);
    obj->links[15].a = &nodes[11];
    obj->links[15].b = &nodes[12];
    obj->links[15].length = fn_1_1289BC((void *)&nodes[11], (void *)&nodes[12]);
}
#undef lbl_801A6410
/* fzgx:end fn_1_11D1FC */

/* fzgx:begin fn_1_11DE2C */
/* VIEWS */

#define INDEX(i) (lbl_1_data_3FFBC[i])

static inline f32 link_measure(Node_11DE2C *a, Node_11DE2C *b, Vec3 *dp) {
    f32 x;
    f32 y;
    f32 z;
    x = a->pos.x - b->pos.x;
    y = a->pos.y - b->pos.y;
    z = a->pos.z - b->pos.z;
    (*dp).x = x; (*dp).y = y; (*dp).z = z;
    { f32 d; d = x * x; d += y * y; d += z * z; return d; }
}

#define delta (*dp)

static inline void link_constrain(Node_11DE2C *a, Node_11DE2C *b, Link_11DE2C *l, f32 *len, Vec3 *dp) {
    f32 wb;
    f32 inv;
    f32 s;
    f32 wa;
    f32 fb;
    f32 r;
    f32 fa;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 x;
    inv = lbl_8006D118(*len, len);
    r = lbl_8006D0B4(l->length);
    s = inv * (*len - r);
    *len = s;
    cx = delta.x * s; cy = delta.y * s; cz = delta.z * s;
    wa = a->weight; wb = b->weight;
    x = a->pos.x;
    delta.x = cx; delta.y = cy; delta.z = cz;
    r = 1.0f / (wa + wb);
    fa = wa * r; fb = wb * r;
    a->pos.x = x - (f32)(cx * fa);
    a->pos.y -= (f32)(cy * fa);
    a->pos.z -= (f32)(cz * fa);
    b->pos.x += (f32)(cx * fb);
    b->pos.y += (f32)(cy * fb);
    b->pos.z += (f32)(cz * fb);
}

#undef delta

#define LINKFIX { link_constrain(a, b, l, &len, dp); }

#define SPHERE(CX, CY, CZ, RADIUS, STRENGTH) { \
    Vec3 diffv; \
    Vec3 center; \
    Vec3 *qp = &diffv; \
    u8 *mb = arg0->owner->model->base; \
    center.x = CX; center.y = CY; center.z = CZ; \
    lbl_8006DBAC(mb + 532); \
    lbl_8006E1B0((void *)&center, (void *)&center); \
    for (ki = 0, kn = arg0->nodes2; ki < arg0->count2; ki++, kn++) { \
        if (!(kn->flags & 1)) { \
            f32 y, x, z, r, s; \
            x = kn->pos.x - center.x; \
            y = kn->pos.y - center.y; \
            z = kn->pos.z - center.z; \
            qp->x = x; qp->y = y; qp->z = z; \
            r = (f32)(x * x) + y * y + z * z; \
            if (r < RADIUS) { \
                s = STRENGTH / lbl_8006D0B4(r); \
                kn->pos.x = center.x + (f32)(qp->x * s); \
                kn->pos.y = center.y + (f32)(qp->y * s); \
                kn->pos.z = center.z + (f32)(qp->z * s); \
            } \
        } \
    } \
}

#define OFFSET(T, IDX) { \
    Node_11DE2C *src = &arg0->nodes2[IDX]; \
    delta.x = src->pos.x - src->local.x; \
    delta.y = src->pos.y - src->local.y; \
    delta.z = src->pos.z - src->local.z; \
    for (oi = 0, on = arg0->nodes; oi < arg0->count; oi++, on++) { \
        if (on->kind == T) { \
            on->pos.x = on->local.x + delta.x; \
            on->pos.y = on->local.y + delta.y; \
            on->pos.z = on->local.z + delta.z; \
        } \
    } \
}

void fn_1_11DE2C(Work_11DE2C *arg0) {
    u8 *fmodel;
    Node_11DE2C *fn;
    Node_11DE2C *b;
    Node_11DE2C *na;
    u32 ki;
    Node_11DE2C *kn;
    s32 fj;
    u32 vi;
    u32 i4;
    u32 fi;
    u32 k;
    u32 i3;
    Node_11DE2C *n3;
    u16 *lp;
    u32 i2;
    u8 *model4;
    Node_11DE2C *n2;
    u32 oi;
    u8 *model3;
    Node_11DE2C *jn;
    u32 i1b;
    Node_11DE2C *on;
    u32 li;
    Node_11DE2C *n1b;
    Node_11DE2C *vn;
    u32 j;
    Node_11DE2C *a;
    Node_11DE2C *n1;
    u32 i1;
    Node_11DE2C *nb;
    Link_11DE2C *l;
    u8 *model1;
    Vec3 deltav;
    Vec3 *dp = &deltav;
#define delta (*dp)
    Vec3 tmp;
    f32 len;

    if (arg0 && arg0->obj) {
        ((s32)fn_80077B14((void *)arg0->obj));
        if (arg0->flags & 2) {
            arg0->flags &= ~2;
            model1 = arg0->owner->model->base + INDEX(arg0->index) * 396;
            for (i1 = 0, n1 = arg0->nodes; i1 < arg0->count; i1++, n1++) {
                lbl_8006DBAC(model1 + 136);
                lbl_8006E1B0((void *)&n1->local, (void *)&n1->pos);
            }
            for (i1b = 0, n1b = arg0->nodes2; i1b < arg0->count2; i1b++, n1b++) {
                lbl_8006DBAC(model1 + 136);
                lbl_8006E1B0((void *)&n1b->local, (void *)&n1b->pos);
            }
        }
        for (i2 = 0, n2 = arg0->nodes2; i2 < arg0->count2; i2++, n2++) {
            if (!(n2->flags & 1)) {
                n2->prev = n2->pos;
                n2->pos.x += n2->vel.x;
                n2->pos.y += n2->vel.y;
                n2->pos.z += n2->vel.z;
                n2->pos.y -= 0.0013611111376020642;
                n2->vel.y -= 0.0027222224f;
            }
        }
        model3 = arg0->owner->model->base + INDEX(arg0->index) * 396;
        for (i3 = 0, n3 = arg0->nodes2; i3 < arg0->count2; i3++, n3++) {
            if (n3->flags & 1) {
                lbl_8006DBAC(model3 + 136);
                lbl_8006E1B0((void *)&n3->local, (void *)&n3->pos);
            }
        }
        for (k = 0; k < 4; k++) {
            for (li = 0, l = arg0->links; li < arg0->linkCount; li++, l++) {
                a = l->a; b = l->b;
                if (a && b) {
                    f32 y, z, x;
                    x = a->pos.x - b->pos.x;
                    y = a->pos.y - b->pos.y;
                    z = a->pos.z - b->pos.z;
                    delta.x = x; delta.y = y; delta.z = z;
                    len = (f32)(x * x) + y * y + z * z;
                    if (len - 0.0001f > l->length) LINKFIX
                    if (len - 0.001f < l->length && li >= 10) {
                        if (a->pos.y < 0.0f) a->pos.y = 0.00001f;
                        if (b->pos.y < 0.0f) b->pos.y = 0.00001f;
                        len = link_measure(a, b, dp);
                        LINKFIX
                    }
                }
            }
        }
        SPHERE(0.13f, 0.004f, 0.0f, 0.006084f, 0.078f)
        SPHERE(0.13f, -0.004f, 0.021f, 0.004356f, 0.066f)
        SPHERE(0.13f, -0.004f, -0.021f, 0.004356f, 0.066f)
        SPHERE(0.061f, 0.001f, 0.0f, 0.0049f, 0.07f)
        SPHERE(0.114f, 0.0f, 0.253f, 0.047523998f, 0.218f)
        SPHERE(0.114f, 0.0f, -0.253f, 0.047523998f, 0.218f)
        model4 = arg0->owner->model->base + INDEX(arg0->index) * 396;
        for (i4 = 0, na = arg0->nodes, nb = arg0->nodes2; i4 < 10; i4++, na += 4, nb++) {
            if (na->kind == 0 || na->kind == 1) {
                lbl_8006DBAC(model4 + 136);
                lbl_8006E1B0((void *)&nb->local, (void *)&tmp);
                delta.x = nb->pos.x - tmp.x;
                delta.y = nb->pos.y - tmp.y;
                delta.z = nb->pos.z - tmp.z;
                for (j = 0, jn = na; j < 4; j++, jn++) {
                    lbl_8006DBAC(model4 + 136);
                    lbl_8006E1B0((void *)&jn->local, (void *)&tmp);
                    jn->pos.x = tmp.x + delta.x;
                    jn->pos.y = tmp.y + delta.y;
                    jn->pos.z = tmp.z + delta.z;
                }
            }
        }
        OFFSET(2, 10)
        OFFSET(3, 11)
        OFFSET(4, 12)
        OFFSET(5, 13)
        for (vi = 0, vn = arg0->nodes2; vi < arg0->count2; vi++, vn++) {
            vn->vel.x = vn->pos.x - vn->prev.x;
            vn->vel.y = vn->pos.y - vn->prev.y;
            vn->vel.z = vn->pos.z - vn->prev.z;
            vn->vel.x *= 0.9f;
            vn->vel.z *= 0.9f;
            if (vn->vel.y > 0.0f) vn->vel.y *= 0.8f;
        }
        fmodel = (u8 *)((s32)fn_80077B14((void *)arg0->obj));
        lbl_8006DBAC(arg0->owner->model->base + INDEX(arg0->index) * 396 + 136);
        for (fi = 0, fn = arg0->nodes; fi < arg0->count; fi++, fn++) {
            for (fj = 0, lp = (u16 *)fn; fj < fn->count; lp++, fj++) {
                fn_8006E250((void *)&fn->pos, (void *)((Vec3 *)(fmodel + (lp[2] << 6))));
            }
        }
    }
}
#undef INDEX
#undef LINKFIX
#undef SPHERE
#undef OFFSET
#undef delta
/* fzgx:end fn_1_11DE2C */

/* fzgx:begin fn_1_11ED0C */
/* begin game/main_rel/accessory_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_ACCESSORY_TYPES_H

// Types (and the externs that name them) of accessory.c, hoisted out of its prologue so that

// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* begin game/main_rel/shared_types.h (deltawave784/fzgx, CC0) */

#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so

// the TU headers can be included together. Hand-owned (librarian).

/* end game/main_rel/shared_types.h */

/* game/main_rel/shared_types.h: inlined above */

/* game/main_rel/shared_types.h: inlined above */

/* end game/main_rel/accessory_types.h */

void fn_1_11ED0C(fn_1_10D2F0_Obj *obj) {
    u32 i;
    u32 j;
    u32 m;
    fn_1_10D2F0_Entry *b;
    fn_1_10D2F0_Entry *a;
    fn_1_10D2F0_Entry *e;
    u32 n;
    u32 rows;
    u32 k;
    u32 c;
    fn_1_10D2F0_Entry *p;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_0 = 0;
                p->unk_40 = -1.0f;
            } else {
                p->unk_0 = 1;
                p->unk_40 = 0.0f;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == 0 && b->unk_0 != 0) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            b = &obj->unk_24[i] + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (a->unk_0 == b->unk_0 && a->unk_10.x < b->unk_10.x) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        for (i = 0, a = obj->unk_24; i < 11; i++, a++) {
            for (j = i + 1, b = a + 1; j < 11; j++, b++) {
                if (a->unk_10.z > b->unk_10.z) {
                    fn_1_128884((void *)a, (void *)b, sizeof(fn_1_10D2F0_Entry));
                }
            }
        }

        a = obj->unk_24;
        n = obj->unk_18;
        for (i = 0; i < n; i++, a++) {
            if (a->unk_0 != 0 && a[1].unk_0 == 0) {
                break;
            }
        }
        a++;
        rows = (n - (a - obj->unk_24)) / 11;

        for (k = 0; k < rows; k++, a += 11) {
            for (i = 0; i < 11; i++) {
                a[i].unk_40 = -(f32)(k + 1) / (rows + 1);
            }
            for (i = 0, b = a; i < 11; i++, b++) {
                for (m = i + 1, e = b + 1; m < 11; m++, e++) {
                    if (b->unk_10.z > e->unk_10.z) {
                        fn_1_128884((void *)b, (void *)e, sizeof(fn_1_10D2F0_Entry));
                    }
                }
            }
        }

        obj->unk_1C = (obj->unk_18 / 11) * 10 + (obj->unk_18 / 11 - 1) * 11 + 20;
        obj->unk_28 = fn_1_4630(lbl_801A6410, obj->unk_1C * sizeof(fn_1_10D2F0_Link), "accessory.c", 9033);

        c = 0;
        a = obj->unk_24;
        for (i = 0; i < 10; i++, a++) {
            obj->unk_28[c].a = a;
            obj->unk_28[c].b = a + 12;
            obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 12));
            c++;
        }
        a = obj->unk_24;
        for (i = 0; i < 10; i++, a++) {
            obj->unk_28[c].a = a + 1;
            obj->unk_28[c].b = a + 11;
            obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)(a + 1), (const Point1024C4 *)(a + 11));
            c++;
        }
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 1; i++, a++) {
            if ((i + 1) % 11 != 0) {
                obj->unk_28[c].a = a;
                obj->unk_28[c].b = a + 1;
                obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 1));
                c++;
            }
        }

        a = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 11; i++, a++) {
            obj->unk_28[c].a = a;
            obj->unk_28[c].b = a + 11;
            obj->unk_28[c].len = fn_1_1289BC((const Point1024C4 *)a, (const Point1024C4 *)(a + 11));
            c++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_11ED0C */

/* fzgx:begin fn_1_11F250 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

#define SPHERE(BASE, CX, CY, CZ, RADIUS, STRENGTH) { \
 Vec3 diff; \
 Vec3 center; \
 f32 scale; \
 f32 cx,cy,cz; \
 cz=CZ; cy=CY; cx=CX; \
 vec_set_xyz(&center,cx,cy,cz); \
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+BASE))); \
 lbl_8006E1B0((void *)&center,(void *)&center); \
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) { \
 if(!(kn->flags&1)) { \
 f32 x,z,y,r; \
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z; \
 x-=center.x; y-=center.y; z-=center.z; \
 r=(f32)(x*x)+y*y+z*z; \
 if(r<RADIUS) { \
 scale=STRENGTH*lbl_8006D0E8(r); \
 psvec_sub_scale_add(&kn->pos,&center,scale,&diff,&kn->pos); \
 } \
 } \
 } \
}

static inline f32 fn_1_11F250_measure(Node *a, Node *b, Vec3 *dp) {
 f32 x;
 f32 y;
 f32 z;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 (*dp).x=x; (*dp).y=y; (*dp).z=z;
 { f32 d; d=x*x; d+=y*y; d+=z*z; return d; }
}

#define delta (*dp)

static inline void fn_1_11F250_constrain(Node *a, Node *b, Link *l, f32 *len, Vec3 *dp) {
 f32 wb;
 f32 inv;
 f32 s;
 f32 wa;
 f32 fb;
 f32 r;
 f32 fa;
 f32 cx;
 f32 cy;
 f32 cz;
 f32 x;
 inv=lbl_8006D118(*len,len);
 r=lbl_8006D0B4(l->length);
 s=inv*(*len-r);
 *len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
}

#define LINKFIX { fn_1_11F250_constrain(a,b,l,&len,dp); }

#undef delta

#pragma opt_common_subs off

static inline void fn_1_11F250_loop0(Work_11F250 *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
}

void fn_1_11F250(Work_11F250 *arg0) {
 u8 *fmodel;
 u32 i3;
 u32 k;
 Link *l;
 Node *kn;
 Node *fn;
 Node *n3;
 Node *a;
 u32 fj;
 u8 *model3;
 u32 ki;
 Node *vn;
 u32 fi;
 u32 li;
 u32 vi;
 u16 *lp;
 Node *n2;
 u32 i2;
 f32 c68;
 f32 c2d4;
 f32 c238;
 f32 c1c8;
 f32 c4b0;
 f32 c4ac;
 u32 i6;
 Node *n6;
 u8 *model6;
 Node *b;
 Vec3 deltav;
 Vec3 random;
 Vec3 push;
 Vec3 target;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 fn_1_11F250_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 c68=0.0f; c2d4=0.066f; c238=0.1f; c1c8=0.2f; c4ac=-0.642f; c4b0=0.549f;
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y;
 f32 wa;
 f32 x;
 f32 inv;
 f32 s;
 f32 cz;
 f32 cy;
 f32 r;
 f32 cx;
 f32 fa;
 f32 wb;
 f32 z;
 f32 fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-0.0001f>l->length) LINKFIX
 if(0.001f+len<(l->length) && li<20) LINKFIX
 if((y=a->pos.y)<0.0f || b->pos.y<0.0f) {
 if(y<0.0f) a->pos.y=0.00001f;
 if(b->pos.y<0.0f) b->pos.y=0.00001f;
 len=fn_1_11F250_measure(a,b,dp);
 LINKFIX
 }
 }
 }
 SPHERE(532,c2d4,c68,c68,0.122499995f,0.35f)
 SPHERE(0xb5c,c68,c68,c68,0.010201001f,0.101f)
 SPHERE(0xb5c,c238,c68,c68,0.010000001f,0.1f)
 SPHERE(0xb5c,c1c8,c68,c68,0.010000001f,0.1f)
 SPHERE(0x1318,c68,c68,c68,0.010201001f,0.101f)
 SPHERE(0x1318,c238,c68,c68,0.010000001f,0.1f)
 SPHERE(0x1318,c1c8,c68,c68,0.010000001f,0.1f)
 SPHERE(532,c4b0,c4ac,c68,0.50552106f,0.711f)
 }
 if(lbl_801A66A0%90<20) {
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target);
 push.x=n6->pos.x-target.x;
 push.y=n6->pos.y-target.y;
 push.z=n6->pos.z-target.z;
 lbl_8006D668(&push);
 n6->vel.x-=(f32)(0.001f*push.x);
 n6->vel.y-=(f32)(0.001f*push.y);
 n6->vel.z-=(f32)(0.001f*push.z);
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.8; vn->vel.y*=0.8; vn->vel.z*=0.8;
 vn->vel.x+=(f64)(0.2*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.2*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.2*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef SPHERE
#undef LINKFIX
#undef delta
/* fzgx:end fn_1_11F250 */

/* fzgx:begin fn_1_1201E4 */
void fn_1_1201E4(Rope_10DDE4 *rope) {
    u32 i;
    u32 m;
    RopeNode_10DDE4 *b;
    RopeNode_10DDE4 *a;
    RopeNode_10DDE4 *p;
    RopeNode_10DDE4 *n;
    s32 last;
    u32 c;
    u32 j;
    RopeNode_10DDE4 *q;
    u32 k;
    u32 rows;
    s32 cols;

    if (rope == NULL) {
        return;
    }
    cols = (rope->unk_C->unk_8C == 2) ? 9 : 13;
    fn_1_10846C((void *)rope);

    for (i = 0, n = rope->unk_24; i < rope->unk_18; i++, n++) {
        if (n->unk_0 & 1) {
            n->unk_0 = 0;
            n->unk_40 = -1.0f;
        } else {
            n->unk_0 = 1;
            n->unk_40 = 0.0f;
        }
    }

    for (i = 0, a = rope->unk_24; i < rope->unk_18; i++, a++) {
        for (j = i + 1, b = &rope->unk_24[i] + 1; j < rope->unk_18; j++, b++) {
            if (a->unk_0 == 0 && b->unk_0 != 0) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = 0, a = rope->unk_24; i < rope->unk_18; i++, a++) {
        for (j = i + 1, b = &rope->unk_24[i] + 1; j < rope->unk_18; j++, b++) {
            if (a->unk_0 == b->unk_0 && a->unk_10.x < b->unk_10.x) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = 0, a = rope->unk_24; i < cols; i++, a++) {
        for (j = i + 1, b = a + 1; j < cols; j++, b++) {
            if (a->unk_10.z > b->unk_10.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = cols, a = &rope->unk_24[cols]; i < cols * 2; i++, a++) {
        for (j = i + 1, b = a + 1; j < cols * 2; j++, b++) {
            if (a->unk_10.z > b->unk_10.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    p = rope->unk_24;
    for (i = 0; i < rope->unk_18; i++) {
        if (p->unk_0 != 0 && p[1].unk_0 == 0) {
            break;
        }
        p++;
    }
    p++;

    rows = (rope->unk_18 - (p - rope->unk_24)) / cols;
    for (j = 0; j < rows; j++) {
        for (c = 0; c < cols; c++) {
            p[c].unk_40 = -(f32)(j + 1) / (rows + 1);
        }
        for (c = 0, n = p; c < cols; c++, n++) {
            for (m = c + 1, q = n + 1; m < cols; m++, q++) {
                if (n->unk_10.z > q->unk_10.z) {
                    fn_1_128884((void *)n, (void *)q, sizeof(RopeNode_10DDE4));
                }
            }
        }
        p += cols;
    }

    rows = rope->unk_18 / cols;
    rope->unk_1C = rows * ((u32)cols - 1) + (rows - 1) * cols + (cols - 1) * 2;
    rope->unk_28 = fn_1_4630(lbl_801A6410, rope->unk_1C * sizeof(Link_10DDE4), "accessory.c", 0x248F);

    last = cols - 1;
    for (i = 0, k = 0, a = rope->unk_24; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a;
        rope->unk_28[k].unk_4 = a + cols + 1;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, a = rope->unk_24; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a + 1;
        rope->unk_28[k].unk_4 = a + cols;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, a = rope->unk_24; i < rope->unk_18 - 1; i++, a++) {
        if ((i + 1) % cols != 0) {
            rope->unk_28[k].unk_0 = a;
            rope->unk_28[k].unk_4 = a + 1;
            rope->unk_28[k].unk_8 = fn_1_1289BC((void *)a, (void *)(a + 1));
            k++;
        }
    }
    for (i = 0, a = rope->unk_24; i < rope->unk_18 - cols; i++, a++) {
        rope->unk_28[k].unk_0 = a;
        rope->unk_28[k].unk_4 = a + (u32)cols;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)a, (void *)(a + (u32)cols));
        k++;
    }
}
/* fzgx:end fn_1_1201E4 */

/* fzgx:begin fn_1_120804 */
#define INDEX(i) (lbl_1_data_3FFBC[i])

static inline f32 fn_1_120804_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f;
}

#define LINKFIX                                                   \
    {                                                             \
        f32 inv, r, wb, wa, fa, fb;                               \
        inv = lbl_8006D118(len, &len);                            \
        r = lbl_8006D0B4(l->length);                              \
        len = inv * (len - r);                                    \
        psvec_scale(&delta, len, &delta);                         \
        wa = a->weight;                                           \
        wb = b->weight;                                           \
        r = 1.0f / (wa + wb);                                     \
        fa = wa * r;                                              \
        fb = wb * r;                                              \
        psvec_scale_add(&a->pos, &delta, -fa, &a->pos);           \
        psvec_scale_add(&b->pos, &delta, fb, &b->pos);           \
    }

static inline void fn_1_120804_sphere(AccWork *arg0, u32 base, f32 cx, f32 cy, f32 cz, f32 radius, f32 strength) {
    Vec3 center;
    Vec3 diff;
    u32 ki;
    Node_10E3B4 *kn;
    center.y = cy;
    center.x = cx;
    center.z = cz;
    lbl_8006DBAC(arg0->owner->model->base + base);
    lbl_8006E1B0(&center, &center);
    for (ki = 0, kn = arg0->nodes; ki < arg0->count; ki++, kn++) {
        if (!(kn->flags & 1)) {
            f32 x, y, z, r;
            x = kn->pos.x;
            y = kn->pos.y;
            z = kn->pos.z;
            x -= center.x;
            y -= center.y;
            z -= center.z;
            r = (f32)(x * x) + y * y + z * z;
            if (r < radius) {
                psvec_sub_scale_add(&kn->pos, &center, strength * lbl_8006D0E8(r), &diff, &kn->pos);
            }
        }
    }
}

static inline void fn_1_120804_sphere0(AccWork *arg0, u32 base, f32 radius, f32 strength) {
    Vec3 center;
    Vec3 diff;
    u32 ki;
    Node_10E3B4 *kn;
    center.z = center.y = center.x = 0.0f;
    lbl_8006DBAC(arg0->owner->model->base + base);
    lbl_8006E1B0(&center, &center);
    for (ki = 0, kn = arg0->nodes; ki < arg0->count; ki++, kn++) {
        if (!(kn->flags & 1)) {
            f32 x, y, z, r;
            x = kn->pos.x;
            y = kn->pos.y;
            z = kn->pos.z;
            x -= center.x;
            y -= center.y;
            z -= center.z;
            r = (f32)(x * x) + y * y + z * z;
            if (r < radius) {
                psvec_sub_scale_add(&kn->pos, &center, strength * lbl_8006D0E8(r), &diff, &kn->pos);
            }
        }
    }
}

static inline void fn_1_120804_drift(Node_10E3B4 *n, Vec3 *d, Vec3 *random) {
    psvec_scale(&n->vel, 0.8f, &n->vel);
    psvec_sub(&n->pos, &n->prev, d);
    psvec_scale_add(&n->vel, d, 0.2f, &n->vel);
    psvec_scale_add(&n->vel, random, 0.5f, &n->vel);
}

static inline void fn_1_120804_attach(AccWork *arg0, u8 *model) {
    u32 i;
    Node_10E3B4 *n;
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        lbl_8006DBAC(model + 136);
        lbl_8006DAEC();
        if (n->flags & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0(&n->local, &n->pos);
        }
        lbl_8006DC20();
    }
}

#define SPHERE(BASE, CX, CY, CZ, RADIUS, STRENGTH) fn_1_120804_sphere(arg0, BASE, CX, CY, CZ, RADIUS, STRENGTH);

void fn_1_120804(AccWork *arg0) {

    u8 *fmodel;
    s32 cols;
    u32 k;
    s32 mode;
    u32 passes;
    u32 i;
    s32 li;
    Link_10E3B4 *l;
    Node_10E3B4 *a;
    Node_10E3B4 *b;
    Node_10E3B4 *n;
    u8 *model;
    Vec3 delta;
    Vec3 random;
    f32 len;
    Node_10E3B4 *n0;
    u32 i0;

    fn_1_A8EB0(20, 20);
    if (arg0 && arg0->obj) {
    fmodel = fn_80077B14(arg0->obj);
    cols = (arg0->owner->kind == 2) ? 9 : 13;
    if (arg0->flags & 2) {
        arg0->flags &= ~2;
        lbl_8006DBAC(arg0->owner->model->base + INDEX(arg0->index) * 396 + 136);
        lbl_8006DAEC();
        for (i0 = 0, n0 = arg0->nodes; i0 < arg0->count; i0++, n0++) {
            lbl_8006DBE4();
            lbl_8006E1B0(&n0->local, &n0->pos);
        }
        lbl_8006DC20();
    }
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        if (!(n->flags & 1)) {
            n->prev = n->pos;
            psvec_add(&n->pos, &n->vel, &n->pos);
            n->pos.y -= 0.0013611111376020642;
            n->vel.y -= 0.0027222224f;
        }
    }
    fn_1_120804_attach(arg0, arg0->owner->model->base + INDEX(arg0->index) * 396);
    if (strcmp((void *)(fn_1_950E8(arg0->owner->unk148)), (void *)("CAR_SEL")) == 0 ||
        strcmp((void *)(fn_1_950E8(arg0->owner->unk148)), (void *)("SEL_WAIT")) == 0 ||
        strcmp((void *)(fn_1_950E8(arg0->owner->unk148)), (void *)("SEL_WAIT_02")) == 0) {
        mode = 1;
    } else if (strcmp((void *)(fn_1_950E8(arg0->owner->unk148)), (void *)("SEL_WAIT_01")) == 0) {
        f32 f = arg0->owner->model->unk4C;
        if (f > 350.0f) {
            mode = 1;
        } else if (f > 30.0f) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        mode = 0;
    }
    passes = (strcmp((void *)(fn_1_950E8(arg0->owner->unk148)), (void *)("SEL_DEC")) == 0) ? 6 : 2;
    for (k = 0; k < passes; k++) {
        for (li = arg0->linkCount - 1, l = arg0->links + arg0->linkCount - 1; li >= 0; li--, l--) {
            a = l->a;
            b = l->b;
            if (a && b) {
                psvec_sub(&a->pos, &b->pos, &delta);
                len = __fmadds(delta.z, delta.z, __fmadds(delta.y, delta.y, delta.x * delta.x));
                if (len - 0.0001f > l->length) LINKFIX
                if (0.001f + len < l->length && li < (cols - 1) * 2) LINKFIX
            }
        }
        if (mode == 0) {
            SPHERE(0x214, 0.115f, 0.0f, 0.0f, 0.02016400173306465f, 0.142f)
            fn_1_120804_sphere0(arg0, 0x1948, 0.017160998657345772f, 0.131f);
            SPHERE(0x1c60, 0.141f, 0.0f, 0.0f, 0.0169f, 0.13f)
            SPHERE(0x241c, 0.141f, 0.0f, 0.0f, 0.0169f, 0.13f)
            if (strcmp((void *)(fn_1_950E8(arg0->owner->unk148)), (void *)("SEL_DEC")) == 0) {
                SPHERE(0x1c60, 0.027f, 0.0f, 0.0f, 0.016384001821279526f, 0.128f)
                SPHERE(0x241c, 0.027f, 0.0f, 0.0f, 0.016384001821279526f, 0.128f)
            }
            SPHERE(0x1dec, 0.051f, 0.0f, 0.0f, 0.014161000959575176f, 0.119f)
            SPHERE(0x25a8, 0.051f, 0.0f, 0.0f, 0.014161000959575176f, 0.119f)
            SPHERE(0x1dec, 0.183f, 0.0f, 0.0f, 0.013225000351667404f, 0.115f)
            SPHERE(0x25a8, 0.183f, 0.0f, 0.0f, 0.013225000351667404f, 0.115f)
        }
    }
    if (mode != 0) {
        Node_10E3B4 *wn;
        s32 wi;
        if (mode == 2) {
            for (wi = 0, wn = arg0->nodes; wi < arg0->count; wi++, wn++) {
                Vec3 d;
                s32 m;
                f32 w1, w2;
                s32 q;
                m = wi % cols;
                w2 = 0.2f + (0.8f * m) / 9.0f;
                w1 = 0.2f + (0.8f * (cols - m)) / 9.0f;
                psvec_scale(&wn->vel, 0.8f, &wn->vel);
                psvec_sub(&wn->pos, &wn->prev, &d);
                psvec_scale_add(&wn->vel, &d, 0.2f, &wn->vel);
                wn->vel.z += (f32)(w1 * (0.0012f * fn_1_120804_rand()));
                if (wi < arg0->count / 2) {
                    wn->vel.y += (f32)(w1 * ((f32)((0.0038f + (0.001f * wi) / (arg0->count / 2)) * fn_1_120804_rand()) - 0.001f));
                } else {
                    wn->vel.y += (f32)(w1 * ((f32)((0.0038f + (0.001f * (arg0->count - wi)) / (arg0->count / 2)) * fn_1_120804_rand()) - 0.001f));
                }
                q = wi / 4;
                wn->vel.x += (f32)(w1 * (0.0006f * lbl_8006D188((-32768.0f + (65536.0f * ((q + lbl_801A66A0) % 39)) / 39.0f))));
                wn->vel.x += (f32)(w2 * (0.0012f * fn_1_120804_rand()));
                if (wi < arg0->count / 2) {
                    wn->vel.y += (f32)(w2 * ((0.0015f + (0.0005f * wi) / (arg0->count / 2)) * fn_1_120804_rand()));
                } else {
                    wn->vel.y += (f32)(w2 * ((0.0015f + (0.0005f * (arg0->count - wi)) / (arg0->count / 2)) * fn_1_120804_rand()));
                }
                wn->vel.z -= (f32)(w2 * (0.0006f * lbl_8006D188((-32768.0f + (65536.0f * ((q + lbl_801A66A0) % 29)) / 29.0f))));
            }
        } else {
            for (wi = 0, wn = arg0->nodes; wi < arg0->count; wi++, wn++) {
                Vec3 d;
                s32 m;
                f32 w1, w2;
                s32 q;
                m = wi % cols;
                w2 = 0.2f + (0.8f * m) / 9.0f;
                w1 = 0.2f + (0.8f * (cols - m)) / 9.0f;
                psvec_scale(&wn->vel, 0.8f, &wn->vel);
                psvec_sub(&wn->pos, &wn->prev, &d);
                psvec_scale_add(&wn->vel, &d, 0.2f, &wn->vel);
                wn->vel.x -= (f32)(w1 * (0.0012f * fn_1_120804_rand()));
                if (wi < arg0->count / 2) {
                    wn->vel.y += (f32)(w1 * ((f32)((0.0038f + (0.001f * wi) / (arg0->count / 2)) * fn_1_120804_rand()) - 0.001f));
                } else {
                    wn->vel.y += (f32)(w1 * ((f32)((0.0038f + (0.001f * (arg0->count - wi)) / (arg0->count / 2)) * fn_1_120804_rand()) - 0.001f));
                }
                q = wi / 4;
                wn->vel.z += (f32)(w1 * (0.0006f * lbl_8006D188((-32768.0f + (65536.0f * ((q + lbl_801A66A0) % 39)) / 39.0f))));
                wn->vel.z += (f32)(w2 * (0.0012f * fn_1_120804_rand()));
                if (wi < arg0->count / 2) {
                    wn->vel.y += (f32)(w2 * ((0.0015f + (0.0005f * wi) / (arg0->count / 2)) * fn_1_120804_rand()));
                } else {
                    wn->vel.y += (f32)(w2 * ((0.0015f + (0.0005f * (arg0->count - wi)) / (arg0->count / 2)) * fn_1_120804_rand()));
                }
                wn->vel.x += (f32)(w2 * (0.0006f * lbl_8006D188((-32768.0f + (65536.0f * ((q + lbl_801A66A0) % 29)) / 29.0f))));
            }
        }
    } else {
        Vec3 push;
        Vec3 target;
        Vec3 d;
        if (arg0->timer < 30) {
            model = arg0->owner->model->base + INDEX(arg0->index) * 396;
            for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
                lbl_8006DBAC(model + 136);
                lbl_8006E1B0(&n->local, &target);
                psvec_sub(&n->pos, &target, &push);
                lbl_8006D668(&push);
                psvec_scale_add(&n->vel, &push, -0.001f, &n->vel);
            }
        }
        arg0->timer--;
        if (arg0->timer < 0) {
            lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
            arg0->timer = (s32)((lbl_801A63C0 >> 16) & 0x7FFF) % 10 + 30;
        }
        for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
            fn_1_1286F4((void *)&random);
            fn_1_120804_drift(n, &d, &random);
        }
    }
    fn_1_108128((void *)arg0, cols);
    for (i = 0, k = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        if (!(n->flags & 1)) {
            ((Vec3 *)&lbl_1_bss_88B50)[k] = n->pos;
            if (((Vec3 *)&lbl_1_bss_88B50)[k].y < 0.0f) {
                ((Vec3 *)&lbl_1_bss_88B50)[k].y = 0.0001f;
            }
            k++;
        }
    }
    lbl_8006DBAC(arg0->owner->model->base + INDEX(arg0->index) * 396 + 136);
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        f32 y;
        u32 j;
        if (n->pos.y < 0.0f) {
            y = n->pos.y;
            n->pos.y = 0.0001f;
        } else {
            y = n->pos.y;
        }
        for (j = 0; (s32)j < n->count; j++) {
            fn_8006E250(&n->pos, fmodel + (n->links[j] << 6));
        }
        n->pos.y = y;
    }
    }
}
#undef INDEX
#undef LINKFIX
#undef SPHERE
/* fzgx:end fn_1_120804 */

/* fzgx:begin fn_1_122348 */
void fn_1_122348(Obj122348 *obj) {
    Group122348 *h;
    u32 j;
    Group122348 *g_2;
    s32 n;
    u32 k;
    Group122348 *start;
    u32 rounds;
    u32 i;
    Group122348 *g;
    s32 num;

    if (obj == NULL) {
        return;
    }
    num = (obj->owner->mode == 2) ? 9 : 13;
    fn_1_10846C((void *)obj);

    k = 0;
    g = obj->groups;
    for (; k < obj->count; k++, g++) {
        if (g->flags & 1) {
            g->flags = 0;
            g->unk40 = -1.0f;
        } else {
            g->flags = 1;
            g->unk40 = 0.0f;
        }
    }

    g = obj->groups;
    for (k = 0; k < obj->count; k++, g++) {
        j = k + 1;
        h = &obj->groups[k] + 1;
        for (; j < obj->count; j++, h++) {
            if (g->flags == 0 && h->flags != 0) {
                fn_1_128884((void *)g, (void *)h, sizeof(Group122348));
            }
        }
    }

    g = obj->groups;
    for (k = 0; k < obj->count; k++, g++) {
        h = &obj->groups[k] + 1;
        for (j = k + 1; j < obj->count; j++, h++) {
            if (g->flags == h->flags && g->unk10 < h->unk10) {
                fn_1_128884((void *)g, (void *)h, sizeof(Group122348));
            }
        }
    }

    n = num;
    g = obj->groups;
    for (k = 0; k < num; k++, g++) {
        for (j = k + 1, h = g + 1; j < num; j++, h++) {
            if (g->unk18 > h->unk18) {
                fn_1_128884((void *)g, (void *)h, sizeof(Group122348));
            }
        }
    }
    g = obj->groups + n;
    for (k = n; k < num * 2; k++, g++) {
        for (j = k + 1, h = g + 1; j < num * 2; j++, h++) {
            if (g->unk18 > h->unk18) {
                fn_1_128884((void *)g, (void *)h, sizeof(Group122348));
            }
        }
    }

    start = obj->groups;
    for (i = 0; i < obj->count; i++) {
        if (start->flags != 0 && start[1].flags == 0) {
            break;
        }
        start++;
    }
    start++;
    rounds = (obj->count - (start - obj->groups)) / n;

    for (k = 0; k < rounds; k++) {
        for (i = 0; i < n; i++) {
            start[i].unk40 = -(f32)(k + 1) / (rounds + 1);
        }
        h = start;
        for (j = 0; j < n; j++, h++) {
            for (i = j + 1, g_2 = h + 1; i < n; i++, g_2++) {
                if (h->unk18 > g_2->unk18) {
                    fn_1_128884((void *)h, (void *)g_2, sizeof(Group122348));
                }
            }
        }
        start += n;
    }
}
/* fzgx:end fn_1_122348 */

/* fzgx:begin fn_1_12277C */
static inline void fn_1_12277C_reset_parts(fn_1_12277C_Object *self)
{
    s32 i;
    fn_1_12277C_Part *p;

    p = self->unk_24;
    for (i = 0; i < self->unk_18; i++, p++) {
        lbl_8006DBE4();
        lbl_8006E1B0(&p->unk_28, &p->unk_10);
    }
}

static inline void fn_1_12277C_attach_parts(fn_1_12277C_Object *self, u8 *tbl)
{
    s32 i;
    s32 j;
    fn_1_12277C_Part *p;

    p = self->unk_24;
    for (i = 0; i < self->unk_18; i++, p++) {
        for (j = 0; j < p->unk_2; j++) {
            fn_8006E250(&p->unk_10, tbl + p->unk_4[j] * 64);
        }
    }
}

void fn_1_12277C(fn_1_12277C_Object *self)
{
    s32 i;
    s32 n;
    fn_1_12277C_Part *part;
    u8 *pool;
    u8 *tbl;

    if (self == 0) {
        return;
    }
    if (self->unk_10 == 0) {
        return;
    }
    fn_80077B14(self->unk_10);

    if (self->unk_0 & 2) {
        self->unk_0 &= ~2;
        lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                    lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
        lbl_8006DAEC();
        fn_1_12277C_reset_parts(self);
        lbl_8006DC20();
    }

    pool = self->unk_C->unk_150->unk_8 +
           lbl_1_data_3FFBC[self->unk_8] * 0x18c;
    n = 0;
    part = self->unk_24;
    for (i = 0; i < self->unk_18; i++, part++) {
        if (part->unk_0 & 1) {
            lbl_8006DBAC(pool + 0x88);
            lbl_8006E1B0(&part->unk_28, &part->unk_10);
        }
        else {
            part->unk_10 = ((fn_1_12277C_Vec *)&lbl_1_bss_88B50)[n];
            n++;
        }
    }

    tbl = fn_80077B14(self->unk_10);
    lbl_8006DBAC(self->unk_C->unk_150->unk_8 +
                lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
    fn_1_12277C_attach_parts(self, tbl);
}
/* fzgx:end fn_1_12277C */

/* fzgx:begin fn_1_12295C */
void fn_1_12295C(Rope_10DDE4 *rope) {
    u32 i;
    u32 m;
    RopeNode_10DDE4 *b;
    RopeNode_10DDE4 *a;
    RopeNode_10DDE4 *p;
    RopeNode_10DDE4 *n;
    s32 last;
    u32 j;
    RopeNode_10DDE4 *q;
    u32 k;
    u32 rows;
    s32 cols;

    if (rope == NULL) {
        return;
    }
    cols = (rope->unk_C->unk_8C == 2) ? 8 : 12;
    fn_1_10846C((void *)rope);

    for (i = 0, n = rope->unk_24; i < rope->unk_18; i++, n++) {
        if (n->unk_0 & 1) {
            n->unk_0 = 0;
            n->unk_40 = -1.0f;
        } else {
            n->unk_0 = 1;
            n->unk_40 = 0.0f;
        }
    }

    for (i = 0, a = rope->unk_24; i < rope->unk_18; i++, a++) {
        for (j = i + 1, b = &rope->unk_24[i] + 1; j < rope->unk_18; j++, b++) {
            if (a->unk_0 == 0 && b->unk_0 != 0) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = 0, a = rope->unk_24; i < rope->unk_18; i++, a++) {
        for (j = i + 1, b = &rope->unk_24[i] + 1; j < rope->unk_18; j++, b++) {
            if (a->unk_0 == b->unk_0 && a->unk_10.x > b->unk_10.x) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = 0, a = rope->unk_24; i < cols; i++, a++) {
        for (j = i + 1, b = a + 1; j < cols; j++, b++) {
            if (a->unk_10.z > b->unk_10.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    for (i = cols, a = &rope->unk_24[cols]; i < cols * 2; i++, a++) {
        for (j = i + 1, b = a + 1; j < cols * 2; j++, b++) {
            if (a->unk_10.z > b->unk_10.z) {
                fn_1_128884((void *)a, (void *)b, sizeof(RopeNode_10DDE4));
            }
        }
    }

    p = rope->unk_24;
    for (i = 0; i < rope->unk_18; i++) {
        if (p->unk_0 != 0 && p[1].unk_0 == 0) {
            break;
        }
        p++;
    }
    p++;

    rows = (rope->unk_18 - (p - rope->unk_24)) / cols;
    for (j = 0; j < rows; j++) {
        for (i = 0; i < cols; i++) {
            p[i].unk_40 = -(f32)(j + 1) / (rows + 1);
        }
        for (i = 0, n = p; i < cols; i++, n++) {
            for (m = i + 1, q = n + 1; m < cols; m++, q++) {
                if (n->unk_10.z > q->unk_10.z) {
                    fn_1_128884((void *)n, (void *)q, sizeof(RopeNode_10DDE4));
                }
            }
        }
        p += cols;
    }

    rows = rope->unk_18 / cols;
    rope->unk_1C = rows * ((u32)cols - 1) + (rows - 1) * cols + (cols - 1) * 4;
    rope->unk_28 = fn_1_4630(lbl_801A6410, rope->unk_1C * sizeof(Link_10DDE4), "accessory.c", 0x279A);

    last = cols - 1;
    for (i = 0, k = 0, a = rope->unk_24; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a;
        rope->unk_28[k].unk_4 = a + cols + 1;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, a = rope->unk_24; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a + 1;
        rope->unk_28[k].unk_4 = a + cols;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, a = rope->unk_24; i < last; i++, a++) {
        rope->unk_28[k].unk_0 = a + cols;
        rope->unk_28[k].unk_4 = a + cols + 1 + cols;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, b = rope->unk_24; i < last; i++, b++) {
        rope->unk_28[k].unk_0 = b + cols + 1;
        rope->unk_28[k].unk_4 = b + cols + cols;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)rope->unk_28[k].unk_0, (void *)rope->unk_28[k].unk_4);
        k++;
    }
    for (i = 0, a = rope->unk_24; i < rope->unk_18 - 1; i++, a++) {
        if ((i + 1) % cols != 0) {
            rope->unk_28[k].unk_0 = a;
            rope->unk_28[k].unk_4 = a + 1;
            rope->unk_28[k].unk_8 = fn_1_1289BC((void *)a, (void *)(a + 1));
            k++;
        }
    }
    for (i = 0, a = rope->unk_24; i < rope->unk_18 - cols; i++, a++) {
        rope->unk_28[k].unk_0 = a;
        rope->unk_28[k].unk_4 = a + (u32)cols;
        rope->unk_28[k].unk_8 = fn_1_1289BC((void *)a, (void *)(a + (u32)cols));
        k++;
    }
}
/* fzgx:end fn_1_12295C */

/* fzgx:begin fn_1_123050 */
/* VIEWS */
#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_GLOBALS_H

/* end rel/main_rel/accessory.h */

#define lbl_8006D118(p) (lbl_8006D118)(*(p), (p))

#define BONE(r, n) ((r)->model->bones->data + (n) * 0x18c + 0x88)

#define MODELROOT(r) ((r)->model->bones->data)

#define BONEID(r) (lbl_1_data_3FFBC[(r)->id])

static inline f32 sim_dot(const Vec3 *v) {
    f32 result = v->x * v->x;
    result += v->y * v->y;
    result += v->z * v->z;
    return result;
}

static inline void sim_sphere(SimRope *r, s32 bone, f32 x, f32 y, f32 z,
                             f32 radius2, f32 radius) {
    Vec3 center, delta;
    u32 i;
    SimNode *n;
    vec_set_xyz(&center, x, y, z);
    lbl_8006DBAC(BONE(r, bone));
    lbl_8006E1B0(&center, &center);
    n = r->nodes;
    for (i = 0; i < r->count; i++, n++) {
        if (!(n->flags & 1)) {
            f32 len, dz, dy;
            len = n->pos.x - center.x;
            dy = n->pos.y - center.y;
            dz = n->pos.z - center.z;
            len *= len;
            len += dy * dy;
            len += dz * dz;
            if (len < radius2) {
                f32 s = radius * lbl_8006D0E8(len);
                psvec_sub_scale_add(&n->pos, &center, s, &delta, &n->pos);
            }
        }
    }
}

#pragma inline_max_size(4096)

#pragma opt_common_subs off

static inline void sim_upload(SimRope *r, u8 *vertices) {
    u32 pass;
    s32 j;
    SimNode *n;
    n = r->nodes;
    for (pass = 0; pass < r->count; pass++, n++) {
        for (j = 0; j < n->count; j++)
            fn_8006E250(&n->pos, vertices + n->links[j] * 0x40);
    }
}

static inline void sim_reset_args(SimRope *r, SimNode *node, u32 index) {
    for (; index < r->count; index++, node++) {
        lbl_8006DBE4();
        lbl_8006E1B0(&node->local, &node->pos);
    }
}

static inline void sim_pin(SimRope *r) {
    u32 index;
    u8 *bone;
    SimNode *n;
    bone = MODELROOT(r) + BONEID(r) * 0x18c;
    n = r->nodes;
    for (index = 0; index < r->count; index++, n++) {
        lbl_8006DBAC(bone + 0x88);
        lbl_8006DAEC();
        if (n->flags & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0(&n->local, &n->pos);
        }
        lbl_8006DC20();
    }
}

static inline void sim_pull(SimRope *r, u8 *unused_bone, SimNode *unused_node, u32 unused_index,
                            Vec3 *anchor, Vec3 *diff) {
    u8 *bone;
    SimNode *n;
    u32 i;
    bone = MODELROOT(r) + BONEID(r) * 0x18c;
    n = r->nodes;
    for (i = 0; i < r->count; i++, n++) {
        f32 pos_y;
        lbl_8006DBAC(bone + 0x88);
        lbl_8006E1B0(&n->local, anchor);
        diff->x = n->pos.x - anchor->x;
        pos_y = n->pos.y;
        diff->y = pos_y - anchor->y;
        diff->z = n->pos.z - anchor->z;
        lbl_8006D668(diff);
        n->vel.x -= (f32)(0.001f * diff->x);
        n->vel.y -= (f32)(0.001f * diff->y);
        n->vel.z -= (f32)(0.001f * diff->z);
    }
}

void fn_1_123050(SimRope *r) {
    f32 fzgx_live;
    Vec3 delta, noise, diff, anchor;
    f32 length;
    SimLink *link;
    SimNode *a, *b, *n;
    u32 i;
    u8 *bone, *vertices;
    s32 j;
    u32 solve_iterations;
    u32 compress_count, pass, ndiv;
    f32 headx, heady, zero, leftx, rightx, chesty, arm_x, arm_y, outerx, lowx, lowy;
    f64 noise_scale, inherit, damping;

    solve_iterations = 4;
    if (r && r->mesh) {
    ((s32)fn_80077B14(r->mesh));
    if (r->flags & 2) {
        r->flags &= ~2;
        lbl_8006DBAC(BONE(r, BONEID(r)));
        lbl_8006DAEC();
        i = 0;
        n = r->nodes;
        sim_reset_args(r, n, i);
        lbl_8006DC20();
    }
    ndiv = (r->model->kind == 2) ? 8 : 12;
    n = r->nodes;
    for (i = 0; i < r->count; i++, n++) {
        if (!(n->flags & 1)) {
            n->prev = n->pos;
            n->pos.x += n->vel.x;
            n->pos.y += n->vel.y;
            n->pos.z += n->vel.z;
            n->pos.y -= 0.0013611111376020642;
            n->vel.y -= 0.0027222224f;
        }
    }
    sim_pin(r);
    solve_iterations = (r->model->kind == 2) ? 2 : 4;
    zero = 0.0f;
    heady = 0.082f;
    headx = 0.047f;
    leftx = -0.004f;
    rightx = 0.12f;
    chesty = -0.019f;
    compress_count = (ndiv - 1) * 4;
    for (pass = 0; pass < solve_iterations; pass++) {
        link = r->links;
        for (i = 0; i < r->link_count; i++, link++) {
            a = link->a; b = link->b;
            if (a && b) {
                f32 epsilon, dz, dy, dx;
                dx = a->pos.x - b->pos.x;
                dy = a->pos.y - b->pos.y;
                dz = a->pos.z - b->pos.z;
                delta.x = dx;
                delta.y = dy;
                delta.z = dz;
                length = (f32)(dx * dx) + dy * dy + dz * dz;
                if (length - 0.0001f > link->length) {
                    f32 inv = lbl_8006D118(&length);
                    f32 rest = lbl_8006D0B4(link->length);
                    f64 one;
                    f32 ma, mb, sum, mass_a, mass_b;
                    one = 1.0f;
                    length = inv * (length - rest);
                    psvec_scale(&delta, length, &delta);
                    mass_a = a->mass;
                    mass_b = b->mass;
                    sum = 1.0f / (mass_a + mass_b);
                    ma = mass_a * sum;
                    mb = mass_b * sum;
                    psvec_scale_add(&a->pos, &delta, -ma, &a->pos);
                    psvec_scale_add(&b->pos, &delta, mb, &b->pos);
                }
                if (0.001f + length < link->length && i < compress_count) {
                    f32 inv = lbl_8006D118(&length);
                    f32 rest = lbl_8006D0B4(link->length);
                    f32 ma, mb, sum, one, mass_b, mass_a;
                    sum = 1.0f;
                    length = inv * (length - rest);
                    psvec_scale(&delta, length, &delta);
                    mass_a = a->mass;
                    mass_b = b->mass;
                    sum = 1.0f / (mass_a + mass_b);
                    ma = mass_a * sum;
                    mb = mass_b * sum;
                    psvec_scale_add(&a->pos, &delta, -ma, &a->pos);
                    psvec_scale_add(&b->pos, &delta, mb, &b->pos);
                }
                fzgx_live = a->pos.y;
                if ((fzgx_live < 0.0f || b->pos.y < 0.0f) &&
                    !(a->flags & 1) && !(b->flags & 1)) {
                    f32 inv;
                    f32 rest, ma, mb, sum, one, mass_b, mass_a;
                    if (fzgx_live < 0.0f) a->pos.y = 0.00001f;
                    if (b->pos.y < 0.0f) b->pos.y = 0.00001f;
                    psvec_sub(&a->pos, &b->pos, &delta);
                    length = sim_dot(&delta);
                    inv = lbl_8006D118(&length);
                    rest = lbl_8006D0B4(link->length);
                    sum = 1.0f;
                    length = inv * (length - rest);
                    psvec_scale(&delta, length, &delta);
                    mass_a = a->mass;
                    mass_b = b->mass;
                    sum = 1.0f / (mass_a + mass_b);
                    ma = mass_a * sum;
                    mb = mass_b * sum;
                    psvec_scale_add(&a->pos, &delta, -ma, &a->pos);
                    psvec_scale_add(&b->pos, &delta, mb, &b->pos);
                }
            }
        }
        sim_sphere(r, 16, headx, heady, zero, 0.010404f, 0.102f);
        sim_sphere(r, 18, leftx, zero, zero, 0.0036f, 0.06f);
        sim_sphere(r, 18, rightx, zero, zero, 0.005625f, 0.075f);
        sim_sphere(r, 19, zero, chesty, zero, 0.005625f, 0.075f);
        arm_y = -0.028f;
        arm_x = 0.265f;
        sim_sphere(r, 19, arm_x, arm_y, zero, 0.0121f, 0.11f);
        sim_sphere(r, 23, leftx, zero, zero, 0.0036f, 0.06f);
        sim_sphere(r, 23, rightx, zero, zero, 0.005625f, 0.075f);
        sim_sphere(r, 24, zero, chesty, zero, 0.005625f, 0.075f);
        sim_sphere(r, 24, arm_x, arm_y, zero, 0.0121f, 0.11f);
        outerx = 0.08f;
        sim_sphere(r, 18, outerx, zero, zero, 0.0064f, 0.08f);
        lowy = -0.025f;
        lowx = 0.138f;
        sim_sphere(r, 19, lowx, lowy, zero, 0.011024999f, 0.105f);
        sim_sphere(r, 23, outerx, zero, zero, 0.0064f, 0.08f);
        sim_sphere(r, 24, lowx, lowy, zero, 0.011024999f, 0.105f);
    }
    if (r->timer < 35) {
        bone = MODELROOT(r) + BONEID(r) * 0x18c;
        n = r->nodes;
        i = 0;
        sim_pull(r, bone, n, i, &anchor, &diff);
    }
    r->timer--;
    if (r->timer < 0) {
        s32 random;
        lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        random = (lbl_801A63C0 >> 16) & 0x7fff;
        r->timer = random % 20 + 40;
    }
    n = r->nodes;
    for (i = 0; i < r->count; i++, n++) {
        fn_1_1286F4((void *)&noise);
        n->vel.x *= 0.59;
        n->vel.y *= 0.59;
        n->vel.z *= 0.59;
        n->vel.x += (f64)(0.4 * (n->pos.x - n->prev.x));
        fzgx_live = n->pos.y;
        n->vel.y += (f64)(0.4 * (fzgx_live - n->prev.y));
        n->vel.z += (f64)(0.4 * (n->pos.z - n->prev.z));
        n->vel.x += (f64)(0.5 * noise.x);
        n->vel.y += (f64)(0.5 * noise.y);
        n->vel.z += (f64)(0.5 * noise.z);
    }
    fn_1_108128((void *)r, ndiv);
    vertices = (u8 *)((s32)fn_80077B14(r->mesh));
    lbl_8006DBAC(BONE(r, BONEID(r)));
    sim_upload(r, vertices);
    }
}

#pragma opt_common_subs reset

#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_GLOBALS_H
#undef lbl_8006D118
#undef BONE
#undef MODELROOT
#undef BONEID
/* fzgx:end fn_1_123050 */

/* fzgx:begin fn_1_1244F0 */
/* VIEWS */
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

/* rel/main_rel/accessory.h: inlined above */

/* 0x44 */

void fn_1_1244F0(Obj1244F0 *obj) {
    Group1244F0 *p;
    u32 jRow;
    Group1244F0 *aRow;
    Group1244F0 *a4;
    Group1244F0 *bFirst;
    Group1244F0 *b2;
    u32 kRow;
    Group1244F0 *a;
    Group1244F0 *b;
    Group1244F0 *bRow;
    u32 j;
    u32 k4;
    u32 rows;
    u32 n;
    u32 i;
    Group1244F0 *g;
    f32 v;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        g = obj->groups;
        for (i = 0; i < obj->groupCount; i++, g++) {
            if (g->flags & 1) {
                g->flags = 0;
                g->f40 = -1.0f;
            } else {
                g->flags = 1;
                g->f40 = 0.0f;
            }
        }

        p = obj->groups;
        for (i = 0; i < obj->groupCount; i++, p++) {
            j = i + 1;
            b = obj->groups + i + 1;
            for (; j < obj->groupCount; j++, b++) {
                if (p->flags == 0 && b->flags != 0) {
                    fn_1_128884((void *)p, (void *)b, sizeof(Group1244F0));
                }
            }
        }

        p = obj->groups;
        for (i = 0; i < obj->groupCount; i++, p++) {
            b2 = obj->groups + i + 1;
            for (j = i + 1; j < obj->groupCount; j++, b2++) {
                if (p->flags == b2->flags && p->f10 < b2->f10) {
                    fn_1_128884((void *)p, (void *)b2, sizeof(Group1244F0));
                }
            }
        }

        p = obj->groups;
        for (i = 0; i < obj->groupCount / 9; i++, p += 9) {
            for (j = 0, a4 = p; j < 9; j++, a4++) {
                for (k4 = j + 1, a = a4 + 1; k4 < 9; k4++, a++) {
                    if (a4->f18 < a->f18) {
                        fn_1_128884((void *)a4, (void *)a, sizeof(Group1244F0));
                    }
                }
            }
        }

        for (p = obj->groups, i = 0; i < 9; i++, p++) {
            for (j = i + 1, bFirst = p + 1; j < 9; j++, bFirst++) {
                if (p->f18 > 0.0f && bFirst->f18 > 0.0f && p->f14 > bFirst->f14) {
                    fn_1_128884((void *)p, (void *)bFirst, sizeof(Group1244F0));
                } else if (p->f18 <= 0.0f && bFirst->f18 <= 0.0f && p->f14 < bFirst->f14) {
                    fn_1_128884((void *)p, (void *)bFirst, sizeof(Group1244F0));
                }
            }
        }

        p = obj->groups;
        for (i = 0; i < obj->groupCount; i++, p++) {
            if (p->flags != 0 && p[1].flags == 0) {
                break;
            }
        }
        p++;
        rows = (obj->groupCount - (p - obj->groups)) / 9;

        for (i = 0; i < rows; i++, p += 9) {
            for (j = 0; j < 9; j += 3) {
                v = -(f32)(i + 1) / (rows + 1);
                p[j].f40 = v;
                p[j + 1].f40 = v;
                p[j + 2].f40 = v;
            }
            for (aRow = p, jRow = 0; jRow < 9; jRow++, aRow++) {
                for (kRow = jRow + 1, bRow = aRow + 1; kRow < 9; kRow++, bRow++) {
                    if (aRow->f18 > 0.0f && bRow->f18 > 0.0f && aRow->f14 > bRow->f14) {
                        fn_1_128884((void *)aRow, (void *)bRow, sizeof(Group1244F0));
                    } else if (aRow->f18 <= 0.0f && bRow->f18 <= 0.0f && aRow->f14 < bRow->f14) {
                        fn_1_128884((void *)aRow, (void *)bRow, sizeof(Group1244F0));
                    }
                }
            }
        }

        obj->linkCount = (obj->groupCount / 9) * 8 + (obj->groupCount / 9 - 1) * 9;
        obj->links = fn_1_4630(lbl_801A6410, obj->linkCount * sizeof(Link1244F0), "accessory.c", 0x2904);

        n = 0;
        p = obj->groups;
        for (i = 0; i < obj->groupCount - 1; i++, p++) {
            if ((i + 1) % 9 != 0) {
                obj->links[n].a = p;
                obj->links[n].b = p + 1;
                obj->links[n].distance = fn_1_1289BC((void *)((const Point1024C4 *)p), (void *)((const Point1024C4 *)(p + 1)));
                n++;
            }
        }

        p = obj->groups;
        for (i = 0; i < obj->groupCount - 9; i++, p++) {
            obj->links[n].a = p;
            obj->links[n].b = p + 9;
            obj->links[n].distance = fn_1_1289BC((void *)((const Point1024C4 *)p), (void *)((const Point1024C4 *)(p + 9)));
            n++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_1244F0 */

/* fzgx:begin fn_1_124AD4 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

#pragma opt_common_subs off

void fn_1_124AD4(Work_124AD4 *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 k;
 u32 fi;
 u32 i1;
 Node *n3;
 Node *a;
 u32 ki;
 u32 fj;
 u32 i3;
 Link *l;
 Node *kn;
 Node *vn;
 Node *fn;
 u32 li;
 u32 vi;
 u16 *lp;
 Node *b;
 Node *n2;
 u32 i2;
 Vec3 deltav;
 Vec3 random;
 Vec3 diff;
 Vec3 center;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 f32 scale,centerX,centerY,centerZ;
 centerZ=0.0f; centerY=-0.016f; centerX=0.049f;
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 /* Read the original position before updating the correction vector. */
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 vec_set_xyz(&center,centerX,centerY,centerZ);
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+532)));
 lbl_8006E1B0((void *)&center,(void *)&center);
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) {
 if(!(kn->flags&1)) {
 f32 x,z,y,r;
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z;
 x-=center.x; y-=center.y; z-=center.z;
 r=(f32)(x*x)+y*y+z*z;
 if(r<0.006561f) {
 scale=0.081f*lbl_8006D0E8(r);
 psvec_sub_scale_add(&kn->pos,&center,scale,&diff,&kn->pos);
 }
 }
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.8; vn->vel.y*=0.8; vn->vel.z*=0.8;
 vn->vel.x+=(f64)(0.2*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.2*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.2*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef delta
/* fzgx:end fn_1_124AD4 */

/* fzgx:begin fn_1_1250D0 */
/* VIEWS */
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

/* rel/main_rel/accessory.h: inlined above */

void fn_1_1250D0(fn_1_10D2F0_Obj *obj) {
    u32 div;
    u32 j;
    Entry_1250D0 *a;
    u32 k;
    u32 rows;
    u32 i;
    u32 count;
    u32 n;
    u32 q;
    Entry_1250D0 *base;
    Entry_1250D0 *p;
    Entry_1250D0 *b;
    f32 num;

    if (obj != NULL) {
        fn_1_10846C((void *)obj);

        for (i = 0, p = obj->unk_24; i < obj->unk_18; i++, p++) {
            if (p->unk_0 & 1) {
                p->unk_0 = 0;
                p->unk_40 = -1.0f;
            } else {
                p->unk_0 = 1;
                p->unk_40 = 0.0f;
            }
        }

        for (i = 0, p = obj->unk_24; i < obj->unk_18; i++, p++) {
            for (j = i + 1, a = obj->unk_24 + i + 1; j < obj->unk_18; j++, a++) {
                if (p->unk_0 == 0 && a->unk_0 != 0) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_1250D0));
                }
            }
        }

        for (i = 0, p = obj->unk_24; i < obj->unk_18; i++, p++) {
            for (j = i + 1, a = obj->unk_24 + i + 1; j < obj->unk_18; j++, a++) {
                if (p->unk_0 == a->unk_0 && p->unk_10.x < a->unk_10.x) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_1250D0));
                }
            }
        }

        for (i = 0, p = obj->unk_24; i < obj->unk_18 / 13; i++, p += 13) {
            for (j = 0, a = p; j < 13; j++, a++) {
                for (k = j + 1, b = a + 1; k < 13; k++, b++) {
                    if (a->unk_10.z < b->unk_10.z) {
                        fn_1_128884((void *)a, (void *)b, sizeof(Entry_1250D0));
                    }
                }
            }
        }

        /* first row: positive-z entries by descending y, the rest by ascending y */
        for (i = 0, p = obj->unk_24; i < 13; i++, p++) {
            for (j = i + 1, a = p + 1; j < 13; j++, a++) {
                if (p->unk_10.z > 0.0f && a->unk_10.z > 0.0f && p->unk_10.y > a->unk_10.y) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_1250D0));
                } else if (p->unk_10.z <= 0.0f && a->unk_10.z <= 0.0f && p->unk_10.y < a->unk_10.y) {
                    fn_1_128884((void *)p, (void *)a, sizeof(Entry_1250D0));
                }
            }
        }

        base = obj->unk_24;
        count = obj->unk_18;
        p = base;
        for (i = 0; i < count; i++) {
            if (p->unk_0 != 0 && p[1].unk_0 == 0) {
                break;
            }
            p++;
        }
        p++;
        rows = (count - (p - base)) / 13;
        div = rows + 1;
        for (i = 0; i < rows; i++, p += 13) {
            num = -(f32)(i + 1);
            for (j = 0; j < 13; j++) {
                p[j].unk_40 = num / div;
            }
            for (j = 0, a = p; j < 13; j++, a++) {
                for (k = j + 1, b = a + 1; k < 13; k++, b++) {
                    if (a->unk_10.z > 0.0f && b->unk_10.z > 0.0f && a->unk_10.y > b->unk_10.y) {
                        fn_1_128884((void *)a, (void *)b, sizeof(Entry_1250D0));
                    } else if (a->unk_10.z <= 0.0f && b->unk_10.z <= 0.0f && a->unk_10.y < b->unk_10.y) {
                        fn_1_128884((void *)a, (void *)b, sizeof(Entry_1250D0));
                    }
                }
            }
        }

        q = obj->unk_18 / 13;
        obj->unk_1C = q * 12 + (q - 1) * 13;
        obj->unk_28 = (fn_1_10D2F0_Link *)((u32)fn_1_4630(lbl_801A6410, obj->unk_1C * sizeof(fn_1_10D2F0_Link), "accessory.c", 0x29F7));

        n = 0;
        p = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 1; i++, p++) {
            if ((i + 1) % 13 != 0) {
                obj->unk_28[n].a = p;
                obj->unk_28[n].b = p + 1;
                obj->unk_28[n].len = fn_1_1289BC((const Point1024C4 *)p, (const Point1024C4 *)(p + 1));
                n++;
            }
        }

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18 - 13; n++, i++, p++) {
            obj->unk_28[n].a = p;
            obj->unk_28[n].b = p + 13;
            obj->unk_28[n].len = fn_1_1289BC((const Point1024C4 *)p, (const Point1024C4 *)(p + 13));
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_1250D0 */

/* fzgx:begin fn_1_1256EC */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

#pragma opt_common_subs off

void fn_1_1256EC(Work_1256EC *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 k;
 u32 fi;
 u32 i1;
 Node *n3;
 Node *a;
 u32 ki;
 u32 fj;
 u32 i3;
 Link *l;
 Node *kn;
 Node *vn;
 Node *fn;
 u32 li;
 u32 vi;
 u16 *lp;
 Node *b;
 Node *n2;
 u32 i2;
 Vec3 deltav;
 Vec3 random;
 Vec3 diff;
 Vec3 center;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 f32 scale,centerX,centerY,centerZ;
 centerZ=0.0f; centerY=-0.008f; centerX=0.038f;
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 /* Read the original position before updating the correction vector. */
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 vec_set_xyz(&center,centerX,centerY,centerZ);
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+532)));
 lbl_8006E1B0((void *)&center,(void *)&center);
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) {
 if(!(kn->flags&1)) {
 f32 x,z,y,r;
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z;
 x-=center.x; y-=center.y; z-=center.z;
 r=(f32)(x*x)+y*y+z*z;
 if(r<0.0047609997f) {
 scale=0.069f*lbl_8006D0E8(r);
 psvec_sub_scale_add(&kn->pos,&center,scale,&diff,&kn->pos);
 }
 }
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.8; vn->vel.y*=0.8; vn->vel.z*=0.8;
 vn->vel.x+=(f64)(0.2*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.2*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.2*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef delta
/* fzgx:end fn_1_1256EC */

/* fzgx:begin fn_1_125CE8 */
void fn_1_125CE8(fn_1_125CE8_AccessoryData *data) {
    u32 i;
    fn_1_125CE8_AccessoryEntry *entry;
    f32 min_value;
    f32 max_value;
    f32 range;
    f32 value_off;
    f32 value_on;

    if (data != 0) {
        fn_1_10846C((void *)data);

        i = 0;
        entry = data->entries;
        value_on = -1.0f;
        value_off = 0.0f;
        while (i < data->count) {
            if ((entry->active & 1) != 0) {
                entry->result = value_on;
                entry->active = 0;
            } else {
                entry->result = value_off;
                entry->active = 1;
            }
            i++;
            entry++;
        }

        entry = data->entries;
        min_value = 100000.0f;
        max_value = -100000.0f;
        i = 0;
        while (i < data->count) {
            if (entry->value < min_value) {
                min_value = entry->value;
            }
            if (entry->value > max_value) {
                max_value = entry->value;
            }
            i++;
            entry++;
        }

        range = max_value - min_value;
        value_on = -1.0f;
        entry = data->entries;
        i = 0;
        while (i < data->count) {
            entry->result = value_on +
                (entry->value - min_value) / range;
            i++;
            entry++;
        }
    }
}
/* fzgx:end fn_1_125CE8 */

/* fzgx:begin fn_1_125DF0 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_125DF0(Work_125DF0 *arg0) {
 u8 *fmodel;
 Node *n1;
 u32 i1;
 Node *fn;
 u32 fj;
 u8 *model5;
 u32 fi;
 Node *n5;
 u32 vi;
 Node *vn;
 Node *n2;
 u16 *lp;
 u32 i5;
 u32 i2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Vec3 random;
 Vec3 target2;
 Vec3 diff;
 Vec3 target;
 Vec3 *qp = &diff;
#define dif (*qp)
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x+(f64)(0.5*random.x);
 n2->pos.y+=n2->vel.y+(f64)(0.5*random.y);
 n2->pos.z+=n2->vel.z+(f64)(0.5*random.z);
 n2->vel.x+=random.x;
 n2->vel.y+=random.y;
 n2->vel.z+=random.z;
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 f32 s;
 s=__fabs(n6->weight);
 s*=s;
 if(s<0.2f) s=0.2f;
 if(s>0.98f) s=0.98f;
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target2);
 { f32 x,y,z;
 x=s*(target2.x-n6->pos.x);
 y=0.98*(target2.y-n6->pos.y);
 z=s*(target2.z-n6->pos.z);
 n6->pos.x+=x;
 n6->pos.y+=y;
 n6->pos.z+=z; }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z;
 if(d>0.0004f) {
 d=lbl_8006D0B4(0.0004f/d);
 n5->pos.x=target.x+(f32)(dif.x*d);
 n5->pos.y=target.y+(f32)(dif.y*d);
 n5->pos.z=target.z+(f32)(dif.z*d);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=0.95f*(vn->pos.x-vn->prev.x);
 vn->vel.y=0.98f*(vn->pos.y-vn->prev.y);
 vn->vel.z=0.95f*(vn->pos.z-vn->prev.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
/* fzgx:end fn_1_125DF0 */

/* fzgx:begin fn_1_1262A4 */
/* VIEWS */
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

void fn_1_1262A4(ClothObj1262A4 *obj) {
    u32 c0;
    ClothNode1262A4 *e4;
    ClothNode1262A4 *e0;
    ClothNode1262A4 *nodes;
    ClothNode1262A4 *e2;
    ClothNode1262A4 *pc;
    ClothNode1262A4 *front;
    ClothNode1262A4 *back;
    ClothNode1262A4 *src;
    u32 k;
    u32 m;
    ClothNode1262A4 *e;
    ClothNode1262A4 *dst;
    ClothNode1262A4 *e3;
    ClothNode1262A4 * ring_2;
    ClothNode1262A4 sorted[8];
    struct { u32 value; } i;
    u32 ja;
    u32 jb;
    u32 g;
    u32 idx;
    f32 t;
    ClothNode1262A4 *ring;
    ClothNode1262A4 *pb;

    if (obj == NULL) {
        return;
    }
    fn_1_10846C((void *)obj);

    c0 = 0;
    e0 = obj->nodes;
    for (; c0 < obj->nodeCount; c0++, e0++) {
        if (e0->flags & 1) {
            e0->weight = -1.0f;
            e0->flags = 0;
        } else {
            e0->weight = 0.0f;
            e0->flags = 1;
        }
    }

    /* sort by height */
    e0 = obj->nodes;
    for (c0 = 0; c0 < obj->nodeCount; c0++, e0++) {
        pb = &obj->nodes[c0] + 1;
        for (ja = c0 + 1; ja < obj->nodeCount; ja++, pb++) {
            if (e0->height > pb->height) {
                fn_1_128884((void *)e0, (void *)pb, sizeof(ClothNode1262A4));
            }
        }
    }

    /* move the first raised pinned node to the end */
    nodes = obj->nodes;
    e2 = nodes;
    for (i.value = 0; i.value < obj->nodeCount; i.value++, e2++) {
        if (e2->height > 0.05f && (e2->flags & 1)) {
            pb = e2;
            break;
        }
    }
    for (c0 = pb - nodes; c0 < obj->nodeCount - 1; c0++, pb++) {
        fn_1_128884((void *)pb, (void *)(pb + 1), sizeof(ClothNode1262A4));
    }

    /* order each ring of eight */
    ring = obj->nodes;
    for (g = 0; g < obj->nodeCount / 8; g++, ring += 8) {
        for (i.value = 0, pb = ring; i.value < 8; i.value++, pb++) {
            jb = i.value + 1;
            pc = pb + 1;
            for (; jb < 8; jb++, pc++) {
                if (pb->order < pc->order) {
                    fn_1_128884((void *)pb, (void *)pc, sizeof(ClothNode1262A4));
                }
            }
        }
        front = sorted;
        *front = ring[0];
        front++;
        back = sorted;
        back += 7;
        e = ring + 1;
        for (k = 1; k < 8; k++, e++) {
            if (e->side > 0.0f) {
                *front = *e;
                front++;
            } else {
                *back = *e;
                back--;
            }
        }
        t = -(f32)g;
        dst = ring;
        src = sorted;
        for (m = 0; m < 8; m++, dst++, src++) {
            *dst = *src;
            dst->weight = t / (obj->nodeCount / 8 - 1);
        }
    }

    obj->linkCount = 0x40;
    obj->links = fn_1_4630(lbl_801A6410, obj->linkCount * sizeof(ClothLink1262A4), "accessory.c", 0x2DF1);

    idx = 0;
    ring_2 = obj->nodes;
    for (g = 0; g < obj->nodeCount / 8 - 1; g++, ring_2 += 8) {
        e3 = ring_2;
        for (i.value = 0; i.value < 7; i.value++, e3++) {
            obj->links[idx].a = e3;
            obj->links[idx].b = e3 + 1;
            obj->links[idx].len = fn_1_1289BC((Point1024C4 *)e3, (Point1024C4 *)(e3 + 1));
            idx++;
        }
        obj->links[idx].a = &ring_2[7];
        obj->links[idx].b = ring_2;
        obj->links[idx].len = fn_1_1289BC((Point1024C4 *)&ring_2[7], (Point1024C4 *)ring_2);
        idx++;
    }
    ring_2 = obj->nodes;
    for (g = 0; g < obj->nodeCount / 8 - 1; g++, ring_2 += 8) {
        e4 = ring_2;
        for (i.value = 0; i.value < 8; i.value++, e4++) {
            obj->links[idx].a = e4;
            obj->links[idx].b = e4 + 8;
            obj->links[idx].len = fn_1_1289BC((Point1024C4 *)e4, (Point1024C4 *)(e4 + 8));
            idx++;
        }
    }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
/* fzgx:end fn_1_1262A4 */

/* fzgx:begin fn_1_126774 */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

void fn_1_126774(Work_126774 *arg0) {
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 Link *l;
 u8 *model5;
 Node *n3;
 Node *a;
 u32 fj;
 u32 i3;
 Node *fn;
 u16 *lp;
 u32 i5;
 Node *n5;
 u32 li;
 u32 vi;
 Node *vn;
 u32 i2;
 Node *n2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Vec3 deltav;
 Vec3 random;
 Vec3 target2;
 Vec3 diff;
 Vec3 target;
 u32 k2;
 Node *b;
 Vec3 *dp = &deltav;
 Vec3 *qp = &diff;
#define dif (*qp)
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x+(f64)(0.5*random.x);
 n2->pos.y+=n2->vel.y+(f64)(0.5*random.y);
 n2->pos.z+=n2->vel.z+(f64)(0.5*random.z);
 n2->pos.y-=0.0013611111376020642;
 n2->vel.x+=random.x;
 n2->vel.y+=random.y;
 n2->vel.z+=random.z;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k2=0;k2<2;k2++) {
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb,d;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 d=x*x; d+=y*y; d+=z*z; len=d;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 }
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 f32 z,y,x;
 lbl_8006DBAC((void *)((Vec3 *)(model6+136)));
 lbl_8006E1B0((void *)&n6->local,(void *)&target2);
#define SS (1.0-__fabs(n6->weight))
 x=0.35f*(target2.x-n6->pos.x)*SS;
 y=0.35f*(target2.y-n6->pos.y)*SS;
 z=0.35f*(target2.z-n6->pos.z)*SS;
 n6->pos.x+=x;
 n6->pos.y+=y;
 n6->pos.z+=z;
 }
 }
 model5=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i5=0,n5=arg0->nodes;i5<arg0->count;i5++,n5++) {
 f32 x;
 f32 y;
 f32 z;
 f32 d;
 lbl_8006DBAC((void *)((Vec3 *)(model5+136)));
 lbl_8006E1B0((void *)&n5->local,(void *)&target);
 x=n5->pos.x-target.x;
 y=n5->pos.y-target.y;
 z=n5->pos.z-target.z;
 dif.x=x; dif.y=y; dif.z=z;
 d=x*x; d+=y*y; d+=z*z;
 if(d>0.0004f) {
 d=lbl_8006D0B4(0.0004f/d);
 n5->pos.x=target.x+(f32)(dif.x*d);
 n5->pos.y=target.y+(f32)(dif.y*d);
 n5->pos.z=target.z+(f32)(dif.z*d);
 n5->prev=n5->pos;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=vn->pos.x-vn->prev.x;
 vn->vel.y=vn->pos.y-vn->prev.y;
 vn->vel.z=vn->pos.z-vn->prev.z;
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef dif
#undef delta
#undef SS
/* fzgx:end fn_1_126774 */

/* fzgx:begin fn_1_126DE8 */
/* VIEWS */
#define GAME_MAIN_REL_ACCESSORY_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_ACCESSORY_H

#define REL_MAIN_REL_CLOTH_H

#define GAME_MAIN_REL_SHARED_TYPES_H

/* end game/main_rel/accessory_types.h */

/* rel/main_rel/accessory.h: inlined above */

void fn_1_126DE8(Sig_fn_1_10846C_Obj10846C_126DE8 *obj) {
 u32 h[1];
 u32 i,k,j,edgeCount,offset;
 Group *p;
 u32 width;
 Group *q,*row;
 u32 n;
 u32 j2;
 if (!obj) return;
 if (*(s32 *)((u8 *)obj->config+0x88)==27) width=13;
 else if (*(s32 *)((u8 *)obj->config+0x88)==4) width=15;
 else if (*(s32 *)((u8 *)obj->config+0x88)==22) width=11;
 fn_1_10846C((void *)obj);
 for (i=0,p=obj->groups;i<obj->groupCount;i++,p++) {
  if (p->flags&1) { p->flags=0; p->weight=-1.0f; }
  else { p->flags=1; p->weight=0.0f; }
 }
 {
 u32 firstOff[1], firstI[1];
 Group *firstRow[1];
 firstOff[0]=0;
 for(firstI[0]=0,firstRow[0]=obj->groups,firstOff[0]=firstI[0];firstI[0]<obj->groupCount;firstOff[0]+=0x44,firstI[0]++,firstRow[0]++) {
  row=firstRow[0];
  for(j=firstI[0]+1,q=(Group *)((u8 *)obj->groups+firstOff[0]+0x44);j<obj->groupCount;j++,q++)
   if(row->flags==0 && q->flags!=0) fn_1_128884((void *)row,(void *)q,0x44);
 }
 }
 {
 u32 secondOff[1], secondI[1];
 Group *secondRow[1];
 u32 secondJ[1];
 secondOff[0]=0;
 for(secondI[0]=0,secondRow[0]=obj->groups,secondOff[0]=secondI[0];secondI[0]<obj->groupCount;secondOff[0]+=0x44,secondI[0]++,secondRow[0]++) {
  for(secondJ[0]=secondI[0]+1,p=(Group *)((u8 *)obj->groups+secondOff[0]+0x44);secondJ[0]<obj->groupCount;secondJ[0]++,p++)
   if(secondRow[0]->flags==p->flags && secondRow[0]->p10.x<p->p10.x) fn_1_128884((void *)secondRow[0],(void *)p,0x44);
 }
 }
 {
 u32 kk[1];
 Group *bb[1];
 for(kk[0]=0,bb[0]=obj->groups;kk[0]<obj->groupCount/width;kk[0]++,bb[0]+=width) {
  for(i=0,p=bb[0];i<width;i++,p++) {
   Group *zQ;
   for(j2=i+1,zQ=p+1;j2<width;j2++,zQ++)
    if(p->p10.z<zQ->p10.z) fn_1_128884((void *)p,(void *)zQ,0x44);
  }
 }
 }
 {
#define nn (&n)
 u32 yzI[1];
 Group *yzRow[1];
 u32 yzJ[1];
 for(yzI[0]=0,yzRow[0]=obj->groups;yzI[0]<width;yzI[0]++,yzRow[0]++) {
  for(yzJ[0]=yzI[0]+1,p=yzRow[0]+1;yzJ[0]<width;yzJ[0]++,p++) {
   if(yzRow[0]->p10.z>0.0f && p->p10.z>0.0f && yzRow[0]->p10.y>p->p10.y)
    fn_1_128884((void *)yzRow[0],(void *)p,0x44);
   else if(yzRow[0]->p10.z<=0.0f && p->p10.z<=0.0f && yzRow[0]->p10.y<p->p10.y)
    fn_1_128884((void *)yzRow[0],(void *)p,0x44);
  }
 }

 for(i=0,yzRow[0]=obj->groups;i<obj->groupCount;i++,yzRow[0]++)
  if(yzRow[0]->flags!=0 && yzRow[0][1].flags==0) break;
 yzRow[0]++;
 nn[0]=(obj->groupCount-(yzRow[0]-obj->groups))/width;
 for(k=0;k<nn[0];k++,yzRow[0]+=width) {
  for(i=0;i<width;i++) yzRow[0][i].weight=-(f32)(k+1)/(nn[0]+1);
  for(h[0]=0,p=yzRow[0];h[0]<width;h[0]++,p++) {
   for(j=h[0]+1,q=p+1;j<width;j++,q++) {
    if(p->p10.z>0.0f && q->p10.z>0.0f && p->p10.y>q->p10.y)
     fn_1_128884((void *)p,(void *)q,0x44);
    else if(p->p10.z<=0.0f && q->p10.z<=0.0f && p->p10.y<q->p10.y)
     fn_1_128884((void *)p,(void *)q,0x44);
   }
  }
 }
 nn[0]=obj->groupCount/width;
 obj->unk_1C=nn[0]*(width-1)+(nn[0]-1)*width;
 obj->unk_28=(void *)((u32)fn_1_4630(lbl_801A6410,obj->unk_1C*12,"accessory.c",0x2f44));
 edgeCount=0;
 for(i=0,p=obj->groups;i<obj->groupCount-1;i++,p++) {
  if((i+1)%width) {
   ((Edge *)obj->unk_28)[edgeCount].a=p;
   ((Edge *)obj->unk_28)[edgeCount].b=p+1;
   ((Edge *)obj->unk_28)[edgeCount].distance=fn_1_1289BC((void *)((Point1024C4 *)p),(void *)((Point1024C4 *)(p+1)));
   edgeCount++;
  }
 }
 edgeCount*=12;
 for(i=0,p=obj->groups;i<obj->groupCount-width;i++,p++) {
  ((Edge *)((u8 *)obj->unk_28+edgeCount))->a=p;
  ((Edge *)((u8 *)obj->unk_28+edgeCount))->b=p+width;
  ((Edge *)((u8 *)obj->unk_28+edgeCount))->distance=fn_1_1289BC((void *)((Point1024C4 *)p),(void *)((Point1024C4 *)(p+width)));
  edgeCount+=12;
 }
 }
}
#undef GAME_MAIN_REL_ACCESSORY_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef REL_MAIN_REL_CLOTH_H
#undef GAME_MAIN_REL_SHARED_TYPES_H
#undef nn
/* fzgx:end fn_1_126DE8 */

/* fzgx:begin fn_1_12744C */
/* VIEWS */
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

#define REL_MAIN_REL_GLOBALS_H

#define REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

/* end game/main_rel/car_test_types.h */

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */

#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,

// live_camera each carried an identical private copy); Vec3 likewise (car, screen_effect,

// stcoli). Hand-owned (librarian).

#define REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

#define INDEX(i) (lbl_1_data_3FFBC[i])

#define SPHERE(CX, CY, CZ, RADIUS, STRENGTH) { \
 Vec3 diff; \
 Vec3 center; \
 f32 scale; \
 f32 cx,cy,cz; \
 cz=CZ; cy=CY; cx=CX; \
 vec_set_xyz(&center,cx,cy,cz); \
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+532))); \
 lbl_8006E1B0((void *)&center,(void *)&center); \
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) { \
 if(!(kn->flags&1)) { \
 f32 x,z,y,r; \
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z; \
 x-=center.x; y-=center.y; z-=center.z; \
 r=(f32)(x*x)+y*y+z*z; \
 if(r<RADIUS) { \
 scale=STRENGTH*lbl_8006D0E8(r); \
 psvec_sub_scale_add(&kn->pos,&center,scale,&diff,&kn->pos); \
 } \
 } \
 } \
}

#pragma opt_common_subs off

static inline void fn_1_12744C_loop0(Work_12744C *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n1->local,(void *)&n1->pos);
 }
}

void fn_1_12744C(Work_12744C *arg0) {
 u8 *fmodel;
 u32 i3;
 u32 k;
 Link *l;
 Node *kn;
 Node *fn;
 Node *n3;
 Node *a;
 u32 fj;
 u8 *model3;
 u32 ki;
 Node *vn;
 u32 fi;
 u32 li;
 u32 vi;
 u16 *lp;
 Node *b;
 Node *n2;
 u32 i2;
 Vec3 deltav;
 Vec3 random;
 Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 ((s32)fn_80077B14((void *)arg0->obj));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 lbl_8006DAEC();
 fn_1_12744C_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=0.0013611111376020642;
 n2->vel.y-=0.0027222224f;
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((void *)((Vec3 *)(model3+136)));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0((void *)&n3->local,(void *)&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y,z,x,inv,s,wa,wb,r,fa,cz,cy,cx,fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-0.0001f>l->length) {
 inv=lbl_8006D118(len,&len);
 r=lbl_8006D0B4(l->length);
 s=inv*(len-r);
 len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=1.0f/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
 }
 }
 }
 if(arg0->owner->kind==0x1b) {
 SPHERE(0.057f,-0.021f,0.0f,0.010000001f,0.1f)
 SPHERE(0.127f,-0.021f,0.0f,0.010000001f,0.1f)
 } else if(arg0->owner->kind==4) {
 SPHERE(0.057f,-0.02f,0.0f,0.021904001f,0.148f)
 SPHERE(0.127f,-0.02f,0.0f,0.021024998f,0.145f)
 } else if(arg0->owner->kind==0x16) {
 SPHERE(0.057f,-0.008f,0.0f,0.0072250003f,0.085f)
 SPHERE(0.127f,-0.008f,0.0f,0.0057759997f,0.076f)
 SPHERE(2.225f,0.0f,0.0f,4.5967364f,2.144f)
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((void *)((Sig_fn_1_1286F4_Vec3f *)&random));
 vn->vel.x*=0.8; vn->vel.y*=0.8; vn->vel.z*=0.8;
 vn->vel.x+=(f64)(0.2*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(0.2*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(0.2*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(0.5*random.x); vn->vel.y+=(f64)(0.5*random.y); vn->vel.z+=(f64)(0.5*random.z);
 }
 fmodel=(u8 *)((s32)fn_80077B14((void *)arg0->obj));
 lbl_8006DBAC((void *)((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136)));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((void *)((Vec3 *)&fn->pos),(void *)((Vec3 *)(fmodel+(lp[2]<<6))));
 }
 }
 }
}

#pragma opt_common_subs reset
#undef GAME_MAIN_REL_CAR_TEST_TYPES_H
#undef REL_MAIN_REL_GLOBALS_H
#undef REL_MAIN_REL_CAR_TEST_H
#undef GAME_VEC3_H
#undef REL_MAIN_REL_ACCESSORY_H
#undef INDEX
#undef SPHERE
#undef delta
/* fzgx:end fn_1_12744C */

/* fzgx:begin fn_1_127FB8 */
/* VIEWS */
#define lbl_1_bss_88B40 (*(Vec3 *)&lbl_1_bss_88B40)
void fn_1_127FB8(Fn127FB8Object *obj) {
    f32 value;
    u32 i;
    Fn127FB8Entry *entry;

    if (obj != 0) {
        fn_1_10846C((void *)obj);
        entry = obj->entries;
        value = 0.0f;
        i = 0;
        while (i < obj->count) {
            if ((entry->active & 1) != 0) {
                entry->active = 0;
                entry->value = value;
            } else {
                entry->active = 1;
                entry->value = value;
            }
            i++;
            entry++;
        }
    }
}
/* fzgx:end fn_1_127FB8 */

/* fzgx:begin fn_1_128038 */
void fn_1_128038(fn_1_128038_AccessoryObject *self) {
    u8 mtx[0x30];

    if (self != 0 && self->unk_10 != 0) {
        u8 *model;
        s32 type;

        fn_80077B14(self->unk_10);
        if (self->unk_0 & 2) {
            u8 *item;
            u32 i;
            fn_1_128038_AccessoryData *owner;

            self->unk_0 &= ~2;
            owner = self->unk_C;
            lbl_8006DBAC(owner->unk_150->unk_8 + lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
            lbl_8006DAEC();
            item = self->unk_24;
            i = 0;
            while (i < self->unk_18) {
                lbl_8006DBE4();
                lbl_8006E1B0(item + 0x28, item + 0x10);
                i++;
                item += 0x44;
            }
            lbl_8006DC20();
        }

        model = self->unk_C->unk_150->unk_8 + lbl_1_data_3FFBC[self->unk_8] * 0x18c;
        type = self->unk_C->unk_88;
        if (type == 0x18) {
            if (strcmp((void *)(fn_1_950E8(self->unk_C->unk_148)), "WIN_4TH") == 0) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x4000);
                lbl_8006DB74(mtx);
            } else {
                lbl_8006D758();
                lbl_8006DB74(mtx);
            }
        } else if (type == 6) {
            if (strcmp((void *)(fn_1_950E8(self->unk_C->unk_148)), "WIN_1ST") == 0 &&
                lbl_1_bss_960 != 14) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x4000);
                lbl_8006DB74(mtx);
            } else if (strcmp((void *)(fn_1_950E8(self->unk_C->unk_148)), "WIN_3RD") == 0) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x2000);
                lbl_8006DB74(mtx);
            } else {
                lbl_8006D758();
                lbl_8006DB74(mtx);
            }
        } else if (type == 1) {
            lbl_8006D758();
            lbl_8006DB74(mtx);
        }

        {
            u8 *item;
            u32 i;

            item = self->unk_24;
            i = 0;
            while (i < self->unk_18) {
                lbl_8006DBAC(model + 0x88);
                lbl_8006DFC4(mtx);
                lbl_8006E1B0(item + 0x28, item + 0x10);
                i++;
                item += 0x44;
            }
        }

        type = self->unk_C->unk_88;
        if (type == 0x18) {
            fn_1_108EEC((void *)self, 1, 12, 0.082f, 0.097f, -0.023f, 0.034f);
            if (strcmp((void *)(fn_1_950E8(self->unk_C->unk_148)), "WIN_4TH") != 0 &&
                strcmp((void *)(fn_1_950E8(self->unk_C->unk_148)), "SEL_DEC") != 0) {
                fn_1_108EEC((void *)self, 12, 12, 0.06f, 0.025f, 0.002f, -0.004f);
                fn_1_108EEC((void *)self, 12, 12, 0.055f, 0.067f, 0.001f, -0.007f);
                fn_1_108EEC((void *)self, 12, 12, 0.05f, 0.103f, 0.005f, -0.013f);
                fn_1_108EEC((void *)self, 13, 12, 0.041f, 0.0f, 0.001f, -0.014f);
                fn_1_108EEC((void *)self, 13, 12, 0.041f, 0.048f, 0.003f, -0.012f);
                fn_1_108EEC((void *)self, 13, 12, 0.034f, 0.096f, 0.003f, -0.012f);
            }
        } else if (type == 6) {
            fn_1_108EEC((void *)self, 1, 12, 0.082f, 0.097f, -0.023f, 0.034f);
            if (strcmp((void *)(fn_1_950E8(self->unk_C->unk_148)), "WIN_1ST") != 0) {
                fn_1_108EEC((void *)self, 12, 12, 0.06f, 0.025f, 0.002f, -0.004f);
                fn_1_108EEC((void *)self, 12, 12, 0.055f, 0.067f, 0.001f, -0.007f);
                fn_1_108EEC((void *)self, 12, 12, 0.05f, 0.103f, 0.005f, -0.013f);
                fn_1_108EEC((void *)self, 13, 12, 0.041f, 0.0f, 0.001f, -0.014f);
                fn_1_108EEC((void *)self, 13, 12, 0.041f, 0.048f, 0.003f, -0.012f);
                fn_1_108EEC((void *)self, 13, 12, 0.034f, 0.096f, 0.003f, -0.012f);
            }
        } else if (type == 1) {
            if (lbl_1_data_3FFBC[self->unk_8] == 11) {
                fn_1_108EEC((void *)self, 1, 12, 0.062f, 0.097f, -0.023f, 0.034f);
                fn_1_108EEC((void *)self, 12, 12, 0.04f, 0.025f, 0.002f, -0.004f);
                fn_1_108EEC((void *)self, 12, 12, 0.035f, 0.067f, 0.001f, -0.007f);
                fn_1_108EEC((void *)self, 12, 12, 0.03f, 0.103f, 0.005f, -0.013f);
                fn_1_108EEC((void *)self, 13, 12, 0.021f, 0.0f, 0.001f, -0.014f);
                fn_1_108EEC((void *)self, 13, 12, 0.021f, 0.048f, 0.003f, -0.012f);
                fn_1_108EEC((void *)self, 13, 12, 0.014f, 0.096f, 0.003f, -0.012f);
            } else {
                fn_1_108EEC((void *)self, 1, 7, 0.062f, 0.097f, -0.023f, 0.034f);
                fn_1_108EEC((void *)self, 7, 7, 0.04f, 0.025f, 0.002f, -0.004f);
                fn_1_108EEC((void *)self, 7, 7, 0.035f, 0.067f, 0.001f, -0.007f);
                fn_1_108EEC((void *)self, 7, 7, 0.03f, 0.103f, 0.005f, -0.013f);
                fn_1_108EEC((void *)self, 13, 7, 0.021f, 0.0f, 0.001f, -0.014f);
                fn_1_108EEC((void *)self, 13, 7, 0.021f, 0.048f, 0.003f, -0.012f);
                fn_1_108EEC((void *)self, 13, 7, 0.014f, 0.096f, 0.003f, -0.012f);
            }
        }

        {
            u8 *base;
            u8 *p;
            u8 *entry;
            int m;
            u32 n;
            fn_1_128038_AccessoryData *owner;

            base = fn_80077B14(self->unk_10);
            owner = self->unk_C;
            lbl_8006DBAC(owner->unk_150->unk_8 + lbl_1_data_3FFBC[self->unk_8] * 0x18c + 0x88);
            entry = self->unk_24;
            n = 0;
            while (n < self->unk_18) {
                p = entry;
                for (m = 0; m < entry[2]; m++) {
                    fn_8006E250(entry + 0x10, base + *(u16 *)(p + 4) * 0x40);
                    p += 2;
                }
                n++;
                entry += 0x44;
            }
        }
    }
}
/* fzgx:end fn_1_128038 */

/* fzgx:begin fn_1_1286F4 */
void fn_1_1286F4(Vec3 *out) {
    if ((lbl_801A66A0 & 0xF) == 0) {
        u32 c;
        u32 b;
        u32 a;
        f32 fx;
        f32 fy;
        f32 fz;
        f32 len;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        a = lbl_801A63C0;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        b = lbl_801A63C0;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        c = lbl_801A63C0;
        fx = -0.00019999999494757503f + (f32)(0.00039999998989515007f * ((s32)((a >> 16) & 0x7FFF) / 32767.0f));
        lbl_1_bss_88B40.x = fx;
        fy = -9.999999747378752e-05f + (f32)(0.00019999999494757503f * ((s32)((b >> 16) & 0x7FFF) / 32767.0f));
        lbl_1_bss_88B40.y = fy;
        fz = -0.00019999999494757503f + (f32)(0.00039999998989515007f * ((s32)((c >> 16) & 0x7FFF) / 32767.0f));
        lbl_1_bss_88B40.z = fz;
        len = (f32)(fx * fx) + fy * fy + fz * fz;
        if (len > 1.6000001778593287e-05f) {
            f32 s = 0.004000000189989805f / lbl_8006D0B4(len);
            lbl_1_bss_88B40.x *= s;
            lbl_1_bss_88B40.y *= s;
            lbl_1_bss_88B40.z *= s;
        }
    }
    *out = lbl_1_bss_88B40;
}
#undef lbl_1_bss_88B40
/* fzgx:end fn_1_1286F4 */

/* fzgx:begin fn_1_128884 */
/* VIEWS */
#define lbl_801A6410 (*(void * *)&lbl_801A6410)
void fn_1_128884(void *arg0, void *arg1, int type) {
    u8 tmp1[0x44];
    u8 tmp2[0x0c];
    void *object;

    switch (type) {
    case 0x44: {
        u32 size = type;
        fn_80008BA8(tmp1, arg0, size);
        fn_80008BA8(arg0, arg1, size);
        fn_80008BA8(arg1, tmp1, size);
        break;
    }
    case 0x0c: {
        u32 size = type;
        fn_80008BA8(tmp2, arg0, size);
        fn_80008BA8(arg0, arg1, size);
        fn_80008BA8(arg1, tmp2, size);
        break;
    }
    default:
        object = fn_1_45D0(lbl_801A6410, type, "accessory.c", 0x308d);
        fn_80008BA8(object, arg0, type);
        fn_80008BA8(arg0, arg1, type);
        fn_80008BA8(arg1, object, type);
        fn_1_46B4((u32)lbl_801A6410, (u32)object, (void *)"accessory.c", 0x3091);
        break;
    }
}
/* fzgx:end fn_1_128884 */

/* fzgx:begin fn_1_1289BC */
f32 fn_1_1289BC(const Point1024C4 *a, const Point1024C4 *b) {
    f32 dz = a->v[2] - b->v[2];
    f32 dy = a->v[1] - b->v[1];
    f32 dx = a->v[0] - b->v[0];
    f32 result = dx * dx;
    result += dy * dy;
    result += dz * dz;
    return result;
}
/* fzgx:end fn_1_1289BC */

/* fzgx:begin fn_1_1289F0 */
#pragma opt_common_subs off

f32 fn_1_1289F0(Vec3 *a, Vec3 *b, Vec3 *c) {
    Vec3 ac;
    Vec3 ab;
    f32 cosine;
    f32 length;
    psvec_sub(c, a, &ac);
    psvec_sub(b, a, &ab);
    ab.x = lbl_8006D6FC(&ac, &ab);
    cosine = ac.x * ac.x;
    cosine = ac.y * ac.y + cosine;
    cosine = ac.z * ac.z + cosine;
    length = lbl_8006D0B4(cosine);
    return length * lbl_8006D0B4(1.0f - (f32)(ab.x * ab.x));
}
/* fzgx:end fn_1_1289F0 */

/* fzgx:begin fn_1_128AAC */
#pragma opt_common_subs reset

f32 fn_1_128AAC(s32 exponent, f32 value) {
    s32 sign;
    s32 n;
    f32 result = 1.0f;

    sign = exponent >> 31;
    n = sign ^ exponent;
    n -= sign;
    while (n != 0) {
        if (n & 1) {
            result *= value;
        }
        value *= value;
        n >>= 1;
    }
    if (exponent >= 0) {
        return result;
    }
    return 1.0f / result;
}
/* fzgx:end fn_1_128AAC */

/* fzgx:begin fn_1_128B00 */
s32 fn_1_128B00(s16 value) {
    switch (value) {
    case 0:
        return 7;
    case 1:
        return 10;
    case 2:
        return 4;
    default:
        return fn_1_14D670();
    }
}
/* fzgx:end fn_1_128B00 */

/* fzgx:begin fn_1_128B60 */
static inline s32 next_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33cb;
    return (lbl_801A63C0 >> 16) & 0x7fff;
}

void fn_1_128B60(u8 *a0, u8 *a1, u8 *a2, u8 *a3, u8 *a4, u8 *a5, u8 *a6, u8 *a7, u8 *a8, u8 *a9) {
    *a0 = next_rand() % 10;
    *a1 = (*a0 + 1) % 10;
    *a2 = (*a0 + 2) % 10;
    *a3 = next_rand() % 10;
    *a4 = (*a3 + 1) % 10;
    *a5 = (*a3 + 2) % 10;
    *a6 = next_rand() % 10;
    *a7 = (*a6 + 1) % 10;
    *a8 = (*a6 + 2) % 10;
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33cb;
    if ((lbl_801A63C0 >> 16) & 1) {
        *a2 = 15;
    }
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33cb;
    if ((lbl_801A63C0 >> 16) & 1) {
        *a5 = 15;
    }
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33cb;
    if ((lbl_801A63C0 >> 16) & 1) {
        *a8 = 15;
    }
    *a9 = next_rand() % 20;
}
#undef lbl_801A6410
/* fzgx:end fn_1_128B60 */

/* fzgx:begin fn_1_128DD8 */
/* .data 405C0: the six values fn_1_128DD8 looks up */
static u8 lbl_1_data_405C0[6] = {0x24, 0x1F, 0x20, 0x21, 0x22, 0x23};

// Return the table index for a matching accessory value, or the first unused index.

u8 fn_1_128DD8(u8 value) {
    u8 *table;
    u8 index;
    u8 entry;

    table = lbl_1_data_405C0;
    for (index = 0; index < 6; index++) {
        entry = table[index];
        if (entry == value) {
            return index;
        }
    }

    return index;
}
/* fzgx:end fn_1_128DD8 */

/* fzgx:begin fn_1_128E10 */
u8 fn_1_128E10(u8 value) {
    u8 table[15] = {0x31, 0x06, 0x02, 0x05, 0x04, 0x28, 0x24, 0x27, 0x20, 0x23, 0x21, 0x25, 0x22, 0x26, 0x1F};
    u8 i;
    u8 entry;

    i = 1;
    while (i < 15) {
        entry = table[i];
        if (entry == (value & 0xFF)) {
            break;
        }
        i++;
    }
    if (i == 15) {
        i = 0;
    }
    return i;
}
/* fzgx:end fn_1_128E10 */

/* fzgx:begin fn_1_128E8C */
void fn_1_128E8C(u32 unused, FnData *data) {
    data->field_0 = 1;
    data->field_1 = 2;
    data->field_2 = 3;
    data->field_4 = 0;
    data->field_8 = lbl_801A66A0 % 255;
    data->field_9 = 1;
    data->field_f = 2;
    data->field_a = 1234;
    data->field_11 = 5;
    data->field_12 = 6;
    data->field_14 = 7;
    data->field_10 = 4;
    data->field_18 = 982;
}
/* fzgx:end fn_1_128E8C */
