#include "types.h"

typedef struct Fn8006BE0CLight {
    u8 type;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    union {
        struct {
            s16 level;
            u16 angle;
            u32 unk_10;
            u32 unk_14;
            u8 unk_18;
            u8 unk_19;
        } t0;
        struct {
            s16 level;
            s16 unk_E;
            u16 angle;
        } t1;
        struct {
            u8 level;
            u8 pad_D;
            u16 angle;
            u16 count;
            u16 angle2;
            s16 unk_14;
            u16 pad_16;
            u32 unk_18;
            u32 unk_1C;
            u8 unk_20;
            u8 unk_21;
        } t2;
        struct {
            s8 center;
            u8 width;
            u8 unk_E;
            u8 unk_F;
            s16 unk_10;
            s16 unk_12;
        } t7;
        u8 raw[0x1C];
    } u;
    u32 flags;
    u8 pad_2C[0xC];
    s32 lo;
    s32 hi;
} Fn8006BE0CLight;

#define CLAMP_S(x) ((x) < -255 ? -255 : (x))
#define CLAMP_H(x) ((x) > 255 ? 255 : (x))
/* angle in degrees to a 0..255 fraction of a turn */
#define WRAP_ANGLE(a) ((((a) % 360) << 8) / 360)

#pragma optimize_for_size on
#pragma scheduling on

s32 fn_8006BE0C(Fn8006BE0CLight *__restrict dst, Fn8006BE0CLight *__restrict src) {
    s32 result;
    s32 type;
    s32 t;

    result = 0;
    type = src->type;
    dst->type = type;
    dst->unk_4 = src->unk_4;
    dst->unk_8 = src->unk_8;

    switch (type) {
    case 0:
        dst->flags |= 0x14;
        t = CLAMP_S(src->u.t0.level);
        dst->u.t0.level = CLAMP_H(t);
        dst->u.t0.angle = WRAP_ANGLE(src->u.t0.angle);
        dst->u.t0.unk_10 = src->u.t0.unk_10;
        dst->u.t0.unk_14 = src->u.t0.unk_14;
        dst->u.t0.unk_18 = CLAMP_H((s32)src->u.t0.unk_18);
        dst->u.t0.unk_19 = CLAMP_H((s32)src->u.t0.unk_19);
        break;
    case 1:
        dst->flags |= 0x24;
        t = CLAMP_S(src->u.t1.level);
        dst->u.t1.level = CLAMP_H(t);
        t = CLAMP_S(src->u.t1.unk_E);
        dst->u.t1.unk_E = CLAMP_H(t);
        dst->u.t1.angle = WRAP_ANGLE(src->u.t1.angle);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        dst->flags |= 0x44;
        dst->u.t2.level = CLAMP_H((s32)src->u.t2.level);
        dst->u.t2.angle = WRAP_ANGLE(src->u.t2.angle);
        dst->u.t2.count = src->u.t2.count < 2 ? 2 : src->u.t2.count;
        dst->u.t2.angle2 = WRAP_ANGLE(src->u.t2.angle2);
        t = CLAMP_S(src->u.t2.unk_14);
        dst->u.t2.unk_14 = CLAMP_H(t);
        dst->u.t2.unk_18 = src->u.t2.unk_18;
        dst->u.t2.unk_1C = src->u.t2.unk_1C;
        dst->u.t2.unk_20 = CLAMP_H((s32)src->u.t2.unk_20);
        dst->u.t2.unk_21 = CLAMP_H((s32)src->u.t2.unk_21);
        if (dst->u.t2.count < 4) {
            dst->u.t2.angle2 = 0x40;
        }
        break;
    case 7:
    case 8:
        dst->flags |= 0x80;
        dst->u.t7.center = src->u.t7.center;
        dst->u.t7.width = src->u.t7.width;
        t = CLAMP_S(src->u.t7.unk_12);
        dst->u.t7.unk_12 = CLAMP_H(t);
        t = CLAMP_S(src->u.t7.unk_10);
        dst->u.t7.unk_10 = CLAMP_H(t);
        dst->u.t7.unk_E = (u32)src->u.t7.unk_E >> 1;
        dst->u.t7.unk_F = (u32)src->u.t7.unk_F >> 1;
        dst->lo = (dst->u.t7.center - ((u32)dst->u.t7.width >> 1)) << 12;
        dst->hi = (dst->u.t7.center + ((u32)dst->u.t7.width >> 1)) << 12;
        break;
    default:
        result = -2;
        break;
    }
    return result;
}

#pragma optimize_for_size reset
