#include <types.h>

typedef u8 GXBool;

typedef enum _GXTexFmt {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CI14 = 0x9,
    GX_TF_CMPR = 0xE,
    GX_TF_Z8 = 0x11,
    GX_TF_Z16 = 0x13,
    GX_TF_Z24X8 = 0x16,
    GX_CTF_R4 = 0x20,
    GX_CTF_RA4 = 0x22,
    GX_CTF_RA8 = 0x23,
    GX_CTF_YUVA8 = 0x26,
    GX_CTF_A8 = 0x26,
    GX_CTF_R8 = 0x27,
    GX_CTF_G8 = 0x28,
    GX_CTF_B8 = 0x29,
    GX_CTF_RG8 = 0x2A,
    GX_CTF_GB8 = 0x2B,
    GX_CTF_Z4 = 0x30,
    GX_CTF_Z8M = 0x39,
    GX_CTF_Z8L = 0x3A,
    GX_CTF_Z16L = 0x3C,
} GXTexFmt;

typedef enum _GXCITexFmt { GX_TF_C4 = 8, GX_TF_C8, GX_TF_C14X2 } GXCITexFmt;

static inline void __GXGetTexTileShift(GXTexFmt format, u32 *widthTiles, u32 *heightTiles) {
    switch (format) {
    case GX_TF_I4:
    case GX_TF_C4:
    case GX_TF_CMPR:
    case GX_CTF_R4:
    case GX_CTF_Z4:
        *widthTiles = 3;
        *heightTiles = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case GX_TF_C8:
    case GX_TF_Z8:
    case GX_CTF_RA4:
    case GX_CTF_R8:
    case GX_CTF_G8:
    case GX_CTF_B8:
    case GX_CTF_RG8:
    case GX_CTF_Z8M:
    case GX_CTF_Z8L:
        *widthTiles = 3;
        *heightTiles = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case GX_TF_RGBA8:
    case GX_TF_C14X2:
    case GX_TF_Z16:
    case GX_TF_Z24X8:
    case GX_CTF_RA8:
    case GX_CTF_GB8:
    case 44:
    case GX_CTF_Z16L:
        *widthTiles = 2;
        *heightTiles = 2;
        break;
    default:
        *heightTiles = 0;
        *widthTiles = 0;
        break;
    }
}

u32 GXGetTexBufferSize(u16 width, u16 height, u32 format, GXBool mipmap, u8 max_lod) {
    u32 widthTiles, heightTiles, tileSize, bufferSize, numX, numY, i;
    __GXGetTexTileShift(format, &widthTiles, &heightTiles);
    if (format == GX_TF_RGBA8 || format == GX_TF_Z24X8) {
        tileSize = 0x40;
    } else {
        tileSize = 0x20;
    }
    if (mipmap == ((GXBool)1)) {
        bufferSize = 0;
        for (i = 0; i < max_lod; i++) {
            numX = (((width) + (1 << (widthTiles)) - 1) >> (widthTiles));
            numY = (((height) + (1 << (heightTiles)) - 1) >> (heightTiles));
            bufferSize += numX * numY * tileSize;
            if (width == 1 && height == 1) {
                break;
            }
            width = (width > 1) ? (width >> 1) : 1;
            height = (height > 1) ? (height >> 1) : 1;
        }
    } else {
        numX = (((width) + (1 << (widthTiles)) - 1) >> (widthTiles));
        numY = (((height) + (1 << (heightTiles)) - 1) >> (heightTiles));
        bufferSize = numX * numY * tileSize;
    }
    return bufferSize;
}

void __GetImageTileCount(GXTexFmt format, u16 width, u16 height, u32 *a, u32 *b, u32 *c) {
    u32 widthTiles, heightTiles;
    __GXGetTexTileShift(format, &widthTiles, &heightTiles);
    if (width <= 0) {
        width = 1;
    }
    if (height <= 0) {
        height = 1;
    }
    *a = (((width) + (1 << (widthTiles)) - 1) >> (widthTiles));
    *b = (((height) + (1 << (heightTiles)) - 1) >> (heightTiles));
    *c = (format == GX_TF_RGBA8 || format == GX_TF_Z24X8) ? 2 : 1;
}
