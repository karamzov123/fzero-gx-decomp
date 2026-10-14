/* Non-matching: best partial attempt (97.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3f;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} W3;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0xE];
    V3f v;
    W3 w1;
    W3 w2;
    u8 pad_34[0xC];
    f32 unk_40;
} Elem;

typedef struct {
    u32 a;
    u32 b;
    f32 d;
} Link;

typedef struct {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u32 pad_20;
    Elem *unk_24;
    Link *unk_28;
} Ctx;

typedef struct {
    u8 pad_0[0x64];
    f32 m1;
    f32 zero;
    u8 pad_6C[0xFC];
    f64 d015;
    f32 m05;
    u8 pad_174[4];
    f64 d045;
} Pool;

extern const Pool lbl_1_rodata_7AB8;
extern u32 lbl_801A6410;
extern u32 fn_1_10846C(Ctx *);
extern void fn_1_128884(Elem *, Elem *, int);
extern u32 fn_1_4630(u32, u32);
extern f32 fn_1_1289BC(const Elem *, const Elem *);

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
static inline Elem * fn_1_10D2F0_read_pointer(Ctx * owner) { return owner->unk_24; }
#pragma opt_lifetimes reset

u32 fn_1_10D2F0(Ctx *arg0) {
    u8 fzgx_value_;
    u8 fzgx_value;
    Elem * fzgx_live;
    const Pool *pool = &lbl_1_rodata_7AB8;
    Elem *a;
    Elem *b;
    Elem *p;
    Elem *last;
    Elem *e;
    Elem *c;
    u32 i;
    u32 j;
    u32 k;
    u32 pairs;
    u32 q;
    s32 tmp_ra5;
    Ctx * lab_t0;

    if (arg0 != 0) {
        return (u32)i;
    }
    lab_t0 = arg0;
    fn_1_10846C(lab_t0);

    p = arg0->unk_24;
    for (i = 0; i < arg0->unk_18; i++, p++) {
        if (p->unk_0 & 1) {
            p->unk_0 = 0;
            if (p->v.x > pool->d015) {
                p->unk_40 = pool->m05;
                fzgx_value_ = 1;
                p->unk_1 = fzgx_value_;
            } else {
                p->unk_40 = pool->m1;
                p->unk_1 = 2;
            }
        } else {
            p->unk_40 = pool->zero;
            p->unk_0 = 1;
            if (p->v.x > pool->d045) {
                p->unk_1 = 0;
            } else {
                p->unk_1 = 3;
            }
        }
    }

    for (p = arg0->unk_24, i = 0; i < arg0->unk_18; i++, p++) {
        {
    Elem * fzgx_loop_e_1764;
for (fzgx_loop_e_1764 = &arg0->unk_24[i] + 1, j = i + 1; j < arg0->unk_18; j++, fzgx_loop_e_1764++) {
            if (p->unk_1 > fzgx_loop_e_1764->unk_1) {
                fn_1_128884(p, fzgx_loop_e_1764, 0x44);
            }
        }
    e = fzgx_loop_e_1764;
}
    }

    for (p = arg0->unk_24, i = 0; i < arg0->unk_18; i++, p++) {
        for (e = &arg0->unk_24[i] + 1, j = i + 1; j < arg0->unk_18; j++, e++) {
            if (p->unk_1 == e->unk_1 && p->v.z < e->v.z) {
                fn_1_128884(p, e, 0x44);
            }
        }
    }

    for (p = arg0->unk_24, i = 0; i < arg0->unk_18; i++, p++) {
        for (e = &arg0->unk_24[i] + 1, j = i + 1; j < arg0->unk_18; j++, e++) {
            if (p->unk_1 == e->unk_1) {
                if (p->v.z > pool->zero) {
                    if (e->v.z > pool->zero) {
                        if (p->v.y > e->v.y) {
                            fn_1_128884(p, e, 0x44);
                        }
                    }
                } else if (p->v.z < (*(f32 volatile *)&(pool->zero)) /* Retail reloads this field. */) {
                    if (e->v.z < pool->zero) {
                        if (p->v.y < e->v.y) {
                            fn_1_128884(p, e, 0x44);
                        }
                    }
                }
            }
        }
    }

    a = fn_1_10D2F0_read_pointer(arg0);
    for (k = 0; k < arg0->unk_18; k++) {
        tmp_ra5 = a->unk_1;
        if (tmp_ra5 == 1) {
            break;
        }
        a++;
    }
    fzgx_live = arg0->unk_24;
    b = fzgx_live;
    for (k = 0; k < arg0->unk_18; k++) {
        if (b->unk_1 == 3) {
            break;
        }
        b++;
    }
    a->unk_40 = b->unk_40;
    fzgx_value = b->unk_0;
    a->unk_0 = fzgx_value;
    a->w2 = b->w2;
    a->v = b->v;
    a->w1 = b->w1;

    c = arg0->unk_24;
    for (k = 0; k < arg0->unk_18; k++) {
        if (c->unk_1 == 2) {
            break;
        }
        c = c + 1;
    }
    last = &arg0->unk_24[arg0->unk_18 - 1];
    c--;
    c->unk_40 = last->unk_40;
    c->unk_0 = last->unk_0;
    c->w2 = last->w2;
    c->v = last->v;
    c->w1 = last->w1;

    q = arg0->unk_18 >> 2;
    arg0->unk_1C = q * 3 + (q - 1) * 4;
    arg0->unk_28 = (Link *)fn_1_4630(lbl_801A6410, arg0->unk_1C * 12);

    pairs = 0;
    for (p = arg0->unk_24, i = 0; i < arg0->unk_18 - 1; i++, p++) {
        if (p->unk_1 == (*((p) + (1))).unk_1) {
            (*((arg0->unk_28) + (pairs))).a = (u32)p;
            (*((arg0->unk_28) + (pairs))).b = (u32)(p + 1);
            (*((arg0->unk_28) + (pairs))).d = fn_1_1289BC(p, p + 1);
            pairs++;
        }
    }
    for (p = arg0->unk_24, i = 0; i < arg0->unk_18 - q; i++, p++) {
        (*((arg0->unk_28) + (pairs))).a = (u32)p;
        (*((arg0->unk_28) + (pairs))).b = (u32)(p + q);
        (*((arg0->unk_28) + (pairs))).d = fn_1_1289BC(p, p + q);
        pairs++;
    }
    return (u32)i;
}
#pragma opt_dead_assignments reset

