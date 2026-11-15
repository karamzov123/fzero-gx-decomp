#include "types.h"
#include "dolphin/gx.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} AvColor;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} AvVec;

/* A line vertex (0x10 bytes). */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    AvColor color;
} AvVertex;

/* The line render state (0x1C bytes). */
typedef struct {
    u8 zMode;
    u32 blendType; /* 0x04 */
    u32 blendSrc; /* 0x08 */
    u32 blendDst; /* 0x0C */
    u32 blendOp; /* 0x10 */
    u32 zFunc; /* 0x14 */
    u32 unk_18;
} AvLineState;

/* A line draw of the draw list (0x60 bytes). */
typedef struct AvLineDraw {
    void *next;
    void (*draw)(struct AvLineDraw *);
    f32 mtx[3][4]; /* 0x08 */
    u32 prim; /* 0x38 */
    u16 count; /* 0x3C */
    AvVertex *verts; /* 0x40 */
    AvLineState state; /* 0x44 */
} AvLineDraw;

/* A queued line strip (0x104 bytes). */
typedef struct {
    u16 zMode;
    u16 count;
    AvVertex verts[16];
} AvLine;

extern void *lbl_801A6410;
extern f32 (*lbl_801A6D00)[4];

extern void fn_80008BA8(void *dst, const void *src, u32 size);
extern void fn_8003462C(u32 prim, u32 fmt, u16 count);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCA4(void);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800728A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(u32);
extern void fn_80074660(u32);
extern void fn_800746A8(u8, u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);
extern void GXLoadPosMtxImm(void *, u32);
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_1_46B4(void *, void *, char *, u32);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void *fn_1_548AC(u32 size);

void fn_1_57DC0(void);
void fn_1_57E84(AvLineDraw *draw);

AvLineState lbl_1_data_1C670 = {6, 0, 1, 0, 0, 0, 0};
AvLine *lbl_1_bss_6C840;
u16 lbl_1_bss_6C844;

static inline void GXPosition3f32(const f32 x, const f32 y, const f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXColor4u8(const u8 r, const u8 g, const u8 b, const u8 a) {
    GXWGFifo.u8 = r;
    GXWGFifo.u8 = g;
    GXWGFifo.u8 = b;
    GXWGFifo.u8 = a;
}

/* fzgx:begin fn_1_57714 */
// Updates the shadow-map enable flag.
void fn_1_57714(u8 zMode) {
    lbl_1_data_1C670.zMode = zMode;
}
/* fzgx:end fn_1_57714 */

/* fzgx:begin fn_1_57720 */
void fn_1_57720(u32 type, u32 src, u32 dst, u32 op) {
    lbl_1_data_1C670.blendType = type;
    lbl_1_data_1C670.blendSrc = src;
    lbl_1_data_1C670.blendDst = dst;
    lbl_1_data_1C670.blendOp = op;
}
/* fzgx:end fn_1_57720 */

/* fzgx:begin fn_1_5773C */
void fn_1_5773C(AvVec *a, AvVec *b, AvColor *color) {
    AvColor c;

    fn_1_57DC0();
    c = *color;
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xA8, 0, 2);
    GXPosition3f32(a->x, a->y, a->z);
    GXColor4u8(c.r, c.g, c.b, c.a);
    GXPosition3f32(b->x, b->y, b->z);
    GXColor4u8(c.r, c.g, c.b, c.a);
}
/* fzgx:end fn_1_5773C */

/* fzgx:begin fn_1_57810 */
void fn_1_57810(u16 n, AvVec *verts, AvColor *color) {
    AvColor c;
    int i;
    AvVec *p;

    if (n < 2) {
        return;
    }
    fn_1_57DC0();
    c = *color;
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xB0, 0, n);
    p = verts;
    for (i = n; i > 0; i--) {
        GXPosition3f32(p->x, p->y, p->z);
        GXColor4u8(c.r, c.g, c.b, c.a);
        p++;
    }
}
/* fzgx:end fn_1_57810 */

/* fzgx:begin fn_1_579A0 */
void fn_1_579A0(AvVertex *a, AvVertex *b) {
    fn_1_57DC0();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xA8, 0, 2);
    GXPosition3f32(a->x, a->y, a->z);
    GXColor4u8(a->color.r, a->color.g, a->color.b, a->color.a);
    GXPosition3f32(b->x, b->y, b->z);
    GXColor4u8(b->color.r, b->color.g, b->color.b, a->color.a);
}
/* fzgx:end fn_1_579A0 */

/* fzgx:begin fn_1_57A70 */
void fn_1_57A70(u16 n, AvVertex *verts) {
    s32 i;
    AvVertex *p;

    if (n < 2) {
        return;
    }
    fn_1_57DC0();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xB0, 0, n);
    p = verts;
    for (i = n; i > 0; i--) {
        GXPosition3f32(p->x, p->y, p->z);
        GXColor4u8(p->color.r, p->color.g, p->color.b, p->color.a);
        p++;
    }
}
/* fzgx:end fn_1_57A70 */

/* fzgx:begin fn_1_57BBC */
void fn_1_57BBC(AvVertex *a, AvVertex *b) {
    AvLineDraw *draw;
    AvVertex *verts;
    void *list;

    draw = fn_1_548AC(sizeof(AvLineDraw));
    if (draw == NULL) {
        return;
    }
    verts = fn_1_548AC(2 * sizeof(AvVertex));
    if (verts == NULL) {
        return;
    }
    list = fn_1_5448C(a);
    draw->draw = fn_1_57E84;
    draw->prim = 0xA8;
    draw->count = 2;
    draw->state = lbl_1_data_1C670;
    verts[0] = *a;
    verts[1] = *b;
    draw->verts = verts;
    lbl_8006DB74(draw->mtx);
    fn_1_5489C(list, draw);
}
/* fzgx:end fn_1_57BBC */

/* fzgx:begin fn_1_57CD0 */
void fn_1_57CD0(u16 n, AvVertex *src) {
    u32 size;
    AvLineDraw *draw;
    void *list;
    AvVertex *verts;

    if (n < 2) {
        return;
    }
    draw = fn_1_548AC(sizeof(AvLineDraw));
    if (draw == NULL) {
        return;
    }
    size = n * sizeof(AvVertex);
    verts = fn_1_548AC(size);
    if (verts == NULL) {
        return;
    }
    list = fn_1_5448C(src);
    draw->draw = fn_1_57E84;
    draw->prim = 0xA8;
    draw->count = n;
    draw->state = lbl_1_data_1C670;
    fn_80008BA8(verts, src, size);
    draw->verts = verts;
    lbl_8006DB74(draw->mtx);
    fn_1_5489C(list, draw);
}
/* fzgx:end fn_1_57CD0 */

/* fzgx:begin fn_1_57DC0 */
void fn_1_57DC0(void) {
    fn_800746A8(lbl_1_data_1C670.zMode, lbl_1_data_1C670.zFunc);
    fn_8007245C(0xA00);
    fn_800728A8(lbl_1_data_1C670.blendType, lbl_1_data_1C670.blendSrc, lbl_1_data_1C670.blendDst,
                lbl_1_data_1C670.blendOp);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xFF, 0xFF, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
}
/* fzgx:end fn_1_57DC0 */

/* fzgx:begin fn_1_57E84 */
void fn_1_57E84(AvLineDraw *draw) {
    AvLineState saved;
    AvVertex *v;
    s32 i;
    s32 count;

    saved = lbl_1_data_1C670;
    lbl_1_data_1C670 = draw->state;
    fn_1_57DC0(); /* retail inlines this same-TU function here */
    fn_80074918(1, 3, 1);
    GXLoadPosMtxImm(draw->mtx, 0);
    fn_8003462C(draw->prim, 0, draw->count);
    count = draw->count;
    v = draw->verts;
    for (i = 0; i < count; i++) {
        GXPosition3f32(v->x, v->y, v->z);
        GXColor4u8(v->color.r, v->color.g, v->color.b, v->color.a);
        v++;
    }
    lbl_1_data_1C670 = saved;
}
/* fzgx:end fn_1_57E84 */

/* fzgx:begin fn_1_58114 */
void fn_1_58114(void) {
    lbl_1_bss_6C840 = fn_1_45D0(lbl_801A6410, 100 * sizeof(AvLine), "avline.c", 0x39F);
}
/* fzgx:end fn_1_58114 */

/* fzgx:begin fn_1_58158 */
// fn_1_58158: loads global values and calls fn_1_46B4.
void fn_1_58158(void) {
    fn_1_46B4(lbl_801A6410, lbl_1_bss_6C840, "avline.c", 0x3A6);
}
/* fzgx:end fn_1_58158 */

/* fzgx:begin fn_1_5819C */
void fn_1_5819C(void) {
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_5819C */

/* fzgx:begin fn_1_581AC */
s32 fn_1_581AC(u16 zMode, u16 count, AvVertex *verts) {
    if (lbl_1_bss_6C844 == 100) {
        return 0;
    }
    lbl_1_bss_6C840[lbl_1_bss_6C844].zMode = zMode;
    lbl_1_bss_6C840[lbl_1_bss_6C844].count = count;
    fn_80008BA8(lbl_1_bss_6C840[lbl_1_bss_6C844].verts, verts, sizeof(lbl_1_bss_6C840->verts));
    lbl_1_bss_6C844++;
    return 1;
}
/* fzgx:end fn_1_581AC */

/* fzgx:begin fn_1_58248 */
static inline void AvLine_draw(u16 count, AvVertex *v) {
    s32 i;

    if (count >= 2) {
        fn_8003462C(0xB0, 0, count);
        for (i = 0; i < count; i++) {
            GXPosition3f32(v->x, v->y, v->z);
            GXColor4u8(v->color.r, v->color.g, v->color.b, v->color.a);
            v++;
        }
    }
}

void fn_1_58248(void) {
    s32 i;
    AvLine *line;

    lbl_1_data_1C670.blendType = 1;
    lbl_1_data_1C670.blendSrc = 1;
    lbl_1_data_1C670.blendDst = 1;
    lbl_1_data_1C670.blendOp = 0;
    lbl_8006DCA4();
    fn_80074918(1, 3, 1);
    fn_1_57DC0();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    for (i = 0; i < lbl_1_bss_6C844; i++) {
        line = &lbl_1_bss_6C840[i];
        lbl_1_data_1C670.zMode = line->zMode;
        AvLine_draw(line->count, line->verts);
    }
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_58248 */

/* fzgx:begin fn_1_584AC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"

extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, unsigned char *, u32);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u8 lbl_1_data_1D62C[148];
extern void fn_1_9F870(void);
extern void fn_1_58158(void);

// fn_1_584AC: linear congruential generator.
u32 fn_1_584AC(void) {
    u32 state = lbl_1_data_1D628;
    u32 next = state * 0x41c64e6du + 0x3039u;
    lbl_1_data_1D628 = next;
    return (next >> 16) & 0x7FFFu;
}
/* fzgx:end fn_1_584AC */
