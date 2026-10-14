/* Non-matching: best partial attempt (71.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    f32 x, y, z;
} fn_1_123050_Vec3;

typedef struct {
    u8 unk_0;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4[6];
    fn_1_123050_Vec3 unk_10;
    fn_1_123050_Vec3 unk_1c;
    u8 unk_28[0xc];
    fn_1_123050_Vec3 unk_34;
    f32 unk_40;
} fn_1_123050_Particle;

typedef struct {
    fn_1_123050_Particle *a;
    fn_1_123050_Particle *b;
    f32 unk_8;
} fn_1_123050_Contact;

typedef struct {
    u8 unk_0;
    u8 pad_0[0x07];
    u32 unk_8;
    void *unk_c;
    void *unk_10;
    s32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u8 pad_20[0x04];
    fn_1_123050_Particle *unk_24;
    fn_1_123050_Contact *unk_28;
} fn_1_123050_Obj;

extern void fn_1_108128(fn_1_123050_Obj *, u32);
extern void fn_1_1286F4(fn_1_123050_Vec3 *);
extern f64 lbl_8006D118(f32);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D668(fn_1_123050_Vec3 *);
extern void fn_8006E250(fn_1_123050_Vec3 *, void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DC20(void);
extern void *fn_80077B14(void *);
extern u32 lbl_801A63C0;

void fn_1_123050(fn_1_123050_Obj *obj) {
    f32 anchor[11];
    void *base;
    void *tex;
    u32 i;
    u32 j;
    u32 k;
    u32 slot_count;
    u32 iters;
    fn_1_123050_Particle *p;
    fn_1_123050_Particle *a;
    fn_1_123050_Particle *b;
    fn_1_123050_Contact *c;
    fn_1_123050_Vec3 v;
    fn_1_123050_Vec3 d;
    fn_1_123050_Vec3 n;
    f32 t;
    f64 r;
    f32 ma;
    f32 mb;
    f32 accel;
    f32 mass_sum;
    f64 damp;
    f64 accel_d;

    if (obj == 0) {
        return;
    }

    if (obj->unk_10 == 0) {
        return;
    }

    fn_80077B14(obj->unk_10);

    if ((obj->unk_0 & 2) != 0) {
        obj->unk_0 = obj->unk_0 & 0xfffffffd;

        base = *(void **)((u8 *)&lbl_1_data_3FFBC + obj->unk_8 * 4);
        base = *(void **)((u8 *)base + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        lbl_8006DBAC((u8 *)base + 0x88);
        lbl_8006DAEC();

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            lbl_8006DBE4();
            lbl_8006E1B0(&p->unk_28, &p->unk_10);
            p++;
        }

        lbl_8006DC20();
    }

    if (*(s32 *)((u8 *)obj->unk_c + 0x8c) == 2) {
        slot_count = 8;
    } else {
        slot_count = 0xc;
    }

    p = obj->unk_24;
    for (i = 0; i < obj->unk_18; i++) {
        if ((p->unk_0 & 1) == 0) {
            p->unk_1c = p->unk_10;
            p->unk_10.x = p->unk_10.x + p->unk_34.x;
            p->unk_10.y = p->unk_10.y + p->unk_34.y;
            p->unk_10.z = p->unk_10.z + p->unk_34.z;
            p->unk_10.y = (f32)((f64)p->unk_10.y - 0.0013611111376020642);
            p->unk_34.y = p->unk_34.y - 0.0027222223579883575f;
        }
        p++;
    }

    base = *(void **)((u8 *)&lbl_1_data_3FFBC + obj->unk_8 * 4);
    base = *(void **)((u8 *)base + 0x150);
    base = *(void **)((u8 *)base + 0x8);

    k = 0;
    p = obj->unk_24;
    while (k < obj->unk_18) {
        lbl_8006DBAC((u8 *)base + 0x88);
        lbl_8006DAEC();
        if ((p->unk_0 & 1) != 0) {
            lbl_8006DBE4();
            lbl_8006E1B0(&p->unk_28, &p->unk_10);
        }
        lbl_8006DC20();
        k++;
        p++;
    }

    if (*(s32 *)((u8 *)obj->unk_c + 0x8c) == 2) {
        iters = 2;
    } else {
        iters = 4;
    }

    anchor[8] = 0.0f;
    anchor[9] = 0.082f;
    anchor[10] = 0.047f;
    anchor[7] = -0.004f;
    anchor[6] = 0.12f;
    anchor[5] = -0.019f;
    anchor[3] = -0.028f;
    anchor[4] = 0.265f;
    anchor[2] = 0.08f;
    anchor[0] = -0.025f;
    anchor[1] = 0.138f;

    for (k = 0; k < iters; k++) {
        c = obj->unk_28;
        for (j = 0; j < obj->unk_1c; j++) {
            a = c->a;
            b = c->b;

            if (a == 0 || b == 0) {
                goto next_contact; /* early out: no pair */
            }

            d.x = a->unk_10.x - b->unk_10.x;
            d.y = a->unk_10.y - b->unk_10.y;
            d.z = a->unk_10.z - b->unk_10.z;

            t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;

            if (t - 9.999999747378752e-05f > c->unk_8) {
                r = lbl_8006D118(t);
                t = (f32)(r * (t - lbl_8006D0B4(c->unk_8)));
                mass_sum = a->unk_40 + b->unk_40;
                accel = 1.0f / mass_sum;
                ma = -(a->unk_40 * accel);
                mb = b->unk_40 * accel;
                psvec_scale(&d.x, t, &d.x);
                psvec_scale_add(&a->unk_10.x, &d.x, ma, &a->unk_10.x);
                psvec_scale_add(&b->unk_10.x, &d.x, mb, &b->unk_10.x);
            }

            if (0.001f + t < c->unk_8 && (u32)j < (slot_count - 1) * 2) {
                r = lbl_8006D118(t);
                t = (f32)(r * (t - lbl_8006D0B4(c->unk_8)));
                mass_sum = a->unk_40 + b->unk_40;
                accel = 1.0f / mass_sum;
                ma = -(a->unk_40 * accel);
                mb = b->unk_40 * accel;
                psvec_scale(&d.x, t, &d.x);
                psvec_scale_add(&a->unk_10.x, &d.x, ma, &a->unk_10.x);
                psvec_scale_add(&b->unk_10.x, &d.x, mb, &b->unk_10.x);
            }

            if (a->unk_10.y < 0.0f || b->unk_10.y < 0.0f) {
                if ((a->unk_0 & 1) == 0 && (b->unk_0 & 1) == 0) {
                    if (a->unk_10.y < 0.0f) {
                        a->unk_10.y = 9.999999747378752e-06f;
                    }

                    if (b->unk_10.y < 0.0f) {
                        b->unk_10.y = 9.999999747378752e-06f;
                    }

                    d.x = a->unk_10.x - b->unk_10.x;
                    d.y = a->unk_10.y - b->unk_10.y;
                    d.z = a->unk_10.z - b->unk_10.z;

                    t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;

                    r = lbl_8006D118(t);
                    t = (f32)(r * (t - lbl_8006D0B4(c->unk_8)));
                    mass_sum = a->unk_40 + b->unk_40;
                    accel = 1.0f / mass_sum;
                    ma = -(a->unk_40 * accel);
                    mb = b->unk_40 * accel;
                    psvec_scale(&d.x, t, &d.x);
                    psvec_scale_add(&a->unk_10.x, &d.x, ma, &a->unk_10.x);
                    psvec_scale_add(&b->unk_10.x, &d.x, mb, &b->unk_10.x);
                }
            }

next_contact:
            c++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[10];
        v.y = anchor[9];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1948);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.01040400005877018f) {
                    accel = 0.10199999809265137f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[7];
        v.y = anchor[8];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1c60);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.003599999938160181f) {
                    accel = 0.05999999865889549f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[6];
        v.y = anchor[8];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1c60);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.005625000223517418f) {
                    accel = 0.07500000298023224f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[8];
        v.y = anchor[5];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1dec);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.005625000223517418f) {
                    accel = 0.07500000298023224f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[4];
        v.y = anchor[3];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1dec);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.01209999993443489f) {
                    accel = 0.10999999940395355f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[7];
        v.y = anchor[8];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x241c);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.003599999938160181f) {
                    accel = 0.05999999865889549f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[6];
        v.y = anchor[8];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x241c);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.005625000223517418f) {
                    accel = 0.07500000298023224f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[8];
        v.y = anchor[5];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x25a8);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.005625000223517418f) {
                    accel = 0.07500000298023224f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[4];
        v.y = anchor[3];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x25a8);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.01209999993443489f) {
                    accel = 0.10999999940395355f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[2];
        v.y = anchor[8];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1c60);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.006399999838322401f) {
                    accel = 0.07999999821186066f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[1];
        v.y = anchor[0];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x1dec);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.011024999432265759f) {
                    accel = 0.10499999672174454f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[2];
        v.y = anchor[8];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x241c);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.006399999838322401f) {
                    accel = 0.07999999821186066f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }

        base = *(void **)((u8 *)obj->unk_c + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        v.x = anchor[1];
        v.y = anchor[0];
        v.z = anchor[8];

        lbl_8006DBAC((u8 *)base + 0x25a8);
        lbl_8006E1B0(&v, &v);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if ((p->unk_0 & 1) == 0) {
                d.x = p->unk_10.x - v.x;
                d.y = p->unk_10.y - v.y;
                d.z = p->unk_10.z - v.z;
                t = (f32)(d.x * d.x) + d.y * d.y + d.z * d.z;
                if (t < 0.011024999432265759f) {
                    accel = 0.10499999672174454f * lbl_8006D0E8(t);
                    psvec_sub_scale_add(&p->unk_10.x, &v.x, accel, &d.x, &p->unk_10.x);
                }
            }
            p++;
        }
    }

    if (obj->unk_14 < 0x23) {
        base = *(void **)((u8 *)&lbl_1_data_3FFBC + obj->unk_8 * 4);
        base = *(void **)((u8 *)base + 0x150);
        base = *(void **)((u8 *)base + 0x8);

        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            lbl_8006DBAC((u8 *)base + 0x88);
            lbl_8006E1B0(&n, &p->unk_28);
            n.x = p->unk_10.x - n.x;
            n.y = p->unk_10.y - n.y;
            n.z = p->unk_10.z - n.z;
            lbl_8006D668(&n);
            p->unk_34.x = p->unk_34.x - 0.0010000000474974513f * n.x;
            p->unk_34.y = p->unk_34.y - 0.0010000000474974513f * n.y;
            p->unk_34.z = p->unk_34.z - 0.0010000000474974513f * n.z;
            p++;
        }
    }

    obj->unk_14 = obj->unk_14 - 1;

    if (obj->unk_14 < 0) {
        u32 s = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        lbl_801A63C0 = s;
        obj->unk_14 = (s32)((s >> 1) & 0x7fff) % 20 + 0x28;
    }

    damp = 0.59;
    accel_d = 0.4;

    p = obj->unk_24;
    for (i = 0; i < obj->unk_18; i++) {
        fn_1_1286F4(&n);

        p->unk_34.x = p->unk_34.x * damp;
        p->unk_34.y = p->unk_34.y * damp;
        p->unk_34.z = p->unk_34.z * damp;

        p->unk_34.x = p->unk_34.x + accel_d * (p->unk_10.x - p->unk_1c.x);
        p->unk_34.y = p->unk_34.y + accel_d * (p->unk_10.y - p->unk_1c.y);
        p->unk_34.z = p->unk_34.z + accel_d * (p->unk_10.z - p->unk_1c.z);

        p->unk_34.x = p->unk_34.x + accel_d * n.x;
        p->unk_34.y = p->unk_34.y + accel_d * n.y;
        p->unk_34.z = p->unk_34.z + accel_d * n.z;

        p++;
    }

    fn_1_108128(obj, slot_count);

    tex = fn_80077B14(obj->unk_10);

    base = *(void **)((u8 *)&lbl_1_data_3FFBC + obj->unk_8 * 4);
    base = *(void **)((u8 *)base + 0x150);
    base = *(void **)((u8 *)base + 0x8);

    lbl_8006DBAC((u8 *)base + 0x88);

    p = obj->unk_24;
    for (i = 0; i < obj->unk_18; i++) {
        for (j = 0; j < p->unk_2; j++) {
            fn_8006E250(&p->unk_10, (u8 *)tex + (p->unk_4[j] << 6));
        }
        p++;
    }
}
