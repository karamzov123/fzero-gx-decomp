#ifndef FONTDRAWPACKETDEFAULT_H
#define FONTDRAWPACKETDEFAULT_H

#include "types.h"

typedef struct {
    u32 image;
    f32 x;
    f32 y;
    f32 z;
    f32 scale_x;
    f32 scale_y;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    s16 rotation_z;
    s16 rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    u8 color[4];
    u8 color_add[4];
    u32 format;
    u16 width;
    u16 height;
    void *pixels;
    void *secondary;
    void *vertex_callback;
    u32 unk_54;
} FontDrawPacketDefault;
extern const FontDrawPacketDefault lbl_1_rodata_26F8[1];

#endif
