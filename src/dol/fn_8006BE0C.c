#include "types.h"


/* --- dol/fn_8006BE0C.c --- */
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

s32 fn_8006BE0C(Fn8006BE0CLight *dst, const Fn8006BE0CLight *src) {
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

/* --- dol/fn_8006C134.c --- */
/* --- dol/fn_8006C134.c --- */
struct fn_8006C134_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x6];
    u16 unk_12;
    u8 pad_14[0x14];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u8 pad_34[0x4];
    u32 unk_38;
};

s32 fn_8006C134(struct fn_8006C134_Arg0 *arg0) {
    arg0->unk_28 = (arg0->unk_28 | 1);
    arg0->unk_28 = (arg0->unk_28 & 0xFFFFFFFD);
    arg0->unk_2C = 0;
    arg0->unk_30 = arg0->unk_8;
    if ((arg0->unk_28 & 0x40) != 0) {
    arg0->unk_38 = (arg0->unk_12 << 16);
    }
    return 0;
}

/* --- dol/fn_8006C17C.c --- */
struct fn_8006C17C_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
};

s32 fn_8006C17C(struct fn_8006C17C_Arg0 *arg0) {
    arg0->unk_28 = (arg0->unk_28 & ~0x1);
    return 0;
}

/* --- dol/fn_8006C190.c --- */
struct Sig_fn_8006C634_fn_8006C634_Arg2 { u32 unk_0; };
struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 {
    u8 pad_0[0x24]; u32 unk_24; u8 pad_28[0x10]; u32 unk_38; u32 unk_3C;
};
struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 {
    u8 pad_0[2]; u8 unk_2; u8 unk_3; s16 unk_4; s16 unk_6;
};
struct fn_8006C190_Arg0 {
    u8 unk_0; u8 pad_1[3]; u32 unk_4; u32 unk_8;
    s16 unk_C; u16 unk_E; u16 unk_10; u16 unk_12;
    s16 unk_14; u8 pad_16[0x12]; u32 unk_28;
    u32 unk_2C; u32 unk_30; u32 unk_34; u32 unk_38;
};
struct fn_8006C634_lbl_8019E014 { s16 unk_0[1]; };
extern struct fn_8006C634_lbl_8019E014 lbl_8019E014[];
extern struct fn_8006C634_lbl_8019E014 lbl_8019E094[];
extern s32 fn_8006C6E8(struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 *, struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 *);
extern u32 fn_8006C570(struct fn_8006C190_Arg0 *, void *, s32);
extern s32 fn_8006C788(struct fn_8006C190_Arg0 *, void *);
extern void fn_8006C634(u32, u32, struct Sig_fn_8006C634_fn_8006C634_Arg2 *);

static inline s32 fn_8006C190_ramp(s32 current, s32 duration, s32 start, s32 end) {
    s32 round;
    s32 difference;
    difference = end - start;
    round = duration / 2;
    if (difference < 0) round = -round;
    difference = difference * current;
    difference += round;
    return start + difference / duration;
}

s32 fn_8006C190(struct fn_8006C190_Arg0 *arg0, u32 arg1) {
    s32 v4;
    u32 v10;
    s16 v9;
    s32 v8;
    s32 v17;
    struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 * lab_t1;
    if (arg0->unk_28 & 1) {
        if (arg0->unk_30 != 0) {
            arg0->unk_30 -= arg1;
            if ((s32)arg0->unk_30 < 0) arg0->unk_30 = 0;
        } else {
            arg0->unk_2C += arg1;
            if (arg0->unk_4 != -1 && arg0->unk_4 < arg0->unk_2C) {
                if (arg0->unk_28 & 2) arg0->unk_28 &= ~1;
            }
        }
    }
    arg0->unk_28 |= 2;
    v4 = 0;
    if ((arg0->unk_28 & 1) && arg0->unk_30 == 0) v4 = 1;
    if (v4) {
        if (arg0->unk_28 & 0x10) {
            v4 = fn_8006C570(arg0, &arg0->unk_10, arg0->unk_C);
            fn_8006C634(v4, arg0->unk_E, (struct Sig_fn_8006C634_fn_8006C634_Arg2 *)&arg0->unk_34);
        } else if (arg0->unk_28 & 0x20) {
            v4 = fn_8006C190_ramp(arg0->unk_2C, arg0->unk_4, arg0->unk_C, *(s16 *)&arg0->unk_E);
            fn_8006C634(v4, arg0->unk_10, (struct Sig_fn_8006C634_fn_8006C634_Arg2 *)&arg0->unk_34);
        } else if (arg0->unk_28 & 0x40) {
            arg1 = (arg1 << 24) / arg0->unk_10;
            arg0->unk_38 += arg1;
            if (arg0->unk_38 >= 0x1000000) arg0->unk_38 -= arg0->unk_38 & ~0xFFFFFF;
            v9 = fn_8006C570(arg0, (u8 *)arg0 + 0x18, *(u8 *)&arg0->unk_C);
            switch (arg0->unk_0) {
            case 2:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 64) v4 = lbl_8019E014[0].unk_0[v10];
                else if (v10 < 128) v4 = lbl_8019E014[0].unk_0[127-v10];
                else if (v10 < 192) v4 = -(*((0) + (lbl_8019E014))).unk_0[v10-128];
                else v4 = -lbl_8019E014[0].unk_0[255-v10];
                v8 = v4;
                break;
            case 3:
                v8 = -1024;
                if ((arg0->unk_38 >> 16) < 128) v8 = 1024;
                break;
            case 4:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 64) v4 = lbl_8019E094[0].unk_0[v10];
                else if (v10 < 128) v4 = lbl_8019E094[0].unk_0[127-v10];
                else if (v10 < 192) v4 = -lbl_8019E094[0].unk_0[v10-128];
                else v4 = -lbl_8019E094[0].unk_0[255-v10];
                v8 = v4;
                break;
            case 5: v8 = lbl_8019E094[0].unk_0[(arg0->unk_38 >> 18) & 63]; break;
            case 6: v8 = lbl_8019E094[0].unk_0[(255 - ((arg0->unk_38 >> 16) & 255)) >> 2]; break;
            default: v8 = 0; break;
            }
            v4 = 512;
            if (v8 < 0) v4 = -512;
            v17 = v8 * v9;
            v17 += v4;
            v4 = v17 / 1024 + arg0->unk_14;
            fn_8006C634(v4, arg0->unk_E, (struct Sig_fn_8006C634_fn_8006C634_Arg2 *)&arg0->unk_34);
        } else if (arg0->unk_28 & 0x80) {
            lab_t1 = (struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 *)&arg0->unk_C;
            switch (arg0->unk_0) {
            case 7:
                arg0->unk_34 = fn_8006C6E8((struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 *)arg0, lab_t1);
                break;
            case 8:
                arg0->unk_34 = fn_8006C788(arg0, lab_t1);
                if ((s32)arg0->unk_34 == 0) arg0->unk_34 = arg0->unk_34 + 1;
                break;
            default: arg0->unk_34 = 0; break;
            }
        } else return 0;
    } else arg0->unk_34 = 0;
    return 1;
}
