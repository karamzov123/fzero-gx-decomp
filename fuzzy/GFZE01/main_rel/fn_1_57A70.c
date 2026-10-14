/* Non-matching: best partial attempt (96.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void *lbl_801A6D00;
extern void fn_1_57DC0(void);
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_8003462C(u32, u32, u32);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} ColorVertex;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

volatile WGPipe GXWGFifo : 0xCC008000; /* fzgx-allow: A1 write-gather FIFO port */

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

void fn_1_57A70(u32 count, ColorVertex *verts) {
    ColorVertex *p;
    s32 n;

    if ((u16)count < 2) {
        return;
    }
    fn_1_57DC0();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xb0, 0, count);

    p = verts;
    n = (u16)count;
    while (n > 0) {
        GXPosition3f32(p->x, p->y, p->z);
        GXColor4u8(p->r, p->g, p->b, p->a);
        p++;
        n--;
    }
}
