#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

// The machine records shared by car_test.c and car.c (both carried identical copies of the model
// and texture types). lbl_1_bss_6D838 points to an array of CarBody, one per machine
// (fn_1_83070 allocates lbl_1_bss_6D84A * 0x620 bytes); lbl_1_bss_6D83C points to an array of
// Car (fn_1_82724 allocates count * 0x440 bytes), whose body member points into the CarBody
// array. car.c's functions used to view the two arrays through a dozen private layouts; these
// are their union. Hand-owned (librarian).

#include "types.h"
#include "game/vec3.h"

/* one model of a machine */
typedef struct CarModel {
    u8 pad_0[8];
    Vec3 center;
    f32 radius;
    u16 ntex;
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
    u32 unk_8;
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
    u8 pad_94[0xB8];
    f32 mtx[3][4];
    f32 unk_17C;
    u8 pad_180[0x4];
    f32 unk_184;
    s16 unk_188;
    u8 pad_18A[0x32];
    u32 unk_1BC;
    u32 unk_1C0;
    u32 unk_1C4;
    u8 pad_1C8[0x2C];
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
    u8 pad_228[0x24C];
    s8 unk_474;
    s8 unk_475;
    u8 pad_476[0xE];
    u32 unk_484;
    void *unk_488[4];
    void *unk_498;
    void *unk_49C;
    u32 unk_4A0;
    u32 unk_4A4;
    u32 unk_4A8;
    u8 pad_4AC[0x62];
    u8 unk_50E;
    u8 pad_50F[0x7D];
    u32 unk_58C;
    u8 pad_590[0x90];
} CarBody;

/* one machine (0x440 bytes) */
typedef struct Car {
    u8 pad_0[2];
    s8 limit;
    u8 pad_3[0x321];
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
    u8 pad_394[0xC];
    u8 *unk_3A0;
    u8 pad_3A4[0x4];
    u32 unk_3A8;
    u8 pad_3AC[0xC];
    s16 cv;
    s16 lod;
    u8 pad_3BC[0x84];
} Car;

#endif  // GAME_MAIN_REL_CAR_TYPES_H
