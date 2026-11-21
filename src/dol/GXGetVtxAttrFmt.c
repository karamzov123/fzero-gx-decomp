#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
#include "types.h"

static inline u8 GetFracForNrm(GXCompType type) {
    u8 frac;
    switch (type) {
    case GX_S8:
        frac = 6;
        break;
    case GX_S16:
        frac = 14;
        break;
    default:
    case GX_U16:
        frac = 0;
        break;
    }
    return frac;
}

void GXGetVtxAttrFmt(GXVtxFmt fmt, int attr, GXCompCnt *cnt, GXCompType *type, u8 *frac) {
    u32 *va;
    u32 *vb;
    u32 *vc;
    va = &gx->vatA[fmt];
    vb = &gx->vatB[fmt];
    vc = &gx->vatC[fmt];
    switch (attr) {
    case GX_VA_POS:
        *cnt = ((int)((*va) >> (0)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (1)) & ((1 << (3)) - 1));
        *frac = ((int)((*va) >> (4)) & ((1 << (5)) - 1));
        return;
    case GX_VA_NRM:
    case GX_VA_NBT:
        *cnt = ((int)((*va) >> (9)) & ((1 << (1)) - 1));
        if (*cnt == GX_TEX_ST && (u8)(*va >> 0x1F) != 0) {
            *cnt = GX_NRM_NBT3;
        }
        *type = ((int)((*va) >> (10)) & ((1 << (3)) - 1));
        *frac = GetFracForNrm(*type);
        return;
    case GX_VA_CLR0:
        *cnt = ((int)((*va) >> (13)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (14)) & ((1 << (3)) - 1));
        *frac = 0;
        return;
    case GX_VA_CLR1:
        *cnt = ((int)((*va) >> (17)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (18)) & ((1 << (3)) - 1));
        *frac = 0;
        return;
    case GX_VA_TEX0:
        *cnt = ((int)((*va) >> (21)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (22)) & ((1 << (3)) - 1));
        *frac = (u8)(*va >> 0x19U) & 0x1F;
        return;
    case GX_VA_TEX1:
        *cnt = ((int)((*vb) >> (0)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (1)) & ((1 << (3)) - 1));
        *frac = (u8)(*vb >> 4U) & 0x1F;
        return;
    case GX_VA_TEX2:
        *cnt = ((int)((*vb) >> (9)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (10)) & ((1 << (3)) - 1));
        *frac = (u8)(*vb >> 0xDU) & 0x1F;
        return;
    case GX_VA_TEX3:
        *cnt = ((int)((*vb) >> (18)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (19)) & ((1 << (3)) - 1));
        *frac = (u8)(*vb >> 0x16U) & 0x1F;
        return;
    case GX_VA_TEX4:
        *cnt = ((int)((*vb) >> (27)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (28)) & ((1 << (3)) - 1));
        *frac = ((int)((*vc) >> (0)) & ((1 << (5)) - 1));
        return;
    case GX_VA_TEX5:
        *cnt = ((int)((*vc) >> (5)) & ((1 << (1)) - 1));
        *type = ((int)((*vc) >> (6)) & ((1 << (3)) - 1));
        *frac = (u8)(*vc >> 9U) & 0x1F;
        return;
    case GX_VA_TEX6:
        *cnt = ((int)((*vc) >> (14)) & ((1 << (1)) - 1));
        *type = ((int)((*vc) >> (15)) & ((1 << (3)) - 1));
        *frac = (u8)(*vc >> 0x12) & 0x1F;
        return;
    case GX_VA_TEX7:
        *cnt = ((int)((*vc) >> (23)) & ((1 << (1)) - 1));
        *type = ((int)((*vc) >> (24)) & ((1 << (3)) - 1));
        *frac = (int)(*vc >> 0x1BU);
        return;
    default:
        *cnt = GX_TEX_ST;
        *type = GX_RGB565;
        *frac = 0;
        return;
    }
}

void GXGetVtxAttrFmtv(GXVtxFmt vat, GXVtxAttrFmt *fmt) {
    int attr;

    for (attr = 9; attr <= 20; attr++) {
        fmt->attr = (u32)attr;
        GXGetVtxAttrFmt(vat, attr, &fmt->cnt, &fmt->type, &fmt->frac);
        fmt++;
    }
    fmt->attr = 0xff;
}

void GXSetArray(GXAttr attr, void *base_ptr, u8 stride) {
    GXAttr cpAttr;
    u32 phyAddr;
    if (attr == GX_VA_NBT) {
        attr = GX_VA_NRM;
    }
    cpAttr = attr - GX_VA_POS;
    phyAddr = (u32)base_ptr & 0x3FFFFFFF;
    do {
        long regAddr;
        GXWGFifo.u8 = (u8)(8);
        GXWGFifo.u8 = (u8)(cpAttr | GX_BP_REG_SETMODE0_TEX4);
        GXWGFifo.u32 = (u32)(phyAddr);
        regAddr = cpAttr - 12;
        if (regAddr >= 0 && regAddr < 4) {
            gx->indexBase[regAddr] = phyAddr;
        }
    } while (0);
    do {
        long regAddr;
        GXWGFifo.u8 = (u8)(8);
        GXWGFifo.u8 = (u8)(cpAttr | GX_BP_REG_SETIMAGE2_TEX4);
        GXWGFifo.u32 = (u32)(stride);
        regAddr = cpAttr - 12;
        if (regAddr >= 0 && regAddr < 4) {
            gx->indexStride[regAddr] = stride;
        }
    } while (0);
}

// Hardware FIFO register is intentionally volatile.

void GXInvalidateVtxCache(void) {
    GXWGFifo.u8 = 0x48;
}

void __GXSetMatrixIndex(GXAttr index);

void GXSetTexCoordGen2(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx,
                 GXBool normalize, u32 pt_texmtx) {
    u32 reg = 0;
    u32 row;
    u32 bumprow;
    u32 form;
    GXAttr mtxIdAttr;
    form = 0;
    row = 5;
    switch (src_param) {
    case GX_TG_POS:
        row = 0;
        form = 1;
        break;
    case GX_TG_NRM:
        row = 1;
        form = 1;
        break;
    case GX_TG_BINRM:
        row = 3;
        form = 1;
        break;
    case GX_TG_TANGENT:
        row = 4;
        form = 1;
        break;
    case GX_TG_COLOR0:
        row = 2;
        break;
    case GX_TG_COLOR1:
        row = 2;
        break;
    case GX_TG_TEX0:
        row = 5;
        break;
    case GX_TG_TEX1:
        row = 6;
        break;
    case GX_TG_TEX2:
        row = 7;
        break;
    case GX_TG_TEX3:
        row = 8;
        break;
    case GX_TG_TEX4:
        row = 9;
        break;
    case GX_TG_TEX5:
        row = 10;
        break;
    case GX_TG_TEX6:
        row = 11;
        break;
    case GX_TG_TEX7:
        row = 12;
        break;
    case GX_TG_TEXCOORD0:
        bumprow;
        break;
    case GX_TG_TEXCOORD1:
        bumprow;
        break;
    case GX_TG_TEXCOORD2:
        bumprow;
        break;
    case GX_TG_TEXCOORD3:
        bumprow;
        break;
    case GX_TG_TEXCOORD4:
        bumprow;
        break;
    case GX_TG_TEXCOORD5:
        bumprow;
        break;
    case GX_TG_TEXCOORD6:
        bumprow;
        break;
    default:
        break;
    }
    switch (func) {
    case GX_TG_MTX2x4:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(0) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(0) << (4));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(row) << (7));
        ;
        break;
    case GX_TG_MTX3x4:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(1) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(0) << (4));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(row) << (7));
        ;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(0) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(1) << (4));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(row) << (7));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (12))) | ((u32)(src_param - 12) << (12));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (15))) | ((u32)(func - 2) << (15));
        ;
        break;
    case GX_TG_SRTG:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(0) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        if (src_param == GX_TG_COLOR0) {
            (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(2) << (4));
            ;
        } else {
            (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(3) << (4));
            ;
        }
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(2) << (7));
        ;
        break;
    default:
        break;
    }
    do {
        GXWGFifo.u8 = (u8)(0x10);
        GXWGFifo.u32 = (u32)(0x1000 + (dst_coord + 0x40));
        GXWGFifo.u32 = (u32)(reg);
        ;
    } while (0);
    reg = 0;
    (reg) = ((u32)(reg) & ~(((1 << (6)) - 1) << (0))) | ((u32)(pt_texmtx - 64) << (0));
    ;
    (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (8))) | ((u32)(normalize) << (8));
    ;
    do {
        GXWGFifo.u8 = (u8)(0x10);
        GXWGFifo.u32 = (u32)(0x1000 + (dst_coord + 0x50));
        GXWGFifo.u32 = (u32)(reg);
        ;
    } while (0);
    switch (dst_coord) {
    case GX_TEXCOORD0:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (6))) | ((u32)(mtx) << (6));
        ;
        break;
    case GX_TEXCOORD1:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (12))) | ((u32)(mtx) << (12));
        ;
        break;
    case GX_TEXCOORD2:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (18))) | ((u32)(mtx) << (18));
        ;
        break;
    case GX_TEXCOORD3:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (24))) | ((u32)(mtx) << (24));
        ;
        break;
    case GX_TEXCOORD4:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (0))) | ((u32)(mtx) << (0));
        ;
        break;
    case GX_TEXCOORD5:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (6))) | ((u32)(mtx) << (6));
        ;
        break;
    case GX_TEXCOORD6:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (12))) | ((u32)(mtx) << (12));
        ;
        break;
    default:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (18))) | ((u32)(mtx) << (18));
        ;
        break;
    }
    mtxIdAttr = dst_coord + 1;
    __GXSetMatrixIndex(mtxIdAttr);
}

// Hardware FIFO register is intentionally volatile.

void GXSetNumTexGens(u32 value) {
    GXData *g;
    u32 masked_value;

    g = gx;
    masked_value = value & 0xFF;
    g->genMode = (g->genMode & ~0xFu) | masked_value;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x103F;
    GXWGFifo.u32 = masked_value;
    g->dirtyState |= 4;
}
