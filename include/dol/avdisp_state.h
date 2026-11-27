#ifndef DOL_AVDISP_STATE_H
#define DOL_AVDISP_STATE_H

#include "game/vec3.h"

struct Color_u6 { u8 r, g, b, a; };
typedef struct AvDispMatState {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    struct Color_u6 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24[4];
    u16 unk_34[3];
    u8 pad_3A[2];
    s32 unk_3C;
    s32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    Vec3 unk_50;
    u8 pad_5C[4];
} AvDispMatState;
extern AvDispMatState lbl_801A3220;

#endif
