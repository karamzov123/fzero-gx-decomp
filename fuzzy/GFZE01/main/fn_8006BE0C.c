/* Non-matching: best partial attempt (67.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/* The shared payload words are read as s16, u16, u32 or as raw bytes depending
 * on the message type, so each two- and four-byte slot is a union. */
typedef union Fn8006BE0CWord {
    s16 sw;
    u16 uw;
    u8 b[2];
} Fn8006BE0CWord;

typedef union Fn8006BE0CHalf {
    u32 w32;
    u16 uw;
    s16 sw;
    u8 b[4];
} Fn8006BE0CHalf;

/* Byte/halfword view of a message. */
typedef struct Fn8006BE0CSrc {
    u8 type;
    u8 pad_1[3];
    u32 field_4;
    u32 field_8;
    Fn8006BE0CWord at_C;
    Fn8006BE0CWord at_E;
    Fn8006BE0CWord at_10;
    Fn8006BE0CWord at_12;
    Fn8006BE0CWord at_14;
    Fn8006BE0CHalf at_18;
    u32 at_1C;
    u8 at_20;
    u8 at_21;
} Fn8006BE0CSrc;

/* Same bytes, with 0x10 and 0x14 as words (type 0 message). */
typedef struct Fn8006BE0CSrcWide {
    u8 type;
    u8 pad_1[3];
    u32 field_4;
    u32 field_8;
    Fn8006BE0CWord at_C;
    Fn8006BE0CWord at_E;
    u32 at_10;
    u32 at_14;
    Fn8006BE0CHalf at_18;
    u32 at_1C;
    u8 at_20;
    u8 at_21;
} Fn8006BE0CSrcWide;

typedef struct Fn8006BE0CDst {
    u8 type;
    u8 pad_1[3];
    u32 field_4;
    u32 field_8;
    Fn8006BE0CWord at_C;
    Fn8006BE0CWord at_E;
    Fn8006BE0CWord at_10;
    Fn8006BE0CWord at_12;
    Fn8006BE0CWord at_14;
    Fn8006BE0CHalf at_18;
    u32 at_1C;
    u8 at_20;
    u8 at_21;
    u8 pad_22[6];
    u32 flags;
    u8 pad_2C[12];
    u32 f38;
    u32 f3C;
} Fn8006BE0CDst;

typedef struct Fn8006BE0CDstWide {
    u8 type;
    u8 pad_1[3];
    u32 field_4;
    u32 field_8;
    Fn8006BE0CWord at_C;
    Fn8006BE0CWord at_E;
    u32 at_10;
    u32 at_14;
    Fn8006BE0CHalf at_18;
    u32 at_1C;
    u8 at_20;
    u8 at_21;
    u8 pad_22[6];
    u32 flags;
    u8 pad_2C[12];
    u32 f38;
    u32 f3C;
} Fn8006BE0CDstWide;

#pragma opt_fold off
#pragma opt_propagation off
s32 fn_8006BE0C(Fn8006BE0CDst *dst, Fn8006BE0CSrc *src) {
    s32 t;
    s32 v;
    s32 w;
    u32 u;
    s32 d;
    s32 result;

    t = src->type;
    v = src->field_4;
    w = src->field_8;
    dst->type = t;
    dst->field_4 = v;
    dst->field_8 = w;
    result = 0;
    switch (t) {
    case 0:
        dst->flags |= 0x14;
        v = src->at_C.sw;
        w = (v >= -255) ? v : -255;
        w = (w <= 255) ? w : 255;
        dst->at_C.uw = w;
        d = 360;
        dst->at_E.uw = ((src->at_E.uw % d) << 8) / d;
        ((Fn8006BE0CDstWide *)dst)->at_10 = ((Fn8006BE0CSrcWide *)src)->at_10;
        ((Fn8006BE0CDstWide *)dst)->at_14 = ((Fn8006BE0CSrcWide *)src)->at_14;
        v = src->at_18.b[0];
        w = (v <= 255) ? v : 255;
        dst->at_18.b[0] = w;
        v = src->at_18.b[1];
        w = (v <= 255) ? v : 255;
        dst->at_18.b[1] = w;
        break;
    case 1:
        dst->flags |= 0x24;
        v = src->at_C.sw;
        w = (v >= -255) ? v : -255;
        w = (w <= 255) ? w : 255;
        dst->at_C.uw = w;
        v = src->at_E.sw;
        w = (v >= -255) ? v : -255;
        w = (w <= 255) ? w : 255;
        dst->at_E.uw = w;
        d = 360;
        dst->at_10.uw = ((src->at_10.uw % d) << 8) / d;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        dst->flags |= 0x44;
        v = src->at_C.b[0];
        w = (v <= 255) ? v : 255;
        dst->at_C.b[0] = w;
        d = 360;
        dst->at_E.uw = ((src->at_E.uw % d) << 8) / d;
        u = src->at_10.uw;
        w = (u >= 2) ? u : 2;
        dst->at_10.uw = w;
        d = 360;
        dst->at_12.uw = ((src->at_12.uw % d) << 8) / d;
        v = src->at_14.sw;
        w = (v >= -255) ? v : -255;
        w = (w <= 255) ? w : 255;
        dst->at_14.uw = w;
        dst->at_18.w32 = src->at_18.w32;
        dst->at_1C = src->at_1C;
        v = src->at_20;
        w = (v <= 255) ? v : 255;
        dst->at_20 = w;
        v = src->at_21;
        w = (v <= 255) ? v : 255;
        dst->at_21 = w;
        if (dst->at_10.uw < 4) {
            dst->at_12.uw = 0x40;
        }
        break;
    case 7:
    case 8:
        dst->flags |= 0x80;
        v = src->at_12.sw;
        dst->at_C.b[0] = src->at_C.b[0];
        dst->at_C.b[1] = src->at_C.b[1];
        w = (v >= -255) ? v : -255;
        w = (w <= 255) ? w : 255;
        dst->at_12.uw = w;
        v = src->at_10.sw;
        w = (v >= -255) ? v : -255;
        w = (w <= 255) ? w : 255;
        dst->at_10.uw = w;
        dst->at_E.b[0] = (u8)(src->at_E.b[0] >> 23);
        dst->at_E.b[1] = (u8)(src->at_E.b[1] >> 23);
        dst->f38 = ((s8)dst->at_C.b[0] - (dst->at_C.b[1] >> 1)) << 12;
        dst->f3C = ((s8)dst->at_C.b[0] + (dst->at_C.b[1] >> 1)) << 12;
        break;
    default:
        result = -2;
        break;
    }
    return result;
}
#pragma opt_propagation reset
