#include "types.h"

typedef struct GXTexObj {
    u32 dummy[8];
} GXTexObj;

typedef struct Layer {
    u32 unk_0;
    u16 unk_4;
    s8 unk_6;
    u8 unk_7;
    GXTexObj *unk_8;
    u8 unk_C[8];
    void *unk_14;
} Layer;

typedef struct TexHeader {
    u32 unk_0;
    u32 unk_4;
    u16 unk_8;
    u16 unk_A;
    u16 unk_C;
} TexHeader;

typedef struct TexFile {
    u32 unk_0;
    u32 unk_4;
    u8 *unk_8;
} TexFile;

extern char lbl_8015AC08[];
extern char lbl_8015AC1C[];
extern void OSReport(const char *, ...);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInitTexObjLOD(GXTexObj *, s32, s32, f32, f32, f32, u8, u8, s32);

/* fn_800717BC: MWCC inlines it here; -1 when a side is not a power of two */
static inline u32 mip_count(int w, int h) {
    s32 i;
    s32 c0;
    s32 c1;
    s32 n;

    c0 = c1 = 0;
    for (i = 0; i < 10; i++) {
        if ((w & (1 << i)) != 0) {
            c0++;
        }
        if ((h & (1 << i)) != 0) {
            c1++;
        }
    }
    if (c0 > 1 || c1 > 1) {
        return -1;
    }
    if (w > h) {
        w = h;
    }
    n = 0;
    while (w > 4) {
        w >>= 1;
        n++;
    }
    return n;
}

void fn_800718BC(Layer *layer, TexHeader *tex, TexFile *file) {
    u8 max_lod;
    u8 *image;
    s32 wrap_s;
    s32 wrap_t;
    u8 lod;
    s32 format;
    s32 min_filter;
    s32 mag_filter;

    image = file->unk_8 + tex->unk_4;
    if (tex->unk_0 & 0x100) {
        OSReport(lbl_8015AC08);
        layer->unk_8 = NULL;
        return;
    }
    switch ((layer->unk_0 >> 2) & 3) {
    case 2:
        wrap_s = 2;
        break;
    case 1:
        wrap_s = 1;
        break;
    default:
        wrap_s = 0;
        break;
    }
    switch ((layer->unk_0 >> 4) & 3) {
    case 2:
        wrap_t = 2;
        break;
    case 1:
        wrap_t = 1;
        break;
    default:
        wrap_t = 0;
        break;
    }
    max_lod = (layer->unk_0 >> 7) & 0xF;
    lod = mip_count(tex->unk_8, tex->unk_A);
    if (lod == 0xFF) {
        if (wrap_t != 0 || wrap_s != 0) {
            OSReport(lbl_8015AC1C, tex->unk_8, tex->unk_A);
        }
        wrap_s = 0;
        wrap_t = 0;
        max_lod = 0;
    } else if (max_lod == 15 || lod < max_lod) {
        max_lod = lod;
    }
    /* retail compares the zero-extended u16 with -1 (lhz; cmpwi), as written here */
    if (tex->unk_C != -1 && tex->unk_C < max_lod) {
        max_lod = tex->unk_C;
    }
    format = tex->unk_0 & 0x1F;
    switch (format) {
    case 0:
    case 14:
        if (max_lod != 0) {
            max_lod--;
        }
        break;
    }
    GXInitTexObj(layer->unk_8, image, tex->unk_8, tex->unk_A, format, wrap_s, wrap_t, max_lod != 0);
    layer->unk_14 = image;
    if (layer->unk_0 & 0x800) {
        mag_filter = 0;
        if (max_lod != 0) {
            min_filter = 4;
        } else {
            min_filter = 2;
        }
    } else {
        mag_filter = 1;
        if (max_lod != 0) {
            min_filter = 5;
        } else {
            min_filter = 3;
        }
    }
    GXInitTexObjLOD(layer->unk_8, min_filter, mag_filter, 0.0f, max_lod, layer->unk_6 / 10.0f, 0,
                    (layer->unk_0 >> 6) & 1, layer->unk_7);
}
