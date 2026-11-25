#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/gx/GXPriv.h"

typedef struct RenderVec {
    f32 x;
    f32 y;
    f32 z;
} RenderVec;

typedef struct RenderQuat {
    u8 data[0x10];
} RenderQuat;

typedef union RenderColor {
    GXColor c;
    u32 word;
} RenderColor;

typedef union FloatBits {
    f32 f;
    u32 u;
} FloatBits;

typedef struct RenderRect {
    f32 z;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    s32 mode;
    GXColor color;
    s32 show_corners;
    RenderVec corners[4];
} RenderRect;

extern GXColor lbl_801A6408;
extern s32 lbl_801A6728;
extern s32 lbl_801A66A0;
extern void *lbl_801A6D00;
extern GXColor lbl_801A7910;
extern GXColor lbl_801A7914;

extern void fn_8003462C(u32, u32, u32);
extern f32 lbl_8006D188(s32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D758(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBAC(void *);
extern void fn_8006E5FC(RenderQuat *);
extern void fn_8006EB4C(RenderQuat *, RenderQuat *, RenderQuat *, f32);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_80072558(void);
extern void fn_800725DC(GXColor);
extern void fn_80072614(GXColor);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_800736C0(s32, GXColor);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800744F8(GXColor, u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_800746A8(u32, u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800791E8(void *, void *, u32);
extern void fn_800793D4(void *, int, u32);
extern void fn_800794F0(void *, void *, u32);
extern void GXGetProjectionv(f32 *);
extern void GXLoadPosMtxImm(void *, u32);
extern void PSMTXQuat(void *, RenderQuat *);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);

void fn_80008204(GXColor *color);
void fn_800087F4(void *texture, RenderRect *rect);
void fn_80008A4C(RenderRect *rect);

u32 fn_80007CDC(f32 *arg0) {
    u32 flags[2];
    FloatBits value0;
    FloatBits value1;
    FloatBits value2;

    flags[0] = 1;
    flags[1] = flags[0];
    value0.f = arg0[0];
    if ((value0.u & 0x7F800000) != 0x7F800000) {
        value1.f = arg0[1];
        if ((value1.u & 0x7F800000) != 0x7F800000) {
            flags[1] = 0;
        }
    }
    if ((s32)flags[1] == 0) {
        value2.f = arg0[2];
        if ((value2.u & 0x7F800000) != 0x7F800000) {
            flags[0] = 0;
        }
    }
    return flags[0];
}

u32 fn_80007D58(f32 *arg0) {
    u32 flags[11];
    FloatBits value3;
    FloatBits value7;
    FloatBits value11;
    FloatBits value0;
    FloatBits value1;
    FloatBits value2;
    FloatBits value4;
    FloatBits value5;
    FloatBits value6;
    FloatBits value8;
    FloatBits value9;
    FloatBits value10;

    flags[0] = 1;
    flags[1] = flags[0];
    flags[2] = flags[0];
    flags[3] = flags[0];
    flags[4] = flags[0];
    flags[5] = flags[0];
    flags[6] = flags[0];
    flags[7] = flags[0];
    flags[8] = flags[0];
    flags[9] = flags[0];
    flags[10] = flags[0];
    value0.f = arg0[0];
    if ((value0.u & 0x7F800000) != 0x7F800000) {
        value1.f = arg0[1];
        if ((value1.u & 0x7F800000) != 0x7F800000) {
            flags[10] = 0;
        }
    }
    if ((s32)flags[10] == 0) {
        value2.f = arg0[2];
        if ((value2.u & 0x7F800000) != 0x7F800000) flags[9] = 0;
    }
    if ((s32)flags[9] == 0) {
        value4.f = arg0[4];
        if ((value4.u & 0x7F800000) != 0x7F800000) flags[8] = 0;
    }
    if ((s32)flags[8] == 0) {
        value5.f = arg0[5];
        if ((value5.u & 0x7F800000) != 0x7F800000) flags[7] = 0;
    }
    if ((s32)flags[7] == 0) {
        value6.f = arg0[6];
        if ((value6.u & 0x7F800000) != 0x7F800000) flags[6] = 0;
    }
    if ((s32)flags[6] == 0) {
        value8.f = arg0[8];
        if ((value8.u & 0x7F800000) != 0x7F800000) flags[5] = 0;
    }
    if ((s32)flags[5] == 0) {
        value9.f = arg0[9];
        if ((value9.u & 0x7F800000) != 0x7F800000) flags[4] = 0;
    }
    if ((s32)flags[4] == 0) {
        value10.f = arg0[10];
        if ((value10.u & 0x7F800000) != 0x7F800000) flags[3] = 0;
    }
    if ((s32)flags[3] == 0) {
        value3.f = arg0[3];
        if ((value3.u & 0x7F800000) != 0x7F800000) flags[2] = 0;
    }
    if ((s32)flags[2] == 0) {
        value7.f = arg0[7];
        if ((value7.u & 0x7F800000) != 0x7F800000) flags[1] = 0;
    }
    if ((s32)flags[1] == 0) {
        value11.f = arg0[11];
        if ((value11.u & 0x7F800000) != 0x7F800000) flags[0] = 0;
    }
    return flags[0];
}

u32 fn_80007F70(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3) {
    RenderColor result;
    f32 blend;
    f32 r, g, b, a;
    u8 temp;

    blend = 0.5f * (1.0f + lbl_8006D188((s16)(arg3 * ((arg2 & 63) << 10))));
    if (arg0[0] < arg1[0]) {
        temp = arg1[0]; arg1[0] = arg0[0]; arg0[0] = temp;
        r = 1.0 - blend;
    } else r = blend;
    if (arg0[1] < arg1[1]) {
        temp = arg1[1]; arg1[1] = arg0[1]; arg0[1] = temp;
        g = 1.0 - blend;
    } else g = blend;
    if (arg0[2] < arg1[2]) {
        temp = arg1[2]; arg1[2] = arg0[2]; arg0[2] = temp;
        b = 1.0 - blend;
    } else b = blend;
    if (arg0[3] < arg1[3]) {
        temp = arg1[3]; arg1[3] = arg0[3]; arg0[3] = temp;
        a = 1.0 - blend;
    } else a = blend;
    result.c.r = arg0[0] - (u8)(r * ((f32)arg0[0] - arg1[0]));
    result.c.g = arg0[1] - (u8)(g * ((f32)arg0[1] - arg1[1]));
    result.c.b = arg0[2] - (u8)(b * ((f32)arg0[2] - arg1[2]));
    result.c.a = arg0[3] - (u8)(a * ((f32)arg0[3] - arg1[3]));
    return result.word;
}

u32 fn_800081C8(GXColor arg0, GXColor arg1, f32 arg2) {
    GXColor color0;
    GXColor color1;

    color1 = arg1;
    color0 = arg0;
    return fn_80007F70((u8 *)&color0, (u8 *)&color1, lbl_801A66A0, arg2);
}

static inline void RenderPosition(f32 x, f32 y, f32 z) {
    GX_WRITE_F32(x);
    GX_WRITE_F32(y);
    GX_WRITE_F32(z);
}

static inline void RenderTexCoord(f32 s, f32 t) {
    GX_WRITE_F32(s);
    GX_WRITE_F32(t);
}

/* A plain static helper: its literals take their pool position here, before fn_80008204's, and every call is inlined. */
static void RenderTexturedQuad(RenderRect *rect, f32 left, f32 top, f32 right, f32 bottom) {
    RenderPosition(left, top, rect->z);
    RenderTexCoord(0.0f, 0.0f);
    RenderPosition(right, top, rect->z);
    RenderTexCoord(1.0f, 0.0f);
    RenderPosition(right, bottom, rect->z);
    RenderTexCoord(1.0f, 1.0f);
    RenderPosition(left, bottom, rect->z);
    RenderTexCoord(0.0f, 1.0f);
}

void fn_80008204(GXColor *color) {
    GXColor c = *color;
    f32 proj[7];
    f32 n;
    f32 x0;
    f32 sx;
    f32 sy;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 z;
    f32 sx_2;

    fn_8007245C(0x200);
    fn_80072864(0);
    fn_80073C6C(0);
    fn_80073620(0, 0x1c);
    fn_800735C8(0, 0xc);
    fn_800736C0(0, c);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_800725DC(lbl_801A7910);
    fn_80072614(lbl_801A7914);
    fn_80072C24(0, 0xf, 0xf, 0xf, 0xe);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 6);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_800728A8(0, 1, 0, 0);
    fn_80074918(1, 7, 1);
    fn_800720B0(0);
    GXGetProjectionv(proj);

    n = proj[6] / proj[5];
    switch ((u32)proj[0]) {
    case 0:
        z = -(n - (n - proj[6] / (proj[5] - 1.0f)) / 16777216.0f);
        sx = z / proj[1];
        x0 = (1.0f - proj[2]) * sx;
        x1 = (-1.0f - proj[2]) * sx;
        sy = z / proj[3];
        y0 = (1.0f - proj[4]) * sy;
        y1 = (-1.0f - proj[4]) * sy;
        break;
    default:
        z = -(n - (n - -(1.0f + proj[6]) / proj[5]) / 16777216.0f);
        sx_2 = 1.0f / proj[1];
        x0 = (1.0f - proj[2]) * sx_2;
        x1 = (-1.0f - proj[2]) * sx_2;
        sy = 1.0f / proj[3];
        y0 = (1.0f - proj[4]) * sy;
        y1 = (-1.0f - proj[4]) * sy;
        break;
    }

    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    fn_8003462C(0x80, 0, 4);
    GX_WRITE_F32(x1);
    GX_WRITE_F32(y0);
    GX_WRITE_F32(z);
    GX_WRITE_F32(x0);
    GX_WRITE_F32(y0);
    GX_WRITE_F32(z);
    GX_WRITE_F32(x0);
    GX_WRITE_F32(y1);
    GX_WRITE_F32(z);
    GX_WRITE_F32(x1);
    GX_WRITE_F32(y1);
    GX_WRITE_F32(z);
}

void fn_800084E8(void *texture, RenderRect *rect) {
    f32 viewport[6];
    f32 sx;
    f32 sy;
    f32 z;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;

    fn_800087F4(texture, rect);
    lbl_8006DAEC();
    lbl_8006D758();
    fn_80072558();
    lbl_8006DB30();
    GXGetProjectionv(viewport);
    sx = -1.0f / viewport[1];
    sy = 1.0f / viewport[3];
    left = sx * (rect->left * rect->z);
    right = sx * (rect->right * rect->z);
    top = sy * (rect->top * rect->z);
    bottom = sy * (rect->bottom * rect->z);

    fn_8003462C(0x80, 0, 4);
    RenderTexturedQuad(rect, left, top, right, bottom);

    fn_80008A4C(rect);
    z = rect->z;
    fn_8003462C(0xB0, 0, 5);
    RenderPosition(left, top, z);
    RenderPosition(right, top, z);
    RenderPosition(right, bottom, z);
    RenderPosition(left, bottom, z);
    RenderPosition(left, top, z);

    if (rect->show_corners != 0) {
        fn_8003462C(0xB0, 0, 5);
        RenderPosition(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);
        RenderPosition(rect->corners[1].x, rect->corners[1].y, rect->corners[1].z);
        RenderPosition(rect->corners[2].x, rect->corners[2].y, rect->corners[2].z);
        RenderPosition(rect->corners[3].x, rect->corners[3].y, rect->corners[3].z);
        RenderPosition(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);

        fn_8003462C(0xA8, 0, 8);
        RenderPosition(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);
        RenderPosition(left, top, z);
        RenderPosition(rect->corners[1].x, rect->corners[1].y, rect->corners[1].z);
        RenderPosition(right, top, z);
        RenderPosition(rect->corners[2].x, rect->corners[2].y, rect->corners[2].z);
        RenderPosition(right, bottom, z);
        RenderPosition(rect->corners[3].x, rect->corners[3].y, rect->corners[3].z);
        RenderPosition(left, bottom, z);
    }
}

void fn_800087F4(void *texture, RenderRect *rect) {
    GXColor color;

    fn_80073778(texture, 0);
    fn_800728A8(0, 1, 0, 0);
    fn_80074918(1, 3, 1);
    fn_800720B0(0);
    fn_80072864(0);
    switch (rect->mode) {
    case 0:
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
        fn_800734A8(0, 0, 0, 0xFF);
        fn_80073620(0, 0);
        fn_80072C24(0, 0xF, 8, 0xC, 0xF);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 6);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80073678(1);
        fn_80074660(1);
        fn_80073898(0);
        fn_80074788(0);
        break;
    case 1:
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
        fn_800734A8(0, 0, 0, 0xFF);
        color.r = 0xFF;
        color.g = 0;
        color.b = 0;
        fn_800736C0(0, color);
        fn_800735C8(0, 0xC);
        fn_80073620(0, 0);
        fn_80072C24(0, 0xE, 0xF, 9, 0xF);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 6);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80073678(1);
        fn_80074660(1);
        fn_80073898(0);
        fn_80074788(0);
        break;
    }
    fn_8007245C(0x2200);
}

void fn_80008A4C(RenderRect *rect) {
    fn_800728A8(0, 1, 0, 0);
    fn_80074918(1, 3, 1);
    fn_800720B0(0);
    fn_800746A8(6, 0);
    fn_80072864(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_800736C0(0, rect->color);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 6);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80073898(0);
    fn_80074788(0);
    fn_8007245C(512);
}

void fn_80008BA8(void *dst, void *src, u32 size) {
    u32 bits = (u32)src | (u32)dst;

    if (bits & 3) {
        memcpy(dst, src, size);
    } else if (bits & 0x1F) {
        fn_800794F0(dst, src, size);
    } else {
        fn_800791E8(dst, src, size);
    }
}

void fn_80008BEC(void *dest, int value, u32 size) {
    if (((u32)dest & 0x1F) == 0) {
        fn_800793D4(dest, value, size);
    } else {
        memset(dest, (u8)value, size);
    }
}

static inline void RenderCross(RenderVec *a, RenderVec *b, RenderVec *out) {
    f32 ax;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;

    ax = a->x;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* WARNING: compiler-diff device, not original code. Retail register order needs copy propagation off. */
#pragma opt_propagation off
void fn_80008C20(RenderVec *arg0, RenderVec *arg1, RenderVec *arg2) {
    RenderVec t;
    RenderVec t2;
    RenderVec v;
    f32 *p;

    v.x = -arg2->x;
    v.y = -arg2->y;
    v.z = -arg2->z;
    if (lbl_8006D668(&v) == 0.0f) {
        lbl_8006D7DC(arg0);
        return;
    }
    RenderCross(arg1, &v, &t);
    if (lbl_8006D668(&t) == 0.0f) {
        lbl_8006D7DC(arg0);
        return;
    }
    RenderCross(&v, &t, &t2);
    if (lbl_8006D668(&t2) == 0.0f) {
        lbl_8006D7DC(arg0);
        return;
    }
    p = (f32 *)lbl_801A6D00;
    p[0] = t.x;
    p[1] = t2.x;
    p[2] = v.x;
    p[3] = arg0->x;
    p[4] = t.y;
    p[5] = t2.y;
    p[6] = v.y;
    p[7] = arg0->y;
    p[8] = t.z;
    p[9] = t2.z;
    p[10] = v.z;
    p[11] = arg0->z;
}

#pragma opt_propagation reset

void fn_80008DB4(void *first, f32 amount, void *second, void *out) {
    RenderQuat a;
    RenderQuat b;
    RenderQuat result;

    lbl_8006DBAC(first);
    fn_8006E5FC(&a);
    lbl_8006DBAC(second);
    fn_8006E5FC(&b);
    fn_8006EB4C(&result, &a, &b, amount);
    PSMTXQuat(out, &result);
}

#if defined(VERSION_GFZE01)
void fn_80008E30(void) {
}
#endif
