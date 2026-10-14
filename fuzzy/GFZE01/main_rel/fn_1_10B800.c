/* Non-matching: best partial attempt (98.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { f32 x, y, z; } Vec3;

struct PoolObj {
    u8 pad_0[0xE8];
    Vec3 v[3];
    f32 lo;
    f32 hi;
};
extern struct PoolObj lbl_1_rodata_7AB8;

struct Rec {
    s16 f_00;
    u8 count;
    u8 pad_1[1];
    u16 idx[18];
    Vec3 v;
    u32 pad_2[4];
};

struct MgrInner {
    u8 pad_0[8];
    u8 *p;
};

struct Mgr {
    u8 pad_0[0x150];
    struct MgrInner *inner;
};

struct Accessory {
    u8 pad_0[0xC];
    struct Mgr *mgr;
    u8 *arg;
    u32 pad_1;
    u32 count;
    u32 pad_2[2];
    struct Rec *recs;
};

extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D758(void);
extern f32 fn_1_1289F0(void *, void *, void *);
extern u32 mathutil_mtxA_rotate_y(u32);

void fn_1_10B800(struct Accessory *acc) {
    struct PoolObj *pool = &lbl_1_rodata_7AB8;
    Vec3 c1 = pool->v[0];
    Vec3 c2 = pool->v[1];
    s32 angle;
    s16 d = 0x100;
    u8 *base;
    u8 *p;
    u32 n;
    f32 f1;
    f32 lo;
    Vec3 c3;
    u32 i;
    u32 j;
    struct Rec *rec;

    if (acc != 0 && acc->arg != 0) {
        base = (u8 *)fn_80077B14(acc->arg);
        p = acc->mgr->inner->p;

        lbl_8006DBAC(p + 0x1C60);
        lbl_8006E1B0(&c1, &c1);
        lbl_8006DBAC(p + 0x1C60);
        lbl_8006E1B0(&c2, &c2);

        angle = -0x800;
        lo = pool->lo;
        n = 100;
        p = acc->mgr->inner->p;
        do {
            c3 = pool->v[2];
            lbl_8006DBAC(p + 0x1948);
            mathutil_mtxA_rotate_y(angle);
            lbl_8006E1B0(&c3, &c3);
            f1 = fn_1_1289F0(&c1, &c2, &c3);
            if (f1 < lo) {
                if (d > 0) {
                    d = -(d / 2);
                }
            } else if (f1 > pool->hi) {
                if (d < 0) {
                    d = -(d / 2);
                }
            }
            angle += d;
        } while ((f1 < lo || pool->hi < f1) && n-- != 0);

        lbl_8006D758();
        mathutil_mtxA_rotate_y(angle);

        rec = acc->recs;
        i = 0;
        while (i < acc->count) {
            for (j = 0; j < rec->count; j++) {
                lbl_8006E1B0(&rec->v, base + rec->idx[j] * 0x40);
            }
            i++;
            rec++;
        }
    }
}
