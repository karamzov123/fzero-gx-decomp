/* Non-matching: best partial attempt (55.35% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 active;
    u8 pad_1[0x0F];
    f32 value_10;
    f32 value_14;
    f32 value_18;
    u8 pad_1C[0x24];
    f32 result;
} Entry;

typedef struct {
    u8 pad_0[0x0C];
    void *kind;
    u8 pad_10[0x08];
    u32 count;
    u32 rows;
    u8 pad_20[0x04];
    Entry *entries;
    u8 pad_28[0x04];
    void *links;
} Data;

typedef struct {
    u8 pad[0x10];
    f32 v[3];
} Point;

extern void fn_1_10846C(void *);
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20;
extern const f64 lbl_1_rodata_7B08;
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_4630(u32, u32);
extern f32 fn_1_1289BC(const Point *, const Point *);
extern u32 lbl_801A6410;
extern u8 lbl_1_data_40530[];

void fn_1_126DE8(Data *data) {
    u32 block;
    u32 block_count;
    u32 i;
    u32 j;
    u32 count;
    Entry *entries;
    Entry *a;
    Entry *b;
    u32 tail;
    u32 link_count;
    u32 link_offset;
    u32 k;

    if (data == 0) {
        return;
    }

    if (*(u32 *)((u8 *)data->kind + 0x88) == 0x1B) {
        block_count = 13;
    } else if (*(u32 *)((u8 *)data->kind + 0x88) == 4) {
        block_count = 15;
    } else if (*(u32 *)((u8 *)data->kind + 0x88) == 0x16) {
        block_count = 11;
    }

    fn_1_10846C(data);
    i = 0;
    entries = data->entries;
    while (i < data->count) {
        if ((entries->active & 1) != 0) {
            entries->active = 0;
            entries->result = lbl_1_rodata_7B1C;
        } else {
            entries->active = 1;
            entries->result = lbl_1_rodata_7B20;
        }
        i++;
        entries++;
    }

    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (entries[i].active == 0 && entries[j].active != 0) {
                fn_1_128884(&entries[i], &entries[j], 0x44);
            }
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (entries[i].active == entries[j].active &&
                entries[i].value_10 < entries[j].value_10) {
                fn_1_128884(&entries[i], &entries[j], 0x44);
            }
        }
    }

    for (block = 0; block < count / block_count; block++) {
        a = &entries[block * block_count];
        for (i = 0; i < block_count; i++) {
            for (j = i + 1; j < block_count; j++) {
                if (a[i].value_18 < a[j].value_18) {
                    fn_1_128884(&a[i], &a[j], 0x44);
                }
            }
        }
    }

    for (i = 0; i < block_count; i++) {
        for (j = i + 1; j < block_count; j++) {
            if (entries[i].value_18 > 0.0f &&
                entries[j].value_18 > 0.0f &&
                entries[i].value_14 > entries[j].value_14) {
                fn_1_128884(&entries[i], &entries[j], 0x44);
            } else if (entries[i].value_18 <= 0.0f &&
                       entries[j].value_18 <= 0.0f &&
                       entries[i].value_14 < entries[j].value_14) {
                fn_1_128884(&entries[i], &entries[j], 0x44);
            }
        }
    }

    entries = data->entries;
    count = data->count;
    for (i = 0; i < count; i++) {
        if (entries[i].active == 0 || entries[i + 1].active != 0) {
            entries++;
        }
    }
    entries++;
    tail = entries - data->entries;
    link_count = (count - (tail / 2)) / block_count;

    for (i = 0; i < link_count; i++) {
        for (j = 0; j < block_count; j++) {
            entries[j].result = -(f32)(i + 1) / (f32)(link_count + 1);
        }
        for (j = 0; j < block_count; j++) {
            for (k = j + 1; k < block_count; k++) {
                if (entries[j].value_18 > 0.0f &&
                    entries[k].value_18 > 0.0f &&
                    entries[j].value_14 > entries[k].value_14) {
                    fn_1_128884(&entries[j], &entries[k], 0x44);
                } else if (entries[j].value_18 <= 0.0f &&
                           entries[k].value_18 <= 0.0f &&
                           entries[j].value_14 < entries[k].value_14) {
                    fn_1_128884(&entries[j], &entries[k], 0x44);
                }
            }
        }
        entries += block_count;
    }

    data->rows = (count / block_count) * (block_count - 1) +
                 ((count / block_count - 1) * block_count);
    data->links = (void *)fn_1_4630(lbl_801A6410, data->rows * 12);
    link_offset = 0;
    link_count = 0;
    a = data->entries;
    for (i = 0; i < count - 1; i++) {
        if ((i + 1) % block_count != 0) {
            ((Entry **)data->links)[link_offset / 4] = a;
            ((Entry **)data->links)[link_offset / 4 + 1] = a + 1;
            *(f32 *)((u8 *)data->links + link_offset + 8) =
                fn_1_1289BC((Point *)a, (Point *)(a + 1));
            link_offset += 12;
            link_count++;
        }
        a++;
    }
    link_offset = link_count * 12;
    entries = data->entries;
    for (i = 0; i < count - block_count; i++) {
        ((Entry **)data->links)[link_offset / 4] = entries;
        ((Entry **)data->links)[link_offset / 4 + 1] = entries + block_count;
        *(f32 *)((u8 *)data->links + link_offset + 8) =
            fn_1_1289BC((Point *)entries, (Point *)(entries + block_count));
        entries++;
        link_offset += 12;
    }
}
