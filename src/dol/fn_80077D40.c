#include "types.h"

struct Item {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
};

struct TextureList {
    u32 count;
    struct Item *items;
};

typedef u8 Sig_GXGetTexBufferSize_GXBool;

extern u32 fn_800717BC(u32, u32);
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

u32 fn_80077D40(struct TextureList *arg0) {
    u32 i;
    u32 total;
    u32 max_lod;
    struct Item *item;

    total = 0;

    for (i = 0; i < arg0->count; i++) {
        item = &arg0->items[i];
        if ((item->flags & 0x100) == 0) {
            max_lod = fn_800717BC(item->width, item->height);
            if (max_lod == 0xFFFFFFFF) {
                max_lod = 0;
            }
            if (item->max_lod != -1 && item->max_lod < max_lod) {
                max_lod = item->max_lod;
            }
            total += GXGetTexBufferSize(item->width, item->height, item->flags & 0x1F, max_lod != 0, max_lod);
        }
    }

    return total;
}
