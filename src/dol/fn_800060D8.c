#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct {
    void *image;
    u16 code;
    u16 width;
} FontGlyph;

typedef struct {
    u32 dummy[8];
} GXTexObj;

extern s16 lbl_801A66EC;
extern FontGlyph lbl_8015B940[];

extern s32 fn_80006334(u8 *);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInvalidateTexAll(void);
extern void fn_80073778(GXTexObj *, s32);
extern void fn_8003462C(s32, s32, u16);

#define FIFO_F32(v) (*(volatile f32 *)GX_FIFO_BASE = (v))  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

static inline FontGlyph *find_glyph(s32 code) {
    FontGlyph *glyph = lbl_8015B940;
    s32 i;

    for (i = 0; i < lbl_801A66EC; i++, glyph++) {
        if (glyph->code == code) {
            return glyph;
        }
    }
    return NULL;
}

void fn_800060D8(f32 x, f32 y, f32 z, u8 *str) {
    GXTexObj obj;
    FontGlyph *glyph;
    u32 code;
    f32 nz;
    f32 y2;
    f32 x2;

    nz = -z;
    while (*str != 0) {
        if (fn_80006334(str)) {
            code = *(u16 *)str;
            str += 2;
        } else {
            code = *str;
            str += 1;
        }
        if (code == 0x20) {
            x += 8.0;
            continue;
        }
        glyph = find_glyph(code);
        if (glyph == NULL) {
            continue;
        }
        GXInitTexObj(&obj, glyph->image, 24, 24, 0, 0, 0, 0);
        GXInvalidateTexAll();
        fn_80073778(&obj, 0);
        y2 = 24.0 + y;
        x2 = x + glyph->width;
        fn_8003462C(0x80, 7, 4);
        FIFO_F32(x);
        FIFO_F32(y);
        FIFO_F32(nz);
        FIFO_F32(0.0f);
        FIFO_F32(0.0f);
        FIFO_F32(x2);
        FIFO_F32(y);
        FIFO_F32(nz);
        FIFO_F32(glyph->width / 24.0);
        FIFO_F32(0.0f);
        FIFO_F32(x2);
        FIFO_F32(y2);
        FIFO_F32(nz);
        FIFO_F32(glyph->width / 24.0);
        FIFO_F32(1.0f);
        FIFO_F32(x);
        FIFO_F32(y2);
        FIFO_F32(nz);
        FIFO_F32(0.0f);
        FIFO_F32(1.0f);
        x += glyph->width;
    }
}
