/* Non-matching: best partial attempt (49.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Entry {
    u8 active;
    u8 pad_1[0x0F];
    f32 key;
    u8 pad_14[0x04];
    f32 sort;
    u8 pad_1C[0x24];
    f32 weight;
} Entry;

typedef struct Manager {
    u8 pad_0[0x0C];
    void *owner;
    u8 pad_10[0x08];
    u32 count;
    u32 index;
    Entry *entries;
    u8 pad_28[0x04];
    void *edges;
} Manager;

typedef struct Point {
    u8 pad[0x10];
    f32 v[3];
} Point;

extern f32 fn_1_1289BC(const Point *, const Point *);
extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern f64 lbl_1_rodata_7B08;
extern u32 fn_1_10846C(u32);
extern u32 fn_1_4630(u32, u32);
extern u32 lbl_1_data_40530;
extern u32 lbl_801A6410;
extern void fn_1_128884(void *, void *, int);

void fn_1_1201E4(Manager *data) {
    u32 n, limit, i, j, k, edge_count;
    Entry *entries;
    Entry *p;
    u32 count;

    if (data == 0) return;
    n = data->owner ? 9 : 13;
    if (*(u32 *)((u8 *)data->owner + 0x8C) != 2) n = 13;
    fn_1_10846C((u32)data);

    entries = data->entries;
    count = data->count;
    for (i = 0; i < count; i++) {
        if (entries[i].active & 1) {
            entries[i].active = 0;
            entries[i].weight = lbl_1_rodata_7B1C;
        } else {
            entries[i].active = 1;
            entries[i].weight = lbl_1_rodata_7B20;
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++)
            if (entries[i].active == 0 && entries[j].active != 0)
                fn_1_128884(&entries[i], &entries[j], 0x44);
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++)
            if (entries[i].active == entries[j].active && entries[i].key < entries[j].key)
                fn_1_128884(&entries[i], &entries[j], 0x44);
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (entries[i].sort > entries[j].sort)
                fn_1_128884(&entries[i], &entries[j], 0x44);
    for (i = n; i < n * 2; i++)
        for (j = i + 1; j < n * 2; j++)
            if (entries[i].sort > entries[j].sort)
                fn_1_128884(&entries[i], &entries[j], 0x44);

    p = entries;
    for (i = 0; i < count && (p[i].active == 0 || p[i + 1].active != 0); i++) {}
    limit = i + 1;
    edge_count = (count - (u32)(p - entries)) / n;
    for (i = 0; i < edge_count; i++) {
        for (j = 0; j < n; j++) entries[i * n + j].weight = (f32)(-(i + 1)) / (f32)(edge_count + 1);
        for (j = 0; j < n; j++)
            for (k = j + 1; k < n; k++)
                if (entries[i * n + j].sort > entries[i * n + k].sort)
                    fn_1_128884(&entries[i * n + j], &entries[i * n + k], 0x44);
    }

    count = data->count;
    data->index = ((count / n - 1) * n) + ((n - 1) * 2) + ((count / n) * (n - 1));
    data->edges = (void *)fn_1_4630(*(u32 *)&lbl_801A6410,
        data->index * 12);
    edge_count = 0;
    for (i = 0; i < n - 1; i++) {
        ((void **)data->edges)[edge_count * 3] = &entries[i];
        ((void **)data->edges)[edge_count * 3 + 1] = &entries[i + n];
        ((f32 *)data->edges)[edge_count * 3 + 2] =
            fn_1_1289BC((Point *)&entries[i], (Point *)&entries[i + n]);
        edge_count++;
    }
    for (i = 0; i < n - 1; i++) {
        ((void **)data->edges)[edge_count * 3] = &entries[i + 1];
        ((void **)data->edges)[edge_count * 3 + 1] = &entries[i + n];
        ((f32 *)data->edges)[edge_count * 3 + 2] =
            fn_1_1289BC((Point *)&entries[i + 1], (Point *)&entries[i + n]);
        edge_count++;
    }
    for (i = 0; i < count - 1; i++) {
        if ((i + 1) % n)
            ((void **)data->edges)[edge_count * 3] = &entries[i],
            ((void **)data->edges)[edge_count * 3 + 1] = &entries[i + 1],
            ((f32 *)data->edges)[edge_count * 3 + 2] =
                fn_1_1289BC((Point *)&entries[i], (Point *)&entries[i + 1]),
            edge_count++;
    }
    for (i = 0; i < count - n; i++) {
        ((void **)data->edges)[edge_count * 3] = &entries[i];
        ((void **)data->edges)[edge_count * 3 + 1] = &entries[i + n];
        ((f32 *)data->edges)[edge_count * 3 + 2] =
            fn_1_1289BC((Point *)&entries[i], (Point *)&entries[i + n]);
        edge_count++;
    }
}
