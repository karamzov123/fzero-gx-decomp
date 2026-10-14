/* Non-matching: best partial attempt (20.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 active;
    u8 pad_1[0x0f];
    f32 x;
    u8 pad_14[4];
    f32 y;
    u8 pad_1c[0x24];
    f32 result;
} fn_1_12295C_Entry;

typedef struct {
    u8 pad_0[0x0c];
    void *child;
    u8 pad_10[8];
    u32 count;
    u32 num;
    u8 pad_20[4];
    fn_1_12295C_Entry *entries;
    void **out;
} fn_1_12295C_Data;

typedef struct {
    u8 pad[0x10];
    f32 v[3];
} fn_1_12295C_Point;

extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern f64 lbl_1_rodata_7B08;
extern void fn_1_10846C(void *);
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_4630(u32, u32);
extern f32 fn_1_1289BC(const fn_1_12295C_Point *, const fn_1_12295C_Point *);
extern u32 lbl_801A6410;

void fn_1_12295C(fn_1_12295C_Data *data) {
    u32 n, i, j, k, idx, rows, edge_count;
    fn_1_12295C_Entry *a, *b, *base, *row;
    fn_1_12295C_Point **edges;
    u32 offset;

    if (data != 0) {
        n = *(u32 *)((u8 *)data->child + 0x8c) == 2 ? 8 : 12;
        fn_1_10846C(data);
        for (i = 0; i < data->count; i++) {
            a = &data->entries[i];
            if ((a->active & 1) != 0) {
                a->active = 0;
                a->result = lbl_1_rodata_7B1C;
            } else {
                a->active = 1;
                a->result = lbl_1_rodata_7B20;
            }
        }
        for (i = 0; i < data->count; i++)
            for (j = i + 1; j < data->count; j++) {
                a = &data->entries[i]; b = &data->entries[j];
                if (a->active == 0 && b->active != 0)
                    fn_1_128884(a, b, 0x44);
            }
        for (i = 0; i < data->count; i++)
            for (j = i + 1; j < data->count; j++) {
                a = &data->entries[i]; b = &data->entries[j];
                if (a->active == b->active && a->x > b->x)
                    fn_1_128884(a, b, 0x44);
            }
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (data->entries[i].y > data->entries[j].y)
                    fn_1_128884(&data->entries[i], &data->entries[j], 0x44);
        for (i = n; i < 2 * n; i++)
            for (j = i + 1; j < 2 * n; j++)
                if (data->entries[i].y > data->entries[j].y)
                    fn_1_128884(&data->entries[i], &data->entries[j], 0x44);

        base = data->entries;
        for (i = 0; i < data->count; i++)
            if ((base[i].active == 0 || base[i + 1].active != 0))
                ;
        idx = 0;
        while (idx < data->count &&
               (data->entries[idx].active == 0 ||
                data->entries[idx + 1].active != 0))
            idx++;
        idx++;
        rows = (data->count - idx) / n;
        for (i = 0; i < rows; i++) {
            row = data->entries + idx + i * n;
            for (j = 0; j < n; j++)
                row[j].result = -(f32)(i + 1) / (f32)(rows + 1);
            for (j = 0; j < n; j++)
                for (k = j + 1; k < n; k++)
                    if (row[j].y > row[k].y)
                        fn_1_128884(&row[j], &row[k], 0x44);
        }
        edge_count = (data->count / n) * (n - 1) + (data->count / n - 1) * (n - 1);
        data->num = ((data->count / n - 1) * n) + ((data->count / n - 1) * 4);
        data->out = (void **)fn_1_4630(lbl_801A6410, data->num * 12);
        offset = 0;
        for (i = 0; i + 1 < n; i++) {
            data->out[offset++] = &data->entries[i];
            data->out[offset++] = &data->entries[i + n];
            *(f32 *)&data->out[offset++] = fn_1_1289BC((fn_1_12295C_Point *)&data->entries[i], (fn_1_12295C_Point *)&data->entries[i + n]);
        }
        for (i = 0; i + 1 < n; i++) {
            data->out[offset++] = &data->entries[i + 1];
            data->out[offset++] = &data->entries[i + n];
            *(f32 *)&data->out[offset++] = fn_1_1289BC((fn_1_12295C_Point *)&data->entries[i + 1], (fn_1_12295C_Point *)&data->entries[i + n]);
        }
        for (i = 0; i + 1 < n; i++) {
            data->out[offset++] = &data->entries[i + n];
            data->out[offset++] = &data->entries[i + n + 1];
            *(f32 *)&data->out[offset++] = fn_1_1289BC((fn_1_12295C_Point *)&data->entries[i + n], (fn_1_12295C_Point *)&data->entries[i + n + 1]);
        }
        for (i = 0; i + 1 < n; i++) {
            data->out[offset++] = &data->entries[i + n + 1];
            data->out[offset++] = &data->entries[i + 2 * n];
            *(f32 *)&data->out[offset++] = fn_1_1289BC((fn_1_12295C_Point *)&data->entries[i + n + 1], (fn_1_12295C_Point *)&data->entries[i + 2 * n]);
        }
        for (i = 0; i + 1 < data->count; i++) {
            if ((i + 1) % n != 0) {
                data->out[offset++] = &data->entries[i];
                data->out[offset++] = &data->entries[i + 1];
                *(f32 *)&data->out[offset++] = fn_1_1289BC((fn_1_12295C_Point *)&data->entries[i], (fn_1_12295C_Point *)&data->entries[i + 1]);
            }
        }
        for (i = 0; i < data->count - n; i++) {
            data->out[offset++] = &data->entries[i];
            data->out[offset++] = &data->entries[i + n];
            *(f32 *)&data->out[offset++] = fn_1_1289BC((fn_1_12295C_Point *)&data->entries[i], (fn_1_12295C_Point *)&data->entries[i + n]);
        }
    }
}
