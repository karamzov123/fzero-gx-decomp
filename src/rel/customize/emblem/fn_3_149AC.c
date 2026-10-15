#include "types.h"
#include "rel/customize/emblem.h"

extern void *memcpy(void *, const void *, u32);

u32 fn_3_149AC(u8 *pixels, s16 x, s16 y) {
    union {
        u8 bytes[8];
        u16 halfwords[4];
        u32 words[2];
    } slot;
    s16 tile_width;
    s16 tile_x;
    s16 tile_y;
    s16 tile;
    s16 pixel_x;
    s16 pixel_y;
    s16 offset;
    u16 pixel;
    u8 lo;
    u8 hi;

    switch (lbl_3_bss_A23E0) {
    case 4:
        tile_x = x / 4;
        tile_y = y / 4;
        tile_width = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tile_x + tile_y * tile_width;
        pixel_x = x % 4;
        pixel_y = y % 4;
        offset = (tile << 5) + ((pixel_x + pixel_y * 4) << 1);

        lo = pixels[offset];
        hi = pixels[offset + 1];
        slot.halfwords[0] = (u16)(lo << 8);
        pixel = (u16)((hi & 0xFF) | ((lo << 8) & 0xFFFF));
        slot.halfwords[0] = pixel;

        slot.bytes[4] = (u8)(((pixel >> 8) & 0xF8) | (pixel & 7));
        slot.bytes[5] = (u8)(((pixel >> 3) & 0xFC) | (pixel & 3));
        slot.bytes[6] = (u8)(((pixel << 3) & 0xF8) | (pixel & 7));
        break;

    case 5:
        tile_x = x / 4;
        tile_y = y / 4;
        tile_width = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tile_x + tile_y * tile_width;
        pixel_x = x % 4;
        pixel_y = y % 4;
        offset = (tile << 5) + ((pixel_x + pixel_y * 4) << 1);

        memcpy(slot.bytes, pixels + offset, 2);
        pixel = slot.halfwords[0];

        if (pixel & 0x8000) {
            slot.bytes[7] = 0xFF;
            slot.bytes[4] = (u8)((pixel >> 7) & 0xF8);
            slot.bytes[5] = (u8)((pixel >> 2) & 0xF8);
            slot.bytes[6] = (u8)((pixel & 0x1F) << 3);
        } else {
            slot.bytes[7] = (u8)((pixel >> 8) & 0x70);
            slot.bytes[4] = (u8)((pixel >> 4) & 0xF0);
            slot.bytes[5] = (u8)(pixel & 0xF0);
            slot.bytes[6] = (u8)((pixel & 0x0F) << 4);
        }
        break;
    }

    return slot.words[1];
}
