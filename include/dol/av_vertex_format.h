#ifndef DOL_AV_VERTEX_FORMAT_H
#define DOL_AV_VERTEX_FORMAT_H

#include "types.h"

typedef struct AvVertexAttrFormat {
    s32 attr;
    s32 componentCount;
    s32 componentType;
    u8 fractionalBits;
} AvVertexAttrFormat;

void fn_800726C0(u32 format, AvVertexAttrFormat *attrs);

#endif
