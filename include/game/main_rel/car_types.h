#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

// The machine records shared by car_test.c and car.c (both carried identical copies of the model
// and texture types). lbl_1_bss_6D838 points to an array of CarBody, one per machine
// (fn_1_83070 allocates lbl_1_bss_6D84A * 0x620 bytes); lbl_1_bss_6D83C points to an array of
// Car (fn_1_82724 allocates count * 0x440 bytes), whose body member points into the CarBody
// array. car.c's functions used to view the two records (and the progress record a body's
// unk_49C points to) through some sixty private layouts; these are their union. Hand-owned
// (librarian).

#include "types.h"
#include "game/vec3.h"

typedef struct CarModelItem {
    u32 unk_0;
    u8 pad_4[0x1C];
} CarModelItem;

/* one model of a machine */
typedef struct CarModel {
    u8 pad_0[8];
    Vec3 center;
    f32 radius;
    u16 ntex;
    u8 pad_1A[0x26];
    CarModelItem items[1];
} CarModel;

typedef struct CarModelEntry {
    u32 unk_0;
    char *name;
} CarModelEntry;

typedef struct CarModelInfo {
    s32 count;
    CarModel *model;
    CarModelEntry *entries;
} CarModelInfo;

/* one level of detail of a machine */
typedef struct CarLod {
    CarModel **models;
    CarModelInfo *info;
    s16 unk_8;
    u8 pad_A[0x2];
} CarLod;

typedef struct CarTex {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
} CarTex;

typedef struct CarTexList {
    u32 count;
    CarTex *items;
    u32 unk_8;
} CarTexList;

/* one level of detail of a part set */
typedef struct CarPartLod {
    u32 unk_0;
    CarModel *unk_4;
    CarModel **unk_8;
} CarPartLod;

/* one of the three part sets a machine's unk_3A0 points to (fn_1_818BC hands each machine
   0xA20 bytes of lbl_1_bss_6D840) */
typedef struct CarPart {
    u8 pad_0[0x340];
    void *unk_340;
    CarPartLod *unk_344[6];
    u8 pad_35C[0x4];
} CarPart;

/* a lap time: frame count, fraction and the minutes / seconds / milliseconds it reads as */
typedef struct CarTime {
    u32 frames;
    f32 frac;
    u8 min;
    u8 sec;
    u16 ms;
} CarTime;

/* the race progress record a body's unk_49C points to (fn_1_83070 allocates 0x1FC bytes) */
typedef struct CarProgress {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x4];
    f32 unk_3C;
    f32 unk_40;
    u8 pad_44[0xC];
    Vec3 unk_50;
    Vec3 unk_5C;
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0xC];
    u32 unk_7C;
    s32 unk_80;
    f32 unk_84;
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
    u16 unk_104;
    u8 pad_106[0x2];
    f32 unk_108;
    s32 unk_10C;
    s32 unk_110;
    s8 unk_114;
    u8 unk_115;
    u8 unk_116;
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
    CarTime unk_160[9];
    CarTime unk_1CC;
    CarTime unk_1D8;
    CarTime unk_1E4;
    Vec3 unk_1F0;
} CarProgress;

/* one of the four corners of a body (0x5C bytes) */
typedef struct CarCorner {
    u32 unk_0;
    u8 pad_4[0x4];
    Vec3 unk_8;
    u8 pad_14[0x48];
} CarCorner;

/* the body state of a machine (0x620 bytes) */
typedef struct CarBody {
    u32 unk_0;
    s16 index;
    s16 unk_6;
    u8 pad_8[0x2C];
    f32 unk_34;
    f32 unk_38;
    char name[0x20];
    u8 pad_5C[0x20];
    Vec3 pos;
    Vec3 unk_88;
    u8 pad_94[0x10];
    f32 unk_A4;
    u8 pad_A8[0x44];
    f32 unk_EC[3][4];
    u8 pad_11C[0x30];
    f32 mtx[3][4];
    f32 unk_17C;
    u8 pad_180[0x4];
    f32 unk_184;
    s16 unk_188;
    u8 unk_18A;
    u8 pad_18B[0x31];
    u32 unk_1BC;
    u32 unk_1C0;
    u32 unk_1C4;
    f32 unk_1C8;
    s32 unk_1CC;
    f32 unk_1D0;
    u8 pad_1D4[0x20];
    f32 unk_1F4;
    f32 unk_1F8;
    f32 unk_1FC;
    f32 unk_200;
    f32 unk_204;
    u8 pad_208[0xC];
    u16 unk_214;
    u8 pad_216[0x2];
    u32 unk_218;
    u8 pad_21C[0x8];
    f32 unk_224;
    u8 pad_228[0x1C];
    CarCorner unk_244[4];
    u8 pad_3B4[0xC0];
    s8 unk_474;
    u8 unk_475;
    u8 pad_476[0xB];
    u8 unk_481;
    u8 pad_482[0x2];
    u32 unk_484;
    void *unk_488[4];
    void *unk_498;
    CarProgress *unk_49C;
    u32 unk_4A0;
    u32 unk_4A4;
    u32 unk_4A8;
    f32 unk_4AC;
    u8 pad_4B0[0x5D];
    u8 unk_50D;
    u8 unk_50E;
    u8 pad_50F[0x7D];
    u32 unk_58C;
    u8 unk_590;
    u8 pad_591[0x4F];
    f32 unk_5E0[3][4];
    f32 unk_610;
    s8 unk_614;
    u8 pad_615[0xB];
} CarBody;

/* a 0x14-byte record of a machine; the first 12 bytes are copied out as a vector */
typedef struct CarJoint {
    Vec3 unk_0;
    u8 pad_C[0x8];
} CarJoint;

/* one machine (0x440 bytes) */
typedef struct Car {
    u8 pad_0[2];
    s8 limit;
    u8 pad_3[0x205];
    CarJoint unk_208[14];
    s16 index;
    u8 pad_322[0x2];
    s32 unk_324;
    s8 kind;
    u8 pad_329[3];
    CarBody *body;
    u8 *parts;
    CarLod lods[6];
    CarTexList *tex[4];
    u8 lod_mask;
    u8 pad_38D[0x3];
    u32 unk_390;
    u8 *unk_394;
    u8 pad_398[0x8];
    CarPart *unk_3A0;
    void *unk_3A4;
    u32 unk_3A8;
    f32 unk_3AC;
    u32 unk_3B0;
    f32 unk_3B4;
    s16 cv;
    s16 lod;
    s32 unk_3BC;
    u32 unk_3C0[8];
    u32 unk_3E0[8];
    u32 unk_400[5];
    u32 unk_414[5];
    u8 pad_428[0x18];
} Car;

#endif  // GAME_MAIN_REL_CAR_TYPES_H
