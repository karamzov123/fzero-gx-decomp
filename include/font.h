#ifndef FONT_H
#define FONT_H

#include "types.h"

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
    f32 x, y, z;
} FontVertex;

struct FontDrawPacket {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    u8 color[4], color_add[4];
    u32 format;
    u16 width, height;
    void* pixels;
    FontDrawPacket* secondary;
    void (*vertex_callback)(const FontDrawPacket* packet, FontVertex* vertices);
    u32 unk_54;
};

void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
               s16 texture_width, s16 texture_height);

#endif
