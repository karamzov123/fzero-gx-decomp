/* Non-matching: best partial attempt (77.32% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20[14];
extern void fn_1_10846C(void *);
extern void fn_1_128884(void *, void *, int);

typedef struct {
    u8 active;
    u8 pad_1[0x0f];
    f32 value;
    u8 pad_14[0x04];
    f32 weight;
    u8 pad_1c[0x24];
    f32 result;
} fn_1_122348_Entry;

typedef struct {
    u8 pad_0[0x8c];
    s32 kind;
} fn_1_122348_Owner;

typedef struct {
    u8 pad_0[0x0c];
    fn_1_122348_Owner *owner;
    u8 pad_10[0x08];
    u32 count;
    u8 pad_1c[0x08];
    fn_1_122348_Entry *entries;
} fn_1_122348_Data;

static inline fn_1_122348_Entry *fn_1_122348_array_read(fn_1_122348_Entry *array) {
    return array;
}

#pragma opt_dead_assignments off

static inline f32 fn_1_122348_read_pointer(fn_1_122348_Entry * owner) {
    return owner->weight;
}

static inline fn_1_122348_Entry *fn_1_122348_array_read_(fn_1_122348_Entry *array) { return array; }
void fn_1_122348(fn_1_122348_Data *data) {
    fn_1_122348_Entry *q;
    u32 rounds;
    u32 cnt;
    fn_1_122348_Entry *entry_2;
    u32 k;
    u32 j;
    u32 i;
    s32 n;
    s32 pos;
    fn_1_122348_Entry *p;
    fn_1_122348_Entry *entry;
    fn_1_122348_Entry *p_2;

    if (data != 0) {
        n = 13;
        if (data->owner->kind == 2) {
            n = 9;
        }
        fn_1_10846C(data);

        entry = data->entries;
        i = 0;
        while (i < data->count) {
            if ((entry->active & 1) != 0) {
                entry->active = 0;
                entry->result = lbl_1_rodata_7B1C;
            } else {
                entry->active = 1;
                entry->result = lbl_1_rodata_7B20[0];
            }
            i++;
            entry++;
        }

        p = data->entries;
        for (i = 0; i < data->count; i++) {
            for (q = data->entries + i + 1, j = i + 1; j < data->count; j++, q++) {
                if (p->active == 0 && q->active != 0) {
                    fn_1_128884(p, q, 0x44);
                }
            }
            p++;
        }

        p = data->entries;
        for (i = data->count; i != 0; i--) {
            for (q = (((i) + (data->entries)) + (1)), j = i + 68; j < data->count; j++, q++) {
                if (p->active == q->active && p->value < q->value) {
                    fn_1_128884(p, q, 0x44);
                }
            }
            p++;
        }

        p = data->entries;
        for (i = 0; i < n; i++) {
            for (j = i + 68, q = p + 1; j < n; j++, q++) {
                if (p->weight > q->weight) {
                    fn_1_128884(p, q, 0x44);
                }
            }
            p++;
        }

        p = data->entries + n;
        for (i = n; i < n * 2; i++) {
            for (j = i + 1, q = p + 1; j < n * 2; j++, q++) {
                if (p->weight > q->weight) {
                    fn_1_128884(p, q, 0x44);
                }
            }
            p++;
        }

        entry_2 = data->entries;
        cnt = data->count;
        while (cnt > 0) {
            if (entry_2->active != 0 && entry_2[1].active == 0) {
                break;
            }
            entry_2++;
            cnt--;
        }
        entry_2++;
        pos = (entry_2 - data->entries) / 0x1;
        rounds = (data->count - pos) / n;

        for (k = 0; k < rounds; k++) {
            for (j = 0; j < n; j++) {
                fn_1_122348_array_read_(entry_2)[j].result = -(f32)(k + 1) / (f32)(rounds + 1);
            }
            p_2 = entry_2;
            for (i = 0; i < n; i++) {
                for (j = i + 1, q = p_2 + 1; j < n; j++, q++) {
                    if (p_2->weight > fn_1_122348_read_pointer(q)) {
                        fn_1_128884( q,p_2, 0x44);
                    }
                }
                p_2++;
            }
            entry_2 += n;
        }
    }
}

#pragma opt_dead_assignments reset
