/* Non-matching: best partial attempt (79.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    u8 active;
    u8 pad_1;
    u8 contact_count;
    u8 pad_3;
    u16 contacts[6];
    f32 pos_x, pos_y, pos_z;
    f32 tgt_x, tgt_y, tgt_z;
    f32 basis_x, basis_y, basis_z;
    f32 vel_x, vel_y, vel_z;
    f32 radius;
} Entry;

typedef struct {
    Entry *a;
    Entry *b;
    f32 rest;
} Constraint;

typedef struct {
    u8 pad_0[0x8];
    u32 stage;
    void *sys;
    void *phys;
    u8 pad_14[0x4];
    u32 entry_count;
    u32 constraint_count;
    u8 pad_20[0x4];
    Entry *entries;
    Constraint *constraints;
} World;

typedef struct {
    f32 x, y, z;
} Vec;

typedef struct {
    Vec v;
    Vec t;
} Pair;

extern f32 lbl_1_rodata_7AB8[];
extern u32 lbl_801A66A0;
extern u32 lbl_1_data_3FFBC[];

extern void fn_80077B14(void *);
extern void fn_1_1286F4(Vec *);
extern void fn_8006E250(void *, void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(f32 *, f32 *);
extern f32 lbl_8006D118(f32);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D668(Vec *);

void fn_1_11F250(World *self) {
    f32 *c = lbl_1_rodata_7AB8;
    f32 zero, k66, k10, k20, kneg, kpos;
    Entry *e;
    Constraint *k;
    u32 i, j, pass, n;
    f32 dx, dy, dz, dist2;
    f32 dist, other, delta;
    f32 nx, ny, nz, w1, w2, s;
    f32 t1, t2;
    Vec grav, near, diff;
    Pair p0, p1, p2, p3, p4, p5, p6, p7;
    f64 K1, K2, K3;
    u8 *base;

    if (self == 0) return;

    if (self->phys != 0) {
        fn_80077B14(self->phys);

        if ((*(u8 *)self & 2) != 0) {
            *(u8 *)self = (u8)(*(u8 *)self & 0xFFFFFFFD);
            n = lbl_1_data_3FFBC[self->stage];
            base = (u8 *)*(void **)((u8 *)self + 0xc);
            base = *(u8 **)(base + 0x150);
            base = *(u8 **)(base + 8);
            base += n * 0x18c + 0x88;
            lbl_8006DBAC(base);
            lbl_8006DAEC();
            e = self->entries;
            for (i = 0; i < self->entry_count; i++) {
                lbl_8006DBE4();
                lbl_8006E1B0(&e->basis_x, &e->pos_x);
                e++;
            }
            lbl_8006DC20();
        }

        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                *(u32 *)&e->tgt_x = *(u32 *)&e->pos_x;
                *(u32 *)&e->tgt_y = *(u32 *)&e->pos_y;
                *(u32 *)&e->tgt_z = *(u32 *)&e->pos_z;
                e->pos_x += e->vel_x;
                e->pos_y += e->vel_y;
                e->pos_z += e->vel_z;
                e->pos_y = (f32)((f64)e->pos_y - 0.0013611111376020642);
                e->vel_y = e->vel_y - c[24];
            }
            e++;
        }
    }

    n = lbl_1_data_3FFBC[self->stage];
    base = (u8 *)*(void **)((u8 *)self + 0xc);
    base = *(u8 **)(base + 0x150);
    base = *(u8 **)(base + 8);
    base += n * 0x18c;
    e = self->entries;
    for (i = 0; i < self->entry_count; i++) {
        lbl_8006DBAC(base + 0x88);
        lbl_8006DAEC();
        if ((e->active & 1) != 0) {
            lbl_8006DBE4();
            lbl_8006E1B0(&e->basis_x, &e->pos_x);
        }
        lbl_8006DC20();
        e++;
    }

    zero = c[26];
    k66 = c[181];
    k10 = c[142];
    k20 = c[114];
    kneg = c[299];
    kpos = c[300];

    for (pass = 0; pass < 4; pass++) {
        k = self->constraints;
        for (i = 0; i < self->constraint_count; i++) {
            Entry *a = k->a;
            Entry *b = k->b;
            if (a != 0 && b != 0) {
                dx = a->pos_x - b->pos_x;
                dy = a->pos_y - b->pos_y;
                dz = a->pos_z - b->pos_z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 - c[39] > k->rest) {
                    dist = lbl_8006D118(dist2);
                    other = lbl_8006D0B4(k->rest);
                    delta = (dist2 - other) * dist;
                    nx = dx * delta;
                    ny = dy * delta;
                    nz = dz * delta;
                    w1 = a->radius;
                    w2 = b->radius;
                    s = c[40] / (w1 + w2);
                    w1 *= s;
                    w2 *= s;
                    a->pos_x -= nx * w1;
                    a->pos_y -= ny * w1;
                    a->pos_z -= nz * w1;
                    b->pos_x += nx * w2;
                    b->pos_y += ny * w2;
                    b->pos_z += nz * w2;
                }
                if (dist2 + c[105] < k->rest && i < 20) {
                    dist = lbl_8006D118(dist2);
                    other = lbl_8006D0B4(k->rest);
                    delta = (dist2 - other) * dist;
                    nx = dx * delta;
                    ny = dy * delta;
                    nz = dz * delta;
                    w1 = a->radius;
                    w2 = b->radius;
                    s = c[40] / (w1 + w2);
                    w1 *= s;
                    w2 *= s;
                    a->pos_x -= nx * w1;
                    a->pos_y -= ny * w1;
                    a->pos_z -= nz * w1;
                    b->pos_x += nx * w2;
                    b->pos_y += ny * w2;
                    b->pos_z += nz * w2;
                }
                t1 = a->pos_y;
                t2 = b->pos_y;
                if (t1 < zero || t2 < zero) {
                    if (t1 < zero) {
                        a->pos_y = c[146];
                    }
                    if (b->pos_y < zero) {
                        b->pos_y = c[146];
                    }
                    dx = a->pos_x - b->pos_x;
                    dy = a->pos_y - b->pos_y;
                    dz = a->pos_z - b->pos_z;
                    dist2 = dx * dx + dy * dy + dz * dz;
                    dist = lbl_8006D118(dist2);
                    other = lbl_8006D0B4(k->rest);
                    delta = (dist2 - other) * dist;
                    nx = dx * delta;
                    ny = dy * delta;
                    nz = dz * delta;
                    w1 = a->radius;
                    w2 = b->radius;
                    s = c[40] / (w1 + w2);
                    w1 *= s;
                    w2 *= s;
                    a->pos_x -= nx * w1;
                    a->pos_y -= ny * w1;
                    a->pos_z -= nz * w1;
                    b->pos_x += nx * w2;
                    b->pos_y += ny * w2;
                    b->pos_z += nz * w2;
                }
            }
            k++;
        }

        p0.v.x = k66;
        p0.v.y = zero;
        p0.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0x214);
        lbl_8006E1B0(&p0.v.x, &p0.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p0.v.x;
                dy = e->pos_y - p0.v.y;
                dz = e->pos_z - p0.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[296]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p0.v, c[266] * s, &p0.t, &e->pos_x);
                }
            }
            e++;
        }

        p1.v.x = zero;
        p1.v.y = zero;
        p1.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0xb5c);
        lbl_8006E1B0(&p1.v.x, &p1.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p1.v.x;
                dy = e->pos_y - p1.v.y;
                dz = e->pos_z - p1.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[297]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p1.v, c[298] * s, &p1.t, &e->pos_x);
                }
            }
            e++;
        }

        p2.v.x = k10;
        p2.v.y = zero;
        p2.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0xb5c);
        lbl_8006E1B0(&p2.v.x, &p2.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p2.v.x;
                dy = e->pos_y - p2.v.y;
                dz = e->pos_z - p2.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[153]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p2.v, c[142] * s, &p2.t, &e->pos_x);
                }
            }
            e++;
        }

        p3.v.x = k20;
        p3.v.y = zero;
        p3.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0xb5c);
        lbl_8006E1B0(&p3.v.x, &p3.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p3.v.x;
                dy = e->pos_y - p3.v.y;
                dz = e->pos_z - p3.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[153]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p3.v, c[142] * s, &p3.t, &e->pos_x);
                }
            }
            e++;
        }

        p4.v.x = zero;
        p4.v.y = zero;
        p4.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0x1318);
        lbl_8006E1B0(&p4.v.x, &p4.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p4.v.x;
                dy = e->pos_y - p4.v.y;
                dz = e->pos_z - p4.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[297]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p4.v, c[298] * s, &p4.t, &e->pos_x);
                }
            }
            e++;
        }

        p5.v.x = k10;
        p5.v.y = zero;
        p5.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0x1318);
        lbl_8006E1B0(&p5.v.x, &p5.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p5.v.x;
                dy = e->pos_y - p5.v.y;
                dz = e->pos_z - p5.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[153]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p5.v, c[142] * s, &p5.t, &e->pos_x);
                }
            }
            e++;
        }

        p6.v.x = k20;
        p6.v.y = zero;
        p6.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0x1318);
        lbl_8006E1B0(&p6.v.x, &p6.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p6.v.x;
                dy = e->pos_y - p6.v.y;
                dz = e->pos_z - p6.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[153]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p6.v, c[142] * s, &p6.t, &e->pos_x);
                }
            }
            e++;
        }

        p7.v.x = kneg;
        p7.v.y = kpos;
        p7.v.z = zero;
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        lbl_8006DBAC(base + 0x214);
        lbl_8006E1B0(&p7.v.x, &p7.v.x);
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            if ((e->active & 1) == 0) {
                dx = e->pos_x - p7.v.x;
                dy = e->pos_y - p7.v.y;
                dz = e->pos_z - p7.v.z;
                dist2 = dx * dx + dy * dy + dz * dz;
                if (dist2 < c[301]) {
                    s = lbl_8006D0E8(dist2);
                    psvec_sub_scale_add(&e->pos_x, &p7.v, c[302] * s, &p7.t, &e->pos_x);
                }
            }
            e++;
        }
    }

    if (lbl_801A66A0 % 90 < 20) {
        n = lbl_1_data_3FFBC[self->stage];
        base = (u8 *)*(void **)((u8 *)self + 0xc);
        base = *(u8 **)(base + 0x150);
        base = *(u8 **)(base + 8);
        base += n * 0x18c + 0x88;
        e = self->entries;
        for (i = 0; i < self->entry_count; i++) {
            lbl_8006DBAC(base);
            lbl_8006E1B0(&e->basis_x, &near.x);
            diff.x = e->pos_x - near.x;
            diff.y = e->pos_y - near.y;
            diff.z = e->pos_z - near.z;
            lbl_8006D668(&diff);
            e->vel_x -= c[105] * diff.x;
            e->vel_y -= c[105] * diff.y;
            e->vel_z -= c[105] * diff.z;
            e++;
        }
    }

    K1 = 0.8;
    K2 = 0.2;
    K3 = 0.5;
    e = self->entries;
    for (i = 0; i < self->entry_count; i++) {
        fn_1_1286F4(&grav);
        e->vel_x = (f32)((f32)((f32)((f64)e->vel_x * K1) * (f32)((f32)((f64)e->pos_x - (f64)e->vel_x) * K2 + (f64)e->vel_x)) + (f32)((f64)grav.x * K3));
        e->vel_y = (f32)((f32)((f32)((f64)e->vel_y * K1) * (f32)((f32)((f64)e->pos_y - (f64)e->vel_y) * K2 + (f64)e->vel_y)) + (f32)((f64)grav.y * K3));
        e->vel_z = (f32)((f32)((f32)((f64)e->vel_z * K1) * (f32)((f32)((f64)e->pos_z - (f64)e->vel_z) * K2 + (f64)e->vel_z)) + (f32)((f64)grav.z * K3));
        e++;
    }

    fn_80077B14(self->phys);
    n = lbl_1_data_3FFBC[self->stage];
    base = (u8 *)*(void **)((u8 *)self + 0xc);
    base = *(u8 **)(base + 0x150);
    base = *(u8 **)(base + 8);
    base += n * 0x18c + 0x88;
    lbl_8006DBAC(base);
    e = self->entries;
    for (i = 0; i < self->entry_count; i++) {
        for (j = 0; j < e->contact_count; j++) {
            fn_8006E250(&e->pos_x, base + (e->contacts[j] << 6));
        }
        e++;
    }
}
