#include "types.h"
/* begin dolphin/gx.h (deltawave784/fzgx, CC0) */
#ifndef DOLPHIN_GX_H
#define DOLPHIN_GX_H

#include "dolphin/types.h"
#include "dolphin/hw_regs.h"

/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE (dolphin/hw_regs.h), written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;
typedef PPCWGPipe WGPipe;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE; /* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))
#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))
#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))
#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */
#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */
#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

#endif

/* end dolphin/gx.h */

typedef struct {
    u32 attr;
    u32 type;
} GXVtxDescList;

typedef struct {
    u32 attr;
    u32 cnt;
    u32 type;
    u8 frac;
} GXVtxAttrFmtList;

typedef enum {
    GX_NONE,
    GX_DIRECT,
    GX_INDEX8,
    GX_INDEX16
} GXAttrType;

/* saved vertex state: descriptor list followed by the VTXFMT3 attribute list */
static GXVtxDescList lbl_80178118[27];
static GXVtxAttrFmtList lbl_80178118__fzgx_offset_D8[27];

extern f32 fn_80088600(f32); /* sinf */
extern f32 fn_80088624(f32); /* cosf */
extern void GXClearVtxDesc(void);
extern void GXGetVtxDesc(u32 attr, GXAttrType *type);
extern void fn_80032EB8(GXVtxDescList *list); /* GXGetVtxDescv */
extern void GXGetVtxAttrFmtv(u32 fmt, GXVtxAttrFmtList *list);
extern void GXSetVtxDesc(u32 attr, u32 type);
extern void GXSetVtxAttrFmt(u32 fmt, u32 attr, u32 cnt, u32 type, u8 frac);
extern void GXSetVtxDescv(GXVtxDescList *list);
extern void GXSetVtxAttrFmtv(u32 fmt, GXVtxAttrFmtList *list);
extern void fn_8003462C(u32 prim, u32 fmt, u16 nverts); /* GXBegin */

#define GXWGFifo_f32 GXWGFifo.f32

#define PI 3.14159265358979323846F

void fn_800384FC(u8 numMajor, u8 numMinor) {
    GXAttrType ttype;
    f32 radius = 1.0F;
    f32 majorStep = PI / numMajor;
    f32 minorStep = 2.0F * PI / numMinor;
    s32 i;
    s32 j;
    f32 a;
    f32 b;
    f32 r0;
    f32 r1;
    f32 z0;
    f32 z1;
    f32 c;
    f32 x;
    f32 y;

    GXGetVtxDesc(13, &ttype);
    fn_80032EB8(lbl_80178118);
    GXGetVtxAttrFmtv(3, lbl_80178118__fzgx_offset_D8);

    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(10, 1);
    GXSetVtxAttrFmt(3, 9, 1, 4, 0);
    GXSetVtxAttrFmt(3, 10, 0, 4, 0);
    if (ttype != GX_NONE) {
        GXSetVtxDesc(13, 1);
        GXSetVtxAttrFmt(3, 13, 1, 4, 0);
    }

    for (i = 0; i < numMajor; i++) {
        a = i * majorStep;
        b = a + majorStep;

        r0 = radius * fn_80088600(a);
        r1 = radius * fn_80088600(b);
        z0 = radius * fn_80088624(a);
        z1 = radius * fn_80088624(b);

        fn_8003462C(0x98, 3, (u16)((numMinor + 1) * 2));
        for (j = 0; j <= numMinor; j++) {
            c = j * minorStep;
            x = fn_80088624(c);
            y = fn_80088600(c);

            GXWGFifo_f32 = x * r1;
            GXWGFifo_f32 = y * r1;
            GXWGFifo_f32 = z1;
            GXWGFifo_f32 = (x * r1) / radius;
            GXWGFifo_f32 = (y * r1) / radius;
            GXWGFifo_f32 = z1 / radius;
            if (ttype != GX_NONE) {
                GXWGFifo_f32 = (f32)j / (f32)numMinor;
                GXWGFifo_f32 = (f32)(i + 1) / (f32)numMajor;
            }

            GXWGFifo_f32 = x * r0;
            GXWGFifo_f32 = y * r0;
            GXWGFifo_f32 = z0;
            GXWGFifo_f32 = (x * r0) / radius;
            GXWGFifo_f32 = (y * r0) / radius;
            GXWGFifo_f32 = z0 / radius;
            if (ttype != GX_NONE) {
                GXWGFifo_f32 = (f32)j / (f32)numMinor;
                GXWGFifo_f32 = (f32)i / (f32)numMajor;
            }
        }
    }

    GXSetVtxDescv(lbl_80178118);
    GXSetVtxAttrFmtv(3, lbl_80178118__fzgx_offset_D8);
}
