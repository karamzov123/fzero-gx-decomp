/* Non-matching: best partial attempt (60.82% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad0[4];
    u16 flags;
    u16 next;
    u32 unk0;
    u8 padc[8];
    f32 radius;
    u8 pad18[0x7C];
    f32 x;
    u8 pad98[0x0C];
    f32 y;
    u8 pada8[0x0C];
    f32 z;
    u8 padb8[0xD0];
} Obj;

typedef struct { f32 x, y, z; } Vec3;
typedef struct { f32 m[3][4]; } Mtx;

extern const f32 lbl_1_rodata_F80;
extern const f32 lbl_1_rodata_F74;
extern const f32 lbl_1_rodata_F54;
struct GlobalMtx { u32 unk_0; };
extern struct GlobalMtx lbl_801A6D00;
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D668(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DB74(void *);
extern void *lbl_8006E1F0(void *, f32, f32, f32);
extern u32 lbl_8006D7B0(void);

static void cross(Vec3 *out, Vec3 *a, Vec3 *b) {
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
}

void *fn_1_44A74(Obj *arg0, Obj *arg1, f32 arg2) {
    Obj *nodes[3];
    Obj *node;
    s32 count = 0;
    s32 i;
    f32 *g;
    Vec3 delta, axis, tmp, vel, rot;
    Mtx *m;
    (void)arg2;

    if (arg1->flags & 0x100)
        return 0;
    node = (Obj *)((u8 *)arg0->unk0 + (u32)arg1->next * 0x18c);
    while ((node->flags & 2) == 0) {
        u16 next;
        if (count == 2)
            break;
        next = node->next;
        if (next == 0xffff)
            break;
        nodes[count++] = node;
        node = (Obj *)((u8 *)arg0->unk0 + (u32)next * 0x18c);
    }
    if (count == 0 || (count == 1 && nodes[0]->radius <= lbl_1_rodata_F80))
        nodes[count++] = node;
    lbl_8006DBAC((u8 *)node + 0x88);

    g = (f32 *)lbl_801A6D00.unk_0;
    delta.x = arg1->x - g[3];
    delta.y = *(f32 *)((u8 *)arg1 + 0xa4) - g[7];
    delta.z = *(f32 *)((u8 *)arg1 + 0xb4) - g[11];
    arg2 = lbl_8006D0B4(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
    lbl_8006D668(&delta);
    axis.x = g[6];
    axis.y = g[2];
    axis.z = g[10];
    cross(&tmp, &axis, &delta);
    lbl_8006D668(&tmp);
    cross(&vel, &delta, &tmp);
    m = (Mtx *)g;
    m->m[0][0] = delta.x; m->m[1][0] = delta.y; m->m[2][0] = delta.z;
    m->m[0][1] = tmp.x; m->m[1][1] = tmp.y; m->m[2][1] = tmp.z;
    m->m[0][2] = vel.x; m->m[1][2] = vel.y; m->m[2][2] = vel.z;

    if (count > 1) {
        f32 d = nodes[0]->radius;
        f32 r = *(f32 *)((u8 *)arg1 + 0x14);
        f32 t = (d*d - r*r + arg2*arg2) / (lbl_1_rodata_F74 * arg2);
        f32 h;
        if (d > t)
            h = lbl_8006D0B4(d*d - t*t);
        else {
            t = d;
            h = lbl_1_rodata_F54;
        }
        if ((nodes[0]->flags & 8) == 0)
            h = -h;
        lbl_8006E1F0(&rot, t, h, lbl_1_rodata_F54);
        rot.x += nodes[1]->x;
        rot.y += *(f32 *)((u8 *)nodes[1] + 0xa4);
        rot.z += *(f32 *)((u8 *)nodes[1] + 0xb4);
        lbl_8006D668(&rot);
        cross(&tmp, &axis, &rot);
        lbl_8006D668(&tmp);
        cross(&vel, &rot, &tmp);
        m = (Mtx *)lbl_801A6D00.unk_0;
        m->m[0][0] = rot.x; m->m[1][0] = rot.y; m->m[2][0] = rot.z;
        m->m[0][1] = tmp.x; m->m[1][1] = tmp.y; m->m[2][1] = tmp.z;
        m->m[0][2] = vel.x; m->m[1][2] = vel.y; m->m[2][2] = vel.z;
        lbl_8006DB74((u8 *)nodes[1] + 0x88);
        delta.x = arg1->x - rot.x;
        delta.y = *(f32 *)((u8 *)arg1 + 0xa4) - rot.y;
        delta.z = *(f32 *)((u8 *)arg1 + 0xb4) - rot.z;
        lbl_8006D668(&delta);
        cross(&tmp, &axis, &delta);
        lbl_8006D668(&tmp);
        cross(&vel, &delta, &tmp);
        m = (Mtx *)lbl_801A6D00.unk_0;
        m->m[0][0] = delta.x; m->m[1][0] = delta.y; m->m[2][0] = delta.z;
        m->m[0][1] = tmp.x; m->m[1][1] = tmp.y; m->m[2][1] = tmp.z;
        m->m[0][2] = vel.x; m->m[1][2] = vel.y; m->m[2][2] = vel.z;
        *(f32 *)0xE000000c = rot.x;
        *(f32 *)0xE000001c = rot.y;
        *(f32 *)0xE000002c = rot.z;
        lbl_8006DB74((u8 *)nodes[0] + 0x88);
    } else {
        lbl_8006DB74((u8 *)nodes[0] + 0x88);
    }
    *(f32 *)0xE000000c += *(f32 *)0xE0000000 * *(f32 *)((u8 *)arg1 + 0x14);
    *(f32 *)0xE000001c += *(f32 *)0xE0000010 * *(f32 *)((u8 *)arg1 + 0x14);
    *(f32 *)0xE000002c += *(f32 *)0xE0000020 * *(f32 *)((u8 *)arg1 + 0x14);
    if (arg1->flags & 4)
        lbl_8006D7B0();
    lbl_8006DB74((u8 *)arg1 + 0x88);
    return (u8 *)arg1 + 0x88;
}
