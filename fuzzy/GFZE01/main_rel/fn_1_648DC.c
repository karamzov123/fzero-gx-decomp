/* Non-matching: best partial attempt (87.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    Vec3 pos;
    Vec3 spare;
} Hit;

struct Self_648DC {
    u8 pad00[0x18];
    s16 kind;
    u8 pad1A[0x0E];
    f32 speed;
    f32 charge;
    u8 pad30[0x04];
    u32 object;
    u8 pad38[0x04];
    Vec3 pos;
    Vec3 dir;
    s16 rot[3];
    s16 ang[3];
    Vec3 tgt;
    u8 pad6C[0x1C];
    f32 value88;
    f32 value8C;
    u8 pad90[0x10];
    Vec3 normal;
};

extern s32 fn_1_8C66C(s16);
extern s32 fn_1_15578(Vec3 *, Vec3 *, f32 *, Hit *, u32, u32 *, u32, void *);
extern u32 lbl_8006D8D8(s16);
extern u32 mathutil_mtxA_rotate_x(s16);
extern u32 mathutil_mtxA_rotate_z(s16);
extern u32 lbl_8006E1C0(void *, void *);
extern void lbl_8006D668(Vec3 *);
extern s16 lbl_8006D24C(f32, f32);
extern f32 lbl_8006D0B4(f32);

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_1_648DC(struct Self_648DC *self) {
    u32 st[3];
    f32 pad14;
    Vec3 v;
    Vec3 w;
    Vec3 d;
    Hit hit;
    s32 ok;
    void *obj;
    f32 s;
    f32 dot;
    f32 slope;
    f32 n;
    f32 len;
    s16 old0;
    s16 old2;

    s = 1.0f - self->value88;
    self->dir.x = self->dir.x * s;
    self->dir.y = self->dir.y * s;
    self->dir.z = self->dir.z * s;
    self->dir.y = self->dir.y + -0.03f;
    self->pos.x = self->pos.x + self->dir.x;
    self->pos.y = self->pos.y + self->dir.y;
    self->pos.z = self->pos.z + self->dir.z;
    self->ang[0] = self->ang[0] - (self->ang[0] >> 5);
    self->ang[1] = self->ang[1] - (self->ang[1] >> 5);
    self->ang[2] = self->ang[2] - (self->ang[2] >> 5);
    self->rot[0] = self->rot[0] + self->ang[0];
    self->rot[1] = self->rot[1] + self->ang[1];
    self->rot[2] = self->rot[2] + self->ang[2];
    self->value88 = self->value88 + (f32)(0.03f * (self->value8C - self->value88));

    st[2] = fn_1_8C66C(self->kind);
    st[0] = 0;
    st[1] = 0;
    ok = fn_1_15578(&self->pos, &self->tgt, &pad14, &hit, 0x40005, &st[2], 1, 0);
    if (ok == 0) {
        goto done;
    }
    obj = (void *)self->object;
    d.x = self->pos.x - self->tgt.x;
    d.y = self->pos.y - self->tgt.y;
    d.z = self->pos.z - self->tgt.z;
    if (self->speed < 0.04) {
        self->dir.x = (f32)((f64)self->dir.x * 0.98);
        self->dir.y = (f32)((f64)self->dir.y * 0.98);
        self->dir.z = (f32)((f64)self->dir.z * 0.98);
    } else {
        self->dir.x = (f32)((f64)self->dir.x * 0.96);
        self->dir.y = (f32)((f64)self->dir.y * 0.96);
        self->dir.z = (f32)((f64)self->dir.z * 0.96);
    }
    dot = hit.pos.x * d.x + hit.pos.y * d.y + hit.pos.z * d.z;
    if (dot < 0.025) {
        self->normal = hit.pos;
        self->charge = (f32)(*(f32 *)((u8 *)obj + 0x14) * self->speed) - dot;
        slope = self->dir.x * hit.pos.x + self->dir.y * hit.pos.y + self->dir.z * hit.pos.z;
        if (slope < 0.0) {
            n = (f32)((f64)slope * -1.0);
            self->dir.x = (f32)(n * hit.pos.x) + self->dir.x;
            self->dir.y = (f32)(n * hit.pos.y) + self->dir.y;
            self->dir.z = (f32)(n * hit.pos.z) + self->dir.z;
            self->dir.x = (f32)((f64)self->dir.x * 0.8);
            self->dir.y = (f32)((f64)self->dir.y * 0.8);
            self->dir.z = (f32)((f64)self->dir.z * 0.8);
            if (self->speed < 0.04) {
                n = n * 0.5f;
            } else {
                n = n * 0.3f;
            }
            self->dir.x = (f32)(n * hit.pos.x) + self->dir.x;
            self->dir.y = (f32)(n * hit.pos.y) + self->dir.y;
            self->dir.z = (f32)(n * hit.pos.z) + self->dir.z;
        }
    }

    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    w = hit.pos;
    lbl_8006D8D8(self->rot[1]);
    mathutil_mtxA_rotate_x(self->rot[0]);
    mathutil_mtxA_rotate_z(self->rot[2]);
    lbl_8006E1C0(&v, &v);
    dot = (f32)(v.x * hit.pos.x) + (f32)(v.y * hit.pos.y) + (f32)(v.z * hit.pos.z);
    if (dot < 0.0) {
        w.x = -w.x;
        w.y = -w.y;
        w.z = -w.z;
    }
    v.x = v.x * 0.95f + w.x * 0.05f;
    v.y = v.y * 0.95f + w.y * 0.05f;
    v.z = v.z * 0.95f + w.z * 0.05f;
    lbl_8006D668(&v);
    old0 = self->rot[0];
    old2 = self->rot[2];
    lbl_8006D8D8(-self->rot[1]);
    mathutil_mtxA_rotate_x(0);
    lbl_8006E1C0(&v, &v);
    self->rot[0] = lbl_8006D24C(v.z, v.y);
    len = lbl_8006D0B4((f32)(v.z * v.z) + v.y * v.y);
    self->rot[2] = -lbl_8006D24C(v.x, len);
    self->ang[0] = self->ang[0] >> 2;
    self->ang[0] = self->ang[0] + ((self->rot[0] - old0) >> 2);
    self->ang[1] = self->ang[1] - (self->ang[1] >> 4);
    self->ang[2] = self->ang[2] >> 2;
    self->ang[2] = self->ang[2] + ((self->rot[2] - old2) >> 2);
done:
    return;
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
