/* Non-matching: best partial attempt (33.99% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 used;
    u8 pad_1[15];
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Item110008;

typedef struct {
    u8 pad_0[0x18];
    u32 count;
    u32 num;
    u32 pad_20;
    Item110008 *items;
    void *links;
} Manager110008;

extern u32 fn_1_10846C(u32);
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern const f64 lbl_1_rodata_7B08;
extern void fn_1_128884(void *, void *, int);
extern u32 lbl_801A6410;
extern u32 fn_1_4630(u32, u32);
extern f32 fn_1_1289BC(const void *, const void *);

void fn_1_110008(Manager110008 *m) {
    u32 i, j, rows, nlinks;
    Item110008 *p, *q, *first;
    if (m == 0)
        return;
    fn_1_10846C((u32)m);
    {
        f32 neg = lbl_1_rodata_7B1C;
        f32 zero = lbl_1_rodata_7B20;
        p = m->items;
        for (i = 0; i < m->count; i++, p++) {
            if (p->used & 1) {
                p->used = 0;
                p->unk_40 = neg;
            } else {
                p->used = 1;
                p->unk_40 = zero;
            }
        }
    }
    for (i = 0, p = m->items; i < m->count; i++, p++) {
        for (j = i + 1, q = p + 1; j < m->count; j++, q++) {
            if (p->used == 0 && q->used != 0)
                fn_1_128884(p, q, 0x44);
        }
    }
    for (i = 0, p = m->items; i < m->count; i++, p++) {
        for (j = i + 1, q = p + 1; j < m->count; j++, q++) {
            if (p->used == q->used && p->unk_10 < q->unk_10)
                fn_1_128884(p, q, 0x44);
        }
    }
    for (i = 0, p = m->items; i < 9; i++, p++) {
        for (j = i + 1, q = p + 1; j < 9; j++, q++) {
            if (p->unk_18 > q->unk_18)
                fn_1_128884(p, q, 0x44);
        }
    }
    first = m->items;
    p = first;
    for (i = 0; i < m->count; i++) {
        if (p->used == 0 || (p + 1)->used != 0)
            p++;
    }
    p++;
    rows = (m->count - (u32)((u8 *)p - (u8 *)first) / 0x44) / 9;
    for (i = 0; i < rows; i++) {
        f32 score = -(f32)(i + 1) / (f32)(rows + 1);
        p->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x44))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x88))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0xCC))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x110))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x154))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x198))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x1DC))->unk_40 = score;
        ((Item110008 *)((u8 *)p + 0x220))->unk_40 = score;
        for (j = 0; j < 9; j++) {
            for (nlinks = j + 1; nlinks < 9; nlinks++) {
                if (((Item110008 *)((u8 *)p + j * 0x44))->unk_18 >
                    ((Item110008 *)((u8 *)p + nlinks * 0x44))->unk_18)
                    fn_1_128884((u8 *)p + j * 0x44,
                                (u8 *)p + nlinks * 0x44, 0x44);
            }
        }
        p = (Item110008 *)((u8 *)p + 9 * 0x44);
    }
    m->num = (m->count / 9 - 1) * 9 + (m->count % 9);
    m->links = (void *)fn_1_4630(lbl_801A6410, m->num * 12);
    nlinks = 0;
    for (i = 0; i < m->count - 1; i++) {
        if ((i + 1) % 9 != 0) {
            ((void **)m->links)[nlinks * 3] = &m->items[i];
            ((void **)m->links)[nlinks * 3 + 1] = &m->items[i + 1];
            ((f32 *)m->links)[nlinks * 3 + 2] =
                fn_1_1289BC((void *)&m->items[i], (void *)&m->items[i + 1]);
            nlinks++;
        }
    }
    for (i = 0; i < m->count - 9; i++) {
        ((void **)m->links)[nlinks * 3] = &m->items[i];
        ((void **)m->links)[nlinks * 3 + 1] =
            (u8 *)&m->items[i] + 9 * 0x44;
        ((f32 *)m->links)[nlinks * 3 + 2] =
            fn_1_1289BC((void *)&m->items[i],
                        (u8 *)&m->items[i] + 9 * 0x44);
        nlinks++;
    }
}
