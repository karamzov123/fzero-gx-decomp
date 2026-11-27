#ifndef GAME_MAIN_REL_EFFECT_PARTICLE_H
#define GAME_MAIN_REL_EFFECT_PARTICLE_H

// The 0xE8-byte effect spawn record. effect_car.c's spawners clear one on the stack, fill it and pass it
// to fn_1_58F50 / fn_1_59078 (effect.c), which copy it into the particle pool lbl_1_bss_6C84C
// (Obj_1_bss_6C84C_Target in the generated effect.h is the same record seen from effect.c's accesses).
// Field names follow their use in the spawners; the unk_ ones are not interpreted yet. Hand-owned (librarian).

#include "types.h"
#include "game/vec3.h"

typedef struct EffectParticle {
    u8 pad_0[0x8];
    u32 flags;        // 0x08
    s16 kind;         // 0x0C
    u8 pad_E[0x2];
    s32 timer;        // 0x10
    u8 pad_14[0x4];
    s16 id;           // 0x18: owning machine
    u16 owner;        // 0x1A
    Vec3 color;       // 0x1C
    f32 scale;        // 0x28
    f32 unk_2C;       // 0x2C
    u8 pad_30[0x4];
    u32 model;        // 0x34
    u32 unk_38;       // 0x38
    Vec3 pos;         // 0x3C
    Vec3 vel;         // 0x48
    s16 rot_x;        // 0x54
    s16 rot_y;        // 0x56
    s16 rot_z;        // 0x58
    s16 unk_5A;       // 0x5A
    s16 unk_5C;       // 0x5C
    u8 pad_5E[0x12];
    Vec3 dir;         // 0x70
    u8 pad_7C[0xC];
    f32 unk_88;       // 0x88
    f32 unk_8C;       // 0x8C
    u8 pad_90[0x4];
    Vec3 unk_94;      // 0x94
    f32 unk_A0;       // 0xA0
    u8 pad_A4[0x8];
    s16 lifetime;     // 0xAC
    u8 pad_AE[0x4];
    u16 unk_B2;       // 0xB2
    f32 unk_B4;       // 0xB4
    f32 mtx[3][4];    // 0xB8
} EffectParticle;     // 0xE8

#endif  // GAME_MAIN_REL_EFFECT_PARTICLE_H
