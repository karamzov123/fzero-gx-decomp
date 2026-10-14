/* Non-matching: best partial attempt (94.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_125DF0_Vec;

typedef struct {
    u8 pad_0[0x2];
    u8 count;
    u8 pad_3[0x1];
    u16 indices[6];
    fn_1_125DF0_Vec pos;
    fn_1_125DF0_Vec prev;
    fn_1_125DF0_Vec aux;
    fn_1_125DF0_Vec vel;
    f32 scale;
} fn_1_125DF0_Entry;

typedef struct {
    u8 pad_0[0x8];
    u8 *unk_8;
} fn_1_125DF0_List;

typedef struct {
    u8 pad_0[0x150];
    fn_1_125DF0_List *unk_150;
} fn_1_125DF0_Owner;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 type;
    fn_1_125DF0_Owner *owner;
    void *resource;
    u32 pad_14;
    u32 count;
    u8 pad_1c[0x8];
    fn_1_125DF0_Entry *entries;
} fn_1_125DF0_Data;

typedef struct {
    f32 pad_0[41];
    f32 dist_eps;
    f32 pad_1[60];
    f64 half;
    f32 pad_2[10];
    f32 blend_min;
    f32 pad_3[216];
    f32 blend_max;
    f64 y_scale;
    f32 vel_decay;
} fn_1_125DF0_Consts;

extern fn_1_125DF0_Consts lbl_1_rodata_7AB8;
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(fn_1_125DF0_Vec *, fn_1_125DF0_Vec *);
extern void lbl_8006DC20(void);
extern f32 lbl_8006D0B4(f32);
extern void fn_1_1286F4(fn_1_125DF0_Vec *);
extern void fn_8006E250(fn_1_125DF0_Vec *, void *);
extern f64 __fabs(f64);

static inline f32 fn_1_125DF0_read_pointer(fn_1_125DF0_Entry * owner) { return owner->pos.z; }
static inline f32 fn_1_125DF0_read_pointer_(fn_1_125DF0_Entry * owner) { return owner->pos.y; }
void fn_1_125DF0(fn_1_125DF0_Data *data) {
    fn_1_125DF0_Consts *constants;
    fn_1_125DF0_Entry *e1;
    u32 i5;
    fn_1_125DF0_Vec acc;
    fn_1_125DF0_Entry *e4;
    fn_1_125DF0_Entry *e5;
    fn_1_125DF0_Entry *e6;
    u32 i1;
    u32 i2;
    u32 i3;
    u32 i4;
    fn_1_125DF0_Entry *e2;
    u32 i6;
    s32 j;
    u8 *obj;
    void *base;
    f32 blend;
    f32 len2;
    f32 step;
    f32 dx;
    f32 dy;
    f32 dz;
    f64 s;
    f64 half;
    f64 ys3;
    f32 hi3;
    f32 lo3;
    f32 eps4;
    f32 hi5;
    f32 dec5;
    fn_1_125DF0_Entry *e3;
    fn_1_125DF0_Vec tgt;
    f32 delta[3];
    fn_1_125DF0_Vec out;

    constants = (fn_1_125DF0_Consts *)&lbl_1_rodata_7AB8;
    if (data != 0) {
        if (data->resource != 0) {
            fn_80077B14(data->resource);
            if (data->unk_0 & 2) {
                data->unk_0 &= 7;
                lbl_8006DBAC((u8 *)data->owner->unk_150->unk_8 +
                    *(u32 *)((u8 *)&lbl_1_data_3FFBC + data->type * 4) * 0x18C + 0x88);
                lbl_8006DAEC();
                e1 = data->entries;
                i1 = 0;
                while (i1 < data->count) {
                    lbl_8006DBE4();
                    lbl_8006E1B0(&e1->aux, &e1->pos);
                    i1++;
                    e1++;
                }
                lbl_8006DC20();
            }
        }

{
    u32 fzgx_loop_i2_2824;
        e2 = data->entries;
        fzgx_loop_i2_2824 = 0;
        half = constants->half;
        while (fzgx_loop_i2_2824 < data->count) {
            fn_1_1286F4(&acc);
            e2->prev = e2->pos;
            s = half * acc.x;
            s = e2->vel.x + s;
            e2->pos.x = e2->pos.x + s;
            s = half * acc.y;
            s = e2->vel.y + s;
            e2->pos.y = e2->pos.y + s;
            s = half * acc.z;
            s = e2->vel.z + s;
            e2->pos.z = e2->pos.z + s;
            e2->vel.x += acc.x;
            e2->vel.y += acc.y;
            e2->vel.z += acc.z;
            fzgx_loop_i2_2824++;
            e2++;
        }
    i2 = fzgx_loop_i2_2824;
}

        e3 = data->entries;
        i3 = 0;
        obj = (u8 *)data->owner->unk_150->unk_8 +
            *(u32 *)((u8 *)&lbl_1_data_3FFBC + data->type * 4) * 0x18C;
        lo3 = constants->blend_min;
        hi3 = constants->blend_max;
        ys3 = constants->y_scale;
        while (i3 < data->count) {
            blend = e3->scale;
            blend = (f32)__fabs(blend);
            blend = blend * blend;
            if (blend < lo3) {
                blend = lo3;
            }
            if (blend > hi3) {
                blend = hi3;
            }
            lbl_8006DBAC(obj + 0x88);
            lbl_8006E1B0(&e3->aux, &tgt);
            dx = tgt.x - e3->pos.x;
            dy = tgt.y - fn_1_125DF0_read_pointer_(e3);
            dz = tgt.z - e3->pos.z;
            e3->pos.x = e3->pos.x + (f32)(blend * dx);
            e3->pos.y = fn_1_125DF0_read_pointer_(e3) + (f32)(ys3 * dy);
            e3->pos.z = fn_1_125DF0_read_pointer(e3) + (f32)(blend * dz);
            i3++;
            e3++;
        }

        e4 = data->entries;
        i4 = 0;
        obj = (u8 *)data->owner->unk_150->unk_8 +
            *(u32 *)((u8 *)&lbl_1_data_3FFBC + data->type * 4) * 0x18C;
        eps4 = constants->dist_eps;
        while (i4 < data->count) {
            lbl_8006DBAC(obj + 0x88);
            lbl_8006E1B0(&e4->aux, &out);
            delta[0] = e4->pos.x - out.x;
            delta[1] = e4->pos.y - out.y;
            delta[2] = e4->pos.z - out.z;
            len2 = (f32)(delta[0] * delta[0]) + delta[1] * delta[1] + delta[2] * delta[2];
            if (len2 > eps4) {
                step = lbl_8006D0B4(eps4 / len2);
                e4->pos.x = out.x + (f32)(delta[0] * step);
                e4->pos.y = out.y + (f32)(delta[1] * step);
                e4->pos.z = out.z + (f32)(delta[2] * step);
                e4->prev = e4->pos;
            }
            i4++;
            e4++;
        }

        e5 = data->entries;
        i5 = 0;
        dec5 = constants->vel_decay;
        hi5 = constants->blend_max;
        while (i5 < data->count) {
            e5->vel.x = dec5 * (e5->pos.x - e5->prev.x);
            e5->vel.y = hi5 * (e5->pos.y - e5->prev.y);
            e5->vel.z = dec5 * (e5->pos.z - e5->prev.z);
            i5++;
            e5++;
        }

        base = fn_80077B14(data->resource);
        lbl_8006DBAC((u8 *)data->owner->unk_150->unk_8 +
            *(u32 *)((u8 *)&lbl_1_data_3FFBC + data->type * 4) * 0x18C + 0x88);
        e6 = data->entries;
        i6 = 0;
        while (i6 < data->count) {
            for (j = 0; j < e6->count; j++) {
                fn_8006E250(&e6->pos, (u8 *)base + e6->indices[j] * 0x40);
            }
            i6++;
            e6++;
        }
    }
}
