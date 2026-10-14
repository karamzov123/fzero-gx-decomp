/* Non-matching: best partial attempt (95.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 flag;
    u8 kind;
    u8 count;
    u8 pad3;
    u16 idx[6];
    V3 pos;
    V3 v1c;
    V3 v28;
    V3 v34;
    f32 f40;
} P;
typedef struct {
    V3 pos;
    u8 pad[0x29];
    u8 tag;
    u8 pad2[0xa];
} Src;
typedef struct {
    P *a;
    P *b;
    f32 c, d, e, f;
} Ent;
struct B {
    u8 pad[0x18];
    P *arr;
    u32 n;
    Ent *ent;
    u32 c24;
    u32 c28;
    u32 c2c;
};
struct Pool {
    u8 pad_0[0x38];
    V3 v38;
    f64 eps;
    f32 m1;
    f32 zero;
    f32 f1695;
    u8 pad_5C[4];
    f64 p195;
    f64 n195;
    f32 f15;
    u8 pad_74[4];
    f64 h5;
    f64 h6;
    f64 e4;
    f32 one;
    f32 f11;
    f32 f095;
};
struct H { u32 unk_0; };

extern struct B lbl_1_bss_85250;
extern struct Pool lbl_1_rodata_77F8;
extern struct H lbl_801A6410;
extern u32 lbl_1_data_3F17C;
extern f64 __fabs(f64);
extern void fn_1_46B4(u32, void *, void *, int);
extern void *fn_1_4630(u32, u32, void *, int);
extern u32 *fn_80077B64(void *);
extern Src *fn_80077B14(void *);
extern void fn_80008BEC(void *, int, int);
extern void fn_1_10240C(void *, void *, int);
extern f32 fn_1_1024C4(P *, P *);

void fn_1_101BC4(void *arg0) {
    struct Pool *pool = &lbl_1_rodata_77F8;
    struct B *bss = &lbl_1_bss_85250;
    u32 *cnt;
    u32 i, j, k;
    Src *src;
    f32 y1;
    s32 found;
    P *arr;
    P *p;
    P *q;
    P *a;
    P *b;
    f64 eps;

    if (arg0 == 0) {
        return;
    }
    if (bss->arr != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, bss->arr, &lbl_1_data_3F17C, 0x119);
        bss->arr = 0;
    }
    if (bss->ent != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, bss->ent, &lbl_1_data_3F17C, 0x11a);
        bss->ent = 0;
    }
    cnt = fn_80077B64(arg0);
    src = fn_80077B14(arg0);
    bss->arr = fn_1_4630(lbl_801A6410.unk_0, *cnt * 0x44, &lbl_1_data_3F17C, 0x11f);
    eps = pool->eps;
    bss->n = 0;
    for (i = 0; i < *cnt; i++, src++) {
        arr = bss->arr;
        found = -1;
        for (p = arr, j = 0; j < bss->n; j++, p++) {
            f32 dx = p->pos.x - src->pos.x;
            f32 dy = p->pos.y - src->pos.y;
            f32 dz = p->pos.z - src->pos.z;
            if ((f32)(dx * dx) + dy * dy + dz * dz < eps) {
                found = j;
                break;
            }
        }
        if ((u32)(found + 0x10000) != 0xffff) {
            arr[found].idx[arr[found].count] = i;
            bss->arr[found].count++;
        } else {
            q = &arr[bss->n];
            q->v28 = src->pos;
            q->v1c = q->v28;
            q->pos = q->v1c;
            q->v34 = pool->v38;
            q->flag = src->tag;
            q->count = 1;
            fn_80008BEC(q->idx, 0xff, 10);
            q->idx[0] = i;
            q->f40 = pool->m1;
            bss->n++;
        }
    }
    a = bss->arr;
    for (i = 0; i < bss->n; i++, a++) {
        if (a->flag & 1) {
            a->flag = 1;
            a->kind = 0;
            a->f40 = pool->zero;
        } else if (a->pos.x > pool->f1695) {
            a->kind = 1;
            if (a->pos.z > pool->p195 || a->pos.z < pool->n195) {
                a->flag = 1;
                a->f40 = pool->zero;
            }
            if (a->pos.y > pool->f15) {
                f32 z = __fabs(a->pos.z);
                if (z > pool->h5 && z < pool->h6) {
                    a->flag = 1;
                    a->f40 = pool->zero;
                }
            }
        } else if (a->pos.y > pool->f15) {
            a->kind = 2;
        } else if (a->pos.z > pool->zero) {
            a->kind = 3;
        } else {
            a->kind = 4;
        }
    }
    a = bss->arr;
    for (i = 0; i < bss->n; i++, a++) {
        b = bss->arr + i + 1;
        for (j = i + 1; j < bss->n; j++, b++) {
            if (a->kind > b->kind) {
                fn_1_10240C( b,a, 0x44);
            }
        }
    }
    a = bss->arr;
    for (i = 0; i < bss->n; i++, a++) {
        b = bss->arr + i + 1;
        for (j = i + 1; j < bss->n; j++, b++) {
            if (a->kind == b->kind && a->pos.y > b->pos.y) {
                fn_1_10240C(a, b, 0x44);
            }
        }
    }
    a = bss->arr;
    eps = pool->e4;
    for (i = 0; i < bss->n; i++, a++) {
        b = bss->arr + i + 1;
        for (j = i + 1; j < bss->n; j++, b++) {
            if (a->kind == b->kind && __fabs(a->pos.y - b->pos.y) < eps && a->pos.z > b->pos.z) {
                fn_1_10240C(a, b, 0x44);
            }
        }
    }
    a = bss->arr;
    for (i = 0; i < bss->n; i++, a++) {
        b = bss->arr + i + 1;
        for (j = i + 1; j < bss->n; j++, b++) {
            if (a->kind == b->kind && __fabs(a->pos.y - b->pos.y) < pool->e4
                && __fabs(a->pos.z - b->pos.z) < pool->e4 && a->pos.x > b->pos.x) {
                fn_1_10240C(a, b, 0x44);
            }
        }
    }
    bss->c28 = 0;
    bss->c2c = 0;
    a = bss->arr;
    for (i = 0; i < bss->n - 1; i++, a++) {
        if (a[0].kind == 1 && a[1].kind == 1) {
            f32 y0 = a[0].pos.y;
            y1 = a[1].pos.y;
            if (__fabs(y0 - y1) < pool->e4) {
                if (__fabs(y0) < pool->e4 && __fabs(y1) < pool->e4) {
                    bss->c28++;
                }
                bss->c2c++;
            }
        }
    }
    bss->c2c = bss->c2c / bss->c28 - 1;
    bss->c24 = bss->c28 * (bss->c2c + 1) + bss->c2c * (bss->c28 + 1);
    bss->ent = fn_1_4630(lbl_801A6410.unk_0, bss->c24 * 0x18, &lbl_1_data_3F17C, 0x1b1);
    k = 0;
    a = bss->arr;
    for (i = 0; i < bss->n - 1; i++, a++) {
        if (a[0].kind == 1 && a[1].kind == 1 && __fabs(a[0].pos.y - a[1].pos.y) < pool->e4) {
            bss->ent[k].a = a;
            bss->ent[k].b = a + 1;
            bss->ent[k].c = fn_1_1024C4(a, a + 1);
            bss->ent[k].d = (*(f32 volatile *)&(pool->one)) /* Retail reloads this field. */;
            bss->ent[k].e = pool->f11;
            bss->ent[k].f = pool->f095;
            k++;
        }
    }
    a = bss->arr;
    eps = pool->e4;
    for (i = 0; i < bss->n; i++, a++) {
        for (j = i + 1, b = bss->arr + i + 1; j < bss->n; j++, b++) {
            if (a->kind == 1 && b->kind == 1 && __fabs(a->pos.z - b->pos.z) < eps) {
                bss->ent[k].a = a;
                bss->ent[k].b = b;
                bss->ent[k].c = fn_1_1024C4(a, b);
                bss->ent[k].d = pool->one;
                bss->ent[k].e = pool->f11;
                bss->ent[k].f = pool->f095;
                k++;
                break;
            }
        }
    }
}
