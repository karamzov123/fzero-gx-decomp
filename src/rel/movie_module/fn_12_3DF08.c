#include "types.h"

/* fn_12_3DF08, from the CC0 MK Deception decomp (cftfx.c) */

typedef struct CFTYcc420Planar {
    const u8 *y;
    const u8 *cb;
    const u8 *cr;
    s32 y_stride;
    s32 cb_stride;
    s32 cr_stride;
} CFTYcc420Planar;
typedef struct CFTArgb8888Output {
    u8 *data;
    s32 width;
    s32 height;
    s32 stride;
} CFTArgb8888Output;

#pragma use_lmw_stmw on
void fn_12_3DF08(const CFTYcc420Planar *source, const CFTArgb8888Output *destination) {
    s32 block_y;
    s32 block_x;
    s32 width_in_blocks = destination->width / 4;
    s32 y_step = source->y_stride / sizeof(u32);
    s32 height_in_blocks = destination->height / 4;
    s32 output_skip = (u32)(destination->stride - destination->width) / 4 * 16;
    u32 *output = (u32 *)destination->data;
    u32 *y = (u32 *)source->y;
    u32 pixels;
    u32 low = 0;
    for (block_y = 0; block_y < height_in_blocks; block_y++) {
        for (block_x = 0; block_x < width_in_blocks; block_x++) {
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output)[0] &= (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output)[1] &= (low) | 0x00FF00FF;
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output + 2)[0] &=
                (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output + 2)[1] &= (low) | 0x00FF00FF;
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output + 4)[0] &=
                (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output + 4)[1] &= (low) | 0x00FF00FF;
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output + 6)[0] &=
                (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output + 6)[1] &= (low) | 0x00FF00FF;
            y -= y_step * 4;
            low = (u32)y + 4;
            y = (u32 *)low;
            low = (u32)output + 64;
            output = (u32 *)low;
        }
        y += y_step * 3;
        output += output_skip;
    }
}
