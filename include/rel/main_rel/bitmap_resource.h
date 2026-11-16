#ifndef REL_MAIN_REL_BITMAP_RESOURCE_H
#define REL_MAIN_REL_BITMAP_RESOURCE_H

#include "types.h"

/* Bitmap resource table lbl_1_data_FCD4[188], 0x28 bytes each.
 * Retail data gives each record seven archive paths selected by the language
 * index lbl_801A66B4. The loader fn_1_47AD4 records the heap index (an entry of
 * the three-heap table lbl_1_data_6CA0) and the image set: 0x10-byte texture
 * headers plus 0x20-byte texture objects initialized with GXInitTexObj. */
typedef struct BitmapImageInfo {
    u32 flags;
    u32 offset;
    u16 width;
    u16 height;
    u32 unk_C;
} BitmapImageInfo;

typedef struct BitmapImages {
    u32 count;
    BitmapImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} BitmapImages;

typedef struct BitmapResource {
    s32 loaded;
    char *paths[7];
    BitmapImages *images;
    u8 heap;
    u8 pad_25[3];
} BitmapResource;

extern BitmapResource lbl_1_data_FCD4[188];

#endif
