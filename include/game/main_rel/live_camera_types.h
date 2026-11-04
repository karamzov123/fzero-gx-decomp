#ifndef GAME_MAIN_REL_LIVE_CAMERA_TYPES_H
#define GAME_MAIN_REL_LIVE_CAMERA_TYPES_H

// Types (and the externs that name them) of live_camera.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"

struct fn_1_E174_lbl_1_rodata_4E0 {
    f32 unk_0;
    u8 pad_4[0x10];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
};

#include "game/main_rel/adxt_stop_types.h"

#include "game/vec3.h"

typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_45730_LoadEntry;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    Sig_fn_1_45730_LoadEntry entry;
} Sig_fn_1_45730_LoadResult;

typedef struct {
    u8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    u16 unk_8;
    u8 pad_A[0x2];
    u32 unk_C;
    u16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u8 pad_1C[0x48];
    u16 unk_64;
} Sig_fn_1_101D0_Fn_1_101D0_State;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_11544_LiveCamVec;

typedef struct {
    f32 m[3][4];
} LiveCamMtx;

extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern int fn_1_45730(char *, Sig_fn_1_45730_LoadResult *);
extern u32 fn_1_45B2C(Sig_fn_1_45730_LoadResult *);
extern void fn_1_458A0(Sig_fn_1_45730_LoadResult *, void *, u32, u32);
extern void fn_1_45850(Sig_fn_1_45730_LoadResult *);
extern u32 fn_1_107B8(Sig_fn_1_101D0_Fn_1_101D0_State *);
extern void fn_1_862D4(int, Vec3 *);
/* returns a status in r3 (fn_1_648DC tests it; stcoli.c callers store it) */
extern int fn_1_15578(void *, fn_1_11544_LiveCamVec *, void *, void *, u32, void *, u32, u32, u32, u32);
extern void fn_8006E2B0(void *, Vec3 *);

#endif  // GAME_MAIN_REL_LIVE_CAMERA_TYPES_H
