#include <types.h>
#include "sdk_addresses.h"

typedef enum _GXFogType {
    GX_FOG_NONE = 0,
} GXFogType;

typedef struct _GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef struct _GXData {
    u16 vNumNot;
    u16 bpSentNot;
} GXData;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

extern GXData *const gx;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | ((u32)(val) << shift))

void fn_800377F8(GXFogType type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color) {
    u32 fogclr;
    u32 fog0;
    u32 fog1;
    u32 fog2;
    u32 fog3;
    f32 A;
    f32 B;
    f32 B_mant;
    f32 C;
    f32 a;
    f32 c;
    s32 B_expn;
    u32 b_m;
    u32 b_s;
    u32 a_hex;
    u32 c_hex;
    u32 fsel;
    u32 proj;

    fog0 = 0;
    fog1 = 0;
    fog2 = 0;
    fog3 = 0;
    fogclr = 0;

    fsel = type & 7;
    proj = (type >> 3) & 1;

    if (proj) {
        if (farz == nearz || endz == startz) {
            a = 0.0f;
            c = 0.0f;
        } else {
            A = 1.0f / (endz - startz);
            a = A * (farz - nearz);
            c = A * (startz - nearz);
        }
    } else {
        if (farz == nearz || endz == startz) {
            A = 0.0f;
            B = 0.5f;
            C = 0.0f;
        } else {
            A = (farz * nearz) / ((farz - nearz) * (endz - startz));
            B = farz / (farz - nearz);
            C = startz / (endz - startz);
        }

        B_mant = B;
        B_expn = 0;
        while (B_mant > 1.0) {
            B_mant /= 2;
            B_expn++;
        }
        while (B_mant > 0 && B_mant < 0.5) {
            B_mant *= 2;
            B_expn--;
        }

        a = A / (1 << (B_expn + 1));
        b_m = (8.388638e6f * B_mant);
        b_s = B_expn + 1;
        c = C;

        SET_REG_FIELD(fog1, 24, 0, b_m);
        SET_REG_FIELD(fog1, 8, 24, 0xEF);
        SET_REG_FIELD(fog2, 24, 0, b_s);
        SET_REG_FIELD(fog2, 8, 24, 0xF0);
    }

    a_hex = *(u32 *)&a;
    c_hex = *(u32 *)&c;

    SET_REG_FIELD(fog0, 11, 0, (a_hex >> 12) & 0x7FF);
    SET_REG_FIELD(fog0, 8, 11, (a_hex >> 23) & 0xFF);
    SET_REG_FIELD(fog0, 1, 19, (a_hex >> 31));
    SET_REG_FIELD(fog0, 8, 24, 0xEE);

    SET_REG_FIELD(fog3, 11, 0, (c_hex >> 12) & 0x7FF);
    SET_REG_FIELD(fog3, 8, 11, (c_hex >> 23) & 0xFF);
    SET_REG_FIELD(fog3, 1, 19, (c_hex >> 31));
    SET_REG_FIELD(fog3, 1, 20, proj);
    SET_REG_FIELD(fog3, 3, 21, fsel);
    SET_REG_FIELD(fog3, 8, 24, 0xF1);

    SET_REG_FIELD(fogclr, 8, 0, color.b);
    SET_REG_FIELD(fogclr, 8, 8, color.g);
    SET_REG_FIELD(fogclr, 8, 16, color.r);
    SET_REG_FIELD(fogclr, 8, 24, 0xF2);

    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = fog0;
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = fog1;
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = fog2;
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = fog3;
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = fogclr;

    gx->bpSentNot = 0;
}
