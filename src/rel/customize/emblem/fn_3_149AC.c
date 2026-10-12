#include "types.h"
#include "rel/customize/emblem.h"

extern void *memcpy(void *, const void *, u32);

u32 fn_3_149AC(u8 *pixels, s16 x, s16 y) {
    s16 tile_width;
    s16 tile_x;
    s16 tile_y;
    s16 tile;
    s16 pixel_x;
    s16 pixel_y;
    s16 offset;
    u16 pixel;
    u32 result;
    u8 *rgba;

    rgba = (u8 *)&result;
    switch (lbl_3_bss_A23E0) {
    case 4:
        tile_x = x / 4;
        tile_y = y / 4;
        tile_width = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tile_x + tile_y * tile_width;
        pixel_x = x % 4;
        pixel_y = y % 4;
        offset = (tile << 5) + ((pixel_x + pixel_y * 4) << 1);

        pixel = pixels[offset] << 8;
        pixel = (pixel & 0xFF00) | pixels[offset + 1];
        rgba[0] = (u8)(((pixel >> 8) & 0xF8) | (pixel & 7));
        rgba[1] = (u8)(((pixel >> 3) & 0xFC) | (pixel & 3));
        rgba[2] = (u8)(((pixel << 3) & 0xF8) | (pixel & 7));
        break;
    case 5:
        tile_x = x / 4;
        tile_y = y / 4;
        tile_width = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tile_x + tile_y * tile_width;
        pixel_x = x % 4;
        pixel_y = y % 4;
        offset = (tile << 5) + ((pixel_x + pixel_y * 4) << 1);

        memcpy(&pixel, pixels + offset, 2);
        if (pixel & 0x8000) {
            rgba[3] = 0xFF;
            rgba[0] = (u8)((pixel >> 7) & 0xF8);
            rgba[1] = (u8)((pixel >> 2) & 0xF8);
            rgba[2] = (u8)((pixel & 0x1F) << 3);
        } else {
            rgba[3] = (u8)((pixel >> 8) & 0x70);
            rgba[0] = (u8)((pixel >> 4) & 0xF0);
            rgba[1] = (u8)(pixel & 0xF0);
            rgba[2] = (u8)((pixel & 0x0F) << 4);
        }
        break;
    }
    return result;
}
