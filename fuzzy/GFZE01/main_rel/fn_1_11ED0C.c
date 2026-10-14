/* Non-matching: best partial attempt (24.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern const f64 lbl_1_rodata_7B08;
extern u32 fn_1_10846C(u32);
extern void fn_1_128884(void *, void *, int);
extern f32 fn_1_1289BC(const void *, const void *);
extern void *fn_1_4630(void *, u32);
extern void *lbl_801A6410;

typedef struct {
    u8 flag;
    u8 pad0[15];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1[36];
    f32 f40;
} TrackEntry;

typedef struct {
    TrackEntry *a;
    TrackEntry *b;
    f32 f;
} Edge;

typedef struct {
    u8 pad0[0x18];
    u32 count;
    u32 edgeCount;
    u8 pad1[4];
    TrackEntry *entries;
    Edge *edges;
} Manager;

void fn_1_11ED0C(Manager *self) {
    u32 i;
    u32 j;
    u32 k;
    u32 n;
    u32 g;
    u32 q;
    u32 denom;
    s32 idx;
    TrackEntry *e;
    TrackEntry *p;

    if (self != NULL) {
        fn_1_10846C((u32)self);
        e = self->entries;
        n = self->count;
        for (i = 0; i < n; i++) {
            if ((e[i].flag & 1) != 0) {
                e[i].flag = 0;
                e[i].f40 = lbl_1_rodata_7B1C;
            } else {
                e[i].flag = 1;
                e[i].f40 = lbl_1_rodata_7B20;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (e[i].flag == 0 && e[j].flag != 0) {
                    fn_1_128884(&e[i], &e[j], 0x44);
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (e[i].flag == e[j].flag && e[i].f10 < e[j].f10) {
                    fn_1_128884(&e[i], &e[j], 0x44);
                }
            }
        }
        for (i = 0; i < 11; i++) {
            for (j = i + 1; j < 11; j++) {
                if (e[i].f18 > e[j].f18) {
                    fn_1_128884(&e[i], &e[j], 0x44);
                }
            }
        }

        p = e;
        i = n;
        while (i != 0) {
            i--;
            if (p->flag != 0 && p[1].flag == 0) {
                break;
            }
            p++;
        }
        p++;

        idx = (s32)(p - e);
        denom = (n - (u32)idx) / 11 + 1;

        for (g = 0; g < denom - 1; g++, p += 11) {
            f32 num = -(f32)(g + 1);
            f32 den = (f32)denom;
            for (j = 0; j < 11; j++) {
                p[j].f40 = num / den;
            }
            for (i = 0; i < 11; i++) {
                for (j = i + 1; j < 11; j++) {
                    if (p[i].f18 > p[j].f18) {
                        fn_1_128884(&p[i], &p[j], 0x44);
                    }
                }
            }
        }

        q = n / 11;
        self->edgeCount = q * 10 + (q - 1) * 11 + 20;
        self->edges = fn_1_4630(lbl_801A6410, self->edgeCount * 12);

        k = 0;
        for (i = 0; i < 10; i++) {
            TrackEntry *pa = &e[i];
            TrackEntry *pb = &e[i + 12];
            self->edges[k].a = pa;
            self->edges[k].b = pb;
            self->edges[k].f = fn_1_1289BC(pa, pb);
            k++;
        }
        for (i = 0; i < 10; i++) {
            TrackEntry *pa = &e[i + 1];
            TrackEntry *pb = &e[i + 11];
            self->edges[k].a = pa;
            self->edges[k].b = pb;
            self->edges[k].f = fn_1_1289BC(pa, pb);
            k++;
        }
        for (i = 0; i + 1 < n; i++) {
            if ((i + 1) % 11 != 0) {
                TrackEntry *pa = &e[i];
                TrackEntry *pb = &e[i + 1];
                self->edges[k].a = pa;
                self->edges[k].b = pb;
                self->edges[k].f = fn_1_1289BC(pa, pb);
                k++;
            }
        }
        for (i = 0; i + 11 < n; i++) {
            TrackEntry *pa = &e[i];
            TrackEntry *pb = &e[i + 11];
            self->edges[k].a = pa;
            self->edges[k].b = pb;
            self->edges[k].f = fn_1_1289BC(pa, pb);
            k++;
        }
    }
}
