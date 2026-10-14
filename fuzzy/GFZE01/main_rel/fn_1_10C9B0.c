/* Non-matching: best partial attempt (92.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Item_10C9B0 {
    u8 flag;
    u8 pad_01[0x17];
    f32 f18;
    u8 pad_1C[0x24];
    f32 f40;
};

struct Obj_10C9B0 {
    u8 pad_00[0x18];
    u32 count;
    u8 pad_1C[0x8];
    struct Item_10C9B0 *items;
};

extern void fn_1_10846C(void *);
extern void fn_1_128884(void *, void *, int);

void fn_1_10C9B0(struct Obj_10C9B0 *self) {
    u32 i, j, j3;
    struct Item_10C9B0 *p, *pj, *pj3, *pi;
    f32 t;
    u32 m;
    s32 k;

    if (self != 0) {
        fn_1_10846C(self);

        p = self->items;
        for (i = 0; i < self->count; i++, p++) {
            if (p->flag & 1) {
                p->f40 = -1.0f;
                p->flag = 0;
            } else {
                p->f40 = 0.0f;
                p->flag = 1;
            }
        }

        pi = self->items;
        for (i = 0; i < self->count; i++, pi++) {
            pj = self->items + i + 1;
            for (j = i + 1; j < self->count; j++, pj++) {
                if (!(pi->flag & 1) && (pj->flag & 1)) {
                    fn_1_128884(pi, pj, 0x44);
                }
            }
        }

        pi = self->items;
        for (i = 0; i < self->count; i++, pi++) {
            pj3 = self->items + i + 1;
            for (j3 = i + 1; j3 < self->count; j3++, pj3++) {
                if (pi->flag == pj3->flag && pi->f18 < pj3->f18) {
                    fn_1_128884(pi, pj3, 0x44);
                }
            }
        }

        m = (self->count - 1) / 3;
        for (j = 0; j < m; j++) {
            t = -(f32)j;
            k = 3 * j;
            if (1.1920929e-07f + self->items[k].f40 < 0.0f) {
                self->items[k].f40 = t / (f32)m;
            }
            if (1.1920929e-07f + self->items[k + 1].f40 < 0.0f) {
                self->items[k + 1].f40 = t / (f32)m;
            }
            if (1.1920929e-07f + self->items[k + 2].f40 < 0.0f) {
                self->items[k + 2].f40 = t / (f32)m;
            }
        }

        self->items[3 * m].f40 = -1.0f;
    }
}
