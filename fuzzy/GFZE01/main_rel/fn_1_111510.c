/* Non-matching: best partial attempt (18.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Item {
    u8 flag;
    u8 pad_1[0x0F];
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Item;
typedef struct Manager {
    u8 pad_0[0x18];
    u32 itemCount;
    u32 count;
    u32 unk_20;
    Item *items;
    u32 *output;
} Manager;
typedef struct Sig_fn_1_1289BC_Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Sig_fn_1_1289BC_Point1024C4;

extern f32 fn_1_1289BC(const Sig_fn_1_1289BC_Point1024C4 *, const Sig_fn_1_1289BC_Point1024C4 *);
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern const f64 lbl_1_rodata_7B08;
extern u32 fn_1_10846C(u32);
extern u32 fn_1_4630(u32, u32);
extern u32 lbl_1_data_40530;
extern u32 lbl_801A6410;
extern void fn_1_128884(void *, void *, int);

void fn_1_111510(Manager *m) {
    u32 i, j;
    Item *a, *b;
    u32 n, usable, loops;

    if (m == 0)
        return;
    fn_1_10846C((u32)m);
    {
        f32 neg = lbl_1_rodata_7B1C;
        f32 zero = lbl_1_rodata_7B20;
        Item *p = m->items;
        i = 0;
        while (i < m->itemCount) {
            if (p->flag & 1) {
                p->flag = 0;
                p->unk_40 = neg;
            } else {
                p->flag = 1;
                p->unk_40 = zero;
            }
            i++;
            p = (Item *)((u8 *)p + 0x44);
        }
    }

    i = 0;
    n = 0;
    a = m->items;
    while (i < m->itemCount) {
        j = i + 1;
        b = (Item *)((u8 *)m->items + n + 0x44);
        while (j < m->itemCount) {
            if (a->flag == 0 && b->flag != 0)
                fn_1_128884(a, b, 0x44);
            j++;
            b = (Item *)((u8 *)b + 0x44);
        }
        i++;
        n += 0x44;
        a = (Item *)((u8 *)a + 0x44);
    }
    for (i = 0; i < m->itemCount; i++) {
        for (j = i + 1; j < m->itemCount; j++) {
            a = &m->items[i];
            b = &m->items[j];
            if (a->flag == b->flag && a->unk_10 < b->unk_10)
                fn_1_128884(a, b, 0x44);
        }
    }
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 9; j++) {
            a = &m->items[i];
            b = &m->items[j];
            if (a->unk_18 > b->unk_18)
                fn_1_128884(a, b, 0x44);
        }
    }

    n = 0;
    while (n < m->itemCount &&
           (m->items[n].flag == 0 || m->items[n + 1].flag != 0))
        n++;
    n++;
    usable = m->itemCount - n;
    loops = usable / 18;

    for (i = 0; i < loops; i++) {
        f32 f = -(f32)(i + 1) / (f32)(loops + 1);
        for (j = 0; j < 9; j++)
            m->items[n + i * 9 + j].unk_40 = f;
        for (j = 0; j < 9; j++) {
            a = &m->items[n + i * 9 + j];
            b = a + 1;
            while (b < &m->items[n + i * 9 + 9]) {
                if (a->unk_18 > b->unk_18)
                    fn_1_128884(a, b, 0x44);
                b++;
            }
        }
    }

    m->count = (((m->itemCount * 7) / 360) * 4) +
               ((((m->itemCount * 7) / 360) / 2 - 1) * 9);
    m->output = (u32 *)fn_1_4630(lbl_801A6410, m->count * 12);
    n = 0;
    for (i = 0; i < m->itemCount - 1; i++) {
        if (((i + 1) % 9) != 0) {
            m->output[n * 3] = (u32)&m->items[i];
            m->output[n * 3 + 1] = (u32)&m->items[i + 1];
            *(f32 *)&m->output[n * 3 + 2] =
                fn_1_1289BC((const Sig_fn_1_1289BC_Point1024C4 *)&m->items[i],
                            (const Sig_fn_1_1289BC_Point1024C4 *)&m->items[i + 1]);
            n++;
        }
    }
    for (i = 0; i < m->itemCount - 9; i++) {
        m->output[n * 3] = (u32)&m->items[i];
        m->output[n * 3 + 1] = (u32)&m->items[i + 9];
        *(f32 *)&m->output[n * 3 + 2] =
            fn_1_1289BC((const Sig_fn_1_1289BC_Point1024C4 *)&m->items[i],
                        (const Sig_fn_1_1289BC_Point1024C4 *)&m->items[i + 9]);
        n++;
    }
}
