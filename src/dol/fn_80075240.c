#include "types.h"
#include "psvec.h"

typedef struct { u32 dummy[8]; } GXTexObj;
typedef struct { u8 r, g, b, a; } GXColor;
typedef struct { f32 x, y, z; } Vec;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") u32 lbl_8019F040[0x38];
__declspec(section ".data") s32 lbl_8019F040_E0[3];
__declspec(section ".data") u32 lbl_8019F040_fill_8019F12C;
__declspec(section ".data") f32 lbl_8019F130[4];
__declspec(section ".data") Vec lbl_8019F130_10;
__declspec(section ".data") Vec lbl_8019F14C;
__declspec(section ".data") GXTexObj lbl_8019F158;
__declspec(section ".data") f32 lbl_8019F158_20[3][4];
__declspec(section ".data") u32 lbl_8019F158_fill_8019F1A8[6];
__declspec(section ".data") u8 lbl_8019F158_68[0x40];
__declspec(section ".data") GXTexObj lbl_8019F200;
__declspec(section ".data") u8 lbl_8019F200_20[0x4000];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_8019F040;
    s = *(u8 *)&lbl_8019F040_E0;
    s = *(u8 *)&lbl_8019F040_fill_8019F12C;
    s = *(u8 *)&lbl_8019F130;
    s = *(u8 *)&lbl_8019F130_10;
    s = *(u8 *)&lbl_8019F14C;
    s = *(u8 *)&lbl_8019F158;
    s = *(u8 *)&lbl_8019F158_20;
    s = *(u8 *)&lbl_8019F158_fill_8019F1A8;
    s = *(u8 *)&lbl_8019F158_68;
    s = *(u8 *)&lbl_8019F200;
    s = *(u8 *)&lbl_8019F200_20;
}
#pragma section code_type ".text"

extern const GXColor lbl_801A7928;
extern const GXColor lbl_801A7498;
extern s32 lbl_801A6D74;
extern s32 lbl_801A6D78;
extern s32 lbl_801A6D60;
extern s32 lbl_801A6D5C;
extern f32 lbl_801A6D70;
extern f32 lbl_801A6D6C;
extern f32 lbl_801A6D68;
extern s32 lbl_801A6D64;
extern s32 lbl_801A6D48;
extern s32 lbl_801A6D54;
extern GXColor lbl_801A6D50;
extern f32 lbl_801A6D4C;
extern s32 lbl_801A6D40;
extern s32 lbl_801A6D58;
extern s32 lbl_801A6D44;

extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(f32 (*)[4]);
extern void GXLoadTexMtxImm(f32 (*)[4], u32, u32);
extern void lbl_8006D668(Vec *);
extern void *memset(void *, int, u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(GXTexObj *, int, int, f32, f32, f32, u8, u8, int);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_800736C0(s32, GXColor);

extern const f32 lbl_801A7480;
extern const f32 lbl_801A7488;
extern const f32 lbl_801A749C;

static inline s32 texture_address(s32 offset, u32 base) {
    return offset + base;
}

void fn_80075240(void) {
    Vec up;
    GXColor black = lbl_801A7928;
    GXColor white = lbl_801A7498;
    s32 ty;
    s32 tx;
    s32 row;
    s32 col;
    s32 tile;
    s32 x;
    s32 n;
    struct { u32 value; } dst;
    u8 *pixel;

    lbl_8019F130[2] = 1.0f;
    lbl_8019F130[1] = 1.0f;
    lbl_8019F130[0] = 1.0f;
    lbl_801A6D74 = 1;
    lbl_801A6D78 = 0;
    lbl_8019F040_E0[0] = 0;
    lbl_8019F040_E0[1] = 0;
    lbl_8019F040_E0[2] = 0;
    lbl_8006D7F4(0.0f, 0.0f, 1.0f);
    lbl_8006DB74(lbl_8019F158_20);
    GXLoadTexMtxImm(lbl_8019F158_20, 0x21, 0);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    lbl_801A6D60 = -1;
    lbl_801A6D5C = -1;
    lbl_8019F14C = up;
    lbl_8006D668(&lbl_8019F14C);

    {
        f32 one;
        f32 zero;
        f32 neg;
        f32 *v;
        one = lbl_801A7488;
        neg = lbl_801A749C;
        zero = lbl_801A7480;
        v = (f32 *)&lbl_8019F130_10;
        lbl_801A6D70 = one;
        lbl_801A6D6C = one;
        lbl_801A6D68 = one;
        lbl_801A6D64 = 1;
        lbl_801A6D48 = 0;
        v[0] = zero;
        v[1] = zero;
        v[2] = neg;
    }

    memset(lbl_8019F158_68, 0xFF, 0x20);
    memset(lbl_8019F158_68 + 0x20, 0, 0x20);
    DCFlushRange(lbl_8019F158_68, 0x40);
    GXInitTexObj(&lbl_8019F200, lbl_8019F158_68, 16, 4, 1, 0, 0, 0);
    GXInitTexObjLOD(&lbl_8019F200, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);

    /* 64x64 RGBA8 texture in 4x4 texel tiles: AR block then GB block */
    dst.value = (u32)lbl_8019F200_20;
    for (ty = 0; ty < 16; ty++) {
        for (tx = 0; tx < 16; tx++) {
            tile = ty * 16 + tx;
            for (row = 0; row < 4; row++) {
                for (col = 0; col < 4; col++) {
                    x = tx * 4 + col;
                    n = row * 4 + col;
                    {
                        struct { s32 value; } offset;
                        s32 address;
                        offset.value = tile * 64 + n * 2;
                        address = offset.value;
                        address += dst.value;
                        *(u8 *)(address + 0) = 0;
                        *(u8 *)(address + 1) = 0;
                        *(u8 *)(address + 32) = (x & 0x3F) << 2;
                        *(u8 *)(address + 33) = (ty * 4 + row) << 2;
                    }
                }
            }
        }
    }
    DCFlushRange(lbl_8019F200_20, 0x4000);
    GXInitTexObj(&lbl_8019F158, lbl_8019F200_20, 64, 64, 6, 2, 2, 0);
    GXInitTexObjLOD(&lbl_8019F158, 3, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);

    lbl_801A6D54 = 0;
    lbl_801A6D50 = white;
    lbl_801A6D4C = 1.0f;
    fn_800728A8(0, 1, 0, 0);
    fn_800729B0(0, 0, 1, 2, 3);
    fn_800729B0(1, 0, 1, 2, 0);
    fn_800729B0(2, 0, 1, 2, 1);
    fn_800729B0(3, 0, 1, 2, 2);
    fn_800736C0(0, black);
    fn_800736C0(1, black);
    fn_800736C0(2, black);
    fn_800736C0(3, black);
    lbl_801A6D40 = 0;
    lbl_801A6D58 = 0;
    lbl_801A6D44 = 0;
}
