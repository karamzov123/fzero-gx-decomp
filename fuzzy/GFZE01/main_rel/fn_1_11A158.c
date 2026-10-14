/* Non-matching: best partial attempt (29.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct Point {
    u8 active;
    u8 pad_1[0x0F];
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Point;

typedef struct Manager {
    u8 pad_0[0x18];
    u32 count;
    u32 outputCount;
    u32 pad_20;
    Point *points;
    void *edges;
} Manager;

typedef struct Sig_fn_1_1289BC_Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Sig_fn_1_1289BC_Point1024C4;

extern void fn_1_10846C(void);
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern void fn_1_128884(void *, void *, int);
extern f32 fn_1_1289BC(const Sig_fn_1_1289BC_Point1024C4 *, const Sig_fn_1_1289BC_Point1024C4 *);
extern u32 fn_1_4630(u32, u32);
extern u32 lbl_801A6410;

void fn_1_11A158(Manager *mgr) {
    u32 i, j, group;
    Point *p;

    if (mgr == 0)
        return;

    fn_1_10846C();
    p = mgr->points;
    for (i = 0; i < mgr->count; i++, p++) {
        if (p->active & 1) {
            p->active = 0;
            p->unk_40 = lbl_1_rodata_7B1C;
        } else {
            p->active = 1;
            p->unk_10 = lbl_1_rodata_7B20;
        }
    }

    for (i = 0; i < mgr->count; i++) {
        for (j = i + 1; j < mgr->count; j++) {
            if (mgr->points[i].active == 0 && mgr->points[j].active != 0)
                fn_1_128884(&mgr->points[i], &mgr->points[j], 0x44);
        }
    }

    for (i = 0; i < mgr->count; i++) {
        for (j = i + 1; j < mgr->count; j++) {
            if (mgr->points[i].active == mgr->points[j].active &&
                mgr->points[i].unk_10 < mgr->points[j].unk_10)
                fn_1_128884(&mgr->points[i], &mgr->points[j], 0x44);
        }
    }

    for (group = 0; group < mgr->count / 13; group++) {
        p = mgr->points + group * 13;
        for (i = 0; i < 13; i++) {
            for (j = i + 1; j < 13; j++) {
                if (p[i].unk_18 < p[j].unk_18)
                    fn_1_128884(&p[i], &p[j], 0x44);
            }
        }
    }

    for (i = 0; i < 13; i++) {
        for (j = i + 1; j < 13; j++) {
            if (mgr->points[i].unk_18 > 0.0f &&
                mgr->points[j].unk_18 > 0.0f &&
                mgr->points[i].unk_14 > mgr->points[j].unk_14) {
                fn_1_128884(&mgr->points[i], &mgr->points[j], 0x44);
            } else if (mgr->points[i].unk_18 <= 0.0f &&
                       mgr->points[j].unk_18 <= 0.0f &&
                       mgr->points[i].unk_14 < mgr->points[j].unk_14) {
                fn_1_128884(&mgr->points[i], &mgr->points[j], 0x44);
            }
        }
    }

    p = mgr->points;
    for (i = 0; i < mgr->count; i++) {
        if (mgr->count > 0 && (p->active == 0 || (p + 1)->active != 0))
            p++;
    }
    p++;
    i = (u32)(p - mgr->points) / 13;
    for (group = 0; group < i / 13; group++) {
        p = mgr->points + i + group * 13;
        for (i = 0; i < 13; i++) {
            for (j = i + 1; j < 13; j++) {
                if (p[i].unk_18 > 0.0f &&
                    p[j].unk_18 > 0.0f &&
                    p[i].unk_14 > p[j].unk_14) {
                    fn_1_128884(&p[i], &p[j], 0x44);
                } else if (p[i].unk_18 <= 0.0f &&
                           p[j].unk_18 <= 0.0f &&
                           p[i].unk_14 < p[j].unk_14) {
                    fn_1_128884(&p[i], &p[j], 0x44);
                }
            }
        }
    }

    mgr->outputCount = (mgr->count / 13) * 12 + (mgr->count / 13 - 1) * 13;
    mgr->edges = (void *)fn_1_4630(lbl_801A6410, mgr->outputCount * 12);

    i = 0;
    j = 0;
    p = mgr->points;
    while (i < mgr->count - 1) {
        if ((i + 1) % 13 != 0) {
            Point **edge = (Point **)mgr->edges;
            edge[j * 3] = p;
            edge[j * 3 + 1] = p + 1;
            ((f32 *)mgr->edges)[j * 3 + 2] =
                fn_1_1289BC((const Sig_fn_1_1289BC_Point1024C4 *)p,
                            (const Sig_fn_1_1289BC_Point1024C4 *)(p + 1));
            j++;
        }
        i++;
        p++;
    }

    i = j;
    p = mgr->points;
    while (i < mgr->count - 13) {
        Point **edge = (Point **)mgr->edges;
        edge[j * 3] = p;
        edge[j * 3 + 1] = p + 13;
        ((f32 *)mgr->edges)[j * 3 + 2] =
            fn_1_1289BC((const Sig_fn_1_1289BC_Point1024C4 *)p,
                        (const Sig_fn_1_1289BC_Point1024C4 *)(p + 13));
        j++;
        p++;
    }
}
