/* Non-matching: best partial attempt (97.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u32 f00;
    u32 f04;
    u8 pad_8[0x20];
    void *f28;
} Cfg21F18;

typedef struct {
    u32 f00;
    Cfg21F18 *cfg;
    u8 pad_8[0x10];
    f32 f18;
} Ent21F18;

typedef struct {
    u8 pad_0[0xc];
    s32 unk_C;
    Ent21F18 *unk_10;
} Obj21F18;

struct fn_1_21F18_pool {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

extern const struct fn_1_21F18_pool lbl_1_rodata_6C8;
extern f32 fn_1_9E14C(u32, void *, f32);
extern f32 lbl_8006D188(s16);
extern void fn_1_18214(Obj21F18 *, Vec3 *, s32, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80072558(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E1B0(Vec3 *, Vec3 *);

/* GX write-gather pipe: hardware FIFO, every store must be emitted */
#define FIFO_F32 (*(volatile f32 *)0xCC008000)

static inline void pos3f(f32 x, f32 y, f32 z) {
    FIFO_F32 = x;
    FIFO_F32 = y;
    FIFO_F32 = z;
}

static inline void vset(Vec3 *v, f32 x, f32 z, f32 y) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline f32 fn_1_21F18_read_pointer(Vec3 * owner) { return owner->y; }
#pragma opt_common_subs off
void fn_1_21F18(Obj21F18 *arg0, Vec3 *arg1, f32 arg4) {
    const struct fn_1_21F18_pool *pool = (const struct fn_1_21F18_pool *)&lbl_1_rodata_6C8;
    Vec3 verts[16];
    Vec3 pt;
    Vec3 *v;
    s32 i;
    s32 ang;
    f32 h;
    Ent21F18 *ent;
    Cfg21F18 *cfg;
    Vec3 * lab_t1;

    fn_1_18214(arg0, arg1, 0, arg4);
    v = verts;
    ang = 0;
    for (i = 0; i < 16; i++, ang += 0xC, v++) {
        vset(v, pool->unk_20 * lbl_8006D188((s16)ang), pool->unk_8, pool->unk_20 * lbl_8006D188((s16)(ang + 0x4000)));
        v->x *= arg1->x;
        v->y *= arg1->y;
        lab_t1 = v;
        lbl_8006E1B0(v, lab_t1);
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    v = verts;
    fn_8003462C(0xb0, 0, 17);
    for (i = 0; i < 16; i++, v++) {
        pos3f(v->x, fn_1_21F18_read_pointer(v), v->z);
    }
    FIFO_F32 = verts[0].x;
    FIFO_F32 = verts[0].y;
    FIFO_F32 = verts[0].z;
    lbl_8006DB30();
    if (arg0->unk_C == 1) {
        ent = arg0->unk_10;
        cfg = ent->cfg;
        if (cfg->f28 != 0) {
            h = fn_1_9E14C(cfg->f04, cfg->f28, arg4);
        } else {
            h = ent->f18;
        }
        vset(&pt, pool->unk_20, pool->unk_8, pool->unk_34 + h);
        pt.x *= arg1->x;
        pt.y *= arg1->y;
        lbl_8006E1B0(&pt, &verts[0]);
        pt.x = -pt.x;
        lbl_8006E1B0(&pt, &verts[1]);
        lbl_8006DAEC();
        lbl_8006DCA4();
        fn_80072558();
        fn_8003462C(0xb0, 0, 2);
        FIFO_F32 = verts[0].x;
        FIFO_F32 = verts[0].y;
        FIFO_F32 = verts[0].z;
        FIFO_F32 = verts[1].x;
        FIFO_F32 = verts[1].y;
        FIFO_F32 = verts[1].z;
        lbl_8006DB30();
    }
}
#pragma opt_common_subs reset

