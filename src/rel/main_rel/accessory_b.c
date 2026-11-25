#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"
#include "rel/main_rel/game.h"
#include "rel/main_rel/archive.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "game/vec3.h"
#include "psvec.h"
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
extern u32 lbl_1_bss_88B40[3];
extern u32 lbl_1_bss_88B4C;
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
extern const char *lbl_1_data_3FCAC[];
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
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
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
void fn_1_108EEC(fn_1_108EEC_Arg *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);
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

/* TU B (128DD8..12A290) objects */
extern const f32 lbl_1_rodata_8068;
u32 lbl_1_bss_89760[4];
f32 lbl_1_bss_89770[4];
u8 lbl_1_bss_89780[32];

/* fzgx:begin fn_1_128F10 */
void fn_1_128F10(void) {
    lbl_1_bss_89760[0] = 0;
    lbl_1_bss_89770[0] = 0.0f;
    lbl_1_bss_89760[1] = 0;
    lbl_1_bss_89770[1] = 0.0f;
    lbl_1_bss_89760[2] = 0;
    lbl_1_bss_89770[2] = 0.0f;
    lbl_1_bss_89760[3] = 0;
    lbl_1_bss_89770[3] = 0.0f;
    lbl_1_bss_89780[0] = 0;
}
/* fzgx:end fn_1_128F10 */

/* fzgx:begin fn_1_128F54 */
void fn_1_128F54(void) {
    u32 inner_count;
    u32 outer_count;
    struct { s16 value; } item;
    u32 i;
    u32 j;
    int found;
    f32 limit;
    u32 spell_call;

{
    u32 fzgx_loop_inner_count_553;
    u32 fzgx_loop_outer_count_553;
    spell_call = fn_1_86624();

    fzgx_loop_inner_count_553 = spell_call;
    fzgx_loop_outer_count_553 = fn_1_58C4();
    i = 0;
    while (i < fzgx_loop_outer_count_553) {
        item.value = fn_1_6B48(i);
        if (item.value == 0xFFFFFFFF) {
            ((f32 *)&lbl_1_bss_89770)[i] = 0.0f;
            ((u32 *)&lbl_1_bss_89760)[i] = 0;
        } else {
{
    int fzgx_loop_found_1003;
    f32 fzgx_loop_limit_1003;
            fzgx_loop_found_1003 = 0;
            fzgx_loop_limit_1003 = -4.8f;
            j = 0;
            while (j < fzgx_loop_inner_count_553) {
                if (item.value != j) {
                    f32 value = fn_1_8CAF4(item.value, j);
                    if (!(value > fzgx_loop_limit_1003)) {
                        if (!fzgx_loop_found_1003) {
                            ((f32 *)&lbl_1_bss_89770)[i] = value;
                            fzgx_loop_found_1003 = 1;
                            ((u32 *)&lbl_1_bss_89760)[i] = j;
                        }
                        if (value > ((f32 *)&lbl_1_bss_89770)[i]) {
                            ((u32 *)&lbl_1_bss_89760)[i] = j;
                            ((f32 *)&lbl_1_bss_89770)[i] = value;
                        }
                    }
                }
                j++;
            }
    found = fzgx_loop_found_1003;
    limit = fzgx_loop_limit_1003;
}
            if (!found) {
                ((u32 *)&lbl_1_bss_89760)[i] = 0;
                ((f32 *)&lbl_1_bss_89770)[i] = 0.0f;
            }
        }
        i++;
    }
    inner_count = fzgx_loop_inner_count_553;
    outer_count = fzgx_loop_outer_count_553;
}
}
/* fzgx:end fn_1_128F54 */

/* fzgx:begin fn_1_12907C */
/* VIEWS */
#define lbl_1_bss_9C (*(s8 (*)[8])&lbl_1_bss_9C)
/* Translate the locked-cache matrix along its y column: m[i][3] += m[i][1] * y. */

static inline void mtxA_translate_y(f32 y) {
    f32 *mtx = (f32 *)0xE0000000;  /* fzgx-allow: A2 locked matrix */
    f32 s = y;
    f32 x0, x1, y0, y1, z0, z1;
    x0 = mtx[1];
    x1 = mtx[3];
    y0 = mtx[5];
    y1 = mtx[7];
    z0 = mtx[9];
    z1 = mtx[11];
    x0 = x0 * s + x1;
    y0 = y0 * s + y1;
    z0 = z0 * s + z1;
    mtx[3] = x0;
    mtx[7] = y0;
    mtx[11] = z0;
}

#pragma opt_propagation off

#pragma opt_lifetimes off

#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

/* base + x * rate, kept unfused. */

static inline f32 remap(f32 x, f32 base, f32 rate) {
    return base + (f32)(x * rate);
}

void fn_1_12907C(void) {
    s32 player;
    f32 dist;
    u32 target;
    s16 id;
    s16 angle;
    s32 count;
    f32 dh;
    f32 height;
    s16 tilt;
    f32 scale;
    f32 h;
    f32 dummy;
    f32 aspect;
    Vec3 pos;
    Vec3 v;
    f32 inv;
    f32 y;
    f32 x;
    f32 sx;
    f32 sy;
    f32 m;
    f32 size;
    f32 fov;
    FontDrawPacket packet;
    s8 mode;

    player = fn_1_5910();
    dist = ((f32 *)&lbl_1_bss_89770)[player];
    target = ((u32 *)&lbl_1_bss_89760)[player];
    id = fn_1_6B48(player);
    if (fn_1_6EC0(player) == 0) {
        return;
    }
    fn_1_12999C();
    if (dist < -100.0f) {
        return;
    }
    if (0.0f == dist) {
        return;
    }
    if (fn_1_864E8(id) & 0x10880) {
        return;
    }
    if (fn_1_864E8(target) & 0x8000880) {
        return;
    }
    count = fn_1_3F7E0();
    if ((u8)fn_1_86810(id) + 1 >= count) {
        return;
    }
    height = fn_1_8627C(target)->height;
    {
        Car_12907C *car = fn_1_8627C(id);
        dh = height - car->height;
        tilt = car->angle;
    }
    scale = 1.0f;
    if (dh > 40.0f) {
        return;
    }
    if (dh < -40.0f) {
        return;
    }
    if (tilt > 0x3000) {
        return;
    }
    if (tilt < -0x3000) {
        return;
    }
    fn_1_A714C(&dummy, &h, &dummy, &dummy);
    fov = fn_1_A71BC();
    aspect = 1.0f / h;
    fn_1_862D4(target, &pos);
    lbl_8006D9D8(&pos);
    lbl_8006D7B0();
    mtxA_translate_y(0.2f);
    psvec_set(&v, ((f32 *)0xE0000000)[11], ((f32 *)0xE0000000)[7], ((f32 *)0xE0000000)[3]);  /* fzgx-allow: A2 locked matrix */
    if (v.z > -1.0f) {
        v.z = -1.0f;
    }
    inv = -1.0f / v.z;
    sx = aspect * (inv * (v.x * fov));
    sy = inv * (v.y * fov);
    mode = camera_get_state();
    y = 445.0f;
    switch (mode) {
    case 0:
        x = 320.0f + (f32)(20.0f * sx);
        if (x < 15.0f) {
            x = 15.0f;
        } else if (x > 625.0f) {
            x = 625.0f;
        }
        break;
    case 1:
        switch (player) {
        case 0:
            {
                f32 t = 320.0f + (f32)(90.0f * sx);
                x = (t < 15.0f) ? 15.0f : ((t > 625.0f) ? 625.0f : t);
            }
            y = 225.0f;
            break;
        case 1:
            {
                f32 t = 320.0f + (f32)(90.0f * sx);
                x = (t < 15.0f) ? 15.0f : ((t > 625.0f) ? 625.0f : t);
            }
            break;
        }
        break;
    case 2:
        x = 10.0f * sx;
        switch (player) {
        case 0:
            x += 160.0f;
            if (x < 18.0f) {
                x = 18.0f;
            } else if (x > 302.0f) {
                x = 302.0f;
            }
            break;
        case 1:
            x += 480.0f;
            if (x < 338.0f) {
                x = 338.0f;
            } else if (x > 622.0f) {
                x = 622.0f;
            }
            break;
        }
        break;
    case 3:
        switch (player) {
        case 0:
            {
                f32 t = 320.0f + (f32)(20.0f * sx);
                x = (t < 15.0f) ? 15.0f : ((t > 625.0f) ? 625.0f : t);
            }
            y = 225.0f;
            break;
        case 1:
            {
                f32 t = 160.0f + (f32)(10.0f * sx);
                x = (t < 10.0f) ? 10.0f : ((t > 310.0f) ? 310.0f : t);
            }
            scale = 0.5f;
            break;
        case 2:
            {
                f32 t = 480.0f + (f32)(10.0f * sx);
                x = (t < 330.0f) ? 330.0f : ((t > 630.0f) ? 630.0f : t);
            }
            scale = 0.5f;
            break;
        }
        break;
    case 4:
        switch (player) {
        case 1:
            {
                f32 t = 320.0f + (f32)(20.0f * sx);
                x = (t < 15.0f) ? 15.0f : ((t > 625.0f) ? 625.0f : t);
            }
            y = 225.0f;
            break;
        case 0:
            {
                f32 t = 160.0f + (f32)(10.0f * sx);
                x = (t < 10.0f) ? 10.0f : ((t > 310.0f) ? 310.0f : t);
            }
            scale = 0.5f;
            break;
        case 2:
            {
                f32 t = 480.0f + (f32)(10.0f * sx);
                x = (t < 330.0f) ? 330.0f : ((t > 630.0f) ? 630.0f : t);
            }
            scale = 0.5f;
            break;
        }
        break;
    case 5:
        switch (player) {
        case 2:
            {
                f32 t = 320.0f + (f32)(20.0f * sx);
                x = (t < 15.0f) ? 15.0f : ((t > 625.0f) ? 625.0f : t);
            }
            y = 225.0f;
            break;
        case 0:
            {
                f32 t = 160.0f + (f32)(10.0f * sx);
                x = (t < 10.0f) ? 10.0f : ((t > 310.0f) ? 310.0f : t);
            }
            scale = 0.5f;
            break;
        case 1:
            {
                f32 t = 480.0f + (f32)(10.0f * sx);
                x = (t < 330.0f) ? 330.0f : ((t > 630.0f) ? 630.0f : t);
            }
            scale = 0.5f;
            break;
        }
        break;
    case 6:
    case 8:
        x = 20.0f * sx;
        scale = 0.5f;
        switch (player) {
        case 0:
            x += 160.0f;
            if (x < 10.0f) {
                x = 10.0f;
            } else if (x > 310.0f) {
                x = 310.0f;
            }
            y = 225.0f;
            break;
        case 1:
            x += 480.0f;
            if (x < 330.0f) {
                x = 330.0f;
            } else if (x > 630.0f) {
                x = 630.0f;
            }
            y = 225.0f;
            break;
        case 2:
            x += 160.0f;
            if (x < 10.0f) {
                x = 10.0f;
            } else if (x > 310.0f) {
                x = 310.0f;
            }
            break;
        case 3:
            x += 480.0f;
            if (x < 330.0f) {
                x = 330.0f;
            } else if (x > 630.0f) {
                x = 630.0f;
            }
            break;
        }
        break;
    }
    m = (__fabs(sx) > __fabs(sy)) ? __fabs(sx) : __fabs(sy);
    if (m > 0.8f) {
        f32 k = 0.8f / m;
        v.x *= k;
        v.y *= k;
        angle = lbl_8006D24C(v.y - (f32)(0.2f * k), v.x) + 0x4000;
    } else {
        angle = lbl_8006D24C(v.y - (f32)(0.2f * m), v.x) + 0x4000;
    }
    packet = lbl_1_rodata_26F8;
    if (fn_1_485A8(0x94)) {
        packet.image = 0x944F;
    } else if (fn_1_485A8(0x97)) {
        packet.image = 0x9732;
    }
    if ((s32)packet.image != 0) {
        static const Color_12907C color = {0xFF, 0x88, 0x33, 0x88};
        size = CLAMP(remap(-dist, 1.0504202f, -0.010504202f), 0.5f, 1.0f);
        size *= scale;
        packet.x = x;
        packet.y = y;
        packet.z = 1.0f;
        packet.rotation_z = angle / 2;
        packet.scale_x *= size;
        packet.scale_y *= size;
        *(Color_12907C *)packet.color = color;
        packet.flags = 10;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_12907C */

/* fzgx:begin fn_1_12999C */
#pragma opt_lifetimes reset

#pragma opt_propagation reset

void fn_1_12999C(void) {
 s32 i;
 u32 t3C[3] = {1, 2, 5};
 u32 t2C[4] = {0, 3, 4, 6};
 static const char staff_ghost[] = "Staff\nGhost";
 struct Vec3 v20;
 struct Vec3 v14;
 struct Vec3 v8;
 u8 o48[0x18];
 u8 buf[5296];
 u8 *sub;
 s32 n;
 s32 mode = 1;
 struct Obj_t *o;
 f32 val;
 s32 idx;
 u8 self;
 u32 j;
 u8 *q;
 if (*(s16 *)&lbl_1_bss_960 != 2 && *(s16 *)&lbl_1_bss_960 != 9) return;
 if (fn_1_3F0C8() != 41) {
 switch (fn_1_3F0C8()) {
 case 40: break;
 /* Unsupported machine: branch to the shared function exit. */
 default: goto end;
 }
 }
 {
 if (fn_1_F2F34() != 0) return;
 fn_1_3EF14(buf);
 val=fn_1_A71AC();
 n=fn_1_40B20();
 if (*(s16 *)&lbl_1_bss_960 == 9) mode=lbl_1_bss_9C[7];
 for(i=0;i<buf[9];i++) {
 o=(struct Obj_t *)fn_1_86254(i);
 if(o->unk_0 & 0x8000880) continue;
 sub=(u8 *)o->unk_49C;
 if(o->unk_475 != -1 && fn_1_5910() == o->unk_475) continue;
 idx=fn_1_12A24C(i);
 self=(i==n);
 if(mode==0 || sub[0x115]>=3) {
 if(idx==-1 && !self) continue;
 }
 if(o->unk_0 & 0x10000) continue;
 fn_1_862A8(i,&v20);
 if(idx!=-1) {
 if(((0)[lbl_1_bss_89780]) != 0) {
 if(fn_1_D66BC((void *)(u8)idx,o48)!=0) {
 fn_1_129D9C((void *)o->unk_14C,(void *)&v20,(void *)o48,(void *)0,0,self,0,val);
 continue;
 }
 }
 fn_1_129D9C((void *)o->unk_14C,(void *)&v20,(void *)0,(void *)(*(void **)(lbl_1_bss_38458->unk_8+t2C[idx]*8)),0,self,0,val);
 continue;
 }
 if(mode!=0) {
 u8 lvl=sub[0x115];
 if(lvl<3) {
 fn_1_129D9C((void *)o->unk_14C,(void *)&v20,(void *)0,(void *)(*(void **)(lbl_1_bss_38458->unk_8+t3C[lvl]*8)),0,self,0,val);
 continue;
 }
 }
 if(!self) continue;
 fn_1_129D9C((void *)o->unk_14C,(void *)&v20,(void *)0,(void *)0,0,self,0,val);
 }
 if(fn_1_F1D60()!=0) {
 if(*(s16 *)&lbl_1_bss_960==9 && lbl_1_bss_9C[6]==-2) {
 v14.x=0.0f; v14.y=1.0f; v14.z=0.0f;
 fn_1_129D9C((void *)lbl_1_bss_7CA58,(void *)&v14,(void *)0,(void *)0,1,1,0,val);
 return;
 }
 }
 if(fn_1_F1D60()!=0) {
 v8.x=0.0f; v8.y=1.0f; v8.z=0.0f;
 if(fn_1_4C10()==0) {
 for(j=0;j<fn_1_EB0B0();j++) {
 q=fn_1_F1C54(j);
 if(lbl_801A66B4!=5 && strstr((char *)q,"\x8A\x4A\x94\xAD\x8E\xD2")!=0) q=(u8 *)staff_ghost;
 fn_1_129D9C((void *)&lbl_1_bss_7CA58[j],(void *)&v8,(void *)q,(void *)0,1,0,0,val);
 }
 }
 }
 }
end:
 return;
}
/* fzgx:end fn_1_12999C */

/* fzgx:begin fn_1_129D9C */
#pragma opt_common_subs off

void fn_1_129D9C(void *arg0, struct Vec3 *arg1, u8 *arg2, void *arg4,
                 u8 arg5, u8 arg6, u8 arg7, f32 arg3) {
    f32 v1;
    f32 v2;
    f32 d;

    if (arg2 != 0) {
        v1 = 0.25f;
    } else {
        v1 = 2.0f;
    }
    if (arg7) {
        v1 = 0.25f;
    }
    v2 = 2.0f * v1;
    if (!arg5) {
        lbl_8006DCA4();
        lbl_8006E1C0(arg1, arg1);
        lbl_8006DFC4(arg0);
    } else {
        lbl_8006DBAC(arg0);
    }
    lbl_8006D7B0();
    if (__fabsf(arg1->x) > 0.00009999999747378752 ||
        __fabsf(arg1->y) > 0.00009999999747378752) {
        arg1->z = 0.0f;
        lbl_8006D668(arg1);
        mathutil_mtxA_rotate_z__fzgx_offset_C(-arg1->x, arg1->y);
    }
    lbl_8006E0B4(0.0f, 1.5f, 0.0f);
    lbl_8006E14C(v1);
    d = -lbl_801A6D00->unk_2C;
    d *= arg3;
    {
        f32 q = 240.0f / d;
        if ((q * v2) < 32.0f) {
            v2 = d * (32.0f / v2 / 240.0f);
        } else if ((q * v2) > 128.0f) {
            v2 = d * (128.0f / v2 / 240.0f);
        } else {
            v2 = 1.0f;
        }
    }
    lbl_8006E14C(v2);
    if (arg7) {
        lbl_8006E0B4(0.0f, -4.0f, 0.0f);
    }
    lbl_8006E0B4(0.0f, 1.0f, 0.0f);
    fn_80072558();
    fn_1_55210((void *)((struct fn_1_129D9C_chain *)lbl_1_bss_38458->unk_8)->unk_38);
    if (arg6) {
        lbl_8006E0B4(0.0f, 1.0f, 0.0f);
        lbl_8006D7B0();
        lbl_8006E14C(v1);
        lbl_8006E14C(v2);
        fn_80072558();
        fn_1_55210((void *)((struct fn_1_129D9C_chain *)lbl_1_bss_38458->unk_8)->unk_48);
        lbl_8006E0B4(0.0f, 0.4f, 0.0f);
        if (arg4 == 0) {
            return;
        }
    }
    lbl_8006E0B4(0.0f, 1.0f, 0.0f);
    lbl_8006D7B0();
    lbl_8006E14C(v1);
    lbl_8006E14C(v2);
    if (arg2 != 0) {
        arg2[0x10] = 0;
        arg4 = fn_1_548AC(0x50);
        if (arg4 != 0) {
{
    u32 loc_8[3] = {0, 0, 0};
            lbl_8006DB74((u8 *)arg4 + 8);
            *(f32 *)((u8 *)arg4 + 56) = 1.0f / v2;
            *(void **)((u8 *)arg4 + 4) = (void *)fn_1_12A0E0;
            strcpy((u8 *)arg4 + 60, arg2);
            fn_1_5489C(fn_1_5448C(loc_8), arg4);
}
        }
    } else {
        fn_80072558();
        fn_1_55210(arg4);
    }
}
/* fzgx:end fn_1_129D9C */

/* fzgx:begin fn_1_12A080 */
#pragma opt_common_subs reset

#pragma opt_propagation off

#pragma opt_common_subs off

void fn_1_12A080(void) {
    f32 fzgx_live;
    Sig_fn_80015EE8_Fn80015EE8Out out;

    fzgx_live = 480.0f;
    C_MTXOrtho(&out, 0.0f, fzgx_live, 0.0f, 640.0f, 0.1f, 90000.0f);
    fn_800737E4(&out, 1);
    fn_80074918(1, 3, 1);
}
/* fzgx:end fn_1_12A080 */

/* fzgx:begin fn_1_12A0E0 */
#pragma opt_common_subs reset

#pragma opt_propagation reset

#pragma opt_propagation off

#pragma opt_common_subs off

void fn_1_12A0E0(DisplayData *arg0)
{
    f32 fzgx_live;
    f32 z;
    f32 scale;
    f32 x;
    f32 y;
    f32 depth;
    f32 size;
    Sig_fn_8006F78C_Fn8006F78CData_12907C vec;
    fn_1_520A0();
    fn_1_52070(0x140);
    scale = fn_1_A71AC();
    lbl_8006DBAC(arg0->unk_08);
    fn_1_49410();
    fn_1_494DC(5);
    if (strcmp((void *)arg0->unk_3C, (void *)("STAFF")) == 0) {
        u8 color[4] = {0xFF, 0xFF, 0x10, 0xFF};
        fn_1_49514((void *)color);
    }
    z = *(f32 *)(LC_BASE + 0x2C);
    x = *(f32 *)(LC_BASE + 0xC);
    y = *(f32 *)(LC_BASE + 0x1C);
    depth = -90000.1 - 9000.0 / z;
    psvec_set(&vec, z, y, x);
    fn_1_4954C(-depth);
    fn_8006F78C(&vec, (void *)&vec, scale);
    fzgx_live = vec.value0;
    fn_1_496FC(fzgx_live, vec.value1);
    fn_1_49738(fn_1_12A080);
    fn_1_495FC();
    fn_1_495C8(0x11);
    if (arg0->unk_38 < 0.5f) {
        arg0->unk_38 = 0.5f;
    }
    fn_1_495A0(0.8f);
    size = 2.0f * arg0->unk_38;
    fn_1_4955C(size, size);
    fn_1_4966C(0.0f, 0.0f);
    fn_1_4A0D8(arg0->unk_3C);
    fn_1_520CC();
}

#pragma opt_common_subs reset

#pragma opt_propagation reset
#undef lbl_1_bss_9C
#undef CLAMP
/* fzgx:end fn_1_12A0E0 */

/* fzgx:begin fn_1_12A24C */
s8 fn_1_12A24C(s8 arg) {
    if ((s8)fn_1_86678(arg) == -1) {
        return -1;
    }
    return arg;
}
/* fzgx:end fn_1_12A24C */
