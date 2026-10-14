/* Non-matching: best partial attempt (90.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_22B10_Arg0 {
    u8 pad_0[0x4];
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    u8 pad_24[0x10];
    f32 f34;
    f32 f38;
    f32 f3C;
};

extern f32 lbl_1_rodata_840[3];
extern f64 __fabs(f64);

#define K(n) (k[(n)])
#define DD(n) (((f32 *)k)[(n)])

static inline f64 fn_1_22B10_step(f64 base, f64 k, f32 x) {
    f64 p = k * __fabs((f64)x);
    return base + p;
}

static inline f64 fn_1_22B10_step2(f64 base, f64 k, f64 s, f32 x) {
    f64 p = s * __fabs((f64)x);
    f64 q = k * p;
    return base + q;
}

#pragma opt_common_subs off
#pragma opt_dead_assignments on
#pragma opt_lifetimes on
#pragma opt_strength_reduction on

#pragma opt_propagation off
static inline f32 fn_1_22B10_operand(f32 right, f32 left) { left *= right; return left; }
#pragma opt_propagation reset

static inline f32 fn_1_22B10_operand_(f32 left, f32 right) { return left * right; }
static inline f32 fn_1_22B10_operand__(f32 left, f32 right) { return left * right; }
static inline f32 fn_1_22B10_operand___(f32 right, f32 left) { left *= right; return left; }
static inline f32 fn_1_22B10_operand____(f32 left, f32 right) { return left * right; }
static inline f32 fn_1_22B10_read_pointer(struct fn_1_22B10_Arg0 * owner) { return owner->f10; }
f32 fn_1_22B10(struct fn_1_22B10_Arg0 *s, f32 arg1) {
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
    f32 *k = lbl_1_rodata_840;
    f32 a;
    f32 b;
    f32 d = arg1 - K(7);
    f32 acc;
    f32 t;
    f32 u;
    s32 flag = 1;

    if (d > K(3)) {
        a = K(5);
        b = K(3);
        if (s->f1C > K(5)) {
            t = fn_1_22B10_operand_((s->f1C), (d));
            t = K(31) * t;
            s->f1C = s->f1C - t;
        }
    } else {
        f32 v = s->f1C;
        a = K(3);
        b = K(32);
        if (v < K(5)) {
            t = fn_1_22B10_operand__((K(30) - v), (d));
            t = K(30) * t;
            s->f1C = v - t;
        } else if (v < K(33)) {
            t = fn_1_22B10_operand__((v), (d));
            t = K(34) * t;
            s->f1C = v - t;
        } else {
            t = fn_1_22B10_operand___((d), (v));
            t = fn_1_22B10_operand__((K(34) - (v - K(33))), (t));
            s->f1C = v - t;
        }
        if (s->f1C > K(35))
            s->f1C = K(35);
    }

    if (d < K(3) && s->f8 >= K(7) && s->fC <= K(26))
        flag = 0;

    acc = (f32)((f64)d * __fabs((f64)(a - s->fC)));

    if (d > K(3)) {
        u = K(5);
        if (s->f8 < K(36))
            u = K(37);
        else if (s->f8 >= K(7)) {
            if (s->fC < K(38))
                u = K(3);
            else
                u = K(39);
        }
        acc = acc * (K(40) * u);
    } else {
        fzgx_live__ = s->fC;
        u = (fzgx_live__ - K(41)) / K(42);
        if (u > K(5))
            u = K(5);
        t = K(26) * u;
        t = K(36) + t;
        acc = acc * (K(43) * t);
    }

    if (s->f8 > K(14) && d < K(3)) {
        u = K(44) - s->f8;
        t = K(30) * d;
        s->f8 = (f32)fn_1_22B10_step((f64)s->f8, (f64)t, u);
    } else {
        u = b - s->f8;
        fzgx_live = s->f8;
        s->f8 = (f32)fn_1_22B10_step2((f64)fzgx_live, DD(23), (f64)(-d), u);
    }

    if (s->f8 < K(36)) {
        u = K(5);
        if (s->f8 < K(48)) {
            u = K(33);
            acc = acc * K(33);
        }
        if (s->f3C > K(49))
            u = u * K(33);
        if (d < K(3))
            u = u * K(30);
        t = fn_1_22B10_operand((d), (s->f3C));
        t = fn_1_22B10_operand____((u), (t));
        t = K(44) * t;
        fzgx_live_ = s->f3C;
        s->f3C = (f32)((f64)fzgx_live_ - __fabs((f64)t));
        if (s->f3C < K(50))
            s->f3C = K(50);
    }

    if (s->f4 < K(51) && s->f8 > K(44))
        s->f8 = K(44);

    s->fC = s->fC + acc;

    if (d > K(3)) {
        t = K(14) * d;
        s->f20 = s->f20 * (K(5) - t);
    } else {
        t = K(26) * d;
        s->f20 = s->f20 * (K(5) - t);
    }

    t = K(24) * d;
    t = K(5) + t;
    s->f10 = fn_1_22B10_read_pointer(s) * t;
    s->f14 = s->f14 * t;

    if (flag == 0)
        return K(6);

    t = K(6) * d;
    t = K(5) + t;
    return (s->f34 = (t) * (s->f34));
}
#pragma peephole reset


#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
