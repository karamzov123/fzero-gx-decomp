/* Non-matching: best partial attempt (75.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};
struct Node {
    u8 flag; u8 pad_1; u8 count; u8 pad_3;
    u16 ids[2];
    u8 pad_8[8];
    f32 x,y,z;
    u32 px,py,pz;
    f32 outx,outy,outz;
    f32 vx,vy,vz;
    f32 radius;
};
struct Manager { u8 pad[0x150]; void *obj; };
struct Root { u8 flags; u8 pad_1[7]; u32 index; struct Manager *manager; void *setup; u8 pad_14[4]; u32 count; u8 pad_1c[8]; struct Node *nodes; };
struct Table { u32 index[1]; };
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern struct Table lbl_1_data_3FFBC;
extern u8 lbl_1_rodata_7AB8[];
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DC20(void);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E250(void *, void *);

void fn_1_11CD3C(struct Root *arg0) {
    u8 *pool = lbl_1_rodata_7AB8;
    u32 i;
    struct Node *n;
    u32 idx;
    void *obj;
    f32 d;
    if (arg0 == 0 || arg0->setup == 0) return;
    fn_80077B14((void *)arg0->setup);
    if (arg0->flags & 2) {
        u32 *base = (u32 *)((u8 *)arg0->manager->obj + 8);
        arg0->flags &= ~2;
        idx = lbl_1_data_3FFBC.index[arg0->index];
        lbl_8006DBAC(base + idx * 0x18c + 0x22);
        lbl_8006DAEC();
        for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
            lbl_8006DBE4();
            lbl_8006E1B0((u8 *)n + 0x28, (u8 *)n + 0x10);
        }
        lbl_8006DC20();
    }
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        if (!(n->flag & 1)) {
            n->px = *(u32 *)&n->x; n->py = *(u32 *)&n->y; n->pz = *(u32 *)&n->z;
            n->x += n->vx; n->y += n->vy; n->z += n->vz;
            n->y = (f32)((f64)n->y - *(f64 *)(pool + 0x58));
            n->vy -= *(f32 *)(pool + 0x60);
        }
    }
    idx = lbl_1_data_3FFBC.index[arg0->index];
    obj = *(void **)((u8 *)arg0->manager->obj + 8);
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        lbl_8006DBAC((u8 *)obj + idx * 0x18c + 0x88);
        lbl_8006DAEC();
        if (n->flag & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0((u8 *)n + 0x28, (u8 *)n + 0x10);
        }
        lbl_8006DC20();
    }
    idx = lbl_1_data_3FFBC.index[arg0->index];
    obj = *(void **)((u8 *)arg0->manager->obj + 8);
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        f32 a, b, c, k, dx, dy, dz;
        if (!(n->flag & 1)) {
            lbl_8006DBAC((u8 *)obj + idx * 0x18c + 0x88);
            lbl_8006E1B0((u8 *)n + 0x28, &d);
            a = d - n->x;
            b = *(f32 *)((u8 *)&d + 4) - n->y;
            c = *(f32 *)((u8 *)&d + 8) - n->z;
            k = (f32)(*(f64 *)(pool + 0x438) -
                    *(f64 *)(pool + 0x440) * __fabs(n->radius));
            dx = (f32)((f64)a * k);
            dy = (f32)(*(f64 *)(pool + 0x340) * (f64)b);
            dz = (f32)((f64)c * k);
            n->x += dx; n->y += dy; n->z += dz;
        }
    }
    idx = lbl_1_data_3FFBC.index[arg0->index];
    obj = *(void **)((u8 *)arg0->manager->obj + 8);
    d = *(f32 *)(pool + 0xa4);
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        f32 a, b, c, len, s;
        lbl_8006DBAC((u8 *)obj + idx * 0x18c + 0x88);
        lbl_8006E1B0((u8 *)n + 0x28, &d);
        a = n->x - d; b = n->y - *(f32 *)((u8 *)&d + 4); c = n->z - *(f32 *)((u8 *)&d + 8);
        len = (f32)(a*a + b*b + c*c);
        if (len > *(f32 *)(pool + 0xa4)) {
            f32 s = lbl_8006D0B4(*(f32 *)(pool + 0xa4) / len);
            n->x = d + a*s;
            n->y = *(f32 *)((u8 *)&d + 4) + b*s;
            n->z = *(f32 *)((u8 *)&d + 8) + c*s;
            n->px = *(u32 *)&n->x; n->py = *(u32 *)&n->y; n->pz = *(u32 *)&n->z;
        }
    }
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        n->vx = 0.8f * (n->x - *(f32 *)&n->px);
        n->vy = 0.8f * (n->y - *(f32 *)&n->py);
        n->vz = 0.8f * (n->z - *(f32 *)&n->pz);
    }
    idx = lbl_1_data_3FFBC.index[arg0->index];
    obj = (void *)fn_80077B14((void *)arg0->manager);
    lbl_8006DBAC((u8 *)*(void **)((u8 *)arg0->manager->obj + 8) + idx * 0x18c + 0x88);
    for (i = 0, n = arg0->nodes; i < arg0->count; i++, n++) {
        u32 j;
        for (j = 0; j < n->count; j++) {
            u16 id = *(u16 *)((u8 *)n + 4 + j*2);
            fn_8006E250((u8 *)n + 0x10, (u8 *)obj + id * 64);
        }
    }
}
