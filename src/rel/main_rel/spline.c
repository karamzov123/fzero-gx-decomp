#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"

extern void mathutil_quat_mult(f32 *, f32 *, f32 *);
extern void fn_1_F56F8(f32 *out, f32 *in);
extern const f32 lbl_1_rodata_6D78;
extern void fn_1_F57A8(f32 *out, f32 *in);
extern const f32 lbl_1_rodata_6D70;
extern f64 fn_80088538(f32);
extern f64 fn_800883E8(f32);
extern f32 lbl_8006D0B4(f32);
extern f64 fn_80087E80(f32);
extern void fn_8006E8DC(void *);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_F5B88(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_9AD88(void);
extern void fn_1_F65A0(Obj_1_data_2A7E0_At3C *);
extern void fn_1_F7578(void);
extern void fn_8001D32C(u32 *);
extern void fn_80008BEC(void *dst, s32 value, u32 size);
extern void fn_1_F75D8(void *, int, int, int);
extern void fn_1_F8918(u8 *, u8 *);
extern s32 fn_8008023C(u8 *, Obj_1_bss_7F0C0 *, u32);
extern void fn_1_F85A0(Obj_1_bss_7F0C0 *, u8 *);
extern u16 lbl_1_data_414[36];
extern int fn_1_8D5F0(s16 value);
extern void fn_1_F7CAC(s16);
extern s32 fn_1_F7BE4(s16);
extern void fn_1_F7F48(s16 value);
extern int fn_1_14D6D8(s16 value);
extern void fn_1_F83F0(s16 value);
extern void fn_1_F8214(s16 value);
extern void fn_1_F8A04(void);
extern void fn_1_F8A90(void);
extern void fn_1_F8A7C(void);
extern void fn_1_F8AFC(u32 value);
extern void fn_1_F8B64(void);
extern void fn_1_F8BA8(void);
extern void fn_1_F8B7C(void);
extern void fn_1_F8BD4(void);
extern void fn_1_F8C28(s32 value);
extern void fn_1_F8CCC(s32 value);
extern void fn_1_F8CA0(s32 value);
extern struct Table lbl_1_rodata_6FF0;
extern void fn_80083DB0(void *arg0, u32 arg1);
extern void fn_1_F9D04(u8 index);
extern void fn_1_F9D90(void);
extern void fn_1_F9E38(void);
extern void fn_1_F9EE4(s32 value);
extern u8 fn_1_FA69C(s32 index);
extern void fn_1_3EF14(void *);
extern s32 fn_1_58C4(void);
extern void fn_1_FA89C(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_FB0B4(Obj_1_bss_84428 *data);
extern void fn_1_FB180(int *value);
extern void fn_1_9AD54(void);
extern void fn_1_FB18C(void);

extern void fn_1_F8918(u8 *, u8 *);
extern u16 lbl_1_data_414[36];
extern void fn_8001D3E4(int index, int value);
extern u32 lbl_801A66A0;

/* fzgx:begin fn_1_F4F08 */
#include "rel/main_rel/replay.h"

extern u32 lbl_801A6410[];
extern u8 lbl_1_data_3E8E0[];
extern const f32 lbl_1_rodata_6D6C;
extern const f32 lbl_1_rodata_6D70;
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_46B4(u32, u32, u8 *, u32);

void fn_1_F4F08(u32 count, f32 *x, f32 *z, f32 *y) {
    s32 tmp_cse1;
    f32 *diff;
    f32 *slope;
    s32 i;
tmp_cse1 = count * 4;

    diff = (f32 *)fn_1_4630(lbl_801A6410[0], tmp_cse1, lbl_1_data_3E8E0, 0x37);
    slope = (f32 *)fn_1_4630(lbl_801A6410[0], tmp_cse1, lbl_1_data_3E8E0, 0x38);

    y[count - 1] = lbl_1_rodata_6D70;
    y[0] = lbl_1_rodata_6D70;

    for (i = 0; i < count - 1; i++) {
        diff[i] = x[(i + 1)] - x[i];
        slope[(i + 1)] = (z[(i + 1)] - z[i]) / diff[i];
    }

    y[1] = (slope[2] - slope[1]) - (f32)(diff[0] * y[0]);
    slope[1] = lbl_1_rodata_6D6C * (x[2] - x[0]);

    for (i = 1; i < count - 2; i++) {
        f32 q = diff[i] / slope[i];
        y[(i + 1)] = (slope[i + 2] - slope[(i + 1)]) - (f32)(q * y[i]);
        slope[(i + 1)] = (f32)(lbl_1_rodata_6D6C * (x[i + 2] - x[i])) - (f32)(q * diff[i]);
    }

    y[count - 2] -= (f32)(diff[count - 2] * y[count - 1]);

    for (i = count - 2; i > 0; i--) {
        y[i] = (y[i] - (f32)(diff[i] * y[(i + 1)])) / slope[i];
    }

    fn_1_46B4(lbl_801A6410[0], (u32)diff, lbl_1_data_3E8E0, 0x4c);
    fn_1_46B4(lbl_801A6410[0], (u32)slope, lbl_1_data_3E8E0, 0x4d);
}
/* fzgx:end fn_1_F4F08 */

/* fzgx:begin fn_1_F5458 */
extern const f32 lbl_1_rodata_6D74;
extern const f32 lbl_1_rodata_6D6C;

extern void fn_8006EB4C(void *arg0, void *arg1, void *arg2, f32 arg3);
extern void fn_1_F55C4(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_1_F588C(void *arg0, void *arg1, void *arg2, f32 arg3);

void fn_1_F5458(void *arg0, u32 count, f32 value, f32 *samples, void *table) {
    u32 index;
    s32 offset;
    f32 lower;
    f32 upper;
    f32 ratio;
    u8 work3[16];
    u8 work2[16];
    u8 work1[16];
    u8 work0[16];
    f64 lab_t3;

    index = 0;
    while (index < count) {
        if (samples[index] > value) {
            index -= 1;
            break;
        }
        index++;
    }

    offset = index << 2;
    lower = samples[index];
    upper = samples[index + 1];
    ratio = (value - lower) / (upper - lower);

    if (index >= count - 1) {
        ratio = lbl_1_rodata_6D74;
        index = count - 2;
    }

    if (index < 1 || count - 3 < index) {
        fn_8006EB4C(arg0, (u8 *)table + (index << 4), ((16) + ((u8 *)table + (index << 4))), ratio);
    } else {
        fn_1_F55C4(work2, (u8 *)table + (index << 4), (u8 *)table + (index << 4) + 16,
                   (u8 *)table + (index << 4) + 32);
        fn_1_F55C4(work3, (u8 *)table + (index << 4) - 16, (u8 *)table + (index << 4),
                   (u8 *)table + (index << 4) + 16);
        fn_1_F588C(work1, (u8 *)table + (index << 4), (u8 *)table + (index << 4) + 16, ratio);
        fn_1_F588C(work0, work3, work2, ratio);
        lab_t3 = ((((lbl_1_rodata_6D6C)) * ((ratio))) * ((lbl_1_rodata_6D74 - ratio)));
        fn_1_F588C(arg0, work1, work0, lab_t3);
    }
}
/* fzgx:end fn_1_F5458 */

/* fzgx:begin fn_1_F55C4 */
void fn_1_F55C4(f32 *out, f32 *arg1, f32 *in, f32 *arg3) {
    f32 temp[4];

    temp[0] = -in[0];
    temp[1] = -in[1];
    temp[2] = -in[2];
    temp[3] = in[3];
    mathutil_quat_mult(out, temp, arg1);
    mathutil_quat_mult(temp, temp, arg3);
    fn_1_F56F8(out, out);
    fn_1_F56F8(temp, temp);
    out[0] += temp[0];
    out[1] += temp[1];
    out[2] += temp[2];
    out[3] += temp[3];
    out[0] /= lbl_1_rodata_6D78;
    out[1] /= lbl_1_rodata_6D78;
    out[2] /= lbl_1_rodata_6D78;
    out[3] /= lbl_1_rodata_6D78;
    fn_1_F57A8(out, out);
    mathutil_quat_mult(out, in, out);
}
/* fzgx:end fn_1_F55C4 */

/* fzgx:begin fn_1_F56F8 */
void fn_1_F56F8(f32 *out, f32 *in) {
    f32 value;
    f32 scale;
    f32 zero;

    value = fn_80088538(in[3]);
    scale = fn_800883E8(value);
    zero = lbl_1_rodata_6D70;
    out[3] = zero;
    if (scale > zero) {
        out[0] = value * in[0] / scale;
        out[1] = value * in[1] / scale;
        out[2] = value * in[2] / scale;
    } else {
        out[2] = zero;
        out[1] = zero;
        out[0] = zero;
    }
}
/* fzgx:end fn_1_F56F8 */

/* fzgx:begin fn_1_F57A8 */
void fn_1_F57A8(f32 *out, f32 *in) {
    f32 length;
    f32 scale;
    f32 angle;

    length = lbl_8006D0B4(in[0] * in[0] + in[1] * in[1] + in[2] * in[2]);
    scale = fn_800883E8(length);
    angle = fn_80087E80(length);
    out[3] = angle;
    if (length > lbl_1_rodata_6D70) {
        out[0] = scale * in[0] / length;
        out[1] = scale * in[1] / length;
        out[2] = scale * in[2] / length;
    } else {
        out[2] = lbl_1_rodata_6D70;
        out[1] = lbl_1_rodata_6D70;
        out[0] = lbl_1_rodata_6D70;
    }
}
/* fzgx:end fn_1_F57A8 */

/* fzgx:begin fn_1_F588C */
#pragma fp_contract off

extern const f32 lbl_1_rodata_6D7C;
extern const f32 lbl_1_rodata_6D80;
extern const f32 lbl_1_rodata_6D74;
extern f64 fn_80088538(f32);
extern f64 fn_800883E8(f32);
extern void fn_1_F5A2C(f32 *, f32 *, f32 *, f32);

void fn_1_F588C(f32 *out, f32 *a, f32 *b, f32 t) {
    f32 dot;
    f32 angle;
    f32 sin_angle;
    f32 sin_t_angle;
    f32 sin_rem_angle;

    dot = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
    if (dot > lbl_1_rodata_6D7C && dot < lbl_1_rodata_6D80) {
        angle = fn_80088538(dot);
        sin_angle = fn_800883E8(angle);
        sin_t_angle = fn_800883E8(angle * t);
        sin_rem_angle = fn_800883E8(angle * (lbl_1_rodata_6D74 - t));
        out[0] = (a[0] * sin_rem_angle + b[0] * sin_t_angle) / sin_angle;
        out[1] = (a[1] * sin_rem_angle + b[1] * sin_t_angle) / sin_angle;
        out[2] = (a[2] * sin_rem_angle + b[2] * sin_t_angle) / sin_angle;
        out[3] = (a[3] * sin_rem_angle + b[3] * sin_t_angle) / sin_angle;
    } else {
        fn_1_F5A2C(out, a, b, t);
    }
}
/* fzgx:end fn_1_F588C */

/* fzgx:begin fn_1_F5A2C */
typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

void fn_1_F5A2C(Vec4 *dst, const Vec4 *a, const Vec4 *b, f32 t) {
    f32 delta;
    f32 product;
    f32 start;

    start = a->x;
    delta = b->x - start;
    product = t * delta;
    dst->x = start + product;
    start = a->y;
    delta = b->y - start;
    product = t * delta;
    dst->y = start + product;
    start = a->z;
    delta = b->z - start;
    product = t * delta;
    dst->z = start + product;
    start = a->w;
    delta = b->w - start;
    product = t * delta;
    dst->w = start + product;
    fn_8006E8DC(dst);
}
/* fzgx:end fn_1_F5A2C */

/* fzgx:begin fn_1_F5AAC */
// fn_1_F5AAC: empty in retail (single blr).
void fn_1_F5AAC(void) {
}
/* fzgx:end fn_1_F5AAC */

/* fzgx:begin fn_1_F5AB0 */
void fn_1_F5AB0(void) {
    Obj_1_data_2A7E0_At3C *arg0 = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508(&lbl_1_data_2A7E0);
    fn_1_F5B88(arg0);
}
/* fzgx:end fn_1_F5AB0 */

/* fzgx:begin fn_1_F5AEC */
// fn_1_F5AEC: empty in retail (single blr).
void fn_1_F5AEC(void) {
}
/* fzgx:end fn_1_F5AEC */

/* fzgx:begin fn_1_F5AF0 */
// Update the spline state after refreshing the shared data.
void fn_1_F5AF0(void) {
    Obj_1_data_2A7E0_At3C *state;

    state = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    if ((s32)state->unk_10 != 0) {
        fn_1_F5D94(state);
    }
}
/* fzgx:end fn_1_F5AF0 */

/* fzgx:begin fn_1_F5B38 */
// fn_1_F5B38: empty in retail (single blr).
void fn_1_F5B38(void) {
}
/* fzgx:end fn_1_F5B38 */

/* fzgx:begin fn_1_F5B3C */
void fn_1_F5B3C(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    fn_1_9AD88();
    if ((s32)obj->unk_10 != 0) {
        fn_1_F65A0(obj);
    }
}
/* fzgx:end fn_1_F5B3C */

/* fzgx:begin fn_1_F5B84 */
// fn_1_F5B84: empty in retail (single blr).
void fn_1_F5B84(void) {
}
/* fzgx:end fn_1_F5B84 */

/* fzgx:begin fn_1_F5B88 */
extern s32 fn_1_58C4(void);
extern u32 lbl_801A63C0;

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f unk_0;
    Vec3f unk_C;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} SplineNode;

typedef struct {
    u8 pad[0x24];
    u32 unk_24;
} NodeTarget;

typedef struct {
    u8 pad[0xA0];
    NodeTarget *unk_A0;
} NodeContainer;

static inline int rand_next(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#pragma opt_lifetimes off
void fn_1_F5B88(Obj_1_data_2A7E0_At3C *arg0) {
    s32 i;
    SplineNode *node;
    NodeContainer *c;
    NodeTarget *target;

    if ((u32)fn_1_58C4() < 2) {
        arg0->unk_10 = 1;
    } else {
        arg0->unk_10 = 0;
        return;
    }

    *(f32 *)&arg0->unk_C = 0.0f;
    node = (SplineNode *)&arg0->unk_14;
    c = (NodeContainer *)lbl_1_bss_38458->unk_8;
    target = c->unk_A0;
    arg0->unk_0 = target->unk_24;
    arg0->unk_4 = target->unk_24;

    for (i = 0; i < 36; i++, node++) {
        node->unk_0.x = 6.0f * ((f32)rand_next() / 32767.0f);
        node->unk_0.y = 6.0f * ((f32)rand_next() / 32767.0f);
        node->unk_0.z = 6.0f * ((f32)rand_next() / 32767.0f);
        node->unk_C = node->unk_0;
        node->unk_18 = 0.0f;
        node->unk_1C = 0.0f;
        node->unk_20 = 0.0f;
        node->unk_24 = 0.0f;
        node->unk_2C = 0.019999999552965164f * (((f32)rand_next() / 32767.0f) + 1.0f);
        node->unk_28 = node->unk_2C;
        node->unk_30 = (s32)(15.0f * ((f32)rand_next() / 32767.0f));
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_F5B88 */

/* fzgx:begin fn_1_F70C0 */
// fn_1_F70C0: returns a constant.
int fn_1_F70C0(void) {
    return 1;
}
/* fzgx:end fn_1_F70C0 */

/* fzgx:begin fn_1_F70C8 */
// fn_1_F70C8: returns a constant.
int fn_1_F70C8(void) {
    return 1;
}
/* fzgx:end fn_1_F70C8 */

/* fzgx:begin fn_1_F70D0 */
// Clear the spline state buffers and mark the state as initialized.
void fn_1_F70D0(void) {
    u32 *state = (u32 *)&lbl_1_bss_7F028;

    fn_80008BEC((u8 *)state + 4, 0, 0x10);
    fn_80008BEC((u8 *)state + 0x14, 0, 0x10);
    *(u8 *)state |= 1;
}
/* fzgx:end fn_1_F70D0 */

/* fzgx:begin fn_1_F7128 */
void fn_1_F7128(void) {
    int i;
    Obj_1_bss_7F03C *dst;
    Obj_1_bss_7F02C *src;

    dst = &lbl_1_bss_7F03C;
    src = &lbl_1_bss_7F02C;
    for (i = 0; i < 4; i++) {
        if (src->unk_0 != 0) {
            dst->unk_0 = src->unk_0;
            if (src->unk_0 == 6 || src->unk_0 == 5) {
                dst->unk_2 = 0;
            } else if ((u8)(src->unk_0 - 1) <= 2 || src->unk_0 == 4) {
                fn_8001D3E4(i, 1);
                dst->unk_2 = src->unk_2;
            }
            src->unk_0 = 0;
        }
        dst = (Obj_1_bss_7F03C *)((u8 *)dst + 4);
        src = (Obj_1_bss_7F02C *)((u8 *)src + 4);
    }

    dst = &lbl_1_bss_7F03C;
    for (i = 0; i < 4; i++) {
        if (dst->unk_0 == 6) {
            fn_8001D3E4(i, 0);
            dst->unk_0 = 0;
        } else if (dst->unk_0 == 5) {
            fn_8001D3E4(i, 2);
            dst->unk_0 = 0;
        } else {
            if (dst->unk_0 == 3) {
                if (lbl_801A66A0 & 1) {
                    fn_8001D3E4(i, 0);
                } else {
                    fn_8001D3E4(i, 1);
                }
            }
            if (dst->unk_0 == 4) {
                if (lbl_801A66A0 & 1) {
                    fn_8001D3E4(i, 2);
                } else {
                    fn_8001D3E4(i, 1);
                }
            }
            if (dst->unk_2 != 0) {
                dst->unk_2--;
            }
            if (dst->unk_2 == 1) {
                fn_8001D3E4(i, dst->unk_0 == 1 ? 2 : 0);
                dst->unk_0 = 0;
                dst->unk_2 = 0;
            }
        }
        dst = (Obj_1_bss_7F03C *)((u8 *)dst + 4);
    }
}
/* fzgx:end fn_1_F7128 */

/* fzgx:begin fn_1_F7308 */
void fn_1_F7308(void) {
    fn_1_F7578();
    lbl_1_bss_7F028 &= 0xFE;
}
/* fzgx:end fn_1_F7308 */

/* fzgx:begin fn_1_F7338 */
extern int fn_1_866B4(s8);
extern int fn_1_864FC(s8);
extern void fn_1_F73A8(int, void *, void *);

void fn_1_F7338(int arg0, void *arg1, void *arg2) {
    s8 value;

    value = (s8)fn_1_866B4((s8)arg0);
    if (value >= 0) {
        switch (fn_1_864FC(value) & 0x10) {
        case 0:
            fn_1_F73A8(arg0, arg1, arg2);
            break;
        default:
            break;
        }
    }
}
/* fzgx:end fn_1_F7338 */

/* fzgx:begin fn_1_F73A8 */
extern void mathutil_quat_mult(f32 *, f32 *, f32 *);
extern void fn_1_F56F8(f32 *out, f32 *in);
extern const f32 lbl_1_rodata_6D78;
extern void fn_1_F57A8(f32 *out, f32 *in);
extern const f32 lbl_1_rodata_6D70;
extern f64 fn_80088538(f32);
extern f64 fn_800883E8(f32);
extern f32 lbl_8006D0B4(f32);
extern f64 fn_80087E80(f32);
extern void fn_8006E8DC(void *);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_F5B88(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_9AD88(void);
extern void fn_1_F65A0(Obj_1_data_2A7E0_At3C *);
extern void fn_1_F7578(void);
extern void fn_8001D32C(u32 *);
extern void fn_80008BEC(void *dst, s32 value, u32 size);
extern void fn_1_F75D8(void *, int, int, int);
extern void fn_1_F8918(u8 *, u8 *);
extern s32 fn_8008023C(u8 *, Obj_1_bss_7F0C0 *, u32);
extern void fn_1_F85A0(Obj_1_bss_7F0C0 *, u8 *);
extern u16 lbl_1_data_414[36];
extern int fn_1_8D5F0(s16 value);
extern void fn_1_F7CAC(s16);
extern s32 fn_1_F7BE4(s16);
extern void fn_1_F7F48(s16 value);
extern int fn_1_14D6D8(s16 value);
extern void fn_1_F83F0(s16 value);
extern void fn_1_F8214(s16 value);
extern void fn_1_F8A04(void);
extern void fn_1_F8A90(void);
extern void fn_1_F8A7C(void);
extern void fn_1_F8AFC(u32 value);
extern void fn_1_F8B64(void);
extern void fn_1_F8BA8(void);
extern void fn_1_F8B7C(void);
extern void fn_1_F8BD4(void);
extern void fn_1_F8C28(s32 value);
extern void fn_1_F8CCC(s32 value);
extern void fn_1_F8CA0(s32 value);
extern struct Table lbl_1_rodata_6FF0;
extern void fn_80083DB0(void *arg0, u32 arg1);
extern void fn_1_F9D04(u8 index);
extern void fn_1_F9D90(void);
extern void fn_1_F9E38(void);
extern void fn_1_F9EE4(s32 value);
extern u8 fn_1_FA69C(s32 index);
extern void fn_1_3EF14(void *);
extern s32 fn_1_58C4(void);
extern void fn_1_FA89C(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_FB0B4(Obj_1_bss_84428 *data);
extern void fn_1_FB180(int *value);
extern void fn_1_9AD54(void);
extern void fn_1_FB18C(void);

extern void fn_1_F8918(u8 *, u8 *);
extern u16 lbl_1_data_414[36];
extern void fn_8001D3E4(int index, int value);
extern u32 lbl_801A66A0;


void fn_1_F73A8(s32 idx, s32 kind, s32 val) {
    Obj_1_bss_7F02C *p;
    if ((lbl_1_bss_7F028 & 1) == 0) return;
    if (kind == 0) return;
    if (idx < 0 || idx >= 4) return;
    {
        if (val > 180) return;
        if ((lbl_1_data_3E8F0 & (1 << idx)) == 0) return;
        if (kind == 6 || kind == 5) val = 0;
        p = (Obj_1_bss_7F02C *)((u8 *)&lbl_1_bss_7F02C + (idx << 2));
        switch (p->unk_0) {
        case 6:
            if (kind == 5) p->unk_0 = kind;
            break;
        case 1:
            switch (kind) {
            case 5:
            case 6:
                p->unk_0 = kind;
                break;
            case 1:
                if (p->unk_2 < val) {
                    p->unk_0 = kind;
                    p->unk_2 = val;
                }
                break;
            }
            break;
        case 2:
            switch (kind) {
            case 5:
            case 6:
                p->unk_0 = kind;
                break;
            case 2:
            case 3:
            case 4:
                if (p->unk_2 < val) break;
            case 1:
                p->unk_0 = kind;
                p->unk_2 = val;
                break;
            }
            break;
        case 3:
            switch (kind) {
            case 5:
            case 6:
                p->unk_0 = kind;
                break;
            case 3:
            case 4:
                if (p->unk_2 < val) break;
            case 1:
            case 2:
                p->unk_0 = kind;
                p->unk_2 = val;
                break;
            }
            break;
        case 4:
            switch (kind) {
            case 5:
            case 6:
                p->unk_0 = kind;
                break;
            case 4:
                if (p->unk_2 < val) break;
            case 1:
            case 2:
            case 3:
                p->unk_0 = kind;
                p->unk_2 = val;
                break;
            }
            break;
        case 0:
            p->unk_0 = kind;
            p->unk_2 = val;
            break;
        }
    }
}
/* fzgx:end fn_1_F73A8 */

/* fzgx:begin fn_1_F755C */
void fn_1_F755C(u8 value) {
    lbl_1_data_3E8F0 = value;
}
/* fzgx:end fn_1_F755C */

/* fzgx:begin fn_1_F7568 */
u8 fn_1_F7568(void) {
    return lbl_1_data_3E8F0;
}
/* fzgx:end fn_1_F7568 */

/* fzgx:begin fn_1_F7578 */
// Initialize the spline work buffers to their default values.

void fn_1_F7578(void) {
    u32 values[4];

    values[0] = 2;
    values[1] = 2;
    values[2] = 2;
    values[3] = 2;
    fn_8001D32C(values);
    fn_80008BEC(&lbl_1_bss_7F02C, 0, 0x10);
    fn_80008BEC(&lbl_1_bss_7F03C, 0, 0x10);
}
/* fzgx:end fn_1_F7578 */

/* fzgx:begin fn_1_F75D8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/light.h"
#include "psvec.h"

/* begin game/main_rel/light_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_LIGHT_TYPES_H
#define GAME_MAIN_REL_LIGHT_TYPES_H

// Types (and the externs that name them) of light.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Triple_80074D28;

extern void fn_80074D28(Triple_80074D28 *);

#endif  // GAME_MAIN_REL_LIGHT_TYPES_H

/* end game/main_rel/light_types.h */

typedef struct {
    u8 r, g, b, a;
} LightColor_F75D8;

typedef struct {
    f32 x, y, z;
} LightVec_F75D8;

typedef struct {
    u32 dummy[16];
} LightObj_F75D8;

typedef struct {
    LightVec_F75D8 pos;       /* 0x00 */
    LightVec_F75D8 dir;       /* 0x0C */
    LightColor_F75D8 ambient; /* 0x18 */
    LightColor_F75D8 color;   /* 0x1C */
    s8 distFn;                /* 0x20 */
    u8 pad_21[3];
    f32 refDist;              /* 0x24 */
    f32 refBright;            /* 0x28 */
    s8 spotFn;                /* 0x2C */
    u8 pad_2D[3];
    f32 cutoff;               /* 0x30 */
} LightDesc_F75D8;

/* Per-player light overrides: a TU-local block of five 4-entry tables at lbl_1_bss_7F050. */
static s32 fzgx_obj_lbl_1_bss_7F050[4];
static LightColor_F75D8 lbl_1_bss_7F050__fzgx_offset_10[4];
static s32 lbl_1_bss_7F050__fzgx_offset_20[4];
static LightColor_F75D8 lbl_1_bss_7F050__fzgx_offset_30[4];
static s32 lbl_1_bss_7F050__fzgx_offset_40[4];

extern s32 fn_1_5910(void);
extern void fn_1_7BB80(LightObj_F75D8 *, s32);
extern void fn_1_7BCCC(Triple_80074D28 *);
extern void fn_1_7BD6C(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void lbl_8006DCA4(void);
extern f32 lbl_8006D668(LightVec_F75D8 *);
extern void lbl_8006D5F0(LightVec_F75D8 *, LightVec_F75D8 *, f32);
extern void lbl_8006E1B0(void *, LightVec_F75D8 *);
extern void lbl_8006E1C0(LightVec_F75D8 *, LightVec_F75D8 *);
extern void fn_800356AC(LightObj_F75D8 *, LightColor_F75D8 *);
extern void fn_80035680(LightObj_F75D8 *, f32, f32, f32);
extern void fn_80035690(LightObj_F75D8 *, f32, f32, f32);
extern void fn_80035420(LightObj_F75D8 *, f32, s32);
extern void GXInitLightDistAttn(LightObj_F75D8 *, f32, f32, s32);
extern void fn_80074CF4(f32, f32, f32);
extern void lbl_8006DB30(void);

void fn_1_F75D8(LightDesc_F75D8 **lights, s32 useOverride, s32 mode) {
    s32 i;
    LightDesc_F75D8 **p;
    LightDesc_F75D8 *light;
    s32 idx;
    s32 lightId = 1;
    LightColor_F75D8 ambient;
    LightVec_F75D8 pos;
    LightVec_F75D8 dir;
    LightObj_F75D8 obj;

    lbl_8006DAEC();
    if (useOverride) {
        idx = fn_1_5910();
    } else {
        idx = 0;
    }
    if (mode) {
        lbl_8006D758();
    } else {
        lbl_8006DCA4();
    }

    p = lights;
    for (i = 0; i < 32; i++) {
        light = *p;
        if (light == NULL) {
            break;
        }
        if (i == 0) {
            if (useOverride && fzgx_obj_lbl_1_bss_7F050[idx] != 0) {
                ambient = lbl_1_bss_7F050__fzgx_offset_10[idx];
            } else {
                ambient = light->ambient;
            }
        }
        dir = light->dir;
        lbl_8006D668(&dir);
        if (light->distFn == 0 && light->spotFn == 0) {
            lbl_8006D5F0(&dir, &pos, -100000.0f);
            lbl_8006E1B0(&pos, &pos);
        } else {
            lbl_8006E1B0(light, &pos);
        }
        lbl_8006E1C0(&dir, &dir);
        if (useOverride && lbl_1_bss_7F050__fzgx_offset_20[idx] != 0) {
            LightColor_F75D8 color = lbl_1_bss_7F050__fzgx_offset_30[idx];
            fn_800356AC(&obj, &color);
        } else {
            LightColor_F75D8 color = light->color;
            fn_800356AC(&obj, &color);
        }
        fn_80035680(&obj, pos.x, pos.y, pos.z);
        fn_80035690(&obj, dir.x, dir.y, dir.z);
        fn_80035420(&obj, light->cutoff, light->spotFn);
        GXInitLightDistAttn(&obj, light->refDist, light->refBright, light->distFn);
        fn_1_7BB80(&obj, lightId++);
        if (i == 0) {
            psvec_scale(&dir, -1.0f, &dir);
            fn_1_7BCCC((Triple_80074D28 *)&dir);
        }
        p++;
    }

    fn_1_7BD6C(1);
    fn_80074CF4(ambient.r / 255.0f, ambient.g / 255.0f, ambient.b / 255.0f);
    lbl_8006DB30();
}
/* fzgx:end fn_1_F75D8 */

/* fzgx:begin fn_1_F7870 */
void fn_1_F7870(u32 value) {
    u32 values[2];

    values[0] = value;
    values[1] = 0;
    fn_1_F75D8(values, 0, 1, 0);
}
/* fzgx:end fn_1_F7870 */

/* fzgx:begin fn_1_F78AC */
void fn_1_F78AC(void *arg0) {
    fn_1_F75D8(arg0, 1, 0, 0);
}
/* fzgx:end fn_1_F78AC */

/* fzgx:begin fn_1_F78D8 */
void fn_1_F78D8(void *arg0) {
    fn_1_F75D8(arg0, 1, 0, 1);
}
/* fzgx:end fn_1_F78D8 */

/* fzgx:begin fn_1_F7904 */
// Builds the spline workspace and reports whether its serialized data is valid.
s32 fn_1_F7904(void) {
    u8 buffer[0x5360];

    fn_1_F8918(&lbl_1_bss_718E0.pad_1A2[0x1e], buffer);
    return fn_8008023C(buffer, &lbl_1_bss_7F0C0, 0x5360) != 0;
}
/* fzgx:end fn_1_F7904 */

/* fzgx:begin fn_1_F7954 */
s32 fn_1_F7954(void) {
    u8 buffer[0x5360];
    u8 *workspace;

    workspace = (u8 *)&lbl_1_bss_718E0 + 0x1c0;
    fn_1_F8918(workspace, buffer);
    if (fn_8008023C(buffer, &lbl_1_bss_7F0C0, 0x5360) == 0) {
        return 0;
    }
    fn_1_F85A0(&lbl_1_bss_7F0C0, workspace);
    return 1;
}
/* fzgx:end fn_1_F7954 */

/* fzgx:begin fn_1_F79C8 */
// Initialize spline data and publish the active spline region.
void fn_1_F79C8(void) {
    fn_1_F8918(&lbl_1_bss_718E0.pad_1A2[0x1e], (u8 *)&lbl_1_bss_7F0C0);
    lbl_1_bss_84420 = (u32)((u8 *)&lbl_1_bss_7F0C0 + 0x4b5c);
    lbl_1_data_414[0] = 0xffff;
}
/* fzgx:end fn_1_F79C8 */

/* fzgx:begin fn_1_F7A20 */
extern void fn_1_F7B2C(void *);
extern void fn_1_F7E88(void);
extern void fn_1_F8048(void);
extern void fn_1_F82E0(void);
extern void fn_1_F8A18(void);
extern void fn_1_F89C0(void);
extern void fn_1_F8B24(void);
extern void fn_1_F9C6C(void);
extern void fn_1_F9E4C(void);
extern void fn_1_F9D24(void);
extern void fn_1_F9DA4(void);
extern void fn_1_F9CD0(u8, u8);
extern void fn_1_FA1D8(u32, u32, void *);
extern u32 fn_1_FA4D4(void);
extern void fn_1_FA61C(void);
extern u32 fn_800793D4(u8 *, u32, u32);

typedef struct {
	u32 pre[0x3D];
	u32 fF4;
	u32 fF8[0x22];
} Elem;

typedef struct {
	s32 v00;
	u32 v04;
	u8 pad0[0x18];
	Elem elems[0x30];
	u8 pad1[0x48F8 - 0x4800];
	u32 f4918;
	u8 pad2[0x5380 - 0x491C];
	void *p;
} Obj;

typedef struct lbl_1_bss_7F0A0_t {
    u32 v00;
    u32 v04;
    u8 pad_8[0x18];
} lbl_1_bss_7F0A0_t;

typedef struct lbl_1_bss_7F0C0_t {
    Elem elems[0x30];
    u8 pad_4800[0xb60];
} lbl_1_bss_7F0C0_t;

typedef struct lbl_1_bss_84420_t {
    void *p;
    u8 pad_4[0x4];
} lbl_1_bss_84420_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_7F0A0_t lbl_1_bss_7F0A0;
lbl_1_bss_7F0C0_t fzgx_obj_lbl_1_bss_7F0C0;
lbl_1_bss_84420_t fzgx_obj_lbl_1_bss_84420;
u32 fzgx_obj_lbl_1_bss_84428[10];
u8 fzgx_obj_lbl_1_bss_84450;
u8 fzgx_pool_lbl_1_bss_7F0A0_gap_84451;
u16 fzgx_pool_lbl_1_bss_7F0A0_gap_84451_fill_84452;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7F0A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F0C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84420;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84428;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_84450;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7F0A0_gap_84451;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7F0A0_gap_84451_fill_84452;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
void fn_1_F7A20(void) {
	
	s32 i;

	*(unsigned long long *)&lbl_1_bss_7F0A0.v00 = 0;
	fn_800793D4((u8 *)&fzgx_obj_lbl_1_bss_7F0C0.elems[0], 0, 0x5360);
	fzgx_obj_lbl_1_bss_84420.p = (void *)((u8 *)&fzgx_obj_lbl_1_bss_7F0C0.elems[0] + 0x4B5C);
	fn_1_F7B2C(&fzgx_obj_lbl_1_bss_7F0C0.elems[0]);
	fn_1_F7E88();
	fn_1_F8048();
	fn_1_F82E0();
	fn_1_F8A18();
	fn_1_F89C0();
	fn_1_F8B24();
	fn_1_F9C6C();
	fn_1_F9E4C();
	fn_1_F9D24();
	fn_1_F9DA4();
	fn_1_F9CD0(0, 0);
	fzgx_obj_lbl_1_bss_7F0C0.elems[0].fF4 = 0;
	*(u32 *)((u8 *)&fzgx_obj_lbl_1_bss_7F0C0.elems[0] + 0x48F8) = 0;
	for (i = 0; i < 0x30; i++) {
		fn_1_FA1D8(i / 6, i % 6, &fzgx_obj_lbl_1_bss_7F0C0.elems[i].fF8);
	}
	((u8 *)fzgx_obj_lbl_1_bss_84420.p)[0] = 0x7C;
	((u8 *)fzgx_obj_lbl_1_bss_84420.p)[8] = 1;
	fn_1_FA4D4();
	fn_1_FA61C();
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F7A20 */

/* fzgx:begin fn_1_F7B2C */
void fn_1_F7B2C(void) {
    s16 i;

    for (i = 0; i < 0x29; i++) {
        if (fn_1_8D5F0(i) & (1u << 31)) {
            fn_1_F7CAC(i);
        }
    }
}
/* fzgx:end fn_1_F7B2C */

/* fzgx:begin fn_1_F7B80 */
s16 fn_1_F7B80(void) {
    s16 i;
    s16 count;

    count = 0;
    for (i = 0; i < 0x29; i++) {
        if (fn_1_F7BE4(i) != 0) {
            count++;
        }
    }
    return count;
}
/* fzgx:end fn_1_F7B80 */

/* fzgx:begin fn_1_F7BE4 */
s32 fn_1_F7BE4(s16 arg0) {
    u64 t0;
    u64 flags;
    s32 v1;
    t0 = 1ULL << arg0;
    flags = ((u64)lbl_1_bss_7F0C0.unk_0 << 32) | lbl_1_bss_7F0C0.unk_4;
    if ((flags & t0) != 0) {
        v1 = 1;
    } else {
        v1 = 0;
    }
    return v1;
}
/* fzgx:end fn_1_F7BE4 */

/* fzgx:begin fn_1_F7C48 */
extern u64 __shl2i(u32, u32, s32);

s16 fn_1_F7C48(s16 arg) {
    u64 mask = (u64)1 << arg;
    u64 bits = ((u64)lbl_1_bss_7F0C0.unk_48 << 32) | lbl_1_bss_7F0C0.unk_4C;
    s16 ret;

    if (bits & mask) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
/* fzgx:end fn_1_F7C48 */

/* fzgx:begin fn_1_F7CAC */
extern u64 __shl2i(u32, u32, s32);

void fn_1_F7CAC(s16 value) {
    u64 mask = (u64)1 << value;

    *(u64 *)&lbl_1_bss_7F0C0.unk_0 |= mask;
    *(u64 *)&lbl_1_bss_7F0C0.unk_48 &= ~mask;
}
/* fzgx:end fn_1_F7CAC */

/* fzgx:begin fn_1_F7D18 */
void fn_1_F7D18(void) {
    s16 i;

    for (i = 0; i < 41; i++) {
        if (!(fn_1_8D5F0(i) & 0x10000000)) {
            fn_1_F7F48(i);
        }
    }
}
/* fzgx:end fn_1_F7D18 */

/* fzgx:begin fn_1_F7D6C */
void fn_1_F7D6C(void) {
    s16 i;

    for (i = 0; i < 41; i++) {
        if (fn_1_8D5F0(i) & 0x10000000) {
            fn_1_F7F48(i);
        }
    }
}
/* fzgx:end fn_1_F7D6C */

/* fzgx:begin fn_1_F7DC0 */
enum {
    SIGN_BIT = (u32)1 << 31
};

void fn_1_F7DC0(void) {
    s16 i;

    for (i = 0; i < 75; i++) {
        if (!(fn_1_14D6D8(i) & SIGN_BIT) &&
            !(fn_1_14D6D8(i) & 0x10000000)) {
            fn_1_F83F0(i);
        }
    }
}
/* fzgx:end fn_1_F7DC0 */

/* fzgx:begin fn_1_F7E24 */
void fn_1_F7E24(void) {
    s16 i;

    for (i = 0; i < 75; i++) {
        if (fn_1_14D6D8(i) & ((u32)1 << 31)) {
            if (!(fn_1_14D6D8(i) & 0x10000000)) {
                fn_1_F83F0(i);
            }
        }
    }
}
/* fzgx:end fn_1_F7E24 */

/* fzgx:begin fn_1_F7E88 */
void fn_1_F7E88(void) {
    s16 i;

    for (i = 0; i < 41; i++) {
        if (fn_1_8D5F0(i) & 0x20000000) {
            fn_1_F7F48(i);
        }
    }
}
/* fzgx:end fn_1_F7E88 */

/* fzgx:begin fn_1_F7EDC */
s32 fn_1_F7EDC(s16 value) {
    u64 result;
    u64 mask;

    result = (u64)1 << value;
    mask = *(u64 *)&lbl_1_bss_7F0C0 | *(u64 *)&lbl_1_bss_7F0C0.unk_18;
    return (mask & result) != 0;
}
/* fzgx:end fn_1_F7EDC */

/* fzgx:begin fn_1_F7F48 */
extern int fn_1_8D5F0(s16 value);

#pragma opt_common_subs off
void fn_1_F7F48(s16 value) {
    Obj_1_bss_7F0C0 *p;
    u64 mask;
    u64 bit;
    struct { s32 value; } cond;

    bit = (u64)1 << value;
    p = (Obj_1_bss_7F0C0 *)&lbl_1_bss_7F0C0;
    mask = *(u64 *)p | *(u64 *)&p->unk_18;
    cond.value = 0;
    if (mask & bit) {
        cond.value = 1;
    }
    if (((0) == (cond.value))) {
        if ((fn_1_8D5F0(value) & 0x20000000) == 0) {
            *(u64 *)&lbl_1_bss_7F0C0.unk_48 |= bit;
        }
    }
    *(u64 *)&p->unk_18 |= bit;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F7F48 */

/* fzgx:begin fn_1_F8030 */
// Clears the spline state counters.
void fn_1_F8030(void) {
    lbl_1_bss_7F0C0.unk_4C = 0;
    lbl_1_bss_7F0C0.unk_48 = 0;
}
/* fzgx:end fn_1_F8030 */

/* fzgx:begin fn_1_F8048 */
void fn_1_F8048(void) {
    s16 i;

    for (i = 0; i < 75; i++) {
        if (fn_1_14D6D8(i) & 0x40000000) {
            fn_1_F8214(i);
        }
    }
}
/* fzgx:end fn_1_F8048 */

/* fzgx:begin fn_1_F809C */
s32 fn_1_F809C(s32 value) {
    s16 index;
    u64 mask;
    s32 result;

    index = value;
    if (index > 63) {
        index = value - 64;
        mask = (u64)1 << index;
        if (*(u64 *)&lbl_1_bss_7F0C0.unk_10 & mask) {
            return 1;
        }
        result = 0;
    } else {
        mask = (u64)1 << index;
        if (*(u64 *)&lbl_1_bss_7F0C0.unk_8 & mask) {
            result = 1;
        } else {
            result = 0;
        }
    }
    return result;
}
/* fzgx:end fn_1_F809C */

/* fzgx:begin fn_1_F8158 */
extern u64 __shl2i(u32 hi, u32 lo, s16 count);

s32 fn_1_F8158(s32 value) {
    u64 mask;
    if ((s16)value > 63) {
        mask = __shl2i(0, 1, (s16)(value - 64));
        return (*(u64 *)&lbl_1_bss_7F0C0.unk_58 & mask) ? 1 : 0;
    }
    mask = __shl2i(0, 1, (s16)value);
    return (*(u64 *)&lbl_1_bss_7F0C0.unk_50 & mask) ? 1 : 0;
}
/* fzgx:end fn_1_F8158 */

/* fzgx:begin fn_1_F8214 */
void fn_1_F8214(s16 value) {
    u64 mask;
    if (value > 63) {
        mask = 1ULL << (s16)(value - 64);
        *(u64 *)&lbl_1_bss_7F0C0.unk_10 |= mask;
        *(u64 *)&lbl_1_bss_7F0C0.unk_58 &= ~mask;
    } else {
        mask = 1ULL << value;
        *(u64 *)&lbl_1_bss_7F0C0.unk_8 |= mask;
        *(u64 *)&lbl_1_bss_7F0C0.unk_50 &= ~mask;
    }
}
/* fzgx:end fn_1_F8214 */

/* fzgx:begin fn_1_F82E0 */
void fn_1_F82E0(void) {
    s16 i;

    for (i = 0; i < 75; i++) {
        if (fn_1_14D6D8(i) & 0x20000000) {
            fn_1_F83F0(i);
        }
    }
}
/* fzgx:end fn_1_F82E0 */

/* fzgx:begin fn_1_F8334 */
extern u64 __shl2i(u64 value, s32 shift);

int fn_1_F8334(s16 value) {
    u64 mask;

    if (value > 0x3f) {
        mask = 1ULL << (s16)(value - 0x40);
        return (*(u64 *)&lbl_1_bss_7F0C0.unk_28 & mask) != 0 ? 1 : 0;
    }

    mask = 1ULL << value;
    return (*(u64 *)&lbl_1_bss_7F0C0.unk_20 & mask) != 0 ? 1 : 0;
}
/* fzgx:end fn_1_F8334 */

/* fzgx:begin fn_1_F83F0 */
extern int fn_1_14D6D8(s16);

static inline int test_bits(u64 bits) {
    if (bits != 0) {
        return 1;
    }
    return 0;
}

void fn_1_F83F0(s16 arg0) {
    int v5 = 0;
    int v0;
    u64 mask;

    if (arg0 > 63) {
        mask = 1ULL << (s16)(arg0 - 64);
        v0 = test_bits(*(u64 *)&lbl_1_bss_7F0C0.unk_28 & mask);
    } else {
        mask = 1ULL << arg0;
        v0 = test_bits(*(u64 *)&lbl_1_bss_7F0C0.unk_20 & mask);
    }
    if (v0 == 0) {
        if ((fn_1_14D6D8(arg0) & 0x20000000) == 0) {
            v5 = 1;
        }
    }
    if (arg0 > 63) {
        mask = 1ULL << (s16)(arg0 - 64);
        *(u64 *)&lbl_1_bss_7F0C0.unk_28 |= mask;
        if (v5 == 1) {
            *(u64 *)&lbl_1_bss_7F0C0.unk_58 |= mask;
        }
    } else {
        mask = 1ULL << arg0;
        *(u64 *)&lbl_1_bss_7F0C0.unk_20 |= mask;
        if (v5 == 1) {
            *(u64 *)&lbl_1_bss_7F0C0.unk_50 |= mask;
        }
    }
}
/* fzgx:end fn_1_F83F0 */

/* fzgx:begin fn_1_F8580 */
void fn_1_F8580(void) {
    lbl_1_bss_7F0C0.unk_5C = 0;
    lbl_1_bss_7F0C0.unk_58 = 0;
    lbl_1_bss_7F0C0.unk_54 = 0;
    lbl_1_bss_7F0C0.unk_50 = 0;
}
/* fzgx:end fn_1_F8580 */

/* fzgx:begin fn_1_F8918 */
extern u32 lbl_801A63C0;

void fn_1_F8918(u8 *src, u8 *dst) {
    u8 *hdr = src + 0x60;
    u32 seed = *(u32 *)hdr ^ 0xcae87fb5;
    s32 value;
    u32 i;

    lbl_801A63C0 = seed;
    for (i = 0; i < 0x5360; i++) {
        if (src < hdr || hdr + 4 <= src) {
            seed = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
            lbl_801A63C0 = seed;
            value = (seed >> 16) & 0x7fff;
            *dst = *src ^ (value % 255 + 1);
        } else {
            *dst = *src;
        }
        src++;
        dst++;
    }
}
/* fzgx:end fn_1_F8918 */

/* fzgx:begin fn_1_F89C0 */
void fn_1_F89C0(void) {
    fn_1_F8A04();
    fn_1_F8A90();
}
/* fzgx:end fn_1_F89C0 */

/* fzgx:begin fn_1_F89E4 */
// Returns the selected bit from the rolling flag mask.
u32 fn_1_F89E4(u8 value) {
    return __rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4672], (value + 1) & 0x1f, 31, 31);
}
/* fzgx:end fn_1_F89E4 */

/* fzgx:begin fn_1_F8A04 */
// Clears the spline object's reset flag.
void fn_1_F8A04(void) {
    ((u32 *)&lbl_1_bss_7F0C0)[4672] = 0;
}
/* fzgx:end fn_1_F8A04 */

/* fzgx:begin fn_1_F8A18 */
void fn_1_F8A18(void) {
    fn_1_F8A7C();
}
/* fzgx:end fn_1_F8A18 */

/* fzgx:begin fn_1_F8A38 */
// Tests the spline flag selected by the low byte of the input.
u32 fn_1_F8A38(u32 value) {
    return __rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4673], ((value & 0xff) + 1) & 0x1f, 31, 31);
}
/* fzgx:end fn_1_F8A38 */

/* fzgx:begin fn_1_F8A58 */
// Sets the spline flag selected by the low byte of the input.
void fn_1_F8A58(u32 value) {
    ((u32 *)&lbl_1_bss_7F0C0)[4673] |= 0x80000000u >> (value & 0xff);
}
/* fzgx:end fn_1_F8A58 */

/* fzgx:begin fn_1_F8A7C */
// Clears the spline object's state field.
void fn_1_F8A7C(void) {
    ((u32 *)&lbl_1_bss_7F0C0)[4673] = 0;
}
/* fzgx:end fn_1_F8A7C */

/* fzgx:begin fn_1_F8A90 */
void fn_1_F8A90(void) {
    u32 i;

    for (i = 0; (i & 0xff) < 6; i++) {
        fn_1_F8AFC(i);
    }
}
/* fzgx:end fn_1_F8A90 */

/* fzgx:begin fn_1_F8AD4 */
// Sets the spline state bit selected by the caller.
void fn_1_F8AD4(u32 value) {
    u32* state_word = (u32*)((u8*)&lbl_1_bss_7F0C0 + 0x4900);

    *state_word |= 0x80000000u >> ((value & 0xff) + 0x10);
}
/* fzgx:end fn_1_F8AD4 */

/* fzgx:begin fn_1_F8AFC noprologue */
#include "types.h"

struct fn_1_F8AFC_lbl_1_bss_7F0C0 {
    u8 pad_0[0x4900];
    u32 unk_4900;
};

extern struct fn_1_F8AFC_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;

void fn_1_F8AFC(u32 arg0) {
    u32 v0;
    v0 = lbl_1_bss_7F0C0.unk_4900;
    lbl_1_bss_7F0C0.unk_4900 = (v0 & ~((u32)0x80000000 >> ((arg0 & 0xFF) + 16)));
}
/* fzgx:end fn_1_F8AFC */

/* fzgx:begin fn_1_F8B24 */
void fn_1_F8B24(void) {
    fn_1_F8B64();
    fn_1_F8BA8();
    fn_1_F8B7C();
    fn_1_F8BD4();
}
/* fzgx:end fn_1_F8B24 */

/* fzgx:begin fn_1_F8B50 */
// Mark the spline state as initialized.
void fn_1_F8B50(void) {
    *(u32 *)((u8 *)&lbl_1_bss_7F0C0 + 0x4910) = 1;
}
/* fzgx:end fn_1_F8B50 */

/* fzgx:begin fn_1_F8B64 */
// Clear the spline state counters.
void fn_1_F8B64(void) {
    ((u32 *)&lbl_1_bss_7F0C0)[4676] = 0;
    ((u32 *)&lbl_1_bss_7F0C0)[4677] = 0;
}
/* fzgx:end fn_1_F8B64 */

/* fzgx:begin fn_1_F8B7C */
void fn_1_F8B7C(void) {
    fn_1_F8C28(0x80000000u);
    fn_1_F8C28(0x40000000u);
}
/* fzgx:end fn_1_F8B7C */

/* fzgx:begin fn_1_F8BA8 */
void fn_1_F8BA8(void) {
    fn_1_F8CCC(0x80000000u);
    fn_1_F8CCC(0x40000000u);
}
/* fzgx:end fn_1_F8BA8 */

/* fzgx:begin fn_1_F8BD4 */
void fn_1_F8BD4(void) {
    fn_1_F8CA0(0);
    fn_1_F8CA0(1);
}
/* fzgx:end fn_1_F8BD4 */

/* fzgx:begin fn_1_F8C00 */
// Sets the bit corresponding to the spline index.
void fn_1_F8C00(s32 value) {
    value *= 2;
    (&lbl_1_bss_7F0C0.unk_104)[4676 - 65] |= (((u32)1 << 31) >> (31 - value));
}
/* fzgx:end fn_1_F8C00 */

/* fzgx:begin fn_1_F8C28 */
// Clears the bit corresponding to the spline index.
void fn_1_F8C28(s32 value) {
    value *= 2;
    (&lbl_1_bss_7F0C0.unk_104)[4676 - 65] &= ~(((u32)1 << 31) >> (31 - value));
}
/* fzgx:end fn_1_F8C28 */

/* fzgx:begin fn_1_F8C50 noprologue */
#include "types.h"

struct fn_1_F8C50_lbl_1_bss_7F0C0 {
    u8 pad_0[0x4910];
    u32 unk_4910;
};

extern struct fn_1_F8C50_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;

u8 fn_1_F8C50(s32 arg0) {
    u32 shift = 32 - (arg0 * 2);
    u32 value = lbl_1_bss_7F0C0.unk_4910;
    shift &= 31;
    return (u8)__rlwnm(value, shift, 31, 31);
}
/* fzgx:end fn_1_F8C50 */

/* fzgx:begin fn_1_F8C74 */
// Sets the bit corresponding to the supplied spline index.
void fn_1_F8C74(s32 value) {
    value *= 2;
    *((u32*)((u8*)&lbl_1_bss_7F0C0 + 0x4910)) |= (((u32)1 << 31) >> (31 - (value + 1)));
}
/* fzgx:end fn_1_F8C74 */

/* fzgx:begin fn_1_F8CA0 */
// Clears the bit corresponding to the spline index.
void fn_1_F8CA0(s32 value) {
    value *= 2;
    ((u32 *)&lbl_1_bss_7F0C0)[4676] &= ~(((u32)1 << 31) >> (31 - (value + 1)));
}
/* fzgx:end fn_1_F8CA0 */

/* fzgx:begin fn_1_F8CCC */
// Clears the bit selected by value from the spline state mask.
void fn_1_F8CCC(s32 value) {
    ((u32 *)&lbl_1_bss_7F0C0)[4677] &= ~(((u32)1 << 31) >> (31 - value));
}
/* fzgx:end fn_1_F8CCC */

/* fzgx:begin fn_1_F8CF0 */
struct Spline_Bss_4914 {
    u8 pad[0x4914];
    u32 val;
};

u8 fn_1_F8CF0(s32 shift) {
    u32 val = ((struct Spline_Bss_4914 *)&lbl_1_bss_7F0C0)->val;
    return __rlwnm(val, (32 - shift) & 0x1F, 31, 31);
}
/* fzgx:end fn_1_F8CF0 */

/* fzgx:begin fn_1_F8D10 */
// Clamps the spline counter to its maximum permitted value.
u32 fn_1_F8D10(void) {
    u32 value = 99999;

    if (((u32 *)&lbl_1_bss_7F0C0)[4670] > value) {
        ((u32 *)&lbl_1_bss_7F0C0)[4670] = value;
    }
    return ((u32 *)&lbl_1_bss_7F0C0)[4670];
}
/* fzgx:end fn_1_F8D10 */

/* fzgx:begin fn_1_F8D38 */
// Clamps the spline limit and stores it in the shared spline state.
void fn_1_F8D38(u32 value) {
    if (value > 0x1869F) {
        value = 0x1869F;
    }
    ((u32 *)&lbl_1_bss_7F0C0)[4670] = value;
}
/* fzgx:end fn_1_F8D38 */

/* fzgx:begin fn_1_F8D5C */
struct fn_1_F8D5C_Copy440 { u32 a[110]; };

extern u32 lbl_1_rodata_6E38;
extern void fn_80008BA8(u32, u32, u32);

void fn_1_F8D5C(u32 arg0, u32 arg1) {
    struct fn_1_F8D5C_Copy440 loc_8;
    /* frame */
    loc_8 = *(struct fn_1_F8D5C_Copy440 *)&lbl_1_rodata_6E38;
    fn_80008BA8(arg1, (u32)((u8 *)&loc_8 + ((s16)arg0 * 10)), 10);
}
/* fzgx:end fn_1_F8D5C */

/* fzgx:begin fn_1_F8DC4 */
struct Table {
    u32 values[4][6];
};

void fn_1_F8DC4(s16 index0, s16 index1, void *arg0) {
    struct Table table;

    table = lbl_1_rodata_6FF0;
    fn_80083DB0(arg0, table.values[index0][index1]);
}
/* fzgx:end fn_1_F8DC4 */

/* fzgx:begin fn_1_F9028 */
typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} Element;

typedef struct {
    Element elements[44];
} Table;

extern Table lbl_1_rodata_6E38;
extern void fn_80008BA8(void *dst, const void *src, u32 size);
extern s32 fn_1_F9CA0(s32, u8);
extern s32 fn_1_F21B8(s16);

static inline void get_element(Element *dst, s16 index) {
    Table table;
    table = lbl_1_rodata_6E38;
    fn_80008BA8(dst, &table.elements[index], 10);
}

static inline s16 find_element_by_unk2(s16 unk_2, s16 nth) {
    Element elem;
    s16 i;
    s16 count;

    i = 0;
    count = 0;
    for (; i < 44; i++) {
        get_element(&elem, i);
        if (elem.unk_2 == unk_2) {
            if (count == nth) {
                return i;
            }
            count++;
        }
    }
    return -1;
}

static inline s16 get_element_index_in_unk2_group(s16 index) {
    Element elem;
    s16 i;

    get_element(&elem, index);
    for (i = 0; ; i++) {
        if (find_element_by_unk2(elem.unk_2, i) == index) {
            return i;
        }
    }
}

static inline s32 check_case2(s16 arg) {
    return fn_1_F21B8(arg) != 0;
}

s32 fn_1_F9028(s16 arg0) {
    s32 ret = 0;
    Element elem;
    s16 group_idx;

    get_element(&elem, arg0);
    group_idx = get_element_index_in_unk2_group(arg0);

    switch (elem.unk_2) {
    case 0:
        ret = fn_1_F9CA0(0, group_idx);
        break;
    case 1:
        ret = __rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4672], ((u8)group_idx + 1) & 0x1F, 31, 31) != 0;
        break;
    case 2:
        ret = check_case2(elem.unk_8);
        break;
    case 3:
        ret = (u8)__rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4677], (32 - group_idx) & 0x1F, 31, 31) != 0;
        break;
    }

    return ret;
}
/* fzgx:end fn_1_F9028 */

/* fzgx:begin fn_1_F9244 */
extern s32 fn_1_F9D44(u8 index);
extern s32 ghost_test_record_flag0(s16 value);

typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} Element;

typedef struct {
    Element elements[44];
} Table;

extern Table lbl_1_rodata_6E38;
extern void fn_80008BA8(void *dst, const void *src, u32 size);

static inline void get_element(Element *dst, s16 index) {
    Table table;
    table = lbl_1_rodata_6E38;
    fn_80008BA8(dst, &table.elements[index], 10);
}

static inline s16 find_element_by_unk2(s16 unk_2, s16 nth) {
    Element elem;
    s16 i;
    s16 count;

    i = 0;
    count = 0;
    for (; i < 44; i++) {
        get_element(&elem, i);
        if (elem.unk_2 == unk_2) {
            if (count == nth) {
                return i;
            }
            count++;
        }
    }
    return -1;
}

static inline s16 get_element_index_in_unk2_group(s16 index) {
    Element elem;
    s16 i;

    get_element(&elem, index);
    for (i = 0; ; i++) {
        if (find_element_by_unk2(elem.unk_2, i) == index) {
            return i;
        }
    }
}

s32 fn_1_F9244(s16 arg0) {
    s32 ret = 0;
    Element elem;
    s16 group_idx;

    get_element(&elem, arg0);
    group_idx = get_element_index_in_unk2_group(arg0);

    switch (elem.unk_2) {
    case 0:
        ret = fn_1_F9D44(group_idx) ? 1 : 0;
        break;
    case 1:
        ret = __rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4673], ((u8)group_idx + 1) & 0x1F, 31, 31) != 0;
        break;
    case 2:
        ret = ghost_test_record_flag0(elem.unk_8) ? 1 : 0;
        break;
    case 3:
        ret = (u8)__rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4676], (32 - group_idx * 2) & 0x1F, 31, 31) != 0;
        break;
    }

    return ret;
}
/* fzgx:end fn_1_F9244 */

/* fzgx:begin fn_1_F946C */
extern void fn_1_F9CD0(s32 arg0, u8 arg1);
extern void ghost_set_record_flag2(s16 value);


typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} Element;

typedef struct {
    Element elements[44];
} Table;

extern Table lbl_1_rodata_6E38;
extern void fn_80008BA8(void *dst, const void *src, u32 size);

static inline void get_element(Element *dst, s16 index) {
    Table table;
    table = lbl_1_rodata_6E38;
    fn_80008BA8(dst, &table.elements[index], 10);
}

static inline s16 find_element_by_unk2(s16 unk_2, s16 nth) {
    Element elem;
    s16 i;
    s16 count;

    i = 0;
    count = 0;
    for (; i < 44; i++) {
        get_element(&elem, i);
        if (elem.unk_2 == unk_2) {
            if (count == nth) {
                return i;
            }
            count++;
        }
    }
    return -1;
}

static inline s16 get_element_index_in_unk2_group(s16 index) {
    Element elem;
    s16 i;

    get_element(&elem, index);
    for (i = 0; ; i++) {
        if (find_element_by_unk2(elem.unk_2, i) == index) {
            return i;
        }
    }
}

void fn_1_F946C(s16 arg0) {
    Element elem;
    s16 group_idx;

    get_element(&elem, arg0);
    group_idx = get_element_index_in_unk2_group(arg0);

    switch (elem.unk_2) {
    case 0:
        fn_1_F9CD0(0, group_idx);
        break;
    case 1:
        ((u32 *)&lbl_1_bss_7F0C0)[4672] |= 0x80000000 >> (u8)group_idx;
        break;
    case 2:
        ghost_set_record_flag2(elem.unk_8);
        break;
    case 3:
        ((u32 *)&lbl_1_bss_7F0C0)[4677] |= 0x80000000 >> (31 - group_idx);
        break;
    }
}
/* fzgx:end fn_1_F946C */

/* fzgx:begin fn_1_F965C */
extern s32 fn_1_F9DC4(u8 index);
extern s32 fn_1_F210C(s16 value);

typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} Element;

typedef struct {
    Element elements[44];
} Table;

extern Table lbl_1_rodata_6E38;
extern void fn_80008BA8(void *dst, const void *src, u32 size);

static inline void get_element(Element *dst, s16 index) {
    Table table;
    table = lbl_1_rodata_6E38;
    fn_80008BA8(dst, &table.elements[index], 10);
}

static inline s16 find_element_by_unk2(s16 unk_2, s16 nth) {
    Element elem;
    s16 i;
    s16 count;

    i = 0;
    count = 0;
    for (; i < 44; i++) {
        get_element(&elem, i);
        if (elem.unk_2 == unk_2) {
            if (count == nth) {
                return i;
            }
            count++;
        }
    }
    return -1;
}

static inline s16 get_element_index_in_unk2_group(s16 index) {
    Element elem;
    s16 i;

    get_element(&elem, index);
    for (i = 0; ; i++) {
        if (find_element_by_unk2(elem.unk_2, i) == index) {
            return i;
        }
    }
}

s32 fn_1_F965C(s16 arg0) {
    s32 ret = 0;
    Element elem;
    s16 group_idx;

    get_element(&elem, arg0);
    group_idx = get_element_index_in_unk2_group(arg0);

    switch (elem.unk_2) {
    case 0:
        ret = fn_1_F9DC4(group_idx) ? 1 : 0;
        break;
    case 1:
        ret = (u8)__rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4672], ((u8)group_idx + 0x11) & 0x1F, 31, 31) != 0;
        break;
    case 2:
        ret = !fn_1_F210C(elem.unk_8);
        break;
    case 3:
        ret = (u8)__rlwnm(((u32 *)&lbl_1_bss_7F0C0)[4676], (32 - (group_idx * 2 + 1)) & 0x1F, 31, 31) != 0;
        break;
    }

    return ret;
}
/* fzgx:end fn_1_F965C */

/* fzgx:begin fn_1_F9888 */
extern void fn_1_F9E10(u8 index);
extern void ghost_set_record_flag1(s16 value);


typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} Element;

typedef struct {
    Element elements[44];
} Table;

extern Table lbl_1_rodata_6E38;
extern void fn_80008BA8(void *dst, const void *src, u32 size);

static inline void get_element(Element *dst, s16 index) {
    Table table;
    table = lbl_1_rodata_6E38;
    fn_80008BA8(dst, &table.elements[index], 10);
}

static inline s16 find_element_by_unk2(s16 unk_2, s16 nth) {
    Element elem;
    s16 i;
    s16 count;

    i = 0;
    count = 0;
    for (; i < 44; i++) {
        get_element(&elem, i);
        if (elem.unk_2 == unk_2) {
            if (count == nth) {
                return i;
            }
            count++;
        }
    }
    return -1;
}

static inline s16 get_element_index_in_unk2_group(s16 index) {
    Element elem;
    s16 i;

    get_element(&elem, index);
    for (i = 0; ; i++) {
        if (find_element_by_unk2(elem.unk_2, i) == index) {
            return i;
        }
    }
}

void fn_1_F9888(s16 arg0) {
    Element elem;
    s16 group_idx;

    get_element(&elem, arg0);
    group_idx = get_element_index_in_unk2_group(arg0);

    switch (elem.unk_2) {
    case 0:
        fn_1_F9E10(group_idx);
        break;
    case 1:
        {
            u32 mask = 0x80000000 >> ((u8)group_idx + 16);
            ((u32 *)&lbl_1_bss_7F0C0)[4672] &= ~mask;
        }
        break;
    case 2:
        ghost_set_record_flag1(elem.unk_8);
        break;
    case 3:
        {
            u32 mask = 0x80000000 >> (31 - (group_idx * 2 + 1));
            ((u32 *)&lbl_1_bss_7F0C0)[4676] &= ~mask;
        }
        break;
    }
}
/* fzgx:end fn_1_F9888 */

/* fzgx:begin fn_1_F9C6C */
void fn_1_F9C6C(void) {
    fn_1_F9D04(0);
    fn_1_F9D04(1);
    fn_1_F9D04(2);
}
/* fzgx:end fn_1_F9C6C */

/* fzgx:begin fn_1_F9CA0 noprologue */
#include "types.h"

extern struct fn_1_F9CA0_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;

struct fn_1_F9CA0_lbl_1_bss_7F0C0_60_E48 {
    u8 pad_0[0x4];
    u16 unk_4;
    u8 pad_6[0x2A];
};
struct fn_1_F9CA0_lbl_1_bss_7F0C0 {
    u8 pad_0[0x60];
    struct fn_1_F9CA0_lbl_1_bss_7F0C0_60_E48 unk_60[1];
};

u32 fn_1_F9CA0(u32 arg0, u32 arg1) {
    return (lbl_1_bss_7F0C0.unk_60[(arg0 & 0xFF)].unk_4 & ((s32)(0x10000 + -32768) >> (arg1 & 0xFF)));
}
/* fzgx:end fn_1_F9CA0 */

/* fzgx:begin fn_1_F9CD0 */
// Sets the requested flag in an indexed spline record.
void fn_1_F9CD0(u8 index, u8 shift) {
    u16 *flags = &lbl_1_bss_7F0C0.unk_64;
    flags[index * 0x18] |= 0x8000 >> shift;
}
/* fzgx:end fn_1_F9CD0 */

/* fzgx:begin fn_1_F9D04 */
// Clear the selected spline entry's status field.
void fn_1_F9D04(u8 index) {
    (&lbl_1_bss_7F0C0.unk_64)[index * 0x18] = 0;
}
/* fzgx:end fn_1_F9D04 */

/* fzgx:begin fn_1_F9D24 */
void fn_1_F9D24(void) {
    fn_1_F9D90();
}
/* fzgx:end fn_1_F9D24 */

/* fzgx:begin fn_1_F9D44 */
// Tests the requested spline flag.
u32 fn_1_F9D44(u32 arg) {
    return lbl_1_bss_7F0C0.unk_68 & (0x8000 >> (arg & 0xff));
}
/* fzgx:end fn_1_F9D44 */

/* fzgx:begin fn_1_F9D68 */
void fn_1_F9D68(u32 arg) {
    lbl_1_bss_7F0C0.unk_68 |= 0x8000 >> (arg & 0xff);
}
/* fzgx:end fn_1_F9D68 */

/* fzgx:begin fn_1_F9D90 */
// Clear the spline object's active flags.
void fn_1_F9D90(void) {
    lbl_1_bss_7F0C0.unk_68 = 0;
}
/* fzgx:end fn_1_F9D90 */

/* fzgx:begin fn_1_F9DA4 */
void fn_1_F9DA4(void) {
    fn_1_F9E38();
}
/* fzgx:end fn_1_F9DA4 */

/* fzgx:begin fn_1_F9DC4 */
// Return the bit selected by the low byte of the requested flag index.
u32 fn_1_F9DC4(u32 arg) {
    return lbl_1_bss_7F0C0.unk_6A & (0x8000 >> (arg & 0xff));
}
/* fzgx:end fn_1_F9DC4 */

/* fzgx:begin fn_1_F9DE8 */
void fn_1_F9DE8(u32 param) {
    lbl_1_bss_7F0C0.unk_6A |= 0x8000 >> (param & 0xFF);
}
/* fzgx:end fn_1_F9DE8 */

/* fzgx:begin fn_1_F9E10 */
// Clear the bit selected by the low byte of the shift amount.
void fn_1_F9E10(u32 param) {
    lbl_1_bss_7F0C0.unk_6A &= ~(0x8000 >> (param & 0xFF));
}
/* fzgx:end fn_1_F9E10 */

/* fzgx:begin fn_1_F9E38 */
// Clear the spline object's status field.
void fn_1_F9E38(void) {
    lbl_1_bss_7F0C0.unk_6A = 0;
}
/* fzgx:end fn_1_F9E38 */

/* fzgx:begin fn_1_F9E4C */
void fn_1_F9E4C(void) {
    fn_1_F9EE4(0);
    fn_1_F9EE4(1);
    fn_1_F9EE4(2);
}
/* fzgx:end fn_1_F9E4C */

/* fzgx:begin fn_1_F9E80 noprologue */
#include "types.h"

extern struct fn_1_F9E80_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;

struct fn_1_F9E80_lbl_1_bss_7F0C0_60_E48 {
    u8 pad_0[0x6];
    u16 unk_6;
    u8 pad_8[0x28];
};
struct fn_1_F9E80_lbl_1_bss_7F0C0 {
    u8 pad_0[0x60];
    struct fn_1_F9E80_lbl_1_bss_7F0C0_60_E48 unk_60[1];
};

u32 fn_1_F9E80(u32 arg0, u32 arg1) {
    return (lbl_1_bss_7F0C0.unk_60[(arg0 & 0xFF)].unk_6 & ((s32)(0x10000 + -32768) >> (arg1 & 0xFF)));
}
/* fzgx:end fn_1_F9E80 */

/* fzgx:begin fn_1_F9EB0 noprologue */
#include "types.h"

extern struct fn_1_F9EB0_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;

struct fn_1_F9EB0_lbl_1_bss_7F0C0_60_E48 {
    u8 pad_0[0x6];
    u16 unk_6;
    u8 pad_8[0x28];
};
struct fn_1_F9EB0_lbl_1_bss_7F0C0 {
    u8 pad_0[0x60];
    struct fn_1_F9EB0_lbl_1_bss_7F0C0_60_E48 unk_60[1];
};

u32 fn_1_F9EB0(u32 arg0, u32 arg1) {
    u32 v0;
    v0 = (0x10000 + -32768);
    lbl_1_bss_7F0C0.unk_60[(arg0 & 0xFF)].unk_6 = (lbl_1_bss_7F0C0.unk_60[(arg0 & 0xFF)].unk_6 | ((s32)v0 >> (arg1 & 0xFF)));
    return v0;
}
/* fzgx:end fn_1_F9EB0 */

/* fzgx:begin fn_1_F9EE4 */
// Reset one spline slot and clear its working buffer.
void fn_1_F9EE4(s32 arg0) {
    *(u16 *)((u8 *)&lbl_1_bss_7F0C0 + ((arg0 & 0xFF) * 0x30) + 0x66) = 0;
    fn_80008BEC((u8 *)&lbl_1_bss_7F0C0 + ((arg0 & 0xFF) * 0x30) + 0x6C, 0, 0x28);
}
/* fzgx:end fn_1_F9EE4 */

/* fzgx:begin fn_1_F9F2C noprologue */
#include "types.h"

extern u8 lbl_1_bss_7F0C0[];

void fn_1_F9F2C(u8 a, u8 b, u8 c, u8 d) {
    s32 index;

    if (a >= 0x29) {
        return;
    }
    if (b >= 4) {
        return;
    }
    if (c >= 5) {
        return;
    }
    if (d >= 5) {
        return;
    }

    index = b * 20 + a * 100 + c * 4 + d;
    lbl_1_bss_7F0C0[0x4956 + index / 8] |= 1 << (index % 8);
}
/* fzgx:end fn_1_F9F2C */

/* fzgx:begin fn_1_F9FB4 */
void fn_1_F9FB4(void) {
    u32 ptr = lbl_1_bss_84420;

    if ((*(u8 *)(ptr + 0x1) & 1) == 0) {
        *(u8 *)(ptr + 0x1) |= 2;
    }

    ptr = lbl_1_bss_84420;
    *(u8 *)(ptr + 0x1) |= 1;
}
/* fzgx:end fn_1_F9FB4 */

/* fzgx:begin fn_1_F9FEC */
// Returns the low flag bit stored in the spline state.
u32 fn_1_F9FEC(void) {
    u32 ptr = lbl_1_bss_84420;
    return (*(u8 *)(ptr + 0x1)) & 1;
}
/* fzgx:end fn_1_F9FEC */

/* fzgx:begin fn_1_FA004 */
// Reads the second status byte and returns its bit-mask value.
u32 fn_1_FA004(void) {
    u32 ptr = lbl_1_bss_84420;
    return (*(u8 *)(ptr + 0x1)) & 2;
}
/* fzgx:end fn_1_FA004 */

/* fzgx:begin fn_1_FA01C noprologue */
#include "types.h"

extern struct fn_1_FA01C_lbl_1_bss_84420 lbl_1_bss_84420;

struct fn_1_FA01C_lbl_1_bss_84420 {
    u32 unk_0;
};

u32 fn_1_FA01C(void) {
    u32 v0;
    v0 = lbl_1_bss_84420.unk_0;
    *(u8 *)((u8 *)v0 + 1) = (*(u8 *)((u8 *)v0 + 1) & 0xFFFFFFFD);
    return v0;
}
/* fzgx:end fn_1_FA01C */

/* fzgx:begin fn_1_FA038 */
void fn_1_FA038(void) {
    u32 ptr = lbl_1_bss_84420;

    if ((*(u8 *)(ptr + 2) & 1) == 0) {
        *(u8 *)(ptr + 2) |= 2;
    }

    ptr = lbl_1_bss_84420;
    *(u8 *)(ptr + 2) |= 1;
}
/* fzgx:end fn_1_FA038 */

/* fzgx:begin fn_1_FA070 */
u32 fn_1_FA070(void) {
    u32 ptr = lbl_1_bss_84420;
    // Test the object's low flag bit.
    return (*(u8 *)(ptr + 2)) & 1;
}
/* fzgx:end fn_1_FA070 */

/* fzgx:begin fn_1_FA088 */
u32 fn_1_FA088(void) {
    u32 ptr = lbl_1_bss_84420;
    return (*(u8 *)(ptr + 2)) & 2;
}
/* fzgx:end fn_1_FA088 */

/* fzgx:begin fn_1_FA0A0 noprologue */
#include "types.h"

extern struct fn_1_FA0A0_lbl_1_bss_84420 lbl_1_bss_84420;

struct fn_1_FA0A0_lbl_1_bss_84420 {
    u32 unk_0;
};

u32 fn_1_FA0A0(void) {
    u32 v0;
    v0 = lbl_1_bss_84420.unk_0;
    *(u8 *)((u8 *)v0 + 2) = (*(u8 *)((u8 *)v0 + 2) & 0xFFFFFFFD);
    return v0;
}
/* fzgx:end fn_1_FA0A0 */

/* fzgx:begin fn_1_FA0BC noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x4900];
    u32 flags;
} SplineGlobalState;

extern SplineGlobalState lbl_1_bss_7F0C0;

u32 fn_1_FA0BC(s32 mode) {
    if (mode == 1) {
        u32 flags = lbl_1_bss_7F0C0.flags;
        s16 i;

        for (i = 1; i < 6; i++) {
            if (__rlwnm(flags, ((((u8)i) + 1) & 0x1f), 31, 31) == 0) {
                return 0;
            }
        }
        return 1;
    } else {
        u32 flags = lbl_1_bss_7F0C0.flags;
        s16 i;

        for (i = 0; i < 6; i++) {
            if (__rlwnm(flags, ((((u8)i) + 1) & 0x1f), 31, 31) != 0) {
                return 1;
            }
        }
        return 0;
    }
}
/* fzgx:end fn_1_FA0BC */

/* fzgx:begin fn_1_FA154 */
void fn_1_FA154(u32 byte_index, u32 bit_index) {
    u32 index;
    u32 ptr;
    u32 bit;
    u32 addr;
    index = byte_index & 0xff;
    ptr = lbl_1_bss_84420;
    bit = bit_index & 0xff;
    addr = ptr;
    addr = addr + index;
    *(u8 *)(3 + addr) |= 1 << bit;
}
/* fzgx:end fn_1_FA154 */

/* fzgx:begin fn_1_FA180 */
u32 fn_1_FA180(u8 arg0, u8 arg1) {
    u8 *ptr = (u8 *)lbl_1_bss_84420;
    u32 bit = 1 << arg1;
    u32 val = (ptr + arg0)[3];
    return val & bit;
}
/* fzgx:end fn_1_FA180 */

/* fzgx:begin fn_1_FA1A8 noprologue */
#include "types.h"

extern u32 fn_1_FA69C(u32);

u32 fn_1_FA1A8(u32 arg0) {
    u32 t0;
    t0 = fn_1_FA69C((s16)arg0);
    return ((u32)((-t0) | t0) >> 31);
}
/* fzgx:end fn_1_FA1A8 */

/* fzgx:begin fn_1_FA1D8 */
extern void mathutil_quat_mult(f32 *, f32 *, f32 *);
extern void fn_1_F56F8(f32 *out, f32 *in);
extern const f32 lbl_1_rodata_6D78;
extern void fn_1_F57A8(f32 *out, f32 *in);
extern const f32 lbl_1_rodata_6D70;
extern f64 fn_80088538(f32);
extern f64 fn_800883E8(f32);
extern f32 lbl_8006D0B4(f32);
extern f64 fn_80087E80(f32);
extern void fn_8006E8DC(void *);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_F5B88(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_9AD88(void);
extern void fn_1_F65A0(Obj_1_data_2A7E0_At3C *);
extern void fn_1_F7578(void);
extern void fn_8001D32C(u32 *);
extern void fn_80008BEC(void *dst, s32 value, u32 size);
extern void fn_1_F75D8(void *, int, int, int);
extern void fn_1_F8918(u8 *, u8 *);
extern s32 fn_8008023C(u8 *, Obj_1_bss_7F0C0 *, u32);
extern void fn_1_F85A0(Obj_1_bss_7F0C0 *, u8 *);
extern u16 lbl_1_data_414[36];
extern int fn_1_8D5F0(s16 value);
extern void fn_1_F7CAC(s16);
extern s32 fn_1_F7BE4(s16);
extern void fn_1_F7F48(s16 value);
extern int fn_1_14D6D8(s16 value);
extern void fn_1_F83F0(s16 value);
extern void fn_1_F8214(s16 value);
extern void fn_1_F8A04(void);
extern void fn_1_F8A90(void);
extern void fn_1_F8A7C(void);
extern void fn_1_F8AFC(u32 value);
extern void fn_1_F8B64(void);
extern void fn_1_F8BA8(void);
extern void fn_1_F8B7C(void);
extern void fn_1_F8BD4(void);
extern void fn_1_F8C28(s32 value);
extern void fn_1_F8CCC(s32 value);
extern void fn_1_F8CA0(s32 value);
extern struct Table lbl_1_rodata_6FF0;
extern void fn_80083DB0(void *arg0, u32 arg1);
extern void fn_1_F9D04(u8 index);
extern void fn_1_F9D90(void);
extern void fn_1_F9E38(void);
extern void fn_1_F9EE4(s32 value);
extern u8 fn_1_FA69C(s32 index);
extern void fn_1_3EF14(void *);
extern s32 fn_1_58C4(void);
extern void fn_1_FA89C(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_FB0B4(Obj_1_bss_84428 *data);
extern void fn_1_FB180(int *value);
extern void fn_1_9AD54(void);
extern void fn_1_FB18C(void);

extern void fn_1_F8918(u8 *, u8 *);
extern u16 lbl_1_data_414[36];
extern void fn_8001D3E4(int index, int value);
extern u32 lbl_801A66A0;


extern const struct fn_1_FA1D8_lbl_1_rodata_7470_pool {
    f64 unk_0;
} lbl_1_rodata_7470;

extern u32 fn_1_F2740(u32, u32);
extern char *strncpy(char *, const char *, size_t);
extern s32 lbl_801A66B4;

typedef struct SplineTimeEntry {
    u32 time0;
    u32 time1;
    char name[16];
    s16 unk18;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
} SplineTimeEntry;

typedef struct SplineTimeTable {
    SplineTimeEntry entries[10];
    SplineTimeEntry best;
    s16 unk160;
    u8 unk162;
    u8 unk163;
    u8 unk164;
    u8 unk165;
    u8 unk166;
    u8 unk167;
    u8 unk168;
} SplineTimeTable;

/* retail's spline.c .data block, addressed off one section base */
extern u8 lbl_1_data_3ECFC__fzgx_offset_0[];
extern u8 lbl_1_data_3ED0C__fzgx_offset_0[];
extern u8 lbl_1_data_3ED20__fzgx_offset_0[];
extern u8 lbl_1_data_3ED34__fzgx_offset_0[];
extern u8 lbl_1_data_3ED48__fzgx_offset_0[];
extern u8 lbl_1_data_3ED5C__fzgx_offset_0[];
extern u8 lbl_1_data_3ED70__fzgx_offset_0[];
extern u8 lbl_1_data_3ED84__fzgx_offset_0[];
extern u8 lbl_1_data_3ED98__fzgx_offset_0[];
extern u8 lbl_1_data_3EDAC__fzgx_offset_0[];
extern u8 lbl_1_data_3EDE8__fzgx_offset_0[];
extern u8 lbl_1_data_3EDF8__fzgx_offset_0[];
extern u8 lbl_1_data_3EE0C__fzgx_offset_0[];
extern u8 lbl_1_data_3EE20__fzgx_offset_0[];
extern u8 lbl_1_data_3EE34__fzgx_offset_0[];
extern u8 lbl_1_data_3EE48__fzgx_offset_0[];
extern u8 lbl_1_data_3EE5C__fzgx_offset_0[];
extern u8 lbl_1_data_3EE6C__fzgx_offset_0[];
extern u8 lbl_1_data_3EE7C__fzgx_offset_0[];
extern u8 lbl_1_data_3EE90__fzgx_offset_0[];
static union { u32 w[248]; u8 v[0x3E0]; } fzgx_pool_init_lbl_1_data_3E910 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5B436172, 0x2020205D, 0x25730A00, 0x4E756D20, 0x25640A00, 0x5B435F53, 0x686F705D, 0x25730A00,
    0x5B506172, 0x7473205D, 0x25730A00, 0x5B505F53, 0x686F705D, 0x25730A00, 0x5B436F75, 0x72736520,
    0x2020205D, 0x25640A00, 0x5B436F75, 0x72736553, 0x686F705D, 0x25640A00, 0x5B4D7573, 0x69632020,
    0x2020205D, 0x25640A00, 0x5B4D7573, 0x69632053, 0x686F705D, 0x25640A00, 0x5B47686F, 0x73745368,
    0x6F702532, 0x645D2564, 0xA000000, 0x5B47686F, 0x73742020, 0x20202532, 0x645D2564, 0xA000000,
    0x53746F72, 0x79000000, 0x0, 0x83588367, 0x815B838A, 0x815B0000, 0x436F7572, 0x73650000,  /* fzgx-allow: A1 retail data bytes */
    0x8352815B, 0x83580000, 0x47686F73, 0x74000000, 0x8353815B, 0x83588367, 0x0, 0x536F756E,
    0x64000000, 0x83548345, 0x83938368, 0x0, 0x50726F6C, 0x6F677565, 0x20426C61, 0x636B2053,
    0x6861646F, 0x77277320, 0x44697367, 0x72616365, 0x0, 0x83558358, 0x8367815B, 0x838A815B,
    0x83498375, 0x834C8383, 0x83768365, 0x83938374, 0x8340838B, 0x83528393, 0x20837683, 0x8D838D81,
    0x5B834F00, 0x43686170, 0x74657220, 0x31204361, 0x70746169, 0x6E204661, 0x6C636F6E, 0x20547261,
    0x696E7300, 0x91E63198, 0x6220834C, 0x83838376, 0x83658393, 0x83748340, 0x838B8352, 0x839382CC,
    0x93C18C50, 0x0, 0x43686170, 0x74657220, 0x3220476F, 0x726F683A, 0x20546865, 0x2056656E,
    0x67656675, 0x6C205361, 0x6D757261, 0x69000000, 0x91E63298, 0x6220959C, 0x8F5182CC, 0x83548380,
    0x83898343, 0x8353838D, 0x815B0000, 0x43686170, 0x74657220, 0x33204869, 0x67682053, 0x74616B65,  /* fzgx-allow: A1 retail data bytes */
    0x7320696E, 0x204D7574, 0x65204369, 0x74790000, 0x91E63398, 0x6220837E, 0x8385815B, 0x83678356,
    0x83658342, 0x82C591E5, 0x8F9F9589, 0x21000000, 0x43686170, 0x74657220, 0x34204368, 0x616C6C65,
    0x6E676520, 0x6F662074, 0x68652042, 0x6C6F6F64, 0x79204368, 0x61696E00, 0x91E63498, 0x62208946,
    0x9288965C, 0x919691B0, 0x82CC92A7, 0x90ED0000, 0x43686170, 0x74657220, 0x35205361, 0x7665204A,
    0x6F647921, 0x0, 0x91E63598, 0x62208357, 0x83878366, 0x834282F0, 0x8B7E82A6, 0x21000000,
    0x43686170, 0x74657220, 0x3620426C, 0x61636B20, 0x53686164, 0x6F772773, 0x20547261, 0x70000000,
    0x91E63698, 0x62208375, 0x83898362, 0x834E8356, 0x83838368, 0x815B82CC, 0xE3A90000, 0x43686170,  /* fzgx-allow: A1 retail data bytes */
    0x74657220, 0x37205468, 0x6520462D, 0x5A45524F, 0x20477261, 0x6E642050, 0x72697800, 0x91E63798,
    0x6220462D, 0x5A45524F, 0x834F8389, 0x83938376, 0x838A0000, 0x43686170, 0x74657220, 0x38205365,
    0x63726574, 0x73206F66, 0x20746865, 0x20436861, 0x6D70696F, 0x6E204265, 0x6C740000, 0x91E63898,
    0x62208360, 0x83838393, 0x83738349, 0x83938378, 0x838B8367, 0x82CC94E9, 0x96A70000, 0x43686170,
    0x74657220, 0x39204669, 0x6E616C65, 0x3A20456E, 0x74657220, 0x74686520, 0x43726561, 0x746F7273,
    0x0, 0x91E63998, 0x6220916E, 0x91A28EE5, 0x82C682CC, 0x8DC58F49, 0x8C8890ED, 0x0,
    0x41582043, 0x6F757273, 0x65202573, 0x0, 0x41588352, 0x815B8358, 0x20257300, 0x53746166,  /* fzgx-allow: A1 retail data bytes */
    0x66204768, 0x6F737420, 0x25730000, 0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x20257300,
    0x536F756E, 0x6473206F, 0x66202573, 0x0, 0x257382CC, 0x83548345, 0x83938368, 0x0
}};
static union { u32 w[52]; u8 v[0xD0]; } fzgx_pool_init_lbl_1_data_3ECF0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6040502, 0x1191413, 0x16150000, 0x82622E83, 0x74834083, 0x8B835283, 0x93814000, 0x83548380,
    0x83898343, 0x81408353, 0x838D815B, 0x0, 0x83738352, 0x81408140, 0x81408140, 0x81408140,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83588360, 0x8385838F, 0x815B8367, 0x81408140, 0x0, 0x83578387, 0x83668342,  /* fzgx-allow: A1 retail data bytes */
    0x81408140, 0x81408140, 0x0, 0x83578387, 0x83938140, 0x835E8369, 0x834A8140, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x837E835A, 0x83588140, 0x8341838D, 0x815B8140, 0x0, 0x8358815B, 0x8370815B, 0x81408341,  /* fzgx-allow: A1 retail data bytes */
    0x838D815B, 0x0, 0x836A815B, 0x838B835A, 0x83938140, 0x81408140, 0x0, 0x8353837D,  /* fzgx-allow: A1 retail data bytes */
    0x815B8195, 0x83568349, 0x815B8140, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[57]; char *v[0x39]; } fzgx_pool_init_lbl_1_data_3EDC0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_3ECFC__fzgx_offset_0, (u32)lbl_1_data_3ED0C__fzgx_offset_0, (u32)lbl_1_data_3ED20__fzgx_offset_0, (u32)lbl_1_data_3ED34__fzgx_offset_0, (u32)lbl_1_data_3ED48__fzgx_offset_0, (u32)lbl_1_data_3ED5C__fzgx_offset_0, (u32)lbl_1_data_3ED70__fzgx_offset_0, (u32)lbl_1_data_3ED84__fzgx_offset_0,
    (u32)lbl_1_data_3ED98__fzgx_offset_0, (u32)lbl_1_data_3EDAC__fzgx_offset_0, 0x82622E82, 0x65826082, 0x6B826282, 0x6E826D00, 0x8266826E, 0x8271826E,
    0x82678140, 0x81408140, 0x0, 0x826F8268, 0x8262826E, 0x81408140, 0x81408140, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x82728273, 0x82648276, 0x82608271, 0x82738140, 0x0, 0x8269826E, 0x82638278, 0x81408140,  /* fzgx-allow: A1 retail data bytes */
    0x81408140, 0x0, 0x82738260, 0x826D8260, 0x826A8260, 0x81408140, 0x0, 0x826C2E82,  /* fzgx-allow: A1 retail data bytes */
    0x60827182, 0x71826E82, 0x76814000, 0x82722E82, 0x60827182, 0x71826E82, 0x76814000, 0x826D8264,
    0x8264826B, 0x82728264, 0x826D8140, 0x0, 0x82668195, 0x82728140, 0x81408140, 0x81408140,  /* fzgx-allow: A1 retail data bytes */
    0x0
}};
static union { u32 w[10]; char *v[10]; } fzgx_pool_init_lbl_1_data_3EEA4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_3EDE8__fzgx_offset_0, (u32)lbl_1_data_3EDF8__fzgx_offset_0, (u32)lbl_1_data_3EE0C__fzgx_offset_0, (u32)lbl_1_data_3EE20__fzgx_offset_0, (u32)lbl_1_data_3EE34__fzgx_offset_0, (u32)lbl_1_data_3EE48__fzgx_offset_0, (u32)lbl_1_data_3EE5C__fzgx_offset_0, (u32)lbl_1_data_3EE6C__fzgx_offset_0,
    (u32)lbl_1_data_3EE7C__fzgx_offset_0, (u32)lbl_1_data_3EE90__fzgx_offset_0
}};

static inline u32 scale_time(u32 value) {
    return (u32)(value * lbl_1_rodata_7470.unk_0);
}

#pragma opt_common_subs off
void fn_1_FA1D8(u32 arg0, u32 arg1, SplineTimeTable *table) {
    s32 i;
    s32 k;
    u32 packed;
    u8 hi;
    u8 lo;
    u32 min0;
    u32 sec0;
    u32 min1;
    u32 sec1;

    packed = fn_1_F2740(arg0, arg1);
    min0 = (packed >> 20) & 0xFF;
    sec0 = (packed >> 12) & 0xFF;
    min1 = min0;
    sec1 = sec0;
    min0 *= 4;
    sec0 *= 4;
    min1 *= lbl_1_rodata_7470.unk_0;
    sec1 *= lbl_1_rodata_7470.unk_0;
    for (k = 0; k < 5; k++) {
        if (sec0 >= 60) {
            sec0 -= 60;
            min0++;
        }
    }
    for (k = 0; k < 3; k++) {
        if (sec1 >= 60) {
            sec1 -= 60;
            min1++;
        }
    }

    table->unk160 = 0;
    table->unk162 = 6;
    table->unk165 = 50;
    table->unk164 = 6;
    table->unk166 = 0xFF;
    table->unk167 = 0xFF;
    table->unk168 = 0xFF;
    table->unk163 = 1;
    table->best.time0 = 0x93B3E7;
    table->best.unk18 = 0;
    table->best.time1 = 0;
    table->best.unk1A = 6;
    table->best.unk1C = 50;
    table->best.unk1B = 6;
    table->best.unk1D = 0xFF;
    table->best.unk1E = 0xFF;
    table->best.unk1F = 0xFF;

    for (i = 0; i < 10; i++) {
        table->entries[i].time0 = (min0 << 20) | (sec0 << 12);
        table->entries[i].time1 = (min1 << 20) | (sec1 << 12);
        table->entries[i].unk1A = fzgx_pool_init_lbl_1_data_3ECF0.v[i];
        table->entries[i].unk18 = 0;
        table->entries[i].unk1C = 50;
        table->entries[i].unk1B = fzgx_pool_init_lbl_1_data_3ECF0.v[i];
        table->entries[i].unk1D = 0xFF;
        table->entries[i].unk1E = 0xFF;
        table->entries[i].unk1F = 0xFF;
        if (lbl_801A66B4 == 5) {
            strncpy(table->entries[i].name, fzgx_pool_init_lbl_1_data_3EDC0.v[i], 16);
        } else {
            strncpy(table->entries[i].name, fzgx_pool_init_lbl_1_data_3EEA4.v[i], 16);
        }
        sec0++;
        if (sec0 >= 60) {
            min0++;
            sec0 -= 60;
        }
        sec1++;
        if (sec1 >= 60) {
            min1++;
            sec1 -= 60;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FA1D8 */

/* fzgx:begin fn_1_FA450 */
// Store the value when initialization permits the update.
void fn_1_FA450(u8 value) {
    u8 local[0x14c0];

    if (*(s16 *)&lbl_1_bss_960 == 2) {
        fn_1_3EF14(local);
        if ((*(u32 *)local & 0x800) == 0) {
            *(u8 *)(*(u32 *)&lbl_1_bss_84420 + 8) = value;
        }
    } else {
        *(u8 *)(*(u32 *)&lbl_1_bss_84420 + 8) = value;
    }
}
/* fzgx:end fn_1_FA450 */

/* fzgx:begin fn_1_FA4C0 */
// Return the byte at offset 0x8 from the spline object referenced by the global.
u8 fn_1_FA4C0(void) {
    return *(u8 *)(lbl_1_bss_84420 + 0x8);
}
/* fzgx:end fn_1_FA4C0 */

/* fzgx:begin fn_1_FA4D4 */
/* View of the object lbl_1_bss_84420 points to (the header types the pointer as u32). */
struct SplineWork {
    u8 pad_0[0xa];
    s16 unk_a[41];
};

void fn_1_FA4D4(void) {
    s16 i;
    struct SplineWork *work;

    for (i = 0; i < 41; i++) {
        work = (struct SplineWork *)lbl_1_bss_84420;
        work->unk_a[i] = 0;
    }
}
/* fzgx:end fn_1_FA4D4 */

/* fzgx:begin fn_1_FA5A8 */
extern u32 lbl_1_bss_84420;

void fn_1_FA5A8(s16 index, u8 bit) {
    u32 base;
    u16 value;

    if (index >= 0x29) {
        return;
    }

    base = lbl_1_bss_84420;
    base += index << 1;
    value = *(u16 *)((u8 *)base + 0xa);
    *(u16 *)((u8 *)base + 0xa) = value | (1 << bit);
}
/* fzgx:end fn_1_FA5A8 */

/* fzgx:begin fn_1_FA5E0 */
extern u32 lbl_1_bss_84420;

u32 fn_1_FA5E0(u32 arg0, u32 arg1) {
    s16 v0;
    u32 v1;
    u32 v2;
    v0 = (s16)arg0;
    v1 = arg0;
    if (v0 >= 41) {
    v1 = 0;
    return v1;
    }
    v1 = 1;
    v2 = (v1 << (arg1 & 0xFF));
    v1 = (lbl_1_bss_84420 + (v0 << 1));
    v1 = *(u16 *)((u8 *)v1 + 10);
    v1 = (v1 & v2);
    return v1;
}
/* fzgx:end fn_1_FA5E0 */

/* fzgx:begin fn_1_FA61C */
// Clears the low flag bit in the spline state.
void fn_1_FA61C(void) {
    ((u8 *)lbl_1_bss_84420)[0x85] &= 0xfe;
}
/* fzgx:end fn_1_FA61C */

/* fzgx:begin fn_1_FA638 */
// Returns whether the spline state flag is enabled.
u8 fn_1_FA638(void) {
    return ((u8*)lbl_1_bss_84420)[0x85] & 1;
}
/* fzgx:end fn_1_FA638 */

/* fzgx:begin fn_1_FA650 */
// Toggle the enabled bit in the spline state.
void fn_1_FA650(void) {
    u8* state = (u8*)lbl_1_bss_84420;

    if (state[0x85] & 1) {
        state[0x85] &= 0xfe;
    } else {
        state[0x85] |= 1;
    }
}
/* fzgx:end fn_1_FA650 */

/* fzgx:begin fn_1_FA67C */
extern u32 lbl_1_bss_84420;

void fn_1_FA67C(s32 index) {
    u8 *base;

    if (index >= 0x29) {
        return;
    }
    base = (u8 *)lbl_1_bss_84420;
    base[index + 0x5c] = 1;
}
/* fzgx:end fn_1_FA67C */

/* fzgx:begin fn_1_FA69C */
// Return the spline entry value for an in-range index.
u8 fn_1_FA69C(s32 index) {
    u8 *base;

    if (index >= 0x29) {
        return 0;
    }
    base = (u8 *)lbl_1_bss_84420;
    return base[index + 0x5c];
}
/* fzgx:end fn_1_FA69C */

/* fzgx:begin fn_1_FA6C0 noprologue */
#include "types.h"

struct fn_1_FA6C0_lbl_1_rodata_7480 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_1_FA6C0_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

extern struct fn_1_FA6C0_lbl_1_data_2A7E0 lbl_1_data_2A7E0;
extern struct fn_1_FA6C0_lbl_1_rodata_7480 lbl_1_rodata_7480;
extern u32 fn_1_76504(s32, void *, s32);
extern u32 lbl_801A63D0;
extern void fn_1_7269C(u32, u32, void *);
extern void fn_1_72768(u32, u32);
extern void fn_1_FAB40(void);

void fn_1_FA6C0(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    struct { u32 a[4]; } loc_8;
    /* frame */
    u32 t0;
    v0 = lbl_1_rodata_7480.unk_0;
    v1 = lbl_1_rodata_7480.unk_4;
    v2 = lbl_1_rodata_7480.unk_8;
    loc_8.a[0] = v0;
    loc_8.a[1] = v1;
    loc_8.a[2] = v2;
    v3 = lbl_1_data_2A7E0.unk_3C;
    loc_8.a[3] = lbl_1_rodata_7480.unk_C;
    t0 = fn_1_76504(35, (void *)&loc_8, 0);
    *(u32 *)((u8 *)v3 + 364) = (t0 & 0xFF);
    fn_1_7269C((*(u32 *)((u8 *)v3 + 364) & 0xFF), 0, (void *)lbl_801A63D0);
    fn_1_72768((*(u32 *)((u8 *)v3 + 364) & 0xFF), (u32)fn_1_FAB40);
}
/* fzgx:end fn_1_FA6C0 */

/* fzgx:begin fn_1_FA75C */
extern s32 fn_1_58C4(void);
extern void fn_80008BEC(void *dst, s32 value, u32 size);
extern void fn_1_FA89C(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_FB0B4(Obj_1_bss_84428 *data);
extern void fn_1_FB180(int *value);

// Reset spline state while preserving the active spline entry.
void fn_1_FA75C(void) {
    s32 spline_index;
    Obj_1_data_2A7E0_At3C *obj;
    u8 *status;
    u32 saved_entry;

    spline_index = fn_1_58C4();
    obj = lbl_1_data_2A7E0.unk_3C;
    status = (u8 *)&obj->unk_4;
    saved_entry = obj->unk_170;
    fn_80008BEC(obj, 0, 0x174);
    obj->unk_170 = saved_entry;

    if (obj->unk_170 != 0 && spline_index <= 1) {
        fn_1_FA89C(obj);
    } else {
        fn_1_76BF8();
        fn_1_72648();
        *status = 0;
    }

    obj->unk_0 = -1;
    {
        extern void fn_1_9A508(void);
        fn_1_9A508();
    }
    fn_1_FB0B4(&lbl_1_bss_84428);
    fn_1_FB180((int *)&lbl_1_bss_84428);

    if (*status == 0) {
        fn_1_76BF8();
        fn_1_72648();
        *status = 0;
    }
}
/* fzgx:end fn_1_FA75C */

/* fzgx:begin fn_1_FA82C */
// fn_1_FA82C: empty in retail (single blr).
void fn_1_FA82C(void) {
}
/* fzgx:end fn_1_FA82C */

/* fzgx:begin fn_1_FA830 */
void fn_1_FA830(void) {
    fn_1_9AD54();
    fn_1_FB18C();
}
/* fzgx:end fn_1_FA830 */

/* fzgx:begin fn_1_FA854 */
void fn_1_FA854(void) {
    fn_1_76BF8();
    fn_1_72648();
}
/* fzgx:end fn_1_FA854 */

/* fzgx:begin fn_1_FA878 */
void fn_1_FA878(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_FA878 */

/* fzgx:begin fn_1_FA898 */
// fn_1_FA898: empty in retail (single blr).
void fn_1_FA898(void) {
}
/* fzgx:end fn_1_FA898 */

/* fzgx:begin fn_1_FA89C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern const f32 lbl_1_rodata_7490[];
extern const f32 lbl_1_rodata_7494;
extern const f64 lbl_1_rodata_7498;
extern const f64 lbl_1_rodata_74A0;
extern u32 __cvt_fp2unsigned(f64);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern int fn_1_58C4(void);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern void fn_80015CB0(f32 *, f32, f32, f32, f32, f32, f32);
extern void fn_80038FD8(u32 *, u32 *, u32 *, u32 *);

typedef struct SplineEntry {
    u8 pad0[0x104];
    u32 f104;
    u8 pad1[0xC];
    u32 f114;
    u8 pad2[0xC];
    u32 f124;
    u8 pad3[0xC];
    u32 f134;
    u8 pad4[0xC];
    u32 f144;
    u8 pad5[0xC];
    u32 f154;
    u8 pad6[0xC];
    f32 f164;
} SplineEntry;

typedef struct SplineMain {
    u8 pad0[4];
    u8 unk_4;
    u8 pad5[0x163];
    f32 unk_168;
} SplineMain;

#pragma opt_common_subs off
void fn_1_FA89C(SplineMain *arg0) {
    SplineEntry *v4;
    u8 *v3;
    f32 v1;
    u32 v7;
    u32 v5;
    u32 v8;
    f32 fzgx_live;
    u32 v6;
    s32 v2;
    SplineEntry *v0;
    s16 v9;
    s16 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    int t0;
    u32 t3;
    u32 t4;

    t0 = fn_1_58C4();
    v0 = (SplineEntry *)((u8 *)arg0 + 4);
    v1 = lbl_1_rodata_7490[0];
    arg0->unk_4 = 0;
    arg0->unk_168 = v1;
    v2 = 0;
    v4 = v0;
    v3 = (u8 *)v0;
    while (v2 < t0) {
        fn_1_5948(v2);
        fn_80038FD8(&v4->f104, &v4->f114, &v4->f124, &v4->f134);
        t3 = (u32)((f32)v4->f124 / v0->f164);
        v4->f144 = t3;
        t4 = (u32)((f32)v4->f134 / v0->f164);
        v4->f154 = t4;
        v5 = v4->f124;
        v6 = v4->f134;
        v7 = v4->f104;
        v8 = v4->f114;
        v9 = (s16)(v7 + (v5 >> 1));
        v10 = (s16)(v8 + (v6 >> 1));
        v11 = (f32)((f32)(s16)v7 / (f32)(s16)v9);
        v12 = (f32)(s16)v8;
        v13 = (f32)(v11 - v1);
        v14 = (f32)((f32)(v12 / (f32)(s16)v10) - v1);
        fn_1_A714C(&sp14, &sp10, &spC, &sp8);
        v15 = (f32)((f32)((f32)((f32)(s16)(v8 + v6) / (f32)(s16)v10) - v1) - v14);
        v16 = (f32)((f32)((f32)((f32)(s16)(v7 + v5) / (f32)(s16)v9) - v1) - v13);
        fn_80015CB0((f32 *)(((0x44) + (v3))), sp14, sp10, (f32)(v1 / v16), (f32)(lbl_1_rodata_7494 / v15), (f32)((-v13) / v16), (f32)((-v14) / v15));
        fn_1_627C(v2);
        v4 = (SplineEntry *)((u8 *)v4 + 4);
        v3 += 0x30;
        v2++;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FA89C */

/* fzgx:begin fn_1_FB0A8 */
Obj_1_bss_84428 *fn_1_FB0A8(void) {
    return &lbl_1_bss_84428;
}
/* fzgx:end fn_1_FB0A8 */

/* fzgx:begin fn_1_FB0B4 */
extern u32 lbl_1_rodata_74CC[3];
extern u32 lbl_1_rodata_74D8[46];
extern void fn_80008BA8(void *dst, const void *src, u32 size);

void fn_1_FB0B4(Obj_1_bss_84428 *data) {
    u32 first[3];
    u32 second[3];

    first[0] = lbl_1_rodata_74CC[0];
    first[1] = lbl_1_rodata_74CC[1];
    first[2] = lbl_1_rodata_74CC[2];

    second[0] = lbl_1_rodata_74D8[0];
    second[1] = lbl_1_rodata_74D8[1];
    second[2] = lbl_1_rodata_74D8[2];

    data->unk_0 = 0;
    data->unk_4 = -1;
    lbl_1_bss_84428.unk_6 = 3;
    lbl_1_bss_84428.unk_8 = 20;
    lbl_1_bss_84428.unk_A = 0;
    lbl_1_bss_84428.unk_C = 30;

    fn_80008BA8((u8 *)&lbl_1_bss_84428 + 0x10, first, 0xc);
    fn_80008BA8((u8 *)&lbl_1_bss_84428 + 0x1c, second, 0xc);
}
/* fzgx:end fn_1_FB0B4 */

/* fzgx:begin fn_1_FB180 */
// Set the destination value to one.
void fn_1_FB180(int *value) {
    *value = 1;
}
/* fzgx:end fn_1_FB180 */

/* fzgx:begin fn_1_FB770 */
int fn_1_FB770(int flag, u32 *value) {
    Obj_1_data_2A7E0_At3C *object = lbl_1_data_2A7E0.unk_3C;

    switch (flag) {
    case 0:
        object->unk_170 = *value;
        break;
    default:
        break;
    }

    return 1;
    return 1;
}
/* fzgx:end fn_1_FB770 */
