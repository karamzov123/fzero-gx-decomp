/* Non-matching: best partial attempt (34.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 active;
    u8 pad_1[0x0F];
    f32 key;
    f32 priority;
    f32 value;
    u8 pad_1C[0x24];
    f32 result;
} fn_1_1244F0_Entry;

typedef struct {
    u8 pad_0[0x18];
    u32 count;
    u32 output_count;
    u32 pad_20;
    fn_1_1244F0_Entry *entries;
    void *output;
} fn_1_1244F0_Data;

extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern const f64 lbl_1_rodata_7B08;
extern void fn_1_10846C(void *);
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_4630(u32, u32);
extern u32 lbl_801A6410;
typedef struct { u8 pad[0x10]; f32 v[3]; } Sig_fn_1_1289BC_Point1024C4;
extern f32 fn_1_1289BC(const Sig_fn_1_1289BC_Point1024C4 *, const Sig_fn_1_1289BC_Point1024C4 *);

void fn_1_1244F0(fn_1_1244F0_Data *data) {
    u32 i;
    u32 j;
    u32 k;
    u32 edges;
    u32 n;
    fn_1_1244F0_Entry *a;
    fn_1_1244F0_Entry *b;
    f32 value;

    if (data == 0) {
        return;
    }
    fn_1_10846C(data);
    a = data->entries;
    for (i = 0; i < data->count; i++, a++) {
        if (a->active & 1) {
            a->active = 0;
            a->result = -1.0f;
        } else {
            a->active = 1;
            a->result = 0.0f;
        }
    }
    a = data->entries;
    for (i = 0; i < data->count; i++, a++) {
        b = a + 1;
        for (j = i + 1; j < data->count; j++, b++) {
            if (a->active == 0 && b->active != 0) {
                fn_1_128884(a, b, 0x44);
            }
        }
    }
    a = data->entries;
    for (i = 0; i < data->count; i++, a++) {
        b = a + 1;
        for (j = i + 1; j < data->count; j++, b++) {
            if (a->active == b->active && a->key < b->key) {
                fn_1_128884(a, b, 0x44);
            }
        }
    }
    a = data->entries;
    for (i = 0; i < data->count / 9; i++, a += 9) {
        b = a;
        for (j = 0; j < 9; j++, b++) {
            fn_1_1244F0_Entry *c = b + 1;
            for (k = j + 1; k < 9; k++, c++) {
                if (b->value < c->value) {
                    fn_1_128884(b, c, 0x44);
                }
            }
        }
    }
    a = data->entries;
    for (i = 0; i < 9; i++, a++) {
        b = a + 1;
        for (j = i + 1; j < 9; j++, b++) {
            if (a->value > 0.0f && b->value > 0.0f) {
                if (a->priority > b->priority) {
                    fn_1_128884(a, b, 0x44);
                }
            } else if (a->value <= 0.0f && b->value <= 0.0f &&
                       a->priority < b->priority) {
                fn_1_128884(a, b, 0x44);
            }
        }
    }
    a = data->entries;
    for (i = 0; i < data->count; i++) {
        if (a->active == 0 && a[1].active != 0) {
            break;
        }
        if (a->active == 0 || a[1].active == 0) {
            a++;
        } else {
            break;
        }
    }
    a++;
    edges = (u32)(a - data->entries);
    edges = (data->count - edges) / 9;
    n = edges;
    value = 0.0f;
    for (i = 0; i < n; i++) {
        f32 result = -(f32)(i + 1) / (f32)(n + 1);
        for (j = 0; j < 9; j++) {
            data->entries[i * 9 + j].result = result;
        }
        a = &data->entries[i * 9];
        for (j = 0; j < 9; j++) {
            for (k = j + 1; k < 9; k++) {
                if (a[j].value > 0.0f && a[k].value > 0.0f) {
                    if (a[j].priority > a[k].priority) {
                        fn_1_128884(&a[j], &a[k], 0x44);
                    }
                } else if (a[j].value <= 0.0f && a[k].value <= 0.0f &&
                           a[j].priority < a[k].priority) {
                    fn_1_128884(&a[j], &a[k], 0x44);
                }
            }
        }
    }

    data->output_count = (data->count / 9 - 1) * 9 +
                         (data->count & 7);
    data->output = (void *)fn_1_4630(lbl_801A6410,
                                     data->output_count * 12);
    edges = 0;
    a = data->entries;
    for (i = 0; i < data->count - 1; i++, a++) {
        if ((i + 1) % 9 != 0) {
            ((void **)data->output)[edges * 3] = a;
            ((void **)data->output)[edges * 3 + 1] = a + 1;
            ((f32 *)data->output)[edges * 3 + 2] =
                fn_1_1289BC((const Sig_fn_1_1289BC_Point1024C4 *)a,
                            (const Sig_fn_1_1289BC_Point1024C4 *)(a + 1));
            edges++;
        }
    }
    a = data->entries;
    for (i = 0; i < data->count - 9; i++, a++) {
        ((void **)data->output)[edges * 3] = a;
        ((void **)data->output)[edges * 3 + 1] = a + 9;
        ((f32 *)data->output)[edges * 3 + 2] =
            fn_1_1289BC((const Sig_fn_1_1289BC_Point1024C4 *)a,
                        (const Sig_fn_1_1289BC_Point1024C4 *)(a + 9));
        edges++;
    }
}
