#ifndef FZERO_DOLPHIN_GX_H
#define FZERO_DOLPHIN_GX_H

/*
 * GFZE01 GX ABI slice. Second header pilot after CARD and EXI, and grown the
 * same way: a type appears here when a conversion will not compile without it,
 * with the retail access that pins it cited alongside.
 *
 * The base typedefs match what the GX units already declared inline
 * (`unsigned int` for u32, not `unsigned long`) so adopting this header cannot
 * change their codegen. That differs from <dolphin/exi.h> on purpose -- the
 * dolsdk EXI reference bodies spell s32 parameters `long`, the GX ones do not.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 4 bytes, r/g/b/a: GXSetChanAmbColor reads `.a` as `lbz r7, 3(r4)`. */
typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

/*
 * Channel ids, read off GXSetChanAmbColor's switch: 0/1 take the colour from
 * the argument and the alpha from the stored register, 2/3 do the reverse, and
 * 4/5 take the whole word.
 */
typedef enum GXChannelID {
    GX_COLOR0 = 0,
    GX_COLOR1 = 1,
    GX_ALPHA0 = 2,
    GX_ALPHA1 = 3,
    GX_COLOR0A0 = 4,
    GX_COLOR1A1 = 5,
    GX_COLOR_ZERO = 6,
    GX_ALPHA_BUMP = 7,
    GX_ALPHA_BUMPN = 8,
    GX_COLOR_NULL = 0xFF
} GXChannelID;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
} __GXFifoInt;

#define GXWGFifo ((volatile __GXFifoInt *)0xCC008000)

#define GX_WRITE_RAS_REG(reg)       \
    do {                            \
        GXWGFifo->u8 = 0x61;        \
        GXWGFifo->u32 = (u32)(reg); \
    } while (0)

/*
 * XF register write: `li r0, 0x10` / `addi r3, r5, 0x100a` in
 * GXSetChanAmbColor, i.e. the 0x1000 transform-unit base plus the register
 * index, with a single-word payload.
 */
#define GX_WRITE_XF_REG(addr, val)          \
    do {                                    \
        GXWGFifo->u8 = 0x10;                \
        GXWGFifo->u32 = 0x1000 + (addr);    \
        GXWGFifo->u32 = (u32)(val);         \
    } while (0)

#define SET_REG_FIELD(reg, size, pos, val) \
    ((reg) = (((u32)(reg)) & ~((((1 << (size)) - 1)) << (pos))) | ((u32)(val) << (pos)))

#endif
